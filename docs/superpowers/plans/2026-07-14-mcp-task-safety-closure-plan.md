# MCP Task Safety Closure Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking. The user explicitly owns Git operations, so this plan makes no commits.

**Goal:** Close the remaining credential, numeric-safety, follow-formation, physical-ownership, response-contract, discovery, and task-aggregation gaps without changing protected IDLs or vehicle programs.

**Architecture:** Python performs early validation and produces stable MCP payloads; Console repeats all physical safety checks and owns authoritative task/formation state. Real units whose physical stop or cleanup cannot be confirmed remain quarantined in `TaskManager` until a later successful Stop clears uncertainty.

**Tech Stack:** Python 3.10, pytest, FastMCP, Qt 5.12/C++17-compatible code, QtTest, legacy ILU C stubs.

---

### Task 1: Remove Embedded Credentials

**Files:**
- Modify: `mcp/deepseek_mcp_client.py`
- Delete: `mcp/deepseek_mcp_client.py.bak`
- Test: `mcp/tests/test_production_client_contract.py`

- [ ] **Step 1: Keep the credential regression red**

Use the existing assertion and add environment precedence coverage:

```python
def test_client_has_no_embedded_api_key() -> None:
    assert client.DEFAULT_DEEPSEEK_API_KEY == ""

def test_api_key_is_loaded_from_environment(monkeypatch) -> None:
    monkeypatch.setenv("DEEPSEEK_API_KEY", "env-test-key")
    assert client.configured_deepseek_api_key() == "env-test-key"
```

- [ ] **Step 2: Run the focused test and verify RED**

Run: `python -m pytest tests/test_production_client_contract.py -q`

Expected: the embedded-key assertion fails on the current source.

- [ ] **Step 3: Implement environment-only loading**

Set `DEFAULT_DEEPSEEK_API_KEY = ""`, add:

```python
def configured_deepseek_api_key() -> str:
    return os.getenv("DEEPSEEK_API_KEY", "").strip()
```

and use that function at client startup. Remove `deepseek_mcp_client.py.bak` because it contains credential material.

- [ ] **Step 4: Run focused tests and verify GREEN**

Run: `python -m pytest tests/test_production_client_contract.py -q`

Expected: all tests pass and no `sk-` literal remains in Python source or backups.

### Task 2: Enforce MCP Safety and Stable Local Contracts

**Files:**
- Modify: `mcp/safety/validator.py`
- Modify: `mcp/robot_adapter.py`
- Modify: `mcp/task_api/contracts.py`
- Modify: `mcp/console_client/console_task_client.py`
- Modify: `mcp/task_api/capability_service.py`
- Modify: `mcp/main.py`
- Test: `mcp/tests/test_task_architecture.py`
- Test: `mcp/tests/test_robot_adapter.py`
- Test: `mcp/tests/test_main_formation_tools.py`

- [ ] **Step 1: Add RED tests for limits and payload shape**

Add assertions that:

```python
assert validate_follow_distance(0.49)[0] is False
assert validate_follow_distance(20.01)[0] is False
assert validate_follow_distance(20.0)[0] is True
assert validate_follow_target(1000.01, 0.0)[1] == "TARGET_OUT_OF_BOUNDS"
```

and that local unit lookup/validation failures contain complete `TaskResult` or `FormationStatus` fields with `UNIT_NOT_FOUND`/`SAFETY_REJECTED` rather than `INTERNAL_ERROR`.

- [ ] **Step 2: Run the new tests and verify RED**

Run: `python -m pytest tests/test_task_architecture.py tests/test_robot_adapter.py tests/test_main_formation_tools.py -q`

Expected: missing validators and incomplete formation/local failure payload assertions fail.

- [ ] **Step 3: Add shared Python validation**

Define:

```python
MIN_FOLLOW_DISTANCE_M = 0.5
MAX_FOLLOW_DISTANCE_M = 20.0

def validate_follow_distance(value: float) -> tuple[bool, str, str]: ...
def validate_follow_target(x: float, y: float) -> tuple[bool, str, str]: ...
```

Reuse `MAX_TARGET_COORD`. Call the validators before posting create/move follow requests.

- [ ] **Step 4: Add stable result builders**

In `contracts.py`, add builders returning every declared field:

```python
def rejected_task_response(task_type: str, error_code: str, message: str) -> str: ...
def failed_formation_response(error_code: str, message: str) -> str: ...
```

