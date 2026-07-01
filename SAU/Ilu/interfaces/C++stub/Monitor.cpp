/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:33:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/monitor.idl" of Wed Jul 16 16:43:00 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Monitor.hh"

extern "C" {
#include <stdio.h>
#include <string.h>
};
static void MonitorCatchException (iluCall _call, MonitorStatus *_val, ilu_Cardinal _ecode)
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

void Monitor_G::RaiseException (MonitorStatus *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	return;
}

#include <stdarg.h>

int Monitor_G::SendException (iluCall _call, MonitorStatus *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Monitor_G::SendException");
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

ilu_Boolean Monitor_G::Output_PictureInfo (iluCall _call, Monitor_T_PictureInfo * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputString (_call, (_val->picturName), strlen((_val->picturName)), 0))
	  goto faild;
	if (!Monitor_G::Output_PictureFlow (_call, (_val->pic)))
	  goto faild;
	if (!Monitor_G::Output_CurrentUnitInfo (_call, (&_val->cui)))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) (_val->responseTime)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Monitor_T_PictureInfo * Monitor_G::Input_PictureInfo (iluCall _call, Monitor_T_PictureInfo * _ref)
{
	Monitor_T_PictureInfo * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Monitor_T_PictureInfo *) malloc(sizeof(Monitor_T_PictureInfo));
	_val->picturName = ilu::InputString(_call, NULL, NULL, 0);
	_val->pic = Monitor_G::Input_PictureFlow (_call, NULL);
	Monitor_G::Input_CurrentUnitInfo (_call, &_val->cui);
	ilu::InputShortInteger (_call, &_val->responseTime);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Monitor_G::SizeOf_PictureInfo (iluCall _call, Monitor_T_PictureInfo * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfString(_call, (_val->picturName), strlen((_val->picturName)), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Monitor_G::SizeOf_PictureFlow (_call, (Monitor_T_PictureFlow) (_val->pic)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Monitor_G::SizeOf_CurrentUnitInfo (_call, (Monitor_T_CurrentUnitInfo *) (&_val->cui)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, (_val->responseTime)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

void Monitor_G::Free_PictureInfo (Monitor_T_PictureInfo * _val)
{
	Monitor_G::Free_PictureFlow (_val->pic);
}

ilu_Boolean Monitor_G::Output_PictureFlow (iluCall _call, Monitor_T_PictureFlow _val)
{
	if (!ilu::OutputBytes (_call, _val->Array(), _val->Length(), 0))
	  goto faild;
	return 1;
faild:
	return 0;
}

Monitor_T_PictureFlow Monitor_G::Input_PictureFlow (iluCall _call, Monitor_T_PictureFlow _ref)
{
	Monitor_T_PictureFlow _val;

	ilu_Cardinal _count;
	ilu_Byte *_bytes;

	_bytes = ilu::InputBytes (_call, NULL, &_count, 0);
	if (_ref != NULL) {
		_val = _ref;
		_val->_Monitor_T_PictureFlow_sequence::Clear(ilu_FALSE);
		for (ilu_Cardinal _index = 0; _index < _count; _index++)
			_val->_Monitor_T_PictureFlow_sequence::Append(_bytes[_index]);
	}
	else _val = _Monitor_T_PictureFlow_sequence::Create (_count, _bytes);
	return (_val);
}

ilu_Cardinal Monitor_G::SizeOf_PictureFlow (iluCall _call, Monitor_T_PictureFlow _val)
{
	return(ilu::SizeOfBytes (_call, _val->Array(), _val->Length(), 0));
}

void Monitor_G::Free_PictureFlow (Monitor_T_PictureFlow _val)
{
	register ilu_Byte *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Monitor_G::Output_CompleteUnitInfo (iluCall _call, Monitor_T_CompleteUnitInfo * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Monitor_G::Output_UnitState (_call, (&_val->us)))
	  goto faild;
	if (!Monitor_G::Output_CurrentUnitInfo (_call, (&_val->cui)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Monitor_T_CompleteUnitInfo * Monitor_G::Input_CompleteUnitInfo (iluCall _call, Monitor_T_CompleteUnitInfo * _ref)
{
	Monitor_T_CompleteUnitInfo * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Monitor_T_CompleteUnitInfo *) malloc(sizeof(Monitor_T_CompleteUnitInfo));
	Monitor_G::Input_UnitState (_call, &_val->us);
	Monitor_G::Input_CurrentUnitInfo (_call, &_val->cui);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Monitor_G::SizeOf_CompleteUnitInfo (iluCall _call, Monitor_T_CompleteUnitInfo * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Monitor_G::SizeOf_UnitState (_call, (Monitor_T_UnitState *) (&_val->us)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Monitor_G::SizeOf_CurrentUnitInfo (_call, (Monitor_T_CurrentUnitInfo *) (&_val->cui)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Monitor_G::Output_CurrentUnitInfo (iluCall _call, Monitor_T_CurrentUnitInfo * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Monitor_T_UnitType_UnitGroundType:
	if (!Ground_Unit_G::Output_GroundUnitInfo (_call, &_val->value.groundUnitInfo))
	  goto faild;
	break;

	case Monitor_T_UnitType_UnitAirType:
	if (!Air_Unit_G::Output_AirUnitInfo (_call, &_val->value.airUnitInfo))
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

Monitor_T_CurrentUnitInfo * Monitor_G::Input_CurrentUnitInfo (iluCall _call, Monitor_T_CurrentUnitInfo * _ref)
{
	Monitor_T_CurrentUnitInfo * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Monitor_T_CurrentUnitInfo *) malloc(sizeof(Monitor_T_CurrentUnitInfo));
	switch (discriminator) {
	case Monitor_T_UnitType_UnitGroundType:
	Ground_Unit_G::Input_GroundUnitInfo (_call, &_val->value.groundUnitInfo);
	break;

	case Monitor_T_UnitType_UnitAirType:
	Air_Unit_G::Input_AirUnitInfo (_call, &_val->value.airUnitInfo);
	break;

		default:
			break;
	}
	_val->discriminator = (Monitor_T_UnitType) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Monitor_G::SizeOf_CurrentUnitInfo (iluCall _call, Monitor_T_CurrentUnitInfo * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Monitor_T_UnitType_UnitGroundType:
	_argSize += (_dSize = Ground_Unit_G::SizeOf_GroundUnitInfo (_call, (Ground_Unit_T_GroundUnitInfo *) &_val->value.groundUnitInfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Monitor_T_UnitType_UnitAirType:
	_argSize += (_dSize = Air_Unit_G::SizeOf_AirUnitInfo (_call, (Air_Unit_T_AirUnitInfo *) &_val->value.airUnitInfo));
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

ilu_Boolean Monitor_G::Output_UnitState (iluCall _call, Monitor_T_UnitState * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) (_val->health)))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) (_val->battery)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Monitor_T_UnitState * Monitor_G::Input_UnitState (iluCall _call, Monitor_T_UnitState * _ref)
{
	Monitor_T_UnitState * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Monitor_T_UnitState *) malloc(sizeof(Monitor_T_UnitState));
	ilu::InputShortInteger (_call, &_val->health);
	ilu::InputShortInteger (_call, &_val->battery);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Monitor_G::SizeOf_UnitState (iluCall _call, Monitor_T_UnitState * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, (_val->health)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, (_val->battery)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

_Monitor_T_PictureFlow_sequence::_Monitor_T_PictureFlow_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Monitor_T_PictureFlow_sequence::~_Monitor_T_PictureFlow_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Monitor_T_PictureFlow _Monitor_T_PictureFlow_sequence::Create (ilu_Cardinal initial_size, ilu_Byte *initial_data)
{
  Monitor_T_PictureFlow s = new _Monitor_T_PictureFlow_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (ilu_Byte *) malloc((unsigned int)(sizeof(ilu_Byte) * (s->_maximum = initial_size)));
  return s;
}

void _Monitor_T_PictureFlow_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (ilu_Byte *) 0;
  }
  _length = 0;
}

void _Monitor_T_PictureFlow_sequence::Append (ilu_Byte item)
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

ilu_Byte _Monitor_T_PictureFlow_sequence::RemoveHead ()
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

ilu_Byte _Monitor_T_PictureFlow_sequence::RemoveTail ()
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

ilu_Cardinal _Monitor_T_PictureFlow_sequence::RemoveAll (ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg)
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

ilu_Byte _Monitor_T_PictureFlow_sequence::Find (ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(_buffer[i], arg))
      return (_buffer[i]);
  return ((ilu_Byte) 0);
}

void _Monitor_T_PictureFlow_sequence::Enumerate (void (*enumproc)(ilu_Byte, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(_buffer[i], arg);
}

ilu_Cardinal _Monitor_T_PictureFlow_sequence::Length ()
{
  return _length;
}

ilu_Byte * _Monitor_T_PictureFlow_sequence::Array ()
{
  return _buffer;
}

ilu_Byte _Monitor_T_PictureFlow_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (_buffer[index]);
  else
    return ((ilu_Byte) 0);
}

ilu_Class Monitor_T_rpc::ILUClassRecord = NULL;

#define MethodRecord_Monitor_T_rpc_sendUnitInfo ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Monitor_T_rpc_sendTrapPoint ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Monitor_T_rpc_sendTargetLocation ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Monitor_T_rpc_foundTarget ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Monitor_T_rpc_confirmAction ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Monitor_T_rpc_backHome ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Monitor_T_rpc_sendMissionState ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Monitor_T_rpc_sendPicture ((Monitor_T_rpc::ILUClassRecord)->cl_methods + 7)

class Monitor_T_rpc * Monitor_T_rpc::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Monitor_T_rpc *) ilu::SBHToObject(sbh, Monitor_T_rpc::ILUClassRecord);
}

class Monitor_T_rpc * Monitor_T_rpc::ILUQuaT (class iluObject *from)
{
	return((class Monitor_T_rpc *) (from->ILUCastDown (Monitor_T_rpc::ILUClassRecord)));
}

void * Monitor_T_rpc::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Monitor_T_rpc::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == ilu_T_CORBA_Object::ILUClassRecord)
		return ((void *)((class ilu_T_CORBA_Object *) this));
	else return (NULL);
}

Monitor_T_rpc::Monitor_T_rpc ()
{
	this->ILUInstanceClassRecord = Monitor_T_rpc::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Monitor_T_rpc::~Monitor_T_rpc ()
{
}

ilu_Boolean Monitor_T_rpc::sendUnitInfo (MonitorStatus *_status, Monitor_T_CompleteUnitInfo * unitInfo)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_sendUnitInfo))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Monitor_G::SizeOf_CompleteUnitInfo (_call, (Monitor_T_CompleteUnitInfo *) unitInfo));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Monitor_G::Output_CompleteUnitInfo (_call, unitInfo))
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

ilu_Boolean Monitor_T_rpc::sendTrapPoint (MonitorStatus *_status, Console_T_TrapPoint * tp)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_sendTrapPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Console_G::SizeOf_TrapPoint (_call, (Console_T_TrapPoint *) tp));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Console_G::Output_TrapPoint (_call, tp))
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

