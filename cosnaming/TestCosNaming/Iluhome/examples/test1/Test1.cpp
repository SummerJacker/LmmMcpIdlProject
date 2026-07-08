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
#include <string.h>
};
static struct Test1_Exceptions_s exnstr = {
	 (ilu_Exception) 0	//E1
	,(ilu_Exception) 0	//E2
	,(ilu_Exception) 0	//CantCreate
	,(ilu_Exception) 0	//E3
	,(ilu_Exception) 0	//E4
	,(ilu_Exception) 0	//E5
	,(ilu_Exception) 0	//E6
	,(ilu_Exception) 0	//E7
	,(ilu_Exception) 0	//E8
	,(ilu_Exception) 0	//E9
};

struct Test1_Exceptions_s * Test1_G::Exceptions()
{
	return(&exnstr);
}

static void Test1CatchException (iluCall _call, Test1Status *_val, ilu_Cardinal _ecode)
{
	if (_ecode > ilu_MethodOfCall(&_call->call)->me_exceptionCount || _ecode == 0) {
		_val->returnCode = ilu::ProtocolError;
		_val->values.anyvalue = (ilu_Cardinal) ilu_ProtocolException_Unknown;
	}
	else {
		_val->returnCode = ilu::ExceptionOfMethod(ilu_MethodOfCall(&_call->call), _ecode);
		if (_val->returnCode == NULL)
			return;

		else if (_val->returnCode == Test1_E_E1)
			{
				_val->values.Test1_E_E1_Value = (Test1_T_U *) malloc(sizeof(Test1_T_U));
				Test1_G::Input_TheU (_call, _val->values.Test1_E_E1_Value);
			}
		else if (_val->returnCode == Test1_E_E2)
			{
				ilu::InputInteger (_call, &_val->values.Test1_E_E2_Value);
			}
		else if (_val->returnCode == Test1_E_E3)
			{
				{ ilu_Boolean _present; ilu::InputOptional (_call, &_present);
		if (_present)	_val->values.Test1_E_E3_Value = Test1_G::Input_TheR (_call, NULL);
		else _val->values.Test1_E_E3_Value = NULL;
	}
			}
		else if (_val->returnCode == Test1_E_E4)
			{
				_val->values.Test1_E_E4_Value = (class Test1_T_TheO1 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_TheO1::ILUClassRecord);
			}
		else if (_val->returnCode == Test1_E_E5)
			{
				_val->values.Test1_E_E5_Value = (Test1_T_A0 *) malloc(sizeof(Test1_T_A0));
				ilu::InputOpaque (_call, *_val->values.Test1_E_E5_Value, 8);
			}
		else if (_val->returnCode == Test1_E_E6)
			{
				_val->values.Test1_E_E6_Value = Test1_G::Input_TheRS (_call, NULL);
			}
		else if (_val->returnCode == Test1_E_E7)
			{
				_val->values.Test1_E_E7_Value = ilu::InputString(_call, NULL, NULL, 0);
			}
		else if (_val->returnCode == Test1_E_E8)
			{
				_val->values.Test1_E_E8_Value = (Test1_T_A1 *) malloc(sizeof(Test1_T_A1));
				Test1_G::Input_TheA1 (_call, (Test1_T_ScS *) *_val->values.Test1_E_E8_Value);
			}
		else if (_val->returnCode == Test1_E_E9)
			{
				_val->values.Test1_E_E9_Value = (Test1_T_R *) malloc(sizeof(Test1_T_R));
				Test1_G::Input_TheR (_call, _val->values.Test1_E_E9_Value);
			}

	}
	return;
}

#include <stdarg.h>

void Test1_G::RaiseException (Test1Status *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	else if (stat->returnCode == Test1_E_E1)
		{
			stat->values.Test1_E_E1_Value = va_arg(ap, Test1_T_U *);
		}
	else if (stat->returnCode == Test1_E_E2)
		{
			stat->values.Test1_E_E2_Value = va_arg(ap, ilu_Integer);
		}
	else if (stat->returnCode == Test1_E_E3)
		{
			stat->values.Test1_E_E3_Value = va_arg(ap, Test1_T_RO);
		}
	else if (stat->returnCode == Test1_E_E4)
		{
			stat->values.Test1_E_E4_Value = va_arg(ap, Test1_T_O1 *);
		}
	else if (stat->returnCode == Test1_E_E5)
		{
			stat->values.Test1_E_E5_Value = va_arg(ap, Test1_T_A0 *);
		}
	else if (stat->returnCode == Test1_E_E6)
		{
			stat->values.Test1_E_E6_Value = va_arg(ap, Test1_T_RS);
		}
	else if (stat->returnCode == Test1_E_E7)
		{
			stat->values.Test1_E_E7_Value = va_arg(ap, ilu_T_CString);
		}
	else if (stat->returnCode == Test1_E_E8)
		{
			stat->values.Test1_E_E8_Value = va_arg(ap, Test1_T_A1 *);
		}
	else if (stat->returnCode == Test1_E_E9)
		{
			stat->values.Test1_E_E9_Value = va_arg(ap, Test1_T_R *);
		}
	return;
}

#include <stdarg.h>

