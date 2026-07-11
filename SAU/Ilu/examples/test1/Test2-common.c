/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Jul 11 06:49:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Thu Jul 10 17:58:44 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Thu Jun 19 13:16:01 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Test2.h"

ilu_Class _Test2_P__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Test2_U2__IoFns = { ilu_union_tk, "ilut:dSc47PlWucPws3UX8kBfzRQVxyF", { sizeof(Test2_U2) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test2_P__IoFns = { ilu_object_tk, "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS", { 0 }, 0, 0, 0, 0, 0 };


ILU_C_Class Test2_P__MakeClass(
  CORBA_long (*Test2_P_SR_to_I__Impl)
     (Test2_P _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(2 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _Test2_P__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test2_P_SR_to_I__Impl;
  ans->ilucc_sections[done].ilucdts_introType = ILU_NIL;
  ans->ilucc_sections[done].ilucdts_methods = ILU_NIL;
  return ans;
fale1:
  for (i=0; i<done; i++) 
    ilu_free(ans->ilucc_sections[i].ilucdts_methods);
fale0:
  ilu_free(ans);
  return ILU_NIL;
}
CORBA_long Test2_P_SR_to_I (Test2_P _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long (*_f)(Test2_P, CORBA_float, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_long _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_long (*)(Test2_P, CORBA_float, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test2_P__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, i, _status));
}

void Test2_P__SetUserData (Test2_P self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Test2_P__GetUserData (Test2_P self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _Test2__Exception_E1 = ILU_NIL;
#include <stdarg.h>

void Test2__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_Test2_E1) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_TheU));
    *(Test1_TheU*)stat->ptr = *va_arg (ap, Test1_TheU*);
    stat->freeRoutine = (void (*) (void *)) Test1_TheU__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to Test2__BindExceptionValue");
  va_end (ap);
}

Test2_U2* _Test2_U2__Input (ilu_Call _call, Test2_U2* _ref, ilu_Error *_err)
{
  Test2_U2* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test2_U2), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test2_U2*) ilu_MallocE(sizeof (Test2_U2), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test2_U2));
  };
  switch (tag) {
    case Test1_ev1:
      (void) _ilu_CString__Input (_call, &_val->_u.CString, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev3:
      *&_val->_u.O1 = _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev7:
      *&_val->_u.P = _ILU_C_InputObject (_call, _Test2_P__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test2_U2__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (Test1_TheE) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test2_U2__Output (ilu_Call _call, Test2_U2* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test2_U2), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Test1_ev1:
      _ilu_CString__Output (_call, _val->_u.CString, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev3:
      _ILU_C_OutputObject(_call, (Test1_TheO1) _val->_u.O1, _Test1_TheO1__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev7:
      _ILU_C_OutputObject(_call, (Test2_P) _val->_u.P, _Test2_P__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test2_U2__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test2_U2__SizeOf (ilu_Call _call, Test2_U2* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test2_U2), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Test1_ev1:
      size += _ilu_CString__SizeOf(_call, _val->_u.CString, _err);
      break;
    case Test1_ev3:
      size += _ILU_C_SizeOfObject(_call, (Test1_TheO1) _val->_u.O1, _Test1_TheO1__ILUType, ilu_FALSE, _err);
      break;
    case Test1_ev7:
      size += _ILU_C_SizeOfObject(_call, (Test2_P) _val->_u.P, _Test2_P__ILUType, ilu_FALSE, _err);
      break;
    default:
      fprintf (stderr, "_Test2_U2__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test2_U2__Free (Test2_U2* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test2_U2 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case Test1_ev1:
      ilu_CString__Free ((ilu_CString *) &_val->_u.CString);
      break;
    case Test1_ev3:
      Test1_TheO1__Free (&_val->_u.O1);
      break;
    case Test1_ev7:
      Test2_P__Free (&_val->_u.P);
      break;
    default:
      fprintf (stderr, "Test2_U2__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test2_U2 *CORBA_sequence_Test2_U2_allocbuf (CORBA_unsigned_long _count)
{
  Test2_U2 *_p;
  CORBA_unsigned_long _size = sizeof(Test2_U2) * _count;

  if ((_p = (Test2_U2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test2_U2* Test2_U2__alloc ()
{
  return ((Test2_U2*) CORBA_sequence_Test2_U2_allocbuf(1));
}

void Test2_P__Free (Test2_P* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test2_P */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Test2_P *CORBA_sequence_Test2_P_allocbuf (CORBA_unsigned_long _count)
{
  Test2_P *_p;
  CORBA_unsigned_long _size = sizeof(Test2_P) * _count;

  if ((_p = (Test2_P *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void _Test2__GeneralInitialization (void)
{
  static ilu_boolean initialized = ilu_FALSE;
  ilu_Error lerr = ILU_INIT_NO_ERR;
  ilu_Class cl = ILU_NIL;
  ilu_Method m = ILU_NIL;
  ilu_Mutex otmu = ilu_GetOTMutex();
  ilu_boolean newreg;

  if (initialized)
    return;
  initialized = ilu_TRUE;
  _ILU_C_InitializeCRuntime();
  _ILU_C_CheckStubConsistency("Test2", "2.0beta1", "v2 (2.0beta1)");
  _Test1__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _Test2__Exception_E1 = ilu_DefineException("Test2", "E1", "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("Test2.P",	/*name*/
	NULL,	/*no brand*/
	"ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	1,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Test2_P__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"SR-to-I",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "i", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  ilu_RegisterAliasType("T1O3", "Test2", ILU_NIL, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",
    "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("T1U3", "Test2", ILU_NIL, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj",
    "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("T1U2", "Test2", ILU_NIL, "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9",
    "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("T1U", "Test2", ILU_NIL, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW",
    "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test2_U2__IoFns.kernelType = type = ilu_RegisterUnionType("U2", "Test2", ILU_NIL, "ilut:dSc47PlWucPws3UX8kBfzRQVxyF",
    "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",	/* UID of discriminant type */
    3,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "ev1";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "ev3";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "ev7";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test2_P__IoFns.kernelType = ilu_RegisterObjectType("P", "Test2", ILU_NIL, "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS",
    _Test2_P__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("F", "Test2", ILU_NIL, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",
    "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Test2_U2__IoFns.inputFn = (ILU_C_InputFn) _Test2_U2__Input;
  _Test2_U2__IoFns.outFn = (ILU_C_OutputFn) _Test2_U2__Output;
  _Test2_U2__IoFns.sizeFn = (ILU_C_SizeFn) _Test2_U2__SizeOf;
  _Test2_U2__IoFns.freeFn = (ILU_C_FreeFn) Test2_U2__Free;
  _ILU_C_RegisterIoFns (&_Test2_U2__IoFns);

  _Test2_P__IoFns.properties.object_class = _Test2_P__ILUType;
  _ILU_C_RegisterIoFns (&_Test2_P__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

