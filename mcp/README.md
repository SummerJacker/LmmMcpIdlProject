# MCP-Console 任务级编排控制系统

基于 **MCP (Model Context Protocol)** 与 **SAU Console** 融合的智能体集群任务编排系统。

> 用户只需说"对集群进行三角形编队"，系统自动完成：状态确认 → 领航者选择 → 跟随关系设置 → 队形下发 → 验证 → 就绪。

---

## 架构

```
用户自然语言 ("对集群进行三角形编队")
        ↓
   LLM (DeepSeek / Claude)
        ↓
   MCP Server (FastMCP, 34 tools)
        ↓
┌─ 任务级编排层 (orchestrator/) ─────────────────┐
│                                                 │
│  execute_formation_mission()                     │
│    └→ FormationMissionOrchestrator               │
│         ├─ check_fleet     查询集群状态          │
│         ├─ select_leader   自动选择领航者        │
│         ├─ set_leader      设置领航者            │
│         ├─ set_followers   设置跟随关系          │
│         ├─ set_formation   下发队形参数          │
│         └─ verify          验证编队建立          │
│                                                 │
│  move_active_formation()                        │
│    └→ 向全部编队成员并发下发 send_move           │
│                                                 │
│  TaskManager + ActiveFormationRegistry           │
│    └→ 状态机 + 子步骤追踪 + 失败回滚             │
└─────────────────────────────────────────────────┘
        ↓
   RobotAdapter
        ↓  HTTP (127.0.0.1:9001)
   SAU Console (C++ Qt + CORBA/ILU)
        ↓
   智能体集群 (Mock 模拟 / 真实车辆)
```

### 关键设计原则

> **大模型不直接调用底层工具** (`set_leader`, `set_follower`, `set_formation`)，
> 而是调用**任务级工具** (`execute_formation_mission`)，
> 由编排器自动完成内部多步流程。

---

## 项目结构

```
mcp/
├── main.py                          # FastMCP 服务入口 (34 tools)
├── config.py                        # 机器人配置、HTTP 端点、速度阈值
├── robot_adapter.py                 # MCP → Console HTTP 适配层
├── qt_http_client.py                # HTTP 请求封装
├── deepseek_mcp_client.py           # DeepSeek LLM MCP 客户端 (交互式)
├── e2e_test_live.py                 # 端到端实时测试脚本
│
├── orchestrator/                    # 任务级编排层
│   ├── formation_mission.py         # 编队任务编排器 (状态机驱动)
│   ├── task_manager.py              # 任务状态追踪 + 子步骤 + 回滚栈
│   └── active_formation.py          # 活跃编队状态记录
│
├── safety/                          # 安全校验层 (客户端侧预检)
│   └── validator.py                 # 导航/编队/移动/冲突校验
│
├── agents/                          # 智能体目录、状态与别名系统
│   ├── agent_api_client.py
│   ├── agent_resolver.py
│   ├── agent_service.py
│   └── agent_tools.py
│
├── utils/
│   └── logging_setup.py
│
└── tests/
    ├── test_formation_orchestrator.py   # 编排器单元测试 (11 cases)
    ├── test_robot_adapter.py
    ├── test_mcp_tools.py
    ├── test_agent_system.py
    ├── test_deepseek_mcp_client.py
    └── ...
```

---

## 快速开始

### 1. 启动 Console (SAU 主控台)

```powershell
# 从 Qt Creator 启动，或直接运行编译好的二进制
D:\projects\project\SAU\build-console-Desktop_Qt_5_12_4_MSVC2017_32bit-Profile\release\main_console.exe -mockRobots GV1,GV2,GV3
```

Console 启动后 HTTP 服务监听 `127.0.0.1:9001`。

### 2. 启动 MCP Server

```powershell
cd E:\MCP-IDL\mcp
python main.py
```

### 3. 运行 E2E 测试

```powershell
cd E:\MCP-IDL\mcp
python e2e_test_live.py
```

### 4. 使用 LLM 客户端交互

```powershell
$env:DEEPSEEK_API_KEY = "your-api-key"
python deepseek_mcp_client.py

User> 对集群进行三角形编队
User> 让编队向前移动
User> 查看编队状态
User> 取消编队
```

---

## 任务级工具 (LLM 可直接调用)

| 工具 | 说明 |
|------|------|
| `execute_formation_mission` | **一句话建立编队**。自动完成 6 步流程 |
| `move_active_formation` | 移动编队（向全部成员并发下发速度指令） |
| `stop_active_formation` | 停止编队（向全部成员并发下发停止指令） |
| `get_formation_status` | 查询活跃编队状态 |
| `cancel_formation_mission` | 取消编队 + 自动回滚配置 |

### 编队类型

| 类型 | 最少智能体 | 说明 |
|------|-----------|------|
| `line` | 2 | 直线编队 |
| `triangle` | 3 | 正三角形编队 |
| `column` | 2 | 纵队 |

### 调用示例

```json
// 最简单调用 — 全部使用默认值
{"tool": "execute_formation_mission", "args": {"formation_type": "triangle"}}

// 指定参数
{"tool": "execute_formation_mission", "args": {
    "formation_type": "triangle",
    "unit_ids_csv": "GV1,GV2,GV3",
    "leader_id": "GV1",
    "spacing_m": 1.5
}}

// 编队建立后移动
{"tool": "move_active_formation", "args": {
    "linear_velocity": 0.3,
    "duration_ms": 2000
}}

// 查询状态
{"tool": "get_formation_status", "args": {}}

// 取消编队
{"tool": "cancel_formation_mission", "args": {}}
```

