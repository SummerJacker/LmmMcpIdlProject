/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:52 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Test1_h_
#define __Test1_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                              Test1                               ***/
/************************************************************************/
/************************************************************************/

extern void Test1__Initialize(void);
extern void Test1__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Test1_O4;
typedef ILU_C_OBJECT Test1_P;
typedef ILU_C_OBJECT Test1_O3;
typedef ILU_C_OBJECT Test1_TheO1;
typedef ILU_C_OBJECT Test1_O2;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _Test1_IS__sequence Test1_IS;
typedef struct _Test1_TheRS__sequence Test1_TheRS;
typedef Test1_TheRS Test1_RS;
typedef struct Test1_TheR Test1_TheR;
typedef Test1_TheR Test1_R;
typedef Test1_TheR *Test1_RO;
typedef struct _Test1_CSS__sequence Test1_CSS;
typedef Test1_TheO1 Test1_O1;
typedef Test1_TheO1 Test1_TheOO;
typedef Test1_TheOO Test1_OO;
typedef struct _Test1_TheU_union Test1_TheU;
typedef Test1_TheU Test1_U;
typedef CORBA_char * Test1_ScS;
typedef CORBA_octet Test1_A0[8];
typedef CORBA_octet Test1_A0_slice;
typedef CORBA_long Test1_I;
typedef CORBA_char * Test1_TheA1[3];
typedef CORBA_char * Test1_TheA1_slice;
typedef Test1_TheA1 Test1_A1;
typedef struct _Test1_BS__sequence Test1_BS;
typedef Test1_TheO1 Test1_One;
typedef struct _Test1_U_scard_union Test1_U_scard;
typedef struct _Test1_U_card_union Test1_U_card;
typedef struct _Test1_U_int_union Test1_U_int;
typedef struct _Test1_U_byte_union Test1_U_byte;
typedef struct _Test1_U4_union Test1_U4;
typedef struct _Test1_U2_union Test1_U2;
typedef struct _Test1_U3_union Test1_U3;
typedef enum {Test1_ev1 = 0, Test1_ev3 = 3, Test1_ev5 = 4, Test1_ev7 = 5} Test1_TheE;
typedef Test1_TheE Test1_E;
typedef struct _Test1_U1_union Test1_U1;
typedef struct _Test1_OO2_union Test1_OO2;
typedef CORBA_unsigned_long Test1_A2[3][4];
typedef CORBA_unsigned_long Test1_A2_slice[4];
typedef CORBA_wchar Test1_C;
typedef CORBA_char Test1_SC;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* sequence type "Test1_IS" */
struct _Test1_IS__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_long *_buffer;
};
void Test1_IS_Every (Test1_IS *h, void (*f)(CORBA_long*, void *, ilu_Error *), void *);
void Test1_IS_Append (Test1_IS *h, CORBA_long item, ilu_Error *);
void Test1_IS_Push (Test1_IS *h, CORBA_long item);
void Test1_IS_Pop (Test1_IS *h, CORBA_long *item);
CORBA_unsigned_long Test1_IS_Length (Test1_IS *);
CORBA_long * Test1_IS_Nth (Test1_IS *, CORBA_unsigned_long);
Test1_IS * Test1_IS_Create (CORBA_unsigned_long /* size */, CORBA_long * /* init val */);
void Test1_IS_Init (Test1_IS * /* seq */, CORBA_unsigned_long /* size */, CORBA_long * /* init val */);
Test1_IS *
  CORBA_sequence_Test1_IS_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Test1_TheRS" */
struct _Test1_TheRS__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Test1_R *_buffer;
};
void Test1_TheRS_Every (Test1_TheRS *h, void (*f)(Test1_R*, void *, ilu_Error *), void *);
void Test1_TheRS_Append (Test1_TheRS *h, Test1_R* item, ilu_Error *);
void Test1_TheRS_Push (Test1_TheRS *h, Test1_R* item);
void Test1_TheRS_Pop (Test1_TheRS *h, Test1_R* item);
CORBA_unsigned_long Test1_TheRS_Length (Test1_TheRS *);
Test1_R * Test1_TheRS_Nth (Test1_TheRS *, CORBA_unsigned_long);
Test1_TheRS * Test1_TheRS_Create (CORBA_unsigned_long /* size */, Test1_R*  /* init val */);
void Test1_TheRS_Init (Test1_TheRS * /* seq */, CORBA_unsigned_long /* size */, Test1_R*  /* init val */);
Test1_TheRS *
  CORBA_sequence_Test1_TheRS_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_RS" alias for "Test1_TheRS" */
#define Test1_RS_Length Test1_TheRS_Length
#define Test1_RS_Nth Test1_TheRS_Nth
#define Test1_RS_Every Test1_TheRS_Every
#define Test1_RS_Append Test1_TheRS_Append
#define Test1_RS_Push Test1_TheRS_Push
#define Test1_RS_Pop Test1_TheRS_Pop
#define Test1_RS_Init Test1_TheRS_Init
#define Test1_RS_Create Test1_TheRS_Create
#define Test1_RS__Free Test1_TheRS__Free
#define Test1_RS__alloc Test1_TheRS__alloc
#define CORBA_sequence_Test1_RS_allocbuf CORBA_sequence_Test1_TheRS_allocbuf

