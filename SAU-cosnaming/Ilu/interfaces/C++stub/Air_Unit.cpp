/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:30:56 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include <ilu.hh>
#include "Air_Unit.hh"

extern "C" {
#include <stdio.h>
#include <string.h>
};
static void Air_UnitCatchException (iluCall _call, Air_UnitStatus *_val, ilu_Cardinal _ecode)
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

void Air_Unit_G::RaiseException (Air_UnitStatus *stat, ilu_Exception exception...)
{
	va_list ap; va_start(ap, exception);
	stat->returnCode = exception;
	if (exception == NULL)
		;
	return;
}

#include <stdarg.h>

int Air_Unit_G::SendException (iluCall _call, Air_UnitStatus *stat)
{
  ilu_Cardinal _dSize, _argSize = 0;
  ilu_Cardinal eCode = 0, i, limit;
  ilu_Method m;
  m = ilu_MethodOfCall(&_call->call);
  limit = m->me_exceptionCount;
  for (i = 1;  i <= limit;  i += 1)
    if (ilu::ExceptionOfMethod(m, i) == stat->returnCode)
      {eCode = i; break;}
  _ilu_Assert(eCode > 0, "Air_Unit_G::SendException");
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

void Air_Unit_G::Free_UnitSBHSeq (Unit_T_UnitSBHSeq _val)
{
	register Unit_T_UnitSBH *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Air_Unit_G::Output_TrapPointSeq (iluCall _call, Air_Unit_T_TrapPointSeq _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Air_Unit_T_TrapPoint3D *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Air_Unit_G::Output_TrapPoint3D (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_TrapPointSeq Air_Unit_G::Input_TrapPointSeq (iluCall _call, Air_Unit_T_TrapPointSeq _ref)
{
	Air_Unit_T_TrapPointSeq _val;

	ilu_Cardinal _count, _index;
	Air_Unit_T_TrapPoint3D * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Air_Unit_T_TrapPointSeq_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Air_Unit_G::Input_TrapPoint3D (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_TrapPointSeq (iluCall _call, Air_Unit_T_TrapPointSeq _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Air_Unit_T_TrapPoint3D *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Air_Unit_G::SizeOf_TrapPoint3D (_call, (Air_Unit_T_TrapPoint3D *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Air_Unit_G::Free_TrapPointSeq (Air_Unit_T_TrapPointSeq _val)
{
	register Air_Unit_T_TrapPoint3D *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Air_Unit_G::Output_TaskPath (iluCall _call, Air_Unit_T_TaskPath _val)
{
	if (!ilu::OutputSequence (_call, _val->Length(), 0))
	  goto faild;
	{
	Air_Unit_T_Point3D *data = _val->Array();
	ilu_Cardinal i;

	for(i = 0;  i < _val->Length();  i++)
	{
	if (!Air_Unit_G::Output_Point3D (_call, &data[i]))
	  goto faild;
	}};
	ilu::EndSequence(_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_TaskPath Air_Unit_G::Input_TaskPath (iluCall _call, Air_Unit_T_TaskPath _ref)
{
	Air_Unit_T_TaskPath _val;

	ilu_Cardinal _count, _index;
	Air_Unit_T_Point3D * _tmp;

	ilu::InputSequence (_call, &_count, 0);
	if (_ref != NULL) _val = _ref; else _val = new _Air_Unit_T_TaskPath_sequence;
	_val->Clear(ilu_FALSE);
	for (_index = 0;  _index < _count;  _index++)
		{
		_tmp = Air_Unit_G::Input_Point3D (_call, NULL);
		_val->Append (_tmp);
	};
	ilu::EndSequence(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_TaskPath (iluCall _call, Air_Unit_T_TaskPath _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	register Air_Unit_T_Point3D *data = _val->Array();
	register ilu_Cardinal i = _val->Length();

	_argSize += (_dSize = ilu::SizeOfSequence (_call, i, 0));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	for (i = 0;  i < _val->Length();  i++) {
	_argSize += (_dSize = Air_Unit_G::SizeOf_Point3D (_call, (Air_Unit_T_Point3D *) &data[i]));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	}
	ilu::EndSequence(_call);
	return (_argSize);
faild:
	return 0;
}

void Air_Unit_G::Free_TaskPath (Air_Unit_T_TaskPath _val)
{
	register Air_Unit_T_Point3D *data = _val->Array();

	free((char *) data);
}

ilu_Boolean Air_Unit_G::Output_Site (iluCall _call, Air_Unit_T_Site * _val)
{
	if (!ilu::OutputUnion (_call, (ilu_Cardinal) _val->discriminator, ilu_enumeration_tk))
	  goto faild;
	switch (_val->discriminator) {
	case Air_Unit_T_SiteType_Rectangle:
	if (!Air_Unit_G::Output_RectangleData (_call, &_val->value.rd))
	  goto faild;
	break;

	case Air_Unit_T_SiteType_Circle:
	if (!Air_Unit_G::Output_CircleData (_call, &_val->value.cd))
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

Air_Unit_T_Site * Air_Unit_G::Input_Site (iluCall _call, Air_Unit_T_Site * _ref)
{
	Air_Unit_T_Site * _val;

	ilu_Cardinal discriminator;
	ilu::InputUnion (_call, &discriminator, ilu_enumeration_tk);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_Site *) malloc(sizeof(Air_Unit_T_Site));
	switch (discriminator) {
	case Air_Unit_T_SiteType_Rectangle:
	Air_Unit_G::Input_RectangleData (_call, &_val->value.rd);
	break;

	case Air_Unit_T_SiteType_Circle:
	Air_Unit_G::Input_CircleData (_call, &_val->value.cd);
	break;

		default:
			break;
	}
	_val->discriminator = (Air_Unit_T_SiteType) discriminator;
	ilu::EndUnion(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_Site (iluCall _call, Air_Unit_T_Site * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize += (_dSize = ilu::SizeOfUnion (_call, _val->discriminator, ilu_enumeration_tk));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	switch (_val->discriminator) {
	case Air_Unit_T_SiteType_Rectangle:
	_argSize += (_dSize = Air_Unit_G::SizeOf_RectangleData (_call, (Air_Unit_T_RectangleData *) &_val->value.rd));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	break;
	case Air_Unit_T_SiteType_Circle:
	_argSize += (_dSize = Air_Unit_G::SizeOf_CircleData (_call, (Air_Unit_T_CircleData *) &_val->value.cd));
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

ilu_Boolean Air_Unit_G::Output_CircleData (iluCall _call, Air_Unit_T_CircleData * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Air_Unit_G::Output_Point3D (_call, (&_val->po)))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) (_val->r)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_CircleData * Air_Unit_G::Input_CircleData (iluCall _call, Air_Unit_T_CircleData * _ref)
{
	Air_Unit_T_CircleData * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_CircleData *) malloc(sizeof(Air_Unit_T_CircleData));
	Air_Unit_G::Input_Point3D (_call, &_val->po);
	ilu::InputShortInteger (_call, &_val->r);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_CircleData (iluCall _call, Air_Unit_T_CircleData * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Air_Unit_G::SizeOf_Point3D (_call, (Air_Unit_T_Point3D *) (&_val->po)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, (_val->r)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_RectangleData (iluCall _call, Air_Unit_T_RectangleData * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Air_Unit_G::Output_Point3D (_call, (&_val->po)))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) (_val->x)))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) (_val->y)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_RectangleData * Air_Unit_G::Input_RectangleData (iluCall _call, Air_Unit_T_RectangleData * _ref)
{
	Air_Unit_T_RectangleData * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_RectangleData *) malloc(sizeof(Air_Unit_T_RectangleData));
	Air_Unit_G::Input_Point3D (_call, &_val->po);
	ilu::InputShortInteger (_call, &_val->x);
	ilu::InputShortInteger (_call, &_val->y);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_RectangleData (iluCall _call, Air_Unit_T_RectangleData * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Air_Unit_G::SizeOf_Point3D (_call, (Air_Unit_T_Point3D *) (&_val->po)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, (_val->x)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, (_val->y)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_TrapPoint3D (iluCall _call, Air_Unit_T_TrapPoint3D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Air_Unit_G::Output_Point3D (_call, (&_val->point)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->radius)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_TrapPoint3D * Air_Unit_G::Input_TrapPoint3D (iluCall _call, Air_Unit_T_TrapPoint3D * _ref)
{
	Air_Unit_T_TrapPoint3D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_TrapPoint3D *) malloc(sizeof(Air_Unit_T_TrapPoint3D));
	Air_Unit_G::Input_Point3D (_call, &_val->point);
	ilu::InputShortReal (_call, &_val->radius);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_TrapPoint3D (iluCall _call, Air_Unit_T_TrapPoint3D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Air_Unit_G::SizeOf_Point3D (_call, (Air_Unit_T_Point3D *) (&_val->point)));
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

ilu_Boolean Air_Unit_G::Output_Point3D (iluCall _call, Air_Unit_T_Point3D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->x)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->y)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->z)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_Point3D * Air_Unit_G::Input_Point3D (iluCall _call, Air_Unit_T_Point3D * _ref)
{
	Air_Unit_T_Point3D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_Point3D *) malloc(sizeof(Air_Unit_T_Point3D));
	ilu::InputShortReal (_call, &_val->x);
	ilu::InputShortReal (_call, &_val->y);
	ilu::InputShortReal (_call, &_val->z);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_Point3D (iluCall _call, Air_Unit_T_Point3D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->x)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->y)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->z)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_AirUnitInfo (iluCall _call, Air_Unit_T_AirUnitInfo * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!Unit_G::Output_UnitInfo (_call, (&_val->info)))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) (_val->role)))
	  goto faild;
	if (!Air_Unit_G::Output_Speed3D (_call, (&_val->speed)))
	  goto faild;
	if (!Air_Unit_G::Output_FusionAngularVelocity (_call, (&_val->angularVelocity)))
	  goto faild;
	if (!Air_Unit_G::Output_GPSInfo (_call, (&_val->gps)))
	  goto faild;
	if (!Air_Unit_G::Output_GimbalState (_call, (&_val->gs)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_AirUnitInfo * Air_Unit_G::Input_AirUnitInfo (iluCall _call, Air_Unit_T_AirUnitInfo * _ref)
{
	Air_Unit_T_AirUnitInfo * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_AirUnitInfo *) malloc(sizeof(Air_Unit_T_AirUnitInfo));
	Unit_G::Input_UnitInfo (_call, &_val->info);
	{ ilu_ShortCardinal _index; ilu::InputEnum (_call, &_index);  _val->role = (Unit_T_UnitRole) _index; };
	Air_Unit_G::Input_Speed3D (_call, &_val->speed);
	Air_Unit_G::Input_FusionAngularVelocity (_call, &_val->angularVelocity);
	Air_Unit_G::Input_GPSInfo (_call, &_val->gps);
	Air_Unit_G::Input_GimbalState (_call, &_val->gs);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_AirUnitInfo (iluCall _call, Air_Unit_T_AirUnitInfo * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = Unit_G::SizeOf_UnitInfo (_call, (Unit_T_UnitInfo *) (&_val->info)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) (_val->role)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_Speed3D (_call, (Air_Unit_T_Speed3D *) (&_val->speed)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_FusionAngularVelocity (_call, (Air_Unit_T_FusionAngularVelocity *) (&_val->angularVelocity)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_GPSInfo (_call, (Air_Unit_T_GPSInfo *) (&_val->gps)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_GimbalState (_call, (Air_Unit_T_GimbalState *) (&_val->gs)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_FusionAngularVelocity (iluCall _call, Air_Unit_T_FusionAngularVelocity * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->x)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->y)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->z)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_FusionAngularVelocity * Air_Unit_G::Input_FusionAngularVelocity (iluCall _call, Air_Unit_T_FusionAngularVelocity * _ref)
{
	Air_Unit_T_FusionAngularVelocity * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_FusionAngularVelocity *) malloc(sizeof(Air_Unit_T_FusionAngularVelocity));
	ilu::InputShortReal (_call, &_val->x);
	ilu::InputShortReal (_call, &_val->y);
	ilu::InputShortReal (_call, &_val->z);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_FusionAngularVelocity (iluCall _call, Air_Unit_T_FusionAngularVelocity * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->x)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->y)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->z)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_Speed3D (iluCall _call, Air_Unit_T_Speed3D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->x)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->y)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->z)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_Speed3D * Air_Unit_G::Input_Speed3D (iluCall _call, Air_Unit_T_Speed3D * _ref)
{
	Air_Unit_T_Speed3D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_Speed3D *) malloc(sizeof(Air_Unit_T_Speed3D));
	ilu::InputShortReal (_call, &_val->x);
	ilu::InputShortReal (_call, &_val->y);
	ilu::InputShortReal (_call, &_val->z);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_Speed3D (iluCall _call, Air_Unit_T_Speed3D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->x)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->y)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->z)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_GPSInfo (iluCall _call, Air_Unit_T_GPSInfo * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->longitude)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->latitude)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->altitude)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->height)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->time)))
	  goto faild;
	if (!ilu::OutputShortInteger(_call, (short int) (_val->health)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_GPSInfo * Air_Unit_G::Input_GPSInfo (iluCall _call, Air_Unit_T_GPSInfo * _ref)
{
	Air_Unit_T_GPSInfo * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_GPSInfo *) malloc(sizeof(Air_Unit_T_GPSInfo));
	ilu::InputShortReal (_call, &_val->longitude);
	ilu::InputShortReal (_call, &_val->latitude);
	ilu::InputShortReal (_call, &_val->altitude);
	ilu::InputShortReal (_call, &_val->height);
	ilu::InputShortReal (_call, &_val->time);
	ilu::InputShortInteger (_call, &_val->health);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_GPSInfo (iluCall _call, Air_Unit_T_GPSInfo * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->longitude)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->latitude)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->altitude)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->height)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->time)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortInteger(_call, (_val->health)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_Pose3D (iluCall _call, Air_Unit_T_Pose3D * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->x)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->y)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->z)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->pitch)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->yaw)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->roll)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_Pose3D * Air_Unit_G::Input_Pose3D (iluCall _call, Air_Unit_T_Pose3D * _ref)
{
	Air_Unit_T_Pose3D * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_Pose3D *) malloc(sizeof(Air_Unit_T_Pose3D));
	ilu::InputShortReal (_call, &_val->x);
	ilu::InputShortReal (_call, &_val->y);
	ilu::InputShortReal (_call, &_val->z);
	ilu::InputShortReal (_call, &_val->pitch);
	ilu::InputShortReal (_call, &_val->yaw);
	ilu::InputShortReal (_call, &_val->roll);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_Pose3D (iluCall _call, Air_Unit_T_Pose3D * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->x)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->y)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->z)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->pitch)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->yaw)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->roll)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_GimbalState (iluCall _call, Air_Unit_T_GimbalState * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->yaw)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->roll)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->pitch)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_GimbalState * Air_Unit_G::Input_GimbalState (iluCall _call, Air_Unit_T_GimbalState * _ref)
{
	Air_Unit_T_GimbalState * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_GimbalState *) malloc(sizeof(Air_Unit_T_GimbalState));
	ilu::InputShortReal (_call, &_val->yaw);
	ilu::InputShortReal (_call, &_val->roll);
	ilu::InputShortReal (_call, &_val->pitch);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_GimbalState (iluCall _call, Air_Unit_T_GimbalState * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->yaw)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->roll)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->pitch)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

