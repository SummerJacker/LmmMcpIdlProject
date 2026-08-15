from __future__ import annotations

from typing import Protocol

from .models import (
    ExecutionRequest,
    ExecutionResult,
    PolicyOutcome,
    UnitDescriptor,
)


class UnitResolver(Protocol):
    resolver_id: str
    priority: int

    async def resolve(self, unit_id: str) -> UnitDescriptor | None:
        ...


class CapabilityProvider(Protocol):
    provider_id: str
    capability: str
    version: str
    priority: int

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        ...

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        ...


class ExecutionPolicy(Protocol):
    policy_id: str
    priority: int

    def applies_to(self, request: ExecutionRequest) -> bool:
        ...

    async def evaluate(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
        provider: CapabilityProvider,
    ) -> PolicyOutcome:
        ...
