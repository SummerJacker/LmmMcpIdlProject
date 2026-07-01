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
#include <string.h>
};
static struct Test2_Exceptions_s exnstr = {
	 (ilu_Exception) 0	//E1
};

struct Test2_Exceptions_s * Test2_G::Exceptions()
{
	return(&exnstr);
}

static void Test2CatchException (iluCall _call, Test2Status *_val, ilu_Cardinal _ecode)
{
	if (_ecode > ilu_MethodOfCall(&_call->call)->me_exceptionCount || _ecode == 0) {
		_val->returnCode = ilu::ProtocolError;
		_val->values.anyvalue = (ilu_Cardinal) ilu_ProtocolException_Unknown;
	}
	else {
		_val->returnCode = ilu::ExceptionOfMethod(ilu_MethodOfCall(&_call->call), _ecode);
		if (_val->returnCode == NULL)
			return;

		else if (_val->returnCode == Test2_E_E1)
			{
				_val->values.Test2_E_E1_Value = (Test2_T_T1U *) malloc(sizeof(Test2_T_T1U));
				Test1_G::Input_TheU (_call, _val->values.Test2_E_E1_Value);
			}

	}
	return;
}

#include <stdarg.h>

void Test2_G::RaiseException (Test2Status *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	else if (stat->returnCode == Test2_E_E1)
		{
			stat->values.Test2_E_E1_Value = va_arg(ap, Test2_T_T1U *);
		}
	return;
}

#include <stdarg.h>

int Test2_G::SendException (iluCall _call, Test2Status *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Test2_G::SendException");
  _argSize = ilu::BeginSizingException(_call, eCode);
  if (stat->returnCode == NULL)
    0;	/* can't happen */
  else if (stat->returnCode == Test2_E_E1) {
	_argSize += (_dSize = Test1_G::SizeOf_TheU (_call, (Test1_T_TheU *) stat->values.Test2_E_E1_Value));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
	if (!ilu::BeginException (_call, eCode, _argSize))
	  goto faild;
  if (stat->returnCode == NULL)
    0;	/* can't happen*/
  else if (stat->returnCode == Test2_E_E1) {
	if (!Test1_G::Output_TheU (_call, stat->values.Test2_E_E1_Value))
	  goto faild;
	}
  ilu::FinishException (_call);
faild:
  return(0);
}

ilu_Boolean Test2_G::Output_T1U3 (iluCall _call, Test2_T_T1U3 * _val)
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

Test2_T_T1U3 * Test2_G::Input_T1U3 (iluCall _call, Test2_T_T1U3 * _ref)
{
	Test2_T_T1U3 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test2_T_T1U3 *) malloc(sizeof(Test2_T_T1U3));
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

ilu_Cardinal Test2_G::SizeOf_T1U3 (iluCall _call, Test2_T_T1U3 * _val)
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

void Test2_G::Free_T1U3 (Test2_T_T1U3 * _val)
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

void Test2_G::Free_U3 (Test1_T_U3 * _val)
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

ilu_Boolean Test2_G::Output_T1U2 (iluCall _call, Test2_T_T1U2 * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_shortinteger_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 3:
	case 7:
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _val->value.x1))
	  goto faild;
	break;

	case 1:
	case 22:
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _val->value.x2, Test1_T_O2::ILUClassRecord))
	  goto faild;
	break;

	case 2:
	if (!Test1_G::Output_CSS (_call, _val->value.x3))
	  goto faild;
	break;

		default:
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test2_T_T1U2 * Test2_G::Input_T1U2 (iluCall _call, Test2_T_T1U2 * _ref)
{
	Test2_T_T1U2 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortinteger_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test2_T_T1U2 *) malloc(sizeof(Test2_T_T1U2));
	switch (discriminator) {
	case 3:
	case 7:
	ilu::InputBoolean (_call, &_val->value.x1);
	break;

	case 1:
	case 22:
	_val->value.x2 = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	break;

	case 2:
	_val->value.x3 = Test1_G::Input_CSS (_call, NULL);
	break;

		default:
			break;
	}
	_val->discriminator = (ilu_ShortInteger) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test2_G::SizeOf_T1U2 (iluCall _call, Test2_T_T1U2 * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_shortinteger_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case 3:
	case 7:
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _val->value.x1));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 1:
	case 22:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _val->value.x2, Test1_T_O2::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 2:
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) _val->value.x3));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test2_G::Free_T1U2 (Test2_T_T1U2 * _val)
{
	switch (_val->discriminator) {
	case 3:
	case 7:
		break;

	case 1:
	case 22:
		break;

	case 2:
	Test1_G::Free_CSS (_val->value.x3);
		break;

		default:
			break;
	}
}

