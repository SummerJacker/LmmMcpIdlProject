/* $Id: Client.java,v 1.4 2025/06/22 05:52:45 cvswxc Exp $
 * $Log: Client.java,v $
 * Revision 1.4  2025/06/22 05:52:45  cvswxc
 * test the new cvs server/client works or not
 * Committed on the Free edition of March Hare Software CVSNT Server.
 * Upgrade to CVS Suite for more features and support:
 * http://march-hare.com/cvsnt/
 *  
*/
/* Chris Jacobi, November 30, 1998 4:38 pm PST */
/* Last edited by Mike Spreitzer October 9, 1998 1:30 pm PDT */

package hello_world;

/**
 * The hello_world client.
 * Usage: java hello_world.Client SBH-OF-SERVER
 */ 
public class Client {
    
    public static void main(String argv[]) {
        if (argv.length < 1) {
            System.err.println(
                "Usage: java hello_world.Client SBH-OF-SERVER"
                );
            System.exit(1);
        }
        String sbh = argv[0];
        String response = null;
        hello_world.service serv = null;
        try {
            serv = (hello_world.service) 
                xerox.ilu.Ilu.objectFromSBH(
                    sbh, hello_world.serviceStub.iluClass()
                    );
        } catch (org.omg.CORBA.SystemException e) {
            System.err.println("Can't get object for sbh " + sbh);
            System.err.println("Exception is: " + e);
            System.exit(1);
        }
        try {
            response = serv.hello_world();
        } catch (org.omg.CORBA.SystemException e) {
            System.err.println("Service fails");
            System.err.println("Exception is: " + e);
            System.exit(1);
        }
        System.out.println("The response is: " + response);
    } //main
    
} //client



