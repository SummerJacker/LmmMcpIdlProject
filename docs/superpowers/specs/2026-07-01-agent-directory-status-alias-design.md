# MCP 智能体目录、状态与唯一别名系统设计

## 1. 目标

本阶段在现有 MCP -> Qt HTTP -> IDL/ILU 链路上增加三类能力：

1. MCP 可以查看 Qt 当前绑定表中的全部智能体。
2. MCP 可以查看每个智能体的实用状态，并明确区分在线、离线和未知。
3. MCP 可以为智能体设置持久化、全局唯一的别名，并在所有 MCP 工具中使用该别名。

本设计采用“Qt 统一注册表 + HTTP 扩展”方案。Qt 是智能体目录和别名的唯一数据源；MCP 只缓存和消费 Qt 数据，不单独持久化别名。

## 2. 已确认的产品决策

- 列表返回 Qt 当前绑定表中的全部节点，而不是只返回在线节点。
- 每个节点必须带 `online`、`offline` 或 `unknown` 连接状态。
- 别名在 Qt 控制台重启后继续保留。
- 第一版状态包括连接、类型、运行方式、角色、位姿、速度、时间和错误信息。
- 电量、健康度作为可选字段；数据源不可用时返回 `null`。
- 设置别名后，所有 MCP 查询和控制工具都可以直接使用别名。
- 别名去除首尾空格、执行 Unicode 兼容归一化、忽略英文大小写。
- 别名不能与任意 UID、旧 `robot_id` 或其他别名冲突。
- 第一版不修改 IDL，不依赖当前尚未实现的 `Console::setNickname`。
- 三名开发人员按互不修改同一源码文件的方式并行开发，完成后由集成人统一接线。

## 3. 当前项目现状

### 3.1 Qt 侧

`SAU/Console/HttpApiExecutor.cpp` 已存在：

- `GET /api/robot/list`
- `GET|POST /api/robot/status`
- 地面车和空中智能体的基础状态读取
- Mock 位姿、速度和在线状态
- `SAU_ENABLE_REAL_RPC=1` 真机 RPC 保护开关

当前 `/api/robot/list` 只返回 `unit_id` 和 `mock`，不能返回别名和完整状态。

`Units_Hash_Table` 会从 `BackupFile.txt` 恢复历史绑定。表中存在某个 UID 只表示“Qt 已登记/恢复该绑定”，不能直接证明智能体当前在线。

### 3.2 MCP 侧

MCP 已存在：

- `list_robots`
- `get_robot_status`
- `get_fleet_status`

但 `RobotInstanceManager` 主要依赖 `mcp/robots.json`。动态接入 Qt、但未写入 `robots.json` 的智能体无法被现有大部分工具解析。

`get_fleet_status()` 的默认查询范围也是 `robots.json`，不是 Qt 当前绑定目录。

### 3.3 IDL 侧

`console.idl` 已声明 `setNickname` 和 `getByName`，但 `console.cpp` 中对应函数目前只是空实现。

`ground_unit.idl` 和 `air_unit.idl` 可以提供位姿、速度和包含角色的当前信息。

`monitor.idl` 定义了 `health` 和 `battery`，但数据发送给 Monitor 进程，Console 当前没有可靠的数据读取路径。因此第一版不能承诺所有智能体都具有电量和健康度。

## 4. 标识和状态语义

### 4.1 标识

| 字段 | 含义 | 所有者 |
| --- | --- | --- |
| `unit_id` | 智能体永久标识，例如 `GV1`、`AV1` | Qt/IDL |
| `alias` | 用户设置的唯一别名，例如“先锋车” | Qt AgentDirectory |
| `robot_id` | `robots.json` 中的旧 MCP 标识，例如 `robot_1` | MCP 兼容层 |
| `display_name` | 有别名时使用别名，否则使用 `unit_id` | Qt 输出 |

`unit_id` 不允许修改。设置别名不会修改 IDL 对象、SBH 或绑定键。

### 4.2 绑定状态

列表只返回当前 `Units_Hash_Table` 中存在的绑定，记录：

- `binding_state = bound`
- `binding_origin = runtime | restored | mock`

其中：

- `runtime`：本次运行期间通过 bind/rebind 加入。
- `restored`：启动时从备份文件恢复。
- `mock`：通过 `-mockRobots` 注册。

