/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:31 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/iiop/iioptest1.isl" of Tue Sep 21 06:54:02 1999,
 * and "D:/Shaun-projects/newstar/Iluhome/Interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __iioptest1_h_
#define __iioptest1_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                            iioptest1                             ***/
/************************************************************************/
/************************************************************************/

extern void iioptest1__Initialize(void);
extern void iioptest1__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT iioptest1_xilu_obj;
typedef ILU_C_OBJECT iioptest1_ext_obj;
typedef ILU_C_OBJECT iioptest1_obj;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef CORBA_char * iioptest1_string;
typedef CORBA_wchar * iioptest1_UnicodeString;
typedef struct iioptest1_rec2 iioptest1_rec2;
typedef enum {iioptest1_a = 0, iioptest1_b = 1, iioptest1_c = 2, iioptest1_d = 3, iioptest1_e = 4} iioptest1_enum1;
typedef struct _iioptest1_seq1__sequence iioptest1_seq1;
typedef struct iioptest1_rec1 iioptest1_rec1;
typedef struct iioptest1_rec1 iioptest1_arr1[2][3];
typedef struct iioptest1_rec1 iioptest1_arr1_slice[3];
typedef struct iioptest1_rec2 iioptest1_arr4[2][3];
typedef struct iioptest1_rec2 iioptest1_arr4_slice[3];
typedef struct _iioptest1_union1_union iioptest1_union1;
typedef struct _iioptest1_union2_union iioptest1_union2;
typedef iioptest1_rec2 *iioptest1_opt1;
typedef CORBA_char iioptest1_arr3[2][3];
typedef CORBA_char iioptest1_arr3_slice[3];
typedef CORBA_char * iioptest1_arr2[2][3];
typedef CORBA_char * iioptest1_arr2_slice[3];
typedef struct iioptest1_x1_rec iioptest1_x1_rec;
typedef struct iioptest1_x2_rec iioptest1_x2_rec;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

void iioptest1_string_Every (iioptest1_string *h, void (*f)(CORBA_char *, void *, ilu_Error *), void *);
void iioptest1_string_Append (iioptest1_string *, CORBA_char, ilu_Error *);
void iioptest1_string_Push (iioptest1_string *, CORBA_char);
void iioptest1_string_Pop (iioptest1_string *, CORBA_char *);
CORBA_unsigned_long iioptest1_string_Length (iioptest1_string *);
CORBA_char * iioptest1_string_Nth (iioptest1_string *, CORBA_unsigned_long);
iioptest1_string iioptest1_string_Create (CORBA_unsigned_long, CORBA_char *);
void iioptest1_string_Init (iioptest1_string *, CORBA_unsigned_long);
iioptest1_string *
  CORBA_sequence_iioptest1_string_allocbuf (CORBA_unsigned_long /* count */);

void iioptest1_UnicodeString_Every (iioptest1_UnicodeString *h, void (*f)(CORBA_wchar *, void *, ilu_Error *), void *);
void iioptest1_UnicodeString_Append (iioptest1_UnicodeString *, CORBA_wchar, ilu_Error *);
void iioptest1_UnicodeString_Push (iioptest1_UnicodeString *, CORBA_wchar);
void iioptest1_UnicodeString_Pop (iioptest1_UnicodeString *, CORBA_wchar *);
CORBA_unsigned_long iioptest1_UnicodeString_Length (iioptest1_UnicodeString *);
CORBA_wchar * iioptest1_UnicodeString_Nth (iioptest1_UnicodeString *, CORBA_unsigned_long);
iioptest1_UnicodeString iioptest1_UnicodeString_Create (CORBA_unsigned_long, CORBA_wchar *);
void iioptest1_UnicodeString_Init (iioptest1_UnicodeString *, CORBA_unsigned_long);
iioptest1_UnicodeString *
  CORBA_sequence_iioptest1_UnicodeString_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_obj *
  CORBA_sequence_iioptest1_obj_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_ext_obj *
  CORBA_sequence_iioptest1_ext_obj_allocbuf (CORBA_unsigned_long /* count */);

/* record "iioptest1_rec2" */
struct iioptest1_rec2 {
	CORBA_short f1;
	CORBA_octet f2;
};
iioptest1_rec2 *
  CORBA_sequence_iioptest1_rec2_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_enum1 *
  CORBA_sequence_iioptest1_enum1_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "iioptest1_seq1" */
struct _iioptest1_seq1__sequence {
 unsigned long _maximum;
 unsigned long _length;
 iioptest1_rec2 *_buffer;
};
void iioptest1_seq1_Every (iioptest1_seq1 *h, void (*f)(iioptest1_rec2*, void *, ilu_Error *), void *);
void iioptest1_seq1_Append (iioptest1_seq1 *h, iioptest1_rec2* item, ilu_Error *);
void iioptest1_seq1_Push (iioptest1_seq1 *h, iioptest1_rec2* item);
void iioptest1_seq1_Pop (iioptest1_seq1 *h, iioptest1_rec2* item);
CORBA_unsigned_long iioptest1_seq1_Length (iioptest1_seq1 *);
iioptest1_rec2 * iioptest1_seq1_Nth (iioptest1_seq1 *, CORBA_unsigned_long);
iioptest1_seq1 * iioptest1_seq1_Create (CORBA_unsigned_long /* size */, iioptest1_rec2*  /* init val */);
void iioptest1_seq1_Init (iioptest1_seq1 * /* seq */, CORBA_unsigned_long /* size */, iioptest1_rec2*  /* init val */);
iioptest1_seq1 *
  CORBA_sequence_iioptest1_seq1_allocbuf (CORBA_unsigned_long /* count */);

