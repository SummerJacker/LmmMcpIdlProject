# Implementation Plan: Vehicle Formation System Improvements

## Overview

本实现计划将设计文档中的技术方案转化为可执行的编码任务，按三条主线组织：
1. **算法层** - 校验、拆分、归一化等核心算法
2. **下发层** - setGroupMode/setFormation职责分离与下发路径
3. **观测层** - 日志、结果汇总与UI反馈

## Tasks

- [x] 1. 数据结构与辅助函数
  - [x] 1.1 定义 FormationResult/GroupResult/UnitResult 结构体
    - 在 `console.h` 中添加结构体定义
    - 包含 success、errorCode、errorMsg、isOrphan 字段
    - _Requirements: 10.2, 10.4_
  - [x] 1.2 定义日志宏 LOG_INFO/LOG_WARN/LOG_ERROR
    - 在 `console.h` 中添加宏定义
    - 格式：`[级别] [模块] 消息`
    - _Requirements: 9.6_
  - [x] 1.3 添加 formatSeq 辅助函数
    - 将 UnitIDSeq/ShortSeq 格式化为可读字符串用于日志
    - _Requirements: 9.1_

- [x] 2. 核心算法实现
  - [x] 2.1 实现 validateFormation() 校验函数
    - 检查 formation 非空、长度一致性
    - 检查 leader_ids 索引有效性
    - _Requirements: 1.5, 5.4_
  - [x] 2.2 编写 validateFormation 属性测试
    - **Property 2: leader_ids索引有效性**
    - **Validates: Requirements 1.5, 5.4**
  - [x] 2.3 实现 detectCrossTypeEdges() 跨类型边检测
    - 遍历 leader_ids，检测 A→G 或 G→A 边
    - 返回跨类型边列表
    - _Requirements: 6.1_
  - [x] 2.4 编写 detectCrossTypeEdges 属性测试
    - **Property 5: 跨类型边降级处理**
    - **Validates: Requirements 6.1, 6.4**
  - [x] 2.5 实现 splitFormation() 拆分函数
    - 按单元类型拆分为空中组和地面组
    - 重映射 leader_ids 索引
    - 跨类型边降级为独立节点
    - _Requirements: 6.2, 6.4_
  - [x] 2.6 编写 splitFormation 属性测试
    - **Property 6: 拆分后索引重映射正确性**
    - **Validates: Requirements 6.4**
  - [x] 2.7 实现 normalizeTopology() 归一化函数
    - 检测星形拓扑（多节点指向同一leader）
    - 按录入顺序转换为链式拓扑
    - 空中组跳过归一化（固定STAR）
    - _Requirements: 1.2, 1.4_
  - [x] 2.8 编写 normalizeTopology 属性测试
    - **Property 1: 链式拓扑归一化正确性**
    - **Validates: Requirements 1.2, 1.4**

- [x] 3. Checkpoint - 算法层验证
  - 确保所有算法函数单元测试通过
  - 确保属性测试通过（如已实现）
  - 如有问题请询问用户

- [x] 4. setGroupMode 重构
  - [x] 4.1 移除空中单元过滤逻辑
    - 删除 `if(((char*)uid)[0] != 'G') continue;`
    - _Requirements: 3.4_
  - [x] 4.2 添加空中单元处理分支
    - 使用 Air_Unit_rpc 类型进行 RPC 调用
    - 设置 Role/Mode/MinorMode
    - _Requirements: 3.1, 3.2, 3.3_
  - [x] 4.3 移除 setRearVehicles 调用
    - 删除 setGroupMode 中的 setRearVehicles 相关代码
    - 职责转移到 setFormation
    - _Requirements: 2.1, 2.4_
  - [x] 4.4 添加日志输出
    - 记录每个单元的 role/mode/minorMode 设置结果
    - _Requirements: 9.4_
  - [x] 4.5 编写 setGroupMode 职责分离测试
    - **Property 3: 职责分离不变量**
    - **Validates: Requirements 2.1, 2.4**