int Test1_G::SendException (iluCall _call, Test1Status *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Test1_G::SendException");
  _argSize = ilu::BeginSizingException(_call, eCode);
  if (stat->returnCode == NULL)
    0;	/* can't happen */
  else if (stat->returnCode == Test1_E_E1) {
	_argSize += (_dSize = Test1_G::SizeOf_TheU (_call, (Test1_T_TheU *) stat->values.Test1_E_E1_Value));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
  else if (stat->returnCode == Test1_E_E2) {
	_argSize += (_dSize = ilu::SizeOfInteger(_call, stat->values.Test1_E_E2_Value));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
  else if (stat->returnCode == Test1_E_E3) {
	_argSize += (_dSize = ilu::SizeOfOptional(_call, (stat->values.Test1_E_E3_Value != NULL)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (stat->values.Test1_E_E3_Value != NULL) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) stat->values.Test1_E_E3_Value));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
  }
  else if (stat->returnCode == Test1_E_E4) {
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_TheO1 *) stat->values.Test1_E_E4_Value, Test1_T_TheO1::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
  else if (stat->returnCode == Test1_E_E5) {
	_argSize += (_dSize = ilu::SizeOfOpaque(_call, *stat->values.Test1_E_E5_Value, 8));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
  else if (stat->returnCode == Test1_E_E6) {
	_argSize += (_dSize = Test1_G::SizeOf_TheRS (_call, (Test1_T_TheRS) stat->values.Test1_E_E6_Value));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
  else if (stat->returnCode == Test1_E_E7) {
	_argSize += (_dSize = ilu::SizeOfString(_call, stat->values.Test1_E_E7_Value, strlen(stat->values.Test1_E_E7_Value), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
  else if (stat->returnCode == Test1_E_E8) {
	_argSize += (_dSize = Test1_G::SizeOf_TheA1 (_call, *stat->values.Test1_E_E8_Value));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
  else if (stat->returnCode == Test1_E_E9) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) stat->values.Test1_E_E9_Value));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
  }
	if (!ilu::BeginException (_call, eCode, _argSize))
	  goto faild;
  if (stat->returnCode == NULL)
    0;	/* can't happen*/
  else if (stat->returnCode == Test1_E_E1) {
	if (!Test1_G::Output_TheU (_call, stat->values.Test1_E_E1_Value))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E2) {
	if (!ilu::OutputInteger(_call, (ilu_Integer) stat->values.Test1_E_E2_Value))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E3) {
	if (!ilu::OutputOptional (_call, (stat->values.Test1_E_E3_Value != NULL)))
	  goto faild;
	if (stat->values.Test1_E_E3_Value != NULL)
		if (!Test1_G::Output_TheR (_call, stat->values.Test1_E_E3_Value))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E4) {
	if (!iluObject::OutputObject (_call, (class Test1_T_TheO1 *) stat->values.Test1_E_E4_Value, Test1_T_TheO1::ILUClassRecord))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E5) {
	if (!ilu::OutputOpaque(_call, *stat->values.Test1_E_E5_Value, 8))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E6) {
	if (!Test1_G::Output_TheRS (_call, stat->values.Test1_E_E6_Value))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E7) {
	if (!ilu::OutputString (_call, stat->values.Test1_E_E7_Value, strlen(stat->values.Test1_E_E7_Value), 0))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E8) {
	if (!Test1_G::Output_TheA1 (_call, *stat->values.Test1_E_E8_Value))
	  goto faild;
	}
  else if (stat->returnCode == Test1_E_E9) {
	if (!Test1_G::Output_TheR (_call, stat->values.Test1_E_E9_Value))
	  goto faild;
	}
  ilu::FinishException (_call);
faild:
  return(0);
}

ilu_Boolean Test1_G::Output_U_scard (iluCall _call, Test1_T_U_scard * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_shortcardinal_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	if (!Test1_G::Output_TheR (_call, &_val->value.R))
	  goto faild;
	break;

	case 1:
	if (!iluObject::OutputObject (_call, (class Test1_T_TheO1 *) _val->value.One, Test1_T_TheO1::ILUClassRecord))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_scard.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_U_scard * Test1_G::Input_U_scard (iluCall _call, Test1_T_U_scard * _ref)
{
	Test1_T_U_scard * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortcardinal_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U_scard *) malloc(sizeof(Test1_T_U_scard));
	switch (discriminator) {
	case 0:
	Test1_G::Input_TheR (_call, &_val->value.R);
	break;

	case 1:
	_val->value.One = (class Test1_T_TheO1 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_TheO1::ILUClassRecord);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type ilu_ShortCardinal.\n", discriminator);
			break;
	}
	_val->discriminator = (ilu_ShortCardinal) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_U_scard (iluCall _call, Test1_T_U_scard * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_shortcardinal_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &_val->value.R));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 1:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_TheO1 *) _val->value.One, Test1_T_TheO1::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_scard.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_U_scard (Test1_T_U_scard * _val)
{
	switch (_val->discriminator) {
	case 0:
	Test1_G::Free_R (&_val->value.R);
		break;

	case 1:
		break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_scard.\n", _val->discriminator);
			break;
	}
}

ilu_Boolean Test1_G::Output_U_card (iluCall _call, Test1_T_U_card * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_cardinal_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	if (!Test1_G::Output_TheR (_call, &_val->value.R))
	  goto faild;
	break;

	case 1:
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_card.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_U_card * Test1_G::Input_U_card (iluCall _call, Test1_T_U_card * _ref)
{
	Test1_T_U_card * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_cardinal_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U_card *) malloc(sizeof(Test1_T_U_card));
	switch (discriminator) {
	case 0:
	Test1_G::Input_TheR (_call, &_val->value.R);
	break;

	case 1:
	_val->value.O2 = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type ilu_Cardinal.\n", discriminator);
			break;
	}
	_val->discriminator = (ilu_Cardinal) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_U_card (iluCall _call, Test1_T_U_card * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_cardinal_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &_val->value.R));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 1:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_card.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_U_card (Test1_T_U_card * _val)
{
	switch (_val->discriminator) {
	case 0:
	Test1_G::Free_R (&_val->value.R);
		break;

	case 1:
		break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_card.\n", _val->discriminator);
			break;
	}
}

ilu_Boolean Test1_G::Output_U_int (iluCall _call, Test1_T_U_int * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_integer_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	if (!Test1_G::Output_TheR (_call, &_val->value.R))
	  goto faild;
	break;

	case 1:
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_int.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_U_int * Test1_G::Input_U_int (iluCall _call, Test1_T_U_int * _ref)
{
	Test1_T_U_int * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_integer_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U_int *) malloc(sizeof(Test1_T_U_int));
	switch (discriminator) {
	case 0:
	Test1_G::Input_TheR (_call, &_val->value.R);
	break;

	case 1:
	_val->value.O2 = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type ilu_Integer.\n", discriminator);
			break;
	}
	_val->discriminator = (ilu_Integer) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_U_int (iluCall _call, Test1_T_U_int * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_integer_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &_val->value.R));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 1:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_int.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_U_int (Test1_T_U_int * _val)
{
	switch (_val->discriminator) {
	case 0:
	Test1_G::Free_R (&_val->value.R);
		break;

	case 1:
		break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_int.\n", _val->discriminator);
			break;
	}
}

ilu_Boolean Test1_G::Output_U_byte (iluCall _call, Test1_T_U_byte * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_byte_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	if (!Test1_G::Output_TheR (_call, &_val->value.R))
	  goto faild;
	break;

	case 1:
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_byte.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_U_byte * Test1_G::Input_U_byte (iluCall _call, Test1_T_U_byte * _ref)
{
	Test1_T_U_byte * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_byte_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U_byte *) malloc(sizeof(Test1_T_U_byte));
	switch (discriminator) {
	case 0:
	Test1_G::Input_TheR (_call, &_val->value.R);
	break;

	case 1:
	_val->value.O2 = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type ilu_Byte.\n", discriminator);
			break;
	}
	_val->discriminator = (ilu_Byte) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_U_byte (iluCall _call, Test1_T_U_byte * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_byte_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &_val->value.R));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 1:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_byte.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_U_byte (Test1_T_U_byte * _val)
{
	switch (_val->discriminator) {
	case 0:
	Test1_G::Free_R (&_val->value.R);
		break;

	case 1:
		break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U_byte.\n", _val->discriminator);
			break;
	}
}

ilu_Boolean Test1_G::Output_U4 (iluCall _call, Test1_T_U4 * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_shortinteger_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 3:
	case 7:
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) _val->value.x1))
	  goto faild;
	break;

	default:
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _val->value.x2, Test1_T_O2::ILUClassRecord))
	  goto faild;
	break;

	case 1:
	case 0:
	if (!Test1_G::Output_CSS (_call, _val->value.x3))
	  goto faild;
	break;

	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_U4 * Test1_G::Input_U4 (iluCall _call, Test1_T_U4 * _ref)
{
	Test1_T_U4 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortinteger_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U4 *) malloc(sizeof(Test1_T_U4));
	switch (discriminator) {
	case 3:
	case 7:
	ilu::InputBoolean (_call, &_val->value.x1);
	break;

	default:
	_val->value.x2 = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	break;

	case 1:
	case 0:
	_val->value.x3 = Test1_G::Input_CSS (_call, NULL);
	break;

	}
	_val->discriminator = (ilu_ShortInteger) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_U4 (iluCall _call, Test1_T_U4 * _val)
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
	default:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _val->value.x2, Test1_T_O2::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case 1:
	case 0:
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) _val->value.x3));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_U4 (Test1_T_U4 * _val)
{
	switch (_val->discriminator) {
	case 3:
	case 7:
		break;

	default:
		break;

	case 1:
	case 0:
	Test1_G::Free_CSS (_val->value.x3);
		break;

	}
}

