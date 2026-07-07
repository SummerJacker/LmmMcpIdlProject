"""
DeepSeek OpenAI 兼容接口连通性测试脚本。

文件作用：在 CMD 中快速验证 API Key、base_url、模型名是否可用，便于排查 401 等问题。

修改原因：与 `deepseek_mcp_client.py` 中 requests 直连方式对照，使用官方推荐的 OpenAI Python SDK 调用同一平台。
"""

from __future__ import annotations

import argparse
import os
import sys

# Ensure the parent directory (mcp/) is on sys.path so we can import deepseek_mcp_client
_PARENT_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if _PARENT_DIR not in sys.path:
    sys.path.insert(0, _PARENT_DIR)


def resolve_api_key() -> str:
    """
    解析 API Key：优先环境变量，其次与客户端一致的代码内默认值。

    @returns: 非空 key 字符串；若为空则返回空字符串
    """

    try:
        from deepseek_mcp_client import DEFAULT_DEEPSEEK_API_KEY

        default_key = (DEFAULT_DEEPSEEK_API_KEY or "").strip()
        if default_key:
            return default_key
    except ImportError:
        pass
    env_key = os.getenv("DEEPSEEK_API_KEY", "").strip()
    if env_key:
        return env_key
    return ""


def main() -> int:
    """
    入口：发起一次 chat.completions 请求并打印结果。

    @returns: 0 表示成功，非 0 表示失败
    """

    parser = argparse.ArgumentParser(description="Test DeepSeek API via OpenAI-compatible client.")
    parser.add_argument(
        "--base-url",
        default="https://api.deepseek.com/v1",
        help="OpenAI-compatible base URL (DeepSeek official: https://api.deepseek.com/v1)",
    )
    parser.add_argument(
        "--model",
        default="deepseek-chat",
        help="Model id on DeepSeek, e.g. deepseek-chat or deepseek-reasoner",
    )
    parser.add_argument(
        "--prompt",
        default="请用一句话回复：连通测试成功。",
        help="User message content for the test call",
    )
    parser.add_argument(
        "--stream",
        action="store_true",
        help="Use streaming mode (like official sample)",
    )
    args = parser.parse_args()

    api_key = resolve_api_key()
    if not api_key:
        print(
            "[ERROR] No API key. Set DEEPSEEK_API_KEY or fill DEFAULT_DEEPSEEK_API_KEY in deepseek_mcp_client.py",
            file=sys.stderr,
        )
        return 1

    try:
        from openai import OpenAI
    except ImportError:
        print("[ERROR] Install openai: pip install openai", file=sys.stderr)
        return 1

    import httpx

    http_client = httpx.Client(proxy=None, trust_env=False)  # bypass system proxy
    client = OpenAI(api_key=api_key, base_url=args.base_url.rstrip("/"), http_client=http_client)

    print(f"[INFO] base_url={args.base_url}")
    print(f"[INFO] model={args.model}")
    print(f"[INFO] stream={args.stream}")
    print(f"[INFO] api_key=...{api_key[-4:]}")
    print("---")

    try:
        if args.stream:
            response = client.chat.completions.create(
                model=args.model,
                messages=[{"role": "user", "content": args.prompt}],
                stream=True,
            )
            for chunk in response:
                if not chunk.choices:
                    continue
                delta = chunk.choices[0].delta
                if getattr(delta, "content", None):
                    print(delta.content, end="", flush=True)
                if getattr(delta, "reasoning_content", None):
                    print(delta.reasoning_content, end="", flush=True)
            print()
        else:
            response = client.chat.completions.create(
                model=args.model,
                messages=[{"role": "user", "content": args.prompt}],
                stream=False,
            )
            msg = response.choices[0].message
            text = getattr(msg, "content", None) or ""
            print(text)
        print("---")
        print("[OK] API call finished.")
        return 0
    except Exception as e:
        print(f"[ERROR] {type(e).__name__}: {e}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
