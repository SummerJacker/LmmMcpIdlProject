/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:50 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/timeit/timeit.idl" of Thu Aug 07 15:38:55 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "timeit.h"

ilu_Class _timeit_p__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _timeit_p__IoFns = { ilu_object_tk, "IDL:com.xerox.parc.ilu.examples/timeit/p:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _timeit_recseq__IoFns = { ilu_sequence_tk, "ilut:mY6RjehMlqQw6KO+IX9n2Giy605", { sizeof(timeit_recseq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _timeit_rec__IoFns = { ilu_record_tk, "IDL:timeit/rec:1.0", { sizeof(timeit_rec) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _timeit_char32__IoFns = { ilu_array_tk, "ilut:lQpiIGc717YqJ2wssgebHpBi7hl", { sizeof(timeit_char32) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _timeit_img20x20x20__IoFns = { ilu_array_tk, "ilut:egbCnhwrbPQkRxYZLqHnqfZL2eM", { sizeof(timeit_img20x20x20) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _timeit_pageSeq__IoFns = { ilu_sequence_tk, "ilut:oRFTOExB4DAA7MCo4LFXJ91nbWQ", { sizeof(timeit_pageSeq) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _timeit_pageimg__IoFns = { ilu_sequence_tk, "ilut:dZHfzRcLaoFXbdkWBy8yhN6DiQO", { sizeof(timeit_pageimg) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class timeit_p__MakeClass(
  CORBA_unsigned_long (*timeit_p_ping1__Impl)
     (timeit_p _handle, CORBA_unsigned_long p1, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*timeit_p_ping2__Impl)
     (timeit_p _handle, CORBA_double p2, ILU_C_ENVIRONMENT *_status),
  ilu_CString (*timeit_p_ping3__Impl)
     (timeit_p _handle, ilu_CString p3, ILU_C_ENVIRONMENT *_status),
  timeit_pageSeq* (*timeit_p_doctest__Impl)
     (timeit_p _handle, ilu_CString name, CORBA_unsigned_long count, CORBA_unsigned_long pagesize, ILU_C_ENVIRONMENT *_status),
  void (*timeit_p_imgtest__Impl)
     (timeit_p _handle, timeit_img20x20x20 val, ILU_C_ENVIRONMENT *_status),
  void (*timeit_p_rectest__Impl)
     (timeit_p _handle, timeit_recseq* val, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _timeit_p__ILUType;
  method_block = ilu_malloc(6 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) timeit_p_ping1__Impl;
  method_block[1] = (_ILU_C_Method) timeit_p_ping2__Impl;
  method_block[2] = (_ILU_C_Method) timeit_p_ping3__Impl;
  method_block[3] = (_ILU_C_Method) timeit_p_doctest__Impl;
  method_block[4] = (_ILU_C_Method) timeit_p_imgtest__Impl;
  method_block[5] = (_ILU_C_Method) timeit_p_rectest__Impl;

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
CORBA_unsigned_long timeit_p_ping1 (timeit_p _handle, CORBA_unsigned_long p1, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long (*_f)(timeit_p, CORBA_unsigned_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_unsigned_long _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_unsigned_long (*)(timeit_p, CORBA_unsigned_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _timeit_p__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, p1, _status));
}

CORBA_double timeit_p_ping2 (timeit_p _handle, CORBA_double p2, ILU_C_ENVIRONMENT *_status)
{
  CORBA_double (*_f)(timeit_p, CORBA_double, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_double _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_double (*)(timeit_p, CORBA_double, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _timeit_p__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, p2, _status));
}

ilu_CString timeit_p_ping3 (timeit_p _handle, ilu_CString p3, ILU_C_ENVIRONMENT *_status)
{
  ilu_CString (*_f)(timeit_p, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ilu_CString _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (ilu_CString (*)(timeit_p, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _timeit_p__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, p3, _status));
}

timeit_pageSeq* timeit_p_doctest (timeit_p _handle, ilu_CString name, CORBA_unsigned_long count, CORBA_unsigned_long pagesize, ILU_C_ENVIRONMENT *_status)
{
  timeit_pageSeq* (*_f)(timeit_p, ilu_CString, CORBA_unsigned_long, CORBA_unsigned_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    timeit_pageSeq* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (timeit_pageSeq* (*)(timeit_p, ilu_CString, CORBA_unsigned_long, CORBA_unsigned_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _timeit_p__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, name, count, pagesize, _status));
}

void timeit_p_imgtest (timeit_p _handle, timeit_img20x20x20 val, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(timeit_p, timeit_img20x20x20, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(timeit_p, timeit_img20x20x20, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _timeit_p__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, val, _status);
}

void timeit_p_rectest (timeit_p _handle, timeit_recseq* val, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(timeit_p, timeit_recseq*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(timeit_p, timeit_recseq*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _timeit_p__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, val, _status);
}

void timeit_p__SetUserData (timeit_p self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *timeit_p__GetUserData (timeit_p self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void timeit_p__Free (timeit_p* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a timeit_p */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

timeit_p *CORBA_sequence_timeit_p_allocbuf (CORBA_unsigned_long _count)
{
  timeit_p *_p;
  CORBA_unsigned_long _size = sizeof(timeit_p) * _count;

  if ((_p = (timeit_p *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

timeit_recseq* _timeit_recseq__Input (ilu_Call _call, timeit_recseq* _ref, ilu_Error *_err)
{
  timeit_recseq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  timeit_rec _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (timeit_recseq*) ilu_MallocE(sizeof (timeit_recseq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  timeit_recseq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(timeit_recseq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(timeit_rec), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(timeit_rec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _timeit_rec__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      timeit_recseq_Append (_val, &_tmp, _err);
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

void _timeit_recseq__Output (ilu_Call _call, timeit_recseq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(timeit_recseq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(timeit_rec), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(timeit_rec), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    timeit_rec *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _timeit_rec__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _timeit_recseq__SizeOf (ilu_Call _call, timeit_recseq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(timeit_recseq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(timeit_rec), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(timeit_rec), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    timeit_rec *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _timeit_rec__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void timeit_recseq__Free (timeit_recseq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a timeit_recseq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(timeit_rec)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(timeit_rec)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(timeit_rec))) */ ) {
    //ilu_DebugPrintf("OK timeit_recseq__Free (timeit_recseq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

timeit_recseq *CORBA_sequence_timeit_recseq_allocbuf (CORBA_unsigned_long _count)
{
  timeit_recseq *_p;
  CORBA_unsigned_long _size = sizeof(timeit_recseq) * _count;

  if ((_p = (timeit_recseq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

timeit_recseq* timeit_recseq__alloc ()
{
  return ((timeit_recseq*) CORBA_sequence_timeit_recseq_allocbuf(1));
}

timeit_rec* _timeit_rec__Input (ilu_Call _call, timeit_rec* _ref, ilu_Error *_err)
{
  timeit_rec* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_timeit_rec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_timeit_rec__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (timeit_rec*) ilu_MallocE (sizeof (timeit_rec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(timeit_rec));
    } else {
      _val = (timeit_rec*) _ILU_C_CRCreate (s, sizeof(timeit_rec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(timeit_rec), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _timeit_char32__Input (_call, _val->name,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->dirty, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &_val->create_time, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _timeit_rec__Output (ilu_Call _call, timeit_rec* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_timeit_rec__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_timeit_rec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(timeit_rec), _err);
    if (ILU_ERRNOK(*_err)) return;
  _timeit_char32__Output(_call, (_val->name), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->dirty), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputCardinal (_call, (_val->create_time), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _timeit_rec__SizeOf (ilu_Call _call, timeit_rec* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_timeit_rec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_timeit_rec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(timeit_rec), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _timeit_char32__SizeOf (_call, _val->name, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->dirty, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfCardinal(_call, _val->create_time, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

timeit_rec *CORBA_sequence_timeit_rec_allocbuf (CORBA_unsigned_long _count)
{
  timeit_rec *_p;
  CORBA_unsigned_long _size = sizeof(timeit_rec) * _count;

  if ((_p = (timeit_rec *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

timeit_rec* timeit_rec__alloc ()
{
  return ((timeit_rec*) CORBA_sequence_timeit_rec_allocbuf(1));
}

timeit_char32_slice * _timeit_char32__Input (ilu_Call _call, timeit_char32 _ref, ilu_Error *_err)
{
  timeit_char32_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (timeit_char32_slice *) ilu_MallocE(sizeof(timeit_char32), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
    ilu_string _tmp = _val;
    ilu_InputStringVec (_call, &_tmp, 32, _err);
  }
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _timeit_char32__Output (ilu_Call _call, timeit_char32 _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputStringVec (_call, (_val), 32, _err);
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _timeit_char32__SizeOf (ilu_Call _call, timeit_char32 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size += ilu_SizeOfStringVec (_call, (_val), 32, _err);
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

timeit_char32 *CORBA_sequence_timeit_char32_allocbuf (CORBA_unsigned_long _count)
{
  timeit_char32 *_p;
  CORBA_unsigned_long _size = sizeof(timeit_char32) * _count;

  if ((_p = (timeit_char32 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

timeit_char32_slice * timeit_char32__alloc ()
{
  return ((timeit_char32_slice *) CORBA_sequence_timeit_char32_allocbuf(1));
}

timeit_img20x20x20_slice * _timeit_img20x20x20__Input (ilu_Call _call, timeit_img20x20x20 _ref, ilu_Error *_err)
{
  timeit_img20x20x20_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (timeit_img20x20x20_slice *) ilu_MallocE(sizeof(timeit_img20x20x20), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_InputArray (_call, ILU_C_KERNEL_TYPE(timeit_img20x20x20), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CORBA_double), 8000, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val, sizeof(timeit_img20x20x20), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 20;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 20;  _i1 += 1)
        {
          register int _i2;
          for (_i2 = 0;  _i2 < 20;  _i2 += 1)
        ilu_InputReal (_call, &_val[_i0][_i1][_i2], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
      }
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _timeit_img20x20x20__Output (ilu_Call _call, timeit_img20x20x20 _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_bytes* nec;
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputArray (_call, 8000, ILU_C_KERNEL_TYPE(timeit_img20x20x20), _err); if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_double), 8000, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val, sizeof(timeit_img20x20x20), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 20;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 20;  _i1 += 1)
        {
          register int _i2;
          for (_i2 = 0;  _i2 < 20;  _i2 += 1)
            ilu_OutputReal(_call, _val[_i0][_i1][_i2], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
      }
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _timeit_img20x20x20__SizeOf (ilu_Call _call, timeit_img20x20x20 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfArray (_call, 8000, ILU_C_KERNEL_TYPE(timeit_img20x20x20), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_double), 8000, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque(_call, (ilu_bytes)_val, sizeof(timeit_img20x20x20), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 20;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 20;  _i1 += 1)
        {
          register int _i2;
          for (_i2 = 0;  _i2 < 20;  _i2 += 1)
            size += ilu_SizeOfReal(_call, _val[_i0][_i1][_i2], _err);
        }
      }
    }
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

timeit_img20x20x20 *CORBA_sequence_timeit_img20x20x20_allocbuf (CORBA_unsigned_long _count)
{
  timeit_img20x20x20 *_p;
  CORBA_unsigned_long _size = sizeof(timeit_img20x20x20) * _count;

  if ((_p = (timeit_img20x20x20 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

timeit_img20x20x20_slice * timeit_img20x20x20__alloc ()
{
  return ((timeit_img20x20x20_slice *) CORBA_sequence_timeit_img20x20x20_allocbuf(1));
}

timeit_pageSeq* _timeit_pageSeq__Input (ilu_Call _call, timeit_pageSeq* _ref, ilu_Error *_err)
{
  timeit_pageSeq* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  timeit_pageimg _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (timeit_pageSeq*) ilu_MallocE(sizeof (timeit_pageSeq), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  timeit_pageSeq_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(timeit_pageSeq), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(timeit_pageimg), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(timeit_pageimg), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _timeit_pageimg__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      timeit_pageSeq_Append (_val, &_tmp, _err);
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

void _timeit_pageSeq__Output (ilu_Call _call, timeit_pageSeq* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(timeit_pageSeq), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(timeit_pageimg), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(timeit_pageimg), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    timeit_pageimg *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _timeit_pageimg__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _timeit_pageSeq__SizeOf (ilu_Call _call, timeit_pageSeq* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(timeit_pageSeq), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(timeit_pageimg), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(timeit_pageimg), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    timeit_pageimg *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _timeit_pageimg__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void timeit_pageSeq__Free (timeit_pageSeq* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a timeit_pageSeq */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(timeit_pageimg)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(timeit_pageimg)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(timeit_pageimg))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          timeit_pageimg__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK timeit_pageSeq__Free (timeit_pageSeq* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

timeit_pageSeq *CORBA_sequence_timeit_pageSeq_allocbuf (CORBA_unsigned_long _count)
{
  timeit_pageSeq *_p;
  CORBA_unsigned_long _size = sizeof(timeit_pageSeq) * _count;

  if ((_p = (timeit_pageSeq *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

timeit_pageSeq* timeit_pageSeq__alloc ()
{
  return ((timeit_pageSeq*) CORBA_sequence_timeit_pageSeq_allocbuf(1));
}

timeit_pageimg* _timeit_pageimg__Input (ilu_Call _call, timeit_pageimg* _ref, ilu_Error *_err)
{
  timeit_pageimg* _val = _ref;

  ilu_cardinal len=0;
  ilu_cardinal limit = 0;
  ilu_bytes b = ILU_NIL;

  if (_ref == ILU_NIL) {
    _val = (timeit_pageimg *) ilu_MallocE(sizeof(timeit_pageimg), _err);
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

void _timeit_pageimg__Output (ilu_Call _call, timeit_pageimg* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputBytes (_call, _val->_buffer, _val->_length, 0, _err);
 marshalError:
  return;
}

ilu_cardinal _timeit_pageimg__SizeOf (ilu_Call _call, timeit_pageimg* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfBytes (_call, _val->_buffer, _val->_length, 0, _err);
  return size;
}

void timeit_pageimg__Free (timeit_pageimg* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a timeit_pageimg */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_octet)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_octet)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_octet))) */ ) {
    //ilu_DebugPrintf("OK timeit_pageimg__Free (timeit_pageimg* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

timeit_pageimg *CORBA_sequence_timeit_pageimg_allocbuf (CORBA_unsigned_long _count)
{
  timeit_pageimg *_p;
  CORBA_unsigned_long _size = sizeof(timeit_pageimg) * _count;

  if ((_p = (timeit_pageimg *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

timeit_pageimg* timeit_pageimg__alloc ()
{
  return ((timeit_pageimg*) CORBA_sequence_timeit_pageimg_allocbuf(1));
}

void timeit_recseq_Every (timeit_recseq *h, void (*f)(timeit_rec*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(timeit_rec), (void *) data);
}

void timeit_recseq_Append (timeit_recseq *h, timeit_rec* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(timeit_rec), err);
}

void timeit_recseq_Push (timeit_recseq *h, timeit_rec* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(timeit_rec));
}

void timeit_recseq_Pop (timeit_recseq *h, timeit_rec* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(timeit_rec));
}

CORBA_unsigned_long timeit_recseq_Length (timeit_recseq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

timeit_rec * timeit_recseq_Nth (timeit_recseq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

timeit_recseq * timeit_recseq_Create (CORBA_unsigned_long sz, timeit_rec* p)
{
  timeit_recseq *s;
  s = (timeit_recseq *) ilu_malloc(sizeof(timeit_recseq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(timeit_recseq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((timeit_rec *) ilu_malloc(sz * sizeof(timeit_rec))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(timeit_rec));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void timeit_recseq_Init (timeit_recseq *s, CORBA_unsigned_long sz, timeit_rec* p)
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
    s->_buffer = (timeit_rec *) ilu_malloc (sz * sizeof (timeit_rec));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(timeit_rec)); }}
  else
    s->_buffer = p;
  return;
}

void timeit_pageSeq_Every (timeit_pageSeq *h, void (*f)(timeit_pageimg*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(timeit_pageimg), (void *) data);
}

void timeit_pageSeq_Append (timeit_pageSeq *h, timeit_pageimg* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(timeit_pageimg), err);
}

void timeit_pageSeq_Push (timeit_pageSeq *h, timeit_pageimg* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(timeit_pageimg));
}

void timeit_pageSeq_Pop (timeit_pageSeq *h, timeit_pageimg* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(timeit_pageimg));
}

CORBA_unsigned_long timeit_pageSeq_Length (timeit_pageSeq *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

timeit_pageimg * timeit_pageSeq_Nth (timeit_pageSeq *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

timeit_pageSeq * timeit_pageSeq_Create (CORBA_unsigned_long sz, timeit_pageimg* p)
{
  timeit_pageSeq *s;
  s = (timeit_pageSeq *) ilu_malloc(sizeof(timeit_pageSeq));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(timeit_pageSeq)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((timeit_pageimg *) ilu_malloc(sz * sizeof(timeit_pageimg))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(timeit_pageimg));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void timeit_pageSeq_Init (timeit_pageSeq *s, CORBA_unsigned_long sz, timeit_pageimg* p)
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
    s->_buffer = (timeit_pageimg *) ilu_malloc (sz * sizeof (timeit_pageimg));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(timeit_pageimg)); }}
  else
    s->_buffer = p;
  return;
}

void timeit_pageimg_Every (timeit_pageimg *h, void (*f)(CORBA_octet *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_octet), (void *) data);
}

void timeit_pageimg_Append (timeit_pageimg *h, CORBA_octet item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet), err);
}

void timeit_pageimg_Push (timeit_pageimg *h, CORBA_octet item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet));
}

void timeit_pageimg_Pop (timeit_pageimg *h, CORBA_octet *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_octet));
}

CORBA_unsigned_long timeit_pageimg_Length (timeit_pageimg *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_octet * timeit_pageimg_Nth (timeit_pageimg *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

timeit_pageimg * timeit_pageimg_Create (CORBA_unsigned_long sz, CORBA_octet *p)
{
  timeit_pageimg *s;
  s = (timeit_pageimg *) ilu_malloc(sizeof(timeit_pageimg));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(timeit_pageimg)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_octet *) ilu_malloc(sz * sizeof(CORBA_octet))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_octet));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void timeit_pageimg_Init (timeit_pageimg *s, CORBA_unsigned_long sz, CORBA_octet *p)
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

void _timeit__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("timeit", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	"IDL:omg.org/CORBA/Object:1.0",
	NULL};
    cl = ilu_DefineObjectType("timeit.p",	/*name*/
	NULL,	/*no brand*/
	"IDL:com.xerox.parc.ilu.examples/timeit/p:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	6,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _timeit_p__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"ping1",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "p1", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"ping2",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "p2", ilu_FALSE, ilu_In, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"ping3",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "p3", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"doctest",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:oRFTOExB4DAA7MCo4LFXJ91nbWQ",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "name", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "count", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "pagesize", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"imgtest",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "val", ilu_FALSE, ilu_In, "ilut:egbCnhwrbPQkRxYZLqHnqfZL2eM", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 5,
	"rectest",	/*name*/
	6,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "val", ilu_FALSE, ilu_In, "ilut:mY6RjehMlqQw6KO+IX9n2Giy605", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _timeit_p__IoFns.kernelType = ilu_RegisterObjectType("p", "timeit", ILU_NIL, "IDL:com.xerox.parc.ilu.examples/timeit/p:1.0",
    _timeit_p__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _timeit_recseq__IoFns.kernelType = ilu_RegisterSequenceType("recseq", "timeit", ILU_NIL, "ilut:mY6RjehMlqQw6KO+IX9n2Giy605",
    "IDL:timeit/rec:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _timeit_rec__IoFns.kernelType = type = ilu_RegisterRecordType("rec", "timeit", ILU_NIL, "IDL:timeit/rec:1.0",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "name", /* field name */
      "ilut:lQpiIGc717YqJ2wssgebHpBi7hl", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "dirty", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "create-time", /* field name */
      "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  { /* array type "timeit_char32" */
    ilu_cardinal _timeit_char32_dims[] = { 32 };
    _timeit_char32__IoFns.kernelType = ilu_RegisterArrayType("char32", "timeit", ILU_NIL, "ilut:lQpiIGc717YqJ2wssgebHpBi7hl",
    "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0", /* base type of array */
    1,		/* number of dimensions */
    _timeit_char32_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  { /* array type "timeit_img20x20x20" */
    ilu_cardinal _timeit_img20x20x20_dims[] = { 20, 20, 20 };
    _timeit_img20x20x20__IoFns.kernelType = ilu_RegisterArrayType("img20x20x20", "timeit", ILU_NIL, "ilut:egbCnhwrbPQkRxYZLqHnqfZL2eM",
    "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", /* base type of array */
    3,		/* number of dimensions */
    _timeit_img20x20x20_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  _timeit_pageSeq__IoFns.kernelType = ilu_RegisterSequenceType("pageSeq", "timeit", ILU_NIL, "ilut:oRFTOExB4DAA7MCo4LFXJ91nbWQ",
    "ilut:dZHfzRcLaoFXbdkWBy8yhN6DiQO",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _timeit_pageimg__IoFns.kernelType = ilu_RegisterSequenceType("pageimg", "timeit", ILU_NIL, "ilut:dZHfzRcLaoFXbdkWBy8yhN6DiQO",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _timeit_p__IoFns.properties.object_class = _timeit_p__ILUType;
  _ILU_C_RegisterIoFns (&_timeit_p__IoFns);

  _timeit_recseq__IoFns.inputFn = (ILU_C_InputFn) _timeit_recseq__Input;
  _timeit_recseq__IoFns.outFn = (ILU_C_OutputFn) _timeit_recseq__Output;
  _timeit_recseq__IoFns.sizeFn = (ILU_C_SizeFn) _timeit_recseq__SizeOf;
  _timeit_recseq__IoFns.freeFn = (ILU_C_FreeFn) timeit_recseq__Free;
  _ILU_C_RegisterIoFns (&_timeit_recseq__IoFns);

  _timeit_rec__IoFns.inputFn = (ILU_C_InputFn) _timeit_rec__Input;
  _timeit_rec__IoFns.outFn = (ILU_C_OutputFn) _timeit_rec__Output;
  _timeit_rec__IoFns.sizeFn = (ILU_C_SizeFn) _timeit_rec__SizeOf;
  _timeit_rec__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_timeit_rec__IoFns);

  _timeit_char32__IoFns.inputFn = (ILU_C_InputFn) _timeit_char32__Input;
  _timeit_char32__IoFns.outFn = (ILU_C_OutputFn) _timeit_char32__Output;
  _timeit_char32__IoFns.sizeFn = (ILU_C_SizeFn) _timeit_char32__SizeOf;
  _timeit_char32__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_timeit_char32__IoFns);

  _timeit_img20x20x20__IoFns.inputFn = (ILU_C_InputFn) _timeit_img20x20x20__Input;
  _timeit_img20x20x20__IoFns.outFn = (ILU_C_OutputFn) _timeit_img20x20x20__Output;
  _timeit_img20x20x20__IoFns.sizeFn = (ILU_C_SizeFn) _timeit_img20x20x20__SizeOf;
  _timeit_img20x20x20__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_timeit_img20x20x20__IoFns);

  _timeit_pageSeq__IoFns.inputFn = (ILU_C_InputFn) _timeit_pageSeq__Input;
  _timeit_pageSeq__IoFns.outFn = (ILU_C_OutputFn) _timeit_pageSeq__Output;
  _timeit_pageSeq__IoFns.sizeFn = (ILU_C_SizeFn) _timeit_pageSeq__SizeOf;
  _timeit_pageSeq__IoFns.freeFn = (ILU_C_FreeFn) timeit_pageSeq__Free;
  _ILU_C_RegisterIoFns (&_timeit_pageSeq__IoFns);

  _timeit_pageimg__IoFns.inputFn = (ILU_C_InputFn) _timeit_pageimg__Input;
  _timeit_pageimg__IoFns.outFn = (ILU_C_OutputFn) _timeit_pageimg__Output;
  _timeit_pageimg__IoFns.sizeFn = (ILU_C_SizeFn) _timeit_pageimg__SizeOf;
  _timeit_pageimg__IoFns.freeFn = (ILU_C_FreeFn) timeit_pageimg__Free;
  _ILU_C_RegisterIoFns (&_timeit_pageimg__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

