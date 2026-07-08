from __future__ import annotations

import argparse
import json

from modern_ilu_bridge.grpc_gateway import GatewayClient
from modern_ilu_bridge.grpc_registry import RegistryClient


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Call a service through the modern ILU bridge.")
    subparsers = parser.add_subparsers(dest="command", required=True)

    list_parser = subparsers.add_parser("list")
    list_parser.add_argument("--registry", default="127.0.0.1:50051")
    list_parser.add_argument("--language", default="")

    invoke_parser = subparsers.add_parser("invoke")
    invoke_parser.add_argument("--gateway", default="127.0.0.1:50052")
    invoke_parser.add_argument("--service", default="legacy.hello-world.c")
    invoke_parser.add_argument("--method", default="hello_world")
    invoke_parser.add_argument("--message", default="hello from modern gRPC")
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    if args.command == "list":
        client = RegistryClient(args.registry)
        try:
            response = client.list_services(language=args.language)
            for record in response.records:
                print(f"{record.name} language={record.language} protocol={record.protocol} status={record.status}")
        finally:
            client.close()
        return 0

    client = GatewayClient(args.gateway)
    try:
        response = client.invoke(
            service_name=args.service,
            method=args.method,
            payload_json=json.dumps({"message": args.message}, ensure_ascii=False),
        )
        if not response.ok:
            print(f"invoke failed: {response.message}")
            return 1
        print(response.result_json)
    finally:
        client.close()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

