/**
 * @file MockRobotSimulator.cpp
 * @brief 模拟车状态与简单平面运动学。
 */

#include "MockRobotSimulator.h"

#include <QJsonValue>
#include <QMutexLocker>
#include <QSet>
#include <QtMath>

MockRobotSimulator &MockRobotSimulator::instance() {
    static MockRobotSimulator inst;
    return inst;
}

bool MockRobotSimulator::isMockSbh(const char *sbh) {
    return sbh != nullptr && QString::fromUtf8(sbh).startsWith(QStringLiteral("MOCK:"));
}

void MockRobotSimulator::ensureUnit(const QString &unitId) {
    QMutexLocker lock(&mutex_);
    if (!units_.contains(unitId)) {
        State s;
        s.isAir = unitId.startsWith(QLatin1Char('A'));
        units_.insert(unitId, s);
    }
}

void MockRobotSimulator::applyMove(const QString &unitId, double linearVelocity, double angularVelocity,
                                   int durationMs) {
    QMutexLocker lock(&mutex_);
    State &s = units_[unitId];
    // 解除原本将 dt 强制限制在 10.0 秒以内的防越界截断，
    // 因为在 MCP 侧已经有配置好的最长执行时间控制。
    const double dt = qMax(0.0, durationMs / 1000.0);
    s.lastLinear = linearVelocity;
    s.lastAngular = angularVelocity;
    /* 简单平面运动：线速度沿当前航向，角速度绕 Z */
    s.x += linearVelocity * qCos(s.yaw) * dt;
    s.y += linearVelocity * qSin(s.yaw) * dt;
    s.yaw += angularVelocity * dt;
    if (unitId == followLeaderId_)
        updateFollowersLocked();
}

void MockRobotSimulator::setPose(const QString &unitId, double x, double y, double yaw) {
    QMutexLocker lock(&mutex_);
    State &s = units_[unitId];
    s.x = x;
    s.y = y;
    s.yaw = yaw;
    if (unitId == followLeaderId_)
        updateFollowersLocked();
}

void MockRobotSimulator::setPose3D(const QString &unitId, double x, double y, double z, double yaw) {
    QMutexLocker lock(&mutex_);
    State &s = units_[unitId];
    s.x = x;
    s.y = y;
    s.z = z;
    s.yaw = yaw;
}

bool MockRobotSimulator::configureFollowFormation(
    const QString &leaderId,
    const QStringList &followerIds,
    const QVector<float> &effectiveDistances,
    QString *error) {
    QMutexLocker lock(&mutex_);
    if (error)
        error->clear();
    if (!units_.contains(leaderId)) {
        if (error)
            *error = QStringLiteral("Mock leader is not registered");
        return false;
    }
    if (followerIds.isEmpty() || followerIds.size() != effectiveDistances.size()) {
        if (error)
            *error = QStringLiteral("Follower ids and distances must have the same non-zero size");
        return false;
    }

    QSet<QString> memberIds;
    memberIds.insert(leaderId);
    for (int i = 0; i < followerIds.size(); ++i) {
        const QString &followerId = followerIds.at(i);
        if (!units_.contains(followerId)) {
            if (error)
                *error = QStringLiteral("Mock follower is not registered: %1").arg(followerId);
            return false;
        }
        if (memberIds.contains(followerId)) {
            if (error)
                *error = QStringLiteral("Formation members must be unique");
            return false;
        }
        const float distance = effectiveDistances.at(i);
        if (!qIsFinite(distance) || distance <= 0.0f) {
            if (error)
                *error = QStringLiteral("Follower distance must be positive and finite");
            return false;
        }
        memberIds.insert(followerId);
    }

    followLeaderId_ = leaderId;
    followFollowerIds_ = followerIds;
    followDistances_ = effectiveDistances;
    updateFollowersLocked();
    return true;
}

void MockRobotSimulator::clearFollowFormation() {
    QMutexLocker lock(&mutex_);
    followLeaderId_.clear();
    followFollowerIds_.clear();
    followDistances_.clear();
}

void MockRobotSimulator::clearAirGroundFormation() {
    QMutexLocker lock(&mutex_);
    airGroundAirLeaderId_.clear();
    airGroundChainIds_.clear();
    airGroundDistances_.clear();
    airGroundAnglesRad_.clear();
}

bool MockRobotSimulator::configureAirGroundFormation(
    const QString &airLeaderId,
    const QStringList &groundChainIds,
    const QVector<float> &distances,
    const QVector<float> &anglesRad,
    QString *error) {
    QMutexLocker lock(&mutex_);
    if (error)
        error->clear();
    if (!units_.contains(airLeaderId)) {
        if (error)
            *error = QStringLiteral("Mock air leader is not registered");
        return false;
    }
    if (groundChainIds.isEmpty() ||
        groundChainIds.size() != distances.size() ||
        groundChainIds.size() != anglesRad.size()) {
        if (error)
            *error = QStringLiteral("Ground chain ids, distances and angles must have matching non-zero size");
        return false;
    }

    QSet<QString> memberIds;
    memberIds.insert(airLeaderId);
    for (int i = 0; i < groundChainIds.size(); ++i) {
        const QString &followerId = groundChainIds.at(i);
        if (!units_.contains(followerId)) {
            if (error)
                *error = QStringLiteral("Mock ground follower is not registered: %1").arg(followerId);
            return false;
        }
        if (memberIds.contains(followerId)) {
            if (error)
                *error = QStringLiteral("Air-ground formation members must be unique");
            return false;
        }
        const float distance = distances.at(i);
        if (!qIsFinite(distance) || distance <= 0.0f) {
            if (error)
                *error = QStringLiteral("Follower distance must be positive and finite");
            return false;
        }
        memberIds.insert(followerId);
    }

    airGroundAirLeaderId_ = airLeaderId;
    airGroundChainIds_ = groundChainIds;
    airGroundDistances_ = distances;
    airGroundAnglesRad_ = anglesRad;
    updateAirGroundFollowersLocked();
    return true;
}

