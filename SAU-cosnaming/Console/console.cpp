//$Id: console.cpp,v 1.7 2025/07/17 04:50:35 cvswxc Exp $

//#include "iluchdrs.h"

// Include windows.h first to ensure SIZE_T is defined before ILU headers
#include <windows.h>

#include "stubs\Console.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "stubs\CosNaming.h"
#ifdef __cplusplus
}
#endif
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
#include "agents/identity/AgentDirectory.h"
#include "agents/status/AgentStatusService.h"
#include "agents/http/AgentHttpController.h"
#include <stdio.h>
#include <iostream>
#include <QStringList>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QHostAddress>
#include <QDebug>
#include <QElapsedTimer>
#include <QTimer>

#include <vector>


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
bool use_cosnaming = false;
char naming_sbh[2048] = "";
char console_name_path[256] = "china/sau/software_defined_laboratory/system/console_sau";
CosNaming_NamingContext naming_root = NULL;

char* transInfo[3] = { NULL, NULL, NULL };
char* backupFileName = "BackupFile.txt";
char* backupCosNamingServerFileName = "BackupCosNamingInfo.txt";
char* backupTrapsFileName = "BackupTrapPoints.txt";
int mainloopFlag = 1;
FILE* backupFile;
float currentCtrlLinearVelocity = 0.05;
float currentCtrlAngularVelocity = 0.53;

Unit_Formation *formation = NULL;

// 当前拓扑策略 (Requirements 1.2, 1.4)
TopologyStrategy currentTopologyStrategy = TOPOLOGY_CHAIN;

MainWindow* UserInter = 0;
ServerThread *st = 0;

// 智能体目录、状态与别名系统（Phase 2 集成）
static AgentDirectory *g_agentDirectory = nullptr;
static AgentStatusService *g_agentStatusService = nullptr;
static AgentHttpController *g_agentHttpController = nullptr;

/**
 * @brief 根据 UID 和 SBH 构造 AgentLookupResult。
 */
static AgentLookupResult makeLookupResult(const char *uid, const char *sbh, BindingOrigin origin) {
    AgentLookupResult r;
    r.found = true;
    r.unitId = QString::fromUtf8(uid);
    r.unitType = AgentContractUtil::unitTypeFromId(r.unitId);
    r.bindingState = BindingState::Bound;
    r.bindingOrigin = origin;
    r.mock = MockRobotSimulator::isMockSbh(sbh);
    r.displayName = r.unitId; // alias will be layered on by AgentDirectory
    return r;
}

/**
 * @brief 从 Units_Hash_Table 全量同步 AgentDirectory。
 * @param origin 绑定来源标记
 */
static void syncAgentDirectoryFromHashTable(BindingOrigin origin) {
    if (!g_agentDirectory || !Units_Hash_Table)
        return;
    QVector<AgentLookupResult> bindings;
    ilu_HashEnumerator_s he{};
    ilu_refany uid = nullptr;
    ilu_refany sbh = nullptr;
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        bindings.append(makeLookupResult((const char *)uid, (const char *)sbh, origin));
    }
    g_agentDirectory->replaceBindings(bindings);
}

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
    qDebug()<<QString::fromUtf8("已将Cos信息备份到本地文件");
}

bool isSkippedAutoHostAddress(const QHostAddress& ip, const QNetworkInterface& iface) {
    if (ip.protocol() != QAbstractSocket::IPv4Protocol) {
        return true;
    }

    QString ipText = ip.toString();
    if (ipText == "127.0.0.1" || ipText.startsWith("169.254.")) {
        return true;
    }

    QString ifaceName = iface.humanReadableName().toLower();
    if (ifaceName.contains("tailscale")) {
        return true;
    }

    quint32 addr = ip.toIPv4Address();
    quint8 first = (addr >> 24) & 0xff;
    quint8 second = (addr >> 16) & 0xff;
    return first == 100 && second >= 64 && second <= 127;
}

void getLocalIP(){

    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    for (const QNetworkInterface &iface : interfaces) {
        if (!(iface.flags() & QNetworkInterface::IsUp) ||
            !(iface.flags() & QNetworkInterface::IsRunning) ||
            (iface.flags() & QNetworkInterface::IsLoopBack))
            continue;

        for (const QNetworkAddressEntry &entry : iface.addressEntries()) {
            QHostAddress ip = entry.ip();
            if (isSkippedAutoHostAddress(ip, iface)) {
                continue;
            }

            QString ip_str = ip.toString();
            strncpy(host, ip_str.toUtf8().constData(), sizeof(host) - 1);
            host[sizeof(host) - 1] = '\0';
            qDebug() << "[Network] auto selected interface:" << iface.humanReadableName();
            qDebug() << "[Network] auto selected host:" << host;
            return;
        }
    }

    qDebug() << "[Network] warning: no non-loopback IPv4 found, fallback host:" << host;
}

bool parseBoolArg(const char* value) {
    if (value == NULL) {
        return false;
    }
    return strcmp(value, "1") == 0 ||
           strcmp(value, "true") == 0 ||
           strcmp(value, "TRUE") == 0 ||
           strcmp(value, "True") == 0 ||
           strcmp(value, "yes") == 0 ||
           strcmp(value, "YES") == 0 ||
           strcmp(value, "on") == 0 ||
           strcmp(value, "ON") == 0;
}

void freeCosNamingException(CORBA_Environment* ev) {
    if (ev != NULL && !ILU_C_SUCCESSFUL(ev)) {
        ILU_C_EXCEPTION_FREE(ev);
    }
}

void initCosNamingEnv(CORBA_Environment* ev) {
    if (ev == NULL) {
        return;
    }

    memset(ev, 0, sizeof(*ev));
    ILU_C_SET_SUCCESSFUL(ev);
}

const char* cosNamingExceptionId(CORBA_Environment* ev) {
    if (ev == NULL || ILU_C_SUCCESSFUL(ev)) {
        return "<none>";
    }

    char* id = CORBA_exception_id(ev);
    return (id != NULL) ? id : "<unknown>";
}

unsigned long cosNamingMinor(CORBA_Environment* ev) {
    if (ev == NULL || ev->_major != CORBA_SYSTEM_EXCEPTION || ev->ptr == NULL) {
        return 0;
    }

    return ((CORBA_ex_body*)ev->ptr)->minor;
}

bool isCosNamingException(CORBA_Environment* ev, ILU_C_ExceptionCode expected) {
    const char* id = cosNamingExceptionId(ev);
    return id != NULL && expected != NULL && strcmp(id, expected) == 0;
}

bool isNamingContextObject(ilu_CORBA_Object object) {
    return object != NULL &&
           ILU_C_ClassRecordOfInstance(object) == CosNaming_NamingContext__MSType;
}

const char* safeCosNamingObjectSbh(CosNaming_NamingContext root) {
    if (root == NULL) {
        return "<null>";
    }

    const char* sbh = ILU_C_SBHOfObject((ILU_C_OBJECT)root);
    return (sbh != NULL && *sbh != '\0') ? sbh : "<unavailable>";
}

void logCosNamingRootDiagnostic(const char* operation,
                                bool createSucceeded,
                                bool pingSucceeded,
                                CORBA_Environment* ev) {
    qDebug() << "[CosNaming] root diagnostic:";
    qDebug().noquote() << "naming_sbh=" << naming_sbh;
    qDebug() << "CreateFromSBH success=" << (createSucceeded ? "true" : "false");
    qDebug() << "naming_root=" << (void*)naming_root;
    qDebug() << "PingObject success=" << (pingSucceeded ? "true" : "false");
    qDebug() << "operation=" << (operation != NULL ? operation : "<null>");
    qDebug() << "exception=" << cosNamingExceptionId(ev);
    qDebug() << "minor=" << cosNamingMinor(ev);
    qDebug().noquote() << "current_root_sbh=" << safeCosNamingObjectSbh(naming_root);
}

bool connectCosNamingRoot() {
    CORBA_Environment ev;
    initCosNamingEnv(&ev);

    naming_root = CosNaming_NamingContext__CreateFromSBH(naming_sbh, &ev);
    bool createSucceeded = ILU_C_SUCCESSFUL(&ev) && naming_root != NULL;
    if (!createSucceeded) {
        qDebug() << "[CosNaming] warning: CreateFromSBH failed, skip Console registration";
        logCosNamingRootDiagnostic("CreateFromSBH", false, false, &ev);
        freeCosNamingException(&ev);
        naming_root = NULL;
        return false;
    }

    qDebug() << "[CosNaming] CreateFromSBH success.";

    initCosNamingEnv(&ev);
    ILU_C_PingObject((ILU_C_OBJECT)naming_root, &ev);
    bool pingSucceeded = ILU_C_SUCCESSFUL(&ev);
    if (!pingSucceeded) {
        qDebug() << "[CosNaming] warning: PingObject failed, skip Console registration";
        logCosNamingRootDiagnostic("PingObject", true, false, &ev);
        freeCosNamingException(&ev);
        naming_root = NULL;
        return false;
    }

    qDebug() << "[CosNaming] PingObject success.";
    qDebug() << "[CosNaming] connect success.";
    return true;
}

void initSingleCosNamingName(CosNaming_Name* name,
                             CosNaming_NameComponent* component,
                             const char* id,
                             const char* kind) {
    component->id = (char*)id;
    component->kind = (char*)kind;
    name->_maximum = 1;
    name->_length = 1;
    name->_buffer = component;
}

void logCosNamingEnsureFailure(const char* parentLabel,
                               const char* child,
                               const char* kind,
                               const char* operation,
                               CORBA_Environment* ev) {
    qDebug() << "[CosNaming] ensure failed:";
    qDebug() << "parent=" << (parentLabel != NULL ? parentLabel : "<null>");
    qDebug() << "child=" << (child != NULL ? child : "<null>");
    qDebug() << "kind=" << (kind != NULL ? kind : "<null>");
    qDebug() << "operation=" << (operation != NULL ? operation : "<null>");
    qDebug() << "exception=" << cosNamingExceptionId(ev);
    qDebug() << "minor=" << cosNamingMinor(ev);
}

CosNaming_NamingContext resolveChildContext(CosNaming_NamingContext parent,
                                            const char* parentLabel,
                                            const char* child,
                                            const char* kind,
                                            bool logFailure) {
    CosNaming_NameComponent component;
    memset(&component, 0, sizeof(component));

    CosNaming_Name name;
    initSingleCosNamingName(&name, &component, child, kind);

    CORBA_Environment ev;
    initCosNamingEnv(&ev);

    ilu_CORBA_Object resolved = CosNaming_NamingContext_resolve(parent, &name, &ev);
    if (ILU_C_SUCCESSFUL(&ev) && resolved != NULL) {
        if (!isNamingContextObject(resolved)) {
            qDebug() << "[CosNaming] ensure failed:";
            qDebug() << "parent=" << (parentLabel != NULL ? parentLabel : "<null>");
            qDebug() << "child=" << (child != NULL ? child : "<null>");
            qDebug() << "kind=" << (kind != NULL ? kind : "<null>");
            qDebug() << "operation=resolve";
            qDebug() << "exception=not_context";
            qDebug() << "minor=0";
            return NULL;
        }
        qDebug().noquote() << "[CosNaming] context ready:" << QString("%1/%2").arg(child).arg(kind);
        return (CosNaming_NamingContext)resolved;
    }

    if (logFailure) {
        logCosNamingEnsureFailure(parentLabel, child, kind, "resolve", &ev);
    }
    freeCosNamingException(&ev);
    return NULL;
}

CosNaming_NamingContext ensureChildContext(CosNaming_NamingContext parent,
                                           const char* parentLabel,
                                           const char* child,
                                           const char* kind) {
    if (parent == NULL || child == NULL || kind == NULL) {
        return NULL;
    }

    CosNaming_NameComponent component;
    memset(&component, 0, sizeof(component));

    CosNaming_Name name;
    initSingleCosNamingName(&name, &component, child, kind);

    CORBA_Environment ev;
    initCosNamingEnv(&ev);

    ilu_CORBA_Object resolved = CosNaming_NamingContext_resolve(parent, &name, &ev);
    if (ILU_C_SUCCESSFUL(&ev) && resolved != NULL) {
        if (!isNamingContextObject(resolved)) {
            qDebug() << "[CosNaming] ensure failed:";
            qDebug() << "parent=" << (parentLabel != NULL ? parentLabel : "<null>");
            qDebug() << "child=" << (child != NULL ? child : "<null>");
            qDebug() << "kind=" << (kind != NULL ? kind : "<null>");
            qDebug() << "operation=resolve";
            qDebug() << "exception=not_context";
            qDebug() << "minor=0";
            return NULL;
        }
        qDebug().noquote() << "[CosNaming] context ready:" << QString("%1/%2").arg(child).arg(kind);
        return (CosNaming_NamingContext)resolved;
    }

    if (!isCosNamingException(&ev, ex_CosNaming_NamingContext_NotFound)) {
        logCosNamingEnsureFailure(parentLabel, child, kind, "resolve", &ev);
        if (parent == naming_root) {
            logCosNamingRootDiagnostic("resolve", true, true, &ev);
        }
        freeCosNamingException(&ev);
        return NULL;
    }
    freeCosNamingException(&ev);

    initCosNamingEnv(&ev);
    CosNaming_NamingContext created = CosNaming_NamingContext_bind_new_context(parent, &name, &ev);
    if (ILU_C_SUCCESSFUL(&ev) && created != NULL) {
        qDebug().noquote() << "[CosNaming] context ready:" << QString("%1/%2").arg(child).arg(kind);
        return created;
    }

    if (isCosNamingException(&ev, ex_CosNaming_NamingContext_AlreadyBound)) {
        freeCosNamingException(&ev);
        return resolveChildContext(parent, parentLabel, child, kind, true);
    }

    logCosNamingEnsureFailure(parentLabel, child, kind, "bind_new_context", &ev);
    freeCosNamingException(&ev);
    return NULL;
}

