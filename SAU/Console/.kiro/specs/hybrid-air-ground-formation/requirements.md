# 需求文档：混合空地编队

## 简介

本功能实现混合空地编队控制，允许空中单元（UAV）作为整个编队的领航者，地面单元（UGV）的第一辆车跟随空中单元，其余地面单元以链式模式依次跟随第一辆地面车。这种编队模式适用于需要空中引导的地面车队场景，例如侦察任务、路径探索等。

## 术语表

- **System**: 混合空地编队控制系统
- **Air_Leader**: 空中领航单元，作为整个编队的领导者
- **Ground_First**: 第一辆地面单元，直接跟随空中领航单元
- **Ground_Follower**: 其余地面单元，以链式模式跟随
- **Formation**: 编队配置，包含单元ID、距离和角度参数
- **Chain_Topology**: 链式拓扑结构，每个单元只跟随一个前车
- **Cross_Type_Edge**: 跨类型边，连接不同类型单元（空中-地面）的边

## 需求

### 需求 1：空中单元作为领航者

**用户故事：** 作为操作员，我希望能够选择一个空中单元作为整个编队的领航者，以便从空中引导地面车队。

#### 验收标准

1. WHEN 用户选择一个空中单元并调用 setToLeader 时，THE System SHALL 将该空中单元设置为 Air_Leader 角色
2. WHEN Air_Leader 被设置后，THE System SHALL 记录 Air_Leader 的 UID 和 SBH
3. WHEN Air_Leader 被设置后，THE System SHALL 将 currentAUVLeaderObj 指向该空中单元对象
4. IF 已存在其他 Leader（地面或空中），THEN THE System SHALL 先清除旧 Leader 信息再设置新 Leader
5. WHEN Air_Leader 设置成功后，THE System SHALL 将 Leader 信息备份到本地文件

### 需求 2：第一辆地面车跟随空中领航者

**用户故事：** 作为操作员，我希望第一辆地面车能够直接跟随空中领航者，以便建立空地连接。

#### 验收标准

1. WHEN 编队配置中第一个地面单元的 leader_id 指向 Air_Leader 时，THE System SHALL 接受此跨类型连接
2. WHEN 设置 Ground_First 的跟随关系时，THE System SHALL 调用 setALeader 将 Air_Leader 的 SBH 传递给 Ground_First
3. WHEN Ground_First 设置 Leader 后，THE System SHALL 设置 Ground_First 的模式为 Follow
4. WHEN Ground_First 设置 Leader 后，THE System SHALL 设置 Ground_First 的次级模式为 FW_Object
5. THE System SHALL 使用编队配置中指定的距离和角度参数设置 Ground_First 与 Air_Leader 的相对位置

### 需求 3：其余地面车链式跟随

**用户故事：** 作为操作员，我希望其余地面车以链式模式依次跟随，以便形成有序的地面车队。

#### 验收标准

1. WHEN 编队配置中包含多个地面单元时，THE System SHALL 将第二辆及之后的地面单元设置为跟随前一辆地面单元
2. WHEN 设置地面单元的跟随关系时，THE System SHALL 确保每个 Ground_Follower 只跟随一个前车（链式拓扑）
3. WHEN 设置地面单元的跟随关系时，THE System SHALL 调用 setRearVehicles 为每个地面单元配置其后车列表
4. THE System SHALL 使用编队配置中每个单元独立的距离和角度参数
5. WHEN 地面单元的距离参数小于最小安全间隔（0.5米）时，THE System SHALL 自动调整为最小安全间隔

### 需求 4：编队配置验证

**用户故事：** 作为操作员，我希望系统能够验证编队配置的有效性，以便避免无效配置导致的错误。

#### 验收标准

1. WHEN 用户提交编队配置时，THE System SHALL 验证 Formation 数据结构的完整性
2. WHEN 验证编队配置时，THE System SHALL 检查 robot_ids、leader_ids、distances 和 angles 序列的长度一致性
3. WHEN 验证编队配置时，THE System SHALL 检查所有 leader_id 索引的有效性（在有效范围内）
4. IF 编队配置无效，THEN THE System SHALL 返回错误码 FE_INVALID_INPUT 并记录错误信息
5. WHEN 编队配置有效时，THE System SHALL 继续执行编队设置流程

### 需求 5：跨类型边检测

**用户故事：** 作为操作员，我希望系统能够检测编队中的跨类型边，以便了解空地连接情况。

#### 验收标准

1. WHEN 系统处理编队配置时，THE System SHALL 检测所有跨类型边（空中单元 → 地面单元 或 地面单元 → 空中单元）
2. WHEN 检测到跨类型边时，THE System SHALL 记录源节点和目标节点的索引及 UID
3. WHEN 检测到跨类型边时，THE System SHALL 将跨类型边信息添加到警告列表
4. WHEN 跨类型边为 Air_Leader → Ground_First 时，THE System SHALL 允许此连接（合法的空地连接）
5. WHEN 跨类型边为其他类型（如 Ground → Air 或非第一辆车的 Air → Ground）时，THE System SHALL 记录警告但不阻止执行

