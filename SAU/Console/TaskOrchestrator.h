#ifndef TASK_ORCHESTRATOR_H
#define TASK_ORCHESTRATOR_H

#include "LegacyIdlAdapter.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QObject>
#include <QVector>

struct TaskCapabilityPolicy {
    bool targetPointNavigation = false;
    bool pathTasks = false;
    bool staticFormation = false;
    bool followFormation = false;
    bool realUnitRpc = false;
};

enum class FollowSetupPolicy {
    DispatchMock,
    UnsupportedMixed,
    RpcDisabled,
    DispatchReal,
};

struct FollowMotionSegment {
    double linearVelocity;
    double angularVelocity;
    int durationMs;
    int bufferMs;

    FollowMotionSegment(double linear = 0.0, double angular = 0.0,
                        int duration = 0, int buffer = 1000)
        : linearVelocity(linear)
        , angularVelocity(angular)
        , durationMs(duration)
        , bufferMs(buffer) {}
};

struct MotionTaskCommand {
    QString unitId;
    double linearVelocity = 0.0;
    double angularVelocity = 0.0;
    int durationMs = 0;
};

class MockPathProgress {
public:
    explicit MockPathProgress(const QJsonArray &points = QJsonArray());

    QJsonObject currentTarget() const;
    bool advance();
    double overallProgress(double segmentProgressPct) const;

private:
    QJsonArray points_;
    int currentIndex_;
};

class TaskOrchestrator : public QObject {
    Q_OBJECT

public:
    static TaskOrchestrator &instance();

    void setAdapterForTests(LegacyIdlAdapter *adapter);

    TaskRpcResult dispatchTarget(const QString &taskId, const QString &unitId,
                                 double x, double y, double toleranceM, int timeoutMs);
    TaskRpcResult dispatchPath(const QString &taskId, const QString &unitId,
                               const QJsonArray &points, double toleranceM, int timeoutMs);
    TaskRpcResult dispatchMotion(const QString &taskId, const QString &unitId,
                                 double linearVelocity, double angularVelocity,
                                 int durationMs);
    TaskRpcResult dispatchMotionSequence(
        const QString &taskId, const QString &unitId,
        const QVector<FollowMotionSegment> &segments);
    TaskRpcResult stopUnit(const QString &unitId);

    static QJsonArray staticFormationTargets(const QString &formationType,
                                             const QJsonArray &unitIds,
                                             double spacingM,
                                             double anchorX,
                                             double anchorY,
                                             double headingRad,
                                             QString *errorMessage = nullptr);

    static QString cancellationEffect(const QVector<TaskRpcResult> &stopResults);
    static QJsonObject taskSnapshotJson(const QString &taskId, bool *found = nullptr);
    static TaskCapabilityPolicy capabilityPolicy(int mockCount, int realCount,
                                                 bool realRpcEnabled);
    static FollowSetupPolicy followSetupPolicy(int mockCount, int realCount,
                                               bool realRpcEnabled);
    static bool validateFollowMotionSequence(
        const QVector<FollowMotionSegment> &segments,
        QString *errorMessage = nullptr);
    static bool validateMotionRequest(
        const QJsonObject &request, bool unitBound,
        MotionTaskCommand *command = nullptr,
        QString *errorCode = nullptr,
        QString *errorMessage = nullptr);

private:
    explicit TaskOrchestrator(QObject *parent = nullptr);
    void startTargetPolling(const QString &taskId, const QString &unitId,
                            double targetX, double targetY,
                            double toleranceM, int timeoutMs);
    void startMockPathPolling(const QString &taskId, const QString &unitId,
                              const QJsonArray &points,
                              double toleranceM, int timeoutMs);

    LegacyIdlAdapter *adapter_;
};

#endif // TASK_ORCHESTRATOR_H
