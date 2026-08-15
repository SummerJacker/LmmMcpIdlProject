from __future__ import annotations

from typing import Any

from .registration import RegistrationJournal
from .registry import (
    CapabilityRegistry,
    PolicyRegistry,
    ProviderRegistry,
    ServiceRegistry,
    ToolRegistry,
    UnitRegistry,
    UnitResolverRegistry,
)


class SwarmContext:
    def __init__(self) -> None:
        self.registration_journal = RegistrationJournal()
        self.units = UnitRegistry(self.registration_journal)
        self.unit_resolvers = UnitResolverRegistry(self.registration_journal)
        self.capabilities = CapabilityRegistry(self.registration_journal)
        self.providers = ProviderRegistry(self.registration_journal)
        self.policies = PolicyRegistry(self.registration_journal)
        self.tools = ToolRegistry(self.registration_journal)
        self.services = ServiceRegistry(self.registration_journal)
        self.plugin_loader: Any = None

        from .executor import CapabilityExecutor

        self.executor = CapabilityExecutor(self)
