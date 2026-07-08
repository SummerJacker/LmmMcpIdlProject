// javastubs/Test1/O4Stub.java
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
public class O4Stub extends xerox.ilu.IluSurrogateObject implements O4 {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _R_to_R_methodRep;
    static private _O4_skeletonClass _O4_skeleton = new _O4_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    xerox.ilu.IluClassRep[] ca = new xerox.ilu.IluClassRep[1];
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test1.O4", //java reference interface name
            "Test1.O4", //ilu object type name
            "ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ", //uuid
            1); //method count
        ca[0] = O3Stub.iluClass();
        _classRep.setSuperClasses(ca);
        _classRep.setSurrClass("Test1.O4Stub");
        _classRep.setIfName("Test1"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O4: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _R_to_R_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "R-to-R", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", //return arg uuid
        _O4_skeleton);
     _R_to_R_methodRep.defineArg(
         0, //argIdx
         "r", //argName
         false, //sibling
         0, //direction
         "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"); //typeUid

    try {
        _classRep.finishClass();
        O4Helper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O4: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public double R_to_R(double r) {
        return _R_to_R_S(this, r);
    } //R_to_R

    public static double _R_to_R_S(O4 self, double r) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        double _r = 0D;
        _call = xerox.ilu.IluCall.startCall(
            O4Stub._R_to_R_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, O4Stub._classRep)
                + _call.szReal64(r)
                ) : 0);
            _call.outObject(self, true, O4Stub._classRep);
            _call.outReal64(r);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = _call.inReal64();
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
    } //_R_to_R_S

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
        O4 _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public O4Stub() {
    }
    /** ilu use only */
    public O4Stub(java.lang.Object arg) {
    }
    static {
        Test1._allJavaStubs.load();
    }
} //O4Stub

class _O4_skeletonClass implements xerox.ilu.IluSkeleton {
    _O4_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //R_to_R
        {
          double _r = 0D;
          O4 _sob;
          _call.startReadRequest();
          _sob = (O4)
              _call.inObject(true, O4Stub._classRep);
          double r = _call.inReal64();
          _call.doneReadRequest();
          try {
            _r = _sob.R_to_R(r);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szReal64(_r);
          }
          _call.startWriteReply(_sz);
          _call.outReal64(_r);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_O4_skeletonClass

