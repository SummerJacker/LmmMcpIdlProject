#include "TaskOrchestrator.h"

#include "MockRobotSimulator.h"
#include "SafetyValidator.h"
#include "TaskManager.h"

#include <QDateTime>
#include <QJsonValue>
#include <QSharedPointer>
#include <QTimer>
#include <QtMath>

MockPathProgress::MockPathProgress(const QJsonArray &points)
    : points_(points)
    , currentIndex_(0) {
}

QJsonObject MockPathProgress::currentTarget() const {
    if (currentIndex_ < 0 || currentIndex_ >= points_.size())
        return QJsonObject();
    return points_.at(currentIndex_).toObject();
}

bool MockPathProgress::advance() {
    if (points_.isEmpty() || currentIndex_ + 1 >= points_.size())
        return true;
    ++currentIndex_;
    return false;
}

double MockPathProgress::overallProgress(double segmentProgressPct) const {
    if (points_.isEmpty())
        return 100.0;
    const double completedSegments = static_cast<double>(currentIndex_);
    const double currentFraction = qBound(0.0, segmentProgressPct, 100.0) / 100.0;
    return qBound(0.0,
                  100.0 * (completedSegments + currentFraction) / points_.size(),
                  100.0);
}

TaskOrchestrator &TaskOrchestrator::instance() {
    static TaskOrchestrator orchestrator;
    return orchestrator;
}

TaskOrchestrator::TaskOrchestrator(QObject *parent)
    : QObject(parent)
    , adapter_(&LegacyIdlAdapter::instance()) {
}

TaskCapabilityPolicy TaskOrchestrator::capabilityPolicy(
    int mockCount, int realCount, bool realRpcEnabled) {
    const int executableGroundCount =
        mockCount + (realRpcEnabled ? realCount : 0);
    TaskCapabilityPolicy policy;
    policy.targetPointNavigation = executableGroundCount >= 1;
    policy.pathTasks = executableGroundCount >= 1;
    policy.staticFormation = executableGroundCount >= 2;
    policy.followFormation = mockCount >= 2 || (realRpcEnabled && realCount >= 2);
    policy.realUnitRpc = realRpcEnabled && realCount >= 1;
    return policy;
}

FollowSetupPolicy TaskOrchestrator::followSetupPolicy(
    int mockCount, int realCount, bool realRpcEnabled) {
    if (mockCount > 0 && realCount == 0)
        return FollowSetupPolicy::DispatchMock;
    if (mockCount > 0 && realCount > 0)
        return FollowSetupPolicy::UnsupportedMixed;
    if (!realRpcEnabled)
        return FollowSetupPolicy::RpcDisabled;
    return FollowSetupPolicy::DispatchReal;
}

void TaskOrchestrator::setAdapterForTests(LegacyIdlAdapter *adapter) {
    adapter_ = adapter ? adapter : &LegacyIdlAdapter::instance();
}

TaskRpcResult TaskOrchestrator::dispatchTarget(
    const QString &taskId, const QString &unitId, double x, double y,
    double toleranceM, int timeoutMs) {
    TaskRpcResult result = adapter_->setTaskPoint(unitId, x, y);
    TaskManager &manager = TaskManager::instance();
    if (!result.success) {
        manager.updateSubTask(taskId, unitId, QStringLiteral("FAILED"), 100.0,
                              result.errorCode, result.message);
        manager.finalizeTaskIfAllSubTasksTerminal(taskId);
        return result;
    }

    manager.updateSubTask(taskId, unitId, QStringLiteral("RUNNING"), 0.0);
    manager.appendAudit(
        taskId, QStringLiteral("TARGET_DISPATCHED"),
        QStringLiteral("%1 target=(%2,%3) mock=%4")
            .arg(unitId).arg(x, 0, 'f', 3).arg(y, 0, 'f', 3).arg(result.mock));
    startTargetPolling(taskId, unitId, x, y, toleranceM, timeoutMs);
    return result;
}

