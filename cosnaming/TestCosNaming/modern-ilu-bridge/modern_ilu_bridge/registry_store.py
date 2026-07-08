from __future__ import annotations

import time
from dataclasses import dataclass, field, replace
from typing import Callable


SUPPORTED_LANGUAGES = {"c", "java", "python", "lisp", "modern"}
SUPPORTED_PROTOCOLS = {"ilu-sbh", "ilu-ior", "grpc"}


@dataclass(frozen=True)
class ServiceRecordData:
    name: str
    language: str
    protocol: str
    interface_name: str
    endpoint: str
    methods: tuple[str, ...]
    status: str = "UNKNOWN"
    metadata: dict[str, str] = field(default_factory=dict)
    last_seen_unix: int = 0


class RegistryStore:
    def __init__(self, now: Callable[[], int] | None = None):
        self._records: dict[str, ServiceRecordData] = {}
        self._now = now or (lambda: int(time.time()))

    def register(self, record: ServiceRecordData) -> ServiceRecordData:
        self._validate(record)
        saved = replace(record, status="HEALTHY", last_seen_unix=self._now())
        self._records[saved.name] = saved
        return saved

    def discover(self, name: str) -> ServiceRecordData | None:
        return self._records.get(name)

    def list_services(self, language: str = "") -> list[ServiceRecordData]:
        records = sorted(self._records.values(), key=lambda record: record.name)
        if not language:
            return records
        return [record for record in records if record.language == language]

    def heartbeat(self, name: str) -> ServiceRecordData | None:
        record = self._records.get(name)
        if record is None:
            return None
        updated = replace(record, status="HEALTHY", last_seen_unix=self._now())
        self._records[name] = updated
        return updated

    def deregister(self, name: str) -> bool:
        return self._records.pop(name, None) is not None

    @staticmethod
    def _validate(record: ServiceRecordData) -> None:
        if record.language not in SUPPORTED_LANGUAGES:
            raise ValueError(f"Unsupported language: {record.language}")
        if record.protocol not in SUPPORTED_PROTOCOLS:
            raise ValueError(f"Unsupported protocol: {record.protocol}")
        if not record.name:
            raise ValueError("Service name is required")
        if not record.endpoint:
            raise ValueError("Service endpoint is required")
        if not record.methods:
            raise ValueError("At least one method is required")

