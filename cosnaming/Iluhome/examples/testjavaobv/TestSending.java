/* $Id: TestSending.java,v 1.4 2025/08/07 08:37:30 cvswxc Exp $ */

package test_sender; 

/**
 * This class is the server side of a sample application of 
 * full custom mapping and object serialization.
 */
class TestSending {
  
    static xerox.ilu.IluServer trueServer;
    static ObjectGetterImpl getter;
    
    
    static void usageExit() {
        System.err.println("USAGE: java test_sender.TestSending ( url | (wire file-name) | (uncached file-name) )");
        System.exit(1);
    } //usageExit
    
    
    static void handleOut() {
        try {
            System.out.println("Starting a server");
            trueServer = xerox.ilu.IluServer.createServer(
                "testJavaSerialServer"
                );
            System.out.println("Server created");
            getter = new ObjectGetterImpl();
            testJavaSerialObjects.ObjectGetterStub.registerTrueObject( 
                "myFactory", 
                getter, 
                trueServer
                );
            xerox.ilu.IluSimpleBinding.publish(getter);
            System.out.println("Factory instance published");
            String sbh = xerox.ilu.Ilu.sbhOfObject(getter);
            System.out.println("Its SBH is '" + sbh + "'");
        } catch (org.omg.CORBA.SystemException e) {
            System.err.println("Caught an ilu exception: " + e);
            e.printStackTrace(System.err);
        }
    } //handleOut

    
    public static void main(String argv[]) {
        if (argv.length < 1) usageExit();
        String method = argv[0];
        System.out.println("Start TestSending");
        xerox.ilujava._allJavaStubs.load();
        testJavaSerialObjects._allJavaStubs.load();
        System.out.println("junk is loaded");
        xerox.ilujava.ClassAccessor accessor = null;
        if (method.equals("url")) {
            xerox.ilujava.IluOBV.setDefaultAccessMethod(
                "URL", null 
                );
        
        } else {
            if (argv.length < 2) usageExit();
            String jarfile = argv[1];
            accessor = new xerox.ilujava.ClassAccessorImplFromJar(
                jarfile
            );
            if (method.equals("wire")) {
                xerox.ilujava.IluOBV.setDefaultAccessMethod(
                    xerox.ilujava.IluOBVWireClassLoader.cachedAccess,
                    accessor
                    );
            } else if (method.equals("uncached")) {
                xerox.ilujava.IluOBV.setDefaultAccessMethod(
                    xerox.ilujava.IluOBVWireClassLoader.unCachedAccess,
                    accessor
                    );
            } else {
                usageExit();
            }
        }
        System.out.println("default IluOBV accessor has been set");
        handleOut();
    } //main

} //TestSending


class ObjectGetterImpl 
        extends xerox.ilu.IluObjectBase
        implements testJavaSerialObjects.ObjectGetter {
        
    public ObjectGetterImpl() {
    } //constructor
    
    static int count = 0;
    
    public java.lang.Object GetIt() {
        java.lang.Object innerObject = "silly string";
        System.out.println("ObjectGetterImpl called");
        count = count + 1;
        if (count==2) {return null;}
        if (count==3) {innerObject = this;}
        if (count==4) {
           xerox.ilujava.IluOBV mo = new xerox.ilujava.IluOBV();
           innerObject = mo;
           try {
               xerox.ilujava.IluOBV.setMO(
                   mo, "unmarshalled other string"
                   );
           } catch (java.io.IOException e) {
               System.out.println("*** caught " + e);
           }
        }
        FooWhizBangFuzzler x = new FooWhizBangFuzzler(innerObject);
        return x;
    } //GetIt
    
} //ObjectGetterImpl



