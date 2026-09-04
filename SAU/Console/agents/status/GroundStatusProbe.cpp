/**
 * @file GroundStatusProbe.cpp
 * @brief 真实地面单元 RPC 状态探测器实现。
 */

#include "GroundStatusProbe.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "iluchdrs.h"
#ifdef __cplusplus
}
#endif

#include "stubs/Ground_Unit.h"
#include "stubs/Unit.h"

#include <QDateTime>
#include <QtMath>
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

AgentStatusSnapshot GroundStatusProbe_probe(const QString &unitId, const char *sbh) {
    AgentStatusSnapshot snap;
    snap.unitId = unitId;
    snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
    snap.unitType = UnitType::Ground;
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

    if (!sbh) {
        snap.connectionState = ConnectionState::Offline;
        snap.statusFreshness = StatusFreshness::Unavailable;
        snap.lastError = QStringLiteral("no SBH for unit");
        return snap;
    }

    /* 通过 ILU SBHToObject 创建代理 */
    CORBA_Environment ev;
    Ground_Unit_rpc proxy = (Ground_Unit_rpc)ILU_C_SBHToObject(
        const_cast<char *>(sbh),
        Ground_Unit_rpc__MSType, &ev);

    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        QString msg = QStringLiteral("Ground SBHToObject failed, rc=%1")
                          .arg(ev.returnCode);
        ILU_C_EXCEPTION_FREE(&ev);
        snap.connectionState = ConnectionState::Offline;
        snap.statusFreshness = StatusFreshness::Unavailable;
        snap.lastError = msg;
        return snap;
    }

    bool allOk = true;
    QStringList errors;

    /* 获取位姿 */
    {
        CORBA_Environment evPose;
        Ground_Unit_Pose2D pose = Ground_Unit_rpc_getCurrentPose(proxy, &evPose);
        if (ILU_C_SUCCESSFUL(&evPose)) {
            snap.poseX = static_cast<double>(pose.x);
            snap.poseY = static_cast<double>(pose.y);
            snap.poseZ = 0.0;
            snap.poseYaw = static_cast<double>(pose.yaw);
            snap.hasPose = true;
        } else {
            errors.append(QStringLiteral("getCurrentPose failed, rc=%1").arg(evPose.returnCode));
            ILU_C_EXCEPTION_FREE(&evPose);
            allOk = false;
        }
    }

    /* 获取速度 */
    {
        CORBA_Environment evSpd;
        Ground_Unit_Speed2D spd = Ground_Unit_rpc_getCurrentSpeed(proxy, &evSpd);
        if (ILU_C_SUCCESSFUL(&evSpd)) {
            snap.speedLinear = static_cast<double>(spd.leanerVel);
            snap.speedAngular = static_cast<double>(spd.angularVel);
            snap.hasSpeed = true;
        } else {
            errors.append(QStringLiteral("getCurrentSpeed failed, rc=%1").arg(evSpd.returnCode));
            ILU_C_EXCEPTION_FREE(&evSpd);
            allOk = false;
        }
    }

    /* 获取角色（通过 getCurrentInfo） */
    {
        CORBA_Environment evInfo;
        Ground_Unit_GroundUnitInfo *info = Ground_Unit_rpc_getCurrentInfo(proxy, &evInfo);
        if (ILU_C_SUCCESSFUL(&evInfo) && info) {
            snap.role = roleToString(info->role);
            Ground_Unit_GroundUnitInfo__Free(info);
        } else {
            errors.append(QStringLiteral("getCurrentInfo failed, rc=%1").arg(evInfo.returnCode));
            ILU_C_EXCEPTION_FREE(&evInfo);
            allOk = false;
        }
    }

    /* 清理代理 */
    Ground_Unit_rpc__Free(&proxy);

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
