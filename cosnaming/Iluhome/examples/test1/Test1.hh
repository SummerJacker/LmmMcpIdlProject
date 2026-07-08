/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:04 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c++-stubber.exe" of Mon Aug 18 11:47:27 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Test1_H_
#define __Test1_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */


typedef struct _Test1_Status_struct Test1Status;

typedef ilu_Integer Test1_T_I;
#define Test1_T_I ilu_Integer
class Test1_T_O3;
class Test1_T_O4;
class Test1_T_P;
typedef ilu_ShortCharacter Test1_T_SC;
#define Test1_T_SC ilu_ShortCharacter
typedef char * Test1_T_ScS;
typedef Test1_T_ScS Test1_T_TheA1[3];
typedef Test1_T_TheA1 Test1_T_A1;
#define Test1_T_A1 Test1_T_TheA1
typedef class _Test1_T_CSS_sequence * Test1_T_CSS;
typedef struct _Test1_T_TheR_record Test1_T_TheR;
typedef Test1_T_TheR Test1_T_R;
#define Test1_T_R Test1_T_TheR
typedef Test1_T_R *  Test1_T_RO;
class Test1_T_TheO1;
typedef class Test1_T_TheO1 Test1_T_One;
#define Test1_T_One Test1_T_TheO1
typedef struct _Test1_T_U_scard_union Test1_T_U_scard;
typedef class Test1_T_TheO1 Test1_T_O1;
#define Test1_T_O1 Test1_T_TheO1
typedef Test1_T_O1 *  Test1_T_TheOO;
typedef Test1_T_TheOO Test1_T_OO;
#define Test1_T_OO Test1_T_TheOO
typedef ilu_Byte Test1_T_A0[8];
class Test1_T_O2;
typedef struct _Test1_T_U_card_union Test1_T_U_card;
typedef struct _Test1_T_U_int_union Test1_T_U_int;
typedef struct _Test1_T_U_byte_union Test1_T_U_byte;
typedef struct _Test1_T_U4_union Test1_T_U4;
typedef enum _Test1_T_TheE_enum {Test1_T_TheE_ev1 = 0, Test1_T_TheE_ev3 = 3, Test1_T_TheE_ev5 = 4, Test1_T_TheE_ev7 = 5} Test1_T_TheE;
typedef Test1_T_TheE Test1_T_E;
#define Test1_T_E Test1_T_TheE
typedef struct _Test1_T_U2_union Test1_T_U2;
typedef struct _Test1_T_U3_union Test1_T_U3;
typedef struct _Test1_T_U1_union Test1_T_U1;
typedef struct _Test1_T_TheU_union Test1_T_TheU;
typedef Test1_T_TheU Test1_T_U;
#define Test1_T_U Test1_T_TheU
typedef struct _Test1_T_OO2_union Test1_T_OO2;
typedef class _Test1_T_TheRS_sequence * Test1_T_TheRS;
typedef Test1_T_TheRS Test1_T_RS;
#define Test1_T_RS Test1_T_TheRS
typedef class _Test1_T_BS_sequence * Test1_T_BS;
typedef ilu_Cardinal Test1_T_A2[3][4];
typedef ilu_Character Test1_T_C;
#define Test1_T_C ilu_Character
typedef class _Test1_T_IS_sequence * Test1_T_IS;



/* declaration of C++ class "Test1_T_O3"
   from ILU class "Test1:O3"  */


class Test1_T_O3 : public virtual iluObject {

 public:

  Test1_T_O3();			// constructor
  virtual ~Test1_T_O3();		// destructor

 // class procedures

  static class Test1_T_O3 * ILUCreateFromSBH(ilu_CString sbh);
  static class Test1_T_O3 * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Test1_T_IS RS_R_to_R_IS (Test1Status *_status, Test1_T_RS r, Test1_T_R * r2);
  virtual void O1_U_to_U (Test1Status *_status, Test1_T_O1 * o, Test1_T_U * u);
  virtual Test1_T_I BS_to_I (Test1Status *_status, Test1_T_BS b);

 // data slots for cacheable methods -- if any

};



/* declaration of C++ class "Test1_T_O4"
   from ILU class "Test1:O4"  */


