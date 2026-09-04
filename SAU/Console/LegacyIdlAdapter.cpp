#include "LegacyIdlAdapter.h"

#include "MockRobotSimulator.h"
#include "console.h"
#include "stubs/Air_Unit.h"
#include "stubs/Ground_Unit.h"
#include "stubs/Unit.h"

#include <QElapsedTimer>

#ifdef __cplusplus
extern "C" {
#endif
#include "iluchdrs.h"
#ifdef __cplusplus
}
#endif

extern ilu_HashTable Units_Hash_Table;

namespace {

char *sbhForUnit(const QString &unitId) {
    if (!Units_Hash_Table)
        return nullptr;
    QByteArray key = unitId.toUtf8();
    char *exact = static_cast<char *>(ilu_hash_FindInTable(
        Units_Hash_Table, reinterpret_cast<ilu_refany>(key.data())));
    if (exact)
        return exact;

    ilu_HashEnumerator_s enumerator{};
    ilu_refany uid = nullptr;
    ilu_refany sbh = nullptr;
    ilu_hash_BeginEnumeration(Units_Hash_Table, &enumerator);
    while (ilu_hash_Next(&enumerator, &uid, &sbh)) {
        if (logicalUnitIdsEqual(key.constData(), static_cast<const char *>(uid)))
            return static_cast<char *>(sbh);
    }
    return nullptr;
}

TaskRpcResult failure(const QString &code, const QString &message, bool mock = false) {
    TaskRpcResult result;
    result.mock = mock;
    result.errorCode = code;
    result.message = message;
    return result;
}

} // namespace

LegacyIdlAdapter &LegacyIdlAdapter::instance() {
    static LegacyIdlAdapter adapter;
    return adapter;
}

bool LegacyIdlAdapter::realRpcEnabled() {
    return qEnvironmentVariableIntValue("SAU_ENABLE_REAL_RPC") == 1;
}

QString LegacyIdlAdapter::taskTypeForNavigateRoute(const QString &path) {
    return path == QStringLiteral("/api/task/goto_pose")
        ? QStringLiteral("goto_pose")
        : QStringLiteral("navigate_to");
}

QString LegacyIdlAdapter::taskTypeForStaticFormationRoute(const QString &path) {
    return path == QStringLiteral("/api/formation/execute")
        ? QStringLiteral("execute_formation")
        : QStringLiteral("create_static_formation");
}

QJsonObject LegacyIdlAdapter::withStaticFormationTransformDefaults(
        const QJsonObject &request) {
    QJsonObject normalized = request;
    if (!normalized.contains(QStringLiteral("anchor"))) {
        QJsonObject anchor;
        anchor.insert(QStringLiteral("x"), 0.0);
        anchor.insert(QStringLiteral("y"), 0.0);
        normalized.insert(QStringLiteral("anchor"), anchor);
    }
    if (!normalized.contains(QStringLiteral("heading_rad")))
        normalized.insert(QStringLiteral("heading_rad"), 0.0);
    return normalized;
}

QString LegacyIdlAdapter::canonicalUnitId(const QString &unitId) const {
    if (!Units_Hash_Table)
        return QString();

    const QByteArray requested = unitId.toUtf8();
    if (ilu_hash_FindInTable(
            Units_Hash_Table,
            reinterpret_cast<ilu_refany>(const_cast<char *>(requested.constData())))) {
        return unitId;
    }

    ilu_HashEnumerator_s enumerator{};
    ilu_refany storedUid = nullptr;
    ilu_refany sbh = nullptr;
    ilu_hash_BeginEnumeration(Units_Hash_Table, &enumerator);
    while (ilu_hash_Next(&enumerator, &storedUid, &sbh)) {
        const char *candidate = static_cast<const char *>(storedUid);
        if (candidate && logicalUnitIdsEqual(requested.constData(), candidate))
            return QString::fromUtf8(candidate);
    }
    return QString();
}

bool LegacyIdlAdapter::isBound(const QString &unitId) const {
    return !canonicalUnitId(unitId).isEmpty();
}