ilu_Boolean Air_Unit_G::Output_GimbalSpeed (iluCall _call, Air_Unit_T_GimbalSpeed * _val)
{
	if (!ilu::OutputRecord (_call))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->yaw)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->roll)))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) (_val->pitch)))
	  goto faild;
	ilu::EndRecord (_call);
	return 1;
faild:
	return 0;
}

Air_Unit_T_GimbalSpeed * Air_Unit_G::Input_GimbalSpeed (iluCall _call, Air_Unit_T_GimbalSpeed * _ref)
{
	Air_Unit_T_GimbalSpeed * _val;

	ilu::InputRecord(_call);
	if (_ref != NULL) _val = _ref; else _val = (Air_Unit_T_GimbalSpeed *) malloc(sizeof(Air_Unit_T_GimbalSpeed));
	ilu::InputShortReal (_call, &_val->yaw);
	ilu::InputShortReal (_call, &_val->roll);
	ilu::InputShortReal (_call, &_val->pitch);
	ilu::EndRecord(_call);
	return (_val);
}

ilu_Cardinal Air_Unit_G::SizeOf_GimbalSpeed (iluCall _call, Air_Unit_T_GimbalSpeed * _val)
{
	ilu_Cardinal _dSize, _argSize = 0;
	_argSize = ilu::SizeOfRecord (_call);
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->yaw)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->roll)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, (_val->pitch)));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	ilu::EndRecord(_call);
	return (_argSize);
