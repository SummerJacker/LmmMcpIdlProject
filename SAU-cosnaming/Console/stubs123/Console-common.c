/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Thu Jul 24 14:42:41 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/SAU/project/SAU/ilu/bin/c-stubber.EXE" of Thu Jul 10 17:58:46 2025
 * on "D:/SAU/project/SAU/Interfaces/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/SAU/project/SAU/ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/SAU/project/SAU/Interfaces/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/SAU/project/SAU/Interfaces/air_unit.idl" of Fri Jul 18 15:18:31 2025,
 * and "D:/SAU/project/SAU/Interfaces/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Console.h"

ilu_Class _Console_rpc__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Console_rpc__IoFns = { ilu_object_tk, "IDL:Console/rpc:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_TrapPointSeq__IoFns = { ilu_sequence_tk, "ilut:bScP2+rZUrGWcNDjgx4pjGKOoFV", { sizeof(Console_TrapPointSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_PointSeq__IoFns = { ilu_sequence_tk, "ilut:gj5QlY2dALbZCLSEKoPy7Ke-T8C", { sizeof(Console_PointSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_Message__IoFns = { ilu_union_tk, "IDL:Console/Message:1.0", { sizeof(Console_Message) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_UnbindData__IoFns = { ilu_record_tk, "IDL:Console/UnbindData:1.0", { sizeof(Console_UnbindData) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_Operation__IoFns = { ilu_enumeration_tk, "IDL:Console/Operation:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_TrapPoint__IoFns = { ilu_union_tk, "IDL:Console/TrapPoint:1.0", { sizeof(Console_TrapPoint) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_TrapType__IoFns = { ilu_enumeration_tk, "IDL:Console/TrapType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_Point__IoFns = { ilu_union_tk, "IDL:Console/Point:1.0", { sizeof(Console_Point) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_PointType__IoFns = { ilu_enumeration_tk, "IDL:Console/PointType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_TrackMode__IoFns = { ilu_enumeration_tk, "IDL:Console/TrackMode:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_FormationType__IoFns = { ilu_enumeration_tk, "IDL:Console/FormationType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_FormationState__IoFns = { ilu_enumeration_tk, "IDL:Console/FormationState:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_MissionStateData__IoFns = { ilu_union_tk, "IDL:Console/MissionStateData:1.0", { sizeof(Console_MissionStateData) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Console_MissionState__IoFns = { ilu_enumeration_tk, "IDL:Console/MissionState:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };


ILU_C_Class Console_rpc__MakeClass(
  Unit_UnitInfoSeq* (*Console_rpc_getCosNamingInfo__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_sendMsg__Impl)
     (Console_rpc _handle, Console_Message* m, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_bind__Impl)
     (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_unbind__Impl)
     (Console_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_rebind__Impl)
     (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setNickname__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ilu_CString newName, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setPosition__Impl)
     (Console_rpc _handle, ilu_CString name, Console_Point* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_addGoalPoint__Impl)
     (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setGoalPoint__Impl)
     (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setRole__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, Unit_UnitRole r, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_cancelRole__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setTrapPoint__Impl)
     (Console_rpc _handle, Console_TrapPoint* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setFollow__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo1, Unit_UnitInfo* uinfo2, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setFormationType__Impl)
     (Console_rpc _handle, Console_FormationType f, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setTrackMode__Impl)
     (Console_rpc _handle, Console_TrackMode tm, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Console_rpc_getCurrentUnit__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*Console_rpc_getUnitNum__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*Console_rpc_getFormationNum__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*Console_rpc_getTrapNum__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_FormationType (*Console_rpc_getFormationType__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_FormationState (*Console_rpc_getFormationState__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_MissionState (*Console_rpc_getMissionState__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_Point (*Console_rpc_getUnitPoint__Impl)
     (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Console_rpc_getByName__Impl)
     (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status),
  Console_Point (*Console_rpc_getLeaderPoint__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_PointSeq* (*Console_rpc_getPointSeq__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_cancelFormation__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setLeaderSuspend__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_recoveryLeaderAction__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_addUnitFormation__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_deleteUnitFormation__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setUnitFault__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setUnitFaultPosition__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setFormationState__Impl)
     (Console_rpc _handle, Console_FormationState fs, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setMissionState__Impl)
     (Console_rpc _handle, Console_MissionStateData* msd, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(3 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _Console_rpc__ILUType;
  method_block = ilu_malloc(35 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Console_rpc_getCosNamingInfo__Impl;
  method_block[1] = (_ILU_C_Method) Console_rpc_sendMsg__Impl;
  method_block[2] = (_ILU_C_Method) Console_rpc_bind__Impl;
  method_block[3] = (_ILU_C_Method) Console_rpc_unbind__Impl;
  method_block[4] = (_ILU_C_Method) Console_rpc_rebind__Impl;
  method_block[5] = (_ILU_C_Method) Console_rpc_setNickname__Impl;
  method_block[6] = (_ILU_C_Method) Console_rpc_setPosition__Impl;
  method_block[7] = (_ILU_C_Method) Console_rpc_addGoalPoint__Impl;
  method_block[8] = (_ILU_C_Method) Console_rpc_setGoalPoint__Impl;
  method_block[9] = (_ILU_C_Method) Console_rpc_setRole__Impl;
  method_block[10] = (_ILU_C_Method) Console_rpc_cancelRole__Impl;
  method_block[11] = (_ILU_C_Method) Console_rpc_setTrapPoint__Impl;
  method_block[12] = (_ILU_C_Method) Console_rpc_setFollow__Impl;
  method_block[13] = (_ILU_C_Method) Console_rpc_setFormationType__Impl;
  method_block[14] = (_ILU_C_Method) Console_rpc_setTrackMode__Impl;
  method_block[15] = (_ILU_C_Method) Console_rpc_getCurrentUnit__Impl;
  method_block[16] = (_ILU_C_Method) Console_rpc_getUnitNum__Impl;
  method_block[17] = (_ILU_C_Method) Console_rpc_getFormationNum__Impl;
  method_block[18] = (_ILU_C_Method) Console_rpc_getTrapNum__Impl;
  method_block[19] = (_ILU_C_Method) Console_rpc_getFormationType__Impl;
  method_block[20] = (_ILU_C_Method) Console_rpc_getFormationState__Impl;
  method_block[21] = (_ILU_C_Method) Console_rpc_getMissionState__Impl;
  method_block[22] = (_ILU_C_Method) Console_rpc_getUnitPoint__Impl;
  method_block[23] = (_ILU_C_Method) Console_rpc_getByName__Impl;
  method_block[24] = (_ILU_C_Method) Console_rpc_getLeaderPoint__Impl;
  method_block[25] = (_ILU_C_Method) Console_rpc_getPointSeq__Impl;
  method_block[26] = (_ILU_C_Method) Console_rpc_cancelFormation__Impl;
  method_block[27] = (_ILU_C_Method) Console_rpc_setLeaderSuspend__Impl;
  method_block[28] = (_ILU_C_Method) Console_rpc_recoveryLeaderAction__Impl;
  method_block[29] = (_ILU_C_Method) Console_rpc_addUnitFormation__Impl;
  method_block[30] = (_ILU_C_Method) Console_rpc_deleteUnitFormation__Impl;
  method_block[31] = (_ILU_C_Method) Console_rpc_setUnitFault__Impl;
  method_block[32] = (_ILU_C_Method) Console_rpc_setUnitFaultPosition__Impl;
  method_block[33] = (_ILU_C_Method) Console_rpc_setFormationState__Impl;
  method_block[34] = (_ILU_C_Method) Console_rpc_setMissionState__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _ilu_CORBA_Object__ILUType;
  ans->ilucc_sections[done++].ilucdts_methods = ILU_NIL;
  ans->ilucc_sections[done].ilucdts_introType = ILU_NIL;
  ans->ilucc_sections[done].ilucdts_methods = ILU_NIL;
  return ans;
fale1:
  for (i=0; i<done; i++) 
    ilu_free(ans->ilucc_sections[i].ilucdts_methods);
fale0:
  ilu_free(ans);
  return ILU_NIL;
}
Unit_UnitInfoSeq* Console_rpc_getCosNamingInfo (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfoSeq* (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Unit_UnitInfoSeq* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Unit_UnitInfoSeq* (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Console_rpc_sendMsg (Console_rpc _handle, Console_Message* m, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_Message*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_Message*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, m, _status));
}

CORBA_boolean Console_rpc_bind (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitID, Unit_UnitSBH, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitID, Unit_UnitSBH, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uid, sbh, _status));
}

CORBA_boolean Console_rpc_unbind (Console_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitID, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitID, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uid, details, _status));
}

CORBA_boolean Console_rpc_rebind (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitID, Unit_UnitSBH, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitID, Unit_UnitSBH, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uid, sbh, _status));
}

CORBA_boolean Console_rpc_setNickname (Console_rpc _handle, Unit_UnitInfo* uinfo, ilu_CString newName, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo, newName, _status));
}

CORBA_boolean Console_rpc_setPosition (Console_rpc _handle, ilu_CString name, Console_Point* p, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, ilu_CString, Console_Point*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, ilu_CString, Console_Point*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, name, p, _status));
}

CORBA_boolean Console_rpc_addGoalPoint (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_Point*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_Point*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, p, _status));
}

CORBA_boolean Console_rpc_setGoalPoint (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_Point*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_Point*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 8);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, p, _status));
}

