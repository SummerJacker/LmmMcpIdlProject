# Swarm Harness Dynamic Unit Resolution Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Preserve the legacy live-Console UnitID behavior for all runtime-owned tools by adding a transactional asynchronous Unit Resolver extension point and a KIS-ORB live-directory resolver.

**Architecture:** CapabilityExecutor keeps static UnitRegistry resolution as the fast, authoritative first path and falls back asynchronously only after UnitNotFoundError. A platform-neutral UnitResolverRegistry selects deterministic resolver candidates; the KIS-ORB plugin registers a resolver that reads the shared RobotAdapter's public `list_robots()` response and returns request-scoped UnitDescriptors without mutating static state.

**Tech Stack:** Python 3.10+, dataclasses and Protocol, asyncio, FastMCP 3.4.2, JSON, pytest, pytest-asyncio.

---

## File map

| Path | Responsibility |
| --- | --- |
| `mcp/swarm_runtime/protocols.py` | Define the asynchronous platform-neutral UnitResolver contract |
| `mcp/swarm_runtime/errors.py` | Represent ambiguous dynamic identity with stable `UNIT_NOT_FOUND` mapping |
| `mcp/swarm_runtime/registry/unit_resolver.py` | Register, roll back, select, and isolate asynchronous resolver candidates |
| `mcp/swarm_runtime/registry/__init__.py` | Export UnitResolverRegistry |
| `mcp/swarm_runtime/context.py` | Own the UnitResolverRegistry beside static UnitRegistry |
| `mcp/swarm_runtime/executor.py` | Resolve static units first, then await dynamic fallback |
| `mcp/tests/test_runtime_unit_resolvers.py` | Cover registration, priority, ambiguity, exceptions, precedence, and no mutation |
| `mcp/plugins/platforms/kisorb_sau/unit_resolver.py` | Resolve direct canonical UnitIDs from the live Console binding table |
| `mcp/plugins/platforms/kisorb_sau/plugin.py` | Register the live resolver against the shared RobotAdapter |
| `mcp/plugins/platforms/kisorb_sau/plugin.json` | Declare `unit_resolver:kisorb.live` provision |
| `mcp/tests/test_kisorb_plugin.py` | Verify live response parsing, plugin ownership, and manifest registration |
| `mcp/tests/test_runtime_main_integration.py` | Prove dynamic Navigate, FollowPath, and Stop production compatibility |
| `mcp/tests/test_runtime_boundaries.py` | Keep platform imports out of Runtime Core and protect IDL/SAU boundaries |

Do not modify `mcp/robot_adapter.py`, `mcp/console_client/`, `mcp/idl/`,
`SAU/Console/`, public MCP tool callables, providers, Motion/Navigation manifests,
profiles, or Mock behavior.

### Task 1: Add the Asynchronous Unit Resolver Runtime Extension

**Files:**
- Create: `mcp/swarm_runtime/registry/unit_resolver.py`
- Create: `mcp/tests/test_runtime_unit_resolvers.py`
- Modify: `mcp/swarm_runtime/protocols.py`
- Modify: `mcp/swarm_runtime/errors.py`
- Modify: `mcp/swarm_runtime/registry/__init__.py`
- Modify: `mcp/swarm_runtime/context.py`
- Modify: `mcp/swarm_runtime/executor.py`

- [ ] **Step 1: Write failing registry and executor tests**

Create `test_runtime_unit_resolvers.py`:

```python
from __future__ import annotations

from dataclasses import dataclass

import pytest

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import (
    AmbiguousUnitResolutionError,
    DuplicateRegistrationError,
    RuntimeRegistrationError,
    UnitNotFoundError,
)
from swarm_runtime.models import (
    CapabilitySpec,
    ExecutionRequest,
    ExecutionResult,
    UnitDescriptor,
)


@dataclass
class StubResolver:
    resolver_id: str
    priority: int
    result: UnitDescriptor | None = None
    error: Exception | None = None
    calls: int = 0

    async def resolve(self, unit_id_or_alias: str) -> UnitDescriptor | None:
        self.calls += 1
        if self.error is not None:
            raise self.error
        return self.result


@dataclass
class RecordingProvider:
    provider_id: str = "test.navigation.goto2d"
    capability: str = "navigation.goto2d"
    version: str = "1.0"
    priority: int = 100
    units: tuple[UnitDescriptor, ...] = ()

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "test-live"

    async def execute(self, request, units) -> ExecutionResult:
        self.units = units
        return ExecutionResult(True, "ok", {"unit_id": units[0].unit_id})


def live_unit(unit_id: str = "GV_DYNAMIC") -> UnitDescriptor:
    return UnitDescriptor(
        unit_id=unit_id,
        kind="ugv",
        platform="test-live",
        provider_plugin_id="platform.test-live",
        metadata={"source": "test-live"},
    )


def request_for(unit_id: str) -> ExecutionRequest:
    return ExecutionRequest(
        request_id="dynamic-request",
        capability="navigation.goto2d",
        version="1.0",
        unit_ids=(unit_id,),
        arguments={},
    )


def execution_context() -> tuple[SwarmContext, RecordingProvider]:
    ctx = SwarmContext()
    ctx.capabilities.register(
        CapabilitySpec("navigation.goto2d", "1.0", "Navigate", "unit")
    )
    provider = RecordingProvider()
    ctx.providers.register(provider)
    return ctx, provider


def test_unit_resolver_registry_rejects_duplicate_ids() -> None:
    ctx = SwarmContext()
    ctx.unit_resolvers.register(StubResolver("resolver.test", 100))

    with pytest.raises(DuplicateRegistrationError):
        ctx.unit_resolvers.register(StubResolver("resolver.test", 50))


def test_unit_resolver_registry_rejects_empty_id() -> None:
    ctx = SwarmContext()

    with pytest.raises(RuntimeRegistrationError):
        ctx.unit_resolvers.register(StubResolver("   ", 100))


def test_unit_resolver_registration_rolls_back_with_plugin_transaction() -> None:
    ctx = SwarmContext()

    with pytest.raises(RuntimeError):
        with ctx.registration_journal.activate("platform.test"):
            ctx.unit_resolvers.register(StubResolver("resolver.test", 100))
            raise RuntimeError("setup failed")

    assert ctx.unit_resolvers.list() == ()


@pytest.mark.asyncio
async def test_executor_prefers_static_unit_without_calling_dynamic_resolver() -> None:
    ctx, provider = execution_context()
    static = live_unit("GV1")
    ctx.units.register(static)
    resolver = StubResolver("resolver.test", 100, live_unit("GV_DYNAMIC"))
    ctx.unit_resolvers.register(resolver)

    result = await ctx.executor.execute(request_for("GV1"))

    assert result.success is True
    assert provider.units == (static,)
    assert resolver.calls == 0


@pytest.mark.asyncio
async def test_executor_uses_dynamic_descriptor_without_mutating_static_units() -> None:
    ctx, provider = execution_context()
    dynamic = live_unit()
    ctx.unit_resolvers.register(StubResolver("resolver.test", 100, dynamic))

    result = await ctx.executor.execute(request_for("gv_dynamic"))

    assert result.success is True
    assert provider.units == (dynamic,)
    assert ctx.units.list() == ()


@pytest.mark.asyncio
async def test_highest_priority_dynamic_candidate_wins() -> None:
    ctx, provider = execution_context()
    low = StubResolver("resolver.low", 10, live_unit("GV_LOW"))
    high = StubResolver("resolver.high", 100, live_unit("GV_HIGH"))
    ctx.unit_resolvers.register(low)
    ctx.unit_resolvers.register(high)

    await ctx.executor.execute(request_for("dynamic"))

    assert provider.units[0].unit_id == "GV_HIGH"
    assert low.calls == 1
    assert high.calls == 1


@pytest.mark.asyncio
async def test_equal_priority_dynamic_candidates_are_ambiguous() -> None:
    ctx, _ = execution_context()
    ctx.unit_resolvers.register(
        StubResolver("resolver.a", 100, live_unit("GV_A"))
    )
    ctx.unit_resolvers.register(
        StubResolver("resolver.b", 100, live_unit("GV_B"))
    )

    with pytest.raises(AmbiguousUnitResolutionError) as error:
        await ctx.executor.execute(request_for("dynamic"))

    assert error.value.error_code == "UNIT_NOT_FOUND"


@pytest.mark.asyncio
async def test_resolver_exception_abstains_and_does_not_leak(caplog) -> None:
    ctx, provider = execution_context()
    ctx.unit_resolvers.register(
        StubResolver("resolver.broken", 200, error=ValueError("private failure"))
    )
    ctx.unit_resolvers.register(
        StubResolver("resolver.good", 100, result=live_unit("GV_GOOD"))
    )

    result = await ctx.executor.execute(request_for("dynamic"))

    assert result.success is True
    assert provider.units[0].unit_id == "GV_GOOD"
    assert "private failure" not in result.message
    assert "resolver.broken" in caplog.text


@pytest.mark.asyncio
async def test_no_dynamic_candidate_preserves_unit_not_found() -> None:
    ctx, _ = execution_context()
    ctx.unit_resolvers.register(StubResolver("resolver.none", 100, None))

    with pytest.raises(UnitNotFoundError) as error:
        await ctx.executor.execute(request_for("missing"))

    assert error.value.error_code == "UNIT_NOT_FOUND"
    assert error.value.message == "unit not found: missing"
```

