/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:33:11 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Ground_Unit.hh"

extern "C" {
#include <stdio.h>
#include <string.h>
};
static void Ground_UnitCatchException (iluCall _call, Ground_UnitStatus *_val, ilu_Cardinal _ecode)
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

void Ground_Unit_G::RaiseException (Ground_UnitStatus *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	return;
}

#include <stdarg.h>

int Ground_Unit_G::SendException (iluCall _call, Ground_UnitStatus *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Ground_Unit_G::SendException");
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

ilu_Boolean Ground_Unit_G::Output_TrapPointSeq (iluCall _call, Ground_Unit_T_TrapPointSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Ground_Unit_T_TrapPoint2D *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Ground_Unit_G::Output_TrapPoint2D (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Ground_Unit_T_TrapPointSeq Ground_Unit_G::Input_TrapPointSeq (iluCall _call, Ground_Unit_T_TrapPointSeq _ref)
{
	Ground_Unit_T_TrapPointSeq _val;

	ilu_Cardinal _count, _index;
	Ground_Unit_T_TrapPoint2D * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Ground_Unit_T_TrapPointSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Ground_Unit_G::Input_TrapPoint2D (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Ground_Unit_G::SizeOf_TrapPointSeq (iluCall _call, Ground_Unit_T_TrapPointSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Ground_Unit_T_TrapPoint2D *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Ground_Unit_G::SizeOf_TrapPoint2D (_call, (Ground_Unit_T_TrapPoint2D *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Ground_Unit_G::Free_TrapPointSeq (Ground_Unit_T_TrapPointSeq _val)
{
	register Ground_Unit_T_TrapPoint2D *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Ground_Unit_G::Output_TaskPath (iluCall _call, Ground_Unit_T_TaskPath _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Ground_Unit_T_Point2D *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Ground_Unit_G::Output_Point2D (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Ground_Unit_T_TaskPath Ground_Unit_G::Input_TaskPath (iluCall _call, Ground_Unit_T_TaskPath _ref)
{
	Ground_Unit_T_TaskPath _val;

	ilu_Cardinal _count, _index;
	Ground_Unit_T_Point2D * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Ground_Unit_T_TaskPath_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Ground_Unit_G::Input_Point2D (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Ground_Unit_G::SizeOf_TaskPath (iluCall _call, Ground_Unit_T_TaskPath _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Ground_Unit_T_Point2D *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Point2D (_call, (Ground_Unit_T_Point2D *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Ground_Unit_G::Free_TaskPath (Ground_Unit_T_TaskPath _val)
{
	register Ground_Unit_T_Point2D *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Ground_Unit_G::Output_TrapPoint2D (iluCall _call, Ground_Unit_T_TrapPoint2D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Ground_Unit_G::Output_Point2D (_call, (&_val->point)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->radius)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Ground_Unit_T_TrapPoint2D * Ground_Unit_G::Input_TrapPoint2D (iluCall _call, Ground_Unit_T_TrapPoint2D * _ref)
{
	Ground_Unit_T_TrapPoint2D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Ground_Unit_T_TrapPoint2D *) malloc(sizeof(Ground_Unit_T_TrapPoint2D));
	Ground_Unit_G::Input_Point2D (_call, &_val->point);
	ilu::InputShortReal (_call, &_val->radius);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Ground_Unit_G::SizeOf_TrapPoint2D (iluCall _call, Ground_Unit_T_TrapPoint2D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Point2D (_call, (Ground_Unit_T_Point2D *) (&_val->point)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->radius)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Ground_Unit_G::Output_Point2D (iluCall _call, Ground_Unit_T_Point2D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->x)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->y)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Ground_Unit_T_Point2D * Ground_Unit_G::Input_Point2D (iluCall _call, Ground_Unit_T_Point2D * _ref)
{
	Ground_Unit_T_Point2D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Ground_Unit_T_Point2D *) malloc(sizeof(Ground_Unit_T_Point2D));
	ilu::InputShortReal (_call, &_val->x);
	ilu::InputShortReal (_call, &_val->y);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Ground_Unit_G::SizeOf_Point2D (iluCall _call, Ground_Unit_T_Point2D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->x)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->y)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Ground_Unit_G::Output_GroundUnitInfo (iluCall _call, Ground_Unit_T_GroundUnitInfo * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, (&_val->info)))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) (_val->role)))
	  goto faild;
	if (!Ground_Unit_G::Output_Speed2D (_call, (&_val->speed)))
	  goto faild;
	if (!Ground_Unit_G::Output_Pose2D (_call, (&_val->pose)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Ground_Unit_T_GroundUnitInfo * Ground_Unit_G::Input_GroundUnitInfo (iluCall _call, Ground_Unit_T_GroundUnitInfo * _ref)
{
	Ground_Unit_T_GroundUnitInfo * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Ground_Unit_T_GroundUnitInfo *) malloc(sizeof(Ground_Unit_T_GroundUnitInfo));
	Unit_G::Input_UnitInfo (_call, &_val->info);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  _val->role = (Unit_T_UnitRole) _index; };
	Ground_Unit_G::Input_Speed2D (_call, &_val->speed);
	Ground_Unit_G::Input_Pose2D (_call, &_val->pose);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Ground_Unit_G::SizeOf_GroundUnitInfo (iluCall _call, Ground_Unit_T_GroundUnitInfo * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) (&_val->info)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) (_val->role)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Speed2D (_call, (Ground_Unit_T_Speed2D *) (&_val->speed)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Pose2D (_call, (Ground_Unit_T_Pose2D *) (&_val->pose)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Ground_Unit_G::Output_Speed2D (iluCall _call, Ground_Unit_T_Speed2D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->leanerVel)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->angularVel)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Ground_Unit_T_Speed2D * Ground_Unit_G::Input_Speed2D (iluCall _call, Ground_Unit_T_Speed2D * _ref)
{
	Ground_Unit_T_Speed2D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Ground_Unit_T_Speed2D *) malloc(sizeof(Ground_Unit_T_Speed2D));
	ilu::InputShortReal (_call, &_val->leanerVel);
	ilu::InputShortReal (_call, &_val->angularVel);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Ground_Unit_G::SizeOf_Speed2D (iluCall _call, Ground_Unit_T_Speed2D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->leanerVel)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->angularVel)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Ground_Unit_G::Output_Pose2D (iluCall _call, Ground_Unit_T_Pose2D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->x)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->y)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->yaw)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Ground_Unit_T_Pose2D * Ground_Unit_G::Input_Pose2D (iluCall _call, Ground_Unit_T_Pose2D * _ref)
{
	Ground_Unit_T_Pose2D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Ground_Unit_T_Pose2D *) malloc(sizeof(Ground_Unit_T_Pose2D));
	ilu::InputShortReal (_call, &_val->x);
	ilu::InputShortReal (_call, &_val->y);
	ilu::InputShortReal (_call, &_val->yaw);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Ground_Unit_G::SizeOf_Pose2D (iluCall _call, Ground_Unit_T_Pose2D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->x)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->y)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->yaw)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

_Ground_Unit_T_TrapPointSeq_sequence::_Ground_Unit_T_TrapPointSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Ground_Unit_T_TrapPointSeq_sequence::~_Ground_Unit_T_TrapPointSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Ground_Unit_T_TrapPointSeq _Ground_Unit_T_TrapPointSeq_sequence::Create (ilu_Cardinal initial_size, Ground_Unit_T_TrapPoint2D *initial_data)
{
  Ground_Unit_T_TrapPointSeq s = new _Ground_Unit_T_TrapPointSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Ground_Unit_T_TrapPoint2D *) malloc((unsigned int)(sizeof(Ground_Unit_T_TrapPoint2D) * (s->_maximum = initial_size)));
  return s;
}

void _Ground_Unit_T_TrapPointSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Ground_Unit_T_TrapPoint2D *) 0;
  }
  _length = 0;
}

void _Ground_Unit_T_TrapPointSeq_sequence::Append (Ground_Unit_T_TrapPoint2D * item)
{
  if (_buffer == NULL) {
    _buffer = (Ground_Unit_T_TrapPoint2D *) malloc ((unsigned int)(sizeof(Ground_Unit_T_TrapPoint2D) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Ground_Unit_T_TrapPoint2D *) realloc ((char *) _buffer, (unsigned int)(sizeof(Ground_Unit_T_TrapPoint2D) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Ground_Unit_T_TrapPoint2D * _Ground_Unit_T_TrapPointSeq_sequence::RemoveHead ()
{
  static Ground_Unit_T_TrapPoint2D k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Ground_Unit_T_TrapPoint2D)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Ground_Unit_T_TrapPoint2D *) 0);
}

Ground_Unit_T_TrapPoint2D * _Ground_Unit_T_TrapPointSeq_sequence::RemoveTail ()
{
  static Ground_Unit_T_TrapPoint2D k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Ground_Unit_T_TrapPoint2D *) 0);
}

ilu_Cardinal _Ground_Unit_T_TrapPointSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Ground_Unit_T_TrapPoint2D *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Ground_Unit_T_TrapPoint2D)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Ground_Unit_T_TrapPoint2D * _Ground_Unit_T_TrapPointSeq_sequence::Find (ilu_Boolean (*matchproc)(Ground_Unit_T_TrapPoint2D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Ground_Unit_T_TrapPoint2D *) 0);
}

void _Ground_Unit_T_TrapPointSeq_sequence::Enumerate (void (*enumproc)(Ground_Unit_T_TrapPoint2D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Ground_Unit_T_TrapPointSeq_sequence::Length ()
{
  return _length;
}

Ground_Unit_T_TrapPoint2D * _Ground_Unit_T_TrapPointSeq_sequence::Array ()
{
  return _buffer;
}

Ground_Unit_T_TrapPoint2D * _Ground_Unit_T_TrapPointSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Ground_Unit_T_TrapPoint2D *) 0);
}

_Ground_Unit_T_TaskPath_sequence::_Ground_Unit_T_TaskPath_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Ground_Unit_T_TaskPath_sequence::~_Ground_Unit_T_TaskPath_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Ground_Unit_T_TaskPath _Ground_Unit_T_TaskPath_sequence::Create (ilu_Cardinal initial_size, Ground_Unit_T_Point2D *initial_data)
{
  Ground_Unit_T_TaskPath s = new _Ground_Unit_T_TaskPath_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Ground_Unit_T_Point2D *) malloc((unsigned int)(sizeof(Ground_Unit_T_Point2D) * (s->_maximum = initial_size)));
  return s;
}

void _Ground_Unit_T_TaskPath_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Ground_Unit_T_Point2D *) 0;
  }
  _length = 0;
}

