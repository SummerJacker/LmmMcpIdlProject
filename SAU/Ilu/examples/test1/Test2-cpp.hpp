
// This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056  Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
// KIS-CORBA information:  http://www.kestrelsystems.ca.

#ifndef __Test2_H_
  #define __Test2_H_
  
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
#ifndef Test2_
  #define Test2_(name) NAME_INSIDE_SCOPE(Test2,name)
#endif
#ifndef Test2
  #define Test2(name) NAME_OUTSIDE_SCOPE(Test2,name)
#endif
  #include "Test1-cpp.hpp" 

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for Test2 
 
    class Test2_E1;
 
    #define g_Test2_E1_index     0
     // Declarations for initialization
     NS_EXTERN void Test2_iluInitialize();
     NS_EXTERN int Test2_g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               Test2_p_initialization_function_list;

     class Test2_U2; 
     typedef iluTemplatableT_var<Test2_U2> Test2_U2_var;

     class Test2_P;
     typedef Test2_P* Test2_P_ptr;
     typedef iluTemplatableObject_var<Test2_P> Test2_P_var;


//////////////////////////////////////////////////////////////////////
// class Test2_P 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Test2_P : public virtual iluObject {
      public:
        // Constructs a new Test2_P using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Test2_P(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(Test2_P::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Test2_P_ptr _duplicate(Test2_P_ptr a_ptr);

        static Test2_P_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (Test2_P_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test2_P_ptr _narrow(iluObject* an_object_ptr) {
          return (Test2_P_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test2_P_ptr _nil();
        Test2_P_ptr _this() { return _duplicate((Test2_P_ptr) this); }

        // IDL specified methods
   
       virtual CORBA_Long SR_to_I(
          CORBA_Float  i
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Test2_P_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Test2_P_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Test2_P::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Test2_P();	// default constructor
        virtual ~Test2_P();	 // destructor

   private:
        Test2_P(const Test2_P&);	// copy constructor
        void operator=(const Test2_P&);	// assignment operator

      };

  // declare the typecode instance for Test2_P
  NS_EXTERN const CORBA_TypeCode_ptr Test2_tc_P;

     typedef Test1_O3     Test2_T1O3;  
     typedef Test1_O3_var Test2_T1O3_var;  
     typedef Test1_O3_ptr Test2_T1O3_ptr;  

     typedef Test1_U3     Test2_T1U3;  
     typedef Test1_U3_var Test2_T1U3_var;  

     typedef Test1_U2     Test2_T1U2;  
     typedef Test1_U2_var Test2_T1U2_var;  

     typedef Test1_TheU     Test2_T1U;  
     typedef Test1_TheU_var Test2_T1U_var;  

     typedef Test1_TheE         Test2_F;  



 class Test2_U2 {
                
         // insertion, extraction, and sizing operators for Test2_U2
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test2_U2();
        Test2_U2(const Test2_U2& r_U2);                   
        ~Test2_U2();
                   
        // assignment
        Test2_U2& operator= (const Test2_U2& r_U2);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test2_U2& self();
                   
        // accessors and modifiers
        Test2_F _d () const;
        void _d (Test2_F new_d);

        void _CString_arm(iluShortCharacter *an__CString_arm);
        void _CString_arm(const iluShortCharacter *an__CString_arm );
        void _CString_arm(const CORBA_String_var& an__CString_arm );
        const iluShortCharacter *_CString_arm() const;  

        void _O1_arm(Test1_O1_ptr an__O1_arm);   
        Test1_O1_ptr _O1_arm() const;

        void _P_arm(Test2_P_ptr an__P_arm);   
        Test2_P_ptr _P_arm() const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 CORBA_String_var* m__CString_arm;    
                 Test1_O1_var* m__O1_arm;    
                 Test2_P_var* m__P_arm;    
        };
                
        Test2_F    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U2
     NS_EXTERN const CORBA_TypeCode_ptr Test2_tc_U2;


///////////////////////////////////////////////////////////////////
// Exception Test2_E1 
 
  class Test2_E1 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test2_E1() { };
      Test2_E1(const Test2_E1& a_E1);
      ~Test2_E1();

      void _raise() { throw *this; };

      // assignment operator
      Test2_E1& operator=(const Test2_E1& a_E1);

      // constructor with member value
      Test2_E1(const Test1_TheU& value);
 
      // Member
      const Test1_TheU& _value() const { return _m_value; }
      Test1_TheU _m_value;
  };

//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // Test2_initializer class is used to create a single instance that puts the
 // Test2_iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class Test2_initializer {
    public:
      Test2_initializer ();
      void * ensure_instantiation ();
      static Test2_initializer sm_the_Test2_initializer;
  };
// End the scope for Test2

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_Test2_CLIENT_ONLY() { \
     Test2_initializer::sm_the_Test2_initializer.ensure_instantiation();\
     Test2_surrogate_P_initializer::sm_the_surrogate_Test2_P_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_Test2_SERVER_ONLY() { \
     Test2_initializer::sm_the_Test2_initializer.ensure_instantiation();\
     Test2_true_P_initializer::sm_the_true_Test2_P_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_Test2_CLIENT_SERVER() { \
     Test2_initializer::sm_the_Test2_initializer.ensure_instantiation();\
     Test2_surrogate_P_initializer::sm_the_surrogate_Test2_P_initializer.ensure_instantiation(); \
     Test2_true_P_initializer::sm_the_true_Test2_P_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for Test2_U2
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test2_U2& r_Test2_U2);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test2_U2& r_Test2_U2);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test2_U2& r_Test2_U2);

  // insertion, extraction, and sizing operators for Test2_P_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test2_P_var& r_Test2_P_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test2_P_var& r_Test2_P_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test2_P_var& r_Test2_P_var);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for Test2_U2
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test2_U2, ilu_union_tk,
        "ilut:dSc47PlWucPws3UX8kBfzRQVxyF");

  // declare the Any insert and extract operators for Test2_U2
  void operator<<=(CORBA_Any& r_any, const Test2_U2& r_Test2_U2);
  void operator<<=(CORBA_Any& r_any, Test2_U2* p_Test2_U2);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test2_U2*& rp_Test2_U2);


  // define the typecode class for Test2_P
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(Test2_P, ilu_object_tk,
        "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS");

  // declare the Any insert and extract operators for Test2_P
  void operator<<=(CORBA_Any& r_any, Test2_P_ptr p_Test2_P);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test2_P_ptr& rp_Test2_P);

#endif
