
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#include "SRIO-Air-Unit-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members


  // list of initialization functions to call for the SRIO_Air_Unit:: interface
  iluInitializationFunctionNode* SRIO_Air_Unit::p_initialization_function_list;
  int SRIO_Air_Unit::g_i_initialized;

  // holds the ilu class record for SRIO_Air_Unit::Air_Unit objects
  iluClass SRIO_Air_Unit::Air_Unit::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// SRIO_Air_Unit initialization

  void SRIO_Air_Unit::iluInitialize () {

      if ( g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // performs object type initialization
        SRIO_Air_Unit::Air_Unit::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Air-Unit-Site"),
             CONST_CAST( iluCString, "SRIO-Air-Unit"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Site:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/SiteType:1.0"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "rd"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/RectangleData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "Rectangle");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "cd"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/CircleData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "Circle");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "Air-Unit-MoveAction"),
             CONST_CAST( iluCString, "SRIO-Air-Unit"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/MoveAction:1.0"),
             CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/MoveActionType:1.0"),  // UID of discriminant type
              9,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "goUpData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_GoUp");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "goDownData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_GoDown");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  2,   // which arm
                  CONST_CAST( iluCString, "goAheadData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
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
                  3,   // which arm
                  CONST_CAST( iluCString, "goBackwardData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
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
                  4,   // which arm
                  CONST_CAST( iluCString, "goLeftData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_GoLeft");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  5,   // which arm
                  CONST_CAST( iluCString, "goRightData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "MA_GoRight");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  6,   // which arm
                  CONST_CAST( iluCString, "turnLeftData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
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
                  7,   // which arm
                  CONST_CAST( iluCString, "turnRightData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"), // arm type
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
                  8,   // which arm
                  CONST_CAST( iluCString, "stopData"),   // name of arm
                  CONST_CAST( iluCString,  "IDL:SRIO_Air_Unit/Air_Unit/ActionDuration:1.0"), // arm type
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
            CONST_CAST( iluCString, "Air-Unit-CircleData"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/CircleData:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "po"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Point3D:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "r"),     // field name
                CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-RectangleData"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/RectangleData:1.0"),
            3, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "po"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Point3D:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "x"),     // field name
                CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "y"),     // field name
                CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-Formation"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Formation:1.0"),
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
            CONST_CAST( iluCString, "Air-Unit-TrapPoint3D"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/TrapPoint3D:1.0"),
            2, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "point"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Point3D:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "radius"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-Point3D"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Point3D:1.0"),
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
                CONST_CAST( iluCString, "z"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-AirUnitInfo"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/AirUnitInfo:1.0"),
            6, // number of fields in the record
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
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Speed3D:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                3,     // which field
                CONST_CAST( iluCString, "angularVelocity"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/FusionAngularVelocity:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                4,     // which field
                CONST_CAST( iluCString, "gps"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/GPSInfo:1.0") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                5,     // which field
                CONST_CAST( iluCString, "gs"),     // field name
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/GimbalState:1.0") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-FusionAngularVelocity"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/FusionAngularVelocity:1.0"),
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
                CONST_CAST( iluCString, "z"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-Speed3D"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Speed3D:1.0"),
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
                CONST_CAST( iluCString, "z"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-GPSInfo"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/GPSInfo:1.0"),
            6, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "longitude"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "latitude"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "altitude"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                3,     // which field
                CONST_CAST( iluCString, "height"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                4,     // which field
                CONST_CAST( iluCString, "time"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                5,     // which field
                CONST_CAST( iluCString, "health"),     // field name
                CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-Pose3D"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Pose3D:1.0"),
            6, // number of fields in the record
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
                CONST_CAST( iluCString, "z"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                3,     // which field
                CONST_CAST( iluCString, "pitch"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                4,     // which field
                CONST_CAST( iluCString, "yaw"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                5,     // which field
                CONST_CAST( iluCString, "roll"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-GimbalState"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/GimbalState:1.0"),
            3, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "yaw"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "roll"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "pitch"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-GimbalSpeed"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/GimbalSpeed:1.0"),
            3, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "yaw"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "roll"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "pitch"),     // field name
                CONST_CAST( iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-BasicMoveActionData"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0"),
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
                CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/ActionDuration:1.0") // UID of field type
            );
        }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "Air-Unit-ActionDuration"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/ActionDuration:1.0"),
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
            CONST_CAST( iluCString, "Air-Unit"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit:1.0"),
            SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord(), // object class
            &b_new_registration);

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Air-Unit-SiteType"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/SiteType:1.0"),
            2,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "Rectangle"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "Circle"),  // element name
              1       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Air-Unit-ActionMode"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/ActionMode:1.0"),
            5,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "None"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "Cruise"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "Locate"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "Assist"),  // element name
              3       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              4,        // which element
              CONST_CAST( iluCString, "Feedback"),  // element name
              4       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Air-Unit-ActionRole"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/ActionRole:1.0"),
            3,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "Actor"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "Standby"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "Facilitators"),  // element name
              2       // integer value for element
        );
     }

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "Air-Unit-MoveActionType"),
            CONST_CAST( iluCString, "SRIO-Air-Unit"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit/MoveActionType:1.0"),
            15,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "MA-GoUp"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "MA-GoDown"),  // element name
              1       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "MA-GoAhead"),  // element name
              2       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "MA-GoBackward"),  // element name
              3       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              4,        // which element
              CONST_CAST( iluCString, "MA-GoLeft"),  // element name
              4       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              5,        // which element
              CONST_CAST( iluCString, "MA-GoRight"),  // element name
              5       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              6,        // which element
              CONST_CAST( iluCString, "MA-TurnLeft"),  // element name
              6       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              7,        // which element
              CONST_CAST( iluCString, "MA-TurnRight"),  // element name
              7       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              8,        // which element
              CONST_CAST( iluCString, "MA-Stop"),  // element name
              8       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              9,        // which element
              CONST_CAST( iluCString, "MA-TakeOff"),  // element name
              9       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              10,        // which element
              CONST_CAST( iluCString, "MA-Land"),  // element name
              10       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              11,        // which element
              CONST_CAST( iluCString, "MA-LandConfirm"),  // element name
              11       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              12,        // which element
              CONST_CAST( iluCString, "MA-ForceLanding"),  // element name
              12       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              13,        // which element
              CONST_CAST( iluCString, "MA-Lock"),  // element name
              13       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              14,        // which element
              CONST_CAST( iluCString, "MA-Unlock"),  // element name
              14       // integer value for element
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
//  SRIO_Air_Unit::Air_Unit_var sizing, input and output operators

