
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Unit-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members


  // list of initialization functions to call for the SRIO_Unit:: interface
  iluInitializationFunctionNode* SRIO_Unit::p_initialization_function_list;
  int SRIO_Unit::g_i_initialized;

  // holds the ilu class record for SRIO_Unit::General_Unit objects
  iluClass SRIO_Unit::General_Unit::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// SRIO_Unit initialization

  void SRIO_Unit::iluInitialize () {

      if ( g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // performs object type initialization
        SRIO_Unit::General_Unit::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "General-Unit-UnitInfo"),
            CONST_CAST( iluCString, "SRIO-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "uid"),     // field name
                CONST_CAST( iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "sbh"),     // field name
                CONST_CAST( iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv") // UID of field type
            );
        }

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "General-Unit"),
            CONST_CAST( iluCString, "SRIO-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit:1.0"),
            SRIO_Unit::General_Unit::iluGetILUClassRecord(), // object class
            &b_new_registration);

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "General-Unit-UnitMinorMode"),
            CONST_CAST( iluCString, "SRIO-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitMinorMode:1.0"),
            3,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "UMM-None"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "UMM-FW-Object"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "UMM-FW-Track"),  // element name
              2       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "General-Unit-UnitMode"),
            CONST_CAST( iluCString, "SRIO-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitMode:1.0"),
            3,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "UM-None"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "UM-Follow"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "UM-Imitate"),  // element name
              2       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "General-Unit-UnitRole"),
            CONST_CAST( iluCString, "SRIO-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitRole:1.0"),
            3,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "UR-Leader"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "UR-Follower"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "UR-None"),  // element name
              2       // integer value for element
        );
     }

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "General-Unit-UnitSBH"),
            CONST_CAST( iluCString, "SRIO-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitSBH:1.0"),
            CONST_CAST( iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "General-Unit-UnitID"),
            CONST_CAST( iluCString, "SRIO-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitID:1.0"),
            CONST_CAST( iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"),  //  base type
            &b_new_registration);

       }
#endif  // IIOP_PROTOCOL 

   g_i_initialized = 1;
 }

 // call all the surrogate and true initialization functions
 iluCppInternal::iluCallInitializationFunctions(&p_initialization_function_list);

}



//////////////////////////////////////////////////////////////////////
//  SRIO_Unit::General_Unit_var sizing, input and output operators

// note following three operators only needed
// if SRIO_Unit::General_Unit is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const SRIO_Unit::General_Unit_var& r_SRIO_Unit_General_Unit_var) {
         r_call += r_SRIO_Unit_General_Unit_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const SRIO_Unit::General_Unit_var& r_SRIO_Unit_General_Unit_var) {

      if (r_SRIO_Unit_General_Unit_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_SRIO_Unit_General_Unit_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_SRIO_Unit_General_Unit_var.iluSetWrapper(
           new iluObjectWrapper(
               r_SRIO_Unit_General_Unit_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_SRIO_Unit_General_Unit_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : SRIO_Unit::General_Unit::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_SRIO_Unit_General_Unit_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Unit::General_Unit_var& r_SRIO_Unit_General_Unit_var) {
	  
      SRIO_Unit::General_Unit_var temp_SRIO_Unit_General_Unit_var;
	  
     if (r_SRIO_Unit_General_Unit_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_SRIO_Unit_General_Unit_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_SRIO_Unit_General_Unit_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_SRIO_Unit_General_Unit_var = r_SRIO_Unit_General_Unit_var;

         // force a release since the var's in control of the refcount
         r_SRIO_Unit_General_Unit_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_SRIO_Unit_General_Unit_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, SRIO_Unit::General_Unit::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_SRIO_Unit_General_Unit_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_SRIO_Unit_General_Unit_var = (SRIO_Unit::General_Unit_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }


  // define the member functions in typecode class for SRIO_Unit::General_Unit::UnitMinorMode
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Unit_General_Unit_UnitMinorMode, SRIO_Unit::General_Unit::UnitMinorMode)

  // typecode instance for SRIO_Unit_General_Unit_UnitMinorMode
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_UnitMinorMode =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_UnitMinorMode);

  // define the Any insertion and extraction operators for SRIO_Unit::General_Unit::UnitMinorMode
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Unit::General_Unit::UnitMinorMode, SRIO_Unit::General_Unit::tc_UnitMinorMode)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Unit::General_Unit::UnitMinorMode, SRIO_Unit::General_Unit::tc_UnitMinorMode)

  // define the member functions in typecode class for SRIO_Unit::General_Unit::UnitMode
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Unit_General_Unit_UnitMode, SRIO_Unit::General_Unit::UnitMode)

  // typecode instance for SRIO_Unit_General_Unit_UnitMode
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_UnitMode =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_UnitMode);

  // define the Any insertion and extraction operators for SRIO_Unit::General_Unit::UnitMode
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Unit::General_Unit::UnitMode, SRIO_Unit::General_Unit::tc_UnitMode)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Unit::General_Unit::UnitMode, SRIO_Unit::General_Unit::tc_UnitMode)

  // define the member functions in typecode class for SRIO_Unit::General_Unit::UnitRole
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Unit_General_Unit_UnitRole, SRIO_Unit::General_Unit::UnitRole)

  // typecode instance for SRIO_Unit_General_Unit_UnitRole
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_UnitRole =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_UnitRole);

  // define the Any insertion and extraction operators for SRIO_Unit::General_Unit::UnitRole
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Unit::General_Unit::UnitRole, SRIO_Unit::General_Unit::tc_UnitRole)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Unit::General_Unit::UnitRole, SRIO_Unit::General_Unit::tc_UnitRole)


