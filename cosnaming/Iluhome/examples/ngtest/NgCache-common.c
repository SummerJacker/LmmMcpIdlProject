/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgCache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "NgCache.h"

struct _ILU_C_IoFnsRegistration_s _NgCache_OptionalResponseCacheControl__IoFns = { ilu_optional_tk, "ilut:ndDitjkJSN2EudLTF5z4PXYSGiA", { sizeof(NgCache_OptionalResponseCacheControl) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgCache_ResponseCacheControl__IoFns = { ilu_record_tk, "ilut:gOsnv5L7LHmsonM8ieFf1OsZD5A", { sizeof(NgCache_ResponseCacheControl) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgCache_OptionalRequestCacheControl__IoFns = { ilu_optional_tk, "ilut:iqacMndTHig-XKjynOJnqaO1tYm", { sizeof(NgCache_OptionalRequestCacheControl) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgCache_RequestCacheControl__IoFns = { ilu_record_tk, "ilut:fm2NdirI9ThWzBuqX+k7YYTZxfb", { sizeof(NgCache_RequestCacheControl) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgCache_EntityTagOrDate__IoFns = { ilu_union_tk, "ilut:i0nIi+HsBIr0yDg+-bvX4zzqE9t", { sizeof(NgCache_EntityTagOrDate) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgCache_EntityTagSequence__IoFns = { ilu_sequence_tk, "ilut:lMWmfx95VPUyXvQWSLhsoK-HvqA", { sizeof(NgCache_EntityTagSequence) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgCache_OptionalEntityTag__IoFns = { ilu_optional_tk, "ilut:kEWPp1zCgLEnsR8q6Kpo6fYHhP-", { sizeof(NgCache_OptionalEntityTag) }, ILU_NIL, 0, 0, 0, 0 };


NgCache_OptionalResponseCacheControl* _NgCache_OptionalResponseCacheControl__Input (ilu_Call _call, NgCache_OptionalResponseCacheControl* _ref, ilu_Error *_err)
{
  NgCache_OptionalResponseCacheControl* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgCache_OptionalResponseCacheControl), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgCache_OptionalResponseCacheControl *) ilu_MallocE (sizeof (NgCache_OptionalResponseCacheControl), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgCache_OptionalResponseCacheControl));
  };
  if (_present)
    {
    *_val = (NgCache_ResponseCacheControl*) ilu_MallocE (sizeof (NgCache_ResponseCacheControl), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(NgCache_ResponseCacheControl));
      (void) _NgCache_ResponseCacheControl__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgCache_OptionalResponseCacheControl__Output (ilu_Call _call, NgCache_OptionalResponseCacheControl _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgCache_OptionalResponseCacheControl), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgCache_ResponseCacheControl__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgCache_OptionalResponseCacheControl__SizeOf (ilu_Call _call, NgCache_OptionalResponseCacheControl _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgCache_OptionalResponseCacheControl), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgCache_ResponseCacheControl__SizeOf (_call, &*_val, _err);
  return size;
}

void NgCache_OptionalResponseCacheControl__Free (NgCache_OptionalResponseCacheControl* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgCache_OptionalResponseCacheControl */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgCache_ResponseCacheControl */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgCache_ResponseCacheControl__Free (&**_val);
    ilu_free(*_val);
  }
}

NgCache_OptionalResponseCacheControl *CORBA_sequence_NgCache_OptionalResponseCacheControl_allocbuf (CORBA_unsigned_long _count)
{
  NgCache_OptionalResponseCacheControl *_p;
  CORBA_unsigned_long _size = sizeof(NgCache_OptionalResponseCacheControl) * _count;

  if ((_p = (NgCache_OptionalResponseCacheControl *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgCache_OptionalResponseCacheControl* NgCache_OptionalResponseCacheControl__alloc ()
{
  return ((NgCache_OptionalResponseCacheControl*) CORBA_sequence_NgCache_OptionalResponseCacheControl_allocbuf(1));
}

NgCache_ResponseCacheControl* _NgCache_ResponseCacheControl__Input (ilu_Call _call, NgCache_ResponseCacheControl* _ref, ilu_Error *_err)
{
  NgCache_ResponseCacheControl* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgCache_ResponseCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgCache_ResponseCacheControl__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgCache_ResponseCacheControl*) ilu_MallocE (sizeof (NgCache_ResponseCacheControl), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgCache_ResponseCacheControl));
    } else {
      _val = (NgCache_ResponseCacheControl*) _ILU_C_CRCreate (s, sizeof(NgCache_ResponseCacheControl), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgCache_ResponseCacheControl), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->okPublic, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->isPrivate, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->noCache, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->noStore, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->noTransform, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->mustRevalidate, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->proxyRevalidate, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalRelativeTime__Input (_call, &_val->maxAge,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalRelativeTime__Input (_call, &_val->sMaxAge,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalRelativeTime__Input (_call, &_val->age,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_StringSequence__Input (_call, &_val->vary,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_OptionalEntityTag__Input (_call, &_val->entityTag,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalAbsoluteTime__Input (_call, &_val->lastModified,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalAbsoluteTime__Input (_call, &_val->expires,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgCache_ResponseCacheControl__Output (ilu_Call _call, NgCache_ResponseCacheControl* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgCache_ResponseCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgCache_ResponseCacheControl__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgCache_ResponseCacheControl), _err);
    if (ILU_ERRNOK(*_err)) return;
  ILU_C_OutputBoolean(_call, (_val->okPublic), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->isPrivate), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->noCache), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->noStore), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->noTransform), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->mustRevalidate), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->proxyRevalidate), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalRelativeTime__Output(_call, (_val->maxAge), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalRelativeTime__Output(_call, (_val->sMaxAge), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalRelativeTime__Output(_call, (_val->age), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_StringSequence__Output(_call, (&_val->vary), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgCache_OptionalEntityTag__Output(_call, (_val->entityTag), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalAbsoluteTime__Output(_call, (_val->lastModified), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalAbsoluteTime__Output(_call, (_val->expires), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgCache_ResponseCacheControl__SizeOf (ilu_Call _call, NgCache_ResponseCacheControl* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgCache_ResponseCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgCache_ResponseCacheControl__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgCache_ResponseCacheControl), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->okPublic, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->isPrivate, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->noCache, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->noStore, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->noTransform, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->mustRevalidate, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->proxyRevalidate, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalRelativeTime__SizeOf (_call, _val->maxAge, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalRelativeTime__SizeOf (_call, _val->sMaxAge, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalRelativeTime__SizeOf (_call, _val->age, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_StringSequence__SizeOf (_call, &_val->vary, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgCache_OptionalEntityTag__SizeOf (_call, _val->entityTag, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalAbsoluteTime__SizeOf (_call, _val->lastModified, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalAbsoluteTime__SizeOf (_call, _val->expires, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgCache_ResponseCacheControl__Free (NgCache_ResponseCacheControl* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgCache_ResponseCacheControl */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_NgCache_ResponseCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgCache_ResponseCacheControl__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  NgBasic_OptionalRelativeTime__Free (&_val->maxAge);
  NgBasic_OptionalRelativeTime__Free (&_val->sMaxAge);
  NgBasic_OptionalRelativeTime__Free (&_val->age);
  NgBasic_StringSequence__Free (&_val->vary);
  NgCache_OptionalEntityTag__Free (&_val->entityTag);
  NgBasic_OptionalAbsoluteTime__Free (&_val->lastModified);
  NgBasic_OptionalAbsoluteTime__Free (&_val->expires);
}

NgCache_ResponseCacheControl *CORBA_sequence_NgCache_ResponseCacheControl_allocbuf (CORBA_unsigned_long _count)
{
  NgCache_ResponseCacheControl *_p;
  CORBA_unsigned_long _size = sizeof(NgCache_ResponseCacheControl) * _count;

  if ((_p = (NgCache_ResponseCacheControl *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgCache_ResponseCacheControl* NgCache_ResponseCacheControl__alloc ()
{
  return ((NgCache_ResponseCacheControl*) CORBA_sequence_NgCache_ResponseCacheControl_allocbuf(1));
}

NgCache_OptionalRequestCacheControl* _NgCache_OptionalRequestCacheControl__Input (ilu_Call _call, NgCache_OptionalRequestCacheControl* _ref, ilu_Error *_err)
{
  NgCache_OptionalRequestCacheControl* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgCache_OptionalRequestCacheControl), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgCache_OptionalRequestCacheControl *) ilu_MallocE (sizeof (NgCache_OptionalRequestCacheControl), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgCache_OptionalRequestCacheControl));
  };
  if (_present)
    {
    *_val = (NgCache_RequestCacheControl*) ilu_MallocE (sizeof (NgCache_RequestCacheControl), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(NgCache_RequestCacheControl));
      (void) _NgCache_RequestCacheControl__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgCache_OptionalRequestCacheControl__Output (ilu_Call _call, NgCache_OptionalRequestCacheControl _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgCache_OptionalRequestCacheControl), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgCache_RequestCacheControl__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgCache_OptionalRequestCacheControl__SizeOf (ilu_Call _call, NgCache_OptionalRequestCacheControl _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgCache_OptionalRequestCacheControl), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgCache_RequestCacheControl__SizeOf (_call, &*_val, _err);
  return size;
}

void NgCache_OptionalRequestCacheControl__Free (NgCache_OptionalRequestCacheControl* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgCache_OptionalRequestCacheControl */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgCache_RequestCacheControl */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgCache_RequestCacheControl__Free (&**_val);
    ilu_free(*_val);
  }
}

NgCache_OptionalRequestCacheControl *CORBA_sequence_NgCache_OptionalRequestCacheControl_allocbuf (CORBA_unsigned_long _count)
{
  NgCache_OptionalRequestCacheControl *_p;
  CORBA_unsigned_long _size = sizeof(NgCache_OptionalRequestCacheControl) * _count;

  if ((_p = (NgCache_OptionalRequestCacheControl *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgCache_OptionalRequestCacheControl* NgCache_OptionalRequestCacheControl__alloc ()
{
  return ((NgCache_OptionalRequestCacheControl*) CORBA_sequence_NgCache_OptionalRequestCacheControl_allocbuf(1));
}

NgCache_RequestCacheControl* _NgCache_RequestCacheControl__Input (ilu_Call _call, NgCache_RequestCacheControl* _ref, ilu_Error *_err)
{
  NgCache_RequestCacheControl* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgCache_RequestCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgCache_RequestCacheControl__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgCache_RequestCacheControl*) ilu_MallocE (sizeof (NgCache_RequestCacheControl), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgCache_RequestCacheControl));
    } else {
      _val = (NgCache_RequestCacheControl*) _ILU_C_CRCreate (s, sizeof(NgCache_RequestCacheControl), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgCache_RequestCacheControl), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->noCache, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->noStore, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->noTransform, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->onlyIfCached, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalAbsoluteTime__Input (_call, &_val->ifModifiedSince,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_EntityTagSequence__Input (_call, &_val->ifMatch,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_EntityTagSequence__Input (_call, &_val->ifNoneMatch,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_EntityTagOrDate__Input (_call, &_val->ifRange,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgCache_RequestCacheControl__Output (ilu_Call _call, NgCache_RequestCacheControl* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgCache_RequestCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgCache_RequestCacheControl__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgCache_RequestCacheControl), _err);
    if (ILU_ERRNOK(*_err)) return;
  ILU_C_OutputBoolean(_call, (_val->noCache), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->noStore), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->noTransform), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->onlyIfCached), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalAbsoluteTime__Output(_call, (_val->ifModifiedSince), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgCache_EntityTagSequence__Output(_call, (&_val->ifMatch), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgCache_EntityTagSequence__Output(_call, (&_val->ifNoneMatch), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgCache_EntityTagOrDate__Output(_call, (&_val->ifRange), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgCache_RequestCacheControl__SizeOf (ilu_Call _call, NgCache_RequestCacheControl* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgCache_RequestCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgCache_RequestCacheControl__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgCache_RequestCacheControl), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->noCache, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->noStore, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->noTransform, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->onlyIfCached, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalAbsoluteTime__SizeOf (_call, _val->ifModifiedSince, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgCache_EntityTagSequence__SizeOf (_call, &_val->ifMatch, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgCache_EntityTagSequence__SizeOf (_call, &_val->ifNoneMatch, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgCache_EntityTagOrDate__SizeOf (_call, &_val->ifRange, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgCache_RequestCacheControl__Free (NgCache_RequestCacheControl* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgCache_RequestCacheControl */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_NgCache_RequestCacheControl__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgCache_RequestCacheControl__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  NgBasic_OptionalAbsoluteTime__Free (&_val->ifModifiedSince);
  NgCache_EntityTagSequence__Free (&_val->ifMatch);
  NgCache_EntityTagSequence__Free (&_val->ifNoneMatch);
  NgCache_EntityTagOrDate__Free (&_val->ifRange);
}

NgCache_RequestCacheControl *CORBA_sequence_NgCache_RequestCacheControl_allocbuf (CORBA_unsigned_long _count)
{
  NgCache_RequestCacheControl *_p;
  CORBA_unsigned_long _size = sizeof(NgCache_RequestCacheControl) * _count;

  if ((_p = (NgCache_RequestCacheControl *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgCache_RequestCacheControl* NgCache_RequestCacheControl__alloc ()
{
  return ((NgCache_RequestCacheControl*) CORBA_sequence_NgCache_RequestCacheControl_allocbuf(1));
}

NgCache_EntityTagOrDate* _NgCache_EntityTagOrDate__Input (ilu_Call _call, NgCache_EntityTagOrDate* _ref, ilu_Error *_err)
{
  NgCache_EntityTagOrDate* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgCache_EntityTagOrDate), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgCache_EntityTagOrDate*) ilu_MallocE(sizeof (NgCache_EntityTagOrDate), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(NgCache_EntityTagOrDate));
  };
  switch (tag) {
    case 0:
      (void) _NgBasic_String__Input (_call, &_val->_u.etag,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      ilu_InputLongInteger (_call, &_val->_u.ifdate, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgCache_EntityTagOrDate__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_short) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgCache_EntityTagOrDate__Output (ilu_Call _call, NgCache_EntityTagOrDate* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgCache_EntityTagOrDate), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _NgBasic_String__Output(_call, _val->_u.etag, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      ilu_OutputLongInteger(_call, _val->_u.ifdate, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgCache_EntityTagOrDate__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _NgCache_EntityTagOrDate__SizeOf (ilu_Call _call, NgCache_EntityTagOrDate* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgCache_EntityTagOrDate), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _NgBasic_String__SizeOf (_call, _val->_u.etag, _err);
      break;
    case 1:
      size += ilu_SizeOfLongInteger(_call, _val->_u.ifdate, _err);
      break;
    default:
      fprintf (stderr, "_NgCache_EntityTagOrDate__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgCache_EntityTagOrDate__Free (NgCache_EntityTagOrDate* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgCache_EntityTagOrDate */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      NgBasic_String__Free (&_val->_u.etag);
      break;
    case 1:
      break;
    default:
      fprintf (stderr, "NgCache_EntityTagOrDate__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

NgCache_EntityTagOrDate *CORBA_sequence_NgCache_EntityTagOrDate_allocbuf (CORBA_unsigned_long _count)
{
  NgCache_EntityTagOrDate *_p;
  CORBA_unsigned_long _size = sizeof(NgCache_EntityTagOrDate) * _count;

  if ((_p = (NgCache_EntityTagOrDate *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgCache_EntityTagOrDate* NgCache_EntityTagOrDate__alloc ()
{
  return ((NgCache_EntityTagOrDate*) CORBA_sequence_NgCache_EntityTagOrDate_allocbuf(1));
}

NgCache_EntityTagSequence* _NgCache_EntityTagSequence__Input (ilu_Call _call, NgCache_EntityTagSequence* _ref, ilu_Error *_err)
{
  NgCache_EntityTagSequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  NgBasic_String _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (NgCache_EntityTagSequence*) ilu_MallocE(sizeof (NgCache_EntityTagSequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  NgCache_EntityTagSequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(NgCache_EntityTagSequence), _err);
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
      NgCache_EntityTagSequence_Append (_val, _tmp, _err);
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

void _NgCache_EntityTagSequence__Output (ilu_Call _call, NgCache_EntityTagSequence* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgCache_EntityTagSequence), _err);
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

ilu_cardinal _NgCache_EntityTagSequence__SizeOf (ilu_Call _call, NgCache_EntityTagSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgCache_EntityTagSequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_String), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(NgCache_EntityTag), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    NgCache_EntityTag *p;  unsigned long i;

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

void NgCache_EntityTagSequence__Free (NgCache_EntityTagSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgCache_EntityTagSequence */
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
    //ilu_DebugPrintf("OK NgCache_EntityTagSequence__Free (NgCache_EntityTagSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgCache_EntityTagSequence *CORBA_sequence_NgCache_EntityTagSequence_allocbuf (CORBA_unsigned_long _count)
{
  NgCache_EntityTagSequence *_p;
  CORBA_unsigned_long _size = sizeof(NgCache_EntityTagSequence) * _count;

  if ((_p = (NgCache_EntityTagSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgCache_EntityTagSequence* NgCache_EntityTagSequence__alloc ()
{
  return ((NgCache_EntityTagSequence*) CORBA_sequence_NgCache_EntityTagSequence_allocbuf(1));
}

NgCache_OptionalEntityTag* _NgCache_OptionalEntityTag__Input (ilu_Call _call, NgCache_OptionalEntityTag* _ref, ilu_Error *_err)
{
  NgCache_OptionalEntityTag* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgCache_OptionalEntityTag), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgCache_OptionalEntityTag *) ilu_MallocE (sizeof (NgCache_OptionalEntityTag), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgCache_OptionalEntityTag));
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

void _NgCache_OptionalEntityTag__Output (ilu_Call _call, NgCache_OptionalEntityTag _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgCache_OptionalEntityTag), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgBasic_String__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgCache_OptionalEntityTag__SizeOf (ilu_Call _call, NgCache_OptionalEntityTag _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgCache_OptionalEntityTag), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgBasic_String__SizeOf (_call, _val, _err);
  return size;
}

void NgCache_OptionalEntityTag__Free (NgCache_OptionalEntityTag* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgCache_OptionalEntityTag */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgBasic_String */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgBasic_String__Free (&*_val);
  }
}

NgCache_OptionalEntityTag *CORBA_sequence_NgCache_OptionalEntityTag_allocbuf (CORBA_unsigned_long _count)
{
  NgCache_OptionalEntityTag *_p;
  CORBA_unsigned_long _size = sizeof(NgCache_OptionalEntityTag) * _count;

  if ((_p = (NgCache_OptionalEntityTag *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgCache_OptionalEntityTag* NgCache_OptionalEntityTag__alloc ()
{
  return ((NgCache_OptionalEntityTag*) CORBA_sequence_NgCache_OptionalEntityTag_allocbuf(1));
}

void NgCache_EntityTagSequence_Every (NgCache_EntityTagSequence *h, void (*f)(NgCache_EntityTag *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(NgCache_EntityTag), (void *) data);
}

void NgCache_EntityTagSequence_Append (NgCache_EntityTagSequence *h, NgCache_EntityTag item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgCache_EntityTag), err);
}

void NgCache_EntityTagSequence_Push (NgCache_EntityTagSequence *h, NgCache_EntityTag item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(NgCache_EntityTag));
}

void NgCache_EntityTagSequence_Pop (NgCache_EntityTagSequence *h, NgCache_EntityTag *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgCache_EntityTag));
}

CORBA_unsigned_long NgCache_EntityTagSequence_Length (NgCache_EntityTagSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

NgCache_EntityTag * NgCache_EntityTagSequence_Nth (NgCache_EntityTagSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgCache_EntityTagSequence * NgCache_EntityTagSequence_Create (CORBA_unsigned_long sz, NgCache_EntityTag *p)
{
  NgCache_EntityTagSequence *s;
  s = (NgCache_EntityTagSequence *) ilu_malloc(sizeof(NgCache_EntityTagSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgCache_EntityTagSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((NgCache_EntityTag *) ilu_malloc(sz * sizeof(NgCache_EntityTag))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(NgCache_EntityTag));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgCache_EntityTagSequence_Init (NgCache_EntityTagSequence *s, CORBA_unsigned_long sz, NgCache_EntityTag *p)
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
    s->_buffer = (NgCache_EntityTag *) ilu_malloc (sz * sizeof (NgCache_EntityTag));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(NgCache_EntityTag)); }}
  else
    s->_buffer = p;
  return;
}

void _NgCache__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("NgCache", "2.0beta1", "v2 (2.0beta1)");
  _NgBasic__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _NgCache_OptionalResponseCacheControl__IoFns.kernelType = ilu_RegisterOptionalType("OptionalResponseCacheControl", "NgCache", "NG", "ilut:ndDitjkJSN2EudLTF5z4PXYSGiA",
    "ilut:gOsnv5L7LHmsonM8ieFf1OsZD5A", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgCache_ResponseCacheControl__IoFns.kernelType = type = ilu_RegisterRecordType("ResponseCacheControl", "NgCache", "NG", "ilut:gOsnv5L7LHmsonM8ieFf1OsZD5A",
    14,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "okPublic", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "isPrivate", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "noCache", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "noStore", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "noTransform", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "mustRevalidate", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 6, /* which field */
      "proxyRevalidate", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 7, /* which field */
      "maxAge", /* field name */
      "ilut:hGxicZDmFes+c9kIA8MKlNDnvYv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 8, /* which field */
      "sMaxAge", /* field name */
      "ilut:hGxicZDmFes+c9kIA8MKlNDnvYv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 9, /* which field */
      "age", /* field name */
      "ilut:hGxicZDmFes+c9kIA8MKlNDnvYv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 10, /* which field */
      "vary", /* field name */
      "ilut:pVA9NPjxKPIk45Pouoxx46IkczI", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 11, /* which field */
      "entityTag", /* field name */
      "ilut:kEWPp1zCgLEnsR8q6Kpo6fYHhP-", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 12, /* which field */
      "lastModified", /* field name */
      "ilut:oyVqGbZWQ4+HRtnw9jG5E2IR1ZK", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 13, /* which field */
      "expires", /* field name */
      "ilut:oyVqGbZWQ4+HRtnw9jG5E2IR1ZK", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgCache_OptionalRequestCacheControl__IoFns.kernelType = ilu_RegisterOptionalType("OptionalRequestCacheControl", "NgCache", "NG", "ilut:iqacMndTHig-XKjynOJnqaO1tYm",
    "ilut:fm2NdirI9ThWzBuqX+k7YYTZxfb", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgCache_RequestCacheControl__IoFns.kernelType = type = ilu_RegisterRecordType("RequestCacheControl", "NgCache", "NG", "ilut:fm2NdirI9ThWzBuqX+k7YYTZxfb",
    8,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "noCache", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "noStore", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "noTransform", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "onlyIfCached", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "ifModifiedSince", /* field name */
      "ilut:oyVqGbZWQ4+HRtnw9jG5E2IR1ZK", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "ifMatch", /* field name */
      "ilut:lMWmfx95VPUyXvQWSLhsoK-HvqA", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 6, /* which field */
      "ifNoneMatch", /* field name */
      "ilut:lMWmfx95VPUyXvQWSLhsoK-HvqA", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 7, /* which field */
      "ifRange", /* field name */
      "ilut:i0nIi+HsBIr0yDg+-bvX4zzqE9t", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgCache_EntityTagOrDate__IoFns.kernelType = type = ilu_RegisterUnionType("EntityTagOrDate", "NgCache", "NG", "ilut:i0nIi+HsBIr0yDg+-bvX4zzqE9t",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* UID of discriminant type */
    2,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "etag", /* name of arm */
      "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 0;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "ifdate", /* name of arm */
      "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 1;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgCache_EntityTagSequence__IoFns.kernelType = ilu_RegisterSequenceType("EntityTagSequence", "NgCache", "NG", "ilut:lMWmfx95VPUyXvQWSLhsoK-HvqA",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgCache_OptionalEntityTag__IoFns.kernelType = ilu_RegisterOptionalType("OptionalEntityTag", "NgCache", "NG", "ilut:kEWPp1zCgLEnsR8q6Kpo6fYHhP-",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("EntityTag", "NgCache", "NG", "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _NgCache_OptionalResponseCacheControl__IoFns.inputFn = (ILU_C_InputFn) _NgCache_OptionalResponseCacheControl__Input;
  _NgCache_OptionalResponseCacheControl__IoFns.outFn = (ILU_C_OutputFn) _NgCache_OptionalResponseCacheControl__Output;
  _NgCache_OptionalResponseCacheControl__IoFns.sizeFn = (ILU_C_SizeFn) _NgCache_OptionalResponseCacheControl__SizeOf;
  _NgCache_OptionalResponseCacheControl__IoFns.freeFn = (ILU_C_FreeFn) NgCache_OptionalResponseCacheControl__Free;
  _ILU_C_RegisterIoFns (&_NgCache_OptionalResponseCacheControl__IoFns);

  _NgCache_ResponseCacheControl__IoFns.inputFn = (ILU_C_InputFn) _NgCache_ResponseCacheControl__Input;
  _NgCache_ResponseCacheControl__IoFns.outFn = (ILU_C_OutputFn) _NgCache_ResponseCacheControl__Output;
  _NgCache_ResponseCacheControl__IoFns.sizeFn = (ILU_C_SizeFn) _NgCache_ResponseCacheControl__SizeOf;
  _NgCache_ResponseCacheControl__IoFns.freeFn = (ILU_C_FreeFn) NgCache_ResponseCacheControl__Free;
  _ILU_C_RegisterIoFns (&_NgCache_ResponseCacheControl__IoFns);

  _NgCache_OptionalRequestCacheControl__IoFns.inputFn = (ILU_C_InputFn) _NgCache_OptionalRequestCacheControl__Input;
  _NgCache_OptionalRequestCacheControl__IoFns.outFn = (ILU_C_OutputFn) _NgCache_OptionalRequestCacheControl__Output;
  _NgCache_OptionalRequestCacheControl__IoFns.sizeFn = (ILU_C_SizeFn) _NgCache_OptionalRequestCacheControl__SizeOf;
  _NgCache_OptionalRequestCacheControl__IoFns.freeFn = (ILU_C_FreeFn) NgCache_OptionalRequestCacheControl__Free;
  _ILU_C_RegisterIoFns (&_NgCache_OptionalRequestCacheControl__IoFns);

  _NgCache_RequestCacheControl__IoFns.inputFn = (ILU_C_InputFn) _NgCache_RequestCacheControl__Input;
  _NgCache_RequestCacheControl__IoFns.outFn = (ILU_C_OutputFn) _NgCache_RequestCacheControl__Output;
  _NgCache_RequestCacheControl__IoFns.sizeFn = (ILU_C_SizeFn) _NgCache_RequestCacheControl__SizeOf;
  _NgCache_RequestCacheControl__IoFns.freeFn = (ILU_C_FreeFn) NgCache_RequestCacheControl__Free;
  _ILU_C_RegisterIoFns (&_NgCache_RequestCacheControl__IoFns);

  _NgCache_EntityTagOrDate__IoFns.inputFn = (ILU_C_InputFn) _NgCache_EntityTagOrDate__Input;
  _NgCache_EntityTagOrDate__IoFns.outFn = (ILU_C_OutputFn) _NgCache_EntityTagOrDate__Output;
  _NgCache_EntityTagOrDate__IoFns.sizeFn = (ILU_C_SizeFn) _NgCache_EntityTagOrDate__SizeOf;
  _NgCache_EntityTagOrDate__IoFns.freeFn = (ILU_C_FreeFn) NgCache_EntityTagOrDate__Free;
  _ILU_C_RegisterIoFns (&_NgCache_EntityTagOrDate__IoFns);

  _NgCache_EntityTagSequence__IoFns.inputFn = (ILU_C_InputFn) _NgCache_EntityTagSequence__Input;
  _NgCache_EntityTagSequence__IoFns.outFn = (ILU_C_OutputFn) _NgCache_EntityTagSequence__Output;
  _NgCache_EntityTagSequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgCache_EntityTagSequence__SizeOf;
  _NgCache_EntityTagSequence__IoFns.freeFn = (ILU_C_FreeFn) NgCache_EntityTagSequence__Free;
  _ILU_C_RegisterIoFns (&_NgCache_EntityTagSequence__IoFns);

  _NgCache_OptionalEntityTag__IoFns.inputFn = (ILU_C_InputFn) _NgCache_OptionalEntityTag__Input;
  _NgCache_OptionalEntityTag__IoFns.outFn = (ILU_C_OutputFn) _NgCache_OptionalEntityTag__Output;
  _NgCache_OptionalEntityTag__IoFns.sizeFn = (ILU_C_SizeFn) _NgCache_OptionalEntityTag__SizeOf;
  _NgCache_OptionalEntityTag__IoFns.freeFn = (ILU_C_FreeFn) NgCache_OptionalEntityTag__Free;
  _ILU_C_RegisterIoFns (&_NgCache_OptionalEntityTag__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

