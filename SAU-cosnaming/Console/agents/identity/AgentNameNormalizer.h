/**
 * @file AgentNameNormalizer.h
 * @brief 别名规范化与校验工具。
 *
 * 负责将用户输入的原始别名转换为统一的规范化形式（NFKC + case-folded），
 * 并生成用于冲突检测的比较键。同时提供完整的校验管道。
 *
 * 版本: 1.0
 */

#ifndef AGENT_NAME_NORMALIZER_H
#define AGENT_NAME_NORMALIZER_H

#include <QPair>
#include <QString>

class AgentNameNormalizer {
public:
    /**
     * @brief 规范化别名：trim → NFKC → case-fold。
     * @param raw 用户输入的原始别名。
     * @return 规范化后的别名；若无效则返回空字符串。
     *
     * 处理流程：
     *   1. 执行 trimmed() 去除首尾空白。
     *   2. 遍历每个 QChar，获取 NFKD 分解，过滤非间距标记（Mn 类），再重组为 NFKC。
     *   3. 执行 toCaseFolded() 进行 Unicode 大小写折叠。
     *   4. 拒绝控制字符（Unicode 类别 Cc）、换行符、逗号。
     *   5. 拒绝空字符串或超过 kMaxAliasLength 的结果。
     */
    static QString normalize(const QString &raw);

    /**
     * @brief 生成用于唯一性检查的比较键。
     * @param normalized 已规范化的别名（由 normalize() 输出）。
     * @return 比较键（在 normalize 基础上再做一次 case-fold，确保幂等）。
     *
     * compareKey(normalize(raw)) 用于冲突检测：任何两个在视觉上不可区分的别名应产生相同的比较键。
     */
    static QString comparisonKey(const QString &normalized);

    /**
     * @brief 校验原始别名。
     * @param raw 用户输入的原始别名。
     * @return (true, "") 表示有效；(false, reason) 表示无效及其具体原因。
     *
     * 校验顺序（短路）：
     *   1. trimmed() 后为空 → "alias is empty or only whitespace"
     *   2. 包含控制字符 → "alias contains control characters"
     *   3. 包含换行符（LF/CR） → "alias contains newline characters"
     *   4. 包含逗号 → "alias contains commas"
     *   5. normalize() 后超过 kMaxAliasLength → "alias exceeds maximum length of N"
     */
    static QPair<bool, QString> validate(const QString &raw);

    /** @brief 规范化后的最大长度 */
    static constexpr int kMaxAliasLength = 32;
};

#endif // AGENT_NAME_NORMALIZER_H
