#!/usr/bin/env python
# need to change: 2 GV1 ,rikibot1(serverid),ip
import sys

# ---- 确保 stub/skeleton 在搜索路径中 ----
sys.path.append('/home/zgy/SRIOProject/ROSRobot/PySrc/Build/stubber')
sys.path.append('/home/zgy/SRIOProject/ilu/lib')

# ---- 这些模块来自你生成的 stub/skeleton ----
import Ground_Unit__skel, Ground_Unit, Console, Console__skel, Unit, Unit__skel, Air_Unit, Air_Unit__skel, ilu

import roslib; roslib.load_manifest('Ground_Vehicle')
import rospy
import time, threading, thread, datetime, math
import numpy as np
from math import radians, copysign, sqrt, pow, pi, atan2
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3
from collections import deque  # deque 来自 collections
from math import cos, sin
import Queue

from geometry_msgs.msg import Point
from geometry_msgs.msg import Vector3
import tf
from tf.transformations import euler_from_quaternion
# ======== Console 操作码适配：兼容 Console.Console_Operation.OP_* / Console.OP_* 两种导出 ========
def _COP(name):
    # 先尝试 Console.Console_Operation.OP_*
    if hasattr(Console, 'Console_Operation') and hasattr(Console.Console_Operation, name):
        return getattr(Console.Console_Operation, name)
    # 再尝试 Console.OP_*（模块级常量）
    if hasattr(Console, name):
        return getattr(Console, name)
    return None  # 没找到就返回 None，便于日志判定
# ==============================================================================

# ===== BIND 调试工具 =====
import socket, re, traceback  # 需要这三个
# ======== 动作枚举适配，不再直接用 MoveActionType ========
def _MA(name):
    # 先尝试 Unit.MoveActionType.MA_*
    try:
        return getattr(Unit.MoveActionType, name)
    except Exception:
        pass
    # 尝试 Unit.MA_*
    if hasattr(Unit, name):
        return getattr(Unit, name)
    # 尝试 Ground_Unit.MoveActionType.MA_*
    try:
        return getattr(Ground_Unit.MoveActionType, name)
    except Exception:
        pass
    # 尝试 Ground_Unit.MA_*
    if hasattr(Ground_Unit, name):
        return getattr(Ground_Unit, name)
    # 都没有就返回 None（方便排查）
    return None
# （可选）第一次用到时打印有哪些可用枚举
_MA_DEBUG_ONCE = True
def _ma_debug_once():
    global _MA_DEBUG_ONCE
    if _MA_DEBUG_ONCE:
        print "[ENUM DEBUG] Unit:", [a for a in dir(Unit) if a.startswith("MA_") or "MoveAction" in a]
        print "[ENUM DEBUG] Ground_Unit:", [a for a in dir(Ground_Unit) if a.startswith("MA_") or "MoveAction" in a]
        _MA_DEBUG_ONCE = False
# ==========================================================


def _preflight_tcp(sbh):
    m = re.search(r'iiop@tcp_([^_]+)_(\d+)', sbh)
    if not m:
        print "[BIND_DEBUG] WARN: cannot parse host/port from SBH:", sbh
        return True
    host, port = m.group(1), int(m.group(2))
    try:
        sock = socket.create_connection((host, port), timeout=2.0)
        sock.close()
        print "[BIND_DEBUG] TCP ok:", host, port
        return True
    except Exception as e:
        print "[BIND_DEBUG] TCP fail:", host, port, e
        return False

def _try_bind_console(theService, selfuid, my_sbh):
    # 先试 (uid, sbh)
    try:
        print "[BIND_DEBUG] TRY bind(uid,sbh):", selfuid, my_sbh
        rc = theService.bind(selfuid, my_sbh)
        print "[BIND_DEBUG] rc(uid,sbh) =", rc
        if rc == 1:
            return 1
    except Exception as e:
        print "[BIND_DEBUG] EXC bind(uid,sbh):", e
        traceback.print_exc()

    # 再试 (Console_CosInfoNode)
    try:
        if hasattr(Console, "Console_CosInfoNode"):
            node = Console.Console_CosInfoNode(selfuid, my_sbh)
            print "[BIND_DEBUG] TRY bind(Console_CosInfoNode):", node.uid
            rc = theService.bind(node)
            print "[BIND_DEBUG] rc(CosInfoNode) =", rc
            if rc == 1:
                return 1
        else:
            print "[BIND_DEBUG] WARN: no Console_CosInfoNode in stubs"
    except Exception as e:
        print "[BIND_DEBUG] EXC bind(CosInfoNode):", e
        traceback.print_exc()

    # 有些实现要求先“开门”
    try:
        if hasattr(Console, "Console_Operation") and hasattr(theService, "sendMsg"):
            print "[BIND_DEBUG] TRY sendMsg(OP_Opened)"
            
            theService.sendMsg([_COP('OP_Bind'), None])       
           # theService.sendMsg([Console.Console_Operation.OP_Opened, None])
            print "[BIND_DEBUG] RETRY bind(uid,sbh) after OP_Opened"
            rc = theService.bind(selfuid, my_sbh)
            print "[BIND_DEBUG] rc(retry) =", rc
            if rc == 1:
                return 1
    except Exception as e:
        print "[BIND_DEBUG] WARN: OP_Opened/retry failed:", e
        traceback.print_exc()

    return 0
# ===== BIND 调试工具结束 =====


tf_listener = None
odom_frame = None
base_frame = None


def get_odom_init():  # virtual
    global tf_listener, odom_frame, base_frame
    tf_listener = tf.TransformListener()
    odom_frame = 'odom'
    try:
        tf_listener.waitForTransform(odom_frame, 'base_footprint', rospy.Time(), rospy.Duration(1.0))
        base_frame = 'base_footprint'
    except (tf.Exception, tf.ConnectivityException, tf.LookupException):
        try:
            tf_listener.waitForTransform(odom_frame, 'base_link', rospy.Time(), rospy.Duration(1.0))
            base_frame = 'base_link'
        except (tf.Exception, tf.ConnectivityException, tf.LookupException):
            print "Cannot find transform between odom and base_link or base_footprint"
            print "tf Exception"