bool LegacyIdlAdapter::isMock(const QString &unitId) const {
    const QString canonical = canonicalUnitId(unitId);
    char *sbh = canonical.isEmpty() ? nullptr : sbhForUnit(canonical);
    return sbh && MockRobotSimulator::isMockSbh(sbh);
}

bool LegacyIdlAdapter::isGroundUnit(const QString &unitId) const {
    const QString canonical = canonicalUnitId(unitId);
    return (canonical.isEmpty() ? unitId : canonical).startsWith(QLatin1Char('G'));
}

// 'A' 前缀识别空中单元，与 splitFormation 的分类规则保持一致
bool LegacyIdlAdapter::isAirUnit(const QString &unitId) const {
    const QString canonical = canonicalUnitId(unitId);
    return (canonical.isEmpty() ? unitId : canonical).startsWith(QLatin1Char('A'));
}

TaskRpcResult LegacyIdlAdapter::setTaskPoint(const QString &unitId, double x, double y) {
    const QString canonical = canonicalUnitId(unitId);
    char *sbh = canonical.isEmpty() ? nullptr : sbhForUnit(canonical);
    if (!sbh)
        return failure(QStringLiteral("UNIT_NOT_FOUND"),
                       QStringLiteral("unit %1 not bound").arg(unitId));
    if (!isGroundUnit(canonical))
        return failure(QStringLiteral("UNSUPPORTED_CAPABILITY"),
                       QStringLiteral("setTaskPoint supports ground units only"));
    if (MockRobotSimulator::isMockSbh(sbh)) {
        TaskRpcResult result;
        result.success = true;
        result.mock = true;
        return result;
    }
    if (!realRpcEnabled())
        return failure(QStringLiteral("RPC_DISABLED"),
                       QStringLiteral("real unit rpc is disabled"));

    CORBA_Environment ev;
    Ground_Unit_rpc proxy = static_cast<Ground_Unit_rpc>(
        ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev));
    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("UNIT_OFFLINE"),
                       QStringLiteral("SBHToObject failed for %1").arg(canonical));
    }

    Ground_Unit_Point2D point{};
    point.x = static_cast<CORBA_float>(x);
    point.y = static_cast<CORBA_float>(y);
    const CORBA_boolean accepted = Ground_Unit_rpc_setTaskPoint(proxy, &point, &ev);
    Ground_Unit_rpc__Free(&proxy);
    if (!ILU_C_SUCCESSFUL(&ev) || !accepted) {
        const QString returnCode = QString::fromUtf8(
            ev.returnCode ? ev.returnCode : "unknown");
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("INTERNAL_ERROR"),
                       QStringLiteral("setTaskPoint failed for %1 (ILU %2)")
                           .arg(canonical).arg(returnCode));
    }

    TaskRpcResult result;
    result.success = true;
    return result;
}

