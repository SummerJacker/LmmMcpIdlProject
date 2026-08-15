# Swarm Harness Navigation Plugin Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Route the production `navigateTo` MCP tool through a profile-loaded Capability Runtime and KIS-ORB Provider while preserving the existing fourteen-tool contract and proving a second Mock provider requires no Core changes.

**Architecture:** Add a small platform-neutral `swarm_runtime` package with typed models, deterministic registries, a fail-closed policy pipeline, and transactional plugin loading. A Navigation Capability Plugin owns the typed MCP tool; KIS-ORB and Mock platform plugins implement `navigation.goto2d@1.0`. The remaining thirteen tools keep using the existing shared RobotAdapter/ConsoleTaskClient through a temporary migration Service Registry.

**Tech Stack:** Python 3.10+, FastMCP 3.4.2, dataclasses, Protocol, JSON manifests/profiles, pytest, pytest-asyncio.

---

## File map

| Path | Responsibility |
| --- | --- |
| `mcp/swarm_runtime/models.py` | Immutable unit, capability, request, result, tool, and policy value types |
| `mcp/swarm_runtime/errors.py` | Registration, resolution, plugin, and execution exceptions |
| `mcp/swarm_runtime/registration.py` | Per-plugin undo journal and provision-token tracking |
| `mcp/swarm_runtime/registry/*.py` | Focused Unit, Capability, Provider, Policy, Tool, and Service registries |
| `mcp/swarm_runtime/context.py` | Composition root for registries and executor |
| `mcp/swarm_runtime/executor.py` | Capability -> unit -> provider -> policy -> execution pipeline |
| `mcp/swarm_runtime/plugin.py` | Manifest/profile models and synchronous plugin protocol |
| `mcp/swarm_runtime/plugin_loader.py` | Allowlisted discovery, dependency ordering, setup rollback, unload |
| `mcp/swarm_runtime/fastmcp_bridge.py` | Add Tool Registry callables to FastMCP |
| `mcp/plugins/capabilities/navigation/` | Capability declaration and typed `navigateTo` callable |
| `mcp/plugins/platforms/kisorb_sau/` | Existing adapter/client services, units, and KIS-ORB provider |
| `mcp/plugins/platforms/mock_navigation/` | In-memory second-platform acceptance provider |
| `mcp/profiles/default.json` | Production Navigation + KIS-ORB composition |
| `mcp/profiles/mock-navigation.json` | Production composition plus Mock unit/provider |
| `mcp/main.py` | Hybrid bootstrap: thirteen legacy tools plus runtime tool installation |

### Task 1: Runtime Models, Registration Journal, and Basic Registries

**Files:**
- Create: `mcp/swarm_runtime/__init__.py`
- Create: `mcp/swarm_runtime/models.py`
- Create: `mcp/swarm_runtime/errors.py`
- Create: `mcp/swarm_runtime/registration.py`
- Create: `mcp/swarm_runtime/registry/__init__.py`
- Create: `mcp/swarm_runtime/registry/unit.py`
- Create: `mcp/swarm_runtime/registry/capability.py`
- Create: `mcp/swarm_runtime/registry/service.py`
- Test: `mcp/tests/test_runtime_registries.py`

- [ ] **Step 1: Write failing model and registry tests**

Create `mcp/tests/test_runtime_registries.py` with these concrete cases:

```python
from __future__ import annotations

import json
import pytest

from swarm_runtime.errors import DuplicateRegistrationError, UnitNotFoundError
from swarm_runtime.models import CapabilitySpec, ExecutionResult, UnitDescriptor
from swarm_runtime.registration import RegistrationJournal
from swarm_runtime.registry import CapabilityRegistry, ServiceRegistry, UnitRegistry


def make_registries():
    journal = RegistrationJournal()
    return journal, UnitRegistry(journal), CapabilityRegistry(journal), ServiceRegistry(journal)


def test_unit_registry_resolves_canonical_id_and_alias_case_insensitively() -> None:
    _, units, _, _ = make_registries()
    descriptor = UnitDescriptor(
        unit_id="GV1", kind="ugv", platform="kisorb-sau",
        provider_plugin_id="platform.kisorb-sau", aliases=("robot_1",),
    )
    units.register(descriptor)
    assert units.resolve("GV1") is descriptor
    assert units.resolve("robot_1") is descriptor
    assert units.resolve("RoBoT_1") is descriptor


def test_unit_registry_rejects_alias_collision() -> None:
    _, units, _, _ = make_registries()
    units.register(UnitDescriptor("GV1", "ugv", "a", "p1", ("robot",)))
    with pytest.raises(DuplicateRegistrationError):
        units.register(UnitDescriptor("GV2", "ugv", "b", "p2", ("ROBOT",)))


def test_missing_unit_raises_typed_error() -> None:
    _, units, _, _ = make_registries()
    with pytest.raises(UnitNotFoundError) as error:
        units.resolve("missing")
    assert error.value.error_code == "UNIT_NOT_FOUND"


def test_capability_registry_uses_exact_name_and_version() -> None:
    _, _, capabilities, _ = make_registries()
    spec = CapabilitySpec("navigation.goto2d", "1.0", "Navigate to x/y", "unit", "navigateTo")
    capabilities.register(spec)
    assert capabilities.get("navigation.goto2d", "1.0") is spec
    with pytest.raises(KeyError):
        capabilities.get("navigation.goto2d", "2.0")


def test_service_registry_returns_same_shared_object() -> None:
    _, _, _, services = make_registries()
    shared = object()
    services.register("legacy.robot_adapter", shared)
    assert services.get("legacy.robot_adapter") is shared


def test_execution_result_round_trips_current_envelope() -> None:
    raw = '{"success":true,"message":"accepted","data":{"task_id":"goto-1"}}'
    result = ExecutionResult.from_json(raw)
    assert json.loads(result.to_json()) == json.loads(raw)
```

