from __future__ import annotations

from ..errors import (
    AmbiguousProviderError,
    DuplicateRegistrationError,
    ProviderNotFoundError,
    RuntimeRegistrationError,
)
from ..models import UnitDescriptor
from ..protocols import CapabilityProvider
from ..registration import RegistrationJournal


class ProviderRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._providers: dict[str, CapabilityProvider] = {}

    def register(self, provider: CapabilityProvider) -> None:
        if not provider.provider_id.strip():
            raise RuntimeRegistrationError("provider_id must not be empty")
        if provider.provider_id in self._providers:
            raise DuplicateRegistrationError(
                f"provider already registered: {provider.provider_id}"
            )
        self._providers[provider.provider_id] = provider
        self._journal.record(
            f"provider:{provider.provider_id}",
            lambda key=provider.provider_id: self._providers.pop(key, None),
        )

    def resolve(
        self,
        capability: str,
        version: str,
        units: tuple[UnitDescriptor, ...],
    ) -> CapabilityProvider:
        matched = [
            provider
            for provider in self._providers.values()
            if provider.capability == capability
            and provider.version == version
            and provider.supports(units)
        ]
        if not matched:
            raise ProviderNotFoundError(capability, version)
        matched.sort(key=lambda provider: (-provider.priority, provider.provider_id))
        if len(matched) > 1 and matched[0].priority == matched[1].priority:
            raise AmbiguousProviderError(capability, version)
        return matched[0]

    def list(self) -> tuple[CapabilityProvider, ...]:
        return tuple(self._providers[key] for key in sorted(self._providers))
