/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 15:13:36 2025 by `??????????????????��?????????'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/../bin/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/../bin/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 ??????????????��??, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <stdlib.h> /* malloc, calloc, free ?? MinGW ????????? */
#include <string.h> /* used for error statements */
#include "Air_Unit.h"

ilu_Class _Air_Unit_rpc__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Air_Unit_rpc__IoFns = { ilu_object_tk, "IDL:Air_Unit/rpc:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_ActionMode__IoFns = { ilu_enumeration_tk, "IDL:Air_Unit/ActionMode:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_ActionRole__IoFns = { ilu_enumeration_tk, "IDL:Air_Unit/ActionRole:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_TrapPointSeq__IoFns = { ilu_sequence_tk, "ilut:f64M6WyJqOAUgQjEF7bfqsiJsHE", { sizeof(Air_Unit_TrapPointSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_TaskPath__IoFns = { ilu_sequence_tk, "ilut:dytiAb5pMGEVcFZXX98Jo+mue-R", { sizeof(Air_Unit_TaskPath) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_Site__IoFns = { ilu_union_tk, "IDL:Air_Unit/Site:1.0", { sizeof(Air_Unit_Site) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_CircleData__IoFns = { ilu_record_tk, "IDL:Air_Unit/CircleData:1.0", { sizeof(Air_Unit_CircleData) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_RectangleData__IoFns = { ilu_record_tk, "IDL:Air_Unit/RectangleData:1.0", { sizeof(Air_Unit_RectangleData) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_SiteType__IoFns = { ilu_enumeration_tk, "IDL:Air_Unit/SiteType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_TrapPoint3D__IoFns = { ilu_record_tk, "IDL:Air_Unit/TrapPoint3D:1.0", { sizeof(Air_Unit_TrapPoint3D) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_Point3D__IoFns = { ilu_record_tk, "IDL:Air_Unit/Point3D:1.0", { sizeof(Air_Unit_Point3D) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_AirUnitInfo__IoFns = { ilu_record_tk, "IDL:Air_Unit/AirUnitInfo:1.0", { sizeof(Air_Unit_AirUnitInfo) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_FusionAngularVelocity__IoFns = { ilu_record_tk, "IDL:Air_Unit/FusionAngularVelocity:1.0", { sizeof(Air_Unit_FusionAngularVelocity) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_Speed3D__IoFns = { ilu_record_tk, "IDL:Air_Unit/Speed3D:1.0", { sizeof(Air_Unit_Speed3D) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_GPSInfo__IoFns = { ilu_record_tk, "IDL:Air_Unit/GPSInfo:1.0", { sizeof(Air_Unit_GPSInfo) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_Pose3D__IoFns = { ilu_record_tk, "IDL:Air_Unit/Pose3D:1.0", { sizeof(Air_Unit_Pose3D) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_GimbalState__IoFns = { ilu_record_tk, "IDL:Air_Unit/GimbalState:1.0", { sizeof(Air_Unit_GimbalState) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Air_Unit_GimbalSpeed__IoFns = { ilu_record_tk, "IDL:Air_Unit/GimbalSpeed:1.0", { sizeof(Air_Unit_GimbalSpeed) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class Air_Unit_rpc__MakeClass(
  Air_Unit_Speed3D (*Air_Unit_rpc_getCurrentSpeed__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Air_Unit_Pose3D (*Air_Unit_rpc_getCurrentPose__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Air_Unit_AirUnitInfo* (*Air_Unit_rpc_getCurrentInfo__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_sendGimbalSpeed__Impl)
     (Air_Unit_rpc _handle, Air_Unit_GimbalSpeed* speed, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_resetGimbal__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_sendVehicleInfo__Impl)
     (Air_Unit_rpc _handle, Air_Unit_AirUnitInfo* info, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_reportTrap__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_clearTraps__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Air_Unit_TrapPointSeq* (*Air_Unit_rpc_getTraps__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTrapPoint__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTrack__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTaskPath__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTaskPoint__Impl)
     (Air_Unit_rpc _handle, Air_Unit_Point3D* point, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_clearTaskPoint__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_obtainCtrlAuthority__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_releaseCtrlAuthority__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setActionRole__Impl)
     (Air_Unit_rpc _handle, Air_Unit_ActionRole ar, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setActionMode__Impl)
     (Air_Unit_rpc _handle, Air_Unit_ActionMode am, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setCruiseScope__Impl)
     (Air_Unit_rpc _handle, Air_Unit_Site* s, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_sendControlledVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitSBHSeq* uss, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_confirmThrow__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_cancelThrow__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_actionThrow__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_confirmFire__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_cancelFire__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_confirmFireLocation__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_cancelFireLocation__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_controlVehicleVelocity__Impl)
     (Air_Unit_rpc _handle, CORBA_float vx, CORBA_float vy, CORBA_float vz, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_backHome__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setCruiseSpeed__Impl)
     (Air_Unit_rpc _handle, CORBA_float cs, ILU_C_ENVIRONMENT *_status),
  Unit_UnitID (*Unit_rpc_getID__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitSBH (*Unit_rpc_getCosNamingSBH__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Unit_rpc_getFrontUnitInfo__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRole__Impl)
     (Air_Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMode__Impl)
     (Air_Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMinorMode__Impl)
     (Air_Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveAction__Impl)
     (Air_Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveActionSeq__Impl)
     (Air_Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setALeader__Impl)
     (Air_Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unregisterFollower__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFollower__Impl)
     (Air_Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unsetFollower__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_addRearVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_deleteRearVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFormation__Impl)
     (Air_Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRearVehicles__Impl)
     (Air_Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_reportDeadVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_shutDown__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_startPhotoStream__Impl)
     (Air_Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_stopPhotoStream__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_takePicture__Impl)
     (Air_Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Air_Unit_rpc__ILUType;
  method_block = ilu_malloc(30 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Air_Unit_rpc_getCurrentSpeed__Impl;
  method_block[1] = (_ILU_C_Method) Air_Unit_rpc_getCurrentPose__Impl;
  method_block[2] = (_ILU_C_Method) Air_Unit_rpc_getCurrentInfo__Impl;
  method_block[3] = (_ILU_C_Method) Air_Unit_rpc_sendGimbalSpeed__Impl;
  method_block[4] = (_ILU_C_Method) Air_Unit_rpc_resetGimbal__Impl;
  method_block[5] = (_ILU_C_Method) Air_Unit_rpc_sendVehicleInfo__Impl;
  method_block[6] = (_ILU_C_Method) Air_Unit_rpc_reportTrap__Impl;
  method_block[7] = (_ILU_C_Method) Air_Unit_rpc_clearTraps__Impl;
  method_block[8] = (_ILU_C_Method) Air_Unit_rpc_getTraps__Impl;
  method_block[9] = (_ILU_C_Method) Air_Unit_rpc_setTrapPoint__Impl;
  method_block[10] = (_ILU_C_Method) Air_Unit_rpc_setTrack__Impl;
  method_block[11] = (_ILU_C_Method) Air_Unit_rpc_setTaskPath__Impl;
  method_block[12] = (_ILU_C_Method) Air_Unit_rpc_setTaskPoint__Impl;
  method_block[13] = (_ILU_C_Method) Air_Unit_rpc_clearTaskPoint__Impl;
  method_block[14] = (_ILU_C_Method) Air_Unit_rpc_obtainCtrlAuthority__Impl;
  method_block[15] = (_ILU_C_Method) Air_Unit_rpc_releaseCtrlAuthority__Impl;
  method_block[16] = (_ILU_C_Method) Air_Unit_rpc_setActionRole__Impl;
  method_block[17] = (_ILU_C_Method) Air_Unit_rpc_setActionMode__Impl;
  method_block[18] = (_ILU_C_Method) Air_Unit_rpc_setCruiseScope__Impl;
  method_block[19] = (_ILU_C_Method) Air_Unit_rpc_sendControlledVehicle__Impl;
  method_block[20] = (_ILU_C_Method) Air_Unit_rpc_confirmThrow__Impl;
  method_block[21] = (_ILU_C_Method) Air_Unit_rpc_cancelThrow__Impl;
  method_block[22] = (_ILU_C_Method) Air_Unit_rpc_actionThrow__Impl;
  method_block[23] = (_ILU_C_Method) Air_Unit_rpc_confirmFire__Impl;
  method_block[24] = (_ILU_C_Method) Air_Unit_rpc_cancelFire__Impl;
  method_block[25] = (_ILU_C_Method) Air_Unit_rpc_confirmFireLocation__Impl;
  method_block[26] = (_ILU_C_Method) Air_Unit_rpc_cancelFireLocation__Impl;
  method_block[27] = (_ILU_C_Method) Air_Unit_rpc_controlVehicleVelocity__Impl;
  method_block[28] = (_ILU_C_Method) Air_Unit_rpc_backHome__Impl;
  method_block[29] = (_ILU_C_Method) Air_Unit_rpc_setCruiseSpeed__Impl;

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
Air_Unit_Speed3D Air_Unit_rpc_getCurrentSpeed (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_Speed3D (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Air_Unit_Speed3D _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Air_Unit_Speed3D (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Air_Unit_Pose3D Air_Unit_rpc_getCurrentPose (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_Pose3D (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Air_Unit_Pose3D _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Air_Unit_Pose3D (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Air_Unit_AirUnitInfo* Air_Unit_rpc_getCurrentInfo (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_AirUnitInfo* (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Air_Unit_AirUnitInfo* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Air_Unit_AirUnitInfo* (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_sendGimbalSpeed (Air_Unit_rpc _handle, Air_Unit_GimbalSpeed* speed, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_GimbalSpeed*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_GimbalSpeed*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, speed, _status));
}

CORBA_boolean Air_Unit_rpc_resetGimbal (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_sendVehicleInfo (Air_Unit_rpc _handle, Air_Unit_AirUnitInfo* info, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_AirUnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_AirUnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, info, _status));
}

CORBA_boolean Air_Unit_rpc_reportTrap (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_TrapPoint3D*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_TrapPoint3D*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, trap, _status));
}

CORBA_boolean Air_Unit_rpc_clearTraps (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Air_Unit_TrapPointSeq* Air_Unit_rpc_getTraps (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_TrapPointSeq* (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Air_Unit_TrapPointSeq* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Air_Unit_TrapPointSeq* (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 8);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_setTrapPoint (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_TrapPoint3D*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_TrapPoint3D*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 9);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, trap, _status));
}

CORBA_boolean Air_Unit_rpc_setTrack (Air_Unit_rpc _handle, Air_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_TaskPath*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_TaskPath*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 10);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, track, _status));
}

CORBA_boolean Air_Unit_rpc_setTaskPath (Air_Unit_rpc _handle, Air_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_TaskPath*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_TaskPath*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 11);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, path, _status));
}

CORBA_boolean Air_Unit_rpc_setTaskPoint (Air_Unit_rpc _handle, Air_Unit_Point3D* point, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_Point3D*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_Point3D*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 12);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, point, _status));
}

CORBA_boolean Air_Unit_rpc_clearTaskPoint (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 13);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_obtainCtrlAuthority (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 14);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_releaseCtrlAuthority (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 15);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_setActionRole (Air_Unit_rpc _handle, Air_Unit_ActionRole ar, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_ActionRole, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_ActionRole, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 16);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, ar, _status));
}

CORBA_boolean Air_Unit_rpc_setActionMode (Air_Unit_rpc _handle, Air_Unit_ActionMode am, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_ActionMode, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_ActionMode, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 17);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, am, _status));
}

CORBA_boolean Air_Unit_rpc_setCruiseScope (Air_Unit_rpc _handle, Air_Unit_Site* s, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Air_Unit_Site*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Air_Unit_Site*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 18);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, s, _status));
}

CORBA_boolean Air_Unit_rpc_sendControlledVehicle (Air_Unit_rpc _handle, Unit_UnitSBHSeq* uss, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, Unit_UnitSBHSeq*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, Unit_UnitSBHSeq*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 19);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uss, _status));
}

CORBA_boolean Air_Unit_rpc_confirmThrow (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 20);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_cancelThrow (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 21);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_actionThrow (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 22);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_confirmFire (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 23);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_cancelFire (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 24);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_confirmFireLocation (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 25);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_cancelFireLocation (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 26);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_controlVehicleVelocity (Air_Unit_rpc _handle, CORBA_float vx, CORBA_float vy, CORBA_float vz, CORBA_float angle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, CORBA_float, CORBA_float, CORBA_float, CORBA_float, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, CORBA_float, CORBA_float, CORBA_float, CORBA_float, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 27);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, vx, vy, vz, angle, _status));
}

CORBA_boolean Air_Unit_rpc_backHome (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 28);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CORBA_boolean Air_Unit_rpc_setCruiseSpeed (Air_Unit_rpc _handle, CORBA_float cs, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Air_Unit_rpc, CORBA_float, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Air_Unit_rpc, CORBA_float, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Air_Unit_rpc__ILUType, 29);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, cs, _status));
}

void Air_Unit_rpc__SetUserData (Air_Unit_rpc self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Air_Unit_rpc__GetUserData (Air_Unit_rpc self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Air_Unit_rpc__Free (Air_Unit_rpc* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Air_Unit_rpc */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Air_Unit_rpc *CORBA_sequence_Air_Unit_rpc_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_rpc *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_rpc) * _count;

  if ((_p = (Air_Unit_rpc *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_ActionMode *CORBA_sequence_Air_Unit_ActionMode_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_ActionMode *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_ActionMode) * _count;

  if ((_p = (Air_Unit_ActionMode *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_ActionRole *CORBA_sequence_Air_Unit_ActionRole_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_ActionRole *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_ActionRole) * _count;

  if ((_p = (Air_Unit_ActionRole *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_TrapPointSeq* _Air_Unit_TrapPointSeq__Input (ilu_Call _call, Air_Unit_TrapPointSeq* _ref, ilu_Error *_err)
{
  Air_Unit_TrapPointSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Air_Unit_TrapPoint3D _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_opaque nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Air_Unit_TrapPointSeq*) ilu_MallocE(sizeof (Air_Unit_TrapPointSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Air_Unit_TrapPointSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Air_Unit_TrapPointSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Air_Unit_TrapPoint3D), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Air_Unit_TrapPoint3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Air_Unit_TrapPoint3D__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Air_Unit_TrapPointSeq_Append (_val, &_tmp, _err);
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

void _Air_Unit_TrapPointSeq__Output (ilu_Call _call, Air_Unit_TrapPointSeq* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_opaque nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Air_Unit_TrapPointSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Air_Unit_TrapPoint3D), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Air_Unit_TrapPoint3D), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Air_Unit_TrapPoint3D *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Air_Unit_TrapPoint3D__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_TrapPointSeq__SizeOf (ilu_Call _call, Air_Unit_TrapPointSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Air_Unit_TrapPointSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Air_Unit_TrapPoint3D), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Air_Unit_TrapPoint3D), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Air_Unit_TrapPoint3D *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Air_Unit_TrapPoint3D__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Air_Unit_TrapPointSeq__Free (Air_Unit_TrapPointSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Air_Unit_TrapPointSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* ????????????????????????????????????��??????  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Air_Unit_TrapPoint3D)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Air_Unit_TrapPoint3D)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Air_Unit_TrapPoint3D))) */ ) {
    //ilu_DebugPrintf("OK Air_Unit_TrapPointSeq__Free (Air_Unit_TrapPointSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Air_Unit_TrapPointSeq *CORBA_sequence_Air_Unit_TrapPointSeq_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_TrapPointSeq *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_TrapPointSeq) * _count;

  if ((_p = (Air_Unit_TrapPointSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_TrapPointSeq* Air_Unit_TrapPointSeq__alloc ()
{
  return ((Air_Unit_TrapPointSeq*) CORBA_sequence_Air_Unit_TrapPointSeq_allocbuf(1));
}

Air_Unit_TaskPath* _Air_Unit_TaskPath__Input (ilu_Call _call, Air_Unit_TaskPath* _ref, ilu_Error *_err)
{
  Air_Unit_TaskPath* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Air_Unit_Point3D _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_opaque nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Air_Unit_TaskPath*) ilu_MallocE(sizeof (Air_Unit_TaskPath), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Air_Unit_TaskPath_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Air_Unit_TaskPath), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Air_Unit_Point3D), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Air_Unit_Point3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Air_Unit_Point3D__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Air_Unit_TaskPath_Append (_val, &_tmp, _err);
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

void _Air_Unit_TaskPath__Output (ilu_Call _call, Air_Unit_TaskPath* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_opaque nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Air_Unit_TaskPath), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Air_Unit_Point3D), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Air_Unit_Point3D), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Air_Unit_Point3D *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Air_Unit_Point3D__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_TaskPath__SizeOf (ilu_Call _call, Air_Unit_TaskPath* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Air_Unit_TaskPath), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Air_Unit_Point3D), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Air_Unit_Point3D), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Air_Unit_Point3D *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Air_Unit_Point3D__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Air_Unit_TaskPath__Free (Air_Unit_TaskPath* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Air_Unit_TaskPath */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* ????????????????????????????????????��??????  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Air_Unit_Point3D)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Air_Unit_Point3D)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Air_Unit_Point3D))) */ ) {
    //ilu_DebugPrintf("OK Air_Unit_TaskPath__Free (Air_Unit_TaskPath* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Air_Unit_TaskPath *CORBA_sequence_Air_Unit_TaskPath_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_TaskPath *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_TaskPath) * _count;

  if ((_p = (Air_Unit_TaskPath *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_TaskPath* Air_Unit_TaskPath__alloc ()
{
  return ((Air_Unit_TaskPath*) CORBA_sequence_Air_Unit_TaskPath_allocbuf(1));
}

Air_Unit_Site* _Air_Unit_Site__Input (ilu_Call _call, Air_Unit_Site* _ref, ilu_Error *_err)
{
  Air_Unit_Site* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Air_Unit_Site), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Air_Unit_Site*) ilu_MallocE(sizeof (Air_Unit_Site), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_Site));
  };
  switch (tag) {
    case Air_Unit_Rectangle:
      (void) _Air_Unit_RectangleData__Input (_call, &_val->_u.rd,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Air_Unit_Circle:
      (void) _Air_Unit_CircleData__Input (_call, &_val->_u.cd,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (Air_Unit_SiteType) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Air_Unit_Site__Output (ilu_Call _call, Air_Unit_Site* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Air_Unit_Site), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Air_Unit_Rectangle:
      _Air_Unit_RectangleData__Output(_call, &_val->_u.rd, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Air_Unit_Circle:
      _Air_Unit_CircleData__Output(_call, &_val->_u.cd, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_Site__SizeOf (ilu_Call _call, Air_Unit_Site* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Air_Unit_Site), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Air_Unit_Rectangle:
      size += _Air_Unit_RectangleData__SizeOf (_call, &_val->_u.rd, _err);
      break;
    case Air_Unit_Circle:
      size += _Air_Unit_CircleData__SizeOf (_call, &_val->_u.cd, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_Site *CORBA_sequence_Air_Unit_Site_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_Site *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_Site) * _count;

  if ((_p = (Air_Unit_Site *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_Site* Air_Unit_Site__alloc ()
{
  return ((Air_Unit_Site*) CORBA_sequence_Air_Unit_Site_allocbuf(1));
}

Air_Unit_CircleData* _Air_Unit_CircleData__Input (ilu_Call _call, Air_Unit_CircleData* _ref, ilu_Error *_err)
{
  Air_Unit_CircleData* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_CircleData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_CircleData__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_CircleData*) ilu_MallocE (sizeof (Air_Unit_CircleData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_CircleData));
    } else {
      _val = (Air_Unit_CircleData*) _ILU_C_CRCreate (s, sizeof(Air_Unit_CircleData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_CircleData), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Air_Unit_Point3D__Input (_call, &_val->po,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->r, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_CircleData__Output (ilu_Call _call, Air_Unit_CircleData* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_CircleData__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_CircleData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_CircleData), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Air_Unit_Point3D__Output(_call, (&_val->po), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortInteger (_call, (_val->r), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_CircleData__SizeOf (ilu_Call _call, Air_Unit_CircleData* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_CircleData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_CircleData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_CircleData), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Air_Unit_Point3D__SizeOf (_call, &_val->po, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->r, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_CircleData *CORBA_sequence_Air_Unit_CircleData_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_CircleData *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_CircleData) * _count;

  if ((_p = (Air_Unit_CircleData *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_CircleData* Air_Unit_CircleData__alloc ()
{
  return ((Air_Unit_CircleData*) CORBA_sequence_Air_Unit_CircleData_allocbuf(1));
}

Air_Unit_RectangleData* _Air_Unit_RectangleData__Input (ilu_Call _call, Air_Unit_RectangleData* _ref, ilu_Error *_err)
{
  Air_Unit_RectangleData* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_RectangleData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_RectangleData__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_RectangleData*) ilu_MallocE (sizeof (Air_Unit_RectangleData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_RectangleData));
    } else {
      _val = (Air_Unit_RectangleData*) _ILU_C_CRCreate (s, sizeof(Air_Unit_RectangleData), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_RectangleData), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Air_Unit_Point3D__Input (_call, &_val->po,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->x, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->y, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_RectangleData__Output (ilu_Call _call, Air_Unit_RectangleData* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_RectangleData__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_RectangleData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_RectangleData), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Air_Unit_Point3D__Output(_call, (&_val->po), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortInteger (_call, (_val->x), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortInteger (_call, (_val->y), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_RectangleData__SizeOf (ilu_Call _call, Air_Unit_RectangleData* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_RectangleData__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_RectangleData__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_RectangleData), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Air_Unit_Point3D__SizeOf (_call, &_val->po, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->x, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->y, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_RectangleData *CORBA_sequence_Air_Unit_RectangleData_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_RectangleData *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_RectangleData) * _count;

  if ((_p = (Air_Unit_RectangleData *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_RectangleData* Air_Unit_RectangleData__alloc ()
{
  return ((Air_Unit_RectangleData*) CORBA_sequence_Air_Unit_RectangleData_allocbuf(1));
}

Air_Unit_SiteType *CORBA_sequence_Air_Unit_SiteType_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_SiteType *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_SiteType) * _count;

  if ((_p = (Air_Unit_SiteType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_TrapPoint3D* _Air_Unit_TrapPoint3D__Input (ilu_Call _call, Air_Unit_TrapPoint3D* _ref, ilu_Error *_err)
{
  Air_Unit_TrapPoint3D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_TrapPoint3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_TrapPoint3D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_TrapPoint3D*) ilu_MallocE (sizeof (Air_Unit_TrapPoint3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_TrapPoint3D));
    } else {
      _val = (Air_Unit_TrapPoint3D*) _ILU_C_CRCreate (s, sizeof(Air_Unit_TrapPoint3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_TrapPoint3D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Air_Unit_Point3D__Input (_call, &_val->point,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_TrapPoint3D__Output (ilu_Call _call, Air_Unit_TrapPoint3D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_TrapPoint3D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_TrapPoint3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_TrapPoint3D), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Air_Unit_Point3D__Output(_call, (&_val->point), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->radius), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_TrapPoint3D__SizeOf (ilu_Call _call, Air_Unit_TrapPoint3D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_TrapPoint3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_TrapPoint3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_TrapPoint3D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Air_Unit_Point3D__SizeOf (_call, &_val->point, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->radius, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_TrapPoint3D *CORBA_sequence_Air_Unit_TrapPoint3D_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_TrapPoint3D *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_TrapPoint3D) * _count;

  if ((_p = (Air_Unit_TrapPoint3D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_TrapPoint3D* Air_Unit_TrapPoint3D__alloc ()
{
  return ((Air_Unit_TrapPoint3D*) CORBA_sequence_Air_Unit_TrapPoint3D_allocbuf(1));
}

Air_Unit_Point3D* _Air_Unit_Point3D__Input (ilu_Call _call, Air_Unit_Point3D* _ref, ilu_Error *_err)
{
  Air_Unit_Point3D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_Point3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_Point3D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_Point3D*) ilu_MallocE (sizeof (Air_Unit_Point3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_Point3D));
    } else {
      _val = (Air_Unit_Point3D*) _ILU_C_CRCreate (s, sizeof(Air_Unit_Point3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Point3D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->x, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->y, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->z, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_Point3D__Output (ilu_Call _call, Air_Unit_Point3D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_Point3D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_Point3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Point3D), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->x), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->y), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->z), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_Point3D__SizeOf (ilu_Call _call, Air_Unit_Point3D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_Point3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_Point3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Point3D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->x, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->y, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->z, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_Point3D *CORBA_sequence_Air_Unit_Point3D_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_Point3D *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_Point3D) * _count;

  if ((_p = (Air_Unit_Point3D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_Point3D* Air_Unit_Point3D__alloc ()
{
  return ((Air_Unit_Point3D*) CORBA_sequence_Air_Unit_Point3D_allocbuf(1));
}

Air_Unit_AirUnitInfo* _Air_Unit_AirUnitInfo__Input (ilu_Call _call, Air_Unit_AirUnitInfo* _ref, ilu_Error *_err)
{
  Air_Unit_AirUnitInfo* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_AirUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_AirUnitInfo__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_AirUnitInfo*) ilu_MallocE (sizeof (Air_Unit_AirUnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_AirUnitInfo));
    } else {
      _val = (Air_Unit_AirUnitInfo*) _ILU_C_CRCreate (s, sizeof(Air_Unit_AirUnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_AirUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Unit_UnitInfo__Input (_call, &_val->info,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  {
    ilu_shortcardinal _xxx;
    ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    *&_val->role = (Unit_UnitRole) _xxx;
  };
  (void) _Air_Unit_Speed3D__Input (_call, &_val->speed,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Air_Unit_FusionAngularVelocity__Input (_call, &_val->angularVelocity,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Air_Unit_GPSInfo__Input (_call, &_val->gps,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Air_Unit_GimbalState__Input (_call, &_val->gs,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_AirUnitInfo__Output (ilu_Call _call, Air_Unit_AirUnitInfo* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_AirUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_AirUnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_AirUnitInfo), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Unit_UnitInfo__Output(_call, (&_val->info), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputEnum (_call, (ilu_shortcardinal) (_val->role), (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Air_Unit_Speed3D__Output(_call, (&_val->speed), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Air_Unit_FusionAngularVelocity__Output(_call, (&_val->angularVelocity), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Air_Unit_GPSInfo__Output(_call, (&_val->gps), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Air_Unit_GimbalState__Output(_call, (&_val->gs), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_AirUnitInfo__SizeOf (ilu_Call _call, Air_Unit_AirUnitInfo* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_AirUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_AirUnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_AirUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Unit_UnitInfo__SizeOf (_call, &_val->info, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) _val->role, (ilu_Type)ILU_NIL,  _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Air_Unit_Speed3D__SizeOf (_call, &_val->speed, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Air_Unit_FusionAngularVelocity__SizeOf (_call, &_val->angularVelocity, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Air_Unit_GPSInfo__SizeOf (_call, &_val->gps, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Air_Unit_GimbalState__SizeOf (_call, &_val->gs, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Air_Unit_AirUnitInfo__Free (Air_Unit_AirUnitInfo* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Air_Unit_AirUnitInfo */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Air_Unit_AirUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_AirUnitInfo__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  Unit_UnitInfo__Free (&_val->info);
}

Air_Unit_AirUnitInfo *CORBA_sequence_Air_Unit_AirUnitInfo_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_AirUnitInfo *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_AirUnitInfo) * _count;

  if ((_p = (Air_Unit_AirUnitInfo *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_AirUnitInfo* Air_Unit_AirUnitInfo__alloc ()
{
  return ((Air_Unit_AirUnitInfo*) CORBA_sequence_Air_Unit_AirUnitInfo_allocbuf(1));
}

Air_Unit_FusionAngularVelocity* _Air_Unit_FusionAngularVelocity__Input (ilu_Call _call, Air_Unit_FusionAngularVelocity* _ref, ilu_Error *_err)
{
  Air_Unit_FusionAngularVelocity* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_FusionAngularVelocity__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_FusionAngularVelocity__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_FusionAngularVelocity*) ilu_MallocE (sizeof (Air_Unit_FusionAngularVelocity), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_FusionAngularVelocity));
    } else {
      _val = (Air_Unit_FusionAngularVelocity*) _ILU_C_CRCreate (s, sizeof(Air_Unit_FusionAngularVelocity), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_FusionAngularVelocity), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->x, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->y, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->z, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_FusionAngularVelocity__Output (ilu_Call _call, Air_Unit_FusionAngularVelocity* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_FusionAngularVelocity__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_FusionAngularVelocity__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_FusionAngularVelocity), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->x), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->y), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->z), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_FusionAngularVelocity__SizeOf (ilu_Call _call, Air_Unit_FusionAngularVelocity* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_FusionAngularVelocity__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_FusionAngularVelocity__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_FusionAngularVelocity), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->x, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->y, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->z, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_FusionAngularVelocity *CORBA_sequence_Air_Unit_FusionAngularVelocity_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_FusionAngularVelocity *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_FusionAngularVelocity) * _count;

  if ((_p = (Air_Unit_FusionAngularVelocity *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_FusionAngularVelocity* Air_Unit_FusionAngularVelocity__alloc ()
{
  return ((Air_Unit_FusionAngularVelocity*) CORBA_sequence_Air_Unit_FusionAngularVelocity_allocbuf(1));
}

Air_Unit_Speed3D* _Air_Unit_Speed3D__Input (ilu_Call _call, Air_Unit_Speed3D* _ref, ilu_Error *_err)
{
  Air_Unit_Speed3D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_Speed3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_Speed3D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_Speed3D*) ilu_MallocE (sizeof (Air_Unit_Speed3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_Speed3D));
    } else {
      _val = (Air_Unit_Speed3D*) _ILU_C_CRCreate (s, sizeof(Air_Unit_Speed3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Speed3D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->x, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->y, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->z, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_Speed3D__Output (ilu_Call _call, Air_Unit_Speed3D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_Speed3D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_Speed3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Speed3D), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->x), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->y), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->z), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_Speed3D__SizeOf (ilu_Call _call, Air_Unit_Speed3D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_Speed3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_Speed3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Speed3D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->x, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->y, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->z, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_Speed3D *CORBA_sequence_Air_Unit_Speed3D_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_Speed3D *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_Speed3D) * _count;

  if ((_p = (Air_Unit_Speed3D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_Speed3D* Air_Unit_Speed3D__alloc ()
{
  return ((Air_Unit_Speed3D*) CORBA_sequence_Air_Unit_Speed3D_allocbuf(1));
}

Air_Unit_GPSInfo* _Air_Unit_GPSInfo__Input (ilu_Call _call, Air_Unit_GPSInfo* _ref, ilu_Error *_err)
{
  Air_Unit_GPSInfo* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_GPSInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_GPSInfo__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_GPSInfo*) ilu_MallocE (sizeof (Air_Unit_GPSInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_GPSInfo));
    } else {
      _val = (Air_Unit_GPSInfo*) _ILU_C_CRCreate (s, sizeof(Air_Unit_GPSInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GPSInfo), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->longitude, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->latitude, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->altitude, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->height, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->time, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->health, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_GPSInfo__Output (ilu_Call _call, Air_Unit_GPSInfo* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_GPSInfo__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_GPSInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GPSInfo), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->longitude), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->latitude), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->altitude), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->height), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->time), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortInteger (_call, (_val->health), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_GPSInfo__SizeOf (ilu_Call _call, Air_Unit_GPSInfo* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_GPSInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_GPSInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GPSInfo), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->longitude, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->latitude, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->altitude, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->height, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->time, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->health, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_GPSInfo *CORBA_sequence_Air_Unit_GPSInfo_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_GPSInfo *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_GPSInfo) * _count;

  if ((_p = (Air_Unit_GPSInfo *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_GPSInfo* Air_Unit_GPSInfo__alloc ()
{
  return ((Air_Unit_GPSInfo*) CORBA_sequence_Air_Unit_GPSInfo_allocbuf(1));
}

Air_Unit_Pose3D* _Air_Unit_Pose3D__Input (ilu_Call _call, Air_Unit_Pose3D* _ref, ilu_Error *_err)
{
  Air_Unit_Pose3D* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_Pose3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_Pose3D__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_Pose3D*) ilu_MallocE (sizeof (Air_Unit_Pose3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_Pose3D));
    } else {
      _val = (Air_Unit_Pose3D*) _ILU_C_CRCreate (s, sizeof(Air_Unit_Pose3D), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Pose3D), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->x, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->y, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->z, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->pitch, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->yaw, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->roll, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_Pose3D__Output (ilu_Call _call, Air_Unit_Pose3D* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_Pose3D__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_Pose3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Pose3D), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->x), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->y), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->z), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->pitch), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->yaw), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->roll), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_Pose3D__SizeOf (ilu_Call _call, Air_Unit_Pose3D* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_Pose3D__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_Pose3D__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_Pose3D), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->x, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->y, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->z, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->pitch, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->yaw, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->roll, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_Pose3D *CORBA_sequence_Air_Unit_Pose3D_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_Pose3D *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_Pose3D) * _count;

  if ((_p = (Air_Unit_Pose3D *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_Pose3D* Air_Unit_Pose3D__alloc ()
{
  return ((Air_Unit_Pose3D*) CORBA_sequence_Air_Unit_Pose3D_allocbuf(1));
}

Air_Unit_GimbalState* _Air_Unit_GimbalState__Input (ilu_Call _call, Air_Unit_GimbalState* _ref, ilu_Error *_err)
{
  Air_Unit_GimbalState* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_GimbalState__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_GimbalState__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_GimbalState*) ilu_MallocE (sizeof (Air_Unit_GimbalState), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_GimbalState));
    } else {
      _val = (Air_Unit_GimbalState*) _ILU_C_CRCreate (s, sizeof(Air_Unit_GimbalState), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GimbalState), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->yaw, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->roll, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->pitch, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_GimbalState__Output (ilu_Call _call, Air_Unit_GimbalState* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_GimbalState__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_GimbalState__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GimbalState), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->yaw), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->roll), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->pitch), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_GimbalState__SizeOf (ilu_Call _call, Air_Unit_GimbalState* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_GimbalState__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_GimbalState__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GimbalState), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->yaw, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->roll, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->pitch, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_GimbalState *CORBA_sequence_Air_Unit_GimbalState_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_GimbalState *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_GimbalState) * _count;

  if ((_p = (Air_Unit_GimbalState *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_GimbalState* Air_Unit_GimbalState__alloc ()
{
  return ((Air_Unit_GimbalState*) CORBA_sequence_Air_Unit_GimbalState_allocbuf(1));
}

Air_Unit_GimbalSpeed* _Air_Unit_GimbalSpeed__Input (ilu_Call _call, Air_Unit_GimbalSpeed* _ref, ilu_Error *_err)
{
  Air_Unit_GimbalSpeed* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_GimbalSpeed__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_GimbalSpeed__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Air_Unit_GimbalSpeed*) ilu_MallocE (sizeof (Air_Unit_GimbalSpeed), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Air_Unit_GimbalSpeed));
    } else {
      _val = (Air_Unit_GimbalSpeed*) _ILU_C_CRCreate (s, sizeof(Air_Unit_GimbalSpeed), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GimbalSpeed), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->yaw, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->roll, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->pitch, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Air_Unit_GimbalSpeed__Output (ilu_Call _call, Air_Unit_GimbalSpeed* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Air_Unit_GimbalSpeed__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Air_Unit_GimbalSpeed__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GimbalSpeed), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortReal(_call, (_val->yaw), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->roll), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->pitch), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Air_Unit_GimbalSpeed__SizeOf (ilu_Call _call, Air_Unit_GimbalSpeed* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Air_Unit_GimbalSpeed__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Air_Unit_GimbalSpeed__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Air_Unit_GimbalSpeed), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->yaw, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->roll, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->pitch, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Air_Unit_GimbalSpeed *CORBA_sequence_Air_Unit_GimbalSpeed_allocbuf (CORBA_unsigned_long _count)
{
  Air_Unit_GimbalSpeed *_p;
  CORBA_unsigned_long _size = sizeof(Air_Unit_GimbalSpeed) * _count;

  if ((_p = (Air_Unit_GimbalSpeed *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Air_Unit_GimbalSpeed* Air_Unit_GimbalSpeed__alloc ()
{
  return ((Air_Unit_GimbalSpeed*) CORBA_sequence_Air_Unit_GimbalSpeed_allocbuf(1));
}

void Air_Unit_TrapPointSeq_Every (Air_Unit_TrapPointSeq *h, void (*f)(Air_Unit_TrapPoint3D*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Air_Unit_TrapPoint3D), (void *) data);
}

void Air_Unit_TrapPointSeq_Append (Air_Unit_TrapPointSeq *h, Air_Unit_TrapPoint3D* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Air_Unit_TrapPoint3D), err);
}

void Air_Unit_TrapPointSeq_Push (Air_Unit_TrapPointSeq *h, Air_Unit_TrapPoint3D* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Air_Unit_TrapPoint3D));
}

void Air_Unit_TrapPointSeq_Pop (Air_Unit_TrapPointSeq *h, Air_Unit_TrapPoint3D* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Air_Unit_TrapPoint3D));
}

CORBA_unsigned_long Air_Unit_TrapPointSeq_Length (Air_Unit_TrapPointSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Air_Unit_TrapPoint3D * Air_Unit_TrapPointSeq_Nth (Air_Unit_TrapPointSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Air_Unit_TrapPointSeq * Air_Unit_TrapPointSeq_Create (CORBA_unsigned_long sz, Air_Unit_TrapPoint3D* p)
{
  Air_Unit_TrapPointSeq *s;
  s = (Air_Unit_TrapPointSeq *) ilu_malloc(sizeof(Air_Unit_TrapPointSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Air_Unit_TrapPointSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Air_Unit_TrapPoint3D *) ilu_malloc(sz * sizeof(Air_Unit_TrapPoint3D))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Air_Unit_TrapPoint3D));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Air_Unit_TrapPointSeq_Init (Air_Unit_TrapPointSeq *s, CORBA_unsigned_long sz, Air_Unit_TrapPoint3D* p)
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
    s->_buffer = (Air_Unit_TrapPoint3D *) ilu_malloc (sz * sizeof (Air_Unit_TrapPoint3D));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Air_Unit_TrapPoint3D)); }}
  else
    s->_buffer = p;
  return;
}

void Air_Unit_TaskPath_Every (Air_Unit_TaskPath *h, void (*f)(Air_Unit_Point3D*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Air_Unit_Point3D), (void *) data);
}

void Air_Unit_TaskPath_Append (Air_Unit_TaskPath *h, Air_Unit_Point3D* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Air_Unit_Point3D), err);
}

void Air_Unit_TaskPath_Push (Air_Unit_TaskPath *h, Air_Unit_Point3D* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Air_Unit_Point3D));
}

void Air_Unit_TaskPath_Pop (Air_Unit_TaskPath *h, Air_Unit_Point3D* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Air_Unit_Point3D));
}

CORBA_unsigned_long Air_Unit_TaskPath_Length (Air_Unit_TaskPath *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Air_Unit_Point3D * Air_Unit_TaskPath_Nth (Air_Unit_TaskPath *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Air_Unit_TaskPath * Air_Unit_TaskPath_Create (CORBA_unsigned_long sz, Air_Unit_Point3D* p)
{
  Air_Unit_TaskPath *s;
  s = (Air_Unit_TaskPath *) ilu_malloc(sizeof(Air_Unit_TaskPath));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Air_Unit_TaskPath)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Air_Unit_Point3D *) ilu_malloc(sz * sizeof(Air_Unit_Point3D))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Air_Unit_Point3D));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Air_Unit_TaskPath_Init (Air_Unit_TaskPath *s, CORBA_unsigned_long sz, Air_Unit_Point3D* p)
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
    s->_buffer = (Air_Unit_Point3D *) ilu_malloc (sz * sizeof (Air_Unit_Point3D));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Air_Unit_Point3D)); }}
  else
    s->_buffer = p;
  return;
}

void _Air_Unit__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Air-Unit", "2.0beta1", "v2 (2.0beta1)");
  _Unit__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	"IDL:Unit/rpc:1.0",
	NULL};
    cl = ilu_DefineObjectType("Air-Unit.rpc",	/*name*/
	NULL,	/*no brand*/
	"IDL:Air_Unit/rpc:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	30,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Air_Unit_rpc__ILUType = cl;
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
	"IDL:Air_Unit/Speed3D:1.0",	/*return type ID*/
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
	"IDL:Air_Unit/Pose3D:1.0",	/*return type ID*/
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
	"IDL:Air_Unit/AirUnitInfo:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"sendGimbalSpeed",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "speed", ilu_FALSE, ilu_In, "IDL:Air_Unit/GimbalSpeed:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"resetGimbal",	/*name*/
	5,	/*id*/
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
    m = ilu_DefineMethod(cl, 5,
	"sendVehicleInfo",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "info", ilu_FALSE, ilu_In, "IDL:Air_Unit/AirUnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 6,
	"reportTrap",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "trap", ilu_FALSE, ilu_In, "IDL:Air_Unit/TrapPoint3D:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 7,
	"clearTraps",	/*name*/
	8,	/*id*/
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
    m = ilu_DefineMethod(cl, 8,
	"getTraps",	/*name*/
	9,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:f64M6WyJqOAUgQjEF7bfqsiJsHE",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 9,
	"setTrapPoint",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "trap", ilu_FALSE, ilu_In, "IDL:Air_Unit/TrapPoint3D:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 10,
	"setTrack",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "track", ilu_FALSE, ilu_In, "ilut:dytiAb5pMGEVcFZXX98Jo+mue-R", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 11,
	"setTaskPath",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "path", ilu_FALSE, ilu_In, "ilut:dytiAb5pMGEVcFZXX98Jo+mue-R", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 12,
	"setTaskPoint",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "point", ilu_FALSE, ilu_In, "IDL:Air_Unit/Point3D:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 13,
	"clearTaskPoint",	/*name*/
	14,	/*id*/
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
    m = ilu_DefineMethod(cl, 14,
	"obtainCtrlAuthority",	/*name*/
	15,	/*id*/
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
    m = ilu_DefineMethod(cl, 15,
	"releaseCtrlAuthority",	/*name*/
	16,	/*id*/
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
    m = ilu_DefineMethod(cl, 16,
	"setActionRole",	/*name*/
	17,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "ar", ilu_FALSE, ilu_In, "IDL:Air_Unit/ActionRole:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 17,
	"setActionMode",	/*name*/
	18,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "am", ilu_FALSE, ilu_In, "IDL:Air_Unit/ActionMode:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 18,
	"setCruiseScope",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "s", ilu_FALSE, ilu_In, "IDL:Air_Unit/Site:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 19,
	"sendControlledVehicle",	/*name*/
	20,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "uss", ilu_FALSE, ilu_In, "ilut:dP+it8jaImjeTpCavo8lYlCeZfT", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 20,
	"confirmThrow",	/*name*/
	21,	/*id*/
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
    m = ilu_DefineMethod(cl, 21,
	"cancelThrow",	/*name*/
	22,	/*id*/
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
    m = ilu_DefineMethod(cl, 22,
	"actionThrow",	/*name*/
	23,	/*id*/
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
    m = ilu_DefineMethod(cl, 23,
	"confirmFire",	/*name*/
	24,	/*id*/
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
    m = ilu_DefineMethod(cl, 24,
	"cancelFire",	/*name*/
	25,	/*id*/
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
    m = ilu_DefineMethod(cl, 25,
	"confirmFireLocation",	/*name*/
	26,	/*id*/
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
    m = ilu_DefineMethod(cl, 26,
	"cancelFireLocation",	/*name*/
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
	"controlVehicleVelocity",	/*name*/
	28,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	4,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "vx", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "vy", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "vz", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 3, "angle", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 28,
	"backHome",	/*name*/
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
	"setCruiseSpeed",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "cs", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Air_Unit_rpc__IoFns.kernelType = ilu_RegisterObjectType("rpc", "Air-Unit", ILU_NIL, "IDL:Air_Unit/rpc:1.0",
    _Air_Unit_rpc__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Air_Unit_ActionMode__IoFns.kernelType = type = ilu_RegisterEnumerationType("ActionMode", "Air-Unit", ILU_NIL, "IDL:Air_Unit/ActionMode:1.0",
    5,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "Nothing", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "Cruise", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "Locate", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "Assist", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 4, /* which element */
    "Feedback", /* element name */
    4,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_ActionRole__IoFns.kernelType = type = ilu_RegisterEnumerationType("ActionRole", "Air-Unit", ILU_NIL, "IDL:Air_Unit/ActionRole:1.0",
    3,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "Actor", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "Standby", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "Facilitators", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_TrapPointSeq__IoFns.kernelType = ilu_RegisterSequenceType("TrapPointSeq", "Air-Unit", ILU_NIL, "ilut:f64M6WyJqOAUgQjEF7bfqsiJsHE",
    "IDL:Air_Unit/TrapPoint3D:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Air_Unit_TaskPath__IoFns.kernelType = ilu_RegisterSequenceType("TaskPath", "Air-Unit", ILU_NIL, "ilut:dytiAb5pMGEVcFZXX98Jo+mue-R",
    "IDL:Air_Unit/Point3D:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Air_Unit_Site__IoFns.kernelType = type = ilu_RegisterUnionType("Site", "Air-Unit", ILU_NIL, "IDL:Air_Unit/Site:1.0",
    "IDL:Air_Unit/SiteType:1.0",	/* UID of discriminant type */
    2,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "rd", /* name of arm */
      "IDL:Air_Unit/RectangleData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "Rectangle";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "cd", /* name of arm */
      "IDL:Air_Unit/CircleData:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "Circle";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_CircleData__IoFns.kernelType = type = ilu_RegisterRecordType("CircleData", "Air-Unit", ILU_NIL, "IDL:Air_Unit/CircleData:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "po", /* field name */
      "IDL:Air_Unit/Point3D:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "r", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_RectangleData__IoFns.kernelType = type = ilu_RegisterRecordType("RectangleData", "Air-Unit", ILU_NIL, "IDL:Air_Unit/RectangleData:1.0",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "po", /* field name */
      "IDL:Air_Unit/Point3D:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "x", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "y", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_SiteType__IoFns.kernelType = type = ilu_RegisterEnumerationType("SiteType", "Air-Unit", ILU_NIL, "IDL:Air_Unit/SiteType:1.0",
    2,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "Rectangle", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "Circle", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_TrapPoint3D__IoFns.kernelType = type = ilu_RegisterRecordType("TrapPoint3D", "Air-Unit", ILU_NIL, "IDL:Air_Unit/TrapPoint3D:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "point", /* field name */
      "IDL:Air_Unit/Point3D:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "radius", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_Point3D__IoFns.kernelType = type = ilu_RegisterRecordType("Point3D", "Air-Unit", ILU_NIL, "IDL:Air_Unit/Point3D:1.0",
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
      "z", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_AirUnitInfo__IoFns.kernelType = type = ilu_RegisterRecordType("AirUnitInfo", "Air-Unit", ILU_NIL, "IDL:Air_Unit/AirUnitInfo:1.0",
    6,	/* number of fields in the record */
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
      "IDL:Air_Unit/Speed3D:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "angularVelocity", /* field name */
      "IDL:Air_Unit/FusionAngularVelocity:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "gps", /* field name */
      "IDL:Air_Unit/GPSInfo:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "gs", /* field name */
      "IDL:Air_Unit/GimbalState:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_FusionAngularVelocity__IoFns.kernelType = type = ilu_RegisterRecordType("FusionAngularVelocity", "Air-Unit", ILU_NIL, "IDL:Air_Unit/FusionAngularVelocity:1.0",
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
      "z", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_Speed3D__IoFns.kernelType = type = ilu_RegisterRecordType("Speed3D", "Air-Unit", ILU_NIL, "IDL:Air_Unit/Speed3D:1.0",
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
      "z", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_GPSInfo__IoFns.kernelType = type = ilu_RegisterRecordType("GPSInfo", "Air-Unit", ILU_NIL, "IDL:Air_Unit/GPSInfo:1.0",
    6,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "longitude", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "latitude", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "altitude", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "height", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "time", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "health", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_Pose3D__IoFns.kernelType = type = ilu_RegisterRecordType("Pose3D", "Air-Unit", ILU_NIL, "IDL:Air_Unit/Pose3D:1.0",
    6,	/* number of fields in the record */
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
      "z", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "pitch", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "yaw", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "roll", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_GimbalState__IoFns.kernelType = type = ilu_RegisterRecordType("GimbalState", "Air-Unit", ILU_NIL, "IDL:Air_Unit/GimbalState:1.0",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "yaw", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "roll", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "pitch", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Air_Unit_GimbalSpeed__IoFns.kernelType = type = ilu_RegisterRecordType("GimbalSpeed", "Air-Unit", ILU_NIL, "IDL:Air_Unit/GimbalSpeed:1.0",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "yaw", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "roll", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "pitch", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Air_Unit_rpc__IoFns.properties.object_class = _Air_Unit_rpc__ILUType;
  _ILU_C_RegisterIoFns (&_Air_Unit_rpc__IoFns);

  _ILU_C_RegisterIoFns (&_Air_Unit_ActionMode__IoFns);

  _ILU_C_RegisterIoFns (&_Air_Unit_ActionRole__IoFns);

  _Air_Unit_TrapPointSeq__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_TrapPointSeq__Input;
  _Air_Unit_TrapPointSeq__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_TrapPointSeq__Output;
  _Air_Unit_TrapPointSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_TrapPointSeq__SizeOf;
  _Air_Unit_TrapPointSeq__IoFns.freeFn = (ILU_C_FreeFn) Air_Unit_TrapPointSeq__Free;
  _ILU_C_RegisterIoFns (&_Air_Unit_TrapPointSeq__IoFns);

  _Air_Unit_TaskPath__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_TaskPath__Input;
  _Air_Unit_TaskPath__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_TaskPath__Output;
  _Air_Unit_TaskPath__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_TaskPath__SizeOf;
  _Air_Unit_TaskPath__IoFns.freeFn = (ILU_C_FreeFn) Air_Unit_TaskPath__Free;
  _ILU_C_RegisterIoFns (&_Air_Unit_TaskPath__IoFns);

  _Air_Unit_Site__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_Site__Input;
  _Air_Unit_Site__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_Site__Output;
  _Air_Unit_Site__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_Site__SizeOf;
  _Air_Unit_Site__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_Site__IoFns);

  _Air_Unit_CircleData__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_CircleData__Input;
  _Air_Unit_CircleData__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_CircleData__Output;
  _Air_Unit_CircleData__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_CircleData__SizeOf;
  _Air_Unit_CircleData__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_CircleData__IoFns);

  _Air_Unit_RectangleData__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_RectangleData__Input;
  _Air_Unit_RectangleData__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_RectangleData__Output;
  _Air_Unit_RectangleData__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_RectangleData__SizeOf;
  _Air_Unit_RectangleData__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_RectangleData__IoFns);

  _ILU_C_RegisterIoFns (&_Air_Unit_SiteType__IoFns);

  _Air_Unit_TrapPoint3D__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_TrapPoint3D__Input;
  _Air_Unit_TrapPoint3D__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_TrapPoint3D__Output;
  _Air_Unit_TrapPoint3D__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_TrapPoint3D__SizeOf;
  _Air_Unit_TrapPoint3D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_TrapPoint3D__IoFns);

  _Air_Unit_Point3D__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_Point3D__Input;
  _Air_Unit_Point3D__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_Point3D__Output;
  _Air_Unit_Point3D__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_Point3D__SizeOf;
  _Air_Unit_Point3D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_Point3D__IoFns);

  _Air_Unit_AirUnitInfo__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_AirUnitInfo__Input;
  _Air_Unit_AirUnitInfo__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_AirUnitInfo__Output;
  _Air_Unit_AirUnitInfo__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_AirUnitInfo__SizeOf;
  _Air_Unit_AirUnitInfo__IoFns.freeFn = (ILU_C_FreeFn) Air_Unit_AirUnitInfo__Free;
  _ILU_C_RegisterIoFns (&_Air_Unit_AirUnitInfo__IoFns);

  _Air_Unit_FusionAngularVelocity__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_FusionAngularVelocity__Input;
  _Air_Unit_FusionAngularVelocity__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_FusionAngularVelocity__Output;
  _Air_Unit_FusionAngularVelocity__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_FusionAngularVelocity__SizeOf;
  _Air_Unit_FusionAngularVelocity__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_FusionAngularVelocity__IoFns);

  _Air_Unit_Speed3D__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_Speed3D__Input;
  _Air_Unit_Speed3D__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_Speed3D__Output;
  _Air_Unit_Speed3D__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_Speed3D__SizeOf;
  _Air_Unit_Speed3D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_Speed3D__IoFns);

  _Air_Unit_GPSInfo__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_GPSInfo__Input;
  _Air_Unit_GPSInfo__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_GPSInfo__Output;
  _Air_Unit_GPSInfo__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_GPSInfo__SizeOf;
  _Air_Unit_GPSInfo__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_GPSInfo__IoFns);

  _Air_Unit_Pose3D__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_Pose3D__Input;
  _Air_Unit_Pose3D__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_Pose3D__Output;
  _Air_Unit_Pose3D__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_Pose3D__SizeOf;
  _Air_Unit_Pose3D__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_Pose3D__IoFns);

  _Air_Unit_GimbalState__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_GimbalState__Input;
  _Air_Unit_GimbalState__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_GimbalState__Output;
  _Air_Unit_GimbalState__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_GimbalState__SizeOf;
  _Air_Unit_GimbalState__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_GimbalState__IoFns);

  _Air_Unit_GimbalSpeed__IoFns.inputFn = (ILU_C_InputFn) _Air_Unit_GimbalSpeed__Input;
  _Air_Unit_GimbalSpeed__IoFns.outFn = (ILU_C_OutputFn) _Air_Unit_GimbalSpeed__Output;
  _Air_Unit_GimbalSpeed__IoFns.sizeFn = (ILU_C_SizeFn) _Air_Unit_GimbalSpeed__SizeOf;
  _Air_Unit_GimbalSpeed__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Air_Unit_GimbalSpeed__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

