
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Console-cppsurrogate.hpp"

// Static class initialization

SRIO_Console_surrogate::Console_initializer
     SRIO_Console_surrogate::Console_initializer::sm_the_surrogate_SRIO_Console_Console_initializer;
int SRIO_Console_surrogate::Console::_initialized; 

// SRIO_Console::Console surrogate methods 


SRIO_Console::Console::CosInfoSeq* 
SRIO_Console_surrogate::Console::
getCosNamingInfo (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Console::Console::CosInfoSeq*  p_return_value = new(SRIO_Console::Console::CosInfoSeq);  
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
SRIO_Console_surrogate::Console::
sendMsg (
          const SRIO_Console::Console::Message&  m
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += m;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << m;
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
SRIO_Console_surrogate::Console::
bind (
          const iluShortCharacter*  uid,
          const iluShortCharacter*  sbh
         ) throw (CORBA::SystemException, SRIO_Console::Console::AlreadyBind) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;
          iluCardinal       uid_length =
                  strlen(uid);
          iluCStringWrapper _uid(uid, uid_length);
          iluCardinal       sbh_length =
                  strlen(sbh);
          iluCStringWrapper _sbh(sbh, sbh_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _uid;
                 _surrogate_call += _sbh;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _uid;
              _surrogate_call << _sbh;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_bind_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
SRIO_Console_surrogate::Console::
_throw_bind_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA::SystemException, SRIO_Console::Console::AlreadyBind) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        SRIO_Console::Console::AlreadyBind _exception;
                        throw(_exception);
                      };

                default: {
                          CORBA::UNKNOWN _exception;
                          throw(_exception);
                         };
           }; //end switch

     } // end try
     catch (CORBA::SystemException& _exception) {
                 _call.iluSetErrorType(_exception.exception_kind());
                 _exception._raise();
     }
 }


CORBA::Boolean 
SRIO_Console_surrogate::Console::
unbind (
          const iluShortCharacter*  uid,
          const iluShortCharacter*  details
         ) throw (CORBA::SystemException, SRIO_Console::Console::NotFound) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 3, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;
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

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_unbind_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
SRIO_Console_surrogate::Console::
_throw_unbind_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA::SystemException, SRIO_Console::Console::NotFound) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        SRIO_Console::Console::NotFound _exception;
                        throw(_exception);
                      };

                default: {
                          CORBA::UNKNOWN _exception;
                          throw(_exception);
                         };
           }; //end switch

     } // end try
     catch (CORBA::SystemException& _exception) {
                 _call.iluSetErrorType(_exception.exception_kind());
                 _exception._raise();
     }
 }


CORBA::Boolean 
SRIO_Console_surrogate::Console::
rebind (
          const iluShortCharacter*  uid,
          const iluShortCharacter*  sbh
         ) throw (CORBA::SystemException, SRIO_Console::Console::NotFound) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 4, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;
          iluCardinal       uid_length =
                  strlen(uid);
          iluCStringWrapper _uid(uid, uid_length);
          iluCardinal       sbh_length =
                  strlen(sbh);
          iluCStringWrapper _sbh(sbh, sbh_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _uid;
                 _surrogate_call += _sbh;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _uid;
              _surrogate_call << _sbh;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_rebind_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> _return_value; 


          return return_value;

   } // end try
   catch(CORBA::SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
SRIO_Console_surrogate::Console::
_throw_rebind_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA::SystemException, SRIO_Console::Console::NotFound) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        SRIO_Console::Console::NotFound _exception;
                        throw(_exception);
                      };

                default: {
                          CORBA::UNKNOWN _exception;
                          throw(_exception);
                         };
           }; //end switch

     } // end try
     catch (CORBA::SystemException& _exception) {
                 _call.iluSetErrorType(_exception.exception_kind());
                 _exception._raise();
     }
 }