def get_odom():
    try:
        (trans, rot) = tf_listener.lookupTransform(odom_frame, base_frame, rospy.Time(0))
        rotation = euler_from_quaternion(rot)
    except (tf.Exception, tf.ConnectivityException, tf.LookupException):
        print "TF Exception"
        return
    return (Point(*trans), rotation[2])


pub = rospy.Publisher('cmd_vel', Twist, queue_size=1)
rospy.init_node('teleop_twist_keyboard')
speed = rospy.get_param("~speed", 0.5)
speed = 1
turn = rospy.get_param("~turn", 1.0)
turn = 1
x = 0
y = 0
z = 0
th = 0
safeDistance = 0.3
posx = 0.0
posy = 0.0
angle = 0.0
angleX = 0
status = 0
selfuid = "GV" + rospy.get_param('ground_vehicle/id')
start = datetime.datetime.now()

CurrentInfo = None
CurrentActionKind = None

# ---- ILU 基础设施 ----
ilu.ThreadedOperation()
loopvar = ilu.CreateLoopHandle()
consoleloopvar = ilu.CreateLoopHandle()
theServer = None
theObject = None
theService = None
ConsoleServer = None
ConsoleObject = None
autoPathThreading = 0

# FrontUnitInfo=Unit.General_Unit_UnitInfo("None","None")
FrontUnitInfo = Unit.UnitInfo("None", "None")
autoTellThreading = {}
goal_x = 0
goal_y = 0
followerobj = {}
followerPointobj = {}
queue = deque()
taskPath = Queue.Queue()
consoleClosed = 0  # 1:off 0:on


class Leader:
    def __init__(self):
        self.obj = None
        self.value = 0


leaderObj = Leader()
Demonstate = 0
dict = []
robots = []
otherVehicleTable = {}  # 用于存储其他无人车信息的字典
diss = []
leaders = []
angs = []
leaderV = 0.08
followerV = 0.14
Role = Unit.UnitRole.UR_None
currentMode = Unit.UnitMode.UM_None
currentMinorMode = Unit.UnitMinorMode.UMM_None
flash = 0
staticnow = 1
traplist = []
selfradius = 0.5
vehicle_radius = 0.6
count_right = 0
count_wrong = 0
old = 0
current_yaw = 0
lock = threading.Lock()
sbh = []
num = rospy.get_param('ground_vehicle/sbhNum')
for a in range(num + 1):
    if a != int(rospy.get_param('ground_vehicle/id')):
        sbh = sbh + [rospy.get_param('ground_vehicle/conSBH' + str(a))]


class DesInfo:
    def __init__(self):
        self.PosX = 0.0
        self.PosY = 0.0
        self.angle = 0.0
        self.speedX = 0.0
        self.speedT = 0.0
        self.second = 0
        self.stop = 0


def callback(data):
    global posx, posy, angle
    posx = data.position.x
    posy = data.position.y
    # angle=data.angle.z#+180


def euler_callback(msg):
    global current_yaw, angle
    current_yaw = msg.z  # 默认弧度
    angle = current_yaw * 180 / (3.1415926)


rospy.Subscriber("/euler_angles", Vector3, euler_callback)


def listen():
    rospy.spin()


def calangle(goal_x, goal_y):
    global angleX, posx, posy, angle
    tempangle = angleX - angle + ((math.atan2((goal_y - posy), (goal_x - posx)) * 360) / (2 * math.pi))
    if tempangle > 180.0:
        a = tempangle
        tempangle = (0 - (360 - a))
    if (tempangle < -180):
        a = tempangle
        tempangle = (360 + a)
    return tempangle


def deletpoint(x, y, dis):
    global taskPath, safeDistance
    while (taskPath.qsize() != 0):
        testpoint = taskPath.get()
        goal_distance = sqrt(pow(testpoint[0].x - x, 2) + pow(testpoint[0].y - y, 2))
        if goal_distance > (dis + 0.3):
            return testpoint
            break
    point = Ground_Unit.Point2D(0, 0)
    return [point, 0]


def towardGoal(goal_x, goal_y, dis):
    print "start to goal: " + str(goal_x) + "," + str(goal_y)
    global posx, posy, angle, th, x, selfradius, lock
    global followerPointobj, Role, taskPath, flash
    if Role == Unit.UnitRole.UR_Follower:
        max_velocity = followerV
    else:
        max_velocity = leaderV
    max_omega = 1.5
    booltrap = checktrap(posx, posy)
    if booltrap[0] == 0:
        lock.acquire()
        goal_dis = sqrt(pow(goal_x - booltrap[1][0], 2) + pow(goal_y - booltrap[1][1], 2))
        if goal_dis > (booltrap[1][2]):
            po = Ground_Unit.Point2D(goal_x, goal_y)
            nextpoint = [po, safeDistance]
        else:
            flash = 1
            nextpoint = deletpoint(booltrap[1][0], booltrap[1][1], booltrap[1][2])
        if nextpoint[1] == 0:
            x = 0
            th = 0
            lock.release()
            return 0
        firstpoint = calpoint(booltrap[1], posx, posy)
        tmpPath = Queue.Queue()
        while (taskPath.qsize() != 0):
            tmpPath.put(taskPath.get())
        taskPath.put(nextpoint)
        while (tmpPath.qsize() != 0):
            taskPath.put(tmpPath.get())
        lock.release()
        goal_x = firstpoint[0].x
        goal_y = firstpoint[0].y
        dis = firstpoint[1]
    goal_distance = sqrt(pow(goal_x - posx, 2) + pow(goal_y - posy, 2))
    if goal_distance <= dis:
        return 0
    else:
        if goal_distance >= (1.3 * dis):
            velocity = followerV
        else:
            velocity = followerV
        angle1 = calangle(goal_x, goal_y) / 57.3
        omega = angle1 * -1
        print "omega 1 : " + str(omega)
        if math.fabs(omega) > max_omega:
            if omega > 0:
                omega = max_omega
            else:
                omega = +max_omega

        print "omega 2 : " + str(omega)
        x = velocity
        th = omega
        time.sleep(0.2)
        if booltrap[0] == 0:
            return -1
        return goal_distance - dis


