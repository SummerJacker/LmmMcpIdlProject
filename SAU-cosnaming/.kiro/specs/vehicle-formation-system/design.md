# Design Document: Vehicle Formation System Improvements

## Overview

本设计文档针对车辆编队控制系统的三个核心问题提出技术解决方案：
1. **地面单位编队相撞** - 星形拓扑导致多个Follower追同一目标点
2. **空中单位跟随模式失效** - setGroupMode遍历时过滤掉了空中单元
3. **空地联合跟随架构** - 为未来混合编队奠定基础

## 1. 背景与问题复述

### 1.1 问题一：地面单位编队相撞

**现状**：当前UI录入时，所有Follower的`leader_ids`都设为0（星形拓扑）
```
当前: Leader(0) ← F1, F2, F3 (全部直连Leader)
目标: Leader(0) ← F1(1) ← F2(2) ← F3 (链式)
```

**根因**：`mainwindow.cpp::on_pushButton_19_clicked()`中：
```cpp
Unit_ShortSeq_Append(&formation->leader_ids, 0, &err); // 固定为0
```

### 1.2 问题二：空中单位跟随模式失效

**现状**：`setGroupMode()`遍历时过滤掉了空中单元
```cpp
if(((char*)uid)[0] != 'G')  // 只处理地面单元
    continue;
```

**根因**：空中单元被跳过，无法设置Mode和MinorMode

### 1.3 问题三：职责混乱

**现状**：`setGroupMode()`中直接调用`setRearVehicles`，与`setFormation()`职责重叠

## 2. 数据模型

### 2.1 Formation 数据结构

```cpp
struct Unit_Formation {
    Unit_UnitIDSeq   robot_ids;   // ["GV1", "GV2", "AV1", "AV2"]
    Unit_ShortSeq    leader_ids;  // [0, 0, 0, 2] - 数组索引，非UID
    Unit_FloatSeq    distances;   // [0.0, 0.5, 0.0, 1.0]
    Unit_FloatSeq    angles;      // [0.0, 0.0, 0.0, 30.0]
};
```

### 2.2 leader_ids 语义定义

| 字段 | 类型 | 语义 |
|------|------|------|
| `leader_ids[i]` | short | `robot_ids[i]` 跟随 `robot_ids[leader_ids[i]]` |
| `leader_ids[0]` | short | 必须为0（Leader自己跟随自己，表示根节点） |

**示例**：
```
robot_ids:  [GV1, GV2, GV3]
leader_ids: [0,   0,   1  ]
含义: GV1是Leader, GV2跟GV1, GV3跟GV2
```

### 2.3 拆分后索引重映射

混合编队拆分时，需要重新映射`leader_ids`：

```
原始: robot_ids=[GV1, GV2, AV1, AV2], leader_ids=[0, 0, 0, 2]

拆分后:
  地面组: robot_ids=[GV1, GV2], leader_ids=[0, 0]  // 索引不变
  空中组: robot_ids=[AV1, AV2], leader_ids=[0, 0]  // AV2原指向索引2(AV1)，重映射为0
```

## 3. 算法流程

### 3.1 整体流程图

