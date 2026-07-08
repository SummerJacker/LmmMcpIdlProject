(* $Id: grid.isl,v 1.4 2025/08/01 00:29:09 cvswxc Exp $ *)


INTERFACE grid;

TYPE grid = OBJECT OPTIONAL TYPEID "IDL:grid:1.0"
	METHODS
		ilu--prefix-idlAttribute--get-height () : SHORT INTEGER,
		ilu--prefix-idlAttribute--get-width () : SHORT INTEGER,
		set (n : SHORT INTEGER, m : SHORT INTEGER, value : INTEGER),
		get (n : SHORT INTEGER, m : SHORT INTEGER) : INTEGER
	END;
