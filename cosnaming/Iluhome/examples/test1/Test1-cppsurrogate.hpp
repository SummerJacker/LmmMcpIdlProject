

// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

#ifndef __Test1_cppsurrogate_H_
#define __Test1_cppsurrogate_H_

#include "Test1-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef Test1_surrogate_
#define Test1_surrogate_(name) NAME_INSIDE_SCOPE(Test1_surrogate,name)
#endif
#ifndef Test1_surrogate
#define Test1_surrogate(name) NAME_OUTSIDE_SCOPE(Test1_surrogate,name)
#endif

 // start the scope for Test1_surrogate 
  class Test1_surrogate_O3 :public virtual Test1_O3 {
    public:

     //ISL specified methods


      virtual Test1_IS* 
         RS_R_to_R_IS(
             const Test1_RS&  r,
             Test1_R*&  r2
             ) throw (CORBA_SystemException);

      virtual void
         O1_U_to_U(
             Test1_O1_ptr  o,
             Test1_U&  u
             ) throw (CORBA_SystemException, Test1_E2);

      virtual CORBA_Long 
         BS_to_I(
             const Test1_BS&  b
             ) throw (CORBA_SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a Test1_O3 object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return Test1_O3::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)

 
      static void _throw_O1_U_to_U_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, Test1_E2);

      static int _initialized;

  };

  // class initializer
  class Test1_surrogate_O3_initializer {
    public:
      Test1_surrogate_O3_initializer ();
      void * ensure_instantiation ();
      static Test1_surrogate_O3_initializer sm_the_surrogate_Test1_O3_initializer;
  };
  class Test1_surrogate_TheO1 :public virtual Test1_TheO1 {
    public:

     //ISL specified methods


      virtual Test1_U* 
         U_CSS_to_U(
             const Test1_U&  u,
             const Test1_CSS&  css
             ) throw (CORBA_SystemException, Test1_E1, Test1_E2);

      virtual Test1_R* 
         f_CSS_to_RO(
             const Test1_CSS&  css
             ) throw (CORBA_SystemException, Test1_E1);

      virtual CORBA_Float 
         R_ScS_to_F(
             const Test1_R&  r,
             Test1_const_ScS    s
             ) throw (CORBA_SystemException);

      virtual void
         a_RO(
             Test1_const_RO    ro
             ) throw (CORBA_SystemException);

      virtual Test1_O2_ptr 
         get_O2(
             ) throw (CORBA_SystemException, Test1_CantCreate);

      virtual Test1_O3_ptr 
         get_O3(
             CORBA_Boolean  subclass
             ) throw (CORBA_SystemException, Test1_CantCreate);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a Test1_TheO1 object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return Test1_TheO1::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)

 
      static void _throw_U_CSS_to_U_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, Test1_E1, Test1_E2); 
      static void _throw_f_CSS_to_RO_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, Test1_E1); 
      static void _throw_get_O2_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, Test1_CantCreate); 
      static void _throw_get_O3_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, Test1_CantCreate);

      static int _initialized;

  };

  // class initializer
  class Test1_surrogate_TheO1_initializer {
    public:
      Test1_surrogate_TheO1_initializer ();
      void * ensure_instantiation ();
      static Test1_surrogate_TheO1_initializer sm_the_surrogate_Test1_TheO1_initializer;
  };
  class Test1_surrogate_O2 :public virtual Test1_O2 {
    public:

     //ISL specified methods


      virtual Test1_CSS* 
         OO_A0_to_CSS(
             Test1_OO  o,
             const Test1_A0  a
             ) throw (CORBA_SystemException, Test1_E2);

      virtual Test1_A0_slice* 
         R_I_A1_to_I_A0(
             const Test1_R&  r,
             CORBA_Long&  i,
             const Test1_A1  a
             ) throw (CORBA_SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a Test1_O2 object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return Test1_O2::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)

 
      static void _throw_OO_A0_to_CSS_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, Test1_E2);

      static int _initialized;

  };

  // class initializer
  class Test1_surrogate_O2_initializer {
    public:
      Test1_surrogate_O2_initializer ();
      void * ensure_instantiation ();
      static Test1_surrogate_O2_initializer sm_the_surrogate_Test1_O2_initializer;
  };
  class Test1_surrogate_O4 : public virtual Test1_surrogate_O3, public virtual Test1_O4 {
    public:

     //ISL specified methods


      virtual CORBA_Double 
         R_to_R(
             CORBA_Double  r
             ) throw (CORBA_SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a Test1_O4 object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return Test1_O4::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)



      static int _initialized;

  };

  // class initializer
  class Test1_surrogate_O4_initializer {
    public:
      Test1_surrogate_O4_initializer ();
      void * ensure_instantiation ();
      static Test1_surrogate_O4_initializer sm_the_surrogate_Test1_O4_initializer;
  };
  class Test1_surrogate_P : public virtual Test1_surrogate_O3, public virtual Test1_P {
    public:

     //ISL specified methods


      virtual Test1_IS* 
         m2(
             CORBA_Long  j
             ) throw (CORBA_SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a Test1_P object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return Test1_P::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)



      static int _initialized;

  };

  // class initializer
  class Test1_surrogate_P_initializer {
    public:
      Test1_surrogate_P_initializer ();
      void * ensure_instantiation ();
      static Test1_surrogate_P_initializer sm_the_surrogate_Test1_P_initializer;
  };
 
// end the scope for Test1_surrogate 
 
#endif
