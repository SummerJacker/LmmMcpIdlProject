/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:30:56 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/air_unit.idl" of Fri Jul 18 15:18:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Air_Unit_H_
#define __Air_Unit_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */

#ifndef __Unit_H_
#include "Unit.hh"
#endif /* ndef __Unit_H_ */


typedef struct _Air_Unit_Status_struct Air_UnitStatus;

typedef enum _Air_Unit_T_ActionRole_enum {Air_Unit_T_ActionRole_Actor = 0, Air_Unit_T_ActionRole_Standby = 1, Air_Unit_T_ActionRole_Facilitators = 2} Air_Unit_T_ActionRole;
typedef enum _Air_Unit_T_ActionMode_enum {Air_Unit_T_ActionMode_Nothing = 0, Air_Unit_T_ActionMode_Cruise = 1, Air_Unit_T_ActionMode_Locate = 2, Air_Unit_T_ActionMode_Assist = 3, Air_Unit_T_ActionMode_Feedback = 4} Air_Unit_T_ActionMode;
class Air_Unit_T_rpc;
typedef struct _Air_Unit_T_Point3D_record Air_Unit_T_Point3D;
typedef struct _Air_Unit_T_TrapPoint3D_record Air_Unit_T_TrapPoint3D;
typedef class _Air_Unit_T_TrapPointSeq_sequence * Air_Unit_T_TrapPointSeq;
typedef class _Air_Unit_T_TaskPath_sequence * Air_Unit_T_TaskPath;
typedef enum _Air_Unit_T_SiteType_enum {Air_Unit_T_SiteType_Rectangle = 0, Air_Unit_T_SiteType_Circle = 1} Air_Unit_T_SiteType;
typedef struct _Air_Unit_T_RectangleData_record Air_Unit_T_RectangleData;
typedef struct _Air_Unit_T_CircleData_record Air_Unit_T_CircleData;
typedef struct _Air_Unit_T_Site_union Air_Unit_T_Site;
typedef struct _Air_Unit_T_Speed3D_record Air_Unit_T_Speed3D;
typedef struct _Air_Unit_T_FusionAngularVelocity_record Air_Unit_T_FusionAngularVelocity;
typedef struct _Air_Unit_T_GPSInfo_record Air_Unit_T_GPSInfo;
typedef struct _Air_Unit_T_GimbalState_record Air_Unit_T_GimbalState;
typedef struct _Air_Unit_T_AirUnitInfo_record Air_Unit_T_AirUnitInfo;
typedef struct _Air_Unit_T_Pose3D_record Air_Unit_T_Pose3D;
typedef struct _Air_Unit_T_GimbalSpeed_record Air_Unit_T_GimbalSpeed;



/* declaration of C++ class "Air_Unit_T_rpc"
   from ILU class "Air-Unit:rpc"  */


class Air_Unit_T_rpc : public virtual Unit_T_rpc {

 public:

  Air_Unit_T_rpc();			// constructor
  virtual ~Air_Unit_T_rpc();		// destructor

 // class procedures

