/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:29:14 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Ground_Unit.h"

Ground_Unit_Speed2D _Ground_Unit_rpc_getCurrentSpeed__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_Speed2D _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Ground_Unit_Speed2D;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Ground_Unit_Pose2D _Ground_Unit_rpc_getCurrentPose__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_Pose2D _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Ground_Unit_Pose2D;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Ground_Unit_GroundUnitInfo* _Ground_Unit_rpc_getCurrentInfo__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_GroundUnitInfo* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Ground_Unit_GroundUnitInfo;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Ground_Unit_rpc_sendVehicleInfo__clientstub (Ground_Unit_rpc _handle, Ground_Unit_GroundUnitInfo* info, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Ground_Unit_GroundUnitInfo;
  __parmsBlock[1].parm_val  = (void *) info;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Ground_Unit_rpc_reportTrap__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Ground_Unit_TrapPoint2D;
  __parmsBlock[1].parm_val  = (void *) trap;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Ground_Unit_rpc_clearTraps__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_boolean;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

Ground_Unit_TrapPointSeq* _Ground_Unit_rpc_getTraps__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status)
{
  Ground_Unit_TrapPointSeq* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_Ground_Unit_TrapPointSeq;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Ground_Unit_rpc_setTrapPoint__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Ground_Unit_TrapPoint2D;
  __parmsBlock[1].parm_val  = (void *) trap;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[7],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Ground_Unit_rpc_setTrack__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Ground_Unit_TaskPath;
  __parmsBlock[1].parm_val  = (void *) track;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[8],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Ground_Unit_rpc_setTaskPath__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Ground_Unit_TaskPath;
  __parmsBlock[1].parm_val  = (void *) path;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[9],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Ground_Unit_rpc_setTaskPoint__clientstub (Ground_Unit_rpc _handle, Ground_Unit_Point2D* point, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Ground_Unit_Point2D;
  __parmsBlock[1].parm_val  = (void *) point;
  _ILU_C_VectorCall (_Ground_Unit_rpc__ILUType, &_Ground_Unit_rpc__ILUType->cl_methods[10],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Ground_Unit_rpc__SurrogateClass = 0;
Ground_Unit_rpc Ground_Unit_rpc__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Ground_Unit_rpc) (ILU_C_SBHToObject(sbh, _Ground_Unit_rpc__ILUType, env));
}

void Ground_Unit__Initialize(void)
{
  extern void _Ground_Unit__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  Unit__Initialize();
  _Ground_Unit__GeneralInitialization();
  _Ground_Unit_rpc__SurrogateClass = Ground_Unit_rpc__MakeClass(
    _Ground_Unit_rpc_getCurrentSpeed__clientstub,
    _Ground_Unit_rpc_getCurrentPose__clientstub,
    _Ground_Unit_rpc_getCurrentInfo__clientstub,
    _Ground_Unit_rpc_sendVehicleInfo__clientstub,
    _Ground_Unit_rpc_reportTrap__clientstub,
    _Ground_Unit_rpc_clearTraps__clientstub,
    _Ground_Unit_rpc_getTraps__clientstub,
    _Ground_Unit_rpc_setTrapPoint__clientstub,
    _Ground_Unit_rpc_setTrack__clientstub,
    _Ground_Unit_rpc_setTaskPath__clientstub,
    _Ground_Unit_rpc_setTaskPoint__clientstub,
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
  _ILU_C_RegisterSurrogateCType (_Ground_Unit_rpc__ILUType,
	_Ground_Unit_rpc__SurrogateClass);
  return;
}