ilu_Boolean Monitor_T_rpc::sendTargetLocation (MonitorStatus *_status, Monitor_T_TargetID fid, Ground_Unit_T_Point2D * fp, ilu_ShortInteger responseTime)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_sendTargetLocation))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, fid, strlen(fid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Ground_Unit_G::SizeOf_Point2D (_call, (Ground_Unit_T_Point2D *) fp));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, responseTime));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, fid, strlen(fid), 0))
	  goto faild;
	if (!Ground_Unit_G::Output_Point2D (_call, fp))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) responseTime))
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

ilu_Boolean Monitor_T_rpc::foundTarget (MonitorStatus *_status, Monitor_T_TargetID fid, Monitor_T_PictureInfo * pi)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_foundTarget))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, fid, strlen(fid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Monitor_G::SizeOf_PictureInfo (_call, (Monitor_T_PictureInfo *) pi));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, fid, strlen(fid), 0))
	  goto faild;
	if (!Monitor_G::Output_PictureInfo (_call, pi))
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

ilu_Boolean Monitor_T_rpc::confirmAction (MonitorStatus *_status, Monitor_T_TargetID fid, ilu_ShortInteger responseTime)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_confirmAction))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, fid, strlen(fid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, responseTime));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, fid, strlen(fid), 0))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) responseTime))
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