### 需求 6：编队拆分

**用户故事：** 作为系统，我需要将混合编队拆分为空中组和地面组，以便分别处理不同类型的单元。

#### 验收标准

1. WHEN 系统处理混合编队时，THE System SHALL 将编队拆分为空中组和地面组
2. WHEN 拆分编队时，THE System SHALL 根据 UID 的首字符（'A' 或 'G'）判断单元类型
3. WHEN 拆分编队时，THE System SHALL 为每个组重新构建 robot_ids、leader_ids、distances 和 angles 序列
4. WHEN 拆分编队时，THE System SHALL 调整 leader_ids 索引以匹配新的组内索引
5. WHEN 拆分完成后，THE System SHALL 返回包含空中组、地面组和跨类型边警告的拆分结果

### 需求 7：空中编队下发

**用户故事：** 作为系统，我需要将空中编队配置下发给空中领航者，以便空中单元执行编队任务。

#### 验收标准

1. WHEN 空中组包含单元时，THE System SHALL 调用 Air_Leader 的 setFormation 方法
2. WHEN 下发空中编队时，THE System SHALL 传递空中组的 Formation 数据（仅包含空中单元）
3. IF Air_Leader 对象为 NULL，THEN THE System SHALL 返回错误并记录日志
4. WHEN 空中编队下发成功时，THE System SHALL 记录成功日志
5. WHEN 空中编队下发失败时，THE System SHALL 记录错误日志并返回失败结果

### 需求 8：地面编队下发

**用户故事：** 作为系统，我需要将地面编队配置下发给所有地面单元，以便地面单元执行编队任务。

#### 验收标准

1. WHEN 地面组包含单元时，THE System SHALL 遍历所有地面单元并调用 setRearVehicles
2. WHEN 下发地面编队时，THE System SHALL 为每个地面单元构建其后车列表
3. WHEN 下发地面编队时，THE System SHALL 使用每个单元独立的距离和角度参数
4. WHEN 地面单元处于非 Follow 模式时，THE System SHALL 先设置模式为 Follow 再重试 setRearVehicles
5. WHEN 所有地面单元下发完成后，THE System SHALL 统计成功和失败数量并记录日志

### 需求 9：日志记录

**用户故事：** 作为开发者，我希望系统能够记录详细的操作日志，以便调试和监控编队设置过程。

#### 验收标准

1. WHEN 系统执行关键操作时，THE System SHALL 使用结构化日志宏（LOG_INFO、LOG_WARN、LOG_ERROR）记录日志
2. WHEN 记录日志时，THE System SHALL 包含时间戳、日志级别和模块名称
3. WHEN 记录日志时，THE System SHALL 使用 QString 格式化消息以支持中文
4. WHEN 编队设置开始时，THE System SHALL 记录编队配置的基本信息（单元数量、拓扑策略等）
5. WHEN 编队设置完成时，THE System SHALL 记录总耗时、成功/失败统计和最终状态

### 需求 10：结果报告

**用户故事：** 作为操作员，我希望系统能够返回详细的编队设置结果，以便了解每个单元的执行状态。

#### 验收标准

1. WHEN 编队设置完成后，THE System SHALL 返回 FormationResult 结构
2. WHEN 返回结果时，THE System SHALL 包含空中组结果和地面组结果
3. WHEN 返回结果时，THE System SHALL 包含每个单元的成功/失败状态、错误码和错误消息
4. WHEN 返回结果时，THE System SHALL 包含跨类型边警告列表
5. WHEN 返回结果时，THE System SHALL 包含总耗时（毫秒）

### 需求 11：错误处理

**用户故事：** 作为操作员，我希望系统能够妥善处理错误情况，以便在出现问题时能够快速定位和恢复。

#### 验收标准

1. WHEN RPC 调用失败时，THE System SHALL 记录错误码和错误消息
2. WHEN 单元对象创建失败时，THE System SHALL 跳过该单元并继续处理其他单元
3. WHEN 部分单元失败时，THE System SHALL 返回部分成功状态（FE_PARTIAL_SUCCESS）
4. WHEN 所有单元失败时，THE System SHALL 返回全部失败状态（FE_ALL_FAILED）
5. WHEN 发生异常时，THE System SHALL 调用 ILU_C_EXCEPTION_FREE 释放异常资源

### 需求 12：兼容性

**用户故事：** 作为开发者，我希望新功能能够与现有代码兼容，以便不影响现有功能。

#### 验收标准

1. THE System SHALL 保留现有的 setFormation(Unit_Formation*) 接口用于向后兼容
2. THE System SHALL 提供新的 setFormationWithResult(Unit_Formation*) 接口返回详细结果
3. WHEN 使用旧接口时，THE System SHALL 在内部调用新接口并转换返回值为 bool
4. THE System SHALL 保留现有的 setToLeader() 和 setGroupMode() 接口
5. THE System SHALL 确保新功能不影响纯地面编队或纯空中编队的现有行为
