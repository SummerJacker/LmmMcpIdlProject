/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:04 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c++-stubber.exe" of Mon Aug 18 11:47:27 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Test3.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class Test3Classes;

void _Test3_T_O_I_to_Test1U_stub (iluCall _call)
{
    Test3Status _status;
    ilu_Integer i;
  Test2_T_T1U * _retvalue;
    Test3_T_O *_realobj;

    _realobj = (Test3_T_O *) iluObject::InputObject(_call, ilu_TRUE, Test3_T_O::ILUClassRecord);
	ilu::InputInteger (_call, &i);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->I_to_Test1U (&_status, i);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = Test1_G::SizeOf_TheU (_call, (Test1_T_TheU *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!Test1_G::Output_TheU (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test3_G::SendException (_call, &_status);
    }
	Test3_G::Free_T1U (_retvalue);
faild:
    return;
}

#define MethodRecord_Test3_T_O_I_to_Test1U ((Test3_T_O::ILUClassRecord)->cl_methods + 0)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Test3_InitializeServerClass {

 public:

  _Test3_InitializeServerClass();
};

#ifndef macintosh
static class _Test3_InitializeServerClass _Test3_InitializationInstance;
#endif

void Test3__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Test3__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Test3_T_O_I_to_Test1U, (ilu_StubProc) _Test3_T_O_I_to_Test1U_stub, ilu::CppLangIdx());
}

_Test3_InitializeServerClass::_Test3_InitializeServerClass()
{
	Test3__InitializeServer();
}

