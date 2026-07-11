/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:29:05 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Unit.h"

ilu_Class _Unit_rpc__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Unit_rpc__IoFns = { ilu_object_tk, "IDL:Unit/rpc:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_Formation__IoFns = { ilu_record_tk, "IDL:Unit/Formation:1.0", { sizeof(Unit_Formation) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitInfoSeq__IoFns = { ilu_sequence_tk, "ilut:nulfTSjgo17mBovMLQKbwxXk7V-", { sizeof(Unit_UnitInfoSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitInfo__IoFns = { ilu_record_tk, "IDL:Unit/UnitInfo:1.0", { sizeof(Unit_UnitInfo) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitMinorMode__IoFns = { ilu_enumeration_tk, "IDL:Unit/UnitMinorMode:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitMode__IoFns = { ilu_enumeration_tk, "IDL:Unit/UnitMode:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitRole__IoFns = { ilu_enumeration_tk, "IDL:Unit/UnitRole:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_ActionSeq__IoFns = { ilu_sequence_tk, "ilut:jU9woNhdbD91MlD6BEa74WZKalJ", { sizeof(Unit_ActionSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_MoveAction__IoFns = { ilu_union_tk, "IDL:Unit/MoveAction:1.0", { sizeof(Unit_MoveAction) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_MoveActionType__IoFns = { ilu_enumeration_tk, "IDL:Unit/MoveActionType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_BasicMoveActionData__IoFns = { ilu_record_tk, "IDL:Unit/BasicMoveActionData:1.0", { sizeof(Unit_BasicMoveActionData) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_ActionDuration__IoFns = { ilu_record_tk, "IDL:Unit/ActionDuration:1.0", { sizeof(Unit_ActionDuration) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_FloatSeq__IoFns = { ilu_sequence_tk, "ilut:j-DlaSOJzZAG9+d6BW6jRDasg8V", { sizeof(Unit_FloatSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_ShortSeq__IoFns = { ilu_sequence_tk, "ilut:meAF12RYW4x2Jq4Jh3mFGFgaTlW", { sizeof(Unit_ShortSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitSBHSeq__IoFns = { ilu_sequence_tk, "ilut:dP+it8jaImjeTpCavo8lYlCeZfT", { sizeof(Unit_UnitSBHSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitIDSeq__IoFns = { ilu_sequence_tk, "ilut:oo3Cq6eRuwATIJS136zmqQiqg6h", { sizeof(Unit_UnitIDSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitSBH__IoFns = { ilu_alias_tk, "IDL:Unit/UnitSBH:1.0", { sizeof(Unit_UnitSBH) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Unit_UnitID__IoFns = { ilu_alias_tk, "IDL:Unit/UnitID:1.0", { sizeof(Unit_UnitID) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class Unit_rpc__MakeClass(
  Unit_UnitID (*Unit_rpc_getID__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitSBH (*Unit_rpc_getCosNamingSBH__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Unit_rpc_getFrontUnitInfo__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRole__Impl)
     (Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMode__Impl)
     (Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMinorMode__Impl)
     (Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveAction__Impl)
     (Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveActionSeq__Impl)
     (Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setALeader__Impl)
     (Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unregisterFollower__Impl)
     (Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFollower__Impl)
     (Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unsetFollower__Impl)
     (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_addRearVehicle__Impl)
     (Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_deleteRearVehicle__Impl)
     (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFormation__Impl)
     (Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRearVehicles__Impl)
     (Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_reportDeadVehicle__Impl)
     (Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_shutDown__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_startPhotoStream__Impl)
     (Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_stopPhotoStream__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_takePicture__Impl)
     (Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Unit_rpc__ILUType;
  method_block = ilu_malloc(21 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Unit_rpc_getID__Impl;
  method_block[1] = (_ILU_C_Method) Unit_rpc_getCosNamingSBH__Impl;
  method_block[2] = (_ILU_C_Method) Unit_rpc_getFrontUnitInfo__Impl;
  method_block[3] = (_ILU_C_Method) Unit_rpc_setRole__Impl;
  method_block[4] = (_ILU_C_Method) Unit_rpc_setMode__Impl;
  method_block[5] = (_ILU_C_Method) Unit_rpc_setMinorMode__Impl;
  method_block[6] = (_ILU_C_Method) Unit_rpc_sendMoveAction__Impl;
  method_block[7] = (_ILU_C_Method) Unit_rpc_sendMoveActionSeq__Impl;
  method_block[8] = (_ILU_C_Method) Unit_rpc_setALeader__Impl;
  method_block[9] = (_ILU_C_Method) Unit_rpc_unregisterFollower__Impl;
  method_block[10] = (_ILU_C_Method) Unit_rpc_setFollower__Impl;
  method_block[11] = (_ILU_C_Method) Unit_rpc_unsetFollower__Impl;
  method_block[12] = (_ILU_C_Method) Unit_rpc_addRearVehicle__Impl;
  method_block[13] = (_ILU_C_Method) Unit_rpc_deleteRearVehicle__Impl;
  method_block[14] = (_ILU_C_Method) Unit_rpc_setFormation__Impl;
  method_block[15] = (_ILU_C_Method) Unit_rpc_setRearVehicles__Impl;
  method_block[16] = (_ILU_C_Method) Unit_rpc_reportDeadVehicle__Impl;
  method_block[17] = (_ILU_C_Method) Unit_rpc_shutDown__Impl;
  method_block[18] = (_ILU_C_Method) Unit_rpc_startPhotoStream__Impl;
  method_block[19] = (_ILU_C_Method) Unit_rpc_stopPhotoStream__Impl;
  method_block[20] = (_ILU_C_Method) Unit_rpc_takePicture__Impl;

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
Unit_UnitID Unit_rpc_getID (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitID (*_f)(Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Unit_UnitID _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Unit_UnitID (*)(Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Unit_UnitSBH Unit_rpc_getCosNamingSBH (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitSBH (*_f)(Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Unit_UnitSBH _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Unit_UnitSBH (*)(Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Unit_UnitInfo* Unit_rpc_getFrontUnitInfo (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Unit_UnitInfo* (*_f)(Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Unit_UnitInfo* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Unit_UnitInfo* (*)(Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Unit_rpc_setRole (Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitRole, Unit_UnitSBH, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitRole, Unit_UnitSBH, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, role, consoleSBH, _status));
}

CORBA_boolean Unit_rpc_setMode (Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitMode, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitMode, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, mode, _status));
}

CORBA_boolean Unit_rpc_setMinorMode (Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitMinorMode, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitMinorMode, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, minorMode, _status));
}

CORBA_boolean Unit_rpc_sendMoveAction (Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_MoveAction*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_MoveAction*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, action, _status));
}

CORBA_boolean Unit_rpc_sendMoveActionSeq (Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_ActionSeq*, CORBA_short, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_ActionSeq*, CORBA_short, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, actions, times, _status));
}

CORBA_boolean Unit_rpc_setALeader (Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitSBH, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitSBH, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 8);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, leaderSBH, _status));
}

CORBA_boolean Unit_rpc_unregisterFollower (Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 9);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, followerUID, _status));
}

CORBA_boolean Unit_rpc_setFollower (Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 10);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, ui, _status));
}

CORBA_boolean Unit_rpc_unsetFollower (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 11);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uid, _status));
}

