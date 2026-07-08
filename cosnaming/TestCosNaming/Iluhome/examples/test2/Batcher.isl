(* $Id: Batcher.isl,v 1.4 2025/08/02 10:52:05 cvswxc Exp $ *)

INTERFACE Batcher;

TYPE Time = LONG CARDINAL;
TYPE TimeRec = RECORD s: Time, r: Time END;
TYPE TimeSeq = SEQUENCE OF TimeRec;

TYPE T = OBJECT METHODS
	ASYNCHRONOUS Send(s: Time),
	Sync(s: Time): TimeSeq
	END;
