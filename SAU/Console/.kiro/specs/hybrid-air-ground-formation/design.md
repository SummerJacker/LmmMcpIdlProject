# 设计文档：混合空地编队

## 概述

本设计实现混合空地编队控制功能，允许空中单元（UAV）作为整个编队的领航者，第一辆地面单元（UGV）直接跟随空中领航者，其余地面单元以链式模式依次跟随。

### 设计目标

1. 支持空中单元作为整个编队的Leader
2. 支持第一辆地面车跟随空中Leader（跨类型连接）
3. 支持其余地面车以链式拓扑跟随
4. 保持与现有代码的兼容性
5. 提供详细的执行结果和日志

### 设计原则

1. **最小侵入性** - 尽量复用现有函数和数据结构
2. **清晰的职责分离** - 空中编队和地面编队分别处理
3. **健壮的错误处理** - 部分失败不影响其他单元
4. **详细的日志记录** - 便于调试和监控

## 架构

### 整体流程

```
用户调用 setFormationWithResult(formation)
    ↓
1. 验证编队配置 (validateFormation)
    ↓
2. 检测跨类型边 (detectCrossTypeEdges)
    ↓
3. 拆分编队 (splitFormation)
    ↓
4. 归一化地面拓扑 (normalizeTopology)
    ↓
5. 下发空中编队 (_setAirSwarmFormation)
    ↓
6. 下发地面编队 (_setGroundFormation)
    ↓
7. 汇总结果并返回
```

### 模块划分

1. **验证模块** - validateFormation()
2. **检测模块** - detectCrossTypeEdges()
3. **拆分模块** - splitFormation()
4. **归一化模块** - normalizeTopology()
5. **空中编队模块** - _setAirSwarmFormation()
6. **地面编队模块** - _setGroundFormation()
7. **日志模块** - LOG_INFO/WARN/ERROR 宏

## 组件和接口

### 核心函数

#### 1. setFormationWithResult

```cpp
FormationResult setFormationWithResult(Unit_Formation* formation);
```

**功能：** 设置混合空地编队并返回详细结果

**输入：**
- `formation`: 编队配置，包含所有单元的ID、Leader关系、距离和角度

**输出：**
- `FormationResult`: 包含空中组结果、地面组结果、跨类型边警告和总耗时

**流程：**
1. 启动计时器
2. 验证编队配置
3. 检测跨类型边
4. 拆分编队为空中组和地面组
5. 归一化地面拓扑
6. 下发空中编队
7. 下发地面编队
8. 汇总结果并记录日志

#### 2. validateFormation

```cpp
bool validateFormation(const Unit_Formation* formation);
```

**功能：** 验证编队配置的有效性

**验证规则：**
- formation 不为 NULL
- robot_ids 长度 > 0
- leader_ids、distances、angles 长度与 robot_ids 一致
- 所有 leader_id 索引在有效范围内 [0, n-1]
- Leader (索引0) 的 leader_id 必须为 -1

**返回：** true=有效，false=无效

#### 3. detectCrossTypeEdges

```cpp
std::vector<CrossTypeEdge> detectCrossTypeEdges(const Unit_Formation* formation);
```

**功能：** 检测编队中的跨类型边

**检测逻辑：**
- 遍历所有单元（从索引1开始，跳过Leader）
- 检查单元类型（UID首字符：'A'=空中，'G'=地面）
- 如果单元类型与其Leader类型不同，记录为跨类型边

**返回：** 跨类型边列表

#### 4. splitFormation

```cpp
SplitResult splitFormation(const Unit_Formation* formation);
```

**功能：** 将混合编队拆分为空中组和地面组

**拆分逻辑：**
1. 遍历所有单元，根据UID首字符分类
2. 为每个组构建新的索引映射（oldIndex → newIndex）
3. 重新构建 robot_ids、leader_ids、distances、angles 序列
4. 调整 leader_ids 索引以匹配新的组内索引
5. 处理跨类型边：如果Leader不在同一组，设置为独立节点（leader_id=-1）

**返回：** SplitResult 包含空中组、地面组和跨类型边警告

#### 5. normalizeTopology

```cpp
void normalizeTopology(Unit_Formation* formation, TopologyStrategy strategy);
```

**功能：** 归一化拓扑结构（仅用于地面组）

