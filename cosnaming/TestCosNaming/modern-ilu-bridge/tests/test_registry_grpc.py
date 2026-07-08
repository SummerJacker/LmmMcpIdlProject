from concurrent import futures

import grpc

from modern_ilu_bridge.generated import bridge_pb2
from modern_ilu_bridge.grpc_registry import RegistryClient, add_registry_service
from modern_ilu_bridge.registry_store import RegistryStore


def test_registry_grpc_register_discover_and_list():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=2))
    store = RegistryStore(now=lambda: 123)
    add_registry_service(server, store)
    port = server.add_insecure_port("127.0.0.1:0")
    server.start()

    try:
        client = RegistryClient(f"127.0.0.1:{port}")
        record = bridge_pb2.ServiceRecord(
            name="legacy.hello-world.c",
            language="c",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:test",
            methods=["hello_world"],
            metadata={"runner": "test"},
        )

        registered = client.register(record)
        discovered = client.discover("legacy.hello-world.c")
        listed = client.list_services(language="c")

        assert registered.ok is True
        assert registered.record.status == "HEALTHY"
        assert registered.record.last_seen_unix == 123
        assert discovered.ok is True
        assert discovered.record.endpoint == "ilusbh:test"
        assert [item.name for item in listed.records] == ["legacy.hello-world.c"]
    finally:
        server.stop(0)


def test_registry_grpc_rejects_unknown_service():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=2))
    add_registry_service(server, RegistryStore())
    port = server.add_insecure_port("127.0.0.1:0")
    server.start()

    try:
        client = RegistryClient(f"127.0.0.1:{port}")
        response = client.discover("missing")

        assert response.ok is False
        assert "not found" in response.message
    finally:
        server.stop(0)

