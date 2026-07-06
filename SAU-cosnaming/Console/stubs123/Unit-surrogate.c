/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Thu Jul 24 14:42:41 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/SAU/project/SAU/ilu/bin/c-stubber.EXE" of Thu Jul 10 17:58:46 2025
 * on "D:/SAU/project/SAU/Interfaces/general_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/SAU/project/SAU/ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Unit.h"

Unit_UnitID _Unit_rpc_getID__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitID _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Unit_UnitID;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Unit_UnitSBH _Unit_rpc_getCosNamingSBH__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitSBH _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Unit_UnitSBH;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Unit_UnitInfo* _Unit_rpc_getFrontUnitInfo__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfo* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_setRole__clientstub (Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitRole;
  __parmsBlock[1].parm_val  = (void *) &role;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Unit_UnitSBH;
  __parmsBlock[2].parm_val  = (void *) consoleSBH;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_setMode__clientstub (Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitMode;
  __parmsBlock[1].parm_val  = (void *) &mode;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_setMinorMode__clientstub (Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitMinorMode;
  __parmsBlock[1].parm_val  = (void *) &minorMode;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_sendMoveAction__clientstub (Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_MoveAction;
  __parmsBlock[1].parm_val  = (void *) action;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_sendMoveActionSeq__clientstub (Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_ActionSeq;
  __parmsBlock[1].parm_val  = (void *) actions;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_short;
  __parmsBlock[2].parm_val  = (void *) &times;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[7],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_setALeader__clientstub (Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitSBH;
  __parmsBlock[1].parm_val  = (void *) leaderSBH;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[8],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_unregisterFollower__clientstub (Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitID;
  __parmsBlock[1].parm_val  = (void *) followerUID;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[9],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_setFollower__clientstub (Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[1].parm_val  = (void *) ui;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[10],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_unsetFollower__clientstub (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitID;
  __parmsBlock[1].parm_val  = (void *) uid;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[11],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_addRearVehicle__clientstub (Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[1].parm_val  = (void *) rearInfo;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[12],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_deleteRearVehicle__clientstub (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitID;
  __parmsBlock[1].parm_val  = (void *) uid;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[13],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_setFormation__clientstub (Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_Formation;
  __parmsBlock[1].parm_val  = (void *) form;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[14],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_setRearVehicles__clientstub (Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitInfoSeq;
  __parmsBlock[1].parm_val  = (void *) rears;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_float;
  __parmsBlock[2].parm_val  = (void *) &distance;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_float;
  __parmsBlock[3].parm_val  = (void *) &angle;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[15],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_reportDeadVehicle__clientstub (Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitID;
  __parmsBlock[1].parm_val  = (void *) uid;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_ilu_CString;
  __parmsBlock[2].parm_val  = (void *) details;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[16],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_shutDown__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[17],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_startPhotoStream__clientstub (Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_float;
  __parmsBlock[1].parm_val  = (void *) &frequency;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[18],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_stopPhotoStream__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[19],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Unit_rpc_takePicture__clientstub (Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_long;
  __parmsBlock[1].parm_val  = (void *) &time;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_long;
  __parmsBlock[2].parm_val  = (void *) &procedureStartTime;
  _ILU_C_VectorCall (_Unit_rpc__ILUType, &_Unit_rpc__ILUType->cl_methods[20],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Unit_rpc__SurrogateClass = 0;
Unit_rpc Unit_rpc__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Unit_rpc) (ILU_C_SBHToObject(sbh, _Unit_rpc__ILUType, env));
}

void Unit__Initialize(void)
{
  extern void _Unit__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Unit__GeneralInitialization();
  _Unit_rpc__SurrogateClass = Unit_rpc__MakeClass(
    _Unit_rpc_getID__clientstub,
    _Unit_rpc_getCosNamingSBH__clientstub,
    _Unit_rpc_getFrontUnitInfo__clientstub,
    _Unit_rpc_setRole__clientstub,
    _Unit_rpc_setMode__clientstub,
    _Unit_rpc_setMinorMode__clientstub,
    _Unit_rpc_sendMoveAction__clientstub,
    _Unit_rpc_sendMoveActionSeq__clientstub,
    _Unit_rpc_setALeader__clientstub,
    _Unit_rpc_unregisterFollower__clientstub,
    _Unit_rpc_setFollower__clientstub,
    _Unit_rpc_unsetFollower__clientstub,
    _Unit_rpc_addRearVehicle__clientstub,
    _Unit_rpc_deleteRearVehicle__clientstub,
    _Unit_rpc_setFormation__clientstub,
    _Unit_rpc_setRearVehicles__clientstub,
    _Unit_rpc_reportDeadVehicle__clientstub,
    _Unit_rpc_shutDown__clientstub,
    _Unit_rpc_startPhotoStream__clientstub,
    _Unit_rpc_stopPhotoStream__clientstub,
    _Unit_rpc_takePicture__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Unit_rpc__ILUType,
	_Unit_rpc__SurrogateClass);
  return;
}
