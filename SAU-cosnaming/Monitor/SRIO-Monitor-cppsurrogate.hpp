

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Monitor_cppsurrogate_H_
#define __SRIO_Monitor_cppsurrogate_H_

#include "SRIO-Monitor-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef SRIO_Monitor_surrogate_
#define SRIO_Monitor_surrogate_(name) NAME_INSIDE_SCOPE(SRIO_Monitor_surrogate,name)
#endif
#ifndef SRIO_Monitor_surrogate
#define SRIO_Monitor_surrogate(name) NAME_OUTSIDE_SCOPE(SRIO_Monitor_surrogate,name)
#endif
#include "SRIO-Ground-Unit-cppsurrogate.hpp"
#include "SRIO-Air-Unit-cppsurrogate.hpp"
#include "SRIO-Console-cppsurrogate.hpp"
#include "SRIO-Unit-cppsurrogate.hpp"

 // start the scope for SRIO_Monitor_surrogate 
namespace SRIO_Monitor_surrogate {
  class Monitor :public virtual SRIO_Monitor::Monitor {
    public:

     //ISL specified methods


      virtual CORBA::Boolean 
         sendUnitInfo(
             const SRIO_Monitor::Monitor::CompleteUnitInfo&  unitInfo
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendTrapPoint(
             const SRIO_Console::Console::TrapPoint&  tp
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendFireLocation(
             const iluShortCharacter*  fid,
             const SRIO_Ground_Unit::Ground_Unit::Point2D&  fp,
             CORBA::Short  responseTime
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         foundFire(
             const iluShortCharacter*  fid,
             const SRIO_Monitor::Monitor::PictureInfo&  pi
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         confirmAction(
             const iluShortCharacter*  fid,
             CORBA::Short  responseTime
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         backHome(
             const iluShortCharacter*  uid,
             SRIO_Monitor::Monitor::BackHomeReason  bhr
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendMissionState(
             const iluShortCharacter*  fid,
             SRIO_Monitor::Monitor::MissionSituation  ms
             ) throw (CORBA::SystemException);

      virtual CORBA::Boolean 
         sendPicture(
             const iluShortCharacter*  pictureName,
             const SRIO_Monitor::Monitor::PictureFlow&  pic,
             CORBA::Long  time,
             CORBA::Long  procedureStartTime
             ) throw (CORBA::SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a SRIO_Monitor::Monitor object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return SRIO_Monitor::Monitor::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)



      static int _initialized;

  };

  // class initializer
  class Monitor_initializer {
    public:
      Monitor_initializer ();
      void * ensure_instantiation ();
      static Monitor_initializer sm_the_surrogate_SRIO_Monitor_Monitor_initializer;
  };
 
// end the scope for SRIO_Monitor_surrogate 
 }
 
#endif
