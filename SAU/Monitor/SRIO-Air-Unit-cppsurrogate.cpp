
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Air-Unit-cppsurrogate.hpp"

// Static class initialization

SRIO_Air_Unit_surrogate::Air_Unit_initializer
     SRIO_Air_Unit_surrogate::Air_Unit_initializer::sm_the_surrogate_SRIO_Air_Unit_Air_Unit_initializer;
int SRIO_Air_Unit_surrogate::Air_Unit::_initialized; 

// SRIO_Air_Unit::Air_Unit surrogate methods 


SRIO_Air_Unit::Air_Unit::Speed3D 
SRIO_Air_Unit_surrogate::Air_Unit::
getCurrentSpeed (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          SRIO_Air_Unit::Air_Unit::Speed3D       return_value;    
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

         _surrogate_call >> return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


SRIO_Air_Unit::Air_Unit::Pose3D 
SRIO_Air_Unit_surrogate::Air_Unit::
getCurrentPose (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          SRIO_Air_Unit::Air_Unit::Pose3D       return_value;    
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

         _surrogate_call >> return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


SRIO_Air_Unit::Air_Unit::AirUnitInfo* 
SRIO_Air_Unit_surrogate::Air_Unit::
getCurrentInfo (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          SRIO_Air_Unit::Air_Unit::AirUnitInfo*  p_return_value = new(SRIO_Air_Unit::Air_Unit::AirUnitInfo);  
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
SRIO_Air_Unit_surrogate::Air_Unit::
sendMoveAction (
          const SRIO_Air_Unit::Air_Unit::MoveAction&  action
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 3, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += action;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << action;
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
SRIO_Air_Unit_surrogate::Air_Unit::
sendGimbalSpeed (
          const SRIO_Air_Unit::Air_Unit::GimbalSpeed&  speed
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 4, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += speed;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << speed;
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
SRIO_Air_Unit_surrogate::Air_Unit::
resetGimbal (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 5, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
sendMoveActionSequence (
          const SRIO_Air_Unit::Air_Unit::ActionSequence&  actions,
          CORBA::Short  times
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 6, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += actions;
                 _surrogate_call += times;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << actions;
              _surrogate_call << times;
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
SRIO_Air_Unit_surrogate::Air_Unit::
sendVehicleInfo (
          const SRIO_Air_Unit::Air_Unit::AirUnitInfo&  info
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 7, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += info;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << info;
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
SRIO_Air_Unit_surrogate::Air_Unit::
setRearVehicles (
          const SRIO_Unit::General_Unit::UnitInfoSequence&  rears,
          CORBA::Float  distance,
          CORBA::Float  angle
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 8, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += rears;
                 _surrogate_call += distance;
                 _surrogate_call += angle;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << rears;
              _surrogate_call << distance;
              _surrogate_call << angle;
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
SRIO_Air_Unit_surrogate::Air_Unit::
setFormation (
          const SRIO_Air_Unit::Air_Unit::Formation&  form
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 9, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += form;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << form;
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
SRIO_Air_Unit_surrogate::Air_Unit::
reportTrap (
          const SRIO_Air_Unit::Air_Unit::TrapPoint3D&  trap
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 10, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += trap;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << trap;
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
SRIO_Air_Unit_surrogate::Air_Unit::
clearTraps (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 11, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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


SRIO_Air_Unit::Air_Unit::TrapPointSequence* 
SRIO_Air_Unit_surrogate::Air_Unit::
getTraps (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 12, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          SRIO_Air_Unit::Air_Unit::TrapPointSequence*  p_return_value = new(SRIO_Air_Unit::Air_Unit::TrapPointSequence);  
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
SRIO_Air_Unit_surrogate::Air_Unit::
setTrapPoint (
          const SRIO_Air_Unit::Air_Unit::TrapPoint3D&  trap
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 13, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += trap;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << trap;
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
SRIO_Air_Unit_surrogate::Air_Unit::
setTrack (
          const SRIO_Air_Unit::Air_Unit::TaskPath&  track
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 14, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += track;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << track;
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
SRIO_Air_Unit_surrogate::Air_Unit::
setTaskPath (
          const SRIO_Air_Unit::Air_Unit::TaskPath&  path
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 15, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += path;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << path;
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
SRIO_Air_Unit_surrogate::Air_Unit::
setTaskPoint (
          const SRIO_Air_Unit::Air_Unit::Point3D&  point
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 16, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += point;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << point;
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
SRIO_Air_Unit_surrogate::Air_Unit::
clearTaskPoint (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 17, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
setFollower (
          const SRIO_Unit::General_Unit::UnitInfo&  ui
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 18, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += ui;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << ui;
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
SRIO_Air_Unit_surrogate::Air_Unit::
unsetFollower (
          const iluShortCharacter*  uid
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 19, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
startPhotoStream (
          CORBA::Float  frequency
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 20, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += frequency;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << frequency;
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
SRIO_Air_Unit_surrogate::Air_Unit::
stopPhotoStream (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 21, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
obtainCtrlAuthority (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 22, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
releaseCtrlAuthority (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 23, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
setActionRole (
          SRIO_Air_Unit::Air_Unit::ActionRole  ar
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 24, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _ar((iluDummyEnum &) ar);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _ar;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _ar;
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
SRIO_Air_Unit_surrogate::Air_Unit::
setActionMode (
          SRIO_Air_Unit::Air_Unit::ActionMode  am
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 25, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _am((iluDummyEnum &) am);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _am;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _am;
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
SRIO_Air_Unit_surrogate::Air_Unit::
setCruiseScope (
          const SRIO_Air_Unit::Air_Unit::Site&  s
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 26, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += s;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << s;
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
SRIO_Air_Unit_surrogate::Air_Unit::
sendControlledVehicle (
          const SRIO_Air_Unit::Air_Unit::UnitSBHSeq&  uss
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 27, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uss;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uss;
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
SRIO_Air_Unit_surrogate::Air_Unit::
confirmThrow (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 28, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
cancelThrow (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 29, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
actionThrow (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 30, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
confirmFire (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 31, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
cancelFire (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 32, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
confirmFireLocation (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 33, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
cancelFireLocation (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 34, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
controlVehicleVelocity (
          CORBA::Float  vx,
          CORBA::Float  vy,
          CORBA::Float  vz,
          CORBA::Float  angle
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 35, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += vx;
                 _surrogate_call += vy;
                 _surrogate_call += vz;
                 _surrogate_call += angle;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << vx;
              _surrogate_call << vy;
              _surrogate_call << vz;
              _surrogate_call << angle;
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
SRIO_Air_Unit_surrogate::Air_Unit::
backHome (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 36, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

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
SRIO_Air_Unit_surrogate::Air_Unit::
setCruiseSpeed (
          CORBA::Float  cs
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 37, this, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += cs;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << cs;
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

// Initialize to use SRIO_Air_Unit::Air_Unit objects

void
SRIO_Air_Unit_surrogate::Air_Unit::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord(),
                SRIO_Air_Unit_surrogate::Air_Unit::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a SRIO_Air_Unit::Air_Unit surrogate
 
iluObject*
SRIO_Air_Unit_surrogate::Air_Unit::
create_surrogate (iluKernelObject _kernel_object) {
        SRIO_Air_Unit::Air_Unit* _new_object = new SRIO_Air_Unit_surrogate::Air_Unit();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of SRIO_Air_Unit::Air_Unit class upon load
 
SRIO_Air_Unit_surrogate::Air_Unit_initializer::
Air_Unit_initializer () {
        ensure_instantiation();
}
 
void *
SRIO_Air_Unit_surrogate::Air_Unit_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Air_Unit::p_initialization_function_list,
                SRIO_Air_Unit_surrogate::Air_Unit::iluInitialize);
        return this;
}
