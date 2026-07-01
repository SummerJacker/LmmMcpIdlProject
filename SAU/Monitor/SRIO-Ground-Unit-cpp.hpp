
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Ground_Unit_H_
  #define __SRIO_Ground_Unit_H_
  
//Note corba.hpp includes ilu.hpp, corba-templates.hpp, cppportability.hpp
#include <corba.hpp>
#include <ilu.hpp>
#include <corba-templates.hpp>
#include <cppportability.hpp>

#ifndef CORBA_
  #define CORBA_(name) NAME_INSIDE_SCOPE(CORBA, name)
#endif
#ifndef CORBA
  #define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA, name)
#endif
#ifndef ADD_VARIANT_SUPPORT
  #define ADD_VARIANT_SUPPORT
#endif
#ifndef SRIO_Ground_Unit_
  #define SRIO_Ground_Unit_(name) NAME_INSIDE_SCOPE(SRIO_Ground_Unit,name)
#endif
#ifndef SRIO_Ground_Unit
  #define SRIO_Ground_Unit(name) NAME_OUTSIDE_SCOPE(SRIO_Ground_Unit,name)
#endif
  #include "SRIO-Unit-cpp.hpp" 

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for SRIO_Ground_Unit 
namespace SRIO_Ground_Unit {
 
 
     // Declarations for initialization
     NS_EXTERN void iluInitialize();
     NS_EXTERN int g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               p_initialization_function_list;

