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

#include <iluntrnl.h>

#include "NgDocument.h"

static ILU_C_Class _NgDocument_HTTPCompatibleWebDocument__DefaultClass = 0;

ILU_C_Class NgDocument_HTTPCompatibleWebDocument__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgDocument_HTTPCompatibleWebDocument__DefaultClass;
  _NgDocument_HTTPCompatibleWebDocument__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _NgDocument_PutableWebDocument__DefaultClass = 0;

ILU_C_Class NgDocument_PutableWebDocument__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgDocument_PutableWebDocument__DefaultClass;
  _NgDocument_PutableWebDocument__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _NgDocument_WebDocument__DefaultClass = 0;

ILU_C_Class NgDocument_WebDocument__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgDocument_WebDocument__DefaultClass;
  _NgDocument_WebDocument__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _NgDocument_RenderingAndPropertiesSink__DefaultClass = 0;

ILU_C_Class NgDocument_RenderingAndPropertiesSink__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgDocument_RenderingAndPropertiesSink__DefaultClass;
  _NgDocument_RenderingAndPropertiesSink__DefaultClass = c;
  return oldclass;
}

static void _NgDocument_PutableWebDocument_PutRenderingAndProperties__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgDocument_PutableWebDocument _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_Rendering renderingInput = {0};
  NgProperty_PropertyModificationSequence propertiesToSet = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgRendering_RenderingPreferences__SizeOf, (ILU_C_OutputFn) _NgRendering_RenderingPreferences__Output, 0, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_NameSequence__SizeOf, (ILU_C_OutputFn) _NgBasic_NameSequence__Output, 0, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgDocument_PutableWebDocument) _ILU_C_InputObject (_call, _NgDocument_PutableWebDocument__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_Rendering__Input (_call, &renderingInput,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgProperty_PropertyModificationSequence__Input (_call, &propertiesToSet,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgDocument_PutableWebDocument_PutRenderingAndProperties (_h, &renderingInput, &propertiesToSet, &_status);
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
      NgProperty_PropertyModificationSequence__Free (&propertiesToSet);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgDocument_WebDocument_GetRenderingAndProperties__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgDocument_WebDocument _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingPreferences renderingPreferences = {0};
  NgCache_OptionalRequestCacheControl requestCacheInfo = {0};
  NgCache_OptionalResponseCacheControl responseCacheInfo = {0};
  NgProperty_PropertyNames propertiesToGet = {0};
  NgProperty_PropertySequence* theproperties = {0};
  NgRendering_Rendering* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgRendering_RenderingPreferences__SizeOf, (ILU_C_OutputFn) _NgRendering_RenderingPreferences__Output, 0, (ILU_C_FreeFn) NgRendering_RenderingPreferences__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_NameSequence__SizeOf, (ILU_C_OutputFn) _NgBasic_NameSequence__Output, 0, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _NgBasic_ExceptionInformation__SizeOf, (ILU_C_OutputFn) _NgBasic_ExceptionInformation__Output, 0, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgDocument_WebDocument) _ILU_C_InputObject (_call, _NgDocument_WebDocument__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingPreferences__Input (_call, &renderingPreferences,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_OptionalRequestCacheControl__Input (_call, &requestCacheInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_NameSequence__Input (_call, &propertiesToGet,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = NgDocument_WebDocument_GetRenderingAndProperties (_h, &renderingPreferences, requestCacheInfo, &responseCacheInfo, &propertiesToGet, &theproperties, &_status);
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
        _size += _NgProperty_PropertySequence__SizeOf (_call, &*theproperties, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _NgRendering_Rendering__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _NgCache_OptionalResponseCacheControl__Output(_call, responseCacheInfo, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _NgProperty_PropertySequence__Output(_call, theproperties, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        NgProperty_PropertySequence__Free (theproperties);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(theproperties);
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
      NgBasic_NameSequence__Free (&propertiesToGet);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgDocument_WebDocument_SendRenderingAndProperties__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgDocument_WebDocument _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingPreferences renderingPreferences = {0};
  NgCache_OptionalRequestCacheControl requestCacheInfo = {0};
  NgProperty_PropertyNames propertiesToGet = {0};
  NgDocument_RenderingAndPropertiesSink renderPropSink = {0};
  NgBasic_OptionalCardinal suggestedChunkSize = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgDocument_WebDocument) _ILU_C_InputObject (_call, _NgDocument_WebDocument__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingPreferences__Input (_call, &renderingPreferences,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_OptionalRequestCacheControl__Input (_call, &requestCacheInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_NameSequence__Input (_call, &propertiesToGet,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&renderPropSink = _ILU_C_InputObject (_call, _NgDocument_RenderingAndPropertiesSink__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalCardinal__Input (_call, &suggestedChunkSize,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgDocument_WebDocument_SendRenderingAndProperties (_h, &renderingPreferences, requestCacheInfo, &propertiesToGet, renderPropSink, suggestedChunkSize, &_status);
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
      NgBasic_NameSequence__Free (&propertiesToGet);
      NgDocument_RenderingAndPropertiesSink__Free (&renderPropSink);
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

static void _NgDocument_WebDocument_SendRenderingAndPropertiesSynched__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgDocument_WebDocument _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgRendering_RenderingPreferences renderingPreferences = {0};
  NgCache_OptionalRequestCacheControl requestCacheInfo = {0};
  NgProperty_PropertyNames propertiesToGet = {0};
  NgDocument_RenderingAndPropertiesSink renderPropSink = {0};
  NgBasic_OptionalCardinal suggestedChunkSize = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgDocument_WebDocument) _ILU_C_InputObject (_call, _NgDocument_WebDocument__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgRendering_RenderingPreferences__Input (_call, &renderingPreferences,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgCache_OptionalRequestCacheControl__Input (_call, &requestCacheInfo,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_NameSequence__Input (_call, &propertiesToGet,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&renderPropSink = _ILU_C_InputObject (_call, _NgDocument_RenderingAndPropertiesSink__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _NgBasic_OptionalCardinal__Input (_call, &suggestedChunkSize,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgDocument_WebDocument_SendRenderingAndPropertiesSynched (_h, &renderingPreferences, requestCacheInfo, &propertiesToGet, renderPropSink, suggestedChunkSize, &_status);
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
      NgBasic_NameSequence__Free (&propertiesToGet);
      NgDocument_RenderingAndPropertiesSink__Free (&renderPropSink);
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

static void _NgDocument_RenderingAndPropertiesSink_PropertiesProblem__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgDocument_RenderingAndPropertiesSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgDocument_PropertiesProblemReport report = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgDocument_RenderingAndPropertiesSink) _ILU_C_InputObject (_call, _NgDocument_RenderingAndPropertiesSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgDocument_PropertiesProblemReport__Input (_call, &report,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgDocument_RenderingAndPropertiesSink_PropertiesProblem (_h, &report, &_status);
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
      NgDocument_PropertiesProblemReport__Free (&report);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgDocument_RenderingAndPropertiesSink_ReceiveProperties__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgDocument_RenderingAndPropertiesSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgProperty_PropertySequence theproperties = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgDocument_RenderingAndPropertiesSink) _ILU_C_InputObject (_call, _NgDocument_RenderingAndPropertiesSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgProperty_PropertySequence__Input (_call, &theproperties,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgDocument_RenderingAndPropertiesSink_ReceiveProperties (_h, &theproperties, &_status);
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
      NgProperty_PropertySequence__Free (&theproperties);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT NgDocument_HTTPCompatibleWebDocument__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgDocument_HTTPCompatibleWebDocument__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_HTTPCompatibleWebDocument__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgDocument_HTTPCompatibleWebDocument__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgDocument_HTTPCompatibleWebDocument__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_HTTPCompatibleWebDocument__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgDocument_HTTPCompatibleWebDocument__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgDocument_HTTPCompatibleWebDocument__DefaultClass != ILU_NIL)
    _NgDocument_HTTPCompatibleWebDocument__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT NgDocument_PutableWebDocument__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgDocument_PutableWebDocument__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_PutableWebDocument__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgDocument_PutableWebDocument__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgDocument_PutableWebDocument__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_PutableWebDocument__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgDocument_PutableWebDocument__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgDocument_PutableWebDocument__DefaultClass != ILU_NIL)
    _NgDocument_PutableWebDocument__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT NgDocument_WebDocument__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgDocument_WebDocument__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_WebDocument__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgDocument_WebDocument__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgDocument_WebDocument__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_WebDocument__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgDocument_WebDocument__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgDocument_WebDocument__DefaultClass != ILU_NIL)
    _NgDocument_WebDocument__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT NgDocument_RenderingAndPropertiesSink__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgDocument_RenderingAndPropertiesSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_RenderingAndPropertiesSink__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgDocument_RenderingAndPropertiesSink__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgDocument_RenderingAndPropertiesSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgDocument_RenderingAndPropertiesSink__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgDocument_RenderingAndPropertiesSink__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgDocument_RenderingAndPropertiesSink__DefaultClass != ILU_NIL)
    _NgDocument_RenderingAndPropertiesSink__DefaultClass->ilucc_finalize = f;
}

void NgDocument__InitializeServer(void)
{
  extern void _NgDocument__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _NgDocument__GeneralInitialization ();
  _NgDocument_HTTPCompatibleWebDocument__DefaultClass = NgDocument_HTTPCompatibleWebDocument__MakeClass(
    server_NgDocument_HTTPCompatibleWebDocument_GetRenderingAndProperties,
    server_NgDocument_HTTPCompatibleWebDocument_SendRenderingAndProperties,
    server_NgDocument_HTTPCompatibleWebDocument_SendRenderingAndPropertiesSynched,
    server_NgDocument_HTTPCompatibleWebDocument_GetAvailableRenderings,
    server_NgDocument_HTTPCompatibleWebDocument_GetRendering,
    server_NgDocument_HTTPCompatibleWebDocument_SendRendering,
    server_NgDocument_HTTPCompatibleWebDocument_SendRenderingSynched,
    server_NgDocument_HTTPCompatibleWebDocument_GetInterfaceDefinitionSource,
    server_NgDocument_HTTPCompatibleWebDocument_GetProperties,
    server_NgDocument_HTTPCompatibleWebDocument_GET,
    server_NgDocument_HTTPCompatibleWebDocument_HEAD,
    server_NgDocument_HTTPCompatibleWebDocument_POST,
    0 /* no finalization */
    );
  _NgDocument_PutableWebDocument__DefaultClass = NgDocument_PutableWebDocument__MakeClass(
    server_NgDocument_PutableWebDocument_PutRenderingAndProperties,
    server_NgDocument_PutableWebDocument_GetRenderingAndProperties,
    server_NgDocument_PutableWebDocument_SendRenderingAndProperties,
    server_NgDocument_PutableWebDocument_SendRenderingAndPropertiesSynched,
    server_NgDocument_PutableWebDocument_GetAvailableRenderings,
    server_NgDocument_PutableWebDocument_GetRendering,
    server_NgDocument_PutableWebDocument_SendRendering,
    server_NgDocument_PutableWebDocument_SendRenderingSynched,
    server_NgDocument_PutableWebDocument_GetInterfaceDefinitionSource,
    server_NgDocument_PutableWebDocument_GetProperties,
    server_NgDocument_PutableWebDocument_PutRendering,
    server_NgDocument_PutableWebDocument_PutProperties,
    0 /* no finalization */
    );
  _NgDocument_WebDocument__DefaultClass = NgDocument_WebDocument__MakeClass(
    server_NgDocument_WebDocument_GetRenderingAndProperties,
    server_NgDocument_WebDocument_SendRenderingAndProperties,
    server_NgDocument_WebDocument_SendRenderingAndPropertiesSynched,
    server_NgDocument_WebDocument_GetAvailableRenderings,
    server_NgDocument_WebDocument_GetRendering,
    server_NgDocument_WebDocument_SendRendering,
    server_NgDocument_WebDocument_SendRenderingSynched,
    server_NgDocument_WebDocument_GetInterfaceDefinitionSource,
    server_NgDocument_WebDocument_GetProperties,
    0 /* no finalization */
    );
  _NgDocument_RenderingAndPropertiesSink__DefaultClass = NgDocument_RenderingAndPropertiesSink__MakeClass(
    server_NgDocument_RenderingAndPropertiesSink_PropertiesProblem,
    server_NgDocument_RenderingAndPropertiesSink_ReceiveProperties,
    server_NgDocument_RenderingAndPropertiesSink_RegisterResponseCacheControl,
    server_NgDocument_RenderingAndPropertiesSink_RenderingProblem,
    server_NgDocument_RenderingAndPropertiesSink_ReceiveRendering,
    server_NgDocument_RenderingAndPropertiesSink_ReceiveRenderingChunk,
    server_NgDocument_RenderingAndPropertiesSink_Resynchronize,
    server_NgDocument_RenderingAndPropertiesSink_RegisterSourceControl,
    server_NgDocument_RenderingAndPropertiesSink_Done,
    server_NgDocument_RenderingAndPropertiesSink_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );


  ilu_SetMethodStubProc(&_NgDocument_PutableWebDocument__ILUType->cl_methods[0], (ilu_StubProc) _NgDocument_PutableWebDocument_PutRenderingAndProperties__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_NgDocument_WebDocument__ILUType->cl_methods[0], (ilu_StubProc) _NgDocument_WebDocument_GetRenderingAndProperties__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgDocument_WebDocument__ILUType->cl_methods[1], (ilu_StubProc) _NgDocument_WebDocument_SendRenderingAndProperties__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgDocument_WebDocument__ILUType->cl_methods[2], (ilu_StubProc) _NgDocument_WebDocument_SendRenderingAndPropertiesSynched__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_NgDocument_RenderingAndPropertiesSink__ILUType->cl_methods[0], (ilu_StubProc) _NgDocument_RenderingAndPropertiesSink_PropertiesProblem__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgDocument_RenderingAndPropertiesSink__ILUType->cl_methods[1], (ilu_StubProc) _NgDocument_RenderingAndPropertiesSink_ReceiveProperties__truestub, _ILU_C_LanguageIndex);;
}

