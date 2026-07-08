/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgBasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __NgBasic_h_
#define __NgBasic_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             NgBasic                              ***/
/************************************************************************/
/************************************************************************/

extern void NgBasic__Initialize(void);
extern void NgBasic__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT NgBasic_NgObject;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _NgBasic_NgObjectSequence__sequence NgBasic_NgObjectSequence;
typedef CORBA_char * NgBasic_String;
typedef struct NgBasic_ExceptionInformation NgBasic_ExceptionInformation;
typedef CORBA_any *NgBasic_OptionalPickle;
typedef struct _NgBasic_NameSequence__sequence NgBasic_NameSequence;
typedef struct _NgBasic_NameValuePairSequence__sequence NgBasic_NameValuePairSequence;
typedef struct NgBasic_NameValuePair NgBasic_NameValuePair;
typedef struct NgBasic_UnsignedInclusiveInterval NgBasic_UnsignedInclusiveInterval;
typedef NgBasic_UnsignedInclusiveInterval *NgBasic_OptionalUnsignedInclusiveInterval;
typedef struct NgBasic_Version NgBasic_Version;
typedef CORBA_long_long NgBasic_RelativeTime;
typedef CORBA_long_long *NgBasic_OptionalRelativeTime;
typedef CORBA_long_long NgBasic_AbsoluteTime;
typedef CORBA_long_long *NgBasic_OptionalAbsoluteTime;
typedef CORBA_unsigned_long *NgBasic_OptionalCardinal;
typedef struct _NgBasic_URISequence__sequence NgBasic_URISequence;
typedef NgBasic_String NgBasic_URI;
typedef NgBasic_String NgBasic_OptionalURI;
typedef struct _NgBasic_ByteSequence__sequence NgBasic_ByteSequence;
typedef struct _NgBasic_StringSequence__sequence NgBasic_StringSequence;
typedef NgBasic_String NgBasic_OptionalString;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* sequence type "NgBasic_NgObjectSequence" */
struct _NgBasic_NgObjectSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgBasic_NgObject *_buffer;
};
void NgBasic_NgObjectSequence_Every (NgBasic_NgObjectSequence *h, void (*f)(NgBasic_NgObject*, void *, ilu_Error *), void *);
void NgBasic_NgObjectSequence_Append (NgBasic_NgObjectSequence *h, NgBasic_NgObject item, ilu_Error *);
void NgBasic_NgObjectSequence_Push (NgBasic_NgObjectSequence *h, NgBasic_NgObject item);
void NgBasic_NgObjectSequence_Pop (NgBasic_NgObjectSequence *h, NgBasic_NgObject *item);
CORBA_unsigned_long NgBasic_NgObjectSequence_Length (NgBasic_NgObjectSequence *);
NgBasic_NgObject * NgBasic_NgObjectSequence_Nth (NgBasic_NgObjectSequence *, CORBA_unsigned_long);
NgBasic_NgObjectSequence * NgBasic_NgObjectSequence_Create (CORBA_unsigned_long /* size */, NgBasic_NgObject * /* init val */);
void NgBasic_NgObjectSequence_Init (NgBasic_NgObjectSequence * /* seq */, CORBA_unsigned_long /* size */, NgBasic_NgObject * /* init val */);
NgBasic_NgObjectSequence *
  CORBA_sequence_NgBasic_NgObjectSequence_allocbuf (CORBA_unsigned_long /* count */);

void NgBasic_String_Every (NgBasic_String *h, void (*f)(CORBA_char *, void *, ilu_Error *), void *);
void NgBasic_String_Append (NgBasic_String *, CORBA_char, ilu_Error *);
void NgBasic_String_Push (NgBasic_String *, CORBA_char);
void NgBasic_String_Pop (NgBasic_String *, CORBA_char *);
CORBA_unsigned_long NgBasic_String_Length (NgBasic_String *);
CORBA_char * NgBasic_String_Nth (NgBasic_String *, CORBA_unsigned_long);
NgBasic_String NgBasic_String_Create (CORBA_unsigned_long, CORBA_char *);
void NgBasic_String_Init (NgBasic_String *, CORBA_unsigned_long);
NgBasic_String *
  CORBA_sequence_NgBasic_String_allocbuf (CORBA_unsigned_long /* count */);

