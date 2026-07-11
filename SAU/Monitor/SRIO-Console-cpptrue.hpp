

// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

// Prevent multiple inclusions
#ifndef __SRIO_Console_cpptrue_H_
#define __SRIO_Console_cpptrue_H_

#include "SRIO-Console-cpp.hpp"

#define SRIO_Console_true_(name) NAME_INSIDE_SCOPE(SRIO_Console_true, name)
#define SRIO_Console_true(name) NAME_OUTSIDE_SCOPE(SRIO_Console_true, name)
 // start the scope for SRIO_Console_true 
namespace SRIO_Console_true {

  class Console_initializer {
    public:
      Console_initializer ();
      void * ensure_instantiation ();

      static Console_initializer sm_the_true_SRIO_Console_Console_initializer;

    private:
      static void iluInitialize ();
      // set to 1 once initialization has occured.
      static int initialized;
  };

 
// end the scope for SRIO_Console_true 
 }
 
#endif
