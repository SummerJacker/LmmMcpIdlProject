/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:04 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c++-stubber.exe" of Mon Aug 18 11:47:27 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Test1.hh"

extern "C" {
#include <stdio.h>
};
extern ilu_Class Test1Classes;

void _Test1_T_O4_R_to_R_stub (iluCall _call)
{
    Test1Status _status;
    ilu_Real r;
  ilu_Real _retvalue;
    Test1_T_O4 *_realobj;

    _realobj = (Test1_T_O4 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_O4::ILUClassRecord);
	ilu::InputReal (_call, &r);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->R_to_R (&_status, r);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfReal(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputReal(_call, (double) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Test1_T_P_m2_stub (iluCall _call)
{
    Test1Status _status;
    ilu_Integer j;
  Test1_T_IS _retvalue;
    Test1_T_P *_realobj;

    _realobj = (Test1_T_P *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_P::ILUClassRecord);
	ilu::InputInteger (_call, &j);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->m2 (&_status, j);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Test1_G::SizeOf_IS (_call, (Test1_T_IS) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Test1_G::Output_IS (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
	Test1_G::Free_IS (_retvalue);
faild:
    return;
}

void _Test1_T_O3_RS_R_to_R_IS_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_RS r;
    Test1_T_R r2;
  Test1_T_IS _retvalue;
    Test1_T_O3 *_realobj;

    _realobj = (Test1_T_O3 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_O3::ILUClassRecord);
	r = Test1_G::Input_TheRS (_call, NULL);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->RS_R_to_R_IS (&_status, r, &r2);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = Test1_G::SizeOf_IS (_call, (Test1_T_IS) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &r2));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!Test1_G::Output_IS (_call, _retvalue))
	  goto faild;
	if (!Test1_G::Output_TheR (_call, &r2))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
	free((char *) r);
	Test1_G::Free_R (&r2);
	Test1_G::Free_IS (_retvalue);
faild:
    return;
}

void _Test1_T_O3_O1_U_to_U_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_O1 * o;
    Test1_T_U u;
    Test1_T_O3 *_realobj;

    _realobj = (Test1_T_O3 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_O3::ILUClassRecord);
	o = (class Test1_T_TheO1 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_TheO1::ILUClassRecord);
	Test1_G::Input_TheU (_call, &u);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _realobj->O1_U_to_U (&_status, o, &u);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += 0;
	_argSize += (_dSize = Test1_G::SizeOf_TheU (_call, (Test1_T_TheU *) &u));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!Test1_G::Output_TheU (_call, &u))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
	Test1_G::Free_U (&u);
faild:
    return;
}

void _Test1_T_O3_BS_to_I_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_BS b;
  Test1_T_I _retvalue;
    Test1_T_O3 *_realobj;

    _realobj = (Test1_T_O3 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_O3::ILUClassRecord);
	b = Test1_G::Input_BS (_call, NULL);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->BS_to_I (&_status, b);

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
	Test1_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Test1_T_TheO1_U_CSS_to_U_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_U u;
    Test1_T_CSS css;
  Test1_T_U * _retvalue;
    Test1_T_TheO1 *_realobj;

    _realobj = (Test1_T_TheO1 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_TheO1::ILUClassRecord);
	Test1_G::Input_TheU (_call, &u);
	css = Test1_G::Input_CSS (_call, NULL);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->U_CSS_to_U (&_status, &u, css);

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
	Test1_G::SendException (_call, &_status);
    }
	free((char *) css);
	Test1_G::Free_U (_retvalue);
faild:
    return;
}

