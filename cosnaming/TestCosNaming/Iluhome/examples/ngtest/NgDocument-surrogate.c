/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgDocument.isl" of Fri Aug 01 13:29:37 2025,
 * and "iluhttp.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngrendering.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngcache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngproperty.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngstream.isl" of Fri Aug 01 13:29:38 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "NgDocument.h"

static ILU_C_Class _NgDocument_HTTPCompatibleWebDocument__SurrogateClass = 0;
NgDocument_HTTPCompatibleWebDocument NgDocument_HTTPCompatibleWebDocument__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgDocument_HTTPCompatibleWebDocument) (ILU_C_SBHToObject(sbh, _NgDocument_HTTPCompatibleWebDocument__ILUType, env));
}

void _NgDocument_PutableWebDocument_PutRenderingAndProperties__clientstub (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgRendering_RenderingPreferences), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgRendering_RenderingPreferences__Input, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { sizeof(NgBasic_NameSequence), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_NameSequence__Input, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgRendering_Rendering;
  __parmsBlock[0].parm_val  = (void *) renderingInput;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_NgProperty_PropertyModificationSequence;
  __parmsBlock[1].parm_val  = (void *) propertiesToSet;
  _ILU_C_VectorCall (_NgDocument_PutableWebDocument__ILUType, &_NgDocument_PutableWebDocument__ILUType->cl_methods[0],
                     _evec, _handle, _status, 2, __parmsBlock);
  return;
}

static ILU_C_Class _NgDocument_PutableWebDocument__SurrogateClass = 0;
NgDocument_PutableWebDocument NgDocument_PutableWebDocument__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgDocument_PutableWebDocument) (ILU_C_SBHToObject(sbh, _NgDocument_PutableWebDocument__ILUType, env));
}

NgRendering_Rendering* _NgDocument_WebDocument_GetRenderingAndProperties__clientstub (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_Rendering* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgRendering_RenderingPreferences), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgRendering_RenderingPreferences__Input, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { sizeof(NgBasic_NameSequence), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_NameSequence__Input, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[6];
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
  __parmsBlock[4].parm_in  = 1;
  __parmsBlock[4].parm_out = 0;
  __parmsBlock[4].parm_needs_assignment   = 0;
  __parmsBlock[4].parm_needs_dereference  = 0;
  __parmsBlock[4].parm_type = TC_NgProperty_PropertyNames;
  __parmsBlock[4].parm_val  = (void *) propertiesToGet;
  __parmsBlock[5].parm_in  = 0;
  __parmsBlock[5].parm_out = 1;
  __parmsBlock[5].parm_needs_assignment   = 1;
  __parmsBlock[5].parm_needs_dereference  = 0;
  __parmsBlock[5].parm_type = TC_NgProperty_PropertySequence;
  __parmsBlock[5].parm_val  = (void *) theproperties;
  _ILU_C_VectorCall (_NgDocument_WebDocument__ILUType, &_NgDocument_WebDocument__ILUType->cl_methods[0],
                     _evec, _handle, _status, 6, __parmsBlock);
  return _retvalue;
}

void _NgDocument_WebDocument_SendRenderingAndProperties__clientstub (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[5];
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
  __parmsBlock[2].parm_type = TC_NgProperty_PropertyNames;
  __parmsBlock[2].parm_val  = (void *) propertiesToGet;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_NgDocument_RenderingAndPropertiesSink;
  __parmsBlock[3].parm_val  = (void *) renderPropSink;
  __parmsBlock[4].parm_in  = 1;
  __parmsBlock[4].parm_out = 0;
  __parmsBlock[4].parm_needs_assignment   = 0;
  __parmsBlock[4].parm_needs_dereference  = 0;
  __parmsBlock[4].parm_type = TC_NgBasic_OptionalCardinal;
  __parmsBlock[4].parm_val  = (void *) suggestedChunkSize;
  _ILU_C_VectorCall (_NgDocument_WebDocument__ILUType, &_NgDocument_WebDocument__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 5, __parmsBlock);
  return;
}

void _NgDocument_WebDocument_SendRenderingAndPropertiesSynched__clientstub (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[5];
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
  __parmsBlock[2].parm_type = TC_NgProperty_PropertyNames;
  __parmsBlock[2].parm_val  = (void *) propertiesToGet;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_NgDocument_RenderingAndPropertiesSink;
  __parmsBlock[3].parm_val  = (void *) renderPropSink;
  __parmsBlock[4].parm_in  = 1;
  __parmsBlock[4].parm_out = 0;
  __parmsBlock[4].parm_needs_assignment   = 0;
  __parmsBlock[4].parm_needs_dereference  = 0;
  __parmsBlock[4].parm_type = TC_NgBasic_OptionalCardinal;
  __parmsBlock[4].parm_val  = (void *) suggestedChunkSize;
  _ILU_C_VectorCall (_NgDocument_WebDocument__ILUType, &_NgDocument_WebDocument__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 5, __parmsBlock);
  return;
}