class Test1_T_O4 : public virtual Test1_T_O3 {

 public:

  Test1_T_O4();			// constructor
  virtual ~Test1_T_O4();		// destructor

 // class procedures

  static class Test1_T_O4 * ILUCreateFromSBH(ilu_CString sbh);
  static class Test1_T_O4 * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual ilu_Real R_to_R (Test1Status *_status, ilu_Real r);

 // data slots for cacheable methods -- if any

};



/* declaration of C++ class "Test1_T_P"
   from ILU class "Test1:P"  */


class Test1_T_P : public virtual Test1_T_O3 {

 public:

  Test1_T_P();			// constructor
  virtual ~Test1_T_P();		// destructor

 // class procedures

  static class Test1_T_P * ILUCreateFromSBH(ilu_CString sbh);
  static class Test1_T_P * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Test1_T_IS m2 (Test1Status *_status, ilu_Integer j);

 // data slots for cacheable methods -- if any

};

  class _Test1_T_CSS_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Test1_T_ScS *_buffer;
   public:
    _Test1_T_CSS_sequence ();
    virtual ~_Test1_T_CSS_sequence ();
    static class _Test1_T_CSS_sequence *Create (ilu_Cardinal initial_size, Test1_T_ScS *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Test1_T_ScS);
    virtual Test1_T_ScS RemoveHead();
    virtual Test1_T_ScS RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Test1_T_ScS, void *), void *arg);
    virtual Test1_T_ScS Find(ilu_Boolean (*matchproc)(Test1_T_ScS, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Test1_T_ScS, void *), void *arg);
    virtual Test1_T_ScS * Array();
    virtual Test1_T_ScS Nth(ilu_Cardinal index);
  };

struct _Test1_T_TheR_record {
	Test1_T_A1 a;
	Test1_T_CSS css;
	Test1_T_I i;
};


/* declaration of C++ class "Test1_T_TheO1"
   from ILU class "Test1:TheO1"  */


class Test1_T_TheO1 : public virtual iluObject {

 public:

  Test1_T_TheO1();			// constructor
  virtual ~Test1_T_TheO1();		// destructor

 // class procedures

  static class Test1_T_TheO1 * ILUCreateFromSBH(ilu_CString sbh);
  static class Test1_T_TheO1 * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Test1_T_U * U_CSS_to_U (Test1Status *_status, Test1_T_U * u, Test1_T_CSS css);
  virtual Test1_T_RO f_CSS_to_RO (Test1Status *_status, Test1_T_CSS css);
  virtual ilu_ShortReal R_ScS_to_F (Test1Status *_status, Test1_T_R * r, Test1_T_ScS s);
  virtual void a_RO (Test1Status *_status, Test1_T_RO ro);
  virtual class Test1_T_O2 * get_O2 (Test1Status *_status);
  virtual class Test1_T_O3 * get_O3 (Test1Status *_status, ilu_Boolean subclass);

 // data slots for cacheable methods -- if any

};

struct _Test1_T_U_scard_union {
	ilu_ShortCardinal discriminator;
	union {
		Test1_T_R R;
		class Test1_T_TheO1 *One;
	} value;
};


/* declaration of C++ class "Test1_T_O2"
   from ILU class "Test1:O2"  */


class Test1_T_O2 : public virtual iluObject {

 public:

  Test1_T_O2();			// constructor
  virtual ~Test1_T_O2();		// destructor

 // class procedures

  static class Test1_T_O2 * ILUCreateFromSBH(ilu_CString sbh);
  static class Test1_T_O2 * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Test1_T_CSS OO_A0_to_CSS (Test1Status *_status, Test1_T_OO o, Test1_T_A0 a);
  virtual Test1_T_A0 * R_I_A1_to_I_A0 (Test1Status *_status, Test1_T_R * r, Test1_T_I * i, Test1_T_A1 a);

 // data slots for cacheable methods -- if any

};

