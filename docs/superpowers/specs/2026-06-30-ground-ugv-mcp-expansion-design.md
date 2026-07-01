# Ground UGV MCP Expansion Design

## Goal

Expand the current MCP integration from basic speed control into a demonstrable ground-vehicle task and formation workflow.

The first milestone is an acceptance-demo loop:

```text
list robots
-> choose / set leader
-> set group mode
-> set minor tracking mode
-> set task point or task path
-> optionally add traps
-> inspect fleet state
-> stop or reset relations
```

This phase is intentionally limited to ground vehicles (`GV*`). Air-vehicle controls, gimbal controls, fire confirmation, throw confirmation, takeoff, landing, and other high-risk actions are out of scope for this milestone.

## Current State

The Python MCP layer currently exposes 11 tools in `mcp/main.py`:

- `send_move`
- `stop_robot`
- `emergency_stop_all`
- `list_robots`
- `get_robot_status`
- `get_fleet_status`
- `compute_remaining_distance`
- `compute_relative_pose`
- `compute_navigation_hint`
- `plan_line_targets`
- `plan_triangle_targets`

Only these Qt HTTP routes currently bridge into the console:

- `GET /api/robot/list`
- `GET /api/robot/status`
- `POST /api/robot/sendmove`
- `POST /api/robot/stop`
- `POST /api/robot/stop_all`

Most planning helpers are Python-side geometry and do not use native Qt / IDL formation APIs.

The current `mcp/robots.json` contains only `robot_2 -> GV2`. A full formation demo requires either restoring the multi-vehicle mapping or starting the Qt console with multiple mock robots such as `-mockRobots GV1,GV2,GV3`.

## Design Principles

Expose task-level MCP tools, not raw IDL calls.

Preferred:

```text
set_leader(robot_id="GV1")
set_group_mode(mode="follow")
set_task_path(robot_id="GV1", points_json="[...]")
```

Avoid exposing raw RPC-shaped tools such as:

```text
unit_rpc_set_mode_raw(mode=1)
unit_rpc_set_minor_mode_raw(mode=2)
```

The MCP surface should be understandable to an LLM and to a human tester. The Qt layer remains responsible for translating task-level HTTP requests into ILU / IDL calls.

All new routes return the existing JSON shape:

```json
{
  "success": true,
  "message": "ok",
  "data": {}
}
```

## Phase 1 MCP Tools

Add these tools to `mcp/main.py` and `mcp/robot_adapter.py`:

| Tool | Purpose |
| --- | --- |
| `set_leader(robot_id)` | Select a ground unit as the leader. |
| `set_group_mode(mode)` | Set group mode: `follow`, `imitate`, or `none`. |
| `set_group_minor_mode(mode)` | Set minor mode: `object_tracking`, `track_tracking`, or `none`. |
| `set_task_point(robot_id, x, y)` | Send a native target point to one ground vehicle. |
| `set_task_path(robot_id, points_json)` | Send a native path to one ground vehicle. |
| `add_trap_point(x, y, radius)` | Broadcast a ground trap point to bound units. |
| `clear_traps()` | Clear trap points across bound units. |
| `reset_unit_relations()` | Reset roles, leader state, and local relation state. |

`points_json` should be a JSON array string:

```json
[
  {"x": 0.0, "y": 0.0},
  {"x": 1.0, "y": 0.0},
  {"x": 1.0, "y": 1.0}
]
```

The Python adapter validates JSON shape and simple numeric bounds before sending to Qt.

## Phase 1 Qt HTTP Routes

Add these routes to `SAU/Console/HttpApiExecutor.cpp`:

| Route | Method | Calls / behavior |
| --- | --- | --- |
| `/api/formation/set_leader` | `POST` | Resolve `unit_id`, create unit proxy, set role to `Unit_UR_Leader`, update console leader globals. |
| `/api/formation/set_group_mode` | `POST` | Convert mode string to `Unit_UnitMode`; apply to bound ground units. |
| `/api/formation/set_group_minor_mode` | `POST` | Convert minor mode string to `Unit_UnitMinorMode`; apply to bound ground units. |
| `/api/task/set_point` | `POST` | Resolve `unit_id`; call `Ground_Unit_rpc_setTaskPoint`. |
| `/api/task/set_path` | `POST` | Resolve `unit_id`; build `Ground_Unit_TaskPath`; call `Ground_Unit_rpc_setTaskPath`. |
| `/api/trap/add` | `POST` | Build `Console_TrapPoint` / `Ground_Unit_TrapPoint2D`; broadcast to ground units. |
| `/api/trap/clear` | `POST` | Call `Ground_Unit_rpc_clearTraps` on bound ground units. |
| `/api/system/reset_relations` | `POST` | Reset leader / follower relation state, mirroring safe parts of `setDefault()`. |