void _Ground_Unit_T_TaskPath_sequence::Append (Ground_Unit_T_Point2D * item)
{
  if (_buffer == NULL) {
    _buffer = (Ground_Unit_T_Point2D *) malloc ((unsigned int)(sizeof(Ground_Unit_T_Point2D) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Ground_Unit_T_Point2D *) realloc ((char *) _buffer, (unsigned int)(sizeof(Ground_Unit_T_Point2D) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Ground_Unit_T_Point2D * _Ground_Unit_T_TaskPath_sequence::RemoveHead ()
{
  static Ground_Unit_T_Point2D k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Ground_Unit_T_Point2D)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Ground_Unit_T_Point2D *) 0);
}

Ground_Unit_T_Point2D * _Ground_Unit_T_TaskPath_sequence::RemoveTail ()
{
  static Ground_Unit_T_Point2D k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Ground_Unit_T_Point2D *) 0);
}

ilu_Cardinal _Ground_Unit_T_TaskPath_sequence::RemoveAll (ilu_Boolean (*matchproc)(Ground_Unit_T_Point2D *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Ground_Unit_T_Point2D)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Ground_Unit_T_Point2D * _Ground_Unit_T_TaskPath_sequence::Find (ilu_Boolean (*matchproc)(Ground_Unit_T_Point2D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Ground_Unit_T_Point2D *) 0);
}

