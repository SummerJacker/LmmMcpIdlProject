

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Ground_Unit_cppsurrogate_H_
#define __SRIO_Ground_Unit_cppsurrogate_H_

#include "SRIO-Ground-Unit-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef SRIO_Ground_Unit_surrogate_
#define SRIO_Ground_Unit_surrogate_(name) NAME_INSIDE_SCOPE(SRIO_Ground_Unit_surrogate,name)
#endif
#ifndef SRIO_Ground_Unit_surrogate
#define SRIO_Ground_Unit_surrogate(name) NAME_OUTSIDE_SCOPE(SRIO_Ground_Unit_surrogate,name)
#endif
#include "SRIO-Unit-cppsurrogate.hpp"

 // start the scope for SRIO_Ground_Unit_surrogate 
namespace SRIO_Ground_Unit_surrogate {
  class Ground_Unit : public virtual SRIO_Unit_surrogate::General_Unit, public virtual SRIO_Ground_Unit::Ground_Unit {
    public:

     //ISL specified methods


      virtual SRIO_Ground_Unit::Ground_Unit::Speed2D 
         getCurrentSpeed(
             ) throw (CORBA::SystemException);

      virtual SRIO_Ground_Unit::Ground_Unit::Pose2D 
         getCurrentPose(
             ) throw (CORBA::SystemException);

      virtual SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo* 
         getCurrentInfo(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendMoveAction(
             const SRIO_Ground_Unit::Ground_Unit::MoveAction&  action
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendMoveActionSequence(
             const SRIO_Ground_Unit::Ground_Unit::ActionSequence&  actions,
             CORBA::Short  times
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendVehicleInfo(
             const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo&  info
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setRearVehicles(
             const SRIO_Unit::General_Unit::UnitInfoSequence&  rears,
             CORBA::Float  distance,
             CORBA::Float  angle
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setFormation(
             const SRIO_Ground_Unit::Ground_Unit::Formation&  form
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         reportTrap(
             const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D&  trap
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         clearTraps(
             ) throw (CORBA::SystemException);

      virtual SRIO_Ground_Unit::Ground_Unit::TrapPointSequence* 
         getTraps(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTrapPoint(
             const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D&  trap
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTrack(
             const SRIO_Ground_Unit::Ground_Unit::TaskPath&  track
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTaskPath(
             const SRIO_Ground_Unit::Ground_Unit::TaskPath&  path
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTaskPoint(
             const SRIO_Ground_Unit::Ground_Unit::Point2D&  point
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         startPhotoStream(
             CORBA::Float  frequency
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         stopPhotoStream(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setFollower(
             const SRIO_Unit::General_Unit::UnitInfo&  ui
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         unsetFollower(
             const iluShortCharacter*  uid
             ) throw (CORBA::SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a SRIO_Ground_Unit::Ground_Unit object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return SRIO_Ground_Unit::Ground_Unit::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)



      static int _initialized;

  };

  // class initializer
  class Ground_Unit_initializer {
    public:
      Ground_Unit_initializer ();
      void * ensure_instantiation ();
      static Ground_Unit_initializer sm_the_surrogate_SRIO_Ground_Unit_Ground_Unit_initializer;
  };
 
// end the scope for SRIO_Ground_Unit_surrogate 
 }
 
#endif
