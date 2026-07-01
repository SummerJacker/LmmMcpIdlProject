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

#ifndef __Ground_Unit_h_
#define __Ground_Unit_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "Unit.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                           Ground-Unit                            ***/
/************************************************************************/
/************************************************************************/

extern void Ground_Unit__Initialize(void);
extern void Ground_Unit__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Ground_Unit_rpc;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct Ground_Unit_Speed2D Ground_Unit_Speed2D;
typedef struct Ground_Unit_Pose2D Ground_Unit_Pose2D;
typedef struct Ground_Unit_GroundUnitInfo Ground_Unit_GroundUnitInfo;
typedef struct Ground_Unit_TrapPoint2D Ground_Unit_TrapPoint2D;
typedef struct _Ground_Unit_TrapPointSeq__sequence Ground_Unit_TrapPointSeq;
typedef struct _Ground_Unit_TaskPath__sequence Ground_Unit_TaskPath;
typedef struct Ground_Unit_Point2D Ground_Unit_Point2D;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* record "Ground_Unit_Speed2D" */
struct Ground_Unit_Speed2D {
	CORBA_float leanerVel;
	CORBA_float angularVel;
};
Ground_Unit_Speed2D *
  CORBA_sequence_Ground_Unit_Speed2D_allocbuf (CORBA_unsigned_long /* count */);

/* record "Ground_Unit_Pose2D" */
struct Ground_Unit_Pose2D {
	CORBA_float x;
	CORBA_float y;
	CORBA_float yaw;
};
Ground_Unit_Pose2D *
  CORBA_sequence_Ground_Unit_Pose2D_allocbuf (CORBA_unsigned_long /* count */);

/* record "Ground_Unit_GroundUnitInfo" */
struct Ground_Unit_GroundUnitInfo {
	Unit_UnitInfo info;
	Unit_UnitRole role;
	Ground_Unit_Speed2D speed;
	Ground_Unit_Pose2D pose;
};
Ground_Unit_GroundUnitInfo *
  CORBA_sequence_Ground_Unit_GroundUnitInfo_allocbuf (CORBA_unsigned_long /* count */);

/* record "Ground_Unit_Point2D" */
struct Ground_Unit_Point2D {
	CORBA_float x;
	CORBA_float y;
};
Ground_Unit_Point2D *
  CORBA_sequence_Ground_Unit_Point2D_allocbuf (CORBA_unsigned_long /* count */);

/* record "Ground_Unit_TrapPoint2D" */
struct Ground_Unit_TrapPoint2D {
	Ground_Unit_Point2D point;
	CORBA_float radius;
};
Ground_Unit_TrapPoint2D *
  CORBA_sequence_Ground_Unit_TrapPoint2D_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Ground_Unit_TrapPointSeq" */
struct _Ground_Unit_TrapPointSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Ground_Unit_TrapPoint2D *_buffer;
};
void Ground_Unit_TrapPointSeq_Every (Ground_Unit_TrapPointSeq *h, void (*f)(Ground_Unit_TrapPoint2D*, void *, ilu_Error *), void *);
void Ground_Unit_TrapPointSeq_Append (Ground_Unit_TrapPointSeq *h, Ground_Unit_TrapPoint2D* item, ilu_Error *);
void Ground_Unit_TrapPointSeq_Push (Ground_Unit_TrapPointSeq *h, Ground_Unit_TrapPoint2D* item);
void Ground_Unit_TrapPointSeq_Pop (Ground_Unit_TrapPointSeq *h, Ground_Unit_TrapPoint2D* item);
CORBA_unsigned_long Ground_Unit_TrapPointSeq_Length (Ground_Unit_TrapPointSeq *);
Ground_Unit_TrapPoint2D * Ground_Unit_TrapPointSeq_Nth (Ground_Unit_TrapPointSeq *, CORBA_unsigned_long);
Ground_Unit_TrapPointSeq * Ground_Unit_TrapPointSeq_Create (CORBA_unsigned_long /* size */, Ground_Unit_TrapPoint2D*  /* init val */);
void Ground_Unit_TrapPointSeq_Init (Ground_Unit_TrapPointSeq * /* seq */, CORBA_unsigned_long /* size */, Ground_Unit_TrapPoint2D*  /* init val */);
Ground_Unit_TrapPointSeq *
  CORBA_sequence_Ground_Unit_TrapPointSeq_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Ground_Unit_TaskPath" */
