
// This file was automatically generated with KISORB (version 2.0beta1) tools
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information:  Dr. Wang at xcwang89@aliyun.com 

#include "foo-cpptrue.hpp"

static void _send_foo_zapexception(
       iluTrueCall &_true_call, foo_zapexception& _exception, iluCardinal exi)
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
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_foo_zapexception");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

// Globals and statics 

int foo_true_bar_initializer::initialized; 
foo_true_bar_initializer
     foo_true_bar_initializer::sm_the_true_foo_bar_initializer;
// Method Stubs

static void foo_bar_zap_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             CORBA_Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             CORBA_Long    inarg;      
             CORBA_Octet    inoutarg;      
             CORBA_Double    outarg;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->zap(
                  inarg,
                  inoutarg,
                  outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             _true_call +=  inoutarg;
             _true_call +=  outarg;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
             _true_call <<  inoutarg;
             _true_call <<  outarg;
      }
    catch(foo_zapexception& _exception) {
          _send_foo_zapexception(_true_call, _exception, 0);
    }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_zap");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passobj_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             foo_bar_ptr   p_return_value;
             iluObjectWrapper _inarg_wr(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord()); 
             iluObjectWrapper _inoutarg_wr(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord()); 
             foo_bar_ptr   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _inarg_wr;
             _true_call >> _inoutarg_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passobj(
                  (foo_bar_ptr) _inarg_wr.m_pv_iluobject,
                  (foo_bar_ptr&) _inoutarg_wr.m_pv_iluobject,
                  p_outarg
              );


             _inoutarg_wr.iluReviseForObject(
                 (foo_bar_ptr) _inoutarg_wr.m_pv_iluobject);
             iluObjectWrapper _return_value_wr(*p_return_value, ILUCPP_FALSE);
             iluObjectWrapper _outarg_wr(*p_outarg, ILUCPP_FALSE);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             _true_call += _inoutarg_wr;
             _true_call += _outarg_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
             _true_call << _inoutarg_wr;
             _true_call << _outarg_wr;
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passobj");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passenum_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             foo_enumtype            return_value;    
             iluEnumWrapper       _return_value_wr( (iluDummyEnum &) return_value);
             foo_enumtype            inarg;    
             iluEnumWrapper       _inarg_wr( (iluDummyEnum &) inarg);
             foo_enumtype            inoutarg;    
             iluEnumWrapper       _inoutarg_wr( (iluDummyEnum &) inoutarg);
             foo_enumtype            outarg;    
             iluEnumWrapper       _outarg_wr( (iluDummyEnum &) outarg);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _inarg_wr;
             _true_call >> _inoutarg_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 

             // Note on G++ workaround  ..
             // use void * trickery to work around G++'s (2.7.2) problems
             // with enum casting.  This approach should work everywhere
             // else, so we may just want to do this for the general case.

             return_value  = _true_object->passenum(
                    (foo_enumtype) _inarg_wr.m_r_enum, 

#ifdef OLDGNUC_WORKAROUND
                    *((foo_enumtype*)((void*)(&(_inoutarg_wr.m_r_enum)))), 
#else
                    (foo_enumtype&) _inoutarg_wr.m_r_enum, 
#endif
#ifdef OLDGNUC_WORKAROUND
                    *((foo_enumtype*)((void*)(&(_outarg_wr.m_r_enum)))) 
#else
                    (foo_enumtype&) _outarg_wr.m_r_enum 
#endif
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             _true_call += _inoutarg_wr;
             _true_call += _outarg_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
             _true_call << _inoutarg_wr;
             _true_call << _outarg_wr;
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passenum");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passlatinstring_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             iluCardinal       _return_value_length;
             iluShortCharacter*          return_value = ILUCPP_NULL;
             iluCStringWrapper _return_value_wr(return_value, _return_value_length);
             iluCardinal       _inarg_length;
             iluShortCharacter*          inarg = ILUCPP_NULL;
             iluCStringWrapper _inarg_wr(inarg, _inarg_length);
             iluCardinal       _inoutarg_length;
             iluShortCharacter*          inoutarg = ILUCPP_NULL;
             iluCStringWrapper _inoutarg_wr(inoutarg, _inoutarg_length);
             iluCardinal       _outarg_length;
             iluShortCharacter*          outarg = ILUCPP_NULL;
             iluCStringWrapper _outarg_wr(outarg, _outarg_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _inarg_wr;
             _true_call >> _inoutarg_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             return_value  = _true_object->passlatinstring(
                 (iluShortCharacter*) _inarg_wr.m_r_cstring,
                 (iluShortCharacter*&) _inoutarg_wr.m_r_cstring,
                 (iluShortCharacter*&) _outarg_wr.m_r_cstring
              );

            _return_value_wr.m_r_cstring = return_value;
            _return_value_wr.m_r_card_length =
                    strlen(_return_value_wr.m_r_cstring);
            _inoutarg_wr.m_r_card_length = 
                   strlen(_inoutarg_wr.m_r_cstring);
            _outarg_wr.m_r_card_length = 
                   strlen(_outarg_wr.m_r_cstring);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             _true_call += _inoutarg_wr;
             _true_call += _outarg_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
             _true_call << _inoutarg_wr;
             _true_call << _outarg_wr;
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passlatinstring");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passunicodestring_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             iluCardinal        _return_value_length;
             iluCharacter*         return_value;
             iluWStringWrapper  _return_value_wr(return_value, _return_value_length,
                                      ILUCPP_DELETE_ON_DESTRUCT);
             iluCardinal        _inarg_length;
             iluCharacter*         inarg;
             iluWStringWrapper  _inarg_wr(inarg, _inarg_length,
                                      ILUCPP_DELETE_ON_DESTRUCT);
             iluCardinal        _inoutarg_length;
             iluCharacter*         inoutarg;
             iluWStringWrapper  _inoutarg_wr(inoutarg, _inoutarg_length,
                                      ILUCPP_DELETE_ON_DESTRUCT);
             iluCardinal        _outarg_length;
             iluCharacter*         outarg;
             iluWStringWrapper  _outarg_wr(outarg, _outarg_length,
                                      ILUCPP_DELETE_ON_DESTRUCT);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _inarg_wr;
             _true_call >> _inoutarg_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             return_value  = _true_object->passunicodestring(
                 (iluCharacter*) _inarg_wr.m_r_wstring,
                 (iluCharacter*&) _inoutarg_wr.m_r_wstring,
                 (iluCharacter*&) _outarg_wr.m_r_wstring
              );

          _return_value_wr.m_r_wstring = return_value;
          _return_value_wr.m_r_card_length = 
                   iluCppRuntime::iluCharacterStringLength(
                                       _return_value_wr.m_r_wstring);
           _inoutarg_wr.m_r_card_length = 
                   iluCppRuntime::iluCharacterStringLength(
                                       _inoutarg_wr.m_r_wstring);
           _outarg_wr.m_r_card_length = 
                   iluCppRuntime::iluCharacterStringLength(
                                       _outarg_wr.m_r_wstring);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
             _true_call += _inoutarg_wr;
             _true_call += _outarg_wr;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
             _true_call << _inoutarg_wr;
             _true_call << _outarg_wr;
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passunicodestring");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passfixedrecord_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             foo_fixedrecordtype    return_value;      
             foo_fixedrecordtype    inarg;      
             foo_fixedrecordtype    inoutarg;      
             foo_fixedrecordtype    outarg;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->passfixedrecord(
                  inarg,
                  inoutarg,
                  outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
             _true_call +=  inoutarg;
             _true_call +=  outarg;
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
             _true_call <<  inoutarg;
             _true_call <<  outarg;
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passfixedrecord");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passvariablerecord_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             foo_variablerecordtype*   p_return_value;
             foo_variablerecordtype    inarg;      
             foo_variablerecordtype    inoutarg;      
             foo_variablerecordtype*   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passvariablerecord(
                  inarg,
                  inoutarg,
                  p_outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call +=  inoutarg;
             _true_call += *p_outarg;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call <<  inoutarg;
             _true_call << *p_outarg;      
             delete p_outarg; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passvariablerecord");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passfixedarray_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
              foo_integerarray_var   return_value_var;
              foo_integerarray_slice* inarg_slice = foo_integerarray_alloc();
              foo_integerarray    inoutarg;
              foo_integerarray    outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
              foo_input_integerarray(_true_call, inarg_slice); 
              // make up var to take care of memory management
              // and allow appropriate conversion for the inarg slice
              foo_integerarray_var    inarg_var(inarg_slice); 

              foo_input_integerarray(_true_call, inoutarg);
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
              return_value_var = 
            _true_object->passfixedarray(
                   inarg_slice,
                    inoutarg, 
                    outarg 
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
                    foo_size_const_integerarray(_true_call, return_value_var.in());
                    foo_size_const_integerarray(_true_call, inoutarg);
                    foo_size_const_integerarray(_true_call, outarg);
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
                    foo_output_const_integerarray(_true_call, return_value_var.in());
                    foo_output_const_integerarray(_true_call, inoutarg);
                    foo_output_const_integerarray(_true_call, outarg);
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passfixedarray");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passvariablearray_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
              foo_bararray_var   return_value_var;
              foo_bararray_slice* inarg_slice = foo_bararray_alloc();
              foo_bararray_slice* inoutarg_slice = foo_bararray_alloc();
              foo_bararray_slice*    outarg_slice;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
              foo_input_bararray(_true_call, inarg_slice); 
              // make up var to take care of memory management
              // and allow appropriate conversion for the inarg slice
              foo_bararray_var    inarg_var(inarg_slice); 

              foo_input_bararray(_true_call, inoutarg_slice);
              // make up var to take care of memory management
              foo_bararray_var    inoutarg_var(inoutarg_slice);
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
              return_value_var = 
            _true_object->passvariablearray(
                   inarg_slice,
                    inoutarg_slice,
                    outarg_slice 
              );

              // make up var to take care of memory management 
              foo_bararray_var   outarg_var(outarg_slice);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
                    foo_size_const_bararray(_true_call, return_value_var.in());
                    foo_size_const_bararray(_true_call, inoutarg_var.in());
                    foo_size_const_bararray(_true_call, outarg_slice);
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
                    foo_output_const_bararray(_true_call, return_value_var.in());
                    foo_output_const_bararray(_true_call, inoutarg_var.in());
                    foo_output_const_bararray(_true_call, outarg_slice);
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passvariablearray");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passunboundedsequence_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             foo_unboundedlongseq*   p_return_value;
             foo_unboundedlongseq    inarg;      
             foo_unboundedlongseq    inoutarg;      
             foo_unboundedlongseq*   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passunboundedsequence(
                  inarg,
                  inoutarg,
                  p_outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call +=  inoutarg;
             _true_call += *p_outarg;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call <<  inoutarg;
             _true_call << *p_outarg;      
             delete p_outarg; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passunboundedsequence");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passboundedsequence_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             foo_boundedbarseq*   p_return_value;
             foo_boundedbarseq    inarg;      
             foo_boundedbarseq    inoutarg;      
             foo_boundedbarseq*   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passboundedsequence(
                  inarg,
                  inoutarg,
                  p_outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call +=  inoutarg;
             _true_call += *p_outarg;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call <<  inoutarg;
             _true_call << *p_outarg;      
             delete p_outarg; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passboundedsequence");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passvariableunion_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             foo_variableuniontype*   p_return_value;
             foo_variableuniontype    inarg;      
             foo_variableuniontype    inoutarg;      
             foo_variableuniontype*   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passvariableunion(
                  inarg,
                  inoutarg,
                  p_outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call +=  inoutarg;
             _true_call += *p_outarg;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call <<  inoutarg;
             _true_call << *p_outarg;      
             delete p_outarg; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passvariableunion");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passoptionals_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());

             foo_optionalinteger    opt_return_value  = ILUCPP_NULL;
             iluOptionalWrapper   _opt_wrap_return_value;
             CORBA_Long    return_value;      

             foo_optionalinteger    opt_inarg  = ILUCPP_NULL;
             iluOptionalWrapper   _opt_wrap_inarg;
             CORBA_Long    inarg;      

             foo_optionalbarobject    opt_inoutarg  = ILUCPP_NULL;
             iluOptionalWrapper   _opt_wrap_inoutarg;
             iluObjectWrapper _inoutarg_wr(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord()); 

             foo_optionalbarobject    opt_outarg  = ILUCPP_NULL;
             iluOptionalWrapper   _opt_wrap_outarg;
             foo_bar_ptr   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments

             _true_call >>  _opt_wrap_inarg;
             if(_opt_wrap_inarg.m_present) {
             _true_call >>  inarg;
             opt_inarg = &inarg;
             }
             else opt_inarg = ILUCPP_NULL;

             _true_call >>  _opt_wrap_inoutarg;
             if(_opt_wrap_inoutarg.m_present) {
             _true_call >> _inoutarg_wr;
             opt_inoutarg = 
                  (foo_bar_ptr) _inoutarg_wr.m_pv_iluobject;
             }
             else opt_inoutarg = ILUCPP_NULL;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             opt_return_value  = _true_object->passoptionals(
                        opt_inarg,
                        opt_inoutarg,
                        opt_outarg
              );


             _opt_wrap_return_value.iluSetFrom(opt_return_value);
             if(_opt_wrap_return_value.m_present)
                return_value = *opt_return_value; 

             _opt_wrap_inarg.iluSetFrom(opt_inarg);
             if(_opt_wrap_inarg.m_present)
                inarg = *opt_inarg; 

             _opt_wrap_inoutarg.iluSetFrom(opt_inoutarg);
             if(_opt_wrap_inoutarg.m_present)
                  _inoutarg_wr.m_pv_iluobject = (foo_bar_ptr) opt_inoutarg; 
             else  _inoutarg_wr.m_pv_iluobject = ILUCPP_NULL;

             _inoutarg_wr.iluReviseForObject(
                 (foo_bar_ptr) _inoutarg_wr.m_pv_iluobject);

             _opt_wrap_outarg.iluSetFrom(opt_outarg);
             if(_opt_wrap_outarg.m_present)
                 p_outarg = (foo_bar_ptr) opt_outarg; 
             iluObjectWrapper _outarg_wr(*p_outarg, ILUCPP_FALSE);

             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      

             _true_call +=  _opt_wrap_return_value;
             if(_opt_wrap_return_value.m_present) {
             _true_call +=  return_value;
             }

             _true_call +=  _opt_wrap_inoutarg;
             if(_opt_wrap_inoutarg.m_present) {
             _true_call += _inoutarg_wr;
             }

             _true_call +=  _opt_wrap_outarg;
             if(_opt_wrap_outarg.m_present) {
             _true_call += _outarg_wr;
             }
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      

             _true_call <<  _opt_wrap_return_value;
             if(_opt_wrap_return_value.m_present) {
             _true_call <<  return_value;
             }

             _true_call <<  _opt_wrap_inoutarg;
             if(_opt_wrap_inoutarg.m_present) {
             _true_call << _inoutarg_wr;
             }

             _true_call <<  _opt_wrap_outarg;
             if(_opt_wrap_outarg.m_present) {
             _true_call << _outarg_wr;
             }
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passoptionals");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passsimpleanys_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             CORBA_Any*   p_return_value;
             CORBA_Any    inarg;      
             CORBA_Any    inoutarg;      
             CORBA_Any*   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passsimpleanys(
                  inarg,
                  inoutarg,
                  p_outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call +=  inoutarg;
             _true_call += *p_outarg;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call <<  inoutarg;
             _true_call << *p_outarg;      
             delete p_outarg; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passsimpleanys");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passarrayanys_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             CORBA_Any*   p_return_value;
             CORBA_Any    inarg;      
             CORBA_Any    inoutarg;      
             CORBA_Any*   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passarrayanys(
                  inarg,
                  inoutarg,
                  p_outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call +=  inoutarg;
             _true_call += *p_outarg;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call <<  inoutarg;
             _true_call << *p_outarg;      
             delete p_outarg; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passarrayanys");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void foo_bar_passassortedanys_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             foo_bar_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   foo_bar::iluGetILUClassRecord());
             CORBA_Any*   p_return_value;
             CORBA_Any    inarg;      
             CORBA_Any    inoutarg;      
             CORBA_Any*   p_outarg;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (foo_bar_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  inarg;
             _true_call >>  inoutarg;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->passassortedanys(
                  inarg,
                  inoutarg,
                  p_outarg
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {  
             _true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
             _true_call +=  inoutarg;
             _true_call += *p_outarg;      
             };

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
             _true_call <<  inoutarg;
             _true_call << *p_outarg;      
             delete p_outarg; 
      }
     catch(CORBA_SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("foo_bar_passassortedanys");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

foo_true_bar_initializer::
foo_true_bar_initializer () {
             ensure_instantiation();
}

void *
foo_true_bar_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &foo_p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
foo_true_bar_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_zap_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passobj_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passenum_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 3,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passlatinstring_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 4,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passunicodestring_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 5,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passfixedrecord_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 6,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passvariablerecord_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 7,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passfixedarray_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 8,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passvariablearray_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 9,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passunboundedsequence_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 10,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passboundedsequence_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 11,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passvariableunion_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 12,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passoptionals_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 13,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passsimpleanys_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 14,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passarrayanys_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                foo_bar::iluGetILUClassRecord()->cl_methods + 15,
                REINTERPRET_CAST(ilu_StubProc, foo_bar_passassortedanys_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        //  iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
