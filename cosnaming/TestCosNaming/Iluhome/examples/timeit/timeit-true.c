/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:50 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/timeit/timeit.idl" of Thu Aug 07 15:38:55 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "timeit.h"

static ILU_C_Class _timeit_p__DefaultClass = 0;

ILU_C_Class timeit_p__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _timeit_p__DefaultClass;
  _timeit_p__DefaultClass = c;
  return oldclass;
}

static void _timeit_p_ping1__truestub(ilu_Call _call, ilu_Error *_err)
{
  timeit_p _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_long p1 = {0};
  CORBA_unsigned_long _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (timeit_p) _ILU_C_InputObject (_call, _timeit_p__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputCardinal (_call, &p1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = timeit_p_ping1 (_h, p1, &_status);
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
        _size += ilu_SizeOfCardinal(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputCardinal (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _timeit_p_ping2__truestub(ilu_Call _call, ilu_Error *_err)
{
  timeit_p _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_double p2 = {0};
  CORBA_double _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (timeit_p) _ILU_C_InputObject (_call, _timeit_p__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputReal (_call, &p2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = timeit_p_ping2 (_h, p2, &_status);
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
        _size += ilu_SizeOfReal(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputReal(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _timeit_p_ping3__truestub(ilu_Call _call, ilu_Error *_err)
{
  timeit_p _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  ilu_CString p3 = {0};
  ilu_CString _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (timeit_p) _ILU_C_InputObject (_call, _timeit_p__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _ilu_CString__Input (_call, &p3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = timeit_p_ping3 (_h, p3, &_status);
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
        _size += _ilu_CString__SizeOf(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _ilu_CString__Output (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        ilu_CString__Free ((ilu_CString *) &_retvalue);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      ilu_CString__Free ((ilu_CString *) &p3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _timeit_p_doctest__truestub(ilu_Call _call, ilu_Error *_err)
{
  timeit_p _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  ilu_CString name = {0};
  CORBA_unsigned_long count = {0};
  CORBA_unsigned_long pagesize = {0};
  timeit_pageSeq* _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (timeit_p) _ILU_C_InputObject (_call, _timeit_p__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _ilu_CString__Input (_call, &name, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &count, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &pagesize, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = timeit_p_doctest (_h, name, count, pagesize, &_status);
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
        _size += _timeit_pageSeq__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _timeit_pageSeq__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        timeit_pageSeq__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      ilu_CString__Free ((ilu_CString *) &name);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _timeit_p_imgtest__truestub(ilu_Call _call, ilu_Error *_err)
{
  timeit_p _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  timeit_img20x20x20 val = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (timeit_p) _ILU_C_InputObject (_call, _timeit_p__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _timeit_img20x20x20__Input (_call, val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    timeit_p_imgtest (_h, val, &_status);
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

static void _timeit_p_rectest__truestub(ilu_Call _call, ilu_Error *_err)
{
  timeit_p _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  timeit_recseq val = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (timeit_p) _ILU_C_InputObject (_call, _timeit_p__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _timeit_recseq__Input (_call, &val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    timeit_p_rectest (_h, &val, &_status);
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
      timeit_recseq__Free (&val);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT timeit_p__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_timeit_p__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_timeit_p__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT timeit_p__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _timeit_p__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_timeit_p__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void timeit_p__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_timeit_p__DefaultClass != ILU_NIL)
    _timeit_p__DefaultClass->ilucc_finalize = f;
}

void timeit__InitializeServer(void)
{
  extern void _timeit__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _timeit__GeneralInitialization ();
  _timeit_p__DefaultClass = timeit_p__MakeClass(
    server_timeit_p_ping1,
    server_timeit_p_ping2,
    server_timeit_p_ping3,
    server_timeit_p_doctest,
    server_timeit_p_imgtest,
    server_timeit_p_rectest,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_timeit_p__ILUType->cl_methods[0], (ilu_StubProc) _timeit_p_ping1__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_timeit_p__ILUType->cl_methods[1], (ilu_StubProc) _timeit_p_ping2__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_timeit_p__ILUType->cl_methods[2], (ilu_StubProc) _timeit_p_ping3__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_timeit_p__ILUType->cl_methods[3], (ilu_StubProc) _timeit_p_doctest__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_timeit_p__ILUType->cl_methods[4], (ilu_StubProc) _timeit_p_imgtest__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_timeit_p__ILUType->cl_methods[5], (ilu_StubProc) _timeit_p_rectest__truestub, _ILU_C_LanguageIndex);;
}

