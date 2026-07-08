

// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

// Prevent multiple inclusions
#ifndef __foo_cpptrue_H_
#define __foo_cpptrue_H_

#include "foo-cpp.hpp"

#define foo_true_(name) NAME_INSIDE_SCOPE(foo_true, name)
#define foo_true(name) NAME_OUTSIDE_SCOPE(foo_true, name)
 // start the scope for foo_true 

  class foo_true_bar_initializer {
    public:
      foo_true_bar_initializer ();
      void * ensure_instantiation ();

      static foo_true_bar_initializer sm_the_true_foo_bar_initializer;

    private:
      static void iluInitialize ();
      // set to 1 once initialization has occured.
      static int initialized;
  };

 
// end the scope for foo_true 
 
#endif
