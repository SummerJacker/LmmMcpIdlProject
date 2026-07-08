from __future__ import annotations

import argparse
from concurrent import futures

import grpc

from modern_ilu_bridge.grpc_registry import add_registry_service
from modern_ilu_bridge.registry_store import RegistryStore


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the modern ILU registry gRPC server.")
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=50051)
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    add_registry_service(server, RegistryStore())
    target = f"{args.host}:{args.port}"
    server.add_insecure_port(target)
    server.start()
    print(f"registry-server listening on {target}")
    try:
        server.wait_for_termination()
    except KeyboardInterrupt:
        server.stop(0)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

