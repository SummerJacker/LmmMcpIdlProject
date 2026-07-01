


// This file was automatically generated with ILU (version 2.0beta1) tools
// ILU is Copyright 1991-1999 Xerox Corporation, All Rights Reserved.
// ILU information:  ftp://ftp.parc.xerox.com/pub/ilu/ilu.html.

// Prevent multiple inclusions
#ifndef __SRIO_Monitor_cpptrue_H_
#define __SRIO_Monitor_cpptrue_H_

#include "SRIO-Monitor-cpp.hpp"

#define SRIO_Monitor_true_(name) NAME_INSIDE_SCOPE(SRIO_Monitor_true, name)
#define SRIO_Monitor_true(name) NAME_OUTSIDE_SCOPE(SRIO_Monitor_true, name)
 // start the scope for SRIO_Monitor_true 
namespace SRIO_Monitor_true {

  class Monitor_initializer {
    public:
      Monitor_initializer ();
      void * ensure_instantiation ();

      static Monitor_initializer sm_the_true_SRIO_Monitor_Monitor_initializer;

    private:
      static void iluInitialize ();
      // set to 1 once initialization has occured.
      static int initialized;
  };

 
// end the scope for SRIO_Monitor_true 
 }
 
#endif
