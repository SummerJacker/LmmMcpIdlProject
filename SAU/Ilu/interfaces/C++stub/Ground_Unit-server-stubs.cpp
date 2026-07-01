/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:33:11 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Ground_Unit.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class Ground_UnitClasses;

void _Ground_Unit_T_rpc_getCurrentSpeed_stub (iluCall _call)
{
    Ground_UnitStatus _status;
  Ground_Unit_T_Speed2D * _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCurrentSpeed (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Speed2D (_call, (Ground_Unit_T_Speed2D *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Ground_Unit_G::Output_Speed2D (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Ground_Unit_T_rpc_getCurrentPose_stub (iluCall _call)
{
    Ground_UnitStatus _status;
  Ground_Unit_T_Pose2D * _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCurrentPose (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Pose2D (_call, (Ground_Unit_T_Pose2D *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Ground_Unit_G::Output_Pose2D (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Ground_Unit_T_rpc_getCurrentInfo_stub (iluCall _call)
{
    Ground_UnitStatus _status;
  Ground_Unit_T_GroundUnitInfo * _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCurrentInfo (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Ground_Unit_G::SizeOf_GroundUnitInfo (_call, (Ground_Unit_T_GroundUnitInfo *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Ground_Unit_G::Output_GroundUnitInfo (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Ground_Unit_T_rpc_sendVehicleInfo_stub (iluCall _call)
{
    Ground_UnitStatus _status;
    Ground_Unit_T_GroundUnitInfo info;
  ilu_Boolean _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	Ground_Unit_G::Input_GroundUnitInfo (_call, &info);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendVehicleInfo (&_status, &info);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Ground_Unit_T_rpc_reportTrap_stub (iluCall _call)
{
    Ground_UnitStatus _status;
    Ground_Unit_T_TrapPoint2D trap;
  ilu_Boolean _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	Ground_Unit_G::Input_TrapPoint2D (_call, &trap);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->reportTrap (&_status, &trap);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Ground_Unit_T_rpc_clearTraps_stub (iluCall _call)
{
    Ground_UnitStatus _status;
  ilu_Boolean _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->clearTraps (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Ground_Unit_T_rpc_getTraps_stub (iluCall _call)
{
    Ground_UnitStatus _status;
  Ground_Unit_T_TrapPointSeq _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getTraps (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Ground_Unit_G::SizeOf_TrapPointSeq (_call, (Ground_Unit_T_TrapPointSeq) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Ground_Unit_G::Output_TrapPointSeq (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
	Ground_Unit_G::Free_TrapPointSeq (_retvalue);
faild:
    return;
}

void _Ground_Unit_T_rpc_setTrapPoint_stub (iluCall _call)
{
    Ground_UnitStatus _status;
    Ground_Unit_T_TrapPoint2D trap;
  ilu_Boolean _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	Ground_Unit_G::Input_TrapPoint2D (_call, &trap);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setTrapPoint (&_status, &trap);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Ground_Unit_T_rpc_setTrack_stub (iluCall _call)
{
    Ground_UnitStatus _status;
    Ground_Unit_T_TaskPath track;
  ilu_Boolean _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	track = Ground_Unit_G::Input_TaskPath (_call, NULL);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setTrack (&_status, track);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
	free((char *) track);
faild:
    return;
}

void _Ground_Unit_T_rpc_setTaskPath_stub (iluCall _call)
{
    Ground_UnitStatus _status;
    Ground_Unit_T_TaskPath path;
  ilu_Boolean _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	path = Ground_Unit_G::Input_TaskPath (_call, NULL);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setTaskPath (&_status, path);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
	free((char *) path);
faild:
    return;
}

void _Ground_Unit_T_rpc_setTaskPoint_stub (iluCall _call)
{
    Ground_UnitStatus _status;
    Ground_Unit_T_Point2D point;
  ilu_Boolean _retvalue;
    Ground_Unit_T_rpc *_realobj;

    _realobj = (Ground_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Ground_Unit_T_rpc::ILUClassRecord);
	Ground_Unit_G::Input_Point2D (_call, &point);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setTaskPoint (&_status, &point);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Ground_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

#define MethodRecord_Ground_Unit_T_rpc_getCurrentSpeed ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Ground_Unit_T_rpc_getCurrentPose ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Ground_Unit_T_rpc_getCurrentInfo ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Ground_Unit_T_rpc_sendVehicleInfo ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Ground_Unit_T_rpc_reportTrap ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Ground_Unit_T_rpc_clearTraps ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Ground_Unit_T_rpc_getTraps ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Ground_Unit_T_rpc_setTrapPoint ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Ground_Unit_T_rpc_setTrack ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Ground_Unit_T_rpc_setTaskPath ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Ground_Unit_T_rpc_setTaskPoint ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 10)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Ground_Unit_InitializeServerClass {

 public:

  _Ground_Unit_InitializeServerClass();
};

#ifndef macintosh
static class _Ground_Unit_InitializeServerClass _Ground_Unit_InitializationInstance;
#endif

void Ground_Unit__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Ground_Unit__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_getCurrentSpeed, (ilu_StubProc) _Ground_Unit_T_rpc_getCurrentSpeed_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_getCurrentPose, (ilu_StubProc) _Ground_Unit_T_rpc_getCurrentPose_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_getCurrentInfo, (ilu_StubProc) _Ground_Unit_T_rpc_getCurrentInfo_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_sendVehicleInfo, (ilu_StubProc) _Ground_Unit_T_rpc_sendVehicleInfo_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_reportTrap, (ilu_StubProc) _Ground_Unit_T_rpc_reportTrap_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_clearTraps, (ilu_StubProc) _Ground_Unit_T_rpc_clearTraps_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_getTraps, (ilu_StubProc) _Ground_Unit_T_rpc_getTraps_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_setTrapPoint, (ilu_StubProc) _Ground_Unit_T_rpc_setTrapPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_setTrack, (ilu_StubProc) _Ground_Unit_T_rpc_setTrack_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_setTaskPath, (ilu_StubProc) _Ground_Unit_T_rpc_setTaskPath_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Ground_Unit_T_rpc_setTaskPoint, (ilu_StubProc) _Ground_Unit_T_rpc_setTaskPoint_stub, ilu::CppLangIdx());
}

_Ground_Unit_InitializeServerClass::_Ground_Unit_InitializeServerClass()
{
	Ground_Unit__InitializeServer();
}

