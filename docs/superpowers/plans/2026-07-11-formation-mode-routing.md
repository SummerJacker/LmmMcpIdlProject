# Formation Mode Routing Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Separate Console follow formation from geometric formation, add durable Console-owned follow state, and make the DeepSeek client ask the user to select a formation mode before executing ambiguous formation commands.

**Architecture:** `HttpApiExecutor` owns the durable follow-formation snapshot and exposes send/status/target routes. Python exposes thin adapter/MCP tools over those routes. `deepseek_mcp_client.py` owns only conversation routing state, never vehicle truth, and uses deterministic guards to prevent cross-mode calls and autonomous recovery chains.

**Tech Stack:** C++11, Qt 5/Qt Test, ILU RPC, Python 3.10+, FastMCP, pytest/pytest-asyncio.

---

## File structure

- Modify `SAU/Console/console.h` and `SAU/Console/console.cpp`: add one shared constructor/free path for the same chain-shaped `Unit_Formation` used by GUI and HTTP.
- Modify `SAU/Console/tests/test_formation.cpp`: verify two-car and three-car chain construction and effective spacing.
- Modify `SAU/Console/HttpApiExecutor.h` and `SAU/Console/HttpApiExecutor.cpp`: add persistent follow state and `/send_follow`, `/status`, `/goto_target` routes.
- Modify `mcp/config.py`: add follow-formation endpoint constants.
- Modify `mcp/robot_adapter.py`: parse/resolve follower payloads and call the new Console endpoints.
- Modify `mcp/main.py`: expose unambiguous follow and geometric MCP tools and replace Python-global formation status.
- Modify `mcp/deepseek_mcp_client.py`: add two-mode selection state and tool-call guards.
- Modify `mcp/tests/test_robot_adapter.py`, `mcp/tests/test_mcp_tools.py`, and `mcp/tests/test_deepseek_mcp_client.py`: Python regression coverage.
- Update `mcp/README.md`: document the two formation modes and natural-language examples.

### Task 1: Build the Console chain formation from one shared helper

**Files:**
- Modify: `SAU/Console/console.h`
- Modify: `SAU/Console/console.cpp`
- Test: `SAU/Console/tests/test_formation.cpp`

- [ ] **Step 1: Write failing Qt tests for chain construction**

Add tests that call a new pure construction helper without live RPC:

```cpp
void testBuildGroundFollowFormation_TwoVehicles() {
    QString error;
    Unit_Formation *f = buildGroundFollowFormation(
        QStringLiteral("GV1"),
        QStringList() << QStringLiteral("GV2"),
        QVector<float>() << 0.3f,
        &error);

    QVERIFY2(f != NULL, qPrintable(error));
    QCOMPARE((int)f->robot_ids._length, 2);
    QCOMPARE(QString::fromUtf8(f->robot_ids._buffer[0]), QStringLiteral("GV1"));
    QCOMPARE(QString::fromUtf8(f->robot_ids._buffer[1]), QStringLiteral("GV2"));
    QCOMPARE((int)f->leader_ids._buffer[0], 0);
    QCOMPARE((int)f->leader_ids._buffer[1], 0);
    QCOMPARE((double)f->distances._buffer[0], 0.0);
    QCOMPARE((double)effectiveGroundFollowDistance(f->distances._buffer[1]), 0.5);
    freeUnitFormation(f);
}

void testBuildGroundFollowFormation_IndependentChainSpacing() {
    QString error;
    Unit_Formation *f = buildGroundFollowFormation(
        QStringLiteral("GV1"),
        QStringList() << QStringLiteral("GV2") << QStringLiteral("GV3"),
        QVector<float>() << 0.6f << 0.9f,
        &error);

    QVERIFY2(f != NULL, qPrintable(error));
    QCOMPARE((int)f->leader_ids._buffer[0], 0);
    QCOMPARE((int)f->leader_ids._buffer[1], 0);
    QCOMPARE((int)f->leader_ids._buffer[2], 1);
    QCOMPARE((double)f->distances._buffer[1], 0.6);
    QCOMPARE((double)f->distances._buffer[2], 0.9);
    freeUnitFormation(f);
}
```

- [ ] **Step 2: Run the focused Qt test and verify RED**

Run from an environment with the repository's Qt/ILU 32-bit kit:

```powershell
cd E:\MCP-IDL\SAU\Console\tests
qmake tests.pro
nmake debug
.\debug\test_formation.exe testBuildGroundFollowFormation_TwoVehicles testBuildGroundFollowFormation_IndependentChainSpacing
```

Expected: compilation fails because `buildGroundFollowFormation`, `effectiveGroundFollowDistance`, and `freeUnitFormation` do not exist.

- [ ] **Step 3: Add the minimal shared constructor and spacing helper**

Declare in `console.h`:

```cpp
float effectiveGroundFollowDistance(float requestedDistance);
Unit_Formation *buildGroundFollowFormation(
    const QString &leaderId,
    const QStringList &followerIds,
    const QVector<float> &distances,
    QString *errorMessage);
void freeUnitFormation(Unit_Formation *value);
```

Implement in `console.cpp` with one authoritative safety constant:

```cpp
static const float MIN_SAFE_DISTANCE = 0.5f;

float effectiveGroundFollowDistance(float requestedDistance) {
    return requestedDistance < MIN_SAFE_DISTANCE ? MIN_SAFE_DISTANCE : requestedDistance;
}

Unit_Formation *buildGroundFollowFormation(
    const QString &leaderId,
    const QStringList &followerIds,
    const QVector<float> &distances,
    QString *errorMessage)
{
    if (leaderId.isEmpty() || followerIds.isEmpty() || followerIds.size() != distances.size()) {
        if (errorMessage) *errorMessage = QStringLiteral("leader, followers, and distances are required");
        return NULL;
    }

    Unit_Formation *value = (Unit_Formation *)malloc(sizeof(Unit_Formation));
    const int count = followerIds.size() + 1;
    value->robot_ids = *Unit_UnitIDSeq_Create(count, NULL);
    value->leader_ids = *Unit_ShortSeq_Create(count, NULL);
    value->distances = *Unit_FloatSeq_Create(count, NULL);
    value->angles = *Unit_FloatSeq_Create(count, NULL);

    ilu_Error err;
    const QByteArray leaderBytes = leaderId.toUtf8();
    char *leaderCopy = (char *)ilu_malloc(leaderBytes.size() + 1);
    strcpy(leaderCopy, leaderBytes.constData());
    Unit_UnitIDSeq_Append(&value->robot_ids, leaderCopy, &err);
    Unit_ShortSeq_Append(&value->leader_ids, 0, &err);
    Unit_FloatSeq_Append(&value->distances, 0.0f, &err);
    Unit_FloatSeq_Append(&value->angles, 0.0f, &err);

    for (int i = 0; i < followerIds.size(); ++i) {
        const QByteArray uidBytes = followerIds[i].toUtf8();
        char *uidCopy = (char *)ilu_malloc(uidBytes.size() + 1);
        strcpy(uidCopy, uidBytes.constData());
        Unit_UnitIDSeq_Append(&value->robot_ids, uidCopy, &err);
        Unit_ShortSeq_Append(&value->leader_ids, (CORBA_short)i, &err);
        Unit_FloatSeq_Append(&value->distances, distances[i], &err);
        Unit_FloatSeq_Append(&value->angles, 0.0f, &err);
    }
    return value;
}
```

`freeUnitFormation` must free all four sequences and the owning struct. Replace the local clamp expression in `_setGroundFormation` with `effectiveGroundFollowDistance(dist_i)` so GUI and HTTP use the same rule.

- [ ] **Step 4: Run the focused Qt tests and verify GREEN**

Run the command from Step 2. Expected: both new tests pass.

### Task 2: Add durable Console follow-formation HTTP routes

**Files:**
- Modify: `SAU/Console/HttpApiExecutor.h`
- Modify: `SAU/Console/HttpApiExecutor.cpp`
- Test: `SAU/Console/tests/test_formation.cpp`

- [ ] **Step 1: Write failing tests for snapshot serialization**

Expose a small value type independent of RPC in `HttpApiExecutor.h` and test its JSON output:

