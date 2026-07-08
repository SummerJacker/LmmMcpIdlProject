/* $Id: ServerILU.java,v 1.4 2025/08/01 00:22:51 cvswxc Exp $ */

import java.util.*;

class AccountILU 
    extends xerox.ilu.IluObjectBase 
    implements Bank.Account {
  AccountILU(float balance) {
    _balance = balance;
  }
  public float balance() throws org.omg.CORBA.SystemException {
    return _balance;
  }
  private float _balance;
}

class AccountManagerILU 
    extends xerox.ilu.IluObjectBase 
    implements Bank.AccountManager {
  AccountManagerILU(String name) {
    //super(name);
  }
  public Bank.Account open(String name) {
    // Lookup the account in the account dictionary.
    Bank.Account account = (Bank.Account) _accounts.get(name);
    if(account == null) {
      // Create a new account with between 0 and 1000 dollars.
      float balance = Math.abs(_random.nextInt()) % 100000 / 100f;
      account = new AccountILU(balance);
      System.out.println("Created " + name + "'s account: " + account);
      // Export the new object reference.
      // CORBA.ORB.init().BOA_init().obj_is_ready(account);
      // Save the account in the account dictionary.
      _accounts.put(name, account);
    }
    // Return the account.
    return account;
  }
  private Dictionary _accounts = new Hashtable();
  private Random _random = new Random();
}

public class ServerILU {
  static xerox.ilu.IluServer trueServer;
  
  public static void main(String[] args) {
    try {
      // Initialize the ORB.
      trueServer = xerox.ilu.IluServer.createServer("ThisExamplesServer");
      String[] ti = {"tcp_0_0"};
      trueServer.createPort("iiop", new xerox.ilu.IluTransportInfo(ti), null);

      // Initialize the BOA.
      // Create the account manager object.
      AccountManagerILU manager = 
	new AccountManagerILU("Post-Modern Bank");
      // Export the newly create object.
      Bank._allJavaStubs.load();
      Bank.AccountManagerStub.registerTrueObject( 
          "OurManager", 
          manager, 
          trueServer);
      System.out.println(xerox.ilu.Ilu.iorOfObject(manager));
      // Wait for incoming requests
    } catch(org.omg.CORBA.SystemException e) {
      System.err.println(e);
    }
  }
}

