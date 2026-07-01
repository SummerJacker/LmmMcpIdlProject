/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:30:56 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Air_Unit.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class Air_UnitClasses;

void _Air_Unit_T_rpc_getCurrentSpeed_stub (iluCall _call)
{
    Air_UnitStatus _status;
  Air_Unit_T_Speed3D * _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCurrentSpeed (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Air_Unit_G::SizeOf_Speed3D (_call, (Air_Unit_T_Speed3D *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Air_Unit_G::Output_Speed3D (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_getCurrentPose_stub (iluCall _call)
{
    Air_UnitStatus _status;
  Air_Unit_T_Pose3D * _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCurrentPose (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Air_Unit_G::SizeOf_Pose3D (_call, (Air_Unit_T_Pose3D *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Air_Unit_G::Output_Pose3D (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_getCurrentInfo_stub (iluCall _call)
{
    Air_UnitStatus _status;
  Air_Unit_T_AirUnitInfo * _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCurrentInfo (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Air_Unit_G::SizeOf_AirUnitInfo (_call, (Air_Unit_T_AirUnitInfo *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Air_Unit_G::Output_AirUnitInfo (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_sendGimbalSpeed_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_GimbalSpeed speed;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	Air_Unit_G::Input_GimbalSpeed (_call, &speed);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendGimbalSpeed (&_status, &speed);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_resetGimbal_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->resetGimbal (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_sendVehicleInfo_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_AirUnitInfo info;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	Air_Unit_G::Input_AirUnitInfo (_call, &info);
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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_reportTrap_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_TrapPoint3D trap;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	Air_Unit_G::Input_TrapPoint3D (_call, &trap);
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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_clearTraps_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_getTraps_stub (iluCall _call)
{
    Air_UnitStatus _status;
  Air_Unit_T_TrapPointSeq _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getTraps (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Air_Unit_G::SizeOf_TrapPointSeq (_call, (Air_Unit_T_TrapPointSeq) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Air_Unit_G::Output_TrapPointSeq (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Air_Unit_G::SendException (_call, &_status);
    }
	Air_Unit_G::Free_TrapPointSeq (_retvalue);
faild:
    return;
}

void _Air_Unit_T_rpc_setTrapPoint_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_TrapPoint3D trap;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	Air_Unit_G::Input_TrapPoint3D (_call, &trap);
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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_setTrack_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_TaskPath track;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	track = Air_Unit_G::Input_TaskPath (_call, NULL);
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
	Air_Unit_G::SendException (_call, &_status);
    }
	free((char *) track);
faild:
    return;
}

void _Air_Unit_T_rpc_setTaskPath_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_TaskPath path;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	path = Air_Unit_G::Input_TaskPath (_call, NULL);
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
	Air_Unit_G::SendException (_call, &_status);
    }
	free((char *) path);
faild:
    return;
}

void _Air_Unit_T_rpc_setTaskPoint_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_Point3D point;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	Air_Unit_G::Input_Point3D (_call, &point);
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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_clearTaskPoint_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->clearTaskPoint (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_obtainCtrlAuthority_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->obtainCtrlAuthority (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_releaseCtrlAuthority_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->releaseCtrlAuthority (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_setActionRole_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_ActionRole ar;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  ar = (Air_Unit_T_ActionRole) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setActionRole (&_status, ar);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_setActionMode_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_ActionMode am;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  am = (Air_Unit_T_ActionMode) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setActionMode (&_status, am);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_setCruiseScope_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Air_Unit_T_Site s;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	Air_Unit_G::Input_Site (_call, &s);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setCruiseScope (&_status, &s);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_sendControlledVehicle_stub (iluCall _call)
{
    Air_UnitStatus _status;
    Unit_T_UnitSBHSeq uss;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	uss = Unit_G::Input_UnitSBHSeq (_call, NULL);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendControlledVehicle (&_status, uss);

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
	Air_Unit_G::SendException (_call, &_status);
    }
	free((char *) uss);
faild:
    return;
}

void _Air_Unit_T_rpc_confirmThrow_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->confirmThrow (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_cancelThrow_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->cancelThrow (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_actionThrow_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->actionThrow (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_confirmFire_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->confirmFire (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_cancelFire_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->cancelFire (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_confirmFireLocation_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->confirmFireLocation (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_cancelFireLocation_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->cancelFireLocation (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_controlVehicleVelocity_stub (iluCall _call)
{
    Air_UnitStatus _status;
    ilu_ShortReal vx;
    ilu_ShortReal vy;
    ilu_ShortReal vz;
    ilu_ShortReal angle;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	ilu::InputShortReal (_call, &vx);
	ilu::InputShortReal (_call, &vy);
	ilu::InputShortReal (_call, &vz);
	ilu::InputShortReal (_call, &angle);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->controlVehicleVelocity (&_status, vx, vy, vz, angle);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_backHome_stub (iluCall _call)
{
    Air_UnitStatus _status;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->backHome (&_status);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Air_Unit_T_rpc_setCruiseSpeed_stub (iluCall _call)
{
    Air_UnitStatus _status;
    ilu_ShortReal cs;
  ilu_Boolean _retvalue;
    Air_Unit_T_rpc *_realobj;

    _realobj = (Air_Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Air_Unit_T_rpc::ILUClassRecord);
	ilu::InputShortReal (_call, &cs);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setCruiseSpeed (&_status, cs);

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
	Air_Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

#define MethodRecord_Air_Unit_T_rpc_getCurrentSpeed ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Air_Unit_T_rpc_getCurrentPose ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Air_Unit_T_rpc_getCurrentInfo ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Air_Unit_T_rpc_sendGimbalSpeed ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Air_Unit_T_rpc_resetGimbal ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Air_Unit_T_rpc_sendVehicleInfo ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Air_Unit_T_rpc_reportTrap ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Air_Unit_T_rpc_clearTraps ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Air_Unit_T_rpc_getTraps ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Air_Unit_T_rpc_setTrapPoint ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Air_Unit_T_rpc_setTrack ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 10)
#define MethodRecord_Air_Unit_T_rpc_setTaskPath ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 11)
#define MethodRecord_Air_Unit_T_rpc_setTaskPoint ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 12)
#define MethodRecord_Air_Unit_T_rpc_clearTaskPoint ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 13)
#define MethodRecord_Air_Unit_T_rpc_obtainCtrlAuthority ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 14)
#define MethodRecord_Air_Unit_T_rpc_releaseCtrlAuthority ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 15)
#define MethodRecord_Air_Unit_T_rpc_setActionRole ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 16)
#define MethodRecord_Air_Unit_T_rpc_setActionMode ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 17)
#define MethodRecord_Air_Unit_T_rpc_setCruiseScope ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 18)
#define MethodRecord_Air_Unit_T_rpc_sendControlledVehicle ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 19)
#define MethodRecord_Air_Unit_T_rpc_confirmThrow ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 20)
#define MethodRecord_Air_Unit_T_rpc_cancelThrow ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 21)
#define MethodRecord_Air_Unit_T_rpc_actionThrow ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 22)
#define MethodRecord_Air_Unit_T_rpc_confirmFire ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 23)
#define MethodRecord_Air_Unit_T_rpc_cancelFire ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 24)
#define MethodRecord_Air_Unit_T_rpc_confirmFireLocation ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 25)
#define MethodRecord_Air_Unit_T_rpc_cancelFireLocation ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 26)
#define MethodRecord_Air_Unit_T_rpc_controlVehicleVelocity ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 27)
#define MethodRecord_Air_Unit_T_rpc_backHome ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 28)
#define MethodRecord_Air_Unit_T_rpc_setCruiseSpeed ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 29)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Air_Unit_InitializeServerClass {

 public:

  _Air_Unit_InitializeServerClass();
};

#ifndef macintosh
static class _Air_Unit_InitializeServerClass _Air_Unit_InitializationInstance;
#endif

void Air_Unit__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Air_Unit__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_getCurrentSpeed, (ilu_StubProc) _Air_Unit_T_rpc_getCurrentSpeed_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_getCurrentPose, (ilu_StubProc) _Air_Unit_T_rpc_getCurrentPose_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_getCurrentInfo, (ilu_StubProc) _Air_Unit_T_rpc_getCurrentInfo_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_sendGimbalSpeed, (ilu_StubProc) _Air_Unit_T_rpc_sendGimbalSpeed_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_resetGimbal, (ilu_StubProc) _Air_Unit_T_rpc_resetGimbal_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_sendVehicleInfo, (ilu_StubProc) _Air_Unit_T_rpc_sendVehicleInfo_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_reportTrap, (ilu_StubProc) _Air_Unit_T_rpc_reportTrap_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_clearTraps, (ilu_StubProc) _Air_Unit_T_rpc_clearTraps_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_getTraps, (ilu_StubProc) _Air_Unit_T_rpc_getTraps_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setTrapPoint, (ilu_StubProc) _Air_Unit_T_rpc_setTrapPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setTrack, (ilu_StubProc) _Air_Unit_T_rpc_setTrack_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setTaskPath, (ilu_StubProc) _Air_Unit_T_rpc_setTaskPath_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setTaskPoint, (ilu_StubProc) _Air_Unit_T_rpc_setTaskPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_clearTaskPoint, (ilu_StubProc) _Air_Unit_T_rpc_clearTaskPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_obtainCtrlAuthority, (ilu_StubProc) _Air_Unit_T_rpc_obtainCtrlAuthority_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_releaseCtrlAuthority, (ilu_StubProc) _Air_Unit_T_rpc_releaseCtrlAuthority_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setActionRole, (ilu_StubProc) _Air_Unit_T_rpc_setActionRole_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setActionMode, (ilu_StubProc) _Air_Unit_T_rpc_setActionMode_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setCruiseScope, (ilu_StubProc) _Air_Unit_T_rpc_setCruiseScope_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_sendControlledVehicle, (ilu_StubProc) _Air_Unit_T_rpc_sendControlledVehicle_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_confirmThrow, (ilu_StubProc) _Air_Unit_T_rpc_confirmThrow_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_cancelThrow, (ilu_StubProc) _Air_Unit_T_rpc_cancelThrow_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_actionThrow, (ilu_StubProc) _Air_Unit_T_rpc_actionThrow_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_confirmFire, (ilu_StubProc) _Air_Unit_T_rpc_confirmFire_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_cancelFire, (ilu_StubProc) _Air_Unit_T_rpc_cancelFire_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_confirmFireLocation, (ilu_StubProc) _Air_Unit_T_rpc_confirmFireLocation_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_cancelFireLocation, (ilu_StubProc) _Air_Unit_T_rpc_cancelFireLocation_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_controlVehicleVelocity, (ilu_StubProc) _Air_Unit_T_rpc_controlVehicleVelocity_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_backHome, (ilu_StubProc) _Air_Unit_T_rpc_backHome_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Air_Unit_T_rpc_setCruiseSpeed, (ilu_StubProc) _Air_Unit_T_rpc_setCruiseSpeed_stub, ilu::CppLangIdx());
}

_Air_Unit_InitializeServerClass::_Air_Unit_InitializeServerClass()
{
	Air_Unit__InitializeServer();
}

