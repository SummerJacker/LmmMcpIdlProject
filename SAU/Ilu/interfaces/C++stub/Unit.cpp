/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:31:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Unit.hh"

extern "C" {
#include <stdio.h>
#include <string.h>
};
static void UnitCatchException (iluCall _call, UnitStatus *_val, ilu_Cardinal _ecode)
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

void Unit_G::RaiseException (UnitStatus *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	return;
}

#include <stdarg.h>

int Unit_G::SendException (iluCall _call, UnitStatus *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Unit_G::SendException");
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

ilu_Boolean Unit_G::Output_Formation (iluCall _call, Unit_T_Formation * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Unit_G::Output_UnitIDSeq (_call, (_val->robot_ids)))
	  goto faild;
	if (!Unit_G::Output_ShortSeq (_call, (_val->leader_ids)))
	  goto faild;
	if (!Unit_G::Output_FloatSeq (_call, (_val->distances)))
	  goto faild;
	if (!Unit_G::Output_FloatSeq (_call, (_val->angles)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Unit_T_Formation * Unit_G::Input_Formation (iluCall _call, Unit_T_Formation * _ref)
{
	Unit_T_Formation * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Unit_T_Formation *) malloc(sizeof(Unit_T_Formation));
	_val->robot_ids = Unit_G::Input_UnitIDSeq (_call, NULL);
	_val->leader_ids = Unit_G::Input_ShortSeq (_call, NULL);
	_val->distances = Unit_G::Input_FloatSeq (_call, NULL);
	_val->angles = Unit_G::Input_FloatSeq (_call, NULL);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_Formation (iluCall _call, Unit_T_Formation * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Unit_G::SizeOf_UnitIDSeq (_call, (Unit_T_UnitIDSeq) (_val->robot_ids)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_ShortSeq (_call, (Unit_T_ShortSeq) (_val->leader_ids)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_FloatSeq (_call, (Unit_T_FloatSeq) (_val->distances)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_FloatSeq (_call, (Unit_T_FloatSeq) (_val->angles)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

void Unit_G::Free_Formation (Unit_T_Formation * _val)
{
	Unit_G::Free_UnitIDSeq (_val->robot_ids);
	Unit_G::Free_ShortSeq (_val->leader_ids);
	Unit_G::Free_FloatSeq (_val->distances);
	Unit_G::Free_FloatSeq (_val->angles);
}

ilu_Boolean Unit_G::Output_UnitInfoSeq (iluCall _call, Unit_T_UnitInfoSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Unit_T_UnitInfo *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Unit_G::Output_UnitInfo (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Unit_T_UnitInfoSeq Unit_G::Input_UnitInfoSeq (iluCall _call, Unit_T_UnitInfoSeq _ref)
{
	Unit_T_UnitInfoSeq _val;

	ilu_Cardinal _count, _index;
	Unit_T_UnitInfo * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Unit_T_UnitInfoSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Unit_G::Input_UnitInfo (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_UnitInfoSeq (iluCall _call, Unit_T_UnitInfoSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Unit_T_UnitInfo *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Unit_G::Free_UnitInfoSeq (Unit_T_UnitInfoSeq _val)
{
	register Unit_T_UnitInfo *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Unit_G::Output_UnitInfo (iluCall _call, Unit_T_UnitInfo * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputString (_call, (_val->uid), strlen((_val->uid)), 0))
	  goto faild;
	if (!ilu::OutputString (_call, (_val->sbh), strlen((_val->sbh)), 0))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Unit_T_UnitInfo * Unit_G::Input_UnitInfo (iluCall _call, Unit_T_UnitInfo * _ref)
{
	Unit_T_UnitInfo * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Unit_T_UnitInfo *) malloc(sizeof(Unit_T_UnitInfo));
	_val->uid = ilu::InputString(_call, NULL, NULL, 0);
	_val->sbh = ilu::InputString(_call, NULL, NULL, 0);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_UnitInfo (iluCall _call, Unit_T_UnitInfo * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfString(_call, (_val->uid), strlen((_val->uid)), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, (_val->sbh), strlen((_val->sbh)), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Unit_G::Output_ActionSeq (iluCall _call, Unit_T_ActionSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Unit_T_MoveAction *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Unit_G::Output_MoveAction (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Unit_T_ActionSeq Unit_G::Input_ActionSeq (iluCall _call, Unit_T_ActionSeq _ref)
{
	Unit_T_ActionSeq _val;

	ilu_Cardinal _count, _index;
	Unit_T_MoveAction * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Unit_T_ActionSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Unit_G::Input_MoveAction (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_ActionSeq (iluCall _call, Unit_T_ActionSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Unit_T_MoveAction *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Unit_G::SizeOf_MoveAction (_call, (Unit_T_MoveAction *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Unit_G::Free_ActionSeq (Unit_T_ActionSeq _val)
{
	register Unit_T_MoveAction *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Unit_G::Output_MoveAction (iluCall _call, Unit_T_MoveAction * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Unit_T_MoveActionType_MA_GoUp:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.goUpData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_GoDown:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.goDownData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_GoAhead:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.goAheadData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_GoBackward:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.goBackwardData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_GoLeft:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.goLeftData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_GoRight:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.goRightData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_TurnLeft:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.turnLeftData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_TurnRight:
	if (!Unit_G::Output_BasicMoveActionData (_call, &_val->value.turnRightData))
	  goto faild;
	break;

	case Unit_T_MoveActionType_MA_Stop:
	if (!Unit_G::Output_ActionDuration (_call, &_val->value.stopData))
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

Unit_T_MoveAction * Unit_G::Input_MoveAction (iluCall _call, Unit_T_MoveAction * _ref)
{
	Unit_T_MoveAction * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Unit_T_MoveAction *) malloc(sizeof(Unit_T_MoveAction));
	switch (discriminator) {
	case Unit_T_MoveActionType_MA_GoUp:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.goUpData);
	break;

	case Unit_T_MoveActionType_MA_GoDown:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.goDownData);
	break;

	case Unit_T_MoveActionType_MA_GoAhead:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.goAheadData);
	break;

	case Unit_T_MoveActionType_MA_GoBackward:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.goBackwardData);
	break;

	case Unit_T_MoveActionType_MA_GoLeft:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.goLeftData);
	break;

	case Unit_T_MoveActionType_MA_GoRight:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.goRightData);
	break;

	case Unit_T_MoveActionType_MA_TurnLeft:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.turnLeftData);
	break;

	case Unit_T_MoveActionType_MA_TurnRight:
	Unit_G::Input_BasicMoveActionData (_call, &_val->value.turnRightData);
	break;

	case Unit_T_MoveActionType_MA_Stop:
	Unit_G::Input_ActionDuration (_call, &_val->value.stopData);
	break;

		default:
			break;
	}
	_val->discriminator = (Unit_T_MoveActionType) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_MoveAction (iluCall _call, Unit_T_MoveAction * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Unit_T_MoveActionType_MA_GoUp:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.goUpData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_GoDown:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.goDownData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_GoAhead:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.goAheadData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_GoBackward:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.goBackwardData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_GoLeft:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.goLeftData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_GoRight:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.goRightData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_TurnLeft:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.turnLeftData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_TurnRight:
	_argSize += (_dSize = Unit_G::SizeOf_BasicMoveActionData (_call, (Unit_T_BasicMoveActionData *) &_val->value.turnRightData));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Unit_T_MoveActionType_MA_Stop:
	_argSize += (_dSize = Unit_G::SizeOf_ActionDuration (_call, (Unit_T_ActionDuration *) &_val->value.stopData));
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

ilu_Boolean Unit_G::Output_BasicMoveActionData (iluCall _call, Unit_T_BasicMoveActionData * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->speed)))
	  goto faild;
	if (!Unit_G::Output_ActionDuration (_call, (&_val->duration)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Unit_T_BasicMoveActionData * Unit_G::Input_BasicMoveActionData (iluCall _call, Unit_T_BasicMoveActionData * _ref)
{
	Unit_T_BasicMoveActionData * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Unit_T_BasicMoveActionData *) malloc(sizeof(Unit_T_BasicMoveActionData));
	ilu::InputShortReal (_call, &_val->speed);
	Unit_G::Input_ActionDuration (_call, &_val->duration);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_BasicMoveActionData (iluCall _call, Unit_T_BasicMoveActionData * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->speed)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_ActionDuration (_call, (Unit_T_ActionDuration *) (&_val->duration)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Unit_G::Output_ActionDuration (iluCall _call, Unit_T_ActionDuration * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputBoolean(_call, (ilu_Boolean) (_val->keep)))
	  goto faild;
	if (!ilu::OutputCardinal(_call, (ilu_Cardinal) (_val->ft_s)))
	  goto faild;
	if (!ilu::OutputCardinal(_call, (ilu_Cardinal) (_val->ft_t)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Unit_T_ActionDuration * Unit_G::Input_ActionDuration (iluCall _call, Unit_T_ActionDuration * _ref)
{
	Unit_T_ActionDuration * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Unit_T_ActionDuration *) malloc(sizeof(Unit_T_ActionDuration));
	ilu::InputBoolean (_call, &_val->keep);
	ilu::InputCardinal (_call, &_val->ft_s);
	ilu::InputCardinal (_call, &_val->ft_t);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_ActionDuration (iluCall _call, Unit_T_ActionDuration * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfBoolean(_call, (_val->keep)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfCardinal(_call, (_val->ft_s)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfCardinal(_call, (_val->ft_t)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Unit_G::Output_FloatSeq (iluCall _call, Unit_T_FloatSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	ilu_ShortReal *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!ilu::OutputShortReal(_call, (float) data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Unit_T_FloatSeq Unit_G::Input_FloatSeq (iluCall _call, Unit_T_FloatSeq _ref)
{
	Unit_T_FloatSeq _val;

	ilu_Cardinal _count, _index;
	ilu_ShortReal _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Unit_T_FloatSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		ilu::InputShortReal (_call, &_tmp);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_FloatSeq (iluCall _call, Unit_T_FloatSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register ilu_ShortReal *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Unit_G::Free_FloatSeq (Unit_T_FloatSeq _val)
{
	register ilu_ShortReal *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Unit_G::Output_ShortSeq (iluCall _call, Unit_T_ShortSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	ilu_ShortInteger *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!ilu::OutputShortInteger(_call, (short int) data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Unit_T_ShortSeq Unit_G::Input_ShortSeq (iluCall _call, Unit_T_ShortSeq _ref)
{
	Unit_T_ShortSeq _val;

	ilu_Cardinal _count, _index;
	ilu_ShortInteger _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Unit_T_ShortSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		ilu::InputShortInteger (_call, &_tmp);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_ShortSeq (iluCall _call, Unit_T_ShortSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register ilu_ShortInteger *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Unit_G::Free_ShortSeq (Unit_T_ShortSeq _val)
{
	register ilu_ShortInteger *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Unit_G::Output_UnitSBHSeq (iluCall _call, Unit_T_UnitSBHSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Unit_T_UnitSBH *data = _val->Array();
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

Unit_T_UnitSBHSeq Unit_G::Input_UnitSBHSeq (iluCall _call, Unit_T_UnitSBHSeq _ref)
{
	Unit_T_UnitSBHSeq _val;

	ilu_Cardinal _count, _index;
	Unit_T_UnitSBH _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Unit_T_UnitSBHSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = ilu::InputString(_call, NULL, NULL, 0);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_UnitSBHSeq (iluCall _call, Unit_T_UnitSBHSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Unit_T_UnitSBH *data = _val->Array();
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

void Unit_G::Free_UnitSBHSeq (Unit_T_UnitSBHSeq _val)
{
	register Unit_T_UnitSBH *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Unit_G::Output_UnitIDSeq (iluCall _call, Unit_T_UnitIDSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Unit_T_UnitID *data = _val->Array();
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

Unit_T_UnitIDSeq Unit_G::Input_UnitIDSeq (iluCall _call, Unit_T_UnitIDSeq _ref)
{
	Unit_T_UnitIDSeq _val;

	ilu_Cardinal _count, _index;
	Unit_T_UnitID _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Unit_T_UnitIDSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = ilu::InputString(_call, NULL, NULL, 0);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Unit_G::SizeOf_UnitIDSeq (iluCall _call, Unit_T_UnitIDSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Unit_T_UnitID *data = _val->Array();
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

void Unit_G::Free_UnitIDSeq (Unit_T_UnitIDSeq _val)
{
	register Unit_T_UnitID *data = _val->Array();

	free((char *) data);
}

_Unit_T_UnitInfoSeq_sequence::_Unit_T_UnitInfoSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Unit_T_UnitInfoSeq_sequence::~_Unit_T_UnitInfoSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Unit_T_UnitInfoSeq _Unit_T_UnitInfoSeq_sequence::Create (ilu_Cardinal initial_size, Unit_T_UnitInfo *initial_data)
{
  Unit_T_UnitInfoSeq s = new _Unit_T_UnitInfoSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Unit_T_UnitInfo *) malloc((unsigned int)(sizeof(Unit_T_UnitInfo) * (s->_maximum = initial_size)));
  return s;
}

void _Unit_T_UnitInfoSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Unit_T_UnitInfo *) 0;
  }
  _length = 0;
}

void _Unit_T_UnitInfoSeq_sequence::Append (Unit_T_UnitInfo * item)
{
  if (_buffer == NULL) {
    _buffer = (Unit_T_UnitInfo *) malloc ((unsigned int)(sizeof(Unit_T_UnitInfo) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Unit_T_UnitInfo *) realloc ((char *) _buffer, (unsigned int)(sizeof(Unit_T_UnitInfo) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Unit_T_UnitInfo * _Unit_T_UnitInfoSeq_sequence::RemoveHead ()
{
  static Unit_T_UnitInfo k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Unit_T_UnitInfo)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Unit_T_UnitInfo *) 0);
}

Unit_T_UnitInfo * _Unit_T_UnitInfoSeq_sequence::RemoveTail ()
{
  static Unit_T_UnitInfo k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Unit_T_UnitInfo *) 0);
}

ilu_Cardinal _Unit_T_UnitInfoSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Unit_T_UnitInfo *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Unit_T_UnitInfo)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Unit_T_UnitInfo * _Unit_T_UnitInfoSeq_sequence::Find (ilu_Boolean (*matchproc)(Unit_T_UnitInfo *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Unit_T_UnitInfo *) 0);
}

void _Unit_T_UnitInfoSeq_sequence::Enumerate (void (*enumproc)(Unit_T_UnitInfo *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Unit_T_UnitInfoSeq_sequence::Length ()
{
  return _length;
}

Unit_T_UnitInfo * _Unit_T_UnitInfoSeq_sequence::Array ()
{
  return _buffer;
}

Unit_T_UnitInfo * _Unit_T_UnitInfoSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Unit_T_UnitInfo *) 0);
}

_Unit_T_ActionSeq_sequence::_Unit_T_ActionSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Unit_T_ActionSeq_sequence::~_Unit_T_ActionSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Unit_T_ActionSeq _Unit_T_ActionSeq_sequence::Create (ilu_Cardinal initial_size, Unit_T_MoveAction *initial_data)
{
  Unit_T_ActionSeq s = new _Unit_T_ActionSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Unit_T_MoveAction *) malloc((unsigned int)(sizeof(Unit_T_MoveAction) * (s->_maximum = initial_size)));
  return s;
}

void _Unit_T_ActionSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Unit_T_MoveAction *) 0;
  }
  _length = 0;
}

void _Unit_T_ActionSeq_sequence::Append (Unit_T_MoveAction * item)
{
  if (_buffer == NULL) {
    _buffer = (Unit_T_MoveAction *) malloc ((unsigned int)(sizeof(Unit_T_MoveAction) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Unit_T_MoveAction *) realloc ((char *) _buffer, (unsigned int)(sizeof(Unit_T_MoveAction) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Unit_T_MoveAction * _Unit_T_ActionSeq_sequence::RemoveHead ()
{
  static Unit_T_MoveAction k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Unit_T_MoveAction)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Unit_T_MoveAction *) 0);
}

Unit_T_MoveAction * _Unit_T_ActionSeq_sequence::RemoveTail ()
{
  static Unit_T_MoveAction k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Unit_T_MoveAction *) 0);
}

ilu_Cardinal _Unit_T_ActionSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Unit_T_MoveAction *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Unit_T_MoveAction)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Unit_T_MoveAction * _Unit_T_ActionSeq_sequence::Find (ilu_Boolean (*matchproc)(Unit_T_MoveAction *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Unit_T_MoveAction *) 0);
}

void _Unit_T_ActionSeq_sequence::Enumerate (void (*enumproc)(Unit_T_MoveAction *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Unit_T_ActionSeq_sequence::Length ()
{
  return _length;
}

Unit_T_MoveAction * _Unit_T_ActionSeq_sequence::Array ()
{
  return _buffer;
}

Unit_T_MoveAction * _Unit_T_ActionSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Unit_T_MoveAction *) 0);
}

_Unit_T_FloatSeq_sequence::_Unit_T_FloatSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Unit_T_FloatSeq_sequence::~_Unit_T_FloatSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Unit_T_FloatSeq _Unit_T_FloatSeq_sequence::Create (ilu_Cardinal initial_size, ilu_ShortReal *initial_data)
{
  Unit_T_FloatSeq s = new _Unit_T_FloatSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (ilu_ShortReal *) malloc((unsigned int)(sizeof(ilu_ShortReal) * (s->_maximum = initial_size)));
  return s;
}

void _Unit_T_FloatSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (ilu_ShortReal *) 0;
  }
  _length = 0;
}

void _Unit_T_FloatSeq_sequence::Append (ilu_ShortReal item)
{
  if (_buffer == NULL) {
    _buffer = (ilu_ShortReal *) malloc ((unsigned int)(sizeof(ilu_ShortReal) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (ilu_ShortReal *) realloc ((char *) _buffer, (unsigned int)(sizeof(ilu_ShortReal) * _maximum));
  };
  _buffer[_length] = item;
  _length += 1;
}

ilu_ShortReal _Unit_T_FloatSeq_sequence::RemoveHead ()
{
  static ilu_ShortReal k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(ilu_ShortReal)));
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_ShortReal) 0);
}

ilu_ShortReal _Unit_T_FloatSeq_sequence::RemoveTail ()
{
  static ilu_ShortReal k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_ShortReal) 0);
}

ilu_Cardinal _Unit_T_FloatSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(ilu_ShortReal, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(ilu_ShortReal)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

ilu_ShortReal _Unit_T_FloatSeq_sequence::Find (ilu_Boolean (*matchproc)(ilu_ShortReal, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((ilu_ShortReal) 0);
}

void _Unit_T_FloatSeq_sequence::Enumerate (void (*enumproc)(ilu_ShortReal, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Unit_T_FloatSeq_sequence::Length ()
{
  return _length;
}

ilu_ShortReal * _Unit_T_FloatSeq_sequence::Array ()
{
  return _buffer;
}

ilu_ShortReal _Unit_T_FloatSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((ilu_ShortReal) 0);
}

_Unit_T_ShortSeq_sequence::_Unit_T_ShortSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Unit_T_ShortSeq_sequence::~_Unit_T_ShortSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Unit_T_ShortSeq _Unit_T_ShortSeq_sequence::Create (ilu_Cardinal initial_size, ilu_ShortInteger *initial_data)
{
  Unit_T_ShortSeq s = new _Unit_T_ShortSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (ilu_ShortInteger *) malloc((unsigned int)(sizeof(ilu_ShortInteger) * (s->_maximum = initial_size)));
  return s;
}

void _Unit_T_ShortSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (ilu_ShortInteger *) 0;
  }
  _length = 0;
}

void _Unit_T_ShortSeq_sequence::Append (ilu_ShortInteger item)
{
  if (_buffer == NULL) {
    _buffer = (ilu_ShortInteger *) malloc ((unsigned int)(sizeof(ilu_ShortInteger) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (ilu_ShortInteger *) realloc ((char *) _buffer, (unsigned int)(sizeof(ilu_ShortInteger) * _maximum));
  };
  _buffer[_length] = item;
  _length += 1;
}

ilu_ShortInteger _Unit_T_ShortSeq_sequence::RemoveHead ()
{
  static ilu_ShortInteger k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(ilu_ShortInteger)));
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_ShortInteger) 0);
}

ilu_ShortInteger _Unit_T_ShortSeq_sequence::RemoveTail ()
{
  static ilu_ShortInteger k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (k);
  }
  else
    return ((ilu_ShortInteger) 0);
}

ilu_Cardinal _Unit_T_ShortSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(ilu_ShortInteger, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(ilu_ShortInteger)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

ilu_ShortInteger _Unit_T_ShortSeq_sequence::Find (ilu_Boolean (*matchproc)(ilu_ShortInteger, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((ilu_ShortInteger) 0);
}

void _Unit_T_ShortSeq_sequence::Enumerate (void (*enumproc)(ilu_ShortInteger, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Unit_T_ShortSeq_sequence::Length ()
{
  return _length;
}

ilu_ShortInteger * _Unit_T_ShortSeq_sequence::Array ()
{
  return _buffer;
}

ilu_ShortInteger _Unit_T_ShortSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((ilu_ShortInteger) 0);
}

_Unit_T_UnitSBHSeq_sequence::_Unit_T_UnitSBHSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Unit_T_UnitSBHSeq_sequence::~_Unit_T_UnitSBHSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Unit_T_UnitSBHSeq _Unit_T_UnitSBHSeq_sequence::Create (ilu_Cardinal initial_size, Unit_T_UnitSBH *initial_data)
{
  Unit_T_UnitSBHSeq s = new _Unit_T_UnitSBHSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Unit_T_UnitSBH *) malloc((unsigned int)(sizeof(Unit_T_UnitSBH) * (s->_maximum = initial_size)));
  return s;
}

void _Unit_T_UnitSBHSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Unit_T_UnitSBH *) 0;
  }
  _length = 0;
}

void _Unit_T_UnitSBHSeq_sequence::Append (Unit_T_UnitSBH item)
{
  if (_buffer == NULL) {
    _buffer = (Unit_T_UnitSBH *) malloc ((unsigned int)(sizeof(Unit_T_UnitSBH) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Unit_T_UnitSBH *) realloc ((char *) _buffer, (unsigned int)(sizeof(Unit_T_UnitSBH) * _maximum));
  };
  _buffer[_length] = item;
  _length += 1;
}

Unit_T_UnitSBH _Unit_T_UnitSBHSeq_sequence::RemoveHead ()
{
  static Unit_T_UnitSBH k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Unit_T_UnitSBH)));
    _length -= 1;
    return (k);
  }
  else
    return ((Unit_T_UnitSBH) 0);
}

Unit_T_UnitSBH _Unit_T_UnitSBHSeq_sequence::RemoveTail ()
{
  static Unit_T_UnitSBH k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (k);
  }
  else
    return ((Unit_T_UnitSBH) 0);
}

ilu_Cardinal _Unit_T_UnitSBHSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Unit_T_UnitSBH, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Unit_T_UnitSBH)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Unit_T_UnitSBH _Unit_T_UnitSBHSeq_sequence::Find (ilu_Boolean (*matchproc)(Unit_T_UnitSBH, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((Unit_T_UnitSBH) 0);
}

void _Unit_T_UnitSBHSeq_sequence::Enumerate (void (*enumproc)(Unit_T_UnitSBH, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Unit_T_UnitSBHSeq_sequence::Length ()
{
  return _length;
}

Unit_T_UnitSBH * _Unit_T_UnitSBHSeq_sequence::Array ()
{
  return _buffer;
}

Unit_T_UnitSBH _Unit_T_UnitSBHSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((Unit_T_UnitSBH) 0);
}

_Unit_T_UnitIDSeq_sequence::_Unit_T_UnitIDSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Unit_T_UnitIDSeq_sequence::~_Unit_T_UnitIDSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Unit_T_UnitIDSeq _Unit_T_UnitIDSeq_sequence::Create (ilu_Cardinal initial_size, Unit_T_UnitID *initial_data)
{
  Unit_T_UnitIDSeq s = new _Unit_T_UnitIDSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Unit_T_UnitID *) malloc((unsigned int)(sizeof(Unit_T_UnitID) * (s->_maximum = initial_size)));
  return s;
}

void _Unit_T_UnitIDSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Unit_T_UnitID *) 0;
  }
  _length = 0;
}

void _Unit_T_UnitIDSeq_sequence::Append (Unit_T_UnitID item)
{
  if (_buffer == NULL) {
    _buffer = (Unit_T_UnitID *) malloc ((unsigned int)(sizeof(Unit_T_UnitID) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Unit_T_UnitID *) realloc ((char *) _buffer, (unsigned int)(sizeof(Unit_T_UnitID) * _maximum));
  };
  _buffer[_length] = item;
  _length += 1;
}

Unit_T_UnitID _Unit_T_UnitIDSeq_sequence::RemoveHead ()
{
  static Unit_T_UnitID k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Unit_T_UnitID)));
    _length -= 1;
    return (k);
  }
  else
    return ((Unit_T_UnitID) 0);
}

Unit_T_UnitID _Unit_T_UnitIDSeq_sequence::RemoveTail ()
{
  static Unit_T_UnitID k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (k);
  }
  else
    return ((Unit_T_UnitID) 0);
}

ilu_Cardinal _Unit_T_UnitIDSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Unit_T_UnitID, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Unit_T_UnitID)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Unit_T_UnitID _Unit_T_UnitIDSeq_sequence::Find (ilu_Boolean (*matchproc)(Unit_T_UnitID, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((Unit_T_UnitID) 0);
}

void _Unit_T_UnitIDSeq_sequence::Enumerate (void (*enumproc)(Unit_T_UnitID, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Unit_T_UnitIDSeq_sequence::Length ()
{
  return _length;
}

Unit_T_UnitID * _Unit_T_UnitIDSeq_sequence::Array ()
{
  return _buffer;
}

Unit_T_UnitID _Unit_T_UnitIDSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((Unit_T_UnitID) 0);
}

ilu_Class Unit_T_rpc::ILUClassRecord = NULL;

#define MethodRecord_Unit_T_rpc_getID ((Unit_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Unit_T_rpc_getCosNamingSBH ((Unit_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Unit_T_rpc_getFrontUnitInfo ((Unit_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Unit_T_rpc_setRole ((Unit_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Unit_T_rpc_setMode ((Unit_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Unit_T_rpc_setMinorMode ((Unit_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Unit_T_rpc_sendMoveAction ((Unit_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Unit_T_rpc_sendMoveActionSeq ((Unit_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Unit_T_rpc_setALeader ((Unit_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Unit_T_rpc_unregisterFollower ((Unit_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Unit_T_rpc_setFollower ((Unit_T_rpc::ILUClassRecord)->cl_methods + 10)
#define MethodRecord_Unit_T_rpc_unsetFollower ((Unit_T_rpc::ILUClassRecord)->cl_methods + 11)
#define MethodRecord_Unit_T_rpc_addRearVehicle ((Unit_T_rpc::ILUClassRecord)->cl_methods + 12)
#define MethodRecord_Unit_T_rpc_deleteRearVehicle ((Unit_T_rpc::ILUClassRecord)->cl_methods + 13)
#define MethodRecord_Unit_T_rpc_setFormation ((Unit_T_rpc::ILUClassRecord)->cl_methods + 14)
#define MethodRecord_Unit_T_rpc_setRearVehicles ((Unit_T_rpc::ILUClassRecord)->cl_methods + 15)
#define MethodRecord_Unit_T_rpc_reportDeadVehicle ((Unit_T_rpc::ILUClassRecord)->cl_methods + 16)
#define MethodRecord_Unit_T_rpc_shutDown ((Unit_T_rpc::ILUClassRecord)->cl_methods + 17)
#define MethodRecord_Unit_T_rpc_startPhotoStream ((Unit_T_rpc::ILUClassRecord)->cl_methods + 18)
#define MethodRecord_Unit_T_rpc_stopPhotoStream ((Unit_T_rpc::ILUClassRecord)->cl_methods + 19)
#define MethodRecord_Unit_T_rpc_takePicture ((Unit_T_rpc::ILUClassRecord)->cl_methods + 20)

class Unit_T_rpc * Unit_T_rpc::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Unit_T_rpc *) ilu::SBHToObject(sbh, Unit_T_rpc::ILUClassRecord);
}

class Unit_T_rpc * Unit_T_rpc::ILUQuaT (class iluObject *from)
{
	return((class Unit_T_rpc *) (from->ILUCastDown (Unit_T_rpc::ILUClassRecord)));
}

void * Unit_T_rpc::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Unit_T_rpc::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == ilu_T_CORBA_Object::ILUClassRecord)
		return ((void *)((class ilu_T_CORBA_Object *) this));
	else return (NULL);
}

Unit_T_rpc::Unit_T_rpc ()
{
	this->ILUInstanceClassRecord = Unit_T_rpc::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Unit_T_rpc::~Unit_T_rpc ()
{
}

Unit_T_UnitID Unit_T_rpc::getID (UnitStatus *_status)
{
	Unit_T_UnitID _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_getID))
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
		_retvalue = ilu::InputString(_call, NULL, NULL, 0);
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

Unit_T_UnitSBH Unit_T_rpc::getCosNamingSBH (UnitStatus *_status)
{
	Unit_T_UnitSBH _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_getCosNamingSBH))
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
		_retvalue = ilu::InputString(_call, NULL, NULL, 0);
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

Unit_T_UnitInfo * Unit_T_rpc::getFrontUnitInfo (UnitStatus *_status)
{
	Unit_T_UnitInfo * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_getFrontUnitInfo))
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

ilu_Boolean Unit_T_rpc::setRole (UnitStatus *_status, Unit_T_UnitRole role, Unit_T_UnitSBH consoleSBH)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_setRole))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) role));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, consoleSBH, strlen(consoleSBH), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) role))
	  goto faild;
	if (!ilu::OutputString (_call, consoleSBH, strlen(consoleSBH), 0))
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