- [ ] **Step 2: Run the new module and verify RED**

Run from `E:\MCP-IDL\mcp`:

```powershell
python -m pytest tests/test_runtime_unit_resolvers.py -q
```

Expected: collection fails because UnitResolverRegistry,
AmbiguousUnitResolutionError, and `ctx.unit_resolvers` do not exist.

- [ ] **Step 3: Define the UnitResolver protocol and ambiguity error**

Add to `swarm_runtime/protocols.py`:

```python
class UnitResolver(Protocol):
    resolver_id: str
    priority: int

    async def resolve(self, unit_id_or_alias: str) -> UnitDescriptor | None:
        ...
```

Add to `swarm_runtime/errors.py`:

```python
class AmbiguousUnitResolutionError(RuntimeResolutionError):
    def __init__(self, unit_id_or_alias: str) -> None:
        super().__init__(
            f"ambiguous unit resolution: {unit_id_or_alias}",
            error_code="UNIT_NOT_FOUND",
        )
```

- [ ] **Step 4: Implement UnitResolverRegistry**

Create `swarm_runtime/registry/unit_resolver.py`:

```python
from __future__ import annotations

import logging

from ..errors import (
    AmbiguousUnitResolutionError,
    DuplicateRegistrationError,
    RuntimeRegistrationError,
    UnitNotFoundError,
)
from ..models import UnitDescriptor
from ..protocols import UnitResolver
from ..registration import RegistrationJournal


class UnitResolverRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._resolvers: dict[str, UnitResolver] = {}
        self._logger = logging.getLogger("swarm_runtime.unit_resolvers")

    def register(self, resolver: UnitResolver) -> None:
        resolver_id = resolver.resolver_id.strip()
        if not resolver_id:
            raise RuntimeRegistrationError("unit resolver_id must not be empty")
        if resolver_id in self._resolvers:
            raise DuplicateRegistrationError(
                f"unit resolver already registered: {resolver_id}"
            )
        self._resolvers[resolver_id] = resolver
        self._journal.record(
            f"unit_resolver:{resolver_id}",
            lambda key=resolver_id: self._resolvers.pop(key, None),
        )

    def list(self) -> tuple[UnitResolver, ...]:
        return tuple(self._resolvers[key] for key in sorted(self._resolvers))

    async def resolve(self, unit_id_or_alias: str) -> UnitDescriptor:
        candidates: list[tuple[UnitResolver, UnitDescriptor]] = []
        for resolver in self.list():
            try:
                unit = await resolver.resolve(unit_id_or_alias)
            except Exception:
                self._logger.exception(
                    "unit resolver %s failed",
                    resolver.resolver_id,
                )
                continue
            if unit is not None:
                candidates.append((resolver, unit))

        if not candidates:
            raise UnitNotFoundError(unit_id_or_alias)
        candidates.sort(key=lambda item: (-item[0].priority, item[0].resolver_id))
        if len(candidates) > 1 and candidates[0][0].priority == candidates[1][0].priority:
            raise AmbiguousUnitResolutionError(unit_id_or_alias)
        return candidates[0][1]
```

