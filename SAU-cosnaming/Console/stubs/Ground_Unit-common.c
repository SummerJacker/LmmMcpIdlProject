/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:29:14 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Ground_Unit.h"

ilu_Class _Ground_Unit_rpc__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_rpc__IoFns = { ilu_object_tk, "IDL:Ground_Unit/rpc:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_TrapPointSeq__IoFns = { ilu_sequence_tk, "ilut:cyWkOJaqoKC2Is+MR6b9JrnwafC", { sizeof(Ground_Unit_TrapPointSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_TaskPath__IoFns = { ilu_sequence_tk, "ilut:hLevTcD2P-ZUamTT3AuiLH5L75s", { sizeof(Ground_Unit_TaskPath) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_TrapPoint2D__IoFns = { ilu_record_tk, "IDL:Ground_Unit/TrapPoint2D:1.0", { sizeof(Ground_Unit_TrapPoint2D) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_Point2D__IoFns = { ilu_record_tk, "IDL:Ground_Unit/Point2D:1.0", { sizeof(Ground_Unit_Point2D) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_GroundUnitInfo__IoFns = { ilu_record_tk, "IDL:Ground_Unit/GroundUnitInfo:1.0", { sizeof(Ground_Unit_GroundUnitInfo) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_Speed2D__IoFns = { ilu_record_tk, "IDL:Ground_Unit/Speed2D:1.0", { sizeof(Ground_Unit_Speed2D) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Ground_Unit_Pose2D__IoFns = { ilu_record_tk, "IDL:Ground_Unit/Pose2D:1.0", { sizeof(Ground_Unit_Pose2D) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class Ground_Unit_rpc__MakeClass(
  Ground_Unit_Speed2D (*Ground_Unit_rpc_getCurrentSpeed__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Ground_Unit_Pose2D (*Ground_Unit_rpc_getCurrentPose__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Ground_Unit_GroundUnitInfo* (*Ground_Unit_rpc_getCurrentInfo__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_sendVehicleInfo__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_GroundUnitInfo* info, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_reportTrap__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_clearTraps__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Ground_Unit_TrapPointSeq* (*Ground_Unit_rpc_getTraps__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTrapPoint__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTrack__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTaskPath__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTaskPoint__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_Point2D* point, ILU_C_ENVIRONMENT *_status),
  Unit_UnitID (*Unit_rpc_getID__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitSBH (*Unit_rpc_getCosNamingSBH__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Unit_rpc_getFrontUnitInfo__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRole__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMode__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMinorMode__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveAction__Impl)
     (Ground_Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveActionSeq__Impl)
     (Ground_Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setALeader__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unregisterFollower__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFollower__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unsetFollower__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_addRearVehicle__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_deleteRearVehicle__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFormation__Impl)
     (Ground_Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRearVehicles__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_reportDeadVehicle__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_shutDown__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_startPhotoStream__Impl)
     (Ground_Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_stopPhotoStream__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_takePicture__Impl)
     (Ground_Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(4 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _Ground_Unit_rpc__ILUType;
  method_block = ilu_malloc(11 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Ground_Unit_rpc_getCurrentSpeed__Impl;
  method_block[1] = (_ILU_C_Method) Ground_Unit_rpc_getCurrentPose__Impl;
  method_block[2] = (_ILU_C_Method) Ground_Unit_rpc_getCurrentInfo__Impl;
  method_block[3] = (_ILU_C_Method) Ground_Unit_rpc_sendVehicleInfo__Impl;
  method_block[4] = (_ILU_C_Method) Ground_Unit_rpc_reportTrap__Impl;
  method_block[5] = (_ILU_C_Method) Ground_Unit_rpc_clearTraps__Impl;
  method_block[6] = (_ILU_C_Method) Ground_Unit_rpc_getTraps__Impl;
  method_block[7] = (_ILU_C_Method) Ground_Unit_rpc_setTrapPoint__Impl;
  method_block[8] = (_ILU_C_Method) Ground_Unit_rpc_setTrack__Impl;
  method_block[9] = (_ILU_C_Method) Ground_Unit_rpc_setTaskPath__Impl;
  method_block[10] = (_ILU_C_Method) Ground_Unit_rpc_setTaskPoint__Impl;

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
Ground_Unit_Speed2D Ground_Unit_rpc_getCurrentSpeed (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_Speed2D (*_f)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Ground_Unit_Speed2D _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Ground_Unit_Speed2D (*)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Ground_Unit_Pose2D Ground_Unit_rpc_getCurrentPose (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_Pose2D (*_f)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Ground_Unit_Pose2D _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Ground_Unit_Pose2D (*)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Ground_Unit_GroundUnitInfo* Ground_Unit_rpc_getCurrentInfo (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_GroundUnitInfo* (*_f)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Ground_Unit_GroundUnitInfo* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Ground_Unit_GroundUnitInfo* (*)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Ground_Unit_rpc_sendVehicleInfo (Ground_Unit_rpc _handle, Ground_Unit_GroundUnitInfo* info, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Ground_Unit_rpc, Ground_Unit_GroundUnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Ground_Unit_rpc, Ground_Unit_GroundUnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, info, _status));
}

CORBA_boolean Ground_Unit_rpc_reportTrap (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Ground_Unit_rpc, Ground_Unit_TrapPoint2D*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Ground_Unit_rpc, Ground_Unit_TrapPoint2D*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, trap, _status));
}

CORBA_boolean Ground_Unit_rpc_clearTraps (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Ground_Unit_TrapPointSeq* Ground_Unit_rpc_getTraps (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_TrapPointSeq* (*_f)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Ground_Unit_TrapPointSeq* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Ground_Unit_TrapPointSeq* (*)(Ground_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Ground_Unit_rpc_setTrapPoint (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Ground_Unit_rpc, Ground_Unit_TrapPoint2D*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Ground_Unit_rpc, Ground_Unit_TrapPoint2D*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, trap, _status));
}

CORBA_boolean Ground_Unit_rpc_setTrack (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Ground_Unit_rpc, Ground_Unit_TaskPath*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Ground_Unit_rpc, Ground_Unit_TaskPath*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 8);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, track, _status));
}

CORBA_boolean Ground_Unit_rpc_setTaskPath (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Ground_Unit_rpc, Ground_Unit_TaskPath*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Ground_Unit_rpc, Ground_Unit_TaskPath*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 9);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, path, _status));
}

CORBA_boolean Ground_Unit_rpc_setTaskPoint (Ground_Unit_rpc _handle, Ground_Unit_Point2D* point, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Ground_Unit_rpc, Ground_Unit_Point2D*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Ground_Unit_rpc, Ground_Unit_Point2D*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Ground_Unit_rpc__ILUType, 10);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, point, _status));
}

