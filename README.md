# 基于 MCP 与 IDL 的多机器人自然语言控制系统 — 验收交付说明

## 1. 模块分层
- L1 交互层：deepseek_mcp_client.py（Agent Loop + DeepSeek LLM，支持 deepseek-v4-flash / deepseek-v4-pro）
- L2 协议层：main.py（FastMCP stdio，生产模式固定 12 个任务级工具）
- L3 适配层：task_api/ + console_client/ + robot_adapter.py + qt_http_client.py（契约、别名解析、安全校验）
- L4 配置：config.py、robots.json、utils/logging_setup.py
- L5 安全层：mcp/safety/validator.py（Python）+ SafetyValidator.cpp（C++）双层校验
- 执行层（外部）：SAU Console HttpPlugin :9001 → IDL/ILU

MCP-IDL 任务级接口契约：`mcp/idl/mcp_swarm_task.idl`

## 快速验证
pip install -r requirements.txt
pytest tests/ -q
fastmcp call main.py getCapabilities --json
（需先启动 SAU 主控 -httpPort 9001 -mockRobots GV1,GV2,GV3）
## 2. 系统分层与模块对应



| 层次 | 职责 | 本交付包中的路径 |
|------|------|------------------|
| **L1 交互层** | 自然语言 → Agent Loop → 调用 MCP 工具 | `mcp/deepseek_mcp_client.py` |
| **L2 协议层** | FastMCP 工具注册、stdio 服务 | `mcp/main.py` |
| **L3 适配层** | ID 映射、别名解析、速度校验、锁、HTTP 封装、编队几何 | `mcp/robot_adapter.py`、`mcp/qt_http_client.py`、`mcp/agents/` |
| **L4 配置与基础设施** | 端点、阈值、机器人映射、日志 | `mcp/config.py`、`mcp/robots.json`、`mcp/utils/logging_setup.py` |
| **L5 安全层** | Python + C++ 双层参数与业务校验 | `mcp/safety/validator.py`、`SAU/Console/SafetyValidator.cpp` |
| **L6 执行层（Qt/IDL）** | HTTP 接入、TaskManager 状态机、Mock/RPC 分流、ILU 桩 | `SAU/Console/`（`HttpApiExecutor`、`TaskManager`、`stubs/`、`MockRobotSimulator` 等） |

**数据流（简要）**：

```text
用户 NL → deepseek_mcp_client (L1)
       → fastmcp call → main.py (L2)
       → robot_adapter（别名解析 + 安全预检）+ qt_http_client (L3)
       → HTTP :9001 → SAU Console TaskManager + SafetyValidator (L5/L6)
       → Mock 模拟器 或 IDL/ILU 桩 → 设备
       → 统一 JSON (success/message/data) 回传
```

**核心设计原则**：

> 旧 IDL 是 Console 控制智能体的底层协议；新 MCP-IDL 是大模型控制 Console 的任务级协议。生产模式下大模型只调用 `getCapabilities`、`getFleetSnapshot`、`navigateTo`、`followPath`、静态/持续编队和任务管理接口；Console 再转换为既有底层 IDL/ILU RPC。

---

## 3. 目录结构说明

```text
项目文件/
├── README.md                 ← 本文件
├── mcp/                      ← Python MCP 子系统（验收核心之一）
│   ├── main.py               L2 协议层入口
│   ├── deepseek_mcp_client.py L1 交互层
│   ├── robot_adapter.py      L3 适配层
│   ├── qt_http_client.py     L3 HTTP 客户端
│   ├── config.py             L4 配置
│   ├── robots.json           L4 机器人映射
│   ├── idl/
│   │   └── mcp_swarm_task.idl   MCP-IDL 任务级接口契约
│   ├── agents/               L3 智能体子系统
│   │   ├── agent_resolver.py    别名解析
│   │   ├── agent_service.py     智能体服务
│   │   ├── agent_tools.py       MCP 别名工具
│   │   └── agent_api_client.py  Console HTTP 客户端
│   ├── safety/
│   │   └── validator.py      L5 Python 侧安全校验
│   ├── utils/logging_setup.py
│   ├── requirements.txt      Python 依赖
│   ├── tests/                单元测试 + 集成测试
│   │   ├── test_agent_system.py    智能体/别名单元测试
│   │   ├── test_api_full.py        HTTP API 全量测试
│   │   ├── test_api_v2.py          HTTP API v2 测试
│   │   ├── test_mcp_tools.py       MCP 工具层测试
│   │   ├── test_deepseek_mcp_client.py  Agent Loop 护栏测试
│   │   ├── test_siliconflow_api.py DeepSeek API 连通性测试
│   │   ├── test_robot_adapter.py   适配层测试
│   │   └── demo_nl_control.py      自然语言驱动演示
│   ├── bench_fast_fail.py    503 快速失败基准（可选）
│   ├── test_stage_a3.py      TC-04 相关（可选）
│   ├── test_stage_b.py       联调脚本（可选）
│   └── logs/                 运行日志（验收包可只保留空目录或脱敏样例）
└── SAU/            ← Qt 主控 + ILU 运行时（执行层）
    ├── Console/              主控源码
    │   ├── console.pro             Qt 项目（已配置 MSVC /utf-8）
    │   ├── HttpApiExecutor.cpp     HTTP 路由 + 任务执行
    │   ├── TaskManager.cpp/h       任务状态机 + 审计日志
    │   ├── SafetyValidator.cpp/h   安全校验
    │   ├── MockRobotSimulator.cpp/h 模拟车运动学
    │   ├── agents/
    │   │   ├── identity/           别名存储/规范化/目录
    │   │   ├── status/             状态探针
    │   │   ├── http/               Agent HTTP 路由
    │   │   └── contracts/          接口契约
    │   └── stubs/              IDL 生成桩
    ├── Console/tests/         测试项目
    ├── Monitor/               监控端
    └── Ilu/                   ILU 库与头文件（运行依赖）
```