ilu_Boolean Test1_G::Output_U3 (iluCall _call, Test1_T_U3 * _val)
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

Test1_T_U3 * Test1_G::Input_U3 (iluCall _call, Test1_T_U3 * _ref)
{
	Test1_T_U3 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U3 *) malloc(sizeof(Test1_T_U3));
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

ilu_Cardinal Test1_G::SizeOf_U3 (iluCall _call, Test1_T_U3 * _val)
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

void Test1_G::Free_U3 (Test1_T_U3 * _val)
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

ilu_Boolean Test1_G::Output_U2 (iluCall _call, Test1_T_U2 * _val)
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

Test1_T_U2 * Test1_G::Input_U2 (iluCall _call, Test1_T_U2 * _ref)
{
	Test1_T_U2 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortinteger_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U2 *) malloc(sizeof(Test1_T_U2));
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

ilu_Cardinal Test1_G::SizeOf_U2 (iluCall _call, Test1_T_U2 * _val)
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

void Test1_G::Free_U2 (Test1_T_U2 * _val)
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

ilu_Boolean Test1_G::Output_U1 (iluCall _call, Test1_T_U1 * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_shortinteger_tk))
	  goto faild;
	switch (_val->discriminator) {
	case 0:
	if (!Test1_G::Output_TheR (_call, &_val->value.R))
	  goto faild;
	break;

	case 1:
	if (!Test1_G::Output_TheA1 (_call, _val->value.A1))
	  goto faild;
	break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U1.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_U1 * Test1_G::Input_U1 (iluCall _call, Test1_T_U1 * _ref)
{
	Test1_T_U1 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortinteger_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U1 *) malloc(sizeof(Test1_T_U1));
	switch (discriminator) {
	case 0:
	Test1_G::Input_TheR (_call, &_val->value.R);
	break;

	case 1:
	Test1_G::Input_TheA1 (_call, (Test1_T_ScS *) &_val->value.A1);
	break;

		default:
			fprintf (stderr, "Bad value %d received for discriminant of value of union type ilu_ShortInteger.\n", discriminator);
			break;
	}
	_val->discriminator = (ilu_ShortInteger) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_U1 (iluCall _call, Test1_T_U1 * _val)
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
	_argSize += (_dSize = Test1_G::SizeOf_TheA1 (_call, _val->value.A1));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	default:
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U1.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_U1 (Test1_T_U1 * _val)
{
	switch (_val->discriminator) {
	case 0:
	Test1_G::Free_R (&_val->value.R);
		break;

	case 1:
		break;

		default:
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U1.\n", _val->discriminator);
			break;
	}
}

ilu_Boolean Test1_G::Output_U (iluCall _call, Test1_T_U * _val)
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
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_U * Test1_G::Input_U (iluCall _call, Test1_T_U * _ref)
{
	Test1_T_U * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortinteger_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_U *) malloc(sizeof(Test1_T_U));
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

ilu_Cardinal Test1_G::SizeOf_U (iluCall _call, Test1_T_U * _val)
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
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_U.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_U (Test1_T_U * _val)
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

ilu_Boolean Test1_G::Output_TheU (iluCall _call, Test1_T_TheU * _val)
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
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_TheU.\n", _val->discriminator);
			break;
	}
	ilu::EndUnion(_call);
	return 1;
faild:
	return 0;
}

Test1_T_TheU * Test1_G::Input_TheU (iluCall _call, Test1_T_TheU * _ref)
{
	Test1_T_TheU * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_shortinteger_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_TheU *) malloc(sizeof(Test1_T_TheU));
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

ilu_Cardinal Test1_G::SizeOf_TheU (iluCall _call, Test1_T_TheU * _val)
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
		fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_TheU.\n", _val->discriminator);
		break;
	}
	ilu::EndUnion(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_TheU (Test1_T_TheU * _val)
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
			fprintf (stderr, "Bad value %d in discriminant of value of union type Test1_T_TheU.\n", _val->discriminator);
			break;
	}
}

ilu_Boolean Test1_G::Output_OO2 (iluCall _call, Test1_T_OO2 * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_boolean_tk))
	  goto faild;
	switch (_val->discriminator) {
	case ilu_TRUE:
	if (!iluObject::OutputObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord))
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

Test1_T_OO2 * Test1_G::Input_OO2 (iluCall _call, Test1_T_OO2 * _ref)
{
	Test1_T_OO2 * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_boolean_tk);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_OO2 *) malloc(sizeof(Test1_T_OO2));
	switch (discriminator) {
	case ilu_TRUE:
	_val->value.O2 = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	break;

		default:
			break;
	}
	_val->discriminator = (ilu_Boolean) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_OO2 (iluCall _call, Test1_T_OO2 * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_boolean_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case ilu_TRUE:
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_O2 *) _val->value.O2, Test1_T_O2::ILUClassRecord));
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

void Test1_G::Free_OO (Test1_T_OO _val)
{
}

void Test1_G::Free_TheOO (Test1_T_TheOO _val)
{
}

void Test1_G::Free_RO (Test1_T_RO _val)
{
	Test1_G::Free_R (_val);
}

