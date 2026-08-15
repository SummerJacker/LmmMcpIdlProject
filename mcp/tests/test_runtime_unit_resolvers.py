from __future__ import annotations

import asyncio
import logging
from dataclasses import dataclass
from types import SimpleNamespace
from typing import Any

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


async def abstaining_resolve(unit_id: str) -> None:
    return None


def malformed_resolver(**overrides: Any) -> Any:
    values = {
        "resolver_id": "malformed",
        "priority": 100,
        "resolve": abstaining_resolve,
    }
    values.update(overrides)
    return SimpleNamespace(**values)


def test_duplicate_resolver_ids_are_rejected() -> None:
    registry = resolver_registry()
    registry.register(StubResolver("live", 100))

    with pytest.raises(DuplicateRegistrationError):
        registry.register(StubResolver("live", 50))


@pytest.mark.parametrize("resolver_id", [None, 7, object(), "   "])
def test_non_string_or_blank_resolver_id_is_rejected(resolver_id: object) -> None:
    registry = resolver_registry()

    with pytest.raises(
        RuntimeRegistrationError,
        match="^resolver_id must be a nonempty string$",
    ):
        registry.register(malformed_resolver(resolver_id=resolver_id))


@pytest.mark.parametrize("priority", [None, "100", 1.0, True, False])
def test_non_integer_or_boolean_resolver_priority_is_rejected(
    priority: object,
) -> None:
    registry = resolver_registry()

    with pytest.raises(
        RuntimeRegistrationError,
        match="^resolver priority must be an integer$",
    ):
        registry.register(malformed_resolver(priority=priority))


@pytest.mark.parametrize("resolve", [None, "resolve"])
def test_noncallable_resolve_is_rejected(resolve: object) -> None:
    registry = resolver_registry()

    with pytest.raises(
        RuntimeRegistrationError,
        match="^resolver resolve must be callable$",
    ):
        registry.register(malformed_resolver(resolve=resolve))


def test_missing_resolve_is_rejected() -> None:
    registry = resolver_registry()
    resolver = malformed_resolver()
    del resolver.resolve

    with pytest.raises(
        RuntimeRegistrationError,
        match="^resolver resolve must be callable$",
    ):
        registry.register(resolver)


def test_resolver_registration_rolls_back_with_setup_transaction() -> None:
    journal = RegistrationJournal()
    registry = UnitResolverRegistry(journal)

    with pytest.raises(ValueError, match="setup failed"):
        with journal.activate("broken") as transaction:
            registry.register(StubResolver("live", 100))
            assert transaction.provisions == {"unit_resolver:live"}
            raise ValueError("setup failed")

    assert registry.list() == ()


def test_successful_registration_transaction_can_be_rolled_back() -> None:
    journal = RegistrationJournal()
    registry = UnitResolverRegistry(journal)

    with journal.activate("temporary") as transaction:
        registry.register(StubResolver("live", 100))

    assert registry.list() != ()
    transaction.rollback()
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
async def test_executor_preserves_mixed_static_dynamic_unit_order() -> None:
    class MultiUnitProvider(RecordingProvider):
        def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
            return len(units) == 3 and all(
                unit.platform == "test-live" for unit in units
            )

    class OrderedResolver(StubResolver):
        def __init__(self, result: UnitDescriptor) -> None:
            super().__init__("ordered", 100, result)
            self.requested_ids: list[str] = []

        async def resolve(self, unit_id: str) -> UnitDescriptor | None:
            self.requested_ids.append(unit_id)
            return await super().resolve(unit_id)

    ctx = SwarmContext()
    provider = MultiUnitProvider()
    first = live_unit("static-first")
    middle = live_unit("dynamic-middle")
    last = live_unit("static-last")
    resolver = OrderedResolver(middle)
    ctx.capabilities.register(
        CapabilitySpec("navigation.goto2d", "1.0", "test navigation", "unit")
    )
    ctx.providers.register(provider)
    ctx.units.register(first)
    ctx.units.register(last)
    ctx.unit_resolvers.register(resolver)
    request = ExecutionRequest(
        request_id="req-live-many",
        capability="navigation.goto2d",
        version="1.0",
        unit_ids=("static-first", "dynamic-middle", "static-last"),
        arguments={"x": 1.0, "y": 2.0},
    )

    result = await ctx.executor.execute(request)

    assert result.success is True
    assert provider.resolved_units == (first, middle, last)
    assert resolver.calls == 1
    assert resolver.requested_ids == ["dynamic-middle"]


