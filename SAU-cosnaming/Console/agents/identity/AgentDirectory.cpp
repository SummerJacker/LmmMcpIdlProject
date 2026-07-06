/**
 * @file AgentDirectory.cpp
 * @brief 智能体目录实现：绑定视图 + 别名管理。
 */

#include "AgentDirectory.h"
#include "AgentNameNormalizer.h"

#include <QDateTime>
#include <QMutexLocker>
#include <QString>
#include <QStringList>
#include <QVector>

// ============================================================================
// 构造 / 初始化
// ============================================================================

AgentDirectory::AgentDirectory(QObject *parent)
{
    Q_UNUSED(parent);
}

bool AgentDirectory::initialize()
{
    return aliasStore_.load();
}

// ============================================================================
// 绑定视图操作
// ============================================================================

QVector<AgentLookupResult> AgentDirectory::listBindings() const
{
    QMutexLocker locker(&mutex_);
    QVector<AgentLookupResult> results;
    results.reserve(bindings_.size());
    for (auto it = bindings_.constBegin(); it != bindings_.constEnd(); ++it) {
        AgentLookupResult result = it.value();
        result.alias = aliasStore_.aliasForUnit(result.unitId);
        result.displayName = result.alias.isEmpty() ? result.unitId : result.alias;
        results.append(result);
    }
    return results;
}

AgentLookupResult AgentDirectory::findByUnitId(const QString &unitId) const
{
    QMutexLocker locker(&mutex_);
    auto it = bindings_.constFind(unitId);
    if (it == bindings_.constEnd()) {
        AgentLookupResult notFound;
        notFound.found = false;
        return notFound;
    }
    AgentLookupResult result = it.value();
    result.alias = aliasStore_.aliasForUnit(result.unitId);
    result.displayName = result.alias.isEmpty() ? result.unitId : result.alias;
    return result;
}

AgentLookupResult AgentDirectory::resolveName(const QString &name) const
{
    QMutexLocker locker(&mutex_);

    // Priority 1: exact unit_id match (case-sensitive)
    auto it = bindings_.constFind(name);
    if (it != bindings_.constEnd()) {
        AgentLookupResult result = it.value();
        result.alias = aliasStore_.aliasForUnit(result.unitId);
        result.displayName = result.alias.isEmpty() ? result.unitId : result.alias;
        return result;
    }

    // Priority 2: alias match (case-folded comparison key)
    const QString normalized = AgentNameNormalizer::normalize(name);
    if (!normalized.isEmpty()) {
        const QString cmpKey = AgentNameNormalizer::comparisonKey(normalized);
        const QString uid = aliasStore_.unitForAlias(cmpKey);
        if (!uid.isEmpty()) {
            auto bindIt = bindings_.constFind(uid);
            if (bindIt != bindings_.constEnd()) {
                AgentLookupResult result = bindIt.value();
                result.alias = aliasStore_.aliasForUnit(uid);
                result.displayName = result.alias.isEmpty() ? result.unitId : result.alias;
                return result;
            }
        }
    }

    // Not found
    AgentLookupResult notFound;
    notFound.found = false;
    return notFound;
}

void AgentDirectory::replaceBindings(const QVector<AgentLookupResult> &bindings)
{
    QMutexLocker locker(&mutex_);
    bindings_.clear();
    for (const AgentLookupResult &b : bindings) {
        bindings_.insert(b.unitId, b);
    }
}

void AgentDirectory::upsertBinding(const AgentLookupResult &binding)
{
    QMutexLocker locker(&mutex_);
    bindings_.insert(binding.unitId, binding);
}

void AgentDirectory::removeBinding(const QString &unitId)
{
    QMutexLocker locker(&mutex_);
    bindings_.remove(unitId);
}

// ============================================================================
// 别名操作
// ============================================================================

AliasMutationResult AgentDirectory::setAlias(const QString &unitId, const QString &alias,
                                              const QStringList &reservedNames)
{
    QMutexLocker locker(&mutex_);
    return internalSetAlias(unitId, alias, reservedNames);
}

AliasMutationResult AgentDirectory::clearAlias(const QString &unitId)
{
    QMutexLocker locker(&mutex_);
    return internalClearAlias(unitId);
}

// ============================================================================
// 批量查询
// ============================================================================

QStringList AgentDirectory::allKnownAliases() const
{
    QMutexLocker locker(&mutex_);
    return aliasStore_.allAliasStrings();
}

