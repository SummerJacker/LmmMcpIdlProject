
// This file was automatically generated with KISORB (version 2.0beta1) tools
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院,All Rights Reserved.
// KISORB information:  Dr. Wang at xcwang89@aliyun.com 

#ifndef __foo_H_
  #define __foo_H_
  
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
#ifndef foo_
  #define foo_(name) NAME_INSIDE_SCOPE(foo,name)
#endif
#ifndef foo
  #define foo(name) NAME_OUTSIDE_SCOPE(foo,name)
#endif

  #ifndef NS_EXTERN
      #define NS_EXTERN extern 
  #endif

// start the scope for foo 
 
    class foo_zapexception;
 
    #define g_foo_zapexception_index     0
     // Declarations for initialization
     NS_EXTERN void foo_iluInitialize();
     NS_EXTERN int foo_g_i_initialized;
     NS_EXTERN iluInitializationFunctionNode* 
               foo_p_initialization_function_list;

     class foo_bar;
     typedef foo_bar* foo_bar_ptr;
     typedef iluTemplatableObject_var<foo_bar> foo_bar_var;

     typedef CORBA_Long*            foo_optionalinteger; 
     typedef const CORBA_Long*      foo_const_optionalinteger; 
     struct foo_optionalinteger_forany; 


     typedef foo_bar_ptr         foo_optionalbarobject; 
     typedef const foo_bar_ptr  foo_const_optionalbarobject; 
     typedef foo_bar_var        foo_optionalbarobject_var; 

     struct foo_optionalbarobject_forany; 

      class foo_boundedbarseq;
      typedef iluTemplatableSequence_var<foo_boundedbarseq, foo_bar_var> foo_boundedbarseq_var; 

      class foo_unboundedlongseq;
      typedef iluTemplatableSequence_var<foo_unboundedlongseq, CORBA_Long> foo_unboundedlongseq_var; 

     class foo_bararray_var;
     class foo_bararray_forany;
     typedef foo_bar_var foo_bararray[2][3];
     typedef foo_bar_var foo_bararray_slice[3];
     NS_EXTERN foo_bararray_slice* foo_bararray_alloc();
     NS_EXTERN foo_bararray_slice*  foo_bararray_dup
             (const foo_bararray_slice* p_bararray_slice);
     NS_EXTERN void foo_bararray_free
             (foo_bararray_slice* p_bararray_slice);
     NS_EXTERN void foo_bararray_copy(
             foo_bararray_slice *p_to_bararray_slice, 
             const foo_bararray_slice *p_from_bararray_slice);

     NS_EXTERN void foo_bararray_iluSurrogateSideCleanup
             (foo_bararray_slice* p_bararray_slice);
     NS_EXTERN void foo_const_bararray_iluSurrogateSideCleanup
             (const foo_bararray_slice* p_bararray_slice);

     class foo_integerarray_var;
     class foo_integerarray_forany;
     typedef CORBA_Long foo_integerarray[5][10];
     typedef CORBA_Long foo_integerarray_slice[10];
     NS_EXTERN foo_integerarray_slice* foo_integerarray_alloc();
     NS_EXTERN foo_integerarray_slice*  foo_integerarray_dup
             (const foo_integerarray_slice* p_integerarray_slice);
     NS_EXTERN void foo_integerarray_free
             (foo_integerarray_slice* p_integerarray_slice);
     NS_EXTERN void foo_integerarray_copy(
             foo_integerarray_slice *p_to_integerarray_slice, 
             const foo_integerarray_slice *p_from_integerarray_slice);

     typedef iluCharacter* foo_UnicodeString;
     typedef const iluCharacter* foo_const_UnicodeString;

     typedef iluShortCharacter* foo_LatinString;
     typedef const iluShortCharacter* foo_const_LatinString;

     class foo_variableuniontype; 
     typedef iluTemplatableT_var<foo_variableuniontype> foo_variableuniontype_var;

     struct foo_variablerecordtype;
     typedef iluTemplatableT_var<foo_variablerecordtype> foo_variablerecordtype_var;

     enum foo_enumtype { foo_red = 0, foo_orange = 1, foo_yellow = 2, foo_green = 3, foo_blue = 4, foo_indigo = 5, foo_violet = 6 };

     // declare the typecode instance for enumtype
     NS_EXTERN const CORBA_TypeCode_ptr foo_tc_enumtype;

     struct foo_fixedrecordtype;
     typedef iluTemplatableT_var<foo_fixedrecordtype> foo_fixedrecordtype_var;


