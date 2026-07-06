/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:29:05 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c-stubber.exe" of Thu Jul 10 17:58:46 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Unit_h_
#define __Unit_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                               Unit                               ***/
/************************************************************************/
/************************************************************************/

extern void Unit__Initialize(void);
extern void Unit__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT Unit_rpc;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef ilu_CString Unit_UnitID;
typedef ilu_CString Unit_UnitSBH;
typedef struct Unit_UnitInfo Unit_UnitInfo;
typedef enum {Unit_UR_Leader = 0, Unit_UR_Follower = 1, Unit_UR_None = 2} Unit_UnitRole;
typedef enum {Unit_UM_None = 0, Unit_UM_Follow = 1, Unit_UM_Imitate = 2, Unit_UM_Mate = 3} Unit_UnitMode;
typedef enum {Unit_UMM_None = 0, Unit_UMM_FW_Object = 1, Unit_UMM_FW_Track = 2} Unit_UnitMinorMode;
typedef struct Unit_BasicMoveActionData Unit_BasicMoveActionData;
typedef struct Unit_ActionDuration Unit_ActionDuration;
typedef struct _Unit_MoveAction_union Unit_MoveAction;
typedef struct _Unit_ActionSeq__sequence Unit_ActionSeq;
typedef struct Unit_Formation Unit_Formation;
typedef struct _Unit_UnitInfoSeq__sequence Unit_UnitInfoSeq;
typedef enum {Unit_MA_GoAhead = 0, Unit_MA_GoBackward = 1, Unit_MA_TurnLeft = 2, Unit_MA_TurnRight = 3, Unit_MA_Stop = 4, Unit_MA_GoUp = 5, Unit_MA_GoDown = 6, Unit_MA_GoLeft = 7, Unit_MA_GoRight = 8, Unit_MA_TakeOff = 9, Unit_MA_Land = 10, Unit_MA_LandConfirm = 11, Unit_MA_ForceLanding = 12, Unit_MA_Lock = 13, Unit_MA_Unlock = 14} Unit_MoveActionType;
typedef struct _Unit_FloatSeq__sequence Unit_FloatSeq;
typedef struct _Unit_ShortSeq__sequence Unit_ShortSeq;
typedef struct _Unit_UnitSBHSeq__sequence Unit_UnitSBHSeq;
typedef struct _Unit_UnitIDSeq__sequence Unit_UnitIDSeq;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

/* "Unit_UnitID" alias for "ilu_CString" */
#define Unit_UnitID_Length ilu_CString_Length
#define Unit_UnitID_Nth ilu_CString_Nth
#define Unit_UnitID_Every ilu_CString_Every
#define Unit_UnitID_Append ilu_CString_Append
#define Unit_UnitID_Push ilu_CString_Push
#define Unit_UnitID_Pop ilu_CString_Pop
#define Unit_UnitID_Init ilu_CString_Init
#define Unit_UnitID_Create ilu_CString_Create
#define Unit_UnitID__Free ilu_CString__Free
#define Unit_UnitID__alloc ilu_CString__alloc
#define CORBA_sequence_Unit_UnitID_allocbuf CORBA_sequence_string_allocbuf

/* "Unit_UnitSBH" alias for "ilu_CString" */
#define Unit_UnitSBH_Length ilu_CString_Length
#define Unit_UnitSBH_Nth ilu_CString_Nth
#define Unit_UnitSBH_Every ilu_CString_Every
#define Unit_UnitSBH_Append ilu_CString_Append
#define Unit_UnitSBH_Push ilu_CString_Push
#define Unit_UnitSBH_Pop ilu_CString_Pop
#define Unit_UnitSBH_Init ilu_CString_Init
#define Unit_UnitSBH_Create ilu_CString_Create
#define Unit_UnitSBH__Free ilu_CString__Free
#define Unit_UnitSBH__alloc ilu_CString__alloc
#define CORBA_sequence_Unit_UnitSBH_allocbuf CORBA_sequence_string_allocbuf