ilu_Boolean Test1_G::Output_RS (iluCall _call, Test1_T_RS _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Test1_T_R *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Test1_G::Output_TheR (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Test1_T_RS Test1_G::Input_RS (iluCall _call, Test1_T_RS _ref)
{
	Test1_T_RS _val;

	ilu_Cardinal _count, _index;
	Test1_T_R * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Test1_T_TheRS_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Test1_G::Input_TheR (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_RS (iluCall _call, Test1_T_RS _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Test1_T_R *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_RS (Test1_T_RS _val)
{
	register Test1_T_R *data = _val->Array();

	ilu_Cardinal _size = _val->Length();

	register ilu_Cardinal i;

	if (_size > 0) {
		for (i = 0;  i < _size;  i++)			Test1_G::Free_R (&data[i]);
	};
}

ilu_Boolean Test1_G::Output_TheRS (iluCall _call, Test1_T_TheRS _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Test1_T_R *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Test1_G::Output_TheR (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Test1_T_TheRS Test1_G::Input_TheRS (iluCall _call, Test1_T_TheRS _ref)
{
	Test1_T_TheRS _val;

	ilu_Cardinal _count, _index;
	Test1_T_R * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Test1_T_TheRS_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Test1_G::Input_TheR (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_TheRS (iluCall _call, Test1_T_TheRS _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Test1_T_R *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_TheRS (Test1_T_TheRS _val)
{
	register Test1_T_R *data = _val->Array();

	ilu_Cardinal _size = _val->Length();

	register ilu_Cardinal i;

	if (_size > 0) {
		for (i = 0;  i < _size;  i++)			Test1_G::Free_R (&data[i]);
	};
}

ilu_Boolean Test1_G::Output_R (iluCall _call, Test1_T_R * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Test1_G::Output_TheA1 (_call, (_val->a)))
	  goto faild;
	if (!Test1_G::Output_CSS (_call, (_val->css)))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) (_val->i)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Test1_T_R * Test1_G::Input_R (iluCall _call, Test1_T_R * _ref)
{
	Test1_T_R * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_R *) malloc(sizeof(Test1_T_R));
	Test1_G::Input_TheA1 (_call, (Test1_T_ScS *) _val->a);
	_val->css = Test1_G::Input_CSS (_call, NULL);
	ilu::InputInteger (_call, &_val->i);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_R (iluCall _call, Test1_T_R * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Test1_G::SizeOf_TheA1 (_call, (_val->a)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) (_val->css)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, (_val->i)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_R (Test1_T_R * _val)
{
	Test1_G::Free_CSS (_val->css);
}

ilu_Boolean Test1_G::Output_TheR (iluCall _call, Test1_T_TheR * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Test1_G::Output_TheA1 (_call, (_val->a)))
	  goto faild;
	if (!Test1_G::Output_CSS (_call, (_val->css)))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) (_val->i)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Test1_T_TheR * Test1_G::Input_TheR (iluCall _call, Test1_T_TheR * _ref)
{
	Test1_T_TheR * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Test1_T_TheR *) malloc(sizeof(Test1_T_TheR));
	Test1_G::Input_TheA1 (_call, (Test1_T_ScS *) _val->a);
	_val->css = Test1_G::Input_CSS (_call, NULL);
	ilu::InputInteger (_call, &_val->i);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_TheR (iluCall _call, Test1_T_TheR * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Test1_G::SizeOf_TheA1 (_call, (_val->a)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) (_val->css)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, (_val->i)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_TheR (Test1_T_TheR * _val)
{
	Test1_G::Free_CSS (_val->css);
}

ilu_Boolean Test1_G::Output_BS (iluCall _call, Test1_T_BS _val)
{
	if (!ilu::OutputBytes (_call, _val->Array(), _val->Length(), 0))
	  goto faild;
	return 1;
faild:
	return 0;
}

Test1_T_BS Test1_G::Input_BS (iluCall _call, Test1_T_BS _ref)
{
	Test1_T_BS _val;

	ilu_Cardinal _count;
	ilu_Byte *_bytes;

	_bytes = ilu::InputBytes (_call, NULL, &_count, 0);
	if (_ref != NULL) {
		_val = _ref;
		_val->_Test1_T_BS_sequence::Clear(ilu_FALSE);
		for (ilu_Cardinal _index = 0; _index < _count; _index++)
			_val->_Test1_T_BS_sequence::Append(_bytes[_index]);
	}
	else _val = _Test1_T_BS_sequence::Create (_count, _bytes);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_BS (iluCall _call, Test1_T_BS _val)
{
	return(ilu::SizeOfBytes (_call, _val->Array(), _val->Length(), 0));
}

void Test1_G::Free_BS (Test1_T_BS _val)
{
	register ilu_Byte *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Test1_G::Output_A2 (iluCall _call, Test1_T_A2 _val)
{
	if (!ilu::OutputArray (_call))
	  goto faild;
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	{ register int _i1;
	for (_i1 = 0;  _i1 < 4;  _i1 += 1)
	if (!ilu::OutputCardinal(_call, (ilu_Cardinal) _val[_i0][_i1]))
	  goto faild;
	}
	}
	ilu::EndArray (_call);
	return 1;
faild:
	return 0;
}

Test1_T_A2 * Test1_G::Input_A2 (iluCall _call, Test1_T_A2 _ref)
{
	Test1_T_A2 * _val;

	ilu::InputArray (_call);
	if (_ref != NULL) _val = (Test1_T_A2 *) _ref; else _val = (Test1_T_A2 *) malloc(sizeof(Test1_T_A2));
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	{ register int _i1;
	for (_i1 = 0;  _i1 < 4;  _i1 += 1)
	ilu::InputCardinal (_call, &(*_val)[_i0][_i1]);
	}
	}
	ilu::EndArray(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_A2 (iluCall _call, Test1_T_A2 _val)
{
	ilu_Cardinal _dSize, _argSize = 0;

	_argSize = ilu::SizeOfArray (_call);
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	{ register int _i1;
	for (_i1 = 0;  _i1 < 4;  _i1 += 1)
	_argSize += (_dSize = ilu::SizeOfCardinal(_call, _val[_i0][_i1]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	}
	ilu::EndArray(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Test1_G::Output_A1 (iluCall _call, Test1_T_A1 _val)
{
	if (!ilu::OutputArray (_call))
	  goto faild;
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	if (!ilu::OutputString (_call, _val[_i0], strlen(_val[_i0]), 0))
	  goto faild;
	}
	ilu::EndArray (_call);
	return 1;
faild:
	return 0;
}

Test1_T_A1 * Test1_G::Input_A1 (iluCall _call, Test1_T_A1 _ref)
{
	Test1_T_A1 * _val;

	ilu::InputArray (_call);
	if (_ref != NULL) _val = (Test1_T_A1 *) _ref; else _val = (Test1_T_A1 *) malloc(sizeof(Test1_T_A1));
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	(*_val)[_i0] = ilu::InputString(_call, NULL, NULL, 0);
	}
	ilu::EndArray(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_A1 (iluCall _call, Test1_T_A1 _val)
{
	ilu_Cardinal _dSize, _argSize = 0;

	_argSize = ilu::SizeOfArray (_call);
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	_argSize += (_dSize = ilu::SizeOfString(_call, _val[_i0], strlen(_val[_i0]), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndArray(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Test1_G::Output_TheA1 (iluCall _call, Test1_T_TheA1 _val)
{
	if (!ilu::OutputArray (_call))
	  goto faild;
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	if (!ilu::OutputString (_call, _val[_i0], strlen(_val[_i0]), 0))
	  goto faild;
	}
	ilu::EndArray (_call);
	return 1;
faild:
	return 0;
}

Test1_T_TheA1 * Test1_G::Input_TheA1 (iluCall _call, Test1_T_TheA1 _ref)
{
	Test1_T_TheA1 * _val;

	ilu::InputArray (_call);
	if (_ref != NULL) _val = (Test1_T_TheA1 *) _ref; else _val = (Test1_T_TheA1 *) malloc(sizeof(Test1_T_TheA1));
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	(*_val)[_i0] = ilu::InputString(_call, NULL, NULL, 0);
	}
	ilu::EndArray(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_TheA1 (iluCall _call, Test1_T_TheA1 _val)
{
	ilu_Cardinal _dSize, _argSize = 0;

	_argSize = ilu::SizeOfArray (_call);
	{ register int _i0;
	for (_i0 = 0;  _i0 < 3;  _i0 += 1)
	_argSize += (_dSize = ilu::SizeOfString(_call, _val[_i0], strlen(_val[_i0]), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndArray(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Test1_G::Output_CSS (iluCall _call, Test1_T_CSS _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Test1_T_ScS *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!ilu::OutputString (_call, data[i], strlen(data[i]), 0))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Test1_T_CSS Test1_G::Input_CSS (iluCall _call, Test1_T_CSS _ref)
{
	Test1_T_CSS _val;

	ilu_Cardinal _count, _index;
	Test1_T_ScS _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Test1_T_CSS_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = ilu::InputString(_call, NULL, NULL, 0);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_CSS (iluCall _call, Test1_T_CSS _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Test1_T_ScS *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = ilu::SizeOfString(_call, data[i], strlen(data[i]), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_CSS (Test1_T_CSS _val)
{
	register Test1_T_ScS *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Test1_G::Output_IS (iluCall _call, Test1_T_IS _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	ilu_Integer *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!ilu::OutputInteger(_call, (ilu_Integer) data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Test1_T_IS Test1_G::Input_IS (iluCall _call, Test1_T_IS _ref)
{
	Test1_T_IS _val;

	ilu_Cardinal _count, _index;
	ilu_Integer _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Test1_T_IS_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		ilu::InputInteger (_call, &_tmp);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Test1_G::SizeOf_IS (iluCall _call, Test1_T_IS _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register ilu_Integer *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = ilu::SizeOfInteger(_call, data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Test1_G::Free_IS (Test1_T_IS _val)
{
	register ilu_Integer *data = _val->Array();

	free((char *) data);
}

_Test1_T_TheRS_sequence::_Test1_T_TheRS_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Test1_T_TheRS_sequence::~_Test1_T_TheRS_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Test1_T_TheRS _Test1_T_TheRS_sequence::Create (ilu_Cardinal initial_size, Test1_T_R *initial_data)
{
  Test1_T_TheRS s = new _Test1_T_TheRS_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Test1_T_R *) malloc((unsigned int)(sizeof(Test1_T_R) * (s->_maximum = initial_size)));
  return s;
}

void _Test1_T_TheRS_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Test1_T_R *) 0;
  }
  _length = 0;
}

void _Test1_T_TheRS_sequence::Append (Test1_T_R * item)
{
  if (_buffer == NULL) {
    _buffer = (Test1_T_R *) malloc ((unsigned int)(sizeof(Test1_T_R) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Test1_T_R *) realloc ((char *) _buffer, (unsigned int)(sizeof(Test1_T_R) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Test1_T_R * _Test1_T_TheRS_sequence::RemoveHead ()
{
  static Test1_T_R k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Test1_T_R)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Test1_T_R *) 0);
}

Test1_T_R * _Test1_T_TheRS_sequence::RemoveTail ()
{
  static Test1_T_R k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Test1_T_R *) 0);
}

ilu_Cardinal _Test1_T_TheRS_sequence::RemoveAll (ilu_Boolean (*matchproc)(Test1_T_R *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Test1_T_R)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Test1_T_R * _Test1_T_TheRS_sequence::Find (ilu_Boolean (*matchproc)(Test1_T_R *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Test1_T_R *) 0);
}

void _Test1_T_TheRS_sequence::Enumerate (void (*enumproc)(Test1_T_R *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Test1_T_TheRS_sequence::Length ()
{
  return _length;
}

Test1_T_R * _Test1_T_TheRS_sequence::Array ()
{
  return _buffer;
}

Test1_T_R * _Test1_T_TheRS_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Test1_T_R *) 0);
}

_Test1_T_BS_sequence::_Test1_T_BS_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Test1_T_BS_sequence::~_Test1_T_BS_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Test1_T_BS _Test1_T_BS_sequence::Create (ilu_Cardinal initial_size, ilu_Byte *initial_data)
{
  Test1_T_BS s = new _Test1_T_BS_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (ilu_Byte *) malloc((unsigned int)(sizeof(ilu_Byte) * (s->_maximum = initial_size)));
  return s;
}

void _Test1_T_BS_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (ilu_Byte *) 0;
  }
  _length = 0;
}

void _Test1_T_BS_sequence::Append (ilu_Byte item)
{
  if (_buffer == NULL) {
    _buffer = (ilu_Byte *) malloc ((unsigned int)(sizeof(ilu_Byte) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (ilu_Byte *) realloc ((char *) _buffer, (unsigned int)(sizeof(ilu_Byte) * _maximum));
  };
  _buffer[_length] = item;
  _length += 1;
}

ilu_Byte _Test1_T_BS_sequence::RemoveHead ()
{
  static ilu_Byte k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(ilu_Byte)));
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_Byte) 0);
}

ilu_Byte _Test1_T_BS_sequence::RemoveTail ()
{
  static ilu_Byte k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_Byte) 0);
}

ilu_Cardinal _Test1_T_BS_sequence::RemoveAll (ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(ilu_Byte)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

ilu_Byte _Test1_T_BS_sequence::Find (ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((ilu_Byte) 0);
}

void _Test1_T_BS_sequence::Enumerate (void (*enumproc)(ilu_Byte, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Test1_T_BS_sequence::Length ()
{
  return _length;
}

ilu_Byte * _Test1_T_BS_sequence::Array ()
{
  return _buffer;
}

ilu_Byte _Test1_T_BS_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((ilu_Byte) 0);
}

_Test1_T_CSS_sequence::_Test1_T_CSS_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Test1_T_CSS_sequence::~_Test1_T_CSS_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Test1_T_CSS _Test1_T_CSS_sequence::Create (ilu_Cardinal initial_size, Test1_T_ScS *initial_data)
{
  Test1_T_CSS s = new _Test1_T_CSS_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Test1_T_ScS *) malloc((unsigned int)(sizeof(Test1_T_ScS) * (s->_maximum = initial_size)));
  return s;
}

void _Test1_T_CSS_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Test1_T_ScS *) 0;
  }
  _length = 0;
}

void _Test1_T_CSS_sequence::Append (Test1_T_ScS item)
{
  if (_buffer == NULL) {
    _buffer = (Test1_T_ScS *) malloc ((unsigned int)(sizeof(Test1_T_ScS) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Test1_T_ScS *) realloc ((char *) _buffer, (unsigned int)(sizeof(Test1_T_ScS) * _maximum));
  };
  _buffer[_length] = item;
  _length += 1;
}

Test1_T_ScS _Test1_T_CSS_sequence::RemoveHead ()
{
  static Test1_T_ScS k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Test1_T_ScS)));
    _length -= 1;
    return (k);
  }
  else
    return ((Test1_T_ScS) 0);
}

Test1_T_ScS _Test1_T_CSS_sequence::RemoveTail ()
{
  static Test1_T_ScS k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (k);
  }
  else
    return ((Test1_T_ScS) 0);
}

ilu_Cardinal _Test1_T_CSS_sequence::RemoveAll (ilu_Boolean (*matchproc)(Test1_T_ScS, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Test1_T_ScS)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Test1_T_ScS _Test1_T_CSS_sequence::Find (ilu_Boolean (*matchproc)(Test1_T_ScS, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((Test1_T_ScS) 0);
}

void _Test1_T_CSS_sequence::Enumerate (void (*enumproc)(Test1_T_ScS, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Test1_T_CSS_sequence::Length ()
{
  return _length;
}

Test1_T_ScS * _Test1_T_CSS_sequence::Array ()
{
  return _buffer;
}

Test1_T_ScS _Test1_T_CSS_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((Test1_T_ScS) 0);
}

_Test1_T_IS_sequence::_Test1_T_IS_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Test1_T_IS_sequence::~_Test1_T_IS_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Test1_T_IS _Test1_T_IS_sequence::Create (ilu_Cardinal initial_size, ilu_Integer *initial_data)
{
  Test1_T_IS s = new _Test1_T_IS_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (ilu_Integer *) malloc((unsigned int)(sizeof(ilu_Integer) * (s->_maximum = initial_size)));
  return s;
}

void _Test1_T_IS_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (ilu_Integer *) 0;
  }
  _length = 0;
}

void _Test1_T_IS_sequence::Append (ilu_Integer item)
{
  if (_buffer == NULL) {
    _buffer = (ilu_Integer *) malloc ((unsigned int)(sizeof(ilu_Integer) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (ilu_Integer *) realloc ((char *) _buffer, (unsigned int)(sizeof(ilu_Integer) * _maximum));
  };
  _buffer[_length] = item;
  _length += 1;
}

ilu_Integer _Test1_T_IS_sequence::RemoveHead ()
{
  static ilu_Integer k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(ilu_Integer)));
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_Integer) 0);
}

ilu_Integer _Test1_T_IS_sequence::RemoveTail ()
{
  static ilu_Integer k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_Integer) 0);
}

ilu_Cardinal _Test1_T_IS_sequence::RemoveAll (ilu_Boolean (*matchproc)(ilu_Integer, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(ilu_Integer)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

ilu_Integer _Test1_T_IS_sequence::Find (ilu_Boolean (*matchproc)(ilu_Integer, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((ilu_Integer) 0);
}

void _Test1_T_IS_sequence::Enumerate (void (*enumproc)(ilu_Integer, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Test1_T_IS_sequence::Length ()
{
  return _length;
}

ilu_Integer * _Test1_T_IS_sequence::Array ()
{
  return _buffer;
}

ilu_Integer _Test1_T_IS_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((ilu_Integer) 0);
}

ilu_Class Test1_T_O4::ILUClassRecord = NULL;

#define MethodRecord_Test1_T_O4_R_to_R ((Test1_T_O4::ILUClassRecord)->cl_methods + 0)

class Test1_T_O4 * Test1_T_O4::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Test1_T_O4 *) ilu::SBHToObject(sbh, Test1_T_O4::ILUClassRecord);
}

class Test1_T_O4 * Test1_T_O4::ILUQuaT (class iluObject *from)
{
	return((class Test1_T_O4 *) (from->ILUCastDown (Test1_T_O4::ILUClassRecord)));
}

void * Test1_T_O4::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Test1_T_O4::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == Test1_T_O3::ILUClassRecord)
		return ((void *)((class Test1_T_O3 *) this));
	else return (NULL);
}

Test1_T_O4::Test1_T_O4 ()
{
	this->ILUInstanceClassRecord = Test1_T_O4::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Test1_T_O4::~Test1_T_O4 ()
{
}

ilu_Real Test1_T_O4::R_to_R (Test1Status *_status, ilu_Real r)
{
	ilu_Real _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_O4::ILUClassRecord, MethodRecord_Test1_T_O4_R_to_R))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfReal(_call, r));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputReal(_call, (double) r))
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
		ilu::InputReal (_call, &_retvalue);
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

static class iluObject * Create_Test1_T_O4(ilu_KernelObject obj) {
	class Test1_T_O4 *nobj = new Test1_T_O4;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

ilu_Class Test1_T_P::ILUClassRecord = NULL;

#define MethodRecord_Test1_T_P_m2 ((Test1_T_P::ILUClassRecord)->cl_methods + 0)

class Test1_T_P * Test1_T_P::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Test1_T_P *) ilu::SBHToObject(sbh, Test1_T_P::ILUClassRecord);
}

class Test1_T_P * Test1_T_P::ILUQuaT (class iluObject *from)
{
	return((class Test1_T_P *) (from->ILUCastDown (Test1_T_P::ILUClassRecord)));
}

void * Test1_T_P::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Test1_T_P::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == Test1_T_O3::ILUClassRecord)
		return ((void *)((class Test1_T_O3 *) this));
	else return (NULL);
}

Test1_T_P::Test1_T_P ()
{
	this->ILUInstanceClassRecord = Test1_T_P::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Test1_T_P::~Test1_T_P ()
{
}

Test1_T_IS Test1_T_P::m2 (Test1Status *_status, ilu_Integer j)
{
	Test1_T_IS _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_P::ILUClassRecord, MethodRecord_Test1_T_P_m2))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, j));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) j))
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
		_retvalue = Test1_G::Input_IS (_call, NULL);
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

static class iluObject * Create_Test1_T_P(ilu_KernelObject obj) {
	class Test1_T_P *nobj = new Test1_T_P;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

ilu_Class Test1_T_O3::ILUClassRecord = NULL;

#define MethodRecord_Test1_T_O3_RS_R_to_R_IS ((Test1_T_O3::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Test1_T_O3_O1_U_to_U ((Test1_T_O3::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Test1_T_O3_BS_to_I ((Test1_T_O3::ILUClassRecord)->cl_methods + 2)

class Test1_T_O3 * Test1_T_O3::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Test1_T_O3 *) ilu::SBHToObject(sbh, Test1_T_O3::ILUClassRecord);
}

class Test1_T_O3 * Test1_T_O3::ILUQuaT (class iluObject *from)
{
	return((class Test1_T_O3 *) (from->ILUCastDown (Test1_T_O3::ILUClassRecord)));
}

void * Test1_T_O3::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Test1_T_O3::ILUClassRecord)
		return ((void *) this);
	else return (NULL);
}

Test1_T_O3::Test1_T_O3 ()
{
	this->ILUInstanceClassRecord = Test1_T_O3::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Test1_T_O3::~Test1_T_O3 ()
{
}

Test1_T_IS Test1_T_O3::RS_R_to_R_IS (Test1Status *_status, Test1_T_RS r, Test1_T_R * r2)
{
	Test1_T_IS _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_O3::ILUClassRecord, MethodRecord_Test1_T_O3_RS_R_to_R_IS))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_TheRS (_call, (Test1_T_TheRS) r));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Test1_G::Output_TheRS (_call, r))
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
		_retvalue = Test1_G::Input_IS (_call, NULL);
	Test1_G::Input_TheR (_call, r2);
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

