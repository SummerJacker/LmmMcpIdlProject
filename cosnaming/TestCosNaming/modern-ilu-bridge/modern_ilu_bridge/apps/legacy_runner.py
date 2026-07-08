from __future__ import annotations

import argparse
import time
from pathlib import Path

from modern_ilu_bridge.grpc_registry import RegistryClient, data_to_proto
from modern_ilu_bridge.legacy_hello import LegacyHelloRunner, build_legacy_hello_record


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run and register a legacy ILU hello-world service.")
    parser.add_argument("--registry", default="127.0.0.1:50051")
    parser.add_argument("--service-dir", required=True)
    parser.add_argument("--name", default="legacy.hello-world.c")
    parser.add_argument("--language", default="c", choices=["c", "java", "python", "lisp"])
    parser.add_argument("--heartbeat-seconds", type=float, default=5.0)
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    runner = LegacyHelloRunner(Path(args.service_dir))
    client = RegistryClient(args.registry)
    try:
        sbh = runner.start()
        record = build_legacy_hello_record(args.name, args.language, sbh, Path(args.service_dir))
        response = client.register(data_to_proto(record))
        if not response.ok:
            print(f"registration failed: {response.message}")
            return 1
        print(f"registered {args.name}: {sbh}")
        while True:
            time.sleep(args.heartbeat_seconds)
            heartbeat = client.heartbeat(args.name)
            if not heartbeat.ok:
                print(f"heartbeat failed: {heartbeat.message}")
    except KeyboardInterrupt:
        client.deregister(args.name)
        return 0
    finally:
        runner.stop()
        client.close()


if __name__ == "__main__":
    raise SystemExit(main())

