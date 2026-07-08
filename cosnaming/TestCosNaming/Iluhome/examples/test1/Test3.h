/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:52 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Test3_h_
#define __Test3_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "Test1.h"
#include "Test2.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                              Test3                               ***/
/************************************************************************/
/************************************************************************/

extern void Test3__Initialize(void);
extern void Test3__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Test3_O;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _Test3_FU_union Test3_FU;
typedef Test1_O3 Test3_T2T1O3;
typedef Test1_U3 Test3_T2T1U3;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

Test3_O *
  CORBA_sequence_Test3_O_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test3_FU" */

struct _Test3_FU_union {
	Test2_F _d;
	union {
		Test3_O O;	/* Test1_ev1 */
		CORBA_long integer;	/* Test1_ev3 */
	} _u;
};
Test3_FU *
  CORBA_sequence_Test3_FU_allocbuf (CORBA_unsigned_long /* count */);

/* "Test3_T2T1O3" alias for "Test1_O3" */
#define Test3_T2T1O3__CreateTrue Test1_O3__CreateTrue
#define Test3_T2T1O3__OTCreateTrue Test1_O3__OTCreateTrue
#define Test3_T2T1O3__CreateFromSBH Test1_O3__CreateFromSBH
#define Test3_T2T1O3__CreateFromURL Test1_O3__CreateFromURL
#define Test3_T2T1O3__SetUserData Test1_O3__SetUserData
#define Test3_T2T1O3__GetUserData Test1_O3__GetUserData
#define _Test3_T2T1O3__ILUType _Test1_O3__ILUType
#define Test3_T2T1O3__MSType _Test1_O3__ILUType
#define Test3_T2T1O3__Free Test1_O3__Free
#define Test3_T2T1O3_RS_R_to_R_IS Test1_O3_RS_R_to_R_IS
#define Test3_T2T1O3_O1_U_to_U Test1_O3_O1_U_to_U
#define Test3_T2T1O3_BS_to_I Test1_O3_BS_to_I
#define CORBA_sequence_Test3_T2T1O3_allocbuf CORBA_sequence_Test1_O3_allocbuf

/* "Test3_T2T1U3" alias for "Test1_U3" */
#define CORBA_sequence_Test3_T2T1U3_allocbuf CORBA_sequence_Test1_U3_allocbuf



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _Test3__Exception_E1;
#define ex_Test3_E1 _Test3__Exception_E1


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Test3_O"  -----------------------------------------*/

#define Test3_O__MSType _Test3_O__ILUType

Test3_O
  Test3_O__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Test3_O__SetUserData (Test3_O /* self */, void * /* userData */);
void *
  Test3_O__GetUserData (Test3_O /* self */);

extern Test3_O
  Test3_O__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Test3_O class */

extern Test3_O
  Test3_O__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Test1_IS* server_Test3_O_RS_R_to_R_IS (Test3_O _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status);

extern void server_Test3_O_O1_U_to_U (Test3_O _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status);

extern Test1_I server_Test3_O_BS_to_I (Test3_O _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status);

extern CORBA_long server_Test3_O_SR_to_I (Test3_O _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status);

extern Test2_T1U* server_Test3_O_I_to_Test1U (Test3_O _handle, CORBA_long i, ILU_C_ENVIRONMENT *_status);

extern void Test3_O__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Test3_O__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Test3_O__MakeClass(
  Test2_T1U* (*Test3_O_I_to_Test1U__Impl)
     (Test3_O _handle, CORBA_long i, ILU_C_ENVIRONMENT *_status),
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test3_O _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test3_O _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test3_O _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*Test2_P_SR_to_I__Impl)
     (Test3_O _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Test2_T1U*  /* exceptions:  E1 E1 */
  Test3_O_I_to_Test1U (Test3_O, CORBA_long, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Test3__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Test3_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Test3_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Test3_FU__IoFns;
#define TC_Test3_FU (& _Test3_FU__IoFns)
extern void _Test3_FU__Output (ilu_Call, Test3_FU*, ilu_Error *);
extern ilu_cardinal _Test3_FU__SizeOf (ilu_Call, Test3_FU*, ilu_Error *);
extern Test3_FU* _Test3_FU__Input (ilu_Call, Test3_FU*, ilu_Error *);
extern void Test3_FU__Free (Test3_FU*);
Test3_FU* Test3_FU__alloc (void);
#define _Test3_T2T1O3__IoFns _Test1_O3__IoFns
#define TC_Test3_T2T1O3 (& _Test3_T2T1O3__IoFns)
#define _Test3_T2T1U3__IoFns _Test1_U3__IoFns
#define TC_Test3_T2T1U3 (& _Test3_T2T1U3__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test3_O__IoFns;
#define TC_Test3_O (& _Test3_O__IoFns)
extern void Test3_O__Free (Test3_O*);

extern ilu_Class _Test3_O__ILUType;
extern Test2_T1U* _Test3_O_I_to_Test1U__clientstub (Test3_O _handle, CORBA_long i, ILU_C_ENVIRONMENT *_status);

extern void _Test3__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Test3_h_ */
