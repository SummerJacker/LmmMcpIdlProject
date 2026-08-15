# Swarm Harness Path and Stop Plugin Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Route the production `followPath` and `stopUnits` MCP tools through profile-loaded Navigation and Motion Capability Plugins while preserving the fourteen-tool contract and the existing KIS-ORB SAU behavior.

**Architecture:** Reuse the existing SwarmContext, registries, executor, policy pipeline, plugin loader, and FastMCP bridge without changing Runtime Core. Add platform-neutral tool builders, KIS-ORB and Mock providers, then atomically wire manifests, profiles, plugin setup, and `main.py` after the independently tested pieces exist. Eleven production tools remain on the legacy service path.

**Tech Stack:** Python 3.10+, FastMCP 3.4.2, dataclasses, Protocol, JSON manifests/profiles, pytest, pytest-asyncio.

---

## File map

| Path | Responsibility |
| --- | --- |
| `mcp/plugins/capabilities/navigation/tools.py` | Build typed `navigateTo` and `followPath` callables and map runtime errors to task envelopes |
| `mcp/plugins/capabilities/navigation/plugin.py` | Register both versioned Navigation capabilities and tools |
| `mcp/plugins/capabilities/navigation/plugin.json` | Declare Navigation plugin version, capabilities, and tools |
| `mcp/plugins/capabilities/motion/__init__.py` | Export the Motion Capability Plugin |
| `mcp/plugins/capabilities/motion/tools.py` | Build typed `stopUnits` and preserve empty-input failure semantics |
| `mcp/plugins/capabilities/motion/plugin.py` | Register `motion.stop@1.0` and `stopUnits` |
| `mcp/plugins/capabilities/motion/plugin.json` | Declare the Motion plugin and provisions |
| `mcp/plugins/platforms/kisorb_sau/providers.py` | Implement GoTo2D, FollowPath2D, and Stop through ConsoleTaskClient |
| `mcp/plugins/platforms/kisorb_sau/plugin.py` | Register shared services, KIS-ORB units, and all three providers |
| `mcp/plugins/platforms/kisorb_sau/plugin.json` | Declare two capability dependencies and all KIS-ORB provisions |
| `mcp/plugins/platforms/mock_navigation/providers.py` | Return complete in-memory TaskResults for all three capabilities |
| `mcp/plugins/platforms/mock_navigation/plugin.py` | Register MOCK1 and all Mock providers |
| `mcp/plugins/platforms/mock_navigation/plugin.json` | Declare Mock dependencies and provisions |
| `mcp/profiles/default.json` | Enable Navigation, Motion, and KIS-ORB only |
| `mcp/profiles/mock-navigation.json` | Enable Navigation, Motion, KIS-ORB, and Mock |
| `mcp/main.py` | Keep eleven static tools and install three runtime-owned tools |
| `mcp/tests/test_navigation_capability_plugin.py` | Navigation tool schema, request construction, and error mapping |
| `mcp/tests/test_motion_capability_plugin.py` | Motion registration, schema, request, empty input, and errors |
| `mcp/tests/test_kisorb_plugin.py` | Canonical forwarding, path serialization, and Stop de-duplication |
| `mcp/tests/test_mock_navigation_plugin.py` | Same-capability Mock acceptance and mixed-platform rejection |
| `mcp/tests/test_runtime_main_integration.py` | Exact production schemas, routes, and tool-set compatibility |
| `mcp/tests/test_runtime_boundaries.py` | Static import, profile, ownership, and protected-IDL audits |
| `README.md` | Document three runtime tools, eleven legacy tools, and composition limits |

Runtime Core files under `mcp/swarm_runtime/`, files under `mcp/idl/`, and files
under `SAU/Console/` are verification-only and must not be edited.

### Task 1: Add the Platform-neutral FollowPath Tool Builder

**Files:**
- Modify: `mcp/tests/test_navigation_capability_plugin.py`
- Modify: `mcp/plugins/capabilities/navigation/tools.py`

- [ ] **Step 1: Write failing FollowPath tool tests**

Add a provider dedicated to the new capability and a helper that registers the
tool directly. This keeps the production plugin manifest untouched until the
providers and profile are ready:

```python
@dataclass
class CapturingFollowProvider:
    provider_id: str = "test.navigation.follow_path2d"
    capability: str = "navigation.follow_path2d"
    version: str = "1.0"
    priority: int = 100
    request: ExecutionRequest | None = None
    raises: bool = False

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "test"

    async def execute(self, request, units) -> ExecutionResult:
        self.request = request
        if self.raises:
            raise ValueError("do not leak follow failure")
        return ExecutionResult(True, "ok", {"unit_id": units[0].unit_id})


def context_with_follow_provider(provider: CapturingFollowProvider | None = None):
    from plugins.capabilities.navigation.tools import build_follow_path
    from swarm_runtime.models import CapabilitySpec, ToolSpec

    ctx = SwarmContext()
    ctx.capabilities.register(
        CapabilitySpec(
            "navigation.follow_path2d", "1.0",
            "Follow an ordered two-dimensional path", "unit", "followPath",
        )
    )
    ctx.tools.register(ToolSpec("followPath", build_follow_path(ctx)))
    ctx.units.register(
        UnitDescriptor("GV1", "ugv", "test", "platform.test", ("robot_1",))
    )
    selected = provider or CapturingFollowProvider()
    ctx.providers.register(selected)
    return ctx, selected


@pytest.mark.asyncio
async def test_follow_path_preserves_exact_schema() -> None:
    ctx, _ = context_with_follow_provider()
    app = FastMCP("test")
    install_runtime_tools(app, ctx.tools)

    tool = await app.get_tool("followPath")

    assert tool.parameters == {
        "additionalProperties": False,
        "properties": {
            "unit_id": {"type": "string"},
            "points": {
                "items": {
                    "additionalProperties": {"type": "number"},
                    "type": "object",
                },
                "type": "array",
            },
            "tolerance_m": {"default": 0.15, "type": "number"},
            "timeout_ms": {"default": 30000, "type": "integer"},
        },
        "required": ["unit_id", "points"],
        "type": "object",
    }


@pytest.mark.asyncio
async def test_follow_path_builds_versioned_execution_request() -> None:
    ctx, provider = context_with_follow_provider()
    raw = await ctx.tools.get("followPath").callable(
        "robot_1", [{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}], 0.2, 5000
    )

    assert json.loads(raw)["success"] is True
    assert provider.request is not None
    assert provider.request.capability == "navigation.follow_path2d"
    assert provider.request.version == "1.0"
    assert provider.request.unit_ids == ("robot_1",)
    assert provider.request.arguments == {
        "points": [{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}],
        "tolerance_m": 0.2,
        "timeout_ms": 5000,
    }
    assert provider.request.metadata == {"tool_name": "followPath"}
```

