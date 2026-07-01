//$Id: console.cpp,v 1.7 2025/07/17 04:50:35 cvswxc Exp $

//#include "iluchdrs.h"


#include "stubs\Console.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "iluchdrs.h"
#ifdef __cplusplus
}
#endif

#include "console.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverthread.h"
#include "HttpApiExecutor.h"
#include "HttpPlugin.h"
#include "MockRobotSimulator.h"
#include <stdio.h>
#include <iostream>
#include <QStringList>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QHostAddress>
#include <QDebug>


#pragma comment(lib, "iluc32.lib")
#pragma comment(lib, "ilu32.lib")
#pragma comment(lib, "ws2_32.lib")
// 还报就再解开：
 #pragma comment(lib, "ilucpp32.lib")
 #pragma comment(lib, "ilupr.lib")
 #pragma comment(lib, "parser32.lib")





ilu_HashTable Units_Hash_Table = NULL;
ILU_C_Server consoleServer = NULL;
Console_rpc  serviceObj = NULL;
Console_rpc  serviceObj_1 = NULL;
Console_rpc  backupCosObj = NULL;
Unit_UnitSBH backupCosSBH = NULL;
Console_TrapPoint trapPoints[MAX_TRAP_POINT_NUM];
Unit_UnitMode currentMode = Unit_UM_None;
Unit_UnitMinorMode currentMinorMode = Unit_UMM_None;
Unit_rpc currentUnitObj = NULL;
Ground_Unit_rpc currentGrdUnitObj;
Air_Unit_rpc currentAirUnitObj;
Ground_Unit_rpc currentGUVLeaderObj = NULL;
Air_Unit_rpc currentAUVLeaderObj =NULL;
Unit_UnitID currentUID = NULL;
Unit_UnitID currentLeaderUID = NULL;
char* leaderSBH = NULL;
int currentGUVNum = 0;
int currentAUVNum = 0;
int currentTrapPointsNum = 0;
ilu_boolean hasLeader = ilu_FALSE;

char host[20]="127.0.0.1";
char port[10] = "5000";
char protocol[20] = "iiop";
char instanceHandle[20] = "console_sau";
char sid[20] = "sau";
char transProctocol[20] = "tcp";

char* transInfo[3] = { NULL, NULL, NULL };
char* backupFileName = "BackupFile.txt";
char* backupCosNamingServerFileName = "BackupCosNamingInfo.txt";
char* backupTrapsFileName = "BackupTrapPoints.txt";
int mainloopFlag = 1;
FILE* backupFile;
float currentCtrlLinearVelocity = 0.05;
float currentCtrlAngularVelocity = 0.53;

Unit_Formation *formation = NULL;

MainWindow* UserInter = 0;
ServerThread *st = 0;

//将hash表保存至本地文件
void backupCosNamingInfoToLocalFile(){
    ilu_HashEnumerator_s he;
    ilu_Error err;
    ilu_refany uid, sbh;
    backupFile = fopen(backupFileName, "w+");
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh))
        fprintf(backupFile, "%s %s\n", uid, sbh);
    fclose(backupFile);
    qDebug()<<QStringLiteral("已将Cos信息备份到本地文件");
}
void getLocalIP(){

    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    for (const QNetworkInterface &iface : interfaces) {
        QString name = iface.humanReadableName().toLower();

        // ✅ 条件 1：名字中包含 "wifi", "wlan" 等关键词（跨平台兼容）

        if (!(name.contains("wifi") || name.contains("wlan")))
            continue;

        // ✅ 条件 2：接口必须启用、运行，并且不是回环
        if (!(iface.flags() & QNetworkInterface::IsUp) ||
            !(iface.flags() & QNetworkInterface::IsRunning) ||
            (iface.flags() & QNetworkInterface::IsLoopBack))
            continue;

        // ✅ 遍历地址条目，找 IPv4
        for (const QNetworkAddressEntry &entry : iface.addressEntries()) {
            QHostAddress ip = entry.ip();
            if (ip.protocol() == QAbstractSocket::IPv4Protocol) {
                qDebug() << "WiFi Interface:" << iface.humanReadableName();
                qDebug() << "IP Address:" << ip.toString();
                QString ip_str = ip.toString(); // 将 IP 转成 QString
                strncpy(host, ip_str.toUtf8().constData(), sizeof(host) - 1);
                host[sizeof(host) - 1] = '\0';  // 添加终止符，防止越界
                return;
            }
        }
    }

    qDebug() << host;
}

//从备份Cos服务器生成hash表
ilu_boolean loadCosInfoFromBackupCosServer(){
    Unit_UnitInfoSeq *newSeq;
    Unit_UnitInfo *node;
    CORBA_Environment ev;
    int i;
    char *newsbh, *newuid;
    ilu_boolean flag;

    qDebug() <<QStringLiteral("准备从Leader CosNaming中载入信息");
    if (Units_Hash_Table != NULL)
        ilu_hash_FreeHashTable(Units_Hash_Table, ilu_free, ilu_free);
    Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM, ilu_hash_HashString, ilu_hash_StringCompare);

    if (backupCosObj != NULL) {
        newSeq = Console_rpc_getCosNamingInfo(backupCosObj, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QStringLiteral("无法联系到Leader");//是否要删除Cos对象和文件？
            return ilu_FALSE;
        }
    } else {
        qDebug() <<QStringLiteral("backupCosObj为NULL，无法从Leader恢复");
        return ilu_FALSE;
    }
    
    if (newSeq != NULL) {
        currentGUVNum = 0;
        currentAUVNum = 0;

        for (i = 0; i < Unit_UnitInfoSeq_Length(newSeq); i++) {
            node = Unit_UnitInfoSeq_Nth (newSeq, i);
    newuid = (char*)ilu_malloc(strlen(node->uid) + 1);
    newsbh = (char*)ilu_malloc(strlen(node->sbh) + 1);
    strcpy(newuid, node->uid);
    strcpy(newsbh, node->sbh);

            ilu_hash_AddToTable(Units_Hash_Table, newuid, newsbh);
            if(newuid[0] == 'G')
                currentGUVNum++;
            if(newuid[0] == 'A')
            currentAUVNum++;
        }
        flag = ilu_TRUE;
    }
    else
        flag = ilu_FALSE;
    backupCosNamingInfoToLocalFile();
    return flag;
}
// 从 Leader 初始化陷阱点
ilu_boolean loadTrapsFromLeader() {
    CORBA_Environment ev;
    Console_TrapPointSeq* traps = nullptr;
    FILE* trapsBackupFile = nullptr;

    // 1. 声明两个变量，分别接收地面和空中 RPC
    Ground_Unit_TrapPointSeq* groundTraps = nullptr;
    Air_Unit_TrapPointSeq*   airTraps    = nullptr;

    // 2. 根据 Leader 类型调用不同的 RPC
    if (currentGUVLeaderObj != nullptr) {
        groundTraps = Ground_Unit_rpc_getTraps(currentGUVLeaderObj, &ev);
        traps = nullptr;                // 不用通用 traps
    }
    else if (currentAUVLeaderObj != nullptr) {
        airTraps = Air_Unit_rpc_getTraps(currentAUVLeaderObj, &ev);
        traps = nullptr;
    }
    else {
        qDebug() << QStringLiteral("未设置任何 Leader，无法获取陷阱点");
        return ilu_FALSE;
    }

    // 3. 检查哪个序列非空，并取得长度
    ilu_cardinal len = 0;
    if (groundTraps) {
        len = Ground_Unit_TrapPointSeq_Length(groundTraps);
    }
    else {
        len = Air_Unit_TrapPointSeq_Length(airTraps);
    }

    if (!ILU_C_SUCCESSFUL(&ev) || len == 0) {
        qDebug() << QStringLiteral("无法联系 Leader 对象或无陷阱点: %1").arg(ev.returnCode);
        return ilu_FALSE;
    }

    qDebug() << QStringLiteral("收到的陷阱长度:%1").arg(len);
    if (len > MAX_TRAP_POINT_NUM) {
        qDebug() << QStringLiteral("陷阱点数量超限: %1").arg(len);
        return ilu_FALSE;
    }

    // 4. 遍历并处理：统一用 Console_TrapPointSeq 也行，或者直接从 ground/air buffer 里读
    for (CORBA_unsigned_long i = 0; i < len; ++i) {
        Console_TrapPoint tp;

        if (groundTraps) {
            auto p = Ground_Unit_TrapPointSeq_Nth(groundTraps, i);
            tp._d = Console_TrapGroundType;
            tp._u.trapPoint2D = *p;
        }
        else {
            auto p = Air_Unit_TrapPointSeq_Nth(airTraps, i);
            tp._d = Console_TrapAirType;
            tp._u.trapPoint3D = *p;
        }

        // 存到全局数组 & 写文件……
        trapPoints[currentTrapPointsNum++] = tp;
        // … fprintf 对应类型 …
    }


    // 检查调用是否成功
    if (!ILU_C_SUCCESSFUL(&ev) || traps == nullptr) {
        qDebug() << QStringLiteral("无法联系 Leader 对象: %1").arg(ev.returnCode);
        return ilu_FALSE;
    }

    qDebug() << QStringLiteral("收到的陷阱长度:%1").arg(traps->_length);
    if (traps->_length > MAX_TRAP_POINT_NUM) {
        qDebug() << QStringLiteral("陷阱点数量超限: %1").arg(traps->_length);
        return ilu_FALSE;
    }

    // 备份文件 & 数组重置
    currentTrapPointsNum = 0;
    remove(backupTrapsFileName);
    trapsBackupFile = fopen(backupTrapsFileName, "w+");
    if (!trapsBackupFile) {
        qDebug() << QStringLiteral("打开陷阱备份文件失败");
        return ilu_FALSE;
    }

    // 遍历 traps 序列，填充 trapPoints 并写入备份
    for (int i = 0; i < traps->_length; ++i) {
        Console_TrapPoint* tp = Console_TrapPointSeq_Nth(traps, i);
        trapPoints[currentTrapPointsNum] = *tp;

        if (tp->_d == Console_TrapGroundType) {
            fprintf(trapsBackupFile, "%f,%f,%f\n",
                    tp->_u.trapPoint2D.point.x,
                    tp->_u.trapPoint2D.point.y,
                    tp->_u.trapPoint2D.radius);
            qDebug() << QStringLiteral("导入地面陷阱点(%1,%2) 半径%3")
                        .arg(tp->_u.trapPoint2D.point.x)
                        .arg(tp->_u.trapPoint2D.point.y)
                        .arg(tp->_u.trapPoint2D.radius);
        }
        else if (tp->_d == Console_TrapAirType) {
            fprintf(trapsBackupFile, "%f,%f,%f,%f\n",
                    tp->_u.trapPoint3D.point.x,
                    tp->_u.trapPoint3D.point.y,
                    tp->_u.trapPoint3D.point.z,
                    tp->_u.trapPoint3D.radius);
            qDebug() << QStringLiteral("导入空中陷阱点(%1,%2,%3) 半径%4")
                        .arg(tp->_u.trapPoint3D.point.x)
                        .arg(tp->_u.trapPoint3D.point.y)
                        .arg(tp->_u.trapPoint3D.point.z)
                        .arg(tp->_u.trapPoint3D.radius);
        }

        ++currentTrapPointsNum;
    }
    fclose(trapsBackupFile);

    qDebug() << QStringLiteral("当前陷阱数量:%1").arg(currentTrapPointsNum);
    qDebug() << QStringLiteral("已将陷阱信息备份到本地文件");
    return ilu_TRUE;
}

