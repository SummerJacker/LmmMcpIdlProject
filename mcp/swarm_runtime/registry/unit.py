from __future__ import annotations

from ..errors import DuplicateRegistrationError, RuntimeRegistrationError, UnitNotFoundError
from ..models import UnitDescriptor
from ..registration import RegistrationJournal


class UnitRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._units: dict[str, UnitDescriptor] = {}
        self._lookup: dict[str, str] = {}

    @staticmethod
    def _key(value: str) -> str:
        return value.strip().casefold()

    def register(self, unit: UnitDescriptor) -> None:
        canonical = self._key(unit.unit_id)
        if not canonical:
            raise RuntimeRegistrationError("unit_id must not be empty")
        lookup_keys = {canonical}
        for alias in unit.aliases:
            key = self._key(alias)
            if not key:
                raise RuntimeRegistrationError("unit alias must not be empty")
            lookup_keys.add(key)
        conflict = next((key for key in lookup_keys if key in self._lookup), None)
        if conflict is not None:
            raise DuplicateRegistrationError(f"unit or alias already registered: {conflict}")

        self._units[canonical] = unit
        for key in lookup_keys:
            self._lookup[key] = canonical
        self._journal.record(
            f"unit:{unit.unit_id}", lambda key=canonical: self._remove(key)
        )

    def _remove(self, canonical: str) -> None:
        self._units.pop(canonical, None)
        for key, owner in tuple(self._lookup.items()):
            if owner == canonical:
                self._lookup.pop(key, None)

    def resolve(self, unit_id_or_alias: str) -> UnitDescriptor:
        canonical = self._lookup.get(self._key(unit_id_or_alias))
        if canonical is None:
            raise UnitNotFoundError(unit_id_or_alias)
        return self._units[canonical]

    def list(self) -> tuple[UnitDescriptor, ...]:
        return tuple(sorted(self._units.values(), key=lambda unit: unit.unit_id))
