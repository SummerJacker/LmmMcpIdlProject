/* $Id: ClientILU.java,v 1.4 2025/08/01 00:22:51 cvswxc Exp $ */

public class ClientILU {

  public static void main(String args[]) {
    try {
      // Initialize the ORB.
      // Locate an account manager.
      Bank.AccountManager manager = (Bank.AccountManager) 
         xerox.ilu.Ilu.objectFromSBH(args[0], Bank.AccountManagerStub.iluClass());
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
    }
  }
}
