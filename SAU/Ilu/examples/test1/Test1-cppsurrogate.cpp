
// This file was automatically generated with  KIS-CORBA (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
// KIS-CORBA information:  http://www.kestrelsystems.ca.

#include "Test1-cppsurrogate.hpp"

// Static class initialization

Test1_surrogate_O3_initializer
     Test1_surrogate_O3_initializer::sm_the_surrogate_Test1_O3_initializer;
int Test1_surrogate_O3::_initialized; 

// Test1_O3 surrogate methods 


Test1_IS* 
Test1_surrogate_O3::
RS_R_to_R_IS (
          const Test1_RS&  r,
          Test1_R*&  r2
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, Test1_O3::iluGetILUClassRecord());

        try {
          Test1_IS*  p_return_value = new(Test1_IS);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          r2 =  new Test1_R;          

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += r;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << r;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 
         _surrogate_call >> *r2; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test1_surrogate_O3::
O1_U_to_U (
          Test1_O1_ptr  o,
          Test1_U&  u
         ) throw (CORBA_SystemException, Test1_E2) {

                  // check for sibling
                  if (! iluInSameServer(o)) {
                  // raise BAD_PARAM exception
                  CORBA(BAD_PARAM) bad_param_not_a_sibling;
                  throw(bad_param_not_a_sibling);
                  }


        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, Test1_O3::iluGetILUClassRecord());

        try {
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;
          iluObjectWrapper _o(o, ILUCPP_FALSE, ( o ? ILUCPP_NULL : Test1_O1::iluGetILUClassRecord())); 

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _o;
                 _surrogate_call += u;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _o;
              _surrogate_call << u;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_O1_U_to_U_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> u; 

         u.iluSurrogateSideCleanup(); 

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test1_surrogate_O3::
_throw_O1_U_to_U_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, Test1_E2) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        Test1_E2 _exception;
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


CORBA_Long 
Test1_surrogate_O3::
BS_to_I (
          const Test1_BS&  b
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, Test1_O3::iluGetILUClassRecord());

        try {
          CORBA_Long       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += b;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << b;
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

// Initialize to use Test1_O3 objects

void
Test1_surrogate_O3::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                Test1_O3::iluGetILUClassRecord(),
                Test1_surrogate_O3::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
         iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a Test1_O3 surrogate
 
iluObject*
Test1_surrogate_O3::
create_surrogate (iluKernelObject _kernel_object) {
        Test1_O3* _new_object = new Test1_surrogate_O3();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of Test1_O3 class upon load
 
Test1_surrogate_O3_initializer::
Test1_surrogate_O3_initializer () {
        ensure_instantiation();
}
 
void *
Test1_surrogate_O3_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                Test1_surrogate_O3::iluInitialize);
        return this;
}

// Static class initialization

Test1_surrogate_TheO1_initializer
     Test1_surrogate_TheO1_initializer::sm_the_surrogate_Test1_TheO1_initializer;
int Test1_surrogate_TheO1::_initialized; 

// Test1_TheO1 surrogate methods 


Test1_U* 
Test1_surrogate_TheO1::
U_CSS_to_U (
          const Test1_U&  u,
          const Test1_CSS&  css
         ) throw (CORBA_SystemException, Test1_E1, Test1_E2) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, Test1_TheO1::iluGetILUClassRecord());

        try {
          Test1_U*  p_return_value = new(Test1_U);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += u;
                 _surrogate_call += css;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << u;
              _surrogate_call << css;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_U_CSS_to_U_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> *p_return_value; 

         u.iluSurrogateSideCleanup(); 
         p_return_value->iluSurrogateSideCleanup(); 

          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test1_surrogate_TheO1::
_throw_U_CSS_to_U_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, Test1_E1, Test1_E2) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        Test1_E1 _exception;
                           _call >> _exception._m_value;
                        throw(_exception);
                      };

                case 1: {
                        Test1_E2 _exception;
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


Test1_RO 
Test1_surrogate_TheO1::
f_CSS_to_RO (
          const Test1_CSS&  css
         ) throw (CORBA_SystemException, Test1_E1) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, Test1_TheO1::iluGetILUClassRecord());

        try {
          Test1_RO      p_return_value;  
          iluOptionalWrapper  o_return_value;
          Test1_R       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += css;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << css;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_f_CSS_to_RO_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> o_return_value; 
         if(o_return_value.m_present) {
              p_return_value = new Test1_TheR;
              _surrogate_call >> *p_return_value;
         }
         else p_return_value = ILUCPP_NULL;


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test1_surrogate_TheO1::
_throw_f_CSS_to_RO_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, Test1_E1) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        Test1_E1 _exception;
                           _call >> _exception._m_value;
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