### 4.3 连接状态

`connection_state` 只能是：

- `online`：Mock 已注册，或最近一次主动状态 RPC 成功。
- `offline`：启用真实 RPC 后，最近一次主动探测明确出现连接/传输失败。
- `unknown`：尚未探测、仅从备份恢复、真实 RPC 被禁用，或无法安全判断。

禁止把 `SAU_ENABLE_REAL_RPC` 未开启解释为离线。

`last_seen_ms` 只在状态获取成功时更新。失败时保留上次成功时间，并更新 `last_error`。

### 4.4 状态新鲜度

`status_freshness` 只能是：

- `fresh`：状态年龄不超过默认 3000 ms。
- `stale`：有历史状态，但已超过新鲜度阈值。
- `unavailable`：尚无成功状态。

列表接口默认只读取缓存，不批量触发真实 RPC，避免单个失联智能体阻塞 Qt 主线程和整份列表。

## 5. 别名规则

### 5.1 格式

别名经过以下处理：

1. 去除首尾空白。
2. 执行 Unicode NFKC 兼容归一化。
3. 使用 Unicode case folding 生成唯一性比较键。

允许中文、英文、数字、内部空格、连字符和下划线。

禁止：

- 空名称。
- 归一化后超过 32 个字符。
- 控制字符、换行符。
- 英文逗号，因为现有批量工具使用 CSV 参数。

### 5.2 唯一性

归一化后的别名不得与以下名称冲突：

- 当前和持久化记录中的其他别名。
- 当前和持久化记录涉及的 `unit_id`。
- MCP `robots.json` 中的全部 `robot_id`。

Qt 始终校验 UID 和别名冲突。MCP 调用设置别名接口时必须同时提交当前旧 `robot_id` 列表，Qt 通过 `reserved_names` 参数完成最终校验。

如果以后修改 `robots.json` 或接入新的 UID，导致它与已有别名冲突，规范标识始终优先使用 `unit_id`。MCP 必须报告 `identity_namespace_conflict` 并拒绝猜测解析，直到管理员通过 UID 重命名冲突别名。

### 5.3 生命周期

- 同一智能体再次设置别名表示原子重命名。
- unbind 后别名记录继续保留，重新 bind 时自动恢复。
- 未绑定智能体不能设置新别名。
- 已持久化但当前未绑定的智能体允许通过 UID 清除别名。
- 清除后 `display_name` 回退为 `unit_id`。

## 6. Qt 模块设计

### 6.1 AgentDirectory

目录：`SAU/Console/agents/identity/`

职责：

- 保存线程安全的绑定目录镜像。
- 管理别名查询、解析和唯一性校验。
- 接收启动、bind、rebind、unbind 和 Mock 注册事件。
- 向状态模块和 HTTP 模块提供只读目录快照。

主要接口：

```cpp
QVector<AgentBinding> listBindings() const;
AgentLookupResult findByUnitId(const QString &unitId) const;
AgentLookupResult resolveName(const QString &name) const;
AliasMutationResult setAlias(
    const QString &unitId,
    const QString &alias,
    const QStringList &reservedNames);
AliasMutationResult clearAlias(const QString &unitId);
void replaceBindings(const QVector<AgentBinding> &bindings);
void upsertBinding(const AgentBinding &binding);
void removeBinding(const QString &unitId);
```

`AgentDirectory` 不直接调用 IDL，也不直接处理 HTTP。

### 6.2 AliasStore

文件：`AgentAliases.json`，默认位于 Qt Console 当前工作目录，与现有备份文件策略保持一致。

文件结构：

```json
{
  "schema_version": 1,
  "aliases": [
    {
      "unit_id": "GV1",
      "alias": "先锋车",
      "updated_at_ms": 1782864000000
    }
  ]
}
```

写入使用 `QSaveFile`，保证替换过程原子化。

若文件无法解析：

- 保留原文件。
- 复制为带时间戳的损坏备份。
- 以空别名表启动。
- 向日志记录明确错误。

### 6.3 AgentStatusService

目录：`SAU/Console/agents/status/`

职责：

- 选择 Mock、Ground 或 Air 状态探测器。
- 将不同 IDL 返回值统一为 JSON 状态模型。
- 维护最后成功状态、最后错误和时间。
- 计算 `connection_state` 与 `status_freshness`。
- 单个智能体失败时返回局部失败，不影响其他智能体。