```cpp
void testFollowFormationSnapshot_ReportsRequestedAndEffectiveDistance() {
    FollowFormationSnapshot snapshot;
    snapshot.ready = true;
    snapshot.leaderId = QStringLiteral("GV1");
    FollowFormationMember member;
    member.unitId = QStringLiteral("GV2");
    member.requestedDistanceM = 0.3;
    member.effectiveDistanceM = 0.5;
    snapshot.followers.append(member);

    const QJsonObject json = snapshot.toJson();
    QCOMPARE(json.value("state").toString(), QStringLiteral("READY"));
    const QJsonObject follower = json.value("followers").toArray().first().toObject();
    QCOMPARE(follower.value("requested_distance_m").toDouble(), 0.3);
    QCOMPARE(follower.value("effective_distance_m").toDouble(), 0.5);
}
```

- [ ] **Step 2: Run the focused test and verify RED**

Expected: compilation fails because `FollowFormationSnapshot` and `FollowFormationMember` do not exist.

- [ ] **Step 3: Implement snapshot members and the three routes**

Add value types and `FollowFormationSnapshot followFormation_;` to `HttpApiExecutor`. Implement:

```cpp
if (path == QStringLiteral("/api/formation/send_follow") && method == QStringLiteral("POST")) {
    QJsonObject request;
    QByteArray errorResponse;
    if (!parseJsonObjectBody(body, &request, &errorResponse, httpStatus))
        return errorResponse;
    const QString leaderId = request.value(QStringLiteral("leader_id")).toString().trimmed();
    const QJsonArray inputFollowers = request.value(QStringLiteral("followers")).toArray();
    if (leaderId.isEmpty() || inputFollowers.isEmpty())
        return jsonResponse(false, QStringLiteral("leader_id and followers are required"), QJsonValue::Null, httpStatus);
    if (currentLeaderUID == NULL || leaderId != QString::fromUtf8(currentLeaderUID))
        return jsonResponse(false, QStringLiteral("requested leader does not match Console leader"), QJsonValue::Null, httpStatus);

    QSet<QString> seen;
    seen.insert(leaderId);
    QStringList followerIds;
    QVector<float> requestedDistances;
    FollowFormationSnapshot candidate;
    candidate.leaderId = leaderId;
    for (const QJsonValue &value : inputFollowers) {
        const QJsonObject item = value.toObject();
        const QString uid = item.value(QStringLiteral("unit_id")).toString().trimmed();
        const double distance = item.value(QStringLiteral("distance_m")).toDouble(-1.0);
        if (!isGroundUnitId(uid) || sbhForUid(uid) == NULL || distance <= 0.0 || seen.contains(uid))
            return jsonResponse(false, QStringLiteral("invalid, duplicate, or unbound follower"), QJsonValue(uid), httpStatus);
        seen.insert(uid);
        followerIds.append(uid);
        requestedDistances.append((float)distance);
        FollowFormationMember member;
        member.unitId = uid;
        member.requestedDistanceM = distance;
        member.effectiveDistanceM = effectiveGroundFollowDistance((float)distance);
        candidate.followers.append(member);
    }

    QString buildError;
    Unit_Formation *formation = buildGroundFollowFormation(
        leaderId, followerIds, requestedDistances, &buildError);
    if (formation == NULL)
        return jsonResponse(false, buildError, QJsonValue::Null, httpStatus);
    const FormationResult result = setFormationWithResult(formation);
    freeUnitFormation(formation);

    const bool accepted = result.isSuccess() || result.isPartialSuccess();
    candidate.ready = accepted;
    if (accepted)
        followFormation_ = candidate;
    QJsonObject data = candidate.toJson();
    data.insert(QStringLiteral("success_count"),
        result.airResult.successCount + result.groundResult.successCount);
    data.insert(QStringLiteral("fail_count"),
        result.airResult.failCount + result.groundResult.failCount);
    data.insert(QStringLiteral("failed_units"), failedFormationUnitsJson(result));
    return jsonResponseObj(accepted,
        accepted ? QStringLiteral("follow formation dispatched")
                 : QStringLiteral("follow formation dispatch failed"),
        data, httpStatus, accepted ? 200 : 409);
}

if (path == QStringLiteral("/api/formation/status") && method == QStringLiteral("GET")) {
    return jsonResponseObj(true, QStringLiteral("ok"), followFormation_.toJson(), httpStatus);
}

if (path == QStringLiteral("/api/formation/goto_target") && method == QStringLiteral("POST")) {
    if (!followFormation_.ready || currentLeaderUID == NULL)
        return jsonResponse(false, QStringLiteral("follow formation is not ready"), QJsonValue::Null, httpStatus);
    if (followFormation_.leaderId != QString::fromUtf8(currentLeaderUID))
        return jsonResponse(false, QStringLiteral("current leader changed"), QJsonValue::Null, httpStatus);
    if (!getUnitObject(currentLeaderUID) || !setTaskPoint(x, y))
        return jsonResponse(false, QStringLiteral("failed to set leader target point"), QJsonValue::Null, httpStatus);
    return jsonResponseObj(true, QStringLiteral("target accepted for leader"), data, httpStatus);
}
```

