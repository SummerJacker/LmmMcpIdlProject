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

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "NgRendering.h"

ilu_Class _NgRendering_PutableRenderable__ILUType = NULL;
ilu_Class _NgRendering_Renderable__ILUType = NULL;
ilu_Class _NgRendering_RenderingSink__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _NgRendering_PutableRenderable__IoFns = { ilu_object_tk, "ilut:h2HNeRBJzX998u0IRU6miS7gNNE", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_Renderable__IoFns = { ilu_object_tk, "ilut:k4HuoKMsKc1MYar7hncLxFSd57W", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingSink__IoFns = { ilu_object_tk, "ilut:m7HWvjCGEElnwD3KB9thODvbloa", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingProblemReport__IoFns = { ilu_union_tk, "ilut:b8rFItTcwWaSZKB7yGUyvOOwLkX", { sizeof(NgRendering_RenderingProblemReport) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_OptionalRendering__IoFns = { ilu_optional_tk, "ilut:jM0wxqVV4AOoPuFgU-ybUb0laj6", { sizeof(NgRendering_OptionalRendering) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_Rendering__IoFns = { ilu_record_tk, "ilut:fehBMnipxhE3y19WLjzMv15h0+3", { sizeof(NgRendering_Rendering) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingChunk__IoFns = { ilu_record_tk, "ilut:oekSseC16jUKDmneuc2Fpf32yO6", { sizeof(NgRendering_RenderingChunk) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingContentBytes__IoFns = { ilu_sequence_tk, "ilut:l-tNuZub7EuwnVch4VPwCn-VDI+", { sizeof(NgRendering_RenderingContentBytes) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingPreferences__IoFns = { ilu_record_tk, "ilut:plNEf7qZY7yQjkdLqh1blbICZWf", { sizeof(NgRendering_RenderingPreferences) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class NgRendering_PutableRenderable__MakeClass(
  void (*NgRendering_PutableRenderable_PutRendering__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgRendering_PutableRenderable _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgRendering_PutableRenderable _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(4 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _NgRendering_PutableRenderable__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgRendering_PutableRenderable_PutRendering__Impl;

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
ILU_C_Class NgRendering_Renderable__MakeClass(
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(3 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

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
ILU_C_Class NgRendering_RenderingSink__MakeClass(
  void (*NgRendering_RenderingSink_RegisterResponseCacheControl__Impl)
     (NgRendering_RenderingSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RenderingProblem__Impl)
     (NgRendering_RenderingSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRendering__Impl)
     (NgRendering_RenderingSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRenderingChunk__Impl)
     (NgRendering_RenderingSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status),
  NgBasic_OptionalCardinal (*NgRendering_RenderingSink_Resynchronize__Impl)
     (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgRendering_RenderingSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(4 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

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
void NgRendering_PutableRenderable_PutRendering (NgRendering_PutableRenderable _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgRendering_PutableRenderable, NgRendering_Rendering*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgRendering_PutableRenderable, NgRendering_Rendering*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_PutableRenderable__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, renderingInput, _status);
}

NgRendering_RenderingPreferences* NgRendering_Renderable_GetAvailableRenderings (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_RenderingPreferences* (*_f)(NgRendering_Renderable, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    NgRendering_RenderingPreferences* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (NgRendering_RenderingPreferences* (*)(NgRendering_Renderable, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_Renderable__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

NgRendering_Rendering* NgRendering_Renderable_GetRendering (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_Rendering* (*_f)(NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgCache_OptionalResponseCacheControl*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    NgRendering_Rendering* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (NgRendering_Rendering* (*)(NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgCache_OptionalResponseCacheControl*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_Renderable__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, renderingPreferences, requestCacheInfo, responseCacheInfo, _status));
}

void NgRendering_Renderable_SendRendering (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgRendering_RenderingSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgRendering_RenderingSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_Renderable__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, renderingPreferences, requestCacheInfo, renderSink, suggestedChunkSize, _status);
}

void NgRendering_Renderable_SendRenderingSynched (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgRendering_RenderingSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgRendering_RenderingSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_Renderable__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, renderingPreferences, requestCacheInfo, renderSink, suggestedChunkSize, _status);
}

void NgRendering_RenderingSink_RegisterResponseCacheControl (NgRendering_RenderingSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgRendering_RenderingSink, NgCache_OptionalResponseCacheControl, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgRendering_RenderingSink, NgCache_OptionalResponseCacheControl, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_RenderingSink__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, responseCacheInfo, _status);
}

void NgRendering_RenderingSink_RenderingProblem (NgRendering_RenderingSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgRendering_RenderingSink, NgRendering_RenderingProblemReport*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgRendering_RenderingSink, NgRendering_RenderingProblemReport*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_RenderingSink__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, report, _status);
}

void NgRendering_RenderingSink_ReceiveRendering (NgRendering_RenderingSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgRendering_RenderingSink, NgRendering_Rendering*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgRendering_RenderingSink, NgRendering_Rendering*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_RenderingSink__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, therendering, _status);
}

void NgRendering_RenderingSink_ReceiveRenderingChunk (NgRendering_RenderingSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgRendering_RenderingSink, NgRendering_RenderingChunk*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgRendering_RenderingSink, NgRendering_RenderingChunk*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_RenderingSink__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, thechunk, _status);
}

NgBasic_OptionalCardinal NgRendering_RenderingSink_Resynchronize (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status)
{
  NgBasic_OptionalCardinal (*_f)(NgRendering_RenderingSink, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    NgBasic_OptionalCardinal _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (NgBasic_OptionalCardinal (*)(NgRendering_RenderingSink, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgRendering_RenderingSink__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

void NgRendering_PutableRenderable__SetUserData (NgRendering_PutableRenderable self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgRendering_PutableRenderable__GetUserData (NgRendering_PutableRenderable self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgRendering_Renderable__SetUserData (NgRendering_Renderable self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgRendering_Renderable__GetUserData (NgRendering_Renderable self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgRendering_RenderingSink__SetUserData (NgRendering_RenderingSink self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgRendering_RenderingSink__GetUserData (NgRendering_RenderingSink self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _NgRendering__Exception_NoRenderingMatch = ILU_NIL;
#include <stdarg.h>

void NgRendering__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
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
    _ilu_Assert(0, "bad exn given to NgRendering__BindExceptionValue");
  va_end (ap);
}

void NgRendering_PutableRenderable__Free (NgRendering_PutableRenderable* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_PutableRenderable */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgRendering_PutableRenderable *CORBA_sequence_NgRendering_PutableRenderable_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_PutableRenderable *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_PutableRenderable) * _count;

  if ((_p = (NgRendering_PutableRenderable *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void NgRendering_Renderable__Free (NgRendering_Renderable* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_Renderable */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgRendering_Renderable *CORBA_sequence_NgRendering_Renderable_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_Renderable *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_Renderable) * _count;

  if ((_p = (NgRendering_Renderable *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void NgRendering_RenderingSink__Free (NgRendering_RenderingSink* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_RenderingSink */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgRendering_RenderingSink *CORBA_sequence_NgRendering_RenderingSink_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_RenderingSink *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_RenderingSink) * _count;

  if ((_p = (NgRendering_RenderingSink *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgRendering_RenderingProblemReport* _NgRendering_RenderingProblemReport__Input (ilu_Call _call, NgRendering_RenderingProblemReport* _ref, ilu_Error *_err)
{
  NgRendering_RenderingProblemReport* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgRendering_RenderingProblemReport), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgRendering_RenderingProblemReport*) ilu_MallocE(sizeof (NgRendering_RenderingProblemReport), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(NgRendering_RenderingProblemReport));
  };
  switch (tag) {
    case 0:
      (void) _NgRendering_RenderingPreferences__Input (_call, &_val->_u.noMatch,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      (void) _NgBasic_ExceptionInformation__Input (_call, &_val->_u.wouldBlock,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      (void) _NgBasic_ExceptionInformation__Input (_call, &_val->_u.objectNotExist,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgRendering_RenderingProblemReport__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
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

void _NgRendering_RenderingProblemReport__Output (ilu_Call _call, NgRendering_RenderingProblemReport* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgRendering_RenderingProblemReport), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _NgRendering_RenderingPreferences__Output(_call, &_val->_u.noMatch, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _NgBasic_ExceptionInformation__Output(_call, &_val->_u.wouldBlock, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      _NgBasic_ExceptionInformation__Output(_call, &_val->_u.objectNotExist, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgRendering_RenderingProblemReport__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _NgRendering_RenderingProblemReport__SizeOf (ilu_Call _call, NgRendering_RenderingProblemReport* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgRendering_RenderingProblemReport), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _NgRendering_RenderingPreferences__SizeOf (_call, &_val->_u.noMatch, _err);
      break;
    case 1:
      size += _NgBasic_ExceptionInformation__SizeOf (_call, &_val->_u.wouldBlock, _err);
      break;
    case 2:
      size += _NgBasic_ExceptionInformation__SizeOf (_call, &_val->_u.objectNotExist, _err);
      break;
    default:
      fprintf (stderr, "_NgRendering_RenderingProblemReport__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgRendering_RenderingProblemReport__Free (NgRendering_RenderingProblemReport* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_RenderingProblemReport */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      NgRendering_RenderingPreferences__Free (&_val->_u.noMatch);
      break;
    case 1:
      NgBasic_ExceptionInformation__Free (&_val->_u.wouldBlock);
      break;
    case 2:
      NgBasic_ExceptionInformation__Free (&_val->_u.objectNotExist);
      break;
    default:
      fprintf (stderr, "NgRendering_RenderingProblemReport__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

NgRendering_RenderingProblemReport *CORBA_sequence_NgRendering_RenderingProblemReport_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_RenderingProblemReport *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_RenderingProblemReport) * _count;

  if ((_p = (NgRendering_RenderingProblemReport *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgRendering_RenderingProblemReport* NgRendering_RenderingProblemReport__alloc ()
{
  return ((NgRendering_RenderingProblemReport*) CORBA_sequence_NgRendering_RenderingProblemReport_allocbuf(1));
}

NgRendering_OptionalRendering* _NgRendering_OptionalRendering__Input (ilu_Call _call, NgRendering_OptionalRendering* _ref, ilu_Error *_err)
{
  NgRendering_OptionalRendering* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgRendering_OptionalRendering), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgRendering_OptionalRendering *) ilu_MallocE (sizeof (NgRendering_OptionalRendering), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgRendering_OptionalRendering));
  };
  if (_present)
    {
    *_val = (NgRendering_Rendering*) ilu_MallocE (sizeof (NgRendering_Rendering), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(NgRendering_Rendering));
      (void) _NgRendering_Rendering__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  else *_val = ILU_NIL;
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgRendering_OptionalRendering__Output (ilu_Call _call, NgRendering_OptionalRendering _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgRendering_OptionalRendering), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgRendering_Rendering__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgRendering_OptionalRendering__SizeOf (ilu_Call _call, NgRendering_OptionalRendering _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgRendering_OptionalRendering), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgRendering_Rendering__SizeOf (_call, &*_val, _err);
  return size;
}

void NgRendering_OptionalRendering__Free (NgRendering_OptionalRendering* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_OptionalRendering */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgRendering_Rendering */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgRendering_Rendering__Free (&**_val);
    ilu_free(*_val);
  }
}

NgRendering_OptionalRendering *CORBA_sequence_NgRendering_OptionalRendering_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_OptionalRendering *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_OptionalRendering) * _count;

  if ((_p = (NgRendering_OptionalRendering *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgRendering_OptionalRendering* NgRendering_OptionalRendering__alloc ()
{
  return ((NgRendering_OptionalRendering*) CORBA_sequence_NgRendering_OptionalRendering_allocbuf(1));
}

NgRendering_Rendering* _NgRendering_Rendering__Input (ilu_Call _call, NgRendering_Rendering* _ref, ilu_Error *_err)
{
  NgRendering_Rendering* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgRendering_Rendering__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_Rendering__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgRendering_Rendering*) ilu_MallocE (sizeof (NgRendering_Rendering), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgRendering_Rendering));
    } else {
      _val = (NgRendering_Rendering*) _ILU_C_CRCreate (s, sizeof(NgRendering_Rendering), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_Rendering), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_String__Input (_call, &_val->contentType,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_URISequence__Input (_call, &_val->contentEncoding,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalUnsignedInclusiveInterval__Input (_call, &_val->contentRange,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->rangeEncoded, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortCardinal (_call, &_val->contentCharSet, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalString__Input (_call, &_val->contentLocale,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgRendering_RenderingContentBytes__Input (_call, &_val->renderingBytes,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (s != ILU_NIL) _ILU_C_CRPostInput (s, _val, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgRendering_Rendering__Output (ilu_Call _call, NgRendering_Rendering* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgRendering_Rendering__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgRendering_Rendering__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_Rendering), _err);
    if (ILU_ERRNOK(*_err)) return;
  _NgBasic_String__Output(_call, (_val->contentType), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_URISequence__Output(_call, (&_val->contentEncoding), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalUnsignedInclusiveInterval__Output(_call, (_val->contentRange), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->rangeEncoded), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortCardinal (_call, (_val->contentCharSet), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalString__Output(_call, (_val->contentLocale), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgRendering_RenderingContentBytes__Output(_call, (&_val->renderingBytes), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgRendering_Rendering__SizeOf (ilu_Call _call, NgRendering_Rendering* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgRendering_Rendering__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_Rendering__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_Rendering), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_String__SizeOf (_call, _val->contentType, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_URISequence__SizeOf (_call, &_val->contentEncoding, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalUnsignedInclusiveInterval__SizeOf (_call, _val->contentRange, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->rangeEncoded, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortCardinal(_call, _val->contentCharSet, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalString__SizeOf (_call, _val->contentLocale, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgRendering_RenderingContentBytes__SizeOf (_call, &_val->renderingBytes, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgRendering_Rendering__Free (NgRendering_Rendering* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_Rendering */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_NgRendering_Rendering__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_Rendering__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  NgBasic_String__Free (&_val->contentType);
  NgBasic_URISequence__Free (&_val->contentEncoding);
  NgBasic_OptionalUnsignedInclusiveInterval__Free (&_val->contentRange);
  NgBasic_OptionalString__Free (&_val->contentLocale);
  NgRendering_RenderingContentBytes__Free (&_val->renderingBytes);
}

NgRendering_Rendering *CORBA_sequence_NgRendering_Rendering_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_Rendering *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_Rendering) * _count;

  if ((_p = (NgRendering_Rendering *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgRendering_Rendering* NgRendering_Rendering__alloc ()
{
  return ((NgRendering_Rendering*) CORBA_sequence_NgRendering_Rendering_allocbuf(1));
}

NgRendering_RenderingChunk* _NgRendering_RenderingChunk__Input (ilu_Call _call, NgRendering_RenderingChunk* _ref, ilu_Error *_err)
{
  NgRendering_RenderingChunk* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgRendering_RenderingChunk__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_RenderingChunk__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgRendering_RenderingChunk*) ilu_MallocE (sizeof (NgRendering_RenderingChunk), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgRendering_RenderingChunk));
    } else {
      _val = (NgRendering_RenderingChunk*) _ILU_C_CRCreate (s, sizeof(NgRendering_RenderingChunk), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_RenderingChunk), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalUnsignedInclusiveInterval__Input (_call, &_val->contentRange,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgRendering_RenderingContentBytes__Input (_call, &_val->renderingBytes,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (s != ILU_NIL) _ILU_C_CRPostInput (s, _val, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgRendering_RenderingChunk__Output (ilu_Call _call, NgRendering_RenderingChunk* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgRendering_RenderingChunk__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgRendering_RenderingChunk__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_RenderingChunk), _err);
    if (ILU_ERRNOK(*_err)) return;
  _NgBasic_OptionalUnsignedInclusiveInterval__Output(_call, (_val->contentRange), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgRendering_RenderingContentBytes__Output(_call, (&_val->renderingBytes), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgRendering_RenderingChunk__SizeOf (ilu_Call _call, NgRendering_RenderingChunk* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgRendering_RenderingChunk__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_RenderingChunk__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_RenderingChunk), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalUnsignedInclusiveInterval__SizeOf (_call, _val->contentRange, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgRendering_RenderingContentBytes__SizeOf (_call, &_val->renderingBytes, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgRendering_RenderingChunk__Free (NgRendering_RenderingChunk* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_RenderingChunk */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_NgRendering_RenderingChunk__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_RenderingChunk__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  NgBasic_OptionalUnsignedInclusiveInterval__Free (&_val->contentRange);
  NgRendering_RenderingContentBytes__Free (&_val->renderingBytes);
}

NgRendering_RenderingChunk *CORBA_sequence_NgRendering_RenderingChunk_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_RenderingChunk *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_RenderingChunk) * _count;

  if ((_p = (NgRendering_RenderingChunk *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgRendering_RenderingChunk* NgRendering_RenderingChunk__alloc ()
{
  return ((NgRendering_RenderingChunk*) CORBA_sequence_NgRendering_RenderingChunk_allocbuf(1));
}

NgRendering_RenderingContentBytes* _NgRendering_RenderingContentBytes__Input (ilu_Call _call, NgRendering_RenderingContentBytes* _ref, ilu_Error *_err)
{
  NgRendering_RenderingContentBytes* _val = _ref;

  ilu_cardinal len=0;
  ilu_cardinal limit = 0;
  ilu_bytes b = ILU_NIL;

  if (_ref == ILU_NIL) {
    _val = (NgRendering_RenderingContentBytes *) ilu_MallocE(sizeof(NgRendering_RenderingContentBytes), _err);
    if (_val == ILU_NIL)  goto marshalError;
  } else {
    if ((_ref->_buffer != ILU_NIL) && (_ref->_maximum > 0)) {
      limit = ((0 != 0) && (_ref->_maximum > 0)) ? 0 : _ref->_maximum;
      b = _ref->_buffer;
    };
  };
  ilu_InputBytes (_call, &b, &len, limit, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  _val->_length = len;
  if ((_ref == ILU_NIL) || (b != _ref->_buffer)) {
    _val->_maximum = len;
    _val->_buffer = b;
  };
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgRendering_RenderingContentBytes__Output (ilu_Call _call, NgRendering_RenderingContentBytes* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputBytes (_call, _val->_buffer, _val->_length, 0, _err);
 marshalError:
  return;
}

ilu_cardinal _NgRendering_RenderingContentBytes__SizeOf (ilu_Call _call, NgRendering_RenderingContentBytes* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfBytes (_call, _val->_buffer, _val->_length, 0, _err);
  return size;
}

void NgRendering_RenderingContentBytes__Free (NgRendering_RenderingContentBytes* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_RenderingContentBytes */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_octet)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_octet)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_octet))) */ ) {
    //ilu_DebugPrintf("OK NgRendering_RenderingContentBytes__Free (NgRendering_RenderingContentBytes* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgRendering_RenderingContentBytes *CORBA_sequence_NgRendering_RenderingContentBytes_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_RenderingContentBytes *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_RenderingContentBytes) * _count;

  if ((_p = (NgRendering_RenderingContentBytes *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgRendering_RenderingContentBytes* NgRendering_RenderingContentBytes__alloc ()
{
  return ((NgRendering_RenderingContentBytes*) CORBA_sequence_NgRendering_RenderingContentBytes_allocbuf(1));
}

NgRendering_RenderingPreferences* _NgRendering_RenderingPreferences__Input (ilu_Call _call, NgRendering_RenderingPreferences* _ref, ilu_Error *_err)
{
  NgRendering_RenderingPreferences* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgRendering_RenderingPreferences__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_RenderingPreferences__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (NgRendering_RenderingPreferences*) ilu_MallocE (sizeof (NgRendering_RenderingPreferences), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(NgRendering_RenderingPreferences));
    } else {
      _val = (NgRendering_RenderingPreferences*) _ILU_C_CRCreate (s, sizeof(NgRendering_RenderingPreferences), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_RenderingPreferences), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_URISequence__Input (_call, &_val->allowContentTypes,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_URISequence__Input (_call, &_val->disallowContentTypes,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_URISequence__Input (_call, &_val->allowEncodings,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_URISequence__Input (_call, &_val->disallowEncodings,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Input (_call, &_val->acceptCharsets,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_StringSequence__Input (_call, &_val->acceptLocales,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalUnsignedInclusiveInterval__Input (_call, &_val->range,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalURI__Input (_call, &_val->userAgent,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (s != ILU_NIL) _ILU_C_CRPostInput (s, _val, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgRendering_RenderingPreferences__Output (ilu_Call _call, NgRendering_RenderingPreferences* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_NgRendering_RenderingPreferences__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_NgRendering_RenderingPreferences__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_RenderingPreferences), _err);
    if (ILU_ERRNOK(*_err)) return;
  _NgBasic_URISequence__Output(_call, (&_val->allowContentTypes), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_URISequence__Output(_call, (&_val->disallowContentTypes), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_URISequence__Output(_call, (&_val->allowEncodings), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_URISequence__Output(_call, (&_val->disallowEncodings), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Output(_call, (&_val->acceptCharsets), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_StringSequence__Output(_call, (&_val->acceptLocales), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalUnsignedInclusiveInterval__Output(_call, (_val->range), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _NgBasic_OptionalURI__Output(_call, (_val->userAgent), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _NgRendering_RenderingPreferences__SizeOf (ilu_Call _call, NgRendering_RenderingPreferences* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_NgRendering_RenderingPreferences__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_RenderingPreferences__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(NgRendering_RenderingPreferences), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_URISequence__SizeOf (_call, &_val->allowContentTypes, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_URISequence__SizeOf (_call, &_val->disallowContentTypes, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_URISequence__SizeOf (_call, &_val->allowEncodings, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_URISequence__SizeOf (_call, &_val->disallowEncodings, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__SizeOf (_call, &_val->acceptCharsets, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_StringSequence__SizeOf (_call, &_val->acceptLocales, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalUnsignedInclusiveInterval__SizeOf (_call, _val->range, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _NgBasic_OptionalURI__SizeOf (_call, _val->userAgent, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgRendering_RenderingPreferences__Free (NgRendering_RenderingPreferences* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgRendering_RenderingPreferences */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_NgRendering_RenderingPreferences__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_NgRendering_RenderingPreferences__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  NgBasic_URISequence__Free (&_val->allowContentTypes);
  NgBasic_URISequence__Free (&_val->disallowContentTypes);
  NgBasic_URISequence__Free (&_val->allowEncodings);
  NgBasic_URISequence__Free (&_val->disallowEncodings);
  IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Free (&_val->acceptCharsets);
  NgBasic_StringSequence__Free (&_val->acceptLocales);
  NgBasic_OptionalUnsignedInclusiveInterval__Free (&_val->range);
  NgBasic_OptionalURI__Free (&_val->userAgent);
}

NgRendering_RenderingPreferences *CORBA_sequence_NgRendering_RenderingPreferences_allocbuf (CORBA_unsigned_long _count)
{
  NgRendering_RenderingPreferences *_p;
  CORBA_unsigned_long _size = sizeof(NgRendering_RenderingPreferences) * _count;

  if ((_p = (NgRendering_RenderingPreferences *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgRendering_RenderingPreferences* NgRendering_RenderingPreferences__alloc ()
{
  return ((NgRendering_RenderingPreferences*) CORBA_sequence_NgRendering_RenderingPreferences_allocbuf(1));
}

void NgRendering_RenderingContentBytes_Every (NgRendering_RenderingContentBytes *h, void (*f)(CORBA_octet *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_octet), (void *) data);
}

void NgRendering_RenderingContentBytes_Append (NgRendering_RenderingContentBytes *h, CORBA_octet item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet), err);
}

void NgRendering_RenderingContentBytes_Push (NgRendering_RenderingContentBytes *h, CORBA_octet item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet));
}

void NgRendering_RenderingContentBytes_Pop (NgRendering_RenderingContentBytes *h, CORBA_octet *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_octet));
}

CORBA_unsigned_long NgRendering_RenderingContentBytes_Length (NgRendering_RenderingContentBytes *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_octet * NgRendering_RenderingContentBytes_Nth (NgRendering_RenderingContentBytes *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgRendering_RenderingContentBytes * NgRendering_RenderingContentBytes_Create (CORBA_unsigned_long sz, CORBA_octet *p)
{
  NgRendering_RenderingContentBytes *s;
  s = (NgRendering_RenderingContentBytes *) ilu_malloc(sizeof(NgRendering_RenderingContentBytes));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgRendering_RenderingContentBytes)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_octet *) ilu_malloc(sz * sizeof(CORBA_octet))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_octet));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgRendering_RenderingContentBytes_Init (NgRendering_RenderingContentBytes *s, CORBA_unsigned_long sz, CORBA_octet *p)
{
  if (sz == 0 && p != ILU_NIL)
    return;
  if (sz > 0)
    s->_maximum = sz;
  else
    s->_maximum = 0;
  if (sz > 0 && p != ILU_NIL)
    s->_length = sz;
  else
    s->_length = 0;
  if (sz > 0 && p == ILU_NIL) {
    s->_buffer = (CORBA_octet *) ilu_malloc (sz * sizeof (CORBA_octet));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CORBA_octet)); }}
  else
    s->_buffer = p;
  return;
}

void _NgRendering__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("NgRendering", "2.0beta1", "v2 (2.0beta1)");
  _NgBasic__GeneralInitialization();
  _IANA_Charsets_Registry__GeneralInitialization();
  _NgCache__GeneralInitialization();
  _NgStream__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _NgRendering__Exception_NoRenderingMatch = ilu_DefineException("NgRendering", "NoRenderingMatch", "ilut:plNEf7qZY7yQjkdLqh1blbICZWf", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"ilut:k4HuoKMsKc1MYar7hncLxFSd57W",
	NULL};
    cl = ilu_DefineObjectType("NgRendering.PutableRenderable",	/*name*/
	NULL,	/*no brand*/
	"ilut:h2HNeRBJzX998u0IRU6miS7gNNE",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	1,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgRendering_PutableRenderable__ILUType = cl;
  }
  { ilu_Exception	exns[4];
    exns[0] = ex_NgRendering_NoRenderingMatch;
    exns[1] = ex_NgBasic_WouldBlock;
    exns[2] = ex_NgBasic_Conflict;
    exns[3] = ex_NgBasic_ObjectNotExist;
    m = ilu_DefineMethod(cl, 0,
	"PutRendering",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	4,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "renderingInput", ilu_FALSE, ilu_In, "ilut:fehBMnipxhE3y19WLjzMv15h0+3", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3",
	NULL};
    cl = ilu_DefineObjectType("NgRendering.Renderable",	/*name*/
	NULL,	/*no brand*/
	"ilut:k4HuoKMsKc1MYar7hncLxFSd57W",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	4,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgRendering_Renderable__ILUType = cl;
  }
  { ilu_Exception	exns[2];
    exns[0] = ex_NgBasic_WouldBlock;
    exns[1] = ex_NgBasic_ObjectNotExist;
    m = ilu_DefineMethod(cl, 0,
	"GetAvailableRenderings",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	2,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:plNEf7qZY7yQjkdLqh1blbICZWf",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[3];
    exns[0] = ex_NgRendering_NoRenderingMatch;
    exns[1] = ex_NgBasic_WouldBlock;
    exns[2] = ex_NgBasic_ObjectNotExist;
    m = ilu_DefineMethod(cl, 1,
	"GetRendering",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	3,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
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
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"SendRendering",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	4,	/*n args*/
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
    ilu_DefineMethodArg (m, 2, "renderSink", ilu_FALSE, ilu_In, "ilut:m7HWvjCGEElnwD3KB9thODvbloa", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 3, "suggestedChunkSize", ilu_FALSE, ilu_In, "ilut:dZcZXjVtqsFnjSSxNyBk9rN3vxq", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"SendRenderingSynched",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	4,	/*n args*/
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
    ilu_DefineMethodArg (m, 2, "renderSink", ilu_FALSE, ilu_In, "ilut:m7HWvjCGEElnwD3KB9thODvbloa", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 3, "suggestedChunkSize", ilu_FALSE, ilu_In, "ilut:dZcZXjVtqsFnjSSxNyBk9rN3vxq", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"ilut:jXwwDJ1F22IQDKuO1TimeEIW1wl",
	NULL};
    cl = ilu_DefineObjectType("NgRendering.RenderingSink",	/*name*/
	NULL,	/*no brand*/
	"ilut:m7HWvjCGEElnwD3KB9thODvbloa",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	5,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgRendering_RenderingSink__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"RegisterResponseCacheControl",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "responseCacheInfo", ilu_FALSE, ilu_In, "ilut:ndDitjkJSN2EudLTF5z4PXYSGiA", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"RenderingProblem",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "report", ilu_FALSE, ilu_In, "ilut:b8rFItTcwWaSZKB7yGUyvOOwLkX", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"ReceiveRendering",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "therendering", ilu_FALSE, ilu_In, "ilut:fehBMnipxhE3y19WLjzMv15h0+3", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"ReceiveRenderingChunk",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "thechunk", ilu_FALSE, ilu_In, "ilut:oekSseC16jUKDmneuc2Fpf32yO6", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"Resynchronize",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:dZcZXjVtqsFnjSSxNyBk9rN3vxq",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _NgRendering_PutableRenderable__IoFns.kernelType = ilu_RegisterObjectType("PutableRenderable", "NgRendering", "NG", "ilut:h2HNeRBJzX998u0IRU6miS7gNNE",
    _NgRendering_PutableRenderable__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgRendering_Renderable__IoFns.kernelType = ilu_RegisterObjectType("Renderable", "NgRendering", "NG", "ilut:k4HuoKMsKc1MYar7hncLxFSd57W",
    _NgRendering_Renderable__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgRendering_RenderingSink__IoFns.kernelType = ilu_RegisterObjectType("RenderingSink", "NgRendering", "NG", "ilut:m7HWvjCGEElnwD3KB9thODvbloa",
    _NgRendering_RenderingSink__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgRendering_RenderingProblemReport__IoFns.kernelType = type = ilu_RegisterUnionType("RenderingProblemReport", "NgRendering", "NG", "ilut:b8rFItTcwWaSZKB7yGUyvOOwLkX",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* UID of discriminant type */
    3,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "noMatch", /* name of arm */
      "ilut:plNEf7qZY7yQjkdLqh1blbICZWf", /* arm type */
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
      "wouldBlock", /* name of arm */
      "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 1;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      "objectNotExist", /* name of arm */
      "ilut:enT6OHHK5PjNfl1lLsIPY96Zwbn", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 2;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgRendering_OptionalRendering__IoFns.kernelType = ilu_RegisterOptionalType("OptionalRendering", "NgRendering", "NG", "ilut:jM0wxqVV4AOoPuFgU-ybUb0laj6",
    "ilut:fehBMnipxhE3y19WLjzMv15h0+3", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgRendering_Rendering__IoFns.kernelType = type = ilu_RegisterRecordType("Rendering", "NgRendering", "NG", "ilut:fehBMnipxhE3y19WLjzMv15h0+3",
    7,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "contentType", /* field name */
      "ilut:lc80izKSPGeLPcHOWRB6Hquk21x", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "contentEncoding", /* field name */
      "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "contentRange", /* field name */
      "ilut:mdFsF5jq+msKV1hcVFdaMToJPMs", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "rangeEncoded", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "contentCharSet", /* field name */
      "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "contentLocale", /* field name */
      "ilut:krQWr8h8gb6uJ7RmH-7ZLXpF-Oy", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 6, /* which field */
      "renderingBytes", /* field name */
      "ilut:l-tNuZub7EuwnVch4VPwCn-VDI+", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgRendering_RenderingChunk__IoFns.kernelType = type = ilu_RegisterRecordType("RenderingChunk", "NgRendering", "NG", "ilut:oekSseC16jUKDmneuc2Fpf32yO6",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "contentRange", /* field name */
      "ilut:mdFsF5jq+msKV1hcVFdaMToJPMs", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "renderingBytes", /* field name */
      "ilut:l-tNuZub7EuwnVch4VPwCn-VDI+", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _NgRendering_RenderingContentBytes__IoFns.kernelType = ilu_RegisterSequenceType("RenderingContentBytes", "NgRendering", "NG", "ilut:l-tNuZub7EuwnVch4VPwCn-VDI+",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgRendering_RenderingPreferences__IoFns.kernelType = type = ilu_RegisterRecordType("RenderingPreferences", "NgRendering", "NG", "ilut:plNEf7qZY7yQjkdLqh1blbICZWf",
    8,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "allowContentTypes", /* field name */
      "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "disallowContentTypes", /* field name */
      "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "allowEncodings", /* field name */
      "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "disallowEncodings", /* field name */
      "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "acceptCharsets", /* field name */
      "ilut:garJ50fEH7VuQSw70iswIWle7xi", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "acceptLocales", /* field name */
      "ilut:pVA9NPjxKPIk45Pouoxx46IkczI", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 6, /* which field */
      "range", /* field name */
      "ilut:mdFsF5jq+msKV1hcVFdaMToJPMs", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 7, /* which field */
      "userAgent", /* field name */
      "ilut:kwagdxa3MUBXSAWpOS1TUCMm-J+", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("RenderingEncodingSequence", "NgRendering", "NG", "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY",
    "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("RenderingEncoding", "NgRendering", "NG", "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("RenderingTypeSequence", "NgRendering", "NG", "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY",
    "ilut:ao2PwB0lCriPcpp5OZMXly3E3iY",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("RenderingType", "NgRendering", "NG", "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",
    "ilut:lc80izKSPGeLPcHOWRB6Hquk21x",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _NgRendering_PutableRenderable__IoFns.properties.object_class = _NgRendering_PutableRenderable__ILUType;
  _ILU_C_RegisterIoFns (&_NgRendering_PutableRenderable__IoFns);

  _NgRendering_Renderable__IoFns.properties.object_class = _NgRendering_Renderable__ILUType;
  _ILU_C_RegisterIoFns (&_NgRendering_Renderable__IoFns);

  _NgRendering_RenderingSink__IoFns.properties.object_class = _NgRendering_RenderingSink__ILUType;
  _ILU_C_RegisterIoFns (&_NgRendering_RenderingSink__IoFns);

  _NgRendering_RenderingProblemReport__IoFns.inputFn = (ILU_C_InputFn) _NgRendering_RenderingProblemReport__Input;
  _NgRendering_RenderingProblemReport__IoFns.outFn = (ILU_C_OutputFn) _NgRendering_RenderingProblemReport__Output;
  _NgRendering_RenderingProblemReport__IoFns.sizeFn = (ILU_C_SizeFn) _NgRendering_RenderingProblemReport__SizeOf;
  _NgRendering_RenderingProblemReport__IoFns.freeFn = (ILU_C_FreeFn) NgRendering_RenderingProblemReport__Free;
  _ILU_C_RegisterIoFns (&_NgRendering_RenderingProblemReport__IoFns);

  _NgRendering_OptionalRendering__IoFns.inputFn = (ILU_C_InputFn) _NgRendering_OptionalRendering__Input;
  _NgRendering_OptionalRendering__IoFns.outFn = (ILU_C_OutputFn) _NgRendering_OptionalRendering__Output;
  _NgRendering_OptionalRendering__IoFns.sizeFn = (ILU_C_SizeFn) _NgRendering_OptionalRendering__SizeOf;
  _NgRendering_OptionalRendering__IoFns.freeFn = (ILU_C_FreeFn) NgRendering_OptionalRendering__Free;
  _ILU_C_RegisterIoFns (&_NgRendering_OptionalRendering__IoFns);

  _NgRendering_Rendering__IoFns.inputFn = (ILU_C_InputFn) _NgRendering_Rendering__Input;
  _NgRendering_Rendering__IoFns.outFn = (ILU_C_OutputFn) _NgRendering_Rendering__Output;
  _NgRendering_Rendering__IoFns.sizeFn = (ILU_C_SizeFn) _NgRendering_Rendering__SizeOf;
  _NgRendering_Rendering__IoFns.freeFn = (ILU_C_FreeFn) NgRendering_Rendering__Free;
  _ILU_C_RegisterIoFns (&_NgRendering_Rendering__IoFns);

  _NgRendering_RenderingChunk__IoFns.inputFn = (ILU_C_InputFn) _NgRendering_RenderingChunk__Input;
  _NgRendering_RenderingChunk__IoFns.outFn = (ILU_C_OutputFn) _NgRendering_RenderingChunk__Output;
  _NgRendering_RenderingChunk__IoFns.sizeFn = (ILU_C_SizeFn) _NgRendering_RenderingChunk__SizeOf;
  _NgRendering_RenderingChunk__IoFns.freeFn = (ILU_C_FreeFn) NgRendering_RenderingChunk__Free;
  _ILU_C_RegisterIoFns (&_NgRendering_RenderingChunk__IoFns);

  _NgRendering_RenderingContentBytes__IoFns.inputFn = (ILU_C_InputFn) _NgRendering_RenderingContentBytes__Input;
  _NgRendering_RenderingContentBytes__IoFns.outFn = (ILU_C_OutputFn) _NgRendering_RenderingContentBytes__Output;
  _NgRendering_RenderingContentBytes__IoFns.sizeFn = (ILU_C_SizeFn) _NgRendering_RenderingContentBytes__SizeOf;
  _NgRendering_RenderingContentBytes__IoFns.freeFn = (ILU_C_FreeFn) NgRendering_RenderingContentBytes__Free;
  _ILU_C_RegisterIoFns (&_NgRendering_RenderingContentBytes__IoFns);

  _NgRendering_RenderingPreferences__IoFns.inputFn = (ILU_C_InputFn) _NgRendering_RenderingPreferences__Input;
  _NgRendering_RenderingPreferences__IoFns.outFn = (ILU_C_OutputFn) _NgRendering_RenderingPreferences__Output;
  _NgRendering_RenderingPreferences__IoFns.sizeFn = (ILU_C_SizeFn) _NgRendering_RenderingPreferences__SizeOf;
  _NgRendering_RenderingPreferences__IoFns.freeFn = (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free;
  _ILU_C_RegisterIoFns (&_NgRendering_RenderingPreferences__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

