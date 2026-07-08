/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:24 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test2/Fibber.isl" of Sat Aug 02 18:52:05 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test2/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Fibber.h"

ilu_Class _Fibber_T__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Fibber_T__IoFns = { ilu_object_tk, "ilut:pvLWtgjZbuCSpVcgly820mLhIcz", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Fibber_StringSeq__IoFns = { ilu_sequence_tk, "ilut:pEKUWbIiHyemJ03LsL2RwH+at2L", { sizeof(Fibber_StringSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Fibber_String__IoFns = { ilu_sequence_tk, "ilut:hmELeCf+ULgOCdSpDDIC0sRola-", { sizeof(Fibber_String) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class Fibber_T__MakeClass(
  CORBA_unsigned_long (*Fibber_T_Calc__Impl)
     (Fibber_T _handle, CORBA_unsigned_long d, CORBA_unsigned_long n, Fibber_T ask, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Fibber_T__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Fibber_T_Calc__Impl;
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
CORBA_unsigned_long Fibber_T_Calc (Fibber_T _handle, CORBA_unsigned_long d, CORBA_unsigned_long n, Fibber_T ask, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long (*_f)(Fibber_T, CORBA_unsigned_long, CORBA_unsigned_long, Fibber_T, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_unsigned_long _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_unsigned_long (*)(Fibber_T, CORBA_unsigned_long, CORBA_unsigned_long, Fibber_T, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Fibber_T__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, d, n, ask, _status));
}

void Fibber_T__SetUserData (Fibber_T self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Fibber_T__GetUserData (Fibber_T self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _Fibber__Exception_Failed = ILU_NIL;
#include <stdarg.h>

void Fibber__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_Fibber_Failed) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Fibber_StringSeq));
    *(Fibber_StringSeq*)stat->ptr = *va_arg (ap, Fibber_StringSeq*);
    stat->freeRoutine = (void (*) (void *)) Fibber_StringSeq__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to Fibber__BindExceptionValue");
  va_end (ap);
}

void Fibber_T__Free (Fibber_T* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Fibber_T */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Fibber_T *CORBA_sequence_Fibber_T_allocbuf (CORBA_unsigned_long _count)
{
  Fibber_T *_p;
  CORBA_unsigned_long _size = sizeof(Fibber_T) * _count;

  if ((_p = (Fibber_T *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Fibber_StringSeq* _Fibber_StringSeq__Input (ilu_Call _call, Fibber_StringSeq* _ref, ilu_Error *_err)
{
  Fibber_StringSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Fibber_String _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Fibber_StringSeq*) ilu_MallocE(sizeof (Fibber_StringSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Fibber_StringSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Fibber_StringSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Fibber_String), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Fibber_String), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Fibber_String__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Fibber_StringSeq_Append (_val, _tmp, _err);
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

void _Fibber_StringSeq__Output (ilu_Call _call, Fibber_StringSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Fibber_StringSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Fibber_String), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Fibber_String), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Fibber_String *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Fibber_String__Output(_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Fibber_StringSeq__SizeOf (ilu_Call _call, Fibber_StringSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Fibber_StringSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Fibber_String), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Fibber_String), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Fibber_String *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Fibber_String__SizeOf (_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Fibber_StringSeq__Free (Fibber_StringSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Fibber_StringSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Fibber_String)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Fibber_String)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Fibber_String))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          Fibber_String__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK Fibber_StringSeq__Free (Fibber_StringSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Fibber_StringSeq *CORBA_sequence_Fibber_StringSeq_allocbuf (CORBA_unsigned_long _count)
{
  Fibber_StringSeq *_p;
  CORBA_unsigned_long _size = sizeof(Fibber_StringSeq) * _count;

  if ((_p = (Fibber_StringSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Fibber_StringSeq* Fibber_StringSeq__alloc ()
{
  return ((Fibber_StringSeq*) CORBA_sequence_Fibber_StringSeq_allocbuf(1));
}

Fibber_String* _Fibber_String__Input (ilu_Call _call, Fibber_String* _ref, ilu_Error *_err)
{
  Fibber_String* _val = _ref;

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

void _Fibber_String__Output (ilu_Call _call, Fibber_String _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
 marshalError:
  return;
}

ilu_cardinal _Fibber_String__SizeOf (ilu_Call _call, Fibber_String _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
  return size;
}

void Fibber_String__Free (Fibber_String* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Fibber_String */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  if (*_val != ILU_NIL)
    ilu_free(*_val);
}

Fibber_String *CORBA_sequence_Fibber_String_allocbuf (CORBA_unsigned_long _count)
{
  Fibber_String *_p;
  CORBA_unsigned_long _size = sizeof(Fibber_String) * _count;

  if ((_p = (Fibber_String *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Fibber_String* Fibber_String__alloc ()
{
  return ((Fibber_String*) CORBA_sequence_Fibber_String_allocbuf(1));
}

void Fibber_StringSeq_Every (Fibber_StringSeq *h, void (*f)(Fibber_String *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Fibber_String), (void *) data);
}

void Fibber_StringSeq_Append (Fibber_StringSeq *h, Fibber_String item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Fibber_String), err);
}

void Fibber_StringSeq_Push (Fibber_StringSeq *h, Fibber_String item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Fibber_String));
}

void Fibber_StringSeq_Pop (Fibber_StringSeq *h, Fibber_String *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Fibber_String));
}

CORBA_unsigned_long Fibber_StringSeq_Length (Fibber_StringSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Fibber_String * Fibber_StringSeq_Nth (Fibber_StringSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Fibber_StringSeq * Fibber_StringSeq_Create (CORBA_unsigned_long sz, Fibber_String *p)
{
  Fibber_StringSeq *s;
  s = (Fibber_StringSeq *) ilu_malloc(sizeof(Fibber_StringSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Fibber_StringSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Fibber_String *) ilu_malloc(sz * sizeof(Fibber_String))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Fibber_String));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Fibber_StringSeq_Init (Fibber_StringSeq *s, CORBA_unsigned_long sz, Fibber_String *p)
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
    s->_buffer = (Fibber_String *) ilu_malloc (sz * sizeof (Fibber_String));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Fibber_String)); }}
  else
    s->_buffer = p;
  return;
}

void Fibber_String_Every (Fibber_String *h, void (*f)(CORBA_char *, void *), void * data)
{
  CORBA_char *p;
  for (p = *h;  *p != 0;  p++) (*f)(p, data);
}

void Fibber_String_Append (Fibber_String *h, CORBA_char item, ilu_Error* err)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 1);
}

void Fibber_String_Push (Fibber_String *h, CORBA_char item)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 0);
}

void Fibber_String_Pop (Fibber_String *h, CORBA_char *item)
{
  _ILU_C_PopString (h, item);
}

CORBA_unsigned_long Fibber_String_Length (Fibber_String *h)
{
  if (h == ILU_NIL || *h == ILU_NIL) return 0;
  return (strlen((char *)(*h)));
}

CORBA_char * Fibber_String_Nth (Fibber_String *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || *h == ILU_NIL) return ILU_NIL;
  if (n >= strlen((char*)(*h)))
    return ILU_NIL;
else return &((*h)[n]);
}

Fibber_String Fibber_String_Create (CORBA_unsigned_long sz, CORBA_char *p)
{
  Fibber_String s;

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

void Fibber_String_Init (Fibber_String *s, CORBA_unsigned_long sz)
{
  return;
}

void _Fibber__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Fibber", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _Fibber__Exception_Failed = ilu_DefineException("Fibber", "Failed", "ilut:pEKUWbIiHyemJ03LsL2RwH+at2L", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("Fibber.T",	/*name*/
	NULL,	/*no brand*/
	"ilut:pvLWtgjZbuCSpVcgly820mLhIcz",	/*uid*/
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
    _Fibber_T__ILUType = cl;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Fibber_Failed;
    m = ilu_DefineMethod(cl, 0,
	"Calc",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "d", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "n", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "ask", ilu_FALSE, ilu_In, "ilut:pvLWtgjZbuCSpVcgly820mLhIcz", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Fibber_T__IoFns.kernelType = ilu_RegisterObjectType("T", "Fibber", ILU_NIL, "ilut:pvLWtgjZbuCSpVcgly820mLhIcz",
    _Fibber_T__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Fibber_StringSeq__IoFns.kernelType = ilu_RegisterSequenceType("StringSeq", "Fibber", ILU_NIL, "ilut:pEKUWbIiHyemJ03LsL2RwH+at2L",
    "ilut:hmELeCf+ULgOCdSpDDIC0sRola-",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Fibber_String__IoFns.kernelType = ilu_RegisterSequenceType("String", "Fibber", ILU_NIL, "ilut:hmELeCf+ULgOCdSpDDIC0sRola-",
    "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Fibber_T__IoFns.properties.object_class = _Fibber_T__ILUType;
  _ILU_C_RegisterIoFns (&_Fibber_T__IoFns);

  _Fibber_StringSeq__IoFns.inputFn = (ILU_C_InputFn) _Fibber_StringSeq__Input;
  _Fibber_StringSeq__IoFns.outFn = (ILU_C_OutputFn) _Fibber_StringSeq__Output;
  _Fibber_StringSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Fibber_StringSeq__SizeOf;
  _Fibber_StringSeq__IoFns.freeFn = (ILU_C_FreeFn) Fibber_StringSeq__Free;
  _ILU_C_RegisterIoFns (&_Fibber_StringSeq__IoFns);

  _Fibber_String__IoFns.inputFn = (ILU_C_InputFn) _Fibber_String__Input;
  _Fibber_String__IoFns.outFn = (ILU_C_OutputFn) _Fibber_String__Output;
  _Fibber_String__IoFns.sizeFn = (ILU_C_SizeFn) _Fibber_String__SizeOf;
  _Fibber_String__IoFns.freeFn = (ILU_C_FreeFn) Fibber_String__Free;
  _ILU_C_RegisterIoFns (&_Fibber_String__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