TaskRpcResult TaskOrchestrator::dispatchPath(
    const QString &taskId, const QString &unitId, const QJsonArray &points,
    double toleranceM, int timeoutMs) {
    TaskRpcResult result = adapter_->setTaskPath(unitId, points);
    TaskManager &manager = TaskManager::instance();
    if (!result.success) {
        manager.updateSubTask(taskId, unitId, QStringLiteral("FAILED"), 100.0,
                              result.errorCode, result.message);
        manager.finalizeTaskIfAllSubTasksTerminal(taskId);
        return result;
    }

    manager.updateSubTask(taskId, unitId, QStringLiteral("RUNNING"), 0.0);
    manager.appendAudit(taskId, QStringLiteral("PATH_DISPATCHED"),
                        QStringLiteral("%1 points=%2 mock=%3")
                            .arg(unitId).arg(points.size()).arg(result.mock));
    if (result.mock) {
        startMockPathPolling(taskId, unitId, points, toleranceM, timeoutMs);
    } else {
        const QJsonObject finalPoint = points.last().toObject();
        startTargetPolling(taskId, unitId,
                           finalPoint.value(QStringLiteral("x")).toDouble(),
                           finalPoint.value(QStringLiteral("y")).toDouble(),
                           toleranceM, timeoutMs);
    }
    return result;
}

TaskRpcResult TaskOrchestrator::dispatchMotion(
    const QString &taskId, const QString &unitId, double linearVelocity,
    double angularVelocity, int durationMs) {
    TaskRpcResult invalid;
    if (!qIsFinite(linearVelocity) || !qIsFinite(angularVelocity) ||
        qAbs(linearVelocity) > SafetyValidator::maxLinearSpeedMS() ||
        qAbs(angularVelocity) > SafetyValidator::maxAngularSpeedRadS() ||
        durationMs <= 0 || durationMs > 60000) {
        invalid.errorCode = QStringLiteral("SAFETY_REJECTED");
        invalid.message = QStringLiteral(
            "motion speed or duration is outside safe limits");
        return invalid;
    }

    TaskManager &manager = TaskManager::instance();
    const TaskRpcResult result = adapter_->sendMove(
        unitId, linearVelocity, angularVelocity, durationMs);
    if (!result.success) {
        manager.updateSubTask(taskId, unitId, QStringLiteral("FAILED"), 100.0,
                              result.errorCode, result.message);
        manager.finalizeTaskIfAllSubTasksTerminal(taskId);
        return result;
    }

    manager.updateSubTask(taskId, unitId, QStringLiteral("RUNNING"), 0.0);
    manager.appendAudit(
        taskId, QStringLiteral("MOTION_DISPATCHED"),
        QStringLiteral("%1 linear=%2 angular=%3 duration_ms=%4 mock=%5")
            .arg(unitId)
            .arg(linearVelocity, 0, 'f', 3)
            .arg(angularVelocity, 0, 'f', 3)
            .arg(durationMs)
            .arg(result.mock));

    QTimer *timer = new QTimer();
    timer->setSingleShot(true);
    QObject::connect(timer, &QTimer::timeout,
                     [taskId, unitId, timer]() {
        TaskManager &taskManager = TaskManager::instance();
        TaskManager::TaskEntry snapshot;
        if (taskManager.taskSnapshot(taskId, &snapshot) &&
            snapshot.state == QStringLiteral("RUNNING")) {
            taskManager.updateSubTask(
                taskId, unitId, QStringLiteral("COMPLETED"), 100.0);
            taskManager.finalizeTaskIfAllSubTasksTerminal(taskId);
        }
        timer->deleteLater();
    });
    manager.registerTimer(taskId, timer);
    timer->start(durationMs);
    return result;
}

TaskRpcResult TaskOrchestrator::stopUnit(const QString &unitId) {
    return adapter_->stopUnit(unitId);
}

bool TaskOrchestrator::validateFollowMotionSequence(
    const QVector<FollowMotionSegment> &segments, QString *errorMessage) {
    if (errorMessage)
        errorMessage->clear();
    if (segments.isEmpty() || segments.size() > 8) {
        if (errorMessage)
            *errorMessage = QStringLiteral("segments must contain between 1 and 8 items");
        return false;
    }

    qint64 totalMs = 0;
    for (const FollowMotionSegment &segment : segments) {
        if (!qIsFinite(segment.linearVelocity) ||
            !qIsFinite(segment.angularVelocity) ||
            qAbs(segment.linearVelocity) > SafetyValidator::maxLinearSpeedMS() ||
            qAbs(segment.angularVelocity) > SafetyValidator::maxAngularSpeedRadS()) {
            if (errorMessage)
                *errorMessage = QStringLiteral("segment speed is invalid or outside safe limits");
            return false;
        }
        if (segment.durationMs <= 0 || segment.bufferMs < 0 || segment.bufferMs > 5000) {
            if (errorMessage)
                *errorMessage = QStringLiteral("segment duration or buffer is invalid");
            return false;
        }
        totalMs += static_cast<qint64>(segment.durationMs) + segment.bufferMs;
        if (totalMs > 60000) {
            if (errorMessage)
                *errorMessage = QStringLiteral("motion sequence exceeds 60000 ms");
            return false;
        }
    }
    return true;
}

