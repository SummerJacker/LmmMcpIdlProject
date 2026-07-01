/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Thu Jul 24 14:42:41 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/SAU/project/SAU/ilu/bin/c-stubber.EXE" of Thu Jul 10 17:58:46 2025
 * on "D:/SAU/project/SAU/Interfaces/monitor.idl" of Wed Jul 16 16:43:00 2025,
 * and "D:/SAU/project/SAU/ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/SAU/project/SAU/Interfaces/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/SAU/project/SAU/Interfaces/air_unit.idl" of Fri Jul 18 15:18:31 2025,
 * and "D:/SAU/project/SAU/Interfaces/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/SAU/project/SAU/Interfaces/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Monitor_h_
#define __Monitor_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "Ground_Unit.h"
#include "Air_Unit.h"
#include "Console.h"
#include "Unit.h"
#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             Monitor                              ***/
/************************************************************************/
/************************************************************************/

extern void Monitor__Initialize(void);
extern void Monitor__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Monitor_rpc;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct Monitor_CompleteUnitInfo Monitor_CompleteUnitInfo;
typedef ilu_CString Monitor_TargetID;
typedef struct Monitor_PictureInfo Monitor_PictureInfo;
typedef enum {Monitor_LowBattery = 0, Monitor_EmptyLoad = 1, Monitor_TaskDone = 2, Monitor_TaskStop = 3} Monitor_BackHomeReason;
typedef enum {Monitor_Success = 0, Monitor_StillBurning = 1, Monitor_Locating = 2, Monitor_Processing = 3} Monitor_MissionSituation;
typedef struct _Monitor_PictureFlow__sequence Monitor_PictureFlow;
typedef enum {Monitor_Fire = 0, Monitor_Person = 1, Monitor_Vehicle = 2, Monitor_Drone = 3} Monitor_TargetType;
typedef struct _Monitor_CurrentUnitInfo_union Monitor_CurrentUnitInfo;
typedef enum {Monitor_UnitGroundType = 0, Monitor_UnitAirType = 1} Monitor_UnitType;
typedef struct Monitor_UnitState Monitor_UnitState;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* record "Monitor_UnitState" */
struct Monitor_UnitState {
	CORBA_short health;
	CORBA_short battery;
};
Monitor_UnitState *
  CORBA_sequence_Monitor_UnitState_allocbuf (CORBA_unsigned_long /* count */);

/* union "Monitor_CurrentUnitInfo" */

struct _Monitor_CurrentUnitInfo_union {
	Monitor_UnitType _d;
	union {
		Ground_Unit_GroundUnitInfo groundUnitInfo;	/* Monitor_UnitGroundType */
		Air_Unit_AirUnitInfo airUnitInfo;	/* Monitor_UnitAirType */
	} _u;
};
Monitor_CurrentUnitInfo *
  CORBA_sequence_Monitor_CurrentUnitInfo_allocbuf (CORBA_unsigned_long /* count */);

/* record "Monitor_CompleteUnitInfo" */
struct Monitor_CompleteUnitInfo {
	Monitor_UnitState us;
	Monitor_CurrentUnitInfo cui;
};
Monitor_CompleteUnitInfo *
  CORBA_sequence_Monitor_CompleteUnitInfo_allocbuf (CORBA_unsigned_long /* count */);

/* "Monitor_TargetID" alias for "ilu_CString" */
#define Monitor_TargetID_Length ilu_CString_Length
#define Monitor_TargetID_Nth ilu_CString_Nth
#define Monitor_TargetID_Every ilu_CString_Every
#define Monitor_TargetID_Append ilu_CString_Append
#define Monitor_TargetID_Push ilu_CString_Push
#define Monitor_TargetID_Pop ilu_CString_Pop
#define Monitor_TargetID_Init ilu_CString_Init
#define Monitor_TargetID_Create ilu_CString_Create
#define Monitor_TargetID__Free ilu_CString__Free
#define Monitor_TargetID__alloc ilu_CString__alloc
#define CORBA_sequence_Monitor_TargetID_allocbuf CORBA_sequence_string_allocbuf

