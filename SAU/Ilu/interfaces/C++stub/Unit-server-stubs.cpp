/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:31:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Unit.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class UnitClasses;

void _Unit_T_rpc_getID_stub (iluCall _call)
{
    UnitStatus _status;
  Unit_T_UnitID _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getID (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfString(_call, _retvalue, strlen(_retvalue), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputString (_call, _retvalue, strlen(_retvalue), 0))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_getCosNamingSBH_stub (iluCall _call)
{
    UnitStatus _status;
  Unit_T_UnitSBH _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCosNamingSBH (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfString(_call, _retvalue, strlen(_retvalue), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputString (_call, _retvalue, strlen(_retvalue), 0))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_getFrontUnitInfo_stub (iluCall _call)
{
    UnitStatus _status;
  Unit_T_UnitInfo * _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getFrontUnitInfo (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_setRole_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitRole role;
    Unit_T_UnitSBH consoleSBH;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  role = (Unit_T_UnitRole) _index; };
	consoleSBH = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setRole (&_status, role, consoleSBH);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_setMode_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitMode mode;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  mode = (Unit_T_UnitMode) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setMode (&_status, mode);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_setMinorMode_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitMinorMode minorMode;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  minorMode = (Unit_T_UnitMinorMode) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setMinorMode (&_status, minorMode);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_sendMoveAction_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_MoveAction action;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	Unit_G::Input_MoveAction (_call, &action);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendMoveAction (&_status, &action);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_sendMoveActionSeq_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_ActionSeq actions;
    ilu_ShortInteger times;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	actions = Unit_G::Input_ActionSeq (_call, NULL);
	ilu::InputShortInteger (_call, &times);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendMoveActionSeq (&_status, actions, times);

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
	Unit_G::SendException (_call, &_status);
    }
	free((char *) actions);
faild:
    return;
}

void _Unit_T_rpc_setALeader_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitSBH leaderSBH;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	leaderSBH = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setALeader (&_status, leaderSBH);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_unregisterFollower_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitID followerUID;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	followerUID = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->unregisterFollower (&_status, followerUID);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_setFollower_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitInfo ui;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &ui);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setFollower (&_status, &ui);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_unsetFollower_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitID uid;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	uid = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->unsetFollower (&_status, uid);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_addRearVehicle_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitInfo rearInfo;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &rearInfo);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->addRearVehicle (&_status, &rearInfo);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_deleteRearVehicle_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitID uid;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	uid = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->deleteRearVehicle (&_status, uid);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_setFormation_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_Formation form;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	Unit_G::Input_Formation (_call, &form);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setFormation (&_status, &form);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_setRearVehicles_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitInfoSeq rears;
    ilu_ShortReal distance;
    ilu_ShortReal angle;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	rears = Unit_G::Input_UnitInfoSeq (_call, NULL);
	ilu::InputShortReal (_call, &distance);
	ilu::InputShortReal (_call, &angle);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setRearVehicles (&_status, rears, distance, angle);

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
	Unit_G::SendException (_call, &_status);
    }
	free((char *) rears);
faild:
    return;
}