CORBA::Boolean 
SRIO_Console_surrogate::Console::
setNickname (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo,
          const iluShortCharacter*  newName
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 5, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       newName_length =
                  strlen(newName);
          iluCStringWrapper _newName(newName, newName_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo;
                 _surrogate_call += _newName;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo;
              _surrogate_call << _newName;
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
SRIO_Console_surrogate::Console::
setPosition (
          const iluShortCharacter*  name,
          const SRIO_Console::Console::Point&  p
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 6, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       name_length =
                  strlen(name);
          iluCStringWrapper _name(name, name_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _name;
                 _surrogate_call += p;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _name;
              _surrogate_call << p;
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
SRIO_Console_surrogate::Console::
addGoalPoint (
          const SRIO_Console::Console::Point&  p
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 7, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += p;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << p;
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
SRIO_Console_surrogate::Console::
setGoalPoint (
          const SRIO_Console::Console::Point&  p
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 8, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += p;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << p;
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
SRIO_Console_surrogate::Console::
setRole (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo,
          SRIO_Console::Console::Role  r
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 9, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _r((iluDummyEnum &) r);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo;
                 _surrogate_call += _r;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo;
              _surrogate_call << _r;
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
SRIO_Console_surrogate::Console::
cancelRole (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 10, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo;
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
SRIO_Console_surrogate::Console::
setTrapPoint (
          const SRIO_Console::Console::TrapPoint&  p
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 11, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += p;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << p;
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
SRIO_Console_surrogate::Console::
setFollow (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo1,
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo2
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 12, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo1;
                 _surrogate_call += uinfo2;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo1;
              _surrogate_call << uinfo2;
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
SRIO_Console_surrogate::Console::
setFormationType (
          SRIO_Console::Console::FormationType  f
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 13, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _f((iluDummyEnum &) f);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _f;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _f;
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
SRIO_Console_surrogate::Console::
setTrackMode (
          SRIO_Console::Console::TrackMode  tm
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 14, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _tm((iluDummyEnum &) tm);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _tm;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _tm;
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
SRIO_Console_surrogate::Console::
getCurrentUnit (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 15, this, SRIO_Console::Console::iluGetILUClassRecord());

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


CORBA::Short 
SRIO_Console_surrogate::Console::
getUnitNum (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 16, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Short       return_value;    
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


CORBA::Short 
SRIO_Console_surrogate::Console::
getFormationNum (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 17, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Short       return_value;    
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


CORBA::Short 
SRIO_Console_surrogate::Console::
getTrapNum (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 18, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Short       return_value;    
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


SRIO_Console::Console::FormationType 
SRIO_Console_surrogate::Console::
getFormationType (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 19, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Console::Console::FormationType       return_value;    
          iluEnumWrapper        _return_value((iluDummyEnum &) return_value);
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


SRIO_Console::Console::FormationState 
SRIO_Console_surrogate::Console::
getFormationState (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 20, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Console::Console::FormationState       return_value;    
          iluEnumWrapper        _return_value((iluDummyEnum &) return_value);
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


SRIO_Console::Console::MissionState 
SRIO_Console_surrogate::Console::
getMissionState (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 21, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Console::Console::MissionState       return_value;    
          iluEnumWrapper        _return_value((iluDummyEnum &) return_value);
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


SRIO_Console::Console::Point 
SRIO_Console_surrogate::Console::
getUnitPoint (
          const iluShortCharacter*  name
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 22, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Console::Console::Point       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       name_length =
                  strlen(name);
          iluCStringWrapper _name(name, name_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _name;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _name;
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


SRIO_Unit::General_Unit::UnitInfo* 
SRIO_Console_surrogate::Console::
getByName (
          const iluShortCharacter*  name
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 23, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Unit::General_Unit::UnitInfo*  p_return_value = new(SRIO_Unit::General_Unit::UnitInfo);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       name_length =
                  strlen(name);
          iluCStringWrapper _name(name, name_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _name;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _name;
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


SRIO_Console::Console::Point 
SRIO_Console_surrogate::Console::
getLeaderPoint (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 24, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Console::Console::Point       return_value;    
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


SRIO_Console::Console::PointSeq* 
SRIO_Console_surrogate::Console::
getPointSeq (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 25, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          SRIO_Console::Console::PointSeq*  p_return_value = new(SRIO_Console::Console::PointSeq);  
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
SRIO_Console_surrogate::Console::
cancelFormation (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 26, this, SRIO_Console::Console::iluGetILUClassRecord());

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
SRIO_Console_surrogate::Console::
setLeaderSuspend (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 27, this, SRIO_Console::Console::iluGetILUClassRecord());

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
SRIO_Console_surrogate::Console::
recoveryLeaderAction (
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 28, this, SRIO_Console::Console::iluGetILUClassRecord());

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
SRIO_Console_surrogate::Console::
addUnitFormation (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 29, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo;
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
SRIO_Console_surrogate::Console::
deleteUnitFormation (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 30, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo;
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
SRIO_Console_surrogate::Console::
setUnitFault (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 31, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo;
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
SRIO_Console_surrogate::Console::
setUnitFaultPosition (
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 32, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += uinfo;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << uinfo;
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
SRIO_Console_surrogate::Console::
setFormationState (
          SRIO_Console::Console::FormationState  fs
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 33, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _fs((iluDummyEnum &) fs);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _fs;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _fs;
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
SRIO_Console_surrogate::Console::
setMissionState (
          const SRIO_Console::Console::MissionStateData&  msd
         ) throw (CORBA::SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 34, this, SRIO_Console::Console::iluGetILUClassRecord());

        try {
          CORBA::Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += msd;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << msd;
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

// Initialize to use SRIO_Console::Console objects

void
SRIO_Console_surrogate::Console::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                SRIO_Console::Console::iluGetILUClassRecord(),
                SRIO_Console_surrogate::Console::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a SRIO_Console::Console surrogate
 
iluObject*
SRIO_Console_surrogate::Console::
create_surrogate (iluKernelObject _kernel_object) {
        SRIO_Console::Console* _new_object = new SRIO_Console_surrogate::Console();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of SRIO_Console::Console class upon load
 
SRIO_Console_surrogate::Console_initializer::
Console_initializer () {
        ensure_instantiation();
}
 
void *
SRIO_Console_surrogate::Console_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Console::p_initialization_function_list,
                SRIO_Console_surrogate::Console::iluInitialize);
        return this;
}