/* record "Unit_UnitInfo" */
struct Unit_UnitInfo {
	Unit_UnitID uid;
	Unit_UnitSBH sbh;
};
Unit_UnitInfo *
  CORBA_sequence_Unit_UnitInfo_allocbuf (CORBA_unsigned_long /* count */);

Unit_UnitRole *
  CORBA_sequence_Unit_UnitRole_allocbuf (CORBA_unsigned_long /* count */);

Unit_UnitMode *
  CORBA_sequence_Unit_UnitMode_allocbuf (CORBA_unsigned_long /* count */);

Unit_UnitMinorMode *
  CORBA_sequence_Unit_UnitMinorMode_allocbuf (CORBA_unsigned_long /* count */);

/* record "Unit_ActionDuration" */
struct Unit_ActionDuration {
	CORBA_boolean keep;
	CORBA_unsigned_long ft_s;
	CORBA_unsigned_long ft_t;
};
Unit_ActionDuration *
  CORBA_sequence_Unit_ActionDuration_allocbuf (CORBA_unsigned_long /* count */);

/* record "Unit_BasicMoveActionData" */
struct Unit_BasicMoveActionData {
	CORBA_float speed;
	Unit_ActionDuration duration;
};
Unit_BasicMoveActionData *
  CORBA_sequence_Unit_BasicMoveActionData_allocbuf (CORBA_unsigned_long /* count */);

/* union "Unit_MoveAction" */

struct _Unit_MoveAction_union {
	Unit_MoveActionType _d;
	union {
		Unit_BasicMoveActionData goUpData;	/* Unit_MA_GoUp */
		Unit_BasicMoveActionData goDownData;	/* Unit_MA_GoDown */
		Unit_BasicMoveActionData goAheadData;	/* Unit_MA_GoAhead */
		Unit_BasicMoveActionData goBackwardData;	/* Unit_MA_GoBackward */
		Unit_BasicMoveActionData goLeftData;	/* Unit_MA_GoLeft */
		Unit_BasicMoveActionData goRightData;	/* Unit_MA_GoRight */
		Unit_BasicMoveActionData turnLeftData;	/* Unit_MA_TurnLeft */
		Unit_BasicMoveActionData turnRightData;	/* Unit_MA_TurnRight */
		Unit_ActionDuration stopData;	/* Unit_MA_Stop */
	} _u;
};
Unit_MoveAction *
  CORBA_sequence_Unit_MoveAction_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Unit_ActionSeq" */
struct _Unit_ActionSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Unit_MoveAction *_buffer;
};
void Unit_ActionSeq_Every (Unit_ActionSeq *h, void (*f)(Unit_MoveAction*, void *, ilu_Error *), void *);
void Unit_ActionSeq_Append (Unit_ActionSeq *h, Unit_MoveAction* item, ilu_Error *);
void Unit_ActionSeq_Push (Unit_ActionSeq *h, Unit_MoveAction* item);
void Unit_ActionSeq_Pop (Unit_ActionSeq *h, Unit_MoveAction* item);
CORBA_unsigned_long Unit_ActionSeq_Length (Unit_ActionSeq *);
Unit_MoveAction * Unit_ActionSeq_Nth (Unit_ActionSeq *, CORBA_unsigned_long);
Unit_ActionSeq * Unit_ActionSeq_Create (CORBA_unsigned_long /* size */, Unit_MoveAction*  /* init val */);
void Unit_ActionSeq_Init (Unit_ActionSeq * /* seq */, CORBA_unsigned_long /* size */, Unit_MoveAction*  /* init val */);
Unit_ActionSeq *
  CORBA_sequence_Unit_ActionSeq_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Unit_UnitIDSeq" */
