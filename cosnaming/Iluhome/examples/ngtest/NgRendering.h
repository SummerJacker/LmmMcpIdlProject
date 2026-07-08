/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgRendering.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "ianacharsets.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngcache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngstream.isl" of Fri Aug 01 13:29:38 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __NgRendering_h_
#define __NgRendering_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "NgBasic.h"
#include "IANA_Charsets_Registry.h"
#include "NgCache.h"
#include "NgStream.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                           NgRendering                            ***/
/************************************************************************/
/************************************************************************/

extern void NgRendering__Initialize(void);
extern void NgRendering__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT NgRendering_PutableRenderable;
typedef ILU_C_OBJECT NgRendering_Renderable;
typedef ILU_C_OBJECT NgRendering_RenderingSink;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct NgRendering_RenderingPreferences NgRendering_RenderingPreferences;
typedef struct NgRendering_Rendering NgRendering_Rendering;
typedef struct _NgRendering_RenderingProblemReport_union NgRendering_RenderingProblemReport;
typedef struct NgRendering_RenderingChunk NgRendering_RenderingChunk;
typedef NgRendering_Rendering *NgRendering_OptionalRendering;
typedef struct _NgRendering_RenderingContentBytes__sequence NgRendering_RenderingContentBytes;
typedef NgBasic_URISequence NgRendering_RenderingEncodingSequence;
typedef NgBasic_String NgRendering_RenderingEncoding;
typedef NgBasic_URISequence NgRendering_RenderingTypeSequence;
typedef NgBasic_String NgRendering_RenderingType;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* "NgRendering_RenderingTypeSequence" alias for "NgBasic_URISequence" */
#define NgRendering_RenderingTypeSequence_Length NgBasic_URISequence_Length
#define NgRendering_RenderingTypeSequence_Nth NgBasic_URISequence_Nth
#define NgRendering_RenderingTypeSequence_Every NgBasic_URISequence_Every
#define NgRendering_RenderingTypeSequence_Append NgBasic_URISequence_Append
#define NgRendering_RenderingTypeSequence_Push NgBasic_URISequence_Push
#define NgRendering_RenderingTypeSequence_Pop NgBasic_URISequence_Pop
#define NgRendering_RenderingTypeSequence_Init NgBasic_URISequence_Init
#define NgRendering_RenderingTypeSequence_Create NgBasic_URISequence_Create
#define NgRendering_RenderingTypeSequence__Free NgBasic_URISequence__Free
#define NgRendering_RenderingTypeSequence__alloc NgBasic_URISequence__alloc
#define CORBA_sequence_NgRendering_RenderingTypeSequence_allocbuf CORBA_sequence_NgBasic_URISequence_allocbuf

/* "NgRendering_RenderingEncodingSequence" alias for "NgBasic_URISequence" */
#define NgRendering_RenderingEncodingSequence_Length NgBasic_URISequence_Length
#define NgRendering_RenderingEncodingSequence_Nth NgBasic_URISequence_Nth
#define NgRendering_RenderingEncodingSequence_Every NgBasic_URISequence_Every
#define NgRendering_RenderingEncodingSequence_Append NgBasic_URISequence_Append
#define NgRendering_RenderingEncodingSequence_Push NgBasic_URISequence_Push
#define NgRendering_RenderingEncodingSequence_Pop NgBasic_URISequence_Pop
#define NgRendering_RenderingEncodingSequence_Init NgBasic_URISequence_Init
#define NgRendering_RenderingEncodingSequence_Create NgBasic_URISequence_Create
#define NgRendering_RenderingEncodingSequence__Free NgBasic_URISequence__Free
#define NgRendering_RenderingEncodingSequence__alloc NgBasic_URISequence__alloc
#define CORBA_sequence_NgRendering_RenderingEncodingSequence_allocbuf CORBA_sequence_NgBasic_URISequence_allocbuf

