/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Mon Aug 18 11:48:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/etc/CosNaming/CosNaming.idl" of Tue Apr 15 16:53:12 2014,
 * and "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/etc/CosNaming/../../stubbers/parser/ilu.isl" of Fri Aug 01 07:58:20 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __CosNaming_h_
#define __CosNaming_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                            CosNaming                             ***/
/************************************************************************/
/************************************************************************/

extern void CosNaming__Initialize(void);
extern void CosNaming__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT CosNaming_BindingIterator;
typedef ILU_C_OBJECT CosNaming_NamingContextExt;
typedef ILU_C_OBJECT CosNaming_NamingContext;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct CosNaming_Binding CosNaming_Binding;
typedef struct _CosNaming_BindingList__sequence CosNaming_BindingList;
typedef ilu_CString CosNaming_NamingContextExt_URLString;
typedef ilu_CString CosNaming_NamingContextExt_Address;
typedef ilu_CString CosNaming_NamingContextExt_StringName;
typedef struct _CosNaming_Name__sequence CosNaming_Name;
typedef struct CosNaming_NamingContext_CannotProceed CosNaming_NamingContext_CannotProceed;
typedef struct CosNaming_NamingContext_NotFound CosNaming_NamingContext_NotFound;
typedef enum {CosNaming_missing_node = 0, CosNaming_not_context = 1, CosNaming_not_object = 2} CosNaming_NamingContext_NotFoundReason;
typedef enum {CosNaming_nobject = 0, CosNaming_ncontext = 1} CosNaming_BindingType;
typedef struct CosNaming_NameComponent CosNaming_NameComponent;
typedef ilu_CString CosNaming_Istring;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* sequence type "CosNaming_Name" */
struct _CosNaming_Name__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CosNaming_NameComponent *_buffer;
};
void CosNaming_Name_Every (CosNaming_Name *h, void (*f)(CosNaming_NameComponent*, void *, ilu_Error *), void *);
void CosNaming_Name_Append (CosNaming_Name *h, CosNaming_NameComponent* item, ilu_Error *);
void CosNaming_Name_Push (CosNaming_Name *h, CosNaming_NameComponent* item);
void CosNaming_Name_Pop (CosNaming_Name *h, CosNaming_NameComponent* item);
CORBA_unsigned_long CosNaming_Name_Length (CosNaming_Name *);
CosNaming_NameComponent * CosNaming_Name_Nth (CosNaming_Name *, CORBA_unsigned_long);
CosNaming_Name * CosNaming_Name_Create (CORBA_unsigned_long /* size */, CosNaming_NameComponent*  /* init val */);
void CosNaming_Name_Init (CosNaming_Name * /* seq */, CORBA_unsigned_long /* size */, CosNaming_NameComponent*  /* init val */);
CosNaming_Name *
  CORBA_sequence_CosNaming_Name_allocbuf (CORBA_unsigned_long /* count */);

CosNaming_BindingType *
  CORBA_sequence_CosNaming_BindingType_allocbuf (CORBA_unsigned_long /* count */);

/* record "CosNaming_Binding" */
struct CosNaming_Binding {
	CosNaming_Name binding_name;
	CosNaming_BindingType binding_type;
};
CosNaming_Binding *
  CORBA_sequence_CosNaming_Binding_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "CosNaming_BindingList" */
struct _CosNaming_BindingList__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CosNaming_Binding *_buffer;
};
void CosNaming_BindingList_Every (CosNaming_BindingList *h, void (*f)(CosNaming_Binding*, void *, ilu_Error *), void *);
void CosNaming_BindingList_Append (CosNaming_BindingList *h, CosNaming_Binding* item, ilu_Error *);
void CosNaming_BindingList_Push (CosNaming_BindingList *h, CosNaming_Binding* item);
void CosNaming_BindingList_Pop (CosNaming_BindingList *h, CosNaming_Binding* item);
CORBA_unsigned_long CosNaming_BindingList_Length (CosNaming_BindingList *);
CosNaming_Binding * CosNaming_BindingList_Nth (CosNaming_BindingList *, CORBA_unsigned_long);
CosNaming_BindingList * CosNaming_BindingList_Create (CORBA_unsigned_long /* size */, CosNaming_Binding*  /* init val */);
void CosNaming_BindingList_Init (CosNaming_BindingList * /* seq */, CORBA_unsigned_long /* size */, CosNaming_Binding*  /* init val */);
CosNaming_BindingList *
  CORBA_sequence_CosNaming_BindingList_allocbuf (CORBA_unsigned_long /* count */);

