
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Ground-Unit-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members


  // list of initialization functions to call for the SRIO_Ground_Unit:: interface
  iluInitializationFunctionNode* SRIO_Ground_Unit::p_initialization_function_list;
  int SRIO_Ground_Unit::g_i_initialized;

  // holds the ilu class record for SRIO_Ground_Unit::Ground_Unit objects
  iluClass SRIO_Ground_Unit::Ground_Unit::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// SRIO_Ground_Unit initialization

  void SRIO_Ground_Unit::iluInitialize () {

      if ( g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // performs object type initialization
        SRIO_Ground_Unit::Ground_Unit::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Ground-Unit-MoveAction"),
             CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/MoveAction:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/MoveActionType:1.0"),  // UID of discriminant type
              5,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "goAheadData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_GoAhead");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "goBackwardData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_GoBackward");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  2,   // which arm
                  CONST_CAST( iluCString, "turnLeftData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_TurnLeft");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  3,   // which arm
                  CONST_CAST( iluCString, "turnRightData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_TurnRight");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  4,   // which arm
                  CONST_CAST( iluCString, "stopData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/ActionDuration:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_Stop");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-Formation"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Formation:1.0"),
            4, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "robot-ids"),     // field name
                CONST_CAST( iluCString, "ilut:nMjCFNifl1hE5bdCpxJIGUGP5Hy") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "leader-ids"),     // field name
                CONST_CAST( iluCString, "ilut:fvIY2xM8RFu7RJSuxiFpgt5crGS") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "distances"),     // field name
                CONST_CAST( iluCString, "ilut:mQ6ToW9sPHwCk-pbHr9ZMf2T7J8") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                3,     // which field
                CONST_CAST( iluCString, "angles"),     // field name
                CONST_CAST( iluCString, "ilut:mQ6ToW9sPHwCk-pbHr9ZMf2T7J8") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-TrapPoint2D"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/TrapPoint2D:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "point"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Point2D:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "radius"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-Point2D"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Point2D:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "x"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "y"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-GroundUnitInfo"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/GroundUnitInfo:1.0"),
            4, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "info"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "role"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Unit/General_Unit/UnitRole:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "speed"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Speed2D:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                3,     // which field
                CONST_CAST( iluCString, "pose"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Pose2D:1.0") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-Speed2D"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Speed2D:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "leanerVel"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "angularVel"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-Pose2D"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Pose2D:1.0"),
            3, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "x"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "y"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "yaw"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-BasicMoveActionData"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/BasicMoveActionData:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "speed"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "duration"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/ActionDuration:1.0") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Ground-Unit-ActionDuration"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/ActionDuration:1.0"),
            3, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "keep"),     // field name
                CONST_CAST( iluCString, "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "ft-s"),     // field name
                CONST_CAST( iluCString, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "ft-t"),     // field name
                CONST_CAST( iluCString, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO") // UID of field type
            );
        }

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "Ground-Unit"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit:1.0"),
            SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord(), // object class
            &b_new_registration);

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Ground-Unit-MoveActionType"),
            CONST_CAST( iluCString, "SRIO-Ground-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/MoveActionType:1.0"),
            5,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "MA-GoAhead"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "MA-GoBackward"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "MA-TurnLeft"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "MA-TurnRight"),  // element name
              3       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              4,        // which element
              CONST_CAST( iluCString, "MA-Stop"),  // element name
              4       // integer value for element
        );
     }

       }
#endif  // IIOP_PROTOCOL 

   g_i_initialized = 1;
 }

 // call all the surrogate and true initialization functions
 iluCppInternal::iluCallInitializationFunctions(&p_initialization_function_list);

}



//////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit_var sizing, input and output operators

