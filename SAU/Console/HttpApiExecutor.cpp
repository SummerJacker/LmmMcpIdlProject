/**
 * @file HttpApiExecutor.cpp
 * @brief HttpApiExecutor：JSON API 与单元 RPC 的桥接实现。
 */

#include "HttpApiExecutor.h"

#include "MockRobotSimulator.h"
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
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMutexLocker>
#include <QSet>
#include <QtMath>
#include <QUrl>
#include <QUrlQuery>

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

} // namespace

HttpApiExecutor::HttpApiExecutor(QObject *parent) : QObject(parent) {}

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
                const QJsonObject data = MockRobotSimulator::instance().groundStatusJson(unitId);
                if (!data.value(QStringLiteral("online")).toBool())
                    continue;
                const QJsonObject pose = data.value(QStringLiteral("pose")).toObject();
                QJsonObject r;
                r.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
                r.insert(QStringLiteral("x_m"), QJsonValue(pose.value(QStringLiteral("x")).toDouble()));
                r.insert(QStringLiteral("y_m"), QJsonValue(pose.value(QStringLiteral("y")).toDouble()));
                r.insert(QStringLiteral("yaw_rad"), QJsonValue(pose.value(QStringLiteral("yaw")).toDouble()));
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
            QJsonObject data = MockRobotSimulator::instance().groundStatusJson(unitId);
            if (unitId.startsWith(QLatin1Char('A')) && data.contains(QStringLiteral("pose"))) {
                QJsonObject p = data.value(QStringLiteral("pose")).toObject();
                p.insert(QStringLiteral("z"), QJsonValue(0.0));
                data.insert(QStringLiteral("pose"), QJsonValue(p));
            }
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
            MockRobotSimulator::instance().applyMove(unitId, lv, av, durationMs);
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
        bool ok = sendMoveToProxy(proxy, lv, av, durationMs, &err);
        Unit_rpc__Free(&proxy);
        if (!ok)
            return jsonResponse(false, err, QJsonValue::Null, httpStatus);

        QJsonObject data;
        data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
        data.insert(QStringLiteral("linear_velocity"), QJsonValue(lv));
        data.insert(QStringLiteral("angular_velocity"), QJsonValue(av));
        data.insert(QStringLiteral("duration_ms"), QJsonValue(durationMs));
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
            consoleFollowFormationRecord.leaderId == currentLeader;
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
        consoleFollowFormationRecord.clear();
        if (state.groundCount <= 0)
            return jsonResponseObj(true, QStringLiteral("no ground units"), data, httpStatus);
        if (state.realCount == 0) {
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
    // MCP-IDL 任务级接口: POST /api/task/goto_pose
    // 对应 mcp_swarm_task.idl SwarmTaskControl::gotoPose
    // =====================================================================
    if (path == QStringLiteral("/api/task/goto_pose") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        const QString unitId = o.value(QStringLiteral("unit_id")).toString().trimmed();
        if (unitId.isEmpty())
            return jsonResponse(false, QStringLiteral("missing unit_id"), QJsonValue::Null, httpStatus);
        if (!isGroundUnitId(unitId))
            return jsonResponse(false, QStringLiteral("goto_pose currently supports ground units only"),
                                QJsonValue::Null, httpStatus);

        double x = 0.0, y = 0.0;
        if (!readFiniteNumber(o, QStringLiteral("x"), &x) ||
            !readFiniteNumber(o, QStringLiteral("y"), &y))
            return jsonResponse(false, QStringLiteral("x and y must be finite numbers"),
                                QJsonValue::Null, httpStatus);

        double lv = o.value(QStringLiteral("linear_speed_m_s")).toDouble(0.3);
        double av = o.value(QStringLiteral("angular_speed_rad_s")).toDouble(0.6);
        double tol = o.value(QStringLiteral("tolerance_m")).toDouble(0.15);
        int timeoutMs = o.value(QStringLiteral("timeout_ms")).toInt(30000);

        // 参数范围校验（与 mcp/safety/validator.py 同步）
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
        SafetyValidator::ValidationResult vr =
            sv.validateGotoPose(unitId, x, y, lv, av);
        if (!vr.passed) {
            TaskManager::instance().appendAudit(
                QStringLiteral("rejected-%1").arg(unitId),
                QStringLiteral("SAFETY_REJECTED"),
                QStringLiteral("%1: %2").arg(vr.errorCode).arg(vr.message));
            QJsonObject rejData;
            rejData.insert(QStringLiteral("error_code"), vr.errorCode);
            return jsonResponseObj(false, vr.message, rejData, httpStatus, 400);
        }

        char *sbh = sbhForUid(unitId);
        if (!sbh)
            return jsonResponse(false, QStringLiteral("unit not bound"), QJsonValue::Null, httpStatus);

        // 创建任务并进入 RUNNING 状态
        QJsonObject params;
        params.insert(QStringLiteral("unit_id"), unitId);
        params.insert(QStringLiteral("target_x"), x);
        params.insert(QStringLiteral("target_y"), y);
        params.insert(QStringLiteral("tolerance_m"), tol);
        params.insert(QStringLiteral("timeout_ms"), timeoutMs);

        QString taskId = TaskManager::instance().createTask(
            QStringLiteral("goto_pose"), params, {unitId});
        TaskManager::instance().transitionTask(taskId, QStringLiteral("RUNNING"));

        // 对 MOCK 单元: 直接调用 setTaskPoint 等价操作 + 启动轮询定时器
        if (MockRobotSimulator::isMockSbh(sbh)) {
            // MOCK: 下发给模拟器 (运动学更新在 buildXy2dMonitorEventPayload 中处理)
            // 启动 QTimer 轮询进度
            QTimer *pollTimer = new QTimer();
            pollTimer->setInterval(200); // 200ms
            QString capturedTaskId = taskId;
            QString capturedUnitId = unitId;
            double capturedX = x, capturedY = y, capturedTol = tol;
            qint64 startMs = QDateTime::currentMSecsSinceEpoch();
            int capturedTimeoutMs = timeoutMs;

            QObject::connect(pollTimer, &QTimer::timeout, [capturedTaskId, capturedUnitId,
                                 capturedX, capturedY, capturedTol, capturedTimeoutMs,
                                 startMs, pollTimer]() {
                TaskManager &tm = TaskManager::instance();
                TaskManager::TaskEntry *entry = tm.getTask(capturedTaskId);
                if (!entry || entry->state != "RUNNING") {
                    // 任务已被取消或完成, 清理
                    return;
                }

                // 读取当前位置
                QJsonObject status = MockRobotSimulator::instance().groundStatusJson(capturedUnitId);
                QJsonObject pose = status.value("pose").toObject();
                double cx = pose.value("x").toDouble();
                double cy = pose.value("y").toDouble();
                double dx = capturedX - cx;
                double dy = capturedY - cy;
                double dist = qSqrt(dx * dx + dy * dy);

                // Mock 运动学: 每 tick (200ms) 朝目标推进 0.06m (0.3m/s * 0.2s)
                if (dist > capturedTol && dist > 0.0) {
                    double step = qMin(dist, 0.06);  // 不超过剩余距离
                    double newX = cx + (dx / dist) * step;
                    double newY = cy + (dy / dist) * step;
                    double newYaw = qAtan2(dy, dx);
                    MockRobotSimulator::instance().setPose(capturedUnitId, newX, newY, newYaw);
                }

                double progress = (dist <= capturedTol) ? 100.0
                    : qMax(0.0, 100.0 * (1.0 - dist / qMax(1.0, qSqrt(capturedX*capturedX + capturedY*capturedY))));

                tm.updateProgress(capturedTaskId, progress);
                tm.updateSubTask(capturedTaskId, capturedUnitId, "RUNNING", progress, "",
                    QStringLiteral("dist=%1m").arg(dist, 0, 'f', 2));

                qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startMs;
                tm.appendAudit(capturedTaskId, "POLL_POSE",
                    QStringLiteral("pos=(%1,%2) dist=%3m progress=%4%").arg(cx, 0, 'f', 2).arg(cy, 0, 'f', 2).arg(dist, 0, 'f', 2).arg(progress, 0, 'f', 1));

                // 到达容差 → 完成
                if (dist <= capturedTol) {
                    tm.transitionTask(capturedTaskId, "COMPLETED");
                    tm.updateSubTask(capturedTaskId, capturedUnitId, "COMPLETED", 100.0);
                    tm.appendAudit(capturedTaskId, "ARRIVED",
                        QStringLiteral("pos=(%1,%2) dist=%3m within %4m").arg(cx, 0, 'f', 2).arg(cy, 0, 'f', 2).arg(dist, 0, 'f', 2).arg(capturedTol, 0, 'f', 2));
                    // 停止自身定时器
                    if (pollTimer) { pollTimer->stop(); pollTimer->deleteLater(); }
                }

                // 超时
                if (elapsed > capturedTimeoutMs) {
                    tm.transitionTask(capturedTaskId, "TIMEOUT", "TIMEOUT",
                        QStringLiteral("elapsed %1ms > %2ms").arg(elapsed).arg(capturedTimeoutMs));
                    tm.updateSubTask(capturedTaskId, capturedUnitId, "TIMEOUT", progress, "TIMEOUT");
                    if (pollTimer) { pollTimer->stop(); pollTimer->deleteLater(); }
                }
            });

            pollTimer->start();
            TaskManager::instance().registerTimer(taskId, pollTimer);

            if (st)
                emit st->infoAppended(
                    QStringLiteral("[MCP-IDL] goto_pose task=%1 unit=%2 target=(%3,%4)")
                        .arg(taskId).arg(unitId).arg(x, 0, 'f', 1).arg(y, 0, 'f', 1));

            TaskManager::TaskEntry *entry = TaskManager::instance().getTask(taskId);
            QJsonObject data = entry ? entry->toJson() : QJsonObject();
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("task accepted"), data, httpStatus);
        }

        // 真实单元: 调用 setTaskPoint + 启动轮询
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        Ground_Unit_rpc proxy = groundProxyForUnit(unitId, &errResp, httpStatus);
        if (!proxy)
            return errResp;

        Ground_Unit_Point2D p{};
        p.x = (CORBA_float)x;
        p.y = (CORBA_float)y;
        CORBA_Environment ev;
        CORBA_boolean ok = Ground_Unit_rpc_setTaskPoint(proxy, &p, &ev);
        Ground_Unit_rpc__Free(&proxy);
        if (!ILU_C_SUCCESSFUL(&ev) || !ok) {
            QString msg = QStringLiteral("ILU setTaskPoint failed: %1").arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
            TaskManager::instance().transitionTask(taskId, "FAILED", "INTERNAL_ERROR", msg);
            TaskManager::TaskEntry *entry = TaskManager::instance().getTask(taskId);
            return jsonResponse(false, msg, entry ? QJsonValue(entry->toJson()) : QJsonValue::Null, httpStatus);
        }

        // 启动轮询定时器 (真实单元: 读 getCurrentPose)
        QTimer *realPollTimer = new QTimer();
        realPollTimer->setInterval(200);
        QString capturedTaskId2 = taskId;
        QString capturedUnitId2 = unitId;
        double capturedX2 = x, capturedY2 = y, capturedTol2 = tol;
        qint64 startMs2 = QDateTime::currentMSecsSinceEpoch();
        int capturedTimeoutMs2 = timeoutMs;

        QObject::connect(realPollTimer, &QTimer::timeout, [capturedTaskId2, capturedUnitId2,
                             capturedX2, capturedY2, capturedTol2, capturedTimeoutMs2,
                             startMs2, realPollTimer]() {
            TaskManager &tm = TaskManager::instance();
            TaskManager::TaskEntry *entry = tm.getTask(capturedTaskId2);
            if (!entry || entry->state != "RUNNING")
                return;

            // 注意: ILU 调用必须在主线程, 这里在 QTimer 回调中 (主线程)
            char *s = sbhForUid(capturedUnitId2);
            if (!s) {
                tm.transitionTask(capturedTaskId2, "FAILED", "UNIT_OFFLINE",
                    QStringLiteral("unit %1 disappeared").arg(capturedUnitId2));
                realPollTimer->stop();
                realPollTimer->deleteLater();
                return;
            }

            CORBA_Environment ev2;
            Ground_Unit_rpc g = (Ground_Unit_rpc)ILU_C_SBHToObject(s, Ground_Unit_rpc__MSType, &ev2);
            if (!ILU_C_SUCCESSFUL(&ev2) || !g) {
                ILU_C_EXCEPTION_FREE(&ev2);
                return; // 重试下一次
            }

            Ground_Unit_Pose2D pose = Ground_Unit_rpc_getCurrentPose(g, &ev2);
            Ground_Unit_rpc__Free(&g);
            if (!ILU_C_SUCCESSFUL(&ev2)) {
                ILU_C_EXCEPTION_FREE(&ev2);
                return;
            }

            double dx = capturedX2 - pose.x;
            double dy = capturedY2 - pose.y;
            double dist = qSqrt(dx * dx + dy * dy);
            double progress = (dist <= capturedTol2) ? 100.0
                : qMax(0.0, 100.0 * (1.0 - dist / qMax(1.0, qSqrt(capturedX2*capturedX2 + capturedY2*capturedY2))));

            tm.updateProgress(capturedTaskId2, progress);
            tm.updateSubTask(capturedTaskId2, capturedUnitId2, "RUNNING", progress, "",
                QStringLiteral("dist=%1m").arg(dist, 0, 'f', 2));

            qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startMs2;
            tm.appendAudit(capturedTaskId2, "POLL_POSE",
                QStringLiteral("pos=(%1,%2) dist=%3m progress=%4%").arg((double)pose.x, 0, 'f', 2).arg((double)pose.y, 0, 'f', 2).arg(dist, 0, 'f', 2).arg(progress, 0, 'f', 1));

            if (dist <= capturedTol2) {
                tm.transitionTask(capturedTaskId2, "COMPLETED");
                tm.updateSubTask(capturedTaskId2, capturedUnitId2, "COMPLETED", 100.0);
                tm.appendAudit(capturedTaskId2, "ARRIVED",
                    QStringLiteral("dist=%1m within %2m").arg(dist, 0, 'f', 2).arg(capturedTol2, 0, 'f', 2));
                realPollTimer->stop();
                realPollTimer->deleteLater();
            }

            if (elapsed > capturedTimeoutMs2) {
                tm.transitionTask(capturedTaskId2, "TIMEOUT", "TIMEOUT",
                    QStringLiteral("elapsed %1ms > %2ms").arg(elapsed).arg(capturedTimeoutMs2));
                tm.updateSubTask(capturedTaskId2, capturedUnitId2, "TIMEOUT", progress, "TIMEOUT");
                realPollTimer->stop();
                realPollTimer->deleteLater();
            }
        });

        realPollTimer->start();
        TaskManager::instance().registerTimer(taskId, realPollTimer);

        TaskManager::TaskEntry *entry2 = TaskManager::instance().getTask(taskId);
        QJsonObject data2 = entry2 ? entry2->toJson() : QJsonObject();
        return jsonResponseObj(true, QStringLiteral("task accepted"), data2, httpStatus);
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

        QString batchTaskId = TaskManager::instance().createTask(
            QStringLiteral("goto_pose_batch"), batchParams, unitIds);
        TaskManager::instance().transitionTask(batchTaskId, QStringLiteral("RUNNING"));

        // 逐一启动子任务 (目前: 对 MOCK 单元调用简易 goto_pose; 真实单元同理)
        for (const QJsonValue &v : targets) {
            QJsonObject t = v.toObject();
            QString uid = t.value("unit_id").toString().trimmed();
            double tx = t.value("x").toDouble();
            double ty = t.value("y").toDouble();

            char *sbh = sbhForUid(uid);
            if (!sbh) {
                TaskManager::instance().updateSubTask(batchTaskId, uid,
                    QStringLiteral("FAILED"), 0.0, QStringLiteral("UNIT_NOT_FOUND"),
                    QStringLiteral("unit %1 not bound").arg(uid));
                continue;
            }

            // 为子任务启动独立轮询 (简化: 使用与 goto_pose 相同的轮询逻辑)
            // MOCK 单元
            if (MockRobotSimulator::isMockSbh(sbh)) {
                QTimer *subTimer = new QTimer();
                subTimer->setInterval(200);
                QString capturedBatchId = batchTaskId;
                QString capturedUid = uid;
                double capturedTx = tx, capturedTy = ty, capturedTol = tol;
                qint64 startMs = QDateTime::currentMSecsSinceEpoch();

                QObject::connect(subTimer, &QTimer::timeout, [capturedBatchId, capturedUid,
                                 capturedTx, capturedTy, capturedTol, timeoutMs, startMs, subTimer]() {
                    TaskManager &tm = TaskManager::instance();
                    TaskManager::TaskEntry *entry = tm.getTask(capturedBatchId);
                    if (!entry || (entry->state != "RUNNING" && entry->state != "PENDING"))
                        return;

                    QJsonObject status = MockRobotSimulator::instance().groundStatusJson(capturedUid);
                    QJsonObject pose = status.value("pose").toObject();
                    double cx = pose.value("x").toDouble();
                    double cy = pose.value("y").toDouble();
                    double dx = capturedTx - cx;
                    double dy = capturedTy - cy;
                    double dist = qSqrt(dx*dx + dy*dy);
                    double prog = (dist <= capturedTol) ? 100.0
                        : qMax(0.0, 100.0 * (1.0 - dist / qMax(1.0, qSqrt(capturedTx*capturedTx + capturedTy*capturedTy))));

                    // Mock 运动学: 每 tick 朝目标推进
                    if (dist > capturedTol && dist > 0.0) {
                        double step = qMin(dist, 0.06);
                        MockRobotSimulator::instance().setPose(capturedUid,
                            cx + (dx/dist)*step, cy + (dy/dist)*step, qAtan2(dy, dx));
                    }

                    tm.updateSubTask(capturedBatchId, capturedUid, "RUNNING", prog);

                    if (dist <= capturedTol) {
                        tm.updateSubTask(capturedBatchId, capturedUid, "COMPLETED", 100.0);
                        tm.appendAudit(capturedBatchId, "SUB_ARRIVED",
                            QStringLiteral("%1 arrived dist=%2m").arg(capturedUid).arg(dist, 0, 'f', 2));
                        subTimer->stop();
                        subTimer->deleteLater();
                    }

                    qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startMs;
                    if (elapsed > timeoutMs) {
                        tm.updateSubTask(capturedBatchId, capturedUid, "TIMEOUT", prog, "TIMEOUT");
                        subTimer->stop();
                        subTimer->deleteLater();
                    }

                    // 检查全部子任务是否都到达终态
                    bool allDone = true;
                    bool anyFailed = false;
                    bool anyCompleted = false;
                    for (const auto &st : entry->subTasks) {
                        if (st.state == "RUNNING" || st.state == "PENDING") {
                            allDone = false;
                            break;
                        }
                        if (st.state == "COMPLETED") anyCompleted = true;
                        if (st.state == "FAILED" || st.state == "TIMEOUT") anyFailed = true;
                    }
                    if (allDone) {
                        if (anyFailed && anyCompleted)
                            tm.transitionTask(capturedBatchId, "PARTIAL_COMPLETED");
                        else if (anyFailed)
                            tm.transitionTask(capturedBatchId, "FAILED");
                        else
                            tm.transitionTask(capturedBatchId, "COMPLETED");
                    }
                });

                subTimer->start();
                TaskManager::instance().updateSubTask(batchTaskId, uid, "RUNNING", 0.0);
                TaskManager::instance().appendAudit(batchTaskId, "SUB_STARTED",
                    QStringLiteral("%1 target=(%2,%3)").arg(uid).arg(tx, 0, 'f', 1).arg(ty, 0, 'f', 1));
            }
            // 真实单元: 跳过 (需要 SAU_ENABLE_REAL_RPC=1)
        }

        TaskManager::TaskEntry *entry = TaskManager::instance().getTask(batchTaskId);
        QJsonObject data = entry ? entry->toJson() : QJsonObject();
        return jsonResponseObj(true, QStringLiteral("batch task accepted"), data, httpStatus);
    }

    // =====================================================================
    // MCP-IDL: POST /api/formation/execute
    // =====================================================================
    if (path == QStringLiteral("/api/formation/execute") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        QString ftype = o.value(QStringLiteral("formation_type")).toString().trimmed().toLower();
        if (ftype.isEmpty())
            return jsonResponse(false, QStringLiteral("missing formation_type (line|triangle|column)"),
                                QJsonValue::Null, httpStatus);

        // 安全校验
        SafetyValidator sv;
        SafetyValidator::ValidationResult vr = sv.validateFormation(o);
        if (!vr.passed) {
            QJsonObject rejData;
            rejData.insert(QStringLiteral("error_code"), vr.errorCode);
            return jsonResponseObj(false, vr.message, rejData, httpStatus, 400);
        }

        QJsonArray unitIdsArr = o.value(QStringLiteral("unit_ids")).toArray();
        double spacing = o.value(QStringLiteral("spacing_m")).toDouble(1.0);

        // 计算编队目标点 (简化: 行编队 + 三角形编队)
        QJsonArray targets;
        if (ftype == "line") {
            // 行编队: 沿 x 轴等间距排列 (以 anchor 或第一个单元当前位置为起点)
            for (int i = 0; i < unitIdsArr.size(); ++i) {
                QJsonObject t;
                t.insert(QStringLiteral("unit_id"), unitIdsArr[i].toString());
                t.insert(QStringLiteral("x"), i * spacing);
                t.insert(QStringLiteral("y"), 0.0);
                targets.append(t);
            }
        } else if (ftype == "triangle") {
            // 三角形编队: 等边三角形
            double h = spacing * qSqrt(3.0) / 2.0; // 高
            QJsonObject t0; t0.insert("unit_id", unitIdsArr[0].toString()); t0.insert("x", 0.0); t0.insert("y", 0.0); targets.append(t0);
            QJsonObject t1; t1.insert("unit_id", unitIdsArr[1].toString()); t1.insert("x", spacing); t1.insert("y", 0.0); targets.append(t1);
            if (unitIdsArr.size() >= 3) {
                QJsonObject t2; t2.insert("unit_id", unitIdsArr[2].toString()); t2.insert("x", spacing/2.0); t2.insert("y", h); targets.append(t2);
            }
        } else {
            // column: 沿 y 轴排列
            for (int i = 0; i < unitIdsArr.size(); ++i) {
                QJsonObject t;
                t.insert(QStringLiteral("unit_id"), unitIdsArr[i].toString());
                t.insert(QStringLiteral("x"), 0.0);
                t.insert(QStringLiteral("y"), i * spacing);
                targets.append(t);
            }
        }

        // 创建 formation 任务 (内部调用 goto_pose_batch 逻辑)
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

        QStringList unitIds;
        for (const QJsonValue &v : targets)
            unitIds.append(v.toObject().value("unit_id").toString());

        QJsonObject formParams;
        formParams.insert(QStringLiteral("formation_type"), ftype);
        formParams.insert(QStringLiteral("targets"), targets);
        formParams.insert(QStringLiteral("tolerance_m"), tol);
        formParams.insert(QStringLiteral("timeout_ms"), timeoutMs);

        QString formTaskId = TaskManager::instance().createTask(
            QStringLiteral("execute_formation"), formParams, unitIds);
        TaskManager::instance().transitionTask(formTaskId, QStringLiteral("RUNNING"));

        // 启动各单元导航 (与 goto_pose_batch 相同轮询逻辑)
        for (const QJsonValue &v : targets) {
            QJsonObject t = v.toObject();
            QString uid = t.value("unit_id").toString().trimmed();
            double tx = t.value("x").toDouble();
            double ty = t.value("y").toDouble();

            char *sbh = sbhForUid(uid);
            if (!sbh) {
                TaskManager::instance().updateSubTask(formTaskId, uid,
                    "FAILED", 0.0, "UNIT_NOT_FOUND");
                continue;
            }

            if (MockRobotSimulator::isMockSbh(sbh)) {
                QTimer *subTimer = new QTimer();
                subTimer->setInterval(200);
                QString capturedFid = formTaskId;
                QString capturedUid = uid;
                double capturedTx = tx, capturedTy = ty, capturedTol = tol;
                qint64 startMs = QDateTime::currentMSecsSinceEpoch();

                QObject::connect(subTimer, &QTimer::timeout, [capturedFid, capturedUid,
                                 capturedTx, capturedTy, capturedTol, timeoutMs, startMs, subTimer]() {
                    TaskManager &tm = TaskManager::instance();
                    TaskManager::TaskEntry *entry = tm.getTask(capturedFid);
                    if (!entry || (entry->state != "RUNNING" && entry->state != "PENDING"))
                        return;

                    QJsonObject status = MockRobotSimulator::instance().groundStatusJson(capturedUid);
                    QJsonObject pose = status.value("pose").toObject();
                    double cx = pose.value("x").toDouble();
                    double cy = pose.value("y").toDouble();
                    double dx = capturedTx - cx;
                    double dy = capturedTy - cy;
                    double dist = qSqrt(dx*dx + dy*dy);
                    double prog = (dist <= capturedTol) ? 100.0
                        : qMax(0.0, 100.0 * (1.0 - dist / qMax(1.0, qSqrt(capturedTx*capturedTx + capturedTy*capturedTy))));

                    // Mock 运动学: 每 tick 朝目标推进
                    if (dist > capturedTol && dist > 0.0) {
                        double step = qMin(dist, 0.06);
                        MockRobotSimulator::instance().setPose(capturedUid,
                            cx + (dx/dist)*step, cy + (dy/dist)*step, qAtan2(dy, dx));
                    }

                    tm.updateSubTask(capturedFid, capturedUid, "RUNNING", prog);

                    if (dist <= capturedTol) {
                        tm.updateSubTask(capturedFid, capturedUid, "COMPLETED", 100.0);
                        tm.appendAudit(capturedFid, "SUB_ARRIVED",
                            QStringLiteral("%1 arrived dist=%2m").arg(capturedUid).arg(dist, 0, 'f', 2));
                        subTimer->stop();
                        subTimer->deleteLater();
                    }

                    qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startMs;
                    if (elapsed > timeoutMs) {
                        tm.updateSubTask(capturedFid, capturedUid, "TIMEOUT", prog, "TIMEOUT");
                        subTimer->stop();
                        subTimer->deleteLater();
                    }

                    // 检查全部完成
                    bool allDone = true, anyFailed = false, anyCompleted = false;
                    for (const auto &st : entry->subTasks) {
                        if (st.state == "RUNNING" || st.state == "PENDING") { allDone = false; break; }
                        if (st.state == "COMPLETED") anyCompleted = true;
                        if (st.state == "FAILED" || st.state == "TIMEOUT") anyFailed = true;
                    }
                    if (allDone) {
                        if (anyFailed && anyCompleted)
                            tm.transitionTask(capturedFid, "PARTIAL_COMPLETED");
                        else if (anyFailed)
                            tm.transitionTask(capturedFid, "FAILED");
                        else
                            tm.transitionTask(capturedFid, "COMPLETED");
                    }
                });

                subTimer->start();
                TaskManager::instance().updateSubTask(formTaskId, uid, "RUNNING", 0.0);
                TaskManager::instance().appendAudit(formTaskId, "SUB_STARTED",
                    QStringLiteral("%1 target=(%2,%3)").arg(uid).arg(tx, 0, 'f', 1).arg(ty, 0, 'f', 1));
            }
        }

        if (st)
            emit st->infoAppended(
                QStringLiteral("[MCP-IDL] execute_formation task=%1 type=%2 units=%3")
                    .arg(formTaskId).arg(ftype).arg(unitIds.join(',')));

        TaskManager::TaskEntry *entry = TaskManager::instance().getTask(formTaskId);
        QJsonObject data = entry ? entry->toJson() : QJsonObject();
        data.insert(QStringLiteral("formation_type"), ftype);
        return jsonResponseObj(true, QStringLiteral("formation task accepted"), data, httpStatus);
    }

    // =====================================================================
    // MCP-IDL: GET /api/task/status + POST /api/task/cancel
    // =====================================================================
    if (path == QStringLiteral("/api/task/status") && method == QStringLiteral("GET")) {
        QUrlQuery q(query);
        QString tid = q.queryItemValue(QStringLiteral("task_id"), QUrl::FullyDecoded);
        if (tid.isEmpty())
            return jsonResponse(false, QStringLiteral("missing task_id"), QJsonValue::Null, httpStatus);

        TaskManager::TaskEntry *entry = TaskManager::instance().getTask(tid);
        if (!entry)
            return jsonResponse(false, QStringLiteral("task not found"), QJsonValue::Null, httpStatus, 404);

        QJsonObject data = entry->toJson();
        data.insert(QStringLiteral("audit_log"), entry->auditLog);
        return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
    }

    if (path == QStringLiteral("/api/task/cancel") && method == QStringLiteral("POST")) {
        QJsonObject o;
        QByteArray errResp;
        if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
            return errResp;

        QString tid = o.value(QStringLiteral("task_id")).toString().trimmed();
        if (tid.isEmpty())
            return jsonResponse(false, QStringLiteral("missing task_id"), QJsonValue::Null, httpStatus);

        QString err = TaskManager::instance().cancelTask(tid);
        if (!err.isEmpty()) {
            QJsonObject errData;
            errData.insert(QStringLiteral("error_code"), err);
            return jsonResponseObj(false, err, errData, httpStatus, 400);
        }

        TaskManager::TaskEntry *entry = TaskManager::instance().getTask(tid);
        QJsonObject data = entry ? entry->toJson() : QJsonObject();
        return jsonResponseObj(true, QStringLiteral("task cancelled"), data, httpStatus);
    }

    return jsonResponse(false, QStringLiteral("not found"), QJsonValue::Null, httpStatus, 404);
}
