/**
 * @file AgentNameNormalizer.cpp
 * @brief 别名规范化与校验实现。
 */

#include "AgentNameNormalizer.h"

#include <QChar>
#include <QString>

QString AgentNameNormalizer::normalize(const QString &raw)
{
    // Step 1: Trim whitespace
    QString trimmed = raw.trimmed();
    if (trimmed.isEmpty())
        return QString();

    // Step 2: Reject control characters (Cc), newlines, and commas in the raw input
    for (const QChar &ch : trimmed) {
        // QChar::Other_Control covers Cc (and some others like Cf, Cs, Co, Cn)
        if (ch.category() == QChar::Other_Control)
            return QString();
        if (ch == QLatin1Char('\n') || ch == QLatin1Char('\r'))
            return QString();
        if (ch == QLatin1Char(','))
            return QString();
    }

    // Step 3: NFKD decomposition
    QString decomposed = trimmed.normalized(QString::NormalizationForm_KD);

    // Step 4: Filter non-spacing marks (Mn category) and build cleaned string
    QString filtered;
    filtered.reserve(decomposed.size());
    for (const QChar &ch : decomposed) {
        // Skip non-spacing marks (combining diacritics, etc.)
        if (ch.category() == QChar::Mark_NonSpacing)
            continue;
        filtered.append(ch);
    }

    // Step 5: NFC recomposition (recompose any remaining combining sequences)
    QString recomposed = filtered.normalized(QString::NormalizationForm_C);

    // Step 6: Unicode case folding
    QString result = recomposed.toCaseFolded();

    // Step 7: Length validation
    if (result.isEmpty() || result.size() > kMaxAliasLength)
        return QString();

    return result;
}

QString AgentNameNormalizer::comparisonKey(const QString &normalized)
{
    // The normalized string from normalize() is already case-folded,
    // but toCaseFolded() on an already-folded string is idempotent and cheap.
    return normalized.toCaseFolded();
}

QPair<bool, QString> AgentNameNormalizer::validate(const QString &raw)
{
    // Check 1: empty after trim
    QString trimmed = raw.trimmed();
    if (trimmed.isEmpty())
        return {false, QStringLiteral("alias is empty or only whitespace")};

    // Check 2: control characters
    for (const QChar &ch : trimmed) {
        if (ch.category() == QChar::Other_Control)
            return {false, QStringLiteral("alias contains control characters")};
    }

    // Check 3: newline characters
    for (const QChar &ch : trimmed) {
        if (ch == QLatin1Char('\n') || ch == QLatin1Char('\r'))
            return {false, QStringLiteral("alias contains newline characters")};
    }

    // Check 4: commas
    for (const QChar &ch : trimmed) {
        if (ch == QLatin1Char(','))
            return {false, QStringLiteral("alias contains commas")};
    }

    // Check 5: normalization and length — after passing checks 1-4,
    // the only remaining way normalize() fails is exceeding kMaxAliasLength
    QString normalized = normalize(raw);
    if (normalized.isEmpty())
        return {false, QStringLiteral("alias exceeds maximum length of ")
                    + QString::number(kMaxAliasLength)};

    return {true, QString()};
}
