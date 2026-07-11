

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Unit_cppsurrogate_H_
#define __SRIO_Unit_cppsurrogate_H_

#include "SRIO-Unit-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef SRIO_Unit_surrogate_
#define SRIO_Unit_surrogate_(name) NAME_INSIDE_SCOPE(SRIO_Unit_surrogate,name)
#endif
#ifndef SRIO_Unit_surrogate
#define SRIO_Unit_surrogate(name) NAME_OUTSIDE_SCOPE(SRIO_Unit_surrogate,name)
#endif

 // start the scope for SRIO_Unit_surrogate 
namespace SRIO_Unit_surrogate {
  class General_Unit :public virtual SRIO_Unit::General_Unit {
    public:

     //ISL specified methods


      virtual iluShortCharacter* 
         getID(
             ) throw (CORBA::SystemException);

      virtual iluShortCharacter* 
         getCosNamingSBH(
             ) throw (CORBA::SystemException);

      virtual SRIO_Unit::General_Unit::UnitInfo* 
         getFrontUnitInfo(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setRole(
             SRIO_Unit::General_Unit::UnitRole  role,
             const iluShortCharacter*  consoleSBH
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setMode(
             SRIO_Unit::General_Unit::UnitMode  mode
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setMinorMode(
             SRIO_Unit::General_Unit::UnitMinorMode  minorMode
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         setALeader(
             const iluShortCharacter*  leaderSBH
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         registerFollower(
             const iluShortCharacter*  followerUID,
             const iluShortCharacter*  followerSBH
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         unregisterFollower(
             const iluShortCharacter*  followerUID
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         addRearVehicle(
             const SRIO_Unit::General_Unit::UnitInfo&  rearInfo
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         deleteRearVehicle(
             const iluShortCharacter*  uid
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         reportDeadVehicle(
             const iluShortCharacter*  uid,
             const iluShortCharacter*  details
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         shutDown(
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         takePicture(
             CORBA::Long  time,
             CORBA::Long  procedureStartTime
             ) throw (CORBA::SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a SRIO_Unit::General_Unit object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return SRIO_Unit::General_Unit::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)



      static int _initialized;

  };

  // class initializer
  class General_Unit_initializer {
    public:
      General_Unit_initializer ();
      void * ensure_instantiation ();
      static General_Unit_initializer sm_the_surrogate_SRIO_Unit_General_Unit_initializer;
  };
 
// end the scope for SRIO_Unit_surrogate 
 }
 
#endif
