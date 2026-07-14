/**
 * @file SafetyValidator.cpp
 * @brief MCP-IDL 安全校验层实现。
 */

#include "SafetyValidator.h"
#include "TaskManager.h"
#include "console.h"

#include <QtMath>
#include <QDebug>
#include <QSet>

#ifdef __cplusplus
extern "C" {
#endif
#include "iluchdrs.h"
#ifdef __cplusplus
}
#endif

// 外部全局变量 (console.cpp)
extern ilu_HashTable Units_Hash_Table;

// ---- Single GotoPose Validation ----

SafetyValidator::ValidationResult
SafetyValidator::validateGotoPose(const QString &unitId,
                                   double targetX, double targetY,
                                   double linearSpeed, double angularSpeed) {
    ValidationResult result;
    result.passed = true;

    // 1. 坐标有效性
    if (!qIsFinite(targetX) || !qIsFinite(targetY)) {
        result.passed = false;
        result.errorCode = QStringLiteral("TARGET_OUT_OF_BOUNDS");
        result.message = QStringLiteral("target coordinates must be finite numbers");
        return result;
    }

    // 2. unit 是否已绑定
    if (!isUnitBound(unitId)) {
        result.passed = false;
        result.errorCode = QStringLiteral("UNIT_NOT_FOUND");
        result.message = QStringLiteral("unit %1 not bound to console").arg(unitId);
        return result;
    }

    // 3. unit 是否空闲 (没有正在执行的任务)
    if (!isUnitAvailable(unitId)) {
        result.passed = false;
        result.errorCode = QStringLiteral("UNIT_BUSY");
        result.message = QStringLiteral("unit %1 is already executing a task").arg(unitId);
        return result;
    }

    // 4. 速度是否在安全范围内
    if (!isSpeedSafe(linearSpeed, angularSpeed)) {
        result.passed = false;
        result.errorCode = QStringLiteral("SPEED_OUT_OF_BOUNDS");
        result.message = QStringLiteral("speed exceeds max safe limits (linear=%1 angular=%2)")
            .arg(maxLinearSpeedMS(), 0, 'f', 1).arg(maxAngularSpeedRadS(), 0, 'f', 1);
        return result;
    }

    // 5. 目标区域检查 (基本范围, 可扩展为禁行区检测)
    if (!isTargetInBounds(targetX, targetY)) {
        result.passed = false;
        result.errorCode = QStringLiteral("TARGET_OUT_OF_BOUNDS");
        result.message = QStringLiteral("target (%1, %2) is outside allowed area").arg(targetX, 0, 'f', 1).arg(targetY, 0, 'f', 1);
        return result;
    }

    return result;
}

// ---- Batch GotoPose Validation ----

SafetyValidator::ValidationResult
SafetyValidator::validateGotoPoseBatch(const QJsonArray &targets) {
    ValidationResult result;
    result.passed = true;

    if (targets.isEmpty()) {
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("targets array is empty");
        return result;
    }

    if (targets.size() > 10) {
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("batch size %1 exceeds max 10").arg(targets.size());
        return result;
    }

    // 逐一校验每个 target，第一个失败即返回
    QSet<QString> seen;
    for (const QJsonValue &v : targets) {
        if (!v.isObject()) {
            result.passed = false;
            result.errorCode = QStringLiteral("SAFETY_REJECTED");
            result.message = QStringLiteral("each target must be a JSON object");
            return result;
        }
        QJsonObject t = v.toObject();
        QString unitId = t.value("unit_id").toString().trimmed();
        const QJsonValue xValue = t.value(QStringLiteral("x"));
        const QJsonValue yValue = t.value(QStringLiteral("y"));

        if (unitId.isEmpty() || !unitId.startsWith(QLatin1Char('G'))) {
            result.passed = false;
            result.errorCode = QStringLiteral("SAFETY_REJECTED");
            result.message = QStringLiteral("target requires a ground unit_id");
            return result;
        }
        if (seen.contains(unitId)) {
            result.passed = false;
            result.errorCode = QStringLiteral("SAFETY_REJECTED");
            result.message = QStringLiteral("duplicate unit_id in batch: %1").arg(unitId);
            return result;
        }
        seen.insert(unitId);
        if (!xValue.isDouble() || !yValue.isDouble() ||
            !qIsFinite(xValue.toDouble()) || !qIsFinite(yValue.toDouble())) {
            result.passed = false;
            result.errorCode = QStringLiteral("TARGET_OUT_OF_BOUNDS");
            result.message = QStringLiteral("target x/y must be finite numbers");
            return result;
        }

        result = validateGotoPose(unitId, xValue.toDouble(), yValue.toDouble(), 0.0, 0.0);
        if (!result.passed)
            return result;
    }

    return result;
}

// ---- Formation Validation ----

