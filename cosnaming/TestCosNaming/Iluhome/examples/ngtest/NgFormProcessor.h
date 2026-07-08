/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/ngform.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "ianacharsets.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngcache.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngrendering.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __NgFormProcessor_h_
#define __NgFormProcessor_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "NgBasic.h"
#include "IANA_Charsets_Registry.h"
#include "NgCache.h"
#include "NgRendering.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                         NgFormProcessor                          ***/
/************************************************************************/
/************************************************************************/

extern void NgFormProcessor__Initialize(void);
extern void NgFormProcessor__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT NgFormProcessor_FormProcessor;
typedef ILU_C_OBJECT NgFormProcessor_ProcessedFormSink;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _NgFormProcessor_FormInputElementSequence__sequence NgFormProcessor_FormInputElementSequence;
typedef NgBasic_NameSequence NgFormProcessor_FormInputElementNames;
typedef struct _NgFormProcessor_FormProblemReport_union NgFormProcessor_FormProblemReport;
typedef NgFormProcessor_FormProblemReport *NgFormProcessor_OptionalFormProblemReport;
typedef NgBasic_NameValuePair NgFormProcessor_FormInputElement;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* sequence type "NgFormProcessor_FormInputElementSequence" */
struct _NgFormProcessor_FormInputElementSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 NgFormProcessor_FormInputElement *_buffer;
};
void NgFormProcessor_FormInputElementSequence_Every (NgFormProcessor_FormInputElementSequence *h, void (*f)(NgFormProcessor_FormInputElement*, void *, ilu_Error *), void *);
void NgFormProcessor_FormInputElementSequence_Append (NgFormProcessor_FormInputElementSequence *h, NgFormProcessor_FormInputElement* item, ilu_Error *);
void NgFormProcessor_FormInputElementSequence_Push (NgFormProcessor_FormInputElementSequence *h, NgFormProcessor_FormInputElement* item);
void NgFormProcessor_FormInputElementSequence_Pop (NgFormProcessor_FormInputElementSequence *h, NgFormProcessor_FormInputElement* item);
CORBA_unsigned_long NgFormProcessor_FormInputElementSequence_Length (NgFormProcessor_FormInputElementSequence *);
NgFormProcessor_FormInputElement * NgFormProcessor_FormInputElementSequence_Nth (NgFormProcessor_FormInputElementSequence *, CORBA_unsigned_long);
NgFormProcessor_FormInputElementSequence * NgFormProcessor_FormInputElementSequence_Create (CORBA_unsigned_long /* size */, NgFormProcessor_FormInputElement*  /* init val */);
void NgFormProcessor_FormInputElementSequence_Init (NgFormProcessor_FormInputElementSequence * /* seq */, CORBA_unsigned_long /* size */, NgFormProcessor_FormInputElement*  /* init val */);
NgFormProcessor_FormInputElementSequence *
  CORBA_sequence_NgFormProcessor_FormInputElementSequence_allocbuf (CORBA_unsigned_long /* count */);

/* "NgFormProcessor_FormInputElementNames" alias for "NgBasic_NameSequence" */
#define NgFormProcessor_FormInputElementNames_Length NgBasic_NameSequence_Length
#define NgFormProcessor_FormInputElementNames_Nth NgBasic_NameSequence_Nth
#define NgFormProcessor_FormInputElementNames_Every NgBasic_NameSequence_Every
#define NgFormProcessor_FormInputElementNames_Append NgBasic_NameSequence_Append
#define NgFormProcessor_FormInputElementNames_Push NgBasic_NameSequence_Push
#define NgFormProcessor_FormInputElementNames_Pop NgBasic_NameSequence_Pop
#define NgFormProcessor_FormInputElementNames_Init NgBasic_NameSequence_Init
#define NgFormProcessor_FormInputElementNames_Create NgBasic_NameSequence_Create
#define NgFormProcessor_FormInputElementNames__Free NgBasic_NameSequence__Free
#define NgFormProcessor_FormInputElementNames__alloc NgBasic_NameSequence__alloc
#define CORBA_sequence_NgFormProcessor_FormInputElementNames_allocbuf CORBA_sequence_NgBasic_NameSequence_allocbuf