Use them from `main.py`, `RobotAdapter`, and `ConsoleTaskClient`; normalize create/status/disband formation responses as `FormationStatus` rather than passing arbitrary envelopes through.

- [ ] **Step 5: Make capability fallback conservative**

When `/api/task/capabilities` is unavailable, return false for unverified execution capabilities and explain that the old Console cannot establish current availability.

- [ ] **Step 6: Verify GREEN**

Run the same focused pytest command. Expected: all selected tests pass.

### Task 3: Resolve Runtime-Bound Unit IDs

**Files:**
- Modify: `mcp/robot_adapter.py`
- Test: `mcp/tests/test_robot_adapter.py`

- [ ] **Step 1: Add a RED dynamic-unit test**

Create an adapter whose `robots.json` manager lacks `GV4`, stub the authoritative robot-list response to contain `{"unit_id": "GV4"}`, and assert `_resolve_to_unit_id("GV4") == "GV4"`.

- [ ] **Step 2: Run the focused test and verify RED**

Run: `python -m pytest tests/test_robot_adapter.py -k dynamic_bound_unit -q`

Expected: current resolver returns `None`.

- [ ] **Step 3: Implement authoritative fallback resolution**

After local config and injected resolver checks, query the Console robot list, compare requested and returned unit IDs case-insensitively/logically, cache the canonical result briefly, and return `None` on transport failure without converting it to a false positive.

- [ ] **Step 4: Verify GREEN**

Run: `python -m pytest tests/test_robot_adapter.py -q`.

### Task 4: Enforce Console Follow Safety and RPC Acceptance

**Files:**
- Modify: `SAU/Console/SafetyValidator.h`
- Modify: `SAU/Console/SafetyValidator.cpp`
- Modify: `SAU/Console/HttpApiExecutor.cpp`
- Modify: `SAU/Console/console.h`
- Modify: `SAU/Console/console.cpp`
- Test: `SAU/Console/tests/test_formation.cpp`
- Test: `SAU/Console/tests/test_task_rpc_static.py`

- [ ] **Step 1: Add RED Qt tests for numeric rules**

Expose static pure helpers and assert:

```cpp
QVERIFY(SafetyValidator::isTaskTargetInBounds(1000.0, -1000.0));
QVERIFY(!SafetyValidator::isTaskTargetInBounds(1000.01, 0.0));
QVERIFY(SafetyValidator::isFollowDistanceAllowed(0.5));
QVERIFY(SafetyValidator::isFollowDistanceAllowed(20.0));
QVERIFY(!SafetyValidator::isFollowDistanceAllowed(20.01));
```

Add static checks proving the follow-move route calls the same validator before task creation.

- [ ] **Step 2: Run Qt/Python tests and verify RED**

Run the Console Python tests and rebuild/run `test_formation.exe`; expected failures are missing helper methods and missing route validation.

- [ ] **Step 3: Implement authoritative Console validation**

Add `minFollowDistanceM()`, `maxFollowDistanceM()`, `isTaskTargetInBounds`, and `isFollowDistanceAllowed`. Reject invalid follow distances before casting to float, and reject out-of-bounds Leader targets before creating the move task.

- [ ] **Step 4: Check `setFormation` acceptance**

Store the `CORBA_boolean` result from `Unit_rpc_setFormation`; a false result creates a failed Leader result and aborts setup even when ILU reports no exception.

- [ ] **Step 5: Make cleanup outcomes conservative**

Capture boolean results from role/mode/minor-mode cleanup. Treat an explicit accepted role reset as authoritative relation removal; record rejected or exception outcomes in `failedUnits`. Do not report complete cleanup when relationship removal is ambiguous.

- [ ] **Step 6: Verify GREEN**

Run Console Python tests and Qt tests; expected: all pass, including existing three-car chain tests.

### Task 5: Quarantine Uncertain Physical Control

**Files:**
- Modify: `SAU/Console/TaskManager.h`
- Modify: `SAU/Console/TaskManager.cpp`
- Modify: `SAU/Console/TaskOrchestrator.cpp`
- Modify: `SAU/Console/HttpApiExecutor.cpp`
- Test: `SAU/Console/tests/test_formation.cpp`
- Test: `SAU/Console/tests/test_task_rpc_static.py`

- [ ] **Step 1: Add RED TaskManager tests**

