/* This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Sep 19 19:31:18 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/projects/project/SAU/Ilu/interfaces/c++-stubber.exe" of Thu Jul 10 17:58:48 2025
 * on "D:/projects/project/SAU/Ilu/interfaces/i/general_unit.idl" of Wed Jul 16 16:34:30 2025,
 * and "D:/projects/project/SAU/Ilu/interfaces/ilu.isl" of Thu Jun 19 13:16:02 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __Unit_H_
#define __Unit_H_ 1
#ifndef __ilu_H_
#include <ilu.hh>
#endif /* ndef __ilu_H_ */


typedef struct _Unit_Status_struct UnitStatus;

typedef ilu_T_CString Unit_T_UnitID;
#define Unit_T_UnitID ilu_T_CString
typedef ilu_T_CString Unit_T_UnitSBH;
#define Unit_T_UnitSBH ilu_T_CString
typedef enum _Unit_T_UnitRole_enum {Unit_T_UnitRole_UR_Leader = 0, Unit_T_UnitRole_UR_Follower = 1, Unit_T_UnitRole_UR_None = 2} Unit_T_UnitRole;
typedef enum _Unit_T_UnitMode_enum {Unit_T_UnitMode_UM_None = 0, Unit_T_UnitMode_UM_Follow = 1, Unit_T_UnitMode_UM_Imitate = 2, Unit_T_UnitMode_UM_Mate = 3} Unit_T_UnitMode;
typedef enum _Unit_T_UnitMinorMode_enum {Unit_T_UnitMinorMode_UMM_None = 0, Unit_T_UnitMinorMode_UMM_FW_Object = 1, Unit_T_UnitMinorMode_UMM_FW_Track = 2} Unit_T_UnitMinorMode;
class Unit_T_rpc;
typedef class _Unit_T_UnitIDSeq_sequence * Unit_T_UnitIDSeq;
typedef class _Unit_T_ShortSeq_sequence * Unit_T_ShortSeq;
typedef class _Unit_T_FloatSeq_sequence * Unit_T_FloatSeq;
typedef struct _Unit_T_Formation_record Unit_T_Formation;
typedef struct _Unit_T_UnitInfo_record Unit_T_UnitInfo;
typedef class _Unit_T_UnitInfoSeq_sequence * Unit_T_UnitInfoSeq;
typedef enum _Unit_T_MoveActionType_enum {Unit_T_MoveActionType_MA_GoAhead = 0, Unit_T_MoveActionType_MA_GoBackward = 1, Unit_T_MoveActionType_MA_TurnLeft = 2, Unit_T_MoveActionType_MA_TurnRight = 3, Unit_T_MoveActionType_MA_Stop = 4, Unit_T_MoveActionType_MA_GoUp = 5, Unit_T_MoveActionType_MA_GoDown = 6, Unit_T_MoveActionType_MA_GoLeft = 7, Unit_T_MoveActionType_MA_GoRight = 8, Unit_T_MoveActionType_MA_TakeOff = 9, Unit_T_MoveActionType_MA_Land = 10, Unit_T_MoveActionType_MA_LandConfirm = 11, Unit_T_MoveActionType_MA_ForceLanding = 12, Unit_T_MoveActionType_MA_Lock = 13, Unit_T_MoveActionType_MA_Unlock = 14} Unit_T_MoveActionType;
typedef struct _Unit_T_ActionDuration_record Unit_T_ActionDuration;
typedef struct _Unit_T_BasicMoveActionData_record Unit_T_BasicMoveActionData;
typedef struct _Unit_T_MoveAction_union Unit_T_MoveAction;
typedef class _Unit_T_ActionSeq_sequence * Unit_T_ActionSeq;
typedef class _Unit_T_UnitSBHSeq_sequence * Unit_T_UnitSBHSeq;



/* declaration of C++ class "Unit_T_rpc"
   from ILU class "Unit:rpc"  */


class Unit_T_rpc : public virtual ilu_T_CORBA_Object {

 public:

  Unit_T_rpc();			// constructor
  virtual ~Unit_T_rpc();		// destructor

 // class procedures

  static class Unit_T_rpc * ILUCreateFromSBH(ilu_CString sbh);
  static class Unit_T_rpc * ILUQuaT (class iluObject *from);

 // public variables

  static ilu_Class ILUClassRecord;
 // methods

  virtual void * ILUCastDown (ilu_Class cast_to);

