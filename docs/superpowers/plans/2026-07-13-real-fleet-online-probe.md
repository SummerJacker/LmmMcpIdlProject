# Real Fleet Online Probe Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Verify real ground vehicles online through their existing read-only pose RPC so GV1 and GV3 can be selected for Console follow formation.

**Architecture:** Keep binding classification and the follow wizard unchanged. Enhance only the task fleet snapshot: Mock online state still comes from the simulator; a real ground binding is probed through `LegacyIdlAdapter::currentPose` when real RPC is enabled, and is declared online only after a successful probe. Align GV3's MCP deployment intent with its real runtime role.

**Tech Stack:** C++17/Qt 5.12, ILU C stubs, Python 3, pytest, QtTest/qmake/nmake.

---

### Task 1: Lock the real-vehicle snapshot behavior with failing tests

**Files:**
- Modify: `SAU/Console/tests/test_task_rpc_static.py`
- Modify: `mcp/tests/test_robot_adapter.py`

- [x] **Step 1: Add a static route test**

Add a test that slices the `/api/task/fleet_snapshot` handler and requires it to call `LegacyIdlAdapter::instance().currentPose(unitId)`, set `onlineVerified` from an actual probe, and include a probe error on failure.

- [x] **Step 2: Add a deployment configuration test**

Load `mcp/robots.json`, find `unit_id == "GV3"`, and assert its `mode` is `real`.

- [x] **Step 3: Verify RED**

Run:

```powershell
python -m pytest SAU\Console\tests\test_task_rpc_static.py -q
Push-Location mcp; python -m pytest tests\test_robot_adapter.py -q; Pop-Location
```

Expected: the new snapshot test fails because real units are hard-coded offline, and the configuration test fails because GV3 is currently `sim`.

### Task 2: Implement the minimal verified-online probe

**Files:**
- Modify: `SAU/Console/HttpApiExecutor.cpp`

- [x] **Step 1: Replace hard-coded real offline state**

Inside `/api/task/fleet_snapshot`, retain the Mock branch. For a non-Mock ground unit with real RPC enabled, call:

```cpp
const TaskPoseResult probe = LegacyIdlAdapter::instance().currentPose(unitId);
online = probe.success;
onlineVerified = true;
if (!probe.success)
    probeError = probe.message;
```

Do not probe when RPC is disabled or for a non-ground unit. Return `probe_error` only when it is non-empty.

- [x] **Step 2: Verify the focused static test is GREEN**

Run:

```powershell
python -m pytest SAU\Console\tests\test_task_rpc_static.py -q
```

Expected: all static RPC tests pass, including protected IDL hashes.

### Task 3: Align GV3 deployment intent

**Files:**
- Modify: `mcp/robots.json`

- [x] **Step 1: Change only GV3 mode**

Change the GV3 entry from `"mode": "sim"` to `"mode": "real"`. Leave GV2 unchanged.

- [x] **Step 2: Verify the focused Python test is GREEN**

Run:

```powershell
Push-Location mcp; python -m pytest tests\test_robot_adapter.py -q; Pop-Location
```

Expected: all adapter tests pass.

### Task 4: Build and regression-test Console and MCP

**Files:**
- No additional source files.

- [x] **Step 1: Build Console tests and release binary**

Run `nmake /NOLOGO release` under the Visual Studio 32-bit environment in both `SAU/Console/tests` and `SAU/Console`.

- [x] **Step 2: Run C++ and Python regression suites**

Run the QtTest executable and the Python suite excluding manual/external API scripts. Expected results are zero failures.

- [ ] **Step 3: Perform a read-only live verification**

Start or deploy the rebuilt Console with `SAU_ENABLE_REAL_RPC=1`, then call only:

```text
GET /api/task/fleet_snapshot
```

Confirm GV1 and GV3 each report `run_mode=real`, `online=true`, and `online_verified=true`. Do not send navigation or movement commands.

No Git commit is included because the user explicitly requested to manage Git separately.