ilu_Boolean Unit_T_rpc::setMode (UnitStatus *_status, Unit_T_UnitMode mode)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_setMode))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) mode));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) mode))
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

ilu_Boolean Unit_T_rpc::setMinorMode (UnitStatus *_status, Unit_T_UnitMinorMode minorMode)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_setMinorMode))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) minorMode));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) minorMode))
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

ilu_Boolean Unit_T_rpc::sendMoveAction (UnitStatus *_status, Unit_T_MoveAction * action)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_sendMoveAction))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_MoveAction (_call, (Unit_T_MoveAction *) action));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_MoveAction (_call, action))
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

ilu_Boolean Unit_T_rpc::sendMoveActionSeq (UnitStatus *_status, Unit_T_ActionSeq actions, ilu_ShortInteger times)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_sendMoveActionSeq))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_ActionSeq (_call, (Unit_T_ActionSeq) actions));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, times));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_ActionSeq (_call, actions))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) times))
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

ilu_Boolean Unit_T_rpc::setALeader (UnitStatus *_status, Unit_T_UnitSBH leaderSBH)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_setALeader))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, leaderSBH, strlen(leaderSBH), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, leaderSBH, strlen(leaderSBH), 0))
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

ilu_Boolean Unit_T_rpc::unregisterFollower (UnitStatus *_status, Unit_T_UnitID followerUID)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_unregisterFollower))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, followerUID, strlen(followerUID), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, followerUID, strlen(followerUID), 0))
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

