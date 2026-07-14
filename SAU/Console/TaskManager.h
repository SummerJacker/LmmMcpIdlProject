/**
 * @file TaskManager.h
 * @brief MCP-IDL 异步任务生命周期管理器。
 *
 * 严格遵循 mcp_swarm_task.idl 定义的 TaskState 状态机:
 *   PENDING → RUNNING → COMPLETED | PARTIAL_COMPLETED | FAILED | TIMEOUT | CANCELLED
 *   PENDING → REJECTED (入口校验不通过)
 *
 * 职责:
 *   1. 为每个异步任务分配唯一 UUID
 *   2. 跟踪状态转换、进度百分比、子任务结果
 *   3. 记录审计日志 (auditLog)
 *   4. 管理关联的 QTimer (供 cancel 时停止)
 *   5. 自动清理超过 300s 的已完成任务
 */

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <QDateTime>
#include <QHash>
#include <QJsonArray>
#include <QJsonObject>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QPointer>
#include <QTimer>
#include <QVector>

class TaskManager : public QObject {
    Q_OBJECT

public:
    static TaskManager &instance();

    // ---- 子任务结构 (对应 MCP-IDL UnitTaskResult) ----
    struct SubTask {
        QString taskId;
        QString unitId;
        QString state;        // TaskState 枚举值字符串
        double progressPct;   // 0.0 ~ 100.0
        QString errorCode;    // MCP-IDL ErrorCode
        QString message;

        QJsonObject toJson() const {
            QJsonObject o;
            o["unit_id"] = unitId;
            o["state"] = state;
            o["progress_pct"] = progressPct;
            o["error_code"] = errorCode;
            o["message"] = message;
            return o;
        }
    };

    // ---- 任务条目 ----
    struct TaskEntry {
        QString taskId;
        QString taskType;       // "goto_pose" | "goto_pose_batch" | "execute_formation"
        QString state;           // TaskState 枚举值字符串
        double progressPct;      // 0.0 ~ 100.0
        QJsonObject params;      // 原始任务参数
        QString errorCode;       // MCP-IDL ErrorCode
        QString message;
        QString cancellationEffect; // NOT_APPLICABLE | CANCEL_CONFIRMED | STOP_REQUESTED | STATE_ONLY_CANCELLED
        QVector<SubTask> subTasks;
        qint64 startedAtMs;
        qint64 completedAtMs;
        QTimer *pollTimer;       // 轮询定时器 (goto_pose 用)
        QJsonArray auditLog;     // [{ts_ms, event, detail}, ...]

        QJsonObject toJson() const {
            QJsonObject o;
            o["task_id"] = taskId;
            o["task_type"] = taskType;
            o["state"] = state;
            o["progress_pct"] = progressPct;
            o["error_code"] = errorCode;
            o["message"] = message;
            o["success"] = state == "PENDING" || state == "RUNNING" ||
                           state == "COMPLETED" || state == "PARTIAL_COMPLETED";
            o["cancellation_effect"] = cancellationEffect;
            o["elapsed_ms"] = (state == "RUNNING" || state == "PENDING")
                ? (qint64)(QDateTime::currentMSecsSinceEpoch() - startedAtMs)
                : (qint64)(completedAtMs - startedAtMs);
            o["started_at_ms"] = startedAtMs;

            QJsonArray units;
            for (const auto &st : subTasks)
                units.append(st.toJson());
            o["unit_results"] = units;
            return o;
        }
    };

    // ---- 公共接口 ----

    /**
     * @brief 创建任务并返回 UUID。
     * @param taskType "goto_pose" | "goto_pose_batch" | "execute_formation"
     * @param params 原始请求参数
     * @param unitIds 参与此任务的单元列表
     * @returns 新任务 UUID
     */
    QString createTask(const QString &taskType, const QJsonObject &params,
                       const QStringList &unitIds = {});