bool ensureCosNamingContexts(char** parts, int count, CosNaming_NamingContext* systemContext) {
    if (parts == NULL || count < 5 || systemContext == NULL) {
        return false;
    }

    CosNaming_NamingContext chinaContext =
        ensureChildContext(naming_root, "root", parts[0], "domain");
    if (chinaContext == NULL) {
        return false;
    }

    CosNaming_NamingContext sauContext =
        ensureChildContext(chinaContext, parts[0], parts[1], "domain");
    if (sauContext == NULL) {
        return false;
    }

    CosNaming_NamingContext sdlContext =
        ensureChildContext(sauContext, parts[1], parts[2], "domain");
    if (sdlContext == NULL) {
        return false;
    }

    *systemContext =
        ensureChildContext(sdlContext, parts[2], parts[3], "domain");
    if (*systemContext == NULL) {
        return false;
    }

    if (ensureChildContext(sdlContext, parts[2], "air_vehicle", "domain") == NULL) {
        return false;
    }

    if (ensureChildContext(sdlContext, parts[2], "ground_vehicle", "domain") == NULL) {
        return false;
    }

    return true;
}

void registerConsoleToCosNaming() {
    if (!use_cosnaming) {
        return;
    }

    if (naming_sbh[0] == '\0') {
        qDebug() << "[CosNaming] warning: naming_sbh is empty, skip Console registration";
        return;
    }

    if (!connectCosNamingRoot()) {
        return;
    }

    char pathCopy[sizeof(console_name_path)];
    strncpy(pathCopy, console_name_path, sizeof(pathCopy) - 1);
    pathCopy[sizeof(pathCopy) - 1] = '\0';

    char* parts[16];
    int count = 0;
    char* context = NULL;
    char* token = strtok_s(pathCopy, "/", &context);
    while (token != NULL && count < 16) {
        parts[count++] = token;
        token = strtok_s(NULL, "/", &context);
    }

    if (count == 0 || token != NULL) {
        qDebug() << "[CosNaming] warning: invalid console_name_path, skip Console registration";
        return;
    }

    CosNaming_NamingContext systemContext = NULL;
    if (!ensureCosNamingContexts(parts, count, &systemContext)) {
        qDebug() << "[CosNaming] warning: ensure contexts failed, skip Console registration";
        return;
    }

    CosNaming_NameComponent consoleComponent;
    memset(&consoleComponent, 0, sizeof(consoleComponent));

    CosNaming_Name consoleName;
    initSingleCosNamingName(&consoleName, &consoleComponent, parts[count - 1], "Object");

    const char* consoleSbh = ILU_C_SBHOfObject(serviceObj);
    if (consoleSbh == NULL || *consoleSbh == '\0') {
        qDebug() << "[CosNaming] warning: Console SBH is empty, skip Console registration";
        return;
    }

    CORBA_Environment ev;
    initCosNamingEnv(&ev);
    ilu_CORBA_Object consoleObject = ilu_CORBA_Object__CreateFromSBH((char*)consoleSbh, &ev);
    if (!ILU_C_SUCCESSFUL(&ev) || consoleObject == NULL) {
        qDebug() << "[CosNaming] warning: Create Console object from SBH failed, skip Console registration";
        freeCosNamingException(&ev);
        return;
    }

    initCosNamingEnv(&ev);
    CosNaming_NamingContext_rebind(
        systemContext,
        &consoleName,
        consoleObject,
        &ev
    );
    ilu_CORBA_Object__Free(&consoleObject);

    if (!ILU_C_SUCCESSFUL(&ev)) {
        qDebug() << "[CosNaming] warning: Console rebind failed";
        qDebug() << "exception=" << cosNamingExceptionId(&ev);
        qDebug() << "minor=" << cosNamingMinor(&ev);
        freeCosNamingException(&ev);
        return;
    }

    qDebug().noquote() << "[CosNaming] Console rebind success:" << console_name_path;
}

//从备份Cos服务器生成hash表
ilu_boolean loadCosInfoFromBackupCosServer(){
    Unit_UnitInfoSeq *newSeq;
    Unit_UnitInfo *node;
    CORBA_Environment ev;
    int i;
    char *newsbh, *newuid;
    ilu_boolean flag;

    qDebug() <<QString::fromUtf8("准备从Leader CosNaming中载入信息");
    if (Units_Hash_Table != NULL)
        ilu_hash_FreeHashTable(Units_Hash_Table, ilu_free, ilu_free);
    Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM, ilu_hash_HashString, ilu_hash_StringCompare);

    if (backupCosObj != NULL) {
        newSeq = Console_rpc_getCosNamingInfo(backupCosObj, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QString::fromUtf8("无法联系到Leader");//是否要删除Cos对象和文件？
            return ilu_FALSE;
        }
    } else {
        qDebug() <<QString::fromUtf8("backupCosObj为NULL，无法从Leader恢复");
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
        qDebug() << QString::fromUtf8("未设置任何 Leader，无法获取陷阱点");
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
        qDebug() << QString::fromUtf8("无法联系 Leader 对象或无陷阱点: %1").arg(ev.returnCode);
        return ilu_FALSE;
    }

    qDebug() << QString::fromUtf8("收到的陷阱长度:%1").arg(len);
    if (len > MAX_TRAP_POINT_NUM) {
        qDebug() << QString::fromUtf8("陷阱点数量超限: %1").arg(len);
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
        qDebug() << QString::fromUtf8("无法联系 Leader 对象: %1").arg(ev.returnCode);
        return ilu_FALSE;
    }

    qDebug() << QString::fromUtf8("收到的陷阱长度:%1").arg(traps->_length);
    if (traps->_length > MAX_TRAP_POINT_NUM) {
        qDebug() << QString::fromUtf8("陷阱点数量超限: %1").arg(traps->_length);
        return ilu_FALSE;
    }

    // 备份文件 & 数组重置
    currentTrapPointsNum = 0;
    remove(backupTrapsFileName);
    trapsBackupFile = fopen(backupTrapsFileName, "w+");
    if (!trapsBackupFile) {
        qDebug() << QString::fromUtf8("打开陷阱备份文件失败");
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
            qDebug() << QString::fromUtf8("导入地面陷阱点(%1,%2) 半径%3")
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
            qDebug() << QString::fromUtf8("导入空中陷阱点(%1,%2,%3) 半径%4")
                        .arg(tp->_u.trapPoint3D.point.x)
                        .arg(tp->_u.trapPoint3D.point.y)
                        .arg(tp->_u.trapPoint3D.point.z)
                        .arg(tp->_u.trapPoint3D.radius);
        }

        ++currentTrapPointsNum;
    }
    fclose(trapsBackupFile);

    qDebug() << QString::fromUtf8("当前陷阱数量:%1").arg(currentTrapPointsNum);
    qDebug() << QString::fromUtf8("已将陷阱信息备份到本地文件");
    return ilu_TRUE;
}

