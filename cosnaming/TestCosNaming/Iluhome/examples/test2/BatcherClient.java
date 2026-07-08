/* $Id: BatcherClient.java,v 1.4 2025/08/01 09:11:53 cvswxc Exp $ */

/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */
/* THIS HAS NOT BEEN TESTED */

/*
 * Run this like
 * java Batcher.BatcherClient 3 3 v
 */ 

package Batcher;

public class BatcherClient {
    
    static boolean verbose = false;
    
    public static void usage() {
        System.err.println(
                "usage: java Batcher.BatcherClient number number [v]");
        System.exit(1);
    }
    
    public static void main(String argv[]) {
        if (argv.length < 2) {
            usage();
        }
        if (argv.length > 2) {
            if (argv[2].indexOf('v')>=0) verbose = true;
            if (argv[2].indexOf('V')>=0) verbose = true;
        }
        int i;
        int j;
        int k;
        long now;
        Batcher.T t;
        Batcher.TimeRec[] ans;
        String serverId = "Batcher-Server";
        String ih = "it";
        String nsendsString = argv[0];
        String nsyncsString = argv[1];
        int nsends = Integer.valueOf(nsendsString).intValue();
        int nsyncs = Integer.valueOf(nsyncsString).intValue();
        System.out.println("Starting BatcherClient");
        Batcher._allJavaStubs.load();
        try {
            t = (T) xerox.ilu.IluSimpleBinding.lookup(
                serverId, ih, Batcher.TStub.iluClass()
                );
            for (i = 0; i < nsyncs; i++) {
                for (j = 0; j < nsyncs; j++) {
                    now = System.currentTimeMillis();
                    if (verbose) {
                        System.out.println("Sending " + now);
                        }
                    t.Send(now);
                    try {
                        Thread.sleep(1000);
                    } catch(java.lang.InterruptedException ie) {
                    }
                } //for-j
                now = System.currentTimeMillis();
                if (verbose) {
                    System.out.println("Syncing " + now);
                }
                ans = t.Sync(now);
                System.out.println("Ans(" + i + ") = " + ans.length);
                for (k = 0; k < ans.length; k++) {
                    System.out.println(" " + ans[k].s + "->" + ans[k].r);
                } //for-k
                System.out.println();
            } //for-i
        } catch (xerox.ilu.IluSystemException e) {
            System.err.println("IluSystemException caught by main: " + e);
        }
        System.out.println("done");
    } //main
    
} //BatcherClient

