from __future__ import annotations

from typing import Any

from ..errors import DuplicateRegistrationError, RuntimeRegistrationError
from ..registration import RegistrationJournal


class ServiceRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._services: dict[str, Any] = {}

    def register(self, service_id: str, service: Any) -> None:
        if not service_id.strip():
            raise RuntimeRegistrationError("service_id must not be empty")
        if service_id in self._services:
            raise DuplicateRegistrationError(f"service already registered: {service_id}")
        self._services[service_id] = service
        self._journal.record(
            f"service:{service_id}",
            lambda key=service_id: self._services.pop(key, None),
        )

    def get(self, service_id: str) -> Any:
        return self._services[service_id]