  static class Air_Unit_T_rpc * ILUCreateFromSBH(ilu_CString sbh);
  static class Air_Unit_T_rpc * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Air_Unit_T_Speed3D * getCurrentSpeed (Air_UnitStatus *_status);
  virtual Air_Unit_T_Pose3D * getCurrentPose (Air_UnitStatus *_status);
  virtual Air_Unit_T_AirUnitInfo * getCurrentInfo (Air_UnitStatus *_status);
  virtual ilu_Boolean sendGimbalSpeed (Air_UnitStatus *_status, Air_Unit_T_GimbalSpeed * speed);
  virtual ilu_Boolean resetGimbal (Air_UnitStatus *_status);
  virtual ilu_Boolean sendVehicleInfo (Air_UnitStatus *_status, Air_Unit_T_AirUnitInfo * info);
  virtual ilu_Boolean reportTrap (Air_UnitStatus *_status, Air_Unit_T_TrapPoint3D * trap);
  virtual ilu_Boolean clearTraps (Air_UnitStatus *_status);
  virtual Air_Unit_T_TrapPointSeq getTraps (Air_UnitStatus *_status);
  virtual ilu_Boolean setTrapPoint (Air_UnitStatus *_status, Air_Unit_T_TrapPoint3D * trap);
  virtual ilu_Boolean setTrack (Air_UnitStatus *_status, Air_Unit_T_TaskPath track);
  virtual ilu_Boolean setTaskPath (Air_UnitStatus *_status, Air_Unit_T_TaskPath path);
  virtual ilu_Boolean setTaskPoint (Air_UnitStatus *_status, Air_Unit_T_Point3D * point);
  virtual ilu_Boolean clearTaskPoint (Air_UnitStatus *_status);
  virtual ilu_Boolean obtainCtrlAuthority (Air_UnitStatus *_status);
  virtual ilu_Boolean releaseCtrlAuthority (Air_UnitStatus *_status);
  virtual ilu_Boolean setActionRole (Air_UnitStatus *_status, Air_Unit_T_ActionRole ar);
  virtual ilu_Boolean setActionMode (Air_UnitStatus *_status, Air_Unit_T_ActionMode am);
  virtual ilu_Boolean setCruiseScope (Air_UnitStatus *_status, Air_Unit_T_Site * s);
  virtual ilu_Boolean sendControlledVehicle (Air_UnitStatus *_status, Unit_T_UnitSBHSeq uss);
  virtual ilu_Boolean confirmThrow (Air_UnitStatus *_status);
  virtual ilu_Boolean cancelThrow (Air_UnitStatus *_status);
  virtual ilu_Boolean actionThrow (Air_UnitStatus *_status);
  virtual ilu_Boolean confirmFire (Air_UnitStatus *_status);
  virtual ilu_Boolean cancelFire (Air_UnitStatus *_status);
  virtual ilu_Boolean confirmFireLocation (Air_UnitStatus *_status);
  virtual ilu_Boolean cancelFireLocation (Air_UnitStatus *_status);
  virtual ilu_Boolean controlVehicleVelocity (Air_UnitStatus *_status, ilu_ShortReal vx, ilu_ShortReal vy, ilu_ShortReal vz, ilu_ShortReal angle);
  virtual ilu_Boolean backHome (Air_UnitStatus *_status);
  virtual ilu_Boolean setCruiseSpeed (Air_UnitStatus *_status, ilu_ShortReal cs);

 // data slots for cacheable methods -- if any

};

struct _Air_Unit_T_Point3D_record {
	ilu_ShortReal x;
	ilu_ShortReal y;
	ilu_ShortReal z;
};
struct _Air_Unit_T_TrapPoint3D_record {
	Air_Unit_T_Point3D point;
	ilu_ShortReal radius;
};
  class _Air_Unit_T_TrapPointSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Air_Unit_T_TrapPoint3D *_buffer;
   public:
    _Air_Unit_T_TrapPointSeq_sequence ();
    virtual ~_Air_Unit_T_TrapPointSeq_sequence ();
    static class _Air_Unit_T_TrapPointSeq_sequence *Create (ilu_Cardinal initial_size, Air_Unit_T_TrapPoint3D *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Air_Unit_T_TrapPoint3D *);
    virtual Air_Unit_T_TrapPoint3D * RemoveHead();
    virtual Air_Unit_T_TrapPoint3D * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Air_Unit_T_TrapPoint3D *, void *), void *arg);
    virtual Air_Unit_T_TrapPoint3D * Find(ilu_Boolean (*matchproc)(Air_Unit_T_TrapPoint3D *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Air_Unit_T_TrapPoint3D *, void *), void *arg);
    virtual Air_Unit_T_TrapPoint3D * Array();
    virtual Air_Unit_T_TrapPoint3D * Nth(ilu_Cardinal index);
  };

  class _Air_Unit_T_TaskPath_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Air_Unit_T_Point3D *_buffer;
   public:
    _Air_Unit_T_TaskPath_sequence ();
    virtual ~_Air_Unit_T_TaskPath_sequence ();
    static class _Air_Unit_T_TaskPath_sequence *Create (ilu_Cardinal initial_size, Air_Unit_T_Point3D *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Air_Unit_T_Point3D *);
    virtual Air_Unit_T_Point3D * RemoveHead();
    virtual Air_Unit_T_Point3D * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Air_Unit_T_Point3D *, void *), void *arg);
    virtual Air_Unit_T_Point3D * Find(ilu_Boolean (*matchproc)(Air_Unit_T_Point3D *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Air_Unit_T_Point3D *, void *), void *arg);
    virtual Air_Unit_T_Point3D * Array();
    virtual Air_Unit_T_Point3D * Nth(ilu_Cardinal index);
  };

