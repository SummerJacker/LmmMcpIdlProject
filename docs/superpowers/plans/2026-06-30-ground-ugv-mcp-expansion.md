# Ground UGV MCP Expansion Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add the first acceptance-demo set of MCP tools for ground UGV leader, formation mode, task point/path, trap, and reset operations.

**Architecture:** Python MCP tools remain task-level APIs and delegate to `RobotAdapter`. `RobotAdapter` validates natural-language-friendly inputs, maps `robot_id` aliases to Qt `unit_id`, and calls new Qt HTTP routes. `HttpApiExecutor.cpp` bridges those routes to the existing console/IDL helper path for real RPC while returning explicit mock acknowledgements for mock units.

**Tech Stack:** Python 3.13, FastMCP, pytest, Qt/C++ HTTP bridge, ILU/IDL generated stubs.

---

## File Structure

- Modify `mcp/robots.json`: restore three-vehicle demo mapping so GV1/GV2/GV3 formation tests and demos have configured aliases.
- Modify `mcp/config.py`: add Qt route constants for formation, task, trap, and reset APIs.
- Modify `mcp/robot_adapter.py`: add validation helpers and eight new async adapter methods.
- Modify `mcp/main.py`: expose eight new FastMCP tools that delegate to `RobotAdapter`.
- Modify `mcp/tests/test_robot_adapter.py`: add Python-side tests for payloads, URL routing, validation, and existing GV1 planned-mode baseline.
- Modify `SAU/Console/HttpApiExecutor.cpp`: add route handlers for formation, task, trap, and reset operations.

No git commit steps are included because `E:\MCP-IDL` is not currently a Git repository.

## Task 1: Restore Demo Robot Mapping

**Files:**
- Modify: `mcp/robots.json`
- Test: `mcp/tests/test_robot_adapter.py`

- [ ] **Step 1: Replace `mcp/robots.json` with the three-vehicle demo mapping**

```json
{
  "robots": [
    {
      "robot_id": "robot_1",
      "unit_id": "GV1",
      "mode": "real",
      "simulator_type": "sau"
    },
    {
      "robot_id": "robot_2",
      "unit_id": "GV2",
      "mode": "sim",
      "simulator_type": "sau"
    },
    {
      "robot_id": "robot_3",
      "unit_id": "GV3",
      "mode": "sim",
      "simulator_type": "sau"
    }
  ]
}
```

- [ ] **Step 2: Run the existing failing baseline test**

Run: `python -m pytest mcp\tests\test_robot_adapter.py::test_list_robots_run_mode_all_sim_when_mock_and_rpc_off -q`

Expected: `1 passed`

## Task 2: Add Python Adapter Tests

**Files:**
- Modify: `mcp/tests/test_robot_adapter.py`
- Modify later: `mcp/config.py`
- Modify later: `mcp/robot_adapter.py`

- [ ] **Step 1: Add tests for new adapter methods**

Append tests that patch `robot_adapter.http_request` and assert:

```python
@pytest.mark.asyncio
async def test_set_leader_posts_unit_id() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"unit_id": "GV1"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_leader(robot_id="robot_1")

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["method"] == "POST"
    assert calls[0]["url"].endswith("/api/formation/set_leader")
    assert calls[0]["json_body"] == {"unit_id": "GV1"}
```

```python
@pytest.mark.asyncio
async def test_set_group_mode_normalizes_alias() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"mode": "follow"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_group_mode(mode="跟随")

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/formation/set_group_mode")
    assert calls[0]["json_body"] == {"mode": "follow"}
```

```python
@pytest.mark.asyncio
async def test_set_group_minor_mode_normalizes_track_alias() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"minor_mode": "track"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_group_minor_mode(mode="route")

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/formation/set_group_minor_mode")
    assert calls[0]["json_body"] == {"minor_mode": "track"}
```

```python
@pytest.mark.asyncio
async def test_set_task_point_posts_canonical_unit() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"unit_id": "GV2"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_task_point(robot_id="robot_2", x=1.25, y=-0.5)

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/task/set_point")
    assert calls[0]["json_body"] == {"unit_id": "GV2", "x": 1.25, "y": -0.5}
```

