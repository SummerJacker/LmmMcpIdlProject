/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:52 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "Test2.h"

static ILU_C_Class _Test2_P__DefaultClass = 0;

ILU_C_Class Test2_P__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Test2_P__DefaultClass;
  _Test2_P__DefaultClass = c;
  return oldclass;
}

static void _Test2_P_SR_to_I__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test2_P _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_float i = {0};
  CORBA_long _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test2_P) _ILU_C_InputObject (_call, _Test2_P__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputShortReal (_call, &i, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test2_P_SR_to_I (_h, i, &_status);
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
        _size += ilu_SizeOfInteger(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputInteger (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT Test2_P__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Test2_P__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test2_P__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Test2_P__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Test2_P__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test2_P__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Test2_P__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Test2_P__DefaultClass != ILU_NIL)
    _Test2_P__DefaultClass->ilucc_finalize = f;
}

void Test2__InitializeServer(void)
{
  extern void _Test2__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Test2__GeneralInitialization ();
  _Test2_P__DefaultClass = Test2_P__MakeClass(
    server_Test2_P_SR_to_I,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_Test2_P__ILUType->cl_methods[0], (ilu_StubProc) _Test2_P_SR_to_I__truestub, _ILU_C_LanguageIndex);;
}

