# 实现计划：混合空地编队

## 概述

本实现计划将混合空地编队功能分解为一系列增量式的编码任务。每个任务都建立在前一个任务的基础上，确保代码始终处于可工作状态。

## 任务列表

- [x] 1. 实现编队配置验证函数
  - 实现 `validateFormation(const Unit_Formation* formation)` 函数
  - 验证 formation 不为 NULL
  - 验证 robot_ids 长度 > 0
  - 验证所有序列长度一致
  - 验证所有 leader_id 索引有效
  - 验证 Leader 的 leader_id 为 -1
  - _需求：4.1, 4.2, 4.3, 4.4, 4.5_

- [x] 1.1 编写属性测试：编队配置验证完整性
  - **属性 3：编队配置验证完整性**
  - **验证：需求 4.1, 4.2, 4.3**
  - 生成随机 Formation（有效和无效）
  - 验证 validateFormation 正确识别所有约束违反
  - 最小100次迭代

- [x] 2. 实现跨类型边检测函数
  - 实现 `detectCrossTypeEdges(const Unit_Formation* formation)` 函数
  - 遍历所有单元（从索引1开始）
  - 根据 UID 首字符判断单元类型
  - 检测类型不匹配的 Leader-Follower 关系
  - 构建 CrossTypeEdge 结构并添加到结果列表
  - _需求：5.1, 5.2, 5.3_

- [x] 2.1 编写属性测试：跨类型边检测完整性
  - **属性 7：跨类型边检测完整性**
  - **验证：需求 5.1, 5.2, 5.3**
  - 生成包含跨类型边的随机 Formation
  - 验证所有跨类型边都被检测到
  - 验证检测结果包含正确的索引和 UID
  - 最小100次迭代

- [x] 3. 实现编队拆分函数
  - 实现 `splitFormation(const Unit_Formation* formation)` 函数
  - 遍历所有单元，根据 UID 首字符分类
  - 构建索引映射（oldIndex → newIndex）
  - 为空中组和地面组分别构建新的序列
  - 调整 leader_ids 索引以匹配新的组内索引
  - 处理跨类型边：将源节点设置为独立节点（leader_id=-1）
  - 返回 SplitResult 包含两个组和警告列表
  - _需求：6.1, 6.2, 6.3, 6.4, 6.5_

- [x] 3.1 编写属性测试：拆分后单元数量守恒
  - **属性 8：拆分后单元数量守恒**
  - **验证：需求 6.3**
  - 生成随机混合 Formation
  - 验证拆分后单元总数等于原始总数
  - 最小100次迭代

- [x] 3.2 编写属性测试：拆分后索引映射正确性
  - **属性 9：拆分后索引映射正确性**
  - **验证：需求 6.4**
  - 生成随机混合 Formation
  - 验证拆分后每个组的 leader_ids 正确映射到组内索引
  - 验证不存在越界索引
  - 最小100次迭代

- [x] 4. 实现空中编队下发函数
  - 实现 `_setAirSwarmFormation(Unit_Formation* formation)` 函数
  - 检查 currentAUVLeaderObj 是否为 NULL
  - 如果为 NULL，返回错误结果并记录日志
  - 调用 `Air_Unit_rpc_setFormation(currentAUVLeaderObj, formation, &ev)`
  - 检查 RPC 调用结果
  - 构建 GroupResult 并记录成功/失败
  - 记录日志（INFO/ERROR）
  - _需求：7.1, 7.2, 7.3, 7.4, 7.5_

- [x] 4.1 编写单元测试：空中编队下发
  - 测试 currentAUVLeaderObj 为 NULL 的情况
  - 测试 RPC 调用成功的情况
  - 测试 RPC 调用失败的情况
  - 验证日志输出
  - _需求：7.3, 7.4, 7.5_

- [x] 5. 实现地面编队下发函数
  - 实现 `_setGroundFormation(Unit_Formation* formation)` 函数
  - 检查 currentGUVLeaderObj 是否为 NULL
  - 调用 Leader 的 `setFormation` 方法
  - 构建每个单元的后车列表（rearsMap）
  - 遍历所有地面单元
  - 为每个单元调用 `setRearVehicles`（使用独立的 distance/angle）
  - 如果失败，补模式（Follow + FW_Object）后重试
  - 应用最小安全间隔钳制（MIN_SAFE_DISTANCE）
  - 记录每个单元的成功/失败结果
  - 构建 GroupResult 并统计成功/失败数量
  - 记录日志（INFO/WARN/ERROR）
  - _需求：8.1, 8.2, 8.3, 8.4, 8.5, 3.5_