/* record "iioptest1_rec1" */
struct iioptest1_rec1 {
	CORBA_short f1;
	CORBA_long f2;
	CORBA_unsigned_short f3;
	CORBA_unsigned_long f4;
	CORBA_octet f5;
	CORBA_boolean f6;
	CORBA_float f7;
	CORBA_double f8;
	iioptest1_string f9;
};
iioptest1_rec1 *
  CORBA_sequence_iioptest1_rec1_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_arr1 *
  CORBA_sequence_iioptest1_arr1_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_arr4 *
  CORBA_sequence_iioptest1_arr4_allocbuf (CORBA_unsigned_long /* count */);

/* union "iioptest1_union1" */

struct _iioptest1_union1_union {
	iioptest1_enum1 _d;
	union {
		iioptest1_rec1 a;	/* iioptest1_a */
		iioptest1_arr1 b;	/* iioptest1_b */
		iioptest1_seq1 c;	/* iioptest1_c */
		iioptest1_enum1 d;	/* DEFAULT */
	} _u;
};
iioptest1_union1 *
  CORBA_sequence_iioptest1_union1_allocbuf (CORBA_unsigned_long /* count */);

/* union "iioptest1_union2" */

struct _iioptest1_union2_union {
	CORBA_short _d;
	union {
		CORBA_long integer;	/* 0 */
		CORBA_double real;	/* 1 */
	} _u;
};
iioptest1_union2 *
  CORBA_sequence_iioptest1_union2_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_opt1 *
  CORBA_sequence_iioptest1_opt1_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_xilu_obj *
  CORBA_sequence_iioptest1_xilu_obj_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_arr3 *
  CORBA_sequence_iioptest1_arr3_allocbuf (CORBA_unsigned_long /* count */);

iioptest1_arr2 *
  CORBA_sequence_iioptest1_arr2_allocbuf (CORBA_unsigned_long /* count */);

/* record "iioptest1_x1_rec" */
struct iioptest1_x1_rec {
	CORBA_long case_num;
};
iioptest1_x1_rec *
  CORBA_sequence_iioptest1_x1_rec_allocbuf (CORBA_unsigned_long /* count */);

/* record "iioptest1_x2_rec" */
struct iioptest1_x2_rec {
	iioptest1_obj obj;
	CORBA_long case_num;
};
iioptest1_x2_rec *
  CORBA_sequence_iioptest1_x2_rec_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _iioptest1__Exception_x1;
#define ex_iioptest1_x1 _iioptest1__Exception_x1
extern ILU_C_ExceptionCode _iioptest1__Exception_x2;
#define ex_iioptest1_x2 _iioptest1__Exception_x2


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "iioptest1_xilu_obj"  ------------------------------*/

#define iioptest1_xilu_obj__MSType _iioptest1_xilu_obj__ILUType

iioptest1_xilu_obj
  iioptest1_xilu_obj__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  iioptest1_xilu_obj__SetUserData (iioptest1_xilu_obj /* self */, void * /* userData */);
void *
  iioptest1_xilu_obj__GetUserData (iioptest1_xilu_obj /* self */);

extern iioptest1_xilu_obj
  iioptest1_xilu_obj__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default iioptest1_xilu_obj class */