Add the result serializer in the same translation unit:

```cpp
static QJsonArray failedFormationUnitsJson(const FormationResult &result) {
    QJsonArray failures;
    const std::vector<UnitResult> failed = result.getAllFailedUnits();
    for (const UnitResult &unit : failed) {
        QJsonObject item;
        item.insert(QStringLiteral("unit_id"), QString::fromUtf8(unit.uid));
        item.insert(QStringLiteral("error_code"), unit.errorCode);
        item.insert(QStringLiteral("message"), QString::fromUtf8(unit.errorMsg));
        failures.append(item);
    }
    return failures;
}
```

The send route must not call `/api/formation/execute`, `TaskManager`, stop, reset, cancel, or retry. Serialize `FormationResult` per-unit failures in the response.

- [ ] **Step 4: Run Qt tests and build Console**

```powershell
cd E:\MCP-IDL\SAU\Console\tests
qmake tests.pro
nmake debug
.\debug\test_formation.exe

cd E:\MCP-IDL\SAU\Console
qmake console.pro
nmake debug
```

Expected: Qt tests pass and `main_console.exe` links with no new errors.

### Task 3: Add Python adapter methods with strict follower validation

**Files:**
- Modify: `mcp/config.py`
- Modify: `mcp/robot_adapter.py`
- Test: `mcp/tests/test_robot_adapter.py`

- [ ] **Step 1: Write failing async adapter tests**

```python
@pytest.mark.asyncio
async def test_send_follow_formation_resolves_aliases_and_preserves_spacing():
    calls = []
    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=lambda **kw: (
        calls.append(kw) or (200, {"success": True, "message": "accepted", "data": {}}, "")
    )):
        response = await adapter.send_follow_formation(
            leader_id="robot_1",
            followers_json='[{"robot_id":"robot_2","distance_m":0.3}]',
        )
    assert _parse_response(response)["success"] is True
    assert calls[0]["url"].endswith("/api/formation/send_follow")
    assert calls[0]["json_body"] == {
        "leader_id": "GV1",
        "followers": [{"unit_id": "GV2", "distance_m": 0.3}],
    }

@pytest.mark.asyncio
async def test_send_follow_formation_rejects_duplicate_followers_without_http():
    adapter = RobotAdapter()
    with patch("robot_adapter.http_request") as request:
        response = await adapter.send_follow_formation(
            leader_id="GV1",
            followers_json='[{"robot_id":"GV2","distance_m":0.3},{"robot_id":"GV2","distance_m":0.4}]',
        )
    assert _parse_response(response)["success"] is False
    request.assert_not_called()

@pytest.mark.asyncio
async def test_goto_follow_formation_posts_target_without_robot_id():
    calls = []
    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=lambda **kw: (
        calls.append(kw) or (200, {"success": True, "message": "accepted", "data": {"leader_id": "GV1"}}, "")
    )):
        await adapter.goto_follow_formation(x=5.0, y=6.0)
    assert calls[0]["url"].endswith("/api/formation/goto_target")
    assert calls[0]["json_body"] == {"x": 5.0, "y": 6.0}
```

- [ ] **Step 2: Run focused pytest and verify RED**

```powershell
cd E:\MCP-IDL\mcp
python -m pytest tests\test_robot_adapter.py -k "follow_formation" -q
```

Expected: failures because the methods and endpoint constants do not exist.

- [ ] **Step 3: Implement endpoint constants, parser, and adapter calls**

Add to `config.py`:

```python
QT_FOLLOW_FORMATION_SEND_PATH = "/api/formation/send_follow"
QT_FOLLOW_FORMATION_STATUS_PATH = "/api/formation/status"
QT_FOLLOW_FORMATION_TARGET_PATH = "/api/formation/goto_target"
```