void Test2_G::Free_U2 (Test1_T_U2 * _val)
{
	switch (_val->discriminator) {
	case 3:
	case 7:
		break;

	case 1:
	case 22:
		break;

	case 2:
	Test1_G::Free_CSS (_val->value.x3);
		break;

		default:
			break;
	}
}

ilu_Boolean Test2_G::Output_T1U (iluCall _call, Test2_T_T1U * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_shortinteger_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	if (!Test1_G::Output_TheR (_call, &_val->value.R))
	  goto faild;
	break;

	case 1:
	if (!ilu::OutputOptional (_call, (_val->value.RO != NULL)))
	  goto faild;
	if (_val->value.RO != NULL)
		if (!Test1_G::Output_TheR (_call, _val->value.RO))
	  goto faild;
	break;

	case 2:
	if (!Test1_G::Output_CSS (_call, _val->value.CSS))
	  goto faild;
	break;

	case 3:
	if (!iluObject::OutputObject (_call, (class Test1_T_TheO1 *) _val->value.O1, Test1_T_TheO1::ILUClassRecord))
	  goto faild;
	break;

	case 4:
	if (!ilu::OutputOptional (_call, (_val->value.OO != NULL)))
	  goto faild;
	if (_val->value.OO != NULL)
		if (!iluObject::OutputObject (_call, (class Test1_T_TheO1 *) _val->value.OO, Test1_T_TheO1::ILUClassRecord))
	  goto faild;
	break;

	case 5:
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _val->value.boolean))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test2_T_T1U.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test2_T_T1U * Test2_G::Input_T1U (iluCall _call, Test2_T_T1U * _ref)
{
	Test2_T_T1U * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortinteger_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test2_T_T1U *) malloc(sizeof(Test2_T_T1U));
	switch (discriminator) {
	case 0:
	Test1_G::Input_TheR (_call, &_val->value.R);
	break;

	case 1:
	{ ilu_Boolean _present; ilu::InputOptional (_call, &_present);
		if (_present)	_val->value.RO = Test1_G::Input_TheR (_call, NULL);
		else _val->value.RO = NULL;
	}
	break;

	case 2:
	_val->value.CSS = Test1_G::Input_CSS (_call, NULL);
	break;

	case 3:
	_val->value.O1 = (class Test1_T_TheO1 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_TheO1::ILUClassRecord);
	break;

	case 4:
	{ ilu_Boolean _present; ilu::InputOptional (_call, &_present);
		if (_present)	_val->value.OO = (class Test1_T_TheO1 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_TheO1::ILUClassRecord);
		else _val->value.OO = NULL;
	}
	break;

	case 5:
	ilu::InputBoolean (_call, &_val->value.boolean);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type ilu_ShortInteger.\n", discriminator);
			break;
	}
	_val->discriminator = (ilu_ShortInteger) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test2_G::SizeOf_T1U (iluCall _call, Test2_T_T1U * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_shortinteger_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &_val->value.R));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 1:
	_argSize += (_dSize = ilu::SizeOfOptional(_call, (_val->value.RO != NULL)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (_val->value.RO != NULL) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) _val->value.RO));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	break;
	case 2:
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) _val->value.CSS));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 3:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_TheO1 *) _val->value.O1, Test1_T_TheO1::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 4:
	_argSize += (_dSize = ilu::SizeOfOptional(_call, (_val->value.OO != NULL)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (_val->value.OO != NULL) {
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_TheO1 *) _val->value.OO, Test1_T_TheO1::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	break;
	case 5:
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, _val->value.boolean));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test2_T_T1U.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test2_G::Free_T1U (Test2_T_T1U * _val)
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

void Test2_G::Free_U (Test1_T_U * _val)
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
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U.\n", _val->discriminator);
			break;
	}
}

