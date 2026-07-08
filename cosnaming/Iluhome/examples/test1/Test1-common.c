/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:52 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <stdio.h>
#include <string.h> /* used for error statements */
#include "Test1.h"

ilu_Class _Test1_O4__ILUType = NULL;
ilu_Class _Test1_P__ILUType = NULL;
ilu_Class _Test1_O3__ILUType = NULL;
ilu_Class _Test1_TheO1__ILUType = NULL;
ilu_Class _Test1_O2__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _Test1_O4__IoFns = { ilu_object_tk, "ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_P__IoFns = { ilu_object_tk, "ilut:dY9O+Pbe716S3dZTXTUzbvfKs87", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_O3__IoFns = { ilu_object_tk, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_TheO1__IoFns = { ilu_object_tk, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U_scard__IoFns = { ilu_union_tk, "ilut:jAPE1zV6LdNhqmjYERCpES3yBpF", { sizeof(Test1_U_scard) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U_card__IoFns = { ilu_union_tk, "ilut:nY7eVP682HUe0ogce3ooQPrruH2", { sizeof(Test1_U_card) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U_int__IoFns = { ilu_union_tk, "ilut:b8uuARf6GuBoeD-p8pOwYMjTZ69", { sizeof(Test1_U_int) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U_byte__IoFns = { ilu_union_tk, "ilut:eEo4ZOFawZcut8dv19+C65eQlWg", { sizeof(Test1_U_byte) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U4__IoFns = { ilu_union_tk, "ilut:iqhShhLIYYhlWJMKqapun2JReYg", { sizeof(Test1_U4) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U3__IoFns = { ilu_union_tk, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj", { sizeof(Test1_U3) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U2__IoFns = { ilu_union_tk, "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9", { sizeof(Test1_U2) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_TheE__IoFns = { ilu_enumeration_tk, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_U1__IoFns = { ilu_union_tk, "ilut:jzGuxkzcjrh34B-89hMcq2ovHB6", { sizeof(Test1_U1) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_TheU__IoFns = { ilu_union_tk, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", { sizeof(Test1_TheU) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_OO2__IoFns = { ilu_union_tk, "ilut:l-kEjRgqgSEZbJTDUfMwmrp5361", { sizeof(Test1_OO2) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_O2__IoFns = { ilu_object_tk, "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_TheOO__IoFns = { ilu_optional_tk, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA", { sizeof(Test1_TheOO) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_RO__IoFns = { ilu_optional_tk, "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", { sizeof(Test1_RO) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_TheRS__IoFns = { ilu_sequence_tk, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac", { sizeof(Test1_TheRS) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_TheR__IoFns = { ilu_record_tk, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", { sizeof(Test1_TheR) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_BS__IoFns = { ilu_sequence_tk, "ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3", { sizeof(Test1_BS) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_A2__IoFns = { ilu_array_tk, "ilut:kM2HH51HMYTWu-khgczpbgNaama", { sizeof(Test1_A2) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_TheA1__IoFns = { ilu_array_tk, "ilut:h3Dnvis94UwnmFURfYsCp700jVy", { sizeof(Test1_TheA1) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_A0__IoFns = { ilu_array_tk, "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r", { sizeof(Test1_A0) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_CSS__IoFns = { ilu_sequence_tk, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", { sizeof(Test1_CSS) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_ScS__IoFns = { ilu_sequence_tk, "ilut:iqqhSf395+BafbY8Oo2elFQD1bK", { sizeof(Test1_ScS) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _Test1_IS__IoFns = { ilu_sequence_tk, "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO", { sizeof(Test1_IS) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class Test1_O4__MakeClass(
  CORBA_double (*Test1_O4_R_to_R__Impl)
     (Test1_O4 _handle, CORBA_double r, ILU_C_ENVIRONMENT *_status),
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test1_O4 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test1_O4 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test1_O4 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(3 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _Test1_O4__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_O4_R_to_R__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _Test1_O3__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_O3_RS_R_to_R_IS__Impl;
  method_block[1] = (_ILU_C_Method) Test1_O3_O1_U_to_U__Impl;
  method_block[2] = (_ILU_C_Method) Test1_O3_BS_to_I__Impl;
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
ILU_C_Class Test1_P__MakeClass(
  Test1_IS* (*Test1_P_m2__Impl)
     (Test1_P _handle, CORBA_long j, ILU_C_ENVIRONMENT *_status),
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test1_P _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test1_P _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test1_P _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize)
{
  ILU_C_Class ans = ilu_malloc(sizeof(*ans));
  _ILU_C_Method *method_block;
  int i, done=0;
  if (!ans) return ans;
  ans->ilucc_finalize = _finalize;
  ans->ilucc_sections = ilu_malloc(3 * sizeof(ans->ilucc_sections[0]));
  if (!ans->ilucc_sections)
    goto fale0;

  ans->ilucc_sections[done].ilucdts_introType = _Test1_P__ILUType;
  method_block = ilu_malloc(1 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_P_m2__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _Test1_O3__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_O3_RS_R_to_R_IS__Impl;
  method_block[1] = (_ILU_C_Method) Test1_O3_O1_U_to_U__Impl;
  method_block[2] = (_ILU_C_Method) Test1_O3_BS_to_I__Impl;
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
ILU_C_Class Test1_O3__MakeClass(
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test1_O3 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test1_O3 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test1_O3 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Test1_O3__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_O3_RS_R_to_R_IS__Impl;
  method_block[1] = (_ILU_C_Method) Test1_O3_O1_U_to_U__Impl;
  method_block[2] = (_ILU_C_Method) Test1_O3_BS_to_I__Impl;
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
ILU_C_Class Test1_TheO1__MakeClass(
  Test1_U* (*Test1_TheO1_U_CSS_to_U__Impl)
     (Test1_TheO1 _handle, Test1_U* u, Test1_CSS* css, ILU_C_ENVIRONMENT *_status),
  Test1_RO (*Test1_TheO1_f_CSS_to_RO__Impl)
     (Test1_TheO1 _handle, Test1_CSS* css, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*Test1_TheO1_R_ScS_to_F__Impl)
     (Test1_TheO1 _handle, Test1_R* r, Test1_ScS s, ILU_C_ENVIRONMENT *_status),
  void (*Test1_TheO1_a_RO__Impl)
     (Test1_TheO1 _handle, Test1_RO ro, ILU_C_ENVIRONMENT *_status),
  Test1_O2 (*Test1_TheO1_get_O2__Impl)
     (Test1_TheO1 _handle, ILU_C_ENVIRONMENT *_status),
  Test1_O3 (*Test1_TheO1_get_O3__Impl)
     (Test1_TheO1 _handle, CORBA_boolean subclass, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Test1_TheO1__ILUType;
  method_block = ilu_malloc(6 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_TheO1_U_CSS_to_U__Impl;
  method_block[1] = (_ILU_C_Method) Test1_TheO1_f_CSS_to_RO__Impl;
  method_block[2] = (_ILU_C_Method) Test1_TheO1_R_ScS_to_F__Impl;
  method_block[3] = (_ILU_C_Method) Test1_TheO1_a_RO__Impl;
  method_block[4] = (_ILU_C_Method) Test1_TheO1_get_O2__Impl;
  method_block[5] = (_ILU_C_Method) Test1_TheO1_get_O3__Impl;
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
ILU_C_Class Test1_O2__MakeClass(
  Test1_CSS* (*Test1_O2_OO_A0_to_CSS__Impl)
     (Test1_O2 _handle, Test1_OO o, Test1_A0 a, ILU_C_ENVIRONMENT *_status),
  Test1_A0_slice * (*Test1_O2_R_I_A1_to_I_A0__Impl)
     (Test1_O2 _handle, Test1_R* r, Test1_I* i, Test1_A1 a, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _Test1_O2__ILUType;
  method_block = ilu_malloc(2 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) Test1_O2_OO_A0_to_CSS__Impl;
  method_block[1] = (_ILU_C_Method) Test1_O2_R_I_A1_to_I_A0__Impl;
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
CORBA_double Test1_O4_R_to_R (Test1_O4 _handle, CORBA_double r, ILU_C_ENVIRONMENT *_status)
{
  CORBA_double (*_f)(Test1_O4, CORBA_double, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_double _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_double (*)(Test1_O4, CORBA_double, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_O4__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, r, _status));
}

Test1_IS* Test1_P_m2 (Test1_P _handle, CORBA_long j, ILU_C_ENVIRONMENT *_status)
{
  Test1_IS* (*_f)(Test1_P, CORBA_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_IS* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_IS* (*)(Test1_P, CORBA_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_P__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, j, _status));
}

Test1_IS* Test1_O3_RS_R_to_R_IS (Test1_O3 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status)
{
  Test1_IS* (*_f)(Test1_O3, Test1_RS*, Test1_R**, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_IS* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_IS* (*)(Test1_O3, Test1_RS*, Test1_R**, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_O3__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, r, r2, _status));
}

void Test1_O3_O1_U_to_U (Test1_O3 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(Test1_O3, Test1_O1, Test1_U*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(Test1_O3, Test1_O1, Test1_U*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_O3__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, o, u, _status);
}

Test1_I Test1_O3_BS_to_I (Test1_O3 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status)
{
  Test1_I (*_f)(Test1_O3, Test1_BS*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_I _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_I (*)(Test1_O3, Test1_BS*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_O3__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, b, _status));
}

Test1_U* Test1_TheO1_U_CSS_to_U (Test1_TheO1 _handle, Test1_U* u, Test1_CSS* css, ILU_C_ENVIRONMENT *_status)
{
  Test1_U* (*_f)(Test1_TheO1, Test1_U*, Test1_CSS*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_U* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_U* (*)(Test1_TheO1, Test1_U*, Test1_CSS*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_TheO1__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, u, css, _status));
}

Test1_RO Test1_TheO1_f_CSS_to_RO (Test1_TheO1 _handle, Test1_CSS* css, ILU_C_ENVIRONMENT *_status)
{
  Test1_RO (*_f)(Test1_TheO1, Test1_CSS*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_RO _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_RO (*)(Test1_TheO1, Test1_CSS*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_TheO1__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, css, _status));
}

CORBA_float Test1_TheO1_R_ScS_to_F (Test1_TheO1 _handle, Test1_R* r, Test1_ScS s, ILU_C_ENVIRONMENT *_status)
{
  CORBA_float (*_f)(Test1_TheO1, Test1_R*, Test1_ScS, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_float _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_float (*)(Test1_TheO1, Test1_R*, Test1_ScS, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_TheO1__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, r, s, _status));
}

void Test1_TheO1_a_RO (Test1_TheO1 _handle, Test1_RO ro, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(Test1_TheO1, Test1_RO, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(Test1_TheO1, Test1_RO, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_TheO1__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, ro, _status);
}

Test1_O2 Test1_TheO1_get_O2 (Test1_TheO1 _handle, ILU_C_ENVIRONMENT *_status)
{
  Test1_O2 (*_f)(Test1_TheO1, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_O2 _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_O2 (*)(Test1_TheO1, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_TheO1__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

Test1_O3 Test1_TheO1_get_O3 (Test1_TheO1 _handle, CORBA_boolean subclass, ILU_C_ENVIRONMENT *_status)
{
  Test1_O3 (*_f)(Test1_TheO1, CORBA_boolean, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_O3 _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_O3 (*)(Test1_TheO1, CORBA_boolean, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_TheO1__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, subclass, _status));
}

Test1_CSS* Test1_O2_OO_A0_to_CSS (Test1_O2 _handle, Test1_OO o, Test1_A0 a, ILU_C_ENVIRONMENT *_status)
{
  Test1_CSS* (*_f)(Test1_O2, Test1_OO, Test1_A0, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_CSS* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_CSS* (*)(Test1_O2, Test1_OO, Test1_A0, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_O2__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, o, a, _status));
}

Test1_A0_slice * Test1_O2_R_I_A1_to_I_A0 (Test1_O2 _handle, Test1_R* r, Test1_I* i, Test1_A1 a, ILU_C_ENVIRONMENT *_status)
{
  Test1_A0_slice * (*_f)(Test1_O2, Test1_R*, Test1_I*, Test1_A1, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    Test1_A0_slice * _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (Test1_A0_slice * (*)(Test1_O2, Test1_R*, Test1_I*, Test1_A1, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _Test1_O2__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, r, i, a, _status));
}

void Test1_O4__SetUserData (Test1_O4 self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Test1_O4__GetUserData (Test1_O4 self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Test1_P__SetUserData (Test1_P self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Test1_P__GetUserData (Test1_P self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Test1_O3__SetUserData (Test1_O3 self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Test1_O3__GetUserData (Test1_O3 self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Test1_TheO1__SetUserData (Test1_TheO1 self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Test1_TheO1__GetUserData (Test1_TheO1 self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void Test1_O2__SetUserData (Test1_O2 self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *Test1_O2__GetUserData (Test1_O2 self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _Test1__Exception_E1 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E2 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_CantCreate = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E3 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E4 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E5 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E6 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E7 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E8 = ILU_NIL;
ILU_C_ExceptionCode _Test1__Exception_E9 = ILU_NIL;
#include <stdarg.h>

void Test1__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_Test1_E1) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_TheU));
    *(Test1_TheU*)stat->ptr = *va_arg (ap, Test1_TheU*);
    stat->freeRoutine = (void (*) (void *)) Test1_TheU__Free;
  }
  else if (stat->returnCode == ex_Test1_E2) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (CORBA_long));
    *(CORBA_long*)stat->ptr = va_arg (ap, CORBA_long);
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_Test1_CantCreate) {
    stat->ptr = ILU_NIL;
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_Test1_E3) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_RO));
    *(Test1_RO*)stat->ptr = va_arg (ap, Test1_RO);
    stat->freeRoutine = (void (*) (void *)) Test1_RO__Free;
  }
  else if (stat->returnCode == ex_Test1_E4) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_TheO1));
    *(Test1_TheO1*)stat->ptr = va_arg (ap, Test1_TheO1);
    stat->freeRoutine = (void (*) (void *)) Test1_TheO1__Free;
  }
  else if (stat->returnCode == ex_Test1_E5) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_A0));
    memcpy ((void *)((Test1_A0_slice *)stat->ptr), (void *) va_arg(ap, Test1_A0_slice *), sizeof(Test1_A0));
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_Test1_E6) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_TheRS));
    *(Test1_TheRS*)stat->ptr = *va_arg (ap, Test1_TheRS*);
    stat->freeRoutine = (void (*) (void *)) Test1_TheRS__Free;
  }
  else if (stat->returnCode == ex_Test1_E7) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (ilu_CString));
    *(ilu_CString*)stat->ptr = va_arg (ap, ilu_CString);
    stat->freeRoutine = (void (*) (void *)) ilu_CString__Free;
  }
  else if (stat->returnCode == ex_Test1_E8) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_TheA1));
    memcpy ((void *)((Test1_TheA1_slice *)stat->ptr), (void *) va_arg(ap, Test1_TheA1_slice *), sizeof(Test1_TheA1));
    stat->freeRoutine = (void (*) (void *)) Test1_TheA1__Free;
  }
  else if (stat->returnCode == ex_Test1_E9) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (Test1_TheR));
    *(Test1_TheR*)stat->ptr = *va_arg (ap, Test1_TheR*);
    stat->freeRoutine = (void (*) (void *)) Test1_TheR__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to Test1__BindExceptionValue");
  va_end (ap);
}

void Test1_O4__Free (Test1_O4* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_O4 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Test1_O4 *CORBA_sequence_Test1_O4_allocbuf (CORBA_unsigned_long _count)
{
  Test1_O4 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_O4) * _count;

  if ((_p = (Test1_O4 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void Test1_P__Free (Test1_P* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_P */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Test1_P *CORBA_sequence_Test1_P_allocbuf (CORBA_unsigned_long _count)
{
  Test1_P *_p;
  CORBA_unsigned_long _size = sizeof(Test1_P) * _count;

  if ((_p = (Test1_P *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void Test1_O3__Free (Test1_O3* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_O3 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Test1_O3 *CORBA_sequence_Test1_O3_allocbuf (CORBA_unsigned_long _count)
{
  Test1_O3 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_O3) * _count;

  if ((_p = (Test1_O3 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void Test1_TheO1__Free (Test1_TheO1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_TheO1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Test1_TheO1 *CORBA_sequence_Test1_TheO1_allocbuf (CORBA_unsigned_long _count)
{
  Test1_TheO1 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_TheO1) * _count;

  if ((_p = (Test1_TheO1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U_scard* _Test1_U_scard__Input (ilu_Call _call, Test1_U_scard* _ref, ilu_Error *_err)
{
  Test1_U_scard* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortcardinal_tk, ILU_C_KERNEL_TYPE(Test1_U_scard), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U_scard*) ilu_MallocE(sizeof (Test1_U_scard), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U_scard));
  };
  switch (tag) {
    case 0:
      (void) _Test1_TheR__Input (_call, &_val->_u.R,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      *&_val->_u.One = _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_scard__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_unsigned_short) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_U_scard__Output (ilu_Call _call, Test1_U_scard* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortcardinal_tk, ILU_C_KERNEL_TYPE(Test1_U_scard), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _Test1_TheR__Output(_call, &_val->_u.R, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _ILU_C_OutputObject(_call, (Test1_TheO1) _val->_u.One, _Test1_TheO1__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_scard__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U_scard__SizeOf (ilu_Call _call, Test1_U_scard* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortcardinal_tk, ILU_C_KERNEL_TYPE(Test1_U_scard), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _Test1_TheR__SizeOf (_call, &_val->_u.R, _err);
      break;
    case 1:
      size += _ILU_C_SizeOfObject(_call, (Test1_TheO1) _val->_u.One, _Test1_TheO1__ILUType, ilu_FALSE, _err);
      break;
    default:
      fprintf (stderr, "_Test1_U_scard__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U_scard__Free (Test1_U_scard* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U_scard */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      Test1_TheR__Free (&_val->_u.R);
      break;
    case 1:
      Test1_TheO1__Free (&_val->_u.One);
      break;
    default:
      fprintf (stderr, "Test1_U_scard__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test1_U_scard *CORBA_sequence_Test1_U_scard_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U_scard *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U_scard) * _count;

  if ((_p = (Test1_U_scard *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U_scard* Test1_U_scard__alloc ()
{
  return ((Test1_U_scard*) CORBA_sequence_Test1_U_scard_allocbuf(1));
}

Test1_U_card* _Test1_U_card__Input (ilu_Call _call, Test1_U_card* _ref, ilu_Error *_err)
{
  Test1_U_card* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_cardinal_tk, ILU_C_KERNEL_TYPE(Test1_U_card), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U_card*) ilu_MallocE(sizeof (Test1_U_card), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U_card));
  };
  switch (tag) {
    case 0:
      (void) _Test1_TheR__Input (_call, &_val->_u.R,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      *&_val->_u.O2 = _ILU_C_InputObject (_call, _Test1_O2__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_card__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_unsigned_long) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_U_card__Output (ilu_Call _call, Test1_U_card* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_cardinal_tk, ILU_C_KERNEL_TYPE(Test1_U_card), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _Test1_TheR__Output(_call, &_val->_u.R, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _ILU_C_OutputObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_card__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U_card__SizeOf (ilu_Call _call, Test1_U_card* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_cardinal_tk, ILU_C_KERNEL_TYPE(Test1_U_card), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _Test1_TheR__SizeOf (_call, &_val->_u.R, _err);
      break;
    case 1:
      size += _ILU_C_SizeOfObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err);
      break;
    default:
      fprintf (stderr, "_Test1_U_card__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U_card__Free (Test1_U_card* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U_card */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      Test1_TheR__Free (&_val->_u.R);
      break;
    case 1:
      Test1_O2__Free (&_val->_u.O2);
      break;
    default:
      fprintf (stderr, "Test1_U_card__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test1_U_card *CORBA_sequence_Test1_U_card_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U_card *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U_card) * _count;

  if ((_p = (Test1_U_card *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U_card* Test1_U_card__alloc ()
{
  return ((Test1_U_card*) CORBA_sequence_Test1_U_card_allocbuf(1));
}

Test1_U_int* _Test1_U_int__Input (ilu_Call _call, Test1_U_int* _ref, ilu_Error *_err)
{
  Test1_U_int* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_integer_tk, ILU_C_KERNEL_TYPE(Test1_U_int), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U_int*) ilu_MallocE(sizeof (Test1_U_int), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U_int));
  };
  switch (tag) {
    case 0:
      (void) _Test1_TheR__Input (_call, &_val->_u.R,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      *&_val->_u.O2 = _ILU_C_InputObject (_call, _Test1_O2__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_int__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_long) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_U_int__Output (ilu_Call _call, Test1_U_int* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_integer_tk, ILU_C_KERNEL_TYPE(Test1_U_int), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _Test1_TheR__Output(_call, &_val->_u.R, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _ILU_C_OutputObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_int__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U_int__SizeOf (ilu_Call _call, Test1_U_int* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_integer_tk, ILU_C_KERNEL_TYPE(Test1_U_int), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _Test1_TheR__SizeOf (_call, &_val->_u.R, _err);
      break;
    case 1:
      size += _ILU_C_SizeOfObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err);
      break;
    default:
      fprintf (stderr, "_Test1_U_int__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U_int__Free (Test1_U_int* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U_int */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      Test1_TheR__Free (&_val->_u.R);
      break;
    case 1:
      Test1_O2__Free (&_val->_u.O2);
      break;
    default:
      fprintf (stderr, "Test1_U_int__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test1_U_int *CORBA_sequence_Test1_U_int_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U_int *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U_int) * _count;

  if ((_p = (Test1_U_int *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U_int* Test1_U_int__alloc ()
{
  return ((Test1_U_int*) CORBA_sequence_Test1_U_int_allocbuf(1));
}

Test1_U_byte* _Test1_U_byte__Input (ilu_Call _call, Test1_U_byte* _ref, ilu_Error *_err)
{
  Test1_U_byte* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_byte_tk, ILU_C_KERNEL_TYPE(Test1_U_byte), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U_byte*) ilu_MallocE(sizeof (Test1_U_byte), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U_byte));
  };
  switch (tag) {
    case 0:
      (void) _Test1_TheR__Input (_call, &_val->_u.R,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      *&_val->_u.O2 = _ILU_C_InputObject (_call, _Test1_O2__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_byte__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_octet) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_U_byte__Output (ilu_Call _call, Test1_U_byte* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_byte_tk, ILU_C_KERNEL_TYPE(Test1_U_byte), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _Test1_TheR__Output(_call, &_val->_u.R, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _ILU_C_OutputObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U_byte__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U_byte__SizeOf (ilu_Call _call, Test1_U_byte* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_byte_tk, ILU_C_KERNEL_TYPE(Test1_U_byte), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _Test1_TheR__SizeOf (_call, &_val->_u.R, _err);
      break;
    case 1:
      size += _ILU_C_SizeOfObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err);
      break;
    default:
      fprintf (stderr, "_Test1_U_byte__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U_byte__Free (Test1_U_byte* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U_byte */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      Test1_TheR__Free (&_val->_u.R);
      break;
    case 1:
      Test1_O2__Free (&_val->_u.O2);
      break;
    default:
      fprintf (stderr, "Test1_U_byte__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test1_U_byte *CORBA_sequence_Test1_U_byte_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U_byte *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U_byte) * _count;

  if ((_p = (Test1_U_byte *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U_byte* Test1_U_byte__alloc ()
{
  return ((Test1_U_byte*) CORBA_sequence_Test1_U_byte_allocbuf(1));
}

Test1_U4* _Test1_U4__Input (ilu_Call _call, Test1_U4* _ref, ilu_Error *_err)
{
  Test1_U4* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U4), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U4*) ilu_MallocE(sizeof (Test1_U4), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U4));
  };
  switch (tag) {
    case 3:
    case 7:
      ILU_C_InputBoolean (_call, &_val->_u.x1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      *&_val->_u.x2 = _ILU_C_InputObject (_call, _Test1_O2__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
    case 0:
      (void) _Test1_CSS__Input (_call, &_val->_u.x3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
  }
  _val->_d = (CORBA_short) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_U4__Output (ilu_Call _call, Test1_U4* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U4), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 3:
    case 7:
      ILU_C_OutputBoolean(_call, _val->_u.x1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      _ILU_C_OutputObject(_call, (Test1_O2) _val->_u.x2, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
    case 0:
      _Test1_CSS__Output(_call, &_val->_u.x3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U4__SizeOf (ilu_Call _call, Test1_U4* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U4), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 3:
    case 7:
      size += ILU_C_SizeOfBoolean(_call, _val->_u.x1, _err);
      break;
    default:
      size += _ILU_C_SizeOfObject(_call, (Test1_O2) _val->_u.x2, _Test1_O2__ILUType, ilu_FALSE, _err);
      break;
    case 1:
    case 0:
      size += _Test1_CSS__SizeOf (_call, &_val->_u.x3, _err);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U4__Free (Test1_U4* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U4 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 3:
    case 7:
      break;
    default:
      Test1_O2__Free (&_val->_u.x2);
      break;
    case 1:
    case 0:
      Test1_CSS__Free (&_val->_u.x3);
      break;
  };
}

Test1_U4 *CORBA_sequence_Test1_U4_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U4 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U4) * _count;

  if ((_p = (Test1_U4 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U4* Test1_U4__alloc ()
{
  return ((Test1_U4*) CORBA_sequence_Test1_U4_allocbuf(1));
}

Test1_U3* _Test1_U3__Input (ilu_Call _call, Test1_U3* _ref, ilu_Error *_err)
{
  Test1_U3* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test1_U3), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U3*) ilu_MallocE(sizeof (Test1_U3), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U3));
  };
  switch (tag) {
    case Test1_ev1:
      (void) _ilu_CString__Input (_call, &_val->_u.CString, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev3:
      (void) _Test1_U2__Input (_call, &_val->_u.U2,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev7:
      *&_val->_u.v3 = _ILU_C_InputObject (_call, _Test1_O2__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      (void) _Test1_RO__Input (_call, &_val->_u.v4,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _Test1_U3__Output (ilu_Call _call, Test1_U3* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test1_U3), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case Test1_ev1:
      _ilu_CString__Output (_call, _val->_u.CString, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev3:
      _Test1_U2__Output(_call, &_val->_u.U2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case Test1_ev7:
      _ILU_C_OutputObject(_call, (Test1_O2) _val->_u.v3, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      _Test1_RO__Output(_call, _val->_u.v4, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U3__SizeOf (ilu_Call _call, Test1_U3* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(Test1_U3), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case Test1_ev1:
      size += _ilu_CString__SizeOf(_call, _val->_u.CString, _err);
      break;
    case Test1_ev3:
      size += _Test1_U2__SizeOf (_call, &_val->_u.U2, _err);
      break;
    case Test1_ev7:
      size += _ILU_C_SizeOfObject(_call, (Test1_O2) _val->_u.v3, _Test1_O2__ILUType, ilu_FALSE, _err);
      break;
    default:
      size += _Test1_RO__SizeOf (_call, _val->_u.v4, _err);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U3__Free (Test1_U3* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U3 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case Test1_ev1:
      ilu_CString__Free ((ilu_CString *) &_val->_u.CString);
      break;
    case Test1_ev3:
      Test1_U2__Free (&_val->_u.U2);
      break;
    case Test1_ev7:
      Test1_O2__Free (&_val->_u.v3);
      break;
    default:
      Test1_RO__Free (&_val->_u.v4);
      break;
  };
}

Test1_U3 *CORBA_sequence_Test1_U3_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U3 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U3) * _count;

  if ((_p = (Test1_U3 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U3* Test1_U3__alloc ()
{
  return ((Test1_U3*) CORBA_sequence_Test1_U3_allocbuf(1));
}

Test1_U2* _Test1_U2__Input (ilu_Call _call, Test1_U2* _ref, ilu_Error *_err)
{
  Test1_U2* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U2), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U2*) ilu_MallocE(sizeof (Test1_U2), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U2));
  };
  switch (tag) {
    case 3:
    case 7:
      ILU_C_InputBoolean (_call, &_val->_u.x1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
    case 22:
      *&_val->_u.x2 = _ILU_C_InputObject (_call, _Test1_O2__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      (void) _Test1_CSS__Input (_call, &_val->_u.x3,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (CORBA_short) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_U2__Output (ilu_Call _call, Test1_U2* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U2), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 3:
    case 7:
      ILU_C_OutputBoolean(_call, _val->_u.x1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
    case 22:
      _ILU_C_OutputObject(_call, (Test1_O2) _val->_u.x2, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      _Test1_CSS__Output(_call, &_val->_u.x3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U2__SizeOf (ilu_Call _call, Test1_U2* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U2), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 3:
    case 7:
      size += ILU_C_SizeOfBoolean(_call, _val->_u.x1, _err);
      break;
    case 1:
    case 22:
      size += _ILU_C_SizeOfObject(_call, (Test1_O2) _val->_u.x2, _Test1_O2__ILUType, ilu_FALSE, _err);
      break;
    case 2:
      size += _Test1_CSS__SizeOf (_call, &_val->_u.x3, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U2__Free (Test1_U2* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U2 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 3:
    case 7:
      break;
    case 1:
    case 22:
      Test1_O2__Free (&_val->_u.x2);
      break;
    case 2:
      Test1_CSS__Free (&_val->_u.x3);
      break;
    default:
      break;
  };
}

Test1_U2 *CORBA_sequence_Test1_U2_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U2 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U2) * _count;

  if ((_p = (Test1_U2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U2* Test1_U2__alloc ()
{
  return ((Test1_U2*) CORBA_sequence_Test1_U2_allocbuf(1));
}

Test1_TheE *CORBA_sequence_Test1_TheE_allocbuf (CORBA_unsigned_long _count)
{
  Test1_TheE *_p;
  CORBA_unsigned_long _size = sizeof(Test1_TheE) * _count;

  if ((_p = (Test1_TheE *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U1* _Test1_U1__Input (ilu_Call _call, Test1_U1* _ref, ilu_Error *_err)
{
  Test1_U1* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U1), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_U1*) ilu_MallocE(sizeof (Test1_U1), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_U1));
  };
  switch (tag) {
    case 0:
      (void) _Test1_TheR__Input (_call, &_val->_u.R,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      (void) _Test1_TheA1__Input (_call, _val->_u.A1,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U1__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_short) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_U1__Output (ilu_Call _call, Test1_U1* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U1), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _Test1_TheR__Output(_call, &_val->_u.R, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _Test1_TheA1__Output(_call, _val->_u.A1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_U1__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_U1__SizeOf (ilu_Call _call, Test1_U1* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_U1), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _Test1_TheR__SizeOf (_call, &_val->_u.R, _err);
      break;
    case 1:
      size += _Test1_TheA1__SizeOf (_call, _val->_u.A1, _err);
      break;
    default:
      fprintf (stderr, "_Test1_U1__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_U1__Free (Test1_U1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_U1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      Test1_TheR__Free (&_val->_u.R);
      break;
    case 1:
      Test1_TheA1__Free (&_val->_u.A1);
      break;
    default:
      fprintf (stderr, "Test1_U1__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test1_U1 *CORBA_sequence_Test1_U1_allocbuf (CORBA_unsigned_long _count)
{
  Test1_U1 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_U1) * _count;

  if ((_p = (Test1_U1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_U1* Test1_U1__alloc ()
{
  return ((Test1_U1*) CORBA_sequence_Test1_U1_allocbuf(1));
}

Test1_TheU* _Test1_TheU__Input (ilu_Call _call, Test1_TheU* _ref, ilu_Error *_err)
{
  Test1_TheU* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_TheU), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_TheU*) ilu_MallocE(sizeof (Test1_TheU), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_TheU));
  };
  switch (tag) {
    case 0:
      (void) _Test1_TheR__Input (_call, &_val->_u.R,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      (void) _Test1_RO__Input (_call, &_val->_u.RO,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      (void) _Test1_CSS__Input (_call, &_val->_u.CSS,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 3:
      *&_val->_u.O1 = _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 4:
      (void) _Test1_TheOO__Input (_call, &_val->_u.OO,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 5:
      ILU_C_InputBoolean (_call, &_val->_u.boolean, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_TheU__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
      break;
  }
  _val->_d = (CORBA_short) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_TheU__Output (ilu_Call _call, Test1_TheU* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_TheU), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      _Test1_TheR__Output(_call, &_val->_u.R, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      _Test1_RO__Output(_call, _val->_u.RO, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 2:
      _Test1_CSS__Output(_call, &_val->_u.CSS, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 3:
      _ILU_C_OutputObject(_call, (Test1_TheO1) _val->_u.O1, _Test1_TheO1__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 4:
      _Test1_TheOO__Output(_call, _val->_u.OO, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 5:
      ILU_C_OutputBoolean(_call, _val->_u.boolean, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_Test1_TheU__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_TheU__SizeOf (ilu_Call _call, Test1_TheU* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(Test1_TheU), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += _Test1_TheR__SizeOf (_call, &_val->_u.R, _err);
      break;
    case 1:
      size += _Test1_RO__SizeOf (_call, _val->_u.RO, _err);
      break;
    case 2:
      size += _Test1_CSS__SizeOf (_call, &_val->_u.CSS, _err);
      break;
    case 3:
      size += _ILU_C_SizeOfObject(_call, (Test1_TheO1) _val->_u.O1, _Test1_TheO1__ILUType, ilu_FALSE, _err);
      break;
    case 4:
      size += _Test1_TheOO__SizeOf (_call, _val->_u.OO, _err);
      break;
    case 5:
      size += ILU_C_SizeOfBoolean(_call, _val->_u.boolean, _err);
      break;
    default:
      fprintf (stderr, "_Test1_TheU__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_TheU__Free (Test1_TheU* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_TheU */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case 0:
      Test1_TheR__Free (&_val->_u.R);
      break;
    case 1:
      Test1_RO__Free (&_val->_u.RO);
      break;
    case 2:
      Test1_CSS__Free (&_val->_u.CSS);
      break;
    case 3:
      Test1_TheO1__Free (&_val->_u.O1);
      break;
    case 4:
      Test1_TheOO__Free (&_val->_u.OO);
      break;
    case 5:
      break;
    default:
      fprintf (stderr, "Test1_TheU__Free:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
}

Test1_TheU *CORBA_sequence_Test1_TheU_allocbuf (CORBA_unsigned_long _count)
{
  Test1_TheU *_p;
  CORBA_unsigned_long _size = sizeof(Test1_TheU) * _count;

  if ((_p = (Test1_TheU *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_TheU* Test1_TheU__alloc ()
{
  return ((Test1_TheU*) CORBA_sequence_Test1_TheU_allocbuf(1));
}

Test1_OO2* _Test1_OO2__Input (ilu_Call _call, Test1_OO2* _ref, ilu_Error *_err)
{
  Test1_OO2* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_boolean_tk, ILU_C_KERNEL_TYPE(Test1_OO2), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_OO2*) ilu_MallocE(sizeof (Test1_OO2), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_OO2));
  };
  switch (tag) {
    case ilu_TRUE:
      *&_val->_u.O2 = _ILU_C_InputObject (_call, _Test1_O2__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  }
  _val->_d = (CORBA_boolean) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_OO2__Output (ilu_Call _call, Test1_OO2* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_boolean_tk, ILU_C_KERNEL_TYPE(Test1_OO2), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case ilu_TRUE:
      _ILU_C_OutputObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_OO2__SizeOf (ilu_Call _call, Test1_OO2* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_boolean_tk, ILU_C_KERNEL_TYPE(Test1_OO2), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case ilu_TRUE:
      size += _ILU_C_SizeOfObject(_call, (Test1_O2) _val->_u.O2, _Test1_O2__ILUType, ilu_FALSE, _err);
      break;
    default:
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_OO2__Free (Test1_OO2* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_OO2 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case ilu_TRUE:
      Test1_O2__Free (&_val->_u.O2);
      break;
    default:
      break;
  };
}

Test1_OO2 *CORBA_sequence_Test1_OO2_allocbuf (CORBA_unsigned_long _count)
{
  Test1_OO2 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_OO2) * _count;

  if ((_p = (Test1_OO2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_OO2* Test1_OO2__alloc ()
{
  return ((Test1_OO2*) CORBA_sequence_Test1_OO2_allocbuf(1));
}

void Test1_O2__Free (Test1_O2* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_O2 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

Test1_O2 *CORBA_sequence_Test1_O2_allocbuf (CORBA_unsigned_long _count)
{
  Test1_O2 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_O2) * _count;

  if ((_p = (Test1_O2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_TheOO* _Test1_TheOO__Input (ilu_Call _call, Test1_TheOO* _ref, ilu_Error *_err)
{
  Test1_TheOO* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(Test1_TheOO), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_TheOO *) ilu_MallocE (sizeof (Test1_TheOO), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(Test1_TheOO));
  };
  if (_present)
    {
      *_val = _ILU_C_InputObject (_call, _Test1_TheO1__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  else *_val = ILU_NIL;
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_TheOO__Output (ilu_Call _call, Test1_TheOO _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(Test1_TheOO), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _ILU_C_OutputObject(_call, (Test1_TheO1) _val, _Test1_TheO1__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _Test1_TheOO__SizeOf (ilu_Call _call, Test1_TheOO _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(Test1_TheOO), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _ILU_C_SizeOfObject(_call, (Test1_TheO1) _val, _Test1_TheO1__ILUType, ilu_FALSE, _err);
  return size;
}

void Test1_TheOO__Free (Test1_TheOO* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_TheOO */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is Test1_TheO1 */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    Test1_TheO1__Free (&*_val);
  }
}

Test1_TheOO *CORBA_sequence_Test1_TheOO_allocbuf (CORBA_unsigned_long _count)
{
  Test1_TheOO *_p;
  CORBA_unsigned_long _size = sizeof(Test1_TheOO) * _count;

  if ((_p = (Test1_TheOO *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_TheOO* Test1_TheOO__alloc ()
{
  return ((Test1_TheOO*) CORBA_sequence_Test1_TheOO_allocbuf(1));
}

Test1_RO* _Test1_RO__Input (ilu_Call _call, Test1_RO* _ref, ilu_Error *_err)
{
  Test1_RO* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(Test1_RO), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (Test1_RO *) ilu_MallocE (sizeof (Test1_RO), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(Test1_RO));
  };
  if (_present)
    {
    *_val = (Test1_TheR*) ilu_MallocE (sizeof (Test1_TheR), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(Test1_TheR));
      (void) _Test1_TheR__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  else *_val = ILU_NIL;
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_RO__Output (ilu_Call _call, Test1_RO _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(Test1_RO), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _Test1_TheR__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _Test1_RO__SizeOf (ilu_Call _call, Test1_RO _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(Test1_RO), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _Test1_TheR__SizeOf (_call, &*_val, _err);
  return size;
}

void Test1_RO__Free (Test1_RO* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_RO */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is Test1_TheR */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    Test1_TheR__Free (&**_val);
    ilu_free(*_val);
  }
}

Test1_RO *CORBA_sequence_Test1_RO_allocbuf (CORBA_unsigned_long _count)
{
  Test1_RO *_p;
  CORBA_unsigned_long _size = sizeof(Test1_RO) * _count;

  if ((_p = (Test1_RO *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_RO* Test1_RO__alloc ()
{
  return ((Test1_RO*) CORBA_sequence_Test1_RO_allocbuf(1));
}

Test1_TheRS* _Test1_TheRS__Input (ilu_Call _call, Test1_TheRS* _ref, ilu_Error *_err)
{
  Test1_TheRS* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Test1_TheR _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Test1_TheRS*) ilu_MallocE(sizeof (Test1_TheRS), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Test1_TheRS_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Test1_TheRS), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Test1_TheR), _count, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Test1_TheR), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Test1_TheR__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Test1_TheRS_Append (_val, &_tmp, _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  ilu_EndSequence (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_TheRS__Output (ilu_Call _call, Test1_TheRS* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Test1_TheRS), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Test1_TheR), _val->_length, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Test1_TheR), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Test1_TheR *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Test1_TheR__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Test1_TheRS__SizeOf (ilu_Call _call, Test1_TheRS* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Test1_TheRS), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Test1_TheR), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Test1_R), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Test1_R *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Test1_TheR__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_TheRS__Free (Test1_TheRS* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_TheRS */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Test1_TheR)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Test1_TheR)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Test1_TheR))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          Test1_TheR__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK Test1_TheRS__Free (Test1_TheRS* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Test1_TheRS *CORBA_sequence_Test1_TheRS_allocbuf (CORBA_unsigned_long _count)
{
  Test1_TheRS *_p;
  CORBA_unsigned_long _size = sizeof(Test1_TheRS) * _count;

  if ((_p = (Test1_TheRS *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_TheRS* Test1_TheRS__alloc ()
{
  return ((Test1_TheRS*) CORBA_sequence_Test1_TheRS_allocbuf(1));
}

Test1_TheR* _Test1_TheR__Input (ilu_Call _call, Test1_TheR* _ref, ilu_Error *_err)
{
  Test1_TheR* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Test1_TheR__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Test1_TheR__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (Test1_TheR*) ilu_MallocE (sizeof (Test1_TheR), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(Test1_TheR));
    } else {
      _val = (Test1_TheR*) _ILU_C_CRCreate (s, sizeof(Test1_TheR), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(Test1_TheR), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Test1_TheA1__Input (_call, _val->a,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _Test1_CSS__Input (_call, &_val->css,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputInteger (_call, &_val->i, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (s != ILU_NIL) _ILU_C_CRPostInput (s, _val, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_TheR__Output (ilu_Call _call, Test1_TheR* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_Test1_TheR__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_Test1_TheR__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(Test1_TheR), _err);
    if (ILU_ERRNOK(*_err)) return;
  _Test1_TheA1__Output(_call, (_val->a), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _Test1_CSS__Output(_call, (&_val->css), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputInteger (_call, (_val->i), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _Test1_TheR__SizeOf (ilu_Call _call, Test1_TheR* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_Test1_TheR__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Test1_TheR__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(Test1_TheR), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Test1_TheA1__SizeOf (_call, _val->a, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _Test1_CSS__SizeOf (_call, &_val->css, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfInteger(_call, _val->i, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_TheR__Free (Test1_TheR* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_TheR */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_Test1_TheR__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_Test1_TheR__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  Test1_TheA1__Free (&_val->a);
  Test1_CSS__Free (&_val->css);
}

Test1_TheR *CORBA_sequence_Test1_TheR_allocbuf (CORBA_unsigned_long _count)
{
  Test1_TheR *_p;
  CORBA_unsigned_long _size = sizeof(Test1_TheR) * _count;

  if ((_p = (Test1_TheR *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_TheR* Test1_TheR__alloc ()
{
  return ((Test1_TheR*) CORBA_sequence_Test1_TheR_allocbuf(1));
}

Test1_BS* _Test1_BS__Input (ilu_Call _call, Test1_BS* _ref, ilu_Error *_err)
{
  Test1_BS* _val = _ref;

  ilu_cardinal len=0;
  ilu_cardinal limit = 0;
  ilu_bytes b = ILU_NIL;

  if (_ref == ILU_NIL) {
    _val = (Test1_BS *) ilu_MallocE(sizeof(Test1_BS), _err);
    if (_val == ILU_NIL)  goto marshalError;
  } else {
    if ((_ref->_buffer != ILU_NIL) && (_ref->_maximum > 0)) {
      limit = ((0 != 0) && (_ref->_maximum > 0)) ? 0 : _ref->_maximum;
      b = _ref->_buffer;
    };
  };
  ilu_InputBytes (_call, &b, &len, limit, _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  _val->_length = len;
  if ((_ref == ILU_NIL) || (b != _ref->_buffer)) {
    _val->_maximum = len;
    _val->_buffer = b;
  };
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_BS__Output (ilu_Call _call, Test1_BS* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputBytes (_call, _val->_buffer, _val->_length, 0, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_BS__SizeOf (ilu_Call _call, Test1_BS* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfBytes (_call, _val->_buffer, _val->_length, 0, _err);
  return size;
}

void Test1_BS__Free (Test1_BS* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_BS */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_octet)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_octet)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_octet))) */ ) {
    //ilu_DebugPrintf("OK Test1_BS__Free (Test1_BS* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Test1_BS *CORBA_sequence_Test1_BS_allocbuf (CORBA_unsigned_long _count)
{
  Test1_BS *_p;
  CORBA_unsigned_long _size = sizeof(Test1_BS) * _count;

  if ((_p = (Test1_BS *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_BS* Test1_BS__alloc ()
{
  return ((Test1_BS*) CORBA_sequence_Test1_BS_allocbuf(1));
}

Test1_A2_slice * _Test1_A2__Input (ilu_Call _call, Test1_A2 _ref, ilu_Error *_err)
{
  Test1_A2_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (Test1_A2_slice *) ilu_MallocE(sizeof(Test1_A2), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_InputArray (_call, ILU_C_KERNEL_TYPE(Test1_A2), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CORBA_unsigned_long), 12, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val, sizeof(Test1_A2), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 3;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 4;  _i1 += 1)
      ilu_InputCardinal (_call, &_val[_i0][_i1], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      }
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_A2__Output (ilu_Call _call, Test1_A2 _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_bytes* nec;
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputArray (_call, 12, ILU_C_KERNEL_TYPE(Test1_A2), _err); if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_unsigned_long), 12, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val, sizeof(Test1_A2), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 3;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 4;  _i1 += 1)
          ilu_OutputCardinal (_call, _val[_i0][_i1], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      }
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_A2__SizeOf (ilu_Call _call, Test1_A2 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfArray (_call, 12, ILU_C_KERNEL_TYPE(Test1_A2), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_unsigned_long), 12, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque(_call, (ilu_bytes)_val, sizeof(Test1_A2), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 3;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 4;  _i1 += 1)
          size += ilu_SizeOfCardinal(_call, _val[_i0][_i1], _err);
      }
    }
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Test1_A2 *CORBA_sequence_Test1_A2_allocbuf (CORBA_unsigned_long _count)
{
  Test1_A2 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_A2) * _count;

  if ((_p = (Test1_A2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_A2_slice * Test1_A2__alloc ()
{
  return ((Test1_A2_slice *) CORBA_sequence_Test1_A2_allocbuf(1));
}

Test1_TheA1_slice * _Test1_TheA1__Input (ilu_Call _call, Test1_TheA1 _ref, ilu_Error *_err)
{
  Test1_TheA1_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (Test1_TheA1_slice *) ilu_MallocE(sizeof(Test1_TheA1), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_InputArray (_call, ILU_C_KERNEL_TYPE(Test1_TheA1), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Test1_ScS), 3, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val, sizeof(Test1_TheA1), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 3;  _i0 += 1)
    (void) _Test1_ScS__Input (_call, &_val[_i0],  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_TheA1__Output (ilu_Call _call, Test1_TheA1 _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_bytes* nec;
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputArray (_call, 3, ILU_C_KERNEL_TYPE(Test1_TheA1), _err); if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Test1_ScS), 3, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val, sizeof(Test1_TheA1), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 3;  _i0 += 1)
        _Test1_ScS__Output(_call, _val[_i0], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_TheA1__SizeOf (ilu_Call _call, Test1_TheA1 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfArray (_call, 3, ILU_C_KERNEL_TYPE(Test1_TheA1), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Test1_ScS), 3, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque(_call, (ilu_bytes)_val, sizeof(Test1_TheA1), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 3;  _i0 += 1)
        size += _Test1_ScS__SizeOf (_call, _val[_i0], _err);
    }
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_TheA1__Free (Test1_TheA1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_TheA1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 3;  _i0 += 1)
      Test1_ScS__Free (&(*_val)[_i0]);
    }
}

Test1_TheA1 *CORBA_sequence_Test1_TheA1_allocbuf (CORBA_unsigned_long _count)
{
  Test1_TheA1 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_TheA1) * _count;

  if ((_p = (Test1_TheA1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_TheA1_slice * Test1_TheA1__alloc ()
{
  return ((Test1_TheA1_slice *) CORBA_sequence_Test1_TheA1_allocbuf(1));
}

Test1_A0_slice * _Test1_A0__Input (ilu_Call _call, Test1_A0 _ref, ilu_Error *_err)
{
  Test1_A0_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (Test1_A0_slice *) ilu_MallocE(sizeof(Test1_A0), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
    ilu_opaque _tmp = _val;
    ilu_InputOpaque (_call, &_tmp, 8, _err);
  }
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_A0__Output (ilu_Call _call, Test1_A0 _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputOpaque (_call, (_val), 8, _err);
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_A0__SizeOf (ilu_Call _call, Test1_A0 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size += ilu_SizeOfOpaque (_call, (_val), 8, _err);
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

Test1_A0 *CORBA_sequence_Test1_A0_allocbuf (CORBA_unsigned_long _count)
{
  Test1_A0 *_p;
  CORBA_unsigned_long _size = sizeof(Test1_A0) * _count;

  if ((_p = (Test1_A0 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_A0_slice * Test1_A0__alloc ()
{
  return ((Test1_A0_slice *) CORBA_sequence_Test1_A0_allocbuf(1));
}

Test1_CSS* _Test1_CSS__Input (ilu_Call _call, Test1_CSS* _ref, ilu_Error *_err)
{
  Test1_CSS* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  Test1_ScS _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Test1_CSS*) ilu_MallocE(sizeof (Test1_CSS), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Test1_CSS_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Test1_CSS), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(Test1_ScS), _count, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(Test1_ScS), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _Test1_ScS__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Test1_CSS_Append (_val, _tmp, _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  ilu_EndSequence (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_CSS__Output (ilu_Call _call, Test1_CSS* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Test1_CSS), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Test1_ScS), _val->_length, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(Test1_ScS), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    Test1_ScS *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _Test1_ScS__Output(_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Test1_CSS__SizeOf (ilu_Call _call, Test1_CSS* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Test1_CSS), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(Test1_ScS), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(Test1_ScS), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    Test1_ScS *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _Test1_ScS__SizeOf (_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_CSS__Free (Test1_CSS* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_CSS */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(Test1_ScS)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(Test1_ScS)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(Test1_ScS))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          Test1_ScS__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK Test1_CSS__Free (Test1_CSS* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Test1_CSS *CORBA_sequence_Test1_CSS_allocbuf (CORBA_unsigned_long _count)
{
  Test1_CSS *_p;
  CORBA_unsigned_long _size = sizeof(Test1_CSS) * _count;

  if ((_p = (Test1_CSS *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_CSS* Test1_CSS__alloc ()
{
  return ((Test1_CSS*) CORBA_sequence_Test1_CSS_allocbuf(1));
}

Test1_ScS* _Test1_ScS__Input (ilu_Call _call, Test1_ScS* _ref, ilu_Error *_err)
{
  Test1_ScS* _val = _ref;

  ilu_cardinal len = 0;
  ilu_cardinal actual_encoding;
  if (_ref == ILU_NIL) {
      _val = ilu_MallocE(sizeof(*_val), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      *_val = ILU_NIL;}
  ilu_InputEString (_call, (ilu_byte **) _val, &len, 0, ILU_StringEncoding_latin1, &actual_encoding, _err);
  if (ILU_ERROK(*_err) && (actual_encoding != ILU_StringEncoding_latin1))
  	  ILU_ERR_CONS1(imp_limit, _err, minor, ilu_ilm_unsupported_charset_encoding, 0);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_ScS__Output (ilu_Call _call, Test1_ScS _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
 marshalError:
  return;
}

ilu_cardinal _Test1_ScS__SizeOf (ilu_Call _call, Test1_ScS _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
  return size;
}

void Test1_ScS__Free (Test1_ScS* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_ScS */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  if (*_val != ILU_NIL)
    ilu_free(*_val);
}

Test1_ScS *CORBA_sequence_Test1_ScS_allocbuf (CORBA_unsigned_long _count)
{
  Test1_ScS *_p;
  CORBA_unsigned_long _size = sizeof(Test1_ScS) * _count;

  if ((_p = (Test1_ScS *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_ScS* Test1_ScS__alloc ()
{
  return ((Test1_ScS*) CORBA_sequence_Test1_ScS_allocbuf(1));
}

Test1_IS* _Test1_IS__Input (ilu_Call _call, Test1_IS* _ref, ilu_Error *_err)
{
  Test1_IS* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  CORBA_long _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (Test1_IS*) ilu_MallocE(sizeof (Test1_IS), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  Test1_IS_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(Test1_IS), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CORBA_long), _count, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)malloc(size);
        ilu_InputOpaque(_call, &nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(CORBA_long), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      ilu_InputInteger (_call, &_tmp, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      Test1_IS_Append (_val, _tmp, _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    }
  ilu_EndSequence (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _Test1_IS__Output (ilu_Call _call, Test1_IS* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Test1_IS), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_long), _val->_length, &aligncode, &alignproc, _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    if (blockmove) {
      if (alignproc != ((_ILU_C_AlignmentProc)0)) {
        size = (*alignproc) (_call, aligncode, _err);
        if (ILU_ERRNOK(*_err)) goto marshalError;
        nec = (ilu_byte*)calloc(size, 1);
        ilu_OutputOpaque(_call, nec, size, _err);
        free(nec);
        if (ILU_ERRNOK(*_err)) goto marshalError;
      };
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(CORBA_long), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    CORBA_long *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        ilu_OutputInteger (_call, *p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _Test1_IS__SizeOf (ilu_Call _call, Test1_IS* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(Test1_IS), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CORBA_long), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(CORBA_long), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    CORBA_long *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += ilu_SizeOfInteger(_call, *p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void Test1_IS__Free (Test1_IS* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a Test1_IS */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CORBA_long)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CORBA_long)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CORBA_long))) */ ) {
    //ilu_DebugPrintf("OK Test1_IS__Free (Test1_IS* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

Test1_IS *CORBA_sequence_Test1_IS_allocbuf (CORBA_unsigned_long _count)
{
  Test1_IS *_p;
  CORBA_unsigned_long _size = sizeof(Test1_IS) * _count;

  if ((_p = (Test1_IS *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

Test1_IS* Test1_IS__alloc ()
{
  return ((Test1_IS*) CORBA_sequence_Test1_IS_allocbuf(1));
}

void Test1_TheRS_Every (Test1_TheRS *h, void (*f)(Test1_R*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Test1_R), (void *) data);
}

void Test1_TheRS_Append (Test1_TheRS *h, Test1_R* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Test1_R), err);
}

void Test1_TheRS_Push (Test1_TheRS *h, Test1_R* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Test1_R));
}

void Test1_TheRS_Pop (Test1_TheRS *h, Test1_R* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Test1_R));
}

CORBA_unsigned_long Test1_TheRS_Length (Test1_TheRS *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Test1_R * Test1_TheRS_Nth (Test1_TheRS *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Test1_TheRS * Test1_TheRS_Create (CORBA_unsigned_long sz, Test1_R* p)
{
  Test1_TheRS *s;
  s = (Test1_TheRS *) ilu_malloc(sizeof(Test1_TheRS));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Test1_TheRS)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Test1_R *) ilu_malloc(sz * sizeof(Test1_R))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Test1_R));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Test1_TheRS_Init (Test1_TheRS *s, CORBA_unsigned_long sz, Test1_R* p)
{
  if (sz == 0 && p != ILU_NIL)
    return;
  if (sz > 0)
    s->_maximum = sz;
  else
    s->_maximum = 0;
  if (sz > 0 && p != ILU_NIL)
    s->_length = sz;
  else
    s->_length = 0;
  if (sz > 0 && p == ILU_NIL) {
    s->_buffer = (Test1_R *) ilu_malloc (sz * sizeof (Test1_R));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Test1_R)); }}
  else
    s->_buffer = p;
  return;
}

void Test1_BS_Every (Test1_BS *h, void (*f)(CORBA_octet *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_octet), (void *) data);
}

void Test1_BS_Append (Test1_BS *h, CORBA_octet item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet), err);
}

void Test1_BS_Push (Test1_BS *h, CORBA_octet item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_octet));
}

void Test1_BS_Pop (Test1_BS *h, CORBA_octet *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_octet));
}

CORBA_unsigned_long Test1_BS_Length (Test1_BS *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_octet * Test1_BS_Nth (Test1_BS *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Test1_BS * Test1_BS_Create (CORBA_unsigned_long sz, CORBA_octet *p)
{
  Test1_BS *s;
  s = (Test1_BS *) ilu_malloc(sizeof(Test1_BS));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Test1_BS)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_octet *) ilu_malloc(sz * sizeof(CORBA_octet))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_octet));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Test1_BS_Init (Test1_BS *s, CORBA_unsigned_long sz, CORBA_octet *p)
{
  if (sz == 0 && p != ILU_NIL)
    return;
  if (sz > 0)
    s->_maximum = sz;
  else
    s->_maximum = 0;
  if (sz > 0 && p != ILU_NIL)
    s->_length = sz;
  else
    s->_length = 0;
  if (sz > 0 && p == ILU_NIL) {
    s->_buffer = (CORBA_octet *) ilu_malloc (sz * sizeof (CORBA_octet));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CORBA_octet)); }}
  else
    s->_buffer = p;
  return;
}

void Test1_CSS_Every (Test1_CSS *h, void (*f)(Test1_ScS *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(Test1_ScS), (void *) data);
}

void Test1_CSS_Append (Test1_CSS *h, Test1_ScS item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Test1_ScS), err);
}

void Test1_CSS_Push (Test1_CSS *h, Test1_ScS item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(Test1_ScS));
}

void Test1_CSS_Pop (Test1_CSS *h, Test1_ScS *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(Test1_ScS));
}

CORBA_unsigned_long Test1_CSS_Length (Test1_CSS *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

Test1_ScS * Test1_CSS_Nth (Test1_CSS *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Test1_CSS * Test1_CSS_Create (CORBA_unsigned_long sz, Test1_ScS *p)
{
  Test1_CSS *s;
  s = (Test1_CSS *) ilu_malloc(sizeof(Test1_CSS));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Test1_CSS)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((Test1_ScS *) ilu_malloc(sz * sizeof(Test1_ScS))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(Test1_ScS));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Test1_CSS_Init (Test1_CSS *s, CORBA_unsigned_long sz, Test1_ScS *p)
{
  if (sz == 0 && p != ILU_NIL)
    return;
  if (sz > 0)
    s->_maximum = sz;
  else
    s->_maximum = 0;
  if (sz > 0 && p != ILU_NIL)
    s->_length = sz;
  else
    s->_length = 0;
  if (sz > 0 && p == ILU_NIL) {
    s->_buffer = (Test1_ScS *) ilu_malloc (sz * sizeof (Test1_ScS));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(Test1_ScS)); }}
  else
    s->_buffer = p;
  return;
}

void Test1_ScS_Every (Test1_ScS *h, void (*f)(Test1_SC *, void *), void * data)
{
  Test1_SC *p;
  for (p = *h;  *p != 0;  p++) (*f)(p, data);
}

void Test1_ScS_Append (Test1_ScS *h, Test1_SC item, ilu_Error* err)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 1);
}

void Test1_ScS_Push (Test1_ScS *h, Test1_SC item)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 0);
}

void Test1_ScS_Pop (Test1_ScS *h, Test1_SC *item)
{
  _ILU_C_PopString (h, item);
}

CORBA_unsigned_long Test1_ScS_Length (Test1_ScS *h)
{
  if (h == ILU_NIL || *h == ILU_NIL) return 0;
  return (strlen((char *)(*h)));
}

Test1_SC * Test1_ScS_Nth (Test1_ScS *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || *h == ILU_NIL) return ILU_NIL;
  if (n >= strlen((char*)(*h)))
    return ILU_NIL;
else return &((*h)[n]);
}

Test1_ScS Test1_ScS_Create (CORBA_unsigned_long sz, Test1_SC *p)
{
  Test1_ScS s;

  if (p == ILU_NIL)
    {
      s = ilu_malloc(sz * sizeof(Test1_SC));
      if (s == ILU_NIL) {        _ILU_C_MallocFailure(sz * sizeof(Test1_SC));        return ILU_NIL; }
      memset((void *) s, 0, sz * sizeof(Test1_SC));
      return s;
    }
  else
    return p;
}

void Test1_ScS_Init (Test1_ScS *s, CORBA_unsigned_long sz)
{
  return;
}

void Test1_IS_Every (Test1_IS *h, void (*f)(CORBA_long *, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CORBA_long), (void *) data);
}

void Test1_IS_Append (Test1_IS *h, CORBA_long item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_long), err);
}

void Test1_IS_Push (Test1_IS *h, CORBA_long item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) &item, sizeof(CORBA_long));
}

void Test1_IS_Pop (Test1_IS *h, CORBA_long *item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CORBA_long));
}

CORBA_unsigned_long Test1_IS_Length (Test1_IS *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CORBA_long * Test1_IS_Nth (Test1_IS *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

Test1_IS * Test1_IS_Create (CORBA_unsigned_long sz, CORBA_long *p)
{
  Test1_IS *s;
  s = (Test1_IS *) ilu_malloc(sizeof(Test1_IS));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(Test1_IS)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CORBA_long *) ilu_malloc(sz * sizeof(CORBA_long))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CORBA_long));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void Test1_IS_Init (Test1_IS *s, CORBA_unsigned_long sz, CORBA_long *p)
{
  if (sz == 0 && p != ILU_NIL)
    return;
  if (sz > 0)
    s->_maximum = sz;
  else
    s->_maximum = 0;
  if (sz > 0 && p != ILU_NIL)
    s->_length = sz;
  else
    s->_length = 0;
  if (sz > 0 && p == ILU_NIL) {
    s->_buffer = (CORBA_long *) ilu_malloc (sz * sizeof (CORBA_long));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CORBA_long)); }}
  else
    s->_buffer = p;
  return;
}

void _Test1__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("Test1", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _Test1__Exception_E1 = ilu_DefineException("Test1", "E1", "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E2 = ilu_DefineException("Test1", "E2", "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_CantCreate = ilu_DefineException("Test1", "CantCreate", ILU_NIL, &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E3 = ilu_DefineException("Test1", "E3", "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E4 = ilu_DefineException("Test1", "E4", "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E5 = ilu_DefineException("Test1", "E5", "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E6 = ilu_DefineException("Test1", "E6", "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E7 = ilu_DefineException("Test1", "E7", "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E8 = ilu_DefineException("Test1", "E8", "ilut:h3Dnvis94UwnmFURfYsCp700jVy", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _Test1__Exception_E9 = ilu_DefineException("Test1", "E9", "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",
	NULL};
    cl = ilu_DefineObjectType("Test1.O4",	/*name*/
	NULL,	/*no brand*/
	"ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	1,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Test1_O4__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"R-to-R",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "r", ilu_FALSE, ilu_In, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",
	NULL};
    cl = ilu_DefineObjectType("Test1.P",	/*name*/
	NULL,	/*no brand*/
	"ilut:dY9O+Pbe716S3dZTXTUzbvfKs87",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	1,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Test1_P__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"m2",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "j", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("Test1.O3",	/*name*/
	"v1",	/*brand*/
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_TRUE,	/* collectible */
	NULL,	/*doc string*/
	3,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Test1_O3__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"RS-R-to-R-IS",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "r", ilu_FALSE, ilu_In, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "r2", ilu_FALSE, ilu_Out, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Test1_E2;
    m = ilu_DefineMethod(cl, 1,
	"O1-U-to-U",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "o", ilu_TRUE, ilu_In, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "u", ilu_FALSE, ilu_InOut, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"BS-to-I",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "b", ilu_FALSE, ilu_In, "ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("Test1.TheO1",	/*name*/
	NULL,	/*no brand*/
	"ilut:fmBFu4mQpwjov+CekDxhjwxkgty",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	"sample\012multi-line doc string",	/*doc string*/
	6,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Test1_TheO1__ILUType = cl;
  }
  { ilu_Exception	exns[2];
    exns[0] = ex_Test1_E1;
    exns[1] = ex_Test1_E2;
    m = ilu_DefineMethod(cl, 0,
	"U-CSS-to-U",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	2,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "u", ilu_FALSE, ilu_In, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "css", ilu_FALSE, ilu_In, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Test1_E1;
    m = ilu_DefineMethod(cl, 1,
	"f-CSS-to-RO",	/*name*/
	2,	/*id*/
	1,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "css", ilu_FALSE, ilu_In, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"R-ScS-to-F",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "r", ilu_FALSE, ilu_In, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "s", ilu_FALSE, ilu_In, "ilut:iqqhSf395+BafbY8Oo2elFQD1bK", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"a-RO",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "ro", ilu_FALSE, ilu_In, "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Test1_CantCreate;
    m = ilu_DefineMethod(cl, 4,
	"get-O2",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"ilut:jXB9BUoPU7650cspZmJCl3y4zzu",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Test1_CantCreate;
    m = ilu_DefineMethod(cl, 5,
	"get-O3",	/*name*/
	6,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "subclass", ilu_FALSE, ilu_In, "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("Test1.O2",	/*name*/
	NULL,	/*no brand*/
	"ilut:jXB9BUoPU7650cspZmJCl3y4zzu",	/*uid*/
	"sunrpc_2_0x3458_3",	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	"sample multi-line\012    doc string with leading whitespace on the second line",	/*doc string*/
	2,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _Test1_O2__ILUType = cl;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_Test1_E2;
    m = ilu_DefineMethod(cl, 0,
	"OO-A0-to-CSS",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "o", ilu_FALSE, ilu_In, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a", ilu_FALSE, ilu_In, "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"R-I-A1-to-I-A0",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "r", ilu_FALSE, ilu_In, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "i", ilu_FALSE, ilu_InOut, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a", ilu_FALSE, ilu_In, "ilut:h3Dnvis94UwnmFURfYsCp700jVy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _Test1_O4__IoFns.kernelType = ilu_RegisterObjectType("O4", "Test1", ILU_NIL, "ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ",
    _Test1_O4__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_P__IoFns.kernelType = ilu_RegisterObjectType("P", "Test1", ILU_NIL, "ilut:dY9O+Pbe716S3dZTXTUzbvfKs87",
    _Test1_P__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_O3__IoFns.kernelType = ilu_RegisterObjectType("O3", "Test1", ILU_NIL, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",
    _Test1_O3__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_TheO1__IoFns.kernelType = ilu_RegisterObjectType("TheO1", "Test1", ILU_NIL, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty",
    _Test1_TheO1__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_U_scard__IoFns.kernelType = type = ilu_RegisterUnionType("U-scard", "Test1", ILU_NIL, "ilut:jAPE1zV6LdNhqmjYERCpES3yBpF",
    "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y",	/* UID of discriminant type */
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
      "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortcardinal_val = 0;
    cv.kind = ilu_shortcardinal_cvk;
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
    cv.value.shortcardinal_val = 1;
    cv.kind = ilu_shortcardinal_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("One", "Test1", ILU_NIL, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty",
    "ilut:fmBFu4mQpwjov+CekDxhjwxkgty",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_U_card__IoFns.kernelType = type = ilu_RegisterUnionType("U-card", "Test1", ILU_NIL, "ilut:nY7eVP682HUe0ogce3ooQPrruH2",
    "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO",	/* UID of discriminant type */
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
      "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.cardinal_val = 0;
    cv.kind = ilu_cardinal_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.cardinal_val = 1;
    cv.kind = ilu_cardinal_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_U_int__IoFns.kernelType = type = ilu_RegisterUnionType("U-int", "Test1", ILU_NIL, "ilut:b8uuARf6GuBoeD-p8pOwYMjTZ69",
    "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY",	/* UID of discriminant type */
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
      "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.integer_val = 0;
    cv.kind = ilu_integer_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.integer_val = 1;
    cv.kind = ilu_integer_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_U_byte__IoFns.kernelType = type = ilu_RegisterUnionType("U-byte", "Test1", ILU_NIL, "ilut:eEo4ZOFawZcut8dv19+C65eQlWg",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/* UID of discriminant type */
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
      "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.byte_val = 0;
    cv.kind = ilu_byte_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.byte_val = 1;
    cv.kind = ilu_byte_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_U4__IoFns.kernelType = type = ilu_RegisterUnionType("U4", "Test1", ILU_NIL, "ilut:iqhShhLIYYhlWJMKqapun2JReYg",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* UID of discriminant type */
    3,	/* number of arms */
    2,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "x1", /* name of arm */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* arm type */
      2, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 3;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 7;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 1, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "x2", /* name of arm */
      "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", /* arm type */
      0, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      "x3", /* name of arm */
      "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", /* arm type */
      2, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 1;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 0;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 1, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_U3__IoFns.kernelType = type = ilu_RegisterUnionType("U3", "Test1", ILU_NIL, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj",
    "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",	/* UID of discriminant type */
    4,	/* number of arms */
    4,	/* default arm (0 for none) */
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
      "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9", /* arm type */
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
      "v3", /* name of arm */
      "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "ev7";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 3, /* which arm */
      "v4", /* name of arm */
      "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", /* arm type */
      0, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_U2__IoFns.kernelType = type = ilu_RegisterUnionType("U2", "Test1", ILU_NIL, "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* UID of discriminant type */
    3,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "x1", /* name of arm */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* arm type */
      2, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 3;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 7;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 1, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "x2", /* name of arm */
      "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", /* arm type */
      2, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 1;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 22;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 1, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      "x3", /* name of arm */
      "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 2;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("E", "Test1", ILU_NIL, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",
    "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_TheE__IoFns.kernelType = type = ilu_RegisterEnumerationType("TheE", "Test1", ILU_NIL, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh",
    4,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "ev1", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "ev3", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "ev5", /* element name */
    4,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "ev7", /* element name */
    5,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_U1__IoFns.kernelType = type = ilu_RegisterUnionType("U1", "Test1", ILU_NIL, "ilut:jzGuxkzcjrh34B-89hMcq2ovHB6",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* UID of discriminant type */
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
      "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 0;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:h3Dnvis94UwnmFURfYsCp700jVy", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 1;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("U", "Test1", ILU_NIL, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW",
    "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_TheU__IoFns.kernelType = type = ilu_RegisterUnionType("TheU", "Test1", ILU_NIL, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW",
    "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/* UID of discriminant type */
    6,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 0;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 1;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 2;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 3, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 3;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 4, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 4;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 5, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.shortinteger_val = 5;
    cv.kind = ilu_shortinteger_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_OO2__IoFns.kernelType = type = ilu_RegisterUnionType("OO2", "Test1", ILU_NIL, "ilut:l-kEjRgqgSEZbJTDUfMwmrp5361",
    "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/* UID of discriminant type */
    1,	/* number of arms */
    0,	/* default arm (0 for none) */
    ilu_TRUE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      ILU_NIL, /* no name for arm */
      "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.boolean_val = ilu_TRUE;
    cv.kind = ilu_boolean_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_O2__IoFns.kernelType = ilu_RegisterObjectType("O2", "Test1", ILU_NIL, "ilut:jXB9BUoPU7650cspZmJCl3y4zzu",
    _Test1_O2__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("OO", "Test1", ILU_NIL, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA",
    "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_TheOO__IoFns.kernelType = ilu_RegisterOptionalType("TheOO", "Test1", ILU_NIL, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA",
    "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("O1", "Test1", ILU_NIL, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty",
    "ilut:fmBFu4mQpwjov+CekDxhjwxkgty",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_RO__IoFns.kernelType = ilu_RegisterOptionalType("RO", "Test1", ILU_NIL, "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2",
    "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("RS", "Test1", ILU_NIL, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac",
    "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_TheRS__IoFns.kernelType = ilu_RegisterSequenceType("TheRS", "Test1", ILU_NIL, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac",
    "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("R", "Test1", ILU_NIL, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7",
    "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_TheR__IoFns.kernelType = type = ilu_RegisterRecordType("TheR", "Test1", ILU_NIL, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7",
    3,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "a", /* field name */
      "ilut:h3Dnvis94UwnmFURfYsCp700jVy", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "css", /* field name */
      "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "i", /* field name */
      "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _Test1_BS__IoFns.kernelType = ilu_RegisterSequenceType("BS", "Test1", ILU_NIL, "ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  { /* array type "Test1_A2" */
    ilu_cardinal _Test1_A2_dims[] = { 3, 4 };
    _Test1_A2__IoFns.kernelType = ilu_RegisterArrayType("A2", "Test1", ILU_NIL, "ilut:kM2HH51HMYTWu-khgczpbgNaama",
    "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* base type of array */
    2,		/* number of dimensions */
    _Test1_A2_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  ilu_RegisterAliasType("A1", "Test1", ILU_NIL, "ilut:h3Dnvis94UwnmFURfYsCp700jVy",
    "ilut:h3Dnvis94UwnmFURfYsCp700jVy",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  { /* array type "Test1_TheA1" */
    ilu_cardinal _Test1_TheA1_dims[] = { 3 };
    _Test1_TheA1__IoFns.kernelType = ilu_RegisterArrayType("TheA1", "Test1", ILU_NIL, "ilut:h3Dnvis94UwnmFURfYsCp700jVy",
    "ilut:iqqhSf395+BafbY8Oo2elFQD1bK", /* base type of array */
    1,		/* number of dimensions */
    _Test1_TheA1_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  { /* array type "Test1_A0" */
    ilu_cardinal _Test1_A0_dims[] = { 8 };
    _Test1_A0__IoFns.kernelType = ilu_RegisterArrayType("A0", "Test1", ILU_NIL, "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r",
    "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc", /* base type of array */
    1,		/* number of dimensions */
    _Test1_A0_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  _Test1_CSS__IoFns.kernelType = ilu_RegisterSequenceType("CSS", "Test1", ILU_NIL, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy",
    "ilut:iqqhSf395+BafbY8Oo2elFQD1bK",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_ScS__IoFns.kernelType = ilu_RegisterSequenceType("ScS", "Test1", ILU_NIL, "ilut:iqqhSf395+BafbY8Oo2elFQD1bK",
    "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("C", "Test1", ILU_NIL, "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx",
    "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("SC", "Test1", ILU_NIL, "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0",
    "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _Test1_IS__IoFns.kernelType = ilu_RegisterSequenceType("IS", "Test1", ILU_NIL, "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO",
    "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("I", "Test1", ILU_NIL, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY",
    "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _Test1_O4__IoFns.properties.object_class = _Test1_O4__ILUType;
  _ILU_C_RegisterIoFns (&_Test1_O4__IoFns);

  _Test1_P__IoFns.properties.object_class = _Test1_P__ILUType;
  _ILU_C_RegisterIoFns (&_Test1_P__IoFns);

  _Test1_O3__IoFns.properties.object_class = _Test1_O3__ILUType;
  _ILU_C_RegisterIoFns (&_Test1_O3__IoFns);

  _Test1_TheO1__IoFns.properties.object_class = _Test1_TheO1__ILUType;
  _ILU_C_RegisterIoFns (&_Test1_TheO1__IoFns);

  _Test1_U_scard__IoFns.inputFn = (ILU_C_InputFn) _Test1_U_scard__Input;
  _Test1_U_scard__IoFns.outFn = (ILU_C_OutputFn) _Test1_U_scard__Output;
  _Test1_U_scard__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U_scard__SizeOf;
  _Test1_U_scard__IoFns.freeFn = (ILU_C_FreeFn) Test1_U_scard__Free;
  _ILU_C_RegisterIoFns (&_Test1_U_scard__IoFns);

  _Test1_U_card__IoFns.inputFn = (ILU_C_InputFn) _Test1_U_card__Input;
  _Test1_U_card__IoFns.outFn = (ILU_C_OutputFn) _Test1_U_card__Output;
  _Test1_U_card__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U_card__SizeOf;
  _Test1_U_card__IoFns.freeFn = (ILU_C_FreeFn) Test1_U_card__Free;
  _ILU_C_RegisterIoFns (&_Test1_U_card__IoFns);

  _Test1_U_int__IoFns.inputFn = (ILU_C_InputFn) _Test1_U_int__Input;
  _Test1_U_int__IoFns.outFn = (ILU_C_OutputFn) _Test1_U_int__Output;
  _Test1_U_int__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U_int__SizeOf;
  _Test1_U_int__IoFns.freeFn = (ILU_C_FreeFn) Test1_U_int__Free;
  _ILU_C_RegisterIoFns (&_Test1_U_int__IoFns);

  _Test1_U_byte__IoFns.inputFn = (ILU_C_InputFn) _Test1_U_byte__Input;
  _Test1_U_byte__IoFns.outFn = (ILU_C_OutputFn) _Test1_U_byte__Output;
  _Test1_U_byte__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U_byte__SizeOf;
  _Test1_U_byte__IoFns.freeFn = (ILU_C_FreeFn) Test1_U_byte__Free;
  _ILU_C_RegisterIoFns (&_Test1_U_byte__IoFns);

  _Test1_U4__IoFns.inputFn = (ILU_C_InputFn) _Test1_U4__Input;
  _Test1_U4__IoFns.outFn = (ILU_C_OutputFn) _Test1_U4__Output;
  _Test1_U4__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U4__SizeOf;
  _Test1_U4__IoFns.freeFn = (ILU_C_FreeFn) Test1_U4__Free;
  _ILU_C_RegisterIoFns (&_Test1_U4__IoFns);

  _Test1_U3__IoFns.inputFn = (ILU_C_InputFn) _Test1_U3__Input;
  _Test1_U3__IoFns.outFn = (ILU_C_OutputFn) _Test1_U3__Output;
  _Test1_U3__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U3__SizeOf;
  _Test1_U3__IoFns.freeFn = (ILU_C_FreeFn) Test1_U3__Free;
  _ILU_C_RegisterIoFns (&_Test1_U3__IoFns);

  _Test1_U2__IoFns.inputFn = (ILU_C_InputFn) _Test1_U2__Input;
  _Test1_U2__IoFns.outFn = (ILU_C_OutputFn) _Test1_U2__Output;
  _Test1_U2__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U2__SizeOf;
  _Test1_U2__IoFns.freeFn = (ILU_C_FreeFn) Test1_U2__Free;
  _ILU_C_RegisterIoFns (&_Test1_U2__IoFns);

  _ILU_C_RegisterIoFns (&_Test1_TheE__IoFns);

  _Test1_U1__IoFns.inputFn = (ILU_C_InputFn) _Test1_U1__Input;
  _Test1_U1__IoFns.outFn = (ILU_C_OutputFn) _Test1_U1__Output;
  _Test1_U1__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_U1__SizeOf;
  _Test1_U1__IoFns.freeFn = (ILU_C_FreeFn) Test1_U1__Free;
  _ILU_C_RegisterIoFns (&_Test1_U1__IoFns);

  _Test1_TheU__IoFns.inputFn = (ILU_C_InputFn) _Test1_TheU__Input;
  _Test1_TheU__IoFns.outFn = (ILU_C_OutputFn) _Test1_TheU__Output;
  _Test1_TheU__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_TheU__SizeOf;
  _Test1_TheU__IoFns.freeFn = (ILU_C_FreeFn) Test1_TheU__Free;
  _ILU_C_RegisterIoFns (&_Test1_TheU__IoFns);

  _Test1_OO2__IoFns.inputFn = (ILU_C_InputFn) _Test1_OO2__Input;
  _Test1_OO2__IoFns.outFn = (ILU_C_OutputFn) _Test1_OO2__Output;
  _Test1_OO2__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_OO2__SizeOf;
  _Test1_OO2__IoFns.freeFn = (ILU_C_FreeFn) Test1_OO2__Free;
  _ILU_C_RegisterIoFns (&_Test1_OO2__IoFns);

  _Test1_O2__IoFns.properties.object_class = _Test1_O2__ILUType;
  _ILU_C_RegisterIoFns (&_Test1_O2__IoFns);

  _Test1_TheOO__IoFns.inputFn = (ILU_C_InputFn) _Test1_TheOO__Input;
  _Test1_TheOO__IoFns.outFn = (ILU_C_OutputFn) _Test1_TheOO__Output;
  _Test1_TheOO__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_TheOO__SizeOf;
  _Test1_TheOO__IoFns.freeFn = (ILU_C_FreeFn) Test1_TheOO__Free;
  _ILU_C_RegisterIoFns (&_Test1_TheOO__IoFns);

  _Test1_RO__IoFns.inputFn = (ILU_C_InputFn) _Test1_RO__Input;
  _Test1_RO__IoFns.outFn = (ILU_C_OutputFn) _Test1_RO__Output;
  _Test1_RO__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_RO__SizeOf;
  _Test1_RO__IoFns.freeFn = (ILU_C_FreeFn) Test1_RO__Free;
  _ILU_C_RegisterIoFns (&_Test1_RO__IoFns);

  _Test1_TheRS__IoFns.inputFn = (ILU_C_InputFn) _Test1_TheRS__Input;
  _Test1_TheRS__IoFns.outFn = (ILU_C_OutputFn) _Test1_TheRS__Output;
  _Test1_TheRS__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_TheRS__SizeOf;
  _Test1_TheRS__IoFns.freeFn = (ILU_C_FreeFn) Test1_TheRS__Free;
  _ILU_C_RegisterIoFns (&_Test1_TheRS__IoFns);

  _Test1_TheR__IoFns.inputFn = (ILU_C_InputFn) _Test1_TheR__Input;
  _Test1_TheR__IoFns.outFn = (ILU_C_OutputFn) _Test1_TheR__Output;
  _Test1_TheR__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_TheR__SizeOf;
  _Test1_TheR__IoFns.freeFn = (ILU_C_FreeFn) Test1_TheR__Free;
  _ILU_C_RegisterIoFns (&_Test1_TheR__IoFns);

  _Test1_BS__IoFns.inputFn = (ILU_C_InputFn) _Test1_BS__Input;
  _Test1_BS__IoFns.outFn = (ILU_C_OutputFn) _Test1_BS__Output;
  _Test1_BS__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_BS__SizeOf;
  _Test1_BS__IoFns.freeFn = (ILU_C_FreeFn) Test1_BS__Free;
  _ILU_C_RegisterIoFns (&_Test1_BS__IoFns);

  _Test1_A2__IoFns.inputFn = (ILU_C_InputFn) _Test1_A2__Input;
  _Test1_A2__IoFns.outFn = (ILU_C_OutputFn) _Test1_A2__Output;
  _Test1_A2__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_A2__SizeOf;
  _Test1_A2__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Test1_A2__IoFns);

  _Test1_TheA1__IoFns.inputFn = (ILU_C_InputFn) _Test1_TheA1__Input;
  _Test1_TheA1__IoFns.outFn = (ILU_C_OutputFn) _Test1_TheA1__Output;
  _Test1_TheA1__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_TheA1__SizeOf;
  _Test1_TheA1__IoFns.freeFn = (ILU_C_FreeFn) Test1_TheA1__Free;
  _ILU_C_RegisterIoFns (&_Test1_TheA1__IoFns);

  _Test1_A0__IoFns.inputFn = (ILU_C_InputFn) _Test1_A0__Input;
  _Test1_A0__IoFns.outFn = (ILU_C_OutputFn) _Test1_A0__Output;
  _Test1_A0__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_A0__SizeOf;
  _Test1_A0__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_Test1_A0__IoFns);

  _Test1_CSS__IoFns.inputFn = (ILU_C_InputFn) _Test1_CSS__Input;
  _Test1_CSS__IoFns.outFn = (ILU_C_OutputFn) _Test1_CSS__Output;
  _Test1_CSS__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_CSS__SizeOf;
  _Test1_CSS__IoFns.freeFn = (ILU_C_FreeFn) Test1_CSS__Free;
  _ILU_C_RegisterIoFns (&_Test1_CSS__IoFns);

  _Test1_ScS__IoFns.inputFn = (ILU_C_InputFn) _Test1_ScS__Input;
  _Test1_ScS__IoFns.outFn = (ILU_C_OutputFn) _Test1_ScS__Output;
  _Test1_ScS__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_ScS__SizeOf;
  _Test1_ScS__IoFns.freeFn = (ILU_C_FreeFn) Test1_ScS__Free;
  _ILU_C_RegisterIoFns (&_Test1_ScS__IoFns);

  _Test1_IS__IoFns.inputFn = (ILU_C_InputFn) _Test1_IS__Input;
  _Test1_IS__IoFns.outFn = (ILU_C_OutputFn) _Test1_IS__Output;
  _Test1_IS__IoFns.sizeFn = (ILU_C_SizeFn) _Test1_IS__SizeOf;
  _Test1_IS__IoFns.freeFn = (ILU_C_FreeFn) Test1_IS__Free;
  _ILU_C_RegisterIoFns (&_Test1_IS__IoFns);

  _ILU_C_EnsureGcClient ();
fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

