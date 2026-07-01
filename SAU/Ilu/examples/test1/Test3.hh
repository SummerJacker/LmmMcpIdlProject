/* This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
 * at Mon Jan  8 12:44:14 2024 by `软智科技有限责任公司'
 * running "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/build/ilu/bin/c++-stubber.EXE" of Tue Nov 21 17:45:03 2023
 * on "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test3.isl" of Thu Dec 28 15:50:31 2023,
 * and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/ilu.isl" of Mon Jan  8 12:28:51 2024 *
 * KIS-CORBA is Copyright 2006-2056 Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
 * KIS-CORBA information:  http://www.kestrelsystems.ca .
 */

#ifndef __Test3_H_
#define __Test3_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */

#ifndef __Test1_H_
#include "Test1.hh"
#endif /* ndef __Test1_H_ */

#ifndef __Test2_H_
#include "Test2.hh"
#endif /* ndef __Test2_H_ */


typedef struct _Test3_Status_struct Test3Status;

class Test3_T_O;
typedef struct _Test3_T_FU_union Test3_T_FU;
typedef class Test1_T_O3 Test3_T_T2T1O3;
#define Test3_T_T2T1O3 Test1_T_O3
typedef Test1_T_U3 Test3_T_T2T1U3;
#define Test3_T_T2T1U3 Test1_T_U3



/* declaration of C++ class "Test3_T_O"
   from ILU class "Test3:O"  */


class Test3_T_O : public virtual Test1_T_O3, public virtual Test2_T_P {

 public:

  Test3_T_O();			// constructor
  virtual ~Test3_T_O();		// destructor

 // class procedures

  static class Test3_T_O * ILUCreateFromSBH(ilu_CString sbh);
  static class Test3_T_O * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Test2_T_T1U * I_to_Test1U (Test3Status *_status, ilu_Integer i);

 // data slots for cacheable methods -- if any

};

struct _Test3_T_FU_union {
	Test2_T_F discriminator;
	union {
		class Test3_T_O *O;
		ilu_Integer integer;
	} value;
};

class Test3_G {

 public:

  static struct Test3_Exceptions_s *Exceptions();
  static void RaiseException (Test3Status *status, ilu_Exception exception...);

  static ilu_Boolean Output_FU (iluCall call, Test3_T_FU * val);
  static Test3_T_FU * Input_FU (iluCall call, Test3_T_FU * ref);
  static ilu_Cardinal SizeOf_FU (iluCall call, Test3_T_FU * val);

  static ilu_Boolean Output_T2T1U3 (iluCall call, Test3_T_T2T1U3 * val);
  static Test3_T_T2T1U3 * Input_T2T1U3 (iluCall call, Test3_T_T2T1U3 * ref);
  static ilu_Cardinal SizeOf_T2T1U3 (iluCall call, Test3_T_T2T1U3 * val);

  static void Free_T2T1U3 (Test3_T_T2T1U3 * val);
  static void Free_T1U3 (Test2_T_T1U3 * val);
  static void Free_T1U (Test2_T_T1U * val);
/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, Test3Status *status);
};

#define Test3Reply_Success		((ilu_Exception) NULL)

struct _Test3_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
		ilu_T_CString Test3_E_E1_Value;
	} values;
};

struct Test3_Exceptions_s {
	ilu_Exception E1;
};

#define Test3_E_E1		(Test3_G::Exceptions()->E1)

extern void Test3__Initialize(void);	//ILU private

#endif /* ndef __Test3_H_ */
