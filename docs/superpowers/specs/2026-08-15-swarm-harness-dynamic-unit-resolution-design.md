# Swarm Harness Dynamic Unit Resolution Design

## Purpose

This document amends the Path and Stop Plugin design after production-compatibility
review found that runtime-owned tools reject units bound to the Console after MCP
startup. The legacy RobotAdapter resolves those direct canonical UnitIDs through
the live Console directory when they are absent from `robots.json`. The current
CapabilityExecutor instead requires every unit to exist in the startup
UnitRegistry before a KIS-ORB provider can run.

The amendment adds a platform-neutral asynchronous Unit Resolver extension point.
Static unit registration remains authoritative when present; dynamic resolution is
only a fallback for identifiers missing from the static registry.

## Root Cause and Required Compatibility

The existing production path resolves a requested identifier in this order:

1. configured `robots.json` alias or UnitID;
2. an injected AgentResolver, when present;
3. the authoritative Console `list_robots()` response for a direct canonical
   UnitID bound at runtime.

The first plugin slice registered only configured units. CapabilityExecutor calls
`UnitRegistry.resolve()` before provider selection, so a runtime-bound unit never
reaches RobotAdapter's live-directory fallback. This affects `navigateTo`,
`followPath`, and `stopUnits`; for Stop it can suppress a physical safety request.

Compatibility requires runtime-owned tools to accept a supported direct canonical
UnitID that is absent from `robots.json` but present in the current Console binding
table. Navigate and FollowPath accept KIS-ORB ground descriptors derived from
uppercase `G*` UnitIDs. Stop accepts both uppercase `G*` and `A*` KIS-ORB UnitIDs,
including mixed UGV/UAV requests on that one platform. Unknown identifiers and
unsupported canonical prefixes must still return complete rejected TaskResults.

## Architecture

Add a focused asynchronous registry beside the existing static UnitRegistry:

```text
ExecutionRequest unit IDs
        |
        v
Request-local map keyed by strip().casefold()
        |
        v
Static UnitRegistry.resolve()
        |
        +-- found --> configured UnitDescriptor
        |
        +-- missing
              |
              v
      UnitResolverRegistry.resolve()
              |
              +-- KIS-ORB live resolver --> temporary UnitDescriptor
              +-- no result ------------> UNIT_NOT_FOUND
        |
        v
ProviderRegistry -> policies -> provider execution
```

Each strip- and casefold-equivalent logical identifier is resolved once per
ExecutionRequest. The executor then reconstructs the UnitDescriptor tuple in the
request's original order and multiplicity. This memo is request-local; it is not a
cache and never mutates UnitRegistry.

Runtime Core gains a `UnitResolver` protocol, a UnitResolverRegistry, one context
field, and asynchronous fallback in CapabilityExecutor. It does not import KIS-ORB,
RobotAdapter, ConsoleTaskClient, configuration, or SAU modules.

This is the sole exception to the previous phase-two constraint that Runtime Core
files remain unchanged. SAU Console, IDLs, RobotAdapter, ConsoleTaskClient, existing
static unit semantics, and external MCP/Console call contracts remain unchanged.
An approved safety amendment tightens KIS-ORB Navigate/Follow provider selection to
`kind == "ugv"`; KIS-ORB Stop remains platform-wide.

## Unit Resolver Contract

A resolver exposes:

```python
class UnitResolver(Protocol):
    resolver_id: str
    priority: int

    async def resolve(self, unit_id_or_alias: str) -> UnitDescriptor | None: ...
```

The resolver returns a fully formed UnitDescriptor when it owns the identifier or
`None` to abstain. Platform resolvers may perform I/O. They must not register the
returned descriptor in UnitRegistry.

The registry enforces non-empty string resolver IDs, integer priorities (excluding
booleans), and callable `resolve` members. It snapshots the validated resolver ID
and priority at registration, so later mutation of plugin object attributes cannot
change selection order or ambiguity. It uses the existing RegistrationJournal so
plugin setup rollback and unload remove resolver registrations. Provision tokens
use `unit_resolver:<resolver_id>`.

Resolution semantics are deterministic:

1. CapabilityExecutor first calls the synchronous static UnitRegistry;
2. only `UnitNotFoundError` triggers asynchronous resolver fallback;
3. every resolver may return a candidate or abstain;
4. the candidate from the highest integer priority wins;
5. equal highest-priority candidates are rejected as ambiguous;
6. no candidate raises UnitNotFoundError for the original requested identifier;
7. strip- and casefold-equivalent IDs in one ExecutionRequest reuse the first
   resolved descriptor while preserving tuple order and multiplicity.

An ambiguous dynamic resolution uses `UNIT_NOT_FOUND`, because the runtime cannot
establish one canonical unit identity safely. Resolver exceptions are logged with
the resolver ID but treated as abstentions. If no resolver succeeds, the external
result remains `UNIT_NOT_FOUND`; exception details and stack traces are not exposed.

Static registrations always win and do not invoke dynamic resolvers. This preserves
configured aliases, avoids network calls on the normal path, and prevents a
platform resolver from overriding an explicitly registered unit.

## KIS-ORB Live Resolver

`platform.kisorb-sau` adds `KisorbLiveUnitResolver` in its own package. The resolver
receives the shared RobotAdapter constructed by the plugin and calls its public
`list_robots()` method. It parses the standard response envelope and reads
`data.units`. Each Console list entry exposes only the canonical `unit_id` and
`mock` flag; it does not provide a trustworthy unit-kind field.

Resolution matches the requested identifier, after trim and case folding, against
each non-empty string `unit_id`. Kind is derived only from the Console's canonical
spelling: uppercase `G*` maps to `ugv`, uppercase `A*` maps to `uav`, and an unknown
or lowercase canonical prefix makes the resolver abstain. A supported match returns:

