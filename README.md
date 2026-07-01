# 基于 MCP 与 IDL 的多机器人自然语言控制系统 — 验收交付说明

## 1. 模块分层
- L1 交互层：deepseek_mcp_client.py（Agent Loop + LLM）
- L2 协议层：main.py（FastMCP stdio，11 个工具）
- L3 适配层：robot_adapter.py + qt_http_client.py
- L4 配置：config.py、robots.json、utils/logging_setup.py
- 执行层（外部）：SAU Console HttpPlugin :9001 → IDL/ILU

## 快速验证
pip install -r requirements.txt
pytest tests/ -q
fastmcp call main.py list_robots --json
（需先启动 SAU 主控 -httpPort 9001 或 -mockRobots）
## 2. 系统分层与模块对应



| 层次 | 职责 | 本交付包中的路径 |
|------|------|------------------|
| **L1 交互层** | 自然语言 → Agent Loop → 调用 MCP 工具 | `mcp/deepseek_mcp_client.py` |
| **L2 协议层** | FastMCP 工具注册、stdio 服务 | `mcp/main.py` |
| **L3 适配层** | ID 映射、速度校验、锁、HTTP 封装、编队几何 | `mcp/robot_adapter.py`、`mcp/qt_http_client.py` |
| **L4 配置与基础设施** | 端点、阈值、机器人映射、日志 | `mcp/config.py`、`mcp/robots.json`、`mcp/utils/logging_setup.py` |
| **L5 执行层（Qt/IDL）** | HTTP 接入、Mock/RPC 分流、ILU 桩 | `SAU/Console/`（`HttpPlugin`、`HttpApiExecutor`、`stubs/`、`MockRobotSimulator` 等） |

**数据流（简要）**：

```text
用户 NL → deepseek_mcp_client (L1)
       → fastmcp call → main.py (L2)
       → robot_adapter + qt_http_client (L3)
       → HTTP :9001 → SAU Console (L5)
       → Mock 模拟器 或 IDL/ILU 桩 → 设备
       → 统一 JSON (success/message/data) 回传
```

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
│   ├── utils/logging_setup.py
│   ├── requirements.txt      Python 依赖
│   ├── tests/                单元测试
│   ├── bench_fast_fail.py    503 快速失败基准（可选）
│   ├── test_stage_a3.py      TC-04 相关（可选）
│   ├── test_stage_b.py       联调脚本（可选）
│   └── logs/                 运行日志（验收包可只保留空目录或脱敏样例）
└── SAU/                      ← Qt 主控 + ILU 运行时（执行层）
    ├── Console/              主控源码（console.pro、HttpApiExecutor 等）
    ├── Console/stubs/        IDL 生成桩
    └── Ilu/                  ILU 库与头文件（运行依赖）
```

**说明**：日常联调对接的是 **SAU 主控 HTTP（默认 `127.0.0.1:9001`）**，不是 `mcp/qt_http_server` 演示工程。若交付包中含 `qt_http_server/`，仅作可选参考，**非毕设主链路**。

---

## 4. MCP 工具清单（`main.py` 注册）

| 类别 | 工具名 | 作用 |
|------|--------|------|
| 基础控制 | `send_move` | 线速度/角速度/持续时间 |
| | `stop_robot` | 单车停止 |
| | `emergency_stop_all` | 全车队停止 |
| 状态感知 | `list_robots` | 绑定表 + run_mode（sim/real） |
| | `get_robot_status` | 单车位姿与速度 |
| | `get_fleet_status` | 批量状态 |
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

在 Qt Creator 或命令行编译运行 `SAU/Console/console.pro`：

- Mock 多车：`main_console -mockRobots -httpPort 9001`
- 真车 RPC：启动前设置 `SAU_ENABLE_REAL_RPC=1`

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

### 5.5 自然语言端到端（需 LLM API）

```powershell
cd mcp

set SILICONFLOW_API_KEY=你的密钥
python deepseek_mcp_client.py
python main.py
```

---

## 6. 测试与验证边界（与论文一致）

| 场景 | 环境 | 结论粒度 |
|------|------|----------|
| 多车编队、XY2D 闭环 | Mock（`-mockRobots`） | 系统级闭环，**非**真机精度 |
| 越界速度 TC-06 | MCP + Qt 双层校验 | 返回 `speed_out_of_bounds` |
| RPC 关闭 TC-04 | 真实单元 + 未设 `SAU_ENABLE_REAL_RPC` | HTTP **503**，**不执行**运动 |
| 真车 TC-07 | 单台 GV1、无 GPS、RPC 开启 | 仅证明链路 `accepted`，开环相对运动 |

**Mock 结论不可外推为真机定点能力。**

---

## 7. 打包清单



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




---



