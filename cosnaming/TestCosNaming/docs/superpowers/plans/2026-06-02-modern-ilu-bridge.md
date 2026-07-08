# Modern ILU Bridge Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build a modern Python gRPC registry and gateway that can discover and invoke the legacy C ILU hello-world service while preserving C/Java/Python/Lisp registration metadata.

**Architecture:** The new `modern-ilu-bridge` project defines protobuf messages, an in-memory registry, gRPC registry and gateway handlers, a legacy ILU hello-world runner/invoker, command-line entry points, and a one-command demo script. The old ILU files remain unchanged.

**Tech Stack:** Python 3.10, grpcio, protobuf, pytest, existing ILU `server.exe` and `client.exe`.

---

### Task 1: Project Skeleton And Protobuf

**Files:**
- Create: `modern-ilu-bridge/proto/bridge.proto`
- Create: `modern-ilu-bridge/modern_ilu_bridge/__init__.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/generated/__init__.py`
- Generate: `modern-ilu-bridge/modern_ilu_bridge/generated/bridge_pb2.py`

- [ ] **Step 1: Write protobuf contract**

Create messages for service records, registry operations, and gateway invoke operations. Use `ServiceRecord`, `RegisterServiceRequest`, `DiscoverServiceRequest`, `ListServicesRequest`, `HeartbeatRequest`, `DeregisterServiceRequest`, `InvokeRequest`, and `InvokeResponse`.

- [ ] **Step 2: Generate Python protobuf messages**

Run: `protoc --python_out=modern-ilu-bridge/modern_ilu_bridge/generated --proto_path=modern-ilu-bridge/proto modern-ilu-bridge/proto/bridge.proto`

Expected: `bridge_pb2.py` exists and imports without error.

### Task 2: Registry Store With TDD

**Files:**
- Create: `modern-ilu-bridge/tests/test_registry_store.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/registry_store.py`

- [ ] **Step 1: Write failing registry tests**

Tests must verify registering/discovering records, listing by language, heartbeat timestamp updates, deregistration, and language validation for `c/java/python/lisp/modern`.

- [ ] **Step 2: Run tests and verify failure**

Run: `python -m pytest modern-ilu-bridge/tests/test_registry_store.py -q`

Expected: FAIL because `modern_ilu_bridge.registry_store` does not exist.

- [ ] **Step 3: Implement registry store**

Implement `RegistryStore`, `ServiceRecordData`, and validation helpers.

- [ ] **Step 4: Run tests and verify pass**

Run: `python -m pytest modern-ilu-bridge/tests/test_registry_store.py -q`

Expected: all tests pass.

### Task 3: gRPC Registry Service With TDD

**Files:**
- Create: `modern-ilu-bridge/tests/test_registry_grpc.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/grpc_registry.py`

- [ ] **Step 1: Write failing gRPC registry test**

Test must start an in-process gRPC server, register `legacy.hello-world.c`, discover it, and list it.

- [ ] **Step 2: Run test and verify failure**

Run: `python -m pytest modern-ilu-bridge/tests/test_registry_grpc.py -q`

Expected: FAIL because `grpc_registry` does not exist.

- [ ] **Step 3: Implement generic gRPC registry service**

Use `grpc.method_handlers_generic_handler` so generated `*_pb2_grpc.py` is not required.

- [ ] **Step 4: Run test and verify pass**

Run: `python -m pytest modern-ilu-bridge/tests/test_registry_grpc.py -q`

Expected: all tests pass.

### Task 4: Legacy Hello Adapter With TDD

**Files:**
- Create: `modern-ilu-bridge/tests/test_legacy_hello.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/legacy_hello.py`

- [ ] **Step 1: Write failing adapter tests**

Tests must verify parsing `Hello! hello from Windows` from legacy stdout and constructing service record metadata from an SBH.

- [ ] **Step 2: Run test and verify failure**

Run: `python -m pytest modern-ilu-bridge/tests/test_legacy_hello.py -q`

Expected: FAIL because `legacy_hello` does not exist.

- [ ] **Step 3: Implement legacy runner and invoker helpers**

Implement `extract_hello_response`, `build_legacy_hello_record`, `LegacyHelloInvoker`, and `LegacyHelloRunner`.

- [ ] **Step 4: Run test and verify pass**

Run: `python -m pytest modern-ilu-bridge/tests/test_legacy_hello.py -q`

Expected: all tests pass.

### Task 5: Gateway Service With TDD

**Files:**
- Create: `modern-ilu-bridge/tests/test_gateway_grpc.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/grpc_gateway.py`

- [ ] **Step 1: Write failing gateway test**

Test must register a legacy service, start a gateway server with a fake invoker, invoke `hello_world`, and assert the gRPC response.

- [ ] **Step 2: Run test and verify failure**

Run: `python -m pytest modern-ilu-bridge/tests/test_gateway_grpc.py -q`

Expected: FAIL because `grpc_gateway` does not exist.

- [ ] **Step 3: Implement generic gRPC gateway service**

Implement service discovery, method validation, payload extraction, adapter dispatch, and error responses.

- [ ] **Step 4: Run test and verify pass**

Run: `python -m pytest modern-ilu-bridge/tests/test_gateway_grpc.py -q`

Expected: all tests pass.

### Task 6: CLI And Demo Scripts

**Files:**
- Create: `modern-ilu-bridge/modern_ilu_bridge/apps/registry_server.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/apps/gateway_server.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/apps/legacy_runner.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/apps/rpc_client.py`
- Create: `modern-ilu-bridge/modern_ilu_bridge/apps/run_demo.py`
- Create: `run-modern-bridge-demo.ps1`
- Create: `run-modern-bridge-demo.bat`

- [ ] **Step 1: Write command modules**

Implement small command-line apps for registry, gateway, legacy runner, client, and an orchestrated demo.

- [ ] **Step 2: Write scripts**

Create Windows scripts that run the orchestrated demo.

- [ ] **Step 3: Run full test suite**

Run: `python -m pytest modern-ilu-bridge/tests -q`

Expected: all tests pass.

- [ ] **Step 4: Run demo**

Run: `powershell -NoProfile -ExecutionPolicy Bypass -File .\run-modern-bridge-demo.ps1`

Expected: output contains `Hello! hello from modern gRPC`.