探测器：

- `MockStatusProbe`
- `GroundStatusProbe`
- `AirStatusProbe`

真实 RPC 继续受 `SAU_ENABLE_REAL_RPC=1` 控制。

所有 ILU 调用仍由现有 Qt 主线程执行策略约束；状态模块不自行创建跨线程 ILU 调用。

### 6.4 AgentHttpController

目录：`SAU/Console/agents/http/`

职责：

- 解析 `/api/agent/*` 请求。
- 调用 `IAgentDirectory` 和 `IAgentStatusService`。
- 返回现有统一 JSON envelope。
- 不直接访问 Qt UI。
- 不直接维护别名文件。

## 7. HTTP API v1

### 7.1 通用响应

```json
{
  "success": true,
  "message": "ok",
  "data": {}
}
```

### 7.2 列出全部智能体

```text
GET /api/agent/list
```

返回缓存状态，不主动批量探测真机。

```json
{
  "success": true,
  "message": "ok",
  "data": {
    "schema_version": "1.0",
    "generated_at_ms": 1782864000000,
    "agents": [
      {
        "unit_id": "GV1",
        "alias": "先锋车",
        "display_name": "先锋车",
        "unit_type": "ground",
        "binding_state": "bound",
        "binding_origin": "mock",
        "connection_state": "online",
        "status_freshness": "fresh",
        "mock": true,
        "run_mode": "sim",
        "role": "leader",
        "pose": {"x": 1.0, "y": 2.0, "yaw": 0.5},
        "speed": {"linear_m_s": 0.2, "angular_rad_s": 0.0},
        "battery_percent": null,
        "health": null,
        "last_seen_ms": 1782863999000,
        "observed_at_ms": 1782863999000,
        "last_error": null,
        "capabilities": ["pose", "speed", "role"]
      }
    ],
    "summary": {
      "total": 1,
      "online": 1,
      "offline": 0,
      "unknown": 0,
      "mock": 1,
      "real": 0
    }
  }
}
```

### 7.3 获取单个智能体状态

```text
GET /api/agent/status?agent=先锋车&refresh=1
```

- `agent` 可为 UID 或 Qt 别名。
- 兼容接受 `unit_id` 查询参数。
- `refresh=1` 表示执行一次主动状态探测。
- `refresh=0` 表示只返回缓存。
- 真实 RPC 被禁用时仍返回 HTTP 200 和智能体记录，其中 `connection_state=unknown`、`status_freshness=unavailable|stale`，并通过 `last_error` 说明未执行刷新。

### 7.4 设置或重命名别名

```text
POST /api/agent/alias/set
```

```json
{
  "agent": "GV1",
  "alias": "先锋车",
  "reserved_names": ["robot_1", "robot_2", "robot_3"]
}
```

成功返回规范 UID、最终别名和更新时间。

### 7.5 清除别名

```text
POST /api/agent/alias/clear
```

```json
{
  "agent": "先锋车"
}
```

当前未绑定但具有持久化别名的记录，只能通过 UID 清除。

### 7.6 HTTP 错误

| HTTP 状态 | 错误语义 |
| --- | --- |
| 400 | JSON、字段或别名格式无效 |
| 404 | 智能体或别名不存在 |
| 409 | 别名冲突 |
| 500 | 持久化或内部错误 |

列表和状态接口不会因为单个状态不可用返回 503；它们返回 `connection_state=unknown` 和局部错误。

## 8. MCP 模块设计

目录：`mcp/agents/`

### 8.1 AgentApiClient

封装 Qt `/api/agent/*` 路由，验证 envelope 和 `schema_version`。

### 8.2 AgentResolver

统一解析顺序：

1. 精确匹配 Qt `unit_id`。
2. 匹配 Qt 持久化别名。
3. 匹配 `robots.json` 中的旧 `robot_id`。
4. 将结果规范为唯一 `unit_id`。

目录缓存默认有效 2000 ms。解析未命中时必须强制刷新一次，避免刚接入的智能体被错误判定为不存在。

所有并发锁最终以 `unit_id` 为键，确保通过 UID、别名或旧 `robot_id` 操作同一智能体时共享同一把锁。

### 8.3 AgentService

提供：