CosNaming_BindingIterator *
  CORBA_sequence_CosNaming_BindingIterator_allocbuf (CORBA_unsigned_long /* count */);

/* "CosNaming_NamingContextExt_URLString" alias for "ilu_CString" */
#define CosNaming_NamingContextExt_URLString_Length ilu_CString_Length
#define CosNaming_NamingContextExt_URLString_Nth ilu_CString_Nth
#define CosNaming_NamingContextExt_URLString_Every ilu_CString_Every
#define CosNaming_NamingContextExt_URLString_Append ilu_CString_Append
#define CosNaming_NamingContextExt_URLString_Push ilu_CString_Push
#define CosNaming_NamingContextExt_URLString_Pop ilu_CString_Pop
#define CosNaming_NamingContextExt_URLString_Init ilu_CString_Init
#define CosNaming_NamingContextExt_URLString_Create ilu_CString_Create
#define CosNaming_NamingContextExt_URLString__Free ilu_CString__Free
#define CosNaming_NamingContextExt_URLString__alloc ilu_CString__alloc
#define CORBA_sequence_CosNaming_NamingContextExt_URLString_allocbuf CORBA_sequence_string_allocbuf

/* "CosNaming_NamingContextExt_Address" alias for "ilu_CString" */
#define CosNaming_NamingContextExt_Address_Length ilu_CString_Length
#define CosNaming_NamingContextExt_Address_Nth ilu_CString_Nth
#define CosNaming_NamingContextExt_Address_Every ilu_CString_Every
#define CosNaming_NamingContextExt_Address_Append ilu_CString_Append
#define CosNaming_NamingContextExt_Address_Push ilu_CString_Push
#define CosNaming_NamingContextExt_Address_Pop ilu_CString_Pop
#define CosNaming_NamingContextExt_Address_Init ilu_CString_Init
#define CosNaming_NamingContextExt_Address_Create ilu_CString_Create
#define CosNaming_NamingContextExt_Address__Free ilu_CString__Free
#define CosNaming_NamingContextExt_Address__alloc ilu_CString__alloc
#define CORBA_sequence_CosNaming_NamingContextExt_Address_allocbuf CORBA_sequence_string_allocbuf

/* "CosNaming_NamingContextExt_StringName" alias for "ilu_CString" */
#define CosNaming_NamingContextExt_StringName_Length ilu_CString_Length
#define CosNaming_NamingContextExt_StringName_Nth ilu_CString_Nth
#define CosNaming_NamingContextExt_StringName_Every ilu_CString_Every
#define CosNaming_NamingContextExt_StringName_Append ilu_CString_Append
#define CosNaming_NamingContextExt_StringName_Push ilu_CString_Push
#define CosNaming_NamingContextExt_StringName_Pop ilu_CString_Pop
#define CosNaming_NamingContextExt_StringName_Init ilu_CString_Init
#define CosNaming_NamingContextExt_StringName_Create ilu_CString_Create
#define CosNaming_NamingContextExt_StringName__Free ilu_CString__Free
#define CosNaming_NamingContextExt_StringName__alloc ilu_CString__alloc
#define CORBA_sequence_CosNaming_NamingContextExt_StringName_allocbuf CORBA_sequence_string_allocbuf

CosNaming_NamingContext *
  CORBA_sequence_CosNaming_NamingContext_allocbuf (CORBA_unsigned_long /* count */);