Where possible, share helper code rather than calling UI slot methods. The implementation should extract non-UI helpers for:

- resolving `unit_id` to SBH and ground proxy
- checking real RPC is enabled
- converting mode strings
- building standard JSON responses
- freeing ILU objects consistently

## IDL Mapping

This phase uses already generated stubs in `SAU/Console/stubs`:

- `Unit_rpc_setRole`
- `Unit_rpc_setMode`
- `Unit_rpc_setMinorMode`
- `Unit_rpc_setALeader`
- `Ground_Unit_rpc_setTaskPoint`
- `Ground_Unit_rpc_setTaskPath`
- `Ground_Unit_rpc_setTrapPoint`
- `Ground_Unit_rpc_clearTraps`

The project contains many more IDL functions, but this phase does not expose them.

## Mock Behavior

Current mock support covers list/status/sendmove/stop with in-memory kinematics. Formation, task point, path, and trap APIs currently do not have equivalent mock semantics.

For Phase 1, new routes should support two behaviors:

1. If the target is a mock unit, return success with `mock: true` and record the requested command in response data.
2. If the route needs real RPC and the unit is real while `SAU_ENABLE_REAL_RPC` is not set, return the existing 503 response.

This preserves acceptance-demo usability without pretending mock execution proves real vehicle behavior.

## Safety Boundaries

Retain existing real-RPC gate:

```text
SAU_ENABLE_REAL_RPC=1
```

No new real vehicle command should bypass this gate.

Additional validation:

- `set_leader` accepts only mapped and currently bound `GV*` units.
- group modes are strict enums.
- task paths must contain 1 to 10 points.
- trap radius must be positive.
- numeric coordinates must be finite.
- destructive actions such as shutdown remain out of scope.

## Natural Language Client

After the tools and routes are implemented, update `mcp/deepseek_mcp_client.py` so the system prompt prefers native task APIs for ground tasks:

- "set GV2 target to (x, y)" -> `set_task_point`
- "send GV2 through these points" -> `set_task_path`
- "set GV1 as leader" -> `set_leader`
- "enter follow mode" -> `set_group_mode("follow")`
- "use target tracking" -> `set_group_minor_mode("object_tracking")`
- "add trap at (x, y)" -> `add_trap_point`

Keep existing guardrails for speed control and premature completion.

## Test Plan

Python tests:

- adapter maps each new tool to the correct HTTP route and payload
- invalid modes are rejected before HTTP
- invalid path JSON is rejected before HTTP
- trap radius validation
- `robot_id` and `unit_id` aliases both work

Qt tests / checks:

- route parsing accepts valid JSON
- invalid JSON returns 400-style JSON
- mock routes return success with `mock: true`
- real routes return 503 when `SAU_ENABLE_REAL_RPC` is not enabled
- mode conversion rejects unknown strings

Integration demo:

```powershell
cd mcp
fastmcp call main.py list_robots --json
fastmcp call main.py set_leader --json robot_id=GV1
fastmcp call main.py set_group_mode --json mode=follow
fastmcp call main.py set_group_minor_mode --json mode=object_tracking
fastmcp call main.py add_trap_point --json x=2.0 y=2.0 radius=0.5
fastmcp call main.py set_task_point --json robot_id=GV1 x=5.0 y=3.0
fastmcp call main.py get_fleet_status --json robot_ids_csv=GV1,GV2,GV3
fastmcp call main.py emergency_stop_all --json
fastmcp call main.py reset_unit_relations --json
```

If only `GV2` is configured, use the single-vehicle subset:

```powershell
fastmcp call main.py list_robots --json
fastmcp call main.py set_task_point --json robot_id=GV2 x=5.0 y=3.0
fastmcp call main.py add_trap_point --json x=2.0 y=2.0 radius=0.5
fastmcp call main.py get_robot_status --json robot_id=GV2
```

## Risks

- Some Qt helper logic is tied to UI/global state. Extracting safe helpers is better than invoking UI slots.
- Several `Console::rpc` server functions are stubbed with `return NULL`; do not rely on them.
- Mock behavior for task/formation commands is not physical simulation. Responses must say `mock: true`.
- Native formation setup depends on leader state and bound vehicles, so implementation should be incremental.

## Acceptance Criteria

- New MCP tools are discoverable from `main.py`.
- Each new tool returns the standard JSON shape.
- Invalid inputs fail before reaching Qt where practical.
- Qt exposes the new routes and preserves the real-RPC safety gate.
- A ground-vehicle acceptance demo can run using mock units or real units with explicit RPC enablement.
- Existing motion and status tests continue to pass after aligning the test robot configuration.
