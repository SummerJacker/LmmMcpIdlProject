/**
 * @file AgentDirectory.h
 * @brief 智能体目录实现：绑定视图 + 别名管理，实现 IAgentDirectory 接口。
 *
 * 作为 Member 1 的核心交付件，集成 AgentNameNormalizer 和 AliasStore，
 * 向 HTTP 层及其他模块提供统一的名称解析与别名变更入口。
 *
 * 版本: 1.0
 */

#ifndef AGENT_DIRECTORY_H
#define AGENT_DIRECTORY_H

#include "agents/contracts/AgentContracts.h"

#include "AliasStore.h"

#include <QMap>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QVector>

class AgentDirectory : public IAgentDirectory {
public:
    /**
     * @brief 构造 AgentDirectory。
     * @param parent Qt 父对象（可选）。
     */
    explicit AgentDirectory(QObject *parent = nullptr);

    /**
     * @brief 初始化：加载 AliasStore。
     * @return true 表示加载成功。
     */
    bool initialize();

    // --- IAgentDirectory 实现 ---

    /** @brief 列出全部当前绑定（含别名信息） */
    QVector<AgentLookupResult> listBindings() const override;

    /** @brief 按 unit_id 精确查找 */
    AgentLookupResult findByUnitId(const QString &unitId) const override;

    /**
     * @brief 统一名称解析：unit_id → alias → not found。
     *
     * 解析顺序：
     *   1. unit_id 精确匹配（大小写敏感）。
     *   2. 别名匹配（case-folded 比较键）。
     *   3. 返回 not found。
     */
    AgentLookupResult resolveName(const QString &name) const override;

    /**
     * @brief 设置或更新别名。
     *
     * 执行流程：
     *   1. 校验 unit_id 当前已绑定。
     *   2. 规范化别名（AgentNameNormalizer）。
     *   3. 冲突检测：不能与任何 unit_id（case-folded）、已有别名（case-folded）、保留名称（case-folded）冲突。
     *   4. 写入 AliasStore 并立即持久化。
     *
     * @param unitId 目标智能体 UID
     * @param alias 新别名（空字符串无效）
     * @param reservedNames 额外保留名称列表
     */
    AliasMutationResult setAlias(const QString &unitId, const QString &alias,
                                 const QStringList &reservedNames) override;

    /**
     * @brief 清除别名。
     *
     * 允许对已解绑但仍有持久化记录的 unit_id 执行清除。
     * @param unitId 目标智能体 UID
     */
    AliasMutationResult clearAlias(const QString &unitId) override;

    /** @brief 全量替换绑定视图（启动恢复时使用） */
    void replaceBindings(const QVector<AgentLookupResult> &bindings) override;

    /** @brief 插入或更新单条绑定 */
    void upsertBinding(const AgentLookupResult &binding) override;

    /** @brief 移除单条绑定（unbind） */
    void removeBinding(const QString &unitId) override;

    /** @brief 获取所有已知别名（含持久化记录） */
    QStringList allKnownAliases() const override;

    /** @brief 获取所有已知 unit_id（含持久化记录） */
    QStringList allKnownUnitIds() const override;

    /** @brief 获取底层 AliasStore 引用（供 HttpApiExecutor 等使用） */
    AliasStore *aliasStore() { return &aliasStore_; }

private:
    mutable QMutex mutex_;
    QMap<QString, AgentLookupResult> bindings_; /**< key: unit_id */
    AliasStore aliasStore_;

    /** @brief 内部 setAlias 实现（调用者已持有锁） */
    AliasMutationResult internalSetAlias(const QString &unitId, const QString &alias,
                                         const QStringList &reservedNames);

    /** @brief 内部 clearAlias 实现（调用者已持有锁） */
    AliasMutationResult internalClearAlias(const QString &unitId);

    /**
     * @brief 检查比较键是否与保留名称冲突。
     * @param comparisonKey 已 case-folded 的比较键
     * @param reservedNames 额外保留名称列表
     * @return true 表示被保留（冲突）
     */
    bool isNameReserved(const QString &comparisonKey, const QStringList &reservedNames) const;

    /**
     * @brief 将名称解析为 unit_id。
     * @param name 输入名称
     * @return 对应的 unit_id 或空字符串（未找到）
     */
    QString resolveToUnitId(const QString &name) const;
};

#endif // AGENT_DIRECTORY_H
