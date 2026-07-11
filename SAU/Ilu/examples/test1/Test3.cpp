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

#include <ilu.hh>
#include "Test3.hh"

extern "C" {
#include <stdio.h>
#include <string.h>
};
static struct Test3_Exceptions_s exnstr = {
	 (ilu_Exception) 0	//E1
};

struct Test3_Exceptions_s * Test3_G::Exceptions()
{
	return(&exnstr);
}

static void Test3CatchException (iluCall _call, Test3Status *_val, ilu_Cardinal _ecode)
{
	if (_ecode > ilu_MethodOfCall(&_call->call)->me_exceptionCount || _ecode == 0) {
		_val->returnCode = ilu::ProtocolError;
		_val->values.anyvalue = (ilu_Cardinal) ilu_ProtocolException_Unknown;
	}
	else {
		_val->returnCode = ilu::ExceptionOfMethod(ilu_MethodOfCall(&_call->call), _ecode);
		if (_val->returnCode == NULL)
			return;

		else if (_val->returnCode == Test3_E_E1)
			{
				_val->values.Test3_E_E1_Value = ilu::InputString(_call, NULL, NULL, 0);
			}

	}
	return;
}

#include <stdarg.h>

void Test3_G::RaiseException (Test3Status *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	else if (stat->returnCode == Test3_E_E1)
		{
			stat->values.Test3_E_E1_Value = va_arg(ap, ilu_T_CString);
		}
	return;
}

#include <stdarg.h>

int Test3_G::SendException (iluCall _call, Test3Status *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Test3_G::SendException");
  _argSize = ilu::BeginSizingException(_call, eCode);
  if (stat->returnCode == NULL)
    0;	/* can't happen */
  else if (stat->returnCode == Test3_E_E1) {
	_argSize += (_dSize = ilu::SizeOfString(_call, stat->values.Test3_E_E1_Value, strlen(stat->values.Test3_E_E1_Value), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
	if (!ilu::BeginException (_call, eCode, _argSize))
	  goto faild;
  if (stat->returnCode == NULL)
    0;	/* can't happen*/
  else if (stat->returnCode == Test3_E_E1) {
	if (!ilu::OutputString (_call, stat->values.Test3_E_E1_Value, strlen(stat->values.Test3_E_E1_Value), 0))
	  goto faild;
	}
  ilu::FinishException (_call);
faild:
  return(0);
}

ilu_Boolean Test3_G::Output_FU (iluCall _call, Test3_T_FU * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Test1_T_TheE_ev1:
	if (!iluObject::OutputObject (_call, (class Test3_T_O *) _val->value.O, Test3_T_O::ILUClassRecord))
	  goto faild;
	break;

	case Test1_T_TheE_ev3:
	if (!ilu::OutputInteger(_call, (ilu_Integer) _val->value.integer))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test3_T_FU.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test3_T_FU * Test3_G::Input_FU (iluCall _call, Test3_T_FU * _ref)
{
	Test3_T_FU * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test3_T_FU *) malloc(sizeof(Test3_T_FU));
	switch (discriminator) {
	case Test1_T_TheE_ev1:
	_val->value.O = (class Test3_T_O *) iluObject::InputObject (_call, ilu_FALSE, Test3_T_O::ILUClassRecord);
	break;

	case Test1_T_TheE_ev3:
	ilu::InputInteger (_call, &_val->value.integer);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type Test1_T_TheE.\n", discriminator);
			break;
	}
	_val->discriminator = (Test1_T_TheE) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test3_G::SizeOf_FU (iluCall _call, Test3_T_FU * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Test1_T_TheE_ev1:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test3_T_O *) _val->value.O, Test3_T_O::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Test1_T_TheE_ev3:
	_argSize += (_dSize = ilu::SizeOfInteger(_call, _val->value.integer));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test3_T_FU.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Test3_G::Output_T2T1U3 (iluCall _call, Test3_T_T2T1U3 * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Test1_T_TheE_ev1:
	if (!ilu::OutputString (_call, _val->value.CString, strlen(_val->value.CString), 0))
	  goto faild;
	break;

	case Test1_T_TheE_ev3:
	if (!Test1_G::Output_U2 (_call, &_val->value.U2))
	  goto faild;
	break;

	case Test1_T_TheE_ev7:
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _val->value.v3, Test1_T_O2::ILUClassRecord))
	  goto faild;
	break;

	default:
	if (!ilu::OutputOptional (_call, (_val->value.v4 != NULL)))
	  goto faild;
	if (_val->value.v4 != NULL)
		if (!Test1_G::Output_TheR (_call, _val->value.v4))
	  goto faild;
	break;

	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test3_T_T2T1U3 * Test3_G::Input_T2T1U3 (iluCall _call, Test3_T_T2T1U3 * _ref)
{
	Test3_T_T2T1U3 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test3_T_T2T1U3 *) malloc(sizeof(Test3_T_T2T1U3));
	switch (discriminator) {
	case Test1_T_TheE_ev1:
	_val->value.CString = ilu::InputString(_call, NULL, NULL, 0);
	break;

	case Test1_T_TheE_ev3:
	Test1_G::Input_U2 (_call, &_val->value.U2);
	break;

	case Test1_T_TheE_ev7:
	_val->value.v3 = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	break;

	default:
	{ ilu_Boolean _present; ilu::InputOptional (_call, &_present);
		if (_present)	_val->value.v4 = Test1_G::Input_TheR (_call, NULL);
		else _val->value.v4 = NULL;
	}
	break;

	}
	_val->discriminator = (Test1_T_TheE) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test3_G::SizeOf_T2T1U3 (iluCall _call, Test3_T_T2T1U3 * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Test1_T_TheE_ev1:
	_argSize += (_dSize = ilu::SizeOfString(_call, _val->value.CString, strlen(_val->value.CString), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Test1_T_TheE_ev3:
	_argSize += (_dSize = Test1_G::SizeOf_U2 (_call, (Test1_T_U2 *) &_val->value.U2));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Test1_T_TheE_ev7:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _val->value.v3, Test1_T_O2::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
	_argSize += (_dSize = ilu::SizeOfOptional(_call, (_val->value.v4 != NULL)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (_val->value.v4 != NULL) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) _val->value.v4));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test3_G::Free_T2T1U3 (Test3_T_T2T1U3 * _val)
{
	switch (_val->discriminator) {
	case Test1_T_TheE_ev1:
		break;

	case Test1_T_TheE_ev3:
	Test1_G::Free_U2 (&_val->value.U2);
		break;

	case Test1_T_TheE_ev7:
		break;

	default:
	Test1_G::Free_RO (_val->value.v4);
		break;

	}
}

void Test3_G::Free_T1U3 (Test2_T_T1U3 * _val)
{
	switch (_val->discriminator) {
	case Test1_T_TheE_ev1:
		break;

	case Test1_T_TheE_ev3:
	Test1_G::Free_U2 (&_val->value.U2);
		break;

	case Test1_T_TheE_ev7:
		break;

	default:
	Test1_G::Free_RO (_val->value.v4);
		break;

	}
}

void Test3_G::Free_T1U (Test2_T_T1U * _val)
{
	switch (_val->discriminator) {
	case 0:
	Test1_G::Free_R (&_val->value.R);
		break;

	case 1:
	Test1_G::Free_RO (_val->value.RO);
		break;

	case 2:
	Test1_G::Free_CSS (_val->value.CSS);
		break;

	case 3:
		break;

	case 4:
	Test1_G::Free_OO (_val->value.OO);
		break;

	case 5:
		break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test2_T_T1U.\n", _val->discriminator);
			break;
	}
}

ilu_Class Test3_T_O::ILUClassRecord = NULL;

#define MethodRecord_Test3_T_O_I_to_Test1U ((Test3_T_O::ILUClassRecord)->cl_methods + 0)

class Test3_T_O * Test3_T_O::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Test3_T_O *) ilu::SBHToObject(sbh, Test3_T_O::ILUClassRecord);
}

class Test3_T_O * Test3_T_O::ILUQuaT (class iluObject *from)
{
	return((class Test3_T_O *) (from->ILUCastDown (Test3_T_O::ILUClassRecord)));
}

void * Test3_T_O::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Test3_T_O::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == Test1_T_O3::ILUClassRecord)
		return ((void *)((class Test1_T_O3 *) this));
	else if (cast_to == Test2_T_P::ILUClassRecord)
		return ((void *)((class Test2_T_P *) this));
	else return (NULL);
}

Test3_T_O::Test3_T_O ()
{
	this->ILUInstanceClassRecord = Test3_T_O::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Test3_T_O::~Test3_T_O ()
{
}

Test2_T_T1U * Test3_T_O::I_to_Test1U (Test3Status *_status, ilu_Integer i)
{
	Test2_T_T1U * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test3_T_O::ILUClassRecord, MethodRecord_Test3_T_O_I_to_Test1U))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, i));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) i))
	  goto faild;
	if (!ilu::FinishRequest (_call))
	  goto faild;
	_perror = ilu::WaitForReply (_call, &_scode);
	if (ILU_ERRNOK(_call[0].err)) goto faild;
	if (_perror != ilu_ProtocolException_Success) {
		_status->returnCode = ilu::ProtocolError;
		_status->values.anyvalue = (ilu_Cardinal) _perror;
		goto returnnow;
	}
	if (_scode == 0)
		{
		_status->returnCode = NULL;
		_retvalue = Test1_G::Input_TheU (_call, NULL);
	}
	else
		Test3CatchException (_call, _status, _scode);
	if (!ilu::ReplyRead(_call))
	  goto faild;
	goto returnnow;