void Ground_Unit_rpc__SetUserData (Ground_Unit_rpc self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Ground_Unit_rpc__GetUserData (Ground_Unit_rpc self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Ground_Unit_rpc__Free (Ground_Unit_rpc* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Ground_Unit_rpc */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Ground_Unit_rpc *CORBA_sequence_Ground_Unit_rpc_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_rpc *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_rpc) * _count;

  if ((_p = (Ground_Unit_rpc *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_TrapPointSeq* _Ground_Unit_TrapPointSeq__Input (ilu_Call _call, Ground_Unit_TrapPointSeq* _ref, ilu_Error *_err)
{
  Ground_Unit_TrapPointSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Ground_Unit_TrapPoint2D _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Ground_Unit_TrapPointSeq*) ilu_MallocE(sizeof (Ground_Unit_TrapPointSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Ground_Unit_TrapPointSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Ground_Unit_TrapPointSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Ground_Unit_TrapPoint2D), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Ground_Unit_TrapPoint2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Ground_Unit_TrapPoint2D__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Ground_Unit_TrapPointSeq_Append (_val, &_tmp, _err);
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

void _Ground_Unit_TrapPointSeq__Output (ilu_Call _call, Ground_Unit_TrapPointSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Ground_Unit_TrapPointSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Ground_Unit_TrapPoint2D), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Ground_Unit_TrapPoint2D), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Ground_Unit_TrapPoint2D *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Ground_Unit_TrapPoint2D__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Ground_Unit_TrapPointSeq__SizeOf (ilu_Call _call, Ground_Unit_TrapPointSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Ground_Unit_TrapPointSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Ground_Unit_TrapPoint2D), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Ground_Unit_TrapPoint2D), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Ground_Unit_TrapPoint2D *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Ground_Unit_TrapPoint2D__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Ground_Unit_TrapPointSeq__Free (Ground_Unit_TrapPointSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Ground_Unit_TrapPointSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Ground_Unit_TrapPoint2D)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Ground_Unit_TrapPoint2D)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Ground_Unit_TrapPoint2D))) */ ) {
    //ilu_DebugPrintf("OK Ground_Unit_TrapPointSeq__Free (Ground_Unit_TrapPointSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Ground_Unit_TrapPointSeq *CORBA_sequence_Ground_Unit_TrapPointSeq_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_TrapPointSeq *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_TrapPointSeq) * _count;

  if ((_p = (Ground_Unit_TrapPointSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_TrapPointSeq* Ground_Unit_TrapPointSeq__alloc ()
{
  return ((Ground_Unit_TrapPointSeq*) CORBA_sequence_Ground_Unit_TrapPointSeq_allocbuf(1));
}

Ground_Unit_TaskPath* _Ground_Unit_TaskPath__Input (ilu_Call _call, Ground_Unit_TaskPath* _ref, ilu_Error *_err)
{
  Ground_Unit_TaskPath* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Ground_Unit_Point2D _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Ground_Unit_TaskPath*) ilu_MallocE(sizeof (Ground_Unit_TaskPath), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Ground_Unit_TaskPath_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Ground_Unit_TaskPath), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Point2D), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Ground_Unit_Point2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Ground_Unit_Point2D__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Ground_Unit_TaskPath_Append (_val, &_tmp, _err);
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

void _Ground_Unit_TaskPath__Output (ilu_Call _call, Ground_Unit_TaskPath* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Ground_Unit_TaskPath), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Ground_Unit_Point2D), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Ground_Unit_Point2D), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Ground_Unit_Point2D *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Ground_Unit_Point2D__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Ground_Unit_TaskPath__SizeOf (ilu_Call _call, Ground_Unit_TaskPath* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Ground_Unit_TaskPath), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Ground_Unit_Point2D), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Ground_Unit_Point2D), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Ground_Unit_Point2D *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Ground_Unit_Point2D__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Ground_Unit_TaskPath__Free (Ground_Unit_TaskPath* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Ground_Unit_TaskPath */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Ground_Unit_Point2D)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Ground_Unit_Point2D)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Ground_Unit_Point2D))) */ ) {
    //ilu_DebugPrintf("OK Ground_Unit_TaskPath__Free (Ground_Unit_TaskPath* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Ground_Unit_TaskPath *CORBA_sequence_Ground_Unit_TaskPath_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_TaskPath *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_TaskPath) * _count;

  if ((_p = (Ground_Unit_TaskPath *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_TaskPath* Ground_Unit_TaskPath__alloc ()
{
  return ((Ground_Unit_TaskPath*) CORBA_sequence_Ground_Unit_TaskPath_allocbuf(1));
}

Ground_Unit_TrapPoint2D* _Ground_Unit_TrapPoint2D__Input (ilu_Call _call, Ground_Unit_TrapPoint2D* _ref, ilu_Error *_err)
{
  Ground_Unit_TrapPoint2D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_TrapPoint2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_TrapPoint2D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Ground_Unit_TrapPoint2D*) ilu_MallocE (sizeof (Ground_Unit_TrapPoint2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Ground_Unit_TrapPoint2D));
    } else {
      _val = (Ground_Unit_TrapPoint2D*) _ILU_C_CRCreate (s, sizeof(Ground_Unit_TrapPoint2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_TrapPoint2D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Ground_Unit_Point2D__Input (_call, &_val->point,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->radius, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Ground_Unit_TrapPoint2D__Output (ilu_Call _call, Ground_Unit_TrapPoint2D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Ground_Unit_TrapPoint2D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Ground_Unit_TrapPoint2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_TrapPoint2D), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Ground_Unit_Point2D__Output(_call, (&_val->point), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->radius), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Ground_Unit_TrapPoint2D__SizeOf (ilu_Call _call, Ground_Unit_TrapPoint2D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_TrapPoint2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_TrapPoint2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_TrapPoint2D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Ground_Unit_Point2D__SizeOf (_call, &_val->point, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->radius, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Ground_Unit_TrapPoint2D *CORBA_sequence_Ground_Unit_TrapPoint2D_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_TrapPoint2D *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_TrapPoint2D) * _count;

  if ((_p = (Ground_Unit_TrapPoint2D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_TrapPoint2D* Ground_Unit_TrapPoint2D__alloc ()
{
  return ((Ground_Unit_TrapPoint2D*) CORBA_sequence_Ground_Unit_TrapPoint2D_allocbuf(1));
}

Ground_Unit_Point2D* _Ground_Unit_Point2D__Input (ilu_Call _call, Ground_Unit_Point2D* _ref, ilu_Error *_err)
{
  Ground_Unit_Point2D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_Point2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_Point2D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Ground_Unit_Point2D*) ilu_MallocE (sizeof (Ground_Unit_Point2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Ground_Unit_Point2D));
    } else {
      _val = (Ground_Unit_Point2D*) _ILU_C_CRCreate (s, sizeof(Ground_Unit_Point2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Point2D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->x, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->y, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Ground_Unit_Point2D__Output (ilu_Call _call, Ground_Unit_Point2D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Ground_Unit_Point2D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Ground_Unit_Point2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Point2D), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->x), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->y), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Ground_Unit_Point2D__SizeOf (ilu_Call _call, Ground_Unit_Point2D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_Point2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_Point2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Point2D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->x, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->y, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Ground_Unit_Point2D *CORBA_sequence_Ground_Unit_Point2D_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_Point2D *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_Point2D) * _count;

  if ((_p = (Ground_Unit_Point2D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_Point2D* Ground_Unit_Point2D__alloc ()
{
  return ((Ground_Unit_Point2D*) CORBA_sequence_Ground_Unit_Point2D_allocbuf(1));
}

Ground_Unit_GroundUnitInfo* _Ground_Unit_GroundUnitInfo__Input (ilu_Call _call, Ground_Unit_GroundUnitInfo* _ref, ilu_Error *_err)
{
  Ground_Unit_GroundUnitInfo* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_GroundUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_GroundUnitInfo__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Ground_Unit_GroundUnitInfo*) ilu_MallocE (sizeof (Ground_Unit_GroundUnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Ground_Unit_GroundUnitInfo));
    } else {
      _val = (Ground_Unit_GroundUnitInfo*) _ILU_C_CRCreate (s, sizeof(Ground_Unit_GroundUnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_GroundUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Unit_UnitInfo__Input (_call, &_val->info,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  {
    ilu_shortcardinal _xxx;
    ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    *&_val->role = (Unit_UnitRole) _xxx;
  };
  (void) _Ground_Unit_Speed2D__Input (_call, &_val->speed,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Ground_Unit_Pose2D__Input (_call, &_val->pose,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Ground_Unit_GroundUnitInfo__Output (ilu_Call _call, Ground_Unit_GroundUnitInfo* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Ground_Unit_GroundUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Ground_Unit_GroundUnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_GroundUnitInfo), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Unit_UnitInfo__Output(_call, (&_val->info), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputEnum (_call, (ilu_shortcardinal) (_val->role), (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Ground_Unit_Speed2D__Output(_call, (&_val->speed), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Ground_Unit_Pose2D__Output(_call, (&_val->pose), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Ground_Unit_GroundUnitInfo__SizeOf (ilu_Call _call, Ground_Unit_GroundUnitInfo* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_GroundUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_GroundUnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_GroundUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Unit_UnitInfo__SizeOf (_call, &_val->info, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) _val->role, (ilu_Type)ILU_NIL,  _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Ground_Unit_Speed2D__SizeOf (_call, &_val->speed, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Ground_Unit_Pose2D__SizeOf (_call, &_val->pose, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Ground_Unit_GroundUnitInfo__Free (Ground_Unit_GroundUnitInfo* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Ground_Unit_GroundUnitInfo */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Ground_Unit_GroundUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_GroundUnitInfo__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  Unit_UnitInfo__Free (&_val->info);
}

Ground_Unit_GroundUnitInfo *CORBA_sequence_Ground_Unit_GroundUnitInfo_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_GroundUnitInfo *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_GroundUnitInfo) * _count;

  if ((_p = (Ground_Unit_GroundUnitInfo *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_GroundUnitInfo* Ground_Unit_GroundUnitInfo__alloc ()
{
  return ((Ground_Unit_GroundUnitInfo*) CORBA_sequence_Ground_Unit_GroundUnitInfo_allocbuf(1));
}

Ground_Unit_Speed2D* _Ground_Unit_Speed2D__Input (ilu_Call _call, Ground_Unit_Speed2D* _ref, ilu_Error *_err)
{
  Ground_Unit_Speed2D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_Speed2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_Speed2D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Ground_Unit_Speed2D*) ilu_MallocE (sizeof (Ground_Unit_Speed2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Ground_Unit_Speed2D));
    } else {
      _val = (Ground_Unit_Speed2D*) _ILU_C_CRCreate (s, sizeof(Ground_Unit_Speed2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Speed2D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->leanerVel, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->angularVel, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Ground_Unit_Speed2D__Output (ilu_Call _call, Ground_Unit_Speed2D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Ground_Unit_Speed2D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Ground_Unit_Speed2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Speed2D), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->leanerVel), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->angularVel), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Ground_Unit_Speed2D__SizeOf (ilu_Call _call, Ground_Unit_Speed2D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_Speed2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_Speed2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Speed2D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->leanerVel, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->angularVel, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Ground_Unit_Speed2D *CORBA_sequence_Ground_Unit_Speed2D_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_Speed2D *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_Speed2D) * _count;

  if ((_p = (Ground_Unit_Speed2D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_Speed2D* Ground_Unit_Speed2D__alloc ()
{
  return ((Ground_Unit_Speed2D*) CORBA_sequence_Ground_Unit_Speed2D_allocbuf(1));
}

Ground_Unit_Pose2D* _Ground_Unit_Pose2D__Input (ilu_Call _call, Ground_Unit_Pose2D* _ref, ilu_Error *_err)
{
  Ground_Unit_Pose2D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_Pose2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_Pose2D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Ground_Unit_Pose2D*) ilu_MallocE (sizeof (Ground_Unit_Pose2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Ground_Unit_Pose2D));
    } else {
      _val = (Ground_Unit_Pose2D*) _ILU_C_CRCreate (s, sizeof(Ground_Unit_Pose2D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Pose2D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->x, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->y, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->yaw, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Ground_Unit_Pose2D__Output (ilu_Call _call, Ground_Unit_Pose2D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Ground_Unit_Pose2D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Ground_Unit_Pose2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Pose2D), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->x), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->y), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->yaw), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Ground_Unit_Pose2D__SizeOf (ilu_Call _call, Ground_Unit_Pose2D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Ground_Unit_Pose2D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Ground_Unit_Pose2D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Ground_Unit_Pose2D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->x, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->y, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->yaw, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Ground_Unit_Pose2D *CORBA_sequence_Ground_Unit_Pose2D_allocbuf (CORBA_unsigned_long _count)
{
  Ground_Unit_Pose2D *_p;
  CORBA_unsigned_long _size = sizeof(Ground_Unit_Pose2D) * _count;

  if ((_p = (Ground_Unit_Pose2D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Ground_Unit_Pose2D* Ground_Unit_Pose2D__alloc ()
{
  return ((Ground_Unit_Pose2D*) CORBA_sequence_Ground_Unit_Pose2D_allocbuf(1));
}

void Ground_Unit_TrapPointSeq_Every (Ground_Unit_TrapPointSeq *h, void (*f)(Ground_Unit_TrapPoint2D*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Ground_Unit_TrapPoint2D), (void *) data);
}

void Ground_Unit_TrapPointSeq_Append (Ground_Unit_TrapPointSeq *h, Ground_Unit_TrapPoint2D* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Ground_Unit_TrapPoint2D), err);
}

void Ground_Unit_TrapPointSeq_Push (Ground_Unit_TrapPointSeq *h, Ground_Unit_TrapPoint2D* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Ground_Unit_TrapPoint2D));
}

void Ground_Unit_TrapPointSeq_Pop (Ground_Unit_TrapPointSeq *h, Ground_Unit_TrapPoint2D* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Ground_Unit_TrapPoint2D));
}

CORBA_unsigned_long Ground_Unit_TrapPointSeq_Length (Ground_Unit_TrapPointSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Ground_Unit_TrapPoint2D * Ground_Unit_TrapPointSeq_Nth (Ground_Unit_TrapPointSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Ground_Unit_TrapPointSeq * Ground_Unit_TrapPointSeq_Create (CORBA_unsigned_long sz, Ground_Unit_TrapPoint2D* p)
{
  Ground_Unit_TrapPointSeq *s;
  s = (Ground_Unit_TrapPointSeq *) ilu_malloc(sizeof(Ground_Unit_TrapPointSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Ground_Unit_TrapPointSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Ground_Unit_TrapPoint2D *) ilu_malloc(sz * sizeof(Ground_Unit_TrapPoint2D))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Ground_Unit_TrapPoint2D));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Ground_Unit_TrapPointSeq_Init (Ground_Unit_TrapPointSeq *s, CORBA_unsigned_long sz, Ground_Unit_TrapPoint2D* p)
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
    s->_buffer = (Ground_Unit_TrapPoint2D *) ilu_malloc (sz * sizeof (Ground_Unit_TrapPoint2D));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Ground_Unit_TrapPoint2D)); }}
  else
    s->_buffer = p;
  return;
}

void Ground_Unit_TaskPath_Every (Ground_Unit_TaskPath *h, void (*f)(Ground_Unit_Point2D*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Ground_Unit_Point2D), (void *) data);
}

void Ground_Unit_TaskPath_Append (Ground_Unit_TaskPath *h, Ground_Unit_Point2D* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Ground_Unit_Point2D), err);
}

void Ground_Unit_TaskPath_Push (Ground_Unit_TaskPath *h, Ground_Unit_Point2D* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Ground_Unit_Point2D));
}

void Ground_Unit_TaskPath_Pop (Ground_Unit_TaskPath *h, Ground_Unit_Point2D* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Ground_Unit_Point2D));
}

CORBA_unsigned_long Ground_Unit_TaskPath_Length (Ground_Unit_TaskPath *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Ground_Unit_Point2D * Ground_Unit_TaskPath_Nth (Ground_Unit_TaskPath *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Ground_Unit_TaskPath * Ground_Unit_TaskPath_Create (CORBA_unsigned_long sz, Ground_Unit_Point2D* p)
{
  Ground_Unit_TaskPath *s;
  s = (Ground_Unit_TaskPath *) ilu_malloc(sizeof(Ground_Unit_TaskPath));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Ground_Unit_TaskPath)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Ground_Unit_Point2D *) ilu_malloc(sz * sizeof(Ground_Unit_Point2D))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Ground_Unit_Point2D));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Ground_Unit_TaskPath_Init (Ground_Unit_TaskPath *s, CORBA_unsigned_long sz, Ground_Unit_Point2D* p)
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
    s->_buffer = (Ground_Unit_Point2D *) ilu_malloc (sz * sizeof (Ground_Unit_Point2D));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Ground_Unit_Point2D)); }}
  else
    s->_buffer = p;
  return;
}

void _Ground_Unit__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Ground-Unit", "2.0beta1", "v2 (2.0beta1)");
  _Unit__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	"IDL:Unit/rpc:1.0",
	NULL};
    cl = ilu_DefineObjectType("Ground-Unit.rpc",	/*name*/
	NULL,	/*no brand*/
	"IDL:Ground_Unit/rpc:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	11,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Ground_Unit_rpc__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"getCurrentSpeed",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Ground_Unit/Speed2D:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"getCurrentPose",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Ground_Unit/Pose2D:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"getCurrentInfo",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:Ground_Unit/GroundUnitInfo:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"sendVehicleInfo",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "info", ilu_FALSE, ilu_In, "IDL:Ground_Unit/GroundUnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"reportTrap",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "trap", ilu_FALSE, ilu_In, "IDL:Ground_Unit/TrapPoint2D:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 5,
	"clearTraps",	/*name*/
	6,	/*id*/
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
    m = ilu_DefineMethod(cl, 6,
	"getTraps",	/*name*/
	7,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:cyWkOJaqoKC2Is+MR6b9JrnwafC",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 7,
	"setTrapPoint",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "trap", ilu_FALSE, ilu_In, "IDL:Ground_Unit/TrapPoint2D:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 8,
	"setTrack",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "track", ilu_FALSE, ilu_In, "ilut:hLevTcD2P-ZUamTT3AuiLH5L75s", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 9,
	"setTaskPath",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "path", ilu_FALSE, ilu_In, "ilut:hLevTcD2P-ZUamTT3AuiLH5L75s", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 10,
	"setTaskPoint",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "point", ilu_FALSE, ilu_In, "IDL:Ground_Unit/Point2D:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Ground_Unit_rpc__IoFns.kernelType = ilu_RegisterObjectType("rpc", "Ground-Unit", ILU_NIL, "IDL:Ground_Unit/rpc:1.0",
    _Ground_Unit_rpc__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Ground_Unit_TrapPointSeq__IoFns.kernelType = ilu_RegisterSequenceType("TrapPointSeq", "Ground-Unit", ILU_NIL, "ilut:cyWkOJaqoKC2Is+MR6b9JrnwafC",
    "IDL:Ground_Unit/TrapPoint2D:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Ground_Unit_TaskPath__IoFns.kernelType = ilu_RegisterSequenceType("TaskPath", "Ground-Unit", ILU_NIL, "ilut:hLevTcD2P-ZUamTT3AuiLH5L75s",
    "IDL:Ground_Unit/Point2D:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Ground_Unit_TrapPoint2D__IoFns.kernelType = type = ilu_RegisterRecordType("TrapPoint2D", "Ground-Unit", ILU_NIL, "IDL:Ground_Unit/TrapPoint2D:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "point", /* field name */
      "IDL:Ground_Unit/Point2D:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "radius", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Ground_Unit_Point2D__IoFns.kernelType = type = ilu_RegisterRecordType("Point2D", "Ground-Unit", ILU_NIL, "IDL:Ground_Unit/Point2D:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "x", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "y", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Ground_Unit_GroundUnitInfo__IoFns.kernelType = type = ilu_RegisterRecordType("GroundUnitInfo", "Ground-Unit", ILU_NIL, "IDL:Ground_Unit/GroundUnitInfo:1.0",
    4,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "info", /* field name */
      "IDL:Unit/UnitInfo:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "role", /* field name */
      "IDL:Unit/UnitRole:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "speed", /* field name */
      "IDL:Ground_Unit/Speed2D:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "pose", /* field name */
      "IDL:Ground_Unit/Pose2D:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Ground_Unit_Speed2D__IoFns.kernelType = type = ilu_RegisterRecordType("Speed2D", "Ground-Unit", ILU_NIL, "IDL:Ground_Unit/Speed2D:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "leanerVel", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "angularVel", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Ground_Unit_Pose2D__IoFns.kernelType = type = ilu_RegisterRecordType("Pose2D", "Ground-Unit", ILU_NIL, "IDL:Ground_Unit/Pose2D:1.0",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "x", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "y", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "yaw", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Ground_Unit_rpc__IoFns.properties.object_class = _Ground_Unit_rpc__ILUType;
  _ILU_C_RegisterIoFns (&_Ground_Unit_rpc__IoFns);

  _Ground_Unit_TrapPointSeq__IoFns.inputFn = (ILU_C_InputFn) _Ground_Unit_TrapPointSeq__Input;
  _Ground_Unit_TrapPointSeq__IoFns.outFn = (ILU_C_OutputFn) _Ground_Unit_TrapPointSeq__Output;
  _Ground_Unit_TrapPointSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Ground_Unit_TrapPointSeq__SizeOf;
  _Ground_Unit_TrapPointSeq__IoFns.freeFn = (ILU_C_FreeFn) Ground_Unit_TrapPointSeq__Free;
  _ILU_C_RegisterIoFns (&_Ground_Unit_TrapPointSeq__IoFns);

  _Ground_Unit_TaskPath__IoFns.inputFn = (ILU_C_InputFn) _Ground_Unit_TaskPath__Input;
  _Ground_Unit_TaskPath__IoFns.outFn = (ILU_C_OutputFn) _Ground_Unit_TaskPath__Output;
  _Ground_Unit_TaskPath__IoFns.sizeFn = (ILU_C_SizeFn) _Ground_Unit_TaskPath__SizeOf;
  _Ground_Unit_TaskPath__IoFns.freeFn = (ILU_C_FreeFn) Ground_Unit_TaskPath__Free;
  _ILU_C_RegisterIoFns (&_Ground_Unit_TaskPath__IoFns);

  _Ground_Unit_TrapPoint2D__IoFns.inputFn = (ILU_C_InputFn) _Ground_Unit_TrapPoint2D__Input;
  _Ground_Unit_TrapPoint2D__IoFns.outFn = (ILU_C_OutputFn) _Ground_Unit_TrapPoint2D__Output;
  _Ground_Unit_TrapPoint2D__IoFns.sizeFn = (ILU_C_SizeFn) _Ground_Unit_TrapPoint2D__SizeOf;
  _Ground_Unit_TrapPoint2D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Ground_Unit_TrapPoint2D__IoFns);

  _Ground_Unit_Point2D__IoFns.inputFn = (ILU_C_InputFn) _Ground_Unit_Point2D__Input;
  _Ground_Unit_Point2D__IoFns.outFn = (ILU_C_OutputFn) _Ground_Unit_Point2D__Output;
  _Ground_Unit_Point2D__IoFns.sizeFn = (ILU_C_SizeFn) _Ground_Unit_Point2D__SizeOf;
  _Ground_Unit_Point2D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Ground_Unit_Point2D__IoFns);

  _Ground_Unit_GroundUnitInfo__IoFns.inputFn = (ILU_C_InputFn) _Ground_Unit_GroundUnitInfo__Input;
  _Ground_Unit_GroundUnitInfo__IoFns.outFn = (ILU_C_OutputFn) _Ground_Unit_GroundUnitInfo__Output;
  _Ground_Unit_GroundUnitInfo__IoFns.sizeFn = (ILU_C_SizeFn) _Ground_Unit_GroundUnitInfo__SizeOf;
  _Ground_Unit_GroundUnitInfo__IoFns.freeFn = (ILU_C_FreeFn) Ground_Unit_GroundUnitInfo__Free;
  _ILU_C_RegisterIoFns (&_Ground_Unit_GroundUnitInfo__IoFns);

  _Ground_Unit_Speed2D__IoFns.inputFn = (ILU_C_InputFn) _Ground_Unit_Speed2D__Input;
  _Ground_Unit_Speed2D__IoFns.outFn = (ILU_C_OutputFn) _Ground_Unit_Speed2D__Output;
  _Ground_Unit_Speed2D__IoFns.sizeFn = (ILU_C_SizeFn) _Ground_Unit_Speed2D__SizeOf;
  _Ground_Unit_Speed2D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Ground_Unit_Speed2D__IoFns);

  _Ground_Unit_Pose2D__IoFns.inputFn = (ILU_C_InputFn) _Ground_Unit_Pose2D__Input;
  _Ground_Unit_Pose2D__IoFns.outFn = (ILU_C_OutputFn) _Ground_Unit_Pose2D__Output;
  _Ground_Unit_Pose2D__IoFns.sizeFn = (ILU_C_SizeFn) _Ground_Unit_Pose2D__SizeOf;
  _Ground_Unit_Pose2D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Ground_Unit_Pose2D__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

