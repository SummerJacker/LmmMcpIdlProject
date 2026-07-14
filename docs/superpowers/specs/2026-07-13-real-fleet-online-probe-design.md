# Real fleet online probe design

## Goal

Make `getFleetSnapshot` distinguish a real ILU binding from a real vehicle that
has been verified online, so the Console follow-formation wizard can use GV1 and
GV3 when their read-only RPCs are actually reachable.

## Scope

- Keep all existing base IDLs and vehicle-side programs unchanged.
- Keep runtime `mock`/`real` classification based on the Console binding.
- Change GV3's deployment intent in `mcp/robots.json` from `sim` to `real`.
- Do not add SSH-based discovery or use vehicle credentials. Runtime
  communication remains ILU/RPC through the Console naming/binding system.

## Behavior

For each unit returned by `GET /api/task/fleet_snapshot`:

- Mock units retain their simulator-provided `online` state and set
  `online_verified=true`.
- Real ground units are probed with the existing read-only
  `Ground_Unit_rpc_getCurrentPose` path when `SAU_ENABLE_REAL_RPC=1`.
- A successful probe returns `online=true` and `online_verified=true`.
- A failed probe returns `online=false`, `online_verified=true`, and a concise
  probe error; it must not be reported online.
- When real RPC is disabled, no probe is attempted and the unit returns
  `online=false`, `online_verified=false`, `rpc_available=false`.
- Non-ground real units remain unverified by this ground-vehicle task probe.

The probe is synchronous because this is the approved minimal implementation.
It may make the snapshot wait for an unavailable ILU endpoint; the existing MCP
HTTP timeout remains the outer safety limit. An asynchronous status cache is a
future improvement and is not part of this change.

## Data flow

`getFleetSnapshot` uses `LegacyIdlAdapter::currentPose`, which already maps real
ground units to `Ground_Unit_rpc_getCurrentPose` and Mock units to simulator
state. The MCP adapter preserves the returned online fields. The deterministic
follow wizard continues to accept only units whose `online` value is exactly
`true`.

## Tests

- Static C++ route test verifies real ground units use the existing pose probe
  and do not remain hard-coded offline.
- Python tests verify GV3 is configured with deployment mode `real`.
- Existing protected-IDL hashes, task architecture tests, Console C++ tests,
  and follow-wizard tests remain green.
- A final read-only live check calls fleet snapshot and confirms GV1/GV3 are
  verified online against the running Console; no movement RPC is sent.
