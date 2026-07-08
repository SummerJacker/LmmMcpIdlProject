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

#include <iluntrnl.h>

#include "NgRendering.h"

static ILU_C_Class _NgRendering_PutableRenderable__DefaultClass = 0;

ILU_C_Class NgRendering_PutableRenderable__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgRendering_PutableRenderable__DefaultClass;
  _NgRendering_PutableRenderable__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _NgRendering_Renderable__DefaultClass = 0;

ILU_C_Class NgRendering_Renderable__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgRendering_Renderable__DefaultClass;
  _NgRendering_Renderable__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _NgRendering_RenderingSink__DefaultClass = 0;

ILU_C_Class NgRendering_RenderingSink__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgRendering_RenderingSink__DefaultClass;
  _NgRendering_RenderingSink__DefaultClass = c;
  return oldclass;
}

static void _NgRendering_PutableRenderable_PutRendering__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_PutableRenderable _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_Rendering renderingInput = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgRendering_RenderingPreferences__SizeOf, (ILU_C_OutputFn) _NgRendering_RenderingPreferences__Output, 0, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_PutableRenderable) _ILU_C_InputObject (_call, _NgRendering_PutableRenderable__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_Rendering__Input (_call, &renderingInput,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgRendering_PutableRenderable_PutRendering (_h, &renderingInput, &_status);
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
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
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
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      NgRendering_Rendering__Free (&renderingInput);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_Renderable_GetAvailableRenderings__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_Renderable _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingPreferences* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_Renderable) _ILU_C_InputObject (_call, _NgRendering_Renderable__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = NgRendering_Renderable_GetAvailableRenderings (_h, &_status);
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
        _size += _NgRendering_RenderingPreferences__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _NgRendering_RenderingPreferences__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        NgRendering_RenderingPreferences__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_Renderable_GetRendering__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_Renderable _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingPreferences renderingPreferences = {0};
  NgCache_OptionalRequestCacheControl requestCacheInfo = {0};
  NgCache_OptionalResponseCacheControl responseCacheInfo = {0};
  NgRendering_Rendering* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgRendering_RenderingPreferences__SizeOf, (ILU_C_OutputFn) _NgRendering_RenderingPreferences__Output, 0, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_Renderable) _ILU_C_InputObject (_call, _NgRendering_Renderable__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingPreferences__Input (_call, &renderingPreferences,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_OptionalRequestCacheControl__Input (_call, &requestCacheInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = NgRendering_Renderable_GetRendering (_h, &renderingPreferences, requestCacheInfo, &responseCacheInfo, &_status);
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
      NgRendering_RenderingPreferences__Free (&renderingPreferences);
      NgCache_OptionalRequestCacheControl__Free (&requestCacheInfo);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_Renderable_SendRendering__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_Renderable _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingPreferences renderingPreferences = {0};
  NgCache_OptionalRequestCacheControl requestCacheInfo = {0};
  NgRendering_RenderingSink renderSink = {0};
  NgBasic_OptionalCardinal suggestedChunkSize = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_Renderable) _ILU_C_InputObject (_call, _NgRendering_Renderable__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingPreferences__Input (_call, &renderingPreferences,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_OptionalRequestCacheControl__Input (_call, &requestCacheInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&renderSink = _ILU_C_InputObject (_call, _NgRendering_RenderingSink__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalCardinal__Input (_call, &suggestedChunkSize,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgRendering_Renderable_SendRendering (_h, &renderingPreferences, requestCacheInfo, renderSink, suggestedChunkSize, &_status);
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
      NgRendering_RenderingPreferences__Free (&renderingPreferences);
      NgCache_OptionalRequestCacheControl__Free (&requestCacheInfo);
      NgRendering_RenderingSink__Free (&renderSink);
      NgBasic_OptionalCardinal__Free (&suggestedChunkSize);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_Renderable_SendRenderingSynched__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_Renderable _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingPreferences renderingPreferences = {0};
  NgCache_OptionalRequestCacheControl requestCacheInfo = {0};
  NgRendering_RenderingSink renderSink = {0};
  NgBasic_OptionalCardinal suggestedChunkSize = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_Renderable) _ILU_C_InputObject (_call, _NgRendering_Renderable__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingPreferences__Input (_call, &renderingPreferences,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_OptionalRequestCacheControl__Input (_call, &requestCacheInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&renderSink = _ILU_C_InputObject (_call, _NgRendering_RenderingSink__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalCardinal__Input (_call, &suggestedChunkSize,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgRendering_Renderable_SendRenderingSynched (_h, &renderingPreferences, requestCacheInfo, renderSink, suggestedChunkSize, &_status);
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
      NgRendering_RenderingPreferences__Free (&renderingPreferences);
      NgCache_OptionalRequestCacheControl__Free (&requestCacheInfo);
      NgRendering_RenderingSink__Free (&renderSink);
      NgBasic_OptionalCardinal__Free (&suggestedChunkSize);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_RenderingSink_RegisterResponseCacheControl__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_RenderingSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgCache_OptionalResponseCacheControl responseCacheInfo = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_RenderingSink) _ILU_C_InputObject (_call, _NgRendering_RenderingSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgCache_OptionalResponseCacheControl__Input (_call, &responseCacheInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgRendering_RenderingSink_RegisterResponseCacheControl (_h, responseCacheInfo, &_status);
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
      NgCache_OptionalResponseCacheControl__Free (&responseCacheInfo);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_RenderingSink_RenderingProblem__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_RenderingSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingProblemReport report = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_RenderingSink) _ILU_C_InputObject (_call, _NgRendering_RenderingSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingProblemReport__Input (_call, &report,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgRendering_RenderingSink_RenderingProblem (_h, &report, &_status);
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
      NgRendering_RenderingProblemReport__Free (&report);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_RenderingSink_ReceiveRendering__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_RenderingSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_Rendering therendering = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_RenderingSink) _ILU_C_InputObject (_call, _NgRendering_RenderingSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_Rendering__Input (_call, &therendering,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgRendering_RenderingSink_ReceiveRendering (_h, &therendering, &_status);
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
      NgRendering_Rendering__Free (&therendering);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_RenderingSink_ReceiveRenderingChunk__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_RenderingSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingChunk thechunk = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_RenderingSink) _ILU_C_InputObject (_call, _NgRendering_RenderingSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingChunk__Input (_call, &thechunk,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgRendering_RenderingSink_ReceiveRenderingChunk (_h, &thechunk, &_status);
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
      NgRendering_RenderingChunk__Free (&thechunk);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgRendering_RenderingSink_Resynchronize__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgRendering_RenderingSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgBasic_OptionalCardinal _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgRendering_RenderingSink) _ILU_C_InputObject (_call, _NgRendering_RenderingSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = NgRendering_RenderingSink_Resynchronize (_h, &_status);
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
        _size += _NgBasic_OptionalCardinal__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _NgBasic_OptionalCardinal__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        NgBasic_OptionalCardinal__Free (&_retvalue);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT NgRendering_PutableRenderable__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgRendering_PutableRenderable__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgRendering_PutableRenderable__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgRendering_PutableRenderable__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgRendering_PutableRenderable__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgRendering_PutableRenderable__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgRendering_PutableRenderable__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgRendering_PutableRenderable__DefaultClass != ILU_NIL)
    _NgRendering_PutableRenderable__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT NgRendering_Renderable__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgRendering_Renderable__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgRendering_Renderable__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgRendering_Renderable__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgRendering_Renderable__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgRendering_Renderable__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgRendering_Renderable__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgRendering_Renderable__DefaultClass != ILU_NIL)
    _NgRendering_Renderable__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT NgRendering_RenderingSink__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgRendering_RenderingSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgRendering_RenderingSink__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgRendering_RenderingSink__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgRendering_RenderingSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgRendering_RenderingSink__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgRendering_RenderingSink__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgRendering_RenderingSink__DefaultClass != ILU_NIL)
    _NgRendering_RenderingSink__DefaultClass->ilucc_finalize = f;
}

void NgRendering__InitializeServer(void)
{
  extern void _NgRendering__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _NgRendering__GeneralInitialization ();
  _NgRendering_PutableRenderable__DefaultClass = NgRendering_PutableRenderable__MakeClass(
    server_NgRendering_PutableRenderable_PutRendering,
    server_NgRendering_PutableRenderable_GetAvailableRenderings,
    server_NgRendering_PutableRenderable_GetRendering,
    server_NgRendering_PutableRenderable_SendRendering,
    server_NgRendering_PutableRenderable_SendRenderingSynched,
    server_NgRendering_PutableRenderable_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );
  _NgRendering_Renderable__DefaultClass = NgRendering_Renderable__MakeClass(
    server_NgRendering_Renderable_GetAvailableRenderings,
    server_NgRendering_Renderable_GetRendering,
    server_NgRendering_Renderable_SendRendering,
    server_NgRendering_Renderable_SendRenderingSynched,
    server_NgRendering_Renderable_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );
  _NgRendering_RenderingSink__DefaultClass = NgRendering_RenderingSink__MakeClass(
    server_NgRendering_RenderingSink_RegisterResponseCacheControl,
    server_NgRendering_RenderingSink_RenderingProblem,
    server_NgRendering_RenderingSink_ReceiveRendering,
    server_NgRendering_RenderingSink_ReceiveRenderingChunk,
    server_NgRendering_RenderingSink_Resynchronize,
    server_NgRendering_RenderingSink_RegisterSourceControl,
    server_NgRendering_RenderingSink_Done,
    server_NgRendering_RenderingSink_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_NgRendering_PutableRenderable__ILUType->cl_methods[0], (ilu_StubProc) _NgRendering_PutableRenderable_PutRendering__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_NgRendering_Renderable__ILUType->cl_methods[0], (ilu_StubProc) _NgRendering_Renderable_GetAvailableRenderings__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgRendering_Renderable__ILUType->cl_methods[1], (ilu_StubProc) _NgRendering_Renderable_GetRendering__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgRendering_Renderable__ILUType->cl_methods[2], (ilu_StubProc) _NgRendering_Renderable_SendRendering__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgRendering_Renderable__ILUType->cl_methods[3], (ilu_StubProc) _NgRendering_Renderable_SendRenderingSynched__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_NgRendering_RenderingSink__ILUType->cl_methods[0], (ilu_StubProc) _NgRendering_RenderingSink_RegisterResponseCacheControl__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgRendering_RenderingSink__ILUType->cl_methods[1], (ilu_StubProc) _NgRendering_RenderingSink_RenderingProblem__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgRendering_RenderingSink__ILUType->cl_methods[2], (ilu_StubProc) _NgRendering_RenderingSink_ReceiveRendering__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgRendering_RenderingSink__ILUType->cl_methods[3], (ilu_StubProc) _NgRendering_RenderingSink_ReceiveRenderingChunk__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgRendering_RenderingSink__ILUType->cl_methods[4], (ilu_StubProc) _NgRendering_RenderingSink_Resynchronize__truestub, _ILU_C_LanguageIndex);;
}

