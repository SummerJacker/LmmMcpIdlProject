/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:51 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/hello-world/hello-world.isl" of Wed Jul 30 16:24:59 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __hello_world_h_
#define __hello_world_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                           hello-world                            ***/
/************************************************************************/
/************************************************************************/

extern void hello_world__Initialize(void);
extern void hello_world__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT hello_world_service;



/*======================================================================*/
/*========================= typedefs ===================================*/




/*======================================================================*/
/*=============== non-object type declarations =========================*/

hello_world_service *
  CORBA_sequence_hello_world_service_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "hello_world_service"  -----------------------------*/

#define hello_world_service__MSType _hello_world_service__ILUType

hello_world_service
  hello_world_service__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  hello_world_service__SetUserData (hello_world_service /* self */, void * /* userData */);
void *
  hello_world_service__GetUserData (hello_world_service /* self */);

extern hello_world_service
  hello_world_service__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default hello_world_service class */

extern hello_world_service
  hello_world_service__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern ilu_CString server_hello_world_service_hello_world (hello_world_service _handle, ilu_CString inarg, ILU_C_ENVIRONMENT *_status);

extern void hello_world_service__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class hello_world_service__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class hello_world_service__MakeClass(
  ilu_CString (*hello_world_service_hello_world__Impl)
     (hello_world_service _handle, ilu_CString inarg, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern ilu_CString
  hello_world_service_hello_world (hello_world_service, ilu_CString, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void hello_world__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _hello_world_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _hello_world_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _hello_world_service__IoFns;
#define TC_hello_world_service (& _hello_world_service__IoFns)
extern void hello_world_service__Free (hello_world_service*);

extern ilu_Class _hello_world_service__ILUType;
extern ilu_CString _hello_world_service_hello_world__clientstub (hello_world_service _handle, ilu_CString inarg, ILU_C_ENVIRONMENT *_status);

extern void _hello_world__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __hello_world_h_ */
