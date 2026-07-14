# Console Follow Formation Fix Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Keep vehicle-side continuous follower position streams alive and make every follower's `ALeader` match the ordered ground chain.

**Architecture:** Console computes the direct parent of each ordered member, configures role/parent/mode first, then dispatches the formation topology last. Existing HTTP and ILU/RPC contracts remain unchanged.

**Tech Stack:** C++11, Qt 5.12 QtTest, ILU C RPC stubs.

---

### Task 1: Chain parent mapping regression

**Files:**
- Modify: `SAU/Console/tests/test_formation.cpp`
- Modify: `SAU/Console/console.h`
- Modify: `SAU/Console/console.cpp`

- [ ] Add a QtTest that expects `groundFollowParentIds("GV1", ["GV2", "GV3"])` to return `['', 'GV1', 'GV2']` and rejects duplicate/empty IDs.
- [ ] Build and run that focused test; expect failure because the helper is not declared.
- [ ] Implement the pure helper with ordered-chain semantics and input validation.
- [ ] Rebuild and run the focused test; expect PASS.

### Task 2: Preserve vehicle-side sendPoint threads

**Files:**
- Modify: `SAU/Console/tests/test_task_rpc_static.py`
- Modify: `SAU/Console/console.cpp`

- [ ] Add a static regression test that extracts `createScopedGroundFollow` and asserts the member `configureUnitMode` loop appears before `setFormationWithResult(follow)`, with no later `configureUnitMode` call.
- [ ] Run the focused Python test; expect failure under the current post-dispatch ordering.
- [ ] Change `createScopedGroundFollow` to resolve each member's direct-parent SBH, configure role/parent/Follow mode before formation dispatch, and remove the post-dispatch configuration loop.
- [ ] Keep rollback behavior and failure reporting unchanged; return before formation dispatch if any member configuration fails.
- [ ] Run the focused Python test; expect PASS.

### Task 3: Build and regression verification

**Files:**
- Verify: `SAU/Console/tests/test_formation.cpp`
- Verify: `SAU/Console/tests/test_task_rpc_static.py`

- [ ] Build the release Qt test binary with the existing MSVC/qmake Makefile.
- [ ] Run the focused Qt tests for chain construction and parent mapping.
- [ ] Run the Console Python static tests.
- [ ] Run the full `test_formation.exe` suite and report any environment-only failures separately from code failures.
- [ ] Confirm protected IDLs and vehicle-side sources were not modified.