**策略：**
- TOPOLOGY_CHAIN: 链式拓扑（默认），保持不变
- TOPOLOGY_STAR: 星形拓扑，转换为链式

**注意：** 空中组固定使用星形拓扑，不需要归一化

#### 6. _setAirSwarmFormation

```cpp
static GroupResult _setAirSwarmFormation(Unit_Formation* formation);
```

**功能：** 下发空中编队配置

**实现：**
1. 检查 currentAUVLeaderObj 是否为 NULL
2. 调用 Air_Unit_rpc_setFormation 下发编队
3. 记录成功/失败结果

**返回：** GroupResult 包含空中组的执行结果

#### 7. _setGroundFormation

```cpp
static GroupResult _setGroundFormation(Unit_Formation* formation);
```

**功能：** 下发地面编队配置

**实现：**
1. 检查 currentGUVLeaderObj 是否为 NULL
2. 先调用 Leader 的 setFormation
3. 遍历所有地面单元，为每个单元调用 setRearVehicles
4. 如果 setRearVehicles 失败，尝试补模式（Follow + FW_Object）后重试
5. 记录每个单元的成功/失败结果

**返回：** GroupResult 包含地面组的执行结果

## 数据模型

### CrossTypeEdge

```cpp
struct CrossTypeEdge {
    int fromIndex;                     // 源节点索引
    int toIndex;                       // 目标节点索引
    char fromUid[MAX_UNITID_LENGTH];   // 源节点UID
    char toUid[MAX_UNITID_LENGTH];     // 目标节点UID
};
```

**用途：** 记录跨类型边信息，用于警告和调试

### SplitResult

```cpp
struct SplitResult {
    Unit_Formation airGroup;           // 空中组
    Unit_Formation groundGroup;        // 地面组
    std::vector<CrossTypeEdge> warnings;  // 跨类型边警告
};
```

**用途：** 存储编队拆分结果

### UnitResult

```cpp
struct UnitResult {
    char uid[MAX_UNITID_LENGTH];  // 单元ID
    bool success;                  // 是否成功
    int errorCode;                 // 错误码
    char errorMsg[256];            // 错误消息
    bool isOrphan;                 // 是否因跨类型边降级为独立节点
};
```

**用途：** 记录单个单元的执行结果

### GroupResult

```cpp
struct GroupResult {
    bool success;                      // 整组是否成功
    int successCount;                  // 成功单元数
    int failCount;                     // 失败单元数
    std::vector<UnitResult> unitResults;  // 每个单元的结果
    
    void calculateCounts();  // 计算成功/失败数量
};
```

**用途：** 记录一个组（空中或地面）的执行结果

### FormationResult

```cpp
struct FormationResult {
    GroupResult airResult;      // 空中组结果
    GroupResult groundResult;   // 地面组结果
    int elapsedMs;              // 耗时（毫秒）
    std::vector<CrossTypeEdge> crossTypeWarnings;  // 跨类型边警告
    
    bool isSuccess() const;           // 是否完全成功
    bool isPartialSuccess() const;    // 是否部分成功
    std::vector<UnitResult> getAllFailedUnits() const;  // 获取所有失败单元
};
```

**用途：** 存储整个编队设置的最终结果

## 关键设计决策

### 1. 跨类型边处理策略

**问题：** 如何处理空中单元和地面单元之间的连接？

**决策：** 
- 检测所有跨类型边并记录警告
- 在拆分阶段，将跨类型边的源节点降级为独立节点（leader_id=-1）
- 特殊情况：第一辆地面车跟随空中Leader是合法的，通过 setALeader 直接设置

**理由：**
- 保持编队拆分的简单性（每个组内部是纯类型）
- 通过 setALeader 显式处理跨类型连接
- 记录警告便于调试和监控

### 2. 地面编队下发策略

**问题：** 如何确保地面单元正确接收编队配置？

**决策：**
- 对每个地面单元都调用 setRearVehicles（包括叶子节点）
- 如果失败，先补模式（Follow + FW_Object）再重试
- 使用每个单元独立的 distance/angle 参数

**理由：**
- 确保所有单元都收到配置（即使后车列表为空）
- 补模式机制提高成功率
- 独立参数提供更灵活的编队控制

### 3. 空中编队下发策略

**问题：** 如何下发空中编队配置？

