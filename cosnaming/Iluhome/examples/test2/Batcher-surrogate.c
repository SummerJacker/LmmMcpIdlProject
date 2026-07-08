/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:25 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test2/Batcher.isl" of Sat Aug 02 18:52:05 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test2/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Batcher.h"

void _Batcher_T_Send__clientstub (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Batcher_Time;
  __parmsBlock[0].parm_val  = (void *) &s;
  _ILU_C_VectorCall (_Batcher_T__ILUType, &_Batcher_T__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

Batcher_TimeSeq* _Batcher_T_Sync__clientstub (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status)
{
  Batcher_TimeSeq* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Batcher_TimeSeq;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Batcher_Time;
  __parmsBlock[1].parm_val  = (void *) &s;
  _ILU_C_VectorCall (_Batcher_T__ILUType, &_Batcher_T__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Batcher_T__SurrogateClass = 0;
Batcher_T Batcher_T__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Batcher_T) (ILU_C_SBHToObject(sbh, _Batcher_T__ILUType, env));
}

void Batcher__Initialize(void)
{
  extern void _Batcher__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Batcher__GeneralInitialization();
  _Batcher_T__SurrogateClass = Batcher_T__MakeClass(
    _Batcher_T_Send__clientstub,
    _Batcher_T_Sync__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Batcher_T__ILUType,
	_Batcher_T__SurrogateClass);
  return;
}
