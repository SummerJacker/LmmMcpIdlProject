/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:33:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/monitor.idl" of Wed Jul 16 16:43:00 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Monitor.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class MonitorClasses;

void _Monitor_T_rpc_sendUnitInfo_stub (iluCall _call)
{
    MonitorStatus _status;
    Monitor_T_CompleteUnitInfo unitInfo;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	Monitor_G::Input_CompleteUnitInfo (_call, &unitInfo);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendUnitInfo (&_status, &unitInfo);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Monitor_T_rpc_sendTrapPoint_stub (iluCall _call)
{
    MonitorStatus _status;
    Console_T_TrapPoint tp;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	Console_G::Input_TrapPoint (_call, &tp);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendTrapPoint (&_status, &tp);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Monitor_T_rpc_sendTargetLocation_stub (iluCall _call)
{
    MonitorStatus _status;
    Monitor_T_TargetID fid;
    Ground_Unit_T_Point2D fp;
    ilu_ShortInteger responseTime;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	fid = ilu::InputString(_call, NULL, NULL, 0);
	Ground_Unit_G::Input_Point2D (_call, &fp);
	ilu::InputShortInteger (_call, &responseTime);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendTargetLocation (&_status, fid, &fp, responseTime);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Monitor_T_rpc_foundTarget_stub (iluCall _call)
{
    MonitorStatus _status;
    Monitor_T_TargetID fid;
    Monitor_T_PictureInfo pi;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	fid = ilu::InputString(_call, NULL, NULL, 0);
	Monitor_G::Input_PictureInfo (_call, &pi);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->foundTarget (&_status, fid, &pi);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Monitor_T_rpc_confirmAction_stub (iluCall _call)
{
    MonitorStatus _status;
    Monitor_T_TargetID fid;
    ilu_ShortInteger responseTime;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	fid = ilu::InputString(_call, NULL, NULL, 0);
	ilu::InputShortInteger (_call, &responseTime);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->confirmAction (&_status, fid, responseTime);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Monitor_T_rpc_backHome_stub (iluCall _call)
{
    MonitorStatus _status;
    Unit_T_UnitID uid;
    Monitor_T_BackHomeReason bhr;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	uid = ilu::InputString(_call, NULL, NULL, 0);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  bhr = (Monitor_T_BackHomeReason) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->backHome (&_status, uid, bhr);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Monitor_T_rpc_sendMissionState_stub (iluCall _call)
{
    MonitorStatus _status;
    Monitor_T_TargetID fid;
    Monitor_T_MissionSituation ms;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	fid = ilu::InputString(_call, NULL, NULL, 0);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  ms = (Monitor_T_MissionSituation) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendMissionState (&_status, fid, ms);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Monitor_T_rpc_sendPicture_stub (iluCall _call)
{
    MonitorStatus _status;
    ilu_T_CString pictureName;
    Monitor_T_PictureFlow pic;
    ilu_Integer time;
    ilu_Integer procedureStartTime;
  ilu_Boolean _retvalue;
    Monitor_T_rpc *_realobj;

    _realobj = (Monitor_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Monitor_T_rpc::ILUClassRecord);
	pictureName = ilu::InputString(_call, NULL, NULL, 0);
	pic = Monitor_G::Input_PictureFlow (_call, NULL);
	ilu::InputInteger (_call, &time);
	ilu::InputInteger (_call, &procedureStartTime);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendPicture (&_status, pictureName, pic, time, procedureStartTime);

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
	Monitor_G::SendException (_call, &_status);
    }
faild:
    return;
}

#define MethodRecord_Monitor_T_rpc_sendUnitInfo ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Monitor_T_rpc_sendTrapPoint ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Monitor_T_rpc_sendTargetLocation ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Monitor_T_rpc_foundTarget ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Monitor_T_rpc_confirmAction ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Monitor_T_rpc_backHome ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Monitor_T_rpc_sendMissionState ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Monitor_T_rpc_sendPicture ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 7)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Monitor_InitializeServerClass {

 public:

  _Monitor_InitializeServerClass();
};

#ifndef macintosh
static class _Monitor_InitializeServerClass _Monitor_InitializationInstance;
#endif

void Monitor__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Monitor__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_sendUnitInfo, (ilu_StubProc) _Monitor_T_rpc_sendUnitInfo_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_sendTrapPoint, (ilu_StubProc) _Monitor_T_rpc_sendTrapPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_sendTargetLocation, (ilu_StubProc) _Monitor_T_rpc_sendTargetLocation_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_foundTarget, (ilu_StubProc) _Monitor_T_rpc_foundTarget_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_confirmAction, (ilu_StubProc) _Monitor_T_rpc_confirmAction_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_backHome, (ilu_StubProc) _Monitor_T_rpc_backHome_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_sendMissionState, (ilu_StubProc) _Monitor_T_rpc_sendMissionState_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Monitor_T_rpc_sendPicture, (ilu_StubProc) _Monitor_T_rpc_sendPicture_stub, ilu::CppLangIdx());
}

_Monitor_InitializeServerClass::_Monitor_InitializeServerClass()
{
	Monitor__InitializeServer();
}