void _Ground_Unit_T_TaskPath_sequence::Enumerate (void (*enumproc)(Ground_Unit_T_Point2D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Ground_Unit_T_TaskPath_sequence::Length ()
{
  return _length;
}

Ground_Unit_T_Point2D * _Ground_Unit_T_TaskPath_sequence::Array ()
{
  return _buffer;
}

Ground_Unit_T_Point2D * _Ground_Unit_T_TaskPath_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Ground_Unit_T_Point2D *) 0);
}

ilu_Class Ground_Unit_T_rpc::ILUClassRecord = NULL;

#define MethodRecord_Ground_Unit_T_rpc_getCurrentSpeed ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Ground_Unit_T_rpc_getCurrentPose ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Ground_Unit_T_rpc_getCurrentInfo ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Ground_Unit_T_rpc_sendVehicleInfo ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Ground_Unit_T_rpc_reportTrap ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Ground_Unit_T_rpc_clearTraps ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Ground_Unit_T_rpc_getTraps ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Ground_Unit_T_rpc_setTrapPoint ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Ground_Unit_T_rpc_setTrack ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Ground_Unit_T_rpc_setTaskPath ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Ground_Unit_T_rpc_setTaskPoint ((Ground_Unit_T_rpc::ILUClassRecord)->cl_methods + 10)

