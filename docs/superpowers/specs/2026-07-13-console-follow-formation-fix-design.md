# Console Follow Formation Fix Design

## Scope

Fix continuous ground-vehicle follow formation setup in Console without changing
the five protected IDL files or any vehicle-side program.

## Required behavior

- Follower order defines a chain. For leader `GV1` and followers
  `[GV2, GV3]`, the parent relationships are `GV2 -> GV1` and `GV3 -> GV2`.
- Role, parent `ALeader`, Follow mode, and `FW_Object` minor mode are configured
  before formation topology is dispatched.
- `setFormationWithResult`, and therefore `setRearVehicles`, is the final
  physical setup step. No later role/mode call may clear the vehicle-side
  `sendPoint` threads started by `setRearVehicles`.
- READY remains contingent on every member setup RPC succeeding.
- Existing HTTP and ILU/RPC contracts remain unchanged.

## Implementation

Add a small pure helper that maps an ordered member list to each member's direct
parent. Use that mapping while configuring followers. Move the existing member
mode-configuration loop before formation construction/dispatch and remove the
post-dispatch mode reconfiguration.

## Tests

- Verify the parent mapping for a three-vehicle chain.
- Verify the leader has no parent and invalid/duplicate input is rejected.
- Add a source-level ordering regression test if the existing test harness cannot
  inject ILU RPC calls: mode setup must precede formation dispatch, with no
  `configureUnitMode` call after dispatch.
- Run the focused Console formation tests, followed by the available Console test
  suite.