CORBA_Float 
Test1_surrogate_TheO1::
R_ScS_to_F (
          const Test1_R&  r,
          Test1_const_ScS    s
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 2, this, Test1_TheO1::iluGetILUClassRecord());

        try {
          CORBA_Float       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       s_length =
                  strlen(s);
          iluCStringWrapper _s(s, s_length);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += r;
                 _surrogate_call += _s;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << r;
              _surrogate_call << _s;
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


void
Test1_surrogate_TheO1::
a_RO (
          Test1_const_RO    ro
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 3, this, Test1_TheO1::iluGetILUClassRecord());

        try {
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluOptionalWrapper   o_ro(CONST_CAST(Test1_RO, ro));

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                _surrogate_call += o_ro; 
                if(o_ro.m_present)
                   _surrogate_call += *ro;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
               _surrogate_call << o_ro; 
               if(o_ro.m_present)
                  _surrogate_call << *ro;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());


   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


Test1_O2_ptr 
Test1_surrogate_TheO1::
get_O2 (
         ) throw (CORBA_SystemException, Test1_CantCreate) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 4, this, Test1_TheO1::iluGetILUClassRecord());

        try {
          iluObjectWrapper _return_value(ILUCPP_FALSE, Test1_O2::iluGetILUClassRecord()); 
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;

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

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_get_O2_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> _return_value; 

    
      return  (Test1_O2_ptr)_return_value.m_pv_iluobject;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test1_surrogate_TheO1::
_throw_get_O2_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, Test1_CantCreate) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        Test1_CantCreate _exception;
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


Test1_O3_ptr 
Test1_surrogate_TheO1::
get_O3 (
          CORBA_Boolean  subclass
         ) throw (CORBA_SystemException, Test1_CantCreate) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 5, this, Test1_TheO1::iluGetILUClassRecord());

        try {
          iluObjectWrapper _return_value(ILUCPP_FALSE, Test1_O3::iluGetILUClassRecord()); 
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;
          iluBoolWrapper      _subclass(subclass);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += _subclass;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << _subclass;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_get_O3_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> _return_value; 

    
      return  (Test1_O3_ptr)_return_value.m_pv_iluobject;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test1_surrogate_TheO1::
_throw_get_O3_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, Test1_CantCreate) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        Test1_CantCreate _exception;
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

// Initialize to use Test1_TheO1 objects

void
Test1_surrogate_TheO1::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                Test1_TheO1::iluGetILUClassRecord(),
                Test1_surrogate_TheO1::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a Test1_TheO1 surrogate
 
iluObject*
Test1_surrogate_TheO1::
create_surrogate (iluKernelObject _kernel_object) {
        Test1_TheO1* _new_object = new Test1_surrogate_TheO1();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of Test1_TheO1 class upon load
 
Test1_surrogate_TheO1_initializer::
Test1_surrogate_TheO1_initializer () {
        ensure_instantiation();
}
 
void *
Test1_surrogate_TheO1_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                Test1_surrogate_TheO1::iluInitialize);
        return this;
}

// Static class initialization

Test1_surrogate_O2_initializer
     Test1_surrogate_O2_initializer::sm_the_surrogate_Test1_O2_initializer;
int Test1_surrogate_O2::_initialized; 

// Test1_O2 surrogate methods 


Test1_CSS* 
Test1_surrogate_O2::
OO_A0_to_CSS (
          Test1_OO  o,
          const Test1_A0  a
         ) throw (CORBA_SystemException, Test1_E2) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, Test1_O2::iluGetILUClassRecord());

        try {
          Test1_CSS*  p_return_value = new(Test1_CSS);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);
          iluCardinal       _exception_number;
          iluOptionalWrapper   o_o(CONST_CAST(Test1_OO, o));
          iluObjectWrapper _o(o, ILUCPP_FALSE, ( o ? ILUCPP_NULL : Test1_O1::iluGetILUClassRecord())); 

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                _surrogate_call += o_o; 
                if(o_o.m_present)
                   _surrogate_call += _o;
                Test1_size_const_A0(
                        _surrogate_call, a);

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
               _surrogate_call << o_o; 
               if(o_o.m_present)
                  _surrogate_call << _o;
                Test1_output_const_A0(
                      _surrogate_call, a);
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

     
         if(_surrogate_call.iluExceptionPresent(_exception_number))
              _throw_OO_A0_to_CSS_exception(_exception_number-1, _surrogate_call);

         _surrogate_call >> *p_return_value; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}


