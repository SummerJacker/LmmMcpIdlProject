/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/hello-world/hello-world.isl" of Wed Jul 30 16:24:59 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "hello_world.h"

ilu_Class _hello_world_service__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _hello_world_service__IoFns = { ilu_object_tk, "ilut:lIV5QXo6KXw4vrj0tHlcPTOi1oY", { 0 }, 0, 0, 0, 0, 0 };


ILU_C_Class hello_world_service__MakeClass(
  ilu_CString (*hello_world_service_hello_world__Impl)
     (hello_world_service _handle, ilu_CString inarg, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _hello_world_service__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) hello_world_service_hello_world__Impl;
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
ilu_CString hello_world_service_hello_world (hello_world_service _handle, ilu_CString inarg, ILU_C_ENVIRONMENT *_status)
{
  ilu_CString (*_f)(hello_world_service, ilu_CString, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ilu_CString _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (ilu_CString (*)(hello_world_service, ilu_CString, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _hello_world_service__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, inarg, _status));
}

void hello_world_service__SetUserData (hello_world_service self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *hello_world_service__GetUserData (hello_world_service self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void hello_world_service__Free (hello_world_service* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a hello_world_service */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

hello_world_service *CORBA_sequence_hello_world_service_allocbuf (CORBA_unsigned_long _count)
{
  hello_world_service *_p;
  CORBA_unsigned_long _size = sizeof(hello_world_service) * _count;

  if ((_p = (hello_world_service *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void _hello_world__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("hello-world", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("hello-world.service",	/*name*/
	NULL,	/*no brand*/
	"ilut:lIV5QXo6KXw4vrj0tHlcPTOi1oY",	/*uid*/
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
    _hello_world_service__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"hello-world",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "inarg", ilu_FALSE, ilu_In, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _hello_world_service__IoFns.kernelType = ilu_RegisterObjectType("service", "hello-world", ILU_NIL, "ilut:lIV5QXo6KXw4vrj0tHlcPTOi1oY",
    _hello_world_service__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _hello_world_service__IoFns.properties.object_class = _hello_world_service__ILUType;
  _ILU_C_RegisterIoFns (&_hello_world_service__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

