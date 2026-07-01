/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 15:13:36 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/../bin/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/../bin/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Air_Unit_h_
#define __Air_Unit_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "Unit.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             Air-Unit                             ***/
/************************************************************************/
/************************************************************************/

extern void Air_Unit__Initialize(void);
extern void Air_Unit__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Air_Unit_rpc;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct Air_Unit_Speed3D Air_Unit_Speed3D;
typedef struct Air_Unit_Pose3D Air_Unit_Pose3D;
typedef struct Air_Unit_AirUnitInfo Air_Unit_AirUnitInfo;
typedef struct Air_Unit_GimbalSpeed Air_Unit_GimbalSpeed;
typedef struct Air_Unit_TrapPoint3D Air_Unit_TrapPoint3D;
typedef struct _Air_Unit_TrapPointSeq__sequence Air_Unit_TrapPointSeq;
typedef struct _Air_Unit_TaskPath__sequence Air_Unit_TaskPath;
typedef struct Air_Unit_Point3D Air_Unit_Point3D;
typedef enum {Air_Unit_Actor = 0, Air_Unit_Standby = 1, Air_Unit_Facilitators = 2} Air_Unit_ActionRole;
typedef enum {Air_Unit_Nothing = 0, Air_Unit_Cruise = 1, Air_Unit_Locate = 2, Air_Unit_Assist = 3, Air_Unit_Feedback = 4} Air_Unit_ActionMode;
typedef struct Air_Unit_RectangleData Air_Unit_RectangleData;
typedef struct Air_Unit_CircleData Air_Unit_CircleData;
typedef struct _Air_Unit_Site_union Air_Unit_Site;
typedef enum {Air_Unit_Rectangle = 0, Air_Unit_Circle = 1} Air_Unit_SiteType;
typedef struct Air_Unit_FusionAngularVelocity Air_Unit_FusionAngularVelocity;
typedef struct Air_Unit_GPSInfo Air_Unit_GPSInfo;
typedef struct Air_Unit_GimbalState Air_Unit_GimbalState;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* record "Air_Unit_Speed3D" */
struct Air_Unit_Speed3D {
	CORBA_float x;
	CORBA_float y;
	CORBA_float z;
};
Air_Unit_Speed3D *
  CORBA_sequence_Air_Unit_Speed3D_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_Pose3D" */
struct Air_Unit_Pose3D {
	CORBA_float x;
	CORBA_float y;
	CORBA_float z;
	CORBA_float pitch;
	CORBA_float yaw;
	CORBA_float roll;
};
Air_Unit_Pose3D *
  CORBA_sequence_Air_Unit_Pose3D_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_FusionAngularVelocity" */
struct Air_Unit_FusionAngularVelocity {
	CORBA_float x;
	CORBA_float y;
	CORBA_float z;
};
Air_Unit_FusionAngularVelocity *
  CORBA_sequence_Air_Unit_FusionAngularVelocity_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_GPSInfo" */
struct Air_Unit_GPSInfo {
	CORBA_float longitude;
	CORBA_float latitude;
	CORBA_float altitude;
	CORBA_float height;
	CORBA_float time;
	CORBA_short health;
};
Air_Unit_GPSInfo *
  CORBA_sequence_Air_Unit_GPSInfo_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_GimbalState" */
struct Air_Unit_GimbalState {
	CORBA_float yaw;
	CORBA_float roll;
	CORBA_float pitch;
};
Air_Unit_GimbalState *
  CORBA_sequence_Air_Unit_GimbalState_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_AirUnitInfo" */
struct Air_Unit_AirUnitInfo {
	Unit_UnitInfo info;
	Unit_UnitRole role;
	Air_Unit_Speed3D speed;
	Air_Unit_FusionAngularVelocity angularVelocity;
	Air_Unit_GPSInfo gps;
	Air_Unit_GimbalState gs;
};
Air_Unit_AirUnitInfo *
  CORBA_sequence_Air_Unit_AirUnitInfo_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_GimbalSpeed" */
struct Air_Unit_GimbalSpeed {
	CORBA_float yaw;
	CORBA_float roll;
	CORBA_float pitch;
};
Air_Unit_GimbalSpeed *
  CORBA_sequence_Air_Unit_GimbalSpeed_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_Point3D" */