static ILU_C_Class _NgDocument_WebDocument__SurrogateClass = 0;
NgDocument_WebDocument NgDocument_WebDocument__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgDocument_WebDocument) (ILU_C_SBHToObject(sbh, _NgDocument_WebDocument__ILUType, env));
}

void _NgDocument_RenderingAndPropertiesSink_PropertiesProblem__clientstub (NgDocument_RenderingAndPropertiesSink _handle, NgDocument_PropertiesProblemReport* report, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgDocument_PropertiesProblemReport;
  __parmsBlock[0].parm_val  = (void *) report;
  _ILU_C_VectorCall (_NgDocument_RenderingAndPropertiesSink__ILUType, &_NgDocument_RenderingAndPropertiesSink__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

void _NgDocument_RenderingAndPropertiesSink_ReceiveProperties__clientstub (NgDocument_RenderingAndPropertiesSink _handle, NgProperty_PropertySequence* theproperties, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgProperty_PropertySequence;
  __parmsBlock[0].parm_val  = (void *) theproperties;
  _ILU_C_VectorCall (_NgDocument_RenderingAndPropertiesSink__ILUType, &_NgDocument_RenderingAndPropertiesSink__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

static ILU_C_Class _NgDocument_RenderingAndPropertiesSink__SurrogateClass = 0;
NgDocument_RenderingAndPropertiesSink NgDocument_RenderingAndPropertiesSink__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgDocument_RenderingAndPropertiesSink) (ILU_C_SBHToObject(sbh, _NgDocument_RenderingAndPropertiesSink__ILUType, env));
}

void NgDocument__Initialize(void)
{
  extern void _NgDocument__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  iluhttp__Initialize();
  NgRendering__Initialize();
  NgCache__Initialize();
  NgProperty__Initialize();
  NgStream__Initialize();
  _NgDocument__GeneralInitialization();
  _NgDocument_HTTPCompatibleWebDocument__SurrogateClass = NgDocument_HTTPCompatibleWebDocument__MakeClass(
    _NgDocument_WebDocument_GetRenderingAndProperties__clientstub,
    _NgDocument_WebDocument_SendRenderingAndProperties__clientstub,
    _NgDocument_WebDocument_SendRenderingAndPropertiesSynched__clientstub,
    _NgRendering_Renderable_GetAvailableRenderings__clientstub,
    _NgRendering_Renderable_GetRendering__clientstub,
    _NgRendering_Renderable_SendRendering__clientstub,
    _NgRendering_Renderable_SendRenderingSynched__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    _NgProperty_PropertySet_GetProperties__clientstub,
    _iluhttp_Resource_GET__clientstub,
    _iluhttp_Resource_HEAD__clientstub,
    _iluhttp_Resource_POST__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgDocument_HTTPCompatibleWebDocument__ILUType,
	_NgDocument_HTTPCompatibleWebDocument__SurrogateClass);
  _NgDocument_PutableWebDocument__SurrogateClass = NgDocument_PutableWebDocument__MakeClass(
    _NgDocument_PutableWebDocument_PutRenderingAndProperties__clientstub,
    _NgDocument_WebDocument_GetRenderingAndProperties__clientstub,
    _NgDocument_WebDocument_SendRenderingAndProperties__clientstub,
    _NgDocument_WebDocument_SendRenderingAndPropertiesSynched__clientstub,
    _NgRendering_Renderable_GetAvailableRenderings__clientstub,
    _NgRendering_Renderable_GetRendering__clientstub,
    _NgRendering_Renderable_SendRendering__clientstub,
    _NgRendering_Renderable_SendRenderingSynched__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    _NgProperty_PropertySet_GetProperties__clientstub,
    _NgRendering_PutableRenderable_PutRendering__clientstub,
    _NgProperty_PutablePropertySet_PutProperties__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgDocument_PutableWebDocument__ILUType,
	_NgDocument_PutableWebDocument__SurrogateClass);
  _NgDocument_WebDocument__SurrogateClass = NgDocument_WebDocument__MakeClass(
    _NgDocument_WebDocument_GetRenderingAndProperties__clientstub,
    _NgDocument_WebDocument_SendRenderingAndProperties__clientstub,
    _NgDocument_WebDocument_SendRenderingAndPropertiesSynched__clientstub,
    _NgRendering_Renderable_GetAvailableRenderings__clientstub,
    _NgRendering_Renderable_GetRendering__clientstub,
    _NgRendering_Renderable_SendRendering__clientstub,
    _NgRendering_Renderable_SendRenderingSynched__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    _NgProperty_PropertySet_GetProperties__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgDocument_WebDocument__ILUType,
	_NgDocument_WebDocument__SurrogateClass);
  _NgDocument_RenderingAndPropertiesSink__SurrogateClass = NgDocument_RenderingAndPropertiesSink__MakeClass(
    _NgDocument_RenderingAndPropertiesSink_PropertiesProblem__clientstub,
    _NgDocument_RenderingAndPropertiesSink_ReceiveProperties__clientstub,
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
  _ILU_C_RegisterSurrogateCType (_NgDocument_RenderingAndPropertiesSink__ILUType,
	_NgDocument_RenderingAndPropertiesSink__SurrogateClass);
  return;
}