@pytest.mark.asyncio
async def test_executor_resolves_duplicate_logical_unit_once_per_request() -> None:
    class DuplicateUnitProvider(RecordingProvider):
        def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
            return len(units) == 2 and all(
                unit.platform == "test-live" for unit in units
            )

    class OneShotResolver:
        resolver_id = "one-shot"
        priority = 100

        def __init__(self, result: UnitDescriptor) -> None:
            self.result = result
            self.requested_ids: list[str] = []

        async def resolve(self, unit_id: str) -> UnitDescriptor | None:
            self.requested_ids.append(unit_id)
            if len(self.requested_ids) > 1:
                raise RuntimeError("second lookup must not occur")
            return self.result

    ctx = SwarmContext()
    provider = DuplicateUnitProvider()
    descriptor = live_unit("GV_DYNAMIC")
    resolver = OneShotResolver(descriptor)
    ctx.capabilities.register(
        CapabilitySpec("navigation.goto2d", "1.0", "test navigation", "unit")
    )
    ctx.providers.register(provider)
    ctx.unit_resolvers.register(resolver)
    request = ExecutionRequest(
        request_id="req-live-duplicate",
        capability="navigation.goto2d",
        version="1.0",
        unit_ids=("gv_dynamic", "GV_DYNAMIC"),
        arguments={"x": 1.0, "y": 2.0},
    )

    result = await ctx.executor.execute(request)

    assert result.success is True
    assert resolver.requested_ids == ["gv_dynamic"]
    assert provider.resolved_units == (descriptor, descriptor)


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


@pytest.mark.parametrize("mutated_priority", [0, True, "invalid"])
@pytest.mark.asyncio
async def test_registered_priority_snapshot_ignores_later_mutation(
    mutated_priority: object,
) -> None:
    registry = resolver_registry()
    winner_unit = live_unit("winner")
    winner = StubResolver("winner", 100, winner_unit)
    lower = StubResolver("lower", 10, live_unit("lower"))
    registry.register(winner)
    registry.register(lower)
    winner.priority = mutated_priority  # type: ignore[assignment]

    resolved = await registry.resolve("missing")

    assert resolved is winner_unit


@pytest.mark.asyncio
async def test_registered_priority_snapshot_preserves_ambiguity() -> None:
    registry = resolver_registry()
    one = StubResolver("one", 100, live_unit("one"))
    two = StubResolver("two", 100, live_unit("two"))
    registry.register(one)
    registry.register(two)
    two.priority = 1

    with pytest.raises(AmbiguousUnitResolutionError):
        await registry.resolve("missing")


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
async def test_invalid_descriptor_is_logged_without_secret_and_abstains(
    caplog: pytest.LogCaptureFixture,
) -> None:
    registry = resolver_registry()
    secret = "private-descriptor-secret"
    resolver = StubResolver("invalid", 100, {"secret": secret})  # type: ignore[arg-type]
    registry.register(resolver)

    with caplog.at_level(logging.ERROR):
        with pytest.raises(UnitNotFoundError, match="^unit not found: missing$"):
            await registry.resolve("missing")

    assert any(
        record.getMessage() == "unit resolver invalid returned invalid descriptor"
        for record in caplog.records
    )
    assert secret not in caplog.text


@pytest.mark.asyncio
async def test_resolver_cancellation_propagates() -> None:
    registry = resolver_registry()
    registry.register(
        StubResolver("cancelled", 100, error=asyncio.CancelledError())
    )

    with pytest.raises(asyncio.CancelledError):
        await registry.resolve("missing")


@pytest.mark.asyncio
async def test_no_resolver_candidate_preserves_original_missing_identifier() -> None:
    registry = resolver_registry()
    registry.register(StubResolver("abstain", 100))

    with pytest.raises(UnitNotFoundError) as error:
        await registry.resolve("missing")

    assert str(error.value) == "unit not found: missing"
    assert error.value.error_code == "UNIT_NOT_FOUND"