  virtual Unit_T_UnitID getID (UnitStatus *_status);
  virtual Unit_T_UnitSBH getCosNamingSBH (UnitStatus *_status);
  virtual Unit_T_UnitInfo * getFrontUnitInfo (UnitStatus *_status);
  virtual ilu_Boolean setRole (UnitStatus *_status, Unit_T_UnitRole role, Unit_T_UnitSBH consoleSBH);
  virtual ilu_Boolean setMode (UnitStatus *_status, Unit_T_UnitMode mode);
  virtual ilu_Boolean setMinorMode (UnitStatus *_status, Unit_T_UnitMinorMode minorMode);
  virtual ilu_Boolean sendMoveAction (UnitStatus *_status, Unit_T_MoveAction * action);
  virtual ilu_Boolean sendMoveActionSeq (UnitStatus *_status, Unit_T_ActionSeq actions, ilu_ShortInteger times);
  virtual ilu_Boolean setALeader (UnitStatus *_status, Unit_T_UnitSBH leaderSBH);
  virtual ilu_Boolean unregisterFollower (UnitStatus *_status, Unit_T_UnitID followerUID);
  virtual ilu_Boolean setFollower (UnitStatus *_status, Unit_T_UnitInfo * ui);
  virtual ilu_Boolean unsetFollower (UnitStatus *_status, Unit_T_UnitID uid);
  virtual ilu_Boolean addRearVehicle (UnitStatus *_status, Unit_T_UnitInfo * rearInfo);
  virtual ilu_Boolean deleteRearVehicle (UnitStatus *_status, Unit_T_UnitID uid);
  virtual ilu_Boolean setFormation (UnitStatus *_status, Unit_T_Formation * form);
  virtual ilu_Boolean setRearVehicles (UnitStatus *_status, Unit_T_UnitInfoSeq rears, ilu_ShortReal distance, ilu_ShortReal angle);
  virtual ilu_Boolean reportDeadVehicle (UnitStatus *_status, Unit_T_UnitID uid, ilu_T_CString details);
  virtual ilu_Boolean shutDown (UnitStatus *_status);
  virtual ilu_Boolean startPhotoStream (UnitStatus *_status, ilu_ShortReal frequency);
  virtual ilu_Boolean stopPhotoStream (UnitStatus *_status);
  virtual ilu_Boolean takePicture (UnitStatus *_status, ilu_Integer time, ilu_Integer procedureStartTime);

 // data slots for cacheable methods -- if any

};

  class _Unit_T_UnitIDSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Unit_T_UnitID *_buffer;
   public:
    _Unit_T_UnitIDSeq_sequence ();
    virtual ~_Unit_T_UnitIDSeq_sequence ();
    static class _Unit_T_UnitIDSeq_sequence *Create (ilu_Cardinal initial_size, Unit_T_UnitID *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Unit_T_UnitID);
    virtual Unit_T_UnitID RemoveHead();
    virtual Unit_T_UnitID RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Unit_T_UnitID, void *), void *arg);
    virtual Unit_T_UnitID Find(ilu_Boolean (*matchproc)(Unit_T_UnitID, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Unit_T_UnitID, void *), void *arg);
    virtual Unit_T_UnitID * Array();
    virtual Unit_T_UnitID Nth(ilu_Cardinal index);
  };

  class _Unit_T_ShortSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    ilu_ShortInteger *_buffer;
   public:
    _Unit_T_ShortSeq_sequence ();
    virtual ~_Unit_T_ShortSeq_sequence ();
    static class _Unit_T_ShortSeq_sequence *Create (ilu_Cardinal initial_size, ilu_ShortInteger *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(ilu_ShortInteger);
    virtual ilu_ShortInteger RemoveHead();
    virtual ilu_ShortInteger RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(ilu_ShortInteger, void *), void *arg);
    virtual ilu_ShortInteger Find(ilu_Boolean (*matchproc)(ilu_ShortInteger, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(ilu_ShortInteger, void *), void *arg);
    virtual ilu_ShortInteger * Array();
    virtual ilu_ShortInteger Nth(ilu_Cardinal index);
  };

  class _Unit_T_FloatSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    ilu_ShortReal *_buffer;
   public:
    _Unit_T_FloatSeq_sequence ();
    virtual ~_Unit_T_FloatSeq_sequence ();
    static class _Unit_T_FloatSeq_sequence *Create (ilu_Cardinal initial_size, ilu_ShortReal *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(ilu_ShortReal);
    virtual ilu_ShortReal RemoveHead();
    virtual ilu_ShortReal RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(ilu_ShortReal, void *), void *arg);
    virtual ilu_ShortReal Find(ilu_Boolean (*matchproc)(ilu_ShortReal, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(ilu_ShortReal, void *), void *arg);
    virtual ilu_ShortReal * Array();
    virtual ilu_ShortReal Nth(ilu_Cardinal index);
  };

