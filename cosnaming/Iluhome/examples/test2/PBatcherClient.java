/* $Id: PBatcherClient.java,v 1.4 2025/08/01 09:14:00 cvswxc Exp $ */


/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */


/*
 * Run this like
 * java Batcher.PBatcherClient 3 vp
 */ 

package Batcher;

public class PBatcherClient extends xerox.ilu.IluServiceThread {
    
    static xerox.ilu.IluPipeline pl = null;
    static Batcher.T t = null;
    static boolean pipeit = false;
    
    boolean verbose = false;
    boolean ismain = false;
    String argv[] = null;
    int idx = 0;

    PBatcherClient(boolean ismain, String argv[], int idx) {
       this.ismain = ismain;
       this.argv = argv;
       this.idx = idx;
    } //constructor
    
    public static void usage() {
        System.err.println(
                "usage: java Batcher.PBatcherClient number [v]");
        System.exit(1);
    } //usage
    
    public static void main(String argv[]) {
        PBatcherClient pbc = null;
        pbc = new PBatcherClient(true, argv, -1);
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
            subThread();
        }
    } //run
    
    public void subThread() {
        try {
            Batcher.TimeRec[] ans;
            long now = System.currentTimeMillis();
            if (verbose) {
                System.out.println("Calling Sync_ " + now);
            }
            if (pipeit) xerox.ilu.IluPipeline.setCurrentPipeline(pl);
            ans = t.Sync(now);
            if (pipeit) xerox.ilu.IluPipeline.setCurrentPipeline(null);
                //no try finally because the thread is done anyway..
            System.out.println("Sync_(" + this.idx + ")" );
            for (int k = 0; k < ans.length; k++) {
                System.out.println(" " + ans[k].s + "->" + ans[k].r);
            } //for-k
            System.out.println();
        } catch (xerox.ilu.IluSystemException e) {
            System.err.println("IluSystemException caught by subThread: " + e);
            e.printStackTrace();
        }
    } //subThread
    
    public void mainThread() {
        String serverId = "Batcher-Server";
        String ih = "it";
        int i;
        if (argv.length < 1) {
            usage();
        }
        System.out.println("Starting PBatcherClient");
        String nsyncsString = argv[0];
        int nsyncs = Integer.valueOf(nsyncsString).intValue();
        if (argv.length > 1) {
            if (argv[1].indexOf('v')>=0) verbose = true;
            if (argv[1].indexOf('V')>=0) verbose = true;
            if (argv[1].indexOf('p')>=0) pipeit = true;
            if (argv[1].indexOf('P')>=0) pipeit = true;
        }
        System.out.println("Pipeline: " + pipeit);
        Batcher._allJavaStubs.load();
        try {
            t = (T) xerox.ilu.IluSimpleBinding.lookup(
                serverId, ih, Batcher.TStub.iluClass()
                );
            if (pipeit) {
                pl = xerox.ilu.IluPipeline.alloc();
            }
            for (i = 0; i < nsyncs; i++) {
                PBatcherClient subClient = 
                    new PBatcherClient(false, argv, i);
                subClient.start();
            } //for-i
        } catch (xerox.ilu.IluSystemException e) {
            System.err.println("IluSystemException caught by mainThread: " + e);
            e.printStackTrace();
        }
        System.out.println("mainThread will return");
    } //mainThread
    
} //PBatcherClient