ilu_Boolean Monitor_T_rpc::backHome (MonitorStatus *_status, Unit_T_UnitID uid, Monitor_T_BackHomeReason bhr)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_backHome))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, uid, strlen(uid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) bhr));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, uid, strlen(uid), 0))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) bhr))
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

ilu_Boolean Monitor_T_rpc::sendMissionState (MonitorStatus *_status, Monitor_T_TargetID fid, Monitor_T_MissionSituation ms)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_sendMissionState))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, fid, strlen(fid), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) ms));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputString (_call, fid, strlen(fid), 0))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) ms))
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

ilu_Boolean Monitor_T_rpc::sendPicture (MonitorStatus *_status, ilu_T_CString pictureName, Monitor_T_PictureFlow pic, ilu_Integer time, ilu_Integer procedureStartTime)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Monitor_T_rpc::ILUClassRecord, MethodRecord_Monitor_T_rpc_sendPicture))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfString(_call, pictureName, strlen(pictureName), 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Monitor_G::SizeOf_PictureFlow (_call, (Monitor_T_PictureFlow) pic));
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
	if (!ilu::OutputString (_call, pictureName, strlen(pictureName), 0))
	  goto faild;
	if (!Monitor_G::Output_PictureFlow (_call, pic))
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

static class iluObject * Create_Monitor_T_rpc(ilu_KernelObject obj) {
	class Monitor_T_rpc *nobj = new Monitor_T_rpc;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Monitor_RegistrationClass {