```
┌─────────────────────────────────────────────────────────────┐
│                    setFormation(formation)                   │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ Step 1: 校验 (validateFormation)                             │
│   - 检查formation非空                                        │
│   - 检查robot_ids长度 >= 1                                   │
│   - 检查leader_ids/distances/angles长度一致                  │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ Step 2: 检测跨类型边 (detectCrossTypeEdges)                  │
│   - 遍历leader_ids，检查robot_ids[i]与robot_ids[leader_ids[i]]│
│   - 若类型不同(A→G或G→A)，记录警告并标记该边为无效           │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ Step 3: 拆分 (splitFormation)                                │
│   - 按robot_ids[i][0]分为空中组(A)和地面组(G)                │
│   - 重映射leader_ids索引                                     │
│   - 忽略跨类型边（降级策略）                                 │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ Step 4: 归一化 (normalizeTopology)                           │
│   - 对每个子组，检测星形拓扑(多个节点leader_ids相同)         │
│   - 按录入顺序转换为链式拓扑                                 │
└─────────────────────────────────────────────────────────────┘
                              │
              ┌───────────────┴───────────────┐
              ▼                               ▼
┌─────────────────────────┐     ┌─────────────────────────┐
│ Step 5A: 空中下发路径    │     │ Step 5G: 地面下发路径    │
│ _setAirSwarmFormation   │     │ _setGroundFormation     │
│ - sendControlledVehicle │     │ - setRearVehicles       │
│ - leader.setFormation   │     │ - 逐节点下发dist/angle  │
└─────────────────────────┘     └─────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ Step 6: 汇总结果 (aggregateResults)                          │
│   - 收集每个单元的成功/失败状态                              │
│   - 返回FormationResult结构                                  │
└─────────────────────────────────────────────────────────────┘
```

### 3.2 归一化算法 (normalizeTopology)

```cpp
// 伪代码
void normalizeTopology(Formation& f, TopologyStrategy strategy) {
    if (strategy == STAR) return; // 保持原样
    
    // 统计每个节点的直接后车数量
    map<int, vector<int>> followers; // leader_idx -> [follower_indices]
    for (int i = 1; i < f.robot_ids.length; i++) {
        followers[f.leader_ids[i]].push_back(i);
    }
    
    // 对于有多个直接后车的节点，串成链
    for (auto& [leader_idx, follower_list] : followers) {
        if (follower_list.size() > 1) {
            // 按录入顺序串成链: F1→F2→F3
            for (int k = 1; k < follower_list.size(); k++) {
                f.leader_ids[follower_list[k]] = follower_list[k-1];
            }
            LOG_INFO("归一化: 节点%d的%d个后车已串成链式", 
                     leader_idx, follower_list.size());
        }
    }
}
```

### 3.3 拆分与重映射算法 (splitFormation)

```cpp
// 伪代码
struct SplitResult {
    Formation air_group;
    Formation ground_group;
    vector<string> warnings;
};

SplitResult splitFormation(const Formation& f) {
    SplitResult result;
    map<int, int> air_idx_map;    // 原索引 -> 空中组新索引
    map<int, int> ground_idx_map; // 原索引 -> 地面组新索引
    
    // 第一遍：分类并建立索引映射
    for (int i = 0; i < f.robot_ids.length; i++) {
        if (f.robot_ids[i][0] == 'A') {
            air_idx_map[i] = result.air_group.robot_ids.length;
            append(result.air_group, f, i);
        } else {
            ground_idx_map[i] = result.ground_group.robot_ids.length;
            append(result.ground_group, f, i);
        }
    }
    
    // 第二遍：重映射leader_ids
    for (int i = 0; i < result.air_group.robot_ids.length; i++) {
        int orig_leader = f.leader_ids[orig_idx_of(i)];
        if (air_idx_map.contains(orig_leader)) {
            result.air_group.leader_ids[i] = air_idx_map[orig_leader];
        } else {
            // 跨类型边，降级为独立Leader
            result.air_group.leader_ids[i] = i; // 自己跟自己
            result.warnings.push_back(
                format("跨类型边[%s→%s]已忽略", 
                       f.robot_ids[orig_idx], f.robot_ids[orig_leader]));
        }
    }
    // 地面组同理...
    
    return result;
}
```

## 4. 接口与调用顺序

### 4.1 职责分离

| 函数 | 职责 | 调用的RPC |
|------|------|----------|
| `setGroupMode(mode)` | 设置角色/模式/次级模式 | `setRole`, `setMode`, `setMinorMode`, `setALeader` |
| `setFormation(formation)` | 下发队形拓扑与参数 | `setRearVehicles`(地面), `sendControlledVehicle`+`setFormation`(空中) |