// 从本地文件生成 Hash 表
ilu_boolean loadCosInfoFromLocalFile() {
    qDebug() << QStringLiteral("准备从备份文件中载入 CosNaming 信息");

    // 1. 释放旧表，重建新表
    if (Units_Hash_Table != nullptr) {
        ilu_hash_FreeHashTable(Units_Hash_Table, ilu_free, ilu_free);
    }
    Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM,
                                             ilu_hash_HashString,
                                             ilu_hash_StringCompare);

    // 2. 打开备份文件
    FILE* backupFile = fopen(backupFileName, "r");
    if (backupFile) {
        currentGUVNum = 0;
        currentAUVNum = 0;

        // 3. 逐行读取 UID 与 SBH
        while (!feof(backupFile)) {
            char* uid = (char*)ilu_malloc(MAX_UNITID_LENGTH);
            char* sbh = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
            if (fscanf(backupFile, "%s %s\n", uid, sbh) != 2) {
                ilu_free(uid);
                ilu_free(sbh);
                break;
            }

            ilu_hash_AddToTable(Units_Hash_Table, uid, sbh);
            if (uid[0] == 'G') ++currentGUVNum;
            else if (uid[0] == 'A') ++currentAUVNum;
        }
        fclose(backupFile);
    }
    else {
        qDebug() << QStringLiteral("无备份文件");
    }

    qDebug() << QStringLiteral("地面单元数: %1, 空中单元数: %2").arg(currentGUVNum).arg(currentAUVNum);
    return ilu_TRUE;
}

ilu_boolean init() {

    // ---------- 1) 拼 transInfo[0] ----------
    char* transStr = (char*)malloc((strlen(transProctocol) + strlen(host) + strlen(port) + 2 + 1));
    if (!transStr) {
        qDebug() << "[init] malloc transStr failed";
        return ilu_FALSE;
    }
    sprintf(transStr, "%s_%s_%s", transProctocol, host, port);
    transInfo[0] = transStr;
    qDebug() << transStr;

    // ---------- 2) 保证使用 DLL 导入库 ----------
#ifdef ILU_NODLL
# error "当前使用的是 DLL 导入库，请不要定义 ILU_NODLL 或类似宏。"
#endif

    // ---------- 3) 初始化桩（顺序固定） ----------
    Ground_Unit__Initialize();
    Air_Unit__Initialize();
    Console__Initialize();

    // ---------- 4) 先建 Server，再初始化接口 ----------
    consoleServer = ILU_C_InitializeServer(sid, NULL, protocol, transInfo, NULL, ilu_TRUE);
    if (consoleServer == NULL) {
        qDebug() << "[init] consoleServer 初始化失败";
        return ilu_FALSE;
    }
    qDebug() << "ConsoleServer created!";
    Console__InitializeServer();     // 必须在 InitializeServer 之后

    // ---------- 5) 直接从桩里的 MSType 取得类记录，并做一次显式转换 ----------
    // 说明：你这版桩里 Console_rpc__MSType 的类型是 ilu_Class（C 侧类型），
    // 而 ILU_C_CreateTrueObject 需要 ILU_C_Class（C++ 侧类型）。
    // 用 reinterpret_cast 即可安全转换（两者本质上是同一类记录的不同 typedef）。
    // 取类记录（把 ilu_Class 转成 ILU_C_Class）
    // ---------- 1) 设置默认类（便捷 CreateTrue 依赖它） ----------
    // 1) 取到类记录（Console.h 暴露的是 ilu_Class；强转成 ILU_C_Class 传给 C-API）
    ILU_C_Class ccls = reinterpret_cast<ILU_C_Class>(Console_rpc__MSType);
    if (ccls == NULL) {
        qDebug() << "[init] MSType 为空：桩/库不匹配或未初始化";
        return ilu_FALSE;
    }

    // 2) 直接创建 True 对象（5 参数版本，不依赖默认类）
    qDebug() << "[CreateTrue/5args] instance =" << instanceHandle;


    // 有的生成桩是 3 参原型，有的是带环境的 4 参原型；按你 Console.h 的原型来用一种
    CORBA_Environment ev;
    memset(&ev, 0, sizeof(ev));

    qDebug() << "[CreateTrue] try instance =" << instanceHandle;

    // --- 版本 A：3 参原型（很多桩是这个）
    serviceObj = Console_rpc__CreateTrue((ilu_string)instanceHandle, consoleServer, NULL);

    // --- 版本 B：4 参原型（如果你头文件有带 &ev 的）
    /*
    serviceObj = Console_rpc__CreateTrue((ilu_string)instanceHandle, consoleServer, NULL, &ev);
    */

    if (serviceObj == NULL) {
        qDebug() << "[CreateTrue] 返回 NULL";
        return ilu_FALSE;
    }

    // 如果你用的是带环境的版本，强烈建议检查异常
    if (ev._major != CORBA_NO_EXCEPTION) {
           qDebug() << "[CreateTrue] 发生异常（无 _id 字段可取）。";
           // 这套头文件通常也没有 ILU_C_EXCEPTION_FREE 宏，直接忽略释放
           // 如果你的头里定义了 ILU_C_EXCEPTION_FREE，可加条件编译：
           // #ifdef ILU_C_EXCEPTION_FREE
           //   ILU_C_EXCEPTION_FREE(&ev);
           // #endif
           return ilu_FALSE;
       }

    // 发布
    if (!ILU_C_PublishObject(serviceObj)) {
        qDebug() << "[Publish] 返回 false（某些协议下即便 false 也可能已可访问）";
    }
    qDebug() << "服务器：" << ILU_C_SBHOfObject(serviceObj);



        const char* sbh = ILU_C_SBHOfObject(serviceObj);
        if (sbh && *sbh) {
            qDebug() << "服务器：" << sbh;
            if (backupCosSBH) { ilu_free(backupCosSBH); backupCosSBH = NULL; }
            backupCosSBH = (char*)ilu_malloc(strlen(sbh) + 1);
            strcpy(backupCosSBH, sbh);
        }

        qDebug() << "服务器初始化成功!";
        
        // ---------- 恢复机制：在服务器初始化成功后进行 ----------
        // 0.1) 尝试从备份Cos服务器恢复信息
        FILE* backupCosFile = fopen(backupCosNamingServerFileName, "r");
        if (backupCosFile != NULL) {
            // 分配内存并读取Leader信息、模式等
            if (backupCosSBH) { ilu_free(backupCosSBH); backupCosSBH = NULL; }
            if (leaderSBH) { ilu_free(leaderSBH); leaderSBH = NULL; }
            if (currentLeaderUID) { ilu_free(currentLeaderUID); currentLeaderUID = NULL; }
            
            backupCosSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
            leaderSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
            currentLeaderUID = (char*)ilu_malloc(MAX_UNITID_LENGTH);
            
            // 安全地读取文件，检查返回值
            int result = fscanf(backupCosFile, "%s\n%s\n%s\n%d\n%d", backupCosSBH, leaderSBH, currentLeaderUID, &currentMode, &currentMinorMode);
            fclose(backupCosFile);
            
            if (result == 5) {
                qDebug() << QStringLiteral("已从备份文件读取Leader信息");
            } else {
                qDebug() << QStringLiteral("备份文件格式错误，将使用默认值");
                // 设置默认值
                currentMode = Unit_UM_None;
                currentMinorMode = Unit_UMM_None;
            }
        } else {
            qDebug() << QStringLiteral("未找到备份文件，将使用默认值");
            // 设置默认值
            currentMode = Unit_UM_None;
            currentMinorMode = Unit_UMM_None;
        }

        // 0.2) 尝试从Leader的CosNaming服务器恢复单元信息
        ilu_boolean cosInitFlag = loadCosInfoFromBackupCosServer();

        // 0.3) 如果无法从Leader恢复,则从本地备份文件恢复
        if (!cosInitFlag) {
            if (!loadCosInfoFromLocalFile()) {
                qDebug() << QStringLiteral("Cos哈希表初始化失败，但服务器仍可正常启动");
                // 不返回失败，让服务器继续启动
            }
        }
        
        return ilu_TRUE;
    }


//显示已绑定单元
void displayBoundUnit() {
    string result =  "无车辆绑定\n";
    if (Units_Hash_Table != ILU_NIL) {
        ilu_HashEnumerator_s he;
        ilu_refany key, data;
        int i = 0;
        result = "";
        ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
        while (ilu_hash_Next(&he, &key, &data))
        {
            i++;
            result.append("\tUnit ID:");
            result.append((char*)key);
            result.append("\tUnit SBH:");
            result.append((char*)data);
            result.append("\n");
        }
        if(0 == i)
            string result =  "无车辆绑定\n";
        emit st->bindInfoChanged(QString::fromStdString(result));
    }
    else
        Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM, ilu_hash_HashString, ilu_hash_StringCompare);
}

