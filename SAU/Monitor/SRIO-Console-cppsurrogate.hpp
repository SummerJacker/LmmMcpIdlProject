

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Console_cppsurrogate_H_
#define __SRIO_Console_cppsurrogate_H_

#include "SRIO-Console-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef SRIO_Console_surrogate_
#define SRIO_Console_surrogate_(name) NAME_INSIDE_SCOPE(SRIO_Console_surrogate,name)
#endif
#ifndef SRIO_Console_surrogate
#define SRIO_Console_surrogate(name) NAME_OUTSIDE_SCOPE(SRIO_Console_surrogate,name)
#endif
#include "SRIO-Unit-cppsurrogate.hpp"
#include "SRIO-Ground-Unit-cppsurrogate.hpp"
#include "SRIO-Air-Unit-cppsurrogate.hpp"

 // start the scope for SRIO_Console_surrogate 
namespace SRIO_Console_surrogate {
  class Console :public virtual SRIO_Console::Console {
    public:

     //ISL specified methods


      virtual SRIO_Console::Console::CosInfoSeq* 
         getCosNamingInfo(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendMsg(
             const SRIO_Console::Console::Message&  m
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         bind(
             const iluShortCharacter*  uid,
             const iluShortCharacter*  sbh
             ) throw (CORBA::SystemException, SRIO_Console::Console::AlreadyBind);

      virtual CORBA::Boolean 
         unbind(
             const iluShortCharacter*  uid,
             const iluShortCharacter*  details
             ) throw (CORBA::SystemException, SRIO_Console::Console::NotFound);

      virtual CORBA::Boolean 
         rebind(
             const iluShortCharacter*  uid,
             const iluShortCharacter*  sbh
             ) throw (CORBA::SystemException, SRIO_Console::Console::NotFound);

      virtual CORBA::Boolean 
         setNickname(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo,
             const iluShortCharacter*  newName
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setPosition(
             const iluShortCharacter*  name,
             const SRIO_Console::Console::Point&  p
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         addGoalPoint(
             const SRIO_Console::Console::Point&  p
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setGoalPoint(
             const SRIO_Console::Console::Point&  p
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setRole(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo,
             SRIO_Console::Console::Role  r
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         cancelRole(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTrapPoint(
             const SRIO_Console::Console::TrapPoint&  p
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setFollow(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo1,
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo2
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setFormationType(
             SRIO_Console::Console::FormationType  f
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setTrackMode(
             SRIO_Console::Console::TrackMode  tm
             ) throw (CORBA::SystemException);

      virtual SRIO_Unit::General_Unit::UnitInfo* 
         getCurrentUnit(
             ) throw (CORBA::SystemException);

      virtual CORBA::Short 
         getUnitNum(
             ) throw (CORBA::SystemException);

      virtual CORBA::Short 
         getFormationNum(
             ) throw (CORBA::SystemException);

      virtual CORBA::Short 
         getTrapNum(
             ) throw (CORBA::SystemException);

      virtual SRIO_Console::Console::FormationType 
         getFormationType(
             ) throw (CORBA::SystemException);

      virtual SRIO_Console::Console::FormationState 
         getFormationState(
             ) throw (CORBA::SystemException);

      virtual SRIO_Console::Console::MissionState 
         getMissionState(
             ) throw (CORBA::SystemException);

      virtual SRIO_Console::Console::Point 
         getUnitPoint(
             const iluShortCharacter*  name
             ) throw (CORBA::SystemException);

      virtual SRIO_Unit::General_Unit::UnitInfo* 
         getByName(
             const iluShortCharacter*  name
             ) throw (CORBA::SystemException);

      virtual SRIO_Console::Console::Point 
         getLeaderPoint(
             ) throw (CORBA::SystemException);

      virtual SRIO_Console::Console::PointSeq* 
         getPointSeq(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         cancelFormation(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setLeaderSuspend(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         recoveryLeaderAction(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         addUnitFormation(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         deleteUnitFormation(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setUnitFault(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setUnitFaultPosition(
             const SRIO_Unit::General_Unit::UnitInfo&  uinfo
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setFormationState(
             SRIO_Console::Console::FormationState  fs
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setMissionState(
             const SRIO_Console::Console::MissionStateData&  msd
             ) throw (CORBA::SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a SRIO_Console::Console object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return SRIO_Console::Console::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)

 
      static void _throw_bind_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA::SystemException, SRIO_Console::Console::AlreadyBind); 
      static void _throw_unbind_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA::SystemException, SRIO_Console::Console::NotFound); 
      static void _throw_rebind_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA::SystemException, SRIO_Console::Console::NotFound);

      static int _initialized;

  };

  // class initializer
  class Console_initializer {
    public:
      Console_initializer ();
      void * ensure_instantiation ();
      static Console_initializer sm_the_surrogate_SRIO_Console_Console_initializer;
  };
 
// end the scope for SRIO_Console_surrogate 
 }
 
#endif