```python
@pytest.mark.asyncio
async def test_set_task_path_accepts_json_points() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"unit_id": "GV3"}}, ""

    adapter = RobotAdapter()
    points_json = '[{"x": 0, "y": 0}, {"x": 1.5, "y": 2.0}]'
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_task_path(robot_id="GV3", points_json=points_json)

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/task/set_path")
    assert calls[0]["json_body"] == {
        "unit_id": "GV3",
        "points": [{"x": 0.0, "y": 0.0}, {"x": 1.5, "y": 2.0}],
    }
```

```python
@pytest.mark.asyncio
async def test_set_task_path_rejects_more_than_ten_points() -> None:
    adapter = RobotAdapter()
    points_json = json.dumps([{"x": i, "y": i} for i in range(11)])

    resp = await adapter.set_task_path(robot_id="GV1", points_json=points_json)

    obj = _parse_response(resp)
    assert obj["success"] is False
    assert "1..10" in obj["message"]
```

```python
@pytest.mark.asyncio
async def test_add_and_clear_trap_routes() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        add_resp = await adapter.add_trap_point(x=2.0, y=3.0, radius=0.4)
        clear_resp = await adapter.clear_traps()

    assert _parse_response(add_resp)["success"] is True
    assert _parse_response(clear_resp)["success"] is True
    assert calls[0]["url"].endswith("/api/trap/add")
    assert calls[0]["json_body"] == {"x": 2.0, "y": 3.0, "radius": 0.4}
    assert calls[1]["url"].endswith("/api/trap/clear")
    assert calls[1]["json_body"] == {}
```

```python
@pytest.mark.asyncio
async def test_reset_unit_relations_route() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.reset_unit_relations()

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/system/reset_relations")
    assert calls[0]["json_body"] == {}
```

- [ ] **Step 2: Run new tests and verify RED**

Run: `python -m pytest mcp\tests\test_robot_adapter.py -q`

Expected: failures mention missing `RobotAdapter.set_leader` or related missing methods.

## Task 3: Implement Python Adapter and MCP Tools

**Files:**
- Modify: `mcp/config.py`
- Modify: `mcp/robot_adapter.py`
- Modify: `mcp/main.py`
- Test: `mcp/tests/test_robot_adapter.py`

- [ ] **Step 1: Add route constants to `mcp/config.py`**

Add:

```python
QT_SET_LEADER_PATH: str = "/api/formation/set_leader"
QT_SET_GROUP_MODE_PATH: str = "/api/formation/set_group_mode"
QT_SET_GROUP_MINOR_MODE_PATH: str = "/api/formation/set_group_minor_mode"
QT_TASK_POINT_PATH: str = "/api/task/set_point"
QT_TASK_PATH_PATH: str = "/api/task/set_path"
QT_TRAP_ADD_PATH: str = "/api/trap/add"
QT_TRAP_CLEAR_PATH: str = "/api/trap/clear"
QT_RESET_RELATIONS_PATH: str = "/api/system/reset_relations"
```

- [ ] **Step 2: Add validation helpers to `mcp/robot_adapter.py`**

Add helpers that normalize group modes, normalize minor modes, parse `points_json`, validate finite floats, and return exact failure messages:

```python
Validation failed: mode must be one of none/follow/imitate/mate
Validation failed: minor mode must be one of none/object/track
Validation failed: task path points_json must be a JSON list with 1..10 points
Validation failed: trap radius must be > 0
```

- [ ] **Step 3: Add adapter methods**

Add async methods:

```python
async def set_leader(self, *, robot_id: str) -> str
async def set_group_mode(self, *, mode: str) -> str
async def set_group_minor_mode(self, *, mode: str) -> str
async def set_task_point(self, *, robot_id: str, x: float, y: float) -> str
async def set_task_path(self, *, robot_id: str, points_json: str) -> str
async def add_trap_point(self, *, x: float, y: float, radius: float) -> str
async def clear_traps(self) -> str
async def reset_unit_relations(self) -> str
```

Each method calls `_run_http` with `POST`, the matching route constant, and the validated JSON body.

- [ ] **Step 4: Register MCP tools in `mcp/main.py`**

