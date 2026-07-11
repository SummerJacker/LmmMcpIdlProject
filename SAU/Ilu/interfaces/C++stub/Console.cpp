/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:31:08 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Console.hh"

extern "C" {
#include <stdio.h>
#include <string.h>
};
static struct Console_Exceptions_s exnstr = {
	 (ilu_Exception) 0	//rpc-AlreadyBind(CORBA rep = "IDL:Console/rpc/AlreadyBind:1.0")
	,(ilu_Exception) 0	//rpc-NotFound(CORBA rep = "IDL:Console/rpc/NotFound:1.0")
};

struct Console_Exceptions_s * Console_G::Exceptions()
{
	return(&exnstr);
}

static void ConsoleCatchException (iluCall _call, ConsoleStatus *_val, ilu_Cardinal _ecode)
{
	if (_ecode > ilu_MethodOfCall(&_call->call)->me_exceptionCount || _ecode == 0) {
		_val->returnCode = ilu::ProtocolError;
		_val->values.anyvalue = (ilu_Cardinal) ilu_ProtocolException_Unknown;
	}
	else {
		_val->returnCode = ilu::ExceptionOfMethod(ilu_MethodOfCall(&_call->call), _ecode);
		if (_val->returnCode == NULL)
			return;


	}
	return;
}

#include <stdarg.h>

void Console_G::RaiseException (ConsoleStatus *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	return;
}

#include <stdarg.h>

int Console_G::SendException (iluCall _call, ConsoleStatus *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Console_G::SendException");
  _argSize = ilu::BeginSizingException(_call, eCode);
  if (stat->returnCode == NULL)
    0;	/* can't happen */
	if (!ilu::BeginException (_call, eCode, _argSize))
	  goto faild;
  if (stat->returnCode == NULL)
    0;	/* can't happen*/
  ilu::FinishException (_call);
faild:
  return(0);
}

