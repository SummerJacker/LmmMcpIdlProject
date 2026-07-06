
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Monitor_H_
  #define __SRIO_Monitor_H_
  
//Note corba.hpp includes ilu.hpp, corba-templates.hpp, cppportability.hpp
#include <corba.hpp>


#ifndef CORBA_
  #define CORBA_(name) NAME_INSIDE_SCOPE(CORBA, name)
#endif
#ifndef CORBA
  #define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA, name)
#endif
#ifndef ADD_VARIANT_SUPPORT
  #define ADD_VARIANT_SUPPORT
#endif
#ifndef SRIO_Monitor_
  #define SRIO_Monitor_(name) NAME_INSIDE_SCOPE(SRIO_Monitor,name)
#endif
#ifndef SRIO_Monitor
  #define SRIO_Monitor(name) NAME_OUTSIDE_SCOPE(SRIO_Monitor,name)
#endif
  #include "SRIO-Ground-Unit-cpp.hpp" 
  #include "SRIO-Air-Unit-cpp.hpp" 
  #include "SRIO-Console-cpp.hpp" 
  #include "SRIO-Unit-cpp.hpp" 

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for SRIO_Monitor 
namespace SRIO_Monitor {
 
 
     // Declarations for initialization
     NS_EXTERN void iluInitialize();
     NS_EXTERN int g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               p_initialization_function_list;

