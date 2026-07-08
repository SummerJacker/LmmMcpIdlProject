/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/hello-world/hello-world.isl" of Wed Jul 30 16:24:59 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "hello_world.h"

ilu_CString _hello_world_service_hello_world__clientstub (hello_world_service _handle, ilu_CString inarg, ILU_C_ENVIRONMENT *_status)
{
  ilu_CString _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_ilu_CString;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_ilu_CString;
  __parmsBlock[1].parm_val  = (void *) inarg;
  _ILU_C_VectorCall (_hello_world_service__ILUType, &_hello_world_service__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _hello_world_service__SurrogateClass = 0;
hello_world_service hello_world_service__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (hello_world_service) (ILU_C_SBHToObject(sbh, _hello_world_service__ILUType, env));
}

void hello_world__Initialize(void)
{
  extern void _hello_world__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _hello_world__GeneralInitialization();
  _hello_world_service__SurrogateClass = hello_world_service__MakeClass(
    _hello_world_service_hello_world__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_hello_world_service__ILUType,
	_hello_world_service__SurrogateClass);
  return;
}