void Console_G::Free_UnitInfoSeq (Unit_T_UnitInfoSeq _val)
{
	register Unit_T_UnitInfo *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Console_G::Output_TrapPointSeq (iluCall _call, Console_T_TrapPointSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Console_T_TrapPoint *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Console_G::Output_TrapPoint (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Console_T_TrapPointSeq Console_G::Input_TrapPointSeq (iluCall _call, Console_T_TrapPointSeq _ref)
{
	Console_T_TrapPointSeq _val;

	ilu_Cardinal _count, _index;
	Console_T_TrapPoint * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Console_T_TrapPointSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Console_G::Input_TrapPoint (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Console_G::SizeOf_TrapPointSeq (iluCall _call, Console_T_TrapPointSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Console_T_TrapPoint *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Console_G::SizeOf_TrapPoint (_call, (Console_T_TrapPoint *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Console_G::Free_TrapPointSeq (Console_T_TrapPointSeq _val)
{
	register Console_T_TrapPoint *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Console_G::Output_PointSeq (iluCall _call, Console_T_PointSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Console_T_Point *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Console_G::Output_Point (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Console_T_PointSeq Console_G::Input_PointSeq (iluCall _call, Console_T_PointSeq _ref)
{
	Console_T_PointSeq _val;

	ilu_Cardinal _count, _index;
	Console_T_Point * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Console_T_PointSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Console_G::Input_Point (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Console_G::SizeOf_PointSeq (iluCall _call, Console_T_PointSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Console_T_Point *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Console_G::SizeOf_Point (_call, (Console_T_Point *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Console_G::Free_PointSeq (Console_T_PointSeq _val)
{
	register Console_T_Point *data = _val->Array();

	free((char *) data);
}

void Console_G::Free_UnitInfoSeq (Unit_T_UnitInfoSeq _val)
{
	register Unit_T_UnitInfo *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Console_G::Output_Message (iluCall _call, Console_T_Message * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_Operation_OP_SetCosInfo:
	if (!Unit_G::Output_UnitInfoSeq (_call, _val->value.infoSeq))
	  goto faild;
	break;

	case Console_T_Operation_OP_Bind:
	if (!Unit_G::Output_UnitInfo (_call, &_val->value.bindInfo))
	  goto faild;
	break;

	case Console_T_Operation_OP_Unbind:
	if (!Console_G::Output_UnbindData (_call, &_val->value.unbindInfo))
	  goto faild;
	break;

	case Console_T_Operation_OP_ReportTrap:
	case Console_T_Operation_OP_AddTrap:
	if (!Console_G::Output_TrapPoint (_call, &_val->value.tp))
	  goto faild;
	break;

	case Console_T_Operation_OP_Opened:
	case Console_T_Operation_OP_Closed:
	if (!ilu::OutputString (_call, _val->value.details, strlen(_val->value.details), 0))
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

Console_T_Message * Console_G::Input_Message (iluCall _call, Console_T_Message * _ref)
{
	Console_T_Message * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Console_T_Message *) malloc(sizeof(Console_T_Message));
	switch (discriminator) {
	case Console_T_Operation_OP_SetCosInfo:
	_val->value.infoSeq = Unit_G::Input_UnitInfoSeq (_call, NULL);
	break;

	case Console_T_Operation_OP_Bind:
	Unit_G::Input_UnitInfo (_call, &_val->value.bindInfo);
	break;

	case Console_T_Operation_OP_Unbind:
	Console_G::Input_UnbindData (_call, &_val->value.unbindInfo);
	break;

	case Console_T_Operation_OP_ReportTrap:
	case Console_T_Operation_OP_AddTrap:
	Console_G::Input_TrapPoint (_call, &_val->value.tp);
	break;

	case Console_T_Operation_OP_Opened:
	case Console_T_Operation_OP_Closed:
	_val->value.details = ilu::InputString(_call, NULL, NULL, 0);
	break;

		default:
			break;
	}
	_val->discriminator = (Console_T_Operation) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Console_G::SizeOf_Message (iluCall _call, Console_T_Message * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_Operation_OP_SetCosInfo:
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfoSeq (_call, (Unit_T_UnitInfoSeq) _val->value.infoSeq));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Console_T_Operation_OP_Bind:
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) &_val->value.bindInfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Console_T_Operation_OP_Unbind:
	_argSize += (_dSize = Console_G::SizeOf_UnbindData (_call, (Console_T_UnbindData *) &_val->value.unbindInfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Console_T_Operation_OP_ReportTrap:
	case Console_T_Operation_OP_AddTrap:
	_argSize += (_dSize = Console_G::SizeOf_TrapPoint (_call, (Console_T_TrapPoint *) &_val->value.tp));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Console_T_Operation_OP_Opened:
	case Console_T_Operation_OP_Closed:
	_argSize += (_dSize = ilu::SizeOfString(_call, _val->value.details, strlen(_val->value.details), 0));
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

void Console_G::Free_Message (Console_T_Message * _val)
{
	switch (_val->discriminator) {
	case Console_T_Operation_OP_SetCosInfo:
	Unit_G::Free_UnitInfoSeq (_val->value.infoSeq);
		break;

	case Console_T_Operation_OP_Bind:
		break;

	case Console_T_Operation_OP_Unbind:
		break;

	case Console_T_Operation_OP_ReportTrap:
	case Console_T_Operation_OP_AddTrap:
		break;

	case Console_T_Operation_OP_Opened:
	case Console_T_Operation_OP_Closed:
		break;

		default:
			break;
	}
}

ilu_Boolean Console_G::Output_UnbindData (iluCall _call, Console_T_UnbindData * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputString (_call, (_val->uid), strlen((_val->uid)), 0))
	  goto faild;
	if (!ilu::OutputString (_call, (_val->details), strlen((_val->details)), 0))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Console_T_UnbindData * Console_G::Input_UnbindData (iluCall _call, Console_T_UnbindData * _ref)
{
	Console_T_UnbindData * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Console_T_UnbindData *) malloc(sizeof(Console_T_UnbindData));
	_val->uid = ilu::InputString(_call, NULL, NULL, 0);
	_val->details = ilu::InputString(_call, NULL, NULL, 0);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Console_G::SizeOf_UnbindData (iluCall _call, Console_T_UnbindData * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfString(_call, (_val->uid), strlen((_val->uid)), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, (_val->details), strlen((_val->details)), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Console_G::Output_TrapPoint (iluCall _call, Console_T_TrapPoint * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_TrapType_TrapGroundType:
	if (!Ground_Unit_G::Output_TrapPoint2D (_call, &_val->value.trapPoint2D))
	  goto faild;
	break;

	case Console_T_TrapType_TrapAirType:
	if (!Air_Unit_G::Output_TrapPoint3D (_call, &_val->value.trapPoint3D))
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

Console_T_TrapPoint * Console_G::Input_TrapPoint (iluCall _call, Console_T_TrapPoint * _ref)
{
	Console_T_TrapPoint * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Console_T_TrapPoint *) malloc(sizeof(Console_T_TrapPoint));
	switch (discriminator) {
	case Console_T_TrapType_TrapGroundType:
	Ground_Unit_G::Input_TrapPoint2D (_call, &_val->value.trapPoint2D);
	break;

	case Console_T_TrapType_TrapAirType:
	Air_Unit_G::Input_TrapPoint3D (_call, &_val->value.trapPoint3D);
	break;

		default:
			break;
	}
	_val->discriminator = (Console_T_TrapType) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Console_G::SizeOf_TrapPoint (iluCall _call, Console_T_TrapPoint * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_TrapType_TrapGroundType:
	_argSize += (_dSize = Ground_Unit_G::SizeOf_TrapPoint2D (_call, (Ground_Unit_T_TrapPoint2D *) &_val->value.trapPoint2D));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Console_T_TrapType_TrapAirType:
	_argSize += (_dSize = Air_Unit_G::SizeOf_TrapPoint3D (_call, (Air_Unit_T_TrapPoint3D *) &_val->value.trapPoint3D));
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

ilu_Boolean Console_G::Output_Point (iluCall _call, Console_T_Point * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_PointType_PointGroundType:
	if (!Ground_Unit_G::Output_Point2D (_call, &_val->value.p2D))
	  goto faild;
	break;

	case Console_T_PointType_PointAirType:
	if (!Air_Unit_G::Output_Point3D (_call, &_val->value.p3D))
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

Console_T_Point * Console_G::Input_Point (iluCall _call, Console_T_Point * _ref)
{
	Console_T_Point * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Console_T_Point *) malloc(sizeof(Console_T_Point));
	switch (discriminator) {
	case Console_T_PointType_PointGroundType:
	Ground_Unit_G::Input_Point2D (_call, &_val->value.p2D);
	break;

	case Console_T_PointType_PointAirType:
	Air_Unit_G::Input_Point3D (_call, &_val->value.p3D);
	break;

		default:
			break;
	}
	_val->discriminator = (Console_T_PointType) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Console_G::SizeOf_Point (iluCall _call, Console_T_Point * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_PointType_PointGroundType:
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Point2D (_call, (Ground_Unit_T_Point2D *) &_val->value.p2D));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Console_T_PointType_PointAirType:
	_argSize += (_dSize = Air_Unit_G::SizeOf_Point3D (_call, (Air_Unit_T_Point3D *) &_val->value.p3D));
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

ilu_Boolean Console_G::Output_MissionStateData (iluCall _call, Console_T_MissionStateData * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_MissionState_MissionSuspend:
	if (!ilu::OutputShortInteger(_call, (short int) _val->value.time))
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

Console_T_MissionStateData * Console_G::Input_MissionStateData (iluCall _call, Console_T_MissionStateData * _ref)
{
	Console_T_MissionStateData * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Console_T_MissionStateData *) malloc(sizeof(Console_T_MissionStateData));
	switch (discriminator) {
	case Console_T_MissionState_MissionSuspend:
	ilu::InputShortInteger (_call, &_val->value.time);
	break;

		default:
			break;
	}
	_val->discriminator = (Console_T_MissionState) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Console_G::SizeOf_MissionStateData (iluCall _call, Console_T_MissionStateData * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Console_T_MissionState_MissionSuspend:
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, _val->value.time));
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

_Console_T_TrapPointSeq_sequence::_Console_T_TrapPointSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Console_T_TrapPointSeq_sequence::~_Console_T_TrapPointSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Console_T_TrapPointSeq _Console_T_TrapPointSeq_sequence::Create (ilu_Cardinal initial_size, Console_T_TrapPoint *initial_data)
{
  Console_T_TrapPointSeq s = new _Console_T_TrapPointSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Console_T_TrapPoint *) malloc((unsigned int)(sizeof(Console_T_TrapPoint) * (s->_maximum = initial_size)));
  return s;
}

void _Console_T_TrapPointSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Console_T_TrapPoint *) 0;
  }
  _length = 0;
}

void _Console_T_TrapPointSeq_sequence::Append (Console_T_TrapPoint * item)
{
  if (_buffer == NULL) {
    _buffer = (Console_T_TrapPoint *) malloc ((unsigned int)(sizeof(Console_T_TrapPoint) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Console_T_TrapPoint *) realloc ((char *) _buffer, (unsigned int)(sizeof(Console_T_TrapPoint) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Console_T_TrapPoint * _Console_T_TrapPointSeq_sequence::RemoveHead ()
{
  static Console_T_TrapPoint k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Console_T_TrapPoint)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Console_T_TrapPoint *) 0);
}

Console_T_TrapPoint * _Console_T_TrapPointSeq_sequence::RemoveTail ()
{
  static Console_T_TrapPoint k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Console_T_TrapPoint *) 0);
}

ilu_Cardinal _Console_T_TrapPointSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Console_T_TrapPoint *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Console_T_TrapPoint)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Console_T_TrapPoint * _Console_T_TrapPointSeq_sequence::Find (ilu_Boolean (*matchproc)(Console_T_TrapPoint *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Console_T_TrapPoint *) 0);
}

void _Console_T_TrapPointSeq_sequence::Enumerate (void (*enumproc)(Console_T_TrapPoint *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Console_T_TrapPointSeq_sequence::Length ()
{
  return _length;
}

Console_T_TrapPoint * _Console_T_TrapPointSeq_sequence::Array ()
{
  return _buffer;
}

Console_T_TrapPoint * _Console_T_TrapPointSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Console_T_TrapPoint *) 0);
}

_Console_T_PointSeq_sequence::_Console_T_PointSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Console_T_PointSeq_sequence::~_Console_T_PointSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Console_T_PointSeq _Console_T_PointSeq_sequence::Create (ilu_Cardinal initial_size, Console_T_Point *initial_data)
{
  Console_T_PointSeq s = new _Console_T_PointSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Console_T_Point *) malloc((unsigned int)(sizeof(Console_T_Point) * (s->_maximum = initial_size)));
  return s;
}

void _Console_T_PointSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Console_T_Point *) 0;
  }
  _length = 0;
}

void _Console_T_PointSeq_sequence::Append (Console_T_Point * item)
{
  if (_buffer == NULL) {
    _buffer = (Console_T_Point *) malloc ((unsigned int)(sizeof(Console_T_Point) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Console_T_Point *) realloc ((char *) _buffer, (unsigned int)(sizeof(Console_T_Point) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Console_T_Point * _Console_T_PointSeq_sequence::RemoveHead ()
{
  static Console_T_Point k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Console_T_Point)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Console_T_Point *) 0);
}

Console_T_Point * _Console_T_PointSeq_sequence::RemoveTail ()
{
  static Console_T_Point k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Console_T_Point *) 0);
}

ilu_Cardinal _Console_T_PointSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Console_T_Point *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Console_T_Point)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Console_T_Point * _Console_T_PointSeq_sequence::Find (ilu_Boolean (*matchproc)(Console_T_Point *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Console_T_Point *) 0);
}

void _Console_T_PointSeq_sequence::Enumerate (void (*enumproc)(Console_T_Point *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Console_T_PointSeq_sequence::Length ()
{
  return _length;
}

Console_T_Point * _Console_T_PointSeq_sequence::Array ()
{
  return _buffer;
}

Console_T_Point * _Console_T_PointSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Console_T_Point *) 0);
}

ilu_Class Console_T_rpc::ILUClassRecord = NULL;

#define MethodRecord_Console_T_rpc_getCosNamingInfo ((Console_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Console_T_rpc_sendMsg ((Console_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Console_T_rpc_bind ((Console_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Console_T_rpc_unbind ((Console_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Console_T_rpc_rebind ((Console_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Console_T_rpc_setNickname ((Console_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Console_T_rpc_setPosition ((Console_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Console_T_rpc_addGoalPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Console_T_rpc_setGoalPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Console_T_rpc_setRole ((Console_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Console_T_rpc_cancelRole ((Console_T_rpc::ILUClassRecord)->cl_methods + 10)
#define MethodRecord_Console_T_rpc_setTrapPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 11)
#define MethodRecord_Console_T_rpc_setFollow ((Console_T_rpc::ILUClassRecord)->cl_methods + 12)
#define MethodRecord_Console_T_rpc_setFormationType ((Console_T_rpc::ILUClassRecord)->cl_methods + 13)
#define MethodRecord_Console_T_rpc_setTrackMode ((Console_T_rpc::ILUClassRecord)->cl_methods + 14)
#define MethodRecord_Console_T_rpc_getCurrentUnit ((Console_T_rpc::ILUClassRecord)->cl_methods + 15)
#define MethodRecord_Console_T_rpc_getUnitNum ((Console_T_rpc::ILUClassRecord)->cl_methods + 16)
#define MethodRecord_Console_T_rpc_getFormationNum ((Console_T_rpc::ILUClassRecord)->cl_methods + 17)
#define MethodRecord_Console_T_rpc_getTrapNum ((Console_T_rpc::ILUClassRecord)->cl_methods + 18)
#define MethodRecord_Console_T_rpc_getFormationType ((Console_T_rpc::ILUClassRecord)->cl_methods + 19)
#define MethodRecord_Console_T_rpc_getFormationState ((Console_T_rpc::ILUClassRecord)->cl_methods + 20)
#define MethodRecord_Console_T_rpc_getMissionState ((Console_T_rpc::ILUClassRecord)->cl_methods + 21)
#define MethodRecord_Console_T_rpc_getUnitPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 22)
#define MethodRecord_Console_T_rpc_getByName ((Console_T_rpc::ILUClassRecord)->cl_methods + 23)
#define MethodRecord_Console_T_rpc_getLeaderPoint ((Console_T_rpc::ILUClassRecord)->cl_methods + 24)
#define MethodRecord_Console_T_rpc_getPointSeq ((Console_T_rpc::ILUClassRecord)->cl_methods + 25)
#define MethodRecord_Console_T_rpc_cancelFormation ((Console_T_rpc::ILUClassRecord)->cl_methods + 26)
#define MethodRecord_Console_T_rpc_setLeaderSuspend ((Console_T_rpc::ILUClassRecord)->cl_methods + 27)
#define MethodRecord_Console_T_rpc_recoveryLeaderAction ((Console_T_rpc::ILUClassRecord)->cl_methods + 28)
#define MethodRecord_Console_T_rpc_addUnitFormation ((Console_T_rpc::ILUClassRecord)->cl_methods + 29)
#define MethodRecord_Console_T_rpc_deleteUnitFormation ((Console_T_rpc::ILUClassRecord)->cl_methods + 30)
#define MethodRecord_Console_T_rpc_setUnitFault ((Console_T_rpc::ILUClassRecord)->cl_methods + 31)
#define MethodRecord_Console_T_rpc_setUnitFaultPosition ((Console_T_rpc::ILUClassRecord)->cl_methods + 32)
#define MethodRecord_Console_T_rpc_setFormationState ((Console_T_rpc::ILUClassRecord)->cl_methods + 33)
#define MethodRecord_Console_T_rpc_setMissionState ((Console_T_rpc::ILUClassRecord)->cl_methods + 34)

class Console_T_rpc * Console_T_rpc::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Console_T_rpc *) ilu::SBHToObject(sbh, Console_T_rpc::ILUClassRecord);
}

class Console_T_rpc * Console_T_rpc::ILUQuaT (class iluObject *from)
{
	return((class Console_T_rpc *) (from->ILUCastDown (Console_T_rpc::ILUClassRecord)));
}

void * Console_T_rpc::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Console_T_rpc::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == ilu_T_CORBA_Object::ILUClassRecord)
		return ((void *)((class ilu_T_CORBA_Object *) this));
	else return (NULL);
}

Console_T_rpc::Console_T_rpc ()
{
	this->ILUInstanceClassRecord = Console_T_rpc::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Console_T_rpc::~Console_T_rpc ()
{
}

Unit_T_UnitInfoSeq Console_T_rpc::getCosNamingInfo (ConsoleStatus *_status)
{
	Unit_T_UnitInfoSeq _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getCosNamingInfo))
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
		_retvalue = Unit_G::Input_UnitInfoSeq (_call, NULL);
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

ilu_Boolean Console_T_rpc::sendMsg (ConsoleStatus *_status, Console_T_Message * m)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_sendMsg))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Console_G::SizeOf_Message (_call, (Console_T_Message *) m));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Console_G::Output_Message (_call, m))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::bind (ConsoleStatus *_status, Unit_T_UnitID uid, Unit_T_UnitSBH sbh)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_bind))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, uid, strlen(uid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, sbh, strlen(sbh), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, uid, strlen(uid), 0))
	  goto faild;
	if (!ilu::OutputString (_call, sbh, strlen(sbh), 0))
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
		ilu::InputBoolean (_call, &_retvalue);
	}
	else
		ConsoleCatchException (_call, _status, _scode);
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