//获取选定单元对象
ilu_boolean getUnitObject(Unit_UnitID uid) {
    CORBA_Environment ev;
    Unit_rpc tmp = NULL;
    char *sbh;

    sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, uid);
    
    if (sbh == ILU_NIL) {
        qDebug() << QStringLiteral("未注册的单元ID: %1").arg(uid);
        return ilu_FALSE;
    }

    if (MockRobotSimulator::isMockSbh(sbh)) {
        qDebug() << QStringLiteral("单元 %1 为 MOCK 模拟车，请使用 HTTP/MCP 控制；UI 物理按钮不会连接 ILU。").arg(uid);
        return ilu_FALSE;
    }
    
    // 检查是否是同一个单元，如果是则直接返回
    if (currentUID != NULL && strcmp(currentUID, uid) == 0) {
        qDebug() << QStringLiteral("单元%1已经是当前控制单元").arg(uid);
        return ilu_TRUE;
    }
    
    qDebug() << QStringLiteral("正在切换到单元: %1, SBH: %2").arg(uid).arg(sbh);
    
    // 先释放旧对象再创建新对象，避免对象缓存问题
    if (currentUnitObj != NULL) {
        qDebug() << QStringLiteral("释放旧单元对象: %1, 地址: %2").arg(currentUID != NULL ? currentUID : "NULL").arg((quintptr)currentUnitObj, 0, 16);
        Unit_rpc__Free(&currentUnitObj);
        currentUnitObj = NULL;
    }
    
    if (currentUID != NULL) {
        ilu_free(currentUID);
        currentUID = NULL;
    }
    
    //地面单元
    if (uid[0] == 'G') {
        tmp = (Unit_rpc)ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() << QStringLiteral("无法创建地面单元对象: %1, 错误: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
            return ilu_FALSE;
        }
        qDebug() << QStringLiteral("创建地面单元对象成功，新地址: %1").arg((quintptr)tmp, 0, 16);
    }
    //空中单元
    else if (uid[0] == 'A') {
        tmp = (Unit_rpc)ILU_C_SBHToObject(sbh, Air_Unit_rpc__MSType, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() << QStringLiteral("无法创建空中单元对象: %1, 错误: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
            return ilu_FALSE;
        }
        qDebug() << QStringLiteral("创建空中单元对象成功，新地址: %1").arg((quintptr)tmp, 0, 16);
    }
    else {
        qDebug() << QStringLiteral("未知的单元类型: %1").arg(uid);
        return ilu_FALSE;
    }
    
    // 设置新的UID和对象
    currentUID = (char*)ilu_malloc(strlen(uid) + 1);
    strcpy(currentUID, uid);
    currentUnitObj = tmp;
    
    qDebug() << QStringLiteral("成功切换到单元: %1, 对象地址: %2").arg(uid).arg((quintptr)currentUnitObj, 0, 16);
    return ilu_TRUE;
}


//设置某单位为Leader
// 正确的使用流程：
// 1. getUnitObject(uid) - 选择要设置为Leader的单元
// 2. setToLeader() - 设置当前单元为Leader，并配置所有其他单元为Follower
// 3. setGroupMode(Unit_UM_Follow) - 开启跟随模式
bool setToLeader() {
    FILE* backupCosFile;
    char* tmpSBH, *leaderSBH;
    ilu_refany uid, sbh;
    ilu_HashEnumerator_s he;
    Ground_Unit_rpc tmpGrdObj;
    CORBA_Environment ev;
    Unit_UnitInfoSeq* seq, *newSeq;
    ilu_Error err;
    Unit_UnitInfo *node;
    
    qDebug() << "========== setToLeader 开始 ==========";
    qDebug() << "当前单元ID:" << (currentUID != NULL ? currentUID : "NULL");
    qDebug() << "currentUnitObj地址:" << currentUnitObj;
    qDebug() << "currentGUVLeaderObj地址:" << currentGUVLeaderObj;
    qDebug() << "currentAUVLeaderObj地址:" << currentAUVLeaderObj;
    
    if (currentUnitObj == NULL) {
        qDebug() << "错误：未选定控制单元！请先调用 getUnitObject(uid) 选择要设为Leader的单元";
        return false;
    }
    
    // 注意：这里比较的是指针地址，但由于每次getUnitObject都会重新创建对象，
    // 所以这个检查可能不会正确工作。改为比较UID
    if (currentLeaderUID != NULL && strcmp(currentUID, currentLeaderUID) == 0) {
        qDebug() << "警告:" << currentUID << "已经是Leader了！";
        return false;
    }
    
    qDebug() << "正在设置" << currentUID << "为Leader...";
    Unit_rpc_setRole(currentUnitObj, Unit_UR_Leader,"ilusbh:sau/console;IDL%3AConsole%2Frpc%3A1.0;iiop@tcp_192.168.1.110_5000",&ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        qDebug() << "failed to setLeader:" << ev.returnCode;
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }

   //需要根据currentUnitObj来决定是地面车 还是 无人机 来作为当前的领头人
    // 先获取CosNaming SBH
    tmpSBH = Unit_rpc_getCosNamingSBH(currentUnitObj, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        qDebug() << "failed to get CosNaming SBH:" << ev.returnCode;
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    qDebug() << "Leader CosNaming SBH:" << tmpSBH;
    
    //释放旧的Leader对象
    if (currentGUVLeaderObj != NULL) {
        Ground_Unit_rpc__Free(&currentGUVLeaderObj);
        currentGUVLeaderObj = NULL;
    }
    if (currentAUVLeaderObj != NULL){
        Air_Unit_rpc__Free(&currentAUVLeaderObj);
        currentAUVLeaderObj = NULL;
    }
    if (backupCosObj != NULL) {
        Console_rpc__Free(&backupCosObj);
        backupCosObj = NULL;
    }

    // 根据单元类型设置对应的Leader对象
    if (currentUID[0] == 'G'){//GUV
        currentGUVLeaderObj = CORBA_Object_duplicate(currentUnitObj, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() << "failed to duplicate ground leader obj:" << ev.returnCode;
            ILU_C_EXCEPTION_FREE(&ev);
            return false;
        }
        leaderSBH = (char*)ilu_malloc(strlen(ILU_C_SBHOfObject(currentGUVLeaderObj)) + 1);
        strcpy(leaderSBH, ILU_C_SBHOfObject(currentGUVLeaderObj));
    }
    else if (currentUID[0] == 'A'){//AUV
        currentAUVLeaderObj = CORBA_Object_duplicate(currentUnitObj, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() << "failed to duplicate air leader obj:" << ev.returnCode;
            ILU_C_EXCEPTION_FREE(&ev);
            return false;
        }
        leaderSBH = (char*)ilu_malloc(strlen(ILU_C_SBHOfObject(currentAUVLeaderObj)) + 1);
        strcpy(leaderSBH, ILU_C_SBHOfObject(currentAUVLeaderObj));
    }
    
    // 创建备份Console对象
    backupCosObj = (Console_rpc)ILU_C_SBHToObject(tmpSBH, Console_rpc__MSType, &ev);
    if(!ILU_C_SUCCESSFUL(&ev)) {
        backupCosObj = NULL;
        qDebug() << "failed to create backup Cos Server when set leader:" << ev.returnCode;
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    qDebug() << "get cos obj";
    
    // Ping备份Console对象
    ILU_C_PingObject(backupCosObj, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        backupCosObj = NULL;
        qDebug() << "failed to connect to backup Cos Server when set leader:" << ev.returnCode;
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }

    if (backupCosSBH != NULL)
    ilu_free(backupCosSBH);
    backupCosSBH = (char*)ilu_malloc(strlen(tmpSBH) + 1);
    strcpy(backupCosSBH, tmpSBH);
    currentLeaderUID = (char*)ilu_malloc(MAX_UNITID_LENGTH);
    strcpy(currentLeaderUID, currentUID);
    //写入文件
    backupCosFile = fopen(backupCosNamingServerFileName, "w+");
    fprintf(backupCosFile, "%s\n%s\n%s\n%d\n%d", backupCosSBH, leaderSBH, currentLeaderUID, Unit_UM_None, Unit_UMM_None);
    fclose(backupCosFile);
    qDebug() << "leader information has been wrote into file";
    //遍历获取表信息
    seq = Unit_UnitInfoSeq_Create(0, NULL);

    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);

    while (ilu_hash_Next(&he, &uid, &sbh)) {
        node = (Unit_UnitInfo*)ilu_malloc(sizeof(Unit_UnitInfo));
        node->uid = (char*)ilu_malloc(MAX_UNITID_LENGTH);
        node->sbh = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);

        strcpy(node->uid, (char*)uid);
        strcpy(node->sbh, (char*)sbh);

        Unit_UnitInfoSeq_Append(seq, node, &err);
    }
    //Console_rpc_setCosNamingInfo(backupCosObj, seq, &ev);
    Console_Message m;
    m._d = Console_OP_SetCosInfo;
    m._u.infoSeq = *seq;
    Console_rpc_sendMsg(backupCosObj, &m, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        backupCosObj = NULL;
        qDebug() << "failed to set CosNaming info:" << ev.returnCode;
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    m._d = Console_OP_Opened;
    m._u.details = "running";
    Console_rpc_sendMsg(backupCosObj, &m, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        backupCosObj = NULL;
        qDebug() << "failed to send Opened info:" << ev.returnCode;
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    qDebug() << "finish setting leader cos info";


//遍历setFollowMode - 只设置角色和Leader，不设置模式（模式由setGroupMode设置）
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        if (((char*)uid)[0] == 'G' && strcmp(currentUID, (char*)uid) != 0) {
            qDebug() << "set follower:" << (char*)uid;
            tmpGrdObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
            
            // 设置角色为Follower
            Unit_rpc_setRole(tmpGrdObj, Unit_UR_Follower, "null", &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() << "failed to set role for" << (char*)uid << ":" << ev.returnCode;
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << "follower" << (char*)uid << "role set successfully";
            }
            
            // 设置Leader
            Unit_rpc_setALeader(tmpGrdObj, leaderSBH, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() << "failed to set leader for" << (char*)uid << ":" << ev.returnCode;
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << "follower" << (char*)uid << "leader set successfully";
            }
            
            qDebug() << "follower" << (char*)uid << "configured (role and leader only, mode should be set via setGroupMode)";
            Ground_Unit_rpc__Free(&tmpGrdObj);
        }
    }
    Unit_UnitInfoSeq__Free(seq);//可能内存泄漏
    ilu_free(seq);
    ilu_free(leaderSBH);
    qDebug() << "设置成功！";
    return true;
}

//设置遥控模式 TODO 修订同样需要适合飞机
//bool romoteControl() {

//    Ground_Unit_MoveAction action;
//	char ch;
//	if (currentUnitObj == NULL) {

//        qDebug() <<QStringLiteral("未选定控制单元！");
//        return false;
//    }
//    qDebug() <<QStringLiteral("请输入遥控的线速度：");
//    scanf("%f", &currentCtrlLinearVelocity);
//    qDebug() <<QStringLiteral("请输入遥控的角速度：");
//    scanf("%f", &currentCtrlAngularVelocity);
//    qDebug() <<QStringLiteral("当前线速度：%1, 当前角速度：%2").arg(currentCtrlLinearVelocity).arg(currentCtrlAngularVelocity);
//    qDebug() <<QStringLiteral("ʹ使用WASD控制，按下q退出");
//	ch = getch();
//	while (ch != 81 && ch != 113) {
//		CORBA_Environment ev;
//		switch (ch) {
//		case 87:
//		case 119:
//            action._d = Ground_Unit_MA_GoAhead;
//			action._u.goAheadData.duration.keep = ilu_TRUE;
//			action._u.goAheadData.speed = currentCtrlLinearVelocity;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);

//                qDebug() <<QStringLiteral("Exception: %1").arg(ev.returnCode);

//			break;
//		case 83:
//		case 115:
//            action._d = Ground_Unit_MA_GoBackward;
//			action._u.goBackwardData.duration.keep = ilu_TRUE;
//			action._u.goBackwardData.speed = currentCtrlLinearVelocity;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QStringLiteral("Exception: %1").arg(ev.returnCode);

//			break;
//		case 65:
//		case 97:
//            action._d = Ground_Unit_MA_TurnLeft;
//			action._u.turnLeftData.duration.keep = ilu_TRUE;
//			action._u.turnLeftData.speed = currentCtrlAngularVelocity;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QStringLiteral("Exception: %1").arg(ev.returnCode);

//			break;
//		case 68:
//		case 100:
//            action._d = Ground_Unit_MA_TurnRight;
//			action._u.turnRightData.duration.keep = ilu_TRUE;
//			action._u.turnRightData.speed = currentCtrlAngularVelocity;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QStringLiteral("Exception: %1").arg(ev.returnCode);
//			break;
//		case 88:
//		case 120:
//            action._d = Ground_Unit_MA_Stop;
//			action._u.stopData.keep = ilu_TRUE;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QStringLiteral("Exception: %1").arg(ev.returnCode);
//            break;
//        default:
//            break;
//        }
//        ch = getch();
//    }
//    return true;
//}


//设置个体跟随模式
void setImitateMode() {
    CORBA_Environment ev;
    Ground_Unit_rpc tmp;
    char uid[20], *sbh = NULL;
    CORBA_boolean succ = ilu_FALSE;
    if (currentUnitObj != NULL) {
        qDebug() <<QStringLiteral("请输入当前单元跟随的单元ID：");
        scanf("%s", uid);
        if (strcmp(uid, currentUID) == 0) {
            qDebug() <<QStringLiteral("与当前控制单元相同！");
            return;
         }
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)uid);
        if (sbh == NULL) {
            qDebug() <<QStringLiteral("未绑定的单元ID！");
        return;
        }

        tmp = ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QStringLiteral("%1: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
//         return;
        }
        Unit_rpc_setMode(tmp, Unit_UM_Imitate, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QStringLiteral("%1: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
//          return;
      }
       succ = Unit_rpc_setALeader(currentUnitObj, sbh, &ev);
       if (ILU_C_SUCCESSFUL(&ev) && succ){
            qDebug() <<QStringLiteral("设置成功！");
       }else{
            qDebug() <<QStringLiteral("设置失败！");
       }
//    return;
    }else {
        qDebug() << QStringLiteral("未选定控制单元!");
    }
}