struct _Unit_T_Formation_record {
	Unit_T_UnitIDSeq robot_ids;
	Unit_T_ShortSeq leader_ids;
	Unit_T_FloatSeq distances;
	Unit_T_FloatSeq angles;
};
struct _Unit_T_UnitInfo_record {
	Unit_T_UnitID uid;
	Unit_T_UnitSBH sbh;
};
  class _Unit_T_UnitInfoSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Unit_T_UnitInfo *_buffer;
   public:
    _Unit_T_UnitInfoSeq_sequence ();
    virtual ~_Unit_T_UnitInfoSeq_sequence ();
    static class _Unit_T_UnitInfoSeq_sequence *Create (ilu_Cardinal initial_size, Unit_T_UnitInfo *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Unit_T_UnitInfo *);
    virtual Unit_T_UnitInfo * RemoveHead();
    virtual Unit_T_UnitInfo * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Unit_T_UnitInfo *, void *), void *arg);
    virtual Unit_T_UnitInfo * Find(ilu_Boolean (*matchproc)(Unit_T_UnitInfo *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Unit_T_UnitInfo *, void *), void *arg);
    virtual Unit_T_UnitInfo * Array();
    virtual Unit_T_UnitInfo * Nth(ilu_Cardinal index);
  };

struct _Unit_T_ActionDuration_record {
	ilu_Boolean keep;
	ilu_Cardinal ft_s;
	ilu_Cardinal ft_t;
};
struct _Unit_T_BasicMoveActionData_record {
	ilu_ShortReal speed;
	Unit_T_ActionDuration duration;
};
struct _Unit_T_MoveAction_union {
	Unit_T_MoveActionType discriminator;
	union {
		Unit_T_BasicMoveActionData goUpData;
		Unit_T_BasicMoveActionData goDownData;
		Unit_T_BasicMoveActionData goAheadData;
		Unit_T_BasicMoveActionData goBackwardData;
		Unit_T_BasicMoveActionData goLeftData;
		Unit_T_BasicMoveActionData goRightData;
		Unit_T_BasicMoveActionData turnLeftData;
		Unit_T_BasicMoveActionData turnRightData;
		Unit_T_ActionDuration stopData;
	} value;
};
  class _Unit_T_ActionSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Unit_T_MoveAction *_buffer;
   public:
    _Unit_T_ActionSeq_sequence ();
    virtual ~_Unit_T_ActionSeq_sequence ();
    static class _Unit_T_ActionSeq_sequence *Create (ilu_Cardinal initial_size, Unit_T_MoveAction *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Unit_T_MoveAction *);
    virtual Unit_T_MoveAction * RemoveHead();
    virtual Unit_T_MoveAction * RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Unit_T_MoveAction *, void *), void *arg);
    virtual Unit_T_MoveAction * Find(ilu_Boolean (*matchproc)(Unit_T_MoveAction *, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Unit_T_MoveAction *, void *), void *arg);
    virtual Unit_T_MoveAction * Array();
    virtual Unit_T_MoveAction * Nth(ilu_Cardinal index);
  };

  class _Unit_T_UnitSBHSeq_sequence {
   private:
    ilu_Cardinal _maximum;
    ilu_Cardinal _length;
    Unit_T_UnitSBH *_buffer;
   public:
    _Unit_T_UnitSBHSeq_sequence ();
    virtual ~_Unit_T_UnitSBHSeq_sequence ();
    static class _Unit_T_UnitSBHSeq_sequence *Create (ilu_Cardinal initial_size, Unit_T_UnitSBH *initial_data);
    virtual void Clear(ilu_Boolean free_contents);
    virtual ilu_Cardinal Length();
    virtual void Append(Unit_T_UnitSBH);
    virtual Unit_T_UnitSBH RemoveHead();
    virtual Unit_T_UnitSBH RemoveTail();
    virtual ilu_Cardinal RemoveAll(ilu_Boolean (*matchproc)(Unit_T_UnitSBH, void *), void *arg);
    virtual Unit_T_UnitSBH Find(ilu_Boolean (*matchproc)(Unit_T_UnitSBH, void *), void *arg);
    virtual void Enumerate(void (*enumproc)(Unit_T_UnitSBH, void *), void *arg);
    virtual Unit_T_UnitSBH * Array();
    virtual Unit_T_UnitSBH Nth(ilu_Cardinal index);
  };


class Unit_G {

 public:

  static struct Unit_Exceptions_s *Exceptions();
  static void RaiseException (UnitStatus *status, ilu_Exception exception...);

  static ilu_Boolean Output_Formation (iluCall call, Unit_T_Formation * val);
  static Unit_T_Formation * Input_Formation (iluCall call, Unit_T_Formation * ref);
  static ilu_Cardinal SizeOf_Formation (iluCall call, Unit_T_Formation * val);

