/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:24 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test2/Fibber.isl" of Sat Aug 02 18:52:05 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test2/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Fibber.h"

CORBA_unsigned_long _Fibber_T_Calc__clientstub (Fibber_T _handle, CORBA_unsigned_long d, CORBA_unsigned_long n, Fibber_T ask, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(Fibber_StringSeq), ILU_NIL, 0, 0, (ILU_C_InputFn) _Fibber_StringSeq__Input, (ILU_C_FreeFn) Fibber_StringSeq__Free }};

  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[1].parm_val  = (void *) &d;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[2].parm_val  = (void *) &n;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_Fibber_T;
  __parmsBlock[3].parm_val  = (void *) ask;
  _ILU_C_VectorCall (_Fibber_T__ILUType, &_Fibber_T__ILUType->cl_methods[0],
                     _evec, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Fibber_T__SurrogateClass = 0;
Fibber_T Fibber_T__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Fibber_T) (ILU_C_SBHToObject(sbh, _Fibber_T__ILUType, env));
}

void Fibber__Initialize(void)
{
  extern void _Fibber__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Fibber__GeneralInitialization();
  _Fibber_T__SurrogateClass = Fibber_T__MakeClass(
    _Fibber_T_Calc__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Fibber_T__ILUType,
	_Fibber_T__SurrogateClass);
  return;
}
