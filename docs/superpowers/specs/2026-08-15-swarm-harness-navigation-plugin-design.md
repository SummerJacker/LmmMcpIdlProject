# MCP-IDL Swarm Harness Navigation Plugin Design

## Purpose

This change introduces the first production vertical slice of a plugin-based
MCP-IDL Swarm Harness. It validates the Capability/Provider separation without
rewriting the working SAU execution chain or migrating every production tool at
once.

The production `navigateTo` tool will be registered by a Navigation Capability
Plugin and executed through a platform-neutral runtime. A KIS-ORB SAU Platform
Plugin will provide the implementation by wrapping the existing
`ConsoleTaskClient -> RobotAdapter -> SAU Console` chain. A separate in-memory
Mock Navigation Platform Plugin will prove that a second provider can implement
the same capability without changing the runtime.

## Decisions and Constraints

- `navigateTo` uses the new runtime by default; there is no legacy-path feature
  switch.
- Its tool name, typed input schema, default values, and JSON response contract
  remain compatible with the current production interface.
- The other thirteen production tools remain on their current static path during
  this phase.
- The current SAU Console, base IDLs, task IDL, RobotAdapter safety checks, and
  Console safety checks are not changed.
- Plugins are loaded only when explicitly enabled by a profile.
- Plugin registration is synchronous; capability execution remains asynchronous.
- Hot reload, remote plugins, Python package entry-point discovery, telemetry,
  task composition, generic formation fallback, and migration of the remaining
  tools are later phases.
- FastMCP is pinned to the locally verified version `3.4.2`, whose `add_tool()`
  API accepts typed async callables.

## Architecture

The platform-neutral implementation lives in `mcp/swarm_runtime/` so it does
not collide with generic packages named `runtime`.

```text
FastMCP navigateTo
        |
        v
Navigation Capability Plugin
        |
        v
ExecutionRequest(navigation.goto2d@1.0)
        |
        v
CapabilityExecutor
  |       |          |
  v       v          v
Unit   Provider    Policy
Registry Registry  Pipeline
        |
        +----------------------------+
        |                            |
        v                            v
KIS-ORB SAU Provider          Mock Navigation Provider
        |                       (test profile only)
        v
ConsoleTaskClient -> RobotAdapter -> SAU Console -> IDL
```

### Runtime package

`mcp/swarm_runtime/` contains:

- `models.py`: immutable `UnitDescriptor`, `CapabilitySpec`,
  `ExecutionRequest`, and `ExecutionResult` models.
- `errors.py`: typed runtime exceptions and stable MCP error-code mapping.
- `registry/`: Unit, Capability, Provider, Policy, Tool, and Service registries.
- `context.py`: `SwarmContext`, which owns the registries and executor.
- `executor.py`: the deterministic capability execution pipeline.
- `plugin.py`: the synchronous plugin protocol and registration transaction.
- `plugin_loader.py`: manifest/profile validation, dependency ordering, loading,
  rollback, and unloading.
- `fastmcp_bridge.py`: installation of typed `ToolSpec` callables into FastMCP.

The Service Registry is an internal migration seam. The KIS-ORB plugin registers
the shared legacy adapter/client objects there so the thirteen unmigrated tools
and opt-in debug tools can continue using the same adapter instance. This avoids
creating independent lock managers while keeping platform imports outside the
runtime core. The legacy bridge may know the migration service IDs; the runtime
registries and executor may not.

### Plugin packages

The first phase adds:

```text
mcp/plugins/
  capabilities/navigation/
    plugin.json
    plugin.py
    tools.py
  platforms/kisorb_sau/
    plugin.json
    plugin.py
    providers.py
  platforms/mock_navigation/
    plugin.json
    plugin.py
    providers.py

mcp/profiles/
  default.json
  mock-navigation.json
```

`capability.navigation` registers `navigation.goto2d@1.0` and one typed
`navigateTo` tool. Platform plugins never register `navigateTo`, preventing tool
name collisions when several navigation providers are installed.

`platform.kisorb-sau` reads the existing robot configuration, registers one
`UnitDescriptor` per configured unit, creates the shared RobotAdapter and
ConsoleTaskClient, and registers a KIS-ORB provider.

`platform.mock-navigation` registers an in-memory unit and provider only in the
test profile. It does not appear in `default.json` and cannot affect production
unit discovery or routing.

## Models and Registry Semantics

### Capability and units

The navigation capability is identified by name and exact version:

```text
name: navigation.goto2d
version: 1.0
scope: unit
tool_name: navigateTo
```

`UnitDescriptor` includes canonical `unit_id`, `kind`, `platform`, owning plugin
ID, aliases, and metadata. The Unit Registry indexes both canonical IDs and
aliases. It rejects duplicate canonical IDs and alias collisions at registration
time. Therefore `robot_1` resolves to the same descriptor as `GV1` before
provider selection.

### Provider selection

A provider declares an ID, capability name, exact capability version, and
integer priority. Its `supports()` method receives the entire resolved unit tuple
rather than a single unit, allowing future multi-unit capabilities to use the
same interface.

Resolution performs these steps:

1. select providers matching capability name and exact version;
2. retain providers whose `supports(units)` returns true;
3. select the highest integer priority;
4. reject an equal-priority tie instead of depending on plugin load order.

Multiple providers may coexist. Tool, capability, unit, service, policy, plugin,
and provider IDs must remain unique within their respective registries.

## Bootstrap and MCP Tool Registration

`main.create_app(profile_path=None)` remains synchronous for compatibility with
the current tests and FastMCP module loading.

Bootstrap performs the following operations:

1. create an empty `SwarmContext`;
2. load the selected profile, defaulting to `profiles/default.json`;
3. validate and transactionally set up the enabled plugins;
4. obtain the shared legacy client/adapter from the migration Service Registry;
5. register the thirteen unchanged production tools using the existing service
   implementations;
6. add runtime tools from Tool Registry through `FastMCP.add_tool()`;
7. optionally register legacy/debug tools with the same shared adapter.

The existing local target-shape rejection for `navigateTo` is retained in the
typed navigation tool callable. A valid call creates this request:

```text
ExecutionRequest(
  request_id=<generated UUID>,
  capability="navigation.goto2d",
  version="1.0",
  unit_ids=(<requested unit ID>,),
  arguments={x, y, tolerance_m, timeout_ms},
  metadata={tool_name: "navigateTo"}
)
```

The executor resolves the alias to a canonical unit before invoking the
provider. The KIS-ORB provider calls `ConsoleTaskClient.navigate_to()` with the
canonical ID and the unchanged numeric arguments.

## Execution Pipeline and Policies

The first-phase executor uses a fixed sequence:

1. resolve the CapabilitySpec;
2. resolve every requested unit and canonicalize aliases;
3. resolve exactly one provider;
4. run matching policies in descending priority order;
5. stop immediately on the first denial;
6. execute the provider;
7. normalize the result into the existing MCP response envelope.

Policy outcomes are `ALLOW`, `DENY`, or `ABSTAIN`. Denial is monotonic: no later
policy can override it. A policy exception fails closed as `SAFETY_REJECTED`.

The pipeline is active in production, but this phase does not move the existing
Python or C++ safety implementation into plugins. KIS-ORB execution continues to
pass through both existing safety layers, avoiding duplicated validation and
changes to current error messages. Production safety-policy extraction requires
a separate design and regression baseline.

## Plugin Manifest, Profile, and Lifecycle

Each local `plugin.json` contains:

- `api_version` (must equal 1);
- globally unique `id`;
- plugin `version`;
- `type` (`capability` or `platform` in this phase);
- Python `entrypoint` in `module:object` form;
- `requires` plugin IDs;
- declared `provides` entries.

The loader may index manifests under the configured plugin root, but it imports
and executes only plugin IDs explicitly enabled by the selected profile. Profile
config is passed only to its owning plugin. Unknown configuration does not leak
into Core.

Before `setup()`, the context starts a registration transaction owned by the
plugin ID. Every successful registration records an undo action. If manifest
validation, dependency checking, import, construction, or setup fails, the
loader invokes undo actions in reverse order and leaves the plugin unloaded.
Normal unload calls the plugin's optional teardown and then reverses all owned
registrations. Duplicate plugin IDs, missing dependencies, dependency cycles,
unsupported API versions, invalid entrypoints, and declared/provided capability
mismatches fail startup.

Registration remains synchronous because phase-one setup performs local object
construction only. This preserves `create_app()` without introducing
`asyncio.run()` into an existing event loop. Async plugin startup and shutdown
will require a later FastMCP lifespan design.

## Failure Semantics

Runtime failures are mapped to the current task response envelope:

| Condition | MCP error code | Task state |
| --- | --- | --- |
| Unit or alias cannot be resolved | `UNIT_NOT_FOUND` | `REJECTED` |
| No provider supports the resolved unit | `UNSUPPORTED_CAPABILITY` | `REJECTED` |
| Policy denies or raises | `SAFETY_REJECTED` | `REJECTED` |
| Ambiguous highest-priority providers | `UNSUPPORTED_CAPABILITY` | `REJECTED` |
| Unexpected runtime/provider failure | `INTERNAL_ERROR` | `FAILED` |

Unexpected exceptions are logged with request and provider identifiers but are
not returned with stack traces. Normal KIS-ORB responses continue through
`normalize_task_response(..., task_type="navigate_to")`, including current
Console business errors and complete `TaskResult` construction.

## Testing Strategy

Implementation follows red-green-refactor cycles. New unit tests cover:

- duplicate registration and alias collision rejection;
- exact capability-version matching;
- provider priority selection and equal-priority ambiguity rejection;
- policy ordering, monotonic denial, and fail-closed exceptions;
- profile allowlisting and manifest validation;
- dependency ordering, cycle detection, and setup rollback;
- typed Tool Registry installation through FastMCP;
- exact `navigateTo` schema and default values;
- canonical alias resolution before provider execution;
- KIS-ORB provider argument forwarding and response normalization;
- Mock profile execution of the same capability without Core changes.

Regression tests must prove:

- the production tool set remains exactly the existing fourteen names;
- low-level tools remain opt-in;
- existing `navigateTo` validation and response fields remain compatible;
- the current 210 passing, non-live tests still pass;
- no SAU Console or IDL file changes are introduced.

The Mock plugin test is the architectural acceptance test: switching from the
default profile to `mock-navigation.json` must route the same
`navigation.goto2d@1.0` request to the Mock provider without changes to
`SwarmContext`, registries, executor, FastMCP bridge, or Navigation Capability
Plugin.

## Migration Boundary and Follow-up Work

The temporary hybrid bootstrap is intentional. It gives one production tool a
complete plugin path while keeping the remaining thirteen stable. Once this
slice is verified, later designs can migrate capabilities in this order:

1. `navigation.follow_path2d` and `motion.stop`;
2. fleet and capability discovery;
3. task status and cancellation;
4. formation capabilities and composed fallbacks;
5. safety policies with explicit equivalence tests;
6. modular IDL families and a non-Mock second platform.

Completion of this phase means the runtime can add a second navigation platform
by adding a platform plugin and profile entry, while leaving the Core executor,
registries, and `navigateTo` capability plugin unchanged.
