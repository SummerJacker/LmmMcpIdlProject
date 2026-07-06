/* $Id: Server.java,v 1.4 2025/06/22 07:52:13 cvswxc Exp $
   $Log: Server.java,v $
   Revision 1.4  2025/06/22 07:52:13  cvswxc
   #681 remove old infor
   Committed on the Free edition of March Hare Software CVSNT Server.
   Upgrade to CVS Suite for more features and support:
   http://march-hare.com/cvsnt/
 
*/
/* Chris Jacobi, November 30, 1998 4:43 pm PST */
/* Last edited by Mike Spreitzer October 9, 1998 1:30 pm PDT */

package hello_world;

/**
 * The hello_world server.
 * Usage: java -Djava.compiler=NONE hello_world.Server 
 */ 
public class Server {
        
    public static void main(String argv[]) {
        xerox.ilu.Ilu.init();
        ServiceImpl service = new ServiceImpl();
        xerox.ilu.Ilu.registerTrueObject(
            xerox.ilu.Ilu.inventID(), 
            service, 
            xerox.ilu.IluServer.createServer(null), 
            hello_world.serviceStub.iluClass(),
            xerox.ilu.IluLifetimeArgs.iluLifetimeRemember
            );
        System.out.println(
            "hello world server is: \"" +  
            xerox.ilu.Ilu.sbhOfObject(service) +
            "\""
            );
    } //main
    
} //Server


/**
 * Implementing the actual service.
 */ 
class ServiceImpl  
    extends xerox.ilu.IluObjectBase 
    implements hello_world.service
{
    
    public String hello_world() {
        return "\"Hello, World!\" from Java";
    } //hello_world
    
} //ServiceImpl


