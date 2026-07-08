
// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

#include "Test3-cppsurrogate.hpp"

// Static class initialization

Test3_surrogate_O_initializer
     Test3_surrogate_O_initializer::sm_the_surrogate_Test3_O_initializer;
int Test3_surrogate_O::_initialized; 

// Test3_O surrogate methods 


Test2_T1U* 
Test3_surrogate_O::
I_to_Test1U (
          CORBA_Long  i
         ) throw (CORBA_SystemException, Test3_E1, Test1_E1) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, Test3_O::iluGetILUClassRecord());

        try {
          Test2_T1U*  p_return_value = new(Test2_T1U);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;

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

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_I_to_Test1U_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> *p_return_value; 

         p_return_value->iluSurrogateSideCleanup(); 

          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test3_surrogate_O::
_throw_I_to_Test1U_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, Test3_E1, Test1_E1) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        Test3_E1 _exception;
                          iluCardinal         _m_value_length;
                          iluCStringWrapper  _m_value_wrap( 
                               _exception._m_value.iluStringVarReference(),
                               _m_value_length);
                           _call >> _m_value_wrap;
                        throw(_exception);
                      };

                case 1: {
                        Test1_E1 _exception;
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

/////////////////////////////////////////////////////////////////////////////

// Initialize to use Test3_O objects

void
Test3_surrogate_O::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                Test3_O::iluGetILUClassRecord(),
                Test3_surrogate_O::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a Test3_O surrogate
 
iluObject*
Test3_surrogate_O::
create_surrogate (iluKernelObject _kernel_object) {
        Test3_O* _new_object = new Test3_surrogate_O();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of Test3_O class upon load
 
Test3_surrogate_O_initializer::
Test3_surrogate_O_initializer () {
        ensure_instantiation();
}
 
void *
Test3_surrogate_O_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test3_p_initialization_function_list,
                Test3_surrogate_O::iluInitialize);
        return this;
}
