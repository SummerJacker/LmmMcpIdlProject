/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:33:11 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/ground_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Ground_Unit_H_
#define __Ground_Unit_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */

#ifndef __Unit_H_
#include "Unit.hh"
#endif /* ndef __Unit_H_ */


typedef struct _Ground_Unit_Status_struct Ground_UnitStatus;

class Ground_Unit_T_rpc;
typedef struct _Ground_Unit_T_Point2D_record Ground_Unit_T_Point2D;
typedef struct _Ground_Unit_T_TrapPoint2D_record Ground_Unit_T_TrapPoint2D;
typedef class _Ground_Unit_T_TrapPointSeq_sequence * Ground_Unit_T_TrapPointSeq;
typedef class _Ground_Unit_T_TaskPath_sequence * Ground_Unit_T_TaskPath;
typedef struct _Ground_Unit_T_Speed2D_record Ground_Unit_T_Speed2D;
typedef struct _Ground_Unit_T_Pose2D_record Ground_Unit_T_Pose2D;
typedef struct _Ground_Unit_T_GroundUnitInfo_record Ground_Unit_T_GroundUnitInfo;



/* declaration of C++ class "Ground_Unit_T_rpc"
   from ILU class "Ground-Unit:rpc"  */


class Ground_Unit_T_rpc : public virtual Unit_T_rpc {

 public:

  Ground_Unit_T_rpc();			// constructor
  virtual ~Ground_Unit_T_rpc();		// destructor

 // class procedures

  static class Ground_Unit_T_rpc * ILUCreateFromSBH(ilu_CString sbh);
  static class Ground_Unit_T_rpc * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Ground_Unit_T_Speed2D * getCurrentSpeed (Ground_UnitStatus *_status);
  virtual Ground_Unit_T_Pose2D * getCurrentPose (Ground_UnitStatus *_status);
  virtual Ground_Unit_T_GroundUnitInfo * getCurrentInfo (Ground_UnitStatus *_status);
  virtual ilu_Boolean sendVehicleInfo (Ground_UnitStatus *_status, Ground_Unit_T_GroundUnitInfo * info);
  virtual ilu_Boolean reportTrap (Ground_UnitStatus *_status, Ground_Unit_T_TrapPoint2D * trap);
  virtual ilu_Boolean clearTraps (Ground_UnitStatus *_status);
  virtual Ground_Unit_T_TrapPointSeq getTraps (Ground_UnitStatus *_status);
  virtual ilu_Boolean setTrapPoint (Ground_UnitStatus *_status, Ground_Unit_T_TrapPoint2D * trap);
  virtual ilu_Boolean setTrack (Ground_UnitStatus *_status, Ground_Unit_T_TaskPath track);
  virtual ilu_Boolean setTaskPath (Ground_UnitStatus *_status, Ground_Unit_T_TaskPath path);
  virtual ilu_Boolean setTaskPoint (Ground_UnitStatus *_status, Ground_Unit_T_Point2D * point);

 // data slots for cacheable methods -- if any

};

struct _Ground_Unit_T_Point2D_record {
	ilu_ShortReal x;
	ilu_ShortReal y;
};
struct _Ground_Unit_T_TrapPoint2D_record {
	Ground_Unit_T_Point2D point;
	ilu_ShortReal radius;
};
  class _Ground_Unit_T_TrapPointSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Ground_Unit_T_TrapPoint2D *_buffer;
   public:
    _Ground_Unit_T_TrapPointSeq_sequence ();
    virtual ~_Ground_Unit_T_TrapPointSeq_sequence ();
    static class _Ground_Unit_T_TrapPointSeq_sequence *Create (ilu_Cardinal initial_size, Ground_Unit_T_TrapPoint2D *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Ground_Unit_T_TrapPoint2D *);
    virtual Ground_Unit_T_TrapPoint2D * RemoveHead();
    virtual Ground_Unit_T_TrapPoint2D * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Ground_Unit_T_TrapPoint2D *, void *), void *arg);
    virtual Ground_Unit_T_TrapPoint2D * Find(ilu_Boolean (*matchproc)(Ground_Unit_T_TrapPoint2D *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Ground_Unit_T_TrapPoint2D *, void *), void *arg);
    virtual Ground_Unit_T_TrapPoint2D * Array();
    virtual Ground_Unit_T_TrapPoint2D * Nth(ilu_Cardinal index);
  };

  class _Ground_Unit_T_TaskPath_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Ground_Unit_T_Point2D *_buffer;
   public:
    _Ground_Unit_T_TaskPath_sequence ();
    virtual ~_Ground_Unit_T_TaskPath_sequence ();
    static class _Ground_Unit_T_TaskPath_sequence *Create (ilu_Cardinal initial_size, Ground_Unit_T_Point2D *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Ground_Unit_T_Point2D *);
    virtual Ground_Unit_T_Point2D * RemoveHead();
    virtual Ground_Unit_T_Point2D * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Ground_Unit_T_Point2D *, void *), void *arg);
    virtual Ground_Unit_T_Point2D * Find(ilu_Boolean (*matchproc)(Ground_Unit_T_Point2D *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Ground_Unit_T_Point2D *, void *), void *arg);
    virtual Ground_Unit_T_Point2D * Array();
    virtual Ground_Unit_T_Point2D * Nth(ilu_Cardinal index);
  };

