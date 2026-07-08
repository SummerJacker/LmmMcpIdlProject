/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgStream.isl" of Fri Aug 01 13:29:38 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __NgStream_h_
#define __NgStream_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "NgBasic.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             NgStream                             ***/
/************************************************************************/
/************************************************************************/

extern void NgStream__Initialize(void);
extern void NgStream__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT NgStream_DataSink;
typedef ILU_C_OBJECT NgStream_DataSource;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef NgStream_DataSource NgStream_OptionalDataSource;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

NgStream_DataSource *
  CORBA_sequence_NgStream_DataSource_allocbuf (CORBA_unsigned_long /* count */);

NgStream_DataSink *
  CORBA_sequence_NgStream_DataSink_allocbuf (CORBA_unsigned_long /* count */);

NgStream_OptionalDataSource *
  CORBA_sequence_NgStream_OptionalDataSource_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "NgStream_DataSink"  -------------------------------*/

#define NgStream_DataSink__MSType _NgStream_DataSink__ILUType

NgStream_DataSink
  NgStream_DataSink__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgStream_DataSink__SetUserData (NgStream_DataSink /* self */, void * /* userData */);
void *
  NgStream_DataSink__GetUserData (NgStream_DataSink /* self */);

extern NgStream_DataSink
  NgStream_DataSink__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgStream_DataSink class */

extern NgStream_DataSink
  NgStream_DataSink__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgStream_DataSink_GetInterfaceDefinitionSource (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgStream_DataSink_RegisterSourceControl (NgStream_DataSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status);

extern void server_NgStream_DataSink_Done (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status);

extern void NgStream_DataSink__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgStream_DataSink__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgStream_DataSink__MakeClass(
  void (*NgStream_DataSink_RegisterSourceControl__Impl)
     (NgStream_DataSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSink_Done__Impl)
     (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void
  NgStream_DataSink_RegisterSourceControl (NgStream_DataSink, NgStream_DataSource, ILU_C_ENVIRONMENT *);

extern void
  NgStream_DataSink_Done (NgStream_DataSink, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "NgStream_DataSource"  -----------------------------*/

#define NgStream_DataSource__MSType _NgStream_DataSource__ILUType

NgStream_DataSource
  NgStream_DataSource__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  NgStream_DataSource__SetUserData (NgStream_DataSource /* self */, void * /* userData */);
void *
  NgStream_DataSource__GetUserData (NgStream_DataSource /* self */);

extern NgStream_DataSource
  NgStream_DataSource__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default NgStream_DataSource class */

extern NgStream_DataSource
  NgStream_DataSource__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern NgBasic_String server_NgStream_DataSource_GetInterfaceDefinitionSource (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgStream_DataSource_Abort (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgStream_DataSource_Pause (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgStream_DataSource_Resume (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status);

extern void server_NgStream_DataSource_Resend (NgStream_DataSource _handle, NgBasic_UnsignedInclusiveInterval* repeatRange, ILU_C_ENVIRONMENT *_status);

extern void server_NgStream_DataSource_SuggestChunkSize (NgStream_DataSource _handle, CORBA_unsigned_long suggestedSize, ILU_C_ENVIRONMENT *_status);

extern void NgStream_DataSource__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class NgStream_DataSource__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class NgStream_DataSource__MakeClass(
  void (*NgStream_DataSource_Abort__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_Pause__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_Resume__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_Resend__Impl)
     (NgStream_DataSource _handle, NgBasic_UnsignedInclusiveInterval* repeatRange, ILU_C_ENVIRONMENT *_status),
  void (*NgStream_DataSource_SuggestChunkSize__Impl)
     (NgStream_DataSource _handle, CORBA_unsigned_long suggestedSize, ILU_C_ENVIRONMENT *_status),
  NgBasic_String (*NgBasic_NgObject_GetInterfaceDefinitionSource__Impl)
     (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void
  NgStream_DataSource_Abort (NgStream_DataSource, ILU_C_ENVIRONMENT *);

extern void
  NgStream_DataSource_Pause (NgStream_DataSource, ILU_C_ENVIRONMENT *);

extern void
  NgStream_DataSource_Resume (NgStream_DataSource, ILU_C_ENVIRONMENT *);

extern void
  NgStream_DataSource_Resend (NgStream_DataSource, NgBasic_UnsignedInclusiveInterval*, ILU_C_ENVIRONMENT *);

extern void
  NgStream_DataSource_SuggestChunkSize (NgStream_DataSource, CORBA_unsigned_long, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void NgStream__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _NgStream_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _NgStream_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _NgStream_DataSink__IoFns;
#define TC_NgStream_DataSink (& _NgStream_DataSink__IoFns)
extern void NgStream_DataSink__Free (NgStream_DataSink*);
extern struct _ILU_C_IoFnsRegistration_s _NgStream_OptionalDataSource__IoFns;
#define TC_NgStream_OptionalDataSource (& _NgStream_OptionalDataSource__IoFns)
extern void _NgStream_OptionalDataSource__Output (ilu_Call, NgStream_OptionalDataSource, ilu_Error *);
extern ilu_cardinal _NgStream_OptionalDataSource__SizeOf (ilu_Call, NgStream_OptionalDataSource, ilu_Error *);
extern NgStream_OptionalDataSource* _NgStream_OptionalDataSource__Input (ilu_Call, NgStream_OptionalDataSource*, ilu_Error *);
extern void NgStream_OptionalDataSource__Free (NgStream_OptionalDataSource*);
NgStream_OptionalDataSource* NgStream_OptionalDataSource__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _NgStream_DataSource__IoFns;
#define TC_NgStream_DataSource (& _NgStream_DataSource__IoFns)
extern void NgStream_DataSource__Free (NgStream_DataSource*);

extern ilu_Class _NgStream_DataSink__ILUType;
extern void _NgStream_DataSink_RegisterSourceControl__clientstub (NgStream_DataSink _handle, NgStream_DataSource thesource, ILU_C_ENVIRONMENT *_status);
extern void _NgStream_DataSink_Done__clientstub (NgStream_DataSink _handle, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _NgStream_DataSource__ILUType;
extern void _NgStream_DataSource_Abort__clientstub (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status);
extern void _NgStream_DataSource_Pause__clientstub (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status);
extern void _NgStream_DataSource_Resume__clientstub (NgStream_DataSource _handle, ILU_C_ENVIRONMENT *_status);
extern void _NgStream_DataSource_Resend__clientstub (NgStream_DataSource _handle, NgBasic_UnsignedInclusiveInterval* repeatRange, ILU_C_ENVIRONMENT *_status);
extern void _NgStream_DataSource_SuggestChunkSize__clientstub (NgStream_DataSource _handle, CORBA_unsigned_long suggestedSize, ILU_C_ENVIRONMENT *_status);

extern void _NgStream__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __NgStream_h_ */
