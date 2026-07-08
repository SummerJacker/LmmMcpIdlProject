/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:00 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/interfaces/iluhttp.isl" of Mon Jul 21 17:22:19 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "iluhttp.h"

ilu_Class _iluhttp_Resource__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _iluhttp_Resource__IoFns = { ilu_object_tk, "ilu:Ilu_Http_1_1_resource_object", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_Response__IoFns = { ilu_record_tk, "ilut:bxCcnPGE2SMcpOPatpnuKAqpWfV", { sizeof(iluhttp_Response) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_StatusCode__IoFns = { ilu_enumeration_tk, "ilut:gAsSjorCFC6JWuykzai04bbppu1", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_Request__IoFns = { ilu_record_tk, "ilut:cYHQ6LmuntidB9xsQoTCLKXpExq", { sizeof(iluhttp_Request) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_OptionalEntityBody__IoFns = { ilu_optional_tk, "ilut:oSVVdsPSNo1aem2m3M061fLaNat", { sizeof(iluhttp_OptionalEntityBody) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_EntityBody__IoFns = { ilu_sequence_tk, "ilut:f+ul3peSFJiOqkqtnlW+0Lkv5hX", { sizeof(iluhttp_EntityBody) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_HTTPHeaders__IoFns = { ilu_sequence_tk, "ilut:coamLHzQL8Mcq5dGXJO2Wbyg0UP", { sizeof(iluhttp_HTTPHeaders) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_Header__IoFns = { ilu_record_tk, "ilut:p0Aom5PoM+bJsUHm2mIlsLjjBS5", { sizeof(iluhttp_Header) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iluhttp_optional_field_value__IoFns = { ilu_optional_tk, "ilut:bFDfRx6ALdvDMkAbFxdJIUOkQIf", { sizeof(iluhttp_optional_field_value) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class iluhttp_Resource__MakeClass(
  iluhttp_Response* (*iluhttp_Resource_GET__Impl)
     (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_HEAD__Impl)
     (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_POST__Impl)
     (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(2 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _iluhttp_Resource__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iluhttp_Resource_GET__Impl;
  method_block[1] = (_ILU_C_Method) iluhttp_Resource_HEAD__Impl;
  method_block[2] = (_ILU_C_Method) iluhttp_Resource_POST__Impl;
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
iluhttp_Response* iluhttp_Resource_GET (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status)
{
  iluhttp_Response* (*_f)(iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iluhttp_Response* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iluhttp_Response* (*)(iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iluhttp_Resource__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, request, _status));
}

iluhttp_Response* iluhttp_Resource_HEAD (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status)
{
  iluhttp_Response* (*_f)(iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iluhttp_Response* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iluhttp_Response* (*)(iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iluhttp_Resource__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, request, _status));
}

iluhttp_Response* iluhttp_Resource_POST (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status)
{
  iluhttp_Response* (*_f)(iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iluhttp_Response* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iluhttp_Response* (*)(iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iluhttp_Resource__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, request, _status));
}

void iluhttp_Resource__SetUserData (iluhttp_Resource self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *iluhttp_Resource__GetUserData (iluhttp_Resource self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void iluhttp_Resource__Free (iluhttp_Resource* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_Resource */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

iluhttp_Resource *CORBA_sequence_iluhttp_Resource_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_Resource *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_Resource) * _count;

  if ((_p = (iluhttp_Resource *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_Response* _iluhttp_Response__Input (ilu_Call _call, iluhttp_Response* _ref, ilu_Error *_err)
{
  iluhttp_Response* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iluhttp_Response__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Response__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (iluhttp_Response*) ilu_MallocE (sizeof (iluhttp_Response), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(iluhttp_Response));
    } else {
      _val = (iluhttp_Response*) _ILU_C_CRCreate (s, sizeof(iluhttp_Response), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Response), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  {
    ilu_shortcardinal _xxx;
    ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    *&_val->status = (iluhttp_StatusCode) _xxx;
  };
  (void) _iluhttp_HTTPHeaders__Input (_call, &_val->headers,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iluhttp_OptionalEntityBody__Input (_call, &_val->body,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iluhttp_Response__Output (ilu_Call _call, iluhttp_Response* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_iluhttp_Response__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_iluhttp_Response__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Response), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputEnum (_call, (ilu_shortcardinal) (_val->status), (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _iluhttp_HTTPHeaders__Output(_call, (&_val->headers), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _iluhttp_OptionalEntityBody__Output(_call, (_val->body), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _iluhttp_Response__SizeOf (ilu_Call _call, iluhttp_Response* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iluhttp_Response__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Response__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Response), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) _val->status, (ilu_Type)ILU_NIL,  _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _iluhttp_HTTPHeaders__SizeOf (_call, &_val->headers, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _iluhttp_OptionalEntityBody__SizeOf (_call, _val->body, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iluhttp_Response__Free (iluhttp_Response* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_Response */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_iluhttp_Response__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Response__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  iluhttp_HTTPHeaders__Free (&_val->headers);
  iluhttp_OptionalEntityBody__Free (&_val->body);
}

iluhttp_Response *CORBA_sequence_iluhttp_Response_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_Response *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_Response) * _count;

  if ((_p = (iluhttp_Response *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_Response* iluhttp_Response__alloc ()
{
  return ((iluhttp_Response*) CORBA_sequence_iluhttp_Response_allocbuf(1));
}

iluhttp_StatusCode *CORBA_sequence_iluhttp_StatusCode_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_StatusCode *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_StatusCode) * _count;

  if ((_p = (iluhttp_StatusCode *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_Request* _iluhttp_Request__Input (ilu_Call _call, iluhttp_Request* _ref, ilu_Error *_err)
{
  iluhttp_Request* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iluhttp_Request__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Request__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (iluhttp_Request*) ilu_MallocE (sizeof (iluhttp_Request), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(iluhttp_Request));
    } else {
      _val = (iluhttp_Request*) _ILU_C_CRCreate (s, sizeof(iluhttp_Request), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Request), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->URI, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iluhttp_HTTPHeaders__Input (_call, &_val->headers,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iluhttp_OptionalEntityBody__Input (_call, &_val->body,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iluhttp_Request__Output (ilu_Call _call, iluhttp_Request* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_iluhttp_Request__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_iluhttp_Request__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Request), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ilu_CString__Output (_call, (_val->URI), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _iluhttp_HTTPHeaders__Output(_call, (&_val->headers), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _iluhttp_OptionalEntityBody__Output(_call, (_val->body), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _iluhttp_Request__SizeOf (ilu_Call _call, iluhttp_Request* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iluhttp_Request__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Request__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Request), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->URI, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _iluhttp_HTTPHeaders__SizeOf (_call, &_val->headers, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _iluhttp_OptionalEntityBody__SizeOf (_call, _val->body, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iluhttp_Request__Free (iluhttp_Request* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_Request */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_iluhttp_Request__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Request__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  ilu_CString__Free ((ilu_CString *) &_val->URI);
  iluhttp_HTTPHeaders__Free (&_val->headers);
  iluhttp_OptionalEntityBody__Free (&_val->body);
}

iluhttp_Request *CORBA_sequence_iluhttp_Request_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_Request *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_Request) * _count;

  if ((_p = (iluhttp_Request *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_Request* iluhttp_Request__alloc ()
{
  return ((iluhttp_Request*) CORBA_sequence_iluhttp_Request_allocbuf(1));
}

iluhttp_OptionalEntityBody* _iluhttp_OptionalEntityBody__Input (ilu_Call _call, iluhttp_OptionalEntityBody* _ref, ilu_Error *_err)
{
  iluhttp_OptionalEntityBody* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(iluhttp_OptionalEntityBody), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (iluhttp_OptionalEntityBody *) ilu_MallocE (sizeof (iluhttp_OptionalEntityBody), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(iluhttp_OptionalEntityBody));
  };
  if (_present)
    {
    *_val = (iluhttp_EntityBody*) ilu_MallocE (sizeof (iluhttp_EntityBody), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(iluhttp_EntityBody));
      (void) _iluhttp_EntityBody__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  else *_val = ILU_NIL;
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _iluhttp_OptionalEntityBody__Output (ilu_Call _call, iluhttp_OptionalEntityBody _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(iluhttp_OptionalEntityBody), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _iluhttp_EntityBody__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _iluhttp_OptionalEntityBody__SizeOf (ilu_Call _call, iluhttp_OptionalEntityBody _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(iluhttp_OptionalEntityBody), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _iluhttp_EntityBody__SizeOf (_call, &*_val, _err);
  return size;
}

void iluhttp_OptionalEntityBody__Free (iluhttp_OptionalEntityBody* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_OptionalEntityBody */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is iluhttp_EntityBody */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    iluhttp_EntityBody__Free (&**_val);
    ilu_free(*_val);
  }
}

iluhttp_OptionalEntityBody *CORBA_sequence_iluhttp_OptionalEntityBody_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_OptionalEntityBody *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_OptionalEntityBody) * _count;

  if ((_p = (iluhttp_OptionalEntityBody *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_OptionalEntityBody* iluhttp_OptionalEntityBody__alloc ()
{
  return ((iluhttp_OptionalEntityBody*) CORBA_sequence_iluhttp_OptionalEntityBody_allocbuf(1));
}

iluhttp_EntityBody* _iluhttp_EntityBody__Input (ilu_Call _call, iluhttp_EntityBody* _ref, ilu_Error *_err)
{
  iluhttp_EntityBody* _val = _ref;

  ilu_cardinal len=0;
  ilu_cardinal limit = 0;
  ilu_bytes b = ILU_NIL;

  if (_ref == ILU_NIL) {
    _val = (iluhttp_EntityBody *) ilu_MallocE(sizeof(iluhttp_EntityBody), _err);
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

void _iluhttp_EntityBody__Output (ilu_Call _call, iluhttp_EntityBody* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputBytes (_call, _val->_buffer, _val->_length, 0, _err);
 marshalError:
  return;
}

ilu_cardinal _iluhttp_EntityBody__SizeOf (ilu_Call _call, iluhttp_EntityBody* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfBytes (_call, _val->_buffer, _val->_length, 0, _err);
  return size;
}

void iluhttp_EntityBody__Free (iluhttp_EntityBody* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_EntityBody */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_octet)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_octet)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_octet))) */ ) {
    //ilu_DebugPrintf("OK iluhttp_EntityBody__Free (iluhttp_EntityBody* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

iluhttp_EntityBody *CORBA_sequence_iluhttp_EntityBody_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_EntityBody *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_EntityBody) * _count;

  if ((_p = (iluhttp_EntityBody *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_EntityBody* iluhttp_EntityBody__alloc ()
{
  return ((iluhttp_EntityBody*) CORBA_sequence_iluhttp_EntityBody_allocbuf(1));
}

iluhttp_HTTPHeaders* _iluhttp_HTTPHeaders__Input (ilu_Call _call, iluhttp_HTTPHeaders* _ref, ilu_Error *_err)
{
  iluhttp_HTTPHeaders* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  iluhttp_Header _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (iluhttp_HTTPHeaders*) ilu_MallocE(sizeof (iluhttp_HTTPHeaders), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  iluhttp_HTTPHeaders_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(iluhttp_HTTPHeaders), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(iluhttp_Header), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(iluhttp_Header), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _iluhttp_Header__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      iluhttp_HTTPHeaders_Append (_val, &_tmp, _err);
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

void _iluhttp_HTTPHeaders__Output (ilu_Call _call, iluhttp_HTTPHeaders* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(iluhttp_HTTPHeaders), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iluhttp_Header), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(iluhttp_Header), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    iluhttp_Header *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _iluhttp_Header__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _iluhttp_HTTPHeaders__SizeOf (ilu_Call _call, iluhttp_HTTPHeaders* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(iluhttp_HTTPHeaders), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iluhttp_Header), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(iluhttp_HTTPHeader), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    iluhttp_HTTPHeader *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _iluhttp_Header__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iluhttp_HTTPHeaders__Free (iluhttp_HTTPHeaders* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_HTTPHeaders */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(iluhttp_Header)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(iluhttp_Header)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(iluhttp_Header))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          iluhttp_Header__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK iluhttp_HTTPHeaders__Free (iluhttp_HTTPHeaders* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

iluhttp_HTTPHeaders *CORBA_sequence_iluhttp_HTTPHeaders_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_HTTPHeaders *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_HTTPHeaders) * _count;

  if ((_p = (iluhttp_HTTPHeaders *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_HTTPHeaders* iluhttp_HTTPHeaders__alloc ()
{
  return ((iluhttp_HTTPHeaders*) CORBA_sequence_iluhttp_HTTPHeaders_allocbuf(1));
}

iluhttp_Header* _iluhttp_Header__Input (ilu_Call _call, iluhttp_Header* _ref, ilu_Error *_err)
{
  iluhttp_Header* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iluhttp_Header__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Header__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (iluhttp_Header*) ilu_MallocE (sizeof (iluhttp_Header), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(iluhttp_Header));
    } else {
      _val = (iluhttp_Header*) _ILU_C_CRCreate (s, sizeof(iluhttp_Header), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Header), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->name, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iluhttp_optional_field_value__Input (_call, &_val->value,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iluhttp_Header__Output (ilu_Call _call, iluhttp_Header* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_iluhttp_Header__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_iluhttp_Header__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Header), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ilu_CString__Output (_call, (_val->name), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _iluhttp_optional_field_value__Output(_call, (_val->value), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _iluhttp_Header__SizeOf (ilu_Call _call, iluhttp_Header* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iluhttp_Header__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Header__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(iluhttp_Header), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->name, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _iluhttp_optional_field_value__SizeOf (_call, _val->value, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iluhttp_Header__Free (iluhttp_Header* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_Header */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_iluhttp_Header__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iluhttp_Header__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  ilu_CString__Free ((ilu_CString *) &_val->name);
  iluhttp_optional_field_value__Free (&_val->value);
}

iluhttp_Header *CORBA_sequence_iluhttp_Header_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_Header *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_Header) * _count;

  if ((_p = (iluhttp_Header *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_Header* iluhttp_Header__alloc ()
{
  return ((iluhttp_Header*) CORBA_sequence_iluhttp_Header_allocbuf(1));
}

iluhttp_optional_field_value* _iluhttp_optional_field_value__Input (ilu_Call _call, iluhttp_optional_field_value* _ref, ilu_Error *_err)
{
  iluhttp_optional_field_value* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(iluhttp_optional_field_value), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (iluhttp_optional_field_value *) ilu_MallocE (sizeof (iluhttp_optional_field_value), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(iluhttp_optional_field_value));
  };
  if (_present)
    {
      (void) _ilu_CString__Input (_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  else *_val = ILU_NIL;
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _iluhttp_optional_field_value__Output (ilu_Call _call, iluhttp_optional_field_value _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(iluhttp_optional_field_value), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _ilu_CString__Output (_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _iluhttp_optional_field_value__SizeOf (ilu_Call _call, iluhttp_optional_field_value _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(iluhttp_optional_field_value), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _ilu_CString__SizeOf(_call, _val, _err);
  return size;
}

void iluhttp_optional_field_value__Free (iluhttp_optional_field_value* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iluhttp_optional_field_value */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is ilu_CString */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    ilu_CString__Free ((ilu_CString *) &*_val);
  }
}

iluhttp_optional_field_value *CORBA_sequence_iluhttp_optional_field_value_allocbuf (CORBA_unsigned_long _count)
{
  iluhttp_optional_field_value *_p;
  CORBA_unsigned_long _size = sizeof(iluhttp_optional_field_value) * _count;

  if ((_p = (iluhttp_optional_field_value *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iluhttp_optional_field_value* iluhttp_optional_field_value__alloc ()
{
  return ((iluhttp_optional_field_value*) CORBA_sequence_iluhttp_optional_field_value_allocbuf(1));
}

void iluhttp_EntityBody_Every (iluhttp_EntityBody *h, void (*f)(CORBA_octet *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_octet), (void *) data);
}

void iluhttp_EntityBody_Append (iluhttp_EntityBody *h, CORBA_octet item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet), err);
}

void iluhttp_EntityBody_Push (iluhttp_EntityBody *h, CORBA_octet item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet));
}

void iluhttp_EntityBody_Pop (iluhttp_EntityBody *h, CORBA_octet *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_octet));
}

CORBA_unsigned_long iluhttp_EntityBody_Length (iluhttp_EntityBody *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_octet * iluhttp_EntityBody_Nth (iluhttp_EntityBody *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

iluhttp_EntityBody * iluhttp_EntityBody_Create (CORBA_unsigned_long sz, CORBA_octet *p)
{
  iluhttp_EntityBody *s;
  s = (iluhttp_EntityBody *) ilu_malloc(sizeof(iluhttp_EntityBody));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(iluhttp_EntityBody)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_octet *) ilu_malloc(sz * sizeof(CORBA_octet))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_octet));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void iluhttp_EntityBody_Init (iluhttp_EntityBody *s, CORBA_unsigned_long sz, CORBA_octet *p)
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

void iluhttp_HTTPHeaders_Every (iluhttp_HTTPHeaders *h, void (*f)(iluhttp_HTTPHeader*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(iluhttp_HTTPHeader), (void *) data);
}

void iluhttp_HTTPHeaders_Append (iluhttp_HTTPHeaders *h, iluhttp_HTTPHeader* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(iluhttp_HTTPHeader), err);
}

void iluhttp_HTTPHeaders_Push (iluhttp_HTTPHeaders *h, iluhttp_HTTPHeader* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(iluhttp_HTTPHeader));
}

void iluhttp_HTTPHeaders_Pop (iluhttp_HTTPHeaders *h, iluhttp_HTTPHeader* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(iluhttp_HTTPHeader));
}

CORBA_unsigned_long iluhttp_HTTPHeaders_Length (iluhttp_HTTPHeaders *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

iluhttp_HTTPHeader * iluhttp_HTTPHeaders_Nth (iluhttp_HTTPHeaders *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

iluhttp_HTTPHeaders * iluhttp_HTTPHeaders_Create (CORBA_unsigned_long sz, iluhttp_HTTPHeader* p)
{
  iluhttp_HTTPHeaders *s;
  s = (iluhttp_HTTPHeaders *) ilu_malloc(sizeof(iluhttp_HTTPHeaders));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(iluhttp_HTTPHeaders)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((iluhttp_HTTPHeader *) ilu_malloc(sz * sizeof(iluhttp_HTTPHeader))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(iluhttp_HTTPHeader));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void iluhttp_HTTPHeaders_Init (iluhttp_HTTPHeaders *s, CORBA_unsigned_long sz, iluhttp_HTTPHeader* p)
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
    s->_buffer = (iluhttp_HTTPHeader *) ilu_malloc (sz * sizeof (iluhttp_HTTPHeader));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(iluhttp_HTTPHeader)); }}
  else
    s->_buffer = p;
  return;
}

void _iluhttp__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("iluhttp", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("iluhttp.Resource",	/*name*/
	NULL,	/*no brand*/
	"ilu:Ilu_Http_1_1_resource_object",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	3,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _iluhttp_Resource__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"GET",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:bxCcnPGE2SMcpOPatpnuKAqpWfV",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "request", ilu_FALSE, ilu_In, "ilut:cYHQ6LmuntidB9xsQoTCLKXpExq", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"HEAD",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:bxCcnPGE2SMcpOPatpnuKAqpWfV",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "request", ilu_FALSE, ilu_In, "ilut:cYHQ6LmuntidB9xsQoTCLKXpExq", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"POST",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:bxCcnPGE2SMcpOPatpnuKAqpWfV",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "request", ilu_FALSE, ilu_In, "ilut:cYHQ6LmuntidB9xsQoTCLKXpExq", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _iluhttp_Resource__IoFns.kernelType = ilu_RegisterObjectType("Resource", "iluhttp", ILU_NIL, "ilu:Ilu_Http_1_1_resource_object",
    _iluhttp_Resource__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iluhttp_Response__IoFns.kernelType = type = ilu_RegisterRecordType("Response", "iluhttp", ILU_NIL, "ilut:bxCcnPGE2SMcpOPatpnuKAqpWfV",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "status", /* field name */
      "ilut:gAsSjorCFC6JWuykzai04bbppu1", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "headers", /* field name */
      "ilut:coamLHzQL8Mcq5dGXJO2Wbyg0UP", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "body", /* field name */
      "ilut:oSVVdsPSNo1aem2m3M061fLaNat", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iluhttp_StatusCode__IoFns.kernelType = type = ilu_RegisterEnumerationType("StatusCode", "iluhttp", ILU_NIL, "ilut:gAsSjorCFC6JWuykzai04bbppu1",
    45,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "Continue", /* element name */
    100,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "SwitchingProtocols", /* element name */
    101,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "OK", /* element name */
    200,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "Created", /* element name */
    201,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 4, /* which element */
    "Accepted", /* element name */
    202,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 5, /* which element */
    "NonAuthoritativeInformation", /* element name */
    203,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 6, /* which element */
    "NoContent", /* element name */
    204,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 7, /* which element */
    "ResetContent", /* element name */
    205,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 8, /* which element */
    "PartialContent", /* element name */
    206,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 9, /* which element */
    "MultipleChoices", /* element name */
    300,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 10, /* which element */
    "MovedPermanently", /* element name */
    301,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 11, /* which element */
    "Found", /* element name */
    302,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 12, /* which element */
    "SeeOther", /* element name */
    303,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 13, /* which element */
    "NotModified", /* element name */
    304,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 14, /* which element */
    "UseProxy", /* element name */
    305,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 15, /* which element */
    "TemporaryRedirect", /* element name */
    307,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 16, /* which element */
    "PermanentRedirect", /* element name */
    308,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 17, /* which element */
    "BadRequest", /* element name */
    400,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 18, /* which element */
    "Unauthorized", /* element name */
    401,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 19, /* which element */
    "PaymentRequired", /* element name */
    402,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 20, /* which element */
    "Forbidden", /* element name */
    403,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 21, /* which element */
    "NotFound", /* element name */
    404,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 22, /* which element */
    "MethodNotAllowed", /* element name */
    405,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 23, /* which element */
    "NotAcceptable", /* element name */
    406,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 24, /* which element */
    "ProxyAuthenticatoinRequired", /* element name */
    407,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 25, /* which element */
    "RequestTimeout", /* element name */
    408,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 26, /* which element */
    "Conflict", /* element name */
    409,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 27, /* which element */
    "Gone", /* element name */
    410,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 28, /* which element */
    "LengthRequired", /* element name */
    411,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 29, /* which element */
    "PreconditionFailed", /* element name */
    412,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 30, /* which element */
    "ContentTooLarge", /* element name */
    413,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 31, /* which element */
    "URITooLong", /* element name */
    414,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 32, /* which element */
    "UnsupportedMediaType", /* element name */
    415,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 33, /* which element */
    "RangeNotSatisfiable", /* element name */
    416,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 34, /* which element */
    "ExpectationFailed", /* element name */
    417,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 35, /* which element */
    "Unused", /* element name */
    418,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 36, /* which element */
    "MisdiectedRequest", /* element name */
    421,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 37, /* which element */
    "UnprocessableConent", /* element name */
    422,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 38, /* which element */
    "UpgradeReqired", /* element name */
    426,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 39, /* which element */
    "InternalServerError", /* element name */
    500,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 40, /* which element */
    "NotImplemented", /* element name */
    501,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 41, /* which element */
    "BadGateway", /* element name */
    502,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 42, /* which element */
    "ServiceUnavailable", /* element name */
    503,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 43, /* which element */
    "GatewayTimeout", /* element name */
    504,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 44, /* which element */
    "HTTPVersionNotSupported", /* element name */
    505,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iluhttp_Request__IoFns.kernelType = type = ilu_RegisterRecordType("Request", "iluhttp", ILU_NIL, "ilut:cYHQ6LmuntidB9xsQoTCLKXpExq",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "URI", /* field name */
      "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "headers", /* field name */
      "ilut:coamLHzQL8Mcq5dGXJO2Wbyg0UP", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "body", /* field name */
      "ilut:oSVVdsPSNo1aem2m3M061fLaNat", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("RequestURI", "iluhttp", ILU_NIL, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iluhttp_OptionalEntityBody__IoFns.kernelType = ilu_RegisterOptionalType("OptionalEntityBody", "iluhttp", ILU_NIL, "ilut:oSVVdsPSNo1aem2m3M061fLaNat",
    "ilut:f+ul3peSFJiOqkqtnlW+0Lkv5hX", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iluhttp_EntityBody__IoFns.kernelType = ilu_RegisterSequenceType("EntityBody", "iluhttp", ILU_NIL, "ilut:f+ul3peSFJiOqkqtnlW+0Lkv5hX",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iluhttp_HTTPHeaders__IoFns.kernelType = ilu_RegisterSequenceType("HTTPHeaders", "iluhttp", ILU_NIL, "ilut:coamLHzQL8Mcq5dGXJO2Wbyg0UP",
    "ilut:p0Aom5PoM+bJsUHm2mIlsLjjBS5",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("HTTPHeader", "iluhttp", ILU_NIL, "ilut:p0Aom5PoM+bJsUHm2mIlsLjjBS5",
    "ilut:p0Aom5PoM+bJsUHm2mIlsLjjBS5",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iluhttp_Header__IoFns.kernelType = type = ilu_RegisterRecordType("Header", "iluhttp", ILU_NIL, "ilut:p0Aom5PoM+bJsUHm2mIlsLjjBS5",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "name", /* field name */
      "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "value", /* field name */
      "ilut:bFDfRx6ALdvDMkAbFxdJIUOkQIf", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iluhttp_optional_field_value__IoFns.kernelType = ilu_RegisterOptionalType("optional-field-value", "iluhttp", ILU_NIL, "ilut:bFDfRx6ALdvDMkAbFxdJIUOkQIf",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("field-value", "iluhttp", ILU_NIL, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("field-name", "iluhttp", ILU_NIL, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _iluhttp_Resource__IoFns.properties.object_class = _iluhttp_Resource__ILUType;
  _ILU_C_RegisterIoFns (&_iluhttp_Resource__IoFns);

  _iluhttp_Response__IoFns.inputFn = (ILU_C_InputFn) _iluhttp_Response__Input;
  _iluhttp_Response__IoFns.outFn = (ILU_C_OutputFn) _iluhttp_Response__Output;
  _iluhttp_Response__IoFns.sizeFn = (ILU_C_SizeFn) _iluhttp_Response__SizeOf;
  _iluhttp_Response__IoFns.freeFn = (ILU_C_FreeFn) iluhttp_Response__Free;
  _ILU_C_RegisterIoFns (&_iluhttp_Response__IoFns);

  _ILU_C_RegisterIoFns (&_iluhttp_StatusCode__IoFns);

  _iluhttp_Request__IoFns.inputFn = (ILU_C_InputFn) _iluhttp_Request__Input;
  _iluhttp_Request__IoFns.outFn = (ILU_C_OutputFn) _iluhttp_Request__Output;
  _iluhttp_Request__IoFns.sizeFn = (ILU_C_SizeFn) _iluhttp_Request__SizeOf;
  _iluhttp_Request__IoFns.freeFn = (ILU_C_FreeFn) iluhttp_Request__Free;
  _ILU_C_RegisterIoFns (&_iluhttp_Request__IoFns);

  _iluhttp_OptionalEntityBody__IoFns.inputFn = (ILU_C_InputFn) _iluhttp_OptionalEntityBody__Input;
  _iluhttp_OptionalEntityBody__IoFns.outFn = (ILU_C_OutputFn) _iluhttp_OptionalEntityBody__Output;
  _iluhttp_OptionalEntityBody__IoFns.sizeFn = (ILU_C_SizeFn) _iluhttp_OptionalEntityBody__SizeOf;
  _iluhttp_OptionalEntityBody__IoFns.freeFn = (ILU_C_FreeFn) iluhttp_OptionalEntityBody__Free;
  _ILU_C_RegisterIoFns (&_iluhttp_OptionalEntityBody__IoFns);

  _iluhttp_EntityBody__IoFns.inputFn = (ILU_C_InputFn) _iluhttp_EntityBody__Input;
  _iluhttp_EntityBody__IoFns.outFn = (ILU_C_OutputFn) _iluhttp_EntityBody__Output;
  _iluhttp_EntityBody__IoFns.sizeFn = (ILU_C_SizeFn) _iluhttp_EntityBody__SizeOf;
  _iluhttp_EntityBody__IoFns.freeFn = (ILU_C_FreeFn) iluhttp_EntityBody__Free;
  _ILU_C_RegisterIoFns (&_iluhttp_EntityBody__IoFns);

  _iluhttp_HTTPHeaders__IoFns.inputFn = (ILU_C_InputFn) _iluhttp_HTTPHeaders__Input;
  _iluhttp_HTTPHeaders__IoFns.outFn = (ILU_C_OutputFn) _iluhttp_HTTPHeaders__Output;
  _iluhttp_HTTPHeaders__IoFns.sizeFn = (ILU_C_SizeFn) _iluhttp_HTTPHeaders__SizeOf;
  _iluhttp_HTTPHeaders__IoFns.freeFn = (ILU_C_FreeFn) iluhttp_HTTPHeaders__Free;
  _ILU_C_RegisterIoFns (&_iluhttp_HTTPHeaders__IoFns);

  _iluhttp_Header__IoFns.inputFn = (ILU_C_InputFn) _iluhttp_Header__Input;
  _iluhttp_Header__IoFns.outFn = (ILU_C_OutputFn) _iluhttp_Header__Output;
  _iluhttp_Header__IoFns.sizeFn = (ILU_C_SizeFn) _iluhttp_Header__SizeOf;
  _iluhttp_Header__IoFns.freeFn = (ILU_C_FreeFn) iluhttp_Header__Free;
  _ILU_C_RegisterIoFns (&_iluhttp_Header__IoFns);

  _iluhttp_optional_field_value__IoFns.inputFn = (ILU_C_InputFn) _iluhttp_optional_field_value__Input;
  _iluhttp_optional_field_value__IoFns.outFn = (ILU_C_OutputFn) _iluhttp_optional_field_value__Output;
  _iluhttp_optional_field_value__IoFns.sizeFn = (ILU_C_SizeFn) _iluhttp_optional_field_value__SizeOf;
  _iluhttp_optional_field_value__IoFns.freeFn = (ILU_C_FreeFn) iluhttp_optional_field_value__Free;
  _ILU_C_RegisterIoFns (&_iluhttp_optional_field_value__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

