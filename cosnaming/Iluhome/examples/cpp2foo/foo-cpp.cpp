
// This file was automatically generated with KISORB (version 2.0beta1) tools
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information:  Dr. Wang at xcwang89@aliyun.com 

#include "foo-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members

  // exceptions vector
  static iluException interface_exceptions[] = {
          (iluException) 0,   //foo_zapexceptionexception
  };

  // list of initialization functions to call for the foo_ interface
  iluInitializationFunctionNode* foo_p_initialization_function_list;
  int foo_g_i_initialized;

  // holds the ilu class record for foo_bar objects
  iluClass foo_bar::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// foo initialization

  void foo_iluInitialize () {

      if ( foo_g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // define the exceptions in the foo interface
       interface_exceptions[g_foo_zapexception_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "foo"),
                 CONST_CAST( iluCString, "zapexception"),
                 CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));

       // performs object type initialization
        foo_bar::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        iluCppInternal::iluRegisterOptionalType(
           CONST_CAST( iluCString, "optionalinteger"),
           CONST_CAST( iluCString, "foo"),
           REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
           CONST_CAST( iluCString, "ilut:ofauPtsPQTj2q-endOLfYeMwJ9O"),
           CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"),  //  base type
             &b_new_registration);

        iluCppInternal::iluRegisterOptionalType(
           CONST_CAST( iluCString, "optionalbarobject"),
           CONST_CAST( iluCString, "foo"),
           REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
           CONST_CAST( iluCString, "ilut:lA1-gauP3mLjEFspj2k52hq5PX7"),
           CONST_CAST( iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"),  //  base type
             &b_new_registration);

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "variableuniontype"),
             CONST_CAST( iluCString, "foo"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:nmTjdwd3QN6EfRusSMC3dQWH7GF"),
             CONST_CAST( iluCString, "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y"),  // UID of discriminant type
              2,         // number of arms
              2,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "bararm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"), // arm type
                  2  // number of vals that can select this arm
              );


             constant_value.value.shortcardinal_val = 0;
             constant_value.kind = ilu_shortcardinal_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             constant_value.value.shortcardinal_val = 1;
             constant_value.kind = ilu_shortcardinal_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 1, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "integerarm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"), // arm type
                  0  // number of vals that can select this arm
              );

      }

       { // array type "foo_bararray"
 
        iluCardinal _foo_bararray_dims[] = { 2, 3 };
 
        iluCppInternal::iluRegisterArrayType(
            CONST_CAST( iluCString, "bararray"),
            CONST_CAST( iluCString, "foo"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:ppduVKzUz7mJ9uNrb12ogZWBUMN"),
            CONST_CAST( iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"), // base type of array
            2,           // number of dimensions
            _foo_bararray_dims, // actual dimensions
            &b_new_registration);
       }

       { // array type "foo_integerarray"
 
        iluCardinal _foo_integerarray_dims[] = { 5, 10 };
 
        iluCppInternal::iluRegisterArrayType(
            CONST_CAST( iluCString, "integerarray"),
            CONST_CAST( iluCString, "foo"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:dS1jP9Hb7HfmiCadLrIaDgo2AtH"),
            CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"), // base type of array
            2,           // number of dimensions
            _foo_integerarray_dims, // actual dimensions
            &b_new_registration);
       }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "variablerecordtype"),
            CONST_CAST( iluCString, "foo"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:dZvb2JnjdmXfZjZmEsM9FjlUmaM"),
            3, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "variablerecordstring"),     // field name
                CONST_CAST( iluCString, "ilut:eYztpSNWOQfUavObPyGDE-e+D6y") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "variablerecordinteger"),     // field name
                CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "variablerecordobject"),     // field name
                CONST_CAST( iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "fixedrecordtype"),
            CONST_CAST( iluCString, "foo"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:fKR0RhuCfCNDSswEBpaTT2AakQv"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "fixedrecordinteger"),     // field name
                CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "fixedrecordenum"),     // field name
                CONST_CAST( iluCString, "ilut:p7G376cXCRfIoOT15k9jenyTrDT") // UID of field type
            );
        }

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "bar"),
            CONST_CAST( iluCString, "foo"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"),
            foo_bar::iluGetILUClassRecord(), // object class
            &b_new_registration);

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "enumtype"),
            CONST_CAST( iluCString, "foo"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:p7G376cXCRfIoOT15k9jenyTrDT"),
            7,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "red"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "orange"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "yellow"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "green"),  // element name
              3       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              4,        // which element
              CONST_CAST( iluCString, "blue"),  // element name
              4       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              5,        // which element
              CONST_CAST( iluCString, "indigo"),  // element name
              5       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              6,        // which element
              CONST_CAST( iluCString, "violet"),  // element name
              6       // integer value for element
        );
     }

       }
#endif  // IIOP_PROTOCOL 

   foo_g_i_initialized = 1;
 }

 // call all the surrogate and true initialization functions
 iluCppInternal::iluCallInitializationFunctions(&foo_p_initialization_function_list);

}



//////////////////////////////////////////////////////////////////////
//  foo_bar_var sizing, input and output operators