/* record "NgRendering_RenderingPreferences" */
struct NgRendering_RenderingPreferences {
	NgRendering_RenderingTypeSequence allowContentTypes;
	NgRendering_RenderingTypeSequence disallowContentTypes;
	NgRendering_RenderingEncodingSequence allowEncodings;
	NgRendering_RenderingEncodingSequence disallowEncodings;
	IANA_Charsets_Registry_CharsetMIBEnumValueSequence acceptCharsets;
	NgBasic_StringSequence acceptLocales;
	NgBasic_OptionalUnsignedInclusiveInterval range;
	NgBasic_OptionalURI userAgent;
};
NgRendering_RenderingPreferences *
  CORBA_sequence_NgRendering_RenderingPreferences_allocbuf (CORBA_unsigned_long /* count */);

/* "NgRendering_RenderingType" alias for "NgBasic_String" */
#define NgRendering_RenderingType_Length NgBasic_String_Length
#define NgRendering_RenderingType_Nth NgBasic_String_Nth
#define NgRendering_RenderingType_Every NgBasic_String_Every
#define NgRendering_RenderingType_Append NgBasic_String_Append
#define NgRendering_RenderingType_Push NgBasic_String_Push
#define NgRendering_RenderingType_Pop NgBasic_String_Pop
#define NgRendering_RenderingType_Init NgBasic_String_Init
#define NgRendering_RenderingType_Create NgBasic_String_Create
#define NgRendering_RenderingType__Free NgBasic_String__Free
#define NgRendering_RenderingType__alloc NgBasic_String__alloc
#define CORBA_sequence_NgRendering_RenderingType_allocbuf CORBA_sequence_NgBasic_String_allocbuf

