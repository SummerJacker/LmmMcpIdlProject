/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:24 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test2/Fibber.isl" of Sat Aug 02 18:52:05 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test2/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Fibber_h_
#define __Fibber_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                              Fibber                              ***/
/************************************************************************/
/************************************************************************/

extern void Fibber__Initialize(void);
extern void Fibber__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Fibber_T;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct _Fibber_StringSeq__sequence Fibber_StringSeq;
typedef CORBA_char * Fibber_String;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

Fibber_T *
  CORBA_sequence_Fibber_T_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Fibber_StringSeq" */
struct _Fibber_StringSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Fibber_String *_buffer;
};
void Fibber_StringSeq_Every (Fibber_StringSeq *h, void (*f)(Fibber_String*, void *, ilu_Error *), void *);
void Fibber_StringSeq_Append (Fibber_StringSeq *h, Fibber_String item, ilu_Error *);
void Fibber_StringSeq_Push (Fibber_StringSeq *h, Fibber_String item);
void Fibber_StringSeq_Pop (Fibber_StringSeq *h, Fibber_String *item);
CORBA_unsigned_long Fibber_StringSeq_Length (Fibber_StringSeq *);
Fibber_String * Fibber_StringSeq_Nth (Fibber_StringSeq *, CORBA_unsigned_long);
Fibber_StringSeq * Fibber_StringSeq_Create (CORBA_unsigned_long /* size */, Fibber_String * /* init val */);
void Fibber_StringSeq_Init (Fibber_StringSeq * /* seq */, CORBA_unsigned_long /* size */, Fibber_String * /* init val */);
Fibber_StringSeq *
  CORBA_sequence_Fibber_StringSeq_allocbuf (CORBA_unsigned_long /* count */);

void Fibber_String_Every (Fibber_String *h, void (*f)(CORBA_char *, void *, ilu_Error *), void *);
void Fibber_String_Append (Fibber_String *, CORBA_char, ilu_Error *);
void Fibber_String_Push (Fibber_String *, CORBA_char);
void Fibber_String_Pop (Fibber_String *, CORBA_char *);
CORBA_unsigned_long Fibber_String_Length (Fibber_String *);
CORBA_char * Fibber_String_Nth (Fibber_String *, CORBA_unsigned_long);
Fibber_String Fibber_String_Create (CORBA_unsigned_long, CORBA_char *);
void Fibber_String_Init (Fibber_String *, CORBA_unsigned_long);
Fibber_String *
  CORBA_sequence_Fibber_String_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _Fibber__Exception_Failed;
#define ex_Fibber_Failed _Fibber__Exception_Failed


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Fibber_T"  ----------------------------------------*/

#define Fibber_T__MSType _Fibber_T__ILUType

Fibber_T
  Fibber_T__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Fibber_T__SetUserData (Fibber_T /* self */, void * /* userData */);
void *
  Fibber_T__GetUserData (Fibber_T /* self */);

extern Fibber_T
  Fibber_T__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Fibber_T class */

extern Fibber_T
  Fibber_T__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern CORBA_unsigned_long server_Fibber_T_Calc (Fibber_T _handle, CORBA_unsigned_long d, CORBA_unsigned_long n, Fibber_T ask, ILU_C_ENVIRONMENT *_status);

extern void Fibber_T__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Fibber_T__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Fibber_T__MakeClass(
  CORBA_unsigned_long (*Fibber_T_Calc__Impl)
     (Fibber_T _handle, CORBA_unsigned_long d, CORBA_unsigned_long n, Fibber_T ask, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern CORBA_unsigned_long  /* exceptions:  Failed */
  Fibber_T_Calc (Fibber_T, CORBA_unsigned_long, CORBA_unsigned_long, Fibber_T, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Fibber__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Fibber_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Fibber_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Fibber_T__IoFns;
#define TC_Fibber_T (& _Fibber_T__IoFns)
extern void Fibber_T__Free (Fibber_T*);
extern struct _ILU_C_IoFnsRegistration_s _Fibber_StringSeq__IoFns;
#define TC_Fibber_StringSeq (& _Fibber_StringSeq__IoFns)
extern void _Fibber_StringSeq__Output (ilu_Call, Fibber_StringSeq*, ilu_Error *);
extern ilu_cardinal _Fibber_StringSeq__SizeOf (ilu_Call, Fibber_StringSeq*, ilu_Error *);
extern Fibber_StringSeq* _Fibber_StringSeq__Input (ilu_Call, Fibber_StringSeq*, ilu_Error *);
extern void Fibber_StringSeq__Free (Fibber_StringSeq*);
Fibber_StringSeq* Fibber_StringSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Fibber_String__IoFns;
#define TC_Fibber_String (& _Fibber_String__IoFns)
extern void _Fibber_String__Output (ilu_Call, Fibber_String, ilu_Error *);
extern ilu_cardinal _Fibber_String__SizeOf (ilu_Call, Fibber_String, ilu_Error *);
extern Fibber_String* _Fibber_String__Input (ilu_Call, Fibber_String*, ilu_Error *);
extern void Fibber_String__Free (Fibber_String*);
Fibber_String* Fibber_String__alloc (void);

extern ilu_Class _Fibber_T__ILUType;
extern CORBA_unsigned_long _Fibber_T_Calc__clientstub (Fibber_T _handle, CORBA_unsigned_long d, CORBA_unsigned_long n, Fibber_T ask, ILU_C_ENVIRONMENT *_status);

extern void _Fibber__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Fibber_h_ */
