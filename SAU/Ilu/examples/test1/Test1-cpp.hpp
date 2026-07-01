
// This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056  Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
// KIS-CORBA information:  http://www.kestrelsystems.ca.

#ifndef __Test1_H_
  #define __Test1_H_
  
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
#ifndef Test1_
  #define Test1_(name) NAME_INSIDE_SCOPE(Test1,name)
#endif
#ifndef Test1
  #define Test1(name) NAME_OUTSIDE_SCOPE(Test1,name)
#endif

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for Test1 
 
    class Test1_E1;
    class Test1_E2;
    class Test1_CantCreate;
    class Test1_E3;
    class Test1_E4;
    class Test1_E5;
    class Test1_E6;
    class Test1_E7;
    class Test1_E8;
    class Test1_E9;
 
    #define g_Test1_E1_index     0
    #define g_Test1_E2_index     1
    #define g_Test1_CantCreate_index     2
    #define g_Test1_E3_index     3
    #define g_Test1_E4_index     4
    #define g_Test1_E5_index     5
    #define g_Test1_E6_index     6
    #define g_Test1_E7_index     7
    #define g_Test1_E8_index     8
    #define g_Test1_E9_index     9
     // Declarations for initialization
     NS_EXTERN void Test1_iluInitialize();
     NS_EXTERN int Test1_g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               Test1_p_initialization_function_list;

     typedef iluCharacter         Test1_C;  

     typedef CORBA_Char         Test1_SC;  

     typedef CORBA_Long         Test1_I;  

     class Test1_O3;
     typedef Test1_O3* Test1_O3_ptr;
     typedef iluTemplatableObject_var<Test1_O3> Test1_O3_var;

     class Test1_TheO1;
     typedef Test1_TheO1* Test1_TheO1_ptr;
     typedef iluTemplatableObject_var<Test1_TheO1> Test1_TheO1_var;

     enum Test1_TheE { Test1_ev1 = 0, Test1_ev3 = 3, Test1_ev5 = 4, Test1_ev7 = 5 };

     // declare the typecode instance for TheE
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_TheE;

     class Test1_TheU; 
     typedef iluTemplatableT_var<Test1_TheU> Test1_TheU_var;

     typedef Test1_TheO1     Test1_O1;  
     typedef Test1_TheO1_var Test1_O1_var;  
     typedef Test1_TheO1_ptr Test1_O1_ptr;  

     struct Test1_TheR;
     typedef iluTemplatableT_var<Test1_TheR> Test1_TheR_var;

     typedef iluShortCharacter* Test1_ScS;
     typedef const iluShortCharacter* Test1_const_ScS;

     class Test1_O4;
     typedef Test1_O4* Test1_O4_ptr;
     typedef iluTemplatableObject_var<Test1_O4> Test1_O4_var;

     class Test1_P;
     typedef Test1_P* Test1_P_ptr;
     typedef iluTemplatableObject_var<Test1_P> Test1_P_var;

     typedef Test1_TheO1     Test1_One;  
     typedef Test1_TheO1_var Test1_One_var;  
     typedef Test1_TheO1_ptr Test1_One_ptr;  

     typedef Test1_TheE         Test1_E;  

     typedef Test1_TheU     Test1_U;  
     typedef Test1_TheU_var Test1_U_var;  


     typedef Test1_TheO1_ptr         Test1_TheOO; 
     typedef const Test1_TheO1_ptr  Test1_const_TheOO; 
     typedef Test1_TheO1_var        Test1_TheOO_var; 

     struct Test1_TheOO_forany; 

     typedef Test1_TheR     Test1_R;  
     typedef Test1_TheR_var Test1_R_var;  

      class Test1_BS;
      typedef iluTemplatableSequence_var<Test1_BS, CORBA_Octet> Test1_BS_var; 

     class Test1_A2_var;
     class Test1_A2_forany;
     typedef CORBA_ULong Test1_A2[3][4];
     typedef CORBA_ULong Test1_A2_slice[4];
     NS_EXTERN Test1_A2_slice* Test1_A2_alloc();
     NS_EXTERN Test1_A2_slice*  Test1_A2_dup
             (const Test1_A2_slice* p_A2_slice);
     NS_EXTERN void Test1_A2_free
             (Test1_A2_slice* p_A2_slice);
     NS_EXTERN void Test1_A2_copy(
             Test1_A2_slice *p_to_A2_slice, 
             const Test1_A2_slice *p_from_A2_slice);

     class Test1_TheA1_var;
     class Test1_TheA1_forany;
     typedef CORBA_String_var Test1_TheA1[3];
     typedef CORBA_String_var Test1_TheA1_slice;
     NS_EXTERN Test1_TheA1_slice* Test1_TheA1_alloc();
     NS_EXTERN Test1_TheA1_slice*  Test1_TheA1_dup
             (const Test1_TheA1_slice* p_TheA1_slice);
     NS_EXTERN void Test1_TheA1_free
             (Test1_TheA1_slice* p_TheA1_slice);
     NS_EXTERN void Test1_TheA1_copy(
             Test1_TheA1_slice *p_to_TheA1_slice, 
             const Test1_TheA1_slice *p_from_TheA1_slice);

     class Test1_A0_var;
     class Test1_A0_forany;
     typedef CORBA_Octet Test1_A0[8];
     typedef CORBA_Octet Test1_A0_slice;
     NS_EXTERN Test1_A0_slice* Test1_A0_alloc();
     NS_EXTERN Test1_A0_slice*  Test1_A0_dup
             (const Test1_A0_slice* p_A0_slice);
     NS_EXTERN void Test1_A0_free
             (Test1_A0_slice* p_A0_slice);
     NS_EXTERN void Test1_A0_copy(
             Test1_A0_slice *p_to_A0_slice, 
             const Test1_A0_slice *p_from_A0_slice);

      class Test1_CSS;
      typedef iluTemplatableSequence_var<Test1_CSS, CORBA_String_var> Test1_CSS_var; 

      class Test1_IS;
      typedef iluTemplatableSequence_var<Test1_IS, CORBA_Long> Test1_IS_var; 

     typedef Test1_TheOO              Test1_OO;  
     typedef Test1_TheOO_forany  Test1_OO_forany;  

     typedef Test1_TheR*            Test1_RO; 
     typedef const Test1_TheR*      Test1_const_RO; 
     struct Test1_RO_forany; 

      class Test1_TheRS;
      typedef iluTemplatableSequence_var<Test1_TheRS, Test1_R> Test1_TheRS_var; 

     typedef Test1_TheA1         Test1_A1;  
     typedef Test1_TheA1_slice   Test1_A1_slice;  
     typedef Test1_TheA1_var     Test1_A1_var;  

     typedef Test1_TheA1_forany  Test1_A1_forany;  

     typedef Test1_TheRS     Test1_RS;  
     typedef Test1_TheRS_var Test1_RS_var;  

     class Test1_O2;
     typedef Test1_O2* Test1_O2_ptr;
     typedef iluTemplatableObject_var<Test1_O2> Test1_O2_var;

     class Test1_U_scard; 
     typedef iluTemplatableT_var<Test1_U_scard> Test1_U_scard_var;

     class Test1_U_card; 
     typedef iluTemplatableT_var<Test1_U_card> Test1_U_card_var;

     class Test1_U_int; 
     typedef iluTemplatableT_var<Test1_U_int> Test1_U_int_var;

     class Test1_U_byte; 
     typedef iluTemplatableT_var<Test1_U_byte> Test1_U_byte_var;

     class Test1_U4; 
     typedef iluTemplatableT_var<Test1_U4> Test1_U4_var;

     class Test1_U3; 
     typedef iluTemplatableT_var<Test1_U3> Test1_U3_var;

     class Test1_U2; 
     typedef iluTemplatableT_var<Test1_U2> Test1_U2_var;

     class Test1_U1; 
     typedef iluTemplatableT_var<Test1_U1> Test1_U1_var;

     class Test1_OO2; 
     typedef iluTemplatableT_var<Test1_OO2> Test1_OO2_var;