- [ ] **Step 5: Export and compose the registry**

In `registry/__init__.py`, import UnitResolverRegistry and include it in
`__all__` if that module defines an export list.

In `context.py`, import it with the other registries and add immediately after
the static registry:

```python
self.units = UnitRegistry(self.registration_journal)
self.unit_resolvers = UnitResolverRegistry(self.registration_journal)
```

- [ ] **Step 6: Add asynchronous fallback to CapabilityExecutor**

Import UnitNotFoundError and UnitDescriptor in `executor.py`, then add:

```python
async def _resolve_unit(self, unit_id_or_alias: str) -> UnitDescriptor:
    try:
        return self._ctx.units.resolve(unit_id_or_alias)
    except UnitNotFoundError:
        return await self._ctx.unit_resolvers.resolve(unit_id_or_alias)
```

Replace the synchronous tuple comprehension with an ordered loop:

```python
resolved_units = []
for unit_id in request.unit_ids:
    resolved_units.append(await self._resolve_unit(unit_id))
units = tuple(resolved_units)
```

Do not change capability lookup, provider selection, policy ordering, exception
sanitization, or provider execution.

- [ ] **Step 7: Run focused runtime tests and verify GREEN**

```powershell
python -m pytest tests/test_runtime_unit_resolvers.py tests/test_runtime_registries.py tests/test_runtime_executor.py tests/test_plugin_loader.py -q
```

Expected: all selected tests pass. The new module contributes seven passing
tests; existing resolver/provider/policy behavior remains green.

- [ ] **Step 8: Commit Runtime Core extension**

```powershell
git add mcp/swarm_runtime/protocols.py mcp/swarm_runtime/errors.py mcp/swarm_runtime/registry/unit_resolver.py mcp/swarm_runtime/registry/__init__.py mcp/swarm_runtime/context.py mcp/swarm_runtime/executor.py mcp/tests/test_runtime_unit_resolvers.py
git diff --cached --name-only
git commit -m "feat: add asynchronous unit resolver registry"
```

Expected: exactly the seven listed files are staged. Existing untracked project
files remain untouched.

### Task 2: Register the KIS-ORB Live Resolver and Prove Production Compatibility

**Files:**
- Create: `mcp/plugins/platforms/kisorb_sau/unit_resolver.py`
- Modify: `mcp/plugins/platforms/kisorb_sau/plugin.py`
- Modify: `mcp/plugins/platforms/kisorb_sau/plugin.json`
- Modify: `mcp/tests/test_kisorb_plugin.py`
- Modify: `mcp/tests/test_runtime_main_integration.py`
- Modify: `mcp/tests/test_runtime_boundaries.py`

- [ ] **Step 1: Write failing KIS-ORB resolver tests**

Add these imports to `test_kisorb_plugin.py`:

```python
from robot_adapter import RobotAdapter
from plugins.platforms.kisorb_sau.unit_resolver import KisorbLiveUnitResolver
```

Add:

```python
def live_directory_json(*unit_ids: str) -> str:
    return json.dumps(
        {
            "success": True,
            "message": "ok",
            "data": {
                "units": [
                    {"unit_id": unit_id, "online": True, "mock": False}
                    for unit_id in unit_ids
                ]
            },
        }
    )


@pytest.mark.asyncio
async def test_kisorb_live_resolver_matches_canonical_id_case_insensitively() -> None:
    adapter = AsyncMock()
    adapter.list_robots.return_value = live_directory_json("GV_DYNAMIC")
    resolver = KisorbLiveUnitResolver(adapter)

    unit = await resolver.resolve(" gv_dynamic ")

    assert unit == UnitDescriptor(
        unit_id="GV_DYNAMIC",
        kind="ugv",
        platform="kisorb-sau",
        provider_plugin_id="platform.kisorb-sau",
        metadata={"source": "console-live"},
    )


@pytest.mark.asyncio
@pytest.mark.parametrize(
    "raw",
    [
        "not-json",
        json.dumps({"success": False, "data": {"units": [{"unit_id": "GV4"}]}}),
        json.dumps({"success": True, "data": {}}),
        json.dumps({"success": True, "data": {"units": [None, {"unit_id": ""}]}}),
    ],
)
async def test_kisorb_live_resolver_abstains_on_invalid_directory(raw: str) -> None:
    adapter = AsyncMock()
    adapter.list_robots.return_value = raw

    assert await KisorbLiveUnitResolver(adapter).resolve("GV4") is None


@pytest.mark.asyncio
async def test_kisorb_live_resolver_abstains_when_unit_is_not_bound() -> None:
    adapter = AsyncMock()
    adapter.list_robots.return_value = live_directory_json("GV1")

    assert await KisorbLiveUnitResolver(adapter).resolve("GV_MISSING") is None


def test_kisorb_plugin_registers_live_resolver_with_shared_adapter() -> None:
    ctx = SwarmContext()
    KisorbPlugin().setup(ctx, {})

    resolver = ctx.unit_resolvers.list()[0]
    assert resolver.resolver_id == "kisorb.live"
    assert resolver._adapter is ctx.services.get("legacy.robot_adapter")
```

- [ ] **Step 2: Write failing production dynamic-unit integration tests**

In `test_runtime_main_integration.py`, import RobotAdapter and add:

```python
def live_directory_json(*unit_ids: str) -> str:
    return json.dumps(
        {
            "success": True,
            "message": "ok",
            "data": {"units": [{"unit_id": value} for value in unit_ids]},
        }
    )


@pytest.mark.asyncio
async def test_dynamic_console_unit_routes_all_runtime_tools(monkeypatch) -> None:
    directory = AsyncMock(return_value=live_directory_json("GV_DYNAMIC"))
    goto = AsyncMock(return_value=complete_running_task_json("navigate_to"))
    follow = AsyncMock(return_value=complete_running_task_json("follow_path"))
    stop = AsyncMock(return_value=complete_running_task_json("stop_units"))
    monkeypatch.setattr(RobotAdapter, "list_robots", directory)
    monkeypatch.setattr(ConsoleTaskClient, "navigate_to", goto)
    monkeypatch.setattr(ConsoleTaskClient, "follow_path", follow)
    monkeypatch.setattr(ConsoleTaskClient, "stop_units", stop)
    app = create_app()

    goto_result = await app.call_tool(
        "navigateTo",
        {"unit_id": "gv_dynamic", "target": {"x": 1.0, "y": 2.0}},
    )
    follow_result = await app.call_tool(
        "followPath",
        {"unit_id": "GV_DYNAMIC", "points": [{"x": 1.0, "y": 2.0}]},
    )
    stop_result = await app.call_tool(
        "stopUnits", {"unit_ids": ["gv_dynamic", "GV_DYNAMIC"]}
    )

    assert json.loads(goto_result.content[0].text)["success"] is True
    assert json.loads(follow_result.content[0].text)["success"] is True
    assert json.loads(stop_result.content[0].text)["success"] is True
    goto.assert_awaited_once_with(
        unit_id="GV_DYNAMIC", x=1.0, y=2.0, tolerance_m=0.15, timeout_ms=30000
    )
    follow.assert_awaited_once_with(
        unit_id="GV_DYNAMIC",
        points_json='[{"x": 1.0, "y": 2.0}]',
        tolerance_m=0.15,
        timeout_ms=30000,
    )
    stop.assert_awaited_once_with(unit_ids_csv="GV_DYNAMIC")
    assert directory.await_count == 4


@pytest.mark.asyncio
async def test_unknown_live_unit_remains_complete_unit_not_found(monkeypatch) -> None:
    directory = AsyncMock(return_value=live_directory_json("GV_DYNAMIC"))
    monkeypatch.setattr(RobotAdapter, "list_robots", directory)

    result = await create_app().call_tool(
        "followPath",
        {"unit_id": "GV_MISSING", "points": [{"x": 1.0, "y": 2.0}]},
    )
    payload = json.loads(result.content[0].text)

    assert payload["error_code"] == "UNIT_NOT_FOUND"
    assert payload["data"]["task_type"] == "follow_path"
    assert payload["data"]["state"] == "REJECTED"


@pytest.mark.asyncio
async def test_configured_alias_does_not_query_live_directory(monkeypatch) -> None:
    directory = AsyncMock(return_value=live_directory_json("GV_DYNAMIC"))
    follow = AsyncMock(return_value=complete_running_task_json("follow_path"))
    monkeypatch.setattr(RobotAdapter, "list_robots", directory)
    monkeypatch.setattr(ConsoleTaskClient, "follow_path", follow)

    await create_app().call_tool(
        "followPath",
        {"unit_id": "robot_1", "points": [{"x": 1.0, "y": 2.0}]},
    )

    directory.assert_not_awaited()
    follow.assert_awaited_once()
```

