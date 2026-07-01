
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Air-Unit-cpptrue.hpp"

// Globals and statics 

int SRIO_Air_Unit_true::Air_Unit_initializer::initialized; 
SRIO_Air_Unit_true::Air_Unit_initializer
     SRIO_Air_Unit_true::Air_Unit_initializer::sm_the_true_SRIO_Air_Unit_Air_Unit_initializer;
// Method Stubs

static void SRIO_Air_Unit_Air_Unit_getCurrentSpeed_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             SRIO_Air_Unit::Air_Unit::Speed3D    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->getCurrentSpeed(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_getCurrentSpeed");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_getCurrentPose_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             SRIO_Air_Unit::Air_Unit::Pose3D    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->getCurrentPose(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_getCurrentPose");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_getCurrentInfo_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             SRIO_Air_Unit::Air_Unit::AirUnitInfo*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->getCurrentInfo(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_getCurrentInfo");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_sendMoveAction_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::MoveAction    action;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  action;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendMoveAction(
                  action
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_sendMoveAction");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_sendGimbalSpeed_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::GimbalSpeed    speed;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  speed;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendGimbalSpeed(
                  speed
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_sendGimbalSpeed");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_resetGimbal_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->resetGimbal(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_resetGimbal");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_sendMoveActionSequence_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::ActionSequence    actions;      
             CORBA::Short    times;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  actions;
             _true_call >>  times;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendMoveActionSequence(
                  actions,
                  times
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_sendMoveActionSequence");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_sendVehicleInfo_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::AirUnitInfo    info;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  info;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendVehicleInfo(
                  info
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_sendVehicleInfo");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setRearVehicles_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfoSequence    rears;      
             CORBA::Float    distance;      
             CORBA::Float    angle;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  rears;
             _true_call >>  distance;
             _true_call >>  angle;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setRearVehicles(
                  rears,
                  distance,
                  angle
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setRearVehicles");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setFormation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::Formation    form;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  form;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setFormation(
                  form
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setFormation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_reportTrap_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::TrapPoint3D    trap;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  trap;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->reportTrap(
                  trap
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_reportTrap");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_clearTraps_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->clearTraps(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_clearTraps");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_getTraps_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             SRIO_Air_Unit::Air_Unit::TrapPointSequence*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->getTraps(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_getTraps");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setTrapPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::TrapPoint3D    trap;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  trap;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setTrapPoint(
                  trap
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setTrapPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setTrack_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::TaskPath    track;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  track;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setTrack(
                  track
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setTrack");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setTaskPath_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::TaskPath    path;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  path;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setTaskPath(
                  path
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setTaskPath");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setTaskPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::Point3D    point;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  point;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setTaskPoint(
                  point
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setTaskPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_clearTaskPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->clearTaskPoint(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_clearTaskPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setFollower_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    ui;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  ui;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setFollower(
                  ui
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setFollower");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_unsetFollower_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _uid_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->unsetFollower(
                 (iluShortCharacter*) _uid_wr.m_r_cstring
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_unsetFollower");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_startPhotoStream_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             CORBA::Float    frequency;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  frequency;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->startPhotoStream(
                  frequency
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_startPhotoStream");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_stopPhotoStream_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->stopPhotoStream(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_stopPhotoStream");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_obtainCtrlAuthority_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->obtainCtrlAuthority(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_obtainCtrlAuthority");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_releaseCtrlAuthority_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->releaseCtrlAuthority(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_releaseCtrlAuthority");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setActionRole_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::ActionRole            ar;    
             iluEnumWrapper       _ar_wr( (iluDummyEnum &) ar);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _ar_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setActionRole(
                    (SRIO_Air_Unit::Air_Unit::ActionRole) _ar_wr.m_r_enum 

              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setActionRole");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setActionMode_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::ActionMode            am;    
             iluEnumWrapper       _am_wr( (iluDummyEnum &) am);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _am_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setActionMode(
                    (SRIO_Air_Unit::Air_Unit::ActionMode) _am_wr.m_r_enum 

              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setActionMode");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setCruiseScope_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::Site    s;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  s;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setCruiseScope(
                  s
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setCruiseScope");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_sendControlledVehicle_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Air_Unit::Air_Unit::UnitSBHSeq    uss;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uss;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendControlledVehicle(
                  uss
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_sendControlledVehicle");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_confirmThrow_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->confirmThrow(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_confirmThrow");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_cancelThrow_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->cancelThrow(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_cancelThrow");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_actionThrow_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->actionThrow(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_actionThrow");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_confirmFire_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->confirmFire(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_confirmFire");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_cancelFire_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->cancelFire(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_cancelFire");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_confirmFireLocation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->confirmFireLocation(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_confirmFireLocation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_cancelFireLocation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->cancelFireLocation(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_cancelFireLocation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_controlVehicleVelocity_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             CORBA::Float    vx;      
             CORBA::Float    vy;      
             CORBA::Float    vz;      
             CORBA::Float    angle;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  vx;
             _true_call >>  vy;
             _true_call >>  vz;
             _true_call >>  angle;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->controlVehicleVelocity(
                  vx,
                  vy,
                  vz,
                  angle
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_controlVehicleVelocity");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_backHome_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->backHome(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_backHome");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Air_Unit_Air_Unit_setCruiseSpeed_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Air_Unit::Air_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             CORBA::Float    cs;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Air_Unit::Air_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  cs;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setCruiseSpeed(
                  cs
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Air_Unit_Air_Unit_setCruiseSpeed");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

SRIO_Air_Unit_true::Air_Unit_initializer::
Air_Unit_initializer () {
             ensure_instantiation();
}

void *
SRIO_Air_Unit_true::Air_Unit_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Air_Unit::p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
SRIO_Air_Unit_true::Air_Unit_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_getCurrentSpeed_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_getCurrentPose_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_getCurrentInfo_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 3,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_sendMoveAction_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 4,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_sendGimbalSpeed_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 5,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_resetGimbal_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 6,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_sendMoveActionSequence_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 7,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_sendVehicleInfo_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 8,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setRearVehicles_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 9,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setFormation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 10,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_reportTrap_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 11,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_clearTraps_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 12,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_getTraps_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 13,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setTrapPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 14,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setTrack_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 15,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setTaskPath_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 16,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setTaskPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 17,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_clearTaskPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 18,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setFollower_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 19,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_unsetFollower_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 20,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_startPhotoStream_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 21,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_stopPhotoStream_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 22,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_obtainCtrlAuthority_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 23,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_releaseCtrlAuthority_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 24,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setActionRole_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 25,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setActionMode_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 26,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setCruiseScope_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 27,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_sendControlledVehicle_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 28,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_confirmThrow_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 29,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_cancelThrow_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 30,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_actionThrow_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 31,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_confirmFire_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 32,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_cancelFire_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 33,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_confirmFireLocation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 34,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_cancelFireLocation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 35,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_controlVehicleVelocity_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 36,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_backHome_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()->cl_methods + 37,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Air_Unit_Air_Unit_setCruiseSpeed_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