// 从本地文件生成 Hash 表
ilu_boolean loadCosInfoFromLocalFile() {
    qDebug() << QString::fromUtf8("准备从备份文件中载入 CosNaming 信息");

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
        qDebug() << QString::fromUtf8("无备份文件");
    }

    qDebug() << QString::fromUtf8("地面单元数: %1, 空中单元数: %2").arg(currentGUVNum).arg(currentAUVNum);
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
    CosNaming__Initialize();

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
    qDebug() << "Console SBH:" << ILU_C_SBHOfObject(serviceObj);

        const char* sbh = ILU_C_SBHOfObject(serviceObj);
        if (sbh && *sbh) {
            qDebug() << "Console SBH:" << sbh;
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
                qDebug() << QString::fromUtf8("已从备份文件读取Leader信息");
            } else {
                qDebug() << QString::fromUtf8("备份文件格式错误，将使用默认值");
                // 设置默认值
                currentMode = Unit_UM_None;
                currentMinorMode = Unit_UMM_None;
            }
        } else {
            qDebug() << QString::fromUtf8("未找到备份文件，将使用默认值");
            // 设置默认值
            currentMode = Unit_UM_None;
            currentMinorMode = Unit_UMM_None;
        }

        // 0.2) 尝试从Leader的CosNaming服务器恢复单元信息
        ilu_boolean cosInitFlag = loadCosInfoFromBackupCosServer();

        // 0.3) 如果无法从Leader恢复,则从本地备份文件恢复
        if (!cosInitFlag) {
            if (!loadCosInfoFromLocalFile()) {
                qDebug() << QString::fromUtf8("Cos哈希表初始化失败，但服务器仍可正常启动");
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
        qDebug() << QString::fromUtf8("未注册的单元ID: %1").arg(uid);
        return ilu_FALSE;
    }
    
    // 检查是否是同一个单元，如果是则直接返回
    if (currentUID != NULL && strcmp(currentUID, uid) == 0) {
        qDebug() << QString::fromUtf8("单元%1已经是当前控制单元").arg(uid);
        return ilu_TRUE;
    }
    
    qDebug() << QString::fromUtf8("正在切换到单元: %1, SBH: %2").arg(uid).arg(sbh);
    
    // 先释放旧对象再创建新对象，避免对象缓存问题
    if (currentUnitObj != NULL) {
        qDebug() << QString::fromUtf8("释放旧单元对象: %1, 地址: %2").arg(currentUID != NULL ? currentUID : "NULL").arg((quintptr)currentUnitObj, 0, 16);
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
            qDebug() << QString::fromUtf8("无法创建地面单元对象: %1, 错误: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
            return ilu_FALSE;
        }
        qDebug() << QString::fromUtf8("创建地面单元对象成功，新地址: %1").arg((quintptr)tmp, 0, 16);
    }
    //空中单元
    else if (uid[0] == 'A') {
        tmp = (Unit_rpc)ILU_C_SBHToObject(sbh, Air_Unit_rpc__MSType, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() << QString::fromUtf8("无法创建空中单元对象: %1, 错误: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
            return ilu_FALSE;
        }
        qDebug() << QString::fromUtf8("创建空中单元对象成功，新地址: %1").arg((quintptr)tmp, 0, 16);
    }
    else {
        qDebug() << QString::fromUtf8("未知的单元类型: %1").arg(uid);
        return ilu_FALSE;
    }
    
    // 设置新的UID和对象
    currentUID = (char*)ilu_malloc(strlen(uid) + 1);
    strcpy(currentUID, uid);
    currentUnitObj = tmp;
    
    qDebug() << QString::fromUtf8("成功切换到单元: %1, 对象地址: %2").arg(uid).arg((quintptr)currentUnitObj, 0, 16);
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
    //Unit_rpc_setRole(currentUnitObj, Unit_UR_Leader,"ilusbh:sau/console_sau;IDL%3AConsole%2Frpc%3A1.0;iiop@tcp_192.168.3.10_5000",&ev);
    // 动态获取当前控制台的SBH，而不是硬编码IP地址
    Unit_UnitSBH currentConsoleSBH = (Unit_UnitSBH)ILU_C_SBHOfObject(serviceObj);
    qDebug() << "使用控制台SBH:" << currentConsoleSBH;
    Unit_rpc_setRole(currentUnitObj, Unit_UR_Leader, currentConsoleSBH, &ev);
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
    
    // 检查返回的SBH是否是控制台自己的SBH（避免循环引用）
    const char* consoleSBH = ILU_C_SBHOfObject(serviceObj);
    if (strcmp(tmpSBH, consoleSBH) == 0) {
        qDebug() << "警告：单元返回的CosNaming SBH是控制台自己，跳过备份Console对象创建";
        qDebug() << "这可能表示该单元没有自己的CosNaming服务";
        backupCosObj = NULL;
        backupCosSBH = NULL;
    } else {
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
    }

    currentLeaderUID = (char*)ilu_malloc(MAX_UNITID_LENGTH);
    strcpy(currentLeaderUID, currentUID);
    //写入文件
    backupCosFile = fopen(backupCosNamingServerFileName, "w+");
    fprintf(backupCosFile, "%s\n%s\n%s\n%d\n%d", 
            backupCosSBH ? backupCosSBH : "NULL", 
            leaderSBH, 
            currentLeaderUID, 
            Unit_UM_None, 
            Unit_UMM_None);
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
    // 只有当备份Console对象存在时才发送消息（地面单元有CosNaming服务）
    if (backupCosObj != NULL) {
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
    } else {
        qDebug() << "跳过CosNaming信息同步（单元无CosNaming服务）";
    }


//遍历setFollowMode - 只设置角色和Leader，不设置模式（模式由setGroupMode设置）
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        // 处理地面单元
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
        // 处理空中单元
        else if (((char*)uid)[0] == 'A' && strcmp(currentUID, (char*)uid) != 0) {
            qDebug() << "set air follower:" << (char*)uid;
            Air_Unit_rpc tmpAirObj = (Air_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Air_Unit_rpc__MSType, &ev);
            
            // 设置角色为Follower
            Unit_rpc_setRole(tmpAirObj, Unit_UR_Follower, "null", &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() << "failed to set role for" << (char*)uid << ":" << ev.returnCode;
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << "air follower" << (char*)uid << "role set successfully";
            }
            
            // 设置Leader
            Unit_rpc_setALeader(tmpAirObj, leaderSBH, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() << "failed to set leader for" << (char*)uid << ":" << ev.returnCode;
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                qDebug() << "air follower" << (char*)uid << "leader set successfully";
            }
            
            qDebug() << "air follower" << (char*)uid << "configured (role and leader only, mode should be set via setGroupMode)";
            Air_Unit_rpc__Free(&tmpAirObj);
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

//        qDebug() <<QString::fromUtf8("未选定控制单元！");
//        return false;
//    }
//    qDebug() <<QString::fromUtf8("请输入遥控的线速度：");
//    scanf("%f", &currentCtrlLinearVelocity);
//    qDebug() <<QString::fromUtf8("请输入遥控的角速度：");
//    scanf("%f", &currentCtrlAngularVelocity);
//    qDebug() <<QString::fromUtf8("当前线速度：%1, 当前角速度：%2").arg(currentCtrlLinearVelocity).arg(currentCtrlAngularVelocity);
//    qDebug() <<QString::fromUtf8("ʹ使用WASD控制，按下q退出");
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

//                qDebug() <<QString::fromUtf8("Exception: %1").arg(ev.returnCode);

//			break;
//		case 83:
//		case 115:
//            action._d = Ground_Unit_MA_GoBackward;
//			action._u.goBackwardData.duration.keep = ilu_TRUE;
//			action._u.goBackwardData.speed = currentCtrlLinearVelocity;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QString::fromUtf8("Exception: %1").arg(ev.returnCode);

//			break;
//		case 65:
//		case 97:
//            action._d = Ground_Unit_MA_TurnLeft;
//			action._u.turnLeftData.duration.keep = ilu_TRUE;
//			action._u.turnLeftData.speed = currentCtrlAngularVelocity;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QString::fromUtf8("Exception: %1").arg(ev.returnCode);

//			break;
//		case 68:
//		case 100:
//            action._d = Ground_Unit_MA_TurnRight;
//			action._u.turnRightData.duration.keep = ilu_TRUE;
//			action._u.turnRightData.speed = currentCtrlAngularVelocity;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QString::fromUtf8("Exception: %1").arg(ev.returnCode);
//			break;
//		case 88:
//		case 120:
//            action._d = Ground_Unit_MA_Stop;
//			action._u.stopData.keep = ilu_TRUE;
//            Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
//			if (!ILU_C_SUCCESSFUL(&ev))

//                qDebug() <<QString::fromUtf8("Exception: %1").arg(ev.returnCode);
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
        qDebug() <<QString::fromUtf8("请输入当前单元跟随的单元ID：");
        scanf("%s", uid);
        if (strcmp(uid, currentUID) == 0) {
            qDebug() <<QString::fromUtf8("与当前控制单元相同！");
            return;
         }
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)uid);
        if (sbh == NULL) {
            qDebug() <<QString::fromUtf8("未绑定的单元ID！");
        return;
        }

        tmp = ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QString::fromUtf8("%1: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
//         return;
        }
        Unit_rpc_setMode(tmp, Unit_UM_Imitate, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QString::fromUtf8("%1: %2").arg(uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
//          return;
      }
       succ = Unit_rpc_setALeader(currentUnitObj, sbh, &ev);
       if (ILU_C_SUCCESSFUL(&ev) && succ){
            qDebug() <<QString::fromUtf8("设置成功！");
       }else{
            qDebug() <<QString::fromUtf8("设置失败！");
       }
//    return;
    }else {
        qDebug() << QString::fromUtf8("未选定控制单元!");
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
        qDebug() <<QString::fromUtf8("%1").arg(ev.returnCode);
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

// -----------------------------------------------------------------------
// 通用单元配置辅助函数：角色 + 主模式 + 次级模式
// 利用 Unit_rpc 是 Ground_Unit_rpc / Air_Unit_rpc 的父类这一事实，
// 将两段完全相同的逻辑合并为一个函数。
// 参数：
//   unitObj   - 父类指针（地面/空中单元均可传入）
//   uid       - 单元ID字符串，仅用于日志
//   isLeader  - 该单元是否为Leader
//   leaderSBH - Leader的SBH（Follower需要用到）
//   mode      - 要设置的主模式
// 返回值：次级模式设置成功返回 true
// -----------------------------------------------------------------------
static bool configureUnitMode(Unit_rpc unitObj, const char* uid,
                               bool isLeader, const char* leaderSBH,
                               Unit_UnitMode mode)
{
    CORBA_Environment ev;

    // 1. 设置角色
    if (isLeader) {
        LOG_INFO("setGroupMode", QString::fromUtf8("[%1] 是Leader，设置Leader角色").arg(uid));
        // 动态获取控制台SBH，避免硬编码IP
        Unit_rpc_setRole(unitObj, Unit_UR_Leader,
                         (char*)ILU_C_SBHOfObject(serviceObj), &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            LOG_ERROR("setGroupMode", QString::fromUtf8("[%1] 设置Leader角色失败: %2").arg(uid).arg(ev.returnCode));
            ILU_C_EXCEPTION_FREE(&ev);
        } else {
            LOG_INFO("setGroupMode", QString::fromUtf8("[%1] Leader角色设置成功").arg(uid));
        }
    } else {
        LOG_INFO("setGroupMode", QString::fromUtf8("[%1] 设置为Follower角色").arg(uid));
        Unit_rpc_setRole(unitObj, Unit_UR_Follower, "null", &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            LOG_ERROR("setGroupMode", QString::fromUtf8("[%1] 设置Follower角色失败: %2").arg(uid).arg(ev.returnCode));
            ILU_C_EXCEPTION_FREE(&ev);
        } else {
            LOG_INFO("setGroupMode", QString::fromUtf8("[%1] Follower角色设置成功").arg(uid));
        }

        // 设置Leader SBH
        if (leaderSBH != NULL) {
            Unit_rpc_setALeader(unitObj, (Unit_UnitSBH)leaderSBH, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                LOG_ERROR("setGroupMode", QString::fromUtf8("[%1] 设置Leader失败: %2").arg(uid).arg(ev.returnCode));
                ILU_C_EXCEPTION_FREE(&ev);
            } else {
                LOG_INFO("setGroupMode", QString::fromUtf8("[%1] Leader已设置为 %2").arg(uid).arg(currentLeaderUID));
            }
        }
    }

    // 2. 设置主模式
    CORBA_boolean flag = Unit_rpc_setMode(unitObj, mode, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        LOG_ERROR("setGroupMode", QString::fromUtf8("[%1] 主模式设置失败: %2").arg(uid).arg(ev.returnCode));
        ILU_C_EXCEPTION_FREE(&ev);
    } else {
        LOG_INFO("setGroupMode", QString::fromUtf8("[%1] 主模式设置为 %2").arg(uid).arg(mode));
    }

    // 3. 计算并设置次级模式
    // 规则来自 checkValidity：Follow → FW_Object，其余 → None
    Unit_UnitMinorMode minorMode = (mode == Unit_UM_Follow) ? Unit_UMM_FW_Object : Unit_UMM_None;
    LOG_INFO("setGroupMode", QString::fromUtf8("[%1] mode=%2，MinorMode=%3").arg(uid).arg(mode).arg((int)minorMode));

    flag = Unit_rpc_setMinorMode(unitObj, minorMode, &ev);
    if (!ILU_C_SUCCESSFUL(&ev)) {
        LOG_ERROR("setGroupMode", QString::fromUtf8("[%1] 次级模式设置失败: %2").arg(uid).arg(ev.returnCode));
        ILU_C_EXCEPTION_FREE(&ev);
        return false;
    }
    LOG_INFO("setGroupMode", QString::fromUtf8("[%1] 次级模式设置成功，值为 %2").arg(uid).arg(minorMode));
    return (flag == ilu_TRUE);
}

//设置团队模式
bool setGroupMode(Unit_UnitMode mode) {
    ilu_refany uid, sbh;
    ilu_HashEnumerator_s he;
    CORBA_Environment ev;
    CORBA_boolean flag = ilu_FALSE;
    char* leaderSBH = NULL;

    qDebug() << QString::fromUtf8("========== setGroupMode 开始 ==========");
    qDebug() << QString::fromUtf8("mode=%1 (0=None,1=Follow,2=Imitate,3=Mate)").arg(mode);
    qDebug() << QString::fromUtf8("currentLeaderUID: %1").arg(currentLeaderUID != NULL ? currentLeaderUID : "NULL");
    qDebug() << QString::fromUtf8("currentGUVLeaderObj: %1").arg((quintptr)currentGUVLeaderObj, 0, 16);
    qDebug() << QString::fromUtf8("currentAUVLeaderObj: %1").arg((quintptr)currentAUVLeaderObj, 0, 16);

    if (currentGUVLeaderObj == NULL && currentAUVLeaderObj == NULL) {
        qDebug() << QString::fromUtf8("错误：未设置队伍！必须先调用 setToLeader() 设置Leader");
        qDebug() << QString::fromUtf8("提示：正确流程是 getUnitObject(leaderUID) → setToLeader() → setGroupMode(mode)");
        return false;
    }

    // 获取Leader的SBH
    if (currentGUVLeaderObj != NULL) {
        leaderSBH = (char*)ilu_malloc(strlen(ILU_C_SBHOfObject(currentGUVLeaderObj)) + 1);
        strcpy(leaderSBH, ILU_C_SBHOfObject(currentGUVLeaderObj));
        qDebug() << QString::fromUtf8("地面Leader SBH: %1").arg(leaderSBH);
    } else if (currentAUVLeaderObj != NULL) {
        leaderSBH = (char*)ilu_malloc(strlen(ILU_C_SBHOfObject(currentAUVLeaderObj)) + 1);
        strcpy(leaderSBH, ILU_C_SBHOfObject(currentAUVLeaderObj));
        qDebug() << QString::fromUtf8("空中Leader SBH: %1").arg(leaderSBH);
    }

    // 统计处理结果
    int totalCount = 0, totalSuccess = 0;

    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        char unitType = ((char*)uid)[0];
        Unit_rpc unitObj = NULL;  // 统一用父类指针接收

        // 按类型创建对象（唯一的类型差异点）
        if (unitType == 'G') {
            unitObj = (Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
        } else if (unitType == 'A') {
            unitObj = (Unit_rpc)ILU_C_SBHToObject((char*)sbh, Air_Unit_rpc__MSType, &ev);
        } else {
            LOG_WARN("setGroupMode", QString::fromUtf8("未知单元类型: %1, 跳过").arg((char*)uid));
            continue;
        }

        if (!ILU_C_SUCCESSFUL(&ev) || unitObj == NULL) {
            LOG_ERROR("setGroupMode", QString::fromUtf8("无法创建单元对象 %1: %2").arg((char*)uid).arg(ev.returnCode));
            ILU_C_EXCEPTION_FREE(&ev);
            continue;
        }

        totalCount++;
        bool isLeader = (currentLeaderUID != NULL && strcmp((char*)uid, currentLeaderUID) == 0);
        LOG_INFO("setGroupMode", QString::fromUtf8("开始处理单元 %1 (isLeader=%2)").arg((char*)uid).arg(isLeader));

        // 调用通用配置函数，地面/空中单元走同一套逻辑
        bool ok = configureUnitMode(unitObj, (char*)uid, isLeader, leaderSBH, mode);
        if (ok) {
            totalSuccess++;
            flag = ilu_TRUE;
        } else {
            LOG_WARN("setGroupMode", QString::fromUtf8("单元 %1 配置失败，已取消！").arg((char*)uid));
            Unit_rpc__Free(&unitObj);
            break;
        }

        Unit_rpc__Free(&unitObj);
    }
    
    if (leaderSBH != NULL) {
        ilu_free(leaderSBH);
    }

    LOG_INFO("setGroupMode", QString::fromUtf8("========== setGroupMode 完成 =========="));
    LOG_INFO("setGroupMode", QString::fromUtf8("处理统计: 总计 %1 个单元，成功 %2 个")
             .arg(totalCount).arg(totalSuccess));
    
    if (flag){
        FILE* backupCosFile;
        char* backupCosSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        char *leaderSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        Unit_UnitMinorMode defaultMinorMode = Unit_UMM_None;
        if (mode == Unit_UM_Follow || mode == Unit_UM_Imitate)
            defaultMinorMode = Unit_UMM_FW_Object;

        LOG_INFO("setGroupMode", QString::fromUtf8("模式设置成功！"));
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
    LOG_WARN("setGroupMode", QString::fromUtf8("模式设置失败"));
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

        qDebug() <<QString::fromUtf8("未设置队伍！");
        return false;
    }
    if (!checkValidity(currentMode, minorMode)){
        qDebug() <<QString::fromUtf8("次级模式错误！");
        return false;
    }
    ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
    while (ilu_hash_Next(&he, &uid, &sbh)) {
        if(((char*)uid)[0] != 'G')//仅设置无人车
            continue;
        tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
        qDebug() <<QString::fromUtf8("set %1 mode start").arg((char*)uid);
        flag = Unit_rpc_setMinorMode(tmpObj, minorMode, &ev);//设置模式
        if (!ILU_C_SUCCESSFUL(&ev)) {

            qDebug() <<QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);
        }
        Ground_Unit_rpc__Free(&tmpObj);
        if (!flag) {
            qDebug() <<QString::fromUtf8("当前无法切换模式，已取消！");
            break;
        }
    }
    if (flag)
    {
        FILE* backupCosFile;
        char* backupCosSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        char *leaderSBH = (char*)ilu_malloc(MAX_UNITSBH_LENGTH);
        qDebug() <<QString::fromUtf8("模式设置成功！");
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


/*======================================================================*/
/*=============== 日志辅助函数 (Requirements 9.1, 9.2, 9.3) ============*/
/*======================================================================*/

// 将 Unit_UnitIDSeq 格式化为可读字符串，用于日志输出
// 例如: "[GV01, AV02, GV03]"
QString formatUnitIDSeq(const Unit_UnitIDSeq* seq) {
    if (seq == NULL || seq->_length == 0) {
        return QString::fromUtf8("[]");
    }
    QString result = QString::fromUtf8("[");
    for (unsigned long i = 0; i < seq->_length; i++) {
        if (i > 0) result += QString::fromUtf8(", ");
        const char* uid = seq->_buffer[i];
        result += (uid != NULL) ? QString::fromUtf8(uid) : QString::fromUtf8("NULL");
    }
    result += QString::fromUtf8("]");
    return result;
}

// 将 Unit_ShortSeq 格式化为可读字符串，用于日志输出
// 例如: "[0, 0, 1, 2]"
QString formatShortSeq(const Unit_ShortSeq* seq) {
    if (seq == NULL || seq->_length == 0) {
        return QString::fromUtf8("[]");
    }
    QString result = QString::fromUtf8("[");
    for (unsigned long i = 0; i < seq->_length; i++) {
        if (i > 0) result += QString::fromUtf8(", ");
        result += QString::number(seq->_buffer[i]);
    }
    result += QString::fromUtf8("]");
    return result;
}

// 将 Unit_FloatSeq 格式化为可读字符串，用于日志输出
// 例如: "[0.00, 1.50, 2.30]"
QString formatFloatSeq(const Unit_FloatSeq* seq) {
    if (seq == NULL || seq->_length == 0) {
        return QString::fromUtf8("[]");
    }
    QString result = QString::fromUtf8("[");
    for (unsigned long i = 0; i < seq->_length; i++) {
        if (i > 0) result += QString::fromUtf8(", ");
        result += QString::number((double)seq->_buffer[i], 'f', 2);
    }
    result += QString::fromUtf8("]");
    return result;
}

//设置队形

/*======================================================================*/
/*=============== 地面编队下发 (Requirements 7.1, 7.2, 7.3, 10.1) ======*/
/*======================================================================*/

// 最小安全间隔（米）- 防止用户输入过小导致碰撞
static const float MIN_SAFE_DISTANCE = 0.5f;

// 地面编队下发：遍历地面组，为每个单元调用 setRearVehicles
// 核心原则1：对每一个地面节点都必须下发一次 setRearVehicles（包括叶子节点）
// 核心原则2：setRearVehicles 下发必须在该车处于 Follow 模式时"最终成功"
// 使用每个单元独立的 distance/angle 参数
// 返回: GroupResult 包含每个单元的成功/失败结果
static GroupResult _setGroundFormation(Unit_Formation* formation)
{
    GroupResult result;
    
    if (formation == NULL || formation->robot_ids._length == 0) {
        LOG_WARN_S("_setGroundFormation", "formation is NULL or empty");
        return result;
    }
    
    if (currentGUVLeaderObj == NULL) {
        LOG_ERROR_S("_setGroundFormation", "currentGUVLeaderObj is NULL, cannot dispatch ground formation");
        return result;
    }
    
    const int n_total = (int)formation->robot_ids._length;
    LOG_INFO_S("_setGroundFormation", 
        QString::fromUtf8("开始下发地面编队: %1 个单元").arg(n_total));
    
    CORBA_Environment en;
    ilu_Error error;
    
    // 先将 formation 下发给 Leader
    Unit_rpc_setFormation(currentGUVLeaderObj, formation, &en);
    if (!ILU_C_SUCCESSFUL(&en)) {
        LOG_ERROR_S("_setGroundFormation", 
            QString::fromUtf8("Leader setFormation 失败: %1").arg(en.returnCode));
        ILU_C_EXCEPTION_FREE(&en);
        
        // 记录 Leader 失败
        UnitResult leaderResult;
        const char* leaderUid = formation->robot_ids._buffer[0];
        if (leaderUid) {
            strncpy(leaderResult.uid, leaderUid, MAX_UNITID_LENGTH - 1);
            leaderResult.uid[MAX_UNITID_LENGTH - 1] = '\0';
        }
        leaderResult.success = false;
        leaderResult.errorCode = (int)en.returnCode;
        strncpy(leaderResult.errorMsg, "Leader setFormation failed", 255);
        result.unitResults.push_back(leaderResult);
        result.calculateCounts();
        return result;
    }
    
    // Step 1: 根据 leader_ids 构建每个节点的 rears 列表（谁的直接后车有哪些）
    std::vector<std::vector<int>> rearsMap(n_total);
    for (int j = 1; j < n_total; j++) {
        int leaderIdx = formation->leader_ids._buffer[j];
        if (leaderIdx >= 0 && leaderIdx < n_total) {
            rearsMap[leaderIdx].push_back(j);
        }
    }
    
    // Step 2: 逐节点下发（对所有 i，从 0 到 N-1，包括叶子节点）
    for (int i = 0; i < n_total; i++) {
        UnitResult unitResult;
        const char* uid = formation->robot_ids._buffer[i];
        if (uid) {
            strncpy(unitResult.uid, uid, MAX_UNITID_LENGTH - 1);
            unitResult.uid[MAX_UNITID_LENGTH - 1] = '\0';
        }
        
        // 查找单元的 SBH
        char* sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (ilu_refany)uid);
        if (sbh == NULL) {
            LOG_ERROR_S("_setGroundFormation", 
                QString::fromUtf8("%1: 找不到 SBH").arg(uid));
            unitResult.success = false;
            unitResult.errorCode = FE_RPC_FAILED;
            strncpy(unitResult.errorMsg, "SBH not found", 255);
            result.unitResults.push_back(unitResult);
            continue;
        }
        
        // 创建单元对象
        Ground_Unit_rpc grd_tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject(sbh, Ground_Unit_rpc__MSType, &en);
        if (!ILU_C_SUCCESSFUL(&en) || grd_tmpObj == NULL) {
            LOG_ERROR_S("_setGroundFormation", 
                QString::fromUtf8("%1: 创建对象失败: %2").arg(uid).arg(en.returnCode));
            ILU_C_EXCEPTION_FREE(&en);
            unitResult.success = false;
            unitResult.errorCode = (int)en.returnCode;
            strncpy(unitResult.errorMsg, "Failed to create unit object", 255);
            result.unitResults.push_back(unitResult);
            continue;
        }
        
        // 构建后车列表（可能为空，叶子节点的 rears 为空列表）
        Unit_UnitInfoSeq* unitInfoSeq = Unit_UnitInfoSeq_Create(0, NULL);
        
        for (int rearIdx : rearsMap[i]) {
            const char* followerUid = formation->robot_ids._buffer[rearIdx];
            char* followerSbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (ilu_refany)followerUid);
            
            if (followerSbh != NULL) {
                Unit_UnitInfo tmp;
                tmp.uid = (char*)ilu_malloc(strlen(followerUid) + 1);
                strcpy(tmp.uid, followerUid);
                tmp.sbh = (char*)ilu_malloc(strlen(followerSbh) + 1);
                strcpy(tmp.sbh, followerSbh);
                Unit_UnitInfoSeq_Append(unitInfoSeq, &tmp, &error);
            }
        }
        
        int rearCount = (int)unitInfoSeq->_length;
        
        // 使用每个单元独立的 distance/angle 参数 (Requirements 7.1, 7.2, 7.3)
        float dist_i = (i < (int)formation->distances._length) ? formation->distances._buffer[i] : 0.5f;
        const float ang_i = (i < (int)formation->angles._length) ? formation->angles._buffer[i] : 0.0f;
        
        // 最小安全间隔钳制：防止用户输入过小导致碰撞
        if (dist_i < MIN_SAFE_DISTANCE && i > 0) {  // Leader(i=0) 的 distance 可以是 0
            LOG_WARN_S("_setGroundFormation", 
                QString::fromUtf8("%1: distance=%2 小于最小安全间隔，已自动调整为 %3")
                    .arg(uid).arg(dist_i, 0, 'f', 2).arg(MIN_SAFE_DISTANCE, 0, 'f', 2));
            dist_i = MIN_SAFE_DISTANCE;
        }
        
        LOG_INFO_S("_setGroundFormation", 
            QString::fromUtf8("%1: setRearVehicles(dist=%2, angle=%3, rearCount=%4)")
                .arg(uid).arg(dist_i, 0, 'f', 2).arg(ang_i, 0, 'f', 2).arg(rearCount));
        
        // 调用 setRearVehicles（核心原则1：每个节点都必须调用，包括叶子节点）
        CORBA_boolean flag = Unit_rpc_setRearVehicles(grd_tmpObj, unitInfoSeq, dist_i, ang_i, &en);
        
        // 核心原则2：如果失败，尝试"补模式+重试"
        if (flag == ilu_FALSE || !ILU_C_SUCCESSFUL(&en)) {
            LOG_WARN_S("_setGroundFormation", 
                QString::fromUtf8("%1: setRearVehicles 首次失败(%2)，尝试补模式+重试...")
                    .arg(uid).arg(en.returnCode));
            ILU_C_EXCEPTION_FREE(&en);
            
            // 补模式：先设置 Follow 模式
            Unit_rpc_setMode(grd_tmpObj, Unit_UM_Follow, &en);
            if (!ILU_C_SUCCESSFUL(&en)) {
                LOG_WARN_S("_setGroundFormation", 
                    QString::fromUtf8("%1: setMode(Follow) 失败: %2").arg(uid).arg(en.returnCode));
                ILU_C_EXCEPTION_FREE(&en);
            } else {
                LOG_INFO_S("_setGroundFormation", 
                    QString::fromUtf8("%1: setMode(Follow) 成功").arg(uid));
            }
            
            // 补 MinorMode（如果需要）
            Unit_rpc_setMinorMode(grd_tmpObj, Unit_UMM_FW_Object, &en);
            if (!ILU_C_SUCCESSFUL(&en)) {
                LOG_WARN_S("_setGroundFormation", 
                    QString::fromUtf8("%1: setMinorMode 失败: %2").arg(uid).arg(en.returnCode));
                ILU_C_EXCEPTION_FREE(&en);
            }
            
            // 重试 setRearVehicles
            flag = Unit_rpc_setRearVehicles(grd_tmpObj, unitInfoSeq, dist_i, ang_i, &en);
            
            if (flag == ilu_FALSE || !ILU_C_SUCCESSFUL(&en)) {
                LOG_ERROR_S("_setGroundFormation", 
                    QString::fromUtf8("%1: setRearVehicles 重试仍失败: %2").arg(uid).arg(en.returnCode));
                ILU_C_EXCEPTION_FREE(&en);
                unitResult.success = false;
                unitResult.errorCode = (int)en.returnCode;
                strncpy(unitResult.errorMsg, "setRearVehicles failed after retry", 255);
            } else {
                LOG_INFO_S("_setGroundFormation", 
                    QString::fromUtf8("%1: setRearVehicles 重试成功").arg(uid));
                unitResult.success = true;
                unitResult.errorCode = 0;
            }
        } else {
            LOG_INFO_S("_setGroundFormation", 
                QString::fromUtf8("%1: setRearVehicles 成功").arg(uid));
            unitResult.success = true;
            unitResult.errorCode = 0;
        }
        
        Unit_UnitInfoSeq__Free(unitInfoSeq);
        result.unitResults.push_back(unitResult);
        Ground_Unit_rpc__Free(&grd_tmpObj);
    }
    
    result.calculateCounts();
    LOG_INFO_S("_setGroundFormation", 
        QString::fromUtf8("地面编队下发完成: 成功=%1, 失败=%2")
            .arg(result.successCount).arg(result.failCount));
    
    return result;
}

/*======================================================================*/
/*=============== 空中编队下发 (Requirements 4.1, 4.2, 4.3) ============*/
/*======================================================================*/

static std::vector<float> _defaultAirAngles(int n_followers)
{
    std::vector<float> ang;
    if (n_followers <= 0) return ang;

    // 默认让队形“落在Leader后方”，更符合直觉
    if (n_followers == 1) {
        ang.push_back(180.0f);
        return ang;
    }
    if (n_followers == 2) {
        // 经典 V 形
        ang.push_back(135.0f);
        ang.push_back(225.0f);
        return ang;
    }
    // n>=3：均匀环绕，但整体偏到后方
    const float step = 360.0f / (float)n_followers;
    for (int k = 0; k < n_followers; ++k) {
        float a = 180.0f + step * k;
        // wrap to [0,360)
        while (a >= 360.0f) a -= 360.0f;
        while (a <   0.0f)  a += 360.0f;
        ang.push_back(a);
    }
    return ang;
}

// 适配“无人机编队”：Console 侧只需要做两件事
// 1) 把 follower 的 SBH 列表发给 leader (sendControlledVehicle)
// 2) 给 leader 下发 formation 的 dist/angle(只包含 follower，不包含 leader)
static GroupResult _setAirSwarmFormation(Unit_Formation* formation)
{
    GroupResult result;
    
    if (formation == NULL) {
        LOG_WARN_S("_setAirSwarmFormation", "formation is NULL");
        return result;
    }

    const int n_total = (int)formation->robot_ids._length;
    if (n_total < 1) {
        LOG_WARN_S("_setAirSwarmFormation", "formation is empty");
        return result;
    }
    if (n_total == 1) {
        LOG_INFO_S("_setAirSwarmFormation", "only 1 air unit, no formation needed");
        UnitResult ur;
        const char* uid = formation->robot_ids._buffer[0];
        if (uid) {
            strncpy(ur.uid, uid, MAX_UNITID_LENGTH - 1);
            ur.uid[MAX_UNITID_LENGTH - 1] = '\0';
        }
        ur.success = true;
        ur.errorCode = 0;
        result.unitResults.push_back(ur);
        result.calculateCounts();
        return result;
    }

    LOG_INFO_S("_setAirSwarmFormation", 
        QString::fromUtf8("Starting air formation dispatch: %1 units").arg(n_total));

    CORBA_Environment en;
    ilu_Error err;

    // Leader is the first in robot_ids
    const char* leader_uid = *(Unit_UnitIDSeq_Nth(&formation->robot_ids, 0));
    char* leader_sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (ilu_refany)leader_uid);
    if (leader_sbh == NULL) {
        LOG_ERROR_S("_setAirSwarmFormation", 
            QString::fromUtf8("Leader SBH not found: %1").arg(leader_uid));
        UnitResult ur;
        strncpy(ur.uid, leader_uid, MAX_UNITID_LENGTH - 1);
        ur.success = false;
        ur.errorCode = FE_RPC_FAILED;
        strncpy(ur.errorMsg, "Leader SBH not found", 255);
        result.unitResults.push_back(ur);
        result.calculateCounts();
        return result;
    }

    Air_Unit_rpc leaderObj = (Air_Unit_rpc)ILU_C_SBHToObject(leader_sbh, Air_Unit_rpc__MSType, &en);
    if (!ILU_C_SUCCESSFUL(&en) || leaderObj == NULL) {
        LOG_ERROR_S("_setAirSwarmFormation", 
            QString::fromUtf8("Failed to create leader object: %1").arg(en.returnCode));
        ILU_C_EXCEPTION_FREE(&en);
        UnitResult ur;
        strncpy(ur.uid, leader_uid, MAX_UNITID_LENGTH - 1);
        ur.success = false;
        ur.errorCode = (int)en.returnCode;
        strncpy(ur.errorMsg, "Failed to create leader object", 255);
        result.unitResults.push_back(ur);
        result.calculateCounts();
        return result;
    }

    // 1) Build follower SBH list and send to leader (sendControlledVehicle)
    const int n_followers = n_total - 1;
    Unit_UnitSBHSeq* followerSBHSeq = Unit_UnitSBHSeq_Create(n_followers, NULL);
    
    // Record leader result
    UnitResult leaderResult;
    strncpy(leaderResult.uid, leader_uid, MAX_UNITID_LENGTH - 1);
    leaderResult.uid[MAX_UNITID_LENGTH - 1] = '\0';
    leaderResult.success = true;
    leaderResult.errorCode = 0;
    
    for (int j = 1; j < n_total; ++j) {
        const char* follower_uid = *(Unit_UnitIDSeq_Nth(&formation->robot_ids, j));
        char* follower_sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (ilu_refany)follower_uid);
        
        UnitResult followerResult;
        strncpy(followerResult.uid, follower_uid, MAX_UNITID_LENGTH - 1);
        followerResult.uid[MAX_UNITID_LENGTH - 1] = '\0';
        
        if (follower_sbh == NULL) {
            LOG_ERROR_S("_setAirSwarmFormation", 
                QString::fromUtf8("Follower SBH not found: %1").arg(follower_uid));
            followerResult.success = false;
            followerResult.errorCode = FE_RPC_FAILED;
            strncpy(followerResult.errorMsg, "Follower SBH not found", 255);
            result.unitResults.push_back(followerResult);
            continue;
        }
        char* sbh_copy = (char*)ilu_malloc(strlen(follower_sbh) + 1);
        strcpy(sbh_copy, follower_sbh);
        Unit_UnitSBHSeq_Append(followerSBHSeq, sbh_copy, &err);
        
        followerResult.success = true;
        followerResult.errorCode = 0;
        result.unitResults.push_back(followerResult);
    }

    LOG_INFO_S("_setAirSwarmFormation", 
        QString::fromUtf8("Calling sendControlledVehicle: %1 followers").arg(followerSBHSeq->_length));
    
    // 【测试点1】打印 follower 数量，两机时应该是 1
    qDebug() << QString::fromUtf8("========== 空中编队测试点 ==========");
    qDebug() << QString::fromUtf8("sendControlledVehicle followers = %1").arg(followerSBHSeq->_length);
    
    Air_Unit_rpc_sendControlledVehicle(leaderObj, followerSBHSeq, &en);
    if (!ILU_C_SUCCESSFUL(&en)) {
        LOG_ERROR_S("_setAirSwarmFormation", 
            QString::fromUtf8("sendControlledVehicle failed: %1").arg(en.returnCode));
        ILU_C_EXCEPTION_FREE(&en);
        Unit_UnitSBHSeq__Free(followerSBHSeq);
        leaderResult.success = false;
        leaderResult.errorCode = (int)en.returnCode;
        strncpy(leaderResult.errorMsg, "sendControlledVehicle failed", 255);
        result.unitResults.insert(result.unitResults.begin(), leaderResult);
        result.calculateCounts();
        return result;
    }
    Unit_UnitSBHSeq__Free(followerSBHSeq);

    // 2) 构造“只包含 follower”的 formation，下发给 leader
    Unit_Formation f2;
    f2.robot_ids  = *Unit_UnitIDSeq_Create(n_followers, NULL);
    f2.leader_ids = *Unit_ShortSeq_Create(n_followers, NULL);
    f2.distances  = *Unit_FloatSeq_Create(n_followers, NULL);
    f2.angles     = *Unit_FloatSeq_Create(n_followers, NULL);

    // 如果用户没有录入角度（多数UI没有角度输入），则给一组默认角度
    const std::vector<float> defaultAngles = _defaultAirAngles(n_followers);

    for (int k = 0; k < n_followers; ++k) {
        const int j = k + 1; // 原 formation 中 follower 的索引
        const char* follower_uid = *(Unit_UnitIDSeq_Nth(&formation->robot_ids, j));
        char* uid_copy = (char*)ilu_malloc(strlen(follower_uid) + 1);
        strcpy(uid_copy, follower_uid);
        Unit_UnitIDSeq_Append(&f2.robot_ids, uid_copy, &err);
        Unit_ShortSeq_Append(&f2.leader_ids, 0, &err);

        float dist = 0.0f;
        if ((int)formation->distances._length > j) {
            dist = *(Unit_FloatSeq_Nth(&formation->distances, j));
        }
        Unit_FloatSeq_Append(&f2.distances, dist, &err);

        float ang_in = 0.0f;
        if ((int)formation->angles._length > j) {
            ang_in = *(Unit_FloatSeq_Nth(&formation->angles, j));
        }
        const float ang = (ang_in == 0.0f && (int)defaultAngles.size() == n_followers) ? defaultAngles[k] : ang_in;
        Unit_FloatSeq_Append(&f2.angles, ang, &err);
    }

    // 【测试点2】打印 setFormation 的各序列长度，两机时都应该是 1
    qDebug() << QString::fromUtf8("setFormation followerCount = %1").arg(f2.robot_ids._length);
    qDebug() << QString::fromUtf8("setFormation distances.length = %1").arg(f2.distances._length);
    qDebug() << QString::fromUtf8("setFormation angles.length = %1").arg(f2.angles._length);
    qDebug() << QString::fromUtf8("setFormation leader_ids.length = %1").arg(f2.leader_ids._length);
    qDebug() << QString::fromUtf8("==========================================");

    Unit_rpc_setFormation((Unit_rpc)leaderObj, &f2, &en);
    if (!ILU_C_SUCCESSFUL(&en)) {
        LOG_ERROR_S("_setAirSwarmFormation", 
            QString::fromUtf8("Leader setFormation failed: %1").arg(en.returnCode));
        ILU_C_EXCEPTION_FREE(&en);
        Unit_UnitIDSeq__Free(&f2.robot_ids);
        Unit_ShortSeq__Free(&f2.leader_ids);
        Unit_FloatSeq__Free(&f2.distances);
        Unit_FloatSeq__Free(&f2.angles);
        leaderResult.success = false;
        leaderResult.errorCode = (int)en.returnCode;
        strncpy(leaderResult.errorMsg, "Leader setFormation failed", 255);
        result.unitResults.insert(result.unitResults.begin(), leaderResult);
        result.calculateCounts();
        return result;
    }

    Unit_UnitIDSeq__Free(&f2.robot_ids);
    Unit_ShortSeq__Free(&f2.leader_ids);
    Unit_FloatSeq__Free(&f2.distances);
    Unit_FloatSeq__Free(&f2.angles);

    // Insert leader result at the beginning
    result.unitResults.insert(result.unitResults.begin(), leaderResult);
    result.calculateCounts();
    
    LOG_INFO_S("_setAirSwarmFormation", 
        QString::fromUtf8("Air formation dispatch complete: success=%1, fail=%2")
            .arg(result.successCount).arg(result.failCount));
    
    return result;
}

