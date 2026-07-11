/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:28:58 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Console_h_
#define __Console_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "Ground_Unit.h"
#include "Air_Unit.h"
#include "Unit.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             Console                              ***/
/************************************************************************/
/************************************************************************/

extern void Console__Initialize(void);
extern void Console__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Console_rpc;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct Console_UnbindData Console_UnbindData;
typedef struct _Console_TrapPoint_union Console_TrapPoint;
typedef struct _Console_Message_union Console_Message;
typedef struct _Console_Point_union Console_Point;
typedef enum {Console_OneLine = 0, Console_Matrix = 1, Console_WildGoose = 2} Console_FormationType;
typedef enum {Console_RouteTrack = 0, Console_ObjectTrack = 1} Console_TrackMode;
typedef enum {Console_FormationImplement = 0, Console_FormationSuspend = 1, Console_FormationSuccess = 2, Console_FormationFail = 3} Console_FormationState;
typedef enum {Console_MssionImplement = 0, Console_MissionSuspend = 1, Console_MissionSuccess = 2, Console_MissionFail = 3, Console_MissionCancel = 4} Console_MissionState;
typedef struct _Console_PointSeq__sequence Console_PointSeq;
typedef struct _Console_MissionStateData_union Console_MissionStateData;
typedef struct _Console_TrapPointSeq__sequence Console_TrapPointSeq;
typedef enum {Console_OP_SetCosInfo = 0, Console_OP_Bind = 1, Console_OP_Unbind = 2, Console_OP_Opened = 3, Console_OP_Closed = 4, Console_OP_ReportTrap = 5, Console_OP_AddTrap = 6} Console_Operation;
typedef enum {Console_TrapGroundType = 0, Console_TrapAirType = 1} Console_TrapType;
typedef enum {Console_PointGroundType = 0, Console_PointAirType = 1} Console_PointType;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* record "Console_UnbindData" */
struct Console_UnbindData {
	Unit_UnitID uid;
	ilu_CString details;
};
Console_UnbindData *
  CORBA_sequence_Console_UnbindData_allocbuf (CORBA_unsigned_long /* count */);

/* union "Console_TrapPoint" */

struct _Console_TrapPoint_union {
	Console_TrapType _d;
	union {
		Ground_Unit_TrapPoint2D trapPoint2D;	/* Console_TrapGroundType */
		Air_Unit_TrapPoint3D trapPoint3D;	/* Console_TrapAirType */
	} _u;
};
Console_TrapPoint *
  CORBA_sequence_Console_TrapPoint_allocbuf (CORBA_unsigned_long /* count */);

/* union "Console_Message" */

struct _Console_Message_union {
	Console_Operation _d;
	union {
		Unit_UnitInfoSeq infoSeq;	/* Console_OP_SetCosInfo */
		Unit_UnitInfo bindInfo;	/* Console_OP_Bind */
		Console_UnbindData unbindInfo;	/* Console_OP_Unbind */
		Console_TrapPoint tp;	/* Console_OP_ReportTrap, Console_OP_AddTrap */
		ilu_CString details;	/* Console_OP_Opened, Console_OP_Closed */
	} _u;
};
Console_Message *
  CORBA_sequence_Console_Message_allocbuf (CORBA_unsigned_long /* count */);

/* union "Console_Point" */

struct _Console_Point_union {
	Console_PointType _d;
	union {
		Ground_Unit_Point2D p2D;	/* Console_PointGroundType */
		Air_Unit_Point3D p3D;	/* Console_PointAirType */
	} _u;
};
Console_Point *
  CORBA_sequence_Console_Point_allocbuf (CORBA_unsigned_long /* count */);

Console_FormationType *
  CORBA_sequence_Console_FormationType_allocbuf (CORBA_unsigned_long /* count */);

Console_TrackMode *
  CORBA_sequence_Console_TrackMode_allocbuf (CORBA_unsigned_long /* count */);

Console_FormationState *
  CORBA_sequence_Console_FormationState_allocbuf (CORBA_unsigned_long /* count */);

Console_MissionState *
  CORBA_sequence_Console_MissionState_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Console_PointSeq" */
