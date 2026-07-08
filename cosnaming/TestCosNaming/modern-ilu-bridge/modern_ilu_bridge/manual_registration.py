from __future__ import annotations

from modern_ilu_bridge.registry_store import ServiceRecordData


def build_manual_legacy_record(
    name: str,
    language: str,
    protocol: str,
    interface_name: str,
    endpoint: str,
    methods: list[str],
    metadata: dict[str, str] | None = None,
) -> ServiceRecordData:
    merged_metadata = {"registration": "manual"}
    if metadata:
        merged_metadata.update(metadata)
    record = ServiceRecordData(
        name=name,
        language=language,
        protocol=protocol,
        interface_name=interface_name,
        endpoint=endpoint,
        methods=tuple(methods),
        metadata=merged_metadata,
    )
    # Reuse the store validator without mutating or timestamping the record.
    from modern_ilu_bridge.registry_store import RegistryStore

    RegistryStore._validate(record)
    return record