ilu_Boolean Console_T_rpc::unbind (ConsoleStatus *_status, Unit_T_UnitID uid, ilu_T_CString details)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_unbind))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, uid, strlen(uid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, details, strlen(details), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, uid, strlen(uid), 0))
	  goto faild;
	if (!ilu::OutputString (_call, details, strlen(details), 0))
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
		ilu::InputBoolean (_call, &_retvalue);
	}
	else
		ConsoleCatchException (_call, _status, _scode);
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

ilu_Boolean Console_T_rpc::rebind (ConsoleStatus *_status, Unit_T_UnitID uid, Unit_T_UnitSBH sbh)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_rebind))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, uid, strlen(uid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, sbh, strlen(sbh), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, uid, strlen(uid), 0))
	  goto faild;
	if (!ilu::OutputString (_call, sbh, strlen(sbh), 0))
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
		ilu::InputBoolean (_call, &_retvalue);
	}
	else
		ConsoleCatchException (_call, _status, _scode);
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

ilu_Boolean Console_T_rpc::setNickname (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo, ilu_T_CString newName)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setNickname))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, newName, strlen(newName), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo))
	  goto faild;
	if (!ilu::OutputString (_call, newName, strlen(newName), 0))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setPosition (ConsoleStatus *_status, ilu_T_CString name, Console_T_Point * p)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setPosition))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, name, strlen(name), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Console_G::SizeOf_Point (_call, (Console_T_Point *) p));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, name, strlen(name), 0))
	  goto faild;
	if (!Console_G::Output_Point (_call, p))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::addGoalPoint (ConsoleStatus *_status, Console_T_Point * p)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_addGoalPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Console_G::SizeOf_Point (_call, (Console_T_Point *) p));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Console_G::Output_Point (_call, p))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setGoalPoint (ConsoleStatus *_status, Console_T_Point * p)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setGoalPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Console_G::SizeOf_Point (_call, (Console_T_Point *) p));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Console_G::Output_Point (_call, p))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setRole (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo, Unit_T_UnitRole r)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setRole))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) r));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) r))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::cancelRole (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_cancelRole))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setTrapPoint (ConsoleStatus *_status, Console_T_TrapPoint * p)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setTrapPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Console_G::SizeOf_TrapPoint (_call, (Console_T_TrapPoint *) p));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Console_G::Output_TrapPoint (_call, p))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setFollow (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo1, Unit_T_UnitInfo * uinfo2)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setFollow))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo1));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo2));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo1))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo2))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setFormationType (ConsoleStatus *_status, Console_T_FormationType f)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setFormationType))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) f));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) f))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setTrackMode (ConsoleStatus *_status, Console_T_TrackMode tm)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setTrackMode))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) tm));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) tm))
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
		ilu::InputBoolean (_call, &_retvalue);
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

