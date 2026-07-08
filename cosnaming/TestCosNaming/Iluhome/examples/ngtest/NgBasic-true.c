/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgBasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "NgBasic.h"

static ILU_C_Class _NgBasic_NgObject__DefaultClass = 0;

ILU_C_Class NgBasic_NgObject__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _NgBasic_NgObject__DefaultClass;
  _NgBasic_NgObject__DefaultClass = c;
  return oldclass;
}

static void _NgBasic_NgObject_GetInterfaceDefinitionSource__truestub(ilu_Call _call, ilu_Error *_err)
{
  NgBasic_NgObject _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  NgBasic_String _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (NgBasic_NgObject) _ILU_C_InputObject (_call, _NgBasic_NgObject__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = NgBasic_NgObject_GetInterfaceDefinitionSource (_h, &_status);
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
        _size += _NgBasic_String__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _NgBasic_String__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        NgBasic_String__Free (&_retvalue);
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

ILU_C_OBJECT NgBasic_NgObject__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_NgBasic_NgObject__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgBasic_NgObject__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT NgBasic_NgObject__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _NgBasic_NgObject__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_NgBasic_NgObject__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void NgBasic_NgObject__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_NgBasic_NgObject__DefaultClass != ILU_NIL)
    _NgBasic_NgObject__DefaultClass->ilucc_finalize = f;
}

void NgBasic__InitializeServer(void)
{
  extern void _NgBasic__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _NgBasic__GeneralInitialization ();
  _NgBasic_NgObject__DefaultClass = NgBasic_NgObject__MakeClass(
    server_NgBasic_NgObject_GetInterfaceDefinitionSource,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_NgBasic_NgObject__ILUType->cl_methods[0], (ilu_StubProc) _NgBasic_NgObject_GetInterfaceDefinitionSource__truestub, _ILU_C_LanguageIndex);;
}