class Ground_Unit_T_rpc * Ground_Unit_T_rpc::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Ground_Unit_T_rpc *) ilu::SBHToObject(sbh, Ground_Unit_T_rpc::ILUClassRecord);
}

class Ground_Unit_T_rpc * Ground_Unit_T_rpc::ILUQuaT (class iluObject *from)
{
	return((class Ground_Unit_T_rpc *) (from->ILUCastDown (Ground_Unit_T_rpc::ILUClassRecord)));
}

void * Ground_Unit_T_rpc::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Ground_Unit_T_rpc::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == Unit_T_rpc::ILUClassRecord)
		return ((void *)((class Unit_T_rpc *) this));
	else if (cast_to == ilu_T_CORBA_Object::ILUClassRecord)
		return ((void *)((class ilu_T_CORBA_Object *) this));
	else return (NULL);
}

Ground_Unit_T_rpc::Ground_Unit_T_rpc ()
{
	this->ILUInstanceClassRecord = Ground_Unit_T_rpc::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Ground_Unit_T_rpc::~Ground_Unit_T_rpc ()
{
}

Ground_Unit_T_Speed2D * Ground_Unit_T_rpc::getCurrentSpeed (Ground_UnitStatus *_status)
{
	Ground_Unit_T_Speed2D * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_getCurrentSpeed))
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
		_retvalue = Ground_Unit_G::Input_Speed2D (_call, NULL);
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

Ground_Unit_T_Pose2D * Ground_Unit_T_rpc::getCurrentPose (Ground_UnitStatus *_status)
{
	Ground_Unit_T_Pose2D * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_getCurrentPose))
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
		_retvalue = Ground_Unit_G::Input_Pose2D (_call, NULL);
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

Ground_Unit_T_GroundUnitInfo * Ground_Unit_T_rpc::getCurrentInfo (Ground_UnitStatus *_status)
{
	Ground_Unit_T_GroundUnitInfo * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_getCurrentInfo))
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
		_retvalue = Ground_Unit_G::Input_GroundUnitInfo (_call, NULL);
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

ilu_Boolean Ground_Unit_T_rpc::sendVehicleInfo (Ground_UnitStatus *_status, Ground_Unit_T_GroundUnitInfo * info)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_sendVehicleInfo))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_GroundUnitInfo (_call, (Ground_Unit_T_GroundUnitInfo *) info));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Ground_Unit_G::Output_GroundUnitInfo (_call, info))
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

ilu_Boolean Ground_Unit_T_rpc::reportTrap (Ground_UnitStatus *_status, Ground_Unit_T_TrapPoint2D * trap)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_reportTrap))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_TrapPoint2D (_call, (Ground_Unit_T_TrapPoint2D *) trap));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Ground_Unit_G::Output_TrapPoint2D (_call, trap))
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

ilu_Boolean Ground_Unit_T_rpc::clearTraps (Ground_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_clearTraps))
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

Ground_Unit_T_TrapPointSeq Ground_Unit_T_rpc::getTraps (Ground_UnitStatus *_status)
{
	Ground_Unit_T_TrapPointSeq _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_getTraps))
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
		_retvalue = Ground_Unit_G::Input_TrapPointSeq (_call, NULL);
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

ilu_Boolean Ground_Unit_T_rpc::setTrapPoint (Ground_UnitStatus *_status, Ground_Unit_T_TrapPoint2D * trap)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_setTrapPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_TrapPoint2D (_call, (Ground_Unit_T_TrapPoint2D *) trap));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Ground_Unit_G::Output_TrapPoint2D (_call, trap))
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

