/**
 * @file MockStatusProbe.h
 * @brief 模拟单元状态探测器 —— 读取 MockRobotSimulator 内存状态。
 *
 * 仅处理 SBH 以 "MOCK:" 开头的单元，不涉及任何 ILU RPC。
 */

#ifndef MOCK_STATUS_PROBE_H
#define MOCK_STATUS_PROBE_H

#include "agents/contracts/AgentContracts.h"

/**
 * @brief 从 MockRobotSimulator 获取指定 unit_id 的 AgentStatusSnapshot。
 *
 * 调用方负责保证该 unit_id 的 SBH 以 "MOCK:" 开头。
 * 线程安全：MockRobotSimulator 内部使用 QMutex 保护。
 */
AgentStatusSnapshot MockStatusProbe_probe(const QString &unitId);

#endif // MOCK_STATUS_PROBE_H
