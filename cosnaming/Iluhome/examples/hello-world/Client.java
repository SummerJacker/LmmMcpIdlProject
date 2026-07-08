/* $Id: Client.java,v 1.5 2025/07/28 09:09:22 cvswxc Exp $
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



