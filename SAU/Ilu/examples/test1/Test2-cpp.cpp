
// This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056, Kestrel AI Institute Ltd, All Rights Reserved.
// KIS-CORBA information:  http://www.kestrelsystems.ca

#include "Test2-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members

  // exceptions vector
  static iluException interface_exceptions[] = {
          (iluException) 0,   //Test2_E1exception
  };

  // list of initialization functions to call for the Test2_ interface
  iluInitializationFunctionNode* Test2_p_initialization_function_list;
  int Test2_g_i_initialized;

  // holds the ilu class record for Test2_P objects
  iluClass Test2_P::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// Test2 initialization

  void Test2_iluInitialize () {

      if ( Test2_g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // define the exceptions in the Test2 interface
       interface_exceptions[g_Test2_E1_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test2"),
                 CONST_CAST( iluCString, "E1"),
                 CONST_CAST(iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"));

       // performs object type initialization
        Test2_P::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U2"),
             CONST_CAST( iluCString, "Test2"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:dSc47PlWucPws3UX8kBfzRQVxyF"),
             CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),  // UID of discriminant type
              3,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-CString-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "ev1");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "-O1-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "ev3");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  2,   // which arm
                  CONST_CAST( iluCString, "-P-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "ev7");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "P"),
            CONST_CAST( iluCString, "Test2"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS"),
            Test2_P::iluGetILUClassRecord(), // object class
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "T1O3"),
            CONST_CAST( iluCString, "Test2"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"),
            CONST_CAST( iluCString, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "T1U3"),
            CONST_CAST( iluCString, "Test2"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj"),
            CONST_CAST( iluCString, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "T1U2"),
            CONST_CAST( iluCString, "Test2"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9"),
            CONST_CAST( iluCString, "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "T1U"),
            CONST_CAST( iluCString, "Test2"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"),
            CONST_CAST( iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "F"),
            CONST_CAST( iluCString, "Test2"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),
            CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),  //  base type
            &b_new_registration);

       }
#endif  // IIOP_PROTOCOL 

   Test2_g_i_initialized = 1;
 }

 // call all the surrogate and true initialization functions
 iluCppInternal::iluCallInitializationFunctions(&Test2_p_initialization_function_list);

}



//////////////////////////////////////////////////////////////////////
//  Test2_P_var sizing, input and output operators

// note following three operators only needed
// if Test2_P is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const Test2_P_var& r_Test2_P_var) {
         r_call += r_Test2_P_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const Test2_P_var& r_Test2_P_var) {

      if (r_Test2_P_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_Test2_P_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_Test2_P_var.iluSetWrapper(
           new iluObjectWrapper(
               r_Test2_P_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_Test2_P_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : Test2_P::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_Test2_P_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, Test2_P_var& r_Test2_P_var) {
	  
      Test2_P_var temp_Test2_P_var;
	  
     if (r_Test2_P_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_Test2_P_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_Test2_P_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_Test2_P_var = r_Test2_P_var;

         // force a release since the var's in control of the refcount
         r_Test2_P_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_Test2_P_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, Test2_P::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_Test2_P_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_Test2_P_var = (Test2_P_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }



  //////////////////////////////////////////////////////////////////////
  // Test2_U2 members
		
  // constructors & destructor
  Test2_U2::Test2_U2() : m_b_beenset(ILUCPP_FALSE) {}

  Test2_U2::Test2_U2(const Test2_U2& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test2_U2::~Test2_U2() {
	  unset();
  }

  // assignment
  Test2_U2& Test2_U2::operator=
          (const Test2_U2& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                   m__CString_arm =
                      new CORBA_String_var(
                        r_union_type.m__CString_arm->iluStringVarReference());
                   break;

                 // _O1_arm
		  case Test1_ev3:  
                   m__O1_arm =
                      new Test1_O1_var(*r_union_type.m__O1_arm);
                   break;

                 // _P_arm
		  case Test1_ev7:  
                   m__P_arm =
                      new Test2_P_var(*r_union_type.m__P_arm);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test2_U2& Test2_U2::self(){
        return *this;
  }

  // discriminator access
  Test1_TheE Test2_U2::_d () const { 
	  return m_discriminator; 
  }

  void Test2_U2::_d (Test1_TheE new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case Test1_ev1: 
                       case Test1_ev3: 
                       case Test1_ev7: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                  switch(new_d) { 
                       case Test1_ev1: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _O1_arm
		  case Test1_ev3:  
                  switch(new_d) { 
                       case Test1_ev3: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _P_arm
		  case Test1_ev7:  
                  switch(new_d) { 
                       case Test1_ev7: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case Test1_ev1: 
                       case Test1_ev3: 
                       case Test1_ev7: 
                             break;
                       default: 
                             m_discriminator = new_d; 
                             return; 
                    }
                    break;

       }
       ILUCPP_WARN("Ignoring attempt to set union discriminator"
                   " outside current membership");
       return;
 }
 
   // _CString_arm access

   const iluShortCharacter *Test2_U2::_CString_arm() const{
        return (m__CString_arm->iluStringVarReference());
   }

   void Test2_U2::_CString_arm(iluShortCharacter * a__CString_arm){
         unset();
         m_discriminator = Test1_ev1;
         m__CString_arm = new CORBA_String_var(a__CString_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
         

   void Test2_U2::_CString_arm(const iluShortCharacter * a__CString_arm){
         unset();
         m_discriminator = Test1_ev1;
         m__CString_arm = new CORBA_String_var(a__CString_arm);
         m_b_beenset = ILUCPP_TRUE;
   }

   void Test2_U2::_CString_arm(const CORBA_String_var& a__CString_arm){
         unset();
         m_discriminator = Test1_ev1;
         m__CString_arm = new CORBA_String_var(a__CString_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _O1_arm access
     Test1_TheO1_ptr Test2_U2::_O1_arm() const {
       return (*m__O1_arm);
    }
  
    void Test2_U2::_O1_arm (Test1_TheO1_ptr a__O1_arm) {
          unset();			
          m_discriminator = Test1_ev3;
          // duplicate per corba spec
          Test1_TheO1::_duplicate(a__O1_arm);
          m__O1_arm = new Test1_O1_var(a__O1_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // _P_arm access
     Test2_P_ptr Test2_U2::_P_arm() const {
       return (*m__P_arm);
    }
  
    void Test2_U2::_P_arm (Test2_P_ptr a__P_arm) {
          unset();			
          m_discriminator = Test1_ev7;
          // duplicate per corba spec
          Test2_P::_duplicate(a__P_arm);
          m__P_arm = new Test2_P_var(a__P_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test2_U2::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
			  break;

                 // _O1_arm
		  case Test1_ev3:  
			  m__O1_arm->iluDeleteWrapper();
			  break;

                 // _P_arm
		  case Test1_ev7:  
			  m__P_arm->iluDeleteWrapper();
			  break;
		  }
	  }
  }
		  
  void Test2_U2::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                     delete m__CString_arm;
                     break;

                 // _O1_arm
		  case Test1_ev3:  
                     delete m__O1_arm;
                     break;

                 // _P_arm
		  case Test1_ev7:  
                     delete m__P_arm;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test2_U2

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test2_U2& r_Test2_U2) {

          iluUnionWrapper _r_Test2_U2(
                                r_Test2_U2._d(),
                                ilu_enumeration_tk);
          r_call += _r_Test2_U2;

          switch (r_Test2_U2.m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                   { iluCardinal _r__CString_arm_length =
                    strlen(r_Test2_U2.m__CString_arm->iluStringVarReference());
                    iluCStringWrapper _r__CString_arm_wrap(
                       (*r_Test2_U2.m__CString_arm).iluStringVarReference(),
                            _r__CString_arm_length);
                    r_call += _r__CString_arm_wrap;
                   }
                   break;

                 // _O1_arm
		  case Test1_ev3:  
                    r_call += (* (r_Test2_U2.m__O1_arm));

                   break;

                 // _P_arm
		  case Test1_ev7:  
                    r_call += (* (r_Test2_U2.m__P_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test2_U2& r_Test2_U2) {

          iluUnionWrapper _r_Test2_U2(
                                r_Test2_U2._d(),
                                ilu_enumeration_tk);
          r_call << _r_Test2_U2;

          switch (r_Test2_U2.m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                   { iluCardinal _r__CString_arm_length =
                    strlen(r_Test2_U2.m__CString_arm->iluStringVarReference());
                    iluCStringWrapper _r__CString_arm_wrap(
                       (*r_Test2_U2.m__CString_arm).iluStringVarReference(),
                            _r__CString_arm_length);
                    r_call << _r__CString_arm_wrap;
                   }
                   break;

                 // _O1_arm
		  case Test1_ev3:  
                    r_call << (* (r_Test2_U2.m__O1_arm));

                   break;

                 // _P_arm
		  case Test1_ev7:  
                    r_call << (* (r_Test2_U2.m__P_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test2_U2& r_Test2_U2) {
        
          iluUnionWrapper _r_Test2_U2(0, ilu_enumeration_tk);
        
          r_call >> _r_Test2_U2;

          switch (_r_Test2_U2.m_card_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                 { CORBA_String_var  _CString_arm_temp;
                     iluCardinal _r__CString_arm_length;
                     iluCStringWrapper _r__CString_arm_wrap(
                             _CString_arm_temp.iluStringVarReference(),
                            _r__CString_arm_length);
                     r_call >> _r__CString_arm_wrap;
                     r_Test2_U2._CString_arm(_CString_arm_temp);
                    break;
                   }

                 // _O1_arm
		  case Test1_ev3:  
                 { Test1_O1_var  _O1_arm_temp;
                    r_call >> _O1_arm_temp;
                    r_Test2_U2._O1_arm(_O1_arm_temp);
                    break;
                   }

                 // _P_arm
		  case Test1_ev7:  
                 { Test2_P_var  _P_arm_temp;
                    r_call >> _P_arm_temp;
                    r_Test2_U2._P_arm(_P_arm_temp);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test2_U2._d((Test1_TheE) (_r_Test2_U2.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test2_U2
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test2_U2, Test2_U2)

  // typecode instance for Test2_U2
  const CORBA_TypeCode_ptr Test2_tc_U2 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test2_U2);

  // define the Any insert and extract operators for Test2_U2 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test2_U2, Test2_tc_U2)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test2_U2, Test2_tc_U2)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test2_U2, Test2_tc_U2)

  //////////////////////////////////////////////////////////////////////
  // Test2_P members

  // CORBA object reference operations

  Test2_P_ptr Test2_P::_duplicate( Test2_P_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  Test2_P_ptr Test2_P::_nil() {
    return (Test2_P_ptr) NULL;
  }

  // default constructor
  Test2_P::Test2_P() {
     // to be determined
  }

  // destructor
  Test2_P::~Test2_P() {
    // to be determined
  }

  // copy constructor
  Test2_P::Test2_P(const Test2_P&) {
    // to be determined
  }

  // assignment operator
  void Test2_P::operator=(const Test2_P&) {
    // to be determined
  }

  // Simple Object Lookup
  Test2_P_ptr Test2_P::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Test2_P_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *Test2_P::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void Test2_P::iluInitialize() {

    ilu_Method a_method;
     char **_superclasses = NULL; 
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "Test2.P"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      1,          // number of methods
      0,          // number of superclasses
      _superclasses
   );

    {
     // for method SR_to_I

       iluException* SR_to_I_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "SR-to-I"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     SR_to_I_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "i"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
    }  //end for method SR_to_I

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  Test2_P typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(Test2_P)::iluDeleteValue (void* pv_value) {
                Test2_P_ptr p_thevalue = (Test2_P_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(Test2_P)::iluDeepCopy (void* pv_value) {
                Test2_P_ptr p_thevalue = (Test2_P_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test2_P)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               Test2_P_ptr p_thevalue = (Test2_P_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test2_P)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, Test2_P::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test2_P)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           Test2_P_ptr p_object = (Test2_P_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If Test2_P were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == Test2_P::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(Test2_P)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           Test2_P_ptr p_object = (Test2_P_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for Test2_P
        const CORBA_TypeCode_ptr Test2_tc_P = new ILUCPP_TYPE_CODE_CLASS_NAME(Test2_P);

      // define the Any insertion and extraction operators for Test2_P

      void operator<<=(CORBA_Any& r_any, Test2_P_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(Test2_tc_P, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test2_P_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(Test2_tc_P)) { 
                 r_p_object = (Test2_P_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


/////////////////////////////////////////////////////////////////
// Exception implementations for locally-defined
// exceptions of interface Test2 

/////////////////////////////////////////////////
// Test2_E1 member functions

  //constructor
  Test2_E1::Test2_E1(const Test2_E1& a_E1) {
  _m_value = a_E1._m_value;
  }

  //destructor
  Test2_E1::~Test2_E1() {
  }

  // constructor with member value
  Test2_E1::Test2_E1(const Test1_TheU& value) {
    _m_value = value;
  }

  // assignment operator
  Test2_E1& Test2_E1::operator=(const Test2_E1& a_E1) {
	_m_value = a_E1._m_value;
  return *this;
  }


////////////////////////////////////////////////////////////////
// Force initialization of Test2_ classes upon load

Test2_initializer Test2_initializer::sm_the_Test2_initializer;

Test2_initializer:: Test2_initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * Test2_initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(Test2_iluInitialize);
  return this;
}
