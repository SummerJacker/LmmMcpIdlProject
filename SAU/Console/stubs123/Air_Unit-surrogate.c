/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Thu Jul 24 14:42:41 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/SAU/project/SAU/ilu/bin/c-stubber.EXE" of Thu Jul 10 17:58:46 2025
 * on "D:/SAU/project/SAU/Interfaces/air_unit.idl" of Fri Jul 18 15:18:31 2025,
 * and "D:/SAU/project/SAU/ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/SAU/project/SAU/Interfaces/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Air_Unit.h"

Air_Unit_Speed3D _Air_Unit_rpc_getCurrentSpeed__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_Speed3D _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Air_Unit_Speed3D;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Air_Unit_Pose3D _Air_Unit_rpc_getCurrentPose__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_Pose3D _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Air_Unit_Pose3D;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Air_Unit_AirUnitInfo* _Air_Unit_rpc_getCurrentInfo__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_AirUnitInfo* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Air_Unit_AirUnitInfo;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_sendGimbalSpeed__clientstub (Air_Unit_rpc _handle, Air_Unit_GimbalSpeed* speed, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_GimbalSpeed;
  __parmsBlock[1].parm_val  = (void *) speed;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_resetGimbal__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_sendVehicleInfo__clientstub (Air_Unit_rpc _handle, Air_Unit_AirUnitInfo* info, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_AirUnitInfo;
  __parmsBlock[1].parm_val  = (void *) info;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_reportTrap__clientstub (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_TrapPoint3D;
  __parmsBlock[1].parm_val  = (void *) trap;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_clearTraps__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[7],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Air_Unit_TrapPointSeq* _Air_Unit_rpc_getTraps__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Air_Unit_TrapPointSeq* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Air_Unit_TrapPointSeq;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[8],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setTrapPoint__clientstub (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_TrapPoint3D;
  __parmsBlock[1].parm_val  = (void *) trap;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[9],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setTrack__clientstub (Air_Unit_rpc _handle, Air_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_TaskPath;
  __parmsBlock[1].parm_val  = (void *) track;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[10],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setTaskPath__clientstub (Air_Unit_rpc _handle, Air_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_TaskPath;
  __parmsBlock[1].parm_val  = (void *) path;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[11],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setTaskPoint__clientstub (Air_Unit_rpc _handle, Air_Unit_Point3D* point, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_Point3D;
  __parmsBlock[1].parm_val  = (void *) point;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[12],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_clearTaskPoint__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[13],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_obtainCtrlAuthority__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[14],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_releaseCtrlAuthority__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[15],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setActionRole__clientstub (Air_Unit_rpc _handle, Air_Unit_ActionRole ar, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_ActionRole;
  __parmsBlock[1].parm_val  = (void *) &ar;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[16],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setActionMode__clientstub (Air_Unit_rpc _handle, Air_Unit_ActionMode am, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_ActionMode;
  __parmsBlock[1].parm_val  = (void *) &am;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[17],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setCruiseScope__clientstub (Air_Unit_rpc _handle, Air_Unit_Site* s, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Air_Unit_Site;
  __parmsBlock[1].parm_val  = (void *) s;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[18],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_sendControlledVehicle__clientstub (Air_Unit_rpc _handle, Unit_UnitSBHSeq* uss, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_Unit_UnitSBHSeq;
  __parmsBlock[1].parm_val  = (void *) uss;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[19],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_confirmThrow__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[20],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_cancelThrow__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[21],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_actionThrow__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[22],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_confirmFire__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[23],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_cancelFire__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[24],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_confirmFireLocation__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[25],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_cancelFireLocation__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[26],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_controlVehicleVelocity__clientstub (Air_Unit_rpc _handle, CORBA_float vx, CORBA_float vy, CORBA_float vz, CORBA_float angle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[5];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_float;
  __parmsBlock[1].parm_val  = (void *) &vx;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_float;
  __parmsBlock[2].parm_val  = (void *) &vy;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_float;
  __parmsBlock[3].parm_val  = (void *) &vz;
  __parmsBlock[4].parm_in  = 1;
  __parmsBlock[4].parm_out = 0;
  __parmsBlock[4].parm_needs_assignment   = 0;
  __parmsBlock[4].parm_needs_dereference  = 0;
  __parmsBlock[4].parm_type = TC_CORBA_float;
  __parmsBlock[4].parm_val  = (void *) &angle;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[27],
                     ILU_NIL, _handle, _status, 5, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_backHome__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[28],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Air_Unit_rpc_setCruiseSpeed__clientstub (Air_Unit_rpc _handle, CORBA_float cs, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_float;
  __parmsBlock[1].parm_val  = (void *) &cs;
  _ILU_C_VectorCall (_Air_Unit_rpc__ILUType, &_Air_Unit_rpc__ILUType->cl_methods[29],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Air_Unit_rpc__SurrogateClass = 0;
Air_Unit_rpc Air_Unit_rpc__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Air_Unit_rpc) (ILU_C_SBHToObject(sbh, _Air_Unit_rpc__ILUType, env));
}

void Air_Unit__Initialize(void)
{
  extern void _Air_Unit__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  Unit__Initialize();
  _Air_Unit__GeneralInitialization();
  _Air_Unit_rpc__SurrogateClass = Air_Unit_rpc__MakeClass(
    _Air_Unit_rpc_getCurrentSpeed__clientstub,
    _Air_Unit_rpc_getCurrentPose__clientstub,
    _Air_Unit_rpc_getCurrentInfo__clientstub,
    _Air_Unit_rpc_sendGimbalSpeed__clientstub,
    _Air_Unit_rpc_resetGimbal__clientstub,
    _Air_Unit_rpc_sendVehicleInfo__clientstub,
    _Air_Unit_rpc_reportTrap__clientstub,
    _Air_Unit_rpc_clearTraps__clientstub,
    _Air_Unit_rpc_getTraps__clientstub,
    _Air_Unit_rpc_setTrapPoint__clientstub,
    _Air_Unit_rpc_setTrack__clientstub,
    _Air_Unit_rpc_setTaskPath__clientstub,
    _Air_Unit_rpc_setTaskPoint__clientstub,
    _Air_Unit_rpc_clearTaskPoint__clientstub,
    _Air_Unit_rpc_obtainCtrlAuthority__clientstub,
    _Air_Unit_rpc_releaseCtrlAuthority__clientstub,
    _Air_Unit_rpc_setActionRole__clientstub,
    _Air_Unit_rpc_setActionMode__clientstub,
    _Air_Unit_rpc_setCruiseScope__clientstub,
    _Air_Unit_rpc_sendControlledVehicle__clientstub,
    _Air_Unit_rpc_confirmThrow__clientstub,
    _Air_Unit_rpc_cancelThrow__clientstub,
    _Air_Unit_rpc_actionThrow__clientstub,
    _Air_Unit_rpc_confirmFire__clientstub,
    _Air_Unit_rpc_cancelFire__clientstub,
    _Air_Unit_rpc_confirmFireLocation__clientstub,
    _Air_Unit_rpc_cancelFireLocation__clientstub,
    _Air_Unit_rpc_controlVehicleVelocity__clientstub,
    _Air_Unit_rpc_backHome__clientstub,
    _Air_Unit_rpc_setCruiseSpeed__clientstub,
    _Unit_rpc_getID__clientstub,
    _Unit_rpc_getCosNamingSBH__clientstub,
    _Unit_rpc_getFrontUnitInfo__clientstub,
    _Unit_rpc_setRole__clientstub,
    _Unit_rpc_setMode__clientstub,
    _Unit_rpc_setMinorMode__clientstub,
    _Unit_rpc_sendMoveAction__clientstub,
    _Unit_rpc_sendMoveActionSeq__clientstub,
    _Unit_rpc_setALeader__clientstub,
    _Unit_rpc_unregisterFollower__clientstub,
    _Unit_rpc_setFollower__clientstub,
    _Unit_rpc_unsetFollower__clientstub,
    _Unit_rpc_addRearVehicle__clientstub,
    _Unit_rpc_deleteRearVehicle__clientstub,
    _Unit_rpc_setFormation__clientstub,
    _Unit_rpc_setRearVehicles__clientstub,
    _Unit_rpc_reportDeadVehicle__clientstub,
    _Unit_rpc_shutDown__clientstub,
    _Unit_rpc_startPhotoStream__clientstub,
    _Unit_rpc_stopPhotoStream__clientstub,
    _Unit_rpc_takePicture__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Air_Unit_rpc__ILUType,
	_Air_Unit_rpc__SurrogateClass);
  return;
}