//////////////////////////////////////////////////////////////////////
// class Test1_O3 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Test1_O3 : public virtual iluObject {
      public:
        // Constructs a new Test1_O3 using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Test1_O3(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(Test1_O3::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Test1_O3_ptr _duplicate(Test1_O3_ptr a_ptr);

        static Test1_O3_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (Test1_O3_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_O3_ptr _narrow(iluObject* an_object_ptr) {
          return (Test1_O3_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_O3_ptr _nil();
        Test1_O3_ptr _this() { return _duplicate((Test1_O3_ptr) this); }

        // IDL specified methods
   
       virtual Test1_IS* RS_R_to_R_IS(
          const Test1_RS&  r,
          Test1_R*&  r2
       ) = 0;

       virtual void O1_U_to_U(
          Test1_O1_ptr  o,
          Test1_U&  u
       ) = 0;
   
       virtual CORBA_Long BS_to_I(
          const Test1_BS&  b
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Test1_O3_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Test1_O3_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Test1_O3::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Test1_O3();	// default constructor
        virtual ~Test1_O3();	 // destructor

   private:
        Test1_O3(const Test1_O3&);	// copy constructor
        void operator=(const Test1_O3&);	// assignment operator

      };

  // declare the typecode instance for Test1_O3
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_O3;


//////////////////////////////////////////////////////////////////////
// class Test1_TheO1 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Test1_TheO1 : public virtual iluObject {
      public:
        // Constructs a new Test1_TheO1 using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Test1_TheO1(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(Test1_TheO1::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Test1_TheO1_ptr _duplicate(Test1_TheO1_ptr a_ptr);

        static Test1_TheO1_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (Test1_TheO1_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_TheO1_ptr _narrow(iluObject* an_object_ptr) {
          return (Test1_TheO1_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_TheO1_ptr _nil();
        Test1_TheO1_ptr _this() { return _duplicate((Test1_TheO1_ptr) this); }

        // IDL specified methods
   
       virtual Test1_U* U_CSS_to_U(
          const Test1_U&  u,
          const Test1_CSS&  css
       ) = 0;
   
       virtual Test1_R* f_CSS_to_RO(
          const Test1_CSS&  css
       ) = 0;
   
       virtual CORBA_Float R_ScS_to_F(
          const Test1_R&  r,
          Test1_const_ScS    s
       ) = 0;

       virtual void a_RO(
          Test1_const_RO    ro
       ) = 0;
   
       virtual Test1_O2_ptr get_O2(
       ) = 0;
   
       virtual Test1_O3_ptr get_O3(
          CORBA_Boolean  subclass
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Test1_TheO1_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Test1_TheO1_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Test1_TheO1::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Test1_TheO1();	// default constructor
        virtual ~Test1_TheO1();	 // destructor

   private:
        Test1_TheO1(const Test1_TheO1&);	// copy constructor
        void operator=(const Test1_TheO1&);	// assignment operator

      };

  // declare the typecode instance for Test1_TheO1
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_TheO1;



 class Test1_OO2 {
                
         // insertion, extraction, and sizing operators for Test1_OO2
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_OO2();
        Test1_OO2(const Test1_OO2& r_OO2);                   
        ~Test1_OO2();
                   
        // assignment
        Test1_OO2& operator= (const Test1_OO2& r_OO2);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_OO2& self();
                   
        // accessors and modifiers
        CORBA_Boolean _d () const;
        void _d (CORBA_Boolean new_d);

        void _O2_arm(Test1_O2_ptr an__O2_arm);   
        Test1_O2_ptr _O2_arm() const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 Test1_O2_var* m__O2_arm;    
        };
                
        CORBA_Boolean    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for OO2
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_OO2;


//////////////////////////////////////////////////////////////////////
// class Test1_O2 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Test1_O2 : public virtual iluObject {
      public:
        // Constructs a new Test1_O2 using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Test1_O2(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(Test1_O2::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Test1_O2_ptr _duplicate(Test1_O2_ptr a_ptr);

        static Test1_O2_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (Test1_O2_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_O2_ptr _narrow(iluObject* an_object_ptr) {
          return (Test1_O2_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_O2_ptr _nil();
        Test1_O2_ptr _this() { return _duplicate((Test1_O2_ptr) this); }

        // IDL specified methods
   
       virtual Test1_CSS* OO_A0_to_CSS(
          Test1_OO  o,
          const Test1_A0  a
       ) = 0;
   
       virtual Test1_A0_slice* R_I_A1_to_I_A0(
          const Test1_R&  r,
          CORBA_Long&  i,
          const Test1_A1  a
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Test1_O2_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Test1_O2_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Test1_O2::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Test1_O2();	// default constructor
        virtual ~Test1_O2();	 // destructor

   private:
        Test1_O2(const Test1_O2&);	// copy constructor
        void operator=(const Test1_O2&);	// assignment operator

      };

  // declare the typecode instance for Test1_O2
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_O2;


////////////////////////////////////////////////////////////////////////
// optional TheOO

  // declare the typecode instance 
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_TheOO;
 
  // used to insert and extract Test1_TheOOs from Anys
  struct Test1_TheOO_forany {
 
      Test1_TheOO_forany( Test1_O1_ptr p_value = NULL) : m_p_value(p_value) {}

      ~Test1_TheOO_forany() { if (m_p_value) m_p_value->_release(); }
 
       // assignment operator
       Test1_TheOO_forany& operator=
         (const Test1_TheOO_forany& r_a_TheOO_forany) {
           if (this != &r_a_TheOO_forany) {
               if (r_a_TheOO_forany.m_p_value)
                   m_p_value =    
                       Test1_O1::_duplicate(r_a_TheOO_forany.m_p_value);
               else m_p_value = NULL;
            }  
          return *this;
       } 

      Test1_O1_ptr m_p_value;
   };


   ////////////////////////////////////////////////////////////////
   // sequence Test1_TheRS

   class Test1_TheRS {

    public:

       // constructors & destructor
        Test1_TheRS ();
        Test1_TheRS (CORBA_ULong max);
        Test1_TheRS (CORBA_ULong max, CORBA_ULong length,
              Test1_R* data, CORBA_Boolean release = ILUCPP_FALSE);
        Test1_TheRS (const Test1_TheRS& r_TheRS);
       ~Test1_TheRS();

        // assignment
        Test1_TheRS& operator= (const Test1_TheRS& r_TheRS);

        // accessors
        CORBA_ULong maximum() const;
        CORBA_ULong length() const;
        void length (CORBA_ULong len);

        // [] operators
        Test1_R& operator [] (CORBA_ULong index);
        const Test1_R& operator [] (CORBA_ULong index) const;

        // memory management
         static Test1_R* allocbuf(CORBA_ULong num_elements);
         static void freebuf(Test1_R* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Test1_TheRS& self();

    private:

          CORBA_ULong m_maximum;
          CORBA_ULong m_length;
          CORBA_Boolean m_release;
          Test1_R* m_buffer;

  };

  // declare the typecode instance for TheRS
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_TheRS;



   ////////////////////////////////////////////////////////////////
   // sequence Test1_BS

   class Test1_BS {

    public:

       // constructors & destructor
        Test1_BS ();
        Test1_BS (CORBA_ULong max);
        Test1_BS (CORBA_ULong max, CORBA_ULong length,
              CORBA_Octet* data, CORBA_Boolean release = ILUCPP_FALSE);
        Test1_BS (const Test1_BS& r_BS);
       ~Test1_BS();

        // assignment
        Test1_BS& operator= (const Test1_BS& r_BS);

        // accessors
        CORBA_ULong maximum() const;
        CORBA_ULong length() const;
        void length (CORBA_ULong len);

        // [] operators
        CORBA_Octet& operator [] (CORBA_ULong index);
        const CORBA_Octet& operator [] (CORBA_ULong index) const;

        // memory management
         static CORBA_Octet* allocbuf(CORBA_ULong num_elements);
         static void freebuf(CORBA_Octet* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Test1_BS& self();

    private:

          CORBA_ULong m_maximum;
          CORBA_ULong m_length;
          CORBA_Boolean m_release;
          CORBA_Octet* m_buffer;

  };

  // declare the typecode instance for BS
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_BS;



   ////////////////////////////////////////////////////////////////
   // array Test1_A2
    
   class Test1_A2_var : public ilu_var {
		
   public:

    // default constructor
    // Added alloc.. inefficient but sunpro error otherwise
    Test1_A2_var() : m_b_release(ILUCPP_TRUE) { 
                m_p_slice = Test1_A2_alloc();
                m_set = ILUCPP_FALSE;
    }

   // construct from slice
   Test1_A2_var(Test1_A2_slice* p_a_Test1_A2_slice) : m_b_release(ILUCPP_TRUE) {
        m_p_slice = p_a_Test1_A2_slice;
      // not completely reliable 
       m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE;
    }

   // copy constructor
   Test1_A2_var(const Test1_A2_var& r_a_Test1_A2) : m_b_release(ILUCPP_TRUE) {
      m_p_slice = Test1_A2_dup((const Test1_A2_slice*) r_a_Test1_A2.m_p_slice);
      m_set = r_a_Test1_A2.m_set;
   }


   // destructor
   ~Test1_A2_var() {
       if (m_b_release) 
            Test1_A2_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   Test1_A2_var& operator=(Test1_A2_slice* p_a_Test1_A2_slice) {
       if (m_p_slice != p_a_Test1_A2_slice)
          if (m_b_release)
             Test1_A2_free (m_p_slice);
           m_p_slice = p_a_Test1_A2_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   Test1_A2_var& operator=(const Test1_A2_var& r_a_Test1_A2) {
        if ((&r_a_Test1_A2 != this) && 
            (m_p_slice != r_a_Test1_A2.m_p_slice)) {
            if (m_b_release)
               Test1_A2_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = Test1_A2_dup((const Test1_A2_slice *) r_a_Test1_A2.m_p_slice);
            m_set = r_a_Test1_A2.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const Test1_A2& () const {	// in parameters
            return *((const Test1_A2*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const Test1_A2_slice* in() const { 
            return *((const Test1_A2*)m_p_slice);
     }

    Test1_A2_slice* out() const { 
            return *((Test1_A2*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator Test1_A2& () const  {  // inout and fixed out parameters

        return *((Test1_A2*)m_p_slice);
    }
#endif

    

    // accessors on the m_b_release member
    void iluSetRelease(ILUCPP_BOOL b_release_on_destruct) const {
        // cast around constness
        ILUCPP_BOOL* p_release = CONST_CAST(ILUCPP_BOOL*, &m_b_release);
        *p_release = b_release_on_destruct;
     }

    ILUCPP_BOOL iluGetRelease() const { return m_b_release; }

    ILUCPP_BOOL iluIsNull() const { return (!m_set); }

    /* Note: the [] operators here have caused operator overloading problems 
     A user workaround is to do something like
     xarray& my_array = my_array_var;
     long temp = my_array_var[i][j]
    */

     // element operator - returns the index'th slice
      Test1_A2_slice& operator[](CORBA_ULong index) {
                 return *(m_p_slice + index);
       }

     const Test1_A2_slice& operator[](CORBA_ULong index) const {
                return ((*this).in())[index];
      }

 protected:
    Test1_A2_slice* m_p_slice;

    // whether or not a delete should be done when the var destructs
    ILUCPP_BOOL m_b_release;

    // for use of corresponding optional as member of structured type
    ILUCPP_BOOL    m_set; 
		
 private:
    Test1_A2_var &operator= (const ilu_var&);
    Test1_A2_var (const ilu_var&);
 };


  // Test1_A2_forany class to support use of arrays with anys
  class Test1_A2_forany : public ilu_var {

   public:

      // default constructor
      Test1_A2_forany() : m_p_slice(ILUCPP_NULL), m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) { m_set = ILUCPP_FALSE;}

     // construct from slice
    Test1_A2_forany(Test1_A2_slice* p_a_Test1_A2_slice, CORBA_Boolean b_nocopy = ILUCPP_FALSE) 
        :  m_p_slice(p_a_Test1_A2_slice), m_b_release(ILUCPP_TRUE), m_b_nocopy(b_nocopy) { m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE; }

    // copy constructor
    Test1_A2_forany(const Test1_A2_forany& r_a_Test1_A2) : m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) {
    m_p_slice = Test1_A2_dup((const Test1_A2_slice *) r_a_Test1_A2.m_p_slice);
     m_set = r_a_Test1_A2.m_set;
    }

   // destructor
   ~Test1_A2_forany() {
       if (m_b_release) 
            Test1_A2_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   Test1_A2_forany& operator=(Test1_A2_slice* p_a_Test1_A2_slice) {
       if (m_p_slice != p_a_Test1_A2_slice)
          if (m_b_release)
             Test1_A2_free (m_p_slice);
           m_p_slice = p_a_Test1_A2_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   Test1_A2_forany& operator=(const Test1_A2_forany& r_a_Test1_A2) {
        if ((&r_a_Test1_A2 != this) && 
            (m_p_slice != r_a_Test1_A2.m_p_slice)) {
            if (m_b_release)
               Test1_A2_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = Test1_A2_dup((const Test1_A2_slice *) r_a_Test1_A2.m_p_slice);
            m_set = r_a_Test1_A2.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const Test1_A2& () const {	// in parameters
            return *((const Test1_A2*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const Test1_A2_slice* in() const { 
            return *((const Test1_A2*)m_p_slice);
     }

    Test1_A2_slice* out() const { 
            return *((Test1_A2*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator Test1_A2& () const  {  // inout and fixed out parameters

        return *((Test1_A2*)m_p_slice);
    }
#endif

    

    // accessors on the m_b_release member
    void iluSetRelease(ILUCPP_BOOL b_release_on_destruct) const {
        // cast around constness
        ILUCPP_BOOL* p_release = CONST_CAST(ILUCPP_BOOL*, &m_b_release);
        *p_release = b_release_on_destruct;
     }

    ILUCPP_BOOL iluGetRelease() const { return m_b_release; }

    ILUCPP_BOOL iluIsNull() const { return (!m_set); }


     // accessors on the m_b_nocopy member
     void iluSetNoCopy(ILUCPP_BOOL b_nocopy) const {
          // cast around constness
           ILUCPP_BOOL* p_nocopy = CONST_CAST(ILUCPP_BOOL*, &m_b_nocopy);
           *p_nocopy = b_nocopy;
     }

    // used by ilu when we transfer ownership of the content to the any 
    CORBA_Boolean iluShouldCopy() const {
         return (m_b_nocopy ? ILUCPP_FALSE : ILUCPP_TRUE);}
    Test1_A2_slice* iluGetSlice() const {return m_p_slice;}		

 protected:
      Test1_A2_slice* m_p_slice;

     // whether or not a delete should be done when the var destructs
      ILUCPP_BOOL m_b_release;

     // for use of corresponding optional as member of structured type
     ILUCPP_BOOL    m_set; 
		
 private:
    Test1_A2_forany &operator= (const ilu_var&);
    Test1_A2_forany (const ilu_var&);

    CORBA_Boolean m_b_nocopy;
 };
   

   // declare the typecode instance for Test1_A2
   NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_A2;

   // insertion, extraction, and sizing functions for Test1_Test1_A2
   // Note we cant use overloaded operators since arrays map to arrays, and
   // simple typedefs do not distinguish among overloaded functions
	
   NS_EXTERN iluBaseCall& Test1_size_const_A2 (
        iluBaseCall& r_call, const CORBA_ULong a_Test1_A2[] [4]);
   NS_EXTERN  iluBaseCall& Test1_size_A2 (
         iluBaseCall& r_call, CORBA_ULong a_Test1_A2[][4]);
   NS_EXTERN iluBaseCall& Test1_output_const_A2(
         iluBaseCall& r_call, const CORBA_ULong a_Test1_A2[][4]);
   NS_EXTERN iluBaseCall& Test1_output_A2(
         iluBaseCall& r_call, CORBA_ULong a_Test1_A2[][4]);
   NS_EXTERN iluBaseCall& Test1_input_A2(
         iluBaseCall& r_call, CORBA_ULong a_Test1_A2[][4]);



   ////////////////////////////////////////////////////////////////
   // array Test1_A0
    
   class Test1_A0_var : public ilu_var {
		
   public:

    // default constructor
    // Added alloc.. inefficient but sunpro error otherwise
    Test1_A0_var() : m_b_release(ILUCPP_TRUE) { 
                m_p_slice = Test1_A0_alloc();
                m_set = ILUCPP_FALSE;
    }

   // construct from slice
   Test1_A0_var(Test1_A0_slice* p_a_Test1_A0_slice) : m_b_release(ILUCPP_TRUE) {
        m_p_slice = p_a_Test1_A0_slice;
      // not completely reliable 
       m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE;
    }

   // copy constructor
   Test1_A0_var(const Test1_A0_var& r_a_Test1_A0) : m_b_release(ILUCPP_TRUE) {
      m_p_slice = Test1_A0_dup((const Test1_A0_slice*) r_a_Test1_A0.m_p_slice);
      m_set = r_a_Test1_A0.m_set;
   }


   // destructor
   ~Test1_A0_var() {
       if (m_b_release) 
            Test1_A0_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   Test1_A0_var& operator=(Test1_A0_slice* p_a_Test1_A0_slice) {
       if (m_p_slice != p_a_Test1_A0_slice)
          if (m_b_release)
             Test1_A0_free (m_p_slice);
           m_p_slice = p_a_Test1_A0_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   Test1_A0_var& operator=(const Test1_A0_var& r_a_Test1_A0) {
        if ((&r_a_Test1_A0 != this) && 
            (m_p_slice != r_a_Test1_A0.m_p_slice)) {
            if (m_b_release)
               Test1_A0_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = Test1_A0_dup((const Test1_A0_slice *) r_a_Test1_A0.m_p_slice);
            m_set = r_a_Test1_A0.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const Test1_A0& () const {	// in parameters
            return *((const Test1_A0*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const Test1_A0_slice* in() const { 
            return *((const Test1_A0*)m_p_slice);
     }

    Test1_A0_slice* out() const { 
            return *((Test1_A0*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator Test1_A0& () const  {  // inout and fixed out parameters

        return *((Test1_A0*)m_p_slice);
    }
#endif

    

    // accessors on the m_b_release member
    void iluSetRelease(ILUCPP_BOOL b_release_on_destruct) const {
        // cast around constness
        ILUCPP_BOOL* p_release = CONST_CAST(ILUCPP_BOOL*, &m_b_release);
        *p_release = b_release_on_destruct;
     }

    ILUCPP_BOOL iluGetRelease() const { return m_b_release; }

    ILUCPP_BOOL iluIsNull() const { return (!m_set); }

    /* Note: the [] operators here have caused operator overloading problems 
     A user workaround is to do something like
     xarray& my_array = my_array_var;
     long temp = my_array_var[i][j]
    */

     // element operator - returns the index'th slice
      Test1_A0_slice& operator[](CORBA_ULong index) {
                 return *(m_p_slice + index);
       }

     const Test1_A0_slice& operator[](CORBA_ULong index) const {
                return ((*this).in())[index];
      }

 protected:
    Test1_A0_slice* m_p_slice;

    // whether or not a delete should be done when the var destructs
    ILUCPP_BOOL m_b_release;

    // for use of corresponding optional as member of structured type
    ILUCPP_BOOL    m_set; 
		
 private:
    Test1_A0_var &operator= (const ilu_var&);
    Test1_A0_var (const ilu_var&);
 };


  // Test1_A0_forany class to support use of arrays with anys
  class Test1_A0_forany : public ilu_var {

   public:

      // default constructor
      Test1_A0_forany() : m_p_slice(ILUCPP_NULL), m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) { m_set = ILUCPP_FALSE;}

     // construct from slice
    Test1_A0_forany(Test1_A0_slice* p_a_Test1_A0_slice, CORBA_Boolean b_nocopy = ILUCPP_FALSE) 
        :  m_p_slice(p_a_Test1_A0_slice), m_b_release(ILUCPP_TRUE), m_b_nocopy(b_nocopy) { m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE; }

    // copy constructor
    Test1_A0_forany(const Test1_A0_forany& r_a_Test1_A0) : m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) {
    m_p_slice = Test1_A0_dup((const Test1_A0_slice *) r_a_Test1_A0.m_p_slice);
     m_set = r_a_Test1_A0.m_set;
    }

   // destructor
   ~Test1_A0_forany() {
       if (m_b_release) 
            Test1_A0_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   Test1_A0_forany& operator=(Test1_A0_slice* p_a_Test1_A0_slice) {
       if (m_p_slice != p_a_Test1_A0_slice)
          if (m_b_release)
             Test1_A0_free (m_p_slice);
           m_p_slice = p_a_Test1_A0_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   Test1_A0_forany& operator=(const Test1_A0_forany& r_a_Test1_A0) {
        if ((&r_a_Test1_A0 != this) && 
            (m_p_slice != r_a_Test1_A0.m_p_slice)) {
            if (m_b_release)
               Test1_A0_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = Test1_A0_dup((const Test1_A0_slice *) r_a_Test1_A0.m_p_slice);
            m_set = r_a_Test1_A0.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const Test1_A0& () const {	// in parameters
            return *((const Test1_A0*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const Test1_A0_slice* in() const { 
            return *((const Test1_A0*)m_p_slice);
     }

    Test1_A0_slice* out() const { 
            return *((Test1_A0*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator Test1_A0& () const  {  // inout and fixed out parameters

        return *((Test1_A0*)m_p_slice);
    }
#endif

    

    // accessors on the m_b_release member
    void iluSetRelease(ILUCPP_BOOL b_release_on_destruct) const {
        // cast around constness
        ILUCPP_BOOL* p_release = CONST_CAST(ILUCPP_BOOL*, &m_b_release);
        *p_release = b_release_on_destruct;
     }

    ILUCPP_BOOL iluGetRelease() const { return m_b_release; }

    ILUCPP_BOOL iluIsNull() const { return (!m_set); }


     // accessors on the m_b_nocopy member
     void iluSetNoCopy(ILUCPP_BOOL b_nocopy) const {
          // cast around constness
           ILUCPP_BOOL* p_nocopy = CONST_CAST(ILUCPP_BOOL*, &m_b_nocopy);
           *p_nocopy = b_nocopy;
     }

    // used by ilu when we transfer ownership of the content to the any 
    CORBA_Boolean iluShouldCopy() const {
         return (m_b_nocopy ? ILUCPP_FALSE : ILUCPP_TRUE);}
    Test1_A0_slice* iluGetSlice() const {return m_p_slice;}		

 protected:
      Test1_A0_slice* m_p_slice;

     // whether or not a delete should be done when the var destructs
      ILUCPP_BOOL m_b_release;

     // for use of corresponding optional as member of structured type
     ILUCPP_BOOL    m_set; 
		
 private:
    Test1_A0_forany &operator= (const ilu_var&);
    Test1_A0_forany (const ilu_var&);

    CORBA_Boolean m_b_nocopy;
 };
   

   // declare the typecode instance for Test1_A0
   NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_A0;

   // insertion, extraction, and sizing functions for Test1_Test1_A0
   // Note we cant use overloaded operators since arrays map to arrays, and
   // simple typedefs do not distinguish among overloaded functions
	
   NS_EXTERN iluBaseCall& Test1_size_const_A0 (
        iluBaseCall& r_call, const CORBA_Octet a_Test1_A0[] );
   NS_EXTERN  iluBaseCall& Test1_size_A0 (
         iluBaseCall& r_call, CORBA_Octet a_Test1_A0[]);
   NS_EXTERN iluBaseCall& Test1_output_const_A0(
         iluBaseCall& r_call, const CORBA_Octet a_Test1_A0[]);
   NS_EXTERN iluBaseCall& Test1_output_A0(
         iluBaseCall& r_call, CORBA_Octet a_Test1_A0[]);
   NS_EXTERN iluBaseCall& Test1_input_A0(
         iluBaseCall& r_call, CORBA_Octet a_Test1_A0[]);



   ////////////////////////////////////////////////////////////////
   // sequence Test1_CSS

   class Test1_CSS {

    public:

       // constructors & destructor
        Test1_CSS ();
        Test1_CSS (CORBA_ULong max);
        Test1_CSS (CORBA_ULong max, CORBA_ULong length,
              iluShortCharacter** data, CORBA_Boolean release = ILUCPP_FALSE);
        Test1_CSS (const Test1_CSS& r_CSS);
       ~Test1_CSS();

        // assignment
        Test1_CSS& operator= (const Test1_CSS& r_CSS);

        // accessors
        CORBA_ULong maximum() const;
        CORBA_ULong length() const;
        void length (CORBA_ULong len);

        // [] operators
        CORBA_String_var& operator [] (CORBA_ULong index);
        const CORBA_String_var& operator [] (CORBA_ULong index) const;

        // memory management
         static iluShortCharacter** allocbuf(CORBA_ULong num_elements);
         static void freebuf(iluShortCharacter** p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Test1_CSS& self();

    private:

          CORBA_ULong m_maximum;
          CORBA_ULong m_length;
          CORBA_Boolean m_release;
          iluShortCharacter** m_buffer;
          CORBA_String_var* m_varbuffer;

  };

  // declare the typecode instance for CSS
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_CSS;



   ////////////////////////////////////////////////////////////////
   // sequence Test1_IS

   class Test1_IS {

    public:

       // constructors & destructor
        Test1_IS ();
        Test1_IS (CORBA_ULong max);
        Test1_IS (CORBA_ULong max, CORBA_ULong length,
              CORBA_Long* data, CORBA_Boolean release = ILUCPP_FALSE);
        Test1_IS (const Test1_IS& r_IS);
       ~Test1_IS();

        // assignment
        Test1_IS& operator= (const Test1_IS& r_IS);

        // accessors
        CORBA_ULong maximum() const;
        CORBA_ULong length() const;
        void length (CORBA_ULong len);

        // [] operators
        CORBA_Long& operator [] (CORBA_ULong index);
        const CORBA_Long& operator [] (CORBA_ULong index) const;

        // memory management
         static CORBA_Long* allocbuf(CORBA_ULong num_elements);
         static void freebuf(CORBA_Long* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Test1_IS& self();

    private:

          CORBA_ULong m_maximum;
          CORBA_ULong m_length;
          CORBA_Boolean m_release;
          CORBA_Long* m_buffer;

  };

  // declare the typecode instance for IS
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_IS;


//////////////////////////////////////////////////////////////////////
// class Test1_O4 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Test1_O4 : public virtual Test1_O3 { 
      public:
        // Constructs a new Test1_O4 using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Test1_O4(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(Test1_O4::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Test1_O4_ptr _duplicate(Test1_O4_ptr a_ptr);

        static Test1_O4_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (Test1_O4_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_O4_ptr _narrow(iluObject* an_object_ptr) {
          return (Test1_O4_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }


        static Test1_O4_ptr _narrow(Test1_O3_ptr an_object_ptr) {
          return (Test1_O4_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }
        static Test1_O4_ptr _nil();
        Test1_O4_ptr _this() { return _duplicate((Test1_O4_ptr) this); }

        // IDL specified methods
   
       virtual CORBA_Double R_to_R(
          CORBA_Double  r
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Test1_O4_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Test1_O4_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Test1_O4::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Test1_O4();	// default constructor
        virtual ~Test1_O4();	 // destructor

   private:
        Test1_O4(const Test1_O4&);	// copy constructor
        void operator=(const Test1_O4&);	// assignment operator

      };

  // declare the typecode instance for Test1_O4
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_O4;


//////////////////////////////////////////////////////////////////////
// class Test1_P 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class Test1_P : public virtual Test1_O3 { 
      public:
        // Constructs a new Test1_P using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        Test1_P(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(Test1_P::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static Test1_P_ptr _duplicate(Test1_P_ptr a_ptr);

        static Test1_P_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (Test1_P_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static Test1_P_ptr _narrow(iluObject* an_object_ptr) {
          return (Test1_P_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }


        static Test1_P_ptr _narrow(Test1_O3_ptr an_object_ptr) {
          return (Test1_P_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }
        static Test1_P_ptr _nil();
        Test1_P_ptr _this() { return _duplicate((Test1_P_ptr) this); }

        // IDL specified methods
   
       virtual Test1_IS* m2(
          CORBA_Long  j
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static Test1_P_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(Test1_P_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->Test1_P::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        Test1_P();	// default constructor
        virtual ~Test1_P();	 // destructor

   private:
        Test1_P(const Test1_P&);	// copy constructor
        void operator=(const Test1_P&);	// assignment operator

      };

  // declare the typecode instance for Test1_P
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_P;



 class Test1_U4 {
                
         // insertion, extraction, and sizing operators for Test1_U4
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U4();
        Test1_U4(const Test1_U4& r_U4);                   
        ~Test1_U4();
                   
        // assignment
        Test1_U4& operator= (const Test1_U4& r_U4);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U4& self();
                   
        // accessors and modifiers
        CORBA_Short _d () const;
        void _d (CORBA_Short new_d);

        void x1 (CORBA_Boolean an_x1);
        CORBA_Boolean x1 () const;

        void x2(Test1_O2_ptr an_x2);   
        Test1_O2_ptr x2() const;

       void x3(const Test1_CSS & an_x3); 
       const Test1_CSS& x3() const;
       Test1_CSS& x3();
         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 CORBA_Boolean m_x1;    
                 Test1_O2_var* m_x2;    
                 Test1_CSS* m_x3;    
        };
                
        CORBA_Short    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U4
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U4;



 class Test1_U2 {
                
         // insertion, extraction, and sizing operators for Test1_U2
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U2();
        Test1_U2(const Test1_U2& r_U2);                   
        ~Test1_U2();
                   
        // assignment
        Test1_U2& operator= (const Test1_U2& r_U2);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U2& self();
                   
        // accessors and modifiers
        CORBA_Short _d () const;
        void _d (CORBA_Short new_d);

        void x1 (CORBA_Boolean an_x1);
        CORBA_Boolean x1 () const;

        void x2(Test1_O2_ptr an_x2);   
        Test1_O2_ptr x2() const;

       void x3(const Test1_CSS & an_x3); 
       const Test1_CSS& x3() const;
       Test1_CSS& x3();
         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 CORBA_Boolean m_x1;    
                 Test1_O2_var* m_x2;    
                 Test1_CSS* m_x3;    
        };
                
        CORBA_Short    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U2
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U2;



   ////////////////////////////////////////////////////////////////
   // array Test1_TheA1
    
   class Test1_TheA1_var : public ilu_var {
		
   public:

    // default constructor
    // Added alloc.. inefficient but sunpro error otherwise
    Test1_TheA1_var() : m_b_release(ILUCPP_TRUE) { 
                m_p_slice = Test1_TheA1_alloc();
                m_set = ILUCPP_FALSE;
    }

   // construct from slice
   Test1_TheA1_var(Test1_TheA1_slice* p_a_Test1_TheA1_slice) : m_b_release(ILUCPP_TRUE) {
        m_p_slice = p_a_Test1_TheA1_slice;
      // not completely reliable 
       m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE;
    }

   // copy constructor
   Test1_TheA1_var(const Test1_TheA1_var& r_a_Test1_TheA1) : m_b_release(ILUCPP_TRUE) {
      m_p_slice = Test1_TheA1_dup((const Test1_TheA1_slice*) r_a_Test1_TheA1.m_p_slice);
      m_set = r_a_Test1_TheA1.m_set;
   }


   // destructor
   ~Test1_TheA1_var() {
       if (m_b_release) 
            Test1_TheA1_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   Test1_TheA1_var& operator=(Test1_TheA1_slice* p_a_Test1_TheA1_slice) {
       if (m_p_slice != p_a_Test1_TheA1_slice)
          if (m_b_release)
             Test1_TheA1_free (m_p_slice);
           m_p_slice = p_a_Test1_TheA1_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   Test1_TheA1_var& operator=(const Test1_TheA1_var& r_a_Test1_TheA1) {
        if ((&r_a_Test1_TheA1 != this) && 
            (m_p_slice != r_a_Test1_TheA1.m_p_slice)) {
            if (m_b_release)
               Test1_TheA1_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = Test1_TheA1_dup((const Test1_TheA1_slice *) r_a_Test1_TheA1.m_p_slice);
            m_set = r_a_Test1_TheA1.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const Test1_TheA1& () const {	// in parameters
            return *((const Test1_TheA1*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const Test1_TheA1_slice* in() const { 
            return *((const Test1_TheA1*)m_p_slice);
     }

    Test1_TheA1_slice* out() const { 
            return *((Test1_TheA1*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator Test1_TheA1& () const  {  // inout and fixed out parameters

        return *((Test1_TheA1*)m_p_slice);
    }
#endif

    

    // accessors on the m_b_release member
    void iluSetRelease(ILUCPP_BOOL b_release_on_destruct) const {
        // cast around constness
        ILUCPP_BOOL* p_release = CONST_CAST(ILUCPP_BOOL*, &m_b_release);
        *p_release = b_release_on_destruct;
     }

    ILUCPP_BOOL iluGetRelease() const { return m_b_release; }

    ILUCPP_BOOL iluIsNull() const { return (!m_set); }

    /* Note: the [] operators here have caused operator overloading problems 
     A user workaround is to do something like
     xarray& my_array = my_array_var;
     long temp = my_array_var[i][j]
    */

     // element operator - returns the index'th slice
      Test1_TheA1_slice& operator[](CORBA_ULong index) {
                 return *(m_p_slice + index);
       }

     const Test1_TheA1_slice& operator[](CORBA_ULong index) const {
                return ((*this).in())[index];
      }

 protected:
    Test1_TheA1_slice* m_p_slice;

    // whether or not a delete should be done when the var destructs
    ILUCPP_BOOL m_b_release;

    // for use of corresponding optional as member of structured type
    ILUCPP_BOOL    m_set; 
		
 private:
    Test1_TheA1_var &operator= (const ilu_var&);
    Test1_TheA1_var (const ilu_var&);
 };


  // Test1_TheA1_forany class to support use of arrays with anys
  class Test1_TheA1_forany : public ilu_var {

   public:

      // default constructor
      Test1_TheA1_forany() : m_p_slice(ILUCPP_NULL), m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) { m_set = ILUCPP_FALSE;}

     // construct from slice
    Test1_TheA1_forany(Test1_TheA1_slice* p_a_Test1_TheA1_slice, CORBA_Boolean b_nocopy = ILUCPP_FALSE) 
        :  m_p_slice(p_a_Test1_TheA1_slice), m_b_release(ILUCPP_TRUE), m_b_nocopy(b_nocopy) { m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE; }

    // copy constructor
    Test1_TheA1_forany(const Test1_TheA1_forany& r_a_Test1_TheA1) : m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) {
    m_p_slice = Test1_TheA1_dup((const Test1_TheA1_slice *) r_a_Test1_TheA1.m_p_slice);
     m_set = r_a_Test1_TheA1.m_set;
    }

   // destructor
   ~Test1_TheA1_forany() {
       if (m_b_release) 
            Test1_TheA1_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   Test1_TheA1_forany& operator=(Test1_TheA1_slice* p_a_Test1_TheA1_slice) {
       if (m_p_slice != p_a_Test1_TheA1_slice)
          if (m_b_release)
             Test1_TheA1_free (m_p_slice);
           m_p_slice = p_a_Test1_TheA1_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   Test1_TheA1_forany& operator=(const Test1_TheA1_forany& r_a_Test1_TheA1) {
        if ((&r_a_Test1_TheA1 != this) && 
            (m_p_slice != r_a_Test1_TheA1.m_p_slice)) {
            if (m_b_release)
               Test1_TheA1_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = Test1_TheA1_dup((const Test1_TheA1_slice *) r_a_Test1_TheA1.m_p_slice);
            m_set = r_a_Test1_TheA1.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const Test1_TheA1& () const {	// in parameters
            return *((const Test1_TheA1*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const Test1_TheA1_slice* in() const { 
            return *((const Test1_TheA1*)m_p_slice);
     }

    Test1_TheA1_slice* out() const { 
            return *((Test1_TheA1*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator Test1_TheA1& () const  {  // inout and fixed out parameters

        return *((Test1_TheA1*)m_p_slice);
    }
#endif

    

    // accessors on the m_b_release member
    void iluSetRelease(ILUCPP_BOOL b_release_on_destruct) const {
        // cast around constness
        ILUCPP_BOOL* p_release = CONST_CAST(ILUCPP_BOOL*, &m_b_release);
        *p_release = b_release_on_destruct;
     }

    ILUCPP_BOOL iluGetRelease() const { return m_b_release; }

    ILUCPP_BOOL iluIsNull() const { return (!m_set); }


     // accessors on the m_b_nocopy member
     void iluSetNoCopy(ILUCPP_BOOL b_nocopy) const {
          // cast around constness
           ILUCPP_BOOL* p_nocopy = CONST_CAST(ILUCPP_BOOL*, &m_b_nocopy);
           *p_nocopy = b_nocopy;
     }

    // used by ilu when we transfer ownership of the content to the any 
    CORBA_Boolean iluShouldCopy() const {
         return (m_b_nocopy ? ILUCPP_FALSE : ILUCPP_TRUE);}
    Test1_TheA1_slice* iluGetSlice() const {return m_p_slice;}		

 protected:
      Test1_TheA1_slice* m_p_slice;

     // whether or not a delete should be done when the var destructs
      ILUCPP_BOOL m_b_release;

     // for use of corresponding optional as member of structured type
     ILUCPP_BOOL    m_set; 
		
 private:
    Test1_TheA1_forany &operator= (const ilu_var&);
    Test1_TheA1_forany (const ilu_var&);

    CORBA_Boolean m_b_nocopy;
 };
   

   // declare the typecode instance for Test1_TheA1
   NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_TheA1;

   // insertion, extraction, and sizing functions for Test1_Test1_TheA1
   // Note we cant use overloaded operators since arrays map to arrays, and
   // simple typedefs do not distinguish among overloaded functions
	
   NS_EXTERN iluBaseCall& Test1_size_const_TheA1 (
        iluBaseCall& r_call, const CORBA_String_var a_Test1_TheA1[] );
   NS_EXTERN  iluBaseCall& Test1_size_TheA1 (
         iluBaseCall& r_call, CORBA_String_var a_Test1_TheA1[]);
   NS_EXTERN iluBaseCall& Test1_output_const_TheA1(
         iluBaseCall& r_call, const CORBA_String_var a_Test1_TheA1[]);
   NS_EXTERN iluBaseCall& Test1_output_TheA1(
         iluBaseCall& r_call, CORBA_String_var a_Test1_TheA1[]);
   NS_EXTERN iluBaseCall& Test1_input_TheA1(
         iluBaseCall& r_call, CORBA_String_var a_Test1_TheA1[]);



 class Test1_U3 {
                
         // insertion, extraction, and sizing operators for Test1_U3
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U3();
        Test1_U3(const Test1_U3& r_U3);                   
        ~Test1_U3();
                   
        // assignment
        Test1_U3& operator= (const Test1_U3& r_U3);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U3& self();
                   
        // accessors and modifiers
        Test1_E _d () const;
        void _d (Test1_E new_d);

        void _CString_arm(iluShortCharacter *an__CString_arm);
        void _CString_arm(const iluShortCharacter *an__CString_arm );
        void _CString_arm(const CORBA_String_var& an__CString_arm );
        const iluShortCharacter *_CString_arm() const;  

       void _U2_arm(const Test1_U2 & an__U2_arm); 
       const Test1_U2& _U2_arm() const;
       Test1_U2& _U2_arm();
        void v3(Test1_O2_ptr an_v3);   
        Test1_O2_ptr v3() const;

        void v4(Test1_RO an_v4);   
        Test1_RO v4() const;
         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 CORBA_String_var* m__CString_arm;    
                 Test1_U2* m__U2_arm;    
                 Test1_O2_var* m_v3;    
                 Test1_R_var* m_v4;    
        };
                
        Test1_E    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U3
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U3;



   ////////////////////////////////////////////////////////////////
   // structure Test1_TheR

   struct Test1_TheR {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         Test1_TheR();    
         // copy constructor
         Test1_TheR(const Test1_TheR&  r_a_TheR);   
         // destructor
         ~Test1_TheR();
         //assignment operator
         Test1_TheR& operator= (const Test1_TheR& r_a_TheR);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          Test1_TheR& self();

         //member vars
           Test1_A1 a;
           Test1_CSS css;
           CORBA_Long i;
     };


     // declare the typecode instance for TheR
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_TheR;



 class Test1_U_scard {
                
         // insertion, extraction, and sizing operators for Test1_U_scard
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U_scard();
        Test1_U_scard(const Test1_U_scard& r_U_scard);                   
        ~Test1_U_scard();
                   
        // assignment
        Test1_U_scard& operator= (const Test1_U_scard& r_U_scard);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U_scard& self();
                   
        // accessors and modifiers
        CORBA_UShort _d () const;
        void _d (CORBA_UShort new_d);

       void _R_arm(const Test1_R & an__R_arm); 
       const Test1_R& _R_arm() const;
       Test1_R& _R_arm();
        void _One_arm(Test1_One_ptr an__One_arm);   
        Test1_One_ptr _One_arm() const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 Test1_R* m__R_arm;    
                 Test1_One_var* m__One_arm;    
        };
                
        CORBA_UShort    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U_scard
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U_scard;



 class Test1_U_card {
                
         // insertion, extraction, and sizing operators for Test1_U_card
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U_card();
        Test1_U_card(const Test1_U_card& r_U_card);                   
        ~Test1_U_card();
                   
        // assignment
        Test1_U_card& operator= (const Test1_U_card& r_U_card);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U_card& self();
                   
        // accessors and modifiers
        CORBA_ULong _d () const;
        void _d (CORBA_ULong new_d);

       void _R_arm(const Test1_R & an__R_arm); 
       const Test1_R& _R_arm() const;
       Test1_R& _R_arm();
        void _O2_arm(Test1_O2_ptr an__O2_arm);   
        Test1_O2_ptr _O2_arm() const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 Test1_R* m__R_arm;    
                 Test1_O2_var* m__O2_arm;    
        };
                
        CORBA_ULong    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U_card
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U_card;



 class Test1_U_int {
                
         // insertion, extraction, and sizing operators for Test1_U_int
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U_int();
        Test1_U_int(const Test1_U_int& r_U_int);                   
        ~Test1_U_int();
                   
        // assignment
        Test1_U_int& operator= (const Test1_U_int& r_U_int);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U_int& self();
                   
        // accessors and modifiers
        CORBA_Long _d () const;
        void _d (CORBA_Long new_d);

       void _R_arm(const Test1_R & an__R_arm); 
       const Test1_R& _R_arm() const;
       Test1_R& _R_arm();
        void _O2_arm(Test1_O2_ptr an__O2_arm);   
        Test1_O2_ptr _O2_arm() const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 Test1_R* m__R_arm;    
                 Test1_O2_var* m__O2_arm;    
        };
                
        CORBA_Long    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U_int
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U_int;



 class Test1_U_byte {
                
         // insertion, extraction, and sizing operators for Test1_U_byte
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U_byte();
        Test1_U_byte(const Test1_U_byte& r_U_byte);                   
        ~Test1_U_byte();
                   
        // assignment
        Test1_U_byte& operator= (const Test1_U_byte& r_U_byte);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U_byte& self();
                   
        // accessors and modifiers
        CORBA_Octet _d () const;
        void _d (CORBA_Octet new_d);

       void _R_arm(const Test1_R & an__R_arm); 
       const Test1_R& _R_arm() const;
       Test1_R& _R_arm();
        void _O2_arm(Test1_O2_ptr an__O2_arm);   
        Test1_O2_ptr _O2_arm() const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 Test1_R* m__R_arm;    
                 Test1_O2_var* m__O2_arm;    
        };
                
        CORBA_Octet    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U_byte
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U_byte;



 class Test1_U1 {
                
         // insertion, extraction, and sizing operators for Test1_U1
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_U1();
        Test1_U1(const Test1_U1& r_U1);                   
        ~Test1_U1();
                   
        // assignment
        Test1_U1& operator= (const Test1_U1& r_U1);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_U1& self();
                   
        // accessors and modifiers
        CORBA_Short _d () const;
        void _d (CORBA_Short new_d);

       void _R_arm(const Test1_R & an__R_arm); 
       const Test1_R& _R_arm() const;
       Test1_R& _R_arm();
        void _A1_arm(Test1_A1);
        Test1_A1_slice *_A1_arm() const;

         void unset();
         union {
                 Test1_R* m__R_arm;    
                 Test1_A1_slice* m__A1_arm;    
        };
                
        CORBA_Short    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for U1
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_U1;



 class Test1_TheU {
                
         // insertion, extraction, and sizing operators for Test1_TheU
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        Test1_TheU();
        Test1_TheU(const Test1_TheU& r_TheU);                   
        ~Test1_TheU();
                   
        // assignment
        Test1_TheU& operator= (const Test1_TheU& r_TheU);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         Test1_TheU& self();
                   
        // accessors and modifiers
        CORBA_Short _d () const;
        void _d (CORBA_Short new_d);

       void _R_arm(const Test1_R & an__R_arm); 
       const Test1_R& _R_arm() const;
       Test1_R& _R_arm();
        void _RO_arm(Test1_RO an__RO_arm);   
        Test1_RO _RO_arm() const;
       void _CSS_arm(const Test1_CSS & an__CSS_arm); 
       const Test1_CSS& _CSS_arm() const;
       Test1_CSS& _CSS_arm();
        void _O1_arm(Test1_O1_ptr an__O1_arm);   
        Test1_O1_ptr _O1_arm() const;

        void _OO_arm(Test1_TheO1_ptr an__OO_arm);   
        Test1_TheO1_ptr _OO_arm() const;

        void _CORBA_Boolean_arm (CORBA_Boolean an__CORBA_Boolean_arm);
        CORBA_Boolean _CORBA_Boolean_arm () const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 Test1_R* m__R_arm;    
                 Test1_R_var* m__RO_arm;    
                 Test1_CSS* m__CSS_arm;    
                 Test1_O1_var* m__O1_arm;    
                 Test1_O1_var* m__OO_arm;    
                 CORBA_Boolean m__CORBA_Boolean_arm;    
        };
                
        CORBA_Short    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for TheU
     NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_TheU;


////////////////////////////////////////////////////////////////////////
// optional RO

  // declare the typecode instance 
  NS_EXTERN const CORBA_TypeCode_ptr Test1_tc_RO;
 
  // used to insert and extract Test1_ROs from Anys
  struct Test1_RO_forany {

      Test1_RO_forany( Test1_R* p_value = NULL) : m_p_value(p_value) {}

      ~Test1_RO_forany() { delete m_p_value; }
 
      // assignment operator
       Test1_RO_forany& operator=
         (const Test1_RO_forany& r_a_RO_forany) {
             if (this != &r_a_RO_forany) {
                   m_p_value = new Test1_R;
                  *m_p_value = *(r_a_RO_forany.m_p_value);
              }
              return *this;
          }   

      Test1_R* m_p_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E1 
 
  class Test1_E1 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E1() { };
      Test1_E1(const Test1_E1& a_E1);
      ~Test1_E1();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E1& operator=(const Test1_E1& a_E1);

      // constructor with member value
      Test1_E1(const Test1_TheU& value);
 
      // Member
      const Test1_TheU& _value() const { return _m_value; }
      Test1_TheU _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E2 
 
  class Test1_E2 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E2() { };
      Test1_E2(const Test1_E2& a_E2);
      ~Test1_E2();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E2& operator=(const Test1_E2& a_E2);

      // constructor with member value
      Test1_E2(const CORBA_Long& value);
 
      // Member
      const CORBA_Long& _value() const { return _m_value; }
      CORBA_Long _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_CantCreate 
 
  class Test1_CantCreate : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_CantCreate() { };
      Test1_CantCreate(const Test1_CantCreate& a_CantCreate);
      ~Test1_CantCreate();

      void _raise() { throw *this; };

      // assignment operator
      Test1_CantCreate& operator=(const Test1_CantCreate& a_CantCreate);
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E3 
 
  class Test1_E3 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E3() { };
      Test1_E3(const Test1_E3& a_E3);
      ~Test1_E3();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E3& operator=(const Test1_E3& a_E3);

      // constructor with member value
      Test1_E3(const Test1_RO value);
 
      // Member
      const Test1_R_var& _value() const { return _m_value; }
      Test1_R_var _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E4 
 
  class Test1_E4 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E4() { };
      Test1_E4(const Test1_E4& a_E4);
      ~Test1_E4();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E4& operator=(const Test1_E4& a_E4);

      // constructor with member value
      Test1_E4(const Test1_TheO1_ptr value);
 
      // Member
      const Test1_TheO1_var& _value() const { return _m_value; }
      Test1_TheO1_var _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E5 
 
  class Test1_E5 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E5() { };
      Test1_E5(const Test1_E5& a_E5);
      ~Test1_E5();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E5& operator=(const Test1_E5& a_E5);

      // constructor with member value
      Test1_E5(const Test1_A0 value);
 
      // Member
      const Test1_A0& _value() const { return _m_value; }
      Test1_A0 _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E6 
 
  class Test1_E6 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E6() { };
      Test1_E6(const Test1_E6& a_E6);
      ~Test1_E6();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E6& operator=(const Test1_E6& a_E6);

      // constructor with member value
      Test1_E6(const Test1_TheRS& value);
 
      // Member
      const Test1_TheRS& _value() const { return _m_value; }
      Test1_TheRS _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E7 
 
  class Test1_E7 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E7() { };
      Test1_E7(const Test1_E7& a_E7);
      ~Test1_E7();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E7& operator=(const Test1_E7& a_E7);

      // constructor with member value
      Test1_E7(const iluShortCharacter* value);
 
      // Member
      const CORBA_String_var& _value() const { return _m_value; }
      CORBA_String_var _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E8 
 
  class Test1_E8 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E8() { };
      Test1_E8(const Test1_E8& a_E8);
      ~Test1_E8();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E8& operator=(const Test1_E8& a_E8);

      // constructor with member value
      Test1_E8(const Test1_TheA1 value);
 
      // Member
      const Test1_TheA1& _value() const { return _m_value; }
      Test1_TheA1 _m_value;
  };

///////////////////////////////////////////////////////////////////
// Exception Test1_E9 
 
  class Test1_E9 : public CORBA_UserException{
    public:
      // constructors and destructors
      Test1_E9() { };
      Test1_E9(const Test1_E9& a_E9);
      ~Test1_E9();

      void _raise() { throw *this; };

      // assignment operator
      Test1_E9& operator=(const Test1_E9& a_E9);

      // constructor with member value
      Test1_E9(const Test1_TheR& value);
 
      // Member
      const Test1_TheR& _value() const { return _m_value; }
      Test1_TheR _m_value;

      //constructor with member values
      Test1_E9(
            const Test1_A1 _a_a, 
            const Test1_CSS& _a_css, 
            const CORBA_Long& _a_i 
       ) ;
      
      const Test1_A1& a() const
                   { return _m_value.a; };
      
      const Test1_CSS& css() const
                   { return _m_value.css; };
      
      const CORBA_Long& i() const
                   { return _m_value.i; };
  };

//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // Test1_initializer class is used to create a single instance that puts the
 // Test1_iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class Test1_initializer {
    public:
      Test1_initializer ();
      void * ensure_instantiation ();
      static Test1_initializer sm_the_Test1_initializer;
  };
// End the scope for Test1

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_Test1_CLIENT_ONLY() { \
     Test1_initializer::sm_the_Test1_initializer.ensure_instantiation();\
     Test1_surrogate_O4_initializer::sm_the_surrogate_Test1_O4_initializer.ensure_instantiation(); \
     Test1_surrogate_P_initializer::sm_the_surrogate_Test1_P_initializer.ensure_instantiation(); \
     Test1_surrogate_O3_initializer::sm_the_surrogate_Test1_O3_initializer.ensure_instantiation(); \
     Test1_surrogate_TheO1_initializer::sm_the_surrogate_Test1_TheO1_initializer.ensure_instantiation(); \
     Test1_surrogate_O2_initializer::sm_the_surrogate_Test1_O2_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_Test1_SERVER_ONLY() { \
     Test1_initializer::sm_the_Test1_initializer.ensure_instantiation();\
     Test1_true_O4_initializer::sm_the_true_Test1_O4_initializer.ensure_instantiation(); \
     Test1_true_P_initializer::sm_the_true_Test1_P_initializer.ensure_instantiation(); \
     Test1_true_O3_initializer::sm_the_true_Test1_O3_initializer.ensure_instantiation(); \
     Test1_true_TheO1_initializer::sm_the_true_Test1_TheO1_initializer.ensure_instantiation(); \
     Test1_true_O2_initializer::sm_the_true_Test1_O2_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_Test1_CLIENT_SERVER() { \
     Test1_initializer::sm_the_Test1_initializer.ensure_instantiation();\
     Test1_surrogate_O4_initializer::sm_the_surrogate_Test1_O4_initializer.ensure_instantiation(); \
     Test1_true_O4_initializer::sm_the_true_Test1_O4_initializer.ensure_instantiation(); \
     Test1_surrogate_P_initializer::sm_the_surrogate_Test1_P_initializer.ensure_instantiation(); \
     Test1_true_P_initializer::sm_the_true_Test1_P_initializer.ensure_instantiation(); \
     Test1_surrogate_O3_initializer::sm_the_surrogate_Test1_O3_initializer.ensure_instantiation(); \
     Test1_true_O3_initializer::sm_the_true_Test1_O3_initializer.ensure_instantiation(); \
     Test1_surrogate_TheO1_initializer::sm_the_surrogate_Test1_TheO1_initializer.ensure_instantiation(); \
     Test1_true_TheO1_initializer::sm_the_true_Test1_TheO1_initializer.ensure_instantiation(); \
     Test1_surrogate_O2_initializer::sm_the_surrogate_Test1_O2_initializer.ensure_instantiation(); \
     Test1_true_O2_initializer::sm_the_true_Test1_O2_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for Test1_O4_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_O4_var& r_Test1_O4_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_O4_var& r_Test1_O4_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_O4_var& r_Test1_O4_var);

  // insertion, extraction, and sizing operators for Test1_P_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_P_var& r_Test1_P_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_P_var& r_Test1_P_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_P_var& r_Test1_P_var);

  // insertion, extraction, and sizing operators for Test1_O3_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_O3_var& r_Test1_O3_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_O3_var& r_Test1_O3_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_O3_var& r_Test1_O3_var);

  // insertion, extraction, and sizing operators for Test1_TheO1_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_TheO1_var& r_Test1_TheO1_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_TheO1_var& r_Test1_TheO1_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_TheO1_var& r_Test1_TheO1_var);

  // insertion, extraction, and sizing operators for Test1_U_scard
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U_scard& r_Test1_U_scard);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U_scard& r_Test1_U_scard);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U_scard& r_Test1_U_scard);

  // insertion, extraction, and sizing operators for Test1_U_card
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U_card& r_Test1_U_card);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U_card& r_Test1_U_card);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U_card& r_Test1_U_card);

  // insertion, extraction, and sizing operators for Test1_U_int
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U_int& r_Test1_U_int);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U_int& r_Test1_U_int);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U_int& r_Test1_U_int);

  // insertion, extraction, and sizing operators for Test1_U_byte
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U_byte& r_Test1_U_byte);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U_byte& r_Test1_U_byte);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U_byte& r_Test1_U_byte);

  // insertion, extraction, and sizing operators for Test1_U4
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U4& r_Test1_U4);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U4& r_Test1_U4);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U4& r_Test1_U4);

  // insertion, extraction, and sizing operators for Test1_U3
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U3& r_Test1_U3);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U3& r_Test1_U3);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U3& r_Test1_U3);

  // insertion, extraction, and sizing operators for Test1_U2
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U2& r_Test1_U2);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U2& r_Test1_U2);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U2& r_Test1_U2);

  // insertion, extraction, and sizing operators for Test1_U1
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_U1& r_Test1_U1);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_U1& r_Test1_U1);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_U1& r_Test1_U1);

  // insertion, extraction, and sizing operators for Test1_TheU
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_TheU& r_Test1_TheU);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_TheU& r_Test1_TheU);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_TheU& r_Test1_TheU);

  // insertion, extraction, and sizing operators for Test1_OO2
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_OO2& r_Test1_OO2);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_OO2& r_Test1_OO2);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_OO2& r_Test1_OO2);

  // insertion, extraction, and sizing operators for Test1_O2_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_O2_var& r_Test1_O2_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_O2_var& r_Test1_O2_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_O2_var& r_Test1_O2_var);

  // insertion, extraction, and sizing operators for Test1_TheRS
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_TheRS& r_Test1_TheRS);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_TheRS& r_Test1_TheRS);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_TheRS& r_Test1_TheRS);

  // insertion, extraction, and sizing operators for Test1_TheR
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_TheR& r_Test1_TheR);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_TheR& r_Test1_TheR);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_TheR& r_Test1_TheR);

  // insertion, extraction, and sizing operators for Test1_BS
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_BS& r_Test1_BS);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_BS& r_Test1_BS);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_BS& r_Test1_BS);

  // insertion, extraction, and sizing operators for Test1_CSS
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_CSS& r_Test1_CSS);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_CSS& r_Test1_CSS);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_CSS& r_Test1_CSS);

  // insertion, extraction, and sizing operators for Test1_IS
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const Test1_IS& r_Test1_IS);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const Test1_IS& r_Test1_IS);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               Test1_IS& r_Test1_IS);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for Test1_O4
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(Test1_O4, ilu_object_tk,
        "ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ");

  // declare the Any insert and extract operators for Test1_O4
  void operator<<=(CORBA_Any& r_any, Test1_O4_ptr p_Test1_O4);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_O4_ptr& rp_Test1_O4);


  // define the typecode class for Test1_P
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(Test1_P, ilu_object_tk,
        "ilut:dY9O+Pbe716S3dZTXTUzbvfKs87");

  // declare the Any insert and extract operators for Test1_P
  void operator<<=(CORBA_Any& r_any, Test1_P_ptr p_Test1_P);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_P_ptr& rp_Test1_P);


  // define the typecode class for Test1_O3
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(Test1_O3, ilu_object_tk,
        "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU");

  // declare the Any insert and extract operators for Test1_O3
  void operator<<=(CORBA_Any& r_any, Test1_O3_ptr p_Test1_O3);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_O3_ptr& rp_Test1_O3);


  // define the typecode class for Test1_TheO1
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(Test1_TheO1, ilu_object_tk,
        "ilut:fmBFu4mQpwjov+CekDxhjwxkgty");

  // declare the Any insert and extract operators for Test1_TheO1
  void operator<<=(CORBA_Any& r_any, Test1_TheO1_ptr p_Test1_TheO1);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_TheO1_ptr& rp_Test1_TheO1);


  // define the typecode class for Test1_U_scard
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U_scard, ilu_union_tk,
        "ilut:jAPE1zV6LdNhqmjYERCpES3yBpF");

  // declare the Any insert and extract operators for Test1_U_scard
  void operator<<=(CORBA_Any& r_any, const Test1_U_scard& r_Test1_U_scard);
  void operator<<=(CORBA_Any& r_any, Test1_U_scard* p_Test1_U_scard);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U_scard*& rp_Test1_U_scard);


  // define the typecode class for Test1_U_card
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U_card, ilu_union_tk,
        "ilut:nY7eVP682HUe0ogce3ooQPrruH2");

  // declare the Any insert and extract operators for Test1_U_card
  void operator<<=(CORBA_Any& r_any, const Test1_U_card& r_Test1_U_card);
  void operator<<=(CORBA_Any& r_any, Test1_U_card* p_Test1_U_card);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U_card*& rp_Test1_U_card);


  // define the typecode class for Test1_U_int
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U_int, ilu_union_tk,
        "ilut:b8uuARf6GuBoeD-p8pOwYMjTZ69");

  // declare the Any insert and extract operators for Test1_U_int
  void operator<<=(CORBA_Any& r_any, const Test1_U_int& r_Test1_U_int);
  void operator<<=(CORBA_Any& r_any, Test1_U_int* p_Test1_U_int);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U_int*& rp_Test1_U_int);


  // define the typecode class for Test1_U_byte
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U_byte, ilu_union_tk,
        "ilut:eEo4ZOFawZcut8dv19+C65eQlWg");

  // declare the Any insert and extract operators for Test1_U_byte
  void operator<<=(CORBA_Any& r_any, const Test1_U_byte& r_Test1_U_byte);
  void operator<<=(CORBA_Any& r_any, Test1_U_byte* p_Test1_U_byte);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U_byte*& rp_Test1_U_byte);


  // define the typecode class for Test1_U4
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U4, ilu_union_tk,
        "ilut:iqhShhLIYYhlWJMKqapun2JReYg");

  // declare the Any insert and extract operators for Test1_U4
  void operator<<=(CORBA_Any& r_any, const Test1_U4& r_Test1_U4);
  void operator<<=(CORBA_Any& r_any, Test1_U4* p_Test1_U4);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U4*& rp_Test1_U4);


  // define the typecode class for Test1_U3
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U3, ilu_union_tk,
        "ilut:b2Q65O-JOci2N0htlZ+qn5HntNj");

  // declare the Any insert and extract operators for Test1_U3
  void operator<<=(CORBA_Any& r_any, const Test1_U3& r_Test1_U3);
  void operator<<=(CORBA_Any& r_any, Test1_U3* p_Test1_U3);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U3*& rp_Test1_U3);


  // define the typecode class for Test1_U2
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U2, ilu_union_tk,
        "ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9");

  // declare the Any insert and extract operators for Test1_U2
  void operator<<=(CORBA_Any& r_any, const Test1_U2& r_Test1_U2);
  void operator<<=(CORBA_Any& r_any, Test1_U2* p_Test1_U2);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U2*& rp_Test1_U2);


  // define the typecode class for Test1_TheE
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_TheE, ilu_enumeration_tk,
        "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh");

  // declare the Any insert and extract operators for Test1_TheE
  void operator<<=(CORBA_Any& r_any,  const Test1_TheE& r_Test1_TheE);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_TheE& r_Test1_TheE);


  // define the typecode class for Test1_U1
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_U1, ilu_union_tk,
        "ilut:jzGuxkzcjrh34B-89hMcq2ovHB6");

  // declare the Any insert and extract operators for Test1_U1
  void operator<<=(CORBA_Any& r_any, const Test1_U1& r_Test1_U1);
  void operator<<=(CORBA_Any& r_any, Test1_U1* p_Test1_U1);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_U1*& rp_Test1_U1);


  // define the typecode class for Test1_TheU
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_TheU, ilu_union_tk,
        "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW");

  // declare the Any insert and extract operators for Test1_TheU
  void operator<<=(CORBA_Any& r_any, const Test1_TheU& r_Test1_TheU);
  void operator<<=(CORBA_Any& r_any, Test1_TheU* p_Test1_TheU);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_TheU*& rp_Test1_TheU);


  // define the typecode class for Test1_OO2
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_OO2, ilu_union_tk,
        "ilut:l-kEjRgqgSEZbJTDUfMwmrp5361");

  // declare the Any insert and extract operators for Test1_OO2
  void operator<<=(CORBA_Any& r_any, const Test1_OO2& r_Test1_OO2);
  void operator<<=(CORBA_Any& r_any, Test1_OO2* p_Test1_OO2);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_OO2*& rp_Test1_OO2);


  // define the typecode class for Test1_O2
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(Test1_O2, ilu_object_tk,
        "ilut:jXB9BUoPU7650cspZmJCl3y4zzu");

  // declare the Any insert and extract operators for Test1_O2
  void operator<<=(CORBA_Any& r_any, Test1_O2_ptr p_Test1_O2);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, Test1_O2_ptr& rp_Test1_O2);


  // define the typecode class for Test1_TheOO
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_TheOO, ilu_optional_tk,
        "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA");

  // declare the Any insert and extract operators for Test1_TheOO
  void operator<<=(CORBA_Any& r_any, const Test1_TheOO_forany& r_Test1_TheOO_forany);
  void operator<<=(CORBA_Any& r_any, Test1_TheOO_forany* p_Test1_TheOO_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_TheOO_forany*& rp_Test1_TheOO);


  // define the typecode class for Test1_RO
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_RO, ilu_optional_tk,
        "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2");

  // declare the Any insert and extract operators for Test1_RO
  void operator<<=(CORBA_Any& r_any, const Test1_RO_forany& r_Test1_RO_forany);
  void operator<<=(CORBA_Any& r_any, Test1_RO_forany* p_Test1_RO_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_RO_forany*& rp_Test1_RO);


  // define the typecode class for Test1_TheRS
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_TheRS, ilu_sequence_tk,
        "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac");

  // declare the Any insert and extract operators for Test1_TheRS
  void operator<<=(CORBA_Any& r_any, const Test1_TheRS& r_Test1_TheRS);
  void operator<<=(CORBA_Any& r_any, Test1_TheRS* p_Test1_TheRS);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_TheRS*& rp_Test1_TheRS);


  // define the typecode class for Test1_TheR
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_TheR, ilu_record_tk,
        "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7");

  // declare the Any insert and extract operators for Test1_TheR
  void operator<<=(CORBA_Any& r_any, const Test1_TheR& r_Test1_TheR);
  void operator<<=(CORBA_Any& r_any, Test1_TheR* p_Test1_TheR);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_TheR*& rp_Test1_TheR);


  // define the typecode class for Test1_BS
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_BS, ilu_sequence_tk,
        "ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3");

  // declare the Any insert and extract operators for Test1_BS
  void operator<<=(CORBA_Any& r_any, const Test1_BS& r_Test1_BS);
  void operator<<=(CORBA_Any& r_any, Test1_BS* p_Test1_BS);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_BS*& rp_Test1_BS);


  // define the typecode class for Test1_A2
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_A2, ilu_array_tk,
        "ilut:kM2HH51HMYTWu-khgczpbgNaama");

  // declare the Any insert and extract operators for Test1_A2
  void operator<<=(CORBA_Any& r_any, const Test1_A2_forany& r_Test1_A2_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_A2_forany& r_Test1_A2_forany);


  // define the typecode class for Test1_TheA1
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_TheA1, ilu_array_tk,
        "ilut:h3Dnvis94UwnmFURfYsCp700jVy");

  // declare the Any insert and extract operators for Test1_TheA1
  void operator<<=(CORBA_Any& r_any, const Test1_TheA1_forany& r_Test1_TheA1_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_TheA1_forany& r_Test1_TheA1_forany);


  // define the typecode class for Test1_A0
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_A0, ilu_array_tk,
        "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r");

  // declare the Any insert and extract operators for Test1_A0
  void operator<<=(CORBA_Any& r_any, const Test1_A0_forany& r_Test1_A0_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_A0_forany& r_Test1_A0_forany);


  // define the typecode class for Test1_CSS
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_CSS, ilu_sequence_tk,
        "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy");

  // declare the Any insert and extract operators for Test1_CSS
  void operator<<=(CORBA_Any& r_any, const Test1_CSS& r_Test1_CSS);
  void operator<<=(CORBA_Any& r_any, Test1_CSS* p_Test1_CSS);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_CSS*& rp_Test1_CSS);


  // define the typecode class for Test1_IS
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(Test1_IS, ilu_sequence_tk,
        "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO");

  // declare the Any insert and extract operators for Test1_IS
  void operator<<=(CORBA_Any& r_any, const Test1_IS& r_Test1_IS);
  void operator<<=(CORBA_Any& r_any, Test1_IS* p_Test1_IS);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                Test1_IS*& rp_Test1_IS);

#endif