// 返回详细结果的版本 (Requirements 10.2, 10.4)
FormationResult setFormationWithResult(Unit_Formation* formation) {
    FormationResult result;
    QElapsedTimer timer;
    timer.start();
    
    // Step 1: Log entry with full input parameters (Requirements 9.1)
    LOG_INFO_S("setFormation", 
        QString::fromUtf8("Entry: robot_ids=%1, leader_ids=%2, distances=%3, angles=%4")
            .arg(formatUnitIDSeq(&formation->robot_ids))
            .arg(formatShortSeq(&formation->leader_ids))
            .arg(formatFloatSeq(&formation->distances))
            .arg(formatFloatSeq(&formation->angles)));
    
    // Step 2: Validate formation (Requirements 1.5, 5.4)
    if (!validateFormation(formation)) {
        LOG_ERROR_S("setFormation", "Validation failed");
        // 返回失败结果
        UnitResult ur;
        ur.success = false;
        ur.errorCode = FE_INVALID_INPUT;
        strcpy(ur.errorMsg, "Formation validation failed");
        result.groundResult.unitResults.push_back(ur);
        result.groundResult.calculateCounts();
        result.elapsedMs = (int)timer.elapsed();
        return result;
    }
    
    // Step 3: Detect cross-type edges (Requirements 6.1)
    std::vector<CrossTypeEdge> crossEdges = detectCrossTypeEdges(formation);
    for (const auto& edge : crossEdges) {
        LOG_WARN_S("setFormation", 
            QString::fromUtf8("Cross-type edge detected [%1 -> %2], will be ignored")
                .arg(edge.fromUid).arg(edge.toUid));
    }
    
    // Step 4: Split formation into air and ground groups (Requirements 6.2, 6.4)
    SplitResult splitResult = splitFormation(formation);
    LOG_INFO_S("setFormation", 
        QString::fromUtf8("Split complete: air=%1 units, ground=%2 units")
            .arg(splitResult.airGroup.robot_ids._length)
            .arg(splitResult.groundGroup.robot_ids._length));
    
    // 保存跨类型边警告到结果中 (Requirements 6.1)
    result.crossTypeWarnings.clear();
    for (const auto& w : splitResult.warnings) {
        result.crossTypeWarnings.push_back(w);
    }
    
    // 标记孤立节点
    for (const auto& edge : splitResult.warnings) {
        for (auto& ur : result.airResult.unitResults) {
            if (strcmp(ur.uid, edge.fromUid) == 0) {
                ur.isOrphan = true;
            }
        }
        for (auto& ur : result.groundResult.unitResults) {
            if (strcmp(ur.uid, edge.fromUid) == 0) {
                ur.isOrphan = true;
            }
        }
    }
    
    // Step 5: Normalize topology for ground group only (Requirements 1.2, 1.4)
    // Air group uses STAR topology (fixed), ground group uses current strategy
    if (splitResult.groundGroup.robot_ids._length > 0) {
        QString beforeLeaderIds = formatShortSeq(&splitResult.groundGroup.leader_ids);
        normalizeTopology(&splitResult.groundGroup, currentTopologyStrategy);
        QString afterLeaderIds = formatShortSeq(&splitResult.groundGroup.leader_ids);
        LOG_INFO_S("setFormation", 
            QString::fromUtf8("Ground topology normalized: %1 -> %2")
                .arg(beforeLeaderIds).arg(afterLeaderIds));
    }
    
    // Step 6: Dispatch to air and ground paths
    
    // Air group dispatch (Requirements 4.1, 4.2, 4.3)
    if (splitResult.airGroup.robot_ids._length > 0) {
        LOG_INFO_S("setFormation", "Dispatching air group...");
        result.airResult = _setAirSwarmFormation(&splitResult.airGroup);
    }
    
    // Ground group dispatch (Requirements 7.1, 7.2, 7.3)
    if (splitResult.groundGroup.robot_ids._length > 0) {
        LOG_INFO_S("setFormation", "Dispatching ground group...");
        result.groundResult = _setGroundFormation(&splitResult.groundGroup);
    }
    
    // Step 7: Aggregate results and log completion (Requirements 9.5, 10.2, 10.4)
    result.elapsedMs = (int)timer.elapsed();
    
    bool overallSuccess = result.isSuccess();
    bool partialSuccess = result.isPartialSuccess();
    
    int totalSuccess = result.airResult.successCount + result.groundResult.successCount;
    int totalFail = result.airResult.failCount + result.groundResult.failCount;
    
    if (overallSuccess) {
        LOG_INFO_S("setFormation", 
            QString::fromUtf8("Complete: SUCCESS, total=%1, elapsed=%2ms")
                .arg(totalSuccess).arg(result.elapsedMs));
    } else if (partialSuccess) {
        LOG_WARN_S("setFormation", 
            QString::fromUtf8("Complete: PARTIAL SUCCESS, success=%1, fail=%2, elapsed=%3ms")
                .arg(totalSuccess).arg(totalFail).arg(result.elapsedMs));
        // Log failed units
        std::vector<UnitResult> failedUnits = result.getAllFailedUnits();
        for (const auto& ur : failedUnits) {
            LOG_ERROR_S("setFormation", 
                QString::fromUtf8("Failed unit: %1, error=%2, msg=%3")
                    .arg(ur.uid).arg(ur.errorCode).arg(ur.errorMsg));
        }
    } else {
        LOG_ERROR_S("setFormation", 
            QString::fromUtf8("Complete: FAILED, fail=%1, elapsed=%2ms")
                .arg(totalFail).arg(result.elapsedMs));
    }
    
    return result;
}