- [ ] **Step 2: Run tests and verify RED**

Run:

```powershell
cd E:\MCP-IDL\mcp
python -m pytest tests/test_runtime_registries.py -q
```

Expected: collection fails with `ModuleNotFoundError: No module named 'swarm_runtime'`.

- [ ] **Step 3: Implement the value types and typed errors**

In `models.py`, define the exact public types used by later tasks:

```python
from __future__ import annotations

import json
from dataclasses import dataclass, field
from enum import Enum
from typing import Any, Awaitable, Callable, Mapping


@dataclass(frozen=True)
class UnitDescriptor:
    unit_id: str
    kind: str
    platform: str
    provider_plugin_id: str
    aliases: tuple[str, ...] = ()
    metadata: Mapping[str, Any] = field(default_factory=dict)


@dataclass(frozen=True)
class CapabilitySpec:
    name: str
    version: str
    description: str
    scope: str
    tool_name: str | None = None


@dataclass(frozen=True)
class ExecutionRequest:
    request_id: str
    capability: str
    version: str
    unit_ids: tuple[str, ...]
    arguments: Mapping[str, Any]
    metadata: Mapping[str, Any] = field(default_factory=dict)


@dataclass(frozen=True)
class ExecutionResult:
    success: bool
    message: str
    data: Any = None
    error_code: str = ""

    @classmethod
    def from_json(cls, raw: str) -> "ExecutionResult":
        payload = json.loads(raw)
        if not isinstance(payload, dict):
            raise ValueError("provider response must be a JSON object")
        return cls(
            success=bool(payload.get("success", False)),
            message=str(payload.get("message", "")),
            data=payload.get("data"),
            error_code=str(payload.get("error_code", "") or ""),
        )

    def to_json(self) -> str:
        payload = {"success": self.success, "message": self.message, "data": self.data}
        if self.error_code:
            payload["error_code"] = self.error_code
        return json.dumps(payload, ensure_ascii=False)


@dataclass(frozen=True)
class ToolSpec:
    name: str
    callable: Callable[..., Awaitable[str]]


class PolicyDecision(str, Enum):
    ALLOW = "ALLOW"
    DENY = "DENY"
    ABSTAIN = "ABSTAIN"


@dataclass(frozen=True)
class PolicyOutcome:
    decision: PolicyDecision
    message: str = ""
```

In `errors.py`, define `RuntimeRegistrationError`, `DuplicateRegistrationError`,
`RuntimeExecutionError`, `RuntimeResolutionError`, `UnitNotFoundError`,
`ProviderNotFoundError`, `AmbiguousProviderError`, `PolicyRejectedError`, and
`PluginLoadError`. `RuntimeExecutionError` is the execution-facing base with
`message`, `error_code="INTERNAL_ERROR"`, and `rejected=False` constructor
defaults. `RuntimeResolutionError(RuntimeExecutionError)` sets `rejected=True`;
Unit, provider, ambiguity, and policy errors inherit from it and set
`UNIT_NOT_FOUND`, `UNSUPPORTED_CAPABILITY`, `UNSUPPORTED_CAPABILITY`, and
`SAFETY_REJECTED`, respectively. This hierarchy makes the two exception branches
in the Navigation Capability Plugin exhaustive and type-consistent.

- [ ] **Step 4: Implement journal-backed Unit, Capability, and Service registries**

Implement `RegistrationTransaction.record(token, undo)`, `rollback()` in reverse
order, and `RegistrationJournal.activate(plugin_id)` as a context manager.
`RegistrationJournal.record()` is a no-op when no plugin transaction is active,
which permits focused registry tests and explicit bootstrap registration. Each
registry mutation inside an active plugin transaction must call:

```python
self._journal.record("unit:GV1", lambda: self._remove("GV1"))
```

Use `casefold()` for Unit canonical/alias indexes. `UnitRegistry.register()` must
validate all canonical and alias keys before mutating either index. Capability
keys are `(name, version)`. Service keys are exact strings. Export the three
registries from `registry/__init__.py` and the public models/errors from
`swarm_runtime/__init__.py`.

- [ ] **Step 5: Run focused tests and commit**

Run:

```powershell
python -m pytest tests/test_runtime_registries.py -q
git add mcp/swarm_runtime mcp/tests/test_runtime_registries.py
git commit -m "feat: add swarm runtime models and core registries"
```

Expected: `6 passed`; commit succeeds.

### Task 2: Provider Resolution, Policy Pipeline, and Capability Executor

**Files:**
- Create: `mcp/swarm_runtime/protocols.py`
- Create: `mcp/swarm_runtime/registry/provider.py`
- Create: `mcp/swarm_runtime/registry/policy.py`
- Create: `mcp/swarm_runtime/registry/tool.py`
- Create: `mcp/swarm_runtime/context.py`
- Create: `mcp/swarm_runtime/executor.py`
- Modify: `mcp/swarm_runtime/registry/__init__.py`
- Modify: `mcp/swarm_runtime/__init__.py`
- Test: `mcp/tests/test_runtime_executor.py`

