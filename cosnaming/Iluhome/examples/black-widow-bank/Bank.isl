(**
$Id: Bank.isl,v 1.4 2025/06/22 05:29:35 cvswxc Exp $
$Log: Bank.isl,v $
Revision 1.4  2025/06/22 05:29:35  cvswxc
test the new cvs server/client works or not
Committed on the Free edition of March Hare Software CVSNT Server.
Upgrade to CVS Suite for more features and support:
http://march-hare.com/cvsnt/

*)
(* Last edited by Mike Spreitzer October 8, 1998 10:22 pm PDT *)

INTERFACE Bank;

TYPE Account = OBJECT TYPEID "IDL:Bank/Account:1.0"
  METHODS
    balance () : SHORT REAL
  END;

TYPE AccountManager = OBJECT TYPEID "IDL:Bank/AccountManager:1.0"
  METHODS
    open (name : ilu.CString) : Account
  END;
