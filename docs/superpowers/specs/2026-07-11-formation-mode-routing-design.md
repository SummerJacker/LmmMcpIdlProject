# Formation Mode Routing and Console Follow Formation Design

## Goal

Make natural-language formation control distinguish two separate operations and make the follow-formation path execute the same Console logic as the GUI:

1. Console follow formation: establish a persistent Leader/Follower chain, send per-follower spacing, then move only the Leader to a target point.
2. Geometric formation: independently navigate participating vehicles to calculated line, triangle, or column positions.

## User interaction

When the user gives an ambiguous formation command such as `进行编队`, the client must ask:

```text
请选择编队类型：
1. Console 跟随编队
   设置 Leader、每辆跟随车的间距；后续只控制 Leader 前往目标点。

2. 几何编队
   各车辆分别移动到直线、三角形等几何位置，不建立持续跟随关系。
```

No formation tool may run until the user selects a mode. If the user explicitly requests a Console follow formation or an unambiguous geometric layout, the client may enter that flow directly.

### Console follow formation flow

1. Check or set the Leader.
2. Collect the ordered Followers.
3. Collect each Follower's distance from the preceding vehicle.
4. Show the collected parameters and send the formation once.
5. Wait for a target point.
6. Send the target point only to the current Leader. Followers move through Console Follow behavior.

Missing spacing must never be replaced with a default value. For multiple Followers, spacing is independent per vehicle.

### Geometric formation flow

1. Collect the geometric shape.
2. Collect participating vehicles.
3. Collect spacing or side length.
4. Collect anchor and heading when needed.
5. Execute independent navigation to the calculated target positions.

This flow does not create a persistent Leader/Follower relationship.

## Architecture and state ownership

Console is the single source of truth for the current Leader, the last successfully dispatched follow formation, effective spacing, and formation readiness.

The Python MCP server must not rely on module-global formation state across calls. `deepseek_mcp_client.py` launches a new FastMCP subprocess for each tool call, so Python globals and Python-owned task IDs are not durable session state.

The follow-formation control chain is:

```text
set_leader
  -> send_follow_formation
  -> Console::setFormationWithResult
  -> FOLLOW_FORMATION_READY
  -> goto_follow_formation
  -> Console::setTaskPoint(current Leader only)
```

The existing `/api/formation/execute` endpoint remains the geometric navigation operation. It must not be used to send a Console follow formation.

## Console HTTP API

### Send a follow formation

Add:

```http
POST /api/formation/send_follow
```

Example request:

```json
{
  "leader_id": "GV1",
  "followers": [
    {"unit_id": "GV2", "distance_m": 0.3},
    {"unit_id": "GV3", "distance_m": 0.5}
  ]
}
```

The endpoint validates bound units and that the requested Leader matches the Console Leader, then constructs the same `Unit_Formation` used by the GUI:

```text
robot_ids  = [GV1, GV2, GV3]
leader_ids = [0,   0,   1]
distances  = [0, 0.3, 0.5]
angles     = [0,   0,   0]
```

It calls `setFormationWithResult()` directly. Existing Console validation, topology handling, RPC dispatch, partial-success behavior, and minimum safe spacing remain authoritative.

Console currently adjusts a ground-follower distance below `0.5m` to `0.5m`. The HTTP response must report both requested and effective distances so MCP can state that `0.3m` became `0.5m`.

On success, Console stores the ordered formation and effective distances for status and later target commands. On failure, it returns per-unit failure information and does not trigger automatic cancellation or stopping.

### Move the follow formation

Add:

```http
POST /api/formation/goto_target
```

Example request:

```json
{"x": 5.0, "y": 6.0}
```

The endpoint requires a successfully dispatched follow formation and a valid current Leader. It selects the current Leader and calls the same `setTaskPoint(x, y)` execution path used by Console. It does not send target points to Followers.

### Query follow-formation status

Add or update a status endpoint so it returns Console-owned state:

```json
{
  "has_active_formation": true,
  "state": "READY",
  "leader_id": "GV1",
  "followers": [
    {"unit_id": "GV2", "requested_distance_m": 0.3, "effective_distance_m": 0.5}
  ]
}
```

## MCP tools

Add:

```text
send_follow_formation(leader_id, followers_json)
goto_follow_formation(x, y)
```

`followers_json` is a JSON array:

```json
[
  {"robot_id": "GV2", "distance_m": 0.3},
  {"robot_id": "GV3", "distance_m": 0.5}
]
```

The adapter resolves unit IDs and aliases, rejects malformed or duplicate entries, and forwards the normalized payload to Console.

Rename the user-facing geometric tool to `execute_geometric_formation`. The old `execute_formation` and `execute_formation_mission` names may remain as compatibility wrappers, but the DeepSeek client must not select them for follow formation.

## Client routing and safety rules

The system prompt and deterministic client guardrails must enforce:

- Ambiguous formation intent requires the two-mode selection prompt.
- An explicit follow-formation request enters the follow flow directly.
- An explicit geometric layout request enters the geometric flow directly.
- Follow formation cannot be sent without Leader, ordered Followers, and every Follower's spacing.
- A follow formation is sent exactly once after parameter collection.
- A follow-formation target uses only `goto_follow_formation`.
- Geometric formation tools are rejected during a follow-formation interaction.
- Follow-formation tools are rejected during a geometric-formation interaction.
- Failures never cause autonomous cancellation, all-stop, per-robot stop, repeated formation creation, or Follower navigation.
- Stop, reset, cancellation, or retry occurs only after an explicit user request.

## Error handling

- Incomplete input returns a clarification request without any RPC.
- Missing or invalid Leader returns a specific validation failure.
- Empty, duplicate, or unbound Followers are rejected before dispatch.
- Missing, nonnumeric, or nonpositive spacing is rejected before dispatch.
- Console per-unit RPC errors are preserved in the MCP response.
- Partial success follows existing `FormationResult` semantics and does not automatically roll back successful units.
- Missing formation state or invalid Leader causes `goto_follow_formation` to fail without moving any vehicle.

## Verification

Automated tests must cover:

1. Ambiguous `进行编队` asks for mode selection and calls no tools.
2. Selecting Console follow formation enters parameter collection.
3. Selecting geometric formation enters the geometric workflow.
4. Missing spacing never invokes a formation tool.
5. Two-vehicle follow formation sends one request and reports `0.3m -> 0.5m`.
6. Three-vehicle independent spacing creates chain leader indices `[0, 0, 1]`.
7. A follow target invokes only the current Leader's task-point path.
8. Follow-formation failure does not trigger cancellation, stop, retry, or geometric navigation.
9. Console-owned status survives separate FastMCP subprocess calls.
10. Existing geometric `/api/formation/execute` behavior remains compatible.

## Out of scope

- Changing vehicle-side follow-control algorithms.
- Removing the existing geometric formation implementation.
- Adding new geometric shapes.
- Changing the Console minimum safe distance below `0.5m`.