- [ ] **Step 1: Write failing deterministic-resolution and policy tests**

Create providers and policies as local test doubles in
`mcp/tests/test_runtime_executor.py`. Cover these exact outcomes:

```python
@pytest.mark.asyncio
async def test_executor_selects_highest_priority_supporting_provider() -> None:
    ctx = SwarmContext()
    ctx.capabilities.register(CapabilitySpec("navigation.goto2d", "1.0", "nav", "unit"))
    ctx.units.register(UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau"))
    low = FakeProvider("low", priority=10, platform="kisorb-sau")
    high = FakeProvider("high", priority=100, platform="kisorb-sau")
    ctx.providers.register(low)
    ctx.providers.register(high)
    result = await ctx.executor.execute(request_for("GV1"))
    assert result.data["provider"] == "high"


@pytest.mark.asyncio
async def test_equal_highest_priorities_fail_closed() -> None:
    ctx = populated_context()
    ctx.providers.register(FakeProvider("one", 100, "kisorb-sau"))
    ctx.providers.register(FakeProvider("two", 100, "kisorb-sau"))
    with pytest.raises(AmbiguousProviderError) as error:
        await ctx.executor.execute(request_for("GV1"))
    assert error.value.error_code == "UNSUPPORTED_CAPABILITY"


@pytest.mark.asyncio
async def test_policy_denial_is_monotonic() -> None:
    ctx = populated_context(provider=True)
    later = RecordingPolicy("later", 10, PolicyDecision.ALLOW)
    ctx.policies.register(RecordingPolicy("deny", 100, PolicyDecision.DENY))
    ctx.policies.register(later)
    with pytest.raises(PolicyRejectedError):
        await ctx.executor.execute(request_for("GV1"))
    assert later.called is False


@pytest.mark.asyncio
async def test_policy_exception_fails_closed() -> None:
    ctx = populated_context(provider=True)
    ctx.policies.register(RaisingPolicy("broken", 100))
    with pytest.raises(PolicyRejectedError) as error:
        await ctx.executor.execute(request_for("GV1"))
    assert error.value.error_code == "SAFETY_REJECTED"
```

Also assert exact-version mismatch yields `ProviderNotFoundError`, unsupported
platforms are filtered by `supports(units)`, provider exceptions become
`RuntimeExecutionError(error_code="INTERNAL_ERROR", rejected=False)`, and duplicate
provider/policy/tool IDs are rejected.

- [ ] **Step 2: Run tests and verify RED**

Run:

```powershell
python -m pytest tests/test_runtime_executor.py -q
```

Expected: collection fails because `SwarmContext` and executor modules are absent.

- [ ] **Step 3: Implement provider, policy, and tool protocols/registries**

Define these protocols in `protocols.py`:

```python
class CapabilityProvider(Protocol):
    provider_id: str
    capability: str
    version: str
    priority: int
    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool: ...
    async def execute(
        self, request: ExecutionRequest, units: tuple[UnitDescriptor, ...]
    ) -> ExecutionResult: ...


class ExecutionPolicy(Protocol):
    policy_id: str
    priority: int
    def applies_to(self, request: ExecutionRequest) -> bool: ...
    async def evaluate(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
        provider: CapabilityProvider,
    ) -> PolicyOutcome: ...
```

`ProviderRegistry.resolve(capability, version, units)` filters exact name/version
and `supports`, sorts descending by priority, and raises on an empty match or a
top-priority tie. `PolicyRegistry.matching(request)` returns matching policies in
descending priority order. `ToolRegistry` stores unique `ToolSpec.name` values.
All mutations record provision tokens and undo actions in the shared journal.

- [ ] **Step 4: Implement context and executor**

`SwarmContext.__init__()` creates one RegistrationJournal, all six registries,
`CapabilityExecutor(self)`, and a `plugin_loader = None` lifecycle slot that
`create_runtime()` fills after profile loading. Implement the executor with this
fixed flow:

```python
async def execute(self, request: ExecutionRequest) -> ExecutionResult:
    self._ctx.capabilities.get(request.capability, request.version)
    units = tuple(self._ctx.units.resolve(uid) for uid in request.unit_ids)
    provider = self._ctx.providers.resolve(request.capability, request.version, units)
    for policy in self._ctx.policies.matching(request):
        try:
            outcome = await policy.evaluate(request, units, provider)
        except Exception as exc:
            raise PolicyRejectedError(f"policy {policy.policy_id} failed closed") from exc
        if outcome.decision is PolicyDecision.DENY:
            raise PolicyRejectedError(outcome.message or f"policy {policy.policy_id} denied request")
    try:
        return await provider.execute(request, units)
    except RuntimeResolutionError:
        raise
    except Exception as exc:
        self._logger.exception("provider execution failed", extra={"request_id": request.request_id})
        raise RuntimeExecutionError("capability execution failed") from exc
```

Capability lookup failure must be translated to `ProviderNotFoundError` with
`UNSUPPORTED_CAPABILITY`, not leaked as a raw `KeyError`.

- [ ] **Step 5: Run Tasks 1-2 tests and commit**

```powershell
python -m pytest tests/test_runtime_registries.py tests/test_runtime_executor.py -q
git add mcp/swarm_runtime mcp/tests/test_runtime_executor.py
git commit -m "feat: add deterministic capability executor"
```