Also add one missing-unit assertion:

```python
@pytest.mark.asyncio
async def test_follow_path_missing_unit_returns_complete_rejected_task() -> None:
    ctx, _ = context_with_follow_provider()

    raw = await ctx.tools.get("followPath").callable(
        "missing", [{"x": 0.0, "y": 1.0}]
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "UNIT_NOT_FOUND"
    assert payload["data"]["task_type"] == "follow_path"
    assert payload["data"]["state"] == "REJECTED"
    assert task_payload_has_contract_shape(payload["data"])


@pytest.mark.asyncio
async def test_follow_path_unexpected_failure_is_internal_and_sanitized() -> None:
    ctx, _ = context_with_follow_provider(CapturingFollowProvider(raises=True))

    raw = await ctx.tools.get("followPath").callable(
        "GV1", [{"x": 0.0, "y": 1.0}]
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "INTERNAL_ERROR"
    assert payload["data"]["task_type"] == "follow_path"
    assert payload["data"]["state"] == "FAILED"
    assert "do not leak follow failure" not in payload["message"]
```

- [ ] **Step 2: Run the focused tests and verify RED**

Run from `E:\MCP-IDL\mcp`:

```powershell
python -m pytest tests/test_navigation_capability_plugin.py -q
```

Expected: the new tests fail because `build_follow_path` does not exist.

- [ ] **Step 3: Implement `build_follow_path`**

Add this callable builder to `navigation/tools.py`, using the same stable error
mapping as `navigateTo`:

```python
def build_follow_path(ctx: SwarmContext):
    async def followPath(
        unit_id: str,
        points: list[dict[str, float]],
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        """Execute an ordered x/y task path on one ground unit."""
        request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="navigation.follow_path2d",
            version="1.0",
            unit_ids=(unit_id,),
            arguments={
                "points": points,
                "tolerance_m": tolerance_m,
                "timeout_ms": timeout_ms,
            },
            metadata={"tool_name": "followPath"},
        )
        try:
            return (await ctx.executor.execute(request)).to_json()
        except RuntimeResolutionError as exc:
            return rejected_task_response(
                task_type="follow_path",
                error_code=exc.error_code,
                message=exc.message,
            )
        except RuntimeExecutionError as exc:
            return response(
                success=False,
                message=exc.message,
                error_code=exc.error_code,
                data=empty_task_result(
                    task_type="follow_path",
                    state="FAILED",
                    message=exc.message,
                    error_code=exc.error_code,
                ),
            )

    return followPath
```

- [ ] **Step 4: Run Navigation tests and verify GREEN**

```powershell
python -m pytest tests/test_navigation_capability_plugin.py -q
```

Expected: all Navigation capability tests pass, including the unchanged
`navigateTo` tests.

- [ ] **Step 5: Commit the isolated tool builder**

```powershell
git add mcp/plugins/capabilities/navigation/tools.py mcp/tests/test_navigation_capability_plugin.py
git commit -m "feat: add follow path capability tool"
```

### Task 2: Add the Motion Capability Plugin and Stop Tool

**Files:**
- Create: `mcp/plugins/capabilities/motion/__init__.py`
- Create: `mcp/plugins/capabilities/motion/tools.py`
- Create: `mcp/plugins/capabilities/motion/plugin.py`
- Create: `mcp/plugins/capabilities/motion/plugin.json`
- Create: `mcp/tests/test_motion_capability_plugin.py`

- [ ] **Step 1: Write failing Motion plugin tests**

Create `test_motion_capability_plugin.py` with a capturing provider and these
contract cases:

```python
from __future__ import annotations

import json
from dataclasses import dataclass

import pytest
from fastmcp import FastMCP

from plugins.capabilities.motion.plugin import MotionCapabilityPlugin
from swarm_runtime.context import SwarmContext
from swarm_runtime.fastmcp_bridge import install_runtime_tools
from swarm_runtime.models import ExecutionRequest, ExecutionResult, UnitDescriptor
from task_api.contracts import task_payload_has_contract_shape


@dataclass
class CapturingStopProvider:
    provider_id: str = "test.motion.stop"
    capability: str = "motion.stop"
    version: str = "1.0"
    priority: int = 100
    request: ExecutionRequest | None = None
    raises: bool = False

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return bool(units) and all(unit.platform == "test" for unit in units)

    async def execute(self, request, units) -> ExecutionResult:
        self.request = request
        if self.raises:
            raise ValueError("do not leak stop failure")
        return ExecutionResult(True, "stopped", {"units": [u.unit_id for u in units]})


def context_with_stop_provider(provider: CapturingStopProvider | None = None):
    ctx = SwarmContext()
    MotionCapabilityPlugin().setup(ctx, {})
    ctx.units.register(
        UnitDescriptor("GV1", "ugv", "test", "platform.test", ("robot_1",))
    )
    ctx.units.register(
        UnitDescriptor("GV2", "ugv", "test", "platform.test", ("robot_2",))
    )
    selected = provider or CapturingStopProvider()
    ctx.providers.register(selected)
    return ctx, selected


def test_motion_plugin_registers_stop_capability_and_tool() -> None:
    ctx = SwarmContext()
    MotionCapabilityPlugin().setup(ctx, {})

    spec = ctx.capabilities.get("motion.stop", "1.0")
    assert spec.scope == "multi_unit"
    assert spec.tool_name == "stopUnits"
    assert ctx.tools.get("stopUnits").name == "stopUnits"


@pytest.mark.asyncio
async def test_stop_units_preserves_exact_schema() -> None:
    ctx, _ = context_with_stop_provider()
    app = FastMCP("test")
    install_runtime_tools(app, ctx.tools)

    tool = await app.get_tool("stopUnits")

    assert tool.parameters == {
        "additionalProperties": False,
        "properties": {
            "unit_ids": {"items": {"type": "string"}, "type": "array"}
        },
        "required": ["unit_ids"],
        "type": "object",
    }


@pytest.mark.asyncio
async def test_stop_units_builds_ordered_versioned_request() -> None:
    ctx, provider = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable(["robot_2", "GV1"])

    assert json.loads(raw)["success"] is True
    assert provider.request is not None
    assert provider.request.capability == "motion.stop"
    assert provider.request.version == "1.0"
    assert provider.request.unit_ids == ("robot_2", "GV1")
    assert provider.request.arguments == {}
    assert provider.request.metadata == {"tool_name": "stopUnits"}


@pytest.mark.asyncio
async def test_stop_units_empty_input_preserves_legacy_failure_contract() -> None:
    ctx, _ = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable([])
    payload = json.loads(raw)

    assert payload["message"] == "Validation failed: unit_ids is empty"
    assert payload["error_code"] == "INTERNAL_ERROR"
    assert payload["data"]["task_type"] == "stop_units"
    assert payload["data"]["state"] == "FAILED"
    assert task_payload_has_contract_shape(payload["data"])


@pytest.mark.asyncio
async def test_stop_units_missing_unit_returns_complete_rejected_task() -> None:
    ctx, _ = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable(["missing"])
    payload = json.loads(raw)

    assert payload["error_code"] == "UNIT_NOT_FOUND"
    assert payload["data"]["state"] == "REJECTED"
    assert task_payload_has_contract_shape(payload["data"])


@pytest.mark.asyncio
async def test_stop_units_unexpected_failure_is_internal_and_sanitized() -> None:
    ctx, _ = context_with_stop_provider(CapturingStopProvider(raises=True))

    raw = await ctx.tools.get("stopUnits").callable(["GV1"])
    payload = json.loads(raw)

    assert payload["error_code"] == "INTERNAL_ERROR"
    assert payload["data"]["task_type"] == "stop_units"
    assert payload["data"]["state"] == "FAILED"
    assert "do not leak stop failure" not in payload["message"]
```

- [ ] **Step 2: Run the new test module and verify RED**

```powershell
python -m pytest tests/test_motion_capability_plugin.py -q
```

Expected: collection fails because `plugins.capabilities.motion` does not exist.

- [ ] **Step 3: Implement the Motion plugin files**

Create `motion/tools.py`:

```python
from __future__ import annotations

import uuid

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import RuntimeExecutionError, RuntimeResolutionError
from swarm_runtime.models import ExecutionRequest
from task_api.contracts import empty_task_result, rejected_task_response, response


def build_stop_units(ctx: SwarmContext):
    async def stopUnits(unit_ids: list[str]) -> str:
        """Request Stop without cancelling tasks or disbanding formations."""
        if not unit_ids:
            message = "Validation failed: unit_ids is empty"
            return response(
                success=False,
                message=message,
                error_code="INTERNAL_ERROR",
                data=empty_task_result(
                    task_type="stop_units",
                    state="FAILED",
                    message=message,
                    error_code="INTERNAL_ERROR",
                ),
            )
        request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="motion.stop",
            version="1.0",
            unit_ids=tuple(unit_ids),
            arguments={},
            metadata={"tool_name": "stopUnits"},
        )
        try:
            return (await ctx.executor.execute(request)).to_json()
        except RuntimeResolutionError as exc:
            return rejected_task_response(
                task_type="stop_units",
                error_code=exc.error_code,
                message=exc.message,
            )
        except RuntimeExecutionError as exc:
            return response(
                success=False,
                message=exc.message,
                error_code=exc.error_code,
                data=empty_task_result(
                    task_type="stop_units",
                    state="FAILED",
                    message=exc.message,
                    error_code=exc.error_code,
                ),
            )

    return stopUnits
```

Create `motion/plugin.py`:

```python
from __future__ import annotations

from typing import Any, Mapping

from swarm_runtime.context import SwarmContext
from swarm_runtime.models import CapabilitySpec, ToolSpec

from .tools import build_stop_units


class MotionCapabilityPlugin:
    plugin_id = "capability.motion"
    version = "1.0.0"

    def setup(self, ctx: SwarmContext, config: Mapping[str, Any]) -> None:
        ctx.capabilities.register(
            CapabilitySpec(
                name="motion.stop",
                version="1.0",
                description="Stop one or more mobile units",
                scope="multi_unit",
                tool_name="stopUnits",
            )
        )
        ctx.tools.register(ToolSpec("stopUnits", build_stop_units(ctx)))
```

Create `motion/__init__.py`:

```python
from .plugin import MotionCapabilityPlugin

__all__ = ["MotionCapabilityPlugin"]
```

Create `motion/plugin.json`:

```json
{
  "api_version": 1,
  "id": "capability.motion",
  "version": "1.0.0",
  "type": "capability",
  "entrypoint": "plugins.capabilities.motion.plugin:MotionCapabilityPlugin",
  "requires": [],
  "provides": [
    "capability:motion.stop@1.0",
    "tool:stopUnits"
  ]
}
```

- [ ] **Step 4: Run Motion tests and verify GREEN**

```powershell
python -m pytest tests/test_motion_capability_plugin.py -q
```

Expected: all Motion capability tests pass.

- [ ] **Step 5: Commit the Motion plugin**

```powershell
git add mcp/plugins/capabilities/motion mcp/tests/test_motion_capability_plugin.py
git commit -m "feat: add motion stop capability plugin"
```

### Task 3: Add KIS-ORB FollowPath and Stop Providers

**Files:**
- Modify: `mcp/tests/test_kisorb_plugin.py`
- Modify: `mcp/plugins/platforms/kisorb_sau/providers.py`

- [ ] **Step 1: Write failing direct-provider tests**

Import `KisorbFollowPath2DProvider` and `KisorbStopProvider`, then add:

```python
@pytest.mark.asyncio
async def test_kisorb_follow_provider_serializes_path_and_forwards_arguments() -> None:
    client = AsyncMock()
    client.follow_path.return_value = complete_running_task_json("follow_path")
    provider = KisorbFollowPath2DProvider(client)
    request = ExecutionRequest(
        request_id="follow-1",
        capability="navigation.follow_path2d",
        version="1.0",
        unit_ids=("robot_1",),
        arguments={
            "points": [{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}],
            "tolerance_m": 0.2,
            "timeout_ms": 5000,
        },
    )
    unit = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")

    result = await provider.execute(request, (unit,))

    assert result.success is True
    client.follow_path.assert_awaited_once_with(
        unit_id="GV1",
        points_json='[{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}]',
        tolerance_m=0.2,
        timeout_ms=5000,
    )


@pytest.mark.asyncio
async def test_kisorb_stop_provider_deduplicates_canonical_ids_in_order() -> None:
    client = AsyncMock()
    client.stop_units.return_value = complete_running_task_json("stop_units")
    provider = KisorbStopProvider(client)
    request = ExecutionRequest(
        request_id="stop-1",
        capability="motion.stop",
        version="1.0",
        unit_ids=("robot_2", "GV1", "robot_1"),
        arguments={},
    )
    gv2 = UnitDescriptor("GV2", "ugv", "kisorb-sau", "platform.kisorb-sau")
    gv1 = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")

    result = await provider.execute(request, (gv2, gv1, gv1))

    assert result.success is True
    client.stop_units.assert_awaited_once_with(unit_ids_csv="GV2,GV1")


def test_kisorb_follow_and_stop_support_only_owned_unit_tuples() -> None:
    follow = KisorbFollowPath2DProvider(AsyncMock())
    stop = KisorbStopProvider(AsyncMock())
    kisorb = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")
    mock = UnitDescriptor("MOCK1", "ugv", "mock-navigation", "platform.mock")

    assert follow.supports((kisorb,)) is True
    assert follow.supports((kisorb, kisorb)) is False
    assert stop.supports((kisorb, kisorb)) is True
    assert stop.supports(()) is False
    assert stop.supports((kisorb, mock)) is False
```

Change the existing task fixture to accept a task type:

```python
def complete_running_task_json(task_type: str = "navigate_to") -> str:
    return json.dumps(
        {
            "success": True,
            "message": "task accepted",
            "data": {
                "success": True,
                "task_id": "task-1",
                "task_type": task_type,
                "state": "RUNNING",
                "progress_pct": 0.0,
                "message": "task accepted",
                "error_code": "",
                "unit_results": [],
                "elapsed_ms": 0,
                "started_at_ms": 1,
                "cancellation_effect": "NOT_APPLICABLE",
            },
        }
    )
```

- [ ] **Step 2: Run KIS-ORB tests and verify RED**

```powershell
python -m pytest tests/test_kisorb_plugin.py -q
```

Expected: import fails for the two provider classes.

- [ ] **Step 3: Implement the two KIS-ORB providers**

Add `import json` and these classes to `kisorb_sau/providers.py`:

```python
class KisorbFollowPath2DProvider:
    provider_id = "kisorb.navigation.follow_path2d"
    capability = "navigation.follow_path2d"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "kisorb-sau"

    async def execute(self, request, units) -> ExecutionResult:
        raw = await self._client.follow_path(
            unit_id=units[0].unit_id,
            points_json=json.dumps(request.arguments["points"], ensure_ascii=False),
            tolerance_m=request.arguments["tolerance_m"],
            timeout_ms=request.arguments["timeout_ms"],
        )
        return ExecutionResult.from_json(raw)


class KisorbStopProvider:
    provider_id = "kisorb.motion.stop"
    capability = "motion.stop"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return bool(units) and all(unit.platform == "kisorb-sau" for unit in units)

    async def execute(self, request, units) -> ExecutionResult:
        canonical_ids = list(dict.fromkeys(unit.unit_id for unit in units))
        raw = await self._client.stop_units(unit_ids_csv=",".join(canonical_ids))
        return ExecutionResult.from_json(raw)
```

- [ ] **Step 4: Run KIS-ORB tests and verify GREEN**

```powershell
python -m pytest tests/test_kisorb_plugin.py -q
```

Expected: all direct and existing GoTo2D provider tests pass.

- [ ] **Step 5: Commit the provider implementations**

```powershell
git add mcp/plugins/platforms/kisorb_sau/providers.py mcp/tests/test_kisorb_plugin.py
git commit -m "feat: add KIS-ORB path and stop providers"
```

### Task 4: Add Mock FollowPath and Stop Providers

**Files:**
- Modify: `mcp/tests/test_mock_navigation_plugin.py`
- Modify: `mcp/plugins/platforms/mock_navigation/providers.py`