Unit_T_UnitInfo * Console_T_rpc::getCurrentUnit (ConsoleStatus *_status)
{
	Unit_T_UnitInfo * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getCurrentUnit))
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
		_retvalue = Unit_G::Input_UnitInfo (_call, NULL);
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

ilu_ShortInteger Console_T_rpc::getUnitNum (ConsoleStatus *_status)
{
	ilu_ShortInteger _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getUnitNum))
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
		ilu::InputShortInteger (_call, &_retvalue);
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

ilu_ShortInteger Console_T_rpc::getFormationNum (ConsoleStatus *_status)
{
	ilu_ShortInteger _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getFormationNum))
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
		ilu::InputShortInteger (_call, &_retvalue);
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

ilu_ShortInteger Console_T_rpc::getTrapNum (ConsoleStatus *_status)
{
	ilu_ShortInteger _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getTrapNum))
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
		ilu::InputShortInteger (_call, &_retvalue);
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

Console_T_FormationType Console_T_rpc::getFormationType (ConsoleStatus *_status)
{
	Console_T_FormationType _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getFormationType))
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
		{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  _retvalue = (Console_T_FormationType) _index; };
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

Console_T_FormationState Console_T_rpc::getFormationState (ConsoleStatus *_status)
{
	Console_T_FormationState _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getFormationState))
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
		{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  _retvalue = (Console_T_FormationState) _index; };
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

