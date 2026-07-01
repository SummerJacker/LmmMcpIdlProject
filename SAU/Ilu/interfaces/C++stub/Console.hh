/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:31:08 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Console_H_
#define __Console_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */

#ifndef __Ground_Unit_H_
#include "Ground_Unit.hh"
#endif /* ndef __Ground_Unit_H_ */

#ifndef __Air_Unit_H_
#include "Air_Unit.hh"
#endif /* ndef __Air_Unit_H_ */

#ifndef __Unit_H_
#include "Unit.hh"
#endif /* ndef __Unit_H_ */


typedef struct _Console_Status_struct ConsoleStatus;

typedef enum _Console_T_FormationType_enum {Console_T_FormationType_OneLine = 0, Console_T_FormationType_Matrix = 1, Console_T_FormationType_WildGoose = 2} Console_T_FormationType;
typedef enum _Console_T_TrackMode_enum {Console_T_TrackMode_RouteTrack = 0, Console_T_TrackMode_ObjectTrack = 1} Console_T_TrackMode;
typedef enum _Console_T_FormationState_enum {Console_T_FormationState_FormationImplement = 0, Console_T_FormationState_FormationSuspend = 1, Console_T_FormationState_FormationSuccess = 2, Console_T_FormationState_FormationFail = 3} Console_T_FormationState;
typedef enum _Console_T_MissionState_enum {Console_T_MissionState_MssionImplement = 0, Console_T_MissionState_MissionSuspend = 1, Console_T_MissionState_MissionSuccess = 2, Console_T_MissionState_MissionFail = 3, Console_T_MissionState_MissionCancel = 4} Console_T_MissionState;
class Console_T_rpc;
typedef enum _Console_T_TrapType_enum {Console_T_TrapType_TrapGroundType = 0, Console_T_TrapType_TrapAirType = 1} Console_T_TrapType;
typedef struct _Console_T_TrapPoint_union Console_T_TrapPoint;
typedef class _Console_T_TrapPointSeq_sequence * Console_T_TrapPointSeq;
typedef enum _Console_T_PointType_enum {Console_T_PointType_PointGroundType = 0, Console_T_PointType_PointAirType = 1} Console_T_PointType;
typedef struct _Console_T_Point_union Console_T_Point;
typedef class _Console_T_PointSeq_sequence * Console_T_PointSeq;
typedef enum _Console_T_Operation_enum {Console_T_Operation_OP_SetCosInfo = 0, Console_T_Operation_OP_Bind = 1, Console_T_Operation_OP_Unbind = 2, Console_T_Operation_OP_Opened = 3, Console_T_Operation_OP_Closed = 4, Console_T_Operation_OP_ReportTrap = 5, Console_T_Operation_OP_AddTrap = 6} Console_T_Operation;
typedef struct _Console_T_UnbindData_record Console_T_UnbindData;
typedef struct _Console_T_Message_union Console_T_Message;
typedef struct _Console_T_MissionStateData_union Console_T_MissionStateData;



/* declaration of C++ class "Console_T_rpc"
   from ILU class "Console:rpc"  */


class Console_T_rpc : public virtual ilu_T_CORBA_Object {

 public:

  Console_T_rpc();			// constructor
  virtual ~Console_T_rpc();		// destructor

 // class procedures