// note following three operators only needed
// if SRIO_Air_Unit::Air_Unit is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const SRIO_Air_Unit::Air_Unit_var& r_SRIO_Air_Unit_Air_Unit_var) {
         r_call += r_SRIO_Air_Unit_Air_Unit_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const SRIO_Air_Unit::Air_Unit_var& r_SRIO_Air_Unit_Air_Unit_var) {

      if (r_SRIO_Air_Unit_Air_Unit_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_SRIO_Air_Unit_Air_Unit_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_SRIO_Air_Unit_Air_Unit_var.iluSetWrapper(
           new iluObjectWrapper(
               r_SRIO_Air_Unit_Air_Unit_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_SRIO_Air_Unit_Air_Unit_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_SRIO_Air_Unit_Air_Unit_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Air_Unit::Air_Unit_var& r_SRIO_Air_Unit_Air_Unit_var) {
	  
      SRIO_Air_Unit::Air_Unit_var temp_SRIO_Air_Unit_Air_Unit_var;
	  
     if (r_SRIO_Air_Unit_Air_Unit_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_SRIO_Air_Unit_Air_Unit_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_SRIO_Air_Unit_Air_Unit_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_SRIO_Air_Unit_Air_Unit_var = r_SRIO_Air_Unit_Air_Unit_var;

         // force a release since the var's in control of the refcount
         r_SRIO_Air_Unit_Air_Unit_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_SRIO_Air_Unit_Air_Unit_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_SRIO_Air_Unit_Air_Unit_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_SRIO_Air_Unit_Air_Unit_var = (SRIO_Air_Unit::Air_Unit_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }


  // define the member functions in typecode class for SRIO_Air_Unit::Air_Unit::SiteType
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Air_Unit_Air_Unit_SiteType, SRIO_Air_Unit::Air_Unit::SiteType)

  // typecode instance for SRIO_Air_Unit_Air_Unit_SiteType
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_SiteType =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_SiteType);

  // define the Any insertion and extraction operators for SRIO_Air_Unit::Air_Unit::SiteType
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::SiteType, SRIO_Air_Unit::Air_Unit::tc_SiteType)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::SiteType, SRIO_Air_Unit::Air_Unit::tc_SiteType)

  // define the member functions in typecode class for SRIO_Air_Unit::Air_Unit::ActionMode
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Air_Unit_Air_Unit_ActionMode, SRIO_Air_Unit::Air_Unit::ActionMode)

  // typecode instance for SRIO_Air_Unit_Air_Unit_ActionMode
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_ActionMode =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_ActionMode);

  // define the Any insertion and extraction operators for SRIO_Air_Unit::Air_Unit::ActionMode
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::ActionMode, SRIO_Air_Unit::Air_Unit::tc_ActionMode)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::ActionMode, SRIO_Air_Unit::Air_Unit::tc_ActionMode)

  // define the member functions in typecode class for SRIO_Air_Unit::Air_Unit::ActionRole
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Air_Unit_Air_Unit_ActionRole, SRIO_Air_Unit::Air_Unit::ActionRole)

  // typecode instance for SRIO_Air_Unit_Air_Unit_ActionRole
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_ActionRole =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_ActionRole);

  // define the Any insertion and extraction operators for SRIO_Air_Unit::Air_Unit::ActionRole
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::ActionRole, SRIO_Air_Unit::Air_Unit::tc_ActionRole)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::ActionRole, SRIO_Air_Unit::Air_Unit::tc_ActionRole)

  // define the member functions in typecode class for SRIO_Air_Unit::Air_Unit::MoveActionType
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            SRIO_Air_Unit_Air_Unit_MoveActionType, SRIO_Air_Unit::Air_Unit::MoveActionType)

  // typecode instance for SRIO_Air_Unit_Air_Unit_MoveActionType
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_MoveActionType =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_MoveActionType);

  // define the Any insertion and extraction operators for SRIO_Air_Unit::Air_Unit::MoveActionType
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::MoveActionType, SRIO_Air_Unit::Air_Unit::tc_MoveActionType)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           SRIO_Air_Unit::Air_Unit::MoveActionType, SRIO_Air_Unit::Air_Unit::tc_MoveActionType)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::CircleData members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::CircleData::CircleData() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::CircleData::CircleData(const SRIO_Air_Unit::Air_Unit::CircleData& r_a_CircleData) {
          po = r_a_CircleData.po;
          r = r_a_CircleData.r;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::CircleData::~CircleData() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::CircleData& SRIO_Air_Unit::Air_Unit::CircleData::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::CircleData& SRIO_Air_Unit::Air_Unit::CircleData::operator=(
       const SRIO_Air_Unit::Air_Unit::CircleData& r_a_CircleData) {
          if (this != &r_a_CircleData) {
          po = r_a_CircleData.po;
          r = r_a_CircleData.r;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::CircleData

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::CircleData& r_SRIO_Air_Unit_Air_Unit_CircleData)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Air_Unit_Air_Unit_CircleData.po;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_CircleData.r;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::CircleData& r_SRIO_Air_Unit_Air_Unit_CircleData)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Air_Unit_Air_Unit_CircleData.po;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_CircleData.r;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::CircleData& r_SRIO_Air_Unit_Air_Unit_CircleData)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Air_Unit_Air_Unit_CircleData.po;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_CircleData.r;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::CircleData
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_CircleData, SRIO_Air_Unit::Air_Unit::CircleData)

  // typecode instance for SRIO_Air_Unit_Air_Unit_CircleData
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_CircleData =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_CircleData);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::CircleData 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::CircleData, SRIO_Air_Unit::Air_Unit::tc_CircleData)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::CircleData, SRIO_Air_Unit::Air_Unit::tc_CircleData)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::CircleData, SRIO_Air_Unit::Air_Unit::tc_CircleData)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::RectangleData members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::RectangleData::RectangleData() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::RectangleData::RectangleData(const SRIO_Air_Unit::Air_Unit::RectangleData& r_a_RectangleData) {
          po = r_a_RectangleData.po;
          x = r_a_RectangleData.x;
          y = r_a_RectangleData.y;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::RectangleData::~RectangleData() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::RectangleData& SRIO_Air_Unit::Air_Unit::RectangleData::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::RectangleData& SRIO_Air_Unit::Air_Unit::RectangleData::operator=(
       const SRIO_Air_Unit::Air_Unit::RectangleData& r_a_RectangleData) {
          if (this != &r_a_RectangleData) {
          po = r_a_RectangleData.po;
          x = r_a_RectangleData.x;
          y = r_a_RectangleData.y;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::RectangleData

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::RectangleData& r_SRIO_Air_Unit_Air_Unit_RectangleData)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Air_Unit_Air_Unit_RectangleData.po;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_RectangleData.x;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_RectangleData.y;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::RectangleData& r_SRIO_Air_Unit_Air_Unit_RectangleData)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Air_Unit_Air_Unit_RectangleData.po;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_RectangleData.x;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_RectangleData.y;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::RectangleData& r_SRIO_Air_Unit_Air_Unit_RectangleData)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Air_Unit_Air_Unit_RectangleData.po;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_RectangleData.x;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_RectangleData.y;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::RectangleData
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_RectangleData, SRIO_Air_Unit::Air_Unit::RectangleData)

  // typecode instance for SRIO_Air_Unit_Air_Unit_RectangleData
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_RectangleData =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_RectangleData);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::RectangleData 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::RectangleData, SRIO_Air_Unit::Air_Unit::tc_RectangleData)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::RectangleData, SRIO_Air_Unit::Air_Unit::tc_RectangleData)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::RectangleData, SRIO_Air_Unit::Air_Unit::tc_RectangleData)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::Formation members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::Formation::Formation() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::Formation::Formation(const SRIO_Air_Unit::Air_Unit::Formation& r_a_Formation) {
          robot_ids = r_a_Formation.robot_ids;
          leader_ids = r_a_Formation.leader_ids;
          distances = r_a_Formation.distances;
          angles = r_a_Formation.angles;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::Formation::~Formation() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::Formation& SRIO_Air_Unit::Air_Unit::Formation::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::Formation& SRIO_Air_Unit::Air_Unit::Formation::operator=(
       const SRIO_Air_Unit::Air_Unit::Formation& r_a_Formation) {
          if (this != &r_a_Formation) {
          robot_ids = r_a_Formation.robot_ids;
          leader_ids = r_a_Formation.leader_ids;
          distances = r_a_Formation.distances;
          angles = r_a_Formation.angles;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Formation

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Formation& r_SRIO_Air_Unit_Air_Unit_Formation)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Air_Unit_Air_Unit_Formation.robot_ids;
          r_call += r_SRIO_Air_Unit_Air_Unit_Formation.leader_ids;
          r_call += r_SRIO_Air_Unit_Air_Unit_Formation.distances;
          r_call += r_SRIO_Air_Unit_Air_Unit_Formation.angles;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Formation& r_SRIO_Air_Unit_Air_Unit_Formation)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Air_Unit_Air_Unit_Formation.robot_ids;
          r_call << r_SRIO_Air_Unit_Air_Unit_Formation.leader_ids;
          r_call << r_SRIO_Air_Unit_Air_Unit_Formation.distances;
          r_call << r_SRIO_Air_Unit_Air_Unit_Formation.angles;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::Formation& r_SRIO_Air_Unit_Air_Unit_Formation)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Air_Unit_Air_Unit_Formation.robot_ids;
          r_call >> r_SRIO_Air_Unit_Air_Unit_Formation.leader_ids;
          r_call >> r_SRIO_Air_Unit_Air_Unit_Formation.distances;
          r_call >> r_SRIO_Air_Unit_Air_Unit_Formation.angles;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::Formation
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_Formation, SRIO_Air_Unit::Air_Unit::Formation)

  // typecode instance for SRIO_Air_Unit_Air_Unit_Formation
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_Formation =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_Formation);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Formation 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Formation, SRIO_Air_Unit::Air_Unit::tc_Formation)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Formation, SRIO_Air_Unit::Air_Unit::tc_Formation)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Formation, SRIO_Air_Unit::Air_Unit::tc_Formation)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::TrapPoint3D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::TrapPoint3D::TrapPoint3D() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::TrapPoint3D::TrapPoint3D(const SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_a_TrapPoint3D) {
          point = r_a_TrapPoint3D.point;
          radius = r_a_TrapPoint3D.radius;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::TrapPoint3D::~TrapPoint3D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::TrapPoint3D& SRIO_Air_Unit::Air_Unit::TrapPoint3D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::TrapPoint3D& SRIO_Air_Unit::Air_Unit::TrapPoint3D::operator=(
       const SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_a_TrapPoint3D) {
          if (this != &r_a_TrapPoint3D) {
          point = r_a_TrapPoint3D.point;
          radius = r_a_TrapPoint3D.radius;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::TrapPoint3D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_SRIO_Air_Unit_Air_Unit_TrapPoint3D)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Air_Unit_Air_Unit_TrapPoint3D.point;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_TrapPoint3D.radius;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_SRIO_Air_Unit_Air_Unit_TrapPoint3D)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Air_Unit_Air_Unit_TrapPoint3D.point;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_TrapPoint3D.radius;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_SRIO_Air_Unit_Air_Unit_TrapPoint3D)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Air_Unit_Air_Unit_TrapPoint3D.point;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_TrapPoint3D.radius;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::TrapPoint3D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_TrapPoint3D, SRIO_Air_Unit::Air_Unit::TrapPoint3D)

  // typecode instance for SRIO_Air_Unit_Air_Unit_TrapPoint3D
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_TrapPoint3D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_TrapPoint3D);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::TrapPoint3D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TrapPoint3D, SRIO_Air_Unit::Air_Unit::tc_TrapPoint3D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TrapPoint3D, SRIO_Air_Unit::Air_Unit::tc_TrapPoint3D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TrapPoint3D, SRIO_Air_Unit::Air_Unit::tc_TrapPoint3D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::Point3D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::Point3D::Point3D() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::Point3D::Point3D(const SRIO_Air_Unit::Air_Unit::Point3D& r_a_Point3D) {
          x = r_a_Point3D.x;
          y = r_a_Point3D.y;
          z = r_a_Point3D.z;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::Point3D::~Point3D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::Point3D& SRIO_Air_Unit::Air_Unit::Point3D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::Point3D& SRIO_Air_Unit::Air_Unit::Point3D::operator=(
       const SRIO_Air_Unit::Air_Unit::Point3D& r_a_Point3D) {
          if (this != &r_a_Point3D) {
          x = r_a_Point3D.x;
          y = r_a_Point3D.y;
          z = r_a_Point3D.z;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Point3D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Point3D& r_SRIO_Air_Unit_Air_Unit_Point3D)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Point3D.x;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Point3D.y;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Point3D.z;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Point3D& r_SRIO_Air_Unit_Air_Unit_Point3D)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Point3D.x;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Point3D.y;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Point3D.z;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::Point3D& r_SRIO_Air_Unit_Air_Unit_Point3D)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Point3D.x;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Point3D.y;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Point3D.z;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::Point3D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_Point3D, SRIO_Air_Unit::Air_Unit::Point3D)

  // typecode instance for SRIO_Air_Unit_Air_Unit_Point3D
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_Point3D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_Point3D);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Point3D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Point3D, SRIO_Air_Unit::Air_Unit::tc_Point3D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Point3D, SRIO_Air_Unit::Air_Unit::tc_Point3D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Point3D, SRIO_Air_Unit::Air_Unit::tc_Point3D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::AirUnitInfo members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::AirUnitInfo::AirUnitInfo() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::AirUnitInfo::AirUnitInfo(const SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_a_AirUnitInfo) {
          info = r_a_AirUnitInfo.info;
          role = r_a_AirUnitInfo.role;
          speed = r_a_AirUnitInfo.speed;
          angularVelocity = r_a_AirUnitInfo.angularVelocity;
          gps = r_a_AirUnitInfo.gps;
          gs = r_a_AirUnitInfo.gs;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::AirUnitInfo::~AirUnitInfo() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::AirUnitInfo& SRIO_Air_Unit::Air_Unit::AirUnitInfo::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::AirUnitInfo& SRIO_Air_Unit::Air_Unit::AirUnitInfo::operator=(
       const SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_a_AirUnitInfo) {
          if (this != &r_a_AirUnitInfo) {
          info = r_a_AirUnitInfo.info;
          role = r_a_AirUnitInfo.role;
          speed = r_a_AirUnitInfo.speed;
          angularVelocity = r_a_AirUnitInfo.angularVelocity;
          gps = r_a_AirUnitInfo.gps;
          gs = r_a_AirUnitInfo.gs;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::AirUnitInfo

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_SRIO_Air_Unit_Air_Unit_AirUnitInfo)  {

         r_call += iluSizeRecord;
          r_call += r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.info;
         iluEnumWrapper _r_role_wrap(
              (iluDummyEnum &) r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.role);
         r_call += _r_role_wrap;
          r_call += r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.speed;
          r_call += r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.angularVelocity;
          r_call += r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.gps;
          r_call += r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.gs;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_SRIO_Air_Unit_Air_Unit_AirUnitInfo)  {

         r_call << iluOutputRecord;
          r_call << r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.info;
         iluEnumWrapper _r_role_wrap(
              (iluDummyEnum &) r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.role);
         r_call << _r_role_wrap;
          r_call << r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.speed;
          r_call << r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.angularVelocity;
          r_call << r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.gps;
          r_call << r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.gs;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_SRIO_Air_Unit_Air_Unit_AirUnitInfo)  {

         r_call >> iluInputRecord;
          r_call >> r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.info;
         iluEnumWrapper _r_role_wrap(
              (iluDummyEnum &) r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.role);
         r_call >> _r_role_wrap;
          r_call >> r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.speed;
          r_call >> r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.angularVelocity;
          r_call >> r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.gps;
          r_call >> r_SRIO_Air_Unit_Air_Unit_AirUnitInfo.gs;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::AirUnitInfo
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_AirUnitInfo, SRIO_Air_Unit::Air_Unit::AirUnitInfo)

  // typecode instance for SRIO_Air_Unit_Air_Unit_AirUnitInfo
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_AirUnitInfo =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_AirUnitInfo);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::AirUnitInfo 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::AirUnitInfo, SRIO_Air_Unit::Air_Unit::tc_AirUnitInfo)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::AirUnitInfo, SRIO_Air_Unit::Air_Unit::tc_AirUnitInfo)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::AirUnitInfo, SRIO_Air_Unit::Air_Unit::tc_AirUnitInfo)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::FusionAngularVelocity members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::FusionAngularVelocity::FusionAngularVelocity() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::FusionAngularVelocity::FusionAngularVelocity(const SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_a_FusionAngularVelocity) {
          x = r_a_FusionAngularVelocity.x;
          y = r_a_FusionAngularVelocity.y;
          z = r_a_FusionAngularVelocity.z;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::FusionAngularVelocity::~FusionAngularVelocity() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& SRIO_Air_Unit::Air_Unit::FusionAngularVelocity::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& SRIO_Air_Unit::Air_Unit::FusionAngularVelocity::operator=(
       const SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_a_FusionAngularVelocity) {
          if (this != &r_a_FusionAngularVelocity) {
          x = r_a_FusionAngularVelocity.x;
          y = r_a_FusionAngularVelocity.y;
          z = r_a_FusionAngularVelocity.z;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::FusionAngularVelocity

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.x;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.y;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.z;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.x;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.y;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.z;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.x;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.y;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity.z;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::FusionAngularVelocity
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_FusionAngularVelocity, SRIO_Air_Unit::Air_Unit::FusionAngularVelocity)

  // typecode instance for SRIO_Air_Unit_Air_Unit_FusionAngularVelocity
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_FusionAngularVelocity =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_FusionAngularVelocity);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::FusionAngularVelocity 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::FusionAngularVelocity, SRIO_Air_Unit::Air_Unit::tc_FusionAngularVelocity)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::FusionAngularVelocity, SRIO_Air_Unit::Air_Unit::tc_FusionAngularVelocity)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::FusionAngularVelocity, SRIO_Air_Unit::Air_Unit::tc_FusionAngularVelocity)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::Speed3D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::Speed3D::Speed3D() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::Speed3D::Speed3D(const SRIO_Air_Unit::Air_Unit::Speed3D& r_a_Speed3D) {
          x = r_a_Speed3D.x;
          y = r_a_Speed3D.y;
          z = r_a_Speed3D.z;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::Speed3D::~Speed3D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::Speed3D& SRIO_Air_Unit::Air_Unit::Speed3D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::Speed3D& SRIO_Air_Unit::Air_Unit::Speed3D::operator=(
       const SRIO_Air_Unit::Air_Unit::Speed3D& r_a_Speed3D) {
          if (this != &r_a_Speed3D) {
          x = r_a_Speed3D.x;
          y = r_a_Speed3D.y;
          z = r_a_Speed3D.z;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Speed3D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Speed3D& r_SRIO_Air_Unit_Air_Unit_Speed3D)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Speed3D.x;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Speed3D.y;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Speed3D.z;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Speed3D& r_SRIO_Air_Unit_Air_Unit_Speed3D)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Speed3D.x;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Speed3D.y;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Speed3D.z;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::Speed3D& r_SRIO_Air_Unit_Air_Unit_Speed3D)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Speed3D.x;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Speed3D.y;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Speed3D.z;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::Speed3D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_Speed3D, SRIO_Air_Unit::Air_Unit::Speed3D)

  // typecode instance for SRIO_Air_Unit_Air_Unit_Speed3D
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_Speed3D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_Speed3D);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Speed3D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Speed3D, SRIO_Air_Unit::Air_Unit::tc_Speed3D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Speed3D, SRIO_Air_Unit::Air_Unit::tc_Speed3D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Speed3D, SRIO_Air_Unit::Air_Unit::tc_Speed3D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::GPSInfo members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::GPSInfo::GPSInfo() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::GPSInfo::GPSInfo(const SRIO_Air_Unit::Air_Unit::GPSInfo& r_a_GPSInfo) {
          longitude = r_a_GPSInfo.longitude;
          latitude = r_a_GPSInfo.latitude;
          altitude = r_a_GPSInfo.altitude;
          height = r_a_GPSInfo.height;
          time = r_a_GPSInfo.time;
          health = r_a_GPSInfo.health;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::GPSInfo::~GPSInfo() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::GPSInfo& SRIO_Air_Unit::Air_Unit::GPSInfo::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::GPSInfo& SRIO_Air_Unit::Air_Unit::GPSInfo::operator=(
       const SRIO_Air_Unit::Air_Unit::GPSInfo& r_a_GPSInfo) {
          if (this != &r_a_GPSInfo) {
          longitude = r_a_GPSInfo.longitude;
          latitude = r_a_GPSInfo.latitude;
          altitude = r_a_GPSInfo.altitude;
          height = r_a_GPSInfo.height;
          time = r_a_GPSInfo.time;
          health = r_a_GPSInfo.health;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::GPSInfo

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::GPSInfo& r_SRIO_Air_Unit_Air_Unit_GPSInfo)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GPSInfo.longitude;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GPSInfo.latitude;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GPSInfo.altitude;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GPSInfo.height;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GPSInfo.time;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GPSInfo.health;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::GPSInfo& r_SRIO_Air_Unit_Air_Unit_GPSInfo)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GPSInfo.longitude;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GPSInfo.latitude;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GPSInfo.altitude;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GPSInfo.height;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GPSInfo.time;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GPSInfo.health;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::GPSInfo& r_SRIO_Air_Unit_Air_Unit_GPSInfo)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GPSInfo.longitude;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GPSInfo.latitude;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GPSInfo.altitude;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GPSInfo.height;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GPSInfo.time;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GPSInfo.health;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::GPSInfo
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_GPSInfo, SRIO_Air_Unit::Air_Unit::GPSInfo)

  // typecode instance for SRIO_Air_Unit_Air_Unit_GPSInfo
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_GPSInfo =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_GPSInfo);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::GPSInfo 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GPSInfo, SRIO_Air_Unit::Air_Unit::tc_GPSInfo)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GPSInfo, SRIO_Air_Unit::Air_Unit::tc_GPSInfo)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GPSInfo, SRIO_Air_Unit::Air_Unit::tc_GPSInfo)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::Pose3D members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::Pose3D::Pose3D() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::Pose3D::Pose3D(const SRIO_Air_Unit::Air_Unit::Pose3D& r_a_Pose3D) {
          x = r_a_Pose3D.x;
          y = r_a_Pose3D.y;
          z = r_a_Pose3D.z;
          pitch = r_a_Pose3D.pitch;
          yaw = r_a_Pose3D.yaw;
          roll = r_a_Pose3D.roll;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::Pose3D::~Pose3D() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::Pose3D& SRIO_Air_Unit::Air_Unit::Pose3D::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::Pose3D& SRIO_Air_Unit::Air_Unit::Pose3D::operator=(
       const SRIO_Air_Unit::Air_Unit::Pose3D& r_a_Pose3D) {
          if (this != &r_a_Pose3D) {
          x = r_a_Pose3D.x;
          y = r_a_Pose3D.y;
          z = r_a_Pose3D.z;
          pitch = r_a_Pose3D.pitch;
          yaw = r_a_Pose3D.yaw;
          roll = r_a_Pose3D.roll;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Pose3D

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Pose3D& r_SRIO_Air_Unit_Air_Unit_Pose3D)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Pose3D.x;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Pose3D.y;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Pose3D.z;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Pose3D.pitch;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Pose3D.yaw;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_Pose3D.roll;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::Pose3D& r_SRIO_Air_Unit_Air_Unit_Pose3D)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Pose3D.x;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Pose3D.y;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Pose3D.z;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Pose3D.pitch;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Pose3D.yaw;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_Pose3D.roll;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::Pose3D& r_SRIO_Air_Unit_Air_Unit_Pose3D)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Pose3D.x;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Pose3D.y;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Pose3D.z;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Pose3D.pitch;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Pose3D.yaw;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_Pose3D.roll;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::Pose3D
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_Pose3D, SRIO_Air_Unit::Air_Unit::Pose3D)

  // typecode instance for SRIO_Air_Unit_Air_Unit_Pose3D
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_Pose3D =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_Pose3D);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Pose3D 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Pose3D, SRIO_Air_Unit::Air_Unit::tc_Pose3D)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Pose3D, SRIO_Air_Unit::Air_Unit::tc_Pose3D)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Pose3D, SRIO_Air_Unit::Air_Unit::tc_Pose3D)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::GimbalState members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::GimbalState::GimbalState() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::GimbalState::GimbalState(const SRIO_Air_Unit::Air_Unit::GimbalState& r_a_GimbalState) {
          yaw = r_a_GimbalState.yaw;
          roll = r_a_GimbalState.roll;
          pitch = r_a_GimbalState.pitch;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::GimbalState::~GimbalState() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::GimbalState& SRIO_Air_Unit::Air_Unit::GimbalState::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::GimbalState& SRIO_Air_Unit::Air_Unit::GimbalState::operator=(
       const SRIO_Air_Unit::Air_Unit::GimbalState& r_a_GimbalState) {
          if (this != &r_a_GimbalState) {
          yaw = r_a_GimbalState.yaw;
          roll = r_a_GimbalState.roll;
          pitch = r_a_GimbalState.pitch;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::GimbalState

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::GimbalState& r_SRIO_Air_Unit_Air_Unit_GimbalState)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GimbalState.yaw;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GimbalState.roll;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GimbalState.pitch;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::GimbalState& r_SRIO_Air_Unit_Air_Unit_GimbalState)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GimbalState.yaw;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GimbalState.roll;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GimbalState.pitch;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::GimbalState& r_SRIO_Air_Unit_Air_Unit_GimbalState)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GimbalState.yaw;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GimbalState.roll;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GimbalState.pitch;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::GimbalState
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_GimbalState, SRIO_Air_Unit::Air_Unit::GimbalState)

  // typecode instance for SRIO_Air_Unit_Air_Unit_GimbalState
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_GimbalState =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_GimbalState);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::GimbalState 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GimbalState, SRIO_Air_Unit::Air_Unit::tc_GimbalState)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GimbalState, SRIO_Air_Unit::Air_Unit::tc_GimbalState)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GimbalState, SRIO_Air_Unit::Air_Unit::tc_GimbalState)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::GimbalSpeed members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::GimbalSpeed::GimbalSpeed() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::GimbalSpeed::GimbalSpeed(const SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_a_GimbalSpeed) {
          yaw = r_a_GimbalSpeed.yaw;
          roll = r_a_GimbalSpeed.roll;
          pitch = r_a_GimbalSpeed.pitch;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::GimbalSpeed::~GimbalSpeed() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::GimbalSpeed& SRIO_Air_Unit::Air_Unit::GimbalSpeed::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::GimbalSpeed& SRIO_Air_Unit::Air_Unit::GimbalSpeed::operator=(
       const SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_a_GimbalSpeed) {
          if (this != &r_a_GimbalSpeed) {
          yaw = r_a_GimbalSpeed.yaw;
          roll = r_a_GimbalSpeed.roll;
          pitch = r_a_GimbalSpeed.pitch;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::GimbalSpeed

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_SRIO_Air_Unit_Air_Unit_GimbalSpeed)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.yaw;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.roll;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.pitch;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_SRIO_Air_Unit_Air_Unit_GimbalSpeed)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.yaw;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.roll;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.pitch;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_SRIO_Air_Unit_Air_Unit_GimbalSpeed)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.yaw;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.roll;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_GimbalSpeed.pitch;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::GimbalSpeed
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_GimbalSpeed, SRIO_Air_Unit::Air_Unit::GimbalSpeed)

  // typecode instance for SRIO_Air_Unit_Air_Unit_GimbalSpeed
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_GimbalSpeed =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_GimbalSpeed);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::GimbalSpeed 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GimbalSpeed, SRIO_Air_Unit::Air_Unit::tc_GimbalSpeed)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GimbalSpeed, SRIO_Air_Unit::Air_Unit::tc_GimbalSpeed)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::GimbalSpeed, SRIO_Air_Unit::Air_Unit::tc_GimbalSpeed)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::BasicMoveActionData members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::BasicMoveActionData::BasicMoveActionData() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::BasicMoveActionData::BasicMoveActionData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_a_BasicMoveActionData) {
          speed = r_a_BasicMoveActionData.speed;
          duration = r_a_BasicMoveActionData.duration;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::BasicMoveActionData::~BasicMoveActionData() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::BasicMoveActionData::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::BasicMoveActionData::operator=(
       const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_a_BasicMoveActionData) {
          if (this != &r_a_BasicMoveActionData) {
          speed = r_a_BasicMoveActionData.speed;
          duration = r_a_BasicMoveActionData.duration;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::BasicMoveActionData

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData)  {

         r_call += iluSizeRecord;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData.speed;
          r_call += r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData.duration;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData)  {

         r_call << iluOutputRecord;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData.speed;
          r_call << r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData.duration;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData)  {

         r_call >> iluInputRecord;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData.speed;
          r_call >> r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData.duration;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::BasicMoveActionData
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_BasicMoveActionData, SRIO_Air_Unit::Air_Unit::BasicMoveActionData)

  // typecode instance for SRIO_Air_Unit_Air_Unit_BasicMoveActionData
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_BasicMoveActionData =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_BasicMoveActionData);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::BasicMoveActionData 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::BasicMoveActionData, SRIO_Air_Unit::Air_Unit::tc_BasicMoveActionData)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::BasicMoveActionData, SRIO_Air_Unit::Air_Unit::tc_BasicMoveActionData)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::BasicMoveActionData, SRIO_Air_Unit::Air_Unit::tc_BasicMoveActionData)