Add pure TaskManager tests that mark `GV1` uncertain and assert:

```cpp
QVERIFY(manager.isUnitControlUncertain("GV1"));
QVERIFY(manager.isUnitBusy("GV1"));
manager.clearUnitControlUncertain("GV1");
QVERIFY(!manager.isUnitControlUncertain("GV1"));
```

Add tests that `STATE_ONLY_CANCELLED` retains uncertainty while `CANCEL_CONFIRMED` does not.

- [ ] **Step 2: Run tests and verify RED**

Expected: quarantine APIs do not exist and cancelled tasks currently release all ownership.

- [ ] **Step 3: Implement quarantine state**

Add a normalized-unit `QHash<QString, QString> controlUncertainUnits_` plus:

```cpp
void markUnitControlUncertain(const QString &unitId, const QString &reason);
void clearUnitControlUncertain(const QString &unitId);
bool isUnitControlUncertain(const QString &unitId) const;
```

Include quarantine in `isUnitBusyLocked`. A task may release its normal reservation while quarantine continues to block reuse.

- [ ] **Step 4: Integrate cancellation, timeout, stop, and disband**

Mark real units uncertain when Stop fails or is not confirmed. On timeout, attempt Stop before finalization. A successful `stopUnits` clears quarantine for that unit. Disband keeps the formation owner reservation and returns failure when Leader Stop or relationship cleanup remains uncertain.

- [ ] **Step 5: Verify GREEN**

Run TaskManager/Console tests and assert new-task reservation fails for quarantined units.

### Task 6: Fix Progress, Aggregate Errors, and Path Construction

**Files:**
- Modify: `SAU/Console/TaskManager.cpp`
- Modify: `SAU/Console/LegacyIdlAdapter.cpp`
- Test: `SAU/Console/tests/test_formation.cpp`
- Test: `SAU/Console/tests/test_task_rpc_static.py`

- [ ] **Step 1: Add RED aggregation tests**

Create single and batch task fixtures. Assert a single subtask at 40% produces parent progress 40%, and a terminal failed subtask propagates its non-empty error/message to the parent.

- [ ] **Step 2: Add a RED path append static test**

Assert the append loop checks `ILU_ERRNOK(appendError)` and returns before `Ground_Unit_rpc_setTaskPath` on failure.

- [ ] **Step 3: Run tests and verify RED**

Expected: progress/error and append checks fail against current code.

- [ ] **Step 4: Implement aggregate updates**

Recompute parent progress for every task with subtasks. During finalization, choose a representative error/message with precedence `FAILED`, `TIMEOUT`, `CANCELLED`, then call `transitionTask(taskId, finalState, errorCode, message)`.

- [ ] **Step 5: Check append failures**

Initialize and test `ilu_Error` for every append; free the sequence/proxy and return `INTERNAL_ERROR` without dispatching a partial path.

- [ ] **Step 6: Verify GREEN**

Run Console Python and Qt test suites.

### Task 7: Full Verification

**Files:**
- Verify only; no protected IDL or vehicle file changes.

- [ ] **Step 1: Run MCP architecture suites**

Run:

```powershell
python -m pytest tests/test_task_architecture.py tests/test_robot_adapter.py tests/test_main_formation_tools.py tests/test_formation_orchestrator.py tests/test_production_client_contract.py tests/test_console_follow_wizard.py -q
```

Expected: zero failures.

- [ ] **Step 2: Run Console static tests**

Run: `python -m pytest test_task_rpc_static.py test_runtime_text_encoding.py -q`

Expected: zero failures.

- [ ] **Step 3: Rebuild and run Qt tests**

Use the existing Qt 5.12.4/MSVC environment, rebuild `test_formation.exe`, run with `-txt`, and require zero failures.

- [ ] **Step 4: Build the production Console**

Rebuild `SAU/Console/release/main_console.exe`; require exit code 0.

- [ ] **Step 5: Audit protected scope**

Run protected-IDL hash tests and a file-list inspection confirming no vehicle-side file, generated stub, binary, or unrelated formatting change was introduced.

- [ ] **Step 6: Prepare hardware handoff**

Document a non-automated three-car check: create `GV1 -> GV2 -> GV3`, move Leader, query formation status, cancel move, retry Stop if uncertainty is reported, and disband. Do not claim live-car success until the user runs this checklist.