void Test1_T_O3::O1_U_to_U (Test1Status *_status, Test1_T_O1 * o, Test1_T_U * u)
{
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_O3::ILUClassRecord, MethodRecord_Test1_T_O3_O1_U_to_U))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_TheO1 *) o, Test1_T_TheO1::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_TheU (_call, (Test1_T_TheU *) u));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!iluObject::OutputObject (_call, (class Test1_T_TheO1 *) o, Test1_T_TheO1::ILUClassRecord))
	  goto faild;
	if (!Test1_G::Output_TheU (_call, u))
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
		/* no return value */
	Test1_G::Input_TheU (_call, u);
	}
	else
		Test1CatchException (_call, _status, _scode);
	if (!ilu::ReplyRead(_call))
	  goto faild;
	goto returnnow;
faild:
	_status->returnCode = ilu::ProtocolError;
	_status->values.anyvalue = (ilu_Cardinal) _call[0].call.ca_pe;
returnnow:
	ilu::FinishCall (_call);
	return;
}

Test1_T_I Test1_T_O3::BS_to_I (Test1Status *_status, Test1_T_BS b)
{
	Test1_T_I _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_O3::ILUClassRecord, MethodRecord_Test1_T_O3_BS_to_I))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_BS (_call, (Test1_T_BS) b));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Test1_G::Output_BS (_call, b))
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

