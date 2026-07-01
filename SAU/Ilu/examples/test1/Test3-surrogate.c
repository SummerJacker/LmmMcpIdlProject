/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Jul 11 06:49:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Thu Jul 10 17:58:44 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test3.isl" of Thu Dec 28 15:50:31 2023,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Thu Jun 19 13:16:01 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Test3.h"

Test2_T1U* _Test3_O_I_to_Test1U__clientstub (Test3_O _handle, CORBA_long i, ILU_C_ENVIRONMENT *_status)
{
  Test2_T1U* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(ilu_CString), ILU_NIL, 0, 0, (ILU_C_InputFn) _ilu_CString__Input, (ILU_C_FreeFn) ilu_CString__Free },
    { sizeof(Test1_TheU), ILU_NIL, 0, 0, (ILU_C_InputFn) _Test1_TheU__Input, (ILU_C_FreeFn) Test1_TheU__Free }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test2_T1U;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_long;
  __parmsBlock[1].parm_val  = (void *) &i;
  _ILU_C_VectorCall (_Test3_O__ILUType, &_Test3_O__ILUType->cl_methods[0],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Test3_O__SurrogateClass = 0;
Test3_O Test3_O__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Test3_O) (ILU_C_SBHToObject(sbh, _Test3_O__ILUType, env));
}

void Test3__Initialize(void)
{
  extern void _Test3__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  Test1__Initialize();
  Test2__Initialize();
  _Test3__GeneralInitialization();
  _Test3_O__SurrogateClass = Test3_O__MakeClass(
    _Test3_O_I_to_Test1U__clientstub,
    _Test1_O3_RS_R_to_R_IS__clientstub,
    _Test1_O3_O1_U_to_U__clientstub,
    _Test1_O3_BS_to_I__clientstub,
    _Test2_P_SR_to_I__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Test3_O__ILUType,
	_Test3_O__SurrogateClass);
  return;
}
