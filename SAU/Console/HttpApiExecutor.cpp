/**
 * @file HttpApiExecutor.cpp
 * @brief HttpApiExecutor：JSON API 与单元 RPC 的桥接实现。
 */

#include "HttpApiExecutor.h"

#include "MockRobotSimulator.h"
#include "LegacyIdlAdapter.h"
#include "TaskOrchestrator.h"
#include "TaskManager.h"
#include "SafetyValidator.h"
#include "agents/http/AgentHttpController.h"
#include "console.h"
#include "serverthread.h"

extern ServerThread *st;

// Console 内部全局状态 (console.cpp) — mock 路径需要直接访问
extern Unit_UnitID currentLeaderUID;
extern Unit_UnitMode currentMode;
extern Unit_UnitMinorMode currentMinorMode;

#ifdef __cplusplus
extern "C" {
#endif
#include "iluchdrs.h"
#ifdef __cplusplus
}
#endif

#include "stubs/Air_Unit.h"
#include "stubs/Ground_Unit.h"
#include "stubs/Unit.h"

#include <QDateTime>
#include <QElapsedTimer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMutexLocker>
#include <QPair>
#include <QSet>
#include <QUuid>
#include <QtMath>
#include <QUrl>
#include <QUrlQuery>
#include <limits>

/* 使用 QtMath::qAbs 等，避免工具链/Clang 模型找不到 <math.h>/<string.h> 时 memset/fabs 连锁失败 */

namespace {

/** @brief 与 UI 一致的小阈值：角速度低于此则视为纯线速度 */
constexpr double kAngularDeadzone = 1e-6;
/** @brief 线速度低于此则视为纯转向 */
constexpr double kLinearDeadzone = 1e-6;
/**
 * @brief HTTP 防卡保护开关：默认禁止在 HTTP 请求路径中对真实单元做同步 ILU RPC。
 *
 * 说明：真实单元断连或链路抖动时，ILU 同步调用可能长时间阻塞主线程，进而导致整个 HttpPlugin
 * 请求队列堆积（表现为 /api/robot/list 也超时）。默认关闭真实 RPC，可保证 mock 联调与监控稳定。
 * 若现场确认真实链路稳定，可通过环境变量 SAU_ENABLE_REAL_RPC=1 恢复原行为。
 */
static bool isRealUnitRpcEnabled() {
    return qEnvironmentVariableIntValue("SAU_ENABLE_REAL_RPC") == 1;
}

static bool benchmarkTimingsEnabled() {
    return qEnvironmentVariableIntValue("SAU_BENCHMARK_TIMINGS") == 1;
}

static double elapsedMilliseconds(const QElapsedTimer &timer) {
    return timer.nsecsElapsed() / 1000000.0;
}

static void insertBenchmarkTimings(
    QJsonObject *data, double taskContractMs, double consoleDispatchMs,
    double mockExecutionMs, bool includeTaskContract) {
    if (!data || !benchmarkTimingsEnabled())
        return;
    QJsonObject timing;
    if (includeTaskContract)
        timing.insert(QStringLiteral("task_contract_ms"), qMax(0.0, taskContractMs));
    timing.insert(QStringLiteral("console_dispatch_ms"),
                  qMax(0.0, consoleDispatchMs));
    timing.insert(QStringLiteral("mock_execution_ms"),
                  qMax(0.0, mockExecutionMs));
    data->insert(QStringLiteral("_benchmark_timing"), timing);
}

QByteArray jsonResponse(bool success, const QString &message, const QJsonValue &data, int *httpStatus,
                        int errorHttpStatus = 400) {
    QJsonObject o;
    o.insert(QStringLiteral("success"), success);
    o.insert(QStringLiteral("message"), QJsonValue(message));
    o.insert(QStringLiteral("data"), data);
    if (httpStatus)
        *httpStatus = success ? 200 : errorHttpStatus;
    return QJsonDocument(o).toJson(QJsonDocument::Compact);
}

/** @brief 将 QJsonObject 包成 QJsonValue，兼容 Qt5/MSVC 对 jsonResponse 第三参的推导 */
static QByteArray jsonResponseObj(bool success, const QString &message, const QJsonObject &obj, int *httpStatus,
                                  int errorHttpStatus = 400) {
    return jsonResponse(success, message, QJsonValue(obj), httpStatus, errorHttpStatus);
}

static QJsonObject immediateTaskResult(
    const QString &taskType, const QString &state, const QString &errorCode,
    const QString &message, const QStringList &unitIds = QStringList()) {
    const bool success = state == QStringLiteral("PENDING") ||
                         state == QStringLiteral("RUNNING") ||
                         state == QStringLiteral("COMPLETED") ||
                         state == QStringLiteral("PARTIAL_COMPLETED");
    const bool terminal = state != QStringLiteral("PENDING") &&
                          state != QStringLiteral("RUNNING");
    QJsonArray unitResults;
    for (const QString &unitId : unitIds) {
        QJsonObject unit;
        unit.insert(QStringLiteral("unit_id"), unitId);
        unit.insert(QStringLiteral("state"), state);
        unit.insert(QStringLiteral("progress_pct"), terminal ? 100.0 : 0.0);
        unit.insert(QStringLiteral("message"), message);
        unit.insert(QStringLiteral("error_code"), errorCode);
        unitResults.append(unit);
    }

    QJsonObject result;
    result.insert(QStringLiteral("success"), success);
    result.insert(QStringLiteral("task_id"), QString());
    result.insert(QStringLiteral("task_type"), taskType);
    result.insert(QStringLiteral("state"), state);
    result.insert(QStringLiteral("progress_pct"), terminal ? 100.0 : 0.0);
    result.insert(QStringLiteral("message"), message);
    result.insert(QStringLiteral("error_code"), errorCode);
    result.insert(QStringLiteral("unit_results"), unitResults);
    result.insert(QStringLiteral("elapsed_ms"), 0);
    result.insert(QStringLiteral("started_at_ms"), QDateTime::currentMSecsSinceEpoch());
    result.insert(QStringLiteral("cancellation_effect"),
                  QStringLiteral("NOT_APPLICABLE"));
    return result;
}

static FollowFormationSnapshot currentFollowFormationSnapshot() {
    FollowFormationSnapshot status;
    status.ready = consoleFollowFormationRecord.ready;
    status.state = consoleFollowFormationRecord.state;
    status.leaderId = consoleFollowFormationRecord.leaderId;
    status.activeMoveTaskId = consoleFollowFormationRecord.activeMoveTaskId;
    status.message = consoleFollowFormationRecord.message;
    status.errorCode = consoleFollowFormationRecord.errorCode;
    for (int i = 0; i < consoleFollowFormationRecord.followerIds.size(); ++i) {
        FollowFormationMember member;
        member.unitId = consoleFollowFormationRecord.followerIds.at(i);
        member.requestedDistanceM =
            consoleFollowFormationRecord.requestedDistances.value(i);
        member.effectiveDistanceM =
            consoleFollowFormationRecord.effectiveDistances.value(i);
        status.followers.append(member);
    }
    return status;
}

/**
 * @brief 非 mock 单元快速失败，避免真实链路断连时阻塞整个 HTTP 服务线程。
 */
static QByteArray realUnitRpcDisabledResponse(int *httpStatus) {
    return jsonResponse(false,
                        QStringLiteral("real unit rpc disabled in HTTP path; use mock units or set SAU_ENABLE_REAL_RPC=1"),
                        QJsonValue::Null, httpStatus, 503);
}

static bool parseJsonObjectBody(const QByteArray &body, QJsonObject *out, QByteArray *errorResponse,
                                int *httpStatus) {
    QJsonParseError pe{};
    const QJsonDocument doc = QJsonDocument::fromJson(body, &pe);
    if (!doc.isObject() || pe.error != QJsonParseError::NoError) {
        if (errorResponse)
            *errorResponse = jsonResponse(false, QStringLiteral("invalid JSON"), QJsonValue::Null, httpStatus);
        return false;
    }
    if (out)
        *out = doc.object();
    return true;
}

static bool isGroundUnitId(const QString &unitId) {
    return unitId.startsWith(QLatin1Char('G'));
}

static bool isAirUnitId(const QString &unitId) {
    return unitId.startsWith(QLatin1Char('A'));
}

// FormationResult → JSON：完整单元级 is_orphan / error_code / error_msg 信息。
static QJsonObject formationResultJson(const FormationResult &result) {
    QJsonObject root;
    const int totalSuccess = result.airResult.successCount + result.groundResult.successCount;
    const int totalFail = result.airResult.failCount + result.groundResult.failCount;
    root.insert(QStringLiteral("success"), result.isSuccess());
    root.insert(QStringLiteral("total_count"), totalSuccess + totalFail);
    root.insert(QStringLiteral("success_count"), totalSuccess);
    root.insert(QStringLiteral("fail_count"), totalFail);
    root.insert(QStringLiteral("elapsed_ms"), result.elapsedMs);

    auto groupJson = [](const GroupResult &group) {
        QJsonObject obj;
        obj.insert(QStringLiteral("success"), group.success);
        obj.insert(QStringLiteral("success_count"), group.successCount);
        obj.insert(QStringLiteral("fail_count"), group.failCount);
        QJsonArray units;
        for (const auto &ur : group.unitResults) {
            QJsonObject u;
            u.insert(QStringLiteral("unit_id"), QString::fromUtf8(ur.uid));
            u.insert(QStringLiteral("success"), ur.success);
            u.insert(QStringLiteral("error_code"), ur.errorCode);
            u.insert(QStringLiteral("error_msg"), QString::fromUtf8(ur.errorMsg));
            u.insert(QStringLiteral("is_orphan"), ur.isOrphan);
            units.append(u);
        }
        obj.insert(QStringLiteral("units"), units);
        return obj;
    };

    root.insert(QStringLiteral("air_result"), groupJson(result.airResult));
    root.insert(QStringLiteral("ground_result"), groupJson(result.groundResult));

    QJsonArray warnings;
    for (const auto &w : result.crossTypeWarnings) {
        QJsonObject edge;
        edge.insert(QStringLiteral("from"), QString::fromUtf8(w.fromUid));
        edge.insert(QStringLiteral("to"), QString::fromUtf8(w.toUid));
        warnings.append(edge);
    }
    root.insert(QStringLiteral("cross_type_warnings"), warnings);
    return root;
}

static bool readFiniteNumber(const QJsonObject &o, const QString &name, double *out) {
    const QJsonValue v = o.value(name);
    if (!v.isDouble())
        return false;
    const double n = v.toDouble();
    if (!qIsFinite(n))
        return false;
    if (out)
        *out = n;
    return true;
}

struct GroundFleetState {
    int groundCount = 0;
    int mockCount = 0;
    int realCount = 0;
};

static GroundFleetState groundFleetState() {
    GroundFleetState state;
    if (!Units_Hash_Table)
        return state;

    ilu_HashEnumerator_s he{};
    ilu_refany uid = nullptr;
    ilu_refany sbh = nullptr;
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        const QString unitId = QString::fromUtf8((const char *)uid);
        if (!isGroundUnitId(unitId))
            continue;
        state.groundCount++;
        if (MockRobotSimulator::isMockSbh((const char *)sbh))
            state.mockCount++;
        else
            state.realCount++;
    }
    return state;
}

static bool parseGroupMode(const QString &mode, Unit_UnitMode *out) {
    if (mode == QStringLiteral("none")) {
        *out = Unit_UM_None;
        return true;
    }
    if (mode == QStringLiteral("follow")) {
        *out = Unit_UM_Follow;
        return true;
    }
    if (mode == QStringLiteral("imitate")) {
        *out = Unit_UM_Imitate;
        return true;
    }
    if (mode == QStringLiteral("mate")) {
        *out = Unit_UM_Mate;
        return true;
    }
    return false;
}

static bool parseMinorMode(const QString &mode, Unit_UnitMinorMode *out) {
    if (mode == QStringLiteral("none")) {
        *out = Unit_UMM_None;
        return true;
    }
    if (mode == QStringLiteral("object")) {
        *out = Unit_UMM_FW_Object;
        return true;
    }
    if (mode == QStringLiteral("track")) {
        *out = Unit_UMM_FW_Track;
        return true;
    }
    return false;
}

static QJsonObject groundFleetData(const GroundFleetState &state) {
    QJsonObject data;
    data.insert(QStringLiteral("ground_count"), QJsonValue(state.groundCount));
    data.insert(QStringLiteral("mock_count"), QJsonValue(state.mockCount));
    data.insert(QStringLiteral("real_count"), QJsonValue(state.realCount));
    return data;
}

char *sbhForUid(const QString &unitId);

static Ground_Unit_rpc groundProxyForUnit(const QString &unitId, QByteArray *errorResponse, int *httpStatus) {
    char *sbh = sbhForUid(unitId);
    if (!sbh) {
        if (errorResponse)
            *errorResponse = jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);
        return nullptr;
    }
    if (MockRobotSimulator::isMockSbh(sbh)) {
        if (errorResponse)
            *errorResponse = jsonResponse(false, QStringLiteral("mock unit has no real rpc proxy"), QJsonValue::Null,
                                          httpStatus);
        return nullptr;
    }
    if (!isRealUnitRpcEnabled()) {
        if (errorResponse)
            *errorResponse = realUnitRpcDisabledResponse(httpStatus);
        return nullptr;
    }

    CORBA_Environment ev;
    Ground_Unit_rpc proxy = (Ground_Unit_rpc)ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev);
    if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
        ILU_C_EXCEPTION_FREE(&ev);
        if (errorResponse)
            *errorResponse = jsonResponse(false, QStringLiteral("SBHToObject failed"), QJsonValue::Null, httpStatus);
        return nullptr;
    }
    return proxy;
}

static QJsonArray failedFormationUnitsJson(const FormationResult &result) {
    QJsonArray failures;
    const std::vector<UnitResult> failed = result.getAllFailedUnits();
    for (const UnitResult &unit : failed) {
        QJsonObject item;
        item.insert(QStringLiteral("unit_id"), QString::fromUtf8(unit.uid));
        item.insert(QStringLiteral("error_code"), unit.errorCode);
        item.insert(QStringLiteral("message"), QString::fromUtf8(unit.errorMsg));
        failures.append(item);
    }
    return failures;
}

char *sbhForUid(const QString &unitId) {
    QByteArray u = unitId.toUtf8();
    if (!Units_Hash_Table)
        return nullptr;
    /* ilu_hash_FindInTable(..., ilu_refany) 需要非 const 指针；constData() 为 const char*，MSVC 会 C2664 */
    return (char *)ilu_hash_FindInTable(Units_Hash_Table, reinterpret_cast<ilu_refany>(u.data()));
}