**说明**：日常联调对接的是 **SAU 主控 HTTP（默认 `127.0.0.1:9001`）**，不是 `mcp/qt_http_server` 演示工程。若交付包中含 `qt_http_server/`，仅作可选参考，**非毕设主链路**。

---

## 4. MCP 工具清单（`main.py` 注册）

| 类别 | 工具名 | 作用 |
|------|--------|------|
| 能力/车队 | `getCapabilities` | 返回八项真实能力及限制原因 |
| | `getFleetSnapshot` | 返回 mock/real、online、busy、rpc_available |
| 单车任务 | `navigateTo` | 使用既有 `setTaskPoint(x,y)` 导航 |
| | `followPath` | 使用既有 `setTaskPath`，按最终点判断完成 |
| 静态编队 | `createStaticFormation` | 旋转/平移几何目标并逐车导航 |
| 持续跟随 | `createFollowFormation` | 建立限定成员的 Leader/Follower/Formation/Follow 关系 |
| | `moveFollowFormation` | 只向当前 Leader 下发目标点 |
| | `getFormationStatus` | 查询 IDLE/CREATING/READY/MOVING/FAILED |
| | `disbandFormation` | 解散当前持续跟随关系 |
| 任务管理 | `getTaskStatus` | 查询父任务与逐车状态 |
| | `cancelTask` | 取消状态机并请求 Stop，返回取消效果 |
| | `stopUnits` | 只发送停止动作，不取消任务或解散编队 |

低层和旧 snake_case 工具仅在 `MCP_EXPOSE_LOW_LEVEL_TOOLS=1` 时用于调试，默认不注册到生产 MCP 工具列表。

---

## 5. 环境安装与快速验证

### 5.1 Python 依赖

```powershell
cd mcp
pip install -r requirements.txt
```

### 5.2 启动 SAU 主控（执行层）

在 Qt Creator 或命令行编译运行 `SAU/Console/console.pro`：

- Mock 多车：`main_console -httpPort 9001 -mockRobots GV1,GV2,GV3`
- 真车 RPC：启动前设置 `SAU_ENABLE_REAL_RPC=1`

**编译注意**：源码为 UTF-8 无 BOM，中文 locale 下 MSVC 需 `/utf-8` flag（已在 `console.pro`、`tests/tests.pro`、`Monitor/Monitor.pro` 中配置）。

`mcp/config.py` 中 `QT_HTTP_BASE` 需与主控端口一致（默认 `http://127.0.0.1:9001`）。

### 5.3 单元测试（不依赖大模型）

```powershell
cd mcp
pytest tests/ -q
```

### 5.4 MCP 工具联调（不经过 LLM）

```powershell
cd mcp
fastmcp call main.py getCapabilities --json
fastmcp call main.py send_move --json robot_id=robot_1 linear_velocity=0.2 angular_velocity=0.0 duration_ms=1000
```

### 5.5 HTTP API 直接测试（curl，不依赖 MCP）

```powershell
# 单点导航
curl -X POST http://127.0.0.1:9001/api/task/goto_pose -H "Content-Type: application/json" -d "{\"unit_id\":\"GV1\",\"x\":3.0,\"y\":5.0,\"tolerance_m\":0.15,\"timeout_ms\":30000}"

# 批量导航
curl -X POST http://127.0.0.1:9001/api/task/goto_pose_batch -H "Content-Type: application/json" -d "{\"targets\":[{\"unit_id\":\"GV1\",\"x\":1,\"y\":0},{\"unit_id\":\"GV2\",\"x\":2,\"y\":0}],\"tolerance_m\":0.15,\"timeout_ms\":30000}"

# 编队
curl -X POST http://127.0.0.1:9001/api/formation/execute -H "Content-Type: application/json" -d "{\"formation_type\":\"line\",\"unit_ids\":[\"GV1\",\"GV2\",\"GV3\"],\"spacing_m\":1.0,\"tolerance_m\":0.15,\"timeout_ms\":30000}"

# 查询/取消
curl "http://127.0.0.1:9001/api/task/status?task_id=goto-xxx"
curl -X POST http://127.0.0.1:9001/api/task/cancel -H "Content-Type: application/json" -d "{\"task_id\":\"goto-xxx\"}"
```