struct _Test1_T_U_card_union {
	ilu_Cardinal discriminator;
	union {
		Test1_T_R R;
		class Test1_T_O2 *O2;
	} value;
};
struct _Test1_T_U_int_union {
	ilu_Integer discriminator;
	union {
		Test1_T_R R;
		class Test1_T_O2 *O2;
	} value;
};
struct _Test1_T_U_byte_union {
	ilu_Byte discriminator;
	union {
		Test1_T_R R;
		class Test1_T_O2 *O2;
	} value;
};
struct _Test1_T_U4_union {
	ilu_ShortInteger discriminator;
	union {
		ilu_Boolean x1;
		class Test1_T_O2 *x2;
		Test1_T_CSS x3;
	} value;
};
struct _Test1_T_U2_union {
	ilu_ShortInteger discriminator;
	union {
		ilu_Boolean x1;
		class Test1_T_O2 *x2;
		Test1_T_CSS x3;
	} value;
};
struct _Test1_T_U3_union {
	Test1_T_E discriminator;
	union {
		ilu_T_CString CString;
		Test1_T_U2 U2;
		class Test1_T_O2 *v3;
		Test1_T_RO v4;
	} value;
};
struct _Test1_T_U1_union {
	ilu_ShortInteger discriminator;
	union {
		Test1_T_R R;
		Test1_T_A1 A1;
	} value;
};
struct _Test1_T_TheU_union {
	ilu_ShortInteger discriminator;
	union {
		Test1_T_R R;
		Test1_T_RO RO;
		Test1_T_CSS CSS;
		class Test1_T_TheO1 *O1;
		Test1_T_OO OO;
		ilu_Boolean boolean;
	} value;
};
struct _Test1_T_OO2_union {
	ilu_Boolean discriminator;
	union {
		class Test1_T_O2 *O2;
	} value;
};
  class _Test1_T_TheRS_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Test1_T_R *_buffer;
   public:
    _Test1_T_TheRS_sequence ();
    virtual ~_Test1_T_TheRS_sequence ();
    static class _Test1_T_TheRS_sequence *Create (ilu_Cardinal initial_size, Test1_T_R *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Test1_T_R *);
    virtual Test1_T_R * RemoveHead();
    virtual Test1_T_R * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Test1_T_R *, void *), void *arg);
    virtual Test1_T_R * Find(ilu_Boolean (*matchproc)(Test1_T_R *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Test1_T_R *, void *), void *arg);
    virtual Test1_T_R * Array();
    virtual Test1_T_R * Nth(ilu_Cardinal index);
  };

  class _Test1_T_BS_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    ilu_Byte *_buffer;
   public:
    _Test1_T_BS_sequence ();
    virtual ~_Test1_T_BS_sequence ();
    static class _Test1_T_BS_sequence *Create (ilu_Cardinal initial_size, ilu_Byte *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(ilu_Byte);
    virtual ilu_Byte RemoveHead();
    virtual ilu_Byte RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg);
    virtual ilu_Byte Find(ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(ilu_Byte, void *), void *arg);
    virtual ilu_Byte * Array();
    virtual ilu_Byte Nth(ilu_Cardinal index);
  };

  class _Test1_T_IS_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    ilu_Integer *_buffer;
   public:
    _Test1_T_IS_sequence ();
    virtual ~_Test1_T_IS_sequence ();
    static class _Test1_T_IS_sequence *Create (ilu_Cardinal initial_size, ilu_Integer *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(ilu_Integer);
    virtual ilu_Integer RemoveHead();
    virtual ilu_Integer RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(ilu_Integer, void *), void *arg);
    virtual ilu_Integer Find(ilu_Boolean (*matchproc)(ilu_Integer, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(ilu_Integer, void *), void *arg);
    virtual ilu_Integer * Array();
    virtual ilu_Integer Nth(ilu_Cardinal index);
  };


class Test1_G {

 public:

  static struct Test1_Exceptions_s *Exceptions();
  static void RaiseException (Test1Status *status, ilu_Exception exception...);

  static ilu_Boolean Output_U_scard (iluCall call, Test1_T_U_scard * val);
  static Test1_T_U_scard * Input_U_scard (iluCall call, Test1_T_U_scard * ref);
  static ilu_Cardinal SizeOf_U_scard (iluCall call, Test1_T_U_scard * val);

  static void Free_U_scard (Test1_T_U_scard * val);
  static ilu_Boolean Output_U_card (iluCall call, Test1_T_U_card * val);
  static Test1_T_U_card * Input_U_card (iluCall call, Test1_T_U_card * ref);
  static ilu_Cardinal SizeOf_U_card (iluCall call, Test1_T_U_card * val);