NgBasic_NgObject *
  CORBA_sequence_NgBasic_NgObject_allocbuf (CORBA_unsigned_long /* count */);

NgBasic_OptionalPickle *
  CORBA_sequence_NgBasic_OptionalPickle_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgBasic_ExceptionInformation" */
struct NgBasic_ExceptionInformation {
	NgBasic_String reasonPhrase;
	NgBasic_OptionalPickle specificsData;
};
NgBasic_ExceptionInformation *
  CORBA_sequence_NgBasic_ExceptionInformation_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "NgBasic_NameSequence" */
struct _NgBasic_NameSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgBasic_String *_buffer;
};
void NgBasic_NameSequence_Every (NgBasic_NameSequence *h, void (*f)(NgBasic_String*, void *, ilu_Error *), void *);
void NgBasic_NameSequence_Append (NgBasic_NameSequence *h, NgBasic_String item, ilu_Error *);
void NgBasic_NameSequence_Push (NgBasic_NameSequence *h, NgBasic_String item);
void NgBasic_NameSequence_Pop (NgBasic_NameSequence *h, NgBasic_String *item);
CORBA_unsigned_long NgBasic_NameSequence_Length (NgBasic_NameSequence *);
NgBasic_String * NgBasic_NameSequence_Nth (NgBasic_NameSequence *, CORBA_unsigned_long);
NgBasic_NameSequence * NgBasic_NameSequence_Create (CORBA_unsigned_long /* size */, NgBasic_String * /* init val */);
void NgBasic_NameSequence_Init (NgBasic_NameSequence * /* seq */, CORBA_unsigned_long /* size */, NgBasic_String * /* init val */);
NgBasic_NameSequence *
  CORBA_sequence_NgBasic_NameSequence_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "NgBasic_NameValuePairSequence" */
struct _NgBasic_NameValuePairSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgBasic_NameValuePair *_buffer;
};
void NgBasic_NameValuePairSequence_Every (NgBasic_NameValuePairSequence *h, void (*f)(NgBasic_NameValuePair*, void *, ilu_Error *), void *);
void NgBasic_NameValuePairSequence_Append (NgBasic_NameValuePairSequence *h, NgBasic_NameValuePair* item, ilu_Error *);
void NgBasic_NameValuePairSequence_Push (NgBasic_NameValuePairSequence *h, NgBasic_NameValuePair* item);
void NgBasic_NameValuePairSequence_Pop (NgBasic_NameValuePairSequence *h, NgBasic_NameValuePair* item);
CORBA_unsigned_long NgBasic_NameValuePairSequence_Length (NgBasic_NameValuePairSequence *);
NgBasic_NameValuePair * NgBasic_NameValuePairSequence_Nth (NgBasic_NameValuePairSequence *, CORBA_unsigned_long);
NgBasic_NameValuePairSequence * NgBasic_NameValuePairSequence_Create (CORBA_unsigned_long /* size */, NgBasic_NameValuePair*  /* init val */);
void NgBasic_NameValuePairSequence_Init (NgBasic_NameValuePairSequence * /* seq */, CORBA_unsigned_long /* size */, NgBasic_NameValuePair*  /* init val */);
NgBasic_NameValuePairSequence *
  CORBA_sequence_NgBasic_NameValuePairSequence_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgBasic_NameValuePair" */
struct NgBasic_NameValuePair {
	NgBasic_String name;
	CORBA_any value;
};
NgBasic_NameValuePair *
  CORBA_sequence_NgBasic_NameValuePair_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgBasic_UnsignedInclusiveInterval" */
struct NgBasic_UnsignedInclusiveInterval {
	CORBA_unsigned_long startValue;
	CORBA_unsigned_long endValue;
};
NgBasic_UnsignedInclusiveInterval *
  CORBA_sequence_NgBasic_UnsignedInclusiveInterval_allocbuf (CORBA_unsigned_long /* count */);

NgBasic_OptionalUnsignedInclusiveInterval *
  CORBA_sequence_NgBasic_OptionalUnsignedInclusiveInterval_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgBasic_Version" */
struct NgBasic_Version {
	CORBA_unsigned_short major;
	CORBA_unsigned_short minor;
};
NgBasic_Version *
  CORBA_sequence_NgBasic_Version_allocbuf (CORBA_unsigned_long /* count */);