struct _Air_Unit_T_RectangleData_record {
	Air_Unit_T_Point3D po;
	ilu_ShortInteger x;
	ilu_ShortInteger y;
};
struct _Air_Unit_T_CircleData_record {
	Air_Unit_T_Point3D po;
	ilu_ShortInteger r;
};
struct _Air_Unit_T_Site_union {
	Air_Unit_T_SiteType discriminator;
	union {
		Air_Unit_T_RectangleData rd;
		Air_Unit_T_CircleData cd;
	} value;
};
struct _Air_Unit_T_Speed3D_record {
	ilu_ShortReal x;
	ilu_ShortReal y;
	ilu_ShortReal z;
};
struct _Air_Unit_T_FusionAngularVelocity_record {
	ilu_ShortReal x;
	ilu_ShortReal y;
	ilu_ShortReal z;
};
struct _Air_Unit_T_GPSInfo_record {
	ilu_ShortReal longitude;
	ilu_ShortReal latitude;
	ilu_ShortReal altitude;
	ilu_ShortReal height;
	ilu_ShortReal time;
	ilu_ShortInteger health;
};
struct _Air_Unit_T_GimbalState_record {
	ilu_ShortReal yaw;
	ilu_ShortReal roll;
	ilu_ShortReal pitch;
};
struct _Air_Unit_T_AirUnitInfo_record {
	Unit_T_UnitInfo info;
	Unit_T_UnitRole role;
	Air_Unit_T_Speed3D speed;
	Air_Unit_T_FusionAngularVelocity angularVelocity;
	Air_Unit_T_GPSInfo gps;
	Air_Unit_T_GimbalState gs;
};
struct _Air_Unit_T_Pose3D_record {
	ilu_ShortReal x;
	ilu_ShortReal y;
	ilu_ShortReal z;
	ilu_ShortReal pitch;
	ilu_ShortReal yaw;
	ilu_ShortReal roll;
};
struct _Air_Unit_T_GimbalSpeed_record {
	ilu_ShortReal yaw;
	ilu_ShortReal roll;
	ilu_ShortReal pitch;
};

class Air_Unit_G {

 public:

  static struct Air_Unit_Exceptions_s *Exceptions();
  static void RaiseException (Air_UnitStatus *status, ilu_Exception exception...);

  static void Free_UnitSBHSeq (Unit_T_UnitSBHSeq val);
  static ilu_Boolean Output_TrapPointSeq (iluCall call, Air_Unit_T_TrapPointSeq val);
  static Air_Unit_T_TrapPointSeq Input_TrapPointSeq (iluCall call, Air_Unit_T_TrapPointSeq ref);
  static ilu_Cardinal SizeOf_TrapPointSeq (iluCall call, Air_Unit_T_TrapPointSeq val);

  static void Free_TrapPointSeq (Air_Unit_T_TrapPointSeq val);
  static ilu_Boolean Output_TaskPath (iluCall call, Air_Unit_T_TaskPath val);
  static Air_Unit_T_TaskPath Input_TaskPath (iluCall call, Air_Unit_T_TaskPath ref);
  static ilu_Cardinal SizeOf_TaskPath (iluCall call, Air_Unit_T_TaskPath val);

  static void Free_TaskPath (Air_Unit_T_TaskPath val);
  static ilu_Boolean Output_Site (iluCall call, Air_Unit_T_Site * val);
  static Air_Unit_T_Site * Input_Site (iluCall call, Air_Unit_T_Site * ref);
  static ilu_Cardinal SizeOf_Site (iluCall call, Air_Unit_T_Site * val);

  static ilu_Boolean Output_CircleData (iluCall call, Air_Unit_T_CircleData * val);
  static Air_Unit_T_CircleData * Input_CircleData (iluCall call, Air_Unit_T_CircleData * ref);
  static ilu_Cardinal SizeOf_CircleData (iluCall call, Air_Unit_T_CircleData * val);