     class Ground_Unit;
     typedef Ground_Unit* Ground_Unit_ptr;
     typedef iluTemplatableObject_var<Ground_Unit> Ground_Unit_var;


//////////////////////////////////////////////////////////////////////
// class Ground_Unit 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Ground_Unit : public virtual SRIO_Unit::General_Unit { 
      public:
        // Constructs a new Ground_Unit using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Ground_Unit(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_(Boolean) b_within_object_table = ILUCPP_FALSE) :
               iluObject(Ground_Unit::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Ground_Unit_ptr _duplicate(Ground_Unit_ptr a_ptr);

        static Ground_Unit_ptr _narrow(CORBA_(Object_ptr) an_object_ptr) {
          return (Ground_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Ground_Unit_ptr _narrow(iluObject* an_object_ptr) {
          return (Ground_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }


        static Ground_Unit_ptr _narrow(SRIO_Unit::General_Unit_ptr an_object_ptr) {
          return (Ground_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }
        static Ground_Unit_ptr _nil();
        Ground_Unit_ptr _this() { return _duplicate((Ground_Unit_ptr) this); }

        // IDL specified methods

  #undef NS_EXTERN
  #define NS_EXTERN static

 
 
     struct TrapPoint2D;
     typedef iluTemplatableT_var<TrapPoint2D> TrapPoint2D_var;

     struct Point2D;
     typedef iluTemplatableT_var<Point2D> Point2D_var;

     class MoveAction; 
     typedef iluTemplatableT_var<MoveAction> MoveAction_var;

      class TrapPointSequence;
      typedef iluTemplatableSequence_var<TrapPointSequence, TrapPoint2D> TrapPointSequence_var; 

      class TaskPath;
      typedef iluTemplatableSequence_var<TaskPath, Point2D> TaskPath_var; 

      class ActionSequence;
      typedef iluTemplatableSequence_var<ActionSequence, MoveAction> ActionSequence_var; 

     struct Formation;
     typedef iluTemplatableT_var<Formation> Formation_var;

     struct GroundUnitInfo;
     typedef iluTemplatableT_var<GroundUnitInfo> GroundUnitInfo_var;

     struct Speed2D;
     typedef iluTemplatableT_var<Speed2D> Speed2D_var;

     struct Pose2D;
     typedef iluTemplatableT_var<Pose2D> Pose2D_var;

     enum MoveActionType { MA_GoAhead = 0, MA_GoBackward = 1, MA_TurnLeft = 2, MA_TurnRight = 3, MA_Stop = 4 };

     // declare the typecode instance for MoveActionType
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_MoveActionType;

     struct BasicMoveActionData;
     typedef iluTemplatableT_var<BasicMoveActionData> BasicMoveActionData_var;

     struct ActionDuration;
     typedef iluTemplatableT_var<ActionDuration> ActionDuration_var;



   ////////////////////////////////////////////////////////////////
   // structure Formation

   struct Formation {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Formation();    
         // copy constructor
         Formation(const Formation&  r_a_Formation);   
         // destructor
         ~Formation();
         //assignment operator
         Formation& operator= (const Formation& r_a_Formation);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Formation& self();

         //member vars
           SRIO_Unit::General_Unit::UnitIDSeq robot_ids;
           SRIO_Unit::General_Unit::ShortSeq leader_ids;
           SRIO_Unit::General_Unit::FloatSeq distances;
           SRIO_Unit::General_Unit::FloatSeq angles;
     };


     // declare the typecode instance for Formation
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Formation;



   ////////////////////////////////////////////////////////////////
   // sequence TrapPointSequence

   class TrapPointSequence {

    public:

       // constructors & destructor
        TrapPointSequence ();
        TrapPointSequence (CORBA_(ULong) max);
        TrapPointSequence (CORBA_(ULong) max, CORBA_(ULong) length,
              TrapPoint2D* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        TrapPointSequence (const TrapPointSequence& r_TrapPointSequence);
       ~TrapPointSequence();

        // assignment
        TrapPointSequence& operator= (const TrapPointSequence& r_TrapPointSequence);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        TrapPoint2D* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        TrapPoint2D const* get_buffer () const;

        // [] operators
        TrapPoint2D& operator [] (CORBA_(ULong) index);
        const TrapPoint2D& operator [] (CORBA_(ULong) index) const;

        // memory management
         static TrapPoint2D* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(TrapPoint2D* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          TrapPointSequence& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          TrapPoint2D* m_buffer;

  };

  // declare the typecode instance for TrapPointSequence
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_TrapPointSequence;



   ////////////////////////////////////////////////////////////////
   // sequence TaskPath

   class TaskPath {

    public:

       // constructors & destructor
        TaskPath ();
        TaskPath (CORBA_(ULong) max);
        TaskPath (CORBA_(ULong) max, CORBA_(ULong) length,
              Point2D* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        TaskPath (const TaskPath& r_TaskPath);
       ~TaskPath();

        // assignment
        TaskPath& operator= (const TaskPath& r_TaskPath);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        Point2D* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        Point2D const* get_buffer () const;

        // [] operators
        Point2D& operator [] (CORBA_(ULong) index);
        const Point2D& operator [] (CORBA_(ULong) index) const;

        // memory management
         static Point2D* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(Point2D* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          TaskPath& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          Point2D* m_buffer;

  };

  // declare the typecode instance for TaskPath
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_TaskPath;



   ////////////////////////////////////////////////////////////////
   // sequence ActionSequence

   class ActionSequence {

    public:

       // constructors & destructor
        ActionSequence ();
        ActionSequence (CORBA_(ULong) max);
        ActionSequence (CORBA_(ULong) max, CORBA_(ULong) length,
              MoveAction* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        ActionSequence (const ActionSequence& r_ActionSequence);
       ~ActionSequence();

        // assignment
        ActionSequence& operator= (const ActionSequence& r_ActionSequence);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        MoveAction* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        MoveAction const* get_buffer () const;

        // [] operators
        MoveAction& operator [] (CORBA_(ULong) index);
        const MoveAction& operator [] (CORBA_(ULong) index) const;

        // memory management
         static MoveAction* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(MoveAction* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          ActionSequence& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          MoveAction* m_buffer;

  };

  // declare the typecode instance for ActionSequence
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_ActionSequence;



   ////////////////////////////////////////////////////////////////
   // structure Point2D

   struct Point2D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Point2D();    
         // copy constructor
         Point2D(const Point2D&  r_a_Point2D);   
         // destructor
         ~Point2D();
         //assignment operator
         Point2D& operator= (const Point2D& r_a_Point2D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Point2D& self();

         //member vars
           CORBA_(Float) x;
           CORBA_(Float) y;
     };


     // declare the typecode instance for Point2D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Point2D;



   ////////////////////////////////////////////////////////////////
   // structure Speed2D

   struct Speed2D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Speed2D();    
         // copy constructor
         Speed2D(const Speed2D&  r_a_Speed2D);   
         // destructor
         ~Speed2D();
         //assignment operator
         Speed2D& operator= (const Speed2D& r_a_Speed2D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Speed2D& self();

         //member vars
           CORBA_(Float) leanerVel;
           CORBA_(Float) angularVel;
     };


     // declare the typecode instance for Speed2D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Speed2D;



   ////////////////////////////////////////////////////////////////
   // structure Pose2D

   struct Pose2D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Pose2D();    
         // copy constructor
         Pose2D(const Pose2D&  r_a_Pose2D);   
         // destructor
         ~Pose2D();
         //assignment operator
         Pose2D& operator= (const Pose2D& r_a_Pose2D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Pose2D& self();

         //member vars
           CORBA_(Float) x;
           CORBA_(Float) y;
           CORBA_(Float) yaw;
     };


     // declare the typecode instance for Pose2D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Pose2D;



   ////////////////////////////////////////////////////////////////
   // structure ActionDuration

   struct ActionDuration {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         ActionDuration();    
         // copy constructor
         ActionDuration(const ActionDuration&  r_a_ActionDuration);   
         // destructor
         ~ActionDuration();
         //assignment operator
         ActionDuration& operator= (const ActionDuration& r_a_ActionDuration);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          ActionDuration& self();

         //member vars
           CORBA_(Boolean) keep;
           CORBA_(ULong) ft_s;
           CORBA_(ULong) ft_t;
     };


     // declare the typecode instance for ActionDuration
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_ActionDuration;



   ////////////////////////////////////////////////////////////////
   // structure TrapPoint2D

   struct TrapPoint2D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         TrapPoint2D();    
         // copy constructor
         TrapPoint2D(const TrapPoint2D&  r_a_TrapPoint2D);   
         // destructor
         ~TrapPoint2D();
         //assignment operator
         TrapPoint2D& operator= (const TrapPoint2D& r_a_TrapPoint2D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          TrapPoint2D& self();

         //member vars
           Point2D point;
           CORBA_(Float) radius;
     };


     // declare the typecode instance for TrapPoint2D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_TrapPoint2D;



   ////////////////////////////////////////////////////////////////
   // structure GroundUnitInfo

   struct GroundUnitInfo {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         GroundUnitInfo();    
         // copy constructor
         GroundUnitInfo(const GroundUnitInfo&  r_a_GroundUnitInfo);   
         // destructor
         ~GroundUnitInfo();
         //assignment operator
         GroundUnitInfo& operator= (const GroundUnitInfo& r_a_GroundUnitInfo);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          GroundUnitInfo& self();

         //member vars
           SRIO_Unit::General_Unit::UnitInfo info;
           SRIO_Unit::General_Unit::UnitRole role;
           Speed2D speed;
           Pose2D pose;
     };


     // declare the typecode instance for GroundUnitInfo
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_GroundUnitInfo;



   ////////////////////////////////////////////////////////////////
   // structure BasicMoveActionData

   struct BasicMoveActionData {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         BasicMoveActionData();    
         // copy constructor
         BasicMoveActionData(const BasicMoveActionData&  r_a_BasicMoveActionData);   
         // destructor
         ~BasicMoveActionData();
         //assignment operator
         BasicMoveActionData& operator= (const BasicMoveActionData& r_a_BasicMoveActionData);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          BasicMoveActionData& self();

         //member vars
           CORBA_(Float) speed;
           ActionDuration duration;
     };


     // declare the typecode instance for BasicMoveActionData
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_BasicMoveActionData;



 class MoveAction {
                
         // insertion, extraction, and sizing operators for MoveAction
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        MoveAction();
        MoveAction(const MoveAction& r_MoveAction);                   
        ~MoveAction();
                   
        // assignment
        MoveAction& operator= (const MoveAction& r_MoveAction);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         MoveAction& self();
                   
        // accessors and modifiers
        MoveActionType _d () const;
        void _d (MoveActionType new_d);

       void goAheadData(const BasicMoveActionData & an_goAheadData); 
       const BasicMoveActionData& goAheadData() const;
       BasicMoveActionData& goAheadData();
       void goBackwardData(const BasicMoveActionData & an_goBackwardData); 
       const BasicMoveActionData& goBackwardData() const;
       BasicMoveActionData& goBackwardData();
       void turnLeftData(const BasicMoveActionData & an_turnLeftData); 
       const BasicMoveActionData& turnLeftData() const;
       BasicMoveActionData& turnLeftData();
       void turnRightData(const BasicMoveActionData & an_turnRightData); 
       const BasicMoveActionData& turnRightData() const;
       BasicMoveActionData& turnRightData();
       void stopData(const ActionDuration & an_stopData); 
       const ActionDuration& stopData() const;
       ActionDuration& stopData();
         void unset();
         union {
                 BasicMoveActionData* m_goAheadData;    
                 BasicMoveActionData* m_goBackwardData;    
                 BasicMoveActionData* m_turnLeftData;    
                 BasicMoveActionData* m_turnRightData;    
                 ActionDuration* m_stopData;    
        };
                
        MoveActionType    m_discriminator;
        CORBA_(Boolean)     m_b_beenset;
                   
 };


     // declare the typecode instance for MoveAction
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_MoveAction;


  #ifndef CPLUSPLUSMAPPING_NESTEDCLASSES
      #undef NS_EXTERN
      #define NS_EXTERN extern
  #endif

   
       virtual Speed2D getCurrentSpeed(
       ) = 0;
   
       virtual Pose2D getCurrentPose(
       ) = 0;
   
       virtual GroundUnitInfo* getCurrentInfo(
       ) = 0;
   
       virtual CORBA_(Boolean) sendMoveAction(
          const MoveAction&  action
       ) = 0;
   
       virtual CORBA_(Boolean) sendMoveActionSequence(
          const ActionSequence&  actions,
          CORBA_(Short)  times
       ) = 0;
   
       virtual CORBA_(Boolean) sendVehicleInfo(
          const GroundUnitInfo&  info
       ) = 0;
   
       virtual CORBA_(Boolean) setRearVehicles(
          const SRIO_Unit::General_Unit::UnitInfoSequence&  rears,
          CORBA_(Float)  distance,
          CORBA_(Float)  angle
       ) = 0;
   
       virtual CORBA_(Boolean) setFormation(
          const Formation&  form
       ) = 0;
   
       virtual CORBA_(Boolean) reportTrap(
          const TrapPoint2D&  trap
       ) = 0;
   
       virtual CORBA_(Boolean) clearTraps(
       ) = 0;
   
       virtual TrapPointSequence* getTraps(
       ) = 0;
   
       virtual CORBA_(Boolean) setTrapPoint(
          const TrapPoint2D&  trap
       ) = 0;
   
       virtual CORBA_(Boolean) setTrack(
          const TaskPath&  track
       ) = 0;
   
       virtual CORBA_(Boolean) setTaskPath(
          const TaskPath&  path
       ) = 0;
   
       virtual CORBA_(Boolean) setTaskPoint(
          const Point2D&  point
       ) = 0;
   
       virtual CORBA_(Boolean) startPhotoStream(
          CORBA_(Float)  frequency
       ) = 0;
   
       virtual CORBA_(Boolean) stopPhotoStream(
       ) = 0;
   
       virtual CORBA_(Boolean) setFollower(
          const SRIO_Unit::General_Unit::UnitInfo&  ui
       ) = 0;
   
       virtual CORBA_(Boolean) unsetFollower(
          const iluShortCharacter*  uid
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Ground_Unit_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Ground_Unit_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Ground_Unit::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Ground_Unit();	// default constructor
        virtual ~Ground_Unit();	 // destructor

   private:
        Ground_Unit(const Ground_Unit&);	// copy constructor
        void operator=(const Ground_Unit&);	// assignment operator

      };

  // declare the typecode instance for Ground_Unit
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_Ground_Unit;


//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // initializer class is used to create a single instance that puts the
 // iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class initializer {
    public:
      initializer ();
      void * ensure_instantiation ();
      static initializer sm_the_SRIO_Ground_Unit_initializer;
  };
// End the scope for SRIO_Ground_Unit
 }

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_SRIO_Ground_Unit_CLIENT_ONLY() { \
     SRIO_Ground_Unit::initializer::sm_the_SRIO_Ground_Unit_initializer.ensure_instantiation();\
     SRIO_Ground_Unit_surrogate::Ground_Unit_initializer::sm_the_surrogate_SRIO_Ground_Unit_Ground_Unit_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Ground_Unit_SERVER_ONLY() { \
     SRIO_Ground_Unit::initializer::sm_the_SRIO_Ground_Unit_initializer.ensure_instantiation();\
     SRIO_Ground_Unit_true::Ground_Unit_initializer::sm_the_true_SRIO_Ground_Unit_Ground_Unit_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Ground_Unit_CLIENT_SERVER() { \
     SRIO_Ground_Unit::initializer::sm_the_SRIO_Ground_Unit_initializer.ensure_instantiation();\
     SRIO_Ground_Unit_surrogate::Ground_Unit_initializer::sm_the_surrogate_SRIO_Ground_Unit_Ground_Unit_initializer.ensure_instantiation(); \
     SRIO_Ground_Unit_true::Ground_Unit_initializer::sm_the_true_SRIO_Ground_Unit_Ground_Unit_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Formation
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Formation& r_SRIO_Ground_Unit_Ground_Unit_Formation);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Formation& r_SRIO_Ground_Unit_Ground_Unit_Formation);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::Formation& r_SRIO_Ground_Unit_Ground_Unit_Formation);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::TrapPointSequence
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::TaskPath
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::ActionSequence
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::TrapPoint2D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Point2D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Point2D& r_SRIO_Ground_Unit_Ground_Unit_Point2D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Point2D& r_SRIO_Ground_Unit_Ground_Unit_Point2D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::Point2D& r_SRIO_Ground_Unit_Ground_Unit_Point2D);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Speed2D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Speed2D& r_SRIO_Ground_Unit_Ground_Unit_Speed2D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Speed2D& r_SRIO_Ground_Unit_Ground_Unit_Speed2D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::Speed2D& r_SRIO_Ground_Unit_Ground_Unit_Speed2D);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::Pose2D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Pose2D& r_SRIO_Ground_Unit_Ground_Unit_Pose2D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::Pose2D& r_SRIO_Ground_Unit_Ground_Unit_Pose2D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::Pose2D& r_SRIO_Ground_Unit_Ground_Unit_Pose2D);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::MoveAction
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::MoveAction& r_SRIO_Ground_Unit_Ground_Unit_MoveAction);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::MoveAction& r_SRIO_Ground_Unit_Ground_Unit_MoveAction);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::MoveAction& r_SRIO_Ground_Unit_Ground_Unit_MoveAction);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit::ActionDuration
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_SRIO_Ground_Unit_Ground_Unit_ActionDuration);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_SRIO_Ground_Unit_Ground_Unit_ActionDuration);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_SRIO_Ground_Unit_Ground_Unit_ActionDuration);

