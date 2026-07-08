

// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

#ifndef __Test3_cppsurrogate_H_
#define __Test3_cppsurrogate_H_

#include "Test3-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef Test3_surrogate_
#define Test3_surrogate_(name) NAME_INSIDE_SCOPE(Test3_surrogate,name)
#endif
#ifndef Test3_surrogate
#define Test3_surrogate(name) NAME_OUTSIDE_SCOPE(Test3_surrogate,name)
#endif
#include "Test1-cppsurrogate.hpp"
#include "Test2-cppsurrogate.hpp"

 // start the scope for Test3_surrogate 
  class Test3_surrogate_O : public virtual Test1_surrogate_O3,  public virtual Test2_surrogate_P, public virtual Test3_O {
    public:

     //ISL specified methods


      virtual Test2_T1U* 
         I_to_Test1U(
             CORBA_Long  i
             ) throw (CORBA_SystemException, Test3_E1, Test1_E1);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a Test3_O object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return Test3_O::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)

 
      static void _throw_I_to_Test1U_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, Test3_E1, Test1_E1);

      static int _initialized;

  };

  // class initializer
  class Test3_surrogate_O_initializer {
    public:
      Test3_surrogate_O_initializer ();
      void * ensure_instantiation ();
      static Test3_surrogate_O_initializer sm_the_surrogate_Test3_O_initializer;
  };
 
// end the scope for Test3_surrogate 
 
#endif