CosNaming_NamingContextExt *
  CORBA_sequence_CosNaming_NamingContextExt_allocbuf (CORBA_unsigned_long /* count */);

/* record "CosNaming_NamingContext_CannotProceed" */
struct CosNaming_NamingContext_CannotProceed {
	CosNaming_NamingContext cxt;
	CosNaming_Name rest_of_name;
};
CosNaming_NamingContext_CannotProceed *
  CORBA_sequence_CosNaming_NamingContext_CannotProceed_allocbuf (CORBA_unsigned_long /* count */);

CosNaming_NamingContext_NotFoundReason *
  CORBA_sequence_CosNaming_NamingContext_NotFoundReason_allocbuf (CORBA_unsigned_long /* count */);

/* record "CosNaming_NamingContext_NotFound" */
struct CosNaming_NamingContext_NotFound {
	CosNaming_NamingContext_NotFoundReason why;
	CosNaming_Name rest_of_name;
};
CosNaming_NamingContext_NotFound *
  CORBA_sequence_CosNaming_NamingContext_NotFound_allocbuf (CORBA_unsigned_long /* count */);

/* "CosNaming_Istring" alias for "ilu_CString" */
#define CosNaming_Istring_Length ilu_CString_Length
#define CosNaming_Istring_Nth ilu_CString_Nth
#define CosNaming_Istring_Every ilu_CString_Every
#define CosNaming_Istring_Append ilu_CString_Append
#define CosNaming_Istring_Push ilu_CString_Push
#define CosNaming_Istring_Pop ilu_CString_Pop
#define CosNaming_Istring_Init ilu_CString_Init
#define CosNaming_Istring_Create ilu_CString_Create
#define CosNaming_Istring__Free ilu_CString__Free
#define CosNaming_Istring__alloc ilu_CString__alloc
#define CORBA_sequence_CosNaming_Istring_allocbuf CORBA_sequence_string_allocbuf

/* record "CosNaming_NameComponent" */
struct CosNaming_NameComponent {
	CosNaming_Istring id;
	CosNaming_Istring kind;
};
CosNaming_NameComponent *
  CORBA_sequence_CosNaming_NameComponent_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_NotFound;
#define ex_CosNaming_NamingContext_NotFound _CosNaming__Exception_NamingContext_NotFound
extern ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_CannotProceed;
#define ex_CosNaming_NamingContext_CannotProceed _CosNaming__Exception_NamingContext_CannotProceed
extern ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_InvalidName;
#define ex_CosNaming_NamingContext_InvalidName _CosNaming__Exception_NamingContext_InvalidName
extern ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_AlreadyBound;
#define ex_CosNaming_NamingContext_AlreadyBound _CosNaming__Exception_NamingContext_AlreadyBound
extern ILU_C_ExceptionCode _CosNaming__Exception_NamingContext_NotEmpty;
#define ex_CosNaming_NamingContext_NotEmpty _CosNaming__Exception_NamingContext_NotEmpty
extern ILU_C_ExceptionCode _CosNaming__Exception_NamingContextExt_InvalidAddress;
#define ex_CosNaming_NamingContextExt_InvalidAddress _CosNaming__Exception_NamingContextExt_InvalidAddress


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "CosNaming_BindingIterator"  -----------------------*/

#define CosNaming_BindingIterator__MSType _CosNaming_BindingIterator__ILUType

CosNaming_BindingIterator
  CosNaming_BindingIterator__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  CosNaming_BindingIterator__SetUserData (CosNaming_BindingIterator /* self */, void * /* userData */);
void *
  CosNaming_BindingIterator__GetUserData (CosNaming_BindingIterator /* self */);

extern CosNaming_BindingIterator
  CosNaming_BindingIterator__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default CosNaming_BindingIterator class */

