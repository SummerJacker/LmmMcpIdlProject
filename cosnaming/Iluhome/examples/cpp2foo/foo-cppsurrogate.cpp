
// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

#include "foo-cppsurrogate.hpp"

// Static class initialization

foo_surrogate_bar_initializer
     foo_surrogate_bar_initializer::sm_the_surrogate_foo_bar_initializer;
int foo_surrogate_bar::_initialized; 

// foo_bar surrogate methods 


CORBA_Boolean 
foo_surrogate_bar::
zap (
          CORBA_Long  inarg,
          CORBA_Octet&  inoutarg,
          CORBA_Double&  outarg
         ) throw (CORBA_SystemException, foo_zapexception) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, foo_bar::iluGetILUClassRecord());

        try {
          CORBA_Boolean       return_value;    
          iluBoolWrapper      _return_value(return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_zap_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> _return_value; 
         _surrogate_call >> inoutarg; 
         _surrogate_call >> outarg; 


          return return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
foo_surrogate_bar::
_throw_zap_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, foo_zapexception) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        foo_zapexception _exception;
#ifdef __SUNPROC_CC
                          _call >>  _exception._m_value;
#else
                          _call >>  _exception._m_value;
#endif
                        throw(_exception);
                      };

                default: {
                          CORBA_UNKNOWN _exception;
                          throw(_exception);
                         };
           }; //end switch

     } // end try
     catch (CORBA_SystemException& _exception) {
                 _call.iluSetErrorType(_exception.exception_kind());
                 _exception._raise();
     }
 }