faild:
	return 0;
}

_Air_Unit_T_TrapPointSeq_sequence::_Air_Unit_T_TrapPointSeq_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Air_Unit_T_TrapPointSeq_sequence::~_Air_Unit_T_TrapPointSeq_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Air_Unit_T_TrapPointSeq _Air_Unit_T_TrapPointSeq_sequence::Create (ilu_Cardinal initial_size, Air_Unit_T_TrapPoint3D *initial_data)
{
  Air_Unit_T_TrapPointSeq s = new _Air_Unit_T_TrapPointSeq_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Air_Unit_T_TrapPoint3D *) malloc((unsigned int)(sizeof(Air_Unit_T_TrapPoint3D) * (s->_maximum = initial_size)));
  return s;
}

void _Air_Unit_T_TrapPointSeq_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Air_Unit_T_TrapPoint3D *) 0;
  }
  _length = 0;
}

void _Air_Unit_T_TrapPointSeq_sequence::Append (Air_Unit_T_TrapPoint3D * item)
{
  if (_buffer == NULL) {
    _buffer = (Air_Unit_T_TrapPoint3D *) malloc ((unsigned int)(sizeof(Air_Unit_T_TrapPoint3D) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Air_Unit_T_TrapPoint3D *) realloc ((char *) _buffer, (unsigned int)(sizeof(Air_Unit_T_TrapPoint3D) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Air_Unit_T_TrapPoint3D * _Air_Unit_T_TrapPointSeq_sequence::RemoveHead ()
{
  static Air_Unit_T_TrapPoint3D k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Air_Unit_T_TrapPoint3D)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Air_Unit_T_TrapPoint3D *) 0);
}

Air_Unit_T_TrapPoint3D * _Air_Unit_T_TrapPointSeq_sequence::RemoveTail ()
{
  static Air_Unit_T_TrapPoint3D k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Air_Unit_T_TrapPoint3D *) 0);
}

