# MCP Task Safety Closure Design

## Scope

This change closes the remaining safety, state-consistency, and contract gaps found after the task-level MCP architecture refactor. It preserves the five protected base IDLs, generated RPC semantics, vehicle-side programs, legacy HTTP routes, Mock execution, and real ILU/RPC execution.

The work covers:

- removal of embedded API credentials;
- task-level numeric safety boundaries for follow movement and spacing;
- conservative ownership after uncertain physical cancellation;
- reliable follow-formation READY, rollback, and disband decisions;
- complete task and formation failure payloads;
- truthful capability fallback and dynamic unit resolution;
- correct single-task progress and aggregate error reporting;
- checked path construction errors;
- regression tests for every changed behavior.

Moving synchronous ILU calls to worker threads is explicitly deferred because it changes the Console threading model and needs an independent design and hardware soak test.

## Safety Decisions

### Navigation targets

`moveFollowFormation` uses the same world-coordinate boundary as `navigateTo`: both coordinates must be finite and within `[-1000.0, 1000.0]` metres. MCP validates early for useful errors, while Console repeats validation as the authoritative boundary before converting to `CORBA_float` or dispatching a task.

### Follow distance

Requested follower distance must be finite and within `[0.5, 20.0]` metres. Values below `0.5` are rejected instead of silently clamped, so the returned requested and effective distances cannot contradict the command. The rule is enforced in the Python adapter, Console HTTP route, and formation-construction validation before any float conversion or RPC call.

### Physical-control uncertainty

A task state transition is not sufficient evidence that a real vehicle stopped. A real unit enters a control-uncertain quarantine when any of these occur:

- task cancellation cannot successfully request Stop;
- a navigation or path task times out and Stop cannot be requested;
- follow disband cannot stop the active Leader;
- follow cleanup may have been applied only partially.

Quarantined units remain unavailable to new tasks. `stopUnits` clears quarantine for a unit only after its Stop RPC succeeds; successful Mock stop is considered confirmed. Console restart clears in-memory quarantine but does not claim that the old physical command was cancelled, so the fleet response must expose that restart cannot prove prior command termination.

Task results retain the requested terminal state and `cancellation_effect`, while unit availability separately reports the uncertain physical-control condition. This avoids inventing a new base RPC or falsely claiming strict cancellation.

## Follow Formation Decisions

### READY

Creation returns `READY` only when every required setup call is both transport-successful and accepted by the vehicle implementation. In particular, `Unit_rpc_setFormation` returning false is a setup failure even when the ILU environment contains no exception.

READY means `SETUP_ACKNOWLEDGED`: the setup RPC sequence was accepted. It does not prove that a vehicle-side follow thread remains healthy indefinitely. Status messages and capability reasons use this precise meaning.

### Rollback and disband

Cleanup evaluates both ILU exceptions and RPC boolean returns. Because legacy implementations may treat an already-cleared mode as an idempotent false, cleanup records individual outcomes and considers the operation safe only when role/relationship removal is positively established by the calls that own that state. An ambiguous or rejected cleanup keeps the formation record, reservations, and affected units quarantined for retry.

Disband reports leader Stop results separately from relationship cleanup. It must not return an unconditional clean `IDLE` result or release all members when the Leader may still be executing the prior target.

## Contract and Discovery Decisions

### Stable failure payloads

All production MCP methods return their declared payload shape inside the standard envelope, including locally detected validation and lookup failures:

- task methods return a complete `TaskResult`;
- formation methods return a complete `FormationStatus`;
- known lookup failures use `UNIT_NOT_FOUND` and `REJECTED`, not `INTERNAL_ERROR` and `FAILED`;
- safety failures use `SAFETY_REJECTED` and `REJECTED`.

Shared Python builders construct these results so `main.py`, `RobotAdapter`, and `ConsoleTaskClient` cannot drift.

### Dynamic units

Production resolution accepts a direct Console-bound canonical UnitID even when the unit is absent from `robots.json`. The adapter queries the authoritative fleet/directory response and resolves aliases before rejecting a unit. `robots.json` remains a planned configuration source, not the complete runtime directory.

### Capabilities

When the authoritative Console capability route is unavailable, the compatibility fallback does not claim executable navigation or formation support merely because a base IDL defines a method. Unverified execution capabilities default to unsupported and explain that availability cannot be established. Capability implementation support and current fleet availability remain distinct concepts.

