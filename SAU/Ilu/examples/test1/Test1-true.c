/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Jul 11 06:49:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Thu Jul 10 17:58:44 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Thu Jun 19 13:16:01 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "Test1.h"

static ILU_C_Class _Test1_O4__DefaultClass = 0;

ILU_C_Class Test1_O4__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Test1_O4__DefaultClass;
  _Test1_O4__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _Test1_P__DefaultClass = 0;

ILU_C_Class Test1_P__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Test1_P__DefaultClass;
  _Test1_P__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _Test1_O3__DefaultClass = 0;

ILU_C_Class Test1_O3__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Test1_O3__DefaultClass;
  _Test1_O3__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _Test1_TheO1__DefaultClass = 0;

ILU_C_Class Test1_TheO1__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Test1_TheO1__DefaultClass;
  _Test1_TheO1__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _Test1_O2__DefaultClass = 0;

ILU_C_Class Test1_O2__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _Test1_O2__DefaultClass;
  _Test1_O2__DefaultClass = c;
  return oldclass;
}

static void _Test1_O4_R_to_R__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_O4 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_double r = {0};
  CORBA_double _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_O4) _ILU_C_InputObject (_call, _Test1_O4__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputReal (_call, &r, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_O4_R_to_R (_h, r, &_status);
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

static void _Test1_P_m2__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_P _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_long j = {0};
  Test1_IS* _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_P) _ILU_C_InputObject (_call, _Test1_P__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputInteger (_call, &j, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_P_m2 (_h, j, &_status);
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
        _size += _Test1_IS__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _Test1_IS__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        Test1_IS__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
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

static void _Test1_O3_RS_R_to_R_IS__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_O3 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_RS r = {0};
  Test1_R* r2 = {0};
  Test1_IS* _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_O3) _ILU_C_InputObject (_call, _Test1_O3__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_TheRS__Input (_call, &r,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_O3_RS_R_to_R_IS (_h, &r, &r2, &_status);
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
        _size += _Test1_IS__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _Test1_TheR__SizeOf (_call, &*r2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _Test1_IS__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _Test1_TheR__Output(_call, r2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        Test1_IS__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
        Test1_TheR__Free (r2);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(r2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      Test1_TheRS__Free (&r);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_O3_O1_U_to_U__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_O3 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_O1 o = {0};
  Test1_U u = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'b', (ilu_Class *) 0, (ILU_C_SizeFn) ilu_SizeOfInteger, (ILU_C_OutputFn) ilu_OutputInteger, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_O3) _ILU_C_InputObject (_call, _Test1_O3__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  *&o = _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Test1_TheU__Input (_call, &u,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    Test1_O3_O1_U_to_U (_h, o, &u, &_status);
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
        _size += _Test1_TheU__SizeOf (_call, &u, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _Test1_TheU__Output(_call, &u, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
      Test1_TheO1__Free (&o);
      Test1_TheU__Free (&u);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_O3_BS_to_I__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_O3 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_BS b = {0};
  Test1_I _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_O3) _ILU_C_InputObject (_call, _Test1_O3__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_BS__Input (_call, &b,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_O3_BS_to_I (_h, &b, &_status);
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
      Test1_BS__Free (&b);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_TheO1_U_CSS_to_U__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_TheO1 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_U u = {0};
  Test1_CSS css = {0};
  Test1_U* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _Test1_TheU__SizeOf, (ILU_C_OutputFn) _Test1_TheU__Output, 0, (ILU_C_FreeFn) Test1_TheU__Free },
    { (unsigned int) 'b', (ilu_Class *) 0, (ILU_C_SizeFn) ilu_SizeOfInteger, (ILU_C_OutputFn) ilu_OutputInteger, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_TheO1) _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_TheU__Input (_call, &u,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Test1_CSS__Input (_call, &css,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_TheO1_U_CSS_to_U (_h, &u, &css, &_status);
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
      Test1_TheU__Free (&u);
      Test1_CSS__Free (&css);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_TheO1_f_CSS_to_RO__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_TheO1 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_CSS css = {0};
  Test1_RO _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _Test1_TheU__SizeOf, (ILU_C_OutputFn) _Test1_TheU__Output, 0, (ILU_C_FreeFn) Test1_TheU__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_TheO1) _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_CSS__Input (_call, &css,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_TheO1_f_CSS_to_RO (_h, &css, &_status);
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
        _size += _Test1_RO__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _Test1_RO__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        Test1_RO__Free (&_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      Test1_CSS__Free (&css);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_TheO1_R_ScS_to_F__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_TheO1 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_R r = {0};
  Test1_ScS s = {0};
  CORBA_float _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_TheO1) _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_TheR__Input (_call, &r,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Test1_ScS__Input (_call, &s,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_TheO1_R_ScS_to_F (_h, &r, s, &_status);
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
        _size += ilu_SizeOfShortReal(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputShortReal(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
      Test1_TheR__Free (&r);
      Test1_ScS__Free (&s);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_TheO1_a_RO__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_TheO1 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_RO ro = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_TheO1) _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_RO__Input (_call, &ro,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    Test1_TheO1_a_RO (_h, ro, &_status);
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
      Test1_RO__Free (&ro);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_TheO1_get_O2__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_TheO1 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_O2 _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_TheO1) _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_TheO1_get_O2 (_h, &_status);
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
        _size += _ILU_C_SizeOfObject(_call, (Test1_O2) _retvalue, _Test1_O2__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _ILU_C_OutputObject(_call, (Test1_O2) _retvalue, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        Test1_O2__Free (&_retvalue);
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

static void _Test1_TheO1_get_O3__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_TheO1 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_boolean subclass = {0};
  Test1_O3 _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_TheO1) _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ILU_C_InputBoolean (_call, &subclass, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_TheO1_get_O3 (_h, subclass, &_status);
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
        _size += _ILU_C_SizeOfObject(_call, (Test1_O3) _retvalue, _Test1_O3__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _ILU_C_OutputObject(_call, (Test1_O3) _retvalue, _Test1_O3__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        Test1_O3__Free (&_retvalue);
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

static void _Test1_O2_OO_A0_to_CSS__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_O2 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_OO o = {0};
  Test1_A0 a = {0};
  Test1_CSS* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'b', (ilu_Class *) 0, (ILU_C_SizeFn) ilu_SizeOfInteger, (ILU_C_OutputFn) ilu_OutputInteger, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_O2) _ILU_C_GetServerSingleton (_call, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_TheOO__Input (_call, &o,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Test1_A0__Input (_call, a,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_O2_OO_A0_to_CSS (_h, o, a, &_status);
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
        _size += _Test1_CSS__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _Test1_CSS__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        Test1_CSS__Free (_retvalue);
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
      Test1_TheOO__Free (&o);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _Test1_O2_R_I_A1_to_I_A0__truestub(ilu_Call _call, ilu_Error *_err)
{
  Test1_O2 _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  Test1_R r = {0};
  Test1_I i = {0};
  Test1_A1 a = {0};
  Test1_A0_slice * _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (Test1_O2) _ILU_C_GetServerSingleton (_call, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _Test1_TheR__Input (_call, &r,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputInteger (_call, &i, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Test1_TheA1__Input (_call, a,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = Test1_O2_R_I_A1_to_I_A0 (_h, &r, &i, a, &_status);
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
        _size += _Test1_A0__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfInteger(_call, i, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _Test1_A0__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputInteger (_call, i, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      Test1_TheR__Free (&r);
      Test1_TheA1__Free (&a);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

ILU_C_OBJECT Test1_O4__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Test1_O4__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_O4__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Test1_O4__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Test1_O4__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_O4__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Test1_O4__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Test1_O4__DefaultClass != ILU_NIL)
    _Test1_O4__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT Test1_P__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Test1_P__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_P__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Test1_P__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Test1_P__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_P__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Test1_P__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Test1_P__DefaultClass != ILU_NIL)
    _Test1_P__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT Test1_O3__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Test1_O3__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_O3__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Test1_O3__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Test1_O3__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_O3__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Test1_O3__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Test1_O3__DefaultClass != ILU_NIL)
    _Test1_O3__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT Test1_TheO1__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Test1_TheO1__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_TheO1__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Test1_TheO1__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Test1_TheO1__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_TheO1__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Test1_TheO1__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Test1_TheO1__DefaultClass != ILU_NIL)
    _Test1_TheO1__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT Test1_O2__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_Test1_O2__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_O2__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT Test1_O2__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _Test1_O2__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_Test1_O2__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void Test1_O2__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_Test1_O2__DefaultClass != ILU_NIL)
    _Test1_O2__DefaultClass->ilucc_finalize = f;
}

void Test1__InitializeServer(void)
{
  extern void _Test1__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Test1__GeneralInitialization ();
  _Test1_O4__DefaultClass = Test1_O4__MakeClass(
    server_Test1_O4_R_to_R,
    server_Test1_O4_RS_R_to_R_IS,
    server_Test1_O4_O1_U_to_U,
    server_Test1_O4_BS_to_I,
    0 /* no finalization */
    );
  _Test1_P__DefaultClass = Test1_P__MakeClass(
    server_Test1_P_m2,
    server_Test1_P_RS_R_to_R_IS,
    server_Test1_P_O1_U_to_U,
    server_Test1_P_BS_to_I,
    0 /* no finalization */
    );
  _Test1_O3__DefaultClass = Test1_O3__MakeClass(
    server_Test1_O3_RS_R_to_R_IS,
    server_Test1_O3_O1_U_to_U,
    server_Test1_O3_BS_to_I,
    0 /* no finalization */
    );
  _Test1_TheO1__DefaultClass = Test1_TheO1__MakeClass(
    server_Test1_TheO1_U_CSS_to_U,
    server_Test1_TheO1_f_CSS_to_RO,
    server_Test1_TheO1_R_ScS_to_F,
    server_Test1_TheO1_a_RO,
    server_Test1_TheO1_get_O2,
    server_Test1_TheO1_get_O3,
    0 /* no finalization */
    );
  _Test1_O2__DefaultClass = Test1_O2__MakeClass(
    server_Test1_O2_OO_A0_to_CSS,
    server_Test1_O2_R_I_A1_to_I_A0,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_Test1_O4__ILUType->cl_methods[0], (ilu_StubProc) _Test1_O4_R_to_R__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_Test1_P__ILUType->cl_methods[0], (ilu_StubProc) _Test1_P_m2__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_Test1_O3__ILUType->cl_methods[0], (ilu_StubProc) _Test1_O3_RS_R_to_R_IS__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_O3__ILUType->cl_methods[1], (ilu_StubProc) _Test1_O3_O1_U_to_U__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_O3__ILUType->cl_methods[2], (ilu_StubProc) _Test1_O3_BS_to_I__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_Test1_TheO1__ILUType->cl_methods[0], (ilu_StubProc) _Test1_TheO1_U_CSS_to_U__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_TheO1__ILUType->cl_methods[1], (ilu_StubProc) _Test1_TheO1_f_CSS_to_RO__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_TheO1__ILUType->cl_methods[2], (ilu_StubProc) _Test1_TheO1_R_ScS_to_F__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_TheO1__ILUType->cl_methods[3], (ilu_StubProc) _Test1_TheO1_a_RO__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_TheO1__ILUType->cl_methods[4], (ilu_StubProc) _Test1_TheO1_get_O2__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_TheO1__ILUType->cl_methods[5], (ilu_StubProc) _Test1_TheO1_get_O3__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_Test1_O2__ILUType->cl_methods[0], (ilu_StubProc) _Test1_O2_OO_A0_to_CSS__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_Test1_O2__ILUType->cl_methods[1], (ilu_StubProc) _Test1_O2_R_I_A1_to_I_A0__truestub, _ILU_C_LanguageIndex);;
}

