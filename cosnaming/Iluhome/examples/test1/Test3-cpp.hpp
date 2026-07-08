
// This file was automatically generated with KISORB (version 2.0beta1) tools
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院,All Rights Reserved.
// KISORB information:  Dr. Wang at xcwang89@aliyun.com 

#ifndef __Test3_H_
  #define __Test3_H_
  
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
#ifndef Test3_
  #define Test3_(name) NAME_INSIDE_SCOPE(Test3,name)
#endif
#ifndef Test3
  #define Test3(name) NAME_OUTSIDE_SCOPE(Test3,name)
#endif
  #include "Test1-cpp.hpp" 
  #include "Test2-cpp.hpp" 

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for Test3 
 
    class Test3_E1;
 
    #define g_Test3_E1_index     0
     // Declarations for initialization
     NS_EXTERN void Test3_iluInitialize();
     NS_EXTERN int Test3_g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               Test3_p_initialization_function_list;

     class Test3_FU; 
     typedef iluTemplatableT_var<Test3_FU> Test3_FU_var;

     typedef Test1_O3     Test3_T2T1O3;  
     typedef Test1_O3_var Test3_T2T1O3_var;  
     typedef Test1_O3_ptr Test3_T2T1O3_ptr;  

     typedef Test1_U3     Test3_T2T1U3;  
     typedef Test1_U3_var Test3_T2T1U3_var;  

     class Test3_O;
     typedef Test3_O* Test3_O_ptr;
     typedef iluTemplatableObject_var<Test3_O> Test3_O_var;


//////////////////////////////////////////////////////////////////////
// class Test3_O 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Test3_O : public virtual Test2_T1O3, public virtual Test2_P { 
      public:
        // Constructs a new Test3_O using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Test3_O(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(Test3_O::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Test3_O_ptr _duplicate(Test3_O_ptr a_ptr);

        static Test3_O_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (Test3_O_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test3_O_ptr _narrow(iluObject* an_object_ptr) {
          return (Test3_O_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }


        static Test3_O_ptr _narrow(Test2_T1O3_ptr an_object_ptr) {
          return (Test3_O_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test3_O_ptr _narrow(Test2_P_ptr an_object_ptr) {
          return (Test3_O_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }
        static Test3_O_ptr _nil();
        Test3_O_ptr _this() { return _duplicate((Test3_O_ptr) this); }

        // IDL specified methods
   
       virtual Test2_T1U* I_to_Test1U(
          CORBA_Long  i
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Test3_O_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Test3_O_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Test3_O::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Test3_O();	// default constructor
        virtual ~Test3_O();	 // destructor

   private:
        Test3_O(const Test3_O&);	// copy constructor
        void operator=(const Test3_O&);	// assignment operator

      };

  // declare the typecode instance for Test3_O
  NS_EXTERN const CORBA_TypeCode_ptr Test3_tc_O;



 class Test3_FU {
                
         // insertion, extraction, and sizing operators for Test3_FU
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test3_FU();
        Test3_FU(const Test3_FU& r_FU);                   
        ~Test3_FU();
                   
        // assignment
        Test3_FU& operator= (const Test3_FU& r_FU);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test3_FU& self();
                   
        // accessors and modifiers
        Test2_F _d () const;
        void _d (Test2_F new_d);

        void _O_arm(Test3_O_ptr an__O_arm);   
        Test3_O_ptr _O_arm() const;

        void _CORBA_Long_arm (CORBA_Long an__CORBA_Long_arm);
        CORBA_Long _CORBA_Long_arm () const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 Test3_O_var* m__O_arm;    
                 CORBA_Long m__CORBA_Long_arm;    
        };
                
        Test2_F    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for FU
     NS_EXTERN const CORBA_TypeCode_ptr Test3_tc_FU;


///////////////////////////////////////////////////////////////////
// Exception Test3_E1 
 
  class Test3_E1 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test3_E1() { };
      Test3_E1(const Test3_E1& a_E1);
      ~Test3_E1();

      void _raise() { throw *this; };

      // assignment operator
      Test3_E1& operator=(const Test3_E1& a_E1);

      // constructor with member value
      Test3_E1(const iluShortCharacter* value);
 
      // Member
      const CORBA_String_var& _value() const { return _m_value; }
      CORBA_String_var _m_value;
  };

//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // Test3_initializer class is used to create a single instance that puts the
 // Test3_iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class Test3_initializer {
    public:
      Test3_initializer ();
      void * ensure_instantiation ();
      static Test3_initializer sm_the_Test3_initializer;
  };
// End the scope for Test3

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_Test3_CLIENT_ONLY() { \
     Test3_initializer::sm_the_Test3_initializer.ensure_instantiation();\
     Test3_surrogate_O_initializer::sm_the_surrogate_Test3_O_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_Test3_SERVER_ONLY() { \
     Test3_initializer::sm_the_Test3_initializer.ensure_instantiation();\
     Test3_true_O_initializer::sm_the_true_Test3_O_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_Test3_CLIENT_SERVER() { \
     Test3_initializer::sm_the_Test3_initializer.ensure_instantiation();\
     Test3_surrogate_O_initializer::sm_the_surrogate_Test3_O_initializer.ensure_instantiation(); \
     Test3_true_O_initializer::sm_the_true_Test3_O_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for Test3_FU
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test3_FU& r_Test3_FU);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test3_FU& r_Test3_FU);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test3_FU& r_Test3_FU);

  // insertion, extraction, and sizing operators for Test3_O_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test3_O_var& r_Test3_O_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test3_O_var& r_Test3_O_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test3_O_var& r_Test3_O_var);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for Test3_FU
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test3_FU, ilu_union_tk,
        "ilut:p7oYELOBiB2uFXthQiHxgFh1H8p");

  // declare the Any insert and extract operators for Test3_FU
  void operator<<=(CORBA_Any& r_any, const Test3_FU& r_Test3_FU);
  void operator<<=(CORBA_Any& r_any, Test3_FU* p_Test3_FU);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test3_FU*& rp_Test3_FU);


  // define the typecode class for Test3_O
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(Test3_O, ilu_object_tk,
        "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg");

  // declare the Any insert and extract operators for Test3_O
  void operator<<=(CORBA_Any& r_any, Test3_O_ptr p_Test3_O);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test3_O_ptr& rp_Test3_O);

#endif
