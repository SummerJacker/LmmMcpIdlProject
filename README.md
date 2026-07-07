# 基于 MCP 与 IDL 的多机器人自然语言控制系统 — 验收交付说明

## 1. 模块分层
- L1 交互层：deepseek_mcp_client.py（Agent Loop + LLM）
- L2 协议层：main.py（FastMCP stdio，15+ 个工具）
- L3 适配层：robot_adapter.py + qt_http_client.py + agents/（别名解析、安全校验）
- L4 配置：config.py、robots.json、utils/logging_setup.py
- L5 安全层：mcp/safety/validator.py（Python）+ SafetyValidator.cpp（C++）双层校验
- 执行层（外部）：SAU Console HttpPlugin :9001 → IDL/ILU

MCP-IDL 任务级接口契约：`mcp/idl/mcp_swarm_task.idl`

## 快速验证
pip install -r requirements.txt
pytest tests/ -q
fastmcp call main.py list_robots --json
（需先启动 SAU 主控 -httpPort 9001 -mockRobots GV1,GV2,GV3）
## 2. 系统分层与模块对应



| 层次 | 职责 | 本交付包中的路径 |
|------|------|------------------|
| **L1 交互层** | 自然语言 → Agent Loop → 调用 MCP 工具 | `mcp/deepseek_mcp_client.py` |
| **L2 协议层** | FastMCP 工具注册、stdio 服务 | `mcp/main.py` |
| **L3 适配层** | ID 映射、别名解析、速度校验、锁、HTTP 封装、编队几何 | `mcp/robot_adapter.py`、`mcp/qt_http_client.py`、`mcp/agents/` |
| **L4 配置与基础设施** | 端点、阈值、机器人映射、日志 | `mcp/config.py`、`mcp/robots.json`、`mcp/utils/logging_setup.py` |
| **L5 安全层** | Python + C++ 双层参数与业务校验 | `mcp/safety/validator.py`、`SAU-cosnaming/Console/SafetyValidator.cpp` |
| **L6 执行层（Qt/IDL）** | HTTP 接入、TaskManager 状态机、Mock/RPC 分流、ILU 桩 | `SAU-cosnaming/Console/`（`HttpApiExecutor`、`TaskManager`、`stubs/`、`MockRobotSimulator` 等） |

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

> 旧 IDL 是 Console 控制智能体的底层协议；新 MCP-IDL 是大模型控制 Console 的任务级协议。大模型不直接调用底层 IDL，而是通过 MCP-IDL 调用高层任务接口（goto_pose / goto_pose_batch / execute_formation），再由 Console 转换到底层 IDL 控制智能体集群执行。

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
│   │   ├── test_mcp_tools.py       MCP 工具层测试
│   │   └── demo_nl_control.py      自然语言驱动演示
│   ├── bench_fast_fail.py    503 快速失败基准（可选）
│   ├── test_stage_a3.py      TC-04 相关（可选）
│   ├── test_stage_b.py       联调脚本（可选）
│   └── logs/                 运行日志（验收包可只保留空目录或脱敏样例）
└── SAU-cosnaming/            ← Qt 主控 + ILU 运行时（执行层）
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
| **任务级导航** | `goto_pose` | 单智能体导航到目标点，返回 task_id |
| | `goto_pose_batch` | 多智能体并发导航 |
| | `execute_formation` | 编队任务（line/column/triangle） |
| | `get_task_status` | 查询任务进度（含子任务状态） |
| | `cancel_task` | 取消运行中的任务 |
| 基础控制 | `send_move` | 线速度/角速度/持续时间 |
| | `stop_robot` | 单车停止 |
| | `emergency_stop_all` | 全车队停止 |
| 状态感知 | `list_robots` | 绑定表 + run_mode（sim/real） |
| | `get_robot_status` | 单车位姿与速度 |
| | `get_fleet_status` | 批量状态 |
| **别名管理** | `list_agents` | 智能体列表（含别名） |
| | `set_agent_alias` | 设置唯一别名 |
| | `clear_agent_alias` | 清除别名 |
| | `get_agent_status` | 查询智能体状态 |
| 任务辅助 | `compute_navigation_hint` | 到目标点导航提示 |
| | `compute_remaining_distance` | 两车间距 |
| | `compute_relative_pose` | 相对位姿 |
| | `plan_line_targets` | 直线编队目标点 |
| | `plan_triangle_targets` | 三角编队目标点 |

---

## 5. 环境安装与快速验证

### 5.1 Python 依赖

```powershell
cd mcp
pip install -r requirements.txt
```

### 5.2 启动 SAU 主控（执行层）

在 Qt Creator 或命令行编译运行 `SAU-cosnaming/Console/console.pro`：

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
fastmcp call main.py list_robots --json
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

### 5.6 自然语言端到端（需 LLM API）

```powershell
cd mcp

set SILICONFLOW_API_KEY=你的密钥
python deepseek_mcp_client.py
python main.py
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
