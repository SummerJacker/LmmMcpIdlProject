# Requirements Document

## Introduction

本文档定义了车辆编队控制系统的编队跟随功能改进需求，旨在解决当前地面单位编队相撞、空中单位跟随模式失效的问题，并为未来空地联合跟随奠定架构基础。

## Glossary

- **Console**: 控制台，负责管理所有单元的注册、角色分配、编队指令下发
- **Leader**: 领航者，编队中的领头单元，其他单元跟随其运动
- **Follower**: 跟随者，跟随Leader或其他Follower运动的单元
- **Formation**: 队形数据结构，包含robot_ids、leader_ids、distances、angles
- **GUV (Ground Unit Vehicle)**: 地面单元/无人车，ID前缀为"GV"
- **AUV (Air Unit Vehicle)**: 空中单元/无人机，ID前缀为"AV"
- **Chain_Topology**: 链式拓扑，每个Follower跟随前一个单元，形成链条
- **Star_Topology**: 星形拓扑，所有Follower直接跟随Leader（当前实现，导致相撞）
- **Cross_Type_Edge**: 跨类型边，指A→G或G→A的跟随关系
- **leader_ids**: 索引数组，leader_ids[i]表示robot_ids[i]跟随robot_ids[leader_ids[i]]，值为数组索引（非UID）
- **Normalization**: 归一化，将星形拓扑转换为链式拓扑的过程
- **setRearVehicles**: 地面单元设置后车列表的RPC接口
- **setFormation**: 设置编队参数的RPC接口
- **sendControlledVehicle**: 空中单元设置受控无人机列表的RPC接口

## Requirements

### Requirement 1: 链式拓扑生成

**User Story:** As a 控制台操作员, I want 编队拓扑自动生成为链式结构, so that 多个地面Follower不会追同一个目标点导致相撞。

#### Acceptance Criteria

1. WHEN 用户在UI录入Follower到formation时, THE Formation_Builder SHALL 将新Follower的leader_ids设置为上一个被录入单元的索引（而非固定为0）
2. WHEN formation中存在多个Follower直连同一个Leader时, THE Console SHALL 在下发前自动将这些Follower串成链式拓扑
3. WHEN 链式拓扑生成完成后, THE Console SHALL 确保每个单元最多只有一个直接后车（除非显式配置为树形）
4. IF formation数据中leader_ids全为0（星形拓扑）, THEN THE Console SHALL 按录入顺序自动转换为链式拓扑
5. THE leader_ids数组 SHALL 使用数组索引（0-based）而非UID字符串作为值
6. WHEN 拓扑转换完成后, THE Console SHALL 输出日志记录原始拓扑和转换后拓扑的对比

### Requirement 2: 编队下发职责分离

**User Story:** As a 系统架构师, I want setGroupMode和setFormation职责明确分离, so that 编队参数不会被两套逻辑覆盖导致状态不同步。

#### Acceptance Criteria

1. THE setGroupMode函数 SHALL 仅负责设置单元的角色(Leader/Follower)、模式(Mode)和次级模式(MinorMode)
2. THE setFormation函数 SHALL 仅负责下发队形拓扑与参数（rear列表、distance、angle）
3. WHEN setGroupMode成功切换到Follow模式且formation不为空时, THE Console SHALL 统一调用setFormation进行队形下发
4. THE Console SHALL NOT 在setGroupMode中直接调用setRearVehicles进行队形配置
5. THE setFormation函数 SHALL 在下发前强制执行拓扑归一化（normalizeTopology）
6. WHEN setFormation被调用时, THE Console SHALL 记录完整的下发参数日志（包括每个单元的leader_id、distance、angle）

### Requirement 3: 空中单位跟随模式支持

**User Story:** As a 无人机操作员, I want 空中单位能够进入跟随模式, so that 无人机编队能够正常工作。

#### Acceptance Criteria