**决策：**
- 只调用 Air_Leader 的 setFormation 方法
- 传递完整的空中组 Formation（仅包含空中单元）
- 由 Air_Leader 负责协调其他空中单元

**理由：**
- 简化控制台逻辑
- 利用空中单元的自组织能力
- 减少 RPC 调用次数

### 4. 错误处理策略

**问题：** 如何处理部分单元失败的情况？

**决策：**
- 继续处理其他单元，不因单个失败而中断
- 记录每个单元的详细错误信息
- 返回部分成功状态（FE_PARTIAL_SUCCESS）

**理由：**
- 提高系统健壮性
- 便于定位问题单元
- 允许部分编队正常工作

## 正确性属性

*属性是一种特征或行为，应该在系统的所有有效执行中保持为真——本质上是关于系统应该做什么的形式化陈述。属性作为人类可读规范和机器可验证正确性保证之间的桥梁。*

### 属性 1：空中Leader设置完整性

*对于任何*空中单元，当调用 setToLeader 后，系统应该正确更新 currentAUVLeaderObj、currentLeaderUID，并将该单元的角色设置为 Leader

**验证：需求 1.1, 1.2, 1.3**

### 属性 2：Leader切换清理

*对于任何*已存在的 Leader，当设置新 Leader 时，旧 Leader 的所有信息（对象引用、UID、备份文件）应该被完全清除

**验证：需求 1.4**

### 属性 3：编队配置验证完整性

*对于任何* Unit_Formation，validateFormation 应该验证：(1) 所有序列长度相等，(2) 所有 leader_id 索引有效，(3) Leader 的 leader_id 为 -1

**验证：需求 4.1, 4.2, 4.3**

### 属性 4：第一辆地面车跟随配置

*对于任何*编队配置，如果第一辆地面车的 leader_id 指向空中Leader，系统应该正确设置该地面车的 Leader、模式（Follow）和次级模式（FW_Object）

**验证：需求 2.1, 2.2, 2.3, 2.4**

### 属性 5：链式拓扑保证

*对于任何*包含多个地面单元的编队，第二辆及之后的地面单元应该形成链式拓扑（每个单元只跟随一个前车）

**验证：需求 3.1, 3.2**

### 属性 6：最小安全间隔保证

*对于任何*地面单元（索引 > 0），如果其 distance 参数小于 MIN_SAFE_DISTANCE（0.5米），系统应该自动调整为 MIN_SAFE_DISTANCE

**验证：需求 3.5**

### 属性 7：跨类型边检测完整性

*对于任何*包含不同类型单元的 Unit_Formation，detectCrossTypeEdges 应该检测到所有跨类型连接，并记录源节点和目标节点的索引及 UID

**验证：需求 5.1, 5.2, 5.3**

### 属性 8：拆分后单元数量守恒

*对于任何* Unit_Formation，拆分后空中组和地面组的单元总数应该等于原始编队的单元总数

**验证：需求 6.3**

### 属性 9：拆分后索引映射正确性

*对于任何*拆分后的组，组内的 leader_ids 应该正确映射到新的组内索引（不再引用原始编队的索引）

**验证：需求 6.4**

### 属性 10：地面编队下发覆盖性

*对于任何*地面组，_setGroundFormation 应该为每个地面单元（包括叶子节点）调用 setRearVehicles，并使用该单元独立的 distance 和 angle 参数

**验证：需求 8.1, 8.2, 8.3**

### 属性 11：地面编队重试机制

*对于任何*地面单元，如果 setRearVehicles 首次失败，系统应该先设置模式为 Follow 和次级模式为 FW_Object，然后重试 setRearVehicles

**验证：需求 8.4**

### 属性 12：结果完整性

*对于任何*编队设置操作，FormationResult 应该包含：(1) 空中组和地面组的结果，(2) 每个单元的成功/失败状态、错误码和错误消息，(3) 跨类型边警告列表，(4) 总耗时

**验证：需求 10.1, 10.2, 10.3, 10.4, 10.5**

### 属性 13：错误传播隔离

*对于任何*单个单元的失败（对象创建失败或RPC调用失败），不应该阻止其他单元的处理，系统应该继续处理剩余单元

**验证：需求 11.2**

### 属性 14：部分成功状态判断

*对于任何*编队设置操作，如果至少有一个单元成功且至少有一个单元失败，系统应该返回部分成功状态（通过 isPartialSuccess() 返回 true）

