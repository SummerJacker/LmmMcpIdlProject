# Modern ILU Bridge Design

## Goal

Build a modern gRPC-based RPC and service registry platform that keeps compatibility with the existing ILU/CosNaming project. The first working version bridges the existing C `hello-world` ILU service into a modern registry and gateway, while preserving registration fields for Java, Python, and Lisp ILU services.

## Scope

The first version must:

- Run a modern gRPC registry.
- Run a modern gRPC gateway.
- Start or attach to the legacy C `hello-world\WinRel\server.exe`.
- Read the legacy SBH from `SBHtempfile.tex`.
- Register the service as `legacy.hello-world.c`.
- Record language, protocol, interface, endpoint, method list, and health status.
- Invoke the old C ILU service through the existing `client.exe`.
- Return the legacy response through a modern gRPC client.
- Keep the model extensible for `c`, `java`, `python`, and `lisp`.

The first version does not need to run Java, Python, or Lisp legacy services yet.

## Architecture

```text
Modern gRPC client
  -> gateway-server
  -> legacy hello adapter
  -> legacy C client.exe
  -> legacy C server.exe
  -> "Hello! <message>"

legacy-runner
  -> starts legacy C server.exe
  -> reads SBHtempfile.tex
  -> registers legacy.hello-world.c with registry-server

registry-server
  -> stores service records in memory
  -> supports register, heartbeat, deregister, discover, list
```

## Service Record

Each service record contains:

- `name`: stable service name, such as `legacy.hello-world.c`.
- `language`: one of `c`, `java`, `python`, `lisp`, or `modern`.
- `protocol`: `ilu-sbh`, `ilu-ior`, or `grpc`.
- `interface_name`: legacy or modern interface name.
- `endpoint`: SBH, IOR, or gRPC host:port.
- `methods`: method names exposed by the service.
- `status`: `HEALTHY`, `STALE`, or `UNKNOWN`.
- `metadata`: extra key/value information.
- `last_seen_unix`: heartbeat timestamp.

## First Compatibility Adapter

The first adapter supports:

- Interface: `hello_world.service`
- Method: `hello_world`
- Protocol: `ilu-sbh`
- Language: `c`

It invokes the existing C client executable with the stored SBH, pipes the input message followed by `exit`, captures stdout, and extracts the `Hello! ...` response.

## Testing

Tests cover:

- Registry store registration, discovery, list, heartbeat, and deregistration.
- gRPC registry server round trip.
- Legacy hello response extraction from old client stdout.
- Gateway invocation using a fake invoker.
- End-to-end demo behavior where feasible without requiring Java/Python/Lisp runtimes.

## Running

The project provides:

- `run-modern-bridge-demo.bat`: one-command demo.
- `run-modern-bridge-demo.ps1`: PowerShell demo runner.
- Python module commands for registry server, gateway server, legacy runner, and rpc client.