Expected: all runtime tests pass.

### Task 3: Transactional Manifest and Profile Loader

**Files:**
- Create: `mcp/swarm_runtime/plugin.py`
- Create: `mcp/swarm_runtime/plugin_loader.py`
- Test: `mcp/tests/test_plugin_loader.py`

- [ ] **Step 1: Write failing loader behavior tests**

Use `tmp_path` to create three manifest directories and a profile. Inject an
entrypoint resolver into `PluginLoader` so tests do not modify `sys.path`.
Implement these concrete cases:

```python
def test_profile_imports_only_explicitly_enabled_plugins(tmp_path: Path) -> None:
    write_manifest(tmp_path, "enabled", entrypoint="fake:Enabled", provides=["service:enabled"])
    write_manifest(tmp_path, "ignored", entrypoint="fake:Ignored", provides=["service:ignored"])
    profile = write_profile(tmp_path, [{"id": "enabled", "enabled": True, "config": {}}])
    resolved: list[str] = []
    loader = PluginLoader(SwarmContext(), tmp_path, resolver=resolver_recording(resolved))
    loader.load_profile(profile)
    assert resolved == ["fake:Enabled"]


def test_setup_failure_rolls_back_every_registration(tmp_path: Path) -> None:
    profile = profile_for(tmp_path, "broken")
    ctx = SwarmContext()
    loader = PluginLoader(ctx, tmp_path, resolver=lambda _: BrokenAfterRegistration)
    with pytest.raises(PluginLoadError):
        loader.load_profile(profile)
    with pytest.raises(KeyError):
        ctx.services.get("temporary")
    assert loader.loaded_plugin_ids == ()


def test_dependency_cycle_fails_before_setup(tmp_path: Path) -> None:
    write_manifest(tmp_path, "a", requires=["b"])
    write_manifest(tmp_path, "b", requires=["a"])
    profile = write_profile(tmp_path, enabled("a"), enabled("b"))
    with pytest.raises(PluginLoadError, match="dependency cycle"):
        PluginLoader(SwarmContext(), tmp_path).load_profile(profile)


def test_missing_declared_provision_rolls_back_plugin(tmp_path: Path) -> None:
    write_manifest(tmp_path, "bad-provides", provides=["tool:navigateTo"])
    with pytest.raises(PluginLoadError, match="tool:navigateTo"):
        load_with_class(tmp_path, "bad-provides", PluginRegisteringNothing)
```

Also test unsupported `api_version`, duplicate manifest IDs, a missing required
plugin, config delivery to `setup(ctx, config)`, reverse dependency setup order,
and `unload_all()` removing services/units/tools even when `teardown()` raises.

- [ ] **Step 2: Run tests and verify RED**

```powershell
python -m pytest tests/test_plugin_loader.py -q
```

Expected: collection fails because `swarm_runtime.plugin_loader` is absent.

- [ ] **Step 3: Implement manifest/profile parsing and plugin protocol**

Define frozen `PluginManifest`, `ProfilePlugin`, and `PluginProfile` dataclasses.
Reject unknown shapes with `PluginLoadError`; require `api_version == 1`, non-empty
IDs/versions/entrypoints, list-valued `requires`/`provides`, and object-valued
profile configs. Define:

```python
class SwarmPlugin(Protocol):
    plugin_id: str
    version: str
    def setup(self, ctx: SwarmContext, config: Mapping[str, Any]) -> None: ...
    def teardown(self, ctx: SwarmContext) -> None: ...
```

Plugins without an explicit teardown are valid; the loader detects the method
with `getattr`.

- [ ] **Step 4: Implement allowlisted discovery, topological loading, and rollback**

`PluginLoader` recursively indexes `plugin.json` below `plugin_root`, but imports
only enabled profile IDs. Resolve dependencies with DFS colors (`unseen`,
`visiting`, `done`) and preserve profile order among independent nodes. For each
plugin:

```python
with ctx.registration_journal.activate(manifest.id) as transaction:
    plugin = plugin_class()
    if plugin.plugin_id != manifest.id or plugin.version != manifest.version:
        raise PluginLoadError(f"entrypoint identity does not match {manifest.id}")
    plugin.setup(ctx, profile_entry.config)
    missing = set(manifest.provides) - transaction.provisions
    if missing:
        raise PluginLoadError(f"plugin {manifest.id} did not provide: {sorted(missing)}")
```

The default entrypoint resolver splits `module:object`, imports the module with
`importlib.import_module(module)`, obtains the named class with `getattr`, and
rejects entrypoints without exactly one non-empty module and object component.
The activation context rolls back on exceptions and retains undo actions after
success. Store `(manifest, plugin, transaction)` for unload. `unload_all()` walks
loaded plugins in reverse order, calls teardown inside `try`, and invokes rollback
inside `finally` so teardown failures never leave registrations active.

- [ ] **Step 5: Run loader tests and commit**

```powershell
python -m pytest tests/test_plugin_loader.py tests/test_runtime_registries.py -q
git add mcp/swarm_runtime/plugin.py mcp/swarm_runtime/plugin_loader.py mcp/tests/test_plugin_loader.py
git commit -m "feat: load swarm plugins transactionally from profiles"
```

Expected: all selected tests pass.

### Task 4: Navigation Capability Plugin and FastMCP Bridge