- 目录查询。
- 单体状态查询。
- 批量状态查询。
- 设置、重命名和清除别名。
- 旧名称兼容。

### 8.4 MCP 工具

新增：

```text
list_agents()
get_agent_status(agent, refresh=true)
get_all_agent_status(refresh=true)
set_agent_alias(agent, alias)
clear_agent_alias(agent)
```

行为：

- `list_agents()` 快速返回 Qt 全部绑定和缓存状态。
- `get_agent_status()` 默认主动刷新一个智能体。
- `get_all_agent_status()` 在 MCP 总超时预算内逐项刷新并返回部分成功结果。
- 批量查询只要成功获取 Qt 目录，就返回可用列表；单体失败记录在 item 和 summary 中。
- 设置或清除别名后立即失效 MCP 目录缓存。

现有工具继续保留：

- `list_robots` 兼容映射到新目录。
- `get_robot_status` 兼容映射到新单体状态。
- 所有控制、任务和编队工具在执行前使用 `AgentResolver`。

## 9. 三人完全隔离的并行开发方案

### 9.1 并行开发前的契约冻结

集成人先创建并锁定：

```text
SAU/Console/agents/contracts/AgentContracts.h
docs/contracts/agent-api-v1.md
contracts/agent-api-v1/*.json
```

三名开发人员只能消费这些契约，不能在并行阶段修改它们。

当前项目根目录没有 Git 元数据。正式并行前应先初始化 Git 并建立三个独立 worktree；如果暂不使用 Git，必须复制成三个独立工作目录。

### 9.2 成员一：智能体目录与别名

独占目录：

```text
SAU/Console/agents/identity/
SAU/Console/tests/agent_identity/
```

交付：

- `AgentDirectory`
- `AliasStore`
- `AgentNameNormalizer`
- 别名单元测试
- 一份集成说明

并行阶段禁止修改：

- `console.cpp`
- `console.pro`
- `HttpApiExecutor.*`
- `mcp/*`

成员一通过契约中的绑定快照输入完成测试，不直接读取 `Units_Hash_Table`。

### 9.3 成员二：状态与 HTTP 控制器

独占目录：

```text
SAU/Console/agents/status/
SAU/Console/agents/http/
SAU/Console/tests/agent_status_api/
```

交付：

- 三类状态探测器
- `AgentStatusService`
- `AgentHttpController`
- HTTP 契约测试
- 一份集成说明

并行阶段禁止修改：

- `console.cpp`
- `console.pro`
- `HttpApiExecutor.*`
- `mcp/*`
- 成员一目录

成员二使用假的 `IAgentDirectory` 测试 HTTP，不等待成员一实现。

### 9.4 成员三：MCP 智能体能力

独占目录：

```text
mcp/agents/
mcp/tests/agents/
```

交付：

- `AgentApiClient`
- `AgentResolver`
- `AgentService`
- `register_agent_tools()`
- Python 单元和契约测试
- 一份集成说明

并行阶段禁止修改：

- `mcp/main.py`
- `mcp/robot_adapter.py`
- `mcp/config.py`
- `SAU/*`

成员三只依赖冻结的 JSON fixtures，不需要 Qt 运行。

### 9.5 并行工作依赖关系

契约冻结后，三部分不存在源码依赖：

```text
成员一 -> 只依赖 AgentContracts.h
成员二 -> 依赖 AgentContracts.h + fake directory
成员三 -> 只依赖 HTTP JSON fixtures
```

并行期间不互相 cherry-pick，不修改共享核心文件。

## 10. 统一整合阶段

三部分分别通过独立测试后，由一名集成人执行：

1. 将成员一、二的新 Qt 文件加入 `console.pro`。
2. 在 Console 启动后加载 `AgentAliases.json`。
3. 将启动恢复的 `Units_Hash_Table` 转成初始绑定快照。
4. 在 bind、rebind、unbind 和 Mock 注册流程中更新 `AgentDirectory`。
5. 在 `HttpApiExecutor` 中将 `/api/agent/*` 委托给 `AgentHttpController`。
6. 补齐 HTTP 409 状态行，并保持现有控制接口的 503 状态行映射。
7. 在 `mcp/config.py` 增加新路由常量。
8. 在 `mcp/main.py` 调用 `register_agent_tools()`。
9. 在 `robot_adapter.py` 接入 `AgentResolver`。
10. 将旧 `list_robots`、`get_robot_status` 兼容到新服务。
11. 运行 Qt 编译、Python 全量测试和 Mock 端到端测试。