/* sequence type "Monitor_PictureFlow" */
struct _Monitor_PictureFlow__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_octet *_buffer;
};
void Monitor_PictureFlow_Every (Monitor_PictureFlow *h, void (*f)(CORBA_octet*, void *, ilu_Error *), void *);
void Monitor_PictureFlow_Append (Monitor_PictureFlow *h, CORBA_octet item, ilu_Error *);
void Monitor_PictureFlow_Push (Monitor_PictureFlow *h, CORBA_octet item);
void Monitor_PictureFlow_Pop (Monitor_PictureFlow *h, CORBA_octet *item);
CORBA_unsigned_long Monitor_PictureFlow_Length (Monitor_PictureFlow *);
CORBA_octet * Monitor_PictureFlow_Nth (Monitor_PictureFlow *, CORBA_unsigned_long);
Monitor_PictureFlow * Monitor_PictureFlow_Create (CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
void Monitor_PictureFlow_Init (Monitor_PictureFlow * /* seq */, CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
Monitor_PictureFlow *
  CORBA_sequence_Monitor_PictureFlow_allocbuf (CORBA_unsigned_long /* count */);

/* record "Monitor_PictureInfo" */
struct Monitor_PictureInfo {
	ilu_CString picturName;
	Monitor_PictureFlow pic;
	Monitor_CurrentUnitInfo cui;
	CORBA_short responseTime;
};
Monitor_PictureInfo *
  CORBA_sequence_Monitor_PictureInfo_allocbuf (CORBA_unsigned_long /* count */);

Monitor_BackHomeReason *
  CORBA_sequence_Monitor_BackHomeReason_allocbuf (CORBA_unsigned_long /* count */);

Monitor_MissionSituation *
  CORBA_sequence_Monitor_MissionSituation_allocbuf (CORBA_unsigned_long /* count */);

Monitor_rpc *
  CORBA_sequence_Monitor_rpc_allocbuf (CORBA_unsigned_long /* count */);

Monitor_TargetType *
  CORBA_sequence_Monitor_TargetType_allocbuf (CORBA_unsigned_long /* count */);

Monitor_UnitType *
  CORBA_sequence_Monitor_UnitType_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Monitor_rpc"  -------------------------------------*/

#define Monitor_rpc__MSType _Monitor_rpc__ILUType

Monitor_rpc
  Monitor_rpc__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Monitor_rpc__SetUserData (Monitor_rpc /* self */, void * /* userData */);
void *
  Monitor_rpc__GetUserData (Monitor_rpc /* self */);

extern Monitor_rpc
  Monitor_rpc__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Monitor_rpc class */

extern Monitor_rpc
  Monitor_rpc__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern CORBA_boolean server_Monitor_rpc_sendUnitInfo (Monitor_rpc _handle, Monitor_CompleteUnitInfo* unitInfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Monitor_rpc_sendTrapPoint (Monitor_rpc _handle, Console_TrapPoint* tp, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Monitor_rpc_sendTargetLocation (Monitor_rpc _handle, Monitor_TargetID fid, Ground_Unit_Point2D* fp, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Monitor_rpc_foundTarget (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_PictureInfo* pi, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Monitor_rpc_confirmAction (Monitor_rpc _handle, Monitor_TargetID fid, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Monitor_rpc_backHome (Monitor_rpc _handle, Unit_UnitID uid, Monitor_BackHomeReason bhr, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Monitor_rpc_sendMissionState (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_MissionSituation ms, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Monitor_rpc_sendPicture (Monitor_rpc _handle, ilu_CString pictureName, Monitor_PictureFlow* pic, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status);

extern void Monitor_rpc__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Monitor_rpc__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Monitor_rpc__MakeClass(
  CORBA_boolean (*Monitor_rpc_sendUnitInfo__Impl)
     (Monitor_rpc _handle, Monitor_CompleteUnitInfo* unitInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendTrapPoint__Impl)
     (Monitor_rpc _handle, Console_TrapPoint* tp, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendTargetLocation__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, Ground_Unit_Point2D* fp, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_foundTarget__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_PictureInfo* pi, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_confirmAction__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_backHome__Impl)
     (Monitor_rpc _handle, Unit_UnitID uid, Monitor_BackHomeReason bhr, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendMissionState__Impl)
     (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_MissionSituation ms, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Monitor_rpc_sendPicture__Impl)
     (Monitor_rpc _handle, ilu_CString pictureName, Monitor_PictureFlow* pic, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern CORBA_boolean
  Monitor_rpc_sendUnitInfo (Monitor_rpc, Monitor_CompleteUnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Monitor_rpc_sendTrapPoint (Monitor_rpc, Console_TrapPoint*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Monitor_rpc_sendTargetLocation (Monitor_rpc, Monitor_TargetID, Ground_Unit_Point2D*, CORBA_short, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Monitor_rpc_foundTarget (Monitor_rpc, Monitor_TargetID, Monitor_PictureInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Monitor_rpc_confirmAction (Monitor_rpc, Monitor_TargetID, CORBA_short, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Monitor_rpc_backHome (Monitor_rpc, Unit_UnitID, Monitor_BackHomeReason, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Monitor_rpc_sendMissionState (Monitor_rpc, Monitor_TargetID, Monitor_MissionSituation, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Monitor_rpc_sendPicture (Monitor_rpc, ilu_CString, Monitor_PictureFlow*, CORBA_long, CORBA_long, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Monitor__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Monitor_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Monitor_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Monitor_rpc__IoFns;
#define TC_Monitor_rpc (& _Monitor_rpc__IoFns)
extern void Monitor_rpc__Free (Monitor_rpc*);
extern struct _ILU_C_IoFnsRegistration_s _Monitor_PictureInfo__IoFns;
#define TC_Monitor_PictureInfo (& _Monitor_PictureInfo__IoFns)
extern void _Monitor_PictureInfo__Output (ilu_Call, Monitor_PictureInfo*, ilu_Error *);
extern ilu_cardinal _Monitor_PictureInfo__SizeOf (ilu_Call, Monitor_PictureInfo*, ilu_Error *);
extern Monitor_PictureInfo* _Monitor_PictureInfo__Input (ilu_Call, Monitor_PictureInfo*, ilu_Error *);
extern void Monitor_PictureInfo__Free (Monitor_PictureInfo*);
Monitor_PictureInfo* Monitor_PictureInfo__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Monitor_PictureFlow__IoFns;
#define TC_Monitor_PictureFlow (& _Monitor_PictureFlow__IoFns)
extern void _Monitor_PictureFlow__Output (ilu_Call, Monitor_PictureFlow*, ilu_Error *);
extern ilu_cardinal _Monitor_PictureFlow__SizeOf (ilu_Call, Monitor_PictureFlow*, ilu_Error *);
extern Monitor_PictureFlow* _Monitor_PictureFlow__Input (ilu_Call, Monitor_PictureFlow*, ilu_Error *);
extern void Monitor_PictureFlow__Free (Monitor_PictureFlow*);
Monitor_PictureFlow* Monitor_PictureFlow__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Monitor_MissionSituation__IoFns;
#define TC_Monitor_MissionSituation (& _Monitor_MissionSituation__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Monitor_BackHomeReason__IoFns;
#define TC_Monitor_BackHomeReason (& _Monitor_BackHomeReason__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Monitor_TargetID__IoFns;
#define TC_Monitor_TargetID (& _Monitor_TargetID__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Monitor_TargetType__IoFns;
#define TC_Monitor_TargetType (& _Monitor_TargetType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Monitor_CompleteUnitInfo__IoFns;
#define TC_Monitor_CompleteUnitInfo (& _Monitor_CompleteUnitInfo__IoFns)
extern void _Monitor_CompleteUnitInfo__Output (ilu_Call, Monitor_CompleteUnitInfo*, ilu_Error *);
extern ilu_cardinal _Monitor_CompleteUnitInfo__SizeOf (ilu_Call, Monitor_CompleteUnitInfo*, ilu_Error *);
extern Monitor_CompleteUnitInfo* _Monitor_CompleteUnitInfo__Input (ilu_Call, Monitor_CompleteUnitInfo*, ilu_Error *);
extern void Monitor_CompleteUnitInfo__Free (Monitor_CompleteUnitInfo*);
Monitor_CompleteUnitInfo* Monitor_CompleteUnitInfo__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Monitor_CurrentUnitInfo__IoFns;
#define TC_Monitor_CurrentUnitInfo (& _Monitor_CurrentUnitInfo__IoFns)
extern void _Monitor_CurrentUnitInfo__Output (ilu_Call, Monitor_CurrentUnitInfo*, ilu_Error *);
extern ilu_cardinal _Monitor_CurrentUnitInfo__SizeOf (ilu_Call, Monitor_CurrentUnitInfo*, ilu_Error *);
extern Monitor_CurrentUnitInfo* _Monitor_CurrentUnitInfo__Input (ilu_Call, Monitor_CurrentUnitInfo*, ilu_Error *);
extern void Monitor_CurrentUnitInfo__Free (Monitor_CurrentUnitInfo*);
Monitor_CurrentUnitInfo* Monitor_CurrentUnitInfo__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Monitor_UnitType__IoFns;
#define TC_Monitor_UnitType (& _Monitor_UnitType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Monitor_UnitState__IoFns;
#define TC_Monitor_UnitState (& _Monitor_UnitState__IoFns)
extern void _Monitor_UnitState__Output (ilu_Call, Monitor_UnitState*, ilu_Error *);
extern ilu_cardinal _Monitor_UnitState__SizeOf (ilu_Call, Monitor_UnitState*, ilu_Error *);
extern Monitor_UnitState* _Monitor_UnitState__Input (ilu_Call, Monitor_UnitState*, ilu_Error *);
Monitor_UnitState* Monitor_UnitState__alloc (void);

extern ilu_Class _Monitor_rpc__ILUType;
extern CORBA_boolean _Monitor_rpc_sendUnitInfo__clientstub (Monitor_rpc _handle, Monitor_CompleteUnitInfo* unitInfo, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Monitor_rpc_sendTrapPoint__clientstub (Monitor_rpc _handle, Console_TrapPoint* tp, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Monitor_rpc_sendTargetLocation__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, Ground_Unit_Point2D* fp, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Monitor_rpc_foundTarget__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_PictureInfo* pi, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Monitor_rpc_confirmAction__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, CORBA_short responseTime, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Monitor_rpc_backHome__clientstub (Monitor_rpc _handle, Unit_UnitID uid, Monitor_BackHomeReason bhr, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Monitor_rpc_sendMissionState__clientstub (Monitor_rpc _handle, Monitor_TargetID fid, Monitor_MissionSituation ms, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Monitor_rpc_sendPicture__clientstub (Monitor_rpc _handle, ilu_CString pictureName, Monitor_PictureFlow* pic, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status);

extern void _Monitor__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Monitor_h_ */
