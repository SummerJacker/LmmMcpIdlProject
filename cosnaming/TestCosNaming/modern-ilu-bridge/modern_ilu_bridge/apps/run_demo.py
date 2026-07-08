from __future__ import annotations

import json
from concurrent import futures
from pathlib import Path

import grpc

from modern_ilu_bridge.grpc_gateway import GatewayClient, add_gateway_service
from modern_ilu_bridge.grpc_registry import RegistryClient, add_registry_service, data_to_proto
from modern_ilu_bridge.legacy_hello import (
    LegacyHelloInvoker,
    LegacyHelloRunner,
    build_legacy_hello_record,
)
from modern_ilu_bridge.registry_store import RegistryStore


def repo_root() -> Path:
    return Path(__file__).resolve().parents[3]


def default_legacy_dir() -> Path:
    return repo_root() / "Iluhome" / "examples" / "hello-world" / "WinRel"


def main() -> int:
    legacy_dir = default_legacy_dir()
    if not (legacy_dir / "server.exe").exists():
        print(f"legacy server.exe not found in {legacy_dir}")
        return 1
    if not (legacy_dir / "client.exe").exists():
        print(f"legacy client.exe not found in {legacy_dir}")
        return 1

    store = RegistryStore()
    registry_server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    add_registry_service(registry_server, store)
    registry_port = registry_server.add_insecure_port("127.0.0.1:0")

    gateway_server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    add_gateway_service(gateway_server, store, LegacyHelloInvoker(legacy_dir / "client.exe"))
    gateway_port = gateway_server.add_insecure_port("127.0.0.1:0")

    runner = LegacyHelloRunner(legacy_dir)
    registry_server.start()
    gateway_server.start()

    try:
        registry_target = f"127.0.0.1:{registry_port}"
        gateway_target = f"127.0.0.1:{gateway_port}"
        print(f"registry-server: {registry_target}")
        print(f"gateway-server:  {gateway_target}")

        sbh = runner.start()
        print(f"legacy C hello-world SBH: {sbh}")

        registry_client = RegistryClient(registry_target)
        try:
            record = build_legacy_hello_record(
                name="legacy.hello-world.c",
                language="c",
                sbh=sbh,
                service_dir=legacy_dir,
            )
            registered = registry_client.register(data_to_proto(record))
            if not registered.ok:
                print(f"registration failed: {registered.message}")
                return 1
            print(
                "registered service: "
                f"{registered.record.name} language={registered.record.language} "
                f"protocol={registered.record.protocol}"
            )
        finally:
            registry_client.close()

        gateway_client = GatewayClient(gateway_target)
        try:
            response = gateway_client.invoke(
                service_name="legacy.hello-world.c",
                method="hello_world",
                payload_json=json.dumps({"message": "hello from modern gRPC"}),
            )
            if not response.ok:
                print(f"invoke failed: {response.message}")
                return 1
            result = json.loads(response.result_json)
            print(f"modern gRPC invoke result: {result['result']}")
        finally:
            gateway_client.close()
    finally:
        runner.stop()
        registry_server.stop(0)
        gateway_server.stop(0)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())