// note following three operators only needed
// if foo_bar is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const foo_bar_var& r_foo_bar_var) {
         r_call += r_foo_bar_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const foo_bar_var& r_foo_bar_var) {

      if (r_foo_bar_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_foo_bar_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_foo_bar_var.iluSetWrapper(
           new iluObjectWrapper(
               r_foo_bar_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_foo_bar_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : foo_bar::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_foo_bar_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, foo_bar_var& r_foo_bar_var) {
	  
      foo_bar_var temp_foo_bar_var;
	  
     if (r_foo_bar_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_foo_bar_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_foo_bar_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_foo_bar_var = r_foo_bar_var;

         // force a release since the var's in control of the refcount
         r_foo_bar_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_foo_bar_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_foo_bar_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_foo_bar_var = (foo_bar_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }


  // define the member functions in typecode class for foo_enumtype
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            foo_enumtype, foo_enumtype)

  // typecode instance for foo_enumtype
  const CORBA_TypeCode_ptr foo_tc_enumtype =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_enumtype);

  // define the Any insertion and extraction operators for foo_enumtype
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           foo_enumtype, foo_tc_enumtype)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           foo_enumtype, foo_tc_enumtype)


/////////////////////////////////////////////////////////////////////
//  foo_variablerecordtype members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   foo_variablerecordtype::foo_variablerecordtype() {
variablerecordstring = CORBA_String_var();  // iffy sunpro workaround
variablerecordobject = foo_bar_var();  // iffy sunpro workaround
  }

  // copy constructor
  foo_variablerecordtype::foo_variablerecordtype(const foo_variablerecordtype& r_a_variablerecordtype) {
          variablerecordstring = r_a_variablerecordtype.variablerecordstring;
          variablerecordinteger = r_a_variablerecordtype.variablerecordinteger;
          variablerecordobject = r_a_variablerecordtype.variablerecordobject;
   }

  // destructor
  foo_variablerecordtype::~foo_variablerecordtype() {
  }

  //possibly sunpro-specific workaround 
  foo_variablerecordtype& foo_variablerecordtype::self(){
        return *this;
  }

  // assignment operator
  foo_variablerecordtype& foo_variablerecordtype::operator=(
       const foo_variablerecordtype& r_a_variablerecordtype) {
          if (this != &r_a_variablerecordtype) {
          variablerecordstring = r_a_variablerecordtype.variablerecordstring;
          variablerecordinteger = r_a_variablerecordtype.variablerecordinteger;
          variablerecordobject = r_a_variablerecordtype.variablerecordobject;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for foo_variablerecordtype

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const foo_variablerecordtype& r_foo_variablerecordtype)  {

         r_call += iluSizeRecord;
         iluCardinal r_variablerecordstring_length =
             strlen(r_foo_variablerecordtype.variablerecordstring.iluStringVarReference());
          iluCStringWrapper _r_variablerecordstring_wrap(
                 (r_foo_variablerecordtype.variablerecordstring).iluStringVarReference(),
                  r_variablerecordstring_length);
         r_call += _r_variablerecordstring_wrap;
          r_call +=  r_foo_variablerecordtype.variablerecordinteger;
          r_call += r_foo_variablerecordtype.variablerecordobject;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const foo_variablerecordtype& r_foo_variablerecordtype)  {

         r_call << iluOutputRecord;
         iluCardinal r_variablerecordstring_length =
             strlen(r_foo_variablerecordtype.variablerecordstring.iluStringVarReference());
          iluCStringWrapper _r_variablerecordstring_wrap(
                 (r_foo_variablerecordtype.variablerecordstring).iluStringVarReference(),
                  r_variablerecordstring_length);
         r_call << _r_variablerecordstring_wrap;
          r_call <<  r_foo_variablerecordtype.variablerecordinteger;
          r_call << r_foo_variablerecordtype.variablerecordobject;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          foo_variablerecordtype& r_foo_variablerecordtype)  {

         r_call >> iluInputRecord;
         iluCardinal r_variablerecordstring_length;
         iluCStringWrapper _r_variablerecordstring_wrap(
                 (r_foo_variablerecordtype.variablerecordstring).iluStringVarReference(),
                  r_variablerecordstring_length);
         r_call >> _r_variablerecordstring_wrap;
          r_call >>  r_foo_variablerecordtype.variablerecordinteger;
          r_call >> r_foo_variablerecordtype.variablerecordobject;

         r_call >> iluEndRecord;
         return r_call;
 }

  // for ilustub use only - should call before surrogate side stub returns
  void foo_variablerecordtype::iluSurrogateSideCleanup() const {
        variablerecordobject.iluDeleteWrapper();
   }

  // define the member fns in typecode class for foo_variablerecordtype
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             foo_variablerecordtype, foo_variablerecordtype)

  // typecode instance for foo_variablerecordtype
  const CORBA_TypeCode_ptr foo_tc_variablerecordtype =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_variablerecordtype);

  // define the Any insert and extract operators for foo_variablerecordtype 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          foo_variablerecordtype, foo_tc_variablerecordtype)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          foo_variablerecordtype, foo_tc_variablerecordtype)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          foo_variablerecordtype, foo_tc_variablerecordtype)


