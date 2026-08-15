# MCP-IDL Swarm Harness Path and Stop Plugin Design

## Purpose

This change is the second production migration slice of the plugin-based
MCP-IDL Swarm Harness. It moves `followPath` and `stopUnits` from static
registration in `mcp/main.py` into typed Capability Plugins while preserving
the public fourteen-tool MCP contract and the existing KIS-ORB SAU execution
chain.

After this slice, the runtime owns three production tools: `navigateTo`,
`followPath`, and `stopUnits`. The other eleven tools remain on the temporary
legacy `TaskService` and `CapabilityService` path. No Runtime Core, SAU Console,
or IDL redesign is part of this phase.

## Decisions and Constraints

- `followPath` belongs to the existing Navigation Capability Plugin.
- `stopUnits` belongs to a new Motion Capability Plugin.
- Both tools use the plugin runtime by default, without a legacy feature switch.
- Tool names, FastMCP input schemas, default values, response envelopes, task
  types, and established KIS-ORB business behavior remain compatible.
- The existing `ConsoleTaskClient -> RobotAdapter -> SAU Console -> IDL` chain
  remains the authoritative KIS-ORB implementation and safety boundary.
- Runtime Core registries, provider resolution, policy execution, plugin
  loading, and FastMCP bridging are reused without modification.
- Profiles continue to be explicit allowlists. The Mock platform is excluded
  from the production default profile as a platform, although both profiles
  enable the platform-neutral Motion Capability Plugin.
- Cross-platform scatter/gather and aggregate result composition are deferred.
  One provider must support the complete unit tuple for a request.
- Hot reload, async plugin lifecycle, safety-policy extraction, task status,
  cancellation, formation migration, modular IDLs, and a second real platform
  remain outside this phase.
- ProjectMemory is not used.

## Architecture

The existing runtime pipeline is reused for both capabilities:

```text
followPath
  -> capability.navigation
  -> navigation.follow_path2d@1.0
  -> CapabilityExecutor
  -> KIS-ORB or Mock FollowPath Provider

stopUnits
  -> capability.motion
  -> motion.stop@1.0
  -> CapabilityExecutor
  -> KIS-ORB or Mock Stop Provider
```

The Capability Plugins own the typed MCP tools and platform-neutral request
construction. Platform Plugins own calls to concrete clients and construction
of platform-specific results. Runtime Core knows only capability names,
versions, unit descriptors, providers, policies, and execution results.

### Capability plugins

`capability.navigation` is extended rather than split by operation. It retains
`navigation.goto2d@1.0` and `navigateTo`, then adds:

```text
name: navigation.follow_path2d
version: 1.0
scope: unit
tool_name: followPath
```

The plugin version advances from `1.0.0` to `1.1.0` because it gains a
backward-compatible capability and tool.

A new `capability.motion` plugin provides:

```text
name: motion.stop
version: 1.0
scope: multi_unit
tool_name: stopUnits
```

The stop capability is distinct from task cancellation. It requests physical
Stop for the selected units without cancelling task state or disbanding a
formation, matching the existing IDL and MCP method semantics.

### Platform plugins

`platform.kisorb-sau` advances to `1.1.0` and adds two providers alongside the
existing GoTo2D provider:

- `kisorb.navigation.follow_path2d` calls the shared
  `ConsoleTaskClient.follow_path()`;
- `kisorb.motion.stop` calls the shared `ConsoleTaskClient.stop_units()`.

The shared RobotAdapter and ConsoleTaskClient service registrations do not
change. The eleven unmigrated tools continue using the same instances, so
locks, task state, configuration, and transport remain consistent.

`platform.mock-navigation` also advances to `1.1.0` and retains its existing ID
to avoid a disruptive rename. It adds in-memory FollowPath and Stop providers.
The plugin remains an acceptance platform, not a production dependency.

## Tool Contracts and Request Construction

### `followPath`

The callable retains this exact public signature:

```python
async def followPath(
    unit_id: str,
    points: list[dict[str, float]],
    tolerance_m: float = 0.15,
    timeout_ms: int = 30000,
) -> str
```

The intentionally broad `dict[str, float]` point type is retained because
replacing it with a strict `Point2D` TypedDict would change the current FastMCP
JSON Schema. A valid invocation creates:

```text
ExecutionRequest(
  capability="navigation.follow_path2d",
  version="1.0",
  unit_ids=(requested_unit_id,),
  arguments={points, tolerance_m, timeout_ms},
  metadata={tool_name: "followPath"}
)
```

Runtime resolves the requested unit or alias to its canonical descriptor before
provider selection. The KIS-ORB provider serializes `points` with
`json.dumps(..., ensure_ascii=False)` and forwards the canonical UnitID and
unchanged numeric arguments to `ConsoleTaskClient.follow_path()`.

Path shape, the one-to-ten point limit, finite coordinates, tolerance, timeout,
task locking, and authoritative dispatch continue to be validated by the
existing adapter and Console chain. The Capability Plugin does not duplicate or
weaken those checks.

### `stopUnits`

The callable retains this exact public signature:

```python
async def stopUnits(unit_ids: list[str]) -> str
```

A non-empty invocation creates `motion.stop@1.0` with the requested IDs in
their original order. Runtime resolves every ID and alias. The selected provider
receives canonical UnitDescriptors and removes duplicate canonical IDs while
preserving first occurrence order before calling the concrete client.

