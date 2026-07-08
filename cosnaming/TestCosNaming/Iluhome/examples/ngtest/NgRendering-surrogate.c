/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgRendering.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "ianacharsets.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngcache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngstream.isl" of Fri Aug 01 13:29:38 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "NgRendering.h"

void _NgRendering_PutableRenderable_PutRendering__clientstub (NgRendering_PutableRenderable _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgRendering_RenderingPreferences), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgRendering_RenderingPreferences__Input, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_Rendering;
  __parmsBlock[0].parm_val  = (void *) renderingInput;
  _ILU_C_VectorCall (_NgRendering_PutableRenderable__ILUType, &_NgRendering_PutableRenderable__ILUType->cl_methods[0],
                     _evec, _handle, _status, 1, __parmsBlock);
  return;
}

static ILU_C_Class _NgRendering_PutableRenderable__SurrogateClass = 0;
NgRendering_PutableRenderable NgRendering_PutableRenderable__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgRendering_PutableRenderable) (ILU_C_SBHToObject(sbh, _NgRendering_PutableRenderable__ILUType, env));
}

NgRendering_RenderingPreferences* _NgRendering_Renderable_GetAvailableRenderings__clientstub (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_RenderingPreferences* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_RenderingPreferences;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_NgRendering_Renderable__ILUType, &_NgRendering_Renderable__ILUType->cl_methods[0],
                     _evec, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

NgRendering_Rendering* _NgRendering_Renderable_GetRendering__clientstub (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_Rendering* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgRendering_RenderingPreferences), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgRendering_RenderingPreferences__Input, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[4];
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
  __parmsBlock[1].parm_type = TC_NgRendering_RenderingPreferences;
  __parmsBlock[1].parm_val  = (void *) renderingPreferences;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_NgCache_OptionalRequestCacheControl;
  __parmsBlock[2].parm_val  = (void *) requestCacheInfo;
  __parmsBlock[3].parm_in  = 0;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_NgCache_OptionalResponseCacheControl;
  __parmsBlock[3].parm_val  = (void *) responseCacheInfo;
  _ILU_C_VectorCall (_NgRendering_Renderable__ILUType, &_NgRendering_Renderable__ILUType->cl_methods[1],
                     _evec, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

void _NgRendering_Renderable_SendRendering__clientstub (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_RenderingPreferences;
  __parmsBlock[0].parm_val  = (void *) renderingPreferences;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_NgCache_OptionalRequestCacheControl;
  __parmsBlock[1].parm_val  = (void *) requestCacheInfo;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_NgRendering_RenderingSink;
  __parmsBlock[2].parm_val  = (void *) renderSink;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_NgBasic_OptionalCardinal;
  __parmsBlock[3].parm_val  = (void *) suggestedChunkSize;
  _ILU_C_VectorCall (_NgRendering_Renderable__ILUType, &_NgRendering_Renderable__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return;
}

void _NgRendering_Renderable_SendRenderingSynched__clientstub (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_RenderingPreferences;
  __parmsBlock[0].parm_val  = (void *) renderingPreferences;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_NgCache_OptionalRequestCacheControl;
  __parmsBlock[1].parm_val  = (void *) requestCacheInfo;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_NgRendering_RenderingSink;
  __parmsBlock[2].parm_val  = (void *) renderSink;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_NgBasic_OptionalCardinal;
  __parmsBlock[3].parm_val  = (void *) suggestedChunkSize;
  _ILU_C_VectorCall (_NgRendering_Renderable__ILUType, &_NgRendering_Renderable__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return;
}

static ILU_C_Class _NgRendering_Renderable__SurrogateClass = 0;
NgRendering_Renderable NgRendering_Renderable__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgRendering_Renderable) (ILU_C_SBHToObject(sbh, _NgRendering_Renderable__ILUType, env));
}

void _NgRendering_RenderingSink_RegisterResponseCacheControl__clientstub (NgRendering_RenderingSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgCache_OptionalResponseCacheControl;
  __parmsBlock[0].parm_val  = (void *) responseCacheInfo;
  _ILU_C_VectorCall (_NgRendering_RenderingSink__ILUType, &_NgRendering_RenderingSink__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

void _NgRendering_RenderingSink_RenderingProblem__clientstub (NgRendering_RenderingSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_RenderingProblemReport;
  __parmsBlock[0].parm_val  = (void *) report;
  _ILU_C_VectorCall (_NgRendering_RenderingSink__ILUType, &_NgRendering_RenderingSink__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

void _NgRendering_RenderingSink_ReceiveRendering__clientstub (NgRendering_RenderingSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_Rendering;
  __parmsBlock[0].parm_val  = (void *) therendering;
  _ILU_C_VectorCall (_NgRendering_RenderingSink__ILUType, &_NgRendering_RenderingSink__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

void _NgRendering_RenderingSink_ReceiveRenderingChunk__clientstub (NgRendering_RenderingSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_RenderingChunk;
  __parmsBlock[0].parm_val  = (void *) thechunk;
  _ILU_C_VectorCall (_NgRendering_RenderingSink__ILUType, &_NgRendering_RenderingSink__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

NgBasic_OptionalCardinal _NgRendering_RenderingSink_Resynchronize__clientstub (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status)
{
  NgBasic_OptionalCardinal _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgBasic_OptionalCardinal;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_NgRendering_RenderingSink__ILUType, &_NgRendering_RenderingSink__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _NgRendering_RenderingSink__SurrogateClass = 0;
NgRendering_RenderingSink NgRendering_RenderingSink__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgRendering_RenderingSink) (ILU_C_SBHToObject(sbh, _NgRendering_RenderingSink__ILUType, env));
}

void NgRendering__Initialize(void)
{
  extern void _NgRendering__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  NgBasic__Initialize();
  IANA_Charsets_Registry__Initialize();
  NgCache__Initialize();
  NgStream__Initialize();
  _NgRendering__GeneralInitialization();
  _NgRendering_PutableRenderable__SurrogateClass = NgRendering_PutableRenderable__MakeClass(
    _NgRendering_PutableRenderable_PutRendering__clientstub,
    _NgRendering_Renderable_GetAvailableRenderings__clientstub,
    _NgRendering_Renderable_GetRendering__clientstub,
    _NgRendering_Renderable_SendRendering__clientstub,
    _NgRendering_Renderable_SendRenderingSynched__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgRendering_PutableRenderable__ILUType,
	_NgRendering_PutableRenderable__SurrogateClass);
  _NgRendering_Renderable__SurrogateClass = NgRendering_Renderable__MakeClass(
    _NgRendering_Renderable_GetAvailableRenderings__clientstub,
    _NgRendering_Renderable_GetRendering__clientstub,
    _NgRendering_Renderable_SendRendering__clientstub,
    _NgRendering_Renderable_SendRenderingSynched__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgRendering_Renderable__ILUType,
	_NgRendering_Renderable__SurrogateClass);
  _NgRendering_RenderingSink__SurrogateClass = NgRendering_RenderingSink__MakeClass(
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
  _ILU_C_RegisterSurrogateCType (_NgRendering_RenderingSink__ILUType,
	_NgRendering_RenderingSink__SurrogateClass);
  return;
}
