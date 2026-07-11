
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Console-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members

  // exceptions vector
  static iluException interface_exceptions[] = {
          (iluException) 0,   //SRIO_Console::Console::AlreadyBindexception
          (iluException) 1,   //SRIO_Console::Console::NotFoundexception
  };

  // list of initialization functions to call for the SRIO_Console:: interface
  iluInitializationFunctionNode* SRIO_Console::p_initialization_function_list;
  int SRIO_Console::g_i_initialized;

  // holds the ilu class record for SRIO_Console::Console objects
  iluClass SRIO_Console::Console::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// SRIO_Console initialization

  void SRIO_Console::iluInitialize () {

      if ( g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // define the exceptions in the SRIO_Console interface

       interface_exceptions[g_SRIO_Console_Console_AlreadyBind_index] =
              iluCppInternal::iluDefineException(
                 REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR) 0)),
                 CONST_CAST( iluCString, "IDL:SRIO_Console/Console/AlreadyBind:1.0"),
                 REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR) 0)));

       interface_exceptions[g_SRIO_Console_Console_NotFound_index] =
              iluCppInternal::iluDefineException(
                 REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR) 0)),
                 CONST_CAST( iluCString, "IDL:SRIO_Console/Console/NotFound:1.0"),
                 REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR) 0)));

       // performs object type initialization
        SRIO_Console::Console::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Console-Message"),
             CONST_CAST( iluCString, "SRIO-Console"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/Message:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/Operation:1.0"),  // UID of discriminant type
              5,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "infoSeq"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:kwkwgbvpv+vadYmnz8w1UE-BJ6B"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "OP-SetCosInfo");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "bindInfo"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Console/Console/CosInfoNode:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "OP-Bind");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  2,   // which arm
                  CONST_CAST( iluCString, "unbindInfo"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Console/Console/UnbindData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "OP-Unbind");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  3,   // which arm
                  CONST_CAST( iluCString, "tp"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Console/Console/TrapPoint:1.0"), // arm type
                  2  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "OP-ReportTrap");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "OP-AddTrap");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 1, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  4,   // which arm
                  CONST_CAST( iluCString, "details"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"), // arm type
                  2  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "OP-Opened");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "OP-Closed");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 1, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Console-TrapPoint"),
             CONST_CAST( iluCString, "SRIO-Console"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/TrapPoint:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/TrapType:1.0"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "trapPoint2D"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/TrapPoint2D:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "TrapGroundType");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "trapPoint3D"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/TrapPoint3D:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "TrapAirType");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Console-Point"),
             CONST_CAST( iluCString, "SRIO-Console"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/Point:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/PointType:1.0"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "p2D"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Ground_Unit/Ground_Unit/Point2D:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "PointGroundType");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "p3D"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/Point3D:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "PointAirType");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Console-MissionStateData"),
             CONST_CAST( iluCString, "SRIO-Console"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/MissionStateData:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Console/Console/MissionState:1.0"),  // UID of discriminant type
              1,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "time"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MissionSuspend");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Console-UnbindData"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/UnbindData:1.0"),
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
                CONST_CAST( iluCString, "details"),     // field name
                CONST_CAST( iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Console-CosInfoNode"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/CosInfoNode:1.0"),
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
            CONST_CAST( iluCString, "Console"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console:1.0"),
            SRIO_Console::Console::iluGetILUClassRecord(), // object class
            &b_new_registration);

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-Operation"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/Operation:1.0"),
            7,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "OP-SetCosInfo"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "OP-Bind"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "OP-Unbind"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "OP-Opened"),  // element name
              3       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              4,        // which element
              CONST_CAST( iluCString, "OP-Closed"),  // element name
              4       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              5,        // which element
              CONST_CAST( iluCString, "OP-ReportTrap"),  // element name
              5       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              6,        // which element
              CONST_CAST( iluCString, "OP-AddTrap"),  // element name
              6       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-TrapType"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/TrapType:1.0"),
            2,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "TrapGroundType"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "TrapAirType"),  // element name
              1       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-PointType"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/PointType:1.0"),
            2,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "PointGroundType"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "PointAirType"),  // element name
              1       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-TrackMode"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/TrackMode:1.0"),
            2,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "RouteTrack"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "ObjectTrack"),  // element name
              1       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-FormationType"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/FormationType:1.0"),
            3,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "OneLine"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "Matrix"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "WildGoose"),  // element name
              2       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-FormationState"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/FormationState:1.0"),
            4,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "FormationImplement"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "FormationSuspend"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "FormationSuccess"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "FormationFail"),  // element name
              3       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-MissionState"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/MissionState:1.0"),
            5,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "MissionImplement"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "MissionSuspend"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "MissionSuccess"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "MissionFail"),  // element name
              3       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              4,        // which element
              CONST_CAST( iluCString, "MissionCancel"),  // element name
              4       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Console-Role"),
            CONST_CAST( iluCString, "SRIO-Console"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Console/Console/Role:1.0"),
            2,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "Follower"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "Leader"),  // element name
              1       // integer value for element
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
//  SRIO_Console::Console_var sizing, input and output operators

// note following three operators only needed
// if SRIO_Console::Console is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const SRIO_Console::Console_var& r_SRIO_Console_Console_var) {
         r_call += r_SRIO_Console_Console_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const SRIO_Console::Console_var& r_SRIO_Console_Console_var) {

      if (r_SRIO_Console_Console_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_SRIO_Console_Console_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_SRIO_Console_Console_var.iluSetWrapper(
           new iluObjectWrapper(
               r_SRIO_Console_Console_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_SRIO_Console_Console_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : SRIO_Console::Console::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_SRIO_Console_Console_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Console::Console_var& r_SRIO_Console_Console_var) {
	  
      SRIO_Console::Console_var temp_SRIO_Console_Console_var;
	  
     if (r_SRIO_Console_Console_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_SRIO_Console_Console_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_SRIO_Console_Console_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_SRIO_Console_Console_var = r_SRIO_Console_Console_var;

         // force a release since the var's in control of the refcount
         r_SRIO_Console_Console_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_SRIO_Console_Console_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, SRIO_Console::Console::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_SRIO_Console_Console_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_SRIO_Console_Console_var = (SRIO_Console::Console_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }


  // define the member functions in typecode class for SRIO_Console::Console::Operation
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_Operation, SRIO_Console::Console::Operation)

  // typecode instance for SRIO_Console_Console_Operation
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_Operation =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_Operation);

  // define the Any insertion and extraction operators for SRIO_Console::Console::Operation
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::Operation, SRIO_Console::Console::tc_Operation)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::Operation, SRIO_Console::Console::tc_Operation)

  // define the member functions in typecode class for SRIO_Console::Console::TrapType
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_TrapType, SRIO_Console::Console::TrapType)

  // typecode instance for SRIO_Console_Console_TrapType
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_TrapType =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_TrapType);

  // define the Any insertion and extraction operators for SRIO_Console::Console::TrapType
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::TrapType, SRIO_Console::Console::tc_TrapType)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::TrapType, SRIO_Console::Console::tc_TrapType)

  // define the member functions in typecode class for SRIO_Console::Console::PointType
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_PointType, SRIO_Console::Console::PointType)

  // typecode instance for SRIO_Console_Console_PointType
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_PointType =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_PointType);

  // define the Any insertion and extraction operators for SRIO_Console::Console::PointType
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::PointType, SRIO_Console::Console::tc_PointType)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::PointType, SRIO_Console::Console::tc_PointType)

  // define the member functions in typecode class for SRIO_Console::Console::TrackMode
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_TrackMode, SRIO_Console::Console::TrackMode)

  // typecode instance for SRIO_Console_Console_TrackMode
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_TrackMode =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_TrackMode);

  // define the Any insertion and extraction operators for SRIO_Console::Console::TrackMode
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::TrackMode, SRIO_Console::Console::tc_TrackMode)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::TrackMode, SRIO_Console::Console::tc_TrackMode)

  // define the member functions in typecode class for SRIO_Console::Console::FormationType
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_FormationType, SRIO_Console::Console::FormationType)

  // typecode instance for SRIO_Console_Console_FormationType
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_FormationType =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_FormationType);

  // define the Any insertion and extraction operators for SRIO_Console::Console::FormationType
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::FormationType, SRIO_Console::Console::tc_FormationType)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::FormationType, SRIO_Console::Console::tc_FormationType)

  // define the member functions in typecode class for SRIO_Console::Console::FormationState
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_FormationState, SRIO_Console::Console::FormationState)

  // typecode instance for SRIO_Console_Console_FormationState
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_FormationState =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_FormationState);

  // define the Any insertion and extraction operators for SRIO_Console::Console::FormationState
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::FormationState, SRIO_Console::Console::tc_FormationState)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::FormationState, SRIO_Console::Console::tc_FormationState)

  // define the member functions in typecode class for SRIO_Console::Console::MissionState
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_MissionState, SRIO_Console::Console::MissionState)

  // typecode instance for SRIO_Console_Console_MissionState
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_MissionState =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_MissionState);

  // define the Any insertion and extraction operators for SRIO_Console::Console::MissionState
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::MissionState, SRIO_Console::Console::tc_MissionState)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::MissionState, SRIO_Console::Console::tc_MissionState)

  // define the member functions in typecode class for SRIO_Console::Console::Role
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Console_Console_Role, SRIO_Console::Console::Role)

  // typecode instance for SRIO_Console_Console_Role
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_Role =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_Role);

  // define the Any insertion and extraction operators for SRIO_Console::Console::Role
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Console::Console::Role, SRIO_Console::Console::tc_Role)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Console::Console::Role, SRIO_Console::Console::tc_Role)