bool TaskOrchestrator::validateMotionRequest(
    const QJsonObject &request, bool unitBound, MotionTaskCommand *command,
    QString *errorCode, QString *errorMessage) {
    if (errorCode)
        errorCode->clear();
    if (errorMessage)
        errorMessage->clear();

    const QString unitId =
        request.value(QStringLiteral("unit_id")).toString().trimmed();
    const QJsonValue linearValue =
        request.value(QStringLiteral("linear_velocity"));
    const QJsonValue angularValue =
        request.value(QStringLiteral("angular_velocity"));
    const QJsonValue durationJson =
        request.value(QStringLiteral("duration_ms"));
    const double linearVelocity = linearValue.toDouble();
    const double angularVelocity = angularValue.toDouble();
    const double durationValue = durationJson.toDouble(-1.0);

    const bool fieldsValid = unitId.startsWith(QLatin1Char('G')) &&
        linearValue.isDouble() && angularValue.isDouble() &&
        durationJson.isDouble() && qIsFinite(linearVelocity) &&
        qIsFinite(angularVelocity) && qIsFinite(durationValue) &&
        qFloor(durationValue) == durationValue && durationValue > 0.0 &&
        durationValue <= 60000.0 &&
        qAbs(linearVelocity) <= SafetyValidator::maxLinearSpeedMS() &&
        qAbs(angularVelocity) <= SafetyValidator::maxAngularSpeedRadS();
    if (!fieldsValid) {
        if (errorCode)
            *errorCode = QStringLiteral("SAFETY_REJECTED");
        if (errorMessage) {
            *errorMessage = QStringLiteral(
                "executeMotion requires a ground unit, bounded finite speeds, "
                "and integer duration_ms in [1, 60000]");
        }
        return false;
    }
    if (!unitBound) {
        if (errorCode)
            *errorCode = QStringLiteral("UNIT_NOT_FOUND");
        if (errorMessage)
            *errorMessage = QStringLiteral("unit not bound");
        return false;
    }

    if (command) {
        command->unitId = unitId;
        command->linearVelocity = linearVelocity;
        command->angularVelocity = angularVelocity;
        command->durationMs = static_cast<int>(durationValue);
    }
    return true;
}

TaskRpcResult TaskOrchestrator::dispatchMotionSequence(
    const QString &taskId, const QString &unitId,
    const QVector<FollowMotionSegment> &segments) {
    QString validationError;
    if (!validateFollowMotionSequence(segments, &validationError)) {
        TaskRpcResult invalid;
        invalid.errorCode = QStringLiteral("SAFETY_REJECTED");
        invalid.message = validationError;
        return invalid;
    }

    TaskManager &manager = TaskManager::instance();
    TaskRpcResult first = adapter_->sendMove(
        unitId, segments.first().linearVelocity,
        segments.first().angularVelocity, segments.first().durationMs);
    if (!first.success) {
        manager.updateSubTask(taskId, unitId, QStringLiteral("FAILED"), 100.0,
                              first.errorCode, first.message);
        manager.finalizeTaskIfAllSubTasksTerminal(taskId);
        return first;
    }

    manager.updateSubTask(taskId, unitId, QStringLiteral("RUNNING"), 0.0);
    manager.appendAudit(taskId, QStringLiteral("MOTION_SEGMENT_DISPATCHED"),
                        QStringLiteral("%1 segment=1/%2").arg(unitId).arg(segments.size()));

    QTimer *timer = new QTimer();
    timer->setSingleShot(true);
    const QSharedPointer<int> index(new int(0));
    const QSharedPointer<QVector<FollowMotionSegment>> sequence(
        new QVector<FollowMotionSegment>(segments));
    TaskOrchestrator *self = this;
    QObject::connect(timer, &QTimer::timeout,
                     [taskId, unitId, timer, index, sequence, self]() {
        TaskManager &taskManager = TaskManager::instance();
        TaskManager::TaskEntry snapshot;
        if (!taskManager.taskSnapshot(taskId, &snapshot) ||
            snapshot.state != QStringLiteral("RUNNING")) {
            timer->stop();
            timer->deleteLater();
            return;
        }

        ++(*index);
        if (*index >= sequence->size()) {
            taskManager.updateSubTask(
                taskId, unitId, QStringLiteral("COMPLETED"), 100.0);
            taskManager.finalizeTaskIfAllSubTasksTerminal(taskId);
            timer->deleteLater();
            return;
        }

        const FollowMotionSegment &segment = sequence->at(*index);
        const TaskRpcResult dispatched = self->adapter_->sendMove(
            unitId, segment.linearVelocity, segment.angularVelocity,
            segment.durationMs);
        if (!dispatched.success) {
            const TaskRpcResult stopped = self->adapter_->stopUnit(unitId);
            if (!stopped.success && !stopped.mock)
                taskManager.markUnitControlUncertain(
                    unitId, QStringLiteral("motion sequence failure; stop request failed"));
            taskManager.updateSubTask(
                taskId, unitId, QStringLiteral("FAILED"), 100.0,
                dispatched.errorCode, dispatched.message);
            taskManager.finalizeTaskIfAllSubTasksTerminal(taskId);
            timer->deleteLater();
            return;
        }

        const double progress = 100.0 * (*index) / sequence->size();
        taskManager.updateSubTask(
            taskId, unitId, QStringLiteral("RUNNING"), progress);
        taskManager.appendAudit(
            taskId, QStringLiteral("MOTION_SEGMENT_DISPATCHED"),
            QStringLiteral("%1 segment=%2/%3")
                .arg(unitId).arg(*index + 1).arg(sequence->size()));
        timer->start(segment.durationMs + segment.bufferMs);
    });

    manager.registerTimer(taskId, timer);
    timer->start(segments.first().durationMs + segments.first().bufferMs);
    return first;
}