////////////////////////////////////////////////////////////////////////
// optional optionalinteger

  // declare the typecode instance 
  NS_EXTERN const CORBA_TypeCode_ptr foo_tc_optionalinteger;
 
  // used to insert and extract foo_optionalintegers from Anys
  struct foo_optionalinteger_forany {

      foo_optionalinteger_forany( CORBA_Long* p_value = NULL) : m_p_value(p_value) {}

      ~foo_optionalinteger_forany() { delete m_p_value; }
 
      // assignment operator
       foo_optionalinteger_forany& operator=
         (const foo_optionalinteger_forany& r_a_optionalinteger_forany) {
             if (this != &r_a_optionalinteger_forany) {
                   m_p_value = new CORBA_Long;
                  *m_p_value = *(r_a_optionalinteger_forany.m_p_value);
              }
              return *this;
          }   

      CORBA_Long* m_p_value;
  };


 class foo_variableuniontype {
                
         // insertion, extraction, and sizing operators for foo_variableuniontype
         // Note: private storage and friends not currently used for
         // unions, as use with namespaces create problems whose solutions not
         //  uniformly accepted among compilers
                   
               
    public:
                
        // constructors & destructor
        foo_variableuniontype();
        foo_variableuniontype(const foo_variableuniontype& r_variableuniontype);                   
        ~foo_variableuniontype();
                   
        // assignment
        foo_variableuniontype& operator= (const foo_variableuniontype& r_variableuniontype);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
         foo_variableuniontype& self();
                   
        // accessors and modifiers
        CORBA_UShort _d () const;
        void _d (CORBA_UShort new_d);

        void bararm(foo_bar_ptr an_bararm);   
        foo_bar_ptr bararm() const;

        void integerarm (CORBA_Long an_integerarm);
        CORBA_Long integerarm () const;

         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;
         void unset();
         union {
                 foo_bar_var* m_bararm;    
                 CORBA_Long m_integerarm;    
        };
                
        CORBA_UShort    m_discriminator;
        CORBA_Boolean     m_b_beenset;
                   
 };


     // declare the typecode instance for variableuniontype
     NS_EXTERN const CORBA_TypeCode_ptr foo_tc_variableuniontype;



   ////////////////////////////////////////////////////////////////
   // sequence foo_boundedbarseq

   class foo_boundedbarseq {

    public:

       // constructors & destructor
        foo_boundedbarseq ();
        foo_boundedbarseq (CORBA_ULong length,
              foo_bar_ptr* data, CORBA_Boolean release = ILUCPP_FALSE);
        foo_boundedbarseq (const foo_boundedbarseq& r_boundedbarseq);
        ~foo_boundedbarseq();

        // assignment
        foo_boundedbarseq& operator= (const foo_boundedbarseq& r_boundedbarseq);

        // accessors
        CORBA_ULong maximum() const;
        CORBA_ULong length() const;
        void length (CORBA_ULong len);
		CORBA_Boolean release() const;
        foo_bar_ptr* get_buffer (CORBA_Boolean orphan = ilu_FALSE);
        foo_bar_ptr const* get_buffer () const;

        // [] operators
        foo_bar_var& operator [] (CORBA_ULong index);
        const foo_bar_var& operator [] (CORBA_ULong index) const;

        // memory management
         static foo_bar_ptr* allocbuf(CORBA_ULong num_elements);
         static void freebuf(foo_bar_ptr* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          foo_boundedbarseq& self();
         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;

    private:

          CORBA_ULong m_maximum;
          CORBA_ULong m_length;
          CORBA_Boolean m_release;
          foo_bar_ptr* m_buffer;
          foo_bar_var* m_varbuffer;

  };

  // declare the typecode instance for boundedbarseq
  NS_EXTERN const CORBA_TypeCode_ptr foo_tc_boundedbarseq;



   ////////////////////////////////////////////////////////////////
   // sequence foo_unboundedlongseq

   class foo_unboundedlongseq {

    public:

       // constructors & destructor
        foo_unboundedlongseq ();
        foo_unboundedlongseq (CORBA_ULong max);
        foo_unboundedlongseq (CORBA_ULong max, CORBA_ULong length,
              CORBA_Long* data, CORBA_Boolean release = ILUCPP_FALSE);
        foo_unboundedlongseq (const foo_unboundedlongseq& r_unboundedlongseq);
        ~foo_unboundedlongseq();

        // assignment
        foo_unboundedlongseq& operator= (const foo_unboundedlongseq& r_unboundedlongseq);

        // accessors
        CORBA_ULong maximum() const;
        CORBA_ULong length() const;
        void length (CORBA_ULong len);
		CORBA_Boolean release() const;
        CORBA_Long* get_buffer (CORBA_Boolean orphan = ilu_FALSE);
        CORBA_Long const* get_buffer () const;

        // [] operators
        CORBA_Long& operator [] (CORBA_ULong index);
        const CORBA_Long& operator [] (CORBA_ULong index) const;

        // memory management
         static CORBA_Long* allocbuf(CORBA_ULong num_elements);
         static void freebuf(CORBA_Long* p_buf);

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          foo_unboundedlongseq& self();

    private:

          CORBA_ULong m_maximum;
          CORBA_ULong m_length;
          CORBA_Boolean m_release;
          CORBA_Long* m_buffer;

  };

  // declare the typecode instance for unboundedlongseq
  NS_EXTERN const CORBA_TypeCode_ptr foo_tc_unboundedlongseq;



   ////////////////////////////////////////////////////////////////
   // array foo_bararray
    
   class foo_bararray_var : public ilu_var {
		
   public:

    // default constructor
    // Added alloc.. inefficient but sunpro error otherwise
    foo_bararray_var() : m_b_release(ILUCPP_TRUE) { 
                m_p_slice = foo_bararray_alloc();
                m_set = ILUCPP_FALSE;
    }

   // construct from slice
   foo_bararray_var(foo_bararray_slice* p_a_foo_bararray_slice) : m_b_release(ILUCPP_TRUE) {
        m_p_slice = p_a_foo_bararray_slice;
      // not completely reliable 
       m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE;
    }

   // copy constructor
   foo_bararray_var(const foo_bararray_var& r_a_foo_bararray) : m_b_release(ILUCPP_TRUE) {
      m_p_slice = foo_bararray_dup((const foo_bararray_slice*) r_a_foo_bararray.m_p_slice);
      m_set = r_a_foo_bararray.m_set;
   }


   // destructor
   ~foo_bararray_var() {
       if (m_b_release) 
            foo_bararray_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   foo_bararray_var& operator=(foo_bararray_slice* p_a_foo_bararray_slice) {
       if (m_p_slice != p_a_foo_bararray_slice)
          if (m_b_release)
             foo_bararray_free (m_p_slice);
           m_p_slice = p_a_foo_bararray_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   foo_bararray_var& operator=(const foo_bararray_var& r_a_foo_bararray) {
        if ((&r_a_foo_bararray != this) && 
            (m_p_slice != r_a_foo_bararray.m_p_slice)) {
            if (m_b_release)
               foo_bararray_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = foo_bararray_dup((const foo_bararray_slice *) r_a_foo_bararray.m_p_slice);
            m_set = r_a_foo_bararray.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const foo_bararray& () const {	// in parameters
            return *((const foo_bararray*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const foo_bararray_slice* in() const { 
            return *((const foo_bararray*)m_p_slice);
     }

    foo_bararray_slice* out() const { 
            return *((foo_bararray*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator foo_bararray& () const  {  // inout and fixed out parameters

        return *((foo_bararray*)m_p_slice);
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
      foo_bararray_slice& operator[](CORBA_ULong index) {
                 return *(m_p_slice + index);
       }

     const foo_bararray_slice& operator[](CORBA_ULong index) const {
                return ((*this).in())[index];
      }

 protected:
    foo_bararray_slice* m_p_slice;

    // whether or not a delete should be done when the var destructs
    ILUCPP_BOOL m_b_release;

    // for use of corresponding optional as member of structured type
    ILUCPP_BOOL    m_set; 
		
 private:
    foo_bararray_var &operator= (const ilu_var&);
    foo_bararray_var (const ilu_var&);
 };


  // foo_bararray_forany class to support use of arrays with anys
  class foo_bararray_forany : public ilu_var {

   public:

      // default constructor
      foo_bararray_forany() : m_p_slice(ILUCPP_NULL), m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) { m_set = ILUCPP_FALSE;}

     // construct from slice
    foo_bararray_forany(foo_bararray_slice* p_a_foo_bararray_slice, CORBA_Boolean b_nocopy = ILUCPP_FALSE) 
        :  m_p_slice(p_a_foo_bararray_slice), m_b_release(ILUCPP_TRUE), m_b_nocopy(b_nocopy) { m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE; }

    // copy constructor
    foo_bararray_forany(const foo_bararray_forany& r_a_foo_bararray) : m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) {
    m_p_slice = foo_bararray_dup((const foo_bararray_slice *) r_a_foo_bararray.m_p_slice);
     m_set = r_a_foo_bararray.m_set;
    }

   // destructor
   ~foo_bararray_forany() {
       if (m_b_release) 
            foo_bararray_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   foo_bararray_forany& operator=(foo_bararray_slice* p_a_foo_bararray_slice) {
       if (m_p_slice != p_a_foo_bararray_slice)
          if (m_b_release)
             foo_bararray_free (m_p_slice);
           m_p_slice = p_a_foo_bararray_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   foo_bararray_forany& operator=(const foo_bararray_forany& r_a_foo_bararray) {
        if ((&r_a_foo_bararray != this) && 
            (m_p_slice != r_a_foo_bararray.m_p_slice)) {
            if (m_b_release)
               foo_bararray_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = foo_bararray_dup((const foo_bararray_slice *) r_a_foo_bararray.m_p_slice);
            m_set = r_a_foo_bararray.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const foo_bararray& () const {	// in parameters
            return *((const foo_bararray*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const foo_bararray_slice* in() const { 
            return *((const foo_bararray*)m_p_slice);
     }

    foo_bararray_slice* out() const { 
            return *((foo_bararray*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator foo_bararray& () const  {  // inout and fixed out parameters

        return *((foo_bararray*)m_p_slice);
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
    foo_bararray_slice* iluGetSlice() const {return m_p_slice;}		

 protected:
      foo_bararray_slice* m_p_slice;

     // whether or not a delete should be done when the var destructs
      ILUCPP_BOOL m_b_release;

     // for use of corresponding optional as member of structured type
     ILUCPP_BOOL    m_set; 
		
 private:
    foo_bararray_forany &operator= (const ilu_var&);
    foo_bararray_forany (const ilu_var&);

    CORBA_Boolean m_b_nocopy;
 };
   

   // declare the typecode instance for foo_bararray
   NS_EXTERN const CORBA_TypeCode_ptr foo_tc_bararray;

   // insertion, extraction, and sizing functions for foo_foo_bararray
   // Note we cant use overloaded operators since arrays map to arrays, and
   // simple typedefs do not distinguish among overloaded functions
	
   NS_EXTERN iluBaseCall& foo_size_const_bararray (
        iluBaseCall& r_call, const foo_bar_var a_foo_bararray[] [3]);
   NS_EXTERN  iluBaseCall& foo_size_bararray (
         iluBaseCall& r_call, foo_bar_var a_foo_bararray[][3]);
   NS_EXTERN iluBaseCall& foo_output_const_bararray(
         iluBaseCall& r_call, const foo_bar_var a_foo_bararray[][3]);
   NS_EXTERN iluBaseCall& foo_output_bararray(
         iluBaseCall& r_call, foo_bar_var a_foo_bararray[][3]);
   NS_EXTERN iluBaseCall& foo_input_bararray(
         iluBaseCall& r_call, foo_bar_var a_foo_bararray[][3]);



   ////////////////////////////////////////////////////////////////
   // array foo_integerarray
    
   class foo_integerarray_var : public ilu_var {
		
   public:

    // default constructor
    // Added alloc.. inefficient but sunpro error otherwise
    foo_integerarray_var() : m_b_release(ILUCPP_TRUE) { 
                m_p_slice = foo_integerarray_alloc();
                m_set = ILUCPP_FALSE;
    }

   // construct from slice
   foo_integerarray_var(foo_integerarray_slice* p_a_foo_integerarray_slice) : m_b_release(ILUCPP_TRUE) {
        m_p_slice = p_a_foo_integerarray_slice;
      // not completely reliable 
       m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE;
    }

   // copy constructor
   foo_integerarray_var(const foo_integerarray_var& r_a_foo_integerarray) : m_b_release(ILUCPP_TRUE) {
      m_p_slice = foo_integerarray_dup((const foo_integerarray_slice*) r_a_foo_integerarray.m_p_slice);
      m_set = r_a_foo_integerarray.m_set;
   }


   // destructor
   ~foo_integerarray_var() {
       if (m_b_release) 
            foo_integerarray_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   foo_integerarray_var& operator=(foo_integerarray_slice* p_a_foo_integerarray_slice) {
       if (m_p_slice != p_a_foo_integerarray_slice)
          if (m_b_release)
             foo_integerarray_free (m_p_slice);
           m_p_slice = p_a_foo_integerarray_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   foo_integerarray_var& operator=(const foo_integerarray_var& r_a_foo_integerarray) {
        if ((&r_a_foo_integerarray != this) && 
            (m_p_slice != r_a_foo_integerarray.m_p_slice)) {
            if (m_b_release)
               foo_integerarray_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = foo_integerarray_dup((const foo_integerarray_slice *) r_a_foo_integerarray.m_p_slice);
            m_set = r_a_foo_integerarray.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const foo_integerarray& () const {	// in parameters
            return *((const foo_integerarray*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const foo_integerarray_slice* in() const { 
            return *((const foo_integerarray*)m_p_slice);
     }

    foo_integerarray_slice* out() const { 
            return *((foo_integerarray*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator foo_integerarray& () const  {  // inout and fixed out parameters

        return *((foo_integerarray*)m_p_slice);
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
      foo_integerarray_slice& operator[](CORBA_ULong index) {
                 return *(m_p_slice + index);
       }

     const foo_integerarray_slice& operator[](CORBA_ULong index) const {
                return ((*this).in())[index];
      }

 protected:
    foo_integerarray_slice* m_p_slice;

    // whether or not a delete should be done when the var destructs
    ILUCPP_BOOL m_b_release;

    // for use of corresponding optional as member of structured type
    ILUCPP_BOOL    m_set; 
		
 private:
    foo_integerarray_var &operator= (const ilu_var&);
    foo_integerarray_var (const ilu_var&);
 };


  // foo_integerarray_forany class to support use of arrays with anys
  class foo_integerarray_forany : public ilu_var {

   public:

      // default constructor
      foo_integerarray_forany() : m_p_slice(ILUCPP_NULL), m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) { m_set = ILUCPP_FALSE;}

     // construct from slice
    foo_integerarray_forany(foo_integerarray_slice* p_a_foo_integerarray_slice, CORBA_Boolean b_nocopy = ILUCPP_FALSE) 
        :  m_p_slice(p_a_foo_integerarray_slice), m_b_release(ILUCPP_TRUE), m_b_nocopy(b_nocopy) { m_set = m_p_slice ? ILUCPP_TRUE : ILUCPP_FALSE; }

    // copy constructor
    foo_integerarray_forany(const foo_integerarray_forany& r_a_foo_integerarray) : m_b_release(ILUCPP_TRUE), m_b_nocopy(ILUCPP_FALSE) {
    m_p_slice = foo_integerarray_dup((const foo_integerarray_slice *) r_a_foo_integerarray.m_p_slice);
     m_set = r_a_foo_integerarray.m_set;
    }

   // destructor
   ~foo_integerarray_forany() {
       if (m_b_release) 
            foo_integerarray_free(m_p_slice);
       m_set = ILUCPP_FALSE;
         
    }

   // assign from slice
   foo_integerarray_forany& operator=(foo_integerarray_slice* p_a_foo_integerarray_slice) {
       if (m_p_slice != p_a_foo_integerarray_slice)
          if (m_b_release)
             foo_integerarray_free (m_p_slice);
           m_p_slice = p_a_foo_integerarray_slice;
           m_set = ILUCPP_TRUE;
           return *this;			
   }	

   // assign from another array_var
   foo_integerarray_forany& operator=(const foo_integerarray_forany& r_a_foo_integerarray) {
        if ((&r_a_foo_integerarray != this) && 
            (m_p_slice != r_a_foo_integerarray.m_p_slice)) {
            if (m_b_release)
               foo_integerarray_free(m_p_slice);
            // const spec for parameter needed for win32 long ints  
            m_p_slice = foo_integerarray_dup((const foo_integerarray_slice *) r_a_foo_integerarray.m_p_slice);
            m_set = r_a_foo_integerarray.m_set;
         }	
         return (*this);
    }

    // conversion operations to allow parameter passing per
    // Corba Spec chap 16, Table 16.2
    operator const foo_integerarray& () const {	// in parameters
            return *((const foo_integerarray*)m_p_slice);
     }

    // additional explicit disambiguation operators for parameters 
    const foo_integerarray_slice* in() const { 
            return *((const foo_integerarray*)m_p_slice);
     }

    foo_integerarray_slice* out() const { 
            return *((foo_integerarray*)m_p_slice);
     }

#ifndef OLDGNUC_WORKAROUND
    operator foo_integerarray& () const  {  // inout and fixed out parameters

        return *((foo_integerarray*)m_p_slice);
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
    foo_integerarray_slice* iluGetSlice() const {return m_p_slice;}		

 protected:
      foo_integerarray_slice* m_p_slice;

     // whether or not a delete should be done when the var destructs
      ILUCPP_BOOL m_b_release;

     // for use of corresponding optional as member of structured type
     ILUCPP_BOOL    m_set; 
		
 private:
    foo_integerarray_forany &operator= (const ilu_var&);
    foo_integerarray_forany (const ilu_var&);

    CORBA_Boolean m_b_nocopy;
 };
   

   // declare the typecode instance for foo_integerarray
   NS_EXTERN const CORBA_TypeCode_ptr foo_tc_integerarray;

   // insertion, extraction, and sizing functions for foo_foo_integerarray
   // Note we cant use overloaded operators since arrays map to arrays, and
   // simple typedefs do not distinguish among overloaded functions
	
   NS_EXTERN iluBaseCall& foo_size_const_integerarray (
        iluBaseCall& r_call, const CORBA_Long a_foo_integerarray[] [10]);
   NS_EXTERN  iluBaseCall& foo_size_integerarray (
         iluBaseCall& r_call, CORBA_Long a_foo_integerarray[][10]);
   NS_EXTERN iluBaseCall& foo_output_const_integerarray(
         iluBaseCall& r_call, const CORBA_Long a_foo_integerarray[][10]);
   NS_EXTERN iluBaseCall& foo_output_integerarray(
         iluBaseCall& r_call, CORBA_Long a_foo_integerarray[][10]);
   NS_EXTERN iluBaseCall& foo_input_integerarray(
         iluBaseCall& r_call, CORBA_Long a_foo_integerarray[][10]);


//////////////////////////////////////////////////////////////////////
// class foo_bar 
//
// For Clients, instances of _surrogate subclasses of this class will function
// as surrogates - that is, their IDL specified member functions will forward
// calls to the true object. Servers will subclass from this class, and supply
// the IDL specified member functions to provide the true object's implementations
   class foo_bar : public virtual iluObject {
      public:
        // Constructs a new foo_bar using pc_instance_handle as the instance
        // identifier, and puts the object under the specified iluServer.
        // If an_iluserver is NULL, the default server will be used.
        foo_bar(char *pc_instance_handle, iluServer& r_an_ilu_server = iluServer::iluGetDefaultServer(),
             CORBA_Boolean b_within_object_table = ILUCPP_FALSE) :
               iluObject(foo_bar::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server, b_within_object_table) {}

        // CORBA object reference operations
        static foo_bar_ptr _duplicate(foo_bar_ptr a_ptr);

        static foo_bar_ptr _narrow(CORBA_Object_ptr an_object_ptr) {
          return (foo_bar_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static foo_bar_ptr _narrow(iluObject* an_object_ptr) {
          return (foo_bar_ptr (an_object_ptr->iluDowncast(m_ILUClassRecord)));
        }

        static foo_bar_ptr _nil();
        foo_bar_ptr _this() { return _duplicate((foo_bar_ptr) this); }

        // IDL specified methods
   
       virtual CORBA_Boolean zap(
          CORBA_Long  inarg,
          CORBA_Octet&  inoutarg,
          CORBA_Double&  outarg
       ) = 0;
   
       virtual foo_bar_ptr passobj(
          foo_bar_ptr  inarg,
          foo_bar_ptr&  inoutarg,
          foo_bar_ptr&  outarg
       ) = 0;
   
       virtual foo_enumtype passenum(
          foo_enumtype  inarg,
          foo_enumtype&  inoutarg,
          foo_enumtype&  outarg
       ) = 0;
   
       virtual iluShortCharacter* passlatinstring(
          foo_const_LatinString    inarg,
          iluShortCharacter*&  inoutarg,
          iluShortCharacter*&  outarg
       ) = 0;
   
       virtual iluCharacter* passunicodestring(
          foo_const_UnicodeString    inarg,
          iluCharacter*&  inoutarg,
          iluCharacter*&  outarg
       ) = 0;
   
       virtual foo_fixedrecordtype passfixedrecord(
          const foo_fixedrecordtype&  inarg,
          foo_fixedrecordtype&  inoutarg,
          foo_fixedrecordtype&  outarg
       ) = 0;
   
       virtual foo_variablerecordtype* passvariablerecord(
          const foo_variablerecordtype&  inarg,
          foo_variablerecordtype&  inoutarg,
          foo_variablerecordtype*&  outarg
       ) = 0;
   
       virtual foo_integerarray_slice* passfixedarray(
          const foo_integerarray  inarg,
          foo_integerarray  inoutarg,
          foo_integerarray  outarg
       ) = 0;
   
       virtual foo_bararray_slice* passvariablearray(
          const foo_bararray  inarg,
          foo_bararray  inoutarg,
          foo_bararray_slice*&  outarg
       ) = 0;
   
       virtual foo_unboundedlongseq* passunboundedsequence(
          const foo_unboundedlongseq&  inarg,
          foo_unboundedlongseq&  inoutarg,
          foo_unboundedlongseq*&  outarg
       ) = 0;
   
       virtual foo_boundedbarseq* passboundedsequence(
          const foo_boundedbarseq&  inarg,
          foo_boundedbarseq&  inoutarg,
          foo_boundedbarseq*&  outarg
       ) = 0;
   
       virtual foo_variableuniontype* passvariableunion(
          const foo_variableuniontype&  inarg,
          foo_variableuniontype&  inoutarg,
          foo_variableuniontype*&  outarg
       ) = 0;
   
       virtual CORBA_Long* passoptionals(
          foo_const_optionalinteger    inarg,
          foo_optionalbarobject&  inoutarg,
          foo_optionalbarobject&  outarg
       ) = 0;
   
       virtual CORBA_Any* passsimpleanys(
          const CORBA_Any&  inarg,
          CORBA_Any&  inoutarg,
          CORBA_Any*&  outarg
       ) = 0;
   
       virtual CORBA_Any* passarrayanys(
          const CORBA_Any&  inarg,
          CORBA_Any&  inoutarg,
          CORBA_Any*&  outarg
       ) = 0;
   
       virtual CORBA_Any* passassortedanys(
          const CORBA_Any&  inarg,
          CORBA_Any&  inoutarg,
          CORBA_Any*&  outarg
       ) = 0;


        // initialize to use of this class of objects - called by (Interface)::initialize
        static void iluInitialize();

        // Simple Object Lookup
        static foo_bar_ptr iluLookup(char *pc_server_id, char *pc_instance_handle);

        // For ILU C++ runtime - stub use only - returns the m_ILUClassRecord member variable
        static ilu_Class iluGetILUClassRecord() {
          return m_ILUClassRecord;
        }

        // for use in narrowing
        virtual void *iluDowncast(iluClass class_to_cast_down_to);

       // used to get around msvc problems calling super's
       // virtual member functions
       static void* iluDowncast_super(foo_bar_ptr p_some_derived,
                 iluClass class_to_cast_down_to) {
            return p_some_derived->foo_bar::iluDowncast(class_to_cast_down_to);
      }

   protected:

        // Holds the kernel class for this kind of object
        static ilu_Class m_ILUClassRecord;

        foo_bar();	// default constructor
        virtual ~foo_bar();	 // destructor

   private:
        foo_bar(const foo_bar&);	// copy constructor
        void operator=(const foo_bar&);	// assignment operator

      };

  // declare the typecode instance for foo_bar
  NS_EXTERN const CORBA_TypeCode_ptr foo_tc_bar;



   ////////////////////////////////////////////////////////////////
   // structure foo_fixedrecordtype

   struct foo_fixedrecordtype {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         foo_fixedrecordtype();    
         // copy constructor
         foo_fixedrecordtype(const foo_fixedrecordtype&  r_a_fixedrecordtype);   
         // destructor
         ~foo_fixedrecordtype();
         //assignment operator
         foo_fixedrecordtype& operator= (const foo_fixedrecordtype& r_a_fixedrecordtype);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          foo_fixedrecordtype& self();

         //member vars
           CORBA_Long fixedrecordinteger;
           foo_enumtype fixedrecordenum;
     };


     // declare the typecode instance for fixedrecordtype
     NS_EXTERN const CORBA_TypeCode_ptr foo_tc_fixedrecordtype;


////////////////////////////////////////////////////////////////////////
// optional optionalbarobject

  // declare the typecode instance 
  NS_EXTERN const CORBA_TypeCode_ptr foo_tc_optionalbarobject;
 
  // used to insert and extract foo_optionalbarobjects from Anys
  struct foo_optionalbarobject_forany {
 
      foo_optionalbarobject_forany( foo_bar_ptr p_value = NULL) : m_p_value(p_value) {}

      ~foo_optionalbarobject_forany() { if (m_p_value) m_p_value->_release(); }
 
       // assignment operator
       foo_optionalbarobject_forany& operator=
         (const foo_optionalbarobject_forany& r_a_optionalbarobject_forany) {
           if (this != &r_a_optionalbarobject_forany) {
               if (r_a_optionalbarobject_forany.m_p_value)
                   m_p_value =    
                       foo_bar::_duplicate(r_a_optionalbarobject_forany.m_p_value);
               else m_p_value = NULL;
            }  
          return *this;
       } 

      foo_bar_ptr m_p_value;
   };


   ////////////////////////////////////////////////////////////////
   // structure foo_variablerecordtype

   struct foo_variablerecordtype {    
    /* Can leave out - and would then allow aggregate inits */

         // default constructor
         foo_variablerecordtype();    
         // copy constructor
         foo_variablerecordtype(const foo_variablerecordtype&  r_a_variablerecordtype);   
         // destructor
         ~foo_variablerecordtype();
         //assignment operator
         foo_variablerecordtype& operator= (const foo_variablerecordtype& r_a_variablerecordtype);
   /* end of omissible */

        // workaround for insertion, sizing, extraction overload  
        // problem.  May be needed only for sunpro
          foo_variablerecordtype& self();
         // for ilustub use only - should be called before the
         // surrogate side stub returns
         void iluSurrogateSideCleanup() const;

         //member vars
           CORBA_String_var variablerecordstring;
           CORBA_Long variablerecordinteger;
           foo_bar_var variablerecordobject;
     };


     // declare the typecode instance for variablerecordtype
     NS_EXTERN const CORBA_TypeCode_ptr foo_tc_variablerecordtype;


///////////////////////////////////////////////////////////////////
// Exception foo_zapexception 
 
  class foo_zapexception : public CORBA_UserException{
    public:
      // constructors and destructors
      foo_zapexception() { };
      foo_zapexception(const foo_zapexception& a_zapexception);
      ~foo_zapexception();

      void _raise() { throw *this; };

      // assignment operator
      foo_zapexception& operator=(const foo_zapexception& a_zapexception);

      // constructor with member value
      foo_zapexception(const CORBA_Long& value);
 
      // Member
      const CORBA_Long& _value() const { return _m_value; }
      CORBA_Long _m_value;
  };

//////////////////////////////////////////////////////////////////////// 
// Initialization related

 // foo_initializer class is used to create a single instance that puts the
 // foo_iluInitialize onto the iluCppInternal::sm_p_initialization_function_list

  class foo_initializer {
    public:
      foo_initializer ();
      void * ensure_instantiation ();
      static foo_initializer sm_the_foo_initializer;
  };
// End the scope for foo

//////////////////////////////////////////////////////////////////////// 
// Initialization macros

  // If you're using a C++ compiler which does not initialize all non-local
  // statics before running main() (or you're doing something else which
  // could cause an unusual initialization order), you should use
  // one of the following macros to perform your initialization
  // before calling iluCppRuntime::iluInitialize()

  #define ILU_INIT_foo_CLIENT_ONLY() { \
     foo_initializer::sm_the_foo_initializer.ensure_instantiation();\
     foo_surrogate_bar_initializer::sm_the_surrogate_foo_bar_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_foo_SERVER_ONLY() { \
     foo_initializer::sm_the_foo_initializer.ensure_instantiation();\
     foo_true_bar_initializer::sm_the_true_foo_bar_initializer.ensure_instantiation(); \
   }

  #define ILU_INIT_foo_CLIENT_SERVER() { \
     foo_initializer::sm_the_foo_initializer.ensure_instantiation();\
     foo_surrogate_bar_initializer::sm_the_surrogate_foo_bar_initializer.ensure_instantiation(); \
     foo_true_bar_initializer::sm_the_true_foo_bar_initializer.ensure_instantiation(); \
   }

///////////////////////////////////////////////////////////////////////////
// insertion & extraction operators
// (Note: ops really needed for objects only if members of structured type)

  // insertion, extraction, and sizing operators for foo_variableuniontype
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const foo_variableuniontype& r_foo_variableuniontype);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const foo_variableuniontype& r_foo_variableuniontype);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               foo_variableuniontype& r_foo_variableuniontype);

  // insertion, extraction, and sizing operators for foo_boundedbarseq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const foo_boundedbarseq& r_foo_boundedbarseq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const foo_boundedbarseq& r_foo_boundedbarseq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               foo_boundedbarseq& r_foo_boundedbarseq);

  // insertion, extraction, and sizing operators for foo_unboundedlongseq
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const foo_unboundedlongseq& r_foo_unboundedlongseq);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const foo_unboundedlongseq& r_foo_unboundedlongseq);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               foo_unboundedlongseq& r_foo_unboundedlongseq);

  // insertion, extraction, and sizing operators for foo_variablerecordtype
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const foo_variablerecordtype& r_foo_variablerecordtype);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const foo_variablerecordtype& r_foo_variablerecordtype);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               foo_variablerecordtype& r_foo_variablerecordtype);

  // insertion, extraction, and sizing operators for foo_bar_var
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const foo_bar_var& r_foo_bar_var);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const foo_bar_var& r_foo_bar_var);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               foo_bar_var& r_foo_bar_var);

  // insertion, extraction, and sizing operators for foo_fixedrecordtype
  iluBaseCall& operator+=(iluBaseCall& r_call,
               const foo_fixedrecordtype& r_foo_fixedrecordtype);
  iluBaseCall& operator<< (iluBaseCall& r_call,
               const foo_fixedrecordtype& r_foo_fixedrecordtype);
  iluBaseCall& operator>>(iluBaseCall& r_call,
               foo_fixedrecordtype& r_foo_fixedrecordtype);

///////////////////////////////////////////////////////////////////////////
// insertion & extraction from anys


  // define the typecode class for foo_optionalinteger
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_optionalinteger, ilu_optional_tk,
        "ilut:ofauPtsPQTj2q-endOLfYeMwJ9O");

  // declare the Any insert and extract operators for foo_optionalinteger
  void operator<<=(CORBA_Any& r_any, const foo_optionalinteger_forany& r_foo_optionalinteger_forany);
  void operator<<=(CORBA_Any& r_any, foo_optionalinteger_forany* p_foo_optionalinteger_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_optionalinteger_forany*& rp_foo_optionalinteger);


  // define the typecode class for foo_optionalbarobject
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_optionalbarobject, ilu_optional_tk,
        "ilut:lA1-gauP3mLjEFspj2k52hq5PX7");

  // declare the Any insert and extract operators for foo_optionalbarobject
  void operator<<=(CORBA_Any& r_any, const foo_optionalbarobject_forany& r_foo_optionalbarobject_forany);
  void operator<<=(CORBA_Any& r_any, foo_optionalbarobject_forany* p_foo_optionalbarobject_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_optionalbarobject_forany*& rp_foo_optionalbarobject);


  // define the typecode class for foo_variableuniontype
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_variableuniontype, ilu_union_tk,
        "ilut:nmTjdwd3QN6EfRusSMC3dQWH7GF");

  // declare the Any insert and extract operators for foo_variableuniontype
  void operator<<=(CORBA_Any& r_any, const foo_variableuniontype& r_foo_variableuniontype);
  void operator<<=(CORBA_Any& r_any, foo_variableuniontype* p_foo_variableuniontype);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_variableuniontype*& rp_foo_variableuniontype);


  // define the typecode class for foo_boundedbarseq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_boundedbarseq, ilu_sequence_tk,
        "ilut:o5kjFsW9FbBFpk3mB0q+1DUevXV");

  // declare the Any insert and extract operators for foo_boundedbarseq
  void operator<<=(CORBA_Any& r_any, const foo_boundedbarseq& r_foo_boundedbarseq);
  void operator<<=(CORBA_Any& r_any, foo_boundedbarseq* p_foo_boundedbarseq);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_boundedbarseq*& rp_foo_boundedbarseq);


  // define the typecode class for foo_unboundedlongseq
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_unboundedlongseq, ilu_sequence_tk,
        "ilut:bT4M-C1TU4wI2xrA+cyasmB33Lf");

  // declare the Any insert and extract operators for foo_unboundedlongseq
  void operator<<=(CORBA_Any& r_any, const foo_unboundedlongseq& r_foo_unboundedlongseq);
  void operator<<=(CORBA_Any& r_any, foo_unboundedlongseq* p_foo_unboundedlongseq);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_unboundedlongseq*& rp_foo_unboundedlongseq);


  // define the typecode class for foo_bararray
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_bararray, ilu_array_tk,
        "ilut:ppduVKzUz7mJ9uNrb12ogZWBUMN");

  // declare the Any insert and extract operators for foo_bararray
  void operator<<=(CORBA_Any& r_any, const foo_bararray_forany& r_foo_bararray_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_bararray_forany& r_foo_bararray_forany);


  // define the typecode class for foo_integerarray
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_integerarray, ilu_array_tk,
        "ilut:dS1jP9Hb7HfmiCadLrIaDgo2AtH");

  // declare the Any insert and extract operators for foo_integerarray
  void operator<<=(CORBA_Any& r_any, const foo_integerarray_forany& r_foo_integerarray_forany);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_integerarray_forany& r_foo_integerarray_forany);


  // define the typecode class for foo_variablerecordtype
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_variablerecordtype, ilu_record_tk,
        "ilut:dZvb2JnjdmXfZjZmEsM9FjlUmaM");

  // declare the Any insert and extract operators for foo_variablerecordtype
  void operator<<=(CORBA_Any& r_any, const foo_variablerecordtype& r_foo_variablerecordtype);
  void operator<<=(CORBA_Any& r_any, foo_variablerecordtype* p_foo_variablerecordtype);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_variablerecordtype*& rp_foo_variablerecordtype);


  // define the typecode class for foo_bar
  ILUCPP_DEFINE_STUB_TYPE_CODE_OBJECT_CLASS(foo_bar, ilu_object_tk,
        "ilut:j6xiIgk9ZY9O9X-LhP1bCSKDYwK");

  // declare the Any insert and extract operators for foo_bar
  void operator<<=(CORBA_Any& r_any, foo_bar_ptr p_foo_bar);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any, foo_bar_ptr& rp_foo_bar);


  // define the typecode class for foo_fixedrecordtype
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_fixedrecordtype, ilu_record_tk,
        "ilut:fKR0RhuCfCNDSswEBpaTT2AakQv");

  // declare the Any insert and extract operators for foo_fixedrecordtype
  void operator<<=(CORBA_Any& r_any, const foo_fixedrecordtype& r_foo_fixedrecordtype);
  void operator<<=(CORBA_Any& r_any, foo_fixedrecordtype* p_foo_fixedrecordtype);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_fixedrecordtype*& rp_foo_fixedrecordtype);


  // define the typecode class for foo_enumtype
  ILUCPP_DEFINE_STUB_TYPE_CODE_CLASS(foo_enumtype, ilu_enumeration_tk,
        "ilut:p7G376cXCRfIoOT15k9jenyTrDT");

  // declare the Any insert and extract operators for foo_enumtype
  void operator<<=(CORBA_Any& r_any,  const foo_enumtype& r_foo_enumtype);
  CORBA_Boolean operator>>=(const CORBA_Any& r_any,
                foo_enumtype& r_foo_enumtype);

#endif
