
// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

#include "Test2-cppsurrogate.hpp"

// Static class initialization

Test2_surrogate_P_initializer
     Test2_surrogate_P_initializer::sm_the_surrogate_Test2_P_initializer;
int Test2_surrogate_P::_initialized; 

// Test2_P surrogate methods 


CORBA_Long 
Test2_surrogate_P::
SR_to_I (
          CORBA_Float  i
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, Test2_P::iluGetILUClassRecord());

        try {
          CORBA_Long       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += i;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << i;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> return_value; 


          return return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}

/////////////////////////////////////////////////////////////////////////////

// Initialize to use Test2_P objects

void
Test2_surrogate_P::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                Test2_P::iluGetILUClassRecord(),
                Test2_surrogate_P::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a Test2_P surrogate
 
iluObject*
Test2_surrogate_P::
create_surrogate (iluKernelObject _kernel_object) {
        Test2_P* _new_object = new Test2_surrogate_P();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of Test2_P class upon load
 
Test2_surrogate_P_initializer::
Test2_surrogate_P_initializer () {
        ensure_instantiation();
}
 
void *
Test2_surrogate_P_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test2_p_initialization_function_list,
                Test2_surrogate_P::iluInitialize);
        return this;
}