struct Air_Unit_Point3D {
	CORBA_float x;
	CORBA_float y;
	CORBA_float z;
};
Air_Unit_Point3D *
  CORBA_sequence_Air_Unit_Point3D_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_TrapPoint3D" */
struct Air_Unit_TrapPoint3D {
	Air_Unit_Point3D point;
	CORBA_float radius;
};
Air_Unit_TrapPoint3D *
  CORBA_sequence_Air_Unit_TrapPoint3D_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Air_Unit_TrapPointSeq" */
struct _Air_Unit_TrapPointSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Air_Unit_TrapPoint3D *_buffer;
};
void Air_Unit_TrapPointSeq_Every (Air_Unit_TrapPointSeq *h, void (*f)(Air_Unit_TrapPoint3D*, void *, ilu_Error *), void *);
void Air_Unit_TrapPointSeq_Append (Air_Unit_TrapPointSeq *h, Air_Unit_TrapPoint3D* item, ilu_Error *);
void Air_Unit_TrapPointSeq_Push (Air_Unit_TrapPointSeq *h, Air_Unit_TrapPoint3D* item);
void Air_Unit_TrapPointSeq_Pop (Air_Unit_TrapPointSeq *h, Air_Unit_TrapPoint3D* item);
CORBA_unsigned_long Air_Unit_TrapPointSeq_Length (Air_Unit_TrapPointSeq *);
Air_Unit_TrapPoint3D * Air_Unit_TrapPointSeq_Nth (Air_Unit_TrapPointSeq *, CORBA_unsigned_long);
Air_Unit_TrapPointSeq * Air_Unit_TrapPointSeq_Create (CORBA_unsigned_long /* size */, Air_Unit_TrapPoint3D*  /* init val */);
void Air_Unit_TrapPointSeq_Init (Air_Unit_TrapPointSeq * /* seq */, CORBA_unsigned_long /* size */, Air_Unit_TrapPoint3D*  /* init val */);
Air_Unit_TrapPointSeq *
  CORBA_sequence_Air_Unit_TrapPointSeq_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Air_Unit_TaskPath" */
struct _Air_Unit_TaskPath__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Air_Unit_Point3D *_buffer;
};
void Air_Unit_TaskPath_Every (Air_Unit_TaskPath *h, void (*f)(Air_Unit_Point3D*, void *, ilu_Error *), void *);
void Air_Unit_TaskPath_Append (Air_Unit_TaskPath *h, Air_Unit_Point3D* item, ilu_Error *);
void Air_Unit_TaskPath_Push (Air_Unit_TaskPath *h, Air_Unit_Point3D* item);
void Air_Unit_TaskPath_Pop (Air_Unit_TaskPath *h, Air_Unit_Point3D* item);
CORBA_unsigned_long Air_Unit_TaskPath_Length (Air_Unit_TaskPath *);
Air_Unit_Point3D * Air_Unit_TaskPath_Nth (Air_Unit_TaskPath *, CORBA_unsigned_long);
Air_Unit_TaskPath * Air_Unit_TaskPath_Create (CORBA_unsigned_long /* size */, Air_Unit_Point3D*  /* init val */);
void Air_Unit_TaskPath_Init (Air_Unit_TaskPath * /* seq */, CORBA_unsigned_long /* size */, Air_Unit_Point3D*  /* init val */);
Air_Unit_TaskPath *
  CORBA_sequence_Air_Unit_TaskPath_allocbuf (CORBA_unsigned_long /* count */);

Air_Unit_ActionRole *
  CORBA_sequence_Air_Unit_ActionRole_allocbuf (CORBA_unsigned_long /* count */);

Air_Unit_ActionMode *
  CORBA_sequence_Air_Unit_ActionMode_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_RectangleData" */
struct Air_Unit_RectangleData {
	Air_Unit_Point3D po;
	CORBA_short x;
	CORBA_short y;
};
Air_Unit_RectangleData *
  CORBA_sequence_Air_Unit_RectangleData_allocbuf (CORBA_unsigned_long /* count */);

/* record "Air_Unit_CircleData" */
struct Air_Unit_CircleData {
	Air_Unit_Point3D po;
	CORBA_short r;
};
Air_Unit_CircleData *
  CORBA_sequence_Air_Unit_CircleData_allocbuf (CORBA_unsigned_long /* count */);

