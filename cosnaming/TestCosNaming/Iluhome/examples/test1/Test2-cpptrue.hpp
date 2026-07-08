

// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

// Prevent multiple inclusions
#ifndef __Test2_cpptrue_H_
#define __Test2_cpptrue_H_

#include "Test2-cpp.hpp"

#define Test2_true_(name) NAME_INSIDE_SCOPE(Test2_true, name)
#define Test2_true(name) NAME_OUTSIDE_SCOPE(Test2_true, name)
 // start the scope for Test2_true 

  class Test2_true_P_initializer {
    public:
      Test2_true_P_initializer ();
      void * ensure_instantiation ();

      static Test2_true_P_initializer sm_the_true_Test2_P_initializer;

    private:
      static void iluInitialize ();
      // set to 1 once initialization has occured.
      static int initialized;
  };

 
// end the scope for Test2_true 
 
#endif