  static class Console_T_rpc * ILUCreateFromSBH(ilu_CString sbh);
  static class Console_T_rpc * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Unit_T_UnitInfoSeq getCosNamingInfo (ConsoleStatus *_status);
  virtual ilu_Boolean sendMsg (ConsoleStatus *_status, Console_T_Message * m);
  virtual ilu_Boolean bind (ConsoleStatus *_status, Unit_T_UnitID uid, Unit_T_UnitSBH sbh);
  virtual ilu_Boolean unbind (ConsoleStatus *_status, Unit_T_UnitID uid, ilu_T_CString details);
  virtual ilu_Boolean rebind (ConsoleStatus *_status, Unit_T_UnitID uid, Unit_T_UnitSBH sbh);
  virtual ilu_Boolean setNickname (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo, ilu_T_CString newName);
  virtual ilu_Boolean setPosition (ConsoleStatus *_status, ilu_T_CString name, Console_T_Point * p);
  virtual ilu_Boolean addGoalPoint (ConsoleStatus *_status, Console_T_Point * p);
  virtual ilu_Boolean setGoalPoint (ConsoleStatus *_status, Console_T_Point * p);
  virtual ilu_Boolean setRole (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo, Unit_T_UnitRole r);
  virtual ilu_Boolean cancelRole (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo);
  virtual ilu_Boolean setTrapPoint (ConsoleStatus *_status, Console_T_TrapPoint * p);
  virtual ilu_Boolean setFollow (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo1, Unit_T_UnitInfo * uinfo2);
  virtual ilu_Boolean setFormationType (ConsoleStatus *_status, Console_T_FormationType f);
  virtual ilu_Boolean setTrackMode (ConsoleStatus *_status, Console_T_TrackMode tm);
  virtual Unit_T_UnitInfo * getCurrentUnit (ConsoleStatus *_status);
  virtual ilu_ShortInteger getUnitNum (ConsoleStatus *_status);
  virtual ilu_ShortInteger getFormationNum (ConsoleStatus *_status);
  virtual ilu_ShortInteger getTrapNum (ConsoleStatus *_status);
  virtual Console_T_FormationType getFormationType (ConsoleStatus *_status);
  virtual Console_T_FormationState getFormationState (ConsoleStatus *_status);
  virtual Console_T_MissionState getMissionState (ConsoleStatus *_status);
  virtual Console_T_Point * getUnitPoint (ConsoleStatus *_status, ilu_T_CString name);
  virtual Unit_T_UnitInfo * getByName (ConsoleStatus *_status, ilu_T_CString name);
  virtual Console_T_Point * getLeaderPoint (ConsoleStatus *_status);
  virtual Console_T_PointSeq getPointSeq (ConsoleStatus *_status);
  virtual ilu_Boolean cancelFormation (ConsoleStatus *_status);
  virtual ilu_Boolean setLeaderSuspend (ConsoleStatus *_status);
  virtual ilu_Boolean recoveryLeaderAction (ConsoleStatus *_status);
  virtual ilu_Boolean addUnitFormation (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo);
  virtual ilu_Boolean deleteUnitFormation (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo);
  virtual ilu_Boolean setUnitFault (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo);
  virtual ilu_Boolean setUnitFaultPosition (ConsoleStatus *_status, Unit_T_UnitInfo * uinfo);
  virtual ilu_Boolean setFormationState (ConsoleStatus *_status, Console_T_FormationState fs);
  virtual ilu_Boolean setMissionState (ConsoleStatus *_status, Console_T_MissionStateData * msd);

 // data slots for cacheable methods -- if any

};

struct _Console_T_TrapPoint_union {
	Console_T_TrapType discriminator;
	union {
		Ground_Unit_T_TrapPoint2D trapPoint2D;
		Air_Unit_T_TrapPoint3D trapPoint3D;
	} value;
};
  class _Console_T_TrapPointSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Console_T_TrapPoint *_buffer;
   public:
    _Console_T_TrapPointSeq_sequence ();
    virtual ~_Console_T_TrapPointSeq_sequence ();
    static class _Console_T_TrapPointSeq_sequence *Create (ilu_Cardinal initial_size, Console_T_TrapPoint *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Console_T_TrapPoint *);
    virtual Console_T_TrapPoint * RemoveHead();
    virtual Console_T_TrapPoint * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Console_T_TrapPoint *, void *), void *arg);
    virtual Console_T_TrapPoint * Find(ilu_Boolean (*matchproc)(Console_T_TrapPoint *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Console_T_TrapPoint *, void *), void *arg);
    virtual Console_T_TrapPoint * Array();
    virtual Console_T_TrapPoint * Nth(ilu_Cardinal index);
  };

struct _Console_T_Point_union {
	Console_T_PointType discriminator;
	union {
		Ground_Unit_T_Point2D p2D;
		Air_Unit_T_Point3D p3D;
	} value;
};
  class _Console_T_PointSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Console_T_Point *_buffer;
   public:
    _Console_T_PointSeq_sequence ();
    virtual ~_Console_T_PointSeq_sequence ();
    static class _Console_T_PointSeq_sequence *Create (ilu_Cardinal initial_size, Console_T_Point *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Console_T_Point *);
    virtual Console_T_Point * RemoveHead();
    virtual Console_T_Point * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Console_T_Point *, void *), void *arg);
    virtual Console_T_Point * Find(ilu_Boolean (*matchproc)(Console_T_Point *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Console_T_Point *, void *), void *arg);
    virtual Console_T_Point * Array();
    virtual Console_T_Point * Nth(ilu_Cardinal index);
  };

