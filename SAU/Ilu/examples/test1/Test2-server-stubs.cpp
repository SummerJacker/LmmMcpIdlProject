/* This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
 * at Mon Jan  8 12:44:14 2024 by `软智科技有限责任公司'
 * running "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/build/ilu/bin/c++-stubber.EXE" of Tue Nov 21 17:45:03 2023
 * on "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
 * and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/ilu.isl" of Mon Jan  8 12:28:51 2024 *
 * KIS-CORBA is Copyright 2006-2056 Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
 * KIS-CORBA information:  http://www.kestrelsystems.ca .
 */

#include <ilu.hh>
#include "Test2.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class Test2Classes;

void _Test2_T_P_SR_to_I_stub (iluCall _call)
{
    Test2Status _status;
    ilu_ShortReal i;
  ilu_Integer _retvalue;
    Test2_T_P *_realobj;

    _realobj = (Test2_T_P *) iluObject::InputObject(_call, ilu_TRUE, Test2_T_P::ILUClassRecord);
	ilu::InputShortReal (_call, &i);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->SR_to_I (&_status, i);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfInteger(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test2_G::SendException (_call, &_status);
    }
faild:
    return;
}

#define MethodRecord_Test2_T_P_SR_to_I ((Test2_T_P::ILUClassRecord)->cl_methods + 0)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Test2_InitializeServerClass {

 public:

  _Test2_InitializeServerClass();
};

#ifndef macintosh
static class _Test2_InitializeServerClass _Test2_InitializationInstance;
#endif

void Test2__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Test2__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Test2_T_P_SR_to_I, (ilu_StubProc) _Test2_T_P_SR_to_I_stub, ilu::CppLangIdx());
}

_Test2_InitializeServerClass::_Test2_InitializeServerClass()
{
	Test2__InitializeServer();
}