Console_T_MissionState Console_T_rpc::getMissionState (ConsoleStatus *_status)
{
	Console_T_MissionState _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getMissionState))
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
		{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  _retvalue = (Console_T_MissionState) _index; };
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

Console_T_Point * Console_T_rpc::getUnitPoint (ConsoleStatus *_status, ilu_T_CString name)
{
	Console_T_Point * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getUnitPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, name, strlen(name), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, name, strlen(name), 0))
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
		_retvalue = Console_G::Input_Point (_call, NULL);
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

Unit_T_UnitInfo * Console_T_rpc::getByName (ConsoleStatus *_status, ilu_T_CString name)
{
	Unit_T_UnitInfo * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getByName))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, name, strlen(name), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, name, strlen(name), 0))
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
		_retvalue = Unit_G::Input_UnitInfo (_call, NULL);
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

Console_T_Point * Console_T_rpc::getLeaderPoint (ConsoleStatus *_status)
{
	Console_T_Point * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getLeaderPoint))
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
		_retvalue = Console_G::Input_Point (_call, NULL);
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

Console_T_PointSeq Console_T_rpc::getPointSeq (ConsoleStatus *_status)
{
	Console_T_PointSeq _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_getPointSeq))
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
		_retvalue = Console_G::Input_PointSeq (_call, NULL);
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