/* "NgBasic_RelativeTime" alias for "CORBA_long_long" */
#define CORBA_sequence_NgBasic_RelativeTime_allocbuf CORBA_sequence_long_long_allocbuf

NgBasic_OptionalRelativeTime *
  CORBA_sequence_NgBasic_OptionalRelativeTime_allocbuf (CORBA_unsigned_long /* count */);

/* "NgBasic_AbsoluteTime" alias for "CORBA_long_long" */
#define CORBA_sequence_NgBasic_AbsoluteTime_allocbuf CORBA_sequence_long_long_allocbuf

NgBasic_OptionalAbsoluteTime *
  CORBA_sequence_NgBasic_OptionalAbsoluteTime_allocbuf (CORBA_unsigned_long /* count */);

NgBasic_OptionalCardinal *
  CORBA_sequence_NgBasic_OptionalCardinal_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "NgBasic_URISequence" */
struct _NgBasic_URISequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgBasic_URI *_buffer;
};
void NgBasic_URISequence_Every (NgBasic_URISequence *h, void (*f)(NgBasic_URI*, void *, ilu_Error *), void *);
void NgBasic_URISequence_Append (NgBasic_URISequence *h, NgBasic_URI item, ilu_Error *);
void NgBasic_URISequence_Push (NgBasic_URISequence *h, NgBasic_URI item);
void NgBasic_URISequence_Pop (NgBasic_URISequence *h, NgBasic_URI *item);
CORBA_unsigned_long NgBasic_URISequence_Length (NgBasic_URISequence *);
NgBasic_URI * NgBasic_URISequence_Nth (NgBasic_URISequence *, CORBA_unsigned_long);
NgBasic_URISequence * NgBasic_URISequence_Create (CORBA_unsigned_long /* size */, NgBasic_URI * /* init val */);
void NgBasic_URISequence_Init (NgBasic_URISequence * /* seq */, CORBA_unsigned_long /* size */, NgBasic_URI * /* init val */);
NgBasic_URISequence *
  CORBA_sequence_NgBasic_URISequence_allocbuf (CORBA_unsigned_long /* count */);

/* "NgBasic_URI" alias for "NgBasic_String" */
#define NgBasic_URI_Length NgBasic_String_Length
#define NgBasic_URI_Nth NgBasic_String_Nth
#define NgBasic_URI_Every NgBasic_String_Every
#define NgBasic_URI_Append NgBasic_String_Append
#define NgBasic_URI_Push NgBasic_String_Push
#define NgBasic_URI_Pop NgBasic_String_Pop
#define NgBasic_URI_Init NgBasic_String_Init
#define NgBasic_URI_Create NgBasic_String_Create
#define NgBasic_URI__Free NgBasic_String__Free
#define NgBasic_URI__alloc NgBasic_String__alloc
#define CORBA_sequence_NgBasic_URI_allocbuf CORBA_sequence_NgBasic_String_allocbuf

NgBasic_OptionalURI *
  CORBA_sequence_NgBasic_OptionalURI_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "NgBasic_ByteSequence" */
