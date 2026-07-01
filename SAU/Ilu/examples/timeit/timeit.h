/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Jul 11 06:49:49 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Thu Jul 10 17:58:44 2025
 * on "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/Opensrc/Ilusrc/examples/timeit/timeit.idl" of Thu Dec 28 15:50:26 2023,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Thu Jun 19 13:16:01 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __timeit_h_
#define __timeit_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                              timeit                              ***/
/************************************************************************/
/************************************************************************/

extern void timeit__Initialize(void);
extern void timeit__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT timeit_p;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _timeit_pageSeq__sequence timeit_pageSeq;
typedef CORBA_double timeit_img20x20x20[20][20][20];
typedef CORBA_double timeit_img20x20x20_slice[20][20];
typedef struct _timeit_recseq__sequence timeit_recseq;
typedef struct timeit_rec timeit_rec;
typedef CORBA_char timeit_char32[32];
typedef CORBA_char timeit_char32_slice;
typedef struct _timeit_pageimg__sequence timeit_pageimg;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* sequence type "timeit_pageSeq" */
struct _timeit_pageSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 timeit_pageimg *_buffer;
};
void timeit_pageSeq_Every (timeit_pageSeq *h, void (*f)(timeit_pageimg*, void *, ilu_Error *), void *);
void timeit_pageSeq_Append (timeit_pageSeq *h, timeit_pageimg* item, ilu_Error *);
void timeit_pageSeq_Push (timeit_pageSeq *h, timeit_pageimg* item);
void timeit_pageSeq_Pop (timeit_pageSeq *h, timeit_pageimg* item);
CORBA_unsigned_long timeit_pageSeq_Length (timeit_pageSeq *);
timeit_pageimg * timeit_pageSeq_Nth (timeit_pageSeq *, CORBA_unsigned_long);
timeit_pageSeq * timeit_pageSeq_Create (CORBA_unsigned_long /* size */, timeit_pageimg*  /* init val */);
void timeit_pageSeq_Init (timeit_pageSeq * /* seq */, CORBA_unsigned_long /* size */, timeit_pageimg*  /* init val */);
timeit_pageSeq *
  CORBA_sequence_timeit_pageSeq_allocbuf (CORBA_unsigned_long /* count */);

timeit_img20x20x20 *
  CORBA_sequence_timeit_img20x20x20_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "timeit_recseq" */
struct _timeit_recseq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 timeit_rec *_buffer;
};
void timeit_recseq_Every (timeit_recseq *h, void (*f)(timeit_rec*, void *, ilu_Error *), void *);
void timeit_recseq_Append (timeit_recseq *h, timeit_rec* item, ilu_Error *);
void timeit_recseq_Push (timeit_recseq *h, timeit_rec* item);
void timeit_recseq_Pop (timeit_recseq *h, timeit_rec* item);
CORBA_unsigned_long timeit_recseq_Length (timeit_recseq *);
timeit_rec * timeit_recseq_Nth (timeit_recseq *, CORBA_unsigned_long);
timeit_recseq * timeit_recseq_Create (CORBA_unsigned_long /* size */, timeit_rec*  /* init val */);
void timeit_recseq_Init (timeit_recseq * /* seq */, CORBA_unsigned_long /* size */, timeit_rec*  /* init val */);
timeit_recseq *
  CORBA_sequence_timeit_recseq_allocbuf (CORBA_unsigned_long /* count */);

timeit_p *
  CORBA_sequence_timeit_p_allocbuf (CORBA_unsigned_long /* count */);

timeit_char32 *
  CORBA_sequence_timeit_char32_allocbuf (CORBA_unsigned_long /* count */);

/* record "timeit_rec" */
struct timeit_rec {
	timeit_char32 name;
	CORBA_boolean dirty;
	CORBA_unsigned_long create_time;
};
timeit_rec *
  CORBA_sequence_timeit_rec_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "timeit_pageimg" */
