
// This file was automatically generated with KISORB (version 2.0beta1) tools
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information:  Dr. Wang at xcwang89@aliyun.com 

#include "Test1-cpptrue.hpp"

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

static void _send_Test1_E2(
       iluTrueCall &_true_call, Test1_E2& _exception, iluCardinal exi)
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E2");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_CantCreate(
       iluTrueCall &_true_call, Test1_CantCreate& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
           // Send Reply
                 _true_call << iluSendExceptionMode;
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_CantCreate");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E3(
       iluTrueCall &_true_call, Test1_E3& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
         {
          iluOptionalWrapper _m_value_opt_wrap;
          _m_value_opt_wrap.m_present =
              !(_exception._m_value.iluIsNull());
          _true_call += _m_value_opt_wrap;
          if(_m_value_opt_wrap.m_present) {
                 _true_call += _exception._m_value->self();
        }
         }
           // Send Reply
                 _true_call << iluSendExceptionMode;
         {
          iluOptionalWrapper _m_value_opt_wrap;
          _m_value_opt_wrap.m_present =
              !(_exception._m_value.iluIsNull());
          _true_call << _m_value_opt_wrap;
          if(_m_value_opt_wrap.m_present) {
                 _true_call << _exception._m_value->self();
        }
         }
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E3");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E4(
       iluTrueCall &_true_call, Test1_E4& _exception, iluCardinal exi)
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E4");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E5(
       iluTrueCall &_true_call, Test1_E5& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
         {
                Test1_size_A0(_true_call, &_exception._m_value[0]);
         }
           // Send Reply
                 _true_call << iluSendExceptionMode;
         {
                Test1_output_A0(_true_call, &_exception._m_value[0]);
         }
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E5");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E6(
       iluTrueCall &_true_call, Test1_E6& _exception, iluCardinal exi)
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E6");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E7(
       iluTrueCall &_true_call, Test1_E7& _exception, iluCardinal exi)
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E7");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E8(
       iluTrueCall &_true_call, Test1_E8& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
         {
                Test1_size_TheA1(_true_call, &_exception._m_value[0]);
         }
           // Send Reply
                 _true_call << iluSendExceptionMode;
         {
                Test1_output_TheA1(_true_call, &_exception._m_value[0]);
         }
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E8");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_Test1_E9(
       iluTrueCall &_true_call, Test1_E9& _exception, iluCardinal exi)
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_Test1_E9");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

// Globals and statics 

int Test1_true_O3_initializer::initialized; 
Test1_true_O3_initializer
     Test1_true_O3_initializer::sm_the_true_Test1_O3_initializer;
// Method Stubs

