#!/usr/bin/env python
# need to change: 2 GV1 ,rikibot1(serverid),ip
import sys
import socket
import re
import traceback
import math
import time
import threading
import thread
import datetime
import Queue
from collections import deque

# ---- 确保 stub/skeleton 在搜索路径中 ----
sys.path.append('/home/robot/SRIOProject/ROSRobot/PySrc/Build/stubber')
sys.path.append('/home/robot/SRIOProject/ilu/lib')

# ---- 这些模块来自你生成的 stub/skeleton ----
import Ground_Unit__skel, Ground_Unit, Console, Console__skel, Unit, Unit__skel, Air_Unit, Air_Unit__skel, ilu

import roslib; roslib.load_manifest('Ground_Vehicle')
import rospy
import tf
from tf.transformations import euler_from_quaternion
import numpy as np
from geometry_msgs.msg import Twist, Vector3, Point
from robot import Robot
from math import radians, copysign, sqrt, pow, pi, atan2, cos, sin

# ======== Console 操作码适配：兼容 Console.Console_Operation.OP_* / Console.OP_* 两种导出 ========
def _COP(name):
    if hasattr(Console, 'Console_Operation') and hasattr(Console.Console_Operation, name):
        return getattr(Console.Console_Operation, name)
    if hasattr(Console, name):
        return getattr(Console, name)
    return None

# ======== 动作枚举适配，不再直接用 MoveActionType ========
def _MA(name):
    try:
        return getattr(Unit.MoveActionType, name)
    except Exception:
        pass
    if hasattr(Unit, name):
        return getattr(Unit, name)
    try:
        return getattr(Ground_Unit.MoveActionType, name)
    except Exception:
        pass
    if hasattr(Ground_Unit, name):
        return getattr(Ground_Unit, name)
    return None

# ===== 新增：运动控制锁和状态管理 =====
motion_lock = threading.Lock()
current_motion = None
role_change_lock = threading.Lock()  # 新增：角色切换锁

def _stopVehicle():
    """停止车辆运动"""
    global x, th
    with motion_lock:
        x = 0
        th = 0
        print "**********stopVehicle*******************"
        time.sleep(0.1)  # 确保停止命令执行完成

def isRoleChangeValid(new_role):
    """检查角色切换是否有效"""
    global Role, currentMode, leaderObj
    
    if Role == new_role:
        return True, "角色未变化"
        
    if new_role == Unit.UnitRole.UR_Leader and leaderObj.value != 0:
        return False, "当前是跟随者，请先解除领航者绑定"
        
    if Role == Unit.UnitRole.UR_Leader and new_role != Unit.UnitRole.UR_Leader:
        # 检查是否有活跃的跟随者
        active_followers = False
        for key in followerobj:
            if followerobj[key][1] != 0:
                active_followers = True
                break
        if active_followers:
            return False, "当前是领航者且有活跃跟随者，无法切换角色"
    
    return True, "角色切换有效"

def clearFollowers():
    """只清理跟随者相关状态，不清理所有消息"""
    global followerobj, autoTellThreading
    print "清理跟随者状态"
    
    # 停止所有发送位置的线程
    for uid in list(autoTellThreading.keys()):
        autoTellThreading[uid] = 0
    
    # 清理跟随者对象
    followerobj.clear()
    print "跟随者状态清理完成"

# ===== BIND 调试工具 =====
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
    try:
        print "[BIND_DEBUG] TRY bind(uid,sbh):", selfuid, my_sbh
        rc = theService.bind(selfuid, my_sbh)
        print "[BIND_DEBUG] rc(uid,sbh) =", rc
        if rc == 1:
            return 1
    except Exception as e:
        print "[BIND_DEBUG] EXC bind(uid,sbh):", e
        traceback.print_exc()

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

    try:
        if hasattr(Console, "Console_Operation") and hasattr(theService, "sendMsg"):
            print "[BIND_DEBUG] TRY sendMsg(OP_Opened)"
            theService.sendMsg([_COP('OP_Bind'), None])       
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

