from __future__ import annotations

import json
from typing import Protocol

import grpc

from modern_ilu_bridge.generated import bridge_pb2
from modern_ilu_bridge.grpc_registry import RegistryClient, proto_to_data
from modern_ilu_bridge.registry_store import RegistryStore


GATEWAY_SERVICE = "modernilu.Gateway"


class HelloInvoker(Protocol):
    def invoke(self, endpoint: str, message: str) -> str:
        ...


class GatewayService:
    def __init__(self, registry, hello_invoker: HelloInvoker):
        self._registry = registry
        self._hello_invoker = hello_invoker

    def Invoke(self, request, context):
        record = self._registry.discover(request.service_name)
        if record is None:
            return bridge_pb2.InvokeResponse(
                ok=False,
                message=f"service {request.service_name} not found",
            )
        if request.method not in record.methods:
            return bridge_pb2.InvokeResponse(
                ok=False,
                message=f"service {request.service_name} does not expose method {request.method}",
            )
        if record.interface_name != "hello_world.service" or request.method != "hello_world":
            return bridge_pb2.InvokeResponse(
                ok=False,
                message=f"no adapter for {record.interface_name}.{request.method}",
            )
        if record.protocol != "ilu-sbh":
            return bridge_pb2.InvokeResponse(
                ok=False,
                message=f"hello_world adapter requires ilu-sbh, got {record.protocol}",
            )

        try:
            payload = json.loads(request.payload_json or "{}")
            message = payload.get("message", "")
            if not isinstance(message, str):
                raise ValueError("payload field 'message' must be a string")
            result = self._hello_invoker.invoke(record.endpoint, message)
        except Exception as exc:
            return bridge_pb2.InvokeResponse(ok=False, message=str(exc))

        return bridge_pb2.InvokeResponse(
            ok=True,
            message="invoked",
            result_json=json.dumps({"result": result}, ensure_ascii=False),
        )


def add_gateway_service(
    server: grpc.Server,
    store: RegistryStore,
    hello_invoker: HelloInvoker,
) -> None:
    service = GatewayService(store, hello_invoker)
    handlers = {
        "Invoke": grpc.unary_unary_rpc_method_handler(
            service.Invoke,
            request_deserializer=bridge_pb2.InvokeRequest.FromString,
            response_serializer=lambda response: response.SerializeToString(),
        )
    }
    server.add_generic_rpc_handlers((grpc.method_handlers_generic_handler(GATEWAY_SERVICE, handlers),))


class GatewayClient:
    def __init__(self, target: str):
        self._channel = grpc.insecure_channel(target)

    def invoke(self, service_name: str, method: str, payload_json: str):
        rpc = self._channel.unary_unary(
            f"/{GATEWAY_SERVICE}/Invoke",
            request_serializer=lambda request: request.SerializeToString(),
            response_deserializer=bridge_pb2.InvokeResponse.FromString,
        )
        return rpc(
            bridge_pb2.InvokeRequest(
                service_name=service_name,
                method=method,
                payload_json=payload_json,
            )
        )

    def close(self) -> None:
        self._channel.close()


class RemoteRegistryLookup:
    def __init__(self, target: str):
        self._client = RegistryClient(target)

    def discover(self, name: str):
        response = self._client.discover(name)
        if not response.ok:
            return None
        return proto_to_data(response.record)

    def close(self) -> None:
        self._client.close()