1. WHEN setGroupMode遍历Units_Hash_Table时, THE Console SHALL 同时处理地面单元(GV)和空中单元(AV)
2. WHEN 处理空中单元时, THE Console SHALL 使用Air_Unit_rpc类型进行RPC调用
3. WHEN 空中单元设置Follow模式时, THE Console SHALL 设置MinorMode为UMM_FW_Object
4. THE Console SHALL NOT 在遍历时过滤掉空中单元(uid[0]=='A')
5. WHEN 空中单元模式设置完成时, THE Console SHALL 输出日志确认设置结果（成功/失败及错误码）

### Requirement 4: 空中编队下发路径

**User Story:** As a 无人机操作员, I want 空中编队通过正确的接口下发, so that 无人机能够接收并执行编队指令。

#### Acceptance Criteria

1. WHEN 下发空中编队时, THE Console SHALL 调用sendControlledVehicle将Follower的SBH列表发给Leader
2. WHEN 下发空中编队时, THE Console SHALL 调用Leader的setFormation下发dist/angle参数
3. THE Console SHALL NOT 对空中单元调用setRearVehicles（该接口空中端未实现）
4. WHEN setFormation检测到formation首个单元为空中单元(AV)时, THE Console SHALL 自动走空中编队下发流程
5. WHEN 空中编队下发完成时, THE Console SHALL 返回明确的成功/失败状态及失败原因

### Requirement 5: 混合编队数据结构支持

**User Story:** As a 系统架构师, I want formation数据结构支持空地混合编队, so that 未来能够实现空地联合跟随。

#### Acceptance Criteria

1. THE Formation数据结构 SHALL 支持robot_ids同时包含AV和GV单元
2. THE Formation数据结构 SHALL 支持leader_ids指向不同类型的单元
3. WHEN formation包含混合单元时, THE Console SHALL 能够正确解析并区分空中和地面单元
4. THE leader_ids语义 SHALL 明确定义为：leader_ids[i]是robot_ids数组的索引，表示robot_ids[i]跟随robot_ids[leader_ids[i]]

### Requirement 6: 编队下发前校验与拆分

**User Story:** As a 控制台操作员, I want 控制台在下发混合编队前进行可执行性校验, so that 不支持的跨类型跟随能够被明确提示。

#### Acceptance Criteria

1. WHEN formation包含跨类型边(A→G或G→A)时, THE Console SHALL 采用"降级策略"：忽略跨类型边并在UI上显示警告"检测到跨类型边[X→Y]，已自动忽略"
2. WHEN formation包含混合单元但无跨类型边时, THE Console SHALL 自动拆分为空中组和地面组分别下发
3. WHEN 拆分下发时, THE Console SHALL 对空中组调用空中编队流程，对地面组调用地面编队流程
4. WHEN 拆分发生时, THE Console SHALL 重新映射leader_ids索引以匹配拆分后的子数组
5. IF 拆分后某组只有Leader无Follower, THEN THE Console SHALL 跳过该组下发并记录日志
6. WHEN 部分组下发成功部分失败时, THE Console SHALL 返回详细状态报告（每组的成功/失败状态）

### Requirement 7: 队形参数按节点生效

**User Story:** As a 控制台操作员, I want 每个Follower的distance和angle参数独立生效, so that 编队间隔能够按我的输入精确控制。

#### Acceptance Criteria

1. WHEN 下发队形时, THE Console SHALL 为每个Follower使用其在formation中对应的distance值
2. WHEN 下发队形时, THE Console SHALL 为每个Follower使用其在formation中对应的angle值
3. THE Console SHALL NOT 使用"第一个Follower的参数作为全体参数"的简化逻辑
4. WHEN 某Follower的distance/angle未设置时, THE Console SHALL 使用默认值(distance=0.5m, angle=0.0)
5. WHEN 下发完成时, THE Console SHALL 输出每个Follower实际使用的distance/angle值日志

### Requirement 8: 拓扑策略可配置

**User Story:** As a 高级用户, I want 能够选择不同的编队拓扑策略, so that 我可以根据场景选择最合适的编队方式。

#### Acceptance Criteria

1. THE Console SHALL 支持至少两种拓扑策略：链式(Chain)和星形(Star)
2. WHEN 用户选择链式策略时, THE Console SHALL 在下发前将formation转换为链式拓扑
3. WHEN 用户选择星形策略时, THE Console SHALL 保持原始leader_ids不变（需用户自行承担碰撞风险）
4. THE Console SHALL 默认使用链式策略以保证安全性
5. WHERE 拓扑策略配置存在, THE Console SHALL 在setFormation调用前应用该策略

