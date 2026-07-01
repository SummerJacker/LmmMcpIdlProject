
// This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056, Kestrel AI Institute Ltd, All Rights Reserved.
// KIS-CORBA information:  http://www.kestrelsystems.ca

#include "Test1-cpp.hpp"

//////////////////////////////////////////////////////////////////////
// globals & static members

  // exceptions vector
  static iluException interface_exceptions[] = {
          (iluException) 0,   //Test1_E1exception
          (iluException) 1,   //Test1_E2exception
          (iluException) 2,   //Test1_CantCreateexception
          (iluException) 3,   //Test1_E3exception
          (iluException) 4,   //Test1_E4exception
          (iluException) 5,   //Test1_E5exception
          (iluException) 6,   //Test1_E6exception
          (iluException) 7,   //Test1_E7exception
          (iluException) 8,   //Test1_E8exception
          (iluException) 9,   //Test1_E9exception
  };

  // list of initialization functions to call for the Test1_ interface
  iluInitializationFunctionNode* Test1_p_initialization_function_list;
  int Test1_g_i_initialized;

  // holds the ilu class record for Test1_O4 objects
  iluClass Test1_O4::m_ILUClassRecord;
  // holds the ilu class record for Test1_P objects
  iluClass Test1_P::m_ILUClassRecord;
  // holds the ilu class record for Test1_O3 objects
  iluClass Test1_O3::m_ILUClassRecord;
  // holds the ilu class record for Test1_TheO1 objects
  iluClass Test1_TheO1::m_ILUClassRecord;
  // holds the ilu class record for Test1_O2 objects
  iluClass Test1_O2::m_ILUClassRecord;