CORBA_boolean Unit_rpc_addRearVehicle (Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 12);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, rearInfo, _status));
}

CORBA_boolean Unit_rpc_deleteRearVehicle (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 13);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uid, _status));
}

CORBA_boolean Unit_rpc_setFormation (Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_Formation*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_Formation*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 14);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, form, _status));
}

CORBA_boolean Unit_rpc_setRearVehicles (Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitInfoSeq*, CORBA_float, CORBA_float, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitInfoSeq*, CORBA_float, CORBA_float, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 15);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, rears, distance, angle, _status));
}

CORBA_boolean Unit_rpc_reportDeadVehicle (Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, Unit_UnitID, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, Unit_UnitID, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 16);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uid, details, _status));
}

CORBA_boolean Unit_rpc_shutDown (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 17);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Unit_rpc_startPhotoStream (Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, CORBA_float, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, CORBA_float, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 18);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, frequency, _status));
}

CORBA_boolean Unit_rpc_stopPhotoStream (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 19);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Unit_rpc_takePicture (Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Unit_rpc, CORBA_long, CORBA_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Unit_rpc, CORBA_long, CORBA_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Unit_rpc__ILUType, 20);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, time, procedureStartTime, _status));
}

void Unit_rpc__SetUserData (Unit_rpc self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Unit_rpc__GetUserData (Unit_rpc self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Unit_rpc__Free (Unit_rpc* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_rpc */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Unit_rpc *CORBA_sequence_Unit_rpc_allocbuf (CORBA_unsigned_long _count)
{
  Unit_rpc *_p;
  CORBA_unsigned_long _size = sizeof(Unit_rpc) * _count;

  if ((_p = (Unit_rpc *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_Formation* _Unit_Formation__Input (ilu_Call _call, Unit_Formation* _ref, ilu_Error *_err)
{
  Unit_Formation* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_Formation__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_Formation__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Unit_Formation*) ilu_MallocE (sizeof (Unit_Formation), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Unit_Formation));
    } else {
      _val = (Unit_Formation*) _ILU_C_CRCreate (s, sizeof(Unit_Formation), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Unit_Formation), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Unit_UnitIDSeq__Input (_call, &_val->robot_ids,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Unit_ShortSeq__Input (_call, &_val->leader_ids,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Unit_FloatSeq__Input (_call, &_val->distances,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Unit_FloatSeq__Input (_call, &_val->angles,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Unit_Formation__Output (ilu_Call _call, Unit_Formation* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Unit_Formation__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Unit_Formation__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Unit_Formation), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Unit_UnitIDSeq__Output(_call, (&_val->robot_ids), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Unit_ShortSeq__Output(_call, (&_val->leader_ids), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Unit_FloatSeq__Output(_call, (&_val->distances), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Unit_FloatSeq__Output(_call, (&_val->angles), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_Formation__SizeOf (ilu_Call _call, Unit_Formation* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_Formation__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_Formation__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Unit_Formation), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Unit_UnitIDSeq__SizeOf (_call, &_val->robot_ids, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Unit_ShortSeq__SizeOf (_call, &_val->leader_ids, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Unit_FloatSeq__SizeOf (_call, &_val->distances, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Unit_FloatSeq__SizeOf (_call, &_val->angles, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_Formation__Free (Unit_Formation* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_Formation */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Unit_Formation__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_Formation__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  Unit_UnitIDSeq__Free (&_val->robot_ids);
  Unit_ShortSeq__Free (&_val->leader_ids);
  Unit_FloatSeq__Free (&_val->distances);
  Unit_FloatSeq__Free (&_val->angles);
}

Unit_Formation *CORBA_sequence_Unit_Formation_allocbuf (CORBA_unsigned_long _count)
{
  Unit_Formation *_p;
  CORBA_unsigned_long _size = sizeof(Unit_Formation) * _count;

  if ((_p = (Unit_Formation *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_Formation* Unit_Formation__alloc ()
{
  return ((Unit_Formation*) CORBA_sequence_Unit_Formation_allocbuf(1));
}

Unit_UnitInfoSeq* _Unit_UnitInfoSeq__Input (ilu_Call _call, Unit_UnitInfoSeq* _ref, ilu_Error *_err)
{
  Unit_UnitInfoSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Unit_UnitInfo _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Unit_UnitInfoSeq*) ilu_MallocE(sizeof (Unit_UnitInfoSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Unit_UnitInfoSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Unit_UnitInfoSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Unit_UnitInfo), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Unit_UnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Unit_UnitInfo__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Unit_UnitInfoSeq_Append (_val, &_tmp, _err);
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

void _Unit_UnitInfoSeq__Output (ilu_Call _call, Unit_UnitInfoSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_UnitInfoSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Unit_UnitInfo), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Unit_UnitInfo), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Unit_UnitInfo *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Unit_UnitInfo__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_UnitInfoSeq__SizeOf (ilu_Call _call, Unit_UnitInfoSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_UnitInfoSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Unit_UnitInfo), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Unit_UnitInfo), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Unit_UnitInfo *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Unit_UnitInfo__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_UnitInfoSeq__Free (Unit_UnitInfoSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_UnitInfoSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Unit_UnitInfo)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Unit_UnitInfo)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Unit_UnitInfo))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          Unit_UnitInfo__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK Unit_UnitInfoSeq__Free (Unit_UnitInfoSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Unit_UnitInfoSeq *CORBA_sequence_Unit_UnitInfoSeq_allocbuf (CORBA_unsigned_long _count)
{
  Unit_UnitInfoSeq *_p;
  CORBA_unsigned_long _size = sizeof(Unit_UnitInfoSeq) * _count;

  if ((_p = (Unit_UnitInfoSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_UnitInfoSeq* Unit_UnitInfoSeq__alloc ()
{
  return ((Unit_UnitInfoSeq*) CORBA_sequence_Unit_UnitInfoSeq_allocbuf(1));
}

Unit_UnitInfo* _Unit_UnitInfo__Input (ilu_Call _call, Unit_UnitInfo* _ref, ilu_Error *_err)
{
  Unit_UnitInfo* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_UnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_UnitInfo__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Unit_UnitInfo*) ilu_MallocE (sizeof (Unit_UnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Unit_UnitInfo));
    } else {
      _val = (Unit_UnitInfo*) _ILU_C_CRCreate (s, sizeof(Unit_UnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Unit_UnitInfo), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->uid, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->sbh, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Unit_UnitInfo__Output (ilu_Call _call, Unit_UnitInfo* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Unit_UnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Unit_UnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Unit_UnitInfo), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ilu_CString__Output (_call, (_val->uid), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _ilu_CString__Output (_call, (_val->sbh), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_UnitInfo__SizeOf (ilu_Call _call, Unit_UnitInfo* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_UnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_UnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Unit_UnitInfo), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->uid, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->sbh, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_UnitInfo__Free (Unit_UnitInfo* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_UnitInfo */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Unit_UnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_UnitInfo__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  ilu_CString__Free (&_val->uid);
  ilu_CString__Free (&_val->sbh);
}

Unit_UnitInfo *CORBA_sequence_Unit_UnitInfo_allocbuf (CORBA_unsigned_long _count)
{
  Unit_UnitInfo *_p;
  CORBA_unsigned_long _size = sizeof(Unit_UnitInfo) * _count;

  if ((_p = (Unit_UnitInfo *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_UnitInfo* Unit_UnitInfo__alloc ()
{
  return ((Unit_UnitInfo*) CORBA_sequence_Unit_UnitInfo_allocbuf(1));
}

Unit_UnitMinorMode *CORBA_sequence_Unit_UnitMinorMode_allocbuf (CORBA_unsigned_long _count)
{
  Unit_UnitMinorMode *_p;
  CORBA_unsigned_long _size = sizeof(Unit_UnitMinorMode) * _count;

  if ((_p = (Unit_UnitMinorMode *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_UnitMode *CORBA_sequence_Unit_UnitMode_allocbuf (CORBA_unsigned_long _count)
{
  Unit_UnitMode *_p;
  CORBA_unsigned_long _size = sizeof(Unit_UnitMode) * _count;

  if ((_p = (Unit_UnitMode *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_UnitRole *CORBA_sequence_Unit_UnitRole_allocbuf (CORBA_unsigned_long _count)
{
  Unit_UnitRole *_p;
  CORBA_unsigned_long _size = sizeof(Unit_UnitRole) * _count;

  if ((_p = (Unit_UnitRole *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_ActionSeq* _Unit_ActionSeq__Input (ilu_Call _call, Unit_ActionSeq* _ref, ilu_Error *_err)
{
  Unit_ActionSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Unit_MoveAction _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Unit_ActionSeq*) ilu_MallocE(sizeof (Unit_ActionSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Unit_ActionSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Unit_ActionSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Unit_MoveAction), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Unit_MoveAction), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Unit_MoveAction__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Unit_ActionSeq_Append (_val, &_tmp, _err);
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

void _Unit_ActionSeq__Output (ilu_Call _call, Unit_ActionSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_ActionSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Unit_MoveAction), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Unit_MoveAction), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Unit_MoveAction *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Unit_MoveAction__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_ActionSeq__SizeOf (ilu_Call _call, Unit_ActionSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_ActionSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Unit_MoveAction), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Unit_MoveAction), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Unit_MoveAction *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Unit_MoveAction__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_ActionSeq__Free (Unit_ActionSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_ActionSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Unit_MoveAction)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Unit_MoveAction)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Unit_MoveAction))) */ ) {
    //ilu_DebugPrintf("OK Unit_ActionSeq__Free (Unit_ActionSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Unit_ActionSeq *CORBA_sequence_Unit_ActionSeq_allocbuf (CORBA_unsigned_long _count)
{
  Unit_ActionSeq *_p;
  CORBA_unsigned_long _size = sizeof(Unit_ActionSeq) * _count;

  if ((_p = (Unit_ActionSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_ActionSeq* Unit_ActionSeq__alloc ()
{
  return ((Unit_ActionSeq*) CORBA_sequence_Unit_ActionSeq_allocbuf(1));
}

Unit_MoveAction* _Unit_MoveAction__Input (ilu_Call _call, Unit_MoveAction* _ref, ilu_Error *_err)
{
  Unit_MoveAction* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Unit_MoveAction), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Unit_MoveAction*) ilu_MallocE(sizeof (Unit_MoveAction), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Unit_MoveAction));
  };
  switch (tag) {
    case Unit_MA_GoUp:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.goUpData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoDown:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.goDownData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoAhead:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.goAheadData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoBackward:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.goBackwardData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoLeft:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.goLeftData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoRight:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.goRightData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_TurnLeft:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.turnLeftData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_TurnRight:
      (void) _Unit_BasicMoveActionData__Input (_call, &_val->_u.turnRightData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_Stop:
      (void) _Unit_ActionDuration__Input (_call, &_val->_u.stopData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (Unit_MoveActionType) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Unit_MoveAction__Output (ilu_Call _call, Unit_MoveAction* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Unit_MoveAction), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Unit_MA_GoUp:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.goUpData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoDown:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.goDownData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoAhead:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.goAheadData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoBackward:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.goBackwardData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoLeft:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.goLeftData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_GoRight:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.goRightData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_TurnLeft:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.turnLeftData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_TurnRight:
      _Unit_BasicMoveActionData__Output(_call, &_val->_u.turnRightData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Unit_MA_Stop:
      _Unit_ActionDuration__Output(_call, &_val->_u.stopData, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Unit_MoveAction__SizeOf (ilu_Call _call, Unit_MoveAction* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Unit_MoveAction), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Unit_MA_GoUp:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.goUpData, _err);
      break;
    case Unit_MA_GoDown:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.goDownData, _err);
      break;
    case Unit_MA_GoAhead:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.goAheadData, _err);
      break;
    case Unit_MA_GoBackward:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.goBackwardData, _err);
      break;
    case Unit_MA_GoLeft:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.goLeftData, _err);
      break;
    case Unit_MA_GoRight:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.goRightData, _err);
      break;
    case Unit_MA_TurnLeft:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.turnLeftData, _err);
      break;
    case Unit_MA_TurnRight:
      size += _Unit_BasicMoveActionData__SizeOf (_call, &_val->_u.turnRightData, _err);
      break;
    case Unit_MA_Stop:
      size += _Unit_ActionDuration__SizeOf (_call, &_val->_u.stopData, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Unit_MoveAction *CORBA_sequence_Unit_MoveAction_allocbuf (CORBA_unsigned_long _count)
{
  Unit_MoveAction *_p;
  CORBA_unsigned_long _size = sizeof(Unit_MoveAction) * _count;

  if ((_p = (Unit_MoveAction *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_MoveAction* Unit_MoveAction__alloc ()
{
  return ((Unit_MoveAction*) CORBA_sequence_Unit_MoveAction_allocbuf(1));
}

Unit_MoveActionType *CORBA_sequence_Unit_MoveActionType_allocbuf (CORBA_unsigned_long _count)
{
  Unit_MoveActionType *_p;
  CORBA_unsigned_long _size = sizeof(Unit_MoveActionType) * _count;

  if ((_p = (Unit_MoveActionType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_BasicMoveActionData* _Unit_BasicMoveActionData__Input (ilu_Call _call, Unit_BasicMoveActionData* _ref, ilu_Error *_err)
{
  Unit_BasicMoveActionData* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_BasicMoveActionData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_BasicMoveActionData__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Unit_BasicMoveActionData*) ilu_MallocE (sizeof (Unit_BasicMoveActionData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Unit_BasicMoveActionData));
    } else {
      _val = (Unit_BasicMoveActionData*) _ILU_C_CRCreate (s, sizeof(Unit_BasicMoveActionData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Unit_BasicMoveActionData), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->speed, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Unit_ActionDuration__Input (_call, &_val->duration,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Unit_BasicMoveActionData__Output (ilu_Call _call, Unit_BasicMoveActionData* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Unit_BasicMoveActionData__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Unit_BasicMoveActionData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Unit_BasicMoveActionData), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->speed), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Unit_ActionDuration__Output(_call, (&_val->duration), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_BasicMoveActionData__SizeOf (ilu_Call _call, Unit_BasicMoveActionData* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_BasicMoveActionData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_BasicMoveActionData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Unit_BasicMoveActionData), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->speed, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Unit_ActionDuration__SizeOf (_call, &_val->duration, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Unit_BasicMoveActionData *CORBA_sequence_Unit_BasicMoveActionData_allocbuf (CORBA_unsigned_long _count)
{
  Unit_BasicMoveActionData *_p;
  CORBA_unsigned_long _size = sizeof(Unit_BasicMoveActionData) * _count;

  if ((_p = (Unit_BasicMoveActionData *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_BasicMoveActionData* Unit_BasicMoveActionData__alloc ()
{
  return ((Unit_BasicMoveActionData*) CORBA_sequence_Unit_BasicMoveActionData_allocbuf(1));
}

Unit_ActionDuration* _Unit_ActionDuration__Input (ilu_Call _call, Unit_ActionDuration* _ref, ilu_Error *_err)
{
  Unit_ActionDuration* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_ActionDuration__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_ActionDuration__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Unit_ActionDuration*) ilu_MallocE (sizeof (Unit_ActionDuration), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Unit_ActionDuration));
    } else {
      _val = (Unit_ActionDuration*) _ILU_C_CRCreate (s, sizeof(Unit_ActionDuration), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Unit_ActionDuration), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->keep, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &_val->ft_s, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &_val->ft_t, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Unit_ActionDuration__Output (ilu_Call _call, Unit_ActionDuration* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Unit_ActionDuration__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Unit_ActionDuration__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Unit_ActionDuration), _err);
    if (ILU_ERRNOK(*_err)) return;
  ILU_C_OutputBoolean(_call, (_val->keep), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputCardinal (_call, (_val->ft_s), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputCardinal (_call, (_val->ft_t), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_ActionDuration__SizeOf (ilu_Call _call, Unit_ActionDuration* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Unit_ActionDuration__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Unit_ActionDuration__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Unit_ActionDuration), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->keep, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfCardinal(_call, _val->ft_s, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfCardinal(_call, _val->ft_t, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Unit_ActionDuration *CORBA_sequence_Unit_ActionDuration_allocbuf (CORBA_unsigned_long _count)
{
  Unit_ActionDuration *_p;
  CORBA_unsigned_long _size = sizeof(Unit_ActionDuration) * _count;

  if ((_p = (Unit_ActionDuration *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_ActionDuration* Unit_ActionDuration__alloc ()
{
  return ((Unit_ActionDuration*) CORBA_sequence_Unit_ActionDuration_allocbuf(1));
}

Unit_FloatSeq* _Unit_FloatSeq__Input (ilu_Call _call, Unit_FloatSeq* _ref, ilu_Error *_err)
{
  Unit_FloatSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  CORBA_float _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Unit_FloatSeq*) ilu_MallocE(sizeof (Unit_FloatSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Unit_FloatSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Unit_FloatSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CORBA_float), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(CORBA_float), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      ilu_InputShortReal (_call, &_tmp, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Unit_FloatSeq_Append (_val, _tmp, _err);
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

void _Unit_FloatSeq__Output (ilu_Call _call, Unit_FloatSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_FloatSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_float), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(CORBA_float), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    CORBA_float *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        ilu_OutputShortReal(_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_FloatSeq__SizeOf (ilu_Call _call, Unit_FloatSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_FloatSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_float), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(CORBA_float), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    CORBA_float *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += ilu_SizeOfShortReal(_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_FloatSeq__Free (Unit_FloatSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_FloatSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_float)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_float)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_float))) */ ) {
    //ilu_DebugPrintf("OK Unit_FloatSeq__Free (Unit_FloatSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Unit_FloatSeq *CORBA_sequence_Unit_FloatSeq_allocbuf (CORBA_unsigned_long _count)
{
  Unit_FloatSeq *_p;
  CORBA_unsigned_long _size = sizeof(Unit_FloatSeq) * _count;

  if ((_p = (Unit_FloatSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_FloatSeq* Unit_FloatSeq__alloc ()
{
  return ((Unit_FloatSeq*) CORBA_sequence_Unit_FloatSeq_allocbuf(1));
}

Unit_ShortSeq* _Unit_ShortSeq__Input (ilu_Call _call, Unit_ShortSeq* _ref, ilu_Error *_err)
{
  Unit_ShortSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  CORBA_short _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Unit_ShortSeq*) ilu_MallocE(sizeof (Unit_ShortSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Unit_ShortSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Unit_ShortSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CORBA_short), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(CORBA_short), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      ilu_InputShortInteger (_call, &_tmp, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Unit_ShortSeq_Append (_val, _tmp, _err);
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

void _Unit_ShortSeq__Output (ilu_Call _call, Unit_ShortSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_ShortSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_short), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(CORBA_short), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    CORBA_short *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        ilu_OutputShortInteger (_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_ShortSeq__SizeOf (ilu_Call _call, Unit_ShortSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_ShortSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_short), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(CORBA_short), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    CORBA_short *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += ilu_SizeOfShortInteger(_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_ShortSeq__Free (Unit_ShortSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_ShortSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_short)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_short)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_short))) */ ) {
    //ilu_DebugPrintf("OK Unit_ShortSeq__Free (Unit_ShortSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Unit_ShortSeq *CORBA_sequence_Unit_ShortSeq_allocbuf (CORBA_unsigned_long _count)
{
  Unit_ShortSeq *_p;
  CORBA_unsigned_long _size = sizeof(Unit_ShortSeq) * _count;

  if ((_p = (Unit_ShortSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_ShortSeq* Unit_ShortSeq__alloc ()
{
  return ((Unit_ShortSeq*) CORBA_sequence_Unit_ShortSeq_allocbuf(1));
}

Unit_UnitSBHSeq* _Unit_UnitSBHSeq__Input (ilu_Call _call, Unit_UnitSBHSeq* _ref, ilu_Error *_err)
{
  Unit_UnitSBHSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  ilu_CString _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Unit_UnitSBHSeq*) ilu_MallocE(sizeof (Unit_UnitSBHSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Unit_UnitSBHSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Unit_UnitSBHSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(ilu_CString), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(ilu_CString), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _ilu_CString__Input (_call, &_tmp, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Unit_UnitSBHSeq_Append (_val, _tmp, _err);
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

void _Unit_UnitSBHSeq__Output (ilu_Call _call, Unit_UnitSBHSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_UnitSBHSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(ilu_CString), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(ilu_CString), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    ilu_CString *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _ilu_CString__Output (_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_UnitSBHSeq__SizeOf (ilu_Call _call, Unit_UnitSBHSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_UnitSBHSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(ilu_CString), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Unit_UnitSBH), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Unit_UnitSBH *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _ilu_CString__SizeOf(_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_UnitSBHSeq__Free (Unit_UnitSBHSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_UnitSBHSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(ilu_CString)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(ilu_CString)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(ilu_CString))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          ilu_CString__Free ((ilu_CString *) &_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK Unit_UnitSBHSeq__Free (Unit_UnitSBHSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Unit_UnitSBHSeq *CORBA_sequence_Unit_UnitSBHSeq_allocbuf (CORBA_unsigned_long _count)
{
  Unit_UnitSBHSeq *_p;
  CORBA_unsigned_long _size = sizeof(Unit_UnitSBHSeq) * _count;

  if ((_p = (Unit_UnitSBHSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_UnitSBHSeq* Unit_UnitSBHSeq__alloc ()
{
  return ((Unit_UnitSBHSeq*) CORBA_sequence_Unit_UnitSBHSeq_allocbuf(1));
}

Unit_UnitIDSeq* _Unit_UnitIDSeq__Input (ilu_Call _call, Unit_UnitIDSeq* _ref, ilu_Error *_err)
{
  Unit_UnitIDSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  ilu_CString _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Unit_UnitIDSeq*) ilu_MallocE(sizeof (Unit_UnitIDSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Unit_UnitIDSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Unit_UnitIDSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(ilu_CString), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(ilu_CString), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _ilu_CString__Input (_call, &_tmp, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Unit_UnitIDSeq_Append (_val, _tmp, _err);
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

void _Unit_UnitIDSeq__Output (ilu_Call _call, Unit_UnitIDSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_UnitIDSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(ilu_CString), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(ilu_CString), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    ilu_CString *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _ilu_CString__Output (_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Unit_UnitIDSeq__SizeOf (ilu_Call _call, Unit_UnitIDSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Unit_UnitIDSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(ilu_CString), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Unit_UnitID), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Unit_UnitID *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _ilu_CString__SizeOf(_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Unit_UnitIDSeq__Free (Unit_UnitIDSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Unit_UnitIDSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(ilu_CString)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(ilu_CString)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(ilu_CString))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          ilu_CString__Free ((ilu_CString *) &_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK Unit_UnitIDSeq__Free (Unit_UnitIDSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Unit_UnitIDSeq *CORBA_sequence_Unit_UnitIDSeq_allocbuf (CORBA_unsigned_long _count)
{
  Unit_UnitIDSeq *_p;
  CORBA_unsigned_long _size = sizeof(Unit_UnitIDSeq) * _count;

  if ((_p = (Unit_UnitIDSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Unit_UnitIDSeq* Unit_UnitIDSeq__alloc ()
{
  return ((Unit_UnitIDSeq*) CORBA_sequence_Unit_UnitIDSeq_allocbuf(1));
}

void Unit_UnitInfoSeq_Every (Unit_UnitInfoSeq *h, void (*f)(Unit_UnitInfo*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Unit_UnitInfo), (void *) data);
}

void Unit_UnitInfoSeq_Append (Unit_UnitInfoSeq *h, Unit_UnitInfo* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_UnitInfo), err);
}

void Unit_UnitInfoSeq_Push (Unit_UnitInfoSeq *h, Unit_UnitInfo* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_UnitInfo));
}

void Unit_UnitInfoSeq_Pop (Unit_UnitInfoSeq *h, Unit_UnitInfo* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_UnitInfo));
}

CORBA_unsigned_long Unit_UnitInfoSeq_Length (Unit_UnitInfoSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Unit_UnitInfo * Unit_UnitInfoSeq_Nth (Unit_UnitInfoSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Unit_UnitInfoSeq * Unit_UnitInfoSeq_Create (CORBA_unsigned_long sz, Unit_UnitInfo* p)
{
  Unit_UnitInfoSeq *s;
  s = (Unit_UnitInfoSeq *) ilu_malloc(sizeof(Unit_UnitInfoSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Unit_UnitInfoSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Unit_UnitInfo *) ilu_malloc(sz * sizeof(Unit_UnitInfo))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Unit_UnitInfo));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Unit_UnitInfoSeq_Init (Unit_UnitInfoSeq *s, CORBA_unsigned_long sz, Unit_UnitInfo* p)
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
    s->_buffer = (Unit_UnitInfo *) ilu_malloc (sz * sizeof (Unit_UnitInfo));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Unit_UnitInfo)); }}
  else
    s->_buffer = p;
  return;
}

void Unit_ActionSeq_Every (Unit_ActionSeq *h, void (*f)(Unit_MoveAction*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Unit_MoveAction), (void *) data);
}

void Unit_ActionSeq_Append (Unit_ActionSeq *h, Unit_MoveAction* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_MoveAction), err);
}

void Unit_ActionSeq_Push (Unit_ActionSeq *h, Unit_MoveAction* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_MoveAction));
}

void Unit_ActionSeq_Pop (Unit_ActionSeq *h, Unit_MoveAction* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_MoveAction));
}

CORBA_unsigned_long Unit_ActionSeq_Length (Unit_ActionSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Unit_MoveAction * Unit_ActionSeq_Nth (Unit_ActionSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Unit_ActionSeq * Unit_ActionSeq_Create (CORBA_unsigned_long sz, Unit_MoveAction* p)
{
  Unit_ActionSeq *s;
  s = (Unit_ActionSeq *) ilu_malloc(sizeof(Unit_ActionSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Unit_ActionSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Unit_MoveAction *) ilu_malloc(sz * sizeof(Unit_MoveAction))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Unit_MoveAction));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Unit_ActionSeq_Init (Unit_ActionSeq *s, CORBA_unsigned_long sz, Unit_MoveAction* p)
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
    s->_buffer = (Unit_MoveAction *) ilu_malloc (sz * sizeof (Unit_MoveAction));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Unit_MoveAction)); }}
  else
    s->_buffer = p;
  return;
}

void Unit_FloatSeq_Every (Unit_FloatSeq *h, void (*f)(CORBA_float *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_float), (void *) data);
}

void Unit_FloatSeq_Append (Unit_FloatSeq *h, CORBA_float item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_float), err);
}

void Unit_FloatSeq_Push (Unit_FloatSeq *h, CORBA_float item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_float));
}

void Unit_FloatSeq_Pop (Unit_FloatSeq *h, CORBA_float *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_float));
}

CORBA_unsigned_long Unit_FloatSeq_Length (Unit_FloatSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_float * Unit_FloatSeq_Nth (Unit_FloatSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Unit_FloatSeq * Unit_FloatSeq_Create (CORBA_unsigned_long sz, CORBA_float *p)
{
  Unit_FloatSeq *s;
  s = (Unit_FloatSeq *) ilu_malloc(sizeof(Unit_FloatSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Unit_FloatSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_float *) ilu_malloc(sz * sizeof(CORBA_float))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_float));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Unit_FloatSeq_Init (Unit_FloatSeq *s, CORBA_unsigned_long sz, CORBA_float *p)
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
    s->_buffer = (CORBA_float *) ilu_malloc (sz * sizeof (CORBA_float));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CORBA_float)); }}
  else
    s->_buffer = p;
  return;
}

void Unit_ShortSeq_Every (Unit_ShortSeq *h, void (*f)(CORBA_short *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_short), (void *) data);
}

void Unit_ShortSeq_Append (Unit_ShortSeq *h, CORBA_short item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_short), err);
}

void Unit_ShortSeq_Push (Unit_ShortSeq *h, CORBA_short item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_short));
}

void Unit_ShortSeq_Pop (Unit_ShortSeq *h, CORBA_short *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_short));
}

CORBA_unsigned_long Unit_ShortSeq_Length (Unit_ShortSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_short * Unit_ShortSeq_Nth (Unit_ShortSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Unit_ShortSeq * Unit_ShortSeq_Create (CORBA_unsigned_long sz, CORBA_short *p)
{
  Unit_ShortSeq *s;
  s = (Unit_ShortSeq *) ilu_malloc(sizeof(Unit_ShortSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Unit_ShortSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_short *) ilu_malloc(sz * sizeof(CORBA_short))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_short));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Unit_ShortSeq_Init (Unit_ShortSeq *s, CORBA_unsigned_long sz, CORBA_short *p)
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
    s->_buffer = (CORBA_short *) ilu_malloc (sz * sizeof (CORBA_short));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CORBA_short)); }}
  else
    s->_buffer = p;
  return;
}

void Unit_UnitSBHSeq_Every (Unit_UnitSBHSeq *h, void (*f)(Unit_UnitSBH *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Unit_UnitSBH), (void *) data);
}

void Unit_UnitSBHSeq_Append (Unit_UnitSBHSeq *h, Unit_UnitSBH item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Unit_UnitSBH), err);
}

void Unit_UnitSBHSeq_Push (Unit_UnitSBHSeq *h, Unit_UnitSBH item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Unit_UnitSBH));
}

void Unit_UnitSBHSeq_Pop (Unit_UnitSBHSeq *h, Unit_UnitSBH *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_UnitSBH));
}

CORBA_unsigned_long Unit_UnitSBHSeq_Length (Unit_UnitSBHSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Unit_UnitSBH * Unit_UnitSBHSeq_Nth (Unit_UnitSBHSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Unit_UnitSBHSeq * Unit_UnitSBHSeq_Create (CORBA_unsigned_long sz, Unit_UnitSBH *p)
{
  Unit_UnitSBHSeq *s;
  s = (Unit_UnitSBHSeq *) ilu_malloc(sizeof(Unit_UnitSBHSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Unit_UnitSBHSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Unit_UnitSBH *) ilu_malloc(sz * sizeof(Unit_UnitSBH))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Unit_UnitSBH));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Unit_UnitSBHSeq_Init (Unit_UnitSBHSeq *s, CORBA_unsigned_long sz, Unit_UnitSBH *p)
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
    s->_buffer = (Unit_UnitSBH *) ilu_malloc (sz * sizeof (Unit_UnitSBH));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Unit_UnitSBH)); }}
  else
    s->_buffer = p;
  return;
}

void Unit_UnitIDSeq_Every (Unit_UnitIDSeq *h, void (*f)(Unit_UnitID *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Unit_UnitID), (void *) data);
}

void Unit_UnitIDSeq_Append (Unit_UnitIDSeq *h, Unit_UnitID item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Unit_UnitID), err);
}

void Unit_UnitIDSeq_Push (Unit_UnitIDSeq *h, Unit_UnitID item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Unit_UnitID));
}

void Unit_UnitIDSeq_Pop (Unit_UnitIDSeq *h, Unit_UnitID *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Unit_UnitID));
}

CORBA_unsigned_long Unit_UnitIDSeq_Length (Unit_UnitIDSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Unit_UnitID * Unit_UnitIDSeq_Nth (Unit_UnitIDSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Unit_UnitIDSeq * Unit_UnitIDSeq_Create (CORBA_unsigned_long sz, Unit_UnitID *p)
{
  Unit_UnitIDSeq *s;
  s = (Unit_UnitIDSeq *) ilu_malloc(sizeof(Unit_UnitIDSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Unit_UnitIDSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Unit_UnitID *) ilu_malloc(sz * sizeof(Unit_UnitID))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Unit_UnitID));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Unit_UnitIDSeq_Init (Unit_UnitIDSeq *s, CORBA_unsigned_long sz, Unit_UnitID *p)
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
    s->_buffer = (Unit_UnitID *) ilu_malloc (sz * sizeof (Unit_UnitID));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Unit_UnitID)); }}
  else
    s->_buffer = p;
  return;
}

void _Unit__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Unit", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	"IDL:omg.org/CORBA/Object:1.0",
	NULL};
    cl = ilu_DefineObjectType("Unit.rpc",	/*name*/
	NULL,	/*no brand*/
	"IDL:Unit/rpc:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	21,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Unit_rpc__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"getID",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Unit/UnitID:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"getCosNamingSBH",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Unit/UnitSBH:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"getFrontUnitInfo",	/*name*/
	3,	/*id*/
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
    m = ilu_DefineMethod(cl, 3,
	"setRole",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "role", ilu_FALSE, ilu_In, "IDL:Unit/UnitRole:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "consoleSBH", ilu_FALSE, ilu_In, "IDL:Unit/UnitSBH:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"setMode",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "mode", ilu_FALSE, ilu_In, "IDL:Unit/UnitMode:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 5,
	"setMinorMode",	/*name*/
	6,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "minorMode", ilu_FALSE, ilu_In, "IDL:Unit/UnitMinorMode:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 6,
	"sendMoveAction",	/*name*/
	7,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "action", ilu_FALSE, ilu_In, "IDL:Unit/MoveAction:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 7,
	"sendMoveActionSeq",	/*name*/
	8,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "actions", ilu_FALSE, ilu_In, "ilut:jU9woNhdbD91MlD6BEa74WZKalJ", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "times", ilu_FALSE, ilu_In, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 8,
	"setALeader",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "leaderSBH", ilu_FALSE, ilu_In, "IDL:Unit/UnitSBH:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 9,
	"unregisterFollower",	/*name*/
	10,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "followerUID", ilu_FALSE, ilu_In, "IDL:Unit/UnitID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 10,
	"setFollower",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "ui", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 11,
	"unsetFollower",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "uid", ilu_FALSE, ilu_In, "IDL:Unit/UnitID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 12,
	"addRearVehicle",	/*name*/
	13,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "rearInfo", ilu_FALSE, ilu_In, "IDL:Unit/UnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 13,
	"deleteRearVehicle",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "uid", ilu_FALSE, ilu_In, "IDL:Unit/UnitID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 14,
	"setFormation",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "form", ilu_FALSE, ilu_In, "IDL:Unit/Formation:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 15,
	"setRearVehicles",	/*name*/
	16,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "rears", ilu_FALSE, ilu_In, "ilut:nulfTSjgo17mBovMLQKbwxXk7V-", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "distance", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "angle", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 16,
	"reportDeadVehicle",	/*name*/
	17,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
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
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 17,
	"shutDown",	/*name*/
	18,	/*id*/
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
    m = ilu_DefineMethod(cl, 18,
	"startPhotoStream",	/*name*/
	19,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "frequency", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 19,
	"stopPhotoStream",	/*name*/
	20,	/*id*/
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
    m = ilu_DefineMethod(cl, 20,
	"takePicture",	/*name*/
	21,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "time", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "procedureStartTime", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Unit_rpc__IoFns.kernelType = ilu_RegisterObjectType("rpc", "Unit", ILU_NIL, "IDL:Unit/rpc:1.0",
    _Unit_rpc__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Unit_Formation__IoFns.kernelType = type = ilu_RegisterRecordType("Formation", "Unit", ILU_NIL, "IDL:Unit/Formation:1.0",
    4,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "robot-ids", /* field name */
      "ilut:oo3Cq6eRuwATIJS136zmqQiqg6h", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "leader-ids", /* field name */
      "ilut:meAF12RYW4x2Jq4Jh3mFGFgaTlW", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "distances", /* field name */
      "ilut:j-DlaSOJzZAG9+d6BW6jRDasg8V", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "angles", /* field name */
      "ilut:j-DlaSOJzZAG9+d6BW6jRDasg8V", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_UnitInfoSeq__IoFns.kernelType = ilu_RegisterSequenceType("UnitInfoSeq", "Unit", ILU_NIL, "ilut:nulfTSjgo17mBovMLQKbwxXk7V-",
    "IDL:Unit/UnitInfo:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Unit_UnitInfo__IoFns.kernelType = type = ilu_RegisterRecordType("UnitInfo", "Unit", ILU_NIL, "IDL:Unit/UnitInfo:1.0",
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
      "sbh", /* field name */
      "IDL:Unit/UnitSBH:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_UnitMinorMode__IoFns.kernelType = type = ilu_RegisterEnumerationType("UnitMinorMode", "Unit", ILU_NIL, "IDL:Unit/UnitMinorMode:1.0",
    3,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "UMM-None", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "UMM-FW-Object", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "UMM-FW-Track", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_UnitMode__IoFns.kernelType = type = ilu_RegisterEnumerationType("UnitMode", "Unit", ILU_NIL, "IDL:Unit/UnitMode:1.0",
    4,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "UM-None", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "UM-Follow", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "UM-Imitate", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "UM-Mate", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_UnitRole__IoFns.kernelType = type = ilu_RegisterEnumerationType("UnitRole", "Unit", ILU_NIL, "IDL:Unit/UnitRole:1.0",
    3,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "UR-Leader", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "UR-Follower", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "UR-None", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_ActionSeq__IoFns.kernelType = ilu_RegisterSequenceType("ActionSeq", "Unit", ILU_NIL, "ilut:jU9woNhdbD91MlD6BEa74WZKalJ",
    "IDL:Unit/MoveAction:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Unit_MoveAction__IoFns.kernelType = type = ilu_RegisterUnionType("MoveAction", "Unit", ILU_NIL, "IDL:Unit/MoveAction:1.0",
    "IDL:Unit/MoveActionType:1.0",	/* UID of discriminant type */
    9,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "goUpData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-GoUp";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "goDownData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-GoDown";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      "goAheadData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-GoAhead";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 3, /* which arm */
      "goBackwardData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-GoBackward";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 4, /* which arm */
      "goLeftData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-GoLeft";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 5, /* which arm */
      "goRightData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-GoRight";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 6, /* which arm */
      "turnLeftData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-TurnLeft";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 7, /* which arm */
      "turnRightData", /* name of arm */
      "IDL:Unit/BasicMoveActionData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-TurnRight";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 8, /* which arm */
      "stopData", /* name of arm */
      "IDL:Unit/ActionDuration:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "MA-Stop";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_MoveActionType__IoFns.kernelType = type = ilu_RegisterEnumerationType("MoveActionType", "Unit", ILU_NIL, "IDL:Unit/MoveActionType:1.0",
    15,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "MA-GoAhead", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "MA-GoBackward", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "MA-TurnLeft", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "MA-TurnRight", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 4, /* which element */
    "MA-Stop", /* element name */
    4,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 5, /* which element */
    "MA-GoUp", /* element name */
    5,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 6, /* which element */
    "MA-GoDown", /* element name */
    6,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 7, /* which element */
    "MA-GoLeft", /* element name */
    7,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 8, /* which element */
    "MA-GoRight", /* element name */
    8,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 9, /* which element */
    "MA-TakeOff", /* element name */
    9,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 10, /* which element */
    "MA-Land", /* element name */
    10,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 11, /* which element */
    "MA-LandConfirm", /* element name */
    11,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 12, /* which element */
    "MA-ForceLanding", /* element name */
    12,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 13, /* which element */
    "MA-Lock", /* element name */
    13,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 14, /* which element */
    "MA-Unlock", /* element name */
    14,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_BasicMoveActionData__IoFns.kernelType = type = ilu_RegisterRecordType("BasicMoveActionData", "Unit", ILU_NIL, "IDL:Unit/BasicMoveActionData:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "speed", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "duration", /* field name */
      "IDL:Unit/ActionDuration:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_ActionDuration__IoFns.kernelType = type = ilu_RegisterRecordType("ActionDuration", "Unit", ILU_NIL, "IDL:Unit/ActionDuration:1.0",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "keep", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "ft-s", /* field name */
      "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "ft-t", /* field name */
      "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Unit_FloatSeq__IoFns.kernelType = ilu_RegisterSequenceType("FloatSeq", "Unit", ILU_NIL, "ilut:j-DlaSOJzZAG9+d6BW6jRDasg8V",
    "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Unit_ShortSeq__IoFns.kernelType = ilu_RegisterSequenceType("ShortSeq", "Unit", ILU_NIL, "ilut:meAF12RYW4x2Jq4Jh3mFGFgaTlW",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Unit_UnitSBHSeq__IoFns.kernelType = ilu_RegisterSequenceType("UnitSBHSeq", "Unit", ILU_NIL, "ilut:dP+it8jaImjeTpCavo8lYlCeZfT",
    "IDL:Unit/UnitSBH:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Unit_UnitIDSeq__IoFns.kernelType = ilu_RegisterSequenceType("UnitIDSeq", "Unit", ILU_NIL, "ilut:oo3Cq6eRuwATIJS136zmqQiqg6h",
    "IDL:Unit/UnitID:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("UnitSBH", "Unit", ILU_NIL, "IDL:Unit/UnitSBH:1.0",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("UnitID", "Unit", ILU_NIL, "IDL:Unit/UnitID:1.0",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Unit_rpc__IoFns.properties.object_class = _Unit_rpc__ILUType;
  _ILU_C_RegisterIoFns (&_Unit_rpc__IoFns);

  _Unit_Formation__IoFns.inputFn = (ILU_C_InputFn) _Unit_Formation__Input;
  _Unit_Formation__IoFns.outFn = (ILU_C_OutputFn) _Unit_Formation__Output;
  _Unit_Formation__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_Formation__SizeOf;
  _Unit_Formation__IoFns.freeFn = (ILU_C_FreeFn) Unit_Formation__Free;
  _ILU_C_RegisterIoFns (&_Unit_Formation__IoFns);

  _Unit_UnitInfoSeq__IoFns.inputFn = (ILU_C_InputFn) _Unit_UnitInfoSeq__Input;
  _Unit_UnitInfoSeq__IoFns.outFn = (ILU_C_OutputFn) _Unit_UnitInfoSeq__Output;
  _Unit_UnitInfoSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_UnitInfoSeq__SizeOf;
  _Unit_UnitInfoSeq__IoFns.freeFn = (ILU_C_FreeFn) Unit_UnitInfoSeq__Free;
  _ILU_C_RegisterIoFns (&_Unit_UnitInfoSeq__IoFns);

  _Unit_UnitInfo__IoFns.inputFn = (ILU_C_InputFn) _Unit_UnitInfo__Input;
  _Unit_UnitInfo__IoFns.outFn = (ILU_C_OutputFn) _Unit_UnitInfo__Output;
  _Unit_UnitInfo__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_UnitInfo__SizeOf;
  _Unit_UnitInfo__IoFns.freeFn = (ILU_C_FreeFn) Unit_UnitInfo__Free;
  _ILU_C_RegisterIoFns (&_Unit_UnitInfo__IoFns);

  _ILU_C_RegisterIoFns (&_Unit_UnitMinorMode__IoFns);

  _ILU_C_RegisterIoFns (&_Unit_UnitMode__IoFns);

  _ILU_C_RegisterIoFns (&_Unit_UnitRole__IoFns);

  _Unit_ActionSeq__IoFns.inputFn = (ILU_C_InputFn) _Unit_ActionSeq__Input;
  _Unit_ActionSeq__IoFns.outFn = (ILU_C_OutputFn) _Unit_ActionSeq__Output;
  _Unit_ActionSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_ActionSeq__SizeOf;
  _Unit_ActionSeq__IoFns.freeFn = (ILU_C_FreeFn) Unit_ActionSeq__Free;
  _ILU_C_RegisterIoFns (&_Unit_ActionSeq__IoFns);

  _Unit_MoveAction__IoFns.inputFn = (ILU_C_InputFn) _Unit_MoveAction__Input;
  _Unit_MoveAction__IoFns.outFn = (ILU_C_OutputFn) _Unit_MoveAction__Output;
  _Unit_MoveAction__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_MoveAction__SizeOf;
  _Unit_MoveAction__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Unit_MoveAction__IoFns);

  _ILU_C_RegisterIoFns (&_Unit_MoveActionType__IoFns);

  _Unit_BasicMoveActionData__IoFns.inputFn = (ILU_C_InputFn) _Unit_BasicMoveActionData__Input;
  _Unit_BasicMoveActionData__IoFns.outFn = (ILU_C_OutputFn) _Unit_BasicMoveActionData__Output;
  _Unit_BasicMoveActionData__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_BasicMoveActionData__SizeOf;
  _Unit_BasicMoveActionData__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Unit_BasicMoveActionData__IoFns);

  _Unit_ActionDuration__IoFns.inputFn = (ILU_C_InputFn) _Unit_ActionDuration__Input;
  _Unit_ActionDuration__IoFns.outFn = (ILU_C_OutputFn) _Unit_ActionDuration__Output;
  _Unit_ActionDuration__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_ActionDuration__SizeOf;
  _Unit_ActionDuration__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Unit_ActionDuration__IoFns);

  _Unit_FloatSeq__IoFns.inputFn = (ILU_C_InputFn) _Unit_FloatSeq__Input;
  _Unit_FloatSeq__IoFns.outFn = (ILU_C_OutputFn) _Unit_FloatSeq__Output;
  _Unit_FloatSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_FloatSeq__SizeOf;
  _Unit_FloatSeq__IoFns.freeFn = (ILU_C_FreeFn) Unit_FloatSeq__Free;
  _ILU_C_RegisterIoFns (&_Unit_FloatSeq__IoFns);

  _Unit_ShortSeq__IoFns.inputFn = (ILU_C_InputFn) _Unit_ShortSeq__Input;
  _Unit_ShortSeq__IoFns.outFn = (ILU_C_OutputFn) _Unit_ShortSeq__Output;
  _Unit_ShortSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_ShortSeq__SizeOf;
  _Unit_ShortSeq__IoFns.freeFn = (ILU_C_FreeFn) Unit_ShortSeq__Free;
  _ILU_C_RegisterIoFns (&_Unit_ShortSeq__IoFns);

  _Unit_UnitSBHSeq__IoFns.inputFn = (ILU_C_InputFn) _Unit_UnitSBHSeq__Input;
  _Unit_UnitSBHSeq__IoFns.outFn = (ILU_C_OutputFn) _Unit_UnitSBHSeq__Output;
  _Unit_UnitSBHSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_UnitSBHSeq__SizeOf;
  _Unit_UnitSBHSeq__IoFns.freeFn = (ILU_C_FreeFn) Unit_UnitSBHSeq__Free;
  _ILU_C_RegisterIoFns (&_Unit_UnitSBHSeq__IoFns);

  _Unit_UnitIDSeq__IoFns.inputFn = (ILU_C_InputFn) _Unit_UnitIDSeq__Input;
  _Unit_UnitIDSeq__IoFns.outFn = (ILU_C_OutputFn) _Unit_UnitIDSeq__Output;
  _Unit_UnitIDSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Unit_UnitIDSeq__SizeOf;
  _Unit_UnitIDSeq__IoFns.freeFn = (ILU_C_FreeFn) Unit_UnitIDSeq__Free;
  _ILU_C_RegisterIoFns (&_Unit_UnitIDSeq__IoFns);

  _Unit_UnitSBH__IoFns.inputFn = (ILU_C_InputFn) _ilu_CString__Input;
  _Unit_UnitSBH__IoFns.outFn = (ILU_C_OutputFn) _ilu_CString__Output;
  _Unit_UnitSBH__IoFns.sizeFn = (ILU_C_SizeFn) _ilu_CString__SizeOf;
  _Unit_UnitSBH__IoFns.freeFn = (ILU_C_FreeFn) ilu_CString__Free;
  _ILU_C_RegisterIoFns (&_Unit_UnitSBH__IoFns);

  _Unit_UnitID__IoFns.inputFn = (ILU_C_InputFn) _ilu_CString__Input;
  _Unit_UnitID__IoFns.outFn = (ILU_C_OutputFn) _ilu_CString__Output;
  _Unit_UnitID__IoFns.sizeFn = (ILU_C_SizeFn) _ilu_CString__SizeOf;
  _Unit_UnitID__IoFns.freeFn = (ILU_C_FreeFn) ilu_CString__Free;
  _ILU_C_RegisterIoFns (&_Unit_UnitID__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