struct _Ground_Unit_TaskPath__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Ground_Unit_Point2D *_buffer;
};
void Ground_Unit_TaskPath_Every (Ground_Unit_TaskPath *h, void (*f)(Ground_Unit_Point2D*, void *, ilu_Error *), void *);
void Ground_Unit_TaskPath_Append (Ground_Unit_TaskPath *h, Ground_Unit_Point2D* item, ilu_Error *);
void Ground_Unit_TaskPath_Push (Ground_Unit_TaskPath *h, Ground_Unit_Point2D* item);
void Ground_Unit_TaskPath_Pop (Ground_Unit_TaskPath *h, Ground_Unit_Point2D* item);
CORBA_unsigned_long Ground_Unit_TaskPath_Length (Ground_Unit_TaskPath *);
Ground_Unit_Point2D * Ground_Unit_TaskPath_Nth (Ground_Unit_TaskPath *, CORBA_unsigned_long);
Ground_Unit_TaskPath * Ground_Unit_TaskPath_Create (CORBA_unsigned_long /* size */, Ground_Unit_Point2D*  /* init val */);
void Ground_Unit_TaskPath_Init (Ground_Unit_TaskPath * /* seq */, CORBA_unsigned_long /* size */, Ground_Unit_Point2D*  /* init val */);
Ground_Unit_TaskPath *
  CORBA_sequence_Ground_Unit_TaskPath_allocbuf (CORBA_unsigned_long /* count */);

Ground_Unit_rpc *
  CORBA_sequence_Ground_Unit_rpc_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Ground_Unit_rpc"  ---------------------------------*/

#define Ground_Unit_rpc__MSType _Ground_Unit_rpc__ILUType

Ground_Unit_rpc
  Ground_Unit_rpc__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Ground_Unit_rpc__SetUserData (Ground_Unit_rpc /* self */, void * /* userData */);
void *
  Ground_Unit_rpc__GetUserData (Ground_Unit_rpc /* self */);

extern Ground_Unit_rpc
  Ground_Unit_rpc__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Ground_Unit_rpc class */

