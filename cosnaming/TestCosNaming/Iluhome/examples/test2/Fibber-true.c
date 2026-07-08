/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:24 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test2/Fibber.isl" of Sat Aug 02 18:52:05 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test2/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "Fibber.h"

static ILU_C_Class _Fibber_T__DefaultClass = 0;

ILU_C_Class Fibber_T__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Fibber_T__DefaultClass;
  _Fibber_T__DefaultClass = c;
  return oldclass;
}

static void _Fibber_T_Calc__truestub(ilu_Call _call, ilu_Error *_err)
{
  Fibber_T _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_long d = {0};
  CORBA_unsigned_long n = {0};
  Fibber_T ask = {0};
  CORBA_unsigned_long _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _Fibber_StringSeq__SizeOf, (ILU_C_OutputFn) _Fibber_StringSeq__Output, 0, (ILU_C_FreeFn) Fibber_StringSeq__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Fibber_T) _ILU_C_InputObject (_call, _Fibber_T__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputCardinal (_call, &d, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &n, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&ask = _ILU_C_InputObject (_call, _Fibber_T__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Fibber_T_Calc (_h, d, n, ask, &_status);
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
        _size += ilu_SizeOfCardinal(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      ilu_OutputCardinal (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
      Fibber_T__Free (&ask);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT Fibber_T__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Fibber_T__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Fibber_T__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Fibber_T__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Fibber_T__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Fibber_T__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Fibber_T__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Fibber_T__DefaultClass != ILU_NIL)
    _Fibber_T__DefaultClass->ilucc_finalize = f;
}

void Fibber__InitializeServer(void)
{
  extern void _Fibber__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Fibber__GeneralInitialization ();
  _Fibber_T__DefaultClass = Fibber_T__MakeClass(
    server_Fibber_T_Calc,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_Fibber_T__ILUType->cl_methods[0], (ilu_StubProc) _Fibber_T_Calc__truestub, _ILU_C_LanguageIndex);;
}

