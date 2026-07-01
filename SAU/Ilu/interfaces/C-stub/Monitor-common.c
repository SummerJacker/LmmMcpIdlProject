/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:29:23 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/monitor.idl" of Wed Jul 16 16:43:00 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Monitor.h"

ilu_Class _Monitor_rpc__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Monitor_rpc__IoFns = { ilu_object_tk, "IDL:Monitor/rpc:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_PictureInfo__IoFns = { ilu_record_tk, "IDL:Monitor/PictureInfo:1.0", { sizeof(Monitor_PictureInfo) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_PictureFlow__IoFns = { ilu_sequence_tk, "ilut:gDDT46ADZpu8AunPkx2DQ2MCyfH", { sizeof(Monitor_PictureFlow) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_MissionSituation__IoFns = { ilu_enumeration_tk, "IDL:Monitor/MissionSituation:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_BackHomeReason__IoFns = { ilu_enumeration_tk, "IDL:Monitor/BackHomeReason:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_TargetID__IoFns = { ilu_alias_tk, "IDL:Monitor/TargetID:1.0", { sizeof(Monitor_TargetID) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_TargetType__IoFns = { ilu_enumeration_tk, "IDL:Monitor/TargetType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_CompleteUnitInfo__IoFns = { ilu_record_tk, "IDL:Monitor/CompleteUnitInfo:1.0", { sizeof(Monitor_CompleteUnitInfo) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_CurrentUnitInfo__IoFns = { ilu_union_tk, "IDL:Monitor/CurrentUnitInfo:1.0", { sizeof(Monitor_CurrentUnitInfo) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_UnitType__IoFns = { ilu_enumeration_tk, "IDL:Monitor/UnitType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Monitor_UnitState__IoFns = { ilu_record_tk, "IDL:Monitor/UnitState:1.0", { sizeof(Monitor_UnitState) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class Monitor_rpc__MakeClass(
  CORBA_boolean (*Monitor_rpc_sendUnitInfo__Impl)
     (Monitor_rpc _handle, Monitor_CompleteUnitInfo* unitInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendTrapPoint__Impl)
     (Monitor_rpc _handle, Console_TrapPoint* tp, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendTargetLocation__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, Ground_Unit_Point2D* fp, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_foundTarget__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_PictureInfo* pi, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_confirmAction__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_backHome__Impl)
     (Monitor_rpc _handle, Unit_UnitID uid, Monitor_BackHomeReason bhr, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendMissionState__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_MissionSituation ms, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendPicture__Impl)
     (Monitor_rpc _handle, ilu_CString pictureName, Monitor_PictureFlow* pic, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Monitor_rpc__ILUType;
  method_block = ilu_malloc(8 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Monitor_rpc_sendUnitInfo__Impl;
  method_block[1] = (_ILU_C_Method) Monitor_rpc_sendTrapPoint__Impl;
  method_block[2] = (_ILU_C_Method) Monitor_rpc_sendTargetLocation__Impl;
  method_block[3] = (_ILU_C_Method) Monitor_rpc_foundTarget__Impl;
  method_block[4] = (_ILU_C_Method) Monitor_rpc_confirmAction__Impl;
  method_block[5] = (_ILU_C_Method) Monitor_rpc_backHome__Impl;
  method_block[6] = (_ILU_C_Method) Monitor_rpc_sendMissionState__Impl;
  method_block[7] = (_ILU_C_Method) Monitor_rpc_sendPicture__Impl;

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
CORBA_boolean Monitor_rpc_sendUnitInfo (Monitor_rpc _handle, Monitor_CompleteUnitInfo* unitInfo, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, Monitor_CompleteUnitInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, Monitor_CompleteUnitInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, unitInfo, _status));
}

CORBA_boolean Monitor_rpc_sendTrapPoint (Monitor_rpc _handle, Console_TrapPoint* tp, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, Console_TrapPoint*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, Console_TrapPoint*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, tp, _status));
}

CORBA_boolean Monitor_rpc_sendTargetLocation (Monitor_rpc _handle, Monitor_TargetID fid, Ground_Unit_Point2D* fp, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, Monitor_TargetID, Ground_Unit_Point2D*, CORBA_short, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, Monitor_TargetID, Ground_Unit_Point2D*, CORBA_short, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, fid, fp, responseTime, _status));
}

CORBA_boolean Monitor_rpc_foundTarget (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_PictureInfo* pi, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, Monitor_TargetID, Monitor_PictureInfo*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, Monitor_TargetID, Monitor_PictureInfo*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, fid, pi, _status));
}

CORBA_boolean Monitor_rpc_confirmAction (Monitor_rpc _handle, Monitor_TargetID fid, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, Monitor_TargetID, CORBA_short, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, Monitor_TargetID, CORBA_short, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, fid, responseTime, _status));
}

