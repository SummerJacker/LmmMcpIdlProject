
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Console_H_
  #define __SRIO_Console_H_
  
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
#ifndef SRIO_Console_
  #define SRIO_Console_(name) NAME_INSIDE_SCOPE(SRIO_Console,name)
#endif
#ifndef SRIO_Console
  #define SRIO_Console(name) NAME_OUTSIDE_SCOPE(SRIO_Console,name)
#endif
  #include "SRIO-Unit-cpp.hpp" 
  #include "SRIO-Ground-Unit-cpp.hpp" 
  #include "SRIO-Air-Unit-cpp.hpp" 

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for SRIO_Console 
namespace SRIO_Console {
 
 
     // Declarations for initialization
     NS_EXTERN void iluInitialize();
     NS_EXTERN int g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               p_initialization_function_list;

     class Console;
     typedef Console* Console_ptr;
     typedef iluTemplatableObject_var<Console> Console_var;


//////////////////////////////////////////////////////////////////////
// class Console 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Console : public virtual CORBA_(Object) { 
      public:
		// Constructs a new Console using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Console(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_(Boolean) b_within_object_table = ILUCPP_FALSE) :
               iluObject(Console::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Console_ptr _duplicate(Console_ptr a_ptr);

        static Console_ptr _narrow(CORBA_(Object_ptr) an_object_ptr) {
          return (Console_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Console_ptr _narrow(iluObject* an_object_ptr) {
          return (Console_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Console_ptr _nil();
        Console_ptr _this() { return _duplicate((Console_ptr) this); }

        // IDL specified methods

  #undef NS_EXTERN
  #define NS_EXTERN static

 
    class AlreadyBind;
    class NotFound;
 
    #define g_SRIO_Console_Console_AlreadyBind_index     0
    #define g_SRIO_Console_Console_NotFound_index     1
     class TrapPoint; 
     typedef iluTemplatableT_var<TrapPoint> TrapPoint_var;

     class Point; 
     typedef iluTemplatableT_var<Point> Point_var;

     struct CosInfoNode;
     typedef iluTemplatableT_var<CosInfoNode> CosInfoNode_var;

      class TrapPointSequence;
      typedef iluTemplatableSequence_var<TrapPointSequence, TrapPoint> TrapPointSequence_var; 

      class PointSeq;
      typedef iluTemplatableSequence_var<PointSeq, Point> PointSeq_var; 

      class CosInfoSeq;
      typedef iluTemplatableSequence_var<CosInfoSeq, CosInfoNode> CosInfoSeq_var; 

     class Message; 
     typedef iluTemplatableT_var<Message> Message_var;

     enum Operation { OP_SetCosInfo = 0, OP_Bind = 1, OP_Unbind = 2, OP_Opened = 3, OP_Closed = 4, OP_ReportTrap = 5, OP_AddTrap = 6 };

     // declare the typecode instance for Operation
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Operation;

     struct UnbindData;
     typedef iluTemplatableT_var<UnbindData> UnbindData_var;

     enum TrapType { TrapGroundType = 0, TrapAirType = 1 };

     // declare the typecode instance for TrapType
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_TrapType;

     enum PointType { PointGroundType = 0, PointAirType = 1 };

     // declare the typecode instance for PointType
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_PointType;

     enum TrackMode { RouteTrack = 0, ObjectTrack = 1 };

     // declare the typecode instance for TrackMode
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_TrackMode;

     enum FormationType { OneLine = 0, Matrix = 1, WildGoose = 2 };

     // declare the typecode instance for FormationType
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_FormationType;

     enum FormationState { FormationImplement = 0, FormationSuspend = 1, FormationSuccess = 2, FormationFail = 3 };

     // declare the typecode instance for FormationState
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_FormationState;

     class MissionStateData; 
     typedef iluTemplatableT_var<MissionStateData> MissionStateData_var;

     enum MissionState { MissionImplement = 0, MissionSuspend = 1, MissionSuccess = 2, MissionFail = 3, MissionCancel = 4 };

     // declare the typecode instance for MissionState
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_MissionState;

     enum Role { Follower = 0, Leader = 1 };

     // declare the typecode instance for Role
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Role;



   ////////////////////////////////////////////////////////////////
   // sequence TrapPointSequence

   class TrapPointSequence {

    public:

       // constructors & destructor
        TrapPointSequence ();
        TrapPointSequence (CORBA_(ULong) max);
        TrapPointSequence (CORBA_(ULong) max, CORBA_(ULong) length,
              TrapPoint* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        TrapPointSequence (const TrapPointSequence& r_TrapPointSequence);
        ~TrapPointSequence();

        // assignment
        TrapPointSequence& operator= (const TrapPointSequence& r_TrapPointSequence);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        TrapPoint* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        TrapPoint const* get_buffer () const;

        // [] operators
        TrapPoint& operator [] (CORBA_(ULong) index);
        const TrapPoint& operator [] (CORBA_(ULong) index) const;

        // memory management
         static TrapPoint* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(TrapPoint* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          TrapPointSequence& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          TrapPoint* m_buffer;

  };

  // declare the typecode instance for TrapPointSequence
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_TrapPointSequence;



   ////////////////////////////////////////////////////////////////
   // sequence PointSeq

   class PointSeq {

    public:

       // constructors & destructor
        PointSeq ();
        PointSeq (CORBA_(ULong) max);
        PointSeq (CORBA_(ULong) max, CORBA_(ULong) length,
              Point* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        PointSeq (const PointSeq& r_PointSeq);
        ~PointSeq();

        // assignment
        PointSeq& operator= (const PointSeq& r_PointSeq);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        Point* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        Point const* get_buffer () const;

        // [] operators
        Point& operator [] (CORBA_(ULong) index);
        const Point& operator [] (CORBA_(ULong) index) const;

        // memory management
         static Point* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(Point* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          PointSeq& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          Point* m_buffer;

  };

  // declare the typecode instance for PointSeq
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_PointSeq;



   ////////////////////////////////////////////////////////////////
   // structure UnbindData

   struct UnbindData {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         UnbindData();    
         // copy constructor
         UnbindData(const UnbindData&  r_a_UnbindData);   
         // destructor
         ~UnbindData();
         //assignment operator
         UnbindData& operator= (const UnbindData& r_a_UnbindData);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          UnbindData& self();

         //member vars
           CORBA_(String_var) uid;
           CORBA_(String_var) details;
     };


     // declare the typecode instance for UnbindData
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnbindData;



 class TrapPoint {
                
         // insertion, extraction, and sizing operators for TrapPoint
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        TrapPoint();
        TrapPoint(const TrapPoint& r_TrapPoint);                   
        ~TrapPoint();
                   
        // assignment
        TrapPoint& operator= (const TrapPoint& r_TrapPoint);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         TrapPoint& self();
                   
        // accessors and modifiers
        TrapType _d () const;
        void _d (TrapType new_d);

       void trapPoint2D(const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D & an_trapPoint2D); 
       const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& trapPoint2D() const;
       SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& trapPoint2D();
       void trapPoint3D(const SRIO_Air_Unit::Air_Unit::TrapPoint3D & an_trapPoint3D); 
       const SRIO_Air_Unit::Air_Unit::TrapPoint3D& trapPoint3D() const;
       SRIO_Air_Unit::Air_Unit::TrapPoint3D& trapPoint3D();
         void unset();
         union {
                 SRIO_Ground_Unit::Ground_Unit::TrapPoint2D* m_trapPoint2D;    
                 SRIO_Air_Unit::Air_Unit::TrapPoint3D* m_trapPoint3D;    
        };
                
        TrapType    m_discriminator;
        CORBA_(Boolean)     m_b_beenset;
                   
 };


     // declare the typecode instance for TrapPoint
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_TrapPoint;



 class Point {
                
         // insertion, extraction, and sizing operators for Point
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Point();
        Point(const Point& r_Point);                   
        ~Point();
                   
        // assignment
        Point& operator= (const Point& r_Point);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Point& self();
                   
        // accessors and modifiers
        PointType _d () const;
        void _d (PointType new_d);

       void p2D(const SRIO_Ground_Unit::Ground_Unit::Point2D & an_p2D); 
       const SRIO_Ground_Unit::Ground_Unit::Point2D& p2D() const;
       SRIO_Ground_Unit::Ground_Unit::Point2D& p2D();
       void p3D(const SRIO_Air_Unit::Air_Unit::Point3D & an_p3D); 
       const SRIO_Air_Unit::Air_Unit::Point3D& p3D() const;
       SRIO_Air_Unit::Air_Unit::Point3D& p3D();
         void unset();
         union {
                 SRIO_Ground_Unit::Ground_Unit::Point2D* m_p2D;    
                 SRIO_Air_Unit::Air_Unit::Point3D* m_p3D;    
        };
                
        PointType    m_discriminator;
        CORBA_(Boolean)     m_b_beenset;
                   
 };


     // declare the typecode instance for Point
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Point;



   ////////////////////////////////////////////////////////////////
   // sequence CosInfoSeq

   class CosInfoSeq {

    public:

       // constructors & destructor
        CosInfoSeq ();
        CosInfoSeq (CORBA_(ULong) max);
        CosInfoSeq (CORBA_(ULong) max, CORBA_(ULong) length,
              CosInfoNode* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        CosInfoSeq (const CosInfoSeq& r_CosInfoSeq);
        ~CosInfoSeq();

        // assignment
        CosInfoSeq& operator= (const CosInfoSeq& r_CosInfoSeq);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        CosInfoNode* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        CosInfoNode const* get_buffer () const;

        // [] operators
        CosInfoNode& operator [] (CORBA_(ULong) index);
        const CosInfoNode& operator [] (CORBA_(ULong) index) const;

        // memory management
         static CosInfoNode* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(CosInfoNode* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          CosInfoSeq& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          CosInfoNode* m_buffer;

  };

  // declare the typecode instance for CosInfoSeq
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_CosInfoSeq;



   ////////////////////////////////////////////////////////////////
   // structure CosInfoNode

   struct CosInfoNode {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         CosInfoNode();    
         // copy constructor
         CosInfoNode(const CosInfoNode&  r_a_CosInfoNode);   
         // destructor
         ~CosInfoNode();
         //assignment operator
         CosInfoNode& operator= (const CosInfoNode& r_a_CosInfoNode);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          CosInfoNode& self();

         //member vars
           CORBA_(String_var) uid;
           CORBA_(String_var) sbh;
     };


     // declare the typecode instance for CosInfoNode
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_CosInfoNode;



 class MissionStateData {
                
         // insertion, extraction, and sizing operators for MissionStateData
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        MissionStateData();
        MissionStateData(const MissionStateData& r_MissionStateData);                   
        ~MissionStateData();
                   
        // assignment
        MissionStateData& operator= (const MissionStateData& r_MissionStateData);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         MissionStateData& self();
                   
        // accessors and modifiers
        MissionState _d () const;
        void _d (MissionState new_d);

        void time (CORBA_(Short) an_time);
        CORBA_(Short) time () const;

         void unset();
         union {
                 CORBA_(Short) m_time;    
        };
                
        MissionState    m_discriminator;
        CORBA_(Boolean)     m_b_beenset;
                   
 };


     // declare the typecode instance for MissionStateData
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_MissionStateData;



 class Message {
                
         // insertion, extraction, and sizing operators for Message
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Message();
        Message(const Message& r_Message);                   
        ~Message();
                   
        // assignment
        Message& operator= (const Message& r_Message);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Message& self();
                   
        // accessors and modifiers
        Operation _d () const;
        void _d (Operation new_d);

       void infoSeq(const CosInfoSeq & an_infoSeq); 
       const CosInfoSeq& infoSeq() const;
       CosInfoSeq& infoSeq();
       void bindInfo(const CosInfoNode & an_bindInfo); 
       const CosInfoNode& bindInfo() const;
       CosInfoNode& bindInfo();
       void unbindInfo(const UnbindData & an_unbindInfo); 
       const UnbindData& unbindInfo() const;
       UnbindData& unbindInfo();
       void tp(const TrapPoint & an_tp); 
       const TrapPoint& tp() const;
       TrapPoint& tp();
        void details(iluShortCharacter *an_details);
        void details(const iluShortCharacter *an_details );
        void details(const CORBA_(String_var)& an_details );
        const iluShortCharacter *details() const;  

         void unset();
         union {
                 CosInfoSeq* m_infoSeq;    
                 CosInfoNode* m_bindInfo;    
                 UnbindData* m_unbindInfo;    
                 TrapPoint* m_tp;    
                 CORBA_(String_var)* m_details;    
        };
                
        Operation    m_discriminator;
        CORBA_(Boolean)     m_b_beenset;
                   
 };


     // declare the typecode instance for Message
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Message;


///////////////////////////////////////////////////////////////////
// Exception AlreadyBind 
 
  class AlreadyBind : public CORBA_(UserException){
    public:
      // constructors and destructors
      AlreadyBind() { };
      AlreadyBind(const AlreadyBind& a_AlreadyBind);
      ~AlreadyBind();

      void _raise() { throw *this; };

      // assignment operator
      AlreadyBind& operator=(const AlreadyBind& a_AlreadyBind);
  };

///////////////////////////////////////////////////////////////////
// Exception NotFound 
 
  class NotFound : public CORBA_(UserException){
    public:
      // constructors and destructors
      NotFound() { };
      NotFound(const NotFound& a_NotFound);
      ~NotFound();

      void _raise() { throw *this; };

      // assignment operator
      NotFound& operator=(const NotFound& a_NotFound);
  };

  #ifndef CPLUSPLUSMAPPING_NESTEDCLASSES
      #undef NS_EXTERN
      #define NS_EXTERN extern
  #endif

   
       virtual CosInfoSeq* getCosNamingInfo(
       ) = 0;
   
       virtual CORBA_(Boolean) sendMsg(
          const Message&  m
       ) = 0;
   
       virtual CORBA_(Boolean) bind(
          const iluShortCharacter*  uid,
          const iluShortCharacter*  sbh
       ) = 0;
   
       virtual CORBA_(Boolean) unbind(
          const iluShortCharacter*  uid,
          const iluShortCharacter*  details
       ) = 0;
   
       virtual CORBA_(Boolean) rebind(
          const iluShortCharacter*  uid,
          const iluShortCharacter*  sbh
       ) = 0;
   
       virtual CORBA_(Boolean) setNickname(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo,
          const iluShortCharacter*  newName
       ) = 0;
   
       virtual CORBA_(Boolean) setPosition(
          const iluShortCharacter*  name,
          const Point&  p
       ) = 0;
   
       virtual CORBA_(Boolean) addGoalPoint(
          const Point&  p
       ) = 0;
   
       virtual CORBA_(Boolean) setGoalPoint(
          const Point&  p
       ) = 0;
   
       virtual CORBA_(Boolean) setRole(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo,
          Role  r
       ) = 0;
   
       virtual CORBA_(Boolean) cancelRole(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
       ) = 0;
   
       virtual CORBA_(Boolean) setTrapPoint(
          const TrapPoint&  p
       ) = 0;
   
       virtual CORBA_(Boolean) setFollow(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo1,
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo2
       ) = 0;
   
       virtual CORBA_(Boolean) setFormationType(
          FormationType  f
       ) = 0;
   
       virtual CORBA_(Boolean) setTrackMode(
          TrackMode  tm
       ) = 0;
   
       virtual SRIO_Unit::General_Unit::UnitInfo* getCurrentUnit(
       ) = 0;
   
       virtual CORBA_(Short) getUnitNum(
       ) = 0;
   
       virtual CORBA_(Short) getFormationNum(
       ) = 0;
   
       virtual CORBA_(Short) getTrapNum(
       ) = 0;
   
       virtual FormationType getFormationType(
       ) = 0;
   
       virtual FormationState getFormationState(
       ) = 0;
   
       virtual MissionState getMissionState(
       ) = 0;
   
       virtual Point getUnitPoint(
          const iluShortCharacter*  name
       ) = 0;
   
       virtual SRIO_Unit::General_Unit::UnitInfo* getByName(
          const iluShortCharacter*  name
       ) = 0;
   
       virtual Point getLeaderPoint(
       ) = 0;
   
       virtual PointSeq* getPointSeq(
       ) = 0;
   
       virtual CORBA_(Boolean) cancelFormation(
       ) = 0;
   
       virtual CORBA_(Boolean) setLeaderSuspend(
       ) = 0;
   
       virtual CORBA_(Boolean) recoveryLeaderAction(
       ) = 0;
   
       virtual CORBA_(Boolean) addUnitFormation(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
       ) = 0;
   
       virtual CORBA_(Boolean) deleteUnitFormation(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
       ) = 0;
   
       virtual CORBA_(Boolean) setUnitFault(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
       ) = 0;
   
       virtual CORBA_(Boolean) setUnitFaultPosition(
          const SRIO_Unit::General_Unit::UnitInfo&  uinfo
       ) = 0;
   
       virtual CORBA_(Boolean) setFormationState(
          FormationState  fs
       ) = 0;
   
       virtual CORBA_(Boolean) setMissionState(
          const MissionStateData&  msd
       ) = 0;

		// Simple Object Lookup
        static Console_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Console_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Console::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Console();	// default constructor used for abstract or local interface 
        virtual ~Console();	 // destructor

   private:
        Console(const Console&);	// copy constructor
        void operator=(const Console&);	// assignment operator

      };

  // declare the typecode instance for Console
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_Console;


//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // initializer class is used to create a single instance that puts the
 // iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class initializer {
    public:
      initializer ();
      void * ensure_instantiation ();
      static initializer sm_the_SRIO_Console_initializer;
  };
// End the scope for SRIO_Console
 }

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_SRIO_Console_CLIENT_ONLY() { \
     SRIO_Console::initializer::sm_the_SRIO_Console_initializer.ensure_instantiation();\
     SRIO_Console_surrogate::Console_initializer::sm_the_surrogate_SRIO_Console_Console_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Console_SERVER_ONLY() { \
     SRIO_Console::initializer::sm_the_SRIO_Console_initializer.ensure_instantiation();\
     SRIO_Console_true::Console_initializer::sm_the_true_SRIO_Console_Console_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Console_CLIENT_SERVER() { \
     SRIO_Console::initializer::sm_the_SRIO_Console_initializer.ensure_instantiation();\
     SRIO_Console_surrogate::Console_initializer::sm_the_surrogate_SRIO_Console_Console_initializer.ensure_instantiation(); \
     SRIO_Console_true::Console_initializer::sm_the_true_SRIO_Console_Console_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for SRIO_Console::Console::TrapPointSequence
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::PointSeq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::Message
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::Message& r_SRIO_Console_Console_Message);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::Message& r_SRIO_Console_Console_Message);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::Message& r_SRIO_Console_Console_Message);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::UnbindData
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::UnbindData& r_SRIO_Console_Console_UnbindData);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::UnbindData& r_SRIO_Console_Console_UnbindData);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::UnbindData& r_SRIO_Console_Console_UnbindData);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::TrapPoint
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::TrapPoint& r_SRIO_Console_Console_TrapPoint);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::TrapPoint& r_SRIO_Console_Console_TrapPoint);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::TrapPoint& r_SRIO_Console_Console_TrapPoint);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::Point
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::Point& r_SRIO_Console_Console_Point);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::Point& r_SRIO_Console_Console_Point);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::Point& r_SRIO_Console_Console_Point);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::CosInfoSeq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::CosInfoNode
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::CosInfoNode& r_SRIO_Console_Console_CosInfoNode);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::CosInfoNode& r_SRIO_Console_Console_CosInfoNode);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::CosInfoNode& r_SRIO_Console_Console_CosInfoNode);

  // insertion, extraction, and sizing operators for SRIO_Console::Console::MissionStateData
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console::MissionStateData& r_SRIO_Console_Console_MissionStateData);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console::MissionStateData& r_SRIO_Console_Console_MissionStateData);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console::MissionStateData& r_SRIO_Console_Console_MissionStateData);

  // insertion, extraction, and sizing operators for SRIO_Console::Console_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Console::Console_var& r_SRIO_Console_Console_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Console::Console_var& r_SRIO_Console_Console_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Console::Console_var& r_SRIO_Console_Console_var);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for SRIO_Console_Console_TrapPointSequence
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_TrapPointSequence, ilu_sequence_tk,
        "ilut:gHc1kz+yFeMFDkYJvZNl96UtWV3");

  // declare the Any insert and extract operators for SRIO_Console::Console::TrapPointSequence
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::TrapPointSequence& r_SRIO_Console_Console_TrapPointSequence);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::TrapPointSequence* p_SRIO_Console_Console_TrapPointSequence);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::TrapPointSequence*& rp_SRIO_Console_Console_TrapPointSequence);


  // define the typecode class for SRIO_Console_Console_PointSeq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_PointSeq, ilu_sequence_tk,
        "ilut:bbdqUgLV+vqK3pHn-j0IdQmOsTn");

  // declare the Any insert and extract operators for SRIO_Console::Console::PointSeq
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::PointSeq& r_SRIO_Console_Console_PointSeq);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::PointSeq* p_SRIO_Console_Console_PointSeq);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::PointSeq*& rp_SRIO_Console_Console_PointSeq);


  // define the typecode class for SRIO_Console_Console_Message
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_Message, ilu_union_tk,
        "IDL:SRIO_Console/Console/Message:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::Message
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::Message& r_SRIO_Console_Console_Message);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::Message* p_SRIO_Console_Console_Message);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::Message*& rp_SRIO_Console_Console_Message);


  // define the typecode class for SRIO_Console_Console_UnbindData
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_UnbindData, ilu_record_tk,
        "IDL:SRIO_Console/Console/UnbindData:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::UnbindData
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::UnbindData& r_SRIO_Console_Console_UnbindData);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::UnbindData* p_SRIO_Console_Console_UnbindData);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::UnbindData*& rp_SRIO_Console_Console_UnbindData);


  // define the typecode class for SRIO_Console_Console_Operation
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_Operation, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/Operation:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::Operation
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::Operation& r_SRIO_Console_Console_Operation);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::Operation& r_SRIO_Console_Console_Operation);


  // define the typecode class for SRIO_Console_Console_TrapPoint
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_TrapPoint, ilu_union_tk,
        "IDL:SRIO_Console/Console/TrapPoint:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::TrapPoint
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::TrapPoint& r_SRIO_Console_Console_TrapPoint);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::TrapPoint* p_SRIO_Console_Console_TrapPoint);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::TrapPoint*& rp_SRIO_Console_Console_TrapPoint);


  // define the typecode class for SRIO_Console_Console_TrapType
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_TrapType, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/TrapType:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::TrapType
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::TrapType& r_SRIO_Console_Console_TrapType);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::TrapType& r_SRIO_Console_Console_TrapType);


  // define the typecode class for SRIO_Console_Console_Point
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_Point, ilu_union_tk,
        "IDL:SRIO_Console/Console/Point:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::Point
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::Point& r_SRIO_Console_Console_Point);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::Point* p_SRIO_Console_Console_Point);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::Point*& rp_SRIO_Console_Console_Point);


  // define the typecode class for SRIO_Console_Console_PointType
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_PointType, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/PointType:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::PointType
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::PointType& r_SRIO_Console_Console_PointType);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::PointType& r_SRIO_Console_Console_PointType);


  // define the typecode class for SRIO_Console_Console_CosInfoSeq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_CosInfoSeq, ilu_sequence_tk,
        "ilut:kwkwgbvpv+vadYmnz8w1UE-BJ6B");

  // declare the Any insert and extract operators for SRIO_Console::Console::CosInfoSeq
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::CosInfoSeq& r_SRIO_Console_Console_CosInfoSeq);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::CosInfoSeq* p_SRIO_Console_Console_CosInfoSeq);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::CosInfoSeq*& rp_SRIO_Console_Console_CosInfoSeq);


  // define the typecode class for SRIO_Console_Console_CosInfoNode
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_CosInfoNode, ilu_record_tk,
        "IDL:SRIO_Console/Console/CosInfoNode:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::CosInfoNode
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::CosInfoNode& r_SRIO_Console_Console_CosInfoNode);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::CosInfoNode* p_SRIO_Console_Console_CosInfoNode);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::CosInfoNode*& rp_SRIO_Console_Console_CosInfoNode);


  // define the typecode class for SRIO_Console_Console_TrackMode
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_TrackMode, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/TrackMode:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::TrackMode
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::TrackMode& r_SRIO_Console_Console_TrackMode);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::TrackMode& r_SRIO_Console_Console_TrackMode);


  // define the typecode class for SRIO_Console_Console_FormationType
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_FormationType, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/FormationType:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::FormationType
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::FormationType& r_SRIO_Console_Console_FormationType);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::FormationType& r_SRIO_Console_Console_FormationType);


  // define the typecode class for SRIO_Console_Console_FormationState
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_FormationState, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/FormationState:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::FormationState
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::FormationState& r_SRIO_Console_Console_FormationState);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::FormationState& r_SRIO_Console_Console_FormationState);


  // define the typecode class for SRIO_Console_Console_MissionStateData
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_MissionStateData, ilu_union_tk,
        "IDL:SRIO_Console/Console/MissionStateData:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::MissionStateData
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Console::Console::MissionStateData& r_SRIO_Console_Console_MissionStateData);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console::MissionStateData* p_SRIO_Console_Console_MissionStateData);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::MissionStateData*& rp_SRIO_Console_Console_MissionStateData);


  // define the typecode class for SRIO_Console_Console_MissionState
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_MissionState, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/MissionState:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::MissionState
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::MissionState& r_SRIO_Console_Console_MissionState);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::MissionState& r_SRIO_Console_Console_MissionState);


  // define the typecode class for SRIO_Console_Console_Role
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Console_Console_Role, ilu_enumeration_tk,
        "IDL:SRIO_Console/Console/Role:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console::Role
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Console::Console::Role& r_SRIO_Console_Console_Role);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Console::Console::Role& r_SRIO_Console_Console_Role);


  // define the typecode class for SRIO_Console_Console
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(SRIO_Console_Console, ilu_object_tk,
        "IDL:SRIO_Console/Console:1.0");

  // declare the Any insert and extract operators for SRIO_Console::Console
  void operator<<=(CORBA_(Any)& r_any, SRIO_Console::Console_ptr p_SRIO_Console_Console);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Console::Console_ptr& rp_SRIO_Console_Console);

#endif
