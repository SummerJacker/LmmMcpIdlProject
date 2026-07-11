/* This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
 * at Mon Jan  8 12:44:14 2024 by `软智科技有限责任公司'
 * running "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/build/ilu/bin/c++-stubber.EXE" of Tue Nov 21 17:45:03 2023
 * on "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/ilu.isl" of Mon Jan  8 12:28:51 2024 *
 * KIS-CORBA is Copyright 2006-2056 Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
 * KIS-CORBA information:  http://www.kestrelsystems.ca .
 */

#ifndef __Test2_H_
#define __Test2_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */

#ifndef __Test1_H_
#include "Test1.hh"
#endif /* ndef __Test1_H_ */


typedef struct _Test2_Status_struct Test2Status;

typedef class Test1_T_O3 Test2_T_T1O3;
#define Test2_T_T1O3 Test1_T_O3
typedef Test1_T_U3 Test2_T_T1U3;
#define Test2_T_T1U3 Test1_T_U3
typedef Test1_T_U2 Test2_T_T1U2;
#define Test2_T_T1U2 Test1_T_U2
typedef Test1_T_TheU Test2_T_T1U;
#define Test2_T_T1U Test1_T_TheU
typedef Test1_T_TheE Test2_T_F;
#define Test2_T_F Test1_T_TheE
class Test2_T_P;
typedef struct _Test2_T_U2_union Test2_T_U2;



/* declaration of C++ class "Test2_T_P"
   from ILU class "Test2:P"  */


class Test2_T_P : public virtual iluObject {

 public:

  Test2_T_P();			// constructor
  virtual ~Test2_T_P();		// destructor

 // class procedures

  static class Test2_T_P * ILUCreateFromSBH(ilu_CString sbh);
  static class Test2_T_P * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual ilu_Integer SR_to_I (Test2Status *_status, ilu_ShortReal i);

 // data slots for cacheable methods -- if any

};

struct _Test2_T_U2_union {
	Test2_T_F discriminator;
	union {
		ilu_T_CString CString;
		class Test1_T_TheO1 *O1;
		class Test2_T_P *P;
	} value;
};

class Test2_G {

 public:

  static struct Test2_Exceptions_s *Exceptions();
  static void RaiseException (Test2Status *status, ilu_Exception exception...);

  static ilu_Boolean Output_T1U3 (iluCall call, Test2_T_T1U3 * val);
  static Test2_T_T1U3 * Input_T1U3 (iluCall call, Test2_T_T1U3 * ref);
  static ilu_Cardinal SizeOf_T1U3 (iluCall call, Test2_T_T1U3 * val);

  static void Free_T1U3 (Test2_T_T1U3 * val);
  static void Free_U3 (Test1_T_U3 * val);
  static ilu_Boolean Output_T1U2 (iluCall call, Test2_T_T1U2 * val);
  static Test2_T_T1U2 * Input_T1U2 (iluCall call, Test2_T_T1U2 * ref);
  static ilu_Cardinal SizeOf_T1U2 (iluCall call, Test2_T_T1U2 * val);

  static void Free_T1U2 (Test2_T_T1U2 * val);
  static void Free_U2 (Test1_T_U2 * val);
  static ilu_Boolean Output_T1U (iluCall call, Test2_T_T1U * val);
  static Test2_T_T1U * Input_T1U (iluCall call, Test2_T_T1U * ref);
  static ilu_Cardinal SizeOf_T1U (iluCall call, Test2_T_T1U * val);

  static void Free_T1U (Test2_T_T1U * val);
  static void Free_U (Test1_T_U * val);
  static ilu_Boolean Output_U2 (iluCall call, Test2_T_U2 * val);
  static Test2_T_U2 * Input_U2 (iluCall call, Test2_T_U2 * ref);
  static ilu_Cardinal SizeOf_U2 (iluCall call, Test2_T_U2 * val);

/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, Test2Status *status);
};

#define Test2Reply_Success		((ilu_Exception) NULL)

struct _Test2_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
		Test2_T_T1U * Test2_E_E1_Value;
	} values;
};

struct Test2_Exceptions_s {
	ilu_Exception E1;
};

#define Test2_E_E1		(Test2_G::Exceptions()->E1)

extern void Test2__Initialize(void);	//ILU private

#endif /* ndef __Test2_H_ */