### Requirement 9: 可观测性与日志

**User Story:** As a 系统运维人员, I want 编队下发过程有完整的日志记录, so that 我可以追踪问题和调试。

#### Acceptance Criteria

1. WHEN setFormation被调用时, THE Console SHALL 记录：输入formation的完整内容（robot_ids、leader_ids、distances、angles）
2. WHEN 拓扑归一化执行时, THE Console SHALL 记录：归一化前后的leader_ids对比
3. WHEN 混合编队拆分时, THE Console SHALL 记录：拆分后的空中组和地面组内容
4. WHEN RPC调用执行时, THE Console SHALL 记录：目标单元UID、调用接口名、参数、返回值/错误码
5. WHEN 下发流程结束时, THE Console SHALL 记录：总体结果（成功/部分成功/失败）及耗时
6. THE 日志格式 SHALL 包含时间戳、日志级别、模块名、消息内容

### Requirement 10: 错误处理与部分成功

**User Story:** As a 控制台操作员, I want 编队下发支持部分成功处理, so that 单个单元失败不会导致整个编队下发失败。

#### Acceptance Criteria

1. WHEN 某个单元的RPC调用失败时, THE Console SHALL 记录错误并继续处理其他单元
2. WHEN 下发完成时, THE Console SHALL 返回详细结果：成功单元列表、失败单元列表及失败原因
3. IF 所有单元都失败, THEN THE Console SHALL 返回整体失败状态
4. IF 部分单元成功部分失败, THEN THE Console SHALL 返回部分成功状态并列出失败单元
5. THE Console SHALL 提供重试机制：允许用户对失败单元单独重试

## Test Cases

### TC-1: 链式拓扑转换测试
- **输入**: formation = {robot_ids: [GV1, GV2, GV3], leader_ids: [0, 0, 0], distances: [0, 0.5, 0.5], angles: [0, 0, 0]}
- **预期输出**: leader_ids转换为[0, 0, 1]（GV2跟GV1，GV3跟GV2）
- **验证点**: 链式拓扑正确生成，日志记录转换过程

### TC-2: 空中编队下发测试
- **输入**: formation = {robot_ids: [AV1, AV2, AV3], leader_ids: [0, 0, 0], distances: [0, 1.0, 1.5], angles: [0, 0, 0]}
- **预期输出**: sendControlledVehicle被调用，setFormation被调用，setRearVehicles不被调用
- **验证点**: 空中编队走正确的下发路径

### TC-3: 混合编队拆分测试
- **输入**: formation = {robot_ids: [GV1, GV2, AV1, AV2], leader_ids: [0, 0, 0, 2], distances: [0, 0.5, 0, 1.0], angles: [0, 0, 0, 0]}
- **预期输出**: 拆分为地面组{GV1, GV2}和空中组{AV1, AV2}，leader_ids重新映射
- **验证点**: 拆分正确，索引重映射正确

### TC-4: 跨类型边降级测试
- **输入**: formation = {robot_ids: [GV1, AV1], leader_ids: [0, 0], distances: [0, 0.5], angles: [0, 0]}
- **预期输出**: 警告"检测到跨类型边[AV1→GV1]，已自动忽略"，AV1作为独立Leader处理
- **验证点**: 跨类型边被正确检测和降级处理

### TC-5: 部分成功处理测试
- **输入**: formation包含3个单元，其中1个单元RPC调用失败
- **预期输出**: 返回部分成功状态，列出成功和失败的单元
- **验证点**: 错误不会中断整体流程，结果报告完整

### TC-6: 参数独立生效测试
- **输入**: formation = {robot_ids: [GV1, GV2, GV3], leader_ids: [0, 0, 1], distances: [0, 0.5, 1.0], angles: [0, 30, 45]}
- **预期输出**: GV2使用distance=0.5/angle=30，GV3使用distance=1.0/angle=45
- **验证点**: 每个Follower使用独立参数，非统一参数