---

## 底层工具 (内部使用，也可直接调用)

<details>
<summary>24 个底层工具列表</summary>

| 工具 | 说明 |
|------|------|
| `list_robots` | 列出已绑定单元 |
| `get_robot_status` | 查询单智能体状态 |
| `get_fleet_status` | 批量查询状态 |
| `send_move` | 发送速度指令 |
| `stop_robot` | 停止单智能体 |
| `emergency_stop_all` | 全停 |
| `set_leader` | 设置领航者 |
| `set_group_mode` | 设置编队主模式 |
| `set_group_minor_mode` | 设置编队次模式 |
| `set_task_point` | 设置任务点 |
| `set_task_path` | 设置任务路径 |
| `add_trap_point` | 添加陷阱点 |
| `clear_traps` | 清除陷阱点 |
| `reset_unit_relations` | 重置编队关系 |
| `goto_pose` | 单智能体导航 |
| `goto_pose_batch` | 多智能体并发导航 |
| `execute_formation` | 编队执行 (底层) |
| `get_task_status` | 查询任务进度 |
| `cancel_task` | 取消任务 |
| `compute_remaining_distance` | 计算剩余距离 |
| `compute_relative_pose` | 计算相对位姿 |
| `compute_navigation_hint` | 计算导航提示 |
| `plan_line_targets` | 规划直线编队点 |
| `plan_triangle_targets` | 规划三角形编队点 |
| + 5 个 Agent 管理工具 | |

</details>

---

## 编队编排器状态机

```
IDLE
  ↓
CHECKING_FLEET        → FAILED_NO_ENOUGH_UNITS / FAILED_UNIT_OFFLINE
  ↓
SELECTING_LEADER      (自动选择: 电池 > 位姿 > 任务状态 > 延迟)
  ↓
SETTING_LEADER        → FAILED_LEADER_SET_FAILED
  ↓
SETTING_FOLLOWERS     → FAILED_FOLLOWER_SET_FAILED
  ↓
SETTING_FORMATION     → FAILED_FORMATION_SET_FAILED
  ↓
VERIFYING             → FAILED_VERIFY_TIMEOUT
  ↓
READY                 ← 编队就绪，可移动
  ↓
MOVING                ← move_active_formation
  ↓
CANCELLED             ← cancel_formation_mission (自动回滚)
```

失败时自动回滚 (LIFO):
```
reset_unit_relations → set_group_mode(none)
```

---

## 安全校验层

客户端侧预检，与 Console 侧 `SafetyValidator` (C++) 形成双重校验：

| 校验函数 | 说明 |
|---------|------|
| `validate_formation_mission` | 编队任务参数 + 冲突检查 |
| `validate_move_formation` | 移动前检查编队就绪 |
| `validate_unit_available` | 智能体在线/故障检查 |
| `validate_formation_feasible` | 初始距离可行性检查 |
| `check_task_conflict` | 任务冲突检测 |
| `validate_goto_pose` | 导航参数校验 |
| `validate_goto_pose_batch` | 批量导航校验 |
| `validate_formation` | 编队基础参数校验 |

---

## 配置

### Console HTTP 端点 (`config.py`)

```python
QT_HTTP_BASE = "http://127.0.0.1:9001"
```

### 机器人列表 (`robots.json`)

```json
{
  "robots": [
    {"robot_id": "robot_1", "unit_id": "GV1", "mode": "sim"},
    {"robot_id": "robot_2", "unit_id": "GV2", "mode": "sim"},
    {"robot_id": "robot_3", "unit_id": "GV3", "mode": "sim"}
  ]
}
```

### 安全阈值

| 参数 | 值 |
|------|-----|
| 最大线速度 | 5.0 m/s |
| 最大角速度 | 10.0 rad/s |
| 目标最大距离 | 100 m |
| 默认工具超时 | 12 s |

---

## Mock vs 真实车辆

| | Mock 模拟 | 真实车辆 (CORBA RPC) |
|---|---|---|
| SBH 格式 | `MOCK:GV1` | CORBA IOR (`ilusbh:sau/...`) |
| 状态存储 | `MockRobotSimulator` 内存 | 车载控制器 |
| 编队配置 | MCP 侧直接设全局变量 | IIOP RPC 到车载控制器 |
| 编队移动 | MCP 显式向全员发 `send_move` | 只控制 leader，跟随者自动协同 |
| 运行模式 | `run_mode=sim` | `run_mode=real` |

---

## Console 编译

```powershell
# 前提: Qt 5.12.4 MSVC2017 32-bit + VS2017 Build Tools
cd E:\MCP-IDL\SAU-cosnaming
.\rebuild_console.bat
```

编译输出: `build-console-*/release/main_console.exe`

---

## 运行测试

```powershell
# 编排器单元测试 (11 cases, 模拟 Console)
cd E:\MCP-IDL\mcp
python -m pytest tests/test_formation_orchestrator.py -v

# 端到端测试 (需要 Console 运行)
python e2e_test_live.py
```
