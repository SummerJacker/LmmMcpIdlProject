(** $Id: hello-world.isl,v 1.4 2025/06/22 07:50:29 cvswxc Exp $
 ** $Log: hello-world.isl,v $
 ** Revision 1.4  2025/06/22 07:50:29  cvswxc
 ** #681 remove old infor
 ** Committed on the Free edition of March Hare Software CVSNT Server.
 ** Upgrade to CVS Suite for more features and support:
 ** http://march-hare.com/cvsnt/
 **  
*)
(* Last edited by Mike Spreitzer October 8, 1998 11:00 pm PDT *)

INTERFACE hello-world;

TYPE service = OBJECT
  METHODS
    hello-world () : ilu.CString
  END;