// note following three operators only needed
// if SRIO_Ground_Unit::Ground_Unit is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const SRIO_Ground_Unit::Ground_Unit_var& r_SRIO_Ground_Unit_Ground_Unit_var) {
         r_call += r_SRIO_Ground_Unit_Ground_Unit_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const SRIO_Ground_Unit::Ground_Unit_var& r_SRIO_Ground_Unit_Ground_Unit_var) {

      if (r_SRIO_Ground_Unit_Ground_Unit_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_SRIO_Ground_Unit_Ground_Unit_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_SRIO_Ground_Unit_Ground_Unit_var.iluSetWrapper(
           new iluObjectWrapper(
               r_SRIO_Ground_Unit_Ground_Unit_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_SRIO_Ground_Unit_Ground_Unit_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_SRIO_Ground_Unit_Ground_Unit_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Ground_Unit::Ground_Unit_var& r_SRIO_Ground_Unit_Ground_Unit_var) {
	  
      SRIO_Ground_Unit::Ground_Unit_var temp_SRIO_Ground_Unit_Ground_Unit_var;
	  
     if (r_SRIO_Ground_Unit_Ground_Unit_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_SRIO_Ground_Unit_Ground_Unit_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_SRIO_Ground_Unit_Ground_Unit_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_SRIO_Ground_Unit_Ground_Unit_var = r_SRIO_Ground_Unit_Ground_Unit_var;

         // force a release since the var's in control of the refcount
         r_SRIO_Ground_Unit_Ground_Unit_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_SRIO_Ground_Unit_Ground_Unit_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_SRIO_Ground_Unit_Ground_Unit_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_SRIO_Ground_Unit_Ground_Unit_var = (SRIO_Ground_Unit::Ground_Unit_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }


  // define the member functions in typecode class for SRIO_Ground_Unit::Ground_Unit::MoveActionType
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Ground_Unit_Ground_Unit_MoveActionType, SRIO_Ground_Unit::Ground_Unit::MoveActionType)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_MoveActionType
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_MoveActionType =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_MoveActionType);

  // define the Any insertion and extraction operators for SRIO_Ground_Unit::Ground_Unit::MoveActionType
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Ground_Unit::Ground_Unit::MoveActionType, SRIO_Ground_Unit::Ground_Unit::tc_MoveActionType)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Ground_Unit::Ground_Unit::MoveActionType, SRIO_Ground_Unit::Ground_Unit::tc_MoveActionType)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::Formation members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::Formation::Formation() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::Formation::Formation(const SRIO_Ground_Unit::Ground_Unit::Formation& r_a_Formation) {
          robot_ids = r_a_Formation.robot_ids;
          leader_ids = r_a_Formation.leader_ids;
          distances = r_a_Formation.distances;
          angles = r_a_Formation.angles;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::Formation::~Formation() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::Formation& SRIO_Ground_Unit::Ground_Unit::Formation::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::Formation& SRIO_Ground_Unit::Ground_Unit::Formation::operator=(
       const SRIO_Ground_Unit::Ground_Unit::Formation& r_a_Formation) {
          if (this != &r_a_Formation) {
          robot_ids = r_a_Formation.robot_ids;
          leader_ids = r_a_Formation.leader_ids;
          distances = r_a_Formation.distances;
          angles = r_a_Formation.angles;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Formation

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Formation& r_SRIO_Ground_Unit_Ground_Unit_Formation)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_Formation.robot_ids;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_Formation.leader_ids;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_Formation.distances;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_Formation.angles;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Formation& r_SRIO_Ground_Unit_Ground_Unit_Formation)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_Formation.robot_ids;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_Formation.leader_ids;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_Formation.distances;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_Formation.angles;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::Formation& r_SRIO_Ground_Unit_Ground_Unit_Formation)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_Formation.robot_ids;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_Formation.leader_ids;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_Formation.distances;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_Formation.angles;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::Formation
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_Formation, SRIO_Ground_Unit::Ground_Unit::Formation)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_Formation
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_Formation =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_Formation);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Formation 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Formation, SRIO_Ground_Unit::Ground_Unit::tc_Formation)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Formation, SRIO_Ground_Unit::Ground_Unit::tc_Formation)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Formation, SRIO_Ground_Unit::Ground_Unit::tc_Formation)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::TrapPoint2D::TrapPoint2D() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D::TrapPoint2D(const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_a_TrapPoint2D) {
          point = r_a_TrapPoint2D.point;
          radius = r_a_TrapPoint2D.radius;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D::~TrapPoint2D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& SRIO_Ground_Unit::Ground_Unit::TrapPoint2D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& SRIO_Ground_Unit::Ground_Unit::TrapPoint2D::operator=(
       const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_a_TrapPoint2D) {
          if (this != &r_a_TrapPoint2D) {
          point = r_a_TrapPoint2D.point;
          radius = r_a_TrapPoint2D.radius;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::TrapPoint2D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D.point;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D.radius;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D.point;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D.radius;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D.point;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D.radius;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::TrapPoint2D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_TrapPoint2D, SRIO_Ground_Unit::Ground_Unit::TrapPoint2D)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_TrapPoint2D
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_TrapPoint2D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_TrapPoint2D);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::TrapPoint2D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TrapPoint2D, SRIO_Ground_Unit::Ground_Unit::tc_TrapPoint2D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TrapPoint2D, SRIO_Ground_Unit::Ground_Unit::tc_TrapPoint2D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TrapPoint2D, SRIO_Ground_Unit::Ground_Unit::tc_TrapPoint2D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::Point2D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::Point2D::Point2D() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::Point2D::Point2D(const SRIO_Ground_Unit::Ground_Unit::Point2D& r_a_Point2D) {
          x = r_a_Point2D.x;
          y = r_a_Point2D.y;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::Point2D::~Point2D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::Point2D& SRIO_Ground_Unit::Ground_Unit::Point2D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::Point2D& SRIO_Ground_Unit::Ground_Unit::Point2D::operator=(
       const SRIO_Ground_Unit::Ground_Unit::Point2D& r_a_Point2D) {
          if (this != &r_a_Point2D) {
          x = r_a_Point2D.x;
          y = r_a_Point2D.y;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Point2D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Point2D& r_SRIO_Ground_Unit_Ground_Unit_Point2D)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_Point2D.x;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_Point2D.y;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Point2D& r_SRIO_Ground_Unit_Ground_Unit_Point2D)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_Point2D.x;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_Point2D.y;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::Point2D& r_SRIO_Ground_Unit_Ground_Unit_Point2D)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_Point2D.x;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_Point2D.y;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::Point2D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_Point2D, SRIO_Ground_Unit::Ground_Unit::Point2D)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_Point2D
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_Point2D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_Point2D);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Point2D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Point2D, SRIO_Ground_Unit::Ground_Unit::tc_Point2D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Point2D, SRIO_Ground_Unit::Ground_Unit::tc_Point2D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Point2D, SRIO_Ground_Unit::Ground_Unit::tc_Point2D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo::GroundUnitInfo() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo::GroundUnitInfo(const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_a_GroundUnitInfo) {
          info = r_a_GroundUnitInfo.info;
          role = r_a_GroundUnitInfo.role;
          speed = r_a_GroundUnitInfo.speed;
          pose = r_a_GroundUnitInfo.pose;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo::~GroundUnitInfo() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo::operator=(
       const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_a_GroundUnitInfo) {
          if (this != &r_a_GroundUnitInfo) {
          info = r_a_GroundUnitInfo.info;
          role = r_a_GroundUnitInfo.role;
          speed = r_a_GroundUnitInfo.speed;
          pose = r_a_GroundUnitInfo.pose;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.info;
         iluEnumWrapper _r_role_wrap(
              (iluDummyEnum &) r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.role);
         r_call += _r_role_wrap;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.speed;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.pose;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.info;
         iluEnumWrapper _r_role_wrap(
              (iluDummyEnum &) r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.role);
         r_call << _r_role_wrap;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.speed;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.pose;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.info;
         iluEnumWrapper _r_role_wrap(
              (iluDummyEnum &) r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.role);
         r_call >> _r_role_wrap;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.speed;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo.pose;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo, SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_GroundUnitInfo =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo, SRIO_Ground_Unit::Ground_Unit::tc_GroundUnitInfo)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo, SRIO_Ground_Unit::Ground_Unit::tc_GroundUnitInfo)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo, SRIO_Ground_Unit::Ground_Unit::tc_GroundUnitInfo)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::Speed2D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::Speed2D::Speed2D() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::Speed2D::Speed2D(const SRIO_Ground_Unit::Ground_Unit::Speed2D& r_a_Speed2D) {
          leanerVel = r_a_Speed2D.leanerVel;
          angularVel = r_a_Speed2D.angularVel;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::Speed2D::~Speed2D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::Speed2D& SRIO_Ground_Unit::Ground_Unit::Speed2D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::Speed2D& SRIO_Ground_Unit::Ground_Unit::Speed2D::operator=(
       const SRIO_Ground_Unit::Ground_Unit::Speed2D& r_a_Speed2D) {
          if (this != &r_a_Speed2D) {
          leanerVel = r_a_Speed2D.leanerVel;
          angularVel = r_a_Speed2D.angularVel;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Speed2D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Speed2D& r_SRIO_Ground_Unit_Ground_Unit_Speed2D)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_Speed2D.leanerVel;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_Speed2D.angularVel;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Speed2D& r_SRIO_Ground_Unit_Ground_Unit_Speed2D)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_Speed2D.leanerVel;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_Speed2D.angularVel;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::Speed2D& r_SRIO_Ground_Unit_Ground_Unit_Speed2D)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_Speed2D.leanerVel;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_Speed2D.angularVel;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::Speed2D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_Speed2D, SRIO_Ground_Unit::Ground_Unit::Speed2D)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_Speed2D
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_Speed2D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_Speed2D);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Speed2D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Speed2D, SRIO_Ground_Unit::Ground_Unit::tc_Speed2D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Speed2D, SRIO_Ground_Unit::Ground_Unit::tc_Speed2D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Speed2D, SRIO_Ground_Unit::Ground_Unit::tc_Speed2D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::Pose2D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::Pose2D::Pose2D() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::Pose2D::Pose2D(const SRIO_Ground_Unit::Ground_Unit::Pose2D& r_a_Pose2D) {
          x = r_a_Pose2D.x;
          y = r_a_Pose2D.y;
          yaw = r_a_Pose2D.yaw;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::Pose2D::~Pose2D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::Pose2D& SRIO_Ground_Unit::Ground_Unit::Pose2D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::Pose2D& SRIO_Ground_Unit::Ground_Unit::Pose2D::operator=(
       const SRIO_Ground_Unit::Ground_Unit::Pose2D& r_a_Pose2D) {
          if (this != &r_a_Pose2D) {
          x = r_a_Pose2D.x;
          y = r_a_Pose2D.y;
          yaw = r_a_Pose2D.yaw;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Pose2D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Pose2D& r_SRIO_Ground_Unit_Ground_Unit_Pose2D)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.x;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.y;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.yaw;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::Pose2D& r_SRIO_Ground_Unit_Ground_Unit_Pose2D)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.x;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.y;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.yaw;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::Pose2D& r_SRIO_Ground_Unit_Ground_Unit_Pose2D)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.x;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.y;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_Pose2D.yaw;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::Pose2D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_Pose2D, SRIO_Ground_Unit::Ground_Unit::Pose2D)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_Pose2D
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_Pose2D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_Pose2D);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Pose2D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Pose2D, SRIO_Ground_Unit::Ground_Unit::tc_Pose2D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Pose2D, SRIO_Ground_Unit::Ground_Unit::tc_Pose2D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::Pose2D, SRIO_Ground_Unit::Ground_Unit::tc_Pose2D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData::BasicMoveActionData() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData::BasicMoveActionData(const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_a_BasicMoveActionData) {
          speed = r_a_BasicMoveActionData.speed;
          duration = r_a_BasicMoveActionData.duration;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData::~BasicMoveActionData() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData::operator=(
       const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_a_BasicMoveActionData) {
          if (this != &r_a_BasicMoveActionData) {
          speed = r_a_BasicMoveActionData.speed;
          duration = r_a_BasicMoveActionData.duration;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData.speed;
          r_call += r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData.duration;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData.speed;
          r_call << r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData.duration;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData.speed;
          r_call >> r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData.duration;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData, SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_BasicMoveActionData =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData, SRIO_Ground_Unit::Ground_Unit::tc_BasicMoveActionData)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData, SRIO_Ground_Unit::Ground_Unit::tc_BasicMoveActionData)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData, SRIO_Ground_Unit::Ground_Unit::tc_BasicMoveActionData)