def reportDeadRearVehicle(uid):
    print "report Dead Rear Vehicle to myself , uid is " + uid
    global robots, leaders, diss, angs, dict, leaderObj, followerPointobj, autoTellThreading, Role
    if Role != Unit.UnitRole.UR_Leader:
        return 0
    for i in range(len(robots)):
        if robots[i] == uid:
            for key1 in range(len(leaders)):
                if leaders[key1] == i:
                    print key1
                    tmpsbh = None
                    tmpuid = None
                    for i1 in range(len(dict)):
                        print dict[i1].uid
                        if dict[i1].uid == robots[key1]:
                            tmpsbh = dict[i1].sbh
                            tmpuid = robots[key1]
                            break
                    tmpinfo = Ground_Unit.GroundUnitInfo(tmpuid, tmpsbh)
                    if leaderObj.obj != None and leaderObj.value != 0:
                        followerobj[i][0].addRearVehicle(tmpinfo)
                    else:
                        followerPointobj[tmpinfo.uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, tmpinfo.sbh), 1]
                        autoTellThreading[uid] = 0
                        followerPointobj[uid][1] = 0
                        thread_1 = threading.Thread(target=sendPoint, args=(followerPointobj[tmpinfo.uid][0], tmpinfo.uid,))
                        thread_1.start()
                    break
            tmp = i
            while (tmp < len(robots) - 1):
                robots[tmp] = robots[tmp + 1]
                diss[tmp] = diss[tmp + 1]
                angs[tmp] = angs[tmp + 1]
                tmp = tmp + 1
            del robots[len(robots) - 1]
            del leaders[len(leaders) - 1]
            del diss[len(diss) - 1]
            del angs[len(angs) - 1]
            break
    for a in range(len(dict)):
        if (dict[a].uid == uid):
            if consoleClosed == 0:
                #tmpService = ilu.ObjectOfSBH(Console.Console, sbh[0])
                tmpService = ilu.ObjectOfSBH(Console.rpc, sbh[0])
                data = Console.Console_UnbindData(uid, "dead")
                #tmpService.sendMsg([Console.Console_Operation.OP_Unbind, data])
                tmpService.sendMsg([_COP('OP_Unbind'), data])
            del dict[a]
            break
    delKey = None
    for key in followerobj:
        if (cmp(key, uid) == 0) and (followerobj[key][1] != 0):
            delKey = key
            break
    if delKey != None:
        followerobj[delKey][1] = 0
    print "report Dead Rear Vehicle to myself end , uid is " + uid
    return 1


def sendPoint(obj, uid):
    global autoTellThreading, goal_x, goal_y, posx, posy, selfuid, vehicle_radius
    autoTellThreading[uid] = 1
    i = 0
    print "start send point to " + uid
    while (autoTellThreading[uid] == 1):
        pose = Ground_Unit.Pose2D(posx, posy, 0)
        speed = Ground_Unit.Speed2D(0, 0, 0, 0)
        info = Ground_Unit.GroundUnitInfo(selfuid, Role, speed, pose, vehicle_radius)
        try:
            time.sleep(0.2)
            print "begin to send info to rear Vehicles"

            obj.setTaskPoint(pose)  # 发送位置点
            print "start send point to " + obj.getID()

        except:
            autoTellThreading[uid] = 0
            global leaderObj
            if leaderObj.obj != None and leaderObj.value != 0:
                print "report someone dead"
                po = Ground_Unit.Point2D(posx, posy)
                trap = Ground_Unit.TrapPoint2D(po, 0)
                leaderObj.obj.reportDeadVehicle(uid, "dead")
            else:
                reportDeadRearVehicle(uid)
    print "end send point to" + uid


def control(delay):
    while (1):
        twist = Twist()
        twist.linear.x = x * speed; twist.linear.y = y * speed; twist.linear.z = z * speed
        twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = th * turn
        pub.publish(twist)
        time.sleep(delay)


def setAleader(uid, sbh_):
    print "start set a leader, sbh is" + sbh_
    global consoleClosed, currentMode, robots, leaders, diss, angs, traplist
    if consoleClosed == 1:
        tmpService = ilu.ObjectOfSBH(Ground_Unit.rpc, sbh_)
        tmpService.setRole(Unit.UnitRole.UR_Follower, "hahahah")
        tmpService.setALeader(theObject.IluSBH())
        tmpService.setMode(currentMode)
        for item in traplist:
            po = Ground_Unit.Point2D(item[0], item[1])
            trap = Ground_Unit.TrapPoint2D(po, item[2])
            tmpService.setTrapPoint(trap)
    if len(robots) > 0:
        robots = robots + [uid]
        leaders = leaders + [max(len(leaders) - 1, 0)]
        diss = diss + [1]
        angs = angs + [0]
        if len(robots) == 2:
            print "num is 2"
            global followerPointobj
            tmpinfo = Ground_Unit.GroundUnitInfo(uid, sbh_)
            followerPointobj[uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, sbh_), 1]
            thread_1 = threading.Thread(target=sendPoint, args=(followerPointobj[uid][0], uid,))
            thread_1.start()
            followerPointobj[uid][0].setRearVehicles([], 1, 0)
        else:
            print "num > 2"
            tmpuid = robots[len(robots) - 2]
            global followerobj
            tmpinfo = Ground_Unit.GroundUnitInfo(uid, sbh_)
            followerobj[tmpuid][0].addRearVehicle(tmpinfo)
            followerobj[uid][0].setRearVehicles([], 1, 0)
    print "end set a leader, sbh is" + sbh_


def takePhoto(delay):
    return