CORBA_boolean Console_rpc_setRole (Console_rpc _handle, Unit_UnitInfo* uinfo, Unit_UnitRole r, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, Unit_UnitRole, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, Unit_UnitRole, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 9);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo, r, _status));
}

CORBA_boolean Console_rpc_cancelRole (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 10);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo, _status));
}

CORBA_boolean Console_rpc_setTrapPoint (Console_rpc _handle, Console_TrapPoint* p, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_TrapPoint*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_TrapPoint*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 11);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, p, _status));
}

CORBA_boolean Console_rpc_setFollow (Console_rpc _handle, Unit_UnitInfo* uinfo1, Unit_UnitInfo* uinfo2, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 12);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo1, uinfo2, _status));
}

CORBA_boolean Console_rpc_setFormationType (Console_rpc _handle, Console_FormationType f, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_FormationType, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_FormationType, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 13);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, f, _status));
}

CORBA_boolean Console_rpc_setTrackMode (Console_rpc _handle, Console_TrackMode tm, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_TrackMode, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_TrackMode, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 14);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, tm, _status));
}

Unit_UnitInfo* Console_rpc_getCurrentUnit (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfo* (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Unit_UnitInfo* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Unit_UnitInfo* (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 15);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_short Console_rpc_getUnitNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_short _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_short (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 16);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_short Console_rpc_getFormationNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_short _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_short (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 17);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_short Console_rpc_getTrapNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_short _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_short (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 18);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Console_FormationType Console_rpc_getFormationType (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_FormationType (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Console_FormationType _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Console_FormationType (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 19);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Console_FormationState Console_rpc_getFormationState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_FormationState (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Console_FormationState _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Console_FormationState (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 20);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Console_MissionState Console_rpc_getMissionState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_MissionState (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Console_MissionState _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Console_MissionState (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 21);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Console_Point Console_rpc_getUnitPoint (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status)
{
  Console_Point (*_f)(Console_rpc, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Console_Point _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Console_Point (*)(Console_rpc, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 22);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, name, _status));
}

Unit_UnitInfo* Console_rpc_getByName (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfo* (*_f)(Console_rpc, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Unit_UnitInfo* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Unit_UnitInfo* (*)(Console_rpc, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 23);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, name, _status));
}

Console_Point Console_rpc_getLeaderPoint (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_Point (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Console_Point _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Console_Point (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 24);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Console_PointSeq* Console_rpc_getPointSeq (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Console_PointSeq* (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Console_PointSeq* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Console_PointSeq* (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 25);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Console_rpc_cancelFormation (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 26);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Console_rpc_setLeaderSuspend (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 27);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Console_rpc_recoveryLeaderAction (Console_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 28);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Console_rpc_addUnitFormation (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 29);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo, _status));
}

CORBA_boolean Console_rpc_deleteUnitFormation (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 30);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo, _status));
}

CORBA_boolean Console_rpc_setUnitFault (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 31);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo, _status));
}

