
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Unit-cpptrue.hpp"

// Globals and statics 

int SRIO_Unit_true::General_Unit_initializer::initialized; 
SRIO_Unit_true::General_Unit_initializer
     SRIO_Unit_true::General_Unit_initializer::sm_the_true_SRIO_Unit_General_Unit_initializer;
// Method Stubs

static void SRIO_Unit_General_Unit_getID_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             iluCardinal       _return_value_length;
             iluShortCharacter*          return_value = ILUCPP_NULL;
             iluCStringWrapper _return_value_wr(return_value, _return_value_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             return_value  = _true_object->getID(
              );

            _return_value_wr.m_r_cstring = return_value;
            _return_value_wr.m_r_card_length =
                    strlen(_return_value_wr.m_r_cstring);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_getID");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_getCosNamingSBH_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             iluCardinal       _return_value_length;
             iluShortCharacter*          return_value = ILUCPP_NULL;
             iluCStringWrapper _return_value_wr(return_value, _return_value_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             return_value  = _true_object->getCosNamingSBH(
              );

            _return_value_wr.m_r_cstring = return_value;
            _return_value_wr.m_r_card_length =
                    strlen(_return_value_wr.m_r_cstring);

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_getCosNamingSBH");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_getFrontUnitInfo_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             SRIO_Unit::General_Unit::UnitInfo*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->getFrontUnitInfo(
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_getFrontUnitInfo");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_setRole_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitRole            role;    
             iluEnumWrapper       _role_wr( (iluDummyEnum &) role);
             iluCardinal       _consoleSBH_length;
             iluShortCharacter*          consoleSBH = ILUCPP_NULL;
             iluCStringWrapper _consoleSBH_wr(consoleSBH, _consoleSBH_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _role_wr;
             _true_call >> _consoleSBH_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setRole(
                    (SRIO_Unit::General_Unit::UnitRole) _role_wr.m_r_enum, 

                 (iluShortCharacter*) _consoleSBH_wr.m_r_cstring
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_setRole");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_setMode_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitMode            mode;    
             iluEnumWrapper       _mode_wr( (iluDummyEnum &) mode);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _mode_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setMode(
                    (SRIO_Unit::General_Unit::UnitMode) _mode_wr.m_r_enum 

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_setMode");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_setMinorMode_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitMinorMode            minorMode;    
             iluEnumWrapper       _minorMode_wr( (iluDummyEnum &) minorMode);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _minorMode_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setMinorMode(
                    (SRIO_Unit::General_Unit::UnitMinorMode) _minorMode_wr.m_r_enum 

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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_setMinorMode");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_setALeader_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _leaderSBH_length;
             iluShortCharacter*          leaderSBH = ILUCPP_NULL;
             iluCStringWrapper _leaderSBH_wr(leaderSBH, _leaderSBH_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _leaderSBH_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setALeader(
                 (iluShortCharacter*) _leaderSBH_wr.m_r_cstring
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_setALeader");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_registerFollower_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _followerUID_length;
             iluShortCharacter*          followerUID = ILUCPP_NULL;
             iluCStringWrapper _followerUID_wr(followerUID, _followerUID_length);
             iluCardinal       _followerSBH_length;
             iluShortCharacter*          followerSBH = ILUCPP_NULL;
             iluCStringWrapper _followerSBH_wr(followerSBH, _followerSBH_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _followerUID_wr;
             _true_call >> _followerSBH_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->registerFollower(
                 (iluShortCharacter*) _followerUID_wr.m_r_cstring,
                 (iluShortCharacter*) _followerSBH_wr.m_r_cstring
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_registerFollower");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_unregisterFollower_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _followerUID_length;
             iluShortCharacter*          followerUID = ILUCPP_NULL;
             iluCStringWrapper _followerUID_wr(followerUID, _followerUID_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _followerUID_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->unregisterFollower(
                 (iluShortCharacter*) _followerUID_wr.m_r_cstring
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_unregisterFollower");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_addRearVehicle_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    rearInfo;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  rearInfo;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->addRearVehicle(
                  rearInfo
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_addRearVehicle");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_deleteRearVehicle_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _uid_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->deleteRearVehicle(
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_deleteRearVehicle");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_reportDeadVehicle_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);
             iluCardinal       _details_length;
             iluShortCharacter*          details = ILUCPP_NULL;
             iluCStringWrapper _details_wr(details, _details_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _uid_wr;
             _true_call >> _details_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->reportDeadVehicle(
                 (iluShortCharacter*) _uid_wr.m_r_cstring,
                 (iluShortCharacter*) _details_wr.m_r_cstring
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_reportDeadVehicle");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_shutDown_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->shutDown(
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_shutDown");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Unit_General_Unit_takePicture_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Unit::General_Unit_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Unit::General_Unit::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             CORBA::Long    time;      
             CORBA::Long    procedureStartTime;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Unit::General_Unit_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  time;
             _true_call >>  procedureStartTime;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->takePicture(
                  time,
                  procedureStartTime
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Unit_General_Unit_takePicture");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

SRIO_Unit_true::General_Unit_initializer::
General_Unit_initializer () {
             ensure_instantiation();
}

void *
SRIO_Unit_true::General_Unit_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Unit::p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
SRIO_Unit_true::General_Unit_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_getID_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_getCosNamingSBH_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_getFrontUnitInfo_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 3,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_setRole_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 4,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_setMode_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 5,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_setMinorMode_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 6,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_setALeader_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 7,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_registerFollower_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 8,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_unregisterFollower_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 9,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_addRearVehicle_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 10,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_deleteRearVehicle_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 11,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_reportDeadVehicle_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 12,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_shutDown_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Unit::General_Unit::iluGetILUClassRecord()->cl_methods + 13,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Unit_General_Unit_takePicture_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
