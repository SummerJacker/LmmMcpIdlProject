/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:29:23 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/monitor.idl" of Wed Jul 16 16:43:00 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "Monitor.h"

CORBA_boolean _Monitor_rpc_sendUnitInfo__clientstub (Monitor_rpc _handle, Monitor_CompleteUnitInfo* unitInfo, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Monitor_CompleteUnitInfo;
  __parmsBlock[1].parm_val  = (void *) unitInfo;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Monitor_rpc_sendTrapPoint__clientstub (Monitor_rpc _handle, Console_TrapPoint* tp, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_Console_TrapPoint;
  __parmsBlock[1].parm_val  = (void *) tp;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Monitor_rpc_sendTargetLocation__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, Ground_Unit_Point2D* fp, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
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
  __parmsBlock[1].parm_type = TC_Monitor_TargetID;
  __parmsBlock[1].parm_val  = (void *) fid;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Ground_Unit_Point2D;
  __parmsBlock[2].parm_val  = (void *) fp;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_short;
  __parmsBlock[3].parm_val  = (void *) &responseTime;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Monitor_rpc_foundTarget__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_PictureInfo* pi, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
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
  __parmsBlock[1].parm_type = TC_Monitor_TargetID;
  __parmsBlock[1].parm_val  = (void *) fid;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Monitor_PictureInfo;
  __parmsBlock[2].parm_val  = (void *) pi;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Monitor_rpc_confirmAction__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
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
  __parmsBlock[1].parm_type = TC_Monitor_TargetID;
  __parmsBlock[1].parm_val  = (void *) fid;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_short;
  __parmsBlock[2].parm_val  = (void *) &responseTime;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Monitor_rpc_backHome__clientstub (Monitor_rpc _handle, Unit_UnitID uid, Monitor_BackHomeReason bhr, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
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
  __parmsBlock[1].parm_type = TC_Unit_UnitID;
  __parmsBlock[1].parm_val  = (void *) uid;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Monitor_BackHomeReason;
  __parmsBlock[2].parm_val  = (void *) &bhr;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Monitor_rpc_sendMissionState__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_MissionSituation ms, ILU_C_ENVIRONMENT *_status)
{
  CORBA_boolean _retvalue;
  _ILU_C_ParmDesc __parmsBlock[3];
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
  __parmsBlock[1].parm_type = TC_Monitor_TargetID;
  __parmsBlock[1].parm_val  = (void *) fid;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Monitor_MissionSituation;
  __parmsBlock[2].parm_val  = (void *) &ms;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[6],
                     ILU_NIL, _handle, _status, 3, __parmsBlock);
  return _retvalue;
}

CORBA_boolean _Monitor_rpc_sendPicture__clientstub (Monitor_rpc _handle, ilu_CString pictureName, Monitor_PictureFlow* pic, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status)
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
  __parmsBlock[1].parm_type = TC_ilu_CString;
  __parmsBlock[1].parm_val  = (void *) pictureName;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_Monitor_PictureFlow;
  __parmsBlock[2].parm_val  = (void *) pic;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_long;
  __parmsBlock[3].parm_val  = (void *) &time;
  __parmsBlock[4].parm_in  = 1;
  __parmsBlock[4].parm_out = 0;
  __parmsBlock[4].parm_needs_assignment   = 0;
  __parmsBlock[4].parm_needs_dereference  = 0;
  __parmsBlock[4].parm_type = TC_CORBA_long;
  __parmsBlock[4].parm_val  = (void *) &procedureStartTime;
  _ILU_C_VectorCall (_Monitor_rpc__ILUType, &_Monitor_rpc__ILUType->cl_methods[7],
                     ILU_NIL, _handle, _status, 5, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _Monitor_rpc__SurrogateClass = 0;
Monitor_rpc Monitor_rpc__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (Monitor_rpc) (ILU_C_SBHToObject(sbh, _Monitor_rpc__ILUType, env));
}

void Monitor__Initialize(void)
{
  extern void _Monitor__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  Ground_Unit__Initialize();
  Air_Unit__Initialize();
  Console__Initialize();
  Unit__Initialize();
  _Monitor__GeneralInitialization();
  _Monitor_rpc__SurrogateClass = Monitor_rpc__MakeClass(
    _Monitor_rpc_sendUnitInfo__clientstub,
    _Monitor_rpc_sendTrapPoint__clientstub,
    _Monitor_rpc_sendTargetLocation__clientstub,
    _Monitor_rpc_foundTarget__clientstub,
    _Monitor_rpc_confirmAction__clientstub,
    _Monitor_rpc_backHome__clientstub,
    _Monitor_rpc_sendMissionState__clientstub,
    _Monitor_rpc_sendPicture__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_Monitor_rpc__ILUType,
	_Monitor_rpc__SurrogateClass);
  return;
}