- [x] 5.1 编写属性测试：地面编队下发覆盖性
  - **属性 10：地面编队下发覆盖性**
  - **验证：需求 8.1, 8.2, 8.3**
  - 生成随机地面组 Formation
  - 验证所有单元（包括叶子节点）都被调用 setRearVehicles
  - 验证每个单元使用独立的 distance/angle 参数
  - 最小100次迭代

- [x] 5.2 编写属性测试：最小安全间隔保证
  - **属性 6：最小安全间隔保证**
  - **验证：需求 3.5**
  - 生成包含小距离值的随机 Formation
  - 验证所有 distance < MIN_SAFE_DISTANCE 的单元被自动调整
  - 最小100次迭代

- [x] 5.3 编写属性测试：地面编队重试机制
  - **属性 11：地面编队重试机制**
  - **验证：需求 8.4**
  - 模拟 setRearVehicles 首次失败
  - 验证系统先设置模式再重试
  - 验证重试后成功
  - 最小100次迭代

- [x] 6. 实现主编队设置函数
  - 实现 `setFormationWithResult(Unit_Formation* formation)` 函数
  - 启动计时器（QElapsedTimer）
  - 调用 validateFormation 验证配置
  - 如果无效，返回错误结果（FE_INVALID_INPUT）
  - 调用 detectCrossTypeEdges 检测跨类型边
  - 记录跨类型边警告日志
  - 调用 splitFormation 拆分编队
  - 记录拆分结果日志
  - 调用 normalizeTopology 归一化地面拓扑
  - 调用 _setAirSwarmFormation 下发空中编队
  - 调用 _setGroundFormation 下发地面编队
  - 汇总结果到 FormationResult
  - 记录总耗时和最终状态日志
  - 返回 FormationResult
  - _需求：9.4, 9.5, 10.1, 10.2, 10.3, 10.4, 10.5_

- [x] 6.1 编写属性测试：结果完整性
  - **属性 12：结果完整性**
  - **验证：需求 10.1, 10.2, 10.3, 10.4, 10.5**
  - 生成随机 Formation
  - 验证 FormationResult 包含所有必要字段
  - 验证每个单元都有对应的 UnitResult
  - 验证跨类型边警告列表正确
  - 验证总耗时 > 0
  - 最小100次迭代

- [x] 6.2 编写属性测试：错误传播隔离
  - **属性 13：错误传播隔离**
  - **验证：需求 11.2**
  - 生成随机 Formation
  - 模拟单个单元失败
  - 验证其他单元继续处理
  - 验证失败单元被正确记录
  - 最小100次迭代

0- [x] 6.3 编写属性测试：部分成功状态判断
  - **属性 14：部分成功状态判断**
  - **验证：需求 11.3**
  - 生成随机 Formation
  - 模拟部分单元成功、部分失败
  - 验证 isPartialSuccess() 返回 true
  - 验证 isSuccess() 返回 false
  - 最小100次迭代

- [x] 7. 实现向后兼容接口
  - 实现 `setFormation(Unit_Formation* formation)` 函数
  - 调用 `setFormationWithResult(formation)`
  - 将 FormationResult 转换为 bool
  - 如果 isSuccess() 或 isPartialSuccess()，返回 true
  - 否则返回 false
  - _需求：12.1, 12.3_

- [x] 7.1 编写属性测试：向后兼容性
  - **属性 15：向后兼容性**
  - **验证：需求 12.3**
  - 生成随机 Formation
  - 调用旧接口 setFormation
  - 验证返回值与 isSuccess() || isPartialSuccess() 一致
  - 最小100次迭代

- [x] 8. 更新 setToLeader 函数支持空中Leader
  - 修改 `setToLeader()` 函数
  - 检查 currentUID 的首字符判断单元类型
  - 如果是空中单元（'A'），设置 currentAUVLeaderObj
  - 如果是地面单元（'G'），设置 currentGUVLeaderObj
  - 清除旧 Leader 信息（无论类型）
  - 获取 CosNaming SBH 并创建 backupCosObj
  - 设置 currentLeaderUID
  - 备份 Leader 信息到文件
  - 遍历所有单元设置为 Follower
  - 记录日志
  - _需求：1.1, 1.2, 1.3, 1.4, 1.5_