/////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit::ActionDuration members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   SRIO_Air_Unit::Air_Unit::ActionDuration::ActionDuration() {
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::ActionDuration::ActionDuration(const SRIO_Air_Unit::Air_Unit::ActionDuration& r_a_ActionDuration) {
          keep = r_a_ActionDuration.keep;
          ft_s = r_a_ActionDuration.ft_s;
          ft_t = r_a_ActionDuration.ft_t;
   }

  // destructor
  SRIO_Air_Unit::Air_Unit::ActionDuration::~ActionDuration() {
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::ActionDuration& SRIO_Air_Unit::Air_Unit::ActionDuration::self(){
        return *this;
  }

  // assignment operator
  SRIO_Air_Unit::Air_Unit::ActionDuration& SRIO_Air_Unit::Air_Unit::ActionDuration::operator=(
       const SRIO_Air_Unit::Air_Unit::ActionDuration& r_a_ActionDuration) {
          if (this != &r_a_ActionDuration) {
          keep = r_a_ActionDuration.keep;
          ft_s = r_a_ActionDuration.ft_s;
          ft_t = r_a_ActionDuration.ft_t;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::ActionDuration

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::ActionDuration& r_SRIO_Air_Unit_Air_Unit_ActionDuration)  {

         r_call += iluSizeRecord;
         iluBoolWrapper _r_keep_wrap(
             (ILUCPP_BOOL &) r_SRIO_Air_Unit_Air_Unit_ActionDuration.keep);
         r_call += _r_keep_wrap;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_ActionDuration.ft_s;
          r_call +=  r_SRIO_Air_Unit_Air_Unit_ActionDuration.ft_t;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const SRIO_Air_Unit::Air_Unit::ActionDuration& r_SRIO_Air_Unit_Air_Unit_ActionDuration)  {

         r_call << iluOutputRecord;
         iluBoolWrapper _r_keep_wrap(
             (ILUCPP_BOOL &) r_SRIO_Air_Unit_Air_Unit_ActionDuration.keep);
         r_call << _r_keep_wrap;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_ActionDuration.ft_s;
          r_call <<  r_SRIO_Air_Unit_Air_Unit_ActionDuration.ft_t;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          SRIO_Air_Unit::Air_Unit::ActionDuration& r_SRIO_Air_Unit_Air_Unit_ActionDuration)  {

         r_call >> iluInputRecord;
         iluBoolWrapper _r_keep_wrap(
             (ILUCPP_BOOL &) r_SRIO_Air_Unit_Air_Unit_ActionDuration.keep);
         r_call >> _r_keep_wrap;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_ActionDuration.ft_s;
          r_call >>  r_SRIO_Air_Unit_Air_Unit_ActionDuration.ft_t;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::ActionDuration
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_ActionDuration, SRIO_Air_Unit::Air_Unit::ActionDuration)

  // typecode instance for SRIO_Air_Unit_Air_Unit_ActionDuration
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_ActionDuration =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_ActionDuration);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::ActionDuration 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::ActionDuration, SRIO_Air_Unit::Air_Unit::tc_ActionDuration)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::ActionDuration, SRIO_Air_Unit::Air_Unit::tc_ActionDuration)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::ActionDuration, SRIO_Air_Unit::Air_Unit::tc_ActionDuration)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Air_Unit::Air_Unit::UnitSBHSeq members   

 // constructors & destructor
  SRIO_Air_Unit::Air_Unit::UnitSBHSeq::UnitSBHSeq () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Air_Unit::Air_Unit::UnitSBHSeq::UnitSBHSeq (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE) {
             m_buffer = allocbuf (m_maximum);
             m_varbuffer = new CORBA_(String_var[m_maximum]);
  }

  SRIO_Air_Unit::Air_Unit::UnitSBHSeq::UnitSBHSeq (CORBA_(ULong) max , CORBA_(ULong) length, 
        iluShortCharacter** data, CORBA_(Boolean) release)  : m_maximum(max),
        m_length(length),
        m_release (release), 
        m_buffer(data) {

        m_varbuffer = new CORBA_(String_var[max]);
        for (CORBA_(ULong) index = 0; index < max; index++) {
            (m_varbuffer[index]).iluSetRelease(m_release);
             m_varbuffer[index] = (data[index]);
        }	  
  }

  SRIO_Air_Unit::Air_Unit::UnitSBHSeq::UnitSBHSeq (const SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq)   :
         m_maximum(r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_maximum), 
         m_length(r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_length), 
         m_release(ILUCPP_TRUE) 
         {
            m_buffer = allocbuf (m_maximum);
            m_varbuffer = new CORBA_(String_var[m_length]);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_buffer[index];
               m_varbuffer[index] = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_varbuffer[index];
            } 
   }
		
  SRIO_Air_Unit::Air_Unit::UnitSBHSeq::~UnitSBHSeq() {
        if (m_buffer && m_release)
           freebuf (m_buffer);
        if(m_length > 0)
           delete [] m_varbuffer;
  }

 // assignment
   SRIO_Air_Unit::Air_Unit::UnitSBHSeq& SRIO_Air_Unit::Air_Unit::UnitSBHSeq::operator= (const SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq) {
         if (this == &r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         if (m_length > 0)  
              delete [] m_varbuffer;
          m_buffer = allocbuf (r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_maximum);
        m_varbuffer = new CORBA_(String_var[r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_length]);

#if (defined(OLDGNUC_WORKAROUND) || defined (_MSC_VER))
         // for some reason GNUC does not allow m_length set before copy
         // and/or doesn't allow m_length to govern iteration 
        // experimentally moved  then should consolidate 
         // and check if also solves object version of problem
          for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_length;
              index++) {
               m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_buffer[index];
               m_varbuffer[index] = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_varbuffer[index];
       }
          m_release = ILUCPP_TRUE;
          m_length = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_length;
          m_maximum = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_maximum;
#else
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_length;
         m_maximum = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_maximum;
        for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_buffer[index];
               m_varbuffer[index] = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.m_varbuffer[index];
         } 
