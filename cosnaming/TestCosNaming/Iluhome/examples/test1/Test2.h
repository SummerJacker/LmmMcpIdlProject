/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:52 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Test2_h_
#define __Test2_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "Test1.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                              Test2                               ***/
/************************************************************************/
/************************************************************************/

extern void Test2__Initialize(void);
extern void Test2__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Test2_P;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef Test1_O3 Test2_T1O3;
typedef Test1_U3 Test2_T1U3;
typedef Test1_U2 Test2_T1U2;
typedef Test1_TheU Test2_T1U;
typedef struct _Test2_U2_union Test2_U2;
typedef Test1_TheE Test2_F;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* "Test2_T1O3" alias for "Test1_O3" */
#define Test2_T1O3__CreateTrue Test1_O3__CreateTrue
#define Test2_T1O3__OTCreateTrue Test1_O3__OTCreateTrue
#define Test2_T1O3__CreateFromSBH Test1_O3__CreateFromSBH
#define Test2_T1O3__CreateFromURL Test1_O3__CreateFromURL
#define Test2_T1O3__SetUserData Test1_O3__SetUserData
#define Test2_T1O3__GetUserData Test1_O3__GetUserData
#define _Test2_T1O3__ILUType _Test1_O3__ILUType
#define Test2_T1O3__MSType _Test1_O3__ILUType
#define Test2_T1O3__Free Test1_O3__Free
#define Test2_T1O3_RS_R_to_R_IS Test1_O3_RS_R_to_R_IS
#define Test2_T1O3_O1_U_to_U Test1_O3_O1_U_to_U
#define Test2_T1O3_BS_to_I Test1_O3_BS_to_I
#define CORBA_sequence_Test2_T1O3_allocbuf CORBA_sequence_Test1_O3_allocbuf

/* "Test2_T1U3" alias for "Test1_U3" */
#define CORBA_sequence_Test2_T1U3_allocbuf CORBA_sequence_Test1_U3_allocbuf

/* "Test2_T1U2" alias for "Test1_U2" */
#define CORBA_sequence_Test2_T1U2_allocbuf CORBA_sequence_Test1_U2_allocbuf

/* "Test2_T1U" alias for "Test1_TheU" */
#define CORBA_sequence_Test2_T1U_allocbuf CORBA_sequence_Test1_TheU_allocbuf

Test2_P *
  CORBA_sequence_Test2_P_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test2_U2" */

struct _Test2_U2_union {
	Test2_F _d;
	union {
		ilu_CString CString;	/* Test1_ev1 */
		Test1_O1 O1;	/* Test1_ev3 */
		Test2_P P;	/* Test1_ev7 */
	} _u;
};
Test2_U2 *
  CORBA_sequence_Test2_U2_allocbuf (CORBA_unsigned_long /* count */);

/* "Test2_F" alias for "Test1_TheE" */
#define CORBA_sequence_Test2_F_allocbuf CORBA_sequence_Test1_TheE_allocbuf



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _Test2__Exception_E1;
#define ex_Test2_E1 _Test2__Exception_E1


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Test2_P"  -----------------------------------------*/

#define Test2_P__MSType _Test2_P__ILUType

Test2_P
  Test2_P__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Test2_P__SetUserData (Test2_P /* self */, void * /* userData */);
void *
  Test2_P__GetUserData (Test2_P /* self */);

extern Test2_P
  Test2_P__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Test2_P class */

extern Test2_P
  Test2_P__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern CORBA_long server_Test2_P_SR_to_I (Test2_P _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status);

extern void Test2_P__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Test2_P__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Test2_P__MakeClass(
  CORBA_long (*Test2_P_SR_to_I__Impl)
     (Test2_P _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern CORBA_long
  Test2_P_SR_to_I (Test2_P, CORBA_float, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Test2__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Test2_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Test2_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

#define _Test2_T1O3__IoFns _Test1_O3__IoFns
#define TC_Test2_T1O3 (& _Test2_T1O3__IoFns)
#define _Test2_T1U3__IoFns _Test1_U3__IoFns
#define TC_Test2_T1U3 (& _Test2_T1U3__IoFns)
#define _Test2_T1U2__IoFns _Test1_U2__IoFns
#define TC_Test2_T1U2 (& _Test2_T1U2__IoFns)
#define _Test2_T1U__IoFns _Test1_TheU__IoFns
#define TC_Test2_T1U (& _Test2_T1U__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test2_U2__IoFns;
#define TC_Test2_U2 (& _Test2_U2__IoFns)
extern void _Test2_U2__Output (ilu_Call, Test2_U2*, ilu_Error *);
extern ilu_cardinal _Test2_U2__SizeOf (ilu_Call, Test2_U2*, ilu_Error *);
extern Test2_U2* _Test2_U2__Input (ilu_Call, Test2_U2*, ilu_Error *);
extern void Test2_U2__Free (Test2_U2*);
Test2_U2* Test2_U2__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test2_P__IoFns;
#define TC_Test2_P (& _Test2_P__IoFns)
extern void Test2_P__Free (Test2_P*);
#define _Test2_F__IoFns _Test1_TheE__IoFns
#define TC_Test2_F (& _Test2_F__IoFns)

extern ilu_Class _Test2_P__ILUType;
extern CORBA_long _Test2_P_SR_to_I__clientstub (Test2_P _handle, CORBA_float i, ILU_C_ENVIRONMENT *_status);

extern void _Test2__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Test2_h_ */
