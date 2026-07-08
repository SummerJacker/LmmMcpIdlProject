// javastubs/Test2/PStub.java
// Stubs for "Test2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test2;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class PStub extends xerox.ilu.IluSurrogateObject implements P {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _SR_to_I_methodRep;
    static private _P_skeletonClass _P_skeleton = new _P_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test2.P", //java reference interface name
            "Test2.P", //ilu object type name
            "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS", //uuid
            1); //method count
        _classRep.setSurrClass("Test2.PStub");
        _classRep.setIfName("Test2"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering P: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _SR_to_I_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "SR-to-I", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", //return arg uuid
        _P_skeleton);
     _SR_to_I_methodRep.defineArg(
         0, //argIdx
         "i", //argName
         false, //sibling
         0, //direction
         "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO"); //typeUid

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

    public int SR_to_I(float i) {
        return _SR_to_I_S(this, i);
    } //SR_to_I

    public static int _SR_to_I_S(P self, float i) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        int _r = 0;
        _call = xerox.ilu.IluCall.startCall(
            PStub._SR_to_I_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, PStub._classRep)
                + _call.szReal32(i)
                ) : 0);
            _call.outObject(self, true, PStub._classRep);
            _call.outReal32(i);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = _call.inInt32();
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
    } //_SR_to_I_S

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
        Test2._allJavaStubs.load();
    }
} //PStub

class _P_skeletonClass implements xerox.ilu.IluSkeleton {
    _P_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //SR_to_I
        {
          int _r = 0;
          P _sob;
          _call.startReadRequest();
          _sob = (P)
              _call.inObject(true, PStub._classRep);
          float i = _call.inReal32();
          _call.doneReadRequest();
          try {
            _r = _sob.SR_to_I(i);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szInt32(_r);
          }
          _call.startWriteReply(_sz);
          _call.outInt32(_r);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_P_skeletonClass