/* sequence type "NgRendering_RenderingContentBytes" */
struct _NgRendering_RenderingContentBytes__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_octet *_buffer;
};
void NgRendering_RenderingContentBytes_Every (NgRendering_RenderingContentBytes *h, void (*f)(CORBA_octet*, void *, ilu_Error *), void *);
void NgRendering_RenderingContentBytes_Append (NgRendering_RenderingContentBytes *h, CORBA_octet item, ilu_Error *);
void NgRendering_RenderingContentBytes_Push (NgRendering_RenderingContentBytes *h, CORBA_octet item);
void NgRendering_RenderingContentBytes_Pop (NgRendering_RenderingContentBytes *h, CORBA_octet *item);
CORBA_unsigned_long NgRendering_RenderingContentBytes_Length (NgRendering_RenderingContentBytes *);
CORBA_octet * NgRendering_RenderingContentBytes_Nth (NgRendering_RenderingContentBytes *, CORBA_unsigned_long);
NgRendering_RenderingContentBytes * NgRendering_RenderingContentBytes_Create (CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
void NgRendering_RenderingContentBytes_Init (NgRendering_RenderingContentBytes * /* seq */, CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
NgRendering_RenderingContentBytes *
  CORBA_sequence_NgRendering_RenderingContentBytes_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgRendering_Rendering" */
struct NgRendering_Rendering {
	NgRendering_RenderingType contentType;
	NgRendering_RenderingEncodingSequence contentEncoding;
	NgBasic_OptionalUnsignedInclusiveInterval contentRange;
	CORBA_boolean rangeEncoded;
	IANA_Charsets_Registry_CharsetMIBEnumValue contentCharSet;
	NgBasic_OptionalString contentLocale;
	NgRendering_RenderingContentBytes renderingBytes;
};
NgRendering_Rendering *
  CORBA_sequence_NgRendering_Rendering_allocbuf (CORBA_unsigned_long /* count */);

/* union "NgRendering_RenderingProblemReport" */

struct _NgRendering_RenderingProblemReport_union {
	CORBA_short _d;
	union {
		NgRendering_RenderingPreferences noMatch;	/* 0 */
		NgBasic_ExceptionInformation wouldBlock;	/* 1 */
		NgBasic_ExceptionInformation objectNotExist;	/* 2 */
	} _u;
};
NgRendering_RenderingProblemReport *
  CORBA_sequence_NgRendering_RenderingProblemReport_allocbuf (CORBA_unsigned_long /* count */);

/* record "NgRendering_RenderingChunk" */
struct NgRendering_RenderingChunk {
	NgBasic_OptionalUnsignedInclusiveInterval contentRange;
	NgRendering_RenderingContentBytes renderingBytes;
};
NgRendering_RenderingChunk *
  CORBA_sequence_NgRendering_RenderingChunk_allocbuf (CORBA_unsigned_long /* count */);

NgRendering_RenderingSink *
  CORBA_sequence_NgRendering_RenderingSink_allocbuf (CORBA_unsigned_long /* count */);

NgRendering_Renderable *
  CORBA_sequence_NgRendering_Renderable_allocbuf (CORBA_unsigned_long /* count */);

NgRendering_PutableRenderable *
  CORBA_sequence_NgRendering_PutableRenderable_allocbuf (CORBA_unsigned_long /* count */);

NgRendering_OptionalRendering *
  CORBA_sequence_NgRendering_OptionalRendering_allocbuf (CORBA_unsigned_long /* count */);

/* "NgRendering_RenderingEncoding" alias for "NgBasic_String" */
#define NgRendering_RenderingEncoding_Length NgBasic_String_Length
#define NgRendering_RenderingEncoding_Nth NgBasic_String_Nth
#define NgRendering_RenderingEncoding_Every NgBasic_String_Every
#define NgRendering_RenderingEncoding_Append NgBasic_String_Append
#define NgRendering_RenderingEncoding_Push NgBasic_String_Push
#define NgRendering_RenderingEncoding_Pop NgBasic_String_Pop
#define NgRendering_RenderingEncoding_Init NgBasic_String_Init
#define NgRendering_RenderingEncoding_Create NgBasic_String_Create
#define NgRendering_RenderingEncoding__Free NgBasic_String__Free
#define NgRendering_RenderingEncoding__alloc NgBasic_String__alloc
#define CORBA_sequence_NgRendering_RenderingEncoding_allocbuf CORBA_sequence_NgBasic_String_allocbuf



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _NgRendering__Exception_NoRenderingMatch;
#define ex_NgRendering_NoRenderingMatch _NgRendering__Exception_NoRenderingMatch


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "NgRendering_PutableRenderable"  -------------------*/

#define NgRendering_PutableRenderable__MSType _NgRendering_PutableRenderable__ILUType

NgRendering_PutableRenderable
  NgRendering_PutableRenderable__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgRendering_PutableRenderable__SetUserData (NgRendering_PutableRenderable /* self */, void * /* userData */);
void *
  NgRendering_PutableRenderable__GetUserData (NgRendering_PutableRenderable /* self */);

extern NgRendering_PutableRenderable
  NgRendering_PutableRenderable__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgRendering_PutableRenderable class */

extern NgRendering_PutableRenderable
  NgRendering_PutableRenderable__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgRendering_PutableRenderable_GetInterfaceDefinitionSource (NgRendering_PutableRenderable _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_RenderingPreferences* server_NgRendering_PutableRenderable_GetAvailableRenderings (NgRendering_PutableRenderable _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgRendering_PutableRenderable_GetRendering (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_PutableRenderable_SendRendering (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_PutableRenderable_SendRenderingSynched (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_PutableRenderable_PutRendering (NgRendering_PutableRenderable _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status);

extern void NgRendering_PutableRenderable__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgRendering_PutableRenderable__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgRendering_PutableRenderable__MakeClass(
  void (*NgRendering_PutableRenderable_PutRendering__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgRendering_PutableRenderable _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgRendering_PutableRenderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgRendering_PutableRenderable _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void  /* exceptions:  NoRenderingMatch WouldBlock Conflict ObjectNotExist */
  NgRendering_PutableRenderable_PutRendering (NgRendering_PutableRenderable, NgRendering_Rendering*, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "NgRendering_Renderable"  --------------------------*/

#define NgRendering_Renderable__MSType _NgRendering_Renderable__ILUType

NgRendering_Renderable
  NgRendering_Renderable__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgRendering_Renderable__SetUserData (NgRendering_Renderable /* self */, void * /* userData */);
void *
  NgRendering_Renderable__GetUserData (NgRendering_Renderable /* self */);

extern NgRendering_Renderable
  NgRendering_Renderable__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgRendering_Renderable class */

extern NgRendering_Renderable
  NgRendering_Renderable__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgRendering_Renderable_GetInterfaceDefinitionSource (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_RenderingPreferences* server_NgRendering_Renderable_GetAvailableRenderings (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgRendering_Renderable_GetRendering (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_Renderable_SendRendering (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_Renderable_SendRenderingSynched (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void NgRendering_Renderable__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgRendering_Renderable__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgRendering_Renderable__MakeClass(
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern NgRendering_RenderingPreferences*  /* exceptions:  WouldBlock ObjectNotExist */
  NgRendering_Renderable_GetAvailableRenderings (NgRendering_Renderable, ILU_C_ENVIRONMENT *);

extern NgRendering_Rendering*  /* exceptions:  NoRenderingMatch WouldBlock ObjectNotExist */
  NgRendering_Renderable_GetRendering (NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgCache_OptionalResponseCacheControl*, ILU_C_ENVIRONMENT *);

extern void
  NgRendering_Renderable_SendRendering (NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgRendering_RenderingSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);

extern void
  NgRendering_Renderable_SendRenderingSynched (NgRendering_Renderable, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgRendering_RenderingSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "NgRendering_RenderingSink"  -----------------------*/

#define NgRendering_RenderingSink__MSType _NgRendering_RenderingSink__ILUType

NgRendering_RenderingSink
  NgRendering_RenderingSink__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgRendering_RenderingSink__SetUserData (NgRendering_RenderingSink /* self */, void * /* userData */);
void *
  NgRendering_RenderingSink__GetUserData (NgRendering_RenderingSink /* self */);

extern NgRendering_RenderingSink
  NgRendering_RenderingSink__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgRendering_RenderingSink class */

extern NgRendering_RenderingSink
  NgRendering_RenderingSink__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgRendering_RenderingSink_GetInterfaceDefinitionSource (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_RenderingSink_RegisterSourceControl (NgRendering_RenderingSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_RenderingSink_Done (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_RenderingSink_RegisterResponseCacheControl (NgRendering_RenderingSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_RenderingSink_RenderingProblem (NgRendering_RenderingSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_RenderingSink_ReceiveRendering (NgRendering_RenderingSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status);

extern void server_NgRendering_RenderingSink_ReceiveRenderingChunk (NgRendering_RenderingSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status);

extern NgBasic_OptionalCardinal server_NgRendering_RenderingSink_Resynchronize (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status);

extern void NgRendering_RenderingSink__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgRendering_RenderingSink__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgRendering_RenderingSink__MakeClass(
  void (*NgRendering_RenderingSink_RegisterResponseCacheControl__Impl)
     (NgRendering_RenderingSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RenderingProblem__Impl)
     (NgRendering_RenderingSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRendering__Impl)
     (NgRendering_RenderingSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRenderingChunk__Impl)
     (NgRendering_RenderingSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status),
  NgBasic_OptionalCardinal (*NgRendering_RenderingSink_Resynchronize__Impl)
     (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgRendering_RenderingSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void
  NgRendering_RenderingSink_RegisterResponseCacheControl (NgRendering_RenderingSink, NgCache_OptionalResponseCacheControl, ILU_C_ENVIRONMENT *);

extern void
  NgRendering_RenderingSink_RenderingProblem (NgRendering_RenderingSink, NgRendering_RenderingProblemReport*, ILU_C_ENVIRONMENT *);

extern void
  NgRendering_RenderingSink_ReceiveRendering (NgRendering_RenderingSink, NgRendering_Rendering*, ILU_C_ENVIRONMENT *);

extern void
  NgRendering_RenderingSink_ReceiveRenderingChunk (NgRendering_RenderingSink, NgRendering_RenderingChunk*, ILU_C_ENVIRONMENT *);

extern NgBasic_OptionalCardinal
  NgRendering_RenderingSink_Resynchronize (NgRendering_RenderingSink, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void NgRendering__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _NgRendering_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _NgRendering_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _NgRendering_PutableRenderable__IoFns;
#define TC_NgRendering_PutableRenderable (& _NgRendering_PutableRenderable__IoFns)
extern void NgRendering_PutableRenderable__Free (NgRendering_PutableRenderable*);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_Renderable__IoFns;
#define TC_NgRendering_Renderable (& _NgRendering_Renderable__IoFns)
extern void NgRendering_Renderable__Free (NgRendering_Renderable*);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingSink__IoFns;
#define TC_NgRendering_RenderingSink (& _NgRendering_RenderingSink__IoFns)
extern void NgRendering_RenderingSink__Free (NgRendering_RenderingSink*);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingProblemReport__IoFns;
#define TC_NgRendering_RenderingProblemReport (& _NgRendering_RenderingProblemReport__IoFns)
extern void _NgRendering_RenderingProblemReport__Output (ilu_Call, NgRendering_RenderingProblemReport*, ilu_Error *);
extern ilu_cardinal _NgRendering_RenderingProblemReport__SizeOf (ilu_Call, NgRendering_RenderingProblemReport*, ilu_Error *);
extern NgRendering_RenderingProblemReport* _NgRendering_RenderingProblemReport__Input (ilu_Call, NgRendering_RenderingProblemReport*, ilu_Error *);
extern void NgRendering_RenderingProblemReport__Free (NgRendering_RenderingProblemReport*);
NgRendering_RenderingProblemReport* NgRendering_RenderingProblemReport__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_OptionalRendering__IoFns;
#define TC_NgRendering_OptionalRendering (& _NgRendering_OptionalRendering__IoFns)
extern void _NgRendering_OptionalRendering__Output (ilu_Call, NgRendering_OptionalRendering, ilu_Error *);
extern ilu_cardinal _NgRendering_OptionalRendering__SizeOf (ilu_Call, NgRendering_OptionalRendering, ilu_Error *);
extern NgRendering_OptionalRendering* _NgRendering_OptionalRendering__Input (ilu_Call, NgRendering_OptionalRendering*, ilu_Error *);
extern void NgRendering_OptionalRendering__Free (NgRendering_OptionalRendering*);
NgRendering_OptionalRendering* NgRendering_OptionalRendering__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_Rendering__IoFns;
#define TC_NgRendering_Rendering (& _NgRendering_Rendering__IoFns)
extern void _NgRendering_Rendering__Output (ilu_Call, NgRendering_Rendering*, ilu_Error *);
extern ilu_cardinal _NgRendering_Rendering__SizeOf (ilu_Call, NgRendering_Rendering*, ilu_Error *);
extern NgRendering_Rendering* _NgRendering_Rendering__Input (ilu_Call, NgRendering_Rendering*, ilu_Error *);
extern void NgRendering_Rendering__Free (NgRendering_Rendering*);
NgRendering_Rendering* NgRendering_Rendering__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingChunk__IoFns;
#define TC_NgRendering_RenderingChunk (& _NgRendering_RenderingChunk__IoFns)
extern void _NgRendering_RenderingChunk__Output (ilu_Call, NgRendering_RenderingChunk*, ilu_Error *);
extern ilu_cardinal _NgRendering_RenderingChunk__SizeOf (ilu_Call, NgRendering_RenderingChunk*, ilu_Error *);
extern NgRendering_RenderingChunk* _NgRendering_RenderingChunk__Input (ilu_Call, NgRendering_RenderingChunk*, ilu_Error *);
extern void NgRendering_RenderingChunk__Free (NgRendering_RenderingChunk*);
NgRendering_RenderingChunk* NgRendering_RenderingChunk__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingContentBytes__IoFns;
#define TC_NgRendering_RenderingContentBytes (& _NgRendering_RenderingContentBytes__IoFns)
extern void _NgRendering_RenderingContentBytes__Output (ilu_Call, NgRendering_RenderingContentBytes*, ilu_Error *);
extern ilu_cardinal _NgRendering_RenderingContentBytes__SizeOf (ilu_Call, NgRendering_RenderingContentBytes*, ilu_Error *);
extern NgRendering_RenderingContentBytes* _NgRendering_RenderingContentBytes__Input (ilu_Call, NgRendering_RenderingContentBytes*, ilu_Error *);
extern void NgRendering_RenderingContentBytes__Free (NgRendering_RenderingContentBytes*);
NgRendering_RenderingContentBytes* NgRendering_RenderingContentBytes__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgRendering_RenderingPreferences__IoFns;
#define TC_NgRendering_RenderingPreferences (& _NgRendering_RenderingPreferences__IoFns)
extern void _NgRendering_RenderingPreferences__Output (ilu_Call, NgRendering_RenderingPreferences*, ilu_Error *);
extern ilu_cardinal _NgRendering_RenderingPreferences__SizeOf (ilu_Call, NgRendering_RenderingPreferences*, ilu_Error *);
extern NgRendering_RenderingPreferences* _NgRendering_RenderingPreferences__Input (ilu_Call, NgRendering_RenderingPreferences*, ilu_Error *);
extern void NgRendering_RenderingPreferences__Free (NgRendering_RenderingPreferences*);
NgRendering_RenderingPreferences* NgRendering_RenderingPreferences__alloc (void);
#define _NgRendering_RenderingEncodingSequence__IoFns _NgBasic_URISequence__IoFns
#define TC_NgRendering_RenderingEncodingSequence (& _NgRendering_RenderingEncodingSequence__IoFns)
#define _NgRendering_RenderingEncoding__IoFns _NgBasic_String__IoFns
#define TC_NgRendering_RenderingEncoding (& _NgRendering_RenderingEncoding__IoFns)
#define _NgRendering_RenderingTypeSequence__IoFns _NgBasic_URISequence__IoFns
#define TC_NgRendering_RenderingTypeSequence (& _NgRendering_RenderingTypeSequence__IoFns)
#define _NgRendering_RenderingType__IoFns _NgBasic_String__IoFns
#define TC_NgRendering_RenderingType (& _NgRendering_RenderingType__IoFns)

extern ilu_Class _NgRendering_PutableRenderable__ILUType;
extern void _NgRendering_PutableRenderable_PutRendering__clientstub (NgRendering_PutableRenderable _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _NgRendering_Renderable__ILUType;
extern NgRendering_RenderingPreferences* _NgRendering_Renderable_GetAvailableRenderings__clientstub (NgRendering_Renderable _handle, ILU_C_ENVIRONMENT *_status);
extern NgRendering_Rendering* _NgRendering_Renderable_GetRendering__clientstub (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);
extern void _NgRendering_Renderable_SendRendering__clientstub (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);
extern void _NgRendering_Renderable_SendRenderingSynched__clientstub (NgRendering_Renderable _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _NgRendering_RenderingSink__ILUType;
extern void _NgRendering_RenderingSink_RegisterResponseCacheControl__clientstub (NgRendering_RenderingSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status);
extern void _NgRendering_RenderingSink_RenderingProblem__clientstub (NgRendering_RenderingSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status);
extern void _NgRendering_RenderingSink_ReceiveRendering__clientstub (NgRendering_RenderingSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status);
extern void _NgRendering_RenderingSink_ReceiveRenderingChunk__clientstub (NgRendering_RenderingSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status);
extern NgBasic_OptionalCardinal _NgRendering_RenderingSink_Resynchronize__clientstub (NgRendering_RenderingSink _handle, ILU_C_ENVIRONMENT *_status);

extern void _NgRendering__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __NgRendering_h_ */