extern CosNaming_BindingIterator
  CosNaming_BindingIterator__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern CORBA_boolean server_CosNaming_BindingIterator_next_one (CosNaming_BindingIterator _handle, CosNaming_Binding** b, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_CosNaming_BindingIterator_next_n (CosNaming_BindingIterator _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_BindingIterator_destroy (CosNaming_BindingIterator _handle, ILU_C_ENVIRONMENT *_status);

extern void CosNaming_BindingIterator__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class CosNaming_BindingIterator__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class CosNaming_BindingIterator__MakeClass(
  CORBA_boolean (*CosNaming_BindingIterator_next_one__Impl)
     (CosNaming_BindingIterator _handle, CosNaming_Binding** b, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*CosNaming_BindingIterator_next_n__Impl)
     (CosNaming_BindingIterator _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, ILU_C_ENVIRONMENT *_status),
  void (*CosNaming_BindingIterator_destroy__Impl)
     (CosNaming_BindingIterator _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern CORBA_boolean
  CosNaming_BindingIterator_next_one (CosNaming_BindingIterator, CosNaming_Binding**, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  CosNaming_BindingIterator_next_n (CosNaming_BindingIterator, CORBA_unsigned_long, CosNaming_BindingList**, ILU_C_ENVIRONMENT *);

extern void
  CosNaming_BindingIterator_destroy (CosNaming_BindingIterator, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "CosNaming_NamingContextExt"  ----------------------*/

#define CosNaming_NamingContextExt__MSType _CosNaming_NamingContextExt__ILUType

CosNaming_NamingContextExt
  CosNaming_NamingContextExt__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  CosNaming_NamingContextExt__SetUserData (CosNaming_NamingContextExt /* self */, void * /* userData */);
void *
  CosNaming_NamingContextExt__GetUserData (CosNaming_NamingContextExt /* self */);

extern CosNaming_NamingContextExt
  CosNaming_NamingContextExt__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default CosNaming_NamingContextExt class */

extern CosNaming_NamingContextExt
  CosNaming_NamingContextExt__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern void server_CosNaming_NamingContextExt_bind (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContextExt_rebind (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContextExt_bind_context (CosNaming_NamingContextExt _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContextExt_rebind_context (CosNaming_NamingContextExt _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status);

extern ilu_CORBA_Object server_CosNaming_NamingContextExt_resolve (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContextExt_unbind (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);

extern CosNaming_NamingContext server_CosNaming_NamingContextExt_new_context (CosNaming_NamingContextExt _handle, ILU_C_ENVIRONMENT *_status);

extern CosNaming_NamingContext server_CosNaming_NamingContextExt_bind_new_context (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContextExt_destroy (CosNaming_NamingContextExt _handle, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContextExt_list (CosNaming_NamingContextExt _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, CosNaming_BindingIterator* bi, ILU_C_ENVIRONMENT *_status);

extern CosNaming_NamingContextExt_StringName server_CosNaming_NamingContextExt_to_string (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);

extern CosNaming_Name* server_CosNaming_NamingContextExt_to_name (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status);

extern CosNaming_NamingContextExt_URLString server_CosNaming_NamingContextExt_to_url (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_Address addr, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status);

extern ilu_CORBA_Object server_CosNaming_NamingContextExt_resolve_str (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName n, ILU_C_ENVIRONMENT *_status);

extern void CosNaming_NamingContextExt__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class CosNaming_NamingContextExt__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class CosNaming_NamingContextExt__MakeClass(
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
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern CosNaming_NamingContextExt_StringName  /* exceptions:  NamingContext-InvalidName */
  CosNaming_NamingContextExt_to_string (CosNaming_NamingContextExt, CosNaming_Name*, ILU_C_ENVIRONMENT *);

extern CosNaming_Name*  /* exceptions:  NamingContext-InvalidName */
  CosNaming_NamingContextExt_to_name (CosNaming_NamingContextExt, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *);

extern CosNaming_NamingContextExt_URLString  /* exceptions:  NamingContextExt-InvalidAddress NamingContext-InvalidName */
  CosNaming_NamingContextExt_to_url (CosNaming_NamingContextExt, CosNaming_NamingContextExt_Address, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *);

extern ilu_CORBA_Object  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName NamingContext-AlreadyBound */
  CosNaming_NamingContextExt_resolve_str (CosNaming_NamingContextExt, CosNaming_NamingContextExt_StringName, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "CosNaming_NamingContext"  -------------------------*/

#define CosNaming_NamingContext__MSType _CosNaming_NamingContext__ILUType

CosNaming_NamingContext
  CosNaming_NamingContext__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  CosNaming_NamingContext__SetUserData (CosNaming_NamingContext /* self */, void * /* userData */);
void *
  CosNaming_NamingContext__GetUserData (CosNaming_NamingContext /* self */);

extern CosNaming_NamingContext
  CosNaming_NamingContext__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default CosNaming_NamingContext class */

extern CosNaming_NamingContext
  CosNaming_NamingContext__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern void server_CosNaming_NamingContext_bind (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContext_rebind (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContext_bind_context (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContext_rebind_context (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status);

extern ilu_CORBA_Object server_CosNaming_NamingContext_resolve (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContext_unbind (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);

extern CosNaming_NamingContext server_CosNaming_NamingContext_new_context (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status);

extern CosNaming_NamingContext server_CosNaming_NamingContext_bind_new_context (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContext_destroy (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status);

extern void server_CosNaming_NamingContext_list (CosNaming_NamingContext _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, CosNaming_BindingIterator* bi, ILU_C_ENVIRONMENT *_status);

extern void CosNaming_NamingContext__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class CosNaming_NamingContext__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class CosNaming_NamingContext__MakeClass(
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
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName NamingContext-AlreadyBound */
  CosNaming_NamingContext_bind (CosNaming_NamingContext, CosNaming_Name*, ilu_CORBA_Object, ILU_C_ENVIRONMENT *);

extern void  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName */
  CosNaming_NamingContext_rebind (CosNaming_NamingContext, CosNaming_Name*, ilu_CORBA_Object, ILU_C_ENVIRONMENT *);

extern void  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName NamingContext-AlreadyBound */
  CosNaming_NamingContext_bind_context (CosNaming_NamingContext, CosNaming_Name*, CosNaming_NamingContext, ILU_C_ENVIRONMENT *);

extern void  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName */
  CosNaming_NamingContext_rebind_context (CosNaming_NamingContext, CosNaming_Name*, CosNaming_NamingContext, ILU_C_ENVIRONMENT *);

extern ilu_CORBA_Object  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName */
  CosNaming_NamingContext_resolve (CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *);

extern void  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName */
  CosNaming_NamingContext_unbind (CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *);

extern CosNaming_NamingContext
  CosNaming_NamingContext_new_context (CosNaming_NamingContext, ILU_C_ENVIRONMENT *);

extern CosNaming_NamingContext  /* exceptions:  NamingContext-NotFound NamingContext-CannotProceed NamingContext-InvalidName NamingContext-AlreadyBound */
  CosNaming_NamingContext_bind_new_context (CosNaming_NamingContext, CosNaming_Name*, ILU_C_ENVIRONMENT *);

extern void  /* exceptions:  NamingContext-NotEmpty */
  CosNaming_NamingContext_destroy (CosNaming_NamingContext, ILU_C_ENVIRONMENT *);

extern void
  CosNaming_NamingContext_list (CosNaming_NamingContext, CORBA_unsigned_long, CosNaming_BindingList**, CosNaming_BindingIterator*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void CosNaming__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _CosNaming_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _CosNaming_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _CosNaming_BindingIterator__IoFns;
#define TC_CosNaming_BindingIterator (& _CosNaming_BindingIterator__IoFns)
extern void CosNaming_BindingIterator__Free (CosNaming_BindingIterator*);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt_URLString__IoFns;
#define TC_CosNaming_NamingContextExt_URLString (& _CosNaming_NamingContextExt_URLString__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt_Address__IoFns;
#define TC_CosNaming_NamingContextExt_Address (& _CosNaming_NamingContextExt_Address__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt_StringName__IoFns;
#define TC_CosNaming_NamingContextExt_StringName (& _CosNaming_NamingContextExt_StringName__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContextExt__IoFns;
#define TC_CosNaming_NamingContextExt (& _CosNaming_NamingContextExt__IoFns)
extern void CosNaming_NamingContextExt__Free (CosNaming_NamingContextExt*);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext_CannotProceed__IoFns;
#define TC_CosNaming_NamingContext_CannotProceed (& _CosNaming_NamingContext_CannotProceed__IoFns)
extern void _CosNaming_NamingContext_CannotProceed__Output (ilu_Call, CosNaming_NamingContext_CannotProceed*, ilu_Error *);
extern ilu_cardinal _CosNaming_NamingContext_CannotProceed__SizeOf (ilu_Call, CosNaming_NamingContext_CannotProceed*, ilu_Error *);
extern CosNaming_NamingContext_CannotProceed* _CosNaming_NamingContext_CannotProceed__Input (ilu_Call, CosNaming_NamingContext_CannotProceed*, ilu_Error *);
extern void CosNaming_NamingContext_CannotProceed__Free (CosNaming_NamingContext_CannotProceed*);
CosNaming_NamingContext_CannotProceed* CosNaming_NamingContext_CannotProceed__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext_NotFound__IoFns;
#define TC_CosNaming_NamingContext_NotFound (& _CosNaming_NamingContext_NotFound__IoFns)
extern void _CosNaming_NamingContext_NotFound__Output (ilu_Call, CosNaming_NamingContext_NotFound*, ilu_Error *);
extern ilu_cardinal _CosNaming_NamingContext_NotFound__SizeOf (ilu_Call, CosNaming_NamingContext_NotFound*, ilu_Error *);
extern CosNaming_NamingContext_NotFound* _CosNaming_NamingContext_NotFound__Input (ilu_Call, CosNaming_NamingContext_NotFound*, ilu_Error *);
extern void CosNaming_NamingContext_NotFound__Free (CosNaming_NamingContext_NotFound*);
CosNaming_NamingContext_NotFound* CosNaming_NamingContext_NotFound__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext_NotFoundReason__IoFns;
#define TC_CosNaming_NamingContext_NotFoundReason (& _CosNaming_NamingContext_NotFoundReason__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NamingContext__IoFns;
#define TC_CosNaming_NamingContext (& _CosNaming_NamingContext__IoFns)
extern void CosNaming_NamingContext__Free (CosNaming_NamingContext*);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_BindingList__IoFns;
#define TC_CosNaming_BindingList (& _CosNaming_BindingList__IoFns)
extern void _CosNaming_BindingList__Output (ilu_Call, CosNaming_BindingList*, ilu_Error *);
extern ilu_cardinal _CosNaming_BindingList__SizeOf (ilu_Call, CosNaming_BindingList*, ilu_Error *);
extern CosNaming_BindingList* _CosNaming_BindingList__Input (ilu_Call, CosNaming_BindingList*, ilu_Error *);
extern void CosNaming_BindingList__Free (CosNaming_BindingList*);
CosNaming_BindingList* CosNaming_BindingList__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_Binding__IoFns;
#define TC_CosNaming_Binding (& _CosNaming_Binding__IoFns)
extern void _CosNaming_Binding__Output (ilu_Call, CosNaming_Binding*, ilu_Error *);
extern ilu_cardinal _CosNaming_Binding__SizeOf (ilu_Call, CosNaming_Binding*, ilu_Error *);
extern CosNaming_Binding* _CosNaming_Binding__Input (ilu_Call, CosNaming_Binding*, ilu_Error *);
extern void CosNaming_Binding__Free (CosNaming_Binding*);
CosNaming_Binding* CosNaming_Binding__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_BindingType__IoFns;
#define TC_CosNaming_BindingType (& _CosNaming_BindingType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_Name__IoFns;
#define TC_CosNaming_Name (& _CosNaming_Name__IoFns)
extern void _CosNaming_Name__Output (ilu_Call, CosNaming_Name*, ilu_Error *);
extern ilu_cardinal _CosNaming_Name__SizeOf (ilu_Call, CosNaming_Name*, ilu_Error *);
extern CosNaming_Name* _CosNaming_Name__Input (ilu_Call, CosNaming_Name*, ilu_Error *);
extern void CosNaming_Name__Free (CosNaming_Name*);
CosNaming_Name* CosNaming_Name__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_NameComponent__IoFns;
#define TC_CosNaming_NameComponent (& _CosNaming_NameComponent__IoFns)
extern void _CosNaming_NameComponent__Output (ilu_Call, CosNaming_NameComponent*, ilu_Error *);
extern ilu_cardinal _CosNaming_NameComponent__SizeOf (ilu_Call, CosNaming_NameComponent*, ilu_Error *);
extern CosNaming_NameComponent* _CosNaming_NameComponent__Input (ilu_Call, CosNaming_NameComponent*, ilu_Error *);
extern void CosNaming_NameComponent__Free (CosNaming_NameComponent*);
CosNaming_NameComponent* CosNaming_NameComponent__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _CosNaming_Istring__IoFns;
#define TC_CosNaming_Istring (& _CosNaming_Istring__IoFns)

extern ilu_Class _CosNaming_BindingIterator__ILUType;
extern CORBA_boolean _CosNaming_BindingIterator_next_one__clientstub (CosNaming_BindingIterator _handle, CosNaming_Binding** b, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _CosNaming_BindingIterator_next_n__clientstub (CosNaming_BindingIterator _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, ILU_C_ENVIRONMENT *_status);
extern void _CosNaming_BindingIterator_destroy__clientstub (CosNaming_BindingIterator _handle, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _CosNaming_NamingContextExt__ILUType;
extern CosNaming_NamingContextExt_StringName _CosNaming_NamingContextExt_to_string__clientstub (CosNaming_NamingContextExt _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);
extern CosNaming_Name* _CosNaming_NamingContextExt_to_name__clientstub (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status);
extern CosNaming_NamingContextExt_URLString _CosNaming_NamingContextExt_to_url__clientstub (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_Address addr, CosNaming_NamingContextExt_StringName sn, ILU_C_ENVIRONMENT *_status);
extern ilu_CORBA_Object _CosNaming_NamingContextExt_resolve_str__clientstub (CosNaming_NamingContextExt _handle, CosNaming_NamingContextExt_StringName n, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _CosNaming_NamingContext__ILUType;
extern void _CosNaming_NamingContext_bind__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status);
extern void _CosNaming_NamingContext_rebind__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ilu_CORBA_Object obj, ILU_C_ENVIRONMENT *_status);
extern void _CosNaming_NamingContext_bind_context__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status);
extern void _CosNaming_NamingContext_rebind_context__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, CosNaming_NamingContext nc, ILU_C_ENVIRONMENT *_status);
extern ilu_CORBA_Object _CosNaming_NamingContext_resolve__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);
extern void _CosNaming_NamingContext_unbind__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);
extern CosNaming_NamingContext _CosNaming_NamingContext_new_context__clientstub (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status);
extern CosNaming_NamingContext _CosNaming_NamingContext_bind_new_context__clientstub (CosNaming_NamingContext _handle, CosNaming_Name* n, ILU_C_ENVIRONMENT *_status);
extern void _CosNaming_NamingContext_destroy__clientstub (CosNaming_NamingContext _handle, ILU_C_ENVIRONMENT *_status);
extern void _CosNaming_NamingContext_list__clientstub (CosNaming_NamingContext _handle, CORBA_unsigned_long how_many, CosNaming_BindingList** bl, CosNaming_BindingIterator* bi, ILU_C_ENVIRONMENT *_status);

extern void _CosNaming__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __CosNaming_h_ */