### 4.2 调用时序

```
用户操作                Console                          Unit
   │                      │                               │
   │──设置Leader────────▶│                               │
   │                      │──setRole(Leader)────────────▶│
   │                      │                               │
   │──录入队形──────────▶│                               │
   │                      │ (存储到formation变量)         │
   │                      │                               │
   │──开启跟随模式──────▶│                               │
   │                      │──setGroupMode(Follow)───────▶│
   │                      │   ├─setRole(Follower)        │
   │                      │   ├─setMode(Follow)          │
   │                      │   └─setMinorMode(FW_Object)  │
   │                      │                               │
   │──发送队形──────────▶│                               │
   │                      │──setFormation(formation)────▶│
   │                      │   ├─validateFormation        │
   │                      │   ├─detectCrossTypeEdges     │
   │                      │   ├─splitFormation           │
   │                      │   ├─normalizeTopology        │
   │                      │   └─dispatch (A/G路径)       │
```

### 4.3 setGroupMode 修改方案

**修改文件**: `Console/console.cpp`

**修改点**:
1. 移除 `if(((char*)uid)[0] != 'G') continue;` 过滤条件
2. 移除 `setRearVehicles` 调用（职责转移到setFormation）
3. 增加空中单元处理分支

```cpp
// 修改后的setGroupMode伪代码
bool setGroupMode(Unit_UnitMode mode) {
    // 遍历所有单元（不再过滤空中单元）
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        char unitType = ((char*)uid)[0];
        
        if (unitType == 'G') {
            // 地面单元处理
            grd_tmpObj = ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev);
            Unit_rpc_setRole(grd_tmpObj, isLeader ? UR_Leader : UR_Follower, ...);
            Unit_rpc_setMode(grd_tmpObj, mode, &ev);
            Unit_rpc_setMinorMode(grd_tmpObj, 
                mode == UM_Follow ? UMM_FW_Object : UMM_None, &ev);
            // 不再调用 setRearVehicles
        } 
        else if (unitType == 'A') {
            // 空中单元处理（新增）
            air_tmpObj = ILU_C_SBHToObject(sbh, Air_Unit_rpc__MSType, &ev);
            Unit_rpc_setRole(air_tmpObj, isLeader ? UR_Leader : UR_Follower, ...);
            Unit_rpc_setMode(air_tmpObj, mode, &ev);
            Unit_rpc_setMinorMode(air_tmpObj, 
                mode == UM_Follow ? UMM_FW_Object : UMM_None, &ev);
        }
        
        LOG_INFO("[setGroupMode] %s: role=%s, mode=%d, minorMode=%d", 
                 uid, isLeader?"Leader":"Follower", mode, minorMode);
    }
    return true;
}
```

### 4.4 setFormation 修改方案

**修改文件**: `Console/console.cpp`

**新增函数**:
- `validateFormation()` - 校验
- `detectCrossTypeEdges()` - 跨类型边检测
- `splitFormation()` - 拆分
- `normalizeTopology()` - 归一化
- `_setGroundFormation()` - 地面下发（重构现有逻辑）
- `_setAirSwarmFormation()` - 空中下发（已存在，微调）

