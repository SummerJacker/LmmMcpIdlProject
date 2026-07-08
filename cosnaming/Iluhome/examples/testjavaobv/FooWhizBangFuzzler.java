/* $Id: FooWhizBangFuzzler.java,v 1.4 2025/08/07 08:37:30 cvswxc Exp $ */

package test_sender; 

/**
 * Useless class used to demonstrate shipping behaviour.
 * The main point is to make sure that this class exist
 * on the server side of the example but not on the client
 * side.  Successfully running the example will load this
 * class on the client side through the ilu connection.
 */
public class FooWhizBangFuzzler implements java.io.Serializable  {
   
   java.lang.Object theChild = null;
   
   public FooWhizBangFuzzler(java.lang.Object ob) {
       this.theChild = ob;
   } //constructor
   
   public java.lang.String toString() {
       return "FooWhizBangFuzzler[" + theChild + "]";
   } //toString
   
   protected java.lang.Object readResolve() throws java.io.ObjectStreamException {
        System.out.println("readResolve called");
        if (theChild instanceof String) {
            theChild = "resolved..." + theChild;
        }
        return this;
    } //readResolve
    
    static {
      System.out.println("The FooWhizBangFuzzler class static initialization;  check how often this is called to count class loaders.");
   }
   
} //FooWhizBangFuzzler