struct _Unit_UnitIDSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Unit_UnitID *_buffer;
};
void Unit_UnitIDSeq_Every (Unit_UnitIDSeq *h, void (*f)(Unit_UnitID*, void *, ilu_Error *), void *);
void Unit_UnitIDSeq_Append (Unit_UnitIDSeq *h, Unit_UnitID item, ilu_Error *);
void Unit_UnitIDSeq_Push (Unit_UnitIDSeq *h, Unit_UnitID item);
void Unit_UnitIDSeq_Pop (Unit_UnitIDSeq *h, Unit_UnitID *item);
CORBA_unsigned_long Unit_UnitIDSeq_Length (Unit_UnitIDSeq *);
Unit_UnitID * Unit_UnitIDSeq_Nth (Unit_UnitIDSeq *, CORBA_unsigned_long);
Unit_UnitIDSeq * Unit_UnitIDSeq_Create (CORBA_unsigned_long /* size */, Unit_UnitID * /* init val */);
void Unit_UnitIDSeq_Init (Unit_UnitIDSeq * /* seq */, CORBA_unsigned_long /* size */, Unit_UnitID * /* init val */);
Unit_UnitIDSeq *
  CORBA_sequence_Unit_UnitIDSeq_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Unit_ShortSeq" */
struct _Unit_ShortSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_short *_buffer;
};
void Unit_ShortSeq_Every (Unit_ShortSeq *h, void (*f)(CORBA_short*, void *, ilu_Error *), void *);
void Unit_ShortSeq_Append (Unit_ShortSeq *h, CORBA_short item, ilu_Error *);
void Unit_ShortSeq_Push (Unit_ShortSeq *h, CORBA_short item);
void Unit_ShortSeq_Pop (Unit_ShortSeq *h, CORBA_short *item);
CORBA_unsigned_long Unit_ShortSeq_Length (Unit_ShortSeq *);
CORBA_short * Unit_ShortSeq_Nth (Unit_ShortSeq *, CORBA_unsigned_long);
Unit_ShortSeq * Unit_ShortSeq_Create (CORBA_unsigned_long /* size */, CORBA_short * /* init val */);
void Unit_ShortSeq_Init (Unit_ShortSeq * /* seq */, CORBA_unsigned_long /* size */, CORBA_short * /* init val */);
Unit_ShortSeq *
  CORBA_sequence_Unit_ShortSeq_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Unit_FloatSeq" */
struct _Unit_FloatSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_float *_buffer;
};
void Unit_FloatSeq_Every (Unit_FloatSeq *h, void (*f)(CORBA_float*, void *, ilu_Error *), void *);
void Unit_FloatSeq_Append (Unit_FloatSeq *h, CORBA_float item, ilu_Error *);
void Unit_FloatSeq_Push (Unit_FloatSeq *h, CORBA_float item);
void Unit_FloatSeq_Pop (Unit_FloatSeq *h, CORBA_float *item);
CORBA_unsigned_long Unit_FloatSeq_Length (Unit_FloatSeq *);
CORBA_float * Unit_FloatSeq_Nth (Unit_FloatSeq *, CORBA_unsigned_long);
Unit_FloatSeq * Unit_FloatSeq_Create (CORBA_unsigned_long /* size */, CORBA_float * /* init val */);
void Unit_FloatSeq_Init (Unit_FloatSeq * /* seq */, CORBA_unsigned_long /* size */, CORBA_float * /* init val */);
Unit_FloatSeq *
  CORBA_sequence_Unit_FloatSeq_allocbuf (CORBA_unsigned_long /* count */);

/* record "Unit_Formation" */
struct Unit_Formation {
	Unit_UnitIDSeq robot_ids;
	Unit_ShortSeq leader_ids;
	Unit_FloatSeq distances;
	Unit_FloatSeq angles;
};
Unit_Formation *
  CORBA_sequence_Unit_Formation_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Unit_UnitInfoSeq" */
struct _Unit_UnitInfoSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Unit_UnitInfo *_buffer;
};
void Unit_UnitInfoSeq_Every (Unit_UnitInfoSeq *h, void (*f)(Unit_UnitInfo*, void *, ilu_Error *), void *);
void Unit_UnitInfoSeq_Append (Unit_UnitInfoSeq *h, Unit_UnitInfo* item, ilu_Error *);
void Unit_UnitInfoSeq_Push (Unit_UnitInfoSeq *h, Unit_UnitInfo* item);
void Unit_UnitInfoSeq_Pop (Unit_UnitInfoSeq *h, Unit_UnitInfo* item);
CORBA_unsigned_long Unit_UnitInfoSeq_Length (Unit_UnitInfoSeq *);
Unit_UnitInfo * Unit_UnitInfoSeq_Nth (Unit_UnitInfoSeq *, CORBA_unsigned_long);
Unit_UnitInfoSeq * Unit_UnitInfoSeq_Create (CORBA_unsigned_long /* size */, Unit_UnitInfo*  /* init val */);
void Unit_UnitInfoSeq_Init (Unit_UnitInfoSeq * /* seq */, CORBA_unsigned_long /* size */, Unit_UnitInfo*  /* init val */);
Unit_UnitInfoSeq *
  CORBA_sequence_Unit_UnitInfoSeq_allocbuf (CORBA_unsigned_long /* count */);