/* union "NgFormProcessor_FormProblemReport" */

struct _NgFormProcessor_FormProblemReport_union {
	CORBA_short _d;
	union {
		NgFormProcessor_FormInputElementNames invalidEntries;	/* 0 */
		NgBasic_ExceptionInformation conflict;	/* 1 */
		NgBasic_ExceptionInformation objectNotExist;	/* 2 */
	} _u;
};
NgFormProcessor_FormProblemReport *
  CORBA_sequence_NgFormProcessor_FormProblemReport_allocbuf (CORBA_unsigned_long /* count */);

NgFormProcessor_ProcessedFormSink *
  CORBA_sequence_NgFormProcessor_ProcessedFormSink_allocbuf (CORBA_unsigned_long /* count */);

NgFormProcessor_FormProcessor *
  CORBA_sequence_NgFormProcessor_FormProcessor_allocbuf (CORBA_unsigned_long /* count */);

NgFormProcessor_OptionalFormProblemReport *
  CORBA_sequence_NgFormProcessor_OptionalFormProblemReport_allocbuf (CORBA_unsigned_long /* count */);

/* "NgFormProcessor_FormInputElement" alias for "NgBasic_NameValuePair" */
#define CORBA_sequence_NgFormProcessor_FormInputElement_allocbuf CORBA_sequence_NgBasic_NameValuePair_allocbuf



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _NgFormProcessor__Exception_InvalidFormEntries;
#define ex_NgFormProcessor_InvalidFormEntries _NgFormProcessor__Exception_InvalidFormEntries


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "NgFormProcessor_FormProcessor"  -------------------*/

#define NgFormProcessor_FormProcessor__MSType _NgFormProcessor_FormProcessor__ILUType

NgFormProcessor_FormProcessor
  NgFormProcessor_FormProcessor__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgFormProcessor_FormProcessor__SetUserData (NgFormProcessor_FormProcessor /* self */, void * /* userData */);
void *
  NgFormProcessor_FormProcessor__GetUserData (NgFormProcessor_FormProcessor /* self */);

extern NgFormProcessor_FormProcessor
  NgFormProcessor_FormProcessor__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgFormProcessor_FormProcessor class */

extern NgFormProcessor_FormProcessor
  NgFormProcessor_FormProcessor__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgFormProcessor_FormProcessor_GetInterfaceDefinitionSource (NgFormProcessor_FormProcessor _handle, ILU_C_ENVIRONMENT *_status);