bool sendStopToProxy(Unit_rpc proxy, QString *errOut) {
    CORBA_Environment ev;
    Unit_MoveAction action{};
    action._d = Unit_MA_Stop;
    action._u.stopData.keep = ilu_TRUE;
    Unit_rpc_sendMoveAction(proxy, &action, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        if (errOut)
            *errOut = QStringLiteral("ILU error %1").arg(ev.returnCode);
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    return true;
}

bool sendMoveToProxy(Unit_rpc proxy, double linearVelocity, double angularVelocity,
                     int durationMs, QString *errOut) {
    CORBA_Environment ev;
    Unit_MoveAction action{};

    const bool useTurn = (qAbs(linearVelocity) < kLinearDeadzone) &&
                         (qAbs(angularVelocity) > kAngularDeadzone);
    const bool useLinear = !useTurn && (qAbs(linearVelocity) > kLinearDeadzone);

    if (useTurn) {
        if (angularVelocity > 0) {
            action._d = Unit_MA_TurnLeft;
            action._u.turnLeftData.speed = (CORBA_float)qAbs(angularVelocity);
            action._u.turnLeftData.duration.keep =
                (durationMs <= 0) ? ilu_TRUE : ilu_FALSE;
            if (durationMs > 0) {
                action._u.turnLeftData.duration.ft_s = (CORBA_unsigned_long)(durationMs / 1000);
                action._u.turnLeftData.duration.ft_t = (CORBA_unsigned_long)(durationMs % 1000);
            }
        } else {
            action._d = Unit_MA_TurnRight;
            action._u.turnRightData.speed = (CORBA_float)qAbs(angularVelocity);
            action._u.turnRightData.duration.keep =
                (durationMs <= 0) ? ilu_TRUE : ilu_FALSE;
            if (durationMs > 0) {
                action._u.turnRightData.duration.ft_s = (CORBA_unsigned_long)(durationMs / 1000);
                action._u.turnRightData.duration.ft_t = (CORBA_unsigned_long)(durationMs % 1000);
            }
        }
    } else if (useLinear) {
        if (linearVelocity >= 0) {
            action._d = Unit_MA_GoAhead;
            action._u.goAheadData.speed = (CORBA_float)linearVelocity;
            action._u.goAheadData.duration.keep =
                (durationMs <= 0) ? ilu_TRUE : ilu_FALSE;
            if (durationMs > 0) {
                action._u.goAheadData.duration.ft_s = (CORBA_unsigned_long)(durationMs / 1000);
                action._u.goAheadData.duration.ft_t = (CORBA_unsigned_long)(durationMs % 1000);
            }
        } else {
            action._d = Unit_MA_GoBackward;
            action._u.goBackwardData.speed = (CORBA_float)qAbs(linearVelocity);
            action._u.goBackwardData.duration.keep =
                (durationMs <= 0) ? ilu_TRUE : ilu_FALSE;
            if (durationMs > 0) {
                action._u.goBackwardData.duration.ft_s = (CORBA_unsigned_long)(durationMs / 1000);
                action._u.goBackwardData.duration.ft_t = (CORBA_unsigned_long)(durationMs % 1000);
            }
        }
    } else {
        action._d = Unit_MA_Stop;
        action._u.stopData.keep = ilu_TRUE;
    }

    Unit_rpc_sendMoveAction(proxy, &action, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        if (errOut)
            *errOut = QStringLiteral("ILU error %1").arg(ev.returnCode);
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    return true;
}

struct TargetDispatchResult {
    bool accepted = false;
    bool mock = false;
    QString errorCode;
    QString message;
};

static TargetDispatchResult dispatchTaskPoint(const QString &unitId, double x, double y) {
    const TaskRpcResult rpc = LegacyIdlAdapter::instance().setTaskPoint(unitId, x, y);
    TargetDispatchResult result;
    result.accepted = rpc.success;
    result.mock = rpc.mock;
    result.errorCode = rpc.errorCode;
    result.message = rpc.message;
    return result;
}

static TargetDispatchResult dispatchTaskPath(const QString &unitId, const QJsonArray &points) {
    const TaskRpcResult rpc = LegacyIdlAdapter::instance().setTaskPath(unitId, points);
    TargetDispatchResult result;
    result.accepted = rpc.success;
    result.mock = rpc.mock;
    result.errorCode = rpc.errorCode;
    result.message = rpc.message;
    return result;
}

static bool readTaskPose(const QString &unitId, double *x, double *y, QString *error) {
    const TaskPoseResult pose = LegacyIdlAdapter::instance().currentPose(unitId);
    if (!pose.success) {
        if (error)
            *error = pose.message;
        return false;
    }
    if (x) *x = pose.x;
    if (y) *y = pose.y;
    return true;
}

static void startTargetPolling(const QString &taskId, const QString &unitId,
                               double targetX, double targetY, double toleranceM,
                               int timeoutMs) {
    QTimer *timer = new QTimer();
    timer->setInterval(200);
    const qint64 startedAt = QDateTime::currentMSecsSinceEpoch();
    QObject::connect(timer, &QTimer::timeout,
                     [taskId, unitId, targetX, targetY, toleranceM,
                      timeoutMs, startedAt, timer]() {
        TaskManager &manager = TaskManager::instance();
        TaskManager::TaskEntry snapshot;
        if (!manager.taskSnapshot(taskId, &snapshot) || snapshot.state != "RUNNING") {
            timer->stop();
            timer->deleteLater();
            return;
        }

        double currentX = 0.0;
        double currentY = 0.0;
        QString poseError;
        if (!readTaskPose(unitId, &currentX, &currentY, &poseError)) {
            const qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startedAt;
            if (elapsed > timeoutMs) {
                manager.updateSubTask(taskId, unitId, "TIMEOUT", 100.0,
                                      "UNIT_OFFLINE", poseError);
                manager.finalizeTaskIfAllSubTasksTerminal(taskId);
                timer->stop();
                timer->deleteLater();
            }
            return;
        }

        double dx = targetX - currentX;
        double dy = targetY - currentY;
        double distance = qSqrt(dx * dx + dy * dy);
        char *sbh = sbhForUid(unitId);
        if (sbh && MockRobotSimulator::isMockSbh(sbh) &&
            distance > toleranceM && distance > 0.0) {
            const double step = qMin(distance, 0.06);
            MockRobotSimulator::instance().setPose(
                unitId,
                currentX + (dx / distance) * step,
                currentY + (dy / distance) * step,
                qAtan2(dy, dx));
        }

        const double initialDistance = qMax(1.0, qSqrt(targetX * targetX + targetY * targetY));
        const double progress = distance <= toleranceM
            ? 100.0 : qBound(0.0, 100.0 * (1.0 - distance / initialDistance), 99.0);
        manager.updateSubTask(taskId, unitId, "RUNNING", progress, QString(),
                              QStringLiteral("dist=%1m").arg(distance, 0, 'f', 2));

        if (distance <= toleranceM) {
            manager.updateSubTask(taskId, unitId, "COMPLETED", 100.0);
            manager.finalizeTaskIfAllSubTasksTerminal(taskId);
            timer->stop();
            timer->deleteLater();
            return;
        }

        const qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startedAt;
        if (elapsed > timeoutMs) {
            manager.updateSubTask(taskId, unitId, "TIMEOUT", 100.0,
                                  "TIMEOUT", QStringLiteral("navigation timeout"));
            manager.finalizeTaskIfAllSubTasksTerminal(taskId);
            timer->stop();
            timer->deleteLater();
        }
    });
    TaskManager::instance().registerTimer(taskId, timer);
    timer->start();
}

static TargetDispatchResult dispatchAndTrackTarget(
    const QString &taskId, const QString &unitId, double x, double y,
    double toleranceM, int timeoutMs) {
    const TaskRpcResult rpc = TaskOrchestrator::instance().dispatchTarget(
        taskId, unitId, x, y, toleranceM, timeoutMs);
    TargetDispatchResult result;
    result.accepted = rpc.success;
    result.mock = rpc.mock;
    result.errorCode = rpc.errorCode;
    result.message = rpc.message;
    return result;
}

static bool sendStopToUnitId(const QString &unitId, bool *mockOut, QString *errorOut) {
    const TaskRpcResult result = TaskOrchestrator::instance().stopUnit(unitId);
    if (mockOut)
        *mockOut = result.mock;
    if (errorOut)
        *errorOut = result.message;
    return result.success;
}

} // namespace

HttpApiExecutor::HttpApiExecutor(QObject *parent) : QObject(parent) {
    connect(&TaskManager::instance(), &TaskManager::taskStateChanged, this,
            [](const QString &taskId, const QString &state) {
        if (taskId != consoleFollowFormationRecord.activeMoveTaskId)
            return;
        if (state == QStringLiteral("COMPLETED")) {
            consoleFollowFormationRecord.ready = true;
            consoleFollowFormationRecord.state = QStringLiteral("READY");
            consoleFollowFormationRecord.message =
                QStringLiteral("leader reached target; formation remains READY");
            consoleFollowFormationRecord.errorCode.clear();
        } else if (state == QStringLiteral("CANCELLED")) {
            consoleFollowFormationRecord.ready = true;
            consoleFollowFormationRecord.state = QStringLiteral("READY");
            consoleFollowFormationRecord.message =
                QStringLiteral("leader move cancelled; formation remains READY");
            consoleFollowFormationRecord.errorCode.clear();
        } else if (state == QStringLiteral("FAILED") ||
                   state == QStringLiteral("TIMEOUT") ||
                   state == QStringLiteral("REJECTED")) {
            consoleFollowFormationRecord.ready = false;
            consoleFollowFormationRecord.state = QStringLiteral("FAILED");
            consoleFollowFormationRecord.message =
                QStringLiteral("leader move ended with %1").arg(state);
            TaskManager::TaskEntry snapshot;
            consoleFollowFormationRecord.errorCode =
                TaskManager::instance().taskSnapshot(taskId, &snapshot) &&
                        !snapshot.errorCode.isEmpty()
                    ? snapshot.errorCode : state;
        } else {
            return;
        }
        consoleFollowFormationRecord.activeMoveTaskId.clear();
    });
}

QByteArray HttpApiExecutor::buildXy2dMonitorEventPayload() {
    QJsonObject root;
    root.insert(QStringLiteral("ts_ms"), QJsonValue(QDateTime::currentMSecsSinceEpoch()));
    {
        QMutexLocker lock(&monitorMutex_);
        root.insert(QStringLiteral("natural_language"), QJsonValue(monitorNaturalLanguage_));
        const QString phase = monitorPhaseText_.isEmpty() ? QString::fromUtf8("空闲") : monitorPhaseText_;
        root.insert(QStringLiteral("phase_text"), QJsonValue(phase));
        root.insert(QStringLiteral("mcp_logs"), QJsonValue(mcpLogs_));
    }

    QJsonArray robots;
    if (Units_Hash_Table) {
        ilu_HashEnumerator_s he{};
        ilu_refany uid = nullptr;
        ilu_refany sbh = nullptr;
        ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
        while (ilu_hash_Next(&he, &uid, &sbh)) {
            const QString unitId = QString::fromUtf8((const char *)uid);
            if (MockRobotSimulator::isMockSbh((char *)sbh)) {
                const bool isAir = isAirUnitId(unitId);
                const QJsonObject data = isAir
                    ? MockRobotSimulator::instance().airStatusJson(unitId)
                    : MockRobotSimulator::instance().groundStatusJson(unitId);
                if (!data.value(QStringLiteral("online")).toBool())
                    continue;
                const QJsonObject pose = data.value(QStringLiteral("pose")).toObject();
                QJsonObject r;
                r.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
                r.insert(QStringLiteral("x_m"), QJsonValue(pose.value(QStringLiteral("x")).toDouble()));
                r.insert(QStringLiteral("y_m"), QJsonValue(pose.value(QStringLiteral("y")).toDouble()));
                r.insert(QStringLiteral("yaw_rad"), QJsonValue(pose.value(QStringLiteral("yaw")).toDouble()));
                if (isAir)
                    r.insert(QStringLiteral("z_m"), QJsonValue(pose.value(QStringLiteral("z")).toDouble()));
                robots.append(QJsonValue(r));
                continue;
            }
            /**
             * @description
             * XY2D SSE 监控帧以“轻量、不卡主线程”为目标：只读取 MOCK 状态，不在该 1Hz 路径内做 ILU 同步 RPC。
             * 真实单元状态请使用 /api/robot/status 或 /api/robot/list 等接口单独查询，避免监控页拖慢主控 UI。
             */
            Q_UNUSED(unitId);
            Q_UNUSED(sbh);
        }
    }
    root.insert(QStringLiteral("robots"), QJsonValue(robots));
    return QJsonDocument(root).toJson(QJsonDocument::Compact);
}

/**
 * @brief 工作线程经 BlockingQueuedConnection 调入；输出 HTTP 状态写入 lastHttpStatus_。
 * @note 局部变量勿命名为 `st`，以免遮蔽全局 `extern ServerThread *st`。
 */
QByteArray HttpApiExecutor::processRequestSlot(const QString &method, const QString &path,
                                               const QString &query, const QByteArray &body) {
    int httpStatusOut = 200;
    QByteArray r = processRequest(method, path, query, body, &httpStatusOut);
    lastHttpStatus_ = httpStatusOut;
    return r;
}

QByteArray HttpApiExecutor::processRequest(const QString &method, const QString &path,
                                           const QString &query, const QByteArray &body,
                                           int *httpStatus) {
    /* /api/agent/* 路由委托给 AgentHttpController */
    if (path.startsWith(QStringLiteral("/api/agent/")) && agentHttpController_) {
        return agentHttpController_->processRequest(method, path, query, body, httpStatus);
    }

    if (path == QStringLiteral("/api/robot/list") && method == QStringLiteral("GET")) {
        QJsonArray arr;
        if (Units_Hash_Table) {
            ilu_HashEnumerator_s he{};
            ilu_refany uid = nullptr;
            ilu_refany sbh = nullptr;
            ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
            while (ilu_hash_Next(&he, &uid, &sbh)) {
                QJsonObject one;
                one.insert(QStringLiteral("unit_id"), QJsonValue(QString::fromUtf8((const char *)uid)));
                one.insert(QStringLiteral("mock"), QJsonValue(MockRobotSimulator::isMockSbh((const char *)sbh)));
                arr.append(QJsonValue(one));
            }
        }
        QJsonObject data;
        data.insert(QStringLiteral("units"), QJsonValue(arr));
        data.insert(QStringLiteral("rpc_enabled"), QJsonValue(isRealUnitRpcEnabled()));
        return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/robot/status")) {
        QString unitId;
        if (method == QStringLiteral("GET")) {
            QUrlQuery q(query);
            unitId = q.queryItemValue(QStringLiteral("unit_id"), QUrl::FullyDecoded);
        } else if (method == QStringLiteral("POST")) {
            QJsonParseError pe{};
            QJsonDocument doc = QJsonDocument::fromJson(body, &pe);
            if (doc.isObject()) {
                QJsonObject o = doc.object();
                unitId = o.value(QStringLiteral("unit_id")).toString();
                if (unitId.isEmpty())
                    unitId = o.value(QStringLiteral("uid")).toString();
            }
        }
        if (unitId.isEmpty())
            return jsonResponse(false, QStringLiteral("missing unit_id"), QJsonValue::Null, httpStatus);

        char *sbh = sbhForUid(unitId);
        if (!sbh)
            return jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);

        if (MockRobotSimulator::isMockSbh(sbh)) {
            QJsonObject data = isAirUnitId(unitId)
                ? MockRobotSimulator::instance().airStatusJson(unitId)
                : MockRobotSimulator::instance().groundStatusJson(unitId);
            return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        CORBA_Environment ev;
        QJsonObject data;
        data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));

        if (unitId.startsWith(QLatin1Char('G'))) {
            Ground_Unit_rpc g = (Ground_Unit_rpc)ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev);
            if (!ILU_C_SUCCESSFUL(&ev) || !g) {
                QString msg = QStringLiteral("SBHToObject failed");
                ILU_C_EXCEPTION_FREE(&ev);
                return jsonResponse(false, msg, QJsonValue::Null, httpStatus);
            }
            Ground_Unit_Pose2D pose = Ground_Unit_rpc_getCurrentPose(g, &ev);
            if (ILU_C_SUCCESSFUL(&ev)) {
                QJsonObject p;
                p.insert(QStringLiteral("x"), QJsonValue((double)pose.x));
                p.insert(QStringLiteral("y"), QJsonValue((double)pose.y));
                p.insert(QStringLiteral("yaw"), QJsonValue((double)pose.yaw));
                data.insert(QStringLiteral("pose"), QJsonValue(p));
            } else {
                ILU_C_EXCEPTION_FREE(&ev);
            }
            {
                CORBA_Environment evSpd;
                Ground_Unit_Speed2D spd = Ground_Unit_rpc_getCurrentSpeed(g, &evSpd);
                if (ILU_C_SUCCESSFUL(&evSpd)) {
                    QJsonObject s;
                    s.insert(QStringLiteral("linear_m_s"), QJsonValue((double)spd.leanerVel));
                    s.insert(QStringLiteral("angular_rad_s"), QJsonValue((double)spd.angularVel));
                    data.insert(QStringLiteral("speed"), QJsonValue(s));
                } else {
                    ILU_C_EXCEPTION_FREE(&evSpd);
                }
            }
            Ground_Unit_rpc__Free(&g);
            data.insert(QStringLiteral("online"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
        }

        if (unitId.startsWith(QLatin1Char('A'))) {
            Air_Unit_rpc a = (Air_Unit_rpc)ILU_C_SBHToObject(sbh, Air_Unit_rpc__MSType, &ev);
            if (!ILU_C_SUCCESSFUL(&ev) || !a) {
                ILU_C_EXCEPTION_FREE(&ev);
                return jsonResponse(false, QStringLiteral("SBHToObject failed"), QJsonValue::Null, httpStatus);
            }
            Air_Unit_Pose3D pose = Air_Unit_rpc_getCurrentPose(a, &ev);
            if (ILU_C_SUCCESSFUL(&ev)) {
                QJsonObject p;
                p.insert(QStringLiteral("x"), QJsonValue((double)pose.x));
                p.insert(QStringLiteral("y"), QJsonValue((double)pose.y));
                p.insert(QStringLiteral("z"), QJsonValue((double)pose.z));
                p.insert(QStringLiteral("yaw"), QJsonValue((double)pose.yaw));
                data.insert(QStringLiteral("pose"), QJsonValue(p));
            } else {
                ILU_C_EXCEPTION_FREE(&ev);
            }
            Air_Unit_rpc__Free(&a);
            data.insert(QStringLiteral("online"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
        }

        return jsonResponse(false, QStringLiteral("unknown unit_id prefix"), QJsonValue::Null, httpStatus);
    }

    if (path == QStringLiteral("/api/robot/sendmove") && method == QStringLiteral("POST")) {
        QElapsedTimer requestTimer;
        requestTimer.start();
        QJsonParseError pe{};
        QJsonDocument doc = QJsonDocument::fromJson(body, &pe);
        if (!doc.isObject() || pe.error != QJsonParseError::NoError)
            return jsonResponse(false, QStringLiteral("invalid JSON"), QJsonValue::Null, httpStatus);

        QJsonObject o = doc.object();
        QString unitId = o.value(QStringLiteral("unit_id")).toString();
        if (unitId.isEmpty())
            unitId = o.value(QStringLiteral("uid")).toString();
        if (unitId.isEmpty())
            return jsonResponse(false, QStringLiteral("missing unit_id"), QJsonValue::Null, httpStatus);

        double lv = o.value(QStringLiteral("linear_velocity")).toDouble();
        double av = o.value(QStringLiteral("angular_velocity")).toDouble();
        int durationMs = o.value(QStringLiteral("duration_ms")).toInt(1000);
        if (durationMs < 0)
            durationMs = 0;

        /** @brief 与 MCP `config.LINEAR_VELOCITY_MAX_ABS_M_S` / 角速度上限对齐的演示安全阈值 */
        constexpr double kMaxLinearAbsMS = 5.0;
        constexpr double kMaxAngularAbsRadS = 10.0;
        if (qAbs(lv) > kMaxLinearAbsMS || qAbs(av) > kMaxAngularAbsRadS) {
            return jsonResponse(
                false,
                QStringLiteral("speed_out_of_bounds: exceeds console max safe limits"),
                QJsonValue::Null,
                httpStatus);
        }

        char *sbh = sbhForUid(unitId);
        if (!sbh)
            return jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);

        if (MockRobotSimulator::isMockSbh(sbh)) {
            QElapsedTimer executionTimer;
            executionTimer.start();
            MockRobotSimulator::instance().applyMove(unitId, lv, av, durationMs);
            const double executionMs = elapsedMilliseconds(executionTimer);
            if (st) {
                emit st->infoAppended(
                    QStringLiteral("[MOCK] %1 move lv=%2 av=%3 dur_ms=%4")
                        .arg(unitId)
                        .arg(lv)
                        .arg(av)
                        .arg(durationMs));
            }
            QJsonObject data;
            data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
            data.insert(QStringLiteral("linear_velocity"), QJsonValue(lv));
            data.insert(QStringLiteral("angular_velocity"), QJsonValue(av));
            data.insert(QStringLiteral("duration_ms"), QJsonValue(durationMs));
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            insertBenchmarkTimings(
                &data, 0.0,
                elapsedMilliseconds(requestTimer) - executionMs,
                executionMs, false);
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        CORBA_Environment ev;
        Unit_rpc proxy = (Unit_rpc)ILU_C_SBHToObject(sbh, Unit_rpc__MSType, &ev);
        if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
            ILU_C_EXCEPTION_FREE(&ev);
            return jsonResponse(false, QStringLiteral("SBHToObject failed"), QJsonValue::Null, httpStatus);
        }

        QString err;
        QElapsedTimer executionTimer;
        executionTimer.start();
        bool ok = sendMoveToProxy(proxy, lv, av, durationMs, &err);
        const double executionMs = elapsedMilliseconds(executionTimer);
        Unit_rpc__Free(&proxy);
        if (!ok)
            return jsonResponse(false, err, QJsonValue::Null, httpStatus);

        QJsonObject data;
        data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
        data.insert(QStringLiteral("linear_velocity"), QJsonValue(lv));
        data.insert(QStringLiteral("angular_velocity"), QJsonValue(av));
        data.insert(QStringLiteral("duration_ms"), QJsonValue(durationMs));
        insertBenchmarkTimings(
            &data, 0.0, elapsedMilliseconds(requestTimer) - executionMs,
            executionMs, false);
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/robot/stop") && method == QStringLiteral("POST")) {
        QJsonParseError pe{};
        QJsonDocument doc = QJsonDocument::fromJson(body, &pe);
        if (!doc.isObject())
            return jsonResponse(false, QStringLiteral("invalid JSON"), QJsonValue::Null, httpStatus);
        QString unitId = doc.object().value(QStringLiteral("unit_id")).toString();
        if (unitId.isEmpty())
            unitId = doc.object().value(QStringLiteral("uid")).toString();
        if (unitId.isEmpty())
            return jsonResponse(false, QStringLiteral("missing unit_id"), QJsonValue::Null, httpStatus);

        char *sbh = sbhForUid(unitId);
        if (!sbh)
            return jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);

        if (MockRobotSimulator::isMockSbh(sbh)) {
            MockRobotSimulator::instance().stop(unitId);
            if (st)
                emit st->infoAppended(QStringLiteral("[MOCK] %1 stop").arg(unitId));
            QJsonObject out;
            out.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
            out.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("stopped"), out, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        CORBA_Environment ev;
        Unit_rpc proxy = (Unit_rpc)ILU_C_SBHToObject(sbh, Unit_rpc__MSType, &ev);
        if (!ILU_C_SUCCESSFUL(&ev) || !proxy) {
            ILU_C_EXCEPTION_FREE(&ev);
            return jsonResponse(false, QStringLiteral("SBHToObject failed"), QJsonValue::Null, httpStatus);
        }
        QString err;
        bool ok = sendStopToProxy(proxy, &err);
        Unit_rpc__Free(&proxy);
        if (!ok)
            return jsonResponse(false, err, QJsonValue::Null, httpStatus);
        QJsonObject out;
        out.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
        return jsonResponseObj(true, QStringLiteral("stopped"), out, httpStatus);
    }

    if (path == QStringLiteral("/api/robot/stop_all") && method == QStringLiteral("POST")) {
        if (!Units_Hash_Table)
            return jsonResponseObj(true, QStringLiteral("no units"), QJsonObject(), httpStatus);

        ilu_HashEnumerator_s he{};
        ilu_refany uid = nullptr;
        ilu_refany sbh = nullptr;
        int n = 0;
        int mockN = 0;
        ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
        while (ilu_hash_Next(&he, &uid, &sbh)) {
            if (MockRobotSimulator::isMockSbh((char *)sbh)) {
                MockRobotSimulator::instance().stop(QString::fromUtf8((char *)uid));
                n++;
                mockN++;
                continue;
            }
            if (!isRealUnitRpcEnabled())
                continue;
            CORBA_Environment ev;
            Unit_rpc proxy = (Unit_rpc)ILU_C_SBHToObject((char *)sbh, Unit_rpc__MSType, &ev);
            if (ILU_C_SUCCESSFUL(&ev) && proxy) {
                sendStopToProxy(proxy, nullptr);
                Unit_rpc__Free(&proxy);
                n++;
            } else {
                ILU_C_EXCEPTION_FREE(&ev);
            }
        }
        if (st && mockN > 0)
            emit st->infoAppended(QString::fromUtf8("[MOCK] stop_all 已停止 %1 台模拟车").arg(mockN));
        QJsonObject data;
        data.insert(QStringLiteral("stopped_count"), QJsonValue(n));
        return jsonResponseObj(true, QStringLiteral("stop_all issued"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/formation/set_leader") && method == QStringLiteral("POST")) {
        if (!consoleFollowFormationRecord.ownerId.isEmpty()) {
            QJsonObject data;
            data.insert(QStringLiteral("error_code"), QStringLiteral("FORMATION_CONFLICT"));
            return jsonResponseObj(false,
                QStringLiteral("task-level follow formation owns the selected members"),
                data, httpStatus, 409);
        }
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        const QString unitId = o.value(QStringLiteral("unit_id")).toString().trimmed();
        if (unitId.isEmpty())
            return jsonResponse(false, QStringLiteral("missing unit_id"), QJsonValue::Null, httpStatus);
        if (!isGroundUnitId(unitId))
            return jsonResponse(false, QStringLiteral("unit_id must be a ground unit id"), QJsonValue::Null, httpStatus);

        char *sbh = sbhForUid(unitId);
        if (!sbh)
            return jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);

        QJsonObject data;
        data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
        const bool isMock = MockRobotSimulator::isMockSbh(sbh);

        if (isMock) {
            // Mock 路径: 直接设置 currentLeaderUID，绕过 CORBA RPC
            // mock SBH ("MOCK:xxx") 不是有效 CORBA IOR，getUnitObject/setToLeader 会失败
            if (currentLeaderUID != NULL) {
                ilu_free(currentLeaderUID);
                currentLeaderUID = NULL;
            }
            QByteArray uidBytes = unitId.toUtf8();
            currentLeaderUID = (Unit_UnitID)ilu_malloc(strlen(uidBytes.data()) + 1);
            strcpy(currentLeaderUID, uidBytes.data());
            qDebug() << "[HttpApi] mock set_leader:" << unitId
                     << "currentLeaderUID=" << currentLeaderUID;

            consoleFollowFormationRecord.clear();
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }

        // Real 路径: 需要 CORBA RPC 连接
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        QByteArray uidBytes = unitId.toUtf8();
        if (!getUnitObject(uidBytes.data()))
            return jsonResponse(false, QStringLiteral("failed to select leader unit"), QJsonValue(data), httpStatus);
        if (!setToLeader())
            return jsonResponse(false, QStringLiteral("failed to set leader"), QJsonValue(data), httpStatus);

        consoleFollowFormationRecord.clear();
        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/formation/send_follow") && method == QStringLiteral("POST")) {
        if (!consoleFollowFormationRecord.ownerId.isEmpty()) {
            QJsonObject data;
            data.insert(QStringLiteral("error_code"), QStringLiteral("FORMATION_CONFLICT"));
            return jsonResponseObj(false,
                QStringLiteral("task-level follow formation owns the selected members"),
                data, httpStatus, 409);
        }
        QJsonObject request;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &request, &errResp, httpStatus))
            return errResp;

        const QString leaderId = request.value(QStringLiteral("leader_id")).toString().trimmed();
        const QJsonValue followersValue = request.value(QStringLiteral("followers"));
        if (leaderId.isEmpty() || !followersValue.isArray() || followersValue.toArray().isEmpty())
            return jsonResponse(false, QStringLiteral("leader_id and followers are required"),
                                QJsonValue::Null, httpStatus);
        if (!isGroundUnitId(leaderId) || sbhForUid(leaderId) == NULL)
            return jsonResponse(false, QStringLiteral("leader must be a bound ground unit"),
                                QJsonValue(leaderId), httpStatus);
        if (currentLeaderUID == NULL || leaderId != QString::fromUtf8(currentLeaderUID))
            return jsonResponse(false, QStringLiteral("requested leader does not match Console leader"),
                                QJsonValue(leaderId), httpStatus, 409);

        QSet<QString> seen;
        seen.insert(leaderId);
        QStringList followerIds;
        QVector<float> requestedDistances;
        FollowFormationSnapshot candidate;
        candidate.leaderId = leaderId;
        bool allMock = MockRobotSimulator::isMockSbh(sbhForUid(leaderId));

        const QJsonArray inputFollowers = followersValue.toArray();
        for (const QJsonValue &value : inputFollowers) {
            if (!value.isObject())
                return jsonResponse(false, QStringLiteral("each follower must be an object"),
                                    QJsonValue::Null, httpStatus);
            const QJsonObject item = value.toObject();
            const QString uid = item.value(QStringLiteral("unit_id")).toString().trimmed();
            double distance = 0.0;
            char *sbh = sbhForUid(uid);
            if (!isGroundUnitId(uid) || sbh == NULL || seen.contains(uid) ||
                !readFiniteNumber(item, QStringLiteral("distance_m"), &distance) || distance <= 0.0) {
                return jsonResponse(false,
                                    QStringLiteral("invalid, duplicate, or unbound follower/distance"),
                                    QJsonValue(uid), httpStatus);
            }
            seen.insert(uid);
            followerIds.append(uid);
            requestedDistances.append((float)distance);
            allMock = allMock && MockRobotSimulator::isMockSbh(sbh);

            FollowFormationMember member;
            member.unitId = uid;
            member.requestedDistanceM = distance;
            member.effectiveDistanceM = effectiveGroundFollowDistance((float)distance);
            candidate.followers.append(member);
        }

        QString buildError;
        Unit_Formation *follow = buildGroundFollowFormation(
            leaderId, followerIds, requestedDistances, &buildError);
        if (follow == NULL)
            return jsonResponse(false, buildError, QJsonValue::Null, httpStatus);

        QJsonObject data;
        bool accepted = false;
        if (allMock) {
            accepted = true;
            consoleFollowFormationRecord.ready = true;
            consoleFollowFormationRecord.state = QStringLiteral("READY");
            consoleFollowFormationRecord.message = QStringLiteral("legacy Mock follow formation READY");
            consoleFollowFormationRecord.leaderId = leaderId;
            consoleFollowFormationRecord.followerIds = followerIds;
            consoleFollowFormationRecord.requestedDistances = requestedDistances;
            for (float requested : requestedDistances) {
                consoleFollowFormationRecord.effectiveDistances.append(
                    effectiveGroundFollowDistance(requested));
            }
            data.insert(QStringLiteral("success_count"), followerIds.size() + 1);
            data.insert(QStringLiteral("fail_count"), 0);
            data.insert(QStringLiteral("failed_units"), QJsonArray());
            data.insert(QStringLiteral("mock"), true);
        } else {
            if (!isRealUnitRpcEnabled()) {
                freeUnitFormation(follow);
                return realUnitRpcDisabledResponse(httpStatus);
            }
            const FormationResult result = setFormationWithResult(follow);
            const int successCount = result.airResult.successCount + result.groundResult.successCount;
            const int failCount = result.airResult.failCount + result.groundResult.failCount;
            accepted = followFormationDispatchIsReady(
                successCount, failCount, followerIds.size() + 1);
            data.insert(QStringLiteral("success_count"), successCount);
            data.insert(QStringLiteral("fail_count"), failCount);
            data.insert(QStringLiteral("failed_units"), failedFormationUnitsJson(result));
            data.insert(QStringLiteral("mock"), false);
            if (accepted) {
                consoleFollowFormationRecord.ready = true;
                consoleFollowFormationRecord.state = QStringLiteral("READY");
                consoleFollowFormationRecord.message = QStringLiteral("legacy real follow formation READY");
                consoleFollowFormationRecord.leaderId = leaderId;
                consoleFollowFormationRecord.followerIds = followerIds;
                consoleFollowFormationRecord.requestedDistances = requestedDistances;
                consoleFollowFormationRecord.effectiveDistances.clear();
                for (float requested : requestedDistances)
                    consoleFollowFormationRecord.effectiveDistances.append(
                        effectiveGroundFollowDistance(requested));
            }
        }
        freeUnitFormation(follow);

        candidate.ready = accepted;
        const QJsonObject snapshot = candidate.toJson();
        for (auto it = snapshot.constBegin(); it != snapshot.constEnd(); ++it)
            data.insert(it.key(), it.value());
        return jsonResponseObj(
            accepted,
            accepted ? QStringLiteral("follow formation dispatched")
                     : QStringLiteral("follow formation dispatch failed"),
            data, httpStatus, 409);
    }

    if (path == QStringLiteral("/api/formation/status") && method == QStringLiteral("GET")) {
        FollowFormationSnapshot status;
        const QString currentLeader = currentLeaderUID != NULL
            ? QString::fromUtf8(currentLeaderUID) : QString();
        status.ready = consoleFollowFormationRecord.ready &&
            !currentLeader.isEmpty() &&
            consoleFollowFormationRecord.leaderId == currentLeader &&
            currentMode == Unit_UM_Follow;
        status.leaderId = currentLeader;
        if (status.ready) {
            for (int i = 0; i < consoleFollowFormationRecord.followerIds.size(); ++i) {
                FollowFormationMember member;
                member.unitId = consoleFollowFormationRecord.followerIds.at(i);
                member.requestedDistanceM =
                    consoleFollowFormationRecord.requestedDistances.value(i);
                member.effectiveDistanceM =
                    consoleFollowFormationRecord.effectiveDistances.value(i);
                status.followers.append(member);
            }
        }
        return jsonResponseObj(true, QStringLiteral("ok"), status.toJson(), httpStatus);
    }

    if (path == QStringLiteral("/api/formation/goto_target") && method == QStringLiteral("POST")) {
        QJsonObject request;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &request, &errResp, httpStatus))
            return errResp;
        double x = 0.0;
        double y = 0.0;
        if (!readFiniteNumber(request, QStringLiteral("x"), &x) ||
            !readFiniteNumber(request, QStringLiteral("y"), &y)) {
            return jsonResponse(false, QStringLiteral("x and y must be finite numbers"),
                                QJsonValue::Null, httpStatus);
        }
        if (!consoleFollowFormationRecord.ready || currentLeaderUID == NULL)
            return jsonResponse(false, QStringLiteral("follow formation is not ready"),
                                QJsonValue::Null, httpStatus, 409);
        const QString leaderId = QString::fromUtf8(currentLeaderUID);
        if (consoleFollowFormationRecord.leaderId != leaderId)
            return jsonResponse(false, QStringLiteral("current leader changed"),
                                QJsonValue(leaderId), httpStatus, 409);

        char *leaderSbh = sbhForUid(leaderId);
        if (leaderSbh == NULL)
            return jsonResponse(false, QStringLiteral("leader is not bound"),
                                QJsonValue(leaderId), httpStatus);
        if (!MockRobotSimulator::isMockSbh(leaderSbh)) {
            if (!isRealUnitRpcEnabled())
                return realUnitRpcDisabledResponse(httpStatus);
            QByteArray leaderBytes = leaderId.toUtf8();
            if (!getUnitObject(leaderBytes.data()) || !setTaskPoint((float)x, (float)y))
                return jsonResponse(false, QStringLiteral("failed to set leader target point"),
                                    QJsonValue(leaderId), httpStatus);
        }

        QJsonObject point;
        point.insert(QStringLiteral("x"), x);
        point.insert(QStringLiteral("y"), y);
        QJsonObject data;
        data.insert(QStringLiteral("leader_id"), leaderId);
        data.insert(QStringLiteral("point"), point);
        data.insert(QStringLiteral("mock"), MockRobotSimulator::isMockSbh(leaderSbh));
        return jsonResponseObj(true, QStringLiteral("target accepted for leader"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/formation/set_group_mode") && method == QStringLiteral("POST")) {
        if (!consoleFollowFormationRecord.ownerId.isEmpty()) {
            QJsonObject data;
            data.insert(QStringLiteral("error_code"), QStringLiteral("FORMATION_CONFLICT"));
            return jsonResponseObj(false,
                QStringLiteral("task-level follow formation owns the selected members"),
                data, httpStatus, 409);
        }
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        const QString mode = o.value(QStringLiteral("mode")).toString().trimmed().toLower();
        Unit_UnitMode unitMode = Unit_UM_None;
        if (!parseGroupMode(mode, &unitMode))
            return jsonResponse(false, QStringLiteral("mode must be one of none/follow/imitate/mate"), QJsonValue::Null,
                                httpStatus);

        const GroundFleetState state = groundFleetState();
        if (state.groundCount <= 0)
            return jsonResponse(false, QStringLiteral("no ground units bound"), QJsonValue::Null, httpStatus);

        QJsonObject data = groundFleetData(state);
        data.insert(QStringLiteral("mode"), QJsonValue(mode));
        const bool allMock = (state.realCount == 0);

        if (allMock) {
            // Mock 路径: 直接设置 currentMode，绕过 setGroupMode() 的 CORBA RPC
            // mock 单元没有 CORBA 端点，无法通过 RPC 设置角色/模式
            if (currentLeaderUID == NULL) {
                qDebug() << "[HttpApi] mock set_group_mode: leader not set, reject";
                return jsonResponse(false,
                    QStringLiteral("mock leader not set - call /api/formation/set_leader first"),
                    QJsonValue(data), httpStatus);
            }
            currentMode = unitMode;
            qDebug() << "[HttpApi] mock set_group_mode:" << mode
                     << "currentLeaderUID=" << currentLeaderUID
                     << "currentMode=" << (int)currentMode;

            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }

        // Real 路径: 需要 CORBA RPC 连接
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        if (!setGroupMode(unitMode))
            return jsonResponse(false, QStringLiteral("failed to set group mode"), QJsonValue(data), httpStatus);
        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/formation/set_group_minor_mode") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        const QString mode = o.value(QStringLiteral("minor_mode")).toString().trimmed().toLower();
        Unit_UnitMinorMode minorMode = Unit_UMM_None;
        if (!parseMinorMode(mode, &minorMode))
            return jsonResponse(false, QStringLiteral("minor_mode must be one of none/object/track"),
                                QJsonValue::Null, httpStatus);

        const GroundFleetState state = groundFleetState();
        if (state.groundCount <= 0)
            return jsonResponse(false, QStringLiteral("no ground units bound"), QJsonValue::Null, httpStatus);

        QJsonObject data = groundFleetData(state);
        data.insert(QStringLiteral("minor_mode"), QJsonValue(mode));
        const bool allMock = (state.realCount == 0);

        if (allMock) {
            // Mock 路径: 直接设置 currentMinorMode，绕过 setGroupMinorMode() 的 CORBA RPC
            currentMinorMode = minorMode;
            qDebug() << "[HttpApi] mock set_group_minor_mode:" << mode
                     << "currentMinorMode=" << (int)currentMinorMode;

            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }

        // Real 路径: 需要 CORBA RPC 连接
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        if (!setGroupMinorMode(minorMode))
            return jsonResponse(false, QStringLiteral("failed to set group minor mode"), QJsonValue(data), httpStatus);
        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/set_point") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        const QString unitId = o.value(QStringLiteral("unit_id")).toString().trimmed();
        double x = 0.0;
        double y = 0.0;
        if (unitId.isEmpty())
            return jsonResponse(false, QStringLiteral("missing unit_id"), QJsonValue::Null, httpStatus);
        if (!isGroundUnitId(unitId))
            return jsonResponse(false, QStringLiteral("unit_id must be a ground unit id"), QJsonValue::Null, httpStatus);
        if (!readFiniteNumber(o, QStringLiteral("x"), &x) || !readFiniteNumber(o, QStringLiteral("y"), &y))
            return jsonResponse(false, QStringLiteral("x and y must be finite numbers"), QJsonValue::Null, httpStatus);

        char *sbh = sbhForUid(unitId);
        if (!sbh)
            return jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);

        QJsonObject point;
        point.insert(QStringLiteral("x"), QJsonValue(x));
        point.insert(QStringLiteral("y"), QJsonValue(y));
        QJsonObject data;
        data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
        data.insert(QStringLiteral("point"), QJsonValue(point));
        if (MockRobotSimulator::isMockSbh(sbh)) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }

        Ground_Unit_rpc proxy = groundProxyForUnit(unitId, &errResp, httpStatus);
        if (!proxy)
            return errResp;
        CORBA_Environment ev;
        Ground_Unit_Point2D p{};
        p.x = (CORBA_float)x;
        p.y = (CORBA_float)y;
        const CORBA_boolean ok = Ground_Unit_rpc_setTaskPoint(proxy, &p, &ev);
        Ground_Unit_rpc__Free(&proxy);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            const QString msg = QStringLiteral("ILU error %1").arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
            return jsonResponse(false, msg, QJsonValue(data), httpStatus);
        }
        if (!ok)
            return jsonResponse(false, QStringLiteral("failed to set task point"), QJsonValue(data), httpStatus);

        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/set_path") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        const QString unitId = o.value(QStringLiteral("unit_id")).toString().trimmed();
        if (unitId.isEmpty())
            return jsonResponse(false, QStringLiteral("missing unit_id"), QJsonValue::Null, httpStatus);
        if (!isGroundUnitId(unitId))
            return jsonResponse(false, QStringLiteral("unit_id must be a ground unit id"), QJsonValue::Null, httpStatus);

        const QJsonValue pointsValue = o.value(QStringLiteral("points"));
        if (!pointsValue.isArray())
            return jsonResponse(false, QStringLiteral("points must be an array with 1..10 items"), QJsonValue::Null,
                                httpStatus);
        const QJsonArray pointsArray = pointsValue.toArray();
        if (pointsArray.size() < 1 || pointsArray.size() > 10)
            return jsonResponse(false, QStringLiteral("points must be an array with 1..10 items"), QJsonValue::Null,
                                httpStatus);

        QJsonArray normalized;
        for (const QJsonValue &v : pointsArray) {
            if (!v.isObject())
                return jsonResponse(false, QStringLiteral("each point must be an object"), QJsonValue::Null, httpStatus);
            const QJsonObject po = v.toObject();
            double x = 0.0;
            double y = 0.0;
            if (!readFiniteNumber(po, QStringLiteral("x"), &x) || !readFiniteNumber(po, QStringLiteral("y"), &y))
                return jsonResponse(false, QStringLiteral("each point must contain finite x and y"), QJsonValue::Null,
                                    httpStatus);
            QJsonObject p;
            p.insert(QStringLiteral("x"), QJsonValue(x));
            p.insert(QStringLiteral("y"), QJsonValue(y));
            normalized.append(QJsonValue(p));
        }

        char *sbh = sbhForUid(unitId);
        if (!sbh)
            return jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);

        QJsonObject data;
        data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
        data.insert(QStringLiteral("points"), QJsonValue(normalized));
        if (MockRobotSimulator::isMockSbh(sbh)) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }

        Ground_Unit_rpc proxy = groundProxyForUnit(unitId, &errResp, httpStatus);
        if (!proxy)
            return errResp;
        Ground_Unit_TaskPath *path2D = Ground_Unit_TaskPath_Create(0, NULL);
        if (!path2D) {
            Ground_Unit_rpc__Free(&proxy);
            return jsonResponse(false, QStringLiteral("failed to allocate task path"), QJsonValue(data), httpStatus);
        }

        ilu_Error appendErr;
        for (const QJsonValue &v : normalized) {
            const QJsonObject po = v.toObject();
            Ground_Unit_Point2D p{};
            p.x = (CORBA_float)po.value(QStringLiteral("x")).toDouble();
            p.y = (CORBA_float)po.value(QStringLiteral("y")).toDouble();
            Ground_Unit_TaskPath_Append(path2D, &p, &appendErr);
        }

        CORBA_Environment ev;
        const CORBA_boolean ok = Ground_Unit_rpc_setTaskPath(proxy, path2D, &ev);
        Ground_Unit_TaskPath__Free(path2D);
        Ground_Unit_rpc__Free(&proxy);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            const QString msg = QStringLiteral("ILU error %1").arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
            return jsonResponse(false, msg, QJsonValue(data), httpStatus);
        }
        if (!ok)
            return jsonResponse(false, QStringLiteral("failed to set task path"), QJsonValue(data), httpStatus);

        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/trap/add") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        double x = 0.0;
        double y = 0.0;
        double radius = 0.0;
        if (!readFiniteNumber(o, QStringLiteral("x"), &x) || !readFiniteNumber(o, QStringLiteral("y"), &y) ||
            !readFiniteNumber(o, QStringLiteral("radius"), &radius))
            return jsonResponse(false, QStringLiteral("x, y and radius must be finite numbers"), QJsonValue::Null,
                                httpStatus);
        if (radius <= 0.0)
            return jsonResponse(false, QStringLiteral("radius must be > 0"), QJsonValue::Null, httpStatus);

        const GroundFleetState state = groundFleetState();
        if (state.groundCount <= 0)
            return jsonResponse(false, QStringLiteral("no ground units bound"), QJsonValue::Null, httpStatus);

        QJsonObject data = groundFleetData(state);
        data.insert(QStringLiteral("x"), QJsonValue(x));
        data.insert(QStringLiteral("y"), QJsonValue(y));
        data.insert(QStringLiteral("radius"), QJsonValue(radius));
        if (state.realCount == 0) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        Console_TrapPoint trap{};
        trap._d = Console_TrapGroundType;
        trap._u.trapPoint2D.point.x = (CORBA_float)x;
        trap._u.trapPoint2D.point.y = (CORBA_float)y;
        trap._u.trapPoint2D.radius = (CORBA_float)radius;
        if (!setTrap(trap))
            return jsonResponse(false, QStringLiteral("failed to add trap point"), QJsonValue(data), httpStatus);
        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/trap/clear") && method == QStringLiteral("POST")) {
        const GroundFleetState state = groundFleetState();
        QJsonObject data = groundFleetData(state);
        if (state.groundCount <= 0)
            return jsonResponseObj(true, QStringLiteral("no ground units"), data, httpStatus);
        if (state.realCount == 0) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        if (!clearTraps())
            return jsonResponse(false, QStringLiteral("failed to clear traps"), QJsonValue(data), httpStatus);
        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/system/reset_relations") && method == QStringLiteral("POST")) {
        const GroundFleetState state = groundFleetState();
        QJsonObject data = groundFleetData(state);
        if (consoleFollowFormationRecord.ready ||
            consoleFollowFormationRecord.state != QStringLiteral("IDLE")) {
            int disbandStatus = 200;
            const QByteArray disbandResponse = processRequest(
                QStringLiteral("POST"),
                QStringLiteral("/api/task/formation/follow/disband"),
                QString(), QByteArray("{}"), &disbandStatus);
            const QJsonObject disbandResult = QJsonDocument::fromJson(disbandResponse).object();
            if (!disbandResult.value(QStringLiteral("success")).toBool()) {
                if (httpStatus)
                    *httpStatus = disbandStatus;
                return disbandResponse;
            }
        }
        if (state.groundCount <= 0) {
            currentMode = Unit_UM_None;
            currentMinorMode = Unit_UMM_None;
            if (currentLeaderUID != NULL) {
                ilu_free(currentLeaderUID);
                currentLeaderUID = NULL;
            }
            return jsonResponseObj(true, QStringLiteral("no ground units"), data, httpStatus);
        }
        if (state.realCount == 0) {
            currentMode = Unit_UM_None;
            currentMinorMode = Unit_UMM_None;
            if (currentLeaderUID != NULL) {
                ilu_free(currentLeaderUID);
                currentLeaderUID = NULL;
            }
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        if (!setDefault())
            return jsonResponse(false, QStringLiteral("some units failed to reset"),
                                QJsonValue(data), httpStatus);
        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/monitor/context") && method == QStringLiteral("POST")) {
        QJsonParseError pe{};
        const QJsonDocument doc = QJsonDocument::fromJson(body, &pe);
        if (!doc.isObject() || pe.error != QJsonParseError::NoError)
            return jsonResponse(false, QStringLiteral("invalid JSON"), QJsonValue::Null, httpStatus);
        const QJsonObject o = doc.object();
        const QString nl = o.value(QStringLiteral("natural_language")).toString();
        const QString ph = o.value(QStringLiteral("phase_text")).toString();
        {
            QMutexLocker lock(&monitorMutex_);
            monitorNaturalLanguage_ = nl;
            monitorPhaseText_ = ph;
        }
        QJsonObject data;
        data.insert(QStringLiteral("natural_language"), QJsonValue(nl));
        data.insert(QStringLiteral("phase_text"), QJsonValue(ph));
        return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/monitor/mcp_log") && method == QStringLiteral("POST")) {
        QJsonParseError pe{};
        const QJsonDocument doc = QJsonDocument::fromJson(body, &pe);
        if (!doc.isObject() || pe.error != QJsonParseError::NoError)
            return jsonResponse(false, QStringLiteral("invalid JSON"), QJsonValue::Null, httpStatus);
        
        QMutexLocker lock(&monitorMutex_);
        mcpLogs_.append(doc.object());
        while (mcpLogs_.size() > 50) {
            mcpLogs_.removeAt(0);
        }
        return jsonResponseObj(true, QStringLiteral("ok"), QJsonObject(), httpStatus);
    }

    // =====================================================================
    // MCP task architecture v2 routes. Legacy routes below remain compatible.
    // =====================================================================
    if (path == QStringLiteral("/api/task/fleet_snapshot") && method == QStringLiteral("GET")) {
        QJsonArray units;
        if (Units_Hash_Table) {
            ilu_HashEnumerator_s enumerator{};
            ilu_refany uid = nullptr;
            ilu_refany sbh = nullptr;
            ilu_hash_BeginEnumeration(Units_Hash_Table, &enumerator);
            while (ilu_hash_Next(&enumerator, &uid, &sbh)) {
                const QString unitId = QString::fromUtf8((const char *)uid);
                const bool mock = MockRobotSimulator::isMockSbh((const char *)sbh);
                QJsonObject unit;
                unit.insert(QStringLiteral("unit_id"), unitId);
                unit.insert(QStringLiteral("run_mode"), mock ? QStringLiteral("sim")
                                                            : QStringLiteral("real"));
                bool online = false;
                bool onlineVerified = false;
                QString probeError;
                const bool isAir = isAirUnitId(unitId);
                if (mock) {
                    const QJsonObject status = isAir
                        ? MockRobotSimulator::instance().airStatusJson(unitId)
                        : MockRobotSimulator::instance().groundStatusJson(unitId);
                    online = status.value(QStringLiteral("online")).toBool(false);
                    onlineVerified = true;
                } else if (isRealUnitRpcEnabled() &&
                           unitId.startsWith(QLatin1Char('G'))) {
                    const TaskPoseResult probe =
                        LegacyIdlAdapter::instance().currentPose(unitId);
                    online = probe.success;
                    onlineVerified = true;
                    if (!probe.success)
                        probeError = probe.message;
                }
                unit.insert(QStringLiteral("online"), online);
                unit.insert(QStringLiteral("online_verified"), onlineVerified);
                unit.insert(QStringLiteral("kind"), QJsonValue(isAir ? QStringLiteral("uav") : QStringLiteral("ugv")));
                unit.insert(QStringLiteral("busy"), TaskManager::instance().isUnitBusy(unitId));
                unit.insert(QStringLiteral("mock"), mock);
                unit.insert(QStringLiteral("rpc_available"), mock || isRealUnitRpcEnabled());
                if (!probeError.isEmpty())
                    unit.insert(QStringLiteral("probe_error"), probeError);
                units.append(unit);
            }
        }
        QJsonObject data;
        data.insert(QStringLiteral("units"), units);
        data.insert(QStringLiteral("rpc_enabled"), isRealUnitRpcEnabled());
        return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/capabilities") && method == QStringLiteral("GET")) {
        const GroundFleetState fleet = groundFleetState();
        const TaskCapabilityPolicy policy = TaskOrchestrator::capabilityPolicy(
            fleet.mockCount, fleet.realCount, isRealUnitRpcEnabled());
        QJsonObject capabilities;
        auto addCapability = [&capabilities](const QString &name, bool supported,
                                             const QString &reason) {
            QJsonObject flag;
            flag.insert(QStringLiteral("supported"), supported);
            flag.insert(QStringLiteral("reason"), reason);
            capabilities.insert(name, flag);
        };
        addCapability(QStringLiteral("target_point_navigation"), policy.targetPointNavigation,
            policy.targetPointNavigation ? QStringLiteral("Ground_Unit.setTaskPoint supports executable x/y targets")
                                         : QStringLiteral("no executable ground unit is available"));
        addCapability(QStringLiteral("path_tasks"), policy.pathTasks,
            policy.pathTasks ? QStringLiteral("Ground_Unit.setTaskPath is executable; completion is inferred from observed poses")
                             : QStringLiteral("no executable ground unit is available"));
        addCapability(QStringLiteral("static_geometric_formation"), policy.staticFormation,
            policy.staticFormation ? QStringLiteral("Console computes rotated/translated x/y targets and dispatches setTaskPoint")
                                   : QStringLiteral("at least two executable ground units are required"));
        addCapability(QStringLiteral("continuous_follow_formation"), policy.followFormation,
            policy.followFormation
                ? QStringLiteral("scoped real Ground follow RPC is available")
                : QStringLiteral("requires at least two real ground units and SAU_ENABLE_REAL_RPC=1; Mock is control-plane only"));
        addCapability(QStringLiteral("final_yaw"), false,
            QStringLiteral("Ground_Unit.setTaskPoint accepts only x and y"));
        addCapability(QStringLiteral("navigation_speed"), false,
            QStringLiteral("task-point and task-path RPCs expose no navigation speed parameter"));
        addCapability(QStringLiteral("strict_cancel"), false,
            QStringLiteral("Unit_MA_Stop exists, but base IDLs expose no clearTaskPoint/clearTaskPath"));
        addCapability(QStringLiteral("real_unit_rpc"), policy.realUnitRpc,
            policy.realUnitRpc
                ? QStringLiteral("real ground unit RPC is enabled")
                : QStringLiteral("requires a bound real ground unit and SAU_ENABLE_REAL_RPC=1"));
        QJsonObject data;
        data.insert(QStringLiteral("capabilities"), capabilities);
        data.insert(QStringLiteral("ground_count"), fleet.groundCount);
        data.insert(QStringLiteral("mock_ground_count"), fleet.mockCount);
        data.insert(QStringLiteral("real_ground_count"), fleet.realCount);
        return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
    }

    if ((path == QStringLiteral("/api/task/navigate") ||
         path == QStringLiteral("/api/task/goto_pose")) &&
        method == QStringLiteral("POST")) {
        const QString taskType = LegacyIdlAdapter::taskTypeForNavigateRoute(path);
        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }

        const QString unitId = request.value(QStringLiteral("unit_id")).toString().trimmed();
        double x = 0.0;
        double y = 0.0;
        double tolerance = 0.15;
        int timeoutMs = request.value(QStringLiteral("timeout_ms")).toInt(30000);
        if (!isGroundUnitId(unitId) ||
            !readFiniteNumber(request, QStringLiteral("x"), &x) ||
            !readFiniteNumber(request, QStringLiteral("y"), &y)) {
            const QString message =
                QStringLiteral("navigateTo requires a ground unit and finite x/y");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    QStringList() << unitId),
                httpStatus, 400);
        }
        if (request.contains(QStringLiteral("tolerance_m")) &&
            !readFiniteNumber(request, QStringLiteral("tolerance_m"), &tolerance)) {
            const QString message = QStringLiteral("tolerance_m must be finite");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    QStringList() << unitId), httpStatus, 400);
        }
        if (tolerance < 0.02 || timeoutMs <= 0 || timeoutMs > 600000) {
            const QString message = QStringLiteral("invalid tolerance_m or timeout_ms");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    QStringList() << unitId), httpStatus, 400);
        }

        SafetyValidator validator;
        const SafetyValidator::ValidationResult validation =
            validator.validateGotoPose(unitId, x, y, 0.0, 0.0);
        if (!validation.passed) {
            return jsonResponseObj(false, validation.message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    validation.errorCode, validation.message,
                                    QStringList() << unitId), httpStatus,
                                   validation.errorCode == QStringLiteral("UNIT_BUSY") ? 409 : 400);
        }

        QJsonObject params;
        params.insert(QStringLiteral("unit_id"), unitId);
        params.insert(QStringLiteral("target_x"), x);
        params.insert(QStringLiteral("target_y"), y);
        params.insert(QStringLiteral("tolerance_m"), tolerance);
        params.insert(QStringLiteral("timeout_ms"), timeoutMs);
        QString busyUnit;
        const QString taskId = TaskManager::instance().createTaskIfUnitsAvailable(
            taskType, params, QStringList() << unitId, &busyUnit);
        if (taskId.isEmpty()) {
            const QString message =
                QStringLiteral("unit is already assigned to another task");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_CONFLICT"), message,
                                    QStringList() << busyUnit), httpStatus, 409);
        }
        TaskManager::instance().transitionTask(taskId, QStringLiteral("RUNNING"));
        const TaskRpcResult dispatch = TaskOrchestrator::instance().dispatchTarget(
            taskId, unitId, x, y, tolerance, timeoutMs);
        const QJsonObject data = TaskOrchestrator::taskSnapshotJson(taskId);
        return jsonResponseObj(dispatch.success,
            dispatch.success ? QStringLiteral("task accepted") : dispatch.message,
            data, httpStatus,
            dispatch.errorCode == QStringLiteral("RPC_DISABLED") ? 503 : 400);
    }

    if (path == QStringLiteral("/api/task/motion") &&
        method == QStringLiteral("POST")) {
        QElapsedTimer contractTimer;
        contractTimer.start();
        const QString taskType = QStringLiteral("execute_motion");
        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            QJsonObject rejected = immediateTaskResult(
                taskType, QStringLiteral("REJECTED"),
                QStringLiteral("SAFETY_REJECTED"), message);
            insertBenchmarkTimings(
                &rejected, elapsedMilliseconds(contractTimer), 0.0, 0.0, true);
            return jsonResponseObj(
                false, message, rejected,
                httpStatus, 400);
        }

        const QString requestedUnitId =
            request.value(QStringLiteral("unit_id")).toString().trimmed();
        MotionTaskCommand command;
        QString validationCode;
        QString validationMessage;
        const bool unitBound = sbhForUid(requestedUnitId) != NULL;
        if (!TaskOrchestrator::validateMotionRequest(
                request, unitBound, &command, &validationCode,
                &validationMessage)) {
            QJsonObject rejected = immediateTaskResult(
                taskType, QStringLiteral("REJECTED"), validationCode,
                validationMessage, QStringList() << requestedUnitId);
            insertBenchmarkTimings(
                &rejected, elapsedMilliseconds(contractTimer), 0.0, 0.0, true);
            return jsonResponseObj(
                false, validationMessage, rejected,
                httpStatus,
                validationCode == QStringLiteral("UNIT_NOT_FOUND") ? 404 : 400);
        }

        const double contractMs = elapsedMilliseconds(contractTimer);
        QElapsedTimer dispatchTimer;
        dispatchTimer.start();

        QJsonObject params;
        params.insert(QStringLiteral("unit_id"), command.unitId);
        params.insert(QStringLiteral("linear_velocity"), command.linearVelocity);
        params.insert(QStringLiteral("angular_velocity"), command.angularVelocity);
        params.insert(QStringLiteral("duration_ms"), command.durationMs);
        QString busyUnit;
        const QString taskId =
            TaskManager::instance().createTaskIfUnitsAvailable(
                taskType, params, QStringList() << command.unitId, &busyUnit);
        if (taskId.isEmpty()) {
            const QString message =
                QStringLiteral("unit is already assigned to another task");
            return jsonResponseObj(
                false, message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_CONFLICT"), message,
                                    QStringList() << busyUnit),
                httpStatus, 409);
        }

        TaskManager::instance().transitionTask(taskId,
                                               QStringLiteral("RUNNING"));
        const TaskRpcResult dispatch =
            TaskOrchestrator::instance().dispatchMotion(
                taskId, command.unitId, command.linearVelocity,
                command.angularVelocity, command.durationMs);
        QJsonObject data = TaskOrchestrator::taskSnapshotJson(taskId);
        insertBenchmarkTimings(
            &data, contractMs,
            elapsedMilliseconds(dispatchTimer) - dispatch.executionMs,
            dispatch.executionMs, true);
        return jsonResponseObj(
            dispatch.success,
            dispatch.success ? QStringLiteral("task accepted")
                             : dispatch.message,
            data, httpStatus,
            dispatch.errorCode == QStringLiteral("RPC_DISABLED") ? 503 : 400);
    }

    if (path == QStringLiteral("/api/task/follow_path") && method == QStringLiteral("POST")) {
        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("follow_path"), QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }
        const QString unitId = request.value(QStringLiteral("unit_id")).toString().trimmed();
        const QJsonArray points = request.value(QStringLiteral("points")).toArray();
        const double tolerance = request.value(QStringLiteral("tolerance_m")).toDouble(0.15);
        const int timeoutMs = request.value(QStringLiteral("timeout_ms")).toInt(30000);
        if (!isGroundUnitId(unitId) || points.isEmpty() || points.size() > 10 ||
            tolerance < 0.02 || timeoutMs <= 0 || timeoutMs > 600000) {
            const QString message = QStringLiteral("invalid followPath request");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("follow_path"), QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    QStringList() << unitId), httpStatus, 400);
        }
        QJsonArray normalized;
        for (const QJsonValue &value : points) {
            if (!value.isObject()) {
                const QString message =
                    QStringLiteral("each path point must be an object");
                return jsonResponseObj(false, message,
                    immediateTaskResult(QStringLiteral("follow_path"), QStringLiteral("REJECTED"),
                                        QStringLiteral("SAFETY_REJECTED"), message,
                                        QStringList() << unitId), httpStatus, 400);
            }
            double x = 0.0;
            double y = 0.0;
            const QJsonObject point = value.toObject();
            if (!readFiniteNumber(point, QStringLiteral("x"), &x) ||
                !readFiniteNumber(point, QStringLiteral("y"), &y) ||
                qAbs(x) > 1000.0 || qAbs(y) > 1000.0) {
                const QString message =
                    QStringLiteral("each path point requires bounded finite x/y");
                return jsonResponseObj(false, message,
                    immediateTaskResult(QStringLiteral("follow_path"), QStringLiteral("REJECTED"),
                                        QStringLiteral("TARGET_OUT_OF_BOUNDS"), message,
                                        QStringList() << unitId), httpStatus, 400);
            }
            QJsonObject normalizedPoint;
            normalizedPoint.insert(QStringLiteral("x"), x);
            normalizedPoint.insert(QStringLiteral("y"), y);
            normalized.append(normalizedPoint);
        }

        QJsonObject params;
        params.insert(QStringLiteral("unit_id"), unitId);
        params.insert(QStringLiteral("points"), normalized);
        params.insert(QStringLiteral("tolerance_m"), tolerance);
        params.insert(QStringLiteral("timeout_ms"), timeoutMs);
        QString busyUnit;
        const QString taskId = TaskManager::instance().createTaskIfUnitsAvailable(
            QStringLiteral("follow_path"), params, QStringList() << unitId, &busyUnit);
        if (taskId.isEmpty()) {
            const QString message = QStringLiteral("unit is busy");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("follow_path"), QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_CONFLICT"), message,
                                    QStringList() << busyUnit), httpStatus, 409);
        }
        TaskManager::instance().transitionTask(taskId, QStringLiteral("RUNNING"));
        const TaskRpcResult dispatch = TaskOrchestrator::instance().dispatchPath(
            taskId, unitId, normalized, tolerance, timeoutMs);
        QJsonObject data = TaskOrchestrator::taskSnapshotJson(taskId);
        data.insert(QStringLiteral("mock"), dispatch.mock);
        return jsonResponseObj(dispatch.success, dispatch.success
            ? QStringLiteral("path task accepted") : dispatch.message,
            data, httpStatus, dispatch.success ? 400 :
                (dispatch.errorCode == QStringLiteral("RPC_DISABLED") ? 503 : 400));
    }

    if (path == QStringLiteral("/api/task/formation/follow/create") && method == QStringLiteral("POST")) {
        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            FollowFormationSnapshot invalid = currentFollowFormationSnapshot();
            invalid.message = QStringLiteral("invalid JSON");
            QJsonObject data = invalid.toJson();
            data.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
            return jsonResponseObj(false, invalid.message, data, httpStatus, 400);
        }
        if (consoleFollowFormationRecord.state != QStringLiteral("IDLE")) {
            FollowFormationSnapshot conflict = currentFollowFormationSnapshot();
            conflict.message =
                QStringLiteral("an active or failed formation must be disbanded first");
            QJsonObject data = conflict.toJson();
            data.insert(QStringLiteral("error_code"), QStringLiteral("FORMATION_CONFLICT"));
            return jsonResponseObj(false, conflict.message, data, httpStatus, 409);
        }

        LegacyIdlAdapter &legacyAdapter = LegacyIdlAdapter::instance();
        const QString requestedLeaderId =
            request.value(QStringLiteral("leader_id")).toString().trimmed();
        const QString leaderId = legacyAdapter.canonicalUnitId(requestedLeaderId);
        const QJsonValue followersValue = request.value(QStringLiteral("followers"));
        if (leaderId.isEmpty() || !isGroundUnitId(leaderId) ||
            !followersValue.isArray() || followersValue.toArray().isEmpty()) {
            FollowFormationSnapshot invalid = currentFollowFormationSnapshot();
            invalid.message = QStringLiteral("bound ground leader and followers are required");
            QJsonObject data = invalid.toJson();
            data.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
            return jsonResponseObj(false, invalid.message, data, httpStatus, 400);
        }

        QSet<QString> seen;
        seen.insert(leaderId);
        QStringList followerIds;
        QVector<float> requestedDistances;
        FollowFormationSnapshot candidate;
        candidate.state = QStringLiteral("CREATING");
        candidate.leaderId = leaderId;
        int mockCount = legacyAdapter.isMock(leaderId) ? 1 : 0;
        int realCount = mockCount == 0 ? 1 : 0;
        for (const QJsonValue &value : followersValue.toArray()) {
            if (!value.isObject()) {
                FollowFormationSnapshot invalid = currentFollowFormationSnapshot();
                invalid.message = QStringLiteral("each follower must be an object");
                QJsonObject data = invalid.toJson();
                data.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
                return jsonResponseObj(false, invalid.message, data, httpStatus, 400);
            }
            const QJsonObject item = value.toObject();
            const QString requestedUnitId =
                item.value(QStringLiteral("unit_id")).toString().trimmed();
            const QString unitId = legacyAdapter.canonicalUnitId(requestedUnitId);
            double distance = 0.0;
            if (unitId.isEmpty() || !isGroundUnitId(unitId) || seen.contains(unitId) ||
                !readFiniteNumber(item, QStringLiteral("distance_m"), &distance) ||
                !SafetyValidator::isFollowDistanceAllowed(distance)) {
                FollowFormationSnapshot invalid = currentFollowFormationSnapshot();
                invalid.message = QStringLiteral("invalid, duplicate or unbound follower");
                QJsonObject data = invalid.toJson();
                data.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
                data.insert(QStringLiteral("unit_id"), requestedUnitId);
                return jsonResponseObj(false, invalid.message, data, httpStatus, 400);
            }
            seen.insert(unitId);
            followerIds.append(unitId);
            requestedDistances.append((float)distance);
            const bool mock = legacyAdapter.isMock(unitId);
            if (mock)
                ++mockCount;
            else
                ++realCount;

            FollowFormationMember member;
            member.unitId = unitId;
            member.requestedDistanceM = distance;
            member.effectiveDistanceM = effectiveGroundFollowDistance((float)distance);
            candidate.followers.append(member);
        }

        const QStringList members = QStringList() << leaderId << followerIds;
        const FollowSetupPolicy setupPolicy = TaskOrchestrator::followSetupPolicy(
            mockCount, realCount, isRealUnitRpcEnabled());
        if (setupPolicy == FollowSetupPolicy::UnsupportedMixed ||
            setupPolicy == FollowSetupPolicy::RpcDisabled) {
            FollowFormationSnapshot rejected;
            rejected.state = QStringLiteral("IDLE");
            QString errorCode = QStringLiteral("UNSUPPORTED_CAPABILITY");
            int errorStatus = 400;
            if (setupPolicy == FollowSetupPolicy::UnsupportedMixed) {
                rejected.message = QStringLiteral(
                    "mixed Mock/real follow formation is unsupported");
            } else {
                rejected.message = QStringLiteral("real unit rpc is disabled");
                errorCode = QStringLiteral("RPC_DISABLED");
                errorStatus = 503;
            }
            QJsonObject data = rejected.toJson();
            data.insert(QStringLiteral("error_code"), errorCode);
            return jsonResponseObj(false, rejected.message, data, httpStatus, errorStatus);
        }
        const bool dispatchMock = setupPolicy == FollowSetupPolicy::DispatchMock;

        const QString ownerId = QStringLiteral("follow-%1")
            .arg(QUuid::createUuid().toString(QUuid::WithoutBraces).left(8));
        QString busyUnit;
        if (!TaskManager::instance().reserveUnitsIfAvailable(ownerId, members, &busyUnit)) {
            FollowFormationSnapshot conflict = currentFollowFormationSnapshot();
            conflict.message = QStringLiteral("formation member is busy");
            QJsonObject data = conflict.toJson();
            data.insert(QStringLiteral("error_code"), QStringLiteral("TASK_CONFLICT"));
            data.insert(QStringLiteral("unit_id"), busyUnit);
            return jsonResponseObj(false, conflict.message, data, httpStatus, 409);
        }

        consoleFollowFormationRecord.clear();
        consoleFollowFormationRecord.state = QStringLiteral("CREATING");
        consoleFollowFormationRecord.ownerId = ownerId;
        consoleFollowFormationRecord.leaderId = leaderId;
        consoleFollowFormationRecord.followerIds = followerIds;
        consoleFollowFormationRecord.requestedDistances = requestedDistances;
        for (float requested : requestedDistances)
            consoleFollowFormationRecord.effectiveDistances.append(
                effectiveGroundFollowDistance(requested));

        ScopedFollowResult scoped;
        if (dispatchMock) {
            QString mockError;
            scoped.success = MockRobotSimulator::instance().configureFollowFormation(
                leaderId, followerIds,
                consoleFollowFormationRecord.effectiveDistances, &mockError);
            scoped.successCount = scoped.success ? members.size() : 0;
            scoped.failCount = scoped.success ? 0 : members.size();
            scoped.message = scoped.success
                ? QStringLiteral("Mock kinematic follow setup succeeded")
                : mockError;
        } else {
            scoped = createScopedGroundFollow(
                leaderId, followerIds, requestedDistances);
        }
        consoleFollowFormationRecord.physicalSetupAttempted =
            scoped.physicalSetupAttempted;
        consoleFollowFormationRecord.physicalMembers = scoped.physicalMembers;

        if (!scoped.success) {
            if (dispatchMock)
                MockRobotSimulator::instance().clearFollowFormation();
            const bool cleanupComplete =
                !scoped.physicalSetupAttempted || scoped.rollbackSucceeded;
            if (cleanupComplete) {
                TaskManager::instance().releaseReservations(ownerId);
                consoleFollowFormationRecord.clear();
                candidate.state = QStringLiteral("IDLE");
                candidate.leaderId.clear();
                candidate.followers.clear();
            } else {
                consoleFollowFormationRecord.ready = false;
                consoleFollowFormationRecord.state = QStringLiteral("FAILED");
                consoleFollowFormationRecord.message = scoped.message;
                consoleFollowFormationRecord.errorCode =
                    QStringLiteral("INTERNAL_ERROR");
                candidate.state = QStringLiteral("FAILED");
                candidate.errorCode = QStringLiteral("INTERNAL_ERROR");
            }
            candidate.message = scoped.message;
            QJsonObject data = candidate.toJson();
            data.insert(QStringLiteral("failed_units"), QJsonArray::fromStringList(scoped.failedUnits));
            data.insert(QStringLiteral("error_code"), QStringLiteral("INTERNAL_ERROR"));
            return jsonResponseObj(false, scoped.message, data, httpStatus, 409);
        }

        consoleFollowFormationRecord.ready = true;
        consoleFollowFormationRecord.state = QStringLiteral("READY");
        consoleFollowFormationRecord.message = dispatchMock
            ? QStringLiteral("Mock kinematic follow formation READY")
            : QStringLiteral("all scoped follow setup steps succeeded");
        consoleFollowFormationRecord.errorCode.clear();
        candidate.ready = true;
        candidate.state = QStringLiteral("READY");
        candidate.message = consoleFollowFormationRecord.message;
        QJsonObject data = candidate.toJson();
        data.insert(QStringLiteral("mock"), dispatchMock);
        data.insert(QStringLiteral("simulation_scope"), dispatchMock
            ? QStringLiteral("MOCK_KINEMATIC") : QStringLiteral("REAL_RPC"));
        data.insert(QStringLiteral("success_count"), scoped.successCount);
        data.insert(QStringLiteral("fail_count"), scoped.failCount);
        return jsonResponseObj(true, QStringLiteral("follow formation READY"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/formation/follow/move") && method == QStringLiteral("POST")) {
        if (!consoleFollowFormationRecord.ready ||
            consoleFollowFormationRecord.state != QStringLiteral("READY")) {
            const QString message = QStringLiteral("follow formation is not READY");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("move_follow_formation"),
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("FORMATION_NOT_READY"), message),
                httpStatus, 409);
        }
        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("move_follow_formation"),
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    QStringList() << consoleFollowFormationRecord.leaderId),
                httpStatus, 400);
        }
        double x = 0.0;
        double y = 0.0;
        if (!readFiniteNumber(request, QStringLiteral("x"), &x) ||
            !readFiniteNumber(request, QStringLiteral("y"), &y) ||
            !SafetyValidator::isTaskTargetInBounds(x, y)) {
            const QString message = QStringLiteral(
                "x and y must be finite and within [-1000, 1000]");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("move_follow_formation"),
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    QStringList() << consoleFollowFormationRecord.leaderId),
                httpStatus, 400);
        }

        const QString leaderId = consoleFollowFormationRecord.leaderId;
        QJsonObject params;
        params.insert(QStringLiteral("leader_id"), leaderId);
        params.insert(QStringLiteral("target_x"), x);
        params.insert(QStringLiteral("target_y"), y);
        params.insert(QStringLiteral("formation_owner"), consoleFollowFormationRecord.ownerId);
        const QString taskId = TaskManager::instance().createTask(
            QStringLiteral("move_follow_formation"), params, QStringList() << leaderId);
        TaskManager::instance().transitionTask(taskId, QStringLiteral("RUNNING"));
        const TaskRpcResult dispatch = TaskOrchestrator::instance().dispatchTarget(
            taskId, leaderId, x, y, 0.15, 30000);
        if (dispatch.success) {
            consoleFollowFormationRecord.state = QStringLiteral("MOVING");
            consoleFollowFormationRecord.activeMoveTaskId = taskId;
            consoleFollowFormationRecord.message = QStringLiteral("leader target dispatched; followers remain under base Follow logic");
            consoleFollowFormationRecord.errorCode.clear();
        } else {
            consoleFollowFormationRecord.ready = false;
            consoleFollowFormationRecord.state = QStringLiteral("FAILED");
            consoleFollowFormationRecord.message = dispatch.message;
            consoleFollowFormationRecord.errorCode = dispatch.errorCode;
        }
        QJsonObject data = TaskOrchestrator::taskSnapshotJson(taskId);
        data.insert(QStringLiteral("leader_id"), leaderId);
        return jsonResponseObj(dispatch.success,
            dispatch.success ? QStringLiteral("leader move task accepted") : dispatch.message,
            data, httpStatus,
            dispatch.errorCode == QStringLiteral("RPC_DISABLED") ? 503 : 400);
    }

    if (path == QStringLiteral("/api/task/formation/follow/move_sequence") &&
        method == QStringLiteral("POST")) {
        if (!consoleFollowFormationRecord.ready ||
            consoleFollowFormationRecord.state != QStringLiteral("READY")) {
            const QString message = QStringLiteral("follow formation is not READY");
            return jsonResponseObj(
                false, message,
                immediateTaskResult(
                    QStringLiteral("move_follow_formation_sequence"),
                    QStringLiteral("REJECTED"),
                    QStringLiteral("FORMATION_NOT_READY"), message),
                httpStatus, 409);
        }

        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            return jsonResponseObj(
                false, message,
                immediateTaskResult(
                    QStringLiteral("move_follow_formation_sequence"),
                    QStringLiteral("REJECTED"),
                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }

        const QJsonArray inputSegments =
            request.value(QStringLiteral("segments")).toArray();
        QVector<FollowMotionSegment> segments;
        QJsonArray normalizedSegments;
        bool malformed = !request.value(QStringLiteral("segments")).isArray();
        for (const QJsonValue &value : inputSegments) {
            if (!value.isObject()) {
                malformed = true;
                break;
            }
            const QJsonObject object = value.toObject();
            double linearVelocity = 0.0;
            double angularVelocity = 0.0;
            if (!readFiniteNumber(object, QStringLiteral("linear_velocity"),
                                  &linearVelocity) ||
                !readFiniteNumber(object, QStringLiteral("angular_velocity"),
                                  &angularVelocity)) {
                malformed = true;
                break;
            }
            const double durationValue =
                object.value(QStringLiteral("duration_ms")).toDouble(-1.0);
            const double bufferValue = object.contains(QStringLiteral("buffer_ms"))
                ? object.value(QStringLiteral("buffer_ms")).toDouble(-1.0)
                : 1000.0;
            if (!qIsFinite(durationValue) || !qIsFinite(bufferValue) ||
                qFloor(durationValue) != durationValue ||
                qFloor(bufferValue) != bufferValue ||
                durationValue > (std::numeric_limits<int>::max)() ||
                bufferValue > (std::numeric_limits<int>::max)()) {
                malformed = true;
                break;
            }
            const FollowMotionSegment segment(
                linearVelocity, angularVelocity,
                static_cast<int>(durationValue), static_cast<int>(bufferValue));
            segments.append(segment);
            QJsonObject normalized;
            normalized.insert(QStringLiteral("linear_velocity"), linearVelocity);
            normalized.insert(QStringLiteral("angular_velocity"), angularVelocity);
            normalized.insert(QStringLiteral("duration_ms"), segment.durationMs);
            normalized.insert(QStringLiteral("buffer_ms"), segment.bufferMs);
            normalizedSegments.append(normalized);
        }

        QString validationError;
        if (malformed ||
            !TaskOrchestrator::validateFollowMotionSequence(
                segments, &validationError)) {
            const QString message = malformed
                ? QStringLiteral("segments contain invalid fields")
                : validationError;
            return jsonResponseObj(
                false, message,
                immediateTaskResult(
                    QStringLiteral("move_follow_formation_sequence"),
                    QStringLiteral("REJECTED"),
                    QStringLiteral("SAFETY_REJECTED"), message,
                    QStringList() << consoleFollowFormationRecord.leaderId),
                httpStatus, 400);
        }

        const QString leaderId = consoleFollowFormationRecord.leaderId;
        QJsonObject params;
        params.insert(QStringLiteral("leader_id"), leaderId);
        params.insert(QStringLiteral("segments"), normalizedSegments);
        params.insert(QStringLiteral("formation_owner"),
                      consoleFollowFormationRecord.ownerId);
        const QString taskId = TaskManager::instance().createTask(
            QStringLiteral("move_follow_formation_sequence"), params,
            QStringList() << leaderId);
        TaskManager::instance().transitionTask(
            taskId, QStringLiteral("RUNNING"));
        const TaskRpcResult dispatch =
            TaskOrchestrator::instance().dispatchMotionSequence(
                taskId, leaderId, segments);
        if (dispatch.success) {
            consoleFollowFormationRecord.state = QStringLiteral("MOVING");
            consoleFollowFormationRecord.activeMoveTaskId = taskId;
            consoleFollowFormationRecord.message =
                QStringLiteral("Leader motion sequence accepted");
            consoleFollowFormationRecord.errorCode.clear();
        } else {
            consoleFollowFormationRecord.ready = true;
            consoleFollowFormationRecord.state = QStringLiteral("READY");
            consoleFollowFormationRecord.activeMoveTaskId.clear();
            consoleFollowFormationRecord.message = dispatch.message;
            consoleFollowFormationRecord.errorCode = dispatch.errorCode;
        }

        QJsonObject data = TaskOrchestrator::taskSnapshotJson(taskId);
        data.insert(QStringLiteral("leader_id"), leaderId);
        data.insert(QStringLiteral("segment_count"), segments.size());
        return jsonResponseObj(
            dispatch.success,
            dispatch.success
                ? QStringLiteral("leader motion sequence accepted")
                : dispatch.message,
            data, httpStatus,
            dispatch.errorCode == QStringLiteral("RPC_DISABLED") ? 503 : 400);
    }

    if (path == QStringLiteral("/api/task/formation/follow/status") && method == QStringLiteral("GET")) {
        if (consoleFollowFormationRecord.state == QStringLiteral("MOVING") &&
            !consoleFollowFormationRecord.activeMoveTaskId.isEmpty()) {
            TaskManager::TaskEntry moveTask;
            if (TaskManager::instance().taskSnapshot(
                    consoleFollowFormationRecord.activeMoveTaskId, &moveTask) &&
                moveTask.state != QStringLiteral("RUNNING") &&
                moveTask.state != QStringLiteral("PENDING")) {
                if (moveTask.state == QStringLiteral("COMPLETED")) {
                    consoleFollowFormationRecord.ready = true;
                    consoleFollowFormationRecord.state = QStringLiteral("READY");
                    consoleFollowFormationRecord.message = QStringLiteral("leader reached target; formation remains READY");
                    consoleFollowFormationRecord.errorCode.clear();
                } else {
                    consoleFollowFormationRecord.ready = false;
                    consoleFollowFormationRecord.state = QStringLiteral("FAILED");
                    consoleFollowFormationRecord.message = QStringLiteral("leader move ended with %1").arg(moveTask.state);
                    consoleFollowFormationRecord.errorCode = moveTask.errorCode.isEmpty()
                        ? moveTask.state : moveTask.errorCode;
                }
                consoleFollowFormationRecord.activeMoveTaskId.clear();
            }
        }

        FollowFormationSnapshot status;
        status.ready = consoleFollowFormationRecord.ready;
        status.state = consoleFollowFormationRecord.state;
        status.leaderId = consoleFollowFormationRecord.leaderId;
        status.activeMoveTaskId = consoleFollowFormationRecord.activeMoveTaskId;
        status.message = consoleFollowFormationRecord.message;
        status.errorCode = consoleFollowFormationRecord.errorCode;
        for (int i = 0; i < consoleFollowFormationRecord.followerIds.size(); ++i) {
            FollowFormationMember member;
            member.unitId = consoleFollowFormationRecord.followerIds.at(i);
            member.requestedDistanceM = consoleFollowFormationRecord.requestedDistances.value(i);
            member.effectiveDistanceM = consoleFollowFormationRecord.effectiveDistances.value(i);
            status.followers.append(member);
        }
        return jsonResponseObj(true, QStringLiteral("ok"), status.toJson(), httpStatus);
    }

    if (path == QStringLiteral("/api/task/formation/follow/disband") && method == QStringLiteral("POST")) {
        if (consoleFollowFormationRecord.state == QStringLiteral("IDLE")) {
            FollowFormationSnapshot idle;
            idle.state = QStringLiteral("IDLE");
            idle.message = QStringLiteral("no active formation");
            return jsonResponseObj(true, QStringLiteral("no active formation"), idle.toJson(), httpStatus);
        }

        const QString ownerId = consoleFollowFormationRecord.ownerId;
        const QString leaderId = consoleFollowFormationRecord.leaderId;
        const bool mockFormation = LegacyIdlAdapter::instance().isMock(leaderId);
        bool leaderStopSafe = true;
        if (!consoleFollowFormationRecord.activeMoveTaskId.isEmpty()) {
            const TaskRpcResult stop = TaskOrchestrator::instance().stopUnit(leaderId);
            leaderStopSafe = stop.success;
            if (stop.success) {
                TaskManager::instance().clearUnitControlUncertain(leaderId);
            } else if (!stop.mock) {
                TaskManager::instance().markUnitControlUncertain(
                    leaderId, QStringLiteral("formation disband leader stop failed"));
            }
            QVector<TaskRpcResult> stops;
            stops.append(stop);
            TaskManager::instance().cancelTask(
                consoleFollowFormationRecord.activeMoveTaskId,
                TaskOrchestrator::cancellationEffect(stops));
        }

        if (mockFormation)
            MockRobotSimulator::instance().clearFollowFormation();

        ScopedFollowResult cleared;
        if (!consoleFollowFormationRecord.physicalSetupAttempted) {
            cleared.success = true;
            cleared.message = QStringLiteral("local follow state cleared");
        } else {
            cleared = clearScopedGroundFollow(
                consoleFollowFormationRecord.physicalMembers);
        }
        if (!cleared.success) {
            for (const QString &failedUnit : cleared.failedUnits) {
                TaskManager::instance().markUnitControlUncertain(
                    failedUnit, QStringLiteral("follow relation cleanup failed"));
            }
        }
        const bool fullyDisbanded = cleared.success && leaderStopSafe;
        if (fullyDisbanded)
            TaskManager::instance().releaseReservations(ownerId);

        FollowFormationSnapshot result;
        result.state = fullyDisbanded ? QStringLiteral("IDLE") : QStringLiteral("FAILED");
        result.message = leaderStopSafe
            ? cleared.message
            : QStringLiteral("follow relations cleared, but Leader stop request failed");
        if (fullyDisbanded) {
            consoleFollowFormationRecord.clear();
        } else {
            consoleFollowFormationRecord.ready = false;
            consoleFollowFormationRecord.state = QStringLiteral("FAILED");
            consoleFollowFormationRecord.message = result.message;
            consoleFollowFormationRecord.errorCode = QStringLiteral("INTERNAL_ERROR");
            result.leaderId = leaderId;
            result.errorCode = QStringLiteral("INTERNAL_ERROR");
        }
        QJsonObject data = result.toJson();
        data.insert(QStringLiteral("failed_units"), QJsonArray::fromStringList(cleared.failedUnits));
        return jsonResponseObj(fullyDisbanded,
            fullyDisbanded ? QStringLiteral("formation disbanded")
                            : QStringLiteral("formation disband partially failed"),
            data, httpStatus, 409);
    }

    // === 混合空地编队（UAV 空中领航 + UGV 地面链式跟随）===
    if (path == QStringLiteral("/api/task/formation/air_ground/disband") && method == QStringLiteral("POST")) {
        if (airGroundFormationRecord.state == QStringLiteral("IDLE")) {
            QJsonObject idle;
            idle.insert(QStringLiteral("state"), QStringLiteral("IDLE"));
            idle.insert(QStringLiteral("message"), QStringLiteral("no active air-ground formation"));
            return jsonResponseObj(true, QStringLiteral("no active air-ground formation"), idle, httpStatus);
        }
        MockRobotSimulator::instance().clearAirGroundFormation();
        airGroundFormationRecord.clear();
        QJsonObject data;
        data.insert(QStringLiteral("state"), QStringLiteral("IDLE"));
        return jsonResponseObj(true, QStringLiteral("air-ground formation disbanded"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/formation/air_ground/status") && method == QStringLiteral("GET")) {
        QJsonObject data;
        data.insert(QStringLiteral("ready"), airGroundFormationRecord.ready);
        data.insert(QStringLiteral("state"), airGroundFormationRecord.state);
        data.insert(QStringLiteral("air_leader"), airGroundFormationRecord.airLeaderId);
        data.insert(QStringLiteral("air_altitude_m"), airGroundFormationRecord.airAltitudeM);
        QJsonArray chain;
        for (int i = 0; i < airGroundFormationRecord.groundChainIds.size(); ++i) {
            QJsonObject member;
            member.insert(QStringLiteral("unit_id"), airGroundFormationRecord.groundChainIds.at(i));
            member.insert(QStringLiteral("distance_m"), airGroundFormationRecord.distances.value(i));
            member.insert(QStringLiteral("angle_rad"), airGroundFormationRecord.anglesRad.value(i));
            chain.append(member);
        }
        data.insert(QStringLiteral("ground_chain"), chain);
        data.insert(QStringLiteral("message"), airGroundFormationRecord.message);
        data.insert(QStringLiteral("error_code"), airGroundFormationRecord.errorCode);
        data.insert(QStringLiteral("mock"), true);
        return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/formation/air_ground") && method == QStringLiteral("POST")) {
        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            return jsonResponseObj(false, QStringLiteral("invalid JSON"), QJsonObject(), httpStatus, 400);
        }
        if (airGroundFormationRecord.state != QStringLiteral("IDLE")) {
            QJsonObject conflict;
            conflict.insert(QStringLiteral("error_code"), QStringLiteral("FORMATION_CONFLICT"));
            return jsonResponseObj(false,
                QStringLiteral("an active air-ground formation must be disbanded first"),
                conflict, httpStatus, 409);
        }

        LegacyIdlAdapter &legacyAdapter = LegacyIdlAdapter::instance();
        const QJsonObject airLeaderObj = request.value(QStringLiteral("air_leader")).toObject();
        const QString requestedAirLeaderId = airLeaderObj.value(QStringLiteral("unit_id")).toString().trimmed();
        const QString airLeaderId = legacyAdapter.canonicalUnitId(requestedAirLeaderId);
        double airAltitudeM = 20.0;
        if (airLeaderObj.contains(QStringLiteral("altitude_m")))
            airAltitudeM = airLeaderObj.value(QStringLiteral("altitude_m")).toDouble();
        if (airLeaderId.isEmpty() || !isAirUnitId(airLeaderId) ||
            !qIsFinite(airAltitudeM) || airAltitudeM < 0.0) {
            return jsonResponseObj(false,
                QStringLiteral("air leader must be a bound A* unit with a finite altitude"),
                QJsonObject(), httpStatus, 400);
        }

        const QJsonArray followersArr = request.value(QStringLiteral("ground_followers")).toArray();
        if (followersArr.isEmpty()) {
            return jsonResponseObj(false, QStringLiteral("ground_followers array is required"),
                QJsonObject(), httpStatus, 400);
        }

        QSet<QString> seen;
        seen.insert(airLeaderId);
        QStringList groundIds;
        QVector<float> distances;
        QVector<float> anglesRad;
        int mockCount = legacyAdapter.isMock(airLeaderId) ? 1 : 0;
        int realCount = mockCount == 0 ? 1 : 0;
        for (const QJsonValue &value : followersArr) {
            if (!value.isObject()) {
                return jsonResponseObj(false, QStringLiteral("each ground follower must be an object"),
                    QJsonObject(), httpStatus, 400);
            }
            const QJsonObject item = value.toObject();
            const QString requestedUnitId = item.value(QStringLiteral("unit_id")).toString().trimmed();
            const QString unitId = legacyAdapter.canonicalUnitId(requestedUnitId);
            double distance = 0.0;
            double angleDeg = 0.0;
            const bool hasAngle = item.contains(QStringLiteral("angle_deg"));
            if (unitId.isEmpty() || !isGroundUnitId(unitId) || seen.contains(unitId) ||
                !readFiniteNumber(item, QStringLiteral("distance_m"), &distance) ||
                !SafetyValidator::isFollowDistanceAllowed(distance) ||
                (hasAngle && !readFiniteNumber(item, QStringLiteral("angle_deg"), &angleDeg)) ||
                angleDeg < -180.0 || angleDeg > 180.0) {
                QJsonObject invalid;
                invalid.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
                invalid.insert(QStringLiteral("unit_id"), requestedUnitId);
                return jsonResponseObj(false,
                    QStringLiteral("invalid, duplicate or unbound ground follower"),
                    invalid, httpStatus, 400);
            }
            seen.insert(unitId);
            groundIds.append(unitId);
            distances.append((float)distance);
            anglesRad.append((float)(angleDeg * 3.14159265358979323846 / 180.0));
            if (legacyAdapter.isMock(unitId))
                ++mockCount;
            else
                ++realCount;
        }

        if (realCount > 0) {
            QJsonObject unsupported;
            unsupported.insert(QStringLiteral("error_code"), QStringLiteral("UNSUPPORTED_CAPABILITY"));
            return jsonResponseObj(false,
                QStringLiteral("real air-ground formation RPC is not yet supported (Mock-only)"),
                unsupported, httpStatus, 400);
        }

        QString buildError;
        Unit_Formation *formation = buildAirGroundFormation(
            airLeaderId, groundIds, distances, anglesRad, &buildError);
        if (!formation) {
            QJsonObject invalid;
            invalid.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
            return jsonResponseObj(false, buildError, invalid, httpStatus, 400);
        }

        FormationResult result = setFormationWithResult(formation);
        freeUnitFormation(formation);

        // 设置空中领航高度（x/y/yaw 保持现状，仅覆盖 z）
        const QJsonObject airStatus = MockRobotSimulator::instance().airStatusJson(airLeaderId);
        const QJsonObject airPose = airStatus.value(QStringLiteral("pose")).toObject();
        MockRobotSimulator::instance().setPose3D(
            airLeaderId,
            airPose.value(QStringLiteral("x")).toDouble(),
            airPose.value(QStringLiteral("y")).toDouble(),
            airAltitudeM,
            airPose.value(QStringLiteral("yaw")).toDouble());

        QString mockError;
        const bool mockOk = MockRobotSimulator::instance().configureAirGroundFormation(
            airLeaderId, groundIds, distances, anglesRad, &mockError);

        airGroundFormationRecord.clear();
        airGroundFormationRecord.airLeaderId = airLeaderId;
        airGroundFormationRecord.airAltitudeM = (float)airAltitudeM;
        airGroundFormationRecord.groundChainIds = groundIds;
        airGroundFormationRecord.distances = distances;
        airGroundFormationRecord.anglesRad = anglesRad;
        airGroundFormationRecord.ready = mockOk;
        airGroundFormationRecord.state = mockOk ? QStringLiteral("READY") : QStringLiteral("FAILED");
        airGroundFormationRecord.message = mockOk
            ? QStringLiteral("air-ground formation READY") : mockError;
        if (!mockOk)
            airGroundFormationRecord.errorCode = QStringLiteral("INTERNAL_ERROR");

        QJsonObject data = formationResultJson(result);
        data.insert(QStringLiteral("ready"), airGroundFormationRecord.ready);
        data.insert(QStringLiteral("state"), airGroundFormationRecord.state);
        data.insert(QStringLiteral("air_leader"), airLeaderId);
        data.insert(QStringLiteral("air_altitude_m"), airAltitudeM);
        data.insert(QStringLiteral("mock"), true);
        return jsonResponseObj(mockOk, airGroundFormationRecord.message, data,
            httpStatus, mockOk ? 200 : 409);
    }

    if (path == QStringLiteral("/api/task/stop_units") && method == QStringLiteral("POST")) {
        QJsonObject request;
        QByteArray errorResponse;
        if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("stop_units"), QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }
        const QJsonArray unitValues = request.value(QStringLiteral("unit_ids")).toArray();
        if (unitValues.isEmpty()) {
            const QString message = QStringLiteral("unit_ids is empty");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("stop_units"), QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }
        QJsonArray unitResults;
        int successCount = 0;
        for (const QJsonValue &value : unitValues) {
            const QString unitId = value.toString().trimmed();
            const TaskRpcResult stop = TaskOrchestrator::instance().stopUnit(unitId);
            const bool stopped = stop.success;
            QJsonObject item;
            item.insert(QStringLiteral("unit_id"), unitId);
            item.insert(QStringLiteral("state"), stopped ? QStringLiteral("COMPLETED")
                                                          : QStringLiteral("FAILED"));
            item.insert(QStringLiteral("progress_pct"), 100.0);
            item.insert(QStringLiteral("error_code"), stop.errorCode);
            item.insert(QStringLiteral("mock"), stop.mock);
            item.insert(QStringLiteral("message"), stopped
                ? (stop.mock ? QStringLiteral("CANCEL_CONFIRMED") : QStringLiteral("STOP_REQUESTED"))
                : stop.message);
            unitResults.append(item);
            if (stopped) {
                ++successCount;
                TaskManager::instance().clearUnitControlUncertain(unitId);
            } else if (!stop.mock) {
                TaskManager::instance().markUnitControlUncertain(
                    unitId, QStringLiteral("explicit stop request failed"));
            }
        }
        const int failCount = unitValues.size() - successCount;
        const QString state = successCount == unitValues.size()
            ? QStringLiteral("COMPLETED")
            : (successCount > 0 ? QStringLiteral("PARTIAL_COMPLETED")
                                : QStringLiteral("FAILED"));
        QJsonObject data;
        data.insert(QStringLiteral("success"), successCount > 0);
        data.insert(QStringLiteral("task_id"), QString());
        data.insert(QStringLiteral("task_type"), QStringLiteral("stop_units"));
        data.insert(QStringLiteral("state"), state);
        data.insert(QStringLiteral("progress_pct"), 100.0);
        data.insert(QStringLiteral("message"), successCount == unitValues.size()
            ? QStringLiteral("stop requested for all units")
            : QStringLiteral("stop requested for some units"));
        data.insert(QStringLiteral("error_code"), successCount > 0
            ? QString() : QStringLiteral("INTERNAL_ERROR"));
        data.insert(QStringLiteral("unit_results"), unitResults);
        data.insert(QStringLiteral("elapsed_ms"), 0);
        data.insert(QStringLiteral("started_at_ms"), QDateTime::currentMSecsSinceEpoch());
        data.insert(QStringLiteral("cancellation_effect"), QStringLiteral("NOT_APPLICABLE"));
        data.insert(QStringLiteral("success_count"), successCount);
        data.insert(QStringLiteral("fail_count"), failCount);
        return jsonResponseObj(successCount > 0,
            data.value(QStringLiteral("message")).toString(),
            data, httpStatus, 409);
    }

    // =====================================================================
    // MCP-IDL: POST /api/task/goto_pose_batch
    // =====================================================================
    if (path == QStringLiteral("/api/task/goto_pose_batch") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        const QJsonValue targetsVal = o.value(QStringLiteral("targets"));
        if (!targetsVal.isArray())
            return jsonResponse(false, QStringLiteral("targets must be an array"), QJsonValue::Null, httpStatus);
        const QJsonArray targets = targetsVal.toArray();

        double tol = o.value(QStringLiteral("tolerance_m")).toDouble(0.15);
        int timeoutMs = o.value(QStringLiteral("timeout_ms")).toInt(30000);

        // 参数范围校验
        if (tol < 0.02 || !qIsFinite(tol)) {
            QJsonObject rejData;
            rejData.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
            return jsonResponseObj(false,
                QStringLiteral("tolerance_m %1 is below minimum 0.02").arg(tol, 0, 'f', 3),
                rejData, httpStatus, 400);
        }
        if (timeoutMs <= 0 || timeoutMs > 600000) {
            QJsonObject rejData;
            rejData.insert(QStringLiteral("error_code"), QStringLiteral("SAFETY_REJECTED"));
            return jsonResponseObj(false,
                QStringLiteral("timeout_ms %1 out of range (1..600000)").arg(timeoutMs),
                rejData, httpStatus, 400);
        }

        // 安全校验
        SafetyValidator sv;
        SafetyValidator::ValidationResult vr = sv.validateGotoPoseBatch(targets);
        if (!vr.passed) {
            QJsonObject rejData;
            rejData.insert(QStringLiteral("error_code"), vr.errorCode);
            return jsonResponseObj(false, vr.message, rejData, httpStatus, 400);
        }

        // 创建 batch 任务
        QStringList unitIds;
        for (const QJsonValue &v : targets) {
            QJsonObject t = v.toObject();
            unitIds.append(t.value("unit_id").toString().trimmed());
        }

        QJsonObject batchParams;
        batchParams.insert(QStringLiteral("targets"), targets);
        batchParams.insert(QStringLiteral("tolerance_m"), tol);
        batchParams.insert(QStringLiteral("timeout_ms"), timeoutMs);

        QString busyUnit;
        QString batchTaskId = TaskManager::instance().createTaskIfUnitsAvailable(
            QStringLiteral("goto_pose_batch"), batchParams, unitIds, &busyUnit);
        if (batchTaskId.isEmpty()) {
            QJsonObject conflict;
            conflict.insert(QStringLiteral("error_code"), QStringLiteral("TASK_CONFLICT"));
            conflict.insert(QStringLiteral("unit_id"), busyUnit);
            return jsonResponseObj(false,
                QStringLiteral("unit %1 is already assigned to another task").arg(busyUnit),
                conflict, httpStatus, 409);
        }
        TaskManager::instance().transitionTask(batchTaskId, QStringLiteral("RUNNING"));

        // Mock and real units share the same dispatch/independent-poll path.
        int acceptedCount = 0;
        QString firstErrorCode;
        QString firstErrorMessage;
        for (const QJsonValue &v : targets) {
            const QJsonObject target = v.toObject();
            const TargetDispatchResult dispatch = dispatchAndTrackTarget(
                batchTaskId,
                target.value(QStringLiteral("unit_id")).toString().trimmed(),
                target.value(QStringLiteral("x")).toDouble(),
                target.value(QStringLiteral("y")).toDouble(),
                tol,
                timeoutMs);
            if (dispatch.accepted) {
                ++acceptedCount;
            } else if (firstErrorCode.isEmpty()) {
                firstErrorCode = dispatch.errorCode;
                firstErrorMessage = dispatch.message;
            }
        }
        TaskManager::instance().finalizeTaskIfAllSubTasksTerminal(batchTaskId);

        QJsonObject data = TaskOrchestrator::taskSnapshotJson(batchTaskId);
        data.insert(QStringLiteral("accepted_count"), acceptedCount);
        data.insert(QStringLiteral("dispatch_failed_count"), targets.size() - acceptedCount);
        const bool accepted = acceptedCount > 0;
        return jsonResponseObj(accepted,
            accepted
                ? (acceptedCount == targets.size()
                    ? QStringLiteral("batch task accepted")
                    : QStringLiteral("batch task partially dispatched"))
                : (firstErrorMessage.isEmpty()
                    ? QStringLiteral("batch dispatch failed") : firstErrorMessage),
            data, httpStatus,
            firstErrorCode == QStringLiteral("RPC_DISABLED") ? 503 : 400);
    }

    // =====================================================================
    // MCP-IDL: POST /api/task/formation/static
    // Legacy:  POST /api/formation/execute
    // =====================================================================
    if ((path == QStringLiteral("/api/task/formation/static") ||
         path == QStringLiteral("/api/formation/execute")) &&
        method == QStringLiteral("POST")) {
        const bool legacyRoute = path == QStringLiteral("/api/formation/execute");
        const QString taskType =
            LegacyIdlAdapter::taskTypeForStaticFormationRoute(path);
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }
        if (legacyRoute) {
            o = LegacyIdlAdapter::withStaticFormationTransformDefaults(o);
        } else if (!o.contains(QStringLiteral("anchor")) ||
                   !o.contains(QStringLiteral("heading_rad"))) {
            const QString message = QStringLiteral(
                "createStaticFormation requires explicit anchor and heading_rad");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType, QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }

        QString ftype = o.value(QStringLiteral("formation_type")).toString().trimmed().toLower();
        if (ftype.isEmpty()) {
            const QString message =
                QStringLiteral("missing formation_type (line|triangle|column)");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }

        // 安全校验
        SafetyValidator sv;
        SafetyValidator::ValidationResult vr = sv.validateFormation(o);
        if (!vr.passed) {
            return jsonResponseObj(false, vr.message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"), vr.errorCode, vr.message),
                httpStatus, 400);
        }

        const QJsonArray unitIdsArr = o.value(QStringLiteral("unit_ids")).toArray();
        QStringList formationUnitIds;
        for (const QJsonValue &unitValue : unitIdsArr)
            formationUnitIds.append(unitValue.toString().trimmed());
        const double spacing = o.value(QStringLiteral("spacing_m")).toDouble(1.0);
        const QJsonObject anchor = o.value(QStringLiteral("anchor")).toObject();
        double anchorX = 0.0;
        double anchorY = 0.0;
        if (!readFiniteNumber(anchor, QStringLiteral("x"), &anchorX) ||
            !readFiniteNumber(anchor, QStringLiteral("y"), &anchorY)) {
            const QString message =
                QStringLiteral("anchor.x and anchor.y must be finite numbers");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    formationUnitIds), httpStatus, 400);
        }
        double heading = 0.0;
        if (!readFiniteNumber(o, QStringLiteral("heading_rad"), &heading)) {
            const QString message =
                QStringLiteral("heading_rad must be a finite number");
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    formationUnitIds), httpStatus, 400);
        }

        QString geometryError;
        const QJsonArray targets = TaskOrchestrator::staticFormationTargets(
            ftype, unitIdsArr, spacing, anchorX, anchorY, heading, &geometryError);
        if (targets.size() != unitIdsArr.size()) {
            const QString message = geometryError.isEmpty()
                ? QStringLiteral("failed to compute formation targets") : geometryError;
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("TARGET_OUT_OF_BOUNDS"), message,
                                    formationUnitIds), httpStatus, 400);
        }

        // 创建 formation 任务 (内部调用 goto_pose_batch 逻辑)
        double tol = o.value(QStringLiteral("tolerance_m")).toDouble(0.15);
        int timeoutMs = o.value(QStringLiteral("timeout_ms")).toInt(30000);

        // 参数范围校验
        if (tol < 0.02 || !qIsFinite(tol)) {
            const QString message =
                QStringLiteral("tolerance_m %1 is below minimum 0.02").arg(tol, 0, 'f', 3);
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    formationUnitIds), httpStatus, 400);
        }
        if (timeoutMs <= 0 || timeoutMs > 600000) {
            const QString message =
                QStringLiteral("timeout_ms %1 out of range (1..600000)").arg(timeoutMs);
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message,
                                    formationUnitIds), httpStatus, 400);
        }

        QStringList unitIds;
        for (const QJsonValue &v : targets)
            unitIds.append(v.toObject().value("unit_id").toString());

        QJsonObject formParams;
        formParams.insert(QStringLiteral("formation_type"), ftype);
        formParams.insert(QStringLiteral("targets"), targets);
        formParams.insert(QStringLiteral("spacing_m"), spacing);
        formParams.insert(QStringLiteral("anchor"), anchor);
        formParams.insert(QStringLiteral("heading_rad"), heading);
        formParams.insert(QStringLiteral("tolerance_m"), tol);
        formParams.insert(QStringLiteral("timeout_ms"), timeoutMs);

        QString busyUnit;
        QString formTaskId = TaskManager::instance().createTaskIfUnitsAvailable(
            taskType, formParams, unitIds, &busyUnit);
        if (formTaskId.isEmpty()) {
            const QString message =
                QStringLiteral("unit %1 is already assigned to another task").arg(busyUnit);
            return jsonResponseObj(false, message,
                immediateTaskResult(taskType,
                                    QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_CONFLICT"), message,
                                    QStringList() << busyUnit), httpStatus, 409);
        }
        TaskManager::instance().transitionTask(formTaskId, QStringLiteral("RUNNING"));

        int acceptedCount = 0;
        QString firstErrorCode;
        QString firstErrorMessage;
        for (const QJsonValue &v : targets) {
            const QJsonObject target = v.toObject();
            const TargetDispatchResult dispatch = dispatchAndTrackTarget(
                formTaskId,
                target.value(QStringLiteral("unit_id")).toString().trimmed(),
                target.value(QStringLiteral("x")).toDouble(),
                target.value(QStringLiteral("y")).toDouble(),
                tol,
                timeoutMs);
            if (dispatch.accepted) {
                ++acceptedCount;
            } else if (firstErrorCode.isEmpty()) {
                firstErrorCode = dispatch.errorCode;
                firstErrorMessage = dispatch.message;
            }
        }
        TaskManager::instance().finalizeTaskIfAllSubTasksTerminal(formTaskId);

        if (st)
            emit st->infoAppended(
                QStringLiteral("[MCP-IDL] create_static_formation task=%1 type=%2 units=%3")
                    .arg(formTaskId).arg(ftype).arg(unitIds.join(',')));

        QJsonObject data = TaskOrchestrator::taskSnapshotJson(formTaskId);
        data.insert(QStringLiteral("formation_type"), ftype);
        data.insert(QStringLiteral("targets"), targets);
        data.insert(QStringLiteral("accepted_count"), acceptedCount);
        data.insert(QStringLiteral("dispatch_failed_count"), targets.size() - acceptedCount);
        const bool accepted = acceptedCount > 0;
        return jsonResponseObj(accepted,
            accepted
                ? (acceptedCount == targets.size()
                    ? QStringLiteral("formation task accepted")
                    : QStringLiteral("formation task partially dispatched"))
                : (firstErrorMessage.isEmpty()
                    ? QStringLiteral("formation dispatch failed") : firstErrorMessage),
            data, httpStatus,
            firstErrorCode == QStringLiteral("RPC_DISABLED") ? 503 : 400);
    }

    // =====================================================================
    // MCP-IDL: GET /api/task/status + POST /api/task/cancel
    // =====================================================================
    if (path == QStringLiteral("/api/task/status") && method == QStringLiteral("GET")) {
        QUrlQuery q(query);
        QString tid = q.queryItemValue(QStringLiteral("task_id"), QUrl::FullyDecoded);
        if (tid.isEmpty()) {
            const QString message = QStringLiteral("missing task_id");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("get_task_status"), QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_NOT_FOUND"), message),
                httpStatus, 400);
        }

        TaskManager::TaskEntry snapshot;
        if (!TaskManager::instance().taskSnapshot(tid, &snapshot)) {
            const QString message = QStringLiteral("task not found");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("get_task_status"), QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_NOT_FOUND"), message),
                httpStatus, 404);
        }

        QJsonObject data = snapshot.toJson();
        data.insert(QStringLiteral("audit_log"), snapshot.auditLog);
        return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/cancel") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus)) {
            const QString message = QStringLiteral("invalid JSON");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("cancel_task"), QStringLiteral("REJECTED"),
                                    QStringLiteral("SAFETY_REJECTED"), message),
                httpStatus, 400);
        }

        QString tid = o.value(QStringLiteral("task_id")).toString().trimmed();
        if (tid.isEmpty()) {
            const QString message = QStringLiteral("missing task_id");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("cancel_task"), QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_NOT_FOUND"), message),
                httpStatus, 400);
        }

        TaskManager::TaskEntry beforeCancel;
        if (!TaskManager::instance().taskSnapshot(tid, &beforeCancel)) {
            const QString message = QStringLiteral("TASK_NOT_FOUND");
            return jsonResponseObj(false, message,
                immediateTaskResult(QStringLiteral("cancel_task"), QStringLiteral("REJECTED"),
                                    QStringLiteral("TASK_NOT_FOUND"), message),
                httpStatus, 404);
        }

        const QStringList unitIds = TaskManager::instance().taskActiveUnitIds(tid);
        QJsonArray stopResults;
        QVector<TaskRpcResult> stopRpcResults;
        for (const QString &unitId : unitIds) {
            const TaskRpcResult stopped = TaskOrchestrator::instance().stopUnit(unitId);
            stopRpcResults.append(stopped);
            if (stopped.success) {
                TaskManager::instance().clearUnitControlUncertain(unitId);
            } else if (!stopped.mock) {
                TaskManager::instance().markUnitControlUncertain(
                    unitId, QStringLiteral("task cancellation stop request failed"));
            }
            QJsonObject item;
            item.insert(QStringLiteral("unit_id"), unitId);
            item.insert(QStringLiteral("success"), stopped.success);
            item.insert(QStringLiteral("mock"), stopped.mock);
            item.insert(QStringLiteral("error_code"), stopped.errorCode);
            item.insert(QStringLiteral("message"), stopped.success
                ? (stopped.mock ? QStringLiteral("CANCEL_CONFIRMED")
                                : QStringLiteral("STOP_REQUESTED"))
                : stopped.message);
            stopResults.append(item);
        }

        const QString cancellationEffect =
            TaskOrchestrator::cancellationEffect(stopRpcResults);
        const QString err = TaskManager::instance().cancelTask(tid, cancellationEffect);
        if (!err.isEmpty()) {
            QStringList cancelUnits;
            for (const TaskManager::SubTask &subTask : beforeCancel.subTasks)
                cancelUnits.append(subTask.unitId);
            QJsonObject errData = immediateTaskResult(
                QStringLiteral("cancel_task"), QStringLiteral("REJECTED"), err, err,
                cancelUnits);
            errData.insert(QStringLiteral("stop_results"), stopResults);
            return jsonResponseObj(false, err, errData, httpStatus,
                                   err == QStringLiteral("TASK_CONFLICT") ? 409 : 400);
        }

        TaskManager::TaskEntry snapshot;
        QJsonObject data;
        if (TaskManager::instance().taskSnapshot(tid, &snapshot))
            data = snapshot.toJson();
        data.insert(QStringLiteral("cancellation_effect"), cancellationEffect);
        data.insert(QStringLiteral("stop_results"), stopResults);
        data.insert(QStringLiteral("strict_cancel_supported"), false);
        data.insert(QStringLiteral("limitation"),
                    QStringLiteral("base IDLs have no clearTaskPoint/clearTaskPath operation"));
        return jsonResponseObj(true, QStringLiteral("task state cancelled; stop effect reported"),
                               data, httpStatus);
    }

    return jsonResponse(false, QStringLiteral("not found"), QJsonValue::Null, httpStatus, 404);
}
