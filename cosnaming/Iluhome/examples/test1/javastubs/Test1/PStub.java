// javastubs/Test1/PStub.java
// Stubs for "Test1"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:19 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test1;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class PStub extends xerox.ilu.IluSurrogateObject implements P {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _m2_methodRep;
    static private _P_skeletonClass _P_skeleton = new _P_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    xerox.ilu.IluClassRep[] ca = new xerox.ilu.IluClassRep[1];
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test1.P", //java reference interface name
            "Test1.P", //ilu object type name
            "ilut:dY9O+Pbe716S3dZTXTUzbvfKs87", //uuid
            1); //method count
        ca[0] = O3Stub.iluClass();
        _classRep.setSuperClasses(ca);
        _classRep.setSurrClass("Test1.PStub");
        _classRep.setIfName("Test1"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering P: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _m2_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "m2", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO", //return arg uuid
        _P_skeleton);
     _m2_methodRep.defineArg(
         0, //argIdx
         "j", //argName
         false, //sibling
         0, //direction
         "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"); //typeUid

    try {
        _classRep.finishClass();
        PHelper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering P: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public int[] m2(int j) {
        return _m2_S(this, j);
    } //m2

    public static int[] _m2_S(P self, int j) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        int[] _r = null;
        _call = xerox.ilu.IluCall.startCall(
            PStub._m2_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, PStub._classRep)
                + _call.szInt32(j)
                ) : 0);
            _call.outObject(self, true, PStub._classRep);
            _call.outInt32(j);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = IS._inFunc(_call);
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            }
            _call.doneReadReply();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
        if (_ec != 0) {
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
        return _r;
    } //_m2_S

    public int[] RS_R_to_R_IS(TheR[] r, TheRHolder r2) {
        return O3Stub._RS_R_to_R_IS_S(this, r, r2);
    } //RS_R_to_R_IS

    public void O1_U_to_U(TheO1 o, TheUHolder u)
        throws E2 {
        O3Stub._O1_U_to_U_S(this, o, u);
    } //O1_U_to_U

    public int BS_to_I(byte[] b) {
        return O3Stub._BS_to_I_S(this, b);
    } //BS_to_I

    public static void registerTrueObject(
        java.lang.String _ih,
        P _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public PStub() {
    }
    /** ilu use only */
    public PStub(java.lang.Object arg) {
    }
    static {
        Test1._allJavaStubs.load();
    }
} //PStub

class _P_skeletonClass implements xerox.ilu.IluSkeleton {
    _P_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //m2
        {
          int[] _r = null;
          P _sob;
          _call.startReadRequest();
          _sob = (P)
              _call.inObject(true, PStub._classRep);
          int j = _call.inInt32();
          _call.doneReadRequest();
          try {
            _r = _sob.m2(j);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += IS._szFunc(_call, _r);
          }
          _call.startWriteReply(_sz);
          IS._outFunc(_call, _r);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_P_skeletonClass