void _Unit_T_rpc_reportDeadVehicle_stub (iluCall _call)
{
    UnitStatus _status;
    Unit_T_UnitID uid;
    ilu_T_CString details;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	uid = ilu::InputString(_call, NULL, NULL, 0);
	details = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->reportDeadVehicle (&_status, uid, details);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_shutDown_stub (iluCall _call)
{
    UnitStatus _status;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->shutDown (&_status);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_startPhotoStream_stub (iluCall _call)
{
    UnitStatus _status;
    ilu_ShortReal frequency;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	ilu::InputShortReal (_call, &frequency);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->startPhotoStream (&_status, frequency);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_stopPhotoStream_stub (iluCall _call)
{
    UnitStatus _status;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->stopPhotoStream (&_status);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Unit_T_rpc_takePicture_stub (iluCall _call)
{
    UnitStatus _status;
    ilu_Integer time;
    ilu_Integer procedureStartTime;
  ilu_Boolean _retvalue;
    Unit_T_rpc *_realobj;

    _realobj = (Unit_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Unit_T_rpc::ILUClassRecord);
	ilu::InputInteger (_call, &time);
	ilu::InputInteger (_call, &procedureStartTime);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->takePicture (&_status, time, procedureStartTime);

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
	Unit_G::SendException (_call, &_status);
    }
faild:
    return;
}

#define MethodRecord_Unit_T_rpc_getID ((Unit_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Unit_T_rpc_getCosNamingSBH ((Unit_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Unit_T_rpc_getFrontUnitInfo ((Unit_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Unit_T_rpc_setRole ((Unit_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Unit_T_rpc_setMode ((Unit_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Unit_T_rpc_setMinorMode ((Unit_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Unit_T_rpc_sendMoveAction ((Unit_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Unit_T_rpc_sendMoveActionSeq ((Unit_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Unit_T_rpc_setALeader ((Unit_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Unit_T_rpc_unregisterFollower ((Unit_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Unit_T_rpc_setFollower ((Unit_T_rpc::ILUClassRecord)->cl_methods + 10)
#define MethodRecord_Unit_T_rpc_unsetFollower ((Unit_T_rpc::ILUClassRecord)->cl_methods + 11)
#define MethodRecord_Unit_T_rpc_addRearVehicle ((Unit_T_rpc::ILUClassRecord)->cl_methods + 12)
#define MethodRecord_Unit_T_rpc_deleteRearVehicle ((Unit_T_rpc::ILUClassRecord)->cl_methods + 13)
#define MethodRecord_Unit_T_rpc_setFormation ((Unit_T_rpc::ILUClassRecord)->cl_methods + 14)
#define MethodRecord_Unit_T_rpc_setRearVehicles ((Unit_T_rpc::ILUClassRecord)->cl_methods + 15)
#define MethodRecord_Unit_T_rpc_reportDeadVehicle ((Unit_T_rpc::ILUClassRecord)->cl_methods + 16)
#define MethodRecord_Unit_T_rpc_shutDown ((Unit_T_rpc::ILUClassRecord)->cl_methods + 17)
#define MethodRecord_Unit_T_rpc_startPhotoStream ((Unit_T_rpc::ILUClassRecord)->cl_methods + 18)
#define MethodRecord_Unit_T_rpc_stopPhotoStream ((Unit_T_rpc::ILUClassRecord)->cl_methods + 19)
#define MethodRecord_Unit_T_rpc_takePicture ((Unit_T_rpc::ILUClassRecord)->cl_methods + 20)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Unit_InitializeServerClass {

 public:

  _Unit_InitializeServerClass();
};

#ifndef macintosh
static class _Unit_InitializeServerClass _Unit_InitializationInstance;
#endif

void Unit__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Unit__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_getID, (ilu_StubProc) _Unit_T_rpc_getID_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_getCosNamingSBH, (ilu_StubProc) _Unit_T_rpc_getCosNamingSBH_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_getFrontUnitInfo, (ilu_StubProc) _Unit_T_rpc_getFrontUnitInfo_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_setRole, (ilu_StubProc) _Unit_T_rpc_setRole_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_setMode, (ilu_StubProc) _Unit_T_rpc_setMode_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_setMinorMode, (ilu_StubProc) _Unit_T_rpc_setMinorMode_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_sendMoveAction, (ilu_StubProc) _Unit_T_rpc_sendMoveAction_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_sendMoveActionSeq, (ilu_StubProc) _Unit_T_rpc_sendMoveActionSeq_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_setALeader, (ilu_StubProc) _Unit_T_rpc_setALeader_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_unregisterFollower, (ilu_StubProc) _Unit_T_rpc_unregisterFollower_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_setFollower, (ilu_StubProc) _Unit_T_rpc_setFollower_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_unsetFollower, (ilu_StubProc) _Unit_T_rpc_unsetFollower_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_addRearVehicle, (ilu_StubProc) _Unit_T_rpc_addRearVehicle_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_deleteRearVehicle, (ilu_StubProc) _Unit_T_rpc_deleteRearVehicle_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_setFormation, (ilu_StubProc) _Unit_T_rpc_setFormation_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_setRearVehicles, (ilu_StubProc) _Unit_T_rpc_setRearVehicles_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_reportDeadVehicle, (ilu_StubProc) _Unit_T_rpc_reportDeadVehicle_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_shutDown, (ilu_StubProc) _Unit_T_rpc_shutDown_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_startPhotoStream, (ilu_StubProc) _Unit_T_rpc_startPhotoStream_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_stopPhotoStream, (ilu_StubProc) _Unit_T_rpc_stopPhotoStream_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Unit_T_rpc_takePicture, (ilu_StubProc) _Unit_T_rpc_takePicture_stub, ilu::CppLangIdx());
}

_Unit_InitializeServerClass::_Unit_InitializeServerClass()
{
	Unit__InitializeServer();
}