extern iioptest1_xilu_obj
  iioptest1_xilu_obj__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern void server_iioptest1_xilu_obj_test_void (iioptest1_xilu_obj _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_short server_iioptest1_xilu_obj_test_short (iioptest1_xilu_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long server_iioptest1_xilu_obj_test_long (iioptest1_xilu_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_short server_iioptest1_xilu_obj_test_ushort (iioptest1_xilu_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_long server_iioptest1_xilu_obj_test_ulong (iioptest1_xilu_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_float server_iioptest1_xilu_obj_test_float (iioptest1_xilu_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_double server_iioptest1_xilu_obj_test_double (iioptest1_xilu_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_iioptest1_xilu_obj_test_boolean (iioptest1_xilu_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_char server_iioptest1_xilu_obj_test_char (iioptest1_xilu_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_octet server_iioptest1_xilu_obj_test_octet (iioptest1_xilu_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_string server_iioptest1_xilu_obj_test_string (iioptest1_xilu_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long_long server_iioptest1_xilu_obj_test_longlong (iioptest1_xilu_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_long_long server_iioptest1_xilu_obj_test_ulonglong (iioptest1_xilu_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_wchar server_iioptest1_xilu_obj_test_wchar (iioptest1_xilu_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_UnicodeString server_iioptest1_xilu_obj_test_wstring (iioptest1_xilu_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long_double server_iioptest1_xilu_obj_test_longdouble (iioptest1_xilu_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status);

extern void server_iioptest1_xilu_obj_test_throw (iioptest1_xilu_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status);

extern void server_iioptest1_xilu_obj_please_exit (iioptest1_xilu_obj _handle, ILU_C_ENVIRONMENT *_status);

extern iioptest1_ext_obj server_iioptest1_xilu_obj_test_obj (iioptest1_xilu_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_rec2 server_iioptest1_xilu_obj_test_fixed_record (iioptest1_xilu_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_enum1 server_iioptest1_xilu_obj_test_enumeration (iioptest1_xilu_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_seq1* server_iioptest1_xilu_obj_test_sequence (iioptest1_xilu_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_rec1* server_iioptest1_xilu_obj_test_var_record (iioptest1_xilu_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_arr1_slice * server_iioptest1_xilu_obj_test_var_array (iioptest1_xilu_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_arr4_slice * server_iioptest1_xilu_obj_test_fixed_array (iioptest1_xilu_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_union1* server_iioptest1_xilu_obj_test_var_union (iioptest1_xilu_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_union2 server_iioptest1_xilu_obj_test_fixed_union (iioptest1_xilu_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_opt1 server_iioptest1_xilu_obj_test_optional (iioptest1_xilu_obj _handle, iioptest1_opt1 a1, iioptest1_opt1* a2, iioptest1_opt1* a3, ILU_C_ENVIRONMENT *_status);

extern void server_iioptest1_xilu_obj_test_asynchronous (iioptest1_xilu_obj _handle, CORBA_long a1, ILU_C_ENVIRONMENT *_status);

extern void iioptest1_xilu_obj__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class iioptest1_xilu_obj__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class iioptest1_xilu_obj__MakeClass(
  iioptest1_opt1 (*iioptest1_xilu_obj_test_optional__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_opt1 a1, iioptest1_opt1* a2, iioptest1_opt1* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_xilu_obj_test_asynchronous__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long a1, ILU_C_ENVIRONMENT *_status),
  iioptest1_ext_obj (*iioptest1_ext_obj_test_obj__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec2 (*iioptest1_ext_obj_test_fixed_record__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_enum1 (*iioptest1_ext_obj_test_enumeration__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_seq1* (*iioptest1_ext_obj_test_sequence__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec1* (*iioptest1_ext_obj_test_var_record__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr1_slice * (*iioptest1_ext_obj_test_var_array__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr4_slice * (*iioptest1_ext_obj_test_fixed_array__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union1* (*iioptest1_ext_obj_test_var_union__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union2 (*iioptest1_ext_obj_test_fixed_union__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_void__Impl)
     (iioptest1_xilu_obj _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*iioptest1_obj_test_short__Impl)
     (iioptest1_xilu_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*iioptest1_obj_test_long__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_short (*iioptest1_obj_test_ushort__Impl)
     (iioptest1_xilu_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long (*iioptest1_obj_test_ulong__Impl)
     (iioptest1_xilu_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*iioptest1_obj_test_float__Impl)
     (iioptest1_xilu_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*iioptest1_obj_test_double__Impl)
     (iioptest1_xilu_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*iioptest1_obj_test_boolean__Impl)
     (iioptest1_xilu_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_char (*iioptest1_obj_test_char__Impl)
     (iioptest1_xilu_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_octet (*iioptest1_obj_test_octet__Impl)
     (iioptest1_xilu_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_string (*iioptest1_obj_test_string__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_long (*iioptest1_obj_test_longlong__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long_long (*iioptest1_obj_test_ulonglong__Impl)
     (iioptest1_xilu_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_wchar (*iioptest1_obj_test_wchar__Impl)
     (iioptest1_xilu_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_UnicodeString (*iioptest1_obj_test_wstring__Impl)
     (iioptest1_xilu_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_double (*iioptest1_obj_test_longdouble__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_throw__Impl)
     (iioptest1_xilu_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_please_exit__Impl)
     (iioptest1_xilu_obj _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern iioptest1_opt1
  iioptest1_xilu_obj_test_optional (iioptest1_xilu_obj, iioptest1_opt1, iioptest1_opt1*, iioptest1_opt1*, ILU_C_ENVIRONMENT *);

extern void
  iioptest1_xilu_obj_test_asynchronous (iioptest1_xilu_obj, CORBA_long, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "iioptest1_ext_obj"  -------------------------------*/

#define iioptest1_ext_obj__MSType _iioptest1_ext_obj__ILUType

iioptest1_ext_obj
  iioptest1_ext_obj__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  iioptest1_ext_obj__SetUserData (iioptest1_ext_obj /* self */, void * /* userData */);
void *
  iioptest1_ext_obj__GetUserData (iioptest1_ext_obj /* self */);

extern iioptest1_ext_obj
  iioptest1_ext_obj__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default iioptest1_ext_obj class */

extern iioptest1_ext_obj
  iioptest1_ext_obj__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern void server_iioptest1_ext_obj_test_void (iioptest1_ext_obj _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_short server_iioptest1_ext_obj_test_short (iioptest1_ext_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long server_iioptest1_ext_obj_test_long (iioptest1_ext_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_short server_iioptest1_ext_obj_test_ushort (iioptest1_ext_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_long server_iioptest1_ext_obj_test_ulong (iioptest1_ext_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_float server_iioptest1_ext_obj_test_float (iioptest1_ext_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_double server_iioptest1_ext_obj_test_double (iioptest1_ext_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_iioptest1_ext_obj_test_boolean (iioptest1_ext_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_char server_iioptest1_ext_obj_test_char (iioptest1_ext_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_octet server_iioptest1_ext_obj_test_octet (iioptest1_ext_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_string server_iioptest1_ext_obj_test_string (iioptest1_ext_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long_long server_iioptest1_ext_obj_test_longlong (iioptest1_ext_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_long_long server_iioptest1_ext_obj_test_ulonglong (iioptest1_ext_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_wchar server_iioptest1_ext_obj_test_wchar (iioptest1_ext_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_UnicodeString server_iioptest1_ext_obj_test_wstring (iioptest1_ext_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long_double server_iioptest1_ext_obj_test_longdouble (iioptest1_ext_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status);

extern void server_iioptest1_ext_obj_test_throw (iioptest1_ext_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status);

extern void server_iioptest1_ext_obj_please_exit (iioptest1_ext_obj _handle, ILU_C_ENVIRONMENT *_status);

extern iioptest1_ext_obj server_iioptest1_ext_obj_test_obj (iioptest1_ext_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_rec2 server_iioptest1_ext_obj_test_fixed_record (iioptest1_ext_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_enum1 server_iioptest1_ext_obj_test_enumeration (iioptest1_ext_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_seq1* server_iioptest1_ext_obj_test_sequence (iioptest1_ext_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_rec1* server_iioptest1_ext_obj_test_var_record (iioptest1_ext_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_arr1_slice * server_iioptest1_ext_obj_test_var_array (iioptest1_ext_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_arr4_slice * server_iioptest1_ext_obj_test_fixed_array (iioptest1_ext_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_union1* server_iioptest1_ext_obj_test_var_union (iioptest1_ext_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_union2 server_iioptest1_ext_obj_test_fixed_union (iioptest1_ext_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status);

extern void iioptest1_ext_obj__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class iioptest1_ext_obj__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class iioptest1_ext_obj__MakeClass(
  iioptest1_ext_obj (*iioptest1_ext_obj_test_obj__Impl)
     (iioptest1_ext_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec2 (*iioptest1_ext_obj_test_fixed_record__Impl)
     (iioptest1_ext_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_enum1 (*iioptest1_ext_obj_test_enumeration__Impl)
     (iioptest1_ext_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_seq1* (*iioptest1_ext_obj_test_sequence__Impl)
     (iioptest1_ext_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_rec1* (*iioptest1_ext_obj_test_var_record__Impl)
     (iioptest1_ext_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr1_slice * (*iioptest1_ext_obj_test_var_array__Impl)
     (iioptest1_ext_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_arr4_slice * (*iioptest1_ext_obj_test_fixed_array__Impl)
     (iioptest1_ext_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union1* (*iioptest1_ext_obj_test_var_union__Impl)
     (iioptest1_ext_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_union2 (*iioptest1_ext_obj_test_fixed_union__Impl)
     (iioptest1_ext_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_void__Impl)
     (iioptest1_ext_obj _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*iioptest1_obj_test_short__Impl)
     (iioptest1_ext_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*iioptest1_obj_test_long__Impl)
     (iioptest1_ext_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_short (*iioptest1_obj_test_ushort__Impl)
     (iioptest1_ext_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long (*iioptest1_obj_test_ulong__Impl)
     (iioptest1_ext_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*iioptest1_obj_test_float__Impl)
     (iioptest1_ext_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*iioptest1_obj_test_double__Impl)
     (iioptest1_ext_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*iioptest1_obj_test_boolean__Impl)
     (iioptest1_ext_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_char (*iioptest1_obj_test_char__Impl)
     (iioptest1_ext_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_octet (*iioptest1_obj_test_octet__Impl)
     (iioptest1_ext_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_string (*iioptest1_obj_test_string__Impl)
     (iioptest1_ext_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_long (*iioptest1_obj_test_longlong__Impl)
     (iioptest1_ext_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long_long (*iioptest1_obj_test_ulonglong__Impl)
     (iioptest1_ext_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_wchar (*iioptest1_obj_test_wchar__Impl)
     (iioptest1_ext_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_UnicodeString (*iioptest1_obj_test_wstring__Impl)
     (iioptest1_ext_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_double (*iioptest1_obj_test_longdouble__Impl)
     (iioptest1_ext_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_throw__Impl)
     (iioptest1_ext_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_please_exit__Impl)
     (iioptest1_ext_obj _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern iioptest1_ext_obj
  iioptest1_ext_obj_test_obj (iioptest1_ext_obj, iioptest1_ext_obj, iioptest1_ext_obj*, iioptest1_ext_obj*, ILU_C_ENVIRONMENT *);

extern iioptest1_rec2
  iioptest1_ext_obj_test_fixed_record (iioptest1_ext_obj, iioptest1_rec2*, iioptest1_rec2*, iioptest1_rec2*, ILU_C_ENVIRONMENT *);

extern iioptest1_enum1
  iioptest1_ext_obj_test_enumeration (iioptest1_ext_obj, iioptest1_enum1, iioptest1_enum1*, iioptest1_enum1*, ILU_C_ENVIRONMENT *);

extern iioptest1_seq1*
  iioptest1_ext_obj_test_sequence (iioptest1_ext_obj, iioptest1_seq1*, iioptest1_seq1**, iioptest1_seq1*, ILU_C_ENVIRONMENT *);

extern iioptest1_rec1*
  iioptest1_ext_obj_test_var_record (iioptest1_ext_obj, iioptest1_rec1*, iioptest1_rec1**, iioptest1_rec1*, ILU_C_ENVIRONMENT *);

extern iioptest1_arr1_slice *
  iioptest1_ext_obj_test_var_array (iioptest1_ext_obj, iioptest1_arr1, iioptest1_arr1_slice **, iioptest1_arr1, ILU_C_ENVIRONMENT *);

extern iioptest1_arr4_slice *
  iioptest1_ext_obj_test_fixed_array (iioptest1_ext_obj, iioptest1_arr4, iioptest1_arr4, iioptest1_arr4, ILU_C_ENVIRONMENT *);

extern iioptest1_union1*
  iioptest1_ext_obj_test_var_union (iioptest1_ext_obj, iioptest1_union1*, iioptest1_union1**, iioptest1_union1*, ILU_C_ENVIRONMENT *);

extern iioptest1_union2
  iioptest1_ext_obj_test_fixed_union (iioptest1_ext_obj, iioptest1_union2*, iioptest1_union2*, iioptest1_union2*, ILU_C_ENVIRONMENT *);




/*-----------------------------------------------------------------------*/
/*-----  object type "iioptest1_obj"  -----------------------------------*/

#define iioptest1_obj__MSType _iioptest1_obj__ILUType

iioptest1_obj
  iioptest1_obj__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  iioptest1_obj__SetUserData (iioptest1_obj /* self */, void * /* userData */);
void *
  iioptest1_obj__GetUserData (iioptest1_obj /* self */);

extern iioptest1_obj
  iioptest1_obj__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default iioptest1_obj class */

extern iioptest1_obj
  iioptest1_obj__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern void server_iioptest1_obj_test_void (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_short server_iioptest1_obj_test_short (iioptest1_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long server_iioptest1_obj_test_long (iioptest1_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_short server_iioptest1_obj_test_ushort (iioptest1_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_long server_iioptest1_obj_test_ulong (iioptest1_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_float server_iioptest1_obj_test_float (iioptest1_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_double server_iioptest1_obj_test_double (iioptest1_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_iioptest1_obj_test_boolean (iioptest1_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_char server_iioptest1_obj_test_char (iioptest1_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_octet server_iioptest1_obj_test_octet (iioptest1_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_string server_iioptest1_obj_test_string (iioptest1_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long_long server_iioptest1_obj_test_longlong (iioptest1_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_unsigned_long_long server_iioptest1_obj_test_ulonglong (iioptest1_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_wchar server_iioptest1_obj_test_wchar (iioptest1_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status);

extern iioptest1_UnicodeString server_iioptest1_obj_test_wstring (iioptest1_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status);

extern CORBA_long_double server_iioptest1_obj_test_longdouble (iioptest1_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status);

extern void server_iioptest1_obj_test_throw (iioptest1_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status);

extern void server_iioptest1_obj_please_exit (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status);

extern void iioptest1_obj__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class iioptest1_obj__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class iioptest1_obj__MakeClass(
  void (*iioptest1_obj_test_void__Impl)
     (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*iioptest1_obj_test_short__Impl)
     (iioptest1_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long (*iioptest1_obj_test_long__Impl)
     (iioptest1_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_short (*iioptest1_obj_test_ushort__Impl)
     (iioptest1_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long (*iioptest1_obj_test_ulong__Impl)
     (iioptest1_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_float (*iioptest1_obj_test_float__Impl)
     (iioptest1_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_double (*iioptest1_obj_test_double__Impl)
     (iioptest1_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*iioptest1_obj_test_boolean__Impl)
     (iioptest1_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_char (*iioptest1_obj_test_char__Impl)
     (iioptest1_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_octet (*iioptest1_obj_test_octet__Impl)
     (iioptest1_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_string (*iioptest1_obj_test_string__Impl)
     (iioptest1_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_long (*iioptest1_obj_test_longlong__Impl)
     (iioptest1_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_unsigned_long_long (*iioptest1_obj_test_ulonglong__Impl)
     (iioptest1_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_wchar (*iioptest1_obj_test_wchar__Impl)
     (iioptest1_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status),
  iioptest1_UnicodeString (*iioptest1_obj_test_wstring__Impl)
     (iioptest1_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status),
  CORBA_long_double (*iioptest1_obj_test_longdouble__Impl)
     (iioptest1_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_test_throw__Impl)
     (iioptest1_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status),
  void (*iioptest1_obj_please_exit__Impl)
     (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern void
  iioptest1_obj_test_void (iioptest1_obj, ILU_C_ENVIRONMENT *);

extern CORBA_short
  iioptest1_obj_test_short (iioptest1_obj, CORBA_short, CORBA_short*, CORBA_short*, ILU_C_ENVIRONMENT *);

extern CORBA_long
  iioptest1_obj_test_long (iioptest1_obj, CORBA_long, CORBA_long*, CORBA_long*, ILU_C_ENVIRONMENT *);

extern CORBA_unsigned_short
  iioptest1_obj_test_ushort (iioptest1_obj, CORBA_unsigned_short, CORBA_unsigned_short*, CORBA_unsigned_short*, ILU_C_ENVIRONMENT *);

extern CORBA_unsigned_long
  iioptest1_obj_test_ulong (iioptest1_obj, CORBA_unsigned_long, CORBA_unsigned_long*, CORBA_unsigned_long*, ILU_C_ENVIRONMENT *);

extern CORBA_float
  iioptest1_obj_test_float (iioptest1_obj, CORBA_float, CORBA_float*, CORBA_float*, ILU_C_ENVIRONMENT *);

extern CORBA_double
  iioptest1_obj_test_double (iioptest1_obj, CORBA_double, CORBA_double*, CORBA_double*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  iioptest1_obj_test_boolean (iioptest1_obj, CORBA_boolean, CORBA_boolean*, CORBA_boolean*, ILU_C_ENVIRONMENT *);

extern CORBA_char
  iioptest1_obj_test_char (iioptest1_obj, CORBA_char, CORBA_char*, CORBA_char*, ILU_C_ENVIRONMENT *);

extern CORBA_octet
  iioptest1_obj_test_octet (iioptest1_obj, CORBA_octet, CORBA_octet*, CORBA_octet*, ILU_C_ENVIRONMENT *);

extern iioptest1_string
  iioptest1_obj_test_string (iioptest1_obj, iioptest1_string, iioptest1_string*, iioptest1_string*, ILU_C_ENVIRONMENT *);

extern CORBA_long_long
  iioptest1_obj_test_longlong (iioptest1_obj, CORBA_long_long, CORBA_long_long*, CORBA_long_long*, ILU_C_ENVIRONMENT *);

extern CORBA_unsigned_long_long
  iioptest1_obj_test_ulonglong (iioptest1_obj, CORBA_unsigned_long_long, CORBA_unsigned_long_long*, CORBA_unsigned_long_long*, ILU_C_ENVIRONMENT *);

extern CORBA_wchar
  iioptest1_obj_test_wchar (iioptest1_obj, CORBA_wchar, CORBA_wchar*, CORBA_wchar*, ILU_C_ENVIRONMENT *);

extern iioptest1_UnicodeString
  iioptest1_obj_test_wstring (iioptest1_obj, iioptest1_UnicodeString, iioptest1_UnicodeString*, iioptest1_UnicodeString*, ILU_C_ENVIRONMENT *);

extern CORBA_long_double
  iioptest1_obj_test_longdouble (iioptest1_obj, CORBA_long_double, CORBA_long_double*, CORBA_long_double*, ILU_C_ENVIRONMENT *);

extern void  /* exceptions:  x1 x2 */
  iioptest1_obj_test_throw (iioptest1_obj, CORBA_long, ILU_C_ENVIRONMENT *);

extern void
  iioptest1_obj_please_exit (iioptest1_obj, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void iioptest1__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _iioptest1_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _iioptest1_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _iioptest1_xilu_obj__IoFns;
#define TC_iioptest1_xilu_obj (& _iioptest1_xilu_obj__IoFns)
extern void iioptest1_xilu_obj__Free (iioptest1_xilu_obj*);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_ext_obj__IoFns;
#define TC_iioptest1_ext_obj (& _iioptest1_ext_obj__IoFns)
extern void iioptest1_ext_obj__Free (iioptest1_ext_obj*);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_opt1__IoFns;
#define TC_iioptest1_opt1 (& _iioptest1_opt1__IoFns)
extern void _iioptest1_opt1__Output (ilu_Call, iioptest1_opt1, ilu_Error *);
extern ilu_cardinal _iioptest1_opt1__SizeOf (ilu_Call, iioptest1_opt1, ilu_Error *);
extern iioptest1_opt1* _iioptest1_opt1__Input (ilu_Call, iioptest1_opt1*, ilu_Error *);
extern void iioptest1_opt1__Free (iioptest1_opt1*);
iioptest1_opt1* iioptest1_opt1__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_union2__IoFns;
#define TC_iioptest1_union2 (& _iioptest1_union2__IoFns)
extern void _iioptest1_union2__Output (ilu_Call, iioptest1_union2*, ilu_Error *);
extern ilu_cardinal _iioptest1_union2__SizeOf (ilu_Call, iioptest1_union2*, ilu_Error *);
extern iioptest1_union2* _iioptest1_union2__Input (ilu_Call, iioptest1_union2*, ilu_Error *);
iioptest1_union2* iioptest1_union2__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_union1__IoFns;
#define TC_iioptest1_union1 (& _iioptest1_union1__IoFns)
extern void _iioptest1_union1__Output (ilu_Call, iioptest1_union1*, ilu_Error *);
extern ilu_cardinal _iioptest1_union1__SizeOf (ilu_Call, iioptest1_union1*, ilu_Error *);
extern iioptest1_union1* _iioptest1_union1__Input (ilu_Call, iioptest1_union1*, ilu_Error *);
extern void iioptest1_union1__Free (iioptest1_union1*);
iioptest1_union1* iioptest1_union1__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_enum1__IoFns;
#define TC_iioptest1_enum1 (& _iioptest1_enum1__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_seq1__IoFns;
#define TC_iioptest1_seq1 (& _iioptest1_seq1__IoFns)
extern void _iioptest1_seq1__Output (ilu_Call, iioptest1_seq1*, ilu_Error *);
extern ilu_cardinal _iioptest1_seq1__SizeOf (ilu_Call, iioptest1_seq1*, ilu_Error *);
extern iioptest1_seq1* _iioptest1_seq1__Input (ilu_Call, iioptest1_seq1*, ilu_Error *);
extern void iioptest1_seq1__Free (iioptest1_seq1*);
iioptest1_seq1* iioptest1_seq1__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_arr4__IoFns;
#define TC_iioptest1_arr4 (& _iioptest1_arr4__IoFns)
extern void _iioptest1_arr4__Output (ilu_Call, iioptest1_arr4, ilu_Error *);
extern ilu_cardinal _iioptest1_arr4__SizeOf (ilu_Call, iioptest1_arr4, ilu_Error *);
extern iioptest1_arr4_slice * _iioptest1_arr4__Input (ilu_Call, iioptest1_arr4, ilu_Error *);
iioptest1_arr4_slice * iioptest1_arr4__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_arr3__IoFns;
#define TC_iioptest1_arr3 (& _iioptest1_arr3__IoFns)
extern void _iioptest1_arr3__Output (ilu_Call, iioptest1_arr3, ilu_Error *);
extern ilu_cardinal _iioptest1_arr3__SizeOf (ilu_Call, iioptest1_arr3, ilu_Error *);
extern iioptest1_arr3_slice * _iioptest1_arr3__Input (ilu_Call, iioptest1_arr3, ilu_Error *);
iioptest1_arr3_slice * iioptest1_arr3__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_arr2__IoFns;
#define TC_iioptest1_arr2 (& _iioptest1_arr2__IoFns)
extern void _iioptest1_arr2__Output (ilu_Call, iioptest1_arr2, ilu_Error *);
extern ilu_cardinal _iioptest1_arr2__SizeOf (ilu_Call, iioptest1_arr2, ilu_Error *);
extern iioptest1_arr2_slice * _iioptest1_arr2__Input (ilu_Call, iioptest1_arr2, ilu_Error *);
extern void iioptest1_arr2__Free (iioptest1_arr2*);
iioptest1_arr2_slice * iioptest1_arr2__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_arr1__IoFns;
#define TC_iioptest1_arr1 (& _iioptest1_arr1__IoFns)
extern void _iioptest1_arr1__Output (ilu_Call, iioptest1_arr1, ilu_Error *);
extern ilu_cardinal _iioptest1_arr1__SizeOf (ilu_Call, iioptest1_arr1, ilu_Error *);
extern iioptest1_arr1_slice * _iioptest1_arr1__Input (ilu_Call, iioptest1_arr1, ilu_Error *);
extern void iioptest1_arr1__Free (iioptest1_arr1*);
iioptest1_arr1_slice * iioptest1_arr1__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_rec2__IoFns;
#define TC_iioptest1_rec2 (& _iioptest1_rec2__IoFns)
extern void _iioptest1_rec2__Output (ilu_Call, iioptest1_rec2*, ilu_Error *);
extern ilu_cardinal _iioptest1_rec2__SizeOf (ilu_Call, iioptest1_rec2*, ilu_Error *);
extern iioptest1_rec2* _iioptest1_rec2__Input (ilu_Call, iioptest1_rec2*, ilu_Error *);
iioptest1_rec2* iioptest1_rec2__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_rec1__IoFns;
#define TC_iioptest1_rec1 (& _iioptest1_rec1__IoFns)
extern void _iioptest1_rec1__Output (ilu_Call, iioptest1_rec1*, ilu_Error *);
extern ilu_cardinal _iioptest1_rec1__SizeOf (ilu_Call, iioptest1_rec1*, ilu_Error *);
extern iioptest1_rec1* _iioptest1_rec1__Input (ilu_Call, iioptest1_rec1*, ilu_Error *);
extern void iioptest1_rec1__Free (iioptest1_rec1*);
iioptest1_rec1* iioptest1_rec1__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_x1_rec__IoFns;
#define TC_iioptest1_x1_rec (& _iioptest1_x1_rec__IoFns)
extern void _iioptest1_x1_rec__Output (ilu_Call, iioptest1_x1_rec*, ilu_Error *);
extern ilu_cardinal _iioptest1_x1_rec__SizeOf (ilu_Call, iioptest1_x1_rec*, ilu_Error *);
extern iioptest1_x1_rec* _iioptest1_x1_rec__Input (ilu_Call, iioptest1_x1_rec*, ilu_Error *);
iioptest1_x1_rec* iioptest1_x1_rec__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_x2_rec__IoFns;
#define TC_iioptest1_x2_rec (& _iioptest1_x2_rec__IoFns)
extern void _iioptest1_x2_rec__Output (ilu_Call, iioptest1_x2_rec*, ilu_Error *);
extern ilu_cardinal _iioptest1_x2_rec__SizeOf (ilu_Call, iioptest1_x2_rec*, ilu_Error *);
extern iioptest1_x2_rec* _iioptest1_x2_rec__Input (ilu_Call, iioptest1_x2_rec*, ilu_Error *);
extern void iioptest1_x2_rec__Free (iioptest1_x2_rec*);
iioptest1_x2_rec* iioptest1_x2_rec__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_obj__IoFns;
#define TC_iioptest1_obj (& _iioptest1_obj__IoFns)
extern void iioptest1_obj__Free (iioptest1_obj*);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_string__IoFns;
#define TC_iioptest1_string (& _iioptest1_string__IoFns)
extern void _iioptest1_string__Output (ilu_Call, iioptest1_string, ilu_Error *);
extern ilu_cardinal _iioptest1_string__SizeOf (ilu_Call, iioptest1_string, ilu_Error *);
extern iioptest1_string* _iioptest1_string__Input (ilu_Call, iioptest1_string*, ilu_Error *);
extern void iioptest1_string__Free (iioptest1_string*);
iioptest1_string* iioptest1_string__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iioptest1_UnicodeString__IoFns;
#define TC_iioptest1_UnicodeString (& _iioptest1_UnicodeString__IoFns)
extern void _iioptest1_UnicodeString__Output (ilu_Call, iioptest1_UnicodeString, ilu_Error *);
extern ilu_cardinal _iioptest1_UnicodeString__SizeOf (ilu_Call, iioptest1_UnicodeString, ilu_Error *);
extern iioptest1_UnicodeString* _iioptest1_UnicodeString__Input (ilu_Call, iioptest1_UnicodeString*, ilu_Error *);
extern void iioptest1_UnicodeString__Free (iioptest1_UnicodeString*);
iioptest1_UnicodeString* iioptest1_UnicodeString__alloc (void);

extern ilu_Class _iioptest1_xilu_obj__ILUType;
extern iioptest1_opt1 _iioptest1_xilu_obj_test_optional__clientstub (iioptest1_xilu_obj _handle, iioptest1_opt1 a1, iioptest1_opt1* a2, iioptest1_opt1* a3, ILU_C_ENVIRONMENT *_status);
extern void _iioptest1_xilu_obj_test_asynchronous__clientstub (iioptest1_xilu_obj _handle, CORBA_long a1, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _iioptest1_ext_obj__ILUType;
extern iioptest1_ext_obj _iioptest1_ext_obj_test_obj__clientstub (iioptest1_ext_obj _handle, iioptest1_ext_obj a1, iioptest1_ext_obj* a2, iioptest1_ext_obj* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_rec2 _iioptest1_ext_obj_test_fixed_record__clientstub (iioptest1_ext_obj _handle, iioptest1_rec2* a1, iioptest1_rec2* a2, iioptest1_rec2* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_enum1 _iioptest1_ext_obj_test_enumeration__clientstub (iioptest1_ext_obj _handle, iioptest1_enum1 a1, iioptest1_enum1* a2, iioptest1_enum1* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_seq1* _iioptest1_ext_obj_test_sequence__clientstub (iioptest1_ext_obj _handle, iioptest1_seq1* a1, iioptest1_seq1** a2, iioptest1_seq1* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_rec1* _iioptest1_ext_obj_test_var_record__clientstub (iioptest1_ext_obj _handle, iioptest1_rec1* a1, iioptest1_rec1** a2, iioptest1_rec1* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_arr1_slice * _iioptest1_ext_obj_test_var_array__clientstub (iioptest1_ext_obj _handle, iioptest1_arr1 a1, iioptest1_arr1_slice ** a2, iioptest1_arr1 a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_arr4_slice * _iioptest1_ext_obj_test_fixed_array__clientstub (iioptest1_ext_obj _handle, iioptest1_arr4 a1, iioptest1_arr4 a2, iioptest1_arr4 a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_union1* _iioptest1_ext_obj_test_var_union__clientstub (iioptest1_ext_obj _handle, iioptest1_union1* a1, iioptest1_union1** a2, iioptest1_union1* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_union2 _iioptest1_ext_obj_test_fixed_union__clientstub (iioptest1_ext_obj _handle, iioptest1_union2* a1, iioptest1_union2* a2, iioptest1_union2* a3, ILU_C_ENVIRONMENT *_status);

extern ilu_Class _iioptest1_obj__ILUType;
extern void _iioptest1_obj_test_void__clientstub (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_short _iioptest1_obj_test_short__clientstub (iioptest1_obj _handle, CORBA_short a1, CORBA_short* a2, CORBA_short* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_long _iioptest1_obj_test_long__clientstub (iioptest1_obj _handle, CORBA_long a1, CORBA_long* a2, CORBA_long* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_unsigned_short _iioptest1_obj_test_ushort__clientstub (iioptest1_obj _handle, CORBA_unsigned_short a1, CORBA_unsigned_short* a2, CORBA_unsigned_short* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_unsigned_long _iioptest1_obj_test_ulong__clientstub (iioptest1_obj _handle, CORBA_unsigned_long a1, CORBA_unsigned_long* a2, CORBA_unsigned_long* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_float _iioptest1_obj_test_float__clientstub (iioptest1_obj _handle, CORBA_float a1, CORBA_float* a2, CORBA_float* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_double _iioptest1_obj_test_double__clientstub (iioptest1_obj _handle, CORBA_double a1, CORBA_double* a2, CORBA_double* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _iioptest1_obj_test_boolean__clientstub (iioptest1_obj _handle, CORBA_boolean a1, CORBA_boolean* a2, CORBA_boolean* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_char _iioptest1_obj_test_char__clientstub (iioptest1_obj _handle, CORBA_char a1, CORBA_char* a2, CORBA_char* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_octet _iioptest1_obj_test_octet__clientstub (iioptest1_obj _handle, CORBA_octet a1, CORBA_octet* a2, CORBA_octet* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_string _iioptest1_obj_test_string__clientstub (iioptest1_obj _handle, iioptest1_string a1, iioptest1_string* a2, iioptest1_string* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_long_long _iioptest1_obj_test_longlong__clientstub (iioptest1_obj _handle, CORBA_long_long a1, CORBA_long_long* a2, CORBA_long_long* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_unsigned_long_long _iioptest1_obj_test_ulonglong__clientstub (iioptest1_obj _handle, CORBA_unsigned_long_long a1, CORBA_unsigned_long_long* a2, CORBA_unsigned_long_long* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_wchar _iioptest1_obj_test_wchar__clientstub (iioptest1_obj _handle, CORBA_wchar a1, CORBA_wchar* a2, CORBA_wchar* a3, ILU_C_ENVIRONMENT *_status);
extern iioptest1_UnicodeString _iioptest1_obj_test_wstring__clientstub (iioptest1_obj _handle, iioptest1_UnicodeString a1, iioptest1_UnicodeString* a2, iioptest1_UnicodeString* a3, ILU_C_ENVIRONMENT *_status);
extern CORBA_long_double _iioptest1_obj_test_longdouble__clientstub (iioptest1_obj _handle, CORBA_long_double a1, CORBA_long_double* a2, CORBA_long_double* a3, ILU_C_ENVIRONMENT *_status);
extern void _iioptest1_obj_test_throw__clientstub (iioptest1_obj _handle, CORBA_long case_num, ILU_C_ENVIRONMENT *_status);
extern void _iioptest1_obj_please_exit__clientstub (iioptest1_obj _handle, ILU_C_ENVIRONMENT *_status);

extern void _iioptest1__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __iioptest1_h_ */
