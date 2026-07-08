/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:52 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Test1.h"

CORBA_double _Test1_O4_R_to_R__clientstub (Test1_O4 _handle, CORBA_double r, ILU_C_ENVIRONMENT *_status)
{
  CORBA_double _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
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
  __parmsBlock[1].parm_val  = (void *) &r;
  _ILU_C_VectorCall (_Test1_O4__ILUType, &_Test1_O4__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Test1_O4__SurrogateClass = 0;
Test1_O4 Test1_O4__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Test1_O4) (ILU_C_SBHToObject(sbh, _Test1_O4__ILUType, env));
}

Test1_IS* _Test1_P_m2__clientstub (Test1_P _handle, CORBA_long j, ILU_C_ENVIRONMENT *_status)
{
  Test1_IS* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_IS;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_long;
  __parmsBlock[1].parm_val  = (void *) &j;
  _ILU_C_VectorCall (_Test1_P__ILUType, &_Test1_P__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Test1_P__SurrogateClass = 0;
Test1_P Test1_P__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Test1_P) (ILU_C_SBHToObject(sbh, _Test1_P__ILUType, env));
}

Test1_IS* _Test1_O3_RS_R_to_R_IS__clientstub (Test1_O3 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status)
{
  Test1_IS* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_IS;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Test1_RS;
  __parmsBlock[1].parm_val  = (void *) r;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Test1_R;
  __parmsBlock[2].parm_val  = (void *) r2;
  _ILU_C_VectorCall (_Test1_O3__ILUType, &_Test1_O3__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

void _Test1_O3_O1_U_to_U__clientstub (Test1_O3 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CORBA_long), ILU_NIL, 0, 0, (ILU_C_InputFn) ilu_InputInteger, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  if (!_ILU_C_CheckSibling(_handle, o, _status)) goto errout;
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_O1;
  __parmsBlock[0].parm_val  = (void *) o;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 1;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Test1_U;
  __parmsBlock[1].parm_val  = (void *) u;
  _ILU_C_VectorCall (_Test1_O3__ILUType, &_Test1_O3__ILUType->cl_methods[1],
                     _evec, _handle, _status, 2, __parmsBlock);
 errout:
  return;
}

Test1_I _Test1_O3_BS_to_I__clientstub (Test1_O3 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status)
{
  Test1_I _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_I;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Test1_BS;
  __parmsBlock[1].parm_val  = (void *) b;
  _ILU_C_VectorCall (_Test1_O3__ILUType, &_Test1_O3__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Test1_O3__SurrogateClass = 0;
Test1_O3 Test1_O3__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Test1_O3) (ILU_C_SBHToObject(sbh, _Test1_O3__ILUType, env));
}

Test1_U* _Test1_TheO1_U_CSS_to_U__clientstub (Test1_TheO1 _handle, Test1_U* u, Test1_CSS* css, ILU_C_ENVIRONMENT *_status)
{
  Test1_U* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(Test1_TheU), ILU_NIL, 0, 0, (ILU_C_InputFn) _Test1_TheU__Input, (ILU_C_FreeFn) Test1_TheU__Free },
    { sizeof(CORBA_long), ILU_NIL, 0, 0, (ILU_C_InputFn) ilu_InputInteger, 0 }};

  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_U;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Test1_U;
  __parmsBlock[1].parm_val  = (void *) u;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Test1_CSS;
  __parmsBlock[2].parm_val  = (void *) css;
  _ILU_C_VectorCall (_Test1_TheO1__ILUType, &_Test1_TheO1__ILUType->cl_methods[0],
                     _evec, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

Test1_RO _Test1_TheO1_f_CSS_to_RO__clientstub (Test1_TheO1 _handle, Test1_CSS* css, ILU_C_ENVIRONMENT *_status)
{
  Test1_RO _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(Test1_TheU), ILU_NIL, 0, 0, (ILU_C_InputFn) _Test1_TheU__Input, (ILU_C_FreeFn) Test1_TheU__Free }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_RO;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Test1_CSS;
  __parmsBlock[1].parm_val  = (void *) css;
  _ILU_C_VectorCall (_Test1_TheO1__ILUType, &_Test1_TheO1__ILUType->cl_methods[1],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_float _Test1_TheO1_R_ScS_to_F__clientstub (Test1_TheO1 _handle, Test1_R* r, Test1_ScS s, ILU_C_ENVIRONMENT *_status)
{
  CORBA_float _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
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
  __parmsBlock[1].parm_type = TC_Test1_R;
  __parmsBlock[1].parm_val  = (void *) r;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Test1_ScS;
  __parmsBlock[2].parm_val  = (void *) s;
  _ILU_C_VectorCall (_Test1_TheO1__ILUType, &_Test1_TheO1__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

void _Test1_TheO1_a_RO__clientstub (Test1_TheO1 _handle, Test1_RO ro, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_RO;
  __parmsBlock[0].parm_val  = (void *) ro;
  _ILU_C_VectorCall (_Test1_TheO1__ILUType, &_Test1_TheO1__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

Test1_O2 _Test1_TheO1_get_O2__clientstub (Test1_TheO1 _handle, ILU_C_ENVIRONMENT *_status)
{
  Test1_O2 _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_O2;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Test1_TheO1__ILUType, &_Test1_TheO1__ILUType->cl_methods[4],
                     _evec, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Test1_O3 _Test1_TheO1_get_O3__clientstub (Test1_TheO1 _handle, CORBA_boolean subclass, ILU_C_ENVIRONMENT *_status)
{
  Test1_O3 _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_O3;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_boolean;
  __parmsBlock[1].parm_val  = (void *) &subclass;
  _ILU_C_VectorCall (_Test1_TheO1__ILUType, &_Test1_TheO1__ILUType->cl_methods[5],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Test1_TheO1__SurrogateClass = 0;
Test1_TheO1 Test1_TheO1__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Test1_TheO1) (ILU_C_SBHToObject(sbh, _Test1_TheO1__ILUType, env));
}

Test1_CSS* _Test1_O2_OO_A0_to_CSS__clientstub (Test1_O2 _handle, Test1_OO o, Test1_A0 a, ILU_C_ENVIRONMENT *_status)
{
  Test1_CSS* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CORBA_long), ILU_NIL, 0, 0, (ILU_C_InputFn) ilu_InputInteger, 0 }};

  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_CSS;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Test1_OO;
  __parmsBlock[1].parm_val  = (void *) o;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Test1_A0;
  __parmsBlock[2].parm_val  = (void *) a;
  _ILU_C_VectorCall (_Test1_O2__ILUType, &_Test1_O2__ILUType->cl_methods[0],
                     _evec, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

Test1_A0_slice * _Test1_O2_R_I_A1_to_I_A0__clientstub (Test1_O2 _handle, Test1_R* r, Test1_I* i, Test1_A1 a, ILU_C_ENVIRONMENT *_status)
{
  Test1_A0_slice * _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Test1_A0;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Test1_R;
  __parmsBlock[1].parm_val  = (void *) r;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Test1_I;
  __parmsBlock[2].parm_val  = (void *) i;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_Test1_A1;
  __parmsBlock[3].parm_val  = (void *) a;
  _ILU_C_VectorCall (_Test1_O2__ILUType, &_Test1_O2__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  if (!ILU_C_SUCCESSFUL(_status))
    ilu_free(_retvalue);
  return _retvalue;
}

static ILU_C_Class _Test1_O2__SurrogateClass = 0;
Test1_O2 Test1_O2__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Test1_O2) (ILU_C_SBHToObject(sbh, _Test1_O2__ILUType, env));
}

void Test1__Initialize(void)
{
  extern void _Test1__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _Test1__GeneralInitialization();
  _Test1_O4__SurrogateClass = Test1_O4__MakeClass(
    _Test1_O4_R_to_R__clientstub,
    _Test1_O3_RS_R_to_R_IS__clientstub,
    _Test1_O3_O1_U_to_U__clientstub,
    _Test1_O3_BS_to_I__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Test1_O4__ILUType,
	_Test1_O4__SurrogateClass);
  _Test1_P__SurrogateClass = Test1_P__MakeClass(
    _Test1_P_m2__clientstub,
    _Test1_O3_RS_R_to_R_IS__clientstub,
    _Test1_O3_O1_U_to_U__clientstub,
    _Test1_O3_BS_to_I__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Test1_P__ILUType,
	_Test1_P__SurrogateClass);
  _Test1_O3__SurrogateClass = Test1_O3__MakeClass(
    _Test1_O3_RS_R_to_R_IS__clientstub,
    _Test1_O3_O1_U_to_U__clientstub,
    _Test1_O3_BS_to_I__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Test1_O3__ILUType,
	_Test1_O3__SurrogateClass);
  _Test1_TheO1__SurrogateClass = Test1_TheO1__MakeClass(
    _Test1_TheO1_U_CSS_to_U__clientstub,
    _Test1_TheO1_f_CSS_to_RO__clientstub,
    _Test1_TheO1_R_ScS_to_F__clientstub,
    _Test1_TheO1_a_RO__clientstub,
    _Test1_TheO1_get_O2__clientstub,
    _Test1_TheO1_get_O3__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Test1_TheO1__ILUType,
	_Test1_TheO1__SurrogateClass);
  _Test1_O2__SurrogateClass = Test1_O2__MakeClass(
    _Test1_O2_OO_A0_to_CSS__clientstub,
    _Test1_O2_R_I_A1_to_I_A0__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Test1_O2__ILUType,
	_Test1_O2__SurrogateClass);
  return;
}