Expose FastMCP tools with the same names as the adapter methods. Each tool delegates directly to the adapter method and returns the adapter JSON string.

- [ ] **Step 5: Run Python tests and verify GREEN**

Run: `python -m pytest mcp\tests\test_robot_adapter.py -q`

Expected: all tests in that file pass.

## Task 4: Implement Qt HTTP Routes

**Files:**
- Modify: `SAU/Console/HttpApiExecutor.cpp`

- [ ] **Step 1: Add small helper functions inside the anonymous namespace**

Add helpers to parse JSON objects, check ground unit IDs, count mock/real ground units, map mode strings to IDL enums, and build repeated response payloads.

- [ ] **Step 2: Add route `/api/formation/set_leader`**

Behavior:
- Require `POST`.
- Body requires `unit_id`.
- Reject non-ground IDs with `unit_id must be a ground unit id`.
- If unit is mock, return success with `mock=true`.
- If real RPC is disabled, return 503 using `realUnitRpcDisabledResponse`.
- If real RPC is enabled, call `getUnitObject(unit_id)` and `setToLeader()`.

- [ ] **Step 3: Add route `/api/formation/set_group_mode`**

Behavior:
- Require body field `mode` in `none`, `follow`, `imitate`, or `mate`.
- If all ground units are mock, return success with `mock=true`.
- If real RPC is disabled and real units are present, return 503.
- If real RPC is enabled, call `setGroupMode(mapped_mode)`.

- [ ] **Step 4: Add route `/api/formation/set_group_minor_mode`**

Behavior:
- Require body field `minor_mode` in `none`, `object`, or `track`.
- If all ground units are mock, return success with `mock=true`.
- If real RPC is disabled and real units are present, return 503.
- If real RPC is enabled, call `setGroupMinorMode(mapped_minor_mode)`.

- [ ] **Step 5: Add route `/api/task/set_point`**

Behavior:
- Require `unit_id`, numeric `x`, numeric `y`.
- Reject non-ground IDs.
- Mock units return success with echoed point.
- Real RPC enabled path obtains `Ground_Unit_rpc` by SBH and calls `Ground_Unit_rpc_setTaskPoint`.

- [ ] **Step 6: Add route `/api/task/set_path`**

Behavior:
- Require `unit_id` and `points` array with 1..10 objects containing numeric `x` and `y`.
- Reject non-ground IDs.
- Mock units return success with echoed path.
- Real RPC enabled path builds `Ground_Unit_TaskPath`, calls `Ground_Unit_rpc_setTaskPath`, and frees the sequence.

- [ ] **Step 7: Add trap and reset routes**

Routes:
- `/api/trap/add`: body requires numeric `x`, numeric `y`, and positive `radius`; mock-only fleet echoes success; real path calls `setTrap`.
- `/api/trap/clear`: mock-only fleet echoes success; real path calls `clearTraps`.
- `/api/system/reset_relations`: mock-only fleet echoes success; real path calls `setDefault`.

- [ ] **Step 8: Run static route verification**

Run:

```powershell
Select-String -LiteralPath 'SAU\Console\HttpApiExecutor.cpp' -Pattern '/api/formation|/api/task|/api/trap|/api/system/reset_relations'
```

Expected: all eight new routes are present.

## Task 5: Final Verification

**Files:**
- `mcp/tests/test_robot_adapter.py`
- `mcp/main.py`
- `mcp/robot_adapter.py`
- `mcp/config.py`
- `SAU/Console/HttpApiExecutor.cpp`

- [ ] **Step 1: Run Python unit tests**

Run: `python -m pytest mcp\tests -q`

Expected: all Python MCP tests pass.

- [ ] **Step 2: Inspect MCP tool registrations**

Run:

```powershell
Select-String -LiteralPath 'mcp\main.py' -Pattern 'set_leader|set_group_mode|set_group_minor_mode|set_task_point|set_task_path|add_trap_point|clear_traps|reset_unit_relations'
```

Expected: each new tool appears.

- [ ] **Step 3: Report any verification limits**

If no Qt compiler/toolchain is available in the current shell, report that Python tests passed and Qt route code was statically verified, but the Qt binary was not rebuilt in this session.