  static ilu_Boolean Output_RectangleData (iluCall call, Air_Unit_T_RectangleData * val);
  static Air_Unit_T_RectangleData * Input_RectangleData (iluCall call, Air_Unit_T_RectangleData * ref);
  static ilu_Cardinal SizeOf_RectangleData (iluCall call, Air_Unit_T_RectangleData * val);

  static ilu_Boolean Output_TrapPoint3D (iluCall call, Air_Unit_T_TrapPoint3D * val);
  static Air_Unit_T_TrapPoint3D * Input_TrapPoint3D (iluCall call, Air_Unit_T_TrapPoint3D * ref);
  static ilu_Cardinal SizeOf_TrapPoint3D (iluCall call, Air_Unit_T_TrapPoint3D * val);

  static ilu_Boolean Output_Point3D (iluCall call, Air_Unit_T_Point3D * val);
  static Air_Unit_T_Point3D * Input_Point3D (iluCall call, Air_Unit_T_Point3D * ref);
  static ilu_Cardinal SizeOf_Point3D (iluCall call, Air_Unit_T_Point3D * val);

  static ilu_Boolean Output_AirUnitInfo (iluCall call, Air_Unit_T_AirUnitInfo * val);
  static Air_Unit_T_AirUnitInfo * Input_AirUnitInfo (iluCall call, Air_Unit_T_AirUnitInfo * ref);
  static ilu_Cardinal SizeOf_AirUnitInfo (iluCall call, Air_Unit_T_AirUnitInfo * val);

  static ilu_Boolean Output_FusionAngularVelocity (iluCall call, Air_Unit_T_FusionAngularVelocity * val);
  static Air_Unit_T_FusionAngularVelocity * Input_FusionAngularVelocity (iluCall call, Air_Unit_T_FusionAngularVelocity * ref);
  static ilu_Cardinal SizeOf_FusionAngularVelocity (iluCall call, Air_Unit_T_FusionAngularVelocity * val);

  static ilu_Boolean Output_Speed3D (iluCall call, Air_Unit_T_Speed3D * val);
  static Air_Unit_T_Speed3D * Input_Speed3D (iluCall call, Air_Unit_T_Speed3D * ref);
  static ilu_Cardinal SizeOf_Speed3D (iluCall call, Air_Unit_T_Speed3D * val);

  static ilu_Boolean Output_GPSInfo (iluCall call, Air_Unit_T_GPSInfo * val);
  static Air_Unit_T_GPSInfo * Input_GPSInfo (iluCall call, Air_Unit_T_GPSInfo * ref);
  static ilu_Cardinal SizeOf_GPSInfo (iluCall call, Air_Unit_T_GPSInfo * val);

  static ilu_Boolean Output_Pose3D (iluCall call, Air_Unit_T_Pose3D * val);
  static Air_Unit_T_Pose3D * Input_Pose3D (iluCall call, Air_Unit_T_Pose3D * ref);
  static ilu_Cardinal SizeOf_Pose3D (iluCall call, Air_Unit_T_Pose3D * val);

  static ilu_Boolean Output_GimbalState (iluCall call, Air_Unit_T_GimbalState * val);
  static Air_Unit_T_GimbalState * Input_GimbalState (iluCall call, Air_Unit_T_GimbalState * ref);
  static ilu_Cardinal SizeOf_GimbalState (iluCall call, Air_Unit_T_GimbalState * val);

  static ilu_Boolean Output_GimbalSpeed (iluCall call, Air_Unit_T_GimbalSpeed * val);
  static Air_Unit_T_GimbalSpeed * Input_GimbalSpeed (iluCall call, Air_Unit_T_GimbalSpeed * ref);
  static ilu_Cardinal SizeOf_GimbalSpeed (iluCall call, Air_Unit_T_GimbalSpeed * val);

/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, Air_UnitStatus *status);
};

#define Air_UnitReply_Success		((ilu_Exception) NULL)

struct _Air_Unit_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
	} values;
};

struct Air_Unit_Exceptions_s {
	ilu_CString dummyException;
};


extern void Air_Unit__Initialize(void);	//ILU private

#endif /* ndef __Air_Unit_H_ */
