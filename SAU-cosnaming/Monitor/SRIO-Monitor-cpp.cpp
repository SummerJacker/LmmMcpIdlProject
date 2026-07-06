
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Monitor-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members


  // list of initialization functions to call for the SRIO_Monitor:: interface
  iluInitializationFunctionNode* SRIO_Monitor::p_initialization_function_list;
  int SRIO_Monitor::g_i_initialized;

  // holds the ilu class record for SRIO_Monitor::Monitor objects
  iluClass SRIO_Monitor::Monitor::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// SRIO_Monitor initialization

  void SRIO_Monitor::iluInitialize () {

      if ( g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // performs object type initialization
        SRIO_Monitor::Monitor::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Monitor-CurrentUnitInfo"),
             CONST_CAST( iluCString, "SRIO-Monitor"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/CurrentUnitInfo:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/UnitType:1.0"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "groundUnitInfo"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/GroundUnitInfo:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "UnitGroundType");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "airUnitInfo"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/AirUnitInfo:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "UnitAirType");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Monitor-PictureInfo"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/PictureInfo:1.0"),
            4, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "picturName"),     // field name
                CONST_CAST( iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "pic"),     // field name
                CONST_CAST( iluCString, "ilut:ndKwf8vfmBTV3Mjc04YR0a3tZcA") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "cui"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/CurrentUnitInfo:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                3,     // which field
                CONST_CAST( iluCString, "responseTime"),     // field name
                CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Monitor-CompleteUnitInfo"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/CompleteUnitInfo:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "us"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/UnitState:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "cui"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/CurrentUnitInfo:1.0") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Monitor-UnitState"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/UnitState:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "health"),     // field name
                CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "battery"),     // field name
                CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // UID of field type
            );
        }

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "Monitor"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor:1.0"),
            SRIO_Monitor::Monitor::iluGetILUClassRecord(), // object class
            &b_new_registration);

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Monitor-MissionSituation"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/MissionSituation:1.0"),
            4,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "Success"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "StillBurning"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "Locating"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "Processing"),  // element name
              3       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Monitor-BackHomeReason"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/BackHomeReason:1.0"),
            2,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "LowBattery"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "EmptyLoad"),  // element name
              1       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Monitor-UnitType"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/UnitType:1.0"),
            2,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "UnitGroundType"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "UnitAirType"),  // element name
              1       // integer value for element
        );
     }

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "Monitor-FireID"),
            CONST_CAST( iluCString, "SRIO-Monitor"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor/FireID:1.0"),
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
//  SRIO_Monitor::Monitor_var sizing, input and output operators

// note following three operators only needed
// if SRIO_Monitor::Monitor is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const SRIO_Monitor::Monitor_var& r_SRIO_Monitor_Monitor_var) {
         r_call += r_SRIO_Monitor_Monitor_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const SRIO_Monitor::Monitor_var& r_SRIO_Monitor_Monitor_var) {

      if (r_SRIO_Monitor_Monitor_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_SRIO_Monitor_Monitor_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_SRIO_Monitor_Monitor_var.iluSetWrapper(
           new iluObjectWrapper(
               r_SRIO_Monitor_Monitor_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_SRIO_Monitor_Monitor_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : SRIO_Monitor::Monitor::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_SRIO_Monitor_Monitor_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Monitor::Monitor_var& r_SRIO_Monitor_Monitor_var) {
	  
      SRIO_Monitor::Monitor_var temp_SRIO_Monitor_Monitor_var;
	  
     if (r_SRIO_Monitor_Monitor_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_SRIO_Monitor_Monitor_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_SRIO_Monitor_Monitor_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_SRIO_Monitor_Monitor_var = r_SRIO_Monitor_Monitor_var;

         // force a release since the var's in control of the refcount
         r_SRIO_Monitor_Monitor_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_SRIO_Monitor_Monitor_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, SRIO_Monitor::Monitor::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_SRIO_Monitor_Monitor_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_SRIO_Monitor_Monitor_var = (SRIO_Monitor::Monitor_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }


  // define the member functions in typecode class for SRIO_Monitor::Monitor::MissionSituation
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Monitor_Monitor_MissionSituation, SRIO_Monitor::Monitor::MissionSituation)

  // typecode instance for SRIO_Monitor_Monitor_MissionSituation
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_MissionSituation =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_MissionSituation);

  // define the Any insertion and extraction operators for SRIO_Monitor::Monitor::MissionSituation
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Monitor::Monitor::MissionSituation, SRIO_Monitor::Monitor::tc_MissionSituation)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Monitor::Monitor::MissionSituation, SRIO_Monitor::Monitor::tc_MissionSituation)

  // define the member functions in typecode class for SRIO_Monitor::Monitor::BackHomeReason
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Monitor_Monitor_BackHomeReason, SRIO_Monitor::Monitor::BackHomeReason)

  // typecode instance for SRIO_Monitor_Monitor_BackHomeReason
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_BackHomeReason =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_BackHomeReason);

  // define the Any insertion and extraction operators for SRIO_Monitor::Monitor::BackHomeReason
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Monitor::Monitor::BackHomeReason, SRIO_Monitor::Monitor::tc_BackHomeReason)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Monitor::Monitor::BackHomeReason, SRIO_Monitor::Monitor::tc_BackHomeReason)

  // define the member functions in typecode class for SRIO_Monitor::Monitor::UnitType
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Monitor_Monitor_UnitType, SRIO_Monitor::Monitor::UnitType)

  // typecode instance for SRIO_Monitor_Monitor_UnitType
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_UnitType =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_UnitType);

  // define the Any insertion and extraction operators for SRIO_Monitor::Monitor::UnitType
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Monitor::Monitor::UnitType, SRIO_Monitor::Monitor::tc_UnitType)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Monitor::Monitor::UnitType, SRIO_Monitor::Monitor::tc_UnitType)


