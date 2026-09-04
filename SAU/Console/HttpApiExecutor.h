#ifndef HTTP_API_EXECUTOR_H
#define HTTP_API_EXECUTOR_H

#include <QByteArray>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QVector>

/**
 * @file HttpApiExecutor.h
 * @brief 在主线程执行 HTTP API对应的 ILU 调用，避免与工作线程并发访问 ILU。
 *
 * 不修改 MainWindow/console业务类；仅使用 console.h 中已有符号与 IDL 客户端桩，
 * 通过绑定表临时 SBHToObject，避免改动 currentUnitObj（保护 UI 当前选中车）。
 *
 * /api/agent/* 路由委托给 AgentHttpController（由集成阶段注入）。
 */

class AgentHttpController;

struct FollowFormationMember {
    QString unitId;
    double requestedDistanceM = 0.0;
    double effectiveDistanceM = 0.0;

    QJsonObject toJson() const {
        QJsonObject value;
        value.insert(QStringLiteral("unit_id"), unitId);
        value.insert(QStringLiteral("requested_distance_m"), requestedDistanceM);
        value.insert(QStringLiteral("effective_distance_m"), effectiveDistanceM);
        return value;
    }
};

struct FollowFormationSnapshot {
    bool ready = false;
    QString state = QStringLiteral("IDLE");
    QString leaderId;
    QString activeMoveTaskId;
    QString message;
    QString errorCode;
    QVector<FollowFormationMember> followers;

    QJsonObject toJson() const {
        QJsonArray followerValues;
        for (const FollowFormationMember &member : followers)
            followerValues.append(member.toJson());
        QJsonObject value;
        const QString effectiveState = ready && state == QStringLiteral("IDLE")
            ? QStringLiteral("READY") : state;
        value.insert(QStringLiteral("has_active_formation"),
                     effectiveState == QStringLiteral("CREATING") ||
                     effectiveState == QStringLiteral("READY") ||
                     effectiveState == QStringLiteral("MOVING") ||
                     (effectiveState == QStringLiteral("FAILED") &&
                      !leaderId.isEmpty()));
        value.insert(QStringLiteral("state"), effectiveState);
        value.insert(QStringLiteral("leader_id"), leaderId);
        value.insert(QStringLiteral("followers"), followerValues);
        value.insert(QStringLiteral("active_move_task_id"), activeMoveTaskId);
        value.insert(QStringLiteral("message"), message);
        value.insert(QStringLiteral("error_code"), errorCode);
        return value;
    }
};

class HttpApiExecutor : public QObject {
    Q_OBJECT

public:
    explicit HttpApiExecutor(QObject *parent = nullptr);

    /**
     * @brief 处理一条已解析的 HTTP 请求，返回 UTF-8 JSON 响应体（不含 HTTP 头）。
     * @param method HTTP 方法（大写，如 "GET" / "POST"）
     * @param path 路径，如 "/api/robot/sendmove"
     * @param query 查询字符串（不含 ?），可为空
     * @param body POST 原始 body
     * @param httpStatus 输出 HTTP 状态码
     * @return JSON 字节数组
     */
    QByteArray processRequest(const QString &method, const QString &path,
                              const QString &query, const QByteArray &body,
                              int *httpStatus);

public slots:
    /**
     * @brief 供 HttpPlugin 工作线程通过 BlockingQueuedConnection 调用（在主线程执行 ILU）。
     */
    QByteArray processRequestSlot(const QString &method, const QString &path,
                                  const QString &query, const QByteArray &body);

    /**
     * @brief 生成 XY2D 监控 SSE 单帧 JSON（UTF-8，紧凑格式），供定时广播调用。
     */
    QByteArray buildXy2dMonitorEventPayload();

    int lastHttpStatus() const { return lastHttpStatus_; }

    /**
     * @brief 注入 /api/agent/* 路由处理器（由集成阶段在 main 中设置）。
     */
    void setAgentHttpController(AgentHttpController *controller) { agentHttpController_ = controller; }

private:
    int lastHttpStatus_ = 200;

    /** @brief 保护 natural_language / phase_text（由 POST /api/monitor/context 更新）。 */
    QMutex monitorMutex_;
    QString monitorNaturalLanguage_;
    QString monitorPhaseText_;
    QJsonArray mcpLogs_;

    /** @brief /api/agent/* 路由委托处理器（集成阶段注入） */
    AgentHttpController *agentHttpController_ = nullptr;
};

#endif
