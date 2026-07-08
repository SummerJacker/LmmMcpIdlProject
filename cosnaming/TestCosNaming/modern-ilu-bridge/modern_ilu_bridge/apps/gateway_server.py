from __future__ import annotations

import argparse
from concurrent import futures
from pathlib import Path

import grpc

from modern_ilu_bridge.grpc_gateway import RemoteRegistryLookup, add_gateway_service
from modern_ilu_bridge.legacy_hello import LegacyHelloInvoker


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the modern ILU gateway gRPC server.")
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=50052)
    parser.add_argument("--registry", default="127.0.0.1:50051")
    parser.add_argument("--client-exe", required=True)
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    registry = RemoteRegistryLookup(args.registry)
    invoker = LegacyHelloInvoker(Path(args.client_exe))
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    add_gateway_service(server, registry, invoker)
    target = f"{args.host}:{args.port}"
    server.add_insecure_port(target)
    server.start()
    print(f"gateway-server listening on {target}, registry={args.registry}")
    try:
        server.wait_for_termination()
    except KeyboardInterrupt:
        server.stop(0)
        registry.close()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

