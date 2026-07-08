/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgStream.isl" of Fri Aug 01 13:29:38 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "NgStream.h"

void _NgStream_DataSink_RegisterSourceControl__clientstub (NgStream_DataSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgStream_DataSource;
  __parmsBlock[0].parm_val  = (void *) thesource;
  _ILU_C_VectorCall (_NgStream_DataSink__ILUType, &_NgStream_DataSink__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

void _NgStream_DataSink_Done__clientstub (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_VectorCall (_NgStream_DataSink__ILUType, &_NgStream_DataSink__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 0, ILU_NIL);
  return;
}

static ILU_C_Class _NgStream_DataSink__SurrogateClass = 0;
NgStream_DataSink NgStream_DataSink__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgStream_DataSink) (ILU_C_SBHToObject(sbh, _NgStream_DataSink__ILUType, env));
}

void _NgStream_DataSource_Abort__clientstub (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_VectorCall (_NgStream_DataSource__ILUType, &_NgStream_DataSource__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 0, ILU_NIL);
  return;
}

void _NgStream_DataSource_Pause__clientstub (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_VectorCall (_NgStream_DataSource__ILUType, &_NgStream_DataSource__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 0, ILU_NIL);
  return;
}

void _NgStream_DataSource_Resume__clientstub (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_VectorCall (_NgStream_DataSource__ILUType, &_NgStream_DataSource__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 0, ILU_NIL);
  return;
}

void _NgStream_DataSource_Resend__clientstub (NgStream_DataSource _handle, NgBasic_UnsignedInclusiveInterval* repeatRange, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgBasic_UnsignedInclusiveInterval;
  __parmsBlock[0].parm_val  = (void *) repeatRange;
  _ILU_C_VectorCall (_NgStream_DataSource__ILUType, &_NgStream_DataSource__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

void _NgStream_DataSource_SuggestChunkSize__clientstub (NgStream_DataSource _handle, CORBA_unsigned_long suggestedSize, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[0].parm_val  = (void *) &suggestedSize;
  _ILU_C_VectorCall (_NgStream_DataSource__ILUType, &_NgStream_DataSource__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

static ILU_C_Class _NgStream_DataSource__SurrogateClass = 0;
NgStream_DataSource NgStream_DataSource__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgStream_DataSource) (ILU_C_SBHToObject(sbh, _NgStream_DataSource__ILUType, env));
}

void NgStream__Initialize(void)
{
  extern void _NgStream__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  NgBasic__Initialize();
  _NgStream__GeneralInitialization();
  _NgStream_DataSink__SurrogateClass = NgStream_DataSink__MakeClass(
    _NgStream_DataSink_RegisterSourceControl__clientstub,
    _NgStream_DataSink_Done__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgStream_DataSink__ILUType,
	_NgStream_DataSink__SurrogateClass);
  _NgStream_DataSource__SurrogateClass = NgStream_DataSource__MakeClass(
    _NgStream_DataSource_Abort__clientstub,
    _NgStream_DataSource_Pause__clientstub,
    _NgStream_DataSource_Resume__clientstub,
    _NgStream_DataSource_Resend__clientstub,
    _NgStream_DataSource_SuggestChunkSize__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgStream_DataSource__ILUType,
	_NgStream_DataSource__SurrogateClass);
  return;
}
