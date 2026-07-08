/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Mon Aug 18 11:48:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/etc/CosNaming/CosNaming.idl" of Tue Apr 15 16:53:12 2014,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/etc/CosNaming/../../stubbers/parser/ilu.isl" of Fri Aug 01 07:58:20 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "CosNaming.h"

static ILU_C_Class _CosNaming_BindingIterator__DefaultClass = 0;

ILU_C_Class CosNaming_BindingIterator__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _CosNaming_BindingIterator__DefaultClass;
  _CosNaming_BindingIterator__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _CosNaming_NamingContextExt__DefaultClass = 0;

ILU_C_Class CosNaming_NamingContextExt__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _CosNaming_NamingContextExt__DefaultClass;
  _CosNaming_NamingContextExt__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _CosNaming_NamingContext__DefaultClass = 0;

ILU_C_Class CosNaming_NamingContext__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _CosNaming_NamingContext__DefaultClass;
  _CosNaming_NamingContext__DefaultClass = c;
  return oldclass;
}

static void _CosNaming_BindingIterator_next_one__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_BindingIterator _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Binding* b = {0};
  CORBA_boolean _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_BindingIterator) _ILU_C_InputObject (_call, _CosNaming_BindingIterator__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_BindingIterator_next_one (_h, &b, &_status);
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
        _size += ILU_C_SizeOfBoolean(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _CosNaming_Binding__SizeOf (_call, &*b, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ILU_C_OutputBoolean(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _CosNaming_Binding__Output(_call, b, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        CosNaming_Binding__Free (b);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(b);
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

static void _CosNaming_BindingIterator_next_n__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_BindingIterator _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_long how_many = {0};
  CosNaming_BindingList* bl = {0};
  CORBA_boolean _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_BindingIterator) _ILU_C_InputObject (_call, _CosNaming_BindingIterator__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputCardinal (_call, &how_many, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_BindingIterator_next_n (_h, how_many, &bl, &_status);
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
        _size += ILU_C_SizeOfBoolean(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _CosNaming_BindingList__SizeOf (_call, &*bl, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ILU_C_OutputBoolean(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _CosNaming_BindingList__Output(_call, bl, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        CosNaming_BindingList__Free (bl);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(bl);
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

static void _CosNaming_BindingIterator_destroy__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_BindingIterator _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_BindingIterator) _ILU_C_InputObject (_call, _CosNaming_BindingIterator__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_BindingIterator_destroy (_h, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContextExt_to_string__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContextExt _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  CosNaming_NamingContextExt_StringName _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContextExt) _ILU_C_InputObject (_call, _CosNaming_NamingContextExt__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_NamingContextExt_to_string (_h, &n, &_status);
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
        ilu_CString__Free (&_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      CosNaming_Name__Free (&n);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContextExt_to_name__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContextExt _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_NamingContextExt_StringName sn = {0};
  CosNaming_Name* _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContextExt) _ILU_C_InputObject (_call, _CosNaming_NamingContextExt__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _ilu_CString__Input (_call, &sn, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_NamingContextExt_to_name (_h, sn, &_status);
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
        _size += _CosNaming_Name__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _CosNaming_Name__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        CosNaming_Name__Free (_retvalue);
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
      ilu_CString__Free (&sn);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContextExt_to_url__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContextExt _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_NamingContextExt_Address addr = {0};
  CosNaming_NamingContextExt_StringName sn = {0};
  CosNaming_NamingContextExt_URLString _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContextExt) _ILU_C_InputObject (_call, _CosNaming_NamingContextExt__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _ilu_CString__Input (_call, &addr, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &sn, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_NamingContextExt_to_url (_h, addr, sn, &_status);
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
        ilu_CString__Free (&_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      ilu_CString__Free (&addr);
      ilu_CString__Free (&sn);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContextExt_resolve_str__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContextExt _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_NamingContextExt_StringName n = {0};
  ilu_CORBA_Object _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContextExt) _ILU_C_InputObject (_call, _CosNaming_NamingContextExt__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _ilu_CString__Input (_call, &n, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_NamingContextExt_resolve_str (_h, n, &_status);
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
        _size += _ILU_C_SizeOfObject(_call, (ilu_CORBA_Object) _retvalue, _ilu_CORBA_Object__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _ILU_C_OutputObject(_call, (ilu_CORBA_Object) _retvalue, _ilu_CORBA_Object__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        ilu_CORBA_Object__Free (&_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      ilu_CString__Free (&n);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_bind__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  ilu_CORBA_Object obj = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&obj = _ILU_C_InputObject (_call, _ilu_CORBA_Object__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_NamingContext_bind (_h, &n, obj, &_status);
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
      CosNaming_Name__Free (&n);
      ilu_CORBA_Object__Free (&obj);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_rebind__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  ilu_CORBA_Object obj = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&obj = _ILU_C_InputObject (_call, _ilu_CORBA_Object__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_NamingContext_rebind (_h, &n, obj, &_status);
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
      CosNaming_Name__Free (&n);
      ilu_CORBA_Object__Free (&obj);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_bind_context__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  CosNaming_NamingContext nc = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&nc = _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_NamingContext_bind_context (_h, &n, nc, &_status);
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
      CosNaming_Name__Free (&n);
      CosNaming_NamingContext__Free (&nc);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_rebind_context__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  CosNaming_NamingContext nc = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&nc = _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_NamingContext_rebind_context (_h, &n, nc, &_status);
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
      CosNaming_Name__Free (&n);
      CosNaming_NamingContext__Free (&nc);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_resolve__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  ilu_CORBA_Object _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_NamingContext_resolve (_h, &n, &_status);
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
        _size += _ILU_C_SizeOfObject(_call, (ilu_CORBA_Object) _retvalue, _ilu_CORBA_Object__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _ILU_C_OutputObject(_call, (ilu_CORBA_Object) _retvalue, _ilu_CORBA_Object__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        ilu_CORBA_Object__Free (&_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      CosNaming_Name__Free (&n);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_unbind__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_NamingContext_unbind (_h, &n, &_status);
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
      CosNaming_Name__Free (&n);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_new_context__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_NamingContext _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_NamingContext_new_context (_h, &_status);
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
        _size += _ILU_C_SizeOfObject(_call, (CosNaming_NamingContext) _retvalue, _CosNaming_NamingContext__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _ILU_C_OutputObject(_call, (CosNaming_NamingContext) _retvalue, _CosNaming_NamingContext__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        CosNaming_NamingContext__Free (&_retvalue);
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

static void _CosNaming_NamingContext_bind_new_context__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CosNaming_Name n = {0};
  CosNaming_NamingContext _retvalue = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf, (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output, 0, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 },
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _CosNaming_Name__Input (_call, &n,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = CosNaming_NamingContext_bind_new_context (_h, &n, &_status);
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
        _size += _ILU_C_SizeOfObject(_call, (CosNaming_NamingContext) _retvalue, _CosNaming_NamingContext__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_TRUE, _size, _err)) goto errexit;
      _ILU_C_OutputObject(_call, (CosNaming_NamingContext) _retvalue, _CosNaming_NamingContext__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        CosNaming_NamingContext__Free (&_retvalue);
      } else {
        ilu_Error _lerr = ILU_INIT_NO_ERR;
        _ILU_C_FreeException(_the_method, _evec, &_status, &_lerr);
        ILU_HANDLED(_lerr);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      CosNaming_Name__Free (&n);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_destroy__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) '*', (ilu_Class *) 0, (ILU_C_SizeFn) 0, 0, 0, 0 }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_NamingContext_destroy (_h, &_status);
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _CosNaming_NamingContext_list__truestub(ilu_Call _call, ilu_Error *_err)
{
  CosNaming_NamingContext _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_long how_many = {0};
  CosNaming_BindingList* bl = {0};
  CosNaming_BindingIterator bi = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (CosNaming_NamingContext) _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputCardinal (_call, &how_many, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    CosNaming_NamingContext_list (_h, how_many, &bl, &bi, &_status);
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
        _size += _CosNaming_BindingList__SizeOf (_call, &*bl, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _ILU_C_SizeOfObject(_call, (CosNaming_BindingIterator) bi, _CosNaming_BindingIterator__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _CosNaming_BindingList__Output(_call, bl, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _ILU_C_OutputObject(_call, (CosNaming_BindingIterator) bi, _CosNaming_BindingIterator__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        CosNaming_BindingList__Free (bl);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(bl);
        CosNaming_BindingIterator__Free (&bi);
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

ILU_C_OBJECT CosNaming_BindingIterator__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_CosNaming_BindingIterator__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_CosNaming_BindingIterator__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT CosNaming_BindingIterator__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _CosNaming_BindingIterator__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_CosNaming_BindingIterator__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void CosNaming_BindingIterator__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_CosNaming_BindingIterator__DefaultClass != ILU_NIL)
    _CosNaming_BindingIterator__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT CosNaming_NamingContextExt__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_CosNaming_NamingContextExt__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_CosNaming_NamingContextExt__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT CosNaming_NamingContextExt__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _CosNaming_NamingContextExt__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_CosNaming_NamingContextExt__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void CosNaming_NamingContextExt__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_CosNaming_NamingContextExt__DefaultClass != ILU_NIL)
    _CosNaming_NamingContextExt__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT CosNaming_NamingContext__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_CosNaming_NamingContext__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_CosNaming_NamingContext__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT CosNaming_NamingContext__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _CosNaming_NamingContext__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_CosNaming_NamingContext__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void CosNaming_NamingContext__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_CosNaming_NamingContext__DefaultClass != ILU_NIL)
    _CosNaming_NamingContext__DefaultClass->ilucc_finalize = f;
}

void CosNaming__InitializeServer(void)
{
  extern void _CosNaming__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _CosNaming__GeneralInitialization ();
  _CosNaming_BindingIterator__DefaultClass = CosNaming_BindingIterator__MakeClass(
    server_CosNaming_BindingIterator_next_one,
    server_CosNaming_BindingIterator_next_n,
    server_CosNaming_BindingIterator_destroy,
    0 /* no finalization */
    );
  _CosNaming_NamingContext__DefaultClass = CosNaming_NamingContext__MakeClass(
    server_CosNaming_NamingContext_bind,
    server_CosNaming_NamingContext_rebind,
    server_CosNaming_NamingContext_bind_context,
    server_CosNaming_NamingContext_rebind_context,
    server_CosNaming_NamingContext_resolve,
    server_CosNaming_NamingContext_unbind,
    server_CosNaming_NamingContext_new_context,
    server_CosNaming_NamingContext_bind_new_context,
    server_CosNaming_NamingContext_destroy,
    server_CosNaming_NamingContext_list,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_CosNaming_BindingIterator__ILUType->cl_methods[0], (ilu_StubProc) _CosNaming_BindingIterator_next_one__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_BindingIterator__ILUType->cl_methods[1], (ilu_StubProc) _CosNaming_BindingIterator_next_n__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_BindingIterator__ILUType->cl_methods[2], (ilu_StubProc) _CosNaming_BindingIterator_destroy__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_CosNaming_NamingContextExt__ILUType->cl_methods[0], (ilu_StubProc) _CosNaming_NamingContextExt_to_string__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContextExt__ILUType->cl_methods[1], (ilu_StubProc) _CosNaming_NamingContextExt_to_name__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContextExt__ILUType->cl_methods[2], (ilu_StubProc) _CosNaming_NamingContextExt_to_url__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContextExt__ILUType->cl_methods[3], (ilu_StubProc) _CosNaming_NamingContextExt_resolve_str__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[0], (ilu_StubProc) _CosNaming_NamingContext_bind__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[1], (ilu_StubProc) _CosNaming_NamingContext_rebind__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[2], (ilu_StubProc) _CosNaming_NamingContext_bind_context__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[3], (ilu_StubProc) _CosNaming_NamingContext_rebind_context__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[4], (ilu_StubProc) _CosNaming_NamingContext_resolve__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[5], (ilu_StubProc) _CosNaming_NamingContext_unbind__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[6], (ilu_StubProc) _CosNaming_NamingContext_new_context__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[7], (ilu_StubProc) _CosNaming_NamingContext_bind_new_context__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[8], (ilu_StubProc) _CosNaming_NamingContext_destroy__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_CosNaming_NamingContext__ILUType->cl_methods[9], (ilu_StubProc) _CosNaming_NamingContext_list__truestub, _ILU_C_LanguageIndex);;
}

