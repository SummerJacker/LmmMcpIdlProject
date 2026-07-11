/**
 * @file AirStatusProbe.cpp
 * @brief 真实空中单元 RPC 状态探测器实现。
 */

#include "AirStatusProbe.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "iluchdrs.h"
#ifdef __cplusplus
}
#endif

#include "stubs/Air_Unit.h"
#include "stubs/Unit.h"

#include <QDateTime>
#include <QString>

namespace {

static bool isRealUnitRpcEnabled() {
    return qEnvironmentVariableIntValue("SAU_ENABLE_REAL_RPC") == 1;
}

/** @brief 将 Unit_UnitRole 枚举转为可读字符串 */
static QString roleToString(Unit_UnitRole role) {
    switch (role) {
    case Unit_UR_Leader:   return QStringLiteral("Leader");
    case Unit_UR_Follower: return QStringLiteral("Follower");
    case Unit_UR_None:     return QStringLiteral("None");
    default:               return QStringLiteral("Unknown");
    }
}

} // namespace

AgentStatusSnapshot AirStatusProbe_probe(const QString &unitId, const char *sbh) {
    AgentStatusSnapshot snap;
    snap.unitId = unitId;
    snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
    snap.unitType = UnitType::Air;
    snap.mock = false;
    snap.bindingState = BindingState::Bound;
    snap.bindingOrigin = BindingOrigin::Runtime;
    snap.runMode = QStringLiteral("real");
    snap.capabilities = QStringList{ QStringLiteral("pose"),
                                     QStringLiteral("speed"),
                                     QStringLiteral("role") };

    if (!isRealUnitRpcEnabled()) {
        snap.connectionState = ConnectionState::Unknown;
        snap.statusFreshness = StatusFreshness::Unavailable;
        snap.lastError = QStringLiteral("real unit RPC disabled (SAU_ENABLE_REAL_RPC != 1)");
        return snap;
    }

    /* 通过 ILU SBHToObject 创建 Air_Unit 代理 */
    CORBA_Environment ev;
    Air_Unit_rpc proxy = (Air_Unit_rpc)ILU_C_SBHToObject(
        const_cast<char *>(sbh),
        Air_Unit_rpc__MSType, &ev);

    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        QString msg = QStringLiteral("Air SBHToObject failed, rc=%1")
                          .arg(ev.returnCode);
        ILU_C_EXCEPTION_FREE(&ev);
        snap.connectionState = ConnectionState::Offline;
        snap.statusFreshness = StatusFreshness::Unavailable;
        snap.lastError = msg;
        return snap;
    }

    bool allOk = true;
    QStringList errors;

    /* 获取位姿（含 z 轴） */
    {
        CORBA_Environment evPose;
        Air_Unit_Pose3D pose = Air_Unit_rpc_getCurrentPose(proxy, &evPose);
        if (ILU_C_SUCCESSFUL(&evPose)) {
            snap.poseX = static_cast<double>(pose.x);
            snap.poseY = static_cast<double>(pose.y);
            snap.poseZ = static_cast<double>(pose.z);
            snap.poseYaw = static_cast<double>(pose.yaw);
            snap.hasPose = true;
        } else {
            errors.append(QStringLiteral("getCurrentPose failed, rc=%1").arg(evPose.returnCode));
            ILU_C_EXCEPTION_FREE(&evPose);
            allOk = false;
        }
    }

    /* 获取速度（通过 getCurrentInfo 中的 speed 字段） */
    {
        CORBA_Environment evInfo;
        Air_Unit_AirUnitInfo *info = Air_Unit_rpc_getCurrentInfo(proxy, &evInfo);
        if (ILU_C_SUCCESSFUL(&evInfo) && info) {
            /* Air_Unit_Speed3D: x, y, z */
            snap.speedLinear = static_cast<double>(info->speed.x);
            snap.speedAngular = 0.0; /* Air 单元速度语义不同，角速度从 angularVelocity 取 */
            if (info->angularVelocity.x != 0.0f || info->angularVelocity.y != 0.0f ||
                info->angularVelocity.z != 0.0f) {
                snap.speedAngular = static_cast<double>(qMax(
                    qMax(qAbs(info->angularVelocity.x),
                         qAbs(info->angularVelocity.y)),
                    qAbs(info->angularVelocity.z)));
            }
            snap.hasSpeed = true;

            /* 角色 */
            snap.role = roleToString(info->role);

            Air_Unit_AirUnitInfo__Free(info);
        } else {
            errors.append(QStringLiteral("getCurrentInfo failed, rc=%1").arg(evInfo.returnCode));
            ILU_C_EXCEPTION_FREE(&evInfo);
            allOk = false;
        }
    }

    /* 清理代理 */
    Air_Unit_rpc__Free(&proxy);

    if (allOk) {
        snap.connectionState = ConnectionState::Online;
        snap.lastSeenMs = snap.observedAtMs;
        snap.statusFreshness = StatusFreshness::Fresh;
    } else {
        snap.connectionState = ConnectionState::Offline;
        snap.statusFreshness = StatusFreshness::Unavailable;
        snap.lastError = errors.join(QStringLiteral("; "));
    }

    return snap;
}