```cpp
// 修改后的setFormation
bool setFormation(Unit_Formation* formation) {
    FormationResult result;
    
    // Step 1: 校验
    if (!validateFormation(formation)) {
        LOG_ERROR("[setFormation] 校验失败");
        return false;
    }
    LOG_INFO("[setFormation] 输入: robot_ids=%s, leader_ids=%s", 
             formatSeq(formation->robot_ids), formatSeq(formation->leader_ids));
    
    // Step 2: 检测跨类型边
    auto crossEdges = detectCrossTypeEdges(formation);
    for (auto& edge : crossEdges) {
        LOG_WARN("[setFormation] 检测到跨类型边[%s→%s]，已自动忽略", 
                 edge.from, edge.to);
    }
    
    // Step 3: 拆分
    auto [airGroup, groundGroup] = splitFormation(formation);
    LOG_INFO("[setFormation] 拆分: 空中组=%d个, 地面组=%d个", 
             airGroup.robot_ids.length, groundGroup.robot_ids.length);
    
    // Step 4: 归一化
    normalizeTopology(airGroup, currentTopologyStrategy);
    normalizeTopology(groundGroup, currentTopologyStrategy);
    LOG_INFO("[setFormation] 归一化后: 空中leader_ids=%s, 地面leader_ids=%s",
             formatSeq(airGroup.leader_ids), formatSeq(groundGroup.leader_ids));
    
    // Step 5: 分别下发
    if (airGroup.robot_ids.length > 1) {
        result.airResult = _setAirSwarmFormation(&airGroup);
    }
    if (groundGroup.robot_ids.length > 1) {
        result.groundResult = _setGroundFormation(&groundGroup);
    }
    
    // Step 6: 汇总结果
    LOG_INFO("[setFormation] 完成: 空中=%s, 地面=%s, 耗时=%dms",
             result.airResult.success ? "成功" : "失败",
             result.groundResult.success ? "成功" : "失败",
             result.elapsedMs);
    
    return result.isSuccess();
}
```

### 4.5 UI录入修改方案

**修改文件**: `Console/mainwindow.cpp`

**修改点**: `on_pushButton_19_clicked()` 中录入时使用链式拓扑

```cpp
// 修改前
Unit_ShortSeq_Append(&formation->leader_ids, 0, &err); // 固定为0

// 修改后
short leaderIdx = (currentUnitCount > 0) ? (currentUnitCount - 1) : 0;
Unit_ShortSeq_Append(&formation->leader_ids, leaderIdx, &err);
// 第1个录入的跟0(Leader)，第2个跟1，第3个跟2...形成链式
```

## 5. 日志规范 (Req 9)

### 5.1 日志格式

```
[时间戳] [级别] [模块] 消息内容
```

示例：
```
[2025-01-10 14:30:15.123] [INFO] [setFormation] 输入: robot_ids=[GV1,GV2,GV3], leader_ids=[0,0,0]
[2025-01-10 14:30:15.124] [INFO] [normalizeTopology] 归一化: [0,0,0] -> [0,0,1]
[2025-01-10 14:30:15.125] [INFO] [_setGroundFormation] GV2: setRearVehicles(dist=0.5, angle=0.0) -> 成功
```

### 5.2 日志点定义

| 阶段 | 日志级别 | 内容 |
|------|----------|------|
| setFormation入口 | INFO | 完整输入参数 |
| 跨类型边检测 | WARN | 每个跨类型边的from/to |
| 拆分完成 | INFO | 空中组/地面组数量 |
| 归一化完成 | INFO | 归一化前后leader_ids对比 |
| RPC调用 | INFO | 目标UID、接口名、参数、结果 |
| RPC失败 | ERROR | 目标UID、接口名、错误码 |
| 流程结束 | INFO | 总体结果、成功/失败数、耗时 |

### 5.3 日志宏定义

```cpp
// console.h 新增
#define LOG_INFO(fmt, ...) qDebug() << QStringLiteral("[INFO] " fmt).arg(__VA_ARGS__)
#define LOG_WARN(fmt, ...) qDebug() << QStringLiteral("[WARN] " fmt).arg(__VA_ARGS__)
#define LOG_ERROR(fmt, ...) qDebug() << QStringLiteral("[ERROR] " fmt).arg(__VA_ARGS__)
```

## 6. 失败与部分成功 (Req 10)

### 6.1 结果数据结构

