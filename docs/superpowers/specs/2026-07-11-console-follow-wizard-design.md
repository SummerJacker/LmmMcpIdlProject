# Deterministic Console Follow Formation Wizard Design

## Goal

Replace LLM-driven parameter collection for Console follow formation with a deterministic client-side wizard. The wizard must reproduce the Console operation order:

1. discover online vehicles;
2. select and set the Leader;
3. determine ordered Followers;
4. collect spacing for every Follower;
5. confirm and send the formation once;
6. collect a target point and move only the Leader.

Geometric formation remains an LLM-orchestrated, separate mode.

## Root cause addressed

The current client selects the correct formation mode but then delegates form collection back to the LLM. Runtime evidence shows three failure modes:

- clarification prose is rejected because `call_llm()` accepts JSON only;
- replies such as `0.5` or `每架都设置成0.5米` are not associated with the pending spacing question;
- the LLM can emit an invalid argument such as `set_leader(unit_id="GV1")` instead of `robot_id`.

The fix moves Console-follow workflow state and tool argument construction out of the LLM.

## Wizard state model

`FormationDialogState` gains an explicit follow-wizard phase and collected slots:

```text
IDLE
  -> DISCOVERING_UNITS
  -> AWAITING_LEADER
  -> AWAITING_FOLLOWER_ORDER       only when more than one Follower exists
  -> AWAITING_SPACING
  -> AWAITING_SEND_CONFIRMATION
  -> READY_FOR_TARGET
```

The state stores:

- currently discovered online ground-unit IDs;
- selected Leader ID;
- ordered Follower IDs;
- one requested spacing per Follower;
- whether uniform spacing is being used;
- whether formation dispatch succeeded.

Changing the Leader or restarting formation clears downstream Follower, spacing, and target state.

## Interaction flow

### Entry and discovery

After the user chooses `1. Console 跟随编队`, the client calls `list_robots` directly and parses the returned units. It does not ask the LLM to choose a tool.

If fewer than two online ground vehicles exist, the wizard reports the problem and returns to `IDLE` without setting a Leader.

Otherwise it displays the available IDs and asks the user to choose the Leader.

### Leader and Followers

The Leader reply accepts a listed `GV*` ID or its known `robot_id`. The client resolves it against the discovery result and calls:

```text
set_leader(robot_id=<selected ID>)
```

For exactly two vehicles, the remaining vehicle automatically becomes the sole Follower. For three or more vehicles, the client asks for the ordered Follower list and validates that every listed ID is unique, online, and not the Leader.

### Spacing collection

While the wizard is awaiting spacing, the input is interpreted in the context of the pending question. Accepted two-vehicle examples include:

```text
0.5
0.5米
间距0.5米
都设置成0.5米
```

For multiple Followers, the user may provide either:

- uniform spacing: `都设置成0.5米`;
- per-Follower spacing: `GV2 0.5米，GV3 0.8米`.

A bare number is accepted only when there is one Follower. Multi-Follower input must explicitly state uniform application or bind each value to a Follower. All values must be finite and greater than zero.

After collection, the client displays the Leader, ordered Followers, and requested spacing, then asks the user to confirm sending the formation. No formation RPC occurs before confirmation.

### Formation dispatch and target

On confirmation, the client constructs the tool arguments itself:

```json
{
  "leader_id": "GV1",
  "followers_json": "[{\"robot_id\":\"GV2\",\"distance_m\":0.5}]"
}
```

It calls `send_follow_formation` exactly once. On success, the wizard reports requested and effective Console spacing and enters `READY_FOR_TARGET`.

Target inputs accept forms such as `(5, 6)`, `5,6`, or `前往目标点(5,6)`. The client parses two finite coordinates and calls `goto_follow_formation(x, y)` directly. It never sends individual `goto_pose` calls to Followers.

On dispatch failure, the wizard preserves the collected parameters for inspection but performs no automatic retry, reset, cancellation, or stop. Only an explicit user recovery command is allowed.

## LLM response compatibility

Outside deterministic wizard steps, `call_llm()` continues to prefer the documented JSON tool protocol. If the model returns nonempty prose instead of JSON, the client converts it to a terminal conversational response equivalent to:

```json
{"done": true, "message": "<model prose>"}
```

This prevents clarification text from terminating the client loop. Empty responses remain errors.

At the generic tool boundary, unambiguous legacy aliases may be normalized defensively. In particular, `set_leader` with `unit_id` is rewritten to `robot_id` only when `robot_id` is absent. Conflicting argument names are rejected rather than guessed.

## Boundaries and ownership

- The wizard owns only conversational slots and phase transitions.
- Console remains authoritative for Leader state, formation readiness, effective spacing, and vehicle execution.
- MCP tools and `RobotAdapter` remain the only execution path from the client to Console.
- The wizard must parse actual MCP result envelopes rather than assuming a successful subprocess means a successful Console operation.
- Geometric formation behavior and tools are unchanged.

## Error handling

- Invalid Leader: show valid choices and remain in `AWAITING_LEADER`.
- Leader RPC failure: report the real tool error and remain in `AWAITING_LEADER`.
- Invalid Follower order: explain the invalid or missing IDs and ask again.
- Invalid spacing: state the accepted format and remain in `AWAITING_SPACING`.
- Rejected confirmation: retain collected values and allow editing or cancellation.
- Formation failure: show the Console error without autonomous recovery.
- Invalid target: ask again without calling a tool.
- Target failure: preserve `READY_FOR_TARGET` so the user can explicitly retry or choose another target.

## Verification

Automated tests must reproduce the reported transcript and cover:

1. mode `1` immediately discovers vehicles and asks for a Leader;
2. two vehicles automatically produce one Follower;
3. a pending spacing question accepts `0.5` without a unit;
4. `每架都设置成0.5米` applies uniform spacing;
5. multi-Follower bare spacing remains rejected;
6. the wizard constructs `set_leader(robot_id=...)` itself;
7. confirmation constructs the exact `send_follow_formation` payload once;
8. a successful send enters `READY_FOR_TARGET`;
9. a target calls only `goto_follow_formation`;
10. non-JSON LLM clarification text is displayed rather than raised;
11. `set_leader(unit_id=...)` is normalized only when unambiguous;
12. existing geometric-formation and safety tests remain green.

## Out of scope

- Changing Console follow-control algorithms or minimum spacing.
- Changing the Console HTTP API implemented by the previous formation-mode work.
- Adding geometric shapes or changing geometric formation planning.
- Automatically choosing a Leader without user confirmation.
- Automatically retrying failed formation or movement commands.