/////////////////////////////////////////////////////////////////////
//  SRIO_Monitor::Monitor::PictureInfo members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Monitor::Monitor::PictureInfo::PictureInfo() {
picturName = CORBA_(String_var());  // iffy sunpro workaround
pic = SRIO_Monitor::Monitor::PictureFlow_var();  // iffy sunpro workaround
  }

  // copy constructor
  SRIO_Monitor::Monitor::PictureInfo::PictureInfo(const SRIO_Monitor::Monitor::PictureInfo& r_a_PictureInfo) {
          picturName = r_a_PictureInfo.picturName;
          pic = r_a_PictureInfo.pic;
          cui = r_a_PictureInfo.cui;
          responseTime = r_a_PictureInfo.responseTime;
   }

  // destructor
  SRIO_Monitor::Monitor::PictureInfo::~PictureInfo() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Monitor::Monitor::PictureInfo& SRIO_Monitor::Monitor::PictureInfo::self(){
        return *this;
  }

  // assignment operator
  SRIO_Monitor::Monitor::PictureInfo& SRIO_Monitor::Monitor::PictureInfo::operator=(
       const SRIO_Monitor::Monitor::PictureInfo& r_a_PictureInfo) {
          if (this != &r_a_PictureInfo) {
          picturName = r_a_PictureInfo.picturName;
          pic = r_a_PictureInfo.pic;
          cui = r_a_PictureInfo.cui;
          responseTime = r_a_PictureInfo.responseTime;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::PictureInfo

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Monitor::Monitor::PictureInfo& r_SRIO_Monitor_Monitor_PictureInfo)  {

         r_call += iluSizeRecord;
         iluCardinal r_picturName_length =
             strlen(r_SRIO_Monitor_Monitor_PictureInfo.picturName.iluStringVarReference());
          iluCStringWrapper _r_picturName_wrap(
                 (r_SRIO_Monitor_Monitor_PictureInfo.picturName).iluStringVarReference(),
                  r_picturName_length);
         r_call += _r_picturName_wrap;
         iluCardinal r_pic_length = r_SRIO_Monitor_Monitor_PictureInfo.pic->length();
         iluByte* r_pic_buffer = r_SRIO_Monitor_Monitor_PictureInfo.pic->get_buffer();
         iluBytesWrapper _r_pic_wrap(r_pic_buffer, r_pic_length);
         r_call += _r_pic_wrap;
          r_call += r_SRIO_Monitor_Monitor_PictureInfo.cui;
          r_call +=  r_SRIO_Monitor_Monitor_PictureInfo.responseTime;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Monitor::Monitor::PictureInfo& r_SRIO_Monitor_Monitor_PictureInfo)  {

         r_call << iluOutputRecord;
         iluCardinal r_picturName_length =
             strlen(r_SRIO_Monitor_Monitor_PictureInfo.picturName.iluStringVarReference());
          iluCStringWrapper _r_picturName_wrap(
                 (r_SRIO_Monitor_Monitor_PictureInfo.picturName).iluStringVarReference(),
                  r_picturName_length);
         r_call << _r_picturName_wrap;
         iluCardinal r_pic_length = r_SRIO_Monitor_Monitor_PictureInfo.pic->length();
         iluByte* r_pic_buffer = r_SRIO_Monitor_Monitor_PictureInfo.pic->get_buffer();
         iluBytesWrapper _r_pic_wrap(r_pic_buffer, r_pic_length);
         r_call << _r_pic_wrap;
          r_call << r_SRIO_Monitor_Monitor_PictureInfo.cui;
          r_call <<  r_SRIO_Monitor_Monitor_PictureInfo.responseTime;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Monitor::Monitor::PictureInfo& r_SRIO_Monitor_Monitor_PictureInfo)  {

         r_call >> iluInputRecord;
         iluCardinal r_picturName_length;
         iluCStringWrapper _r_picturName_wrap(
                 (r_SRIO_Monitor_Monitor_PictureInfo.picturName).iluStringVarReference(),
                  r_picturName_length);
         r_call >> _r_picturName_wrap;
         iluCardinal r_pic_length;
		 iluByte* r_pic_buffer = NULL;
         iluBytesWrapper _r_pic_wrap( r_pic_buffer, r_pic_length);
         r_call >> _r_pic_wrap;
          r_call >> r_SRIO_Monitor_Monitor_PictureInfo.cui;
          r_call >>  r_SRIO_Monitor_Monitor_PictureInfo.responseTime;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Monitor::Monitor::PictureInfo
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Monitor_Monitor_PictureInfo, SRIO_Monitor::Monitor::PictureInfo)

  // typecode instance for SRIO_Monitor_Monitor_PictureInfo
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_PictureInfo =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_PictureInfo);

  // define the Any insert and extract operators for SRIO_Monitor::Monitor::PictureInfo 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::PictureInfo, SRIO_Monitor::Monitor::tc_PictureInfo)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::PictureInfo, SRIO_Monitor::Monitor::tc_PictureInfo)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Monitor::Monitor::PictureInfo, SRIO_Monitor::Monitor::tc_PictureInfo)


