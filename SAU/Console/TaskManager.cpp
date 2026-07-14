/**
 * @file TaskManager.cpp
 * @brief MCP-IDL 异步任务生命周期管理器实现。
 */

#include "TaskManager.h"

#include <QMutexLocker>
#include <QDebug>
#include <QSet>
#include <QUuid>

namespace {

QString normalizedUnitKey(const QString &unitId) {
    const QString value = unitId.trimmed().toUpper();
    int digitIndex = -1;
    for (int i = 0; i < value.size(); ++i) {
        if (value.at(i).isDigit()) {
            digitIndex = i;
            break;
        }
    }
    if (digitIndex <= 0)
        return value;
    bool ok = false;
    const int number = value.mid(digitIndex).toInt(&ok);
    return ok ? value.left(digitIndex) + QString::number(number) : value;
}

} // namespace

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

QString TaskManager::createTaskLocked(const QString &taskType, const QJsonObject &params,
                                       const QStringList &unitIds) {
    TaskEntry entry;
    entry.taskId = generateTaskId(
        taskType == "goto_pose_batch" ? QStringLiteral("batch") :
        taskType == "create_static_formation" || taskType == "execute_formation"
            ? QStringLiteral("form") :
        taskType == "follow_path" ? QStringLiteral("path") :
        QStringLiteral("goto"));
    entry.taskType = taskType;
    entry.state = QStringLiteral("PENDING");
    entry.progressPct = 0.0;
    entry.params = params;
    entry.startedAtMs = QDateTime::currentMSecsSinceEpoch();
    entry.completedAtMs = 0;
    entry.pollTimer = nullptr;
    entry.cancellationEffect = QStringLiteral("NOT_APPLICABLE");

    for (const QString &uid : unitIds) {
        SubTask st;
        st.unitId = uid;
        st.state = QStringLiteral("PENDING");
        st.progressPct = 0.0;
        entry.subTasks.append(st);
    }

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

QString TaskManager::createTask(const QString &taskType, const QJsonObject &params,
                                 const QStringList &unitIds) {
    QMutexLocker lock(&mutex_);
    return createTaskLocked(taskType, params, unitIds);
}

QString TaskManager::createTaskIfUnitsAvailable(const QString &taskType,
                                                 const QJsonObject &params,
                                                 const QStringList &unitIds,
                                                 QString *busyUnit) {
    QMutexLocker lock(&mutex_);
    QSet<QString> seen;
    for (const QString &uid : unitIds) {
        const QString key = normalizedUnitKey(uid);
        if (key.isEmpty() || seen.contains(key) || isUnitBusyLocked(uid)) {
            if (busyUnit)
                *busyUnit = uid;
            return QString();
        }
        seen.insert(key);
    }
    const QString taskId = createTaskLocked(taskType, params, unitIds);
    for (const QString &uid : unitIds)
        unitReservations_.insert(normalizedUnitKey(uid), taskId);
    return taskId;
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
    if (isTerminalState(oldState) && oldState != newState) {
        qWarning() << "[TaskManager] refusing terminal transition" << taskId
                   << oldState << "->" << newState;
        return;
    }
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
        releaseReservationsLocked(taskId);
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

    // Every task with sub-tasks, including a single-unit navigation task,
    // derives its visible progress from those sub-tasks.
    if (!it->subTasks.isEmpty()) {
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

bool TaskManager::taskSnapshot(const QString &taskId, TaskEntry *out) const {
    QMutexLocker lock(&mutex_);
    auto it = tasks_.constFind(taskId);
    if (it == tasks_.constEnd())
        return false;
    if (out)
        *out = it.value();
    return true;
}

QStringList TaskManager::taskUnitIds(const QString &taskId) const {
    QMutexLocker lock(&mutex_);
    QStringList result;
    auto it = tasks_.constFind(taskId);
    if (it == tasks_.constEnd())
        return result;
    for (const SubTask &subTask : it->subTasks)
        result.append(subTask.unitId);
    return result;
}

QStringList TaskManager::taskActiveUnitIds(const QString &taskId) const {
    QMutexLocker lock(&mutex_);
    QStringList result;
    auto it = tasks_.constFind(taskId);
    if (it == tasks_.constEnd())
        return result;
    for (const SubTask &subTask : it->subTasks) {
        if (subTask.state == "PENDING" || subTask.state == "RUNNING")
            result.append(subTask.unitId);
    }
    return result;
}

bool TaskManager::reserveUnitsIfAvailable(const QString &ownerId,
                                          const QStringList &unitIds,
                                          QString *busyUnit) {
    QMutexLocker lock(&mutex_);
    if (ownerId.isEmpty() || unitIds.isEmpty())
        return false;
    QSet<QString> seen;
    for (const QString &uid : unitIds) {
        const QString key = normalizedUnitKey(uid);
        if (key.isEmpty() || seen.contains(key) || isUnitBusyLocked(uid)) {
            if (busyUnit)
                *busyUnit = uid;
            return false;
        }
        seen.insert(key);
    }
    for (const QString &uid : unitIds)
        unitReservations_.insert(normalizedUnitKey(uid), ownerId);
    return true;
}

void TaskManager::releaseReservations(const QString &ownerId) {
    QMutexLocker lock(&mutex_);
    releaseReservationsLocked(ownerId);
}

void TaskManager::markUnitControlUncertain(const QString &unitId,
                                           const QString &reason) {
    QMutexLocker lock(&mutex_);
    const QString key = normalizedUnitKey(unitId);
    if (!key.isEmpty())
        controlUncertainUnits_.insert(key, reason);
}

void TaskManager::clearUnitControlUncertain(const QString &unitId) {
    QMutexLocker lock(&mutex_);
    controlUncertainUnits_.remove(normalizedUnitKey(unitId));
}

bool TaskManager::isUnitControlUncertain(const QString &unitId) const {
    QMutexLocker lock(&mutex_);
    return controlUncertainUnits_.contains(normalizedUnitKey(unitId));
}

// ---- Cancel ----

QString TaskManager::cancelTask(const QString &taskId,
                                const QString &cancellationEffect) {
    QMutexLocker lock(&mutex_);
    auto it = tasks_.find(taskId);
    if (it == tasks_.end())
        return QStringLiteral("TASK_NOT_FOUND");

    if (it->state == "CANCELLED")
        return QStringLiteral("TASK_ALREADY_CANCELLED");
    if (isTerminalState(it->state))
        return QStringLiteral("TASK_CONFLICT");

    auto timerIt = timers_.find(taskId);
    if (timerIt != timers_.end()) {
        for (const QPointer<QTimer> &timer : timerIt.value()) {
            if (timer) {
                timer->stop();
                timer->deleteLater();
            }
        }
        timers_.erase(timerIt);
    }

    for (auto &st : it->subTasks) {
        if (st.state == "RUNNING" || st.state == "PENDING") {
            st.state = "CANCELLED";
            st.message = QStringLiteral("task state cancelled");
            st.progressPct = 100.0;
        }
    }

    it->progressPct = computeBatchProgress(it->subTasks);
    const QString oldState = it->state;
    it->state = QStringLiteral("CANCELLED");
    it->cancellationEffect = cancellationEffect;
    it->message = QStringLiteral("task state cancelled; physical stop effect is reported separately");
    it->completedAtMs = QDateTime::currentMSecsSinceEpoch();
    releaseReservationsLocked(taskId);

    QJsonObject auditEntry;
    auditEntry["ts_ms"] = it->completedAtMs;
    auditEntry["event"] = QStringLiteral("STATE_TRANSITION");
    auditEntry["detail"] = QStringLiteral("%1 -> CANCELLED effect=%2")
        .arg(oldState, cancellationEffect);
    it->auditLog.append(auditEntry);

    qDebug() << "[TaskManager] task cancelled:" << taskId
             << "effect=" << cancellationEffect;
    lock.unlock();
    emit taskStateChanged(taskId, QStringLiteral("CANCELLED"));
    return QString();
}

// ---- Timer Registration ----

void TaskManager::registerTimer(const QString &taskId, QTimer *timer) {
    if (!timer)
        return;
    QMutexLocker lock(&mutex_);
    timers_[taskId].append(QPointer<QTimer>(timer));
}

// ---- Unit Busy Check ----

bool TaskManager::isTerminalState(const QString &state) {
    return state == "COMPLETED" || state == "PARTIAL_COMPLETED" ||
           state == "FAILED" || state == "TIMEOUT" ||
           state == "CANCELLED" || state == "REJECTED";
}

void TaskManager::releaseReservationsLocked(const QString &ownerId) {
    for (auto it = unitReservations_.begin(); it != unitReservations_.end();) {
        if (it.value() == ownerId)
            it = unitReservations_.erase(it);
        else
            ++it;
    }
}

bool TaskManager::isUnitBusyLocked(const QString &unitId) const {
    const QString key = normalizedUnitKey(unitId);
    if (controlUncertainUnits_.contains(key))
        return true;
    if (unitReservations_.contains(key))
        return true;
    for (auto it = tasks_.cbegin(); it != tasks_.cend(); ++it) {
        if (it->state != "RUNNING" && it->state != "PENDING")
            continue;
        for (const auto &st : it->subTasks) {
            if (normalizedUnitKey(st.unitId) == key &&
                (st.state == "RUNNING" || st.state == "PENDING"))
                return true;
        }
    }
    return false;
}

bool TaskManager::isUnitBusy(const QString &unitId) const {
    QMutexLocker lock(&mutex_);
    return isUnitBusyLocked(unitId);
}

// ---- Batch Progress ----

double TaskManager::computeBatchProgress(const QVector<SubTask> &subTasks) {
    if (subTasks.isEmpty())
        return 0.0;
    double total = 0.0;
    for (const auto &st : subTasks) {
        if (st.state == "COMPLETED" || st.state == "FAILED" ||
            st.state == "TIMEOUT" || st.state == "CANCELLED")
            total += 100.0;
        else
            total += st.progressPct;
    }
    return total / subTasks.size();
}

bool TaskManager::finalizeTaskIfAllSubTasksTerminal(const QString &taskId) {
    QString finalState;
    QString finalErrorCode;
    QString finalMessage;
    {
        QMutexLocker lock(&mutex_);
        auto it = tasks_.find(taskId);
        if (it == tasks_.end() || it->subTasks.isEmpty())
            return false;

        bool anyCompleted = false;
        bool anyFailed = false;
        bool anyTimeout = false;
        bool anyCancelled = false;
        int representativeErrorRank = 0;
        for (const SubTask &subTask : it->subTasks) {
            if (subTask.state == "RUNNING" || subTask.state == "PENDING")
                return false;
            anyCompleted = anyCompleted || subTask.state == "COMPLETED";
            anyFailed = anyFailed || subTask.state == "FAILED";
            anyTimeout = anyTimeout || subTask.state == "TIMEOUT";
            anyCancelled = anyCancelled || subTask.state == "CANCELLED";

            int errorRank = 0;
            if (subTask.state == "FAILED")
                errorRank = 3;
            else if (subTask.state == "TIMEOUT")
                errorRank = 2;
            else if (subTask.state == "CANCELLED")
                errorRank = 1;
            if (errorRank > representativeErrorRank) {
                representativeErrorRank = errorRank;
                finalErrorCode = subTask.errorCode;
                finalMessage = subTask.message;
            }
        }

        if (anyCompleted && (anyFailed || anyTimeout || anyCancelled))
            finalState = QStringLiteral("PARTIAL_COMPLETED");
        else if (anyCompleted)
            finalState = QStringLiteral("COMPLETED");
        else if (anyCancelled && !anyFailed && !anyTimeout)
            finalState = QStringLiteral("CANCELLED");
        else if (anyTimeout && !anyFailed)
            finalState = QStringLiteral("TIMEOUT");
        else
            finalState = QStringLiteral("FAILED");
    }
    transitionTask(taskId, finalState, finalErrorCode, finalMessage);
    return true;
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
        if (timerIt != timers_.end()) {
            for (const QPointer<QTimer> &timer : timerIt.value()) {
                if (timer)
                    timer->deleteLater();
            }
            timers_.erase(timerIt);
        }
        tasks_.remove(id);
    }

    if (!toRemove.isEmpty())
        qDebug() << "[TaskManager] cleaned up" << toRemove.size() << "expired tasks";
}
