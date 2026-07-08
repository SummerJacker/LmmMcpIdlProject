/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:25 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test2/Batcher.isl" of Sat Aug 02 18:52:05 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test2/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Batcher.h"

ilu_Class _Batcher_T__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Batcher_T__IoFns = { ilu_object_tk, "ilut:dudeNTx18p2OwJ4eLGicYF-M1ZP", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Batcher_TimeSeq__IoFns = { ilu_sequence_tk, "ilut:ooHIiHNDV73Yyj1ZFJ9lg54VdCh", { sizeof(Batcher_TimeSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Batcher_TimeRec__IoFns = { ilu_record_tk, "ilut:nOz-YjsFDUIE-xV2KZetZ8cyHZz", { sizeof(Batcher_TimeRec) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class Batcher_T__MakeClass(
  void (*Batcher_T_Send__Impl)
     (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status),
  Batcher_TimeSeq* (*Batcher_T_Sync__Impl)
     (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Batcher_T__ILUType;
  method_block = ilu_malloc(2 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Batcher_T_Send__Impl;
  method_block[1] = (_ILU_C_Method) Batcher_T_Sync__Impl;
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
void Batcher_T_Send (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(Batcher_T, Batcher_Time, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(Batcher_T, Batcher_Time, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Batcher_T__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, s, _status);
}

Batcher_TimeSeq* Batcher_T_Sync (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status)
{
  Batcher_TimeSeq* (*_f)(Batcher_T, Batcher_Time, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Batcher_TimeSeq* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Batcher_TimeSeq* (*)(Batcher_T, Batcher_Time, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Batcher_T__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, s, _status));
}

void Batcher_T__SetUserData (Batcher_T self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Batcher_T__GetUserData (Batcher_T self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Batcher_T__Free (Batcher_T* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Batcher_T */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Batcher_T *CORBA_sequence_Batcher_T_allocbuf (CORBA_unsigned_long _count)
{
  Batcher_T *_p;
  CORBA_unsigned_long _size = sizeof(Batcher_T) * _count;

  if ((_p = (Batcher_T *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Batcher_TimeSeq* _Batcher_TimeSeq__Input (ilu_Call _call, Batcher_TimeSeq* _ref, ilu_Error *_err)
{
  Batcher_TimeSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Batcher_TimeRec _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Batcher_TimeSeq*) ilu_MallocE(sizeof (Batcher_TimeSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Batcher_TimeSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Batcher_TimeSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Batcher_TimeRec), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Batcher_TimeRec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Batcher_TimeRec__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Batcher_TimeSeq_Append (_val, &_tmp, _err);
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

void _Batcher_TimeSeq__Output (ilu_Call _call, Batcher_TimeSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Batcher_TimeSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Batcher_TimeRec), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Batcher_TimeRec), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Batcher_TimeRec *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Batcher_TimeRec__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Batcher_TimeSeq__SizeOf (ilu_Call _call, Batcher_TimeSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Batcher_TimeSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Batcher_TimeRec), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Batcher_TimeRec), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Batcher_TimeRec *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Batcher_TimeRec__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Batcher_TimeSeq__Free (Batcher_TimeSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Batcher_TimeSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Batcher_TimeRec)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Batcher_TimeRec)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Batcher_TimeRec))) */ ) {
    //ilu_DebugPrintf("OK Batcher_TimeSeq__Free (Batcher_TimeSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Batcher_TimeSeq *CORBA_sequence_Batcher_TimeSeq_allocbuf (CORBA_unsigned_long _count)
{
  Batcher_TimeSeq *_p;
  CORBA_unsigned_long _size = sizeof(Batcher_TimeSeq) * _count;

  if ((_p = (Batcher_TimeSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Batcher_TimeSeq* Batcher_TimeSeq__alloc ()
{
  return ((Batcher_TimeSeq*) CORBA_sequence_Batcher_TimeSeq_allocbuf(1));
}

Batcher_TimeRec* _Batcher_TimeRec__Input (ilu_Call _call, Batcher_TimeRec* _ref, ilu_Error *_err)
{
  Batcher_TimeRec* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Batcher_TimeRec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Batcher_TimeRec__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Batcher_TimeRec*) ilu_MallocE (sizeof (Batcher_TimeRec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Batcher_TimeRec));
    } else {
      _val = (Batcher_TimeRec*) _ILU_C_CRCreate (s, sizeof(Batcher_TimeRec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Batcher_TimeRec), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputLongCardinal (_call, &_val->s, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputLongCardinal (_call, &_val->r, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Batcher_TimeRec__Output (ilu_Call _call, Batcher_TimeRec* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Batcher_TimeRec__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Batcher_TimeRec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Batcher_TimeRec), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputLongCardinal(_call, (_val->s), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputLongCardinal(_call, (_val->r), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Batcher_TimeRec__SizeOf (ilu_Call _call, Batcher_TimeRec* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Batcher_TimeRec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Batcher_TimeRec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Batcher_TimeRec), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfLongCardinal(_call, _val->s, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfLongCardinal(_call, _val->r, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Batcher_TimeRec *CORBA_sequence_Batcher_TimeRec_allocbuf (CORBA_unsigned_long _count)
{
  Batcher_TimeRec *_p;
  CORBA_unsigned_long _size = sizeof(Batcher_TimeRec) * _count;

  if ((_p = (Batcher_TimeRec *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Batcher_TimeRec* Batcher_TimeRec__alloc ()
{
  return ((Batcher_TimeRec*) CORBA_sequence_Batcher_TimeRec_allocbuf(1));
}

void Batcher_TimeSeq_Every (Batcher_TimeSeq *h, void (*f)(Batcher_TimeRec*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Batcher_TimeRec), (void *) data);
}

void Batcher_TimeSeq_Append (Batcher_TimeSeq *h, Batcher_TimeRec* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Batcher_TimeRec), err);
}

void Batcher_TimeSeq_Push (Batcher_TimeSeq *h, Batcher_TimeRec* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Batcher_TimeRec));
}

void Batcher_TimeSeq_Pop (Batcher_TimeSeq *h, Batcher_TimeRec* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Batcher_TimeRec));
}

CORBA_unsigned_long Batcher_TimeSeq_Length (Batcher_TimeSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Batcher_TimeRec * Batcher_TimeSeq_Nth (Batcher_TimeSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Batcher_TimeSeq * Batcher_TimeSeq_Create (CORBA_unsigned_long sz, Batcher_TimeRec* p)
{
  Batcher_TimeSeq *s;
  s = (Batcher_TimeSeq *) ilu_malloc(sizeof(Batcher_TimeSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Batcher_TimeSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Batcher_TimeRec *) ilu_malloc(sz * sizeof(Batcher_TimeRec))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Batcher_TimeRec));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Batcher_TimeSeq_Init (Batcher_TimeSeq *s, CORBA_unsigned_long sz, Batcher_TimeRec* p)
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
    s->_buffer = (Batcher_TimeRec *) ilu_malloc (sz * sizeof (Batcher_TimeRec));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Batcher_TimeRec)); }}
  else
    s->_buffer = p;
  return;
}

void _Batcher__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Batcher", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("Batcher.T",	/*name*/
	NULL,	/*no brand*/
	"ilut:dudeNTx18p2OwJ4eLGicYF-M1ZP",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	2,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Batcher_T__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"Send",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "s", ilu_FALSE, ilu_In, "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"Sync",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:ooHIiHNDV73Yyj1ZFJ9lg54VdCh",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "s", ilu_FALSE, ilu_In, "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Batcher_T__IoFns.kernelType = ilu_RegisterObjectType("T", "Batcher", ILU_NIL, "ilut:dudeNTx18p2OwJ4eLGicYF-M1ZP",
    _Batcher_T__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Batcher_TimeSeq__IoFns.kernelType = ilu_RegisterSequenceType("TimeSeq", "Batcher", ILU_NIL, "ilut:ooHIiHNDV73Yyj1ZFJ9lg54VdCh",
    "ilut:nOz-YjsFDUIE-xV2KZetZ8cyHZz",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Batcher_TimeRec__IoFns.kernelType = type = ilu_RegisterRecordType("TimeRec", "Batcher", ILU_NIL, "ilut:nOz-YjsFDUIE-xV2KZetZ8cyHZz",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "s", /* field name */
      "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "r", /* field name */
      "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("Time", "Batcher", ILU_NIL, "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy",
    "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Batcher_T__IoFns.properties.object_class = _Batcher_T__ILUType;
  _ILU_C_RegisterIoFns (&_Batcher_T__IoFns);

  _Batcher_TimeSeq__IoFns.inputFn = (ILU_C_InputFn) _Batcher_TimeSeq__Input;
  _Batcher_TimeSeq__IoFns.outFn = (ILU_C_OutputFn) _Batcher_TimeSeq__Output;
  _Batcher_TimeSeq__IoFns.sizeFn = (ILU_C_SizeFn) _Batcher_TimeSeq__SizeOf;
  _Batcher_TimeSeq__IoFns.freeFn = (ILU_C_FreeFn) Batcher_TimeSeq__Free;
  _ILU_C_RegisterIoFns (&_Batcher_TimeSeq__IoFns);

  _Batcher_TimeRec__IoFns.inputFn = (ILU_C_InputFn) _Batcher_TimeRec__Input;
  _Batcher_TimeRec__IoFns.outFn = (ILU_C_OutputFn) _Batcher_TimeRec__Output;
  _Batcher_TimeRec__IoFns.sizeFn = (ILU_C_SizeFn) _Batcher_TimeRec__SizeOf;
  _Batcher_TimeRec__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Batcher_TimeRec__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