void _Test1_T_TheO1_f_CSS_to_RO_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_CSS css;
  Test1_T_RO _retvalue;
    Test1_T_TheO1 *_realobj;

    _realobj = (Test1_T_TheO1 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_TheO1::ILUClassRecord);
	css = Test1_G::Input_CSS (_call, NULL);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->f_CSS_to_RO (&_status, css);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = ilu::SizeOfOptional(_call, (_retvalue != NULL)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (_retvalue != NULL) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!ilu::OutputOptional (_call, (_retvalue != NULL)))
	  goto faild;
	if (_retvalue != NULL)
		if (!Test1_G::Output_TheR (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
	free((char *) css);
	Test1_G::Free_RO (_retvalue);
faild:
    return;
}

void _Test1_T_TheO1_R_ScS_to_F_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_R r;
    Test1_T_ScS s;
  ilu_ShortReal _retvalue;
    Test1_T_TheO1 *_realobj;

    _realobj = (Test1_T_TheO1 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_TheO1::ILUClassRecord);
	Test1_G::Input_TheR (_call, &r);
	s = ilu::InputString(_call, NULL, NULL, 0);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->R_ScS_to_F (&_status, &r, s);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Test1_T_TheO1_a_RO_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_RO ro;
    Test1_T_TheO1 *_realobj;

    _realobj = (Test1_T_TheO1 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_TheO1::ILUClassRecord);
	{ ilu_Boolean _present; ilu::InputOptional (_call, &_present);
		if (_present)	ro = Test1_G::Input_TheR (_call, NULL);
		else ro = NULL;
	}
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _realobj->a_RO (&_status, ro);

    /* asynchronous method -- no reply */
    ilu::NoReply (_call);
faild:
    return;
}

void _Test1_T_TheO1_get_O2_stub (iluCall _call)
{
    Test1Status _status;
  class Test1_T_O2 * _retvalue;
    Test1_T_TheO1 *_realobj;

    _realobj = (Test1_T_TheO1 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_TheO1::ILUClassRecord);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->get_O2 (&_status);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _retvalue, Test1_T_O2::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _retvalue, Test1_T_O2::ILUClassRecord))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Test1_T_TheO1_get_O3_stub (iluCall _call)
{
    Test1Status _status;
    ilu_Boolean subclass;
  class Test1_T_O3 * _retvalue;
    Test1_T_TheO1 *_realobj;

    _realobj = (Test1_T_TheO1 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_TheO1::ILUClassRecord);
	ilu::InputBoolean (_call, &subclass);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->get_O3 (&_status, subclass);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O3 *) _retvalue, Test1_T_O3::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!iluObject::OutputObject (_call, (class Test1_T_O3 *) _retvalue, Test1_T_O3::ILUClassRecord))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
faild:
    return;
}

void _Test1_T_O2_OO_A0_to_CSS_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_OO o;
    Test1_T_A0 a;
  Test1_T_CSS _retvalue;
    Test1_T_O2 *_realobj;

    _realobj = (Test1_T_O2 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_O2::ILUClassRecord);
	{ ilu_Boolean _present; ilu::InputOptional (_call, &_present);
		if (_present)	o = (class Test1_T_TheO1 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_TheO1::ILUClassRecord);
		else o = NULL;
	}
	ilu::InputOpaque (_call, a, 8);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->OO_A0_to_CSS (&_status, o, a);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_TRUE);
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) _retvalue));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_TRUE, _argSize))
	  goto faild;
	if (!Test1_G::Output_CSS (_call, _retvalue))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
	Test1_G::Free_CSS (_retvalue);
faild:
    return;
}

void _Test1_T_O2_R_I_A1_to_I_A0_stub (iluCall _call)
{
    Test1Status _status;
    Test1_T_R r;
    Test1_T_I i;
    Test1_T_A1 a;
  Test1_T_A0 * _retvalue;
    Test1_T_O2 *_realobj;

    _realobj = (Test1_T_O2 *) iluObject::InputObject(_call, ilu_TRUE, Test1_T_O2::ILUClassRecord);
	Test1_G::Input_TheR (_call, &r);
	ilu::InputInteger (_call, &i);
	Test1_G::Input_TheA1 (_call, (Test1_T_ScS *) a);
	if (!ilu::FinishParameters(_call, (void *) _realobj))
	  goto faild;
    _status.returnCode = NULL;
    _status.callerPassport = _call->call.ca_caller;
    _retvalue = _realobj->R_I_A1_to_I_A0 (&_status, &r, &i, a);

    if (_status.returnCode == NULL) {
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize=ilu::BeginSizingReply(_call, ilu_FALSE);
	_argSize += (_dSize = ilu::SizeOfOpaque(_call, ((_retvalue == NULL) ? 0 : *_retvalue), 8));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, i));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::BeginReply (_call, ilu_FALSE, _argSize))
	  goto faild;
	if (!ilu::OutputOpaque(_call, ((_retvalue == NULL) ? 0 : *_retvalue), 8))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) i))
	  goto faild;
	ilu::FinishReply (_call);
	}
    else {
	Test1_G::SendException (_call, &_status);
    }