class consoleService(Console__skel.rpc):
    def __init__(self, server=None, ih=None):
        self.IluServer = server
        self.IluInstHandle = ih

    def getCosNamingInfo(self):
        print "get CosNaming info"
        global dict
        return dict
        print "get CosNaming info end"

    def setCosNamingInfo(self, infoSeq):
        print "set CosNaming info"
        global dict
        dict = infoSeq
        for i in range(len(dict)):
            print dict[i].uid
        print "set CosNaming info end"
        return 1

    def bind(self, uid, sbh_):
        print "************bind start*********************\n"
        global Role, consoleClosed, selfuid, theObject, followerobj, dict
        if Role != Unit.UnitRole.UR_Leader:
            return 0
        if consoleClosed == 0:
            print "console is working !!!!!!!!!!!!!!!!"
            print consoleClosed
            n = Console.Console_CosInfoNode(uid, sbh_)
            #theService.sendMsg([Console.Console_Operation.OP_Bind, n])
            theService.sendMsg([_COP('OP_Bind'), n])
        if Role == Unit.UnitRole.UR_Leader:
            thread.start_new_thread(setAleader, (uid, sbh_,))
        tmp = Console.Console_CosInfoNode(uid, sbh_)
        dict = dict + [tmp]
        print "************bind" + uid + " end*********************\n"
        return 1

    def unbind(self, uid, details):
        global dict
        global Role, consoleClosed, selfuid, theObject
        if consoleClosed == 0:
            #tmpService = ilu.ObjectOfSBH(Console.Console, sbh[0])
            tmpService = ilu.ObjectOfSBH(Console.rpc, sbh[0])
            data = Console.Console_UnbindData(uid, "dead")
            #tmpService.sendMsg([Console.Console_Operation.OP_Unbind, data])
            tmpService.sendMsg([_COP('OP_Unbind'), data])
        for i in range(len(dict)):
            if (dict[i].uid == uid):
                print "***********unbund " + uid + "***************\n"
                del dict[i]
                return 1
        return 0

    def sendMsg(self, m):
        global dict, Role, consoleClosed
        #if m[0] == Console.Console_Operation.OP_Bind:
        if m[0] == _COP('OP_Bind'):
            tmp = Console.Console_CosInfoNode(m[1].uid, m[1].sbh)
            print "***********send msg bind " + m[1].uid + "***************\n"
            if Role == Unit.UnitRole.UR_Leader:
                thread.start_new_thread(setAleader, (m[1].uid, m[1].sbh,))
            dict = dict + [tmp]
        #if m[0] == Console.Console_Operation.OP_Unbind:
        if m[0] == _COP('OP_Unbind'):
            for i in range(len(dict)):
                if (dict[i].uid == m[1]):
                    del dict[i]
                    print "***********send msg unbind " + m[1].uid + "***************\n"
        if m[0] == _COP('OP_Opened'):
        #if m[0] == Console.Console_Operation.OP_Opened:
            consoleClosed = 0
        if m[0] == _COP('OP_Closed'):
        #if m[0] == Console.Console_Operation.OP_Closed:
            consoleClosed = 1
        #if m[0] == Console.Console_Operation.OP_SetCosInfo:
        if m[0] == _COP('OP_SetCosInfo'):
            dict = m[1]
        #if m[0] == Console.Console_Operation.OP_ReportTrap:
        if m[0] ==  _COP('OP_ReportTrap'):
            return 0
        #if m[0] == Console.Console_Operation.OP_AddTrap:
        if m[0] == _COP('OP_AddTrap'):
            return 0
        return 1


def FAction(obj, action):
    print "[IMITATE] FAction called"
    obj.sendMoveAction(action)


def consoleinit():
    global theServer
    global ConsoleObject
    ConsoleObject = consoleService(theServer, 'Cosnaming')
    print "the Cosnaming's sbh is", ConsoleObject.IluSBH()


def goTurnSpeed(action):
    print "[IMITATE] goTurnSpeed called"
    global th
    a = th
    th = ((action[1].speed * 3) / 3.3)
    kind = action[0]
    if kind == _MA('MA_TurnRight'):
    #global followerobj
    #if action[0] == Ground_Unit.MoveActionType.MA_TurnRight:
    #if action[0] == Unit.MoveActionType.MA_TurnRight:
        th = -th
    print "**********goTurnSpeed th=" + str(th) + "*******************\n"
    global currentMode
    if currentMode == Unit.UnitMode.UM_Imitate:
        print "currentMode == Imitate"
        for key in followerobj:
            if followerobj[key][1] != 0:
                print followerobj[key][1]
                print "*************tell " + key + " goTurnSpeed*****************"
                thread_1 = threading.Thread(target=FAction, args=(followerobj[key][0], action,))
                thread_1.start()
    if action[1].duration.keep == 0:
        time.sleep(action[1].duration.ft_s + (float(action[1].duration.ft_t) / 1000.0))
        th = a


def goXBySpeed(action):
    print "[IMITATE] goXBySpeed called"
    global x
    a = x
    x = action[1].speed
    kind = action[0]
    global followerobj
    #if action[0] == Ground_Unit.MoveActionType.MA_GoBackward:
    #if action[0] == Unit.MoveActionType.MA_GoBackward:
    if kind == _MA('MA_GoBackward'):
        x = 0 - x
    print "**********goXBySpeed x=" + str(x) + "*******************\n"
    global currentMode
    if currentMode == Unit.UnitMode.UM_Imitate:
        print "currentMode == Imitate"
        for key in followerobj:
            if followerobj[key][1] != 0:
                print followerobj[key][1]
                print "*************tell " + key + " goXBySpeed*****************"
                thread_1 = threading.Thread(target=FAction, args=(followerobj[key][0], action,))
                thread_1.start()
    if action[1].duration.keep == 0:
        time.sleep(action[1].duration.ft_s + (float(action[1].duration.ft_t) / 1000.0))
        x = a


