(* $Id: Batcher2.isl,v 1.4 2025/08/02 10:52:05 cvswxc Exp $ *)

INTERFACE Batcher2;

TYPE Time = LONG CARDINAL;
TYPE Bytes = SEQUENCE OF BYTE;

TYPE Server = OBJECT METHODS
	ASYNCHRONOUS Request(r: Time, x: CARDINAL, phil: Bytes,
	                     replyTo: CallBack)
	END;

TYPE CallBack = OBJECT METHODS
	ASYNCHRONOUS Reply(r: Time, x: CARDINAL, s: Time)
	END;
