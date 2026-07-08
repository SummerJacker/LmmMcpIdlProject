/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/ngform.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "ianacharsets.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngcache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngrendering.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "NgFormProcessor.h"

NgRendering_Rendering* _NgFormProcessor_FormProcessor_ProcessForm__clientstub (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_Rendering* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgBasic_NameSequence), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_NameSequence__Input, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_Rendering;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_NgFormProcessor_FormInputElementSequence;
  __parmsBlock[1].parm_val  = (void *) formEntries;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_NgCache_OptionalResponseCacheControl;
  __parmsBlock[2].parm_val  = (void *) responseCacheInfo;
  _ILU_C_VectorCall (_NgFormProcessor_FormProcessor__ILUType, &_NgFormProcessor_FormProcessor__ILUType->cl_methods[0],
                     _evec, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

void _NgFormProcessor_FormProcessor_SendFormReply__clientstub (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgFormProcessor_FormInputElementSequence;
  __parmsBlock[0].parm_val  = (void *) formEntries;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_NgFormProcessor_ProcessedFormSink;
  __parmsBlock[1].parm_val  = (void *) formSink;
  _ILU_C_VectorCall (_NgFormProcessor_FormProcessor__ILUType, &_NgFormProcessor_FormProcessor__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return;
}

void _NgFormProcessor_FormProcessor_SendFormReplySynched__clientstub (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgFormProcessor_FormInputElementSequence;
  __parmsBlock[0].parm_val  = (void *) formEntries;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_NgFormProcessor_ProcessedFormSink;
  __parmsBlock[1].parm_val  = (void *) formSink;
  _ILU_C_VectorCall (_NgFormProcessor_FormProcessor__ILUType, &_NgFormProcessor_FormProcessor__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return;
}

static ILU_C_Class _NgFormProcessor_FormProcessor__SurrogateClass = 0;
NgFormProcessor_FormProcessor NgFormProcessor_FormProcessor__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgFormProcessor_FormProcessor) (ILU_C_SBHToObject(sbh, _NgFormProcessor_FormProcessor__ILUType, env));
}

void _NgFormProcessor_ProcessedFormSink_FormProblem__clientstub (NgFormProcessor_ProcessedFormSink _handle, NgFormProcessor_FormProblemReport* report, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgFormProcessor_FormProblemReport;
  __parmsBlock[0].parm_val  = (void *) report;
  _ILU_C_VectorCall (_NgFormProcessor_ProcessedFormSink__ILUType, &_NgFormProcessor_ProcessedFormSink__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

static ILU_C_Class _NgFormProcessor_ProcessedFormSink__SurrogateClass = 0;
NgFormProcessor_ProcessedFormSink NgFormProcessor_ProcessedFormSink__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgFormProcessor_ProcessedFormSink) (ILU_C_SBHToObject(sbh, _NgFormProcessor_ProcessedFormSink__ILUType, env));
}

void NgFormProcessor__Initialize(void)
{
  extern void _NgFormProcessor__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  NgBasic__Initialize();
  IANA_Charsets_Registry__Initialize();
  NgCache__Initialize();
  NgRendering__Initialize();
  _NgFormProcessor__GeneralInitialization();
  _NgFormProcessor_FormProcessor__SurrogateClass = NgFormProcessor_FormProcessor__MakeClass(
    _NgFormProcessor_FormProcessor_ProcessForm__clientstub,
    _NgFormProcessor_FormProcessor_SendFormReply__clientstub,
    _NgFormProcessor_FormProcessor_SendFormReplySynched__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgFormProcessor_FormProcessor__ILUType,
	_NgFormProcessor_FormProcessor__SurrogateClass);
  _NgFormProcessor_ProcessedFormSink__SurrogateClass = NgFormProcessor_ProcessedFormSink__MakeClass(
    _NgFormProcessor_ProcessedFormSink_FormProblem__clientstub,
    _NgRendering_RenderingSink_RegisterResponseCacheControl__clientstub,
    _NgRendering_RenderingSink_RenderingProblem__clientstub,
    _NgRendering_RenderingSink_ReceiveRendering__clientstub,
    _NgRendering_RenderingSink_ReceiveRenderingChunk__clientstub,
    _NgRendering_RenderingSink_Resynchronize__clientstub,
    _NgStream_DataSink_RegisterSourceControl__clientstub,
    _NgStream_DataSink_Done__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgFormProcessor_ProcessedFormSink__ILUType,
	_NgFormProcessor_ProcessedFormSink__SurrogateClass);
  return;
}