ep = Robot()
ep.get_robot_ip()
ep.connect()
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
is_leader = False  # 标记是否为领航者（用于模仿模式指令转发）
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
                tmpService = ilu.ObjectOfSBH(Console.rpc, sbh[0])
                data = Console.Console_UnbindData(uid, "dead")
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
    global x, y, z, th, speed, turn, ep
    prev_sent_stop = False
    last_send_time = 0
    send_interval = 1  # 每 0.2 秒最多发一次控制指令

    while True:
        now = time.time()

        twist = Twist()
        twist.linear.x = x * speed
        twist.linear.y = y * speed
        twist.linear.z = z * speed
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = th * turn

        X = x * speed
        Z_turn = -th * turn * 57.3  # 弧度转角度

        if X != 0 or Z_turn != 0:
            if now - last_send_time >= send_interval:
                cmd = 'chassis speed x {} y 0 z {}'.format(X, Z_turn)
                ep.send(cmd)
                last_send_time = now
                prev_sent_stop = False
        else:
            if not prev_sent_stop:
                ep.send('chassis speed x 0 y 0 z 0')
                prev_sent_stop = True

        time.sleep(delay)

def setAleader(uid, sbh_):
    print "start set a leader, sbh is" + sbh_
    global consoleClosed, currentMode, robots, leaders, diss, angs, traplist
    if consoleClosed == 0:
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
        tmp = Console.Console_CosInfoNode(uid,sbh_)
        dict = dict + [tmp]
        
        if Role == Unit.UnitRole.UR_Leader:
            if consoleClosed == 0:
                n = Console.Console_CosInfoNode(uid, sbh_)
                theService.sendMsg([_COP('OP_Bind'), n])
                thread.start_new_thread(setAleader, (uid, sbh_,))
            thread.start_new_thread(setAleader, (uid, sbh_,))
        
        #if Role != Unit.UnitRole.UR_Leader:
        #    return 0
        #if consoleClosed == 0:
         #   n = Console.Console_CosInfoNode(uid, sbh_)
            #theService.sendMsg([Console.Console_Operation.OP_Bind, n])
          #  theService.sendMsg([_COP('OP_Bind'), n])
        #if Role == Unit.UnitRole.UR_Leader:
         #   thread.start_new_thread(setAleader, (uid, sbh_,))
        #tmp = Console.Console_CosInfoNode(uid, sbh_)
        #dict = dict + [tmp]
        print "************bind" + uid + " end*********************\n"
        return 1

    def unbind(self, uid, details):
        global dict
        global Role, consoleClosed, selfuid, theObject
        if consoleClosed == 0:
            tmpService = ilu.ObjectOfSBH(Console.rpc, sbh[0])
            data = Console.Console_UnbindData(uid, "dead")
            tmpService.sendMsg([_COP('OP_Unbind'), data])
        for i in range(len(dict)):
            if (dict[i].uid == uid):
                print "***********unbund " + uid + "***************\n"
                del dict[i]
                return 1
        return 0

    def sendMsg(self, m):
        global dict, Role, consoleClosed
        if m[0] == _COP('OP_Bind'):
            tmp = Console.Console_CosInfoNode(m[1].uid, m[1].sbh)
            print "***********send msg bind " + m[1].uid + "***************\n"
            if Role == Unit.UnitRole.UR_Leader:
                thread.start_new_thread(setAleader, (m[1].uid, m[1].sbh,))
            dict = dict + [tmp]
        if m[0] == _COP('OP_Unbind'):
            for i in range(len(dict)):
                if (dict[i].uid == m[1]):
                    del dict[i]
                    print "***********send msg unbind " + m[1].uid + "***************\n"
        if m[0] == _COP('OP_Opened'):
            consoleClosed = 0
        if m[0] == _COP('OP_Closed'):
            consoleClosed = 1
        if m[0] == _COP('OP_SetCosInfo'):
            dict = m[1]
        if m[0] ==  _COP('OP_ReportTrap'):
            return 0
        if m[0] == _COP('OP_AddTrap'):
            return 0
        return 1

def FAction(obj, action):
    obj.sendMoveAction(action)

def consoleinit():
    global theServer
    global ConsoleObject
    ConsoleObject = consoleService(theServer, 'Cosnaming')
    print "the Cosnaming's sbh is", ConsoleObject.IluSBH()

def goTurnSpeed(action):
    global th
    with motion_lock:
        th = ((action[1].speed * 3) / 3.3)
        kind = action[0]
        if kind == _MA('MA_TurnRight'):
            th = -th
        print "**********goTurnSpeed th=" + str(th) + "*******************\n"