  static void Free_Formation (Unit_T_Formation * val);
  static ilu_Boolean Output_UnitInfoSeq (iluCall call, Unit_T_UnitInfoSeq val);
  static Unit_T_UnitInfoSeq Input_UnitInfoSeq (iluCall call, Unit_T_UnitInfoSeq ref);
  static ilu_Cardinal SizeOf_UnitInfoSeq (iluCall call, Unit_T_UnitInfoSeq val);

  static void Free_UnitInfoSeq (Unit_T_UnitInfoSeq val);
  static ilu_Boolean Output_UnitInfo (iluCall call, Unit_T_UnitInfo * val);
  static Unit_T_UnitInfo * Input_UnitInfo (iluCall call, Unit_T_UnitInfo * ref);
  static ilu_Cardinal SizeOf_UnitInfo (iluCall call, Unit_T_UnitInfo * val);

  static ilu_Boolean Output_ActionSeq (iluCall call, Unit_T_ActionSeq val);
  static Unit_T_ActionSeq Input_ActionSeq (iluCall call, Unit_T_ActionSeq ref);
  static ilu_Cardinal SizeOf_ActionSeq (iluCall call, Unit_T_ActionSeq val);

  static void Free_ActionSeq (Unit_T_ActionSeq val);
  static ilu_Boolean Output_MoveAction (iluCall call, Unit_T_MoveAction * val);
  static Unit_T_MoveAction * Input_MoveAction (iluCall call, Unit_T_MoveAction * ref);
  static ilu_Cardinal SizeOf_MoveAction (iluCall call, Unit_T_MoveAction * val);

  static ilu_Boolean Output_BasicMoveActionData (iluCall call, Unit_T_BasicMoveActionData * val);
  static Unit_T_BasicMoveActionData * Input_BasicMoveActionData (iluCall call, Unit_T_BasicMoveActionData * ref);
  static ilu_Cardinal SizeOf_BasicMoveActionData (iluCall call, Unit_T_BasicMoveActionData * val);

  static ilu_Boolean Output_ActionDuration (iluCall call, Unit_T_ActionDuration * val);
  static Unit_T_ActionDuration * Input_ActionDuration (iluCall call, Unit_T_ActionDuration * ref);
  static ilu_Cardinal SizeOf_ActionDuration (iluCall call, Unit_T_ActionDuration * val);

  static ilu_Boolean Output_FloatSeq (iluCall call, Unit_T_FloatSeq val);
  static Unit_T_FloatSeq Input_FloatSeq (iluCall call, Unit_T_FloatSeq ref);
  static ilu_Cardinal SizeOf_FloatSeq (iluCall call, Unit_T_FloatSeq val);

  static void Free_FloatSeq (Unit_T_FloatSeq val);
  static ilu_Boolean Output_ShortSeq (iluCall call, Unit_T_ShortSeq val);
  static Unit_T_ShortSeq Input_ShortSeq (iluCall call, Unit_T_ShortSeq ref);
  static ilu_Cardinal SizeOf_ShortSeq (iluCall call, Unit_T_ShortSeq val);

  static void Free_ShortSeq (Unit_T_ShortSeq val);
  static ilu_Boolean Output_UnitSBHSeq (iluCall call, Unit_T_UnitSBHSeq val);
  static Unit_T_UnitSBHSeq Input_UnitSBHSeq (iluCall call, Unit_T_UnitSBHSeq ref);
  static ilu_Cardinal SizeOf_UnitSBHSeq (iluCall call, Unit_T_UnitSBHSeq val);

  static void Free_UnitSBHSeq (Unit_T_UnitSBHSeq val);
  static ilu_Boolean Output_UnitIDSeq (iluCall call, Unit_T_UnitIDSeq val);
  static Unit_T_UnitIDSeq Input_UnitIDSeq (iluCall call, Unit_T_UnitIDSeq ref);
  static ilu_Cardinal SizeOf_UnitIDSeq (iluCall call, Unit_T_UnitIDSeq val);

  static void Free_UnitIDSeq (Unit_T_UnitIDSeq val);
/* Note:  SendException should only be used by generated code, not by user code. */
  static int SendException (iluCall call, UnitStatus *status);
};

#define UnitReply_Success		((ilu_Exception) NULL)

struct _Unit_Status_struct {
	ilu_Exception returnCode;
	ilu_Passport callerPassport;
	union {
		ilu_Cardinal anyvalue;
	} values;
};

struct Unit_Exceptions_s {
	ilu_CString dummyException;
};


extern void Unit__Initialize(void);	//ILU private

#endif /* ndef __Unit_H_ */