void TaskOrchestrator::startTargetPolling(
    const QString &taskId, const QString &unitId,
    double targetX, double targetY, double toleranceM, int timeoutMs) {
    QTimer *timer = new QTimer();
    timer->setInterval(200);
    const qint64 startedAt = QDateTime::currentMSecsSinceEpoch();
    const QSharedPointer<double> initialDistance(new double(-1.0));
    TaskOrchestrator *self = this;

    QObject::connect(timer, &QTimer::timeout,
                     [taskId, unitId, targetX, targetY, toleranceM,
                      timeoutMs, startedAt, timer, initialDistance, self]() {
        TaskManager &manager = TaskManager::instance();
        TaskManager::TaskEntry snapshot;
        if (!manager.taskSnapshot(taskId, &snapshot) || snapshot.state != "RUNNING") {
            timer->stop();
            timer->deleteLater();
            return;
        }

        const TaskPoseResult pose = self->adapter_->currentPose(unitId);
        const qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startedAt;
        if (!pose.success) {
            if (elapsed > timeoutMs) {
                const TaskRpcResult stopResult = self->adapter_->stopUnit(unitId);
                if (stopResult.success) {
                    manager.clearUnitControlUncertain(unitId);
                } else if (!stopResult.mock) {
                    manager.markUnitControlUncertain(
                        unitId, QStringLiteral("navigation timeout; stop request failed"));
                }
                manager.updateSubTask(taskId, unitId, QStringLiteral("TIMEOUT"), 100.0,
                                      pose.errorCode.isEmpty()
                                          ? QStringLiteral("UNIT_OFFLINE")
                                          : pose.errorCode,
                                      pose.message);
                manager.finalizeTaskIfAllSubTasksTerminal(taskId);
                timer->stop();
                timer->deleteLater();
            }
            return;
        }

        const double dx = targetX - pose.x;
        const double dy = targetY - pose.y;
        const double distance = qSqrt(dx * dx + dy * dy);
        if (*initialDistance < 0.0)
            *initialDistance = qMax(distance, toleranceM);

        if (pose.mock && distance > toleranceM && distance > 0.0) {
            const double step = qMin(distance, 0.06);
            MockRobotSimulator::instance().setPose(
                unitId,
                pose.x + (dx / distance) * step,
                pose.y + (dy / distance) * step,
                qAtan2(dy, dx));
        }

        const double progress = distance <= toleranceM
            ? 100.0
            : qBound(0.0, 100.0 * (1.0 - distance / qMax(*initialDistance, toleranceM)), 99.0);
        manager.updateSubTask(taskId, unitId, QStringLiteral("RUNNING"), progress,
                              QString(), QStringLiteral("dist=%1m").arg(distance, 0, 'f', 2));

        if (distance <= toleranceM) {
            manager.updateSubTask(taskId, unitId, QStringLiteral("COMPLETED"), 100.0);
            manager.finalizeTaskIfAllSubTasksTerminal(taskId);
            timer->stop();
            timer->deleteLater();
            return;
        }

        if (elapsed > timeoutMs) {
            const TaskRpcResult stopResult = self->adapter_->stopUnit(unitId);
            if (stopResult.success) {
                manager.clearUnitControlUncertain(unitId);
            } else if (!stopResult.mock) {
                manager.markUnitControlUncertain(
                    unitId, QStringLiteral("navigation timeout; stop request failed"));
            }
            manager.updateSubTask(taskId, unitId, QStringLiteral("TIMEOUT"), 100.0,
                                  QStringLiteral("TIMEOUT"),
                                  QStringLiteral("navigation timeout"));
            manager.finalizeTaskIfAllSubTasksTerminal(taskId);
            timer->stop();
            timer->deleteLater();
        }
    });

    TaskManager::instance().registerTimer(taskId, timer);
    timer->start();
}

