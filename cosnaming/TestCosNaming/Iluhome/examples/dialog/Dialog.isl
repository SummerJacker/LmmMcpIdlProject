(* $Id: Dialog.isl,v 1.4 2025/08/01 04:58:01 cvswxc Exp $ *)
(* Last edited by Mike Spreitzer October 8, 1998 10:45 pm PDT *)

INTERFACE Dialog;

TYPE String = SEQUENCE OF SHORT CHARACTER;

TYPE T = OBJECT METHODS
	M(arg: String): String
	END;