CORBA_boolean Console_rpc_setUnitFaultPosition (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 32);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uinfo, _status));
}

CORBA_boolean Console_rpc_setFormationState (Console_rpc _handle, Console_FormationState fs, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_FormationState, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_FormationState, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 33);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, fs, _status));
}

CORBA_boolean Console_rpc_setMissionState (Console_rpc _handle, Console_MissionStateData* msd, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Console_rpc, Console_MissionStateData*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Console_rpc, Console_MissionStateData*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Console_rpc__ILUType, 34);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, msd, _status));
}

void Console_rpc__SetUserData (Console_rpc self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Console_rpc__GetUserData (Console_rpc self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _Console__Exception_rpc_AlreadyBind = ILU_NIL;
ILU_C_ExceptionCode _Console__Exception_rpc_NotFound = ILU_NIL;
#include <stdarg.h>

void Console__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_Console_rpc_AlreadyBind) {
    stat->ptr = ILU_NIL;
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_Console_rpc_NotFound) {
    stat->ptr = ILU_NIL;
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else
    _ilu_Assert(0, "bad exn given to Console__BindExceptionValue");
  va_end (ap);
}

void Console_rpc__Free (Console_rpc* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Console_rpc */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Console_rpc *CORBA_sequence_Console_rpc_allocbuf (CORBA_unsigned_long _count)
{
  Console_rpc *_p;
  CORBA_unsigned_long _size = sizeof(Console_rpc) * _count;

  if ((_p = (Console_rpc *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_TrapPointSeq* _Console_TrapPointSeq__Input (ilu_Call _call, Console_TrapPointSeq* _ref, ilu_Error *_err)
{
  Console_TrapPointSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Console_TrapPoint _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Console_TrapPointSeq*) ilu_MallocE(sizeof (Console_TrapPointSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Console_TrapPointSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Console_TrapPointSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Console_TrapPoint), _count, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Console_TrapPoint), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Console_TrapPoint__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Console_TrapPointSeq_Append (_val, &_tmp, _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  ilu_EndSequence (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Console_TrapPointSeq__Output (ilu_Call _call, Console_TrapPointSeq* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Console_TrapPointSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Console_TrapPoint), _val->_length, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Console_TrapPoint), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Console_TrapPoint *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Console_TrapPoint__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Console_TrapPointSeq__SizeOf (ilu_Call _call, Console_TrapPointSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Console_TrapPointSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Console_TrapPoint), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Console_TrapPoint), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Console_TrapPoint *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Console_TrapPoint__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Console_TrapPointSeq__Free (Console_TrapPointSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Console_TrapPointSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Console_TrapPoint)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Console_TrapPoint)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Console_TrapPoint))) */ ) {
    //ilu_DebugPrintf("OK Console_TrapPointSeq__Free (Console_TrapPointSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Console_TrapPointSeq *CORBA_sequence_Console_TrapPointSeq_allocbuf (CORBA_unsigned_long _count)
{
  Console_TrapPointSeq *_p;
  CORBA_unsigned_long _size = sizeof(Console_TrapPointSeq) * _count;

  if ((_p = (Console_TrapPointSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_TrapPointSeq* Console_TrapPointSeq__alloc ()
{
  return ((Console_TrapPointSeq*) CORBA_sequence_Console_TrapPointSeq_allocbuf(1));
}

Console_PointSeq* _Console_PointSeq__Input (ilu_Call _call, Console_PointSeq* _ref, ilu_Error *_err)
{
  Console_PointSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Console_Point _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Console_PointSeq*) ilu_MallocE(sizeof (Console_PointSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Console_PointSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Console_PointSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Console_Point), _count, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Console_Point), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Console_Point__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Console_PointSeq_Append (_val, &_tmp, _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  ilu_EndSequence (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Console_PointSeq__Output (ilu_Call _call, Console_PointSeq* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Console_PointSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Console_Point), _val->_length, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Console_Point), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Console_Point *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Console_Point__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Console_PointSeq__SizeOf (ilu_Call _call, Console_PointSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Console_PointSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Console_Point), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Console_Point), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Console_Point *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Console_Point__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Console_PointSeq__Free (Console_PointSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Console_PointSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Console_Point)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Console_Point)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Console_Point))) */ ) {
    //ilu_DebugPrintf("OK Console_PointSeq__Free (Console_PointSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Console_PointSeq *CORBA_sequence_Console_PointSeq_allocbuf (CORBA_unsigned_long _count)
{
  Console_PointSeq *_p;
  CORBA_unsigned_long _size = sizeof(Console_PointSeq) * _count;

  if ((_p = (Console_PointSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_PointSeq* Console_PointSeq__alloc ()
{
  return ((Console_PointSeq*) CORBA_sequence_Console_PointSeq_allocbuf(1));
}

Console_Message* _Console_Message__Input (ilu_Call _call, Console_Message* _ref, ilu_Error *_err)
{
  Console_Message* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_Message), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Console_Message*) ilu_MallocE(sizeof (Console_Message), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Console_Message));
  };
  switch (tag) {
    case Console_OP_SetCosInfo:
      (void) _Unit_UnitInfoSeq__Input (_call, &_val->_u.infoSeq,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_Bind:
      (void) _Unit_UnitInfo__Input (_call, &_val->_u.bindInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_Unbind:
      (void) _Console_UnbindData__Input (_call, &_val->_u.unbindInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_ReportTrap:
    case Console_OP_AddTrap:
      (void) _Console_TrapPoint__Input (_call, &_val->_u.tp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_Opened:
    case Console_OP_Closed:
      (void) _ilu_CString__Input (_call, &_val->_u.details, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (Console_Operation) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Console_Message__Output (ilu_Call _call, Console_Message* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_Message), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Console_OP_SetCosInfo:
      _Unit_UnitInfoSeq__Output(_call, &_val->_u.infoSeq, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_Bind:
      _Unit_UnitInfo__Output(_call, &_val->_u.bindInfo, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_Unbind:
      _Console_UnbindData__Output(_call, &_val->_u.unbindInfo, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_ReportTrap:
    case Console_OP_AddTrap:
      _Console_TrapPoint__Output(_call, &_val->_u.tp, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_OP_Opened:
    case Console_OP_Closed:
      _ilu_CString__Output (_call, _val->_u.details, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Console_Message__SizeOf (ilu_Call _call, Console_Message* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_Message), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Console_OP_SetCosInfo:
      size += _Unit_UnitInfoSeq__SizeOf (_call, &_val->_u.infoSeq, _err);
      break;
    case Console_OP_Bind:
      size += _Unit_UnitInfo__SizeOf (_call, &_val->_u.bindInfo, _err);
      break;
    case Console_OP_Unbind:
      size += _Console_UnbindData__SizeOf (_call, &_val->_u.unbindInfo, _err);
      break;
    case Console_OP_ReportTrap:
    case Console_OP_AddTrap:
      size += _Console_TrapPoint__SizeOf (_call, &_val->_u.tp, _err);
      break;
    case Console_OP_Opened:
    case Console_OP_Closed:
      size += _ilu_CString__SizeOf(_call, _val->_u.details, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Console_Message__Free (Console_Message* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Console_Message */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case Console_OP_SetCosInfo:
      Unit_UnitInfoSeq__Free (&_val->_u.infoSeq);
      break;
    case Console_OP_Bind:
      Unit_UnitInfo__Free (&_val->_u.bindInfo);
      break;
    case Console_OP_Unbind:
      Console_UnbindData__Free (&_val->_u.unbindInfo);
      break;
    case Console_OP_ReportTrap:
    case Console_OP_AddTrap:
      break;
    case Console_OP_Opened:
    case Console_OP_Closed:
      ilu_CString__Free ((ilu_CString *) &_val->_u.details);
      break;
    default:
      break;
  };
}

Console_Message *CORBA_sequence_Console_Message_allocbuf (CORBA_unsigned_long _count)
{
  Console_Message *_p;
  CORBA_unsigned_long _size = sizeof(Console_Message) * _count;

  if ((_p = (Console_Message *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_Message* Console_Message__alloc ()
{
  return ((Console_Message*) CORBA_sequence_Console_Message_allocbuf(1));
}

Console_UnbindData* _Console_UnbindData__Input (ilu_Call _call, Console_UnbindData* _ref, ilu_Error *_err)
{
  Console_UnbindData* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Console_UnbindData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Console_UnbindData__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Console_UnbindData*) ilu_MallocE (sizeof (Console_UnbindData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Console_UnbindData));
    } else {
      _val = (Console_UnbindData*) _ILU_C_CRCreate (s, sizeof(Console_UnbindData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Console_UnbindData), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->uid, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->details, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (s != ILU_NIL) _ILU_C_CRPostInput (s, _val, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Console_UnbindData__Output (ilu_Call _call, Console_UnbindData* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Console_UnbindData__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Console_UnbindData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Console_UnbindData), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ilu_CString__Output (_call, (_val->uid), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _ilu_CString__Output (_call, (_val->details), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Console_UnbindData__SizeOf (ilu_Call _call, Console_UnbindData* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Console_UnbindData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Console_UnbindData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Console_UnbindData), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->uid, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->details, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Console_UnbindData__Free (Console_UnbindData* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Console_UnbindData */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Console_UnbindData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Console_UnbindData__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  ilu_CString__Free (&_val->uid);
  ilu_CString__Free ((ilu_CString *) &_val->details);
}

Console_UnbindData *CORBA_sequence_Console_UnbindData_allocbuf (CORBA_unsigned_long _count)
{
  Console_UnbindData *_p;
  CORBA_unsigned_long _size = sizeof(Console_UnbindData) * _count;

  if ((_p = (Console_UnbindData *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_UnbindData* Console_UnbindData__alloc ()
{
  return ((Console_UnbindData*) CORBA_sequence_Console_UnbindData_allocbuf(1));
}

Console_Operation *CORBA_sequence_Console_Operation_allocbuf (CORBA_unsigned_long _count)
{
  Console_Operation *_p;
  CORBA_unsigned_long _size = sizeof(Console_Operation) * _count;

  if ((_p = (Console_Operation *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_TrapPoint* _Console_TrapPoint__Input (ilu_Call _call, Console_TrapPoint* _ref, ilu_Error *_err)
{
  Console_TrapPoint* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_TrapPoint), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Console_TrapPoint*) ilu_MallocE(sizeof (Console_TrapPoint), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Console_TrapPoint));
  };
  switch (tag) {
    case Console_TrapGroundType:
      (void) _Ground_Unit_TrapPoint2D__Input (_call, &_val->_u.trapPoint2D,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_TrapAirType:
      (void) _Air_Unit_TrapPoint3D__Input (_call, &_val->_u.trapPoint3D,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (Console_TrapType) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Console_TrapPoint__Output (ilu_Call _call, Console_TrapPoint* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_TrapPoint), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Console_TrapGroundType:
      _Ground_Unit_TrapPoint2D__Output(_call, &_val->_u.trapPoint2D, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_TrapAirType:
      _Air_Unit_TrapPoint3D__Output(_call, &_val->_u.trapPoint3D, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Console_TrapPoint__SizeOf (ilu_Call _call, Console_TrapPoint* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_TrapPoint), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Console_TrapGroundType:
      size += _Ground_Unit_TrapPoint2D__SizeOf (_call, &_val->_u.trapPoint2D, _err);
      break;
    case Console_TrapAirType:
      size += _Air_Unit_TrapPoint3D__SizeOf (_call, &_val->_u.trapPoint3D, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Console_TrapPoint *CORBA_sequence_Console_TrapPoint_allocbuf (CORBA_unsigned_long _count)
{
  Console_TrapPoint *_p;
  CORBA_unsigned_long _size = sizeof(Console_TrapPoint) * _count;

  if ((_p = (Console_TrapPoint *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_TrapPoint* Console_TrapPoint__alloc ()
{
  return ((Console_TrapPoint*) CORBA_sequence_Console_TrapPoint_allocbuf(1));
}

Console_TrapType *CORBA_sequence_Console_TrapType_allocbuf (CORBA_unsigned_long _count)
{
  Console_TrapType *_p;
  CORBA_unsigned_long _size = sizeof(Console_TrapType) * _count;

  if ((_p = (Console_TrapType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_Point* _Console_Point__Input (ilu_Call _call, Console_Point* _ref, ilu_Error *_err)
{
  Console_Point* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_Point), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Console_Point*) ilu_MallocE(sizeof (Console_Point), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Console_Point));
  };
  switch (tag) {
    case Console_PointGroundType:
      (void) _Ground_Unit_Point2D__Input (_call, &_val->_u.p2D,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_PointAirType:
      (void) _Air_Unit_Point3D__Input (_call, &_val->_u.p3D,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (Console_PointType) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Console_Point__Output (ilu_Call _call, Console_Point* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_Point), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Console_PointGroundType:
      _Ground_Unit_Point2D__Output(_call, &_val->_u.p2D, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Console_PointAirType:
      _Air_Unit_Point3D__Output(_call, &_val->_u.p3D, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Console_Point__SizeOf (ilu_Call _call, Console_Point* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_Point), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Console_PointGroundType:
      size += _Ground_Unit_Point2D__SizeOf (_call, &_val->_u.p2D, _err);
      break;
    case Console_PointAirType:
      size += _Air_Unit_Point3D__SizeOf (_call, &_val->_u.p3D, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Console_Point *CORBA_sequence_Console_Point_allocbuf (CORBA_unsigned_long _count)
{
  Console_Point *_p;
  CORBA_unsigned_long _size = sizeof(Console_Point) * _count;

  if ((_p = (Console_Point *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_Point* Console_Point__alloc ()
{
  return ((Console_Point*) CORBA_sequence_Console_Point_allocbuf(1));
}

Console_PointType *CORBA_sequence_Console_PointType_allocbuf (CORBA_unsigned_long _count)
{
  Console_PointType *_p;
  CORBA_unsigned_long _size = sizeof(Console_PointType) * _count;

  if ((_p = (Console_PointType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_TrackMode *CORBA_sequence_Console_TrackMode_allocbuf (CORBA_unsigned_long _count)
{
  Console_TrackMode *_p;
  CORBA_unsigned_long _size = sizeof(Console_TrackMode) * _count;

  if ((_p = (Console_TrackMode *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_FormationType *CORBA_sequence_Console_FormationType_allocbuf (CORBA_unsigned_long _count)
{
  Console_FormationType *_p;
  CORBA_unsigned_long _size = sizeof(Console_FormationType) * _count;

  if ((_p = (Console_FormationType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_FormationState *CORBA_sequence_Console_FormationState_allocbuf (CORBA_unsigned_long _count)
{
  Console_FormationState *_p;
  CORBA_unsigned_long _size = sizeof(Console_FormationState) * _count;

  if ((_p = (Console_FormationState *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_MissionStateData* _Console_MissionStateData__Input (ilu_Call _call, Console_MissionStateData* _ref, ilu_Error *_err)
{
  Console_MissionStateData* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_MissionStateData), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Console_MissionStateData*) ilu_MallocE(sizeof (Console_MissionStateData), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Console_MissionStateData));
  };
  switch (tag) {
    case Console_MissionSuspend:
      ilu_InputShortInteger (_call, &_val->_u.time, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (Console_MissionState) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Console_MissionStateData__Output (ilu_Call _call, Console_MissionStateData* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_MissionStateData), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Console_MissionSuspend:
      ilu_OutputShortInteger (_call, _val->_u.time, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Console_MissionStateData__SizeOf (ilu_Call _call, Console_MissionStateData* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Console_MissionStateData), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Console_MissionSuspend:
      size += ilu_SizeOfShortInteger(_call, _val->_u.time, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Console_MissionStateData *CORBA_sequence_Console_MissionStateData_allocbuf (CORBA_unsigned_long _count)
{
  Console_MissionStateData *_p;
  CORBA_unsigned_long _size = sizeof(Console_MissionStateData) * _count;

  if ((_p = (Console_MissionStateData *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Console_MissionStateData* Console_MissionStateData__alloc ()
{
  return ((Console_MissionStateData*) CORBA_sequence_Console_MissionStateData_allocbuf(1));
}

Console_MissionState *CORBA_sequence_Console_MissionState_allocbuf (CORBA_unsigned_long _count)
{
  Console_MissionState *_p;
  CORBA_unsigned_long _size = sizeof(Console_MissionState) * _count;

  if ((_p = (Console_MissionState *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void Console_TrapPointSeq_Every (Console_TrapPointSeq *h, void (*f)(Console_TrapPoint*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Console_TrapPoint), (void *) data);
}

void Console_TrapPointSeq_Append (Console_TrapPointSeq *h, Console_TrapPoint* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Console_TrapPoint), err);
}

void Console_TrapPointSeq_Push (Console_TrapPointSeq *h, Console_TrapPoint* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Console_TrapPoint));
}

void Console_TrapPointSeq_Pop (Console_TrapPointSeq *h, Console_TrapPoint* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Console_TrapPoint));
}

CORBA_unsigned_long Console_TrapPointSeq_Length (Console_TrapPointSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Console_TrapPoint * Console_TrapPointSeq_Nth (Console_TrapPointSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Console_TrapPointSeq * Console_TrapPointSeq_Create (CORBA_unsigned_long sz, Console_TrapPoint* p)
{
  Console_TrapPointSeq *s;
  s = (Console_TrapPointSeq *) ilu_malloc(sizeof(Console_TrapPointSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Console_TrapPointSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Console_TrapPoint *) ilu_malloc(sz * sizeof(Console_TrapPoint))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Console_TrapPoint));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Console_TrapPointSeq_Init (Console_TrapPointSeq *s, CORBA_unsigned_long sz, Console_TrapPoint* p)
{
  if (sz == 0 && p != ILU_NIL)
    return;
  if (sz > 0)
    s->_maximum = sz;
  else
    s->_maximum = 0;
  if (sz > 0 && p != ILU_NIL)
    s->_length = sz;
  else
    s->_length = 0;
  if (sz > 0 && p == ILU_NIL) {
    s->_buffer = (Console_TrapPoint *) ilu_malloc (sz * sizeof (Console_TrapPoint));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Console_TrapPoint)); }}
  else
    s->_buffer = p;
  return;
}

void Console_PointSeq_Every (Console_PointSeq *h, void (*f)(Console_Point*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Console_Point), (void *) data);
}

void Console_PointSeq_Append (Console_PointSeq *h, Console_Point* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Console_Point), err);
}

void Console_PointSeq_Push (Console_PointSeq *h, Console_Point* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Console_Point));
}

void Console_PointSeq_Pop (Console_PointSeq *h, Console_Point* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Console_Point));
}

CORBA_unsigned_long Console_PointSeq_Length (Console_PointSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Console_Point * Console_PointSeq_Nth (Console_PointSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Console_PointSeq * Console_PointSeq_Create (CORBA_unsigned_long sz, Console_Point* p)
{
  Console_PointSeq *s;
  s = (Console_PointSeq *) ilu_malloc(sizeof(Console_PointSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Console_PointSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Console_Point *) ilu_malloc(sz * sizeof(Console_Point))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Console_Point));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Console_PointSeq_Init (Console_PointSeq *s, CORBA_unsigned_long sz, Console_Point* p)
{
  if (sz == 0 && p != ILU_NIL)
    return;
  if (sz > 0)
    s->_maximum = sz;
  else
    s->_maximum = 0;
  if (sz > 0 && p != ILU_NIL)
    s->_length = sz;
  else
    s->_length = 0;
  if (sz > 0 && p == ILU_NIL) {
    s->_buffer = (Console_Point *) ilu_malloc (sz * sizeof (Console_Point));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Console_Point)); }}
  else
    s->_buffer = p;
  return;
}

void _Console__GeneralInitialization (void)
{
  static ilu_boolean initialized = ilu_FALSE;
  ilu_Error lerr = ILU_INIT_NO_ERR;
  ilu_Class cl = ILU_NIL;
  ilu_Method m = ILU_NIL;
  ilu_Mutex otmu = ilu_GetOTMutex();
  ilu_boolean newreg;

  if (initialized)
    return;
  initialized = ilu_TRUE;
  _ILU_C_InitializeCRuntime();
  _ILU_C_CheckStubConsistency("Console", "2.0beta1", "v2 (2.0beta1)");
  _Ground_Unit__GeneralInitialization();
  _Air_Unit__GeneralInitialization();
  _Unit__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _Console__Exception_rpc_AlreadyBind = ilu_DefineException(ILU_NIL, "IDL:Console/rpc/AlreadyBind:1.0", ILU_NIL, &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Console__Exception_rpc_NotFound = ilu_DefineException(ILU_NIL, "IDL:Console/rpc/NotFound:1.0", ILU_NIL, &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"IDL:omg.org/CORBA/Object:1.0",
	NULL};
    cl = ilu_DefineObjectType("Console.rpc",	/*name*/
	NULL,	/*no brand*/
	"IDL:Console/rpc:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	35,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Console_rpc__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"getCosNamingInfo",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:nulfTSjgo17mBovMLQKbwxXk7V-",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"sendMsg",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "m", ilu_FALSE, ilu_In, "IDL:Console/Message:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Console_rpc_AlreadyBind;
    m = ilu_DefineMethod(cl, 2,
	"bind",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uid", ilu_FALSE, ilu_In, "IDL:Unit/UnitID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "sbh", ilu_FALSE, ilu_In, "IDL:Unit/UnitSBH:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Console_rpc_NotFound;
    m = ilu_DefineMethod(cl, 3,
	"unbind",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uid", ilu_FALSE, ilu_In, "IDL:Unit/UnitID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "details", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Console_rpc_NotFound;
    m = ilu_DefineMethod(cl, 4,
	"rebind",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uid", ilu_FALSE, ilu_In, "IDL:Unit/UnitID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "sbh", ilu_FALSE, ilu_In, "IDL:Unit/UnitSBH:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 5,
	"setNickname",	/*name*/
	6,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "newName", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 6,
	"setPosition",	/*name*/
	7,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "name", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "p", ilu_FALSE, ilu_In, "IDL:Console/Point:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 7,
	"addGoalPoint",	/*name*/
	8,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "p", ilu_FALSE, ilu_In, "IDL:Console/Point:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 8,
	"setGoalPoint",	/*name*/
	9,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "p", ilu_FALSE, ilu_In, "IDL:Console/Point:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 9,
	"setRole",	/*name*/
	10,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "r", ilu_FALSE, ilu_In, "IDL:Unit/UnitRole:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 10,
	"cancelRole",	/*name*/
	11,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 11,
	"setTrapPoint",	/*name*/
	12,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "p", ilu_FALSE, ilu_In, "IDL:Console/TrapPoint:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 12,
	"setFollow",	/*name*/
	13,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo1", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "uinfo2", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 13,
	"setFormationType",	/*name*/
	14,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "f", ilu_FALSE, ilu_In, "IDL:Console/FormationType:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 14,
	"setTrackMode",	/*name*/
	15,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "tm", ilu_FALSE, ilu_In, "IDL:Console/TrackMode:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 15,
	"getCurrentUnit",	/*name*/
	16,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Unit/UnitInfo:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 16,
	"getUnitNum",	/*name*/
	17,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 17,
	"getFormationNum",	/*name*/
	18,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 18,
	"getTrapNum",	/*name*/
	19,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 19,
	"getFormationType",	/*name*/
	20,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Console/FormationType:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 20,
	"getFormationState",	/*name*/
	21,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Console/FormationState:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 21,
	"getMissionState",	/*name*/
	22,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Console/MissionState:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 22,
	"getUnitPoint",	/*name*/
	23,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"IDL:Console/Point:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "name", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 23,
	"getByName",	/*name*/
	24,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"IDL:Unit/UnitInfo:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "name", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 24,
	"getLeaderPoint",	/*name*/
	25,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Console/Point:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 25,
	"getPointSeq",	/*name*/
	26,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:gj5QlY2dALbZCLSEKoPy7Ke-T8C",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 26,
	"cancelFormation",	/*name*/
	27,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 27,
	"setLeaderSuspend",	/*name*/
	28,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 28,
	"recoveryLeaderAction",	/*name*/
	29,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 29,
	"addUnitFormation",	/*name*/
	30,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 30,
	"deleteUnitFormation",	/*name*/
	31,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 31,
	"setUnitFault",	/*name*/
	32,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 32,
	"setUnitFaultPosition",	/*name*/
	33,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uinfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 33,
	"setFormationState",	/*name*/
	34,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "fs", ilu_FALSE, ilu_In, "IDL:Console/FormationState:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 34,
	"setMissionState",	/*name*/
	35,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "msd", ilu_FALSE, ilu_In, "IDL:Console/MissionStateData:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Console_rpc__IoFns.kernelType = ilu_RegisterObjectType("rpc", "Console", ILU_NIL, "IDL:Console/rpc:1.0",
    _Console_rpc__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Console_TrapPointSeq__IoFns.kernelType = ilu_RegisterSequenceType("TrapPointSeq", "Console", ILU_NIL, "ilut:bScP2+rZUrGWcNDjgx4pjGKOoFV",
    "IDL:Console/TrapPoint:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Console_PointSeq__IoFns.kernelType = ilu_RegisterSequenceType("PointSeq", "Console", ILU_NIL, "ilut:gj5QlY2dALbZCLSEKoPy7Ke-T8C",
    "IDL:Console/Point:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Console_Message__IoFns.kernelType = type = ilu_RegisterUnionType("Message", "Console", ILU_NIL, "IDL:Console/Message:1.0",
    "IDL:Console/Operation:1.0",	/* UID of discriminant type */
    5,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "infoSeq", /* name of arm */
      "ilut:nulfTSjgo17mBovMLQKbwxXk7V-", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "OP-SetCosInfo";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "bindInfo", /* name of arm */
      "IDL:Unit/UnitInfo:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "OP-Bind";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      "unbindInfo", /* name of arm */
      "IDL:Console/UnbindData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "OP-Unbind";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 3, /* which arm */
      "tp", /* name of arm */
      "IDL:Console/TrapPoint:1.0", /* arm type */
      2, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "OP-ReportTrap";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "OP-AddTrap";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 1, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 4, /* which arm */
      "details", /* name of arm */
      "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", /* arm type */
      2, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "OP-Opened";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "OP-Closed";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 1, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_UnbindData__IoFns.kernelType = type = ilu_RegisterRecordType("UnbindData", "Console", ILU_NIL, "IDL:Console/UnbindData:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "uid", /* field name */
      "IDL:Unit/UnitID:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "details", /* field name */
      "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_Operation__IoFns.kernelType = type = ilu_RegisterEnumerationType("Operation", "Console", ILU_NIL, "IDL:Console/Operation:1.0",
    7,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "OP-SetCosInfo", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "OP-Bind", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "OP-Unbind", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "OP-Opened", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 4, /* which element */
    "OP-Closed", /* element name */
    4,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 5, /* which element */
    "OP-ReportTrap", /* element name */
    5,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 6, /* which element */
    "OP-AddTrap", /* element name */
    6,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_TrapPoint__IoFns.kernelType = type = ilu_RegisterUnionType("TrapPoint", "Console", ILU_NIL, "IDL:Console/TrapPoint:1.0",
    "IDL:Console/TrapType:1.0",	/* UID of discriminant type */
    2,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "trapPoint2D", /* name of arm */
      "IDL:Ground_Unit/TrapPoint2D:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "TrapGroundType";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "trapPoint3D", /* name of arm */
      "IDL:Air_Unit/TrapPoint3D:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "TrapAirType";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_TrapType__IoFns.kernelType = type = ilu_RegisterEnumerationType("TrapType", "Console", ILU_NIL, "IDL:Console/TrapType:1.0",
    2,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "TrapGroundType", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "TrapAirType", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_Point__IoFns.kernelType = type = ilu_RegisterUnionType("Point", "Console", ILU_NIL, "IDL:Console/Point:1.0",
    "IDL:Console/PointType:1.0",	/* UID of discriminant type */
    2,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "p2D", /* name of arm */
      "IDL:Ground_Unit/Point2D:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "PointGroundType";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "p3D", /* name of arm */
      "IDL:Air_Unit/Point3D:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "PointAirType";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_PointType__IoFns.kernelType = type = ilu_RegisterEnumerationType("PointType", "Console", ILU_NIL, "IDL:Console/PointType:1.0",
    2,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "PointGroundType", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "PointAirType", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_TrackMode__IoFns.kernelType = type = ilu_RegisterEnumerationType("TrackMode", "Console", ILU_NIL, "IDL:Console/TrackMode:1.0",
    2,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "RouteTrack", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "ObjectTrack", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_FormationType__IoFns.kernelType = type = ilu_RegisterEnumerationType("FormationType", "Console", ILU_NIL, "IDL:Console/FormationType:1.0",
    3,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "OneLine", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "Matrix", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "WildGoose", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_FormationState__IoFns.kernelType = type = ilu_RegisterEnumerationType("FormationState", "Console", ILU_NIL, "IDL:Console/FormationState:1.0",
    4,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "FormationImplement", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "FormationSuspend", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "FormationSuccess", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "FormationFail", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_MissionStateData__IoFns.kernelType = type = ilu_RegisterUnionType("MissionStateData", "Console", ILU_NIL, "IDL:Console/MissionStateData:1.0",
    "IDL:Console/MissionState:1.0",	/* UID of discriminant type */
    1,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "time", /* name of arm */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MissionSuspend";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Console_MissionState__IoFns.kernelType = type = ilu_RegisterEnumerationType("MissionState", "Console", ILU_NIL, "IDL:Console/MissionState:1.0",
    5,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "MssionImplement", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "MissionSuspend", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "MissionSuccess", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "MissionFail", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 4, /* which element */
    "MissionCancel", /* element name */
    4,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Console_rpc__IoFns.properties.object_class = _Console_rpc__ILUType;
  _ILU_C_RegisterIoFns (&_Console_rpc__IoFns);

  _Console_TrapPointSeq__IoFns.inputFn = (ILU_C_InputFn) _Console_TrapPointSeq__Input;
  _Console_TrapPointSeq__IoFns.outFn = (ILU_C_OutputFn) _Console_TrapPointSeq__Output;
  _Console_TrapPointSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Console_TrapPointSeq__SizeOf;
  _Console_TrapPointSeq__IoFns.freeFn = (ILU_C_FreeFn) Console_TrapPointSeq__Free;
  _ILU_C_RegisterIoFns (&_Console_TrapPointSeq__IoFns);

  _Console_PointSeq__IoFns.inputFn = (ILU_C_InputFn) _Console_PointSeq__Input;
  _Console_PointSeq__IoFns.outFn = (ILU_C_OutputFn) _Console_PointSeq__Output;
  _Console_PointSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Console_PointSeq__SizeOf;
  _Console_PointSeq__IoFns.freeFn = (ILU_C_FreeFn) Console_PointSeq__Free;
  _ILU_C_RegisterIoFns (&_Console_PointSeq__IoFns);

  _Console_Message__IoFns.inputFn = (ILU_C_InputFn) _Console_Message__Input;
  _Console_Message__IoFns.outFn = (ILU_C_OutputFn) _Console_Message__Output;
  _Console_Message__IoFns.sizeFn = (ILU_C_SizeFn) _Console_Message__SizeOf;
  _Console_Message__IoFns.freeFn = (ILU_C_FreeFn) Console_Message__Free;
  _ILU_C_RegisterIoFns (&_Console_Message__IoFns);

  _Console_UnbindData__IoFns.inputFn = (ILU_C_InputFn) _Console_UnbindData__Input;
  _Console_UnbindData__IoFns.outFn = (ILU_C_OutputFn) _Console_UnbindData__Output;
  _Console_UnbindData__IoFns.sizeFn = (ILU_C_SizeFn) _Console_UnbindData__SizeOf;
  _Console_UnbindData__IoFns.freeFn = (ILU_C_FreeFn) Console_UnbindData__Free;
  _ILU_C_RegisterIoFns (&_Console_UnbindData__IoFns);

  _ILU_C_RegisterIoFns (&_Console_Operation__IoFns);

  _Console_TrapPoint__IoFns.inputFn = (ILU_C_InputFn) _Console_TrapPoint__Input;
  _Console_TrapPoint__IoFns.outFn = (ILU_C_OutputFn) _Console_TrapPoint__Output;
  _Console_TrapPoint__IoFns.sizeFn = (ILU_C_SizeFn) _Console_TrapPoint__SizeOf;
  _Console_TrapPoint__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Console_TrapPoint__IoFns);

  _ILU_C_RegisterIoFns (&_Console_TrapType__IoFns);

  _Console_Point__IoFns.inputFn = (ILU_C_InputFn) _Console_Point__Input;
  _Console_Point__IoFns.outFn = (ILU_C_OutputFn) _Console_Point__Output;
  _Console_Point__IoFns.sizeFn = (ILU_C_SizeFn) _Console_Point__SizeOf;
  _Console_Point__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Console_Point__IoFns);

  _ILU_C_RegisterIoFns (&_Console_PointType__IoFns);

  _ILU_C_RegisterIoFns (&_Console_TrackMode__IoFns);

  _ILU_C_RegisterIoFns (&_Console_FormationType__IoFns);

  _ILU_C_RegisterIoFns (&_Console_FormationState__IoFns);

  _Console_MissionStateData__IoFns.inputFn = (ILU_C_InputFn) _Console_MissionStateData__Input;
  _Console_MissionStateData__IoFns.outFn = (ILU_C_OutputFn) _Console_MissionStateData__Output;
  _Console_MissionStateData__IoFns.sizeFn = (ILU_C_SizeFn) _Console_MissionStateData__SizeOf;
  _Console_MissionStateData__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Console_MissionStateData__IoFns);

  _ILU_C_RegisterIoFns (&_Console_MissionState__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