//发送指令序列
//todo 需要搞清楚为什么硬数值16出现在这里,  能不能修改吗?
bool sendCommandSeq(){
    CORBA_Environment ev;
    ilu_Error err;
    int i;
    Unit_ActionSeq* cmdQ = Unit_ActionSeq_Create(16, NULL);
    Unit_MoveAction act[16];
    for (i = 0; i < 16; i += 4) {
        act[i]._d = Unit_MA_GoAhead;
        act[i]._u.goAheadData.speed = 0.05;
        act[i]._u.goAheadData.duration.keep = ilu_FALSE;
        act[i]._u.goAheadData.duration.ft_s = 2;
        act[i]._u.goAheadData.duration.ft_t = 0;
        act[i + 1]._d = Unit_MA_Stop;

        act[i + 1]._u.stopData.keep = ilu_FALSE;
        act[i + 1]._u.stopData.ft_s = 0;
        act[i + 1]._u.stopData.ft_t = 0;

        act[i + 2]._d = Unit_MA_GoBackward;
        act[i + 2]._u.goAheadData.speed = 0.05;

        act[i + 2]._u.goBackwardData.duration.keep = ilu_FALSE;
        act[i + 2]._u.goBackwardData.duration.ft_s = 2;
        act[i + 2]._u.goBackwardData.duration.ft_t = 0;
        act[i + 3]._d = Unit_MA_Stop;
        act[i + 3]._u.stopData.keep = ilu_FALSE;
        act[i + 3]._u.stopData.ft_s = 0;
    }
    for (i=0;i<16;i++) {
     Unit_ActionSeq_Append(cmdQ, &(act[i]), &err);
    }
    Unit_rpc_sendMoveActionSeq(currentUnitObj, cmdQ, 1, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        qDebug() <<QStringLiteral("%1").arg(ev.returnCode);
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    Unit_ActionSeq__Free(cmdQ);
    ilu_free(cmdQ);

    return true;
}



//编队模式的合法性是:
//如果主模式是跟随者模式,那就一定的目标或轨迹跟踪;
// 如果主模式是模拟模式, 那子模式就一定是空
//如果主模式是空, 那自模式也一定是空 .
CORBA_boolean checkValidity(Unit_UnitMode mode, Unit_UnitMinorMode minorMode)
{
    if (mode == Unit_UM_Follow &&
        (minorMode == Unit_UMM_FW_Object || minorMode == Unit_UMM_FW_Track))
        return ilu_TRUE;
    else if (mode == Unit_UM_Imitate && minorMode == Unit_UMM_None)
        return ilu_TRUE;
    else if (mode == Unit_UM_None && minorMode == Unit_UMM_None)
        return ilu_TRUE;
    return ilu_FALSE;

}

//设置团队模式
bool setGroupMode(Unit_UnitMode mode) {
    ilu_refany uid, sbh;
    ilu_HashEnumerator_s he;
    Ground_Unit_rpc grd_tmpObj;
    Air_Unit_rpc air_tmpObj;
    CORBA_Environment ev;
    ilu_Error err;
    CORBA_boolean flag = ilu_FALSE;
    char* leaderSBH = NULL;
    
    qDebug() << QStringLiteral("========== setGroupMode 开始 ==========");
    qDebug() << QStringLiteral("mode=%1 (0=None,1=Follow,2=Imitate,3=Mate)").arg(mode);
    qDebug() << QStringLiteral("currentLeaderUID: %1").arg(currentLeaderUID != NULL ? currentLeaderUID : "NULL");
    qDebug() << QStringLiteral("currentGUVLeaderObj: %1").arg((quintptr)currentGUVLeaderObj, 0, 16);
    qDebug() << QStringLiteral("currentAUVLeaderObj: %1").arg((quintptr)currentAUVLeaderObj, 0, 16);
    
    if ( currentGUVLeaderObj == NULL && currentAUVLeaderObj == NULL ) {
        qDebug() <<QStringLiteral("错误：未设置队伍！必须先调用 setToLeader() 设置Leader");
        qDebug() <<QStringLiteral("提示：正确流程是 getUnitObject(leaderUID) → setToLeader() → setGroupMode(mode)");
        return false;
    }
    
    // 获取Leader的SBH
    if (currentGUVLeaderObj != NULL) {
        leaderSBH = (char*)ilu_malloc(strlen(ILU_C_SBHOfObject(currentGUVLeaderObj)) + 1);
        strcpy(leaderSBH, ILU_C_SBHOfObject(currentGUVLeaderObj));
        qDebug() << QStringLiteral("地面Leader对象地址: %1").arg((quintptr)currentGUVLeaderObj, 0, 16);
        qDebug() << QStringLiteral("地面Leader SBH: %1").arg(leaderSBH);
    } else if (currentAUVLeaderObj != NULL) {
        leaderSBH = (char*)ilu_malloc(strlen(ILU_C_SBHOfObject(currentAUVLeaderObj)) + 1);
        strcpy(leaderSBH, ILU_C_SBHOfObject(currentAUVLeaderObj));
        qDebug() << QStringLiteral("空中Leader对象地址: %1").arg((quintptr)currentAUVLeaderObj, 0, 16);
        qDebug() << QStringLiteral("空中Leader SBH: %1").arg(leaderSBH);
    }
    
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        if(((char*)uid)[0] != 'G')  //只处理地面单元
            continue;
        if(((char*)uid)[2] == '1')
        {
            qDebug() <<QStringLiteral("开始设置飞机的团队模式");
            air_tmpObj = (Air_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Air_Unit_rpc__MSType, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() << QStringLiteral("无法创建空中单元对象 %1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
                continue;
            }
            qDebug() <<QStringLiteral("完成设置飞机的团队模式");

            qDebug() <<QStringLiteral("set %1 mode start").arg((char*)uid);
            flag = Unit_rpc_setMode(air_tmpObj, mode, &ev);//设置模式
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QStringLiteral("%1 模式设置失败: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << QStringLiteral("%1 模式设置为 %2").arg((char*)uid).arg(mode);
            }
            
            // 设置次级模式
            qDebug() << QStringLiteral("[空中单元] 准备设置 %1 的次级模式，mode=%2").arg((char*)uid).arg(mode);
            Unit_UnitMinorMode minorMode = Unit_UMM_None;
            
            if (mode == Unit_UM_Follow) {
                minorMode = Unit_UMM_FW_Object;
                qDebug() << QStringLiteral("[空中单元] %1: 跟随模式(Follow)，MinorMode=FW_Object(%2)").arg((char*)uid).arg((int)minorMode);
            } else if (mode == Unit_UM_Imitate) {
                minorMode = Unit_UMM_None;
                qDebug() << QStringLiteral("[空中单元] %1: 模仿模式(Imitate)，MinorMode=None(%2)").arg((char*)uid).arg((int)minorMode);
            }
            
            // 总是调用 setMinorMode
            qDebug() << QStringLiteral("[空中单元] 调用 Unit_rpc_setMinorMode for %1, minorMode=%2").arg((char*)uid).arg((int)minorMode);
            flag = Unit_rpc_setMinorMode(air_tmpObj, minorMode, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QStringLiteral("[空中单元] 设置次级模式失败 %1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << QStringLiteral("✓✓✓ [空中单元] %1 次级模式设置成功，值为 %2 ✓✓✓").arg((char*)uid).arg(minorMode);
            }
            
            Air_Unit_rpc__Free(&air_tmpObj);

        }
        else {
            grd_tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() << QStringLiteral("无法创建单元对象 %1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
                continue;
            }

            qDebug() <<QStringLiteral("set %1 mode start").arg((char*)uid);
            
            // 检查是否为Leader
            bool isLeader = (currentLeaderUID != NULL && strcmp((char*)uid, currentLeaderUID) == 0);
            
            if (isLeader) {
                qDebug() << QStringLiteral("%1 是Leader，设置Leader角色").arg((char*)uid);
                
                // 设置角色为Leader - 关键！Leader必须知道自己是Leader
                Unit_rpc_setRole(grd_tmpObj, Unit_UR_Leader, "ilusbh:sau/console;IDL%3AConsole%2Frpc%3A1.0;iiop@tcp_192.168.1.110_5000", &ev);
                if (!ILU_C_SUCCESSFUL(&ev)) {
                    qDebug() << QStringLiteral("设置Leader角色失败 %1: %2").arg((char*)uid).arg(ev.returnCode);
                    ILU_C_EXCEPTION_FREE(&ev);
                } else {
                    qDebug() << QStringLiteral("✓✓✓ %1 Leader角色设置成功 ✓✓✓").arg((char*)uid);
                }
            } else {
                qDebug() << QStringLiteral("设置 %1 为跟随者").arg((char*)uid);
                
                // 设置角色为Follower
                Unit_rpc_setRole(grd_tmpObj, Unit_UR_Follower, "null", &ev);
                if (!ILU_C_SUCCESSFUL(&ev)) {
                    qDebug() << QStringLiteral("设置角色失败 %1: %2").arg((char*)uid).arg(ev.returnCode);
                    ILU_C_EXCEPTION_FREE(&ev);
                } else {
                    qDebug() << QStringLiteral("✓ %1 Follower角色设置成功").arg((char*)uid);
                }
                
                // 设置Leader
                if (leaderSBH != NULL) {
                    Unit_rpc_setALeader(grd_tmpObj, leaderSBH, &ev);
                    if (!ILU_C_SUCCESSFUL(&ev)) {
                        qDebug() << QStringLiteral("设置Leader失败 %1: %2").arg((char*)uid).arg(ev.returnCode);
                        ILU_C_EXCEPTION_FREE(&ev);
                    } else {
                        qDebug() << QStringLiteral("✓ %1 的Leader已设置为 %2").arg((char*)uid).arg(currentLeaderUID);
                    }
                }
            }
            
            // 设置模式
            flag = Unit_rpc_setMode(grd_tmpObj, mode, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QStringLiteral("设置模式失败 %1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << QStringLiteral("%1 模式设置为 %2").arg((char*)uid).arg(mode);
            }
            
            // 设置次级模式（MinorMode）- 关键！
            // 根据checkValidity函数：Follow需要FW_Object，Imitate需要None
            qDebug() << QStringLiteral("准备设置 %1 的次级模式，mode=%2 (0=None,1=Follow,2=Imitate)").arg((char*)uid).arg(mode);
            Unit_UnitMinorMode minorMode = Unit_UMM_None;
            
            if (mode == Unit_UM_Follow) {
                // 跟随模式需要 FW_Object
                minorMode = Unit_UMM_FW_Object;
                qDebug() << QStringLiteral("%1: 跟随模式(Follow)，MinorMode=FW_Object(%2)").arg((char*)uid).arg((int)minorMode);
            } else if (mode == Unit_UM_Imitate) {
                // 模仿模式需要 None！（根据checkValidity）
                minorMode = Unit_UMM_None;
                qDebug() << QStringLiteral("%1: 模仿模式(Imitate)，MinorMode=None(%2)").arg((char*)uid).arg((int)minorMode);
            } else {
                qDebug() << QStringLiteral("%1: 其他模式(mode=%2)，MinorMode=None").arg((char*)uid).arg(mode);
            }
            
            // 总是调用 setMinorMode，即使是 None
            qDebug() << QStringLiteral("调用 Unit_rpc_setMinorMode for %1, minorMode=%2").arg((char*)uid).arg((int)minorMode);
            flag = Unit_rpc_setMinorMode(grd_tmpObj, minorMode, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QStringLiteral("设置次级模式失败 %1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << QStringLiteral("✓✓✓ %1 次级模式设置成功，值为 %2 ✓✓✓").arg((char*)uid).arg(minorMode);
            }
            
            Ground_Unit_rpc__Free(&grd_tmpObj);
        }

        if (!flag) {
            qDebug() <<QStringLiteral("当前无法切换模式，已取消！");
            break;
        }
    }
    
    if (leaderSBH != NULL) {
        ilu_free(leaderSBH);
    }
    if (flag){
        FILE* backupCosFile;
        char* backupCosSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        char *leaderSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        Unit_UnitMinorMode defaultMinorMode = Unit_UMM_None;
        if (mode == Unit_UM_Follow || mode == Unit_UM_Imitate)
            defaultMinorMode = Unit_UMM_FW_Object;

        qDebug() <<QStringLiteral("模式设置成功！");
        backupCosFile = fopen(backupCosNamingServerFileName, "r");
        if (backupCosFile != NULL) {
            fscanf(backupCosFile, "%s\n%s\n", backupCosSBH, leaderSBH);
            fclose(backupCosFile);
        }
        backupCosFile = fopen("tmp.txt", "w");
        if (backupCosFile != NULL){
            fprintf(backupCosFile, "%s\n%s\n%s\n%d\n%d", backupCosSBH, leaderSBH, currentLeaderUID, mode, defaultMinorMode);
            fclose(backupCosFile);
        }
        remove(backupCosNamingServerFileName);
        rename("tmp.txt", backupCosNamingServerFileName);
        ilu_free(backupCosSBH);
        ilu_free(leaderSBH);
        currentMode = mode;
        currentMinorMode = defaultMinorMode;
        return true;
    }
    return false;
}

bool setGroupMinorMode(Unit_UnitMinorMode minorMode)
{
    ilu_refany uid, sbh;
    ilu_HashEnumerator_s he;
    Ground_Unit_rpc tmpObj;
    CORBA_Environment ev;
    ilu_Error err;
    CORBA_boolean flag = ilu_FALSE;
    if (currentGUVLeaderObj == NULL) {

        qDebug() <<QStringLiteral("未设置队伍！");
        return false;
    }
    if (!checkValidity(currentMode, minorMode)){
        qDebug() <<QStringLiteral("次级模式错误！");
        return false;
    }
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        if(((char*)uid)[0] != 'G')//仅设置无人车
            continue;
        tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
        qDebug() <<QStringLiteral("set %1 mode start").arg((char*)uid);
        flag = Unit_rpc_setMinorMode(tmpObj, minorMode, &ev);//设置模式
        if (!ILU_C_SUCCESSFUL(&ev)) {

            qDebug() <<QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
        }
        Ground_Unit_rpc__Free(&tmpObj);
        if (!flag) {
            qDebug() <<QStringLiteral("当前无法切换模式，已取消！");
            break;
        }
    }
    if (flag)
    {
        FILE* backupCosFile;
        char* backupCosSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        char *leaderSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        qDebug() <<QStringLiteral("模式设置成功！");
        backupCosFile = fopen(backupCosNamingServerFileName, "r");
        if (backupCosFile != NULL){
            fscanf(backupCosFile, "%s\n%s\n", backupCosSBH, leaderSBH);
            fclose(backupCosFile);
        }
        backupCosFile = fopen("tmp.txt", "w");
        if (backupCosFile != NULL){
            fprintf(backupCosFile, "%s\n%s\n%s\n%d\n%d", backupCosSBH, leaderSBH, currentLeaderUID, currentMode, minorMode);
            fclose(backupCosFile);
        }
        remove(backupCosNamingServerFileName);
        rename("tmp.txt", backupCosNamingServerFileName);
        ilu_free(backupCosSBH);
        ilu_free(leaderSBH);
        currentMinorMode = minorMode;
        return true;
    }
    return false;
}


//���ö���
bool setFormation(Unit_Formation* formation) {
    Ground_Unit_rpc grd_tmpObj;
    Air_Unit_rpc air_tmpObj;
    CORBA_Environment en;
    Unit_UnitInfoSeq* unitInfoSeq;
    //store formation
    ilu_Error error;
    CORBA_boolean flag;
    char* sbh, *followerSbh;
    int done;
    int i = 0, j = 0;

    Unit_rpc_setFormation(currentGUVLeaderObj, formation, &en);
    if (!ILU_C_SUCCESSFUL(&en)) {

        qDebug() <<QStringLiteral("exception: %1").arg(en.returnCode);
        ILU_C_EXCEPTION_FREE(&en);
        return false;
    }
    qDebug() <<QStringLiteral("飞机开始设置编队信息");
    done = 1;
    for (i = 0; i < currentGUVNum; i++) {
        ilu_Error ie;
        unitInfoSeq = Unit_UnitInfoSeq_Create(0, NULL);
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, *(Unit_UnitIDSeq_Nth(&formation->robot_ids, i)));
        qDebug() <<sbh;
        if(i==0){
          air_tmpObj = ILU_C_SBHToObject(sbh, Air_Unit_rpc__MSType, &en);
        }
        else{
          grd_tmpObj = ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &en);
        }
        if (grd_tmpObj == NULL){
            qDebug() <<QStringLiteral("grd_tmpObj NULL");
        }

        if (air_tmpObj == NULL)
            qDebug() <<QStringLiteral("air_tmpObj NULL");

        for (j = 1; j < currentGUVNum && done != currentGUVNum; j++) {
            if ((*Unit_ShortSeq_Nth(&formation->leader_ids, j)) == i) {
                Unit_UnitInfo tmp;
                char** robot_idsj = Unit_UnitIDSeq_Nth(&formation->robot_ids, j);

                followerSbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, *robot_idsj);

                tmp.uid = (char*)ilu_malloc(strlen(*robot_idsj) + 1);
                strcpy(tmp.uid, *robot_idsj);
                tmp.sbh = (char*)ilu_malloc(strlen(followerSbh) + 1);
                strcpy(tmp.sbh, followerSbh);
                Unit_UnitInfoSeq_Append(unitInfoSeq, &tmp, &ie);
                done++;
            }
        }
        if(i!=0)
        {
            qDebug() <<QStringLiteral("开始设置后车信息");
            flag = Unit_rpc_setRearVehicles(grd_tmpObj, unitInfoSeq,
                (*Unit_FloatSeq_Nth(&formation->distances, i)),
                (*Unit_FloatSeq_Nth(&formation->angles, i)), &en);
             qDebug() <<QStringLiteral("完成设置后车信息");
        }
        else {
              qDebug() <<QStringLiteral("飞机开始设置后车信息");
            flag = Unit_rpc_setRearVehicles(air_tmpObj, unitInfoSeq,
                (*Unit_FloatSeq_Nth(&formation->distances, i)),
                (*Unit_FloatSeq_Nth(&formation->angles, i)), &en);
            flag=ilu_TRUE;
               qDebug() <<QStringLiteral("飞机完成设置后车信息");
        }


        Unit_UnitInfoSeq__Free(unitInfoSeq);
        if (flag == ilu_FALSE)
        {
            qDebug() <<QStringLiteral("%1:当前状态无法设置队形,已取消。").arg(*Unit_UnitIDSeq_Nth(&formation->robot_ids, i));
            return false;
        }
        else
            qDebug() <<QStringLiteral("设置%1的队形成功！").arg(*(Unit_UnitIDSeq_Nth(&formation->robot_ids, i)));
    }

    return true;
}

