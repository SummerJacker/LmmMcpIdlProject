

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

// Prevent multiple inclusions
#ifndef __SRIO_Unit_cpptrue_H_
#define __SRIO_Unit_cpptrue_H_

#include "SRIO-Unit-cpp.hpp"

#define SRIO_Unit_true_(name) NAME_INSIDE_SCOPE(SRIO_Unit_true, name)
#define SRIO_Unit_true(name) NAME_OUTSIDE_SCOPE(SRIO_Unit_true, name)
 // start the scope for SRIO_Unit_true 
namespace SRIO_Unit_true {

  class General_Unit_initializer {
    public:
      General_Unit_initializer ();
      void * ensure_instantiation ();

      static General_Unit_initializer sm_the_true_SRIO_Unit_General_Unit_initializer;

    private:
      static void iluInitialize ();
      // set to 1 once initialization has occured.
      static int initialized;
  };

 
// end the scope for SRIO_Unit_true 
 }
 
#endif
