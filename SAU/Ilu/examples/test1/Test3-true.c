/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Jul 11 06:49:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Thu Jul 10 17:58:44 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test3.isl" of Thu Dec 28 15:50:31 2023,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Thu Jun 19 13:16:01 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "Test3.h"

static ILU_C_Class _Test3_O__DefaultClass = 0;

ILU_C_Class Test3_O__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Test3_O__DefaultClass;
  _Test3_O__DefaultClass = c;
  return oldclass;
}

static void _Test3_O_I_to_Test1U__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test3_O _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_long i = {0};
  Test2_T1U* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'q', (ilu_Class *) 0, (ILU_C_SizeFn) _ilu_CString__SizeOf, (ILU_C_OutputFn) _ilu_CString__Output, 0, (ILU_C_FreeFn) ilu_CString__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _Test1_TheU__SizeOf, (ILU_C_OutputFn) _Test1_TheU__Output, 0, (ILU_C_FreeFn) Test1_TheU__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test3_O) _ILU_C_InputObject (_call, _Test3_O__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputInteger (_call, &i, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test3_O_I_to_Test1U (_h, i, &_status);
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
        _size += _Test1_TheU__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _Test1_TheU__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        Test1_TheU__Free (_retvalue);
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

ILU_C_OBJECT Test3_O__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Test3_O__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test3_O__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Test3_O__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Test3_O__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test3_O__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Test3_O__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Test3_O__DefaultClass != ILU_NIL)
    _Test3_O__DefaultClass->ilucc_finalize = f;
}

void Test3__InitializeServer(void)
{
  extern void _Test3__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Test3__GeneralInitialization ();
  _Test3_O__DefaultClass = Test3_O__MakeClass(
    server_Test3_O_I_to_Test1U,
    server_Test3_O_RS_R_to_R_IS,
    server_Test3_O_O1_U_to_U,
    server_Test3_O_BS_to_I,
    server_Test3_O_SR_to_I,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_Test3_O__ILUType->cl_methods[0], (ilu_StubProc) _Test3_O_I_to_Test1U__truestub, _ILU_C_LanguageIndex);;
}

