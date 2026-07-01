/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:33:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/monitor.idl" of Wed Jul 16 16:43:00 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/console.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Monitor_H_
#define __Monitor_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */

#ifndef __Ground_Unit_H_
#include "Ground_Unit.hh"
#endif /* ndef __Ground_Unit_H_ */

#ifndef __Air_Unit_H_
#include "Air_Unit.hh"
#endif /* ndef __Air_Unit_H_ */

#ifndef __Console_H_
#include "Console.hh"
#endif /* ndef __Console_H_ */

#ifndef __Unit_H_
#include "Unit.hh"
#endif /* ndef __Unit_H_ */


typedef struct _Monitor_Status_struct MonitorStatus;

typedef enum _Monitor_T_BackHomeReason_enum {Monitor_T_BackHomeReason_LowBattery = 0, Monitor_T_BackHomeReason_EmptyLoad = 1, Monitor_T_BackHomeReason_TaskDone = 2, Monitor_T_BackHomeReason_TaskStop = 3} Monitor_T_BackHomeReason;
typedef enum _Monitor_T_MissionSituation_enum {Monitor_T_MissionSituation_Success = 0, Monitor_T_MissionSituation_StillBurning = 1, Monitor_T_MissionSituation_Locating = 2, Monitor_T_MissionSituation_Processing = 3} Monitor_T_MissionSituation;
class Monitor_T_rpc;
typedef class _Monitor_T_PictureFlow_sequence * Monitor_T_PictureFlow;
typedef enum _Monitor_T_UnitType_enum {Monitor_T_UnitType_UnitGroundType = 0, Monitor_T_UnitType_UnitAirType = 1} Monitor_T_UnitType;
typedef struct _Monitor_T_CurrentUnitInfo_union Monitor_T_CurrentUnitInfo;
typedef struct _Monitor_T_PictureInfo_record Monitor_T_PictureInfo;
typedef ilu_T_CString Monitor_T_TargetID;
#define Monitor_T_TargetID ilu_T_CString
typedef enum _Monitor_T_TargetType_enum {Monitor_T_TargetType_Fire = 0, Monitor_T_TargetType_Person = 1, Monitor_T_TargetType_Vehicle = 2, Monitor_T_TargetType_Drone = 3} Monitor_T_TargetType;
typedef struct _Monitor_T_UnitState_record Monitor_T_UnitState;
typedef struct _Monitor_T_CompleteUnitInfo_record Monitor_T_CompleteUnitInfo;



/* declaration of C++ class "Monitor_T_rpc"
   from ILU class "Monitor:rpc"  */


class Monitor_T_rpc : public virtual ilu_T_CORBA_Object {

 public:

  Monitor_T_rpc();			// constructor
  virtual ~Monitor_T_rpc();		// destructor

 // class procedures

  static class Monitor_T_rpc * ILUCreateFromSBH(ilu_CString sbh);
  static class Monitor_T_rpc * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual ilu_Boolean sendUnitInfo (MonitorStatus *_status, Monitor_T_CompleteUnitInfo * unitInfo);
  virtual ilu_Boolean sendTrapPoint (MonitorStatus *_status, Console_T_TrapPoint * tp);
  virtual ilu_Boolean sendTargetLocation (MonitorStatus *_status, Monitor_T_TargetID fid, Ground_Unit_T_Point2D * fp, ilu_ShortInteger responseTime);
  virtual ilu_Boolean foundTarget (MonitorStatus *_status, Monitor_T_TargetID fid, Monitor_T_PictureInfo * pi);
  virtual ilu_Boolean confirmAction (MonitorStatus *_status, Monitor_T_TargetID fid, ilu_ShortInteger responseTime);
  virtual ilu_Boolean backHome (MonitorStatus *_status, Unit_T_UnitID uid, Monitor_T_BackHomeReason bhr);
  virtual ilu_Boolean sendMissionState (MonitorStatus *_status, Monitor_T_TargetID fid, Monitor_T_MissionSituation ms);
  virtual ilu_Boolean sendPicture (MonitorStatus *_status, ilu_T_CString pictureName, Monitor_T_PictureFlow pic, ilu_Integer time, ilu_Integer procedureStartTime);

