

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Air_Unit_cppsurrogate_H_
#define __SRIO_Air_Unit_cppsurrogate_H_

#include "SRIO-Air-Unit-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef SRIO_Air_Unit_surrogate_
#define SRIO_Air_Unit_surrogate_(name) NAME_INSIDE_SCOPE(SRIO_Air_Unit_surrogate,name)
#endif
#ifndef SRIO_Air_Unit_surrogate
#define SRIO_Air_Unit_surrogate(name) NAME_OUTSIDE_SCOPE(SRIO_Air_Unit_surrogate,name)
#endif
#include "SRIO-Unit-cppsurrogate.hpp"

 // start the scope for SRIO_Air_Unit_surrogate 
namespace SRIO_Air_Unit_surrogate {
  class Air_Unit : public virtual SRIO_Unit_surrogate::General_Unit, public virtual SRIO_Air_Unit::Air_Unit {
    public:

     //ISL specified methods


      virtual SRIO_Air_Unit::Air_Unit::Speed3D 
         getCurrentSpeed(
             ) throw (CORBA::SystemException);

      virtual SRIO_Air_Unit::Air_Unit::Pose3D 
         getCurrentPose(
             ) throw (CORBA::SystemException);

      virtual SRIO_Air_Unit::Air_Unit::AirUnitInfo* 
         getCurrentInfo(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendMoveAction(
             const SRIO_Air_Unit::Air_Unit::MoveAction&  action
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendGimbalSpeed(
             const SRIO_Air_Unit::Air_Unit::GimbalSpeed&  speed
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         resetGimbal(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendMoveActionSequence(
             const SRIO_Air_Unit::Air_Unit::ActionSequence&  actions,
             CORBA::Short  times
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendVehicleInfo(
             const SRIO_Air_Unit::Air_Unit::AirUnitInfo&  info
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setRearVehicles(
             const SRIO_Unit::General_Unit::UnitInfoSequence&  rears,
             CORBA::Float  distance,
             CORBA::Float  angle
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setFormation(
             const SRIO_Air_Unit::Air_Unit::Formation&  form
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         reportTrap(
             const SRIO_Air_Unit::Air_Unit::TrapPoint3D&  trap
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         clearTraps(
             ) throw (CORBA::SystemException);

      virtual SRIO_Air_Unit::Air_Unit::TrapPointSequence* 
         getTraps(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTrapPoint(
             const SRIO_Air_Unit::Air_Unit::TrapPoint3D&  trap
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTrack(
             const SRIO_Air_Unit::Air_Unit::TaskPath&  track
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTaskPath(
             const SRIO_Air_Unit::Air_Unit::TaskPath&  path
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTaskPoint(
             const SRIO_Air_Unit::Air_Unit::Point3D&  point
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         clearTaskPoint(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setFollower(
             const SRIO_Unit::General_Unit::UnitInfo&  ui
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         unsetFollower(
             const iluShortCharacter*  uid
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         startPhotoStream(
             CORBA::Float  frequency
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         stopPhotoStream(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         obtainCtrlAuthority(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         releaseCtrlAuthority(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setActionRole(
             SRIO_Air_Unit::Air_Unit::ActionRole  ar
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setActionMode(
             SRIO_Air_Unit::Air_Unit::ActionMode  am
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setCruiseScope(
             const SRIO_Air_Unit::Air_Unit::Site&  s
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendControlledVehicle(
             const SRIO_Air_Unit::Air_Unit::UnitSBHSeq&  uss
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         confirmThrow(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         cancelThrow(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         actionThrow(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         confirmFire(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         cancelFire(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         confirmFireLocation(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         cancelFireLocation(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         controlVehicleVelocity(
             CORBA::Float  vx,
             CORBA::Float  vy,
             CORBA::Float  vz,
             CORBA::Float  angle
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         backHome(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setCruiseSpeed(
             CORBA::Float  cs
             ) throw (CORBA::SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a SRIO_Air_Unit::Air_Unit object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return SRIO_Air_Unit::Air_Unit::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)



      static int _initialized;

  };

  // class initializer
  class Air_Unit_initializer {
    public:
      Air_Unit_initializer ();
      void * ensure_instantiation ();
      static Air_Unit_initializer sm_the_surrogate_SRIO_Air_Unit_Air_Unit_initializer;
  };
 
// end the scope for SRIO_Air_Unit_surrogate 
 }
 
#endif
