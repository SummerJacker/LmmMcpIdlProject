
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Ground-Unit-cppsurrogate.hpp"

// Static class initialization

SRIO_Ground_Unit_surrogate::Ground_Unit_initializer
     SRIO_Ground_Unit_surrogate::Ground_Unit_initializer::sm_the_surrogate_SRIO_Ground_Unit_Ground_Unit_initializer;
int SRIO_Ground_Unit_surrogate::Ground_Unit::_initialized; 

// SRIO_Ground_Unit::Ground_Unit surrogate methods 


SRIO_Ground_Unit::Ground_Unit::Speed2D 
SRIO_Ground_Unit_surrogate::Ground_Unit::
getCurrentSpeed (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

        try {
          SRIO_Ground_Unit::Ground_Unit::Speed2D       return_value;    
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


SRIO_Ground_Unit::Ground_Unit::Pose2D 
SRIO_Ground_Unit_surrogate::Ground_Unit::
getCurrentPose (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

        try {
          SRIO_Ground_Unit::Ground_Unit::Pose2D       return_value;    
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


SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo* 
SRIO_Ground_Unit_surrogate::Ground_Unit::
getCurrentInfo (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

        try {
          SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo*  p_return_value = new(SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo);  
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
SRIO_Ground_Unit_surrogate::Ground_Unit::
sendMoveAction (
          const SRIO_Ground_Unit::Ground_Unit::MoveAction&  action
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 3, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
sendMoveActionSequence (
          const SRIO_Ground_Unit::Ground_Unit::ActionSequence&  actions,
          CORBA::Short  times
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 4, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
sendVehicleInfo (
          const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo&  info
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 5, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
setRearVehicles (
          const SRIO_Unit::General_Unit::UnitInfoSequence&  rears,
          CORBA::Float  distance,
          CORBA::Float  angle
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 6, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
setFormation (
          const SRIO_Ground_Unit::Ground_Unit::Formation&  form
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 7, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
reportTrap (
          const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D&  trap
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 8, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
clearTraps (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 9, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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


SRIO_Ground_Unit::Ground_Unit::TrapPointSequence* 
SRIO_Ground_Unit_surrogate::Ground_Unit::
getTraps (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 10, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

        try {
          SRIO_Ground_Unit::Ground_Unit::TrapPointSequence*  p_return_value = new(SRIO_Ground_Unit::Ground_Unit::TrapPointSequence);  
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
SRIO_Ground_Unit_surrogate::Ground_Unit::
setTrapPoint (
          const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D&  trap
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 11, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
setTrack (
          const SRIO_Ground_Unit::Ground_Unit::TaskPath&  track
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 12, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
setTaskPath (
          const SRIO_Ground_Unit::Ground_Unit::TaskPath&  path
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 13, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
setTaskPoint (
          const SRIO_Ground_Unit::Ground_Unit::Point2D&  point
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 14, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
startPhotoStream (
          CORBA::Float  frequency
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 15, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
stopPhotoStream (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 16, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
setFollower (
          const SRIO_Unit::General_Unit::UnitInfo&  ui
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 17, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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
SRIO_Ground_Unit_surrogate::Ground_Unit::
unsetFollower (
          const iluShortCharacter*  uid
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 18, this, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());

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

/////////////////////////////////////////////////////////////////////////////

// Initialize to use SRIO_Ground_Unit::Ground_Unit objects

void
SRIO_Ground_Unit_surrogate::Ground_Unit::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord(),
                SRIO_Ground_Unit_surrogate::Ground_Unit::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a SRIO_Ground_Unit::Ground_Unit surrogate
 
iluObject*
SRIO_Ground_Unit_surrogate::Ground_Unit::
create_surrogate (iluKernelObject _kernel_object) {
        SRIO_Ground_Unit::Ground_Unit* _new_object = new SRIO_Ground_Unit_surrogate::Ground_Unit();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of SRIO_Ground_Unit::Ground_Unit class upon load
 
SRIO_Ground_Unit_surrogate::Ground_Unit_initializer::
Ground_Unit_initializer () {
        ensure_instantiation();
}
 
void *
SRIO_Ground_Unit_surrogate::Ground_Unit_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Ground_Unit::p_initialization_function_list,
                SRIO_Ground_Unit_surrogate::Ground_Unit::iluInitialize);
        return this;
}
