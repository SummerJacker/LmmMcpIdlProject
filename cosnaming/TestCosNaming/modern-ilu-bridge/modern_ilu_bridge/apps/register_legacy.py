from __future__ import annotations

import argparse

from modern_ilu_bridge.grpc_registry import RegistryClient, data_to_proto
from modern_ilu_bridge.manual_registration import build_manual_legacy_record


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Manually register a legacy ILU service endpoint.")
    parser.add_argument("--registry", default="127.0.0.1:50051")
    parser.add_argument("--name", required=True)
    parser.add_argument("--language", required=True, choices=["c", "java", "python", "lisp", "modern"])
    parser.add_argument("--protocol", required=True, choices=["ilu-sbh", "ilu-ior", "grpc"])
    parser.add_argument("--interface", dest="interface_name", required=True)
    parser.add_argument("--endpoint", required=True)
    parser.add_argument("--method", action="append", required=True)
    parser.add_argument("--metadata", action="append", default=[], help="key=value metadata. May be repeated.")
    return parser


def parse_metadata(items: list[str]) -> dict[str, str]:
    metadata: dict[str, str] = {}
    for item in items:
        if "=" not in item:
            raise ValueError(f"metadata must be key=value, got {item}")
        key, value = item.split("=", 1)
        metadata[key] = value
    return metadata


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    try:
        metadata = parse_metadata(args.metadata)
        record = build_manual_legacy_record(
            name=args.name,
            language=args.language,
            protocol=args.protocol,
            interface_name=args.interface_name,
            endpoint=args.endpoint,
            methods=args.method,
            metadata=metadata,
        )
    except ValueError as exc:
        print(f"invalid registration: {exc}")
        return 1

    client = RegistryClient(args.registry)
    try:
        response = client.register(data_to_proto(record))
        if not response.ok:
            print(f"registration failed: {response.message}")
            return 1
        print(
            f"registered {response.record.name} "
            f"language={response.record.language} protocol={response.record.protocol}"
        )
    finally:
        client.close()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

