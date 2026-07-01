
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Monitor-cpptrue.hpp"

// Globals and statics 

int SRIO_Monitor_true::Monitor_initializer::initialized; 
SRIO_Monitor_true::Monitor_initializer
     SRIO_Monitor_true::Monitor_initializer::sm_the_true_SRIO_Monitor_Monitor_initializer;
// Method Stubs

static void SRIO_Monitor_Monitor_sendUnitInfo_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Monitor::Monitor::CompleteUnitInfo    unitInfo;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  unitInfo;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendUnitInfo(
                  unitInfo
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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_sendUnitInfo");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Monitor_Monitor_sendTrapPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::TrapPoint    tp;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  tp;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendTrapPoint(
                  tp
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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_sendTrapPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Monitor_Monitor_sendFireLocation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _fid_length;
             iluShortCharacter*          fid = ILUCPP_NULL;
             iluCStringWrapper _fid_wr(fid, _fid_length);
             SRIO_Ground_Unit::Ground_Unit::Point2D    fp;      
             CORBA_(Short)    responseTime;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _fid_wr;
             _true_call >>  fp;
             _true_call >>  responseTime;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendFireLocation(
                 (iluShortCharacter*) _fid_wr.m_r_cstring,
                  fp,
                  responseTime
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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_sendFireLocation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Monitor_Monitor_foundFire_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _fid_length;
             iluShortCharacter*          fid = ILUCPP_NULL;
             iluCStringWrapper _fid_wr(fid, _fid_length);
             SRIO_Monitor::Monitor::PictureInfo    pi;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _fid_wr;
             _true_call >>  pi;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->foundFire(
                 (iluShortCharacter*) _fid_wr.m_r_cstring,
                  pi
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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_foundFire");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Monitor_Monitor_confirmAction_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _fid_length;
             iluShortCharacter*          fid = ILUCPP_NULL;
             iluCStringWrapper _fid_wr(fid, _fid_length);
             CORBA_(Short)    responseTime;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _fid_wr;
             _true_call >>  responseTime;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->confirmAction(
                 (iluShortCharacter*) _fid_wr.m_r_cstring,
                  responseTime
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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_confirmAction");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Monitor_Monitor_backHome_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);
             SRIO_Monitor::Monitor::BackHomeReason            bhr;    
             iluEnumWrapper       _bhr_wr( (iluDummyEnum &) bhr);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _uid_wr;
             _true_call >> _bhr_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->backHome(
                 (iluShortCharacter*) _uid_wr.m_r_cstring,
                    (SRIO_Monitor::Monitor::BackHomeReason) _bhr_wr.m_r_enum 

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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_backHome");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Monitor_Monitor_sendMissionState_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _fid_length;
             iluShortCharacter*          fid = ILUCPP_NULL;
             iluCStringWrapper _fid_wr(fid, _fid_length);
             SRIO_Monitor::Monitor::MissionSituation            ms;    
             iluEnumWrapper       _ms_wr( (iluDummyEnum &) ms);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _fid_wr;
             _true_call >> _ms_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendMissionState(
                 (iluShortCharacter*) _fid_wr.m_r_cstring,
                    (SRIO_Monitor::Monitor::MissionSituation) _ms_wr.m_r_enum 

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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_sendMissionState");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Monitor_Monitor_sendPicture_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Monitor::Monitor_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Monitor::Monitor::iluGetILUClassRecord());
             CORBA_(Boolean)        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _pictureName_length;
             iluShortCharacter*          pictureName = ILUCPP_NULL;
             iluCStringWrapper _pictureName_wr(pictureName, _pictureName_length);
             SRIO_Monitor::Monitor::PictureFlow    pic;      
             CORBA_(Long)    time;      
             CORBA_(Long)    procedureStartTime;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Monitor::Monitor_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _pictureName_wr;
             _true_call >>  pic;
             _true_call >>  time;
             _true_call >>  procedureStartTime;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendPicture(
                 (iluShortCharacter*) _pictureName_wr.m_r_cstring,
                  pic,
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
     catch(CORBA_(SystemException)& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Monitor_Monitor_sendPicture");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

SRIO_Monitor_true::Monitor_initializer::
Monitor_initializer () {
             ensure_instantiation();
}

void *
SRIO_Monitor_true::Monitor_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Monitor::p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
SRIO_Monitor_true::Monitor_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_sendUnitInfo_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_sendTrapPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_sendFireLocation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 3,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_foundFire_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 4,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_confirmAction_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 5,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_backHome_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 6,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_sendMissionState_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Monitor::Monitor::iluGetILUClassRecord()->cl_methods + 7,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Monitor_Monitor_sendPicture_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
