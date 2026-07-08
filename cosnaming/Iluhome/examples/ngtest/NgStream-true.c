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

#include <stdio.h>

#include <iluntrnl.h>

#include "NgStream.h"

static ILU_C_Class _NgStream_DataSink__DefaultClass = 0;

ILU_C_Class NgStream_DataSink__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgStream_DataSink__DefaultClass;
  _NgStream_DataSink__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _NgStream_DataSource__DefaultClass = 0;

ILU_C_Class NgStream_DataSource__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgStream_DataSource__DefaultClass;
  _NgStream_DataSource__DefaultClass = c;
  return oldclass;
}

static void _NgStream_DataSink_RegisterSourceControl__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgStream_DataSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgStream_DataSource thesource = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgStream_DataSink) _ILU_C_InputObject (_call, _NgStream_DataSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  *&thesource = _ILU_C_InputObject (_call, _NgStream_DataSource__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgStream_DataSink_RegisterSourceControl (_h, thesource, &_status);
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
      NgStream_DataSource__Free (&thesource);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgStream_DataSink_Done__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgStream_DataSink _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgStream_DataSink) _ILU_C_InputObject (_call, _NgStream_DataSink__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgStream_DataSink_Done (_h, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgStream_DataSource_Abort__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgStream_DataSource _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgStream_DataSource) _ILU_C_InputObject (_call, _NgStream_DataSource__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgStream_DataSource_Abort (_h, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgStream_DataSource_Pause__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgStream_DataSource _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgStream_DataSource) _ILU_C_InputObject (_call, _NgStream_DataSource__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgStream_DataSource_Pause (_h, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgStream_DataSource_Resume__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgStream_DataSource _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgStream_DataSource) _ILU_C_InputObject (_call, _NgStream_DataSource__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgStream_DataSource_Resume (_h, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgStream_DataSource_Resend__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgStream_DataSource _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgBasic_UnsignedInclusiveInterval repeatRange = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgStream_DataSource) _ILU_C_InputObject (_call, _NgStream_DataSource__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _NgBasic_UnsignedInclusiveInterval__Input (_call, &repeatRange,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgStream_DataSource_Resend (_h, &repeatRange, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _NgStream_DataSource_SuggestChunkSize__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgStream_DataSource _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_long suggestedSize = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgStream_DataSource) _ILU_C_InputObject (_call, _NgStream_DataSource__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputCardinal (_call, &suggestedSize, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    NgStream_DataSource_SuggestChunkSize (_h, suggestedSize, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT NgStream_DataSink__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgStream_DataSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgStream_DataSink__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgStream_DataSink__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgStream_DataSink__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgStream_DataSink__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgStream_DataSink__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgStream_DataSink__DefaultClass != ILU_NIL)
    _NgStream_DataSink__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT NgStream_DataSource__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgStream_DataSource__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgStream_DataSource__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgStream_DataSource__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgStream_DataSource__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgStream_DataSource__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgStream_DataSource__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgStream_DataSource__DefaultClass != ILU_NIL)
    _NgStream_DataSource__DefaultClass->ilucc_finalize = f;
}

void NgStream__InitializeServer(void)
{
  extern void _NgStream__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _NgStream__GeneralInitialization ();
  _NgStream_DataSink__DefaultClass = NgStream_DataSink__MakeClass(
    server_NgStream_DataSink_RegisterSourceControl,
    server_NgStream_DataSink_Done,
    server_NgStream_DataSink_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );
  _NgStream_DataSource__DefaultClass = NgStream_DataSource__MakeClass(
    server_NgStream_DataSource_Abort,
    server_NgStream_DataSource_Pause,
    server_NgStream_DataSource_Resume,
    server_NgStream_DataSource_Resend,
    server_NgStream_DataSource_SuggestChunkSize,
    server_NgStream_DataSource_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_NgStream_DataSink__ILUType->cl_methods[0], (ilu_StubProc) _NgStream_DataSink_RegisterSourceControl__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgStream_DataSink__ILUType->cl_methods[1], (ilu_StubProc) _NgStream_DataSink_Done__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_NgStream_DataSource__ILUType->cl_methods[0], (ilu_StubProc) _NgStream_DataSource_Abort__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgStream_DataSource__ILUType->cl_methods[1], (ilu_StubProc) _NgStream_DataSource_Pause__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgStream_DataSource__ILUType->cl_methods[2], (ilu_StubProc) _NgStream_DataSource_Resume__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgStream_DataSource__ILUType->cl_methods[3], (ilu_StubProc) _NgStream_DataSource_Resend__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_NgStream_DataSource__ILUType->cl_methods[4], (ilu_StubProc) _NgStream_DataSource_SuggestChunkSize__truestub, _ILU_C_LanguageIndex);;
}