/////////////////////////////////////////////////////////////////////
//  SRIO_Console::Console::UnbindData members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Console::Console::UnbindData::UnbindData() {
uid = CORBA_(String_var());  // iffy sunpro workaround
details = CORBA_(String_var());  // iffy sunpro workaround
  }

  // copy constructor
  SRIO_Console::Console::UnbindData::UnbindData(const SRIO_Console::Console::UnbindData& r_a_UnbindData) {
          uid = r_a_UnbindData.uid;
          details = r_a_UnbindData.details;
   }

  // destructor
  SRIO_Console::Console::UnbindData::~UnbindData() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::UnbindData& SRIO_Console::Console::UnbindData::self(){
        return *this;
  }

  // assignment operator
  SRIO_Console::Console::UnbindData& SRIO_Console::Console::UnbindData::operator=(
       const SRIO_Console::Console::UnbindData& r_a_UnbindData) {
          if (this != &r_a_UnbindData) {
          uid = r_a_UnbindData.uid;
          details = r_a_UnbindData.details;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Console::Console::UnbindData

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Console::Console::UnbindData& r_SRIO_Console_Console_UnbindData)  {

         r_call += iluSizeRecord;
         iluCardinal r_uid_length =
             strlen(r_SRIO_Console_Console_UnbindData.uid.iluStringVarReference());
          iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Console_Console_UnbindData.uid).iluStringVarReference(),
                  r_uid_length);
         r_call += _r_uid_wrap;
         iluCardinal r_details_length =
             strlen(r_SRIO_Console_Console_UnbindData.details.iluStringVarReference());
          iluCStringWrapper _r_details_wrap(
                 (r_SRIO_Console_Console_UnbindData.details).iluStringVarReference(),
                  r_details_length);
         r_call += _r_details_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Console::Console::UnbindData& r_SRIO_Console_Console_UnbindData)  {

         r_call << iluOutputRecord;
         iluCardinal r_uid_length =
             strlen(r_SRIO_Console_Console_UnbindData.uid.iluStringVarReference());
          iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Console_Console_UnbindData.uid).iluStringVarReference(),
                  r_uid_length);
         r_call << _r_uid_wrap;
         iluCardinal r_details_length =
             strlen(r_SRIO_Console_Console_UnbindData.details.iluStringVarReference());
          iluCStringWrapper _r_details_wrap(
                 (r_SRIO_Console_Console_UnbindData.details).iluStringVarReference(),
                  r_details_length);
         r_call << _r_details_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Console::Console::UnbindData& r_SRIO_Console_Console_UnbindData)  {

         r_call >> iluInputRecord;
         iluCardinal r_uid_length;
         iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Console_Console_UnbindData.uid).iluStringVarReference(),
                  r_uid_length);
         r_call >> _r_uid_wrap;
         iluCardinal r_details_length;
         iluCStringWrapper _r_details_wrap(
                 (r_SRIO_Console_Console_UnbindData.details).iluStringVarReference(),
                  r_details_length);
         r_call >> _r_details_wrap;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Console::Console::UnbindData
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_UnbindData, SRIO_Console::Console::UnbindData)

  // typecode instance for SRIO_Console_Console_UnbindData
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_UnbindData =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_UnbindData);

  // define the Any insert and extract operators for SRIO_Console::Console::UnbindData 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::UnbindData, SRIO_Console::Console::tc_UnbindData)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::UnbindData, SRIO_Console::Console::tc_UnbindData)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::UnbindData, SRIO_Console::Console::tc_UnbindData)


