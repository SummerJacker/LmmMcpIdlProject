/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Sat Jun 27 12:19:53 2026 by `沈阳市软件定义智能协同重点实验室'
 * running "H:/projects/SAU/Ilu/bin/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "H:/projects/SAU/Ilu/interfaces/CosNaming.idl" of Thu Jun 19 13:16:04 2025,
 * and "H:/projects/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "CosNaming.h"

CORBA_boolean _CosNaming_BindingIterator_next_one__clientstub (CosNaming_BindingIterator _handle, CosNaming_Binding** b, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 0;
  __parmsBlock[1].parm_out = 1;
  __parmsBlock[1].parm_needs_assignment   = 1;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_Binding;
  __parmsBlock[1].parm_val  = (void *) b;
  _ILU_C_VectorCall (_CosNaming_BindingIterator__ILUType, &_CosNaming_BindingIterator__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _CosNaming_BindingIterator_next_n__clientstub (CosNaming_BindingIterator _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
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
  __parmsBlock[1].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[1].parm_val  = (void *) &how_many;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CosNaming_BindingList;
  __parmsBlock[2].parm_val  = (void *) bl;
  _ILU_C_VectorCall (_CosNaming_BindingIterator__ILUType, &_CosNaming_BindingIterator__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

void _CosNaming_BindingIterator_destroy__clientstub (CosNaming_BindingIterator _handle, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_VectorCall (_CosNaming_BindingIterator__ILUType, &_CosNaming_BindingIterator__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 0, ILU_NIL);
  return;
}

static ILU_C_Class _CosNaming_BindingIterator__SurrogateClass = 0;
CosNaming_BindingIterator CosNaming_BindingIterator__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (CosNaming_BindingIterator) (ILU_C_SBHToObject(sbh, _CosNaming_BindingIterator__ILUType, env));
}

CosNaming_NamingContextExt_StringName _CosNaming_NamingContextExt_to_string__clientstub (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContextExt_StringName _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_NamingContextExt_StringName;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_Name;
  __parmsBlock[1].parm_val  = (void *) n;
  _ILU_C_VectorCall (_CosNaming_NamingContextExt__ILUType, &_CosNaming_NamingContextExt__ILUType->cl_methods[0],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CosNaming_Name* _CosNaming_NamingContextExt_to_name__clientstub (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_Name* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_Name;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_NamingContextExt_StringName;
  __parmsBlock[1].parm_val  = (void *) sn;
  _ILU_C_VectorCall (_CosNaming_NamingContextExt__ILUType, &_CosNaming_NamingContextExt__ILUType->cl_methods[1],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CosNaming_NamingContextExt_URLString _CosNaming_NamingContextExt_to_url__clientstub (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_Address addr, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContextExt_URLString _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_NamingContextExt_URLString;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_NamingContextExt_Address;
  __parmsBlock[1].parm_val  = (void *) addr;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CosNaming_NamingContextExt_StringName;
  __parmsBlock[2].parm_val  = (void *) sn;
  _ILU_C_VectorCall (_CosNaming_NamingContextExt__ILUType, &_CosNaming_NamingContextExt__ILUType->cl_methods[2],
                     _evec, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

ilu_CORBA_Object _CosNaming_NamingContextExt_resolve_str__clientstub (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName n, ILU_C_ENVIRONMENT *_status)
{
  ilu_CORBA_Object _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_ilu_CORBA_Object;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_NamingContextExt_StringName;
  __parmsBlock[1].parm_val  = (void *) n;
  _ILU_C_VectorCall (_CosNaming_NamingContextExt__ILUType, &_CosNaming_NamingContextExt__ILUType->cl_methods[3],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _CosNaming_NamingContextExt__SurrogateClass = 0;
CosNaming_NamingContextExt CosNaming_NamingContextExt__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (CosNaming_NamingContextExt) (ILU_C_SBHToObject(sbh, _CosNaming_NamingContextExt__ILUType, env));
}

void _CosNaming_NamingContext_bind__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_Name;
  __parmsBlock[0].parm_val  = (void *) n;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_ilu_CORBA_Object;
  __parmsBlock[1].parm_val  = (void *) obj;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[0],
                     _evec, _handle, _status, 2, __parmsBlock);
  return;
}

void _CosNaming_NamingContext_rebind__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_Name;
  __parmsBlock[0].parm_val  = (void *) n;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_ilu_CORBA_Object;
  __parmsBlock[1].parm_val  = (void *) obj;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[1],
                     _evec, _handle, _status, 2, __parmsBlock);
  return;
}

void _CosNaming_NamingContext_bind_context__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_Name;
  __parmsBlock[0].parm_val  = (void *) n;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_NamingContext;
  __parmsBlock[1].parm_val  = (void *) nc;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[2],
                     _evec, _handle, _status, 2, __parmsBlock);
  return;
}

void _CosNaming_NamingContext_rebind_context__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_Name;
  __parmsBlock[0].parm_val  = (void *) n;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_NamingContext;
  __parmsBlock[1].parm_val  = (void *) nc;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[3],
                     _evec, _handle, _status, 2, __parmsBlock);
  return;
}

ilu_CORBA_Object _CosNaming_NamingContext_resolve__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  ilu_CORBA_Object _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_ilu_CORBA_Object;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_Name;
  __parmsBlock[1].parm_val  = (void *) n;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[4],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

void _CosNaming_NamingContext_unbind__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_Name;
  __parmsBlock[0].parm_val  = (void *) n;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[5],
                     _evec, _handle, _status, 1, __parmsBlock);
  return;
}

CosNaming_NamingContext _CosNaming_NamingContext_new_context__clientstub (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContext _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_NamingContext;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CosNaming_NamingContext _CosNaming_NamingContext_bind_new_context__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContext _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(CosNaming_NamingContext_NotFound), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input, (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free },
    { sizeof(CosNaming_NamingContext_CannotProceed), ILU_NIL, 0, 0, (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input, (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free },
    { 0, ILU_NIL, 0, 0, 0, 0 },
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CosNaming_NamingContext;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_Name;
  __parmsBlock[1].parm_val  = (void *) n;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[7],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

void _CosNaming_NamingContext_destroy__clientstub (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { 0, ILU_NIL, 0, 0, 0, 0 }};

  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[8],
                     _evec, _handle, _status, 0, ILU_NIL);
  return;
}

void _CosNaming_NamingContext_list__clientstub (CosNaming_NamingContext _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, CosNaming_BindingIterator* bi, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[3];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[0].parm_val  = (void *) &how_many;
  __parmsBlock[1].parm_in  = 0;
  __parmsBlock[1].parm_out = 1;
  __parmsBlock[1].parm_needs_assignment   = 1;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CosNaming_BindingList;
  __parmsBlock[1].parm_val  = (void *) bl;
  __parmsBlock[2].parm_in  = 0;
  __parmsBlock[2].parm_out = 1;
  __parmsBlock[2].parm_needs_assignment   = 1;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CosNaming_BindingIterator;
  __parmsBlock[2].parm_val  = (void *) bi;
  _ILU_C_VectorCall (_CosNaming_NamingContext__ILUType, &_CosNaming_NamingContext__ILUType->cl_methods[9],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return;
}

static ILU_C_Class _CosNaming_NamingContext__SurrogateClass = 0;
CosNaming_NamingContext CosNaming_NamingContext__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (CosNaming_NamingContext) (ILU_C_SBHToObject(sbh, _CosNaming_NamingContext__ILUType, env));
}

void CosNaming__Initialize(void)
{
  extern void _CosNaming__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _CosNaming__GeneralInitialization();
  _CosNaming_BindingIterator__SurrogateClass = CosNaming_BindingIterator__MakeClass(
    _CosNaming_BindingIterator_next_one__clientstub,
    _CosNaming_BindingIterator_next_n__clientstub,
    _CosNaming_BindingIterator_destroy__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_CosNaming_BindingIterator__ILUType,
	_CosNaming_BindingIterator__SurrogateClass);
  _CosNaming_NamingContextExt__SurrogateClass = CosNaming_NamingContextExt__MakeClass(
    _CosNaming_NamingContextExt_to_string__clientstub,
    _CosNaming_NamingContextExt_to_name__clientstub,
    _CosNaming_NamingContextExt_to_url__clientstub,
    _CosNaming_NamingContextExt_resolve_str__clientstub,
    _CosNaming_NamingContext_bind__clientstub,
    _CosNaming_NamingContext_rebind__clientstub,
    _CosNaming_NamingContext_bind_context__clientstub,
    _CosNaming_NamingContext_rebind_context__clientstub,
    _CosNaming_NamingContext_resolve__clientstub,
    _CosNaming_NamingContext_unbind__clientstub,
    _CosNaming_NamingContext_new_context__clientstub,
    _CosNaming_NamingContext_bind_new_context__clientstub,
    _CosNaming_NamingContext_destroy__clientstub,
    _CosNaming_NamingContext_list__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_CosNaming_NamingContextExt__ILUType,
	_CosNaming_NamingContextExt__SurrogateClass);
  _CosNaming_NamingContext__SurrogateClass = CosNaming_NamingContext__MakeClass(
    _CosNaming_NamingContext_bind__clientstub,
    _CosNaming_NamingContext_rebind__clientstub,
    _CosNaming_NamingContext_bind_context__clientstub,
    _CosNaming_NamingContext_rebind_context__clientstub,
    _CosNaming_NamingContext_resolve__clientstub,
    _CosNaming_NamingContext_unbind__clientstub,
    _CosNaming_NamingContext_new_context__clientstub,
    _CosNaming_NamingContext_bind_new_context__clientstub,
    _CosNaming_NamingContext_destroy__clientstub,
    _CosNaming_NamingContext_list__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_CosNaming_NamingContext__ILUType,
	_CosNaming_NamingContext__SurrogateClass);
  return;
}