# ---- 关键：继承 Ground_Unit__skel.rpc（不是 Ground_Unit） ----
class realService(Ground_Unit__skel.rpc):
    def __init__(self, server=None, ih=None):
        self.IluServer = server
        self.IluInstHandle = ih

    def startPhotoStream(self, frequency):
        return 1

    def stopPhotoStream(self):
        return 1

    def getID(self):
        return selfuid

    def getCurrentSpeed(self):
        global x, th, current_yaw
        CurrentSpeed = Ground_Unit.Speed2D(x, th, x * cos(current_yaw), x * sin(current_yaw))
        return CurrentSpeed

    def getCurrentPose(self):
        global posx, posy, angle
        currentPose = Ground_Unit.Pose2D(posx, posy, angle)
        return currentPose

    def getCurrentInfo(self):
        global selfuid, Role, x, th, posx, posy, angle, vehicle_radius
        speed = Ground_Unit.Speed2D(x, th, 0, 0)
        pose = Ground_Unit.Pose2D(posx, posy, angle)
        return Ground_Unit.GroundUnitInfo(selfuid, Role, speed, pose, vehicle_radius)

    def getCosNamingSBH(self):
        global ConsoleObject
        return ConsoleObject.IluSBH()

    def getFrontUnitInfo(self):
        global FrontUnitInfo
        tmpInfo = Ground_Unit.GroundUnitInfo(FrontUnitInfo.uid, FrontUnitInfo.sbh)
        return tmpInfo

    def setMinorMode(self, minorMode):
        global currentMinorMode, lock, Role, followerV
        print "setMinorMode"
        if Role == Unit.UnitRole.UR_Leader:
            return 1
        if (minorMode == Unit.UnitMinorMode.UMM_FW_Object) and (currentMinorMode == Unit.UnitMinorMode.UMM_FW_Track):
            global taskPath
            point = [Ground_Unit.Point2D(0, 0), 0.3]
            lock.acquire()
            while (taskPath.qsize() != 0):
                _ = taskPath.get()
            taskPath.put(point)
            lock.release()
        currentMinorMode = minorMode
        if currentMinorMode == Unit.UnitMinorMode.UMM_FW_Object:
            followerV = 0.14
        else:
            followerV = 0.18
        return 1

    def unsetFollower(self):
        print ("unsetFollower")
        return 1

    def setFollower(self,ui):
        uid = ui.uid
        followerSBH = ui.sbh
        print "[IMITATE] setFollower"
        print "[setFollower] 参数: uid=" + str(uid) + ", followerSBH=" + str(followerSBH)
        global leaderObj
        global selfuid, Role
        if leaderObj.obj != None and leaderObj.value != 0 and leaderObj.obj.IluSBH() == followerSBH:
           leaderObj.obj.unregisterFollower(selfuid)
           print "[setFollower] unregister from " + leaderObj.obj.getID()
           leaderObj.value = 0
           if Role == Unit.UnitRole.UR_Follower:
               Role = Unit.UnitRole.UR_None
        global followerobj
        followerobj[uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, followerSBH), 1]
        print "[setFollower] 成功！followerobj[" + str(uid) + "] 已存储"

        print ("setFollowerdone")
        return 1

    def takePicture(self, time_, procedureStartTime):
        return 1
    def sendMoveAction(self, action):
        print "[IMITATE] sendMoveAction called"
        _ma_debug_once()  # 打一次可用枚举，帮你确认 stub 里到底导出了哪些名字

        kind = action[0]

        if kind in (_MA('MA_GoAhead'), _MA('MA_GoBackward')):
            goXBySpeed(action)

        elif kind in (_MA('MA_TurnLeft'), _MA('MA_TurnRight')):
            goTurnSpeed(action)

        elif kind == _MA('MA_Stop'):
            global x, th, currentMode
            x = th = 0
            print "**********stopVehicle*******************"
            if currentMode == Unit.UnitMode.UM_Imitate:
                print "currentMode == Imitate"
                for key in followerobj:
                    if followerobj[key][1] != 0:
                        print followerobj[key][1]
                        thread_1 = threading.Thread(target=FAction, args=(followerobj[key][0], action,))
                        thread_1.start()
        # 保持你原来的停留时间逻辑
            if getattr(action[1], 'keep', 0) == 0:
                time.sleep(action[1].ft_s + (float(action[1].ft_t) / 1000.0))

        else:
        # 没识别出来的动作，给出提示但别崩
            print "[WARN] Unknown action kind:", kind

        return 1

    #def sendMoveAction(self, action):
        #if action[0] == Ground_Unit.MoveActionType.MA_GoAhead or action[0] == Ground_Unit.MoveActionType.MA_GoBackward:
            #goXBySpeed(action)
        #if action[0] == Ground_Unit.MoveActionType.MA_TurnLeft or action[0] == Ground_Unit.MoveActionType.MA_TurnRight:
            #goTurnSpeed(action)
       # if action[0] == Ground_Unit.MoveActionType.MA_Stop:
        #if action[0] == Unit.MoveActionType.MA_GoAhead or action[0] == Unit.MoveActionType.MA_GoBackward:
            #goXBySpeed(action)
       # if action[0] == Unit.MoveActionType.MA_TurnLeft or action[0] == Unit.MoveActionType.MA_TurnRight:
            #goTurnSpeed(action)
        #if action[0] == Unit.MoveActionType.MA_Stop:
           # global x, th
          #  x = th = 0
           # print "**********stopVegicle*******************\n"
          #  global currentMode
           # if currentMode == Unit.UnitMode.UM_Imitate:
               # for key in followerobj:
                   # if followerobj[key][1] != 0:
                       # print "*************tell " + key + " stop*****************"
                       # thread_1 = threading.Thread(target=FAction, args=(followerobj[key][0], action,))
                        #thread_1.start()
            #if action[1].keep == 0:
                #time.sleep(action[1].ft_s + (float(action[1].ft_t) / 1000.0))
        #return 1

    def setTrapPoint(self, trap):
        print "get trap info"
        global traplist
        traplist.append([trap.point.x, trap.point.y, trap.radius])
        return 1

    def setALeader(self, leaderSBH):
        print "start being set a leader sbh is " + leaderSBH
        print "[IMITATE] setALeader big xie"
        global leaderObj
        global theObject, selfuid
        if leaderObj.obj != None and leaderObj.value != 0:
            print "[set a Leader] unregister from " + leaderObj.obj.getID()
            leaderObj.obj.unregisterFollower(selfuid)
            leaderObj.value = 0
        tmp = ilu.ObjectOfSBH(Ground_Unit.rpc, leaderSBH)
        print "wil going set follower"
        follower_info = Unit.UnitInfo(selfuid, theObject.IluSBH())
        print follower_info
        tmp.setFollower(follower_info)
