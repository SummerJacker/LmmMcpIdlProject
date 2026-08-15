from __future__ import annotations

from dataclasses import dataclass

import pytest

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import (
    AmbiguousProviderError,
    DuplicateRegistrationError,
    PolicyRejectedError,
    ProviderNotFoundError,
    RuntimeExecutionError,
)
from swarm_runtime.models import (
    CapabilitySpec,
    ExecutionRequest,
    ExecutionResult,
    PolicyDecision,
    PolicyOutcome,
    ToolSpec,
    UnitDescriptor,
)


def request_for(unit_id: str, *, version: str = "1.0") -> ExecutionRequest:
    return ExecutionRequest(
        request_id="req-1",
        capability="navigation.goto2d",
        version=version,
        unit_ids=(unit_id,),
        arguments={"x": 1.0, "y": 2.0},
    )


@dataclass
class FakeProvider:
    provider_id: str
    priority: int
    platform: str
    capability: str = "navigation.goto2d"
    version: str = "1.0"
    raises: bool = False

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == self.platform

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        if self.raises:
            raise ValueError("provider secret")
        return ExecutionResult(True, "ok", {"provider": self.provider_id})


class RecordingPolicy:
    def __init__(
        self,
        policy_id: str,
        priority: int,
        decision: PolicyDecision,
    ) -> None:
        self.policy_id = policy_id
        self.priority = priority
        self.decision = decision
        self.called = False

    def applies_to(self, request: ExecutionRequest) -> bool:
        return request.capability == "navigation.goto2d"

    async def evaluate(self, request, units, provider) -> PolicyOutcome:
        self.called = True
        return PolicyOutcome(self.decision, f"{self.policy_id} decision")


class RaisingPolicy(RecordingPolicy):
    async def evaluate(self, request, units, provider) -> PolicyOutcome:
        self.called = True
        raise ValueError("policy failed")


def populated_context(*, provider: bool = False) -> SwarmContext:
    ctx = SwarmContext()
    ctx.capabilities.register(
        CapabilitySpec("navigation.goto2d", "1.0", "nav", "unit")
    )
    ctx.units.register(
        UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")
    )
    if provider:
        ctx.providers.register(FakeProvider("only", 100, "kisorb-sau"))
    return ctx


@pytest.mark.asyncio
async def test_executor_selects_highest_priority_supporting_provider() -> None:
    ctx = populated_context()
    ctx.providers.register(FakeProvider("low", priority=10, platform="kisorb-sau"))
    ctx.providers.register(FakeProvider("high", priority=100, platform="kisorb-sau"))

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
    ctx.policies.register(RaisingPolicy("broken", 100, PolicyDecision.ABSTAIN))

    with pytest.raises(PolicyRejectedError) as error:
        await ctx.executor.execute(request_for("GV1"))

    assert error.value.error_code == "SAFETY_REJECTED"


@pytest.mark.asyncio
async def test_provider_resolution_requires_exact_capability_version() -> None:
    ctx = populated_context(provider=True)

    with pytest.raises(ProviderNotFoundError):
        await ctx.executor.execute(request_for("GV1", version="2.0"))


@pytest.mark.asyncio
async def test_provider_resolution_filters_unsupported_platform() -> None:
    ctx = populated_context()
    ctx.providers.register(FakeProvider("mock", 100, "mock-navigation"))

    with pytest.raises(ProviderNotFoundError):
        await ctx.executor.execute(request_for("GV1"))


@pytest.mark.asyncio
async def test_provider_exception_becomes_internal_runtime_error() -> None:
    ctx = populated_context()
    ctx.providers.register(FakeProvider("broken", 100, "kisorb-sau", raises=True))

    with pytest.raises(RuntimeExecutionError) as error:
        await ctx.executor.execute(request_for("GV1"))

    assert error.value.error_code == "INTERNAL_ERROR"
    assert error.value.rejected is False
    assert "provider secret" not in error.value.message


def test_provider_policy_and_tool_ids_are_unique() -> None:
    ctx = SwarmContext()
    provider = FakeProvider("duplicate", 10, "kisorb-sau")
    policy = RecordingPolicy("duplicate", 10, PolicyDecision.ABSTAIN)

    async def tool() -> str:
        return "ok"

    ctx.providers.register(provider)
    ctx.policies.register(policy)
    ctx.tools.register(ToolSpec("tool", tool))

    with pytest.raises(DuplicateRegistrationError):
        ctx.providers.register(provider)
    with pytest.raises(DuplicateRegistrationError):
        ctx.policies.register(policy)
    with pytest.raises(DuplicateRegistrationError):
        ctx.tools.register(ToolSpec("tool", tool))
