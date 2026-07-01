
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Console-cpptrue.hpp"

static void _send_SRIO_Console_Console_AlreadyBind(
       iluTrueCall &_true_call, SRIO_Console::Console::AlreadyBind& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
           // Send Reply
                 _true_call << iluSendExceptionMode;
    }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_SRIO_Console_Console_AlreadyBind");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void _send_SRIO_Console_Console_NotFound(
       iluTrueCall &_true_call, SRIO_Console::Console::NotFound& _exception, iluCardinal exi)
{
    try {

           // Size Return
                 _true_call.iluSizeExceptionMode(exi+1);
           // Send Reply
                 _true_call << iluSendExceptionMode;
    }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("_send_SRIO_Console_Console_NotFound");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

// Globals and statics 

int SRIO_Console_true::Console_initializer::initialized; 
SRIO_Console_true::Console_initializer
     SRIO_Console_true::Console_initializer::sm_the_true_SRIO_Console_Console_initializer;
// Method Stubs

static void SRIO_Console_Console_getCosNamingInfo_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Console::Console::CosInfoSeq*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->getCosNamingInfo(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getCosNamingInfo");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_sendMsg_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::Message    m;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  m;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->sendMsg(
                  m
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_sendMsg");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_bind_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);
             iluCardinal       _sbh_length;
             iluShortCharacter*          sbh = ILUCPP_NULL;
             iluCStringWrapper _sbh_wr(sbh, _sbh_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _uid_wr;
             _true_call >> _sbh_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->bind(
                 (iluShortCharacter*) _uid_wr.m_r_cstring,
                 (iluShortCharacter*) _sbh_wr.m_r_cstring
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
    catch(SRIO_Console::Console::AlreadyBind& _exception) {
          _send_SRIO_Console_Console_AlreadyBind(_true_call, _exception, 0);
    }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_bind");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_unbind_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);
             iluCardinal       _details_length;
             iluShortCharacter*          details = ILUCPP_NULL;
             iluCStringWrapper _details_wr(details, _details_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _uid_wr;
             _true_call >> _details_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->unbind(
                 (iluShortCharacter*) _uid_wr.m_r_cstring,
                 (iluShortCharacter*) _details_wr.m_r_cstring
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
    catch(SRIO_Console::Console::NotFound& _exception) {
          _send_SRIO_Console_Console_NotFound(_true_call, _exception, 0);
    }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_unbind");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_rebind_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_TRUE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _uid_length;
             iluShortCharacter*          uid = ILUCPP_NULL;
             iluCStringWrapper _uid_wr(uid, _uid_length);
             iluCardinal       _sbh_length;
             iluShortCharacter*          sbh = ILUCPP_NULL;
             iluCStringWrapper _sbh_wr(sbh, _sbh_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _uid_wr;
             _true_call >> _sbh_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->rebind(
                 (iluShortCharacter*) _uid_wr.m_r_cstring,
                 (iluShortCharacter*) _sbh_wr.m_r_cstring
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
    catch(SRIO_Console::Console::NotFound& _exception) {
          _send_SRIO_Console_Console_NotFound(_true_call, _exception, 0);
    }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_rebind");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setNickname_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo;      
             iluCardinal       _newName_length;
             iluShortCharacter*          newName = ILUCPP_NULL;
             iluCStringWrapper _newName_wr(newName, _newName_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo;
             _true_call >> _newName_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setNickname(
                  uinfo,
                 (iluShortCharacter*) _newName_wr.m_r_cstring
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setNickname");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setPosition_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             iluCardinal       _name_length;
             iluShortCharacter*          name = ILUCPP_NULL;
             iluCStringWrapper _name_wr(name, _name_length);
             SRIO_Console::Console::Point    p;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _name_wr;
             _true_call >>  p;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setPosition(
                 (iluShortCharacter*) _name_wr.m_r_cstring,
                  p
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setPosition");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_addGoalPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::Point    p;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  p;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->addGoalPoint(
                  p
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_addGoalPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setGoalPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::Point    p;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  p;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setGoalPoint(
                  p
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setGoalPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setRole_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo;      
             SRIO_Console::Console::Role            r;    
             iluEnumWrapper       _r_wr( (iluDummyEnum &) r);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo;
             _true_call >> _r_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setRole(
                  uinfo,
                    (SRIO_Console::Console::Role) _r_wr.m_r_enum 

              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setRole");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_cancelRole_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->cancelRole(
                  uinfo
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_cancelRole");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setTrapPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::TrapPoint    p;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  p;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setTrapPoint(
                  p
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setTrapPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setFollow_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo1;      
             SRIO_Unit::General_Unit::UnitInfo    uinfo2;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo1;
             _true_call >>  uinfo2;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setFollow(
                  uinfo1,
                  uinfo2
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setFollow");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setFormationType_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::FormationType            f;    
             iluEnumWrapper       _f_wr( (iluDummyEnum &) f);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _f_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setFormationType(
                    (SRIO_Console::Console::FormationType) _f_wr.m_r_enum 

              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setFormationType");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setTrackMode_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::TrackMode            tm;    
             iluEnumWrapper       _tm_wr( (iluDummyEnum &) tm);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _tm_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setTrackMode(
                    (SRIO_Console::Console::TrackMode) _tm_wr.m_r_enum 

              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setTrackMode");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getCurrentUnit_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Unit::General_Unit::UnitInfo*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->getCurrentUnit(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getCurrentUnit");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getUnitNum_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Short    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->getUnitNum(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getUnitNum");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getFormationNum_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Short    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->getFormationNum(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getFormationNum");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getTrapNum_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Short    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->getTrapNum(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getTrapNum");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getFormationType_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Console::Console::FormationType            return_value;    
             iluEnumWrapper       _return_value_wr( (iluDummyEnum &) return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 

             // Note on G++ workaround  ..
             // use void * trickery to work around G++'s (2.7.2) problems
             // with enum casting.  This approach should work everywhere
             // else, so we may just want to do this for the general case.

             return_value  = _true_object->getFormationType(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getFormationType");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getFormationState_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Console::Console::FormationState            return_value;    
             iluEnumWrapper       _return_value_wr( (iluDummyEnum &) return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 

             // Note on G++ workaround  ..
             // use void * trickery to work around G++'s (2.7.2) problems
             // with enum casting.  This approach should work everywhere
             // else, so we may just want to do this for the general case.

             return_value  = _true_object->getFormationState(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getFormationState");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getMissionState_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Console::Console::MissionState            return_value;    
             iluEnumWrapper       _return_value_wr( (iluDummyEnum &) return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 

             // Note on G++ workaround  ..
             // use void * trickery to work around G++'s (2.7.2) problems
             // with enum casting.  This approach should work everywhere
             // else, so we may just want to do this for the general case.

             return_value  = _true_object->getMissionState(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getMissionState");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getUnitPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Console::Console::Point    return_value;      
             iluCardinal       _name_length;
             iluShortCharacter*          name = ILUCPP_NULL;
             iluCStringWrapper _name_wr(name, _name_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _name_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->getUnitPoint(
                 (iluShortCharacter*) _name_wr.m_r_cstring
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getUnitPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getByName_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Unit::General_Unit::UnitInfo*   p_return_value;
             iluCardinal       _name_length;
             iluShortCharacter*          name = ILUCPP_NULL;
             iluCStringWrapper _name_wr(name, _name_length);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _name_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->getByName(
                 (iluShortCharacter*) _name_wr.m_r_cstring
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getByName");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getLeaderPoint_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Console::Console::Point    return_value;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
                         return_value  = _true_object->getLeaderPoint(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call +=  return_value;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call <<  return_value;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getLeaderPoint");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_getPointSeq_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             SRIO_Console::Console::PointSeq*   p_return_value;

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
             p_return_value  = _true_object->getPointSeq(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += *p_return_value;      
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << *p_return_value;      
             delete p_return_value; 
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_getPointSeq");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_cancelFormation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->cancelFormation(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_cancelFormation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setLeaderSuspend_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setLeaderSuspend(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setLeaderSuspend");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_recoveryLeaderAction_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->recoveryLeaderAction(
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_recoveryLeaderAction");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_addUnitFormation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->addUnitFormation(
                  uinfo
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_addUnitFormation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_deleteUnitFormation_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->deleteUnitFormation(
                  uinfo
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_deleteUnitFormation");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setUnitFault_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setUnitFault(
                  uinfo
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setUnitFault");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setUnitFaultPosition_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Unit::General_Unit::UnitInfo    uinfo;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  uinfo;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setUnitFaultPosition(
                  uinfo
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setUnitFaultPosition");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setFormationState_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::FormationState            fs;    
             iluEnumWrapper       _fs_wr( (iluDummyEnum &) fs);

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >> _fs_wr;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setFormationState(
                    (SRIO_Console::Console::FormationState) _fs_wr.m_r_enum 

              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setFormationState");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

static void SRIO_Console_Console_setMissionState_stub (iluCall _call) {

       iluTrueCall _true_call(_call, ILUCPP_FALSE); 

       try {
             SRIO_Console::Console_ptr     _true_object;
             iluObjectWrapper  _discriminator(ILUCPP_TRUE, 
                                   SRIO_Console::Console::iluGetILUClassRecord());
             CORBA::Boolean        return_value;    
             iluBoolWrapper    _return_value_wr(return_value);
             SRIO_Console::Console::MissionStateData    msd;      

             // Read in discriminator 
             _true_call >> _discriminator;
             _true_object = (SRIO_Console::Console_ptr)(_discriminator.m_pv_iluobject);

             //Read in arguments
             _true_call >>  msd;
             _true_call << iluParametersFinishedMode;

             // Invoke actual method 
          return_value  = _true_object->setMissionState(
                  msd
              );


             // Size return
             if(_true_call.iluNeedsSizing()) {
				if (!ilu_ConnectionIsClosed(_true_call.iluGetCall()->ca_connection)) {			 
					_true_call << iluSizeReplyMode;                      
             _true_call += _return_value_wr;
				}
				else{
					_true_call.iluSetErrorType(ilu_ET_comm_failure);
					return;
				}
			}

             // Send reply 
             _true_call << iluSendReplyMode;                      
             _true_call << _return_value_wr;
      }
     catch(CORBA::SystemException& _exception) {
           _true_call.iluSetErrorType(_exception.exception_kind());
     }
     catch(...) {
        ILUCPP_WARN_UNEXPECTED_EXCEPTION("SRIO_Console_Console_setMissionState");
                _true_call.iluSetErrorType(CORBA_ERRTYP(unknown));
        }
}

/////////////////////////////////////////////////////////////////////////////

// Class Initializers

SRIO_Console_true::Console_initializer::
Console_initializer () {
             ensure_instantiation();
}

void *
SRIO_Console_true::Console_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &SRIO_Console::p_initialization_function_list,
                iluInitialize);
        return this; 
}

void
SRIO_Console_true::Console_initializer::iluInitialize () {
        if (initialized == 1)
                return;
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 0,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getCosNamingInfo_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 1,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_sendMsg_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 2,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_bind_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 3,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_unbind_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 4,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_rebind_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 5,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setNickname_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 6,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setPosition_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 7,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_addGoalPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 8,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setGoalPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 9,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setRole_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 10,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_cancelRole_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 11,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setTrapPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 12,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setFollow_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 13,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setFormationType_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 14,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setTrackMode_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 15,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getCurrentUnit_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 16,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getUnitNum_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 17,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getFormationNum_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 18,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getTrapNum_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 19,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getFormationType_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 20,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getFormationState_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 21,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getMissionState_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 22,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getUnitPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 23,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getByName_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 24,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getLeaderPoint_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 25,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_getPointSeq_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 26,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_cancelFormation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 27,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setLeaderSuspend_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 28,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_recoveryLeaderAction_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 29,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_addUnitFormation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 30,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_deleteUnitFormation_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 31,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setUnitFault_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 32,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setUnitFaultPosition_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 33,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setFormationState_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );
         ilu_SetMethodStubProc(
                SRIO_Console::Console::iluGetILUClassRecord()->cl_methods + 34,
                REINTERPRET_CAST(ilu_StubProc, SRIO_Console_Console_setMissionState_stub),
                iluCppInternal::iluGetCppLanguageIndex()
                );

        // for collectable objects, the following line is uncommented
        // NOTE: no longer needed - done by runtime, but benign if called
        // // iluCppInternal::iluEnsureGCNoter();

        initialized = 1;
}
