/**
 * @file AgentContracts.h
 * @brief Agent directory, status, and alias system contracts.
 *
 * Frozen before parallel development. Version 1.0.
 */

#ifndef AGENT_CONTRACTS_H
#define AGENT_CONTRACTS_H

#include <QJsonObject>
#include <QString>
#include <QStringList>
#include <QVector>

// ============================================================================
// Enums
// ============================================================================

enum class BindingState {
    Bound,
};

enum class BindingOrigin {
    Runtime,
    Restored,
    Mock,
};

enum class ConnectionState {
    Online,
    Offline,
    Unknown,
};

enum class StatusFreshness {
    Fresh,
    Stale,
    Unavailable,
};

enum class UnitType {
    Ground,
    Air,
    Unknown,
};

// ============================================================================
// Data structures
// ============================================================================

struct AliasMutationResult {
    bool success = false;
    QString errorCode;
    QString errorMessage;
    QString canonicalUnitId;
    QString finalAlias;
    qint64 updatedAtMs = 0;
};

struct AgentLookupResult {
    bool found = false;
    QString unitId;
    QString alias;
    QString displayName;
    UnitType unitType = UnitType::Unknown;
    BindingState bindingState = BindingState::Bound;
    BindingOrigin bindingOrigin = BindingOrigin::Runtime;
    bool mock = false;
};

struct AgentStatusSnapshot {
    QString unitId;
    QString alias;
    QString displayName;
    UnitType unitType = UnitType::Unknown;
    BindingState bindingState = BindingState::Bound;
    BindingOrigin bindingOrigin = BindingOrigin::Runtime;
    ConnectionState connectionState = ConnectionState::Unknown;
    StatusFreshness statusFreshness = StatusFreshness::Unavailable;
    bool mock = false;
    QString runMode;
    QString role;
    double poseX = 0.0;
    double poseY = 0.0;
    double poseZ = 0.0;
    double poseYaw = 0.0;
    bool hasPose = false;
    double speedLinear = 0.0;
    double speedAngular = 0.0;
    bool hasSpeed = false;
    double batteryPercent = -1.0;
    bool hasBattery = false;
    QString health;
    bool hasHealth = false;
    qint64 lastSeenMs = 0;
    qint64 observedAtMs = 0;
    QString lastError;
    QStringList capabilities;
};

// ============================================================================
// Interfaces
// ============================================================================

class IAgentDirectory {
public:
    virtual ~IAgentDirectory() = default;

    virtual QVector<AgentLookupResult> listBindings() const = 0;
    virtual AgentLookupResult findByUnitId(const QString &unitId) const = 0;
    virtual AgentLookupResult resolveName(const QString &name) const = 0;
    virtual AliasMutationResult setAlias(
        const QString &unitId,
        const QString &alias,
        const QStringList &reservedNames) = 0;
    virtual AliasMutationResult clearAlias(const QString &unitId) = 0;
    virtual void replaceBindings(const QVector<AgentLookupResult> &bindings) = 0;
    virtual void upsertBinding(const AgentLookupResult &binding) = 0;
    virtual void removeBinding(const QString &unitId) = 0;
    virtual QStringList allKnownAliases() const = 0;
    virtual QStringList allKnownUnitIds() const = 0;
};

class IAgentStatusService {
public:
    virtual ~IAgentStatusService() = default;

    virtual AgentStatusSnapshot getStatus(const QString &unitId, bool refresh) = 0;
    virtual QVector<AgentStatusSnapshot> getAllStatus() = 0;
    virtual qint64 freshnessThresholdMs() const = 0;
    virtual void setDirectory(IAgentDirectory *directory) = 0;
};

// ============================================================================
// Utility functions
// ============================================================================

namespace AgentContractUtil {

QString bindingOriginToString(BindingOrigin origin);
QString connectionStateToString(ConnectionState state);
QString statusFreshnessToString(StatusFreshness freshness);
QString unitTypeToString(UnitType type);
UnitType unitTypeFromId(const QString &unitId);
QJsonObject statusSnapshotToJson(const AgentStatusSnapshot &snap);
QJsonObject lookupResultToJson(const AgentLookupResult &result);

} // namespace AgentContractUtil

#endif // AGENT_CONTRACTS_H
