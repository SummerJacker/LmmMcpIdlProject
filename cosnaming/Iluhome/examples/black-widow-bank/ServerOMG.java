/* $Id: ServerOMG.java,v 1.4 2025/08/01 00:22:51 cvswxc Exp $ */

import java.util.*;

class AccountOMG extends Bank._AccountImplBase {
  AccountOMG(float balance) {
    _balance = balance;
  }
  public float balance() throws org.omg.CORBA.SystemException {
    return _balance;
  }
  private float _balance;
} //AccountOMG


class AccountManagerOMG extends Bank._AccountManagerImplBase {
  AccountManagerOMG(String name) {
  }
  public Bank.Account open(String name) 
          throws org.omg.CORBA.SystemException {
    // Lookup the account in the account dictionary.
    Bank.Account account = (Bank.Account) _accounts.get(name);
    if (account == null) {
      // Create a new account with between 0 and 1000 dollars.
      float balance = Math.abs(_random.nextInt()) % 100000 / 100f;
      account = new AccountOMG(balance);
      // Export the new object reference.
      ServerOMG.orb.connect(account);
      System.out.println("Created " + name + "'s account: " + account);
      // Save the account in the account dictionary.
      _accounts.put(name, account);
    }
    // Return the account.
    return account;
  }
  private Dictionary _accounts = new Hashtable();
  private Random _random = new Random();
} //AccountManagerOMG


public class ServerOMG {
  
  public static org.omg.CORBA.ORB orb = null;
  
  public static void main(String[] args) {
    try {
      // Initialize the ORB.
      orb = org.omg.CORBA.ORB.init(args, null);
      // Create the account manager object.
      AccountManagerOMG manager = new AccountManagerOMG("Post-Modern Bank");
      // Export the newly create object.
      orb.connect(manager);      
      //print its ior
      System.out.println(orb.object_to_string(manager));
      // wait for invocations from clients
      java.lang.Object sync = new java.lang.Object();
      synchronized (sync) {
          sync.wait();
      }    
    } catch (Exception e) {
      System.err.println(e);
      e.printStackTrace(System.err);
    }
  }
  
} //ServerOMG


