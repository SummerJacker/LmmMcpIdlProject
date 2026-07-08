// javastubs/Test1/O5Stub.java
// Stubs for "Test1"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:39 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/pickle//Test1.isl" of Fri Aug 01 14:00:48 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/pickle//ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test1;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class O5Stub extends xerox.ilu.IluSurrogateObject implements O5 {

    static xerox.ilu.IluClassRep _classRep;
    static private _O5_skeletonClass _O5_skeleton = new _O5_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    xerox.ilu.IluClassRep[] ca = new xerox.ilu.IluClassRep[1];
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test1.O5", //java reference interface name
            "Test1.O5", //ilu object type name
            "IDL:Test1/O5:1.0", //uuid
            0); //method count
        ca[0] = xerox.ilu.CORBA_ObjectStub.iluClass();
        _classRep.setSuperClasses(ca);
        _classRep.setOptional();
        _classRep.setSurrClass("Test1.O5Stub");
        _classRep.setIfName("Test1"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O5: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    try {
        _classRep.finishClass();
        O5Helper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O5: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public static void registerTrueObject(
        java.lang.String _ih,
        O5 _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public O5Stub() {
    }
    /** ilu use only */
    public O5Stub(java.lang.Object arg) {
    }
    static {
        Test1._allJavaStubs.load();
    }
} //O5Stub

class _O5_skeletonClass implements xerox.ilu.IluSkeleton {
    _O5_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      default:
    }
  } //serveRequest

} //_O5_skeletonClass

