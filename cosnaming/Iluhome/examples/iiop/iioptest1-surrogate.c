/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:31 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/iiop/iioptest1.isl" of Tue Sep 21 06:54:02 1999,
 * and "D:/Shaun-projects/newstar/Iluhome/Interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "iioptest1.h"

iioptest1_opt1 _iioptest1_xilu_obj_test_optional__clientstub (iioptest1_xilu_obj _handle, iioptest1_opt1 a1, iioptest1_opt1* a2, iioptest1_opt1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_opt1 _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_opt1;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_opt1;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_opt1;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 1;
  __parmsBlock[3].parm_type = TC_iioptest1_opt1;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_xilu_obj__ILUType, &_iioptest1_xilu_obj__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

void _iioptest1_xilu_obj_test_asynchronous__clientstub (iioptest1_xilu_obj _handle, CORBA_long a1, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_long;
  __parmsBlock[0].parm_val  = (void *) &a1;
  _ILU_C_VectorCall (_iioptest1_xilu_obj__ILUType, &_iioptest1_xilu_obj__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

static ILU_C_Class _iioptest1_xilu_obj__SurrogateClass = 0;
iioptest1_xilu_obj iioptest1_xilu_obj__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (iioptest1_xilu_obj) (ILU_C_SBHToObject(sbh, _iioptest1_xilu_obj__ILUType, env));
}

iioptest1_ext_obj _iioptest1_ext_obj_test_obj__clientstub (iioptest1_ext_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_ext_obj _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_ext_obj;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_ext_obj;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_ext_obj;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 1;
  __parmsBlock[3].parm_needs_dereference  = 1;
  __parmsBlock[3].parm_type = TC_iioptest1_ext_obj;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_rec2 _iioptest1_ext_obj_test_fixed_record__clientstub (iioptest1_ext_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_rec2 _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_rec2;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_rec2;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_rec2;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_rec2;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_enum1 _iioptest1_ext_obj_test_enumeration__clientstub (iioptest1_ext_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_enum1 _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_enum1;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_enum1;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_enum1;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_enum1;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_seq1* _iioptest1_ext_obj_test_sequence__clientstub (iioptest1_ext_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_seq1* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_seq1;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_seq1;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_seq1;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_seq1;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_rec1* _iioptest1_ext_obj_test_var_record__clientstub (iioptest1_ext_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_rec1* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_rec1;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_rec1;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_rec1;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_rec1;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_arr1_slice * _iioptest1_ext_obj_test_var_array__clientstub (iioptest1_ext_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_arr1_slice * _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_arr1;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_arr1;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_arr1;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_arr1;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  if (!ILU_C_SUCCESSFUL(_status))
    ilu_free(_retvalue);
  return _retvalue;
}

iioptest1_arr4_slice * _iioptest1_ext_obj_test_fixed_array__clientstub (iioptest1_ext_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_arr4_slice * _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_arr4;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_arr4;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_arr4;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_arr4;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  if (!ILU_C_SUCCESSFUL(_status))
    ilu_free(_retvalue);
  return _retvalue;
}

iioptest1_union1* _iioptest1_ext_obj_test_var_union__clientstub (iioptest1_ext_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_union1* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_union1;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_union1;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_union1;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_union1;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[7],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_union2 _iioptest1_ext_obj_test_fixed_union__clientstub (iioptest1_ext_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_union2 _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_union2;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_union2;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_union2;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_iioptest1_union2;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_ext_obj__ILUType, &_iioptest1_ext_obj__ILUType->cl_methods[8],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _iioptest1_ext_obj__SurrogateClass = 0;
iioptest1_ext_obj iioptest1_ext_obj__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (iioptest1_ext_obj) (ILU_C_SBHToObject(sbh, _iioptest1_ext_obj__ILUType, env));
}

void _iioptest1_obj_test_void__clientstub (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 0, ILU_NIL);
  return;
}

CORBA_short _iioptest1_obj_test_short__clientstub (iioptest1_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_short _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_short;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_short;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_short;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_short;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_long _iioptest1_obj_test_long__clientstub (iioptest1_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_long;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_long;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_long;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_long;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_unsigned_short _iioptest1_obj_test_ushort__clientstub (iioptest1_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_short _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_unsigned_short;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_unsigned_short;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_unsigned_short;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_unsigned_short;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_unsigned_long _iioptest1_obj_test_ulong__clientstub (iioptest1_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_float _iioptest1_obj_test_float__clientstub (iioptest1_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_float _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_float;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_float;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_float;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_float;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_double _iioptest1_obj_test_double__clientstub (iioptest1_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_double _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_double;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_double;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_double;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_double;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _iioptest1_obj_test_boolean__clientstub (iioptest1_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_boolean;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_boolean;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_boolean;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[7],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_char _iioptest1_obj_test_char__clientstub (iioptest1_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_char _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_char;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_char;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_char;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_char;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[8],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_octet _iioptest1_obj_test_octet__clientstub (iioptest1_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_octet _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_octet;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_octet;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_octet;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_octet;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[9],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_string _iioptest1_obj_test_string__clientstub (iioptest1_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_string _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_string;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_string;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_string;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 1;
  __parmsBlock[3].parm_type = TC_iioptest1_string;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[10],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_long_long _iioptest1_obj_test_longlong__clientstub (iioptest1_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long_long _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_long_long;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_long_long;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_long_long;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_long_long;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[11],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_unsigned_long_long _iioptest1_obj_test_ulonglong__clientstub (iioptest1_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long_long _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_unsigned_long_long;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_unsigned_long_long;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_unsigned_long_long;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_unsigned_long_long;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[12],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_wchar _iioptest1_obj_test_wchar__clientstub (iioptest1_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_wchar _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_wchar;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_wchar;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_wchar;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_wchar;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[13],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

iioptest1_UnicodeString _iioptest1_obj_test_wstring__clientstub (iioptest1_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status)
{
  iioptest1_UnicodeString _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_iioptest1_UnicodeString;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_iioptest1_UnicodeString;
  __parmsBlock[1].parm_val  = (void *) a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_iioptest1_UnicodeString;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 1;
  __parmsBlock[3].parm_type = TC_iioptest1_UnicodeString;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[14],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_long_double _iioptest1_obj_test_longdouble__clientstub (iioptest1_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status)
{
  CORBA_long_double _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_long_double;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_long_double;
  __parmsBlock[1].parm_val  = (void *) &a1;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_long_double;
  __parmsBlock[2].parm_val  = (void *) a2;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 1;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_long_double;
  __parmsBlock[3].parm_val  = (void *) a3;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[15],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

void _iioptest1_obj_test_throw__clientstub (iioptest1_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(iioptest1_x1_rec), ILU_NIL, 0, 0, (ILU_C_InputFn) _iioptest1_x1_rec__Input, 0 },
    { sizeof(iioptest1_x2_rec), ILU_NIL, 0, 0, (ILU_C_InputFn) _iioptest1_x2_rec__Input, (ILU_C_FreeFn) iioptest1_x2_rec__Free }};

  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_long;
  __parmsBlock[0].parm_val  = (void *) &case_num;
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[16],
                     _evec, _handle, _status, 1, __parmsBlock);
  return;
}

void _iioptest1_obj_please_exit__clientstub (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_VectorCall (_iioptest1_obj__ILUType, &_iioptest1_obj__ILUType->cl_methods[17],
                     ILU_NIL, _handle, _status, 0, ILU_NIL);
  return;
}

static ILU_C_Class _iioptest1_obj__SurrogateClass = 0;
iioptest1_obj iioptest1_obj__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (iioptest1_obj) (ILU_C_SBHToObject(sbh, _iioptest1_obj__ILUType, env));
}

void iioptest1__Initialize(void)
{
  extern void _iioptest1__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _iioptest1__GeneralInitialization();
  _iioptest1_xilu_obj__SurrogateClass = iioptest1_xilu_obj__MakeClass(
    _iioptest1_xilu_obj_test_optional__clientstub,
    _iioptest1_xilu_obj_test_asynchronous__clientstub,
    _iioptest1_ext_obj_test_obj__clientstub,
    _iioptest1_ext_obj_test_fixed_record__clientstub,
    _iioptest1_ext_obj_test_enumeration__clientstub,
    _iioptest1_ext_obj_test_sequence__clientstub,
    _iioptest1_ext_obj_test_var_record__clientstub,
    _iioptest1_ext_obj_test_var_array__clientstub,
    _iioptest1_ext_obj_test_fixed_array__clientstub,
    _iioptest1_ext_obj_test_var_union__clientstub,
    _iioptest1_ext_obj_test_fixed_union__clientstub,
    _iioptest1_obj_test_void__clientstub,
    _iioptest1_obj_test_short__clientstub,
    _iioptest1_obj_test_long__clientstub,
    _iioptest1_obj_test_ushort__clientstub,
    _iioptest1_obj_test_ulong__clientstub,
    _iioptest1_obj_test_float__clientstub,
    _iioptest1_obj_test_double__clientstub,
    _iioptest1_obj_test_boolean__clientstub,
    _iioptest1_obj_test_char__clientstub,
    _iioptest1_obj_test_octet__clientstub,
    _iioptest1_obj_test_string__clientstub,
    _iioptest1_obj_test_longlong__clientstub,
    _iioptest1_obj_test_ulonglong__clientstub,
    _iioptest1_obj_test_wchar__clientstub,
    _iioptest1_obj_test_wstring__clientstub,
    _iioptest1_obj_test_longdouble__clientstub,
    _iioptest1_obj_test_throw__clientstub,
    _iioptest1_obj_please_exit__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_iioptest1_xilu_obj__ILUType,
	_iioptest1_xilu_obj__SurrogateClass);
  _iioptest1_ext_obj__SurrogateClass = iioptest1_ext_obj__MakeClass(
    _iioptest1_ext_obj_test_obj__clientstub,
    _iioptest1_ext_obj_test_fixed_record__clientstub,
    _iioptest1_ext_obj_test_enumeration__clientstub,
    _iioptest1_ext_obj_test_sequence__clientstub,
    _iioptest1_ext_obj_test_var_record__clientstub,
    _iioptest1_ext_obj_test_var_array__clientstub,
    _iioptest1_ext_obj_test_fixed_array__clientstub,
    _iioptest1_ext_obj_test_var_union__clientstub,
    _iioptest1_ext_obj_test_fixed_union__clientstub,
    _iioptest1_obj_test_void__clientstub,
    _iioptest1_obj_test_short__clientstub,
    _iioptest1_obj_test_long__clientstub,
    _iioptest1_obj_test_ushort__clientstub,
    _iioptest1_obj_test_ulong__clientstub,
    _iioptest1_obj_test_float__clientstub,
    _iioptest1_obj_test_double__clientstub,
    _iioptest1_obj_test_boolean__clientstub,
    _iioptest1_obj_test_char__clientstub,
    _iioptest1_obj_test_octet__clientstub,
    _iioptest1_obj_test_string__clientstub,
    _iioptest1_obj_test_longlong__clientstub,
    _iioptest1_obj_test_ulonglong__clientstub,
    _iioptest1_obj_test_wchar__clientstub,
    _iioptest1_obj_test_wstring__clientstub,
    _iioptest1_obj_test_longdouble__clientstub,
    _iioptest1_obj_test_throw__clientstub,
    _iioptest1_obj_please_exit__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_iioptest1_ext_obj__ILUType,
	_iioptest1_ext_obj__SurrogateClass);
  _iioptest1_obj__SurrogateClass = iioptest1_obj__MakeClass(
    _iioptest1_obj_test_void__clientstub,
    _iioptest1_obj_test_short__clientstub,
    _iioptest1_obj_test_long__clientstub,
    _iioptest1_obj_test_ushort__clientstub,
    _iioptest1_obj_test_ulong__clientstub,
    _iioptest1_obj_test_float__clientstub,
    _iioptest1_obj_test_double__clientstub,
    _iioptest1_obj_test_boolean__clientstub,
    _iioptest1_obj_test_char__clientstub,
    _iioptest1_obj_test_octet__clientstub,
    _iioptest1_obj_test_string__clientstub,
    _iioptest1_obj_test_longlong__clientstub,
    _iioptest1_obj_test_ulonglong__clientstub,
    _iioptest1_obj_test_wchar__clientstub,
    _iioptest1_obj_test_wstring__clientstub,
    _iioptest1_obj_test_longdouble__clientstub,
    _iioptest1_obj_test_throw__clientstub,
    _iioptest1_obj_please_exit__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_iioptest1_obj__ILUType,
	_iioptest1_obj__SurrogateClass);
  return;
}