ilu_Cardinal _Air_Unit_T_TrapPointSeq_sequence::RemoveAll (ilu_Boolean (*matchproc)(Air_Unit_T_TrapPoint3D *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Air_Unit_T_TrapPoint3D)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Air_Unit_T_TrapPoint3D * _Air_Unit_T_TrapPointSeq_sequence::Find (ilu_Boolean (*matchproc)(Air_Unit_T_TrapPoint3D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Air_Unit_T_TrapPoint3D *) 0);
}

void _Air_Unit_T_TrapPointSeq_sequence::Enumerate (void (*enumproc)(Air_Unit_T_TrapPoint3D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Air_Unit_T_TrapPointSeq_sequence::Length ()
{
  return _length;
}

Air_Unit_T_TrapPoint3D * _Air_Unit_T_TrapPointSeq_sequence::Array ()
{
  return _buffer;
}

Air_Unit_T_TrapPoint3D * _Air_Unit_T_TrapPointSeq_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Air_Unit_T_TrapPoint3D *) 0);
}

_Air_Unit_T_TaskPath_sequence::_Air_Unit_T_TaskPath_sequence ()
{
  _maximum = 0;
  _length = 0;
  _buffer = NULL;
}

_Air_Unit_T_TaskPath_sequence::~_Air_Unit_T_TaskPath_sequence ()
{
  if (_buffer != NULL) free((char *) _buffer);
};

Air_Unit_T_TaskPath _Air_Unit_T_TaskPath_sequence::Create (ilu_Cardinal initial_size, Air_Unit_T_Point3D *initial_data)
{
  Air_Unit_T_TaskPath s = new _Air_Unit_T_TaskPath_sequence;
  if (initial_data != NULL) {
    s->_buffer = initial_data;
    s->_length = initial_size;
    s->_maximum = initial_size;
  }
  else if (initial_size > 0)
    s->_buffer = (Air_Unit_T_Point3D *) malloc((unsigned int)(sizeof(Air_Unit_T_Point3D) * (s->_maximum = initial_size)));
  return s;
}

