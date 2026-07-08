/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgCache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __NgCache_h_
#define __NgCache_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "NgBasic.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             NgCache                              ***/
/************************************************************************/
/************************************************************************/

extern void NgCache__Initialize(void);
extern void NgCache__InitializeServer(void);



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct NgCache_ResponseCacheControl NgCache_ResponseCacheControl;
typedef NgCache_ResponseCacheControl *NgCache_OptionalResponseCacheControl;
typedef struct NgCache_RequestCacheControl NgCache_RequestCacheControl;
typedef NgCache_RequestCacheControl *NgCache_OptionalRequestCacheControl;
typedef NgBasic_String NgCache_EntityTag;
typedef struct _NgCache_EntityTagOrDate_union NgCache_EntityTagOrDate;
typedef struct _NgCache_EntityTagSequence__sequence NgCache_EntityTagSequence;
typedef NgBasic_String NgCache_OptionalEntityTag;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

NgCache_OptionalEntityTag *
  CORBA_sequence_NgCache_OptionalEntityTag_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgCache_ResponseCacheControl" */
struct NgCache_ResponseCacheControl {
	CORBA_boolean okPublic;
	CORBA_boolean isPrivate;
	CORBA_boolean noCache;
	CORBA_boolean noStore;
	CORBA_boolean noTransform;
	CORBA_boolean mustRevalidate;
	CORBA_boolean proxyRevalidate;
	NgBasic_OptionalRelativeTime maxAge;
	NgBasic_OptionalRelativeTime sMaxAge;
	NgBasic_OptionalRelativeTime age;
	NgBasic_StringSequence vary;
	NgCache_OptionalEntityTag entityTag;
	NgBasic_OptionalAbsoluteTime lastModified;
	NgBasic_OptionalAbsoluteTime expires;
};
NgCache_ResponseCacheControl *
  CORBA_sequence_NgCache_ResponseCacheControl_allocbuf (CORBA_unsigned_long /* count */);

NgCache_OptionalResponseCacheControl *
  CORBA_sequence_NgCache_OptionalResponseCacheControl_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "NgCache_EntityTagSequence" */
struct _NgCache_EntityTagSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgCache_EntityTag *_buffer;
};
void NgCache_EntityTagSequence_Every (NgCache_EntityTagSequence *h, void (*f)(NgCache_EntityTag*, void *, ilu_Error *), void *);
void NgCache_EntityTagSequence_Append (NgCache_EntityTagSequence *h, NgCache_EntityTag item, ilu_Error *);
void NgCache_EntityTagSequence_Push (NgCache_EntityTagSequence *h, NgCache_EntityTag item);
void NgCache_EntityTagSequence_Pop (NgCache_EntityTagSequence *h, NgCache_EntityTag *item);
CORBA_unsigned_long NgCache_EntityTagSequence_Length (NgCache_EntityTagSequence *);
NgCache_EntityTag * NgCache_EntityTagSequence_Nth (NgCache_EntityTagSequence *, CORBA_unsigned_long);
NgCache_EntityTagSequence * NgCache_EntityTagSequence_Create (CORBA_unsigned_long /* size */, NgCache_EntityTag * /* init val */);
void NgCache_EntityTagSequence_Init (NgCache_EntityTagSequence * /* seq */, CORBA_unsigned_long /* size */, NgCache_EntityTag * /* init val */);
NgCache_EntityTagSequence *
  CORBA_sequence_NgCache_EntityTagSequence_allocbuf (CORBA_unsigned_long /* count */);

/* "NgCache_EntityTag" alias for "NgBasic_String" */
#define NgCache_EntityTag_Length NgBasic_String_Length
#define NgCache_EntityTag_Nth NgBasic_String_Nth
#define NgCache_EntityTag_Every NgBasic_String_Every
#define NgCache_EntityTag_Append NgBasic_String_Append
#define NgCache_EntityTag_Push NgBasic_String_Push
#define NgCache_EntityTag_Pop NgBasic_String_Pop
#define NgCache_EntityTag_Init NgBasic_String_Init
#define NgCache_EntityTag_Create NgBasic_String_Create
#define NgCache_EntityTag__Free NgBasic_String__Free
#define NgCache_EntityTag__alloc NgBasic_String__alloc
#define CORBA_sequence_NgCache_EntityTag_allocbuf CORBA_sequence_NgBasic_String_allocbuf

/* union "NgCache_EntityTagOrDate" */

struct _NgCache_EntityTagOrDate_union {
	CORBA_short _d;
	union {
		NgCache_EntityTag etag;	/* 0 */
		NgBasic_AbsoluteTime ifdate;	/* 1 */
	} _u;
};
NgCache_EntityTagOrDate *
  CORBA_sequence_NgCache_EntityTagOrDate_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgCache_RequestCacheControl" */
struct NgCache_RequestCacheControl {
	CORBA_boolean noCache;
	CORBA_boolean noStore;
	CORBA_boolean noTransform;
	CORBA_boolean onlyIfCached;
	NgBasic_OptionalAbsoluteTime ifModifiedSince;
	NgCache_EntityTagSequence ifMatch;
	NgCache_EntityTagSequence ifNoneMatch;
	NgCache_EntityTagOrDate ifRange;
};
NgCache_RequestCacheControl *
  CORBA_sequence_NgCache_RequestCacheControl_allocbuf (CORBA_unsigned_long /* count */);

NgCache_OptionalRequestCacheControl *
  CORBA_sequence_NgCache_OptionalRequestCacheControl_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void NgCache__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _NgCache_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _NgCache_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _NgCache_OptionalResponseCacheControl__IoFns;
