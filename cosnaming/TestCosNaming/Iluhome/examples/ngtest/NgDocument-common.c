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

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "NgDocument.h"

ilu_Class _NgDocument_HTTPCompatibleWebDocument__ILUType = NULL;
ilu_Class _NgDocument_PutableWebDocument__ILUType = NULL;
ilu_Class _NgDocument_WebDocument__ILUType = NULL;
ilu_Class _NgDocument_RenderingAndPropertiesSink__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _NgDocument_HTTPCompatibleWebDocument__IoFns = { ilu_object_tk, "ilut:kSGfFmUKAZChItOITTmoWlR2w9e", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgDocument_PutableWebDocument__IoFns = { ilu_object_tk, "ilut:aZqSt5CUdFzkRGTnYHqMY3f+5ES", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgDocument_WebDocument__IoFns = { ilu_object_tk, "ilut:gyFK9XbpUL7uA4DvedgAEpV6xoJ", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgDocument_RenderingAndPropertiesSink__IoFns = { ilu_object_tk, "ilut:nx3l7OVBZmEMIQLsgu7VpBt5OO1", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgDocument_PropertiesProblemReport__IoFns = { ilu_union_tk, "ilut:dAkkuBnO+2dubobLDR5tu--IYsv", { sizeof(NgDocument_PropertiesProblemReport) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class NgDocument_HTTPCompatibleWebDocument__MakeClass(
  NgRendering_Rendering* (*NgDocument_WebDocument_GetRenderingAndProperties__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndProperties__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_GET__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_HEAD__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_POST__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(7 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _NgDocument_HTTPCompatibleWebDocument__ILUType;
  ans->ilucc_sections[done++].ilucdts_methods = ILU_NIL;

  ans->ilucc_sections[done].ilucdts_introType = _NgDocument_WebDocument__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgDocument_WebDocument_GetRenderingAndProperties__Impl;
  method_block[1] = (_ILU_C_Method) NgDocument_WebDocument_SendRenderingAndProperties__Impl;
  method_block[2] = (_ILU_C_Method) NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgRendering_Renderable__ILUType;
  method_block = ilu_malloc(4 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgRendering_Renderable_GetAvailableRenderings__Impl;
  method_block[1] = (_ILU_C_Method) NgRendering_Renderable_GetRendering__Impl;
  method_block[2] = (_ILU_C_Method) NgRendering_Renderable_SendRendering__Impl;
  method_block[3] = (_ILU_C_Method) NgRendering_Renderable_SendRenderingSynched__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgBasic_NgObject__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgBasic_NgObject_GetInterfaceDefinitionSource__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgProperty_PropertySet__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgProperty_PropertySet_GetProperties__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _iluhttp_Resource__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iluhttp_Resource_GET__Impl;
  method_block[1] = (_ILU_C_Method) iluhttp_Resource_HEAD__Impl;
  method_block[2] = (_ILU_C_Method) iluhttp_Resource_POST__Impl;
  ans->ilucc_sections[done].ilucdts_introType = ILU_NIL;
  ans->ilucc_sections[done].ilucdts_methods = ILU_NIL;
  return ans;
fale1:
  for (i=0; i<done; i++) 
    ilu_free(ans->ilucc_sections[i].ilucdts_methods);
fale0:
  ilu_free(ans);
  return ILU_NIL;
}
ILU_C_Class NgDocument_PutableWebDocument__MakeClass(
  void (*NgDocument_PutableWebDocument_PutRenderingAndProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgDocument_WebDocument_GetRenderingAndProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_PutableRenderable_PutRendering__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status),
  void (*NgProperty_PutablePropertySet_PutProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(8 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _NgDocument_PutableWebDocument__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgDocument_PutableWebDocument_PutRenderingAndProperties__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgDocument_WebDocument__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgDocument_WebDocument_GetRenderingAndProperties__Impl;
  method_block[1] = (_ILU_C_Method) NgDocument_WebDocument_SendRenderingAndProperties__Impl;
  method_block[2] = (_ILU_C_Method) NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgRendering_Renderable__ILUType;
  method_block = ilu_malloc(4 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgRendering_Renderable_GetAvailableRenderings__Impl;
  method_block[1] = (_ILU_C_Method) NgRendering_Renderable_GetRendering__Impl;
  method_block[2] = (_ILU_C_Method) NgRendering_Renderable_SendRendering__Impl;
  method_block[3] = (_ILU_C_Method) NgRendering_Renderable_SendRenderingSynched__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgBasic_NgObject__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgBasic_NgObject_GetInterfaceDefinitionSource__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgProperty_PropertySet__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgProperty_PropertySet_GetProperties__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgRendering_PutableRenderable__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgRendering_PutableRenderable_PutRendering__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgProperty_PutablePropertySet__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgProperty_PutablePropertySet_PutProperties__Impl;
  ans->ilucc_sections[done].ilucdts_introType = ILU_NIL;
  ans->ilucc_sections[done].ilucdts_methods = ILU_NIL;
  return ans;
fale1:
  for (i=0; i<done; i++) 
    ilu_free(ans->ilucc_sections[i].ilucdts_methods);
fale0:
  ilu_free(ans);
  return ILU_NIL;
}
ILU_C_Class NgDocument_WebDocument__MakeClass(
  NgRendering_Rendering* (*NgDocument_WebDocument_GetRenderingAndProperties__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndProperties__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgDocument_WebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_WebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgDocument_WebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(5 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _NgDocument_WebDocument__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgDocument_WebDocument_GetRenderingAndProperties__Impl;
  method_block[1] = (_ILU_C_Method) NgDocument_WebDocument_SendRenderingAndProperties__Impl;
  method_block[2] = (_ILU_C_Method) NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgRendering_Renderable__ILUType;
  method_block = ilu_malloc(4 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgRendering_Renderable_GetAvailableRenderings__Impl;
  method_block[1] = (_ILU_C_Method) NgRendering_Renderable_GetRendering__Impl;
  method_block[2] = (_ILU_C_Method) NgRendering_Renderable_SendRendering__Impl;
  method_block[3] = (_ILU_C_Method) NgRendering_Renderable_SendRenderingSynched__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgBasic_NgObject__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgBasic_NgObject_GetInterfaceDefinitionSource__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgProperty_PropertySet__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgProperty_PropertySet_GetProperties__Impl;
  ans->ilucc_sections[done].ilucdts_introType = ILU_NIL;
  ans->ilucc_sections[done].ilucdts_methods = ILU_NIL;
  return ans;
fale1:
  for (i=0; i<done; i++) 
    ilu_free(ans->ilucc_sections[i].ilucdts_methods);
fale0:
  ilu_free(ans);
  return ILU_NIL;
}
ILU_C_Class NgDocument_RenderingAndPropertiesSink__MakeClass(
  void (*NgDocument_RenderingAndPropertiesSink_PropertiesProblem__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgDocument_PropertiesProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_RenderingAndPropertiesSink_ReceiveProperties__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgProperty_PropertySequence* theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RegisterResponseCacheControl__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RenderingProblem__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRendering__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRenderingChunk__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status),
  NgBasic_OptionalCardinal (*NgRendering_RenderingSink_Resynchronize__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(5 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _NgDocument_RenderingAndPropertiesSink__ILUType;
  method_block = ilu_malloc(2 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgDocument_RenderingAndPropertiesSink_PropertiesProblem__Impl;
  method_block[1] = (_ILU_C_Method) NgDocument_RenderingAndPropertiesSink_ReceiveProperties__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgRendering_RenderingSink__ILUType;
  method_block = ilu_malloc(5 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgRendering_RenderingSink_RegisterResponseCacheControl__Impl;
  method_block[1] = (_ILU_C_Method) NgRendering_RenderingSink_RenderingProblem__Impl;
  method_block[2] = (_ILU_C_Method) NgRendering_RenderingSink_ReceiveRendering__Impl;
  method_block[3] = (_ILU_C_Method) NgRendering_RenderingSink_ReceiveRenderingChunk__Impl;
  method_block[4] = (_ILU_C_Method) NgRendering_RenderingSink_Resynchronize__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgStream_DataSink__ILUType;
  method_block = ilu_malloc(2 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgStream_DataSink_RegisterSourceControl__Impl;
  method_block[1] = (_ILU_C_Method) NgStream_DataSink_Done__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _NgBasic_NgObject__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgBasic_NgObject_GetInterfaceDefinitionSource__Impl;
  ans->ilucc_sections[done].ilucdts_introType = ILU_NIL;
  ans->ilucc_sections[done].ilucdts_methods = ILU_NIL;
  return ans;
fale1:
  for (i=0; i<done; i++) 
    ilu_free(ans->ilucc_sections[i].ilucdts_methods);
fale0:
  ilu_free(ans);
  return ILU_NIL;
}
void NgDocument_PutableWebDocument_PutRenderingAndProperties (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgDocument_PutableWebDocument, NgRendering_Rendering*, NgProperty_PropertyModificationSequence*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgDocument_PutableWebDocument, NgRendering_Rendering*, NgProperty_PropertyModificationSequence*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgDocument_PutableWebDocument__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, renderingInput, propertiesToSet, _status);
}

NgRendering_Rendering* NgDocument_WebDocument_GetRenderingAndProperties (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_Rendering* (*_f)(NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgCache_OptionalResponseCacheControl*, NgProperty_PropertyNames*, NgProperty_PropertySequence**, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    NgRendering_Rendering* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (NgRendering_Rendering* (*)(NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgCache_OptionalResponseCacheControl*, NgProperty_PropertyNames*, NgProperty_PropertySequence**, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgDocument_WebDocument__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, renderingPreferences, requestCacheInfo, responseCacheInfo, propertiesToGet, theproperties, _status));
}

void NgDocument_WebDocument_SendRenderingAndProperties (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgProperty_PropertyNames*, NgDocument_RenderingAndPropertiesSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgProperty_PropertyNames*, NgDocument_RenderingAndPropertiesSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgDocument_WebDocument__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, renderingPreferences, requestCacheInfo, propertiesToGet, renderPropSink, suggestedChunkSize, _status);
}

void NgDocument_WebDocument_SendRenderingAndPropertiesSynched (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgProperty_PropertyNames*, NgDocument_RenderingAndPropertiesSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgProperty_PropertyNames*, NgDocument_RenderingAndPropertiesSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgDocument_WebDocument__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, renderingPreferences, requestCacheInfo, propertiesToGet, renderPropSink, suggestedChunkSize, _status);
}

void NgDocument_RenderingAndPropertiesSink_PropertiesProblem (NgDocument_RenderingAndPropertiesSink _handle, NgDocument_PropertiesProblemReport* report, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgDocument_RenderingAndPropertiesSink, NgDocument_PropertiesProblemReport*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgDocument_RenderingAndPropertiesSink, NgDocument_PropertiesProblemReport*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgDocument_RenderingAndPropertiesSink__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, report, _status);
}

void NgDocument_RenderingAndPropertiesSink_ReceiveProperties (NgDocument_RenderingAndPropertiesSink _handle, NgProperty_PropertySequence* theproperties, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgDocument_RenderingAndPropertiesSink, NgProperty_PropertySequence*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgDocument_RenderingAndPropertiesSink, NgProperty_PropertySequence*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgDocument_RenderingAndPropertiesSink__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, theproperties, _status);
}

void NgDocument_HTTPCompatibleWebDocument__SetUserData (NgDocument_HTTPCompatibleWebDocument self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgDocument_HTTPCompatibleWebDocument__GetUserData (NgDocument_HTTPCompatibleWebDocument self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgDocument_PutableWebDocument__SetUserData (NgDocument_PutableWebDocument self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgDocument_PutableWebDocument__GetUserData (NgDocument_PutableWebDocument self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgDocument_WebDocument__SetUserData (NgDocument_WebDocument self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgDocument_WebDocument__GetUserData (NgDocument_WebDocument self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgDocument_RenderingAndPropertiesSink__SetUserData (NgDocument_RenderingAndPropertiesSink self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgDocument_RenderingAndPropertiesSink__GetUserData (NgDocument_RenderingAndPropertiesSink self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

#include <stdarg.h>

void NgDocument__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_NgRendering_NoRenderingMatch) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgRendering_RenderingPreferences));
    *(NgRendering_RenderingPreferences*)stat->ptr = *va_arg (ap, NgRendering_RenderingPreferences*);
    stat->freeRoutine = (void (*) (void *)) NgRendering_RenderingPreferences__Free;
  }
  else if (stat->returnCode == ex_NgProperty_UnknownPropertyNames) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_NameSequence));
    *(NgBasic_NameSequence*)stat->ptr = *va_arg (ap, NgBasic_NameSequence*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_NameSequence__Free;
  }
  else if (stat->returnCode == ex_NgBasic_WouldBlock) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else if (stat->returnCode == ex_NgBasic_ObjectNotExist) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else if (stat->returnCode == ex_NgBasic_Conflict) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to NgDocument__BindExceptionValue");
  va_end (ap);
}

void NgDocument_HTTPCompatibleWebDocument__Free (NgDocument_HTTPCompatibleWebDocument* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgDocument_HTTPCompatibleWebDocument */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgDocument_HTTPCompatibleWebDocument *CORBA_sequence_NgDocument_HTTPCompatibleWebDocument_allocbuf (CORBA_unsigned_long _count)
{
  NgDocument_HTTPCompatibleWebDocument *_p;
  CORBA_unsigned_long _size = sizeof(NgDocument_HTTPCompatibleWebDocument) * _count;

  if ((_p = (NgDocument_HTTPCompatibleWebDocument *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void NgDocument_PutableWebDocument__Free (NgDocument_PutableWebDocument* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgDocument_PutableWebDocument */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgDocument_PutableWebDocument *CORBA_sequence_NgDocument_PutableWebDocument_allocbuf (CORBA_unsigned_long _count)
{
  NgDocument_PutableWebDocument *_p;
  CORBA_unsigned_long _size = sizeof(NgDocument_PutableWebDocument) * _count;

  if ((_p = (NgDocument_PutableWebDocument *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void NgDocument_WebDocument__Free (NgDocument_WebDocument* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgDocument_WebDocument */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgDocument_WebDocument *CORBA_sequence_NgDocument_WebDocument_allocbuf (CORBA_unsigned_long _count)
{
  NgDocument_WebDocument *_p;
  CORBA_unsigned_long _size = sizeof(NgDocument_WebDocument) * _count;

  if ((_p = (NgDocument_WebDocument *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void NgDocument_RenderingAndPropertiesSink__Free (NgDocument_RenderingAndPropertiesSink* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgDocument_RenderingAndPropertiesSink */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgDocument_RenderingAndPropertiesSink *CORBA_sequence_NgDocument_RenderingAndPropertiesSink_allocbuf (CORBA_unsigned_long _count)
{
  NgDocument_RenderingAndPropertiesSink *_p;
  CORBA_unsigned_long _size = sizeof(NgDocument_RenderingAndPropertiesSink) * _count;

  if ((_p = (NgDocument_RenderingAndPropertiesSink *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgDocument_PropertiesProblemReport* _NgDocument_PropertiesProblemReport__Input (ilu_Call _call, NgDocument_PropertiesProblemReport* _ref, ilu_Error *_err)
{
  NgDocument_PropertiesProblemReport* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgDocument_PropertiesProblemReport), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgDocument_PropertiesProblemReport*) ilu_MallocE(sizeof (NgDocument_PropertiesProblemReport), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(NgDocument_PropertiesProblemReport));
  };
  switch (tag) {
    case 0:
      (void) _NgBasic_ExceptionInformation__Input (_call, &_val->_u.wouldBlock,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      (void) _NgBasic_NameSequence__Input (_call, &_val->_u.unknownProperties,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgDocument_PropertiesProblemReport__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_short) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgDocument_PropertiesProblemReport__Output (ilu_Call _call, NgDocument_PropertiesProblemReport* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgDocument_PropertiesProblemReport), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _NgBasic_ExceptionInformation__Output(_call, &_val->_u.wouldBlock, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _NgBasic_NameSequence__Output(_call, &_val->_u.unknownProperties, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgDocument_PropertiesProblemReport__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _NgDocument_PropertiesProblemReport__SizeOf (ilu_Call _call, NgDocument_PropertiesProblemReport* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgDocument_PropertiesProblemReport), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _NgBasic_ExceptionInformation__SizeOf (_call, &_val->_u.wouldBlock, _err);
      break;
    case 1:
      size += _NgBasic_NameSequence__SizeOf (_call, &_val->_u.unknownProperties, _err);
      break;
    default:
      fprintf (stderr, "_NgDocument_PropertiesProblemReport__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgDocument_PropertiesProblemReport__Free (NgDocument_PropertiesProblemReport* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgDocument_PropertiesProblemReport */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      NgBasic_ExceptionInformation__Free (&_val->_u.wouldBlock);
      break;
    case 1:
      NgBasic_NameSequence__Free (&_val->_u.unknownProperties);
      break;
    default:
      fprintf (stderr, "NgDocument_PropertiesProblemReport__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

NgDocument_PropertiesProblemReport *CORBA_sequence_NgDocument_PropertiesProblemReport_allocbuf (CORBA_unsigned_long _count)
{
  NgDocument_PropertiesProblemReport *_p;
  CORBA_unsigned_long _size = sizeof(NgDocument_PropertiesProblemReport) * _count;

  if ((_p = (NgDocument_PropertiesProblemReport *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgDocument_PropertiesProblemReport* NgDocument_PropertiesProblemReport__alloc ()
{
  return ((NgDocument_PropertiesProblemReport*) CORBA_sequence_NgDocument_PropertiesProblemReport_allocbuf(1));
}

void _NgDocument__GeneralInitialization (void)
{
  static ilu_boolean initialized = ilu_FALSE;
  ilu_Error lerr = ILU_INIT_NO_ERR;
  ilu_Class cl = ILU_NIL;
  ilu_Method m = ILU_NIL;
  ilu_Mutex otmu = ilu_GetOTMutex();
  ilu_boolean newreg;

  if (initialized)
    return;
  initialized = ilu_TRUE;
  _ILU_C_InitializeCRuntime();
  _ILU_C_CheckStubConsistency("NgDocument", "2.0beta1", "v2 (2.0beta1)");
  _iluhttp__GeneralInitialization();
  _NgRendering__GeneralInitialization();
  _NgCache__GeneralInitialization();
  _NgProperty__GeneralInitialization();
  _NgStream__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  { ilu_string supers[] = {
	"ilut:gyFK9XbpUL7uA4DvedgAEpV6xoJ",
	"ilu:Ilu_Http_1_1_resource_object",
	NULL};
    cl = ilu_DefineObjectType("NgDocument.HTTPCompatibleWebDocument",	/*name*/
	NULL,	/*no brand*/
	"ilut:kSGfFmUKAZChItOITTmoWlR2w9e",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	0,	/*n methods*/
	2,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgDocument_HTTPCompatibleWebDocument__ILUType = cl;
  }
  { ilu_string supers[] = {
	"ilut:gyFK9XbpUL7uA4DvedgAEpV6xoJ",
	"ilut:h2HNeRBJzX998u0IRU6miS7gNNE",
	"ilut:mIJlovLYXEbzp3BXqb3LeTk5ufK",
	NULL};
    cl = ilu_DefineObjectType("NgDocument.PutableWebDocument",	/*name*/
	NULL,	/*no brand*/
	"ilut:aZqSt5CUdFzkRGTnYHqMY3f+5ES",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	1,	/*n methods*/
	3,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgDocument_PutableWebDocument__ILUType = cl;
  }
  { ilu_Exception	exns[5];
    exns[0] = ex_NgRendering_NoRenderingMatch;
    exns[1] = ex_NgProperty_UnknownPropertyNames;
    exns[2] = ex_NgBasic_WouldBlock;
    exns[3] = ex_NgBasic_Conflict;
    exns[4] = ex_NgBasic_ObjectNotExist;
    m = ilu_DefineMethod(cl, 0,
	"PutRenderingAndProperties",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	5,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "renderingInput", ilu_FALSE, ilu_In, "ilut:fehBMnipxhE3y19WLjzMv15h0+3", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "propertiesToSet", ilu_FALSE, ilu_In, "ilut:pmpcRjoiedKh3CkhMOURXOZKPI3", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"ilut:k4HuoKMsKc1MYar7hncLxFSd57W",
	"ilut:m44lJUWvllZBHhWqMT4E2uCqKds",
	NULL};
    cl = ilu_DefineObjectType("NgDocument.WebDocument",	/*name*/
	NULL,	/*no brand*/
	"ilut:gyFK9XbpUL7uA4DvedgAEpV6xoJ",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	3,	/*n methods*/
	2,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgDocument_WebDocument__ILUType = cl;
  }
  { ilu_Exception	exns[4];
    exns[0] = ex_NgRendering_NoRenderingMatch;
    exns[1] = ex_NgProperty_UnknownPropertyNames;
    exns[2] = ex_NgBasic_WouldBlock;
    exns[3] = ex_NgBasic_ObjectNotExist;
    m = ilu_DefineMethod(cl, 0,
	"GetRenderingAndProperties",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	4,	/*n exns*/
	exns,	/*exceptions*/
	5,	/*n args*/
	"ilut:fehBMnipxhE3y19WLjzMv15h0+3",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "renderingPreferences", ilu_FALSE, ilu_In, "ilut:plNEf7qZY7yQjkdLqh1blbICZWf", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "requestCacheInfo", ilu_FALSE, ilu_In, "ilut:iqacMndTHig-XKjynOJnqaO1tYm", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "responseCacheInfo", ilu_FALSE, ilu_Out, "ilut:ndDitjkJSN2EudLTF5z4PXYSGiA", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 3, "propertiesToGet", ilu_FALSE, ilu_In, "ilut:jnKRp54g57gOe7fPCulRE7vmvPc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 4, "theproperties", ilu_FALSE, ilu_Out, "ilut:mTOEgnV7d3PoGRSTp993OO-S1d+", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"SendRenderingAndProperties",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	5,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "renderingPreferences", ilu_FALSE, ilu_In, "ilut:plNEf7qZY7yQjkdLqh1blbICZWf", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "requestCacheInfo", ilu_FALSE, ilu_In, "ilut:iqacMndTHig-XKjynOJnqaO1tYm", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "propertiesToGet", ilu_FALSE, ilu_In, "ilut:jnKRp54g57gOe7fPCulRE7vmvPc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 3, "renderPropSink", ilu_FALSE, ilu_In, "ilut:nx3l7OVBZmEMIQLsgu7VpBt5OO1", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 4, "suggestedChunkSize", ilu_FALSE, ilu_In, "ilut:dZcZXjVtqsFnjSSxNyBk9rN3vxq", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"SendRenderingAndPropertiesSynched",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	5,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "renderingPreferences", ilu_FALSE, ilu_In, "ilut:plNEf7qZY7yQjkdLqh1blbICZWf", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "requestCacheInfo", ilu_FALSE, ilu_In, "ilut:iqacMndTHig-XKjynOJnqaO1tYm", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "propertiesToGet", ilu_FALSE, ilu_In, "ilut:jnKRp54g57gOe7fPCulRE7vmvPc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 3, "renderPropSink", ilu_FALSE, ilu_In, "ilut:nx3l7OVBZmEMIQLsgu7VpBt5OO1", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 4, "suggestedChunkSize", ilu_FALSE, ilu_In, "ilut:dZcZXjVtqsFnjSSxNyBk9rN3vxq", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"ilut:m7HWvjCGEElnwD3KB9thODvbloa",
	NULL};
    cl = ilu_DefineObjectType("NgDocument.RenderingAndPropertiesSink",	/*name*/
	NULL,	/*no brand*/
	"ilut:nx3l7OVBZmEMIQLsgu7VpBt5OO1",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	2,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgDocument_RenderingAndPropertiesSink__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"PropertiesProblem",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "report", ilu_FALSE, ilu_In, "ilut:dAkkuBnO+2dubobLDR5tu--IYsv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"ReceiveProperties",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "theproperties", ilu_FALSE, ilu_In, "ilut:mTOEgnV7d3PoGRSTp993OO-S1d+", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _NgDocument_HTTPCompatibleWebDocument__IoFns.kernelType = ilu_RegisterObjectType("HTTPCompatibleWebDocument", "NgDocument", "NG", "ilut:kSGfFmUKAZChItOITTmoWlR2w9e",
    _NgDocument_HTTPCompatibleWebDocument__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgDocument_PutableWebDocument__IoFns.kernelType = ilu_RegisterObjectType("PutableWebDocument", "NgDocument", "NG", "ilut:aZqSt5CUdFzkRGTnYHqMY3f+5ES",
    _NgDocument_PutableWebDocument__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgDocument_WebDocument__IoFns.kernelType = ilu_RegisterObjectType("WebDocument", "NgDocument", "NG", "ilut:gyFK9XbpUL7uA4DvedgAEpV6xoJ",
    _NgDocument_WebDocument__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgDocument_RenderingAndPropertiesSink__IoFns.kernelType = ilu_RegisterObjectType("RenderingAndPropertiesSink", "NgDocument", "NG", "ilut:nx3l7OVBZmEMIQLsgu7VpBt5OO1",
    _NgDocument_RenderingAndPropertiesSink__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgDocument_PropertiesProblemReport__IoFns.kernelType = type = ilu_RegisterUnionType("PropertiesProblemReport", "NgDocument", "NG", "ilut:dAkkuBnO+2dubobLDR5tu--IYsv",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* UID of discriminant type */
    2,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "wouldBlock", /* name of arm */
      "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 0;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "unknownProperties", /* name of arm */
      "ilut:jnKRp54g57gOe7fPCulRE7vmvPc", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 1;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _NgDocument_HTTPCompatibleWebDocument__IoFns.properties.object_class = _NgDocument_HTTPCompatibleWebDocument__ILUType;
  _ILU_C_RegisterIoFns (&_NgDocument_HTTPCompatibleWebDocument__IoFns);

  _NgDocument_PutableWebDocument__IoFns.properties.object_class = _NgDocument_PutableWebDocument__ILUType;
  _ILU_C_RegisterIoFns (&_NgDocument_PutableWebDocument__IoFns);

  _NgDocument_WebDocument__IoFns.properties.object_class = _NgDocument_WebDocument__ILUType;
  _ILU_C_RegisterIoFns (&_NgDocument_WebDocument__IoFns);

  _NgDocument_RenderingAndPropertiesSink__IoFns.properties.object_class = _NgDocument_RenderingAndPropertiesSink__ILUType;
  _ILU_C_RegisterIoFns (&_NgDocument_RenderingAndPropertiesSink__IoFns);

  _NgDocument_PropertiesProblemReport__IoFns.inputFn = (ILU_C_InputFn) _NgDocument_PropertiesProblemReport__Input;
  _NgDocument_PropertiesProblemReport__IoFns.outFn = (ILU_C_OutputFn) _NgDocument_PropertiesProblemReport__Output;
  _NgDocument_PropertiesProblemReport__IoFns.sizeFn = (ILU_C_SizeFn) _NgDocument_PropertiesProblemReport__SizeOf;
  _NgDocument_PropertiesProblemReport__IoFns.freeFn = (ILU_C_FreeFn) NgDocument_PropertiesProblemReport__Free;
  _ILU_C_RegisterIoFns (&_NgDocument_PropertiesProblemReport__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

