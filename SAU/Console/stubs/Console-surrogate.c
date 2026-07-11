/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:28:58 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Console.h"

Unit_UnitInfoSeq* _Console_rpc_getCosNamingInfo__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfoSeq* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Unit_UnitInfoSeq;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_sendMsg__clientstub (Console_rpc _handle, Console_Message* m, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_Message;
  __parmsBlock[1].parm_val  = (void *) m;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_bind__clientstub (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

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
  __parmsBlock[2].parm_type = TC_Unit_UnitSBH;
  __parmsBlock[2].parm_val  = (void *) sbh;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[2],
                     _evec, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_unbind__clientstub (Console_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

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
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[3],
                     _evec, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_rebind__clientstub (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

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
  __parmsBlock[2].parm_type = TC_Unit_UnitSBH;
  __parmsBlock[2].parm_val  = (void *) sbh;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[4],
                     _evec, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setNickname__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ilu_CString newName, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[1].parm_val  = (void *) uinfo;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_ilu_CString;
  __parmsBlock[2].parm_val  = (void *) newName;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setPosition__clientstub (Console_rpc _handle, ilu_CString name, Console_Point* p, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_ilu_CString;
  __parmsBlock[1].parm_val  = (void *) name;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Console_Point;
  __parmsBlock[2].parm_val  = (void *) p;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_addGoalPoint__clientstub (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_Point;
  __parmsBlock[1].parm_val  = (void *) p;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[7],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setGoalPoint__clientstub (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_Point;
  __parmsBlock[1].parm_val  = (void *) p;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[8],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setRole__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, Unit_UnitRole r, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[1].parm_val  = (void *) uinfo;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Unit_UnitRole;
  __parmsBlock[2].parm_val  = (void *) &r;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[9],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_cancelRole__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_val  = (void *) uinfo;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[10],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setTrapPoint__clientstub (Console_rpc _handle, Console_TrapPoint* p, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_TrapPoint;
  __parmsBlock[1].parm_val  = (void *) p;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[11],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setFollow__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo1, Unit_UnitInfo* uinfo2, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[1].parm_val  = (void *) uinfo1;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[2].parm_val  = (void *) uinfo2;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[12],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setFormationType__clientstub (Console_rpc _handle, Console_FormationType f, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_FormationType;
  __parmsBlock[1].parm_val  = (void *) &f;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[13],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setTrackMode__clientstub (Console_rpc _handle, Console_TrackMode tm, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_TrackMode;
  __parmsBlock[1].parm_val  = (void *) &tm;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[14],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

Unit_UnitInfo* _Console_rpc_getCurrentUnit__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfo* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[15],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_short _Console_rpc_getUnitNum__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_short;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[16],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_short _Console_rpc_getFormationNum__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_short;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[17],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_short _Console_rpc_getTrapNum__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_short;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[18],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Console_FormationType _Console_rpc_getFormationType__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_FormationType _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Console_FormationType;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[19],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Console_FormationState _Console_rpc_getFormationState__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_FormationState _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Console_FormationState;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[20],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Console_MissionState _Console_rpc_getMissionState__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_MissionState _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Console_MissionState;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[21],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Console_Point _Console_rpc_getUnitPoint__clientstub (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status)
{
  Console_Point _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Console_Point;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_ilu_CString;
  __parmsBlock[1].parm_val  = (void *) name;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[22],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

Unit_UnitInfo* _Console_rpc_getByName__clientstub (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfo* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Unit_UnitInfo;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_ilu_CString;
  __parmsBlock[1].parm_val  = (void *) name;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[23],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

Console_Point _Console_rpc_getLeaderPoint__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_Point _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Console_Point;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[24],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Console_PointSeq* _Console_rpc_getPointSeq__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_PointSeq* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Console_PointSeq;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[25],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_cancelFormation__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[26],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setLeaderSuspend__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[27],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_recoveryLeaderAction__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[28],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_addUnitFormation__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_val  = (void *) uinfo;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[29],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_deleteUnitFormation__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_val  = (void *) uinfo;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[30],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setUnitFault__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_val  = (void *) uinfo;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[31],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setUnitFaultPosition__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_val  = (void *) uinfo;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[32],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setFormationState__clientstub (Console_rpc _handle, Console_FormationState fs, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_FormationState;
  __parmsBlock[1].parm_val  = (void *) &fs;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[33],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Console_rpc_setMissionState__clientstub (Console_rpc _handle, Console_MissionStateData* msd, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_MissionStateData;
  __parmsBlock[1].parm_val  = (void *) msd;
  _ILU_C_VectorCall (_Console_rpc__ILUType, &_Console_rpc__ILUType->cl_methods[34],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Console_rpc__SurrogateClass = 0;
Console_rpc Console_rpc__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Console_rpc) (ILU_C_SBHToObject(sbh, _Console_rpc__ILUType, env));
}

void Console__Initialize(void)
{
  extern void _Console__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  Ground_Unit__Initialize();
  Air_Unit__Initialize();
  Unit__Initialize();
  _Console__GeneralInitialization();
  _Console_rpc__SurrogateClass = Console_rpc__MakeClass(
    _Console_rpc_getCosNamingInfo__clientstub,
    _Console_rpc_sendMsg__clientstub,
    _Console_rpc_bind__clientstub,
    _Console_rpc_unbind__clientstub,
    _Console_rpc_rebind__clientstub,
    _Console_rpc_setNickname__clientstub,
    _Console_rpc_setPosition__clientstub,
    _Console_rpc_addGoalPoint__clientstub,
    _Console_rpc_setGoalPoint__clientstub,
    _Console_rpc_setRole__clientstub,
    _Console_rpc_cancelRole__clientstub,
    _Console_rpc_setTrapPoint__clientstub,
    _Console_rpc_setFollow__clientstub,
    _Console_rpc_setFormationType__clientstub,
    _Console_rpc_setTrackMode__clientstub,
    _Console_rpc_getCurrentUnit__clientstub,
    _Console_rpc_getUnitNum__clientstub,
    _Console_rpc_getFormationNum__clientstub,
    _Console_rpc_getTrapNum__clientstub,
    _Console_rpc_getFormationType__clientstub,
    _Console_rpc_getFormationState__clientstub,
    _Console_rpc_getMissionState__clientstub,
    _Console_rpc_getUnitPoint__clientstub,
    _Console_rpc_getByName__clientstub,
    _Console_rpc_getLeaderPoint__clientstub,
    _Console_rpc_getPointSeq__clientstub,
    _Console_rpc_cancelFormation__clientstub,
    _Console_rpc_setLeaderSuspend__clientstub,
    _Console_rpc_recoveryLeaderAction__clientstub,
    _Console_rpc_addUnitFormation__clientstub,
    _Console_rpc_deleteUnitFormation__clientstub,
    _Console_rpc_setUnitFault__clientstub,
    _Console_rpc_setUnitFaultPosition__clientstub,
    _Console_rpc_setFormationState__clientstub,
    _Console_rpc_setMissionState__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Console_rpc__ILUType,
	_Console_rpc__SurrogateClass);
  return;
}