#define TC_NgCache_OptionalResponseCacheControl (& _NgCache_OptionalResponseCacheControl__IoFns)
extern void _NgCache_OptionalResponseCacheControl__Output (ilu_Call, NgCache_OptionalResponseCacheControl, ilu_Error *);
extern ilu_cardinal _NgCache_OptionalResponseCacheControl__SizeOf (ilu_Call, NgCache_OptionalResponseCacheControl, ilu_Error *);
extern NgCache_OptionalResponseCacheControl* _NgCache_OptionalResponseCacheControl__Input (ilu_Call, NgCache_OptionalResponseCacheControl*, ilu_Error *);
extern void NgCache_OptionalResponseCacheControl__Free (NgCache_OptionalResponseCacheControl*);
NgCache_OptionalResponseCacheControl* NgCache_OptionalResponseCacheControl__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgCache_ResponseCacheControl__IoFns;
#define TC_NgCache_ResponseCacheControl (& _NgCache_ResponseCacheControl__IoFns)
extern void _NgCache_ResponseCacheControl__Output (ilu_Call, NgCache_ResponseCacheControl*, ilu_Error *);
extern ilu_cardinal _NgCache_ResponseCacheControl__SizeOf (ilu_Call, NgCache_ResponseCacheControl*, ilu_Error *);
extern NgCache_ResponseCacheControl* _NgCache_ResponseCacheControl__Input (ilu_Call, NgCache_ResponseCacheControl*, ilu_Error *);
extern void NgCache_ResponseCacheControl__Free (NgCache_ResponseCacheControl*);
NgCache_ResponseCacheControl* NgCache_ResponseCacheControl__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgCache_OptionalRequestCacheControl__IoFns;
#define TC_NgCache_OptionalRequestCacheControl (& _NgCache_OptionalRequestCacheControl__IoFns)
extern void _NgCache_OptionalRequestCacheControl__Output (ilu_Call, NgCache_OptionalRequestCacheControl, ilu_Error *);
extern ilu_cardinal _NgCache_OptionalRequestCacheControl__SizeOf (ilu_Call, NgCache_OptionalRequestCacheControl, ilu_Error *);
extern NgCache_OptionalRequestCacheControl* _NgCache_OptionalRequestCacheControl__Input (ilu_Call, NgCache_OptionalRequestCacheControl*, ilu_Error *);
extern void NgCache_OptionalRequestCacheControl__Free (NgCache_OptionalRequestCacheControl*);
NgCache_OptionalRequestCacheControl* NgCache_OptionalRequestCacheControl__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgCache_RequestCacheControl__IoFns;
#define TC_NgCache_RequestCacheControl (& _NgCache_RequestCacheControl__IoFns)
extern void _NgCache_RequestCacheControl__Output (ilu_Call, NgCache_RequestCacheControl*, ilu_Error *);
extern ilu_cardinal _NgCache_RequestCacheControl__SizeOf (ilu_Call, NgCache_RequestCacheControl*, ilu_Error *);
extern NgCache_RequestCacheControl* _NgCache_RequestCacheControl__Input (ilu_Call, NgCache_RequestCacheControl*, ilu_Error *);
extern void NgCache_RequestCacheControl__Free (NgCache_RequestCacheControl*);
NgCache_RequestCacheControl* NgCache_RequestCacheControl__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgCache_EntityTagOrDate__IoFns;
#define TC_NgCache_EntityTagOrDate (& _NgCache_EntityTagOrDate__IoFns)
extern void _NgCache_EntityTagOrDate__Output (ilu_Call, NgCache_EntityTagOrDate*, ilu_Error *);
extern ilu_cardinal _NgCache_EntityTagOrDate__SizeOf (ilu_Call, NgCache_EntityTagOrDate*, ilu_Error *);
extern NgCache_EntityTagOrDate* _NgCache_EntityTagOrDate__Input (ilu_Call, NgCache_EntityTagOrDate*, ilu_Error *);
extern void NgCache_EntityTagOrDate__Free (NgCache_EntityTagOrDate*);
NgCache_EntityTagOrDate* NgCache_EntityTagOrDate__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgCache_EntityTagSequence__IoFns;
#define TC_NgCache_EntityTagSequence (& _NgCache_EntityTagSequence__IoFns)
extern void _NgCache_EntityTagSequence__Output (ilu_Call, NgCache_EntityTagSequence*, ilu_Error *);
extern ilu_cardinal _NgCache_EntityTagSequence__SizeOf (ilu_Call, NgCache_EntityTagSequence*, ilu_Error *);
extern NgCache_EntityTagSequence* _NgCache_EntityTagSequence__Input (ilu_Call, NgCache_EntityTagSequence*, ilu_Error *);
extern void NgCache_EntityTagSequence__Free (NgCache_EntityTagSequence*);
NgCache_EntityTagSequence* NgCache_EntityTagSequence__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgCache_OptionalEntityTag__IoFns;
#define TC_NgCache_OptionalEntityTag (& _NgCache_OptionalEntityTag__IoFns)
extern void _NgCache_OptionalEntityTag__Output (ilu_Call, NgCache_OptionalEntityTag, ilu_Error *);
extern ilu_cardinal _NgCache_OptionalEntityTag__SizeOf (ilu_Call, NgCache_OptionalEntityTag, ilu_Error *);
extern NgCache_OptionalEntityTag* _NgCache_OptionalEntityTag__Input (ilu_Call, NgCache_OptionalEntityTag*, ilu_Error *);
extern void NgCache_OptionalEntityTag__Free (NgCache_OptionalEntityTag*);
NgCache_OptionalEntityTag* NgCache_OptionalEntityTag__alloc (void);
#define _NgCache_EntityTag__IoFns _NgBasic_String__IoFns
#define TC_NgCache_EntityTag (& _NgCache_EntityTag__IoFns)

extern void _NgCache__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __NgCache_h_ */