/* union "Air_Unit_Site" */

struct _Air_Unit_Site_union {
	Air_Unit_SiteType _d;
	union {
		Air_Unit_RectangleData rd;	/* Air_Unit_Rectangle */
		Air_Unit_CircleData cd;	/* Air_Unit_Circle */
	} _u;
};
Air_Unit_Site *
  CORBA_sequence_Air_Unit_Site_allocbuf (CORBA_unsigned_long /* count */);

Air_Unit_rpc *
  CORBA_sequence_Air_Unit_rpc_allocbuf (CORBA_unsigned_long /* count */);

Air_Unit_SiteType *
  CORBA_sequence_Air_Unit_SiteType_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Air_Unit_rpc"  ------------------------------------*/

#define Air_Unit_rpc__MSType _Air_Unit_rpc__ILUType

Air_Unit_rpc
  Air_Unit_rpc__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Air_Unit_rpc__SetUserData (Air_Unit_rpc /* self */, void * /* userData */);
void *
  Air_Unit_rpc__GetUserData (Air_Unit_rpc /* self */);

extern Air_Unit_rpc
  Air_Unit_rpc__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Air_Unit_rpc class */

extern Air_Unit_rpc
  Air_Unit_rpc__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Unit_UnitID server_Air_Unit_rpc_getID (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitSBH server_Air_Unit_rpc_getCosNamingSBH (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitInfo* server_Air_Unit_rpc_getFrontUnitInfo (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setRole (Air_Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setMode (Air_Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setMinorMode (Air_Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_sendMoveAction (Air_Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_sendMoveActionSeq (Air_Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setALeader (Air_Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_unregisterFollower (Air_Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setFollower (Air_Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_unsetFollower (Air_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_addRearVehicle (Air_Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_deleteRearVehicle (Air_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setFormation (Air_Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setRearVehicles (Air_Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_reportDeadVehicle (Air_Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_shutDown (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_startPhotoStream (Air_Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_stopPhotoStream (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_takePicture (Air_Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status);

extern Air_Unit_Speed3D server_Air_Unit_rpc_getCurrentSpeed (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Air_Unit_Pose3D server_Air_Unit_rpc_getCurrentPose (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Air_Unit_AirUnitInfo* server_Air_Unit_rpc_getCurrentInfo (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_sendGimbalSpeed (Air_Unit_rpc _handle, Air_Unit_GimbalSpeed* speed, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_resetGimbal (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_sendVehicleInfo (Air_Unit_rpc _handle, Air_Unit_AirUnitInfo* info, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_reportTrap (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_clearTraps (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Air_Unit_TrapPointSeq* server_Air_Unit_rpc_getTraps (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setTrapPoint (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setTrack (Air_Unit_rpc _handle, Air_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setTaskPath (Air_Unit_rpc _handle, Air_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setTaskPoint (Air_Unit_rpc _handle, Air_Unit_Point3D* point, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_clearTaskPoint (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_obtainCtrlAuthority (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_releaseCtrlAuthority (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setActionRole (Air_Unit_rpc _handle, Air_Unit_ActionRole ar, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setActionMode (Air_Unit_rpc _handle, Air_Unit_ActionMode am, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setCruiseScope (Air_Unit_rpc _handle, Air_Unit_Site* s, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_sendControlledVehicle (Air_Unit_rpc _handle, Unit_UnitSBHSeq* uss, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_confirmThrow (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_cancelThrow (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_actionThrow (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_confirmFire (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_cancelFire (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_confirmFireLocation (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_cancelFireLocation (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_controlVehicleVelocity (Air_Unit_rpc _handle, CORBA_float vx, CORBA_float vy, CORBA_float vz, CORBA_float angle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_backHome (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Air_Unit_rpc_setCruiseSpeed (Air_Unit_rpc _handle, CORBA_float cs, ILU_C_ENVIRONMENT *_status);

extern void Air_Unit_rpc__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Air_Unit_rpc__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Air_Unit_rpc__MakeClass(
  Air_Unit_Speed3D (*Air_Unit_rpc_getCurrentSpeed__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Air_Unit_Pose3D (*Air_Unit_rpc_getCurrentPose__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Air_Unit_AirUnitInfo* (*Air_Unit_rpc_getCurrentInfo__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_sendGimbalSpeed__Impl)
     (Air_Unit_rpc _handle, Air_Unit_GimbalSpeed* speed, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_resetGimbal__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_sendVehicleInfo__Impl)
     (Air_Unit_rpc _handle, Air_Unit_AirUnitInfo* info, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_reportTrap__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_clearTraps__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Air_Unit_TrapPointSeq* (*Air_Unit_rpc_getTraps__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTrapPoint__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTrack__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTaskPath__Impl)
     (Air_Unit_rpc _handle, Air_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setTaskPoint__Impl)
     (Air_Unit_rpc _handle, Air_Unit_Point3D* point, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_clearTaskPoint__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_obtainCtrlAuthority__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_releaseCtrlAuthority__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setActionRole__Impl)
     (Air_Unit_rpc _handle, Air_Unit_ActionRole ar, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setActionMode__Impl)
     (Air_Unit_rpc _handle, Air_Unit_ActionMode am, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setCruiseScope__Impl)
     (Air_Unit_rpc _handle, Air_Unit_Site* s, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_sendControlledVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitSBHSeq* uss, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_confirmThrow__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_cancelThrow__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_actionThrow__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_confirmFire__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_cancelFire__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_confirmFireLocation__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_cancelFireLocation__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_controlVehicleVelocity__Impl)
     (Air_Unit_rpc _handle, CORBA_float vx, CORBA_float vy, CORBA_float vz, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_backHome__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Air_Unit_rpc_setCruiseSpeed__Impl)
     (Air_Unit_rpc _handle, CORBA_float cs, ILU_C_ENVIRONMENT *_status),
  Unit_UnitID (*Unit_rpc_getID__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitSBH (*Unit_rpc_getCosNamingSBH__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Unit_rpc_getFrontUnitInfo__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRole__Impl)
     (Air_Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMode__Impl)
     (Air_Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMinorMode__Impl)
     (Air_Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveAction__Impl)
     (Air_Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveActionSeq__Impl)
     (Air_Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setALeader__Impl)
     (Air_Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unregisterFollower__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFollower__Impl)
     (Air_Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unsetFollower__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_addRearVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_deleteRearVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFormation__Impl)
     (Air_Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRearVehicles__Impl)
     (Air_Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_reportDeadVehicle__Impl)
     (Air_Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_shutDown__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_startPhotoStream__Impl)
     (Air_Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_stopPhotoStream__Impl)
     (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_takePicture__Impl)
     (Air_Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Air_Unit_Speed3D
  Air_Unit_rpc_getCurrentSpeed (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern Air_Unit_Pose3D
  Air_Unit_rpc_getCurrentPose (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern Air_Unit_AirUnitInfo*
  Air_Unit_rpc_getCurrentInfo (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_sendGimbalSpeed (Air_Unit_rpc, Air_Unit_GimbalSpeed*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_resetGimbal (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_sendVehicleInfo (Air_Unit_rpc, Air_Unit_AirUnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_reportTrap (Air_Unit_rpc, Air_Unit_TrapPoint3D*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_clearTraps (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern Air_Unit_TrapPointSeq*
  Air_Unit_rpc_getTraps (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setTrapPoint (Air_Unit_rpc, Air_Unit_TrapPoint3D*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setTrack (Air_Unit_rpc, Air_Unit_TaskPath*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setTaskPath (Air_Unit_rpc, Air_Unit_TaskPath*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setTaskPoint (Air_Unit_rpc, Air_Unit_Point3D*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_clearTaskPoint (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_obtainCtrlAuthority (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_releaseCtrlAuthority (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setActionRole (Air_Unit_rpc, Air_Unit_ActionRole, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setActionMode (Air_Unit_rpc, Air_Unit_ActionMode, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setCruiseScope (Air_Unit_rpc, Air_Unit_Site*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_sendControlledVehicle (Air_Unit_rpc, Unit_UnitSBHSeq*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_confirmThrow (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_cancelThrow (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_actionThrow (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_confirmFire (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_cancelFire (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_confirmFireLocation (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_cancelFireLocation (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_controlVehicleVelocity (Air_Unit_rpc, CORBA_float, CORBA_float, CORBA_float, CORBA_float, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_backHome (Air_Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Air_Unit_rpc_setCruiseSpeed (Air_Unit_rpc, CORBA_float, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Air_Unit__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Air_Unit_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Air_Unit_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_rpc__IoFns;
#define TC_Air_Unit_rpc (& _Air_Unit_rpc__IoFns)
extern void Air_Unit_rpc__Free (Air_Unit_rpc*);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_ActionMode__IoFns;
#define TC_Air_Unit_ActionMode (& _Air_Unit_ActionMode__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_ActionRole__IoFns;
#define TC_Air_Unit_ActionRole (& _Air_Unit_ActionRole__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_TrapPointSeq__IoFns;
#define TC_Air_Unit_TrapPointSeq (& _Air_Unit_TrapPointSeq__IoFns)
extern void _Air_Unit_TrapPointSeq__Output (ilu_Call, Air_Unit_TrapPointSeq*, ilu_Error *);
extern ilu_cardinal _Air_Unit_TrapPointSeq__SizeOf (ilu_Call, Air_Unit_TrapPointSeq*, ilu_Error *);
extern Air_Unit_TrapPointSeq* _Air_Unit_TrapPointSeq__Input (ilu_Call, Air_Unit_TrapPointSeq*, ilu_Error *);
extern void Air_Unit_TrapPointSeq__Free (Air_Unit_TrapPointSeq*);
Air_Unit_TrapPointSeq* Air_Unit_TrapPointSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_TaskPath__IoFns;
#define TC_Air_Unit_TaskPath (& _Air_Unit_TaskPath__IoFns)
extern void _Air_Unit_TaskPath__Output (ilu_Call, Air_Unit_TaskPath*, ilu_Error *);
extern ilu_cardinal _Air_Unit_TaskPath__SizeOf (ilu_Call, Air_Unit_TaskPath*, ilu_Error *);
extern Air_Unit_TaskPath* _Air_Unit_TaskPath__Input (ilu_Call, Air_Unit_TaskPath*, ilu_Error *);
extern void Air_Unit_TaskPath__Free (Air_Unit_TaskPath*);
Air_Unit_TaskPath* Air_Unit_TaskPath__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_Site__IoFns;
#define TC_Air_Unit_Site (& _Air_Unit_Site__IoFns)
extern void _Air_Unit_Site__Output (ilu_Call, Air_Unit_Site*, ilu_Error *);
extern ilu_cardinal _Air_Unit_Site__SizeOf (ilu_Call, Air_Unit_Site*, ilu_Error *);
extern Air_Unit_Site* _Air_Unit_Site__Input (ilu_Call, Air_Unit_Site*, ilu_Error *);
Air_Unit_Site* Air_Unit_Site__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_CircleData__IoFns;
#define TC_Air_Unit_CircleData (& _Air_Unit_CircleData__IoFns)
extern void _Air_Unit_CircleData__Output (ilu_Call, Air_Unit_CircleData*, ilu_Error *);
extern ilu_cardinal _Air_Unit_CircleData__SizeOf (ilu_Call, Air_Unit_CircleData*, ilu_Error *);
extern Air_Unit_CircleData* _Air_Unit_CircleData__Input (ilu_Call, Air_Unit_CircleData*, ilu_Error *);
Air_Unit_CircleData* Air_Unit_CircleData__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_RectangleData__IoFns;
#define TC_Air_Unit_RectangleData (& _Air_Unit_RectangleData__IoFns)
extern void _Air_Unit_RectangleData__Output (ilu_Call, Air_Unit_RectangleData*, ilu_Error *);
extern ilu_cardinal _Air_Unit_RectangleData__SizeOf (ilu_Call, Air_Unit_RectangleData*, ilu_Error *);
extern Air_Unit_RectangleData* _Air_Unit_RectangleData__Input (ilu_Call, Air_Unit_RectangleData*, ilu_Error *);
Air_Unit_RectangleData* Air_Unit_RectangleData__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_SiteType__IoFns;
#define TC_Air_Unit_SiteType (& _Air_Unit_SiteType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_TrapPoint3D__IoFns;
#define TC_Air_Unit_TrapPoint3D (& _Air_Unit_TrapPoint3D__IoFns)
extern void _Air_Unit_TrapPoint3D__Output (ilu_Call, Air_Unit_TrapPoint3D*, ilu_Error *);
extern ilu_cardinal _Air_Unit_TrapPoint3D__SizeOf (ilu_Call, Air_Unit_TrapPoint3D*, ilu_Error *);
extern Air_Unit_TrapPoint3D* _Air_Unit_TrapPoint3D__Input (ilu_Call, Air_Unit_TrapPoint3D*, ilu_Error *);
Air_Unit_TrapPoint3D* Air_Unit_TrapPoint3D__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_Point3D__IoFns;
#define TC_Air_Unit_Point3D (& _Air_Unit_Point3D__IoFns)
extern void _Air_Unit_Point3D__Output (ilu_Call, Air_Unit_Point3D*, ilu_Error *);
extern ilu_cardinal _Air_Unit_Point3D__SizeOf (ilu_Call, Air_Unit_Point3D*, ilu_Error *);
extern Air_Unit_Point3D* _Air_Unit_Point3D__Input (ilu_Call, Air_Unit_Point3D*, ilu_Error *);
Air_Unit_Point3D* Air_Unit_Point3D__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_AirUnitInfo__IoFns;
#define TC_Air_Unit_AirUnitInfo (& _Air_Unit_AirUnitInfo__IoFns)
extern void _Air_Unit_AirUnitInfo__Output (ilu_Call, Air_Unit_AirUnitInfo*, ilu_Error *);
extern ilu_cardinal _Air_Unit_AirUnitInfo__SizeOf (ilu_Call, Air_Unit_AirUnitInfo*, ilu_Error *);
extern Air_Unit_AirUnitInfo* _Air_Unit_AirUnitInfo__Input (ilu_Call, Air_Unit_AirUnitInfo*, ilu_Error *);
extern void Air_Unit_AirUnitInfo__Free (Air_Unit_AirUnitInfo*);
Air_Unit_AirUnitInfo* Air_Unit_AirUnitInfo__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_FusionAngularVelocity__IoFns;
#define TC_Air_Unit_FusionAngularVelocity (& _Air_Unit_FusionAngularVelocity__IoFns)
extern void _Air_Unit_FusionAngularVelocity__Output (ilu_Call, Air_Unit_FusionAngularVelocity*, ilu_Error *);
extern ilu_cardinal _Air_Unit_FusionAngularVelocity__SizeOf (ilu_Call, Air_Unit_FusionAngularVelocity*, ilu_Error *);
extern Air_Unit_FusionAngularVelocity* _Air_Unit_FusionAngularVelocity__Input (ilu_Call, Air_Unit_FusionAngularVelocity*, ilu_Error *);
Air_Unit_FusionAngularVelocity* Air_Unit_FusionAngularVelocity__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_Speed3D__IoFns;
#define TC_Air_Unit_Speed3D (& _Air_Unit_Speed3D__IoFns)
extern void _Air_Unit_Speed3D__Output (ilu_Call, Air_Unit_Speed3D*, ilu_Error *);
extern ilu_cardinal _Air_Unit_Speed3D__SizeOf (ilu_Call, Air_Unit_Speed3D*, ilu_Error *);
extern Air_Unit_Speed3D* _Air_Unit_Speed3D__Input (ilu_Call, Air_Unit_Speed3D*, ilu_Error *);
Air_Unit_Speed3D* Air_Unit_Speed3D__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_GPSInfo__IoFns;
#define TC_Air_Unit_GPSInfo (& _Air_Unit_GPSInfo__IoFns)
extern void _Air_Unit_GPSInfo__Output (ilu_Call, Air_Unit_GPSInfo*, ilu_Error *);
extern ilu_cardinal _Air_Unit_GPSInfo__SizeOf (ilu_Call, Air_Unit_GPSInfo*, ilu_Error *);
extern Air_Unit_GPSInfo* _Air_Unit_GPSInfo__Input (ilu_Call, Air_Unit_GPSInfo*, ilu_Error *);
Air_Unit_GPSInfo* Air_Unit_GPSInfo__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_Pose3D__IoFns;
#define TC_Air_Unit_Pose3D (& _Air_Unit_Pose3D__IoFns)
extern void _Air_Unit_Pose3D__Output (ilu_Call, Air_Unit_Pose3D*, ilu_Error *);
extern ilu_cardinal _Air_Unit_Pose3D__SizeOf (ilu_Call, Air_Unit_Pose3D*, ilu_Error *);
extern Air_Unit_Pose3D* _Air_Unit_Pose3D__Input (ilu_Call, Air_Unit_Pose3D*, ilu_Error *);
Air_Unit_Pose3D* Air_Unit_Pose3D__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_GimbalState__IoFns;
#define TC_Air_Unit_GimbalState (& _Air_Unit_GimbalState__IoFns)
extern void _Air_Unit_GimbalState__Output (ilu_Call, Air_Unit_GimbalState*, ilu_Error *);
extern ilu_cardinal _Air_Unit_GimbalState__SizeOf (ilu_Call, Air_Unit_GimbalState*, ilu_Error *);
extern Air_Unit_GimbalState* _Air_Unit_GimbalState__Input (ilu_Call, Air_Unit_GimbalState*, ilu_Error *);
Air_Unit_GimbalState* Air_Unit_GimbalState__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Air_Unit_GimbalSpeed__IoFns;
#define TC_Air_Unit_GimbalSpeed (& _Air_Unit_GimbalSpeed__IoFns)
extern void _Air_Unit_GimbalSpeed__Output (ilu_Call, Air_Unit_GimbalSpeed*, ilu_Error *);
extern ilu_cardinal _Air_Unit_GimbalSpeed__SizeOf (ilu_Call, Air_Unit_GimbalSpeed*, ilu_Error *);
extern Air_Unit_GimbalSpeed* _Air_Unit_GimbalSpeed__Input (ilu_Call, Air_Unit_GimbalSpeed*, ilu_Error *);
Air_Unit_GimbalSpeed* Air_Unit_GimbalSpeed__alloc (void);

extern ilu_Class _Air_Unit_rpc__ILUType;
extern Air_Unit_Speed3D _Air_Unit_rpc_getCurrentSpeed__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Air_Unit_Pose3D _Air_Unit_rpc_getCurrentPose__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Air_Unit_AirUnitInfo* _Air_Unit_rpc_getCurrentInfo__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_sendGimbalSpeed__clientstub (Air_Unit_rpc _handle, Air_Unit_GimbalSpeed* speed, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_resetGimbal__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_sendVehicleInfo__clientstub (Air_Unit_rpc _handle, Air_Unit_AirUnitInfo* info, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_reportTrap__clientstub (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_clearTraps__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Air_Unit_TrapPointSeq* _Air_Unit_rpc_getTraps__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setTrapPoint__clientstub (Air_Unit_rpc _handle, Air_Unit_TrapPoint3D* trap, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setTrack__clientstub (Air_Unit_rpc _handle, Air_Unit_TaskPath* track, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setTaskPath__clientstub (Air_Unit_rpc _handle, Air_Unit_TaskPath* path, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setTaskPoint__clientstub (Air_Unit_rpc _handle, Air_Unit_Point3D* point, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_clearTaskPoint__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_obtainCtrlAuthority__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_releaseCtrlAuthority__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setActionRole__clientstub (Air_Unit_rpc _handle, Air_Unit_ActionRole ar, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setActionMode__clientstub (Air_Unit_rpc _handle, Air_Unit_ActionMode am, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setCruiseScope__clientstub (Air_Unit_rpc _handle, Air_Unit_Site* s, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_sendControlledVehicle__clientstub (Air_Unit_rpc _handle, Unit_UnitSBHSeq* uss, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_confirmThrow__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_cancelThrow__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_actionThrow__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_confirmFire__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_cancelFire__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_confirmFireLocation__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_cancelFireLocation__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_controlVehicleVelocity__clientstub (Air_Unit_rpc _handle, CORBA_float vx, CORBA_float vy, CORBA_float vz, CORBA_float angle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_backHome__clientstub (Air_Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Air_Unit_rpc_setCruiseSpeed__clientstub (Air_Unit_rpc _handle, CORBA_float cs, ILU_C_ENVIRONMENT *_status);

extern void _Air_Unit__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Air_Unit_h_ */
