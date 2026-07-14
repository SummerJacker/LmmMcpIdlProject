# FastMCP nested argument transport design

## Problem

`deepseek_mcp_client.run_mcp_call` converts each argument with Python string
formatting. Nested dictionaries therefore become Python repr strings with
single quotes. FastMCP expects nested values as JSON and exits before invoking
the MCP tool. The client then reports only stderr, hiding FastMCP's useful
stdout validation error.

## Chosen design

Pass the complete argument mapping through FastMCP's documented
`--input-json` option using `json.dumps(args, ensure_ascii=False)`. Keep
`--json` for machine-readable output. Do not emit per-field `key=value`
arguments, so flat and nested production tools share one serialization path.

On non-zero exit, combine non-empty stdout and stderr into the returned error
message. Stdout comes first because FastMCP writes argument validation errors
there; stderr remains available for server startup and transport diagnostics.

Alternatives rejected:

- JSON-encode only dictionary-valued `key=value` arguments: creates two
  serialization paths and remains fragile for lists and future nested types.
- Replace the CLI subprocess with a persistent in-process MCP client: more
  efficient, but much larger than this targeted bug fix.

## Safety and tests

Unit tests intercept `subprocess.run` and assert exact command construction, so
no Console or vehicle command is sent. A safe live check may use
`moveFollowFormation` only while formation status is IDLE; the Console rejects
it before movement and proves FastMCP parsed the nested target successfully.
