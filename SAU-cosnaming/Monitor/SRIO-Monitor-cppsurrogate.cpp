
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Monitor-cppsurrogate.hpp"

// Static class initialization

SRIO_Monitor_surrogate::Monitor_initializer
     SRIO_Monitor_surrogate::Monitor_initializer::sm_the_surrogate_SRIO_Monitor_Monitor_initializer;
int SRIO_Monitor_surrogate::Monitor::_initialized; 

// SRIO_Monitor::Monitor surrogate methods 


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
sendUnitInfo (
          const SRIO_Monitor::Monitor::CompleteUnitInfo&  unitInfo
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += unitInfo;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << unitInfo;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
sendTrapPoint (
          const SRIO_Console::Console::TrapPoint&  tp
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += tp;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << tp;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
sendFireLocation (
          const iluShortCharacter*  fid,
          const SRIO_Ground_Unit::Ground_Unit::Point2D&  fp,
          CORBA::Short  responseTime
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       fid_length =
                  strlen(fid);
          iluCStringWrapper _fid(fid, fid_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _fid;
                 _surrogate_call += fp;
                 _surrogate_call += responseTime;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _fid;
              _surrogate_call << fp;
              _surrogate_call << responseTime;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
foundFire (
          const iluShortCharacter*  fid,
          const SRIO_Monitor::Monitor::PictureInfo&  pi
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 3, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       fid_length =
                  strlen(fid);
          iluCStringWrapper _fid(fid, fid_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _fid;
                 _surrogate_call += pi;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _fid;
              _surrogate_call << pi;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
confirmAction (
          const iluShortCharacter*  fid,
          CORBA::Short  responseTime
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 4, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       fid_length =
                  strlen(fid);
          iluCStringWrapper _fid(fid, fid_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _fid;
                 _surrogate_call += responseTime;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _fid;
              _surrogate_call << responseTime;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
backHome (
          const iluShortCharacter*  uid,
          SRIO_Monitor::Monitor::BackHomeReason  bhr
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 5, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       uid_length =
                  strlen(uid);
          iluCStringWrapper _uid(uid, uid_length);
          iluEnumWrapper        _bhr((iluDummyEnum &) bhr);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _uid;
                 _surrogate_call += _bhr;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _uid;
              _surrogate_call << _bhr;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
sendMissionState (
          const iluShortCharacter*  fid,
          SRIO_Monitor::Monitor::MissionSituation  ms
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 6, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       fid_length =
                  strlen(fid);
          iluCStringWrapper _fid(fid, fid_length);
          iluEnumWrapper        _ms((iluDummyEnum &) ms);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _fid;
                 _surrogate_call += _ms;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _fid;
              _surrogate_call << _ms;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Monitor_surrogate::Monitor::
sendPicture (
          const iluShortCharacter*  pictureName,
          const SRIO_Monitor::Monitor::PictureFlow&  pic,
          CORBA::Long  time,
          CORBA::Long  procedureStartTime
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 7, this, SRIO_Monitor::Monitor::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       pictureName_length =
                  strlen(pictureName);
          iluCStringWrapper _pictureName(pictureName, pictureName_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _pictureName;
                 _surrogate_call += pic;
                 _surrogate_call += time;
                 _surrogate_call += procedureStartTime;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _pictureName;
              _surrogate_call << pic;
              _surrogate_call << time;
              _surrogate_call << procedureStartTime;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}

/////////////////////////////////////////////////////////////////////////////

// Initialize to use SRIO_Monitor::Monitor objects

void
SRIO_Monitor_surrogate::Monitor::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                SRIO_Monitor::Monitor::iluGetILUClassRecord(),
                SRIO_Monitor_surrogate::Monitor::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a SRIO_Monitor::Monitor surrogate
 
iluObject*
SRIO_Monitor_surrogate::Monitor::
create_surrogate (iluKernelObject _kernel_object) {
        SRIO_Monitor::Monitor* _new_object = new SRIO_Monitor_surrogate::Monitor();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of SRIO_Monitor::Monitor class upon load
 
SRIO_Monitor_surrogate::Monitor_initializer::
Monitor_initializer () {
        ensure_instantiation();
}
 
void *
SRIO_Monitor_surrogate::Monitor_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Monitor::p_initialization_function_list,
                SRIO_Monitor_surrogate::Monitor::iluInitialize);
        return this;
}