void _Air_Unit_T_TaskPath_sequence::Clear (ilu_Boolean free_contents)
{
  if (_buffer != NULL && free_contents) {
    free((char *) _buffer);
    _maximum = 0;
    _buffer = (Air_Unit_T_Point3D *) 0;
  }
  _length = 0;
}

void _Air_Unit_T_TaskPath_sequence::Append (Air_Unit_T_Point3D * item)
{
  if (_buffer == NULL) {
    _buffer = (Air_Unit_T_Point3D *) malloc ((unsigned int)(sizeof(Air_Unit_T_Point3D) * (_maximum = 20)));
  }
  else if (_maximum <= _length) {
    _maximum *= 2;
    _buffer = (Air_Unit_T_Point3D *) realloc ((char *) _buffer, (unsigned int)(sizeof(Air_Unit_T_Point3D) * _maximum));
  };
  _buffer[_length] = *item;
  _length += 1;
}

Air_Unit_T_Point3D * _Air_Unit_T_TaskPath_sequence::RemoveHead ()
{
  static Air_Unit_T_Point3D k;
  if (_length > 0) {
    k = _buffer[0];
    if (_length > 1)
      memmove (&_buffer[0], &_buffer[1], (int)((_length - 1) * sizeof(Air_Unit_T_Point3D)));
    _length -= 1;
    return (&k);
  }
  else
    return ((Air_Unit_T_Point3D *) 0);
}

Air_Unit_T_Point3D * _Air_Unit_T_TaskPath_sequence::RemoveTail ()
{
  static Air_Unit_T_Point3D k;
  if (_length > 0) {
    k = _buffer[_length-1];
    _length -= 1;
    return (&k);
  }
  else
    return ((Air_Unit_T_Point3D *) 0);
}

ilu_Cardinal _Air_Unit_T_TaskPath_sequence::RemoveAll (ilu_Boolean (*matchproc)(Air_Unit_T_Point3D *, void *), void *arg)
{
  ilu_Cardinal i, oldLength = _length;
  i = 0;
  while (i < _length)
    if ((*matchproc)(&_buffer[i], arg)) {
      memmove (&_buffer[i], &_buffer[i + 1], (int)((_length - i - 1) * sizeof(Air_Unit_T_Point3D)));
      _length -= 1;
    }
    else
      i += 1;
  return (oldLength - _length);
}

Air_Unit_T_Point3D * _Air_Unit_T_TaskPath_sequence::Find (ilu_Boolean (*matchproc)(Air_Unit_T_Point3D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    if ((*matchproc)(&_buffer[i], arg))
      return (&_buffer[i]);
  return ((Air_Unit_T_Point3D *) 0);
}

void _Air_Unit_T_TaskPath_sequence::Enumerate (void (*enumproc)(Air_Unit_T_Point3D *, void *), void *arg)
{
  register int i;
  for (i = 0;  i < _length;  i += 1)
    (*enumproc)(&_buffer[i], arg);
}

ilu_Cardinal _Air_Unit_T_TaskPath_sequence::Length ()
{
  return _length;
}

Air_Unit_T_Point3D * _Air_Unit_T_TaskPath_sequence::Array ()
{
  return _buffer;
}

Air_Unit_T_Point3D * _Air_Unit_T_TaskPath_sequence::Nth (ilu_Cardinal index)
{
  if (index < _length)
    return (&_buffer[index]);
  else
    return ((Air_Unit_T_Point3D *) 0);
}

ilu_Class Air_Unit_T_rpc::ILUClassRecord = NULL;

#define MethodRecord_Air_Unit_T_rpc_getCurrentSpeed ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 0)
#define MethodRecord_Air_Unit_T_rpc_getCurrentPose ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 1)
#define MethodRecord_Air_Unit_T_rpc_getCurrentInfo ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 2)
#define MethodRecord_Air_Unit_T_rpc_sendGimbalSpeed ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 3)
#define MethodRecord_Air_Unit_T_rpc_resetGimbal ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 4)
#define MethodRecord_Air_Unit_T_rpc_sendVehicleInfo ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 5)
#define MethodRecord_Air_Unit_T_rpc_reportTrap ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 6)
#define MethodRecord_Air_Unit_T_rpc_clearTraps ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 7)
#define MethodRecord_Air_Unit_T_rpc_getTraps ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 8)
#define MethodRecord_Air_Unit_T_rpc_setTrapPoint ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 9)
#define MethodRecord_Air_Unit_T_rpc_setTrack ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 10)
#define MethodRecord_Air_Unit_T_rpc_setTaskPath ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 11)
#define MethodRecord_Air_Unit_T_rpc_setTaskPoint ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 12)
#define MethodRecord_Air_Unit_T_rpc_clearTaskPoint ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 13)
#define MethodRecord_Air_Unit_T_rpc_obtainCtrlAuthority ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 14)
#define MethodRecord_Air_Unit_T_rpc_releaseCtrlAuthority ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 15)
#define MethodRecord_Air_Unit_T_rpc_setActionRole ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 16)
#define MethodRecord_Air_Unit_T_rpc_setActionMode ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 17)
#define MethodRecord_Air_Unit_T_rpc_setCruiseScope ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 18)
#define MethodRecord_Air_Unit_T_rpc_sendControlledVehicle ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 19)
#define MethodRecord_Air_Unit_T_rpc_confirmThrow ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 20)
#define MethodRecord_Air_Unit_T_rpc_cancelThrow ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 21)
#define MethodRecord_Air_Unit_T_rpc_actionThrow ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 22)
#define MethodRecord_Air_Unit_T_rpc_confirmFire ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 23)
#define MethodRecord_Air_Unit_T_rpc_cancelFire ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 24)
#define MethodRecord_Air_Unit_T_rpc_confirmFireLocation ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 25)
#define MethodRecord_Air_Unit_T_rpc_cancelFireLocation ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 26)
#define MethodRecord_Air_Unit_T_rpc_controlVehicleVelocity ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 27)
#define MethodRecord_Air_Unit_T_rpc_backHome ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 28)
#define MethodRecord_Air_Unit_T_rpc_setCruiseSpeed ((Air_Unit_T_rpc::ILUClassRecord)->cl_methods + 29)

class Air_Unit_T_rpc * Air_Unit_T_rpc::ILUCreateFromSBH (ilu_CString sbh)
{
	return (Air_Unit_T_rpc *) ilu::SBHToObject(sbh, Air_Unit_T_rpc::ILUClassRecord);
}

class Air_Unit_T_rpc * Air_Unit_T_rpc::ILUQuaT (class iluObject *from)
{
	return((class Air_Unit_T_rpc *) (from->ILUCastDown (Air_Unit_T_rpc::ILUClassRecord)));
}

void * Air_Unit_T_rpc::ILUCastDown (ilu_Class cast_to)
{
	if (cast_to == NULL)
		return((void *)((class iluObject *) this));
	else if (cast_to == Air_Unit_T_rpc::ILUClassRecord)
		return ((void *) this);
	else if (cast_to == Unit_T_rpc::ILUClassRecord)
		return ((void *)((class Unit_T_rpc *) this));
	else if (cast_to == ilu_T_CORBA_Object::ILUClassRecord)
		return ((void *)((class ilu_T_CORBA_Object *) this));
	else return (NULL);
}

Air_Unit_T_rpc::Air_Unit_T_rpc ()
{
	this->ILUInstanceClassRecord = Air_Unit_T_rpc::ILUClassRecord;
	this->ILUSetMostSpecificObject((void *) this);
}

Air_Unit_T_rpc::~Air_Unit_T_rpc ()
{
}

Air_Unit_T_Speed3D * Air_Unit_T_rpc::getCurrentSpeed (Air_UnitStatus *_status)
{
	Air_Unit_T_Speed3D * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_getCurrentSpeed))
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
		_retvalue = Air_Unit_G::Input_Speed3D (_call, NULL);
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