```text
UnitDescriptor(
  unit_id=<Console canonical spelling>,
  kind=<"ugv" for uppercase G*; "uav" for uppercase A*>,
  platform="kisorb-sau",
  provider_plugin_id="platform.kisorb-sau",
  aliases=(),
  metadata={source: "console-live"}
)
```

Configured robot aliases continue to resolve statically. The current default
production bootstrap does not inject AgentResolver, so this amendment preserves the
existing live fallback for direct canonical UnitIDs without adding new alias
semantics.

Invalid JSON, an unsuccessful envelope, missing `data.units`, malformed entries, an
empty request, no matching UnitID, or a matched canonical ID with an unknown or
lowercase prefix returns `None`. The resolver does not cache across requests or
mutate UnitRegistry, so binding removal and changes remain visible on subsequent
requests. The executor only memoizes equivalent IDs within one request. In a mocked
provider integration, Navigate, FollowPath, and duplicate-ID Stop therefore perform
three resolver directory calls total. That count is not a public contract: the full
RobotAdapter/provider path may perform its own authoritative lookup before the
Console operation.

## KIS-ORB Provider Selection Safety Amendment

The live resolver's descriptor kind participates in provider selection:

- KIS-ORB Navigate and FollowPath require exactly one `kisorb-sau` unit whose kind
  is `ugv`; a live `A*`/`uav` descriptor is rejected as unsupported.
- KIS-ORB Stop requires one or more `kisorb-sau` units and intentionally does not
  restrict kind, so same-platform UGV/UAV mixtures can still receive Stop.
- A mixed KIS-ORB/Mock Stop remains unsupported because one provider must support
  the entire multi-unit tuple.

The KIS-ORB plugin registers the resolver against the same RobotAdapter instance
used by its providers and the eleven legacy tools. Its manifest adds:

```text
unit_resolver:kisorb.live
```

The Mock platform requires no resolver because its units are explicit profile-owned
test fixtures.

## Error and Lifecycle Semantics

- Static unknown plus live match: continue with the temporary canonical descriptor.
- Static unknown plus no live match: `UNIT_NOT_FOUND` / `REJECTED`.
- Malformed or failed live-directory response: `UNIT_NOT_FOUND` / `REJECTED`.
- Resolver exception: log internally, abstain, and return `UNIT_NOT_FOUND` if no
  other resolver succeeds.
- Equal-priority resolver candidates: deterministic `UNIT_NOT_FOUND` / `REJECTED`.
- Policy ordering and external provider call contracts are unchanged; provider
  eligibility follows the approved kind-aware safety amendment above.

Temporary descriptors are request-scoped values. They create no registration undo
entries, survive no request boundary, and cannot leak after plugin unload. Resolver
registrations themselves are provision-checked and rolled back with their owning
plugin.

## Testing Strategy

Implementation follows red-green-refactor cycles.

Runtime unit tests cover:

- unique resolver registration and registration rollback;
- static UnitRegistry precedence without calling a resolver;
- asynchronous fallback returning a temporary descriptor;
- priority selection and equal-priority ambiguity;
- registration-time priority validation and immutable selection snapshots;
- resolver exceptions treated as abstentions without leaked messages;
- no successful fallback preserving the original UnitNotFoundError;
- no mutation of the static UnitRegistry after dynamic resolution;
- one resolution per strip- and casefold-equivalent ID within an ExecutionRequest,
  with descriptor tuple order and multiplicity preserved.

KIS-ORB tests cover:

- case-insensitive direct canonical UnitID matching from `list_robots()`;
- uppercase `G*`/`A*` kind derivation and lowercase/unknown-prefix abstention;
- canonical spelling and platform metadata in the returned descriptor;
- malformed, unsuccessful, missing, and non-matching responses abstaining;
- plugin registration, manifest provision, rollback, and shared-adapter identity;
- Navigate/Follow UGV-only selection and same-platform mixed-kind Stop support.

Production integration tests patch the shared adapter's live directory and prove:

- `navigateTo` accepts a live-bound unit absent from `robots.json`;
- `followPath` accepts it and forwards the canonical UnitID;
- `stopUnits` accepts it, preserves canonical de-duplication, and issues Stop;
- a live UAV is rejected by Navigate/Follow but remains eligible for KIS-ORB Stop;
- duplicate logical Stop IDs perform one resolver lookup within that request;
- an absent unit still returns a complete rejected `UNIT_NOT_FOUND` TaskResult;
- configured aliases continue to resolve without live-directory lookup;
- the default and Mock tool sets remain exactly fourteen names.

Final verification reruns syntax checks, FastMCP version validation, the complete
non-live Python suite, import-boundary audits, and protected-path diffs. IDL SHA-256
remains `2EA71279A5FD8C0AD1157ED38F5EA7E04621EF439DB16E86CBEA65FEDB625F1A`.

## Scope and Completion Criteria

Expected implementation files are limited to Runtime unit-resolution protocol,
registry, context, executor and tests; the KIS-ORB resolver, plugin, manifest,
kind-aware KIS-ORB provider predicates and tests; runtime integration tests; and the
phase documentation. RobotAdapter, ConsoleTaskClient, SAU Console, IDLs, Mock
provider behavior, and public MCP schemas remain unchanged.

This amendment is complete when supported live-bound canonical UnitIDs preserve the
legacy behavior, Navigate/Follow reject non-UGV KIS-ORB descriptors, same-platform
mixed-kind Stop remains available, resolver selection is deterministic and
transactional, equivalent IDs resolve once per request, no dynamic descriptor
pollutes static state, all previous plugin acceptance tests pass, and protected
paths remain unchanged.
