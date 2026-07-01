
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Unit_H_
  #define __SRIO_Unit_H_
  
//Note corba.hpp includes ilu.hpp, corba-templates.hpp, cppportability.hpp
#include <corba.hpp>
//#include <ilu.hpp>
//#include <corba-templates.hpp>
//#include <cppportability.hpp>



#ifndef CORBA_
  #define CORBA_(name) NAME_INSIDE_SCOPE(CORBA, name)
#endif
#ifndef CORBA
  #define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA, name)
#endif
#ifndef ADD_VARIANT_SUPPORT
  #define ADD_VARIANT_SUPPORT
#endif
#ifndef SRIO_Unit_
  #define SRIO_Unit_(name) NAME_INSIDE_SCOPE(SRIO_Unit,name)
#endif
#ifndef SRIO_Unit
  #define SRIO_Unit(name) NAME_OUTSIDE_SCOPE(SRIO_Unit,name)
#endif

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for SRIO_Unit 
namespace SRIO_Unit {
 
 
     // Declarations for initialization
     NS_EXTERN void iluInitialize();
     NS_EXTERN int g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               p_initialization_function_list;

     class General_Unit;
     typedef General_Unit* General_Unit_ptr;
     typedef iluTemplatableObject_var<General_Unit> General_Unit_var;


//////////////////////////////////////////////////////////////////////
// class General_Unit

// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class General_Unit : public virtual CORBA_(Object) {
      public:
        // Constructs a new General_Unit using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        General_Unit(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_(Boolean) b_within_object_table = ILUCPP_FALSE) :
               iluObject(General_Unit::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static General_Unit_ptr _duplicate(General_Unit_ptr a_ptr);

        static General_Unit_ptr _narrow(CORBA_(Object_ptr) an_object_ptr) {
          return (General_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static General_Unit_ptr _narrow(iluObject* an_object_ptr) {
          return (General_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static General_Unit_ptr _nil();
        General_Unit_ptr _this() { return _duplicate((General_Unit_ptr) this); }

        // IDL specified methods

  #undef NS_EXTERN
  #define NS_EXTERN static

 
 
     typedef iluShortCharacter*     UnitSBH;  
     typedef CORBA_(String_var)     UnitSBH_var;  
     typedef iluShortCharacter*     UnitID;  
     typedef CORBA_(String_var)     UnitID_var;  
     struct UnitInfo;
     typedef iluTemplatableT_var<UnitInfo> UnitInfo_var;

      class UnitInfoSequence;
      typedef iluTemplatableSequence_var<UnitInfoSequence, UnitInfo> UnitInfoSequence_var; 

      class FloatSeq;
      typedef iluTemplatableSequence_var<FloatSeq, CORBA_(Float)> FloatSeq_var; 

      class ShortSeq;
      typedef iluTemplatableSequence_var<ShortSeq, CORBA_(Short)> ShortSeq_var; 

      class UnitIDSeq;
      typedef iluTemplatableSequence_var<UnitIDSeq, CORBA_(String_var)> UnitIDSeq_var; 

     enum UnitMinorMode { UMM_None = 0, UMM_FW_Object = 1, UMM_FW_Track = 2 };

     // declare the typecode instance for UnitMinorMode
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitMinorMode;

     enum UnitMode { UM_None = 0, UM_Follow = 1, UM_Imitate = 2 };

     // declare the typecode instance for UnitMode
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitMode;

     enum UnitRole { UR_Leader = 0, UR_Follower = 1, UR_None = 2 };

     // declare the typecode instance for UnitRole
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitRole;



   ////////////////////////////////////////////////////////////////
   // sequence UnitInfoSequence

   class UnitInfoSequence {

    public:

       // constructors & destructor
        UnitInfoSequence ();
        UnitInfoSequence (CORBA_(ULong max));
        UnitInfoSequence (CORBA_(ULong max), CORBA_(ULong length),
              UnitInfo* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        UnitInfoSequence (const UnitInfoSequence& r_UnitInfoSequence);
       ~UnitInfoSequence();

        // assignment
        UnitInfoSequence& operator= (const UnitInfoSequence& r_UnitInfoSequence);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong len));
		CORBA_(Boolean) release() const;
        UnitInfo* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        UnitInfo const* get_buffer () const;

        // [] operators
        UnitInfo& operator [] (CORBA_(ULong) index);
        const UnitInfo& operator [] (CORBA_(ULong) index) const;

        // memory management
         static UnitInfo* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(UnitInfo* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          UnitInfoSequence& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          UnitInfo* m_buffer;

  };

  // declare the typecode instance for UnitInfoSequence
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitInfoSequence;



   ////////////////////////////////////////////////////////////////
   // structure UnitInfo

   struct UnitInfo {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         UnitInfo();    
         // copy constructor
         UnitInfo(const UnitInfo&  r_a_UnitInfo);   
         // destructor
         ~UnitInfo();
         //assignment operator
         UnitInfo& operator= (const UnitInfo& r_a_UnitInfo);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          UnitInfo& self();

         //member vars
           CORBA_(String_var) uid;
           CORBA_(String_var) sbh;
     };


     // declare the typecode instance for UnitInfo
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitInfo;



   ////////////////////////////////////////////////////////////////
   // sequence FloatSeq

   class FloatSeq {

    public:

       // constructors & destructor
        FloatSeq ();
        FloatSeq (CORBA_(ULong) max);
        FloatSeq (CORBA_(ULong) max, CORBA_(ULong) length,
          CORBA_(Float)* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        FloatSeq (const FloatSeq& r_FloatSeq);
       ~FloatSeq();

        // assignment
        FloatSeq& operator= (const FloatSeq& r_FloatSeq);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        CORBA_(Float)* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        CORBA_(Float) const* get_buffer () const;

        // [] operators
        CORBA_(Float)& operator [] (CORBA_(ULong) index);
        const CORBA_(Float)& operator [] (CORBA_(ULong) index) const;

        // memory management
         static CORBA_(Float)* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(CORBA_(Float)* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          FloatSeq& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          CORBA_(Float)* m_buffer;

  };

  // declare the typecode instance for FloatSeq
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_FloatSeq;



   ////////////////////////////////////////////////////////////////
   // sequence ShortSeq

   class ShortSeq {

    public:

       // constructors & destructor
        ShortSeq ();
        ShortSeq (CORBA_(ULong) max);
        ShortSeq (CORBA_(ULong) max, CORBA_(ULong) length,
              CORBA_(Short)* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        ShortSeq (const ShortSeq& r_ShortSeq);
       ~ShortSeq();

        // assignment
        ShortSeq& operator= (const ShortSeq& r_ShortSeq);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        CORBA_(Short)* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        CORBA_(Short) const* get_buffer () const;

        // [] operators
        CORBA_(Short)& operator [] (CORBA_(ULong) index);
        const CORBA_(Short)& operator [] (CORBA_(ULong) index) const;

        // memory management
         static CORBA_(Short)* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(CORBA_(Short)* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          ShortSeq& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          CORBA_(Short)* m_buffer;

  };

  // declare the typecode instance for ShortSeq
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_ShortSeq;



   ////////////////////////////////////////////////////////////////
   // sequence UnitIDSeq

   class UnitIDSeq {

    public:

       // constructors & destructor
        UnitIDSeq ();
        UnitIDSeq (CORBA_(ULong) max);
        UnitIDSeq (CORBA_(ULong) max, CORBA_(ULong) length,
              iluShortCharacter** data, CORBA_(Boolean) release = ILUCPP_FALSE);
        UnitIDSeq (const UnitIDSeq& r_UnitIDSeq);
       ~UnitIDSeq();

        // assignment
        UnitIDSeq& operator= (const UnitIDSeq& r_UnitIDSeq);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        iluShortCharacter** get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        iluShortCharacter* const* get_buffer () const;

        // [] operators
        CORBA_(String_var)& operator [] (CORBA_(ULong) index);
        const CORBA_(String_var)& operator [] (CORBA_(ULong) index) const;

        // memory management
         static iluShortCharacter** allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(iluShortCharacter** p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          UnitIDSeq& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          iluShortCharacter** m_buffer;
          CORBA_(String_var)* m_varbuffer;

  };

  // declare the typecode instance for UnitIDSeq
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitIDSeq;


  #ifndef CPLUSPLUSMAPPING_NESTEDCLASSES
      #undef NS_EXTERN
      #define NS_EXTERN extern
  #endif

   
       virtual iluShortCharacter* getID(
       ) = 0;
   
       virtual iluShortCharacter* getCosNamingSBH(
       ) = 0;
   
       virtual UnitInfo* getFrontUnitInfo(
       ) = 0;
   
       virtual CORBA_(Boolean) setRole(
          UnitRole  role,
          const iluShortCharacter*  consoleSBH
       ) = 0;
   
       virtual CORBA_(Boolean) setMode(
          UnitMode  mode
       ) = 0;
   
       virtual CORBA_(Boolean) setMinorMode(
          UnitMinorMode  minorMode
       ) = 0;
   
       virtual CORBA_(Boolean) setALeader(
          const iluShortCharacter*  leaderSBH
       ) = 0;
   
       virtual CORBA_(Boolean) registerFollower(
          const iluShortCharacter*  followerUID,
          const iluShortCharacter*  followerSBH
       ) = 0;
   
       virtual CORBA_(Boolean) unregisterFollower(
          const iluShortCharacter*  followerUID
       ) = 0;
   
       virtual CORBA_(Boolean) addRearVehicle(
          const UnitInfo&  rearInfo
       ) = 0;
   
       virtual CORBA_(Boolean) deleteRearVehicle(
          const iluShortCharacter*  uid
       ) = 0;
   
       virtual CORBA_(Boolean) reportDeadVehicle(
          const iluShortCharacter*  uid,
          const iluShortCharacter*  details
       ) = 0;
   
       virtual CORBA_(Boolean) shutDown(
       ) = 0;
   
       virtual CORBA_(Boolean) takePicture(
          CORBA_(Long)  time,
          CORBA_(Long)  procedureStartTime
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static General_Unit_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(General_Unit_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->General_Unit::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        General_Unit();	// default constructor
        virtual ~General_Unit();	 // destructor

   private:
        General_Unit(const General_Unit&);	// copy constructor
        void operator=(const General_Unit&);	// assignment operator

      };

  // declare the typecode instance for General_Unit
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_General_Unit;


//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // initializer class is used to create a single instance that puts the
 // iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class initializer {
    public:
      initializer ();
      void * ensure_instantiation ();
      static initializer sm_the_SRIO_Unit_initializer;
  };
// End the scope for SRIO_Unit
 }

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_SRIO_Unit_CLIENT_ONLY() { \
     SRIO_Unit::initializer::sm_the_SRIO_Unit_initializer.ensure_instantiation();\
     SRIO_Unit_surrogate::General_Unit_initializer::sm_the_surrogate_SRIO_Unit_General_Unit_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Unit_SERVER_ONLY() { \
     SRIO_Unit::initializer::sm_the_SRIO_Unit_initializer.ensure_instantiation();\
     SRIO_Unit_true::General_Unit_initializer::sm_the_true_SRIO_Unit_General_Unit_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Unit_CLIENT_SERVER() { \
     SRIO_Unit::initializer::sm_the_SRIO_Unit_initializer.ensure_instantiation();\
     SRIO_Unit_surrogate::General_Unit_initializer::sm_the_surrogate_SRIO_Unit_General_Unit_initializer.ensure_instantiation(); \
     SRIO_Unit_true::General_Unit_initializer::sm_the_true_SRIO_Unit_General_Unit_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::UnitInfoSequence
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence);

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::UnitInfo
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::UnitInfo& r_SRIO_Unit_General_Unit_UnitInfo);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::UnitInfo& r_SRIO_Unit_General_Unit_UnitInfo);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Unit::General_Unit::UnitInfo& r_SRIO_Unit_General_Unit_UnitInfo);

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::FloatSeq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq);

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::ShortSeq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq);

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit::UnitIDSeq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq);

  // insertion, extraction, and sizing operators for SRIO_Unit::General_Unit_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Unit::General_Unit_var& r_SRIO_Unit_General_Unit_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Unit::General_Unit_var& r_SRIO_Unit_General_Unit_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Unit::General_Unit_var& r_SRIO_Unit_General_Unit_var);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for SRIO_Unit_General_Unit_UnitInfoSequence
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_UnitInfoSequence, ilu_sequence_tk,
        "ilut:m8BRq0bOnb45leg0NOS8ZmQa-ro");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::UnitInfoSequence
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Unit::General_Unit::UnitInfoSequence& r_SRIO_Unit_General_Unit_UnitInfoSequence);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Unit::General_Unit::UnitInfoSequence* p_SRIO_Unit_General_Unit_UnitInfoSequence);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::UnitInfoSequence*& rp_SRIO_Unit_General_Unit_UnitInfoSequence);


  // define the typecode class for SRIO_Unit_General_Unit_UnitInfo
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_UnitInfo, ilu_record_tk,
        "IDL:SRIO_Unit/General_Unit/UnitInfo:1.0");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::UnitInfo
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Unit::General_Unit::UnitInfo& r_SRIO_Unit_General_Unit_UnitInfo);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Unit::General_Unit::UnitInfo* p_SRIO_Unit_General_Unit_UnitInfo);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::UnitInfo*& rp_SRIO_Unit_General_Unit_UnitInfo);


  // define the typecode class for SRIO_Unit_General_Unit_UnitMinorMode
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_UnitMinorMode, ilu_enumeration_tk,
        "IDL:SRIO_Unit/General_Unit/UnitMinorMode:1.0");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::UnitMinorMode
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Unit::General_Unit::UnitMinorMode& r_SRIO_Unit_General_Unit_UnitMinorMode);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::UnitMinorMode& r_SRIO_Unit_General_Unit_UnitMinorMode);


  // define the typecode class for SRIO_Unit_General_Unit_UnitMode
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_UnitMode, ilu_enumeration_tk,
        "IDL:SRIO_Unit/General_Unit/UnitMode:1.0");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::UnitMode
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Unit::General_Unit::UnitMode& r_SRIO_Unit_General_Unit_UnitMode);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::UnitMode& r_SRIO_Unit_General_Unit_UnitMode);


  // define the typecode class for SRIO_Unit_General_Unit_UnitRole
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_UnitRole, ilu_enumeration_tk,
        "IDL:SRIO_Unit/General_Unit/UnitRole:1.0");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::UnitRole
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Unit::General_Unit::UnitRole& r_SRIO_Unit_General_Unit_UnitRole);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::UnitRole& r_SRIO_Unit_General_Unit_UnitRole);


  // define the typecode class for SRIO_Unit_General_Unit_FloatSeq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_FloatSeq, ilu_sequence_tk,
        "ilut:mQ6ToW9sPHwCk-pbHr9ZMf2T7J8");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::FloatSeq
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Unit::General_Unit::FloatSeq& r_SRIO_Unit_General_Unit_FloatSeq);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Unit::General_Unit::FloatSeq* p_SRIO_Unit_General_Unit_FloatSeq);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::FloatSeq*& rp_SRIO_Unit_General_Unit_FloatSeq);


  // define the typecode class for SRIO_Unit_General_Unit_ShortSeq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_ShortSeq, ilu_sequence_tk,
        "ilut:fvIY2xM8RFu7RJSuxiFpgt5crGS");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::ShortSeq
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Unit::General_Unit::ShortSeq& r_SRIO_Unit_General_Unit_ShortSeq);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Unit::General_Unit::ShortSeq* p_SRIO_Unit_General_Unit_ShortSeq);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::ShortSeq*& rp_SRIO_Unit_General_Unit_ShortSeq);


  // define the typecode class for SRIO_Unit_General_Unit_UnitIDSeq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Unit_General_Unit_UnitIDSeq, ilu_sequence_tk,
        "ilut:nMjCFNifl1hE5bdCpxJIGUGP5Hy");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit::UnitIDSeq
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Unit::General_Unit::UnitIDSeq& r_SRIO_Unit_General_Unit_UnitIDSeq);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Unit::General_Unit::UnitIDSeq* p_SRIO_Unit_General_Unit_UnitIDSeq);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Unit::General_Unit::UnitIDSeq*& rp_SRIO_Unit_General_Unit_UnitIDSeq);


  // define the typecode class for SRIO_Unit_General_Unit
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(SRIO_Unit_General_Unit, ilu_object_tk,
        "IDL:SRIO_Unit/General_Unit:1.0");

  // declare the Any insert and extract operators for SRIO_Unit::General_Unit
  void operator<<=(CORBA_(Any)& r_any, SRIO_Unit::General_Unit_ptr p_SRIO_Unit_General_Unit);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Unit::General_Unit_ptr& rp_SRIO_Unit_General_Unit);

#endif
