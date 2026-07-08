from __future__ import annotations

from dataclasses import asdict

import grpc

from modern_ilu_bridge.generated import bridge_pb2
from modern_ilu_bridge.registry_store import RegistryStore, ServiceRecordData


REGISTRY_SERVICE = "modernilu.Registry"


def data_to_proto(record: ServiceRecordData | None) -> bridge_pb2.ServiceRecord:
    if record is None:
        return bridge_pb2.ServiceRecord()
    data = asdict(record)
    methods = list(data.pop("methods"))
    metadata = data.pop("metadata")
    proto = bridge_pb2.ServiceRecord(**data)
    proto.methods.extend(methods)
    proto.metadata.update(metadata)
    return proto


def proto_to_data(record: bridge_pb2.ServiceRecord) -> ServiceRecordData:
    return ServiceRecordData(
        name=record.name,
        language=record.language,
        protocol=record.protocol,
        interface_name=record.interface_name,
        endpoint=record.endpoint,
        methods=tuple(record.methods),
        status=record.status or "UNKNOWN",
        metadata=dict(record.metadata),
        last_seen_unix=record.last_seen_unix,
    )


class RegistryService:
    def __init__(self, store: RegistryStore):
        self._store = store

    def RegisterService(self, request, context):
        try:
            saved = self._store.register(proto_to_data(request.record))
        except ValueError as exc:
            return bridge_pb2.RegisterServiceResponse(ok=False, message=str(exc))
        return bridge_pb2.RegisterServiceResponse(
            ok=True,
            message="registered",
            record=data_to_proto(saved),
        )

    def DiscoverService(self, request, context):
        record = self._store.discover(request.name)
        if record is None:
            return bridge_pb2.DiscoverServiceResponse(
                ok=False,
                message=f"service {request.name} not found",
            )
        return bridge_pb2.DiscoverServiceResponse(
            ok=True,
            message="found",
            record=data_to_proto(record),
        )

    def ListServices(self, request, context):
        return bridge_pb2.ListServicesResponse(
            records=[data_to_proto(record) for record in self._store.list_services(request.language)]
        )

    def Heartbeat(self, request, context):
        record = self._store.heartbeat(request.name)
        if record is None:
            return bridge_pb2.HeartbeatResponse(
                ok=False,
                message=f"service {request.name} not found",
            )
        return bridge_pb2.HeartbeatResponse(
            ok=True,
            message="heartbeat accepted",
            record=data_to_proto(record),
        )

    def DeregisterService(self, request, context):
        removed = self._store.deregister(request.name)
        return bridge_pb2.DeregisterServiceResponse(
            ok=removed,
            message="deregistered" if removed else f"service {request.name} not found",
        )


def add_registry_service(server: grpc.Server, store: RegistryStore) -> None:
    service = RegistryService(store)
    handlers = {
        "RegisterService": grpc.unary_unary_rpc_method_handler(
            service.RegisterService,
            request_deserializer=bridge_pb2.RegisterServiceRequest.FromString,
            response_serializer=lambda response: response.SerializeToString(),
        ),
        "DiscoverService": grpc.unary_unary_rpc_method_handler(
            service.DiscoverService,
            request_deserializer=bridge_pb2.DiscoverServiceRequest.FromString,
            response_serializer=lambda response: response.SerializeToString(),
        ),
        "ListServices": grpc.unary_unary_rpc_method_handler(
            service.ListServices,
            request_deserializer=bridge_pb2.ListServicesRequest.FromString,
            response_serializer=lambda response: response.SerializeToString(),
        ),
        "Heartbeat": grpc.unary_unary_rpc_method_handler(
            service.Heartbeat,
            request_deserializer=bridge_pb2.HeartbeatRequest.FromString,
            response_serializer=lambda response: response.SerializeToString(),
        ),
        "DeregisterService": grpc.unary_unary_rpc_method_handler(
            service.DeregisterService,
            request_deserializer=bridge_pb2.DeregisterServiceRequest.FromString,
            response_serializer=lambda response: response.SerializeToString(),
        ),
    }
    server.add_generic_rpc_handlers((grpc.method_handlers_generic_handler(REGISTRY_SERVICE, handlers),))


class RegistryClient:
    def __init__(self, target: str):
        self._channel = grpc.insecure_channel(target)

    def register(self, record: bridge_pb2.ServiceRecord):
        method = self._channel.unary_unary(
            f"/{REGISTRY_SERVICE}/RegisterService",
            request_serializer=lambda request: request.SerializeToString(),
            response_deserializer=bridge_pb2.RegisterServiceResponse.FromString,
        )
        return method(bridge_pb2.RegisterServiceRequest(record=record))

    def discover(self, name: str):
        method = self._channel.unary_unary(
            f"/{REGISTRY_SERVICE}/DiscoverService",
            request_serializer=lambda request: request.SerializeToString(),
            response_deserializer=bridge_pb2.DiscoverServiceResponse.FromString,
        )
        return method(bridge_pb2.DiscoverServiceRequest(name=name))

    def list_services(self, language: str = ""):
        method = self._channel.unary_unary(
            f"/{REGISTRY_SERVICE}/ListServices",
            request_serializer=lambda request: request.SerializeToString(),
            response_deserializer=bridge_pb2.ListServicesResponse.FromString,
        )
        return method(bridge_pb2.ListServicesRequest(language=language))

    def heartbeat(self, name: str):
        method = self._channel.unary_unary(
            f"/{REGISTRY_SERVICE}/Heartbeat",
            request_serializer=lambda request: request.SerializeToString(),
            response_deserializer=bridge_pb2.HeartbeatResponse.FromString,
        )
        return method(bridge_pb2.HeartbeatRequest(name=name))

    def deregister(self, name: str):
        method = self._channel.unary_unary(
            f"/{REGISTRY_SERVICE}/DeregisterService",
            request_serializer=lambda request: request.SerializeToString(),
            response_deserializer=bridge_pb2.DeregisterServiceResponse.FromString,
        )
        return method(bridge_pb2.DeregisterServiceRequest(name=name))

    def close(self) -> None:
        self._channel.close()