struct _Console_PointSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Console_Point *_buffer;
};
void Console_PointSeq_Every (Console_PointSeq *h, void (*f)(Console_Point*, void *, ilu_Error *), void *);
void Console_PointSeq_Append (Console_PointSeq *h, Console_Point* item, ilu_Error *);
void Console_PointSeq_Push (Console_PointSeq *h, Console_Point* item);
void Console_PointSeq_Pop (Console_PointSeq *h, Console_Point* item);
CORBA_unsigned_long Console_PointSeq_Length (Console_PointSeq *);
Console_Point * Console_PointSeq_Nth (Console_PointSeq *, CORBA_unsigned_long);
Console_PointSeq * Console_PointSeq_Create (CORBA_unsigned_long /* size */, Console_Point*  /* init val */);
void Console_PointSeq_Init (Console_PointSeq * /* seq */, CORBA_unsigned_long /* size */, Console_Point*  /* init val */);
Console_PointSeq *
  CORBA_sequence_Console_PointSeq_allocbuf (CORBA_unsigned_long /* count */);

/* union "Console_MissionStateData" */

struct _Console_MissionStateData_union {
	Console_MissionState _d;
	union {
		CORBA_short time;	/* Console_MissionSuspend */
	} _u;
};
Console_MissionStateData *
  CORBA_sequence_Console_MissionStateData_allocbuf (CORBA_unsigned_long /* count */);

Console_rpc *
  CORBA_sequence_Console_rpc_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Console_TrapPointSeq" */
struct _Console_TrapPointSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Console_TrapPoint *_buffer;
};
void Console_TrapPointSeq_Every (Console_TrapPointSeq *h, void (*f)(Console_TrapPoint*, void *, ilu_Error *), void *);
void Console_TrapPointSeq_Append (Console_TrapPointSeq *h, Console_TrapPoint* item, ilu_Error *);
void Console_TrapPointSeq_Push (Console_TrapPointSeq *h, Console_TrapPoint* item);
void Console_TrapPointSeq_Pop (Console_TrapPointSeq *h, Console_TrapPoint* item);
CORBA_unsigned_long Console_TrapPointSeq_Length (Console_TrapPointSeq *);
Console_TrapPoint * Console_TrapPointSeq_Nth (Console_TrapPointSeq *, CORBA_unsigned_long);
Console_TrapPointSeq * Console_TrapPointSeq_Create (CORBA_unsigned_long /* size */, Console_TrapPoint*  /* init val */);
void Console_TrapPointSeq_Init (Console_TrapPointSeq * /* seq */, CORBA_unsigned_long /* size */, Console_TrapPoint*  /* init val */);
Console_TrapPointSeq *
  CORBA_sequence_Console_TrapPointSeq_allocbuf (CORBA_unsigned_long /* count */);

Console_Operation *
  CORBA_sequence_Console_Operation_allocbuf (CORBA_unsigned_long /* count */);

Console_TrapType *
  CORBA_sequence_Console_TrapType_allocbuf (CORBA_unsigned_long /* count */);

Console_PointType *
  CORBA_sequence_Console_PointType_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*======================== exceptions ==================================*/

extern ILU_C_ExceptionCode _Console__Exception_rpc_AlreadyBind;
#define ex_Console_rpc_AlreadyBind _Console__Exception_rpc_AlreadyBind
extern ILU_C_ExceptionCode _Console__Exception_rpc_NotFound;
#define ex_Console_rpc_NotFound _Console__Exception_rpc_NotFound


/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Console_rpc"  -------------------------------------*/

#define Console_rpc__MSType _Console_rpc__ILUType

Console_rpc
  Console_rpc__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Console_rpc__SetUserData (Console_rpc /* self */, void * /* userData */);
void *
  Console_rpc__GetUserData (Console_rpc /* self */);

extern Console_rpc
  Console_rpc__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Console_rpc class */