ilu_Boolean Unit_T_rpc::setFollower (UnitStatus *_status, Unit_T_UnitInfo * ui)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_setFollower))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) ui));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, ui))
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

ilu_Boolean Unit_T_rpc::unsetFollower (UnitStatus *_status, Unit_T_UnitID uid)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_unsetFollower))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, uid, strlen(uid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, uid, strlen(uid), 0))
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

ilu_Boolean Unit_T_rpc::addRearVehicle (UnitStatus *_status, Unit_T_UnitInfo * rearInfo)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_addRearVehicle))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) rearInfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, rearInfo))
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

ilu_Boolean Unit_T_rpc::deleteRearVehicle (UnitStatus *_status, Unit_T_UnitID uid)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_deleteRearVehicle))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, uid, strlen(uid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, uid, strlen(uid), 0))
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

ilu_Boolean Unit_T_rpc::setFormation (UnitStatus *_status, Unit_T_Formation * form)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_setFormation))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_Formation (_call, (Unit_T_Formation *) form));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_Formation (_call, form))
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

ilu_Boolean Unit_T_rpc::setRearVehicles (UnitStatus *_status, Unit_T_UnitInfoSeq rears, ilu_ShortReal distance, ilu_ShortReal angle)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_setRearVehicles))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfoSeq (_call, (Unit_T_UnitInfoSeq) rears));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, distance));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, angle));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitInfoSeq (_call, rears))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) distance))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) angle))
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