ilu_Boolean Test2_G::Output_U2 (iluCall _call, Test2_T_U2 * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Test1_T_TheE_ev1:
	if (!ilu::OutputString (_call, _val->value.CString, strlen(_val->value.CString), 0))
	  goto faild;
	break;

	case Test1_T_TheE_ev3:
	if (!iluObject::OutputObject (_call, (class Test1_T_TheO1 *) _val->value.O1, Test1_T_TheO1::ILUClassRecord))
	  goto faild;
	break;

	case Test1_T_TheE_ev7:
	if (!iluObject::OutputObject (_call, (class Test2_T_P *) _val->value.P, Test2_T_P::ILUClassRecord))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test2_T_U2.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test2_T_U2 * Test2_G::Input_U2 (iluCall _call, Test2_T_U2 * _ref)
{
	Test2_T_U2 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test2_T_U2 *) malloc(sizeof(Test2_T_U2));
	switch (discriminator) {
	case Test1_T_TheE_ev1:
	_val->value.CString = ilu::InputString(_call, NULL, NULL, 0);
	break;

	case Test1_T_TheE_ev3:
	_val->value.O1 = (class Test1_T_TheO1 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_TheO1::ILUClassRecord);
	break;

	case Test1_T_TheE_ev7:
	_val->value.P = (class Test2_T_P *) iluObject::InputObject (_call, ilu_FALSE, Test2_T_P::ILUClassRecord);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type Test1_T_TheE.\n", discriminator);
			break;
	}
	_val->discriminator = (Test1_T_TheE) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test2_G::SizeOf_U2 (iluCall _call, Test2_T_U2 * _val)
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
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_TheO1 *) _val->value.O1, Test1_T_TheO1::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Test1_T_TheE_ev7:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test2_T_P *) _val->value.P, Test2_T_P::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test2_T_U2.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Class Test2_T_P::ILUClassRecord = NULL;

#define MethodRecord_Test2_T_P_SR_to_I ((Test2_T_P::ILUClassRecord)->cl_methods + 0)

class Test2_T_P * Test2_T_P::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Test2_T_P *) ilu::SBHToObject(sbh, Test2_T_P::ILUClassRecord);
}

class Test2_T_P * Test2_T_P::ILUQuaT (class iluObject *from)
{
	return((class Test2_T_P *) (from->ILUCastDown (Test2_T_P::ILUClassRecord)));
}

void * Test2_T_P::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Test2_T_P::ILUClassRecord)
		return ((void *) this);
	else return (NULL);
}

Test2_T_P::Test2_T_P ()
{
	this->ILUInstanceClassRecord = Test2_T_P::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Test2_T_P::~Test2_T_P ()
{
}

ilu_Integer Test2_T_P::SR_to_I (Test2Status *_status, ilu_ShortReal i)
{
	ilu_Integer _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test2_T_P::ILUClassRecord, MethodRecord_Test2_T_P_SR_to_I))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, i));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) i))
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
		ilu::InputInteger (_call, &_retvalue);
	};
	/* no exceptions to catch */
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

static class iluObject * Create_Test2_T_P(ilu_KernelObject obj) {
	class Test2_T_P *nobj = new Test2_T_P;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Test2_RegistrationClass {

 public:

  _Test2_RegistrationClass();
};

#ifndef macintosh
static class _Test2_RegistrationClass _Test2_RegistrationInstance;
#endif

void Test2__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Test2", "2.0beta1", "v2 (post-2.0alpha12)");
  initialized = 1;

  ilu::EnterOTMu();
  exnstr.E1 = ilu::DefineException("Test2", "E1", "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW");
  {	// for definition of Test2_T_P
    ilu_Class t;
    Test2_T_P::ILUClassRecord = t = ilu::DefineObjectType(
	"Test2.P",	/* ILU name */
	"",	/* Brand */
	"ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS",	/* id */
	NULL,	/* singleton */
	ilu_kernelFALSE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	1,	/* number of methods */
	0,	/* number of superclasses */
	NULL	/* no superclass uids */);
    iluObject::RegisterSurrogateCreator(t, Create_Test2_T_P);
    {	//for method SR-to-I
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"SR-to-I",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY");	//return type
    }	//end method SR-to-I
    ilu::ObjectTypeDefined(t);
  }	// end definition of Test2_T_P
  ilu::ExitOTMu();
}

_Test2_RegistrationClass::_Test2_RegistrationClass()
{
	Test2__Initialize();
}

