/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgProperty.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __NgProperty_h_
#define __NgProperty_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "NgBasic.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                            NgProperty                            ***/
/************************************************************************/
/************************************************************************/

extern void NgProperty__Initialize(void);
extern void NgProperty__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT NgProperty_PutablePropertySet;
typedef ILU_C_OBJECT NgProperty_PropertySet;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _NgProperty_PropertySequence__sequence NgProperty_PropertySequence;
typedef NgBasic_NameSequence NgProperty_PropertyNames;
typedef struct _NgProperty_PropertyModificationSequence__sequence NgProperty_PropertyModificationSequence;
typedef struct NgProperty_PropertyModification NgProperty_PropertyModification;
typedef enum {NgProperty_Add = 0, NgProperty_Remove = 1, NgProperty_Change = 2} NgProperty_PropertyModificationKind;
typedef NgBasic_NameValuePair NgProperty_Property;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* sequence type "NgProperty_PropertySequence" */
struct _NgProperty_PropertySequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgProperty_Property *_buffer;
};
void NgProperty_PropertySequence_Every (NgProperty_PropertySequence *h, void (*f)(NgProperty_Property*, void *, ilu_Error *), void *);
void NgProperty_PropertySequence_Append (NgProperty_PropertySequence *h, NgProperty_Property* item, ilu_Error *);
void NgProperty_PropertySequence_Push (NgProperty_PropertySequence *h, NgProperty_Property* item);
void NgProperty_PropertySequence_Pop (NgProperty_PropertySequence *h, NgProperty_Property* item);
CORBA_unsigned_long NgProperty_PropertySequence_Length (NgProperty_PropertySequence *);
NgProperty_Property * NgProperty_PropertySequence_Nth (NgProperty_PropertySequence *, CORBA_unsigned_long);
NgProperty_PropertySequence * NgProperty_PropertySequence_Create (CORBA_unsigned_long /* size */, NgProperty_Property*  /* init val */);
void NgProperty_PropertySequence_Init (NgProperty_PropertySequence * /* seq */, CORBA_unsigned_long /* size */, NgProperty_Property*  /* init val */);
NgProperty_PropertySequence *
  CORBA_sequence_NgProperty_PropertySequence_allocbuf (CORBA_unsigned_long /* count */);

/* "NgProperty_PropertyNames" alias for "NgBasic_NameSequence" */
#define NgProperty_PropertyNames_Length NgBasic_NameSequence_Length
#define NgProperty_PropertyNames_Nth NgBasic_NameSequence_Nth
#define NgProperty_PropertyNames_Every NgBasic_NameSequence_Every
#define NgProperty_PropertyNames_Append NgBasic_NameSequence_Append
#define NgProperty_PropertyNames_Push NgBasic_NameSequence_Push
#define NgProperty_PropertyNames_Pop NgBasic_NameSequence_Pop
#define NgProperty_PropertyNames_Init NgBasic_NameSequence_Init
#define NgProperty_PropertyNames_Create NgBasic_NameSequence_Create
#define NgProperty_PropertyNames__Free NgBasic_NameSequence__Free
#define NgProperty_PropertyNames__alloc NgBasic_NameSequence__alloc
#define CORBA_sequence_NgProperty_PropertyNames_allocbuf CORBA_sequence_NgBasic_NameSequence_allocbuf

NgProperty_PropertySet *
  CORBA_sequence_NgProperty_PropertySet_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "NgProperty_PropertyModificationSequence" */
struct _NgProperty_PropertyModificationSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgProperty_PropertyModification *_buffer;
};
void NgProperty_PropertyModificationSequence_Every (NgProperty_PropertyModificationSequence *h, void (*f)(NgProperty_PropertyModification*, void *, ilu_Error *), void *);
void NgProperty_PropertyModificationSequence_Append (NgProperty_PropertyModificationSequence *h, NgProperty_PropertyModification* item, ilu_Error *);
void NgProperty_PropertyModificationSequence_Push (NgProperty_PropertyModificationSequence *h, NgProperty_PropertyModification* item);
void NgProperty_PropertyModificationSequence_Pop (NgProperty_PropertyModificationSequence *h, NgProperty_PropertyModification* item);
CORBA_unsigned_long NgProperty_PropertyModificationSequence_Length (NgProperty_PropertyModificationSequence *);
NgProperty_PropertyModification * NgProperty_PropertyModificationSequence_Nth (NgProperty_PropertyModificationSequence *, CORBA_unsigned_long);
NgProperty_PropertyModificationSequence * NgProperty_PropertyModificationSequence_Create (CORBA_unsigned_long /* size */, NgProperty_PropertyModification*  /* init val */);
void NgProperty_PropertyModificationSequence_Init (NgProperty_PropertyModificationSequence * /* seq */, CORBA_unsigned_long /* size */, NgProperty_PropertyModification*  /* init val */);
NgProperty_PropertyModificationSequence *
  CORBA_sequence_NgProperty_PropertyModificationSequence_allocbuf (CORBA_unsigned_long /* count */);