bool setTaskPoint(float x, float y) {
    CORBA_Environment ev;
    ilu_Error e;
    CORBA_boolean flag = 1;
    int num;
    Ground_Unit_Point2D point;

    point.x = x;
    point.y = y;
    flag = Ground_Unit_rpc_setTaskPoint(currentUnitObj, &point, &ev);
    if (!flag) {

        qDebug() <<QStringLiteral("当前状态无法设置任务路径，已取消！");
        return false;
    }else
        qDebug() <<QStringLiteral("任务点设置成功！");
    return true;
}



//单元停止
//todo: 现在停止的是车, 需要考虑飞机
//todo: 需要考虑屡顺IDL部分的共性转移到Unit中 .
//void stopUnit() {
//    Ground_Unit_MoveAction action;
//    CORBA_Environment ev;
//    if (currentUnitObj == NULL) {
//        qDebug() <<QStringLiteral("未选定控制单元！");
//        return;
//    }
//    action._d = Ground_Unit_MA_Stop;
//	action._u.stopData.ft_s = 0;
//	action._u.stopData.ft_t = 0;
//    Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);

//   if(ILU_C_SUCCESSFUL(&ev)){
//        qDebug() <<QStringLiteral("指令成功！");
//    }else{
//        qDebug() <<QStringLiteral("出现异常%1").arg(ev.returnCode);
//    }
//    return;
//}


