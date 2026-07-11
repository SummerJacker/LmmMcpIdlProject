
// This file was automatically generated with  KIS-CORBA (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
// KIS-CORBA information:  http://www.kestrelsystems.ca.

#include "Test3-cpptrue.hpp"

static void _send_Test3_E1(
       iluTrueCall &_true_call, Test3_E1& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
         {
          iluCardinal       _m_value_length =
               strlen(_exception._m_value.iluStringVarReference());
          iluCStringWrapper  _m_value_wrap(
                 _exception._m_value.iluStringVarReference(),
                 _m_value_length);
                   _true_call += _m_value_wrap;
         }
           // Send Reply
                 _true_call << iluSendExceptionMode;
         {
          iluCardinal       _m_value_length =
               strlen(_exception._m_value.iluStringVarReference());
          iluCStringWrapper  _m_value_wrap(
                 _exception._m_value.iluStringVarReference(),
                 _m_value_length);
                   _true_call << _m_value_wrap;
         }
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test3_E1");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E1(
       iluTrueCall &_true_call, Test1_E1& _exception, iluCardinal exi)
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E1");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

// Globals and statics 

int Test3_true_O_initializer::initialized; 
Test3_true_O_initializer
     Test3_true_O_initializer::sm_the_true_Test3_O_initializer;
// Method Stubs

static void Test3_O_I_to_Test1U_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             Test3_O_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test3_O::iluGetILUClassRecord());
             Test1_TheU*   p_return_value;
             CORBA_Long    i;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test3_O_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  i;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->I_to_Test1U(
                  i
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
      }
    catch(Test3_E1& _exception) {
          _send_Test3_E1(_true_call, _exception, 0);
    }
    catch(Test1_E1& _exception) {
          _send_Test1_E1(_true_call, _exception, 1);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test3_O_I_to_Test1U");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

Test3_true_O_initializer::
Test3_true_O_initializer () {
             ensure_instantiation();
}

void *
Test3_true_O_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test3_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
Test3_true_O_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                Test3_O::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, Test3_O_I_to_Test1U_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