def goXBySpeed(action):
    global x
    with motion_lock:
        x = action[1].speed
        kind = action[0]
        if kind == _MA('MA_GoBackward'):
            x = 0 - x
        print "**********goXBySpeed x=" + str(x) + "*******************\n"

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

    def setFollower(self):
        print ("setFollower")
        return 1

    def takePicture(self, time_, procedureStartTime):
        return 1

    def sendMoveAction(self, action):
        kind = action[0]

        # 1. 先执行自己的动作
        if kind in (_MA('MA_GoAhead'), _MA('MA_GoBackward')):
            goXBySpeed(action)

        elif kind in (_MA('MA_TurnLeft'), _MA('MA_TurnRight')):
            goTurnSpeed(action)

        elif kind == _MA('MA_Stop'):
            _stopVehicle()
        else:
            print "[WARN] Unknown action kind:", kind

        # 2. 如果是模仿模式的Leader，转发给所有Follower
        print "[DEBUG] sendMoveAction - currentMode:", currentMode, "is_leader:", is_leader, "Role:", Role
        print "[DEBUG] followerobj keys:", followerobj.keys()
        
        if currentMode == Unit.UnitMode.UM_Imitate and is_leader:
            print "[DEBUG] 开始转发动作给跟随者，动作类型:", kind
            for key in followerobj:
                if followerobj[key][1] != 0:
                    print "[DEBUG] 转发给:", key
                    thread_1 = threading.Thread(target=FAction, args=(followerobj[key][0], action,))
                    thread_1.start()
                else:
                    print "[DEBUG] 跳过无效跟随者:", key, "状态:", followerobj[key][1]
        else:
            print "[DEBUG] 不满足转发条件 - currentMode:", currentMode, "is_leader:", is_leader

        return 1

    def setTrapPoint(self, trap):
        print "get trap info"
        global traplist
        traplist.append([trap.point.x, trap.point.y, trap.radius])
        return 1

    def setALeader(self, leaderSBH):
        global leaderObj, theObject, selfuid, Role, currentMode, is_leader
        # 使用角色切换锁防止重复调用
        with role_change_lock:
            # 校验：若当前是Leader，禁止绑定其他领队
            if Role == Unit.UnitRole.UR_Leader:
                print "错误：当前是领航者角色，无法注册为其他车辆的跟随者"
                return False
            # 校验：若已绑定其他领队，提示无需重复绑定
            if leaderObj.value != 0:
                print "警告：已绑定领航者%s，无需重复绑定" % leaderObj.obj.getID()
                return True  # 返回True表示已经绑定，不需要重复绑定
            
            print "start being set a leader sbh is " + leaderSBH
            
            # 只有在没有绑定领航者时才进行绑定
            tmp = ilu.ObjectOfSBH(Ground_Unit.rpc, leaderSBH)
            try:
                tmp.registerFollower(selfuid, theObject.IluSBH())
                print "selfuid:",selfuid
                print "theObject.IluSBH:",theObject.IluSBH()
                print "[set a Leader]register to " + tmp.getID()
                leaderObj.obj = tmp
                leaderObj.value = 1
                # 自动切换为跟随模式
                currentMode = Unit.UnitMode.UM_Follow
                currentMinorMode = Unit.UnitMinorMode.UMM_FW_Object
                is_leader = False  # 标记为跟随者
                print "end being set a leader sbh is " + leaderSBH
                return 1
            except Exception as e:
                print "绑定领航者失败:", e
                return 0

    def clearMode(self):
        print "clear mode"
        global currentMode, currentMinorMode, autoPathThreading, flash, robots, leaders, diss, angs, followerPointobj, autoTellThreading, taskPath
        autoPathThreading = 0
        flash = 1
        taskPath.queue.clear()  # 清空路径队列（避免命令堆积）
        # 注意：不清除robots、leaders等编队信息，只清除运动状态
        if currentMode == Unit.UnitMode.UM_Follow:
            currentMinorMode = Unit.UnitMinorMode.UMM_None
        currentMode = Unit.UnitMode.UM_None
        
        # 只停止发送位置，但不解除绑定
        for key in list(autoTellThreading.keys()):
            autoTellThreading[key] = 0
        return   

    def clearmessage(self):
        """全面清理消息状态"""
        print "全面清理消息状态"
        self.clearMode()
        global leaderObj, selfuid
        if leaderObj.obj != None and leaderObj.value != 0:
            try:
                print "解除领航者绑定: " + leaderObj.obj.getID()
                leaderObj.obj.unregisterFollower(selfuid)
            except Exception as e:
                print "解除绑定异常:", e
            leaderObj.value = 0
            leaderObj.obj = None
        return

    def setRole(self, role, consoleSBH):
        global leaderObj, is_leader, Role
        
        # 使用角色切换锁防止重复调用
        with role_change_lock:
            # 检查角色切换是否有效
            valid, message = isRoleChangeValid(role)
            if not valid:
                print "错误：", message
                return False
                
            # 如果角色没有变化，直接返回成功
            if Role == role:
                print "角色未变化，无需设置"
                return True
                
            print "开始设置角色: %s" % role
            
            # 从领航者切换为其他角色时的特殊处理
            if Role == Unit.UnitRole.UR_Leader and role != Unit.UnitRole.UR_Leader:
                # 作为领航者，需要先解除所有跟随者
                clearFollowers()
                print "领航者角色解除，已清理所有跟随者"
            
            # 只有在真正需要清理时才进行全面清理
            if Role != Unit.UnitRole.UR_None:
                self.clearmessage()
            
            global theService
            if role == Unit.UnitRole.UR_Leader:
                print "设置为领航者角色"
                theService = ilu.ObjectOfSBH(Console.rpc, consoleSBH)
                is_leader = True  # 标记为领航者
            else:
                is_leader = False  # 非领航者
            Role = role
            print "角色设置成功: %s" % role
            return 1

    def setMode(self, mode):
        print "set mode to: %s" % mode
        # 如果模式没有变化，直接返回
        if currentMode == mode:
            print "模式未变化，无需设置"
            return 1
            
        # 只有在模式真正变化时才清理
        self.clearMode()
        global currentMode, currentMinorMode
        currentMode = mode
        if currentMode == Unit.UnitMode.UM_Follow:
            currentMinorMode = Unit.UnitMinorMode.UMM_FW_Object
        print "模式设置成功: %s" % mode
        return 1

    def reportTrap(self, trap):
        global dict, traplist, consoleClosed, theService, Role
        if Role != Unit.UnitRole.UR_Leader:
            print "not leader"
            return 0
        if consoleClosed == 0:
            print "keep in touch with console"
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

    def sendMoveActionSeq(self, actions, times):
        try:
            return self.sendMoveActionSequence(actions, times)
        except AttributeError:
            thread.start_new_thread(Demo, (self, actions, times))
            return 1

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
        global currentMode, followerPointobj, Role, safeDistance
        print "get rear vehicles"
        # 修复：领航者模式应为UM_Leader，而非UM_Follow
        if currentMode != Unit.UnitMode.UM_Leader:
            print "not leader mode, cannot add rear vehicles"
            return 0
        for item in rears:
            followerPointobj[item.uid] = [ilu.ObjectOfSBH(Ground_Unit.rpc, item.sbh), 1]
            print "后车sbh 是 " + item.sbh
            print "-------------------"
            thread.start_new_thread(sendPoint, (ilu.ObjectOfSBH(Ground_Unit.rpc, item.sbh), item.uid,))
        safeDistance = 0.3 if Role == Unit.UnitRole.UR_Leader else distance
        return 1     

    def addRearVehicle(self, rearInfo):
        print "get add rear vehicle"
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
        ep.close()
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
                    tmpService = ilu.ObjectOfSBH(Console.rpc, sbh[0])
                    data = Console.Console_UnbindData(uid, "dead")
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
        self_ip = rospy.get_param('/ground_vehicle/selfIP')  # e.g. "tcp_172.20.10.3_5000"
        print("DEBUG selfIP param =", self_ip)

        # 统一用 launch 里的 selfIP，强制让服务在这个 IP:PORT 上监听，并且 SBH 写这个地址
        server_id = 'rikirobot2'   # 与日志里期望的 "rikirobot2/vehicle" 对齐
        theServer = ilu.CreateServer(server_id, (self_ip,), "iiop")

        theObject = realService(theServer, 'vehicle')
        print "the sbh is", theObject.IluSBH()
        thread.start_new_thread(static, ())

        i = 0
        for item in sbh:
            print("[TRY] console SBH:", item)

            if not _preflight_tcp(item):
                continue

            try:
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