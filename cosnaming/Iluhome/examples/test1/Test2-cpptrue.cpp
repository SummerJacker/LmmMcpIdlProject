
// This file was automatically generated with KISORB (version 2.0beta1) tools
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information:  Dr. Wang at xcwang89@aliyun.com 

#include "Test2-cpptrue.hpp"

static void _send_Test2_E1(
       iluTrueCall &_true_call, Test2_E1& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
         {
                 _true_call += _exception._m_value;
         }
           // Send Reply
                 _true_call << iluSendExceptionMode;
         {
                 _true_call << _exception._m_value;
         }
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test2_E1");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

// Globals and statics 

int Test2_true_P_initializer::initialized; 
Test2_true_P_initializer
     Test2_true_P_initializer::sm_the_true_Test2_P_initializer;
// Method Stubs

static void Test2_P_SR_to_I_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test2_P_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test2_P::iluGetILUClassRecord());
             CORBA_Long    return_value;      
             CORBA_Float    i;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test2_P_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  i;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->SR_to_I(
                  i
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test2_P_SR_to_I");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

Test2_true_P_initializer::
Test2_true_P_initializer () {
             ensure_instantiation();
}

void *
Test2_true_P_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test2_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
Test2_true_P_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                Test2_P::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, Test2_P_SR_to_I_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