**Files:**
- Create: `mcp/plugins/__init__.py`
- Create: `mcp/plugins/capabilities/__init__.py`
- Create: `mcp/plugins/capabilities/navigation/__init__.py`
- Create: `mcp/plugins/capabilities/navigation/plugin.json`
- Create: `mcp/plugins/capabilities/navigation/plugin.py`
- Create: `mcp/plugins/capabilities/navigation/tools.py`
- Create: `mcp/swarm_runtime/fastmcp_bridge.py`
- Test: `mcp/tests/test_navigation_capability_plugin.py`

- [ ] **Step 1: Write failing capability-tool and schema tests**

Load only `NavigationCapabilityPlugin` into a context with a fake unit/provider,
then install its tools into FastMCP. Assert the schema equals the current schema:

```python
@pytest.mark.asyncio
async def test_navigation_plugin_preserves_navigate_to_schema() -> None:
    app = FastMCP("test")
    ctx = context_with_navigation_provider()
    NavigationCapabilityPlugin().setup(ctx, {})
    install_runtime_tools(app, ctx.tools)
    tool = await app.get_tool("navigateTo")
    assert tool.parameters["required"] == ["unit_id", "target"]
    assert tool.parameters["properties"]["tolerance_m"] == {"default": 0.15, "type": "number"}
    assert tool.parameters["properties"]["timeout_ms"] == {"default": 30000, "type": "integer"}
    assert tool.parameters["$defs"]["Point2D"]["required"] == ["x", "y"]


@pytest.mark.asyncio
async def test_navigate_to_builds_versioned_execution_request() -> None:
    provider = CapturingProvider()
    app = app_with_provider(provider)
    result = await app.call_tool(
        "navigateTo",
        {"unit_id": "robot_1", "target": {"x": 3.0, "y": 5.0}},
    )
    assert json.loads(result.content[0].text)["success"] is True
    assert provider.request.capability == "navigation.goto2d"
    assert provider.request.version == "1.0"
    assert provider.request.arguments == {
        "x": 3.0, "y": 5.0, "tolerance_m": 0.15, "timeout_ms": 30000,
    }
```

Add tests for missing target fields returning a complete `SAFETY_REJECTED`
TaskResult when the callable is invoked directly, unit resolution returning
`UNIT_NOT_FOUND`, no provider returning `UNSUPPORTED_CAPABILITY`, policy rejection
returning `SAFETY_REJECTED`, and unexpected execution failure returning a complete
`INTERNAL_ERROR`/`FAILED` TaskResult.

- [ ] **Step 2: Run tests and verify RED**

```powershell
python -m pytest tests/test_navigation_capability_plugin.py -q
```

Expected: collection fails because the capability plugin and bridge are absent.

- [ ] **Step 3: Implement the typed navigation callable**

In `tools.py`, keep the public TypedDict name and signature exactly:

```python
class Point2D(TypedDict):
    x: float
    y: float


def build_navigate_to(ctx: SwarmContext):
    async def navigateTo(
        unit_id: str,
        target: Point2D,
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        if not isinstance(target, dict) or "x" not in target or "y" not in target:
            return rejected_task_response(
                task_type="navigate_to", error_code="SAFETY_REJECTED",
                message="target requires x and y",
            )
        request = ExecutionRequest(
            request_id=str(uuid.uuid4()), capability="navigation.goto2d", version="1.0",
            unit_ids=(unit_id,),
            arguments={"x": target["x"], "y": target["y"],
                       "tolerance_m": tolerance_m, "timeout_ms": timeout_ms},
            metadata={"tool_name": "navigateTo"},
        )
        try:
            return (await ctx.executor.execute(request)).to_json()
        except RuntimeResolutionError as exc:
            return rejected_task_response(
                task_type="navigate_to", error_code=exc.error_code, message=exc.message,
            )
        except RuntimeExecutionError as exc:
            return response(
                success=False, message=exc.message, error_code=exc.error_code,
                data=empty_task_result(
                    task_type="navigate_to", state="FAILED",
                    message=exc.message, error_code=exc.error_code,
                ),
            )
    return navigateTo
```

`NavigationCapabilityPlugin.setup()` registers the exact `CapabilitySpec` and
`ToolSpec("navigateTo", build_navigate_to(ctx))`. Its manifest declares
`capability:navigation.goto2d@1.0` and `tool:navigateTo`:

```json
{
  "api_version": 1,
  "id": "capability.navigation",
  "version": "1.0.0",
  "type": "capability",
  "entrypoint": "plugins.capabilities.navigation.plugin:NavigationCapabilityPlugin",
  "requires": [],
  "provides": ["capability:navigation.goto2d@1.0", "tool:navigateTo"]
}
```

- [ ] **Step 4: Implement FastMCP installation and run tests**

`install_runtime_tools(mcp, registry)` iterates `registry.list()` in sorted tool
name order, asserts `spec.callable.__name__ == spec.name`, and calls
`mcp.add_tool(spec.callable)`. ToolRegistry already rejects duplicate runtime
names; the integration test verifies that no static MCP decorator retained the
`navigateTo` name.

Run:

```powershell
python -m pytest tests/test_navigation_capability_plugin.py tests/test_runtime_executor.py -q
git add mcp/plugins/capabilities mcp/plugins/__init__.py mcp/swarm_runtime/fastmcp_bridge.py mcp/tests/test_navigation_capability_plugin.py
git commit -m "feat: register navigation capability as a typed MCP tool"
```