- [x] 5. setFormation 重构
  - [x] 5.1 重构 setFormation 主流程
    - 调用 validateFormation → detectCrossTypeEdges → splitFormation → normalizeTopology
    - 添加入口日志（完整输入参数）
    - _Requirements: 2.5, 9.1_
  - [x] 5.2 实现 _setGroundFormation() 地面下发
    - 遍历地面组，为每个单元调用 setRearVehicles
    - 使用每个单元独立的 distance/angle 参数
    - 收集每个单元的成功/失败结果
    - _Requirements: 7.1, 7.2, 7.3, 10.1_
  - [x] 5.3 编写参数独立性属性测试
    - **Property 7: 参数独立性**
    - **Validates: Requirements 7.1, 7.2, 7.3**
  - [x] 5.4 修改 _setAirSwarmFormation() 空中下发
    - 确保不调用 setRearVehicles
    - 收集每个单元的成功/失败结果
    - _Requirements: 4.1, 4.2, 4.3_
  - [x] 5.5 编写空中编队接口约束测试
    - **Property 4: 空中编队接口约束**
    - **Validates: Requirements 4.1, 4.2, 4.3**
  - [x] 5.6 实现结果汇总逻辑
    - 合并空中组和地面组结果
    - 计算 successCount/failCount
    - 处理空组情况（默认成功）
    - _Requirements: 10.2, 10.4_
  - [x] 5.7 编写部分成功处理属性测试
    - **Property 8: 部分成功处理**
    - **Validates: Requirements 10.1, 10.2, 10.4**
  - [x] 5.8 添加流程结束日志
    - 记录总体结果、成功/失败数、耗时
    - _Requirements: 9.5_

- [x] 6. Checkpoint - 下发层验证
  - 确保 setGroupMode 不再调用 setRearVehicles
  - 确保空中单元能正确设置 Follow 模式
  - 确保 setFormation 完整流程可执行
  - 如有问题请询问用户

- [x] 7. UI层修改
  - [x] 7.1 修改录入逻辑为链式拓扑
    - 修改 `on_pushButton_19_clicked()` 中 leader_ids 赋值
    - 新 Follower 的 leader_ids 设为 currentUnitCount-1
    - _Requirements: 1.1_
  - [x] 7.2 修改发送队形按钮处理
    - 使用 FormationResult 处理返回值
    - 显示部分成功/失败详情
    - _Requirements: 10.2, 10.4_
  - [x] 7.3 添加跨类型边警告显示
    - 在 UI 上显示跨类型边降级警告
    - _Requirements: 6.1_

- [x] 8. 集成测试
  - [x] 8.1 TC-1: 链式拓扑转换测试
    - 输入星形拓扑，验证输出为链式
    - 验证日志包含归一化记录
    - _Requirements: 1.2, 1.4, 1.6_
  - [x] 8.2 TC-2: 空中编队下发测试
    - 输入纯空中编队，验证走空中下发路径
    - 验证 setRearVehicles 不被调用
    - _Requirements: 4.1, 4.2, 4.3_
  - [x] 8.3 TC-3: 混合编队拆分测试
    - 输入混合编队，验证正确拆分
    - 验证 leader_ids 重映射正确
    - _Requirements: 5.1, 6.2, 6.4_
  - [x] 8.4 TC-4: 跨类型边降级测试
    - 输入包含跨类型边的编队
    - 验证警告日志输出
    - 验证跨类型边被忽略
    - _Requirements: 6.1, 6.4_
  - [x] 8.5 TC-5: 部分成功处理测试
    - 模拟部分单元 RPC 失败
    - 验证其他单元继续处理
    - 验证结果报告正确
    - _Requirements: 10.1, 10.2, 10.4_
  - [x] 8.6 TC-6: 参数独立生效测试
    - 输入不同 distance/angle 的编队
    - 验证每个单元使用独立参数
    - _Requirements: 7.1, 7.2, 7.3, 7.5_

- [x] 9. Final Checkpoint - 全部验证
  - [x] 确保所有单元测试通过 ✓ (34 tests passed)
  - [x] 确保所有属性测试通过 ✓ (8 properties verified)
  - [x] 确保所有集成测试通过 ✓ (TC1-TC6 passed)
  - 测试执行时间: 167ms

## Notes

- All tasks are required for comprehensive testing
- Each task references specific requirements for traceability
- Checkpoints ensure incremental validation
- Property tests validate universal correctness properties
- Unit tests validate specific examples and edge cases
