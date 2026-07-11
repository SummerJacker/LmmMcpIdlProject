/**
 * @file AgentStatusService.cpp
 * @brief 智能体状态服务实现。
 */

#include "AgentStatusService.h"
#include "MockStatusProbe.h"
#include "GroundStatusProbe.h"
#include "AirStatusProbe.h"
#include "MockRobotSimulator.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "iluchdrs.h"
#ifdef __cplusplus
}
#endif

#include "console.h"

#include <QDateTime>
#include <QMutexLocker>

/* --------------------------------------------------------------------------
 * sbhForUid — 从全局 Units_Hash_Table 查找 SBH，与 HttpApiExecutor.cpp 一致
 * -------------------------------------------------------------------------- */
static char *sbhForUid(const QString &unitId) {
    extern ilu_HashTable Units_Hash_Table;
    QByteArray u = unitId.toUtf8();
    if (!Units_Hash_Table)
        return nullptr;
    return (char *)ilu_hash_FindInTable(Units_Hash_Table, reinterpret_cast<ilu_refany>(u.data()));
}

/* --------------------------------------------------------------------------
 * 构造 / 析构
 * -------------------------------------------------------------------------- */
AgentStatusService::AgentStatusService() = default;
AgentStatusService::~AgentStatusService() = default;

void AgentStatusService::setFreshnessThresholdMs(qint64 ms) {
    QMutexLocker lock(&mutex_);
    freshnessThresholdMs_ = ms;
}

void AgentStatusService::setDirectory(IAgentDirectory *directory) {
    QMutexLocker lock(&mutex_);
    directory_ = directory;
}

/* --------------------------------------------------------------------------
 * computeFreshness
 * -------------------------------------------------------------------------- */
StatusFreshness AgentStatusService::computeFreshness(const AgentStatusSnapshot &snap) const {
    if (snap.lastSeenMs <= 0)
        return StatusFreshness::Unavailable;
    const qint64 age = QDateTime::currentMSecsSinceEpoch() - snap.lastSeenMs;
    if (age <= freshnessThresholdMs_)
        return StatusFreshness::Fresh;
    /* 有历史数据但已过期 */
    if (snap.hasPose || snap.hasSpeed)
        return StatusFreshness::Stale;
    return StatusFreshness::Unavailable;
}

/* --------------------------------------------------------------------------
 * executeProbe — 根据 SBH 前缀分派到对应探测器
 * -------------------------------------------------------------------------- */
AgentStatusSnapshot AgentStatusService::executeProbe(const QString &unitId, const char *sbh) const {
    /* Mock 单元：直接用 MockStatusProbe */
    if (MockRobotSimulator::isMockSbh(sbh)) {
        return MockStatusProbe_probe(unitId);
    }

    /* 真实单元：按前缀分派 */
    if (unitId.startsWith(QLatin1Char('G'))) {
        return GroundStatusProbe_probe(unitId, sbh);
    }
    if (unitId.startsWith(QLatin1Char('A'))) {
        return AirStatusProbe_probe(unitId, sbh);
    }

    /* 无法识别类型 */
    AgentStatusSnapshot snap;
    snap.unitId = unitId;
    snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
    snap.unitType = UnitType::Unknown;
    snap.connectionState = ConnectionState::Unknown;
    snap.statusFreshness = StatusFreshness::Unavailable;
    snap.lastError = QStringLiteral("unknown unit_id prefix for status probe");
    return snap;
}

/* --------------------------------------------------------------------------
 * getStatus
 * -------------------------------------------------------------------------- */
