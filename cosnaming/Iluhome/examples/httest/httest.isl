(* $Id: httest.isl,v 1.4 2025/08/07 13:51:07 cvswxc Exp $ *)

(* 
   Sample interface that imports http.isl and adds a method to 
   the resource object as defined in http.isl

	-- Dan Larner, 
*)

INTERFACE httest IMPORTS iluhttp END;

EXCEPTION FLIPEXCEP: INTEGER;

TYPE DerivedResource = OBJECT
  DOCUMENTATION "Derived object of Resource to test http subtypes"
  SUPERTYPES iluhttp.Resource END
  METHODS
	flipcase (strtoflipcase : ilu.CString ) : ilu.CString RAISES FLIPEXCEP END
  END;
