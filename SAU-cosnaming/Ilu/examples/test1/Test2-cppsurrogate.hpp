

// This file was automatically generated with  KIS-CORBA (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
// KIS-CORBA information:  http://www.kestrelsystems.ca.

#ifndef __Test2_cppsurrogate_H_
#define __Test2_cppsurrogate_H_

#include "Test2-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef Test2_surrogate_
#define Test2_surrogate_(name) NAME_INSIDE_SCOPE(Test2_surrogate,name)
#endif
#ifndef Test2_surrogate
#define Test2_surrogate(name) NAME_OUTSIDE_SCOPE(Test2_surrogate,name)
#endif
#include "Test1-cppsurrogate.hpp"

 // start the scope for Test2_surrogate 
  class Test2_surrogate_P :public virtual Test2_P {
    public:

     //ISL specified methods


      virtual CORBA_Long 
         SR_to_I(
             CORBA_Float  i
             ) throw (CORBA_SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a Test2_P object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return Test2_P::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)



      static int _initialized;

  };

  // class initializer
  class Test2_surrogate_P_initializer {
    public:
      Test2_surrogate_P_initializer ();
      void * ensure_instantiation ();
      static Test2_surrogate_P_initializer sm_the_surrogate_Test2_P_initializer;
  };
 
// end the scope for Test2_surrogate 
 
#endif
