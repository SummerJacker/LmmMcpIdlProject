/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Jul 11 06:49:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Thu Jul 10 17:58:44 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Thu Jun 19 13:16:01 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Test2.h"

CORBA_long _Test2_P_SR_to_I__clientstub (Test2_P _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_long;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_float;
  __parmsBlock[1].parm_val  = (void *) &i;
  _ILU_C_VectorCall (_Test2_P__ILUType, &_Test2_P__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Test2_P__SurrogateClass = 0;
Test2_P Test2_P__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Test2_P) (ILU_C_SBHToObject(sbh, _Test2_P__ILUType, env));
}

void Test2__Initialize(void)
{
  extern void _Test2__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  Test1__Initialize();
  _Test2__GeneralInitialization();
  _Test2_P__SurrogateClass = Test2_P__MakeClass(
    _Test2_P_SR_to_I__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Test2_P__ILUType,
	_Test2_P__SurrogateClass);
  return;
}