extern Ground_Unit_rpc
  Ground_Unit_rpc__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Unit_UnitID server_Ground_Unit_rpc_getID (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitSBH server_Ground_Unit_rpc_getCosNamingSBH (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitInfo* server_Ground_Unit_rpc_getFrontUnitInfo (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setRole (Ground_Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setMode (Ground_Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setMinorMode (Ground_Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_sendMoveAction (Ground_Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_sendMoveActionSeq (Ground_Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setALeader (Ground_Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_unregisterFollower (Ground_Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setFollower (Ground_Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_unsetFollower (Ground_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_addRearVehicle (Ground_Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_deleteRearVehicle (Ground_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setFormation (Ground_Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setRearVehicles (Ground_Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_reportDeadVehicle (Ground_Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_shutDown (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_startPhotoStream (Ground_Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_stopPhotoStream (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_takePicture (Ground_Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status);

extern Ground_Unit_Speed2D server_Ground_Unit_rpc_getCurrentSpeed (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Ground_Unit_Pose2D server_Ground_Unit_rpc_getCurrentPose (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Ground_Unit_GroundUnitInfo* server_Ground_Unit_rpc_getCurrentInfo (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_sendVehicleInfo (Ground_Unit_rpc _handle, Ground_Unit_GroundUnitInfo* info, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_reportTrap (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_clearTraps (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Ground_Unit_TrapPointSeq* server_Ground_Unit_rpc_getTraps (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setTrapPoint (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setTrack (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setTaskPath (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Ground_Unit_rpc_setTaskPoint (Ground_Unit_rpc _handle, Ground_Unit_Point2D* point, ILU_C_ENVIRONMENT *_status);

extern void Ground_Unit_rpc__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Ground_Unit_rpc__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Ground_Unit_rpc__MakeClass(
  Ground_Unit_Speed2D (*Ground_Unit_rpc_getCurrentSpeed__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Ground_Unit_Pose2D (*Ground_Unit_rpc_getCurrentPose__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Ground_Unit_GroundUnitInfo* (*Ground_Unit_rpc_getCurrentInfo__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_sendVehicleInfo__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_GroundUnitInfo* info, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_reportTrap__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_clearTraps__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Ground_Unit_TrapPointSeq* (*Ground_Unit_rpc_getTraps__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTrapPoint__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTrack__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTaskPath__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Ground_Unit_rpc_setTaskPoint__Impl)
     (Ground_Unit_rpc _handle, Ground_Unit_Point2D* point, ILU_C_ENVIRONMENT *_status),
  Unit_UnitID (*Unit_rpc_getID__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitSBH (*Unit_rpc_getCosNamingSBH__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Unit_rpc_getFrontUnitInfo__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRole__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMode__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMinorMode__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveAction__Impl)
     (Ground_Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveActionSeq__Impl)
     (Ground_Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setALeader__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unregisterFollower__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFollower__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unsetFollower__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_addRearVehicle__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_deleteRearVehicle__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFormation__Impl)
     (Ground_Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRearVehicles__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_reportDeadVehicle__Impl)
     (Ground_Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_shutDown__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_startPhotoStream__Impl)
     (Ground_Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_stopPhotoStream__Impl)
     (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_takePicture__Impl)
     (Ground_Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Ground_Unit_Speed2D
  Ground_Unit_rpc_getCurrentSpeed (Ground_Unit_rpc, ILU_C_ENVIRONMENT *);

extern Ground_Unit_Pose2D
  Ground_Unit_rpc_getCurrentPose (Ground_Unit_rpc, ILU_C_ENVIRONMENT *);

extern Ground_Unit_GroundUnitInfo*
  Ground_Unit_rpc_getCurrentInfo (Ground_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Ground_Unit_rpc_sendVehicleInfo (Ground_Unit_rpc, Ground_Unit_GroundUnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Ground_Unit_rpc_reportTrap (Ground_Unit_rpc, Ground_Unit_TrapPoint2D*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Ground_Unit_rpc_clearTraps (Ground_Unit_rpc, ILU_C_ENVIRONMENT *);

extern Ground_Unit_TrapPointSeq*
  Ground_Unit_rpc_getTraps (Ground_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Ground_Unit_rpc_setTrapPoint (Ground_Unit_rpc, Ground_Unit_TrapPoint2D*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Ground_Unit_rpc_setTrack (Ground_Unit_rpc, Ground_Unit_TaskPath*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Ground_Unit_rpc_setTaskPath (Ground_Unit_rpc, Ground_Unit_TaskPath*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Ground_Unit_rpc_setTaskPoint (Ground_Unit_rpc, Ground_Unit_Point2D*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Ground_Unit__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Ground_Unit_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Ground_Unit_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_rpc__IoFns;
#define TC_Ground_Unit_rpc (& _Ground_Unit_rpc__IoFns)
extern void Ground_Unit_rpc__Free (Ground_Unit_rpc*);
extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_TrapPointSeq__IoFns;
#define TC_Ground_Unit_TrapPointSeq (& _Ground_Unit_TrapPointSeq__IoFns)
extern void _Ground_Unit_TrapPointSeq__Output (ilu_Call, Ground_Unit_TrapPointSeq*, ilu_Error *);
extern ilu_cardinal _Ground_Unit_TrapPointSeq__SizeOf (ilu_Call, Ground_Unit_TrapPointSeq*, ilu_Error *);
extern Ground_Unit_TrapPointSeq* _Ground_Unit_TrapPointSeq__Input (ilu_Call, Ground_Unit_TrapPointSeq*, ilu_Error *);
extern void Ground_Unit_TrapPointSeq__Free (Ground_Unit_TrapPointSeq*);
Ground_Unit_TrapPointSeq* Ground_Unit_TrapPointSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_TaskPath__IoFns;
#define TC_Ground_Unit_TaskPath (& _Ground_Unit_TaskPath__IoFns)
extern void _Ground_Unit_TaskPath__Output (ilu_Call, Ground_Unit_TaskPath*, ilu_Error *);
extern ilu_cardinal _Ground_Unit_TaskPath__SizeOf (ilu_Call, Ground_Unit_TaskPath*, ilu_Error *);
extern Ground_Unit_TaskPath* _Ground_Unit_TaskPath__Input (ilu_Call, Ground_Unit_TaskPath*, ilu_Error *);
extern void Ground_Unit_TaskPath__Free (Ground_Unit_TaskPath*);
Ground_Unit_TaskPath* Ground_Unit_TaskPath__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_TrapPoint2D__IoFns;
#define TC_Ground_Unit_TrapPoint2D (& _Ground_Unit_TrapPoint2D__IoFns)
extern void _Ground_Unit_TrapPoint2D__Output (ilu_Call, Ground_Unit_TrapPoint2D*, ilu_Error *);
extern ilu_cardinal _Ground_Unit_TrapPoint2D__SizeOf (ilu_Call, Ground_Unit_TrapPoint2D*, ilu_Error *);
extern Ground_Unit_TrapPoint2D* _Ground_Unit_TrapPoint2D__Input (ilu_Call, Ground_Unit_TrapPoint2D*, ilu_Error *);
Ground_Unit_TrapPoint2D* Ground_Unit_TrapPoint2D__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_Point2D__IoFns;
#define TC_Ground_Unit_Point2D (& _Ground_Unit_Point2D__IoFns)
extern void _Ground_Unit_Point2D__Output (ilu_Call, Ground_Unit_Point2D*, ilu_Error *);
extern ilu_cardinal _Ground_Unit_Point2D__SizeOf (ilu_Call, Ground_Unit_Point2D*, ilu_Error *);
extern Ground_Unit_Point2D* _Ground_Unit_Point2D__Input (ilu_Call, Ground_Unit_Point2D*, ilu_Error *);
Ground_Unit_Point2D* Ground_Unit_Point2D__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_GroundUnitInfo__IoFns;
#define TC_Ground_Unit_GroundUnitInfo (& _Ground_Unit_GroundUnitInfo__IoFns)
extern void _Ground_Unit_GroundUnitInfo__Output (ilu_Call, Ground_Unit_GroundUnitInfo*, ilu_Error *);
extern ilu_cardinal _Ground_Unit_GroundUnitInfo__SizeOf (ilu_Call, Ground_Unit_GroundUnitInfo*, ilu_Error *);
extern Ground_Unit_GroundUnitInfo* _Ground_Unit_GroundUnitInfo__Input (ilu_Call, Ground_Unit_GroundUnitInfo*, ilu_Error *);
extern void Ground_Unit_GroundUnitInfo__Free (Ground_Unit_GroundUnitInfo*);
Ground_Unit_GroundUnitInfo* Ground_Unit_GroundUnitInfo__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_Speed2D__IoFns;
#define TC_Ground_Unit_Speed2D (& _Ground_Unit_Speed2D__IoFns)
extern void _Ground_Unit_Speed2D__Output (ilu_Call, Ground_Unit_Speed2D*, ilu_Error *);
extern ilu_cardinal _Ground_Unit_Speed2D__SizeOf (ilu_Call, Ground_Unit_Speed2D*, ilu_Error *);
extern Ground_Unit_Speed2D* _Ground_Unit_Speed2D__Input (ilu_Call, Ground_Unit_Speed2D*, ilu_Error *);
Ground_Unit_Speed2D* Ground_Unit_Speed2D__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Ground_Unit_Pose2D__IoFns;
#define TC_Ground_Unit_Pose2D (& _Ground_Unit_Pose2D__IoFns)
extern void _Ground_Unit_Pose2D__Output (ilu_Call, Ground_Unit_Pose2D*, ilu_Error *);
extern ilu_cardinal _Ground_Unit_Pose2D__SizeOf (ilu_Call, Ground_Unit_Pose2D*, ilu_Error *);
extern Ground_Unit_Pose2D* _Ground_Unit_Pose2D__Input (ilu_Call, Ground_Unit_Pose2D*, ilu_Error *);
Ground_Unit_Pose2D* Ground_Unit_Pose2D__alloc (void);

extern ilu_Class _Ground_Unit_rpc__ILUType;
extern Ground_Unit_Speed2D _Ground_Unit_rpc_getCurrentSpeed__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Ground_Unit_Pose2D _Ground_Unit_rpc_getCurrentPose__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Ground_Unit_GroundUnitInfo* _Ground_Unit_rpc_getCurrentInfo__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Ground_Unit_rpc_sendVehicleInfo__clientstub (Ground_Unit_rpc _handle, Ground_Unit_GroundUnitInfo* info, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Ground_Unit_rpc_reportTrap__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Ground_Unit_rpc_clearTraps__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Ground_Unit_TrapPointSeq* _Ground_Unit_rpc_getTraps__clientstub (Ground_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Ground_Unit_rpc_setTrapPoint__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TrapPoint2D* trap, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Ground_Unit_rpc_setTrack__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Ground_Unit_rpc_setTaskPath__clientstub (Ground_Unit_rpc _handle, Ground_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Ground_Unit_rpc_setTaskPoint__clientstub (Ground_Unit_rpc _handle, Ground_Unit_Point2D* point, ILU_C_ENVIRONMENT *_status);

extern void _Ground_Unit__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Ground_Unit_h_ */