Air_Unit_T_Pose3D * Air_Unit_T_rpc::getCurrentPose (Air_UnitStatus *_status)
{
	Air_Unit_T_Pose3D * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_getCurrentPose))
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
		_retvalue = Air_Unit_G::Input_Pose3D (_call, NULL);
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

Air_Unit_T_AirUnitInfo * Air_Unit_T_rpc::getCurrentInfo (Air_UnitStatus *_status)
{
	Air_Unit_T_AirUnitInfo * _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_getCurrentInfo))
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
		_retvalue = Air_Unit_G::Input_AirUnitInfo (_call, NULL);
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

ilu_Boolean Air_Unit_T_rpc::sendGimbalSpeed (Air_UnitStatus *_status, Air_Unit_T_GimbalSpeed * speed)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_sendGimbalSpeed))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_GimbalSpeed (_call, (Air_Unit_T_GimbalSpeed *) speed));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_GimbalSpeed (_call, speed))
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

ilu_Boolean Air_Unit_T_rpc::resetGimbal (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_resetGimbal))
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

ilu_Boolean Air_Unit_T_rpc::sendVehicleInfo (Air_UnitStatus *_status, Air_Unit_T_AirUnitInfo * info)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_sendVehicleInfo))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_AirUnitInfo (_call, (Air_Unit_T_AirUnitInfo *) info));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_AirUnitInfo (_call, info))
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

ilu_Boolean Air_Unit_T_rpc::reportTrap (Air_UnitStatus *_status, Air_Unit_T_TrapPoint3D * trap)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_reportTrap))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_TrapPoint3D (_call, (Air_Unit_T_TrapPoint3D *) trap));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_TrapPoint3D (_call, trap))
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

ilu_Boolean Air_Unit_T_rpc::clearTraps (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_clearTraps))
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

Air_Unit_T_TrapPointSeq Air_Unit_T_rpc::getTraps (Air_UnitStatus *_status)
{
	Air_Unit_T_TrapPointSeq _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_getTraps))
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
		_retvalue = Air_Unit_G::Input_TrapPointSeq (_call, NULL);
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

ilu_Boolean Air_Unit_T_rpc::setTrapPoint (Air_UnitStatus *_status, Air_Unit_T_TrapPoint3D * trap)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setTrapPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_TrapPoint3D (_call, (Air_Unit_T_TrapPoint3D *) trap));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_TrapPoint3D (_call, trap))
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

