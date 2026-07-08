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
#include <string.h> /* used for error statements */
#include "CosNaming.h"

ilu_Class _CosNaming_BindingIterator__ILUType = NULL;
ilu_Class _CosNaming_NamingContextExt__ILUType = NULL;
ilu_Class _CosNaming_NamingContext__ILUType = NULL;
struct _ILU_C_IoFnsRegistration_s _CosNaming_BindingIterator__IoFns = { ilu_object_tk, "IDL:omg.org/CosNaming/BindingIterator:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt_URLString__IoFns = { ilu_alias_tk, "IDL:omg.org/CosNaming/NamingContextExt/URLString:1.0", { sizeof(CosNaming_NamingContextExt_URLString) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt_Address__IoFns = { ilu_alias_tk, "IDL:omg.org/CosNaming/NamingContextExt/Address:1.0", { sizeof(CosNaming_NamingContextExt_Address) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt_StringName__IoFns = { ilu_alias_tk, "IDL:omg.org/CosNaming/NamingContextExt/StringName:1.0", { sizeof(CosNaming_NamingContextExt_StringName) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt__IoFns = { ilu_object_tk, "IDL:omg.org/CosNaming/NamingContextExt:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext_CannotProceed__IoFns = { ilu_record_tk, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0", { sizeof(CosNaming_NamingContext_CannotProceed) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext_NotFound__IoFns = { ilu_record_tk, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0", { sizeof(CosNaming_NamingContext_NotFound) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext_NotFoundReason__IoFns = { ilu_enumeration_tk, "IDL:omg.org/CosNaming/NamingContext/NotFoundReason:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext__IoFns = { ilu_object_tk, "IDL:omg.org/CosNaming/NamingContext:1.0", { 0 }, 0, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_BindingList__IoFns = { ilu_sequence_tk, "ilut:lXd+fSOhSZVEB-SPG5EwaEp9XC-", { sizeof(CosNaming_BindingList) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_Binding__IoFns = { ilu_record_tk, "IDL:omg.org/CosNaming/Binding:1.0", { sizeof(CosNaming_Binding) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_BindingType__IoFns = { ilu_enumeration_tk, "IDL:omg.org/CosNaming/BindingType:1.0", { 0 }, ILU_NIL, _ILU_C_Enumeration__SizeOf, _ILU_C_Enumeration__Output, _ILU_C_Enumeration__Input, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_Name__IoFns = { ilu_sequence_tk, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", { sizeof(CosNaming_Name) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_NameComponent__IoFns = { ilu_record_tk, "IDL:omg.org/CosNaming/NameComponent:1.0", { sizeof(CosNaming_NameComponent) }, ILU_NIL, 0, 0, 0, 0 };
struct _ILU_C_IoFnsRegistration_s _CosNaming_Istring__IoFns = { ilu_alias_tk, "IDL:omg.org/CosNaming/Istring:1.0", { sizeof(CosNaming_Istring) }, ILU_NIL, 0, 0, 0, 0 };


ILU_C_Class CosNaming_BindingIterator__MakeClass(
  CORBA_boolean (*CosNaming_BindingIterator_next_one__Impl)
     (CosNaming_BindingIterator _handle, CosNaming_Binding** b, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*CosNaming_BindingIterator_next_n__Impl)
     (CosNaming_BindingIterator _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_BindingIterator_destroy__Impl)
     (CosNaming_BindingIterator _handle, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _CosNaming_BindingIterator__ILUType;
  method_block = ilu_malloc(3 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) CosNaming_BindingIterator_next_one__Impl;
  method_block[1] = (_ILU_C_Method) CosNaming_BindingIterator_next_n__Impl;
  method_block[2] = (_ILU_C_Method) CosNaming_BindingIterator_destroy__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _ilu_CORBA_Object__ILUType;
  ans->ilucc_sections[done++].ilucdts_methods = ILU_NIL;
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
ILU_C_Class CosNaming_NamingContextExt__MakeClass(
  CosNaming_NamingContextExt_StringName (*CosNaming_NamingContextExt_to_string__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status),
  CosNaming_Name* (*CosNaming_NamingContextExt_to_name__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status),
  CosNaming_NamingContextExt_URLString (*CosNaming_NamingContextExt_to_url__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_Address addr, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status),
  ilu_CORBA_Object (*CosNaming_NamingContextExt_resolve_str__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName n, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_bind__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_rebind__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_bind_context__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_rebind_context__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status),
  ilu_CORBA_Object (*CosNaming_NamingContext_resolve__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_unbind__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status),
  CosNaming_NamingContext (*CosNaming_NamingContext_new_context__Impl)
     (CosNaming_NamingContextExt _handle, ILU_C_ENVIRONMENT *_status),
  CosNaming_NamingContext (*CosNaming_NamingContext_bind_new_context__Impl)
     (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_destroy__Impl)
     (CosNaming_NamingContextExt _handle, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_list__Impl)
     (CosNaming_NamingContextExt _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, CosNaming_BindingIterator* bi, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _CosNaming_NamingContextExt__ILUType;
  method_block = ilu_malloc(4 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) CosNaming_NamingContextExt_to_string__Impl;
  method_block[1] = (_ILU_C_Method) CosNaming_NamingContextExt_to_name__Impl;
  method_block[2] = (_ILU_C_Method) CosNaming_NamingContextExt_to_url__Impl;
  method_block[3] = (_ILU_C_Method) CosNaming_NamingContextExt_resolve_str__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _CosNaming_NamingContext__ILUType;
  method_block = ilu_malloc(10 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) CosNaming_NamingContext_bind__Impl;
  method_block[1] = (_ILU_C_Method) CosNaming_NamingContext_rebind__Impl;
  method_block[2] = (_ILU_C_Method) CosNaming_NamingContext_bind_context__Impl;
  method_block[3] = (_ILU_C_Method) CosNaming_NamingContext_rebind_context__Impl;
  method_block[4] = (_ILU_C_Method) CosNaming_NamingContext_resolve__Impl;
  method_block[5] = (_ILU_C_Method) CosNaming_NamingContext_unbind__Impl;
  method_block[6] = (_ILU_C_Method) CosNaming_NamingContext_new_context__Impl;
  method_block[7] = (_ILU_C_Method) CosNaming_NamingContext_bind_new_context__Impl;
  method_block[8] = (_ILU_C_Method) CosNaming_NamingContext_destroy__Impl;
  method_block[9] = (_ILU_C_Method) CosNaming_NamingContext_list__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _ilu_CORBA_Object__ILUType;
  ans->ilucc_sections[done++].ilucdts_methods = ILU_NIL;
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
ILU_C_Class CosNaming_NamingContext__MakeClass(
  void (*CosNaming_NamingContext_bind__Impl)
     (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_rebind__Impl)
     (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_bind_context__Impl)
     (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_rebind_context__Impl)
     (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status),
  ilu_CORBA_Object (*CosNaming_NamingContext_resolve__Impl)
     (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_unbind__Impl)
     (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status),
  CosNaming_NamingContext (*CosNaming_NamingContext_new_context__Impl)
     (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status),
  CosNaming_NamingContext (*CosNaming_NamingContext_bind_new_context__Impl)
     (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_destroy__Impl)
     (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_NamingContext_list__Impl)
     (CosNaming_NamingContext _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, CosNaming_BindingIterator* bi, ILU_C_ENVIRONMENT *_status),
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

  ans->ilucc_sections[done].ilucdts_introType = _CosNaming_NamingContext__ILUType;
  method_block = ilu_malloc(10 * sizeof(_ILU_C_Method));
  if (method_block == ILU_NIL)
    goto fale1;
  ans->ilucc_sections[done++].ilucdts_methods = method_block;
  method_block[0] = (_ILU_C_Method) CosNaming_NamingContext_bind__Impl;
  method_block[1] = (_ILU_C_Method) CosNaming_NamingContext_rebind__Impl;
  method_block[2] = (_ILU_C_Method) CosNaming_NamingContext_bind_context__Impl;
  method_block[3] = (_ILU_C_Method) CosNaming_NamingContext_rebind_context__Impl;
  method_block[4] = (_ILU_C_Method) CosNaming_NamingContext_resolve__Impl;
  method_block[5] = (_ILU_C_Method) CosNaming_NamingContext_unbind__Impl;
  method_block[6] = (_ILU_C_Method) CosNaming_NamingContext_new_context__Impl;
  method_block[7] = (_ILU_C_Method) CosNaming_NamingContext_bind_new_context__Impl;
  method_block[8] = (_ILU_C_Method) CosNaming_NamingContext_destroy__Impl;
  method_block[9] = (_ILU_C_Method) CosNaming_NamingContext_list__Impl;

  ans->ilucc_sections[done].ilucdts_introType = _ilu_CORBA_Object__ILUType;
  ans->ilucc_sections[done++].ilucdts_methods = ILU_NIL;
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
CORBA_boolean CosNaming_BindingIterator_next_one (CosNaming_BindingIterator _handle, CosNaming_Binding** b, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(CosNaming_BindingIterator, CosNaming_Binding**, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(CosNaming_BindingIterator, CosNaming_Binding**, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_BindingIterator__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, b, _status));
}

CORBA_boolean CosNaming_BindingIterator_next_n (CosNaming_BindingIterator _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean (*_f)(CosNaming_BindingIterator, CORBA_unsigned_long, CosNaming_BindingList**, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CORBA_boolean _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CORBA_boolean (*)(CosNaming_BindingIterator, CORBA_unsigned_long, CosNaming_BindingList**, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_BindingIterator__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, how_many, bl, _status));
}

void CosNaming_BindingIterator_destroy (CosNaming_BindingIterator _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_BindingIterator, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_BindingIterator, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_BindingIterator__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

CosNaming_NamingContextExt_StringName CosNaming_NamingContextExt_to_string (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContextExt_StringName (*_f)(CosNaming_NamingContextExt, CosNaming_Name*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CosNaming_NamingContextExt_StringName _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CosNaming_NamingContextExt_StringName (*)(CosNaming_NamingContextExt, CosNaming_Name*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContextExt__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, n, _status));
}

CosNaming_Name* CosNaming_NamingContextExt_to_name (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_Name* (*_f)(CosNaming_NamingContextExt, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CosNaming_Name* _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CosNaming_Name* (*)(CosNaming_NamingContextExt, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContextExt__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, sn, _status));
}

CosNaming_NamingContextExt_URLString CosNaming_NamingContextExt_to_url (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_Address addr, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContextExt_URLString (*_f)(CosNaming_NamingContextExt, CosNaming_NamingContextExt_Address, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CosNaming_NamingContextExt_URLString _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CosNaming_NamingContextExt_URLString (*)(CosNaming_NamingContextExt, CosNaming_NamingContextExt_Address, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContextExt__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, addr, sn, _status));
}

ilu_CORBA_Object CosNaming_NamingContextExt_resolve_str (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName n, ILU_C_ENVIRONMENT *_status)
{
  ilu_CORBA_Object (*_f)(CosNaming_NamingContextExt, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ilu_CORBA_Object _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (ilu_CORBA_Object (*)(CosNaming_NamingContextExt, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContextExt__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, n, _status));
}

void CosNaming_NamingContext_bind (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_NamingContext, CosNaming_Name*, ilu_CORBA_Object, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_NamingContext, CosNaming_Name*, ilu_CORBA_Object, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 0);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, n, obj, _status);
}

void CosNaming_NamingContext_rebind (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_NamingContext, CosNaming_Name*, ilu_CORBA_Object, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_NamingContext, CosNaming_Name*, ilu_CORBA_Object, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 1);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, n, obj, _status);
}

void CosNaming_NamingContext_bind_context (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_NamingContext, CosNaming_Name*, CosNaming_NamingContext, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_NamingContext, CosNaming_Name*, CosNaming_NamingContext, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 2);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, n, nc, _status);
}

void CosNaming_NamingContext_rebind_context (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_NamingContext, CosNaming_Name*, CosNaming_NamingContext, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_NamingContext, CosNaming_Name*, CosNaming_NamingContext, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 3);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, n, nc, _status);
}

ilu_CORBA_Object CosNaming_NamingContext_resolve (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  ilu_CORBA_Object (*_f)(CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ilu_CORBA_Object _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (ilu_CORBA_Object (*)(CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 4);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, n, _status));
}

void CosNaming_NamingContext_unbind (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 5);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, n, _status);
}

CosNaming_NamingContext CosNaming_NamingContext_new_context (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContext (*_f)(CosNaming_NamingContext, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CosNaming_NamingContext _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CosNaming_NamingContext (*)(CosNaming_NamingContext, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 6);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, _status));
}

CosNaming_NamingContext CosNaming_NamingContext_bind_new_context (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status)
{
  CosNaming_NamingContext (*_f)(CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    CosNaming_NamingContext _ret = {0};
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return _ret;
  }
  _f = (CosNaming_NamingContext (*)(CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 7);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  return ((*_f)(_handle, n, _status));
}

void CosNaming_NamingContext_destroy (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_NamingContext, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_NamingContext, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 8);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, _status);
}