// 兼容旧接口：返回 bool
bool setFormation(Unit_Formation* formation) {
    FormationResult result = setFormationWithResult(formation);
    // Return true if any success (Requirements 10.1)
    return result.isSuccess() || result.isPartialSuccess();
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

        qDebug() <<QString::fromUtf8("当前状态无法设置任务路径，已取消！");
        return false;
    }else
        qDebug() <<QString::fromUtf8("任务点设置成功！");
    return true;
}



//单元停止
//todo: 现在停止的是车, 需要考虑飞机
//todo: 需要考虑屡顺IDL部分的共性转移到Unit中 .
//void stopUnit() {
//    Ground_Unit_MoveAction action;
//    CORBA_Environment ev;
//    if (currentUnitObj == NULL) {
//        qDebug() <<QString::fromUtf8("未选定控制单元！");
//        return;
//    }
//    action._d = Ground_Unit_MA_Stop;
//	action._u.stopData.ft_s = 0;
//	action._u.stopData.ft_t = 0;
//    Ground_Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);

//   if(ILU_C_SUCCESSFUL(&ev)){
//        qDebug() <<QString::fromUtf8("指令成功！");
//    }else{
//        qDebug() <<QString::fromUtf8("出现异常%1").arg(ev.returnCode);
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
            qDebug() << QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
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
        qDebug() << QString::fromUtf8("已清除文件%1").arg(backupCosNamingServerFileName);
    else
        qDebug() << QString::fromUtf8("文件%1不存在或正在被使用").arg(backupCosNamingServerFileName);
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
        qDebug() <<QString::fromUtf8("[setTrap] traps overflow, opertaion cancelled.");
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
            qDebug() <<QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
            ILU_C_EXCEPTION_FREE(&ev);}//endif
        if (tmpGrdObj) Ground_Unit_rpc__Free(&tmpGrdObj); } //endif

     if (((char *)uid)[0] == 'A') {
            tmpSkyObj = (Air_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Air_Unit_rpc__MSType, &ev);
         Air_Unit_rpc_setTrapPoint(tmpSkyObj, &trap._u.trapPoint3D, &ev);
        if (!ILU_C_SUCCESSFUL(&ev)) {
            qDebug() <<QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
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
                    qDebug() <<QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
                    ILU_C_EXCEPTION_FREE(&ev);
               } //endif  env
            if (tmpGrdObj) Ground_Unit_rpc__Free(&tmpGrdObj);
        } //end if ...G
        if (((char *)uid)[0] == 'A') {
            tmpAirObj = (Air_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Air_Unit_rpc__MSType, &ev);
            Air_Unit_rpc_clearTraps(tmpAirObj, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
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
            qDebug() <<QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
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
        qDebug() <<QString::fromUtf8("已清除文件%1").arg(backupFileName);
    else
        qDebug() <<QString::fromUtf8("文件%1不存在或正在被使用").arg(backupFileName);
    if (Units_Hash_Table != NULL){
        ilu_hash_FreeHashTable(Units_Hash_Table, ilu_free, ilu_free);
        Units_Hash_Table = NULL;
    }
    Units_Hash_Table = ilu_hash_MakeNewTable(MAX_UNIT_NUM, ilu_hash_HashString, ilu_hash_StringCompare);
    qDebug() <<QString::fromUtf8("已经重置cosnaming表");
    displayBoundUnit();
}

void usage(char* prom) {
    qDebug() <<QString::fromUtf8("%1用法：\t-host\t服务器主机地址\t-port\t服务器端口地址"
        "\t-sid\t服务器ID\t-ih\tInstance Handle"
        "\t-trans\t服务器传输层协议\t-protocol\t服务器应用层协议"
        "\t-use_cosnaming\t0|1|true|false\t-naming_sbh\tCosNaming Root SBH"
        "\t-console_name_path\tCosNaming路径"
        "\t-httpPort\tMCP HTTP API 端口(默认9001)\t-noHttp\t禁用 HTTP API"
        "\t-httpBind\tHTTP 绑定地址(默认127.0.0.1)\t-mockRobots\t测试用模拟车 unit_id 列表，逗号分隔，如 GV1 或 GV1,GV2").arg(prom);
}

/**
 * @brief 注册测试用 MOCK 单元；当 uid 已存在时覆盖旧绑定（如历史真实 SBH）。
 *
 * @param commaSeparatedUnitIds 逗号分隔 unit_id，例如 "GV1,GV2,GV3"
 * @description
 * 过去逻辑在 uid 已存在时直接 skip，导致历史备份里的真实 SBH（如 GV1 -> ilusbh:...）
 * 无法被 -mockRobots 覆盖。这里改为"同名即替换为 MOCK:uid"，避免每次手工删除备份文件。
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
            qDebug() << QString::fromUtf8("[MOCK] override existing uid %1").arg(uid);
        }
        char *uidStr = (char *)ilu_malloc((size_t)uba.size() + 1);
        strcpy(uidStr, uba.constData());
        const QString sbhQ = QString::fromUtf8("MOCK:") + uid;
        QByteArray sba = sbhQ.toUtf8();
        char *sbhStr = (char *)ilu_malloc((size_t)sba.size() + 1);
        strcpy(sbhStr, sba.constData());
        ilu_hash_AddToTable(Units_Hash_Table, uidStr, sbhStr);
        if (!hasExisting && uidStr[0] == 'G')
            currentGUVNum++;
        else if (!hasExisting && uidStr[0] == 'A')
            currentAUVNum++;
        MockRobotSimulator::instance().ensureUnit(uid);
        // 同步 AgentDirectory
        if (g_agentDirectory)
            g_agentDirectory->upsertBinding(makeLookupResult(uidStr, sbhStr, BindingOrigin::Mock));
        qDebug() << QString::fromUtf8("[MOCK] registered uid=%1 sbh=%2").arg(uid).arg(sbhQ);
    }
    if (st)
        emit st->infoAppended(QString::fromUtf8("[MOCK] 已注册模拟单元（仅 HTTP/MCP 可控制运动学）：%1").arg(csv));
}

ilu_boolean safe_strcpy(char* des, int size, char* from) {
    if (strlen(from) + 1 <= size) {
        strcpy(des, from);
        return ilu_TRUE;
    }
    return ilu_FALSE;
}

#ifndef UNIT_TEST
int main(int argc, char** args) {
    QApplication a(argc, args);
    st = new ServerThread();
    MainWindow w;
    UserInter = &w;
    //分配用户输入的参数
    int i = 1;
    char ch;
    CORBA_Environment ev;
    bool hostProvided = false;
    int httpPort = 9001;
    bool httpEnable = true;
    QHostAddress httpBind = QHostAddress::LocalHost;
    QString mockRobotsArg;
    while (i < argc) {
        if (strcmp(args[i], "-host") == 0)
            if (i + 1 < argc) {
                if (safe_strcpy(host, 20, args[i + 1])) {
                    hostProvided = true;
                } else {
                    qDebug() << "[Network] warning: -host is too long, keep current host:" << host;
                }
                i += 2;
            } else {
                i++;
                usage(args[0]);
            }
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
        else if (strcmp(args[i], "-use_cosnaming") == 0)
            if (i + 1 < argc) {
                use_cosnaming = parseBoolArg(args[i + 1]);
                i += 2;
            } else {
                i++;
                usage(args[0]);
            }
        else if (strcmp(args[i], "-naming_sbh") == 0)
            if (i + 1 < argc) {
                if (!safe_strcpy(naming_sbh, sizeof(naming_sbh), args[i + 1])) {
                    qDebug() << "[CosNaming] warning: naming_sbh is too long, ignore it";
                    naming_sbh[0] = '\0';
                }
                i += 2;
            } else {
                i++;
                usage(args[0]);
            }
        else if (strcmp(args[i], "-console_name_path") == 0)
            if (i + 1 < argc) {
                if (!safe_strcpy(console_name_path, sizeof(console_name_path), args[i + 1])) {
                    qDebug() << "[CosNaming] warning: console_name_path is too long, keep default";
                }
                i += 2;
            } else {
                i++;
                usage(args[0]);
            }
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
                    qDebug() << QString::fromUtf8("无效 -httpBind，使用 127.0.0.1");
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
        }
        else {
            i++;
            usage(args[0]);
        }
    }
    if (!hostProvided) {
        getLocalIP();
    }
    qDebug() << "[Network] final publish host:" << host;
    qDebug() <<QString::fromUtf8("完成参数解析");
    ILU_C_USE_OS_THREADS;
    if (!init()){
        qDebug() << "init failed in main of console";
        return 1;
    }
    qDebug() <<QString::fromUtf8("服务器已启动");
    qDebug() << "Console SBH:" << ILU_C_SBHOfObject(serviceObj);

    QObject::connect (st,SIGNAL(bindInfoChanged(QString)),UserInter,SLOT(updateBrowser(QString)));
    QObject::connect (st,SIGNAL(infoAppended(QString)),UserInter,SLOT(appendInfo(QString)));
    if (!mockRobotsArg.isEmpty())
        registerMockRobotsForTest(mockRobotsArg);

    // --- 智能体目录、状态与别名系统初始化 ---
    {
        g_agentDirectory = new AgentDirectory();
        if (g_agentDirectory->initialize()) {
            qDebug() << QString::fromUtf8("[AgentSystem] AliasStore loaded OK");
        }
        // 从已加载的哈希表同步初始绑定
        syncAgentDirectoryFromHashTable(BindingOrigin::Restored);
        // Mock 单元已在上面通过 registerMockRobotsForTest 单独 upsert（BindingOrigin::Mock）
        // 对 restore 后仍为 mock 的单元，重新标记为 Mock 来源
        if (Units_Hash_Table) {
            ilu_HashEnumerator_s he2{};
            ilu_refany uid2 = nullptr;
            ilu_refany sbh2 = nullptr;
            ilu_hash_BeginEnumeration(Units_Hash_Table, &he2);
            while (ilu_hash_Next(&he2, &uid2, &sbh2)) {
                const char *uidStr2 = (const char *)uid2;
                const char *sbhStr2 = (const char *)sbh2;
                if (MockRobotSimulator::isMockSbh(sbhStr2)) {
                    g_agentDirectory->upsertBinding(
                        makeLookupResult(uidStr2, sbhStr2, BindingOrigin::Mock));
                }
            }
        }
    }

    g_agentStatusService = new AgentStatusService();
    g_agentStatusService->setDirectory(g_agentDirectory);

    g_agentHttpController = new AgentHttpController(g_agentDirectory, g_agentStatusService);

    displayBoundUnit();
    st->start();
    HttpApiExecutor *httpApi = nullptr;
    HttpPlugin *httpPlugin = nullptr;
    if (httpEnable && httpPort > 0 && httpPort <= 65535) {
        httpApi = new HttpApiExecutor(&a);
        httpPlugin = new HttpPlugin(httpApi, &a);
        // 注入 /api/agent/* 路由处理器
        httpApi->setAgentHttpController(g_agentHttpController);
        if (!httpPlugin->start(quint16(httpPort), httpBind))
            qDebug() << QString::fromUtf8("HTTP 插件未启动");
    }
    w.show();
    QTimer::singleShot(1000, []() {
        registerConsoleToCosNaming();
    });
    return a.exec();
}
#endif // UNIT_TEST

CORBA_boolean server_Console_rpc_setCosNamingInfo
    (Console_rpc _handle, Unit_UnitInfoSeq* infoSeq, ILU_C_ENVIRONMENT *_status){
    qDebug() <<QString::fromUtf8("[setCosNamingInfo]no implement");
    Console__BindExceptionValue(_status, ex_CORBA_NO_IMPLEMENT);
    return ilu_FALSE;

}

Unit_UnitInfoSeq* server_Console_rpc_getCosNamingInfo(Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    qDebug() <<QString::fromUtf8("[getCosNamingInfo]no implement");
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
        // 同步 AgentDirectory
        if (g_agentDirectory)
            g_agentDirectory->upsertBinding(makeLookupResult(uid, sbh, BindingOrigin::Runtime));
        qDebug() <<QString::fromUtf8("[handleBindOperation] done.");
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
                qDebug() << QString::fromUtf8("[bind] %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setRole(tmpObj, Unit_UR_Follower, "null", _status);//设置角色
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QString::fromUtf8("[bind] (setRole) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setALeader(tmpObj, ILU_C_SBHOfObject(currentGUVLeaderObj), _status);//设置leader
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QString::fromUtf8("[bind] (setALeader) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setMode(tmpObj, currentMode, _status);//设置模式
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QString::fromUtf8("[bind] (setMode) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
                return ilu_FALSE;
            }
            
            Unit_rpc_setMinorMode(tmpObj, currentMinorMode, _status);//设置次模式
            if (!ILU_C_SUCCESSFUL(_status)) {
                qDebug() << QString::fromUtf8("[bind] (setMinorMode) %1: %2").arg(uid).arg(_status->returnCode);
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
                qDebug() << QString::fromUtf8("[bind] (setTrap) %1: %2").arg(uid).arg(_status->returnCode);
                ILU_C_EXCEPTION_FREE(_status);
            }
        }
        
        qDebug() << QString::fromUtf8("[bind]单元%1已绑定此控制台").arg(uid);
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
        qDebug() <<QString::fromUtf8("item %1 not found in backup file").arg(uid);
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
                qDebug() << QString::fromUtf8("[unbind] Leader calling unbind!");
                //遍历setFollowMode
                ilu_refany uid, sbh;
                ilu_HashEnumerator_s he;
                CORBA_Environment ev;
                Ground_Unit_rpc tmpObj;
                ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
                while (ilu_hash_Next(&he, &uid, &sbh)) {
                    if (strcmp((char*)uid, currentLeaderUID) != 0) {
                        qDebug() << QString::fromUtf8("[unbind] set None role for %1").arg((char*)uid);
                        tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
                        Unit_rpc_setRole(tmpObj, Unit_UR_None, "null", &ev);
                        if (!ILU_C_SUCCESSFUL(&ev)) {
                            qDebug() << QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
                            ILU_C_EXCEPTION_FREE(&ev);
                        }
                        Ground_Unit_rpc__Free(&tmpObj);
                    }
                }
                if (currentGUVLeaderObj != NULL) {
                    qDebug() << QString::fromUtf8("[unbind] set None role for Learder %1").arg((char*)uid);
                    Unit_rpc_setRole(currentGUVLeaderObj, Unit_UR_None, "null", &ev);
                    if (!ILU_C_SUCCESSFUL(&ev)) {
                        qDebug() << QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
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
            // 同步 AgentDirectory（别名记录保留，仅移除绑定）
            if (g_agentDirectory)
                g_agentDirectory->removeBinding(QString::fromUtf8(uid));
            if (backupCosObj != NULL) {
                Console_Message m;
                m._d = Console_OP_Unbind;
                m._u.unbindInfo.uid = uid;
                m._u.unbindInfo.details = details;
                Console_rpc_sendMsg(backupCosObj, &m, _status);
            }
            qDebug() << QString::fromUtf8("[unbind] 单元%1已解除绑定, details = %2").arg(uid).arg(details);
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
        qDebug() <<QString::fromUtf8("[sendMsg] Bind.");
        handleBindOperation(m->_u.bindInfo.uid, m->_u.bindInfo.sbh, _status);
        qDebug() <<QString::fromUtf8("[sendMsg] 单元%1已绑定此控制台").arg(m->_u.bindInfo.uid);
        displayBoundUnit();//update
        return ilu_TRUE;
        break;
    case Console_OP_Unbind:
        qDebug() <<QString::fromUtf8("[sendMsg] Unbind.");
        if (Units_Hash_Table != NULL) {
            if (ilu_hash_FindInTable(Units_Hash_Table, m->_u.unbindInfo.uid) != ILU_NIL) {
                ilu_hash_RemoveFromTable(Units_Hash_Table, m->_u.unbindInfo.uid);
                if(m->_u.unbindInfo.uid[0] == 'G')
                    currentGUVNum --;
                if(m->_u.unbindInfo.uid[0] == 'A')
                    currentAUVNum --;
                qDebug() <<QString::fromUtf8("[sendMsg] %1").arg(m->_u.unbindInfo.uid);
                removeFromBackupFile(m->_u.unbindInfo.uid);
                // 同步 AgentDirectory（别名记录保留，仅移除绑定）
                if (g_agentDirectory)
                    g_agentDirectory->removeBinding(QString::fromUtf8(m->_u.unbindInfo.uid));
                qDebug() <<QString::fromUtf8("[sendMsg] 单元%1已解除绑定, details = %2").arg(m->_u.unbindInfo.uid).arg(m->_u.unbindInfo.details);
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
        qDebug() <<QString::fromUtf8("[sendMsg] report trap start.");
        if (currentTrapPointsNum == MAX_TRAP_POINT_NUM) {
            qDebug() <<QString::fromUtf8("[sendMsg] traps overflow, opertaion cancelled.");
            return ilu_FALSE;
        }
        ilu_hash_BeginEnumeration(Units_Hash_Table, &he);
        while (ilu_hash_Next(&he, &uid, &sbh)) {
            tmpObj = (Ground_Unit_rpc)ILU_C_SBHToObject((char*)sbh, Ground_Unit_rpc__MSType, &ev);
            Ground_Unit_rpc_setTrapPoint(tmpObj, &m->_u.tp._u.trapPoint2D, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)) {
                qDebug() <<QString::fromUtf8("%1: %2").arg((char*)uid).arg(ev.returnCode);
                ILU_C_EXCEPTION_FREE(&ev);
            }
            Ground_Unit_rpc__Free(&tmpObj);
        }
        emit st->infoAppended(QString::fromUtf8("成功收到汇报的陷阱点(%1,%2)�뾶Ϊ%3��").arg(m->_u.tp._u.trapPoint2D.point.x).arg(m->_u.tp._u.trapPoint2D.point.y).arg(m->_u.tp._u.trapPoint2D.radius));
        qDebug() <<QString::fromUtf8("[sendMsg] report trap end.");
    case Console_OP_AddTrap:
        /*写入备份文件*/
        qDebug() <<QString::fromUtf8("[sendMsg] add trap start.");
        if (currentTrapPointsNum == MAX_TRAP_POINT_NUM) {
            qDebug() <<QString::fromUtf8("[sendMsg] traps overflow, opertaion cancelled.");
            return ilu_FALSE;
        }
        trapPoints[currentTrapPointsNum] = m->_u.tp;
        currentTrapPointsNum ++;
        trapsBackupFile = fopen(backupTrapsFileName, "a+");
        fprintf(trapsBackupFile, "%f,%f,%f\n", m->_u.tp._u.trapPoint2D.point.x, m->_u.tp._u.trapPoint2D.point.y, m->_u.tp._u.trapPoint2D.radius);
        fclose(trapsBackupFile);
        qDebug() <<QString::fromUtf8("[sendMsg] add trap end.");
        emit st->infoAppended(QString::fromUtf8("成功添加陷阱点(%1,%2)�뾶Ϊ%3!").arg(m->_u.tp._u.trapPoint2D.point.x).arg(m->_u.tp._u.trapPoint2D.point.y).arg(m->_u.tp._u.trapPoint2D.radius));
        break;
    case Console_OP_SetCosInfo:
        return ilu_FALSE;
        break;
    case Console_OP_Opened:
        qDebug() <<QString::fromUtf8("[sendMsg] %1").arg(m->_u.details);
        break;
    case Console_OP_Closed:
        qDebug() <<QString::fromUtf8("[sendMsg] %1").arg(m->_u.details);
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
    qDebug() << QString::fromUtf8("[rebind] 请求: uid=%1 -> %2").arg(uid).arg(sbh);

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
        qDebug() << QString::fromUtf8("[rebind] 更新哈希/备份失败");
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
    Console_FormationType tmp;
     return tmp;
 }

 Console_FormationState server_Console_rpc_getFormationState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
    Console_FormationState tmp;
     return tmp;
 }

