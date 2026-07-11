
// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

#ifndef __SRIO_Air_Unit_H_
  #define __SRIO_Air_Unit_H_
  
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
#ifndef SRIO_Air_Unit_
  #define SRIO_Air_Unit_(name) NAME_INSIDE_SCOPE(SRIO_Air_Unit,name)
#endif
#ifndef SRIO_Air_Unit
  #define SRIO_Air_Unit(name) NAME_OUTSIDE_SCOPE(SRIO_Air_Unit,name)
#endif
  #include "SRIO-Unit-cpp.hpp" 

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for SRIO_Air_Unit 
namespace SRIO_Air_Unit {
 
 
     // Declarations for initialization
     NS_EXTERN void iluInitialize();
     NS_EXTERN int g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               p_initialization_function_list;

     class Air_Unit;
     typedef Air_Unit* Air_Unit_ptr;
     typedef iluTemplatableObject_var<Air_Unit> Air_Unit_var;


//////////////////////////////////////////////////////////////////////
// class Air_Unit 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Air_Unit : public virtual SRIO_Unit::General_Unit { 
      public:
        // Constructs a new Air_Unit using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Air_Unit(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_(Boolean) b_within_object_table = ILUCPP_FALSE) :
               iluObject(Air_Unit::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Air_Unit_ptr _duplicate(Air_Unit_ptr a_ptr);

        static Air_Unit_ptr _narrow(CORBA_(Object_ptr) an_object_ptr) {
          return (Air_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Air_Unit_ptr _narrow(iluObject* an_object_ptr) {
          return (Air_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }


        static Air_Unit_ptr _narrow(SRIO_Unit::General_Unit_ptr an_object_ptr) {
          return (Air_Unit_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }
        static Air_Unit_ptr _nil();
        Air_Unit_ptr _this() { return _duplicate((Air_Unit_ptr) this); }

        // IDL specified methods

  #undef NS_EXTERN
  #define NS_EXTERN static

 
 
     struct TrapPoint3D;
     typedef iluTemplatableT_var<TrapPoint3D> TrapPoint3D_var;

     struct Point3D;
     typedef iluTemplatableT_var<Point3D> Point3D_var;

     class MoveAction; 
     typedef iluTemplatableT_var<MoveAction> MoveAction_var;

      class TrapPointSequence;
      typedef iluTemplatableSequence_var<TrapPointSequence, TrapPoint3D> TrapPointSequence_var; 

      class TaskPath;
      typedef iluTemplatableSequence_var<TaskPath, Point3D> TaskPath_var; 

      class ActionSequence;
      typedef iluTemplatableSequence_var<ActionSequence, MoveAction> ActionSequence_var; 

      class UnitSBHSeq;
      typedef iluTemplatableSequence_var<UnitSBHSeq, CORBA_(String_var)> UnitSBHSeq_var; 

     class Site; 
     typedef iluTemplatableT_var<Site> Site_var;

     enum SiteType { Rectangle = 0, Circle = 1 };

     // declare the typecode instance for SiteType
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_SiteType;

     struct CircleData;
     typedef iluTemplatableT_var<CircleData> CircleData_var;

     struct RectangleData;
     typedef iluTemplatableT_var<RectangleData> RectangleData_var;

     enum ActionMode { None = 0, Cruise = 1, Locate = 2, Assist = 3, Feedback = 4 };

     // declare the typecode instance for ActionMode
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_ActionMode;

     enum ActionRole { Actor = 0, Standby = 1, Facilitators = 2 };

     // declare the typecode instance for ActionRole
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_ActionRole;

     struct Formation;
     typedef iluTemplatableT_var<Formation> Formation_var;

     struct AirUnitInfo;
     typedef iluTemplatableT_var<AirUnitInfo> AirUnitInfo_var;

     struct FusionAngularVelocity;
     typedef iluTemplatableT_var<FusionAngularVelocity> FusionAngularVelocity_var;

     struct Speed3D;
     typedef iluTemplatableT_var<Speed3D> Speed3D_var;

     struct GPSInfo;
     typedef iluTemplatableT_var<GPSInfo> GPSInfo_var;

     struct Pose3D;
     typedef iluTemplatableT_var<Pose3D> Pose3D_var;

     struct GimbalState;
     typedef iluTemplatableT_var<GimbalState> GimbalState_var;

     struct GimbalSpeed;
     typedef iluTemplatableT_var<GimbalSpeed> GimbalSpeed_var;

     enum MoveActionType { MA_GoUp = 0, MA_GoDown = 1, MA_GoAhead = 2, MA_GoBackward = 3, MA_GoLeft = 4, MA_GoRight = 5, MA_TurnLeft = 6, MA_TurnRight = 7, MA_Stop = 8, MA_TakeOff = 9, MA_Land = 10, MA_LandConfirm = 11, MA_ForceLanding = 12, MA_Lock = 13, MA_Unlock = 14 };

     // declare the typecode instance for MoveActionType
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_MoveActionType;

     struct BasicMoveActionData;
     typedef iluTemplatableT_var<BasicMoveActionData> BasicMoveActionData_var;

     struct ActionDuration;
     typedef iluTemplatableT_var<ActionDuration> ActionDuration_var;



   ////////////////////////////////////////////////////////////////
   // sequence UnitSBHSeq

   class UnitSBHSeq {

    public:

       // constructors & destructor
        UnitSBHSeq ();
        UnitSBHSeq (CORBA_(ULong) max);
        UnitSBHSeq (CORBA_(ULong) max, CORBA_(ULong) length,
              iluShortCharacter** data, CORBA_(Boolean) release = ILUCPP_FALSE);
        UnitSBHSeq (const UnitSBHSeq& r_UnitSBHSeq);
       ~UnitSBHSeq();

        // assignment
        UnitSBHSeq& operator= (const UnitSBHSeq& r_UnitSBHSeq);

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
          UnitSBHSeq& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          iluShortCharacter** m_buffer;
          CORBA_(String_var)* m_varbuffer;

  };

  // declare the typecode instance for UnitSBHSeq
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_UnitSBHSeq;



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
              TrapPoint3D* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        TrapPointSequence (const TrapPointSequence& r_TrapPointSequence);
       ~TrapPointSequence();

        // assignment
        TrapPointSequence& operator= (const TrapPointSequence& r_TrapPointSequence);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        TrapPoint3D* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        TrapPoint3D const* get_buffer () const;

        // [] operators
        TrapPoint3D& operator [] (CORBA_(ULong) index);
        const TrapPoint3D& operator [] (CORBA_(ULong) index) const;

        // memory management
         static TrapPoint3D* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(TrapPoint3D* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          TrapPointSequence& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          TrapPoint3D* m_buffer;

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
              Point3D* data, CORBA_(Boolean) release = ILUCPP_FALSE);
        TaskPath (const TaskPath& r_TaskPath);
       ~TaskPath();

        // assignment
        TaskPath& operator= (const TaskPath& r_TaskPath);

        // accessors
        CORBA_(ULong) maximum() const;
        CORBA_(ULong) length() const;
        void length (CORBA_(ULong) len);
		CORBA_(Boolean) release() const;
        Point3D* get_buffer (CORBA_(Boolean) orphan = ilu_FALSE);
        Point3D const* get_buffer () const;

        // [] operators
        Point3D& operator [] (CORBA_(ULong) index);
        const Point3D& operator [] (CORBA_(ULong) index) const;

        // memory management
         static Point3D* allocbuf(CORBA_(ULong) num_elements);
         static void freebuf(Point3D* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          TaskPath& self();

    private:

          CORBA_(ULong) m_maximum;
          CORBA_(ULong) m_length;
          CORBA_(Boolean) m_release;
          Point3D* m_buffer;

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
   // structure Point3D

   struct Point3D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Point3D();    
         // copy constructor
         Point3D(const Point3D&  r_a_Point3D);   
         // destructor
         ~Point3D();
         //assignment operator
         Point3D& operator= (const Point3D& r_a_Point3D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Point3D& self();

         //member vars
           CORBA_(Float) x;
           CORBA_(Float) y;
           CORBA_(Float) z;
     };


     // declare the typecode instance for Point3D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Point3D;



   ////////////////////////////////////////////////////////////////
   // structure FusionAngularVelocity

   struct FusionAngularVelocity {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         FusionAngularVelocity();    
         // copy constructor
         FusionAngularVelocity(const FusionAngularVelocity&  r_a_FusionAngularVelocity);   
         // destructor
         ~FusionAngularVelocity();
         //assignment operator
         FusionAngularVelocity& operator= (const FusionAngularVelocity& r_a_FusionAngularVelocity);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          FusionAngularVelocity& self();

         //member vars
           CORBA_(Float) x;
           CORBA_(Float) y;
           CORBA_(Float) z;
     };


     // declare the typecode instance for FusionAngularVelocity
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_FusionAngularVelocity;



   ////////////////////////////////////////////////////////////////
   // structure Speed3D

   struct Speed3D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Speed3D();    
         // copy constructor
         Speed3D(const Speed3D&  r_a_Speed3D);   
         // destructor
         ~Speed3D();
         //assignment operator
         Speed3D& operator= (const Speed3D& r_a_Speed3D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Speed3D& self();

         //member vars
           CORBA_(Float) x;
           CORBA_(Float) y;
           CORBA_(Float) z;
     };


     // declare the typecode instance for Speed3D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Speed3D;



   ////////////////////////////////////////////////////////////////
   // structure GPSInfo

   struct GPSInfo {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         GPSInfo();    
         // copy constructor
         GPSInfo(const GPSInfo&  r_a_GPSInfo);   
         // destructor
         ~GPSInfo();
         //assignment operator
         GPSInfo& operator= (const GPSInfo& r_a_GPSInfo);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          GPSInfo& self();

         //member vars
           CORBA_(Float) longitude;
           CORBA_(Float) latitude;
           CORBA_(Float) altitude;
           CORBA_(Float) height;
           CORBA_(Float) time;
           CORBA_(Short) health;
     };


     // declare the typecode instance for GPSInfo
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_GPSInfo;



   ////////////////////////////////////////////////////////////////
   // structure Pose3D

   struct Pose3D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Pose3D();    
         // copy constructor
         Pose3D(const Pose3D&  r_a_Pose3D);   
         // destructor
         ~Pose3D();
         //assignment operator
         Pose3D& operator= (const Pose3D& r_a_Pose3D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Pose3D& self();

         //member vars
           CORBA_(Float) x;
           CORBA_(Float) y;
           CORBA_(Float) z;
           CORBA_(Float) pitch;
           CORBA_(Float) yaw;
           CORBA_(Float) roll;
     };


     // declare the typecode instance for Pose3D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Pose3D;



   ////////////////////////////////////////////////////////////////
   // structure GimbalState

   struct GimbalState {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         GimbalState();    
         // copy constructor
         GimbalState(const GimbalState&  r_a_GimbalState);   
         // destructor
         ~GimbalState();
         //assignment operator
         GimbalState& operator= (const GimbalState& r_a_GimbalState);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          GimbalState& self();

         //member vars
           CORBA_(Float) yaw;
           CORBA_(Float) roll;
           CORBA_(Float) pitch;
     };


     // declare the typecode instance for GimbalState
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_GimbalState;



   ////////////////////////////////////////////////////////////////
   // structure GimbalSpeed

   struct GimbalSpeed {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         GimbalSpeed();    
         // copy constructor
         GimbalSpeed(const GimbalSpeed&  r_a_GimbalSpeed);   
         // destructor
         ~GimbalSpeed();
         //assignment operator
         GimbalSpeed& operator= (const GimbalSpeed& r_a_GimbalSpeed);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          GimbalSpeed& self();

         //member vars
           CORBA_(Float) yaw;
           CORBA_(Float) roll;
           CORBA_(Float) pitch;
     };


     // declare the typecode instance for GimbalSpeed
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_GimbalSpeed;



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
   // structure CircleData

   struct CircleData {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         CircleData();    
         // copy constructor
         CircleData(const CircleData&  r_a_CircleData);   
         // destructor
         ~CircleData();
         //assignment operator
         CircleData& operator= (const CircleData& r_a_CircleData);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          CircleData& self();

         //member vars
           Point3D po;
           CORBA_(Short) r;
     };


     // declare the typecode instance for CircleData
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_CircleData;



   ////////////////////////////////////////////////////////////////
   // structure RectangleData

   struct RectangleData {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         RectangleData();    
         // copy constructor
         RectangleData(const RectangleData&  r_a_RectangleData);   
         // destructor
         ~RectangleData();
         //assignment operator
         RectangleData& operator= (const RectangleData& r_a_RectangleData);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          RectangleData& self();

         //member vars
           Point3D po;
           CORBA_(Short) x;
           CORBA_(Short) y;
     };


     // declare the typecode instance for RectangleData
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_RectangleData;



   ////////////////////////////////////////////////////////////////
   // structure TrapPoint3D

   struct TrapPoint3D {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         TrapPoint3D();    
         // copy constructor
         TrapPoint3D(const TrapPoint3D&  r_a_TrapPoint3D);   
         // destructor
         ~TrapPoint3D();
         //assignment operator
         TrapPoint3D& operator= (const TrapPoint3D& r_a_TrapPoint3D);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          TrapPoint3D& self();

         //member vars
           Point3D point;
           CORBA_(Float) radius;
     };


     // declare the typecode instance for TrapPoint3D
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_TrapPoint3D;



   ////////////////////////////////////////////////////////////////
   // structure AirUnitInfo

   struct AirUnitInfo {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         AirUnitInfo();    
         // copy constructor
         AirUnitInfo(const AirUnitInfo&  r_a_AirUnitInfo);   
         // destructor
         ~AirUnitInfo();
         //assignment operator
         AirUnitInfo& operator= (const AirUnitInfo& r_a_AirUnitInfo);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          AirUnitInfo& self();

         //member vars
           SRIO_Unit::General_Unit::UnitInfo info;
           SRIO_Unit::General_Unit::UnitRole role;
           Speed3D speed;
           FusionAngularVelocity angularVelocity;
           GPSInfo gps;
           GimbalState gs;
     };


     // declare the typecode instance for AirUnitInfo
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_AirUnitInfo;



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



 class Site {
                
         // insertion, extraction, and sizing operators for Site
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Site();
        Site(const Site& r_Site);                   
        ~Site();
                   
        // assignment
        Site& operator= (const Site& r_Site);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Site& self();
                   
        // accessors and modifiers
        SiteType _d () const;
        void _d (SiteType new_d);

       void rd(const RectangleData & an_rd); 
       const RectangleData& rd() const;
       RectangleData& rd();
       void cd(const CircleData & an_cd); 
       const CircleData& cd() const;
       CircleData& cd();
         void unset();
         union {
                 RectangleData* m_rd;    
                 CircleData* m_cd;    
        };
                
        SiteType    m_discriminator;
        CORBA_(Boolean)     m_b_beenset;
                   
 };


     // declare the typecode instance for Site
     NS_EXTERN const CORBA_(TypeCode_ptr) tc_Site;



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

       void goUpData(const BasicMoveActionData & an_goUpData); 
       const BasicMoveActionData& goUpData() const;
       BasicMoveActionData& goUpData();
       void goDownData(const BasicMoveActionData & an_goDownData); 
       const BasicMoveActionData& goDownData() const;
       BasicMoveActionData& goDownData();
       void goAheadData(const BasicMoveActionData & an_goAheadData); 
       const BasicMoveActionData& goAheadData() const;
       BasicMoveActionData& goAheadData();
       void goBackwardData(const BasicMoveActionData & an_goBackwardData); 
       const BasicMoveActionData& goBackwardData() const;
       BasicMoveActionData& goBackwardData();
       void goLeftData(const BasicMoveActionData & an_goLeftData); 
       const BasicMoveActionData& goLeftData() const;
       BasicMoveActionData& goLeftData();
       void goRightData(const BasicMoveActionData & an_goRightData); 
       const BasicMoveActionData& goRightData() const;
       BasicMoveActionData& goRightData();
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
                 BasicMoveActionData* m_goUpData;    
                 BasicMoveActionData* m_goDownData;    
                 BasicMoveActionData* m_goAheadData;    
                 BasicMoveActionData* m_goBackwardData;    
                 BasicMoveActionData* m_goLeftData;    
                 BasicMoveActionData* m_goRightData;    
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

   
       virtual Speed3D getCurrentSpeed(
       ) = 0;
   
       virtual Pose3D getCurrentPose(
       ) = 0;
   
       virtual AirUnitInfo* getCurrentInfo(
       ) = 0;
   
       virtual CORBA_(Boolean) sendMoveAction(
          const MoveAction&  action
       ) = 0;
   
       virtual CORBA_(Boolean) sendGimbalSpeed(
          const GimbalSpeed&  speed
       ) = 0;
   
       virtual CORBA_(Boolean) resetGimbal(
       ) = 0;
   
       virtual CORBA_(Boolean) sendMoveActionSequence(
          const ActionSequence&  actions,
          CORBA_(Short)  times
       ) = 0;
   
       virtual CORBA_(Boolean) sendVehicleInfo(
          const AirUnitInfo&  info
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
          const TrapPoint3D&  trap
       ) = 0;
   
       virtual CORBA_(Boolean) clearTraps(
       ) = 0;
   
       virtual TrapPointSequence* getTraps(
       ) = 0;
   
       virtual CORBA_(Boolean) setTrapPoint(
          const TrapPoint3D&  trap
       ) = 0;
   
       virtual CORBA_(Boolean) setTrack(
          const TaskPath&  track
       ) = 0;
   
       virtual CORBA_(Boolean) setTaskPath(
          const TaskPath&  path
       ) = 0;
   
       virtual CORBA_(Boolean) setTaskPoint(
          const Point3D&  point
       ) = 0;
   
       virtual CORBA_(Boolean) clearTaskPoint(
       ) = 0;
   
       virtual CORBA_(Boolean) setFollower(
          const SRIO_Unit::General_Unit::UnitInfo&  ui
       ) = 0;
   
       virtual CORBA_(Boolean) unsetFollower(
          const iluShortCharacter*  uid
       ) = 0;
   
       virtual CORBA_(Boolean) startPhotoStream(
          CORBA_(Float)  frequency
       ) = 0;
   
       virtual CORBA_(Boolean) stopPhotoStream(
       ) = 0;
   
       virtual CORBA_(Boolean) obtainCtrlAuthority(
       ) = 0;
   
       virtual CORBA_(Boolean) releaseCtrlAuthority(
       ) = 0;
   
       virtual CORBA_(Boolean) setActionRole(
          ActionRole  ar
       ) = 0;
   
       virtual CORBA_(Boolean) setActionMode(
          ActionMode  am
       ) = 0;
   
       virtual CORBA_(Boolean) setCruiseScope(
          const Site&  s
       ) = 0;
   
       virtual CORBA_(Boolean) sendControlledVehicle(
          const UnitSBHSeq&  uss
       ) = 0;
   
       virtual CORBA_(Boolean) confirmThrow(
       ) = 0;
   
       virtual CORBA_(Boolean) cancelThrow(
       ) = 0;
   
       virtual CORBA_(Boolean) actionThrow(
       ) = 0;
   
       virtual CORBA_(Boolean) confirmFire(
       ) = 0;
   
       virtual CORBA_(Boolean) cancelFire(
       ) = 0;
   
       virtual CORBA_(Boolean) confirmFireLocation(
       ) = 0;
   
       virtual CORBA_(Boolean) cancelFireLocation(
       ) = 0;
   
       virtual CORBA_(Boolean) controlVehicleVelocity(
          CORBA_(Float)  vx,
          CORBA_(Float)  vy,
          CORBA_(Float)  vz,
          CORBA_(Float)  angle
       ) = 0;
   
       virtual CORBA_(Boolean) backHome(
       ) = 0;
   
       virtual CORBA_(Boolean) setCruiseSpeed(
          CORBA_(Float)  cs
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Air_Unit_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Air_Unit_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Air_Unit::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Air_Unit();	// default constructor
        virtual ~Air_Unit();	 // destructor

   private:
        Air_Unit(const Air_Unit&);	// copy constructor
        void operator=(const Air_Unit&);	// assignment operator

      };

  // declare the typecode instance for Air_Unit
  NS_EXTERN const CORBA_(TypeCode_ptr) tc_Air_Unit;


//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // initializer class is used to create a single instance that puts the
 // iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class initializer {
    public:
      initializer ();
      void * ensure_instantiation ();
      static initializer sm_the_SRIO_Air_Unit_initializer;
  };
// End the scope for SRIO_Air_Unit
 }

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_SRIO_Air_Unit_CLIENT_ONLY() { \
     SRIO_Air_Unit::initializer::sm_the_SRIO_Air_Unit_initializer.ensure_instantiation();\
     SRIO_Air_Unit_surrogate::Air_Unit_initializer::sm_the_surrogate_SRIO_Air_Unit_Air_Unit_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Air_Unit_SERVER_ONLY() { \
     SRIO_Air_Unit::initializer::sm_the_SRIO_Air_Unit_initializer.ensure_instantiation();\
     SRIO_Air_Unit_true::Air_Unit_initializer::sm_the_true_SRIO_Air_Unit_Air_Unit_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_SRIO_Air_Unit_CLIENT_SERVER() { \
     SRIO_Air_Unit::initializer::sm_the_SRIO_Air_Unit_initializer.ensure_instantiation();\
     SRIO_Air_Unit_surrogate::Air_Unit_initializer::sm_the_surrogate_SRIO_Air_Unit_Air_Unit_initializer.ensure_instantiation(); \
     SRIO_Air_Unit_true::Air_Unit_initializer::sm_the_true_SRIO_Air_Unit_Air_Unit_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::UnitSBHSeq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Site
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Site& r_SRIO_Air_Unit_Air_Unit_Site);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Site& r_SRIO_Air_Unit_Air_Unit_Site);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::Site& r_SRIO_Air_Unit_Air_Unit_Site);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::CircleData
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::CircleData& r_SRIO_Air_Unit_Air_Unit_CircleData);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::CircleData& r_SRIO_Air_Unit_Air_Unit_CircleData);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::CircleData& r_SRIO_Air_Unit_Air_Unit_CircleData);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::RectangleData
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::RectangleData& r_SRIO_Air_Unit_Air_Unit_RectangleData);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::RectangleData& r_SRIO_Air_Unit_Air_Unit_RectangleData);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::RectangleData& r_SRIO_Air_Unit_Air_Unit_RectangleData);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Formation
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Formation& r_SRIO_Air_Unit_Air_Unit_Formation);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Formation& r_SRIO_Air_Unit_Air_Unit_Formation);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::Formation& r_SRIO_Air_Unit_Air_Unit_Formation);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::TrapPointSequence
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::TaskPath
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::ActionSequence
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::TrapPoint3D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_SRIO_Air_Unit_Air_Unit_TrapPoint3D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_SRIO_Air_Unit_Air_Unit_TrapPoint3D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_SRIO_Air_Unit_Air_Unit_TrapPoint3D);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Point3D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Point3D& r_SRIO_Air_Unit_Air_Unit_Point3D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Point3D& r_SRIO_Air_Unit_Air_Unit_Point3D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::Point3D& r_SRIO_Air_Unit_Air_Unit_Point3D);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::AirUnitInfo
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_SRIO_Air_Unit_Air_Unit_AirUnitInfo);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_SRIO_Air_Unit_Air_Unit_AirUnitInfo);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_SRIO_Air_Unit_Air_Unit_AirUnitInfo);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::FusionAngularVelocity
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Speed3D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Speed3D& r_SRIO_Air_Unit_Air_Unit_Speed3D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Speed3D& r_SRIO_Air_Unit_Air_Unit_Speed3D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::Speed3D& r_SRIO_Air_Unit_Air_Unit_Speed3D);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::GPSInfo
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::GPSInfo& r_SRIO_Air_Unit_Air_Unit_GPSInfo);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::GPSInfo& r_SRIO_Air_Unit_Air_Unit_GPSInfo);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::GPSInfo& r_SRIO_Air_Unit_Air_Unit_GPSInfo);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::Pose3D
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Pose3D& r_SRIO_Air_Unit_Air_Unit_Pose3D);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::Pose3D& r_SRIO_Air_Unit_Air_Unit_Pose3D);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::Pose3D& r_SRIO_Air_Unit_Air_Unit_Pose3D);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::GimbalState
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::GimbalState& r_SRIO_Air_Unit_Air_Unit_GimbalState);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::GimbalState& r_SRIO_Air_Unit_Air_Unit_GimbalState);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::GimbalState& r_SRIO_Air_Unit_Air_Unit_GimbalState);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::GimbalSpeed
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_SRIO_Air_Unit_Air_Unit_GimbalSpeed);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_SRIO_Air_Unit_Air_Unit_GimbalSpeed);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_SRIO_Air_Unit_Air_Unit_GimbalSpeed);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::MoveAction
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::MoveAction& r_SRIO_Air_Unit_Air_Unit_MoveAction);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::MoveAction& r_SRIO_Air_Unit_Air_Unit_MoveAction);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::MoveAction& r_SRIO_Air_Unit_Air_Unit_MoveAction);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::BasicMoveActionData
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit::ActionDuration
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::ActionDuration& r_SRIO_Air_Unit_Air_Unit_ActionDuration);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit::ActionDuration& r_SRIO_Air_Unit_Air_Unit_ActionDuration);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit::ActionDuration& r_SRIO_Air_Unit_Air_Unit_ActionDuration);

  // insertion, extraction, and sizing operators for SRIO_Air_Unit::Air_Unit_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit_var& r_SRIO_Air_Unit_Air_Unit_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const SRIO_Air_Unit::Air_Unit_var& r_SRIO_Air_Unit_Air_Unit_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               SRIO_Air_Unit::Air_Unit_var& r_SRIO_Air_Unit_Air_Unit_var);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for SRIO_Air_Unit_Air_Unit_UnitSBHSeq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_UnitSBHSeq, ilu_sequence_tk,
        "ilut:koGcvCzPGAj93X7FStZeh1dTy8R");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::UnitSBHSeq
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::UnitSBHSeq& r_SRIO_Air_Unit_Air_Unit_UnitSBHSeq);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::UnitSBHSeq* p_SRIO_Air_Unit_Air_Unit_UnitSBHSeq);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::UnitSBHSeq*& rp_SRIO_Air_Unit_Air_Unit_UnitSBHSeq);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_Site
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_Site, ilu_union_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/Site:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Site
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::Site& r_SRIO_Air_Unit_Air_Unit_Site);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::Site* p_SRIO_Air_Unit_Air_Unit_Site);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::Site*& rp_SRIO_Air_Unit_Air_Unit_Site);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_CircleData
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_CircleData, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/CircleData:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::CircleData
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::CircleData& r_SRIO_Air_Unit_Air_Unit_CircleData);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::CircleData* p_SRIO_Air_Unit_Air_Unit_CircleData);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::CircleData*& rp_SRIO_Air_Unit_Air_Unit_CircleData);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_RectangleData
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_RectangleData, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/RectangleData:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::RectangleData
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::RectangleData& r_SRIO_Air_Unit_Air_Unit_RectangleData);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::RectangleData* p_SRIO_Air_Unit_Air_Unit_RectangleData);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::RectangleData*& rp_SRIO_Air_Unit_Air_Unit_RectangleData);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_SiteType
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_SiteType, ilu_enumeration_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/SiteType:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::SiteType
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Air_Unit::Air_Unit::SiteType& r_SRIO_Air_Unit_Air_Unit_SiteType);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::SiteType& r_SRIO_Air_Unit_Air_Unit_SiteType);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_ActionMode
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_ActionMode, ilu_enumeration_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/ActionMode:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::ActionMode
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Air_Unit::Air_Unit::ActionMode& r_SRIO_Air_Unit_Air_Unit_ActionMode);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::ActionMode& r_SRIO_Air_Unit_Air_Unit_ActionMode);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_ActionRole
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_ActionRole, ilu_enumeration_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/ActionRole:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::ActionRole
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Air_Unit::Air_Unit::ActionRole& r_SRIO_Air_Unit_Air_Unit_ActionRole);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::ActionRole& r_SRIO_Air_Unit_Air_Unit_ActionRole);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_Formation
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_Formation, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/Formation:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Formation
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::Formation& r_SRIO_Air_Unit_Air_Unit_Formation);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::Formation* p_SRIO_Air_Unit_Air_Unit_Formation);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::Formation*& rp_SRIO_Air_Unit_Air_Unit_Formation);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_TrapPointSequence
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_TrapPointSequence, ilu_sequence_tk,
        "ilut:oJ79iYTP2pX76MF3a0rHKhDdAS-");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::TrapPointSequence
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::TrapPointSequence& r_SRIO_Air_Unit_Air_Unit_TrapPointSequence);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::TrapPointSequence* p_SRIO_Air_Unit_Air_Unit_TrapPointSequence);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::TrapPointSequence*& rp_SRIO_Air_Unit_Air_Unit_TrapPointSequence);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_TaskPath
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_TaskPath, ilu_sequence_tk,
        "ilut:fXgO5O12b3RECi10savMBsleNfh");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::TaskPath
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::TaskPath& r_SRIO_Air_Unit_Air_Unit_TaskPath);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::TaskPath* p_SRIO_Air_Unit_Air_Unit_TaskPath);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::TaskPath*& rp_SRIO_Air_Unit_Air_Unit_TaskPath);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_ActionSequence
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_ActionSequence, ilu_sequence_tk,
        "ilut:jMVJ5BOiaU73NxUBLjsJREn228E");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::ActionSequence
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::ActionSequence& r_SRIO_Air_Unit_Air_Unit_ActionSequence);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::ActionSequence* p_SRIO_Air_Unit_Air_Unit_ActionSequence);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::ActionSequence*& rp_SRIO_Air_Unit_Air_Unit_ActionSequence);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_TrapPoint3D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_TrapPoint3D, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/TrapPoint3D:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::TrapPoint3D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::TrapPoint3D& r_SRIO_Air_Unit_Air_Unit_TrapPoint3D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::TrapPoint3D* p_SRIO_Air_Unit_Air_Unit_TrapPoint3D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::TrapPoint3D*& rp_SRIO_Air_Unit_Air_Unit_TrapPoint3D);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_Point3D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_Point3D, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/Point3D:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Point3D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::Point3D& r_SRIO_Air_Unit_Air_Unit_Point3D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::Point3D* p_SRIO_Air_Unit_Air_Unit_Point3D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::Point3D*& rp_SRIO_Air_Unit_Air_Unit_Point3D);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_AirUnitInfo
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_AirUnitInfo, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/AirUnitInfo:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::AirUnitInfo
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::AirUnitInfo& r_SRIO_Air_Unit_Air_Unit_AirUnitInfo);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::AirUnitInfo* p_SRIO_Air_Unit_Air_Unit_AirUnitInfo);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::AirUnitInfo*& rp_SRIO_Air_Unit_Air_Unit_AirUnitInfo);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_FusionAngularVelocity
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_FusionAngularVelocity, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/FusionAngularVelocity:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::FusionAngularVelocity
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::FusionAngularVelocity& r_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::FusionAngularVelocity* p_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::FusionAngularVelocity*& rp_SRIO_Air_Unit_Air_Unit_FusionAngularVelocity);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_Speed3D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_Speed3D, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/Speed3D:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Speed3D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::Speed3D& r_SRIO_Air_Unit_Air_Unit_Speed3D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::Speed3D* p_SRIO_Air_Unit_Air_Unit_Speed3D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::Speed3D*& rp_SRIO_Air_Unit_Air_Unit_Speed3D);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_GPSInfo
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_GPSInfo, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/GPSInfo:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::GPSInfo
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::GPSInfo& r_SRIO_Air_Unit_Air_Unit_GPSInfo);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::GPSInfo* p_SRIO_Air_Unit_Air_Unit_GPSInfo);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::GPSInfo*& rp_SRIO_Air_Unit_Air_Unit_GPSInfo);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_Pose3D
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_Pose3D, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/Pose3D:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::Pose3D
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::Pose3D& r_SRIO_Air_Unit_Air_Unit_Pose3D);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::Pose3D* p_SRIO_Air_Unit_Air_Unit_Pose3D);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::Pose3D*& rp_SRIO_Air_Unit_Air_Unit_Pose3D);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_GimbalState
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_GimbalState, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/GimbalState:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::GimbalState
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::GimbalState& r_SRIO_Air_Unit_Air_Unit_GimbalState);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::GimbalState* p_SRIO_Air_Unit_Air_Unit_GimbalState);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::GimbalState*& rp_SRIO_Air_Unit_Air_Unit_GimbalState);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_GimbalSpeed
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_GimbalSpeed, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/GimbalSpeed:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::GimbalSpeed
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::GimbalSpeed& r_SRIO_Air_Unit_Air_Unit_GimbalSpeed);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::GimbalSpeed* p_SRIO_Air_Unit_Air_Unit_GimbalSpeed);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::GimbalSpeed*& rp_SRIO_Air_Unit_Air_Unit_GimbalSpeed);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_MoveAction
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_MoveAction, ilu_union_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/MoveAction:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::MoveAction
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::MoveAction& r_SRIO_Air_Unit_Air_Unit_MoveAction);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::MoveAction* p_SRIO_Air_Unit_Air_Unit_MoveAction);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::MoveAction*& rp_SRIO_Air_Unit_Air_Unit_MoveAction);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_BasicMoveActionData
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_BasicMoveActionData, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/BasicMoveActionData:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::BasicMoveActionData
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::BasicMoveActionData& r_SRIO_Air_Unit_Air_Unit_BasicMoveActionData);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::BasicMoveActionData* p_SRIO_Air_Unit_Air_Unit_BasicMoveActionData);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::BasicMoveActionData*& rp_SRIO_Air_Unit_Air_Unit_BasicMoveActionData);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_ActionDuration
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_ActionDuration, ilu_record_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/ActionDuration:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::ActionDuration
  void operator<<=(CORBA_(Any)& r_any, const SRIO_Air_Unit::Air_Unit::ActionDuration& r_SRIO_Air_Unit_Air_Unit_ActionDuration);
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit::ActionDuration* p_SRIO_Air_Unit_Air_Unit_ActionDuration);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::ActionDuration*& rp_SRIO_Air_Unit_Air_Unit_ActionDuration);


  // define the typecode class for SRIO_Air_Unit_Air_Unit_MoveActionType
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(SRIO_Air_Unit_Air_Unit_MoveActionType, ilu_enumeration_tk,
        "IDL:SRIO_Air_Unit/Air_Unit/MoveActionType:1.0");
  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit::MoveActionType
  void operator<<=(CORBA_(Any)& r_any,  const SRIO_Air_Unit::Air_Unit::MoveActionType& r_SRIO_Air_Unit_Air_Unit_MoveActionType);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any,
                SRIO_Air_Unit::Air_Unit::MoveActionType& r_SRIO_Air_Unit_Air_Unit_MoveActionType);


  // define the typecode class for SRIO_Air_Unit_Air_Unit
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(SRIO_Air_Unit_Air_Unit, ilu_object_tk,
        "IDL:SRIO_Air_Unit/Air_Unit:1.0");

  // declare the Any insert and extract operators for SRIO_Air_Unit::Air_Unit
  void operator<<=(CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit_ptr p_SRIO_Air_Unit_Air_Unit);
  CORBA_(Boolean) operator>>=(const CORBA_(Any)& r_any, SRIO_Air_Unit::Air_Unit_ptr& rp_SRIO_Air_Unit_Air_Unit);

#endif