/////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit::ActionDuration members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Ground_Unit::Ground_Unit::ActionDuration::ActionDuration() {
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::ActionDuration::ActionDuration(const SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_a_ActionDuration) {
          keep = r_a_ActionDuration.keep;
          ft_s = r_a_ActionDuration.ft_s;
          ft_t = r_a_ActionDuration.ft_t;
   }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::ActionDuration::~ActionDuration() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::ActionDuration& SRIO_Ground_Unit::Ground_Unit::ActionDuration::self(){
        return *this;
  }

  // assignment operator
  SRIO_Ground_Unit::Ground_Unit::ActionDuration& SRIO_Ground_Unit::Ground_Unit::ActionDuration::operator=(
       const SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_a_ActionDuration) {
          if (this != &r_a_ActionDuration) {
          keep = r_a_ActionDuration.keep;
          ft_s = r_a_ActionDuration.ft_s;
          ft_t = r_a_ActionDuration.ft_t;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::ActionDuration

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_SRIO_Ground_Unit_Ground_Unit_ActionDuration)  {

         r_call += iluSizeRecord;
         iluBoolWrapper _r_keep_wrap(
             (ILUCPP_BOOL &) r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.keep);
         r_call += _r_keep_wrap;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.ft_s;
          r_call +=  r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.ft_t;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_SRIO_Ground_Unit_Ground_Unit_ActionDuration)  {

         r_call << iluOutputRecord;
         iluBoolWrapper _r_keep_wrap(
             (ILUCPP_BOOL &) r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.keep);
         r_call << _r_keep_wrap;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.ft_s;
          r_call <<  r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.ft_t;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_SRIO_Ground_Unit_Ground_Unit_ActionDuration)  {

         r_call >> iluInputRecord;
         iluBoolWrapper _r_keep_wrap(
             (ILUCPP_BOOL &) r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.keep);
         r_call >> _r_keep_wrap;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.ft_s;
          r_call >>  r_SRIO_Ground_Unit_Ground_Unit_ActionDuration.ft_t;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::ActionDuration
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_ActionDuration, SRIO_Ground_Unit::Ground_Unit::ActionDuration)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_ActionDuration
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_ActionDuration =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_ActionDuration);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::ActionDuration 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::ActionDuration, SRIO_Ground_Unit::Ground_Unit::tc_ActionDuration)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::ActionDuration, SRIO_Ground_Unit::Ground_Unit::tc_ActionDuration)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::ActionDuration, SRIO_Ground_Unit::Ground_Unit::tc_ActionDuration)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Ground_Unit::Ground_Unit::TrapPointSequence members   

 // constructors & destructor
  SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::TrapPointSequence () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::TrapPointSequence (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::TrapPointSequence (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Ground_Unit::Ground_Unit::TrapPoint2D* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::~TrapPointSequence() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::TrapPointSequence (const SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence)
  :
         m_maximum(r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.m_maximum),
         m_length(r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.m_buffer[index];
            }
   }

 // assignment
   SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::operator= (const SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence) {
         if (this == &r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D* SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Ground_Unit::Ground_Unit::TrapPoint2D[num_elements]) : NULL);
  }
  
  void SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::freebuf(SRIO_Ground_Unit::Ground_Unit::TrapPoint2D* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Ground_Unit::Ground_Unit::TrapPoint2D* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D* SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D const* SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D *_temp = 
              (const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& SRIO_Ground_Unit::Ground_Unit::TrapPointSequence::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::TrapPointSequence

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence){

        iluCardinal card_length = r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.length();
        iluSequenceWrapper _r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence(card_length);
        r_call += _r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.length(); index++) {
          r_call += r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence){

        iluCardinal card_length = r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.length();
        iluSequenceWrapper _r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence(card_length);
        r_call << _r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence.length(); index++) {
          r_call << r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Ground_Unit::Ground_Unit::TrapPointSequence _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence = SRIO_Ground_Unit::Ground_Unit::TrapPointSequence(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::TrapPointSequence
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_TrapPointSequence, SRIO_Ground_Unit::Ground_Unit::TrapPointSequence)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_TrapPointSequence
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_TrapPointSequence =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_TrapPointSequence);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::TrapPointSequence 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TrapPointSequence, SRIO_Ground_Unit::Ground_Unit::tc_TrapPointSequence)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TrapPointSequence, SRIO_Ground_Unit::Ground_Unit::tc_TrapPointSequence)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TrapPointSequence, SRIO_Ground_Unit::Ground_Unit::tc_TrapPointSequence)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Ground_Unit::Ground_Unit::TaskPath members   

 // constructors & destructor
  SRIO_Ground_Unit::Ground_Unit::TaskPath::TaskPath () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Ground_Unit::Ground_Unit::TaskPath::TaskPath (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Ground_Unit::Ground_Unit::TaskPath::TaskPath (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Ground_Unit::Ground_Unit::Point2D* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Ground_Unit::Ground_Unit::TaskPath::~TaskPath() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Ground_Unit::Ground_Unit::TaskPath::TaskPath (const SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath)
  :
         m_maximum(r_SRIO_Ground_Unit_Ground_Unit_TaskPath.m_maximum),
         m_length(r_SRIO_Ground_Unit_Ground_Unit_TaskPath.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Ground_Unit_Ground_Unit_TaskPath.m_buffer[index];
            }
   }

 // assignment
   SRIO_Ground_Unit::Ground_Unit::TaskPath& SRIO_Ground_Unit::Ground_Unit::TaskPath::operator= (const SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath) {
         if (this == &r_SRIO_Ground_Unit_Ground_Unit_TaskPath) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Ground_Unit_Ground_Unit_TaskPath.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Ground_Unit_Ground_Unit_TaskPath.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Ground_Unit_Ground_Unit_TaskPath.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Ground_Unit::Ground_Unit::Point2D* SRIO_Ground_Unit::Ground_Unit::TaskPath::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Ground_Unit::Ground_Unit::Point2D[num_elements]) : NULL);
  }
  
  void SRIO_Ground_Unit::Ground_Unit::TaskPath::freebuf(SRIO_Ground_Unit::Ground_Unit::Point2D* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Ground_Unit::Ground_Unit::TaskPath::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Ground_Unit::Ground_Unit::Point2D* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Ground_Unit::Ground_Unit::TaskPath::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Ground_Unit::Ground_Unit::TaskPath::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Ground_Unit::Ground_Unit::TaskPath::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Ground_Unit::Ground_Unit::Point2D* SRIO_Ground_Unit::Ground_Unit::TaskPath::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Ground_Unit::Ground_Unit::Point2D const* SRIO_Ground_Unit::Ground_Unit::TaskPath::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Ground_Unit::Ground_Unit::Point2D& SRIO_Ground_Unit::Ground_Unit::TaskPath::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Ground_Unit::Ground_Unit::Point2D& SRIO_Ground_Unit::Ground_Unit::TaskPath::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Ground_Unit::Ground_Unit::Point2D *_temp = 
              (const SRIO_Ground_Unit::Ground_Unit::Point2D *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::TaskPath& SRIO_Ground_Unit::Ground_Unit::TaskPath::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::TaskPath

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath){

        iluCardinal card_length = r_SRIO_Ground_Unit_Ground_Unit_TaskPath.length();
        iluSequenceWrapper _r_SRIO_Ground_Unit_Ground_Unit_TaskPath(card_length);
        r_call += _r_SRIO_Ground_Unit_Ground_Unit_TaskPath;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Ground_Unit_Ground_Unit_TaskPath.length(); index++) {
          r_call += r_SRIO_Ground_Unit_Ground_Unit_TaskPath[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath){

        iluCardinal card_length = r_SRIO_Ground_Unit_Ground_Unit_TaskPath.length();
        iluSequenceWrapper _r_SRIO_Ground_Unit_Ground_Unit_TaskPath(card_length);
        r_call << _r_SRIO_Ground_Unit_Ground_Unit_TaskPath;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Ground_Unit_Ground_Unit_TaskPath.length(); index++) {
          r_call << r_SRIO_Ground_Unit_Ground_Unit_TaskPath[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Ground_Unit::Ground_Unit::TaskPath _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Ground_Unit_Ground_Unit_TaskPath = SRIO_Ground_Unit::Ground_Unit::TaskPath(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::TaskPath
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_TaskPath, SRIO_Ground_Unit::Ground_Unit::TaskPath)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_TaskPath
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_TaskPath =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_TaskPath);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::TaskPath 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TaskPath, SRIO_Ground_Unit::Ground_Unit::tc_TaskPath)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TaskPath, SRIO_Ground_Unit::Ground_Unit::tc_TaskPath)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::TaskPath, SRIO_Ground_Unit::Ground_Unit::tc_TaskPath)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Ground_Unit::Ground_Unit::ActionSequence members   

 // constructors & destructor
  SRIO_Ground_Unit::Ground_Unit::ActionSequence::ActionSequence () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Ground_Unit::Ground_Unit::ActionSequence::ActionSequence (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Ground_Unit::Ground_Unit::ActionSequence::ActionSequence (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Ground_Unit::Ground_Unit::MoveAction* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Ground_Unit::Ground_Unit::ActionSequence::~ActionSequence() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Ground_Unit::Ground_Unit::ActionSequence::ActionSequence (const SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence)
  :
         m_maximum(r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.m_maximum),
         m_length(r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.m_buffer[index];
            }
   }

 // assignment
   SRIO_Ground_Unit::Ground_Unit::ActionSequence& SRIO_Ground_Unit::Ground_Unit::ActionSequence::operator= (const SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence) {
         if (this == &r_SRIO_Ground_Unit_Ground_Unit_ActionSequence) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Ground_Unit::Ground_Unit::MoveAction* SRIO_Ground_Unit::Ground_Unit::ActionSequence::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Ground_Unit::Ground_Unit::MoveAction[num_elements]) : NULL);
  }
  
  void SRIO_Ground_Unit::Ground_Unit::ActionSequence::freebuf(SRIO_Ground_Unit::Ground_Unit::MoveAction* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Ground_Unit::Ground_Unit::ActionSequence::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Ground_Unit::Ground_Unit::MoveAction* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Ground_Unit::Ground_Unit::ActionSequence::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Ground_Unit::Ground_Unit::ActionSequence::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Ground_Unit::Ground_Unit::ActionSequence::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Ground_Unit::Ground_Unit::MoveAction* SRIO_Ground_Unit::Ground_Unit::ActionSequence::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Ground_Unit::Ground_Unit::MoveAction const* SRIO_Ground_Unit::Ground_Unit::ActionSequence::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Ground_Unit::Ground_Unit::MoveAction& SRIO_Ground_Unit::Ground_Unit::ActionSequence::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Ground_Unit::Ground_Unit::MoveAction& SRIO_Ground_Unit::Ground_Unit::ActionSequence::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Ground_Unit::Ground_Unit::MoveAction *_temp = 
              (const SRIO_Ground_Unit::Ground_Unit::MoveAction *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::ActionSequence& SRIO_Ground_Unit::Ground_Unit::ActionSequence::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::ActionSequence

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence){

        iluCardinal card_length = r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.length();
        iluSequenceWrapper _r_SRIO_Ground_Unit_Ground_Unit_ActionSequence(card_length);
        r_call += _r_SRIO_Ground_Unit_Ground_Unit_ActionSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.length(); index++) {
          r_call += r_SRIO_Ground_Unit_Ground_Unit_ActionSequence[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence){

        iluCardinal card_length = r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.length();
        iluSequenceWrapper _r_SRIO_Ground_Unit_Ground_Unit_ActionSequence(card_length);
        r_call << _r_SRIO_Ground_Unit_Ground_Unit_ActionSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Ground_Unit_Ground_Unit_ActionSequence.length(); index++) {
          r_call << r_SRIO_Ground_Unit_Ground_Unit_ActionSequence[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Ground_Unit::Ground_Unit::ActionSequence _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Ground_Unit_Ground_Unit_ActionSequence = SRIO_Ground_Unit::Ground_Unit::ActionSequence(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::ActionSequence
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_ActionSequence, SRIO_Ground_Unit::Ground_Unit::ActionSequence)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_ActionSequence
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_ActionSequence =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_ActionSequence);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::ActionSequence 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::ActionSequence, SRIO_Ground_Unit::Ground_Unit::tc_ActionSequence)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::ActionSequence, SRIO_Ground_Unit::Ground_Unit::tc_ActionSequence)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::ActionSequence, SRIO_Ground_Unit::Ground_Unit::tc_ActionSequence)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Ground_Unit::Ground_Unit::MoveAction members
		
  // constructors & destructor
  SRIO_Ground_Unit::Ground_Unit::MoveAction::MoveAction() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Ground_Unit::Ground_Unit::MoveAction::MoveAction(const SRIO_Ground_Unit::Ground_Unit::MoveAction& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Ground_Unit::Ground_Unit::MoveAction::~MoveAction() {
	  unset();
  }

  // assignment
  SRIO_Ground_Unit::Ground_Unit::MoveAction& SRIO_Ground_Unit::Ground_Unit::MoveAction::operator=
          (const SRIO_Ground_Unit::Ground_Unit::MoveAction& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // goAheadData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead:  
                   m_goAheadData =
                      new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(*r_union_type.m_goAheadData);
                   break;

                 // goBackwardData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward:  
                   m_goBackwardData =
                      new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(*r_union_type.m_goBackwardData);
                   break;

                 // turnLeftData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft:  
                   m_turnLeftData =
                      new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(*r_union_type.m_turnLeftData);
                   break;

                 // turnRightData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight:  
                   m_turnRightData =
                      new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(*r_union_type.m_turnRightData);
                   break;

                 // stopData
		  case SRIO_Ground_Unit::Ground_Unit::MA_Stop:  
                   m_stopData =
                      new SRIO_Ground_Unit::Ground_Unit::ActionDuration(*r_union_type.m_stopData);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Ground_Unit::Ground_Unit::MoveAction& SRIO_Ground_Unit::Ground_Unit::MoveAction::self(){
        return *this;
  }

  // discriminator access
  SRIO_Ground_Unit::Ground_Unit::MoveActionType SRIO_Ground_Unit::Ground_Unit::MoveAction::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Ground_Unit::Ground_Unit::MoveAction::_d (SRIO_Ground_Unit::Ground_Unit::MoveActionType new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // goAheadData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead:  
                  switch(new_d) { 
                       case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // goBackwardData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward:  
                  switch(new_d) { 
                       case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // turnLeftData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft:  
                  switch(new_d) { 
                       case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // turnRightData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight:  
                  switch(new_d) { 
                       case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // stopData
		  case SRIO_Ground_Unit::Ground_Unit::MA_Stop:  
                  switch(new_d) { 
                       case SRIO_Ground_Unit::Ground_Unit::MA_Stop: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead: 
                       case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward: 
                       case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft: 
                       case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight: 
                       case SRIO_Ground_Unit::Ground_Unit::MA_Stop: 
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
 
   // goAheadData access
    const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::goAheadData() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_goAheadData);
    }

    SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::goAheadData(){
           return( (SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_goAheadData);
    }

    void SRIO_Ground_Unit::Ground_Unit::MoveAction::goAheadData(const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData & a_goAheadData){
         unset();
         m_discriminator = SRIO_Ground_Unit::Ground_Unit::MA_GoAhead;
         m_goAheadData = new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(a_goAheadData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // goBackwardData access
    const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::goBackwardData() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_goBackwardData);
    }

    SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::goBackwardData(){
           return( (SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_goBackwardData);
    }

    void SRIO_Ground_Unit::Ground_Unit::MoveAction::goBackwardData(const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData & a_goBackwardData){
         unset();
         m_discriminator = SRIO_Ground_Unit::Ground_Unit::MA_GoBackward;
         m_goBackwardData = new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(a_goBackwardData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // turnLeftData access
    const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::turnLeftData() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_turnLeftData);
    }

    SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::turnLeftData(){
           return( (SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_turnLeftData);
    }

    void SRIO_Ground_Unit::Ground_Unit::MoveAction::turnLeftData(const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData & a_turnLeftData){
         unset();
         m_discriminator = SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft;
         m_turnLeftData = new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(a_turnLeftData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // turnRightData access
    const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::turnRightData() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_turnRightData);
    }

    SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& SRIO_Ground_Unit::Ground_Unit::MoveAction::turnRightData(){
           return( (SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData&) *m_turnRightData);
    }

    void SRIO_Ground_Unit::Ground_Unit::MoveAction::turnRightData(const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData & a_turnRightData){
         unset();
         m_discriminator = SRIO_Ground_Unit::Ground_Unit::MA_TurnRight;
         m_turnRightData = new SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData(a_turnRightData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // stopData access
    const SRIO_Ground_Unit::Ground_Unit::ActionDuration& SRIO_Ground_Unit::Ground_Unit::MoveAction::stopData() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::ActionDuration&) *m_stopData);
    }

    SRIO_Ground_Unit::Ground_Unit::ActionDuration& SRIO_Ground_Unit::Ground_Unit::MoveAction::stopData(){
           return( (SRIO_Ground_Unit::Ground_Unit::ActionDuration&) *m_stopData);
    }

    void SRIO_Ground_Unit::Ground_Unit::MoveAction::stopData(const SRIO_Ground_Unit::Ground_Unit::ActionDuration & a_stopData){
         unset();
         m_discriminator = SRIO_Ground_Unit::Ground_Unit::MA_Stop;
         m_stopData = new SRIO_Ground_Unit::Ground_Unit::ActionDuration(a_stopData);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  void SRIO_Ground_Unit::Ground_Unit::MoveAction::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // goAheadData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead:  
                     delete m_goAheadData;
                     break;

                 // goBackwardData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward:  
                     delete m_goBackwardData;
                     break;

                 // turnLeftData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft:  
                     delete m_turnLeftData;
                     break;

                 // turnRightData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight:  
                     delete m_turnRightData;
                     break;

                 // stopData
		  case SRIO_Ground_Unit::Ground_Unit::MA_Stop:  
                     delete m_stopData;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::MoveAction

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Ground_Unit::Ground_Unit::MoveAction& r_SRIO_Ground_Unit_Ground_Unit_MoveAction) {

          iluUnionWrapper _r_SRIO_Ground_Unit_Ground_Unit_MoveAction(
                                r_SRIO_Ground_Unit_Ground_Unit_MoveAction._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Ground_Unit_Ground_Unit_MoveAction;

          switch (r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_discriminator) {

                 // goAheadData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead:  
                    r_call += (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_goAheadData); 
                   break;

                 // goBackwardData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward:  
                    r_call += (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_goBackwardData); 
                   break;

                 // turnLeftData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft:  
                    r_call += (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_turnLeftData); 
                   break;

                 // turnRightData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight:  
                    r_call += (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_turnRightData); 
                   break;

                 // stopData
		  case SRIO_Ground_Unit::Ground_Unit::MA_Stop:  
                    r_call += (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_stopData); 
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Ground_Unit::Ground_Unit::MoveAction& r_SRIO_Ground_Unit_Ground_Unit_MoveAction) {

          iluUnionWrapper _r_SRIO_Ground_Unit_Ground_Unit_MoveAction(
                                r_SRIO_Ground_Unit_Ground_Unit_MoveAction._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Ground_Unit_Ground_Unit_MoveAction;

          switch (r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_discriminator) {

                 // goAheadData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead:  
                    r_call << (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_goAheadData); 
                   break;

                 // goBackwardData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward:  
                    r_call << (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_goBackwardData); 
                   break;

                 // turnLeftData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft:  
                    r_call << (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_turnLeftData); 
                   break;

                 // turnRightData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight:  
                    r_call << (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_turnRightData); 
                   break;

                 // stopData
		  case SRIO_Ground_Unit::Ground_Unit::MA_Stop:  
                    r_call << (*r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_stopData); 
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Ground_Unit::Ground_Unit::MoveAction& r_SRIO_Ground_Unit_Ground_Unit_MoveAction) {
        
          iluUnionWrapper _r_SRIO_Ground_Unit_Ground_Unit_MoveAction(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Ground_Unit_Ground_Unit_MoveAction;

          switch (_r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_card_discriminator) {

                 // goAheadData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoAhead:  
                 { SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData  goAheadData_temp;
                    r_call >> goAheadData_temp;
                    r_SRIO_Ground_Unit_Ground_Unit_MoveAction.goAheadData(goAheadData_temp);
                    break;
                   }

                 // goBackwardData
		  case SRIO_Ground_Unit::Ground_Unit::MA_GoBackward:  
                 { SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData  goBackwardData_temp;
                    r_call >> goBackwardData_temp;
                    r_SRIO_Ground_Unit_Ground_Unit_MoveAction.goBackwardData(goBackwardData_temp);
                    break;
                   }

                 // turnLeftData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnLeft:  
                 { SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData  turnLeftData_temp;
                    r_call >> turnLeftData_temp;
                    r_SRIO_Ground_Unit_Ground_Unit_MoveAction.turnLeftData(turnLeftData_temp);
                    break;
                   }

                 // turnRightData
		  case SRIO_Ground_Unit::Ground_Unit::MA_TurnRight:  
                 { SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData  turnRightData_temp;
                    r_call >> turnRightData_temp;
                    r_SRIO_Ground_Unit_Ground_Unit_MoveAction.turnRightData(turnRightData_temp);
                    break;
                   }

                 // stopData
		  case SRIO_Ground_Unit::Ground_Unit::MA_Stop:  
                 { SRIO_Ground_Unit::Ground_Unit::ActionDuration  stopData_temp;
                    r_call >> stopData_temp;
                    r_SRIO_Ground_Unit_Ground_Unit_MoveAction.stopData(stopData_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Ground_Unit_Ground_Unit_MoveAction._d((SRIO_Ground_Unit::Ground_Unit::MoveActionType) (_r_SRIO_Ground_Unit_Ground_Unit_MoveAction.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Ground_Unit::Ground_Unit::MoveAction
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Ground_Unit_Ground_Unit_MoveAction, SRIO_Ground_Unit::Ground_Unit::MoveAction)

  // typecode instance for SRIO_Ground_Unit_Ground_Unit_MoveAction
  const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::Ground_Unit::tc_MoveAction =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit_MoveAction);

  // define the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::MoveAction 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::MoveAction, SRIO_Ground_Unit::Ground_Unit::tc_MoveAction)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::MoveAction, SRIO_Ground_Unit::Ground_Unit::tc_MoveAction)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Ground_Unit::Ground_Unit::MoveAction, SRIO_Ground_Unit::Ground_Unit::tc_MoveAction)

  //////////////////////////////////////////////////////////////////////
  // SRIO_Ground_Unit::Ground_Unit members

  // CORBA object reference operations

  SRIO_Ground_Unit::Ground_Unit_ptr SRIO_Ground_Unit::Ground_Unit::_duplicate( Ground_Unit_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  SRIO_Ground_Unit::Ground_Unit_ptr SRIO_Ground_Unit::Ground_Unit::_nil() {
    return (Ground_Unit_ptr) NULL;
  }

  // default constructor
  SRIO_Ground_Unit::Ground_Unit::Ground_Unit() {
     // to be determined
  }

  // destructor
  SRIO_Ground_Unit::Ground_Unit::~Ground_Unit() {
    // to be determined
  }

  // copy constructor
  SRIO_Ground_Unit::Ground_Unit::Ground_Unit(const Ground_Unit&) {
    // to be determined
  }

  // assignment operator
  void SRIO_Ground_Unit::Ground_Unit::operator=(const Ground_Unit&) {
    // to be determined
  }

  // Simple Object Lookup
  SRIO_Ground_Unit::Ground_Unit_ptr SRIO_Ground_Unit::Ground_Unit::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Ground_Unit_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *SRIO_Ground_Unit::Ground_Unit::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == SRIO_Unit::General_Unit::iluGetILUClassRecord()) 
      return (REINTERPRET_CAST(void *, STATIC_CAST(SRIO_Unit::General_Unit_ptr, this)));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void SRIO_Ground_Unit::Ground_Unit::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "IDL:SRIO_Unit/General_Unit:1.0"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "SRIO_Ground_Unit.Ground-Unit"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit:1.0"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_TRUE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      19,          // number of methods
      1,          // number of superclasses
      _superclasses
   );

    {
     // for method getCurrentSpeed

       iluException* getCurrentSpeed_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "getCurrentSpeed"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getCurrentSpeed_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Ground_Unit/Ground_Unit/Speed2D:1.0") // return type ID
        );
    }  //end for method getCurrentSpeed

    {
     // for method getCurrentPose

       iluException* getCurrentPose_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "getCurrentPose"), // name
                     2,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getCurrentPose_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Ground_Unit/Ground_Unit/Pose2D:1.0") // return type ID
        );
    }  //end for method getCurrentPose

    {
     // for method getCurrentInfo

       iluException* getCurrentInfo_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     2,      // method index
                     CONST_CAST(iluCString, "getCurrentInfo"), // name
                     3,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getCurrentInfo_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Ground_Unit/Ground_Unit/GroundUnitInfo:1.0") // return type ID
        );
    }  //end for method getCurrentInfo

    {
     // for method sendMoveAction

       iluException* sendMoveAction_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     3,      // method index
                     CONST_CAST(iluCString, "sendMoveAction"), // name
                     4,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendMoveAction_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "action"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/MoveAction:1.0"));
    }  //end for method sendMoveAction

    {
     // for method sendMoveActionSequence

       iluException* sendMoveActionSequence_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     4,      // method index
                     CONST_CAST(iluCString, "sendMoveActionSequence"), // name
                     5,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendMoveActionSequence_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "actions"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:eZqYM8Z+Erss108EKN+8tWm75v9"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "times"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"));
    }  //end for method sendMoveActionSequence

    {
     // for method sendVehicleInfo

       iluException* sendVehicleInfo_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     5,      // method index
                     CONST_CAST(iluCString, "sendVehicleInfo"), // name
                     6,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendVehicleInfo_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "info"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/GroundUnitInfo:1.0"));
    }  //end for method sendVehicleInfo

    {
     // for method setRearVehicles

       iluException* setRearVehicles_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     6,      // method index
                     CONST_CAST(iluCString, "setRearVehicles"), // name
                     7,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setRearVehicles_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "rears"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:m8BRq0bOnb45leg0NOS8ZmQa-ro"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "distance"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "angle"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
    }  //end for method setRearVehicles

    {
     // for method setFormation

       iluException* setFormation_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     7,      // method index
                     CONST_CAST(iluCString, "setFormation"), // name
                     8,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setFormation_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "form"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Formation:1.0"));
    }  //end for method setFormation

    {
     // for method reportTrap

       iluException* reportTrap_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     8,      // method index
                     CONST_CAST(iluCString, "reportTrap"), // name
                     9,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     reportTrap_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "trap"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/TrapPoint2D:1.0"));
    }  //end for method reportTrap

    {
     // for method clearTraps

       iluException* clearTraps_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     9,      // method index
                     CONST_CAST(iluCString, "clearTraps"), // name
                     10,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     clearTraps_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method clearTraps

    {
     // for method getTraps

       iluException* getTraps_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     10,      // method index
                     CONST_CAST(iluCString, "getTraps"), // name
                     11,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getTraps_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:pL4QAQdx3RBvFQGnuVUbbauErPi") // return type ID
        );
    }  //end for method getTraps

    {
     // for method setTrapPoint

       iluException* setTrapPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     11,      // method index
                     CONST_CAST(iluCString, "setTrapPoint"), // name
                     12,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setTrapPoint_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "trap"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/TrapPoint2D:1.0"));
    }  //end for method setTrapPoint

    {
     // for method setTrack

       iluException* setTrack_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     12,      // method index
                     CONST_CAST(iluCString, "setTrack"), // name
                     13,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setTrack_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "track"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:kaKU7Mg3Xc8D15tnQikFLuEMsP+"));
    }  //end for method setTrack

    {
     // for method setTaskPath

       iluException* setTaskPath_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     13,      // method index
                     CONST_CAST(iluCString, "setTaskPath"), // name
                     14,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setTaskPath_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "path"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:kaKU7Mg3Xc8D15tnQikFLuEMsP+"));
    }  //end for method setTaskPath

    {
     // for method setTaskPoint

       iluException* setTaskPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     14,      // method index
                     CONST_CAST(iluCString, "setTaskPoint"), // name
                     15,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setTaskPoint_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "point"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Ground_Unit/Ground_Unit/Point2D:1.0"));
    }  //end for method setTaskPoint

    {
     // for method startPhotoStream

       iluException* startPhotoStream_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     15,      // method index
                     CONST_CAST(iluCString, "startPhotoStream"), // name
                     16,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     startPhotoStream_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "frequency"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
    }  //end for method startPhotoStream

    {
     // for method stopPhotoStream

       iluException* stopPhotoStream_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     16,      // method index
                     CONST_CAST(iluCString, "stopPhotoStream"), // name
                     17,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     stopPhotoStream_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method stopPhotoStream

    {
     // for method setFollower

       iluException* setFollower_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     17,      // method index
                     CONST_CAST(iluCString, "setFollower"), // name
                     18,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setFollower_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "ui"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method setFollower

    {
     // for method unsetFollower

       iluException* unsetFollower_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     18,      // method index
                     CONST_CAST(iluCString, "unsetFollower"), // name
                     19,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     unsetFollower_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method unsetFollower

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  SRIO_Ground_Unit::Ground_Unit typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit)::iluDeleteValue (void* pv_value) {
                SRIO_Ground_Unit::Ground_Unit_ptr p_thevalue = (SRIO_Ground_Unit::Ground_Unit_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit)::iluDeepCopy (void* pv_value) {
                SRIO_Ground_Unit::Ground_Unit_ptr p_thevalue = (SRIO_Ground_Unit::Ground_Unit_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_(Boolean) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               SRIO_Ground_Unit::Ground_Unit_ptr p_thevalue = (SRIO_Ground_Unit::Ground_Unit_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           SRIO_Ground_Unit::Ground_Unit_ptr p_object = (SRIO_Ground_Unit::Ground_Unit_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If SRIO_Ground_Unit::Ground_Unit were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA::Object::iluGetILUClassRecord())
           //    return ((CORBA::Object_ptr)p_object);
           if (casttoclass == SRIO_Ground_Unit::Ground_Unit::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


//      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
//           SRIO_Ground_Unit::Ground_Unit_ptr p_object = (SRIO_Ground_Unit::Ground_Unit_ptr) p_an_object_of_your_type;
//           return CORBA::TypeCode::LookupTypeCode(p_object->iluClassId());
//      }

      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit)::iluMostSpecificTypeCode(void* p_an_object_of_your_type) {
          if (!p_an_object_of_your_type) return nullptr;
          SRIO_Ground_Unit::Ground_Unit_ptr p_object = static_cast<SRIO_Ground_Unit::Ground_Unit_ptr>(p_an_object_of_your_type);
          return CORBA_(TypeCode)::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for SRIO_Ground_Unit::Ground_Unit
        const CORBA_(TypeCode_ptr) SRIO_Ground_Unit::tc_Ground_Unit = new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Ground_Unit_Ground_Unit);

      // define the Any insertion and extraction operators for SRIO_Ground_Unit::Ground_Unit

      void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(SRIO_Ground_Unit::tc_Ground_Unit, p_object, ILUCPP_TRUE);
      }

      CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit_ptr& r_p_object) {

          CORBA_(Any)* p_nc_any = CONST_CAST(CORBA_(Any)*, &r_any);

          if (p_nc_any->iluGetFromPickle(SRIO_Ground_Unit::tc_Ground_Unit)) { 
                 r_p_object = (SRIO_Ground_Unit::Ground_Unit_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


////////////////////////////////////////////////////////////////
// Force initialization of SRIO_Ground_Unit:: classes upon load

SRIO_Ground_Unit::initializer SRIO_Ground_Unit::initializer::sm_the_SRIO_Ground_Unit_initializer;

SRIO_Ground_Unit::initializer:: initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * SRIO_Ground_Unit::initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(SRIO_Ground_Unit::iluInitialize);
  return this;
}