faild:
	_status->returnCode = ilu::ProtocolError;
	_status->values.anyvalue = (ilu_Cardinal) _call[0].call.ca_pe;
returnnow:
	ilu::FinishCall (_call);
	return(_retvalue);
}

static class iluObject * Create_Test3_T_O(ilu_KernelObject obj) {
	class Test3_T_O *nobj = new Test3_T_O;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Test3_RegistrationClass {

 public:

  _Test3_RegistrationClass();
};

#ifndef macintosh
static class _Test3_RegistrationClass _Test3_RegistrationInstance;
#endif

void Test3__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Test3", "2.0beta1", "v2 (post-2.0alpha12)");
  initialized = 1;

  ilu::EnterOTMu();
  exnstr.E1 = ilu::DefineException("Test3", "E1", "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv");
  {	// for definition of Test3_T_O
    static ilu_CString Superclass_IDs[2] = {
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",
	"ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS"
	};
    ilu_Class t;
    Test3_T_O::ILUClassRecord = t = ilu::DefineObjectType(
	"Test3.O",	/* ILU name */
	"",	/* Brand */
	"ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg",	/* id */
	NULL,	/* singleton */
	ilu_kernelFALSE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	1,	/* number of methods */
	2,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Test3_T_O);
    {	//for method I-to-Test1U
      ilu_Exception exns[2];
      exns[0] = exnstr.E1;
      exns[1] = exnstr.E1;
      ilu::DefineMethod(t,
	0,	//method index
	"I-to-Test1U",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	2,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW");	//return type
    }	//end method I-to-Test1U
    ilu::ObjectTypeDefined(t);
  }	// end definition of Test3_T_O
  ilu::ExitOTMu();
}

_Test3_RegistrationClass::_Test3_RegistrationClass()
{
	Test3__Initialize();
}

