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

#include "httest.h"

ilu_CString _httest_DerivedResource_flipcase__clientstub (httest_DerivedResource _handle, ilu_CString strtoflipcase, ILU_C_ENVIRONMENT *_status)
{
  ilu_CString _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CORBA_long), ILU_NIL, 0, 0, (ILU_C_InputFn) ilu_InputInteger, 0 }};

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
  __parmsBlock[1].parm_val  = (void *) strtoflipcase;
  _ILU_C_VectorCall (_httest_DerivedResource__ILUType, &_httest_DerivedResource__ILUType->cl_methods[0],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _httest_DerivedResource__SurrogateClass = 0;
httest_DerivedResource httest_DerivedResource__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (httest_DerivedResource) (ILU_C_SBHToObject(sbh, _httest_DerivedResource__ILUType, env));
}

void httest__Initialize(void)
{
  extern void _httest__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  iluhttp__Initialize();
  _httest__GeneralInitialization();
  _httest_DerivedResource__SurrogateClass = httest_DerivedResource__MakeClass(
    _httest_DerivedResource_flipcase__clientstub,
    _iluhttp_Resource_GET__clientstub,
    _iluhttp_Resource_HEAD__clientstub,
    _iluhttp_Resource_POST__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_httest_DerivedResource__ILUType,
	_httest_DerivedResource__SurrogateClass);
  return;
}