    /**
     * @brief Atomically reserve all units and create the task.
     * @returns empty when any unit is already owned by a PENDING/RUNNING task.
     */
    QString createTaskIfUnitsAvailable(const QString &taskType, const QJsonObject &params,
                                       const QStringList &unitIds, QString *busyUnit = nullptr);

    /**
     * @brief 状态转换 (线程安全)。
     */
    void transitionTask(const QString &taskId, const QString &newState,
                        const QString &errorCode = QString(),
                        const QString &message = QString());

    /**
     * @brief 更新进度 (0.0 ~ 100.0)。
     */
    void updateProgress(const QString &taskId, double progressPct);

    /**
     * @brief 更新单个子任务状态。
     */
    void updateSubTask(const QString &taskId, const QString &unitId,
                       const QString &state, double progressPct = 0.0,
                       const QString &errorCode = QString(),
                       const QString &message = QString());

    /**
     * @brief 添加审计日志条目。
     */
    void appendAudit(const QString &taskId, const QString &event,
                     const QString &detail);

    /** @brief Copy a task while holding the manager lock. */
    bool taskSnapshot(const QString &taskId, TaskEntry *out) const;

    /** @brief Return a copy of all units associated with a task. */
    QStringList taskUnitIds(const QString &taskId) const;

    /** @brief Return only PENDING/RUNNING units associated with a task. */
    QStringList taskActiveUnitIds(const QString &taskId) const;

    /** @brief Atomically reserve persistent formation members. */
    bool reserveUnitsIfAvailable(const QString &ownerId, const QStringList &unitIds,
                                 QString *busyUnit = nullptr);

    /** @brief Release all persistent reservations owned by ownerId. */
    void releaseReservations(const QString &ownerId);

    /** Keep a unit unavailable when the Console cannot confirm physical control ended. */
    void markUnitControlUncertain(const QString &unitId, const QString &reason);
    void clearUnitControlUncertain(const QString &unitId);
    bool isUnitControlUncertain(const QString &unitId) const;

    /**
     * @brief 取消任务: 停止定时器 + 状态 → CANCELLED。
     * @returns 错误消息 (空 = 成功)
     */
    QString cancelTask(const QString &taskId,
                       const QString &cancellationEffect = QStringLiteral("STATE_ONLY_CANCELLED"));

    /**
     * @brief 注册 QTimer (供 cancel 时停止)。
     */
    void registerTimer(const QString &taskId, QTimer *timer);

    /**
     * @brief 检查 unit 是否有运行中的任务。
     */
    bool isUnitBusy(const QString &unitId) const;

    /**
     * @brief 计算整体进度 (批量任务: 所有子任务进度均值)。
     */
    static double computeBatchProgress(const QVector<SubTask> &subTasks);

    /** @brief Aggregate terminal subtask states into the parent task. */
    bool finalizeTaskIfAllSubTasksTerminal(const QString &taskId);

signals:
    void taskStateChanged(const QString &taskId, const QString &newState);

private slots:
    void cleanupExpiredTasks();

private:
    TaskManager();
    ~TaskManager() override;
    Q_DISABLE_COPY(TaskManager)

    QString generateTaskId(const QString &prefix) const;

    static bool isTerminalState(const QString &state);
    bool isUnitBusyLocked(const QString &unitId) const;
    void releaseReservationsLocked(const QString &ownerId);
    QString createTaskLocked(const QString &taskType, const QJsonObject &params,
                             const QStringList &unitIds);

    QHash<QString, TaskEntry> tasks_;
    QHash<QString, QVector<QPointer<QTimer>>> timers_;
    QHash<QString, QString> unitReservations_; // unitId -> task/formation owner id
    QHash<QString, QString> controlUncertainUnits_; // unitId -> reason
    mutable QMutex mutex_;
    int taskIdCounter_;
    QTimer *cleanupTimer_;
};

#endif // TASK_MANAGER_H
