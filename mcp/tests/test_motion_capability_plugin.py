from __future__ import annotations

import json
import uuid
from dataclasses import dataclass
from pathlib import Path

import pytest
from fastmcp import FastMCP

from plugins.capabilities.motion.plugin import MotionCapabilityPlugin
from swarm_runtime.context import SwarmContext
from swarm_runtime.fastmcp_bridge import install_runtime_tools
from swarm_runtime.models import (
    CapabilitySpec,
    ExecutionRequest,
    ExecutionResult,
    UnitDescriptor,
)
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
        return ExecutionResult(
            True,
            "stopped",
            {"units": [unit.unit_id for unit in units]},
        )


def context_with_stop_provider(
    provider: CapturingStopProvider | None = None,
) -> tuple[SwarmContext, CapturingStopProvider]:
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


def test_motion_plugin_registers_capability_and_tool() -> None:
    ctx = SwarmContext()

    MotionCapabilityPlugin().setup(ctx, {})

    assert ctx.capabilities.get("motion.stop", "1.0") == CapabilitySpec(
        name="motion.stop",
        version="1.0",
        description="Stop one or more mobile units",
        scope="multi_unit",
        tool_name="stopUnits",
    )
    assert ctx.tools.get("stopUnits").name == "stopUnits"
    assert ctx.tools.get("stopUnits").callable.__name__ == "stopUnits"


@pytest.mark.asyncio
async def test_stop_units_preserves_exact_fastmcp_contract() -> None:
    ctx, _ = context_with_stop_provider()
    app = FastMCP("test")
    install_runtime_tools(app, ctx.tools)

    tool = await app.get_tool("stopUnits")

    assert tool.description == (
        "Request Unit_MA_Stop without cancelling tasks or disbanding formations."
    )
    assert tool.parameters == {
        "additionalProperties": False,
        "properties": {
            "unit_ids": {
                "items": {"type": "string"},
                "type": "array",
            }
        },
        "required": ["unit_ids"],
        "type": "object",
    }


@pytest.mark.asyncio
async def test_stop_units_builds_versioned_multi_unit_request_in_requested_order() -> None:
    ctx, provider = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable(["robot_2", "GV1"])
    payload = json.loads(raw)

    assert payload == {
        "success": True,
        "message": "stopped",
        "data": {"units": ["GV2", "GV1"]},
    }
    assert provider.request is not None
    assert str(uuid.UUID(provider.request.request_id)) == provider.request.request_id
    assert provider.request.capability == "motion.stop"
    assert provider.request.version == "1.0"
    assert provider.request.unit_ids == ("robot_2", "GV1")
    assert provider.request.arguments == {}
    assert provider.request.metadata == {"tool_name": "stopUnits"}


@pytest.mark.asyncio
async def test_stop_units_trims_ids_and_discards_blanks_in_requested_order() -> None:
    ctx, provider = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable(
        ["  robot_2  ", "", " \t ", " GV1 "]
    )
    payload = json.loads(raw)

    assert payload == {
        "success": True,
        "message": "stopped",
        "data": {"units": ["GV2", "GV1"]},
    }
    assert provider.request is not None
    assert provider.request.unit_ids == ("robot_2", "GV1")


@pytest.mark.asyncio
async def test_stop_units_empty_list_returns_complete_failed_task() -> None:
    ctx, provider = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable([])
    payload = json.loads(raw)

    assert payload["success"] is False
    assert payload["message"] == "Validation failed: unit_ids is empty"
    assert payload["error_code"] == "INTERNAL_ERROR"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["task_type"] == "stop_units"
    assert payload["data"]["state"] == "FAILED"
    assert payload["data"]["error_code"] == "INTERNAL_ERROR"
    assert provider.request is None


@pytest.mark.asyncio
async def test_stop_units_all_blank_ids_return_legacy_empty_failure() -> None:
    ctx, provider = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable(["", "  ", "\t"])
    payload = json.loads(raw)

    assert payload["success"] is False
    assert payload["message"] == "Validation failed: unit_ids is empty"
    assert payload["error_code"] == "INTERNAL_ERROR"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["task_type"] == "stop_units"
    assert payload["data"]["state"] == "FAILED"
    assert payload["data"]["message"] == "Validation failed: unit_ids is empty"
    assert payload["data"]["error_code"] == "INTERNAL_ERROR"
    assert provider.request is None


@pytest.mark.asyncio
async def test_stop_units_missing_unit_returns_complete_rejected_task() -> None:
    ctx, _ = context_with_stop_provider()

    raw = await ctx.tools.get("stopUnits").callable(["missing"])
    payload = json.loads(raw)

    assert payload["success"] is False
    assert payload["error_code"] == "UNIT_NOT_FOUND"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["task_type"] == "stop_units"
    assert payload["data"]["state"] == "REJECTED"
    assert payload["data"]["error_code"] == "UNIT_NOT_FOUND"


@pytest.mark.asyncio
async def test_stop_units_unexpected_provider_error_is_sanitized() -> None:
    ctx, _ = context_with_stop_provider(CapturingStopProvider(raises=True))

    raw = await ctx.tools.get("stopUnits").callable(["robot_1", "GV2"])
    payload = json.loads(raw)

    assert payload["success"] is False
    assert payload["error_code"] == "INTERNAL_ERROR"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["task_type"] == "stop_units"
    assert payload["data"]["state"] == "FAILED"
    assert payload["data"]["error_code"] == "INTERNAL_ERROR"
    assert "do not leak stop failure" not in raw


def test_motion_plugin_manifest_is_exact() -> None:
    manifest_path = (
        Path(__file__).parents[1]
        / "plugins"
        / "capabilities"
        / "motion"
        / "plugin.json"
    )

    assert json.loads(manifest_path.read_text(encoding="utf-8")) == {
        "api_version": 1,
        "id": "capability.motion",
        "version": "1.1.0",
        "type": "capability",
        "entrypoint": "plugins.capabilities.motion.plugin:MotionCapabilityPlugin",
        "requires": [],
        "provides": [
            "capability:motion.execute@1.0",
            "capability:motion.stop@1.0",
            "tool:executeMotion",
            "tool:stopUnits",
        ],
    }