NgProperty_PutablePropertySet *
  CORBA_sequence_NgProperty_PutablePropertySet_allocbuf (CORBA_unsigned_long /* count */);

NgProperty_PropertyModificationKind *
  CORBA_sequence_NgProperty_PropertyModificationKind_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgProperty_PropertyModification" */
struct NgProperty_PropertyModification {
	NgBasic_String propertyName;
	NgProperty_PropertyModificationKind modification;
	NgBasic_OptionalPickle value;
};
NgProperty_PropertyModification *
  CORBA_sequence_NgProperty_PropertyModification_allocbuf (CORBA_unsigned_long /* count */);

/* "NgProperty_Property" alias for "NgBasic_NameValuePair" */
#define CORBA_sequence_NgProperty_Property_allocbuf CORBA_sequence_NgBasic_NameValuePair_allocbuf



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _NgProperty__Exception_UnknownPropertyNames;
#define ex_NgProperty_UnknownPropertyNames _NgProperty__Exception_UnknownPropertyNames


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "NgProperty_PutablePropertySet"  -------------------*/

#define NgProperty_PutablePropertySet__MSType _NgProperty_PutablePropertySet__ILUType

NgProperty_PutablePropertySet
  NgProperty_PutablePropertySet__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgProperty_PutablePropertySet__SetUserData (NgProperty_PutablePropertySet /* self */, void * /* userData */);
void *
  NgProperty_PutablePropertySet__GetUserData (NgProperty_PutablePropertySet /* self */);

extern NgProperty_PutablePropertySet
  NgProperty_PutablePropertySet__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgProperty_PutablePropertySet class */

extern NgProperty_PutablePropertySet
  NgProperty_PutablePropertySet__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgProperty_PutablePropertySet_GetInterfaceDefinitionSource (NgProperty_PutablePropertySet _handle, ILU_C_ENVIRONMENT *_status);

extern NgProperty_PropertySequence* server_NgProperty_PutablePropertySet_GetProperties (NgProperty_PutablePropertySet _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status);

extern void server_NgProperty_PutablePropertySet_PutProperties (NgProperty_PutablePropertySet _handle, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status);

