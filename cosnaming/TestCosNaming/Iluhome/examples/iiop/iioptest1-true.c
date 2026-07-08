/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:31 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/iiop/iioptest1.isl" of Tue Sep 21 06:54:02 1999,
 * and "D:/Shaun-projects/newstar/Iluhome/Interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>

#include <iluntrnl.h>

#include "iioptest1.h"

static ILU_C_Class _iioptest1_xilu_obj__DefaultClass = 0;

ILU_C_Class iioptest1_xilu_obj__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _iioptest1_xilu_obj__DefaultClass;
  _iioptest1_xilu_obj__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _iioptest1_ext_obj__DefaultClass = 0;

ILU_C_Class iioptest1_ext_obj__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _iioptest1_ext_obj__DefaultClass;
  _iioptest1_ext_obj__DefaultClass = c;
  return oldclass;
}

static ILU_C_Class _iioptest1_obj__DefaultClass = 0;

ILU_C_Class iioptest1_obj__SetDefaultClass(ILU_C_Class c)
{
  ILU_C_Class oldclass = _iioptest1_obj__DefaultClass;
  _iioptest1_obj__DefaultClass = c;
  return oldclass;
}

static void _iioptest1_xilu_obj_test_optional__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_xilu_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_opt1 a1 = {0};
  iioptest1_opt1 a2 = {0};
  iioptest1_opt1 a3 = {0};
  iioptest1_opt1 _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_xilu_obj) _ILU_C_InputObject (_call, _iioptest1_xilu_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_opt1__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_opt1__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_xilu_obj_test_optional (_h, a1, &a2, &a3, &_status);
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
        _size += _iioptest1_opt1__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_opt1__SizeOf (_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_opt1__SizeOf (_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_opt1__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_opt1__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_opt1__Output(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_opt1__Free (&_retvalue);
        iioptest1_opt1__Free (&a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_opt1__Free (&a1);
      iioptest1_opt1__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_xilu_obj_test_asynchronous__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_xilu_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_long a1 = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_xilu_obj) _ILU_C_InputObject (_call, _iioptest1_xilu_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputInteger (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    iioptest1_xilu_obj_test_asynchronous (_h, a1, &_status);
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

static void _iioptest1_ext_obj_test_obj__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_ext_obj a1 = {0};
  iioptest1_ext_obj a2 = {0};
  iioptest1_ext_obj a3 = {0};
  iioptest1_ext_obj _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  *&a1 = _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  *&a3 = _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_obj (_h, a1, &a2, &a3, &_status);
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
        _size += _ILU_C_SizeOfObject(_call, (iioptest1_ext_obj) _retvalue, _iioptest1_ext_obj__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _ILU_C_SizeOfObject(_call, (iioptest1_ext_obj) a2, _iioptest1_ext_obj__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _ILU_C_SizeOfObject(_call, (iioptest1_ext_obj) a3, _iioptest1_ext_obj__ILUType, ilu_FALSE, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _ILU_C_OutputObject(_call, (iioptest1_ext_obj) _retvalue, _iioptest1_ext_obj__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _ILU_C_OutputObject(_call, (iioptest1_ext_obj) a2, _iioptest1_ext_obj__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _ILU_C_OutputObject(_call, (iioptest1_ext_obj) a3, _iioptest1_ext_obj__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_ext_obj__Free (&_retvalue);
        iioptest1_ext_obj__Free (&a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_ext_obj__Free (&a1);
      iioptest1_ext_obj__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_ext_obj_test_fixed_record__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_rec2 a1 = {0};
  iioptest1_rec2 a2 = {0};
  iioptest1_rec2 a3 = {0};
  iioptest1_rec2 _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_rec2__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_rec2__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_fixed_record (_h, &a1, &a2, &a3, &_status);
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
        _size += _iioptest1_rec2__SizeOf (_call, &_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_rec2__SizeOf (_call, &a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_rec2__SizeOf (_call, &a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_rec2__Output(_call, &_retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_rec2__Output(_call, &a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_rec2__Output(_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_ext_obj_test_enumeration__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_enum1 a1 = {0};
  iioptest1_enum1 a2 = {0};
  iioptest1_enum1 a3 = {0};
  iioptest1_enum1 _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  {
    ilu_shortcardinal _xxx;
    ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    *&a1 = (iioptest1_enum1) _xxx;
  };
  {
    ilu_shortcardinal _xxx;
    ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    *&a3 = (iioptest1_enum1) _xxx;
  };
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_enumeration (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) _retvalue, (ilu_Type)ILU_NIL,  _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) a2, (ilu_Type)ILU_NIL,  _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) a3, (ilu_Type)ILU_NIL,  _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputEnum (_call, (ilu_shortcardinal) _retvalue, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputEnum (_call, (ilu_shortcardinal) a2, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputEnum (_call, (ilu_shortcardinal) a3, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_ext_obj_test_sequence__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_seq1 a1 = {0};
  iioptest1_seq1* a2 = {0};
  iioptest1_seq1 a3 = {0};
  iioptest1_seq1* _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_seq1__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_seq1__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_sequence (_h, &a1, &a2, &a3, &_status);
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
        _size += _iioptest1_seq1__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_seq1__SizeOf (_call, &*a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_seq1__SizeOf (_call, &a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_seq1__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_seq1__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_seq1__Output(_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_seq1__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
        iioptest1_seq1__Free (a2);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_seq1__Free (&a1);
      iioptest1_seq1__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_ext_obj_test_var_record__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_rec1 a1 = {0};
  iioptest1_rec1* a2 = {0};
  iioptest1_rec1 a3 = {0};
  iioptest1_rec1* _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_rec1__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_rec1__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_var_record (_h, &a1, &a2, &a3, &_status);
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
        _size += _iioptest1_rec1__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_rec1__SizeOf (_call, &*a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_rec1__SizeOf (_call, &a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_rec1__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_rec1__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_rec1__Output(_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_rec1__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
        iioptest1_rec1__Free (a2);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_rec1__Free (&a1);
      iioptest1_rec1__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_ext_obj_test_var_array__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_arr1 a1 = {0};
  iioptest1_arr1_slice * a2 = {0};
  iioptest1_arr1 a3 = {0};
  iioptest1_arr1_slice * _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_arr1__Input (_call, a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_arr1__Input (_call, a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_var_array (_h, a1, &a2, a3, &_status);
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
        _size += _iioptest1_arr1__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_arr1__SizeOf (_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_arr1__SizeOf (_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_arr1__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_arr1__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_arr1__Output(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_arr1__Free ((iioptest1_arr1*)_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
        iioptest1_arr1__Free ((iioptest1_arr1*)a2);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_arr1__Free (&a1);
      iioptest1_arr1__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_ext_obj_test_fixed_array__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_arr4 a1 = {0};
  iioptest1_arr4 a2 = {0};
  iioptest1_arr4 a3 = {0};
  iioptest1_arr4_slice * _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_arr4__Input (_call, a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_arr4__Input (_call, a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_fixed_array (_h, a1, a2, a3, &_status);
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
        _size += _iioptest1_arr4__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_arr4__SizeOf (_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_arr4__SizeOf (_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_arr4__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_arr4__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_arr4__Output(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_ext_obj_test_var_union__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_union1 a1 = {0};
  iioptest1_union1* a2 = {0};
  iioptest1_union1 a3 = {0};
  iioptest1_union1* _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_union1__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_union1__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_var_union (_h, &a1, &a2, &a3, &_status);
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
        _size += _iioptest1_union1__SizeOf (_call, &*_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_union1__SizeOf (_call, &*a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_union1__SizeOf (_call, &a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_union1__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_union1__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_union1__Output(_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_union1__Free (_retvalue);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(_retvalue);
        iioptest1_union1__Free (a2);
        /* C++的服务mediator.exe会因为调用如下而中断 */
        CORBA_free(a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_union1__Free (&a1);
      iioptest1_union1__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_ext_obj_test_fixed_union__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_ext_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_union2 a1 = {0};
  iioptest1_union2 a2 = {0};
  iioptest1_union2 a3 = {0};
  iioptest1_union2 _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_ext_obj) _ILU_C_InputObject (_call, _iioptest1_ext_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_union2__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_union2__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_ext_obj_test_fixed_union (_h, &a1, &a2, &a3, &_status);
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
        _size += _iioptest1_union2__SizeOf (_call, &_retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_union2__SizeOf (_call, &a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_union2__SizeOf (_call, &a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_union2__Output(_call, &_retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_union2__Output(_call, &a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_union2__Output(_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_void__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    iioptest1_obj_test_void (_h, &_status);
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

static void _iioptest1_obj_test_short__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_short a1 = {0};
  CORBA_short a2 = {0};
  CORBA_short a3 = {0};
  CORBA_short _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputShortInteger (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_short (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfShortInteger(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfShortInteger(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfShortInteger(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputShortInteger (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortInteger (_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortInteger (_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_long__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_long a1 = {0};
  CORBA_long a2 = {0};
  CORBA_long a3 = {0};
  CORBA_long _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputInteger (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputInteger (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_long (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfInteger(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfInteger(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputInteger (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputInteger (_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputInteger (_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_ushort__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_short a1 = {0};
  CORBA_unsigned_short a2 = {0};
  CORBA_unsigned_short a3 = {0};
  CORBA_unsigned_short _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputShortCardinal (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortCardinal (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_ushort (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfShortCardinal(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfShortCardinal(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfShortCardinal(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputShortCardinal (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortCardinal (_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortCardinal (_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_ulong__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_long a1 = {0};
  CORBA_unsigned_long a2 = {0};
  CORBA_unsigned_long a3 = {0};
  CORBA_unsigned_long _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputCardinal (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_ulong (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfCardinal(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfCardinal(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputCardinal (_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputCardinal (_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputCardinal (_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_float__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_float a1 = {0};
  CORBA_float a2 = {0};
  CORBA_float a3 = {0};
  CORBA_float _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputShortReal (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_float (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfShortReal(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfShortReal(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputShortReal(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortReal(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortReal(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_double__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_double a1 = {0};
  CORBA_double a2 = {0};
  CORBA_double a3 = {0};
  CORBA_double _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputReal (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputReal (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_double (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfReal(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfReal(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputReal(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputReal(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputReal(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_boolean__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_boolean a1 = {0};
  CORBA_boolean a2 = {0};
  CORBA_boolean a3 = {0};
  CORBA_boolean _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ILU_C_InputBoolean (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_boolean (_h, a1, &a2, &a3, &_status);
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
        _size += ILU_C_SizeOfBoolean(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ILU_C_SizeOfBoolean(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ILU_C_OutputBoolean(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ILU_C_OutputBoolean(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ILU_C_OutputBoolean(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_char__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_char a1 = {0};
  CORBA_char a2 = {0};
  CORBA_char a3 = {0};
  CORBA_char _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputShortCharacter (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortCharacter (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_char (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfShortCharacter(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfShortCharacter(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfShortCharacter(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputShortCharacter(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortCharacter(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputShortCharacter(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_octet__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_octet a1 = {0};
  CORBA_octet a2 = {0};
  CORBA_octet a3 = {0};
  CORBA_octet _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputByte (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputByte (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_octet (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfByte(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfByte(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfByte(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputByte(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputByte(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputByte(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_string__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_string a1 = {0};
  iioptest1_string a2 = {0};
  iioptest1_string a3 = {0};
  iioptest1_string _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_string__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_string__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_string (_h, a1, &a2, &a3, &_status);
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
        _size += _iioptest1_string__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_string__SizeOf (_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_string__SizeOf (_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_string__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_string__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_string__Output(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_string__Free (&_retvalue);
        iioptest1_string__Free (&a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_string__Free (&a1);
      iioptest1_string__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_obj_test_longlong__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_long_long a1 = {0};
  CORBA_long_long a2 = {0};
  CORBA_long_long a3 = {0};
  CORBA_long_long _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputLongInteger (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputLongInteger (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_longlong (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfLongInteger(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfLongInteger(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfLongInteger(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputLongInteger(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputLongInteger(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputLongInteger(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_ulonglong__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_unsigned_long_long a1 = {0};
  CORBA_unsigned_long_long a2 = {0};
  CORBA_unsigned_long_long a3 = {0};
  CORBA_unsigned_long_long _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputLongCardinal (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputLongCardinal (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_ulonglong (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfLongCardinal(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfLongCardinal(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfLongCardinal(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputLongCardinal(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputLongCardinal(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputLongCardinal(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_wchar__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_wchar a1 = {0};
  CORBA_wchar a2 = {0};
  CORBA_wchar a3 = {0};
  CORBA_wchar _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ILU_C_InputCharacter (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputCharacter (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_wchar (_h, a1, &a2, &a3, &_status);
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
        _size += ILU_C_SizeOfCharacter(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ILU_C_SizeOfCharacter(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ILU_C_SizeOfCharacter(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ILU_C_OutputCharacter(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ILU_C_OutputCharacter(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ILU_C_OutputCharacter(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_wstring__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  iioptest1_UnicodeString a1 = {0};
  iioptest1_UnicodeString a2 = {0};
  iioptest1_UnicodeString a3 = {0};
  iioptest1_UnicodeString _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  (void) _iioptest1_UnicodeString__Input (_call, &a1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_UnicodeString__Input (_call, &a3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_wstring (_h, a1, &a2, &a3, &_status);
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
        _size += _iioptest1_UnicodeString__SizeOf (_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_UnicodeString__SizeOf (_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += _iioptest1_UnicodeString__SizeOf (_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      _iioptest1_UnicodeString__Output(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_UnicodeString__Output(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      _iioptest1_UnicodeString__Output(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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
        iioptest1_UnicodeString__Free (&_retvalue);
        iioptest1_UnicodeString__Free (&a2);
      };
    case 5: /* input args unmarshalled, but before call */
    case 4:
    case 3:
      iioptest1_UnicodeString__Free (&a1);
      iioptest1_UnicodeString__Free (&a3);
    case 2: /* before unmarshalling any arguments */
      _ILU_C_Object_release(_h);
    case 1: 
break;
    default:
      break;
  };
  return;
}

static void _iioptest1_obj_test_longdouble__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_long_double a1 = {0};
  CORBA_long_double a2 = {0};
  CORBA_long_double a3 = {0};
  CORBA_long_double _retvalue = {0};

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputLongReal (_call, &a1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputLongReal (_call, &a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    _retvalue = iioptest1_obj_test_longdouble (_h, a1, &a2, &a3, &_status);
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
        _size += ilu_SizeOfLongReal(_call, _retvalue, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfLongReal(_call, a2, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
        _size += ilu_SizeOfLongReal(_call, a3, _err);
        if (ILU_ERRNOK(*_err)) goto errexit;
      };
      if (!_ILU_C_BeginReply (_call, ilu_FALSE, _size, _err)) goto errexit;
      ilu_OutputLongReal(_call, _retvalue, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputLongReal(_call, a2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      ilu_OutputLongReal(_call, a3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

static void _iioptest1_obj_test_throw__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */
  CORBA_long case_num = {0};
  ilu_Method _the_method = ilu_MethodOfCall(_call);
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _iioptest1_x1_rec__SizeOf, (ILU_C_OutputFn) _iioptest1_x1_rec__Output, 0, 0 },
    { (unsigned int) 'z', (ilu_Class *) 0, (ILU_C_SizeFn) _iioptest1_x2_rec__SizeOf, (ILU_C_OutputFn) _iioptest1_x2_rec__Output, 0, (ILU_C_FreeFn) iioptest1_x2_rec__Free }};


  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  ilu_InputInteger (_call, &case_num, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    iioptest1_obj_test_throw (_h, case_num, &_status);
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

static void _iioptest1_obj_please_exit__truestub(ilu_Call _call, ilu_Error *_err)
{
  iioptest1_obj _h = {0};
  ILU_C_ENVIRONMENT _status;
  int _state = 1; /* keeps track of state of args for resource mgmt purposes */

  _status.returnCode = ILU_NIL;
  _status.ptr = ILU_NIL;
  ILU_CLER(*_err);
  _state = 2;
  _h = (iioptest1_obj) _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, ilu_TRUE, _err);
  if (ILU_ERRNOK(*_err))
    goto errexit;
  _state = 3;
  _state = 4;
  if (_ILU_C_FinishParameters (_call, _h, _err)) {
    _ILU_C_SetCallerContext(ilu_CallerPassportOfCall(_call));
    _state = 5;
    iioptest1_obj_please_exit (_h, &_status);
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

ILU_C_OBJECT iioptest1_xilu_obj__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_iioptest1_xilu_obj__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_iioptest1_xilu_obj__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT iioptest1_xilu_obj__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _iioptest1_xilu_obj__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_iioptest1_xilu_obj__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void iioptest1_xilu_obj__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_iioptest1_xilu_obj__DefaultClass != ILU_NIL)
    _iioptest1_xilu_obj__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT iioptest1_ext_obj__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_iioptest1_ext_obj__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_iioptest1_ext_obj__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT iioptest1_ext_obj__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _iioptest1_ext_obj__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_iioptest1_ext_obj__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void iioptest1_ext_obj__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_iioptest1_ext_obj__DefaultClass != ILU_NIL)
    _iioptest1_ext_obj__DefaultClass->ilucc_finalize = f;
}

ILU_C_OBJECT iioptest1_obj__CreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (_iioptest1_obj__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_iioptest1_obj__DefaultClass, instance_handle, server, data, ilu_FALSE));
}

ILU_C_OBJECT iioptest1_obj__OTCreateTrue  (ilu_string instance_handle, ILU_C_Server server, void * data)
{
  if (server == ILU_NIL || instance_handle == ILU_NIL || _iioptest1_obj__DefaultClass == ILU_NIL) return ILU_NIL;
  return (ILU_C_CreateTrueObject (_iioptest1_obj__DefaultClass, instance_handle, server, data, ilu_TRUE));
}

void iioptest1_obj__SetDefaultClassFinalization  (ILU_C_FinalizationProc f)
{
  if (_iioptest1_obj__DefaultClass != ILU_NIL)
    _iioptest1_obj__DefaultClass->ilucc_finalize = f;
}

void iioptest1__InitializeServer(void)
{
  extern void _iioptest1__GeneralInitialization(void);
  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _iioptest1__GeneralInitialization ();
  _iioptest1_xilu_obj__DefaultClass = iioptest1_xilu_obj__MakeClass(
    server_iioptest1_xilu_obj_test_optional,
    server_iioptest1_xilu_obj_test_asynchronous,
    server_iioptest1_xilu_obj_test_obj,
    server_iioptest1_xilu_obj_test_fixed_record,
    server_iioptest1_xilu_obj_test_enumeration,
    server_iioptest1_xilu_obj_test_sequence,
    server_iioptest1_xilu_obj_test_var_record,
    server_iioptest1_xilu_obj_test_var_array,
    server_iioptest1_xilu_obj_test_fixed_array,
    server_iioptest1_xilu_obj_test_var_union,
    server_iioptest1_xilu_obj_test_fixed_union,
    server_iioptest1_xilu_obj_test_void,
    server_iioptest1_xilu_obj_test_short,
    server_iioptest1_xilu_obj_test_long,
    server_iioptest1_xilu_obj_test_ushort,
    server_iioptest1_xilu_obj_test_ulong,
    server_iioptest1_xilu_obj_test_float,
    server_iioptest1_xilu_obj_test_double,
    server_iioptest1_xilu_obj_test_boolean,
    server_iioptest1_xilu_obj_test_char,
    server_iioptest1_xilu_obj_test_octet,
    server_iioptest1_xilu_obj_test_string,
    server_iioptest1_xilu_obj_test_longlong,
    server_iioptest1_xilu_obj_test_ulonglong,
    server_iioptest1_xilu_obj_test_wchar,
    server_iioptest1_xilu_obj_test_wstring,
    server_iioptest1_xilu_obj_test_longdouble,
    server_iioptest1_xilu_obj_test_throw,
    server_iioptest1_xilu_obj_please_exit,
    0 /* no finalization */
    );
  _iioptest1_ext_obj__DefaultClass = iioptest1_ext_obj__MakeClass(
    server_iioptest1_ext_obj_test_obj,
    server_iioptest1_ext_obj_test_fixed_record,
    server_iioptest1_ext_obj_test_enumeration,
    server_iioptest1_ext_obj_test_sequence,
    server_iioptest1_ext_obj_test_var_record,
    server_iioptest1_ext_obj_test_var_array,
    server_iioptest1_ext_obj_test_fixed_array,
    server_iioptest1_ext_obj_test_var_union,
    server_iioptest1_ext_obj_test_fixed_union,
    server_iioptest1_ext_obj_test_void,
    server_iioptest1_ext_obj_test_short,
    server_iioptest1_ext_obj_test_long,
    server_iioptest1_ext_obj_test_ushort,
    server_iioptest1_ext_obj_test_ulong,
    server_iioptest1_ext_obj_test_float,
    server_iioptest1_ext_obj_test_double,
    server_iioptest1_ext_obj_test_boolean,
    server_iioptest1_ext_obj_test_char,
    server_iioptest1_ext_obj_test_octet,
    server_iioptest1_ext_obj_test_string,
    server_iioptest1_ext_obj_test_longlong,
    server_iioptest1_ext_obj_test_ulonglong,
    server_iioptest1_ext_obj_test_wchar,
    server_iioptest1_ext_obj_test_wstring,
    server_iioptest1_ext_obj_test_longdouble,
    server_iioptest1_ext_obj_test_throw,
    server_iioptest1_ext_obj_please_exit,
    0 /* no finalization */
    );
  _iioptest1_obj__DefaultClass = iioptest1_obj__MakeClass(
    server_iioptest1_obj_test_void,
    server_iioptest1_obj_test_short,
    server_iioptest1_obj_test_long,
    server_iioptest1_obj_test_ushort,
    server_iioptest1_obj_test_ulong,
    server_iioptest1_obj_test_float,
    server_iioptest1_obj_test_double,
    server_iioptest1_obj_test_boolean,
    server_iioptest1_obj_test_char,
    server_iioptest1_obj_test_octet,
    server_iioptest1_obj_test_string,
    server_iioptest1_obj_test_longlong,
    server_iioptest1_obj_test_ulonglong,
    server_iioptest1_obj_test_wchar,
    server_iioptest1_obj_test_wstring,
    server_iioptest1_obj_test_longdouble,
    server_iioptest1_obj_test_throw,
    server_iioptest1_obj_please_exit,
    0 /* no finalization */
    );

  ilu_SetMethodStubProc(&_iioptest1_xilu_obj__ILUType->cl_methods[0], (ilu_StubProc) _iioptest1_xilu_obj_test_optional__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_xilu_obj__ILUType->cl_methods[1], (ilu_StubProc) _iioptest1_xilu_obj_test_asynchronous__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[0], (ilu_StubProc) _iioptest1_ext_obj_test_obj__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[1], (ilu_StubProc) _iioptest1_ext_obj_test_fixed_record__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[2], (ilu_StubProc) _iioptest1_ext_obj_test_enumeration__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[3], (ilu_StubProc) _iioptest1_ext_obj_test_sequence__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[4], (ilu_StubProc) _iioptest1_ext_obj_test_var_record__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[5], (ilu_StubProc) _iioptest1_ext_obj_test_var_array__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[6], (ilu_StubProc) _iioptest1_ext_obj_test_fixed_array__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[7], (ilu_StubProc) _iioptest1_ext_obj_test_var_union__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_ext_obj__ILUType->cl_methods[8], (ilu_StubProc) _iioptest1_ext_obj_test_fixed_union__truestub, _ILU_C_LanguageIndex);;

  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[0], (ilu_StubProc) _iioptest1_obj_test_void__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[1], (ilu_StubProc) _iioptest1_obj_test_short__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[2], (ilu_StubProc) _iioptest1_obj_test_long__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[3], (ilu_StubProc) _iioptest1_obj_test_ushort__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[4], (ilu_StubProc) _iioptest1_obj_test_ulong__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[5], (ilu_StubProc) _iioptest1_obj_test_float__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[6], (ilu_StubProc) _iioptest1_obj_test_double__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[7], (ilu_StubProc) _iioptest1_obj_test_boolean__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[8], (ilu_StubProc) _iioptest1_obj_test_char__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[9], (ilu_StubProc) _iioptest1_obj_test_octet__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[10], (ilu_StubProc) _iioptest1_obj_test_string__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[11], (ilu_StubProc) _iioptest1_obj_test_longlong__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[12], (ilu_StubProc) _iioptest1_obj_test_ulonglong__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[13], (ilu_StubProc) _iioptest1_obj_test_wchar__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[14], (ilu_StubProc) _iioptest1_obj_test_wstring__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[15], (ilu_StubProc) _iioptest1_obj_test_longdouble__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[16], (ilu_StubProc) _iioptest1_obj_test_throw__truestub, _ILU_C_LanguageIndex);;
  ilu_SetMethodStubProc(&_iioptest1_obj__ILUType->cl_methods[17], (ilu_StubProc) _iioptest1_obj_please_exit__truestub, _ILU_C_LanguageIndex);;
}

