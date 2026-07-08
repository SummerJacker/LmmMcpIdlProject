/* $Id: BankAppletVisi.java,v 1.4 2025/08/01 00:22:51 cvswxc Exp $ */


import java.awt.*;

public class BankAppletVisi extends java.applet.Applet {

  private static final String useVisiBind = "visigenic...bind";
  
  private TextField _iorField, _nameField, _balanceField;
  private Button _checkBalance;
  private Bank.AccountManager _manager;
  CORBA.ORB orb;
  private String _ior = null;

  public void init() {
    // This GUI uses a 2 by 3 grid of widgets.
    setLayout(new GridLayout(3, 2, 5, 5));
    // Add the four widgets.
    add(new Label("_ior"));
    add(_iorField = new TextField());
    add(new Label("Account Name"));
    add(_nameField = new TextField());
    add(_checkBalance = new Button("Check Balance"));
    add(_balanceField = new TextField());
    // make the balance text field non-editable.
    _balanceField.setEditable(false);
    _iorField.setText(getParameter("IOR"));
    try {
      // Initialize the ORB (using the Applet).
      orb = CORBA.ORB.init(this);
    } catch(CORBA.SystemException e) {
      System.out.println(e);
      e.printStackTrace();
      _balanceField.setText("exception...");
    }
  }

  public boolean action(Event ev, Object arg) {
    if(ev.target == _checkBalance) {
      String ior = _iorField.getText();
      if (ior == null || ior.length() == 0) {
          ior = getParameter("IOR");
          _iorField.setText(ior);
      }
      try {
        if (_ior == null || ! _ior.equals(ior)) {
          _ior = ior;
          if (useVisiBind.equals(_ior)) {
            _manager = Bank.AccountManager_var.bind("Post-Modern Bank");        
          } else {
            CORBA.Object obj = orb.string_to_object(_ior);
            _manager = Bank.AccountManager_var.narrow(obj);
          }
        }
        // Request the account manager to open a named account.
        // Get the account name from the name text widget.
        Bank.Account account = _manager.open(_nameField.getText());
        // Set the balance text widget to the account's balance.
        _balanceField.setText(Float.toString(account.balance()));
      }
      catch(CORBA.SystemException e) {
        System.out.println(e);
        e.printStackTrace();
        _balanceField.setText("exception...");
      }
      return true;
    }
    return false;
  }

}
