#ifndef GROUND_CONSOLE_H_
#define GROUND_CONSOLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "stubs\Console.h"
#include "stubs\Unit.h"
#include "stubs\Ground_Unit.h"
#include "stubs\Air_Unit.h"
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QDateTime>
#include <QVector>
#include <vector>
#include <string>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#define MAX_POINT_NUM 10
#define MAX_TRAP_POINT_NUM 20
#define MAX_VEHICLE_NUM 10
#define MAX_UNIT_NUM 23
#define RECONNECT_TIME 3
#define MAX_UNITID_LENGTH 21
#define MAX_UNITSBH_LENGTH 257

/*======================================================================*/
/*=============== 日志宏定义 (Requirements 9.6) ========================*/
/*======================================================================*/

// 日志宏 - 接受已格式化的QString消息
#define LOG_INFO(module, msg) \
    qDebug() << QStringLiteral("[%1] [INFO] [%2] ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(module) + (msg)

#define LOG_WARN(module, msg) \
    qDebug() << QStringLiteral("[%1] [WARN] [%2] ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(module) + (msg)

#define LOG_ERROR(module, msg) \
    qDebug() << QStringLiteral("[%1] [ERROR] [%2] ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(module) + (msg)

// 简化版本（无参数）- 与上面相同，保留兼容性
#define LOG_INFO_S(module, msg) LOG_INFO(module, msg)
#define LOG_WARN_S(module, msg) LOG_WARN(module, msg)
#define LOG_ERROR_S(module, msg) LOG_ERROR(module, msg)

/*======================================================================*/
/*=============== 跨类型边数据结构 (Requirements 6.1) ==================*/
/*======================================================================*/

// 跨类型边信息 - 必须在 FormationResult 之前定义
struct CrossTypeEdge {
    int fromIndex;                     // 源节点索引
    int toIndex;                       // 目标节点索引
    char fromUid[MAX_UNITID_LENGTH];   // 源节点UID
    char toUid[MAX_UNITID_LENGTH];     // 目标节点UID
    
    CrossTypeEdge() : fromIndex(-1), toIndex(-1) {
        fromUid[0] = '\0';
        toUid[0] = '\0';
    }
};

// 拆分结果数据结构
struct SplitResult {
    Unit_Formation airGroup;           // 空中组
    Unit_Formation groundGroup;        // 地面组
    std::vector<CrossTypeEdge> warnings;  // 跨类型边警告
    
    SplitResult() {
        // 初始化空中组
        airGroup.robot_ids._maximum = 0;
        airGroup.robot_ids._length = 0;
        airGroup.robot_ids._buffer = NULL;
        airGroup.leader_ids._maximum = 0;
        airGroup.leader_ids._length = 0;
        airGroup.leader_ids._buffer = NULL;
        airGroup.distances._maximum = 0;
        airGroup.distances._length = 0;
        airGroup.distances._buffer = NULL;
        airGroup.angles._maximum = 0;
        airGroup.angles._length = 0;
        airGroup.angles._buffer = NULL;
        
        // 初始化地面组
        groundGroup.robot_ids._maximum = 0;
        groundGroup.robot_ids._length = 0;
        groundGroup.robot_ids._buffer = NULL;
        groundGroup.leader_ids._maximum = 0;
        groundGroup.leader_ids._length = 0;
        groundGroup.leader_ids._buffer = NULL;
        groundGroup.distances._maximum = 0;
        groundGroup.distances._length = 0;
        groundGroup.distances._buffer = NULL;
        groundGroup.angles._maximum = 0;
        groundGroup.angles._length = 0;
        groundGroup.angles._buffer = NULL;
    }
};

/*======================================================================*/
/*=============== 编队结果数据结构 (Requirements 10.2, 10.4) ===========*/
/*======================================================================*/

// 错误码定义
enum FormationErrorCode {
    FE_SUCCESS = 0,           // 成功
    FE_INVALID_INPUT = 1,     // 输入校验失败
    FE_NO_LEADER = 2,         // 未设置Leader
    FE_RPC_FAILED = 3,        // RPC调用失败
    FE_PARTIAL_SUCCESS = 4,   // 部分成功
    FE_ALL_FAILED = 5         // 全部失败
};

// 单个单元的结果
struct UnitResult {
    char uid[MAX_UNITID_LENGTH];  // 单元ID
    bool success;                  // 是否成功
    int errorCode;                 // 错误码 (0=成功, 其他=错误码)
    char errorMsg[256];            // 错误消息
    bool isOrphan;                 // 是否因跨类型边降级为独立节点
    
    UnitResult() : success(true), errorCode(0), isOrphan(false) {
        uid[0] = '\0';
        errorMsg[0] = '\0';
    }
};

// 单个组（空中组或地面组）的结果
struct GroupResult {
    bool success;                      // 整组是否成功
    int successCount;                  // 成功单元数
    int failCount;                     // 失败单元数
    std::vector<UnitResult> unitResults;  // 每个单元的结果
    
    GroupResult() : success(true), successCount(0), failCount(0) {}
    
    // 计算成功/失败数量
    void calculateCounts() {
        successCount = 0;
        failCount = 0;
        for (const auto& ur : unitResults) {
            if (ur.success) {
                successCount++;
            } else {
                failCount++;
            }
        }
        success = (failCount == 0);
    }
};

// 整体编队下发结果
struct FormationResult {
    GroupResult airResult;      // 空中组结果
    GroupResult groundResult;   // 地面组结果
    int elapsedMs;              // 耗时（毫秒）
    std::vector<CrossTypeEdge> crossTypeWarnings;  // 跨类型边警告 (Requirements 6.1)
    
    // 新增字段用于测试兼容性
    bool success;               // 整体是否成功
    int totalCount;             // 总单元数
    int successCount;           // 成功单元数
    int failCount;              // 失败单元数
    GroupResult airGroupResult;    // 空中组结果别名
    GroupResult groundGroupResult; // 地面组结果别名
    
    FormationResult() : elapsedMs(0), success(true), totalCount(0), successCount(0), failCount(0) {}
    
    // 判断是否完全成功
    bool isSuccess() const {
        // 空组默认视为成功
        bool airOk = airResult.unitResults.empty() || airResult.success;
        bool groundOk = groundResult.unitResults.empty() || groundResult.success;
        return airOk && groundOk;
    }
    
    // 判断是否部分成功
    bool isPartialSuccess() const {
        int totalSuccess = airResult.successCount + groundResult.successCount;
        int totalFail = airResult.failCount + groundResult.failCount;
        return (totalSuccess > 0) && (totalFail > 0);
    }
    
    // 获取所有失败的单元
    std::vector<UnitResult> getAllFailedUnits() const {
        std::vector<UnitResult> failed;
        for (const auto& ur : airResult.unitResults) {
            if (!ur.success) {
                failed.push_back(ur);
            }
        }
        for (const auto& ur : groundResult.unitResults) {
            if (!ur.success) {
                failed.push_back(ur);
            }
        }
        return failed;
    }
};

struct ConsoleFollowFormationRecord {
    bool ready;
    bool physicalSetupAttempted;
    QString state;
    QString ownerId;
    QString activeMoveTaskId;
    QString message;
    QString errorCode;
    QString leaderId;
    QStringList followerIds;
    QVector<float> requestedDistances;
    QVector<float> effectiveDistances;
    QStringList physicalMembers;

    ConsoleFollowFormationRecord()
        : ready(false)
        , physicalSetupAttempted(false)
        , state(QStringLiteral("IDLE")) {}

    void clear() {
        ready = false;
        physicalSetupAttempted = false;
        state = QStringLiteral("IDLE");
        ownerId.clear();
        activeMoveTaskId.clear();
        message.clear();
        errorCode.clear();
        leaderId.clear();
        followerIds.clear();
        requestedDistances.clear();
        effectiveDistances.clear();
        physicalMembers.clear();
    }
};

extern ConsoleFollowFormationRecord consoleFollowFormationRecord;

/*======================================================================*/
/*=============== 辅助函数声明 (Requirements 9.1) ======================*/
/*======================================================================*/

// 将 Unit_UnitIDSeq 格式化为可读字符串用于日志
QString formatUnitIDSeq(const Unit_UnitIDSeq* seq);

// 将 Unit_ShortSeq 格式化为可读字符串用于日志
QString formatShortSeq(const Unit_ShortSeq* seq);

// 将 Unit_FloatSeq 格式化为可读字符串用于日志
QString formatFloatSeq(const Unit_FloatSeq* seq);

// 将 ILU 生成的回环/通配地址 SBH 改写为外部设备可回连的发布地址。
QByteArray normalizePublishedConsoleSbh(const char* rawSbh, const char* advertisedHost);

// 兼容界面输入的 GV1/AV1 与设备实际注册的 GV01/AV01。
bool logicalUnitIdsEqual(const char* lhs, const char* rhs);

// 若两个不同网络端点复用了同一个ILU Server ID，返回可读诊断；否则返回空串。
QString describeIluServerIdConflict(const char* uidA, const char* sbhA,
                                    const char* uidB, const char* sbhB);

// Console GUI 与 HTTP 跟随编队共用的链式 Unit_Formation 构造逻辑。
float effectiveGroundFollowDistance(float requestedDistance);
QStringList groundFollowParentIds(
    const QString &leaderId,
    const QStringList &followerIds,
    QString *errorMessage);
Unit_Formation *buildGroundFollowFormation(
    const QString &leaderId,
    const QStringList &followerIds,
    const QVector<float> &distances,
    QString *errorMessage);
void freeUnitFormation(Unit_Formation *value);
bool followFormationDispatchIsReady(int successCount, int failCount, int expectedCount);

struct ScopedFollowResult {
    bool success;
    bool physicalSetupAttempted;
    bool rollbackSucceeded;
    int successCount;
    int failCount;
    QStringList failedUnits;
    QStringList physicalMembers;
    QString message;

    ScopedFollowResult()
        : success(false)
        , physicalSetupAttempted(false)
        , rollbackSucceeded(true)
        , successCount(0)
        , failCount(0) {}
};

// Task-level scoped follow helpers. Legacy setToLeader/setGroupMode keep their
// existing all-bound-unit behavior for GUI and compatibility callers.
ScopedFollowResult createScopedGroundFollow(
    const QString &leaderId,
    const QStringList &followerIds,
    const QVector<float> &distances);
ScopedFollowResult clearScopedGroundFollow(const QStringList &unitIds);

// 拓扑策略枚举
enum TopologyStrategy {
    TOPOLOGY_CHAIN = 0,   // 链式拓扑（默认）
    TOPOLOGY_STAR = 1     // 星形拓扑
};

/*======================================================================*/
/*=============== 核心算法函数声明 (Requirements 1, 5, 6) ==============*/
/*======================================================================*/

// 校验 formation 数据有效性 (Requirements 1.5, 5.4)
// 返回: true=有效, false=无效
bool validateFormation(const Unit_Formation* formation);

// 检测跨类型边 (Requirements 6.1)
// 返回: 跨类型边列表
std::vector<CrossTypeEdge> detectCrossTypeEdges(const Unit_Formation* formation);

// 拆分混合编队为空中组和地面组 (Requirements 6.2, 6.4)
// 返回: 拆分结果，包含空中组、地面组和警告信息
SplitResult splitFormation(const Unit_Formation* formation);

// 归一化拓扑结构 (Requirements 1.2, 1.4)
// 将星形拓扑转换为链式拓扑
void normalizeTopology(Unit_Formation* formation, TopologyStrategy strategy);

extern ilu_HashTable Units_Hash_Table;
extern Unit_Formation *formation;  // 全局队形数据，包含用户录入的距离和角度参数

void displayBoundUnit();
ilu_boolean getUnitObject(Unit_UnitID uid);
bool setToLeader();
bool romoteControl();
bool sendCommandSeq();
bool setGroupMode(Unit_UnitMode mode);
bool setGroupMinorMode(Unit_UnitMinorMode minorMode);

bool setFormation(Unit_Formation* formation);
// 新增：返回详细结果的版本 (Requirements 10.2, 10.4)
FormationResult setFormationWithResult(Unit_Formation* formation);

bool setTaskPoint(float x, float y);
bool setTrap(Console_TrapPoint trap);
bool clearTraps();
bool setDefault();
void shutDownAllUnit();
void stopUnit();
void usage(char* prom);
void getLocalIP();

#endif