struct _timeit_pageimg__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_octet *_buffer;
};
void timeit_pageimg_Every (timeit_pageimg *h, void (*f)(CORBA_octet*, void *, ilu_Error *), void *);
void timeit_pageimg_Append (timeit_pageimg *h, CORBA_octet item, ilu_Error *);
void timeit_pageimg_Push (timeit_pageimg *h, CORBA_octet item);
void timeit_pageimg_Pop (timeit_pageimg *h, CORBA_octet *item);
CORBA_unsigned_long timeit_pageimg_Length (timeit_pageimg *);
CORBA_octet * timeit_pageimg_Nth (timeit_pageimg *, CORBA_unsigned_long);
timeit_pageimg * timeit_pageimg_Create (CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
void timeit_pageimg_Init (timeit_pageimg * /* seq */, CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
timeit_pageimg *
  CORBA_sequence_timeit_pageimg_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "timeit_p"  ----------------------------------------*/

#define timeit_p__MSType _timeit_p__ILUType

timeit_p
  timeit_p__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  timeit_p__SetUserData (timeit_p /* self */, void * /* userData */);
void *
  timeit_p__GetUserData (timeit_p /* self */);

extern timeit_p
  timeit_p__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default timeit_p class */

extern timeit_p
  timeit_p__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern CORBA_unsigned_long server_timeit_p_ping1 (timeit_p _handle, CORBA_unsigned_long p1, ILU_C_ENVIRONMENT *_status);

extern CORBA_double server_timeit_p_ping2 (timeit_p _handle, CORBA_double p2, ILU_C_ENVIRONMENT *_status);

extern ilu_CString server_timeit_p_ping3 (timeit_p _handle, ilu_CString p3, ILU_C_ENVIRONMENT *_status);

extern timeit_pageSeq* server_timeit_p_doctest (timeit_p _handle, ilu_CString name, CORBA_unsigned_long count, CORBA_unsigned_long pagesize, ILU_C_ENVIRONMENT *_status);

extern void server_timeit_p_imgtest (timeit_p _handle, timeit_img20x20x20 val, ILU_C_ENVIRONMENT *_status);

extern void server_timeit_p_rectest (timeit_p _handle, timeit_recseq* val, ILU_C_ENVIRONMENT *_status);

extern void timeit_p__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class timeit_p__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class timeit_p__MakeClass(
  CORBA_unsigned_long (*timeit_p_ping1__Impl)
     (timeit_p _handle, CORBA_unsigned_long p1, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*timeit_p_ping2__Impl)
     (timeit_p _handle, CORBA_double p2, ILU_C_ENVIRONMENT *_status),
  ilu_CString (*timeit_p_ping3__Impl)
     (timeit_p _handle, ilu_CString p3, ILU_C_ENVIRONMENT *_status),
  timeit_pageSeq* (*timeit_p_doctest__Impl)
     (timeit_p _handle, ilu_CString name, CORBA_unsigned_long count, CORBA_unsigned_long pagesize, ILU_C_ENVIRONMENT *_status),
  void (*timeit_p_imgtest__Impl)
     (timeit_p _handle, timeit_img20x20x20 val, ILU_C_ENVIRONMENT *_status),
  void (*timeit_p_rectest__Impl)
     (timeit_p _handle, timeit_recseq* val, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern CORBA_unsigned_long
  timeit_p_ping1 (timeit_p, CORBA_unsigned_long, ILU_C_ENVIRONMENT *);

extern CORBA_double
  timeit_p_ping2 (timeit_p, CORBA_double, ILU_C_ENVIRONMENT *);

extern ilu_CString
  timeit_p_ping3 (timeit_p, ilu_CString, ILU_C_ENVIRONMENT *);

extern timeit_pageSeq*
  timeit_p_doctest (timeit_p, ilu_CString, CORBA_unsigned_long, CORBA_unsigned_long, ILU_C_ENVIRONMENT *);

extern void
  timeit_p_imgtest (timeit_p, timeit_img20x20x20, ILU_C_ENVIRONMENT *);

extern void
  timeit_p_rectest (timeit_p, timeit_recseq*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void timeit__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _timeit_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _timeit_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _timeit_p__IoFns;
#define TC_timeit_p (& _timeit_p__IoFns)
extern void timeit_p__Free (timeit_p*);
extern struct _ILU_C_IoFnsRegistration_s _timeit_recseq__IoFns;
#define TC_timeit_recseq (& _timeit_recseq__IoFns)
extern void _timeit_recseq__Output (ilu_Call, timeit_recseq*, ilu_Error *);
extern ilu_cardinal _timeit_recseq__SizeOf (ilu_Call, timeit_recseq*, ilu_Error *);
extern timeit_recseq* _timeit_recseq__Input (ilu_Call, timeit_recseq*, ilu_Error *);
extern void timeit_recseq__Free (timeit_recseq*);
timeit_recseq* timeit_recseq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _timeit_rec__IoFns;
#define TC_timeit_rec (& _timeit_rec__IoFns)
extern void _timeit_rec__Output (ilu_Call, timeit_rec*, ilu_Error *);
extern ilu_cardinal _timeit_rec__SizeOf (ilu_Call, timeit_rec*, ilu_Error *);
extern timeit_rec* _timeit_rec__Input (ilu_Call, timeit_rec*, ilu_Error *);
timeit_rec* timeit_rec__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _timeit_char32__IoFns;
#define TC_timeit_char32 (& _timeit_char32__IoFns)
extern void _timeit_char32__Output (ilu_Call, timeit_char32, ilu_Error *);
extern ilu_cardinal _timeit_char32__SizeOf (ilu_Call, timeit_char32, ilu_Error *);
extern timeit_char32_slice * _timeit_char32__Input (ilu_Call, timeit_char32, ilu_Error *);
timeit_char32_slice * timeit_char32__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _timeit_img20x20x20__IoFns;
#define TC_timeit_img20x20x20 (& _timeit_img20x20x20__IoFns)
extern void _timeit_img20x20x20__Output (ilu_Call, timeit_img20x20x20, ilu_Error *);
extern ilu_cardinal _timeit_img20x20x20__SizeOf (ilu_Call, timeit_img20x20x20, ilu_Error *);
extern timeit_img20x20x20_slice * _timeit_img20x20x20__Input (ilu_Call, timeit_img20x20x20, ilu_Error *);
timeit_img20x20x20_slice * timeit_img20x20x20__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _timeit_pageSeq__IoFns;
#define TC_timeit_pageSeq (& _timeit_pageSeq__IoFns)
extern void _timeit_pageSeq__Output (ilu_Call, timeit_pageSeq*, ilu_Error *);
extern ilu_cardinal _timeit_pageSeq__SizeOf (ilu_Call, timeit_pageSeq*, ilu_Error *);
extern timeit_pageSeq* _timeit_pageSeq__Input (ilu_Call, timeit_pageSeq*, ilu_Error *);
extern void timeit_pageSeq__Free (timeit_pageSeq*);
timeit_pageSeq* timeit_pageSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _timeit_pageimg__IoFns;
#define TC_timeit_pageimg (& _timeit_pageimg__IoFns)
extern void _timeit_pageimg__Output (ilu_Call, timeit_pageimg*, ilu_Error *);
extern ilu_cardinal _timeit_pageimg__SizeOf (ilu_Call, timeit_pageimg*, ilu_Error *);
extern timeit_pageimg* _timeit_pageimg__Input (ilu_Call, timeit_pageimg*, ilu_Error *);
extern void timeit_pageimg__Free (timeit_pageimg*);
timeit_pageimg* timeit_pageimg__alloc (void);

extern ilu_Class _timeit_p__ILUType;
extern CORBA_unsigned_long _timeit_p_ping1__clientstub (timeit_p _handle, CORBA_unsigned_long p1, ILU_C_ENVIRONMENT *_status);
extern CORBA_double _timeit_p_ping2__clientstub (timeit_p _handle, CORBA_double p2, ILU_C_ENVIRONMENT *_status);
extern ilu_CString _timeit_p_ping3__clientstub (timeit_p _handle, ilu_CString p3, ILU_C_ENVIRONMENT *_status);
extern timeit_pageSeq* _timeit_p_doctest__clientstub (timeit_p _handle, ilu_CString name, CORBA_unsigned_long count, CORBA_unsigned_long pagesize, ILU_C_ENVIRONMENT *_status);
extern void _timeit_p_imgtest__clientstub (timeit_p _handle, timeit_img20x20x20 val, ILU_C_ENVIRONMENT *_status);
extern void _timeit_p_rectest__clientstub (timeit_p _handle, timeit_recseq* val, ILU_C_ENVIRONMENT *_status);

extern void _timeit__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __timeit_h_ */
