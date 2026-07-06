/**
 * @file AgentHttpController.cpp
 * @brief Agent HTTP 控制器实现。
 */

#include "AgentHttpController.h"

#include <QDateTime>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>
#include <QUrl>
#include <QUrlQuery>

/* --------------------------------------------------------------------------
 * JSON 响应辅助（与 HttpApiExecutor.cpp 相同的信封模式）
 * -------------------------------------------------------------------------- */
namespace {

QByteArray jsonResponse(bool success, const QString &message, const QJsonValue &data,
                        int *httpStatus, int errorHttpStatus = 400) {
    QJsonObject o;
    o.insert(QStringLiteral("success"), success);
    o.insert(QStringLiteral("message"), QJsonValue(message));
    o.insert(QStringLiteral("data"), data);
    if (httpStatus)
        *httpStatus = success ? 200 : errorHttpStatus;
    return QJsonDocument(o).toJson(QJsonDocument::Compact);
}

static QByteArray jsonResponseObj(bool success, const QString &message, const QJsonObject &obj,
                                  int *httpStatus, int errorHttpStatus = 400) {
    return jsonResponse(success, message, QJsonValue(obj), httpStatus, errorHttpStatus);
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

} // namespace

/* --------------------------------------------------------------------------
 * 构造
 * -------------------------------------------------------------------------- */
AgentHttpController::AgentHttpController(IAgentDirectory *directory,
                                         IAgentStatusService *statusService)
    : directory_(directory), statusService_(statusService) {}

/* --------------------------------------------------------------------------
 * processRequest — 主路由分派
 * -------------------------------------------------------------------------- */
QByteArray AgentHttpController::processRequest(const QString &method, const QString &path,
                                                const QString &query, const QByteArray &body,
                                                int *httpStatus) {
    /* GET /api/agent/list */
    if (path == QStringLiteral("/api/agent/list") && method == QStringLiteral("GET")) {
        return handleList(httpStatus);
    }

    /* GET /api/agent/status?agent=XXX&refresh=0|1 */
    if (path == QStringLiteral("/api/agent/status") && method == QStringLiteral("GET")) {
        return handleStatus(query, httpStatus);
    }

    /* POST /api/agent/alias/set */
    if (path == QStringLiteral("/api/agent/alias/set") && method == QStringLiteral("POST")) {
        return handleAliasSet(body, httpStatus);
    }

    /* POST /api/agent/alias/clear */
    if (path == QStringLiteral("/api/agent/alias/clear") && method == QStringLiteral("POST")) {
        return handleAliasClear(body, httpStatus);
    }

    return jsonResponse(false, QStringLiteral("not found"), QJsonValue::Null, httpStatus, 404);
}

/* --------------------------------------------------------------------------
 * handleList — GET /api/agent/list
 * -------------------------------------------------------------------------- */
QByteArray AgentHttpController::handleList(int *httpStatus) {
    if (!directory_) {
        return jsonResponse(false, QStringLiteral("agent directory not configured"),
                            QJsonValue::Null, httpStatus, 500);
    }
    if (!statusService_) {
        return jsonResponse(false, QStringLiteral("agent status service not configured"),
                            QJsonValue::Null, httpStatus, 500);
    }

    const QVector<AgentLookupResult> bindings = directory_->listBindings();
    const QVector<AgentStatusSnapshot> statuses = statusService_->getAllStatus();

    /* 构建 status map 便于合并 */
    QMap<QString, AgentStatusSnapshot> statusMap;
    for (const AgentStatusSnapshot &s : statuses) {
        statusMap.insert(s.unitId, s);
    }

    QJsonArray agents;
    int onlineCount = 0;
    int offlineCount = 0;
    int unknownCount = 0;
    int mockCount = 0;
    int realCount = 0;

    for (const AgentLookupResult &lr : bindings) {
        AgentStatusSnapshot snap;

        if (statusMap.contains(lr.unitId)) {
            snap = statusMap.value(lr.unitId);
        } else {
            snap.unitId = lr.unitId;
            snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
            snap.unitType = lr.unitType;
            snap.connectionState = ConnectionState::Unknown;
            snap.statusFreshness = StatusFreshness::Unavailable;
        }

        /* 从目录结果补全字段 */
        snap.alias = lr.alias;
        snap.displayName = lr.displayName;
        snap.bindingState = lr.bindingState;
        snap.bindingOrigin = lr.bindingOrigin;
        snap.mock = lr.mock;
        if (snap.unitType == UnitType::Unknown)
            snap.unitType = lr.unitType;

        QJsonObject agentObj = AgentContractUtil::statusSnapshotToJson(snap);
        agents.append(QJsonValue(agentObj));

        /* 统计 */
        switch (snap.connectionState) {
        case ConnectionState::Online:  onlineCount++;  break;
        case ConnectionState::Offline: offlineCount++; break;
        default:                       unknownCount++; break;
        }
        if (snap.mock) mockCount++; else realCount++;
    }

    /* 构建汇总 */
    QJsonObject summary;
    summary.insert(QStringLiteral("total"), QJsonValue(bindings.size()));
    summary.insert(QStringLiteral("online"), QJsonValue(onlineCount));
    summary.insert(QStringLiteral("offline"), QJsonValue(offlineCount));
    summary.insert(QStringLiteral("unknown"), QJsonValue(unknownCount));
    summary.insert(QStringLiteral("mock"), QJsonValue(mockCount));
    summary.insert(QStringLiteral("real"), QJsonValue(realCount));

    QJsonObject data;
    data.insert(QStringLiteral("schema_version"), QJsonValue(QStringLiteral("1.0")));
    data.insert(QStringLiteral("generated_at_ms"), QJsonValue(QDateTime::currentMSecsSinceEpoch()));
    data.insert(QStringLiteral("agents"), QJsonValue(agents));
    data.insert(QStringLiteral("summary"), QJsonValue(summary));

    return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
}

/* --------------------------------------------------------------------------
 * handleStatus — GET /api/agent/status?agent=XXX&refresh=0|1
 * -------------------------------------------------------------------------- */
QByteArray AgentHttpController::handleStatus(const QString &query, int *httpStatus) {
    if (!directory_) {
        return jsonResponse(false, QStringLiteral("agent directory not configured"),
                            QJsonValue::Null, httpStatus, 500);
    }
    if (!statusService_) {
        return jsonResponse(false, QStringLiteral("agent status service not configured"),
                            QJsonValue::Null, httpStatus, 500);
    }

    QUrlQuery q(query);
    const QString agentName = q.queryItemValue(QStringLiteral("agent"), QUrl::FullyDecoded).trimmed();
    if (agentName.isEmpty()) {
        return jsonResponse(false, QStringLiteral("missing 'agent' query parameter"),
                            QJsonValue::Null, httpStatus);
    }

    /* 解析 agent name -> unit_id（支持 unit_id 直传或 alias 查询） */
    const AgentLookupResult lr = directory_->resolveName(agentName);
    if (!lr.found) {
        return jsonResponse(false, QStringLiteral("agent not found: %1").arg(agentName),
                            QJsonValue::Null, httpStatus, 404);
    }

    /* 解析 refresh 参数 */
    bool refresh = false;
    {
        const QString refreshStr = q.queryItemValue(QStringLiteral("refresh"), QUrl::FullyDecoded);
        refresh = (refreshStr == QStringLiteral("1") || refreshStr == QStringLiteral("true"));
    }

    AgentStatusSnapshot snap = statusService_->getStatus(lr.unitId, refresh);

    /* 合并目录查找结果的元信息 */
    snap.alias = lr.alias;
    snap.displayName = lr.displayName;
    snap.bindingState = lr.bindingState;
    snap.bindingOrigin = lr.bindingOrigin;
    snap.mock = lr.mock;
    if (snap.unitType == UnitType::Unknown)
        snap.unitType = lr.unitType;

    QJsonObject data = AgentContractUtil::statusSnapshotToJson(snap);
    return jsonResponseObj(true, QStringLiteral("ok"), data, httpStatus);
}

/* --------------------------------------------------------------------------
 * handleAliasSet — POST /api/agent/alias/set
 * -------------------------------------------------------------------------- */
QByteArray AgentHttpController::handleAliasSet(const QByteArray &body, int *httpStatus) {
    if (!directory_) {
        return jsonResponse(false, QStringLiteral("agent directory not configured"),
                            QJsonValue::Null, httpStatus, 500);
    }

    QJsonObject o;
    QByteArray errResp;
    if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
        return errResp;

    const QString unitId = o.value(QStringLiteral("agent")).toString().trimmed();
    if (unitId.isEmpty()) {
        return jsonResponse(false, QStringLiteral("missing 'agent' (unit_id) field"),
                            QJsonValue::Null, httpStatus);
    }

    const QString alias = o.value(QStringLiteral("alias")).toString().trimmed();
    /* alias 可为空字符串，表示清除 */

    /* 解析 reserved_names */
    QStringList reservedNames;
    const QJsonValue rnValue = o.value(QStringLiteral("reserved_names"));
    if (rnValue.isArray()) {
        const QJsonArray arr = rnValue.toArray();
        for (const QJsonValue &v : arr) {
            if (v.isString())
                reservedNames.append(v.toString().trimmed());
        }
    }

    const AliasMutationResult result = directory_->setAlias(unitId, alias, reservedNames);

    if (!result.success) {
        int errorStatus = 400;
        if (result.errorCode == QStringLiteral("alias_conflict"))
            errorStatus = 409;
        else if (result.errorCode == QStringLiteral("not_found"))
            errorStatus = 404;
        QJsonObject errData;
        errData.insert(QStringLiteral("error_code"), QJsonValue(result.errorCode));
        errData.insert(QStringLiteral("canonical_unit_id"), QJsonValue(result.canonicalUnitId));
        return jsonResponseObj(false, result.errorMessage, errData, httpStatus, errorStatus);
    }

    QJsonObject data;
    data.insert(QStringLiteral("canonical_unit_id"), QJsonValue(result.canonicalUnitId));
    data.insert(QStringLiteral("alias"), QJsonValue(result.finalAlias));
    data.insert(QStringLiteral("updated_at_ms"), QJsonValue(result.updatedAtMs));
    return jsonResponseObj(true, QStringLiteral("alias set"), data, httpStatus);
}

/* --------------------------------------------------------------------------
 * handleAliasClear — POST /api/agent/alias/clear
 * -------------------------------------------------------------------------- */
QByteArray AgentHttpController::handleAliasClear(const QByteArray &body, int *httpStatus) {
    if (!directory_) {
        return jsonResponse(false, QStringLiteral("agent directory not configured"),
                            QJsonValue::Null, httpStatus, 500);
    }

    QJsonObject o;
    QByteArray errResp;
    if (!parseJsonObjectBody(body, &o, &errResp, httpStatus))
        return errResp;

    const QString unitId = o.value(QStringLiteral("agent")).toString().trimmed();
    if (unitId.isEmpty()) {
        return jsonResponse(false, QStringLiteral("missing 'agent' (unit_id) field"),
                            QJsonValue::Null, httpStatus);
    }

    const AliasMutationResult result = directory_->clearAlias(unitId);

    if (!result.success) {
        QJsonObject errData;
        errData.insert(QStringLiteral("error_code"), QJsonValue(result.errorCode));
        errData.insert(QStringLiteral("canonical_unit_id"), QJsonValue(result.canonicalUnitId));
        return jsonResponseObj(false, result.errorMessage, errData, httpStatus, 404);
    }

    QJsonObject data;
    data.insert(QStringLiteral("canonical_unit_id"), QJsonValue(result.canonicalUnitId));
    data.insert(QStringLiteral("updated_at_ms"), QJsonValue(result.updatedAtMs));
    return jsonResponseObj(true, QStringLiteral("alias cleared"), data, httpStatus);
}
