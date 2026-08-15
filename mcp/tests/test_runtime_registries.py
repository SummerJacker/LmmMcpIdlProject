from __future__ import annotations

import json

import pytest

from swarm_runtime.errors import DuplicateRegistrationError, UnitNotFoundError
from swarm_runtime.models import CapabilitySpec, ExecutionResult, UnitDescriptor
from swarm_runtime.registration import RegistrationJournal
from swarm_runtime.registry import CapabilityRegistry, ServiceRegistry, UnitRegistry


def make_registries():
    journal = RegistrationJournal()
    return (
        journal,
        UnitRegistry(journal),
        CapabilityRegistry(journal),
        ServiceRegistry(journal),
    )


def test_unit_registry_resolves_canonical_id_and_alias_case_insensitively() -> None:
    _, units, _, _ = make_registries()
    descriptor = UnitDescriptor(
        unit_id="GV1",
        kind="ugv",
        platform="kisorb-sau",
        provider_plugin_id="platform.kisorb-sau",
        aliases=("robot_1",),
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
    spec = CapabilitySpec(
        "navigation.goto2d", "1.0", "Navigate to x/y", "unit", "navigateTo"
    )

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