void CosNaming_NamingContext_list (CosNaming_NamingContext _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, CosNaming_BindingIterator* bi, ILU_C_ENVIRONMENT *_status)
{
  void (*_f)(CosNaming_NamingContext, CORBA_unsigned_long, CosNaming_BindingList**, CosNaming_BindingIterator*, ILU_C_ENVIRONMENT *);
  if (!_handle) {
    ILU_C_RAISE_SYSTEM(_status, BAD_PARAM, ilu_bpm_nil, NO);
    return;
  }
  _f = (void (*)(CosNaming_NamingContext, CORBA_unsigned_long, CosNaming_BindingList**, CosNaming_BindingIterator*, ILU_C_ENVIRONMENT *)) _ILU_C_FindMethod (_handle, _CosNaming_NamingContext__ILUType, 9);
  _status->_major = ILU_C_NO_EXCEPTION;
  _status->ptr = ILU_NIL;
  _status->freeRoutine = (void(*)(void *)) 0;
  _status->returnCode = (ilu_Exception) 0;
  (*_f)(_handle, how_many, bl, bi, _status);
}

void CosNaming_BindingIterator__SetUserData (CosNaming_BindingIterator self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *CosNaming_BindingIterator__GetUserData (CosNaming_BindingIterator self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void CosNaming_NamingContextExt__SetUserData (CosNaming_NamingContextExt self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *CosNaming_NamingContextExt__GetUserData (CosNaming_NamingContextExt self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

void CosNaming_NamingContext__SetUserData (CosNaming_NamingContext self, void *userData)
{
  ((ILU_C_Object *) self)->instanceData = userData;
}

void *CosNaming_NamingContext__GetUserData (CosNaming_NamingContext self)
{
  return(((ILU_C_Object *) self)->instanceData);
}

ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_NotFound = ILU_NIL;
ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_CannotProceed = ILU_NIL;
ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_InvalidName = ILU_NIL;
ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_AlreadyBound = ILU_NIL;
ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_NotEmpty = ILU_NIL;
ILU_C_ExceptionCode _CosNaming__Exception_NamingContextExt_InvalidAddress = ILU_NIL;
#include <stdarg.h>

void CosNaming__BindExceptionValue (ILU_C_ENVIRONMENT *stat, ilu_Exception exception, ...)
{
  va_list ap;
  va_start (ap, exception);
  stat->_major = ILU_C_USER_EXCEPTION;
  stat->returnCode = exception;
  if (exception == NULL)
    /* no exception */;
  else if (stat->returnCode == ex_CosNaming_NamingContext_NotFound) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (CosNaming_NamingContext_NotFound));
    *(CosNaming_NamingContext_NotFound*)stat->ptr = *va_arg (ap, CosNaming_NamingContext_NotFound*);
    stat->freeRoutine = (void (*) (void *)) CosNaming_NamingContext_NotFound__Free;
  }
  else if (stat->returnCode == ex_CosNaming_NamingContext_CannotProceed) {
    stat->ptr = (void *) ilu_must_malloc (sizeof (CosNaming_NamingContext_CannotProceed));
    *(CosNaming_NamingContext_CannotProceed*)stat->ptr = *va_arg (ap, CosNaming_NamingContext_CannotProceed*);
    stat->freeRoutine = (void (*) (void *)) CosNaming_NamingContext_CannotProceed__Free;
  }
  else if (stat->returnCode == ex_CosNaming_NamingContext_InvalidName) {
    stat->ptr = ILU_NIL;
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_CosNaming_NamingContext_AlreadyBound) {
    stat->ptr = ILU_NIL;
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_CosNaming_NamingContext_NotEmpty) {
    stat->ptr = ILU_NIL;
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else if (stat->returnCode == ex_CosNaming_NamingContextExt_InvalidAddress) {
    stat->ptr = ILU_NIL;
    stat->freeRoutine = ((void (*) (void *)) 0);
  }
  else
    _ilu_Assert(0, "bad exn given to CosNaming__BindExceptionValue");
  va_end (ap);
}

void CosNaming_BindingIterator__Free (CosNaming_BindingIterator* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_BindingIterator */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

CosNaming_BindingIterator *CORBA_sequence_CosNaming_BindingIterator_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_BindingIterator *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_BindingIterator) * _count;

  if ((_p = (CosNaming_BindingIterator *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void CosNaming_NamingContextExt__Free (CosNaming_NamingContextExt* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_NamingContextExt */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

CosNaming_NamingContextExt *CORBA_sequence_CosNaming_NamingContextExt_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_NamingContextExt *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_NamingContextExt) * _count;

  if ((_p = (CosNaming_NamingContextExt *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_NamingContext_CannotProceed* _CosNaming_NamingContext_CannotProceed__Input (ilu_Call _call, CosNaming_NamingContext_CannotProceed* _ref, ilu_Error *_err)
{
  CosNaming_NamingContext_CannotProceed* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_NamingContext_CannotProceed__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_CannotProceed__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (CosNaming_NamingContext_CannotProceed*) ilu_MallocE (sizeof (CosNaming_NamingContext_CannotProceed), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(CosNaming_NamingContext_CannotProceed));
    } else {
      _val = (CosNaming_NamingContext_CannotProceed*) _ILU_C_CRCreate (s, sizeof(CosNaming_NamingContext_CannotProceed), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NamingContext_CannotProceed), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  *&_val->cxt = _ILU_C_InputObject (_call, _CosNaming_NamingContext__ILUType, 0, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _CosNaming_Name__Input (_call, &_val->rest_of_name,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _CosNaming_NamingContext_CannotProceed__Output (ilu_Call _call, CosNaming_NamingContext_CannotProceed* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_CosNaming_NamingContext_CannotProceed__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_CannotProceed__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NamingContext_CannotProceed), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ILU_C_OutputObject(_call, (CosNaming_NamingContext) (_val->cxt), _CosNaming_NamingContext__ILUType, ilu_FALSE, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _CosNaming_Name__Output(_call, (&_val->rest_of_name), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _CosNaming_NamingContext_CannotProceed__SizeOf (ilu_Call _call, CosNaming_NamingContext_CannotProceed* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_NamingContext_CannotProceed__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_CannotProceed__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NamingContext_CannotProceed), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ILU_C_SizeOfObject(_call, (CosNaming_NamingContext) _val->cxt, _CosNaming_NamingContext__ILUType, ilu_FALSE, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _CosNaming_Name__SizeOf (_call, &_val->rest_of_name, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void CosNaming_NamingContext_CannotProceed__Free (CosNaming_NamingContext_CannotProceed* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_NamingContext_CannotProceed */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_CosNaming_NamingContext_CannotProceed__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_CannotProceed__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  CosNaming_NamingContext__Free (&_val->cxt);
  CosNaming_Name__Free (&_val->rest_of_name);
}

CosNaming_NamingContext_CannotProceed *CORBA_sequence_CosNaming_NamingContext_CannotProceed_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_NamingContext_CannotProceed *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_NamingContext_CannotProceed) * _count;

  if ((_p = (CosNaming_NamingContext_CannotProceed *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_NamingContext_CannotProceed* CosNaming_NamingContext_CannotProceed__alloc ()
{
  return ((CosNaming_NamingContext_CannotProceed*) CORBA_sequence_CosNaming_NamingContext_CannotProceed_allocbuf(1));
}

CosNaming_NamingContext_NotFound* _CosNaming_NamingContext_NotFound__Input (ilu_Call _call, CosNaming_NamingContext_NotFound* _ref, ilu_Error *_err)
{
  CosNaming_NamingContext_NotFound* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_NamingContext_NotFound__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_NotFound__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (CosNaming_NamingContext_NotFound*) ilu_MallocE (sizeof (CosNaming_NamingContext_NotFound), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(CosNaming_NamingContext_NotFound));
    } else {
      _val = (CosNaming_NamingContext_NotFound*) _ILU_C_CRCreate (s, sizeof(CosNaming_NamingContext_NotFound), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NamingContext_NotFound), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  {
    ilu_shortcardinal _xxx;
    ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    *&_val->why = (CosNaming_NamingContext_NotFoundReason) _xxx;
  };
  (void) _CosNaming_Name__Input (_call, &_val->rest_of_name,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _CosNaming_NamingContext_NotFound__Output (ilu_Call _call, CosNaming_NamingContext_NotFound* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_CosNaming_NamingContext_NotFound__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_NotFound__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NamingContext_NotFound), _err);
    if (ILU_ERRNOK(*_err)) return;
  ilu_OutputEnum (_call, (ilu_shortcardinal) (_val->why), (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _CosNaming_Name__Output(_call, (&_val->rest_of_name), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _CosNaming_NamingContext_NotFound__SizeOf (ilu_Call _call, CosNaming_NamingContext_NotFound* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_NamingContext_NotFound__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_NotFound__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NamingContext_NotFound), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) _val->why, (ilu_Type)ILU_NIL,  _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _CosNaming_Name__SizeOf (_call, &_val->rest_of_name, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void CosNaming_NamingContext_NotFound__Free (CosNaming_NamingContext_NotFound* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_NamingContext_NotFound */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_CosNaming_NamingContext_NotFound__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NamingContext_NotFound__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  CosNaming_Name__Free (&_val->rest_of_name);
}

CosNaming_NamingContext_NotFound *CORBA_sequence_CosNaming_NamingContext_NotFound_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_NamingContext_NotFound *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_NamingContext_NotFound) * _count;

  if ((_p = (CosNaming_NamingContext_NotFound *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_NamingContext_NotFound* CosNaming_NamingContext_NotFound__alloc ()
{
  return ((CosNaming_NamingContext_NotFound*) CORBA_sequence_CosNaming_NamingContext_NotFound_allocbuf(1));
}

CosNaming_NamingContext_NotFoundReason *CORBA_sequence_CosNaming_NamingContext_NotFoundReason_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_NamingContext_NotFoundReason *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_NamingContext_NotFoundReason) * _count;

  if ((_p = (CosNaming_NamingContext_NotFoundReason *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

void CosNaming_NamingContext__Free (CosNaming_NamingContext* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_NamingContext */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  CORBA_Environment env = {0};
  if ((_val == ILU_NIL) || (*_val == ILU_NIL)) return;
  CORBA_Object_release(*_val, &env);
  *_val = 0;
}

CosNaming_NamingContext *CORBA_sequence_CosNaming_NamingContext_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_NamingContext *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_NamingContext) * _count;

  if ((_p = (CosNaming_NamingContext *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_BindingList* _CosNaming_BindingList__Input (ilu_Call _call, CosNaming_BindingList* _ref, ilu_Error *_err)
{
  CosNaming_BindingList* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  CosNaming_Binding _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (CosNaming_BindingList*) ilu_MallocE(sizeof (CosNaming_BindingList), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  CosNaming_BindingList_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(CosNaming_BindingList), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CosNaming_Binding), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(CosNaming_Binding), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _CosNaming_Binding__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      CosNaming_BindingList_Append (_val, &_tmp, _err);
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

void _CosNaming_BindingList__Output (ilu_Call _call, CosNaming_BindingList* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(CosNaming_BindingList), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CosNaming_Binding), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(CosNaming_Binding), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    CosNaming_Binding *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _CosNaming_Binding__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _CosNaming_BindingList__SizeOf (ilu_Call _call, CosNaming_BindingList* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(CosNaming_BindingList), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CosNaming_Binding), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(CosNaming_Binding), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    CosNaming_Binding *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _CosNaming_Binding__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void CosNaming_BindingList__Free (CosNaming_BindingList* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_BindingList */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CosNaming_Binding)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CosNaming_Binding)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CosNaming_Binding))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          CosNaming_Binding__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK CosNaming_BindingList__Free (CosNaming_BindingList* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

CosNaming_BindingList *CORBA_sequence_CosNaming_BindingList_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_BindingList *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_BindingList) * _count;

  if ((_p = (CosNaming_BindingList *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_BindingList* CosNaming_BindingList__alloc ()
{
  return ((CosNaming_BindingList*) CORBA_sequence_CosNaming_BindingList_allocbuf(1));
}

CosNaming_Binding* _CosNaming_Binding__Input (ilu_Call _call, CosNaming_Binding* _ref, ilu_Error *_err)
{
  CosNaming_Binding* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_Binding__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_Binding__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (CosNaming_Binding*) ilu_MallocE (sizeof (CosNaming_Binding), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(CosNaming_Binding));
    } else {
      _val = (CosNaming_Binding*) _ILU_C_CRCreate (s, sizeof(CosNaming_Binding), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_Binding), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _CosNaming_Name__Input (_call, &_val->binding_name,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  {
    ilu_shortcardinal _xxx;
    ilu_InputEnum (_call, &_xxx, (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    *&_val->binding_type = (CosNaming_BindingType) _xxx;
  };
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

void _CosNaming_Binding__Output (ilu_Call _call, CosNaming_Binding* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_CosNaming_Binding__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_CosNaming_Binding__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_Binding), _err);
    if (ILU_ERRNOK(*_err)) return;
  _CosNaming_Name__Output(_call, (&_val->binding_name), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  ilu_OutputEnum (_call, (ilu_shortcardinal) (_val->binding_type), (ilu_Type)ILU_NIL, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _CosNaming_Binding__SizeOf (ilu_Call _call, CosNaming_Binding* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_Binding__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_Binding__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_Binding), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _CosNaming_Name__SizeOf (_call, &_val->binding_name, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += ilu_SizeOfEnum(_call, (ilu_shortcardinal) _val->binding_type, (ilu_Type)ILU_NIL,  _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void CosNaming_Binding__Free (CosNaming_Binding* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_Binding */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_CosNaming_Binding__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_Binding__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  CosNaming_Name__Free (&_val->binding_name);
}

CosNaming_Binding *CORBA_sequence_CosNaming_Binding_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_Binding *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_Binding) * _count;

  if ((_p = (CosNaming_Binding *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_Binding* CosNaming_Binding__alloc ()
{
  return ((CosNaming_Binding*) CORBA_sequence_CosNaming_Binding_allocbuf(1));
}

CosNaming_BindingType *CORBA_sequence_CosNaming_BindingType_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_BindingType *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_BindingType) * _count;

  if ((_p = (CosNaming_BindingType *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_Name* _CosNaming_Name__Input (ilu_Call _call, CosNaming_Name* _ref, ilu_Error *_err)
{
  CosNaming_Name* _val = _ref;

  ilu_cardinal _count=0, _index=0;
  CosNaming_NameComponent _tmp;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode,size;
  ilu_bytes* nec;
  _ILU_C_AlignmentProc alignproc;
#endif

  if (_ref == ILU_NIL) {
    _val = (CosNaming_Name*) ilu_MallocE(sizeof (CosNaming_Name), _err);
    if (_val == ILU_NIL)  goto marshalError;
  };
  CosNaming_Name_Init(_val, 0, NULL);
  ilu_InputSequence (_call, &_count, 0, ILU_C_KERNEL_TYPE(CosNaming_Name), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call, ILU_C_KERNEL_TYPE(CosNaming_NameComponent), _count, &aligncode, &alignproc, _err);
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
      ilu_InputOpaque (_call, (ilu_bytes *) &_val->_buffer, _count * sizeof(CosNaming_NameComponent), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val->_maximum < _count) _val->_maximum = _count;
      _val->_length = _count;
    } else
#endif
    for (_index = 0;  _index < _count;  _index++) {
      (void) _CosNaming_NameComponent__Input (_call, &_tmp,  _err); if (ILU_ERRNOK(*_err)) goto marshalError;
      if (ILU_ERRNOK(*_err))
         goto marshalError;
      CosNaming_Name_Append (_val, &_tmp, _err);
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

void _CosNaming_Name__Output (ilu_Call _call, CosNaming_Name* _val, ilu_Error *_err)
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
    ilu_OutputSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(CosNaming_Name), _err);
    if (ILU_ERRNOK(*_err)) return;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
    blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CosNaming_NameComponent), _val->_length, &aligncode, &alignproc, _err);
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
      ilu_OutputOpaque (_call, (ilu_bytes) _val->_buffer, _val->_length * sizeof(CosNaming_NameComponent), _err);
      if (ILU_ERRNOK(*_err)) return;
    } else
#endif
    {
    CosNaming_NameComponent *p;  unsigned long i;

      for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
        {
        _CosNaming_NameComponent__Output(_call, p, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
        }
    }
    ilu_EndSequence (_call, _err);
  }
 marshalError:
  return;
}

ilu_cardinal _CosNaming_Name__SizeOf (ilu_Call _call, CosNaming_Name* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  ilu_boolean blockmove = ilu_FALSE;
  ilu_cardinal aligncode;
  _ILU_C_AlignmentProc alignproc;
#endif

  size = ilu_SizeOfSequence (_call, _val->_length, 0, ILU_C_KERNEL_TYPE(CosNaming_Name), _err);
  if (ILU_ERRNOK(*_err)) return 0;
#if defined(ADD_TYPE_REGISTRATION_SUPPORT)
  blockmove = _ILU_C_CanMoveAsBlock (_call,  ILU_C_KERNEL_TYPE(CosNaming_NameComponent), _val->_length, &aligncode, &alignproc, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  if (blockmove) {
    if (alignproc != ((_ILU_C_AlignmentProc)0)) {
      size += (*alignproc) (_call, aligncode, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    };
    size += ilu_SizeOfOpaque (_call, (ilu_bytes) (_val->_buffer), _val->_length * sizeof(CosNaming_NameComponent), _err);
    if (ILU_ERRNOK(*_err)) return 0;
  } else
#endif
  {
    CosNaming_NameComponent *p;  unsigned long i;

    for (p = _val->_buffer, i = 0;  i < _val->_length;  p++, i++)
    {
      size += _CosNaming_NameComponent__SizeOf (_call, &*p, _err);
      if (ILU_ERRNOK(*_err)) return 0;
    }
  }
  ilu_EndSequence (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void CosNaming_Name__Free (CosNaming_Name* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_Name */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  if (_val == ILU_NIL) return;
  /* 更严密的过滤条件使得缺陷对象不被释放，防止野指针导致服务失败  */
  //if (_val->_buffer != ILU_NIL) ilu_DebugPrintf("\n   _length=%lu _maximum=%lu buffer_size=%lu real_size=%lu\n", _val->_length, _val->_maximum, sizeof(_val->_buffer), ((_val->_length) * sizeof(CosNaming_NameComponent)));
  if ((_val->_buffer != ILU_NIL)  && (0 < _val->_length)  &&  
      (_val->_length <= _val->_maximum) && (_val->_maximum <= (_val->_length+5)) /*  &&  
      (sizeof(_val->_buffer) >= (_val->_length  * sizeof(CosNaming_NameComponent)))  &&  
      (sizeof(_val->_buffer) <= (2 * _val->_maximum * sizeof(CosNaming_NameComponent))) */ ) {
    unsigned long i;
    for (i = 0;  i < _val->_length;  i++)
    {
          CosNaming_NameComponent__Free (&_val->_buffer[i]);
    }
    //ilu_DebugPrintf("OK CosNaming_Name__Free (CosNaming_Name* _val=%p)\n", (unsigned long) _val);
    ilu_free(_val->_buffer);
    }
  _val->_length = 0;
  _val->_maximum = 0;
  _val->_buffer = ILU_NIL;
}

CosNaming_Name *CORBA_sequence_CosNaming_Name_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_Name *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_Name) * _count;

  if ((_p = (CosNaming_Name *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_Name* CosNaming_Name__alloc ()
{
  return ((CosNaming_Name*) CORBA_sequence_CosNaming_Name_allocbuf(1));
}

CosNaming_NameComponent* _CosNaming_NameComponent__Input (ilu_Call _call, CosNaming_NameComponent* _ref, ilu_Error *_err)
{
  CosNaming_NameComponent* _val = _ref;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_NameComponent__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NameComponent__IoFns);
  if (_ref == ILU_NIL) {
    if (s == ILU_NIL) {
      _val = (CosNaming_NameComponent*) ilu_MallocE (sizeof (CosNaming_NameComponent), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      memset((void*) _val, 0, sizeof(CosNaming_NameComponent));
    } else {
      _val = (CosNaming_NameComponent*) _ILU_C_CRCreate (s, sizeof(CosNaming_NameComponent), _err);
      if (ILU_ERRNOK(*_err)) goto marshalError;
      if (_val == ILU_NIL) goto marshalError;
    }
  };
  ilu_InputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NameComponent), _err);
  if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->id, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  (void) _ilu_CString__Input (_call, &_val->kind, _err); if (ILU_ERRNOK(*_err)) goto marshalError;
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

void _CosNaming_NameComponent__Output (ilu_Call _call, CosNaming_NameComponent* _val, ilu_Error *_err)
{
  if (_val == NULL) {
    ILU_ERR_CONS1(bad_param, _err, minor, ilu_bpm_nil, 0);
    return;
  };
  {
    _ILU_C_CRInfo s = ILU_NIL;
    if ((_CosNaming_NameComponent__IoFns.properties.value_size & 0x80000000) != 0)
      s = _ILU_C_GetCRInfo(&_CosNaming_NameComponent__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
    ilu_OutputRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NameComponent), _err);
    if (ILU_ERRNOK(*_err)) return;
  _ilu_CString__Output (_call, (_val->id), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
  _ilu_CString__Output (_call, (_val->kind), _err); if (ILU_ERRNOK(*_err)) goto marshalError;
    ilu_EndRecord (_call, _err);
    if (s != ILU_NIL) { _ILU_C_CRPostOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return; };
  }
 marshalError:
  return;
}

ilu_cardinal _CosNaming_NameComponent__SizeOf (ilu_Call _call, CosNaming_NameComponent* _val, ilu_Error *_err)
{
  ilu_cardinal size = 0;

  _ILU_C_CRInfo s = ILU_NIL;
  if ((_CosNaming_NameComponent__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NameComponent__IoFns);
    if (s != ILU_NIL) { _ILU_C_CRPreOutput (s, _val, _err); if (ILU_ERRNOK(*_err)) return 0;}
  size = ilu_SizeOfRecord (_call, ILU_C_KERNEL_TYPE(CosNaming_NameComponent), _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->id, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  size += _ilu_CString__SizeOf(_call, _val->kind, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  ilu_EndRecord (_call, _err);
  if (ILU_ERRNOK(*_err)) return 0;
  return size;
}

void CosNaming_NameComponent__Free (CosNaming_NameComponent* _val)
{
  /* What you put in the freeRoutine member of a CORBA_Environment for an exception parameterized by a CosNaming_NameComponent */
  /* frees allocated storage inside _val (if any), but does not free(_val) */
  _ILU_C_CRInfo s = ILU_NIL;
  if (_val == ILU_NIL) return;
  if ((_CosNaming_NameComponent__IoFns.properties.value_size & 0x80000000) != 0)
    s = _ILU_C_GetCRInfo(&_CosNaming_NameComponent__IoFns);
  if (s != ILU_NIL) _ILU_C_CRFree (s, _val);
  ilu_CString__Free (&_val->id);
  ilu_CString__Free (&_val->kind);
}

CosNaming_NameComponent *CORBA_sequence_CosNaming_NameComponent_allocbuf (CORBA_unsigned_long _count)
{
  CosNaming_NameComponent *_p;
  CORBA_unsigned_long _size = sizeof(CosNaming_NameComponent) * _count;

  if ((_p = (CosNaming_NameComponent *) ilu_malloc(_size)) == ILU_NIL)
    { _ILU_C_MallocFailure(_size); return 0; }
  else
    { memset((void *) _p, 0, _size);  return _p; }
}

CosNaming_NameComponent* CosNaming_NameComponent__alloc ()
{
  return ((CosNaming_NameComponent*) CORBA_sequence_CosNaming_NameComponent_allocbuf(1));
}

void CosNaming_BindingList_Every (CosNaming_BindingList *h, void (*f)(CosNaming_Binding*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CosNaming_Binding), (void *) data);
}

void CosNaming_BindingList_Append (CosNaming_BindingList *h, CosNaming_Binding* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CosNaming_Binding), err);
}

void CosNaming_BindingList_Push (CosNaming_BindingList *h, CosNaming_Binding* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CosNaming_Binding));
}

void CosNaming_BindingList_Pop (CosNaming_BindingList *h, CosNaming_Binding* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CosNaming_Binding));
}

CORBA_unsigned_long CosNaming_BindingList_Length (CosNaming_BindingList *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CosNaming_Binding * CosNaming_BindingList_Nth (CosNaming_BindingList *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

CosNaming_BindingList * CosNaming_BindingList_Create (CORBA_unsigned_long sz, CosNaming_Binding* p)
{
  CosNaming_BindingList *s;
  s = (CosNaming_BindingList *) ilu_malloc(sizeof(CosNaming_BindingList));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(CosNaming_BindingList)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CosNaming_Binding *) ilu_malloc(sz * sizeof(CosNaming_Binding))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CosNaming_Binding));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void CosNaming_BindingList_Init (CosNaming_BindingList *s, CORBA_unsigned_long sz, CosNaming_Binding* p)
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
    s->_buffer = (CosNaming_Binding *) ilu_malloc (sz * sizeof (CosNaming_Binding));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CosNaming_Binding)); }}
  else
    s->_buffer = p;
  return;
}

void CosNaming_Name_Every (CosNaming_Name *h, void (*f)(CosNaming_NameComponent*, void *, ilu_Error *), void * data)
{
  _ILU_C_EveryElement ((ILU_C_Sequence) h, (void (*)(void *, void *, ilu_Error *)) f, sizeof(CosNaming_NameComponent), (void *) data);
}

void CosNaming_Name_Append (CosNaming_Name *h, CosNaming_NameComponent* item, ilu_Error* err)
{
  _ILU_C_AppendGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CosNaming_NameComponent), err);
}

void CosNaming_Name_Push (CosNaming_Name *h, CosNaming_NameComponent* item)
{
  _ILU_C_PushGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CosNaming_NameComponent));
}

void CosNaming_Name_Pop (CosNaming_Name *h, CosNaming_NameComponent* item)
{
  _ILU_C_PopGeneric ((ILU_C_Sequence) h, (char *) item, sizeof(CosNaming_NameComponent));
}

CORBA_unsigned_long CosNaming_Name_Length (CosNaming_Name *h)
{
  if (h == ILU_NIL)
    return 0;
  else return h->_length;
}

CosNaming_NameComponent * CosNaming_Name_Nth (CosNaming_Name *h, CORBA_unsigned_long n)
{
  if (h == ILU_NIL || (n >= h->_length))
    return ILU_NIL;
  else return &(h->_buffer[n]);
}

CosNaming_Name * CosNaming_Name_Create (CORBA_unsigned_long sz, CosNaming_NameComponent* p)
{
  CosNaming_Name *s;
  s = (CosNaming_Name *) ilu_malloc(sizeof(CosNaming_Name));
  if (s == ILU_NIL) { _ILU_C_MallocFailure(sizeof(CosNaming_Name)); return ILU_NIL; };
  s->_maximum = sz;
  s->_length = (sz > 0 && p != ILU_NIL) ? sz : 0;
  s->_buffer = (p != ILU_NIL) ? p : ((sz > 0) ? ((CosNaming_NameComponent *) ilu_malloc(sz * sizeof(CosNaming_NameComponent))) : ILU_NIL);
  if ((s->_buffer == ILU_NIL) && sz > 0 && p == ILU_NIL) {
    _ILU_C_MallocFailure(sz * sizeof(CosNaming_NameComponent));  ilu_free(s);  return ILU_NIL; };
  return s;
}

void CosNaming_Name_Init (CosNaming_Name *s, CORBA_unsigned_long sz, CosNaming_NameComponent* p)
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
    s->_buffer = (CosNaming_NameComponent *) ilu_malloc (sz * sizeof (CosNaming_NameComponent));
    if (s->_buffer == ILU_NIL || s->_buffer == NULL) {
      s->_length = 0;
      s->_maximum = 0;
      _ILU_C_MallocFailure(sz * sizeof(CosNaming_NameComponent)); }}
  else
    s->_buffer = p;
  return;
}

void _CosNaming__GeneralInitialization (void)
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
  _ILU_C_CheckStubConsistency("CosNaming", "2.0beta1", "v2 (2.0beta1)");
  if (!ilu_EnterMutex(otmu, &lerr))
    goto fail2;
  _CosNaming__Exception_NamingContext_NotFound = ilu_DefineException(ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0", "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _CosNaming__Exception_NamingContext_CannotProceed = ilu_DefineException(ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0", "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0", &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _CosNaming__Exception_NamingContext_InvalidName = ilu_DefineException(ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/InvalidName:1.0", ILU_NIL, &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _CosNaming__Exception_NamingContext_AlreadyBound = ilu_DefineException(ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/AlreadyBound:1.0", ILU_NIL, &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _CosNaming__Exception_NamingContext_NotEmpty = ilu_DefineException(ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/NotEmpty:1.0", ILU_NIL, &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  _CosNaming__Exception_NamingContextExt_InvalidAddress = ilu_DefineException(ILU_NIL, "IDL:omg.org/CosNaming/NamingContextExt/InvalidAddress:1.0", ILU_NIL, &lerr);
  if (ILU_ERRNOK(lerr))
    goto fail1;
  { ilu_string supers[] = {
	"IDL:omg.org/CORBA/Object:1.0",
	NULL};
    cl = ilu_DefineObjectType("CosNaming.BindingIterator",	/*name*/
	NULL,	/*no brand*/
	"IDL:omg.org/CosNaming/BindingIterator:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	3,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _CosNaming_BindingIterator__ILUType = cl;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 0,
	"next-one",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "b", ilu_FALSE, ilu_Out, "IDL:omg.org/CosNaming/Binding:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 1,
	"next-n",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "how-many", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "bl", ilu_FALSE, ilu_Out, "ilut:lXd+fSOhSZVEB-SPG5EwaEp9XC-", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 2,
	"destroy",	/*name*/
	3,	/*id*/
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
  { ilu_string supers[] = {
	"IDL:omg.org/CosNaming/NamingContext:1.0",
	NULL};
    cl = ilu_DefineObjectType("CosNaming.NamingContextExt",	/*name*/
	NULL,	/*no brand*/
	"IDL:omg.org/CosNaming/NamingContextExt:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	4,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _CosNaming_NamingContextExt__ILUType = cl;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_CosNaming_NamingContext_InvalidName;
    m = ilu_DefineMethod(cl, 0,
	"to-string",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"IDL:omg.org/CosNaming/NamingContextExt/StringName:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_CosNaming_NamingContext_InvalidName;
    m = ilu_DefineMethod(cl, 1,
	"to-name",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "sn", ilu_FALSE, ilu_In, "IDL:omg.org/CosNaming/NamingContextExt/StringName:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[2];
    exns[0] = ex_CosNaming_NamingContextExt_InvalidAddress;
    exns[1] = ex_CosNaming_NamingContext_InvalidName;
    m = ilu_DefineMethod(cl, 2,
	"to-url",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	2,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	"IDL:omg.org/CosNaming/NamingContextExt/URLString:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "addr", ilu_FALSE, ilu_In, "IDL:omg.org/CosNaming/NamingContextExt/Address:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "sn", ilu_FALSE, ilu_In, "IDL:omg.org/CosNaming/NamingContextExt/StringName:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[4];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    exns[3] = ex_CosNaming_NamingContext_AlreadyBound;
    m = ilu_DefineMethod(cl, 3,
	"resolve-str",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	4,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"IDL:omg.org/CORBA/Object:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "IDL:omg.org/CosNaming/NamingContextExt/StringName:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_string supers[] = {
	"IDL:omg.org/CORBA/Object:1.0",
	NULL};
    cl = ilu_DefineObjectType("CosNaming.NamingContext",	/*name*/
	NULL,	/*no brand*/
	"IDL:omg.org/CosNaming/NamingContext:1.0",	/*uid*/
	NULL,	/*singleton*/
	ilu_TRUE,	/* optional */
	ilu_FALSE,	/* collectible */
	NULL,	/*doc string*/
	10,	/*n methods*/
	1,	/*n supers*/
	supers,	/* supers */
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    _CosNaming_NamingContext__ILUType = cl;
  }
  { ilu_Exception	exns[4];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    exns[3] = ex_CosNaming_NamingContext_AlreadyBound;
    m = ilu_DefineMethod(cl, 0,
	"bind",	/*name*/
	1,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	4,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "obj", ilu_FALSE, ilu_In, "IDL:omg.org/CORBA/Object:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[3];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    m = ilu_DefineMethod(cl, 1,
	"rebind",	/*name*/
	2,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	3,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "obj", ilu_FALSE, ilu_In, "IDL:omg.org/CORBA/Object:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[4];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    exns[3] = ex_CosNaming_NamingContext_AlreadyBound;
    m = ilu_DefineMethod(cl, 2,
	"bind-context",	/*name*/
	3,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	4,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "nc", ilu_FALSE, ilu_In, "IDL:omg.org/CosNaming/NamingContext:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[3];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    m = ilu_DefineMethod(cl, 3,
	"rebind-context",	/*name*/
	4,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	3,	/*n exns*/
	exns,	/*exceptions*/
	2,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "nc", ilu_FALSE, ilu_In, "IDL:omg.org/CosNaming/NamingContext:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[3];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    m = ilu_DefineMethod(cl, 4,
	"resolve",	/*name*/
	5,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	3,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"IDL:omg.org/CORBA/Object:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[3];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    m = ilu_DefineMethod(cl, 5,
	"unbind",	/*name*/
	6,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	3,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 6,
	"new-context",	/*name*/
	7,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	"IDL:omg.org/CosNaming/NamingContext:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[4];
    exns[0] = ex_CosNaming_NamingContext_NotFound;
    exns[1] = ex_CosNaming_NamingContext_CannotProceed;
    exns[2] = ex_CosNaming_NamingContext_InvalidName;
    exns[3] = ex_CosNaming_NamingContext_AlreadyBound;
    m = ilu_DefineMethod(cl, 7,
	"bind-new-context",	/*name*/
	8,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	4,	/*n exns*/
	exns,	/*exceptions*/
	1,	/*n args*/
	"IDL:omg.org/CosNaming/NamingContext:1.0",	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "n", ilu_FALSE, ilu_In, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	exns[1];
    exns[0] = ex_CosNaming_NamingContext_NotEmpty;
    m = ilu_DefineMethod(cl, 8,
	"destroy",	/*name*/
	9,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	1,	/*n exns*/
	exns,	/*exceptions*/
	0,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
  { ilu_Exception	*exns = NULL;
    m = ilu_DefineMethod(cl, 9,
	"list",	/*name*/
	10,	/*id*/
	0,	/*functional*/
	0,	/*asynch*/
	0,	/*n exns*/
	exns,	/*exceptions*/
	3,	/*n args*/
	ILU_NIL,	/*return type ID*/
	&lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 0, "how-many", ilu_FALSE, ilu_In, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 1, "bl", ilu_FALSE, ilu_Out, "ilut:lXd+fSOhSZVEB-SPG5EwaEp9XC-", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
    ilu_DefineMethodArg (m, 2, "bi", ilu_FALSE, ilu_Out, "IDL:omg.org/CosNaming/BindingIterator:1.0", &lerr);
    if (ILU_ERRNOK(lerr))
      goto fail2;
  }
#ifdef ADD_TYPE_REGISTRATION_SUPPORT
{
  ilu_Type type;
  _CosNaming_BindingIterator__IoFns.kernelType = ilu_RegisterObjectType("BindingIterator", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/BindingIterator:1.0",
    _CosNaming_BindingIterator__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("NamingContextExt-URLString", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContextExt/URLString:1.0",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("NamingContextExt-Address", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContextExt/Address:1.0",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  ilu_RegisterAliasType("NamingContextExt-StringName", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContextExt/StringName:1.0",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _CosNaming_NamingContextExt__IoFns.kernelType = ilu_RegisterObjectType("NamingContextExt", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContextExt:1.0",
    _CosNaming_NamingContextExt__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _CosNaming_NamingContext_CannotProceed__IoFns.kernelType = type = ilu_RegisterRecordType("ilu--prefix-idlExceptionType-NamingContext-CannotProceed", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "cxt", /* field name */
      "IDL:omg.org/CosNaming/NamingContext:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "rest-of-name", /* field name */
      "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _CosNaming_NamingContext_NotFound__IoFns.kernelType = type = ilu_RegisterRecordType("ilu--prefix-idlExceptionType-NamingContext-NotFound", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "why", /* field name */
      "IDL:omg.org/CosNaming/NamingContext/NotFoundReason:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "rest-of-name", /* field name */
      "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _CosNaming_NamingContext_NotFoundReason__IoFns.kernelType = type = ilu_RegisterEnumerationType("NamingContext-NotFoundReason", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContext/NotFoundReason:1.0",
    3,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "missing-node", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "not-context", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 2, /* which element */
    "not-object", /* element name */
    2,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _CosNaming_NamingContext__IoFns.kernelType = ilu_RegisterObjectType("NamingContext", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NamingContext:1.0",
    _CosNaming_NamingContext__ILUType, /* object class */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _CosNaming_BindingList__IoFns.kernelType = ilu_RegisterSequenceType("BindingList", "CosNaming", ILU_NIL, "ilut:lXd+fSOhSZVEB-SPG5EwaEp9XC-",
    "IDL:omg.org/CosNaming/Binding:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _CosNaming_Binding__IoFns.kernelType = type = ilu_RegisterRecordType("Binding", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/Binding:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "binding-name", /* field name */
      "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "binding-type", /* field name */
      "IDL:omg.org/CosNaming/BindingType:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _CosNaming_BindingType__IoFns.kernelType = type = ilu_RegisterEnumerationType("BindingType", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/BindingType:1.0",
    2,	/* number of elements in the enum */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterEnumerationElement(type, 0, /* which element */
    "nobject", /* element name */
    0,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterEnumerationElement(type, 1, /* which element */
    "ncontext", /* element name */
    1,	/* integer value for element */
    &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  _CosNaming_Name__IoFns.kernelType = ilu_RegisterSequenceType("Name", "CosNaming", ILU_NIL, "ilut:fI69gQz+JcNvRuTZzJbTk2QqsuN",
    "IDL:omg.org/CosNaming/NameComponent:1.0",	/* base type of sequence */
    0,		/* limit (0 for no limit) */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  _CosNaming_NameComponent__IoFns.kernelType = type = ilu_RegisterRecordType("NameComponent", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/NameComponent:1.0",
    2,	/* number of fields in the record */
    ilu_FALSE,	/* whether or not it is extensible */
    ILU_NIL,	/* supertype, if any */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
  if (newreg) {
    ilu_RegisterRecordField(type, 0, /* which field */
      "id", /* field name */
      "IDL:omg.org/CosNaming/Istring:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
    ilu_RegisterRecordField(type, 1, /* which field */
      "kind", /* field name */
      "IDL:omg.org/CosNaming/Istring:1.0", /* UID of field type */
      &lerr);
    if (ILU_ERRNOK(lerr)) goto fail1;
  };
  ilu_RegisterAliasType("Istring", "CosNaming", ILU_NIL, "IDL:omg.org/CosNaming/Istring:1.0",
    "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv",	/* base type */
    &newreg, &lerr);
  if (ILU_ERRNOK(lerr)) goto fail1;
}
#endif /* def ADD_TYPE_REGISTRATION_SUPPORT */
fail1:
  if (!ilu_ExitMutex(otmu, ilu_TRUE, &lerr))
    goto fail2;
  _CosNaming_BindingIterator__IoFns.properties.object_class = _CosNaming_BindingIterator__ILUType;
  _ILU_C_RegisterIoFns (&_CosNaming_BindingIterator__IoFns);

  _CosNaming_NamingContextExt_URLString__IoFns.inputFn = (ILU_C_InputFn) _ilu_CString__Input;
  _CosNaming_NamingContextExt_URLString__IoFns.outFn = (ILU_C_OutputFn) _ilu_CString__Output;
  _CosNaming_NamingContextExt_URLString__IoFns.sizeFn = (ILU_C_SizeFn) _ilu_CString__SizeOf;
  _CosNaming_NamingContextExt_URLString__IoFns.freeFn = (ILU_C_FreeFn) ilu_CString__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_NamingContextExt_URLString__IoFns);

  _CosNaming_NamingContextExt_Address__IoFns.inputFn = (ILU_C_InputFn) _ilu_CString__Input;
  _CosNaming_NamingContextExt_Address__IoFns.outFn = (ILU_C_OutputFn) _ilu_CString__Output;
  _CosNaming_NamingContextExt_Address__IoFns.sizeFn = (ILU_C_SizeFn) _ilu_CString__SizeOf;
  _CosNaming_NamingContextExt_Address__IoFns.freeFn = (ILU_C_FreeFn) ilu_CString__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_NamingContextExt_Address__IoFns);

  _CosNaming_NamingContextExt_StringName__IoFns.inputFn = (ILU_C_InputFn) _ilu_CString__Input;
  _CosNaming_NamingContextExt_StringName__IoFns.outFn = (ILU_C_OutputFn) _ilu_CString__Output;
  _CosNaming_NamingContextExt_StringName__IoFns.sizeFn = (ILU_C_SizeFn) _ilu_CString__SizeOf;
  _CosNaming_NamingContextExt_StringName__IoFns.freeFn = (ILU_C_FreeFn) ilu_CString__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_NamingContextExt_StringName__IoFns);

  _CosNaming_NamingContextExt__IoFns.properties.object_class = _CosNaming_NamingContextExt__ILUType;
  _ILU_C_RegisterIoFns (&_CosNaming_NamingContextExt__IoFns);

  _CosNaming_NamingContext_CannotProceed__IoFns.inputFn = (ILU_C_InputFn) _CosNaming_NamingContext_CannotProceed__Input;
  _CosNaming_NamingContext_CannotProceed__IoFns.outFn = (ILU_C_OutputFn) _CosNaming_NamingContext_CannotProceed__Output;
  _CosNaming_NamingContext_CannotProceed__IoFns.sizeFn = (ILU_C_SizeFn) _CosNaming_NamingContext_CannotProceed__SizeOf;
  _CosNaming_NamingContext_CannotProceed__IoFns.freeFn = (ILU_C_FreeFn) CosNaming_NamingContext_CannotProceed__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_NamingContext_CannotProceed__IoFns);

  _CosNaming_NamingContext_NotFound__IoFns.inputFn = (ILU_C_InputFn) _CosNaming_NamingContext_NotFound__Input;
  _CosNaming_NamingContext_NotFound__IoFns.outFn = (ILU_C_OutputFn) _CosNaming_NamingContext_NotFound__Output;
  _CosNaming_NamingContext_NotFound__IoFns.sizeFn = (ILU_C_SizeFn) _CosNaming_NamingContext_NotFound__SizeOf;
  _CosNaming_NamingContext_NotFound__IoFns.freeFn = (ILU_C_FreeFn) CosNaming_NamingContext_NotFound__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_NamingContext_NotFound__IoFns);

  _ILU_C_RegisterIoFns (&_CosNaming_NamingContext_NotFoundReason__IoFns);

  _CosNaming_NamingContext__IoFns.properties.object_class = _CosNaming_NamingContext__ILUType;
  _ILU_C_RegisterIoFns (&_CosNaming_NamingContext__IoFns);

  _CosNaming_BindingList__IoFns.inputFn = (ILU_C_InputFn) _CosNaming_BindingList__Input;
  _CosNaming_BindingList__IoFns.outFn = (ILU_C_OutputFn) _CosNaming_BindingList__Output;
  _CosNaming_BindingList__IoFns.sizeFn = (ILU_C_SizeFn) _CosNaming_BindingList__SizeOf;
  _CosNaming_BindingList__IoFns.freeFn = (ILU_C_FreeFn) CosNaming_BindingList__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_BindingList__IoFns);

  _CosNaming_Binding__IoFns.inputFn = (ILU_C_InputFn) _CosNaming_Binding__Input;
  _CosNaming_Binding__IoFns.outFn = (ILU_C_OutputFn) _CosNaming_Binding__Output;
  _CosNaming_Binding__IoFns.sizeFn = (ILU_C_SizeFn) _CosNaming_Binding__SizeOf;
  _CosNaming_Binding__IoFns.freeFn = (ILU_C_FreeFn) CosNaming_Binding__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_Binding__IoFns);

  _ILU_C_RegisterIoFns (&_CosNaming_BindingType__IoFns);

  _CosNaming_Name__IoFns.inputFn = (ILU_C_InputFn) _CosNaming_Name__Input;
  _CosNaming_Name__IoFns.outFn = (ILU_C_OutputFn) _CosNaming_Name__Output;
  _CosNaming_Name__IoFns.sizeFn = (ILU_C_SizeFn) _CosNaming_Name__SizeOf;
  _CosNaming_Name__IoFns.freeFn = (ILU_C_FreeFn) CosNaming_Name__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_Name__IoFns);

  _CosNaming_NameComponent__IoFns.inputFn = (ILU_C_InputFn) _CosNaming_NameComponent__Input;
  _CosNaming_NameComponent__IoFns.outFn = (ILU_C_OutputFn) _CosNaming_NameComponent__Output;
  _CosNaming_NameComponent__IoFns.sizeFn = (ILU_C_SizeFn) _CosNaming_NameComponent__SizeOf;
  _CosNaming_NameComponent__IoFns.freeFn = (ILU_C_FreeFn) CosNaming_NameComponent__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_NameComponent__IoFns);

  _CosNaming_Istring__IoFns.inputFn = (ILU_C_InputFn) _ilu_CString__Input;
  _CosNaming_Istring__IoFns.outFn = (ILU_C_OutputFn) _ilu_CString__Output;
  _CosNaming_Istring__IoFns.sizeFn = (ILU_C_SizeFn) _ilu_CString__SizeOf;
  _CosNaming_Istring__IoFns.freeFn = (ILU_C_FreeFn) ilu_CString__Free;
  _ILU_C_RegisterIoFns (&_CosNaming_Istring__IoFns);

fail2:
  ILU_MUST_BE_SUCCESS(lerr);
}