extern void NgProperty_PutablePropertySet__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgProperty_PutablePropertySet__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgProperty_PutablePropertySet__MakeClass(
  void (*NgProperty_PutablePropertySet_PutProperties__Impl)
     (NgProperty_PutablePropertySet _handle, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status),
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgProperty_PutablePropertySet _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgProperty_PutablePropertySet _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void  /* exceptions:  UnknownPropertyNames WouldBlock Conflict ObjectNotExist */
  NgProperty_PutablePropertySet_PutProperties (NgProperty_PutablePropertySet, NgProperty_PropertyModificationSequence*, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "NgProperty_PropertySet"  --------------------------*/

#define NgProperty_PropertySet__MSType _NgProperty_PropertySet__ILUType

NgProperty_PropertySet
  NgProperty_PropertySet__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgProperty_PropertySet__SetUserData (NgProperty_PropertySet /* self */, void * /* userData */);
void *
  NgProperty_PropertySet__GetUserData (NgProperty_PropertySet /* self */);

extern NgProperty_PropertySet
  NgProperty_PropertySet__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgProperty_PropertySet class */

extern NgProperty_PropertySet
  NgProperty_PropertySet__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgProperty_PropertySet_GetInterfaceDefinitionSource (NgProperty_PropertySet _handle, ILU_C_ENVIRONMENT *_status);

extern NgProperty_PropertySequence* server_NgProperty_PropertySet_GetProperties (NgProperty_PropertySet _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status);

extern void NgProperty_PropertySet__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgProperty_PropertySet__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgProperty_PropertySet__MakeClass(
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgProperty_PropertySet _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgProperty_PropertySet _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern NgProperty_PropertySequence*  /* exceptions:  UnknownPropertyNames WouldBlock ObjectNotExist */
  NgProperty_PropertySet_GetProperties (NgProperty_PropertySet, NgProperty_PropertyNames*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void NgProperty__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _NgProperty_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _NgProperty_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _NgProperty_PutablePropertySet__IoFns;
#define TC_NgProperty_PutablePropertySet (& _NgProperty_PutablePropertySet__IoFns)
extern void NgProperty_PutablePropertySet__Free (NgProperty_PutablePropertySet*);
extern struct _ILU_C_IoFnsRegistration_s _NgProperty_PropertyModificationSequence__IoFns;
#define TC_NgProperty_PropertyModificationSequence (& _NgProperty_PropertyModificationSequence__IoFns)
extern void _NgProperty_PropertyModificationSequence__Output (ilu_Call, NgProperty_PropertyModificationSequence*, ilu_Error *);
extern ilu_cardinal _NgProperty_PropertyModificationSequence__SizeOf (ilu_Call, NgProperty_PropertyModificationSequence*, ilu_Error *);
extern NgProperty_PropertyModificationSequence* _NgProperty_PropertyModificationSequence__Input (ilu_Call, NgProperty_PropertyModificationSequence*, ilu_Error *);
extern void NgProperty_PropertyModificationSequence__Free (NgProperty_PropertyModificationSequence*);
NgProperty_PropertyModificationSequence* NgProperty_PropertyModificationSequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgProperty_PropertyModification__IoFns;
#define TC_NgProperty_PropertyModification (& _NgProperty_PropertyModification__IoFns)
extern void _NgProperty_PropertyModification__Output (ilu_Call, NgProperty_PropertyModification*, ilu_Error *);
extern ilu_cardinal _NgProperty_PropertyModification__SizeOf (ilu_Call, NgProperty_PropertyModification*, ilu_Error *);
extern NgProperty_PropertyModification* _NgProperty_PropertyModification__Input (ilu_Call, NgProperty_PropertyModification*, ilu_Error *);
extern void NgProperty_PropertyModification__Free (NgProperty_PropertyModification*);
NgProperty_PropertyModification* NgProperty_PropertyModification__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgProperty_PropertyModificationKind__IoFns;
#define TC_NgProperty_PropertyModificationKind (& _NgProperty_PropertyModificationKind__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _NgProperty_PropertySet__IoFns;
#define TC_NgProperty_PropertySet (& _NgProperty_PropertySet__IoFns)
extern void NgProperty_PropertySet__Free (NgProperty_PropertySet*);
#define _NgProperty_PropertyNames__IoFns _NgBasic_NameSequence__IoFns
#define TC_NgProperty_PropertyNames (& _NgProperty_PropertyNames__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _NgProperty_PropertySequence__IoFns;
#define TC_NgProperty_PropertySequence (& _NgProperty_PropertySequence__IoFns)
extern void _NgProperty_PropertySequence__Output (ilu_Call, NgProperty_PropertySequence*, ilu_Error *);
extern ilu_cardinal _NgProperty_PropertySequence__SizeOf (ilu_Call, NgProperty_PropertySequence*, ilu_Error *);
extern NgProperty_PropertySequence* _NgProperty_PropertySequence__Input (ilu_Call, NgProperty_PropertySequence*, ilu_Error *);
extern void NgProperty_PropertySequence__Free (NgProperty_PropertySequence*);
NgProperty_PropertySequence* NgProperty_PropertySequence__alloc (void);
#define _NgProperty_Property__IoFns _NgBasic_NameValuePair__IoFns
#define TC_NgProperty_Property (& _NgProperty_Property__IoFns)

extern ilu_Class _NgProperty_PutablePropertySet__ILUType;
extern void _NgProperty_PutablePropertySet_PutProperties__clientstub (NgProperty_PutablePropertySet _handle, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _NgProperty_PropertySet__ILUType;
extern NgProperty_PropertySequence* _NgProperty_PropertySet_GetProperties__clientstub (NgProperty_PropertySet _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status);

extern void _NgProperty__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __NgProperty_h_ */
