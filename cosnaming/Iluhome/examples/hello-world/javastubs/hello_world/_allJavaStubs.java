// javastubs/hello_world/_allJavaStubs.java
// Stubs for "hello-world"
//



package hello_world;

import xerox.basics.Environment;

/**
 * Loads all java classes used for the stub (client) 
 * side of the ilu interface which might not be loaded  
 * automatically when needed.
 */
public class _allJavaStubs {
    public static void load(){}
    static {
        xerox.basics.Environment.loadClasses("hello_world.serviceStub");
        xerox.basics.Environment.loadClasses("hello_world.serviceHelper");
    }
}//_allJavaStubs