- [x] 8.1 编写属性测试：空中Leader设置完整性
  - **属性 1：空中Leader设置完整性**
  - **验证：需求 1.1, 1.2, 1.3**
  - 生成随机空中单元
  - 调用 setToLeader
  - 验证 currentAUVLeaderObj 正确设置
  - 验证 currentLeaderUID 正确记录
  - 验证单元角色为 Leader
  - 最小100次迭代

- [x] 8.2 编写属性测试：Leader切换清理
  - **属性 2：Leader切换清理**
  - **验证：需求 1.4**
  - 先设置一个 Leader（地面或空中）
  - 再设置另一个 Leader
  - 验证旧 Leader 信息被完全清除
  - 最小100次迭代

- [x] 9. 更新 setGroupMode 函数支持空中单元
  - 修改 `setGroupMode(Unit_UnitMode mode)` 函数
  - 检查 currentGUVLeaderObj 或 currentAUVLeaderObj 是否为 NULL
  - 获取 Leader 的 SBH（根据类型）
  - 遍历所有单元（包括空中单元）
  - 为每个单元设置角色、Leader、模式和次级模式
  - 区分空中单元和地面单元的处理
  - 记录详细日志（每个单元的处理过程）
  - 统计成功/失败数量
  - 更新备份文件
  - _需求：2.3, 2.4_

- [x] 9.1 编写属性测试：第一辆地面车跟随配置
  - **属性 4：第一辆地面车跟随配置**
  - **验证：需求 2.1, 2.2, 2.3, 2.4**
  - 生成空中Leader + 地面Follower的配置
  - 调用 setGroupMode(Unit_UM_Follow)
  - 验证第一辆地面车的 Leader 设置正确
  - 验证模式为 Follow，次级模式为 FW_Object
  - 最小100次迭代

- [x] 10. 添加日志宏和辅助函数
  - 确保 LOG_INFO、LOG_WARN、LOG_ERROR 宏已定义
  - 实现 `formatUnitIDSeq(const Unit_UnitIDSeq* seq)` 辅助函数
  - 实现 `formatShortSeq(const Unit_ShortSeq* seq)` 辅助函数
  - 实现 `formatFloatSeq(const Unit_FloatSeq* seq)` 辅助函数
  - 这些函数用于格式化日志输出
  - _需求：9.1, 9.2, 9.3_

- [x] 11. 集成测试：纯地面编队
  - 创建包含3个地面单元的编队配置
  - 设置第一个为 Leader
  - 调用 setFormation
  - 验证所有单元成功配置
  - 验证无跨类型边警告
  - 验证返回结果正确
  - _需求：12.5_

- [x] 12. 集成测试：纯空中编队
  - 创建包含3个空中单元的编队配置
  - 设置第一个为 Leader
  - 调用 setFormation
  - 验证所有单元成功配置
  - 验证无跨类型边警告
  - 验证返回结果正确
  - _需求：12.5_

- [x] 13. 集成测试：混合空地编队
  - 创建包含1个空中单元和3个地面单元的编队配置
  - 设置空中单元为 Leader
  - 第一辆地面车跟随空中单元
  - 其余地面车链式跟随
  - 调用 setFormation
  - 验证所有单元成功配置
  - 验证跨类型边警告正确
  - 验证第一辆地面车跟随空中Leader
  - 验证其余地面车链式跟随
  - 验证返回结果正确
  - _需求：1.1, 2.1, 3.1, 5.4_

- [x] 14. 最终检查点
  - 确保所有测试通过
  - 确保日志输出清晰可读
  - 确保向后兼容性
  - 确保代码符合项目编码规范
  - 询问用户是否有问题

## 注意事项

- 每个任务都应该在完成后进行测试，确保功能正常
- 属性测试使用最小100次迭代以确保覆盖足够的输入空间
- 集成测试应该在真实或模拟的 CORBA 环境中运行
- 所有 RPC 调用失败后必须调用 `ILU_C_EXCEPTION_FREE(&ev)` 释放资源
- 日志应该使用 QString 格式化以支持中文字符
34