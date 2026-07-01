#ifndef MOCK_ROBOT_SIMULATOR_H
#define MOCK_ROBOT_SIMULATOR_H

#include <QJsonObject>
#include <QMap>
#include <QMutex>
#include <QString>

/**
 * @file MockRobotSimulator.h
 * @brief 无真车时的内存模拟地面单元：位姿/速度由 HTTP 指令更新，供 MCP 与 HttpApiExecutor 测试。
 *
 * 绑定表中的 SBH 形如 `MOCK:GV1`，不经过 ILU；UI 主列表可见，UI 物理按钮对 MOCK 车仍走 ILU 会失败。
 */

class MockRobotSimulator {
public:
    static MockRobotSimulator &instance();

    /**
     * @brief 确保该 unit_id 有状态块（注册时调用）。
     */
    void ensureUnit(const QString &unitId);

    /**
     * @brief 是否为由本模拟器使用的 SBH 字符串。
     */
    static bool isMockSbh(const char *sbh);

    /**
     * @brief 按简单运动学积分一次 move（duration_ms 为秒比例尺）。
     */
    void applyMove(const QString &unitId, double linearVelocity, double angularVelocity, int durationMs);

    void stop(const QString &unitId);

    /** @brief 地面单元形态 JSON：pose/speed/mock */
    QJsonObject groundStatusJson(const QString &unitId) const;

private:
    MockRobotSimulator() = default;

    struct State {
        double x = 0.0;
        double y = 0.0;
        double yaw = 0.0;
        double lastLinear = 0.0;
        double lastAngular = 0.0;
    };

    mutable QMutex mutex_;
    QMap<QString, State> units_;
};

#endif