- [ ] **Step 1: Write failing direct Mock-provider tests**

Import the new providers and add:

Extend `CORE_FILES` so the execution-time mutation check covers both capability
packages:

```python
CORE_FILES = (
    MCP_ROOT / "swarm_runtime" / "executor.py",
    MCP_ROOT / "swarm_runtime" / "registry" / "capability.py",
    MCP_ROOT / "swarm_runtime" / "registry" / "provider.py",
    MCP_ROOT / "swarm_runtime" / "registry" / "unit.py",
    MCP_ROOT / "plugins" / "capabilities" / "navigation" / "plugin.py",
    MCP_ROOT / "plugins" / "capabilities" / "navigation" / "tools.py",
    MCP_ROOT / "plugins" / "capabilities" / "motion" / "plugin.py",
    MCP_ROOT / "plugins" / "capabilities" / "motion" / "tools.py",
)
```

```python
@pytest.mark.asyncio
async def test_mock_follow_provider_returns_complete_follow_path_task() -> None:
    provider = MockFollowPath2DProvider()
    unit = UnitDescriptor("MOCK1", "ugv", "mock-navigation", "platform.mock")
    request = ExecutionRequest(
        request_id="mock-follow",
        capability="navigation.follow_path2d",
        version="1.0",
        unit_ids=("MOCK1",),
        arguments={
            "points": [{"x": 1.0, "y": 2.0}],
            "tolerance_m": 0.15,
            "timeout_ms": 30000,
        },
    )

    result = await provider.execute(request, (unit,))

    assert result.success is True
    assert result.data["task_type"] == "follow_path"
    assert result.data["state"] == "COMPLETED"
    assert result.data["unit_results"][0]["target"] == {
        "points": [{"x": 1.0, "y": 2.0}]
    }
    assert task_payload_has_contract_shape(result.data)


@pytest.mark.asyncio
async def test_mock_stop_provider_returns_one_result_per_canonical_unit() -> None:
    provider = MockStopProvider()
    mock1 = UnitDescriptor("MOCK1", "ugv", "mock-navigation", "platform.mock")
    request = ExecutionRequest(
        request_id="mock-stop",
        capability="motion.stop",
        version="1.0",
        unit_ids=("mock_robot", "MOCK1"),
        arguments={},
    )

    result = await provider.execute(request, (mock1, mock1))

    assert result.success is True
    assert result.data["task_type"] == "stop_units"
    assert [item["unit_id"] for item in result.data["unit_results"]] == ["MOCK1"]
    assert task_payload_has_contract_shape(result.data)


def test_mock_stop_rejects_mixed_platform_tuple() -> None:
    provider = MockStopProvider()
    mock = UnitDescriptor("MOCK1", "ugv", "mock-navigation", "platform.mock")
    kisorb = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")

    assert provider.supports((mock,)) is True
    assert provider.supports(()) is False
    assert provider.supports((mock, kisorb)) is False
```

Add `UnitDescriptor` to the imports.

- [ ] **Step 2: Run Mock tests and verify RED**

```powershell
python -m pytest tests/test_mock_navigation_plugin.py -q
```

Expected: import fails for `MockFollowPath2DProvider` and `MockStopProvider`.

- [ ] **Step 3: Implement reusable Mock TaskResult construction and providers**

Refactor `mock_navigation/providers.py` around this helper, retaining the
existing GoTo2D fields:

```python
def _completed_result(
    request: ExecutionRequest,
    units: tuple[UnitDescriptor, ...],
    *,
    task_type: str,
    message: str,
    target: dict | None = None,
) -> ExecutionResult:
    canonical_units = list(dict.fromkeys(unit.unit_id for unit in units))
    unit_results = []
    for unit_id in canonical_units:
        item = {
            "unit_id": unit_id,
            "state": "COMPLETED",
            "message": message,
            "error_code": "",
        }
        if target is not None:
            item["target"] = target
        unit_results.append(item)
    data = {
        "success": True,
        "task_id": f"mock-{request.request_id}",
        "task_type": task_type,
        "state": "COMPLETED",
        "progress_pct": 100.0,
        "message": message,
        "error_code": "",
        "unit_results": unit_results,
        "elapsed_ms": 0,
        "started_at_ms": int(time.time() * 1000),
        "cancellation_effect": "NOT_APPLICABLE",
    }
    return ExecutionResult(True, message, data)
```

Implement the providers:

```python
class MockFollowPath2DProvider:
    provider_id = "mock.navigation.follow_path2d"
    capability = "navigation.follow_path2d"
    version = "1.0"
    priority = 100

    def supports(self, units):
        return len(units) == 1 and units[0].platform == "mock-navigation"

    async def execute(self, request, units):
        return _completed_result(
            request,
            units,
            task_type="follow_path",
            message="mock path completed",
            target={"points": request.arguments["points"]},
        )


class MockStopProvider:
    provider_id = "mock.motion.stop"
    capability = "motion.stop"
    version = "1.0"
    priority = 100

    def supports(self, units):
        return bool(units) and all(
            unit.platform == "mock-navigation" for unit in units
        )

    async def execute(self, request, units):
        return _completed_result(
            request,
            units,
            task_type="stop_units",
            message="mock units stopped",
        )
```

Replace the existing GoTo2D class with the helper-backed version:

```python
class MockGoto2DProvider:
    provider_id = "mock.navigation.goto2d"
    capability = "navigation.goto2d"
    version = "1.0"
    priority = 100

    def supports(self, units):
        return len(units) == 1 and units[0].platform == "mock-navigation"

    async def execute(self, request, units):
        return _completed_result(
            request,
            units,
            task_type="navigate_to",
            message="mock navigation completed",
            target={
                "x": request.arguments["x"],
                "y": request.arguments["y"],
            },
        )
```

- [ ] **Step 4: Run Mock tests and verify GREEN**