void
Test1_surrogate_O2::
_throw_OO_A0_to_CSS_exception (iluCardinal _exception_index, iluSurrogateCall& _call)
throw (CORBA_SystemException, Test1_E2) {     

   try {
          switch(_exception_index) {  

                case 0: {
                        Test1_E2 _exception;
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


Test1_A0_slice* 
Test1_surrogate_O2::
R_I_A1_to_I_A0 (
          const Test1_R&  r,
          CORBA_Long&  i,
          const Test1_A1  a
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 1, this, Test1_O2::iluGetILUClassRecord());

        try {
          Test1_A0_slice*  p_return_value = Test1_A0_alloc();   
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += r;
                 _surrogate_call += i;
                Test1_size_const_TheA1(
                        _surrogate_call, a);

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << r;
              _surrogate_call << i;
                Test1_output_const_TheA1(
                      _surrogate_call, a);
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         Test1_input_A0(_surrogate_call, p_return_value);
         _surrogate_call >> i; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}

/////////////////////////////////////////////////////////////////////////////

// Initialize to use Test1_O2 objects

void
Test1_surrogate_O2::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                Test1_O2::iluGetILUClassRecord(),
                Test1_surrogate_O2::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a Test1_O2 surrogate
 
iluObject*
Test1_surrogate_O2::
create_surrogate (iluKernelObject _kernel_object) {
        Test1_O2* _new_object = new Test1_surrogate_O2();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of Test1_O2 class upon load
 
Test1_surrogate_O2_initializer::
Test1_surrogate_O2_initializer () {
        ensure_instantiation();
}
 
void *
Test1_surrogate_O2_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                Test1_surrogate_O2::iluInitialize);
        return this;
}

// Static class initialization

Test1_surrogate_O4_initializer
     Test1_surrogate_O4_initializer::sm_the_surrogate_Test1_O4_initializer;
int Test1_surrogate_O4::_initialized; 

// Test1_O4 surrogate methods 


CORBA_Double 
Test1_surrogate_O4::
R_to_R (
          CORBA_Double  r
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, Test1_O4::iluGetILUClassRecord());

        try {
          CORBA_Double       return_value;    
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += r;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << r;
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

// Initialize to use Test1_O4 objects

void
Test1_surrogate_O4::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                Test1_O4::iluGetILUClassRecord(),
                Test1_surrogate_O4::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a Test1_O4 surrogate
 
iluObject*
Test1_surrogate_O4::
create_surrogate (iluKernelObject _kernel_object) {
        Test1_O4* _new_object = new Test1_surrogate_O4();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of Test1_O4 class upon load
 
Test1_surrogate_O4_initializer::
Test1_surrogate_O4_initializer () {
        ensure_instantiation();
}
 
void *
Test1_surrogate_O4_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                Test1_surrogate_O4::iluInitialize);
        return this;
}

// Static class initialization

Test1_surrogate_P_initializer
     Test1_surrogate_P_initializer::sm_the_surrogate_Test1_P_initializer;
int Test1_surrogate_P::_initialized; 

// Test1_P surrogate methods 


Test1_IS* 
Test1_surrogate_P::
m2 (
          CORBA_Long  j
         ) throw (CORBA_SystemException) {

        iluCallStruct _call;
        iluSurrogateCall _surrogate_call( &_call, 0, this, Test1_P::iluGetILUClassRecord());

        try {
          Test1_IS*  p_return_value = new(Test1_IS);  
          iluObjectWrapper   _discriminator(*this, ILUCPP_TRUE);

          do {

             // Size arguments
             if (_surrogate_call.iluNeedsSizing()) {
                 _surrogate_call += _discriminator;
                 _surrogate_call += j;

            };

            // Send request
              _surrogate_call << iluRequestMode;
              _surrogate_call << _discriminator;
              _surrogate_call << j;
              _surrogate_call << iluRequestSentMode;

            // Note: If asynchronous call, end of try block here. 
             
            // Get reply 
             _surrogate_call << iluGetReplyMode;

         } //end do 
             
         while(_surrogate_call.iluShouldRetryCall());

         _surrogate_call >> *p_return_value; 


          return p_return_value;

   } // end try
   catch(CORBA_SystemException& _exception) {
      _surrogate_call.iluSetErrorType(_exception.exception_kind());
      _exception._raise();
   }
}

/////////////////////////////////////////////////////////////////////////////

// Initialize to use Test1_P objects

void
Test1_surrogate_P::iluInitialize () {
        if (_initialized == 1)
                return;
        iluCppInternal::iluRegisterSurrogateCreator(
                Test1_P::iluGetILUClassRecord(),
                Test1_surrogate_P::create_surrogate
                );

        // if the object is 'COLLECTIBLE', the following line is uncommented
        // iluCppInternal::iluEnsureGCCallback();

        _initialized = 1;
}

// Create a Test1_P surrogate
 
iluObject*
Test1_surrogate_P::
create_surrogate (iluKernelObject _kernel_object) {
        Test1_P* _new_object = new Test1_surrogate_P();
        _new_object->iluAssociateKernelObject(_kernel_object);
        return _new_object;
}
 
// Force initialization of Test1_P class upon load
 
Test1_surrogate_P_initializer::
Test1_surrogate_P_initializer () {
        ensure_instantiation();
}
 
void *
Test1_surrogate_P_initializer::
ensure_instantiation () {
        iluCppInternal::iluAddInitializationFunction(
                &Test1_p_initialization_function_list,
                Test1_surrogate_P::iluInitialize);
        return this;
}
