/**
 * @file SafetyValidator.h
 * @brief MCP-IDL 安全校验层。
 *
 * 在任务执行前进行校验，返回 MCP-IDL ErrorCode。
 * 校验规则对应 mcp_swarm_task.idl 定义的安全约束。
 */

#ifndef SAFETY_VALIDATOR_H
#define SAFETY_VALIDATOR_H

#include <QJsonArray>
#include <QJsonObject>
#include <QString>

class SafetyValidator {
public:
    struct ValidationResult {
        bool passed;
        QString errorCode;    // MCP-IDL ErrorCode (空 = 通过)
        QString message;      // 人类可读消息
    };

    // ---- 单点导航校验 ----
    ValidationResult validateGotoPose(const QString &unitId,
                                       double targetX, double targetY,
                                       double linearSpeed, double angularSpeed);

    // ---- 批量导航校验 ----
    ValidationResult validateGotoPoseBatch(const QJsonArray &targets);

    // ---- 编队校验 ----
    ValidationResult validateFormation(const QJsonObject &request);

    // ---- 可配置阈值 ----
    static double maxTargetDistanceM()   { return 100.0; }
    static double maxLinearSpeedMS()     { return 5.0; }
    static double maxAngularSpeedRadS()  { return 10.0; }
    static double minToleranceM()        { return 0.02; }
    static double minFollowDistanceM()   { return 0.5; }
    static double maxFollowDistanceM()   { return 20.0; }
    static bool isTaskTargetInBounds(double x, double y);
    static bool isFollowDistanceAllowed(double distanceM);

private:
    bool isTargetInBounds(double x, double y);
    bool isUnitBound(const QString &unitId);
    bool isUnitAvailable(const QString &unitId);
    bool isSpeedSafe(double linear, double angular);
    bool isDistanceReasonable(double targetX, double targetY,
                               double currentX, double currentY);
};

#endif // SAFETY_VALIDATOR_H
