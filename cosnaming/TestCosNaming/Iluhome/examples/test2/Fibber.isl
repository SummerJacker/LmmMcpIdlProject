(* $Id: Fibber.isl,v 1.4 2025/08/02 10:52:05 cvswxc Exp $ *)

INTERFACE Fibber;

TYPE String = SEQUENCE OF SHORT CHARACTER;
TYPE StringSeq = SEQUENCE OF String;

EXCEPTION Failed: StringSeq;

TYPE T = OBJECT
	METHODS
	Calc(d: CARDINAL, n: CARDINAL, ask: T): CARDINAL
		RAISES Failed END
	(* Return fib(n), using /ask/ for recursive calls. *)
	END;