static class iluObject * Create_Test1_T_O3(ilu_KernelObject obj) {
	class Test1_T_O3 *nobj = new Test1_T_O3;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

ilu_Class Test1_T_TheO1::ILUClassRecord = NULL;

#define MethodRecord_Test1_T_TheO1_U_CSS_to_U ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Test1_T_TheO1_f_CSS_to_RO ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Test1_T_TheO1_R_ScS_to_F ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Test1_T_TheO1_a_RO ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Test1_T_TheO1_get_O2 ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Test1_T_TheO1_get_O3 ((Test1_T_TheO1::ILUClassRecord)->cl_methods + 5)

class Test1_T_TheO1 * Test1_T_TheO1::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Test1_T_TheO1 *) ilu::SBHToObject(sbh, Test1_T_TheO1::ILUClassRecord);
}

class Test1_T_TheO1 * Test1_T_TheO1::ILUQuaT (class iluObject *from)
{
	return((class Test1_T_TheO1 *) (from->ILUCastDown (Test1_T_TheO1::ILUClassRecord)));
}

void * Test1_T_TheO1::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Test1_T_TheO1::ILUClassRecord)
		return ((void *) this);
	else return (NULL);
}

Test1_T_TheO1::Test1_T_TheO1 ()
{
	this->ILUInstanceClassRecord = Test1_T_TheO1::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Test1_T_TheO1::~Test1_T_TheO1 ()
{
}

Test1_T_U * Test1_T_TheO1::U_CSS_to_U (Test1Status *_status, Test1_T_U * u, Test1_T_CSS css)
{
	Test1_T_U * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_TheO1::ILUClassRecord, MethodRecord_Test1_T_TheO1_U_CSS_to_U))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_TheU (_call, (Test1_T_TheU *) u));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) css));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Test1_G::Output_TheU (_call, u))
	  goto faild;
	if (!Test1_G::Output_CSS (_call, css))
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
		Test1CatchException (_call, _status, _scode);
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

