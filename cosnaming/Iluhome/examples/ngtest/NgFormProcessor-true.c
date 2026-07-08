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

#include <iluntrnl.h>

#include "NgFormProcessor.h"

static ILU_C_Class _NgFormProcessor_FormProcessor__DefaultClass = 0;

ILU_C_Class NgFormProcessor_FormProcessor__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgFormProcessor_FormProcessor__DefaultClass;
  _NgFormProcessor_FormProcessor__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _NgFormProcessor_ProcessedFormSink__DefaultClass = 0;

ILU_C_Class NgFormProcessor_ProcessedFormSink__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgFormProcessor_ProcessedFormSink__DefaultClass;
  _NgFormProcessor_ProcessedFormSink__DefaultClass = c;
  return oldclass;
}

static void _NgFormProcessor_FormProcessor_ProcessForm__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgFormProcessor_FormProcessor _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgFormProcessor_FormInputElementSequence formEntries = {0};
  NgCache_OptionalResponseCacheControl responseCacheInfo = {0};
  NgRendering_Rendering* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_NameSequence__SizeOf, (ILU_C_OutputFn) _NgBasic_NameSequence__Output, 0, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgFormProcessor_FormProcessor) _ILU_C_InputObject (_call, _NgFormProcessor_FormProcessor__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgFormProcessor_FormInputElementSequence__Input (_call, &formEntries,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = NgFormProcessor_FormProcessor_ProcessForm (_h, &formEntries, &responseCacheInfo, &_status);
    _ILU_C_SetCallerContext(ILU_NIL);
    _state = 6;
    /* check for errors */
    if (_status.returnCode == ILU_NIL) {
      ilu_cardinal _size = 0;
      if (ilu_CallNeedsSizing(_call)) {
      /* add by lzm 20080614. */
      /* Add this code to avoid crash when client disconnect with server again. */
		ilu_Connection  conn = ilu_ConnectionOfCall(_call);
		if ( NIL != conn )
			if ( conn->co_closed ) goto errexit;
      /* end of add codes */
        _size = ilu_BeginSizingReply(_call, ilu_TRUE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _NgRendering_Rendering__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _NgCache_OptionalResponseCacheControl__SizeOf (_call, responseCacheInfo, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _NgRendering_Rendering__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _NgCache_OptionalResponseCacheControl__Output(_call, responseCacheInfo, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (! _ILU_C_FinishReply (_call, _err)) goto errexit;
    }
    else {
      _ILU_C_SendException (_call, _evec, &_status, _err);
      if (ILU_ERRNOK(*_err)) goto errexit;
    }
  }

marshalError:
errexit:
  _ILU_C_FinishServingCall(_call, _err);
  switch (_state) {
    case 6: /* after true call */
      if (_status.returnCode == ILU_NIL) {
        NgRendering_Rendering__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
        NgCache_OptionalResponseCacheControl__Free (&responseCacheInfo);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      NgFormProcessor_FormInputElementSequence__Free (&formEntries);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgFormProcessor_FormProcessor_SendFormReply__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgFormProcessor_FormProcessor _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgFormProcessor_FormInputElementSequence formEntries = {0};
  NgFormProcessor_ProcessedFormSink formSink = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgFormProcessor_FormProcessor) _ILU_C_InputObject (_call, _NgFormProcessor_FormProcessor__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgFormProcessor_FormInputElementSequence__Input (_call, &formEntries,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&formSink = _ILU_C_InputObject (_call, _NgFormProcessor_ProcessedFormSink__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgFormProcessor_FormProcessor_SendFormReply (_h, &formEntries, formSink, &_status);
    _ILU_C_SetCallerContext(ILU_NIL);
    _state = 6;
    /* asynchronous method -- no reply */
  }
  if (!_ILU_C_NoReply(_call, _err)) goto errexit;

marshalError:
errexit:
  _ILU_C_FinishServingCall(_call, _err);
  switch (_state) {
    case 6: /* after true call */
      if (_status.returnCode == ILU_NIL) {
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      NgFormProcessor_FormInputElementSequence__Free (&formEntries);
      NgFormProcessor_ProcessedFormSink__Free (&formSink);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgFormProcessor_FormProcessor_SendFormReplySynched__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgFormProcessor_FormProcessor _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgFormProcessor_FormInputElementSequence formEntries = {0};
  NgFormProcessor_ProcessedFormSink formSink = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgFormProcessor_FormProcessor) _ILU_C_InputObject (_call, _NgFormProcessor_FormProcessor__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgFormProcessor_FormInputElementSequence__Input (_call, &formEntries,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&formSink = _ILU_C_InputObject (_call, _NgFormProcessor_ProcessedFormSink__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgFormProcessor_FormProcessor_SendFormReplySynched (_h, &formEntries, formSink, &_status);
    _ILU_C_SetCallerContext(ILU_NIL);
    _state = 6;
    /* check for errors */
    if (_status.returnCode == ILU_NIL) {
      ilu_cardinal _size = 0;
      if (ilu_CallNeedsSizing(_call)) {
      /* add by lzm 20080614. */
      /* Add this code to avoid crash when client disconnect with server again. */
		ilu_Connection  conn = ilu_ConnectionOfCall(_call);
		if ( NIL != conn )
			if ( conn->co_closed ) goto errexit;
      /* end of add codes */
        _size = ilu_BeginSizingReply(_call, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      if (! _ILU_C_FinishReply (_call, _err)) goto errexit;
    }
    else {
      (void) ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_some_raise, 6);
    }
  }

marshalError:
errexit:
  _ILU_C_FinishServingCall(_call, _err);
  switch (_state) {
    case 6: /* after true call */
      if (_status.returnCode == ILU_NIL) {
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      NgFormProcessor_FormInputElementSequence__Free (&formEntries);
      NgFormProcessor_ProcessedFormSink__Free (&formSink);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgFormProcessor_ProcessedFormSink_FormProblem__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgFormProcessor_ProcessedFormSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgFormProcessor_FormProblemReport report = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgFormProcessor_ProcessedFormSink) _ILU_C_InputObject (_call, _NgFormProcessor_ProcessedFormSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgFormProcessor_FormProblemReport__Input (_call, &report,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgFormProcessor_ProcessedFormSink_FormProblem (_h, &report, &_status);
    _ILU_C_SetCallerContext(ILU_NIL);
    _state = 6;
    /* asynchronous method -- no reply */
  }
  if (!_ILU_C_NoReply(_call, _err)) goto errexit;

marshalError:
errexit:
  _ILU_C_FinishServingCall(_call, _err);
  switch (_state) {
    case 6: /* after true call */
      if (_status.returnCode == ILU_NIL) {
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      NgFormProcessor_FormProblemReport__Free (&report);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT NgFormProcessor_FormProcessor__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgFormProcessor_FormProcessor__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgFormProcessor_FormProcessor__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgFormProcessor_FormProcessor__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgFormProcessor_FormProcessor__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgFormProcessor_FormProcessor__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgFormProcessor_FormProcessor__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgFormProcessor_FormProcessor__DefaultClass != ILU_NIL)
    _NgFormProcessor_FormProcessor__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT NgFormProcessor_ProcessedFormSink__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgFormProcessor_ProcessedFormSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgFormProcessor_ProcessedFormSink__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgFormProcessor_ProcessedFormSink__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgFormProcessor_ProcessedFormSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgFormProcessor_ProcessedFormSink__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgFormProcessor_ProcessedFormSink__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgFormProcessor_ProcessedFormSink__DefaultClass != ILU_NIL)
    _NgFormProcessor_ProcessedFormSink__DefaultClass->ilucc_finalize = f;
}

void NgFormProcessor__InitializeServer(void)
{
  extern void _NgFormProcessor__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _NgFormProcessor__GeneralInitialization ();
  _NgFormProcessor_FormProcessor__DefaultClass = NgFormProcessor_FormProcessor__MakeClass(
    server_NgFormProcessor_FormProcessor_ProcessForm,
    server_NgFormProcessor_FormProcessor_SendFormReply,
    server_NgFormProcessor_FormProcessor_SendFormReplySynched,
    server_NgFormProcessor_FormProcessor_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );
  _NgFormProcessor_ProcessedFormSink__DefaultClass = NgFormProcessor_ProcessedFormSink__MakeClass(
    server_NgFormProcessor_ProcessedFormSink_FormProblem,
    server_NgFormProcessor_ProcessedFormSink_RegisterResponseCacheControl,
    server_NgFormProcessor_ProcessedFormSink_RenderingProblem,
    server_NgFormProcessor_ProcessedFormSink_ReceiveRendering,
    server_NgFormProcessor_ProcessedFormSink_ReceiveRenderingChunk,
    server_NgFormProcessor_ProcessedFormSink_Resynchronize,
    server_NgFormProcessor_ProcessedFormSink_RegisterSourceControl,
    server_NgFormProcessor_ProcessedFormSink_Done,
    server_NgFormProcessor_ProcessedFormSink_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_NgFormProcessor_FormProcessor__ILUType->cl_methods[0], (ilu_StubProc) _NgFormProcessor_FormProcessor_ProcessForm__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgFormProcessor_FormProcessor__ILUType->cl_methods[1], (ilu_StubProc) _NgFormProcessor_FormProcessor_SendFormReply__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgFormProcessor_FormProcessor__ILUType->cl_methods[2], (ilu_StubProc) _NgFormProcessor_FormProcessor_SendFormReplySynched__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_NgFormProcessor_ProcessedFormSink__ILUType->cl_methods[0], (ilu_StubProc) _NgFormProcessor_ProcessedFormSink_FormProblem__truestub, _ILU_C_LanguageIndex);;
}

