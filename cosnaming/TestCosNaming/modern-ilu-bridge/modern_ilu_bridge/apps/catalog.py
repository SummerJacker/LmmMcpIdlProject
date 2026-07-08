from __future__ import annotations

import argparse
from pathlib import Path

from modern_ilu_bridge.legacy_catalog import (
    LegacyCatalogSummary,
    build_default_hello_world_catalog,
    summarize_catalog,
)


def format_summary_rows(rows: list[LegacyCatalogSummary]) -> str:
    lines = [
        "Legacy ILU compatibility catalog",
        "LANG     STATE    SERVICE                         DETAILS",
    ]
    for row in rows:
        state = "READY" if row.ready else "MISSING"
        lines.append(f"{row.language:<8} {state:<8} {row.name:<31} {row.reason}")
    return "\n".join(lines)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Show legacy ILU multi-language compatibility status.")
    parser.add_argument(
        "--repo-root",
        default=str(Path(__file__).resolve().parents[3]),
        help="Repository root containing Iluhome.",
    )
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    catalog = build_default_hello_world_catalog(Path(args.repo_root))
    print(format_summary_rows(summarize_catalog(catalog)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