#        tmp.registerFollower(selfuid, theObject.IluSBH())
     
        print "[set a Leader]register to " + tmp.getID()
        leaderObj.obj = tmp
        leaderObj.value = 1
        print "end being set a leader sbh is " + leaderSBH
        return 1

    def clearMode(self):
        print "clear mode"
        global currentMode, currentMinorMode, autoPathThreading, flash, robots, leaders, diss, angs
        autoPathThreading = 0
        flash = 1
        robots = []
        leaders = []
        diss = []
        angs = []
        if currentMode == Unit.UnitMode.UM_None:
            currentMode = Unit.UnitMode.UM_None
            return
        if currentMode == Unit.UnitMode.UM_Imitate:
            currentMode = Unit.UnitMode.UM_None
            return
        if currentMode == Unit.UnitMode.UM_Follow:
            currentMinorMode = Unit.UnitMinorMode.UMM_None
            currentMode = Unit.UnitMode.UM_None
            global followerPointobj
            for key in followerPointobj:
                global autoTellThreading
                autoTellThreading[key] = 0
                followerPointobj[key][1] = 0
            return
        return

    def clearmessage(self):
        print "clear message"
        self.clearMode()
        global Role
        global leaderObj, selfuid
        if leaderObj.obj != None and leaderObj.value != 0:
            print "[clear] unregister from " + leaderObj.obj.getID()
            leaderObj.obj.unregisterFollower(selfuid)
            leaderObj.value = 1

    def setRole(self, role, consoleSBH):
        self.clearmessage()
        global Role
        if role == Unit.UnitRole.UR_Leader:
            print "change Service"
            print role
            global theService
           # theService = ilu.ObjectOfSBH(Console.Console, consoleSBH)
            theService = ilu.ObjectOfSBH(Console.rpc, consoleSBH)  # Console 用 Console.Console
        Role = role
        return 1

    def setMode(self, mode):
        print "set mode"
        self.clearMode()
        global currentMode, currentMinorMode
        if currentMode == mode:
            return 0
        currentMode = mode
        if currentMode == Unit.UnitMode.UM_Follow:
            currentMinorMode = Unit.UnitMinorMode.UMM_FW_Object
        return 1

    def reportTrap(self, trap):
        global dict, traplist, consoleClosed, theService, Role
        if Role != Unit.UnitRole.UR_Leader:
            print "not leader"
            return 0
        if consoleClosed == 0:
            print "keep in touch with console"
            #theService.sendMsg([Console.Console_Operation.OP_AddTrap, trap])
            theService.sendMsg([_COP('OP_AddTrap'), trap])
        print "report trap"
        traplist.append([trap.point.x, trap.point.y, trap.radius])
        for key in followerobj:
            if followerobj[key][1] != 0:
                followerobj[key][0].setTrapPoint(trap)
        return 1

    def clearTraps(self):
        global traplist
        traplist = []
        return 1

    def getTraps(self):
        global traplist
        print "getTraps"
        tmp = []
        for item in traplist:
            po = Ground_Unit.Point2D(item[0], item[1])
            trap = Ground_Unit.TrapPoint2D(po, item[2])
            tmp.append(trap)
        return tmp

    def setTrack(self, path):
        global taskPath, safeDistance, lock
        lock.acquire()
        taskPath.queue.clear()
        for item in path:
            taskPath.put([item, safeDistance])
        lock.release()
        return 1

    def registerFollower(self, uid, followerSBH):
        print "start reg "
        global leaderObj
        global selfuid, Role
        if leaderObj.obj != None and leaderObj.value != 0 and leaderObj.obj.IluSBH() == followerSBH:
            leaderObj.obj.unregisterFollower(selfuid)
            print "[registerFollower] unregister from " + leaderObj.obj.getID()
            leaderObj.value = 0
            if Role == Unit.UnitRole.UR_Follower:
                Role = Unit.UnitRole.UR_None
        global followerobj
        followerobj[uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, followerSBH), 1]
        print "registerFollower:" + uid
        return 1

    def unregisterFollower(self, uid):
        print "[IMITATE] unregisterFollower"
        global followerobj
        delKey = None
        for key in followerobj:
            if (cmp(key, uid) == 0) and (followerobj[key][1] != 0):
                delKey = key
                break
        if delKey != None:
            followerobj[delKey][1] = 0
            print "unregisterFollower:" + uid
        return 1
        # 兼容 stub 调用的简写方法名：sendMoveActionSeq(actions, times)
#gaiguo
    def sendMoveActionSeq(self, actions, times):
        try:
            # 如果你已经实现了 sendMoveActionSequence，就直接复用
            return self.sendMoveActionSequence(actions, times)
        except AttributeError:
            # 兜底：和 sendMoveActionSequence 做同样的事
            thread.start_new_thread(Demo, (self, actions, times))
            return 1