static void Test1_O3_RS_R_to_R_IS_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test1_O3_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_O3::iluGetILUClassRecord());
             Test1_IS*   p_return_value;
             Test1_TheRS    r;      
             Test1_TheR*   p_r2;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_O3_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  r;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->RS_R_to_R_IS(
                  r,
                  p_r2
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call += *p_r2;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call << *p_r2;      
             delete p_r2; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_O3_RS_R_to_R_IS");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_O3_O1_U_to_U_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             Test1_O3_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_O3::iluGetILUClassRecord());
             iluObjectWrapper _o_wr(ILUCPP_FALSE, Test1_TheO1::iluGetILUClassRecord()); 
             Test1_TheU    u;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_O3_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _o_wr;
             _true_call >>  u;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
              _true_object->O1_U_to_U(
                  (Test1_TheO1_ptr) _o_wr.m_pv_iluobject,
                  u
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call +=  u;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  u;
      }
    catch(Test1_E2& _exception) {
          _send_Test1_E2(_true_call, _exception, 0);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_O3_O1_U_to_U");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_O3_BS_to_I_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test1_O3_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_O3::iluGetILUClassRecord());
             CORBA_Long    return_value;      
             Test1_BS    b;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_O3_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  b;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->BS_to_I(
                  b
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_O3_BS_to_I");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

Test1_true_O3_initializer::
Test1_true_O3_initializer () {
             ensure_instantiation();
}

void *
Test1_true_O3_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
Test1_true_O3_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                Test1_O3::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, Test1_O3_RS_R_to_R_IS_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_O3::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, Test1_O3_O1_U_to_U_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_O3::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, Test1_O3_BS_to_I_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        //  iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}

// Globals and statics 

int Test1_true_TheO1_initializer::initialized; 
Test1_true_TheO1_initializer
     Test1_true_TheO1_initializer::sm_the_true_Test1_TheO1_initializer;
// Method Stubs

static void Test1_TheO1_U_CSS_to_U_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             Test1_TheO1_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_TheO1::iluGetILUClassRecord());
             Test1_TheU*   p_return_value;
             Test1_TheU    u;      
             Test1_CSS    css;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_TheO1_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  u;
             _true_call >>  css;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->U_CSS_to_U(
                  u,
                  css
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
    catch(Test1_E1& _exception) {
          _send_Test1_E1(_true_call, _exception, 0);
    }
    catch(Test1_E2& _exception) {
          _send_Test1_E2(_true_call, _exception, 1);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_TheO1_U_CSS_to_U");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_TheO1_f_CSS_to_RO_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             Test1_TheO1_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_TheO1::iluGetILUClassRecord());

             Test1_RO    opt_return_value  = ILUCPP_NULL;
             iluOptionalWrapper   _opt_wrap_return_value;
             Test1_TheR*   p_return_value;
             Test1_CSS    css;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_TheO1_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  css;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             opt_return_value  = _true_object->f_CSS_to_RO(
                  css
              );


             _opt_wrap_return_value.iluSetFrom(opt_return_value);
         p_return_value = opt_return_value;

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      

             _true_call +=  _opt_wrap_return_value;
             if(_opt_wrap_return_value.m_present) {
             _true_call += *p_return_value;      
             }
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      

             _true_call <<  _opt_wrap_return_value;
             if(_opt_wrap_return_value.m_present) {
             _true_call << *p_return_value;      
             delete p_return_value; 
             }
      }
    catch(Test1_E1& _exception) {
          _send_Test1_E1(_true_call, _exception, 0);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_TheO1_f_CSS_to_RO");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_TheO1_R_ScS_to_F_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test1_TheO1_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_TheO1::iluGetILUClassRecord());
             CORBA_Float    return_value;      
             Test1_TheR    r;      
             iluCardinal       _s_length;
             iluShortCharacter*          s = ILUCPP_NULL;
             iluCStringWrapper _s_wr(s, _s_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_TheO1_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  r;
             _true_call >> _s_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->R_ScS_to_F(
                  r,
                 (iluShortCharacter*) _s_wr.m_r_cstring
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_TheO1_R_ScS_to_F");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_TheO1_a_RO_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test1_TheO1_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_TheO1::iluGetILUClassRecord());

             Test1_RO    opt_ro  = ILUCPP_NULL;
             iluOptionalWrapper   _opt_wrap_ro;
             Test1_TheR    ro;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_TheO1_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments

             _true_call >>  _opt_wrap_ro;
             if(_opt_wrap_ro.m_present) {
             _true_call >>  ro;
          opt_ro = &ro;
             }
             else opt_ro = ILUCPP_NULL;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
              _true_object->a_RO(
                        opt_ro
              );


             _opt_wrap_ro.iluSetFrom(opt_ro);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_TheO1_a_RO");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_TheO1_get_O2_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             Test1_TheO1_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_TheO1::iluGetILUClassRecord());
             Test1_O2_ptr   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_TheO1_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->get_O2(
              );

             iluObjectWrapper _return_value_wr(*p_return_value, ILUCPP_FALSE);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
    catch(Test1_CantCreate& _exception) {
          _send_Test1_CantCreate(_true_call, _exception, 0);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_TheO1_get_O2");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_TheO1_get_O3_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             Test1_TheO1_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_TheO1::iluGetILUClassRecord());
             Test1_O3_ptr   p_return_value;
             CORBA_Boolean        subclass;    
             iluBoolWrapper    _subclass_wr(subclass);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_TheO1_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _subclass_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->get_O3(
                    (CORBA_Boolean) _subclass_wr.m_r_bool 
              );

             iluObjectWrapper _return_value_wr(*p_return_value, ILUCPP_FALSE);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
    catch(Test1_CantCreate& _exception) {
          _send_Test1_CantCreate(_true_call, _exception, 0);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_TheO1_get_O3");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

Test1_true_TheO1_initializer::
Test1_true_TheO1_initializer () {
             ensure_instantiation();
}

void *
Test1_true_TheO1_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
Test1_true_TheO1_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                Test1_TheO1::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, Test1_TheO1_U_CSS_to_U_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_TheO1::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, Test1_TheO1_f_CSS_to_RO_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_TheO1::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, Test1_TheO1_R_ScS_to_F_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_TheO1::iluGetILUClassRecord()->cl_methods + 3,
                REINTERPRET_CAST(ilu_StubProc, Test1_TheO1_a_RO_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_TheO1::iluGetILUClassRecord()->cl_methods + 4,
                REINTERPRET_CAST(ilu_StubProc, Test1_TheO1_get_O2_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_TheO1::iluGetILUClassRecord()->cl_methods + 5,
                REINTERPRET_CAST(ilu_StubProc, Test1_TheO1_get_O3_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}

// Globals and statics 

int Test1_true_O2_initializer::initialized; 
Test1_true_O2_initializer
     Test1_true_O2_initializer::sm_the_true_Test1_O2_initializer;
// Method Stubs

static void Test1_O2_OO_A0_to_CSS_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             Test1_O2_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_O2::iluGetILUClassRecord());
             Test1_CSS*   p_return_value;

             Test1_TheOO    opt_o  = ILUCPP_NULL;
             iluOptionalWrapper   _opt_wrap_o;
             iluObjectWrapper _o_wr(ILUCPP_FALSE, Test1_TheO1::iluGetILUClassRecord()); 
              Test1_A0_slice* a_slice = Test1_A0_alloc();

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_O2_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments

             _true_call >>  _opt_wrap_o;
             if(_opt_wrap_o.m_present) {
             _true_call >> _o_wr;
             opt_o = 
                  (Test1_TheO1_ptr) _o_wr.m_pv_iluobject;
             }
             else opt_o = ILUCPP_NULL;
              Test1_input_A0(_true_call, a_slice); 
              // make up var to take care of memory management
              // and allow appropriate conversion for the inarg slice
              Test1_A0_var    a_var(a_slice); 

             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->OO_A0_to_CSS(
                        opt_o,
                   a_slice
              );


             _opt_wrap_o.iluSetFrom(opt_o);

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
    catch(Test1_E2& _exception) {
          _send_Test1_E2(_true_call, _exception, 0);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_O2_OO_A0_to_CSS");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void Test1_O2_R_I_A1_to_I_A0_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test1_O2_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_O2::iluGetILUClassRecord());
              Test1_A0_var   return_value_var;
             Test1_TheR    r;      
             CORBA_Long    i;      
              Test1_TheA1_slice* a_slice = Test1_TheA1_alloc();

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_O2_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  r;
             _true_call >>  i;
              Test1_input_TheA1(_true_call, a_slice); 
              // make up var to take care of memory management
              // and allow appropriate conversion for the inarg slice
              Test1_TheA1_var    a_var(a_slice); 

             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
              return_value_var = 
            _true_object->R_I_A1_to_I_A0(
                  r,
                  i,
                   a_slice
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
                    Test1_size_const_A0(_true_call, return_value_var.in());
             _true_call +=  i;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
                    Test1_output_const_A0(_true_call, return_value_var.in());
             _true_call <<  i;
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_O2_R_I_A1_to_I_A0");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

Test1_true_O2_initializer::
Test1_true_O2_initializer () {
             ensure_instantiation();
}

void *
Test1_true_O2_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
Test1_true_O2_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                Test1_O2::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, Test1_O2_OO_A0_to_CSS_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                Test1_O2::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, Test1_O2_R_I_A1_to_I_A0_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}

// Globals and statics 

int Test1_true_O4_initializer::initialized; 
Test1_true_O4_initializer
     Test1_true_O4_initializer::sm_the_true_Test1_O4_initializer;
// Method Stubs

static void Test1_O4_R_to_R_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test1_O4_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_O4::iluGetILUClassRecord());
             CORBA_Double    return_value;      
             CORBA_Double    r;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_O4_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  r;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->R_to_R(
                  r
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_O4_R_to_R");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

Test1_true_O4_initializer::
Test1_true_O4_initializer () {
             ensure_instantiation();
}

void *
Test1_true_O4_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
Test1_true_O4_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                Test1_O4::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, Test1_O4_R_to_R_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}

// Globals and statics 

int Test1_true_P_initializer::initialized; 
Test1_true_P_initializer
     Test1_true_P_initializer::sm_the_true_Test1_P_initializer;
// Method Stubs

static void Test1_P_m2_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             Test1_P_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   Test1_P::iluGetILUClassRecord());
             Test1_IS*   p_return_value;
             CORBA_Long    j;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (Test1_P_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  j;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->m2(
                  j
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
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("Test1_P_m2");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

Test1_true_P_initializer::
Test1_true_P_initializer () {
             ensure_instantiation();
}

void *
Test1_true_P_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
Test1_true_P_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                Test1_P::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, Test1_P_m2_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