 public:

  _Monitor_RegistrationClass();
};

#ifndef macintosh
static class _Monitor_RegistrationClass _Monitor_RegistrationInstance;
#endif

void Monitor__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Monitor", "2.0beta1", "v2 (2.0beta1)");
  initialized = 1;

  ilu::EnterOTMu();
  {	// for definition of Monitor_T_rpc
    static ilu_CString Superclass_IDs[1] = {
	"IDL:omg.org/CORBA/Object:1.0"
	};
    ilu_Class t;
    Monitor_T_rpc::ILUClassRecord = t = ilu::DefineObjectType(
	"Monitor.rpc",	/* ILU name */
	"",	/* Brand */
	"IDL:Monitor/rpc:1.0",	/* id */
	NULL,	/* singleton */
	ilu_kernelTRUE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	8,	/* number of methods */
	1,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Monitor_T_rpc);
    {	//for method sendUnitInfo
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	0,	//method index
	"sendUnitInfo",	//name
	1,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendUnitInfo
    {	//for method sendTrapPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	1,	//method index
	"sendTrapPoint",	//name
	2,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendTrapPoint
    {	//for method sendTargetLocation
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	2,	//method index
	"sendTargetLocation",	//name
	3,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	3,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendTargetLocation
    {	//for method foundTarget
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	3,	//method index
	"foundTarget",	//name
	4,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method foundTarget
    {	//for method confirmAction
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	4,	//method index
	"confirmAction",	//name
	5,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method confirmAction
    {	//for method backHome
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	5,	//method index
	"backHome",	//name
	6,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method backHome
    {	//for method sendMissionState
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	6,	//method index
	"sendMissionState",	//name
	7,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	2,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendMissionState
    {	//for method sendPicture
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	7,	//method index
	"sendPicture",	//name
	8,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	4,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendPicture
    ilu::ObjectTypeDefined(t);
  }	// end definition of Monitor_T_rpc
  ilu::ExitOTMu();
}

_Monitor_RegistrationClass::_Monitor_RegistrationClass()
{
	Monitor__Initialize();
}