Expected: all selected tests pass.

### Task 5: KIS-ORB SAU Platform Plugin and Default Profile

**Files:**
- Create: `mcp/plugins/platforms/__init__.py`
- Create: `mcp/plugins/platforms/kisorb_sau/__init__.py`
- Create: `mcp/plugins/platforms/kisorb_sau/plugin.json`
- Create: `mcp/plugins/platforms/kisorb_sau/plugin.py`
- Create: `mcp/plugins/platforms/kisorb_sau/providers.py`
- Create: `mcp/profiles/default.json`
- Test: `mcp/tests/test_kisorb_plugin.py`

- [ ] **Step 1: Write failing KIS-ORB registration and forwarding tests**

```python
def test_kisorb_plugin_registers_configured_units_and_shared_services() -> None:
    ctx = SwarmContext()
    plugin = KisorbPlugin()
    plugin.setup(ctx, {"tool_timeout_s": 7.5})
    assert ctx.units.resolve("robot_1").unit_id == "GV1"
    assert ctx.units.resolve("GV1").platform == "kisorb-sau"
    adapter = ctx.services.get("legacy.robot_adapter")
    client = ctx.services.get("legacy.console_task_client")
    assert client._adapter is adapter
    assert adapter._manager.tool_timeout_s == 7.5


@pytest.mark.asyncio
async def test_kisorb_provider_forwards_canonical_unit_and_arguments(monkeypatch) -> None:
    call = AsyncMock(return_value=complete_running_task_json())
    monkeypatch.setattr(ConsoleTaskClient, "navigate_to", call)
    ctx = load_default_runtime()
    result = await ctx.executor.execute(request_for("robot_1", x=3.0, y=-2.0))
    assert result.success is True
    call.assert_awaited_once_with(
        unit_id="GV1", x=3.0, y=-2.0, tolerance_m=0.15, timeout_ms=30000,
    )
```

Also test that the provider rejects non-KIS-ORB units in `supports()`, malformed
Console JSON becomes a provider exception handled as `INTERNAL_ERROR`, and the
default profile loads only Navigation and KIS-ORB plugin IDs.

- [ ] **Step 2: Run tests and verify RED**

```powershell
python -m pytest tests/test_kisorb_plugin.py -q
```

Expected: collection fails because the KIS-ORB plugin is absent.

- [ ] **Step 3: Implement shared services, units, and provider**

`KisorbGoto2DProvider` declares:

```python
provider_id = "kisorb.navigation.goto2d"
capability = "navigation.goto2d"
version = "1.0"
priority = 100

def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
    return len(units) == 1 and units[0].platform == "kisorb-sau"

async def execute(self, request, units) -> ExecutionResult:
    unit = units[0]
    raw = await self._client.navigate_to(
        unit_id=unit.unit_id,
        x=request.arguments["x"], y=request.arguments["y"],
        tolerance_m=request.arguments["tolerance_m"],
        timeout_ms=request.arguments["timeout_ms"],
    )
    return ExecutionResult.from_json(raw)
```

`KisorbPlugin.setup()` reads `tool_timeout_s` with
`DEFAULT_TOOL_TIMEOUT_S` as the default, creates exactly one RobotAdapter and
ConsoleTaskClient, registers the two generic legacy service IDs, registers one
UnitDescriptor per `load_robot_configs()` entry with `robot_id` as an alias, and
registers one provider. The manifest requires `capability.navigation` and declares
the provider plus both service tokens:

```json
{
  "api_version": 1,
  "id": "platform.kisorb-sau",
  "version": "1.0.0",
  "type": "platform",
  "entrypoint": "plugins.platforms.kisorb_sau.plugin:KisorbPlugin",
  "requires": ["capability.navigation"],
  "provides": [
    "provider:kisorb.navigation.goto2d",
    "service:legacy.robot_adapter",
    "service:legacy.console_task_client"
  ]
}
```

- [ ] **Step 4: Add and verify the production profile**

Create `default.json`:

```json
{
  "profile_api_version": 1,
  "plugins": [
    {"id": "capability.navigation", "enabled": true, "config": {}},
    {"id": "platform.kisorb-sau", "enabled": true, "config": {}}
  ]
}
```

Run:

```powershell
python -m pytest tests/test_kisorb_plugin.py tests/test_plugin_loader.py -q
git add mcp/plugins/platforms mcp/profiles/default.json mcp/tests/test_kisorb_plugin.py
git commit -m "feat: add KIS-ORB navigation provider plugin"
```

Expected: all selected tests pass.

### Task 6: Mock Second-Platform Plugin and Profile Acceptance Test

**Files:**
- Create: `mcp/plugins/platforms/mock_navigation/__init__.py`
- Create: `mcp/plugins/platforms/mock_navigation/plugin.json`
- Create: `mcp/plugins/platforms/mock_navigation/plugin.py`
- Create: `mcp/plugins/platforms/mock_navigation/providers.py`
- Create: `mcp/profiles/mock-navigation.json`
- Test: `mcp/tests/test_mock_navigation_plugin.py`

- [ ] **Step 1: Write the failing second-platform proof**

