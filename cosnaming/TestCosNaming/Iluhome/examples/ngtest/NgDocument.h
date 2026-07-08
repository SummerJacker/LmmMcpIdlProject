/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgDocument.isl" of Fri Aug 01 13:29:37 2025,
 * and "iluhttp.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngrendering.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngcache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngproperty.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngstream.isl" of Fri Aug 01 13:29:38 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __NgDocument_h_
#define __NgDocument_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "iluhttp.h"
#include "NgRendering.h"
#include "NgCache.h"
#include "NgProperty.h"
#include "NgStream.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                            NgDocument                            ***/
/************************************************************************/
/************************************************************************/

extern void NgDocument__Initialize(void);
extern void NgDocument__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT NgDocument_HTTPCompatibleWebDocument;
typedef ILU_C_OBJECT NgDocument_PutableWebDocument;
typedef ILU_C_OBJECT NgDocument_WebDocument;
typedef ILU_C_OBJECT NgDocument_RenderingAndPropertiesSink;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _NgDocument_PropertiesProblemReport_union NgDocument_PropertiesProblemReport;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* union "NgDocument_PropertiesProblemReport" */

struct _NgDocument_PropertiesProblemReport_union {
	CORBA_short _d;
	union {
		NgBasic_ExceptionInformation wouldBlock;	/* 0 */
		NgProperty_PropertyNames unknownProperties;	/* 1 */
	} _u;
};
NgDocument_PropertiesProblemReport *
  CORBA_sequence_NgDocument_PropertiesProblemReport_allocbuf (CORBA_unsigned_long /* count */);

NgDocument_RenderingAndPropertiesSink *
  CORBA_sequence_NgDocument_RenderingAndPropertiesSink_allocbuf (CORBA_unsigned_long /* count */);

NgDocument_WebDocument *
  CORBA_sequence_NgDocument_WebDocument_allocbuf (CORBA_unsigned_long /* count */);

NgDocument_HTTPCompatibleWebDocument *
  CORBA_sequence_NgDocument_HTTPCompatibleWebDocument_allocbuf (CORBA_unsigned_long /* count */);

NgDocument_PutableWebDocument *
  CORBA_sequence_NgDocument_PutableWebDocument_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*======================== exceptions ==================================*/



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "NgDocument_HTTPCompatibleWebDocument"  ------------*/

#define NgDocument_HTTPCompatibleWebDocument__MSType _NgDocument_HTTPCompatibleWebDocument__ILUType

NgDocument_HTTPCompatibleWebDocument
  NgDocument_HTTPCompatibleWebDocument__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgDocument_HTTPCompatibleWebDocument__SetUserData (NgDocument_HTTPCompatibleWebDocument /* self */, void * /* userData */);
void *
  NgDocument_HTTPCompatibleWebDocument__GetUserData (NgDocument_HTTPCompatibleWebDocument /* self */);

extern NgDocument_HTTPCompatibleWebDocument
  NgDocument_HTTPCompatibleWebDocument__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgDocument_HTTPCompatibleWebDocument class */

