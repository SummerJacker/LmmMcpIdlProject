(* $Id: hello-world.isl,v 1.6 2025/07/30 08:24:59 cvswxc Exp $ *)


INTERFACE hello-world;

TYPE service = OBJECT
  METHODS
    hello-world (IN inarg: ilu.CString) :ilu.CString 
  END;
