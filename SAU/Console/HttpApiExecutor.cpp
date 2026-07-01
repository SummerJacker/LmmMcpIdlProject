/**
 * @file HttpApiExecutor.cpp
 * @brief HttpApiExecutor：JSON API 与单元 RPC 的桥接实现。
 */

#include "HttpApiExecutor.h"

#include "MockRobotSimulator.h"
#include "console.h"
#include "serverthread.h"

extern ServerThread *st;

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
        const QString phase = monitorPhaseText_.isEmpty() ? QStringLiteral("空闲") : monitorPhaseText_;
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
            emit st->infoAppended(QStringLiteral("[MOCK] stop_all 已停止 %1 台模拟车").arg(mockN));
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
        if (MockRobotSimulator::isMockSbh(sbh)) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        QByteArray uidBytes = unitId.toUtf8();
        if (!getUnitObject(uidBytes.data()))
            return jsonResponse(false, QStringLiteral("failed to select leader unit"), QJsonValue(data), httpStatus);
        if (!setToLeader())
            return jsonResponse(false, QStringLiteral("failed to set leader"), QJsonValue(data), httpStatus);

        data.insert(QStringLiteral("mock"), QJsonValue(false));
        return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
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
        if (state.realCount == 0) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
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
        if (state.realCount == 0) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
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
        if (state.groundCount <= 0)
            return jsonResponseObj(true, QStringLiteral("no ground units"), data, httpStatus);
        if (state.realCount == 0) {
            data.insert(QStringLiteral("mock"), QJsonValue(true));
            return jsonResponseObj(true, QStringLiteral("accepted"), data, httpStatus);
        }
        if (!isRealUnitRpcEnabled())
            return realUnitRpcDisabledResponse(httpStatus);

        setDefault();
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

    return jsonResponse(false, QStringLiteral("not found"), QJsonValue::Null, httpStatus, 404);
}