/////////////////////////////////////////////////////////////////////
//  foo_fixedrecordtype members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   foo_fixedrecordtype::foo_fixedrecordtype() {
  }

  // copy constructor
  foo_fixedrecordtype::foo_fixedrecordtype(const foo_fixedrecordtype& r_a_fixedrecordtype) {
          fixedrecordinteger = r_a_fixedrecordtype.fixedrecordinteger;
          fixedrecordenum = r_a_fixedrecordtype.fixedrecordenum;
   }

  // destructor
  foo_fixedrecordtype::~foo_fixedrecordtype() {
  }

  //possibly sunpro-specific workaround 
  foo_fixedrecordtype& foo_fixedrecordtype::self(){
        return *this;
  }

  // assignment operator
  foo_fixedrecordtype& foo_fixedrecordtype::operator=(
       const foo_fixedrecordtype& r_a_fixedrecordtype) {
          if (this != &r_a_fixedrecordtype) {
          fixedrecordinteger = r_a_fixedrecordtype.fixedrecordinteger;
          fixedrecordenum = r_a_fixedrecordtype.fixedrecordenum;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for foo_fixedrecordtype

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const foo_fixedrecordtype& r_foo_fixedrecordtype)  {

         r_call += iluSizeRecord;
          r_call +=  r_foo_fixedrecordtype.fixedrecordinteger;
         iluEnumWrapper _r_fixedrecordenum_wrap(
              (iluDummyEnum &) r_foo_fixedrecordtype.fixedrecordenum);
         r_call += _r_fixedrecordenum_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const foo_fixedrecordtype& r_foo_fixedrecordtype)  {

         r_call << iluOutputRecord;
          r_call <<  r_foo_fixedrecordtype.fixedrecordinteger;
         iluEnumWrapper _r_fixedrecordenum_wrap(
              (iluDummyEnum &) r_foo_fixedrecordtype.fixedrecordenum);
         r_call << _r_fixedrecordenum_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          foo_fixedrecordtype& r_foo_fixedrecordtype)  {

         r_call >> iluInputRecord;
          r_call >>  r_foo_fixedrecordtype.fixedrecordinteger;
         iluEnumWrapper _r_fixedrecordenum_wrap(
              (iluDummyEnum &) r_foo_fixedrecordtype.fixedrecordenum);
         r_call >> _r_fixedrecordenum_wrap;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for foo_fixedrecordtype
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             foo_fixedrecordtype, foo_fixedrecordtype)

  // typecode instance for foo_fixedrecordtype
  const CORBA_TypeCode_ptr foo_tc_fixedrecordtype =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_fixedrecordtype);

  // define the Any insert and extract operators for foo_fixedrecordtype 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          foo_fixedrecordtype, foo_tc_fixedrecordtype)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          foo_fixedrecordtype, foo_tc_fixedrecordtype)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          foo_fixedrecordtype, foo_tc_fixedrecordtype)
  
 //////////////////////////////////////////////////////////////////////
 // foo_bararray_var array member funs and allocation utility functions

  foo_bararray_slice* foo_bararray_alloc (){

/* xxx temp debugging only 
       foo_bararray_slice* p_slice =
              (foo_bararray_slice*)(new foo_bar_var[2][3]);
       foo_bar_var* p_element = (foo_bar_var*) p_slice;	
       for (CORBA_Long) count = 0; count < 2 * 3; count++)
               *p_element++ = ~count;
       return (p_slice);
end xxx temp debugging only */

       return ((foo_bararray_slice*) (new foo_bar_var[2][3]));
   }


  void foo_bararray_free(
       foo_bararray_slice* p_foo_bararray_slice) {
       delete [] p_foo_bararray_slice;
  }
  
  // duplicate a foo_bararray
  foo_bararray_slice* foo_bararray_dup(
      const foo_bararray_slice* p_foo_bararray_slice) {

       if (!p_foo_bararray_slice)
          return ILUCPP_NULL;
       else {
           foo_bararray_slice* p_slice = foo_bararray_alloc();
           foo_bar_var* p_this_element = (foo_bar_var*) p_slice;
           foo_bar_var* p_that_element =
                           (foo_bar_var*) p_foo_bararray_slice;
           for (CORBA_Long count = 0; count < 2 * 3; count++)
              *p_this_element++ = *p_that_element++;
           return p_slice;
       }
  }
  
  // copy a foo_bararray
  void foo_bararray_copy(
       foo_bararray_slice*       p_to_foo_bararray_slice,
       const foo_bararray_slice* p_from_foo_bararray_slice) {
       if (   (!p_from_foo_bararray_slice)
           || (!p_to_foo_bararray_slice)) return;
       else {
           foo_bar_var* p_this_element =
                     (foo_bar_var*) p_to_foo_bararray_slice;
           foo_bar_var* p_that_element =
                     (foo_bar_var*) p_from_foo_bararray_slice;
           for (CORBA_Long count = 0; count < 2 * 3; count++)
              *p_this_element++ = *p_that_element++;
       }
  }

  void foo_bararray_iluSurrogateSideCleanup (
         foo_bararray_slice* p_foo_bararray_slice) {
        if (p_foo_bararray_slice) {
            foo_bar_var* p_element =
                  (foo_bar_var*) p_foo_bararray_slice;
            for (CORBA_Long count = 0; count < 2 * 3; count++){
                    p_element->iluDeleteWrapper();
                    p_element++;
             }
       }
 }


  void foo_const_bararray_iluSurrogateSideCleanup (
        const foo_bararray_slice* p_foo_bararray_slice) {
        if (p_foo_bararray_slice) {
            foo_bar_var* p_element =
                  (foo_bar_var*) p_foo_bararray_slice;
            for (CORBA_Long count = 0; count < 2 * 3; count++){
                    p_element->iluDeleteWrapper();
                    p_element++;
             }
       }
 }

 
  // insertion, extraction, and sizing functions for foo_bararray

  iluBaseCall& foo_size_const_bararray(
         iluBaseCall& r_call,
          const foo_bar_var a_foo_bararray[][3]) {


          r_call.iluSizeArray(2 * 3);
          for (iluCardinal index0 = 0; index0 < 2; index0++) {
             for (iluCardinal index1 = 0; index1 < 3; index1++) {
                  r_call +=  a_foo_bararray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_size_bararray(
         iluBaseCall& r_call,
           foo_bar_var a_foo_bararray[][3]) {


          r_call.iluSizeArray(2 * 3);
          for (iluCardinal index0 = 0; index0 < 2; index0++) {
             for (iluCardinal index1 = 0; index1 < 3; index1++) {
                  r_call +=  a_foo_bararray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_output_const_bararray(
         iluBaseCall& r_call,
          const foo_bar_var a_foo_bararray[][3]) {


          r_call.iluOutputArray(2 * 3);
          for (iluCardinal index0 = 0; index0 < 2; index0++) {
             for (iluCardinal index1 = 0; index1 < 3; index1++) {
                  r_call <<  a_foo_bararray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_output_bararray(
         iluBaseCall& r_call,
           foo_bar_var a_foo_bararray[][3]) {


          r_call.iluOutputArray(2 * 3);
          for (iluCardinal index0 = 0; index0 < 2; index0++) {
             for (iluCardinal index1 = 0; index1 < 3; index1++) {
                  r_call <<  a_foo_bararray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_input_bararray(
         iluBaseCall& r_call,
           foo_bar_var a_foo_bararray[][3]) {


         r_call >> iluInputArray;
          for (iluCardinal index0 = 0; index0 < 2; index0++) {
             for (iluCardinal index1 = 0; index1 < 3; index1++) {
                  r_call >>  a_foo_bararray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


 // define the four member functions in typecode class for foo_bararray
  ILUCPP_DEFINE_ILU_TYPE_CODE_ARRAY_MEMBERFUNCTIONS(foo_bararray, 
       foo_bararray_slice, foo_bararray_alloc, foo_bararray_dup,
       foo_size_bararray, foo_output_bararray, foo_input_bararray)

  // typecode instance for foo_bararray
  const CORBA_TypeCode_ptr foo_tc_bararray =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_bararray);

 // define the Any insertion and extraction operators for foo_bararray_forany
  ILUCPP_DEFINE_ARRAY_INSERTION_OPERATOR(foo_bararray_slice, foo_bararray_forany,
        foo_tc_bararray, foo_bararray_dup)
  ILUCPP_DEFINE_ARRAY_EXTRACTION_OPERATOR(foo_bararray_forany,
         foo_tc_bararray,  foo_bararray_slice)
  
 //////////////////////////////////////////////////////////////////////
 // foo_integerarray_var array member funs and allocation utility functions

  foo_integerarray_slice* foo_integerarray_alloc (){

/* xxx temp debugging only 
       foo_integerarray_slice* p_slice =
              (foo_integerarray_slice*)(new CORBA_Long[5][10]);
       CORBA_Long* p_element = (CORBA_Long*) p_slice;	
       for (CORBA_Long) count = 0; count < 5 * 10; count++)
               *p_element++ = ~count;
       return (p_slice);
end xxx temp debugging only */

       return ((foo_integerarray_slice*) (new CORBA_Long[5][10]));
   }


  void foo_integerarray_free(
       foo_integerarray_slice* p_foo_integerarray_slice) {
       delete [] p_foo_integerarray_slice;
  }
  
  // duplicate a foo_integerarray
  foo_integerarray_slice* foo_integerarray_dup(
      const foo_integerarray_slice* p_foo_integerarray_slice) {

       if (!p_foo_integerarray_slice)
          return ILUCPP_NULL;
       else {
           foo_integerarray_slice* p_slice = foo_integerarray_alloc();
           CORBA_Long* p_this_element = (CORBA_Long*) p_slice;
           CORBA_Long* p_that_element =
                           (CORBA_Long*) p_foo_integerarray_slice;
           for (CORBA_Long count = 0; count < 5 * 10; count++)
              *p_this_element++ = *p_that_element++;
           return p_slice;
       }
  }
  
  // copy a foo_integerarray
  void foo_integerarray_copy(
       foo_integerarray_slice*       p_to_foo_integerarray_slice,
       const foo_integerarray_slice* p_from_foo_integerarray_slice) {
       if (   (!p_from_foo_integerarray_slice)
           || (!p_to_foo_integerarray_slice)) return;
       else {
           CORBA_Long* p_this_element =
                     (CORBA_Long*) p_to_foo_integerarray_slice;
           CORBA_Long* p_that_element =
                     (CORBA_Long*) p_from_foo_integerarray_slice;
           for (CORBA_Long count = 0; count < 5 * 10; count++)
              *p_this_element++ = *p_that_element++;
       }
  }
 
  // insertion, extraction, and sizing functions for foo_integerarray

  iluBaseCall& foo_size_const_integerarray(
         iluBaseCall& r_call,
          const CORBA_Long a_foo_integerarray[][10]) {


          r_call.iluSizeArray(5 * 10);
          for (iluCardinal index0 = 0; index0 < 5; index0++) {
             for (iluCardinal index1 = 0; index1 < 10; index1++) {
                  r_call +=  a_foo_integerarray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_size_integerarray(
         iluBaseCall& r_call,
           CORBA_Long a_foo_integerarray[][10]) {


          r_call.iluSizeArray(5 * 10);
          for (iluCardinal index0 = 0; index0 < 5; index0++) {
             for (iluCardinal index1 = 0; index1 < 10; index1++) {
                  r_call +=  a_foo_integerarray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_output_const_integerarray(
         iluBaseCall& r_call,
          const CORBA_Long a_foo_integerarray[][10]) {


          r_call.iluOutputArray(5 * 10);
          for (iluCardinal index0 = 0; index0 < 5; index0++) {
             for (iluCardinal index1 = 0; index1 < 10; index1++) {
                  r_call <<  a_foo_integerarray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_output_integerarray(
         iluBaseCall& r_call,
           CORBA_Long a_foo_integerarray[][10]) {


          r_call.iluOutputArray(5 * 10);
          for (iluCardinal index0 = 0; index0 < 5; index0++) {
             for (iluCardinal index1 = 0; index1 < 10; index1++) {
                  r_call <<  a_foo_integerarray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& foo_input_integerarray(
         iluBaseCall& r_call,
           CORBA_Long a_foo_integerarray[][10]) {


         r_call >> iluInputArray;
          for (iluCardinal index0 = 0; index0 < 5; index0++) {
             for (iluCardinal index1 = 0; index1 < 10; index1++) {
                  r_call >>  a_foo_integerarray [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


 // define the four member functions in typecode class for foo_integerarray
  ILUCPP_DEFINE_ILU_TYPE_CODE_ARRAY_MEMBERFUNCTIONS(foo_integerarray, 
       foo_integerarray_slice, foo_integerarray_alloc, foo_integerarray_dup,
       foo_size_integerarray, foo_output_integerarray, foo_input_integerarray)

  // typecode instance for foo_integerarray
  const CORBA_TypeCode_ptr foo_tc_integerarray =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_integerarray);

 // define the Any insertion and extraction operators for foo_integerarray_forany
  ILUCPP_DEFINE_ARRAY_INSERTION_OPERATOR(foo_integerarray_slice, foo_integerarray_forany,
        foo_tc_integerarray, foo_integerarray_dup)
  ILUCPP_DEFINE_ARRAY_EXTRACTION_OPERATOR(foo_integerarray_forany,
         foo_tc_integerarray,  foo_integerarray_slice)
  

 //////////////////////////////////////////////////////////////////////
 // foo_boundedbarseq members   
  
  // constructors & destructor
  foo_boundedbarseq::foo_boundedbarseq () : m_maximum(3),
        m_length(0),
        m_release (ILUCPP_TRUE) {
            m_buffer = allocbuf (m_maximum);
            m_varbuffer = new foo_bar_var [3];
  }
  foo_boundedbarseq::foo_boundedbarseq (CORBA_ULong length, 
        foo_bar_ptr* data, CORBA_Boolean release) : m_maximum(3),
        m_length(length),
        m_release (release),
        m_buffer(data) {

        if (m_length > 3) {
        // really undefined by CORBA as to what to do,
        // but better safe than sorry!
             CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
             throw (an_exception);
        }
        m_varbuffer = new foo_bar_var[3];
        for (CORBA_ULong index = 0; index < 3; index++) {
            (m_varbuffer[index]).iluSetRelease(m_release);
             m_varbuffer[index] = (data[index]);
        }	  
  }

  foo_boundedbarseq::foo_boundedbarseq (const foo_boundedbarseq& r_foo_boundedbarseq)   :
         m_maximum(r_foo_boundedbarseq.m_maximum), 
         m_length(r_foo_boundedbarseq.m_length), 
         m_release(ILUCPP_TRUE) 
         {
            m_buffer = allocbuf (m_maximum);
            m_varbuffer = new foo_bar_var[3];

#if( defined(OLDGNUC_WORKAROUND) || defined (_MSC_VER))
                        // workaround to GNU 2.7.2 internal compiler error
                        // note, this GNU workaround approach should work every where else, so
                        // we may just want to do this for the general case.
                        foo_bar_ptr p_buffer_ptr;
                        foo_bar_var* p_buffer_var;
                        for (CORBA_ULong index = 0; index < m_length; index++) {
                                p_buffer_ptr = r_foo_boundedbarseq.m_buffer[index];
                                m_buffer[index] = p_buffer_ptr;
                                p_buffer_var =  &(m_varbuffer[index]);
                                (*(p_buffer_var)) = foo_bar::_duplicate((foo_bar_ptr)r_foo_boundedbarseq.m_varbuffer[index]);
                        }

#else
            for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_foo_boundedbarseq.m_buffer[index];
               m_varbuffer[index] = r_foo_boundedbarseq.m_varbuffer[index];
            } 
#endif
   }
		
  foo_boundedbarseq::~foo_boundedbarseq() {
        if (m_buffer && m_release)
           freebuf (m_buffer);
        if(m_length > 0)
           delete [] m_varbuffer;
  }

 // assignment
   foo_boundedbarseq& foo_boundedbarseq::operator= (const foo_boundedbarseq& r_foo_boundedbarseq) {
         if (this == &r_foo_boundedbarseq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         if (m_length > 0)  
              delete [] m_varbuffer;
          m_buffer = allocbuf (r_foo_boundedbarseq.m_maximum);
        m_varbuffer = new foo_bar_var[3];
         m_release = ILUCPP_TRUE;
         m_length = r_foo_boundedbarseq.m_length;
         m_maximum = r_foo_boundedbarseq.m_maximum;

#if (defined(OLDGNUC_WORKAROUND) || defined (_MSC_VER))
       {
         // workaround to GNU 2.7.2 internal compiler error
         // note, this GNU workaround approach should work every where else, 
         // so we may just want to do this for the general case.
            foo_bar_ptr  p_buffer_ptr;
            foo_bar_var* p_buffer_var;
            for (CORBA_ULong index = 0; index < m_length; index++) {
                p_buffer_ptr= r_foo_boundedbarseq.m_buffer[index];
                m_buffer[index] = p_buffer_ptr;
               p_buffer_var =  &(m_varbuffer[index]);
               (*(p_buffer_var)) =
                 foo_bar::_duplicate((foo_bar_ptr)r_foo_boundedbarseq.
                      m_varbuffer[index]);
            }
        }

#else
        for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_foo_boundedbarseq.m_buffer[index];
               m_varbuffer[index] = r_foo_boundedbarseq.m_varbuffer[index];
         } 
#endif
        return *this;
  }

  // memory management
  foo_bar_ptr* foo_boundedbarseq::allocbuf(CORBA_ULong num_elements) {
       if (num_elements > 0) {
          foo_bar_ptr* p_new_buffer =
                new foo_bar_ptr [num_elements];
          for (CORBA_ULong ul_index = 0; ul_index < num_elements; ul_index++)
             p_new_buffer[ul_index] = *(new foo_bar_ptr);
          return p_new_buffer;
        }
        else return ILUCPP_NULL;
  }
  
  void foo_boundedbarseq::freebuf(foo_bar_ptr* p_buf) {
        delete [] p_buf;
  }

  void foo_boundedbarseq::length (CORBA_ULong len) {
      if (len > m_maximum) {
      // really undefined by CORBA as to what to do,
      // but better safe than sorry!
         CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
         throw (an_exception);
         }
       else {
          if (len < m_length && m_release) {
             for (CORBA_ULong index = len; index < m_length; index++) {
                 // attempt to NULL, not sure correct 
                 m_buffer[index] = *(new foo_bar_ptr);
              }
          }
          m_length = len;
       }
  }
  
 // accessors
   CORBA_ULong foo_boundedbarseq::maximum() const {
        return m_maximum;
  }
  
  CORBA_ULong foo_boundedbarseq::length() const {
        return m_length;
  }  
  
  CORBA_Boolean foo_boundedbarseq::release() const{
    return m_release;
  }
  
  // buffer accessors
  foo_bar_ptr* foo_boundedbarseq::get_buffer (CORBA_Boolean orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  foo_bar_ptr const* foo_boundedbarseq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  foo_bar_var& foo_boundedbarseq::operator [] (CORBA_ULong index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
            throw (an_exception);
       }
      return m_varbuffer[index];
  }
  
  const foo_bar_var& foo_boundedbarseq::operator [] (CORBA_ULong index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const foo_bar_var *_temp = 
              (const foo_bar_var *) &m_varbuffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  foo_boundedbarseq& foo_boundedbarseq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for foo_boundedbarseq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const foo_boundedbarseq& r_foo_boundedbarseq){

        iluCardinal card_length = r_foo_boundedbarseq.length();
        iluSequenceWrapper _r_foo_boundedbarseq(card_length);
        r_call += _r_foo_boundedbarseq;
        for (CORBA_ULong index = 0; index < r_foo_boundedbarseq.length(); index++) {
          r_call += r_foo_boundedbarseq[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const foo_boundedbarseq& r_foo_boundedbarseq){

        iluCardinal card_length = r_foo_boundedbarseq.length();
        iluSequenceWrapper _r_foo_boundedbarseq(card_length);
        r_call << _r_foo_boundedbarseq;
        for (CORBA_ULong index = 0; index < r_foo_boundedbarseq.length(); index++) {
          r_call << r_foo_boundedbarseq[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        foo_boundedbarseq& r_foo_boundedbarseq){

        CORBA_ULong card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        foo_boundedbarseq _seq_temp; // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_ULong index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_foo_boundedbarseq = foo_boundedbarseq(_seq_temp); 
        return r_call;
  }

  // for ilustub use only - call before the surrogate side stub returns
  void foo_boundedbarseq::iluSurrogateSideCleanup() const {
	  for (CORBA_ULong index = 0; index < m_length; index++) {
		  (m_varbuffer[index]).iluDeleteWrapper();
	  }
  }

  // define the member fns in typecode class for foo_boundedbarseq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             foo_boundedbarseq, foo_boundedbarseq)

  // typecode instance for foo_boundedbarseq
  const CORBA_TypeCode_ptr foo_tc_boundedbarseq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_boundedbarseq);

  // define the Any insert and extract operators for foo_boundedbarseq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          foo_boundedbarseq, foo_tc_boundedbarseq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          foo_boundedbarseq, foo_tc_boundedbarseq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          foo_boundedbarseq, foo_tc_boundedbarseq)
  

 //////////////////////////////////////////////////////////////////////
 // foo_unboundedlongseq members   

 // constructors & destructor
  foo_unboundedlongseq::foo_unboundedlongseq () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  foo_unboundedlongseq::foo_unboundedlongseq (CORBA_ULong max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  foo_unboundedlongseq::foo_unboundedlongseq (CORBA_ULong max , CORBA_ULong length, 
          CORBA_Long* data, CORBA_Boolean release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  foo_unboundedlongseq::~foo_unboundedlongseq() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  foo_unboundedlongseq::foo_unboundedlongseq (const foo_unboundedlongseq& r_foo_unboundedlongseq)
  :
         m_maximum(r_foo_unboundedlongseq.m_maximum),
         m_length(r_foo_unboundedlongseq.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_foo_unboundedlongseq.m_buffer[index];
            }
   }

 // assignment
   foo_unboundedlongseq& foo_unboundedlongseq::operator= (const foo_unboundedlongseq& r_foo_unboundedlongseq) {
         if (this == &r_foo_unboundedlongseq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_foo_unboundedlongseq.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_foo_unboundedlongseq.m_length;
          for (CORBA_ULong index = 0; index < m_length; index++) {
              m_buffer[index] = r_foo_unboundedlongseq.m_buffer[index];
          }
          return *this;
       }

  // memory management
  CORBA_Long* foo_unboundedlongseq::allocbuf(CORBA_ULong num_elements) {
      return (num_elements > 0 ? (new CORBA_Long[num_elements]) : NULL);
  }
  
  void foo_unboundedlongseq::freebuf(CORBA_Long* p_buf) {
        delete [] p_buf;
  }

  void foo_unboundedlongseq::length (CORBA_ULong len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 CORBA_Long* p_oldbuf = m_buffer;
                 CORBA_ULong oldlen = m_length;
                 CORBA_Boolean b_oldrelease = m_release;
                 m_release = ILUCPP_TRUE;
                 m_length = len;
                 m_maximum = len;
                 m_buffer = allocbuf(m_length);
                 for (CORBA_ULong index = 0; index < oldlen; index++) {
                     m_buffer[index] = p_oldbuf[index];
                 }
                if (b_oldrelease)
                   freebuf(p_oldbuf);
                } 
  }
  
 // accessors
   CORBA_ULong foo_unboundedlongseq::maximum() const {
        return m_maximum;
  }
  
  CORBA_ULong foo_unboundedlongseq::length() const {
        return m_length;
  }  
  
  CORBA_Boolean foo_unboundedlongseq::release() const{
    return m_release;
  }
  
  // buffer accessors
  CORBA_Long* foo_unboundedlongseq::get_buffer (CORBA_Boolean orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  CORBA_Long const* foo_unboundedlongseq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  CORBA_Long& foo_unboundedlongseq::operator [] (CORBA_ULong index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const CORBA_Long& foo_unboundedlongseq::operator [] (CORBA_ULong index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const CORBA_Long *_temp = 
              (const CORBA_Long *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  foo_unboundedlongseq& foo_unboundedlongseq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for foo_unboundedlongseq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const foo_unboundedlongseq& r_foo_unboundedlongseq){

        iluCardinal card_length = r_foo_unboundedlongseq.length();
        iluSequenceWrapper _r_foo_unboundedlongseq(card_length);
        r_call += _r_foo_unboundedlongseq;
        for (CORBA_ULong index = 0; index < r_foo_unboundedlongseq.length(); index++) {
          r_call += r_foo_unboundedlongseq[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const foo_unboundedlongseq& r_foo_unboundedlongseq){

        iluCardinal card_length = r_foo_unboundedlongseq.length();
        iluSequenceWrapper _r_foo_unboundedlongseq(card_length);
        r_call << _r_foo_unboundedlongseq;
        for (CORBA_ULong index = 0; index < r_foo_unboundedlongseq.length(); index++) {
          r_call << r_foo_unboundedlongseq[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        foo_unboundedlongseq& r_foo_unboundedlongseq){

        CORBA_ULong card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        foo_unboundedlongseq _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_ULong index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_foo_unboundedlongseq = foo_unboundedlongseq(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for foo_unboundedlongseq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             foo_unboundedlongseq, foo_unboundedlongseq)

  // typecode instance for foo_unboundedlongseq
  const CORBA_TypeCode_ptr foo_tc_unboundedlongseq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_unboundedlongseq);

  // define the Any insert and extract operators for foo_unboundedlongseq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          foo_unboundedlongseq, foo_tc_unboundedlongseq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          foo_unboundedlongseq, foo_tc_unboundedlongseq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          foo_unboundedlongseq, foo_tc_unboundedlongseq)


  //////////////////////////////////////////////////////////////////////
  // foo_variableuniontype members
		
  // constructors & destructor
  foo_variableuniontype::foo_variableuniontype() : m_b_beenset(ILUCPP_FALSE) {}

  foo_variableuniontype::foo_variableuniontype(const foo_variableuniontype& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  foo_variableuniontype::~foo_variableuniontype() {
	  unset();
  }

  // assignment
  foo_variableuniontype& foo_variableuniontype::operator=
          (const foo_variableuniontype& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // bararm
		  case 0:  
		  case 1:  
                   m_bararm =
                      new foo_bar_var(*r_union_type.m_bararm);
                   break;

                 // integerarm
                  default:
                  m_integerarm = r_union_type.m_integerarm;
                  break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  foo_variableuniontype& foo_variableuniontype::self(){
        return *this;
  }

  // discriminator access
  CORBA_UShort foo_variableuniontype::_d () const { 
	  return m_discriminator; 
  }

  void foo_variableuniontype::_d (CORBA_UShort new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // bararm
		  case 0:  
		  case 1:  
                  switch(new_d) { 
                       case 0: 
                       case 1: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case 0: 
                       case 1: 
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
 
   // bararm access
     foo_bar_ptr foo_variableuniontype::bararm() const {
       return (*m_bararm);
    }
  
    void foo_variableuniontype::bararm (foo_bar_ptr a_bararm) {
          unset();			
          m_discriminator = 0;
          // duplicate per corba spec
          foo_bar::_duplicate(a_bararm);
          m_bararm = new foo_bar_var(a_bararm);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // integerarm access
     CORBA_Long foo_variableuniontype::integerarm () const {
       return m_integerarm;
     }

     void foo_variableuniontype::integerarm (CORBA_Long a_integerarm) {
          unset();			
          m_discriminator = 2;
          m_integerarm = a_integerarm;
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void foo_variableuniontype::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // bararm
		  case 0:  
		  case 1:  
			  m_bararm->iluDeleteWrapper();
			  break;

                 // integerarm
                  default:
			  break;
		  }
	  }
  }
		  
  void foo_variableuniontype::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // bararm
		  case 0:  
		  case 1:  
                     delete m_bararm;
                     break;

                 // integerarm
                  default:
                     break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for foo_variableuniontype

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const foo_variableuniontype& r_foo_variableuniontype) {

          iluUnionWrapper _r_foo_variableuniontype(
                                r_foo_variableuniontype._d(),
                                ilu_shortcardinal_tk);
          r_call += _r_foo_variableuniontype;

          switch (r_foo_variableuniontype.m_discriminator) {

                 // bararm
		  case 0:  
		  case 1:  
                    r_call += (* (r_foo_variableuniontype.m_bararm));

                   break;

                 // integerarm
                  default:
                    r_call += r_foo_variableuniontype.m_integerarm;
                   break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const foo_variableuniontype& r_foo_variableuniontype) {

          iluUnionWrapper _r_foo_variableuniontype(
                                r_foo_variableuniontype._d(),
                                ilu_shortcardinal_tk);
          r_call << _r_foo_variableuniontype;

          switch (r_foo_variableuniontype.m_discriminator) {

                 // bararm
		  case 0:  
		  case 1:  
                    r_call << (* (r_foo_variableuniontype.m_bararm));

                   break;

                 // integerarm
                  default:
                    r_call << r_foo_variableuniontype.m_integerarm;
                   break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, foo_variableuniontype& r_foo_variableuniontype) {
        
          iluUnionWrapper _r_foo_variableuniontype(0, ilu_shortcardinal_tk);
        
          r_call >> _r_foo_variableuniontype;

          switch (_r_foo_variableuniontype.m_card_discriminator) {

                 // bararm
		  case 0:  
		  case 1:  
                 { foo_bar_var  bararm_temp;
                    r_call >> bararm_temp;
                    r_foo_variableuniontype.bararm(bararm_temp);
                    break;
                   }

                 // integerarm
                  default:
                 { CORBA_Long  integerarm_temp;
                    r_call >> integerarm_temp;
                    r_foo_variableuniontype.integerarm(integerarm_temp);
                    break;
                   }

          };

          r_call >> iluEndUnion;
          r_foo_variableuniontype._d((CORBA_UShort) (_r_foo_variableuniontype.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for foo_variableuniontype
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             foo_variableuniontype, foo_variableuniontype)

  // typecode instance for foo_variableuniontype
  const CORBA_TypeCode_ptr foo_tc_variableuniontype =
            new ILUCPP_TYPE_CODE_CLASS_NAME(foo_variableuniontype);

  // define the Any insert and extract operators for foo_variableuniontype 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          foo_variableuniontype, foo_tc_variableuniontype)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          foo_variableuniontype, foo_tc_variableuniontype)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          foo_variableuniontype, foo_tc_variableuniontype)

  //////////////////////////////////////////////////////////////////////
  // foo_bar members

  // CORBA object reference operations

  foo_bar_ptr foo_bar::_duplicate( foo_bar_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  foo_bar_ptr foo_bar::_nil() {
    return (foo_bar_ptr) NULL;
  }

  // default constructor
  foo_bar::foo_bar() {
     // to be determined
  }

  // destructor
  foo_bar::~foo_bar() {
    // to be determined
  }

  // copy constructor
  foo_bar::foo_bar(const foo_bar&) {
    // to be determined
  }

  // assignment operator
  void foo_bar::operator=(const foo_bar&) {
    // to be determined
  }

  // Simple Object Lookup
  foo_bar_ptr foo_bar::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (foo_bar_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *foo_bar::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void foo_bar::iluInitialize() {

    ilu_Method a_method;
     char **_superclasses = NULL; 
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "foo.bar"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_TRUE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      16,          // number of methods
      0,          // number of superclasses
      _superclasses
   );

    {
     // for method zap

       iluException zap_exception_array[1];
       zap_exception_array[0] =
            interface_exceptions[g_foo_zapexception_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "zap"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     zap_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"));
    }  //end for method zap

    {
     // for method passobj

       iluException* passobj_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "passobj"), // name
                     2,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passobj_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK"));
    }  //end for method passobj

    {
     // for method passenum

       iluException* passenum_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     2,      // method index
                     CONST_CAST(iluCString, "passenum"), // name
                     3,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passenum_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:p7G376cXCRfIoOT15k9jenyTrDT") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:p7G376cXCRfIoOT15k9jenyTrDT"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:p7G376cXCRfIoOT15k9jenyTrDT"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:p7G376cXCRfIoOT15k9jenyTrDT"));
    }  //end for method passenum

    {
     // for method passlatinstring

       iluException* passlatinstring_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     3,      // method index
                     CONST_CAST(iluCString, "passlatinstring"), // name
                     4,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passlatinstring_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:eYztpSNWOQfUavObPyGDE-e+D6y") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:eYztpSNWOQfUavObPyGDE-e+D6y"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:eYztpSNWOQfUavObPyGDE-e+D6y"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:eYztpSNWOQfUavObPyGDE-e+D6y"));
    }  //end for method passlatinstring

    {
     // for method passunicodestring

       iluException* passunicodestring_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     4,      // method index
                     CONST_CAST(iluCString, "passunicodestring"), // name
                     5,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passunicodestring_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:fvQgfgVDerLn1k730-F39wc+dD4") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:fvQgfgVDerLn1k730-F39wc+dD4"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:fvQgfgVDerLn1k730-F39wc+dD4"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:fvQgfgVDerLn1k730-F39wc+dD4"));
    }  //end for method passunicodestring

    {
     // for method passfixedrecord

       iluException* passfixedrecord_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     5,      // method index
                     CONST_CAST(iluCString, "passfixedrecord"), // name
                     6,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passfixedrecord_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:fKR0RhuCfCNDSswEBpaTT2AakQv") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:fKR0RhuCfCNDSswEBpaTT2AakQv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:fKR0RhuCfCNDSswEBpaTT2AakQv"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:fKR0RhuCfCNDSswEBpaTT2AakQv"));
    }  //end for method passfixedrecord

    {
     // for method passvariablerecord

       iluException* passvariablerecord_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     6,      // method index
                     CONST_CAST(iluCString, "passvariablerecord"), // name
                     7,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passvariablerecord_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:dZvb2JnjdmXfZjZmEsM9FjlUmaM") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:dZvb2JnjdmXfZjZmEsM9FjlUmaM"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:dZvb2JnjdmXfZjZmEsM9FjlUmaM"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:dZvb2JnjdmXfZjZmEsM9FjlUmaM"));
    }  //end for method passvariablerecord

    {
     // for method passfixedarray

       iluException* passfixedarray_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     7,      // method index
                     CONST_CAST(iluCString, "passfixedarray"), // name
                     8,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passfixedarray_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:dS1jP9Hb7HfmiCadLrIaDgo2AtH") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:dS1jP9Hb7HfmiCadLrIaDgo2AtH"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:dS1jP9Hb7HfmiCadLrIaDgo2AtH"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:dS1jP9Hb7HfmiCadLrIaDgo2AtH"));
    }  //end for method passfixedarray

    {
     // for method passvariablearray

       iluException* passvariablearray_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     8,      // method index
                     CONST_CAST(iluCString, "passvariablearray"), // name
                     9,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passvariablearray_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:ppduVKzUz7mJ9uNrb12ogZWBUMN") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ppduVKzUz7mJ9uNrb12ogZWBUMN"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:ppduVKzUz7mJ9uNrb12ogZWBUMN"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:ppduVKzUz7mJ9uNrb12ogZWBUMN"));
    }  //end for method passvariablearray

    {
     // for method passunboundedsequence

       iluException* passunboundedsequence_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     9,      // method index
                     CONST_CAST(iluCString, "passunboundedsequence"), // name
                     10,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passunboundedsequence_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:bT4M-C1TU4wI2xrA+cyasmB33Lf") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:bT4M-C1TU4wI2xrA+cyasmB33Lf"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:bT4M-C1TU4wI2xrA+cyasmB33Lf"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:bT4M-C1TU4wI2xrA+cyasmB33Lf"));
    }  //end for method passunboundedsequence

    {
     // for method passboundedsequence

       iluException* passboundedsequence_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     10,      // method index
                     CONST_CAST(iluCString, "passboundedsequence"), // name
                     11,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passboundedsequence_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:o5kjFsW9FbBFpk3mB0q+1DUevXV") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:o5kjFsW9FbBFpk3mB0q+1DUevXV"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:o5kjFsW9FbBFpk3mB0q+1DUevXV"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:o5kjFsW9FbBFpk3mB0q+1DUevXV"));
    }  //end for method passboundedsequence

    {
     // for method passvariableunion

       iluException* passvariableunion_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     11,      // method index
                     CONST_CAST(iluCString, "passvariableunion"), // name
                     12,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passvariableunion_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:nmTjdwd3QN6EfRusSMC3dQWH7GF") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:nmTjdwd3QN6EfRusSMC3dQWH7GF"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:nmTjdwd3QN6EfRusSMC3dQWH7GF"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:nmTjdwd3QN6EfRusSMC3dQWH7GF"));
    }  //end for method passvariableunion

    {
     // for method passoptionals

       iluException* passoptionals_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     12,      // method index
                     CONST_CAST(iluCString, "passoptionals"), // name
                     13,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passoptionals_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:ofauPtsPQTj2q-endOLfYeMwJ9O") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ofauPtsPQTj2q-endOLfYeMwJ9O"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:lA1-gauP3mLjEFspj2k52hq5PX7"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:lA1-gauP3mLjEFspj2k52hq5PX7"));
    }  //end for method passoptionals

    {
     // for method passsimpleanys

       iluException* passsimpleanys_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     13,      // method index
                     CONST_CAST(iluCString, "passsimpleanys"), // name
                     14,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passsimpleanys_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:irM650Q4ZJ3aqx9pgLzoj5Delco") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
    }  //end for method passsimpleanys

    {
     // for method passarrayanys

       iluException* passarrayanys_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     14,      // method index
                     CONST_CAST(iluCString, "passarrayanys"), // name
                     15,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passarrayanys_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:irM650Q4ZJ3aqx9pgLzoj5Delco") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
    }  //end for method passarrayanys

    {
     // for method passassortedanys

       iluException* passassortedanys_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     15,      // method index
                     CONST_CAST(iluCString, "passassortedanys"), // name
                     16,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     passassortedanys_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:irM650Q4ZJ3aqx9pgLzoj5Delco") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "inarg"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "inoutarg"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "outarg"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"));
    }  //end for method passassortedanys

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  foo_bar typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(foo_bar)::iluDeleteValue (void* pv_value) {
                foo_bar_ptr p_thevalue = (foo_bar_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(foo_bar)::iluDeepCopy (void* pv_value) {
                foo_bar_ptr p_thevalue = (foo_bar_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(foo_bar)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               foo_bar_ptr p_thevalue = (foo_bar_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(foo_bar)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, foo_bar::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(foo_bar)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           foo_bar_ptr p_object = (foo_bar_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If foo_bar were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == foo_bar::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(foo_bar)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           foo_bar_ptr p_object = (foo_bar_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for foo_bar
        const CORBA_TypeCode_ptr foo_tc_bar = new ILUCPP_TYPE_CODE_CLASS_NAME(foo_bar);

      // define the Any insertion and extraction operators for foo_bar

      void operator<<=(CORBA_Any& r_any, foo_bar_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(foo_tc_bar, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, foo_bar_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(foo_tc_bar)) { 
                 r_p_object = (foo_bar_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


  //////////////////////////////////////////////////////////////////////
  //  foo_optionalinteger any support

        // define the four member functions in typecode class for foo_optionalinteger
        ILUCPP_DEFINE_ILU_TYPE_CODE_DELETEVALUE(foo_optionalinteger, foo_optionalinteger_forany)
        ILUCPP_DEFINE_ILU_TYPE_CODE_DEEPCOPY(foo_optionalinteger, foo_optionalinteger_forany)
         CORBA_Boolean _ilu_foo_optionalinteger_TypeCode::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
                try {
                     foo_optionalinteger_forany* p_forany = (foo_optionalinteger_forany*)pv_value;
                    iluOptionalWrapper _p_thevalue(p_forany->m_p_value);
                    r_pickle_call += _p_thevalue;
                    if (p_forany->m_p_value) {
                        r_pickle_call += *(p_forany->m_p_value);
                     }
                     r_pickle_call.iluOutputPickle();
                     r_pickle_call << _p_thevalue;
                     if (p_forany->m_p_value) { 
                        r_pickle_call << *(p_forany->m_p_value);
                     }
            }
                catch (...) {return ILUCPP_FALSE;}
                return ILUCPP_TRUE;
        }
         void * _ilu_foo_optionalinteger_TypeCode::iluPickleToValue (
              iluPickleCall& r_pickle_call) {
                 foo_optionalinteger_forany* p_thevalue = new foo_optionalinteger_forany;
                try {
                        iluOptionalWrapper _the_opt_wrapper;
                        r_pickle_call >> _the_opt_wrapper;
                        if (_the_opt_wrapper.m_present) {
                       p_thevalue->m_p_value = new CORBA_Long;
                       r_pickle_call >> *(p_thevalue->m_p_value);
                        }
                        }
                        catch (...) { delete p_thevalue; return ILUCPP_NULL;}
                return p_thevalue;
        }

        // typecode instance for foo_optionalinteger
        const CORBA_TypeCode_ptr foo_tc_optionalinteger =
              new ILUCPP_TYPE_CODE_CLASS_NAME(foo_optionalinteger);

        // define the Any insertion and extraction operators for foo_optionalinteger
        ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(foo_optionalinteger_forany, foo_tc_optionalinteger)
        ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(foo_optionalinteger_forany, foo_tc_optionalinteger)
        ILUCPP_DEFINE_EXTRACTION_OPERATOR(foo_optionalinteger_forany, foo_tc_optionalinteger)

  // Support for use of optional objects in pickles/anys  

  // define the four member functions in typecode class for foo_optionalbarobject 
    ILUCPP_DEFINE_ILU_TYPE_CODE_DELETEVALUE(foo_optionalbarobject, foo_optionalbarobject_forany)
    ILUCPP_DEFINE_ILU_TYPE_CODE_DEEPCOPY(foo_optionalbarobject, foo_optionalbarobject_forany)

  void* ILUCPP_TYPE_CODE_CLASS_NAME(foo_optionalbarobject)::iluPickleToValue
        (iluPickleCall& r_pickle_call) {
                foo_optionalbarobject_forany* p_thevalue = new foo_optionalbarobject_forany;
                try {
                        iluOptionalWrapper _the_value_wrapper;
                        r_pickle_call >> _the_value_wrapper;
                        if (_the_value_wrapper.m_present) {
                                iluObjectWrapper _the_obj_wrapper(ILUCPP_FALSE,
 foo_bar::iluGetILUClassRecord());
                                r_pickle_call >> _the_obj_wrapper;
                                p_thevalue->m_p_value = (foo_bar_ptr)
_the_obj_wrapper.m_pv_iluobject;
                        }
                }
                catch (...) { delete p_thevalue; return ILUCPP_NULL;}
                return p_thevalue;
        }
 
  CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(foo_optionalbarobject)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
                iluOptionalWrapper opt_wrapper(((foo_optionalbarobject_forany*)pv_value)->m_p_value);
                foo_bar_ptr p_thevalue = ((foo_optionalbarobject_forany*) pv_value)->m_p_value;
                try {
                        r_pickle_call += opt_wrapper;
                        if (p_thevalue) {
                                iluObjectWrapper obj_wrapper(*p_thevalue, ILUCPP_FALSE);
                                r_pickle_call += obj_wrapper;
                                r_pickle_call.iluOutputPickle();
                                r_pickle_call << opt_wrapper;
                                r_pickle_call << obj_wrapper;
                        }
                        else {
                                r_pickle_call.iluOutputPickle();
                                r_pickle_call << opt_wrapper;
                        }
                }
                catch (...) {return ILUCPP_FALSE;}
                return ILUCPP_TRUE;
        }
        
  // typecode instance for foo_optionalbarobject
  const CORBA_TypeCode_ptr foo_tc_optionalbarobject =
          new ILUCPP_TYPE_CODE_CLASS_NAME(foo_optionalbarobject);
 
  // define the Any insertion and extraction operators for foo_optionalbarobject
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(foo_optionalbarobject_forany, foo_tc_optionalbarobject)
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(foo_optionalbarobject_forany, foo_tc_optionalbarobject)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(foo_optionalbarobject_forany, foo_tc_optionalbarobject)


/////////////////////////////////////////////////////////////////
// Exception implementations for locally-defined
// exceptions of interface foo 

/////////////////////////////////////////////////
// foo_zapexception member functions

  //constructor
  foo_zapexception::foo_zapexception(const foo_zapexception& a_zapexception) {
  _m_value = a_zapexception._m_value;
  }

  //destructor
  foo_zapexception::~foo_zapexception() {
  }

  // constructor with member value
  foo_zapexception::foo_zapexception(const CORBA_Long& value) {
    _m_value = value;
  }

  // assignment operator
  foo_zapexception& foo_zapexception::operator=(const foo_zapexception& a_zapexception) {
	_m_value = a_zapexception._m_value;
  return *this;
  }


////////////////////////////////////////////////////////////////
// Force initialization of foo_ classes upon load

foo_initializer foo_initializer::sm_the_foo_initializer;

foo_initializer:: foo_initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * foo_initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(foo_iluInitialize);
  return this;
}