faild:
    return;
}

#define MethodRecord_Test1_T_O4_R_to_R ((Test1_T_O4::ILUClassRecord)->cl_methods + 0)

#define MethodRecord_Test1_T_P_m2 ((Test1_T_P::ILUClassRecord)->cl_methods + 0)

#define MethodRecord_Test1_T_O3_RS_R_to_R_IS ((Test1_T_O3::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Test1_T_O3_O1_U_to_U ((Test1_T_O3::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Test1_T_O3_BS_to_I ((Test1_T_O3::ILUClassRecord)->cl_methods + 2)

#define MethodRecord_Test1_T_TheO1_U_CSS_to_U ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Test1_T_TheO1_f_CSS_to_RO ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Test1_T_TheO1_R_ScS_to_F ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Test1_T_TheO1_a_RO ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Test1_T_TheO1_get_O2 ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Test1_T_TheO1_get_O3 ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 5)

#define MethodRecord_Test1_T_O2_OO_A0_to_CSS ((Test1_T_O2::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Test1_T_O2_R_I_A1_to_I_A0 ((Test1_T_O2::ILUClassRecord)->cl_methods + 1)



/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Test1_InitializeServerClass {

 public:

  _Test1_InitializeServerClass();
};

#ifndef macintosh
static class _Test1_InitializeServerClass _Test1_InitializationInstance;
#endif

void Test1__InitializeServer(void)
{
	static int initialized = 0;

	if (initialized) return;
	initialized = 1;

	Test1__Initialize();
	ilu_SetMethodStubProc(MethodRecord_Test1_T_O4_R_to_R, (ilu_StubProc) _Test1_T_O4_R_to_R_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_P_m2, (ilu_StubProc) _Test1_T_P_m2_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_O3_RS_R_to_R_IS, (ilu_StubProc) _Test1_T_O3_RS_R_to_R_IS_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_O3_O1_U_to_U, (ilu_StubProc) _Test1_T_O3_O1_U_to_U_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_O3_BS_to_I, (ilu_StubProc) _Test1_T_O3_BS_to_I_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_TheO1_U_CSS_to_U, (ilu_StubProc) _Test1_T_TheO1_U_CSS_to_U_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_TheO1_f_CSS_to_RO, (ilu_StubProc) _Test1_T_TheO1_f_CSS_to_RO_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_TheO1_R_ScS_to_F, (ilu_StubProc) _Test1_T_TheO1_R_ScS_to_F_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_TheO1_a_RO, (ilu_StubProc) _Test1_T_TheO1_a_RO_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_TheO1_get_O2, (ilu_StubProc) _Test1_T_TheO1_get_O2_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_TheO1_get_O3, (ilu_StubProc) _Test1_T_TheO1_get_O3_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_O2_OO_A0_to_CSS, (ilu_StubProc) _Test1_T_O2_OO_A0_to_CSS_stub, ilu::CppLangIdx());
	ilu_SetMethodStubProc(MethodRecord_Test1_T_O2_R_I_A1_to_I_A0, (ilu_StubProc) _Test1_T_O2_R_I_A1_to_I_A0_stub, ilu::CppLangIdx());
}

_Test1_InitializeServerClass::_Test1_InitializeServerClass()
{
	Test1__InitializeServer();
}