  // insertion, extraction, and sizing operators for SRIO_Ground_Unit::Ground_Unit_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit_var& r_SRIO_Ground_Unit_Ground_Unit_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Ground_Unit::Ground_Unit_var& r_SRIO_Ground_Unit_Ground_Unit_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Ground_Unit::Ground_Unit_var& r_SRIO_Ground_Unit_Ground_Unit_var);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_Formation
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_Formation, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/Formation:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Formation
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::Formation& r_SRIO_Ground_Unit_Ground_Unit_Formation);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::Formation* p_SRIO_Ground_Unit_Ground_Unit_Formation);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::Formation*& rp_SRIO_Ground_Unit_Ground_Unit_Formation);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_TrapPointSequence
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_TrapPointSequence, ilu_sequence_tk,
        "ilut:pL4QAQdx3RBvFQGnuVUbbauErPi");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::TrapPointSequence
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::TrapPointSequence& r_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::TrapPointSequence* p_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::TrapPointSequence*& rp_SRIO_Ground_Unit_Ground_Unit_TrapPointSequence);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_TaskPath
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_TaskPath, ilu_sequence_tk,
        "ilut:kaKU7Mg3Xc8D15tnQikFLuEMsP+");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::TaskPath
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::TaskPath& r_SRIO_Ground_Unit_Ground_Unit_TaskPath);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::TaskPath* p_SRIO_Ground_Unit_Ground_Unit_TaskPath);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::TaskPath*& rp_SRIO_Ground_Unit_Ground_Unit_TaskPath);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_ActionSequence
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_ActionSequence, ilu_sequence_tk,
        "ilut:eZqYM8Z+Erss108EKN+8tWm75v9");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::ActionSequence
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::ActionSequence& r_SRIO_Ground_Unit_Ground_Unit_ActionSequence);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::ActionSequence* p_SRIO_Ground_Unit_Ground_Unit_ActionSequence);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::ActionSequence*& rp_SRIO_Ground_Unit_Ground_Unit_ActionSequence);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_TrapPoint2D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_TrapPoint2D, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/TrapPoint2D:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::TrapPoint2D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::TrapPoint2D& r_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::TrapPoint2D* p_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::TrapPoint2D*& rp_SRIO_Ground_Unit_Ground_Unit_TrapPoint2D);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_Point2D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_Point2D, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/Point2D:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Point2D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::Point2D& r_SRIO_Ground_Unit_Ground_Unit_Point2D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::Point2D* p_SRIO_Ground_Unit_Ground_Unit_Point2D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::Point2D*& rp_SRIO_Ground_Unit_Ground_Unit_Point2D);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/GroundUnitInfo:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& r_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo* p_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo*& rp_SRIO_Ground_Unit_Ground_Unit_GroundUnitInfo);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_Speed2D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_Speed2D, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/Speed2D:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Speed2D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::Speed2D& r_SRIO_Ground_Unit_Ground_Unit_Speed2D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::Speed2D* p_SRIO_Ground_Unit_Ground_Unit_Speed2D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::Speed2D*& rp_SRIO_Ground_Unit_Ground_Unit_Speed2D);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_Pose2D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_Pose2D, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/Pose2D:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::Pose2D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::Pose2D& r_SRIO_Ground_Unit_Ground_Unit_Pose2D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::Pose2D* p_SRIO_Ground_Unit_Ground_Unit_Pose2D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::Pose2D*& rp_SRIO_Ground_Unit_Ground_Unit_Pose2D);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_MoveAction
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_MoveAction, ilu_union_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/MoveAction:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::MoveAction
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::MoveAction& r_SRIO_Ground_Unit_Ground_Unit_MoveAction);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::MoveAction* p_SRIO_Ground_Unit_Ground_Unit_MoveAction);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::MoveAction*& rp_SRIO_Ground_Unit_Ground_Unit_MoveAction);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/BasicMoveActionData:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData& r_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData* p_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::BasicMoveActionData*& rp_SRIO_Ground_Unit_Ground_Unit_BasicMoveActionData);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_ActionDuration
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_ActionDuration, ilu_record_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/ActionDuration:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::ActionDuration
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Ground_Unit::Ground_Unit::ActionDuration& r_SRIO_Ground_Unit_Ground_Unit_ActionDuration);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit::ActionDuration* p_SRIO_Ground_Unit_Ground_Unit_ActionDuration);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::ActionDuration*& rp_SRIO_Ground_Unit_Ground_Unit_ActionDuration);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit_MoveActionType
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Ground_Unit_Ground_Unit_MoveActionType, ilu_enumeration_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit/MoveActionType:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit::MoveActionType
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Ground_Unit::Ground_Unit::MoveActionType& r_SRIO_Ground_Unit_Ground_Unit_MoveActionType);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Ground_Unit::Ground_Unit::MoveActionType& r_SRIO_Ground_Unit_Ground_Unit_MoveActionType);


  // define the typecode class for SRIO_Ground_Unit_Ground_Unit
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(SRIO_Ground_Unit_Ground_Unit, ilu_object_tk,
        "IDL:SRIO_Ground_Unit/Ground_Unit:1.0");

  // declare the Any insert and extract operators for SRIO_Ground_Unit::Ground_Unit
  void operator<<=(CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit_ptr p_SRIO_Ground_Unit_Ground_Unit);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Ground_Unit::Ground_Unit_ptr& rp_SRIO_Ground_Unit_Ground_Unit);

#endif
