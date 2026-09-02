#ifndef MOCK_ROBOT_SIMULATOR_H
#define MOCK_ROBOT_SIMULATOR_H

#include <QJsonObject>
#include <QMap>
#include <QMutex>
#include <QString>
#include <QStringList>
#include <QVector>

/**
 * @file MockRobotSimulator.h
 * @brief 无真车时的内存模拟单元（地面 UGV + 空中 UAV）：位姿/速度由 HTTP 指令更新，供 MCP 与 HttpApiExecutor 测试。
 *
 * 绑定表中的 SBH 形如 `MOCK:GV1`（地面）或 `MOCK:AV1`（空中），不经过 ILU；
 * 空中单元在 State 中额外携带高度 z。UI 主列表可见，UI 物理按钮对 MOCK 单元仍走 ILU 会失败。
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

    /** @brief 直接设置位姿（供 mock goto_pose 轮询使用） */
    void setPose(const QString &unitId, double x, double y, double yaw);

    /** @brief 直接设置三维位姿（供 mock 空中单元设置高度） */
    void setPose3D(const QString &unitId, double x, double y, double z, double yaw);

    /** @brief 地面单元形态 JSON：pose/speed/mock */
    QJsonObject groundStatusJson(const QString &unitId) const;

    /** @brief 空中单元形态 JSON：pose(x/y/z/yaw)/speed/mock */
    QJsonObject airStatusJson(const QString &unitId) const;

    bool configureFollowFormation(const QString &leaderId,
                                  const QStringList &followerIds,
                                  const QVector<float> &effectiveDistances,
                                  QString *error = nullptr);

    void clearFollowFormation();

    /** @brief 混合空地编队：空中领航者的 (x,y) 投影作为地面链头，逐链按 distance/angle 摆放地面车。 */
    bool configureAirGroundFormation(const QString &airLeaderId,
                                     const QStringList &groundChainIds,
                                     const QVector<float> &distances,
                                     const QVector<float> &anglesRad,
                                     QString *error = nullptr);

    void clearAirGroundFormation();

private:
    MockRobotSimulator() = default;

    struct State {
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
        double yaw = 0.0;
        double lastLinear = 0.0;
        double lastAngular = 0.0;
        bool isAir = false;
    };

    mutable QMutex mutex_;
    QMap<QString, State> units_;
    QString followLeaderId_;
    QStringList followFollowerIds_;
    QVector<float> followDistances_;
    QString airGroundAirLeaderId_;
    QStringList airGroundChainIds_;
    QVector<float> airGroundDistances_;
    QVector<float> airGroundAnglesRad_;

    void updateFollowersLocked();
    void updateAirGroundFollowersLocked();
};

#endif