void TaskOrchestrator::startMockPathPolling(
    const QString &taskId, const QString &unitId, const QJsonArray &points,
    double toleranceM, int timeoutMs) {
    QTimer *timer = new QTimer();
    timer->setInterval(200);
    const qint64 startedAt = QDateTime::currentMSecsSinceEpoch();
    const QSharedPointer<MockPathProgress> pathProgress(new MockPathProgress(points));
    const QSharedPointer<double> segmentInitialDistance(new double(-1.0));
    TaskOrchestrator *self = this;

    QObject::connect(
        timer, &QTimer::timeout,
        [taskId, unitId, toleranceM, timeoutMs, startedAt, timer,
         pathProgress, segmentInitialDistance, self]() {
            TaskManager &manager = TaskManager::instance();
            TaskManager::TaskEntry snapshot;
            if (!manager.taskSnapshot(taskId, &snapshot) ||
                snapshot.state != QStringLiteral("RUNNING")) {
                timer->stop();
                timer->deleteLater();
                return;
            }

            const TaskPoseResult pose = self->adapter_->currentPose(unitId);
            const qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startedAt;
            if (!pose.success) {
                if (elapsed > timeoutMs) {
                    manager.updateSubTask(
                        taskId, unitId, QStringLiteral("TIMEOUT"), 100.0,
                        pose.errorCode.isEmpty() ? QStringLiteral("UNIT_OFFLINE")
                                                 : pose.errorCode,
                        pose.message);
                    manager.finalizeTaskIfAllSubTasksTerminal(taskId);
                    timer->stop();
                    timer->deleteLater();
                }
                return;
            }

            const QJsonObject target = pathProgress->currentTarget();
            const double targetX = target.value(QStringLiteral("x")).toDouble();
            const double targetY = target.value(QStringLiteral("y")).toDouble();
            const double dx = targetX - pose.x;
            const double dy = targetY - pose.y;
            const double distance = qSqrt(dx * dx + dy * dy);
            if (*segmentInitialDistance < 0.0)
                *segmentInitialDistance = qMax(distance, toleranceM);

            if (distance > toleranceM && distance > 0.0) {
                const double step = qMin(distance, 0.06);
                MockRobotSimulator::instance().setPose(
                    unitId,
                    pose.x + (dx / distance) * step,
                    pose.y + (dy / distance) * step,
                    qAtan2(dy, dx));
            }

            const double segmentProgress = distance <= toleranceM
                ? 100.0
                : qBound(0.0,
                         100.0 * (1.0 - distance /
                             qMax(*segmentInitialDistance, toleranceM)),
                         99.0);
            const double overallProgress =
                pathProgress->overallProgress(segmentProgress);
            manager.updateSubTask(
                taskId, unitId, QStringLiteral("RUNNING"), overallProgress,
                QString(), QStringLiteral("waypoint dist=%1m").arg(distance, 0, 'f', 2));

            if (distance <= toleranceM) {
                if (pathProgress->advance()) {
                    manager.updateSubTask(
                        taskId, unitId, QStringLiteral("COMPLETED"), 100.0);
                    manager.finalizeTaskIfAllSubTasksTerminal(taskId);
                    timer->stop();
                    timer->deleteLater();
                    return;
                }
                *segmentInitialDistance = -1.0;
                manager.updateSubTask(
                    taskId, unitId, QStringLiteral("RUNNING"),
                    pathProgress->overallProgress(0.0));
            }

            if (elapsed > timeoutMs) {
                manager.updateSubTask(
                    taskId, unitId, QStringLiteral("TIMEOUT"), 100.0,
                    QStringLiteral("TIMEOUT"), QStringLiteral("path timeout"));
                manager.finalizeTaskIfAllSubTasksTerminal(taskId);
                timer->stop();
                timer->deleteLater();
            }
        });

    TaskManager::instance().registerTimer(taskId, timer);
    timer->start();
}