void MockRobotSimulator::updateAirGroundFollowersLocked() {
    if (airGroundAirLeaderId_.isEmpty() || !units_.contains(airGroundAirLeaderId_))
        return;

    const State leader = units_.value(airGroundAirLeaderId_);
    double parentX = leader.x;
    double parentY = leader.y;
    double parentYaw = leader.yaw;
    for (int i = 0; i < airGroundChainIds_.size(); ++i) {
        State &follower = units_[airGroundChainIds_.at(i)];
        const double distance = airGroundDistances_.at(i);
        const double angle = airGroundAnglesRad_.at(i);
        const double heading = parentYaw + angle;
        follower.x = parentX - distance * qCos(heading);
        follower.y = parentY - distance * qSin(heading);
        follower.yaw = heading;
        follower.z = 0.0;
        parentX = follower.x;
        parentY = follower.y;
        parentYaw = heading;
    }
}

void MockRobotSimulator::updateFollowersLocked() {
    if (followLeaderId_.isEmpty() || !units_.contains(followLeaderId_))
        return;

    const State leader = units_.value(followLeaderId_);
    double parentX = leader.x;
    double parentY = leader.y;
    for (int i = 0; i < followFollowerIds_.size(); ++i) {
        State &follower = units_[followFollowerIds_.at(i)];
        const double distance = followDistances_.at(i);
        follower.x = parentX - distance * qCos(leader.yaw);
        follower.y = parentY - distance * qSin(leader.yaw);
        follower.yaw = leader.yaw;
        follower.lastLinear = leader.lastLinear;
        follower.lastAngular = leader.lastAngular;
        parentX = follower.x;
        parentY = follower.y;
    }
}

void MockRobotSimulator::stop(const QString &unitId) {
    QMutexLocker lock(&mutex_);
    if (!units_.contains(unitId))
        return;
    State &s = units_[unitId];
    s.lastLinear = 0.0;
    s.lastAngular = 0.0;
}

QJsonObject MockRobotSimulator::groundStatusJson(const QString &unitId) const {
    QMutexLocker lock(&mutex_);
    QJsonObject data;
    data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
    if (!units_.contains(unitId)) {
        data.insert(QStringLiteral("online"), QJsonValue(false));
        return data;
    }
    const State &s = units_.value(unitId);
    QJsonObject pose;
    pose.insert(QStringLiteral("x"), QJsonValue(s.x));
    pose.insert(QStringLiteral("y"), QJsonValue(s.y));
    pose.insert(QStringLiteral("yaw"), QJsonValue(s.yaw));
    data.insert(QStringLiteral("pose"), QJsonValue(pose));
    QJsonObject spd;
    spd.insert(QStringLiteral("linear_m_s"), QJsonValue(s.lastLinear));
    spd.insert(QStringLiteral("angular_rad_s"), QJsonValue(s.lastAngular));
    data.insert(QStringLiteral("speed"), QJsonValue(spd));
    data.insert(QStringLiteral("online"), QJsonValue(true));
    data.insert(QStringLiteral("mock"), QJsonValue(true));
    data.insert(QStringLiteral("kind"), QJsonValue(QStringLiteral("ugv")));
    return data;
}

QJsonObject MockRobotSimulator::airStatusJson(const QString &unitId) const {
    QMutexLocker lock(&mutex_);
    QJsonObject data;
    data.insert(QStringLiteral("unit_id"), QJsonValue(unitId));
    if (!units_.contains(unitId)) {
        data.insert(QStringLiteral("online"), QJsonValue(false));
        return data;
    }
    const State &s = units_.value(unitId);
    QJsonObject pose;
    pose.insert(QStringLiteral("x"), QJsonValue(s.x));
    pose.insert(QStringLiteral("y"), QJsonValue(s.y));
    pose.insert(QStringLiteral("z"), QJsonValue(s.z));
    pose.insert(QStringLiteral("yaw"), QJsonValue(s.yaw));
    data.insert(QStringLiteral("pose"), QJsonValue(pose));
    QJsonObject spd;
    spd.insert(QStringLiteral("linear_m_s"), QJsonValue(s.lastLinear));
    spd.insert(QStringLiteral("angular_rad_s"), QJsonValue(s.lastAngular));
    data.insert(QStringLiteral("speed"), QJsonValue(spd));
    data.insert(QStringLiteral("online"), QJsonValue(true));
    data.insert(QStringLiteral("mock"), QJsonValue(true));
    data.insert(QStringLiteral("kind"), QJsonValue(QStringLiteral("uav")));
    return data;
}