TaskRpcResult LegacyIdlAdapter::setTaskPath(const QString &unitId,
                                            const QJsonArray &points) {
    const QString canonical = canonicalUnitId(unitId);
    char *sbh = canonical.isEmpty() ? nullptr : sbhForUnit(canonical);
    if (!sbh)
        return failure(QStringLiteral("UNIT_NOT_FOUND"),
                       QStringLiteral("unit %1 not bound").arg(unitId));
    if (!isGroundUnit(canonical))
        return failure(QStringLiteral("UNSUPPORTED_CAPABILITY"),
                       QStringLiteral("setTaskPath supports ground units only"));
    if (MockRobotSimulator::isMockSbh(sbh)) {
        TaskRpcResult result;
        result.success = true;
        result.mock = true;
        return result;
    }
    if (!realRpcEnabled())
        return failure(QStringLiteral("RPC_DISABLED"),
                       QStringLiteral("real unit rpc is disabled"));

    CORBA_Environment ev;
    Ground_Unit_rpc proxy = static_cast<Ground_Unit_rpc>(
        ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev));
    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("UNIT_OFFLINE"),
                       QStringLiteral("SBHToObject failed for %1").arg(canonical));
    }

    Ground_Unit_TaskPath *taskPath = Ground_Unit_TaskPath_Create(0, NULL);
    if (!taskPath) {
        Ground_Unit_rpc__Free(&proxy);
        return failure(QStringLiteral("INTERNAL_ERROR"),
                       QStringLiteral("failed to allocate task path"));
    }

    ilu_Error appendError;
    for (const QJsonValue &value : points) {
        const QJsonObject object = value.toObject();
        Ground_Unit_Point2D point{};
        point.x = static_cast<CORBA_float>(object.value(QStringLiteral("x")).toDouble());
        point.y = static_cast<CORBA_float>(object.value(QStringLiteral("y")).toDouble());
        ILU_CLER(appendError);
        Ground_Unit_TaskPath_Append(taskPath, &point, &appendError);
        if (ILU_ERRNOK(appendError)) {
            ILU_HANDLED(appendError);
            Ground_Unit_TaskPath__Free(taskPath);
            Ground_Unit_rpc__Free(&proxy);
            return failure(QStringLiteral("INTERNAL_ERROR"),
                           QStringLiteral("failed to append task path point"));
        }
    }

    const CORBA_boolean accepted = Ground_Unit_rpc_setTaskPath(proxy, taskPath, &ev);
    Ground_Unit_TaskPath__Free(taskPath);
    Ground_Unit_rpc__Free(&proxy);
    if (!ILU_C_SUCCESSFUL(&ev) || !accepted) {
        const QString returnCode = QString::fromUtf8(
            ev.returnCode ? ev.returnCode : "unknown");
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("INTERNAL_ERROR"),
                       QStringLiteral("setTaskPath failed for %1 (ILU %2)")
                           .arg(canonical).arg(returnCode));
    }

    TaskRpcResult result;
    result.success = true;
    return result;
}

TaskRpcResult LegacyIdlAdapter::sendMove(const QString &unitId,
                                         double linearVelocity,
                                         double angularVelocity,
                                         int durationMs) {
    const QString canonical = canonicalUnitId(unitId);
    char *sbh = canonical.isEmpty() ? nullptr : sbhForUnit(canonical);
    if (!sbh)
        return failure(QStringLiteral("UNIT_NOT_FOUND"),
                       QStringLiteral("unit %1 not bound").arg(unitId));
    if (!isGroundUnit(canonical))
        return failure(QStringLiteral("UNSUPPORTED_CAPABILITY"),
                       QStringLiteral("sendMove supports ground units only"));
    if (MockRobotSimulator::isMockSbh(sbh)) {
        QElapsedTimer executionTimer;
        executionTimer.start();
        MockRobotSimulator::instance().applyMove(
            canonical, linearVelocity, angularVelocity, durationMs);
        TaskRpcResult result;
        result.success = true;
        result.mock = true;
        result.executionMs = executionTimer.nsecsElapsed() / 1000000.0;
        result.message = QStringLiteral("accepted");
        return result;
    }
    if (!realRpcEnabled())
        return failure(QStringLiteral("RPC_DISABLED"),
                       QStringLiteral("real unit rpc is disabled"));

    CORBA_Environment ev;
    Unit_rpc proxy = static_cast<Unit_rpc>(
        ILU_C_SBHToObject(sbh, Unit_rpc__MSType, &ev));
    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("UNIT_OFFLINE"),
                       QStringLiteral("SBHToObject failed for %1").arg(canonical));
    }

    Unit_MoveAction action{};
    const bool useTurn = qAbs(linearVelocity) < 1e-6 &&
                         qAbs(angularVelocity) > 1e-6;
    const bool useLinear = !useTurn && qAbs(linearVelocity) > 1e-6;
    if (useTurn) {
        Unit_ActionDuration *duration = nullptr;
        if (angularVelocity > 0.0) {
            action._d = Unit_MA_TurnLeft;
            action._u.turnLeftData.speed = static_cast<CORBA_float>(qAbs(angularVelocity));
            duration = &action._u.turnLeftData.duration;
        } else {
            action._d = Unit_MA_TurnRight;
            action._u.turnRightData.speed = static_cast<CORBA_float>(qAbs(angularVelocity));
            duration = &action._u.turnRightData.duration;
        }
        duration->keep = durationMs <= 0 ? ilu_TRUE : ilu_FALSE;
        if (durationMs > 0) {
            duration->ft_s = static_cast<CORBA_unsigned_long>(durationMs / 1000);
            duration->ft_t = static_cast<CORBA_unsigned_long>(durationMs % 1000);
        }
    } else if (useLinear) {
        Unit_ActionDuration *duration = nullptr;
        if (linearVelocity >= 0.0) {
            action._d = Unit_MA_GoAhead;
            action._u.goAheadData.speed = static_cast<CORBA_float>(linearVelocity);
            duration = &action._u.goAheadData.duration;
        } else {
            action._d = Unit_MA_GoBackward;
            action._u.goBackwardData.speed = static_cast<CORBA_float>(qAbs(linearVelocity));
            duration = &action._u.goBackwardData.duration;
        }
        duration->keep = durationMs <= 0 ? ilu_TRUE : ilu_FALSE;
        if (durationMs > 0) {
            duration->ft_s = static_cast<CORBA_unsigned_long>(durationMs / 1000);
            duration->ft_t = static_cast<CORBA_unsigned_long>(durationMs % 1000);
        }
    } else {
        action._d = Unit_MA_Stop;
        action._u.stopData.keep = ilu_TRUE;
    }

    QElapsedTimer executionTimer;
    executionTimer.start();
    Unit_rpc_sendMoveAction(proxy, &action, &ev);
    const double executionMs = executionTimer.nsecsElapsed() / 1000000.0;
    Unit_rpc__Free(&proxy);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        const QString returnCode = QString::fromUtf8(
            ev.returnCode ? ev.returnCode : "unknown");
        ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("INTERNAL_ERROR"),
                       QStringLiteral("sendMoveAction failed for %1 (ILU %2)")
                           .arg(canonical).arg(returnCode));
    }

    TaskRpcResult result;
    result.success = true;
    result.executionMs = executionMs;
    result.message = QStringLiteral("accepted");
    return result;
}

