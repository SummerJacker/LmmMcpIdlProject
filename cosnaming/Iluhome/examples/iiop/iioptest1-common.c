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
#include <string.h> /* used for error statements */
#include "iioptest1.h"

ilu_Class _iioptest1_xilu_obj__ILUType = NULL;
ilu_Class _iioptest1_ext_obj__ILUType = NULL;
ilu_Class _iioptest1_obj__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _iioptest1_xilu_obj__IoFns = { ilu_object_tk, "ilut:mbyJOnx0VN0V5byl6sLU4hGE82-", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_ext_obj__IoFns = { ilu_object_tk, "ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_opt1__IoFns = { ilu_optional_tk, "ilut:hlK1nloCSblsYHmRgvWX5jx91cp", { sizeof(iioptest1_opt1) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_union2__IoFns = { ilu_union_tk, "ilut:aRIPnvzDbqQaCcGIjccxZ1IaJSC", { sizeof(iioptest1_union2) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_union1__IoFns = { ilu_union_tk, "ilut:bGOh3+LBS9RFwWiJ1giyNTEhjWh", { sizeof(iioptest1_union1) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_enum1__IoFns = { ilu_enumeration_tk, "ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_seq1__IoFns = { ilu_sequence_tk, "ilut:j+1RscoPGsK8z6gMGEVLgFHM2Uc", { sizeof(iioptest1_seq1) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_arr4__IoFns = { ilu_array_tk, "ilut:m0fj5hi3ZLi6EtOg5endszy8Pqs", { sizeof(iioptest1_arr4) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_arr3__IoFns = { ilu_array_tk, "ilut:c13Jl5cNbwN2TCMXoOolEcAAuvR", { sizeof(iioptest1_arr3) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_arr2__IoFns = { ilu_array_tk, "ilut:m7779BmSgRHZ-LUq0QBnPQyRXwB", { sizeof(iioptest1_arr2) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_arr1__IoFns = { ilu_array_tk, "ilut:gt-ssb5dxOVCM+NRv7xibbgx15C", { sizeof(iioptest1_arr1) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_rec2__IoFns = { ilu_record_tk, "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM", { sizeof(iioptest1_rec2) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_rec1__IoFns = { ilu_record_tk, "ilut:jHYRUYvcjJXfNKFvDAktQANqXz-", { sizeof(iioptest1_rec1) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_x1_rec__IoFns = { ilu_record_tk, "ilut:gm+G75yVMIfAYUavXJ8FCuTaWrf", { sizeof(iioptest1_x1_rec) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_x2_rec__IoFns = { ilu_record_tk, "ilut:jrPVosIfQH0KKRrEEm4hgSetHs7", { sizeof(iioptest1_x2_rec) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_obj__IoFns = { ilu_object_tk, "IDL:Eng.SUN.COM/test1:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_string__IoFns = { ilu_sequence_tk, "ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv", { sizeof(iioptest1_string) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _iioptest1_UnicodeString__IoFns = { ilu_sequence_tk, "ilut:eIVlsdSfEXFq0qWlnmijMWfFvfC", { sizeof(iioptest1_UnicodeString) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class iioptest1_xilu_obj__MakeClass(
  iioptest1_opt1 (*iioptest1_xilu_obj_test_optional__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_opt1 a1, iioptest1_opt1* a2, iioptest1_opt1* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_xilu_obj_test_asynchronous__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long a1, ILU_C_ENVIRONMENT *_status),
  iioptest1_ext_obj (*iioptest1_ext_obj_test_obj__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec2 (*iioptest1_ext_obj_test_fixed_record__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_enum1 (*iioptest1_ext_obj_test_enumeration__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_seq1* (*iioptest1_ext_obj_test_sequence__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec1* (*iioptest1_ext_obj_test_var_record__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr1_slice * (*iioptest1_ext_obj_test_var_array__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr4_slice * (*iioptest1_ext_obj_test_fixed_array__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union1* (*iioptest1_ext_obj_test_var_union__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union2 (*iioptest1_ext_obj_test_fixed_union__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_void__Impl)
     (iioptest1_xilu_obj _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*iioptest1_obj_test_short__Impl)
     (iioptest1_xilu_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*iioptest1_obj_test_long__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_short (*iioptest1_obj_test_ushort__Impl)
     (iioptest1_xilu_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long (*iioptest1_obj_test_ulong__Impl)
     (iioptest1_xilu_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*iioptest1_obj_test_float__Impl)
     (iioptest1_xilu_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*iioptest1_obj_test_double__Impl)
     (iioptest1_xilu_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*iioptest1_obj_test_boolean__Impl)
     (iioptest1_xilu_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_char (*iioptest1_obj_test_char__Impl)
     (iioptest1_xilu_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_octet (*iioptest1_obj_test_octet__Impl)
     (iioptest1_xilu_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_string (*iioptest1_obj_test_string__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_long (*iioptest1_obj_test_longlong__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long_long (*iioptest1_obj_test_ulonglong__Impl)
     (iioptest1_xilu_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_wchar (*iioptest1_obj_test_wchar__Impl)
     (iioptest1_xilu_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_UnicodeString (*iioptest1_obj_test_wstring__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_double (*iioptest1_obj_test_longdouble__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_throw__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_please_exit__Impl)
     (iioptest1_xilu_obj _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _iioptest1_xilu_obj__ILUType;
  method_block = ilu_malloc(2 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iioptest1_xilu_obj_test_optional__Impl;
  method_block[1] = (_ILU_C_Method) iioptest1_xilu_obj_test_asynchronous__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _iioptest1_ext_obj__ILUType;
  method_block = ilu_malloc(9 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iioptest1_ext_obj_test_obj__Impl;
  method_block[1] = (_ILU_C_Method) iioptest1_ext_obj_test_fixed_record__Impl;
  method_block[2] = (_ILU_C_Method) iioptest1_ext_obj_test_enumeration__Impl;
  method_block[3] = (_ILU_C_Method) iioptest1_ext_obj_test_sequence__Impl;
  method_block[4] = (_ILU_C_Method) iioptest1_ext_obj_test_var_record__Impl;
  method_block[5] = (_ILU_C_Method) iioptest1_ext_obj_test_var_array__Impl;
  method_block[6] = (_ILU_C_Method) iioptest1_ext_obj_test_fixed_array__Impl;
  method_block[7] = (_ILU_C_Method) iioptest1_ext_obj_test_var_union__Impl;
  method_block[8] = (_ILU_C_Method) iioptest1_ext_obj_test_fixed_union__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _iioptest1_obj__ILUType;
  method_block = ilu_malloc(18 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iioptest1_obj_test_void__Impl;
  method_block[1] = (_ILU_C_Method) iioptest1_obj_test_short__Impl;
  method_block[2] = (_ILU_C_Method) iioptest1_obj_test_long__Impl;
  method_block[3] = (_ILU_C_Method) iioptest1_obj_test_ushort__Impl;
  method_block[4] = (_ILU_C_Method) iioptest1_obj_test_ulong__Impl;
  method_block[5] = (_ILU_C_Method) iioptest1_obj_test_float__Impl;
  method_block[6] = (_ILU_C_Method) iioptest1_obj_test_double__Impl;
  method_block[7] = (_ILU_C_Method) iioptest1_obj_test_boolean__Impl;
  method_block[8] = (_ILU_C_Method) iioptest1_obj_test_char__Impl;
  method_block[9] = (_ILU_C_Method) iioptest1_obj_test_octet__Impl;
  method_block[10] = (_ILU_C_Method) iioptest1_obj_test_string__Impl;
  method_block[11] = (_ILU_C_Method) iioptest1_obj_test_longlong__Impl;
  method_block[12] = (_ILU_C_Method) iioptest1_obj_test_ulonglong__Impl;
  method_block[13] = (_ILU_C_Method) iioptest1_obj_test_wchar__Impl;
  method_block[14] = (_ILU_C_Method) iioptest1_obj_test_wstring__Impl;
  method_block[15] = (_ILU_C_Method) iioptest1_obj_test_longdouble__Impl;
  method_block[16] = (_ILU_C_Method) iioptest1_obj_test_throw__Impl;
  method_block[17] = (_ILU_C_Method) iioptest1_obj_please_exit__Impl;
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
ILU_C_Class iioptest1_ext_obj__MakeClass(
  iioptest1_ext_obj (*iioptest1_ext_obj_test_obj__Impl)
     (iioptest1_ext_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec2 (*iioptest1_ext_obj_test_fixed_record__Impl)
     (iioptest1_ext_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_enum1 (*iioptest1_ext_obj_test_enumeration__Impl)
     (iioptest1_ext_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_seq1* (*iioptest1_ext_obj_test_sequence__Impl)
     (iioptest1_ext_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec1* (*iioptest1_ext_obj_test_var_record__Impl)
     (iioptest1_ext_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr1_slice * (*iioptest1_ext_obj_test_var_array__Impl)
     (iioptest1_ext_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr4_slice * (*iioptest1_ext_obj_test_fixed_array__Impl)
     (iioptest1_ext_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union1* (*iioptest1_ext_obj_test_var_union__Impl)
     (iioptest1_ext_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union2 (*iioptest1_ext_obj_test_fixed_union__Impl)
     (iioptest1_ext_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_void__Impl)
     (iioptest1_ext_obj _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*iioptest1_obj_test_short__Impl)
     (iioptest1_ext_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*iioptest1_obj_test_long__Impl)
     (iioptest1_ext_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_short (*iioptest1_obj_test_ushort__Impl)
     (iioptest1_ext_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long (*iioptest1_obj_test_ulong__Impl)
     (iioptest1_ext_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*iioptest1_obj_test_float__Impl)
     (iioptest1_ext_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*iioptest1_obj_test_double__Impl)
     (iioptest1_ext_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*iioptest1_obj_test_boolean__Impl)
     (iioptest1_ext_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_char (*iioptest1_obj_test_char__Impl)
     (iioptest1_ext_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_octet (*iioptest1_obj_test_octet__Impl)
     (iioptest1_ext_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_string (*iioptest1_obj_test_string__Impl)
     (iioptest1_ext_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_long (*iioptest1_obj_test_longlong__Impl)
     (iioptest1_ext_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long_long (*iioptest1_obj_test_ulonglong__Impl)
     (iioptest1_ext_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_wchar (*iioptest1_obj_test_wchar__Impl)
     (iioptest1_ext_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_UnicodeString (*iioptest1_obj_test_wstring__Impl)
     (iioptest1_ext_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_double (*iioptest1_obj_test_longdouble__Impl)
     (iioptest1_ext_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_throw__Impl)
     (iioptest1_ext_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_please_exit__Impl)
     (iioptest1_ext_obj _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _iioptest1_ext_obj__ILUType;
  method_block = ilu_malloc(9 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iioptest1_ext_obj_test_obj__Impl;
  method_block[1] = (_ILU_C_Method) iioptest1_ext_obj_test_fixed_record__Impl;
  method_block[2] = (_ILU_C_Method) iioptest1_ext_obj_test_enumeration__Impl;
  method_block[3] = (_ILU_C_Method) iioptest1_ext_obj_test_sequence__Impl;
  method_block[4] = (_ILU_C_Method) iioptest1_ext_obj_test_var_record__Impl;
  method_block[5] = (_ILU_C_Method) iioptest1_ext_obj_test_var_array__Impl;
  method_block[6] = (_ILU_C_Method) iioptest1_ext_obj_test_fixed_array__Impl;
  method_block[7] = (_ILU_C_Method) iioptest1_ext_obj_test_var_union__Impl;
  method_block[8] = (_ILU_C_Method) iioptest1_ext_obj_test_fixed_union__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _iioptest1_obj__ILUType;
  method_block = ilu_malloc(18 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iioptest1_obj_test_void__Impl;
  method_block[1] = (_ILU_C_Method) iioptest1_obj_test_short__Impl;
  method_block[2] = (_ILU_C_Method) iioptest1_obj_test_long__Impl;
  method_block[3] = (_ILU_C_Method) iioptest1_obj_test_ushort__Impl;
  method_block[4] = (_ILU_C_Method) iioptest1_obj_test_ulong__Impl;
  method_block[5] = (_ILU_C_Method) iioptest1_obj_test_float__Impl;
  method_block[6] = (_ILU_C_Method) iioptest1_obj_test_double__Impl;
  method_block[7] = (_ILU_C_Method) iioptest1_obj_test_boolean__Impl;
  method_block[8] = (_ILU_C_Method) iioptest1_obj_test_char__Impl;
  method_block[9] = (_ILU_C_Method) iioptest1_obj_test_octet__Impl;
  method_block[10] = (_ILU_C_Method) iioptest1_obj_test_string__Impl;
  method_block[11] = (_ILU_C_Method) iioptest1_obj_test_longlong__Impl;
  method_block[12] = (_ILU_C_Method) iioptest1_obj_test_ulonglong__Impl;
  method_block[13] = (_ILU_C_Method) iioptest1_obj_test_wchar__Impl;
  method_block[14] = (_ILU_C_Method) iioptest1_obj_test_wstring__Impl;
  method_block[15] = (_ILU_C_Method) iioptest1_obj_test_longdouble__Impl;
  method_block[16] = (_ILU_C_Method) iioptest1_obj_test_throw__Impl;
  method_block[17] = (_ILU_C_Method) iioptest1_obj_please_exit__Impl;
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
ILU_C_Class iioptest1_obj__MakeClass(
  void (*iioptest1_obj_test_void__Impl)
     (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*iioptest1_obj_test_short__Impl)
     (iioptest1_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*iioptest1_obj_test_long__Impl)
     (iioptest1_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_short (*iioptest1_obj_test_ushort__Impl)
     (iioptest1_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long (*iioptest1_obj_test_ulong__Impl)
     (iioptest1_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*iioptest1_obj_test_float__Impl)
     (iioptest1_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*iioptest1_obj_test_double__Impl)
     (iioptest1_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*iioptest1_obj_test_boolean__Impl)
     (iioptest1_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_char (*iioptest1_obj_test_char__Impl)
     (iioptest1_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_octet (*iioptest1_obj_test_octet__Impl)
     (iioptest1_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_string (*iioptest1_obj_test_string__Impl)
     (iioptest1_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_long (*iioptest1_obj_test_longlong__Impl)
     (iioptest1_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long_long (*iioptest1_obj_test_ulonglong__Impl)
     (iioptest1_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_wchar (*iioptest1_obj_test_wchar__Impl)
     (iioptest1_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_UnicodeString (*iioptest1_obj_test_wstring__Impl)
     (iioptest1_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_double (*iioptest1_obj_test_longdouble__Impl)
     (iioptest1_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_throw__Impl)
     (iioptest1_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_please_exit__Impl)
     (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _iioptest1_obj__ILUType;
  method_block = ilu_malloc(18 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) iioptest1_obj_test_void__Impl;
  method_block[1] = (_ILU_C_Method) iioptest1_obj_test_short__Impl;
  method_block[2] = (_ILU_C_Method) iioptest1_obj_test_long__Impl;
  method_block[3] = (_ILU_C_Method) iioptest1_obj_test_ushort__Impl;
  method_block[4] = (_ILU_C_Method) iioptest1_obj_test_ulong__Impl;
  method_block[5] = (_ILU_C_Method) iioptest1_obj_test_float__Impl;
  method_block[6] = (_ILU_C_Method) iioptest1_obj_test_double__Impl;
  method_block[7] = (_ILU_C_Method) iioptest1_obj_test_boolean__Impl;
  method_block[8] = (_ILU_C_Method) iioptest1_obj_test_char__Impl;
  method_block[9] = (_ILU_C_Method) iioptest1_obj_test_octet__Impl;
  method_block[10] = (_ILU_C_Method) iioptest1_obj_test_string__Impl;
  method_block[11] = (_ILU_C_Method) iioptest1_obj_test_longlong__Impl;
  method_block[12] = (_ILU_C_Method) iioptest1_obj_test_ulonglong__Impl;
  method_block[13] = (_ILU_C_Method) iioptest1_obj_test_wchar__Impl;
  method_block[14] = (_ILU_C_Method) iioptest1_obj_test_wstring__Impl;
  method_block[15] = (_ILU_C_Method) iioptest1_obj_test_longdouble__Impl;
  method_block[16] = (_ILU_C_Method) iioptest1_obj_test_throw__Impl;
  method_block[17] = (_ILU_C_Method) iioptest1_obj_please_exit__Impl;
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
iioptest1_opt1 iioptest1_xilu_obj_test_optional (iioptest1_xilu_obj _handle, iioptest1_opt1 a1, iioptest1_opt1* a2, iioptest1_opt1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_opt1 (*_f)(iioptest1_xilu_obj, iioptest1_opt1, iioptest1_opt1*, iioptest1_opt1*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_opt1 _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_opt1 (*)(iioptest1_xilu_obj, iioptest1_opt1, iioptest1_opt1*, iioptest1_opt1*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_xilu_obj__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

void iioptest1_xilu_obj_test_asynchronous (iioptest1_xilu_obj _handle, CORBA_long a1, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(iioptest1_xilu_obj, CORBA_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(iioptest1_xilu_obj, CORBA_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_xilu_obj__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, a1, _status);
}

iioptest1_ext_obj iioptest1_ext_obj_test_obj (iioptest1_ext_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_ext_obj (*_f)(iioptest1_ext_obj, iioptest1_ext_obj, iioptest1_ext_obj*, iioptest1_ext_obj*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_ext_obj _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_ext_obj (*)(iioptest1_ext_obj, iioptest1_ext_obj, iioptest1_ext_obj*, iioptest1_ext_obj*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_rec2 iioptest1_ext_obj_test_fixed_record (iioptest1_ext_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_rec2 (*_f)(iioptest1_ext_obj, iioptest1_rec2*, iioptest1_rec2*, iioptest1_rec2*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_rec2 _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_rec2 (*)(iioptest1_ext_obj, iioptest1_rec2*, iioptest1_rec2*, iioptest1_rec2*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_enum1 iioptest1_ext_obj_test_enumeration (iioptest1_ext_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_enum1 (*_f)(iioptest1_ext_obj, iioptest1_enum1, iioptest1_enum1*, iioptest1_enum1*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_enum1 _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_enum1 (*)(iioptest1_ext_obj, iioptest1_enum1, iioptest1_enum1*, iioptest1_enum1*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_seq1* iioptest1_ext_obj_test_sequence (iioptest1_ext_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_seq1* (*_f)(iioptest1_ext_obj, iioptest1_seq1*, iioptest1_seq1**, iioptest1_seq1*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_seq1* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_seq1* (*)(iioptest1_ext_obj, iioptest1_seq1*, iioptest1_seq1**, iioptest1_seq1*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_rec1* iioptest1_ext_obj_test_var_record (iioptest1_ext_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_rec1* (*_f)(iioptest1_ext_obj, iioptest1_rec1*, iioptest1_rec1**, iioptest1_rec1*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_rec1* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_rec1* (*)(iioptest1_ext_obj, iioptest1_rec1*, iioptest1_rec1**, iioptest1_rec1*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_arr1_slice * iioptest1_ext_obj_test_var_array (iioptest1_ext_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_arr1_slice * (*_f)(iioptest1_ext_obj, iioptest1_arr1, iioptest1_arr1_slice **, iioptest1_arr1, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_arr1_slice * _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_arr1_slice * (*)(iioptest1_ext_obj, iioptest1_arr1, iioptest1_arr1_slice **, iioptest1_arr1, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_arr4_slice * iioptest1_ext_obj_test_fixed_array (iioptest1_ext_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_arr4_slice * (*_f)(iioptest1_ext_obj, iioptest1_arr4, iioptest1_arr4, iioptest1_arr4, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_arr4_slice * _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_arr4_slice * (*)(iioptest1_ext_obj, iioptest1_arr4, iioptest1_arr4, iioptest1_arr4, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_union1* iioptest1_ext_obj_test_var_union (iioptest1_ext_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_union1* (*_f)(iioptest1_ext_obj, iioptest1_union1*, iioptest1_union1**, iioptest1_union1*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_union1* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_union1* (*)(iioptest1_ext_obj, iioptest1_union1*, iioptest1_union1**, iioptest1_union1*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_union2 iioptest1_ext_obj_test_fixed_union (iioptest1_ext_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_union2 (*_f)(iioptest1_ext_obj, iioptest1_union2*, iioptest1_union2*, iioptest1_union2*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_union2 _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_union2 (*)(iioptest1_ext_obj, iioptest1_union2*, iioptest1_union2*, iioptest1_union2*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_ext_obj__ILUType, 8);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

void iioptest1_obj_test_void (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(iioptest1_obj, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(iioptest1_obj, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

CORBA_short iioptest1_obj_test_short (iioptest1_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short (*_f)(iioptest1_obj, CORBA_short, CORBA_short*, CORBA_short*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_short _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_short (*)(iioptest1_obj, CORBA_short, CORBA_short*, CORBA_short*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_long iioptest1_obj_test_long (iioptest1_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long (*_f)(iioptest1_obj, CORBA_long, CORBA_long*, CORBA_long*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_long _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_long (*)(iioptest1_obj, CORBA_long, CORBA_long*, CORBA_long*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_unsigned_short iioptest1_obj_test_ushort (iioptest1_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_short (*_f)(iioptest1_obj, CORBA_unsigned_short, CORBA_unsigned_short*, CORBA_unsigned_short*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_unsigned_short _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_unsigned_short (*)(iioptest1_obj, CORBA_unsigned_short, CORBA_unsigned_short*, CORBA_unsigned_short*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_unsigned_long iioptest1_obj_test_ulong (iioptest1_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long (*_f)(iioptest1_obj, CORBA_unsigned_long, CORBA_unsigned_long*, CORBA_unsigned_long*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_unsigned_long _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_unsigned_long (*)(iioptest1_obj, CORBA_unsigned_long, CORBA_unsigned_long*, CORBA_unsigned_long*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_float iioptest1_obj_test_float (iioptest1_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_float (*_f)(iioptest1_obj, CORBA_float, CORBA_float*, CORBA_float*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_float _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_float (*)(iioptest1_obj, CORBA_float, CORBA_float*, CORBA_float*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_double iioptest1_obj_test_double (iioptest1_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_double (*_f)(iioptest1_obj, CORBA_double, CORBA_double*, CORBA_double*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_double _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_double (*)(iioptest1_obj, CORBA_double, CORBA_double*, CORBA_double*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_boolean iioptest1_obj_test_boolean (iioptest1_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(iioptest1_obj, CORBA_boolean, CORBA_boolean*, CORBA_boolean*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(iioptest1_obj, CORBA_boolean, CORBA_boolean*, CORBA_boolean*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_char iioptest1_obj_test_char (iioptest1_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_char (*_f)(iioptest1_obj, CORBA_char, CORBA_char*, CORBA_char*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_char _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_char (*)(iioptest1_obj, CORBA_char, CORBA_char*, CORBA_char*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 8);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_octet iioptest1_obj_test_octet (iioptest1_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_octet (*_f)(iioptest1_obj, CORBA_octet, CORBA_octet*, CORBA_octet*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_octet _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_octet (*)(iioptest1_obj, CORBA_octet, CORBA_octet*, CORBA_octet*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 9);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_string iioptest1_obj_test_string (iioptest1_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_string (*_f)(iioptest1_obj, iioptest1_string, iioptest1_string*, iioptest1_string*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_string _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_string (*)(iioptest1_obj, iioptest1_string, iioptest1_string*, iioptest1_string*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 10);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_long_long iioptest1_obj_test_longlong (iioptest1_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long_long (*_f)(iioptest1_obj, CORBA_long_long, CORBA_long_long*, CORBA_long_long*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_long_long _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_long_long (*)(iioptest1_obj, CORBA_long_long, CORBA_long_long*, CORBA_long_long*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 11);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_unsigned_long_long iioptest1_obj_test_ulonglong (iioptest1_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long_long (*_f)(iioptest1_obj, CORBA_unsigned_long_long, CORBA_unsigned_long_long*, CORBA_unsigned_long_long*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_unsigned_long_long _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_unsigned_long_long (*)(iioptest1_obj, CORBA_unsigned_long_long, CORBA_unsigned_long_long*, CORBA_unsigned_long_long*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 12);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_wchar iioptest1_obj_test_wchar (iioptest1_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_wchar (*_f)(iioptest1_obj, CORBA_wchar, CORBA_wchar*, CORBA_wchar*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_wchar _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_wchar (*)(iioptest1_obj, CORBA_wchar, CORBA_wchar*, CORBA_wchar*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 13);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

iioptest1_UnicodeString iioptest1_obj_test_wstring (iioptest1_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_UnicodeString (*_f)(iioptest1_obj, iioptest1_UnicodeString, iioptest1_UnicodeString*, iioptest1_UnicodeString*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    iioptest1_UnicodeString _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (iioptest1_UnicodeString (*)(iioptest1_obj, iioptest1_UnicodeString, iioptest1_UnicodeString*, iioptest1_UnicodeString*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 14);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

CORBA_long_double iioptest1_obj_test_longdouble (iioptest1_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long_double (*_f)(iioptest1_obj, CORBA_long_double, CORBA_long_double*, CORBA_long_double*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_long_double _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_long_double (*)(iioptest1_obj, CORBA_long_double, CORBA_long_double*, CORBA_long_double*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 15);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, a1, a2, a3, _status));
}

void iioptest1_obj_test_throw (iioptest1_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(iioptest1_obj, CORBA_long, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(iioptest1_obj, CORBA_long, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 16);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, case_num, _status);
}

void iioptest1_obj_please_exit (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(iioptest1_obj, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(iioptest1_obj, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _iioptest1_obj__ILUType, 17);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

void iioptest1_xilu_obj__SetUserData (iioptest1_xilu_obj self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *iioptest1_xilu_obj__GetUserData (iioptest1_xilu_obj self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void iioptest1_ext_obj__SetUserData (iioptest1_ext_obj self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *iioptest1_ext_obj__GetUserData (iioptest1_ext_obj self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void iioptest1_obj__SetUserData (iioptest1_obj self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *iioptest1_obj__GetUserData (iioptest1_obj self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _iioptest1__Exception_x1 = ILU_NIL;
ILU_C_ExceptionCode _iioptest1__Exception_x2 = ILU_NIL;
#include <stdarg.h>

void iioptest1__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_iioptest1_x1) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (iioptest1_x1_rec));
    *(iioptest1_x1_rec*)stat->ptr = *va_arg (ap, iioptest1_x1_rec*);
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_iioptest1_x2) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (iioptest1_x2_rec));
    *(iioptest1_x2_rec*)stat->ptr = *va_arg (ap, iioptest1_x2_rec*);
    stat->freeRoutine = (void (*) (void *)) iioptest1_x2_rec__Free;
  }
  else
    _ilu_Assert(0, "bad exn given to iioptest1__BindExceptionValue");
  va_end (ap);
}

void iioptest1_xilu_obj__Free (iioptest1_xilu_obj* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_xilu_obj */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

iioptest1_xilu_obj *CORBA_sequence_iioptest1_xilu_obj_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_xilu_obj *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_xilu_obj) * _count;

  if ((_p = (iioptest1_xilu_obj *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void iioptest1_ext_obj__Free (iioptest1_ext_obj* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_ext_obj */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

iioptest1_ext_obj *CORBA_sequence_iioptest1_ext_obj_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_ext_obj *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_ext_obj) * _count;

  if ((_p = (iioptest1_ext_obj *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_opt1* _iioptest1_opt1__Input (ilu_Call _call, iioptest1_opt1* _ref, ilu_Error *_err)
{
  iioptest1_opt1* _val = _ref;

  ilu_boolean _present;
  ilu_InputOptional (_call, &_present, ILU_C_KERNEL_TYPE(iioptest1_opt1), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (iioptest1_opt1 *) ilu_MallocE (sizeof (iioptest1_opt1), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) _val, 0, sizeof(iioptest1_opt1));
  };
  if (_present)
    {
    *_val = (iioptest1_rec2*) ilu_MallocE (sizeof (iioptest1_rec2), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
    memset((void *) *_val, 0, sizeof(iioptest1_rec2));
      (void) _iioptest1_rec2__Input (_call, *_val,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_opt1__Output (ilu_Call _call, iioptest1_opt1 _val, ilu_Error *_err)
{
  ilu_OutputOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(iioptest1_opt1), _err);
  if (ILU_ERRNOK(*_err) || (_val == ILU_NIL)) return;
  _iioptest1_rec2__Output(_call, _val, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
 marshalError:
  return;
}

ilu_cardinal _iioptest1_opt1__SizeOf (ilu_Call _call, iioptest1_opt1 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfOptional (_call, _val != ILU_NIL, ILU_C_KERNEL_TYPE(iioptest1_opt1), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (_val != ILU_NIL)
    size += _iioptest1_rec2__SizeOf (_call, &*_val, _err);
  return size;
}

void iioptest1_opt1__Free (iioptest1_opt1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_opt1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  /* subtype is iioptest1_rec2 */
  if ((_val != ILU_NIL) && (*_val != ILU_NIL)) {
    ilu_free(*_val);
  }
}

iioptest1_opt1 *CORBA_sequence_iioptest1_opt1_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_opt1 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_opt1) * _count;

  if ((_p = (iioptest1_opt1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_opt1* iioptest1_opt1__alloc ()
{
  return ((iioptest1_opt1*) CORBA_sequence_iioptest1_opt1_allocbuf(1));
}

iioptest1_union2* _iioptest1_union2__Input (ilu_Call _call, iioptest1_union2* _ref, ilu_Error *_err)
{
  iioptest1_union2* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(iioptest1_union2), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (iioptest1_union2*) ilu_MallocE(sizeof (iioptest1_union2), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(iioptest1_union2));
  };
  switch (tag) {
    case 0:
      ilu_InputInteger (_call, &_val->_u.integer, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      ilu_InputReal (_call, &_val->_u.real, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_iioptest1_union2__Input:  Bad value %lu received for discriminant.\n", (unsigned long) tag);
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

void _iioptest1_union2__Output (ilu_Call _call, iioptest1_union2* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(iioptest1_union2), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case 0:
      ilu_OutputInteger (_call, _val->_u.integer, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case 1:
      ilu_OutputReal(_call, _val->_u.real, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      fprintf (stderr, "_iioptest1_union2__Output:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_union2__SizeOf (ilu_Call _call, iioptest1_union2* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_shortinteger_tk, ILU_C_KERNEL_TYPE(iioptest1_union2), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case 0:
      size += ilu_SizeOfInteger(_call, _val->_u.integer, _err);
      break;
    case 1:
      size += ilu_SizeOfReal(_call, _val->_u.real, _err);
      break;
    default:
      fprintf (stderr, "_iioptest1_union2__SizeOf:  Bad value %lu in discriminant.\n", (unsigned long) _val->_d);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

iioptest1_union2 *CORBA_sequence_iioptest1_union2_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_union2 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_union2) * _count;

  if ((_p = (iioptest1_union2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_union2* iioptest1_union2__alloc ()
{
  return ((iioptest1_union2*) CORBA_sequence_iioptest1_union2_allocbuf(1));
}

iioptest1_union1* _iioptest1_union1__Input (ilu_Call _call, iioptest1_union1* _ref, ilu_Error *_err)
{
  iioptest1_union1* _val = _ref;

  ilu_cardinal tag=0;

  ilu_InputUnion (_call, &tag, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(iioptest1_union1), _err);
  if (ILU_ERRNOK(*_err))
    goto marshalError;
  if (_ref == ILU_NIL) {
    _val = (iioptest1_union1*) ilu_MallocE(sizeof (iioptest1_union1), _err);
      if (_val == ILU_NIL) goto marshalError;
      memset((void*) _val, 0, sizeof(iioptest1_union1));
  };
  switch (tag) {
    case iioptest1_a:
      (void) _iioptest1_rec1__Input (_call, &_val->_u.a,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case iioptest1_b:
      (void) _iioptest1_arr1__Input (_call, _val->_u.b,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case iioptest1_c:
      (void) _iioptest1_seq1__Input (_call, &_val->_u.c,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      {
        ilu_shortcardinal _xxx;
        ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        *&_val->_u.d = (iioptest1_enum1) _xxx;
      };
      break;
  }
  _val->_d = (iioptest1_enum1) tag;
  ilu_EndUnion (_call, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _iioptest1_union1__Output (ilu_Call _call, iioptest1_union1* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(iioptest1_union1), _err);
  if (ILU_ERRNOK(*_err)) return;
  switch (_val->_d) {
    case iioptest1_a:
      _iioptest1_rec1__Output(_call, &_val->_u.a, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case iioptest1_b:
      _iioptest1_arr1__Output(_call, _val->_u.b, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    case iioptest1_c:
      _iioptest1_seq1__Output(_call, &_val->_u.c, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
    default:
      ilu_OutputEnum (_call, (ilu_shortcardinal) _val->_u.d, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      break;
  };
  ilu_EndUnion (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_union1__SizeOf (ilu_Call _call, iioptest1_union1* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfUnion (_call, _val->_d, ilu_enumeration_tk, ILU_C_KERNEL_TYPE(iioptest1_union1), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  switch (_val->_d) {
    case iioptest1_a:
      size += _iioptest1_rec1__SizeOf (_call, &_val->_u.a, _err);
      break;
    case iioptest1_b:
      size += _iioptest1_arr1__SizeOf (_call, _val->_u.b, _err);
      break;
    case iioptest1_c:
      size += _iioptest1_seq1__SizeOf (_call, &_val->_u.c, _err);
      break;
    default:
      size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) _val->_u.d, (ilu_Type)ILU_NIL,  _err);
      break;
  };
  ilu_EndUnion (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iioptest1_union1__Free (iioptest1_union1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_union1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  switch (_val->_d) {
    case iioptest1_a:
      iioptest1_rec1__Free (&_val->_u.a);
      break;
    case iioptest1_b:
      iioptest1_arr1__Free (&_val->_u.b);
      break;
    case iioptest1_c:
      iioptest1_seq1__Free (&_val->_u.c);
      break;
    default:
      break;
  };
}

iioptest1_union1 *CORBA_sequence_iioptest1_union1_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_union1 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_union1) * _count;

  if ((_p = (iioptest1_union1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_union1* iioptest1_union1__alloc ()
{
  return ((iioptest1_union1*) CORBA_sequence_iioptest1_union1_allocbuf(1));
}

iioptest1_enum1 *CORBA_sequence_iioptest1_enum1_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_enum1 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_enum1) * _count;

  if ((_p = (iioptest1_enum1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_seq1* _iioptest1_seq1__Input (ilu_Call _call, iioptest1_seq1* _ref, ilu_Error *_err)
{
  iioptest1_seq1* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  iioptest1_rec2 _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (iioptest1_seq1*) ilu_MallocE(sizeof (iioptest1_seq1), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  iioptest1_seq1_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(iioptest1_seq1), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(iioptest1_rec2), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(iioptest1_rec2), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _iioptest1_rec2__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      iioptest1_seq1_Append (_val, &_tmp, _err);
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

void _iioptest1_seq1__Output (ilu_Call _call, iioptest1_seq1* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(iioptest1_seq1), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_rec2), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(iioptest1_rec2), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    iioptest1_rec2 *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _iioptest1_rec2__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _iioptest1_seq1__SizeOf (ilu_Call _call, iioptest1_seq1* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(iioptest1_seq1), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_rec2), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(iioptest1_rec2), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    iioptest1_rec2 *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _iioptest1_rec2__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iioptest1_seq1__Free (iioptest1_seq1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_seq1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(iioptest1_rec2)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(iioptest1_rec2)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(iioptest1_rec2))) */ ) {
    //ilu_DebugPrintf("OK iioptest1_seq1__Free (iioptest1_seq1* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

iioptest1_seq1 *CORBA_sequence_iioptest1_seq1_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_seq1 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_seq1) * _count;

  if ((_p = (iioptest1_seq1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_seq1* iioptest1_seq1__alloc ()
{
  return ((iioptest1_seq1*) CORBA_sequence_iioptest1_seq1_allocbuf(1));
}

iioptest1_arr4_slice * _iioptest1_arr4__Input (ilu_Call _call, iioptest1_arr4 _ref, ilu_Error *_err)
{
  iioptest1_arr4_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (iioptest1_arr4_slice *) ilu_MallocE(sizeof(iioptest1_arr4), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_InputArray (_call, ILU_C_KERNEL_TYPE(iioptest1_arr4), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(iioptest1_rec2), 6, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val, sizeof(iioptest1_arr4), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
      (void) _iioptest1_rec2__Input (_call, &_val[_i0][_i1],  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_arr4__Output (ilu_Call _call, iioptest1_arr4 _val, ilu_Error *_err)
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
    ilu_OutputArray (_call, 6, ILU_C_KERNEL_TYPE(iioptest1_arr4), _err); if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_rec2), 6, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val, sizeof(iioptest1_arr4), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
          _iioptest1_rec2__Output(_call, &_val[_i0][_i1], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      }
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_arr4__SizeOf (ilu_Call _call, iioptest1_arr4 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfArray (_call, 6, ILU_C_KERNEL_TYPE(iioptest1_arr4), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_rec2), 6, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque(_call, (ilu_bytes)_val, sizeof(iioptest1_arr4), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
          size += _iioptest1_rec2__SizeOf (_call, &_val[_i0][_i1], _err);
      }
    }
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

iioptest1_arr4 *CORBA_sequence_iioptest1_arr4_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_arr4 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_arr4) * _count;

  if ((_p = (iioptest1_arr4 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_arr4_slice * iioptest1_arr4__alloc ()
{
  return ((iioptest1_arr4_slice *) CORBA_sequence_iioptest1_arr4_allocbuf(1));
}

iioptest1_arr3_slice * _iioptest1_arr3__Input (ilu_Call _call, iioptest1_arr3 _ref, ilu_Error *_err)
{
  iioptest1_arr3_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (iioptest1_arr3_slice *) ilu_MallocE(sizeof(iioptest1_arr3), _err);
    if (_val == ILU_NIL)  goto marshalError;
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
    {
      ilu_string _tmp = _val[_i0];
      ilu_InputStringVec (_call, &_tmp, 3, _err);
    }
  }
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _iioptest1_arr3__Output (ilu_Call _call, iioptest1_arr3 _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
    ilu_OutputStringVec (_call, (_val[_i0]), 3, _err);
  }
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_arr3__SizeOf (ilu_Call _call, iioptest1_arr3 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
    size += ilu_SizeOfStringVec (_call, (_val[_i0]), 3, _err);
  }
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

iioptest1_arr3 *CORBA_sequence_iioptest1_arr3_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_arr3 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_arr3) * _count;

  if ((_p = (iioptest1_arr3 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_arr3_slice * iioptest1_arr3__alloc ()
{
  return ((iioptest1_arr3_slice *) CORBA_sequence_iioptest1_arr3_allocbuf(1));
}

iioptest1_arr2_slice * _iioptest1_arr2__Input (ilu_Call _call, iioptest1_arr2 _ref, ilu_Error *_err)
{
  iioptest1_arr2_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (iioptest1_arr2_slice *) ilu_MallocE(sizeof(iioptest1_arr2), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_InputArray (_call, ILU_C_KERNEL_TYPE(iioptest1_arr2), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(iioptest1_string), 6, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val, sizeof(iioptest1_arr2), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
      (void) _iioptest1_string__Input (_call, &_val[_i0][_i1],  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_arr2__Output (ilu_Call _call, iioptest1_arr2 _val, ilu_Error *_err)
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
    ilu_OutputArray (_call, 6, ILU_C_KERNEL_TYPE(iioptest1_arr2), _err); if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_string), 6, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val, sizeof(iioptest1_arr2), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
          _iioptest1_string__Output(_call, _val[_i0][_i1], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      }
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_arr2__SizeOf (ilu_Call _call, iioptest1_arr2 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfArray (_call, 6, ILU_C_KERNEL_TYPE(iioptest1_arr2), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_string), 6, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque(_call, (ilu_bytes)_val, sizeof(iioptest1_arr2), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
          size += _iioptest1_string__SizeOf (_call, _val[_i0][_i1], _err);
      }
    }
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iioptest1_arr2__Free (iioptest1_arr2* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_arr2 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
        iioptest1_string__Free (&(*_val)[_i0][_i1]);
      }
    }
}

iioptest1_arr2 *CORBA_sequence_iioptest1_arr2_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_arr2 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_arr2) * _count;

  if ((_p = (iioptest1_arr2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_arr2_slice * iioptest1_arr2__alloc ()
{
  return ((iioptest1_arr2_slice *) CORBA_sequence_iioptest1_arr2_allocbuf(1));
}

iioptest1_arr1_slice * _iioptest1_arr1__Input (ilu_Call _call, iioptest1_arr1 _ref, ilu_Error *_err)
{
  iioptest1_arr1_slice * _val = _ref;

  if (_ref == ILU_NIL)
    _val = (iioptest1_arr1_slice *) ilu_MallocE(sizeof(iioptest1_arr1), _err);
    if (_val == ILU_NIL)  goto marshalError;
  {
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    ilu_boolean blockmove = ilu_FALSE;
    ilu_cardinal aligncode,size;
    ilu_bytes* nec;
    _ILU_C_AlignmentProc alignproc;
#endif
    ilu_InputArray (_call, ILU_C_KERNEL_TYPE(iioptest1_arr1), _err);
    if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(iioptest1_rec1), 6, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val, sizeof(iioptest1_arr1), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
      (void) _iioptest1_rec1__Input (_call, &_val[_i0][_i1],  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_arr1__Output (ilu_Call _call, iioptest1_arr1 _val, ilu_Error *_err)
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
    ilu_OutputArray (_call, 6, ILU_C_KERNEL_TYPE(iioptest1_arr1), _err); if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_rec1), 6, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val, sizeof(iioptest1_arr1), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
          _iioptest1_rec1__Output(_call, &_val[_i0][_i1], _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      }
    }
  }
  ilu_EndArray (_call, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_arr1__SizeOf (ilu_Call _call, iioptest1_arr1 _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfArray (_call, 6, ILU_C_KERNEL_TYPE(iioptest1_arr1), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(iioptest1_rec1), 6, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque(_call, (ilu_bytes)_val, sizeof(iioptest1_arr1), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
          size += _iioptest1_rec1__SizeOf (_call, &_val[_i0][_i1], _err);
      }
    }
  ilu_EndArray (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iioptest1_arr1__Free (iioptest1_arr1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_arr1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
    {
      register int _i0;
      for (_i0 = 0;  _i0 < 2;  _i0 += 1)
      {
        register int _i1;
        for (_i1 = 0;  _i1 < 3;  _i1 += 1)
        iioptest1_rec1__Free (&(*_val)[_i0][_i1]);
      }
    }
}

iioptest1_arr1 *CORBA_sequence_iioptest1_arr1_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_arr1 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_arr1) * _count;

  if ((_p = (iioptest1_arr1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_arr1_slice * iioptest1_arr1__alloc ()
{
  return ((iioptest1_arr1_slice *) CORBA_sequence_iioptest1_arr1_allocbuf(1));
}

iioptest1_rec2* _iioptest1_rec2__Input (ilu_Call _call, iioptest1_rec2* _ref, ilu_Error *_err)
{
  iioptest1_rec2* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_rec2__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_rec2__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (iioptest1_rec2*) ilu_MallocE (sizeof (iioptest1_rec2), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(iioptest1_rec2));
    } else {
      _val = (iioptest1_rec2*) _ILU_C_CRCreate (s, sizeof(iioptest1_rec2), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_rec2), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->f1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputByte (_call, &_val->f2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_rec2__Output (ilu_Call _call, iioptest1_rec2* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_iioptest1_rec2__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_iioptest1_rec2__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_rec2), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortInteger (_call, (_val->f1), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputByte(_call, (_val->f2), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _iioptest1_rec2__SizeOf (ilu_Call _call, iioptest1_rec2* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_rec2__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_rec2__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_rec2), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->f1, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfByte(_call, _val->f2, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

iioptest1_rec2 *CORBA_sequence_iioptest1_rec2_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_rec2 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_rec2) * _count;

  if ((_p = (iioptest1_rec2 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_rec2* iioptest1_rec2__alloc ()
{
  return ((iioptest1_rec2*) CORBA_sequence_iioptest1_rec2_allocbuf(1));
}

iioptest1_rec1* _iioptest1_rec1__Input (ilu_Call _call, iioptest1_rec1* _ref, ilu_Error *_err)
{
  iioptest1_rec1* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_rec1__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_rec1__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (iioptest1_rec1*) ilu_MallocE (sizeof (iioptest1_rec1), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(iioptest1_rec1));
    } else {
      _val = (iioptest1_rec1*) _ILU_C_CRCreate (s, sizeof(iioptest1_rec1), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_rec1), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortInteger (_call, &_val->f1, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputInteger (_call, &_val->f2, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortCardinal (_call, &_val->f3, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputCardinal (_call, &_val->f4, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputByte (_call, &_val->f5, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_InputBoolean (_call, &_val->f6, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputShortReal (_call, &_val->f7, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputReal (_call, &_val->f8, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _iioptest1_string__Input (_call, &_val->f9,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_rec1__Output (ilu_Call _call, iioptest1_rec1* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_iioptest1_rec1__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_iioptest1_rec1__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_rec1), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputShortInteger (_call, (_val->f1), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputInteger (_call, (_val->f2), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortCardinal (_call, (_val->f3), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputCardinal (_call, (_val->f4), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputByte(_call, (_val->f5), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ILU_C_OutputBoolean(_call, (_val->f6), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputShortReal(_call, (_val->f7), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputReal(_call, (_val->f8), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _iioptest1_string__Output(_call, (_val->f9), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _iioptest1_rec1__SizeOf (ilu_Call _call, iioptest1_rec1* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_rec1__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_rec1__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_rec1), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortInteger(_call, _val->f1, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfInteger(_call, _val->f2, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortCardinal(_call, _val->f3, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfCardinal(_call, _val->f4, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfByte(_call, _val->f5, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ILU_C_SizeOfBoolean(_call, _val->f6, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfShortReal(_call, _val->f7, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfReal(_call, _val->f8, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _iioptest1_string__SizeOf (_call, _val->f9, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iioptest1_rec1__Free (iioptest1_rec1* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_rec1 */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_iioptest1_rec1__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_rec1__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  iioptest1_string__Free (&_val->f9);
}

iioptest1_rec1 *CORBA_sequence_iioptest1_rec1_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_rec1 *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_rec1) * _count;

  if ((_p = (iioptest1_rec1 *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_rec1* iioptest1_rec1__alloc ()
{
  return ((iioptest1_rec1*) CORBA_sequence_iioptest1_rec1_allocbuf(1));
}

iioptest1_x1_rec* _iioptest1_x1_rec__Input (ilu_Call _call, iioptest1_x1_rec* _ref, ilu_Error *_err)
{
  iioptest1_x1_rec* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_x1_rec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_x1_rec__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (iioptest1_x1_rec*) ilu_MallocE (sizeof (iioptest1_x1_rec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(iioptest1_x1_rec));
    } else {
      _val = (iioptest1_x1_rec*) _ILU_C_CRCreate (s, sizeof(iioptest1_x1_rec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_x1_rec), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputInteger (_call, &_val->case_num, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_x1_rec__Output (ilu_Call _call, iioptest1_x1_rec* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_iioptest1_x1_rec__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_iioptest1_x1_rec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_x1_rec), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputInteger (_call, (_val->case_num), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _iioptest1_x1_rec__SizeOf (ilu_Call _call, iioptest1_x1_rec* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_x1_rec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_x1_rec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_x1_rec), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfInteger(_call, _val->case_num, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

iioptest1_x1_rec *CORBA_sequence_iioptest1_x1_rec_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_x1_rec *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_x1_rec) * _count;

  if ((_p = (iioptest1_x1_rec *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_x1_rec* iioptest1_x1_rec__alloc ()
{
  return ((iioptest1_x1_rec*) CORBA_sequence_iioptest1_x1_rec_allocbuf(1));
}

iioptest1_x2_rec* _iioptest1_x2_rec__Input (ilu_Call _call, iioptest1_x2_rec* _ref, ilu_Error *_err)
{
  iioptest1_x2_rec* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_x2_rec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_x2_rec__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (iioptest1_x2_rec*) ilu_MallocE (sizeof (iioptest1_x2_rec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(iioptest1_x2_rec));
    } else {
      _val = (iioptest1_x2_rec*) _ILU_C_CRCreate (s, sizeof(iioptest1_x2_rec), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_x2_rec), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  *&_val->obj = _ILU_C_InputObject (_call, _iioptest1_obj__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_InputInteger (_call, &_val->case_num, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _iioptest1_x2_rec__Output (ilu_Call _call, iioptest1_x2_rec* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_iioptest1_x2_rec__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_iioptest1_x2_rec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_x2_rec), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ILU_C_OutputObject(_call, (iioptest1_obj) (_val->obj), _iioptest1_obj__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputInteger (_call, (_val->case_num), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _iioptest1_x2_rec__SizeOf (ilu_Call _call, iioptest1_x2_rec* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_iioptest1_x2_rec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_x2_rec__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(iioptest1_x2_rec), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ILU_C_SizeOfObject(_call, (iioptest1_obj) _val->obj, _iioptest1_obj__ILUType, ilu_FALSE, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfInteger(_call, _val->case_num, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void iioptest1_x2_rec__Free (iioptest1_x2_rec* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_x2_rec */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_iioptest1_x2_rec__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_iioptest1_x2_rec__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  iioptest1_obj__Free (&_val->obj);
}

iioptest1_x2_rec *CORBA_sequence_iioptest1_x2_rec_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_x2_rec *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_x2_rec) * _count;

  if ((_p = (iioptest1_x2_rec *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_x2_rec* iioptest1_x2_rec__alloc ()
{
  return ((iioptest1_x2_rec*) CORBA_sequence_iioptest1_x2_rec_allocbuf(1));
}

void iioptest1_obj__Free (iioptest1_obj* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_obj */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

iioptest1_obj *CORBA_sequence_iioptest1_obj_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_obj *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_obj) * _count;

  if ((_p = (iioptest1_obj *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_string* _iioptest1_string__Input (ilu_Call _call, iioptest1_string* _ref, ilu_Error *_err)
{
  iioptest1_string* _val = _ref;

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

void _iioptest1_string__Output (ilu_Call _call, iioptest1_string _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  ilu_OutputEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_string__SizeOf (ilu_Call _call, iioptest1_string _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = ilu_SizeOfEString (_call, (ilu_bytes) _val, _ILU_C_SafeStrlen(_val), 0, ILU_StringEncoding_latin1, ILU_StringEncoding_latin1, _err);
  return size;
}

void iioptest1_string__Free (iioptest1_string* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_string */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  if (*_val != ILU_NIL)
    ilu_free(*_val);
}

iioptest1_string *CORBA_sequence_iioptest1_string_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_string *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_string) * _count;

  if ((_p = (iioptest1_string *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_string* iioptest1_string__alloc ()
{
  return ((iioptest1_string*) CORBA_sequence_iioptest1_string_allocbuf(1));
}

iioptest1_UnicodeString* _iioptest1_UnicodeString__Input (ilu_Call _call, iioptest1_UnicodeString* _ref, ilu_Error *_err)
{
  iioptest1_UnicodeString* _val = _ref;

  ilu_cardinal len = 0;
  if (_ref == ILU_NIL) {
      _val = ilu_MallocE(sizeof(*_val), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      *_val = ILU_NIL;}
  _ILU_C_InputWString (_call, _val, &len, 0, _err);
 marshalError:
  if (ILU_ERROK(*_err)) return _val;
  if ((_val != ILU_NIL) && (_ref == ILU_NIL))
    { ilu_free(_val);
      _val = ILU_NIL;
     };
  return _val;
}

void _iioptest1_UnicodeString__Output (ilu_Call _call, iioptest1_UnicodeString _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  _ILU_C_OutputWString (_call, _val, _ILU_C_SafeWStrlen(_val), 0, _err);
 marshalError:
  return;
}

ilu_cardinal _iioptest1_UnicodeString__SizeOf (ilu_Call _call, iioptest1_UnicodeString _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  size = _ILU_C_SizeOfWString (_call, _val, _ILU_C_SafeWStrlen(_val), 0, _err);
  return size;
}

void iioptest1_UnicodeString__Free (iioptest1_UnicodeString* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a iioptest1_UnicodeString */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  if (*_val != ILU_NIL)
    ilu_free(*_val);
}

iioptest1_UnicodeString *CORBA_sequence_iioptest1_UnicodeString_allocbuf (CORBA_unsigned_long _count)
{
  iioptest1_UnicodeString *_p;
  CORBA_unsigned_long _size = sizeof(iioptest1_UnicodeString) * _count;

  if ((_p = (iioptest1_UnicodeString *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

iioptest1_UnicodeString* iioptest1_UnicodeString__alloc ()
{
  return ((iioptest1_UnicodeString*) CORBA_sequence_iioptest1_UnicodeString_allocbuf(1));
}

void iioptest1_seq1_Every (iioptest1_seq1 *h, void (*f)(iioptest1_rec2*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(iioptest1_rec2), (void *) data);
}

void iioptest1_seq1_Append (iioptest1_seq1 *h, iioptest1_rec2* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(iioptest1_rec2), err);
}

void iioptest1_seq1_Push (iioptest1_seq1 *h, iioptest1_rec2* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(iioptest1_rec2));
}

void iioptest1_seq1_Pop (iioptest1_seq1 *h, iioptest1_rec2* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(iioptest1_rec2));
}

CORBA_unsigned_long iioptest1_seq1_Length (iioptest1_seq1 *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

iioptest1_rec2 * iioptest1_seq1_Nth (iioptest1_seq1 *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

iioptest1_seq1 * iioptest1_seq1_Create (CORBA_unsigned_long sz, iioptest1_rec2* p)
{
  iioptest1_seq1 *s;
  s = (iioptest1_seq1 *) ilu_malloc(sizeof(iioptest1_seq1));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(iioptest1_seq1)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((iioptest1_rec2 *) ilu_malloc(sz * sizeof(iioptest1_rec2))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(iioptest1_rec2));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void iioptest1_seq1_Init (iioptest1_seq1 *s, CORBA_unsigned_long sz, iioptest1_rec2* p)
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
    s->_buffer = (iioptest1_rec2 *) ilu_malloc (sz * sizeof (iioptest1_rec2));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(iioptest1_rec2)); }}
  else
    s->_buffer = p;
  return;
}

void iioptest1_string_Every (iioptest1_string *h, void (*f)(CORBA_char *, void *), void * data)
{
  CORBA_char *p;
  for (p = *h;  *p != 0;  p++) (*f)(p, data);
}

void iioptest1_string_Append (iioptest1_string *h, CORBA_char item, ilu_Error* err)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 1);
}

void iioptest1_string_Push (iioptest1_string *h, CORBA_char item)
{
  _ILU_C_ExtendString (h, item, (CORBA_boolean) 0);
}

void iioptest1_string_Pop (iioptest1_string *h, CORBA_char *item)
{
  _ILU_C_PopString (h, item);
}

CORBA_unsigned_long iioptest1_string_Length (iioptest1_string *h)
{
  if (h == ILU_NIL || *h == ILU_NIL) return 0;
  return (strlen((char *)(*h)));
}

CORBA_char * iioptest1_string_Nth (iioptest1_string *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || *h == ILU_NIL) return ILU_NIL;
  if (n >= strlen((char*)(*h)))
    return ILU_NIL;
else return &((*h)[n]);
}

iioptest1_string iioptest1_string_Create (CORBA_unsigned_long sz, CORBA_char *p)
{
  iioptest1_string s;

  if (p == ILU_NIL)
    {
      s = ilu_malloc(sz * sizeof(CORBA_char));
      if (s == ILU_NIL) {        _ILU_C_MallocFailure(sz * sizeof(CORBA_char));        return ILU_NIL; }
      memset((void *) s, 0, sz * sizeof(CORBA_char));
      return s;
    }
  else
    return p;
}

void iioptest1_string_Init (iioptest1_string *s, CORBA_unsigned_long sz)
{
  return;
}

void iioptest1_UnicodeString_Every (iioptest1_UnicodeString *h, void (*f)(CORBA_wchar *, void *), void * data)
{
  CORBA_wchar *p;
  for (p = *h;  *p != 0;  p++) (*f)(p, data);
}

void iioptest1_UnicodeString_Append (iioptest1_UnicodeString *h, CORBA_wchar item, ilu_Error* err)
{
  _ILU_C_ExtendWString (h, item, (CORBA_boolean) 1);
}

void iioptest1_UnicodeString_Push (iioptest1_UnicodeString *h, CORBA_wchar item)
{
  _ILU_C_ExtendWString (h, item, (CORBA_boolean) 0);
}

void iioptest1_UnicodeString_Pop (iioptest1_UnicodeString *h, CORBA_wchar *item)
{
  _ILU_C_PopWString (h, item);
}

CORBA_unsigned_long iioptest1_UnicodeString_Length (iioptest1_UnicodeString *h)
{
  if (h == ILU_NIL || *h == ILU_NIL) return 0;
  return _ILU_C_SafeWStrlen((CORBA_wchar *)(*h));
}

CORBA_wchar * iioptest1_UnicodeString_Nth (iioptest1_UnicodeString *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || *h == ILU_NIL) return ILU_NIL;
  if (n >= _ILU_C_SafeWStrlen((CORBA_wchar*)(*h)))
    return ILU_NIL;
else return &((*h)[n]);
}

iioptest1_UnicodeString iioptest1_UnicodeString_Create (CORBA_unsigned_long sz, CORBA_wchar *p)
{
  iioptest1_UnicodeString s;

  if (p == ILU_NIL)
    {
      s = ilu_malloc(sz * sizeof(CORBA_wchar));
      if (s == ILU_NIL) {        _ILU_C_MallocFailure(sz * sizeof(CORBA_wchar));        return ILU_NIL; }
      memset((void *) s, 0, sz * sizeof(CORBA_wchar));
      return s;
    }
  else
    return p;
}

void iioptest1_UnicodeString_Init (iioptest1_UnicodeString *s, CORBA_unsigned_long sz)
{
  return;
}

void _iioptest1__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("iioptest1", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _iioptest1__Exception_x1 = ilu_DefineException("iioptest1", "x1", "ilut:gm+G75yVMIfAYUavXJ8FCuTaWrf", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _iioptest1__Exception_x2 = ilu_DefineException("iioptest1", "x2", "ilut:jrPVosIfQH0KKRrEEm4hgSetHs7", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS",
	NULL};
    cl = ilu_DefineObjectType("iioptest1.xilu-obj",	/*name*/
	NULL,	/*no brand*/
	"ilut:mbyJOnx0VN0V5byl6sLU4hGE82-",	/*uid*/
	NULL,	/*singleton*/
	ilu_FALSE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	2,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _iioptest1_xilu_obj__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"test-optional",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:hlK1nloCSblsYHmRgvWX5jx91cp",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:hlK1nloCSblsYHmRgvWX5jx91cp", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:hlK1nloCSblsYHmRgvWX5jx91cp", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:hlK1nloCSblsYHmRgvWX5jx91cp", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"test-asynchronous",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"IDL:Eng.SUN.COM/test1:1.0",
	NULL};
    cl = ilu_DefineObjectType("iioptest1.ext-obj",	/*name*/
	NULL,	/*no brand*/
	"ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	9,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _iioptest1_ext_obj__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"test-obj",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"test-fixed-record",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"test-enumeration",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"test-sequence",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:j+1RscoPGsK8z6gMGEVLgFHM2Uc",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:j+1RscoPGsK8z6gMGEVLgFHM2Uc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:j+1RscoPGsK8z6gMGEVLgFHM2Uc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:j+1RscoPGsK8z6gMGEVLgFHM2Uc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"test-var-record",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:jHYRUYvcjJXfNKFvDAktQANqXz-",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:jHYRUYvcjJXfNKFvDAktQANqXz-", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:jHYRUYvcjJXfNKFvDAktQANqXz-", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:jHYRUYvcjJXfNKFvDAktQANqXz-", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 5,
	"test-var-array",	/*name*/
	6,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:gt-ssb5dxOVCM+NRv7xibbgx15C",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:gt-ssb5dxOVCM+NRv7xibbgx15C", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:gt-ssb5dxOVCM+NRv7xibbgx15C", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:gt-ssb5dxOVCM+NRv7xibbgx15C", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 6,
	"test-fixed-array",	/*name*/
	7,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:m0fj5hi3ZLi6EtOg5endszy8Pqs",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:m0fj5hi3ZLi6EtOg5endszy8Pqs", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:m0fj5hi3ZLi6EtOg5endszy8Pqs", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:m0fj5hi3ZLi6EtOg5endszy8Pqs", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 7,
	"test-var-union",	/*name*/
	8,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:bGOh3+LBS9RFwWiJ1giyNTEhjWh",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:bGOh3+LBS9RFwWiJ1giyNTEhjWh", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:bGOh3+LBS9RFwWiJ1giyNTEhjWh", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:bGOh3+LBS9RFwWiJ1giyNTEhjWh", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 8,
	"test-fixed-union",	/*name*/
	9,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:aRIPnvzDbqQaCcGIjccxZ1IaJSC",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:aRIPnvzDbqQaCcGIjccxZ1IaJSC", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:aRIPnvzDbqQaCcGIjccxZ1IaJSC", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:aRIPnvzDbqQaCcGIjccxZ1IaJSC", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	NULL};
    cl = ilu_DefineObjectType("iioptest1.obj",	/*name*/
	NULL,	/*no brand*/
	"IDL:Eng.SUN.COM/test1:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	18,	/*n methods*/
	0,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _iioptest1_obj__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"test-void",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"test-short",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"test-long",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 3,
	"test-ushort",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 4,
	"test-ulong",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 5,
	"test-float",	/*name*/
	6,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 6,
	"test-double",	/*name*/
	7,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 7,
	"test-boolean",	/*name*/
	8,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 8,
	"test-char",	/*name*/
	9,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 9,
	"test-octet",	/*name*/
	10,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 10,
	"test-string",	/*name*/
	11,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 11,
	"test-longlong",	/*name*/
	12,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:ap0UzrYMjUguZ+wB78TvkND+tOg",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:ap0UzrYMjUguZ+wB78TvkND+tOg", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 12,
	"test-ulonglong",	/*name*/
	13,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:dPuSGnNscKtAsfZwuhl6wY5kZhy", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 13,
	"test-wchar",	/*name*/
	14,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 14,
	"test-wstring",	/*name*/
	15,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:eIVlsdSfEXFq0qWlnmijMWfFvfC",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:eIVlsdSfEXFq0qWlnmijMWfFvfC", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:eIVlsdSfEXFq0qWlnmijMWfFvfC", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:eIVlsdSfEXFq0qWlnmijMWfFvfC", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 15,
	"test-longdouble",	/*name*/
	16,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	"ilut:pya4QLO5jOhGqxQf1Q1kgS9gFmx",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "a1", ilu_FALSE, ilu_In, "ilut:pya4QLO5jOhGqxQf1Q1kgS9gFmx", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "a2", ilu_FALSE, ilu_Out, "ilut:pya4QLO5jOhGqxQf1Q1kgS9gFmx", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "a3", ilu_FALSE, ilu_InOut, "ilut:pya4QLO5jOhGqxQf1Q1kgS9gFmx", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[2];
    exns[0] = ex_iioptest1_x1;
    exns[1] = ex_iioptest1_x2;
    m = ilu_DefineMethod(cl, 16,
	"test-throw",	/*name*/
	17,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	2,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "case-num", ilu_FALSE, ilu_In, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 17,
	"please-exit",	/*name*/
	18,	/*id*/
	0,	/*functional*/
	1,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _iioptest1_xilu_obj__IoFns.kernelType = ilu_RegisterObjectType("xilu-obj", "iioptest1", ILU_NIL, "ilut:mbyJOnx0VN0V5byl6sLU4hGE82-",
    _iioptest1_xilu_obj__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iioptest1_ext_obj__IoFns.kernelType = ilu_RegisterObjectType("ext-obj", "iioptest1", ILU_NIL, "ilut:kY8WdVnykPS4gSrGo-xr1hOJqpS",
    _iioptest1_ext_obj__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iioptest1_opt1__IoFns.kernelType = ilu_RegisterOptionalType("opt1", "iioptest1", ILU_NIL, "ilut:hlK1nloCSblsYHmRgvWX5jx91cp",
    "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM", /* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iioptest1_union2__IoFns.kernelType = type = ilu_RegisterUnionType("union2", "iioptest1", ILU_NIL, "ilut:aRIPnvzDbqQaCcGIjccxZ1IaJSC",
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
      "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", /* arm type */
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
      "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", /* arm type */
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
  _iioptest1_union1__IoFns.kernelType = type = ilu_RegisterUnionType("union1", "iioptest1", ILU_NIL, "ilut:bGOh3+LBS9RFwWiJ1giyNTEhjWh",
    "ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e",	/* UID of discriminant type */
    4,	/* number of arms */
    4,	/* default arm (0 for none) */
    ilu_FALSE,	/* invalid discriminant values allowed? (idiot CORBA) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_ConstantValue_s cv;
    ilu_UnionArm arm;

    arm = ilu_RegisterUnionArm (type, 0, /* which arm */
      "a", /* name of arm */
      "ilut:jHYRUYvcjJXfNKFvDAktQANqXz-", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "a";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 1, /* which arm */
      "b", /* name of arm */
      "ilut:gt-ssb5dxOVCM+NRv7xibbgx15C", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "b";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 2, /* which arm */
      "c", /* name of arm */
      "ilut:j+1RscoPGsK8z6gMGEVLgFHM2Uc", /* arm type */
      1, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    cv.value.enumeration_val = "c";
    cv.kind = ilu_enumeration_cvk;
    ilu_RegisterUnionArmValue (arm, 0, /* which arm value */
      &cv, /* actual value */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    arm = ilu_RegisterUnionArm (type, 3, /* which arm */
      "d", /* name of arm */
      "ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e", /* arm type */
      0, /* number of values that can select this arm */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iioptest1_enum1__IoFns.kernelType = type = ilu_RegisterEnumerationType("enum1", "iioptest1", ILU_NIL, "ilut:g8F0cunsqoy7+5NSI6MZzFHtN6e",
    5,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "a", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "b", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "c", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 3, /* which element */
    "d", /* element name */
    3,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 4, /* which element */
    "e", /* element name */
    4,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iioptest1_seq1__IoFns.kernelType = ilu_RegisterSequenceType("seq1", "iioptest1", ILU_NIL, "ilut:j+1RscoPGsK8z6gMGEVLgFHM2Uc",
    "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  { /* array type "iioptest1_arr4" */
    ilu_cardinal _iioptest1_arr4_dims[] = { 2, 3 };
    _iioptest1_arr4__IoFns.kernelType = ilu_RegisterArrayType("arr4", "iioptest1", ILU_NIL, "ilut:m0fj5hi3ZLi6EtOg5endszy8Pqs",
    "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM", /* base type of array */
    2,		/* number of dimensions */
    _iioptest1_arr4_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  { /* array type "iioptest1_arr3" */
    ilu_cardinal _iioptest1_arr3_dims[] = { 2, 3 };
    _iioptest1_arr3__IoFns.kernelType = ilu_RegisterArrayType("arr3", "iioptest1", ILU_NIL, "ilut:c13Jl5cNbwN2TCMXoOolEcAAuvR",
    "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0", /* base type of array */
    2,		/* number of dimensions */
    _iioptest1_arr3_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  { /* array type "iioptest1_arr2" */
    ilu_cardinal _iioptest1_arr2_dims[] = { 2, 3 };
    _iioptest1_arr2__IoFns.kernelType = ilu_RegisterArrayType("arr2", "iioptest1", ILU_NIL, "ilut:m7779BmSgRHZ-LUq0QBnPQyRXwB",
    "ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv", /* base type of array */
    2,		/* number of dimensions */
    _iioptest1_arr2_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  { /* array type "iioptest1_arr1" */
    ilu_cardinal _iioptest1_arr1_dims[] = { 2, 3 };
    _iioptest1_arr1__IoFns.kernelType = ilu_RegisterArrayType("arr1", "iioptest1", ILU_NIL, "ilut:gt-ssb5dxOVCM+NRv7xibbgx15C",
    "ilut:jHYRUYvcjJXfNKFvDAktQANqXz-", /* base type of array */
    2,		/* number of dimensions */
    _iioptest1_arr1_dims,	/* actual dimensions */
    &newreg, &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  }
  _iioptest1_rec2__IoFns.kernelType = type = ilu_RegisterRecordType("rec2", "iioptest1", ILU_NIL, "ilut:hyl8bU9QeL3LrBiD9li7TDh7DbM",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "f1", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "f2", /* field name */
      "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iioptest1_rec1__IoFns.kernelType = type = ilu_RegisterRecordType("rec1", "iioptest1", ILU_NIL, "ilut:jHYRUYvcjJXfNKFvDAktQANqXz-",
    9,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "f1", /* field name */
      "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "f2", /* field name */
      "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 2, /* which field */
      "f3", /* field name */
      "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 3, /* which field */
      "f4", /* field name */
      "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 4, /* which field */
      "f5", /* field name */
      "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 5, /* which field */
      "f6", /* field name */
      "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 6, /* which field */
      "f7", /* field name */
      "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 7, /* which field */
      "f8", /* field name */
      "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 8, /* which field */
      "f9", /* field name */
      "ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iioptest1_x1_rec__IoFns.kernelType = type = ilu_RegisterRecordType("x1-rec", "iioptest1", ILU_NIL, "ilut:gm+G75yVMIfAYUavXJ8FCuTaWrf",
    1,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "case-num", /* field name */
      "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iioptest1_x2_rec__IoFns.kernelType = type = ilu_RegisterRecordType("x2-rec", "iioptest1", ILU_NIL, "ilut:jrPVosIfQH0KKRrEEm4hgSetHs7",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "obj", /* field name */
      "IDL:Eng.SUN.COM/test1:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "case-num", /* field name */
      "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _iioptest1_obj__IoFns.kernelType = ilu_RegisterObjectType("obj", "iioptest1", ILU_NIL, "IDL:Eng.SUN.COM/test1:1.0",
    _iioptest1_obj__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iioptest1_string__IoFns.kernelType = ilu_RegisterSequenceType("string", "iioptest1", ILU_NIL, "ilut:fcDXGNUSXDiSMyXTxmI+RZvqGBv",
    "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _iioptest1_UnicodeString__IoFns.kernelType = ilu_RegisterSequenceType("UnicodeString", "iioptest1", ILU_NIL, "ilut:eIVlsdSfEXFq0qWlnmijMWfFvfC",
    "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _iioptest1_xilu_obj__IoFns.properties.object_class = _iioptest1_xilu_obj__ILUType;
  _ILU_C_RegisterIoFns (&_iioptest1_xilu_obj__IoFns);

  _iioptest1_ext_obj__IoFns.properties.object_class = _iioptest1_ext_obj__ILUType;
  _ILU_C_RegisterIoFns (&_iioptest1_ext_obj__IoFns);

  _iioptest1_opt1__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_opt1__Input;
  _iioptest1_opt1__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_opt1__Output;
  _iioptest1_opt1__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_opt1__SizeOf;
  _iioptest1_opt1__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_opt1__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_opt1__IoFns);

  _iioptest1_union2__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_union2__Input;
  _iioptest1_union2__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_union2__Output;
  _iioptest1_union2__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_union2__SizeOf;
  _iioptest1_union2__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_iioptest1_union2__IoFns);

  _iioptest1_union1__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_union1__Input;
  _iioptest1_union1__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_union1__Output;
  _iioptest1_union1__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_union1__SizeOf;
  _iioptest1_union1__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_union1__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_union1__IoFns);

  _ILU_C_RegisterIoFns (&_iioptest1_enum1__IoFns);

  _iioptest1_seq1__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_seq1__Input;
  _iioptest1_seq1__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_seq1__Output;
  _iioptest1_seq1__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_seq1__SizeOf;
  _iioptest1_seq1__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_seq1__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_seq1__IoFns);

  _iioptest1_arr4__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_arr4__Input;
  _iioptest1_arr4__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_arr4__Output;
  _iioptest1_arr4__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_arr4__SizeOf;
  _iioptest1_arr4__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_iioptest1_arr4__IoFns);

  _iioptest1_arr3__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_arr3__Input;
  _iioptest1_arr3__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_arr3__Output;
  _iioptest1_arr3__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_arr3__SizeOf;
  _iioptest1_arr3__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_iioptest1_arr3__IoFns);

  _iioptest1_arr2__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_arr2__Input;
  _iioptest1_arr2__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_arr2__Output;
  _iioptest1_arr2__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_arr2__SizeOf;
  _iioptest1_arr2__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_arr2__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_arr2__IoFns);

  _iioptest1_arr1__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_arr1__Input;
  _iioptest1_arr1__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_arr1__Output;
  _iioptest1_arr1__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_arr1__SizeOf;
  _iioptest1_arr1__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_arr1__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_arr1__IoFns);

  _iioptest1_rec2__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_rec2__Input;
  _iioptest1_rec2__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_rec2__Output;
  _iioptest1_rec2__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_rec2__SizeOf;
  _iioptest1_rec2__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_iioptest1_rec2__IoFns);

  _iioptest1_rec1__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_rec1__Input;
  _iioptest1_rec1__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_rec1__Output;
  _iioptest1_rec1__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_rec1__SizeOf;
  _iioptest1_rec1__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_rec1__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_rec1__IoFns);

  _iioptest1_x1_rec__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_x1_rec__Input;
  _iioptest1_x1_rec__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_x1_rec__Output;
  _iioptest1_x1_rec__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_x1_rec__SizeOf;
  _iioptest1_x1_rec__IoFns.freeFn = (ILU_C_FreeFn) 0;
  _ILU_C_RegisterIoFns (&_iioptest1_x1_rec__IoFns);

  _iioptest1_x2_rec__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_x2_rec__Input;
  _iioptest1_x2_rec__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_x2_rec__Output;
  _iioptest1_x2_rec__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_x2_rec__SizeOf;
  _iioptest1_x2_rec__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_x2_rec__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_x2_rec__IoFns);

  _iioptest1_obj__IoFns.properties.object_class = _iioptest1_obj__ILUType;
  _ILU_C_RegisterIoFns (&_iioptest1_obj__IoFns);

  _iioptest1_string__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_string__Input;
  _iioptest1_string__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_string__Output;
  _iioptest1_string__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_string__SizeOf;
  _iioptest1_string__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_string__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_string__IoFns);

  _iioptest1_UnicodeString__IoFns.inputFn = (ILU_C_InputFn) _iioptest1_UnicodeString__Input;
  _iioptest1_UnicodeString__IoFns.outFn = (ILU_C_OutputFn) _iioptest1_UnicodeString__Output;
  _iioptest1_UnicodeString__IoFns.sizeFn = (ILU_C_SizeFn) _iioptest1_UnicodeString__SizeOf;
  _iioptest1_UnicodeString__IoFns.freeFn = (ILU_C_FreeFn) iioptest1_UnicodeString__Free;
  _ILU_C_RegisterIoFns (&_iioptest1_UnicodeString__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