ilu_Boolean Air_Unit_T_rpc::setTrack (Air_UnitStatus *_status, Air_Unit_T_TaskPath track)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setTrack))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_TaskPath (_call, (Air_Unit_T_TaskPath) track));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_TaskPath (_call, track))
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

ilu_Boolean Air_Unit_T_rpc::setTaskPath (Air_UnitStatus *_status, Air_Unit_T_TaskPath path)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setTaskPath))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_TaskPath (_call, (Air_Unit_T_TaskPath) path));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_TaskPath (_call, path))
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

ilu_Boolean Air_Unit_T_rpc::setTaskPoint (Air_UnitStatus *_status, Air_Unit_T_Point3D * point)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setTaskPoint))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_Point3D (_call, (Air_Unit_T_Point3D *) point));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_Point3D (_call, point))
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

ilu_Boolean Air_Unit_T_rpc::clearTaskPoint (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_clearTaskPoint))
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

ilu_Boolean Air_Unit_T_rpc::obtainCtrlAuthority (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_obtainCtrlAuthority))
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

ilu_Boolean Air_Unit_T_rpc::releaseCtrlAuthority (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_releaseCtrlAuthority))
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

ilu_Boolean Air_Unit_T_rpc::setActionRole (Air_UnitStatus *_status, Air_Unit_T_ActionRole ar)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setActionRole))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) ar));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) ar))
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

ilu_Boolean Air_Unit_T_rpc::setActionMode (Air_UnitStatus *_status, Air_Unit_T_ActionMode am)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setActionMode))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfEnum(_call, (ilu_ShortCardinal) am));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputEnum(_call, (unsigned short int) am))
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

ilu_Boolean Air_Unit_T_rpc::setCruiseScope (Air_UnitStatus *_status, Air_Unit_T_Site * s)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setCruiseScope))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Air_Unit_G::SizeOf_Site (_call, (Air_Unit_T_Site *) s));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Air_Unit_G::Output_Site (_call, s))
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

ilu_Boolean Air_Unit_T_rpc::sendControlledVehicle (Air_UnitStatus *_status, Unit_T_UnitSBHSeq uss)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_sendControlledVehicle))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = Unit_G::SizeOf_UnitSBHSeq (_call, (Unit_T_UnitSBHSeq) uss));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!Unit_G::Output_UnitSBHSeq (_call, uss))
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

ilu_Boolean Air_Unit_T_rpc::confirmThrow (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_confirmThrow))
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

ilu_Boolean Air_Unit_T_rpc::cancelThrow (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_cancelThrow))
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

ilu_Boolean Air_Unit_T_rpc::actionThrow (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_actionThrow))
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

ilu_Boolean Air_Unit_T_rpc::confirmFire (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_confirmFire))
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

ilu_Boolean Air_Unit_T_rpc::cancelFire (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_cancelFire))
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

ilu_Boolean Air_Unit_T_rpc::confirmFireLocation (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_confirmFireLocation))
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

ilu_Boolean Air_Unit_T_rpc::cancelFireLocation (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_cancelFireLocation))
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

ilu_Boolean Air_Unit_T_rpc::controlVehicleVelocity (Air_UnitStatus *_status, ilu_ShortReal vx, ilu_ShortReal vy, ilu_ShortReal vz, ilu_ShortReal angle)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_controlVehicleVelocity))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, vx));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, vy));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, vz));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, angle));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) vx))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) vy))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) vz))
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

ilu_Boolean Air_Unit_T_rpc::backHome (Air_UnitStatus *_status)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_backHome))
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

ilu_Boolean Air_Unit_T_rpc::setCruiseSpeed (Air_UnitStatus *_status, ilu_ShortReal cs)
{
	ilu_Boolean _retvalue;
	iluCall_s _call[1];
	ilu_Cardinal _dSize, _argSize = 0;
	ilu_ProtocolException _perror;
	ilu_Cardinal _scode;
	if (!ilu::StartCall (_call, this->ILUGetKernelServer(), Air_Unit_T_rpc::ILUClassRecord, MethodRecord_Air_Unit_T_rpc_setCruiseSpeed))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfObjectID(_call, this->ILUGetRPCObject(), ilu_TRUE, NULL));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	_argSize += (_dSize = ilu::SizeOfShortReal(_call, cs));
	if (ILU_ERRNOK(_call[0].err))
	  goto faild;
	if (!ilu::StartRequest (_call, _argSize))
	  goto faild;
	if (!ilu::OutputObjectID (_call, this->ILUGetRPCObject(), ilu_TRUE, NULL))
	  goto faild;
	if (!ilu::OutputShortReal(_call, (float) cs))
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

static class iluObject * Create_Air_Unit_T_rpc(ilu_KernelObject obj) {
	class Air_Unit_T_rpc *nobj = new Air_Unit_T_rpc;
	nobj->ILUSetRPCObject(obj);
	ilu::SetLanguageSpecificObject(obj, (class iluObject *) nobj);
	return ((class iluObject *) nobj);
}

/* the following is all done to achieve load-time module initialization.
   We declare a private class which only has one instance, statically declared.
   We use the constructor of the class to do all the initializations we need
   for the module, trusting that the single static instance of the class will
   be initialized before the user code is given control. */

class _Air_Unit_RegistrationClass {

 public:

  _Air_Unit_RegistrationClass();
};

