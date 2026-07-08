/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgBasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "NgBasic.h"

NgBasic_String _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub (NgBasic_NgObject _handle, ILU_C_ENVIRONMENT *_status)
{
  NgBasic_String _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgBasic_String;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_NgBasic_NgObject__ILUType, &_NgBasic_NgObject__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _NgBasic_NgObject__SurrogateClass = 0;
NgBasic_NgObject NgBasic_NgObject__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgBasic_NgObject) (ILU_C_SBHToObject(sbh, _NgBasic_NgObject__ILUType, env));
}

void NgBasic__Initialize(void)
{
  extern void _NgBasic__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _NgBasic__GeneralInitialization();
  _NgBasic_NgObject__SurrogateClass = NgBasic_NgObject__MakeClass(
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgBasic_NgObject__ILUType,
	_NgBasic_NgObject__SurrogateClass);
  return;
}