## Task State Decisions

Every task with subtasks recomputes aggregate progress, including single-unit navigation, path, and follow-Leader movement. A single task therefore mirrors its only subtask.

Finalization derives a deterministic top-level error and message from terminal subtasks. Precedence is `FAILED`, then `TIMEOUT`, then `CANCELLED`; partial completion retains a representative non-success error while preserving every per-unit result.

Path construction checks every `Ground_Unit_TaskPath_Append` result. Any append failure frees allocated resources and returns `INTERNAL_ERROR` without calling `setTaskPath` with a partial sequence.

## Credential Handling

`deepseek_mcp_client.py` contains no default API key. It reads `DEEPSEEK_API_KEY` from the environment and fails with an explicit configuration error when absent. Backup source files containing credentials are removed from the working tree. Previously embedded credentials must be revoked and rotated outside this repository; code changes cannot revoke an external provider key.

## Files Expected to Change

- `mcp/deepseek_mcp_client.py`: environment-only credential loading.
- `mcp/deepseek_mcp_client.py.bak`: remove credential-bearing backup file.
- `mcp/safety/validator.py`: shared task-level coordinate and follow-distance limits.
- `mcp/robot_adapter.py`: structured local failures, safety checks, and dynamic UnitID resolution.
- `mcp/task_api/contracts.py`: complete `TaskResult` and `FormationStatus` builders.
- `mcp/task_api/capability_service.py`: conservative compatibility fallback.
- `mcp/console_client/console_task_client.py`: formation-response normalization.
- `mcp/main.py`: shared contract builders for preflight rejection.
- `SAU/Console/SafetyValidator.cpp` and `.h`: authoritative follow-target and distance validation helpers.
- `SAU/Console/HttpApiExecutor.cpp`: validation, quarantine-aware cancel/timeout/disband, and truthful status responses.
- `SAU/Console/TaskManager.cpp` and `.h`: quarantine ownership and complete aggregation.
- `SAU/Console/TaskOrchestrator.cpp` and `.h`: timeout Stop handling and aggregate error propagation support.
- `SAU/Console/LegacyIdlAdapter.cpp`: checked path append construction.
- `SAU/Console/console.cpp` and `.h`: accepted-return checks and conservative cleanup results.
- existing Python and Qt test files: red-green regression coverage.

No protected IDL or generated stub is edited.

## Test Strategy

Each behavior follows a separate red-green-refactor cycle. Required regressions are:

1. no embedded API key and environment-only key selection;
2. follow movement outside `[-1000, 1000]` is rejected by MCP and Console;
3. follow distance below `0.5`, above `20.0`, non-finite, or float-overflowing is rejected;
4. `setFormation(false)` prevents READY and starts rollback;
5. rejected or ambiguous cleanup retains reservations and reports failed units;
6. cancellation Stop failure quarantines the unit and blocks a new task;
7. timeout requests Stop and quarantines when Stop fails;
8. successful `stopUnits` releases quarantine;
9. disband does not hide Leader Stop failure;
10. local validation and lookup failures retain complete IDL payloads and specific error codes;
11. a runtime-bound unit absent from `robots.json` resolves by canonical UnitID;
12. capability fallback is conservative;
13. single-task progress mirrors its subtask;
14. aggregate terminal errors reach the top-level task result;
15. path append failure prevents `setTaskPath` dispatch;
16. existing three-vehicle chain mapping and RPC ordering continue to pass;
17. protected base-IDL hashes remain unchanged.

Verification runs the targeted MCP suites, Console Python tests, Qt `test_formation.exe`, and the production Console build. Live-car motion is not performed automatically; the final handoff includes a short three-car hardware checklist after static and Mock verification pass.

## Constraints and Non-goals

- Do not modify `air_unit.idl`, `console.idl`, `general_unit.idl`, `ground_unit.idl`, or `monitor.idl`.
- Do not modify vehicle-side code or change existing RPC wire semantics.
- Do not claim strict cancellation, final yaw, or navigation-speed support.
- Do not remove legacy HTTP, Mock, ILU, or debug-tool compatibility.
- Do not add a new persistent database for task state in this phase.
- Do not redesign Qt/ILU threading in this phase.
- Do not perform Git commits or branch operations; the user will handle Git.