//重置单元间关系
void setDefault() {
    ilu_refany uid, sbh;
    ilu_HashEnumerator_s he;
    Ground_Unit_rpc tmpObj;
    CORBA_Environment ev;
    
    if (currentGUVNum == 0 && currentAUVNum == 0)
        return;
    
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        if (((char*)uid)[0] != 'G')
            continue;
        tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
        Unit_rpc_setRole(tmpObj, Unit_UR_None, "null", &ev);//设置角色
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() << QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
        }
        Ground_Unit_rpc__Free(&tmpObj);
    }
    
    //清除Leader相关信息
    if (currentLeaderUID != NULL) {
        ilu_free(currentLeaderUID);
        currentLeaderUID = NULL;
    }
    if (currentGUVLeaderObj != NULL) {
        Ground_Unit_rpc__Free(&currentGUVLeaderObj);
        currentGUVLeaderObj = NULL;
    }
    if (backupCosObj != NULL) {
        Console_rpc__Free(&backupCosObj);
        backupCosObj = NULL;
    }
    if (!remove(backupCosNamingServerFileName))
        qDebug() << QStringLiteral("已清除文件%1").arg(backupCosNamingServerFileName);
    else
        qDebug() << QStringLiteral("文件%1不存在或正在被使用").arg(backupCosNamingServerFileName);
}

bool setTrap(Console_TrapPoint trap){
     ilu_refany uid, sbh;
     ilu_HashEnumerator_s he;
     Ground_Unit_rpc tmpGrdObj;
     Air_Unit_rpc tmpSkyObj;
     CORBA_Environment ev;
     ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    /*写入备份文件*/
    FILE* trapsBackupFile;
    if (currentTrapPointsNum == MAX_TRAP_POINT_NUM) {
        qDebug() <<QStringLiteral("[setTrap] traps overflow, opertaion cancelled.");
        return false; }//endif

    trapPoints[currentTrapPointsNum] = trap;
    currentTrapPointsNum++;
    trapsBackupFile = fopen(backupTrapsFileName, "a+");
    fprintf(trapsBackupFile, "%f,%f,%f\n", trap._u.trapPoint2D.point.x, trap._u.trapPoint2D.point.y, trap._u.trapPoint2D.radius);
    fclose(trapsBackupFile);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
          if (((char *)uid)[0] == 'G') {
            tmpGrdObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
         Ground_Unit_rpc_setTrapPoint(tmpGrdObj, &trap._u.trapPoint2D, &ev);
         if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);}//endif
        if (tmpGrdObj) Ground_Unit_rpc__Free(&tmpGrdObj); } //endif

     if (((char *)uid)[0] == 'A') {
            tmpSkyObj = (Air_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Air_Unit_rpc__MSType, &ev);
         Air_Unit_rpc_setTrapPoint(tmpSkyObj, &trap._u.trapPoint3D, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);}//endif
        Air_Unit_rpc__Free(&tmpSkyObj); } //endif
    }//end while

  return true;
}

bool clearTraps(){
     ilu_refany uid, sbh;
     ilu_HashEnumerator_s he;
    Ground_Unit_rpc tmpGrdObj;
    Air_Unit_rpc tmpAirObj;
    CORBA_Environment ev;
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
            if (((char *)uid)[0] == 'G') {
                tmpGrdObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
                Ground_Unit_rpc_clearTraps(tmpGrdObj, &ev);
                if (!ILU_C_SUCCESSFUL(&ev)) {
                    qDebug() <<QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
                    ILU_C_EXCEPTION_FREE(&ev);
               } //endif  env
            if (tmpGrdObj) Ground_Unit_rpc__Free(&tmpGrdObj);
        } //end if ...G
        if (((char *)uid)[0] == 'A') {
            tmpAirObj = (Air_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Air_Unit_rpc__MSType, &ev);
            Air_Unit_rpc_clearTraps(tmpAirObj, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
            } //endif  env
                if (tmpAirObj) Air_Unit_rpc__Free(&tmpAirObj);
        } //end if ...A
    } //end while ...sbh

        currentTrapPointsNum = 0;
        remove(backupTrapsFileName);
        return true;
}

void shutDownAllUnit()
{
    ilu_refany uid, sbh;
    ilu_HashEnumerator_s he;
    Unit_rpc tmpObj;
    CORBA_Environment ev;
    if(currentGUVNum == 0&&currentAUVNum==0)
        return;
    //重置车间关系
    setDefault();
    //关闭单元程序
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {

        tmpObj = (Unit_rpc)ILU_C_SBHToObject((char*)sbh, Unit_rpc__MSType, &ev);
        Unit_rpc_shutDown(tmpObj, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
        }//end if of ev

        Unit_rpc__Free(&tmpObj);
    }
    //清除当前全局变量
    currentGUVNum = 0;
    currentAUVNum = 0;
    if (Units_Hash_Table != NULL){
        ilu_hash_FreeHashTable(Units_Hash_Table, ilu_free, ilu_free);
        Units_Hash_Table = NULL;
    }

    currentMode = Unit_UM_None;
    currentMinorMode = Unit_UMM_None;
    if (currentUID != NULL) {
        ilu_free(currentUID);
        currentUID = NULL;
    }
    if (currentUnitObj != NULL){
        Unit_rpc__Free(&currentUnitObj);
        currentUnitObj = NULL;
    }
    if (currentGrdUnitObj != NULL){
        Ground_Unit_rpc__Free(&currentGrdUnitObj);
        currentUnitObj = NULL;
    }
    if (currentAirUnitObj != NULL){
        Air_Unit_rpc__Free(&currentAirUnitObj);
        currentAirUnitObj = NULL;
    }
    if (!remove(backupFileName))
        qDebug() <<QStringLiteral("已清除文件%1").arg(backupFileName);
    else
        qDebug() <<QStringLiteral("文件%1不存在或正在被使用").arg(backupFileName);
    if (Units_Hash_Table != NULL){
        ilu_hash_FreeHashTable(Units_Hash_Table, ilu_free, ilu_free);
        Units_Hash_Table = NULL;
    }
    Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM, ilu_hash_HashString, ilu_hash_StringCompare);
    qDebug() <<QStringLiteral("已经重置cosnaming表");
    displayBoundUnit();
}

void usage(char* prom) {
    qDebug() <<QStringLiteral("%1用法：\t-host\t服务器主机地址\t-port\t服务器端口地址"
        "\t-sid\t服务器ID\t-ih\tInstance Handle"
        "\t-trans\t服务器传输层协议\t-protocol\t服务器应用层协议"
        "\t-httpPort\tMCP HTTP API 端口(默认9001)\t-noHttp\t禁用 HTTP API"
        "\t-mockRobots\t测试用模拟车 unit_id 列表，逗号分隔，如 GV1 或 GV1,GV2").arg(prom);
}

/**
 * @brief 注册测试用 MOCK 单元；当 uid 已存在时覆盖旧绑定（如历史真实 SBH）。
 *
 * @param commaSeparatedUnitIds 逗号分隔 unit_id，例如 "GV1,GV2,GV3"
 * @description
 * 过去逻辑在 uid 已存在时直接 skip，导致历史备份里的真实 SBH（如 GV1 -> ilusbh:...）
 * 无法被 -mockRobots 覆盖。这里改为“同名即替换为 MOCK:uid”，避免每次手工删除备份文件。
 */
void registerMockRobotsForTest(const QString &commaSeparatedUnitIds) {
    const QString csv = commaSeparatedUnitIds.trimmed();
    if (csv.isEmpty())
        return;
    if (Units_Hash_Table == NULL)
        Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM, ilu_hash_HashString, ilu_hash_StringCompare);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    const QStringList parts = csv.split(QLatin1Char(','), Qt::SkipEmptyParts);
#else
    const QStringList parts = csv.split(QLatin1Char(','), QString::SkipEmptyParts);
#endif
    for (QString uid : parts) {
        uid = uid.trimmed();
        if (uid.isEmpty())
            continue;
        QByteArray uba = uid.toUtf8();
        const ilu_refany existed = ilu_hash_FindInTable(Units_Hash_Table, reinterpret_cast<ilu_refany>(uba.data()));
        const bool hasExisting = (existed != ILU_NIL);
        if (hasExisting) {
            ilu_hash_RemoveFromTable(Units_Hash_Table, reinterpret_cast<ilu_refany>(uba.data()));
            qDebug() << QStringLiteral("[MOCK] override existing uid %1").arg(uid);
        }
        char *uidStr = (char *)ilu_malloc((size_t)uba.size() + 1);
        strcpy(uidStr, uba.constData());
        const QString sbhQ = QStringLiteral("MOCK:") + uid;
        QByteArray sba = sbhQ.toUtf8();
        char *sbhStr = (char *)ilu_malloc((size_t)sba.size() + 1);
        strcpy(sbhStr, sba.constData());
        ilu_hash_AddToTable(Units_Hash_Table, uidStr, sbhStr);
        if (!hasExisting && uidStr[0] == 'G')
            currentGUVNum++;
        else if (!hasExisting && uidStr[0] == 'A')
            currentAUVNum++;
        MockRobotSimulator::instance().ensureUnit(uid);
        qDebug() << QStringLiteral("[MOCK] registered uid=%1 sbh=%2").arg(uid).arg(sbhQ);
    }
    if (st)
        emit st->infoAppended(QStringLiteral("[MOCK] 已注册模拟单元（仅 HTTP/MCP 可控制运动学）：%1").arg(csv));
}

