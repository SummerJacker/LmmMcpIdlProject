
// This file was automatically generated with KISORB (version 2.0beta1) tools
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information:  Dr. Wang at xcwang89@aliyun.com 

#include "Test3-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members

  // exceptions vector
  static iluException interface_exceptions[] = {
          (iluException) 0,   //Test3_E1exception
          (iluException) 1,   //Test1_E1exception
  };

  // list of initialization functions to call for the Test3_ interface
  iluInitializationFunctionNode* Test3_p_initialization_function_list;
  int Test3_g_i_initialized;

  // holds the ilu class record for Test3_O objects
  iluClass Test3_O::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// Test3 initialization

  void Test3_iluInitialize () {

      if ( Test3_g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // define the exceptions in the Test3 interface
       interface_exceptions[g_Test3_E1_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test3"),
                 CONST_CAST( iluCString, "E1"),
                 CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
       interface_exceptions[g_Test1_E1_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E1"),
                 CONST_CAST(iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"));

       // performs object type initialization
        Test3_O::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "FU"),
             CONST_CAST( iluCString, "Test3"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:p7oYELOBiB2uFXthQiHxgFh1H8p"),
             CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-O-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg"), // arm type
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
                  CONST_CAST( iluCString, "-CORBA-Long-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "ev3");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "O"),
            CONST_CAST( iluCString, "Test3"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg"),
            Test3_O::iluGetILUClassRecord(), // object class
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "T2T1O3"),
            CONST_CAST( iluCString, "Test3"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"),
            CONST_CAST( iluCString, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "T2T1U3"),
            CONST_CAST( iluCString, "Test3"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj"),
            CONST_CAST( iluCString, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj"),  //  base type
            &b_new_registration);

       }
#endif  // IIOP_PROTOCOL 

   Test3_g_i_initialized = 1;
 }

 // call all the surrogate and true initialization functions
 iluCppInternal::iluCallInitializationFunctions(&Test3_p_initialization_function_list);

}



//////////////////////////////////////////////////////////////////////
//  Test3_O_var sizing, input and output operators

// note following three operators only needed
// if Test3_O is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const Test3_O_var& r_Test3_O_var) {
         r_call += r_Test3_O_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const Test3_O_var& r_Test3_O_var) {

      if (r_Test3_O_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_Test3_O_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_Test3_O_var.iluSetWrapper(
           new iluObjectWrapper(
               r_Test3_O_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_Test3_O_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : Test3_O::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_Test3_O_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, Test3_O_var& r_Test3_O_var) {
	  
      Test3_O_var temp_Test3_O_var;
	  
     if (r_Test3_O_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_Test3_O_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_Test3_O_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_Test3_O_var = r_Test3_O_var;

         // force a release since the var's in control of the refcount
         r_Test3_O_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_Test3_O_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, Test3_O::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_Test3_O_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_Test3_O_var = (Test3_O_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }



  //////////////////////////////////////////////////////////////////////
  // Test3_FU members
		
  // constructors & destructor
  Test3_FU::Test3_FU() : m_b_beenset(ILUCPP_FALSE) {}

  Test3_FU::Test3_FU(const Test3_FU& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test3_FU::~Test3_FU() {
	  unset();
  }

  // assignment
  Test3_FU& Test3_FU::operator=
          (const Test3_FU& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _O_arm
		  case Test1_ev1:  
                   m__O_arm =
                      new Test3_O_var(*r_union_type.m__O_arm);
                   break;

                 // _CORBA_Long_arm
		  case Test1_ev3:  
                  m__CORBA_Long_arm = r_union_type.m__CORBA_Long_arm;
                  break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test3_FU& Test3_FU::self(){
        return *this;
  }

  // discriminator access
  Test1_TheE Test3_FU::_d () const { 
	  return m_discriminator; 
  }

  void Test3_FU::_d (Test1_TheE new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case Test1_ev1: 
                       case Test1_ev3: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _O_arm
		  case Test1_ev1:  
                  switch(new_d) { 
                       case Test1_ev1: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _CORBA_Long_arm
		  case Test1_ev3:  
                  switch(new_d) { 
                       case Test1_ev3: 
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
 
   // _O_arm access
     Test3_O_ptr Test3_FU::_O_arm() const {
       return (*m__O_arm);
    }
  
    void Test3_FU::_O_arm (Test3_O_ptr a__O_arm) {
          unset();			
          m_discriminator = Test1_ev1;
          // duplicate per corba spec
          Test3_O::_duplicate(a__O_arm);
          m__O_arm = new Test3_O_var(a__O_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // _CORBA_Long_arm access
     CORBA_Long Test3_FU::_CORBA_Long_arm () const {
       return m__CORBA_Long_arm;
     }

     void Test3_FU::_CORBA_Long_arm (CORBA_Long a__CORBA_Long_arm) {
          unset();			
          m_discriminator = Test1_ev3;
          m__CORBA_Long_arm = a__CORBA_Long_arm;
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test3_FU::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _O_arm
		  case Test1_ev1:  
			  m__O_arm->iluDeleteWrapper();
			  break;

                 // _CORBA_Long_arm
		  case Test1_ev3:  
			  break;
		  }
	  }
  }
		  
  void Test3_FU::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _O_arm
		  case Test1_ev1:  
                     delete m__O_arm;
                     break;

                 // _CORBA_Long_arm
		  case Test1_ev3:  
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test3_FU

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test3_FU& r_Test3_FU) {

          iluUnionWrapper _r_Test3_FU(
                                r_Test3_FU._d(),
                                ilu_enumeration_tk);
          r_call += _r_Test3_FU;

          switch (r_Test3_FU.m_discriminator) {

                 // _O_arm
		  case Test1_ev1:  
                    r_call += (* (r_Test3_FU.m__O_arm));

                   break;

                 // _CORBA_Long_arm
		  case Test1_ev3:  
                    r_call += r_Test3_FU.m__CORBA_Long_arm;
                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test3_FU& r_Test3_FU) {

          iluUnionWrapper _r_Test3_FU(
                                r_Test3_FU._d(),
                                ilu_enumeration_tk);
          r_call << _r_Test3_FU;

          switch (r_Test3_FU.m_discriminator) {

                 // _O_arm
		  case Test1_ev1:  
                    r_call << (* (r_Test3_FU.m__O_arm));

                   break;

                 // _CORBA_Long_arm
		  case Test1_ev3:  
                    r_call << r_Test3_FU.m__CORBA_Long_arm;
                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test3_FU& r_Test3_FU) {
        
          iluUnionWrapper _r_Test3_FU(0, ilu_enumeration_tk);
        
          r_call >> _r_Test3_FU;

          switch (_r_Test3_FU.m_card_discriminator) {

                 // _O_arm
		  case Test1_ev1:  
                 { Test3_O_var  _O_arm_temp;
                    r_call >> _O_arm_temp;
                    r_Test3_FU._O_arm(_O_arm_temp);
                    break;
                   }

                 // _CORBA_Long_arm
		  case Test1_ev3:  
                 { CORBA_Long  _CORBA_Long_arm_temp;
                    r_call >> _CORBA_Long_arm_temp;
                    r_Test3_FU._CORBA_Long_arm(_CORBA_Long_arm_temp);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test3_FU._d((Test1_TheE) (_r_Test3_FU.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test3_FU
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test3_FU, Test3_FU)

  // typecode instance for Test3_FU
  const CORBA_TypeCode_ptr Test3_tc_FU =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test3_FU);

  // define the Any insert and extract operators for Test3_FU 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test3_FU, Test3_tc_FU)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test3_FU, Test3_tc_FU)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test3_FU, Test3_tc_FU)

  //////////////////////////////////////////////////////////////////////
  // Test3_O members

  // CORBA object reference operations

  Test3_O_ptr Test3_O::_duplicate( Test3_O_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  Test3_O_ptr Test3_O::_nil() {
    return (Test3_O_ptr) NULL;
  }

  // default constructor
  Test3_O::Test3_O() {
     // to be determined
  }

  // destructor
  Test3_O::~Test3_O() {
    // to be determined
  }

  // copy constructor
  Test3_O::Test3_O(const Test3_O&) {
    // to be determined
  }

  // assignment operator
  void Test3_O::operator=(const Test3_O&) {
    // to be determined
  }

  // Simple Object Lookup
  Test3_O_ptr Test3_O::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Test3_O_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *Test3_O::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == Test2_T1O3::iluGetILUClassRecord()) 
      return (REINTERPRET_CAST(void *, STATIC_CAST(Test2_T1O3_ptr, this)));
    if (class_to_cast_down_to == Test2_P::iluGetILUClassRecord()) 
      return (REINTERPRET_CAST(void *, STATIC_CAST(Test2_P_ptr, this)));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void Test3_O::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"), 
                   CONST_CAST( iluCString,  "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "Test3.O"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      1,          // number of methods
      2,          // number of superclasses
      _superclasses
   );

    {
     // for method I_to_Test1U

       iluException I_to_Test1U_exception_array[2];
       I_to_Test1U_exception_array[0] =
            interface_exceptions[g_Test3_E1_index];
       I_to_Test1U_exception_array[1] =
            interface_exceptions[g_Test1_E1_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "I-to-Test1U"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     2 ,     // number of exceptions
                     I_to_Test1U_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "i"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
    }  //end for method I_to_Test1U

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  Test3_O typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(Test3_O)::iluDeleteValue (void* pv_value) {
                Test3_O_ptr p_thevalue = (Test3_O_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(Test3_O)::iluDeepCopy (void* pv_value) {
                Test3_O_ptr p_thevalue = (Test3_O_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test3_O)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               Test3_O_ptr p_thevalue = (Test3_O_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test3_O)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, Test3_O::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test3_O)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           Test3_O_ptr p_object = (Test3_O_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If Test3_O were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == Test3_O::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(Test3_O)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           Test3_O_ptr p_object = (Test3_O_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for Test3_O
        const CORBA_TypeCode_ptr Test3_tc_O = new ILUCPP_TYPE_CODE_CLASS_NAME(Test3_O);

      // define the Any insertion and extraction operators for Test3_O

      void operator<<=(CORBA_Any& r_any, Test3_O_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(Test3_tc_O, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test3_O_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(Test3_tc_O)) { 
                 r_p_object = (Test3_O_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


/////////////////////////////////////////////////////////////////
// Exception implementations for locally-defined
// exceptions of interface Test3 

/////////////////////////////////////////////////
// Test3_E1 member functions

  //constructor
  Test3_E1::Test3_E1(const Test3_E1& a_E1) {
  _m_value = a_E1._m_value;
  }

  //destructor
  Test3_E1::~Test3_E1() {
  }

  // constructor with member value
  Test3_E1::Test3_E1(const iluShortCharacter* value) {
    _m_value = value;
  }

  // assignment operator
  Test3_E1& Test3_E1::operator=(const Test3_E1& a_E1) {
	_m_value = a_E1._m_value;
  return *this;
  }


////////////////////////////////////////////////////////////////
// Force initialization of Test3_ classes upon load

Test3_initializer Test3_initializer::sm_the_Test3_initializer;

Test3_initializer:: Test3_initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * Test3_initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(Test3_iluInitialize);
  return this;
}
