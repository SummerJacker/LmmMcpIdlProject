// javastubs/Tutorial/_allJavaStubs.java
// Stubs for "Tutorial"
//



package Tutorial;

import xerox.basics.Environment;

/**
 * Loads all java classes used for the stub (client) 
 * side of the ilu interface which might not be loaded  
 * automatically when needed.
 */
public class _allJavaStubs {
    public static void load(){}
    static {
        xerox.basics.Environment.loadClasses("Tutorial.DivideByZero");
        xerox.basics.Environment.loadClasses("Tutorial.DivideByZero_exh_");
        xerox.basics.Environment.loadClasses("Tutorial.FactoryStub");
        xerox.basics.Environment.loadClasses("Tutorial.FactoryHelper");
        xerox.basics.Environment.loadClasses("Tutorial.CalculatorStub");
        xerox.basics.Environment.loadClasses("Tutorial.CalculatorHelper");
    }
}//_allJavaStubs

