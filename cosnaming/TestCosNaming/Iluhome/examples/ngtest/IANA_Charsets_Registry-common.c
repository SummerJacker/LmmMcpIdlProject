/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:00 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/ianacharsets.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "IANA_Charsets_Registry.h"

struct _ILU_C_IoFnsRegistration_s _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns = { ilu_optional_tk, "ilut:mN4YT+tl0wo8gRTACMIzqX4uW6o", { sizeof(IANA_Charsets_Registry_OptionalCharsetMIBEnumValue) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns = { ilu_sequence_tk, "ilut:garJ50fEH7VuQSw70iswIWle7xi", { sizeof(IANA_Charsets_Registry_CharsetMIBEnumValueSequence) }, ILU_NIL, 0, 0, 0, 0 };


IANA_Charsets_Registry_OptionalCharsetMIBEnumValue* _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Input (ilu_Call _call, IANA_Charsets_Registry_OptionalCharsetMIBEnumValue* _ref, ilu_Error *_err)
{
  IANA_Charsets_Registry_OptionalCharsetMIBEnumValue* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(IANA_Charsets_Registry_OptionalCharsetMIBEnumValue), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (IANA_Charsets_Registry_OptionalCharsetMIBEnumValue *) ilu_MallocE (sizeof (IANA_Charsets_Registry_OptionalCharsetMIBEnumValue), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(IANA_Charsets_Registry_OptionalCharsetMIBEnumValue));
  };
  if (_present)
    {
    *_val = (CORBA_unsigned_short*) ilu_MallocE (sizeof (CORBA_unsigned_short), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(CORBA_unsigned_short));
      ilu_InputShortCardinal (_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Output (ilu_Call _call, IANA_Charsets_Registry_OptionalCharsetMIBEnumValue _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(IANA_Charsets_Registry_OptionalCharsetMIBEnumValue), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  ilu_OutputShortCardinal (_call, *_val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__SizeOf (ilu_Call _call, IANA_Charsets_Registry_OptionalCharsetMIBEnumValue _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(IANA_Charsets_Registry_OptionalCharsetMIBEnumValue), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += ilu_SizeOfShortCardinal(_call, *_val, _err);
  return size;
}

void IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Free (IANA_Charsets_Registry_OptionalCharsetMIBEnumValue* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a IANA_Charsets_Registry_OptionalCharsetMIBEnumValue */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is CORBA_unsigned_short */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    ilu_free(*_val);
  }
}

IANA_Charsets_Registry_OptionalCharsetMIBEnumValue *CORBA_sequence_IANA_Charsets_Registry_OptionalCharsetMIBEnumValue_allocbuf (CORBA_unsigned_long _count)
{
  IANA_Charsets_Registry_OptionalCharsetMIBEnumValue *_p;
  CORBA_unsigned_long _size = sizeof(IANA_Charsets_Registry_OptionalCharsetMIBEnumValue) * _count;

  if ((_p = (IANA_Charsets_Registry_OptionalCharsetMIBEnumValue *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

IANA_Charsets_Registry_OptionalCharsetMIBEnumValue* IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__alloc ()
{
  return ((IANA_Charsets_Registry_OptionalCharsetMIBEnumValue*) CORBA_sequence_IANA_Charsets_Registry_OptionalCharsetMIBEnumValue_allocbuf(1));
}

IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Input (ilu_Call _call, IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _ref, ilu_Error *_err)
{
  IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  CORBA_unsigned_short _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (IANA_Charsets_Registry_CharsetMIBEnumValueSequence*) ilu_MallocE(sizeof (IANA_Charsets_Registry_CharsetMIBEnumValueSequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(IANA_Charsets_Registry_CharsetMIBEnumValueSequence), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CORBA_unsigned_short), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(CORBA_unsigned_short), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      ilu_InputShortCardinal (_call, &_tmp, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Append (_val, _tmp, _err);
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

void _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Output (ilu_Call _call, IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(IANA_Charsets_Registry_CharsetMIBEnumValueSequence), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_unsigned_short), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(CORBA_unsigned_short), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    CORBA_unsigned_short *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        ilu_OutputShortCardinal (_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__SizeOf (ilu_Call _call, IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(IANA_Charsets_Registry_CharsetMIBEnumValueSequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_unsigned_short), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    IANA_Charsets_Registry_CharsetMIBEnumValue *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += ilu_SizeOfShortCardinal(_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Free (IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a IANA_Charsets_Registry_CharsetMIBEnumValueSequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_unsigned_short)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_unsigned_short)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_unsigned_short))) */ ) {
    //ilu_DebugPrintf("OK IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Free (IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

IANA_Charsets_Registry_CharsetMIBEnumValueSequence *CORBA_sequence_IANA_Charsets_Registry_CharsetMIBEnumValueSequence_allocbuf (CORBA_unsigned_long _count)
{
  IANA_Charsets_Registry_CharsetMIBEnumValueSequence *_p;
  CORBA_unsigned_long _size = sizeof(IANA_Charsets_Registry_CharsetMIBEnumValueSequence) * _count;

  if ((_p = (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

IANA_Charsets_Registry_CharsetMIBEnumValueSequence* IANA_Charsets_Registry_CharsetMIBEnumValueSequence__alloc ()
{
  return ((IANA_Charsets_Registry_CharsetMIBEnumValueSequence*) CORBA_sequence_IANA_Charsets_Registry_CharsetMIBEnumValueSequence_allocbuf(1));
}

void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Every (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, void (*f)(IANA_Charsets_Registry_CharsetMIBEnumValue *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue), (void *) data);
}

void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Append (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, IANA_Charsets_Registry_CharsetMIBEnumValue item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue), err);
}

void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Push (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, IANA_Charsets_Registry_CharsetMIBEnumValue item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue));
}

void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Pop (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, IANA_Charsets_Registry_CharsetMIBEnumValue *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue));
}

CORBA_unsigned_long IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Length (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

IANA_Charsets_Registry_CharsetMIBEnumValue * IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Nth (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

IANA_Charsets_Registry_CharsetMIBEnumValueSequence * IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Create (CORBA_unsigned_long sz, IANA_Charsets_Registry_CharsetMIBEnumValue *p)
{
  IANA_Charsets_Registry_CharsetMIBEnumValueSequence *s;
  s = (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *) ilu_malloc(sizeof(IANA_Charsets_Registry_CharsetMIBEnumValueSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(IANA_Charsets_Registry_CharsetMIBEnumValueSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((IANA_Charsets_Registry_CharsetMIBEnumValue *) ilu_malloc(sz * sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Init (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *s, CORBA_unsigned_long sz, IANA_Charsets_Registry_CharsetMIBEnumValue *p)
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
    s->_buffer = (IANA_Charsets_Registry_CharsetMIBEnumValue *) ilu_malloc (sz * sizeof (IANA_Charsets_Registry_CharsetMIBEnumValue));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(IANA_Charsets_Registry_CharsetMIBEnumValue)); }}
  else
    s->_buffer = p;
  return;
}

void _IANA_Charsets_Registry__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("IANA-Charsets-Registry", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns.kernelType = ilu_RegisterOptionalType("OptionalCharsetMIBEnumValue", "IANA-Charsets-Registry", "NG", "ilut:mN4YT+tl0wo8gRTACMIzqX4uW6o",
    "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns.kernelType = ilu_RegisterSequenceType("CharsetMIBEnumValueSequence", "IANA-Charsets-Registry", "NG", "ilut:garJ50fEH7VuQSw70iswIWle7xi",
    "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("CharsetMIBEnumValue", "IANA-Charsets-Registry", "NG", "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y",
    "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns.inputFn = (ILU_C_InputFn) _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Input;
  _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns.outFn = (ILU_C_OutputFn) _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Output;
  _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns.sizeFn = (ILU_C_SizeFn) _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__SizeOf;
  _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns.freeFn = (ILU_C_FreeFn) IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Free;
  _ILU_C_RegisterIoFns (&_IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns);

  _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns.inputFn = (ILU_C_InputFn) _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Input;
  _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns.outFn = (ILU_C_OutputFn) _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Output;
  _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns.sizeFn = (ILU_C_SizeFn) _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__SizeOf;
  _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns.freeFn = (ILU_C_FreeFn) IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Free;
  _ILU_C_RegisterIoFns (&_IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