ilu_Boolean Ground_Unit_T_rpc::setTrack (Ground_UnitStatus *_status, Ground_Unit_T_TaskPath track)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_setTrack))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_TaskPath (_call, (Ground_Unit_T_TaskPath) track));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Ground_Unit_G::Output_TaskPath (_call, track))
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

ilu_Boolean Ground_Unit_T_rpc::setTaskPath (Ground_UnitStatus *_status, Ground_Unit_T_TaskPath path)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_setTaskPath))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_TaskPath (_call, (Ground_Unit_T_TaskPath) path));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Ground_Unit_G::Output_TaskPath (_call, path))
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

ilu_Boolean Ground_Unit_T_rpc::setTaskPoint (Ground_UnitStatus *_status, Ground_Unit_T_Point2D * point)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Ground_Unit_T_rpc::ILUClassRecord, MethodRecord_Ground_Unit_T_rpc_setTaskPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Point2D (_call, (Ground_Unit_T_Point2D *) point));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Ground_Unit_G::Output_Point2D (_call, point))
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

static class iluObject * Create_Ground_Unit_T_rpc(ilu_KernelObject obj) {
	class Ground_Unit_T_rpc *nobj = new Ground_Unit_T_rpc;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Ground_Unit_RegistrationClass {

 public:

  _Ground_Unit_RegistrationClass();
};

#ifndef macintosh
static class _Ground_Unit_RegistrationClass _Ground_Unit_RegistrationInstance;
#endif

void Ground_Unit__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Ground-Unit", "2.0beta1", "v2 (2.0beta1)");
  initialized = 1;

  ilu::EnterOTMu();
  {	// for definition of Ground_Unit_T_rpc
    static ilu_CString Superclass_IDs[1] = {
	"IDL:Unit/rpc:1.0"
	};
    ilu_Class t;
    Ground_Unit_T_rpc::ILUClassRecord = t = ilu::DefineObjectType(
	"Ground-Unit.rpc",	/* ILU name */
	"",	/* Brand */
	"IDL:Ground_Unit/rpc:1.0",	/* id */
	NULL,	/* singleton */
	ilu_kernelTRUE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	11,	/* number of methods */
	1,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Ground_Unit_T_rpc);
    {	//for method getCurrentSpeed
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"getCurrentSpeed",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Ground_Unit/Speed2D:1.0");	//return type
    }	//end method getCurrentSpeed
    {	//for method getCurrentPose
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	1,	//method index
	"getCurrentPose",	//name
	2,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Ground_Unit/Pose2D:1.0");	//return type
    }	//end method getCurrentPose
    {	//for method getCurrentInfo
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	2,	//method index
	"getCurrentInfo",	//name
	3,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"IDL:Ground_Unit/GroundUnitInfo:1.0");	//return type
    }	//end method getCurrentInfo
    {	//for method sendVehicleInfo
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	3,	//method index
	"sendVehicleInfo",	//name
	4,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendVehicleInfo
    {	//for method reportTrap
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	4,	//method index
	"reportTrap",	//name
	5,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method reportTrap
    {	//for method clearTraps
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	5,	//method index
	"clearTraps",	//name
	6,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method clearTraps
    {	//for method getTraps
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	6,	//method index
	"getTraps",	//name
	7,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:cyWkOJaqoKC2Is+MR6b9JrnwafC");	//return type
    }	//end method getTraps
    {	//for method setTrapPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	7,	//method index
	"setTrapPoint",	//name
	8,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setTrapPoint
    {	//for method setTrack
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	8,	//method index
	"setTrack",	//name
	9,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setTrack
    {	//for method setTaskPath
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	9,	//method index
	"setTaskPath",	//name
	10,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setTaskPath
    {	//for method setTaskPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	10,	//method index
	"setTaskPoint",	//name
	11,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setTaskPoint
    ilu::ObjectTypeDefined(t);
  }	// end definition of Ground_Unit_T_rpc
  ilu::ExitOTMu();
}

_Ground_Unit_RegistrationClass::_Ground_Unit_RegistrationClass()
{
	Ground_Unit__Initialize();
}

