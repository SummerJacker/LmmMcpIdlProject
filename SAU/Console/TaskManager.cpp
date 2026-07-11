/**
 * @file TaskManager.cpp
 * @brief MCP-IDL 异步任务生命周期管理器实现。
 */

#include "TaskManager.h"

#include <QMutexLocker>
#include <QDebug>
#include <QUuid>

// ---- Singleton ----

TaskManager &TaskManager::instance() {
    static TaskManager inst;
    return inst;
}

TaskManager::TaskManager()
    : QObject(nullptr)
    , taskIdCounter_(0)
{
    // 每 60 秒清理超过 300 秒的已完成任务
    cleanupTimer_ = new QTimer(this);
    cleanupTimer_->setInterval(60000);
    connect(cleanupTimer_, &QTimer::timeout, this, &TaskManager::cleanupExpiredTasks);
    cleanupTimer_->start();
}

TaskManager::~TaskManager() {
    cleanupTimer_->stop();
}

// ---- Task ID Generation ----

QString TaskManager::generateTaskId(const QString &prefix) const {
    TaskManager *self = const_cast<TaskManager *>(this);
    int seq = ++(self->taskIdCounter_);
    QString shortUuid = QUuid::createUuid().toString(QUuid::WithoutBraces).left(8);
    return QStringLiteral("%1-%2-%3").arg(prefix, shortUuid).arg(seq);
}

// ---- Create Task ----

QString TaskManager::createTask(const QString &taskType, const QJsonObject &params,
                                 const QStringList &unitIds) {
    QMutexLocker lock(&mutex_);

    TaskEntry entry;
    entry.taskId = generateTaskId(
        taskType == "goto_pose_batch" ? QStringLiteral("batch") :
        taskType == "execute_formation" ? QStringLiteral("form") :
        QStringLiteral("goto"));
    entry.taskType = taskType;
    entry.state = QStringLiteral("PENDING");
    entry.progressPct = 0.0;
    entry.params = params;
    entry.startedAtMs = QDateTime::currentMSecsSinceEpoch();
    entry.completedAtMs = 0;
    entry.pollTimer = nullptr;

    // 为每个参与单元创建子任务
    for (const QString &uid : unitIds) {
        SubTask st;
        st.unitId = uid;
        st.state = QStringLiteral("PENDING");
        st.progressPct = 0.0;
        entry.subTasks.append(st);
    }

    // 审计日志: 任务创建
    QJsonObject auditEntry;
    auditEntry["ts_ms"] = entry.startedAtMs;
    auditEntry["event"] = QStringLiteral("TASK_CREATED");
    auditEntry["detail"] = QStringLiteral("type=%1 units=%2")
        .arg(taskType)
        .arg(unitIds.join(','));
    entry.auditLog.append(auditEntry);

    tasks_.insert(entry.taskId, entry);

    qDebug() << "[TaskManager] created task" << entry.taskId
             << "type=" << taskType << "units=" << unitIds;
    return entry.taskId;
}

// ---- State Transition ----

void TaskManager::transitionTask(const QString &taskId, const QString &newState,
                                  const QString &errorCode, const QString &message) {
    QMutexLocker lock(&mutex_);

    QHash<QString, TaskEntry>::iterator it = tasks_.find(taskId);
    if (it == tasks_.end()) {
        qWarning() << "[TaskManager] transitionTask: task not found" << taskId;
        return;
    }

    const QString oldState = it->state;
    it->state = newState;
    if (!errorCode.isEmpty())
        it->errorCode = errorCode;
    if (!message.isEmpty())
        it->message = message;

    // 终态: 记录完成时间
    if (newState == "COMPLETED" || newState == "FAILED" ||
        newState == "PARTIAL_COMPLETED" || newState == "TIMEOUT" ||
        newState == "CANCELLED" || newState == "REJECTED") {
        it->completedAtMs = QDateTime::currentMSecsSinceEpoch();
        it->progressPct = (newState == "COMPLETED") ? 100.0 : it->progressPct;
    }

    // 审计日志
    qint64 nowMs = QDateTime::currentMSecsSinceEpoch();
    QJsonObject auditEntry;
    auditEntry["ts_ms"] = nowMs;
    auditEntry["event"] = QStringLiteral("STATE_TRANSITION");
    auditEntry["detail"] = QStringLiteral("%1 -> %2 error=%3 msg=%4")
        .arg(oldState).arg(newState).arg(errorCode).arg(message);
    it->auditLog.append(auditEntry);

    qDebug() << "[TaskManager] task" << taskId
             << "state:" << oldState << "->" << newState
             << "error:" << errorCode;

    // 通知 (在锁外发送，避免死锁)
    lock.unlock();
    emit taskStateChanged(taskId, newState);
}

// ---- Progress ----

void TaskManager::updateProgress(const QString &taskId, double progressPct) {
    QMutexLocker lock(&mutex_);
    auto it = tasks_.find(taskId);
    if (it != tasks_.end())
        it->progressPct = qBound(0.0, progressPct, 100.0);
}