This preserves the current behavior when a canonical ID and one of its aliases
refer to the same unit. An empty list is rejected by the capability callable
with the established `stop_units` TaskResult structure, message, failed state,
and `INTERNAL_ERROR` code rather than reaching provider resolution.

## Provider Resolution and Multi-unit Semantics

Provider selection continues to require an exact capability name and version
and chooses the unique highest-priority supporting provider.

The KIS-ORB Stop provider supports a non-empty tuple only when every resolved
unit has platform `kisorb-sau`. The Mock Stop provider applies the equivalent
rule for `mock-navigation`. The default profile contains only KIS-ORB units, so
normal production multi-unit Stop remains supported.

In the Mock acceptance profile, a request containing both a KIS-ORB unit and a
Mock unit is rejected as `UNSUPPORTED_CAPABILITY`. This is deliberate: neither
provider owns the entire tuple, and Runtime Core does not split one request
across providers in this phase. Cross-platform fan-out, concurrency,
compensation, and aggregate result precedence require a separate composition
design.

The FollowPath providers support exactly one unit from their own platform.
Equal-priority ambiguity remains a deterministic resolution error.

## Plugin Manifests and Profiles

The Navigation manifest adds:

```text
capability:navigation.follow_path2d@1.0
tool:followPath
```

The new Motion manifest declares:

```text
id: capability.motion
version: 1.0.0
type: capability
provides:
  capability:motion.stop@1.0
  tool:stopUnits
```

The KIS-ORB manifest depends on both `capability.navigation` and
`capability.motion`, and declares all three provider tokens plus its two legacy
service tokens. The Mock manifest also depends on both capability plugins and
declares all three provider tokens and `unit:MOCK1`.

Both `default.json` and `mock-navigation.json` explicitly enable
`capability.motion`. Only `mock-navigation.json` enables
`platform.mock-navigation`. Dependency ordering therefore loads capability
declarations and tools before either platform provider. Existing transactional
setup, declared-provision verification, and reverse rollback semantics remain
unchanged.

## Failure Semantics

Capability tool callables map runtime errors into complete task envelopes using
their own existing task types:

| Condition | Error code | Task state |
| --- | --- | --- |
| Unit or alias cannot be resolved | `UNIT_NOT_FOUND` | `REJECTED` |
| Provider cannot support the whole unit tuple | `UNSUPPORTED_CAPABILITY` | `REJECTED` |
| Policy denies or raises | `SAFETY_REJECTED` | `REJECTED` |
| Unexpected runtime/provider failure | `INTERNAL_ERROR` | `FAILED` |
| Empty `stopUnits` input | `INTERNAL_ERROR` | `FAILED` |

KIS-ORB provider responses are parsed into `ExecutionResult` only after the
existing ConsoleTaskClient normalization. Existing adapter/Console validation,
business error messages, TaskResult fields, and task types (`follow_path` and
`stop_units`) are not reinterpreted by Runtime.

Mock providers return complete successful TaskResults with the same task types.
They record canonical units, path targets, and Stop results sufficiently for
architectural acceptance tests; they do not emulate Console task scheduling.

## Bootstrap and Migration Boundary

`main.create_app(profile_path=None)` still creates one SwarmContext, loads the
profile, retrieves the shared legacy services, registers static tools, and then
installs Tool Registry callables through FastMCP.

The static `followPath` and `stopUnits` functions are removed from `main.py`.
The eleven remaining static tools are unchanged. The production MCP surface is
still exactly fourteen tools:

```text
3 runtime tools + 11 legacy tools = 14 production tools
```

Low-level debug tools remain opt-in and continue using the shared KIS-ORB
adapter. The runtime does not gain a generic JSON execution escape hatch.

## Testing Strategy

Implementation follows red-green-refactor cycles. Focused tests cover:

- Navigation and Motion capability registration and manifest provisions;
- exact FastMCP schema snapshots for `followPath` and `stopUnits`;
- ExecutionRequest capability names, versions, metadata, and ordered arguments;
- alias-to-canonical resolution before KIS-ORB provider calls;
- exact path JSON serialization and numeric argument forwarding;
- Stop canonical-ID de-duplication with first-occurrence ordering;
- empty Stop compatibility response;
- Mock FollowPath and Stop success through the same capability tools;
- deterministic rejection of mixed KIS-ORB/Mock Stop tuples;
- all three runtime tools and exactly eleven static legacy tools;
- the unchanged fourteen-name production tool set and opt-in debug surface.

Boundary and regression tests assert:

- no `swarm_runtime` or Capability Plugin imports platform implementations;
- Runtime Core files are unchanged by the feature commit;
- only platform packages import RobotAdapter and ConsoleTaskClient;
- the production profile excludes the Mock platform;
- no SAU Console or IDL file changes occur;
- the protected task-IDL SHA-256 remains
  `2EA71279A5FD8C0AD1157ED38F5EA7E04621EF439DB16E86CBEA65FEDB625F1A`;
- the full non-live suite preserves the current baseline of 254 passing and
  3 skipped tests, plus all new tests.

## Documentation and Completion Criteria

The root README is updated to describe three runtime-owned tools, eleven legacy
tools, the Motion Capability Plugin, and the single-provider requirement for
multi-unit requests. It must not claim that composition, task lifecycle,
formation, safety policies, IDLs, or a second real platform are pluginized.

This phase is complete when both production tools route through profile-loaded
Capability and Platform Plugins, the Mock profile demonstrates both new
capabilities without Runtime Core changes, all external contracts remain
compatible, protected paths remain unchanged, and the complete non-live suite
passes.

