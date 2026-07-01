

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

// Prevent multiple inclusions
#ifndef __SRIO_Ground_Unit_cpptrue_H_
#define __SRIO_Ground_Unit_cpptrue_H_

#include "SRIO-Ground-Unit-cpp.hpp"

#define SRIO_Ground_Unit_true_(name) NAME_INSIDE_SCOPE(SRIO_Ground_Unit_true, name)
#define SRIO_Ground_Unit_true(name) NAME_OUTSIDE_SCOPE(SRIO_Ground_Unit_true, name)
 // start the scope for SRIO_Ground_Unit_true 
namespace SRIO_Ground_Unit_true {

  class Ground_Unit_initializer {
    public:
      Ground_Unit_initializer ();
      void * ensure_instantiation ();

      static Ground_Unit_initializer sm_the_true_SRIO_Ground_Unit_Ground_Unit_initializer;

    private:
      static void iluInitialize ();
      // set to 1 once initialization has occured.
      static int initialized;
  };

 
// end the scope for SRIO_Ground_Unit_true 
 }
 
#endif
