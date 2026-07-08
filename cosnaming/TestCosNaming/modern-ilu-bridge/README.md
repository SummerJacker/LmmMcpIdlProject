# Modern ILU Bridge

This project modernizes the old ILU/CosNaming idea as a gRPC registry and gateway while keeping legacy ILU compatibility.

The first version supports:

- Modern gRPC registry.
- Modern gRPC gateway.
- Legacy C ILU `hello-world` service discovery.
- Legacy C ILU invocation through the existing `client.exe`.
- Service metadata for future C, Java, Python, and Lisp ILU adapters.

## One-Command Demo

From `E:\CosNaming\TestCosNaming`:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\run-modern-bridge-demo.ps1
```

Expected output includes:

```text
registered service: legacy.hello-world.c language=c protocol=ilu-sbh
modern gRPC invoke result: Hello! hello from modern gRPC
```

The demo starts:

- a modern registry gRPC server,
- a modern gateway gRPC server,
- the old C `hello-world\WinRel\server.exe`,
- then calls the old ILU service through the modern gRPC gateway.

The demo stops its own legacy server before exiting.

## Multi-Language Compatibility Catalog

The bridge keeps C, Java, Python, and Lisp as first-class legacy ILU languages.
Check the current machine's readiness with:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\show-legacy-catalog.ps1
```

Example output on a machine with only the C legacy binaries ready:

```text
Legacy ILU compatibility catalog
LANG     STATE    SERVICE                         DETAILS
c        READY    legacy.hello-world.c            ready
java     MISSING  legacy.hello-world.java         missing command: java
python   MISSING  legacy.hello-world.python       missing command: python2
lisp     MISSING  legacy.hello-world.lisp         missing command: clisp
```

This means the modern registry can model all four languages now. Actual Java,
Python, and Lisp invocation adapters can be enabled once their old ILU runtimes
are available.

## Service Model

Each service record keeps compatibility metadata:

```text
name           legacy.hello-world.c
language       c | java | python | lisp | modern
protocol       ilu-sbh | ilu-ior | grpc
interface      hello_world.service
endpoint       old SBH / IOR / modern address
methods        hello_world
status         HEALTHY
```

## Commands

Run registry:

```powershell
$env:PYTHONPATH="E:\CosNaming\TestCosNaming\modern-ilu-bridge"
python -m modern_ilu_bridge.apps.registry_server --port 50051
```

Run gateway:

```powershell
$env:PYTHONPATH="E:\CosNaming\TestCosNaming\modern-ilu-bridge"
python -m modern_ilu_bridge.apps.gateway_server --registry 127.0.0.1:50051 --port 50052 --client-exe "E:\CosNaming\TestCosNaming\Iluhome\examples\hello-world\WinRel\client.exe"
```

Run and register the legacy C service:

```powershell
$env:PYTHONPATH="E:\CosNaming\TestCosNaming\modern-ilu-bridge"
python -m modern_ilu_bridge.apps.legacy_runner --registry 127.0.0.1:50051 --service-dir "E:\CosNaming\TestCosNaming\Iluhome\examples\hello-world\WinRel"
```

Invoke through the modern gateway:

```powershell
$env:PYTHONPATH="E:\CosNaming\TestCosNaming\modern-ilu-bridge"
python -m modern_ilu_bridge.apps.rpc_client invoke --gateway 127.0.0.1:50052 --service legacy.hello-world.c --message "hello from modern gRPC"
```

List registered services:

```powershell
$env:PYTHONPATH="E:\CosNaming\TestCosNaming\modern-ilu-bridge"
python -m modern_ilu_bridge.apps.rpc_client list --registry 127.0.0.1:50051
```

Manually register any old ILU SBH or IOR endpoint:

```powershell
$env:PYTHONPATH="E:\CosNaming\TestCosNaming\modern-ilu-bridge"
python -m modern_ilu_bridge.apps.register_legacy `
  --registry 127.0.0.1:50051 `
  --name legacy.hello-world.java `
  --language java `
  --protocol ilu-sbh `
  --interface hello_world.service `
  --endpoint "ilusbh:PUT_OLD_SERVICE_SBH_HERE" `
  --method hello_world
```

## Tests

```powershell
python -m pytest modern-ilu-bridge/tests -q
```