foo_bar_ptr 
foo_surrogate_bar::
passobj (
          foo_bar_ptr  inarg,
          foo_bar_ptr&  inoutarg,
          foo_bar_ptr&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, foo_bar::iluGetILUClassRecord());

        try {
          iluObjectWrapper _return_value(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord()); 
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluObjectWrapper _inarg(inarg, ILUCPP_FALSE, ( inarg ? ILUCPP_NULL : foo_bar::iluGetILUClassRecord())); 
          iluObjectWrapper _inoutarg(inoutarg, ILUCPP_FALSE, ( inoutarg ? ILUCPP_NULL : foo_bar::iluGetILUClassRecord())); 
          iluObjectWrapper _outarg(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord()); 

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _inarg;
                 _surrogate_call += _inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _inarg;
              _surrogate_call << _inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 
         _surrogate_call >> _inoutarg; 
         _surrogate_call >> _outarg; 

      inoutarg = (foo_bar_ptr)_inoutarg.m_pv_iluobject;
      outarg = (foo_bar_ptr)_outarg.m_pv_iluobject;
    
      return  (foo_bar_ptr)_return_value.m_pv_iluobject;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_enumtype 
foo_surrogate_bar::
passenum (
          foo_enumtype  inarg,
          foo_enumtype&  inoutarg,
          foo_enumtype&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_enumtype       return_value;    
          iluEnumWrapper        _return_value((iluDummyEnum &) return_value);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluEnumWrapper        _inarg((iluDummyEnum &) inarg);
          iluEnumWrapper        _inoutarg((iluDummyEnum &) inoutarg);
          iluEnumWrapper        _outarg((iluDummyEnum &) outarg);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _inarg;
                 _surrogate_call += _inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _inarg;
              _surrogate_call << _inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 
         _surrogate_call >> _inoutarg; 
         _surrogate_call >> _outarg; 


          return return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


iluShortCharacter* 
foo_surrogate_bar::
passlatinstring (
          foo_const_LatinString    inarg,
          iluShortCharacter*&  inoutarg,
          iluShortCharacter*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 3, this, foo_bar::iluGetILUClassRecord());

        try {
          iluShortCharacter*       return_value;
          iluCardinal       return_length;
          iluCStringWrapper   _return_value(return_value, return_length);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       inarg_length =
                  strlen(inarg);
          iluCStringWrapper _inarg(inarg, inarg_length);
          iluCardinal       inoutarg_length = strlen(inoutarg);
          iluCStringWrapper _inoutarg(inoutarg, inoutarg_length,
                             ILUCPP_DELETE_ON_INPUT);
          iluCardinal         outarg_length;
          iluCStringWrapper     _outarg(outarg, outarg_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _inarg;
                 _surrogate_call += _inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _inarg;
              _surrogate_call << _inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 
         _surrogate_call >> _inoutarg; 
         _surrogate_call >> _outarg; 


          return return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


iluCharacter* 
foo_surrogate_bar::
passunicodestring (
          foo_const_UnicodeString    inarg,
          iluCharacter*&  inoutarg,
          iluCharacter*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 4, this, foo_bar::iluGetILUClassRecord());

        try {
          iluCharacter*       return_value;
          iluCardinal       return_length;
          iluWStringWrapper   _return_value(return_value, return_length);
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal      inarg_length =
                    iluCppRuntime::iluCharacterStringLength(inarg);
          iluWStringWrapper _inarg( inarg, inarg_length);
          iluCardinal       inoutarg_length = 
                    iluCppRuntime::iluCharacterStringLength(inoutarg);
          iluWStringWrapper _inoutarg(inoutarg, inoutarg_length,
                     ILUCPP_DELETE_ON_INPUT);
          iluCardinal         outarg_length;
          iluWStringWrapper     _outarg(outarg, outarg_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _inarg;
                 _surrogate_call += _inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _inarg;
              _surrogate_call << _inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> _return_value; 
         _surrogate_call >> _inoutarg; 
         _surrogate_call >> _outarg; 


          return return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_fixedrecordtype 
foo_surrogate_bar::
passfixedrecord (
          const foo_fixedrecordtype&  inarg,
          foo_fixedrecordtype&  inoutarg,
          foo_fixedrecordtype&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 5, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_fixedrecordtype       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> return_value; 
         _surrogate_call >> inoutarg; 
         _surrogate_call >> outarg; 


          return return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_variablerecordtype* 
foo_surrogate_bar::
passvariablerecord (
          const foo_variablerecordtype&  inarg,
          foo_variablerecordtype&  inoutarg,
          foo_variablerecordtype*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 6, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_variablerecordtype*  p_return_value = new(foo_variablerecordtype);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg =  new foo_variablerecordtype;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> inoutarg; 
         _surrogate_call >> *outarg; 

         inarg.iluSurrogateSideCleanup(); 
         inoutarg.iluSurrogateSideCleanup(); 
         outarg->iluSurrogateSideCleanup(); 
         p_return_value->iluSurrogateSideCleanup(); 

          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_integerarray_slice* 
foo_surrogate_bar::
passfixedarray (
          const foo_integerarray  inarg,
          foo_integerarray  inoutarg,
          foo_integerarray  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 7, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_integerarray_slice*  p_return_value = foo_integerarray_alloc();   
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                foo_size_const_integerarray(
                        _surrogate_call, inarg);
                foo_size_integerarray(
                        _surrogate_call, inoutarg);

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
                foo_output_const_integerarray(
                      _surrogate_call, inarg);
                foo_output_integerarray(
                      _surrogate_call, inoutarg);
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         foo_input_integerarray(_surrogate_call, p_return_value);
         foo_input_integerarray(_surrogate_call, inoutarg);
         foo_input_integerarray(_surrogate_call, outarg);


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_bararray_slice* 
foo_surrogate_bar::
passvariablearray (
          const foo_bararray  inarg,
          foo_bararray  inoutarg,
          foo_bararray_slice*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 8, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_bararray_slice*  p_return_value = foo_bararray_alloc();   
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg = foo_bararray_alloc();

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                foo_size_const_bararray(
                        _surrogate_call, inarg);
                foo_size_bararray(
                        _surrogate_call, inoutarg);

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
                foo_output_const_bararray(
                      _surrogate_call, inarg);
                foo_output_bararray(
                      _surrogate_call, inoutarg);
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         foo_input_bararray(_surrogate_call, p_return_value);
         foo_input_bararray(_surrogate_call, inoutarg);
         foo_input_bararray(_surrogate_call, outarg);

          foo_const_bararray_iluSurrogateSideCleanup(inarg);
          foo_bararray_iluSurrogateSideCleanup(inoutarg);
          foo_bararray_iluSurrogateSideCleanup(outarg);
          foo_bararray_iluSurrogateSideCleanup(p_return_value);

          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_unboundedlongseq* 
foo_surrogate_bar::
passunboundedsequence (
          const foo_unboundedlongseq&  inarg,
          foo_unboundedlongseq&  inoutarg,
          foo_unboundedlongseq*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 9, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_unboundedlongseq*  p_return_value = new(foo_unboundedlongseq);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg =  new foo_unboundedlongseq;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> inoutarg; 
         _surrogate_call >> *outarg; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_boundedbarseq* 
foo_surrogate_bar::
passboundedsequence (
          const foo_boundedbarseq&  inarg,
          foo_boundedbarseq&  inoutarg,
          foo_boundedbarseq*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 10, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_boundedbarseq*  p_return_value = new(foo_boundedbarseq);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg =  new foo_boundedbarseq;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> inoutarg; 
         _surrogate_call >> *outarg; 

         inarg.iluSurrogateSideCleanup(); 
         inoutarg.iluSurrogateSideCleanup(); 
         outarg->iluSurrogateSideCleanup(); 
         p_return_value->iluSurrogateSideCleanup(); 

          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_variableuniontype* 
foo_surrogate_bar::
passvariableunion (
          const foo_variableuniontype&  inarg,
          foo_variableuniontype&  inoutarg,
          foo_variableuniontype*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 11, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_variableuniontype*  p_return_value = new(foo_variableuniontype);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg =  new foo_variableuniontype;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> inoutarg; 
         _surrogate_call >> *outarg; 

         inarg.iluSurrogateSideCleanup(); 
         inoutarg.iluSurrogateSideCleanup(); 
         outarg->iluSurrogateSideCleanup(); 
         p_return_value->iluSurrogateSideCleanup(); 

          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


foo_optionalinteger 
foo_surrogate_bar::
passoptionals (
          foo_const_optionalinteger    inarg,
          foo_optionalbarobject&  inoutarg,
          foo_optionalbarobject&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 12, this, foo_bar::iluGetILUClassRecord());

        try {
          foo_optionalinteger      p_return_value;  
          iluOptionalWrapper  o_return_value;
          CORBA_Long       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluOptionalWrapper   o_inarg(CONST_CAST(foo_optionalinteger, inarg));
          iluOptionalWrapper   o_inoutarg(inoutarg);
          iluObjectWrapper _inoutarg(inoutarg, ILUCPP_FALSE, ( inoutarg ? ILUCPP_NULL : foo_bar::iluGetILUClassRecord())); 
          iluOptionalWrapper   o_outarg(outarg);
          iluObjectWrapper _outarg(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord()); 

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                _surrogate_call += o_inarg; 
                if(o_inarg.m_present)
                   _surrogate_call += *inarg;
                _surrogate_call += o_inoutarg; 
                if(o_inoutarg.m_present)
                   _surrogate_call += _inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
               _surrogate_call << o_inarg; 
               if(o_inarg.m_present)
                  _surrogate_call << *inarg;
               _surrogate_call << o_inoutarg; 
               if(o_inoutarg.m_present)
                  _surrogate_call << _inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> o_return_value; 
         if(o_return_value.m_present) {
              p_return_value = new CORBA_Long;
             _surrogate_call >> *p_return_value; 
         }
         else p_return_value = ILUCPP_NULL;
         _surrogate_call >> o_inoutarg; 
         if(o_inoutarg.m_present) {
              _surrogate_call >> _inoutarg;
              inoutarg = (foo_bar_ptr) _inoutarg.m_pv_iluobject;
         }
         else inoutarg = ILUCPP_NULL;
         _surrogate_call >> o_outarg; 
         if(o_outarg.m_present) {
              _surrogate_call >> _outarg;
              outarg = (foo_bar_ptr) _outarg.m_pv_iluobject;
         }
         else outarg = ILUCPP_NULL;


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA_Any* 
foo_surrogate_bar::
passsimpleanys (
          const CORBA_Any&  inarg,
          CORBA_Any&  inoutarg,
          CORBA_Any*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 13, this, foo_bar::iluGetILUClassRecord());

        try {
          CORBA_Any*  p_return_value = new(CORBA_Any);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg =  new CORBA_Any;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> inoutarg; 
              outarg = new CORBA_Any;
         _surrogate_call >> *outarg; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA_Any* 
foo_surrogate_bar::
passarrayanys (
          const CORBA_Any&  inarg,
          CORBA_Any&  inoutarg,
          CORBA_Any*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 14, this, foo_bar::iluGetILUClassRecord());

        try {
          CORBA_Any*  p_return_value = new(CORBA_Any);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg =  new CORBA_Any;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> inoutarg; 
              outarg = new CORBA_Any;
         _surrogate_call >> *outarg; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


CORBA_Any* 
foo_surrogate_bar::
passassortedanys (
          const CORBA_Any&  inarg,
          CORBA_Any&  inoutarg,
          CORBA_Any*&  outarg
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 15, this, foo_bar::iluGetILUClassRecord());

        try {
          CORBA_Any*  p_return_value = new(CORBA_Any);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          outarg =  new CORBA_Any;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += inarg;
                 _surrogate_call += inoutarg;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << inarg;
              _surrogate_call << inoutarg;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> inoutarg; 
              outarg = new CORBA_Any;
         _surrogate_call >> *outarg; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}

/////////////////////////////////////////////////////////////////////////////

// Initialize to use foo_bar objects

void
foo_surrogate_bar::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                foo_bar::iluGetILUClassRecord(),
                foo_surrogate_bar::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
         iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a foo_bar surrogate
 
iluObject*
foo_surrogate_bar::
create_surrogate (iluKernelObject _kernel_object) {
        foo_bar* _new_object = new foo_surrogate_bar();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of foo_bar class upon load
 
foo_surrogate_bar_initializer::
foo_surrogate_bar_initializer () {
        ensure_instantiation();
}
 
void *
foo_surrogate_bar_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &foo_p_initialization_function_list,
                foo_surrogate_bar::iluInitialize);
        return this;
}
