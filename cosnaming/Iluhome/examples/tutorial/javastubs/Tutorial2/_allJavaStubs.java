// javastubs/Tutorial2/_allJavaStubs.java
// Stubs for "Tutorial2"
//



package Tutorial2;

import xerox.basics.Environment;

/**
 * Loads all java classes used for the stub (client) 
 * side of the ilu interface which might not be loaded  
 * automatically when needed.
 */
public class _allJavaStubs {
    public static void load(){}
    static {
        xerox.basics.Environment.loadClasses("Tutorial2.FactoryStub");
        xerox.basics.Environment.loadClasses("Tutorial2.FactoryHelper");
        xerox.basics.Environment.loadClasses("Tutorial2.TapeCalculatorStub");
        xerox.basics.Environment.loadClasses("Tutorial2.TapeCalculatorHelper");
        xerox.basics.Environment.loadClasses("Tutorial2.RegisterTape");
        xerox.basics.Environment.loadClasses("Tutorial2.RegisterTapeHelper");
        xerox.basics.Environment.loadClasses("Tutorial2.Operation");
        xerox.basics.Environment.loadClasses("Tutorial2.OperationHelper");
        xerox.basics.Environment.loadClasses("Tutorial2.OpType");
        xerox.basics.Environment.loadClasses("Tutorial2.OpTypeHelper");
    }
}//_allJavaStubs