```python
@pytest.mark.asyncio
async def test_mock_profile_executes_same_capability_without_core_changes() -> None:
    ctx = load_runtime(PROFILES / "mock-navigation.json")
    request = ExecutionRequest(
        request_id="req-mock", capability="navigation.goto2d", version="1.0",
        unit_ids=("mock_robot",),
        arguments={"x": 2.0, "y": 3.0, "tolerance_m": 0.15, "timeout_ms": 30000},
    )
    result = await ctx.executor.execute(request)
    assert result.success is True
    assert result.data["task_type"] == "navigate_to"
    assert result.data["state"] == "COMPLETED"
    assert result.data["unit_results"][0]["unit_id"] == "MOCK1"


def test_default_profile_does_not_register_mock_unit() -> None:
    ctx = load_runtime(PROFILES / "default.json")
    with pytest.raises(UnitNotFoundError):
        ctx.units.resolve("MOCK1")
```

Record hashes of `mcp/swarm_runtime/executor.py`, each registry file, and the
Navigation Capability Plugin before loading both profiles; assert loading and
executing the Mock profile does not modify those files.

- [ ] **Step 2: Run tests and verify RED**

```powershell
python -m pytest tests/test_mock_navigation_plugin.py -q
```

Expected: collection or profile loading fails because Mock files are absent.

- [ ] **Step 3: Implement the in-memory provider and profile**

Register `UnitDescriptor("MOCK1", "ugv", "mock-navigation",
"platform.mock-navigation", aliases=("mock_robot",))`. The provider supports
only that platform and returns an `ExecutionResult` whose `data` contains every
current TaskResult field: `success`, `task_id`, `task_type`, `state`,
`progress_pct`, `message`, `error_code`, `unit_results`, `elapsed_ms`,
`started_at_ms`, and `cancellation_effect`. Use `COMPLETED`, 100 percent,
`NOT_APPLICABLE`, and one successful unit result containing the requested target.

Create `mock-navigation.json` with Navigation, KIS-ORB, and Mock plugins. Keeping
KIS-ORB in this profile preserves shared legacy services for the thirteen
unmigrated tools while provider `supports()` routes `MOCK1` to Mock and `GV1` to
KIS-ORB. Use this Mock manifest and profile:

```json
{
  "api_version": 1,
  "id": "platform.mock-navigation",
  "version": "1.0.0",
  "type": "platform",
  "entrypoint": "plugins.platforms.mock_navigation.plugin:MockNavigationPlugin",
  "requires": ["capability.navigation"],
  "provides": ["provider:mock.navigation.goto2d", "unit:MOCK1"]
}
```

```json
{
  "profile_api_version": 1,
  "plugins": [
    {"id": "capability.navigation", "enabled": true, "config": {}},
    {"id": "platform.kisorb-sau", "enabled": true, "config": {}},
    {"id": "platform.mock-navigation", "enabled": true, "config": {}}
  ]
}
```

- [ ] **Step 4: Run acceptance tests and commit**

```powershell
python -m pytest tests/test_mock_navigation_plugin.py tests/test_kisorb_plugin.py -q
git add mcp/plugins/platforms/mock_navigation mcp/profiles/mock-navigation.json mcp/tests/test_mock_navigation_plugin.py
git commit -m "test: prove second navigation platform via profile"
```

Expected: all selected tests pass.

### Task 7: Hybrid Main Bootstrap and Production Contract Migration

**Files:**
- Modify: `mcp/main.py:12-123`
- Modify: `mcp/requirements.txt:1`
- Modify: `mcp/tests/test_task_architecture.py:27-60`
- Create: `mcp/tests/test_runtime_main_integration.py`

- [ ] **Step 1: Write failing production integration tests**

Add the complete current `navigateTo` schema as a literal expected dictionary,
including `$defs.Point2D`, `additionalProperties: false`, required fields, and
defaults. Add these routing tests:

```python
@pytest.mark.asyncio
async def test_production_navigate_to_routes_through_kisorb_provider(monkeypatch) -> None:
    call = AsyncMock(return_value=complete_running_task_json())
    monkeypatch.setattr(ConsoleTaskClient, "navigate_to", call)
    result = await create_app().call_tool(
        "navigateTo",
        {"unit_id": "robot_1", "target": {"x": 3.0, "y": 5.0},
         "tolerance_m": 0.2, "timeout_ms": 5000},
    )
    payload = json.loads(result.content[0].text)
    assert payload["success"] is True
    call.assert_awaited_once_with(
        unit_id="GV1", x=3.0, y=5.0, tolerance_m=0.2, timeout_ms=5000,
    )


@pytest.mark.asyncio
async def test_mock_profile_keeps_fourteen_tools_and_routes_mock_unit() -> None:
    app = create_app(PROFILES / "mock-navigation.json")
    assert {tool.name for tool in await app.list_tools()} == PRODUCTION_TOOL_NAMES
    result = await app.call_tool(
        "navigateTo", {"unit_id": "MOCK1", "target": {"x": 1.0, "y": 2.0}},
    )
    assert json.loads(result.content[0].text)["data"]["state"] == "COMPLETED"
```

Retain existing assertions that debug tools are opt-in and the IDL method set
equals the production tool set. Run these tests before changing `main.py`; expect
failure because `create_app` has no profile argument and `navigateTo` still calls
TaskService directly.

- [ ] **Step 2: Implement synchronous runtime bootstrap**

Add:

```python
DEFAULT_PROFILE = Path(__file__).resolve().with_name("profiles") / "default.json"
PLUGIN_ROOT = Path(__file__).resolve().with_name("plugins")


def create_runtime(profile_path: str | Path | None = None) -> SwarmContext:
    ctx = SwarmContext()
    loader = PluginLoader(ctx, PLUGIN_ROOT)
    loader.load_profile(Path(profile_path) if profile_path else DEFAULT_PROFILE)
    ctx.plugin_loader = loader
    return ctx
```

