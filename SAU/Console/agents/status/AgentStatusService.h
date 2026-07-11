/**
 * @file AgentStatusService.h
 * @brief 智能体状态服务 —— 实现 IAgentStatusService 接口。
 *
 * 维护 QMap<QString, AgentStatusSnapshot> 内存缓存，提供 getStatus/getAllStatus。
 * 根据 SBH 前缀将探测分派到 MockStatusProbe / GroundStatusProbe / AirStatusProbe。
 * 线程安全：所有公开方法使用 QMutex 保护。
 */

#ifndef AGENT_STATUS_SERVICE_H
#define AGENT_STATUS_SERVICE_H

#include "agents/contracts/AgentContracts.h"

#include <QMutex>
#include <QMap>

class AgentStatusService : public IAgentStatusService {
public:
    AgentStatusService();
    ~AgentStatusService() override;

    /**
     * @brief 获取单个智能体状态（从缓存或主动探测）。
     *
     * 若 refresh=true 或缓存命中单位为 Unknown/Offline，则执行主动探测。
     * 探测成功更新缓存；探测失败保留旧缓存并设置 freshness 为 Stale/Unavailable。
     *
     * @param unitId 智能体 UID
     * @param refresh true 表示主动探测
     * @return 状态快照
     */
    AgentStatusSnapshot getStatus(const QString &unitId, bool refresh) override;

    /**
     * @brief 获取全部已绑定智能体的缓存状态。
     *
     * 根据 IAgentDirectory 列出所有绑定，返回每个 unit_id 的缓存状态（不主动探测）。
     * 若 directory_ 尚未设置，则遍历当前缓存中已有条目。
     *
     * @return 全部状态快照列表
     */
    QVector<AgentStatusSnapshot> getAllStatus() override;

    /** @brief 状态新鲜度阈值（毫秒），默认 3000 */
    qint64 freshnessThresholdMs() const override { return freshnessThresholdMs_; }

    /** @brief 更新 freshness 阈值 */
    void setFreshnessThresholdMs(qint64 ms);

    /** @brief 注入目录引用 */
    void setDirectory(IAgentDirectory *directory) override;

private:
    /**
     * @brief 计算 statusFreshness：年龄 <= 阈值 → Fresh；有数据 → Stale；否则 Unavailable
     */
    StatusFreshness computeFreshness(const AgentStatusSnapshot &snap) const;

    /**
     * @brief 根据 unit_id 和 SBH 选择适当的探测器并执行探测。
     *
     * 不直接修改缓存；调用方负责合并结果。
     */
    AgentStatusSnapshot executeProbe(const QString &unitId, const char *sbh) const;

    mutable QMutex mutex_;
    QMap<QString, AgentStatusSnapshot> cache_;
    IAgentDirectory *directory_ = nullptr;
    qint64 freshnessThresholdMs_ = 3000;
};

#endif // AGENT_STATUS_SERVICE_H
