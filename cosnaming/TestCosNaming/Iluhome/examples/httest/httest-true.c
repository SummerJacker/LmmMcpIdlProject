/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:28 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/httest/httest.isl" of Thu Aug 07 21:51:07 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/httest/iluhttp.isl" of Mon Jul 21 17:22:19 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/httest/ilu.isl" of Wed Jul 30 16:32:51 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "httest.h"

static ILU_C_Class _httest_DerivedResource__DefaultClass = 0;

ILU_C_Class httest_DerivedResource__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _httest_DerivedResource__DefaultClass;
  _httest_DerivedResource__DefaultClass = c;
  return oldclass;
}

static void _httest_DerivedResource_flipcase__truestub(ilu_Call _call, ilu_Error *_err)
{
  httest_DerivedResource _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  ilu_CString strtoflipcase = {0};
  ilu_CString _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'b', (ilu_Class *) 0, (ILU_C_SizeFn) ilu_SizeOfInteger, (ILU_C_OutputFn) ilu_OutputInteger, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (httest_DerivedResource) _ILU_C_InputObject (_call, _httest_DerivedResource__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _ilu_CString__Input (_call, &strtoflipcase, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = httest_DerivedResource_flipcase (_h, strtoflipcase, &_status);
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
        _size += _ilu_CString__SizeOf(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _ilu_CString__Output (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        ilu_CString__Free ((ilu_CString *) &_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      ilu_CString__Free ((ilu_CString *) &strtoflipcase);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT httest_DerivedResource__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_httest_DerivedResource__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_httest_DerivedResource__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT httest_DerivedResource__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _httest_DerivedResource__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_httest_DerivedResource__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void httest_DerivedResource__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_httest_DerivedResource__DefaultClass != ILU_NIL)
    _httest_DerivedResource__DefaultClass->ilucc_finalize = f;
}

void httest__InitializeServer(void)
{
  extern void _httest__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _httest__GeneralInitialization ();
  _httest_DerivedResource__DefaultClass = httest_DerivedResource__MakeClass(
    server_httest_DerivedResource_flipcase,
    server_httest_DerivedResource_GET,
    server_httest_DerivedResource_HEAD,
    server_httest_DerivedResource_POST,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_httest_DerivedResource__ILUType->cl_methods[0], (ilu_StubProc) _httest_DerivedResource_flipcase__truestub, _ILU_C_LanguageIndex);;
}