共享核心文件只在这一阶段由集成人修改，避免并行冲突。

## 11. 测试设计

### 11.1 成员一测试

- 中文别名保存和恢复。
- 大小写和 NFKC 冲突。
- UID 冲突。
- 旧 `robot_id` 保留名称冲突。
- 原子重命名。
- 清除别名。
- unbind 后别名保留。
- 损坏文件备份和恢复。
- 并发读取与修改。

### 11.2 成员二测试

- Ground、Air、Mock 字段转换。
- Mock 状态为在线。
- RPC 禁用为未知。
- 探测成功转在线。
- 明确传输失败转离线。
- fresh/stale/unavailable 计算。
- 单体失败不破坏列表。
- 四个 HTTP 路由的成功和失败响应。
- JSON 输出与冻结 fixtures 一致。

### 11.3 成员三测试

- UID、别名和旧 `robot_id` 解析。
- 动态未配置智能体解析。
- 缓存命中、过期和未命中刷新。
- 设置别名时提交全部保留名称。
- 设置和清除后缓存失效。
- 批量状态部分成功。
- Qt 不可达和超时。
- 所有旧控制工具通过别名解析到同一 UID。

### 11.4 整合测试

Mock 启动：

```text
console -httpPort 9001 -mockRobots GV1,GV2,GV3
```

验收流程：

```text
list_agents
-> set_agent_alias(GV1, "先锋车")
-> set_agent_alias(GV2, "跟随车")
-> list_agents
-> get_agent_status("先锋车")
-> send_move("先锋车", ...)
-> stop_robot("先锋车")
-> 重启 Qt Console
-> list_agents 确认别名恢复
```

冲突流程：

```text
set_agent_alias(GV1, "先锋车") -> success
set_agent_alias(GV2, "先锋车") -> 409
set_agent_alias(GV2, "robot_1") -> 409
set_agent_alias(GV2, "GV1") -> 409
```

## 12. 兼容性

- 保留现有 `/api/robot/list` 和 `/api/robot/status`。
- 保留现有 MCP 工具名称。
- `robots.json` 继续提供旧 `robot_id -> unit_id` 兼容映射和部署意图。
- 新接入且不在 `robots.json` 的智能体仍可通过 UID 或 Qt 别名操作。
- 不改变现有速度安全校验和真机 RPC 开关。

## 13. 本阶段不包含

- 不修改 IDL 文件或重新生成 ILU 桩。
- 不实现物理智能体内部昵称同步。
- 不实现健康度和电量的新遥测链路。
- 不实现后台心跳协议。
- 不新增 Qt 可视化别名编辑界面。
- 不自动删除 `BackupFile.txt` 中的历史绑定。
- 不改变现有编队、任务和安全控制语义。

## 14. 风险与处理

### 历史绑定不等于在线

通过 `binding_state` 与 `connection_state` 分离解决，默认状态为未知。

### 真机 RPC 可能阻塞 Qt

列表只读缓存；主动刷新限定为单体接口。批量刷新由 MCP 在总超时预算内组织，并允许部分成功。

### 旧 IDL 昵称接口为空实现

本阶段完全不调用该接口。别名是 Qt 控制面的元数据。

### 多人修改冲突

并行阶段只新增各自独占目录，所有共享文件由集成人在最后统一修改。

### 当前项目没有 Git

并行编码前必须建立 Git 分支/worktree，或使用三个独立目录，并保留一份只用于整合的主目录。

## 15. 验收标准

- MCP 能列出 Qt 当前绑定表的全部智能体。
- 每个智能体都有明确的绑定状态、连接状态和状态新鲜度。
- Mock 能返回位姿和速度；真实智能体在允许 RPC 时可主动查询。
- 别名持久化、唯一且可重命名、清除。
- Qt 重启后别名恢复。
- 所有 MCP 查询、控制、任务和编队工具都可使用别名。
- 动态接入且未配置在 `robots.json` 的智能体可以被查询和控制。
- 旧 API 和旧 MCP 工具继续可用。
- 三个独立模块分别通过测试后可以由集成人统一接线。
- Python 全量测试、Qt 编译和三车 Mock 端到端流程全部通过。