extern NgDocument_HTTPCompatibleWebDocument
  NgDocument_HTTPCompatibleWebDocument__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgDocument_HTTPCompatibleWebDocument_GetInterfaceDefinitionSource (NgDocument_HTTPCompatibleWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_RenderingPreferences* server_NgDocument_HTTPCompatibleWebDocument_GetAvailableRenderings (NgDocument_HTTPCompatibleWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgDocument_HTTPCompatibleWebDocument_GetRendering (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_HTTPCompatibleWebDocument_SendRendering (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_HTTPCompatibleWebDocument_SendRenderingSynched (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern NgBasic_String server_NgDocument_HTTPCompatibleWebDocument_GetInterfaceDefinitionSource (NgDocument_HTTPCompatibleWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgProperty_PropertySequence* server_NgDocument_HTTPCompatibleWebDocument_GetProperties (NgDocument_HTTPCompatibleWebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgDocument_HTTPCompatibleWebDocument_GetRenderingAndProperties (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_HTTPCompatibleWebDocument_SendRenderingAndProperties (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_HTTPCompatibleWebDocument_SendRenderingAndPropertiesSynched (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern iluhttp_Response* server_NgDocument_HTTPCompatibleWebDocument_GET (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern iluhttp_Response* server_NgDocument_HTTPCompatibleWebDocument_HEAD (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern iluhttp_Response* server_NgDocument_HTTPCompatibleWebDocument_POST (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern void NgDocument_HTTPCompatibleWebDocument__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgDocument_HTTPCompatibleWebDocument__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgDocument_HTTPCompatibleWebDocument__MakeClass(
  NgRendering_Rendering* (*NgDocument_WebDocument_GetRenderingAndProperties__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndProperties__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_GET__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_HEAD__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_POST__Impl)
     (NgDocument_HTTPCompatibleWebDocument _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/




/*-----------------------------------------------------------------------*/
/*-----  object type "NgDocument_PutableWebDocument"  -------------------*/

#define NgDocument_PutableWebDocument__MSType _NgDocument_PutableWebDocument__ILUType

NgDocument_PutableWebDocument
  NgDocument_PutableWebDocument__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgDocument_PutableWebDocument__SetUserData (NgDocument_PutableWebDocument /* self */, void * /* userData */);
void *
  NgDocument_PutableWebDocument__GetUserData (NgDocument_PutableWebDocument /* self */);

extern NgDocument_PutableWebDocument
  NgDocument_PutableWebDocument__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgDocument_PutableWebDocument class */

extern NgDocument_PutableWebDocument
  NgDocument_PutableWebDocument__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgDocument_PutableWebDocument_GetInterfaceDefinitionSource (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_RenderingPreferences* server_NgDocument_PutableWebDocument_GetAvailableRenderings (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgDocument_PutableWebDocument_GetRendering (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_SendRendering (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_SendRenderingSynched (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern NgBasic_String server_NgDocument_PutableWebDocument_GetInterfaceDefinitionSource (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgProperty_PropertySequence* server_NgDocument_PutableWebDocument_GetProperties (NgDocument_PutableWebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgDocument_PutableWebDocument_GetRenderingAndProperties (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_SendRenderingAndProperties (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_SendRenderingAndPropertiesSynched (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern NgBasic_String server_NgDocument_PutableWebDocument_GetInterfaceDefinitionSource (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_RenderingPreferences* server_NgDocument_PutableWebDocument_GetAvailableRenderings (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgDocument_PutableWebDocument_GetRendering (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_SendRendering (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_SendRenderingSynched (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_PutRendering (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status);

extern NgBasic_String server_NgDocument_PutableWebDocument_GetInterfaceDefinitionSource (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgProperty_PropertySequence* server_NgDocument_PutableWebDocument_GetProperties (NgDocument_PutableWebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_PutProperties (NgDocument_PutableWebDocument _handle, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_PutableWebDocument_PutRenderingAndProperties (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status);

extern void NgDocument_PutableWebDocument__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgDocument_PutableWebDocument__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgDocument_PutableWebDocument__MakeClass(
  void (*NgDocument_PutableWebDocument_PutRenderingAndProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgDocument_WebDocument_GetRenderingAndProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_PutableWebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_PutableRenderable_PutRendering__Impl)
     (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, ILU_C_ENVIRONMENT *_status),
  void (*NgProperty_PutablePropertySet_PutProperties__Impl)
     (NgDocument_PutableWebDocument _handle, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void  /* exceptions:  NoRenderingMatch UnknownPropertyNames WouldBlock Conflict ObjectNotExist */
  NgDocument_PutableWebDocument_PutRenderingAndProperties (NgDocument_PutableWebDocument, NgRendering_Rendering*, NgProperty_PropertyModificationSequence*, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "NgDocument_WebDocument"  --------------------------*/

#define NgDocument_WebDocument__MSType _NgDocument_WebDocument__ILUType

NgDocument_WebDocument
  NgDocument_WebDocument__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgDocument_WebDocument__SetUserData (NgDocument_WebDocument /* self */, void * /* userData */);
void *
  NgDocument_WebDocument__GetUserData (NgDocument_WebDocument /* self */);

extern NgDocument_WebDocument
  NgDocument_WebDocument__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgDocument_WebDocument class */

extern NgDocument_WebDocument
  NgDocument_WebDocument__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgDocument_WebDocument_GetInterfaceDefinitionSource (NgDocument_WebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_RenderingPreferences* server_NgDocument_WebDocument_GetAvailableRenderings (NgDocument_WebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgDocument_WebDocument_GetRendering (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_WebDocument_SendRendering (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_WebDocument_SendRenderingSynched (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern NgBasic_String server_NgDocument_WebDocument_GetInterfaceDefinitionSource (NgDocument_WebDocument _handle, ILU_C_ENVIRONMENT *_status);

extern NgProperty_PropertySequence* server_NgDocument_WebDocument_GetProperties (NgDocument_WebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgDocument_WebDocument_GetRenderingAndProperties (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_WebDocument_SendRenderingAndProperties (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_WebDocument_SendRenderingAndPropertiesSynched (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern void NgDocument_WebDocument__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgDocument_WebDocument__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgDocument_WebDocument__MakeClass(
  NgRendering_Rendering* (*NgDocument_WebDocument_GetRenderingAndProperties__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndProperties__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_WebDocument_SendRenderingAndPropertiesSynched__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgRendering_RenderingPreferences* (*NgRendering_Renderable_GetAvailableRenderings__Impl)
     (NgDocument_WebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgRendering_Rendering* (*NgRendering_Renderable_GetRendering__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRendering__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_Renderable_SendRenderingSynched__Impl)
     (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgRendering_RenderingSink renderSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_WebDocument _handle, ILU_C_ENVIRONMENT *_status),
  NgProperty_PropertySequence* (*NgProperty_PropertySet_GetProperties__Impl)
     (NgDocument_WebDocument _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern NgRendering_Rendering*  /* exceptions:  NoRenderingMatch UnknownPropertyNames WouldBlock ObjectNotExist */
  NgDocument_WebDocument_GetRenderingAndProperties (NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgCache_OptionalResponseCacheControl*, NgProperty_PropertyNames*, NgProperty_PropertySequence**, ILU_C_ENVIRONMENT *);

extern void
  NgDocument_WebDocument_SendRenderingAndProperties (NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgProperty_PropertyNames*, NgDocument_RenderingAndPropertiesSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);

extern void
  NgDocument_WebDocument_SendRenderingAndPropertiesSynched (NgDocument_WebDocument, NgRendering_RenderingPreferences*, NgCache_OptionalRequestCacheControl, NgProperty_PropertyNames*, NgDocument_RenderingAndPropertiesSink, NgBasic_OptionalCardinal, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "NgDocument_RenderingAndPropertiesSink"  -----------*/

#define NgDocument_RenderingAndPropertiesSink__MSType _NgDocument_RenderingAndPropertiesSink__ILUType

NgDocument_RenderingAndPropertiesSink
  NgDocument_RenderingAndPropertiesSink__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgDocument_RenderingAndPropertiesSink__SetUserData (NgDocument_RenderingAndPropertiesSink /* self */, void * /* userData */);
void *
  NgDocument_RenderingAndPropertiesSink__GetUserData (NgDocument_RenderingAndPropertiesSink /* self */);

extern NgDocument_RenderingAndPropertiesSink
  NgDocument_RenderingAndPropertiesSink__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgDocument_RenderingAndPropertiesSink class */

extern NgDocument_RenderingAndPropertiesSink
  NgDocument_RenderingAndPropertiesSink__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgDocument_RenderingAndPropertiesSink_GetInterfaceDefinitionSource (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_RegisterSourceControl (NgDocument_RenderingAndPropertiesSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_Done (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_RegisterResponseCacheControl (NgDocument_RenderingAndPropertiesSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_RenderingProblem (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_ReceiveRendering (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_ReceiveRenderingChunk (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status);

extern NgBasic_OptionalCardinal server_NgDocument_RenderingAndPropertiesSink_Resynchronize (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_PropertiesProblem (NgDocument_RenderingAndPropertiesSink _handle, NgDocument_PropertiesProblemReport* report, ILU_C_ENVIRONMENT *_status);

extern void server_NgDocument_RenderingAndPropertiesSink_ReceiveProperties (NgDocument_RenderingAndPropertiesSink _handle, NgProperty_PropertySequence* theproperties, ILU_C_ENVIRONMENT *_status);

extern void NgDocument_RenderingAndPropertiesSink__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgDocument_RenderingAndPropertiesSink__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgDocument_RenderingAndPropertiesSink__MakeClass(
  void (*NgDocument_RenderingAndPropertiesSink_PropertiesProblem__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgDocument_PropertiesProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgDocument_RenderingAndPropertiesSink_ReceiveProperties__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgProperty_PropertySequence* theproperties, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RegisterResponseCacheControl__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RenderingProblem__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRendering__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRenderingChunk__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status),
  NgBasic_OptionalCardinal (*NgRendering_RenderingSink_Resynchronize__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgDocument_RenderingAndPropertiesSink _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void
  NgDocument_RenderingAndPropertiesSink_PropertiesProblem (NgDocument_RenderingAndPropertiesSink, NgDocument_PropertiesProblemReport*, ILU_C_ENVIRONMENT *);

extern void
  NgDocument_RenderingAndPropertiesSink_ReceiveProperties (NgDocument_RenderingAndPropertiesSink, NgProperty_PropertySequence*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void NgDocument__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _NgDocument_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _NgDocument_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _NgDocument_HTTPCompatibleWebDocument__IoFns;
#define TC_NgDocument_HTTPCompatibleWebDocument (& _NgDocument_HTTPCompatibleWebDocument__IoFns)
extern void NgDocument_HTTPCompatibleWebDocument__Free (NgDocument_HTTPCompatibleWebDocument*);
extern struct _ILU_C_IoFnsRegistration_s _NgDocument_PutableWebDocument__IoFns;
#define TC_NgDocument_PutableWebDocument (& _NgDocument_PutableWebDocument__IoFns)
extern void NgDocument_PutableWebDocument__Free (NgDocument_PutableWebDocument*);
extern struct _ILU_C_IoFnsRegistration_s _NgDocument_WebDocument__IoFns;
#define TC_NgDocument_WebDocument (& _NgDocument_WebDocument__IoFns)
extern void NgDocument_WebDocument__Free (NgDocument_WebDocument*);
extern struct _ILU_C_IoFnsRegistration_s _NgDocument_RenderingAndPropertiesSink__IoFns;
#define TC_NgDocument_RenderingAndPropertiesSink (& _NgDocument_RenderingAndPropertiesSink__IoFns)
extern void NgDocument_RenderingAndPropertiesSink__Free (NgDocument_RenderingAndPropertiesSink*);
extern struct _ILU_C_IoFnsRegistration_s _NgDocument_PropertiesProblemReport__IoFns;
#define TC_NgDocument_PropertiesProblemReport (& _NgDocument_PropertiesProblemReport__IoFns)
extern void _NgDocument_PropertiesProblemReport__Output (ilu_Call, NgDocument_PropertiesProblemReport*, ilu_Error *);
extern ilu_cardinal _NgDocument_PropertiesProblemReport__SizeOf (ilu_Call, NgDocument_PropertiesProblemReport*, ilu_Error *);
extern NgDocument_PropertiesProblemReport* _NgDocument_PropertiesProblemReport__Input (ilu_Call, NgDocument_PropertiesProblemReport*, ilu_Error *);
extern void NgDocument_PropertiesProblemReport__Free (NgDocument_PropertiesProblemReport*);
NgDocument_PropertiesProblemReport* NgDocument_PropertiesProblemReport__alloc (void);

extern ilu_Class _NgDocument_HTTPCompatibleWebDocument__ILUType;

extern ilu_Class _NgDocument_PutableWebDocument__ILUType;
extern void _NgDocument_PutableWebDocument_PutRenderingAndProperties__clientstub (NgDocument_PutableWebDocument _handle, NgRendering_Rendering* renderingInput, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _NgDocument_WebDocument__ILUType;
extern NgRendering_Rendering* _NgDocument_WebDocument_GetRenderingAndProperties__clientstub (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgCache_OptionalResponseCacheControl* responseCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgProperty_PropertySequence** theproperties, ILU_C_ENVIRONMENT *_status);
extern void _NgDocument_WebDocument_SendRenderingAndProperties__clientstub (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);
extern void _NgDocument_WebDocument_SendRenderingAndPropertiesSynched__clientstub (NgDocument_WebDocument _handle, NgRendering_RenderingPreferences* renderingPreferences, NgCache_OptionalRequestCacheControl requestCacheInfo, NgProperty_PropertyNames* propertiesToGet, NgDocument_RenderingAndPropertiesSink renderPropSink, NgBasic_OptionalCardinal suggestedChunkSize, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _NgDocument_RenderingAndPropertiesSink__ILUType;
extern void _NgDocument_RenderingAndPropertiesSink_PropertiesProblem__clientstub (NgDocument_RenderingAndPropertiesSink _handle, NgDocument_PropertiesProblemReport* report, ILU_C_ENVIRONMENT *_status);
extern void _NgDocument_RenderingAndPropertiesSink_ReceiveProperties__clientstub (NgDocument_RenderingAndPropertiesSink _handle, NgProperty_PropertySequence* theproperties, ILU_C_ENVIRONMENT *_status);

extern void _NgDocument__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __NgDocument_h_ */
