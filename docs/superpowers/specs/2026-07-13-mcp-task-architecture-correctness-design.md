# MCP Task Architecture Correctness Design

## Scope

This change closes the remaining implementation gaps in the task-level MCP architecture without changing the five protected base IDLs, generated stub semantics, vehicle-side programs, or existing low-level HTTP/ILU compatibility routes.

The work covers:

- truthful capability reporting;
- conservative Mock follow-formation behavior;
- recoverable follow-formation failure and disband behavior;
- canonical logical unit-ID lookup such as `GV1` versus `GV01`;
- stable task-level failure payloads;
- task-contract enum alignment;
- removal of unreachable legacy route code;
- ordered Mock path execution.

Test-suite organization and documentation cleanup beyond tests required to drive these behavior changes remain separate follow-up work.

## Behavioral Decisions

### Mock continuous-follow formation

Mock units do not have a persistent follower controller. `createFollowFormation` must therefore reject an all-Mock formation with `UNSUPPORTED_CAPABILITY`; it must not reserve members, create an active formation, or return `READY`. Mixed Mock/real follow formations remain unsupported.

Static geometric formations continue to work for Mock units because they dispatch independent target points and do not claim persistent following.

### Capability truthfulness

Target navigation and path execution are supported only when at least one ground unit can execute them: a bound Mock ground unit, or a bound real ground unit while `SAU_ENABLE_REAL_RPC=1`.

Static geometric formation is supported only when at least two executable ground units are present. Continuous follow formation is supported only when at least two real ground units are bound and real RPC is enabled. Final yaw, task-specific navigation speed, and strict cancellation remain unsupported.

Fleet snapshots distinguish binding from verified liveness. Mock units may report online from simulator state. A real binding must not be labeled online merely because an SBH exists; without a successful liveness probe it reports availability conservatively and keeps RPC configuration in a separate field.

### Follow creation, rollback, and disband

Follow creation tracks whether any physical setup was applied. Failures before physical setup restore the local record to `IDLE` immediately. Failures after partial setup keep enough information to retry cleanup and remain `FAILED` only when cleanup itself fails.

Disband sends cleanup RPCs only to real members whose setup may have been applied. Unsupported Mock and pre-dispatch failures never enter the physical cleanup path. A successful cleanup releases reservations and resets the local record to `IDLE`; a failed cleanup retains the record and reservations for a safe retry.

### Unit identity

All task-level binding and proxy lookups use one logical-ID resolver. Exact table matches are preferred; otherwise `logicalUnitIdsEqual` resolves compatible forms such as `GV1` and `GV01`. Duplicate checks operate on the canonical resolved ID so aliases cannot identify the same unit twice.

### Task-level response contract

Every task-returning production method yields the standard MCP envelope. Its `data` value is always a complete TaskResult-compatible object, including rejection and transport failures. Error responses carry a stable `error_code`, terminal state, unit results, timestamps, progress, and cancellation effect.

Formation-status methods similarly preserve the full FormationStatus field set on failure. The Python Console client validates both successful and unsuccessful task payloads instead of validating only successful responses.

### Formation type wire values

The production wire values remain lowercase (`line`, `triangle`, `column`) to preserve existing MCP and HTTP callers. The task IDL will explicitly use the same lowercase enum identifiers, while Console continues normalizing input defensively.

### Mock path execution

Mock `followPath` advances through each path point in order. Real units continue to receive the unchanged `Ground_Unit_rpc_setTaskPath` payload, and completion remains observed through existing pose polling.

### Legacy compatibility

`/api/task/goto_pose` remains an x/y-only compatibility alias to `/api/task/navigate`; yaw and speed fields remain accepted but ignored. The unreachable implementation after the alias return is removed. Other legacy HTTP routes and opt-in MCP debug tools remain available.

## Component Changes

- `SAU/Console/HttpApiExecutor.cpp`: capability calculation, follow state transitions, canonical member validation, stable route failures, and legacy dead-code cleanup.
- `SAU/Console/console.cpp` and `console.h`: reusable canonical unit lookup and scoped-follow cleanup bookkeeping.
- `SAU/Console/TaskOrchestrator.cpp` and `.h`: ordered Mock path polling and reusable task snapshot construction.
- `SAU/Console/LegacyIdlAdapter.cpp` and `.h`: canonical binding/proxy access shared by all task operations.
- `SAU/Console/TaskManager.cpp` and `.h`: keep existing task aggregation unchanged; pre-task rejection payloads are constructed at the HTTP boundary.
- `mcp/idl/mcp_swarm_task.idl`: lowercase formation enum values only; protected IDLs remain untouched.
- `mcp/task_api/contracts.py` and `mcp/console_client/console_task_client.py`: complete TaskResult construction and validation for failures.
- `mcp/robot_adapter.py`: normalize local validation and transport failures into the same task contract.

## Testing Strategy

Changes follow red-green-refactor cycles. Tests use the existing `LegacyIdlAdapter` injection boundary rather than live vehicles.

Required behavior tests cover:

- all-Mock follow creation returns `UNSUPPORTED_CAPABILITY` and leaves state `IDLE`;
- pre-dispatch follow failures do not require RPC disband;
- partial real follow cleanup preserves reservations only when cleanup fails;
- capabilities are false for real-only fleets when real RPC is disabled;
- logical aliases resolve to one canonical bound unit;
- task failures retain complete TaskResult fields;
- concrete static-formation coordinates prove anchor and heading use;
- Mock paths visit intermediate points in order;
- legacy `/api/task/goto_pose` still aliases to x/y navigation;
- protected base-IDL hashes remain unchanged.

## Non-goals and Constraints

- No changes to `air_unit.idl`, `console.idl`, `general_unit.idl`, `ground_unit.idl`, or `monitor.idl`.
- No vehicle-side changes and no new vehicle RPC operations.
- No claim of strict cancellation or final-yaw/task-speed support.
- No physical continuous-follow simulator is introduced for Mock units.
- No removal of low-level HTTP, ILU, Mock navigation, or real RPC compatibility capability.
