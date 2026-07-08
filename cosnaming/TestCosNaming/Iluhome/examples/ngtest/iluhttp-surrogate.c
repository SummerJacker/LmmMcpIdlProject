/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:00 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/interfaces/iluhttp.isl" of Mon Jul 21 17:22:19 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "iluhttp.h"

iluhttp_Response* _iluhttp_Resource_GET__clientstub (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status)
{
  iluhttp_Response* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iluhttp_Response;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iluhttp_Request;
  __parmsBlock[1].parm_val  = (void *) request;
  _ILU_C_VectorCall (_iluhttp_Resource__ILUType, &_iluhttp_Resource__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

iluhttp_Response* _iluhttp_Resource_HEAD__clientstub (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status)
{
  iluhttp_Response* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iluhttp_Response;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iluhttp_Request;
  __parmsBlock[1].parm_val  = (void *) request;
  _ILU_C_VectorCall (_iluhttp_Resource__ILUType, &_iluhttp_Resource__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

iluhttp_Response* _iluhttp_Resource_POST__clientstub (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status)
{
  iluhttp_Response* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iluhttp_Response;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iluhttp_Request;
  __parmsBlock[1].parm_val  = (void *) request;
  _ILU_C_VectorCall (_iluhttp_Resource__ILUType, &_iluhttp_Resource__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _iluhttp_Resource__SurrogateClass = 0;
iluhttp_Resource iluhttp_Resource__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (iluhttp_Resource) (ILU_C_SBHToObject(sbh, _iluhttp_Resource__ILUType, env));
}

void iluhttp__Initialize(void)
{
  extern void _iluhttp__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _iluhttp__GeneralInitialization();
  _iluhttp_Resource__SurrogateClass = iluhttp_Resource__MakeClass(
    _iluhttp_Resource_GET__clientstub,
    _iluhttp_Resource_HEAD__clientstub,
    _iluhttp_Resource_POST__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_iluhttp_Resource__ILUType,
	_iluhttp_Resource__SurrogateClass);
  return;
}