```cpp
struct UnitResult {
    char* uid;
    bool success;
    int errorCode;      // 0=成功, 其他=错误码
    char* errorMsg;
};

struct GroupResult {
    bool success;       // 整组是否成功
    int successCount;
    int failCount;
    vector<UnitResult> unitResults;
};

struct FormationResult {
    GroupResult airResult;
    GroupResult groundResult;
    int elapsedMs;
    
    bool isSuccess() { 
        return airResult.success && groundResult.success; 
    }
    bool isPartialSuccess() {
        return (airResult.successCount > 0 || groundResult.successCount > 0) &&
               (airResult.failCount > 0 || groundResult.failCount > 0);
    }
};
```

### 6.2 错误处理策略

```cpp
// 单个单元失败不中断整体流程
for (int i = 0; i < n_total; i++) {
    UnitResult ur;
    ur.uid = robot_ids[i];
    
    flag = Unit_rpc_setRearVehicles(obj, seq, dist, angle, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        ur.success = false;
        ur.errorCode = ev.returnCode;
        ur.errorMsg = "RPC调用失败";
        LOG_ERROR("[_setGroundFormation] %s: setRearVehicles失败, 错误码=%d", 
                  ur.uid, ur.errorCode);
        ILU_C_EXCEPTION_FREE(&ev);
        // 继续处理下一个单元，不return
    } else {
        ur.success = true;
        ur.errorCode = 0;
        LOG_INFO("[_setGroundFormation] %s: setRearVehicles成功", ur.uid);
    }
    
    result.unitResults.push_back(ur);
}

// 汇总
result.successCount = count_if(result.unitResults, [](auto& r){ return r.success; });
result.failCount = result.unitResults.size() - result.successCount;
result.success = (result.failCount == 0);
```

### 6.3 UI反馈

```cpp
// mainwindow.cpp 修改 on_sendFormationButton_clicked()
FormationResult result = setFormation(formation);

if (result.isSuccess()) {
    ui->textBrowser_2->append(QStringLiteral("✓ 队形下发成功！"));
} else if (result.isPartialSuccess()) {
    ui->textBrowser_2->append(QStringLiteral("⚠ 队形部分成功："));
    for (auto& ur : result.getAllFailedUnits()) {
        ui->textBrowser_2->append(QStringLiteral("  - %1 失败: %2")
            .arg(ur.uid).arg(ur.errorMsg));
    }
} else {
    ui->textBrowser_2->append(QStringLiteral("✗ 队形下发失败！"));
}
```

## 7. 测试用例与验收映射

### 7.1 测试用例映射表

| 测试用例 | 验证需求 | 关键日志/行为 |
|----------|----------|---------------|
| TC-1: 链式拓扑转换 | Req 1.1, 1.2, 1.4, 1.6 | `[normalizeTopology] 归一化: [0,0,0] -> [0,0,1]` |
| TC-2: 空中编队下发 | Req 4.1, 4.2, 4.3, 4.4 | `sendControlledVehicle`被调用，无`setRearVehicles`日志 |
| TC-3: 混合编队拆分 | Req 5.1, 6.2, 6.4 | `[splitFormation] 拆分: 空中组=2个, 地面组=2个` |
| TC-4: 跨类型边降级 | Req 6.1, 6.4 | `[WARN] 检测到跨类型边[AV1→GV1]，已自动忽略` |
| TC-5: 部分成功处理 | Req 10.1, 10.2, 10.4 | `[ERROR] GV2: setRearVehicles失败` + 继续处理其他单元 |
| TC-6: 参数独立生效 | Req 7.1, 7.2, 7.3, 7.5 | 每个单元日志显示不同的dist/angle值 |

### 7.2 测试数据