Test1_T_RO Test1_T_TheO1::f_CSS_to_RO (Test1Status *_status, Test1_T_CSS css)
{
	Test1_T_RO _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_TheO1::ILUClassRecord, MethodRecord_Test1_T_TheO1_f_CSS_to_RO))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_CSS (_call, (Test1_T_CSS) css));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Test1_G::Output_CSS (_call, css))
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
		{ ilu_Boolean _present; ilu::InputOptional (_call, &_present);
		if (_present)	_retvalue = Test1_G::Input_TheR (_call, NULL);
		else _retvalue = NULL;
	}
	}
	else
		Test1CatchException (_call, _status, _scode);
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

ilu_ShortReal Test1_T_TheO1::R_ScS_to_F (Test1Status *_status, Test1_T_R * r, Test1_T_ScS s)
{
	ilu_ShortReal _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_TheO1::ILUClassRecord, MethodRecord_Test1_T_TheO1_R_ScS_to_F))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) r));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, s, strlen(s), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Test1_G::Output_TheR (_call, r))
	  goto faild;
	if (!ilu::OutputString (_call, s, strlen(s), 0))
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
		ilu::InputShortReal (_call, &_retvalue);
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

void Test1_T_TheO1::a_RO (Test1Status *_status, Test1_T_RO ro)
{
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_TheO1::ILUClassRecord, MethodRecord_Test1_T_TheO1_a_RO))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfOptional(_call, (ro != NULL)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (ro != NULL) {
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) ro));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputOptional (_call, (ro != NULL)))
	  goto faild;
	if (ro != NULL)
		if (!Test1_G::Output_TheR (_call, ro))
	  goto faild;
	if (!ilu::FinishRequest (_call))
	  goto faild;
	goto returnnow;
faild:
	_status->returnCode = ilu::ProtocolError;
	_status->values.anyvalue = (ilu_Cardinal) _call[0].call.ca_pe;
returnnow:
	ilu::FinishCall (_call);
	return;
}

class Test1_T_O2 * Test1_T_TheO1::get_O2 (Test1Status *_status)
{
	class Test1_T_O2 * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_TheO1::ILUClassRecord, MethodRecord_Test1_T_TheO1_get_O2))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
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
		_retvalue = (class Test1_T_O2 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O2::ILUClassRecord);
	}
	else
		Test1CatchException (_call, _status, _scode);
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

class Test1_T_O3 * Test1_T_TheO1::get_O3 (Test1Status *_status, ilu_Boolean subclass)
{
	class Test1_T_O3 * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_TheO1::ILUClassRecord, MethodRecord_Test1_T_TheO1_get_O3))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, subclass));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) subclass))
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
		_retvalue = (class Test1_T_O3 *) iluObject::InputObject (_call, ilu_FALSE, Test1_T_O3::ILUClassRecord);
	}
	else
		Test1CatchException (_call, _status, _scode);
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

static class iluObject * Create_Test1_T_TheO1(ilu_KernelObject obj) {
	class Test1_T_TheO1 *nobj = new Test1_T_TheO1;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

ilu_Class Test1_T_O2::ILUClassRecord = NULL;

#define MethodRecord_Test1_T_O2_OO_A0_to_CSS ((Test1_T_O2::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Test1_T_O2_R_I_A1_to_I_A0 ((Test1_T_O2::ILUClassRecord)->cl_methods + 1)

class Test1_T_O2 * Test1_T_O2::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Test1_T_O2 *) ilu::SBHToObject(sbh, Test1_T_O2::ILUClassRecord);
}

class Test1_T_O2 * Test1_T_O2::ILUQuaT (class iluObject *from)
{
	return((class Test1_T_O2 *) (from->ILUCastDown (Test1_T_O2::ILUClassRecord)));
}

void * Test1_T_O2::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Test1_T_O2::ILUClassRecord)
		return ((void *) this);
	else return (NULL);
}

Test1_T_O2::Test1_T_O2 ()
{
	this->ILUInstanceClassRecord = Test1_T_O2::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Test1_T_O2::~Test1_T_O2 ()
{
}

Test1_T_CSS Test1_T_O2::OO_A0_to_CSS (Test1Status *_status, Test1_T_OO o, Test1_T_A0 a)
{
	Test1_T_CSS _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_O2::ILUClassRecord, MethodRecord_Test1_T_O2_OO_A0_to_CSS))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfOptional(_call, (o != NULL)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (o != NULL) {
	_argSize += (_dSize = iluObject::SizeOfObject (_call, (class Test1_T_TheO1 *) o, Test1_T_TheO1::ILUClassRecord));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	_argSize += (_dSize = ilu::SizeOfOpaque(_call, a, 8));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputOptional (_call, (o != NULL)))
	  goto faild;
	if (o != NULL)
		if (!iluObject::OutputObject (_call, (class Test1_T_TheO1 *) o, Test1_T_TheO1::ILUClassRecord))
	  goto faild;
	if (!ilu::OutputOpaque(_call, a, 8))
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
		_retvalue = Test1_G::Input_CSS (_call, NULL);
	}
	else
		Test1CatchException (_call, _status, _scode);
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

Test1_T_A0 * Test1_T_O2::R_I_A1_to_I_A0 (Test1Status *_status, Test1_T_R * r, Test1_T_I * i, Test1_T_A1 a)
{
	Test1_T_A0 * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Test1_T_O2::ILUClassRecord, MethodRecord_Test1_T_O2_R_I_A1_to_I_A0))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_TheR (_call, (Test1_T_TheR *) r));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, *i));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Test1_G::SizeOf_TheA1 (_call, a));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!Test1_G::Output_TheR (_call, r))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) *i))
	  goto faild;
	if (!Test1_G::Output_TheA1 (_call, a))
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
		* (ilu_Byte * *) &_retvalue = ilu::InputOpaque(_call, NULL, 8);
	ilu::InputInteger (_call, i);
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

static class iluObject * Create_Test1_T_O2(ilu_KernelObject obj) {
	class Test1_T_O2 *nobj = new Test1_T_O2;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Test1_RegistrationClass {

 public:

  _Test1_RegistrationClass();
};

#ifndef macintosh
static class _Test1_RegistrationClass _Test1_RegistrationInstance;
#endif

void Test1__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Test1", "2.0beta1", "v2 (2.0beta1)");
  initialized = 1;

  ilu::EnterOTMu();
  exnstr.E1 = ilu::DefineException("Test1", "E1", "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW");
  exnstr.E2 = ilu::DefineException("Test1", "E2", "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY");
  exnstr.CantCreate = ilu::DefineException("Test1", "CantCreate", NULL);
  exnstr.E3 = ilu::DefineException("Test1", "E3", "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2");
  exnstr.E4 = ilu::DefineException("Test1", "E4", "ilut:fmBFu4mQpwjov+CekDxhjwxkgty");
  exnstr.E5 = ilu::DefineException("Test1", "E5", "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r");
  exnstr.E6 = ilu::DefineException("Test1", "E6", "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac");
  exnstr.E7 = ilu::DefineException("Test1", "E7", "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv");
  exnstr.E8 = ilu::DefineException("Test1", "E8", "ilut:h3Dnvis94UwnmFURfYsCp700jVy");
  exnstr.E9 = ilu::DefineException("Test1", "E9", "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7");
  {	// for definition of Test1_T_O4
    static ilu_CString Superclass_IDs[1] = {
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"
	};
    ilu_Class t;
    Test1_T_O4::ILUClassRecord = t = ilu::DefineObjectType(
	"Test1.O4",	/* ILU name */
	"",	/* Brand */
	"ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ",	/* id */
	NULL,	/* singleton */
	ilu_kernelFALSE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	1,	/* number of methods */
	1,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Test1_T_O4);
    {	//for method R-to-R
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"R-to-R",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP");	//return type
    }	//end method R-to-R
    ilu::ObjectTypeDefined(t);
  }	// end definition of Test1_T_O4
  {	// for definition of Test1_T_P
    static ilu_CString Superclass_IDs[1] = {
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"
	};
    ilu_Class t;
    Test1_T_P::ILUClassRecord = t = ilu::DefineObjectType(
	"Test1.P",	/* ILU name */
	"",	/* Brand */
	"ilut:dY9O+Pbe716S3dZTXTUzbvfKs87",	/* id */
	NULL,	/* singleton */
	ilu_kernelFALSE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	1,	/* number of methods */
	1,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Test1_T_P);
    {	//for method m2
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"m2",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO");	//return type
    }	//end method m2
    ilu::ObjectTypeDefined(t);
  }	// end definition of Test1_T_P
  {	// for definition of Test1_T_O3
    ilu_Class t;
    Test1_T_O3::ILUClassRecord = t = ilu::DefineObjectType(
	"Test1.O3",	/* ILU name */
	"v1",	/* Brand */
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU",	/* id */
	NULL,	/* singleton */
	ilu_kernelFALSE,	/* optional? */
	ilu_kernelTRUE,	/* collectible? */
	NULL,	/* authentication */
	3,	/* number of methods */
	0,	/* number of superclasses */
	NULL	/* no superclass uids */);
    iluObject::RegisterSurrogateCreator(t, Create_Test1_T_O3);
    {	//for method RS-R-to-R-IS
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"RS-R-to-R-IS",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO");	//return type
    }	//end method RS-R-to-R-IS
    {	//for method O1-U-to-U
      ilu_Exception exns[1];
      exns[0] = exnstr.E2;
      ilu::DefineMethod(t,
	1,	//method index
	"O1-U-to-U",	//name
	2,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	(ilu_CString) 0);	//return type
    }	//end method O1-U-to-U
    {	//for method BS-to-I
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	2,	//method index
	"BS-to-I",	//name
	3,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY");	//return type
    }	//end method BS-to-I
    ilu::ObjectTypeDefined(t);
  }	// end definition of Test1_T_O3
  {	// for definition of Test1_T_TheO1
    ilu_Class t;
    Test1_T_TheO1::ILUClassRecord = t = ilu::DefineObjectType(
	"Test1.TheO1",	/* ILU name */
	"",	/* Brand */
	"ilut:fmBFu4mQpwjov+CekDxhjwxkgty",	/* id */
	NULL,	/* singleton */
	ilu_kernelFALSE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	6,	/* number of methods */
	0,	/* number of superclasses */
	NULL	/* no superclass uids */);
    iluObject::RegisterSurrogateCreator(t, Create_Test1_T_TheO1);
    {	//for method U-CSS-to-U
      ilu_Exception exns[2];
      exns[0] = exnstr.E1;
      exns[1] = exnstr.E2;
      ilu::DefineMethod(t,
	0,	//method index
	"U-CSS-to-U",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	2,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW");	//return type
    }	//end method U-CSS-to-U
    {	//for method f-CSS-to-RO
      ilu_Exception exns[1];
      exns[0] = exnstr.E1;
      ilu::DefineMethod(t,
	1,	//method index
	"f-CSS-to-RO",	//name
	2,	//method ID
	ilu_kernelTRUE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2");	//return type
    }	//end method f-CSS-to-RO
    {	//for method R-ScS-to-F
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	2,	//method index
	"R-ScS-to-F",	//name
	3,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO");	//return type
    }	//end method R-ScS-to-F
    {	//for method a-RO
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	3,	//method index
	"a-RO",	//name
	4,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelTRUE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	(ilu_CString) 0);	//return type
    }	//end method a-RO
    {	//for method get-O2
      ilu_Exception exns[1];
      exns[0] = exnstr.CantCreate;
      ilu::DefineMethod(t,
	4,	//method index
	"get-O2",	//name
	5,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:jXB9BUoPU7650cspZmJCl3y4zzu");	//return type
    }	//end method get-O2
    {	//for method get-O3
      ilu_Exception exns[1];
      exns[0] = exnstr.CantCreate;
      ilu::DefineMethod(t,
	5,	//method index
	"get-O3",	//name
	6,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU");	//return type
    }	//end method get-O3
    ilu::ObjectTypeDefined(t);
  }	// end definition of Test1_T_TheO1
  {	// for definition of Test1_T_O2
    ilu_Class t;
    Test1_T_O2::ILUClassRecord = t = ilu::DefineObjectType(
	"Test1.O2",	/* ILU name */
	"",	/* Brand */
	"ilut:jXB9BUoPU7650cspZmJCl3y4zzu",	/* id */
	"sunrpc_2_0x3458_3",	/* singleton */
	ilu_kernelFALSE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	2,	/* number of methods */
	0,	/* number of superclasses */
	NULL	/* no superclass uids */);
    iluObject::RegisterSurrogateCreator(t, Create_Test1_T_O2);
    {	//for method OO-A0-to-CSS
      ilu_Exception exns[1];
      exns[0] = exnstr.E2;
      ilu::DefineMethod(t,
	0,	//method index
	"OO-A0-to-CSS",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy");	//return type
    }	//end method OO-A0-to-CSS
    {	//for method R-I-A1-to-I-A0
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	1,	//method index
	"R-I-A1-to-I-A0",	//name
	2,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	3,	//num. args
	"ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r");	//return type
    }	//end method R-I-A1-to-I-A0
    ilu::ObjectTypeDefined(t);
  }	// end definition of Test1_T_O2
  ilu::ExitOTMu();
}

_Test1_RegistrationClass::_Test1_RegistrationClass()
{
	Test1__Initialize();
}