#daozhe

    def sendMoveActionSequence(self, actionSeq, times):
        thread.start_new_thread(Demo, (self, actionSeq, times))
        return 1

    def sendVehicleInfo(self, info):
        print "get vehicle info"
        global currentMode, currentMinorMode, taskPath, flash, safeDistance, lock, autoPathThreading
        lock.acquire()
        if currentMode != Unit.UnitMode.UM_Follow:
            print "not follow mode"
            lock.release()
            return 0
        if currentMinorMode == Unit.UnitMinorMode.UMM_FW_Object:
            taskPath.queue.clear()
            taskPath.put([info.pose, safeDistance])
            print "目标跟踪已经收到目标点"
            flash = 1
        if currentMinorMode == Unit.UnitMinorMode.UMM_FW_Track:
            taskPath.put([info.pose, safeDistance])
        if autoPathThreading == 0:
            thread.start_new_thread(followPath, ())
        lock.release()
        return 1

    def setRearVehicles(self, rears, distance, angle_):
        global currentMode
        print "get rear vehicles"
        if currentMode != Unit.UnitMode.UM_Follow:
            print "not follow mode"
            return 0
        global followerPointobj
        for item in rears:
            followerPointobj[item.uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, item.sbh), 1]
            print "后车sbh 是 " + item.sbh
            print "-------------------"
            thread.start_new_thread(sendPoint, (ilu.ObjectOfSBH(Ground_Unit.rpc, item.sbh), item.uid,))
        global Role, safeDistance
        if Role == Unit.UnitRole.UR_Leader:
            safeDistance = 0.3
        else:
            safeDistance = distance

        return 1

    def addRearVehicle(self, rearInfo):
        print "get add rear vehicle"
        print "[IMITATE] addRearVehicle"
        global followerPointobj
        followerPointobj[rearInfo.uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, rearInfo.sbh), 1]
        thread_1 = threading.Thread(target=sendPoint, args=(followerPointobj[rearInfo.uid][0], rearInfo.uid,))
        thread_1.start()
        return 1

    def deleteRearVehicle(self, uid):
        global followerPointobj, autoTellThreading
        autoTellThreading[uid] = 0
        followerPointobj[uid][1] = 0
        return 1

    def setFormation(self, form):
        print "get formation"
        global robots, leaders, diss, angs
        for item in form.robot_ids:
            robots = robots + [item]
        for item in form.leader_ids:
            leaders = leaders + [item]
        for item in form.distances:
            diss = diss + [item]
        for item in form.angles:
            angs = angs + [item]
        return 1

    def setTaskPoint(self, point):
        global goal_x, goal_y, taskPath, flash, safeDistance, lock, autoPathThreading
        goal_x = point.x
        goal_y = point.y
        lock.acquire()
        taskPath.queue.clear()
        taskPath.put([point, safeDistance])
        flash = 1
        print "get TaskPoint :" + str(goal_x) + "," + str(goal_y)
        if autoPathThreading == 0:
            thread.start_new_thread(followPath, ())
        lock.release()
        return 1

    def setTaskPath(self, path):
        global taskPath, flash, safeDistance, lock, autoPathThreading
        print "get taskpath"
        lock.acquire()
        taskPath.queue.clear()
        for item in path:
            taskPath.put([item, safeDistance])
        flash = 1
        lock.release()
        if autoPathThreading == 0:
            thread.start_new_thread(followPath, ())
        return 1

    def shutDown(self):
        global x, th, loopvar
        x = 0
        th = 0
        time.sleep(0.5)
        ilu.ExitMainLoop(loopvar)
        return 1

    def reportDeadVehicle(self, uid, details):
        global robots, leaders, diss, angs, dict, leaderObj, followerPointobj, Role
        if Role != Unit.UnitRole.UR_Leader:
            return 0
        print "get dead rear vehicle uid is " + uid
        for i in range(len(robots)):
            if robots[i] == uid:
                if robots[i - 1] == selfuid:
                    global autoTellThreading
                    autoTellThreading[uid] = 0
                    followerPointobj[uid][1] = 0
                else:
                    followerobj[robots[i - 1]][0].deleteRearVehicle(uid)
                time.sleep(1)
                for key1 in range(len(leaders)):
                    if leaders[key1] == i:
                        tmpsbh = None
                        tmpuid = None
                        for i1 in range(len(dict)):
                            if dict[i1].uid == robots[key1]:
                                tmpsbh = dict[i1].sbh
                                tmpuid = robots[key1]
                                break
                        print tmpsbh
                        tmpinfo = Ground_Unit.GroundUnitInfo(tmpuid, tmpsbh)
                        if robots[i - 1] == selfuid:
                            followerPointobj[tmpinfo.uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, tmpinfo.sbh), 1]
                            thread_1 = threading.Thread(target=sendPoint, args=(followerPointobj[tmpinfo.uid][0], tmpinfo.uid))
                            thread_1.start()
                        else:
                            followerobj[robots[i - 1]][0].addRearVehicle(tmpinfo)

                        break
                tmp = i
                while (tmp < len(robots) - 1):
                    robots[tmp] = robots[tmp + 1]
                    diss[tmp] = diss[tmp + 1]
                    angs[tmp] = angs[tmp + 1]
                    tmp = tmp + 1
                del robots[len(robots) - 1]
                del leaders[len(leaders) - 1]
                del diss[len(diss) - 1]
                del angs[len(angs) - 1]
                break
        for a in range(len(dict)):
            if (dict[a].uid == uid):
                print "***********unbind " + uid + "***************\n"
                if consoleClosed == 0:
                    #tmpService = ilu.ObjectOfSBH(Console.Console, sbh[0])
                    tmpService = ilu.ObjectOfSBH(Console.rpc, sbh[0])
                    data = Console.Console_UnbindData(uid, "dead")
                    tmpService.sendMsg([_COP('OP_Unbind'), data])
                    #tmpService.sendMsg([Console.Console_Operation.OP_Unbind, data])
                del dict[a]
                break
        delKey = None
        for key in followerobj:
            if (cmp(key, uid) == 0) and (followerobj[key][1] != 0):
                delKey = key
                break
        if delKey != None:
            followerobj[delKey][1] = 0
            print "unregisterFollower:" + uid
        print "end get dead rear vehicle uid is " + uid
        print details

        return 1


def Demo(obj, commands, times):
    print "start demo"
    for i in range(times):
        for item in commands:
            obj.sendMoveAction(item)
    print "end demo"


def followPath():
    print "start followpath"
    global autoPathThreading, taskPath, flash, x, th
    autoPathThreading = 1
    while (autoPathThreading):
        lock.acquire()
        if (taskPath.qsize() != 0):
            tmppoint = taskPath.get()
            lock.release()
            tmpx = tmppoint[0].x
            tmpy = tmppoint[0].y
            flash = 0
            gotoPoint(tmpx, tmpy, tmppoint[1])
        else:
            lock.release()
            time.sleep(0.1)

    autoPathThreading = 0
    print "end followpath"


