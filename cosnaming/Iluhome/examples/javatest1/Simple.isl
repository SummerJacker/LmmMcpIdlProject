(* $Id: Simple.isl,v 1.4 2025/08/02 11:45:15 cvswxc Exp $ *)

INTERFACE Simple;
    EXCEPTION Exc1;
    EXCEPTION Exc2;
    TYPE TestObject = OBJECT OPTIONAL
        METHODS
            method1(i: INTEGER): INTEGER RAISES Exc1, Exc2 END
        END;
