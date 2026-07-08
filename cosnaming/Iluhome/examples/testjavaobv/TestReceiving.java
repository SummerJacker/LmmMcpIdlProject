/* $Id: TestReceiving.java,v 1.4 2025/08/07 08:37:30 cvswxc Exp $ */

package test_client; 

/**
 * This class is the client side of a sample application of 
 * full custom mapping.
 */
class TestReceiving {
      
    static testJavaSerialObjects.ObjectGetter getter;
        
    static void handleIn() {
        try {
            java.lang.Object obj;
            System.out.println("Looking up a getter");
            getter = (testJavaSerialObjects.ObjectGetter) 
                xerox.ilu.IluSimpleBinding.lookup(
                    "testJavaSerialServer", 
                    "myFactory", 
                    testJavaSerialObjects.ObjectGetterStub.iluClass()
                    );
            System.out.println("Got a getter " + getter);
            //
            //Get the first object ...
            obj = getter.GetIt();
            System.out.println("First returned object is: " + obj);
            //
            //Get a second object ...
            obj = getter.GetIt();
            System.out.println("Second returned object is: " + obj);
            //
            //Get a third object ...
            obj = getter.GetIt();
            System.out.println("Third returned object is: " + obj);
            //
            //Get a fouth object ...
            obj = getter.GetIt();
            System.out.println("Fourth returned object is: " + obj);
            //
        } catch (org.omg.CORBA.SystemException e) {
            System.err.println("Caught an ilu exception: " + e );
        }
    } //handleIn

    public static void main(String argv[]) {
        System.out.println("Start TestReceiving...");
        //
        //Making sure test program has its stubs loaded
        testJavaSerialObjects._allJavaStubs.load();
        //
        //Telling ilu that it may load classes through the wire
        xerox.ilujava.IluOBVWireClassLoader.load();
        System.out.println("wire-class-loader loaded");
        //
        //Telling ilu that it may load classes through URL's
        if (argv.length>0) {
            try {
                xerox.ilujava.IluOBVURLClassLoader.load();
                xerox.ilujava.IluOBVURLClassLoader.addURLToPath(
                    new java.net.URL(argv[0])
                    );
                System.out.println("URL-class-loader for " 
                    + argv[0] + " loaded"
                    );
            } catch (Exception e) {
                System.out.println(
                    "**Couldn't register IluOBVURLClassLoader" + e
                    );
            }
        }
        //
        System.out.println("All the junk is loaded");
        handleIn();
    } //main

} //TestReceiving

