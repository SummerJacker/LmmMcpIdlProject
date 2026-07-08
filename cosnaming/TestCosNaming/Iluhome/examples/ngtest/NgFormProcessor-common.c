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

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "NgFormProcessor.h"

ilu_Class _NgFormProcessor_FormProcessor__ILUType = NULL;
ilu_Class _NgFormProcessor_ProcessedFormSink__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_FormProcessor__IoFns = { ilu_object_tk, "ilut:pKWFaQEx78q1ToefmjSoVW0mrne", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_ProcessedFormSink__IoFns = { ilu_object_tk, "ilut:b7g4WIAt4oLUHLfZHwsLIGO+2J4", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_OptionalFormProblemReport__IoFns = { ilu_optional_tk, "ilut:ocdfE949BT5ifrc9it5kFhnHqsD", { sizeof(NgFormProcessor_OptionalFormProblemReport) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_FormProblemReport__IoFns = { ilu_union_tk, "ilut:ik-ZTBDPNoZOzA7HGpax9tvz4vv", { sizeof(NgFormProcessor_FormProblemReport) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_FormInputElementSequence__IoFns = { ilu_sequence_tk, "ilut:hWtNxxvpajCI6Lq51a0s9mnUrsF", { sizeof(NgFormProcessor_FormInputElementSequence) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class NgFormProcessor_FormProcessor__MakeClass(
  NgRendering_Rendering* (*NgFormProcessor_FormProcessor_ProcessForm__Impl)
     (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgFormProcessor_FormProcessor_SendFormReply__Impl)
     (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status),
  void (*NgFormProcessor_FormProcessor_SendFormReplySynched__Impl)
     (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgFormProcessor_FormProcessor _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _NgFormProcessor_FormProcessor__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgFormProcessor_FormProcessor_ProcessForm__Impl;
  method_block[1] = (_ILU_C_Method) NgFormProcessor_FormProcessor_SendFormReply__Impl;
  method_block[2] = (_ILU_C_Method) NgFormProcessor_FormProcessor_SendFormReplySynched__Impl;

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
ILU_C_Class NgFormProcessor_ProcessedFormSink__MakeClass(
  void (*NgFormProcessor_ProcessedFormSink_FormProblem__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgFormProcessor_FormProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RegisterResponseCacheControl__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RenderingProblem__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRendering__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRenderingChunk__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status),
  NgBasic_OptionalCardinal (*NgRendering_RenderingSink_Resynchronize__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _NgFormProcessor_ProcessedFormSink__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) NgFormProcessor_ProcessedFormSink_FormProblem__Impl;

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
NgRendering_Rendering* NgFormProcessor_FormProcessor_ProcessForm (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status)
{
  NgRendering_Rendering* (*_f)(NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgCache_OptionalResponseCacheControl*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    NgRendering_Rendering* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (NgRendering_Rendering* (*)(NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgCache_OptionalResponseCacheControl*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgFormProcessor_FormProcessor__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, formEntries, responseCacheInfo, _status));
}

void NgFormProcessor_FormProcessor_SendFormReply (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgFormProcessor_ProcessedFormSink, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgFormProcessor_ProcessedFormSink, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgFormProcessor_FormProcessor__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, formEntries, formSink, _status);
}

void NgFormProcessor_FormProcessor_SendFormReplySynched (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgFormProcessor_ProcessedFormSink, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgFormProcessor_ProcessedFormSink, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgFormProcessor_FormProcessor__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, formEntries, formSink, _status);
}

void NgFormProcessor_ProcessedFormSink_FormProblem (NgFormProcessor_ProcessedFormSink _handle, NgFormProcessor_FormProblemReport* report, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(NgFormProcessor_ProcessedFormSink, NgFormProcessor_FormProblemReport*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(NgFormProcessor_ProcessedFormSink, NgFormProcessor_FormProblemReport*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _NgFormProcessor_ProcessedFormSink__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, report, _status);
}

void NgFormProcessor_FormProcessor__SetUserData (NgFormProcessor_FormProcessor self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgFormProcessor_FormProcessor__GetUserData (NgFormProcessor_FormProcessor self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void NgFormProcessor_ProcessedFormSink__SetUserData (NgFormProcessor_ProcessedFormSink self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *NgFormProcessor_ProcessedFormSink__GetUserData (NgFormProcessor_ProcessedFormSink self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _NgFormProcessor__Exception_InvalidFormEntries = ILU_NIL;
#include <stdarg.h>

void NgFormProcessor__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_NgFormProcessor_InvalidFormEntries) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_NameSequence));
    *(NgBasic_NameSequence*)stat->ptr = *va_arg (ap, NgBasic_NameSequence*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_NameSequence__Free;
  }
  else if (stat->returnCode == ex_NgBasic_WouldBlock) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else if (stat->returnCode == ex_NgBasic_Conflict) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else if (stat->returnCode == ex_NgBasic_ObjectNotExist) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (NgBasic_ExceptionInformation));
    *(NgBasic_ExceptionInformation*)stat->ptr = *va_arg (ap, NgBasic_ExceptionInformation*);
    stat->freeRoutine = (void (*) (void *)) NgBasic_ExceptionInformation__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to NgFormProcessor__BindExceptionValue");
  va_end (ap);
}

void NgFormProcessor_FormProcessor__Free (NgFormProcessor_FormProcessor* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgFormProcessor_FormProcessor */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgFormProcessor_FormProcessor *CORBA_sequence_NgFormProcessor_FormProcessor_allocbuf (CORBA_unsigned_long _count)
{
  NgFormProcessor_FormProcessor *_p;
  CORBA_unsigned_long _size = sizeof(NgFormProcessor_FormProcessor) * _count;

  if ((_p = (NgFormProcessor_FormProcessor *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void NgFormProcessor_ProcessedFormSink__Free (NgFormProcessor_ProcessedFormSink* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgFormProcessor_ProcessedFormSink */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

NgFormProcessor_ProcessedFormSink *CORBA_sequence_NgFormProcessor_ProcessedFormSink_allocbuf (CORBA_unsigned_long _count)
{
  NgFormProcessor_ProcessedFormSink *_p;
  CORBA_unsigned_long _size = sizeof(NgFormProcessor_ProcessedFormSink) * _count;

  if ((_p = (NgFormProcessor_ProcessedFormSink *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgFormProcessor_OptionalFormProblemReport* _NgFormProcessor_OptionalFormProblemReport__Input (ilu_Call _call, NgFormProcessor_OptionalFormProblemReport* _ref, ilu_Error *_err)
{
  NgFormProcessor_OptionalFormProblemReport* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(NgFormProcessor_OptionalFormProblemReport), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgFormProcessor_OptionalFormProblemReport *) ilu_MallocE (sizeof (NgFormProcessor_OptionalFormProblemReport), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(NgFormProcessor_OptionalFormProblemReport));
  };
  if (_present)
    {
    *_val = (NgFormProcessor_FormProblemReport*) ilu_MallocE (sizeof (NgFormProcessor_FormProblemReport), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(NgFormProcessor_FormProblemReport));
      (void) _NgFormProcessor_FormProblemReport__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _NgFormProcessor_OptionalFormProblemReport__Output (ilu_Call _call, NgFormProcessor_OptionalFormProblemReport _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgFormProcessor_OptionalFormProblemReport), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _NgFormProcessor_FormProblemReport__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _NgFormProcessor_OptionalFormProblemReport__SizeOf (ilu_Call _call, NgFormProcessor_OptionalFormProblemReport _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(NgFormProcessor_OptionalFormProblemReport), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _NgFormProcessor_FormProblemReport__SizeOf (_call, &*_val, _err);
  return size;
}

void NgFormProcessor_OptionalFormProblemReport__Free (NgFormProcessor_OptionalFormProblemReport* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgFormProcessor_OptionalFormProblemReport */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is NgFormProcessor_FormProblemReport */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    NgFormProcessor_FormProblemReport__Free (&**_val);
    ilu_free(*_val);
  }
}

NgFormProcessor_OptionalFormProblemReport *CORBA_sequence_NgFormProcessor_OptionalFormProblemReport_allocbuf (CORBA_unsigned_long _count)
{
  NgFormProcessor_OptionalFormProblemReport *_p;
  CORBA_unsigned_long _size = sizeof(NgFormProcessor_OptionalFormProblemReport) * _count;

  if ((_p = (NgFormProcessor_OptionalFormProblemReport *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgFormProcessor_OptionalFormProblemReport* NgFormProcessor_OptionalFormProblemReport__alloc ()
{
  return ((NgFormProcessor_OptionalFormProblemReport*) CORBA_sequence_NgFormProcessor_OptionalFormProblemReport_allocbuf(1));
}

NgFormProcessor_FormProblemReport* _NgFormProcessor_FormProblemReport__Input (ilu_Call _call, NgFormProcessor_FormProblemReport* _ref, ilu_Error *_err)
{
  NgFormProcessor_FormProblemReport* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgFormProcessor_FormProblemReport), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (NgFormProcessor_FormProblemReport*) ilu_MallocE(sizeof (NgFormProcessor_FormProblemReport), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(NgFormProcessor_FormProblemReport));
  };
  switch (tag) {
    case 0:
      (void) _NgBasic_NameSequence__Input (_call, &_val->_u.invalidEntries,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      (void) _NgBasic_ExceptionInformation__Input (_call, &_val->_u.conflict,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      (void) _NgBasic_ExceptionInformation__Input (_call, &_val->_u.objectNotExist,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgFormProcessor_FormProblemReport__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
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

void _NgFormProcessor_FormProblemReport__Output (ilu_Call _call, NgFormProcessor_FormProblemReport* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgFormProcessor_FormProblemReport), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _NgBasic_NameSequence__Output(_call, &_val->_u.invalidEntries, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _NgBasic_ExceptionInformation__Output(_call, &_val->_u.conflict, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      _NgBasic_ExceptionInformation__Output(_call, &_val->_u.objectNotExist, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_NgFormProcessor_FormProblemReport__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _NgFormProcessor_FormProblemReport__SizeOf (ilu_Call _call, NgFormProcessor_FormProblemReport* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(NgFormProcessor_FormProblemReport), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _NgBasic_NameSequence__SizeOf (_call, &_val->_u.invalidEntries, _err);
      break;
    case 1:
      size += _NgBasic_ExceptionInformation__SizeOf (_call, &_val->_u.conflict, _err);
      break;
    case 2:
      size += _NgBasic_ExceptionInformation__SizeOf (_call, &_val->_u.objectNotExist, _err);
      break;
    default:
      fprintf (stderr, "_NgFormProcessor_FormProblemReport__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgFormProcessor_FormProblemReport__Free (NgFormProcessor_FormProblemReport* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgFormProcessor_FormProblemReport */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      NgBasic_NameSequence__Free (&_val->_u.invalidEntries);
      break;
    case 1:
      NgBasic_ExceptionInformation__Free (&_val->_u.conflict);
      break;
    case 2:
      NgBasic_ExceptionInformation__Free (&_val->_u.objectNotExist);
      break;
    default:
      fprintf (stderr, "NgFormProcessor_FormProblemReport__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

NgFormProcessor_FormProblemReport *CORBA_sequence_NgFormProcessor_FormProblemReport_allocbuf (CORBA_unsigned_long _count)
{
  NgFormProcessor_FormProblemReport *_p;
  CORBA_unsigned_long _size = sizeof(NgFormProcessor_FormProblemReport) * _count;

  if ((_p = (NgFormProcessor_FormProblemReport *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgFormProcessor_FormProblemReport* NgFormProcessor_FormProblemReport__alloc ()
{
  return ((NgFormProcessor_FormProblemReport*) CORBA_sequence_NgFormProcessor_FormProblemReport_allocbuf(1));
}

NgFormProcessor_FormInputElementSequence* _NgFormProcessor_FormInputElementSequence__Input (ilu_Call _call, NgFormProcessor_FormInputElementSequence* _ref, ilu_Error *_err)
{
  NgFormProcessor_FormInputElementSequence* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  NgBasic_NameValuePair _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (NgFormProcessor_FormInputElementSequence*) ilu_MallocE(sizeof (NgFormProcessor_FormInputElementSequence), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  NgFormProcessor_FormInputElementSequence_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(NgFormProcessor_FormInputElementSequence), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _count, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(NgBasic_NameValuePair), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _NgBasic_NameValuePair__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      NgFormProcessor_FormInputElementSequence_Append (_val, &_tmp, _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  ilu_EndSequence (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _NgFormProcessor_FormInputElementSequence__Output (ilu_Call _call, NgFormProcessor_FormInputElementSequence* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgFormProcessor_FormInputElementSequence), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _val->_length, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(NgBasic_NameValuePair), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    NgBasic_NameValuePair *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _NgBasic_NameValuePair__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _NgFormProcessor_FormInputElementSequence__SizeOf (ilu_Call _call, NgFormProcessor_FormInputElementSequence* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(NgFormProcessor_FormInputElementSequence), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(NgBasic_NameValuePair), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(NgFormProcessor_FormInputElement), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    NgFormProcessor_FormInputElement *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _NgBasic_NameValuePair__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void NgFormProcessor_FormInputElementSequence__Free (NgFormProcessor_FormInputElementSequence* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a NgFormProcessor_FormInputElementSequence */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(NgBasic_NameValuePair)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(NgBasic_NameValuePair)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(NgBasic_NameValuePair))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          NgBasic_NameValuePair__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK NgFormProcessor_FormInputElementSequence__Free (NgFormProcessor_FormInputElementSequence* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

NgFormProcessor_FormInputElementSequence *CORBA_sequence_NgFormProcessor_FormInputElementSequence_allocbuf (CORBA_unsigned_long _count)
{
  NgFormProcessor_FormInputElementSequence *_p;
  CORBA_unsigned_long _size = sizeof(NgFormProcessor_FormInputElementSequence) * _count;

  if ((_p = (NgFormProcessor_FormInputElementSequence *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

NgFormProcessor_FormInputElementSequence* NgFormProcessor_FormInputElementSequence__alloc ()
{
  return ((NgFormProcessor_FormInputElementSequence*) CORBA_sequence_NgFormProcessor_FormInputElementSequence_allocbuf(1));
}

void NgFormProcessor_FormInputElementSequence_Every (NgFormProcessor_FormInputElementSequence *h, void (*f)(NgFormProcessor_FormInputElement*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(NgFormProcessor_FormInputElement), (void *) data);
}

void NgFormProcessor_FormInputElementSequence_Append (NgFormProcessor_FormInputElementSequence *h, NgFormProcessor_FormInputElement* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgFormProcessor_FormInputElement), err);
}

void NgFormProcessor_FormInputElementSequence_Push (NgFormProcessor_FormInputElementSequence *h, NgFormProcessor_FormInputElement* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgFormProcessor_FormInputElement));
}

void NgFormProcessor_FormInputElementSequence_Pop (NgFormProcessor_FormInputElementSequence *h, NgFormProcessor_FormInputElement* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(NgFormProcessor_FormInputElement));
}

CORBA_unsigned_long NgFormProcessor_FormInputElementSequence_Length (NgFormProcessor_FormInputElementSequence *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

NgFormProcessor_FormInputElement * NgFormProcessor_FormInputElementSequence_Nth (NgFormProcessor_FormInputElementSequence *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

NgFormProcessor_FormInputElementSequence * NgFormProcessor_FormInputElementSequence_Create (CORBA_unsigned_long sz, NgFormProcessor_FormInputElement* p)
{
  NgFormProcessor_FormInputElementSequence *s;
  s = (NgFormProcessor_FormInputElementSequence *) ilu_malloc(sizeof(NgFormProcessor_FormInputElementSequence));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(NgFormProcessor_FormInputElementSequence)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((NgFormProcessor_FormInputElement *) ilu_malloc(sz * sizeof(NgFormProcessor_FormInputElement))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(NgFormProcessor_FormInputElement));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void NgFormProcessor_FormInputElementSequence_Init (NgFormProcessor_FormInputElementSequence *s, CORBA_unsigned_long sz, NgFormProcessor_FormInputElement* p)
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
    s->_buffer = (NgFormProcessor_FormInputElement *) ilu_malloc (sz * sizeof (NgFormProcessor_FormInputElement));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(NgFormProcessor_FormInputElement)); }}
  else
    s->_buffer = p;
  return;
}

void _NgFormProcessor__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("NgFormProcessor", "2.0beta1", "v2 (2.0beta1)");
  _NgBasic__GeneralInitialization();
  _IANA_Charsets_Registry__GeneralInitialization();
  _NgCache__GeneralInitialization();
  _NgRendering__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _NgFormProcessor__Exception_InvalidFormEntries = ilu_DefineException("NgFormProcessor", "InvalidFormEntries", "ilut:jnKRp54g57gOe7fPCulRE7vmvPc", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"ilut:jXXCK7f4rCxHnfnnFBPnx6xBGD3",
	NULL};
    cl = ilu_DefineObjectType("NgFormProcessor.FormProcessor",	/*name*/
	NULL,	/*no brand*/
	"ilut:pKWFaQEx78q1ToefmjSoVW0mrne",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	3,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _NgFormProcessor_FormProcessor__ILUType = cl;
  }
  { ilu_Exception	exns[4];
    exns[0] = ex_NgFormProcessor_InvalidFormEntries;
    exns[1] = ex_NgBasic_WouldBlock;
    exns[2] = ex_NgBasic_Conflict;
    exns[3] = ex_NgBasic_ObjectNotExist;
    m = ilu_DefineMethod(cl, 0,
	"ProcessForm",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	4,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:fehBMnipxhE3y19WLjzMv15h0+3",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "formEntries", ilu_FALSE, ilu_In, "ilut:hWtNxxvpajCI6Lq51a0s9mnUrsF", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "responseCacheInfo", ilu_FALSE, ilu_Out, "ilut:ndDitjkJSN2EudLTF5z4PXYSGiA", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"SendFormReply",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "formEntries", ilu_FALSE, ilu_In, "ilut:hWtNxxvpajCI6Lq51a0s9mnUrsF", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "formSink", ilu_FALSE, ilu_In, "ilut:b7g4WIAt4oLUHLfZHwsLIGO+2J4", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"SendFormReplySynched",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "formEntries", ilu_FALSE, ilu_In, "ilut:hWtNxxvpajCI6Lq51a0s9mnUrsF", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "formSink", ilu_FALSE, ilu_In, "ilut:b7g4WIAt4oLUHLfZHwsLIGO+2J4", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"ilut:m7HWvjCGEElnwD3KB9thODvbloa",
	NULL};
    cl = ilu_DefineObjectType("NgFormProcessor.ProcessedFormSink",	/*name*/
	NULL,	/*no brand*/
	"ilut:b7g4WIAt4oLUHLfZHwsLIGO+2J4",	/*uid*/
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
    _NgFormProcessor_ProcessedFormSink__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"FormProblem",	/*name*/
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
    ilu_DefineMethodArg (m, 0, "report", ilu_FALSE, ilu_In, "ilut:ik-ZTBDPNoZOzA7HGpax9tvz4vv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _NgFormProcessor_FormProcessor__IoFns.kernelType = ilu_RegisterObjectType("FormProcessor", "NgFormProcessor", "NG", "ilut:pKWFaQEx78q1ToefmjSoVW0mrne",
    _NgFormProcessor_FormProcessor__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgFormProcessor_ProcessedFormSink__IoFns.kernelType = ilu_RegisterObjectType("ProcessedFormSink", "NgFormProcessor", "NG", "ilut:b7g4WIAt4oLUHLfZHwsLIGO+2J4",
    _NgFormProcessor_ProcessedFormSink__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgFormProcessor_OptionalFormProblemReport__IoFns.kernelType = ilu_RegisterOptionalType("OptionalFormProblemReport", "NgFormProcessor", "NG", "ilut:ocdfE949BT5ifrc9it5kFhnHqsD",
    "ilut:ik-ZTBDPNoZOzA7HGpax9tvz4vv", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgFormProcessor_FormProblemReport__IoFns.kernelType = type = ilu_RegisterUnionType("FormProblemReport", "NgFormProcessor", "NG", "ilut:ik-ZTBDPNoZOzA7HGpax9tvz4vv",
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
      "invalidEntries", /* name of arm */
      "ilut:jnKRp54g57gOe7fPCulRE7vmvPc", /* arm type */
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
      "conflict", /* name of arm */
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
  ilu_RegisterAliasType("FormInputElementNames", "NgFormProcessor", "NG", "ilut:jnKRp54g57gOe7fPCulRE7vmvPc",
    "ilut:jnKRp54g57gOe7fPCulRE7vmvPc",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _NgFormProcessor_FormInputElementSequence__IoFns.kernelType = ilu_RegisterSequenceType("FormInputElementSequence", "NgFormProcessor", "NG", "ilut:hWtNxxvpajCI6Lq51a0s9mnUrsF",
    "ilut:llyaclLXkJ5rS7qiIv4Fpupayvw",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("FormInputElement", "NgFormProcessor", "NG", "ilut:llyaclLXkJ5rS7qiIv4Fpupayvw",
    "ilut:llyaclLXkJ5rS7qiIv4Fpupayvw",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _NgFormProcessor_FormProcessor__IoFns.properties.object_class = _NgFormProcessor_FormProcessor__ILUType;
  _ILU_C_RegisterIoFns (&_NgFormProcessor_FormProcessor__IoFns);

  _NgFormProcessor_ProcessedFormSink__IoFns.properties.object_class = _NgFormProcessor_ProcessedFormSink__ILUType;
  _ILU_C_RegisterIoFns (&_NgFormProcessor_ProcessedFormSink__IoFns);

  _NgFormProcessor_OptionalFormProblemReport__IoFns.inputFn = (ILU_C_InputFn) _NgFormProcessor_OptionalFormProblemReport__Input;
  _NgFormProcessor_OptionalFormProblemReport__IoFns.outFn = (ILU_C_OutputFn) _NgFormProcessor_OptionalFormProblemReport__Output;
  _NgFormProcessor_OptionalFormProblemReport__IoFns.sizeFn = (ILU_C_SizeFn) _NgFormProcessor_OptionalFormProblemReport__SizeOf;
  _NgFormProcessor_OptionalFormProblemReport__IoFns.freeFn = (ILU_C_FreeFn) NgFormProcessor_OptionalFormProblemReport__Free;
  _ILU_C_RegisterIoFns (&_NgFormProcessor_OptionalFormProblemReport__IoFns);

  _NgFormProcessor_FormProblemReport__IoFns.inputFn = (ILU_C_InputFn) _NgFormProcessor_FormProblemReport__Input;
  _NgFormProcessor_FormProblemReport__IoFns.outFn = (ILU_C_OutputFn) _NgFormProcessor_FormProblemReport__Output;
  _NgFormProcessor_FormProblemReport__IoFns.sizeFn = (ILU_C_SizeFn) _NgFormProcessor_FormProblemReport__SizeOf;
  _NgFormProcessor_FormProblemReport__IoFns.freeFn = (ILU_C_FreeFn) NgFormProcessor_FormProblemReport__Free;
  _ILU_C_RegisterIoFns (&_NgFormProcessor_FormProblemReport__IoFns);

  _NgFormProcessor_FormInputElementSequence__IoFns.inputFn = (ILU_C_InputFn) _NgFormProcessor_FormInputElementSequence__Input;
  _NgFormProcessor_FormInputElementSequence__IoFns.outFn = (ILU_C_OutputFn) _NgFormProcessor_FormInputElementSequence__Output;
  _NgFormProcessor_FormInputElementSequence__IoFns.sizeFn = (ILU_C_SizeFn) _NgFormProcessor_FormInputElementSequence__SizeOf;
  _NgFormProcessor_FormInputElementSequence__IoFns.freeFn = (ILU_C_FreeFn) NgFormProcessor_FormInputElementSequence__Free;
  _ILU_C_RegisterIoFns (&_NgFormProcessor_FormInputElementSequence__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

