from __future__ import annotations

import logging

from ..errors import (
    AmbiguousUnitResolutionError,
    DuplicateRegistrationError,
    RuntimeRegistrationError,
    UnitNotFoundError,
)
from ..models import UnitDescriptor
from ..protocols import UnitResolver
from ..registration import RegistrationJournal


class UnitResolverRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._resolvers: dict[str, UnitResolver] = {}
        self._logger = logging.getLogger("swarm_runtime.registry.unit_resolver")

    def register(self, resolver: UnitResolver) -> None:
        raw_resolver_id = getattr(resolver, "resolver_id", None)
        if not isinstance(raw_resolver_id, str) or not raw_resolver_id.strip():
            raise RuntimeRegistrationError(
                "resolver_id must be a nonempty string"
            )
        resolver_id = raw_resolver_id.strip()
        priority = getattr(resolver, "priority", None)
        if not isinstance(priority, int) or isinstance(priority, bool):
            raise RuntimeRegistrationError("resolver priority must be an integer")
        if not callable(getattr(resolver, "resolve", None)):
            raise RuntimeRegistrationError("resolver resolve must be callable")
        if resolver_id in self._resolvers:
            raise DuplicateRegistrationError(
                f"unit resolver already registered: {resolver_id}"
            )
        self._resolvers[resolver_id] = resolver
        self._journal.record(
            f"unit_resolver:{resolver_id}",
            lambda key=resolver_id: self._resolvers.pop(key, None),
        )

    def list(self) -> tuple[UnitResolver, ...]:
        return tuple(self._resolvers[key] for key in sorted(self._resolvers))

    async def resolve(self, unit_id: str) -> UnitDescriptor:
        candidates: list[tuple[int, str, UnitDescriptor]] = []
        for resolver_id in sorted(self._resolvers):
            resolver = self._resolvers[resolver_id]
            try:
                candidate = await resolver.resolve(unit_id)
                if candidate is not None and not isinstance(
                    candidate, UnitDescriptor
                ):
                    self._logger.error(
                        "unit resolver %s returned invalid descriptor",
                        resolver_id,
                    )
                    continue
            except Exception:
                self._logger.exception("unit resolver %s failed", resolver_id)
                continue
            if candidate is not None:
                candidates.append((resolver.priority, resolver_id, candidate))

        if not candidates:
            raise UnitNotFoundError(unit_id)

        candidates.sort(key=lambda candidate: (-candidate[0], candidate[1]))
        if len(candidates) > 1 and candidates[0][0] == candidates[1][0]:
            raise AmbiguousUnitResolutionError(unit_id)
        return candidates[0][2]