AgentStatusSnapshot AgentStatusService::getStatus(const QString &unitId, bool refresh) {
    QMutexLocker lock(&mutex_);

    if (!refresh) {
        /* 仅返回缓存 */
        if (cache_.contains(unitId)) {
            AgentStatusSnapshot snap = cache_.value(unitId);
            snap.statusFreshness = computeFreshness(snap);
            return snap;
        }
        /* 无缓存：构造一个 Unavailable 快照 */
        AgentStatusSnapshot snap;
        snap.unitId = unitId;
        snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
        snap.unitType = AgentContractUtil::unitTypeFromId(unitId);
        snap.connectionState = ConnectionState::Unknown;
        snap.statusFreshness = StatusFreshness::Unavailable;
        snap.lastError = QStringLiteral("no cached status");
        return snap;
    }

    /* refresh=true：执行主动探测 */

    /* 1. 从 hash table 查 SBH */
    char *sbh = sbhForUid(unitId);
    if (!sbh) {
        /* 单元未绑定：返回 Unknown 状态 */
        AgentStatusSnapshot snap;
        snap.unitId = unitId;
        snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
        snap.unitType = AgentContractUtil::unitTypeFromId(unitId);
        snap.bindingState = BindingState::Bound; /* 保持默认，调用方可覆写 */
        snap.connectionState = ConnectionState::Unknown;
        snap.statusFreshness = StatusFreshness::Unavailable;
        snap.lastError = QStringLiteral("unit not bound in hash table");
        /* 不更新缓存 */
        return snap;
    }

    /* 2. 执行探测 */
    AgentStatusSnapshot probed = executeProbe(unitId, sbh);

    /* 3. 合并目录信息（如果有 directory_ 且已查到） */
    if (directory_) {
        AgentLookupResult lr = directory_->findByUnitId(unitId);
        if (lr.found) {
            probed.alias = lr.alias;
            probed.displayName = lr.displayName;
            probed.bindingState = lr.bindingState;
            probed.bindingOrigin = lr.bindingOrigin;
            probed.mock = lr.mock;
            /* 如果探测结果类型为 Unknown，从查找结果补全 */
            if (probed.unitType == UnitType::Unknown)
                probed.unitType = lr.unitType;
        }
    }

    /* 4. 更新缓存 */
    if (probed.connectionState == ConnectionState::Online) {
        /* 探测成功：覆盖缓存 */
        cache_.insert(unitId, probed);
        probed.statusFreshness = StatusFreshness::Fresh;
        return probed;
    }

    /* 探测失败：尝试与旧缓存合并 */
    if (cache_.contains(unitId)) {
        AgentStatusSnapshot old = cache_.value(unitId);
        /* 保留旧的位姿/速度数据 */
        if (!probed.hasPose && old.hasPose) {
            probed.poseX = old.poseX;
            probed.poseY = old.poseY;
            probed.poseZ = old.poseZ;
            probed.poseYaw = old.poseYaw;
            probed.hasPose = true;
        }
        if (!probed.hasSpeed && old.hasSpeed) {
            probed.speedLinear = old.speedLinear;
            probed.speedAngular = old.speedAngular;
            probed.hasSpeed = true;
        }
        probed.lastSeenMs = old.lastSeenMs; /* 保持旧时间戳 */
        probed.statusFreshness = computeFreshness(old);
        return probed;
    }

    /* 无旧缓存 */
    probed.statusFreshness = StatusFreshness::Unavailable;
    return probed;
}

/* --------------------------------------------------------------------------
 * getAllStatus
 * -------------------------------------------------------------------------- */
QVector<AgentStatusSnapshot> AgentStatusService::getAllStatus() {
    QMutexLocker lock(&mutex_);

    QVector<AgentStatusSnapshot> result;

    if (directory_) {
        /* 从目录获取所有绑定 */
        const QVector<AgentLookupResult> bindings = directory_->listBindings();
        for (const AgentLookupResult &lr : bindings) {
            AgentStatusSnapshot snap;

            if (cache_.contains(lr.unitId)) {
                snap = cache_.value(lr.unitId);
            } else {
                snap.unitId = lr.unitId;
                snap.observedAtMs = QDateTime::currentMSecsSinceEpoch();
                snap.unitType = lr.unitType;
                snap.bindingState = lr.bindingState;
                snap.bindingOrigin = lr.bindingOrigin;
                snap.connectionState = ConnectionState::Unknown;
            }

            /* 从目录补全别名等元信息 */
            snap.alias = lr.alias;
            snap.displayName = lr.displayName;
            snap.mock = lr.mock;
            snap.statusFreshness = computeFreshness(snap);

            result.append(snap);
        }
    } else {
        /* 无目录引用：仅返回缓存中的条目 */
        for (auto it = cache_.cbegin(); it != cache_.cend(); ++it) {
            AgentStatusSnapshot snap = it.value();
            snap.statusFreshness = computeFreshness(snap);
            result.append(snap);
        }
    }

    return result;
}