Console_MissionState server_Console_rpc_getMissionState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     Console_MissionState tmp;
     return tmp;
  }

 Console_Point server_Console_rpc_getUnitPoint (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status){
     Console_Point tmp;
     return tmp;
  }

 Unit_UnitInfo* server_Console_rpc_getByName (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status){
     return NULL;
  }

 Console_Point server_Console_rpc_getLeaderPoint (Console_rpc _handle, ILU_C_ENVIRONMENT *_status){
     Console_Point tmp;
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

/*======================================================================*/
/*=============== 核心算法实现 (Requirements 1, 5, 6) ==================*/
/*======================================================================*/

// 校验 formation 数据有效性 (Requirements 1.5, 5.4)
// 检查: formation非空、长度一致性、leader_ids索引有效性
bool validateFormation(const Unit_Formation* formation) {
    // 检查 formation 非空
    if (formation == NULL) {
        LOG_ERROR_S("validateFormation", "formation is NULL");
        return false;
    }
    
    // 检查 robot_ids 非空且长度 >= 1
    if (formation->robot_ids._length == 0) {
        LOG_ERROR_S("validateFormation", "robot_ids is empty");
        return false;
    }
    
    unsigned long n = formation->robot_ids._length;
    
    // 检查 leader_ids 长度一致性
    if (formation->leader_ids._length != n) {
        LOG_ERROR_S("validateFormation", 
            QString::fromUtf8("leader_ids length mismatch: expected %1, got %2")
                .arg(n).arg(formation->leader_ids._length));
        return false;
    }
    
    // 检查 distances 长度一致性
    if (formation->distances._length != n) {
        LOG_ERROR_S("validateFormation", 
            QString::fromUtf8("distances length mismatch: expected %1, got %2")
                .arg(n).arg(formation->distances._length));
        return false;
    }
    
    // 检查 angles 长度一致性
    if (formation->angles._length != n) {
        LOG_ERROR_S("validateFormation", 
            QString::fromUtf8("angles length mismatch: expected %1, got %2")
                .arg(n).arg(formation->angles._length));
        return false;
    }
    
    // 检查 leader_ids 索引有效性 (Requirements 1.5, 5.4)
    // 所有 leader_ids[i] 必须是有效索引: 0 <= leader_ids[i] < n
    for (unsigned long i = 0; i < n; i++) {
        CORBA_short leaderIdx = formation->leader_ids._buffer[i];
        if (leaderIdx < 0 || (unsigned long)leaderIdx >= n) {
            LOG_ERROR_S("validateFormation", 
                QString::fromUtf8("invalid leader_ids[%1]=%2, valid range is [0, %3)")
                    .arg(i).arg(leaderIdx).arg(n));
            return false;
        }
    }
    
    // 检查第一个节点（Leader）的 leader_ids[0] 必须为 0（自己跟随自己）
    if (formation->leader_ids._buffer[0] != 0) {
        LOG_WARN_S("validateFormation", 
            QString::fromUtf8("leader_ids[0]=%1, expected 0 (Leader should follow itself)")
                .arg(formation->leader_ids._buffer[0]));
        // 这是警告，不是错误，允许继续
    }
    
    LOG_INFO_S("validateFormation", 
        QString::fromUtf8("validation passed: %1 units").arg(n));
    return true;
}

// 检测跨类型边 (Requirements 6.1)
// 遍历 leader_ids，检测 A→G 或 G→A 边
// 返回: 跨类型边列表
std::vector<CrossTypeEdge> detectCrossTypeEdges(const Unit_Formation* formation) {
    std::vector<CrossTypeEdge> crossEdges;
    
    if (formation == NULL || formation->robot_ids._length == 0) {
        return crossEdges;
    }
    
    unsigned long n = formation->robot_ids._length;
    
    for (unsigned long i = 0; i < n; i++) {
        CORBA_short leaderIdx = formation->leader_ids._buffer[i];
        
        // 跳过自己跟随自己的情况（Leader节点）
        if (leaderIdx == (CORBA_short)i) {
            continue;
        }
        
        // 获取当前节点和其leader的UID
        const char* currentUid = formation->robot_ids._buffer[i];
        const char* leaderUid = formation->robot_ids._buffer[leaderIdx];
        
        if (currentUid == NULL || leaderUid == NULL) {
            continue;
        }
        
        // 获取单元类型（第一个字符：'A'=空中, 'G'=地面）
        char currentType = currentUid[0];
        char leaderType = leaderUid[0];
        
        // 检测跨类型边：A→G 或 G→A
        if ((currentType == 'A' && leaderType == 'G') ||
            (currentType == 'G' && leaderType == 'A')) {
            CrossTypeEdge edge;
            edge.fromIndex = (int)i;
            edge.toIndex = (int)leaderIdx;
            strncpy(edge.fromUid, currentUid, MAX_UNITID_LENGTH - 1);
            edge.fromUid[MAX_UNITID_LENGTH - 1] = '\0';
            strncpy(edge.toUid, leaderUid, MAX_UNITID_LENGTH - 1);
            edge.toUid[MAX_UNITID_LENGTH - 1] = '\0';
            
            crossEdges.push_back(edge);
            
            LOG_WARN_S("detectCrossTypeEdges", 
                QString::fromUtf8("检测到跨类型边[%1→%2]")
                    .arg(currentUid).arg(leaderUid));
        }
    }
    
    if (crossEdges.empty()) {
        LOG_INFO_S("detectCrossTypeEdges", "未检测到跨类型边");
    } else {
        LOG_INFO_S("detectCrossTypeEdges", 
            QString::fromUtf8("检测到 %1 条跨类型边").arg(crossEdges.size()));
    }
    
    return crossEdges;
}

// 拆分混合编队为空中组和地面组 (Requirements 6.2, 6.4)
// 按单元类型拆分，重映射 leader_ids 索引，跨类型边降级为独立节点
SplitResult splitFormation(const Unit_Formation* formation) {
    SplitResult result;
    
    if (formation == NULL || formation->robot_ids._length == 0) {
        LOG_WARN_S("splitFormation", "formation is NULL or empty");
        return result;
    }
    
    unsigned long n = formation->robot_ids._length;
    ilu_Error err;
    
    // 初始化结果的序列
    Unit_UnitIDSeq_Init(&result.airGroup.robot_ids, 0, nullptr);
    Unit_ShortSeq_Init(&result.airGroup.leader_ids, 0, nullptr);
    Unit_FloatSeq_Init(&result.airGroup.distances, 0, nullptr);
    Unit_FloatSeq_Init(&result.airGroup.angles, 0, nullptr);
    
    Unit_UnitIDSeq_Init(&result.groundGroup.robot_ids, 0, nullptr);
    Unit_ShortSeq_Init(&result.groundGroup.leader_ids, 0, nullptr);
    Unit_FloatSeq_Init(&result.groundGroup.distances, 0, nullptr);
    Unit_FloatSeq_Init(&result.groundGroup.angles, 0, nullptr);
    
    // 建立原索引到新索引的映射
    std::vector<int> airIdxMap(n, -1);    // 原索引 -> 空中组新索引
    std::vector<int> groundIdxMap(n, -1); // 原索引 -> 地面组新索引
    std::vector<bool> isAirUnit(n, false);
    
    // 第一遍：分类并建立索引映射
    int airCount = 0;
    int groundCount = 0;
    
    for (unsigned long i = 0; i < n; i++) {
        const char* uid = formation->robot_ids._buffer[i];
        if (uid == NULL) continue;
        
        if (uid[0] == 'A') {
            isAirUnit[i] = true;
            airIdxMap[i] = airCount++;
        } else {
            isAirUnit[i] = false;
            groundIdxMap[i] = groundCount++;
        }
    }
    
    LOG_INFO_S("splitFormation", 
        QString::fromUtf8("分类完成: 空中=%1, 地面=%2").arg(airCount).arg(groundCount));
    
    // 检测跨类型边
    std::vector<CrossTypeEdge> crossEdges = detectCrossTypeEdges(formation);
    result.warnings = crossEdges;
    
    // 建立跨类型边的集合，用于快速查找
    std::vector<bool> hasCrossTypeEdge(n, false);
    for (const auto& edge : crossEdges) {
        hasCrossTypeEdge[edge.fromIndex] = true;
    }
    
    // 第二遍：填充数据并重映射 leader_ids
    for (unsigned long i = 0; i < n; i++) {
        const char* uid = formation->robot_ids._buffer[i];
        if (uid == NULL) continue;
        
        CORBA_short origLeaderIdx = formation->leader_ids._buffer[i];
        CORBA_float dist = formation->distances._buffer[i];
        CORBA_float angle = formation->angles._buffer[i];
        
        // 复制 UID
        char* uidCopy = (char*)ilu_malloc(strlen(uid) + 1);
        strcpy(uidCopy, uid);
        
        if (isAirUnit[i]) {
            // 空中单元
            Unit_UnitIDSeq_Append(&result.airGroup.robot_ids, uidCopy, &err);
            Unit_FloatSeq_Append(&result.airGroup.distances, dist, &err);
            Unit_FloatSeq_Append(&result.airGroup.angles, angle, &err);
            
            // 重映射 leader_ids
            CORBA_short newLeaderIdx;
            if (hasCrossTypeEdge[i]) {
                // 跨类型边：降级为独立节点（自己跟随自己）
                newLeaderIdx = (CORBA_short)airIdxMap[i];
                LOG_WARN_S("splitFormation", 
                    QString::fromUtf8("%1 因跨类型边降级为独立节点").arg(uid));
            } else if (airIdxMap[origLeaderIdx] >= 0) {
                // Leader 也是空中单元，使用重映射后的索引
                newLeaderIdx = (CORBA_short)airIdxMap[origLeaderIdx];
            } else {
                // Leader 是地面单元（跨类型），降级为独立节点
                newLeaderIdx = (CORBA_short)airIdxMap[i];
            }
            Unit_ShortSeq_Append(&result.airGroup.leader_ids, newLeaderIdx, &err);
        } else {
            // 地面单元
            Unit_UnitIDSeq_Append(&result.groundGroup.robot_ids, uidCopy, &err);
            Unit_FloatSeq_Append(&result.groundGroup.distances, dist, &err);
            Unit_FloatSeq_Append(&result.groundGroup.angles, angle, &err);
            
            // 重映射 leader_ids
            CORBA_short newLeaderIdx;
            if (hasCrossTypeEdge[i]) {
                // 跨类型边：降级为独立节点
                newLeaderIdx = (CORBA_short)groundIdxMap[i];
                LOG_WARN_S("splitFormation", 
                    QString::fromUtf8("%1 因跨类型边降级为独立节点").arg(uid));
            } else if (groundIdxMap[origLeaderIdx] >= 0) {
                // Leader 也是地面单元，使用重映射后的索引
                newLeaderIdx = (CORBA_short)groundIdxMap[origLeaderIdx];
            } else {
                // Leader 是空中单元（跨类型），降级为独立节点
                newLeaderIdx = (CORBA_short)groundIdxMap[i];
            }
            Unit_ShortSeq_Append(&result.groundGroup.leader_ids, newLeaderIdx, &err);
        }
    }
    
    LOG_INFO_S("splitFormation", 
        QString::fromUtf8("拆分完成: 空中组=%1个, 地面组=%2个, 跨类型边=%3条")
            .arg(result.airGroup.robot_ids._length)
            .arg(result.groundGroup.robot_ids._length)
            .arg(result.warnings.size()));
    
    return result;
}

// 归一化拓扑结构 (Requirements 1.2, 1.4)
// 将星形拓扑转换为链式拓扑，避免多个 Follower 追同一目标点导致相撞
// 空中组跳过归一化（固定使用 STAR 策略）
void normalizeTopology(Unit_Formation* formation, TopologyStrategy strategy) {
    if (formation == NULL || formation->robot_ids._length <= 1) {
        return;
    }
    
    // 如果策略是 STAR，保持原样不变
    if (strategy == TOPOLOGY_STAR) {
        LOG_INFO_S("normalizeTopology", "策略为STAR，跳过归一化");
        return;
    }
    
    unsigned long n = formation->robot_ids._length;
    
    // 检查是否是空中编队（第一个单元是空中单元）
    const char* firstUid = formation->robot_ids._buffer[0];
    if (firstUid != NULL && firstUid[0] == 'A') {
        LOG_INFO_S("normalizeTopology", "空中编队固定使用STAR策略，跳过归一化");
        return;
    }
    
    // 记录归一化前的 leader_ids
    QString beforeLeaderIds = formatShortSeq(&formation->leader_ids);
    
    // 统计每个节点的直接后车列表
    // followers[leader_idx] = [follower_indices...]
    std::vector<std::vector<int>> followers(n);
    
    for (unsigned long i = 1; i < n; i++) {
        CORBA_short leaderIdx = formation->leader_ids._buffer[i];
        if (leaderIdx >= 0 && (unsigned long)leaderIdx < n) {
            followers[leaderIdx].push_back((int)i);
        }
    }
    
    // 对于有多个直接后车的节点，按录入顺序串成链
    bool modified = false;
    for (unsigned long leaderIdx = 0; leaderIdx < n; leaderIdx++) {
        if (followers[leaderIdx].size() > 1) {
            // 有多个后车，需要串成链
            // 按录入顺序：F1→F2→F3...
            // 即 F2 的 leader 改为 F1，F3 的 leader 改为 F2
            for (size_t k = 1; k < followers[leaderIdx].size(); k++) {
                int currentFollower = followers[leaderIdx][k];
                int previousFollower = followers[leaderIdx][k - 1];
                formation->leader_ids._buffer[currentFollower] = (CORBA_short)previousFollower;
                modified = true;
            }
            
            LOG_INFO_S("normalizeTopology", 
                QString::fromUtf8("节点%1的%2个后车已串成链式")
                    .arg(leaderIdx).arg(followers[leaderIdx].size()));
        }
    }
    
    if (modified) {
        QString afterLeaderIds = formatShortSeq(&formation->leader_ids);
        LOG_INFO_S("normalizeTopology", 
            QString::fromUtf8("归一化完成: %1 -> %2").arg(beforeLeaderIds).arg(afterLeaderIds));
    } else {
        LOG_INFO_S("normalizeTopology", "无需归一化，拓扑已是链式");
    }
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

/*
修订记录

2025-07-07 WXC
1 根据新的IDL命名法则,数据说明在Interface之外,进行相应代码修订
2 数据结构序列的命名, 要用Seq而非Sequence
3 当进行新版本与你自己修订的版本合并的时候,一定确认合并后没有冲突再行提交
4 请一定注意Linux和Window系统对温饱工程格式的差异会导致中文的 乱码.需要保障无论是在Linux 环视Window系统下都要正确显示,才能提交.
*/