/////////////////////////////////////////////////////////////////////
//  SRIO_Monitor::Monitor::CompleteUnitInfo members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Monitor::Monitor::CompleteUnitInfo::CompleteUnitInfo() {
  }

  // copy constructor
  SRIO_Monitor::Monitor::CompleteUnitInfo::CompleteUnitInfo(const SRIO_Monitor::Monitor::CompleteUnitInfo& r_a_CompleteUnitInfo) {
          us = r_a_CompleteUnitInfo.us;
          cui = r_a_CompleteUnitInfo.cui;
   }

  // destructor
  SRIO_Monitor::Monitor::CompleteUnitInfo::~CompleteUnitInfo() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Monitor::Monitor::CompleteUnitInfo& SRIO_Monitor::Monitor::CompleteUnitInfo::self(){
        return *this;
  }

  // assignment operator
  SRIO_Monitor::Monitor::CompleteUnitInfo& SRIO_Monitor::Monitor::CompleteUnitInfo::operator=(
       const SRIO_Monitor::Monitor::CompleteUnitInfo& r_a_CompleteUnitInfo) {
          if (this != &r_a_CompleteUnitInfo) {
          us = r_a_CompleteUnitInfo.us;
          cui = r_a_CompleteUnitInfo.cui;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::CompleteUnitInfo

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Monitor::Monitor::CompleteUnitInfo& r_SRIO_Monitor_Monitor_CompleteUnitInfo)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Monitor_Monitor_CompleteUnitInfo.us;
          r_call += r_SRIO_Monitor_Monitor_CompleteUnitInfo.cui;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Monitor::Monitor::CompleteUnitInfo& r_SRIO_Monitor_Monitor_CompleteUnitInfo)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Monitor_Monitor_CompleteUnitInfo.us;
          r_call << r_SRIO_Monitor_Monitor_CompleteUnitInfo.cui;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Monitor::Monitor::CompleteUnitInfo& r_SRIO_Monitor_Monitor_CompleteUnitInfo)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Monitor_Monitor_CompleteUnitInfo.us;
          r_call >> r_SRIO_Monitor_Monitor_CompleteUnitInfo.cui;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Monitor::Monitor::CompleteUnitInfo
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Monitor_Monitor_CompleteUnitInfo, SRIO_Monitor::Monitor::CompleteUnitInfo)

  // typecode instance for SRIO_Monitor_Monitor_CompleteUnitInfo
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_CompleteUnitInfo =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_CompleteUnitInfo);

  // define the Any insert and extract operators for SRIO_Monitor::Monitor::CompleteUnitInfo 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::CompleteUnitInfo, SRIO_Monitor::Monitor::tc_CompleteUnitInfo)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::CompleteUnitInfo, SRIO_Monitor::Monitor::tc_CompleteUnitInfo)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Monitor::Monitor::CompleteUnitInfo, SRIO_Monitor::Monitor::tc_CompleteUnitInfo)


