/**
 * @file AirStatusProbe.h
 * @brief 真实空中单元 RPC 状态探测器。
 *
 * 仅处理 unit_id 以 'A' 开头且 SBH 非 "MOCK:" 前缀的单元。
 * 通过 ILU synchronous RPC 调用 getCurrentPose / getCurrentInfo。
 * 与 GroundStatusProbe 逻辑对称，但使用 Air_Unit_rpc 代理并包含 pose.z 字段。
 */

#ifndef AIR_STATUS_PROBE_H
#define AIR_STATUS_PROBE_H

#include "agents/contracts/AgentContracts.h"

/**
 * @brief 执行一次空中单元 ILU RPC 状态探测。
 *
 * - 若 SAU_ENABLE_REAL_RPC != 1：connection_state = Unknown
 * - 若 ILU 调用全部成功：connection_state = Online，填充 pose(含z)/speed/role
 * - 若任一 ILU 调用失败：connection_state = Offline，设置 lastError
 *
 * @param unitId  规范 unit_id（如 AV1）
 * @param sbh     已从 Units_Hash_Table 查出的 SBH 字符串（调用方保证非空）
 * @return 本次探测产生的状态快照
 */
AgentStatusSnapshot AirStatusProbe_probe(const QString &unitId, const char *sbh);

#endif // AIR_STATUS_PROBE_H
