# MCP Task Architecture Correctness Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Close the remaining task-architecture correctness gaps while preserving the vehicle programs, five protected base IDLs, generated RPC semantics, and legacy/debug compatibility paths.

**Architecture:** Keep FastMCP as a thin task facade and keep Console as the authoritative task state owner. Add conservative capability/formation policies and canonical unit resolution at the Console boundary, normalize every production task response to the MCP-IDL payload shape, and use the existing `LegacyIdlAdapter` injection seam for behavior tests.

**Tech Stack:** Python 3.10, pytest, FastMCP, C++11, Qt 5.12, Qt Test, ILU/CORBA generated stubs.

**Repository note:** `E:\MCP-IDL\.git` is empty, so worktree and commit steps are unavailable. Each task ends with an explicit test checkpoint instead.

---

### Task 1: Stable Python Task Contract and Formation Wire Values

**Files:**
- Modify: `mcp/idl/mcp_swarm_task.idl:58-62`
- Modify: `mcp/task_api/contracts.py`
- Modify: `mcp/console_client/console_task_client.py`
- Modify: `mcp/robot_adapter.py`
- Test: `mcp/tests/test_task_architecture.py`
- Test: `mcp/tests/test_robot_adapter.py`

- [ ] **Step 1: Write failing contract tests**

Add tests asserting that lowercase formation values are present in the IDL and that failed task responses are normalized into a full TaskResult:

```python
def test_idl_formation_values_match_mcp_wire_values() -> None:
    text = IDL_PATH.read_text(encoding="utf-8")
    enum = text.split("enum FormationType", 1)[1].split("};", 1)[0]
    assert {"line", "triangle", "column"} <= set(re.findall(r"\b\w+\b", enum))


def test_failed_task_response_is_normalized_to_task_result() -> None:
    raw = json.dumps({
        "success": False,
        "message": "unit not bound",
        "data": None,
        "error_code": "UNIT_NOT_FOUND",
    })
    normalized = json.loads(normalize_task_response(raw, task_type="navigate_to"))
    assert normalized["success"] is False
    assert normalized["data"]["task_type"] == "navigate_to"
    assert normalized["data"]["state"] == "REJECTED"
    assert normalized["data"]["error_code"] == "UNIT_NOT_FOUND"
    assert task_payload_has_contract_shape(normalized["data"])
```

Add an async `ConsoleTaskClient.navigate_to` test where the adapter returns the failure envelope above and assert the normalized full payload is returned.

- [ ] **Step 2: Run the focused tests and verify RED**

```powershell
cd E:\MCP-IDL
python -m pytest mcp/tests/test_task_architecture.py mcp/tests/test_robot_adapter.py -q
```

Expected: failures because the IDL enum is uppercase and `normalize_task_response` does not exist.

- [ ] **Step 3: Implement minimal Python normalization**

Change the task IDL enum to:

```idl
enum FormationType {
  line,
  triangle,
  column
};
```

Add to `contracts.py`:

```python
import time


def empty_task_result(*, task_type: str, state: str, message: str,
                      error_code: str = "") -> dict[str, Any]:
    return {
        "success": state in {"PENDING", "RUNNING", "COMPLETED", "PARTIAL_COMPLETED"},
        "task_id": "",
        "task_type": task_type,
        "state": state,
        "progress_pct": 100.0 if state in TASK_STATES - {"PENDING", "RUNNING"} else 0.0,
        "message": message,
        "error_code": error_code,
        "unit_results": [],
        "elapsed_ms": 0,
        "started_at_ms": int(time.time() * 1000),
        "cancellation_effect": "NOT_APPLICABLE",
    }


def normalize_task_response(raw: str, *, task_type: str) -> str:
    parsed = parse_response(raw)
    data = parsed.get("data")
    if task_payload_has_contract_shape(data):
        return raw
    error_code = str(parsed.get("error_code", "") or "INTERNAL_ERROR")
    state = "REJECTED" if error_code in {
        "UNIT_NOT_FOUND", "UNIT_OFFLINE", "UNIT_BUSY", "TASK_CONFLICT",
        "TARGET_OUT_OF_BOUNDS", "SAFETY_REJECTED", "FORMATION_NOT_READY",
        "FORMATION_CONFLICT", "UNSUPPORTED_CAPABILITY", "RPC_DISABLED",
    } else "FAILED"
    parsed["data"] = empty_task_result(
        task_type=task_type,
        state=state,
        message=str(parsed.get("message", "task failed")),
        error_code=error_code,
    )
    parsed["error_code"] = error_code
    return json.dumps(parsed, ensure_ascii=False)
```

Update every task-returning `ConsoleTaskClient` method to call `normalize_task_response(raw, task_type=<canonical type>)`. Update RobotAdapter local validation failures to include explicit error codes through the existing response envelope.