/////////////////////////////////////////////////////////////////////
//  SRIO_Monitor::Monitor::UnitState members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Monitor::Monitor::UnitState::UnitState() {
  }

  // copy constructor
  SRIO_Monitor::Monitor::UnitState::UnitState(const SRIO_Monitor::Monitor::UnitState& r_a_UnitState) {
          health = r_a_UnitState.health;
          battery = r_a_UnitState.battery;
   }

  // destructor
  SRIO_Monitor::Monitor::UnitState::~UnitState() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Monitor::Monitor::UnitState& SRIO_Monitor::Monitor::UnitState::self(){
        return *this;
  }

  // assignment operator
  SRIO_Monitor::Monitor::UnitState& SRIO_Monitor::Monitor::UnitState::operator=(
       const SRIO_Monitor::Monitor::UnitState& r_a_UnitState) {
          if (this != &r_a_UnitState) {
          health = r_a_UnitState.health;
          battery = r_a_UnitState.battery;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::UnitState

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Monitor::Monitor::UnitState& r_SRIO_Monitor_Monitor_UnitState)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Monitor_Monitor_UnitState.health;
          r_call +=  r_SRIO_Monitor_Monitor_UnitState.battery;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Monitor::Monitor::UnitState& r_SRIO_Monitor_Monitor_UnitState)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Monitor_Monitor_UnitState.health;
          r_call <<  r_SRIO_Monitor_Monitor_UnitState.battery;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Monitor::Monitor::UnitState& r_SRIO_Monitor_Monitor_UnitState)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Monitor_Monitor_UnitState.health;
          r_call >>  r_SRIO_Monitor_Monitor_UnitState.battery;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Monitor::Monitor::UnitState
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Monitor_Monitor_UnitState, SRIO_Monitor::Monitor::UnitState)

  // typecode instance for SRIO_Monitor_Monitor_UnitState
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_UnitState =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_UnitState);

  // define the Any insert and extract operators for SRIO_Monitor::Monitor::UnitState 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::UnitState, SRIO_Monitor::Monitor::tc_UnitState)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::UnitState, SRIO_Monitor::Monitor::tc_UnitState)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Monitor::Monitor::UnitState, SRIO_Monitor::Monitor::tc_UnitState)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Monitor::Monitor::PictureFlow members   

 // constructors & destructor
  SRIO_Monitor::Monitor::PictureFlow::PictureFlow () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Monitor::Monitor::PictureFlow::PictureFlow (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Monitor::Monitor::PictureFlow::PictureFlow (CORBA_(ULong) max , CORBA_(ULong) length, 
          CORBA_(Octet)* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Monitor::Monitor::PictureFlow::~PictureFlow() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Monitor::Monitor::PictureFlow::PictureFlow (const SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow)
  :
         m_maximum(r_SRIO_Monitor_Monitor_PictureFlow.m_maximum),
         m_length(r_SRIO_Monitor_Monitor_PictureFlow.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Monitor_Monitor_PictureFlow.m_buffer[index];
            }
   }

 // assignment
   SRIO_Monitor::Monitor::PictureFlow& SRIO_Monitor::Monitor::PictureFlow::operator= (const SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow) {
         if (this == &r_SRIO_Monitor_Monitor_PictureFlow) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Monitor_Monitor_PictureFlow.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Monitor_Monitor_PictureFlow.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Monitor_Monitor_PictureFlow.m_buffer[index];
          }
          return *this;
       }

  // memory management
  CORBA_(Octet)* SRIO_Monitor::Monitor::PictureFlow::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new CORBA_(Octet)[num_elements]) : NULL);
  }
  
  void SRIO_Monitor::Monitor::PictureFlow::freebuf(CORBA_(Octet)* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Monitor::Monitor::PictureFlow::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 CORBA_(Octet)* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Monitor::Monitor::PictureFlow::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Monitor::Monitor::PictureFlow::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Monitor::Monitor::PictureFlow::release() const{
    return m_release;
  }
  
  // buffer accessors
  CORBA_(Octet)* SRIO_Monitor::Monitor::PictureFlow::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  CORBA_(Octet) const* SRIO_Monitor::Monitor::PictureFlow::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  CORBA_(Octet)& SRIO_Monitor::Monitor::PictureFlow::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const CORBA_(Octet)& SRIO_Monitor::Monitor::PictureFlow::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const CORBA_(Octet) *_temp = 
              (const CORBA_(Octet) *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Monitor::Monitor::PictureFlow& SRIO_Monitor::Monitor::PictureFlow::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::PictureFlow

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow){

        iluCardinal card_length = r_SRIO_Monitor_Monitor_PictureFlow.length();
        iluSequenceWrapper _r_SRIO_Monitor_Monitor_PictureFlow(card_length);
        r_call += _r_SRIO_Monitor_Monitor_PictureFlow;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Monitor_Monitor_PictureFlow.length(); index++) {
          r_call += r_SRIO_Monitor_Monitor_PictureFlow[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow){

        iluCardinal card_length = r_SRIO_Monitor_Monitor_PictureFlow.length();
        iluSequenceWrapper _r_SRIO_Monitor_Monitor_PictureFlow(card_length);
        r_call << _r_SRIO_Monitor_Monitor_PictureFlow;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Monitor_Monitor_PictureFlow.length(); index++) {
          r_call << r_SRIO_Monitor_Monitor_PictureFlow[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Monitor::Monitor::PictureFlow _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Monitor_Monitor_PictureFlow = SRIO_Monitor::Monitor::PictureFlow(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Monitor::Monitor::PictureFlow
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Monitor_Monitor_PictureFlow, SRIO_Monitor::Monitor::PictureFlow)

  // typecode instance for SRIO_Monitor_Monitor_PictureFlow
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_PictureFlow =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_PictureFlow);

  // define the Any insert and extract operators for SRIO_Monitor::Monitor::PictureFlow 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::PictureFlow, SRIO_Monitor::Monitor::tc_PictureFlow)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::PictureFlow, SRIO_Monitor::Monitor::tc_PictureFlow)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Monitor::Monitor::PictureFlow, SRIO_Monitor::Monitor::tc_PictureFlow)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Monitor::Monitor::CurrentUnitInfo members
		
  // constructors & destructor
  SRIO_Monitor::Monitor::CurrentUnitInfo::CurrentUnitInfo() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Monitor::Monitor::CurrentUnitInfo::CurrentUnitInfo(const SRIO_Monitor::Monitor::CurrentUnitInfo& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Monitor::Monitor::CurrentUnitInfo::~CurrentUnitInfo() {
	  unset();
  }

  // assignment
  SRIO_Monitor::Monitor::CurrentUnitInfo& SRIO_Monitor::Monitor::CurrentUnitInfo::operator=
          (const SRIO_Monitor::Monitor::CurrentUnitInfo& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // groundUnitInfo
		  case SRIO_Monitor::Monitor::UnitGroundType:  
                   m_groundUnitInfo =
                      new SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo(*r_union_type.m_groundUnitInfo);
                   break;

                 // airUnitInfo
		  case SRIO_Monitor::Monitor::UnitAirType:  
                   m_airUnitInfo =
                      new SRIO_Air_Unit::Air_Unit::AirUnitInfo(*r_union_type.m_airUnitInfo);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Monitor::Monitor::CurrentUnitInfo& SRIO_Monitor::Monitor::CurrentUnitInfo::self(){
        return *this;
  }

  // discriminator access
  SRIO_Monitor::Monitor::UnitType SRIO_Monitor::Monitor::CurrentUnitInfo::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Monitor::Monitor::CurrentUnitInfo::_d (SRIO_Monitor::Monitor::UnitType new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // groundUnitInfo
		  case SRIO_Monitor::Monitor::UnitGroundType:  
                  switch(new_d) { 
                       case SRIO_Monitor::Monitor::UnitGroundType: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // airUnitInfo
		  case SRIO_Monitor::Monitor::UnitAirType:  
                  switch(new_d) { 
                       case SRIO_Monitor::Monitor::UnitAirType: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Monitor::Monitor::UnitGroundType: 
                       case SRIO_Monitor::Monitor::UnitAirType: 
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
 
   // groundUnitInfo access
    const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& SRIO_Monitor::Monitor::CurrentUnitInfo::groundUnitInfo() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo&) *m_groundUnitInfo);
    }

    SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& SRIO_Monitor::Monitor::CurrentUnitInfo::groundUnitInfo(){
           return( (SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo&) *m_groundUnitInfo);
    }

    void SRIO_Monitor::Monitor::CurrentUnitInfo::groundUnitInfo(const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo & a_groundUnitInfo){
         unset();
         m_discriminator = SRIO_Monitor::Monitor::UnitGroundType;
         m_groundUnitInfo = new SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo(a_groundUnitInfo);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // airUnitInfo access
    const SRIO_Air_Unit::Air_Unit::AirUnitInfo& SRIO_Monitor::Monitor::CurrentUnitInfo::airUnitInfo() const {
           return( (const SRIO_Air_Unit::Air_Unit::AirUnitInfo&) *m_airUnitInfo);
    }

    SRIO_Air_Unit::Air_Unit::AirUnitInfo& SRIO_Monitor::Monitor::CurrentUnitInfo::airUnitInfo(){
           return( (SRIO_Air_Unit::Air_Unit::AirUnitInfo&) *m_airUnitInfo);
    }

    void SRIO_Monitor::Monitor::CurrentUnitInfo::airUnitInfo(const SRIO_Air_Unit::Air_Unit::AirUnitInfo & a_airUnitInfo){
         unset();
         m_discriminator = SRIO_Monitor::Monitor::UnitAirType;
         m_airUnitInfo = new SRIO_Air_Unit::Air_Unit::AirUnitInfo(a_airUnitInfo);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  void SRIO_Monitor::Monitor::CurrentUnitInfo::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // groundUnitInfo
		  case SRIO_Monitor::Monitor::UnitGroundType:  
                     delete m_groundUnitInfo;
                     break;

                 // airUnitInfo
		  case SRIO_Monitor::Monitor::UnitAirType:  
                     delete m_airUnitInfo;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::CurrentUnitInfo

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Monitor::Monitor::CurrentUnitInfo& r_SRIO_Monitor_Monitor_CurrentUnitInfo) {

          iluUnionWrapper _r_SRIO_Monitor_Monitor_CurrentUnitInfo(
                                r_SRIO_Monitor_Monitor_CurrentUnitInfo._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Monitor_Monitor_CurrentUnitInfo;

          switch (r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_discriminator) {

                 // groundUnitInfo
		  case SRIO_Monitor::Monitor::UnitGroundType:  
                    r_call += (*r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_groundUnitInfo); 
                   break;

                 // airUnitInfo
		  case SRIO_Monitor::Monitor::UnitAirType:  
                    r_call += (*r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_airUnitInfo); 
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Monitor::Monitor::CurrentUnitInfo& r_SRIO_Monitor_Monitor_CurrentUnitInfo) {

          iluUnionWrapper _r_SRIO_Monitor_Monitor_CurrentUnitInfo(
                                r_SRIO_Monitor_Monitor_CurrentUnitInfo._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Monitor_Monitor_CurrentUnitInfo;

          switch (r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_discriminator) {

                 // groundUnitInfo
		  case SRIO_Monitor::Monitor::UnitGroundType:  
                    r_call << (*r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_groundUnitInfo); 
                   break;

                 // airUnitInfo
		  case SRIO_Monitor::Monitor::UnitAirType:  
                    r_call << (*r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_airUnitInfo); 
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Monitor::Monitor::CurrentUnitInfo& r_SRIO_Monitor_Monitor_CurrentUnitInfo) {
        
          iluUnionWrapper _r_SRIO_Monitor_Monitor_CurrentUnitInfo(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Monitor_Monitor_CurrentUnitInfo;

          switch (_r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_card_discriminator) {

                 // groundUnitInfo
		  case SRIO_Monitor::Monitor::UnitGroundType:  
                 { SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo  groundUnitInfo_temp;
                    r_call >> groundUnitInfo_temp;
                    r_SRIO_Monitor_Monitor_CurrentUnitInfo.groundUnitInfo(groundUnitInfo_temp);
                    break;
                   }

                 // airUnitInfo
		  case SRIO_Monitor::Monitor::UnitAirType:  
                 { SRIO_Air_Unit::Air_Unit::AirUnitInfo  airUnitInfo_temp;
                    r_call >> airUnitInfo_temp;
                    r_SRIO_Monitor_Monitor_CurrentUnitInfo.airUnitInfo(airUnitInfo_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Monitor_Monitor_CurrentUnitInfo._d((SRIO_Monitor::Monitor::UnitType) (_r_SRIO_Monitor_Monitor_CurrentUnitInfo.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Monitor::Monitor::CurrentUnitInfo
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Monitor_Monitor_CurrentUnitInfo, SRIO_Monitor::Monitor::CurrentUnitInfo)

  // typecode instance for SRIO_Monitor_Monitor_CurrentUnitInfo
  const CORBA_(TypeCode_ptr) SRIO_Monitor::Monitor::tc_CurrentUnitInfo =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor_CurrentUnitInfo);

  // define the Any insert and extract operators for SRIO_Monitor::Monitor::CurrentUnitInfo 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::CurrentUnitInfo, SRIO_Monitor::Monitor::tc_CurrentUnitInfo)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Monitor::Monitor::CurrentUnitInfo, SRIO_Monitor::Monitor::tc_CurrentUnitInfo)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Monitor::Monitor::CurrentUnitInfo, SRIO_Monitor::Monitor::tc_CurrentUnitInfo)

  //////////////////////////////////////////////////////////////////////
  // SRIO_Monitor::Monitor members

  // CORBA object reference operations

  SRIO_Monitor::Monitor_ptr SRIO_Monitor::Monitor::_duplicate( Monitor_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  SRIO_Monitor::Monitor_ptr SRIO_Monitor::Monitor::_nil() {
    return (Monitor_ptr) NULL;
  }

  // default constructor
  SRIO_Monitor::Monitor::Monitor() {
     // to be determined
  }

  // destructor
  SRIO_Monitor::Monitor::~Monitor() {
    // to be determined
  }

  // copy constructor
  SRIO_Monitor::Monitor::Monitor(const Monitor&) {
    // to be determined
  }

  // assignment operator
  void SRIO_Monitor::Monitor::operator=(const Monitor&) {
    // to be determined
  }

  // Simple Object Lookup
  SRIO_Monitor::Monitor_ptr SRIO_Monitor::Monitor::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Monitor_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

//  for use in narrowing
//  void *SRIO_Monitor::Monitor::iluDowncast (iluClass class_to_cast_down_to) {
//    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
//      return((void *)((iluObject*) this));
//    if (class_to_cast_down_to == CORBA::Object::iluGetILUClassRecord())
//       return((void *) ((CORBA_(Object_ptr)) this));
//    if (class_to_cast_down_to == m_ILUClassRecord)
//      return ((void*) this);
//    return (NULL);
//  }
  void* SRIO_Monitor::Monitor::iluDowncast(iluClass class_to_cast_down_to) {
      if (!class_to_cast_down_to || class_to_cast_down_to == ilu_rootClass)
          return static_cast<void*>(static_cast<iluObject*>(this));

      if (class_to_cast_down_to == CORBA_(Object)::iluGetILUClassRecord())
          return static_cast<void*>(static_cast<CORBA_(Object_ptr)>(this));

      if (class_to_cast_down_to == m_ILUClassRecord)
          return static_cast<void*>(this);

      return nullptr;
  }


  // initialize to use of this class of objects - called by iluInitialize

  void SRIO_Monitor::Monitor::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "IDL:omg.org/CORBA/Object:1.0"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "SRIO_Monitor.Monitor"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "IDL:SRIO_Monitor/Monitor:1.0"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_TRUE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      8,          // number of methods
      1,          // number of superclasses
      _superclasses
   );

    {
     // for method sendUnitInfo

       iluException* sendUnitInfo_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "sendUnitInfo"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendUnitInfo_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "unitInfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Monitor/Monitor/CompleteUnitInfo:1.0"));
    }  //end for method sendUnitInfo

    {
     // for method sendTrapPoint

       iluException* sendTrapPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "sendTrapPoint"), // name
                     2,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendTrapPoint_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "tp"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/TrapPoint:1.0"));
    }  //end for method sendTrapPoint

    {
     // for method sendFireLocation

       iluException* sendFireLocation_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     2,      // method index
                     CONST_CAST(iluCString, "sendFireLocation"), // name
                     3,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendFireLocation_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "fid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "fp"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Point2D:1.0"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "responseTime"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"));
    }  //end for method sendFireLocation

    {
     // for method foundFire

       iluException* foundFire_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     3,      // method index
                     CONST_CAST(iluCString, "foundFire"), // name
                     4,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     foundFire_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "fid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "pi"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Monitor/Monitor/PictureInfo:1.0"));
    }  //end for method foundFire

    {
     // for method confirmAction

       iluException* confirmAction_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     4,      // method index
                     CONST_CAST(iluCString, "confirmAction"), // name
                     5,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     confirmAction_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "fid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "responseTime"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"));
    }  //end for method confirmAction

    {
     // for method backHome

       iluException* backHome_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     5,      // method index
                     CONST_CAST(iluCString, "backHome"), // name
                     6,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     backHome_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "bhr"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Monitor/Monitor/BackHomeReason:1.0"));
    }  //end for method backHome

    {
     // for method sendMissionState

       iluException* sendMissionState_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     6,      // method index
                     CONST_CAST(iluCString, "sendMissionState"), // name
                     7,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendMissionState_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "fid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "ms"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Monitor/Monitor/MissionSituation:1.0"));
    }  //end for method sendMissionState

    {
     // for method sendPicture

       iluException* sendPicture_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     7,      // method index
                     CONST_CAST(iluCString, "sendPicture"), // name
                     8,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendPicture_exception_array,
                     4,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "pictureName"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "pic"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ndKwf8vfmBTV3Mjc04YR0a3tZcA"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "time"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
        iluCppInternal::iluDefineMethodArg (a_method, 3,
             CONST_CAST(iluCString, "procedureStartTime"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
    }  //end for method sendPicture

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  SRIO_Monitor::Monitor typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor)::iluDeleteValue (void* pv_value) {
                SRIO_Monitor::Monitor_ptr p_thevalue = (SRIO_Monitor::Monitor_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor)::iluDeepCopy (void* pv_value) {
                SRIO_Monitor::Monitor_ptr p_thevalue = (SRIO_Monitor::Monitor_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_(Boolean) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               SRIO_Monitor::Monitor_ptr p_thevalue = (SRIO_Monitor::Monitor_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, SRIO_Monitor::Monitor::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           SRIO_Monitor::Monitor_ptr p_object = (SRIO_Monitor::Monitor_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If SRIO_Monitor::Monitor were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA::Object::iluGetILUClassRecord())
           //    return ((CORBA_(Object_ptr))p_object);
           if (casttoclass == SRIO_Monitor::Monitor::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


//      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
//           SRIO_Monitor::Monitor_ptr p_object = (SRIO_Monitor::Monitor_ptr) p_an_object_of_your_type;
//           return CORBA::TypeCode::LookupTypeCode(p_object->iluClassId());
//      }

      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor)::iluMostSpecificTypeCode(void* p_an_object_of_your_type) {
          if (!p_an_object_of_your_type) return nullptr;
          SRIO_Monitor::Monitor_ptr p_object = static_cast<SRIO_Monitor::Monitor_ptr>(p_an_object_of_your_type);
          return CORBA_(TypeCode)::LookupTypeCode(p_object->iluClassId());
      }



        // typecode instance for SRIO_Monitor::Monitor
        const CORBA_(TypeCode_ptr) SRIO_Monitor::tc_Monitor = new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Monitor_Monitor);

      // define the Any insertion and extraction operators for SRIO_Monitor::Monitor

      void operator<<=(CORBA_(Any)& r_any, SRIO_Monitor::Monitor_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(SRIO_Monitor::tc_Monitor, p_object, ILUCPP_TRUE);
      }

      CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Monitor::Monitor_ptr& r_p_object) {

          CORBA_(Any)* p_nc_any = CONST_CAST(CORBA_(Any)*, &r_any);

          if (p_nc_any->iluGetFromPickle(SRIO_Monitor::tc_Monitor)) { 
                 r_p_object = (SRIO_Monitor::Monitor_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


////////////////////////////////////////////////////////////////
// Force initialization of SRIO_Monitor:: classes upon load

SRIO_Monitor::initializer SRIO_Monitor::initializer::sm_the_SRIO_Monitor_initializer;

SRIO_Monitor::initializer:: initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * SRIO_Monitor::initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(SRIO_Monitor::iluInitialize);
  return this;
}
