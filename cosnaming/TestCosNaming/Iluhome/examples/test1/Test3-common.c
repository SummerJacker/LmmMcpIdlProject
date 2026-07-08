/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:52 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Test3.h"

ilu_Class _Test3_O__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Test3_FU__IoFns = { ilu_union_tk, "ilut:p7oYELOBiB2uFXthQiHxgFh1H8p", { sizeof(Test3_FU) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test3_O__IoFns = { ilu_object_tk, "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg", { 0 }, 0, 0, 0, 0, 0 };


ILU_C_Class Test3_O__MakeClass(
  Test2_T1U* (*Test3_O_I_to_Test1U__Impl)
     (Test3_O _handle, CORBA_long i, ILU_C_ENVIRONMENT *_status),
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test3_O _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test3_O _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test3_O _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*Test2_P_SR_to_I__Impl)
     (Test3_O _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(4 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _Test3_O__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test3_O_I_to_Test1U__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _Test1_O3__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_O3_RS_R_to_R_IS__Impl;
  method_block[1] = (_ILU_C_Method) Test1_O3_O1_U_to_U__Impl;
  method_block[2] = (_ILU_C_Method) Test1_O3_BS_to_I__Impl;

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
Test2_T1U* Test3_O_I_to_Test1U (Test3_O _handle, CORBA_long i, ILU_C_ENVIRONMENT *_status)
{
  Test2_T1U* (*_f)(Test3_O, CORBA_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test2_T1U* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test2_T1U* (*)(Test3_O, CORBA_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test3_O__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, i, _status));
}

void Test3_O__SetUserData (Test3_O self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Test3_O__GetUserData (Test3_O self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _Test3__Exception_E1 = ILU_NIL;
#include <stdarg.h>

void Test3__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_Test3_E1) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (ilu_CString));
    *(ilu_CString*)stat->ptr = va_arg (ap, ilu_CString);
    stat->freeRoutine = (void (*) (void *)) ilu_CString__Free;
  }
  else if (stat->returnCode == ex_Test1_E1) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_TheU));
    *(Test1_TheU*)stat->ptr = *va_arg (ap, Test1_TheU*);
    stat->freeRoutine = (void (*) (void *)) Test1_TheU__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to Test3__BindExceptionValue");
  va_end (ap);
}

Test3_FU* _Test3_FU__Input (ilu_Call _call, Test3_FU* _ref, ilu_Error *_err)
{
  Test3_FU* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test3_FU), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test3_FU*) ilu_MallocE(sizeof (Test3_FU), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test3_FU));
  };
  switch (tag) {
    case Test1_ev1:
      *&_val->_u.O = _ILU_C_InputObject (_call, _Test3_O__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev3:
      ilu_InputInteger (_call, &_val->_u.integer, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test3_FU__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
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

void _Test3_FU__Output (ilu_Call _call, Test3_FU* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test3_FU), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Test1_ev1:
      _ILU_C_OutputObject(_call, (Test3_O) _val->_u.O, _Test3_O__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev3:
      ilu_OutputInteger (_call, _val->_u.integer, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test3_FU__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test3_FU__SizeOf (ilu_Call _call, Test3_FU* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test3_FU), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Test1_ev1:
      size += _ILU_C_SizeOfObject(_call, (Test3_O) _val->_u.O, _Test3_O__ILUType, ilu_FALSE, _err);
      break;
    case Test1_ev3:
      size += ilu_SizeOfInteger(_call, _val->_u.integer, _err);
      break;
    default:
      fprintf (stderr, "_Test3_FU__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test3_FU__Free (Test3_FU* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test3_FU */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case Test1_ev1:
      Test3_O__Free (&_val->_u.O);
      break;
    case Test1_ev3:
      break;
    default:
      fprintf (stderr, "Test3_FU__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test3_FU *CORBA_sequence_Test3_FU_allocbuf (CORBA_unsigned_long _count)
{
  Test3_FU *_p;
  CORBA_unsigned_long _size = sizeof(Test3_FU) * _count;

  if ((_p = (Test3_FU *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test3_FU* Test3_FU__alloc ()
{
  return ((Test3_FU*) CORBA_sequence_Test3_FU_allocbuf(1));
}

void Test3_O__Free (Test3_O* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test3_O */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Test3_O *CORBA_sequence_Test3_O_allocbuf (CORBA_unsigned_long _count)
{
  Test3_O *_p;
  CORBA_unsigned_long _size = sizeof(Test3_O) * _count;

  if ((_p = (Test3_O *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void _Test3__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Test3", "2.0beta1", "v2 (2.0beta1)");
  _Test1__GeneralInitialization();
  _Test2__GeneralInitialization();
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _Test3__Exception_E1 = ilu_DefineException("Test3", "E1", "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",
	"ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS",
	NULL};
    cl = ilu_DefineObjectType("Test3.O",	/*name*/
	NULL,	/*no brand*/
	"ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	1,	/*n methods*/
	2,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Test3_O__ILUType = cl;
  }
  { ilu_Exception	exns[2];
    exns[0] = ex_Test3_E1;
    exns[1] = ex_Test1_E1;
    m = ilu_DefineMethod(cl, 0,
	"I-to-Test1U",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	2,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "i", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Test3_FU__IoFns.kernelType = type = ilu_RegisterUnionType("FU", "Test3", ILU_NIL, "ilut:p7oYELOBiB2uFXthQiHxgFh1H8p",
    "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",	/* UID of discriminant type */
    2,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg", /* arm type */
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
      "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "ev3";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("T2T1O3", "Test3", ILU_NIL, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",
    "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("T2T1U3", "Test3", ILU_NIL, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj",
    "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test3_O__IoFns.kernelType = ilu_RegisterObjectType("O", "Test3", ILU_NIL, "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg",
    _Test3_O__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Test3_FU__IoFns.inputFn = (ILU_C_InputFn) _Test3_FU__Input;
  _Test3_FU__IoFns.outFn = (ILU_C_OutputFn) _Test3_FU__Output;
  _Test3_FU__IoFns.sizeFn = (ILU_C_SizeFn) _Test3_FU__SizeOf;
  _Test3_FU__IoFns.freeFn = (ILU_C_FreeFn) Test3_FU__Free;
  _ILU_C_RegisterIoFns (&_Test3_FU__IoFns);

  _Test3_O__IoFns.properties.object_class = _Test3_O__ILUType;
  _ILU_C_RegisterIoFns (&_Test3_O__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