ilu_Boolean Console_T_rpc::cancelFormation (ConsoleStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_cancelFormation))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setLeaderSuspend (ConsoleStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setLeaderSuspend))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::recoveryLeaderAction (ConsoleStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_recoveryLeaderAction))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::addUnitFormation (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_addUnitFormation))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::deleteUnitFormation (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_deleteUnitFormation))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setUnitFault (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setUnitFault))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setUnitFaultPosition (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setUnitFaultPosition))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) uinfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, uinfo))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setFormationState (ConsoleStatus *_status, Console_T_FormationState fs)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setFormationState))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) fs));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) fs))
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
		ilu::InputBoolean (_call, &_retvalue);
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

ilu_Boolean Console_T_rpc::setMissionState (ConsoleStatus *_status, Console_T_MissionStateData * msd)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Console_T_rpc::ILUClassRecord, MethodRecord_Console_T_rpc_setMissionState))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Console_G::SizeOf_MissionStateData (_call, (Console_T_MissionStateData *) msd));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Console_G::Output_MissionStateData (_call, msd))
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
		ilu::InputBoolean (_call, &_retvalue);
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

static class iluObject * Create_Console_T_rpc(ilu_KernelObject obj) {
	class Console_T_rpc *nobj = new Console_T_rpc;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Console_RegistrationClass {

