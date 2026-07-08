/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:28 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/httest/httest.isl" of Thu Aug 07 21:51:07 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/httest/iluhttp.isl" of Mon Jul 21 17:22:19 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/httest/ilu.isl" of Wed Jul 30 16:32:51 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "httest.h"

ilu_Class _httest_DerivedResource__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _httest_DerivedResource__IoFns = { ilu_object_tk, "ilut:aHidLOCdc0cA4RQsW5oEXfm7DQ1", { 0 }, 0, 0, 0, 0, 0 };


ILU_C_Class httest_DerivedResource__MakeClass(
  ilu_CString (*httest_DerivedResource_flipcase__Impl)
     (httest_DerivedResource _handle, ilu_CString strtoflipcase, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_GET__Impl)
     (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_HEAD__Impl)
     (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_POST__Impl)
     (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _httest_DerivedResource__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) httest_DerivedResource_flipcase__Impl;

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
ilu_CString httest_DerivedResource_flipcase (httest_DerivedResource _handle, ilu_CString strtoflipcase, ILU_C_ENVIRONMENT *_status)
{
  ilu_CString (*_f)(httest_DerivedResource, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ilu_CString _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (ilu_CString (*)(httest_DerivedResource, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _httest_DerivedResource__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, strtoflipcase, _status));
}

void httest_DerivedResource__SetUserData (httest_DerivedResource self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *httest_DerivedResource__GetUserData (httest_DerivedResource self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _httest__Exception_FLIPEXCEP = ILU_NIL;
#include <stdarg.h>

void httest__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_httest_FLIPEXCEP) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (CORBA_long));
    *(CORBA_long*)stat->ptr = va_arg (ap, CORBA_long);
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else
    _ilu_Assert(0, "bad exn given to httest__BindExceptionValue");
  va_end (ap);
}

void httest_DerivedResource__Free (httest_DerivedResource* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a httest_DerivedResource */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

httest_DerivedResource *CORBA_sequence_httest_DerivedResource_allocbuf (CORBA_unsigned_long _count)
{
  httest_DerivedResource *_p;
  CORBA_unsigned_long _size = sizeof(httest_DerivedResource) * _count;

  if ((_p = (httest_DerivedResource *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void _httest__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("httest", "2.0beta1", "v2 (2.0beta1)");
  _iluhttp__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _httest__Exception_FLIPEXCEP = ilu_DefineException("httest", "FLIPEXCEP", "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"ilu:Ilu_Http_1_1_resource_object",
	NULL};
    cl = ilu_DefineObjectType("httest.DerivedResource",	/*name*/
	NULL,	/*no brand*/
	"ilut:aHidLOCdc0cA4RQsW5oEXfm7DQ1",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	"Derived object of Resource to test http subtypes",	/*doc string*/
	1,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _httest_DerivedResource__ILUType = cl;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_httest_FLIPEXCEP;
    m = ilu_DefineMethod(cl, 0,
	"flipcase",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "strtoflipcase", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _httest_DerivedResource__IoFns.kernelType = ilu_RegisterObjectType("DerivedResource", "httest", ILU_NIL, "ilut:aHidLOCdc0cA4RQsW5oEXfm7DQ1",
    _httest_DerivedResource__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _httest_DerivedResource__IoFns.properties.object_class = _httest_DerivedResource__ILUType;
  _ILU_C_RegisterIoFns (&_httest_DerivedResource__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

