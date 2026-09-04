#ifndef LEGACY_IDL_ADAPTER_H
#define LEGACY_IDL_ADAPTER_H

#include <QJsonArray>
#include <QJsonObject>
#include <QString>

struct TaskRpcResult {
    bool success = false;
    bool mock = false;
    double executionMs = 0.0;
    QString errorCode;
    QString message;
};

struct TaskPoseResult {
    bool success = false;
    bool mock = false;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;   // air unit altitude; always 0 for ground units
    QString errorCode;
    QString message;
};

class LegacyIdlAdapter {
public:
    virtual ~LegacyIdlAdapter() {}

    static LegacyIdlAdapter &instance();
    static bool realRpcEnabled();
    static QString taskTypeForNavigateRoute(const QString &path);
    static QString taskTypeForStaticFormationRoute(const QString &path);
    static QJsonObject withStaticFormationTransformDefaults(const QJsonObject &request);

    virtual QString canonicalUnitId(const QString &unitId) const;
    virtual bool isBound(const QString &unitId) const;
    virtual bool isMock(const QString &unitId) const;
    virtual bool isGroundUnit(const QString &unitId) const;
    virtual bool isAirUnit(const QString &unitId) const;

    virtual TaskRpcResult setTaskPoint(const QString &unitId, double x, double y);
    virtual TaskRpcResult setTaskPath(const QString &unitId, const QJsonArray &points);
    virtual TaskRpcResult sendMove(const QString &unitId, double linearVelocity,
                                   double angularVelocity, int durationMs);
    virtual TaskPoseResult currentPose(const QString &unitId);
    virtual TaskPoseResult airCurrentPose(const QString &unitId);
    virtual TaskRpcResult stopUnit(const QString &unitId);

protected:
    LegacyIdlAdapter() {}
};

#endif // LEGACY_IDL_ADAPTER_H