QJsonArray TaskOrchestrator::staticFormationTargets(
    const QString &formationType, const QJsonArray &unitIds, double spacingM,
    double anchorX, double anchorY, double headingRad, QString *errorMessage) {
    QJsonArray targets;
    QVector<QPair<double, double>> localTargets;
    const QString type = formationType.trimmed().toLower();
    const int count = unitIds.size();

    if (count <= 0 || !qIsFinite(spacingM) || spacingM <= 0.0 ||
        !qIsFinite(anchorX) || !qIsFinite(anchorY) || !qIsFinite(headingRad)) {
        if (errorMessage)
            *errorMessage = QStringLiteral("invalid static formation geometry");
        return targets;
    }

    if (type == QStringLiteral("line")) {
        const double center = (count - 1) / 2.0;
        for (int i = 0; i < count; ++i)
            localTargets.append(qMakePair((i - center) * spacingM, 0.0));
    } else if (type == QStringLiteral("triangle")) {
        if (count < 3) {
            if (errorMessage)
                *errorMessage = QStringLiteral("triangle formation requires at least 3 units");
            return targets;
        }
        const double height = spacingM * qSqrt(3.0) / 2.0;
        localTargets.append(qMakePair(0.0, 2.0 * height / 3.0));
        localTargets.append(qMakePair(-spacingM / 2.0, -height / 3.0));
        localTargets.append(qMakePair(spacingM / 2.0, -height / 3.0));
        for (int i = 3; i < count; ++i)
            localTargets.append(qMakePair((i - 2) * spacingM, -height / 3.0));
    } else if (type == QStringLiteral("column")) {
        const double center = (count - 1) / 2.0;
        for (int i = 0; i < count; ++i)
            localTargets.append(qMakePair(0.0, (i - center) * spacingM));
    } else {
        if (errorMessage)
            *errorMessage = QStringLiteral("unknown formation_type");
        return targets;
    }

    const double cosHeading = qCos(headingRad);
    const double sinHeading = qSin(headingRad);
    for (int i = 0; i < count; ++i) {
        const double localX = localTargets.at(i).first;
        const double localY = localTargets.at(i).second;
        const double worldX = anchorX + cosHeading * localX - sinHeading * localY;
        const double worldY = anchorY + sinHeading * localX + cosHeading * localY;
        if (!qIsFinite(worldX) || !qIsFinite(worldY) ||
            qAbs(worldX) > 1000.0 || qAbs(worldY) > 1000.0) {
            if (errorMessage)
                *errorMessage = QStringLiteral("computed formation target is outside allowed bounds");
            return QJsonArray();
        }
        QJsonObject target;
        target.insert(QStringLiteral("unit_id"), unitIds.at(i).toString());
        target.insert(QStringLiteral("x"), worldX);
        target.insert(QStringLiteral("y"), worldY);
        targets.append(target);
    }

    if (errorMessage)
        errorMessage->clear();
    return targets;
}

QString TaskOrchestrator::cancellationEffect(const QVector<TaskRpcResult> &stopResults) {
    if (stopResults.isEmpty())
        return QStringLiteral("STATE_ONLY_CANCELLED");

    bool allSucceeded = true;
    bool allMock = true;
    bool anySucceeded = false;
    for (const TaskRpcResult &result : stopResults) {
        allSucceeded = allSucceeded && result.success;
        allMock = allMock && result.mock;
        anySucceeded = anySucceeded || result.success;
    }
    if (allSucceeded && allMock)
        return QStringLiteral("CANCEL_CONFIRMED");
    if (anySucceeded)
        return QStringLiteral("STOP_REQUESTED");
    return QStringLiteral("STATE_ONLY_CANCELLED");
}

QJsonObject TaskOrchestrator::taskSnapshotJson(const QString &taskId, bool *found) {
    TaskManager::TaskEntry snapshot;
    const bool exists = TaskManager::instance().taskSnapshot(taskId, &snapshot);
    if (found)
        *found = exists;
    return exists ? snapshot.toJson() : QJsonObject();
}
