
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Unit-cppsurrogate.hpp"

// Static class initialization

SRIO_Unit_surrogate::General_Unit_initializer
     SRIO_Unit_surrogate::General_Unit_initializer::sm_the_surrogate_SRIO_Unit_General_Unit_initializer;
int SRIO_Unit_surrogate::General_Unit::_initialized; 

// SRIO_Unit::General_Unit surrogate methods 


iluShortCharacter* 
SRIO_Unit_surrogate::General_Unit::
getID (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          iluShortCharacter*       return_value;
          iluCardinal       return_length;
          iluCStringWrapper   _return_value(return_value, return_length);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
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


iluShortCharacter* 
SRIO_Unit_surrogate::General_Unit::
getCosNamingSBH (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          iluShortCharacter*       return_value;
          iluCardinal       return_length;
          iluCStringWrapper   _return_value(return_value, return_length);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
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


SRIO_Unit::General_Unit::UnitInfo* 
SRIO_Unit_surrogate::General_Unit::
getFrontUnitInfo (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          SRIO_Unit::General_Unit::UnitInfo*  p_return_value = new(SRIO_Unit::General_Unit::UnitInfo);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 


          return p_return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA::Boolean 
SRIO_Unit_surrogate::General_Unit::
setRole (
          SRIO_Unit::General_Unit::UnitRole  role,
          const iluShortCharacter*  consoleSBH
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 3, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _role((iluDummyEnum &) role);
          iluCardinal       consoleSBH_length =
                  strlen(consoleSBH);
          iluCStringWrapper _consoleSBH(consoleSBH, consoleSBH_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _role;
                 _surrogate_call += _consoleSBH;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _role;
              _surrogate_call << _consoleSBH;
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
SRIO_Unit_surrogate::General_Unit::
setMode (
          SRIO_Unit::General_Unit::UnitMode  mode
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 4, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _mode((iluDummyEnum &) mode);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _mode;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _mode;
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
SRIO_Unit_surrogate::General_Unit::
setMinorMode (
          SRIO_Unit::General_Unit::UnitMinorMode  minorMode
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 5, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _minorMode((iluDummyEnum &) minorMode);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _minorMode;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _minorMode;
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
SRIO_Unit_surrogate::General_Unit::
setALeader (
          const iluShortCharacter*  leaderSBH
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 6, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       leaderSBH_length =
                  strlen(leaderSBH);
          iluCStringWrapper _leaderSBH(leaderSBH, leaderSBH_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _leaderSBH;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _leaderSBH;
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
SRIO_Unit_surrogate::General_Unit::
registerFollower (
          const iluShortCharacter*  followerUID,
          const iluShortCharacter*  followerSBH
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 7, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       followerUID_length =
                  strlen(followerUID);
          iluCStringWrapper _followerUID(followerUID, followerUID_length);
          iluCardinal       followerSBH_length =
                  strlen(followerSBH);
          iluCStringWrapper _followerSBH(followerSBH, followerSBH_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _followerUID;
                 _surrogate_call += _followerSBH;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _followerUID;
              _surrogate_call << _followerSBH;
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
SRIO_Unit_surrogate::General_Unit::
unregisterFollower (
          const iluShortCharacter*  followerUID
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 8, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       followerUID_length =
                  strlen(followerUID);
          iluCStringWrapper _followerUID(followerUID, followerUID_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _followerUID;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _followerUID;
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
SRIO_Unit_surrogate::General_Unit::
addRearVehicle (
          const SRIO_Unit::General_Unit::UnitInfo&  rearInfo
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 9, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += rearInfo;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << rearInfo;
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
SRIO_Unit_surrogate::General_Unit::
deleteRearVehicle (
          const iluShortCharacter*  uid
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 10, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       uid_length =
                  strlen(uid);
          iluCStringWrapper _uid(uid, uid_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _uid;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _uid;
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
SRIO_Unit_surrogate::General_Unit::
reportDeadVehicle (
          const iluShortCharacter*  uid,
          const iluShortCharacter*  details
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 11, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       uid_length =
                  strlen(uid);
          iluCStringWrapper _uid(uid, uid_length);
          iluCardinal       details_length =
                  strlen(details);
          iluCStringWrapper _details(details, details_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _uid;
                 _surrogate_call += _details;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _uid;
              _surrogate_call << _details;
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
SRIO_Unit_surrogate::General_Unit::
shutDown (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 12, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
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
SRIO_Unit_surrogate::General_Unit::
takePicture (
          CORBA::Long  time,
          CORBA::Long  procedureStartTime
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 13, this, SRIO_Unit::General_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += time;
                 _surrogate_call += procedureStartTime;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
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

// Initialize to use SRIO_Unit::General_Unit objects

void
SRIO_Unit_surrogate::General_Unit::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                SRIO_Unit::General_Unit::iluGetILUClassRecord(),
                SRIO_Unit_surrogate::General_Unit::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a SRIO_Unit::General_Unit surrogate
 
iluObject*
SRIO_Unit_surrogate::General_Unit::
create_surrogate (iluKernelObject _kernel_object) {
        SRIO_Unit::General_Unit* _new_object = new SRIO_Unit_surrogate::General_Unit();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of SRIO_Unit::General_Unit class upon load
 
SRIO_Unit_surrogate::General_Unit_initializer::
General_Unit_initializer () {
        ensure_instantiation();
}
 
void *
SRIO_Unit_surrogate::General_Unit_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Unit::p_initialization_function_list,
                SRIO_Unit_surrogate::General_Unit::iluInitialize);
        return this;
}
