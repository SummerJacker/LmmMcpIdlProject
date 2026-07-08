(* $Id: SerialTest.isl,v 1.4 2025/08/01 09:14:18 cvswxc Exp $ *)

INTERFACE SerialTest;

TYPE T = OBJECT METHODS
	Prep(nthr: CARDINAL, n: CARDINAL),
	ASYNCHRONOUS M(series: CARDINAL, i: CARDINAL),
	N(series: CARDINAL, i: CARDINAL)
	END;