 public:

  _Console_RegistrationClass();
};

#ifndef macintosh
static class _Console_RegistrationClass _Console_RegistrationInstance;
#endif

void Console__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Console", "2.0beta1", "v2 (2.0beta1)");
  initialized = 1;

  ilu::EnterOTMu();
  exnstr.rpc_AlreadyBind = ilu::DefineException(NULL, "IDL:Console/rpc/AlreadyBind:1.0", NULL);
  exnstr.rpc_NotFound = ilu::DefineException(NULL, "IDL:Console/rpc/NotFound:1.0", NULL);
  {	// for definition of Console_T_rpc
    static ilu_CString Superclass_IDs[1] = {
	"IDL:omg.org/CORBA/Object:1.0"
	};
    ilu_Class t;
    Console_T_rpc::ILUClassRecord = t = ilu::DefineObjectType(
	"Console.rpc",	/* ILU name */
	"",	/* Brand */
	"IDL:Console/rpc:1.0",	/* id */
	NULL,	/* singleton */
	ilu_kernelTRUE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	35,	/* number of methods */
	1,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Console_T_rpc);
    {	//for method getCosNamingInfo
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"getCosNamingInfo",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:nulfTSjgo17mBovMLQKbwxXk7V-");	//return type
    }	//end method getCosNamingInfo
    {	//for method sendMsg
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	1,	//method index
	"sendMsg",	//name
	2,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendMsg
    {	//for method bind
      ilu_Exception exns[1];
      exns[0] = exnstr.rpc_AlreadyBind;
      ilu::DefineMethod(t,
	2,	//method index
	"bind",	//name
	3,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method bind
    {	//for method unbind
      ilu_Exception exns[1];
      exns[0] = exnstr.rpc_NotFound;
      ilu::DefineMethod(t,
	3,	//method index
	"unbind",	//name
	4,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method unbind
    {	//for method rebind
      ilu_Exception exns[1];
      exns[0] = exnstr.rpc_NotFound;
      ilu::DefineMethod(t,
	4,	//method index
	"rebind",	//name
	5,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	1,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method rebind
    {	//for method setNickname
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	5,	//method index
	"setNickname",	//name
	6,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setNickname
    {	//for method setPosition
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	6,	//method index
	"setPosition",	//name
	7,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setPosition
    {	//for method addGoalPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	7,	//method index
	"addGoalPoint",	//name
	8,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method addGoalPoint
    {	//for method setGoalPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	8,	//method index
	"setGoalPoint",	//name
	9,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setGoalPoint
    {	//for method setRole
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	9,	//method index
	"setRole",	//name
	10,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setRole
    {	//for method cancelRole
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	10,	//method index
	"cancelRole",	//name
	11,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method cancelRole
    {	//for method setTrapPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	11,	//method index
	"setTrapPoint",	//name
	12,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setTrapPoint
    {	//for method setFollow
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	12,	//method index
	"setFollow",	//name
	13,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setFollow
    {	//for method setFormationType
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	13,	//method index
	"setFormationType",	//name
	14,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setFormationType
    {	//for method setTrackMode
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	14,	//method index
	"setTrackMode",	//name
	15,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setTrackMode
    {	//for method getCurrentUnit
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	15,	//method index
	"getCurrentUnit",	//name
	16,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Unit/UnitInfo:1.0");	//return type
    }	//end method getCurrentUnit
    {	//for method getUnitNum
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	16,	//method index
	"getUnitNum",	//name
	17,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ");	//return type
    }	//end method getUnitNum
    {	//for method getFormationNum
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	17,	//method index
	"getFormationNum",	//name
	18,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ");	//return type
    }	//end method getFormationNum
    {	//for method getTrapNum
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	18,	//method index
	"getTrapNum",	//name
	19,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ");	//return type
    }	//end method getTrapNum
    {	//for method getFormationType
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	19,	//method index
	"getFormationType",	//name
	20,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Console/FormationType:1.0");	//return type
    }	//end method getFormationType
    {	//for method getFormationState
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	20,	//method index
	"getFormationState",	//name
	21,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Console/FormationState:1.0");	//return type
    }	//end method getFormationState
    {	//for method getMissionState
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	21,	//method index
	"getMissionState",	//name
	22,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Console/MissionState:1.0");	//return type
    }	//end method getMissionState
    {	//for method getUnitPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	22,	//method index
	"getUnitPoint",	//name
	23,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"IDL:Console/Point:1.0");	//return type
    }	//end method getUnitPoint
    {	//for method getByName
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	23,	//method index
	"getByName",	//name
	24,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"IDL:Unit/UnitInfo:1.0");	//return type
    }	//end method getByName
    {	//for method getLeaderPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	24,	//method index
	"getLeaderPoint",	//name
	25,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Console/Point:1.0");	//return type
    }	//end method getLeaderPoint
    {	//for method getPointSeq
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	25,	//method index
	"getPointSeq",	//name
	26,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:gj5QlY2dALbZCLSEKoPy7Ke-T8C");	//return type
    }	//end method getPointSeq
    {	//for method cancelFormation
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	26,	//method index
	"cancelFormation",	//name
	27,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method cancelFormation
    {	//for method setLeaderSuspend
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	27,	//method index
	"setLeaderSuspend",	//name
	28,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setLeaderSuspend
    {	//for method recoveryLeaderAction
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	28,	//method index
	"recoveryLeaderAction",	//name
	29,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method recoveryLeaderAction
    {	//for method addUnitFormation
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	29,	//method index
	"addUnitFormation",	//name
	30,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method addUnitFormation
    {	//for method deleteUnitFormation
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	30,	//method index
	"deleteUnitFormation",	//name
	31,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method deleteUnitFormation
    {	//for method setUnitFault
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	31,	//method index
	"setUnitFault",	//name
	32,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setUnitFault
    {	//for method setUnitFaultPosition
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	32,	//method index
	"setUnitFaultPosition",	//name
	33,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setUnitFaultPosition
    {	//for method setFormationState
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	33,	//method index
	"setFormationState",	//name
	34,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setFormationState
    {	//for method setMissionState
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	34,	//method index
	"setMissionState",	//name
	35,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setMissionState
    ilu::ObjectTypeDefined(t);
  }	// end definition of Console_T_rpc
  ilu::ExitOTMu();
}

_Console_RegistrationClass::_Console_RegistrationClass()
{
	Console__Initialize();
}