  static void Free_U_card (Test1_T_U_card * val);
  static ilu_Boolean Output_U_int (iluCall call, Test1_T_U_int * val);
  static Test1_T_U_int * Input_U_int (iluCall call, Test1_T_U_int * ref);
  static ilu_Cardinal SizeOf_U_int (iluCall call, Test1_T_U_int * val);

  static void Free_U_int (Test1_T_U_int * val);
  static ilu_Boolean Output_U_byte (iluCall call, Test1_T_U_byte * val);
  static Test1_T_U_byte * Input_U_byte (iluCall call, Test1_T_U_byte * ref);
  static ilu_Cardinal SizeOf_U_byte (iluCall call, Test1_T_U_byte * val);

  static void Free_U_byte (Test1_T_U_byte * val);
  static ilu_Boolean Output_U4 (iluCall call, Test1_T_U4 * val);
  static Test1_T_U4 * Input_U4 (iluCall call, Test1_T_U4 * ref);
  static ilu_Cardinal SizeOf_U4 (iluCall call, Test1_T_U4 * val);

  static void Free_U4 (Test1_T_U4 * val);
  static ilu_Boolean Output_U3 (iluCall call, Test1_T_U3 * val);
  static Test1_T_U3 * Input_U3 (iluCall call, Test1_T_U3 * ref);
  static ilu_Cardinal SizeOf_U3 (iluCall call, Test1_T_U3 * val);

  static void Free_U3 (Test1_T_U3 * val);
  static ilu_Boolean Output_U2 (iluCall call, Test1_T_U2 * val);
  static Test1_T_U2 * Input_U2 (iluCall call, Test1_T_U2 * ref);
  static ilu_Cardinal SizeOf_U2 (iluCall call, Test1_T_U2 * val);

  static void Free_U2 (Test1_T_U2 * val);
  static ilu_Boolean Output_U1 (iluCall call, Test1_T_U1 * val);
  static Test1_T_U1 * Input_U1 (iluCall call, Test1_T_U1 * ref);
  static ilu_Cardinal SizeOf_U1 (iluCall call, Test1_T_U1 * val);

  static void Free_U1 (Test1_T_U1 * val);
  static ilu_Boolean Output_U (iluCall call, Test1_T_U * val);
  static Test1_T_U * Input_U (iluCall call, Test1_T_U * ref);
  static ilu_Cardinal SizeOf_U (iluCall call, Test1_T_U * val);

  static void Free_U (Test1_T_U * val);
  static ilu_Boolean Output_TheU (iluCall call, Test1_T_TheU * val);
  static Test1_T_TheU * Input_TheU (iluCall call, Test1_T_TheU * ref);
  static ilu_Cardinal SizeOf_TheU (iluCall call, Test1_T_TheU * val);

  static void Free_TheU (Test1_T_TheU * val);
  static ilu_Boolean Output_OO2 (iluCall call, Test1_T_OO2 * val);
  static Test1_T_OO2 * Input_OO2 (iluCall call, Test1_T_OO2 * ref);
  static ilu_Cardinal SizeOf_OO2 (iluCall call, Test1_T_OO2 * val);

  static void Free_OO (Test1_T_OO val);
  static void Free_TheOO (Test1_T_TheOO val);
  static void Free_RO (Test1_T_RO val);
  static ilu_Boolean Output_RS (iluCall call, Test1_T_RS val);
  static Test1_T_RS Input_RS (iluCall call, Test1_T_RS ref);
  static ilu_Cardinal SizeOf_RS (iluCall call, Test1_T_RS val);

  static void Free_RS (Test1_T_RS val);
  static ilu_Boolean Output_TheRS (iluCall call, Test1_T_TheRS val);
  static Test1_T_TheRS Input_TheRS (iluCall call, Test1_T_TheRS ref);
  static ilu_Cardinal SizeOf_TheRS (iluCall call, Test1_T_TheRS val);

  static void Free_TheRS (Test1_T_TheRS val);
  static ilu_Boolean Output_R (iluCall call, Test1_T_R * val);
  static Test1_T_R * Input_R (iluCall call, Test1_T_R * ref);
  static ilu_Cardinal SizeOf_R (iluCall call, Test1_T_R * val);

