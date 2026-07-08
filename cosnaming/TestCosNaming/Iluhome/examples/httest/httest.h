/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:28 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/httest/httest.isl" of Thu Aug 07 21:51:07 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/httest/iluhttp.isl" of Mon Jul 21 17:22:19 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/httest/ilu.isl" of Wed Jul 30 16:32:51 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __httest_h_
#define __httest_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "iluhttp.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                              httest                              ***/
/************************************************************************/
/************************************************************************/

extern void httest__Initialize(void);
extern void httest__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT httest_DerivedResource;



/*======================================================================*/
/*========================= typedefs ===================================*/




/*======================================================================*/
/*=============== non-object type declarations =========================*/

httest_DerivedResource *
  CORBA_sequence_httest_DerivedResource_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _httest__Exception_FLIPEXCEP;
#define ex_httest_FLIPEXCEP _httest__Exception_FLIPEXCEP


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "httest_DerivedResource"  --------------------------*/

#define httest_DerivedResource__MSType _httest_DerivedResource__ILUType

httest_DerivedResource
  httest_DerivedResource__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  httest_DerivedResource__SetUserData (httest_DerivedResource /* self */, void * /* userData */);
void *
  httest_DerivedResource__GetUserData (httest_DerivedResource /* self */);

extern httest_DerivedResource
  httest_DerivedResource__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default httest_DerivedResource class */

extern httest_DerivedResource
  httest_DerivedResource__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern iluhttp_Response* server_httest_DerivedResource_GET (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern iluhttp_Response* server_httest_DerivedResource_HEAD (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern iluhttp_Response* server_httest_DerivedResource_POST (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern ilu_CString server_httest_DerivedResource_flipcase (httest_DerivedResource _handle, ilu_CString strtoflipcase, ILU_C_ENVIRONMENT *_status);

extern void httest_DerivedResource__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class httest_DerivedResource__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class httest_DerivedResource__MakeClass(
  ilu_CString (*httest_DerivedResource_flipcase__Impl)
     (httest_DerivedResource _handle, ilu_CString strtoflipcase, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_GET__Impl)
     (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_HEAD__Impl)
     (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_POST__Impl)
     (httest_DerivedResource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern ilu_CString  /* exceptions:  FLIPEXCEP */
  httest_DerivedResource_flipcase (httest_DerivedResource, ilu_CString, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void httest__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _httest_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _httest_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _httest_DerivedResource__IoFns;
#define TC_httest_DerivedResource (& _httest_DerivedResource__IoFns)
extern void httest_DerivedResource__Free (httest_DerivedResource*);

extern ilu_Class _httest_DerivedResource__ILUType;
extern ilu_CString _httest_DerivedResource_flipcase__clientstub (httest_DerivedResource _handle, ilu_CString strtoflipcase, ILU_C_ENVIRONMENT *_status);

extern void _httest__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __httest_h_ */
