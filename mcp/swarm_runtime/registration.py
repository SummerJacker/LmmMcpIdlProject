from __future__ import annotations

from contextlib import contextmanager
from dataclasses import dataclass, field
from typing import Callable, Iterator

from .errors import RuntimeRegistrationError


Undo = Callable[[], None]


@dataclass
class RegistrationTransaction:
    plugin_id: str
    provisions: set[str] = field(default_factory=set)
    _undos: list[Undo] = field(default_factory=list)
    _rolled_back: bool = False

    def record(self, token: str, undo: Undo) -> None:
        if self._rolled_back:
            raise RuntimeRegistrationError("registration transaction is closed")
        self.provisions.add(token)
        self._undos.append(undo)

    def rollback(self) -> None:
        if self._rolled_back:
            return
        for undo in reversed(self._undos):
            undo()
        self._rolled_back = True


class RegistrationJournal:
    def __init__(self) -> None:
        self._active: RegistrationTransaction | None = None

    def record(self, token: str, undo: Undo) -> None:
        if self._active is not None:
            self._active.record(token, undo)

    @contextmanager
    def activate(self, plugin_id: str) -> Iterator[RegistrationTransaction]:
        if self._active is not None:
            raise RuntimeRegistrationError("nested plugin registration is not supported")
        transaction = RegistrationTransaction(plugin_id)
        self._active = transaction
        try:
            yield transaction
        except Exception:
            transaction.rollback()
            raise
        finally:
            self._active = None
