from concurrent import futures
import json

import grpc

from modern_ilu_bridge.generated import bridge_pb2
from modern_ilu_bridge.grpc_gateway import GatewayClient, add_gateway_service
from modern_ilu_bridge.registry_store import RegistryStore, ServiceRecordData


class FakeHelloInvoker:
    def __init__(self):
        self.calls = []

    def invoke(self, endpoint, message):
        self.calls.append((endpoint, message))
        return f"Hello! {message}"


def test_gateway_invokes_registered_legacy_hello_service():
    store = RegistryStore(now=lambda: 100)
    store.register(
        ServiceRecordData(
            name="legacy.hello-world.c",
            language="c",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:test",
            methods=("hello_world",),
        )
    )
    fake_invoker = FakeHelloInvoker()
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=2))
    add_gateway_service(server, store, hello_invoker=fake_invoker)
    port = server.add_insecure_port("127.0.0.1:0")
    server.start()

    try:
        client = GatewayClient(f"127.0.0.1:{port}")
        response = client.invoke(
            service_name="legacy.hello-world.c",
            method="hello_world",
            payload_json=json.dumps({"message": "from grpc"}),
        )

        assert response.ok is True
        assert json.loads(response.result_json) == {"result": "Hello! from grpc"}
        assert fake_invoker.calls == [("ilusbh:test", "from grpc")]
    finally:
        server.stop(0)


def test_gateway_rejects_unknown_method():
    store = RegistryStore(now=lambda: 100)
    store.register(
        ServiceRecordData(
            name="legacy.hello-world.c",
            language="c",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:test",
            methods=("hello_world",),
        )
    )
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=2))
    add_gateway_service(server, store, hello_invoker=FakeHelloInvoker())
    port = server.add_insecure_port("127.0.0.1:0")
    server.start()

    try:
        client = GatewayClient(f"127.0.0.1:{port}")
        response = client.invoke(
            service_name="legacy.hello-world.c",
            method="missing",
            payload_json=json.dumps({"message": "from grpc"}),
        )

        assert response.ok is False
        assert "does not expose method" in response.message
    finally:
        server.stop(0)