/////////////////////////////////////////////////////////////////////
//  SRIO_Unit::General_Unit::UnitInfo members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Unit::General_Unit::UnitInfo::UnitInfo() {
uid = CORBA_(String_var());  // iffy sunpro workaround
sbh = CORBA_(String_var());  // iffy sunpro workaround
  }

  // copy constructor
  SRIO_Unit::General_Unit::UnitInfo::UnitInfo(const SRIO_Unit::General_Unit::UnitInfo& r_a_UnitInfo) {
          uid = r_a_UnitInfo.uid;
          sbh = r_a_UnitInfo.sbh;
   }

  // destructor
  SRIO_Unit::General_Unit::UnitInfo::~UnitInfo() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Unit::General_Unit::UnitInfo& SRIO_Unit::General_Unit::UnitInfo::self(){
        return *this;
  }

  // assignment operator
  SRIO_Unit::General_Unit::UnitInfo& SRIO_Unit::General_Unit::UnitInfo::operator=(
       const SRIO_Unit::General_Unit::UnitInfo& r_a_UnitInfo) {
          if (this != &r_a_UnitInfo) {
          uid = r_a_UnitInfo.uid;
          sbh = r_a_UnitInfo.sbh;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::UnitInfo

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Unit::General_Unit::UnitInfo& r_SRIO_Unit_General_Unit_UnitInfo)  {

         r_call += iluSizeRecord;
         iluCardinal r_uid_length =
             strlen(r_SRIO_Unit_General_Unit_UnitInfo.uid.iluStringVarReference());
          iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Unit_General_Unit_UnitInfo.uid).iluStringVarReference(),
                  r_uid_length);
         r_call += _r_uid_wrap;
         iluCardinal r_sbh_length =
             strlen(r_SRIO_Unit_General_Unit_UnitInfo.sbh.iluStringVarReference());
          iluCStringWrapper _r_sbh_wrap(
                 (r_SRIO_Unit_General_Unit_UnitInfo.sbh).iluStringVarReference(),
                  r_sbh_length);
         r_call += _r_sbh_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Unit::General_Unit::UnitInfo& r_SRIO_Unit_General_Unit_UnitInfo)  {

         r_call << iluOutputRecord;
         iluCardinal r_uid_length =
             strlen(r_SRIO_Unit_General_Unit_UnitInfo.uid.iluStringVarReference());
          iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Unit_General_Unit_UnitInfo.uid).iluStringVarReference(),
                  r_uid_length);
         r_call << _r_uid_wrap;
         iluCardinal r_sbh_length =
             strlen(r_SRIO_Unit_General_Unit_UnitInfo.sbh.iluStringVarReference());
          iluCStringWrapper _r_sbh_wrap(
                 (r_SRIO_Unit_General_Unit_UnitInfo.sbh).iluStringVarReference(),
                  r_sbh_length);
         r_call << _r_sbh_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Unit::General_Unit::UnitInfo& r_SRIO_Unit_General_Unit_UnitInfo)  {

         r_call >> iluInputRecord;
         iluCardinal r_uid_length;
         iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Unit_General_Unit_UnitInfo.uid).iluStringVarReference(),
                  r_uid_length);
         r_call >> _r_uid_wrap;
         iluCardinal r_sbh_length;
         iluCStringWrapper _r_sbh_wrap(
                 (r_SRIO_Unit_General_Unit_UnitInfo.sbh).iluStringVarReference(),
                  r_sbh_length);
         r_call >> _r_sbh_wrap;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Unit::General_Unit::UnitInfo
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Unit_General_Unit_UnitInfo, SRIO_Unit::General_Unit::UnitInfo)

  // typecode instance for SRIO_Unit_General_Unit_UnitInfo
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_UnitInfo =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_UnitInfo);

  // define the Any insert and extract operators for SRIO_Unit::General_Unit::UnitInfo 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitInfo, SRIO_Unit::General_Unit::tc_UnitInfo)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitInfo, SRIO_Unit::General_Unit::tc_UnitInfo)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitInfo, SRIO_Unit::General_Unit::tc_UnitInfo)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Unit::General_Unit::UnitInfoSequence members   

 // constructors & destructor
  SRIO_Unit::General_Unit::UnitInfoSequence::UnitInfoSequence () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Unit::General_Unit::UnitInfoSequence::UnitInfoSequence (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Unit::General_Unit::UnitInfoSequence::UnitInfoSequence (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Unit::General_Unit::UnitInfo* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Unit::General_Unit::UnitInfoSequence::~UnitInfoSequence() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Unit::General_Unit::UnitInfoSequence::UnitInfoSequence (const SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence)
  :
         m_maximum(r_SRIO_Unit_General_Unit_UnitInfoSequence.m_maximum),
         m_length(r_SRIO_Unit_General_Unit_UnitInfoSequence.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Unit_General_Unit_UnitInfoSequence.m_buffer[index];
            }
   }

 // assignment
   SRIO_Unit::General_Unit::UnitInfoSequence& SRIO_Unit::General_Unit::UnitInfoSequence::operator= (const SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence) {
         if (this == &r_SRIO_Unit_General_Unit_UnitInfoSequence) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Unit_General_Unit_UnitInfoSequence.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Unit_General_Unit_UnitInfoSequence.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Unit_General_Unit_UnitInfoSequence.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Unit::General_Unit::UnitInfo* SRIO_Unit::General_Unit::UnitInfoSequence::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Unit::General_Unit::UnitInfo[num_elements]) : NULL);
  }
  
  void SRIO_Unit::General_Unit::UnitInfoSequence::freebuf(SRIO_Unit::General_Unit::UnitInfo* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Unit::General_Unit::UnitInfoSequence::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Unit::General_Unit::UnitInfo* p_oldbuf = m_buffer;
                 CORBA_(ULong) oldlen = m_length;
                 CORBA_(Boolean) b_oldrelease = m_release;
                 m_release = ILUCPP_TRUE;
                 m_length = len;
                 m_maximum = len;
                 m_buffer = allocbuf(m_length);
                 for (CORBA_(ULong) index = 0; index < oldlen; index++) {
                     m_buffer[index] = p_oldbuf[index];
                 }
                if (b_oldrelease)
                   freebuf(p_oldbuf);
                } 
  }
  
 // accessors
   CORBA_(ULong) SRIO_Unit::General_Unit::UnitInfoSequence::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Unit::General_Unit::UnitInfoSequence::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Unit::General_Unit::UnitInfoSequence::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Unit::General_Unit::UnitInfo* SRIO_Unit::General_Unit::UnitInfoSequence::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Unit::General_Unit::UnitInfo const* SRIO_Unit::General_Unit::UnitInfoSequence::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Unit::General_Unit::UnitInfo& SRIO_Unit::General_Unit::UnitInfoSequence::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Unit::General_Unit::UnitInfo& SRIO_Unit::General_Unit::UnitInfoSequence::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Unit::General_Unit::UnitInfo *_temp = 
              (const SRIO_Unit::General_Unit::UnitInfo *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Unit::General_Unit::UnitInfoSequence& SRIO_Unit::General_Unit::UnitInfoSequence::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::UnitInfoSequence

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_UnitInfoSequence.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_UnitInfoSequence(card_length);
        r_call += _r_SRIO_Unit_General_Unit_UnitInfoSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_UnitInfoSequence.length(); index++) {
          r_call += r_SRIO_Unit_General_Unit_UnitInfoSequence[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_UnitInfoSequence.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_UnitInfoSequence(card_length);
        r_call << _r_SRIO_Unit_General_Unit_UnitInfoSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_UnitInfoSequence.length(); index++) {
          r_call << r_SRIO_Unit_General_Unit_UnitInfoSequence[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Unit::General_Unit::UnitInfoSequence _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Unit_General_Unit_UnitInfoSequence = SRIO_Unit::General_Unit::UnitInfoSequence(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Unit::General_Unit::UnitInfoSequence
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Unit_General_Unit_UnitInfoSequence, SRIO_Unit::General_Unit::UnitInfoSequence)

  // typecode instance for SRIO_Unit_General_Unit_UnitInfoSequence
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_UnitInfoSequence =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_UnitInfoSequence);

  // define the Any insert and extract operators for SRIO_Unit::General_Unit::UnitInfoSequence 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitInfoSequence, SRIO_Unit::General_Unit::tc_UnitInfoSequence)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitInfoSequence, SRIO_Unit::General_Unit::tc_UnitInfoSequence)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitInfoSequence, SRIO_Unit::General_Unit::tc_UnitInfoSequence)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Unit::General_Unit::FloatSeq members   

 // constructors & destructor
  SRIO_Unit::General_Unit::FloatSeq::FloatSeq () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Unit::General_Unit::FloatSeq::FloatSeq (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Unit::General_Unit::FloatSeq::FloatSeq (CORBA_(ULong) max , CORBA_(ULong) length, 
          CORBA_(Float)* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Unit::General_Unit::FloatSeq::~FloatSeq() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Unit::General_Unit::FloatSeq::FloatSeq (const SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq)
  :
         m_maximum(r_SRIO_Unit_General_Unit_FloatSeq.m_maximum),
         m_length(r_SRIO_Unit_General_Unit_FloatSeq.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Unit_General_Unit_FloatSeq.m_buffer[index];
            }
   }

 // assignment
   SRIO_Unit::General_Unit::FloatSeq& SRIO_Unit::General_Unit::FloatSeq::operator= (const SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq) {
         if (this == &r_SRIO_Unit_General_Unit_FloatSeq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Unit_General_Unit_FloatSeq.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Unit_General_Unit_FloatSeq.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Unit_General_Unit_FloatSeq.m_buffer[index];
          }
          return *this;
       }

  // memory management
  CORBA_(Float)* SRIO_Unit::General_Unit::FloatSeq::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new CORBA_(Float)[num_elements]) : NULL);
  }
  
  void SRIO_Unit::General_Unit::FloatSeq::freebuf(CORBA_(Float)* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Unit::General_Unit::FloatSeq::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 CORBA_(Float)* p_oldbuf = m_buffer;
                 CORBA_(ULong) oldlen = m_length;
                 CORBA_(Boolean) b_oldrelease = m_release;
                 m_release = ILUCPP_TRUE;
                 m_length = len;
                 m_maximum = len;
                 m_buffer = allocbuf(m_length);
                 for (CORBA_(ULong) index = 0; index < oldlen; index++) {
                     m_buffer[index] = p_oldbuf[index];
                 }
                if (b_oldrelease)
                   freebuf(p_oldbuf);
                } 
  }
  
 // accessors
   CORBA_(ULong) SRIO_Unit::General_Unit::FloatSeq::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Unit::General_Unit::FloatSeq::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Unit::General_Unit::FloatSeq::release() const{
    return m_release;
  }
  
  // buffer accessors
  CORBA_(Float)* SRIO_Unit::General_Unit::FloatSeq::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  CORBA_(Float) const* SRIO_Unit::General_Unit::FloatSeq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  CORBA_(Float)& SRIO_Unit::General_Unit::FloatSeq::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const CORBA_(Float)& SRIO_Unit::General_Unit::FloatSeq::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const CORBA_(Float) *_temp = 
              (const CORBA_(Float) *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Unit::General_Unit::FloatSeq& SRIO_Unit::General_Unit::FloatSeq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::FloatSeq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_FloatSeq.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_FloatSeq(card_length);
        r_call += _r_SRIO_Unit_General_Unit_FloatSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_FloatSeq.length(); index++) {
          r_call += r_SRIO_Unit_General_Unit_FloatSeq[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_FloatSeq.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_FloatSeq(card_length);
        r_call << _r_SRIO_Unit_General_Unit_FloatSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_FloatSeq.length(); index++) {
          r_call << r_SRIO_Unit_General_Unit_FloatSeq[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Unit::General_Unit::FloatSeq _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Unit_General_Unit_FloatSeq = SRIO_Unit::General_Unit::FloatSeq(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Unit::General_Unit::FloatSeq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Unit_General_Unit_FloatSeq, SRIO_Unit::General_Unit::FloatSeq)

  // typecode instance for SRIO_Unit_General_Unit_FloatSeq
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_FloatSeq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_FloatSeq);

  // define the Any insert and extract operators for SRIO_Unit::General_Unit::FloatSeq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::FloatSeq, SRIO_Unit::General_Unit::tc_FloatSeq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::FloatSeq, SRIO_Unit::General_Unit::tc_FloatSeq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Unit::General_Unit::FloatSeq, SRIO_Unit::General_Unit::tc_FloatSeq)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Unit::General_Unit::ShortSeq members   

 // constructors & destructor
  SRIO_Unit::General_Unit::ShortSeq::ShortSeq () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Unit::General_Unit::ShortSeq::ShortSeq (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Unit::General_Unit::ShortSeq::ShortSeq (CORBA_(ULong) max , CORBA_(ULong) length, 
          CORBA_(Short)* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Unit::General_Unit::ShortSeq::~ShortSeq() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Unit::General_Unit::ShortSeq::ShortSeq (const SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq)
  :
         m_maximum(r_SRIO_Unit_General_Unit_ShortSeq.m_maximum),
         m_length(r_SRIO_Unit_General_Unit_ShortSeq.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Unit_General_Unit_ShortSeq.m_buffer[index];
            }
   }

 // assignment
   SRIO_Unit::General_Unit::ShortSeq& SRIO_Unit::General_Unit::ShortSeq::operator= (const SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq) {
         if (this == &r_SRIO_Unit_General_Unit_ShortSeq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Unit_General_Unit_ShortSeq.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Unit_General_Unit_ShortSeq.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Unit_General_Unit_ShortSeq.m_buffer[index];
          }
          return *this;
       }

  // memory management
  CORBA_(Short)* SRIO_Unit::General_Unit::ShortSeq::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new CORBA_(Short)[num_elements]) : NULL);
  }
  
  void SRIO_Unit::General_Unit::ShortSeq::freebuf(CORBA_(Short)* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Unit::General_Unit::ShortSeq::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 CORBA_(Short)* p_oldbuf = m_buffer;
                 CORBA_(ULong) oldlen = m_length;
                 CORBA_(Boolean) b_oldrelease = m_release;
                 m_release = ILUCPP_TRUE;
                 m_length = len;
                 m_maximum = len;
                 m_buffer = allocbuf(m_length);
                 for (CORBA_(ULong) index = 0; index < oldlen; index++) {
                     m_buffer[index] = p_oldbuf[index];
                 }
                if (b_oldrelease)
                   freebuf(p_oldbuf);
                } 
  }
  
 // accessors
   CORBA_(ULong) SRIO_Unit::General_Unit::ShortSeq::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Unit::General_Unit::ShortSeq::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Unit::General_Unit::ShortSeq::release() const{
    return m_release;
  }
  
  // buffer accessors
  CORBA_(Short)* SRIO_Unit::General_Unit::ShortSeq::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  CORBA_(Short) const* SRIO_Unit::General_Unit::ShortSeq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  CORBA_(Short)& SRIO_Unit::General_Unit::ShortSeq::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const CORBA_(Short)& SRIO_Unit::General_Unit::ShortSeq::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const CORBA_(Short) *_temp = 
              (const CORBA_(Short) *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Unit::General_Unit::ShortSeq& SRIO_Unit::General_Unit::ShortSeq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::ShortSeq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_ShortSeq.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_ShortSeq(card_length);
        r_call += _r_SRIO_Unit_General_Unit_ShortSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_ShortSeq.length(); index++) {
          r_call += r_SRIO_Unit_General_Unit_ShortSeq[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_ShortSeq.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_ShortSeq(card_length);
        r_call << _r_SRIO_Unit_General_Unit_ShortSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_ShortSeq.length(); index++) {
          r_call << r_SRIO_Unit_General_Unit_ShortSeq[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Unit::General_Unit::ShortSeq _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Unit_General_Unit_ShortSeq = SRIO_Unit::General_Unit::ShortSeq(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Unit::General_Unit::ShortSeq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Unit_General_Unit_ShortSeq, SRIO_Unit::General_Unit::ShortSeq)

  // typecode instance for SRIO_Unit_General_Unit_ShortSeq
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_ShortSeq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_ShortSeq);

  // define the Any insert and extract operators for SRIO_Unit::General_Unit::ShortSeq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::ShortSeq, SRIO_Unit::General_Unit::tc_ShortSeq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::ShortSeq, SRIO_Unit::General_Unit::tc_ShortSeq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Unit::General_Unit::ShortSeq, SRIO_Unit::General_Unit::tc_ShortSeq)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Unit::General_Unit::UnitIDSeq members   

 // constructors & destructor
  SRIO_Unit::General_Unit::UnitIDSeq::UnitIDSeq () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Unit::General_Unit::UnitIDSeq::UnitIDSeq (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE) {
             m_buffer = allocbuf (m_maximum);
             m_varbuffer = new CORBA_(String_var)[m_maximum];
  }

  SRIO_Unit::General_Unit::UnitIDSeq::UnitIDSeq (CORBA_(ULong) max , CORBA_(ULong) length, 
        iluShortCharacter** data, CORBA_(Boolean) release)  : m_maximum(max),
        m_length(length),
        m_release (release), 
        m_buffer(data) {

        m_varbuffer = new CORBA_(String_var)[max];
        for (CORBA_(ULong) index = 0; index < max; index++) {
            (m_varbuffer[index]).iluSetRelease(m_release);
             m_varbuffer[index] = (data[index]);
        }	  
  }

  SRIO_Unit::General_Unit::UnitIDSeq::UnitIDSeq (const SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq)   :
         m_maximum(r_SRIO_Unit_General_Unit_UnitIDSeq.m_maximum), 
         m_length(r_SRIO_Unit_General_Unit_UnitIDSeq.m_length), 
         m_release(ILUCPP_TRUE) 
         {
            m_buffer = allocbuf (m_maximum);
            m_varbuffer = new CORBA_(String_var)[m_length];
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Unit_General_Unit_UnitIDSeq.m_buffer[index];
               m_varbuffer[index] = r_SRIO_Unit_General_Unit_UnitIDSeq.m_varbuffer[index];
            } 
   }
		
  SRIO_Unit::General_Unit::UnitIDSeq::~UnitIDSeq() {
        if (m_buffer && m_release)
           freebuf (m_buffer);
        if(m_length > 0)
           delete [] m_varbuffer;
  }

 // assignment
   SRIO_Unit::General_Unit::UnitIDSeq& SRIO_Unit::General_Unit::UnitIDSeq::operator= (const SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq) {
         if (this == &r_SRIO_Unit_General_Unit_UnitIDSeq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         if (m_length > 0)  
              delete [] m_varbuffer;
          m_buffer = allocbuf (r_SRIO_Unit_General_Unit_UnitIDSeq.m_maximum);
        m_varbuffer = new CORBA_(String_var)[r_SRIO_Unit_General_Unit_UnitIDSeq.m_length];

#if (defined(OLDGNUC_WORKAROUND) || defined (_MSC_VER))
         // for some reason GNUC does not allow m_length set before copy
         // and/or doesn't allow m_length to govern iteration 
        // experimentally moved  then should consolidate 
         // and check if also solves object version of problem
          for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_UnitIDSeq.m_length;
              index++) {
               m_buffer[index] = r_SRIO_Unit_General_Unit_UnitIDSeq.m_buffer[index];
               m_varbuffer[index] = r_SRIO_Unit_General_Unit_UnitIDSeq.m_varbuffer[index];
       }
          m_release = ILUCPP_TRUE;
          m_length = r_SRIO_Unit_General_Unit_UnitIDSeq.m_length;
          m_maximum = r_SRIO_Unit_General_Unit_UnitIDSeq.m_maximum;
#else
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Unit_General_Unit_UnitIDSeq.m_length;
         m_maximum = r_SRIO_Unit_General_Unit_UnitIDSeq.m_maximum;
        for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Unit_General_Unit_UnitIDSeq.m_buffer[index];
               m_varbuffer[index] = r_SRIO_Unit_General_Unit_UnitIDSeq.m_varbuffer[index];
         } 
#endif
        return *this;
  }

  // memory management
  iluShortCharacter** SRIO_Unit::General_Unit::UnitIDSeq::allocbuf(CORBA_(ULong) num_elements) {
       if (num_elements > 0) {
          iluShortCharacter** p_new_buffer =
                new iluShortCharacter* [num_elements];
          for (CORBA_(ULong) ul_index = 0; ul_index < num_elements; ul_index++)
             p_new_buffer[ul_index] = *(new iluShortCharacter*);
          return p_new_buffer;
        }
        else return ILUCPP_NULL;
  }
  
  void SRIO_Unit::General_Unit::UnitIDSeq::freebuf(iluShortCharacter** p_buf) {
        delete [] p_buf;
  }

   void SRIO_Unit::General_Unit::UnitIDSeq::length (CORBA_(ULong) len) {
         if (len <= m_maximum) {
             for (CORBA_(ULong) index = len; index < m_length; index++) {
                 // attempt to NULL, not sure correct 
                 m_buffer[index] = *(new iluShortCharacter*);
             }
             m_length = len;
           }
          else {
                 iluShortCharacter** p_oldbuf = m_buffer;
                 CORBA_(String_var)* p_oldbufvar = m_varbuffer;

                 CORBA_(ULong) oldlen = m_length;
                 CORBA_(Boolean) b_oldrelease = m_release;
                 m_release = ILUCPP_TRUE;
                 m_length = len;
                 m_maximum = len;
                 m_buffer = allocbuf(m_length);
                 m_varbuffer = new CORBA_(String_var)[m_length];
                 for (CORBA_(ULong) index = 0; index < oldlen; index++) {
                     m_buffer[index] = p_oldbuf[index];
                     m_varbuffer[index] = p_oldbufvar[index];
                 }
                if (b_oldrelease) {
                   freebuf(p_oldbuf);
                 if(oldlen > 0)
                   delete [] p_oldbufvar; 
                }
         }
  }
  
 // accessors
   CORBA_(ULong) SRIO_Unit::General_Unit::UnitIDSeq::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Unit::General_Unit::UnitIDSeq::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Unit::General_Unit::UnitIDSeq::release() const{
    return m_release;
  }
  
  // buffer accessors
  iluShortCharacter** SRIO_Unit::General_Unit::UnitIDSeq::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  iluShortCharacter* const* SRIO_Unit::General_Unit::UnitIDSeq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  CORBA_(String_var)& SRIO_Unit::General_Unit::UnitIDSeq::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_varbuffer[index];
  }
  
  const CORBA_(String_var)& SRIO_Unit::General_Unit::UnitIDSeq::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const CORBA_(String_var) *_temp = 
              (const CORBA_(String_var) *) &m_varbuffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Unit::General_Unit::UnitIDSeq& SRIO_Unit::General_Unit::UnitIDSeq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::UnitIDSeq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_UnitIDSeq.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_UnitIDSeq(card_length);
        r_call += _r_SRIO_Unit_General_Unit_UnitIDSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_UnitIDSeq.length(); index++) {
          iluCardinal s_element_length =
              strlen(r_SRIO_Unit_General_Unit_UnitIDSeq[index].iluStringVarReference());
          iluCStringWrapper  s_element(
            r_SRIO_Unit_General_Unit_UnitIDSeq[index].iluStringVarReference(), s_element_length);
          r_call += s_element; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq){

        iluCardinal card_length = r_SRIO_Unit_General_Unit_UnitIDSeq.length();
        iluSequenceWrapper _r_SRIO_Unit_General_Unit_UnitIDSeq(card_length);
        r_call << _r_SRIO_Unit_General_Unit_UnitIDSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Unit_General_Unit_UnitIDSeq.length(); index++) {
          iluCardinal s_element_length =
              strlen(r_SRIO_Unit_General_Unit_UnitIDSeq[index].iluStringVarReference());
          iluCStringWrapper  s_element(
            r_SRIO_Unit_General_Unit_UnitIDSeq[index].iluStringVarReference(), s_element_length);
          r_call << s_element; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Unit::General_Unit::UnitIDSeq _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          iluCardinal s_element_length;
          iluCStringWrapper  s_element(
            _seq_temp[index].iluStringVarReference(), s_element_length);
          r_call >> s_element; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Unit_General_Unit_UnitIDSeq = SRIO_Unit::General_Unit::UnitIDSeq(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Unit::General_Unit::UnitIDSeq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Unit_General_Unit_UnitIDSeq, SRIO_Unit::General_Unit::UnitIDSeq)

  // typecode instance for SRIO_Unit_General_Unit_UnitIDSeq
  const CORBA_(TypeCode_ptr) SRIO_Unit::General_Unit::tc_UnitIDSeq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit_UnitIDSeq);

  // define the Any insert and extract operators for SRIO_Unit::General_Unit::UnitIDSeq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitIDSeq, SRIO_Unit::General_Unit::tc_UnitIDSeq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitIDSeq, SRIO_Unit::General_Unit::tc_UnitIDSeq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Unit::General_Unit::UnitIDSeq, SRIO_Unit::General_Unit::tc_UnitIDSeq)

  //////////////////////////////////////////////////////////////////////
  // SRIO_Unit::General_Unit members

  // CORBA object reference operations

  SRIO_Unit::General_Unit_ptr SRIO_Unit::General_Unit::_duplicate( General_Unit_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  SRIO_Unit::General_Unit_ptr SRIO_Unit::General_Unit::_nil() {
    return (General_Unit_ptr) NULL;
  }

  // default constructor
  SRIO_Unit::General_Unit::General_Unit() {
     // to be determined
  }

  // destructor
  SRIO_Unit::General_Unit::~General_Unit() {
    // to be determined
  }

  // copy constructor
  SRIO_Unit::General_Unit::General_Unit(const General_Unit&) {
    // to be determined
  }

  // assignment operator
  void SRIO_Unit::General_Unit::operator=(const General_Unit&) {
    // to be determined
  }

  // Simple Object Lookup
  SRIO_Unit::General_Unit_ptr SRIO_Unit::General_Unit::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (General_Unit_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
//  void *SRIO_Unit::General_Unit::iluDowncast (iluClass class_to_cast_down_to) {
//    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
//      return((void *)((iluObject*) this));
//    if (class_to_cast_down_to == CORBA::Object::iluGetILUClassRecord())
//       return((void *) ((CORBA_(Object_ptr)) this));
//    if (class_to_cast_down_to == m_ILUClassRecord)
//      return ((void*) this);
//    return (NULL);
//  }

  void* SRIO_Unit::General_Unit::iluDowncast(iluClass class_to_cast_down_to) {
      if (!class_to_cast_down_to || class_to_cast_down_to == ilu_rootClass)
          return static_cast<void*>(static_cast<iluObject*>(this));

      if (class_to_cast_down_to == CORBA_(Object)::iluGetILUClassRecord())
          return static_cast<void*>(static_cast<CORBA_(Object_ptr)>(this));

      if (class_to_cast_down_to == m_ILUClassRecord)
          return static_cast<void*>(this);

      return nullptr;
  }


  // initialize to use of this class of objects - called by iluInitialize

  void SRIO_Unit::General_Unit::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "IDL:omg.org/CORBA/Object:1.0"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "SRIO_Unit.General-Unit"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit:1.0"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_TRUE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      14,          // number of methods
      1,          // number of superclasses
      _superclasses
   );

    {
     // for method getID

       iluException* getID_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "getID"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getID_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv") // return type ID
        );
    }  //end for method getID

    {
     // for method getCosNamingSBH

       iluException* getCosNamingSBH_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "getCosNamingSBH"), // name
                     2,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getCosNamingSBH_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv") // return type ID
        );
    }  //end for method getCosNamingSBH

    {
     // for method getFrontUnitInfo

       iluException* getFrontUnitInfo_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     2,      // method index
                     CONST_CAST(iluCString, "getFrontUnitInfo"), // name
                     3,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getFrontUnitInfo_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Unit/General_Unit/UnitInfo:1.0") // return type ID
        );
    }  //end for method getFrontUnitInfo

    {
     // for method setRole

       iluException* setRole_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     3,      // method index
                     CONST_CAST(iluCString, "setRole"), // name
                     4,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setRole_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "role"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitRole:1.0"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "consoleSBH"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method setRole

    {
     // for method setMode

       iluException* setMode_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     4,      // method index
                     CONST_CAST(iluCString, "setMode"), // name
                     5,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setMode_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "mode"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitMode:1.0"));
    }  //end for method setMode

    {
     // for method setMinorMode

       iluException* setMinorMode_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     5,      // method index
                     CONST_CAST(iluCString, "setMinorMode"), // name
                     6,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setMinorMode_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "minorMode"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitMinorMode:1.0"));
    }  //end for method setMinorMode

    {
     // for method setALeader

       iluException* setALeader_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     6,      // method index
                     CONST_CAST(iluCString, "setALeader"), // name
                     7,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setALeader_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "leaderSBH"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method setALeader

    {
     // for method registerFollower

       iluException* registerFollower_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     7,      // method index
                     CONST_CAST(iluCString, "registerFollower"), // name
                     8,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     registerFollower_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "followerUID"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "followerSBH"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method registerFollower

    {
     // for method unregisterFollower

       iluException* unregisterFollower_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     8,      // method index
                     CONST_CAST(iluCString, "unregisterFollower"), // name
                     9,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     unregisterFollower_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "followerUID"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method unregisterFollower

    {
     // for method addRearVehicle

       iluException* addRearVehicle_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     9,      // method index
                     CONST_CAST(iluCString, "addRearVehicle"), // name
                     10,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     addRearVehicle_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "rearInfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method addRearVehicle

    {
     // for method deleteRearVehicle

       iluException* deleteRearVehicle_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     10,      // method index
                     CONST_CAST(iluCString, "deleteRearVehicle"), // name
                     11,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     deleteRearVehicle_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method deleteRearVehicle

    {
     // for method reportDeadVehicle

       iluException* reportDeadVehicle_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     11,      // method index
                     CONST_CAST(iluCString, "reportDeadVehicle"), // name
                     12,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     reportDeadVehicle_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "details"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method reportDeadVehicle

    {
     // for method shutDown

       iluException* shutDown_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     12,      // method index
                     CONST_CAST(iluCString, "shutDown"), // name
                     13,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     shutDown_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method shutDown

    {
     // for method takePicture

       iluException* takePicture_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     13,      // method index
                     CONST_CAST(iluCString, "takePicture"), // name
                     14,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     takePicture_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "time"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "procedureStartTime"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
    }  //end for method takePicture

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  SRIO_Unit::General_Unit typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit)::iluDeleteValue (void* pv_value) {
                SRIO_Unit::General_Unit_ptr p_thevalue = (SRIO_Unit::General_Unit_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit)::iluDeepCopy (void* pv_value) {
                SRIO_Unit::General_Unit_ptr p_thevalue = (SRIO_Unit::General_Unit_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_(Boolean) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               SRIO_Unit::General_Unit_ptr p_thevalue = (SRIO_Unit::General_Unit_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, SRIO_Unit::General_Unit::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           SRIO_Unit::General_Unit_ptr p_object = (SRIO_Unit::General_Unit_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If SRIO_Unit::General_Unit were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA::Object::iluGetILUClassRecord())
           //    return ((CORBA::Object_ptr)p_object);
           if (casttoclass == SRIO_Unit::General_Unit::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


//      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
//           SRIO_Unit::General_Unit_ptr p_object = (SRIO_Unit::General_Unit_ptr) p_an_object_of_your_type;
//           return CORBA::TypeCode::LookupTypeCode(p_object->iluClassId());
//      }

      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit)::iluMostSpecificTypeCode(void* p_an_object_of_your_type) {
          if (!p_an_object_of_your_type) return nullptr;
          SRIO_Unit::General_Unit_ptr p_object = static_cast<SRIO_Unit::General_Unit_ptr>(p_an_object_of_your_type);
          return CORBA_(TypeCode)::LookupTypeCode(p_object->iluClassId());
      }

        // typecode instance for SRIO_Unit::General_Unit
        const CORBA_(TypeCode_ptr) SRIO_Unit::tc_General_Unit = new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Unit_General_Unit);

      // define the Any insertion and extraction operators for SRIO_Unit::General_Unit

      void operator<<=(CORBA_(Any)& r_any, SRIO_Unit::General_Unit_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(SRIO_Unit::tc_General_Unit, p_object, ILUCPP_TRUE);
      }

      CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Unit::General_Unit_ptr& r_p_object) {

          CORBA_(Any)* p_nc_any = CONST_CAST(CORBA_(Any)*, &r_any);

          if (p_nc_any->iluGetFromPickle(SRIO_Unit::tc_General_Unit)) { 
                 r_p_object = (SRIO_Unit::General_Unit_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


////////////////////////////////////////////////////////////////
// Force initialization of SRIO_Unit:: classes upon load

SRIO_Unit::initializer SRIO_Unit::initializer::sm_the_SRIO_Unit_initializer;

SRIO_Unit::initializer:: initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * SRIO_Unit::initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(SRIO_Unit::iluInitialize);
  return this;
}