Add adapter methods:

```python
async def send_follow_formation(self, *, leader_id: str, followers_json: str) -> str:
    leader_unit = await self._resolve_to_unit_id(leader_id)
    if leader_unit is None:
        return make_tool_response(success=False, message=_message_unit_not_bound(leader_id))
    try:
        raw_followers = json.loads(followers_json)
    except (TypeError, json.JSONDecodeError):
        return make_tool_response(success=False, message="followers_json must be a JSON array")
    if not isinstance(raw_followers, list) or not raw_followers:
        return make_tool_response(success=False, message="at least one follower is required")

    followers: list[dict[str, Any]] = []
    seen = {leader_unit}
    for item in raw_followers:
        if not isinstance(item, dict):
            return make_tool_response(success=False, message="each follower must be an object")
        robot_id = str(item.get("robot_id", "")).strip()
        unit_id = await self._resolve_to_unit_id(robot_id)
        if unit_id is None:
            return make_tool_response(success=False, message=_message_unit_not_bound(robot_id))
        ok, distance, message = _finite_float(item.get("distance_m"), "distance_m")
        if not ok or distance <= 0.0:
            return make_tool_response(success=False, message=message or "distance_m must be positive")
        if unit_id in seen:
            return make_tool_response(success=False, message=f"duplicate formation unit: {unit_id}")
        seen.add(unit_id)
        followers.append({"unit_id": unit_id, "distance_m": distance})
    return await self._post_qt(
        path=QT_FOLLOW_FORMATION_SEND_PATH,
        json_body={"leader_id": leader_unit, "followers": followers},
        robot_id_for_lock=None,
        op_name="send_follow_formation",
    )

async def get_follow_formation_status(self) -> str:
    return await self._run_http(
        method="GET",
        url=qt_url(QT_FOLLOW_FORMATION_STATUS_PATH),
        json_body=None,
        robot_id_for_lock=None,
        op_name="get_follow_formation_status",
    )

async def goto_follow_formation(self, *, x: float, y: float) -> str:
    ok_x, target_x, msg_x = _finite_float(x, "x")
    ok_y, target_y, msg_y = _finite_float(y, "y")
    if not ok_x or not ok_y:
        return make_tool_response(success=False, message=msg_x or msg_y)
    return await self._post_qt(
        path=QT_FOLLOW_FORMATION_TARGET_PATH,
        json_body={"x": target_x, "y": target_y},
        robot_id_for_lock=None,
        op_name="goto_follow_formation",
    )
```

- [ ] **Step 4: Run focused and full adapter tests**

```powershell
python -m pytest tests\test_robot_adapter.py -q
```

Expected: all adapter tests pass.

### Task 4: Expose unambiguous MCP tools and remove Python-global status dependence

**Files:**
- Modify: `mcp/main.py`
- Test: `mcp/tests/test_mcp_tools.py`

- [ ] **Step 1: Write failing MCP registration/dispatch tests**

Add tests proving these tools exist and delegate exactly once:

```python
async def test_send_follow_formation_tool_delegates_to_adapter(app_tools, adapter_spy):
    await app_tools["send_follow_formation"](
        leader_id="GV1",
        followers_json='[{"robot_id":"GV2","distance_m":0.3}]',
    )
    assert adapter_spy.calls == [
        ("send_follow_formation", {"leader_id": "GV1", "followers_json": '[{"robot_id":"GV2","distance_m":0.3}]'})
    ]

async def test_get_formation_status_reads_console_adapter(app_tools, adapter_spy):
    await app_tools["get_formation_status"]()
    assert adapter_spy.calls == [("get_follow_formation_status", {})]
```

- [ ] **Step 2: Run focused tests and verify RED**

```powershell
python -m pytest tests\test_mcp_tools.py -k "follow_formation or formation_status" -q
```

- [ ] **Step 3: Add the tools and geometric compatibility name**

Inside `create_app()` add:

```python
@mcp.tool
async def send_follow_formation(leader_id: str, followers_json: str) -> str:
    return await adapter.send_follow_formation(
        leader_id=leader_id,
        followers_json=followers_json,
    )

@mcp.tool
async def goto_follow_formation(x: float, y: float) -> str:
    return await adapter.goto_follow_formation(x=x, y=y)

@mcp.tool
async def get_formation_status() -> str:
    return await adapter.get_follow_formation_status()

@mcp.tool
async def execute_geometric_formation(
    formation_type: str,
    unit_ids_csv: str = "",
    spacing_m: float = 1.0,
    anchor_json: str = "",
    heading_rad: float = 0.0,
    tolerance_m: float = 0.15,
    timeout_ms: int = 30000,
) -> str:
    return await adapter.execute_formation(
        formation_type=formation_type,
        unit_ids_csv=unit_ids_csv,
        spacing_m=spacing_m,
        anchor_json=anchor_json,
        heading_rad=heading_rad,
        tolerance_m=tolerance_m,
        timeout_ms=timeout_ms,
    )
```

Keep old geometric names only for compatibility. Do not use `active_formation_registry` for the public status or target flow.

- [ ] **Step 4: Run MCP tool tests**

```powershell
python -m pytest tests\test_mcp_tools.py -q
```

Expected: all MCP tool tests pass.

### Task 5: Add deterministic natural-language mode selection and cross-mode guards

**Files:**
- Modify: `mcp/deepseek_mcp_client.py`
- Test: `mcp/tests/test_deepseek_mcp_client.py`

- [ ] **Step 1: Write failing pure routing tests**

```python
def test_ambiguous_formation_requires_mode_selection():
    state = FormationDialogState()
    result = route_formation_input("进行编队", state)
    assert result.prompt_only is True
    assert result.mode is None
    assert "1. Console 跟随编队" in result.message
    assert "2. 几何编队" in result.message

def test_numeric_selection_enters_follow_mode():
    state = FormationDialogState(awaiting_mode=True)
    result = route_formation_input("1", state)
    assert result.mode == FormationMode.CONSOLE_FOLLOW

def test_explicit_triangle_enters_geometric_mode_without_menu():
    state = FormationDialogState()
    result = route_formation_input("让三辆车排成边长2米的三角形", state)
    assert result.mode == FormationMode.GEOMETRIC
    assert result.prompt_only is False
```

- [ ] **Step 2: Write failing agent-loop guard tests**

Simulate LLM output and assert:

```python
def test_follow_mode_blocks_geometric_tool(monkeypatch, capsys):
    import deepseek_mcp_client as client
    inputs = iter(["进行编队", "1", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    monkeypatch.setattr(
        client,
        "call_llm",
        lambda *args: {"tool": "execute_geometric_formation", "args": {"formation_type": "line"}},
    )
    calls = []
    monkeypatch.setattr(client, "run_mcp_call", lambda *args: calls.append(args) or '{"success":true}')
    client.main()
    assert all(call[1] != "execute_geometric_formation" for call in calls)
    assert "forbids geometric formation tools" in capsys.readouterr().out

def test_failed_follow_send_does_not_allow_autonomous_recovery(monkeypatch, capsys):
    import deepseek_mcp_client as client
    inputs = iter(["建立Console跟随编队，GV1领导，GV2间距0.3米", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    llm_results = iter([
        {"tool": "send_follow_formation", "args": {
            "leader_id": "GV1",
            "followers_json": '[{"robot_id":"GV2","distance_m":0.3}]',
        }},
        [
            {"tool": "stop_active_formation", "args": {}},
            {"tool": "send_follow_formation", "args": {
                "leader_id": "GV1",
                "followers_json": '[{"robot_id":"GV2","distance_m":0.3}]',
            }},
        ],
        {"done": True, "message": "队形发送失败，未执行自动恢复。"},
    ])
    monkeypatch.setattr(client, "call_llm", lambda *args: next(llm_results))
    calls = []
    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "send_follow_formation":
            return '{"success":false,"message":"GV2 RPC failed"}'
        return '{"success":true,"data":{"items":[]}}'
    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)
    client.main()
    assert calls.count("send_follow_formation") == 1
    assert "stop_active_formation" not in calls

def test_follow_target_uses_goto_follow_formation_not_generic_point_guard(monkeypatch, capsys):
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    assert allowed_formation_tool("goto_follow_formation", state)
    assert not allowed_formation_tool("goto_pose_batch", state)
    assert follow_target_completed("goto_follow_formation", {"success": True})
```

- [ ] **Step 3: Run focused client tests and verify RED**

