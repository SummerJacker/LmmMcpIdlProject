/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:25 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test2/Batcher.isl" of Sat Aug 02 18:52:05 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test2/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Batcher_h_
#define __Batcher_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             Batcher                              ***/
/************************************************************************/
/************************************************************************/

extern void Batcher__Initialize(void);
extern void Batcher__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Batcher_T;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef CORBA_unsigned_long_long Batcher_Time;
typedef struct _Batcher_TimeSeq__sequence Batcher_TimeSeq;
typedef struct Batcher_TimeRec Batcher_TimeRec;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* "Batcher_Time" alias for "CORBA_unsigned_long_long" */
#define CORBA_sequence_Batcher_Time_allocbuf CORBA_sequence_unsigned_long_long_allocbuf

/* sequence type "Batcher_TimeSeq" */
struct _Batcher_TimeSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Batcher_TimeRec *_buffer;
};
void Batcher_TimeSeq_Every (Batcher_TimeSeq *h, void (*f)(Batcher_TimeRec*, void *, ilu_Error *), void *);
void Batcher_TimeSeq_Append (Batcher_TimeSeq *h, Batcher_TimeRec* item, ilu_Error *);
void Batcher_TimeSeq_Push (Batcher_TimeSeq *h, Batcher_TimeRec* item);
void Batcher_TimeSeq_Pop (Batcher_TimeSeq *h, Batcher_TimeRec* item);
CORBA_unsigned_long Batcher_TimeSeq_Length (Batcher_TimeSeq *);
Batcher_TimeRec * Batcher_TimeSeq_Nth (Batcher_TimeSeq *, CORBA_unsigned_long);
Batcher_TimeSeq * Batcher_TimeSeq_Create (CORBA_unsigned_long /* size */, Batcher_TimeRec*  /* init val */);
void Batcher_TimeSeq_Init (Batcher_TimeSeq * /* seq */, CORBA_unsigned_long /* size */, Batcher_TimeRec*  /* init val */);
Batcher_TimeSeq *
  CORBA_sequence_Batcher_TimeSeq_allocbuf (CORBA_unsigned_long /* count */);

Batcher_T *
  CORBA_sequence_Batcher_T_allocbuf (CORBA_unsigned_long /* count */);

/* record "Batcher_TimeRec" */
struct Batcher_TimeRec {
	Batcher_Time s;
	Batcher_Time r;
};
Batcher_TimeRec *
  CORBA_sequence_Batcher_TimeRec_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Batcher_T"  ---------------------------------------*/

#define Batcher_T__MSType _Batcher_T__ILUType

Batcher_T
  Batcher_T__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Batcher_T__SetUserData (Batcher_T /* self */, void * /* userData */);
void *
  Batcher_T__GetUserData (Batcher_T /* self */);

extern Batcher_T
  Batcher_T__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Batcher_T class */

extern Batcher_T
  Batcher_T__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern void server_Batcher_T_Send (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status);

extern Batcher_TimeSeq* server_Batcher_T_Sync (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status);

extern void Batcher_T__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Batcher_T__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Batcher_T__MakeClass(
  void (*Batcher_T_Send__Impl)
     (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status),
  Batcher_TimeSeq* (*Batcher_T_Sync__Impl)
     (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void
  Batcher_T_Send (Batcher_T, Batcher_Time, ILU_C_ENVIRONMENT *);

extern Batcher_TimeSeq*
  Batcher_T_Sync (Batcher_T, Batcher_Time, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Batcher__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Batcher_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Batcher_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Batcher_T__IoFns;
#define TC_Batcher_T (& _Batcher_T__IoFns)
extern void Batcher_T__Free (Batcher_T*);
extern struct _ILU_C_IoFnsRegistration_s _Batcher_TimeSeq__IoFns;
#define TC_Batcher_TimeSeq (& _Batcher_TimeSeq__IoFns)
extern void _Batcher_TimeSeq__Output (ilu_Call, Batcher_TimeSeq*, ilu_Error *);
extern ilu_cardinal _Batcher_TimeSeq__SizeOf (ilu_Call, Batcher_TimeSeq*, ilu_Error *);
extern Batcher_TimeSeq* _Batcher_TimeSeq__Input (ilu_Call, Batcher_TimeSeq*, ilu_Error *);
extern void Batcher_TimeSeq__Free (Batcher_TimeSeq*);
Batcher_TimeSeq* Batcher_TimeSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Batcher_TimeRec__IoFns;
#define TC_Batcher_TimeRec (& _Batcher_TimeRec__IoFns)
extern void _Batcher_TimeRec__Output (ilu_Call, Batcher_TimeRec*, ilu_Error *);
extern ilu_cardinal _Batcher_TimeRec__SizeOf (ilu_Call, Batcher_TimeRec*, ilu_Error *);
extern Batcher_TimeRec* _Batcher_TimeRec__Input (ilu_Call, Batcher_TimeRec*, ilu_Error *);
Batcher_TimeRec* Batcher_TimeRec__alloc (void);
#define _Batcher_Time__IoFns _CORBA_unsigned_long_long__IoFns
#define TC_Batcher_Time (& _Batcher_Time__IoFns)

extern ilu_Class _Batcher_T__ILUType;
extern void _Batcher_T_Send__clientstub (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status);
extern Batcher_TimeSeq* _Batcher_T_Sync__clientstub (Batcher_T _handle, Batcher_Time s, ILU_C_ENVIRONMENT *_status);

extern void _Batcher__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Batcher_h_ */