```cpp
// TC-1: 链式拓扑转换
Unit_Formation tc1 = {
    .robot_ids = ["GV1", "GV2", "GV3"],
    .leader_ids = [0, 0, 0],      // 星形输入
    .distances = [0.0, 0.5, 0.5],
    .angles = [0.0, 0.0, 0.0]
};
// 预期输出: leader_ids = [0, 0, 1]

// TC-2: 空中编队下发
Unit_Formation tc2 = {
    .robot_ids = ["AV1", "AV2", "AV3"],
    .leader_ids = [0, 0, 0],
    .distances = [0.0, 1.0, 1.5],
    .angles = [0.0, 0.0, 0.0]
};
// 预期: _setAirSwarmFormation被调用

// TC-3: 混合编队拆分
Unit_Formation tc3 = {
    .robot_ids = ["GV1", "GV2", "AV1", "AV2"],
    .leader_ids = [0, 0, 0, 2],   // AV2跟AV1(索引2)
    .distances = [0.0, 0.5, 0.0, 1.0],
    .angles = [0.0, 0.0, 0.0, 0.0]
};
// 预期: 地面组=[GV1,GV2], leader_ids=[0,0]
//       空中组=[AV1,AV2], leader_ids=[0,0] (重映射)

// TC-4: 跨类型边降级
Unit_Formation tc4 = {
    .robot_ids = ["GV1", "AV1"],
    .leader_ids = [0, 0],         // AV1跟GV1(跨类型)
    .distances = [0.0, 0.5],
    .angles = [0.0, 0.0]
};
// 预期: 警告日志，AV1变为独立Leader

// TC-5: 部分成功处理
// 模拟: GV2的RPC调用返回失败
// 预期: GV1成功，GV2失败，GV3继续处理

// TC-6: 参数独立生效
Unit_Formation tc6 = {
    .robot_ids = ["GV1", "GV2", "GV3"],
    .leader_ids = [0, 0, 1],
    .distances = [0.0, 0.5, 1.0],
    .angles = [0.0, 30.0, 45.0]
};
// 预期: GV2使用dist=0.5/angle=30, GV3使用dist=1.0/angle=45
```

## 8. Correctness Properties

*A property is a characteristic or behavior that should hold true across all valid executions of a system—essentially, a formal statement about what the system should do. Properties serve as the bridge between human-readable specifications and machine-verifiable correctness guarantees.*

### Property 1: 链式拓扑归一化正确性
*For any* formation with star topology (multiple followers pointing to same leader), after `normalizeTopology()`, each non-leader node SHALL have at most one direct follower.

**Validates: Requirements 1.2, 1.4**

```cpp
// 伪代码验证
bool verifyChainTopology(Formation& f) {
    map<int, int> followerCount; // leader_idx -> count of direct followers
    for (int i = 1; i < f.leader_ids.length; i++) {
        followerCount[f.leader_ids[i]]++;
    }
    // 除了根节点(0)，其他节点最多有1个直接后车
    for (auto& [idx, count] : followerCount) {
        if (idx != 0 && count > 1) return false;
    }
    return true;
}
```

### Property 2: leader_ids索引有效性
*For any* valid formation, all values in `leader_ids` SHALL be valid indices into `robot_ids` (0 <= leader_ids[i] < robot_ids.length).

**Validates: Requirements 1.5, 5.4**

```cpp
bool verifyLeaderIdsValidity(Formation& f) {
    int n = f.robot_ids.length;
    for (int i = 0; i < n; i++) {
        if (f.leader_ids[i] < 0 || f.leader_ids[i] >= n) return false;
    }
    return true;
}
```

### Property 3: 职责分离不变量
*For any* call to `setGroupMode()`, the function SHALL NOT invoke `setRearVehicles()` or `sendControlledVehicle()`.

**Validates: Requirements 2.1, 2.4**

### Property 4: 空中编队接口约束
*For any* formation where all units are air units (AV*), `setFormation()` SHALL invoke `sendControlledVehicle()` and `setFormation()` on leader, and SHALL NOT invoke `setRearVehicles()`.

**Validates: Requirements 4.1, 4.2, 4.3**

### Property 5: 跨类型边降级处理
*For any* formation containing cross-type edges (A→G or G→A), after `splitFormation()`:
1. A warning SHALL be logged for each cross-type edge
2. The cross-type edge SHALL be removed (follower becomes independent leader)
3. Same-type edges SHALL be preserved

