

// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

// Prevent multiple inclusions
#ifndef __Test3_cpptrue_H_
#define __Test3_cpptrue_H_

#include "Test3-cpp.hpp"

#define Test3_true_(name) NAME_INSIDE_SCOPE(Test3_true, name)
#define Test3_true(name) NAME_OUTSIDE_SCOPE(Test3_true, name)
 // start the scope for Test3_true 

  class Test3_true_O_initializer {
    public:
      Test3_true_O_initializer ();
      void * ensure_instantiation ();

      static Test3_true_O_initializer sm_the_true_Test3_O_initializer;

    private:
      static void iluInitialize ();
      // set to 1 once initialization has occured.
      static int initialized;
  };

 
// end the scope for Test3_true 
 
#endif