QStringList AgentDirectory::allKnownUnitIds() const
{
    QMutexLocker locker(&mutex_);

    // Start with currently bound unit IDs
    QStringList ids = bindings_.keys();

    // Append persisted unit IDs that are not currently bound
    const QStringList persistedIds = aliasStore_.allUnitIds();
    for (const QString &pid : persistedIds) {
        if (!ids.contains(pid))
            ids.append(pid);
    }

    return ids;
}

// ============================================================================
// 内部实现（调用者已持有 mutex_）
// ============================================================================

AliasMutationResult AgentDirectory::internalSetAlias(const QString &unitId, const QString &alias,
                                                      const QStringList &reservedNames)
{
    AliasMutationResult result;
    result.canonicalUnitId = unitId;

    // --- Step 1: Validate unit_id is currently bound ---
    if (!bindings_.contains(unitId)) {
        result.success = false;
        result.errorCode = QStringLiteral("unit_not_bound");
        result.errorMessage = QStringLiteral("unit_id is not currently bound: ") + unitId;
        return result;
    }

    // --- Step 2: Validate and normalize the alias ---
    const QPair<bool, QString> validation = AgentNameNormalizer::validate(alias);
    if (!validation.first) {
        result.success = false;
        result.errorCode = QStringLiteral("invalid_alias");
        result.errorMessage = validation.second;
        return result;
    }

    const QString normalized = AgentNameNormalizer::normalize(alias);
    if (normalized.isEmpty()) {
        result.success = false;
        result.errorCode = QStringLiteral("invalid_alias");
        result.errorMessage = QStringLiteral("alias is empty after normalization");
        return result;
    }

    const QString cmpKey = AgentNameNormalizer::comparisonKey(normalized);

    // --- Step 3: Conflict detection ---

    // 3a: Check against all unit_ids (case-folded)
    for (auto it = bindings_.constBegin(); it != bindings_.constEnd(); ++it) {
        if (it.key().toCaseFolded() == cmpKey) {
            result.success = false;
            result.errorCode = QStringLiteral("alias_conflict");
            result.errorMessage =
                QStringLiteral("alias conflicts with unit_id: ") + it.key();
            return result;
        }
    }

    // 3b: Check against other aliases (case-folded) — allow re-setting own alias
    const QString existingOwner = aliasStore_.unitForAlias(cmpKey);
    if (!existingOwner.isEmpty() && existingOwner != unitId) {
        result.success = false;
        result.errorCode = QStringLiteral("alias_conflict");
        result.errorMessage =
            QStringLiteral("alias is already used by unit_id: ") + existingOwner;
        return result;
    }

    // 3c: Check against reserved names
    if (isNameReserved(cmpKey, reservedNames)) {
        result.success = false;
        result.errorCode = QStringLiteral("alias_reserved");
        result.errorMessage = QStringLiteral("alias conflicts with a reserved name");
        return result;
    }

    // --- Step 4: Persist to AliasStore ---
    const qint64 nowMs = QDateTime::currentMSecsSinceEpoch();
    if (!aliasStore_.setAlias(unitId, normalized, nowMs)) {
        result.success = false;
        result.errorCode = QStringLiteral("store_error");
        result.errorMessage = QStringLiteral("failed to persist alias");
        return result;
    }

    // --- Step 5: Save to disk ---
    aliasStore_.save();

    result.success = true;
    result.finalAlias = normalized;
    result.updatedAtMs = nowMs;
    return result;
}

AliasMutationResult AgentDirectory::internalClearAlias(const QString &unitId)
{
    AliasMutationResult result;
    result.canonicalUnitId = unitId;

    aliasStore_.removeAlias(unitId);
    aliasStore_.save();

    result.success = true;
    result.finalAlias = QString();
    result.updatedAtMs = QDateTime::currentMSecsSinceEpoch();
    return result;
}

// ============================================================================
// 辅助方法
// ============================================================================

bool AgentDirectory::isNameReserved(const QString &comparisonKey,
                                     const QStringList &reservedNames) const
{
    for (const QString &name : reservedNames) {
        if (name.trimmed().toCaseFolded() == comparisonKey)
            return true;
    }
    return false;
}

QString AgentDirectory::resolveToUnitId(const QString &name) const
{
    // Priority 1: exact unit_id match
    if (bindings_.contains(name))
        return name;

    // Priority 2: alias match
    const QString normalized = AgentNameNormalizer::normalize(name);
    if (!normalized.isEmpty()) {
        const QString cmpKey = AgentNameNormalizer::comparisonKey(normalized);
        const QString uid = aliasStore_.unitForAlias(cmpKey);
        if (!uid.isEmpty())
            return uid;
    }

    return QString();
}