The expected directory count is four: one dynamic lookup for Navigate, one for
FollowPath, and two requested IDs in Stop. Provider calls are patched, so the
legacy adapter does not perform its second live lookup in this test.

- [ ] **Step 3: Run focused tests and verify RED**

```powershell
python -m pytest tests/test_kisorb_plugin.py tests/test_runtime_main_integration.py -q
```

Expected: collection fails because `KisorbLiveUnitResolver` does not exist, or
the new integration tests fail because the plugin has no live resolver.

- [ ] **Step 4: Implement KisorbLiveUnitResolver**

Create `kisorb_sau/unit_resolver.py`:

```python
from __future__ import annotations

import json

from robot_adapter import RobotAdapter
from swarm_runtime.models import UnitDescriptor


class KisorbLiveUnitResolver:
    resolver_id = "kisorb.live"
    priority = 100

    def __init__(self, adapter: RobotAdapter) -> None:
        self._adapter = adapter

    async def resolve(self, unit_id_or_alias: str) -> UnitDescriptor | None:
        requested = unit_id_or_alias.strip().casefold()
        if not requested:
            return None
        try:
            payload = json.loads(await self._adapter.list_robots())
        except (TypeError, json.JSONDecodeError):
            return None
        if not isinstance(payload, dict) or not payload.get("success", False):
            return None
        data = payload.get("data")
        units = data.get("units") if isinstance(data, dict) else None
        if not isinstance(units, list):
            return None
        for item in units:
            if not isinstance(item, dict):
                continue
            candidate = str(item.get("unit_id", "")).strip()
            if candidate and candidate.casefold() == requested:
                return UnitDescriptor(
                    unit_id=candidate,
                    kind="ugv",
                    platform="kisorb-sau",
                    provider_plugin_id="platform.kisorb-sau",
                    metadata={"source": "console-live"},
                )
        return None
```

Do not catch transport exceptions from `list_robots()` here; UnitResolverRegistry
owns exception isolation and logging.

- [ ] **Step 5: Register and declare the resolver**

In `kisorb_sau/plugin.py`, import `KisorbLiveUnitResolver` and register it after
the shared adapter/client services and before providers:

```python
ctx.unit_resolvers.register(KisorbLiveUnitResolver(adapter))
```

Add this exact token to `kisorb_sau/plugin.json` provides:

```json
"unit_resolver:kisorb.live"
```

Retain plugin ID/version, two capability dependencies, three providers, and two
service provisions unchanged.

- [ ] **Step 6: Strengthen boundary audit for the new platform file**

The existing AST audit already scans Runtime Core and all Capability Plugins.
Add a test that the new resolver's concrete RobotAdapter import remains under
the KIS-ORB package:

```python
def test_live_unit_resolver_is_owned_by_kisorb_platform() -> None:
    resolver_path = KISORB_ROOT / "unit_resolver.py"
    runtime_registry_path = RUNTIME_ROOT / "registry" / "unit_resolver.py"

    assert resolver_path.is_file()
    assert "robot_adapter" in imported_modules(resolver_path)
    assert "robot_adapter" not in imported_modules(runtime_registry_path)
```

Do not weaken FORBIDDEN_CORE_IMPORTS or the existing protected IDL hash test.