TaskPoseResult LegacyIdlAdapter::currentPose(const QString &unitId) {
    TaskPoseResult result;
    const QString canonical = canonicalUnitId(unitId);
    char *sbh = canonical.isEmpty() ? nullptr : sbhForUnit(canonical);
    if (!sbh) {
        result.errorCode = QStringLiteral("UNIT_NOT_FOUND");
        result.message = QStringLiteral("unit %1 not bound").arg(unitId);
        return result;
    }
    if (!isGroundUnit(canonical)) {
        result.errorCode = QStringLiteral("UNSUPPORTED_CAPABILITY");
        result.message = QStringLiteral("getCurrentPose task polling supports ground units only");
        return result;
    }
    if (MockRobotSimulator::isMockSbh(sbh)) {
        const QJsonObject pose = MockRobotSimulator::instance()
            .groundStatusJson(canonical).value(QStringLiteral("pose")).toObject();
        result.success = true;
        result.mock = true;
        result.x = pose.value(QStringLiteral("x")).toDouble();
        result.y = pose.value(QStringLiteral("y")).toDouble();
        return result;
    }
    if (!realRpcEnabled()) {
        result.errorCode = QStringLiteral("RPC_DISABLED");
        result.message = QStringLiteral("real unit rpc is disabled");
        return result;
    }

    CORBA_Environment ev;
    Ground_Unit_rpc proxy = static_cast<Ground_Unit_rpc>(
        ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev));
    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        result.errorCode = QStringLiteral("UNIT_OFFLINE");
        result.message = QStringLiteral("SBHToObject failed for %1").arg(canonical);
        return result;
    }

    const Ground_Unit_Pose2D pose = Ground_Unit_rpc_getCurrentPose(proxy, &ev);
    Ground_Unit_rpc__Free(&proxy);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        ILU_C_EXCEPTION_FREE(&ev);
        result.errorCode = QStringLiteral("UNIT_OFFLINE");
        result.message = QStringLiteral("getCurrentPose failed for %1").arg(canonical);
        return result;
    }

    result.success = true;
    result.x = pose.x;
    result.y = pose.y;
    return result;
}

