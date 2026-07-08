/* $Id: ClientOMG.java,v 1.4 2025/08/01 00:22:51 cvswxc Exp $ */


public class ClientOMG {

  public static void main(String args[]) {
    try {
      // Initialize the ORB.
      org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args, null);
      // Locate an account manager.
      org.omg.CORBA.Object obj = orb.string_to_object(args[0]);
      Bank.AccountManager manager = Bank.AccountManagerHelper.narrow(obj);
      // use args[0] as the account name, or a default.
      String name = args.length > 1 ? args[1] : "Jack B. Quick";
      // Request the account manager to open a named account.
      Bank.Account account = manager.open(name);
      // Get the balance of the account.
      float balance = account.balance();
      // Print out the balance.
      System.out.println
	("The balance in " + name + "'s account is $" + balance);
    }
    catch(org.omg.CORBA.SystemException e) {
      System.err.println(e);
      e.printStackTrace(System.err);
    }
  }
}