struct _Console_T_UnbindData_record {
	Unit_T_UnitID uid;
	ilu_T_CString details;
};
struct _Console_T_Message_union {
	Console_T_Operation discriminator;
	union {
		Unit_T_UnitInfoSeq infoSeq;
		Unit_T_UnitInfo bindInfo;
		Console_T_UnbindData unbindInfo;
		Console_T_TrapPoint tp;
		ilu_T_CString details;
	} value;
};
struct _Console_T_MissionStateData_union {
	Console_T_MissionState discriminator;
	union {
		ilu_ShortInteger time;
	} value;
};

class Console_G {

 public:

  static struct Console_Exceptions_s *Exceptions();
  static void RaiseException (ConsoleStatus *status, ilu_Exception exception...);

  static void Free_UnitInfoSeq (Unit_T_UnitInfoSeq val);
  static ilu_Boolean Output_TrapPointSeq (iluCall call, Console_T_TrapPointSeq val);
  static Console_T_TrapPointSeq Input_TrapPointSeq (iluCall call, Console_T_TrapPointSeq ref);
  static ilu_Cardinal SizeOf_TrapPointSeq (iluCall call, Console_T_TrapPointSeq val);

  static void Free_TrapPointSeq (Console_T_TrapPointSeq val);
  static ilu_Boolean Output_PointSeq (iluCall call, Console_T_PointSeq val);
  static Console_T_PointSeq Input_PointSeq (iluCall call, Console_T_PointSeq ref);
  static ilu_Cardinal SizeOf_PointSeq (iluCall call, Console_T_PointSeq val);

  static void Free_PointSeq (Console_T_PointSeq val);
  static void Free_UnitInfoSeq (Unit_T_UnitInfoSeq val);
  static ilu_Boolean Output_Message (iluCall call, Console_T_Message * val);
  static Console_T_Message * Input_Message (iluCall call, Console_T_Message * ref);
  static ilu_Cardinal SizeOf_Message (iluCall call, Console_T_Message * val);

  static void Free_Message (Console_T_Message * val);
  static ilu_Boolean Output_UnbindData (iluCall call, Console_T_UnbindData * val);
  static Console_T_UnbindData * Input_UnbindData (iluCall call, Console_T_UnbindData * ref);
  static ilu_Cardinal SizeOf_UnbindData (iluCall call, Console_T_UnbindData * val);

  static ilu_Boolean Output_TrapPoint (iluCall call, Console_T_TrapPoint * val);
  static Console_T_TrapPoint * Input_TrapPoint (iluCall call, Console_T_TrapPoint * ref);
  static ilu_Cardinal SizeOf_TrapPoint (iluCall call, Console_T_TrapPoint * val);

  static ilu_Boolean Output_Point (iluCall call, Console_T_Point * val);
  static Console_T_Point * Input_Point (iluCall call, Console_T_Point * ref);
  static ilu_Cardinal SizeOf_Point (iluCall call, Console_T_Point * val);

  static ilu_Boolean Output_MissionStateData (iluCall call, Console_T_MissionStateData * val);
  static Console_T_MissionStateData * Input_MissionStateData (iluCall call, Console_T_MissionStateData * ref);
  static ilu_Cardinal SizeOf_MissionStateData (iluCall call, Console_T_MissionStateData * val);

/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, ConsoleStatus *status);
};

#define ConsoleReply_Success		((ilu_Exception) NULL)

struct _Console_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
	} values;
};

struct Console_Exceptions_s {
	ilu_Exception rpc_AlreadyBind;
	ilu_Exception rpc_NotFound;
};

#define Console_E_rpc_AlreadyBind		(Console_G::Exceptions()->rpc_AlreadyBind)
#define Console_E_rpc_NotFound		(Console_G::Exceptions()->rpc_NotFound)

extern void Console__Initialize(void);	//ILU private

#endif /* ndef __Console_H_ */
