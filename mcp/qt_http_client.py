"""
QT 端 HTTP 客户端（同步请求封装）。

文件作用：由 `RobotAdapter` 在线程池中调用，向主控台 HttpPlugin 或演示 `qt_http_server`
发送 JSON 请求（GET/POST）。

修改原因：与 SAU 主控台多路由对齐（sendmove / stop / status / list），统一超时与错误处理。
"""

from __future__ import annotations

import json
from typing import Any

import requests

from config import QT_HTTP_TIMEOUT_S


def http_request(
    *,
    method: str,
    url: str,
    json_body: dict[str, Any] | None = None,
    timeout: float | None = None,
) -> tuple[int, dict[str, Any] | None, str]:
    """
    发送一次 HTTP 请求并解析 JSON 响应体（若存在）。

    @param method: "GET" 或 "POST"
    @param url: 完整 URL（GET 可将 query 已拼在 url 上）
    @param json_body: POST 时作为 application/json 发送；GET 忽略
    @param timeout: 超时秒数，默认 config.QT_HTTP_TIMEOUT_S
    @returns: (http_status_code, response_json_or_none, error_hint)
    """

    t = timeout if timeout is not None else QT_HTTP_TIMEOUT_S
    m = method.upper()
    try:
        if m == "GET":
            resp = requests.get(url, timeout=t)
        elif m == "POST":
            resp = requests.post(
                url,
                json=json_body,
                headers={"Content-Type": "application/json; charset=utf-8"},
                timeout=t,
            )
        else:
            return -1, None, f"unsupported HTTP method: {method}"
    except requests.Timeout:
        return -1, None, f"HTTP request timed out after {t} s"
    except requests.RequestException as e:
        return -1, None, f"HTTP request failed: {e}"

    body: dict[str, Any] | None = None
    try:
        if resp.text.strip():
            body = resp.json()
    except json.JSONDecodeError:
        return resp.status_code, None, f"Invalid JSON in response: {resp.text[:200]}"

    return resp.status_code, body, ""


def post_send_move(*, url: str, payload: dict[str, Any], timeout: float | None = None) -> tuple[int, dict[str, Any] | None, str]:
    """
    兼容旧调用：POST sendmove URL。

    @param url: 完整 URL
    @param payload: JSON 请求体
    @param timeout: 超时
    @returns: 同 http_request
    """

    return http_request(method="POST", url=url, json_body=payload, timeout=timeout)