struct _Ground_Unit_T_Speed2D_record {
	ilu_ShortReal leanerVel;
	ilu_ShortReal angularVel;
};
struct _Ground_Unit_T_Pose2D_record {
	ilu_ShortReal x;
	ilu_ShortReal y;
	ilu_ShortReal yaw;
};
struct _Ground_Unit_T_GroundUnitInfo_record {
	Unit_T_UnitInfo info;
	Unit_T_UnitRole role;
	Ground_Unit_T_Speed2D speed;
	Ground_Unit_T_Pose2D pose;
};

class Ground_Unit_G {

 public:

  static struct Ground_Unit_Exceptions_s *Exceptions();
  static void RaiseException (Ground_UnitStatus *status, ilu_Exception exception...);

  static ilu_Boolean Output_TrapPointSeq (iluCall call, Ground_Unit_T_TrapPointSeq val);
  static Ground_Unit_T_TrapPointSeq Input_TrapPointSeq (iluCall call, Ground_Unit_T_TrapPointSeq ref);
  static ilu_Cardinal SizeOf_TrapPointSeq (iluCall call, Ground_Unit_T_TrapPointSeq val);

  static void Free_TrapPointSeq (Ground_Unit_T_TrapPointSeq val);
  static ilu_Boolean Output_TaskPath (iluCall call, Ground_Unit_T_TaskPath val);
  static Ground_Unit_T_TaskPath Input_TaskPath (iluCall call, Ground_Unit_T_TaskPath ref);
  static ilu_Cardinal SizeOf_TaskPath (iluCall call, Ground_Unit_T_TaskPath val);

  static void Free_TaskPath (Ground_Unit_T_TaskPath val);
  static ilu_Boolean Output_TrapPoint2D (iluCall call, Ground_Unit_T_TrapPoint2D * val);
  static Ground_Unit_T_TrapPoint2D * Input_TrapPoint2D (iluCall call, Ground_Unit_T_TrapPoint2D * ref);
  static ilu_Cardinal SizeOf_TrapPoint2D (iluCall call, Ground_Unit_T_TrapPoint2D * val);

  static ilu_Boolean Output_Point2D (iluCall call, Ground_Unit_T_Point2D * val);
  static Ground_Unit_T_Point2D * Input_Point2D (iluCall call, Ground_Unit_T_Point2D * ref);
  static ilu_Cardinal SizeOf_Point2D (iluCall call, Ground_Unit_T_Point2D * val);

  static ilu_Boolean Output_GroundUnitInfo (iluCall call, Ground_Unit_T_GroundUnitInfo * val);
  static Ground_Unit_T_GroundUnitInfo * Input_GroundUnitInfo (iluCall call, Ground_Unit_T_GroundUnitInfo * ref);
  static ilu_Cardinal SizeOf_GroundUnitInfo (iluCall call, Ground_Unit_T_GroundUnitInfo * val);

  static ilu_Boolean Output_Speed2D (iluCall call, Ground_Unit_T_Speed2D * val);
  static Ground_Unit_T_Speed2D * Input_Speed2D (iluCall call, Ground_Unit_T_Speed2D * ref);
  static ilu_Cardinal SizeOf_Speed2D (iluCall call, Ground_Unit_T_Speed2D * val);

  static ilu_Boolean Output_Pose2D (iluCall call, Ground_Unit_T_Pose2D * val);
  static Ground_Unit_T_Pose2D * Input_Pose2D (iluCall call, Ground_Unit_T_Pose2D * ref);
  static ilu_Cardinal SizeOf_Pose2D (iluCall call, Ground_Unit_T_Pose2D * val);

/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, Ground_UnitStatus *status);
};

#define Ground_UnitReply_Success		((ilu_Exception) NULL)

struct _Ground_Unit_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
	} values;
};

struct Ground_Unit_Exceptions_s {
	ilu_CString dummyException;
};


extern void Ground_Unit__Initialize(void);	//ILU private

#endif /* ndef __Ground_Unit_H_ */