void Test1_ScS_Every (Test1_ScS *h, void (*f)(Test1_SC *, void *, ilu_Error *), void *);
void Test1_ScS_Append (Test1_ScS *, Test1_SC, ilu_Error *);
void Test1_ScS_Push (Test1_ScS *, Test1_SC);
void Test1_ScS_Pop (Test1_ScS *, Test1_SC *);
CORBA_unsigned_long Test1_ScS_Length (Test1_ScS *);
Test1_SC * Test1_ScS_Nth (Test1_ScS *, CORBA_unsigned_long);
Test1_ScS Test1_ScS_Create (CORBA_unsigned_long, Test1_SC *);
void Test1_ScS_Init (Test1_ScS *, CORBA_unsigned_long);
Test1_ScS *
  CORBA_sequence_Test1_ScS_allocbuf (CORBA_unsigned_long /* count */);

Test1_TheA1 *
  CORBA_sequence_Test1_TheA1_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_A1" alias for "Test1_TheA1" */
#define CORBA_sequence_Test1_A1_allocbuf CORBA_sequence_Test1_TheA1_allocbuf

/* sequence type "Test1_CSS" */
struct _Test1_CSS__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Test1_ScS *_buffer;
};
void Test1_CSS_Every (Test1_CSS *h, void (*f)(Test1_ScS*, void *, ilu_Error *), void *);
void Test1_CSS_Append (Test1_CSS *h, Test1_ScS item, ilu_Error *);
void Test1_CSS_Push (Test1_CSS *h, Test1_ScS item);
void Test1_CSS_Pop (Test1_CSS *h, Test1_ScS *item);
CORBA_unsigned_long Test1_CSS_Length (Test1_CSS *);
Test1_ScS * Test1_CSS_Nth (Test1_CSS *, CORBA_unsigned_long);
Test1_CSS * Test1_CSS_Create (CORBA_unsigned_long /* size */, Test1_ScS * /* init val */);
void Test1_CSS_Init (Test1_CSS * /* seq */, CORBA_unsigned_long /* size */, Test1_ScS * /* init val */);
Test1_CSS *
  CORBA_sequence_Test1_CSS_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_I" alias for "CORBA_long" */
#define CORBA_sequence_Test1_I_allocbuf CORBA_sequence_long_allocbuf

/* record "Test1_TheR" */
struct Test1_TheR {
	Test1_A1 a;
	Test1_CSS css;
	Test1_I i;
};
Test1_TheR *
  CORBA_sequence_Test1_TheR_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_R" alias for "Test1_TheR" */
#define CORBA_sequence_Test1_R_allocbuf CORBA_sequence_Test1_TheR_allocbuf

Test1_RO *
  CORBA_sequence_Test1_RO_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_O1" alias for "Test1_TheO1" */
#define Test1_O1__CreateTrue Test1_TheO1__CreateTrue
#define Test1_O1__OTCreateTrue Test1_TheO1__OTCreateTrue
#define Test1_O1__CreateFromSBH Test1_TheO1__CreateFromSBH
#define Test1_O1__CreateFromURL Test1_TheO1__CreateFromURL
#define Test1_O1__SetUserData Test1_TheO1__SetUserData
#define Test1_O1__GetUserData Test1_TheO1__GetUserData
#define _Test1_O1__ILUType _Test1_TheO1__ILUType
#define Test1_O1__MSType _Test1_TheO1__ILUType
#define Test1_O1__Free Test1_TheO1__Free
#define Test1_O1_U_CSS_to_U Test1_TheO1_U_CSS_to_U
#define Test1_O1_f_CSS_to_RO Test1_TheO1_f_CSS_to_RO
#define Test1_O1_R_ScS_to_F Test1_TheO1_R_ScS_to_F
#define Test1_O1_a_RO Test1_TheO1_a_RO
#define Test1_O1_get_O2 Test1_TheO1_get_O2
#define Test1_O1_get_O3 Test1_TheO1_get_O3
#define CORBA_sequence_Test1_O1_allocbuf CORBA_sequence_Test1_TheO1_allocbuf

Test1_TheOO *
  CORBA_sequence_Test1_TheOO_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_OO" alias for "Test1_TheOO" */
#define CORBA_sequence_Test1_OO_allocbuf CORBA_sequence_Test1_TheOO_allocbuf

/* union "Test1_TheU" */

struct _Test1_TheU_union {
	CORBA_short _d;
	union {
		Test1_R R;	/* 0 */
		Test1_RO RO;	/* 1 */
		Test1_CSS CSS;	/* 2 */
		Test1_O1 O1;	/* 3 */
		Test1_OO OO;	/* 4 */
		CORBA_boolean boolean;	/* 5 */
	} _u;
};
Test1_TheU *
  CORBA_sequence_Test1_TheU_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_U" alias for "Test1_TheU" */
#define CORBA_sequence_Test1_U_allocbuf CORBA_sequence_Test1_TheU_allocbuf

Test1_A0 *
  CORBA_sequence_Test1_A0_allocbuf (CORBA_unsigned_long /* count */);

Test1_O2 *
  CORBA_sequence_Test1_O2_allocbuf (CORBA_unsigned_long /* count */);

Test1_O3 *
  CORBA_sequence_Test1_O3_allocbuf (CORBA_unsigned_long /* count */);

Test1_TheO1 *
  CORBA_sequence_Test1_TheO1_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Test1_BS" */