**Validates: Requirements 6.1, 6.4**

```cpp
bool verifyCrossTypeHandling(Formation& input, SplitResult& result) {
    // 验证跨类型边被移除
    for (auto& edge : detectCrossTypeEdges(input)) {
        // 在拆分后的组中，该边不应存在
        assert(!edgeExistsInGroup(result.airGroup, edge));
        assert(!edgeExistsInGroup(result.groundGroup, edge));
    }
    // 验证同类型边被保留
    for (int i = 0; i < input.robot_ids.length; i++) {
        if (isSameType(input.robot_ids[i], input.robot_ids[input.leader_ids[i]])) {
            // 该边应在对应组中存在
            assert(edgePreservedInSplitResult(input, i, result));
        }
    }
    return true;
}
```

### Property 6: 拆分后索引重映射正确性
*For any* mixed formation after `splitFormation()`, the `leader_ids` in each sub-group SHALL correctly reference indices within that sub-group (not original indices).

**Validates: Requirements 6.4**

```cpp
bool verifyIndexRemapping(Formation& original, SplitResult& result) {
    // 空中组验证
    for (int i = 0; i < result.airGroup.robot_ids.length; i++) {
        int leaderIdx = result.airGroup.leader_ids[i];
        assert(leaderIdx >= 0 && leaderIdx < result.airGroup.robot_ids.length);
        // 且语义正确：原始关系被保留
    }
    // 地面组同理
    return true;
}
```

### Property 7: 参数独立性
*For any* formation with distinct distance/angle values per follower, each follower's RPC call SHALL use its own distance/angle values (not the first follower's values).

**Validates: Requirements 7.1, 7.2, 7.3**

```cpp
bool verifyParameterIndependence(Formation& f, vector<RPCCall>& calls) {
    for (int i = 1; i < f.robot_ids.length; i++) {
        auto& call = findCallForUnit(calls, f.robot_ids[i]);
        assert(call.distance == f.distances[i]);
        assert(call.angle == f.angles[i]);
    }
    return true;
}
```

### Property 8: 部分成功处理
*For any* formation dispatch where some units fail, the result SHALL:
1. Continue processing remaining units (not abort)
2. Return correct success/fail counts
3. List all failed units with error details

**Validates: Requirements 10.1, 10.2, 10.4**

```cpp
bool verifyPartialSuccessHandling(Formation& f, 
                                   set<string> simulatedFailures,
                                   FormationResult& result) {
    // 验证失败数量正确
    assert(result.failCount == simulatedFailures.size());
    // 验证成功数量正确
    assert(result.successCount == f.robot_ids.length - simulatedFailures.size());
    // 验证失败单元被正确记录
    for (auto& uid : simulatedFailures) {
        assert(result.containsFailedUnit(uid));
    }
    return true;
}
```

## 9. Error Handling

### 9.1 错误分类

| 错误类型 | 处理策略 | 示例 |
|----------|----------|------|
| 输入校验失败 | 立即返回false | formation为NULL |
| 跨类型边 | 降级处理，继续执行 | AV1→GV1 |
| 单个单元RPC失败 | 记录错误，继续处理其他单元 | GV2连接超时 |
| 全部单元失败 | 返回整体失败 | 网络断开 |

### 9.2 错误码定义

```cpp
enum FormationErrorCode {
    FE_SUCCESS = 0,
    FE_INVALID_INPUT = 1,      // 输入校验失败
    FE_NO_LEADER = 2,          // 未设置Leader
    FE_RPC_FAILED = 3,         // RPC调用失败
    FE_PARTIAL_SUCCESS = 4,    // 部分成功
    FE_ALL_FAILED = 5          // 全部失败
};
```

## 10. Testing Strategy

### 10.1 单元测试

