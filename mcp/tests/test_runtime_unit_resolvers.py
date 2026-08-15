from __future__ import annotations

import logging
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
from swarm_runtime.registration import RegistrationJournal
from swarm_runtime.registry import UnitResolverRegistry


@dataclass
class StubResolver:
    resolver_id: str
    priority: int
    result: UnitDescriptor | None = None
    error: Exception | None = None
    calls: int = 0

    async def resolve(self, unit_id: str) -> UnitDescriptor | None:
        self.calls += 1
        if self.error is not None:
            raise self.error
        return self.result


class RecordingProvider:
    provider_id = "recording"
    capability = "navigation.goto2d"
    version = "1.0"
    priority = 100

    def __init__(self) -> None:
        self.resolved_units: tuple[UnitDescriptor, ...] = ()

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "test-live"

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        self.resolved_units = units
        return ExecutionResult(True, "ok", {"unit_id": units[0].unit_id})


def live_unit(unit_id: str) -> UnitDescriptor:
    return UnitDescriptor(
        unit_id=unit_id,
        kind="ugv",
        platform="test-live",
        provider_plugin_id="platform.test-live",
    )


def execution_context() -> tuple[SwarmContext, RecordingProvider]:
    ctx = SwarmContext()
    provider = RecordingProvider()
    ctx.capabilities.register(
        CapabilitySpec("navigation.goto2d", "1.0", "test navigation", "unit")
    )
    ctx.providers.register(provider)
    return ctx, provider


def request_for(unit_id: str) -> ExecutionRequest:
    return ExecutionRequest(
        request_id="req-live-1",
        capability="navigation.goto2d",
        version="1.0",
        unit_ids=(unit_id,),
        arguments={"x": 1.0, "y": 2.0},
    )


def resolver_registry() -> UnitResolverRegistry:
    return UnitResolverRegistry(RegistrationJournal())


def test_duplicate_resolver_ids_are_rejected() -> None:
    registry = resolver_registry()
    registry.register(StubResolver("live", 100))

    with pytest.raises(DuplicateRegistrationError):
        registry.register(StubResolver("live", 50))


def test_blank_resolver_id_is_rejected() -> None:
    registry = resolver_registry()

    with pytest.raises(RuntimeRegistrationError):
        registry.register(StubResolver("   ", 100))


def test_resolver_registration_rolls_back_with_setup_transaction() -> None:
    journal = RegistrationJournal()
    registry = UnitResolverRegistry(journal)

    with pytest.raises(ValueError, match="setup failed"):
        with journal.activate("broken") as transaction:
            registry.register(StubResolver("live", 100))
            assert transaction.provisions == {"unit_resolver:live"}
            raise ValueError("setup failed")

    assert registry.list() == ()


@pytest.mark.asyncio
async def test_executor_prefers_static_unit_without_calling_resolvers() -> None:
    ctx, provider = execution_context()
    static = live_unit("known")
    resolver = StubResolver("dynamic", 100, live_unit("known"))
    ctx.units.register(static)
    ctx.unit_resolvers.register(resolver)

    result = await ctx.executor.execute(request_for("known"))

    assert result.success is True
    assert resolver.calls == 0
    assert provider.resolved_units == (static,)


@pytest.mark.asyncio
async def test_dynamic_unit_executes_without_mutating_static_registry() -> None:
    ctx, provider = execution_context()
    dynamic = live_unit("missing")
    ctx.unit_resolvers.register(StubResolver("dynamic", 100, dynamic))

    result = await ctx.executor.execute(request_for("missing"))

    assert result.success is True
    assert provider.resolved_units == (dynamic,)
    assert ctx.units.list() == ()


@pytest.mark.asyncio
async def test_all_resolvers_are_evaluated_and_unique_highest_priority_wins() -> None:
    ctx, provider = execution_context()
    high_unit = live_unit("winner")
    high = StubResolver("high", 100, high_unit)
    low = StubResolver("low", 10, live_unit("loser"))
    ctx.unit_resolvers.register(high)
    ctx.unit_resolvers.register(low)

    await ctx.executor.execute(request_for("missing"))

    assert high.calls == 1
    assert low.calls == 1
    assert provider.resolved_units == (high_unit,)


@pytest.mark.asyncio
async def test_equal_highest_priority_candidates_are_ambiguous() -> None:
    ctx, _ = execution_context()
    ctx.unit_resolvers.register(StubResolver("one", 100, live_unit("one")))
    ctx.unit_resolvers.register(StubResolver("two", 100, live_unit("two")))

    with pytest.raises(AmbiguousUnitResolutionError) as error:
        await ctx.executor.execute(request_for("missing"))

    assert error.value.error_code == "UNIT_NOT_FOUND"
    assert str(error.value) == "ambiguous unit resolution: missing"


@pytest.mark.asyncio
async def test_resolver_exception_is_logged_and_treated_as_abstention(
    caplog: pytest.LogCaptureFixture,
) -> None:
    ctx, provider = execution_context()
    broken = StubResolver("broken", 100, error=ValueError("resolver secret"))
    good_unit = live_unit("resolved")
    good = StubResolver("good", 10, good_unit)
    ctx.unit_resolvers.register(broken)
    ctx.unit_resolvers.register(good)

    with caplog.at_level(logging.ERROR):
        result = await ctx.executor.execute(request_for("missing"))

    assert broken.calls == 1
    assert good.calls == 1
    assert provider.resolved_units == (good_unit,)
    assert any(
        record.getMessage() == "unit resolver broken failed"
        for record in caplog.records
    )
    assert "resolver secret" not in result.message
    assert "resolver secret" not in str(result.data)


@pytest.mark.asyncio
async def test_no_resolver_candidate_preserves_original_missing_identifier() -> None:
    registry = resolver_registry()
    registry.register(StubResolver("abstain", 100))

    with pytest.raises(UnitNotFoundError) as error:
        await registry.resolve("missing")

    assert str(error.value) == "unit not found: missing"
    assert error.value.error_code == "UNIT_NOT_FOUND"