ilu_boolean safe_strcpy(char* des, int size, char* from) {
    if (strlen(from) + 1 <= size) {
        strcpy(des, from);
        return ilu_TRUE;
    }
    return ilu_FALSE;
}

int main(int argc, char** args) {
    QApplication a(argc, args);
    st = new ServerThread();
    MainWindow w;
    UserInter = &w;
    //分配用户输入的参数
    int i = 1;
    char ch;
    CORBA_Environment ev;
    int httpPort = 9001;
    bool httpEnable = true;
    QHostAddress httpBind = QHostAddress::LocalHost;
    QString mockRobotsArg;
    //need remove sometime soon
    getLocalIP();
    while (i < argc) {
        if (strcmp(args[i], "-host") == 0)
            if (i++ < argc)
                safe_strcpy(host, 20, args[i++]);
            else
                usage(args[0]);
        else if (strcmp(args[i], "-sid") == 0)
            if (i++ < argc)
                safe_strcpy(sid, 20, args[i++]);
            else
                usage(args[0]);
        else if (strcmp(args[i], "-port") == 0)
            if (i++ < argc)
                safe_strcpy(port, 10, args[i++]);
            else
                usage(args[0]);
        else if (strcmp(args[i], "-ih") == 0)
            if (i++ < argc)
                safe_strcpy(instanceHandle, 20, args[i++]);
            else
                usage(args[0]);
        else if (strcmp(args[i], "-trans") == 0)
            if (i++ < argc)
                safe_strcpy(transProctocol, 20, args[i++]);
            else
                usage(args[0]);
        else if (strcmp(args[i], "-protocol") == 0)
            if (i++ < argc)
                safe_strcpy(protocol, 20, args[i++]);
            else
                usage(args[0]);
        else if (strcmp(args[i], "-httpPort") == 0) {
            if (i++ < argc)
                httpPort = atoi(args[i++]);
            else
                usage(args[0]);
        } else if (strcmp(args[i], "-httpBind") == 0) {
            if (i++ < argc) {
                QHostAddress tmp;
                if (tmp.setAddress(QString::fromLocal8Bit(args[i++])))
                    httpBind = tmp;
                else
                    qDebug() << QStringLiteral("无效 -httpBind，使用 127.0.0.1");
            } else
                usage(args[0]);
        } else if (strcmp(args[i], "-noHttp") == 0) {
            httpEnable = false;
            i++;
        } else if (strcmp(args[i], "-mockRobots") == 0) {
            if (i++ < argc)
                mockRobotsArg = QString::fromLocal8Bit(args[i++]);
            else
                usage(args[0]);
        } else {
            i++;
            usage(args[0]);
        }
    }
    qDebug() <<QStringLiteral("完成参数解析");
    ILU_C_USE_OS_THREADS;
    if (!init()){
        qDebug() << "init failed in main of console";
        return 1;
    }
    qDebug() <<QStringLiteral("服务器已启动");
    qDebug() <<QStringLiteral("服务器：%1").arg(ILU_C_SBHOfObject(serviceObj));

    QObject::connect (st,SIGNAL(bindInfoChanged(QString)),UserInter,SLOT(updateBrowser(QString)));
    QObject::connect (st,SIGNAL(infoAppended(QString)),UserInter,SLOT(appendInfo(QString)));
    if (!mockRobotsArg.isEmpty())
        registerMockRobotsForTest(mockRobotsArg);
    displayBoundUnit();
    st->start();
    HttpApiExecutor *httpApi = nullptr;
    HttpPlugin *httpPlugin = nullptr;
    if (httpEnable && httpPort > 0 && httpPort <= 65535) {
        httpApi = new HttpApiExecutor(&a);
        httpPlugin = new HttpPlugin(httpApi, &a);
        if (!httpPlugin->start(quint16(httpPort), httpBind))
            qDebug() << QStringLiteral("HTTP 插件未启动");
    }
    w.show();
    return a.exec();
}

CORBA_boolean server_Console_rpc_setCosNamingInfo
    (Console_rpc _handle, Unit_UnitInfoSeq* infoSeq, ILU_C_ENVIRONMENT *_status){
    qDebug() <<QStringLiteral("[setCosNamingInfo]no implement");
    Console__BindExceptionValue(_status, ex_CORBA_NO_IMPLEMENT);
    return ilu_FALSE;

}

Unit_UnitInfoSeq* server_Console_rpc_getCosNamingInfo(Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    qDebug() <<QStringLiteral("[getCosNamingInfo]no implement");
    Console__BindExceptionValue(_status, ex_CORBA_NO_IMPLEMENT);
    return NULL;
}

CORBA_boolean handleBindOperation(Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status)
{
    char *uidStr = NULL, *sbhStr = NULL;
    if (Units_Hash_Table == NULL){
        Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM, ilu_hash_HashString, ilu_hash_StringCompare);
    }//end if NULL
    if (ilu_hash_FindInTable(Units_Hash_Table, uid) == ILU_NIL) {
        //将当前UID插入到一般单元哈西表中
        uidStr = (char*)ilu_malloc(sizeof(char)*strlen(uid) + 1);
        strcpy(uidStr, uid);
        sbhStr = (char*)ilu_malloc(sizeof(char)*strlen(sbh) + 1);
        strcpy(sbhStr, sbh);
        ilu_hash_AddToTable(Units_Hash_Table, uidStr, sbhStr);
        if(uidStr[0] == 'G'){
            currentGUVNum++;
        }
        if(uidStr[0] == 'A'){
            currentAUVNum++;
        }
        //添加到本地文件
        backupFile = fopen(backupFileName, "a+");
        fprintf(backupFile, "%s %s\n", uid, sbh);
        fclose(backupFile);
        qDebug() <<QStringLiteral("[handleBindOperation] done.");
        return ilu_TRUE;
    }else {
        Console__BindExceptionValue(_status, ex_Console_rpc_AlreadyBind);
        return ilu_FALSE;
    }
}