CORBA_boolean Monitor_rpc_backHome (Monitor_rpc _handle, Unit_UnitID uid, Monitor_BackHomeReason bhr, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, Unit_UnitID, Monitor_BackHomeReason, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, Unit_UnitID, Monitor_BackHomeReason, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, uid, bhr, _status));
}

CORBA_boolean Monitor_rpc_sendMissionState (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_MissionSituation ms, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, Monitor_TargetID, Monitor_MissionSituation, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, Monitor_TargetID, Monitor_MissionSituation, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, fid, ms, _status));
}

CORBA_boolean Monitor_rpc_sendPicture (Monitor_rpc _handle, ilu_CString pictureName, Monitor_PictureFlow* pic, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(Monitor_rpc, ilu_CString, Monitor_PictureFlow*, CORBA_long, CORBA_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(Monitor_rpc, ilu_CString, Monitor_PictureFlow*, CORBA_long, CORBA_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Monitor_rpc__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, pictureName, pic, time, procedureStartTime, _status));
}

void Monitor_rpc__SetUserData (Monitor_rpc self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Monitor_rpc__GetUserData (Monitor_rpc self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Monitor_rpc__Free (Monitor_rpc* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Monitor_rpc */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Monitor_rpc *CORBA_sequence_Monitor_rpc_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_rpc *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_rpc) * _count;

  if ((_p = (Monitor_rpc *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_PictureInfo* _Monitor_PictureInfo__Input (ilu_Call _call, Monitor_PictureInfo* _ref, ilu_Error *_err)
{
  Monitor_PictureInfo* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Monitor_PictureInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_PictureInfo__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Monitor_PictureInfo*) ilu_MallocE (sizeof (Monitor_PictureInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Monitor_PictureInfo));
    } else {
      _val = (Monitor_PictureInfo*) _ILU_C_CRCreate (s, sizeof(Monitor_PictureInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Monitor_PictureInfo), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->picturName, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Monitor_PictureFlow__Input (_call, &_val->pic,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Monitor_CurrentUnitInfo__Input (_call, &_val->cui,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->responseTime, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Monitor_PictureInfo__Output (ilu_Call _call, Monitor_PictureInfo* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Monitor_PictureInfo__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Monitor_PictureInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Monitor_PictureInfo), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ilu_CString__Output (_call, (_val->picturName), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Monitor_PictureFlow__Output(_call, (&_val->pic), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Monitor_CurrentUnitInfo__Output(_call, (&_val->cui), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortInteger (_call, (_val->responseTime), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Monitor_PictureInfo__SizeOf (ilu_Call _call, Monitor_PictureInfo* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Monitor_PictureInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_PictureInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Monitor_PictureInfo), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->picturName, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Monitor_PictureFlow__SizeOf (_call, &_val->pic, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Monitor_CurrentUnitInfo__SizeOf (_call, &_val->cui, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->responseTime, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Monitor_PictureInfo__Free (Monitor_PictureInfo* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Monitor_PictureInfo */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Monitor_PictureInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_PictureInfo__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  ilu_CString__Free ((ilu_CString *) &_val->picturName);
  Monitor_PictureFlow__Free (&_val->pic);
  Monitor_CurrentUnitInfo__Free (&_val->cui);
}

Monitor_PictureInfo *CORBA_sequence_Monitor_PictureInfo_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_PictureInfo *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_PictureInfo) * _count;

  if ((_p = (Monitor_PictureInfo *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_PictureInfo* Monitor_PictureInfo__alloc ()
{
  return ((Monitor_PictureInfo*) CORBA_sequence_Monitor_PictureInfo_allocbuf(1));
}

Monitor_PictureFlow* _Monitor_PictureFlow__Input (ilu_Call _call, Monitor_PictureFlow* _ref, ilu_Error *_err)
{
  Monitor_PictureFlow* _val = _ref;

  ilu_cardinal len=0;
  ilu_cardinal limit = 0;
  ilu_bytes b = ILU_NIL;

  if (_ref == ILU_NIL) {
    _val = (Monitor_PictureFlow *) ilu_MallocE(sizeof(Monitor_PictureFlow), _err);
    if (_val == ILU_NIL)  goto marshalError;
  } else {
    if ((_ref->_buffer != ILU_NIL) && (_ref->_maximum > 0)) {
      limit = ((0 != 0) && (_ref->_maximum > 0)) ? 0 : _ref->_maximum;
      b = _ref->_buffer;
    };
  };
  ilu_InputBytes (_call, &b, &len, limit, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  _val->_length = len;
  if ((_ref == ILU_NIL) || (b != _ref->_buffer)) {
    _val->_maximum = len;
    _val->_buffer = b;
  };
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Monitor_PictureFlow__Output (ilu_Call _call, Monitor_PictureFlow* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputBytes (_call, _val->_buffer, _val->_length, 0, _err);
 marshalError:
  return;
}

ilu_cardinal _Monitor_PictureFlow__SizeOf (ilu_Call _call, Monitor_PictureFlow* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfBytes (_call, _val->_buffer, _val->_length, 0, _err);
  return size;
}

void Monitor_PictureFlow__Free (Monitor_PictureFlow* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Monitor_PictureFlow */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_octet)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_octet)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_octet))) */ ) {
    //ilu_DebugPrintf("OK Monitor_PictureFlow__Free (Monitor_PictureFlow* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Monitor_PictureFlow *CORBA_sequence_Monitor_PictureFlow_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_PictureFlow *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_PictureFlow) * _count;

  if ((_p = (Monitor_PictureFlow *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_PictureFlow* Monitor_PictureFlow__alloc ()
{
  return ((Monitor_PictureFlow*) CORBA_sequence_Monitor_PictureFlow_allocbuf(1));
}

Monitor_MissionSituation *CORBA_sequence_Monitor_MissionSituation_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_MissionSituation *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_MissionSituation) * _count;

  if ((_p = (Monitor_MissionSituation *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_BackHomeReason *CORBA_sequence_Monitor_BackHomeReason_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_BackHomeReason *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_BackHomeReason) * _count;

  if ((_p = (Monitor_BackHomeReason *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_TargetType *CORBA_sequence_Monitor_TargetType_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_TargetType *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_TargetType) * _count;

  if ((_p = (Monitor_TargetType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_CompleteUnitInfo* _Monitor_CompleteUnitInfo__Input (ilu_Call _call, Monitor_CompleteUnitInfo* _ref, ilu_Error *_err)
{
  Monitor_CompleteUnitInfo* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Monitor_CompleteUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_CompleteUnitInfo__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Monitor_CompleteUnitInfo*) ilu_MallocE (sizeof (Monitor_CompleteUnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Monitor_CompleteUnitInfo));
    } else {
      _val = (Monitor_CompleteUnitInfo*) _ILU_C_CRCreate (s, sizeof(Monitor_CompleteUnitInfo), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Monitor_CompleteUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Monitor_UnitState__Input (_call, &_val->us,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Monitor_CurrentUnitInfo__Input (_call, &_val->cui,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Monitor_CompleteUnitInfo__Output (ilu_Call _call, Monitor_CompleteUnitInfo* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Monitor_CompleteUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Monitor_CompleteUnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Monitor_CompleteUnitInfo), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Monitor_UnitState__Output(_call, (&_val->us), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Monitor_CurrentUnitInfo__Output(_call, (&_val->cui), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Monitor_CompleteUnitInfo__SizeOf (ilu_Call _call, Monitor_CompleteUnitInfo* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Monitor_CompleteUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_CompleteUnitInfo__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Monitor_CompleteUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Monitor_UnitState__SizeOf (_call, &_val->us, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Monitor_CurrentUnitInfo__SizeOf (_call, &_val->cui, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Monitor_CompleteUnitInfo__Free (Monitor_CompleteUnitInfo* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Monitor_CompleteUnitInfo */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Monitor_CompleteUnitInfo__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_CompleteUnitInfo__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  Monitor_CurrentUnitInfo__Free (&_val->cui);
}

Monitor_CompleteUnitInfo *CORBA_sequence_Monitor_CompleteUnitInfo_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_CompleteUnitInfo *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_CompleteUnitInfo) * _count;

  if ((_p = (Monitor_CompleteUnitInfo *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_CompleteUnitInfo* Monitor_CompleteUnitInfo__alloc ()
{
  return ((Monitor_CompleteUnitInfo*) CORBA_sequence_Monitor_CompleteUnitInfo_allocbuf(1));
}

Monitor_CurrentUnitInfo* _Monitor_CurrentUnitInfo__Input (ilu_Call _call, Monitor_CurrentUnitInfo* _ref, ilu_Error *_err)
{
  Monitor_CurrentUnitInfo* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Monitor_CurrentUnitInfo), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Monitor_CurrentUnitInfo*) ilu_MallocE(sizeof (Monitor_CurrentUnitInfo), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Monitor_CurrentUnitInfo));
  };
  switch (tag) {
    case Monitor_UnitGroundType:
      (void) _Ground_Unit_GroundUnitInfo__Input (_call, &_val->_u.groundUnitInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Monitor_UnitAirType:
      (void) _Air_Unit_AirUnitInfo__Input (_call, &_val->_u.airUnitInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (Monitor_UnitType) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Monitor_CurrentUnitInfo__Output (ilu_Call _call, Monitor_CurrentUnitInfo* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Monitor_CurrentUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Monitor_UnitGroundType:
      _Ground_Unit_GroundUnitInfo__Output(_call, &_val->_u.groundUnitInfo, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Monitor_UnitAirType:
      _Air_Unit_AirUnitInfo__Output(_call, &_val->_u.airUnitInfo, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Monitor_CurrentUnitInfo__SizeOf (ilu_Call _call, Monitor_CurrentUnitInfo* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Monitor_CurrentUnitInfo), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Monitor_UnitGroundType:
      size += _Ground_Unit_GroundUnitInfo__SizeOf (_call, &_val->_u.groundUnitInfo, _err);
      break;
    case Monitor_UnitAirType:
      size += _Air_Unit_AirUnitInfo__SizeOf (_call, &_val->_u.airUnitInfo, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Monitor_CurrentUnitInfo__Free (Monitor_CurrentUnitInfo* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Monitor_CurrentUnitInfo */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case Monitor_UnitGroundType:
      Ground_Unit_GroundUnitInfo__Free (&_val->_u.groundUnitInfo);
      break;
    case Monitor_UnitAirType:
      Air_Unit_AirUnitInfo__Free (&_val->_u.airUnitInfo);
      break;
    default:
      break;
  };
}

Monitor_CurrentUnitInfo *CORBA_sequence_Monitor_CurrentUnitInfo_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_CurrentUnitInfo *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_CurrentUnitInfo) * _count;

  if ((_p = (Monitor_CurrentUnitInfo *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_CurrentUnitInfo* Monitor_CurrentUnitInfo__alloc ()
{
  return ((Monitor_CurrentUnitInfo*) CORBA_sequence_Monitor_CurrentUnitInfo_allocbuf(1));
}

Monitor_UnitType *CORBA_sequence_Monitor_UnitType_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_UnitType *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_UnitType) * _count;

  if ((_p = (Monitor_UnitType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_UnitState* _Monitor_UnitState__Input (ilu_Call _call, Monitor_UnitState* _ref, ilu_Error *_err)
{
  Monitor_UnitState* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Monitor_UnitState__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_UnitState__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Monitor_UnitState*) ilu_MallocE (sizeof (Monitor_UnitState), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Monitor_UnitState));
    } else {
      _val = (Monitor_UnitState*) _ILU_C_CRCreate (s, sizeof(Monitor_UnitState), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Monitor_UnitState), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->health, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->battery, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Monitor_UnitState__Output (ilu_Call _call, Monitor_UnitState* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Monitor_UnitState__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Monitor_UnitState__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Monitor_UnitState), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortInteger (_call, (_val->health), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortInteger (_call, (_val->battery), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Monitor_UnitState__SizeOf (ilu_Call _call, Monitor_UnitState* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Monitor_UnitState__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Monitor_UnitState__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Monitor_UnitState), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->health, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->battery, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Monitor_UnitState *CORBA_sequence_Monitor_UnitState_allocbuf (CORBA_unsigned_long _count)
{
  Monitor_UnitState *_p;
  CORBA_unsigned_long _size = sizeof(Monitor_UnitState) * _count;

  if ((_p = (Monitor_UnitState *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Monitor_UnitState* Monitor_UnitState__alloc ()
{
  return ((Monitor_UnitState*) CORBA_sequence_Monitor_UnitState_allocbuf(1));
}

void Monitor_PictureFlow_Every (Monitor_PictureFlow *h, void (*f)(CORBA_octet *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_octet), (void *) data);
}

void Monitor_PictureFlow_Append (Monitor_PictureFlow *h, CORBA_octet item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet), err);
}

void Monitor_PictureFlow_Push (Monitor_PictureFlow *h, CORBA_octet item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet));
}

void Monitor_PictureFlow_Pop (Monitor_PictureFlow *h, CORBA_octet *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_octet));
}

CORBA_unsigned_long Monitor_PictureFlow_Length (Monitor_PictureFlow *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_octet * Monitor_PictureFlow_Nth (Monitor_PictureFlow *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Monitor_PictureFlow * Monitor_PictureFlow_Create (CORBA_unsigned_long sz, CORBA_octet *p)
{
  Monitor_PictureFlow *s;
  s = (Monitor_PictureFlow *) ilu_malloc(sizeof(Monitor_PictureFlow));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Monitor_PictureFlow)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_octet *) ilu_malloc(sz * sizeof(CORBA_octet))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_octet));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Monitor_PictureFlow_Init (Monitor_PictureFlow *s, CORBA_unsigned_long sz, CORBA_octet *p)
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
    s->_buffer = (CORBA_octet *) ilu_malloc (sz * sizeof (CORBA_octet));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CORBA_octet)); }}
  else
    s->_buffer = p;
  return;
}

void _Monitor__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Monitor", "2.0beta1", "v2 (2.0beta1)");
  _Ground_Unit__GeneralInitialization();
  _Air_Unit__GeneralInitialization();
  _Console__GeneralInitialization();
  _Unit__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	"IDL:omg.org/CORBA/Object:1.0",
	NULL};
    cl = ilu_DefineObjectType("Monitor.rpc",	/*name*/
	NULL,	/*no brand*/
	"IDL:Monitor/rpc:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	8,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Monitor_rpc__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"sendUnitInfo",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "unitInfo", ilu_FALSE, ilu_In, "IDL:Monitor/CompleteUnitInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"sendTrapPoint",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "tp", ilu_FALSE, ilu_In, "IDL:Console/TrapPoint:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"sendTargetLocation",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "fid", ilu_FALSE, ilu_In, "IDL:Monitor/TargetID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "fp", ilu_FALSE, ilu_In, "IDL:Ground_Unit/Point2D:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "responseTime", ilu_FALSE, ilu_In, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"foundTarget",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "fid", ilu_FALSE, ilu_In, "IDL:Monitor/TargetID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "pi", ilu_FALSE, ilu_In, "IDL:Monitor/PictureInfo:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"confirmAction",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "fid", ilu_FALSE, ilu_In, "IDL:Monitor/TargetID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "responseTime", ilu_FALSE, ilu_In, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 5,
	"backHome",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "uid", ilu_FALSE, ilu_In, "IDL:Unit/UnitID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "bhr", ilu_FALSE, ilu_In, "IDL:Monitor/BackHomeReason:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 6,
	"sendMissionState",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "fid", ilu_FALSE, ilu_In, "IDL:Monitor/TargetID:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "ms", ilu_FALSE, ilu_In, "IDL:Monitor/MissionSituation:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 7,
	"sendPicture",	/*name*/
	8,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	4,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "pictureName", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "pic", ilu_FALSE, ilu_In, "ilut:gDDT46ADZpu8AunPkx2DQ2MCyfH", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "time", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 3, "procedureStartTime", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Monitor_rpc__IoFns.kernelType = ilu_RegisterObjectType("rpc", "Monitor", ILU_NIL, "IDL:Monitor/rpc:1.0",
    _Monitor_rpc__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Monitor_PictureInfo__IoFns.kernelType = type = ilu_RegisterRecordType("PictureInfo", "Monitor", ILU_NIL, "IDL:Monitor/PictureInfo:1.0",
    4,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "picturName", /* field name */
      "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "pic", /* field name */
      "ilut:gDDT46ADZpu8AunPkx2DQ2MCyfH", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "cui", /* field name */
      "IDL:Monitor/CurrentUnitInfo:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "responseTime", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Monitor_PictureFlow__IoFns.kernelType = ilu_RegisterSequenceType("PictureFlow", "Monitor", ILU_NIL, "ilut:gDDT46ADZpu8AunPkx2DQ2MCyfH",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Monitor_MissionSituation__IoFns.kernelType = type = ilu_RegisterEnumerationType("MissionSituation", "Monitor", ILU_NIL, "IDL:Monitor/MissionSituation:1.0",
    4,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "Success", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "StillBurning", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "Locating", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "Processing", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Monitor_BackHomeReason__IoFns.kernelType = type = ilu_RegisterEnumerationType("BackHomeReason", "Monitor", ILU_NIL, "IDL:Monitor/BackHomeReason:1.0",
    4,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "LowBattery", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "EmptyLoad", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "TaskDone", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "TaskStop", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("TargetID", "Monitor", ILU_NIL, "IDL:Monitor/TargetID:1.0",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Monitor_TargetType__IoFns.kernelType = type = ilu_RegisterEnumerationType("TargetType", "Monitor", ILU_NIL, "IDL:Monitor/TargetType:1.0",
    4,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "Fire", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "Person", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "Vehicle", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "Drone", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Monitor_CompleteUnitInfo__IoFns.kernelType = type = ilu_RegisterRecordType("CompleteUnitInfo", "Monitor", ILU_NIL, "IDL:Monitor/CompleteUnitInfo:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "us", /* field name */
      "IDL:Monitor/UnitState:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "cui", /* field name */
      "IDL:Monitor/CurrentUnitInfo:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Monitor_CurrentUnitInfo__IoFns.kernelType = type = ilu_RegisterUnionType("CurrentUnitInfo", "Monitor", ILU_NIL, "IDL:Monitor/CurrentUnitInfo:1.0",
    "IDL:Monitor/UnitType:1.0",	/* UID of discriminant type */
    2,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "groundUnitInfo", /* name of arm */
      "IDL:Ground_Unit/GroundUnitInfo:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "UnitGroundType";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "airUnitInfo", /* name of arm */
      "IDL:Air_Unit/AirUnitInfo:1.0", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "UnitAirType";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Monitor_UnitType__IoFns.kernelType = type = ilu_RegisterEnumerationType("UnitType", "Monitor", ILU_NIL, "IDL:Monitor/UnitType:1.0",
    2,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "UnitGroundType", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "UnitAirType", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Monitor_UnitState__IoFns.kernelType = type = ilu_RegisterRecordType("UnitState", "Monitor", ILU_NIL, "IDL:Monitor/UnitState:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "health", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "battery", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Monitor_rpc__IoFns.properties.object_class = _Monitor_rpc__ILUType;
  _ILU_C_RegisterIoFns (&_Monitor_rpc__IoFns);

  _Monitor_PictureInfo__IoFns.inputFn = (ILU_C_InputFn) _Monitor_PictureInfo__Input;
  _Monitor_PictureInfo__IoFns.outFn = (ILU_C_OutputFn) _Monitor_PictureInfo__Output;
  _Monitor_PictureInfo__IoFns.sizeFn = (ILU_C_SizeFn) _Monitor_PictureInfo__SizeOf;
  _Monitor_PictureInfo__IoFns.freeFn = (ILU_C_FreeFn) Monitor_PictureInfo__Free;
  _ILU_C_RegisterIoFns (&_Monitor_PictureInfo__IoFns);

  _Monitor_PictureFlow__IoFns.inputFn = (ILU_C_InputFn) _Monitor_PictureFlow__Input;
  _Monitor_PictureFlow__IoFns.outFn = (ILU_C_OutputFn) _Monitor_PictureFlow__Output;
  _Monitor_PictureFlow__IoFns.sizeFn = (ILU_C_SizeFn) _Monitor_PictureFlow__SizeOf;
  _Monitor_PictureFlow__IoFns.freeFn = (ILU_C_FreeFn) Monitor_PictureFlow__Free;
  _ILU_C_RegisterIoFns (&_Monitor_PictureFlow__IoFns);

  _ILU_C_RegisterIoFns (&_Monitor_MissionSituation__IoFns);

  _ILU_C_RegisterIoFns (&_Monitor_BackHomeReason__IoFns);

  _Monitor_TargetID__IoFns.inputFn = (ILU_C_InputFn) _ilu_CString__Input;
  _Monitor_TargetID__IoFns.outFn = (ILU_C_OutputFn) _ilu_CString__Output;
  _Monitor_TargetID__IoFns.sizeFn = (ILU_C_SizeFn) _ilu_CString__SizeOf;
  _Monitor_TargetID__IoFns.freeFn = (ILU_C_FreeFn) ilu_CString__Free;
  _ILU_C_RegisterIoFns (&_Monitor_TargetID__IoFns);

  _ILU_C_RegisterIoFns (&_Monitor_TargetType__IoFns);

  _Monitor_CompleteUnitInfo__IoFns.inputFn = (ILU_C_InputFn) _Monitor_CompleteUnitInfo__Input;
  _Monitor_CompleteUnitInfo__IoFns.outFn = (ILU_C_OutputFn) _Monitor_CompleteUnitInfo__Output;
  _Monitor_CompleteUnitInfo__IoFns.sizeFn = (ILU_C_SizeFn) _Monitor_CompleteUnitInfo__SizeOf;
  _Monitor_CompleteUnitInfo__IoFns.freeFn = (ILU_C_FreeFn) Monitor_CompleteUnitInfo__Free;
  _ILU_C_RegisterIoFns (&_Monitor_CompleteUnitInfo__IoFns);

  _Monitor_CurrentUnitInfo__IoFns.inputFn = (ILU_C_InputFn) _Monitor_CurrentUnitInfo__Input;
  _Monitor_CurrentUnitInfo__IoFns.outFn = (ILU_C_OutputFn) _Monitor_CurrentUnitInfo__Output;
  _Monitor_CurrentUnitInfo__IoFns.sizeFn = (ILU_C_SizeFn) _Monitor_CurrentUnitInfo__SizeOf;
  _Monitor_CurrentUnitInfo__IoFns.freeFn = (ILU_C_FreeFn) Monitor_CurrentUnitInfo__Free;
  _ILU_C_RegisterIoFns (&_Monitor_CurrentUnitInfo__IoFns);

  _ILU_C_RegisterIoFns (&_Monitor_UnitType__IoFns);

  _Monitor_UnitState__IoFns.inputFn = (ILU_C_InputFn) _Monitor_UnitState__Input;
  _Monitor_UnitState__IoFns.outFn = (ILU_C_OutputFn) _Monitor_UnitState__Output;
  _Monitor_UnitState__IoFns.sizeFn = (ILU_C_SizeFn) _Monitor_UnitState__SizeOf;
  _Monitor_UnitState__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Monitor_UnitState__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