**验证：需求 11.3**

### 属性 15：向后兼容性

*对于任何*使用旧接口 setFormation(Unit_Formation*) 的调用，系统应该在内部调用 setFormationWithResult 并将结果转换为 bool（成功或部分成功返回 true）

**验证：需求 12.3**

## 错误处理

### 错误码定义

```cpp
enum FormationErrorCode {
    FE_SUCCESS = 0,           // 成功
    FE_INVALID_INPUT = 1,     // 输入校验失败
    FE_NO_LEADER = 2,         // 未设置Leader
    FE_RPC_FAILED = 3,        // RPC调用失败
    FE_PARTIAL_SUCCESS = 4,   // 部分成功
    FE_ALL_FAILED = 5         // 全部失败
};
```

### 错误处理流程

1. **输入验证失败** → 返回 FE_INVALID_INPUT，记录错误日志
2. **Leader未设置** → 返回 FE_NO_LEADER，记录错误日志
3. **RPC调用失败** → 记录错误信息，继续处理其他单元
4. **部分单元失败** → 返回 FE_PARTIAL_SUCCESS，记录失败单元列表
5. **所有单元失败** → 返回 FE_ALL_FAILED，记录错误日志

### 异常资源释放

所有 CORBA 异常必须通过 `ILU_C_EXCEPTION_FREE(&ev)` 释放，避免内存泄漏。

## 测试策略

### 单元测试

1. **validateFormation 测试**
   - 测试有效配置
   - 测试无效配置（NULL、长度不一致、索引越界）

2. **detectCrossTypeEdges 测试**
   - 测试纯地面编队（无跨类型边）
   - 测试纯空中编队（无跨类型边）
   - 测试混合编队（有跨类型边）

3. **splitFormation 测试**
   - 测试纯地面编队拆分
   - 测试纯空中编队拆分
   - 测试混合编队拆分
   - 验证索引映射正确性

### 集成测试

1. **空地混合编队测试**
   - 1个空中Leader + 3个地面Follower
   - 验证第一辆地面车跟随空中Leader
   - 验证其余地面车链式跟随

2. **纯地面编队测试**
   - 验证现有功能不受影响

3. **纯空中编队测试**
   - 验证现有功能不受影响

### 属性测试

使用属性测试框架（如 Google Test + 随机生成器）验证正确性属性：

1. **属性1-2**: 生成随机 Formation，验证完整性和索引有效性
2. **属性3**: 生成随机混合 Formation，验证拆分后单元数量守恒
3. **属性4**: 生成包含跨类型边的 Formation，验证检测完整性
4. **属性5**: 生成随机地面组，验证所有单元都被处理
5. **属性6**: 生成包含小距离值的 Formation，验证自动调整
6. **属性7**: 生成随机 Formation，验证结果包含所有单元
7. **属性8**: 模拟单个单元失败，验证其他单元不受影响

## 性能考虑

### 时间复杂度

- validateFormation: O(n)
- detectCrossTypeEdges: O(n)
- splitFormation: O(n)
- _setGroundFormation: O(n) RPC调用
- _setAirSwarmFormation: O(1) RPC调用

总体：O(n)，其中 n 是单元总数

### 空间复杂度

- SplitResult: O(n)
- FormationResult: O(n)

总体：O(n)

### 优化建议

1. **并行RPC调用** - 可以并行调用多个单元的 setRearVehicles
2. **缓存单元对象** - 避免重复创建 Unit_rpc 对象
3. **批量操作** - 考虑批量下发编队配置

## 兼容性

### 向后兼容

1. 保留 `setFormation(Unit_Formation*)` 接口
2. 内部调用 `setFormationWithResult` 并转换返回值
3. 现有代码无需修改

### 接口演进

```cpp
// 旧接口（保留）
bool setFormation(Unit_Formation* formation);

// 新接口（推荐）
FormationResult setFormationWithResult(Unit_Formation* formation);
```

## 部署注意事项

1. **测试顺序**
   - 先测试纯地面编队
   - 再测试纯空中编队
   - 最后测试混合编队

2. **日志监控**
   - 关注跨类型边警告
   - 关注部分失败情况
   - 关注RPC调用耗时

3. **回滚计划**
   - 如果新功能有问题，可以回退到旧接口
   - 旧接口保持不变，确保基本功能可用
