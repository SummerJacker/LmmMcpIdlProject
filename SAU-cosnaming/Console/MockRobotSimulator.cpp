/**
 * @file MockRobotSimulator.cpp
 * @brief 模拟车状态与简单平面运动学。
 */

#include "MockRobotSimulator.h"

#include <QJsonValue>
#include <QMutexLocker>
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
    if (!units_.contains(unitId))
        units_.insert(unitId, State{});
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
    return data;
}