- [ ] **Step 7: Run focused and complete tests**

From `E:\MCP-IDL\mcp`:

```powershell
python -m pytest tests/test_runtime_unit_resolvers.py tests/test_kisorb_plugin.py tests/test_runtime_main_integration.py tests/test_runtime_boundaries.py -q
python -m pytest tests -q
```

Expected: focused tests pass; full suite has no failures and retains exactly
three existing skips.

- [ ] **Step 8: Verify protected scope and commit**

From `E:\MCP-IDL`:

```powershell
git diff --check
git diff 0119f50 -- mcp/robot_adapter.py mcp/console_client mcp/idl SAU/Console
git status --short --untracked-files=no
```

Expected: diff check is silent; protected legacy transport, IDL, and SAU diff is
empty; tracked status contains only the six intended Task 2 files.

Commit:

```powershell
git add mcp/plugins/platforms/kisorb_sau/unit_resolver.py mcp/plugins/platforms/kisorb_sau/plugin.py mcp/plugins/platforms/kisorb_sau/plugin.json mcp/tests/test_kisorb_plugin.py mcp/tests/test_runtime_main_integration.py mcp/tests/test_runtime_boundaries.py
git diff --cached --name-only
git commit -m "feat: resolve live KIS-ORB units"
```

### Task 3: Final Dynamic-resolution Verification

**Files:**
- Verify: `mcp/swarm_runtime/`
- Verify: `mcp/plugins/platforms/kisorb_sau/`
- Verify: `mcp/tests/`
- Verify: `mcp/idl/mcp_swarm_task.idl`
- Verify: `SAU/Console/`

- [ ] **Step 1: Run syntax and dependency verification**

```powershell
cd E:\MCP-IDL\mcp
python -m compileall -q main.py swarm_runtime plugins
python -c "import fastmcp; assert fastmcp.__version__ == '3.4.2'; print(fastmcp.__version__)"
```

Expected: compileall is silent and version output is `3.4.2`.

- [ ] **Step 2: Run targeted dynamic, plugin, and contract suites**

```powershell
python -m pytest tests/test_runtime_unit_resolvers.py tests/test_runtime_executor.py tests/test_plugin_loader.py tests/test_kisorb_plugin.py tests/test_runtime_main_integration.py tests/test_runtime_boundaries.py -q
```

Expected: all selected tests pass.

- [ ] **Step 3: Run the complete non-live suite**

```powershell
python -m pytest tests -q
```

Expected: every test passes except the same three intentional skips; passing
count is greater than the pre-amendment `283 passed` baseline.

- [ ] **Step 4: Run contract and scope inspection**

```powershell
cd E:\MCP-IDL
git diff --check
git diff 0119f50 -- mcp/robot_adapter.py mcp/console_client mcp/idl SAU/Console
git status --short --untracked-files=no
git log --oneline -8
```

Expected: both diffs are silent, tracked status is clean, and recent commits
contain the Runtime resolver and KIS-ORB resolver changes. Do not create a commit
for verification-only work.

## Final requirement checklist

- [ ] Static UnitRegistry resolution always precedes dynamic I/O.
- [ ] Missing static units fall back asynchronously through UnitResolverRegistry.
- [ ] Resolver IDs are unique, transactional, and provision-checked.
- [ ] Highest priority wins; equal top priority rejects deterministically.
- [ ] Resolver exceptions are logged and treated as abstentions.
- [ ] Dynamic descriptors remain request-scoped and never mutate UnitRegistry.
- [ ] KIS-ORB live resolution uses the shared RobotAdapter's public list route.
- [ ] Direct canonical UnitID matching is trim- and case-insensitive.
- [ ] Navigate, FollowPath, and Stop accept a runtime-bound direct UnitID.
- [ ] Unknown dynamic units remain complete `UNIT_NOT_FOUND` rejected tasks.
- [ ] Configured aliases do not perform live-directory I/O.
- [ ] RobotAdapter, ConsoleTaskClient, public tool schemas, providers, profiles, Mock, SAU, and IDL remain unchanged.
- [ ] The full suite passes with exactly three existing skips.
- [ ] ProjectMemory was not used.