```powershell
python -m pytest tests/test_mock_navigation_plugin.py -q
```

Expected: all Mock provider tests and the existing GoTo2D acceptance test pass.

- [ ] **Step 5: Commit the Mock provider implementations**

```powershell
git add mcp/plugins/platforms/mock_navigation/providers.py mcp/tests/test_mock_navigation_plugin.py
git commit -m "feat: add mock path and stop providers"
```

### Task 5: Wire Plugins, Manifests, Profiles, and Production Tools

**Files:**
- Modify: `mcp/tests/test_navigation_capability_plugin.py`
- Modify: `mcp/tests/test_kisorb_plugin.py`
- Modify: `mcp/tests/test_mock_navigation_plugin.py`
- Modify: `mcp/tests/test_runtime_main_integration.py`
- Modify: `mcp/plugins/capabilities/navigation/plugin.py`
- Modify: `mcp/plugins/capabilities/navigation/plugin.json`
- Modify: `mcp/plugins/platforms/kisorb_sau/plugin.py`
- Modify: `mcp/plugins/platforms/kisorb_sau/plugin.json`
- Modify: `mcp/plugins/platforms/mock_navigation/plugin.py`
- Modify: `mcp/plugins/platforms/mock_navigation/plugin.json`
- Modify: `mcp/profiles/default.json`
- Modify: `mcp/profiles/mock-navigation.json`
- Modify: `mcp/main.py`

- [ ] **Step 1: Write failing end-to-end wiring tests**

In `test_runtime_main_integration.py`, add exact schema constants captured from
the pre-migration server:

```python
EXPECTED_FOLLOW_PATH_SCHEMA = {
    "additionalProperties": False,
    "properties": {
        "unit_id": {"type": "string"},
        "points": {
            "items": {
                "additionalProperties": {"type": "number"},
                "type": "object",
            },
            "type": "array",
        },
        "tolerance_m": {"default": 0.15, "type": "number"},
        "timeout_ms": {"default": 30000, "type": "integer"},
    },
    "required": ["unit_id", "points"],
    "type": "object",
}

EXPECTED_STOP_UNITS_SCHEMA = {
    "additionalProperties": False,
    "properties": {
        "unit_ids": {"items": {"type": "string"}, "type": "array"}
    },
    "required": ["unit_ids"],
    "type": "object",
}
```

Add production route tests:

```python
@pytest.mark.asyncio
async def test_runtime_path_and_stop_preserve_exact_fastmcp_schemas() -> None:
    app = create_app()

    assert (await app.get_tool("followPath")).parameters == EXPECTED_FOLLOW_PATH_SCHEMA
    assert (await app.get_tool("stopUnits")).parameters == EXPECTED_STOP_UNITS_SCHEMA


@pytest.mark.asyncio
async def test_production_follow_path_routes_through_kisorb_provider(monkeypatch) -> None:
    call = AsyncMock(return_value=complete_running_task_json("follow_path"))
    monkeypatch.setattr(ConsoleTaskClient, "follow_path", call)

    result = await create_app().call_tool(
        "followPath",
        {
            "unit_id": "robot_1",
            "points": [{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}],
            "tolerance_m": 0.2,
            "timeout_ms": 5000,
        },
    )

    assert json.loads(result.content[0].text)["success"] is True
    call.assert_awaited_once_with(
        unit_id="GV1",
        points_json='[{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}]',
        tolerance_m=0.2,
        timeout_ms=5000,
    )


@pytest.mark.asyncio
async def test_production_stop_routes_and_deduplicates_canonical_units(monkeypatch) -> None:
    call = AsyncMock(return_value=complete_running_task_json("stop_units"))
    monkeypatch.setattr(ConsoleTaskClient, "stop_units", call)

    result = await create_app().call_tool(
        "stopUnits", {"unit_ids": ["robot_2", "GV1", "robot_1"]}
    )

    assert json.loads(result.content[0].text)["success"] is True
    call.assert_awaited_once_with(unit_ids_csv="GV2,GV1")


@pytest.mark.asyncio
async def test_default_app_has_three_runtime_tools_and_fourteen_total() -> None:
    from main import create_runtime

    ctx = create_runtime()
    assert {tool.name for tool in ctx.tools.list()} == {
        "navigateTo", "followPath", "stopUnits"
    }
    assert {tool.name for tool in await create_app().list_tools()} == PRODUCTION_TOOL_NAMES
```

Replace `complete_running_task_json` in this test with:

```python
def complete_running_task_json(task_type: str = "navigate_to") -> str:
    return json.dumps(
        {
            "success": True,
            "message": "task accepted",
            "data": {
                "success": True,
                "task_id": "task-1",
                "task_type": task_type,
                "state": "RUNNING",
                "progress_pct": 0.0,
                "message": "task accepted",
                "error_code": "",
                "unit_results": [],
                "elapsed_ms": 0,
                "started_at_ms": 1,
                "cancellation_effect": "NOT_APPLICABLE",
            },
        }
    )
```

Add these Mock integration assertions:

```python
@pytest.mark.asyncio
async def test_mock_profile_routes_follow_path_and_stop_without_core_changes() -> None:
    app = create_app(PROFILES / "mock-navigation.json")

    follow = await app.call_tool(
        "followPath", {"unit_id": "MOCK1", "points": [{"x": 1.0, "y": 2.0}]}
    )
    stop = await app.call_tool("stopUnits", {"unit_ids": ["mock_robot", "MOCK1"]})

    assert json.loads(follow.content[0].text)["data"]["task_type"] == "follow_path"
    assert json.loads(stop.content[0].text)["data"]["task_type"] == "stop_units"


@pytest.mark.asyncio
async def test_mock_profile_rejects_mixed_platform_stop() -> None:
    result = await create_app(PROFILES / "mock-navigation.json").call_tool(
        "stopUnits", {"unit_ids": ["GV1", "MOCK1"]}
    )
    payload = json.loads(result.content[0].text)

    assert payload["error_code"] == "UNSUPPORTED_CAPABILITY"
    assert payload["data"]["state"] == "REJECTED"
```

