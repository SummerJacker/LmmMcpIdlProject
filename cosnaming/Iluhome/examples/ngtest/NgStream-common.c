/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgStream.isl" of Fri Aug 01 13:29:38 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "NgStream.h"

ilu_Class _NgStream_DataSink__ILUType = NULL;
ilu_Class _NgStream_DataSource__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _NgStream_DataSink__IoFns = { ilu_object_tk, "ilut:jXwwDJ1F22IQDKuO1TimeEIW1wl", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgStream_OptionalDataSource__IoFns = { ilu_optional_tk, "ilut:daEgus3HovCDeXPgQKNk2DkCxEu", { sizeof(NgStream_OptionalDataSource) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgStream_DataSource__IoFns = { ilu_object_tk, "ilut:oQ2vdKmpFhHFEwTWaLNHurAvCN7", { 0 }, 0, 0, 0, 0, 0 };


ILU_C_Class NgStream_DataSink__MakeClass(
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgStream_DataSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _NgStream_DataSink__ILUType;
  method_block = ilu_malloc(2 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgStream_DataSink_RegisterSourceControl__Impl;
  method_block[1] = (_ILU_C_Method) NgStream_DataSink_Done__Impl;

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
ILU_C_Class NgStream_DataSource__MakeClass(
  void (*NgStream_DataSource_Abort__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_Pause__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_Resume__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_Resend__Impl)
     (NgStream_DataSource _handle, NgBasic_UnsignedInclusiveInterval* repeatRange, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_SuggestChunkSize__Impl)
     (NgStream_DataSource _handle, CORBA_unsigned_long suggestedSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _NgStream_DataSource__ILUType;
  method_block = ilu_malloc(5 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgStream_DataSource_Abort__Impl;
  method_block[1] = (_ILU_C_Method) NgStream_DataSource_Pause__Impl;
  method_block[2] = (_ILU_C_Method) NgStream_DataSource_Resume__Impl;
  method_block[3] = (_ILU_C_Method) NgStream_DataSource_Resend__Impl;
  method_block[4] = (_ILU_C_Method) NgStream_DataSource_SuggestChunkSize__Impl;

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
void NgStream_DataSink_RegisterSourceControl (NgStream_DataSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgStream_DataSink, NgStream_DataSource, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgStream_DataSink, NgStream_DataSource, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgStream_DataSink__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, thesource, _status);
}

void NgStream_DataSink_Done (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgStream_DataSink, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgStream_DataSink, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgStream_DataSink__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

void NgStream_DataSource_Abort (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgStream_DataSource, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgStream_DataSource, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgStream_DataSource__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

void NgStream_DataSource_Pause (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgStream_DataSource, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgStream_DataSource, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgStream_DataSource__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

void NgStream_DataSource_Resume (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgStream_DataSource, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgStream_DataSource, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgStream_DataSource__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

void NgStream_DataSource_Resend (NgStream_DataSource _handle, NgBasic_UnsignedInclusiveInterval* repeatRange, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgStream_DataSource, NgBasic_UnsignedInclusiveInterval*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgStream_DataSource, NgBasic_UnsignedInclusiveInterval*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgStream_DataSource__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, repeatRange, _status);
}

void NgStream_DataSource_SuggestChunkSize (NgStream_DataSource _handle, CORBA_unsigned_long suggestedSize, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgStream_DataSource, CORBA_unsigned_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgStream_DataSource, CORBA_unsigned_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgStream_DataSource__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, suggestedSize, _status);
}

void NgStream_DataSink__SetUserData (NgStream_DataSink self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgStream_DataSink__GetUserData (NgStream_DataSink self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgStream_DataSource__SetUserData (NgStream_DataSource self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgStream_DataSource__GetUserData (NgStream_DataSource self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgStream_DataSink__Free (NgStream_DataSink* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgStream_DataSink */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgStream_DataSink *CORBA_sequence_NgStream_DataSink_allocbuf (CORBA_unsigned_long _count)
{
  NgStream_DataSink *_p;
  CORBA_unsigned_long _size = sizeof(NgStream_DataSink) * _count;

  if ((_p = (NgStream_DataSink *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgStream_OptionalDataSource* _NgStream_OptionalDataSource__Input (ilu_Call _call, NgStream_OptionalDataSource* _ref, ilu_Error *_err)
{
  NgStream_OptionalDataSource* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgStream_OptionalDataSource), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgStream_OptionalDataSource *) ilu_MallocE (sizeof (NgStream_OptionalDataSource), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgStream_OptionalDataSource));
  };
  if (_present)
    {
      *_val = _ILU_C_InputObject (_call, _NgStream_DataSource__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgStream_OptionalDataSource__Output (ilu_Call _call, NgStream_OptionalDataSource _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgStream_OptionalDataSource), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _ILU_C_OutputObject(_call, (NgStream_DataSource) _val, _NgStream_DataSource__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgStream_OptionalDataSource__SizeOf (ilu_Call _call, NgStream_OptionalDataSource _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgStream_OptionalDataSource), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _ILU_C_SizeOfObject(_call, (NgStream_DataSource) _val, _NgStream_DataSource__ILUType, ilu_FALSE, _err);
  return size;
}

void NgStream_OptionalDataSource__Free (NgStream_OptionalDataSource* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgStream_OptionalDataSource */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgStream_DataSource */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgStream_DataSource__Free (&*_val);
  }
}

NgStream_OptionalDataSource *CORBA_sequence_NgStream_OptionalDataSource_allocbuf (CORBA_unsigned_long _count)
{
  NgStream_OptionalDataSource *_p;
  CORBA_unsigned_long _size = sizeof(NgStream_OptionalDataSource) * _count;

  if ((_p = (NgStream_OptionalDataSource *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgStream_OptionalDataSource* NgStream_OptionalDataSource__alloc ()
{
  return ((NgStream_OptionalDataSource*) CORBA_sequence_NgStream_OptionalDataSource_allocbuf(1));
}

void NgStream_DataSource__Free (NgStream_DataSource* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgStream_DataSource */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgStream_DataSource *CORBA_sequence_NgStream_DataSource_allocbuf (CORBA_unsigned_long _count)
{
  NgStream_DataSource *_p;
  CORBA_unsigned_long _size = sizeof(NgStream_DataSource) * _count;

  if ((_p = (NgStream_DataSource *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void _NgStream__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("NgStream", "2.0beta1", "v2 (2.0beta1)");
  _NgBasic__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	"ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3",
	NULL};
    cl = ilu_DefineObjectType("NgStream.DataSink",	/*name*/
	NULL,	/*no brand*/
	"ilut:jXwwDJ1F22IQDKuO1TimeEIW1wl",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	2,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgStream_DataSink__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"RegisterSourceControl",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "thesource", ilu_FALSE, ilu_In, "ilut:oQ2vdKmpFhHFEwTWaLNHurAvCN7", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"Done",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3",
	NULL};
    cl = ilu_DefineObjectType("NgStream.DataSource",	/*name*/
	NULL,	/*no brand*/
	"ilut:oQ2vdKmpFhHFEwTWaLNHurAvCN7",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	5,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgStream_DataSource__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"Abort",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"Pause",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"Resume",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"Resend",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "repeatRange", ilu_FALSE, ilu_In, "ilut:ijhRh2ztjcTnB71rJMJySaH2QWI", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"SuggestChunkSize",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "suggestedSize", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _NgStream_DataSink__IoFns.kernelType = ilu_RegisterObjectType("DataSink", "NgStream", "NG", "ilut:jXwwDJ1F22IQDKuO1TimeEIW1wl",
    _NgStream_DataSink__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgStream_OptionalDataSource__IoFns.kernelType = ilu_RegisterOptionalType("OptionalDataSource", "NgStream", "NG", "ilut:daEgus3HovCDeXPgQKNk2DkCxEu",
    "ilut:oQ2vdKmpFhHFEwTWaLNHurAvCN7", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgStream_DataSource__IoFns.kernelType = ilu_RegisterObjectType("DataSource", "NgStream", "NG", "ilut:oQ2vdKmpFhHFEwTWaLNHurAvCN7",
    _NgStream_DataSource__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _NgStream_DataSink__IoFns.properties.object_class = _NgStream_DataSink__ILUType;
  _ILU_C_RegisterIoFns (&_NgStream_DataSink__IoFns);

  _NgStream_OptionalDataSource__IoFns.inputFn = (ILU_C_InputFn) _NgStream_OptionalDataSource__Input;
  _NgStream_OptionalDataSource__IoFns.outFn = (ILU_C_OutputFn) _NgStream_OptionalDataSource__Output;
  _NgStream_OptionalDataSource__IoFns.sizeFn = (ILU_C_SizeFn) _NgStream_OptionalDataSource__SizeOf;
  _NgStream_OptionalDataSource__IoFns.freeFn = (ILU_C_FreeFn) NgStream_OptionalDataSource__Free;
  _ILU_C_RegisterIoFns (&_NgStream_OptionalDataSource__IoFns);

  _NgStream_DataSource__IoFns.properties.object_class = _NgStream_DataSource__ILUType;
  _ILU_C_RegisterIoFns (&_NgStream_DataSource__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