struct _NgBasic_ByteSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_octet *_buffer;
};
void NgBasic_ByteSequence_Every (NgBasic_ByteSequence *h, void (*f)(CORBA_octet*, void *, ilu_Error *), void *);
void NgBasic_ByteSequence_Append (NgBasic_ByteSequence *h, CORBA_octet item, ilu_Error *);
void NgBasic_ByteSequence_Push (NgBasic_ByteSequence *h, CORBA_octet item);
void NgBasic_ByteSequence_Pop (NgBasic_ByteSequence *h, CORBA_octet *item);
CORBA_unsigned_long NgBasic_ByteSequence_Length (NgBasic_ByteSequence *);
CORBA_octet * NgBasic_ByteSequence_Nth (NgBasic_ByteSequence *, CORBA_unsigned_long);
NgBasic_ByteSequence * NgBasic_ByteSequence_Create (CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
void NgBasic_ByteSequence_Init (NgBasic_ByteSequence * /* seq */, CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
NgBasic_ByteSequence *
  CORBA_sequence_NgBasic_ByteSequence_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "NgBasic_StringSequence" */
struct _NgBasic_StringSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgBasic_String *_buffer;
};
void NgBasic_StringSequence_Every (NgBasic_StringSequence *h, void (*f)(NgBasic_String*, void *, ilu_Error *), void *);
void NgBasic_StringSequence_Append (NgBasic_StringSequence *h, NgBasic_String item, ilu_Error *);
void NgBasic_StringSequence_Push (NgBasic_StringSequence *h, NgBasic_String item);
void NgBasic_StringSequence_Pop (NgBasic_StringSequence *h, NgBasic_String *item);
CORBA_unsigned_long NgBasic_StringSequence_Length (NgBasic_StringSequence *);
NgBasic_String * NgBasic_StringSequence_Nth (NgBasic_StringSequence *, CORBA_unsigned_long);
NgBasic_StringSequence * NgBasic_StringSequence_Create (CORBA_unsigned_long /* size */, NgBasic_String * /* init val */);
void NgBasic_StringSequence_Init (NgBasic_StringSequence * /* seq */, CORBA_unsigned_long /* size */, NgBasic_String * /* init val */);
NgBasic_StringSequence *
  CORBA_sequence_NgBasic_StringSequence_allocbuf (CORBA_unsigned_long /* count */);

NgBasic_OptionalString *
  CORBA_sequence_NgBasic_OptionalString_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _NgBasic__Exception_WouldBlock;
#define ex_NgBasic_WouldBlock _NgBasic__Exception_WouldBlock
extern ILU_C_ExceptionCode _NgBasic__Exception_Conflict;
#define ex_NgBasic_Conflict _NgBasic__Exception_Conflict
extern ILU_C_ExceptionCode _NgBasic__Exception_ObjectNotExist;
#define ex_NgBasic_ObjectNotExist _NgBasic__Exception_ObjectNotExist


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "NgBasic_NgObject"  --------------------------------*/

#define NgBasic_NgObject__MSType _NgBasic_NgObject__ILUType

NgBasic_NgObject
  NgBasic_NgObject__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgBasic_NgObject__SetUserData (NgBasic_NgObject /* self */, void * /* userData */);
void *
  NgBasic_NgObject__GetUserData (NgBasic_NgObject /* self */);

extern NgBasic_NgObject
  NgBasic_NgObject__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgBasic_NgObject class */

extern NgBasic_NgObject
  NgBasic_NgObject__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgBasic_NgObject_GetInterfaceDefinitionSource (NgBasic_NgObject _handle, ILU_C_ENVIRONMENT *_status);

extern void NgBasic_NgObject__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgBasic_NgObject__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgBasic_NgObject__MakeClass(
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgBasic_NgObject _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern NgBasic_String
  NgBasic_NgObject_GetInterfaceDefinitionSource (NgBasic_NgObject, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void NgBasic__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _NgBasic_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _NgBasic_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _NgBasic_NgObjectSequence__IoFns;
#define TC_NgBasic_NgObjectSequence (& _NgBasic_NgObjectSequence__IoFns)
extern void _NgBasic_NgObjectSequence__Output (ilu_Call, NgBasic_NgObjectSequence*, ilu_Error *);
extern ilu_cardinal _NgBasic_NgObjectSequence__SizeOf (ilu_Call, NgBasic_NgObjectSequence*, ilu_Error *);
extern NgBasic_NgObjectSequence* _NgBasic_NgObjectSequence__Input (ilu_Call, NgBasic_NgObjectSequence*, ilu_Error *);
extern void NgBasic_NgObjectSequence__Free (NgBasic_NgObjectSequence*);
NgBasic_NgObjectSequence* NgBasic_NgObjectSequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_NgObject__IoFns;
#define TC_NgBasic_NgObject (& _NgBasic_NgObject__IoFns)
extern void NgBasic_NgObject__Free (NgBasic_NgObject*);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_ExceptionInformation__IoFns;
#define TC_NgBasic_ExceptionInformation (& _NgBasic_ExceptionInformation__IoFns)
extern void _NgBasic_ExceptionInformation__Output (ilu_Call, NgBasic_ExceptionInformation*, ilu_Error *);
extern ilu_cardinal _NgBasic_ExceptionInformation__SizeOf (ilu_Call, NgBasic_ExceptionInformation*, ilu_Error *);
extern NgBasic_ExceptionInformation* _NgBasic_ExceptionInformation__Input (ilu_Call, NgBasic_ExceptionInformation*, ilu_Error *);
extern void NgBasic_ExceptionInformation__Free (NgBasic_ExceptionInformation*);
NgBasic_ExceptionInformation* NgBasic_ExceptionInformation__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalPickle__IoFns;
#define TC_NgBasic_OptionalPickle (& _NgBasic_OptionalPickle__IoFns)
extern void _NgBasic_OptionalPickle__Output (ilu_Call, NgBasic_OptionalPickle, ilu_Error *);
extern ilu_cardinal _NgBasic_OptionalPickle__SizeOf (ilu_Call, NgBasic_OptionalPickle, ilu_Error *);
extern NgBasic_OptionalPickle* _NgBasic_OptionalPickle__Input (ilu_Call, NgBasic_OptionalPickle*, ilu_Error *);
extern void NgBasic_OptionalPickle__Free (NgBasic_OptionalPickle*);
NgBasic_OptionalPickle* NgBasic_OptionalPickle__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_NameSequence__IoFns;
#define TC_NgBasic_NameSequence (& _NgBasic_NameSequence__IoFns)
extern void _NgBasic_NameSequence__Output (ilu_Call, NgBasic_NameSequence*, ilu_Error *);
extern ilu_cardinal _NgBasic_NameSequence__SizeOf (ilu_Call, NgBasic_NameSequence*, ilu_Error *);
extern NgBasic_NameSequence* _NgBasic_NameSequence__Input (ilu_Call, NgBasic_NameSequence*, ilu_Error *);
extern void NgBasic_NameSequence__Free (NgBasic_NameSequence*);
NgBasic_NameSequence* NgBasic_NameSequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_NameValuePairSequence__IoFns;
#define TC_NgBasic_NameValuePairSequence (& _NgBasic_NameValuePairSequence__IoFns)
extern void _NgBasic_NameValuePairSequence__Output (ilu_Call, NgBasic_NameValuePairSequence*, ilu_Error *);
extern ilu_cardinal _NgBasic_NameValuePairSequence__SizeOf (ilu_Call, NgBasic_NameValuePairSequence*, ilu_Error *);
extern NgBasic_NameValuePairSequence* _NgBasic_NameValuePairSequence__Input (ilu_Call, NgBasic_NameValuePairSequence*, ilu_Error *);
extern void NgBasic_NameValuePairSequence__Free (NgBasic_NameValuePairSequence*);
NgBasic_NameValuePairSequence* NgBasic_NameValuePairSequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_NameValuePair__IoFns;
#define TC_NgBasic_NameValuePair (& _NgBasic_NameValuePair__IoFns)
extern void _NgBasic_NameValuePair__Output (ilu_Call, NgBasic_NameValuePair*, ilu_Error *);
extern ilu_cardinal _NgBasic_NameValuePair__SizeOf (ilu_Call, NgBasic_NameValuePair*, ilu_Error *);
extern NgBasic_NameValuePair* _NgBasic_NameValuePair__Input (ilu_Call, NgBasic_NameValuePair*, ilu_Error *);
extern void NgBasic_NameValuePair__Free (NgBasic_NameValuePair*);
NgBasic_NameValuePair* NgBasic_NameValuePair__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalUnsignedInclusiveInterval__IoFns;
#define TC_NgBasic_OptionalUnsignedInclusiveInterval (& _NgBasic_OptionalUnsignedInclusiveInterval__IoFns)
extern void _NgBasic_OptionalUnsignedInclusiveInterval__Output (ilu_Call, NgBasic_OptionalUnsignedInclusiveInterval, ilu_Error *);
extern ilu_cardinal _NgBasic_OptionalUnsignedInclusiveInterval__SizeOf (ilu_Call, NgBasic_OptionalUnsignedInclusiveInterval, ilu_Error *);
extern NgBasic_OptionalUnsignedInclusiveInterval* _NgBasic_OptionalUnsignedInclusiveInterval__Input (ilu_Call, NgBasic_OptionalUnsignedInclusiveInterval*, ilu_Error *);
extern void NgBasic_OptionalUnsignedInclusiveInterval__Free (NgBasic_OptionalUnsignedInclusiveInterval*);
NgBasic_OptionalUnsignedInclusiveInterval* NgBasic_OptionalUnsignedInclusiveInterval__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_UnsignedInclusiveInterval__IoFns;
#define TC_NgBasic_UnsignedInclusiveInterval (& _NgBasic_UnsignedInclusiveInterval__IoFns)
extern void _NgBasic_UnsignedInclusiveInterval__Output (ilu_Call, NgBasic_UnsignedInclusiveInterval*, ilu_Error *);
extern ilu_cardinal _NgBasic_UnsignedInclusiveInterval__SizeOf (ilu_Call, NgBasic_UnsignedInclusiveInterval*, ilu_Error *);
extern NgBasic_UnsignedInclusiveInterval* _NgBasic_UnsignedInclusiveInterval__Input (ilu_Call, NgBasic_UnsignedInclusiveInterval*, ilu_Error *);
NgBasic_UnsignedInclusiveInterval* NgBasic_UnsignedInclusiveInterval__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_Version__IoFns;
#define TC_NgBasic_Version (& _NgBasic_Version__IoFns)
extern void _NgBasic_Version__Output (ilu_Call, NgBasic_Version*, ilu_Error *);
extern ilu_cardinal _NgBasic_Version__SizeOf (ilu_Call, NgBasic_Version*, ilu_Error *);
extern NgBasic_Version* _NgBasic_Version__Input (ilu_Call, NgBasic_Version*, ilu_Error *);
NgBasic_Version* NgBasic_Version__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalRelativeTime__IoFns;
#define TC_NgBasic_OptionalRelativeTime (& _NgBasic_OptionalRelativeTime__IoFns)
extern void _NgBasic_OptionalRelativeTime__Output (ilu_Call, NgBasic_OptionalRelativeTime, ilu_Error *);
extern ilu_cardinal _NgBasic_OptionalRelativeTime__SizeOf (ilu_Call, NgBasic_OptionalRelativeTime, ilu_Error *);
extern NgBasic_OptionalRelativeTime* _NgBasic_OptionalRelativeTime__Input (ilu_Call, NgBasic_OptionalRelativeTime*, ilu_Error *);
extern void NgBasic_OptionalRelativeTime__Free (NgBasic_OptionalRelativeTime*);
NgBasic_OptionalRelativeTime* NgBasic_OptionalRelativeTime__alloc (void);
#define _NgBasic_RelativeTime__IoFns _CORBA_long_long__IoFns
#define TC_NgBasic_RelativeTime (& _NgBasic_RelativeTime__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalAbsoluteTime__IoFns;
#define TC_NgBasic_OptionalAbsoluteTime (& _NgBasic_OptionalAbsoluteTime__IoFns)
extern void _NgBasic_OptionalAbsoluteTime__Output (ilu_Call, NgBasic_OptionalAbsoluteTime, ilu_Error *);
extern ilu_cardinal _NgBasic_OptionalAbsoluteTime__SizeOf (ilu_Call, NgBasic_OptionalAbsoluteTime, ilu_Error *);
extern NgBasic_OptionalAbsoluteTime* _NgBasic_OptionalAbsoluteTime__Input (ilu_Call, NgBasic_OptionalAbsoluteTime*, ilu_Error *);
extern void NgBasic_OptionalAbsoluteTime__Free (NgBasic_OptionalAbsoluteTime*);
NgBasic_OptionalAbsoluteTime* NgBasic_OptionalAbsoluteTime__alloc (void);
#define _NgBasic_AbsoluteTime__IoFns _CORBA_long_long__IoFns
#define TC_NgBasic_AbsoluteTime (& _NgBasic_AbsoluteTime__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalCardinal__IoFns;
#define TC_NgBasic_OptionalCardinal (& _NgBasic_OptionalCardinal__IoFns)
extern void _NgBasic_OptionalCardinal__Output (ilu_Call, NgBasic_OptionalCardinal, ilu_Error *);
extern ilu_cardinal _NgBasic_OptionalCardinal__SizeOf (ilu_Call, NgBasic_OptionalCardinal, ilu_Error *);
extern NgBasic_OptionalCardinal* _NgBasic_OptionalCardinal__Input (ilu_Call, NgBasic_OptionalCardinal*, ilu_Error *);
extern void NgBasic_OptionalCardinal__Free (NgBasic_OptionalCardinal*);
NgBasic_OptionalCardinal* NgBasic_OptionalCardinal__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_URISequence__IoFns;
#define TC_NgBasic_URISequence (& _NgBasic_URISequence__IoFns)
extern void _NgBasic_URISequence__Output (ilu_Call, NgBasic_URISequence*, ilu_Error *);
extern ilu_cardinal _NgBasic_URISequence__SizeOf (ilu_Call, NgBasic_URISequence*, ilu_Error *);
extern NgBasic_URISequence* _NgBasic_URISequence__Input (ilu_Call, NgBasic_URISequence*, ilu_Error *);
extern void NgBasic_URISequence__Free (NgBasic_URISequence*);
NgBasic_URISequence* NgBasic_URISequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalURI__IoFns;
#define TC_NgBasic_OptionalURI (& _NgBasic_OptionalURI__IoFns)
extern void _NgBasic_OptionalURI__Output (ilu_Call, NgBasic_OptionalURI, ilu_Error *);
extern ilu_cardinal _NgBasic_OptionalURI__SizeOf (ilu_Call, NgBasic_OptionalURI, ilu_Error *);
extern NgBasic_OptionalURI* _NgBasic_OptionalURI__Input (ilu_Call, NgBasic_OptionalURI*, ilu_Error *);
extern void NgBasic_OptionalURI__Free (NgBasic_OptionalURI*);
NgBasic_OptionalURI* NgBasic_OptionalURI__alloc (void);
#define _NgBasic_URI__IoFns _NgBasic_String__IoFns
#define TC_NgBasic_URI (& _NgBasic_URI__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_ByteSequence__IoFns;
#define TC_NgBasic_ByteSequence (& _NgBasic_ByteSequence__IoFns)
extern void _NgBasic_ByteSequence__Output (ilu_Call, NgBasic_ByteSequence*, ilu_Error *);
extern ilu_cardinal _NgBasic_ByteSequence__SizeOf (ilu_Call, NgBasic_ByteSequence*, ilu_Error *);
extern NgBasic_ByteSequence* _NgBasic_ByteSequence__Input (ilu_Call, NgBasic_ByteSequence*, ilu_Error *);
extern void NgBasic_ByteSequence__Free (NgBasic_ByteSequence*);
NgBasic_ByteSequence* NgBasic_ByteSequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_StringSequence__IoFns;
#define TC_NgBasic_StringSequence (& _NgBasic_StringSequence__IoFns)
extern void _NgBasic_StringSequence__Output (ilu_Call, NgBasic_StringSequence*, ilu_Error *);
extern ilu_cardinal _NgBasic_StringSequence__SizeOf (ilu_Call, NgBasic_StringSequence*, ilu_Error *);
extern NgBasic_StringSequence* _NgBasic_StringSequence__Input (ilu_Call, NgBasic_StringSequence*, ilu_Error *);
extern void NgBasic_StringSequence__Free (NgBasic_StringSequence*);
NgBasic_StringSequence* NgBasic_StringSequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_OptionalString__IoFns;
#define TC_NgBasic_OptionalString (& _NgBasic_OptionalString__IoFns)
extern void _NgBasic_OptionalString__Output (ilu_Call, NgBasic_OptionalString, ilu_Error *);
extern ilu_cardinal _NgBasic_OptionalString__SizeOf (ilu_Call, NgBasic_OptionalString, ilu_Error *);
extern NgBasic_OptionalString* _NgBasic_OptionalString__Input (ilu_Call, NgBasic_OptionalString*, ilu_Error *);
extern void NgBasic_OptionalString__Free (NgBasic_OptionalString*);
NgBasic_OptionalString* NgBasic_OptionalString__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgBasic_String__IoFns;
#define TC_NgBasic_String (& _NgBasic_String__IoFns)
extern void _NgBasic_String__Output (ilu_Call, NgBasic_String, ilu_Error *);
extern ilu_cardinal _NgBasic_String__SizeOf (ilu_Call, NgBasic_String, ilu_Error *);
extern NgBasic_String* _NgBasic_String__Input (ilu_Call, NgBasic_String*, ilu_Error *);
extern void NgBasic_String__Free (NgBasic_String*);
NgBasic_String* NgBasic_String__alloc (void);

extern ilu_Class _NgBasic_NgObject__ILUType;
extern NgBasic_String _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub (NgBasic_NgObject _handle, ILU_C_ENVIRONMENT *_status);

extern void _NgBasic__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __NgBasic_h_ */