#ifndef macintosh
static class _Air_Unit_RegistrationClass _Air_Unit_RegistrationInstance;
#endif

void Air_Unit__Initialize(void)
{
  static int initialized = 0;
  if (initialized)
    return;
  ilu::CheckStubConsistency("Air-Unit", "2.0beta1", "v2 (2.0beta1)");
  initialized = 1;

  ilu::EnterOTMu();
  {	// for definition of Air_Unit_T_rpc
    static ilu_CString Superclass_IDs[1] = {
	"IDL:Unit/rpc:1.0"
	};
    ilu_Class t;
    Air_Unit_T_rpc::ILUClassRecord = t = ilu::DefineObjectType(
	"Air-Unit.rpc",	/* ILU name */
	"",	/* Brand */
	"IDL:Air_Unit/rpc:1.0",	/* id */
	NULL,	/* singleton */
	ilu_kernelTRUE,	/* optional? */
	ilu_kernelFALSE,	/* collectible? */
	NULL,	/* authentication */
	30,	/* number of methods */
	1,	/* number of superclasses */
	Superclass_IDs	/* IDs of superclasses */);
    iluObject::RegisterSurrogateCreator(t, Create_Air_Unit_T_rpc);
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
	"IDL:Air_Unit/Speed3D:1.0");	//return type
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
	"IDL:Air_Unit/Pose3D:1.0");	//return type
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
	"IDL:Air_Unit/AirUnitInfo:1.0");	//return type
    }	//end method getCurrentInfo
    {	//for method sendGimbalSpeed
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	3,	//method index
	"sendGimbalSpeed",	//name
	4,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendGimbalSpeed
    {	//for method resetGimbal
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	4,	//method index
	"resetGimbal",	//name
	5,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method resetGimbal
    {	//for method sendVehicleInfo
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	5,	//method index
	"sendVehicleInfo",	//name
	6,	//method ID
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
	6,	//method index
	"reportTrap",	//name
	7,	//method ID
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
	7,	//method index
	"clearTraps",	//name
	8,	//method ID
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
	8,	//method index
	"getTraps",	//name
	9,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:f64M6WyJqOAUgQjEF7bfqsiJsHE");	//return type
    }	//end method getTraps
    {	//for method setTrapPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	9,	//method index
	"setTrapPoint",	//name
	10,	//method ID
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
	10,	//method index
	"setTrack",	//name
	11,	//method ID
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
	11,	//method index
	"setTaskPath",	//name
	12,	//method ID
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
	12,	//method index
	"setTaskPoint",	//name
	13,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setTaskPoint
    {	//for method clearTaskPoint
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	13,	//method index
	"clearTaskPoint",	//name
	14,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method clearTaskPoint
    {	//for method obtainCtrlAuthority
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	14,	//method index
	"obtainCtrlAuthority",	//name
	15,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method obtainCtrlAuthority
    {	//for method releaseCtrlAuthority
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	15,	//method index
	"releaseCtrlAuthority",	//name
	16,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method releaseCtrlAuthority
    {	//for method setActionRole
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	16,	//method index
	"setActionRole",	//name
	17,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setActionRole
    {	//for method setActionMode
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	17,	//method index
	"setActionMode",	//name
	18,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setActionMode
    {	//for method setCruiseScope
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	18,	//method index
	"setCruiseScope",	//name
	19,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setCruiseScope
    {	//for method sendControlledVehicle
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	19,	//method index
	"sendControlledVehicle",	//name
	20,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method sendControlledVehicle
    {	//for method confirmThrow
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	20,	//method index
	"confirmThrow",	//name
	21,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method confirmThrow
    {	//for method cancelThrow
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	21,	//method index
	"cancelThrow",	//name
	22,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method cancelThrow
    {	//for method actionThrow
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	22,	//method index
	"actionThrow",	//name
	23,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method actionThrow
    {	//for method confirmFire
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	23,	//method index
	"confirmFire",	//name
	24,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method confirmFire
    {	//for method cancelFire
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	24,	//method index
	"cancelFire",	//name
	25,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method cancelFire
    {	//for method confirmFireLocation
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	25,	//method index
	"confirmFireLocation",	//name
	26,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method confirmFireLocation
    {	//for method cancelFireLocation
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	26,	//method index
	"cancelFireLocation",	//name
	27,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method cancelFireLocation
    {	//for method controlVehicleVelocity
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	27,	//method index
	"controlVehicleVelocity",	//name
	28,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	4,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method controlVehicleVelocity
    {	//for method backHome
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	28,	//method index
	"backHome",	//name
	29,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	0,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method backHome
    {	//for method setCruiseSpeed
      ilu_Exception *exns = NULL;
      ilu::DefineMethod(t,
	29,	//method index
	"setCruiseSpeed",	//name
	30,	//method ID
	ilu_kernelFALSE,	//cacheable
	ilu_kernelFALSE,	//asynchronous
	0,	//num. exns
	exns,	//the exceptions
	1,	//num. args
	"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I");	//return type
    }	//end method setCruiseSpeed
    ilu::ObjectTypeDefined(t);
  }	// end definition of Air_Unit_T_rpc
  ilu::ExitOTMu();
}

_Air_Unit_RegistrationClass::_Air_Unit_RegistrationClass()
{
	Air_Unit__Initialize();
}