Unit_rpc *
  CORBA_sequence_Unit_rpc_allocbuf (CORBA_unsigned_long /* count */);

Unit_MoveActionType *
  CORBA_sequence_Unit_MoveActionType_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "Unit_UnitSBHSeq" */
struct _Unit_UnitSBHSeq__sequence {
 unsigned long _maximum;
 unsigned long _length;
 Unit_UnitSBH *_buffer;
};
void Unit_UnitSBHSeq_Every (Unit_UnitSBHSeq *h, void (*f)(Unit_UnitSBH*, void *, ilu_Error *), void *);
void Unit_UnitSBHSeq_Append (Unit_UnitSBHSeq *h, Unit_UnitSBH item, ilu_Error *);
void Unit_UnitSBHSeq_Push (Unit_UnitSBHSeq *h, Unit_UnitSBH item);
void Unit_UnitSBHSeq_Pop (Unit_UnitSBHSeq *h, Unit_UnitSBH *item);
CORBA_unsigned_long Unit_UnitSBHSeq_Length (Unit_UnitSBHSeq *);
Unit_UnitSBH * Unit_UnitSBHSeq_Nth (Unit_UnitSBHSeq *, CORBA_unsigned_long);
Unit_UnitSBHSeq * Unit_UnitSBHSeq_Create (CORBA_unsigned_long /* size */, Unit_UnitSBH * /* init val */);
void Unit_UnitSBHSeq_Init (Unit_UnitSBHSeq * /* seq */, CORBA_unsigned_long /* size */, Unit_UnitSBH * /* init val */);
Unit_UnitSBHSeq *
  CORBA_sequence_Unit_UnitSBHSeq_allocbuf (CORBA_unsigned_long /* count */);



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "Unit_rpc"  ----------------------------------------*/

#define Unit_rpc__MSType _Unit_rpc__ILUType

Unit_rpc
  Unit_rpc__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  Unit_rpc__SetUserData (Unit_rpc /* self */, void * /* userData */);
void *
  Unit_rpc__GetUserData (Unit_rpc /* self */);

extern Unit_rpc
  Unit_rpc__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default Unit_rpc class */