CORBA_boolean server_Console_rpc_bind(Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status) {
    Unit_rpc tmpObj = NULL;
    
    //如果有leader，去leader处注册，设置角色、设置leader、设置模式、加入队形都由leader来做
    //如果当前有leader，左leader处理域，设置角色等，设置Leader已由Leader承诺
    if (handleBindOperation(uid, sbh, _status)) {
        tmpObj = (Unit_rpc)ILU_C_SBHToObject(sbh, Unit_rpc__MSType, _status);
        
        if (currentGUVLeaderObj != NULL) {
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QStringLiteral("[bind] %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setRole(tmpObj, Unit_UR_Follower, "null", _status);//设置角色
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QStringLiteral("[bind] (setRole) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setALeader(tmpObj, ILU_C_SBHOfObject(currentGUVLeaderObj), _status);//设置leader
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QStringLiteral("[bind] (setALeader) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setMode(tmpObj, currentMode, _status);//设置模式
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QStringLiteral("[bind] (setMode) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setMinorMode(tmpObj, currentMinorMode, _status);//设置次模式
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QStringLiteral("[bind] (setMinorMode) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            if (backupCosObj != NULL) {
                Console_Message m;
                m._d = Console_OP_Bind;
                m._u.bindInfo.uid = uid;
                m._u.bindInfo.sbh = sbh;
                Console_rpc_sendMsg(backupCosObj, &m, _status);//传输信息到备份cos
            }
        }
        
        for (int i = 0; i < currentTrapPointsNum; i++) {
            Ground_Unit_rpc_setTrapPoint(tmpObj, &trapPoints[i]._u.trapPoint2D, _status);//设置陷阱点
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QStringLiteral("[bind] (setTrap) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
            }
        }
        
        qDebug() << QStringLiteral("[bind]单元%1已绑定此控制台").arg(uid);
        Unit_rpc__Free(&tmpObj);
        displayBoundUnit();//update
        return ilu_TRUE;
    }
    
    return ilu_TRUE;
}

ilu_boolean removeFromBackupFile (Unit_UnitID uid) {
    char u[MAX_UNITID_LENGTH], s[MAX_UNITSBH_LENGTH], buf[1024];
    ilu_boolean removed = ilu_FALSE;
    int curr, tail;
    FILE *tmp = fopen("tmp.txt", "w+");
    backupFile = fopen(backupFileName, "r");
    while (!feof(backupFile)){
        fscanf(backupFile, "%s %s\n", u, s);
        if (strcmp(uid, u) != 0){
            fprintf(tmp, "%s %s\n", u, s);
        }
        else {
            removed = ilu_TRUE;
            continue;
        }
    }
    fclose(backupFile);
    fclose(tmp);
    if(!removed){
        remove("tmp.txt");
        qDebug() <<QStringLiteral("item %1 not found in backup file").arg(uid);
        return ilu_FALSE;
    }
    else {
        remove(backupFileName);
        rename("tmp.txt", backupFileName);
    }
    displayBoundUnit();
    return ilu_TRUE;
}

CORBA_boolean server_Console_rpc_unbind(Console_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status)
{
    if (Units_Hash_Table != NULL) {
        if (ilu_hash_FindInTable(Units_Hash_Table, uid) != ILU_NIL) {
            if (currentLeaderUID != NULL && strcmp(uid, currentLeaderUID) == 0) {//清除leader相关数据，车间关系重置
                qDebug() << QStringLiteral("[unbind] Leader calling unbind!");
                //遍历setFollowMode
                ilu_refany uid, sbh;
                ilu_HashEnumerator_s he;
                CORBA_Environment ev;
                Ground_Unit_rpc tmpObj;
                ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
                while (ilu_hash_Next(&he, &uid, &sbh)) {
                    if (strcmp((char*)uid, currentLeaderUID) != 0) {
                        qDebug() << QStringLiteral("[unbind] set None role for %1").arg((char*)uid);
                        tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
                        Unit_rpc_setRole(tmpObj, Unit_UR_None, "null", &ev);
                        if (!ILU_C_SUCCESSFUL(&ev)) {
                            qDebug() << QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
                            ILU_C_EXCEPTION_FREE(&ev);
                        }
                        Ground_Unit_rpc__Free(&tmpObj);
                    }
                }
                if (currentGUVLeaderObj != NULL) {
                    qDebug() << QStringLiteral("[unbind] set None role for Learder %1").arg((char*)uid);
                    Unit_rpc_setRole(currentGUVLeaderObj, Unit_UR_None, "null", &ev);
                    if (!ILU_C_SUCCESSFUL(&ev)) {
                        qDebug() << QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
                        ILU_C_EXCEPTION_FREE(&ev);
                    }
                    Ground_Unit_rpc__Free(&currentGUVLeaderObj);
                    currentGUVLeaderObj = NULL;
                }
                if (currentLeaderUID != NULL) {
                    ilu_free(currentLeaderUID);
                    currentLeaderUID = NULL;
                }
                if (backupCosObj != NULL) {
                    Console_rpc__Free(&backupCosObj);
                    backupCosObj = NULL;
                }
                if (backupCosSBH != NULL) {
                    ilu_free(backupCosSBH);
                    backupCosSBH = NULL;
                }
            }
            ilu_hash_RemoveFromTable(Units_Hash_Table, uid);
            if (uid[0] == 'G')
                currentGUVNum--;
            if (uid[0] == 'A')
                currentAUVNum--;
            removeFromBackupFile(uid);
            if (backupCosObj != NULL) {
                Console_Message m;
                m._d = Console_OP_Unbind;
                m._u.unbindInfo.uid = uid;
                m._u.unbindInfo.details = details;
                Console_rpc_sendMsg(backupCosObj, &m, _status);
            }
            qDebug() << QStringLiteral("[unbind] 单元%1已解除绑定, details = %2").arg(uid).arg(details);
            return ilu_TRUE;
        }
        else {
            Console__BindExceptionValue(_status, ex_Console_rpc_NotFound);
            return ilu_FALSE;
        }
    }
    else
        return ilu_FALSE;
}

CORBA_boolean server_Console_rpc_sendMsg(Console_rpc _handle, Console_Message* m, ILU_C_ENVIRONMENT *_status)
{
    FILE* trapsBackupFile;
    ilu_refany uid, sbh;
    ilu_HashEnumerator_s he;
    Ground_Unit_rpc tmpObj;
    CORBA_Environment ev;
    switch (m->_d)
    {
    case Console_OP_Bind:
        qDebug() <<QStringLiteral("[sendMsg] Bind.");
        handleBindOperation(m->_u.bindInfo.uid, m->_u.bindInfo.sbh, _status);
        qDebug() <<QStringLiteral("[sendMsg] 单元%1已绑定此控制台").arg(m->_u.bindInfo.uid);
        displayBoundUnit();//update
        return ilu_TRUE;
        break;
    case Console_OP_Unbind:
        qDebug() <<QStringLiteral("[sendMsg] Unbind.");
        if (Units_Hash_Table != NULL) {
            if (ilu_hash_FindInTable(Units_Hash_Table, m->_u.unbindInfo.uid) != ILU_NIL) {
                ilu_hash_RemoveFromTable(Units_Hash_Table, m->_u.unbindInfo.uid);
                if(m->_u.unbindInfo.uid[0] == 'G')
                    currentGUVNum --;
                if(m->_u.unbindInfo.uid[0] == 'A')
                    currentAUVNum --;
                qDebug() <<QStringLiteral("[sendMsg] %1").arg(m->_u.unbindInfo.uid);
                removeFromBackupFile(m->_u.unbindInfo.uid);
                qDebug() <<QStringLiteral("[sendMsg] 单元%1已解除绑定, details = %2").arg(m->_u.unbindInfo.uid).arg(m->_u.unbindInfo.details);
                displayBoundUnit();//update
                return ilu_TRUE;
            }
            else {
                Console__BindExceptionValue(_status, _Console__Exception_rpc_NotFound);
                return ilu_FALSE;
            }
        }
        else
            return ilu_FALSE;
        break;
    case Console_OP_ReportTrap:
        qDebug() <<QStringLiteral("[sendMsg] report trap start.");
        if (currentTrapPointsNum == MAX_TRAP_POINT_NUM) {
            qDebug() <<QStringLiteral("[sendMsg] traps overflow, opertaion cancelled.");
            return ilu_FALSE;
        }
        ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
        while (ilu_hash_Next(&he, &uid, &sbh)) {
            tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
            Ground_Unit_rpc_setTrapPoint(tmpObj, &m->_u.tp._u.trapPoint2D, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QStringLiteral("%1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
            }
            Ground_Unit_rpc__Free(&tmpObj);
        }
        emit st->infoAppended(QStringLiteral("成功收到汇报的陷阱点(%1,%2)�뾶Ϊ%3��").arg(m->_u.tp._u.trapPoint2D.point.x).arg(m->_u.tp._u.trapPoint2D.point.y).arg(m->_u.tp._u.trapPoint2D.radius));
        qDebug() <<QStringLiteral("[sendMsg] report trap end.");
    case Console_OP_AddTrap:
        /*写入备份文件*/
        qDebug() <<QStringLiteral("[sendMsg] add trap start.");
        if (currentTrapPointsNum == MAX_TRAP_POINT_NUM) {
            qDebug() <<QStringLiteral("[sendMsg] traps overflow, opertaion cancelled.");
            return ilu_FALSE;
        }
        trapPoints[currentTrapPointsNum] = m->_u.tp;
        currentTrapPointsNum ++;
        trapsBackupFile = fopen(backupTrapsFileName, "a+");
        fprintf(trapsBackupFile, "%f,%f,%f\n", m->_u.tp._u.trapPoint2D.point.x, m->_u.tp._u.trapPoint2D.point.y, m->_u.tp._u.trapPoint2D.radius);
        fclose(trapsBackupFile);
        qDebug() <<QStringLiteral("[sendMsg] add trap end.");
        emit st->infoAppended(QStringLiteral("成功添加陷阱点(%1,%2)�뾶Ϊ%3!").arg(m->_u.tp._u.trapPoint2D.point.x).arg(m->_u.tp._u.trapPoint2D.point.y).arg(m->_u.tp._u.trapPoint2D.radius));
        break;
    case Console_OP_SetCosInfo:
        return ilu_FALSE;
        break;
    case Console_OP_Opened:
        qDebug() <<QStringLiteral("[sendMsg] %1").arg(m->_u.details);
        break;
    case Console_OP_Closed:
        qDebug() <<QStringLiteral("[sendMsg] %1").arg(m->_u.details);
        break;
    }
    return ilu_TRUE;
}


// 重新绑定：同一个 uid 换一个新的 SBH
CORBA_boolean server_Console_rpc_rebind(Console_rpc _handle,
                                        Unit_UnitID uid,
                                        Unit_UnitSBH sbh,
                                        ILU_C_ENVIRONMENT *_status)
{
    qDebug() << QStringLiteral("[rebind] 请求: uid=%1 -> %2").arg(uid).arg(sbh);

    // 1) 确保哈希表存在
    if (Units_Hash_Table == NULL) {
        Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM,
                                                 ilu_hash_HashString,
                                                 ilu_hash_StringCompare);
    }

    // 2) 如果已有该 uid，则先移除旧映射（注意不改变统计计数）
    if (ilu_hash_FindInTable(Units_Hash_Table, uid) != ILU_NIL) {
        ilu_hash_RemoveFromTable(Units_Hash_Table, uid);
        // 同步更新备份文件，删掉旧行
        removeFromBackupFile(uid);
    }

    // 3) 复用已有的绑定逻辑：写入哈希 + 追加到备份文件
    if (!handleBindOperation(uid, sbh, _status)) {
        qDebug() << QStringLiteral("[rebind] 更新哈希/备份失败");
        return ilu_FALSE;
    }

    // 4) 如果当前选中对象就是该 uid，重建本地代理对象，避免后续调用用到旧 SBH
    if (currentUID && strcmp(currentUID, uid) == 0) {
        CORBA_Environment ev;
        Unit_rpc newObj = (Unit_rpc)ILU_C_SBHToObject(sbh, Unit_rpc__MSType, &ev);
        if (ILU_C_SUCCESSFUL(&ev)) {
            if (currentUnitObj) Unit_rpc__Free(&currentUnitObj);
            currentUnitObj = newObj;
        } else {
            qDebug() << "[rebind] 重建 Unit 代理失败:" << ev.returnCode;
            ILU_C_EXCEPTION_FREE(&ev);
        }
    }

    displayBoundUnit(); // 刷新 UI
    qDebug() << "[rebind] OK";
    return ilu_TRUE;
}

/** @brief MSVC：以下 ILU Console_rpc 桩函数形参多为占位，关闭 C4100（未引用形参）。 */
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4100)
#endif

CORBA_boolean server_onsole_C2_rebind (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status){
    return NULL;
}

CORBA_boolean server_Console_rpc_setNickname (Console_rpc _handle, Unit_UnitInfo* uinfo, ilu_CString newName, ILU_C_ENVIRONMENT *_status){
    return NULL;
}

 CORBA_boolean server_Console_rpc_setPosition (Console_rpc _handle, ilu_CString name, Console_Point* p, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_addGoalPoint (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_setGoalPoint (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_setRole (Console_rpc _handle, Unit_UnitInfo* uinfo, Unit_UnitRole r, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_cancelRole (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_setTrapPoint (Console_rpc _handle, Console_TrapPoint* p, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_setFollow (Console_rpc _handle, Unit_UnitInfo* uinfo1, Unit_UnitInfo* uinfo2, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_setFormationType (Console_rpc _handle, Console_FormationType f, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_boolean server_Console_rpc_setTrackMode (Console_rpc _handle, Console_TrackMode tm, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 Unit_UnitInfo* server_Console_rpc_getCurrentUnit (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_short server_Console_rpc_getUnitNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_short server_Console_rpc_getFormationNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    return NULL;
 }

 CORBA_short server_Console_rpc_getTrapNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    return 1;
 }

 Console_FormationType server_Console_rpc_getFormationType (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    Console_FormationType tmp{};
     return tmp;
 }

 Console_FormationState server_Console_rpc_getFormationState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    Console_FormationState tmp{};
     return tmp;
 }

Console_MissionState server_Console_rpc_getMissionState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     Console_MissionState tmp{};
     return tmp;
  }

 Console_Point server_Console_rpc_getUnitPoint (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status){
     Console_Point tmp{};
     return tmp;
  }

 Unit_UnitInfo* server_Console_rpc_getByName (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 Console_Point server_Console_rpc_getLeaderPoint (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     Console_Point tmp{};
     return tmp;
  }

 Console_PointSeq* server_Console_rpc_getPointSeq (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_cancelFormation (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_setLeaderSuspend (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_recoveryLeaderAction (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_addUnitFormation (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_deleteUnitFormation (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_setUnitFault (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_setUnitFaultPosition (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_setFormationState (Console_rpc _handle,Console_FormationState fs, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 CORBA_boolean server_Console_rpc_setMissionState (Console_rpc _handle, Console_MissionStateData* msd, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

#if defined(_MSC_VER)
#pragma warning(pop)
#endif

/*
修订记录

2025-07-07 WXC
1 根据新的IDL命名法则,数据说明在Interface之外,进行相应代码修订
2 数据结构序列的命名, 要用Seq而非Sequence
3 当进行新版本与你自己修订的版本合并的时候,一定确认合并后没有冲突再行提交
4 请一定注意Linux和Window系统对温饱工程格式的差异会导致中文的 乱码.需要保障无论是在Linux 环视Window系统下都要正确显示,才能提交.
*/