//////////////////////////////////////////////////////////////////////
// Test1 initialization

  void Test1_iluInitialize () {

      if ( Test1_g_i_initialized == 0) {  // haven't initialized before

      // grab global mutex for object type data structures
      iluMutexer mutex_on_object_type(iluCppInternal::sm_object_type_mutex);


       // define the exceptions in the Test1 interface
       interface_exceptions[g_Test1_E1_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E1"),
                 CONST_CAST(iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"));
       interface_exceptions[g_Test1_E2_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E2"),
                 CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
       interface_exceptions[g_Test1_CantCreate_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "CantCreate"),
                 REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR) 0)));
       interface_exceptions[g_Test1_E3_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E3"),
                 CONST_CAST(iluCString, "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2"));
       interface_exceptions[g_Test1_E4_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E4"),
                 CONST_CAST(iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"));
       interface_exceptions[g_Test1_E5_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E5"),
                 CONST_CAST(iluCString, "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r"));
       interface_exceptions[g_Test1_E6_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E6"),
                 CONST_CAST(iluCString, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac"));
       interface_exceptions[g_Test1_E7_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E7"),
                 CONST_CAST(iluCString, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"));
       interface_exceptions[g_Test1_E8_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E8"),
                 CONST_CAST(iluCString, "ilut:h3Dnvis94UwnmFURfYsCp700jVy"));
       interface_exceptions[g_Test1_E9_index] =
              iluCppInternal::iluDefineException(
                 CONST_CAST( iluCString, "Test1"),
                 CONST_CAST( iluCString, "E9"),
                 CONST_CAST(iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"));

       // performs object type initialization
        Test1_O4::iluInitialize();
        Test1_P::iluInitialize();
        Test1_O3::iluInitialize();
        Test1_TheO1::iluInitialize();
        Test1_O2::iluInitialize();

#ifdef IIOP_PROTOCOL
        {
        ILUCPP_BOOL b_new_registration;
                  iluType  a_type;

        iluCppInternal::iluRegisterOptionalType(
           CONST_CAST( iluCString, "TheOO"),
           CONST_CAST( iluCString, "Test1"),
           REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
           CONST_CAST( iluCString, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA"),
           CONST_CAST( iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"),  //  base type
             &b_new_registration);

        iluCppInternal::iluRegisterOptionalType(
           CONST_CAST( iluCString, "RO"),
           CONST_CAST( iluCString, "Test1"),
           REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
           CONST_CAST( iluCString, "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2"),
           CONST_CAST( iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"),  //  base type
             &b_new_registration);

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U-scard"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:jAPE1zV6LdNhqmjYERCpES3yBpF"),
             CONST_CAST( iluCString, "ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-R-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortcardinal_val = 0;
             constant_value.kind = ilu_shortcardinal_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "-One-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortcardinal_val = 1;
             constant_value.kind = ilu_shortcardinal_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U-card"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:nY7eVP682HUe0ogce3ooQPrruH2"),
             CONST_CAST( iluCString, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-R-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.cardinal_val = 0;
             constant_value.kind = ilu_cardinal_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "-O2-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.cardinal_val = 1;
             constant_value.kind = ilu_cardinal_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U-int"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:b8uuARf6GuBoeD-p8pOwYMjTZ69"),
             CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-R-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.integer_val = 0;
             constant_value.kind = ilu_integer_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "-O2-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.integer_val = 1;
             constant_value.kind = ilu_integer_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U-byte"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:eEo4ZOFawZcut8dv19+C65eQlWg"),
             CONST_CAST( iluCString, "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-R-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.byte_val = 0;
             constant_value.kind = ilu_byte_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "-O2-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.byte_val = 1;
             constant_value.kind = ilu_byte_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U4"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:iqhShhLIYYhlWJMKqapun2JReYg"),
             CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"),  // UID of discriminant type
              3,         // number of arms
              2,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "x1"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I"), // arm type
                  2  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 3;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             constant_value.value.shortinteger_val = 7;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 1, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "x2"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"), // arm type
                  0  // number of vals that can select this arm
              );


             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  2,   // which arm
                  CONST_CAST( iluCString, "x3"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy"), // arm type
                  2  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 1;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             constant_value.value.shortinteger_val = 0;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 1, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U3"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj"),
             CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),  // UID of discriminant type
              4,         // number of arms
              4,  // default arm (0 for none)
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
                  CONST_CAST( iluCString, "-U2-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9"), // arm type
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
                  CONST_CAST( iluCString, "v3"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.enumeration_val =
                 CONST_CAST( iluCString, "ev7");
             constant_value.kind = ilu_enumeration_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  3,   // which arm
                  CONST_CAST( iluCString, "v4"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2"), // arm type
                  0  // number of vals that can select this arm
              );

      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U2"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9"),
             CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"),  // UID of discriminant type
              3,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "x1"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I"), // arm type
                  2  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 3;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             constant_value.value.shortinteger_val = 7;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 1, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "x2"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"), // arm type
                  2  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 1;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             constant_value.value.shortinteger_val = 22;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 1, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  2,   // which arm
                  CONST_CAST( iluCString, "x3"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 2;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "U1"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:jzGuxkzcjrh34B-89hMcq2ovHB6"),
             CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"),  // UID of discriminant type
              2,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-R-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 0;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "-A1-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:h3Dnvis94UwnmFURfYsCp700jVy"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 1;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "TheU"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"),
             CONST_CAST( iluCString, "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ"),  // UID of discriminant type
              6,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_FALSE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-R-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 0;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  1,   // which arm
                  CONST_CAST( iluCString, "-RO-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 1;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  2,   // which arm
                  CONST_CAST( iluCString, "-CSS-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 2;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  3,   // which arm
                  CONST_CAST( iluCString, "-O1-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 3;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  4,   // which arm
                  CONST_CAST( iluCString, "-OO-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 4;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  5,   // which arm
                  CONST_CAST( iluCString, "-CORBA-Boolean-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.shortinteger_val = 5;
             constant_value.kind = ilu_shortinteger_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

        a_type = iluCppInternal::iluRegisterUnionType(
             CONST_CAST( iluCString, "OO2"),
             CONST_CAST( iluCString, "Test1"), 
             REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
             CONST_CAST( iluCString, "ilut:l-kEjRgqgSEZbJTDUfMwmrp5361"),
             CONST_CAST( iluCString, "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I"),  // UID of discriminant type
              1,         // number of arms
              0,  // default arm (0 for none)
              ILUCPP_TRUE,      // invalid discriminant values allowed?
             &b_new_registration);

        if (b_new_registration) {
             iluConstantValue_s constant_value;
             iluUnionArm union_arm;

             union_arm = iluCppInternal::iluRegisterUnionArm (a_type,
                  0,   // which arm
                  CONST_CAST( iluCString, "-O2-arm"),   // name of arm
                  CONST_CAST( iluCString,  "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"), // arm type
                  1  // number of vals that can select this arm
              );


             constant_value.value.boolean_val =
               STATIC_CAST(iluBoolean, ILUCPP_TRUE);
             constant_value.kind = ilu_boolean_cvk;
             iluCppInternal::iluRegisterUnionArmValue ( union_arm,
                 0, // which arm value
                 &constant_value // actual value
             );
      }

       { // array type "Test1_A2"
 
        iluCardinal _Test1_A2_dims[] = { 3, 4 };
 
        iluCppInternal::iluRegisterArrayType(
            CONST_CAST( iluCString, "A2"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:kM2HH51HMYTWu-khgczpbgNaama"),
            CONST_CAST( iluCString, "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO"), // base type of array
            2,           // number of dimensions
            _Test1_A2_dims, // actual dimensions
            &b_new_registration);
       }

       { // array type "Test1_TheA1"
 
        iluCardinal _Test1_TheA1_dims[] = { 3 };
 
        iluCppInternal::iluRegisterArrayType(
            CONST_CAST( iluCString, "TheA1"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:h3Dnvis94UwnmFURfYsCp700jVy"),
            CONST_CAST( iluCString, "ilut:iqqhSf395+BafbY8Oo2elFQD1bK"), // base type of array
            1,           // number of dimensions
            _Test1_TheA1_dims, // actual dimensions
            &b_new_registration);
       }

       { // array type "Test1_A0"
 
        iluCardinal _Test1_A0_dims[] = { 8 };
 
        iluCppInternal::iluRegisterArrayType(
            CONST_CAST( iluCString, "A0"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r"),
            CONST_CAST( iluCString, "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc"), // base type of array
            1,           // number of dimensions
            _Test1_A0_dims, // actual dimensions
            &b_new_registration);
       }

        a_type = iluCppInternal::iluRegisterRecordType(
            CONST_CAST( iluCString, "TheR"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)), 
            CONST_CAST( iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"),
            3, // number of fields in the record
            &b_new_registration);

        if (b_new_registration) {

            iluCppInternal::iluRegisterRecordField(a_type,
                0,     // which field
                CONST_CAST( iluCString, "a"),     // field name
                CONST_CAST( iluCString, "ilut:h3Dnvis94UwnmFURfYsCp700jVy") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                1,     // which field
                CONST_CAST( iluCString, "css"),     // field name
                CONST_CAST( iluCString, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy") // UID of field type
            );

            iluCppInternal::iluRegisterRecordField(a_type,
                2,     // which field
                CONST_CAST( iluCString, "i"),     // field name
                CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY") // UID of field type
            );
        }

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "O4"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ"),
            Test1_O4::iluGetILUClassRecord(), // object class
            &b_new_registration);

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "P"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:dY9O+Pbe716S3dZTXTUzbvfKs87"),
            Test1_P::iluGetILUClassRecord(), // object class
            &b_new_registration);

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "O3"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"),
            Test1_O3::iluGetILUClassRecord(), // object class
            &b_new_registration);

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "TheO1"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"),
            Test1_TheO1::iluGetILUClassRecord(), // object class
            &b_new_registration);

        iluCppInternal::iluRegisterObjectType(
            CONST_CAST( iluCString, "O2"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"),
            Test1_O2::iluGetILUClassRecord(), // object class
            &b_new_registration);

        a_type = iluCppInternal::iluRegisterEnumerationType(
            CONST_CAST( iluCString, "TheE"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),
            4,  // number of elements in the enum
            &b_new_registration);

        if (b_new_registration) {

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              0,        // which element
              CONST_CAST( iluCString, "ev1"),  // element name
              0       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              1,        // which element
              CONST_CAST( iluCString, "ev3"),  // element name
              3       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              2,        // which element
              CONST_CAST( iluCString, "ev5"),  // element name
              4       // integer value for element
        );

          iluCppInternal::iluRegisterEnumerationElement(a_type,
              3,        // which element
              CONST_CAST( iluCString, "ev7"),  // element name
              5       // integer value for element
        );
     }

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "One"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"),
            CONST_CAST( iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "E"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),
            CONST_CAST( iluCString, "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "U"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"),
            CONST_CAST( iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "OO"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA"),
            CONST_CAST( iluCString, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "O1"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"),
            CONST_CAST( iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "RS"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac"),
            CONST_CAST( iluCString, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "R"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"),
            CONST_CAST( iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "A1"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:h3Dnvis94UwnmFURfYsCp700jVy"),
            CONST_CAST( iluCString, "ilut:h3Dnvis94UwnmFURfYsCp700jVy"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "C"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx"),
            CONST_CAST( iluCString, "ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "SC"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0"),
            CONST_CAST( iluCString, "ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0"),  //  base type
            &b_new_registration);

        iluCppInternal::iluRegisterAliasType(
            CONST_CAST( iluCString, "I"),
            CONST_CAST( iluCString, "Test1"), 
            REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0)),
            CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"),
            CONST_CAST( iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"),  //  base type
            &b_new_registration);

       }
#endif  // IIOP_PROTOCOL 

   Test1_g_i_initialized = 1;
 }

 // call all the surrogate and true initialization functions
 iluCppInternal::iluCallInitializationFunctions(&Test1_p_initialization_function_list);

}



//////////////////////////////////////////////////////////////////////
//  Test1_O4_var sizing, input and output operators

// note following three operators only needed
// if Test1_O4 is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const Test1_O4_var& r_Test1_O4_var) {
         r_call += r_Test1_O4_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const Test1_O4_var& r_Test1_O4_var) {

      if (r_Test1_O4_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_Test1_O4_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_Test1_O4_var.iluSetWrapper(
           new iluObjectWrapper(
               r_Test1_O4_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_Test1_O4_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : Test1_O4::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_Test1_O4_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, Test1_O4_var& r_Test1_O4_var) {
	  
      Test1_O4_var temp_Test1_O4_var;
	  
     if (r_Test1_O4_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_Test1_O4_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_Test1_O4_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_Test1_O4_var = r_Test1_O4_var;

         // force a release since the var's in control of the refcount
         r_Test1_O4_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_Test1_O4_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, Test1_O4::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_Test1_O4_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_Test1_O4_var = (Test1_O4_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }



//////////////////////////////////////////////////////////////////////
//  Test1_P_var sizing, input and output operators

// note following three operators only needed
// if Test1_P is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const Test1_P_var& r_Test1_P_var) {
         r_call += r_Test1_P_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const Test1_P_var& r_Test1_P_var) {

      if (r_Test1_P_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_Test1_P_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_Test1_P_var.iluSetWrapper(
           new iluObjectWrapper(
               r_Test1_P_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_Test1_P_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : Test1_P::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_Test1_P_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, Test1_P_var& r_Test1_P_var) {
	  
      Test1_P_var temp_Test1_P_var;
	  
     if (r_Test1_P_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_Test1_P_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_Test1_P_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_Test1_P_var = r_Test1_P_var;

         // force a release since the var's in control of the refcount
         r_Test1_P_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_Test1_P_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, Test1_P::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_Test1_P_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_Test1_P_var = (Test1_P_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }



//////////////////////////////////////////////////////////////////////
//  Test1_O3_var sizing, input and output operators

// note following three operators only needed
// if Test1_O3 is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const Test1_O3_var& r_Test1_O3_var) {
         r_call += r_Test1_O3_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const Test1_O3_var& r_Test1_O3_var) {

      if (r_Test1_O3_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_Test1_O3_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_Test1_O3_var.iluSetWrapper(
           new iluObjectWrapper(
               r_Test1_O3_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_Test1_O3_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : Test1_O3::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_Test1_O3_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, Test1_O3_var& r_Test1_O3_var) {
	  
      Test1_O3_var temp_Test1_O3_var;
	  
     if (r_Test1_O3_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_Test1_O3_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_Test1_O3_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_Test1_O3_var = r_Test1_O3_var;

         // force a release since the var's in control of the refcount
         r_Test1_O3_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_Test1_O3_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, Test1_O3::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_Test1_O3_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_Test1_O3_var = (Test1_O3_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }



//////////////////////////////////////////////////////////////////////
//  Test1_TheO1_var sizing, input and output operators

// note following three operators only needed
// if Test1_TheO1 is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const Test1_TheO1_var& r_Test1_TheO1_var) {
         r_call += r_Test1_TheO1_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const Test1_TheO1_var& r_Test1_TheO1_var) {

      if (r_Test1_TheO1_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_Test1_TheO1_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_Test1_TheO1_var.iluSetWrapper(
           new iluObjectWrapper(
               r_Test1_TheO1_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_Test1_TheO1_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : Test1_TheO1::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_Test1_TheO1_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, Test1_TheO1_var& r_Test1_TheO1_var) {
	  
      Test1_TheO1_var temp_Test1_TheO1_var;
	  
     if (r_Test1_TheO1_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_Test1_TheO1_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_Test1_TheO1_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_Test1_TheO1_var = r_Test1_TheO1_var;

         // force a release since the var's in control of the refcount
         r_Test1_TheO1_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_Test1_TheO1_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, Test1_TheO1::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_Test1_TheO1_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_Test1_TheO1_var = (Test1_TheO1_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }



//////////////////////////////////////////////////////////////////////
//  Test1_O2_var sizing, input and output operators

// note following three operators only needed
// if Test1_O2 is member of a structured type

 iluBaseCall& operator+=(iluBaseCall& r_call, const Test1_O2_var& r_Test1_O2_var) {
         r_call += r_Test1_O2_var.iluGetObjectPointer();
         return r_call;
  }

 iluBaseCall& operator<<(iluBaseCall& r_call, const Test1_O2_var& r_Test1_O2_var) {

      if (r_Test1_O2_var.iluGetWrapper() != NULL) { // must be a true side inout
          r_Test1_O2_var.iluDeleteWrapper();
      }

      // make a new wrapper for the object
      r_Test1_O2_var.iluSetWrapper(
           new iluObjectWrapper(
               r_Test1_O2_var.iluGetObjectPointer(),
               ILUCPP_FALSE, 
               (r_Test1_O2_var.iluGetObjectPointer() ?
                           ILUCPP_NULL : Test1_O2::iluGetILUClassRecord())));

      // output the object from the wrapper
      iluObjectWrapper* p_wrapper = r_Test1_O2_var.iluGetWrapper();
      r_call << *p_wrapper;

      // ensure _var is in control
      p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;
 
     return r_call;
  }

 iluBaseCall& operator>>(iluBaseCall& r_call, Test1_O2_var& r_Test1_O2_var) {
	  
      Test1_O2_var temp_Test1_O2_var;
	  
     if (r_Test1_O2_var.iluGetWrapper() != ILUCPP_NULL) { // must be a surrogate side inout
         r_Test1_O2_var.iluDeleteWrapper();

         // we assign a temporary var to what the argument var is to handle the
         // case where the client put a 'true' object with a single refcount
         // into the inout var, and the server did not modify it.  If we didn't
         // do this temporary assignment, then we would end up destructing the 
         // object, and then try reading in a reference to the object that was
         // was just destroyed.  Note that the destructor for temp_Test1_O2_var will
         // be invoked when we leave the scope of this function, releasing the
         // extra count we had to keep the object in existence for this brief period.
         temp_Test1_O2_var = r_Test1_O2_var;

         // force a release since the var's in control of the refcount
         r_Test1_O2_var = ILUCPP_NULL;
     }
	  
     // make up a new wrapper
     r_Test1_O2_var.iluSetWrapper
          (new iluObjectWrapper(ILUCPP_FALSE, Test1_O2::iluGetILUClassRecord()));
	  
         // read the object into a wrapper
         iluObjectWrapper* p_wrapper = r_Test1_O2_var.iluGetWrapper();
         r_call >> *p_wrapper;
	  
         // give the _var control of it
         r_Test1_O2_var = (Test1_O2_ptr)(p_wrapper->m_pv_iluobject);
         p_wrapper->m_b_do_refcount_decrement = ILUCPP_FALSE;

         return r_call;
 }


  // define the member functions in typecode class for Test1_TheE
  ILUCPP_DEFINE_ILU_TYPE_CODE_ENUM_MEMBERFUNCTIONS(
            Test1_TheE, Test1_TheE)

  // typecode instance for Test1_TheE
  const CORBA_TypeCode_ptr Test1_tc_TheE =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheE);

  // define the Any insertion and extraction operators for Test1_TheE
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
           Test1_TheE, Test1_tc_TheE)
  ILUCPP_DEFINE_REF_EXTRACTION_OPERATOR(
           Test1_TheE, Test1_tc_TheE)


/////////////////////////////////////////////////////////////////////
//  Test1_TheR members

/* Can leave out - and would then allow aggregate inits */
// default constructor
   Test1_TheR::Test1_TheR() {
  }

  // copy constructor
  Test1_TheR::Test1_TheR(const Test1_TheR& r_a_TheR) {
          Test1_TheA1_copy(a, r_a_TheR.a);
          css = r_a_TheR.css;
          i = r_a_TheR.i;
   }

  // destructor
  Test1_TheR::~Test1_TheR() {
  }

  //possibly sunpro-specific workaround 
  Test1_TheR& Test1_TheR::self(){
        return *this;
  }

  // assignment operator
  Test1_TheR& Test1_TheR::operator=(
       const Test1_TheR& r_a_TheR) {
          if (this != &r_a_TheR) {
          Test1_TheA1_copy(a, r_a_TheR.a);
          css = r_a_TheR.css;
          i = r_a_TheR.i;
          }
          return *this;
  }
/* end of omissible*/

  // insertion, extraction, and sizing operators for Test1_TheR

    iluBaseCall& operator+=(iluBaseCall& r_call,
         const Test1_TheR& r_Test1_TheR)  {

         r_call += iluSizeRecord;
        Test1_size_const_TheA1(r_call, r_Test1_TheR.a);
          r_call += r_Test1_TheR.css;
          r_call +=  r_Test1_TheR.i;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator<<(iluBaseCall& r_call,
         const Test1_TheR& r_Test1_TheR)  {

         r_call << iluOutputRecord;
        Test1_output_const_TheA1(r_call, r_Test1_TheR.a);
          r_call << r_Test1_TheR.css;
          r_call <<  r_Test1_TheR.i;

         r_call << iluEndRecord;
         return r_call;
 }

    iluBaseCall& operator>>(iluBaseCall& r_call,
          Test1_TheR& r_Test1_TheR)  {

         r_call >> iluInputRecord;
        Test1_input_TheA1(r_call, r_Test1_TheR.a);
          r_call >> r_Test1_TheR.css;
          r_call >>  r_Test1_TheR.i;

         r_call >> iluEndRecord;
         return r_call;
 }

  // define the member fns in typecode class for Test1_TheR
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_TheR, Test1_TheR)

  // typecode instance for Test1_TheR
  const CORBA_TypeCode_ptr Test1_tc_TheR =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheR);

  // define the Any insert and extract operators for Test1_TheR 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_TheR, Test1_tc_TheR)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_TheR, Test1_tc_TheR)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_TheR, Test1_tc_TheR)
  
 //////////////////////////////////////////////////////////////////////
 // Test1_A2_var array member funs and allocation utility functions

  Test1_A2_slice* Test1_A2_alloc (){

/* xxx temp debugging only 
       Test1_A2_slice* p_slice =
              (Test1_A2_slice*)(new CORBA_ULong[3][4]);
       CORBA_ULong* p_element = (CORBA_ULong*) p_slice;	
       for (CORBA_Long) count = 0; count < 3 * 4; count++)
               *p_element++ = ~count;
       return (p_slice);
end xxx temp debugging only */

       return ((Test1_A2_slice*) (new CORBA_ULong[3][4]));
   }


  void Test1_A2_free(
       Test1_A2_slice* p_Test1_A2_slice) {
       delete [] p_Test1_A2_slice;
  }
  
  // duplicate a Test1_A2
  Test1_A2_slice* Test1_A2_dup(
      const Test1_A2_slice* p_Test1_A2_slice) {

       if (!p_Test1_A2_slice)
          return ILUCPP_NULL;
       else {
           Test1_A2_slice* p_slice = Test1_A2_alloc();
           CORBA_ULong* p_this_element = (CORBA_ULong*) p_slice;
           CORBA_ULong* p_that_element =
                           (CORBA_ULong*) p_Test1_A2_slice;
           for (CORBA_Long count = 0; count < 3 * 4; count++)
              *p_this_element++ = *p_that_element++;
           return p_slice;
       }
  }
  
  // copy a Test1_A2
  void Test1_A2_copy(
       Test1_A2_slice*       p_to_Test1_A2_slice,
       const Test1_A2_slice* p_from_Test1_A2_slice) {
       if (   (!p_from_Test1_A2_slice)
           || (!p_to_Test1_A2_slice)) return;
       else {
           CORBA_ULong* p_this_element =
                     (CORBA_ULong*) p_to_Test1_A2_slice;
           CORBA_ULong* p_that_element =
                     (CORBA_ULong*) p_from_Test1_A2_slice;
           for (CORBA_Long count = 0; count < 3 * 4; count++)
              *p_this_element++ = *p_that_element++;
       }
  }
 
  // insertion, extraction, and sizing functions for Test1_A2

  iluBaseCall& Test1_size_const_A2(
         iluBaseCall& r_call,
          const CORBA_ULong a_Test1_A2[][4]) {


          r_call.iluSizeArray(3 * 4);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
             for (iluCardinal index1 = 0; index1 < 4; index1++) {
                  r_call +=  a_Test1_A2 [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_size_A2(
         iluBaseCall& r_call,
           CORBA_ULong a_Test1_A2[][4]) {


          r_call.iluSizeArray(3 * 4);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
             for (iluCardinal index1 = 0; index1 < 4; index1++) {
                  r_call +=  a_Test1_A2 [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_output_const_A2(
         iluBaseCall& r_call,
          const CORBA_ULong a_Test1_A2[][4]) {


          r_call.iluOutputArray(3 * 4);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
             for (iluCardinal index1 = 0; index1 < 4; index1++) {
                  r_call <<  a_Test1_A2 [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_output_A2(
         iluBaseCall& r_call,
           CORBA_ULong a_Test1_A2[][4]) {


          r_call.iluOutputArray(3 * 4);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
             for (iluCardinal index1 = 0; index1 < 4; index1++) {
                  r_call <<  a_Test1_A2 [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_input_A2(
         iluBaseCall& r_call,
           CORBA_ULong a_Test1_A2[][4]) {


         r_call >> iluInputArray;
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
             for (iluCardinal index1 = 0; index1 < 4; index1++) {
                  r_call >>  a_Test1_A2 [index0][index1];
             }
          }
         r_call << iluEndArray;
         return r_call;
  }


 // define the four member functions in typecode class for Test1_A2
  ILUCPP_DEFINE_ILU_TYPE_CODE_ARRAY_MEMBERFUNCTIONS(Test1_A2, 
       Test1_A2_slice, Test1_A2_alloc, Test1_A2_dup,
       Test1_size_A2, Test1_output_A2, Test1_input_A2)

  // typecode instance for Test1_A2
  const CORBA_TypeCode_ptr Test1_tc_A2 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_A2);

 // define the Any insertion and extraction operators for Test1_A2_forany
  ILUCPP_DEFINE_ARRAY_INSERTION_OPERATOR(Test1_A2_slice, Test1_A2_forany,
        Test1_tc_A2, Test1_A2_dup)
  ILUCPP_DEFINE_ARRAY_EXTRACTION_OPERATOR(Test1_A2_forany,
         Test1_tc_A2,  Test1_A2_slice)
  
 //////////////////////////////////////////////////////////////////////
 // Test1_TheA1_var array member funs and allocation utility functions

  Test1_TheA1_slice* Test1_TheA1_alloc (){

/* xxx temp debugging only 
       Test1_TheA1_slice* p_slice =
              (Test1_TheA1_slice*)(new CORBA_String_var[3]);
       CORBA_String_var* p_element = (CORBA_String_var*) p_slice;	
       for (CORBA_Long) count = 0; count < 3; count++)
               *p_element++ = ~count;
       return (p_slice);
end xxx temp debugging only */

       return ((Test1_TheA1_slice*) (new CORBA_String_var[3]));
   }


  void Test1_TheA1_free(
       Test1_TheA1_slice* p_Test1_TheA1_slice) {
       delete [] p_Test1_TheA1_slice;
  }
  
  // duplicate a Test1_TheA1
  Test1_TheA1_slice* Test1_TheA1_dup(
      const Test1_TheA1_slice* p_Test1_TheA1_slice) {

       if (!p_Test1_TheA1_slice)
          return ILUCPP_NULL;
       else {
           Test1_TheA1_slice* p_slice = Test1_TheA1_alloc();
           CORBA_String_var* p_this_element = (CORBA_String_var*) p_slice;
           CORBA_String_var* p_that_element =
                           (CORBA_String_var*) p_Test1_TheA1_slice;
           for (CORBA_Long count = 0; count < 3; count++)
              *p_this_element++ = *p_that_element++;
           return p_slice;
       }
  }
  
  // copy a Test1_TheA1
  void Test1_TheA1_copy(
       Test1_TheA1_slice*       p_to_Test1_TheA1_slice,
       const Test1_TheA1_slice* p_from_Test1_TheA1_slice) {
       if (   (!p_from_Test1_TheA1_slice)
           || (!p_to_Test1_TheA1_slice)) return;
       else {
           CORBA_String_var* p_this_element =
                     (CORBA_String_var*) p_to_Test1_TheA1_slice;
           CORBA_String_var* p_that_element =
                     (CORBA_String_var*) p_from_Test1_TheA1_slice;
           for (CORBA_Long count = 0; count < 3; count++)
              *p_this_element++ = *p_that_element++;
       }
  }
 
  // insertion, extraction, and sizing functions for Test1_TheA1

  iluBaseCall& Test1_size_const_TheA1(
         iluBaseCall& r_call,
          const CORBA_String_var a_Test1_TheA1[]) {


          r_call.iluSizeArray(3);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
         iluCardinal a_element_length =
            strlen(a_Test1_TheA1[index0].iluStringVarReference());
         iluCStringWrapper a_element(a_Test1_TheA1 [index0]
             .iluStringVarReference(), a_element_length);
               r_call += a_element;
 
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_size_TheA1(
         iluBaseCall& r_call,
           CORBA_String_var a_Test1_TheA1[]) {


          r_call.iluSizeArray(3);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
         iluCardinal a_element_length =
            strlen(a_Test1_TheA1[index0].iluStringVarReference());
         iluCStringWrapper a_element(a_Test1_TheA1 [index0]
             .iluStringVarReference(), a_element_length);
               r_call += a_element;
 
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_output_const_TheA1(
         iluBaseCall& r_call,
          const CORBA_String_var a_Test1_TheA1[]) {


          r_call.iluOutputArray(3);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
         iluCardinal a_element_length =
            strlen(a_Test1_TheA1[index0].iluStringVarReference());
         iluCStringWrapper a_element(a_Test1_TheA1 [index0]
             .iluStringVarReference(), a_element_length);
               r_call << a_element;
 
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_output_TheA1(
         iluBaseCall& r_call,
           CORBA_String_var a_Test1_TheA1[]) {


          r_call.iluOutputArray(3);
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
         iluCardinal a_element_length =
            strlen(a_Test1_TheA1[index0].iluStringVarReference());
         iluCStringWrapper a_element(a_Test1_TheA1 [index0]
             .iluStringVarReference(), a_element_length);
               r_call << a_element;
 
          }
         r_call << iluEndArray;
         return r_call;
  }


  iluBaseCall& Test1_input_TheA1(
         iluBaseCall& r_call,
           CORBA_String_var a_Test1_TheA1[]) {


         r_call >> iluInputArray;
          for (iluCardinal index0 = 0; index0 < 3; index0++) {
         iluCardinal a_element_length;
         iluCStringWrapper a_element(a_Test1_TheA1 [index0]
             .iluStringVarReference(), a_element_length);
               r_call >> a_element;
 
          }
         r_call << iluEndArray;
         return r_call;
  }


 // define the four member functions in typecode class for Test1_TheA1
  ILUCPP_DEFINE_ILU_TYPE_CODE_ARRAY_MEMBERFUNCTIONS(Test1_TheA1, 
       Test1_TheA1_slice, Test1_TheA1_alloc, Test1_TheA1_dup,
       Test1_size_TheA1, Test1_output_TheA1, Test1_input_TheA1)

  // typecode instance for Test1_TheA1
  const CORBA_TypeCode_ptr Test1_tc_TheA1 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheA1);

 // define the Any insertion and extraction operators for Test1_TheA1_forany
  ILUCPP_DEFINE_ARRAY_INSERTION_OPERATOR(Test1_TheA1_slice, Test1_TheA1_forany,
        Test1_tc_TheA1, Test1_TheA1_dup)
  ILUCPP_DEFINE_ARRAY_EXTRACTION_OPERATOR(Test1_TheA1_forany,
         Test1_tc_TheA1,  Test1_TheA1_slice)
  
 //////////////////////////////////////////////////////////////////////
 // Test1_A0_var array member funs and allocation utility functions

  Test1_A0_slice* Test1_A0_alloc (){

/* xxx temp debugging only 
       Test1_A0_slice* p_slice =
              (Test1_A0_slice*)(new CORBA_Octet[8]);
       CORBA_Octet* p_element = (CORBA_Octet*) p_slice;	
       for (CORBA_Long) count = 0; count < 8; count++)
               *p_element++ = ~count;
       return (p_slice);
end xxx temp debugging only */

       return ((Test1_A0_slice*) (new CORBA_Octet[8]));
   }


  void Test1_A0_free(
       Test1_A0_slice* p_Test1_A0_slice) {
       delete [] p_Test1_A0_slice;
  }
  
  // duplicate a Test1_A0
  Test1_A0_slice* Test1_A0_dup(
      const Test1_A0_slice* p_Test1_A0_slice) {

       if (!p_Test1_A0_slice)
          return ILUCPP_NULL;
       else {
           Test1_A0_slice* p_slice = Test1_A0_alloc();
           CORBA_Octet* p_this_element = (CORBA_Octet*) p_slice;
           CORBA_Octet* p_that_element =
                           (CORBA_Octet*) p_Test1_A0_slice;
           for (CORBA_Long count = 0; count < 8; count++)
              *p_this_element++ = *p_that_element++;
           return p_slice;
       }
  }
  
  // copy a Test1_A0
  void Test1_A0_copy(
       Test1_A0_slice*       p_to_Test1_A0_slice,
       const Test1_A0_slice* p_from_Test1_A0_slice) {
       if (   (!p_from_Test1_A0_slice)
           || (!p_to_Test1_A0_slice)) return;
       else {
           CORBA_Octet* p_this_element =
                     (CORBA_Octet*) p_to_Test1_A0_slice;
           CORBA_Octet* p_that_element =
                     (CORBA_Octet*) p_from_Test1_A0_slice;
           for (CORBA_Long count = 0; count < 8; count++)
              *p_this_element++ = *p_that_element++;
       }
  }

  iluBaseCall& Test1_size_const_A0( iluBaseCall& r_call,
         const CORBA_Octet a_Test1_A0[]) {
             CORBA_Octet* _temp = 
                   (CORBA_Octet*) a_Test1_A0;
             iluOpaqueWrapper _array_wrapper(_temp, 8);
             r_call += _array_wrapper;
             return r_call;
   }
  iluBaseCall& Test1_size_A0( iluBaseCall& r_call,
         CORBA_Octet a_Test1_A0[]) {
             CORBA_Octet* _temp = 
                   (CORBA_Octet*) a_Test1_A0;
             iluOpaqueWrapper _array_wrapper(_temp, 8);
             r_call += _array_wrapper;
             return r_call;
   }
  iluBaseCall& Test1_output_A0( iluBaseCall& r_call,
         CORBA_Octet a_Test1_A0[]) {
             CORBA_Octet* _temp = 
                   (CORBA_Octet*) a_Test1_A0;
             iluOpaqueWrapper _array_wrapper(_temp, 8);
             r_call << _array_wrapper;
             return r_call;
   }
  iluBaseCall& Test1_output_const_A0( iluBaseCall& r_call,
         const CORBA_Octet a_Test1_A0[]) {
             CORBA_Octet* _temp = 
                   (CORBA_Octet*) a_Test1_A0;
             iluOpaqueWrapper _array_wrapper(_temp, 8);
             r_call << _array_wrapper;
             return r_call;
   }
  iluBaseCall& Test1_input_A0( iluBaseCall& r_call,
          CORBA_Octet a_Test1_A0[]) {
             CORBA_Octet* _temp = 
                   (CORBA_Octet*) a_Test1_A0;
             iluOpaqueWrapper _array_wrapper(_temp, 8);
             r_call >> _array_wrapper;
             return r_call;
   }


 // define the four member functions in typecode class for Test1_A0
  ILUCPP_DEFINE_ILU_TYPE_CODE_ARRAY_MEMBERFUNCTIONS(Test1_A0, 
       Test1_A0_slice, Test1_A0_alloc, Test1_A0_dup,
       Test1_size_A0, Test1_output_A0, Test1_input_A0)

  // typecode instance for Test1_A0
  const CORBA_TypeCode_ptr Test1_tc_A0 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_A0);

 // define the Any insertion and extraction operators for Test1_A0_forany
  ILUCPP_DEFINE_ARRAY_INSERTION_OPERATOR(Test1_A0_slice, Test1_A0_forany,
        Test1_tc_A0, Test1_A0_dup)
  ILUCPP_DEFINE_ARRAY_EXTRACTION_OPERATOR(Test1_A0_forany,
         Test1_tc_A0,  Test1_A0_slice)
  

 //////////////////////////////////////////////////////////////////////
 // Test1_TheRS members   

 // constructors & destructor
  Test1_TheRS::Test1_TheRS () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  Test1_TheRS::Test1_TheRS (CORBA_ULong max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  Test1_TheRS::Test1_TheRS (CORBA_ULong max , CORBA_ULong length, 
          Test1_TheR* data, CORBA_Boolean release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  Test1_TheRS::~Test1_TheRS() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  Test1_TheRS::Test1_TheRS (const Test1_TheRS& r_Test1_TheRS)
  :
         m_maximum(r_Test1_TheRS.m_maximum),
         m_length(r_Test1_TheRS.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_Test1_TheRS.m_buffer[index];
            }
   }

 // assignment
   Test1_TheRS& Test1_TheRS::operator= (const Test1_TheRS& r_Test1_TheRS) {
         if (this == &r_Test1_TheRS) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_Test1_TheRS.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_Test1_TheRS.m_length;
          for (CORBA_ULong index = 0; index < m_length; index++) {
              m_buffer[index] = r_Test1_TheRS.m_buffer[index];
          }
          return *this;
       }

  // memory management
  Test1_TheR* Test1_TheRS::allocbuf(CORBA_ULong num_elements) {
      return (num_elements > 0 ? (new Test1_TheR[num_elements]) : NULL);
  }
  
  void Test1_TheRS::freebuf(Test1_TheR* p_buf) {
        delete [] p_buf;
  }

  void Test1_TheRS::length (CORBA_ULong len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 Test1_TheR* p_oldbuf = m_buffer;
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
   CORBA_ULong Test1_TheRS::maximum() const {
        return m_maximum;
  }
  
  CORBA_ULong Test1_TheRS::length() const {
        return m_length;
  }  

  // [] operators
  Test1_TheR& Test1_TheRS::operator [] (CORBA_ULong index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const Test1_TheR& Test1_TheRS::operator [] (CORBA_ULong index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const Test1_TheR *_temp = 
              (const Test1_TheR *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  Test1_TheRS& Test1_TheRS::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for Test1_TheRS

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const Test1_TheRS& r_Test1_TheRS){

        iluCardinal card_length = r_Test1_TheRS.length();
        iluSequenceWrapper _r_Test1_TheRS(card_length);
        r_call += _r_Test1_TheRS;
        for (CORBA_ULong index = 0; index < r_Test1_TheRS.length(); index++) {
          r_call += r_Test1_TheRS[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const Test1_TheRS& r_Test1_TheRS){

        iluCardinal card_length = r_Test1_TheRS.length();
        iluSequenceWrapper _r_Test1_TheRS(card_length);
        r_call << _r_Test1_TheRS;
        for (CORBA_ULong index = 0; index < r_Test1_TheRS.length(); index++) {
          r_call << r_Test1_TheRS[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        Test1_TheRS& r_Test1_TheRS){

        CORBA_ULong card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        Test1_TheRS _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_ULong index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_Test1_TheRS = Test1_TheRS(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for Test1_TheRS
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_TheRS, Test1_TheRS)

  // typecode instance for Test1_TheRS
  const CORBA_TypeCode_ptr Test1_tc_TheRS =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheRS);

  // define the Any insert and extract operators for Test1_TheRS 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_TheRS, Test1_tc_TheRS)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_TheRS, Test1_tc_TheRS)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_TheRS, Test1_tc_TheRS)
  

 //////////////////////////////////////////////////////////////////////
 // Test1_BS members   

 // constructors & destructor
  Test1_BS::Test1_BS () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  Test1_BS::Test1_BS (CORBA_ULong max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  Test1_BS::Test1_BS (CORBA_ULong max , CORBA_ULong length, 
          CORBA_Octet* data, CORBA_Boolean release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  Test1_BS::~Test1_BS() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  Test1_BS::Test1_BS (const Test1_BS& r_Test1_BS)
  :
         m_maximum(r_Test1_BS.m_maximum),
         m_length(r_Test1_BS.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_Test1_BS.m_buffer[index];
            }
   }

 // assignment
   Test1_BS& Test1_BS::operator= (const Test1_BS& r_Test1_BS) {
         if (this == &r_Test1_BS) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_Test1_BS.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_Test1_BS.m_length;
          for (CORBA_ULong index = 0; index < m_length; index++) {
              m_buffer[index] = r_Test1_BS.m_buffer[index];
          }
          return *this;
       }

  // memory management
  CORBA_Octet* Test1_BS::allocbuf(CORBA_ULong num_elements) {
      return (num_elements > 0 ? (new CORBA_Octet[num_elements]) : NULL);
  }
  
  void Test1_BS::freebuf(CORBA_Octet* p_buf) {
        delete [] p_buf;
  }

  void Test1_BS::length (CORBA_ULong len) {
         if (len <= m_maximum)
               m_length = len;
          else {
                 CORBA_Octet* p_oldbuf = m_buffer;
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
   CORBA_ULong Test1_BS::maximum() const {
        return m_maximum;
  }
  
  CORBA_ULong Test1_BS::length() const {
        return m_length;
  }  

  // [] operators
  CORBA_Octet& Test1_BS::operator [] (CORBA_ULong index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const CORBA_Octet& Test1_BS::operator [] (CORBA_ULong index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const CORBA_Octet *_temp = 
              (const CORBA_Octet *) &m_buffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  Test1_BS& Test1_BS::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for Test1_BS

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const Test1_BS& r_Test1_BS){

        iluCardinal card_length = r_Test1_BS.length();
        iluSequenceWrapper _r_Test1_BS(card_length);
        r_call += _r_Test1_BS;
        for (CORBA_ULong index = 0; index < r_Test1_BS.length(); index++) {
          r_call += r_Test1_BS[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const Test1_BS& r_Test1_BS){

        iluCardinal card_length = r_Test1_BS.length();
        iluSequenceWrapper _r_Test1_BS(card_length);
        r_call << _r_Test1_BS;
        for (CORBA_ULong index = 0; index < r_Test1_BS.length(); index++) {
          r_call << r_Test1_BS[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        Test1_BS& r_Test1_BS){

        CORBA_ULong card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        Test1_BS _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_ULong index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_Test1_BS = Test1_BS(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for Test1_BS
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_BS, Test1_BS)

  // typecode instance for Test1_BS
  const CORBA_TypeCode_ptr Test1_tc_BS =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_BS);

  // define the Any insert and extract operators for Test1_BS 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_BS, Test1_tc_BS)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_BS, Test1_tc_BS)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_BS, Test1_tc_BS)
  

 //////////////////////////////////////////////////////////////////////
 // Test1_CSS members   

 // constructors & destructor
  Test1_CSS::Test1_CSS () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  Test1_CSS::Test1_CSS (CORBA_ULong max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE) {
             m_buffer = allocbuf (m_maximum);
             m_varbuffer = new CORBA_String_var[m_maximum];
  }

  Test1_CSS::Test1_CSS (CORBA_ULong max , CORBA_ULong length, 
        iluShortCharacter** data, CORBA_Boolean release)  : m_maximum(max),
        m_length(length),
        m_release (release), 
        m_buffer(data) {

        m_varbuffer = new CORBA_String_var[max];
        for (CORBA_ULong index = 0; index < max; index++) {
            (m_varbuffer[index]).iluSetRelease(m_release);
             m_varbuffer[index] = (data[index]);
        }	  
  }

  Test1_CSS::Test1_CSS (const Test1_CSS& r_Test1_CSS)   :
         m_maximum(r_Test1_CSS.m_maximum), 
         m_length(r_Test1_CSS.m_length), 
         m_release(ILUCPP_TRUE) 
         {
            m_buffer = allocbuf (m_maximum);
            m_varbuffer = new CORBA_String_var[m_length];
            for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_Test1_CSS.m_buffer[index];
               m_varbuffer[index] = r_Test1_CSS.m_varbuffer[index];
            } 
   }
		
  Test1_CSS::~Test1_CSS() {
        if (m_buffer && m_release)
           freebuf (m_buffer);
        if(m_length > 0)
           delete [] m_varbuffer;
  }

 // assignment
   Test1_CSS& Test1_CSS::operator= (const Test1_CSS& r_Test1_CSS) {
         if (this == &r_Test1_CSS) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         if (m_length > 0)  
              delete [] m_varbuffer;
          m_buffer = allocbuf (r_Test1_CSS.m_maximum);
        m_varbuffer = new CORBA_String_var[r_Test1_CSS.m_length];

#if (defined(OLDGNUC_WORKAROUND) || defined (_MSC_VER))
         // for some reason GNUC does not allow m_length set before copy
         // and/or doesn't allow m_length to govern iteration 
        // experimentally moved  then should consolidate 
         // and check if also solves object version of problem
          for (CORBA_ULong index = 0; index < r_Test1_CSS.m_length;
              index++) {
               m_buffer[index] = r_Test1_CSS.m_buffer[index];
               m_varbuffer[index] = r_Test1_CSS.m_varbuffer[index];
       }
          m_release = ILUCPP_TRUE;
          m_length = r_Test1_CSS.m_length;
          m_maximum = r_Test1_CSS.m_maximum;
#else
         m_release = ILUCPP_TRUE;
         m_length = r_Test1_CSS.m_length;
         m_maximum = r_Test1_CSS.m_maximum;
        for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_Test1_CSS.m_buffer[index];
               m_varbuffer[index] = r_Test1_CSS.m_varbuffer[index];
         } 
#endif
        return *this;
  }

  // memory management
  iluShortCharacter** Test1_CSS::allocbuf(CORBA_ULong num_elements) {
       if (num_elements > 0) {
          iluShortCharacter** p_new_buffer =
                new iluShortCharacter* [num_elements];
          for (CORBA_ULong ul_index = 0; ul_index < num_elements; ul_index++)
             p_new_buffer[ul_index] = *(new iluShortCharacter*);
          return p_new_buffer;
        }
        else return ILUCPP_NULL;
  }
  
  void Test1_CSS::freebuf(iluShortCharacter** p_buf) {
        delete [] p_buf;
  }

   void Test1_CSS::length (CORBA_ULong len) {
         if (len <= m_maximum) {
             for (CORBA_ULong index = len; index < m_length; index++) {
                 // attempt to NULL, not sure correct 
                 m_buffer[index] = *(new iluShortCharacter*);
             }
             m_length = len;
           }
          else {
                 iluShortCharacter** p_oldbuf = m_buffer;
                 CORBA_String_var* p_oldbufvar = m_varbuffer;

                 CORBA_ULong oldlen = m_length;
                 CORBA_Boolean b_oldrelease = m_release;
                 m_release = ILUCPP_TRUE;
                 m_length = len;
                 m_maximum = len;
                 m_buffer = allocbuf(m_length);
                 m_varbuffer = new CORBA_String_var[m_length];
                 for (CORBA_ULong index = 0; index < oldlen; index++) {
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
   CORBA_ULong Test1_CSS::maximum() const {
        return m_maximum;
  }
  
  CORBA_ULong Test1_CSS::length() const {
        return m_length;
  }  

  // [] operators
  CORBA_String_var& Test1_CSS::operator [] (CORBA_ULong index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
            throw (an_exception);
       }
      return m_varbuffer[index];
  }
  
  const CORBA_String_var& Test1_CSS::operator [] (CORBA_ULong index) const {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
          CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
          throw (an_exception);
       }
       // _temp added for SUNPRO 5.0 sequences,
       // cast for vc++ 
       const CORBA_String_var *_temp = 
              (const CORBA_String_var *) &m_varbuffer[index];
 
       return *_temp;
  }

  //possibly sunpro-specific workaround 
  Test1_CSS& Test1_CSS::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for Test1_CSS

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const Test1_CSS& r_Test1_CSS){

        iluCardinal card_length = r_Test1_CSS.length();
        iluSequenceWrapper _r_Test1_CSS(card_length);
        r_call += _r_Test1_CSS;
        for (CORBA_ULong index = 0; index < r_Test1_CSS.length(); index++) {
          iluCardinal s_element_length =
              strlen(r_Test1_CSS[index].iluStringVarReference());
          iluCStringWrapper  s_element(
            r_Test1_CSS[index].iluStringVarReference(), s_element_length);
          r_call += s_element; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const Test1_CSS& r_Test1_CSS){

        iluCardinal card_length = r_Test1_CSS.length();
        iluSequenceWrapper _r_Test1_CSS(card_length);
        r_call << _r_Test1_CSS;
        for (CORBA_ULong index = 0; index < r_Test1_CSS.length(); index++) {
          iluCardinal s_element_length =
              strlen(r_Test1_CSS[index].iluStringVarReference());
          iluCStringWrapper  s_element(
            r_Test1_CSS[index].iluStringVarReference(), s_element_length);
          r_call << s_element; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        Test1_CSS& r_Test1_CSS){

        CORBA_ULong card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        Test1_CSS _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_ULong index = 0; index < _seq_temp.length(); index++) {
          iluCardinal s_element_length;
          iluCStringWrapper  s_element(
            _seq_temp[index].iluStringVarReference(), s_element_length);
          r_call >> s_element; 
         }
        r_call >> iluEndSequence;
        r_Test1_CSS = Test1_CSS(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for Test1_CSS
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_CSS, Test1_CSS)

  // typecode instance for Test1_CSS
  const CORBA_TypeCode_ptr Test1_tc_CSS =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_CSS);

  // define the Any insert and extract operators for Test1_CSS 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_CSS, Test1_tc_CSS)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_CSS, Test1_tc_CSS)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_CSS, Test1_tc_CSS)
  

 //////////////////////////////////////////////////////////////////////
 // Test1_IS members   

 // constructors & destructor
  Test1_IS::Test1_IS () :
          m_maximum(0), 
	  m_length(0),
          m_release (ILUCPP_TRUE), 
          m_buffer(NULL)  
         {}

  Test1_IS::Test1_IS (CORBA_ULong max) :
          m_maximum(max),
          m_length(0),    /* zero if unbounded */
          m_release (ILUCPP_TRUE),
          m_buffer(allocbuf (max))
         {}
  
  Test1_IS::Test1_IS (CORBA_ULong max , CORBA_ULong length, 
          CORBA_Long* data, CORBA_Boolean release)  : m_maximum(max),
          m_length(length),
          m_release (release),
          m_buffer(data) {}

  Test1_IS::~Test1_IS() {
            if (m_buffer && m_release)
               freebuf (m_buffer);
  }

  Test1_IS::Test1_IS (const Test1_IS& r_Test1_IS)
  :
         m_maximum(r_Test1_IS.m_maximum),
         m_length(r_Test1_IS.m_length),
         m_release(ILUCPP_TRUE)
         {
            m_buffer = allocbuf (m_maximum);
            for (CORBA_ULong index = 0; index < m_length; index++) {
               m_buffer[index] = r_Test1_IS.m_buffer[index];
            }
   }

 // assignment
   Test1_IS& Test1_IS::operator= (const Test1_IS& r_Test1_IS) {
         if (this == &r_Test1_IS) 
             return *this;
         if (m_buffer && m_release)
              freebuf (m_buffer);
         m_maximum = r_Test1_IS.m_maximum;
         m_buffer = allocbuf (m_maximum);
         m_release = ILUCPP_TRUE;
         m_length = r_Test1_IS.m_length;
          for (CORBA_ULong index = 0; index < m_length; index++) {
              m_buffer[index] = r_Test1_IS.m_buffer[index];
          }
          return *this;
       }

  // memory management
  CORBA_Long* Test1_IS::allocbuf(CORBA_ULong num_elements) {
      return (num_elements > 0 ? (new CORBA_Long[num_elements]) : NULL);
  }
  
  void Test1_IS::freebuf(CORBA_Long* p_buf) {
        delete [] p_buf;
  }

  void Test1_IS::length (CORBA_ULong len) {
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
   CORBA_ULong Test1_IS::maximum() const {
        return m_maximum;
  }
  
  CORBA_ULong Test1_IS::length() const {
        return m_length;
  }  

  // [] operators
  CORBA_Long& Test1_IS::operator [] (CORBA_ULong index) {
       if (index >= m_length) {
       // really undefined by CORBA as to what to do,
       // but better safe than sorry!
           CORBA_UNKNOWN an_exception(0, CORBA_COMPLETED_NO);
            throw (an_exception);
       }
      return m_buffer[index];
  }
  
  const CORBA_Long& Test1_IS::operator [] (CORBA_ULong index) const {
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
  Test1_IS& Test1_IS::self(){
        return *this;
  }

  // insertion, extraction, and sizing operators for Test1_IS

  iluBaseCall& operator+=(iluBaseCall& r_call,
        const Test1_IS& r_Test1_IS){

        iluCardinal card_length = r_Test1_IS.length();
        iluSequenceWrapper _r_Test1_IS(card_length);
        r_call += _r_Test1_IS;
        for (CORBA_ULong index = 0; index < r_Test1_IS.length(); index++) {
          r_call += r_Test1_IS[index]; 
        }
        r_call += iluEndSequence;
        return r_call;
  }

  iluBaseCall& operator<<(iluBaseCall& r_call,
        const Test1_IS& r_Test1_IS){

        iluCardinal card_length = r_Test1_IS.length();
        iluSequenceWrapper _r_Test1_IS(card_length);
        r_call << _r_Test1_IS;
        for (CORBA_ULong index = 0; index < r_Test1_IS.length(); index++) {
          r_call << r_Test1_IS[index]; 
        }
        r_call << iluEndSequence;
        return r_call;
  }

    // use of seq_temp is workaround for possible sunpro problem 
  iluBaseCall& operator>>(iluBaseCall& r_call,
        Test1_IS& r_Test1_IS){

        CORBA_ULong card_length;
        iluSequenceWrapper _r_wrapper(card_length);
        r_call >> _r_wrapper;
        Test1_IS _seq_temp(card_length); // sets max
        _seq_temp.length(card_length);
        
        for (CORBA_ULong index = 0; index < _seq_temp.length(); index++) {
          r_call >> _seq_temp[index]; 
         }
        r_call >> iluEndSequence;
        r_Test1_IS = Test1_IS(_seq_temp); 
        return r_call;
  }

  // define the member fns in typecode class for Test1_IS
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_IS, Test1_IS)

  // typecode instance for Test1_IS
  const CORBA_TypeCode_ptr Test1_tc_IS =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_IS);

  // define the Any insert and extract operators for Test1_IS 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_IS, Test1_tc_IS)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_IS, Test1_tc_IS)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_IS, Test1_tc_IS)


  //////////////////////////////////////////////////////////////////////
  // Test1_U_scard members
		
  // constructors & destructor
  Test1_U_scard::Test1_U_scard() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U_scard::Test1_U_scard(const Test1_U_scard& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U_scard::~Test1_U_scard() {
	  unset();
  }

  // assignment
  Test1_U_scard& Test1_U_scard::operator=
          (const Test1_U_scard& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                   m__R_arm =
                      new Test1_R(*r_union_type.m__R_arm);
                   break;

                 // _One_arm
		  case 1:  
                   m__One_arm =
                      new Test1_One_var(*r_union_type.m__One_arm);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U_scard& Test1_U_scard::self(){
        return *this;
  }

  // discriminator access
  CORBA_UShort Test1_U_scard::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U_scard::_d (CORBA_UShort new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case 0: 
                       case 1: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _R_arm
		  case 0:  
                  switch(new_d) { 
                       case 0: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _One_arm
		  case 1:  
                  switch(new_d) { 
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
 
   // _R_arm access
    const Test1_TheR& Test1_U_scard::_R_arm() const {
           return( (const Test1_TheR&) *m__R_arm);
    }

    Test1_TheR& Test1_U_scard::_R_arm(){
           return( (Test1_TheR&) *m__R_arm);
    }

    void Test1_U_scard::_R_arm(const Test1_TheR & a__R_arm){
         unset();
         m_discriminator = 0;
         m__R_arm = new Test1_TheR(a__R_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _One_arm access
     Test1_TheO1_ptr Test1_U_scard::_One_arm() const {
       return (*m__One_arm);
    }
  
    void Test1_U_scard::_One_arm (Test1_TheO1_ptr a__One_arm) {
          unset();			
          m_discriminator = 1;
          // duplicate per corba spec
          Test1_TheO1::_duplicate(a__One_arm);
          m__One_arm = new Test1_One_var(a__One_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_U_scard::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
			  break;

                 // _One_arm
		  case 1:  
			  m__One_arm->iluDeleteWrapper();
			  break;
		  }
	  }
  }
		  
  void Test1_U_scard::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                     delete m__R_arm;
                     break;

                 // _One_arm
		  case 1:  
                     delete m__One_arm;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U_scard

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U_scard& r_Test1_U_scard) {

          iluUnionWrapper _r_Test1_U_scard(
                                r_Test1_U_scard._d(),
                                ilu_shortcardinal_tk);
          r_call += _r_Test1_U_scard;

          switch (r_Test1_U_scard.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call += (*r_Test1_U_scard.m__R_arm); 
                   break;

                 // _One_arm
		  case 1:  
                    r_call += (* (r_Test1_U_scard.m__One_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U_scard& r_Test1_U_scard) {

          iluUnionWrapper _r_Test1_U_scard(
                                r_Test1_U_scard._d(),
                                ilu_shortcardinal_tk);
          r_call << _r_Test1_U_scard;

          switch (r_Test1_U_scard.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call << (*r_Test1_U_scard.m__R_arm); 
                   break;

                 // _One_arm
		  case 1:  
                    r_call << (* (r_Test1_U_scard.m__One_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U_scard& r_Test1_U_scard) {
        
          iluUnionWrapper _r_Test1_U_scard(0, ilu_shortcardinal_tk);
        
          r_call >> _r_Test1_U_scard;

          switch (_r_Test1_U_scard.m_card_discriminator) {

                 // _R_arm
		  case 0:  
                 { Test1_R  _R_arm_temp;
                    r_call >> _R_arm_temp;
                    r_Test1_U_scard._R_arm(_R_arm_temp);
                    break;
                   }

                 // _One_arm
		  case 1:  
                 { Test1_One_var  _One_arm_temp;
                    r_call >> _One_arm_temp;
                    r_Test1_U_scard._One_arm(_One_arm_temp);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test1_U_scard._d((CORBA_UShort) (_r_Test1_U_scard.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U_scard
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U_scard, Test1_U_scard)

  // typecode instance for Test1_U_scard
  const CORBA_TypeCode_ptr Test1_tc_U_scard =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U_scard);

  // define the Any insert and extract operators for Test1_U_scard 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U_scard, Test1_tc_U_scard)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U_scard, Test1_tc_U_scard)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U_scard, Test1_tc_U_scard)


  //////////////////////////////////////////////////////////////////////
  // Test1_U_card members
		
  // constructors & destructor
  Test1_U_card::Test1_U_card() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U_card::Test1_U_card(const Test1_U_card& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U_card::~Test1_U_card() {
	  unset();
  }

  // assignment
  Test1_U_card& Test1_U_card::operator=
          (const Test1_U_card& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                   m__R_arm =
                      new Test1_R(*r_union_type.m__R_arm);
                   break;

                 // _O2_arm
		  case 1:  
                   m__O2_arm =
                      new Test1_O2_var(*r_union_type.m__O2_arm);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U_card& Test1_U_card::self(){
        return *this;
  }

  // discriminator access
  CORBA_ULong Test1_U_card::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U_card::_d (CORBA_ULong new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case 0: 
                       case 1: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _R_arm
		  case 0:  
                  switch(new_d) { 
                       case 0: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _O2_arm
		  case 1:  
                  switch(new_d) { 
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
 
   // _R_arm access
    const Test1_TheR& Test1_U_card::_R_arm() const {
           return( (const Test1_TheR&) *m__R_arm);
    }

    Test1_TheR& Test1_U_card::_R_arm(){
           return( (Test1_TheR&) *m__R_arm);
    }

    void Test1_U_card::_R_arm(const Test1_TheR & a__R_arm){
         unset();
         m_discriminator = 0;
         m__R_arm = new Test1_TheR(a__R_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _O2_arm access
     Test1_O2_ptr Test1_U_card::_O2_arm() const {
       return (*m__O2_arm);
    }
  
    void Test1_U_card::_O2_arm (Test1_O2_ptr a__O2_arm) {
          unset();			
          m_discriminator = 1;
          // duplicate per corba spec
          Test1_O2::_duplicate(a__O2_arm);
          m__O2_arm = new Test1_O2_var(a__O2_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_U_card::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
			  break;

                 // _O2_arm
		  case 1:  
			  m__O2_arm->iluDeleteWrapper();
			  break;
		  }
	  }
  }
		  
  void Test1_U_card::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                     delete m__R_arm;
                     break;

                 // _O2_arm
		  case 1:  
                     delete m__O2_arm;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U_card

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U_card& r_Test1_U_card) {

          iluUnionWrapper _r_Test1_U_card(
                                r_Test1_U_card._d(),
                                ilu_cardinal_tk);
          r_call += _r_Test1_U_card;

          switch (r_Test1_U_card.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call += (*r_Test1_U_card.m__R_arm); 
                   break;

                 // _O2_arm
		  case 1:  
                    r_call += (* (r_Test1_U_card.m__O2_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U_card& r_Test1_U_card) {

          iluUnionWrapper _r_Test1_U_card(
                                r_Test1_U_card._d(),
                                ilu_cardinal_tk);
          r_call << _r_Test1_U_card;

          switch (r_Test1_U_card.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call << (*r_Test1_U_card.m__R_arm); 
                   break;

                 // _O2_arm
		  case 1:  
                    r_call << (* (r_Test1_U_card.m__O2_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U_card& r_Test1_U_card) {
        
          iluUnionWrapper _r_Test1_U_card(0, ilu_cardinal_tk);
        
          r_call >> _r_Test1_U_card;

          switch (_r_Test1_U_card.m_card_discriminator) {

                 // _R_arm
		  case 0:  
                 { Test1_R  _R_arm_temp;
                    r_call >> _R_arm_temp;
                    r_Test1_U_card._R_arm(_R_arm_temp);
                    break;
                   }

                 // _O2_arm
		  case 1:  
                 { Test1_O2_var  _O2_arm_temp;
                    r_call >> _O2_arm_temp;
                    r_Test1_U_card._O2_arm(_O2_arm_temp);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test1_U_card._d((CORBA_ULong) (_r_Test1_U_card.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U_card
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U_card, Test1_U_card)

  // typecode instance for Test1_U_card
  const CORBA_TypeCode_ptr Test1_tc_U_card =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U_card);

  // define the Any insert and extract operators for Test1_U_card 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U_card, Test1_tc_U_card)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U_card, Test1_tc_U_card)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U_card, Test1_tc_U_card)


  //////////////////////////////////////////////////////////////////////
  // Test1_U_int members
		
  // constructors & destructor
  Test1_U_int::Test1_U_int() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U_int::Test1_U_int(const Test1_U_int& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U_int::~Test1_U_int() {
	  unset();
  }

  // assignment
  Test1_U_int& Test1_U_int::operator=
          (const Test1_U_int& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                   m__R_arm =
                      new Test1_R(*r_union_type.m__R_arm);
                   break;

                 // _O2_arm
		  case 1:  
                   m__O2_arm =
                      new Test1_O2_var(*r_union_type.m__O2_arm);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U_int& Test1_U_int::self(){
        return *this;
  }

  // discriminator access
  CORBA_Long Test1_U_int::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U_int::_d (CORBA_Long new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case 0: 
                       case 1: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _R_arm
		  case 0:  
                  switch(new_d) { 
                       case 0: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _O2_arm
		  case 1:  
                  switch(new_d) { 
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
 
   // _R_arm access
    const Test1_TheR& Test1_U_int::_R_arm() const {
           return( (const Test1_TheR&) *m__R_arm);
    }

    Test1_TheR& Test1_U_int::_R_arm(){
           return( (Test1_TheR&) *m__R_arm);
    }

    void Test1_U_int::_R_arm(const Test1_TheR & a__R_arm){
         unset();
         m_discriminator = 0;
         m__R_arm = new Test1_TheR(a__R_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _O2_arm access
     Test1_O2_ptr Test1_U_int::_O2_arm() const {
       return (*m__O2_arm);
    }
  
    void Test1_U_int::_O2_arm (Test1_O2_ptr a__O2_arm) {
          unset();			
          m_discriminator = 1;
          // duplicate per corba spec
          Test1_O2::_duplicate(a__O2_arm);
          m__O2_arm = new Test1_O2_var(a__O2_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_U_int::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
			  break;

                 // _O2_arm
		  case 1:  
			  m__O2_arm->iluDeleteWrapper();
			  break;
		  }
	  }
  }
		  
  void Test1_U_int::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                     delete m__R_arm;
                     break;

                 // _O2_arm
		  case 1:  
                     delete m__O2_arm;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U_int

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U_int& r_Test1_U_int) {

          iluUnionWrapper _r_Test1_U_int(
                                r_Test1_U_int._d(),
                                ilu_integer_tk);
          r_call += _r_Test1_U_int;

          switch (r_Test1_U_int.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call += (*r_Test1_U_int.m__R_arm); 
                   break;

                 // _O2_arm
		  case 1:  
                    r_call += (* (r_Test1_U_int.m__O2_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U_int& r_Test1_U_int) {

          iluUnionWrapper _r_Test1_U_int(
                                r_Test1_U_int._d(),
                                ilu_integer_tk);
          r_call << _r_Test1_U_int;

          switch (r_Test1_U_int.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call << (*r_Test1_U_int.m__R_arm); 
                   break;

                 // _O2_arm
		  case 1:  
                    r_call << (* (r_Test1_U_int.m__O2_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U_int& r_Test1_U_int) {
        
          iluUnionWrapper _r_Test1_U_int(0, ilu_integer_tk);
        
          r_call >> _r_Test1_U_int;

          switch (_r_Test1_U_int.m_card_discriminator) {

                 // _R_arm
		  case 0:  
                 { Test1_R  _R_arm_temp;
                    r_call >> _R_arm_temp;
                    r_Test1_U_int._R_arm(_R_arm_temp);
                    break;
                   }

                 // _O2_arm
		  case 1:  
                 { Test1_O2_var  _O2_arm_temp;
                    r_call >> _O2_arm_temp;
                    r_Test1_U_int._O2_arm(_O2_arm_temp);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test1_U_int._d((CORBA_Long) (_r_Test1_U_int.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U_int
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U_int, Test1_U_int)

  // typecode instance for Test1_U_int
  const CORBA_TypeCode_ptr Test1_tc_U_int =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U_int);

  // define the Any insert and extract operators for Test1_U_int 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U_int, Test1_tc_U_int)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U_int, Test1_tc_U_int)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U_int, Test1_tc_U_int)


  //////////////////////////////////////////////////////////////////////
  // Test1_U_byte members
		
  // constructors & destructor
  Test1_U_byte::Test1_U_byte() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U_byte::Test1_U_byte(const Test1_U_byte& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U_byte::~Test1_U_byte() {
	  unset();
  }

  // assignment
  Test1_U_byte& Test1_U_byte::operator=
          (const Test1_U_byte& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                   m__R_arm =
                      new Test1_R(*r_union_type.m__R_arm);
                   break;

                 // _O2_arm
		  case 1:  
                   m__O2_arm =
                      new Test1_O2_var(*r_union_type.m__O2_arm);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U_byte& Test1_U_byte::self(){
        return *this;
  }

  // discriminator access
  CORBA_Octet Test1_U_byte::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U_byte::_d (CORBA_Octet new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case 0: 
                       case 1: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _R_arm
		  case 0:  
                  switch(new_d) { 
                       case 0: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _O2_arm
		  case 1:  
                  switch(new_d) { 
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
 
   // _R_arm access
    const Test1_TheR& Test1_U_byte::_R_arm() const {
           return( (const Test1_TheR&) *m__R_arm);
    }

    Test1_TheR& Test1_U_byte::_R_arm(){
           return( (Test1_TheR&) *m__R_arm);
    }

    void Test1_U_byte::_R_arm(const Test1_TheR & a__R_arm){
         unset();
         m_discriminator = 0;
         m__R_arm = new Test1_TheR(a__R_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _O2_arm access
     Test1_O2_ptr Test1_U_byte::_O2_arm() const {
       return (*m__O2_arm);
    }
  
    void Test1_U_byte::_O2_arm (Test1_O2_ptr a__O2_arm) {
          unset();			
          m_discriminator = 1;
          // duplicate per corba spec
          Test1_O2::_duplicate(a__O2_arm);
          m__O2_arm = new Test1_O2_var(a__O2_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_U_byte::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
			  break;

                 // _O2_arm
		  case 1:  
			  m__O2_arm->iluDeleteWrapper();
			  break;
		  }
	  }
  }
		  
  void Test1_U_byte::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                     delete m__R_arm;
                     break;

                 // _O2_arm
		  case 1:  
                     delete m__O2_arm;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U_byte

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U_byte& r_Test1_U_byte) {

          iluUnionWrapper _r_Test1_U_byte(
                                r_Test1_U_byte._d(),
                                ilu_byte_tk);
          r_call += _r_Test1_U_byte;

          switch (r_Test1_U_byte.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call += (*r_Test1_U_byte.m__R_arm); 
                   break;

                 // _O2_arm
		  case 1:  
                    r_call += (* (r_Test1_U_byte.m__O2_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U_byte& r_Test1_U_byte) {

          iluUnionWrapper _r_Test1_U_byte(
                                r_Test1_U_byte._d(),
                                ilu_byte_tk);
          r_call << _r_Test1_U_byte;

          switch (r_Test1_U_byte.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call << (*r_Test1_U_byte.m__R_arm); 
                   break;

                 // _O2_arm
		  case 1:  
                    r_call << (* (r_Test1_U_byte.m__O2_arm));

                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U_byte& r_Test1_U_byte) {
        
          iluUnionWrapper _r_Test1_U_byte(0, ilu_byte_tk);
        
          r_call >> _r_Test1_U_byte;

          switch (_r_Test1_U_byte.m_card_discriminator) {

                 // _R_arm
		  case 0:  
                 { Test1_R  _R_arm_temp;
                    r_call >> _R_arm_temp;
                    r_Test1_U_byte._R_arm(_R_arm_temp);
                    break;
                   }

                 // _O2_arm
		  case 1:  
                 { Test1_O2_var  _O2_arm_temp;
                    r_call >> _O2_arm_temp;
                    r_Test1_U_byte._O2_arm(_O2_arm_temp);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test1_U_byte._d((CORBA_Octet) (_r_Test1_U_byte.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U_byte
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U_byte, Test1_U_byte)

  // typecode instance for Test1_U_byte
  const CORBA_TypeCode_ptr Test1_tc_U_byte =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U_byte);

  // define the Any insert and extract operators for Test1_U_byte 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U_byte, Test1_tc_U_byte)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U_byte, Test1_tc_U_byte)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U_byte, Test1_tc_U_byte)


  //////////////////////////////////////////////////////////////////////
  // Test1_U4 members
		
  // constructors & destructor
  Test1_U4::Test1_U4() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U4::Test1_U4(const Test1_U4& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U4::~Test1_U4() {
	  unset();
  }

  // assignment
  Test1_U4& Test1_U4::operator=
          (const Test1_U4& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  m_x1 = r_union_type.m_x1;
                  break;

                 // x2
                  default:
                   m_x2 =
                      new Test1_O2_var(*r_union_type.m_x2);
                   break;

                 // x3
		  case 1:  
		  case 0:  
                   m_x3 =
                      new Test1_CSS(*r_union_type.m_x3);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U4& Test1_U4::self(){
        return *this;
  }

  // discriminator access
  CORBA_Short Test1_U4::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U4::_d (CORBA_Short new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  switch(new_d) { 
                       case 3: 
                       case 7: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // x3
		  case 1:  
		  case 0:  
                  switch(new_d) { 
                       case 1: 
                       case 0: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case 3: 
                       case 7: 
                       case 1: 
                       case 0: 
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
 
   // x1 access
     CORBA_Boolean Test1_U4::x1 () const {
       return m_x1;
     }

     void Test1_U4::x1 (CORBA_Boolean a_x1) {
          unset();			
          m_discriminator = 3;
          m_x1 = a_x1;
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // x2 access
     Test1_O2_ptr Test1_U4::x2() const {
       return (*m_x2);
    }
  
    void Test1_U4::x2 (Test1_O2_ptr a_x2) {
          unset();			
          m_discriminator = 8;
          // duplicate per corba spec
          Test1_O2::_duplicate(a_x2);
          m_x2 = new Test1_O2_var(a_x2);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // x3 access
    const Test1_CSS& Test1_U4::x3() const {
           return( (const Test1_CSS&) *m_x3);
    }

    Test1_CSS& Test1_U4::x3(){
           return( (Test1_CSS&) *m_x3);
    }

    void Test1_U4::x3(const Test1_CSS & a_x3){
         unset();
         m_discriminator = 1;
         m_x3 = new Test1_CSS(a_x3);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_U4::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
			  break;

                 // x2
                  default:
			  m_x2->iluDeleteWrapper();
			  break;

                 // x3
		  case 1:  
		  case 0:  
			  break;
		  }
	  }
  }
		  
  void Test1_U4::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                     break;

                 // x2
                  default:
                     delete m_x2;
                     break;

                 // x3
		  case 1:  
		  case 0:  
                     delete m_x3;
                     break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U4

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U4& r_Test1_U4) {

          iluUnionWrapper _r_Test1_U4(
                                r_Test1_U4._d(),
                                ilu_shortinteger_tk);
          r_call += _r_Test1_U4;

          switch (r_Test1_U4.m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  { iluBoolWrapper _r_x1_wrap(
                    (ILUCPP_BOOL &) r_Test1_U4.m_x1);
                    r_call += _r_x1_wrap;
                  }
                   break;

                 // x2
                  default:
                    r_call += (* (r_Test1_U4.m_x2));

                   break;

                 // x3
		  case 1:  
		  case 0:  
                    r_call += (*r_Test1_U4.m_x3); 
                   break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U4& r_Test1_U4) {

          iluUnionWrapper _r_Test1_U4(
                                r_Test1_U4._d(),
                                ilu_shortinteger_tk);
          r_call << _r_Test1_U4;

          switch (r_Test1_U4.m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  { iluBoolWrapper _r_x1_wrap(
                    (ILUCPP_BOOL &) r_Test1_U4.m_x1);
                    r_call << _r_x1_wrap;
                  }
                   break;

                 // x2
                  default:
                    r_call << (* (r_Test1_U4.m_x2));

                   break;

                 // x3
		  case 1:  
		  case 0:  
                    r_call << (*r_Test1_U4.m_x3); 
                   break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U4& r_Test1_U4) {
        
          iluUnionWrapper _r_Test1_U4(0, ilu_shortinteger_tk);
        
          r_call >> _r_Test1_U4;

          switch (_r_Test1_U4.m_card_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                 { CORBA_Boolean  x1_temp;
                  iluBoolWrapper _r_x1_wrap(
                        (ILUCPP_BOOL &)  x1_temp);
                  r_call >> _r_x1_wrap;
                  r_Test1_U4.x1(x1_temp);
                    break;
                   }

                 // x2
                  default:
                 { Test1_O2_var  x2_temp;
                    r_call >> x2_temp;
                    r_Test1_U4.x2(x2_temp);
                    break;
                   }

                 // x3
		  case 1:  
		  case 0:  
                 { Test1_CSS  x3_temp;
                    r_call >> x3_temp;
                    r_Test1_U4.x3(x3_temp);
                    break;
                   }

          };

          r_call >> iluEndUnion;
          r_Test1_U4._d((CORBA_Short) (_r_Test1_U4.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U4
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U4, Test1_U4)

  // typecode instance for Test1_U4
  const CORBA_TypeCode_ptr Test1_tc_U4 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U4);

  // define the Any insert and extract operators for Test1_U4 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U4, Test1_tc_U4)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U4, Test1_tc_U4)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U4, Test1_tc_U4)


  //////////////////////////////////////////////////////////////////////
  // Test1_U3 members
		
  // constructors & destructor
  Test1_U3::Test1_U3() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U3::Test1_U3(const Test1_U3& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U3::~Test1_U3() {
	  unset();
  }

  // assignment
  Test1_U3& Test1_U3::operator=
          (const Test1_U3& r_union_type) {

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

                 // _U2_arm
		  case Test1_ev3:  
                   m__U2_arm =
                      new Test1_U2(*r_union_type.m__U2_arm);
                   break;

                 // v3
		  case Test1_ev7:  
                   m_v3 =
                      new Test1_O2_var(*r_union_type.m_v3);
                   break;

                 // v4
                  default:
                   m_v4 =
                      new Test1_R_var(*r_union_type.m_v4);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U3& Test1_U3::self(){
        return *this;
  }

  // discriminator access
  Test1_TheE Test1_U3::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U3::_d (Test1_TheE new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
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

                 // _U2_arm
		  case Test1_ev3:  
                  switch(new_d) { 
                       case Test1_ev3: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // v3
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

   const iluShortCharacter *Test1_U3::_CString_arm() const{
        return (m__CString_arm->iluStringVarReference());
   }

   void Test1_U3::_CString_arm(iluShortCharacter * a__CString_arm){
         unset();
         m_discriminator = Test1_ev1;
         m__CString_arm = new CORBA_String_var(a__CString_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
         

   void Test1_U3::_CString_arm(const iluShortCharacter * a__CString_arm){
         unset();
         m_discriminator = Test1_ev1;
         m__CString_arm = new CORBA_String_var(a__CString_arm);
         m_b_beenset = ILUCPP_TRUE;
   }

   void Test1_U3::_CString_arm(const CORBA_String_var& a__CString_arm){
         unset();
         m_discriminator = Test1_ev1;
         m__CString_arm = new CORBA_String_var(a__CString_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _U2_arm access
    const Test1_U2& Test1_U3::_U2_arm() const {
           return( (const Test1_U2&) *m__U2_arm);
    }

    Test1_U2& Test1_U3::_U2_arm(){
           return( (Test1_U2&) *m__U2_arm);
    }

    void Test1_U3::_U2_arm(const Test1_U2 & a__U2_arm){
         unset();
         m_discriminator = Test1_ev3;
         m__U2_arm = new Test1_U2(a__U2_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // v3 access
     Test1_O2_ptr Test1_U3::v3() const {
       return (*m_v3);
    }
  
    void Test1_U3::v3 (Test1_O2_ptr a_v3) {
          unset();			
          m_discriminator = Test1_ev7;
          // duplicate per corba spec
          Test1_O2::_duplicate(a_v3);
          m_v3 = new Test1_O2_var(a_v3);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // v4 access

    Test1_RO Test1_U3::v4() const {
              return( (Test1_TheR*&) *m_v4);
    }


    void Test1_U3::v4(Test1_RO a_v4){
         unset();
         m_discriminator = Test1_ev5;
         m_v4 =  new Test1_TheR_var(a_v4);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_U3::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
			  break;

                 // _U2_arm
		  case Test1_ev3:  
			  break;

                 // v3
		  case Test1_ev7:  
			  m_v3->iluDeleteWrapper();
			  break;

                 // v4
                  default:
			  break;
		  }
	  }
  }
		  
  void Test1_U3::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                     delete m__CString_arm;
                     break;

                 // _U2_arm
		  case Test1_ev3:  
                     delete m__U2_arm;
                     break;

                 // v3
		  case Test1_ev7:  
                     delete m_v3;
                     break;

                 // v4
                  default:
                     delete m_v4;
                     break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U3

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U3& r_Test1_U3) {

          iluUnionWrapper _r_Test1_U3(
                                r_Test1_U3._d(),
                                ilu_enumeration_tk);
          r_call += _r_Test1_U3;

          switch (r_Test1_U3.m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                   { iluCardinal _r__CString_arm_length =
                    strlen(r_Test1_U3.m__CString_arm->iluStringVarReference());
                    iluCStringWrapper _r__CString_arm_wrap(
                       (*r_Test1_U3.m__CString_arm).iluStringVarReference(),
                            _r__CString_arm_length);
                    r_call += _r__CString_arm_wrap;
                   }
                   break;

                 // _U2_arm
		  case Test1_ev3:  
                    r_call += (*r_Test1_U3.m__U2_arm); 
                   break;

                 // v3
		  case Test1_ev7:  
                    r_call += (* (r_Test1_U3.m_v3));

                   break;

                 // v4
                  default:
                {
                  iluOptionalWrapper _opt_v4_wrap;
                  _opt_v4_wrap.m_present =
                     !((*r_Test1_U3.m_v4).iluIsNull());
                  r_call += _opt_v4_wrap;
                  if(_opt_v4_wrap.m_present) {
                    r_call += (*r_Test1_U3.m_v4)->self(); 
                  }
                 }
                   break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U3& r_Test1_U3) {

          iluUnionWrapper _r_Test1_U3(
                                r_Test1_U3._d(),
                                ilu_enumeration_tk);
          r_call << _r_Test1_U3;

          switch (r_Test1_U3.m_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                   { iluCardinal _r__CString_arm_length =
                    strlen(r_Test1_U3.m__CString_arm->iluStringVarReference());
                    iluCStringWrapper _r__CString_arm_wrap(
                       (*r_Test1_U3.m__CString_arm).iluStringVarReference(),
                            _r__CString_arm_length);
                    r_call << _r__CString_arm_wrap;
                   }
                   break;

                 // _U2_arm
		  case Test1_ev3:  
                    r_call << (*r_Test1_U3.m__U2_arm); 
                   break;

                 // v3
		  case Test1_ev7:  
                    r_call << (* (r_Test1_U3.m_v3));

                   break;

                 // v4
                  default:
                {
                  iluOptionalWrapper _opt_v4_wrap;
                  _opt_v4_wrap.m_present =
                     !((*r_Test1_U3.m_v4).iluIsNull());
                  r_call << _opt_v4_wrap;
                  if(_opt_v4_wrap.m_present) {
                    r_call << (*r_Test1_U3.m_v4)->self(); 
                  }
                 }
                   break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U3& r_Test1_U3) {
        
          iluUnionWrapper _r_Test1_U3(0, ilu_enumeration_tk);
        
          r_call >> _r_Test1_U3;

          switch (_r_Test1_U3.m_card_discriminator) {

                 // _CString_arm
		  case Test1_ev1:  
                 { CORBA_String_var  _CString_arm_temp;
                     iluCardinal _r__CString_arm_length;
                     iluCStringWrapper _r__CString_arm_wrap(
                             _CString_arm_temp.iluStringVarReference(),
                            _r__CString_arm_length);
                     r_call >> _r__CString_arm_wrap;
                     r_Test1_U3._CString_arm(_CString_arm_temp);
                    break;
                   }

                 // _U2_arm
		  case Test1_ev3:  
                 { Test1_U2  _U2_arm_temp;
                    r_call >> _U2_arm_temp;
                    r_Test1_U3._U2_arm(_U2_arm_temp);
                    break;
                   }

                 // v3
		  case Test1_ev7:  
                 { Test1_O2_var  v3_temp;
                    r_call >> v3_temp;
                    r_Test1_U3.v3(v3_temp);
                    break;
                   }

                 // v4
                  default:
                 {
                   iluOptionalWrapper _opt_v4_wrap;
                   r_call >> _opt_v4_wrap;
                   if(_opt_v4_wrap.m_present) { 
                 { Test1_TheR  v4_temp;
                    r_call >> v4_temp;
                    r_Test1_U3.v4(&v4_temp);
                    }
                  }
                  else {
                     delete r_Test1_U3.m_v4;
                  }
                    break;
                   }

          };

          r_call >> iluEndUnion;
          r_Test1_U3._d((Test1_TheE) (_r_Test1_U3.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U3
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U3, Test1_U3)

  // typecode instance for Test1_U3
  const CORBA_TypeCode_ptr Test1_tc_U3 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U3);

  // define the Any insert and extract operators for Test1_U3 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U3, Test1_tc_U3)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U3, Test1_tc_U3)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U3, Test1_tc_U3)


  //////////////////////////////////////////////////////////////////////
  // Test1_U2 members
		
  // constructors & destructor
  Test1_U2::Test1_U2() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U2::Test1_U2(const Test1_U2& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U2::~Test1_U2() {
	  unset();
  }

  // assignment
  Test1_U2& Test1_U2::operator=
          (const Test1_U2& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  m_x1 = r_union_type.m_x1;
                  break;

                 // x2
		  case 1:  
		  case 22:  
                   m_x2 =
                      new Test1_O2_var(*r_union_type.m_x2);
                   break;

                 // x3
		  case 2:  
                   m_x3 =
                      new Test1_CSS(*r_union_type.m_x3);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U2& Test1_U2::self(){
        return *this;
  }

  // discriminator access
  CORBA_Short Test1_U2::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U2::_d (CORBA_Short new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  switch(new_d) { 
                       case 3: 
                       case 7: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // x2
		  case 1:  
		  case 22:  
                  switch(new_d) { 
                       case 1: 
                       case 22: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // x3
		  case 2:  
                  switch(new_d) { 
                       case 2: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case 3: 
                       case 7: 
                       case 1: 
                       case 22: 
                       case 2: 
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
 
   // x1 access
     CORBA_Boolean Test1_U2::x1 () const {
       return m_x1;
     }

     void Test1_U2::x1 (CORBA_Boolean a_x1) {
          unset();			
          m_discriminator = 3;
          m_x1 = a_x1;
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // x2 access
     Test1_O2_ptr Test1_U2::x2() const {
       return (*m_x2);
    }
  
    void Test1_U2::x2 (Test1_O2_ptr a_x2) {
          unset();			
          m_discriminator = 1;
          // duplicate per corba spec
          Test1_O2::_duplicate(a_x2);
          m_x2 = new Test1_O2_var(a_x2);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // x3 access
    const Test1_CSS& Test1_U2::x3() const {
           return( (const Test1_CSS&) *m_x3);
    }

    Test1_CSS& Test1_U2::x3(){
           return( (Test1_CSS&) *m_x3);
    }

    void Test1_U2::x3(const Test1_CSS & a_x3){
         unset();
         m_discriminator = 2;
         m_x3 = new Test1_CSS(a_x3);
         m_b_beenset = ILUCPP_TRUE;
   }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_U2::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
			  break;

                 // x2
		  case 1:  
		  case 22:  
			  m_x2->iluDeleteWrapper();
			  break;

                 // x3
		  case 2:  
			  break;
		  }
	  }
  }
		  
  void Test1_U2::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                     break;

                 // x2
		  case 1:  
		  case 22:  
                     delete m_x2;
                     break;

                 // x3
		  case 2:  
                     delete m_x3;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U2

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U2& r_Test1_U2) {

          iluUnionWrapper _r_Test1_U2(
                                r_Test1_U2._d(),
                                ilu_shortinteger_tk);
          r_call += _r_Test1_U2;

          switch (r_Test1_U2.m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  { iluBoolWrapper _r_x1_wrap(
                    (ILUCPP_BOOL &) r_Test1_U2.m_x1);
                    r_call += _r_x1_wrap;
                  }
                   break;

                 // x2
		  case 1:  
		  case 22:  
                    r_call += (* (r_Test1_U2.m_x2));

                   break;

                 // x3
		  case 2:  
                    r_call += (*r_Test1_U2.m_x3); 
                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U2& r_Test1_U2) {

          iluUnionWrapper _r_Test1_U2(
                                r_Test1_U2._d(),
                                ilu_shortinteger_tk);
          r_call << _r_Test1_U2;

          switch (r_Test1_U2.m_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                  { iluBoolWrapper _r_x1_wrap(
                    (ILUCPP_BOOL &) r_Test1_U2.m_x1);
                    r_call << _r_x1_wrap;
                  }
                   break;

                 // x2
		  case 1:  
		  case 22:  
                    r_call << (* (r_Test1_U2.m_x2));

                   break;

                 // x3
		  case 2:  
                    r_call << (*r_Test1_U2.m_x3); 
                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U2& r_Test1_U2) {
        
          iluUnionWrapper _r_Test1_U2(0, ilu_shortinteger_tk);
        
          r_call >> _r_Test1_U2;

          switch (_r_Test1_U2.m_card_discriminator) {

                 // x1
		  case 3:  
		  case 7:  
                 { CORBA_Boolean  x1_temp;
                  iluBoolWrapper _r_x1_wrap(
                        (ILUCPP_BOOL &)  x1_temp);
                  r_call >> _r_x1_wrap;
                  r_Test1_U2.x1(x1_temp);
                    break;
                   }

                 // x2
		  case 1:  
		  case 22:  
                 { Test1_O2_var  x2_temp;
                    r_call >> x2_temp;
                    r_Test1_U2.x2(x2_temp);
                    break;
                   }

                 // x3
		  case 2:  
                 { Test1_CSS  x3_temp;
                    r_call >> x3_temp;
                    r_Test1_U2.x3(x3_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_Test1_U2._d((CORBA_Short) (_r_Test1_U2.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U2
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U2, Test1_U2)

  // typecode instance for Test1_U2
  const CORBA_TypeCode_ptr Test1_tc_U2 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U2);

  // define the Any insert and extract operators for Test1_U2 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U2, Test1_tc_U2)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U2, Test1_tc_U2)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U2, Test1_tc_U2)


  //////////////////////////////////////////////////////////////////////
  // Test1_U1 members
		
  // constructors & destructor
  Test1_U1::Test1_U1() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_U1::Test1_U1(const Test1_U1& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_U1::~Test1_U1() {
	  unset();
  }

  // assignment
  Test1_U1& Test1_U1::operator=
          (const Test1_U1& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                   m__R_arm =
                      new Test1_R(*r_union_type.m__R_arm);
                   break;

                 // _A1_arm
		  case 1:  
                   if(r_union_type.m__A1_arm == NULL)  
                       m__A1_arm= NULL;
                   else {
                      if(m__A1_arm == NULL) 
                          Test1_TheA1_dup(r_union_type.m__A1_arm);
                      else
                         Test1_TheA1_copy( m__A1_arm,
                               r_union_type.m__A1_arm);
                   }  
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_U1& Test1_U1::self(){
        return *this;
  }

  // discriminator access
  CORBA_Short Test1_U1::_d () const { 
	  return m_discriminator; 
  }

  void Test1_U1::_d (CORBA_Short new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case 0: 
                       case 1: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _R_arm
		  case 0:  
                  switch(new_d) { 
                       case 0: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _A1_arm
		  case 1:  
                  switch(new_d) { 
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
 
   // _R_arm access
    const Test1_TheR& Test1_U1::_R_arm() const {
           return( (const Test1_TheR&) *m__R_arm);
    }

    Test1_TheR& Test1_U1::_R_arm(){
           return( (Test1_TheR&) *m__R_arm);
    }

    void Test1_U1::_R_arm(const Test1_TheR & a__R_arm){
         unset();
         m_discriminator = 0;
         m__R_arm = new Test1_TheR(a__R_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _A1_arm access

    Test1_TheA1_slice *Test1_U1::_A1_arm() const {
           return((Test1_TheA1_slice *) m__A1_arm);
    }


    void Test1_U1::_A1_arm( Test1_TheA1_slice* a__A1_arm){
         unset();
         m_discriminator = 1;
         if(a__A1_arm == NULL) m__A1_arm = NULL;
         else { 
              if(m__A1_arm == NULL)
                  m__A1_arm = Test1_TheA1_alloc();
             Test1_TheA1_copy(m__A1_arm, a__A1_arm);
         }
         m_b_beenset = ILUCPP_TRUE;
    }
		  
  void Test1_U1::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                     delete m__R_arm;
                     break;

                 // _A1_arm
		  case 1:  
                     delete [] m__A1_arm;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_U1

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_U1& r_Test1_U1) {

          iluUnionWrapper _r_Test1_U1(
                                r_Test1_U1._d(),
                                ilu_shortinteger_tk);
          r_call += _r_Test1_U1;

          switch (r_Test1_U1.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call += (*r_Test1_U1.m__R_arm); 
                   break;

                 // _A1_arm
		  case 1:  
                    Test1_size_const_TheA1(r_call, r_Test1_U1.m__A1_arm);
                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_U1& r_Test1_U1) {

          iluUnionWrapper _r_Test1_U1(
                                r_Test1_U1._d(),
                                ilu_shortinteger_tk);
          r_call << _r_Test1_U1;

          switch (r_Test1_U1.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call << (*r_Test1_U1.m__R_arm); 
                   break;

                 // _A1_arm
		  case 1:  
                    Test1_output_const_TheA1(r_call, r_Test1_U1.m__A1_arm);
                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_U1& r_Test1_U1) {
        
          iluUnionWrapper _r_Test1_U1(0, ilu_shortinteger_tk);
        
          r_call >> _r_Test1_U1;

          switch (_r_Test1_U1.m_card_discriminator) {

                 // _R_arm
		  case 0:  
                 { Test1_R  _R_arm_temp;
                    r_call >> _R_arm_temp;
                    r_Test1_U1._R_arm(_R_arm_temp);
                    break;
                   }

                 // _A1_arm
		  case 1:  
         {
                    Test1_input_TheA1(r_call, r_Test1_U1.m__A1_arm);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test1_U1._d((CORBA_Short) (_r_Test1_U1.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_U1
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_U1, Test1_U1)

  // typecode instance for Test1_U1
  const CORBA_TypeCode_ptr Test1_tc_U1 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_U1);

  // define the Any insert and extract operators for Test1_U1 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_U1, Test1_tc_U1)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_U1, Test1_tc_U1)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_U1, Test1_tc_U1)


  //////////////////////////////////////////////////////////////////////
  // Test1_TheU members
		
  // constructors & destructor
  Test1_TheU::Test1_TheU() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_TheU::Test1_TheU(const Test1_TheU& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_TheU::~Test1_TheU() {
	  unset();
  }

  // assignment
  Test1_TheU& Test1_TheU::operator=
          (const Test1_TheU& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                   m__R_arm =
                      new Test1_R(*r_union_type.m__R_arm);
                   break;

                 // _RO_arm
		  case 1:  
                   m__RO_arm =
                      new Test1_R_var(*r_union_type.m__RO_arm);
                   break;

                 // _CSS_arm
		  case 2:  
                   m__CSS_arm =
                      new Test1_CSS(*r_union_type.m__CSS_arm);
                   break;

                 // _O1_arm
		  case 3:  
                   m__O1_arm =
                      new Test1_O1_var(*r_union_type.m__O1_arm);
                   break;

                 // _OO_arm
		  case 4:  
                   m__OO_arm =
                      new Test1_O1_var(*r_union_type.m__OO_arm);
                   break;

                 // _CORBA_Boolean_arm
		  case 5:  
                  m__CORBA_Boolean_arm = r_union_type.m__CORBA_Boolean_arm;
                  break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_TheU& Test1_TheU::self(){
        return *this;
  }

  // discriminator access
  CORBA_Short Test1_TheU::_d () const { 
	  return m_discriminator; 
  }

  void Test1_TheU::_d (CORBA_Short new_d) { 
	  
    if (!m_b_beenset) {
          // neither default nor others allowed, so see if new setting in range
          switch (new_d) { 
                       case 0: 
                       case 1: 
                       case 2: 
                       case 3: 
                       case 4: 
                       case 5: 
		              m_discriminator = new_d;
                              return;
                       default:
                              ILUCPP_BAD_DISC_SET()
                              return;
                   }
          }
         switch(m_discriminator) {

                 // _R_arm
		  case 0:  
                  switch(new_d) { 
                       case 0: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _RO_arm
		  case 1:  
                  switch(new_d) { 
                       case 1: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _CSS_arm
		  case 2:  
                  switch(new_d) { 
                       case 2: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _O1_arm
		  case 3:  
                  switch(new_d) { 
                       case 3: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _OO_arm
		  case 4:  
                  switch(new_d) { 
                       case 4: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                 // _CORBA_Boolean_arm
		  case 5:  
                  switch(new_d) { 
                       case 5: 
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
                       case 2: 
                       case 3: 
                       case 4: 
                       case 5: 
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
 
   // _R_arm access
    const Test1_TheR& Test1_TheU::_R_arm() const {
           return( (const Test1_TheR&) *m__R_arm);
    }

    Test1_TheR& Test1_TheU::_R_arm(){
           return( (Test1_TheR&) *m__R_arm);
    }

    void Test1_TheU::_R_arm(const Test1_TheR & a__R_arm){
         unset();
         m_discriminator = 0;
         m__R_arm = new Test1_TheR(a__R_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _RO_arm access

    Test1_RO Test1_TheU::_RO_arm() const {
              return( (Test1_TheR*&) *m__RO_arm);
    }


    void Test1_TheU::_RO_arm(Test1_RO a__RO_arm){
         unset();
         m_discriminator = 1;
         m__RO_arm =  new Test1_TheR_var(a__RO_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _CSS_arm access
    const Test1_CSS& Test1_TheU::_CSS_arm() const {
           return( (const Test1_CSS&) *m__CSS_arm);
    }

    Test1_CSS& Test1_TheU::_CSS_arm(){
           return( (Test1_CSS&) *m__CSS_arm);
    }

    void Test1_TheU::_CSS_arm(const Test1_CSS & a__CSS_arm){
         unset();
         m_discriminator = 2;
         m__CSS_arm = new Test1_CSS(a__CSS_arm);
         m_b_beenset = ILUCPP_TRUE;
   }
 
   // _O1_arm access
     Test1_TheO1_ptr Test1_TheU::_O1_arm() const {
       return (*m__O1_arm);
    }
  
    void Test1_TheU::_O1_arm (Test1_TheO1_ptr a__O1_arm) {
          unset();			
          m_discriminator = 3;
          // duplicate per corba spec
          Test1_TheO1::_duplicate(a__O1_arm);
          m__O1_arm = new Test1_O1_var(a__O1_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // _OO_arm access
     Test1_TheO1_ptr Test1_TheU::_OO_arm() const {
       return (*m__OO_arm);
    }
  
    void Test1_TheU::_OO_arm (Test1_TheO1_ptr a__OO_arm) {
          unset();			
          m_discriminator = 4;
          // duplicate per corba spec
          Test1_TheO1::_duplicate(a__OO_arm);
          m__OO_arm = new Test1_O1_var(a__OO_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
 
   // _CORBA_Boolean_arm access
     CORBA_Boolean Test1_TheU::_CORBA_Boolean_arm () const {
       return m__CORBA_Boolean_arm;
     }

     void Test1_TheU::_CORBA_Boolean_arm (CORBA_Boolean a__CORBA_Boolean_arm) {
          unset();			
          m_discriminator = 5;
          m__CORBA_Boolean_arm = a__CORBA_Boolean_arm;
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_TheU::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
			  break;

                 // _RO_arm
		  case 1:  
			  break;

                 // _CSS_arm
		  case 2:  
			  break;

                 // _O1_arm
		  case 3:  
			  m__O1_arm->iluDeleteWrapper();
			  break;

                 // _OO_arm
		  case 4:  
			  m__OO_arm->iluDeleteWrapper();
			  break;

                 // _CORBA_Boolean_arm
		  case 5:  
			  break;
		  }
	  }
  }
		  
  void Test1_TheU::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _R_arm
		  case 0:  
                     delete m__R_arm;
                     break;

                 // _RO_arm
		  case 1:  
                     delete m__RO_arm;
                     break;

                 // _CSS_arm
		  case 2:  
                     delete m__CSS_arm;
                     break;

                 // _O1_arm
		  case 3:  
                     delete m__O1_arm;
                     break;

                 // _OO_arm
		  case 4:  
                     delete m__OO_arm;
                     break;

                 // _CORBA_Boolean_arm
		  case 5:  
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_TheU

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_TheU& r_Test1_TheU) {

          iluUnionWrapper _r_Test1_TheU(
                                r_Test1_TheU._d(),
                                ilu_shortinteger_tk);
          r_call += _r_Test1_TheU;

          switch (r_Test1_TheU.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call += (*r_Test1_TheU.m__R_arm); 
                   break;

                 // _RO_arm
		  case 1:  
                {
                  iluOptionalWrapper _opt__RO_arm_wrap;
                  _opt__RO_arm_wrap.m_present =
                     !((*r_Test1_TheU.m__RO_arm).iluIsNull());
                  r_call += _opt__RO_arm_wrap;
                  if(_opt__RO_arm_wrap.m_present) {
                    r_call += (*r_Test1_TheU.m__RO_arm)->self(); 
                  }
                 }
                   break;

                 // _CSS_arm
		  case 2:  
                    r_call += (*r_Test1_TheU.m__CSS_arm); 
                   break;

                 // _O1_arm
		  case 3:  
                    r_call += (* (r_Test1_TheU.m__O1_arm));

                   break;

                 // _OO_arm
		  case 4:  
                {
                  iluOptionalWrapper _opt__OO_arm_wrap;
                  _opt__OO_arm_wrap.m_present =
                     !((*r_Test1_TheU.m__OO_arm).iluIsNull());
                  r_call += _opt__OO_arm_wrap;
                  if(_opt__OO_arm_wrap.m_present) {
                    r_call += (* (r_Test1_TheU.m__OO_arm));

                  }
                 }
                   break;

                 // _CORBA_Boolean_arm
		  case 5:  
                  { iluBoolWrapper _r__CORBA_Boolean_arm_wrap(
                    (ILUCPP_BOOL &) r_Test1_TheU.m__CORBA_Boolean_arm);
                    r_call += _r__CORBA_Boolean_arm_wrap;
                  }
                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_TheU& r_Test1_TheU) {

          iluUnionWrapper _r_Test1_TheU(
                                r_Test1_TheU._d(),
                                ilu_shortinteger_tk);
          r_call << _r_Test1_TheU;

          switch (r_Test1_TheU.m_discriminator) {

                 // _R_arm
		  case 0:  
                    r_call << (*r_Test1_TheU.m__R_arm); 
                   break;

                 // _RO_arm
		  case 1:  
                {
                  iluOptionalWrapper _opt__RO_arm_wrap;
                  _opt__RO_arm_wrap.m_present =
                     !((*r_Test1_TheU.m__RO_arm).iluIsNull());
                  r_call << _opt__RO_arm_wrap;
                  if(_opt__RO_arm_wrap.m_present) {
                    r_call << (*r_Test1_TheU.m__RO_arm)->self(); 
                  }
                 }
                   break;

                 // _CSS_arm
		  case 2:  
                    r_call << (*r_Test1_TheU.m__CSS_arm); 
                   break;

                 // _O1_arm
		  case 3:  
                    r_call << (* (r_Test1_TheU.m__O1_arm));

                   break;

                 // _OO_arm
		  case 4:  
                {
                  iluOptionalWrapper _opt__OO_arm_wrap;
                  _opt__OO_arm_wrap.m_present =
                     !((*r_Test1_TheU.m__OO_arm).iluIsNull());
                  r_call << _opt__OO_arm_wrap;
                  if(_opt__OO_arm_wrap.m_present) {
                    r_call << (* (r_Test1_TheU.m__OO_arm));

                  }
                 }
                   break;

                 // _CORBA_Boolean_arm
		  case 5:  
                  { iluBoolWrapper _r__CORBA_Boolean_arm_wrap(
                    (ILUCPP_BOOL &) r_Test1_TheU.m__CORBA_Boolean_arm);
                    r_call << _r__CORBA_Boolean_arm_wrap;
                  }
                   break;
               default:
                    ILUCPP_BAD_DISC()  
                    break;
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_TheU& r_Test1_TheU) {
        
          iluUnionWrapper _r_Test1_TheU(0, ilu_shortinteger_tk);
        
          r_call >> _r_Test1_TheU;

          switch (_r_Test1_TheU.m_card_discriminator) {

                 // _R_arm
		  case 0:  
                 { Test1_R  _R_arm_temp;
                    r_call >> _R_arm_temp;
                    r_Test1_TheU._R_arm(_R_arm_temp);
                    break;
                   }

                 // _RO_arm
		  case 1:  
                 {
                   iluOptionalWrapper _opt__RO_arm_wrap;
                   r_call >> _opt__RO_arm_wrap;
                   if(_opt__RO_arm_wrap.m_present) { 
                 { Test1_TheR  _RO_arm_temp;
                    r_call >> _RO_arm_temp;
                    r_Test1_TheU._RO_arm(&_RO_arm_temp);
                    }
                  }
                  else {
                     delete r_Test1_TheU.m__RO_arm;
                  }
                    break;
                   }

                 // _CSS_arm
		  case 2:  
                 { Test1_CSS  _CSS_arm_temp;
                    r_call >> _CSS_arm_temp;
                    r_Test1_TheU._CSS_arm(_CSS_arm_temp);
                    break;
                   }

                 // _O1_arm
		  case 3:  
                 { Test1_O1_var  _O1_arm_temp;
                    r_call >> _O1_arm_temp;
                    r_Test1_TheU._O1_arm(_O1_arm_temp);
                    break;
                   }

                 // _OO_arm
		  case 4:  
                 {
                   iluOptionalWrapper _opt__OO_arm_wrap;
                   r_call >> _opt__OO_arm_wrap;
                   if(_opt__OO_arm_wrap.m_present) { 
                 { Test1_TheO1_var  _OO_arm_temp;
                    r_call >> _OO_arm_temp;
                    r_Test1_TheU._OO_arm(_OO_arm_temp);
                    }
                  }
                  else {
                     delete r_Test1_TheU.m__OO_arm;
                  }
                    break;
                   }

                 // _CORBA_Boolean_arm
		  case 5:  
                 { CORBA_Boolean  _CORBA_Boolean_arm_temp;
                  iluBoolWrapper _r__CORBA_Boolean_arm_wrap(
                        (ILUCPP_BOOL &)  _CORBA_Boolean_arm_temp);
                  r_call >> _r__CORBA_Boolean_arm_wrap;
                  r_Test1_TheU._CORBA_Boolean_arm(_CORBA_Boolean_arm_temp);
                    break;
                   }
               default:
                    ILUCPP_BAD_DISC()  
                    break;

          };

          r_call >> iluEndUnion;
          r_Test1_TheU._d((CORBA_Short) (_r_Test1_TheU.m_card_discriminator));
	  return r_call;
  }

  // define the member fns in typecode class for Test1_TheU
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_TheU, Test1_TheU)

  // typecode instance for Test1_TheU
  const CORBA_TypeCode_ptr Test1_tc_TheU =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheU);

  // define the Any insert and extract operators for Test1_TheU 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_TheU, Test1_tc_TheU)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_TheU, Test1_tc_TheU)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_TheU, Test1_tc_TheU)


  //////////////////////////////////////////////////////////////////////
  // Test1_OO2 members
		
  // constructors & destructor
  Test1_OO2::Test1_OO2() : m_b_beenset(ILUCPP_FALSE) {}

  Test1_OO2::Test1_OO2(const Test1_OO2& r_union_type) : m_b_beenset(ILUCPP_FALSE) {
	  (*this) = r_union_type;
  }

  
  Test1_OO2::~Test1_OO2() {
	  unset();
  }

  // assignment
  Test1_OO2& Test1_OO2::operator=
          (const Test1_OO2& r_union_type) {

	  if (this == &r_union_type) return (*this);
	  unset();
	  m_b_beenset = r_union_type.m_b_beenset;
	  if (!m_b_beenset) return (*this);
	  
	  m_discriminator = r_union_type.m_discriminator;
	  switch (m_discriminator) {

                 // _O2_arm
		  case ILUCPP_TRUE:  
                   m__O2_arm =
                      new Test1_O2_var(*r_union_type.m__O2_arm);
                   break;
             }
             return(*this);
 }

  //possibly sunpro-specific workaround 
  Test1_OO2& Test1_OO2::self(){
        return *this;
  }

  // discriminator access
  CORBA_Boolean Test1_OO2::_d () const { 
	  return m_discriminator; 
  }

  void Test1_OO2::_d (CORBA_Boolean new_d) { 
	  
	  if (! m_b_beenset) {
		  m_discriminator = new_d;
		  return;
	  }
          switch(m_discriminator) {

                 // _O2_arm
		  case ILUCPP_TRUE:  
                  switch(new_d) { 
                       case ILUCPP_TRUE: 
                            m_discriminator = new_d;
                            return;  
                       default:
                            break; 
                  }
                  break;

                //default
                  default:
                    switch(new_d) {
                       case ILUCPP_TRUE: 
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
 
   // _O2_arm access
     Test1_O2_ptr Test1_OO2::_O2_arm() const {
       return (*m__O2_arm);
    }
  
    void Test1_OO2::_O2_arm (Test1_O2_ptr a__O2_arm) {
          unset();			
          m_discriminator = ILUCPP_TRUE;
          // duplicate per corba spec
          Test1_O2::_duplicate(a__O2_arm);
          m__O2_arm = new Test1_O2_var(a__O2_arm);
          m_b_beenset = ILUCPP_TRUE;
    }
		  
  // for ilustub use only -
  // should be called before the surrogate side stub returns
  void Test1_OO2::iluSurrogateSideCleanup() const {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _O2_arm
		  case ILUCPP_TRUE:  
			  m__O2_arm->iluDeleteWrapper();
			  break;
		  }
	  }
  }
		  
  void Test1_OO2::unset() {
	  if (m_b_beenset) {
		  switch (m_discriminator) {

                 // _O2_arm
		  case ILUCPP_TRUE:  
                     delete m__O2_arm;
                     break;
                  default: 
                      break;
                }
                m_b_beenset = ILUCPP_FALSE;
       }
  }

  // insertion, extraction, and sizing operators for Test1_OO2

  
  iluBaseCall& operator+=(iluBaseCall& r_call,
                           const Test1_OO2& r_Test1_OO2) {

          iluUnionWrapper _r_Test1_OO2(
                                r_Test1_OO2._d(),
                                ilu_boolean_tk);
          r_call += _r_Test1_OO2;

          switch (r_Test1_OO2.m_discriminator) {

                 // _O2_arm
		  case ILUCPP_TRUE:  
                    r_call += (* (r_Test1_OO2.m__O2_arm));

                   break;
               default:
                   break;  
          }

          r_call += iluEndUnion;
          return r_call;
 }
  
  iluBaseCall& operator<<(iluBaseCall& r_call,
                           const Test1_OO2& r_Test1_OO2) {

          iluUnionWrapper _r_Test1_OO2(
                                r_Test1_OO2._d(),
                                ilu_boolean_tk);
          r_call << _r_Test1_OO2;

          switch (r_Test1_OO2.m_discriminator) {

                 // _O2_arm
		  case ILUCPP_TRUE:  
                    r_call << (* (r_Test1_OO2.m__O2_arm));

                   break;
               default:
                   break;  
          }

          r_call << iluEndUnion;
          return r_call;
 }

  iluBaseCall& operator>>(iluBaseCall& r_call, Test1_OO2& r_Test1_OO2) {
        
          iluUnionWrapper _r_Test1_OO2(0, ilu_boolean_tk);
        
          r_call >> _r_Test1_OO2;

          switch (_r_Test1_OO2.m_card_discriminator) {

                 // _O2_arm
		  case ILUCPP_TRUE:  
                 { Test1_O2_var  _O2_arm_temp;
                    r_call >> _O2_arm_temp;
                    r_Test1_OO2._O2_arm(_O2_arm_temp);
                    break;
                   }
               default:
                   break;  

          };

          r_call >> iluEndUnion;
          r_Test1_OO2._d(_r_Test1_OO2.m_card_discriminator!= 0);
          return r_call;
  }

  // define the member fns in typecode class for Test1_OO2
  ILUCPP_DEFINE_ILU_TYPE_CODE_MEMBERFUNCTIONS(
             Test1_OO2, Test1_OO2)

  // typecode instance for Test1_OO2
  const CORBA_TypeCode_ptr Test1_tc_OO2 =
            new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_OO2);

  // define the Any insert and extract operators for Test1_OO2 
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(
          Test1_OO2, Test1_tc_OO2)
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(
          Test1_OO2, Test1_tc_OO2)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(
          Test1_OO2, Test1_tc_OO2)

  //////////////////////////////////////////////////////////////////////
  // Test1_O4 members

  // CORBA object reference operations

  Test1_O4_ptr Test1_O4::_duplicate( Test1_O4_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  Test1_O4_ptr Test1_O4::_nil() {
    return (Test1_O4_ptr) NULL;
  }

  // default constructor
  Test1_O4::Test1_O4() {
     // to be determined
  }

  // destructor
  Test1_O4::~Test1_O4() {
    // to be determined
  }

  // copy constructor
  Test1_O4::Test1_O4(const Test1_O4&) {
    // to be determined
  }

  // assignment operator
  void Test1_O4::operator=(const Test1_O4&) {
    // to be determined
  }

  // Simple Object Lookup
  Test1_O4_ptr Test1_O4::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Test1_O4_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *Test1_O4::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == Test1_O3::iluGetILUClassRecord()) 
      return (REINTERPRET_CAST(void *, STATIC_CAST(Test1_O3_ptr, this)));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void Test1_O4::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "Test1.O4"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      1,          // number of methods
      1,          // number of superclasses
      _superclasses
   );

    {
     // for method R_to_R

       iluException* R_to_R_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "R-to-R"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     R_to_R_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "r"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"));
    }  //end for method R_to_R

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  Test1_O4 typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O4)::iluDeleteValue (void* pv_value) {
                Test1_O4_ptr p_thevalue = (Test1_O4_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O4)::iluDeepCopy (void* pv_value) {
                Test1_O4_ptr p_thevalue = (Test1_O4_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O4)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               Test1_O4_ptr p_thevalue = (Test1_O4_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O4)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, Test1_O4::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O4)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           Test1_O4_ptr p_object = (Test1_O4_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If Test1_O4 were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == Test1_O4::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O4)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           Test1_O4_ptr p_object = (Test1_O4_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for Test1_O4
        const CORBA_TypeCode_ptr Test1_tc_O4 = new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O4);

      // define the Any insertion and extraction operators for Test1_O4

      void operator<<=(CORBA_Any& r_any, Test1_O4_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(Test1_tc_O4, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_O4_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(Test1_tc_O4)) { 
                 r_p_object = (Test1_O4_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }

  //////////////////////////////////////////////////////////////////////
  // Test1_P members

  // CORBA object reference operations

  Test1_P_ptr Test1_P::_duplicate( Test1_P_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  Test1_P_ptr Test1_P::_nil() {
    return (Test1_P_ptr) NULL;
  }

  // default constructor
  Test1_P::Test1_P() {
     // to be determined
  }

  // destructor
  Test1_P::~Test1_P() {
    // to be determined
  }

  // copy constructor
  Test1_P::Test1_P(const Test1_P&) {
    // to be determined
  }

  // assignment operator
  void Test1_P::operator=(const Test1_P&) {
    // to be determined
  }

  // Simple Object Lookup
  Test1_P_ptr Test1_P::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Test1_P_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *Test1_P::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == Test1_O3::iluGetILUClassRecord()) 
      return (REINTERPRET_CAST(void *, STATIC_CAST(Test1_O3_ptr, this)));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void Test1_P::iluInitialize() {

    ilu_Method a_method;
     char *_superclasses[] = {                   CONST_CAST( iluCString,  "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"), 
       };
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "Test1.P"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "ilut:dY9O+Pbe716S3dZTXTUzbvfKs87"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      1,          // number of methods
      1,          // number of superclasses
      _superclasses
   );

    {
     // for method m2

       iluException* m2_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "m2"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     m2_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "j"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
    }  //end for method m2

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  Test1_P typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(Test1_P)::iluDeleteValue (void* pv_value) {
                Test1_P_ptr p_thevalue = (Test1_P_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_P)::iluDeepCopy (void* pv_value) {
                Test1_P_ptr p_thevalue = (Test1_P_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test1_P)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               Test1_P_ptr p_thevalue = (Test1_P_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_P)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, Test1_P::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_P)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           Test1_P_ptr p_object = (Test1_P_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If Test1_P were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == Test1_P::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(Test1_P)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           Test1_P_ptr p_object = (Test1_P_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for Test1_P
        const CORBA_TypeCode_ptr Test1_tc_P = new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_P);

      // define the Any insertion and extraction operators for Test1_P

      void operator<<=(CORBA_Any& r_any, Test1_P_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(Test1_tc_P, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_P_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(Test1_tc_P)) { 
                 r_p_object = (Test1_P_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }

  //////////////////////////////////////////////////////////////////////
  // Test1_O3 members

  // CORBA object reference operations

  Test1_O3_ptr Test1_O3::_duplicate( Test1_O3_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  Test1_O3_ptr Test1_O3::_nil() {
    return (Test1_O3_ptr) NULL;
  }

  // default constructor
  Test1_O3::Test1_O3() {
     // to be determined
  }

  // destructor
  Test1_O3::~Test1_O3() {
    // to be determined
  }

  // copy constructor
  Test1_O3::Test1_O3(const Test1_O3&) {
    // to be determined
  }

  // assignment operator
  void Test1_O3::operator=(const Test1_O3&) {
    // to be determined
  }

  // Simple Object Lookup
  Test1_O3_ptr Test1_O3::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Test1_O3_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *Test1_O3::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void Test1_O3::iluInitialize() {

    ilu_Method a_method;
     char **_superclasses = NULL; 
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "Test1.O3"),   // ILU name
      CONST_CAST( iluCString, "v1"), 
      CONST_CAST( iluCString, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_TRUE,           // collectible?
      CONST_CAST( iluCString, ""),          // docstring
      3,          // number of methods
      0,          // number of superclasses
      _superclasses
   );

    {
     // for method RS_R_to_R_IS

       iluException* RS_R_to_R_IS_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "RS-R-to-R-IS"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     RS_R_to_R_IS_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "r"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "r2"),
             ILUCPP_FALSE, ilu_Out,
             CONST_CAST(iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"));
    }  //end for method RS_R_to_R_IS

    {
     // for method O1_U_to_U

       iluException O1_U_to_U_exception_array[1];
       O1_U_to_U_exception_array[0] =
            interface_exceptions[g_Test1_E2_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "O1-U-to-U"), // name
                     2,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     O1_U_to_U_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "o"),
             ILUCPP_TRUE, ilu_In,
             CONST_CAST(iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "u"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"));
    }  //end for method O1_U_to_U

    {
     // for method BS_to_I

       iluException* BS_to_I_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     2,      // method index
                     CONST_CAST(iluCString, "BS-to-I"), // name
                     3,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     BS_to_I_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "b"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3"));
    }  //end for method BS_to_I

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  Test1_O3 typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O3)::iluDeleteValue (void* pv_value) {
                Test1_O3_ptr p_thevalue = (Test1_O3_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O3)::iluDeepCopy (void* pv_value) {
                Test1_O3_ptr p_thevalue = (Test1_O3_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O3)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               Test1_O3_ptr p_thevalue = (Test1_O3_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O3)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, Test1_O3::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O3)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           Test1_O3_ptr p_object = (Test1_O3_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If Test1_O3 were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == Test1_O3::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O3)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           Test1_O3_ptr p_object = (Test1_O3_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for Test1_O3
        const CORBA_TypeCode_ptr Test1_tc_O3 = new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O3);

      // define the Any insertion and extraction operators for Test1_O3

      void operator<<=(CORBA_Any& r_any, Test1_O3_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(Test1_tc_O3, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_O3_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(Test1_tc_O3)) { 
                 r_p_object = (Test1_O3_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }

  //////////////////////////////////////////////////////////////////////
  // Test1_TheO1 members

  // CORBA object reference operations

  Test1_TheO1_ptr Test1_TheO1::_duplicate( Test1_TheO1_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  Test1_TheO1_ptr Test1_TheO1::_nil() {
    return (Test1_TheO1_ptr) NULL;
  }

  // default constructor
  Test1_TheO1::Test1_TheO1() {
     // to be determined
  }

  // destructor
  Test1_TheO1::~Test1_TheO1() {
    // to be determined
  }

  // copy constructor
  Test1_TheO1::Test1_TheO1(const Test1_TheO1&) {
    // to be determined
  }

  // assignment operator
  void Test1_TheO1::operator=(const Test1_TheO1&) {
    // to be determined
  }

  // Simple Object Lookup
  Test1_TheO1_ptr Test1_TheO1::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Test1_TheO1_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *Test1_TheO1::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void Test1_TheO1::iluInitialize() {

    ilu_Method a_method;
     char **_superclasses = NULL; 
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "Test1.TheO1"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"),   // type id
      REINTERPRET_CAST(iluCString, ((ILUCPP_NULL_PTR)0) ),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, "sample\nmulti-line doc string"),          // docstring
      6,          // number of methods
      0,          // number of superclasses
      _superclasses
   );

    {
     // for method U_CSS_to_U

       iluException U_CSS_to_U_exception_array[2];
       U_CSS_to_U_exception_array[0] =
            interface_exceptions[g_Test1_E1_index];
       U_CSS_to_U_exception_array[1] =
            interface_exceptions[g_Test1_E2_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "U-CSS-to-U"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     2 ,     // number of exceptions
                     U_CSS_to_U_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "u"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "css"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy"));
    }  //end for method U_CSS_to_U

    {
     // for method f_CSS_to_RO

       iluException f_CSS_to_RO_exception_array[1];
       f_CSS_to_RO_exception_array[0] =
            interface_exceptions[g_Test1_E1_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "f-CSS-to-RO"), // name
                     2,       //method ID
                     ILUCPP_TRUE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     f_CSS_to_RO_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "css"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy"));
    }  //end for method f_CSS_to_RO

    {
     // for method R_ScS_to_F

       iluException* R_ScS_to_F_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     2,      // method index
                     CONST_CAST(iluCString, "R-ScS-to-F"), // name
                     3,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     R_ScS_to_F_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "r"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "s"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:iqqhSf395+BafbY8Oo2elFQD1bK"));
    }  //end for method R_ScS_to_F

    {
     // for method a_RO

       iluException* a_RO_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     3,      // method index
                     CONST_CAST(iluCString, "a-RO"), // name
                     4,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_TRUE,        // asynch
                     0 ,     // number of exceptions
                     a_RO_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "ro"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2"));
    }  //end for method a_RO

    {
     // for method get_O2

       iluException get_O2_exception_array[1];
       get_O2_exception_array[0] =
            interface_exceptions[g_Test1_CantCreate_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     4,      // method index
                     CONST_CAST(iluCString, "get-O2"), // name
                     5,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     get_O2_exception_array,
                     0,             // number of args
                     CONST_CAST(iluCString,"ilut:jXB9BUoPU7650cspZmJCl3y4zzu") // return type ID
        );
    }  //end for method get_O2

    {
     // for method get_O3

       iluException get_O3_exception_array[1];
       get_O3_exception_array[0] =
            interface_exceptions[g_Test1_CantCreate_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     5,      // method index
                     CONST_CAST(iluCString, "get-O3"), // name
                     6,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     get_O3_exception_array,
                     1,             // number of args
                     CONST_CAST(iluCString,"ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "subclass"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I"));
    }  //end for method get_O3

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  Test1_TheO1 typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheO1)::iluDeleteValue (void* pv_value) {
                Test1_TheO1_ptr p_thevalue = (Test1_TheO1_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheO1)::iluDeepCopy (void* pv_value) {
                Test1_TheO1_ptr p_thevalue = (Test1_TheO1_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheO1)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               Test1_TheO1_ptr p_thevalue = (Test1_TheO1_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheO1)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, Test1_TheO1::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheO1)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           Test1_TheO1_ptr p_object = (Test1_TheO1_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If Test1_TheO1 were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == Test1_TheO1::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheO1)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           Test1_TheO1_ptr p_object = (Test1_TheO1_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for Test1_TheO1
        const CORBA_TypeCode_ptr Test1_tc_TheO1 = new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheO1);

      // define the Any insertion and extraction operators for Test1_TheO1

      void operator<<=(CORBA_Any& r_any, Test1_TheO1_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(Test1_tc_TheO1, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_TheO1_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(Test1_tc_TheO1)) { 
                 r_p_object = (Test1_TheO1_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }

  //////////////////////////////////////////////////////////////////////
  // Test1_O2 members

  // CORBA object reference operations

  Test1_O2_ptr Test1_O2::_duplicate( Test1_O2_ptr a_ptr) {
    if (a_ptr) a_ptr->iluIncrementReferenceCount();
    return a_ptr;
  }

  Test1_O2_ptr Test1_O2::_nil() {
    return (Test1_O2_ptr) NULL;
  }

  // default constructor
  Test1_O2::Test1_O2() {
     // to be determined
  }

  // destructor
  Test1_O2::~Test1_O2() {
    // to be determined
  }

  // copy constructor
  Test1_O2::Test1_O2(const Test1_O2&) {
    // to be determined
  }

  // assignment operator
  void Test1_O2::operator=(const Test1_O2&) {
    // to be determined
  }

  // Simple Object Lookup
  Test1_O2_ptr Test1_O2::iluLookup(char* pc_server_id, char* pc_instance_handle) {
    return (Test1_O2_ptr) iluObject::iluLookup(pc_server_id, pc_instance_handle, m_ILUClassRecord);
  }

  // for use in narrowing
  void *Test1_O2::iluDowncast (iluClass class_to_cast_down_to) {
    if (!class_to_cast_down_to  || class_to_cast_down_to == ilu_rootClass)
      return((void *)((iluObject*) this));
    if (class_to_cast_down_to == m_ILUClassRecord)
      return ((void*) this);
    return (NULL);
  }

  // initialize to use of this class of objects - called by iluInitialize

  void Test1_O2::iluInitialize() {

    ilu_Method a_method;
     char **_superclasses = NULL; 
  // initialize to use of this class of objects - called by iluInitialize
    // create and set the class record member to be the iluClass
    // for this object type
    m_ILUClassRecord = iluCppInternal::iluDefineObjectType(
      CONST_CAST( iluCString, "Test1.O2"),   // ILU name
      CONST_CAST( iluCString, ""), 
      CONST_CAST( iluCString, "ilut:jXB9BUoPU7650cspZmJCl3y4zzu"),   // type id
      CONST_CAST(iluCString, "sunrpc_2_0x3458_3"),              // singleton?
      ILUCPP_FALSE,             // optional?
      ILUCPP_FALSE,           // collectible?
      CONST_CAST( iluCString, "sample multi-line\n    doc string with leading whitespace on the second line"),          // docstring
      2,          // number of methods
      0,          // number of superclasses
      _superclasses
   );

    {
     // for method OO_A0_to_CSS

       iluException OO_A0_to_CSS_exception_array[1];
       OO_A0_to_CSS_exception_array[0] =
            interface_exceptions[g_Test1_E2_index];

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     0,      // method index
                     CONST_CAST(iluCString, "OO-A0-to-CSS"), // name
                     1,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     1 ,     // number of exceptions
                     OO_A0_to_CSS_exception_array,
                     2,             // number of args
                     CONST_CAST(iluCString,"ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "o"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "a"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r"));
    }  //end for method OO_A0_to_CSS

    {
     // for method R_I_A1_to_I_A0

       iluException* R_I_A1_to_I_A0_exception_array = NULL;

        a_method = iluCppInternal::iluDefineMethod(
                     m_ILUClassRecord,
                     1,      // method index
                     CONST_CAST(iluCString, "R-I-A1-to-I-A0"), // name
                     2,       //method ID
                     ILUCPP_FALSE,    // cacheable
                     ILUCPP_FALSE,        // asynch
                     0 ,     // number of exceptions
                     R_I_A1_to_I_A0_exception_array,
                     3,             // number of args
                     CONST_CAST(iluCString,"ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r") // return type ID
        );
        iluCppInternal::iluDefineMethodArg (a_method, 0,
             CONST_CAST(iluCString, "r"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"));
        iluCppInternal::iluDefineMethodArg (a_method, 1,
             CONST_CAST(iluCString, "i"),
             ILUCPP_FALSE, ilu_InOut,
             CONST_CAST(iluCString, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"));
        iluCppInternal::iluDefineMethodArg (a_method, 2,
             CONST_CAST(iluCString, "a"),
             ILUCPP_FALSE, ilu_In,
             CONST_CAST(iluCString, "ilut:h3Dnvis94UwnmFURfYsCp700jVy"));
    }  //end for method R_I_A1_to_I_A0

    iluCppInternal::iluObjectTypeDefined(m_ILUClassRecord);

};

//////////////////////////////////////////////////////////////////////
//  Test1_O2 typecode related

      void ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O2)::iluDeleteValue (void* pv_value) {
                Test1_O2_ptr p_thevalue = (Test1_O2_ptr) pv_value;
                if (p_thevalue)
                    p_thevalue->iluDecrementReferenceCount();
       }

     void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O2)::iluDeepCopy (void* pv_value) {
                Test1_O2_ptr p_thevalue = (Test1_O2_ptr) pv_value;
                if (p_thevalue)
                     p_thevalue->iluIncrementReferenceCount();
                return p_thevalue;
      }

      // objects require wrappers
      CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O2)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
            try {
               Test1_O2_ptr p_thevalue = (Test1_O2_ptr) pv_value;
               iluObjectWrapper _p_thevalue(*p_thevalue, ILUCPP_FALSE);
               r_pickle_call += _p_thevalue;
               r_pickle_call.iluOutputPickle();
               r_pickle_call << _p_thevalue;
            }
            catch (...) {return ILUCPP_FALSE;}
            return ILUCPP_TRUE;
      }
	
      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O2)::iluPickleToValue (iluPickleCall& r_pickle_call) {
            iluObjectWrapper _the_value_wrapper(ILUCPP_FALSE, Test1_O2::iluGetILUClassRecord());
            try {
                r_pickle_call >> _the_value_wrapper;
            }
           catch (...) { return ILUCPP_NULL;}
           return _the_value_wrapper.m_pv_iluobject;
      }


      void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O2)::iluUpcast (void* p_an_object_of_your_type, iluClass casttoclass) {
           Test1_O2_ptr p_object = (Test1_O2_ptr) p_an_object_of_your_type;
           if ((!casttoclass) || casttoclass == ilu_rootClass)
               return ((void*)((iluObject*)p_object));
           // If Test1_O2 were a CORBA::Object type too, we'd also need
           // if (casttoclass == CORBA_Object::iluGetILUClassRecord())
           //    return ((CORBA_Object_ptr)p_object);
           if (casttoclass == Test1_O2::iluGetILUClassRecord())
                return ((void*) p_object);
           return ILUCPP_NULL;
       }


      CORBA_TypeCode_ptr ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O2)::iluMostSpecificTypeCode (void* p_an_object_of_your_type) {
           Test1_O2_ptr p_object = (Test1_O2_ptr) p_an_object_of_your_type;
           return CORBA_TypeCode::LookupTypeCode(p_object->iluClassId());
      }


        // typecode instance for Test1_O2
        const CORBA_TypeCode_ptr Test1_tc_O2 = new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_O2);

      // define the Any insertion and extraction operators for Test1_O2

      void operator<<=(CORBA_Any& r_any, Test1_O2_ptr p_object){
             // free up anything we had inside
             r_any.iluDeleteContent();
             // assign the appropriate typecode and value
             r_any.replace(Test1_tc_O2, p_object, ILUCPP_TRUE);
      }

      CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_O2_ptr& r_p_object) {

          CORBA_Any* p_nc_any = CONST_CAST(CORBA_Any*, &r_any);

          if (p_nc_any->iluGetFromPickle(Test1_tc_O2)) { 
                 r_p_object = (Test1_O2_ptr) p_nc_any->value();
                 return ILUCPP_TRUE;
          }
          return ILUCPP_FALSE;
     }

  // Support for use of optional objects in pickles/anys  

  // define the four member functions in typecode class for Test1_TheOO 
    ILUCPP_DEFINE_ILU_TYPE_CODE_DELETEVALUE(Test1_TheOO, Test1_TheOO_forany)
    ILUCPP_DEFINE_ILU_TYPE_CODE_DEEPCOPY(Test1_TheOO, Test1_TheOO_forany)

  void* ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheOO)::iluPickleToValue
        (iluPickleCall& r_pickle_call) {
                Test1_TheOO_forany* p_thevalue = new Test1_TheOO_forany;
                try {
                        iluOptionalWrapper _the_value_wrapper;
                        r_pickle_call >> _the_value_wrapper;
                        if (_the_value_wrapper.m_present) {
                                iluObjectWrapper _the_obj_wrapper(ILUCPP_FALSE,
 Test1_TheO1::iluGetILUClassRecord());
                                r_pickle_call >> _the_obj_wrapper;
                                p_thevalue->m_p_value = (Test1_TheO1_ptr)
_the_obj_wrapper.m_pv_iluobject;
                        }
                }
                catch (...) { delete p_thevalue; return ILUCPP_NULL;}
                return p_thevalue;
        }
 
  CORBA_Boolean ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheOO)::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
                iluOptionalWrapper opt_wrapper(((Test1_TheOO_forany*)pv_value)->m_p_value);
                Test1_TheO1_ptr p_thevalue = ((Test1_TheOO_forany*) pv_value)->m_p_value;
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
        
  // typecode instance for Test1_TheOO
  const CORBA_TypeCode_ptr Test1_tc_TheOO =
          new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_TheOO);
 
  // define the Any insertion and extraction operators for Test1_TheOO
  ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(Test1_TheOO_forany, Test1_tc_TheOO)
  ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(Test1_TheOO_forany, Test1_tc_TheOO)
  ILUCPP_DEFINE_EXTRACTION_OPERATOR(Test1_TheOO_forany, Test1_tc_TheOO)


  //////////////////////////////////////////////////////////////////////
  //  Test1_RO any support

        // define the four member functions in typecode class for Test1_RO
        ILUCPP_DEFINE_ILU_TYPE_CODE_DELETEVALUE(Test1_RO, Test1_RO_forany)
        ILUCPP_DEFINE_ILU_TYPE_CODE_DEEPCOPY(Test1_RO, Test1_RO_forany)
         CORBA_Boolean _ilu_Test1_RO_TypeCode::iluValueToPickle (void* pv_value, iluPickleCall& r_pickle_call) {
                try {
                     Test1_RO_forany* p_forany = (Test1_RO_forany*)pv_value;
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
         void * _ilu_Test1_RO_TypeCode::iluPickleToValue (
              iluPickleCall& r_pickle_call) {
                 Test1_RO_forany* p_thevalue = new Test1_RO_forany;
                try {
                        iluOptionalWrapper _the_opt_wrapper;
                        r_pickle_call >> _the_opt_wrapper;
                        if (_the_opt_wrapper.m_present) {
                       p_thevalue->m_p_value = new Test1_TheR;
                       r_pickle_call >> *(p_thevalue->m_p_value);
                        }
                        }
                        catch (...) { delete p_thevalue; return ILUCPP_NULL;}
                return p_thevalue;
        }

        // typecode instance for Test1_RO
        const CORBA_TypeCode_ptr Test1_tc_RO =
              new ILUCPP_TYPE_CODE_CLASS_NAME(Test1_RO);

        // define the Any insertion and extraction operators for Test1_RO
        ILUCPP_DEFINE_NONCOPYING_INSERTION_OPERATOR(Test1_RO_forany, Test1_tc_RO)
        ILUCPP_DEFINE_COPYING_INSERTION_OPERATOR(Test1_RO_forany, Test1_tc_RO)
        ILUCPP_DEFINE_EXTRACTION_OPERATOR(Test1_RO_forany, Test1_tc_RO)


/////////////////////////////////////////////////////////////////
// Exception implementations for locally-defined
// exceptions of interface Test1 

/////////////////////////////////////////////////
// Test1_E1 member functions

  //constructor
  Test1_E1::Test1_E1(const Test1_E1& a_E1) {
  _m_value = a_E1._m_value;
  }

  //destructor
  Test1_E1::~Test1_E1() {
  }

  // constructor with member value
  Test1_E1::Test1_E1(const Test1_TheU& value) {
    _m_value = value;
  }

  // assignment operator
  Test1_E1& Test1_E1::operator=(const Test1_E1& a_E1) {
	_m_value = a_E1._m_value;
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E2 member functions

  //constructor
  Test1_E2::Test1_E2(const Test1_E2& a_E2) {
  _m_value = a_E2._m_value;
  }

  //destructor
  Test1_E2::~Test1_E2() {
  }

  // constructor with member value
  Test1_E2::Test1_E2(const CORBA_Long& value) {
    _m_value = value;
  }

  // assignment operator
  Test1_E2& Test1_E2::operator=(const Test1_E2& a_E2) {
	_m_value = a_E2._m_value;
  return *this;
  }

/////////////////////////////////////////////////
// Test1_CantCreate functions

  //constructor
  Test1_CantCreate::Test1_CantCreate(const Test1_CantCreate& a_CantCreate) { }

  //destructor
  Test1_CantCreate::~Test1_CantCreate() { }

  // assignment operator
  Test1_CantCreate& Test1_CantCreate::operator=(const Test1_CantCreate& a_CantCreate) {
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E3 member functions

  //constructor
  Test1_E3::Test1_E3(const Test1_E3& a_E3) {
  _m_value = a_E3._m_value;
  }

  //destructor
  Test1_E3::~Test1_E3() {
  }

  // constructor with member value
  Test1_E3::Test1_E3(const Test1_RO value) {
    _m_value = value;
  }

  // assignment operator
  Test1_E3& Test1_E3::operator=(const Test1_E3& a_E3) {
	_m_value = a_E3._m_value;
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E4 member functions

  //constructor
  Test1_E4::Test1_E4(const Test1_E4& a_E4) {
  _m_value = a_E4._m_value;
  }

  //destructor
  Test1_E4::~Test1_E4() {
  }

  // constructor with member value
  Test1_E4::Test1_E4(const Test1_TheO1_ptr value) {
    _m_value = value;
  }

  // assignment operator
  Test1_E4& Test1_E4::operator=(const Test1_E4& a_E4) {
	_m_value = a_E4._m_value;
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E5 member functions

  //constructor
  Test1_E5::Test1_E5(const Test1_E5& a_E5) {
     Test1_A0_copy(_m_value,  a_E5._m_value);
  }

  //destructor
  Test1_E5::~Test1_E5() {
  }

  // constructor with member value
  Test1_E5::Test1_E5(const Test1_A0 value) {
     Test1_A0_copy(_m_value, value);
  }

  // assignment operator
  Test1_E5& Test1_E5::operator=(const Test1_E5& a_E5) {
        Test1_A0_copy(_m_value, a_E5._m_value);
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E6 member functions

  //constructor
  Test1_E6::Test1_E6(const Test1_E6& a_E6) {
  _m_value = a_E6._m_value;
  }

  //destructor
  Test1_E6::~Test1_E6() {
  }

  // constructor with member value
  Test1_E6::Test1_E6(const Test1_TheRS& value) {
    _m_value = value;
  }

  // assignment operator
  Test1_E6& Test1_E6::operator=(const Test1_E6& a_E6) {
	_m_value = a_E6._m_value;
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E7 member functions

  //constructor
  Test1_E7::Test1_E7(const Test1_E7& a_E7) {
  _m_value = a_E7._m_value;
  }

  //destructor
  Test1_E7::~Test1_E7() {
  }

  // constructor with member value
  Test1_E7::Test1_E7(const iluShortCharacter* value) {
    _m_value = value;
  }

  // assignment operator
  Test1_E7& Test1_E7::operator=(const Test1_E7& a_E7) {
	_m_value = a_E7._m_value;
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E8 member functions

  //constructor
  Test1_E8::Test1_E8(const Test1_E8& a_E8) {
     Test1_TheA1_copy(_m_value,  a_E8._m_value);
  }

  //destructor
  Test1_E8::~Test1_E8() {
  }

  // constructor with member value
  Test1_E8::Test1_E8(const Test1_TheA1 value) {
     Test1_TheA1_copy(_m_value, value);
  }

  // assignment operator
  Test1_E8& Test1_E8::operator=(const Test1_E8& a_E8) {
        Test1_TheA1_copy(_m_value, a_E8._m_value);
  return *this;
  }

/////////////////////////////////////////////////
// Test1_E9 member functions

  //constructor
  Test1_E9::Test1_E9(const Test1_E9& a_E9) {
  _m_value = a_E9._m_value;
  }

  //destructor
  Test1_E9::~Test1_E9() {
  }

  // constructor with member value
  Test1_E9::Test1_E9(const Test1_TheR& value) {
    _m_value = value;
  }

  // assignment operator
  Test1_E9& Test1_E9::operator=(const Test1_E9& a_E9) {
	_m_value = a_E9._m_value;
  return *this;
  }

  //member list constructor
  Test1_E9::Test1_E9(
               const Test1_A1  a_a, 
               const Test1_CSS&  a_css, 
               const CORBA_Long&  a_i 
   ) {
     Test1_TheA1_copy(_m_value.a,
                        a_a);
    _m_value.css = a_css;
    _m_value.i = a_i;
   }


////////////////////////////////////////////////////////////////
// Force initialization of Test1_ classes upon load

Test1_initializer Test1_initializer::sm_the_Test1_initializer;

Test1_initializer:: Test1_initializer () {
  ensure_instantiation();  
}

/* CHANGED RETURN FROM int to void * for SUNPRO 5 */
void * Test1_initializer:: ensure_instantiation () {
  iluCppRuntime::iluAddInitializationFunction(Test1_iluInitialize);
  return this;
}