```powershell
python -m pytest tests\test_deepseek_mcp_client.py -k "formation" -q
```

- [ ] **Step 4: Implement the dialog state and prompt rules**

Add:

```python
class FormationMode(str, Enum):
    CONSOLE_FOLLOW = "console_follow"
    GEOMETRIC = "geometric"

@dataclass
class FormationDialogState:
    awaiting_mode: bool = False
    mode: FormationMode | None = None
    follow_failure_seen: bool = False
    follow_send_seen_this_turn: bool = False
```

`route_formation_input` must intercept only ambiguous entry commands when no mode is active. Explicit follow/geometric requests set the mode directly. A numeric/text selection while `awaiting_mode` sets the selected mode and injects an explicit semantic message into LLM history.

Replace the formation section of `build_system_prompt()` with:

```text
FORMATION HAS TWO DISTINCT MODES.
For ambiguous formation requests, do not call a tool; the client asks the user to choose.
Console follow formation: require Leader, ordered Followers, and every distance; never default spacing.
Use send_follow_formation exactly once, then goto_follow_formation for targets.
Geometric formation: use execute_geometric_formation only for explicit independent geometric placement.
Never use cancel, stop, retry, or per-follower navigation as automatic recovery.
```

- [ ] **Step 5: Implement tool-call guards**

Before `run_mcp_call`:

```python
if state.mode is FormationMode.CONSOLE_FOLLOW and tool_name in GEOMETRIC_FORMATION_TOOLS:
    reject("Console follow mode forbids geometric formation tools")
if state.mode is FormationMode.GEOMETRIC and tool_name in FOLLOW_FORMATION_TOOLS:
    reject("Geometric mode forbids follow formation tools")
if state.follow_failure_seen and not user_explicitly_requested_recovery(user_text):
    if tool_name in AUTO_RECOVERY_TOOLS or tool_name == "send_follow_formation":
        reject("Automatic recovery is forbidden after follow-formation failure")
```

Track successful `goto_follow_formation` as completion of a follow target so the existing `send_move` absolute-point guard does not fire.

- [ ] **Step 6: Run client tests and the full Python suite**

```powershell
python -m pytest tests\test_deepseek_mcp_client.py -q
python -m pytest tests -q
```

Expected: client tests pass; any unavailable optional integration dependency is reported separately from product regressions.

### Task 6: Document and perform end-to-end verification

**Files:**
- Modify: `mcp/README.md`
- Verify: `mcp/logs/client.log`, Console UI/runtime log

- [ ] **Step 1: Document both modes with paste-ready examples**

Add examples:

```text
用户：进行编队
Agent：请选择 1. Console 跟随编队 / 2. 几何编队

用户：1
用户：GV1 为 Leader，GV2 距离前车 0.3 米
Agent：请求 0.3 米，Console 安全规则实际采用 0.5 米，队形发送成功。

用户：前往 (5, 6)
Agent：只向 GV1 下发目标点，GV2 通过 Follow 模式跟随。
```

- [ ] **Step 2: Run static and automated verification**

```powershell
cd E:\MCP-IDL\mcp
python -m py_compile deepseek_mcp_client.py main.py robot_adapter.py config.py
python -m pytest tests\test_robot_adapter.py tests\test_mcp_tools.py tests\test_deepseek_mcp_client.py -q
```

Run the Qt test/build commands from Tasks 1 and 2 with the compatible Qt MSVC 32-bit/ILU environment.

- [ ] **Step 3: Run the live Console sequence**

With Console and two vehicles online:

```text
查看当前车辆状态
设置 GV1 为领导者
进行编队
1
GV2 与前车间距 0.3 米
前往目标点 (5, 6)
```

Verify from logs and poses:

- No formation tool runs before selection and spacing.
- Exactly one `/api/formation/send_follow` request occurs.
- Response states requested `0.3m`, effective `0.5m`.
- Exactly one `/api/formation/goto_target` occurs.
- The target RPC is sent only to GV1.
- No `/api/formation/execute`, cancel, stop-all, per-robot stop, or Follower `goto_pose` occurs.

- [ ] **Step 4: Record environment limitations without weakening results**

If the Qt/ILU build cannot run in the current shell, record the exact unavailable compiler/library evidence and still complete Python tests and source-level checks. Do not claim C++ verification passed without executable output.