- [ ] **Step 4: Run tests and verify GREEN**

Run the Step 2 command. Expected: all focused tests pass.

### Task 2: Canonical Console Unit Identity and Truthful Capability Policy

**Files:**
- Modify: `SAU/Console/LegacyIdlAdapter.h`
- Modify: `SAU/Console/LegacyIdlAdapter.cpp`
- Modify: `SAU/Console/HttpApiExecutor.cpp`
- Modify: `SAU/Console/TaskOrchestrator.h`
- Modify: `SAU/Console/TaskOrchestrator.cpp`
- Modify: `SAU/Console/tests/tests.pro`
- Modify: `SAU/Console/tests/test_formation.cpp`
- Test: `SAU/Console/tests/test_task_rpc_static.py`

- [ ] **Step 1: Write failing C++ behavior tests**

Add `TaskManager.cpp`, `TaskOrchestrator.cpp`, and `LegacyIdlAdapter.cpp` to `tests.pro`. Add pure policy tests to `test_formation.cpp`:

```cpp
void testTaskCapabilityPolicy_RealOnlyRpcDisabled() {
    const TaskCapabilityPolicy p = TaskOrchestrator::capabilityPolicy(0, 2, false);
    QVERIFY(!p.targetPointNavigation);
    QVERIFY(!p.pathTasks);
    QVERIFY(!p.staticFormation);
    QVERIFY(!p.followFormation);
    QVERIFY(!p.realUnitRpc);
}

void testTaskCapabilityPolicy_MockFleetSupportsIndependentTasks() {
    const TaskCapabilityPolicy p = TaskOrchestrator::capabilityPolicy(2, 0, false);
    QVERIFY(p.targetPointNavigation);
    QVERIFY(p.pathTasks);
    QVERIFY(p.staticFormation);
    QVERIFY(!p.followFormation);
}

void testLogicalUnitAliasComparison() {
    QVERIFY(logicalUnitIdsEqual("GV1", "GV01"));
    QVERIFY(!logicalUnitIdsEqual("GV1", "GV02"));
}
```

Extend the static test to assert follow creation calls `LegacyIdlAdapter::canonicalUnitId` instead of exact `sbhForUid` checks.

- [ ] **Step 2: Verify RED**

Run the Python static test first:

```powershell
python -m pytest SAU/Console/tests/test_task_rpc_static.py -q
```

Expected: failure because `canonicalUnitId` and `capabilityPolicy` are absent.

If the Qt/MSVC build environment is available, rebuild and run the C++ test executable; otherwise record the C++ build as an explicit environment limitation and continue using the static plus Python policy coverage.

- [ ] **Step 3: Add canonical ID and capability helpers**

Add to `LegacyIdlAdapter`:

```cpp
virtual QString canonicalUnitId(const QString &unitId) const;
```

The implementation must prefer an exact hash-table key, then enumerate `Units_Hash_Table` and return the stored key whose value satisfies `logicalUnitIdsEqual`. `isBound`, `isMock`, `setTaskPoint`, `setTaskPath`, `currentPose`, and `stopUnit` must resolve through that canonical ID before lookup.

Add to `TaskOrchestrator.h`:

```cpp
struct TaskCapabilityPolicy {
    bool targetPointNavigation = false;
    bool pathTasks = false;
    bool staticFormation = false;
    bool followFormation = false;
    bool realUnitRpc = false;
};

static TaskCapabilityPolicy capabilityPolicy(int mockGroundCount,
                                             int realGroundCount,
                                             bool realRpcEnabled);
```

Implement it so executable ground count is `mockGroundCount + (realRpcEnabled ? realGroundCount : 0)`, follow requires two real units plus enabled RPC, and real RPC requires one real unit plus enabled RPC.

Use this helper in `/api/task/capabilities`. In `/api/task/fleet_snapshot`, report Mock `online` from simulator state; report real `online=false` and add `online_verified=false` unless a real liveness RPC was actually performed. Keep `rpc_available` separate.

- [ ] **Step 4: Replace follow-route exact lookups**

Resolve the leader and every follower with `canonicalUnitId` before duplicate checks, reservations, record creation, and scoped RPC setup. Reject aliases resolving to the same canonical member as duplicates.

- [ ] **Step 5: Run focused tests**

```powershell
python -m pytest SAU/Console/tests/test_task_rpc_static.py mcp/tests/test_task_architecture.py -q
```

Expected: all pass. Run the current C++ test binary only after a fresh successful rebuild; never use the stale binary as evidence.

### Task 3: Conservative Follow Formation Lifecycle

**Files:**
- Modify: `SAU/Console/HttpApiExecutor.cpp`
- Modify: `SAU/Console/HttpApiExecutor.h`
- Modify: `SAU/Console/console.cpp`
- Modify: `SAU/Console/console.h`
- Modify: `SAU/Console/tests/test_task_rpc_static.py`
- Modify: `SAU/Console/tests/test_formation.cpp`