Replace the KIS-ORB profile-order assertion with:

```python
assert loader.loaded_plugin_ids == (
    "capability.navigation",
    "capability.motion",
    "platform.kisorb-sau",
)
```

Replace the Mock profile-order assertion with:

```python
assert loader.loaded_plugin_ids == (
    "capability.navigation",
    "capability.motion",
    "platform.kisorb-sau",
    "platform.mock-navigation",
)
```

- [ ] **Step 2: Run focused integration tests and verify RED**

```powershell
python -m pytest tests/test_runtime_main_integration.py tests/test_kisorb_plugin.py tests/test_mock_navigation_plugin.py -q
```

Expected: runtime tools are not registered, profiles do not enable Motion, and
the static Main callables still own `followPath` and `stopUnits`.

- [ ] **Step 3: Register the new Navigation capability and tool**

In `navigation/plugin.py`, set `version = "1.1.0"`, import
`build_follow_path`, and add:

```python
ctx.capabilities.register(
    CapabilitySpec(
        name="navigation.follow_path2d",
        version="1.0",
        description="Follow an ordered two-dimensional path",
        scope="unit",
        tool_name="followPath",
    )
)
ctx.tools.register(ToolSpec("followPath", build_follow_path(ctx)))
```

Replace `navigation/plugin.json` with:

```json
{
  "api_version": 1,
  "id": "capability.navigation",
  "version": "1.1.0",
  "type": "capability",
  "entrypoint": "plugins.capabilities.navigation.plugin:NavigationCapabilityPlugin",
  "requires": [],
  "provides": [
    "capability:navigation.goto2d@1.0",
    "capability:navigation.follow_path2d@1.0",
    "tool:navigateTo",
    "tool:followPath"
  ]
}
```

- [ ] **Step 4: Register providers and update platform manifests**

In `kisorb_sau/plugin.py`, import both new provider classes, set
`version = "1.1.0"`, and register all three against the one shared client:

```python
ctx.providers.register(KisorbGoto2DProvider(client))
ctx.providers.register(KisorbFollowPath2DProvider(client))
ctx.providers.register(KisorbStopProvider(client))
```

Replace its manifest with:

```json
{
  "api_version": 1,
  "id": "platform.kisorb-sau",
  "version": "1.1.0",
  "type": "platform",
  "entrypoint": "plugins.platforms.kisorb_sau.plugin:KisorbPlugin",
  "requires": ["capability.navigation", "capability.motion"],
  "provides": [
    "provider:kisorb.navigation.goto2d",
    "provider:kisorb.navigation.follow_path2d",
    "provider:kisorb.motion.stop",
    "service:legacy.robot_adapter",
    "service:legacy.console_task_client"
  ]
}
```

In `mock_navigation/plugin.py`, set `version = "1.1.0"` and register
`MockGoto2DProvider`, `MockFollowPath2DProvider`, and `MockStopProvider`. Replace
its manifest with:

```json
{
  "api_version": 1,
  "id": "platform.mock-navigation",
  "version": "1.1.0",
  "type": "platform",
  "entrypoint": "plugins.platforms.mock_navigation.plugin:MockNavigationPlugin",
  "requires": ["capability.navigation", "capability.motion"],
  "provides": [
    "provider:mock.navigation.goto2d",
    "provider:mock.navigation.follow_path2d",
    "provider:mock.motion.stop",
    "unit:MOCK1"
  ]
}
```

- [ ] **Step 5: Enable Motion in both profiles**

Set the production order to:

```json
{
  "profile_api_version": 1,
  "plugins": [
    {"id": "capability.navigation", "enabled": true, "config": {}},
    {"id": "capability.motion", "enabled": true, "config": {}},
    {"id": "platform.kisorb-sau", "enabled": true, "config": {}}
  ]
}
```

Set the Mock order to the same first three entries followed by:

```json
{"id": "platform.mock-navigation", "enabled": true, "config": {}}
```

- [ ] **Step 6: Remove only the two static Main tool definitions**

Delete the decorated `followPath` and `stopUnits` functions from `create_app()`.
Do not remove `json`, `TaskService`, or the shared `tasks` object because the
remaining formation and task-lifecycle tools still use them. Leave
`install_runtime_tools(mcp, ctx.tools)` in its current position.

- [ ] **Step 7: Run focused tests and verify GREEN**

```powershell
python -m pytest tests/test_navigation_capability_plugin.py tests/test_motion_capability_plugin.py tests/test_kisorb_plugin.py tests/test_mock_navigation_plugin.py tests/test_runtime_main_integration.py tests/test_task_architecture.py -q
```

Expected: all selected tests pass; the tool set remains fourteen names and the
runtime registry contains exactly three tools.

- [ ] **Step 8: Commit the atomic production wiring**

```powershell
git add mcp/main.py mcp/plugins/capabilities/navigation/plugin.py mcp/plugins/capabilities/navigation/plugin.json mcp/plugins/platforms/kisorb_sau/plugin.py mcp/plugins/platforms/kisorb_sau/plugin.json mcp/plugins/platforms/mock_navigation/plugin.py mcp/plugins/platforms/mock_navigation/plugin.json mcp/profiles/default.json mcp/profiles/mock-navigation.json mcp/tests
git commit -m "feat: route path and stop through swarm runtime"
```

Before committing, run `git diff --cached --name-only` and verify no unrelated,
previously untracked project file is staged.

### Task 6: Strengthen Boundaries, Update Documentation, and Verify