     class Monitor;
     typedef Monitor* Monitor_ptr;
     typedef iluTemplatableObject_var<Monitor> Monitor_var;


//////////////////////////////////////////////////////////////////////
// class Monitor 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Monitor : public virtual CORBA_(Object) { 
      public:
        // Constructs a new Monitor using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Monitor(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_(Boolean) b_within_object_table = ILUCPP_FALSE) :
               iluObject(Monitor::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Monitor_ptr _duplicate(Monitor_ptr a_ptr);

        static Monitor_ptr _narrow(CORBA_(Object_ptr) an_object_ptr) {
          return (Monitor_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Monitor_ptr _narrow(iluObject* an_object_ptr) {
          return (Monitor_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Monitor_ptr _nil();
        Monitor_ptr _this() { return _duplicate((Monitor_ptr) this); }

        // IDL specified methods

  #undef NS_EXTERN
  #define NS_EXTERN static

 
 
     typedef iluShortCharacter*     FireID;  
     typedef CORBA_(String_var)     FireID_var;  
      class PictureFlow;
      typedef iluTemplatableSequence_var<PictureFlow, CORBA_(Octet)> PictureFlow_var; 

     struct PictureInfo;
     typedef iluTemplatableT_var<PictureInfo> PictureInfo_var;

     enum MissionSituation { Success = 0, StillBurning = 1, Locating = 2, Processing = 3 };

     // declare the typecode instance for MissionSituation
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_MissionSituation;

     enum BackHomeReason { LowBattery = 0, EmptyLoad = 1 };

     // declare the typecode instance for BackHomeReason
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_BackHomeReason;

     struct CompleteUnitInfo;
     typedef iluTemplatableT_var<CompleteUnitInfo> CompleteUnitInfo_var;

     class CurrentUnitInfo; 
     typedef iluTemplatableT_var<CurrentUnitInfo> CurrentUnitInfo_var;

     enum UnitType { UnitGroundType = 0, UnitAirType = 1 };

     // declare the typecode instance for UnitType
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitType;

     struct UnitState;
     typedef iluTemplatableT_var<UnitState> UnitState_var;



   ////////////////////////////////////////////////////////////////
   // sequence PictureFlow

   class PictureFlow {

    public:

       // constructors & destructor
        PictureFlow ();
        PictureFlow (CORBA_(ULong) max);
        PictureFlow (CORBA_(ULong) max, CORBA_(ULong) length,
              CORBA_(Octet)* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        PictureFlow (const PictureFlow& r_PictureFlow);
       ~PictureFlow();

        // assignment
        PictureFlow& operator= (const PictureFlow& r_PictureFlow);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        CORBA_(Octet)* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        CORBA_(Octet) const* get_buffer () const;

        // [] operators
        CORBA_(Octet)& operator [] (CORBA_(ULong) index);
        const CORBA_(Octet)& operator [] (CORBA_(ULong) index) const;

        // memory management
         static CORBA_(Octet)* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(CORBA_(Octet)* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          PictureFlow& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          CORBA_(Octet)* m_buffer;

  };

  // declare the typecode instance for PictureFlow
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_PictureFlow;



 class CurrentUnitInfo {
                
         // insertion, extraction, and sizing operators for CurrentUnitInfo
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        CurrentUnitInfo();
        CurrentUnitInfo(const CurrentUnitInfo& r_CurrentUnitInfo);                   
        ~CurrentUnitInfo();
                   
        // assignment
        CurrentUnitInfo& operator= (const CurrentUnitInfo& r_CurrentUnitInfo);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         CurrentUnitInfo& self();
                   
        // accessors and modifiers
        UnitType _d () const;
        void _d (UnitType new_d);

       void groundUnitInfo(const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo & an_groundUnitInfo); 
       const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& groundUnitInfo() const;
       SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& groundUnitInfo();
       void airUnitInfo(const SRIO_Air_Unit::Air_Unit::AirUnitInfo & an_airUnitInfo); 
       const SRIO_Air_Unit::Air_Unit::AirUnitInfo& airUnitInfo() const;
       SRIO_Air_Unit::Air_Unit::AirUnitInfo& airUnitInfo();
         void unset();
         union {
                 SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo* m_groundUnitInfo;    
                 SRIO_Air_Unit::Air_Unit::AirUnitInfo* m_airUnitInfo;    
        };
                
        UnitType    m_discriminator;
        CORBA_(Boolean)     m_b_beenset;
                   
 };


     // declare the typecode instance for CurrentUnitInfo
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_CurrentUnitInfo;



   ////////////////////////////////////////////////////////////////
   // structure UnitState

   struct UnitState {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         UnitState();    
         // copy constructor
         UnitState(const UnitState&  r_a_UnitState);   
         // destructor
         ~UnitState();
         //assignment operator
         UnitState& operator= (const UnitState& r_a_UnitState);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          UnitState& self();

         //member vars
           CORBA_(Short) health;
           CORBA_(Short) battery;
     };


     // declare the typecode instance for UnitState
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitState;



   ////////////////////////////////////////////////////////////////
   // structure PictureInfo

   struct PictureInfo {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         PictureInfo();    
         // copy constructor
         PictureInfo(const PictureInfo&  r_a_PictureInfo);   
         // destructor
         ~PictureInfo();
         //assignment operator
         PictureInfo& operator= (const PictureInfo& r_a_PictureInfo);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          PictureInfo& self();

         //member vars
           CORBA_(String_var) picturName;
           PictureFlow_var pic;
           CurrentUnitInfo cui;
           CORBA_(Short) responseTime;
     };


     // declare the typecode instance for PictureInfo
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_PictureInfo;



   ////////////////////////////////////////////////////////////////
   // structure CompleteUnitInfo

   struct CompleteUnitInfo {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         CompleteUnitInfo();    
         // copy constructor
         CompleteUnitInfo(const CompleteUnitInfo&  r_a_CompleteUnitInfo);   
         // destructor
         ~CompleteUnitInfo();
         //assignment operator
         CompleteUnitInfo& operator= (const CompleteUnitInfo& r_a_CompleteUnitInfo);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          CompleteUnitInfo& self();

         //member vars
           UnitState us;
           CurrentUnitInfo cui;
     };


     // declare the typecode instance for CompleteUnitInfo
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_CompleteUnitInfo;


  #ifndef CPLUSPLUSMAPPING_NESTEDCLASSES
      #undef NS_EXTERN
      #define NS_EXTERN extern
  #endif

   
       virtual CORBA_(Boolean) sendUnitInfo(
          const CompleteUnitInfo&  unitInfo
       ) = 0;
   
       virtual CORBA_(Boolean) sendTrapPoint(
          const SRIO_Console::Console::TrapPoint&  tp
       ) = 0;
   
       virtual CORBA_(Boolean) sendFireLocation(
          const iluShortCharacter*  fid,
          const SRIO_Ground_Unit::Ground_Unit::Point2D&  fp,
          CORBA_(Short)  responseTime
       ) = 0;
   
       virtual CORBA_(Boolean) foundFire(
          const iluShortCharacter*  fid,
          const PictureInfo&  pi
       ) = 0;
   
       virtual CORBA_(Boolean) confirmAction(
          const iluShortCharacter*  fid,
          CORBA_(Short)  responseTime
       ) = 0;
   
       virtual CORBA_(Boolean) backHome(
          const iluShortCharacter*  uid,
          BackHomeReason  bhr
       ) = 0;
   
       virtual CORBA_(Boolean) sendMissionState(
          const iluShortCharacter*  fid,
          MissionSituation  ms
       ) = 0;
   
       virtual CORBA_(Boolean) sendPicture(
          const iluShortCharacter*  pictureName,
          const PictureFlow&  pic,
          CORBA_(Long)  time,
          CORBA_(Long)  procedureStartTime
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Monitor_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Monitor_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Monitor::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Monitor();	// default constructor
        virtual ~Monitor();	 // destructor

   private:
        Monitor(const Monitor&);	// copy constructor
        void operator=(const Monitor&);	// assignment operator

      };

  // declare the typecode instance for Monitor
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_Monitor;


//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // initializer class is used to create a single instance that puts the
 // iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class initializer {
    public:
      initializer ();
      void * ensure_instantiation ();
      static initializer sm_the_SRIO_Monitor_initializer;
  };
// End the scope for SRIO_Monitor
 }

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_SRIO_Monitor_CLIENT_ONLY() { \
     SRIO_Monitor::initializer::sm_the_SRIO_Monitor_initializer.ensure_instantiation();\
     SRIO_Monitor_surrogate::Monitor_initializer::sm_the_surrogate_SRIO_Monitor_Monitor_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Monitor_SERVER_ONLY() { \
     SRIO_Monitor::initializer::sm_the_SRIO_Monitor_initializer.ensure_instantiation();\
     SRIO_Monitor_true::Monitor_initializer::sm_the_true_SRIO_Monitor_Monitor_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Monitor_CLIENT_SERVER() { \
     SRIO_Monitor::initializer::sm_the_SRIO_Monitor_initializer.ensure_instantiation();\
     SRIO_Monitor_surrogate::Monitor_initializer::sm_the_surrogate_SRIO_Monitor_Monitor_initializer.ensure_instantiation(); \
     SRIO_Monitor_true::Monitor_initializer::sm_the_true_SRIO_Monitor_Monitor_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::PictureInfo
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::PictureInfo& r_SRIO_Monitor_Monitor_PictureInfo);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::PictureInfo& r_SRIO_Monitor_Monitor_PictureInfo);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Monitor::Monitor::PictureInfo& r_SRIO_Monitor_Monitor_PictureInfo);

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::PictureFlow
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow);

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::CompleteUnitInfo
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::CompleteUnitInfo& r_SRIO_Monitor_Monitor_CompleteUnitInfo);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::CompleteUnitInfo& r_SRIO_Monitor_Monitor_CompleteUnitInfo);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Monitor::Monitor::CompleteUnitInfo& r_SRIO_Monitor_Monitor_CompleteUnitInfo);

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::CurrentUnitInfo
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::CurrentUnitInfo& r_SRIO_Monitor_Monitor_CurrentUnitInfo);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::CurrentUnitInfo& r_SRIO_Monitor_Monitor_CurrentUnitInfo);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Monitor::Monitor::CurrentUnitInfo& r_SRIO_Monitor_Monitor_CurrentUnitInfo);

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor::UnitState
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::UnitState& r_SRIO_Monitor_Monitor_UnitState);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Monitor::Monitor::UnitState& r_SRIO_Monitor_Monitor_UnitState);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Monitor::Monitor::UnitState& r_SRIO_Monitor_Monitor_UnitState);

  // insertion, extraction, and sizing operators for SRIO_Monitor::Monitor_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Monitor::Monitor_var& r_SRIO_Monitor_Monitor_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Monitor::Monitor_var& r_SRIO_Monitor_Monitor_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Monitor::Monitor_var& r_SRIO_Monitor_Monitor_var);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for SRIO_Monitor_Monitor_PictureInfo
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_PictureInfo, ilu_record_tk,
        "IDL:SRIO_Monitor/Monitor/PictureInfo:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::PictureInfo
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Monitor::Monitor::PictureInfo& r_SRIO_Monitor_Monitor_PictureInfo);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Monitor::Monitor::PictureInfo* p_SRIO_Monitor_Monitor_PictureInfo);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::PictureInfo*& rp_SRIO_Monitor_Monitor_PictureInfo);


  // define the typecode class for SRIO_Monitor_Monitor_PictureFlow
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_PictureFlow, ilu_sequence_tk,
        "ilut:ndKwf8vfmBTV3Mjc04YR0a3tZcA");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::PictureFlow
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Monitor::Monitor::PictureFlow& r_SRIO_Monitor_Monitor_PictureFlow);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Monitor::Monitor::PictureFlow* p_SRIO_Monitor_Monitor_PictureFlow);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::PictureFlow*& rp_SRIO_Monitor_Monitor_PictureFlow);


  // define the typecode class for SRIO_Monitor_Monitor_MissionSituation
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_MissionSituation, ilu_enumeration_tk,
        "IDL:SRIO_Monitor/Monitor/MissionSituation:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::MissionSituation
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Monitor::Monitor::MissionSituation& r_SRIO_Monitor_Monitor_MissionSituation);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::MissionSituation& r_SRIO_Monitor_Monitor_MissionSituation);


  // define the typecode class for SRIO_Monitor_Monitor_BackHomeReason
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_BackHomeReason, ilu_enumeration_tk,
        "IDL:SRIO_Monitor/Monitor/BackHomeReason:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::BackHomeReason
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Monitor::Monitor::BackHomeReason& r_SRIO_Monitor_Monitor_BackHomeReason);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::BackHomeReason& r_SRIO_Monitor_Monitor_BackHomeReason);


  // define the typecode class for SRIO_Monitor_Monitor_CompleteUnitInfo
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_CompleteUnitInfo, ilu_record_tk,
        "IDL:SRIO_Monitor/Monitor/CompleteUnitInfo:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::CompleteUnitInfo
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Monitor::Monitor::CompleteUnitInfo& r_SRIO_Monitor_Monitor_CompleteUnitInfo);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Monitor::Monitor::CompleteUnitInfo* p_SRIO_Monitor_Monitor_CompleteUnitInfo);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::CompleteUnitInfo*& rp_SRIO_Monitor_Monitor_CompleteUnitInfo);


  // define the typecode class for SRIO_Monitor_Monitor_CurrentUnitInfo
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_CurrentUnitInfo, ilu_union_tk,
        "IDL:SRIO_Monitor/Monitor/CurrentUnitInfo:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::CurrentUnitInfo
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Monitor::Monitor::CurrentUnitInfo& r_SRIO_Monitor_Monitor_CurrentUnitInfo);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Monitor::Monitor::CurrentUnitInfo* p_SRIO_Monitor_Monitor_CurrentUnitInfo);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::CurrentUnitInfo*& rp_SRIO_Monitor_Monitor_CurrentUnitInfo);


  // define the typecode class for SRIO_Monitor_Monitor_UnitType
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_UnitType, ilu_enumeration_tk,
        "IDL:SRIO_Monitor/Monitor/UnitType:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::UnitType
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Monitor::Monitor::UnitType& r_SRIO_Monitor_Monitor_UnitType);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::UnitType& r_SRIO_Monitor_Monitor_UnitType);


  // define the typecode class for SRIO_Monitor_Monitor_UnitState
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Monitor_Monitor_UnitState, ilu_record_tk,
        "IDL:SRIO_Monitor/Monitor/UnitState:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor::UnitState
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Monitor::Monitor::UnitState& r_SRIO_Monitor_Monitor_UnitState);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Monitor::Monitor::UnitState* p_SRIO_Monitor_Monitor_UnitState);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Monitor::Monitor::UnitState*& rp_SRIO_Monitor_Monitor_UnitState);


  // define the typecode class for SRIO_Monitor_Monitor
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(SRIO_Monitor_Monitor, ilu_object_tk,
        "IDL:SRIO_Monitor/Monitor:1.0");

  // declare the Any insert and extract operators for SRIO_Monitor::Monitor
  void operator<<=(CORBA_(Any)& r_any, SRIO_Monitor::Monitor_ptr p_SRIO_Monitor_Monitor);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Monitor::Monitor_ptr& rp_SRIO_Monitor_Monitor);

#endif