#endif
        return *this;
  }

  // memory management
  iluShortCharacter** SRIO_Air_Unit::Air_Unit::UnitSBHSeq::allocbuf(CORBA_(ULong) num_elements) {
       if (num_elements > 0) {
          iluShortCharacter** p_new_buffer =
                new iluShortCharacter* [num_elements];
          for (CORBA_(ULong) ul_index = 0; ul_index < num_elements; ul_index++)
             p_new_buffer[ul_index] = *(new iluShortCharacter*);
          return p_new_buffer;
        }
        else return ILUCPP_NULL;
  }
  
  void SRIO_Air_Unit::Air_Unit::UnitSBHSeq::freebuf(iluShortCharacter** p_buf) {
        delete [] p_buf;
  }

   void SRIO_Air_Unit::Air_Unit::UnitSBHSeq::length (CORBA_(ULong) len) {
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
                 m_varbuffer = new CORBA_(String_var[m_length]);
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
   CORBA_(ULong) SRIO_Air_Unit::Air_Unit::UnitSBHSeq::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Air_Unit::Air_Unit::UnitSBHSeq::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Air_Unit::Air_Unit::UnitSBHSeq::release() const{
    return m_release;
  }
  
  // buffer accessors
  iluShortCharacter** SRIO_Air_Unit::Air_Unit::UnitSBHSeq::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  iluShortCharacter* const* SRIO_Air_Unit::Air_Unit::UnitSBHSeq::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  CORBA_(String_var)& SRIO_Air_Unit::Air_Unit::UnitSBHSeq::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_varbuffer[index];
  }
  
  const CORBA_(String_var)& SRIO_Air_Unit::Air_Unit::UnitSBHSeq::operator [] (CORBA_(ULong) index) const {
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
  SRIO_Air_Unit::Air_Unit::UnitSBHSeq& SRIO_Air_Unit::Air_Unit::UnitSBHSeq::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::UnitSBHSeq

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq(card_length);
        r_call += _r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.length(); index++) {
          iluCardinal s_element_length =
              strlen(r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq[index].iluStringVarReference());
          iluCStringWrapper  s_element(
            r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq[index].iluStringVarReference(), s_element_length);
          r_call += s_element; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq(card_length);
        r_call << _r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq.length(); index++) {
          iluCardinal s_element_length =
              strlen(r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq[index].iluStringVarReference());
          iluCStringWrapper  s_element(
            r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq[index].iluStringVarReference(), s_element_length);
          r_call << s_element; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Air_Unit::Air_Unit::UnitSBHSeq _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          iluCardinal s_element_length;
          iluCStringWrapper  s_element(
            _seq_temp[index].iluStringVarReference(), s_element_length);
          r_call >> s_element; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq = SRIO_Air_Unit::Air_Unit::UnitSBHSeq(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::UnitSBHSeq
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_UnitSBHSeq, SRIO_Air_Unit::Air_Unit::UnitSBHSeq)

  // typecode instance for SRIO_Air_Unit_Air_Unit_UnitSBHSeq
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_UnitSBHSeq =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_UnitSBHSeq);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::UnitSBHSeq 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::UnitSBHSeq, SRIO_Air_Unit::Air_Unit::tc_UnitSBHSeq)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::UnitSBHSeq, SRIO_Air_Unit::Air_Unit::tc_UnitSBHSeq)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::UnitSBHSeq, SRIO_Air_Unit::Air_Unit::tc_UnitSBHSeq)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Air_Unit::Air_Unit::TrapPointSequence members   

 // constructors & destructor
  SRIO_Air_Unit::Air_Unit::TrapPointSequence::TrapPointSequence () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Air_Unit::Air_Unit::TrapPointSequence::TrapPointSequence (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Air_Unit::Air_Unit::TrapPointSequence::TrapPointSequence (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Air_Unit::Air_Unit::TrapPoint3D* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Air_Unit::Air_Unit::TrapPointSequence::~TrapPointSequence() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Air_Unit::Air_Unit::TrapPointSequence::TrapPointSequence (const SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence)
  :
         m_maximum(r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.m_maximum),
         m_length(r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.m_buffer[index];
            }
   }

 // assignment
   SRIO_Air_Unit::Air_Unit::TrapPointSequence& SRIO_Air_Unit::Air_Unit::TrapPointSequence::operator= (const SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence) {
         if (this == &r_SRIO_Air_Unit_Air_Unit_TrapPointSequence) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Air_Unit::Air_Unit::TrapPoint3D* SRIO_Air_Unit::Air_Unit::TrapPointSequence::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Air_Unit::Air_Unit::TrapPoint3D[num_elements]) : NULL);
  }
  
  void SRIO_Air_Unit::Air_Unit::TrapPointSequence::freebuf(SRIO_Air_Unit::Air_Unit::TrapPoint3D* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Air_Unit::Air_Unit::TrapPointSequence::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Air_Unit::Air_Unit::TrapPoint3D* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Air_Unit::Air_Unit::TrapPointSequence::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Air_Unit::Air_Unit::TrapPointSequence::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Air_Unit::Air_Unit::TrapPointSequence::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Air_Unit::Air_Unit::TrapPoint3D* SRIO_Air_Unit::Air_Unit::TrapPointSequence::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Air_Unit::Air_Unit::TrapPoint3D const* SRIO_Air_Unit::Air_Unit::TrapPointSequence::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Air_Unit::Air_Unit::TrapPoint3D& SRIO_Air_Unit::Air_Unit::TrapPointSequence::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Air_Unit::Air_Unit::TrapPoint3D& SRIO_Air_Unit::Air_Unit::TrapPointSequence::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Air_Unit::Air_Unit::TrapPoint3D *_temp = 
              (const SRIO_Air_Unit::Air_Unit::TrapPoint3D *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::TrapPointSequence& SRIO_Air_Unit::Air_Unit::TrapPointSequence::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::TrapPointSequence

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_TrapPointSequence(card_length);
        r_call += _r_SRIO_Air_Unit_Air_Unit_TrapPointSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.length(); index++) {
          r_call += r_SRIO_Air_Unit_Air_Unit_TrapPointSequence[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_TrapPointSequence(card_length);
        r_call << _r_SRIO_Air_Unit_Air_Unit_TrapPointSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_TrapPointSequence.length(); index++) {
          r_call << r_SRIO_Air_Unit_Air_Unit_TrapPointSequence[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Air_Unit::Air_Unit::TrapPointSequence _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Air_Unit_Air_Unit_TrapPointSequence = SRIO_Air_Unit::Air_Unit::TrapPointSequence(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::TrapPointSequence
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_TrapPointSequence, SRIO_Air_Unit::Air_Unit::TrapPointSequence)

  // typecode instance for SRIO_Air_Unit_Air_Unit_TrapPointSequence
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_TrapPointSequence =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_TrapPointSequence);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::TrapPointSequence 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TrapPointSequence, SRIO_Air_Unit::Air_Unit::tc_TrapPointSequence)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TrapPointSequence, SRIO_Air_Unit::Air_Unit::tc_TrapPointSequence)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TrapPointSequence, SRIO_Air_Unit::Air_Unit::tc_TrapPointSequence)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Air_Unit::Air_Unit::TaskPath members   

 // constructors & destructor
  SRIO_Air_Unit::Air_Unit::TaskPath::TaskPath () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Air_Unit::Air_Unit::TaskPath::TaskPath (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Air_Unit::Air_Unit::TaskPath::TaskPath (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Air_Unit::Air_Unit::Point3D* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Air_Unit::Air_Unit::TaskPath::~TaskPath() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Air_Unit::Air_Unit::TaskPath::TaskPath (const SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath)
  :
         m_maximum(r_SRIO_Air_Unit_Air_Unit_TaskPath.m_maximum),
         m_length(r_SRIO_Air_Unit_Air_Unit_TaskPath.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_TaskPath.m_buffer[index];
            }
   }

 // assignment
   SRIO_Air_Unit::Air_Unit::TaskPath& SRIO_Air_Unit::Air_Unit::TaskPath::operator= (const SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath) {
         if (this == &r_SRIO_Air_Unit_Air_Unit_TaskPath) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Air_Unit_Air_Unit_TaskPath.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Air_Unit_Air_Unit_TaskPath.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_TaskPath.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Air_Unit::Air_Unit::Point3D* SRIO_Air_Unit::Air_Unit::TaskPath::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Air_Unit::Air_Unit::Point3D[num_elements]) : NULL);
  }
  
  void SRIO_Air_Unit::Air_Unit::TaskPath::freebuf(SRIO_Air_Unit::Air_Unit::Point3D* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Air_Unit::Air_Unit::TaskPath::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Air_Unit::Air_Unit::Point3D* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Air_Unit::Air_Unit::TaskPath::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Air_Unit::Air_Unit::TaskPath::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Air_Unit::Air_Unit::TaskPath::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Air_Unit::Air_Unit::Point3D* SRIO_Air_Unit::Air_Unit::TaskPath::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Air_Unit::Air_Unit::Point3D const* SRIO_Air_Unit::Air_Unit::TaskPath::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Air_Unit::Air_Unit::Point3D& SRIO_Air_Unit::Air_Unit::TaskPath::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Air_Unit::Air_Unit::Point3D& SRIO_Air_Unit::Air_Unit::TaskPath::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Air_Unit::Air_Unit::Point3D *_temp = 
              (const SRIO_Air_Unit::Air_Unit::Point3D *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::TaskPath& SRIO_Air_Unit::Air_Unit::TaskPath::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::TaskPath

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_TaskPath.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_TaskPath(card_length);
        r_call += _r_SRIO_Air_Unit_Air_Unit_TaskPath;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_TaskPath.length(); index++) {
          r_call += r_SRIO_Air_Unit_Air_Unit_TaskPath[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_TaskPath.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_TaskPath(card_length);
        r_call << _r_SRIO_Air_Unit_Air_Unit_TaskPath;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_TaskPath.length(); index++) {
          r_call << r_SRIO_Air_Unit_Air_Unit_TaskPath[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Air_Unit::Air_Unit::TaskPath _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Air_Unit_Air_Unit_TaskPath = SRIO_Air_Unit::Air_Unit::TaskPath(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::TaskPath
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_TaskPath, SRIO_Air_Unit::Air_Unit::TaskPath)

  // typecode instance for SRIO_Air_Unit_Air_Unit_TaskPath
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_TaskPath =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_TaskPath);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::TaskPath 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TaskPath, SRIO_Air_Unit::Air_Unit::tc_TaskPath)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TaskPath, SRIO_Air_Unit::Air_Unit::tc_TaskPath)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::TaskPath, SRIO_Air_Unit::Air_Unit::tc_TaskPath)
  

 //////////////////////////////////////////////////////////////////////
 // SRIO_Air_Unit::Air_Unit::ActionSequence members   

 // constructors & destructor
  SRIO_Air_Unit::Air_Unit::ActionSequence::ActionSequence () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  SRIO_Air_Unit::Air_Unit::ActionSequence::ActionSequence (CORBA_(ULong) max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  SRIO_Air_Unit::Air_Unit::ActionSequence::ActionSequence (CORBA_(ULong) max , CORBA_(ULong) length, 
          SRIO_Air_Unit::Air_Unit::MoveAction* data, CORBA_(Boolean) release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  SRIO_Air_Unit::Air_Unit::ActionSequence::~ActionSequence() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  SRIO_Air_Unit::Air_Unit::ActionSequence::ActionSequence (const SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence)
  :
         m_maximum(r_SRIO_Air_Unit_Air_Unit_ActionSequence.m_maximum),
         m_length(r_SRIO_Air_Unit_Air_Unit_ActionSequence.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_(ULong) index = 0; index < m_length; index++) {
               m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_ActionSequence.m_buffer[index];
            }
   }

 // assignment
   SRIO_Air_Unit::Air_Unit::ActionSequence& SRIO_Air_Unit::Air_Unit::ActionSequence::operator= (const SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence) {
         if (this == &r_SRIO_Air_Unit_Air_Unit_ActionSequence) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_SRIO_Air_Unit_Air_Unit_ActionSequence.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_SRIO_Air_Unit_Air_Unit_ActionSequence.m_length;
          for (CORBA_(ULong) index = 0; index < m_length; index++) {
              m_buffer[index] = r_SRIO_Air_Unit_Air_Unit_ActionSequence.m_buffer[index];
          }
          return *this;
       }

  // memory management
  SRIO_Air_Unit::Air_Unit::MoveAction* SRIO_Air_Unit::Air_Unit::ActionSequence::allocbuf(CORBA_(ULong) num_elements) {
      return (num_elements > 0 ? (new SRIO_Air_Unit::Air_Unit::MoveAction[num_elements]) : NULL);
  }
  
  void SRIO_Air_Unit::Air_Unit::ActionSequence::freebuf(SRIO_Air_Unit::Air_Unit::MoveAction* p_buf) {
        delete [] p_buf;
  }

  void SRIO_Air_Unit::Air_Unit::ActionSequence::length (CORBA_(ULong) len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 SRIO_Air_Unit::Air_Unit::MoveAction* p_oldbuf = m_buffer;
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
   CORBA_(ULong) SRIO_Air_Unit::Air_Unit::ActionSequence::maximum() const {
        return m_maximum;
  }
  
  CORBA_(ULong) SRIO_Air_Unit::Air_Unit::ActionSequence::length() const {
        return m_length;
  }  
  
  CORBA_(Boolean) SRIO_Air_Unit::Air_Unit::ActionSequence::release() const{
    return m_release;
  }
  
  // buffer accessors
  SRIO_Air_Unit::Air_Unit::MoveAction* SRIO_Air_Unit::Air_Unit::ActionSequence::get_buffer (CORBA_(Boolean) orphan){
    if(orphan) {
	  if(!m_release)
	    return NULL;
	  m_release = ilu_FALSE;
	}
	if(m_buffer == NULL)
	  m_buffer = allocbuf(1);
	return m_buffer;
  }
  
  SRIO_Air_Unit::Air_Unit::MoveAction const* SRIO_Air_Unit::Air_Unit::ActionSequence::get_buffer () const{
	return m_buffer;
  }

  // [] operators
  SRIO_Air_Unit::Air_Unit::MoveAction& SRIO_Air_Unit::Air_Unit::ActionSequence::operator [] (CORBA_(ULong) index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const SRIO_Air_Unit::Air_Unit::MoveAction& SRIO_Air_Unit::Air_Unit::ActionSequence::operator [] (CORBA_(ULong) index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_(UNKNOWN) an_exception(0, CORBA_(COMPLETED_NO));
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const SRIO_Air_Unit::Air_Unit::MoveAction *_temp = 
              (const SRIO_Air_Unit::Air_Unit::MoveAction *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::ActionSequence& SRIO_Air_Unit::Air_Unit::ActionSequence::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::ActionSequence

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_ActionSequence.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_ActionSequence(card_length);
        r_call += _r_SRIO_Air_Unit_Air_Unit_ActionSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_ActionSequence.length(); index++) {
          r_call += r_SRIO_Air_Unit_Air_Unit_ActionSequence[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence){

        iluCardinal card_length = r_SRIO_Air_Unit_Air_Unit_ActionSequence.length();
        iluSequenceWrapper _r_SRIO_Air_Unit_Air_Unit_ActionSequence(card_length);
        r_call << _r_SRIO_Air_Unit_Air_Unit_ActionSequence;
        for (CORBA_(ULong) index = 0; index < r_SRIO_Air_Unit_Air_Unit_ActionSequence.length(); index++) {
          r_call << r_SRIO_Air_Unit_Air_Unit_ActionSequence[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence){

        CORBA_(ULong) card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        SRIO_Air_Unit::Air_Unit::ActionSequence _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_(ULong) index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_SRIO_Air_Unit_Air_Unit_ActionSequence = SRIO_Air_Unit::Air_Unit::ActionSequence(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::ActionSequence
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_ActionSequence, SRIO_Air_Unit::Air_Unit::ActionSequence)

  // typecode instance for SRIO_Air_Unit_Air_Unit_ActionSequence
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_ActionSequence =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_ActionSequence);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::ActionSequence 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::ActionSequence, SRIO_Air_Unit::Air_Unit::tc_ActionSequence)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::ActionSequence, SRIO_Air_Unit::Air_Unit::tc_ActionSequence)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::ActionSequence, SRIO_Air_Unit::Air_Unit::tc_ActionSequence)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Air_Unit::Air_Unit::Site members
		
  // constructors & destructor
  SRIO_Air_Unit::Air_Unit::Site::Site() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Air_Unit::Air_Unit::Site::Site(const SRIO_Air_Unit::Air_Unit::Site& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Air_Unit::Air_Unit::Site::~Site() {
	  unset();
  }

  // assignment
  SRIO_Air_Unit::Air_Unit::Site& SRIO_Air_Unit::Air_Unit::Site::operator=
          (const SRIO_Air_Unit::Air_Unit::Site& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // rd
		  case SRIO_Air_Unit::Air_Unit::Rectangle:  
                   m_rd =
                      new SRIO_Air_Unit::Air_Unit::RectangleData(*r_union_type.m_rd);
                   break;

                 // cd
		  case SRIO_Air_Unit::Air_Unit::Circle:  
                   m_cd =
                      new SRIO_Air_Unit::Air_Unit::CircleData(*r_union_type.m_cd);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::Site& SRIO_Air_Unit::Air_Unit::Site::self(){
        return *this;
  }

  // discriminator access
  SRIO_Air_Unit::Air_Unit::SiteType SRIO_Air_Unit::Air_Unit::Site::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Air_Unit::Air_Unit::Site::_d (SRIO_Air_Unit::Air_Unit::SiteType new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // rd
		  case SRIO_Air_Unit::Air_Unit::Rectangle:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::Rectangle: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // cd
		  case SRIO_Air_Unit::Air_Unit::Circle:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::Circle: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Air_Unit::Air_Unit::Rectangle: 
                       case SRIO_Air_Unit::Air_Unit::Circle: 
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
 
   // rd access
    const SRIO_Air_Unit::Air_Unit::RectangleData& SRIO_Air_Unit::Air_Unit::Site::rd() const {
           return( (const SRIO_Air_Unit::Air_Unit::RectangleData&) *m_rd);
    }

    SRIO_Air_Unit::Air_Unit::RectangleData& SRIO_Air_Unit::Air_Unit::Site::rd(){
           return( (SRIO_Air_Unit::Air_Unit::RectangleData&) *m_rd);
    }

    void SRIO_Air_Unit::Air_Unit::Site::rd(const SRIO_Air_Unit::Air_Unit::RectangleData & a_rd){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::Rectangle;
         m_rd = new SRIO_Air_Unit::Air_Unit::RectangleData(a_rd);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // cd access
    const SRIO_Air_Unit::Air_Unit::CircleData& SRIO_Air_Unit::Air_Unit::Site::cd() const {
           return( (const SRIO_Air_Unit::Air_Unit::CircleData&) *m_cd);
    }

    SRIO_Air_Unit::Air_Unit::CircleData& SRIO_Air_Unit::Air_Unit::Site::cd(){
           return( (SRIO_Air_Unit::Air_Unit::CircleData&) *m_cd);
    }

    void SRIO_Air_Unit::Air_Unit::Site::cd(const SRIO_Air_Unit::Air_Unit::CircleData & a_cd){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::Circle;
         m_cd = new SRIO_Air_Unit::Air_Unit::CircleData(a_cd);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  void SRIO_Air_Unit::Air_Unit::Site::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // rd
		  case SRIO_Air_Unit::Air_Unit::Rectangle:  
                     delete m_rd;
                     break;

                 // cd
		  case SRIO_Air_Unit::Air_Unit::Circle:  
                     delete m_cd;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Site

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Air_Unit::Air_Unit::Site& r_SRIO_Air_Unit_Air_Unit_Site) {

          iluUnionWrapper _r_SRIO_Air_Unit_Air_Unit_Site(
                                r_SRIO_Air_Unit_Air_Unit_Site._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Air_Unit_Air_Unit_Site;

          switch (r_SRIO_Air_Unit_Air_Unit_Site.m_discriminator) {

                 // rd
		  case SRIO_Air_Unit::Air_Unit::Rectangle:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_Site.m_rd); 
                   break;

                 // cd
		  case SRIO_Air_Unit::Air_Unit::Circle:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_Site.m_cd); 
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Air_Unit::Air_Unit::Site& r_SRIO_Air_Unit_Air_Unit_Site) {

          iluUnionWrapper _r_SRIO_Air_Unit_Air_Unit_Site(
                                r_SRIO_Air_Unit_Air_Unit_Site._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Air_Unit_Air_Unit_Site;

          switch (r_SRIO_Air_Unit_Air_Unit_Site.m_discriminator) {

                 // rd
		  case SRIO_Air_Unit::Air_Unit::Rectangle:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_Site.m_rd); 
                   break;

                 // cd
		  case SRIO_Air_Unit::Air_Unit::Circle:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_Site.m_cd); 
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Air_Unit::Air_Unit::Site& r_SRIO_Air_Unit_Air_Unit_Site) {
        
          iluUnionWrapper _r_SRIO_Air_Unit_Air_Unit_Site(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Air_Unit_Air_Unit_Site;

          switch (_r_SRIO_Air_Unit_Air_Unit_Site.m_card_discriminator) {

                 // rd
		  case SRIO_Air_Unit::Air_Unit::Rectangle:  
                 { SRIO_Air_Unit::Air_Unit::RectangleData  rd_temp;
                    r_call >> rd_temp;
                    r_SRIO_Air_Unit_Air_Unit_Site.rd(rd_temp);
                    break;
                   }

                 // cd
		  case SRIO_Air_Unit::Air_Unit::Circle:  
                 { SRIO_Air_Unit::Air_Unit::CircleData  cd_temp;
                    r_call >> cd_temp;
                    r_SRIO_Air_Unit_Air_Unit_Site.cd(cd_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Air_Unit_Air_Unit_Site._d((SRIO_Air_Unit::Air_Unit::SiteType) (_r_SRIO_Air_Unit_Air_Unit_Site.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::Site
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_Site, SRIO_Air_Unit::Air_Unit::Site)

  // typecode instance for SRIO_Air_Unit_Air_Unit_Site
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_Site =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_Site);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Site 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Site, SRIO_Air_Unit::Air_Unit::tc_Site)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Site, SRIO_Air_Unit::Air_Unit::tc_Site)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::Site, SRIO_Air_Unit::Air_Unit::tc_Site)


  //////////////////////////////////////////////////////////////////////
  // SRIO_Air_Unit::Air_Unit::MoveAction members
		
  // constructors & destructor
  SRIO_Air_Unit::Air_Unit::MoveAction::MoveAction() : m_b_beenset(ILUCPP_FALSE) {}

  SRIO_Air_Unit::Air_Unit::MoveAction::MoveAction(const SRIO_Air_Unit::Air_Unit::MoveAction& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  SRIO_Air_Unit::Air_Unit::MoveAction::~MoveAction() {
	  unset();
  }

  // assignment
  SRIO_Air_Unit::Air_Unit::MoveAction& SRIO_Air_Unit::Air_Unit::MoveAction::operator=
          (const SRIO_Air_Unit::Air_Unit::MoveAction& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // goUpData
		  case SRIO_Air_Unit::Air_Unit::MA_GoUp:  
                   m_goUpData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_goUpData);
                   break;

                 // goDownData
		  case SRIO_Air_Unit::Air_Unit::MA_GoDown:  
                   m_goDownData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_goDownData);
                   break;

                 // goAheadData
		  case SRIO_Air_Unit::Air_Unit::MA_GoAhead:  
                   m_goAheadData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_goAheadData);
                   break;

                 // goBackwardData
		  case SRIO_Air_Unit::Air_Unit::MA_GoBackward:  
                   m_goBackwardData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_goBackwardData);
                   break;

                 // goLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_GoLeft:  
                   m_goLeftData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_goLeftData);
                   break;

                 // goRightData
		  case SRIO_Air_Unit::Air_Unit::MA_GoRight:  
                   m_goRightData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_goRightData);
                   break;

                 // turnLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnLeft:  
                   m_turnLeftData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_turnLeftData);
                   break;

                 // turnRightData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnRight:  
                   m_turnRightData =
                      new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(*r_union_type.m_turnRightData);
                   break;

                 // stopData
		  case SRIO_Air_Unit::Air_Unit::MA_Stop:  
                   m_stopData =
                      new SRIO_Air_Unit::Air_Unit::ActionDuration(*r_union_type.m_stopData);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  SRIO_Air_Unit::Air_Unit::MoveAction& SRIO_Air_Unit::Air_Unit::MoveAction::self(){
        return *this;
  }

  // discriminator access
  SRIO_Air_Unit::Air_Unit::MoveActionType SRIO_Air_Unit::Air_Unit::MoveAction::_d () const { 
	  return m_discriminator; 
  }

  void SRIO_Air_Unit::Air_Unit::MoveAction::_d (SRIO_Air_Unit::Air_Unit::MoveActionType new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // goUpData
		  case SRIO_Air_Unit::Air_Unit::MA_GoUp:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_GoUp: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // goDownData
		  case SRIO_Air_Unit::Air_Unit::MA_GoDown:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_GoDown: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // goAheadData
		  case SRIO_Air_Unit::Air_Unit::MA_GoAhead:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_GoAhead: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // goBackwardData
		  case SRIO_Air_Unit::Air_Unit::MA_GoBackward:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_GoBackward: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // goLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_GoLeft:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_GoLeft: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // goRightData
		  case SRIO_Air_Unit::Air_Unit::MA_GoRight:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_GoRight: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // turnLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnLeft:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_TurnLeft: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // turnRightData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnRight:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_TurnRight: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // stopData
		  case SRIO_Air_Unit::Air_Unit::MA_Stop:  
                  switch(new_d) { 
                       case SRIO_Air_Unit::Air_Unit::MA_Stop: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case SRIO_Air_Unit::Air_Unit::MA_GoUp: 
                       case SRIO_Air_Unit::Air_Unit::MA_GoDown: 
                       case SRIO_Air_Unit::Air_Unit::MA_GoAhead: 
                       case SRIO_Air_Unit::Air_Unit::MA_GoBackward: 
                       case SRIO_Air_Unit::Air_Unit::MA_GoLeft: 
                       case SRIO_Air_Unit::Air_Unit::MA_GoRight: 
                       case SRIO_Air_Unit::Air_Unit::MA_TurnLeft: 
                       case SRIO_Air_Unit::Air_Unit::MA_TurnRight: 
                       case SRIO_Air_Unit::Air_Unit::MA_Stop: 
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
 
   // goUpData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goUpData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goUpData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goUpData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goUpData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::goUpData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_goUpData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_GoUp;
         m_goUpData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_goUpData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // goDownData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goDownData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goDownData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goDownData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goDownData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::goDownData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_goDownData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_GoDown;
         m_goDownData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_goDownData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // goAheadData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goAheadData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goAheadData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goAheadData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goAheadData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::goAheadData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_goAheadData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_GoAhead;
         m_goAheadData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_goAheadData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // goBackwardData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goBackwardData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goBackwardData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goBackwardData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goBackwardData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::goBackwardData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_goBackwardData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_GoBackward;
         m_goBackwardData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_goBackwardData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // goLeftData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goLeftData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goLeftData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goLeftData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goLeftData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::goLeftData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_goLeftData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_GoLeft;
         m_goLeftData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_goLeftData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // goRightData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goRightData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goRightData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::goRightData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_goRightData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::goRightData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_goRightData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_GoRight;
         m_goRightData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_goRightData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // turnLeftData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::turnLeftData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_turnLeftData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::turnLeftData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_turnLeftData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::turnLeftData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_turnLeftData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_TurnLeft;
         m_turnLeftData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_turnLeftData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // turnRightData access
    const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::turnRightData() const {
           return( (const SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_turnRightData);
    }

    SRIO_Air_Unit::Air_Unit::BasicMoveActionData& SRIO_Air_Unit::Air_Unit::MoveAction::turnRightData(){
           return( (SRIO_Air_Unit::Air_Unit::BasicMoveActionData&) *m_turnRightData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::turnRightData(const SRIO_Air_Unit::Air_Unit::BasicMoveActionData & a_turnRightData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_TurnRight;
         m_turnRightData = new SRIO_Air_Unit::Air_Unit::BasicMoveActionData(a_turnRightData);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // stopData access
    const SRIO_Air_Unit::Air_Unit::ActionDuration& SRIO_Air_Unit::Air_Unit::MoveAction::stopData() const {
           return( (const SRIO_Air_Unit::Air_Unit::ActionDuration&) *m_stopData);
    }

    SRIO_Air_Unit::Air_Unit::ActionDuration& SRIO_Air_Unit::Air_Unit::MoveAction::stopData(){
           return( (SRIO_Air_Unit::Air_Unit::ActionDuration&) *m_stopData);
    }

    void SRIO_Air_Unit::Air_Unit::MoveAction::stopData(const SRIO_Air_Unit::Air_Unit::ActionDuration & a_stopData){
         unset();
         m_discriminator = SRIO_Air_Unit::Air_Unit::MA_Stop;
         m_stopData = new SRIO_Air_Unit::Air_Unit::ActionDuration(a_stopData);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  void SRIO_Air_Unit::Air_Unit::MoveAction::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // goUpData
		  case SRIO_Air_Unit::Air_Unit::MA_GoUp:  
                     delete m_goUpData;
                     break;

                 // goDownData
		  case SRIO_Air_Unit::Air_Unit::MA_GoDown:  
                     delete m_goDownData;
                     break;

                 // goAheadData
		  case SRIO_Air_Unit::Air_Unit::MA_GoAhead:  
                     delete m_goAheadData;
                     break;

                 // goBackwardData
		  case SRIO_Air_Unit::Air_Unit::MA_GoBackward:  
                     delete m_goBackwardData;
                     break;

                 // goLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_GoLeft:  
                     delete m_goLeftData;
                     break;

                 // goRightData
		  case SRIO_Air_Unit::Air_Unit::MA_GoRight:  
                     delete m_goRightData;
                     break;

                 // turnLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnLeft:  
                     delete m_turnLeftData;
                     break;

                 // turnRightData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnRight:  
                     delete m_turnRightData;
                     break;

                 // stopData
		  case SRIO_Air_Unit::Air_Unit::MA_Stop:  
                     delete m_stopData;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::MoveAction

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const SRIO_Air_Unit::Air_Unit::MoveAction& r_SRIO_Air_Unit_Air_Unit_MoveAction) {

          iluUnionWrapper _r_SRIO_Air_Unit_Air_Unit_MoveAction(
                                r_SRIO_Air_Unit_Air_Unit_MoveAction._d(),
                                ilu_enumeration_tk);
          r_call += _r_SRIO_Air_Unit_Air_Unit_MoveAction;

          switch (r_SRIO_Air_Unit_Air_Unit_MoveAction.m_discriminator) {

                 // goUpData
		  case SRIO_Air_Unit::Air_Unit::MA_GoUp:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goUpData); 
                   break;

                 // goDownData
		  case SRIO_Air_Unit::Air_Unit::MA_GoDown:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goDownData); 
                   break;

                 // goAheadData
		  case SRIO_Air_Unit::Air_Unit::MA_GoAhead:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goAheadData); 
                   break;

                 // goBackwardData
		  case SRIO_Air_Unit::Air_Unit::MA_GoBackward:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goBackwardData); 
                   break;

                 // goLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_GoLeft:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goLeftData); 
                   break;

                 // goRightData
		  case SRIO_Air_Unit::Air_Unit::MA_GoRight:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goRightData); 
                   break;

                 // turnLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnLeft:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_turnLeftData); 
                   break;

                 // turnRightData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnRight:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_turnRightData); 
                   break;

                 // stopData
		  case SRIO_Air_Unit::Air_Unit::MA_Stop:  
                    r_call += (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_stopData); 
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const SRIO_Air_Unit::Air_Unit::MoveAction& r_SRIO_Air_Unit_Air_Unit_MoveAction) {

          iluUnionWrapper _r_SRIO_Air_Unit_Air_Unit_MoveAction(
                                r_SRIO_Air_Unit_Air_Unit_MoveAction._d(),
                                ilu_enumeration_tk);
          r_call << _r_SRIO_Air_Unit_Air_Unit_MoveAction;

          switch (r_SRIO_Air_Unit_Air_Unit_MoveAction.m_discriminator) {

                 // goUpData
		  case SRIO_Air_Unit::Air_Unit::MA_GoUp:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goUpData); 
                   break;

                 // goDownData
		  case SRIO_Air_Unit::Air_Unit::MA_GoDown:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goDownData); 
                   break;

                 // goAheadData
		  case SRIO_Air_Unit::Air_Unit::MA_GoAhead:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goAheadData); 
                   break;

                 // goBackwardData
		  case SRIO_Air_Unit::Air_Unit::MA_GoBackward:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goBackwardData); 
                   break;

                 // goLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_GoLeft:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goLeftData); 
                   break;

                 // goRightData
		  case SRIO_Air_Unit::Air_Unit::MA_GoRight:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_goRightData); 
                   break;

                 // turnLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnLeft:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_turnLeftData); 
                   break;

                 // turnRightData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnRight:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_turnRightData); 
                   break;

                 // stopData
		  case SRIO_Air_Unit::Air_Unit::MA_Stop:  
                    r_call << (*r_SRIO_Air_Unit_Air_Unit_MoveAction.m_stopData); 
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, SRIO_Air_Unit::Air_Unit::MoveAction& r_SRIO_Air_Unit_Air_Unit_MoveAction) {
        
          iluUnionWrapper _r_SRIO_Air_Unit_Air_Unit_MoveAction(0, ilu_enumeration_tk);
        
          r_call >> _r_SRIO_Air_Unit_Air_Unit_MoveAction;

          switch (_r_SRIO_Air_Unit_Air_Unit_MoveAction.m_card_discriminator) {

                 // goUpData
		  case SRIO_Air_Unit::Air_Unit::MA_GoUp:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  goUpData_temp;
                    r_call >> goUpData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.goUpData(goUpData_temp);
                    break;
                   }

                 // goDownData
		  case SRIO_Air_Unit::Air_Unit::MA_GoDown:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  goDownData_temp;
                    r_call >> goDownData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.goDownData(goDownData_temp);
                    break;
                   }

                 // goAheadData
		  case SRIO_Air_Unit::Air_Unit::MA_GoAhead:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  goAheadData_temp;
                    r_call >> goAheadData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.goAheadData(goAheadData_temp);
                    break;
                   }

                 // goBackwardData
		  case SRIO_Air_Unit::Air_Unit::MA_GoBackward:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  goBackwardData_temp;
                    r_call >> goBackwardData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.goBackwardData(goBackwardData_temp);
                    break;
                   }

                 // goLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_GoLeft:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  goLeftData_temp;
                    r_call >> goLeftData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.goLeftData(goLeftData_temp);
                    break;
                   }

                 // goRightData
		  case SRIO_Air_Unit::Air_Unit::MA_GoRight:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  goRightData_temp;
                    r_call >> goRightData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.goRightData(goRightData_temp);
                    break;
                   }

                 // turnLeftData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnLeft:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  turnLeftData_temp;
                    r_call >> turnLeftData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.turnLeftData(turnLeftData_temp);
                    break;
                   }

                 // turnRightData
		  case SRIO_Air_Unit::Air_Unit::MA_TurnRight:  
                 { SRIO_Air_Unit::Air_Unit::BasicMoveActionData  turnRightData_temp;
                    r_call >> turnRightData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.turnRightData(turnRightData_temp);
                    break;
                   }

                 // stopData
		  case SRIO_Air_Unit::Air_Unit::MA_Stop:  
                 { SRIO_Air_Unit::Air_Unit::ActionDuration  stopData_temp;
                    r_call >> stopData_temp;
                    r_SRIO_Air_Unit_Air_Unit_MoveAction.stopData(stopData_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_SRIO_Air_Unit_Air_Unit_MoveAction._d((SRIO_Air_Unit::Air_Unit::MoveActionType) (_r_SRIO_Air_Unit_Air_Unit_MoveAction.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for SRIO_Air_Unit::Air_Unit::MoveAction
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             SRIO_Air_Unit_Air_Unit_MoveAction, SRIO_Air_Unit::Air_Unit::MoveAction)

  // typecode instance for SRIO_Air_Unit_Air_Unit_MoveAction
  const CORBA_(TypeCode_ptr) SRIO_Air_Unit::Air_Unit::tc_MoveAction =
            new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit_MoveAction);

  // define the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::MoveAction 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::MoveAction, SRIO_Air_Unit::Air_Unit::tc_MoveAction)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::MoveAction, SRIO_Air_Unit::Air_Unit::tc_MoveAction)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          SRIO_Air_Unit::Air_Unit::MoveAction, SRIO_Air_Unit::Air_Unit::tc_MoveAction)

  //////////////////////////////////////////////////////////////////////
  // SRIO_Air_Unit::Air_Unit members

  // CORBA object reference operations

  SRIO_Air_Unit::Air_Unit_ptr SRIO_Air_Unit::Air_Unit::_duplicate( Air_Unit_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  SRIO_Air_Unit::Air_Unit_ptr SRIO_Air_Unit::Air_Unit::_nil() {
    return (Air_Unit_ptr) NULL;
  }

  // default constructor
  SRIO_Air_Unit::Air_Unit::Air_Unit() {
     // to be determined
  }

  // destructor
  SRIO_Air_Unit::Air_Unit::~Air_Unit() {
    // to be determined
  }

  // copy constructor
  SRIO_Air_Unit::Air_Unit::Air_Unit(const Air_Unit&) {
    // to be determined
  }

  // assignment operator
  void SRIO_Air_Unit::Air_Unit::operator=(const Air_Unit&) {
    // to be determined
  }

  // Simple Object Lookup
  SRIO_Air_Unit::Air_Unit_ptr SRIO_Air_Unit::Air_Unit::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Air_Unit_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *SRIO_Air_Unit::Air_Unit::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == SRIO_Unit::General_Unit::iluGetILUClassRecord()) 
      return (REINTERPRET_CAST(void *, STATIC_CAST(SRIO_Unit::General_Unit_ptr, this)));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void SRIO_Air_Unit::Air_Unit::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "IDL:SRIO_Unit/General_Unit:1.0"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "SRIO_Air_Unit.Air-Unit"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "IDL:SRIO_Air_Unit/Air_Unit:1.0"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_TRUE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      38,          // number of methods
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
                     CONST_CAST(iluCString,"IDL:SRIO_Air_Unit/Air_Unit/Speed3D:1.0") // return type ID
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
                     CONST_CAST(iluCString,"IDL:SRIO_Air_Unit/Air_Unit/Pose3D:1.0") // return type ID
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
                     CONST_CAST(iluCString,"IDL:SRIO_Air_Unit/Air_Unit/AirUnitInfo:1.0") // return type ID
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
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/MoveAction:1.0"));
    }  //end for method sendMoveAction

    {
     // for method sendGimbalSpeed

       iluException* sendGimbalSpeed_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     4,      // method index
                     CONST_CAST(iluCString, "sendGimbalSpeed"), // name
                     5,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendGimbalSpeed_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "speed"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/GimbalSpeed:1.0"));
    }  //end for method sendGimbalSpeed

    {
     // for method resetGimbal

       iluException* resetGimbal_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     5,      // method index
                     CONST_CAST(iluCString, "resetGimbal"), // name
                     6,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     resetGimbal_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method resetGimbal

    {
     // for method sendMoveActionSequence

       iluException* sendMoveActionSequence_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     6,      // method index
                     CONST_CAST(iluCString, "sendMoveActionSequence"), // name
                     7,       //method ID
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
             CONST_CAST(iluCString, "ilut:jMVJ5BOiaU73NxUBLjsJREn228E"));
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
                     7,      // method index
                     CONST_CAST(iluCString, "sendVehicleInfo"), // name
                     8,       //method ID
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
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/AirUnitInfo:1.0"));
    }  //end for method sendVehicleInfo

    {
     // for method setRearVehicles

       iluException* setRearVehicles_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     8,      // method index
                     CONST_CAST(iluCString, "setRearVehicles"), // name
                     9,       //method ID
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
                     9,      // method index
                     CONST_CAST(iluCString, "setFormation"), // name
                     10,       //method ID
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
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Formation:1.0"));
    }  //end for method setFormation

    {
     // for method reportTrap

       iluException* reportTrap_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     10,      // method index
                     CONST_CAST(iluCString, "reportTrap"), // name
                     11,       //method ID
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
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/TrapPoint3D:1.0"));
    }  //end for method reportTrap

    {
     // for method clearTraps

       iluException* clearTraps_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     11,      // method index
                     CONST_CAST(iluCString, "clearTraps"), // name
                     12,       //method ID
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
                     12,      // method index
                     CONST_CAST(iluCString, "getTraps"), // name
                     13,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     getTraps_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:oJ79iYTP2pX76MF3a0rHKhDdAS-") // return type ID
        );
    }  //end for method getTraps

    {
     // for method setTrapPoint

       iluException* setTrapPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     13,      // method index
                     CONST_CAST(iluCString, "setTrapPoint"), // name
                     14,       //method ID
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
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/TrapPoint3D:1.0"));
    }  //end for method setTrapPoint

    {
     // for method setTrack

       iluException* setTrack_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     14,      // method index
                     CONST_CAST(iluCString, "setTrack"), // name
                     15,       //method ID
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
             CONST_CAST(iluCString, "ilut:fXgO5O12b3RECi10savMBsleNfh"));
    }  //end for method setTrack

    {
     // for method setTaskPath

       iluException* setTaskPath_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     15,      // method index
                     CONST_CAST(iluCString, "setTaskPath"), // name
                     16,       //method ID
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
             CONST_CAST(iluCString, "ilut:fXgO5O12b3RECi10savMBsleNfh"));
    }  //end for method setTaskPath

    {
     // for method setTaskPoint

       iluException* setTaskPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     16,      // method index
                     CONST_CAST(iluCString, "setTaskPoint"), // name
                     17,       //method ID
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
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Point3D:1.0"));
    }  //end for method setTaskPoint

    {
     // for method clearTaskPoint

       iluException* clearTaskPoint_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     17,      // method index
                     CONST_CAST(iluCString, "clearTaskPoint"), // name
                     18,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     clearTaskPoint_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method clearTaskPoint

    {
     // for method setFollower

       iluException* setFollower_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     18,      // method index
                     CONST_CAST(iluCString, "setFollower"), // name
                     19,       //method ID
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
                     19,      // method index
                     CONST_CAST(iluCString, "unsetFollower"), // name
                     20,       //method ID
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

    {
     // for method startPhotoStream

       iluException* startPhotoStream_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     20,      // method index
                     CONST_CAST(iluCString, "startPhotoStream"), // name
                     21,       //method ID
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
                     21,      // method index
                     CONST_CAST(iluCString, "stopPhotoStream"), // name
                     22,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     stopPhotoStream_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method stopPhotoStream

    {
     // for method obtainCtrlAuthority

       iluException* obtainCtrlAuthority_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     22,      // method index
                     CONST_CAST(iluCString, "obtainCtrlAuthority"), // name
                     23,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     obtainCtrlAuthority_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method obtainCtrlAuthority

    {
     // for method releaseCtrlAuthority

       iluException* releaseCtrlAuthority_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     23,      // method index
                     CONST_CAST(iluCString, "releaseCtrlAuthority"), // name
                     24,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     releaseCtrlAuthority_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method releaseCtrlAuthority

    {
     // for method setActionRole

       iluException* setActionRole_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     24,      // method index
                     CONST_CAST(iluCString, "setActionRole"), // name
                     25,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setActionRole_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "ar"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/ActionRole:1.0"));
    }  //end for method setActionRole

    {
     // for method setActionMode

       iluException* setActionMode_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     25,      // method index
                     CONST_CAST(iluCString, "setActionMode"), // name
                     26,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setActionMode_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "am"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/ActionMode:1.0"));
    }  //end for method setActionMode

    {
     // for method setCruiseScope

       iluException* setCruiseScope_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     26,      // method index
                     CONST_CAST(iluCString, "setCruiseScope"), // name
                     27,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setCruiseScope_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "s"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "IDL:SRIO_Air_Unit/Air_Unit/Site:1.0"));
    }  //end for method setCruiseScope

    {
     // for method sendControlledVehicle

       iluException* sendControlledVehicle_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     27,      // method index
                     CONST_CAST(iluCString, "sendControlledVehicle"), // name
                     28,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     sendControlledVehicle_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "uss"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:koGcvCzPGAj93X7FStZeh1dTy8R"));
    }  //end for method sendControlledVehicle

    {
     // for method confirmThrow

       iluException* confirmThrow_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     28,      // method index
                     CONST_CAST(iluCString, "confirmThrow"), // name
                     29,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     confirmThrow_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method confirmThrow

    {
     // for method cancelThrow

       iluException* cancelThrow_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     29,      // method index
                     CONST_CAST(iluCString, "cancelThrow"), // name
                     30,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     cancelThrow_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method cancelThrow

    {
     // for method actionThrow

       iluException* actionThrow_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     30,      // method index
                     CONST_CAST(iluCString, "actionThrow"), // name
                     31,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     actionThrow_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method actionThrow

    {
     // for method confirmFire

       iluException* confirmFire_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     31,      // method index
                     CONST_CAST(iluCString, "confirmFire"), // name
                     32,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     confirmFire_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method confirmFire

    {
     // for method cancelFire

       iluException* cancelFire_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     32,      // method index
                     CONST_CAST(iluCString, "cancelFire"), // name
                     33,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     cancelFire_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method cancelFire

    {
     // for method confirmFireLocation

       iluException* confirmFireLocation_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     33,      // method index
                     CONST_CAST(iluCString, "confirmFireLocation"), // name
                     34,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     confirmFireLocation_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method confirmFireLocation

    {
     // for method cancelFireLocation

       iluException* cancelFireLocation_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     34,      // method index
                     CONST_CAST(iluCString, "cancelFireLocation"), // name
                     35,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     cancelFireLocation_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method cancelFireLocation

    {
     // for method controlVehicleVelocity

       iluException* controlVehicleVelocity_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     35,      // method index
                     CONST_CAST(iluCString, "controlVehicleVelocity"), // name
                     36,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     controlVehicleVelocity_exception_array,
                     4,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "vx"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "vy"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "vz"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
        iluCppInternal::iluDefineMethodArg (a_method, 3,
             CONST_CAST(iluCString, "angle"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
    }  //end for method controlVehicleVelocity

    {
     // for method backHome

       iluException* backHome_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     36,      // method index
                     CONST_CAST(iluCString, "backHome"), // name
                     37,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     backHome_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
    }  //end for method backHome

    {
     // for method setCruiseSpeed

       iluException* setCruiseSpeed_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     37,      // method index
                     CONST_CAST(iluCString, "setCruiseSpeed"), // name
                     38,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     setCruiseSpeed_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "cs"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"));
    }  //end for method setCruiseSpeed

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  SRIO_Air_Unit::Air_Unit typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit)::iluDeleteValue (void* pv_value) {
                SRIO_Air_Unit::Air_Unit_ptr p_thevalue = (SRIO_Air_Unit::Air_Unit_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit)::iluDeepCopy (void* pv_value) {
                SRIO_Air_Unit::Air_Unit_ptr p_thevalue = (SRIO_Air_Unit::Air_Unit_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_(Boolean) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               SRIO_Air_Unit::Air_Unit_ptr p_thevalue = (SRIO_Air_Unit::Air_Unit_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           SRIO_Air_Unit::Air_Unit_ptr p_object = (SRIO_Air_Unit::Air_Unit_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If SRIO_Air_Unit::Air_Unit were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA::Object::iluGetILUClassRecord())
           //    return ((CORBA::Object_ptr)p_object);
           if (casttoclass == SRIO_Air_Unit::Air_Unit::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


//      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
//           SRIO_Air_Unit::Air_Unit_ptr p_object = (SRIO_Air_Unit::Air_Unit_ptr) p_an_object_of_your_type;
//           return CORBA::TypeCode::LookupTypeCode(p_object->iluClassId());
//      }

      CORBA_(TypeCode_ptr) ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit)::iluMostSpecificTypeCode(void* p_an_object_of_your_type) {
          if (!p_an_object_of_your_type) return nullptr;
          SRIO_Air_Unit::Air_Unit_ptr p_object = static_cast<SRIO_Air_Unit::Air_Unit_ptr>(p_an_object_of_your_type);
          return CORBA_(TypeCode)::LookupTypeCode(p_object->iluClassId());
      }



        // typecode instance for SRIO_Air_Unit::Air_Unit
        const CORBA_(TypeCode_ptr) SRIO_Air_Unit::tc_Air_Unit = new ILUCPP_TYPE_CODE_CLASS_NAME(SRIO_Air_Unit_Air_Unit);

      // define the Any insertion and extraction operators for SRIO_Air_Unit::Air_Unit

      void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(SRIO_Air_Unit::tc_Air_Unit, p_object, ILUCPP_TRUE);
      }

      CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit_ptr& r_p_object) {

          CORBA_(Any)* p_nc_any = CONST_CAST(CORBA_(Any)*, &r_any);

          if (p_nc_any->iluGetFromPickle(SRIO_Air_Unit::tc_Air_Unit)) { 
                 r_p_object = (SRIO_Air_Unit::Air_Unit_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }


////////////////////////////////////////////////////////////////
// Force initialization of SRIO_Air_Unit:: classes upon load

SRIO_Air_Unit::initializer SRIO_Air_Unit::initializer::sm_the_SRIO_Air_Unit_initializer;

SRIO_Air_Unit::initializer:: initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * SRIO_Air_Unit::initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(SRIO_Air_Unit::iluInitialize);
  return this;
}