ilu_Boolean Unit_T_rpc::reportDeadVehicle (UnitStatus *_status, Unit_T_UnitID uid, ilu_T_CString details)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_reportDeadVehicle))
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

ilu_Boolean Unit_T_rpc::shutDown (UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_shutDown))
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

ilu_Boolean Unit_T_rpc::startPhotoStream (UnitStatus *_status, ilu_ShortReal frequency)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_startPhotoStream))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, frequency));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) frequency))
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

ilu_Boolean Unit_T_rpc::stopPhotoStream (UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_stopPhotoStream))
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

ilu_Boolean Unit_T_rpc::takePicture (UnitStatus *_status, ilu_Integer time, ilu_Integer procedureStartTime)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Unit_T_rpc::ILUClassRecord, MethodRecord_Unit_T_rpc_takePicture))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, time));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfInteger(_call, procedureStartTime));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) time))
	  goto faild;
	if (!ilu::OutputInteger(_call, (ilu_Integer) procedureStartTime))
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

static class iluObject * Create_Unit_T_rpc(ilu_KernelObject obj) {
	class Unit_T_rpc *nobj = new Unit_T_rpc;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Unit_RegistrationClass {

 public:

  _Unit_RegistrationClass();
};

#ifndef macintosh
static class _Unit_RegistrationClass _Unit_RegistrationInstance;
#endif

void Unit__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Unit", "2.0beta1", "v2 (2.0beta1)");
  initialized = 1;