**Files:**
- Modify: `mcp/tests/test_runtime_boundaries.py`
- Modify: `README.md`
- Verify only: `mcp/swarm_runtime/`
- Verify only: `mcp/idl/mcp_swarm_task.idl`
- Verify only: `SAU/Console/`

- [ ] **Step 1: Add failing static ownership/profile assertions**

Add `MAIN_PATH = MCP_ROOT / "main.py"`, then add:

```python
def top_level_nested_function_names(path: Path, parent_name: str) -> set[str]:
    tree = ast.parse(path.read_text(encoding="utf-8"), filename=str(path))
    for node in tree.body:
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)) and node.name == parent_name:
            return {
                child.name
                for child in node.body
                if isinstance(child, (ast.FunctionDef, ast.AsyncFunctionDef))
            }
    raise AssertionError(f"function not found: {parent_name}")


def test_path_and_stop_are_not_static_main_tools() -> None:
    names = top_level_nested_function_names(MAIN_PATH, "create_app")

    assert "followPath" not in names
    assert "stopUnits" not in names


def test_profiles_enable_motion_but_only_mock_profile_enables_mock_platform() -> None:
    def enabled(name: str) -> set[str]:
        profile = json.loads((MCP_ROOT / "profiles" / name).read_text(encoding="utf-8"))
        return {item["id"] for item in profile["plugins"] if item.get("enabled", True)}

    default = enabled("default.json")
    mock = enabled("mock-navigation.json")
    assert "capability.motion" in default
    assert "capability.motion" in mock
    assert "platform.mock-navigation" not in default
    assert "platform.mock-navigation" in mock
```

Extend the existing import audit implicitly by keeping the whole
`CAPABILITY_ROOT` scan; the new Motion package must pass without a whitelist
change.

- [ ] **Step 2: Run the boundary audit**

```powershell
python -m pytest tests/test_runtime_boundaries.py -q
```

Expected: all assertions pass after Task 5. If an import boundary fails, move
the concrete dependency into the owning platform package; do not weaken
`FORBIDDEN_CORE_IMPORTS`.

- [ ] **Step 3: Update README with exact migration status**

Replace statements describing one runtime tool and thirteen legacy tools with:

```markdown
The profile-loaded Swarm Runtime now owns three typed production tools:
`navigateTo`, `followPath`, and `stopUnits`. They resolve versioned capabilities,
canonical units, policies, and platform providers before execution. The other
eleven production tools continue through the shared legacy TaskService seam.

`profiles/default.json` enables Navigation, Motion, and the KIS-ORB SAU platform.
`profiles/mock-navigation.json` additionally enables the in-memory Mock platform
for architectural acceptance tests; it is not part of production discovery.

A multi-unit request must currently be supported by one provider. Therefore a
mixed KIS-ORB/Mock `stopUnits` request is rejected deterministically; cross-
platform fan-out and aggregate result composition remain a later phase.
```

Retain the existing statements that SAU Console and IDLs are unchanged. Do not
claim that task lifecycle, formations, safety policies, or all tools are
pluginized.

- [ ] **Step 4: Run syntax, focused contract, and complete regression checks**

From `E:\MCP-IDL\mcp`:

```powershell
python -m compileall -q main.py swarm_runtime plugins
python -c "import fastmcp; assert fastmcp.__version__ == '3.4.2'; print(fastmcp.__version__)"
python -m pytest tests/test_runtime_boundaries.py tests/test_runtime_main_integration.py -q
python -m pytest tests -q
```

Expected: compileall is silent, FastMCP prints `3.4.2`, focused tests pass, the
full suite has no failures, at least the previous 254 tests still pass, and the
skip count remains 3.

- [ ] **Step 5: Verify protected scope and diff hygiene**

From `E:\MCP-IDL`:

```powershell
git diff --check
git diff 1726bac -- mcp/swarm_runtime mcp/idl SAU/Console
git status --short --untracked-files=no
```

Expected: `git diff --check` is silent; the protected-path diff is empty; tracked
status contains only the intended README and boundary-test changes before the
final commit. Existing untracked repository content remains untouched.

- [ ] **Step 6: Commit documentation and boundary tests**

```powershell
git add README.md mcp/tests/test_runtime_boundaries.py
git diff --cached --name-only
git commit -m "docs: describe path and stop plugin slice"
```

Expected: exactly README and the boundary test are staged for this commit.

- [ ] **Step 7: Perform a fresh post-commit verification**

```powershell
cd E:\MCP-IDL\mcp
python -m compileall -q main.py swarm_runtime plugins
python -m pytest tests -q
cd E:\MCP-IDL
git diff --check
git status --short --untracked-files=no
git log --oneline -8
```

Expected: syntax is clean, the full suite passes with three skips, tracked status
is clean, and the recent log contains the focused TDD commits from this plan.

## Final requirement checklist

- [ ] `followPath` is owned by `capability.navigation`, not by a platform plugin.
- [ ] `stopUnits` is owned by `capability.motion` and remains distinct from cancellation.
- [ ] Exact FastMCP schemas and default values are unchanged.
- [ ] Runtime canonicalizes aliases before provider execution.
- [ ] KIS-ORB path serialization and Stop ordering match the legacy calls.
- [ ] Stop removes duplicate canonical IDs while preserving first occurrence.
- [ ] Empty Stop input retains its complete legacy failure envelope.
- [ ] Mock executes both new capabilities without Runtime Core changes.
- [ ] Mixed-platform Stop is rejected as `UNSUPPORTED_CAPABILITY`.
- [ ] The default profile contains no Mock platform.
- [ ] Three runtime tools plus eleven legacy tools equal the same fourteen tools.
- [ ] Runtime Core, SAU Console, and IDL files are unchanged.
- [ ] FastMCP remains pinned to 3.4.2.
- [ ] The full non-live suite passes with exactly three existing skips.
- [ ] ProjectMemory was not used.