- [ ] **Step 1: Write failing lifecycle tests**

Add static assertions that the all-Mock branch returns `UNSUPPORTED_CAPABILITY` before `reserveUnitsIfAvailable`, and that pre-dispatch failures clear the local record instead of leaving `FAILED`.

Add pure C++ decision tests around a new helper:

```cpp
void testFollowSetupPolicy_AllMockIsUnsupported() {
    QCOMPARE(TaskOrchestrator::followSetupPolicy(2, 0, false),
             FollowSetupPolicy::UnsupportedMock);
}

void testFollowSetupPolicy_RealRpcDisabledFailsBeforeSetup() {
    QCOMPARE(TaskOrchestrator::followSetupPolicy(0, 2, false),
             FollowSetupPolicy::RpcDisabled);
}

void testFollowSetupPolicy_RealRpcEnabledCanDispatch() {
    QCOMPARE(TaskOrchestrator::followSetupPolicy(0, 2, true),
             FollowSetupPolicy::DispatchReal);
}
```

- [ ] **Step 2: Verify RED**

```powershell
python -m pytest SAU/Console/tests/test_task_rpc_static.py -q
```

Expected: lifecycle assertions fail because the current route reserves first and returns Mock `READY`.

- [ ] **Step 3: Implement preflight before reservation**

Resolve all canonical members, count Mock and real members, then apply:

```cpp
enum class FollowSetupPolicy {
    UnsupportedMock,
    UnsupportedMixed,
    RpcDisabled,
    DispatchReal,
};
```

All-Mock and mixed requests return a complete FormationStatus-shaped failure with `UNSUPPORTED_CAPABILITY`, leave `consoleFollowFormationRecord` at `IDLE`, and never reserve units. Real-only with RPC disabled returns `RPC_DISABLED`, also leaving `IDLE` and unreserved. Only `DispatchReal` reserves members and calls `createScopedGroundFollow`.

- [ ] **Step 4: Make rollback state explicit**

Extend the internal follow record with:

```cpp
bool physicalSetupAttempted = false;
QStringList physicalMembers;
```

Set these immediately before the first real follow RPC. If setup fails and the internal rollback succeeds, release reservations and clear the record to `IDLE`. If rollback fails, retain `FAILED`, physical member IDs, and reservations so disband can retry safely.

`disbandFormation` must call `clearScopedGroundFollow` only when `physicalSetupAttempted` is true, and only for `physicalMembers`. A failed record with no attempted setup clears locally without RPC.

- [ ] **Step 5: Run lifecycle tests**

Run the Step 2 command and the rebuilt C++ tests when available. Expected: all lifecycle tests pass.

### Task 4: Ordered Mock Path Execution

**Files:**
- Modify: `SAU/Console/TaskOrchestrator.h`
- Modify: `SAU/Console/TaskOrchestrator.cpp`
- Modify: `SAU/Console/tests/test_formation.cpp`
- Modify: `SAU/Console/tests/test_task_rpc_static.py`

- [ ] **Step 1: Write a failing path progression test**

Extract path target selection into a small state object and test it directly:

```cpp
void testMockPathProgressionVisitsEveryPoint() {
    QJsonArray points;
    points.append(QJsonObject{{"x", 1.0}, {"y", 0.0}});
    points.append(QJsonObject{{"x", 1.0}, {"y", 1.0}});
    MockPathProgress progress(points);
    QCOMPARE(progress.currentTarget().value("x").toDouble(), 1.0);
    QCOMPARE(progress.currentTarget().value("y").toDouble(), 0.0);
    QVERIFY(!progress.advance());
    QCOMPARE(progress.currentTarget().value("y").toDouble(), 1.0);
    QVERIFY(progress.advance());
}
```

The final return values mean `false` while another target remains and `true` after the final target is completed.

- [ ] **Step 2: Verify RED**

The C++ test must fail to compile because `MockPathProgress` is absent. The static test must also fail until `dispatchPath` stops calling final-point-only polling for Mock.

- [ ] **Step 3: Implement Mock-only ordered progression**

Keep the real path dispatch unchanged. After `setTaskPath`, branch on `result.mock`:

- real: poll only the final point, preserving current completion observability;
- Mock: retain the ordered `QJsonArray`, move toward the current point, advance only when within tolerance, and mark the task completed only after the last point.

Progress combines completed-point fraction with distance progress inside the active segment. Cancellation still stops the one registered timer.

- [ ] **Step 4: Run focused tests**

```powershell
python -m pytest SAU/Console/tests/test_task_rpc_static.py -q
```

Run fresh C++ tests when build tooling is available. Expected: ordered progression tests pass.

### Task 5: Console Failure Payloads and Legacy Route Cleanup