  ilu::EnterOTMu();
  {	// for definition of Unit_T_rpc
    static ilu_CString Superclass_IDs[1] = {
	"IDL:omg.org/CORBA/Object:1.0"
	};
    ilu_Class t;
    Unit_T_rpc::ILUClassRecord = t = ilu::DefineObjectType(
	"Unit.rpc",	/* ILU name */
	"",	/* Brand */
	"IDL:Unit/rpc:1.0",	/* id */
	NULL,	/* singleton */
	ilu_kernelTRUE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	21,	/* number of methods */
	1,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Unit_T_rpc);
    {	//for method getID
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"getID",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Unit/UnitID:1.0");	//return type
    }	//end method getID
    {	//for method getCosNamingSBH
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	1,	//method index
	"getCosNamingSBH",	//name
	2,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Unit/UnitSBH:1.0");	//return type
    }	//end method getCosNamingSBH
    {	//for method getFrontUnitInfo
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	2,	//method index
	"getFrontUnitInfo",	//name
	3,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Unit/UnitInfo:1.0");	//return type
    }	//end method getFrontUnitInfo
    {	//for method setRole
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	3,	//method index
	"setRole",	//name
	4,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setRole
    {	//for method setMode
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	4,	//method index
	"setMode",	//name
	5,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setMode
    {	//for method setMinorMode
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	5,	//method index
	"setMinorMode",	//name
	6,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setMinorMode
    {	//for method sendMoveAction
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	6,	//method index
	"sendMoveAction",	//name
	7,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendMoveAction
    {	//for method sendMoveActionSeq
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	7,	//method index
	"sendMoveActionSeq",	//name
	8,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendMoveActionSeq
    {	//for method setALeader
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	8,	//method index
	"setALeader",	//name
	9,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setALeader
    {	//for method unregisterFollower
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	9,	//method index
	"unregisterFollower",	//name
	10,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method unregisterFollower
    {	//for method setFollower
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	10,	//method index
	"setFollower",	//name
	11,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setFollower
    {	//for method unsetFollower
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	11,	//method index
	"unsetFollower",	//name
	12,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method unsetFollower
    {	//for method addRearVehicle
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	12,	//method index
	"addRearVehicle",	//name
	13,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method addRearVehicle
    {	//for method deleteRearVehicle
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	13,	//method index
	"deleteRearVehicle",	//name
	14,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method deleteRearVehicle
    {	//for method setFormation
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	14,	//method index
	"setFormation",	//name
	15,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setFormation
    {	//for method setRearVehicles
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	15,	//method index
	"setRearVehicles",	//name
	16,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	3,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setRearVehicles
    {	//for method reportDeadVehicle
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	16,	//method index
	"reportDeadVehicle",	//name
	17,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method reportDeadVehicle
    {	//for method shutDown
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	17,	//method index
	"shutDown",	//name
	18,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method shutDown
    {	//for method startPhotoStream
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	18,	//method index
	"startPhotoStream",	//name
	19,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method startPhotoStream
    {	//for method stopPhotoStream
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	19,	//method index
	"stopPhotoStream",	//name
	20,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method stopPhotoStream
    {	//for method takePicture
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	20,	//method index
	"takePicture",	//name
	21,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method takePicture
    ilu::ObjectTypeDefined(t);
  }	// end definition of Unit_T_rpc
  ilu::ExitOTMu();
}

_Unit_RegistrationClass::_Unit_RegistrationClass()
{
	Unit__Initialize();
}

