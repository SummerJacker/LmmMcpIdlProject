/**
 * @file MockStatusProbe.cpp
 * @brief 模拟单元状态探测器实现。
 */

#include "MockStatusProbe.h"
#include "MockRobotSimulator.h"

#include <QDateTime>
#include <QJsonObject>
#include <QJsonValue>

AgentStatusSnapshot MockStatusProbe_probe(const QString &unitId) {
    AgentStatusSnapshot snap;
    snap.unitId = unitId;
    snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
    snap.mock = true;
    snap.bindingState = BindingState::Bound;
    snap.bindingOrigin = BindingOrigin::Mock;
    snap.connectionState = ConnectionState::Online;
    snap.runMode = QStringLiteral("sim");

    /* 根据 unit_id 前缀推导类型 */
    if (unitId.startsWith(QLatin1Char('G'))) {
        snap.unitType = UnitType::Ground;
        snap.capabilities = QStringList{ QStringLiteral("pose"),
                                         QStringLiteral("speed"),
                                         QStringLiteral("role") };
    } else if (unitId.startsWith(QLatin1Char('A'))) {
        snap.unitType = UnitType::Air;
        snap.capabilities = QStringList{ QStringLiteral("pose"),
                                         QStringLiteral("speed"),
                                         QStringLiteral("role") };
    } else {
        snap.unitType = UnitType::Unknown;
    }

    /* 从 MockRobotSimulator 获取当前状态 */
    const QJsonObject data = MockRobotSimulator::instance().groundStatusJson(unitId);

    if (data.value(QStringLiteral("online")).toBool(false)) {
        /* 解析位姿 */
        if (data.contains(QStringLiteral("pose"))) {
            const QJsonObject pose = data.value(QStringLiteral("pose")).toObject();
            snap.poseX = pose.value(QStringLiteral("x")).toDouble(0.0);
            snap.poseY = pose.value(QStringLiteral("y")).toDouble(0.0);
            snap.poseZ = pose.value(QStringLiteral("z")).toDouble(0.0);
            snap.poseYaw = pose.value(QStringLiteral("yaw")).toDouble(0.0);
            snap.hasPose = true;
        }

        /* 解析速度 */
        if (data.contains(QStringLiteral("speed"))) {
            const QJsonObject spd = data.value(QStringLiteral("speed")).toObject();
            snap.speedLinear = spd.value(QStringLiteral("linear_m_s")).toDouble(0.0);
            snap.speedAngular = spd.value(QStringLiteral("angular_rad_s")).toDouble(0.0);
            snap.hasSpeed = true;
        }

        snap.connectionState = ConnectionState::Online;
    } else {
        snap.connectionState = ConnectionState::Offline;
        snap.lastError = QStringLiteral("mock unit not initialized in simulator");
    }

    snap.lastSeenMs = snap.observedAtMs;
    snap.statusFreshness = StatusFreshness::Fresh;

    return snap;
}