extern NgRendering_Rendering* server_NgFormProcessor_FormProcessor_ProcessForm (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_FormProcessor_SendFormReply (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_FormProcessor_SendFormReplySynched (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status);

extern void NgFormProcessor_FormProcessor__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgFormProcessor_FormProcessor__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgFormProcessor_FormProcessor__MakeClass(
  NgRendering_Rendering* (*NgFormProcessor_FormProcessor_ProcessForm__Impl)
     (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgFormProcessor_FormProcessor_SendFormReply__Impl)
     (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status),
  void (*NgFormProcessor_FormProcessor_SendFormReplySynched__Impl)
     (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgFormProcessor_FormProcessor _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern NgRendering_Rendering*  /* exceptions:  InvalidFormEntries WouldBlock Conflict ObjectNotExist */
  NgFormProcessor_FormProcessor_ProcessForm (NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgCache_OptionalResponseCacheControl*, ILU_C_ENVIRONMENT *);

extern void
  NgFormProcessor_FormProcessor_SendFormReply (NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgFormProcessor_ProcessedFormSink, ILU_C_ENVIRONMENT *);

extern void
  NgFormProcessor_FormProcessor_SendFormReplySynched (NgFormProcessor_FormProcessor, NgFormProcessor_FormInputElementSequence*, NgFormProcessor_ProcessedFormSink, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "NgFormProcessor_ProcessedFormSink"  ---------------*/

#define NgFormProcessor_ProcessedFormSink__MSType _NgFormProcessor_ProcessedFormSink__ILUType

NgFormProcessor_ProcessedFormSink
  NgFormProcessor_ProcessedFormSink__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgFormProcessor_ProcessedFormSink__SetUserData (NgFormProcessor_ProcessedFormSink /* self */, void * /* userData */);
void *
  NgFormProcessor_ProcessedFormSink__GetUserData (NgFormProcessor_ProcessedFormSink /* self */);

extern NgFormProcessor_ProcessedFormSink
  NgFormProcessor_ProcessedFormSink__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgFormProcessor_ProcessedFormSink class */

extern NgFormProcessor_ProcessedFormSink
  NgFormProcessor_ProcessedFormSink__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgFormProcessor_ProcessedFormSink_GetInterfaceDefinitionSource (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_ProcessedFormSink_RegisterSourceControl (NgFormProcessor_ProcessedFormSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_ProcessedFormSink_Done (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_ProcessedFormSink_RegisterResponseCacheControl (NgFormProcessor_ProcessedFormSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_ProcessedFormSink_RenderingProblem (NgFormProcessor_ProcessedFormSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_ProcessedFormSink_ReceiveRendering (NgFormProcessor_ProcessedFormSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_ProcessedFormSink_ReceiveRenderingChunk (NgFormProcessor_ProcessedFormSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status);

extern NgBasic_OptionalCardinal server_NgFormProcessor_ProcessedFormSink_Resynchronize (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgFormProcessor_ProcessedFormSink_FormProblem (NgFormProcessor_ProcessedFormSink _handle, NgFormProcessor_FormProblemReport* report, ILU_C_ENVIRONMENT *_status);

extern void NgFormProcessor_ProcessedFormSink__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgFormProcessor_ProcessedFormSink__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgFormProcessor_ProcessedFormSink__MakeClass(
  void (*NgFormProcessor_ProcessedFormSink_FormProblem__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgFormProcessor_FormProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RegisterResponseCacheControl__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgCache_OptionalResponseCacheControl responseCacheInfo, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_RenderingProblem__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgRendering_RenderingProblemReport* report, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRendering__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgRendering_Rendering* therendering, ILU_C_ENVIRONMENT *_status),
  void (*NgRendering_RenderingSink_ReceiveRenderingChunk__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgRendering_RenderingChunk* thechunk, ILU_C_ENVIRONMENT *_status),
  NgBasic_OptionalCardinal (*NgRendering_RenderingSink_Resynchronize__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgFormProcessor_ProcessedFormSink _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void
  NgFormProcessor_ProcessedFormSink_FormProblem (NgFormProcessor_ProcessedFormSink, NgFormProcessor_FormProblemReport*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void NgFormProcessor__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _NgFormProcessor_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _NgFormProcessor_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_FormProcessor__IoFns;
#define TC_NgFormProcessor_FormProcessor (& _NgFormProcessor_FormProcessor__IoFns)
extern void NgFormProcessor_FormProcessor__Free (NgFormProcessor_FormProcessor*);
extern struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_ProcessedFormSink__IoFns;
#define TC_NgFormProcessor_ProcessedFormSink (& _NgFormProcessor_ProcessedFormSink__IoFns)
extern void NgFormProcessor_ProcessedFormSink__Free (NgFormProcessor_ProcessedFormSink*);
extern struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_OptionalFormProblemReport__IoFns;
#define TC_NgFormProcessor_OptionalFormProblemReport (& _NgFormProcessor_OptionalFormProblemReport__IoFns)
extern void _NgFormProcessor_OptionalFormProblemReport__Output (ilu_Call, NgFormProcessor_OptionalFormProblemReport, ilu_Error *);
extern ilu_cardinal _NgFormProcessor_OptionalFormProblemReport__SizeOf (ilu_Call, NgFormProcessor_OptionalFormProblemReport, ilu_Error *);
extern NgFormProcessor_OptionalFormProblemReport* _NgFormProcessor_OptionalFormProblemReport__Input (ilu_Call, NgFormProcessor_OptionalFormProblemReport*, ilu_Error *);
extern void NgFormProcessor_OptionalFormProblemReport__Free (NgFormProcessor_OptionalFormProblemReport*);
NgFormProcessor_OptionalFormProblemReport* NgFormProcessor_OptionalFormProblemReport__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_FormProblemReport__IoFns;
#define TC_NgFormProcessor_FormProblemReport (& _NgFormProcessor_FormProblemReport__IoFns)
extern void _NgFormProcessor_FormProblemReport__Output (ilu_Call, NgFormProcessor_FormProblemReport*, ilu_Error *);
extern ilu_cardinal _NgFormProcessor_FormProblemReport__SizeOf (ilu_Call, NgFormProcessor_FormProblemReport*, ilu_Error *);
extern NgFormProcessor_FormProblemReport* _NgFormProcessor_FormProblemReport__Input (ilu_Call, NgFormProcessor_FormProblemReport*, ilu_Error *);
extern void NgFormProcessor_FormProblemReport__Free (NgFormProcessor_FormProblemReport*);
NgFormProcessor_FormProblemReport* NgFormProcessor_FormProblemReport__alloc (void);
#define _NgFormProcessor_FormInputElementNames__IoFns _NgBasic_NameSequence__IoFns
#define TC_NgFormProcessor_FormInputElementNames (& _NgFormProcessor_FormInputElementNames__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _NgFormProcessor_FormInputElementSequence__IoFns;
#define TC_NgFormProcessor_FormInputElementSequence (& _NgFormProcessor_FormInputElementSequence__IoFns)
extern void _NgFormProcessor_FormInputElementSequence__Output (ilu_Call, NgFormProcessor_FormInputElementSequence*, ilu_Error *);
extern ilu_cardinal _NgFormProcessor_FormInputElementSequence__SizeOf (ilu_Call, NgFormProcessor_FormInputElementSequence*, ilu_Error *);
extern NgFormProcessor_FormInputElementSequence* _NgFormProcessor_FormInputElementSequence__Input (ilu_Call, NgFormProcessor_FormInputElementSequence*, ilu_Error *);
extern void NgFormProcessor_FormInputElementSequence__Free (NgFormProcessor_FormInputElementSequence*);
NgFormProcessor_FormInputElementSequence* NgFormProcessor_FormInputElementSequence__alloc (void);
#define _NgFormProcessor_FormInputElement__IoFns _NgBasic_NameValuePair__IoFns
#define TC_NgFormProcessor_FormInputElement (& _NgFormProcessor_FormInputElement__IoFns)

extern ilu_Class _NgFormProcessor_FormProcessor__ILUType;
extern NgRendering_Rendering* _NgFormProcessor_FormProcessor_ProcessForm__clientstub (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgCache_OptionalResponseCacheControl* responseCacheInfo, ILU_C_ENVIRONMENT *_status);
extern void _NgFormProcessor_FormProcessor_SendFormReply__clientstub (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status);
extern void _NgFormProcessor_FormProcessor_SendFormReplySynched__clientstub (NgFormProcessor_FormProcessor _handle, NgFormProcessor_FormInputElementSequence* formEntries, NgFormProcessor_ProcessedFormSink formSink, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _NgFormProcessor_ProcessedFormSink__ILUType;
extern void _NgFormProcessor_ProcessedFormSink_FormProblem__clientstub (NgFormProcessor_ProcessedFormSink _handle, NgFormProcessor_FormProblemReport* report, ILU_C_ENVIRONMENT *_status);

extern void _NgFormProcessor__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __NgFormProcessor_h_ */