struct _Test1_BS__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_octet *_buffer;
};
void Test1_BS_Every (Test1_BS *h, void (*f)(CORBA_octet*, void *, ilu_Error *), void *);
void Test1_BS_Append (Test1_BS *h, CORBA_octet item, ilu_Error *);
void Test1_BS_Push (Test1_BS *h, CORBA_octet item);
void Test1_BS_Pop (Test1_BS *h, CORBA_octet *item);
CORBA_unsigned_long Test1_BS_Length (Test1_BS *);
CORBA_octet * Test1_BS_Nth (Test1_BS *, CORBA_unsigned_long);
Test1_BS * Test1_BS_Create (CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
void Test1_BS_Init (Test1_BS * /* seq */, CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
Test1_BS *
  CORBA_sequence_Test1_BS_allocbuf (CORBA_unsigned_long /* count */);

Test1_O4 *
  CORBA_sequence_Test1_O4_allocbuf (CORBA_unsigned_long /* count */);

Test1_P *
  CORBA_sequence_Test1_P_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_One" alias for "Test1_TheO1" */
#define Test1_One__CreateTrue Test1_TheO1__CreateTrue
#define Test1_One__OTCreateTrue Test1_TheO1__OTCreateTrue
#define Test1_One__CreateFromSBH Test1_TheO1__CreateFromSBH
#define Test1_One__CreateFromURL Test1_TheO1__CreateFromURL
#define Test1_One__SetUserData Test1_TheO1__SetUserData
#define Test1_One__GetUserData Test1_TheO1__GetUserData
#define _Test1_One__ILUType _Test1_TheO1__ILUType
#define Test1_One__MSType _Test1_TheO1__ILUType
#define Test1_One__Free Test1_TheO1__Free
#define Test1_One_U_CSS_to_U Test1_TheO1_U_CSS_to_U
#define Test1_One_f_CSS_to_RO Test1_TheO1_f_CSS_to_RO
#define Test1_One_R_ScS_to_F Test1_TheO1_R_ScS_to_F
#define Test1_One_a_RO Test1_TheO1_a_RO
#define Test1_One_get_O2 Test1_TheO1_get_O2
#define Test1_One_get_O3 Test1_TheO1_get_O3
#define CORBA_sequence_Test1_One_allocbuf CORBA_sequence_Test1_TheO1_allocbuf

/* union "Test1_U_scard" */

struct _Test1_U_scard_union {
	CORBA_unsigned_short _d;
	union {
		Test1_R R;	/* 0 */
		Test1_One One;	/* 1 */
	} _u;
};
Test1_U_scard *
  CORBA_sequence_Test1_U_scard_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test1_U_card" */

struct _Test1_U_card_union {
	CORBA_unsigned_long _d;
	union {
		Test1_R R;	/* 0 */
		Test1_O2 O2;	/* 1 */
	} _u;
};
Test1_U_card *
  CORBA_sequence_Test1_U_card_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test1_U_int" */

struct _Test1_U_int_union {
	CORBA_long _d;
	union {
		Test1_R R;	/* 0 */
		Test1_O2 O2;	/* 1 */
	} _u;
};
Test1_U_int *
  CORBA_sequence_Test1_U_int_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test1_U_byte" */

struct _Test1_U_byte_union {
	CORBA_octet _d;
	union {
		Test1_R R;	/* 0 */
		Test1_O2 O2;	/* 1 */
	} _u;
};
Test1_U_byte *
  CORBA_sequence_Test1_U_byte_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test1_U4" */

struct _Test1_U4_union {
	CORBA_short _d;
	union {
		CORBA_boolean x1;	/* 3, 7 */
		Test1_O2 x2;	/* DEFAULT */
		Test1_CSS x3;	/* 1, 0 */
	} _u;
};
Test1_U4 *
  CORBA_sequence_Test1_U4_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test1_U2" */

struct _Test1_U2_union {
	CORBA_short _d;
	union {
		CORBA_boolean x1;	/* 3, 7 */
		Test1_O2 x2;	/* 1, 22 */
		Test1_CSS x3;	/* 2 */
	} _u;
};
Test1_U2 *
  CORBA_sequence_Test1_U2_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test1_U3" */

struct _Test1_U3_union {
	Test1_E _d;
	union {
		ilu_CString CString;	/* Test1_ev1 */
		Test1_U2 U2;	/* Test1_ev3 */
		Test1_O2 v3;	/* Test1_ev7 */
		Test1_RO v4;	/* DEFAULT */
	} _u;
};
Test1_U3 *
  CORBA_sequence_Test1_U3_allocbuf (CORBA_unsigned_long /* count */);

Test1_TheE *
  CORBA_sequence_Test1_TheE_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_E" alias for "Test1_TheE" */
#define CORBA_sequence_Test1_E_allocbuf CORBA_sequence_Test1_TheE_allocbuf

/* union "Test1_U1" */

struct _Test1_U1_union {
	CORBA_short _d;
	union {
		Test1_R R;	/* 0 */
		Test1_A1 A1;	/* 1 */
	} _u;
};
Test1_U1 *
  CORBA_sequence_Test1_U1_allocbuf (CORBA_unsigned_long /* count */);

/* union "Test1_OO2" */

struct _Test1_OO2_union {
	CORBA_boolean _d;
	union {
		Test1_O2 O2;	/* ilu_TRUE */
	} _u;
};
Test1_OO2 *
  CORBA_sequence_Test1_OO2_allocbuf (CORBA_unsigned_long /* count */);

Test1_A2 *
  CORBA_sequence_Test1_A2_allocbuf (CORBA_unsigned_long /* count */);

/* "Test1_C" alias for "CORBA_wchar" */
#define CORBA_sequence_Test1_C_allocbuf CORBA_sequence_wchar_allocbuf

/* "Test1_SC" alias for "CORBA_char" */
#define CORBA_sequence_Test1_SC_allocbuf CORBA_sequence_char_allocbuf



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _Test1__Exception_E1;
#define ex_Test1_E1 _Test1__Exception_E1
extern ILU_C_ExceptionCode _Test1__Exception_E2;
#define ex_Test1_E2 _Test1__Exception_E2
extern ILU_C_ExceptionCode _Test1__Exception_CantCreate;
#define ex_Test1_CantCreate _Test1__Exception_CantCreate
extern ILU_C_ExceptionCode _Test1__Exception_E3;
#define ex_Test1_E3 _Test1__Exception_E3
extern ILU_C_ExceptionCode _Test1__Exception_E4;
#define ex_Test1_E4 _Test1__Exception_E4
extern ILU_C_ExceptionCode _Test1__Exception_E5;
#define ex_Test1_E5 _Test1__Exception_E5
extern ILU_C_ExceptionCode _Test1__Exception_E6;
#define ex_Test1_E6 _Test1__Exception_E6
extern ILU_C_ExceptionCode _Test1__Exception_E7;
#define ex_Test1_E7 _Test1__Exception_E7
extern ILU_C_ExceptionCode _Test1__Exception_E8;
#define ex_Test1_E8 _Test1__Exception_E8
extern ILU_C_ExceptionCode _Test1__Exception_E9;
#define ex_Test1_E9 _Test1__Exception_E9


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Test1_O4"  ----------------------------------------*/

#define Test1_O4__MSType _Test1_O4__ILUType

Test1_O4
  Test1_O4__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Test1_O4__SetUserData (Test1_O4 /* self */, void * /* userData */);
void *
  Test1_O4__GetUserData (Test1_O4 /* self */);

extern Test1_O4
  Test1_O4__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Test1_O4 class */

extern Test1_O4
  Test1_O4__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Test1_IS* server_Test1_O4_RS_R_to_R_IS (Test1_O4 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status);

extern void server_Test1_O4_O1_U_to_U (Test1_O4 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status);

extern Test1_I server_Test1_O4_BS_to_I (Test1_O4 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status);

extern CORBA_double server_Test1_O4_R_to_R (Test1_O4 _handle, CORBA_double r, ILU_C_ENVIRONMENT *_status);

extern void Test1_O4__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Test1_O4__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Test1_O4__MakeClass(
  CORBA_double (*Test1_O4_R_to_R__Impl)
     (Test1_O4 _handle, CORBA_double r, ILU_C_ENVIRONMENT *_status),
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test1_O4 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test1_O4 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test1_O4 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern CORBA_double
  Test1_O4_R_to_R (Test1_O4, CORBA_double, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "Test1_P"  -----------------------------------------*/

#define Test1_P__MSType _Test1_P__ILUType

Test1_P
  Test1_P__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Test1_P__SetUserData (Test1_P /* self */, void * /* userData */);
void *
  Test1_P__GetUserData (Test1_P /* self */);

extern Test1_P
  Test1_P__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Test1_P class */

extern Test1_P
  Test1_P__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Test1_IS* server_Test1_P_RS_R_to_R_IS (Test1_P _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status);

extern void server_Test1_P_O1_U_to_U (Test1_P _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status);

extern Test1_I server_Test1_P_BS_to_I (Test1_P _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status);

extern Test1_IS* server_Test1_P_m2 (Test1_P _handle, CORBA_long j, ILU_C_ENVIRONMENT *_status);

extern void Test1_P__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Test1_P__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Test1_P__MakeClass(
  Test1_IS* (*Test1_P_m2__Impl)
     (Test1_P _handle, CORBA_long j, ILU_C_ENVIRONMENT *_status),
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test1_P _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test1_P _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test1_P _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Test1_IS*
  Test1_P_m2 (Test1_P, CORBA_long, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "Test1_O3"  ----------------------------------------*/

#define Test1_O3__MSType _Test1_O3__ILUType

Test1_O3
  Test1_O3__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Test1_O3__SetUserData (Test1_O3 /* self */, void * /* userData */);
void *
  Test1_O3__GetUserData (Test1_O3 /* self */);

extern Test1_O3
  Test1_O3__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Test1_O3 class */

extern Test1_O3
  Test1_O3__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Test1_IS* server_Test1_O3_RS_R_to_R_IS (Test1_O3 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status);

extern void server_Test1_O3_O1_U_to_U (Test1_O3 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status);

extern Test1_I server_Test1_O3_BS_to_I (Test1_O3 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status);

extern void Test1_O3__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Test1_O3__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Test1_O3__MakeClass(
  Test1_IS* (*Test1_O3_RS_R_to_R_IS__Impl)
     (Test1_O3 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status),
  void (*Test1_O3_O1_U_to_U__Impl)
     (Test1_O3 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status),
  Test1_I (*Test1_O3_BS_to_I__Impl)
     (Test1_O3 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Test1_IS*
  Test1_O3_RS_R_to_R_IS (Test1_O3, Test1_RS*, Test1_R**, ILU_C_ENVIRONMENT *);

extern void  /* exceptions:  E2 */
  Test1_O3_O1_U_to_U (Test1_O3, Test1_O1, Test1_U*, ILU_C_ENVIRONMENT *);

extern Test1_I
  Test1_O3_BS_to_I (Test1_O3, Test1_BS*, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "Test1_TheO1"  -------------------------------------*/

#define Test1_TheO1__MSType _Test1_TheO1__ILUType

Test1_TheO1
  Test1_TheO1__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Test1_TheO1__SetUserData (Test1_TheO1 /* self */, void * /* userData */);
void *
  Test1_TheO1__GetUserData (Test1_TheO1 /* self */);

extern Test1_TheO1
  Test1_TheO1__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Test1_TheO1 class */

extern Test1_TheO1
  Test1_TheO1__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Test1_U* server_Test1_TheO1_U_CSS_to_U (Test1_TheO1 _handle, Test1_U* u, Test1_CSS* css, ILU_C_ENVIRONMENT *_status);

extern Test1_RO server_Test1_TheO1_f_CSS_to_RO (Test1_TheO1 _handle, Test1_CSS* css, ILU_C_ENVIRONMENT *_status);

extern CORBA_float server_Test1_TheO1_R_ScS_to_F (Test1_TheO1 _handle, Test1_R* r, Test1_ScS s, ILU_C_ENVIRONMENT *_status);

extern void server_Test1_TheO1_a_RO (Test1_TheO1 _handle, Test1_RO ro, ILU_C_ENVIRONMENT *_status);

extern Test1_O2 server_Test1_TheO1_get_O2 (Test1_TheO1 _handle, ILU_C_ENVIRONMENT *_status);

extern Test1_O3 server_Test1_TheO1_get_O3 (Test1_TheO1 _handle, CORBA_boolean subclass, ILU_C_ENVIRONMENT *_status);

extern void Test1_TheO1__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Test1_TheO1__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Test1_TheO1__MakeClass(
  Test1_U* (*Test1_TheO1_U_CSS_to_U__Impl)
     (Test1_TheO1 _handle, Test1_U* u, Test1_CSS* css, ILU_C_ENVIRONMENT *_status),
  Test1_RO (*Test1_TheO1_f_CSS_to_RO__Impl)
     (Test1_TheO1 _handle, Test1_CSS* css, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*Test1_TheO1_R_ScS_to_F__Impl)
     (Test1_TheO1 _handle, Test1_R* r, Test1_ScS s, ILU_C_ENVIRONMENT *_status),
  void (*Test1_TheO1_a_RO__Impl)
     (Test1_TheO1 _handle, Test1_RO ro, ILU_C_ENVIRONMENT *_status),
  Test1_O2 (*Test1_TheO1_get_O2__Impl)
     (Test1_TheO1 _handle, ILU_C_ENVIRONMENT *_status),
  Test1_O3 (*Test1_TheO1_get_O3__Impl)
     (Test1_TheO1 _handle, CORBA_boolean subclass, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Test1_U*  /* exceptions:  E1 E2 */
  Test1_TheO1_U_CSS_to_U (Test1_TheO1, Test1_U*, Test1_CSS*, ILU_C_ENVIRONMENT *);

extern Test1_RO  /* exceptions:  E1 */
  Test1_TheO1_f_CSS_to_RO (Test1_TheO1, Test1_CSS*, ILU_C_ENVIRONMENT *);

extern CORBA_float
  Test1_TheO1_R_ScS_to_F (Test1_TheO1, Test1_R*, Test1_ScS, ILU_C_ENVIRONMENT *);

extern void
  Test1_TheO1_a_RO (Test1_TheO1, Test1_RO, ILU_C_ENVIRONMENT *);

extern Test1_O2  /* exceptions:  CantCreate */
  Test1_TheO1_get_O2 (Test1_TheO1, ILU_C_ENVIRONMENT *);

extern Test1_O3  /* exceptions:  CantCreate */
  Test1_TheO1_get_O3 (Test1_TheO1, CORBA_boolean, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "Test1_O2"  ----------------------------------------*/

#define Test1_O2__MSType _Test1_O2__ILUType

Test1_O2
  Test1_O2__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Test1_O2__SetUserData (Test1_O2 /* self */, void * /* userData */);
void *
  Test1_O2__GetUserData (Test1_O2 /* self */);

extern Test1_O2
  Test1_O2__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Test1_O2 class */

extern Test1_O2
  Test1_O2__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Test1_CSS* server_Test1_O2_OO_A0_to_CSS (Test1_O2 _handle, Test1_OO o, Test1_A0 a, ILU_C_ENVIRONMENT *_status);

extern Test1_A0_slice * server_Test1_O2_R_I_A1_to_I_A0 (Test1_O2 _handle, Test1_R* r, Test1_I* i, Test1_A1 a, ILU_C_ENVIRONMENT *_status);

extern void Test1_O2__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Test1_O2__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Test1_O2__MakeClass(
  Test1_CSS* (*Test1_O2_OO_A0_to_CSS__Impl)
     (Test1_O2 _handle, Test1_OO o, Test1_A0 a, ILU_C_ENVIRONMENT *_status),
  Test1_A0_slice * (*Test1_O2_R_I_A1_to_I_A0__Impl)
     (Test1_O2 _handle, Test1_R* r, Test1_I* i, Test1_A1 a, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Test1_CSS*  /* exceptions:  E2 */
  Test1_O2_OO_A0_to_CSS (Test1_O2, Test1_OO, Test1_A0, ILU_C_ENVIRONMENT *);

extern Test1_A0_slice *
  Test1_O2_R_I_A1_to_I_A0 (Test1_O2, Test1_R*, Test1_I*, Test1_A1, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Test1__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Test1_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Test1_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Test1_O4__IoFns;
#define TC_Test1_O4 (& _Test1_O4__IoFns)
extern void Test1_O4__Free (Test1_O4*);
extern struct _ILU_C_IoFnsRegistration_s _Test1_P__IoFns;
#define TC_Test1_P (& _Test1_P__IoFns)
extern void Test1_P__Free (Test1_P*);
extern struct _ILU_C_IoFnsRegistration_s _Test1_O3__IoFns;
#define TC_Test1_O3 (& _Test1_O3__IoFns)
extern void Test1_O3__Free (Test1_O3*);
extern struct _ILU_C_IoFnsRegistration_s _Test1_TheO1__IoFns;
#define TC_Test1_TheO1 (& _Test1_TheO1__IoFns)
extern void Test1_TheO1__Free (Test1_TheO1*);
extern struct _ILU_C_IoFnsRegistration_s _Test1_U_scard__IoFns;
#define TC_Test1_U_scard (& _Test1_U_scard__IoFns)
extern void _Test1_U_scard__Output (ilu_Call, Test1_U_scard*, ilu_Error *);
extern ilu_cardinal _Test1_U_scard__SizeOf (ilu_Call, Test1_U_scard*, ilu_Error *);
extern Test1_U_scard* _Test1_U_scard__Input (ilu_Call, Test1_U_scard*, ilu_Error *);
extern void Test1_U_scard__Free (Test1_U_scard*);
Test1_U_scard* Test1_U_scard__alloc (void);
#define _Test1_One__IoFns _Test1_TheO1__IoFns
#define TC_Test1_One (& _Test1_One__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_U_card__IoFns;
#define TC_Test1_U_card (& _Test1_U_card__IoFns)
extern void _Test1_U_card__Output (ilu_Call, Test1_U_card*, ilu_Error *);
extern ilu_cardinal _Test1_U_card__SizeOf (ilu_Call, Test1_U_card*, ilu_Error *);
extern Test1_U_card* _Test1_U_card__Input (ilu_Call, Test1_U_card*, ilu_Error *);
extern void Test1_U_card__Free (Test1_U_card*);
Test1_U_card* Test1_U_card__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_U_int__IoFns;
#define TC_Test1_U_int (& _Test1_U_int__IoFns)
extern void _Test1_U_int__Output (ilu_Call, Test1_U_int*, ilu_Error *);
extern ilu_cardinal _Test1_U_int__SizeOf (ilu_Call, Test1_U_int*, ilu_Error *);
extern Test1_U_int* _Test1_U_int__Input (ilu_Call, Test1_U_int*, ilu_Error *);
extern void Test1_U_int__Free (Test1_U_int*);
Test1_U_int* Test1_U_int__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_U_byte__IoFns;
#define TC_Test1_U_byte (& _Test1_U_byte__IoFns)
extern void _Test1_U_byte__Output (ilu_Call, Test1_U_byte*, ilu_Error *);
extern ilu_cardinal _Test1_U_byte__SizeOf (ilu_Call, Test1_U_byte*, ilu_Error *);
extern Test1_U_byte* _Test1_U_byte__Input (ilu_Call, Test1_U_byte*, ilu_Error *);
extern void Test1_U_byte__Free (Test1_U_byte*);
Test1_U_byte* Test1_U_byte__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_U4__IoFns;
#define TC_Test1_U4 (& _Test1_U4__IoFns)
extern void _Test1_U4__Output (ilu_Call, Test1_U4*, ilu_Error *);
extern ilu_cardinal _Test1_U4__SizeOf (ilu_Call, Test1_U4*, ilu_Error *);
extern Test1_U4* _Test1_U4__Input (ilu_Call, Test1_U4*, ilu_Error *);
extern void Test1_U4__Free (Test1_U4*);
Test1_U4* Test1_U4__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_U3__IoFns;
#define TC_Test1_U3 (& _Test1_U3__IoFns)
extern void _Test1_U3__Output (ilu_Call, Test1_U3*, ilu_Error *);
extern ilu_cardinal _Test1_U3__SizeOf (ilu_Call, Test1_U3*, ilu_Error *);
extern Test1_U3* _Test1_U3__Input (ilu_Call, Test1_U3*, ilu_Error *);
extern void Test1_U3__Free (Test1_U3*);
Test1_U3* Test1_U3__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_U2__IoFns;
#define TC_Test1_U2 (& _Test1_U2__IoFns)
extern void _Test1_U2__Output (ilu_Call, Test1_U2*, ilu_Error *);
extern ilu_cardinal _Test1_U2__SizeOf (ilu_Call, Test1_U2*, ilu_Error *);
extern Test1_U2* _Test1_U2__Input (ilu_Call, Test1_U2*, ilu_Error *);
extern void Test1_U2__Free (Test1_U2*);
Test1_U2* Test1_U2__alloc (void);
#define _Test1_E__IoFns _Test1_TheE__IoFns
#define TC_Test1_E (& _Test1_E__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_TheE__IoFns;
#define TC_Test1_TheE (& _Test1_TheE__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_U1__IoFns;
#define TC_Test1_U1 (& _Test1_U1__IoFns)
extern void _Test1_U1__Output (ilu_Call, Test1_U1*, ilu_Error *);
extern ilu_cardinal _Test1_U1__SizeOf (ilu_Call, Test1_U1*, ilu_Error *);
extern Test1_U1* _Test1_U1__Input (ilu_Call, Test1_U1*, ilu_Error *);
extern void Test1_U1__Free (Test1_U1*);
Test1_U1* Test1_U1__alloc (void);
#define _Test1_U__IoFns _Test1_TheU__IoFns
#define TC_Test1_U (& _Test1_U__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_TheU__IoFns;
#define TC_Test1_TheU (& _Test1_TheU__IoFns)
extern void _Test1_TheU__Output (ilu_Call, Test1_TheU*, ilu_Error *);
extern ilu_cardinal _Test1_TheU__SizeOf (ilu_Call, Test1_TheU*, ilu_Error *);
extern Test1_TheU* _Test1_TheU__Input (ilu_Call, Test1_TheU*, ilu_Error *);
extern void Test1_TheU__Free (Test1_TheU*);
Test1_TheU* Test1_TheU__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_OO2__IoFns;
#define TC_Test1_OO2 (& _Test1_OO2__IoFns)
extern void _Test1_OO2__Output (ilu_Call, Test1_OO2*, ilu_Error *);
extern ilu_cardinal _Test1_OO2__SizeOf (ilu_Call, Test1_OO2*, ilu_Error *);
extern Test1_OO2* _Test1_OO2__Input (ilu_Call, Test1_OO2*, ilu_Error *);
extern void Test1_OO2__Free (Test1_OO2*);
Test1_OO2* Test1_OO2__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_O2__IoFns;
#define TC_Test1_O2 (& _Test1_O2__IoFns)
extern void Test1_O2__Free (Test1_O2*);
#define _Test1_OO__IoFns _Test1_TheOO__IoFns
#define TC_Test1_OO (& _Test1_OO__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_TheOO__IoFns;
#define TC_Test1_TheOO (& _Test1_TheOO__IoFns)
extern void _Test1_TheOO__Output (ilu_Call, Test1_TheOO, ilu_Error *);
extern ilu_cardinal _Test1_TheOO__SizeOf (ilu_Call, Test1_TheOO, ilu_Error *);
extern Test1_TheOO* _Test1_TheOO__Input (ilu_Call, Test1_TheOO*, ilu_Error *);
extern void Test1_TheOO__Free (Test1_TheOO*);
Test1_TheOO* Test1_TheOO__alloc (void);
#define _Test1_O1__IoFns _Test1_TheO1__IoFns
#define TC_Test1_O1 (& _Test1_O1__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_RO__IoFns;
#define TC_Test1_RO (& _Test1_RO__IoFns)
extern void _Test1_RO__Output (ilu_Call, Test1_RO, ilu_Error *);
extern ilu_cardinal _Test1_RO__SizeOf (ilu_Call, Test1_RO, ilu_Error *);
extern Test1_RO* _Test1_RO__Input (ilu_Call, Test1_RO*, ilu_Error *);
extern void Test1_RO__Free (Test1_RO*);
Test1_RO* Test1_RO__alloc (void);
#define _Test1_RS__IoFns _Test1_TheRS__IoFns
#define TC_Test1_RS (& _Test1_RS__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_TheRS__IoFns;
#define TC_Test1_TheRS (& _Test1_TheRS__IoFns)
extern void _Test1_TheRS__Output (ilu_Call, Test1_TheRS*, ilu_Error *);
extern ilu_cardinal _Test1_TheRS__SizeOf (ilu_Call, Test1_TheRS*, ilu_Error *);
extern Test1_TheRS* _Test1_TheRS__Input (ilu_Call, Test1_TheRS*, ilu_Error *);
extern void Test1_TheRS__Free (Test1_TheRS*);
Test1_TheRS* Test1_TheRS__alloc (void);
#define _Test1_R__IoFns _Test1_TheR__IoFns
#define TC_Test1_R (& _Test1_R__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_TheR__IoFns;
#define TC_Test1_TheR (& _Test1_TheR__IoFns)
extern void _Test1_TheR__Output (ilu_Call, Test1_TheR*, ilu_Error *);
extern ilu_cardinal _Test1_TheR__SizeOf (ilu_Call, Test1_TheR*, ilu_Error *);
extern Test1_TheR* _Test1_TheR__Input (ilu_Call, Test1_TheR*, ilu_Error *);
extern void Test1_TheR__Free (Test1_TheR*);
Test1_TheR* Test1_TheR__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_BS__IoFns;
#define TC_Test1_BS (& _Test1_BS__IoFns)
extern void _Test1_BS__Output (ilu_Call, Test1_BS*, ilu_Error *);
extern ilu_cardinal _Test1_BS__SizeOf (ilu_Call, Test1_BS*, ilu_Error *);
extern Test1_BS* _Test1_BS__Input (ilu_Call, Test1_BS*, ilu_Error *);
extern void Test1_BS__Free (Test1_BS*);
Test1_BS* Test1_BS__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_A2__IoFns;
#define TC_Test1_A2 (& _Test1_A2__IoFns)
extern void _Test1_A2__Output (ilu_Call, Test1_A2, ilu_Error *);
extern ilu_cardinal _Test1_A2__SizeOf (ilu_Call, Test1_A2, ilu_Error *);
extern Test1_A2_slice * _Test1_A2__Input (ilu_Call, Test1_A2, ilu_Error *);
Test1_A2_slice * Test1_A2__alloc (void);
#define _Test1_A1__IoFns _Test1_TheA1__IoFns
#define TC_Test1_A1 (& _Test1_A1__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_TheA1__IoFns;
#define TC_Test1_TheA1 (& _Test1_TheA1__IoFns)
extern void _Test1_TheA1__Output (ilu_Call, Test1_TheA1, ilu_Error *);
extern ilu_cardinal _Test1_TheA1__SizeOf (ilu_Call, Test1_TheA1, ilu_Error *);
extern Test1_TheA1_slice * _Test1_TheA1__Input (ilu_Call, Test1_TheA1, ilu_Error *);
extern void Test1_TheA1__Free (Test1_TheA1*);
Test1_TheA1_slice * Test1_TheA1__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_A0__IoFns;
#define TC_Test1_A0 (& _Test1_A0__IoFns)
extern void _Test1_A0__Output (ilu_Call, Test1_A0, ilu_Error *);
extern ilu_cardinal _Test1_A0__SizeOf (ilu_Call, Test1_A0, ilu_Error *);
extern Test1_A0_slice * _Test1_A0__Input (ilu_Call, Test1_A0, ilu_Error *);
Test1_A0_slice * Test1_A0__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_CSS__IoFns;
#define TC_Test1_CSS (& _Test1_CSS__IoFns)
extern void _Test1_CSS__Output (ilu_Call, Test1_CSS*, ilu_Error *);
extern ilu_cardinal _Test1_CSS__SizeOf (ilu_Call, Test1_CSS*, ilu_Error *);
extern Test1_CSS* _Test1_CSS__Input (ilu_Call, Test1_CSS*, ilu_Error *);
extern void Test1_CSS__Free (Test1_CSS*);
Test1_CSS* Test1_CSS__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Test1_ScS__IoFns;
#define TC_Test1_ScS (& _Test1_ScS__IoFns)
extern void _Test1_ScS__Output (ilu_Call, Test1_ScS, ilu_Error *);
extern ilu_cardinal _Test1_ScS__SizeOf (ilu_Call, Test1_ScS, ilu_Error *);
extern Test1_ScS* _Test1_ScS__Input (ilu_Call, Test1_ScS*, ilu_Error *);
extern void Test1_ScS__Free (Test1_ScS*);
Test1_ScS* Test1_ScS__alloc (void);
#define _Test1_C__IoFns _CORBA_wchar__IoFns
#define TC_Test1_C (& _Test1_C__IoFns)
#define _Test1_SC__IoFns _CORBA_char__IoFns
#define TC_Test1_SC (& _Test1_SC__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Test1_IS__IoFns;
#define TC_Test1_IS (& _Test1_IS__IoFns)
extern void _Test1_IS__Output (ilu_Call, Test1_IS*, ilu_Error *);
extern ilu_cardinal _Test1_IS__SizeOf (ilu_Call, Test1_IS*, ilu_Error *);
extern Test1_IS* _Test1_IS__Input (ilu_Call, Test1_IS*, ilu_Error *);
extern void Test1_IS__Free (Test1_IS*);
Test1_IS* Test1_IS__alloc (void);
#define _Test1_I__IoFns _CORBA_long__IoFns
#define TC_Test1_I (& _Test1_I__IoFns)

extern ilu_Class _Test1_O4__ILUType;
extern CORBA_double _Test1_O4_R_to_R__clientstub (Test1_O4 _handle, CORBA_double r, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _Test1_P__ILUType;
extern Test1_IS* _Test1_P_m2__clientstub (Test1_P _handle, CORBA_long j, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _Test1_O3__ILUType;
extern Test1_IS* _Test1_O3_RS_R_to_R_IS__clientstub (Test1_O3 _handle, Test1_RS* r, Test1_R** r2, ILU_C_ENVIRONMENT *_status);
extern void _Test1_O3_O1_U_to_U__clientstub (Test1_O3 _handle, Test1_O1 o, Test1_U* u, ILU_C_ENVIRONMENT *_status);
extern Test1_I _Test1_O3_BS_to_I__clientstub (Test1_O3 _handle, Test1_BS* b, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _Test1_TheO1__ILUType;
extern Test1_U* _Test1_TheO1_U_CSS_to_U__clientstub (Test1_TheO1 _handle, Test1_U* u, Test1_CSS* css, ILU_C_ENVIRONMENT *_status);
extern Test1_RO _Test1_TheO1_f_CSS_to_RO__clientstub (Test1_TheO1 _handle, Test1_CSS* css, ILU_C_ENVIRONMENT *_status);
extern CORBA_float _Test1_TheO1_R_ScS_to_F__clientstub (Test1_TheO1 _handle, Test1_R* r, Test1_ScS s, ILU_C_ENVIRONMENT *_status);
extern void _Test1_TheO1_a_RO__clientstub (Test1_TheO1 _handle, Test1_RO ro, ILU_C_ENVIRONMENT *_status);
extern Test1_O2 _Test1_TheO1_get_O2__clientstub (Test1_TheO1 _handle, ILU_C_ENVIRONMENT *_status);
extern Test1_O3 _Test1_TheO1_get_O3__clientstub (Test1_TheO1 _handle, CORBA_boolean subclass, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _Test1_O2__ILUType;
extern Test1_CSS* _Test1_O2_OO_A0_to_CSS__clientstub (Test1_O2 _handle, Test1_OO o, Test1_A0 a, ILU_C_ENVIRONMENT *_status);
extern Test1_A0_slice * _Test1_O2_R_I_A1_to_I_A0__clientstub (Test1_O2 _handle, Test1_R* r, Test1_I* i, Test1_A1 a, ILU_C_ENVIRONMENT *_status);

extern void _Test1__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Test1_h_ */
