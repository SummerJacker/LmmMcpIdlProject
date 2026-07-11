# MCP-IDL 车辆控制服务

FastMCP 将自然语言车辆指令转发到持续运行的 SAU Console。Console 是 Leader、跟随队形和实际生效间距的状态源。

## 编队的两种模式

### 1. Console 跟随编队

用于建立持续的 Leader/Follower 关系。流程与 Console 界面一致：

```text
设置 Leader
→ 按顺序录入 Followers 及各自相对前车的间距
→ 发送队形（Console::setFormationWithResult）
→ 设置目标点（只发给 Leader）
→ Followers 通过 Follow 逻辑自动跟随
```

MCP 工具：

- `set_leader(robot_id)`
- `send_follow_formation(leader_id, followers_json)`
- `get_formation_status()`
- `goto_follow_formation(x, y)`

`followers_json` 示例：

```json
[
  {"robot_id": "GV2", "distance_m": 0.3},
  {"robot_id": "GV3", "distance_m": 0.8}
]
```

Console 会把小于 `0.5m` 的地面跟随间距调整为 `0.5m`。响应同时包含请求间距与实际生效间距。

### 2. 几何编队

用于让多辆车分别导航到直线、三角形或纵队的几何位置，不建立持续跟随关系。

MCP 工具：

- `execute_geometric_formation(formation_type, unit_ids_csv, spacing_m, ...)`

旧工具 `execute_formation` 和 `execute_formation_mission` 仅保留兼容性，不应再用于 Console 跟随编队。

## 自然语言交互

模糊输入会先要求选择模式：

```text
用户：进行编队

Agent：
请选择编队类型：
1. Console 跟随编队
2. 几何编队
```

选择 Console 跟随编队：

```text
用户：1
Agent：发现在线地面车辆 GV1、GV2，请选择 Leader。

用户：GV1
Agent：GV1 已设为 Leader，GV2 自动作为 Follower。请输入间距。

用户：0.5
Agent：已记录 GV2=0.5 米。输入“发送队形”确认。

用户：发送队形
Agent：队形发送成功，请输入目标点。

用户：前往 (5, 6)
Agent：只向 GV1 下发目标点，GV2 通过 Follow 逻辑跟随。
```

两车场景也接受 `0.5米`、`间距0.5米`、`每架都设置成0.5米`。多 Follower 场景可以输入统一间距，或为每辆 Follower 分别绑定间距。

Console 跟随模式的车辆发现、Leader、Follower、间距、发送确认和目标点收集由客户端确定性向导完成，不调用 LLM 生成这些工具参数。几何编队仍由 LLM 进行工具规划。

选择几何编队：

```text
用户：2
Agent：请指定形状、参与车辆以及间距或边长。

用户：让 GV1、GV2、GV3 排成边长 2 米的三角形
```

选择完成前不会调用编队工具。Console 跟随编队缺少间距时不会采用默认值。

## 目标点已接收但 Leader 不移动

目标点支持英文或中文括号、逗号，例如：

```text
设置目标点 (3.0, 3.0)
设置目标点（3.0，3.0）
前往 3.0,3.0
```

客户端会把这些输入统一解析成数值参数：

```json
{"x": 3.0, "y": 3.0}
```

出现下面的输出时：

```text
[Agent] 目标点已发送给当前 Leader。
```

它表示 Console 调用车辆的 `setTaskPoint()` RPC 成功，不表示车辆已经产生位移或完成导航。

车辆端为 Leader 使用约 `0.3m` 的 `safeDistance`。车辆收到目标点后会计算当前位置到目标点的距离；当距离不超过该值时，直接判定已经到达，不会产生明显运动：

```python
goal_distance = sqrt((goal_x - posx) ** 2 + (goal_y - posy) ** 2)
if goal_distance <= safeDistance:
    return 0
```

例如 GV1 位于 `(2.22, 2.26)` 时，目标 `(2.3, 2.3)` 仅相距约 `0.089m`，小于 `0.3m`，因此不移动属于车辆端的正常到达判定，并非坐标格式错误。

排查时应先设置一个距离当前位置明显超过 `0.3m` 的目标，例如：

```text
设置目标点（3.0，3.0）
```

Leader 终端正常应出现类似日志：

```text
get TaskPoint :3.0,3.0
start followpath
start gotoPoint
```

如果远目标仍不移动，再检查 Leader 终端是否收到 `get TaskPoint`、真实 RPC 是否连通、车辆定位是否持续更新，以及车辆导航线程是否已经启动。

## 架构

```text
deepseek_mcp_client.py
  ├─ 自然语言模式选择与安全护栏
  ├─ console_follow_wizard.py（确定性 Console 跟随向导）
  └─ 每次工具调用启动 FastMCP 子进程
                ↓
main.py / RobotAdapter
                ↓ HTTP
SAU Console / HttpApiExecutor（持久状态）
  ├─ POST /api/formation/send_follow
  ├─ GET  /api/formation/status
  ├─ POST /api/formation/goto_target
  └─ POST /api/formation/execute（几何编队）
                ↓ ILU RPC
车辆节点
```

Python 模块全局变量不承担跨工具调用的编队状态，因为每次 `fastmcp call` 都是独立进程。

## 快速开始

### 启动 Console

启动带 HttpPlugin 的 `main_console.exe`，默认监听 `127.0.0.1:9001`。真实车辆 RPC 需要：

```powershell
$env:SAU_ENABLE_REAL_RPC = "1"
```

### 启动交互客户端

```powershell
cd E:\MCP-IDL\mcp
python .\deepseek_mcp_client.py
```

### Python 测试

```powershell
cd E:\MCP-IDL\mcp
python -m pytest tests\test_robot_adapter.py tests\test_main_formation_tools.py tests\test_console_follow_wizard.py tests\test_deepseek_mcp_client.py -q
```

### Console 构建要求

Console 使用 32 位 ILU 库，因此 Qt、MSVC 和 ILU 必须保持同一架构。推荐 Qt 5.15 MSVC x86 工具链；x64 Qt 与 x86 ILU 混用会在链接阶段报 `LNK1112`。
