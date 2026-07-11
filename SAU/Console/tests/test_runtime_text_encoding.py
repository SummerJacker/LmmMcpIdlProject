from pathlib import Path
import re


ROOT = Path(__file__).resolve().parents[1]


def read_text(relative_path: str) -> str:
    return (ROOT / relative_path).read_text(encoding="utf-8")


def test_http_executor_runtime_messages_are_readable_chinese() -> None:
    text = read_text("HttpApiExecutor.cpp")

    assert "[MOCK] stop_all 已停止 %1 台模拟车" in text
    assert "空闲" in text

    for mojibake in (
        "宸插仠姝",
        "鍙版ā鎷熻溅",
        "绌洪棽",
    ):
        assert mojibake not in text


def test_console_mock_registration_message_is_readable_chinese() -> None:
    text = read_text("console.cpp")

    assert "[MOCK] 已注册模拟单元（仅 HTTP/MCP 可控制运动学）：%1" in text

    for mojibake in (
        "宸叉敞鍐屾ā鎷熷崟鍏",
        "HTTP/MCP 鍙",
        "杩愬姩瀛",
    ):
        assert mojibake not in text


def test_visible_qstring_arg_placeholders_are_contiguous() -> None:
    text = read_text("mainwindow.cpp")
    statement = []
    start_line = 1
    failures: list[str] = []

    for line_number, line in enumerate(text.splitlines(), 1):
        if not statement:
            start_line = line_number
        statement.append(line)
        if ";" not in line:
            continue

        joined = "\n".join(statement)
        statement = []
        if ".arg(" not in joined:
            continue

        placeholders = sorted({int(n) for n in re.findall(r"%(\d+)", joined)})
        if not placeholders:
            continue

        expected = list(range(1, max(placeholders) + 1))
        if placeholders != expected:
            failures.append(f"line {start_line}: placeholders {placeholders}, expected {expected}")

    assert failures == []


def test_visible_chinese_does_not_use_qstringliteral() -> None:
    # Qt 5.12 的 QStringLiteral 展开为 u"" str；MSVC 2017 会把其中的
    # 普通字符串片段按系统代码页转换，导致 UTF-8 中文在编译期变成乱码。
    for relative_path in ("mainwindow.cpp", "console.cpp", "HttpApiExecutor.cpp"):
        text = read_text(relative_path)
        for line_number, line in enumerate(text.splitlines(), 1):
            if "QStringLiteral(" not in line:
                continue
            assert not any("\u4e00" <= ch <= "\u9fff" for ch in line), (
                f"{relative_path}:{line_number}: Chinese runtime text must use "
                "QString::fromUtf8, not QStringLiteral"
            )