def gotoPoint(x1, y1, dis):
    global flash, leaderObj, posx, posy, angle, x, th, autoPathThreading, currentMode, count_right, count_wrong, old, lock
    print "start gotoPoint"
    i = 1
    while (i != 0 and flash == 0):
        i = towardGoal(x1, y1, dis)
        if i != 0:
            if staticnow == 1:
                count_wrong = count_wrong + 1
            else:
                if i <= old:
                    count_right = count_right + 1
                else:
                    count_wrong = count_wrong + 1
            old = i
            if count_wrong > (count_right + 80):
                print "#####################wrong!!!!!############################"
                if Role == Unit.UnitRole.UR_Leader:
                    theService.unbind(selfuid, "cannot go to destination as leader")
                    po = Ground_Unit.Point2D(posx, posy)
                    trap = Ground_Unit.TrapPoint2D(po, selfradius)
                    #theService.sendMsg([Console.Console_Operation.OP_ReportTrap, trap])
                    theService.sendMsg([_COP('OP_ReportTrap'), trap])
                    autoPathThreading = 0
                    ilu.ExitMainLoop(loopvar)
                    break
                if Role == Unit.UnitRole.UR_Follower:
                    for key in autoTellThreading:
                        autoTellThreading[key] = 0
                    currentMode = Unit.UnitMode.UM_None
                    time.sleep(0.5)
                    tmp = []
                    lock.acquire()
                    while (taskPath.qsize() != 0):
                        tmp.append(taskPath.get()[0])
                    lock.release()
                    for key in followerPointobj:
                        print "setTrack"
                        followerPointobj[key][0].setTrack(tmp)
                    po = Ground_Unit.Point2D(posx, posy)
                    trap = Ground_Unit.TrapPoint2D(po, selfradius)
                    leaderObj.obj.reportDeadVehicle(selfuid, "cannot go to destination as follower")
                    autoPathThreading = 0
                    leaderObj.obj.reportTrap(trap)
                    ilu.ExitMainLoop(loopvar)
                    break
                else:
                    theService.unbind(selfuid, "cannot go to destination")
                    po = Ground_Unit.Point2D(posx, posy)
                    trap = Ground_Unit.TrapPoint2D(po, selfradius)
                    theService.sendMsg([_COP('OP_ReportTrap'), trap])
                    #theService.sendMsg([Console.Console_Operation.OP_ReportTrap, trap])
                    autoPathThreading = 0
                    ilu.ExitMainLoop(loopvar)
                    break
            if count_right > (count_wrong + 5):
                count_right = 0
                count_wrong = 0
        else:
            count_right = count_right + 1
        if i == -1:
            break
    x = 0
    th = 0


def static():
    right = 0
    wrong = 0
    global posx, poxy, staticnow
    posx_old = 0
    posy_old = 0
    while (1):
        if ((abs(posx - posx_old) + abs(posy - posy_old)) < 0.06):
            wrong = wrong + 1
        else:
            right = right + 1
        if wrong > 3:
            staticnow = 1
        if right > 3:
            staticnow = 0
            right = 0
            wrong = 0
        posx_old = posx
        posy_old = posy
        time.sleep(1)


def checktrap(x_, y_):
    global posx, posy, traplist, selfradius
    for item in traplist:
        safedistance = item[2] + 0.2
        trapdist = sqrt(pow(item[0] - posx, 2) + pow(item[1] - posy, 2))
        if trapdist < safedistance:
            return [0, item]
            break
    return [1, ]


def init():
    try:
        global theServer
        global theObject, theService
        #self_ip = rospy.get_param('/ground_vehicle/selfIP')
       # print("DEBUG selfIP param =", self_ip)
        #theServer = ilu.CreateServer('rikirobot' + rospy.get_param('ground_vehicle/id'), ("tcp_192.168.3.60" + "_9995",), "iiop")
        self_ip = rospy.get_param('/ground_vehicle/selfIP')  # e.g. "tcp_172.20.10.3_5000"
        print("DEBUG selfIP param =", self_ip)

        # 统一用 launch 里的 selfIP，强制让服务在这个 IP:PORT 上监听，并且 SBH 写这个地址
        server_id = 'rikirobot4'   # 与日志里期望的 "rikirobot2/vehicle" 对齐
        theServer = ilu.CreateServer(server_id, (self_ip,), "iiop")


        theObject = realService(theServer, 'vehicle')
        print "the sbh is", theObject.IluSBH()
        thread.start_new_thread(static, ())

#gaide
        i = 0
        for item in sbh:
            print("[TRY] console SBH:", item)

            if not _preflight_tcp(item):
                continue

            try:
                #theService = ilu.ObjectOfSBH(Console.Console, item)
                theService = ilu.ObjectOfSBH(Console.rpc, item)
                print("[INFO] got console object from SBH.")
                rc = _try_bind_console(theService, selfuid, theObject.IluSBH())
                if rc == 1:
                    print("[OK] bind success with console:", item)
                    i = 1
                    break
                else:
                    print("[WARN] bind returned non-1 on:", item)
            except Exception as e:
                print("[ERR] binding to", item, "raised exception:", e)
                traceback.print_exc()

       # if i == 0:
           # print("no one can be bund!")
          #  return 0
       
       # i = 0
        #print "the sbh is", theObject.IluSBH()
        #thread.start_new_thread(static, ())
       # for item in sbh:
            #try:
               # print item
              #  theService = ilu.ObjectOfSBH(Console.Console, item)  # Console 用 Console.Console
              #  i = theService.bind(selfuid, theObject.IluSBH())
                #if i == 1:
                #    i = 1
                #    break

           # except:
             #   pass
       # if i == 0:
         #   print "no one can be bund!"
         #   return 0
        # get_odom_init()
    except:
        t, v, tb = sys.exc_info()
        print 'theService fails with exception <' + str(t) + '> ' + str(v)
        sys.exit(1)
    try:
        t = thread.start_new_thread(control, (0.01,))

        consoleinit()
        thread.start_new_thread(listen, ())
        ilu.RunMainLoop(loopvar)
    except:
        t, v, tb = sys.exc_info()
        print ("Can't create object from SBH <" + str(sbh) + ">; error is", str(t), v)
        sys.exit(1)


def main():
    init()


if __name__ == "__main__":
    main()