  static void Free_R (Test1_T_R * val);
  static ilu_Boolean Output_TheR (iluCall call, Test1_T_TheR * val);
  static Test1_T_TheR * Input_TheR (iluCall call, Test1_T_TheR * ref);
  static ilu_Cardinal SizeOf_TheR (iluCall call, Test1_T_TheR * val);

  static void Free_TheR (Test1_T_TheR * val);
  static ilu_Boolean Output_BS (iluCall call, Test1_T_BS val);
  static Test1_T_BS Input_BS (iluCall call, Test1_T_BS ref);
  static ilu_Cardinal SizeOf_BS (iluCall call, Test1_T_BS val);

  static void Free_BS (Test1_T_BS val);
  static ilu_Boolean Output_A2 (iluCall call, Test1_T_A2 val);
  static Test1_T_A2 * Input_A2 (iluCall call, Test1_T_A2 ref);
  static ilu_Cardinal SizeOf_A2 (iluCall call, Test1_T_A2 val);

  static ilu_Boolean Output_A1 (iluCall call, Test1_T_A1 val);
  static Test1_T_A1 * Input_A1 (iluCall call, Test1_T_A1 ref);
  static ilu_Cardinal SizeOf_A1 (iluCall call, Test1_T_A1 val);

  static ilu_Boolean Output_TheA1 (iluCall call, Test1_T_TheA1 val);
  static Test1_T_TheA1 * Input_TheA1 (iluCall call, Test1_T_TheA1 ref);
  static ilu_Cardinal SizeOf_TheA1 (iluCall call, Test1_T_TheA1 val);

  static ilu_Boolean Output_CSS (iluCall call, Test1_T_CSS val);
  static Test1_T_CSS Input_CSS (iluCall call, Test1_T_CSS ref);
  static ilu_Cardinal SizeOf_CSS (iluCall call, Test1_T_CSS val);

  static void Free_CSS (Test1_T_CSS val);
  static ilu_Boolean Output_IS (iluCall call, Test1_T_IS val);
  static Test1_T_IS Input_IS (iluCall call, Test1_T_IS ref);
  static ilu_Cardinal SizeOf_IS (iluCall call, Test1_T_IS val);

  static void Free_IS (Test1_T_IS val);
/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, Test1Status *status);
};

#define Test1Reply_Success		((ilu_Exception) NULL)

struct _Test1_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
		Test1_T_U * Test1_E_E1_Value;
		ilu_Integer Test1_E_E2_Value;
		Test1_T_RO Test1_E_E3_Value;
		Test1_T_O1 * Test1_E_E4_Value;
		Test1_T_A0 * Test1_E_E5_Value;
		Test1_T_RS Test1_E_E6_Value;
		ilu_T_CString Test1_E_E7_Value;
		Test1_T_A1 * Test1_E_E8_Value;
		Test1_T_R * Test1_E_E9_Value;
	} values;
};

struct Test1_Exceptions_s {
	ilu_Exception E1;
	ilu_Exception E2;
	ilu_Exception CantCreate;
	ilu_Exception E3;
	ilu_Exception E4;
	ilu_Exception E5;
	ilu_Exception E6;
	ilu_Exception E7;
	ilu_Exception E8;
	ilu_Exception E9;
};

#define Test1_E_E1		(Test1_G::Exceptions()->E1)
#define Test1_E_E2		(Test1_G::Exceptions()->E2)
#define Test1_E_CantCreate		(Test1_G::Exceptions()->CantCreate)
#define Test1_E_E3		(Test1_G::Exceptions()->E3)
#define Test1_E_E4		(Test1_G::Exceptions()->E4)
#define Test1_E_E5		(Test1_G::Exceptions()->E5)
#define Test1_E_E6		(Test1_G::Exceptions()->E6)
#define Test1_E_E7		(Test1_G::Exceptions()->E7)
#define Test1_E_E8		(Test1_G::Exceptions()->E8)
#define Test1_E_E9		(Test1_G::Exceptions()->E9)

extern void Test1__Initialize(void);	//ILU private

#endif /* ndef __Test1_H_ */
