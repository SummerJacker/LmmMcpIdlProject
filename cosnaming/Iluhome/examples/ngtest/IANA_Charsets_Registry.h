/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:00 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/ianacharsets.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __IANA_Charsets_Registry_h_
#define __IANA_Charsets_Registry_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                      IANA-Charsets-Registry                      ***/
/************************************************************************/
/************************************************************************/

extern void IANA_Charsets_Registry__Initialize(void);
extern void IANA_Charsets_Registry__InitializeServer(void);



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef CORBA_unsigned_short IANA_Charsets_Registry_CharsetMIBEnumValue;
typedef CORBA_unsigned_short *IANA_Charsets_Registry_OptionalCharsetMIBEnumValue;
typedef struct _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__sequence IANA_Charsets_Registry_CharsetMIBEnumValueSequence;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* "IANA_Charsets_Registry_CharsetMIBEnumValue" alias for "CORBA_unsigned_short" */
#define CORBA_sequence_IANA_Charsets_Registry_CharsetMIBEnumValue_allocbuf CORBA_sequence_unsigned_short_allocbuf

IANA_Charsets_Registry_OptionalCharsetMIBEnumValue *
  CORBA_sequence_IANA_Charsets_Registry_OptionalCharsetMIBEnumValue_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "IANA_Charsets_Registry_CharsetMIBEnumValueSequence" */
struct _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__sequence {
 unsigned long _maximum;
 unsigned long _length;
 IANA_Charsets_Registry_CharsetMIBEnumValue *_buffer;
};
void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Every (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, void (*f)(IANA_Charsets_Registry_CharsetMIBEnumValue*, void *, ilu_Error *), void *);
void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Append (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, IANA_Charsets_Registry_CharsetMIBEnumValue item, ilu_Error *);
void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Push (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, IANA_Charsets_Registry_CharsetMIBEnumValue item);
void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Pop (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *h, IANA_Charsets_Registry_CharsetMIBEnumValue *item);
CORBA_unsigned_long IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Length (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *);
IANA_Charsets_Registry_CharsetMIBEnumValue * IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Nth (IANA_Charsets_Registry_CharsetMIBEnumValueSequence *, CORBA_unsigned_long);
IANA_Charsets_Registry_CharsetMIBEnumValueSequence * IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Create (CORBA_unsigned_long /* size */, IANA_Charsets_Registry_CharsetMIBEnumValue * /* init val */);
void IANA_Charsets_Registry_CharsetMIBEnumValueSequence_Init (IANA_Charsets_Registry_CharsetMIBEnumValueSequence * /* seq */, CORBA_unsigned_long /* size */, IANA_Charsets_Registry_CharsetMIBEnumValue * /* init val */);
IANA_Charsets_Registry_CharsetMIBEnumValueSequence *
  CORBA_sequence_IANA_Charsets_Registry_CharsetMIBEnumValueSequence_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*=========================== constants ================================*/

static const unsigned short IANA_Charsets_Registry_US_ASCII = 0x3;


/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void IANA_Charsets_Registry__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _IANA_Charsets_Registry_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _IANA_Charsets_Registry_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns;
#define TC_IANA_Charsets_Registry_OptionalCharsetMIBEnumValue (& _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__IoFns)
extern void _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Output (ilu_Call, IANA_Charsets_Registry_OptionalCharsetMIBEnumValue, ilu_Error *);
extern ilu_cardinal _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__SizeOf (ilu_Call, IANA_Charsets_Registry_OptionalCharsetMIBEnumValue, ilu_Error *);
extern IANA_Charsets_Registry_OptionalCharsetMIBEnumValue* _IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Input (ilu_Call, IANA_Charsets_Registry_OptionalCharsetMIBEnumValue*, ilu_Error *);
extern void IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__Free (IANA_Charsets_Registry_OptionalCharsetMIBEnumValue*);
IANA_Charsets_Registry_OptionalCharsetMIBEnumValue* IANA_Charsets_Registry_OptionalCharsetMIBEnumValue__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns;
#define TC_IANA_Charsets_Registry_CharsetMIBEnumValueSequence (& _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__IoFns)
extern void _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Output (ilu_Call, IANA_Charsets_Registry_CharsetMIBEnumValueSequence*, ilu_Error *);
extern ilu_cardinal _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__SizeOf (ilu_Call, IANA_Charsets_Registry_CharsetMIBEnumValueSequence*, ilu_Error *);
extern IANA_Charsets_Registry_CharsetMIBEnumValueSequence* _IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Input (ilu_Call, IANA_Charsets_Registry_CharsetMIBEnumValueSequence*, ilu_Error *);
extern void IANA_Charsets_Registry_CharsetMIBEnumValueSequence__Free (IANA_Charsets_Registry_CharsetMIBEnumValueSequence*);
IANA_Charsets_Registry_CharsetMIBEnumValueSequence* IANA_Charsets_Registry_CharsetMIBEnumValueSequence__alloc (void);
#define _IANA_Charsets_Registry_CharsetMIBEnumValue__IoFns _CORBA_unsigned_short__IoFns
#define TC_IANA_Charsets_Registry_CharsetMIBEnumValue (& _IANA_Charsets_Registry_CharsetMIBEnumValue__IoFns)

extern void _IANA_Charsets_Registry__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __IANA_Charsets_Registry_h_ */