**Files:**
- Modify: `SAU/Console/HttpApiExecutor.cpp`
- Modify: `SAU/Console/HttpApiExecutor.h`
- Modify: `SAU/Console/tests/test_task_rpc_static.py`
- Modify: `mcp/tests/test_robot_adapter.py`

- [ ] **Step 1: Write failing response-shape and dead-code tests**

Add a static test that extracts the `/api/task/goto_pose` route and asserts no statements follow the canonical `return processRequest(.../api/task/navigate...)` inside that branch.

Add adapter tests for representative Console failures from `navigateTo`, `followPath`, `createStaticFormation`, `moveFollowFormation`, `cancelTask`, and `stopUnits`, asserting complete TaskResult fields after Python normalization.

- [ ] **Step 2: Verify RED**

```powershell
python -m pytest SAU/Console/tests/test_task_rpc_static.py mcp/tests/test_robot_adapter.py -q
```

Expected: dead-code and one or more response-shape assertions fail.

- [ ] **Step 3: Add immediate Console task-result construction**

Add a private helper in `HttpApiExecutor.cpp`:

```cpp
static QJsonObject immediateTaskResult(const QString &taskType,
                                       const QString &state,
                                       const QString &errorCode,
                                       const QString &message,
                                       const QStringList &unitIds = QStringList());
```

It returns every `TaskResult` field defined by the MCP IDL, creates one UnitTaskResult per supplied unit, uses `NOT_APPLICABLE`, and sets `started_at_ms` once. Use it for production task-route validation, capability, conflict, RPC-disabled, and dispatch failures that occur without a TaskManager snapshot.

For formation-status failures, always return all fields from `FollowFormationSnapshot::toJson()` plus `error_code`; never return `data=null` from a production formation method.

- [ ] **Step 4: Remove unreachable legacy code**

Keep only:

```cpp
if (path == QStringLiteral("/api/task/goto_pose") && method == QStringLiteral("POST")) {
    return processRequest(method, QStringLiteral("/api/task/navigate"),
                          query, body, httpStatus);
}
```

Delete the old unreachable implementation up to the next route. Do not remove `/api/task/goto_pose_batch`, `/api/formation/execute`, or any low-level compatibility route.

- [ ] **Step 5: Run focused tests**

Run the Step 2 command. Expected: all pass.

### Task 6: Protected-Scope and End-to-End Verification

**Files:**
- Verify: all modified files above
- Verify unchanged: `SAU/Ilu/interfaces/i/air_unit.idl`
- Verify unchanged: `SAU/Ilu/interfaces/i/console.idl`
- Verify unchanged: `SAU/Ilu/interfaces/i/general_unit.idl`
- Verify unchanged: `SAU/Ilu/interfaces/i/ground_unit.idl`
- Verify unchanged: `SAU/Ilu/interfaces/i/monitor.idl`

- [ ] **Step 1: Run Python syntax checks**

```powershell
cd E:\MCP-IDL
python -m py_compile mcp/main.py mcp/robot_adapter.py mcp/config.py mcp/task_api/contracts.py mcp/task_api/task_service.py mcp/task_api/capability_service.py mcp/console_client/console_task_client.py
```

Expected: exit code 0 with no output.

- [ ] **Step 2: Run the complete non-live focused suite**

```powershell
python -m pytest mcp/tests/test_agent_system.py mcp/tests/test_console_follow_wizard.py mcp/tests/test_formation_orchestrator.py mcp/tests/test_main_formation_tools.py mcp/tests/test_production_client_contract.py mcp/tests/test_robot_adapter.py mcp/tests/test_task_architecture.py SAU/Console/tests/test_runtime_text_encoding.py SAU/Console/tests/test_task_rpc_static.py -q
```

Expected: all collected tests pass. Keep live HTTP scripts excluded until Console is explicitly started.

- [ ] **Step 3: Verify protected IDL hashes**

```powershell
python -m pytest SAU/Console/tests/test_task_rpc_static.py::test_protected_base_idl_hashes_are_unchanged -q
```

Expected: `1 passed`.

- [ ] **Step 4: Build and run fresh Console tests if toolchain is available**

Use Qt 5.12.4 with the x86 MSVC 2017-compatible toolchain and existing ILU x86 libraries. Regenerate the test Makefile from `SAU/Console/tests/tests.pro`, build, and run `test_formation.exe`. If the compatible compiler environment is unavailable, report that limitation explicitly; do not treat the stale 2026-07-11 binary as verification.

- [ ] **Step 5: Review the requirement checklist**

Confirm all twelve production tools still match the MCP-IDL interface, low-level tools remain hidden by default and opt-in in debug mode, legacy HTTP routes remain, Mock follow is explicitly unsupported, real setTaskPoint/setTaskPath/getCurrentPose/Unit_MA_Stop calls remain unchanged, and all five protected IDLs retain their hashes.
