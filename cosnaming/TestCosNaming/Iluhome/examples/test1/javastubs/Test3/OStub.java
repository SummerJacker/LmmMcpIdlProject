// javastubs/Test3/OStub.java
// Stubs for "Test3"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test3;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class OStub extends xerox.ilu.IluSurrogateObject implements O {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _I_to_Test1U_methodRep;
    static private xerox.ilu.IluExceptionRep[] _xArr = null;
    static private _O_skeletonClass _O_skeleton = new _O_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    xerox.ilu.IluClassRep[] ca = new xerox.ilu.IluClassRep[2];
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test3.O", //java reference interface name
            "Test3.O", //ilu object type name
            "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg", //uuid
            1); //method count
        ca[0] = Test1.O3Stub.iluClass();
        ca[1] = Test2.PStub.iluClass();
        _classRep.setSuperClasses(ca);
        _classRep.setSurrClass("Test3.OStub");
        _classRep.setIfName("Test3"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _xArr = new xerox.ilu.IluExceptionRep[2];
    _xArr[0] = E1_exh_._E1getRep();
    _xArr[1] = Test1.E1_exh_._E1getRep();
    _I_to_Test1U_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "I-to-Test1U", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        1, //no of args
        "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", //return arg uuid
        _O_skeleton);
     _I_to_Test1U_methodRep.defineArg(
         0, //argIdx
         "i", //argName
         false, //sibling
         0, //direction
         "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"); //typeUid

    try {
        _classRep.finishClass();
        OHelper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public Test1.TheU I_to_Test1U(int i)
        throws E1, Test1.E1 {
        return _I_to_Test1U_S(this, i);
    } //I_to_Test1U

    public static Test1.TheU _I_to_Test1U_S(O self, int i)
        throws E1, Test1.E1 {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        Test1.TheU _r = null;
        _call = xerox.ilu.IluCall.startCall(
            OStub._I_to_Test1U_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, OStub._classRep)
                + _call.szInt32(i)
                ) : 0);
            _call.outObject(self, true, OStub._classRep);
            _call.outInt32(i);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = Test1.TheUHelper._inFunc(_call);
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(OStub._I_to_Test1U_methodRep, _ec);
            }
            _call.doneReadReply();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
        if (_ec != 0) {
            switch (_ec) {
              case 1: throw (E1) _userException;
              case 2: throw (Test1.E1) _userException;
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
        return _r;
    } //_I_to_Test1U_S

    public int[] RS_R_to_R_IS(Test1.TheR[] r, Test1.TheRHolder r2) {
        return Test1.O3Stub._RS_R_to_R_IS_S(this, r, r2);
    } //RS_R_to_R_IS

    public void O1_U_to_U(Test1.TheO1 o, Test1.TheUHolder u)
        throws Test1.E2 {
        Test1.O3Stub._O1_U_to_U_S(this, o, u);
    } //O1_U_to_U

    public int BS_to_I(byte[] b) {
        return Test1.O3Stub._BS_to_I_S(this, b);
    } //BS_to_I

    public int SR_to_I(float i) {
        return Test2.PStub._SR_to_I_S(this, i);
    } //SR_to_I

    public static void registerTrueObject(
        java.lang.String _ih,
        O _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public OStub() {
    }
    /** ilu use only */
    public OStub(java.lang.Object arg) {
    }
    static {
        Test3._allJavaStubs.load();
    }
} //OStub

class _O_skeletonClass implements xerox.ilu.IluSkeleton {
    _O_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //I_to_Test1U
        {
          Test1.TheU _r = null;
          O _sob;
          _call.startReadRequest();
          _sob = (O)
              _call.inObject(true, OStub._classRep);
          int i = _call.inInt32();
          _call.doneReadRequest();
          try {
            _r = _sob.I_to_Test1U(i);
          } catch (E1 _e) {
            Test3.E1_exh_._E1_marshall(_e, 1, _call);
            return;
          } catch (Test1.E1 _e) {
            Test1.E1_exh_._E1_marshall(_e, 2, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += Test1.TheUHelper._szFunc(_call, _r);
          }
          _call.startWriteReply(_sz);
          Test1.TheUHelper._outFunc(_call, _r);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_O_skeletonClass