 // data slots for cacheable methods -- if any

};

  class _Monitor_T_PictureFlow_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    ilu_Byte *_buffer;
   public:
    _Monitor_T_PictureFlow_sequence ();
    virtual ~_Monitor_T_PictureFlow_sequence ();
    static class _Monitor_T_PictureFlow_sequence *Create (ilu_Cardinal initial_size, ilu_Byte *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(ilu_Byte);
    virtual ilu_Byte RemoveHead();
    virtual ilu_Byte RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg);
    virtual ilu_Byte Find(ilu_Boolean (*matchproc)(ilu_Byte, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(ilu_Byte, void *), void *arg);
    virtual ilu_Byte * Array();
    virtual ilu_Byte Nth(ilu_Cardinal index);
  };

struct _Monitor_T_CurrentUnitInfo_union {
	Monitor_T_UnitType discriminator;
	union {
		Ground_Unit_T_GroundUnitInfo groundUnitInfo;
		Air_Unit_T_AirUnitInfo airUnitInfo;
	} value;
};
struct _Monitor_T_PictureInfo_record {
	ilu_T_CString picturName;
	Monitor_T_PictureFlow pic;
	Monitor_T_CurrentUnitInfo cui;
	ilu_ShortInteger responseTime;
};
struct _Monitor_T_UnitState_record {
	ilu_ShortInteger health;
	ilu_ShortInteger battery;
};
struct _Monitor_T_CompleteUnitInfo_record {
	Monitor_T_UnitState us;
	Monitor_T_CurrentUnitInfo cui;
};

class Monitor_G {

 public:

  static struct Monitor_Exceptions_s *Exceptions();
  static void RaiseException (MonitorStatus *status, ilu_Exception exception...);

  static ilu_Boolean Output_PictureInfo (iluCall call, Monitor_T_PictureInfo * val);
  static Monitor_T_PictureInfo * Input_PictureInfo (iluCall call, Monitor_T_PictureInfo * ref);
  static ilu_Cardinal SizeOf_PictureInfo (iluCall call, Monitor_T_PictureInfo * val);

  static void Free_PictureInfo (Monitor_T_PictureInfo * val);
  static ilu_Boolean Output_PictureFlow (iluCall call, Monitor_T_PictureFlow val);
  static Monitor_T_PictureFlow Input_PictureFlow (iluCall call, Monitor_T_PictureFlow ref);
  static ilu_Cardinal SizeOf_PictureFlow (iluCall call, Monitor_T_PictureFlow val);

  static void Free_PictureFlow (Monitor_T_PictureFlow val);
  static ilu_Boolean Output_CompleteUnitInfo (iluCall call, Monitor_T_CompleteUnitInfo * val);
  static Monitor_T_CompleteUnitInfo * Input_CompleteUnitInfo (iluCall call, Monitor_T_CompleteUnitInfo * ref);
  static ilu_Cardinal SizeOf_CompleteUnitInfo (iluCall call, Monitor_T_CompleteUnitInfo * val);

  static ilu_Boolean Output_CurrentUnitInfo (iluCall call, Monitor_T_CurrentUnitInfo * val);
  static Monitor_T_CurrentUnitInfo * Input_CurrentUnitInfo (iluCall call, Monitor_T_CurrentUnitInfo * ref);
  static ilu_Cardinal SizeOf_CurrentUnitInfo (iluCall call, Monitor_T_CurrentUnitInfo * val);

  static ilu_Boolean Output_UnitState (iluCall call, Monitor_T_UnitState * val);
  static Monitor_T_UnitState * Input_UnitState (iluCall call, Monitor_T_UnitState * ref);
  static ilu_Cardinal SizeOf_UnitState (iluCall call, Monitor_T_UnitState * val);

/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, MonitorStatus *status);
};

#define MonitorReply_Success		((ilu_Exception) NULL)

struct _Monitor_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
	} values;
};

struct Monitor_Exceptions_s {
	ilu_CString dummyException;
};


extern void Monitor__Initialize(void);	//ILU private

#endif /* ndef __Monitor_H_ */
