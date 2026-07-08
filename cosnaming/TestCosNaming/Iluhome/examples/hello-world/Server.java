/* $Id: Server.java,v 1.5 2025/07/28 09:09:22 cvswxc Exp $ */

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