/////////////////////////////////////////////////////////////////////
//  SRIO_Console::Console::CosInfoNode members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Console::Console::CosInfoNode::CosInfoNode() {
uid = CORBA_(String_var)();  // iffy sunpro workaround
sbh = CORBA_(String_var)();  // iffy sunpro workaround
  }

  // copy constructor
  SRIO_Console::Console::CosInfoNode::CosInfoNode(const SRIO_Console::Console::CosInfoNode& r_a_CosInfoNode) {
          uid = r_a_CosInfoNode.uid;
          sbh = r_a_CosInfoNode.sbh;
   }

  // destructor
  SRIO_Console::Console::CosInfoNode::~CosInfoNode() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::CosInfoNode& SRIO_Console::Console::CosInfoNode::self(){
        return *this;
  }

  // assignment operator
  SRIO_Console::Console::CosInfoNode& SRIO_Console::Console::CosInfoNode::operator=(
       const SRIO_Console::Console::CosInfoNode& r_a_CosInfoNode) {
          if (this != &r_a_CosInfoNode) {
          uid = r_a_CosInfoNode.uid;
          sbh = r_a_CosInfoNode.sbh;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Console::Console::CosInfoNode

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Console::Console::CosInfoNode& r_SRIO_Console_Console_CosInfoNode)  {

         r_call += iluSizeRecord;
         iluCardinal r_uid_length =
             strlen(r_SRIO_Console_Console_CosInfoNode.uid.iluStringVarReference());
          iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Console_Console_CosInfoNode.uid).iluStringVarReference(),
                  r_uid_length);
         r_call += _r_uid_wrap;
         iluCardinal r_sbh_length =
             strlen(r_SRIO_Console_Console_CosInfoNode.sbh.iluStringVarReference());
          iluCStringWrapper _r_sbh_wrap(
                 (r_SRIO_Console_Console_CosInfoNode.sbh).iluStringVarReference(),
                  r_sbh_length);
         r_call += _r_sbh_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Console::Console::CosInfoNode& r_SRIO_Console_Console_CosInfoNode)  {

         r_call << iluOutputRecord;
         iluCardinal r_uid_length =
             strlen(r_SRIO_Console_Console_CosInfoNode.uid.iluStringVarReference());
          iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Console_Console_CosInfoNode.uid).iluStringVarReference(),
                  r_uid_length);
         r_call << _r_uid_wrap;
         iluCardinal r_sbh_length =
             strlen(r_SRIO_Console_Console_CosInfoNode.sbh.iluStringVarReference());
          iluCStringWrapper _r_sbh_wrap(
                 (r_SRIO_Console_Console_CosInfoNode.sbh).iluStringVarReference(),
                  r_sbh_length);
         r_call << _r_sbh_wrap;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Console::Console::CosInfoNode& r_SRIO_Console_Console_CosInfoNode)  {

         r_call >> iluInputRecord;
         iluCardinal r_uid_length;
         iluCStringWrapper _r_uid_wrap(
                 (r_SRIO_Console_Console_CosInfoNode.uid).iluStringVarReference(),
                  r_uid_length);
         r_call >> _r_uid_wrap;
         iluCardinal r_sbh_length;
         iluCStringWrapper _r_sbh_wrap(
                 (r_SRIO_Console_Console_CosInfoNode.sbh).iluStringVarReference(),
                  r_sbh_length);
         r_call >> _r_sbh_wrap;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Console::Console::CosInfoNode
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_CosInfoNode, SRIO_Console::Console::CosInfoNode)

  // typecode instance for SRIO_Console_Console_CosInfoNode
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_CosInfoNode =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_CosInfoNode);

  // define the Any insert and extract operators for SRIO_Console::Console::CosInfoNode 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::CosInfoNode, SRIO_Console::Console::tc_CosInfoNode)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::CosInfoNode, SRIO_Console::Console::tc_CosInfoNode)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::CosInfoNode, SRIO_Console::Console::tc_CosInfoNode)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Console::Console::TrapPointSequence members   

 // constructors & destructor
  SRIO_Console::Console::TrapPointSequence::TrapPointSequence () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Console::Console::TrapPointSequence::TrapPointSequence (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Console::Console::TrapPointSequence::TrapPointSequence (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Console::Console::TrapPoint* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Console::Console::TrapPointSequence::~TrapPointSequence() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Console::Console::TrapPointSequence::TrapPointSequence (const SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence)
  :
         m_maximum(r_SRIO_Console_Console_TrapPointSequence.m_maximum),
         m_length(r_SRIO_Console_Console_TrapPointSequence.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Console_Console_TrapPointSequence.m_buffer[index];
            }
   }

 // assignment
   SRIO_Console::Console::TrapPointSequence& SRIO_Console::Console::TrapPointSequence::operator= (const SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence) {
         if (this == &r_SRIO_Console_Console_TrapPointSequence) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Console_Console_TrapPointSequence.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Console_Console_TrapPointSequence.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Console_Console_TrapPointSequence.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Console::Console::TrapPoint* SRIO_Console::Console::TrapPointSequence::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Console::Console::TrapPoint[num_elements]) : NULL);
  }
  
  void SRIO_Console::Console::TrapPointSequence::freebuf(SRIO_Console::Console::TrapPoint* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Console::Console::TrapPointSequence::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Console::Console::TrapPoint* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Console::Console::TrapPointSequence::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Console::Console::TrapPointSequence::length() const {
        return m_length;
  }    
  
  CORBA_(Boolean) SRIO_Console::Console::TrapPointSequence::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Console::Console::TrapPoint* SRIO_Console::Console::TrapPointSequence::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Console::Console::TrapPoint const* SRIO_Console::Console::TrapPointSequence::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Console::Console::TrapPoint& SRIO_Console::Console::TrapPointSequence::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Console::Console::TrapPoint& SRIO_Console::Console::TrapPointSequence::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Console::Console::TrapPoint *_temp = 
              (const SRIO_Console::Console::TrapPoint *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::TrapPointSequence& SRIO_Console::Console::TrapPointSequence::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Console::Console::TrapPointSequence

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence){

        iluCardinal card_length = r_SRIO_Console_Console_TrapPointSequence.length();
        iluSequenceWrapper _r_SRIO_Console_Console_TrapPointSequence(card_length);
        r_call += _r_SRIO_Console_Console_TrapPointSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Console_Console_TrapPointSequence.length(); index++) {
          r_call += r_SRIO_Console_Console_TrapPointSequence[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence){

        iluCardinal card_length = r_SRIO_Console_Console_TrapPointSequence.length();
        iluSequenceWrapper _r_SRIO_Console_Console_TrapPointSequence(card_length);
        r_call << _r_SRIO_Console_Console_TrapPointSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Console_Console_TrapPointSequence.length(); index++) {
          r_call << r_SRIO_Console_Console_TrapPointSequence[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Console::Console::TrapPointSequence _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Console_Console_TrapPointSequence = SRIO_Console::Console::TrapPointSequence(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Console::Console::TrapPointSequence
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_TrapPointSequence, SRIO_Console::Console::TrapPointSequence)

  // typecode instance for SRIO_Console_Console_TrapPointSequence
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_TrapPointSequence =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_TrapPointSequence);

  // define the Any insert and extract operators for SRIO_Console::Console::TrapPointSequence 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::TrapPointSequence, SRIO_Console::Console::tc_TrapPointSequence)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::TrapPointSequence, SRIO_Console::Console::tc_TrapPointSequence)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::TrapPointSequence, SRIO_Console::Console::tc_TrapPointSequence)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Console::Console::PointSeq members   

 // constructors & destructor
  SRIO_Console::Console::PointSeq::PointSeq () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Console::Console::PointSeq::PointSeq (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Console::Console::PointSeq::PointSeq (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Console::Console::Point* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Console::Console::PointSeq::~PointSeq() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Console::Console::PointSeq::PointSeq (const SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq)
  :
         m_maximum(r_SRIO_Console_Console_PointSeq.m_maximum),
         m_length(r_SRIO_Console_Console_PointSeq.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Console_Console_PointSeq.m_buffer[index];
            }
   }

 // assignment
   SRIO_Console::Console::PointSeq& SRIO_Console::Console::PointSeq::operator= (const SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq) {
         if (this == &r_SRIO_Console_Console_PointSeq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Console_Console_PointSeq.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Console_Console_PointSeq.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Console_Console_PointSeq.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Console::Console::Point* SRIO_Console::Console::PointSeq::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Console::Console::Point[num_elements]) : NULL);
  }
  
  void SRIO_Console::Console::PointSeq::freebuf(SRIO_Console::Console::Point* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Console::Console::PointSeq::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Console::Console::Point* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Console::Console::PointSeq::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Console::Console::PointSeq::length() const {
        return m_length;
  }    
  
  CORBA_(Boolean) SRIO_Console::Console::PointSeq::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Console::Console::Point* SRIO_Console::Console::PointSeq::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Console::Console::Point const* SRIO_Console::Console::PointSeq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Console::Console::Point& SRIO_Console::Console::PointSeq::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Console::Console::Point& SRIO_Console::Console::PointSeq::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Console::Console::Point *_temp = 
              (const SRIO_Console::Console::Point *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::PointSeq& SRIO_Console::Console::PointSeq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Console::Console::PointSeq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq){

        iluCardinal card_length = r_SRIO_Console_Console_PointSeq.length();
        iluSequenceWrapper _r_SRIO_Console_Console_PointSeq(card_length);
        r_call += _r_SRIO_Console_Console_PointSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Console_Console_PointSeq.length(); index++) {
          r_call += r_SRIO_Console_Console_PointSeq[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq){

        iluCardinal card_length = r_SRIO_Console_Console_PointSeq.length();
        iluSequenceWrapper _r_SRIO_Console_Console_PointSeq(card_length);
        r_call << _r_SRIO_Console_Console_PointSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Console_Console_PointSeq.length(); index++) {
          r_call << r_SRIO_Console_Console_PointSeq[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Console::Console::PointSeq _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Console_Console_PointSeq = SRIO_Console::Console::PointSeq(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Console::Console::PointSeq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_PointSeq, SRIO_Console::Console::PointSeq)

  // typecode instance for SRIO_Console_Console_PointSeq
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_PointSeq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_PointSeq);

  // define the Any insert and extract operators for SRIO_Console::Console::PointSeq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::PointSeq, SRIO_Console::Console::tc_PointSeq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::PointSeq, SRIO_Console::Console::tc_PointSeq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::PointSeq, SRIO_Console::Console::tc_PointSeq)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Console::Console::CosInfoSeq members   

 // constructors & destructor
  SRIO_Console::Console::CosInfoSeq::CosInfoSeq () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Console::Console::CosInfoSeq::CosInfoSeq (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Console::Console::CosInfoSeq::CosInfoSeq (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Console::Console::CosInfoNode* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Console::Console::CosInfoSeq::~CosInfoSeq() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Console::Console::CosInfoSeq::CosInfoSeq (const SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq)
  :
         m_maximum(r_SRIO_Console_Console_CosInfoSeq.m_maximum),
         m_length(r_SRIO_Console_Console_CosInfoSeq.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Console_Console_CosInfoSeq.m_buffer[index];
            }
   }

 // assignment
   SRIO_Console::Console::CosInfoSeq& SRIO_Console::Console::CosInfoSeq::operator= (const SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq) {
         if (this == &r_SRIO_Console_Console_CosInfoSeq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Console_Console_CosInfoSeq.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Console_Console_CosInfoSeq.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Console_Console_CosInfoSeq.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Console::Console::CosInfoNode* SRIO_Console::Console::CosInfoSeq::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Console::Console::CosInfoNode[num_elements]) : NULL);
  }
  
  void SRIO_Console::Console::CosInfoSeq::freebuf(SRIO_Console::Console::CosInfoNode* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Console::Console::CosInfoSeq::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Console::Console::CosInfoNode* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Console::Console::CosInfoSeq::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Console::Console::CosInfoSeq::length() const {
        return m_length;
  }    
  
  CORBA_(Boolean) SRIO_Console::Console::CosInfoSeq::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Console::Console::CosInfoNode* SRIO_Console::Console::CosInfoSeq::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Console::Console::CosInfoNode const* SRIO_Console::Console::CosInfoSeq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Console::Console::CosInfoNode& SRIO_Console::Console::CosInfoSeq::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Console::Console::CosInfoNode& SRIO_Console::Console::CosInfoSeq::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Console::Console::CosInfoNode *_temp = 
              (const SRIO_Console::Console::CosInfoNode *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::CosInfoSeq& SRIO_Console::Console::CosInfoSeq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Console::Console::CosInfoSeq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq){

        iluCardinal card_length = r_SRIO_Console_Console_CosInfoSeq.length();
        iluSequenceWrapper _r_SRIO_Console_Console_CosInfoSeq(card_length);
        r_call += _r_SRIO_Console_Console_CosInfoSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Console_Console_CosInfoSeq.length(); index++) {
          r_call += r_SRIO_Console_Console_CosInfoSeq[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq){

        iluCardinal card_length = r_SRIO_Console_Console_CosInfoSeq.length();
        iluSequenceWrapper _r_SRIO_Console_Console_CosInfoSeq(card_length);
        r_call << _r_SRIO_Console_Console_CosInfoSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Console_Console_CosInfoSeq.length(); index++) {
          r_call << r_SRIO_Console_Console_CosInfoSeq[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Console::Console::CosInfoSeq _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Console_Console_CosInfoSeq = SRIO_Console::Console::CosInfoSeq(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Console::Console::CosInfoSeq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_CosInfoSeq, SRIO_Console::Console::CosInfoSeq)

  // typecode instance for SRIO_Console_Console_CosInfoSeq
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_CosInfoSeq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_CosInfoSeq);

  // define the Any insert and extract operators for SRIO_Console::Console::CosInfoSeq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::CosInfoSeq, SRIO_Console::Console::tc_CosInfoSeq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::CosInfoSeq, SRIO_Console::Console::tc_CosInfoSeq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::CosInfoSeq, SRIO_Console::Console::tc_CosInfoSeq)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Console::Console::Message members
		
  // constructors & destructor
  SRIO_Console::Console::Message::Message() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Console::Console::Message::Message(const SRIO_Console::Console::Message& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Console::Console::Message::~Message() {
	  unset();
  }

  // assignment
  SRIO_Console::Console::Message& SRIO_Console::Console::Message::operator=
          (const SRIO_Console::Console::Message& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // infoSeq
		  case SRIO_Console::Console::OP_SetCosInfo:  
                   m_infoSeq =
                      new SRIO_Console::Console::CosInfoSeq(*r_union_type.m_infoSeq);
                   break;

                 // bindInfo
		  case SRIO_Console::Console::OP_Bind:  
                   m_bindInfo =
                      new SRIO_Console::Console::CosInfoNode(*r_union_type.m_bindInfo);
                   break;

                 // unbindInfo
		  case SRIO_Console::Console::OP_Unbind:  
                   m_unbindInfo =
                      new SRIO_Console::Console::UnbindData(*r_union_type.m_unbindInfo);
                   break;

                 // tp
		  case SRIO_Console::Console::OP_ReportTrap:  
		  case SRIO_Console::Console::OP_AddTrap:  
                   m_tp =
                      new SRIO_Console::Console::TrapPoint(*r_union_type.m_tp);
                   break;

                 // details
		  case SRIO_Console::Console::OP_Opened:  
		  case SRIO_Console::Console::OP_Closed:  
                   m_details =
                      new CORBA_(String_var)(
                        r_union_type.m_details->iluStringVarReference());
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::Message& SRIO_Console::Console::Message::self(){
        return *this;
  }

  // discriminator access
  SRIO_Console::Console::Operation SRIO_Console::Console::Message::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Console::Console::Message::_d (SRIO_Console::Console::Operation new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // infoSeq
		  case SRIO_Console::Console::OP_SetCosInfo:  
                  switch(new_d) { 
                       case SRIO_Console::Console::OP_SetCosInfo: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // bindInfo
		  case SRIO_Console::Console::OP_Bind:  
                  switch(new_d) { 
                       case SRIO_Console::Console::OP_Bind: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // unbindInfo
		  case SRIO_Console::Console::OP_Unbind:  
                  switch(new_d) { 
                       case SRIO_Console::Console::OP_Unbind: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // tp
		  case SRIO_Console::Console::OP_ReportTrap:  
		  case SRIO_Console::Console::OP_AddTrap:  
                  switch(new_d) { 
                       case SRIO_Console::Console::OP_ReportTrap: 
                       case SRIO_Console::Console::OP_AddTrap: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // details
		  case SRIO_Console::Console::OP_Opened:  
		  case SRIO_Console::Console::OP_Closed:  
                  switch(new_d) { 
                       case SRIO_Console::Console::OP_Opened: 
                       case SRIO_Console::Console::OP_Closed: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Console::Console::OP_SetCosInfo: 
                       case SRIO_Console::Console::OP_Bind: 
                       case SRIO_Console::Console::OP_Unbind: 
                       case SRIO_Console::Console::OP_ReportTrap: 
                       case SRIO_Console::Console::OP_AddTrap: 
                       case SRIO_Console::Console::OP_Opened: 
                       case SRIO_Console::Console::OP_Closed: 
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
 
   // infoSeq access
    const SRIO_Console::Console::CosInfoSeq& SRIO_Console::Console::Message::infoSeq() const {
           return( (const SRIO_Console::Console::CosInfoSeq&) *m_infoSeq);
    }

    SRIO_Console::Console::CosInfoSeq& SRIO_Console::Console::Message::infoSeq(){
           return( (SRIO_Console::Console::CosInfoSeq&) *m_infoSeq);
    }

    void SRIO_Console::Console::Message::infoSeq(const SRIO_Console::Console::CosInfoSeq & a_infoSeq){
         unset();
         m_discriminator = SRIO_Console::Console::OP_SetCosInfo;
         m_infoSeq = new SRIO_Console::Console::CosInfoSeq(a_infoSeq);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // bindInfo access
    const SRIO_Console::Console::CosInfoNode& SRIO_Console::Console::Message::bindInfo() const {
           return( (const SRIO_Console::Console::CosInfoNode&) *m_bindInfo);
    }

    SRIO_Console::Console::CosInfoNode& SRIO_Console::Console::Message::bindInfo(){
           return( (SRIO_Console::Console::CosInfoNode&) *m_bindInfo);
    }

    void SRIO_Console::Console::Message::bindInfo(const SRIO_Console::Console::CosInfoNode & a_bindInfo){
         unset();
         m_discriminator = SRIO_Console::Console::OP_Bind;
         m_bindInfo = new SRIO_Console::Console::CosInfoNode(a_bindInfo);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // unbindInfo access
    const SRIO_Console::Console::UnbindData& SRIO_Console::Console::Message::unbindInfo() const {
           return( (const SRIO_Console::Console::UnbindData&) *m_unbindInfo);
    }

    SRIO_Console::Console::UnbindData& SRIO_Console::Console::Message::unbindInfo(){
           return( (SRIO_Console::Console::UnbindData&) *m_unbindInfo);
    }

    void SRIO_Console::Console::Message::unbindInfo(const SRIO_Console::Console::UnbindData & a_unbindInfo){
         unset();
         m_discriminator = SRIO_Console::Console::OP_Unbind;
         m_unbindInfo = new SRIO_Console::Console::UnbindData(a_unbindInfo);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // tp access
    const SRIO_Console::Console::TrapPoint& SRIO_Console::Console::Message::tp() const {
           return( (const SRIO_Console::Console::TrapPoint&) *m_tp);
    }

    SRIO_Console::Console::TrapPoint& SRIO_Console::Console::Message::tp(){
           return( (SRIO_Console::Console::TrapPoint&) *m_tp);
    }

    void SRIO_Console::Console::Message::tp(const SRIO_Console::Console::TrapPoint & a_tp){
         unset();
         m_discriminator = SRIO_Console::Console::OP_ReportTrap;
         m_tp = new SRIO_Console::Console::TrapPoint(a_tp);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // details access

   const iluShortCharacter *SRIO_Console::Console::Message::details() const{
        return (m_details->iluStringVarReference());
   }

   void SRIO_Console::Console::Message::details(iluShortCharacter * a_details){
         unset();
         m_discriminator = SRIO_Console::Console::OP_Opened;
         m_details = new CORBA_(String_var)(a_details);
         m_b_beenset = ILUCPP_TRUE;
   }
         

   void SRIO_Console::Console::Message::details(const iluShortCharacter * a_details){
         unset();
         m_discriminator = SRIO_Console::Console::OP_Opened;
         m_details = new CORBA_(String_var)(a_details);
         m_b_beenset = ILUCPP_TRUE;
   }

   void SRIO_Console::Console::Message::details(const CORBA_(String_var)& a_details){
         unset();
         m_discriminator = SRIO_Console::Console::OP_Opened;
         m_details = new CORBA_(String_var)(a_details);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  void SRIO_Console::Console::Message::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // infoSeq
		  case SRIO_Console::Console::OP_SetCosInfo:  
                     delete m_infoSeq;
                     break;

                 // bindInfo
		  case SRIO_Console::Console::OP_Bind:  
                     delete m_bindInfo;
                     break;

                 // unbindInfo
		  case SRIO_Console::Console::OP_Unbind:  
                     delete m_unbindInfo;
                     break;

                 // tp
		  case SRIO_Console::Console::OP_ReportTrap:  
		  case SRIO_Console::Console::OP_AddTrap:  
                     delete m_tp;
                     break;

                 // details
		  case SRIO_Console::Console::OP_Opened:  
		  case SRIO_Console::Console::OP_Closed:  
                     delete m_details;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Console::Console::Message

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Console::Console::Message& r_SRIO_Console_Console_Message) {

          iluUnionWrapper _r_SRIO_Console_Console_Message(
                                r_SRIO_Console_Console_Message._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Console_Console_Message;

          switch (r_SRIO_Console_Console_Message.m_discriminator) {

                 // infoSeq
		  case SRIO_Console::Console::OP_SetCosInfo:  
                    r_call += (*r_SRIO_Console_Console_Message.m_infoSeq); 
                   break;

                 // bindInfo
		  case SRIO_Console::Console::OP_Bind:  
                    r_call += (*r_SRIO_Console_Console_Message.m_bindInfo); 
                   break;

                 // unbindInfo
		  case SRIO_Console::Console::OP_Unbind:  
                    r_call += (*r_SRIO_Console_Console_Message.m_unbindInfo); 
                   break;

                 // tp
		  case SRIO_Console::Console::OP_ReportTrap:  
		  case SRIO_Console::Console::OP_AddTrap:  
                    r_call += (*r_SRIO_Console_Console_Message.m_tp); 
                   break;

                 // details
		  case SRIO_Console::Console::OP_Opened:  
		  case SRIO_Console::Console::OP_Closed:  
                   { iluCardinal _r_details_length =
                    strlen(r_SRIO_Console_Console_Message.m_details->iluStringVarReference());
                    iluCStringWrapper _r_details_wrap(
                       (*r_SRIO_Console_Console_Message.m_details).iluStringVarReference(),
                            _r_details_length);
                    r_call += _r_details_wrap;
                   }
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Console::Console::Message& r_SRIO_Console_Console_Message) {

          iluUnionWrapper _r_SRIO_Console_Console_Message(
                                r_SRIO_Console_Console_Message._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Console_Console_Message;

          switch (r_SRIO_Console_Console_Message.m_discriminator) {

                 // infoSeq
		  case SRIO_Console::Console::OP_SetCosInfo:  
                    r_call << (*r_SRIO_Console_Console_Message.m_infoSeq); 
                   break;

                 // bindInfo
		  case SRIO_Console::Console::OP_Bind:  
                    r_call << (*r_SRIO_Console_Console_Message.m_bindInfo); 
                   break;

                 // unbindInfo
		  case SRIO_Console::Console::OP_Unbind:  
                    r_call << (*r_SRIO_Console_Console_Message.m_unbindInfo); 
                   break;

                 // tp
		  case SRIO_Console::Console::OP_ReportTrap:  
		  case SRIO_Console::Console::OP_AddTrap:  
                    r_call << (*r_SRIO_Console_Console_Message.m_tp); 
                   break;

                 // details
		  case SRIO_Console::Console::OP_Opened:  
		  case SRIO_Console::Console::OP_Closed:  
                   { iluCardinal _r_details_length =
                    strlen(r_SRIO_Console_Console_Message.m_details->iluStringVarReference());
                    iluCStringWrapper _r_details_wrap(
                       (*r_SRIO_Console_Console_Message.m_details).iluStringVarReference(),
                            _r_details_length);
                    r_call << _r_details_wrap;
                   }
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Console::Console::Message& r_SRIO_Console_Console_Message) {
        
          iluUnionWrapper _r_SRIO_Console_Console_Message(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Console_Console_Message;

          switch (_r_SRIO_Console_Console_Message.m_card_discriminator) {

                 // infoSeq
		  case SRIO_Console::Console::OP_SetCosInfo:  
                 { SRIO_Console::Console::CosInfoSeq  infoSeq_temp;
                    r_call >> infoSeq_temp;
                    r_SRIO_Console_Console_Message.infoSeq(infoSeq_temp);
                    break;
                   }

                 // bindInfo
		  case SRIO_Console::Console::OP_Bind:  
                 { SRIO_Console::Console::CosInfoNode  bindInfo_temp;
                    r_call >> bindInfo_temp;
                    r_SRIO_Console_Console_Message.bindInfo(bindInfo_temp);
                    break;
                   }

                 // unbindInfo
		  case SRIO_Console::Console::OP_Unbind:  
                 { SRIO_Console::Console::UnbindData  unbindInfo_temp;
                    r_call >> unbindInfo_temp;
                    r_SRIO_Console_Console_Message.unbindInfo(unbindInfo_temp);
                    break;
                   }

                 // tp
		  case SRIO_Console::Console::OP_ReportTrap:  
		  case SRIO_Console::Console::OP_AddTrap:  
                 { SRIO_Console::Console::TrapPoint  tp_temp;
                    r_call >> tp_temp;
                    r_SRIO_Console_Console_Message.tp(tp_temp);
                    break;
                   }

                 // details
		  case SRIO_Console::Console::OP_Opened:  
		  case SRIO_Console::Console::OP_Closed:  
                 { CORBA_(String_var)  details_temp;
                     iluCardinal _r_details_length;
                     iluCStringWrapper _r_details_wrap(
                             details_temp.iluStringVarReference(),
                            _r_details_length);
                     r_call >> _r_details_wrap;
                     r_SRIO_Console_Console_Message.details(details_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Console_Console_Message._d((SRIO_Console::Console::Operation) (_r_SRIO_Console_Console_Message.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Console::Console::Message
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_Message, SRIO_Console::Console::Message)

  // typecode instance for SRIO_Console_Console_Message
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_Message =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_Message);

  // define the Any insert and extract operators for SRIO_Console::Console::Message 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::Message, SRIO_Console::Console::tc_Message)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::Message, SRIO_Console::Console::tc_Message)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::Message, SRIO_Console::Console::tc_Message)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Console::Console::TrapPoint members
		
  // constructors & destructor
  SRIO_Console::Console::TrapPoint::TrapPoint() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Console::Console::TrapPoint::TrapPoint(const SRIO_Console::Console::TrapPoint& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Console::Console::TrapPoint::~TrapPoint() {
	  unset();
  }

  // assignment
  SRIO_Console::Console::TrapPoint& SRIO_Console::Console::TrapPoint::operator=
          (const SRIO_Console::Console::TrapPoint& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // trapPoint2D
		  case SRIO_Console::Console::TrapGroundType:  
                   m_trapPoint2D =
                      new SRIO_Ground_Unit::Ground_Unit::TrapPoint2D(*r_union_type.m_trapPoint2D);
                   break;

                 // trapPoint3D
		  case SRIO_Console::Console::TrapAirType:  
                   m_trapPoint3D =
                      new SRIO_Air_Unit::Air_Unit::TrapPoint3D(*r_union_type.m_trapPoint3D);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::TrapPoint& SRIO_Console::Console::TrapPoint::self(){
        return *this;
  }

  // discriminator access
  SRIO_Console::Console::TrapType SRIO_Console::Console::TrapPoint::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Console::Console::TrapPoint::_d (SRIO_Console::Console::TrapType new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // trapPoint2D
		  case SRIO_Console::Console::TrapGroundType:  
                  switch(new_d) { 
                       case SRIO_Console::Console::TrapGroundType: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // trapPoint3D
		  case SRIO_Console::Console::TrapAirType:  
                  switch(new_d) { 
                       case SRIO_Console::Console::TrapAirType: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Console::Console::TrapGroundType: 
                       case SRIO_Console::Console::TrapAirType: 
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
 
   // trapPoint2D access
    const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& SRIO_Console::Console::TrapPoint::trapPoint2D() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D&) *m_trapPoint2D);
    }

    SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& SRIO_Console::Console::TrapPoint::trapPoint2D(){
           return( (SRIO_Ground_Unit::Ground_Unit::TrapPoint2D&) *m_trapPoint2D);
    }

    void SRIO_Console::Console::TrapPoint::trapPoint2D(const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D & a_trapPoint2D){
         unset();
         m_discriminator = SRIO_Console::Console::TrapGroundType;
         m_trapPoint2D = new SRIO_Ground_Unit::Ground_Unit::TrapPoint2D(a_trapPoint2D);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // trapPoint3D access
    const SRIO_Air_Unit::Air_Unit::TrapPoint3D& SRIO_Console::Console::TrapPoint::trapPoint3D() const {
           return( (const SRIO_Air_Unit::Air_Unit::TrapPoint3D&) *m_trapPoint3D);
    }

    SRIO_Air_Unit::Air_Unit::TrapPoint3D& SRIO_Console::Console::TrapPoint::trapPoint3D(){
           return( (SRIO_Air_Unit::Air_Unit::TrapPoint3D&) *m_trapPoint3D);
    }

    void SRIO_Console::Console::TrapPoint::trapPoint3D(const SRIO_Air_Unit::Air_Unit::TrapPoint3D & a_trapPoint3D){
         unset();
         m_discriminator = SRIO_Console::Console::TrapAirType;
         m_trapPoint3D = new SRIO_Air_Unit::Air_Unit::TrapPoint3D(a_trapPoint3D);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  void SRIO_Console::Console::TrapPoint::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // trapPoint2D
		  case SRIO_Console::Console::TrapGroundType:  
                     delete m_trapPoint2D;
                     break;

                 // trapPoint3D
		  case SRIO_Console::Console::TrapAirType:  
                     delete m_trapPoint3D;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Console::Console::TrapPoint

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Console::Console::TrapPoint& r_SRIO_Console_Console_TrapPoint) {

          iluUnionWrapper _r_SRIO_Console_Console_TrapPoint(
                                r_SRIO_Console_Console_TrapPoint._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Console_Console_TrapPoint;

          switch (r_SRIO_Console_Console_TrapPoint.m_discriminator) {

                 // trapPoint2D
		  case SRIO_Console::Console::TrapGroundType:  
                    r_call += (*r_SRIO_Console_Console_TrapPoint.m_trapPoint2D); 
                   break;

                 // trapPoint3D
		  case SRIO_Console::Console::TrapAirType:  
                    r_call += (*r_SRIO_Console_Console_TrapPoint.m_trapPoint3D); 
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Console::Console::TrapPoint& r_SRIO_Console_Console_TrapPoint) {

          iluUnionWrapper _r_SRIO_Console_Console_TrapPoint(
                                r_SRIO_Console_Console_TrapPoint._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Console_Console_TrapPoint;

          switch (r_SRIO_Console_Console_TrapPoint.m_discriminator) {

                 // trapPoint2D
		  case SRIO_Console::Console::TrapGroundType:  
                    r_call << (*r_SRIO_Console_Console_TrapPoint.m_trapPoint2D); 
                   break;

                 // trapPoint3D
		  case SRIO_Console::Console::TrapAirType:  
                    r_call << (*r_SRIO_Console_Console_TrapPoint.m_trapPoint3D); 
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Console::Console::TrapPoint& r_SRIO_Console_Console_TrapPoint) {
        
          iluUnionWrapper _r_SRIO_Console_Console_TrapPoint(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Console_Console_TrapPoint;

          switch (_r_SRIO_Console_Console_TrapPoint.m_card_discriminator) {

                 // trapPoint2D
		  case SRIO_Console::Console::TrapGroundType:  
                 { SRIO_Ground_Unit::Ground_Unit::TrapPoint2D  trapPoint2D_temp;
                    r_call >> trapPoint2D_temp;
                    r_SRIO_Console_Console_TrapPoint.trapPoint2D(trapPoint2D_temp);
                    break;
                   }

                 // trapPoint3D
		  case SRIO_Console::Console::TrapAirType:  
                 { SRIO_Air_Unit::Air_Unit::TrapPoint3D  trapPoint3D_temp;
                    r_call >> trapPoint3D_temp;
                    r_SRIO_Console_Console_TrapPoint.trapPoint3D(trapPoint3D_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Console_Console_TrapPoint._d((SRIO_Console::Console::TrapType) (_r_SRIO_Console_Console_TrapPoint.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Console::Console::TrapPoint
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_TrapPoint, SRIO_Console::Console::TrapPoint)

  // typecode instance for SRIO_Console_Console_TrapPoint
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_TrapPoint =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_TrapPoint);

  // define the Any insert and extract operators for SRIO_Console::Console::TrapPoint 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::TrapPoint, SRIO_Console::Console::tc_TrapPoint)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::TrapPoint, SRIO_Console::Console::tc_TrapPoint)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::TrapPoint, SRIO_Console::Console::tc_TrapPoint)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Console::Console::Point members
		
  // constructors & destructor
  SRIO_Console::Console::Point::Point() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Console::Console::Point::Point(const SRIO_Console::Console::Point& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Console::Console::Point::~Point() {
	  unset();
  }

  // assignment
  SRIO_Console::Console::Point& SRIO_Console::Console::Point::operator=
          (const SRIO_Console::Console::Point& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // p2D
		  case SRIO_Console::Console::PointGroundType:  
                   m_p2D =
                      new SRIO_Ground_Unit::Ground_Unit::Point2D(*r_union_type.m_p2D);
                   break;

                 // p3D
		  case SRIO_Console::Console::PointAirType:  
                   m_p3D =
                      new SRIO_Air_Unit::Air_Unit::Point3D(*r_union_type.m_p3D);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::Point& SRIO_Console::Console::Point::self(){
        return *this;
  }

  // discriminator access
  SRIO_Console::Console::PointType SRIO_Console::Console::Point::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Console::Console::Point::_d (SRIO_Console::Console::PointType new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // p2D
		  case SRIO_Console::Console::PointGroundType:  
                  switch(new_d) { 
                       case SRIO_Console::Console::PointGroundType: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // p3D
		  case SRIO_Console::Console::PointAirType:  
                  switch(new_d) { 
                       case SRIO_Console::Console::PointAirType: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Console::Console::PointGroundType: 
                       case SRIO_Console::Console::PointAirType: 
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
 
   // p2D access
    const SRIO_Ground_Unit::Ground_Unit::Point2D& SRIO_Console::Console::Point::p2D() const {
           return( (const SRIO_Ground_Unit::Ground_Unit::Point2D&) *m_p2D);
    }

    SRIO_Ground_Unit::Ground_Unit::Point2D& SRIO_Console::Console::Point::p2D(){
           return( (SRIO_Ground_Unit::Ground_Unit::Point2D&) *m_p2D);
    }

    void SRIO_Console::Console::Point::p2D(const SRIO_Ground_Unit::Ground_Unit::Point2D & a_p2D){
         unset();
         m_discriminator = SRIO_Console::Console::PointGroundType;
         m_p2D = new SRIO_Ground_Unit::Ground_Unit::Point2D(a_p2D);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // p3D access
    const SRIO_Air_Unit::Air_Unit::Point3D& SRIO_Console::Console::Point::p3D() const {
           return( (const SRIO_Air_Unit::Air_Unit::Point3D&) *m_p3D);
    }

    SRIO_Air_Unit::Air_Unit::Point3D& SRIO_Console::Console::Point::p3D(){
           return( (SRIO_Air_Unit::Air_Unit::Point3D&) *m_p3D);
    }

    void SRIO_Console::Console::Point::p3D(const SRIO_Air_Unit::Air_Unit::Point3D & a_p3D){
         unset();
         m_discriminator = SRIO_Console::Console::PointAirType;
         m_p3D = new SRIO_Air_Unit::Air_Unit::Point3D(a_p3D);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  void SRIO_Console::Console::Point::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // p2D
		  case SRIO_Console::Console::PointGroundType:  
                     delete m_p2D;
                     break;

                 // p3D
		  case SRIO_Console::Console::PointAirType:  
                     delete m_p3D;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Console::Console::Point

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Console::Console::Point& r_SRIO_Console_Console_Point) {

          iluUnionWrapper _r_SRIO_Console_Console_Point(
                                r_SRIO_Console_Console_Point._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Console_Console_Point;

          switch (r_SRIO_Console_Console_Point.m_discriminator) {

                 // p2D
		  case SRIO_Console::Console::PointGroundType:  
                    r_call += (*r_SRIO_Console_Console_Point.m_p2D); 
                   break;

                 // p3D
		  case SRIO_Console::Console::PointAirType:  
                    r_call += (*r_SRIO_Console_Console_Point.m_p3D); 
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Console::Console::Point& r_SRIO_Console_Console_Point) {

          iluUnionWrapper _r_SRIO_Console_Console_Point(
                                r_SRIO_Console_Console_Point._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Console_Console_Point;

          switch (r_SRIO_Console_Console_Point.m_discriminator) {

                 // p2D
		  case SRIO_Console::Console::PointGroundType:  
                    r_call << (*r_SRIO_Console_Console_Point.m_p2D); 
                   break;

                 // p3D
		  case SRIO_Console::Console::PointAirType:  
                    r_call << (*r_SRIO_Console_Console_Point.m_p3D); 
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Console::Console::Point& r_SRIO_Console_Console_Point) {
        
          iluUnionWrapper _r_SRIO_Console_Console_Point(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Console_Console_Point;

          switch (_r_SRIO_Console_Console_Point.m_card_discriminator) {

                 // p2D
		  case SRIO_Console::Console::PointGroundType:  
                 { SRIO_Ground_Unit::Ground_Unit::Point2D  p2D_temp;
                    r_call >> p2D_temp;
                    r_SRIO_Console_Console_Point.p2D(p2D_temp);
                    break;
                   }

                 // p3D
		  case SRIO_Console::Console::PointAirType:  
                 { SRIO_Air_Unit::Air_Unit::Point3D  p3D_temp;
                    r_call >> p3D_temp;
                    r_SRIO_Console_Console_Point.p3D(p3D_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Console_Console_Point._d((SRIO_Console::Console::PointType) (_r_SRIO_Console_Console_Point.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Console::Console::Point
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_Point, SRIO_Console::Console::Point)

  // typecode instance for SRIO_Console_Console_Point
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_Point =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_Point);

  // define the Any insert and extract operators for SRIO_Console::Console::Point 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::Point, SRIO_Console::Console::tc_Point)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::Point, SRIO_Console::Console::tc_Point)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::Point, SRIO_Console::Console::tc_Point)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Console::Console::MissionStateData members
		
  // constructors & destructor
  SRIO_Console::Console::MissionStateData::MissionStateData() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Console::Console::MissionStateData::MissionStateData(const SRIO_Console::Console::MissionStateData& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Console::Console::MissionStateData::~MissionStateData() {
	  unset();
  }

  // assignment
  SRIO_Console::Console::MissionStateData& SRIO_Console::Console::MissionStateData::operator=
          (const SRIO_Console::Console::MissionStateData& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // time
		  case SRIO_Console::Console::MissionSuspend:  
                  m_time = r_union_type.m_time;
                  break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Console::Console::MissionStateData& SRIO_Console::Console::MissionStateData::self(){
        return *this;
  }

  // discriminator access
  SRIO_Console::Console::MissionState SRIO_Console::Console::MissionStateData::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Console::Console::MissionStateData::_d (SRIO_Console::Console::MissionState new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // time
		  case SRIO_Console::Console::MissionSuspend:  
                  switch(new_d) { 
                       case SRIO_Console::Console::MissionSuspend: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Console::Console::MissionSuspend: 
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
 
   // time access
     CORBA_(Short) SRIO_Console::Console::MissionStateData::time () const {
       return m_time;
     }

     void SRIO_Console::Console::MissionStateData::time (CORBA_(Short) a_time) {
          unset();			
          m_discriminator = SRIO_Console::Console::MissionSuspend;
          m_time = a_time;
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  void SRIO_Console::Console::MissionStateData::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // time
		  case SRIO_Console::Console::MissionSuspend:  
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Console::Console::MissionStateData

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Console::Console::MissionStateData& r_SRIO_Console_Console_MissionStateData) {

          iluUnionWrapper _r_SRIO_Console_Console_MissionStateData(
                                r_SRIO_Console_Console_MissionStateData._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Console_Console_MissionStateData;

          switch (r_SRIO_Console_Console_MissionStateData.m_discriminator) {

                 // time
		  case SRIO_Console::Console::MissionSuspend:  
                    r_call += r_SRIO_Console_Console_MissionStateData.m_time;
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Console::Console::MissionStateData& r_SRIO_Console_Console_MissionStateData) {

          iluUnionWrapper _r_SRIO_Console_Console_MissionStateData(
                                r_SRIO_Console_Console_MissionStateData._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Console_Console_MissionStateData;

          switch (r_SRIO_Console_Console_MissionStateData.m_discriminator) {

                 // time
		  case SRIO_Console::Console::MissionSuspend:  
                    r_call << r_SRIO_Console_Console_MissionStateData.m_time;
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Console::Console::MissionStateData& r_SRIO_Console_Console_MissionStateData) {
        
          iluUnionWrapper _r_SRIO_Console_Console_MissionStateData(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Console_Console_MissionStateData;

          switch (_r_SRIO_Console_Console_MissionStateData.m_card_discriminator) {

                 // time
		  case SRIO_Console::Console::MissionSuspend:  
                 { CORBA_(Short)  time_temp;
                    r_call >> time_temp;
                    r_SRIO_Console_Console_MissionStateData.time(time_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Console_Console_MissionStateData._d((SRIO_Console::Console::MissionState) (_r_SRIO_Console_Console_MissionStateData.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Console::Console::MissionStateData
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Console_Console_MissionStateData, SRIO_Console::Console::MissionStateData)

  // typecode instance for SRIO_Console_Console_MissionStateData
  const CORBA_(TypeCode_ptr) SRIO_Console::Console::tc_MissionStateData =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console_MissionStateData);

  // define the Any insert and extract operators for SRIO_Console::Console::MissionStateData 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::MissionStateData, SRIO_Console::Console::tc_MissionStateData)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Console::Console::MissionStateData, SRIO_Console::Console::tc_MissionStateData)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Console::Console::MissionStateData, SRIO_Console::Console::tc_MissionStateData)

  //////////////////////////////////////////////////////////////////////
  // SRIO_Console::Console members

  // CORBA object reference operations

  SRIO_Console::Console_ptr SRIO_Console::Console::_duplicate( Console_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  SRIO_Console::Console_ptr SRIO_Console::Console::_nil() {
    return (Console_ptr) NULL;
  }

  // default constructor
  SRIO_Console::Console::Console() {
     // to be determined
  }

  // destructor
  SRIO_Console::Console::~Console() {
    // to be determined
  }

  // copy constructor
  SRIO_Console::Console::Console(const Console&) {
    // to be determined
  }

  // assignment operator
  void SRIO_Console::Console::operator=(const Console&) {
    // to be determined
  }

  // Simple Object Lookup
  SRIO_Console::Console_ptr SRIO_Console::Console::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Console_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
//  void *SRIO_Console::Console::iluDowncast (iluClass class_to_cast_down_to) {
//    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
//      return((void *)((iluObject*) this));
//    if (class_to_cast_down_to == CORBA::Object::iluGetILUClassRecord())
//       return((void *) ((CORBA_(Object_ptr)) this));
//    if (class_to_cast_down_to == m_ILUClassRecord)
//      return ((void*) this);
//    return (NULL);
//  }

  void* SRIO_Console::Console::iluDowncast(iluClass class_to_cast_down_to) {
      if (!class_to_cast_down_to || class_to_cast_down_to == ilu_rootClass)
          return static_cast<void*>(static_cast<iluObject*>(this));

      if (class_to_cast_down_to == CORBA_(Object)::iluGetILUClassRecord())
          return static_cast<void*>(static_cast<CORBA_(Object_ptr)>(this));

      if (class_to_cast_down_to == m_ILUClassRecord)
          return static_cast<void*>(this);

      return nullptr;
  }


  // initialize to use of this class of objects - called by iluInitialize

  void SRIO_Console::Console::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "IDL:omg.org/CORBA/Object:1.0"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "SRIO_Console.Console"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "IDL:SRIO_Console/Console:1.0"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_TRUE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      35,          // number of methods
      1,          // number of superclasses
      _superclasses
   );

    {
     // for method getCosNamingInfo

       iluException* getCosNamingInfo_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "getCosNamingInfo"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getCosNamingInfo_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:kwkwgbvpv+vadYmnz8w1UE-BJ6B") // return type ID
        );
    }  //end for method getCosNamingInfo

    {
     // for method sendMsg

       iluException* sendMsg_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "sendMsg"), // name
                     2,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendMsg_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "m"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/Message:1.0"));
    }  //end for method sendMsg

    {
     // for method bind

       iluException bind_exception_array[1];
       bind_exception_array[0] =
            interface_exceptions[g_SRIO_Console_Console_AlreadyBind_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     2,      // method index
                     CONST_CAST(iluCString, "bind"), // name
                     3,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     bind_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "sbh"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method bind

    {
     // for method unbind

       iluException unbind_exception_array[1];
       unbind_exception_array[0] =
            interface_exceptions[g_SRIO_Console_Console_NotFound_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     3,      // method index
                     CONST_CAST(iluCString, "unbind"), // name
                     4,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     unbind_exception_array,
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
    }  //end for method unbind

    {
     // for method rebind

       iluException rebind_exception_array[1];
       rebind_exception_array[0] =
            interface_exceptions[g_SRIO_Console_Console_NotFound_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     4,      // method index
                     CONST_CAST(iluCString, "rebind"), // name
                     5,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     rebind_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uid"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "sbh"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method rebind

    {
     // for method setNickname

       iluException* setNickname_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     5,      // method index
                     CONST_CAST(iluCString, "setNickname"), // name
                     6,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setNickname_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "newName"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method setNickname

    {
     // for method setPosition

       iluException* setPosition_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     6,      // method index
                     CONST_CAST(iluCString, "setPosition"), // name
                     7,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setPosition_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "name"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "p"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/Point:1.0"));
    }  //end for method setPosition

    {
     // for method addGoalPoint

       iluException* addGoalPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     7,      // method index
                     CONST_CAST(iluCString, "addGoalPoint"), // name
                     8,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     addGoalPoint_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "p"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/Point:1.0"));
    }  //end for method addGoalPoint

    {
     // for method setGoalPoint

       iluException* setGoalPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     8,      // method index
                     CONST_CAST(iluCString, "setGoalPoint"), // name
                     9,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setGoalPoint_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "p"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/Point:1.0"));
    }  //end for method setGoalPoint

    {
     // for method setRole

       iluException* setRole_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     9,      // method index
                     CONST_CAST(iluCString, "setRole"), // name
                     10,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setRole_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "r"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/Role:1.0"));
    }  //end for method setRole

    {
     // for method cancelRole

       iluException* cancelRole_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     10,      // method index
                     CONST_CAST(iluCString, "cancelRole"), // name
                     11,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     cancelRole_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method cancelRole

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
             CONST_CAST(iluCString, "p"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/TrapPoint:1.0"));
    }  //end for method setTrapPoint

    {
     // for method setFollow

       iluException* setFollow_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     12,      // method index
                     CONST_CAST(iluCString, "setFollow"), // name
                     13,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setFollow_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo1"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "uinfo2"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method setFollow

    {
     // for method setFormationType

       iluException* setFormationType_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     13,      // method index
                     CONST_CAST(iluCString, "setFormationType"), // name
                     14,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setFormationType_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "f"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/FormationType:1.0"));
    }  //end for method setFormationType

    {
     // for method setTrackMode

       iluException* setTrackMode_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     14,      // method index
                     CONST_CAST(iluCString, "setTrackMode"), // name
                     15,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setTrackMode_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "tm"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/TrackMode:1.0"));
    }  //end for method setTrackMode

    {
     // for method getCurrentUnit

       iluException* getCurrentUnit_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     15,      // method index
                     CONST_CAST(iluCString, "getCurrentUnit"), // name
                     16,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getCurrentUnit_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Unit/General_Unit/UnitInfo:1.0") // return type ID
        );
    }  //end for method getCurrentUnit

    {
     // for method getUnitNum

       iluException* getUnitNum_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     16,      // method index
                     CONST_CAST(iluCString, "getUnitNum"), // name
                     17,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getUnitNum_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // return type ID
        );
    }  //end for method getUnitNum

    {
     // for method getFormationNum

       iluException* getFormationNum_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     17,      // method index
                     CONST_CAST(iluCString, "getFormationNum"), // name
                     18,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getFormationNum_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // return type ID
        );
    }  //end for method getFormationNum

    {
     // for method getTrapNum

       iluException* getTrapNum_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     18,      // method index
                     CONST_CAST(iluCString, "getTrapNum"), // name
                     19,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getTrapNum_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // return type ID
        );
    }  //end for method getTrapNum

    {
     // for method getFormationType

       iluException* getFormationType_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     19,      // method index
                     CONST_CAST(iluCString, "getFormationType"), // name
                     20,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getFormationType_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Console/Console/FormationType:1.0") // return type ID
        );
    }  //end for method getFormationType

    {
     // for method getFormationState

       iluException* getFormationState_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     20,      // method index
                     CONST_CAST(iluCString, "getFormationState"), // name
                     21,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getFormationState_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Console/Console/FormationState:1.0") // return type ID
        );
    }  //end for method getFormationState

    {
     // for method getMissionState

       iluException* getMissionState_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     21,      // method index
                     CONST_CAST(iluCString, "getMissionState"), // name
                     22,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getMissionState_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Console/Console/MissionState:1.0") // return type ID
        );
    }  //end for method getMissionState

    {
     // for method getUnitPoint

       iluException* getUnitPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     22,      // method index
                     CONST_CAST(iluCString, "getUnitPoint"), // name
                     23,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getUnitPoint_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Console/Console/Point:1.0") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "name"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method getUnitPoint

    {
     // for method getByName

       iluException* getByName_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     23,      // method index
                     CONST_CAST(iluCString, "getByName"), // name
                     24,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getByName_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Unit/General_Unit/UnitInfo:1.0") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "name"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
    }  //end for method getByName

    {
     // for method getLeaderPoint

       iluException* getLeaderPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     24,      // method index
                     CONST_CAST(iluCString, "getLeaderPoint"), // name
                     25,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getLeaderPoint_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"IDL:SRIO_Console/Console/Point:1.0") // return type ID
        );
    }  //end for method getLeaderPoint

    {
     // for method getPointSeq

       iluException* getPointSeq_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     25,      // method index
                     CONST_CAST(iluCString, "getPointSeq"), // name
                     26,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getPointSeq_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:bbdqUgLV+vqK3pHn-j0IdQmOsTn") // return type ID
        );
    }  //end for method getPointSeq

    {
     // for method cancelFormation

       iluException* cancelFormation_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     26,      // method index
                     CONST_CAST(iluCString, "cancelFormation"), // name
                     27,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     cancelFormation_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method cancelFormation

    {
     // for method setLeaderSuspend

       iluException* setLeaderSuspend_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     27,      // method index
                     CONST_CAST(iluCString, "setLeaderSuspend"), // name
                     28,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setLeaderSuspend_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method setLeaderSuspend

    {
     // for method recoveryLeaderAction

       iluException* recoveryLeaderAction_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     28,      // method index
                     CONST_CAST(iluCString, "recoveryLeaderAction"), // name
                     29,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     recoveryLeaderAction_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method recoveryLeaderAction

    {
     // for method addUnitFormation

       iluException* addUnitFormation_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     29,      // method index
                     CONST_CAST(iluCString, "addUnitFormation"), // name
                     30,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     addUnitFormation_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method addUnitFormation

    {
     // for method deleteUnitFormation

       iluException* deleteUnitFormation_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     30,      // method index
                     CONST_CAST(iluCString, "deleteUnitFormation"), // name
                     31,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     deleteUnitFormation_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method deleteUnitFormation

    {
     // for method setUnitFault

       iluException* setUnitFault_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     31,      // method index
                     CONST_CAST(iluCString, "setUnitFault"), // name
                     32,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setUnitFault_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method setUnitFault

    {
     // for method setUnitFaultPosition

       iluException* setUnitFaultPosition_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     32,      // method index
                     CONST_CAST(iluCString, "setUnitFaultPosition"), // name
                     33,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setUnitFaultPosition_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uinfo"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0"));
    }  //end for method setUnitFaultPosition

    {
     // for method setFormationState

       iluException* setFormationState_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     33,      // method index
                     CONST_CAST(iluCString, "setFormationState"), // name
                     34,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setFormationState_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "fs"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/FormationState:1.0"));
    }  //end for method setFormationState

    {
     // for method setMissionState

       iluException* setMissionState_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     34,      // method index
                     CONST_CAST(iluCString, "setMissionState"), // name
                     35,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setMissionState_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "msd"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Console/Console/MissionStateData:1.0"));
    }  //end for method setMissionState

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  SRIO_Console::Console typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console)::iluDeleteValue (void* pv_value) {
                SRIO_Console::Console_ptr p_thevalue = (SRIO_Console::Console_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console)::iluDeepCopy (void* pv_value) {
                SRIO_Console::Console_ptr p_thevalue = (SRIO_Console::Console_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_(Boolean) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               SRIO_Console::Console_ptr p_thevalue = (SRIO_Console::Console_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, SRIO_Console::Console::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           SRIO_Console::Console_ptr p_object = (SRIO_Console::Console_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If SRIO_Console::Console were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA::Object::iluGetILUClassRecord())
           //    return ((CORBA::Object_ptr)p_object);
           if (casttoclass == SRIO_Console::Console::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


//      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
//           SRIO_Console::Console_ptr p_object = (SRIO_Console::Console_ptr) p_an_object_of_your_type;
//           return CORBA::TypeCode::LookupTypeCode(p_object->iluClassId());
//      }


      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console)::iluMostSpecificTypeCode(void* p_an_object_of_your_type) {
          if (!p_an_object_of_your_type) return nullptr;
          SRIO_Console::Console_ptr p_object = static_cast<SRIO_Console::Console_ptr>(p_an_object_of_your_type);
          return CORBA_(TypeCode)::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for SRIO_Console::Console
        const CORBA_(TypeCode_ptr) SRIO_Console::tc_Console = new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Console_Console);

      // define the Any insertion and extraction operators for SRIO_Console::Console

      void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(SRIO_Console::tc_Console, p_object, ILUCPP_TRUE);
      }

      CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Console::Console_ptr& r_p_object) {

          CORBA_(Any)* p_nc_any = CONST_CAST(CORBA_(Any)*, &r_any);

          if (p_nc_any->iluGetFromPickle(SRIO_Console::tc_Console)) { 
                 r_p_object = (SRIO_Console::Console_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


/////////////////////////////////////////////////////////////////
// Exception implementations for locally-defined
// exceptions of interface SRIO_Console 

/////////////////////////////////////////////////
// AlreadyBind functions

  //constructor
  SRIO_Console::Console::AlreadyBind::AlreadyBind(const SRIO_Console::Console::AlreadyBind& a_AlreadyBind) { }

  //destructor
  SRIO_Console::Console::AlreadyBind::~AlreadyBind() { }

  // assignment operator
  SRIO_Console::Console::AlreadyBind& SRIO_Console::Console::AlreadyBind::operator=(const SRIO_Console::Console::AlreadyBind& a_AlreadyBind) {
  return *this;
  }

/////////////////////////////////////////////////
// NotFound functions

  //constructor
  SRIO_Console::Console::NotFound::NotFound(const SRIO_Console::Console::NotFound& a_NotFound) { }

  //destructor
  SRIO_Console::Console::NotFound::~NotFound() { }

  // assignment operator
  SRIO_Console::Console::NotFound& SRIO_Console::Console::NotFound::operator=(const SRIO_Console::Console::NotFound& a_NotFound) {
  return *this;
  }


////////////////////////////////////////////////////////////////
// Force initialization of SRIO_Console:: classes upon load

SRIO_Console::initializer SRIO_Console::initializer::sm_the_SRIO_Console_initializer;

SRIO_Console::initializer:: initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * SRIO_Console::initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(SRIO_Console::iluInitialize);
  return this;
}
