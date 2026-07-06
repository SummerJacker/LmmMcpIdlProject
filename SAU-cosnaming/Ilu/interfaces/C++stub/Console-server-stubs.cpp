/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:31:08 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Console.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class ConsoleClasses;

void _Console_T_rpc_getCosNamingInfo_stub (iluCall _call)
{
    ConsoleStatus _status;
  Unit_T_UnitInfoSeq _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCosNamingInfo (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfoSeq (_call, (Unit_T_UnitInfoSeq) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Unit_G::Output_UnitInfoSeq (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
	Unit_G::Free_UnitInfoSeq (_retvalue);
faild:
    return;
}

void _Console_T_rpc_sendMsg_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_Message m;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Console_G::Input_Message (_call, &m);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->sendMsg (&_status, &m);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_bind_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitID uid;
    Unit_T_UnitSBH sbh;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	uid = ilu::InputString(_call, NULL, NULL, 0);
	sbh = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->bind (&_status, uid, sbh);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_unbind_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitID uid;
    ilu_T_CString details;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	uid = ilu::InputString(_call, NULL, NULL, 0);
	details = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->unbind (&_status, uid, details);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_rebind_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitID uid;
    Unit_T_UnitSBH sbh;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	uid = ilu::InputString(_call, NULL, NULL, 0);
	sbh = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->rebind (&_status, uid, sbh);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setNickname_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo;
    ilu_T_CString newName;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo);
	newName = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setNickname (&_status, &uinfo, newName);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setPosition_stub (iluCall _call)
{
    ConsoleStatus _status;
    ilu_T_CString name;
    Console_T_Point p;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	name = ilu::InputString(_call, NULL, NULL, 0);
	Console_G::Input_Point (_call, &p);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setPosition (&_status, name, &p);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_addGoalPoint_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_Point p;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Console_G::Input_Point (_call, &p);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->addGoalPoint (&_status, &p);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setGoalPoint_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_Point p;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Console_G::Input_Point (_call, &p);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setGoalPoint (&_status, &p);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setRole_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo;
    Unit_T_UnitRole r;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  r = (Unit_T_UnitRole) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setRole (&_status, &uinfo, r);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_cancelRole_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->cancelRole (&_status, &uinfo);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setTrapPoint_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_TrapPoint p;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Console_G::Input_TrapPoint (_call, &p);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setTrapPoint (&_status, &p);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setFollow_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo1;
    Unit_T_UnitInfo uinfo2;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo1);
	Unit_G::Input_UnitInfo (_call, &uinfo2);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setFollow (&_status, &uinfo1, &uinfo2);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setFormationType_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_FormationType f;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  f = (Console_T_FormationType) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setFormationType (&_status, f);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setTrackMode_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_TrackMode tm;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  tm = (Console_T_TrackMode) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setTrackMode (&_status, tm);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getCurrentUnit_stub (iluCall _call)
{
    ConsoleStatus _status;
  Unit_T_UnitInfo * _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getCurrentUnit (&_status);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getUnitNum_stub (iluCall _call)
{
    ConsoleStatus _status;
  ilu_ShortInteger _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getUnitNum (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getFormationNum_stub (iluCall _call)
{
    ConsoleStatus _status;
  ilu_ShortInteger _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getFormationNum (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getTrapNum_stub (iluCall _call)
{
    ConsoleStatus _status;
  ilu_ShortInteger _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getTrapNum (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getFormationType_stub (iluCall _call)
{
    ConsoleStatus _status;
  Console_T_FormationType _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getFormationType (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getFormationState_stub (iluCall _call)
{
    ConsoleStatus _status;
  Console_T_FormationState _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getFormationState (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getMissionState_stub (iluCall _call)
{
    ConsoleStatus _status;
  Console_T_MissionState _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getMissionState (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getUnitPoint_stub (iluCall _call)
{
    ConsoleStatus _status;
    ilu_T_CString name;
  Console_T_Point * _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	name = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getUnitPoint (&_status, name);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Console_G::SizeOf_Point (_call, (Console_T_Point *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Console_G::Output_Point (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getByName_stub (iluCall _call)
{
    ConsoleStatus _status;
    ilu_T_CString name;
  Unit_T_UnitInfo * _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	name = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getByName (&_status, name);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getLeaderPoint_stub (iluCall _call)
{
    ConsoleStatus _status;
  Console_T_Point * _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getLeaderPoint (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Console_G::SizeOf_Point (_call, (Console_T_Point *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Console_G::Output_Point (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_getPointSeq_stub (iluCall _call)
{
    ConsoleStatus _status;
  Console_T_PointSeq _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->getPointSeq (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Console_G::SizeOf_PointSeq (_call, (Console_T_PointSeq) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Console_G::Output_PointSeq (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Console_G::SendException (_call, &_status);
    }
	Console_G::Free_PointSeq (_retvalue);
faild:
    return;
}

void _Console_T_rpc_cancelFormation_stub (iluCall _call)
{
    ConsoleStatus _status;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->cancelFormation (&_status);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setLeaderSuspend_stub (iluCall _call)
{
    ConsoleStatus _status;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setLeaderSuspend (&_status);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_recoveryLeaderAction_stub (iluCall _call)
{
    ConsoleStatus _status;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->recoveryLeaderAction (&_status);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_addUnitFormation_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->addUnitFormation (&_status, &uinfo);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_deleteUnitFormation_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->deleteUnitFormation (&_status, &uinfo);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setUnitFault_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setUnitFault (&_status, &uinfo);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setUnitFaultPosition_stub (iluCall _call)
{
    ConsoleStatus _status;
    Unit_T_UnitInfo uinfo;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Unit_G::Input_UnitInfo (_call, &uinfo);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setUnitFaultPosition (&_status, &uinfo);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setFormationState_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_FormationState fs;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  fs = (Console_T_FormationState) _index; };
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setFormationState (&_status, fs);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Console_T_rpc_setMissionState_stub (iluCall _call)
{
    ConsoleStatus _status;
    Console_T_MissionStateData msd;
  ilu_Boolean _retvalue;
    Console_T_rpc *_realobj;

    _realobj = (Console_T_rpc *) iluObject::InputObject(_call, ilu_TRUE, Console_T_rpc::ILUClassRecord);
	Console_G::Input_MissionStateData (_call, &msd);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->setMissionState (&_status, &msd);

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
	Console_G::SendException (_call, &_status);
    }
faild:
    return;
}

#define MethodRecord_Console_T_rpc_getCosNamingInfo ((Console_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Console_T_rpc_sendMsg ((Console_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Console_T_rpc_bind ((Console_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Console_T_rpc_unbind ((Console_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Console_T_rpc_rebind ((Console_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Console_T_rpc_setNickname ((Console_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Console_T_rpc_setPosition ((Console_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Console_T_rpc_addGoalPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Console_T_rpc_setGoalPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Console_T_rpc_setRole ((Console_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Console_T_rpc_cancelRole ((Console_T_rpc::ILUClassRecord)->cl_methods + 10)
#define MethodRecord_Console_T_rpc_setTrapPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 11)
#define MethodRecord_Console_T_rpc_setFollow ((Console_T_rpc::ILUClassRecord)->cl_methods + 12)
#define MethodRecord_Console_T_rpc_setFormationType ((Console_T_rpc::ILUClassRecord)->cl_methods + 13)
#define MethodRecord_Console_T_rpc_setTrackMode ((Console_T_rpc::ILUClassRecord)->cl_methods + 14)
#define MethodRecord_Console_T_rpc_getCurrentUnit ((Console_T_rpc::ILUClassRecord)->cl_methods + 15)
#define MethodRecord_Console_T_rpc_getUnitNum ((Console_T_rpc::ILUClassRecord)->cl_methods + 16)
#define MethodRecord_Console_T_rpc_getFormationNum ((Console_T_rpc::ILUClassRecord)->cl_methods + 17)
#define MethodRecord_Console_T_rpc_getTrapNum ((Console_T_rpc::ILUClassRecord)->cl_methods + 18)
#define MethodRecord_Console_T_rpc_getFormationType ((Console_T_rpc::ILUClassRecord)->cl_methods + 19)
#define MethodRecord_Console_T_rpc_getFormationState ((Console_T_rpc::ILUClassRecord)->cl_methods + 20)
#define MethodRecord_Console_T_rpc_getMissionState ((Console_T_rpc::ILUClassRecord)->cl_methods + 21)
#define MethodRecord_Console_T_rpc_getUnitPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 22)
#define MethodRecord_Console_T_rpc_getByName ((Console_T_rpc::ILUClassRecord)->cl_methods + 23)
#define MethodRecord_Console_T_rpc_getLeaderPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 24)
#define MethodRecord_Console_T_rpc_getPointSeq ((Console_T_rpc::ILUClassRecord)->cl_methods + 25)
#define MethodRecord_Console_T_rpc_cancelFormation ((Console_T_rpc::ILUClassRecord)->cl_methods + 26)
#define MethodRecord_Console_T_rpc_setLeaderSuspend ((Console_T_rpc::ILUClassRecord)->cl_methods + 27)
#define MethodRecord_Console_T_rpc_recoveryLeaderAction ((Console_T_rpc::ILUClassRecord)->cl_methods + 28)
#define MethodRecord_Console_T_rpc_addUnitFormation ((Console_T_rpc::ILUClassRecord)->cl_methods + 29)
#define MethodRecord_Console_T_rpc_deleteUnitFormation ((Console_T_rpc::ILUClassRecord)->cl_methods + 30)
#define MethodRecord_Console_T_rpc_setUnitFault ((Console_T_rpc::ILUClassRecord)->cl_methods + 31)
#define MethodRecord_Console_T_rpc_setUnitFaultPosition ((Console_T_rpc::ILUClassRecord)->cl_methods + 32)
#define MethodRecord_Console_T_rpc_setFormationState ((Console_T_rpc::ILUClassRecord)->cl_methods + 33)
#define MethodRecord_Console_T_rpc_setMissionState ((Console_T_rpc::ILUClassRecord)->cl_methods + 34)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Console_InitializeServerClass {

 public:

  _Console_InitializeServerClass();
};

#ifndef macintosh
static class _Console_InitializeServerClass _Console_InitializationInstance;
#endif

void Console__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Console__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getCosNamingInfo, (ilu_StubProc) _Console_T_rpc_getCosNamingInfo_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_sendMsg, (ilu_StubProc) _Console_T_rpc_sendMsg_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_bind, (ilu_StubProc) _Console_T_rpc_bind_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_unbind, (ilu_StubProc) _Console_T_rpc_unbind_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_rebind, (ilu_StubProc) _Console_T_rpc_rebind_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setNickname, (ilu_StubProc) _Console_T_rpc_setNickname_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setPosition, (ilu_StubProc) _Console_T_rpc_setPosition_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_addGoalPoint, (ilu_StubProc) _Console_T_rpc_addGoalPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setGoalPoint, (ilu_StubProc) _Console_T_rpc_setGoalPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setRole, (ilu_StubProc) _Console_T_rpc_setRole_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_cancelRole, (ilu_StubProc) _Console_T_rpc_cancelRole_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setTrapPoint, (ilu_StubProc) _Console_T_rpc_setTrapPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setFollow, (ilu_StubProc) _Console_T_rpc_setFollow_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setFormationType, (ilu_StubProc) _Console_T_rpc_setFormationType_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setTrackMode, (ilu_StubProc) _Console_T_rpc_setTrackMode_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getCurrentUnit, (ilu_StubProc) _Console_T_rpc_getCurrentUnit_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getUnitNum, (ilu_StubProc) _Console_T_rpc_getUnitNum_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getFormationNum, (ilu_StubProc) _Console_T_rpc_getFormationNum_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getTrapNum, (ilu_StubProc) _Console_T_rpc_getTrapNum_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getFormationType, (ilu_StubProc) _Console_T_rpc_getFormationType_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getFormationState, (ilu_StubProc) _Console_T_rpc_getFormationState_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getMissionState, (ilu_StubProc) _Console_T_rpc_getMissionState_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getUnitPoint, (ilu_StubProc) _Console_T_rpc_getUnitPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getByName, (ilu_StubProc) _Console_T_rpc_getByName_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getLeaderPoint, (ilu_StubProc) _Console_T_rpc_getLeaderPoint_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_getPointSeq, (ilu_StubProc) _Console_T_rpc_getPointSeq_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_cancelFormation, (ilu_StubProc) _Console_T_rpc_cancelFormation_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setLeaderSuspend, (ilu_StubProc) _Console_T_rpc_setLeaderSuspend_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_recoveryLeaderAction, (ilu_StubProc) _Console_T_rpc_recoveryLeaderAction_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_addUnitFormation, (ilu_StubProc) _Console_T_rpc_addUnitFormation_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_deleteUnitFormation, (ilu_StubProc) _Console_T_rpc_deleteUnitFormation_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setUnitFault, (ilu_StubProc) _Console_T_rpc_setUnitFault_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setUnitFaultPosition, (ilu_StubProc) _Console_T_rpc_setUnitFaultPosition_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setFormationState, (ilu_StubProc) _Console_T_rpc_setFormationState_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Console_T_rpc_setMissionState, (ilu_StubProc) _Console_T_rpc_setMissionState_stub, ilu::CppLangIdx());
}

_Console_InitializeServerClass::_Console_InitializeServerClass()
{
	Console__InitializeServer();
}

