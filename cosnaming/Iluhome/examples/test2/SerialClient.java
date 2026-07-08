/* $Id: SerialClient.java,v 1.4 2025/08/01 09:14:09 cvswxc Exp $ */

/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */


/*
 * Run this like
 * java SerialTest.SerialClient n n [v] <p>
 *
 * Transliteration of a test program in C.
 */ 

package SerialTest;

public class SerialClient extends xerox.ilu.IluServiceThread {
    
    static xerox.ilu.IluPipeline pl = null;
    static SerialTest.T t = null;
    static boolean pipeit = false;
    
    boolean verbose = false;
    boolean ismain = false;
    String argv[] = null;
    Inst inst;
    

    SerialClient(boolean ismain, String argv[], Inst inst) {
       this.ismain = ismain;
       this.argv = argv;
       this.inst = inst;
    } //constructor
    
    public static void usage() {
        System.err.println(
                "usage: java SerialTest.SerialClient number number [v]");
        System.exit(1);
    } //usage
    
    public static void main(String argv[]) {
        SerialClient pbc = null;
        pbc = new SerialClient(true, argv, null);
        pbc.start();
        try {
            pbc.join();
        } catch (java.lang.InterruptedException ie) {
            System.err.println("InterruptedException caught by main: " + ie);
        }
        System.out.println("main is done");
    } //main
    
    public void run() {
        if ( ismain ) {
            mainThread();
        } else {
            doWaitAndCall();
        }
    } //run
    
    public void sched() {
        SerialClient subClient = 
            new SerialClient(false, argv, inst);
        subClient.start();
    } //sched
    
    public void doWaitAndCall() {
        long now = System.currentTimeMillis();
        try {
            int x = inst.seed;
            inst.seed = (inst.seed * 101) % 1013;
            Thread.sleep(1000 * x / 50);
        } catch (java.lang.InterruptedException ie) {
            System.err.println(
                "InterruptedException caught by doWaitAndCall: " + ie
                );
        }
        doCall();
    }
    
    public void doCall() {
        try {
            System.out.println(
                "Calling M(" + inst.i + ", " + inst.n + ") at " 
                + System.currentTimeMillis()
                );
            xerox.ilu.IluSerializationContext.
                setCurrentSerializationContext(inst.si);
            try {
                t.M(inst.i, inst.n);
            } catch (xerox.ilu.IluSystemException e0) {
                System.err.println("IluSystemException caught by t.M" + e0);
                System.err.println("continue...");
            } 
            inst.n--;
            if (inst.n>0) {
                sched();
            }
        } catch (xerox.ilu.IluSystemException e) {
            System.err.println("IluSystemException caught by doCall: " + e);
            e.printStackTrace();
        }
    } //doCall
    
    public void mainThread() {
        String serverId = "SerialTest-Server";
        String ih = "it";
        int i;
        if (argv.length < 2) {
            usage();
        }
        System.out.println("Starting SerialClient");
        String nsersString = argv[0];
        int nsers = Integer.valueOf(nsersString).intValue();
        String nperString = argv[1];
        int nper = Integer.valueOf(nperString).intValue();
        if (argv.length > 2) {
            if (argv[2].indexOf('v')>=0) verbose = true;
            if (argv[2].indexOf('V')>=0) verbose = true;
        }
        System.out.println("SerialTest");
        SerialTest._allJavaStubs.load();
        try {
            t = (SerialTest.T) xerox.ilu.IluSimpleBinding.lookup(
                serverId, ih, SerialTest.TStub.iluClass()
                );
            t.Prep(nsers, nper);
            for (i = 0; i < nsers; i++) {
                Inst inst = new Inst();
                inst.i = i;
                inst.n = nper;
                inst.si = xerox.ilu.IluSerializationContext.alloc(t);
                inst.seed = (int) (System.currentTimeMillis() % 1013);
                SerialClient subClient = 
                    new SerialClient(false, argv, inst);
                
                subClient.start();
                Thread.sleep(1000);
            } //for-i
        } catch (java.lang.InterruptedException e) {
            System.err.println("java.lang.InterruptedException");
            e.printStackTrace();
        } catch (xerox.ilu.IluSystemException e) {
            System.err.println("IluSystemException caught by mainThread: " + e);
            e.printStackTrace();
        }
        System.out.println("mainThread will return");
    } //mainThread
    
} //SerialClient


class Inst {
    public int i = 0;
    public int n = 0;
    public int seed = 0;
    public xerox.ilu.IluSerializationContext si = null;
} //Inst