Change `create_app(profile_path=None)` to create the runtime first, obtain
`legacy.robot_adapter` and `legacy.console_task_client`, then construct the
existing CapabilityService and TaskService. Remove only the decorated
`navigateTo` function at current lines 99-123. Leave `Point2D` because
`moveFollowFormation` still uses it. After registering the other thirteen tools,
call `install_runtime_tools(mcp, ctx.tools)`. Pass the shared adapter to
`register_low_level_tools`.

The runtime core and capability plugin must not import `robot_adapter`,
`console_client`, `config`, or any SAU module. Only the KIS-ORB platform plugin
may import those modules.

- [ ] **Step 3: Pin FastMCP and run focused integration tests**

Change the first requirement to:

```text
fastmcp==3.4.2
```

Run:

```powershell
python -m pytest tests/test_runtime_main_integration.py tests/test_task_architecture.py tests/test_main_formation_tools.py -q
```

Expected: all selected tests pass, tool count remains fourteen, and the exact
schema literal matches.

- [ ] **Step 4: Run the complete non-live Python suite and commit**

```powershell
python -m pytest tests -q
git add mcp/main.py mcp/requirements.txt mcp/tests/test_task_architecture.py mcp/tests/test_runtime_main_integration.py
git commit -m "feat: route navigateTo through swarm plugin runtime"
```

Expected: the existing baseline remains `210 passed, 3 skipped` plus all newly
added tests; no previously passing test fails.

### Task 8: Documentation, Static Boundary Audit, and Final Verification

**Files:**
- Modify: `README.md`
- Create: `mcp/tests/test_runtime_boundaries.py`
- Verify: `mcp/idl/mcp_swarm_task.idl`
- Verify: `SAU/Console/`

- [ ] **Step 1: Write the boundary audit before documentation changes**

Create a static test that imports `ast`, walks every Python file below
`mcp/swarm_runtime` and `mcp/plugins/capabilities`, and fails if imports start with
`robot_adapter`, `console_client`, `config`, `plugins.platforms`, or an SAU name.
Also assert the KIS-ORB plugin is the only new package importing RobotAdapter and
ConsoleTaskClient, default Profile excludes `platform.mock-navigation`, the IDL
file contains no generic `execute(string operation, string json)` escape hatch,
and `mcp/idl/mcp_swarm_task.idl` retains its pre-change SHA-256
`2EA71279A5FD8C0AD1157ED38F5EA7E04621EF439DB16E86CBEA65FEDB625F1A`.

- [ ] **Step 2: Run the audit and verify it passes**

```powershell
python -m pytest tests/test_runtime_boundaries.py -q
```

Expected: all boundary assertions pass. If an import is reported, move it to the
KIS-ORB plugin rather than weakening the forbidden-import set.

- [ ] **Step 3: Document profiles and migration status**

Update the root README architecture and quick-validation sections with:

- `navigateTo` now follows Tool Registry -> CapabilityExecutor -> Provider;
- the other thirteen tools remain on the legacy task-service path;
- `profiles/default.json` is production and does not expose the Mock unit;
- `profiles/mock-navigation.json` is the second-provider acceptance profile;
- a concise command showing `create_app()` uses the default profile and pytest
  verifies both profiles;
- the unchanged SAU Console and IDL boundary.

Do not claim that all tools, safety policies, IDLs, ROS2, or PX4 are pluginized.

- [ ] **Step 4: Perform syntax, dependency, contract, and full regression checks**

Run from `E:\MCP-IDL\mcp`:

```powershell
python -m compileall -q main.py swarm_runtime plugins
python -c "import fastmcp; assert fastmcp.__version__ == '3.4.2'; print(fastmcp.__version__)"
python -m pytest tests -q
```

Run from `E:\MCP-IDL`:

```powershell
git diff --check
git status --short
```

Expected: syntax check is silent, version output is `3.4.2`, all non-live Python
tests pass, `git diff --check` is silent, and status contains only intentional
source/test/documentation changes plus pre-existing untracked project content.

- [ ] **Step 5: Confirm protected scope and commit documentation**

Use path-scoped Git checks:

```powershell
git diff -- mcp/idl SAU/Console
git add README.md mcp/tests/test_runtime_boundaries.py
git commit -m "docs: describe swarm runtime navigation slice"
```

Expected: the first command is empty; the documentation commit succeeds.

## Final requirement checklist

- [ ] `navigateTo` is owned by `capability.navigation`, not by a platform plugin.
- [ ] Default execution resolves `robot_1` to `GV1` and selects KIS-ORB by unit platform.
- [ ] Mock execution uses the same capability and tool with no Core modification.
- [ ] Provider selection is exact-version, priority-based, deterministic, and ambiguity-safe.
- [ ] Policy denial is monotonic and policy exceptions fail closed.
- [ ] Plugin setup is allowlisted, dependency-ordered, provision-checked, and reversible.
- [ ] The shared adapter/client instance serves both the new provider and thirteen legacy tools.
- [ ] Production and debug tool sets retain their current contracts.
- [ ] FastMCP is pinned to 3.4.2.
- [ ] No SAU Console or IDL files change.
- [ ] The full non-live suite passes with all newly added tests.
