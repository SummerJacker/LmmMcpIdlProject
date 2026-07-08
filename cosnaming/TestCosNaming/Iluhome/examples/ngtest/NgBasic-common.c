/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgBasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "NgBasic.h"

ilu_Class _NgBasic_NgObject__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _NgBasic_NgObjectSequence__IoFns = { ilu_sequence_tk, "ilut:bqWhqXfPmQ0OnFRSDF++uY7KnKx", { sizeof(NgBasic_NgObjectSequence) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_NgObject__IoFns = { ilu_object_tk, "ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_ExceptionInformation__IoFns = { ilu_record_tk, "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn", { sizeof(NgBasic_ExceptionInformation) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalPickle__IoFns = { ilu_optional_tk, "ilut:on5t6u5LDRoo+AtGkW9ncvntNZw", { sizeof(NgBasic_OptionalPickle) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_NameSequence__IoFns = { ilu_sequence_tk, "ilut:jnKRp54g57gOe7fPCulRE7vmvPc", { sizeof(NgBasic_NameSequence) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_NameValuePairSequence__IoFns = { ilu_sequence_tk, "ilut:ovYm9PlmGfhDKZj5JkVFnkAntlC", { sizeof(NgBasic_NameValuePairSequence) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_NameValuePair__IoFns = { ilu_record_tk, "ilut:llyaclLXkJ5rS7qiIv4Fpupayvw", { sizeof(NgBasic_NameValuePair) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalUnsignedInclusiveInterval__IoFns = { ilu_optional_tk, "ilut:mdFsF5jq+msKV1hcVFdaMToJPMs", { sizeof(NgBasic_OptionalUnsignedInclusiveInterval) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_UnsignedInclusiveInterval__IoFns = { ilu_record_tk, "ilut:ijhRh2ztjcTnB71rJMJySaH2QWI", { sizeof(NgBasic_UnsignedInclusiveInterval) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_Version__IoFns = { ilu_record_tk, "ilut:cYNlN9KQa8-1BMJ8V8mxA8lRdGa", { sizeof(NgBasic_Version) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalRelativeTime__IoFns = { ilu_optional_tk, "ilut:hGxicZDmFes+c9kIA8MKlNDnvYv", { sizeof(NgBasic_OptionalRelativeTime) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalAbsoluteTime__IoFns = { ilu_optional_tk, "ilut:oyVqGbZWQ4+HRtnw9jG5E2IR1ZK", { sizeof(NgBasic_OptionalAbsoluteTime) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalCardinal__IoFns = { ilu_optional_tk, "ilut:dZcZXjVtqsFnjSSxNyBk9rN3vxq", { sizeof(NgBasic_OptionalCardinal) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_URISequence__IoFns = { ilu_sequence_tk, "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY", { sizeof(NgBasic_URISequence) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalURI__IoFns = { ilu_optional_tk, "ilut:kwagdxa3MUBXSAWpOS1TUCMm-J+", { sizeof(NgBasic_OptionalURI) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_ByteSequence__IoFns = { ilu_sequence_tk, "ilut:iw+TJyerx6QHNk2sCXPGzL8d90a", { sizeof(NgBasic_ByteSequence) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_StringSequence__IoFns = { ilu_sequence_tk, "ilut:pVA9NPjxKPIk45Pouoxx46IkczI", { sizeof(NgBasic_StringSequence) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalString__IoFns = { ilu_optional_tk, "ilut:krQWr8h8gb6uJ7RmH-7ZLXpF-Oy", { sizeof(NgBasic_OptionalString) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgBasic_String__IoFns = { ilu_sequence_tk, "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", { sizeof(NgBasic_String) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class NgBasic_NgObject__MakeClass(
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgBasic_NgObject _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _NgBasic_NgObject__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgBasic_NgObject_GetInterfaceDefinitionSource__Impl;
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
NgBasic_String NgBasic_NgObject_GetInterfaceDefinitionSource (NgBasic_NgObject _handle, ILU_C_ENVIRONMENT *_status)
{
  NgBasic_String (*_f)(NgBasic_NgObject, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    NgBasic_String _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (NgBasic_String (*)(NgBasic_NgObject, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgBasic_NgObject__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

void NgBasic_NgObject__SetUserData (NgBasic_NgObject self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgBasic_NgObject__GetUserData (NgBasic_NgObject self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _NgBasic__Exception_WouldBlock = ILU_NIL;
ILU_C_ExceptionCode _NgBasic__Exception_Conflict = ILU_NIL;
ILU_C_ExceptionCode _NgBasic__Exception_ObjectNotExist = ILU_NIL;
#include <stdarg.h>

void NgBasic__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_NgBasic_WouldBlock) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else if (stat->returnCode == ex_NgBasic_Conflict) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else if (stat->returnCode == ex_NgBasic_ObjectNotExist) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to NgBasic__BindExceptionValue");
  va_end (ap);
}

NgBasic_NgObjectSequence* _NgBasic_NgObjectSequence__Input (ilu_Call _call, NgBasic_NgObjectSequence* _ref, ilu_Error *_err)
{
  NgBasic_NgObjectSequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  NgBasic_NgObject _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (NgBasic_NgObjectSequence*) ilu_MallocE(sizeof (NgBasic_NgObjectSequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  NgBasic_NgObjectSequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(NgBasic_NgObjectSequence), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(NgBasic_NgObject), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(NgBasic_NgObject), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      *&_tmp = _ILU_C_InputObject (_call, _NgBasic_NgObject__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      NgBasic_NgObjectSequence_Append (_val, _tmp, _err);
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

void _NgBasic_NgObjectSequence__Output (ilu_Call _call, NgBasic_NgObjectSequence* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_NgObjectSequence), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_NgObject), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(NgBasic_NgObject), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    NgBasic_NgObject *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _ILU_C_OutputObject(_call, (NgBasic_NgObject) *p, _NgBasic_NgObject__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_NgObjectSequence__SizeOf (ilu_Call _call, NgBasic_NgObjectSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_NgObjectSequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_NgObject), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(NgBasic_NgObject), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    NgBasic_NgObject *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _ILU_C_SizeOfObject(_call, (NgBasic_NgObject) *p, _NgBasic_NgObject__ILUType, ilu_FALSE, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgBasic_NgObjectSequence__Free (NgBasic_NgObjectSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_NgObjectSequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(NgBasic_NgObject)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(NgBasic_NgObject)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(NgBasic_NgObject))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          NgBasic_NgObject__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK NgBasic_NgObjectSequence__Free (NgBasic_NgObjectSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgBasic_NgObjectSequence *CORBA_sequence_NgBasic_NgObjectSequence_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_NgObjectSequence *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_NgObjectSequence) * _count;

  if ((_p = (NgBasic_NgObjectSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_NgObjectSequence* NgBasic_NgObjectSequence__alloc ()
{
  return ((NgBasic_NgObjectSequence*) CORBA_sequence_NgBasic_NgObjectSequence_allocbuf(1));
}

void NgBasic_NgObject__Free (NgBasic_NgObject* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_NgObject */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgBasic_NgObject *CORBA_sequence_NgBasic_NgObject_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_NgObject *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_NgObject) * _count;

  if ((_p = (NgBasic_NgObject *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_ExceptionInformation* _NgBasic_ExceptionInformation__Input (ilu_Call _call, NgBasic_ExceptionInformation* _ref, ilu_Error *_err)
{
  NgBasic_ExceptionInformation* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_ExceptionInformation__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_ExceptionInformation__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgBasic_ExceptionInformation*) ilu_MallocE (sizeof (NgBasic_ExceptionInformation), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgBasic_ExceptionInformation));
    } else {
      _val = (NgBasic_ExceptionInformation*) _ILU_C_CRCreate (s, sizeof(NgBasic_ExceptionInformation), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_ExceptionInformation), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_String__Input (_call, &_val->reasonPhrase,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalPickle__Input (_call, &_val->specificsData,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_ExceptionInformation__Output (ilu_Call _call, NgBasic_ExceptionInformation* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgBasic_ExceptionInformation__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgBasic_ExceptionInformation__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_ExceptionInformation), _err);
    if (ILU_ERRNOK(*_err)) return;
  _NgBasic_String__Output(_call, (_val->reasonPhrase), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalPickle__Output(_call, (_val->specificsData), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_ExceptionInformation__SizeOf (ilu_Call _call, NgBasic_ExceptionInformation* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_ExceptionInformation__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_ExceptionInformation__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_ExceptionInformation), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_String__SizeOf (_call, _val->reasonPhrase, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalPickle__SizeOf (_call, _val->specificsData, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgBasic_ExceptionInformation__Free (NgBasic_ExceptionInformation* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_ExceptionInformation */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_NgBasic_ExceptionInformation__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_ExceptionInformation__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  NgBasic_String__Free (&_val->reasonPhrase);
  NgBasic_OptionalPickle__Free (&_val->specificsData);
}

NgBasic_ExceptionInformation *CORBA_sequence_NgBasic_ExceptionInformation_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_ExceptionInformation *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_ExceptionInformation) * _count;

  if ((_p = (NgBasic_ExceptionInformation *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_ExceptionInformation* NgBasic_ExceptionInformation__alloc ()
{
  return ((NgBasic_ExceptionInformation*) CORBA_sequence_NgBasic_ExceptionInformation_allocbuf(1));
}

NgBasic_OptionalPickle* _NgBasic_OptionalPickle__Input (ilu_Call _call, NgBasic_OptionalPickle* _ref, ilu_Error *_err)
{
  NgBasic_OptionalPickle* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgBasic_OptionalPickle), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgBasic_OptionalPickle *) ilu_MallocE (sizeof (NgBasic_OptionalPickle), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgBasic_OptionalPickle));
  };
  if (_present)
    {
    *_val = (CORBA_any*) ilu_MallocE (sizeof (CORBA_any), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(CORBA_any));
      (void) _CORBA_any__Input (_call, (CORBA_any *) *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_OptionalPickle__Output (ilu_Call _call, NgBasic_OptionalPickle _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalPickle), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _CORBA_any__Output (_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgBasic_OptionalPickle__SizeOf (ilu_Call _call, NgBasic_OptionalPickle _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalPickle), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _CORBA_any__SizeOf(_call, &*_val, _err);
  return size;
}

void NgBasic_OptionalPickle__Free (NgBasic_OptionalPickle* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_OptionalPickle */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is CORBA_any */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    CORBA_any__Free ((CORBA_any *) &**_val);
    ilu_free(*_val);
  }
}

NgBasic_OptionalPickle *CORBA_sequence_NgBasic_OptionalPickle_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_OptionalPickle *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_OptionalPickle) * _count;

  if ((_p = (NgBasic_OptionalPickle *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_OptionalPickle* NgBasic_OptionalPickle__alloc ()
{
  return ((NgBasic_OptionalPickle*) CORBA_sequence_NgBasic_OptionalPickle_allocbuf(1));
}

NgBasic_NameSequence* _NgBasic_NameSequence__Input (ilu_Call _call, NgBasic_NameSequence* _ref, ilu_Error *_err)
{
  NgBasic_NameSequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  NgBasic_String _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (NgBasic_NameSequence*) ilu_MallocE(sizeof (NgBasic_NameSequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  NgBasic_NameSequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(NgBasic_NameSequence), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(NgBasic_String), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(NgBasic_String), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _NgBasic_String__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      NgBasic_NameSequence_Append (_val, _tmp, _err);
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

void _NgBasic_NameSequence__Output (ilu_Call _call, NgBasic_NameSequence* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_NameSequence), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_String), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(NgBasic_String), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    NgBasic_String *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _NgBasic_String__Output(_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_NameSequence__SizeOf (ilu_Call _call, NgBasic_NameSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_NameSequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_String), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(NgBasic_String), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    NgBasic_String *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _NgBasic_String__SizeOf (_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgBasic_NameSequence__Free (NgBasic_NameSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_NameSequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(NgBasic_String)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(NgBasic_String)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(NgBasic_String))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          NgBasic_String__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK NgBasic_NameSequence__Free (NgBasic_NameSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgBasic_NameSequence *CORBA_sequence_NgBasic_NameSequence_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_NameSequence *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_NameSequence) * _count;

  if ((_p = (NgBasic_NameSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_NameSequence* NgBasic_NameSequence__alloc ()
{
  return ((NgBasic_NameSequence*) CORBA_sequence_NgBasic_NameSequence_allocbuf(1));
}

NgBasic_NameValuePairSequence* _NgBasic_NameValuePairSequence__Input (ilu_Call _call, NgBasic_NameValuePairSequence* _ref, ilu_Error *_err)
{
  NgBasic_NameValuePairSequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  NgBasic_NameValuePair _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (NgBasic_NameValuePairSequence*) ilu_MallocE(sizeof (NgBasic_NameValuePairSequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  NgBasic_NameValuePairSequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(NgBasic_NameValuePairSequence), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(NgBasic_NameValuePair), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _NgBasic_NameValuePair__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      NgBasic_NameValuePairSequence_Append (_val, &_tmp, _err);
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

void _NgBasic_NameValuePairSequence__Output (ilu_Call _call, NgBasic_NameValuePairSequence* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_NameValuePairSequence), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(NgBasic_NameValuePair), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    NgBasic_NameValuePair *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _NgBasic_NameValuePair__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_NameValuePairSequence__SizeOf (ilu_Call _call, NgBasic_NameValuePairSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_NameValuePairSequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(NgBasic_NameValuePair), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    NgBasic_NameValuePair *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _NgBasic_NameValuePair__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgBasic_NameValuePairSequence__Free (NgBasic_NameValuePairSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_NameValuePairSequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(NgBasic_NameValuePair)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(NgBasic_NameValuePair)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(NgBasic_NameValuePair))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          NgBasic_NameValuePair__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK NgBasic_NameValuePairSequence__Free (NgBasic_NameValuePairSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgBasic_NameValuePairSequence *CORBA_sequence_NgBasic_NameValuePairSequence_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_NameValuePairSequence *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_NameValuePairSequence) * _count;

  if ((_p = (NgBasic_NameValuePairSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_NameValuePairSequence* NgBasic_NameValuePairSequence__alloc ()
{
  return ((NgBasic_NameValuePairSequence*) CORBA_sequence_NgBasic_NameValuePairSequence_allocbuf(1));
}

NgBasic_NameValuePair* _NgBasic_NameValuePair__Input (ilu_Call _call, NgBasic_NameValuePair* _ref, ilu_Error *_err)
{
  NgBasic_NameValuePair* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_NameValuePair__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_NameValuePair__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgBasic_NameValuePair*) ilu_MallocE (sizeof (NgBasic_NameValuePair), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgBasic_NameValuePair));
    } else {
      _val = (NgBasic_NameValuePair*) _ILU_C_CRCreate (s, sizeof(NgBasic_NameValuePair), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_String__Input (_call, &_val->name,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _CORBA_any__Input (_call, (CORBA_any *) &_val->value, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_NameValuePair__Output (ilu_Call _call, NgBasic_NameValuePair* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgBasic_NameValuePair__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgBasic_NameValuePair__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _err);
    if (ILU_ERRNOK(*_err)) return;
  _NgBasic_String__Output(_call, (_val->name), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _CORBA_any__Output (_call, (&_val->value), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_NameValuePair__SizeOf (ilu_Call _call, NgBasic_NameValuePair* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_NameValuePair__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_NameValuePair__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_String__SizeOf (_call, _val->name, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _CORBA_any__SizeOf(_call, &_val->value, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgBasic_NameValuePair__Free (NgBasic_NameValuePair* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_NameValuePair */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_NgBasic_NameValuePair__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_NameValuePair__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  NgBasic_String__Free (&_val->name);
  CORBA_any__Free ((CORBA_any *) &_val->value);
}

NgBasic_NameValuePair *CORBA_sequence_NgBasic_NameValuePair_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_NameValuePair *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_NameValuePair) * _count;

  if ((_p = (NgBasic_NameValuePair *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_NameValuePair* NgBasic_NameValuePair__alloc ()
{
  return ((NgBasic_NameValuePair*) CORBA_sequence_NgBasic_NameValuePair_allocbuf(1));
}

NgBasic_OptionalUnsignedInclusiveInterval* _NgBasic_OptionalUnsignedInclusiveInterval__Input (ilu_Call _call, NgBasic_OptionalUnsignedInclusiveInterval* _ref, ilu_Error *_err)
{
  NgBasic_OptionalUnsignedInclusiveInterval* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgBasic_OptionalUnsignedInclusiveInterval), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgBasic_OptionalUnsignedInclusiveInterval *) ilu_MallocE (sizeof (NgBasic_OptionalUnsignedInclusiveInterval), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgBasic_OptionalUnsignedInclusiveInterval));
  };
  if (_present)
    {
    *_val = (NgBasic_UnsignedInclusiveInterval*) ilu_MallocE (sizeof (NgBasic_UnsignedInclusiveInterval), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(NgBasic_UnsignedInclusiveInterval));
      (void) _NgBasic_UnsignedInclusiveInterval__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_OptionalUnsignedInclusiveInterval__Output (ilu_Call _call, NgBasic_OptionalUnsignedInclusiveInterval _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalUnsignedInclusiveInterval), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgBasic_UnsignedInclusiveInterval__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgBasic_OptionalUnsignedInclusiveInterval__SizeOf (ilu_Call _call, NgBasic_OptionalUnsignedInclusiveInterval _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalUnsignedInclusiveInterval), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgBasic_UnsignedInclusiveInterval__SizeOf (_call, &*_val, _err);
  return size;
}

void NgBasic_OptionalUnsignedInclusiveInterval__Free (NgBasic_OptionalUnsignedInclusiveInterval* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_OptionalUnsignedInclusiveInterval */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgBasic_UnsignedInclusiveInterval */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    ilu_free(*_val);
  }
}

NgBasic_OptionalUnsignedInclusiveInterval *CORBA_sequence_NgBasic_OptionalUnsignedInclusiveInterval_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_OptionalUnsignedInclusiveInterval *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_OptionalUnsignedInclusiveInterval) * _count;

  if ((_p = (NgBasic_OptionalUnsignedInclusiveInterval *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_OptionalUnsignedInclusiveInterval* NgBasic_OptionalUnsignedInclusiveInterval__alloc ()
{
  return ((NgBasic_OptionalUnsignedInclusiveInterval*) CORBA_sequence_NgBasic_OptionalUnsignedInclusiveInterval_allocbuf(1));
}

NgBasic_UnsignedInclusiveInterval* _NgBasic_UnsignedInclusiveInterval__Input (ilu_Call _call, NgBasic_UnsignedInclusiveInterval* _ref, ilu_Error *_err)
{
  NgBasic_UnsignedInclusiveInterval* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_UnsignedInclusiveInterval__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_UnsignedInclusiveInterval__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgBasic_UnsignedInclusiveInterval*) ilu_MallocE (sizeof (NgBasic_UnsignedInclusiveInterval), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgBasic_UnsignedInclusiveInterval));
    } else {
      _val = (NgBasic_UnsignedInclusiveInterval*) _ILU_C_CRCreate (s, sizeof(NgBasic_UnsignedInclusiveInterval), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_UnsignedInclusiveInterval), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &_val->startValue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &_val->endValue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_UnsignedInclusiveInterval__Output (ilu_Call _call, NgBasic_UnsignedInclusiveInterval* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgBasic_UnsignedInclusiveInterval__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgBasic_UnsignedInclusiveInterval__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_UnsignedInclusiveInterval), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputCardinal (_call, (_val->startValue), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputCardinal (_call, (_val->endValue), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_UnsignedInclusiveInterval__SizeOf (ilu_Call _call, NgBasic_UnsignedInclusiveInterval* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_UnsignedInclusiveInterval__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_UnsignedInclusiveInterval__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_UnsignedInclusiveInterval), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfCardinal(_call, _val->startValue, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfCardinal(_call, _val->endValue, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

NgBasic_UnsignedInclusiveInterval *CORBA_sequence_NgBasic_UnsignedInclusiveInterval_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_UnsignedInclusiveInterval *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_UnsignedInclusiveInterval) * _count;

  if ((_p = (NgBasic_UnsignedInclusiveInterval *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_UnsignedInclusiveInterval* NgBasic_UnsignedInclusiveInterval__alloc ()
{
  return ((NgBasic_UnsignedInclusiveInterval*) CORBA_sequence_NgBasic_UnsignedInclusiveInterval_allocbuf(1));
}

NgBasic_Version* _NgBasic_Version__Input (ilu_Call _call, NgBasic_Version* _ref, ilu_Error *_err)
{
  NgBasic_Version* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_Version__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_Version__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgBasic_Version*) ilu_MallocE (sizeof (NgBasic_Version), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgBasic_Version));
    } else {
      _val = (NgBasic_Version*) _ILU_C_CRCreate (s, sizeof(NgBasic_Version), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_Version), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortCardinal (_call, &_val->major, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortCardinal (_call, &_val->minor, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_Version__Output (ilu_Call _call, NgBasic_Version* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgBasic_Version__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgBasic_Version__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_Version), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortCardinal (_call, (_val->major), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortCardinal (_call, (_val->minor), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_Version__SizeOf (ilu_Call _call, NgBasic_Version* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgBasic_Version__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgBasic_Version__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgBasic_Version), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortCardinal(_call, _val->major, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortCardinal(_call, _val->minor, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

NgBasic_Version *CORBA_sequence_NgBasic_Version_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_Version *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_Version) * _count;

  if ((_p = (NgBasic_Version *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_Version* NgBasic_Version__alloc ()
{
  return ((NgBasic_Version*) CORBA_sequence_NgBasic_Version_allocbuf(1));
}

NgBasic_OptionalRelativeTime* _NgBasic_OptionalRelativeTime__Input (ilu_Call _call, NgBasic_OptionalRelativeTime* _ref, ilu_Error *_err)
{
  NgBasic_OptionalRelativeTime* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgBasic_OptionalRelativeTime), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgBasic_OptionalRelativeTime *) ilu_MallocE (sizeof (NgBasic_OptionalRelativeTime), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgBasic_OptionalRelativeTime));
  };
  if (_present)
    {
    *_val = (CORBA_long_long*) ilu_MallocE (sizeof (CORBA_long_long), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(CORBA_long_long));
      ilu_InputLongInteger (_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_OptionalRelativeTime__Output (ilu_Call _call, NgBasic_OptionalRelativeTime _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalRelativeTime), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  ilu_OutputLongInteger(_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgBasic_OptionalRelativeTime__SizeOf (ilu_Call _call, NgBasic_OptionalRelativeTime _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalRelativeTime), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += ilu_SizeOfLongInteger(_call, *_val, _err);
  return size;
}

void NgBasic_OptionalRelativeTime__Free (NgBasic_OptionalRelativeTime* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_OptionalRelativeTime */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is CORBA_long_long */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    ilu_free(*_val);
  }
}

NgBasic_OptionalRelativeTime *CORBA_sequence_NgBasic_OptionalRelativeTime_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_OptionalRelativeTime *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_OptionalRelativeTime) * _count;

  if ((_p = (NgBasic_OptionalRelativeTime *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_OptionalRelativeTime* NgBasic_OptionalRelativeTime__alloc ()
{
  return ((NgBasic_OptionalRelativeTime*) CORBA_sequence_NgBasic_OptionalRelativeTime_allocbuf(1));
}

NgBasic_OptionalAbsoluteTime* _NgBasic_OptionalAbsoluteTime__Input (ilu_Call _call, NgBasic_OptionalAbsoluteTime* _ref, ilu_Error *_err)
{
  NgBasic_OptionalAbsoluteTime* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgBasic_OptionalAbsoluteTime), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgBasic_OptionalAbsoluteTime *) ilu_MallocE (sizeof (NgBasic_OptionalAbsoluteTime), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgBasic_OptionalAbsoluteTime));
  };
  if (_present)
    {
    *_val = (CORBA_long_long*) ilu_MallocE (sizeof (CORBA_long_long), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(CORBA_long_long));
      ilu_InputLongInteger (_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_OptionalAbsoluteTime__Output (ilu_Call _call, NgBasic_OptionalAbsoluteTime _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalAbsoluteTime), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  ilu_OutputLongInteger(_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgBasic_OptionalAbsoluteTime__SizeOf (ilu_Call _call, NgBasic_OptionalAbsoluteTime _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalAbsoluteTime), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += ilu_SizeOfLongInteger(_call, *_val, _err);
  return size;
}

void NgBasic_OptionalAbsoluteTime__Free (NgBasic_OptionalAbsoluteTime* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_OptionalAbsoluteTime */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is CORBA_long_long */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    ilu_free(*_val);
  }
}

NgBasic_OptionalAbsoluteTime *CORBA_sequence_NgBasic_OptionalAbsoluteTime_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_OptionalAbsoluteTime *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_OptionalAbsoluteTime) * _count;

  if ((_p = (NgBasic_OptionalAbsoluteTime *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_OptionalAbsoluteTime* NgBasic_OptionalAbsoluteTime__alloc ()
{
  return ((NgBasic_OptionalAbsoluteTime*) CORBA_sequence_NgBasic_OptionalAbsoluteTime_allocbuf(1));
}

NgBasic_OptionalCardinal* _NgBasic_OptionalCardinal__Input (ilu_Call _call, NgBasic_OptionalCardinal* _ref, ilu_Error *_err)
{
  NgBasic_OptionalCardinal* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgBasic_OptionalCardinal), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgBasic_OptionalCardinal *) ilu_MallocE (sizeof (NgBasic_OptionalCardinal), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgBasic_OptionalCardinal));
  };
  if (_present)
    {
    *_val = (CORBA_unsigned_long*) ilu_MallocE (sizeof (CORBA_unsigned_long), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(CORBA_unsigned_long));
      ilu_InputCardinal (_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_OptionalCardinal__Output (ilu_Call _call, NgBasic_OptionalCardinal _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalCardinal), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  ilu_OutputCardinal (_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgBasic_OptionalCardinal__SizeOf (ilu_Call _call, NgBasic_OptionalCardinal _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalCardinal), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += ilu_SizeOfCardinal(_call, *_val, _err);
  return size;
}

void NgBasic_OptionalCardinal__Free (NgBasic_OptionalCardinal* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_OptionalCardinal */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is CORBA_unsigned_long */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    ilu_free(*_val);
  }
}

NgBasic_OptionalCardinal *CORBA_sequence_NgBasic_OptionalCardinal_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_OptionalCardinal *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_OptionalCardinal) * _count;

  if ((_p = (NgBasic_OptionalCardinal *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_OptionalCardinal* NgBasic_OptionalCardinal__alloc ()
{
  return ((NgBasic_OptionalCardinal*) CORBA_sequence_NgBasic_OptionalCardinal_allocbuf(1));
}

NgBasic_URISequence* _NgBasic_URISequence__Input (ilu_Call _call, NgBasic_URISequence* _ref, ilu_Error *_err)
{
  NgBasic_URISequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  NgBasic_String _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (NgBasic_URISequence*) ilu_MallocE(sizeof (NgBasic_URISequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  NgBasic_URISequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(NgBasic_URISequence), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(NgBasic_String), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(NgBasic_String), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _NgBasic_String__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      NgBasic_URISequence_Append (_val, _tmp, _err);
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

void _NgBasic_URISequence__Output (ilu_Call _call, NgBasic_URISequence* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_URISequence), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_String), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(NgBasic_String), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    NgBasic_String *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _NgBasic_String__Output(_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_URISequence__SizeOf (ilu_Call _call, NgBasic_URISequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_URISequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_String), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(NgBasic_URI), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    NgBasic_URI *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _NgBasic_String__SizeOf (_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgBasic_URISequence__Free (NgBasic_URISequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_URISequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(NgBasic_String)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(NgBasic_String)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(NgBasic_String))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          NgBasic_String__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK NgBasic_URISequence__Free (NgBasic_URISequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgBasic_URISequence *CORBA_sequence_NgBasic_URISequence_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_URISequence *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_URISequence) * _count;

  if ((_p = (NgBasic_URISequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_URISequence* NgBasic_URISequence__alloc ()
{
  return ((NgBasic_URISequence*) CORBA_sequence_NgBasic_URISequence_allocbuf(1));
}

NgBasic_OptionalURI* _NgBasic_OptionalURI__Input (ilu_Call _call, NgBasic_OptionalURI* _ref, ilu_Error *_err)
{
  NgBasic_OptionalURI* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgBasic_OptionalURI), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgBasic_OptionalURI *) ilu_MallocE (sizeof (NgBasic_OptionalURI), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgBasic_OptionalURI));
  };
  if (_present)
    {
      (void) _NgBasic_String__Input (_call, _val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_OptionalURI__Output (ilu_Call _call, NgBasic_OptionalURI _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalURI), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgBasic_String__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgBasic_OptionalURI__SizeOf (ilu_Call _call, NgBasic_OptionalURI _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalURI), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgBasic_String__SizeOf (_call, _val, _err);
  return size;
}

void NgBasic_OptionalURI__Free (NgBasic_OptionalURI* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_OptionalURI */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgBasic_String */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgBasic_String__Free (&*_val);
  }
}

NgBasic_OptionalURI *CORBA_sequence_NgBasic_OptionalURI_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_OptionalURI *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_OptionalURI) * _count;

  if ((_p = (NgBasic_OptionalURI *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_OptionalURI* NgBasic_OptionalURI__alloc ()
{
  return ((NgBasic_OptionalURI*) CORBA_sequence_NgBasic_OptionalURI_allocbuf(1));
}

NgBasic_ByteSequence* _NgBasic_ByteSequence__Input (ilu_Call _call, NgBasic_ByteSequence* _ref, ilu_Error *_err)
{
  NgBasic_ByteSequence* _val = _ref;

  ilu_cardinal len=0;
  ilu_cardinal limit = 0;
  ilu_bytes b = ILU_NIL;

  if (_ref == ILU_NIL) {
    _val = (NgBasic_ByteSequence *) ilu_MallocE(sizeof(NgBasic_ByteSequence), _err);
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

void _NgBasic_ByteSequence__Output (ilu_Call _call, NgBasic_ByteSequence* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputBytes (_call, _val->_buffer, _val->_length, 0, _err);
 marshalError:
  return;
}

ilu_cardinal _NgBasic_ByteSequence__SizeOf (ilu_Call _call, NgBasic_ByteSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfBytes (_call, _val->_buffer, _val->_length, 0, _err);
  return size;
}

void NgBasic_ByteSequence__Free (NgBasic_ByteSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_ByteSequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_octet)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_octet)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_octet))) */ ) {
    //ilu_DebugPrintf("OK NgBasic_ByteSequence__Free (NgBasic_ByteSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgBasic_ByteSequence *CORBA_sequence_NgBasic_ByteSequence_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_ByteSequence *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_ByteSequence) * _count;

  if ((_p = (NgBasic_ByteSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_ByteSequence* NgBasic_ByteSequence__alloc ()
{
  return ((NgBasic_ByteSequence*) CORBA_sequence_NgBasic_ByteSequence_allocbuf(1));
}

NgBasic_StringSequence* _NgBasic_StringSequence__Input (ilu_Call _call, NgBasic_StringSequence* _ref, ilu_Error *_err)
{
  NgBasic_StringSequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  NgBasic_String _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (NgBasic_StringSequence*) ilu_MallocE(sizeof (NgBasic_StringSequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  NgBasic_StringSequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(NgBasic_StringSequence), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(NgBasic_String), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(NgBasic_String), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _NgBasic_String__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      NgBasic_StringSequence_Append (_val, _tmp, _err);
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

void _NgBasic_StringSequence__Output (ilu_Call _call, NgBasic_StringSequence* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_StringSequence), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_String), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(NgBasic_String), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    NgBasic_String *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _NgBasic_String__Output(_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _NgBasic_StringSequence__SizeOf (ilu_Call _call, NgBasic_StringSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgBasic_StringSequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_String), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(NgBasic_String), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    NgBasic_String *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _NgBasic_String__SizeOf (_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgBasic_StringSequence__Free (NgBasic_StringSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_StringSequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(NgBasic_String)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(NgBasic_String)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(NgBasic_String))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          NgBasic_String__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK NgBasic_StringSequence__Free (NgBasic_StringSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgBasic_StringSequence *CORBA_sequence_NgBasic_StringSequence_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_StringSequence *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_StringSequence) * _count;

  if ((_p = (NgBasic_StringSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_StringSequence* NgBasic_StringSequence__alloc ()
{
  return ((NgBasic_StringSequence*) CORBA_sequence_NgBasic_StringSequence_allocbuf(1));
}

NgBasic_OptionalString* _NgBasic_OptionalString__Input (ilu_Call _call, NgBasic_OptionalString* _ref, ilu_Error *_err)
{
  NgBasic_OptionalString* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgBasic_OptionalString), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgBasic_OptionalString *) ilu_MallocE (sizeof (NgBasic_OptionalString), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgBasic_OptionalString));
  };
  if (_present)
    {
      (void) _NgBasic_String__Input (_call, _val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgBasic_OptionalString__Output (ilu_Call _call, NgBasic_OptionalString _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalString), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgBasic_String__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgBasic_OptionalString__SizeOf (ilu_Call _call, NgBasic_OptionalString _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgBasic_OptionalString), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgBasic_String__SizeOf (_call, _val, _err);
  return size;
}

void NgBasic_OptionalString__Free (NgBasic_OptionalString* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_OptionalString */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgBasic_String */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgBasic_String__Free (&*_val);
  }
}

NgBasic_OptionalString *CORBA_sequence_NgBasic_OptionalString_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_OptionalString *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_OptionalString) * _count;

  if ((_p = (NgBasic_OptionalString *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_OptionalString* NgBasic_OptionalString__alloc ()
{
  return ((NgBasic_OptionalString*) CORBA_sequence_NgBasic_OptionalString_allocbuf(1));
}

NgBasic_String* _NgBasic_String__Input (ilu_Call _call, NgBasic_String* _ref, ilu_Error *_err)
{
  NgBasic_String* _val = _ref;

  ilu_cardinal len = 0;
  ilu_cardinal actual_encoding;
  if (_ref == ILU_NIL) {
      _val = ilu_MallocE(sizeof(*_val), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      *_val = ILU_NIL;}
  ilu_InputEString (_call, (ilu_byte **) _val, &len, 0, ILU_StringEncoding_latin1, &actual_encoding, _err);
  if (ILU_ERROK(*_err) && (actual_encoding != ILU_StringEncoding_latin1))
  	  ILU_ERR_CONS1(imp_limit, _err, minor, ilu_ilm_unsupported_charset_encoding, 0);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgBasic_String__Output (ilu_Call _call, NgBasic_String _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
 marshalError:
  return;
}

ilu_cardinal _NgBasic_String__SizeOf (ilu_Call _call, NgBasic_String _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
  return size;
}

void NgBasic_String__Free (NgBasic_String* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgBasic_String */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  if (*_val != ILU_NIL)
    ilu_free(*_val);
}

NgBasic_String *CORBA_sequence_NgBasic_String_allocbuf (CORBA_unsigned_long _count)
{
  NgBasic_String *_p;
  CORBA_unsigned_long _size = sizeof(NgBasic_String) * _count;

  if ((_p = (NgBasic_String *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgBasic_String* NgBasic_String__alloc ()
{
  return ((NgBasic_String*) CORBA_sequence_NgBasic_String_allocbuf(1));
}

void NgBasic_NgObjectSequence_Every (NgBasic_NgObjectSequence *h, void (*f)(NgBasic_NgObject *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(NgBasic_NgObject), (void *) data);
}

void NgBasic_NgObjectSequence_Append (NgBasic_NgObjectSequence *h, NgBasic_NgObject item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_NgObject), err);
}

void NgBasic_NgObjectSequence_Push (NgBasic_NgObjectSequence *h, NgBasic_NgObject item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_NgObject));
}

void NgBasic_NgObjectSequence_Pop (NgBasic_NgObjectSequence *h, NgBasic_NgObject *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgBasic_NgObject));
}

CORBA_unsigned_long NgBasic_NgObjectSequence_Length (NgBasic_NgObjectSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

NgBasic_NgObject * NgBasic_NgObjectSequence_Nth (NgBasic_NgObjectSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgBasic_NgObjectSequence * NgBasic_NgObjectSequence_Create (CORBA_unsigned_long sz, NgBasic_NgObject *p)
{
  NgBasic_NgObjectSequence *s;
  s = (NgBasic_NgObjectSequence *) ilu_malloc(sizeof(NgBasic_NgObjectSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgBasic_NgObjectSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((NgBasic_NgObject *) ilu_malloc(sz * sizeof(NgBasic_NgObject))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(NgBasic_NgObject));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgBasic_NgObjectSequence_Init (NgBasic_NgObjectSequence *s, CORBA_unsigned_long sz, NgBasic_NgObject *p)
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
    s->_buffer = (NgBasic_NgObject *) ilu_malloc (sz * sizeof (NgBasic_NgObject));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(NgBasic_NgObject)); }}
  else
    s->_buffer = p;
  return;
}

void NgBasic_NameSequence_Every (NgBasic_NameSequence *h, void (*f)(NgBasic_String *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(NgBasic_String), (void *) data);
}

void NgBasic_NameSequence_Append (NgBasic_NameSequence *h, NgBasic_String item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_String), err);
}

void NgBasic_NameSequence_Push (NgBasic_NameSequence *h, NgBasic_String item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_String));
}

void NgBasic_NameSequence_Pop (NgBasic_NameSequence *h, NgBasic_String *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgBasic_String));
}

CORBA_unsigned_long NgBasic_NameSequence_Length (NgBasic_NameSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

NgBasic_String * NgBasic_NameSequence_Nth (NgBasic_NameSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgBasic_NameSequence * NgBasic_NameSequence_Create (CORBA_unsigned_long sz, NgBasic_String *p)
{
  NgBasic_NameSequence *s;
  s = (NgBasic_NameSequence *) ilu_malloc(sizeof(NgBasic_NameSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgBasic_NameSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((NgBasic_String *) ilu_malloc(sz * sizeof(NgBasic_String))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(NgBasic_String));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgBasic_NameSequence_Init (NgBasic_NameSequence *s, CORBA_unsigned_long sz, NgBasic_String *p)
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
    s->_buffer = (NgBasic_String *) ilu_malloc (sz * sizeof (NgBasic_String));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(NgBasic_String)); }}
  else
    s->_buffer = p;
  return;
}

void NgBasic_NameValuePairSequence_Every (NgBasic_NameValuePairSequence *h, void (*f)(NgBasic_NameValuePair*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(NgBasic_NameValuePair), (void *) data);
}

void NgBasic_NameValuePairSequence_Append (NgBasic_NameValuePairSequence *h, NgBasic_NameValuePair* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgBasic_NameValuePair), err);
}

void NgBasic_NameValuePairSequence_Push (NgBasic_NameValuePairSequence *h, NgBasic_NameValuePair* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgBasic_NameValuePair));
}

void NgBasic_NameValuePairSequence_Pop (NgBasic_NameValuePairSequence *h, NgBasic_NameValuePair* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgBasic_NameValuePair));
}

CORBA_unsigned_long NgBasic_NameValuePairSequence_Length (NgBasic_NameValuePairSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

NgBasic_NameValuePair * NgBasic_NameValuePairSequence_Nth (NgBasic_NameValuePairSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgBasic_NameValuePairSequence * NgBasic_NameValuePairSequence_Create (CORBA_unsigned_long sz, NgBasic_NameValuePair* p)
{
  NgBasic_NameValuePairSequence *s;
  s = (NgBasic_NameValuePairSequence *) ilu_malloc(sizeof(NgBasic_NameValuePairSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgBasic_NameValuePairSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((NgBasic_NameValuePair *) ilu_malloc(sz * sizeof(NgBasic_NameValuePair))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(NgBasic_NameValuePair));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgBasic_NameValuePairSequence_Init (NgBasic_NameValuePairSequence *s, CORBA_unsigned_long sz, NgBasic_NameValuePair* p)
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
    s->_buffer = (NgBasic_NameValuePair *) ilu_malloc (sz * sizeof (NgBasic_NameValuePair));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(NgBasic_NameValuePair)); }}
  else
    s->_buffer = p;
  return;
}

void NgBasic_URISequence_Every (NgBasic_URISequence *h, void (*f)(NgBasic_URI *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(NgBasic_URI), (void *) data);
}

void NgBasic_URISequence_Append (NgBasic_URISequence *h, NgBasic_URI item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_URI), err);
}

void NgBasic_URISequence_Push (NgBasic_URISequence *h, NgBasic_URI item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_URI));
}

void NgBasic_URISequence_Pop (NgBasic_URISequence *h, NgBasic_URI *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgBasic_URI));
}

CORBA_unsigned_long NgBasic_URISequence_Length (NgBasic_URISequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

NgBasic_URI * NgBasic_URISequence_Nth (NgBasic_URISequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgBasic_URISequence * NgBasic_URISequence_Create (CORBA_unsigned_long sz, NgBasic_URI *p)
{
  NgBasic_URISequence *s;
  s = (NgBasic_URISequence *) ilu_malloc(sizeof(NgBasic_URISequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgBasic_URISequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((NgBasic_URI *) ilu_malloc(sz * sizeof(NgBasic_URI))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(NgBasic_URI));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgBasic_URISequence_Init (NgBasic_URISequence *s, CORBA_unsigned_long sz, NgBasic_URI *p)
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
    s->_buffer = (NgBasic_URI *) ilu_malloc (sz * sizeof (NgBasic_URI));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(NgBasic_URI)); }}
  else
    s->_buffer = p;
  return;
}

void NgBasic_ByteSequence_Every (NgBasic_ByteSequence *h, void (*f)(CORBA_octet *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_octet), (void *) data);
}

void NgBasic_ByteSequence_Append (NgBasic_ByteSequence *h, CORBA_octet item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet), err);
}

void NgBasic_ByteSequence_Push (NgBasic_ByteSequence *h, CORBA_octet item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet));
}

void NgBasic_ByteSequence_Pop (NgBasic_ByteSequence *h, CORBA_octet *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_octet));
}

CORBA_unsigned_long NgBasic_ByteSequence_Length (NgBasic_ByteSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_octet * NgBasic_ByteSequence_Nth (NgBasic_ByteSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgBasic_ByteSequence * NgBasic_ByteSequence_Create (CORBA_unsigned_long sz, CORBA_octet *p)
{
  NgBasic_ByteSequence *s;
  s = (NgBasic_ByteSequence *) ilu_malloc(sizeof(NgBasic_ByteSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgBasic_ByteSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_octet *) ilu_malloc(sz * sizeof(CORBA_octet))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_octet));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgBasic_ByteSequence_Init (NgBasic_ByteSequence *s, CORBA_unsigned_long sz, CORBA_octet *p)
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

void NgBasic_StringSequence_Every (NgBasic_StringSequence *h, void (*f)(NgBasic_String *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(NgBasic_String), (void *) data);
}

void NgBasic_StringSequence_Append (NgBasic_StringSequence *h, NgBasic_String item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_String), err);
}

void NgBasic_StringSequence_Push (NgBasic_StringSequence *h, NgBasic_String item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgBasic_String));
}

void NgBasic_StringSequence_Pop (NgBasic_StringSequence *h, NgBasic_String *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgBasic_String));
}

CORBA_unsigned_long NgBasic_StringSequence_Length (NgBasic_StringSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

NgBasic_String * NgBasic_StringSequence_Nth (NgBasic_StringSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgBasic_StringSequence * NgBasic_StringSequence_Create (CORBA_unsigned_long sz, NgBasic_String *p)
{
  NgBasic_StringSequence *s;
  s = (NgBasic_StringSequence *) ilu_malloc(sizeof(NgBasic_StringSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgBasic_StringSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((NgBasic_String *) ilu_malloc(sz * sizeof(NgBasic_String))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(NgBasic_String));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgBasic_StringSequence_Init (NgBasic_StringSequence *s, CORBA_unsigned_long sz, NgBasic_String *p)
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
    s->_buffer = (NgBasic_String *) ilu_malloc (sz * sizeof (NgBasic_String));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(NgBasic_String)); }}
  else
    s->_buffer = p;
  return;
}

void NgBasic_String_Every (NgBasic_String *h, void (*f)(CORBA_char *, void *), void * data)
{
  CORBA_char *p;
  for (p = *h;  *p != 0;  p++) (*f)(p, data);
}

void NgBasic_String_Append (NgBasic_String *h, CORBA_char item, ilu_Error* err)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 1);
}

void NgBasic_String_Push (NgBasic_String *h, CORBA_char item)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 0);
}

void NgBasic_String_Pop (NgBasic_String *h, CORBA_char *item)
{
  _ILU_C_PopString (h, item);
}

CORBA_unsigned_long NgBasic_String_Length (NgBasic_String *h)
{
  if (h == ILU_NIL || *h == ILU_NIL) return 0;
  return (strlen((char *)(*h)));
}

CORBA_char * NgBasic_String_Nth (NgBasic_String *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || *h == ILU_NIL) return ILU_NIL;
  if (n >= strlen((char*)(*h)))
    return ILU_NIL;
else return &((*h)[n]);
}

NgBasic_String NgBasic_String_Create (CORBA_unsigned_long sz, CORBA_char *p)
{
  NgBasic_String s;

  if (p == ILU_NIL)
    {
      s = ilu_malloc(sz * sizeof(CORBA_char));
      if (s == ILU_NIL) {        _ILU_C_MallocFailure(sz * sizeof(CORBA_char));        return ILU_NIL; }
      memset((void *) s, 0, sz * sizeof(CORBA_char));
      return s;
    }
  else
    return p;
}

void NgBasic_String_Init (NgBasic_String *s, CORBA_unsigned_long sz)
{
  return;
}

void _NgBasic__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("NgBasic", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _NgBasic__Exception_WouldBlock = ilu_DefineException("NgBasic", "WouldBlock", "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _NgBasic__Exception_Conflict = ilu_DefineException("NgBasic", "Conflict", "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _NgBasic__Exception_ObjectNotExist = ilu_DefineException("NgBasic", "ObjectNotExist", "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("NgBasic.NgObject",	/*name*/
	NULL,	/*no brand*/
	"ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	1,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgBasic_NgObject__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"GetInterfaceDefinitionSource",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _NgBasic_NgObjectSequence__IoFns.kernelType = ilu_RegisterSequenceType("NgObjectSequence", "NgBasic", "NG", "ilut:bqWhqXfPmQ0OnFRSDF++uY7KnKx",
    "ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_NgObject__IoFns.kernelType = ilu_RegisterObjectType("NgObject", "NgBasic", "NG", "ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3",
    _NgBasic_NgObject__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_ExceptionInformation__IoFns.kernelType = type = ilu_RegisterRecordType("ExceptionInformation", "NgBasic", "NG", "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "reasonPhrase", /* field name */
      "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "specificsData", /* field name */
      "ilut:on5t6u5LDRoo+AtGkW9ncvntNZw", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgBasic_OptionalPickle__IoFns.kernelType = ilu_RegisterOptionalType("OptionalPickle", "NgBasic", "NG", "ilut:on5t6u5LDRoo+AtGkW9ncvntNZw",
    "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_NameSequence__IoFns.kernelType = ilu_RegisterSequenceType("NameSequence", "NgBasic", "NG", "ilut:jnKRp54g57gOe7fPCulRE7vmvPc",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_NameValuePairSequence__IoFns.kernelType = ilu_RegisterSequenceType("NameValuePairSequence", "NgBasic", "NG", "ilut:ovYm9PlmGfhDKZj5JkVFnkAntlC",
    "ilut:llyaclLXkJ5rS7qiIv4Fpupayvw",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_NameValuePair__IoFns.kernelType = type = ilu_RegisterRecordType("NameValuePair", "NgBasic", "NG", "ilut:llyaclLXkJ5rS7qiIv4Fpupayvw",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "name", /* field name */
      "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "value", /* field name */
      "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgBasic_OptionalUnsignedInclusiveInterval__IoFns.kernelType = ilu_RegisterOptionalType("OptionalUnsignedInclusiveInterval", "NgBasic", "NG", "ilut:mdFsF5jq+msKV1hcVFdaMToJPMs",
    "ilut:ijhRh2ztjcTnB71rJMJySaH2QWI", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_UnsignedInclusiveInterval__IoFns.kernelType = type = ilu_RegisterRecordType("UnsignedInclusiveInterval", "NgBasic", "NG", "ilut:ijhRh2ztjcTnB71rJMJySaH2QWI",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "startValue", /* field name */
      "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "endValue", /* field name */
      "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgBasic_Version__IoFns.kernelType = type = ilu_RegisterRecordType("Version", "NgBasic", "NG", "ilut:cYNlN9KQa8-1BMJ8V8mxA8lRdGa",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "major", /* field name */
      "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "minor", /* field name */
      "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgBasic_OptionalRelativeTime__IoFns.kernelType = ilu_RegisterOptionalType("OptionalRelativeTime", "NgBasic", "NG", "ilut:hGxicZDmFes+c9kIA8MKlNDnvYv",
    "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("RelativeTime", "NgBasic", "NG", "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg",
    "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_OptionalAbsoluteTime__IoFns.kernelType = ilu_RegisterOptionalType("OptionalAbsoluteTime", "NgBasic", "NG", "ilut:oyVqGbZWQ4+HRtnw9jG5E2IR1ZK",
    "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("AbsoluteTime", "NgBasic", "NG", "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg",
    "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_OptionalCardinal__IoFns.kernelType = ilu_RegisterOptionalType("OptionalCardinal", "NgBasic", "NG", "ilut:dZcZXjVtqsFnjSSxNyBk9rN3vxq",
    "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_URISequence__IoFns.kernelType = ilu_RegisterSequenceType("URISequence", "NgBasic", "NG", "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_OptionalURI__IoFns.kernelType = ilu_RegisterOptionalType("OptionalURI", "NgBasic", "NG", "ilut:kwagdxa3MUBXSAWpOS1TUCMm-J+",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("URI", "NgBasic", "NG", "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_ByteSequence__IoFns.kernelType = ilu_RegisterSequenceType("ByteSequence", "NgBasic", "NG", "ilut:iw+TJyerx6QHNk2sCXPGzL8d90a",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_StringSequence__IoFns.kernelType = ilu_RegisterSequenceType("StringSequence", "NgBasic", "NG", "ilut:pVA9NPjxKPIk45Pouoxx46IkczI",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_OptionalString__IoFns.kernelType = ilu_RegisterOptionalType("OptionalString", "NgBasic", "NG", "ilut:krQWr8h8gb6uJ7RmH-7ZLXpF-Oy",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgBasic_String__IoFns.kernelType = ilu_RegisterSequenceType("String", "NgBasic", "NG", "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",
    "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _NgBasic_NgObjectSequence__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_NgObjectSequence__Input;
  _NgBasic_NgObjectSequence__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_NgObjectSequence__Output;
  _NgBasic_NgObjectSequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_NgObjectSequence__SizeOf;
  _NgBasic_NgObjectSequence__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_NgObjectSequence__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_NgObjectSequence__IoFns);

  _NgBasic_NgObject__IoFns.properties.object_class = _NgBasic_NgObject__ILUType;
  _ILU_C_RegisterIoFns (&_NgBasic_NgObject__IoFns);

  _NgBasic_ExceptionInformation__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input;
  _NgBasic_ExceptionInformation__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output;
  _NgBasic_ExceptionInformation__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf;
  _NgBasic_ExceptionInformation__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_ExceptionInformation__IoFns);

  _NgBasic_OptionalPickle__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_OptionalPickle__Input;
  _NgBasic_OptionalPickle__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_OptionalPickle__Output;
  _NgBasic_OptionalPickle__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_OptionalPickle__SizeOf;
  _NgBasic_OptionalPickle__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_OptionalPickle__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_OptionalPickle__IoFns);

  _NgBasic_NameSequence__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_NameSequence__Input;
  _NgBasic_NameSequence__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_NameSequence__Output;
  _NgBasic_NameSequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_NameSequence__SizeOf;
  _NgBasic_NameSequence__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_NameSequence__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_NameSequence__IoFns);

  _NgBasic_NameValuePairSequence__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_NameValuePairSequence__Input;
  _NgBasic_NameValuePairSequence__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_NameValuePairSequence__Output;
  _NgBasic_NameValuePairSequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_NameValuePairSequence__SizeOf;
  _NgBasic_NameValuePairSequence__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_NameValuePairSequence__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_NameValuePairSequence__IoFns);

  _NgBasic_NameValuePair__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_NameValuePair__Input;
  _NgBasic_NameValuePair__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_NameValuePair__Output;
  _NgBasic_NameValuePair__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_NameValuePair__SizeOf;
  _NgBasic_NameValuePair__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_NameValuePair__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_NameValuePair__IoFns);

  _NgBasic_OptionalUnsignedInclusiveInterval__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_OptionalUnsignedInclusiveInterval__Input;
  _NgBasic_OptionalUnsignedInclusiveInterval__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_OptionalUnsignedInclusiveInterval__Output;
  _NgBasic_OptionalUnsignedInclusiveInterval__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_OptionalUnsignedInclusiveInterval__SizeOf;
  _NgBasic_OptionalUnsignedInclusiveInterval__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_OptionalUnsignedInclusiveInterval__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_OptionalUnsignedInclusiveInterval__IoFns);

  _NgBasic_UnsignedInclusiveInterval__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_UnsignedInclusiveInterval__Input;
  _NgBasic_UnsignedInclusiveInterval__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_UnsignedInclusiveInterval__Output;
  _NgBasic_UnsignedInclusiveInterval__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_UnsignedInclusiveInterval__SizeOf;
  _NgBasic_UnsignedInclusiveInterval__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_NgBasic_UnsignedInclusiveInterval__IoFns);

  _NgBasic_Version__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_Version__Input;
  _NgBasic_Version__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_Version__Output;
  _NgBasic_Version__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_Version__SizeOf;
  _NgBasic_Version__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_NgBasic_Version__IoFns);

  _NgBasic_OptionalRelativeTime__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_OptionalRelativeTime__Input;
  _NgBasic_OptionalRelativeTime__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_OptionalRelativeTime__Output;
  _NgBasic_OptionalRelativeTime__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_OptionalRelativeTime__SizeOf;
  _NgBasic_OptionalRelativeTime__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_OptionalRelativeTime__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_OptionalRelativeTime__IoFns);

  _NgBasic_OptionalAbsoluteTime__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_OptionalAbsoluteTime__Input;
  _NgBasic_OptionalAbsoluteTime__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_OptionalAbsoluteTime__Output;
  _NgBasic_OptionalAbsoluteTime__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_OptionalAbsoluteTime__SizeOf;
  _NgBasic_OptionalAbsoluteTime__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_OptionalAbsoluteTime__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_OptionalAbsoluteTime__IoFns);

  _NgBasic_OptionalCardinal__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_OptionalCardinal__Input;
  _NgBasic_OptionalCardinal__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_OptionalCardinal__Output;
  _NgBasic_OptionalCardinal__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_OptionalCardinal__SizeOf;
  _NgBasic_OptionalCardinal__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_OptionalCardinal__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_OptionalCardinal__IoFns);

  _NgBasic_URISequence__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_URISequence__Input;
  _NgBasic_URISequence__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_URISequence__Output;
  _NgBasic_URISequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_URISequence__SizeOf;
  _NgBasic_URISequence__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_URISequence__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_URISequence__IoFns);

  _NgBasic_OptionalURI__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_OptionalURI__Input;
  _NgBasic_OptionalURI__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_OptionalURI__Output;
  _NgBasic_OptionalURI__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_OptionalURI__SizeOf;
  _NgBasic_OptionalURI__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_OptionalURI__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_OptionalURI__IoFns);

  _NgBasic_ByteSequence__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_ByteSequence__Input;
  _NgBasic_ByteSequence__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_ByteSequence__Output;
  _NgBasic_ByteSequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_ByteSequence__SizeOf;
  _NgBasic_ByteSequence__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_ByteSequence__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_ByteSequence__IoFns);

  _NgBasic_StringSequence__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_StringSequence__Input;
  _NgBasic_StringSequence__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_StringSequence__Output;
  _NgBasic_StringSequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_StringSequence__SizeOf;
  _NgBasic_StringSequence__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_StringSequence__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_StringSequence__IoFns);

  _NgBasic_OptionalString__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_OptionalString__Input;
  _NgBasic_OptionalString__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_OptionalString__Output;
  _NgBasic_OptionalString__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_OptionalString__SizeOf;
  _NgBasic_OptionalString__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_OptionalString__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_OptionalString__IoFns);

  _NgBasic_String__IoFns.inputFn = (ILU_C_InputFn) _NgBasic_String__Input;
  _NgBasic_String__IoFns.outFn = (ILU_C_OutputFn) _NgBasic_String__Output;
  _NgBasic_String__IoFns.sizeFn = (ILU_C_SizeFn) _NgBasic_String__SizeOf;
  _NgBasic_String__IoFns.freeFn = (ILU_C_FreeFn) NgBasic_String__Free;
  _ILU_C_RegisterIoFns (&_NgBasic_String__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