extern Console_rpc
  Console_rpc__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Unit_UnitInfoSeq* server_Console_rpc_getCosNamingInfo (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_sendMsg (Console_rpc _handle, Console_Message* m, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_bind (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_unbind (Console_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_rebind (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setNickname (Console_rpc _handle, Unit_UnitInfo* uinfo, ilu_CString newName, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setPosition (Console_rpc _handle, ilu_CString name, Console_Point* p, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_addGoalPoint (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setGoalPoint (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setRole (Console_rpc _handle, Unit_UnitInfo* uinfo, Unit_UnitRole r, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_cancelRole (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setTrapPoint (Console_rpc _handle, Console_TrapPoint* p, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setFollow (Console_rpc _handle, Unit_UnitInfo* uinfo1, Unit_UnitInfo* uinfo2, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setFormationType (Console_rpc _handle, Console_FormationType f, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setTrackMode (Console_rpc _handle, Console_TrackMode tm, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitInfo* server_Console_rpc_getCurrentUnit (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_short server_Console_rpc_getUnitNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_short server_Console_rpc_getFormationNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_short server_Console_rpc_getTrapNum (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Console_FormationType server_Console_rpc_getFormationType (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Console_FormationState server_Console_rpc_getFormationState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Console_MissionState server_Console_rpc_getMissionState (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Console_Point server_Console_rpc_getUnitPoint (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitInfo* server_Console_rpc_getByName (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status);

extern Console_Point server_Console_rpc_getLeaderPoint (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Console_PointSeq* server_Console_rpc_getPointSeq (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_cancelFormation (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setLeaderSuspend (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_recoveryLeaderAction (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_addUnitFormation (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_deleteUnitFormation (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setUnitFault (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setUnitFaultPosition (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setFormationState (Console_rpc _handle, Console_FormationState fs, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Console_rpc_setMissionState (Console_rpc _handle, Console_MissionStateData* msd, ILU_C_ENVIRONMENT *_status);

extern void Console_rpc__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Console_rpc__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Console_rpc__MakeClass(
  Unit_UnitInfoSeq* (*Console_rpc_getCosNamingInfo__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_sendMsg__Impl)
     (Console_rpc _handle, Console_Message* m, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_bind__Impl)
     (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_unbind__Impl)
     (Console_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_rebind__Impl)
     (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setNickname__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ilu_CString newName, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setPosition__Impl)
     (Console_rpc _handle, ilu_CString name, Console_Point* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_addGoalPoint__Impl)
     (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setGoalPoint__Impl)
     (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setRole__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, Unit_UnitRole r, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_cancelRole__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setTrapPoint__Impl)
     (Console_rpc _handle, Console_TrapPoint* p, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setFollow__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo1, Unit_UnitInfo* uinfo2, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setFormationType__Impl)
     (Console_rpc _handle, Console_FormationType f, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setTrackMode__Impl)
     (Console_rpc _handle, Console_TrackMode tm, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Console_rpc_getCurrentUnit__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*Console_rpc_getUnitNum__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*Console_rpc_getFormationNum__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_short (*Console_rpc_getTrapNum__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_FormationType (*Console_rpc_getFormationType__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_FormationState (*Console_rpc_getFormationState__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_MissionState (*Console_rpc_getMissionState__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_Point (*Console_rpc_getUnitPoint__Impl)
     (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Console_rpc_getByName__Impl)
     (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status),
  Console_Point (*Console_rpc_getLeaderPoint__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Console_PointSeq* (*Console_rpc_getPointSeq__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_cancelFormation__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setLeaderSuspend__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_recoveryLeaderAction__Impl)
     (Console_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_addUnitFormation__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_deleteUnitFormation__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setUnitFault__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setUnitFaultPosition__Impl)
     (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setFormationState__Impl)
     (Console_rpc _handle, Console_FormationState fs, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Console_rpc_setMissionState__Impl)
     (Console_rpc _handle, Console_MissionStateData* msd, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Unit_UnitInfoSeq*
  Console_rpc_getCosNamingInfo (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_sendMsg (Console_rpc, Console_Message*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean  /* exceptions:  rpc-AlreadyBind */
  Console_rpc_bind (Console_rpc, Unit_UnitID, Unit_UnitSBH, ILU_C_ENVIRONMENT *);

extern CORBA_boolean  /* exceptions:  rpc-NotFound */
  Console_rpc_unbind (Console_rpc, Unit_UnitID, ilu_CString, ILU_C_ENVIRONMENT *);

extern CORBA_boolean  /* exceptions:  rpc-NotFound */
  Console_rpc_rebind (Console_rpc, Unit_UnitID, Unit_UnitSBH, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setNickname (Console_rpc, Unit_UnitInfo*, ilu_CString, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setPosition (Console_rpc, ilu_CString, Console_Point*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_addGoalPoint (Console_rpc, Console_Point*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setGoalPoint (Console_rpc, Console_Point*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setRole (Console_rpc, Unit_UnitInfo*, Unit_UnitRole, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_cancelRole (Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setTrapPoint (Console_rpc, Console_TrapPoint*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setFollow (Console_rpc, Unit_UnitInfo*, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setFormationType (Console_rpc, Console_FormationType, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setTrackMode (Console_rpc, Console_TrackMode, ILU_C_ENVIRONMENT *);

extern Unit_UnitInfo*
  Console_rpc_getCurrentUnit (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_short
  Console_rpc_getUnitNum (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_short
  Console_rpc_getFormationNum (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_short
  Console_rpc_getTrapNum (Console_rpc, ILU_C_ENVIRONMENT *);

extern Console_FormationType
  Console_rpc_getFormationType (Console_rpc, ILU_C_ENVIRONMENT *);

extern Console_FormationState
  Console_rpc_getFormationState (Console_rpc, ILU_C_ENVIRONMENT *);

extern Console_MissionState
  Console_rpc_getMissionState (Console_rpc, ILU_C_ENVIRONMENT *);

extern Console_Point
  Console_rpc_getUnitPoint (Console_rpc, ilu_CString, ILU_C_ENVIRONMENT *);

extern Unit_UnitInfo*
  Console_rpc_getByName (Console_rpc, ilu_CString, ILU_C_ENVIRONMENT *);

extern Console_Point
  Console_rpc_getLeaderPoint (Console_rpc, ILU_C_ENVIRONMENT *);

extern Console_PointSeq*
  Console_rpc_getPointSeq (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_cancelFormation (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setLeaderSuspend (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_recoveryLeaderAction (Console_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_addUnitFormation (Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_deleteUnitFormation (Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setUnitFault (Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setUnitFaultPosition (Console_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setFormationState (Console_rpc, Console_FormationState, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Console_rpc_setMissionState (Console_rpc, Console_MissionStateData*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Console__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Console_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Console_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Console_rpc__IoFns;
#define TC_Console_rpc (& _Console_rpc__IoFns)
extern void Console_rpc__Free (Console_rpc*);
extern struct _ILU_C_IoFnsRegistration_s _Console_TrapPointSeq__IoFns;
#define TC_Console_TrapPointSeq (& _Console_TrapPointSeq__IoFns)
extern void _Console_TrapPointSeq__Output (ilu_Call, Console_TrapPointSeq*, ilu_Error *);
extern ilu_cardinal _Console_TrapPointSeq__SizeOf (ilu_Call, Console_TrapPointSeq*, ilu_Error *);
extern Console_TrapPointSeq* _Console_TrapPointSeq__Input (ilu_Call, Console_TrapPointSeq*, ilu_Error *);
extern void Console_TrapPointSeq__Free (Console_TrapPointSeq*);
Console_TrapPointSeq* Console_TrapPointSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Console_PointSeq__IoFns;
#define TC_Console_PointSeq (& _Console_PointSeq__IoFns)
extern void _Console_PointSeq__Output (ilu_Call, Console_PointSeq*, ilu_Error *);
extern ilu_cardinal _Console_PointSeq__SizeOf (ilu_Call, Console_PointSeq*, ilu_Error *);
extern Console_PointSeq* _Console_PointSeq__Input (ilu_Call, Console_PointSeq*, ilu_Error *);
extern void Console_PointSeq__Free (Console_PointSeq*);
Console_PointSeq* Console_PointSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Console_Message__IoFns;
#define TC_Console_Message (& _Console_Message__IoFns)
extern void _Console_Message__Output (ilu_Call, Console_Message*, ilu_Error *);
extern ilu_cardinal _Console_Message__SizeOf (ilu_Call, Console_Message*, ilu_Error *);
extern Console_Message* _Console_Message__Input (ilu_Call, Console_Message*, ilu_Error *);
extern void Console_Message__Free (Console_Message*);
Console_Message* Console_Message__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Console_UnbindData__IoFns;
#define TC_Console_UnbindData (& _Console_UnbindData__IoFns)
extern void _Console_UnbindData__Output (ilu_Call, Console_UnbindData*, ilu_Error *);
extern ilu_cardinal _Console_UnbindData__SizeOf (ilu_Call, Console_UnbindData*, ilu_Error *);
extern Console_UnbindData* _Console_UnbindData__Input (ilu_Call, Console_UnbindData*, ilu_Error *);
extern void Console_UnbindData__Free (Console_UnbindData*);
Console_UnbindData* Console_UnbindData__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Console_Operation__IoFns;
#define TC_Console_Operation (& _Console_Operation__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Console_TrapPoint__IoFns;
#define TC_Console_TrapPoint (& _Console_TrapPoint__IoFns)
extern void _Console_TrapPoint__Output (ilu_Call, Console_TrapPoint*, ilu_Error *);
extern ilu_cardinal _Console_TrapPoint__SizeOf (ilu_Call, Console_TrapPoint*, ilu_Error *);
extern Console_TrapPoint* _Console_TrapPoint__Input (ilu_Call, Console_TrapPoint*, ilu_Error *);
Console_TrapPoint* Console_TrapPoint__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Console_TrapType__IoFns;
#define TC_Console_TrapType (& _Console_TrapType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Console_Point__IoFns;
#define TC_Console_Point (& _Console_Point__IoFns)
extern void _Console_Point__Output (ilu_Call, Console_Point*, ilu_Error *);
extern ilu_cardinal _Console_Point__SizeOf (ilu_Call, Console_Point*, ilu_Error *);
extern Console_Point* _Console_Point__Input (ilu_Call, Console_Point*, ilu_Error *);
Console_Point* Console_Point__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Console_PointType__IoFns;
#define TC_Console_PointType (& _Console_PointType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Console_TrackMode__IoFns;
#define TC_Console_TrackMode (& _Console_TrackMode__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Console_FormationType__IoFns;
#define TC_Console_FormationType (& _Console_FormationType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Console_FormationState__IoFns;
#define TC_Console_FormationState (& _Console_FormationState__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Console_MissionStateData__IoFns;
#define TC_Console_MissionStateData (& _Console_MissionStateData__IoFns)
extern void _Console_MissionStateData__Output (ilu_Call, Console_MissionStateData*, ilu_Error *);
extern ilu_cardinal _Console_MissionStateData__SizeOf (ilu_Call, Console_MissionStateData*, ilu_Error *);
extern Console_MissionStateData* _Console_MissionStateData__Input (ilu_Call, Console_MissionStateData*, ilu_Error *);
Console_MissionStateData* Console_MissionStateData__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Console_MissionState__IoFns;
#define TC_Console_MissionState (& _Console_MissionState__IoFns)

extern ilu_Class _Console_rpc__ILUType;
extern Unit_UnitInfoSeq* _Console_rpc_getCosNamingInfo__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_sendMsg__clientstub (Console_rpc _handle, Console_Message* m, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_bind__clientstub (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_unbind__clientstub (Console_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_rebind__clientstub (Console_rpc _handle, Unit_UnitID uid, Unit_UnitSBH sbh, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setNickname__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ilu_CString newName, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setPosition__clientstub (Console_rpc _handle, ilu_CString name, Console_Point* p, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_addGoalPoint__clientstub (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setGoalPoint__clientstub (Console_rpc _handle, Console_Point* p, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setRole__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, Unit_UnitRole r, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_cancelRole__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setTrapPoint__clientstub (Console_rpc _handle, Console_TrapPoint* p, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setFollow__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo1, Unit_UnitInfo* uinfo2, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setFormationType__clientstub (Console_rpc _handle, Console_FormationType f, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setTrackMode__clientstub (Console_rpc _handle, Console_TrackMode tm, ILU_C_ENVIRONMENT *_status);
extern Unit_UnitInfo* _Console_rpc_getCurrentUnit__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_short _Console_rpc_getUnitNum__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_short _Console_rpc_getFormationNum__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_short _Console_rpc_getTrapNum__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Console_FormationType _Console_rpc_getFormationType__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Console_FormationState _Console_rpc_getFormationState__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Console_MissionState _Console_rpc_getMissionState__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Console_Point _Console_rpc_getUnitPoint__clientstub (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status);
extern Unit_UnitInfo* _Console_rpc_getByName__clientstub (Console_rpc _handle, ilu_CString name, ILU_C_ENVIRONMENT *_status);
extern Console_Point _Console_rpc_getLeaderPoint__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Console_PointSeq* _Console_rpc_getPointSeq__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_cancelFormation__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setLeaderSuspend__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_recoveryLeaderAction__clientstub (Console_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_addUnitFormation__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_deleteUnitFormation__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setUnitFault__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setUnitFaultPosition__clientstub (Console_rpc _handle, Unit_UnitInfo* uinfo, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setFormationState__clientstub (Console_rpc _handle, Console_FormationState fs, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Console_rpc_setMissionState__clientstub (Console_rpc _handle, Console_MissionStateData* msd, ILU_C_ENVIRONMENT *_status);

extern void _Console__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Console_h_ */