SafetyValidator::ValidationResult
SafetyValidator::validateFormation(const QJsonObject &request) {
    ValidationResult result;
    result.passed = true;

    QString ftype = request.value("formation_type").toString().trimmed().toLower();
    if (ftype != "line" && ftype != "triangle" && ftype != "column") {
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("unknown formation_type: %1 (expected: line, triangle, column)").arg(ftype);
        return result;
    }

    QJsonArray unitIds = request.value("unit_ids").toArray();
    if (unitIds.isEmpty()) {
        // 自动选择: 需要至少 2 个 (line) 或 3 个 (triangle) 可用地面单元
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("unit_ids is empty and auto-selection not yet supported; provide explicit unit_ids");
        return result;
    }

    int n = unitIds.size();
    if (ftype == "line" && n < 2) {
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("line formation requires at least 2 units");
        return result;
    }
    if (ftype == "triangle" && n < 3) {
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("triangle formation requires at least 3 units");
        return result;
    }
    if (ftype == "column" && n < 2) {
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("column formation requires at least 2 units");
        return result;
    }

    double spacing = request.value("spacing_m").toDouble(1.0);
    if (spacing <= 0.0 || spacing > 50.0) {
        result.passed = false;
        result.errorCode = QStringLiteral("SAFETY_REJECTED");
        result.message = QStringLiteral("spacing_m must be > 0 and <= 50");
        return result;
    }

    // Static geometric formation dispatches Ground_Unit.setTaskPoint only.
    QSet<QString> seen;
    for (const QJsonValue &v : unitIds) {
        QString uid = v.toString().trimmed();
        if (!uid.startsWith(QLatin1Char('G'))) {
            result.passed = false;
            result.errorCode = QStringLiteral("UNSUPPORTED_CAPABILITY");
            result.message = QStringLiteral("static formation supports ground units only");
            return result;
        }
        if (seen.contains(uid)) {
            result.passed = false;
            result.errorCode = QStringLiteral("SAFETY_REJECTED");
            result.message = QStringLiteral("duplicate unit_id: %1").arg(uid);
            return result;
        }
        seen.insert(uid);
        if (!isUnitBound(uid)) {
            result.passed = false;
            result.errorCode = QStringLiteral("UNIT_NOT_FOUND");
            result.message = QStringLiteral("unit %1 not bound").arg(uid);
            return result;
        }
        if (!isUnitAvailable(uid)) {
            result.passed = false;
            result.errorCode = QStringLiteral("UNIT_BUSY");
            result.message = QStringLiteral("unit %1 is busy").arg(uid);
            return result;
        }
    }

    return result;
}

// ---- Private Helpers ----

bool SafetyValidator::isTargetInBounds(double x, double y) {
    // 基本范围检查: 允许 [-1000, 1000] 米 (可配置)
    return isTaskTargetInBounds(x, y);
}

bool SafetyValidator::isTaskTargetInBounds(double x, double y) {
    constexpr double kMaxCoord = 1000.0;
    return qIsFinite(x) && qIsFinite(y) &&
           qAbs(x) <= kMaxCoord && qAbs(y) <= kMaxCoord;
}

bool SafetyValidator::isFollowDistanceAllowed(double distanceM) {
    return qIsFinite(distanceM) &&
           distanceM >= minFollowDistanceM() &&
           distanceM <= maxFollowDistanceM();
}

bool SafetyValidator::isUnitBound(const QString &unitId) {
    if (!Units_Hash_Table)
        return false;
    QByteArray requested = unitId.toUtf8();
    if (ilu_hash_FindInTable(Units_Hash_Table,
                            reinterpret_cast<ilu_refany>(requested.data())) != ILU_NIL)
        return true;

    ilu_HashEnumerator_s enumerator{};
    ilu_refany uid = nullptr;
    ilu_refany sbh = nullptr;
    ilu_hash_BeginEnumeration(Units_Hash_Table, &enumerator);
    while (ilu_hash_Next(&enumerator, &uid, &sbh)) {
        Q_UNUSED(sbh);
        if (logicalUnitIdsEqual(requested.constData(), static_cast<const char *>(uid)))
            return true;
    }
    return false;
}

bool SafetyValidator::isUnitAvailable(const QString &unitId) {
    return !TaskManager::instance().isUnitBusy(unitId);
}

bool SafetyValidator::isSpeedSafe(double linear, double angular) {
    return qAbs(linear) <= maxLinearSpeedMS() + 1e-6 &&
           qAbs(angular) <= maxAngularSpeedRadS() + 1e-6;
}

bool SafetyValidator::isDistanceReasonable(double targetX, double targetY,
                                            double currentX, double currentY) {
    double dx = targetX - currentX;
    double dy = targetY - currentY;
    double dist = qSqrt(dx * dx + dy * dy);
    return dist <= maxTargetDistanceM();
}