### 5.6 自然语言端到端（需 DeepSeek API）

本系统使用 **DeepSeek 官方 API** 作为 LLM 后端，支持以下模型：

| 模型 | 说明 |
|------|------|
| `deepseek-v4-flash`（默认） | 快速推理，适合日常联调 |
| `deepseek-v4-pro` | 更强推理能力，适合复杂编队任务 |

**Step 1: 获取 API Key**

访问 [platform.deepseek.com](https://platform.deepseek.com) 注册并获取 API Key。

**Step 2: 配置密钥（二选一）**

方式一：设置环境变量（推荐）
```powershell
setx DEEPSEEK_API_KEY "sk-你的密钥"
```
> 注意：`setx` 只对新终端生效。当前终端可先用 `set DEEPSEEK_API_KEY=sk-你的密钥`。

方式二：直接写入代码默认值

编辑 `mcp/deepseek_mcp_client.py` 第 38 行：
```python
DEFAULT_DEEPSEEK_API_KEY = "sk-你的密钥"
```

**Step 3: 启动**

```powershell
cd mcp

# 使用默认模型 (deepseek-v4-flash)
python deepseek_mcp_client.py

# 使用更强模型
python deepseek_mcp_client.py --model deepseek-v4-pro
```

**Step 4: 测试连通性（可选）**

```powershell
python tests/test_siliconflow_api.py
```

**交互示例**：

```
User> 查看当前有哪些机器人
[Agent] Calling tool: list_robots({})
[Agent] 车队运行态: GV1(模拟), GV2(模拟), GV3(模拟)

User> 让所有小车排成一排，间距 1 米
[Agent] Calling tool: plan_line_targets(robot_ids_csv="GV1,GV2,GV3", spacing_m=1.0)
...

User> 紧急停止
[Agent] Calling tool: emergency_stop_all({})
[Agent] Task Done: 所有车辆已紧急停止
```

---

## 6. 任务状态机与错误码

### 6.1 任务状态

```
PENDING → RUNNING → COMPLETED           (全部成功)
                 → PARTIAL_COMPLETED     (部分成功)
                 → FAILED                (全部失败)
                 → TIMEOUT               (超时)
                 → CANCELLED             (被取消)
                 → REJECTED              (安全校验拒绝)
```

### 6.2 统一错误码（mcp_swarm_task.idl 定义）

`ERR_OK` / `UNIT_NOT_FOUND` / `UNIT_OFFLINE` / `UNIT_BUSY` / `TARGET_OUT_OF_BOUNDS` / `TARGET_IN_NOGO_ZONE` / `SPEED_OUT_OF_BOUNDS` / `DISTANCE_TOO_FAR` / `LOW_BATTERY` / `TASK_NOT_FOUND` / `TASK_ALREADY_CANCELLED` / `SAFETY_REJECTED` / `INTERNAL_ERROR` / `RPC_DISABLED`

---

## 7. 测试与验证边界（与论文一致）

| 场景 | 环境 | 结论粒度 |
|------|------|----------|
| goto_pose → COMPLETED | Mock（`-mockRobots GV1,GV2,GV3`） | 系统级闭环，含运动学模拟 |
| goto_pose → TIMEOUT | Mock | 超时自动终止 |
| goto_pose_batch 多车并发 | Mock | 子任务独立管理 |
| execute_formation LINE/COLUMN/TRIANGLE | Mock | 编队目标计算 + 全部完成 |
| 别名设置 → 解析 → 任务下发 | Mock | 全链路闭环 |
| 越界速度 TC-06 | MCP + Qt 双层校验 | 返回 `SPEED_OUT_OF_BOUNDS` |
| 越界参数 (tolerance/timeout/coord) | MCP + Qt 双层校验 | 返回 `SAFETY_REJECTED` |
| unit 忙碌拒绝 | Mock | 返回 `UNIT_BUSY` |
| RPC 关闭 TC-04 | 真实单元 + 未设 `SAU_ENABLE_REAL_RPC` | HTTP **503**，**不执行**运动 |
| 真车 TC-07 | 单台 GV1、无 GPS、RPC 开启 | 仅证明链路 `accepted`，开环相对运动 |

**Mock 结论不可外推为真机定点能力。**

---

## 8. 打包清单



| 排除项 | 原因 |
|--------|------|
| `mcp/.pytest_cache/` | 测试缓存 |
| `mcp/.vscode/`、`SAU/.vscode/` | IDE 配置 |
| `mcp/deepseek_mcp_client.py.bak` | 历史备份 |
| `mcp/qt_http_server/build/` | 编译产物（若保留 qt_http_server 源码） |
| `SAU/build-console-*/` 等所有 `build-*` 目录 | Qt 编译产物 |
| `SAU/Console/.qtcreator/`、`.qtc_clangd/`、`*.pro.user*` | IDE 用户文件 |
| `SAU/Console/Makefile*`（本地 qmake 生成，可选删） | 可本地重新生成 |
| `mcp/logs/*.log` 全文 | 建议脱敏或只留空 `logs/` 目录 |