extern Unit_rpc
  Unit_rpc__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern Unit_UnitID server_Unit_rpc_getID (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitSBH server_Unit_rpc_getCosNamingSBH (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern Unit_UnitInfo* server_Unit_rpc_getFrontUnitInfo (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_setRole (Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_setMode (Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_setMinorMode (Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_sendMoveAction (Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_sendMoveActionSeq (Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_setALeader (Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_unregisterFollower (Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_setFollower (Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_unsetFollower (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_addRearVehicle (Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_deleteRearVehicle (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_setFormation (Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_setRearVehicles (Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_reportDeadVehicle (Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_shutDown (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_startPhotoStream (Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_stopPhotoStream (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);

extern CORBA_boolean server_Unit_rpc_takePicture (Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status);

extern void Unit_rpc__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class Unit_rpc__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class Unit_rpc__MakeClass(
  Unit_UnitID (*Unit_rpc_getID__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitSBH (*Unit_rpc_getCosNamingSBH__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  Unit_UnitInfo* (*Unit_rpc_getFrontUnitInfo__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRole__Impl)
     (Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMode__Impl)
     (Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setMinorMode__Impl)
     (Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveAction__Impl)
     (Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_sendMoveActionSeq__Impl)
     (Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setALeader__Impl)
     (Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unregisterFollower__Impl)
     (Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFollower__Impl)
     (Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_unsetFollower__Impl)
     (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_addRearVehicle__Impl)
     (Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_deleteRearVehicle__Impl)
     (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setFormation__Impl)
     (Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_setRearVehicles__Impl)
     (Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_reportDeadVehicle__Impl)
     (Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_shutDown__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_startPhotoStream__Impl)
     (Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_stopPhotoStream__Impl)
     (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status),
  CORBA_boolean (*Unit_rpc_takePicture__Impl)
     (Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern Unit_UnitID
  Unit_rpc_getID (Unit_rpc, ILU_C_ENVIRONMENT *);

extern Unit_UnitSBH
  Unit_rpc_getCosNamingSBH (Unit_rpc, ILU_C_ENVIRONMENT *);

extern Unit_UnitInfo*
  Unit_rpc_getFrontUnitInfo (Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_setRole (Unit_rpc, Unit_UnitRole, Unit_UnitSBH, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_setMode (Unit_rpc, Unit_UnitMode, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_setMinorMode (Unit_rpc, Unit_UnitMinorMode, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_sendMoveAction (Unit_rpc, Unit_MoveAction*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_sendMoveActionSeq (Unit_rpc, Unit_ActionSeq*, CORBA_short, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_setALeader (Unit_rpc, Unit_UnitSBH, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_unregisterFollower (Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_setFollower (Unit_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_unsetFollower (Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_addRearVehicle (Unit_rpc, Unit_UnitInfo*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_deleteRearVehicle (Unit_rpc, Unit_UnitID, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_setFormation (Unit_rpc, Unit_Formation*, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_setRearVehicles (Unit_rpc, Unit_UnitInfoSeq*, CORBA_float, CORBA_float, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_reportDeadVehicle (Unit_rpc, Unit_UnitID, ilu_CString, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_shutDown (Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_startPhotoStream (Unit_rpc, CORBA_float, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_stopPhotoStream (Unit_rpc, ILU_C_ENVIRONMENT *);

extern CORBA_boolean
  Unit_rpc_takePicture (Unit_rpc, CORBA_long, CORBA_long, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void Unit__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _Unit_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _Unit_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _Unit_rpc__IoFns;
#define TC_Unit_rpc (& _Unit_rpc__IoFns)
extern void Unit_rpc__Free (Unit_rpc*);
extern struct _ILU_C_IoFnsRegistration_s _Unit_Formation__IoFns;
#define TC_Unit_Formation (& _Unit_Formation__IoFns)
extern void _Unit_Formation__Output (ilu_Call, Unit_Formation*, ilu_Error *);
extern ilu_cardinal _Unit_Formation__SizeOf (ilu_Call, Unit_Formation*, ilu_Error *);
extern Unit_Formation* _Unit_Formation__Input (ilu_Call, Unit_Formation*, ilu_Error *);
extern void Unit_Formation__Free (Unit_Formation*);
Unit_Formation* Unit_Formation__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitInfoSeq__IoFns;
#define TC_Unit_UnitInfoSeq (& _Unit_UnitInfoSeq__IoFns)
extern void _Unit_UnitInfoSeq__Output (ilu_Call, Unit_UnitInfoSeq*, ilu_Error *);
extern ilu_cardinal _Unit_UnitInfoSeq__SizeOf (ilu_Call, Unit_UnitInfoSeq*, ilu_Error *);
extern Unit_UnitInfoSeq* _Unit_UnitInfoSeq__Input (ilu_Call, Unit_UnitInfoSeq*, ilu_Error *);
extern void Unit_UnitInfoSeq__Free (Unit_UnitInfoSeq*);
Unit_UnitInfoSeq* Unit_UnitInfoSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitInfo__IoFns;
#define TC_Unit_UnitInfo (& _Unit_UnitInfo__IoFns)
extern void _Unit_UnitInfo__Output (ilu_Call, Unit_UnitInfo*, ilu_Error *);
extern ilu_cardinal _Unit_UnitInfo__SizeOf (ilu_Call, Unit_UnitInfo*, ilu_Error *);
extern Unit_UnitInfo* _Unit_UnitInfo__Input (ilu_Call, Unit_UnitInfo*, ilu_Error *);
extern void Unit_UnitInfo__Free (Unit_UnitInfo*);
Unit_UnitInfo* Unit_UnitInfo__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitMinorMode__IoFns;
#define TC_Unit_UnitMinorMode (& _Unit_UnitMinorMode__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitMode__IoFns;
#define TC_Unit_UnitMode (& _Unit_UnitMode__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitRole__IoFns;
#define TC_Unit_UnitRole (& _Unit_UnitRole__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Unit_ActionSeq__IoFns;
#define TC_Unit_ActionSeq (& _Unit_ActionSeq__IoFns)
extern void _Unit_ActionSeq__Output (ilu_Call, Unit_ActionSeq*, ilu_Error *);
extern ilu_cardinal _Unit_ActionSeq__SizeOf (ilu_Call, Unit_ActionSeq*, ilu_Error *);
extern Unit_ActionSeq* _Unit_ActionSeq__Input (ilu_Call, Unit_ActionSeq*, ilu_Error *);
extern void Unit_ActionSeq__Free (Unit_ActionSeq*);
Unit_ActionSeq* Unit_ActionSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_MoveAction__IoFns;
#define TC_Unit_MoveAction (& _Unit_MoveAction__IoFns)
extern void _Unit_MoveAction__Output (ilu_Call, Unit_MoveAction*, ilu_Error *);
extern ilu_cardinal _Unit_MoveAction__SizeOf (ilu_Call, Unit_MoveAction*, ilu_Error *);
extern Unit_MoveAction* _Unit_MoveAction__Input (ilu_Call, Unit_MoveAction*, ilu_Error *);
Unit_MoveAction* Unit_MoveAction__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_MoveActionType__IoFns;
#define TC_Unit_MoveActionType (& _Unit_MoveActionType__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Unit_BasicMoveActionData__IoFns;
#define TC_Unit_BasicMoveActionData (& _Unit_BasicMoveActionData__IoFns)
extern void _Unit_BasicMoveActionData__Output (ilu_Call, Unit_BasicMoveActionData*, ilu_Error *);
extern ilu_cardinal _Unit_BasicMoveActionData__SizeOf (ilu_Call, Unit_BasicMoveActionData*, ilu_Error *);
extern Unit_BasicMoveActionData* _Unit_BasicMoveActionData__Input (ilu_Call, Unit_BasicMoveActionData*, ilu_Error *);
Unit_BasicMoveActionData* Unit_BasicMoveActionData__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_ActionDuration__IoFns;
#define TC_Unit_ActionDuration (& _Unit_ActionDuration__IoFns)
extern void _Unit_ActionDuration__Output (ilu_Call, Unit_ActionDuration*, ilu_Error *);
extern ilu_cardinal _Unit_ActionDuration__SizeOf (ilu_Call, Unit_ActionDuration*, ilu_Error *);
extern Unit_ActionDuration* _Unit_ActionDuration__Input (ilu_Call, Unit_ActionDuration*, ilu_Error *);
Unit_ActionDuration* Unit_ActionDuration__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_FloatSeq__IoFns;
#define TC_Unit_FloatSeq (& _Unit_FloatSeq__IoFns)
extern void _Unit_FloatSeq__Output (ilu_Call, Unit_FloatSeq*, ilu_Error *);
extern ilu_cardinal _Unit_FloatSeq__SizeOf (ilu_Call, Unit_FloatSeq*, ilu_Error *);
extern Unit_FloatSeq* _Unit_FloatSeq__Input (ilu_Call, Unit_FloatSeq*, ilu_Error *);
extern void Unit_FloatSeq__Free (Unit_FloatSeq*);
Unit_FloatSeq* Unit_FloatSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_ShortSeq__IoFns;
#define TC_Unit_ShortSeq (& _Unit_ShortSeq__IoFns)
extern void _Unit_ShortSeq__Output (ilu_Call, Unit_ShortSeq*, ilu_Error *);
extern ilu_cardinal _Unit_ShortSeq__SizeOf (ilu_Call, Unit_ShortSeq*, ilu_Error *);
extern Unit_ShortSeq* _Unit_ShortSeq__Input (ilu_Call, Unit_ShortSeq*, ilu_Error *);
extern void Unit_ShortSeq__Free (Unit_ShortSeq*);
Unit_ShortSeq* Unit_ShortSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitSBHSeq__IoFns;
#define TC_Unit_UnitSBHSeq (& _Unit_UnitSBHSeq__IoFns)
extern void _Unit_UnitSBHSeq__Output (ilu_Call, Unit_UnitSBHSeq*, ilu_Error *);
extern ilu_cardinal _Unit_UnitSBHSeq__SizeOf (ilu_Call, Unit_UnitSBHSeq*, ilu_Error *);
extern Unit_UnitSBHSeq* _Unit_UnitSBHSeq__Input (ilu_Call, Unit_UnitSBHSeq*, ilu_Error *);
extern void Unit_UnitSBHSeq__Free (Unit_UnitSBHSeq*);
Unit_UnitSBHSeq* Unit_UnitSBHSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitIDSeq__IoFns;
#define TC_Unit_UnitIDSeq (& _Unit_UnitIDSeq__IoFns)
extern void _Unit_UnitIDSeq__Output (ilu_Call, Unit_UnitIDSeq*, ilu_Error *);
extern ilu_cardinal _Unit_UnitIDSeq__SizeOf (ilu_Call, Unit_UnitIDSeq*, ilu_Error *);
extern Unit_UnitIDSeq* _Unit_UnitIDSeq__Input (ilu_Call, Unit_UnitIDSeq*, ilu_Error *);
extern void Unit_UnitIDSeq__Free (Unit_UnitIDSeq*);
Unit_UnitIDSeq* Unit_UnitIDSeq__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitSBH__IoFns;
#define TC_Unit_UnitSBH (& _Unit_UnitSBH__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _Unit_UnitID__IoFns;
#define TC_Unit_UnitID (& _Unit_UnitID__IoFns)

extern ilu_Class _Unit_rpc__ILUType;
extern Unit_UnitID _Unit_rpc_getID__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Unit_UnitSBH _Unit_rpc_getCosNamingSBH__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern Unit_UnitInfo* _Unit_rpc_getFrontUnitInfo__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_setRole__clientstub (Unit_rpc _handle, Unit_UnitRole role, Unit_UnitSBH consoleSBH, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_setMode__clientstub (Unit_rpc _handle, Unit_UnitMode mode, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_setMinorMode__clientstub (Unit_rpc _handle, Unit_UnitMinorMode minorMode, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_sendMoveAction__clientstub (Unit_rpc _handle, Unit_MoveAction* action, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_sendMoveActionSeq__clientstub (Unit_rpc _handle, Unit_ActionSeq* actions, CORBA_short times, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_setALeader__clientstub (Unit_rpc _handle, Unit_UnitSBH leaderSBH, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_unregisterFollower__clientstub (Unit_rpc _handle, Unit_UnitID followerUID, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_setFollower__clientstub (Unit_rpc _handle, Unit_UnitInfo* ui, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_unsetFollower__clientstub (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_addRearVehicle__clientstub (Unit_rpc _handle, Unit_UnitInfo* rearInfo, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_deleteRearVehicle__clientstub (Unit_rpc _handle, Unit_UnitID uid, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_setFormation__clientstub (Unit_rpc _handle, Unit_Formation* form, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_setRearVehicles__clientstub (Unit_rpc _handle, Unit_UnitInfoSeq* rears, CORBA_float distance, CORBA_float angle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_reportDeadVehicle__clientstub (Unit_rpc _handle, Unit_UnitID uid, ilu_CString details, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_shutDown__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_startPhotoStream__clientstub (Unit_rpc _handle, CORBA_float frequency, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_stopPhotoStream__clientstub (Unit_rpc _handle, ILU_C_ENVIRONMENT *_status);
extern CORBA_boolean _Unit_rpc_takePicture__clientstub (Unit_rpc _handle, CORBA_long time, CORBA_long procedureStartTime, ILU_C_ENVIRONMENT *_status);

extern void _Unit__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __Unit_h_ */