void TaskManager::updateSubTask(const QString &taskId, const QString &unitId,
                                 const QString &state, double progressPct,
                                 const QString &errorCode, const QString &message) {
    QMutexLocker lock(&mutex_);
    auto it = tasks_.find(taskId);
    if (it == tasks_.end())
        return;

    for (auto &st : it->subTasks) {
        if (st.unitId == unitId) {
            st.state = state;
            st.progressPct = qBound(0.0, progressPct, 100.0);
            if (!errorCode.isEmpty())
                st.errorCode = errorCode;
            if (!message.isEmpty())
                st.message = message;
            break;
        }
    }

    // 批量任务: 自动计算整体进度
    if (it->taskType == "goto_pose_batch" || it->taskType == "execute_formation") {
        it->progressPct = computeBatchProgress(it->subTasks);
    }
}

// ---- Audit ----

void TaskManager::appendAudit(const QString &taskId, const QString &event,
                               const QString &detail) {
    QMutexLocker lock(&mutex_);
    auto it = tasks_.find(taskId);
    if (it == tasks_.end())
        return;

    QJsonObject auditEntry;
    auditEntry["ts_ms"] = QDateTime::currentMSecsSinceEpoch();
    auditEntry["event"] = event;
    auditEntry["detail"] = detail;
    it->auditLog.append(auditEntry);
}

// ---- Get Task ----

TaskManager::TaskEntry *TaskManager::getTask(const QString &taskId) {
    QMutexLocker lock(&mutex_);
    auto it = tasks_.find(taskId);
    return (it != tasks_.end()) ? &it.value() : nullptr;
}

// ---- Cancel ----

QString TaskManager::cancelTask(const QString &taskId) {
    QMutexLocker lock(&mutex_);
    auto it = tasks_.find(taskId);
    if (it == tasks_.end())
        return QStringLiteral("TASK_NOT_FOUND");

    if (it->state == "COMPLETED" || it->state == "CANCELLED") {
        return QStringLiteral("TASK_ALREADY_CANCELLED");
    }

    // 停止关联定时器
    auto timerIt = timers_.find(taskId);
    if (timerIt != timers_.end() && timerIt.value()) {
        timerIt.value()->stop();
        timerIt.value()->deleteLater();
        timers_.erase(timerIt);
    }

    // 所有子任务标记为 cancelled
    for (auto &st : it->subTasks) {
        if (st.state == "RUNNING" || st.state == "PENDING") {
            st.state = "CANCELLED";
        }
    }

    it->state = QStringLiteral("CANCELLED");
    it->completedAtMs = QDateTime::currentMSecsSinceEpoch();

    qDebug() << "[TaskManager] task cancelled:" << taskId;
    return QString(); // empty = success
}

// ---- Timer Registration ----

void TaskManager::registerTimer(const QString &taskId, QTimer *timer) {
    QMutexLocker lock(&mutex_);
    timers_.insert(taskId, timer);
}

// ---- Unit Busy Check ----

bool TaskManager::isUnitBusy(const QString &unitId) const {
    QMutexLocker lock(&mutex_);
    for (auto it = tasks_.cbegin(); it != tasks_.cend(); ++it) {
        if (it->state != "RUNNING" && it->state != "PENDING")
            continue;
        for (const auto &st : it->subTasks) {
            if (st.unitId == unitId &&
                (st.state == "RUNNING" || st.state == "PENDING"))
                return true;
        }
    }
    return false;
}

// ---- Batch Progress ----

double TaskManager::computeBatchProgress(const QVector<SubTask> &subTasks) {
    if (subTasks.isEmpty())
        return 0.0;
    double total = 0.0;
    for (const auto &st : subTasks) {
        // 终态计为 100%
        if (st.state == "COMPLETED")
            total += 100.0;
        else if (st.state == "FAILED" || st.state == "TIMEOUT" ||
                 st.state == "CANCELLED")
            total += 100.0; // 不再变化，计入完成
        else
            total += st.progressPct;
    }
    return total / subTasks.size();
}

// ---- Cleanup ----

void TaskManager::cleanupExpiredTasks() {
    QMutexLocker lock(&mutex_);
    const qint64 nowMs = QDateTime::currentMSecsSinceEpoch();
    const qint64 kMaxAgeMs = 300000; // 5 分钟

    QStringList toRemove;
    for (auto it = tasks_.cbegin(); it != tasks_.cend(); ++it) {
        if (it->completedAtMs == 0)
            continue; // 还在运行
        if (nowMs - it->completedAtMs > kMaxAgeMs)
            toRemove.append(it.key());
    }

    for (const QString &id : toRemove) {
        // 清理关联定时器
        auto timerIt = timers_.find(id);
        if (timerIt != timers_.end() && timerIt.value()) {
            timerIt.value()->deleteLater();
            timers_.erase(timerIt);
        }
        tasks_.remove(id);
    }

    if (!toRemove.isEmpty())
        qDebug() << "[TaskManager] cleaned up" << toRemove.size() << "expired tasks";
}
