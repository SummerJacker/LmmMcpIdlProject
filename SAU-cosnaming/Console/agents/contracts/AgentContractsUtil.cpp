/**
 * @file AgentContractsUtil.cpp
 * @brief AgentContractUtil namespace function implementations.
 *
 * Provides implementations for utility functions declared in AgentContracts.h.
 */

#include "AgentContracts.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

namespace AgentContractUtil {

QString bindingOriginToString(BindingOrigin origin) {
    switch (origin) {
    case BindingOrigin::Runtime:  return QStringLiteral("runtime");
    case BindingOrigin::Restored: return QStringLiteral("restored");
    case BindingOrigin::Mock:     return QStringLiteral("mock");
    }
    return QStringLiteral("unknown");
}

QString connectionStateToString(ConnectionState state) {
    switch (state) {
    case ConnectionState::Online:  return QStringLiteral("online");
    case ConnectionState::Offline: return QStringLiteral("offline");
    case ConnectionState::Unknown: return QStringLiteral("unknown");
    }
    return QStringLiteral("unknown");
}

QString statusFreshnessToString(StatusFreshness freshness) {
    switch (freshness) {
    case StatusFreshness::Fresh:       return QStringLiteral("fresh");
    case StatusFreshness::Stale:       return QStringLiteral("stale");
    case StatusFreshness::Unavailable: return QStringLiteral("unavailable");
    }
    return QStringLiteral("unavailable");
}

QString unitTypeToString(UnitType type) {
    switch (type) {
    case UnitType::Ground:  return QStringLiteral("ground");
    case UnitType::Air:     return QStringLiteral("air");
    case UnitType::Unknown: return QStringLiteral("unknown");
    }
    return QStringLiteral("unknown");
}

UnitType unitTypeFromId(const QString &unitId) {
    if (unitId.isEmpty())
        return UnitType::Unknown;
    if (unitId.startsWith(QLatin1Char('G')))
        return UnitType::Ground;
    if (unitId.startsWith(QLatin1Char('A')))
        return UnitType::Air;
    return UnitType::Unknown;
}

QJsonObject statusSnapshotToJson(const AgentStatusSnapshot &snap) {
    QJsonObject o;
    o.insert(QStringLiteral("unit_id"), QJsonValue(snap.unitId));
    if (!snap.alias.isEmpty())
        o.insert(QStringLiteral("alias"), QJsonValue(snap.alias));
    if (!snap.displayName.isEmpty())
        o.insert(QStringLiteral("display_name"), QJsonValue(snap.displayName));
    o.insert(QStringLiteral("unit_type"), QJsonValue(unitTypeToString(snap.unitType)));
    o.insert(QStringLiteral("binding_state"),
             QJsonValue(snap.bindingState == BindingState::Bound ? QStringLiteral("bound") : QStringLiteral("unbound")));
    o.insert(QStringLiteral("binding_origin"), QJsonValue(bindingOriginToString(snap.bindingOrigin)));
    o.insert(QStringLiteral("connection_state"), QJsonValue(connectionStateToString(snap.connectionState)));
    o.insert(QStringLiteral("status_freshness"), QJsonValue(statusFreshnessToString(snap.statusFreshness)));
    o.insert(QStringLiteral("mock"), QJsonValue(snap.mock));
    if (!snap.runMode.isEmpty())
        o.insert(QStringLiteral("run_mode"), QJsonValue(snap.runMode));
    if (!snap.role.isEmpty())
        o.insert(QStringLiteral("role"), QJsonValue(snap.role));

    if (snap.hasPose) {
        QJsonObject pose;
        pose.insert(QStringLiteral("x"), QJsonValue(snap.poseX));
        pose.insert(QStringLiteral("y"), QJsonValue(snap.poseY));
        pose.insert(QStringLiteral("z"), QJsonValue(snap.poseZ));
        pose.insert(QStringLiteral("yaw"), QJsonValue(snap.poseYaw));
        o.insert(QStringLiteral("pose"), QJsonValue(pose));
    }

    if (snap.hasSpeed) {
        QJsonObject spd;
        spd.insert(QStringLiteral("linear_m_s"), QJsonValue(snap.speedLinear));
        spd.insert(QStringLiteral("angular_rad_s"), QJsonValue(snap.speedAngular));
        o.insert(QStringLiteral("speed"), QJsonValue(spd));
    }

    if (snap.hasBattery)
        o.insert(QStringLiteral("battery_percent"), QJsonValue(snap.batteryPercent));
    if (snap.hasHealth)
        o.insert(QStringLiteral("health"), QJsonValue(snap.health));

    o.insert(QStringLiteral("last_seen_ms"), QJsonValue(snap.lastSeenMs));
    o.insert(QStringLiteral("observed_at_ms"), QJsonValue(snap.observedAtMs));
    if (!snap.lastError.isEmpty())
        o.insert(QStringLiteral("last_error"), QJsonValue(snap.lastError));

    if (!snap.capabilities.isEmpty()) {
        QJsonArray caps;
        for (const QString &c : snap.capabilities)
            caps.append(QJsonValue(c));
        o.insert(QStringLiteral("capabilities"), QJsonValue(caps));
    }

    return o;
}

QJsonObject lookupResultToJson(const AgentLookupResult &result) {
    QJsonObject o;
    o.insert(QStringLiteral("unit_id"), QJsonValue(result.unitId));
    if (!result.alias.isEmpty())
        o.insert(QStringLiteral("alias"), QJsonValue(result.alias));
    if (!result.displayName.isEmpty())
        o.insert(QStringLiteral("display_name"), QJsonValue(result.displayName));
    o.insert(QStringLiteral("unit_type"), QJsonValue(unitTypeToString(result.unitType)));
    o.insert(QStringLiteral("binding_state"),
             QJsonValue(result.bindingState == BindingState::Bound ? QStringLiteral("bound") : QStringLiteral("unbound")));
    o.insert(QStringLiteral("binding_origin"), QJsonValue(bindingOriginToString(result.bindingOrigin)));
    o.insert(QStringLiteral("mock"), QJsonValue(result.mock));
    return o;
}

} // namespace AgentContractUtil