- `validateFormation()` - 边界条件测试
- `detectCrossTypeEdges()` - 各种边类型组合
- `splitFormation()` - 索引重映射正确性
- `normalizeTopology()` - 星形→链式转换

### 10.2 属性测试

使用 Qt Test 框架 + 随机数据生成：

```cpp
void TestFormation::testNormalizeTopology_property() {
    // 生成随机星形拓扑
    for (int trial = 0; trial < 100; trial++) {
        Formation f = generateRandomStarFormation(3 + rand() % 10);
        normalizeTopology(f, CHAIN);
        QVERIFY(verifyChainTopology(f));
        QVERIFY(verifyLeaderIdsValidity(f));
    }
}
```

### 10.3 集成测试

- 完整流程测试：录入→发送→验证日志
- 模拟RPC失败场景
- 混合编队端到端测试


## 11. 设计决策补充说明

### 11.1 空中组拓扑策略

**决策**：空中组固定采用 STAR 策略，不执行链式归一化。

**原因**：
- 空中编队下发路径为 `sendControlledVehicle` + `leader.setFormation`，Leader统一控制所有Follower
- 空中端 `setRearVehicles` 未实现，链式拓扑无法在空中端生效
- `airGroup.leader_ids` 仅用于数据表达和日志展示，不影响下发语义

```cpp
// 修改后的setFormation
normalizeTopology(groundGroup, currentTopologyStrategy); // 地面组应用策略
// 空中组不归一化，保持原样（或固定STAR）
```

### 11.2 跨类型边降级后孤立节点处理

**决策**：降级后的孤立节点作为独立根节点参与下发，但在日志/结果中标记为"独立节点"。

**规则**：
- 孤立节点（`leader_ids[i] == i` 且非原始Leader）仍参与 mode 切换和下发
- 日志标记：`[WARN] %s 因跨类型边降级为独立节点`
- 结果中标记：`UnitResult.isOrphan = true`

**示例**：
```
原始: [GV1, AV1], leader_ids=[0, 0]  // AV1跟GV1(跨类型)
降级后: 空中组=[AV1], leader_ids=[0]  // AV1自己是Leader
日志: [WARN] AV1 因跨类型边降级为独立节点
```

### 11.3 空组成功判定

**决策**：空组默认视为成功。

```cpp
struct GroupResult {
    bool success = true;      // 默认true
    int successCount = 0;
    int failCount = 0;
    // ...
};

bool FormationResult::isSuccess() {
    // 空组不影响整体判定
    bool airOk = (airResult.unitResults.empty() || airResult.success);
    bool groundOk = (groundResult.unitResults.empty() || groundResult.success);
    return airOk && groundOk;
}
```

### 11.4 日志点定义（修正为7个）

| # | 阶段 | 日志级别 | 内容 |
|---|------|----------|------|
| 1 | setFormation入口 | INFO | 完整输入参数 |
| 2 | 跨类型边检测 | WARN | 每个跨类型边的from/to |
| 3 | 拆分完成 | INFO | 空中组/地面组数量 |
| 4 | 归一化完成 | INFO | 归一化前后leader_ids对比 |
| 5 | RPC调用成功 | INFO | 目标UID、接口名、参数 |
| 6 | RPC调用失败 | ERROR | 目标UID、接口名、错误码 |
| 7 | 流程结束 | INFO | 总体结果、成功/失败数、耗时 |

### 11.5 Property 1 修正

**修正后表述**：
*For any* formation with star topology after `normalizeTopology()`, **every node (including root)** SHALL have at most one direct follower.

```cpp
bool verifyChainTopology(Formation& f) {
    map<int, int> followerCount;
    for (int i = 1; i < f.leader_ids.length; i++) {
        followerCount[f.leader_ids[i]]++;
    }
    // 所有节点（包括根节点0）最多有1个直接后车
    for (auto& [idx, count] : followerCount) {
        if (count > 1) return false;
    }
    return true;
}
```