// 读取空中单元三维位姿。地面链跟随只需要 x/y（地面投影），z 供状态上报使用。
TaskPoseResult LegacyIdlAdapter::airCurrentPose(const QString &unitId) {
    TaskPoseResult result;
    const QString canonical = canonicalUnitId(unitId);
    char *sbh = canonical.isEmpty() ? nullptr : sbhForUnit(canonical);
    if (!sbh) {
        result.errorCode = QStringLiteral("UNIT_NOT_FOUND");
        result.message = QStringLiteral("unit %1 not bound").arg(unitId);
        return result;
    }
    if (!isAirUnit(canonical)) {
        result.errorCode = QStringLiteral("UNSUPPORTED_CAPABILITY");
        result.message =
            QStringLiteral("airCurrentPose supports air units only");
        return result;
    }
    if (MockRobotSimulator::isMockSbh(sbh)) {
        const QJsonObject pose = MockRobotSimulator::instance()
            .airStatusJson(canonical).value(QStringLiteral("pose")).toObject();
        result.success = true;
        result.mock = true;
        result.x = pose.value(QStringLiteral("x")).toDouble();
        result.y = pose.value(QStringLiteral("y")).toDouble();
        result.z = pose.value(QStringLiteral("z")).toDouble();
        return result;
    }
    if (!realRpcEnabled()) {
        result.errorCode = QStringLiteral("RPC_DISABLED");
        result.message = QStringLiteral("real unit rpc is disabled");
        return result;
    }

    CORBA_Environment ev;
    Air_Unit_rpc proxy = static_cast<Air_Unit_rpc>(
        ILU_C_SBHToObject(sbh, Air_Unit_rpc__MSType, &ev));
    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        result.errorCode = QStringLiteral("UNIT_OFFLINE");
        result.message = QStringLiteral("SBHToObject failed for %1").arg(canonical);
        return result;
    }

    const Air_Unit_Pose3D pose = Air_Unit_rpc_getCurrentPose(proxy, &ev);
    Air_Unit_rpc__Free(&proxy);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        ILU_C_EXCEPTION_FREE(&ev);
        result.errorCode = QStringLiteral("UNIT_OFFLINE");
        result.message = QStringLiteral("getCurrentPose failed for %1").arg(canonical);
        return result;
    }

    result.success = true;
    result.x = pose.x;
    result.y = pose.y;
    result.z = pose.z;
    return result;
}

TaskRpcResult LegacyIdlAdapter::stopUnit(const QString &unitId) {
    const QString canonical = canonicalUnitId(unitId);
    char *sbh = canonical.isEmpty() ? nullptr : sbhForUnit(canonical);
    if (!sbh)
        return failure(QStringLiteral("UNIT_NOT_FOUND"),
                       QStringLiteral("unit %1 not bound").arg(unitId));
    if (MockRobotSimulator::isMockSbh(sbh)) {
        MockRobotSimulator::instance().stop(canonical);
        TaskRpcResult result;
        result.success = true;
        result.mock = true;
        result.message = QStringLiteral("CANCEL_CONFIRMED");
        return result;
    }
    if (!realRpcEnabled())
        return failure(QStringLiteral("RPC_DISABLED"),
                       QStringLiteral("real unit rpc is disabled"));

    CORBA_Environment ev;
    Unit_rpc proxy = static_cast<Unit_rpc>(
        ILU_C_SBHToObject(sbh, Unit_rpc__MSType, &ev));
    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        if (!ILU_C_SUCCESSFUL(&ev))
            ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("UNIT_OFFLINE"),
                       QStringLiteral("SBHToObject failed for %1").arg(canonical));
    }

    Unit_MoveAction action{};
    action._d = Unit_MA_Stop;
    action._u.stopData.keep = ilu_TRUE;
    Unit_rpc_sendMoveAction(proxy, &action, &ev);
    Unit_rpc__Free(&proxy);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        const QString returnCode = QString::fromUtf8(
            ev.returnCode ? ev.returnCode : "unknown");
        ILU_C_EXCEPTION_FREE(&ev);
        return failure(QStringLiteral("INTERNAL_ERROR"),
                       QStringLiteral("Unit_MA_Stop failed for %1 (ILU %2)")
                           .arg(canonical).arg(returnCode));
    }

    TaskRpcResult result;
    result.success = true;
    result.message = QStringLiteral("STOP_REQUESTED");
    return result;
}
