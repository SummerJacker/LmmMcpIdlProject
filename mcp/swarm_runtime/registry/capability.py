from __future__ import annotations

from ..errors import DuplicateRegistrationError, RuntimeRegistrationError
from ..models import CapabilitySpec
from ..registration import RegistrationJournal


class CapabilityRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._capabilities: dict[tuple[str, str], CapabilitySpec] = {}

    def register(self, capability: CapabilitySpec) -> None:
        if not capability.name.strip() or not capability.version.strip():
            raise RuntimeRegistrationError("capability name and version are required")
        key = (capability.name, capability.version)
        if key in self._capabilities:
            raise DuplicateRegistrationError(
                f"capability already registered: {capability.name}@{capability.version}"
            )
        self._capabilities[key] = capability
        self._journal.record(
            f"capability:{capability.name}@{capability.version}",
            lambda item=key: self._capabilities.pop(item, None),
        )

    def get(self, name: str, version: str) -> CapabilitySpec:
        return self._capabilities[(name, version)]

    def list(self) -> tuple[CapabilitySpec, ...]:
        return tuple(self._capabilities[key] for key in sorted(self._capabilities))
