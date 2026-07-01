
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Ground-Unit-cpptrue.hpp"

// Globals and statics 

int SRIO_Ground_Unit_true::Ground_Unit_initializer::initialized; 
SRIO_Ground_Unit_true::Ground_Unit_initializer
     SRIO_Ground_Unit_true::Ground_Unit_initializer::sm_the_true_SRIO_Ground_Unit_Ground_Unit_initializer;
// Method Stubs

static void SRIO_Ground_Unit_Ground_Unit_getCurrentSpeed_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             SRIO_Ground_Unit::Ground_Unit::Speed2D    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_getCurrentSpeed");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_getCurrentPose_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             SRIO_Ground_Unit::Ground_Unit::Pose2D    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_getCurrentPose");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_getCurrentInfo_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_getCurrentInfo");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_sendMoveAction_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::MoveAction    action;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_sendMoveAction");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_sendMoveActionSequence_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::ActionSequence    actions;      
             CORBA::Short    times;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_sendMoveActionSequence");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_sendVehicleInfo_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo    info;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_sendVehicleInfo");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_setRearVehicles_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfoSequence    rears;      
             CORBA::Float    distance;      
             CORBA::Float    angle;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_setRearVehicles");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_setFormation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::Formation    form;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_setFormation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_reportTrap_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::TrapPoint2D    trap;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_reportTrap");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_clearTraps_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_clearTraps");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_getTraps_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             SRIO_Ground_Unit::Ground_Unit::TrapPointSequence*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_getTraps");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_setTrapPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::TrapPoint2D    trap;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_setTrapPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_setTrack_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::TaskPath    track;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_setTrack");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_setTaskPath_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::TaskPath    path;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_setTaskPath");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_setTaskPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Ground_Unit::Ground_Unit::Point2D    point;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_setTaskPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_startPhotoStream_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             CORBA::Float    frequency;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_startPhotoStream");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_stopPhotoStream_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_stopPhotoStream");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_setFollower_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    ui;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_setFollower");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Ground_Unit_Ground_Unit_unsetFollower_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Ground_Unit::Ground_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Ground_Unit::Ground_Unit_ptr)(_discriminator.m_pv_iluobject);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Ground_Unit_Ground_Unit_unsetFollower");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

SRIO_Ground_Unit_true::Ground_Unit_initializer::
Ground_Unit_initializer () {
             ensure_instantiation();
}

void *
SRIO_Ground_Unit_true::Ground_Unit_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Ground_Unit::p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
SRIO_Ground_Unit_true::Ground_Unit_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_getCurrentSpeed_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_getCurrentPose_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_getCurrentInfo_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 3,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_sendMoveAction_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 4,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_sendMoveActionSequence_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 5,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_sendVehicleInfo_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 6,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_setRearVehicles_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 7,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_setFormation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 8,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_reportTrap_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 9,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_clearTraps_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 10,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_getTraps_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 11,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_setTrapPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 12,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_setTrack_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 13,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_setTaskPath_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 14,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_setTaskPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 15,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_startPhotoStream_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 16,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_stopPhotoStream_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 17,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_setFollower_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()->cl_methods + 18,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Ground_Unit_Ground_Unit_unsetFollower_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
