// javastubs/Test2/O1Stub.java
// Stubs for "Test2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:39 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/pickle//Test2.isl" of Tue Sep 21 06:54:01 1999,
// and "D:/Shaun-projects/newstar/Iluhome/examples/pickle//ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test2;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class O1Stub extends xerox.ilu.IluSurrogateObject implements O1 {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _bounce_methodRep;
    static private _O1_skeletonClass _O1_skeleton = new _O1_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    xerox.ilu.IluClassRep[] ca = new xerox.ilu.IluClassRep[1];
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test2.O1", //java reference interface name
            "Test2.O1", //ilu object type name
            "IDL:Test2/O1:1.0", //uuid
            1); //method count
        ca[0] = xerox.ilu.CORBA_ObjectStub.iluClass();
        _classRep.setSuperClasses(ca);
        _classRep.setOptional();
        _classRep.setSurrClass("Test2.O1Stub");
        _classRep.setIfName("Test2"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O1: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _bounce_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "bounce", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco", //return arg uuid
        _O1_skeleton);
     _bounce_methodRep.defineArg(
         0, //argIdx
         "v", //argName
         false, //sibling
         0, //direction
         "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco"); //typeUid

    try {
        _classRep.finishClass();
        O1Helper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O1: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public xerox.ilu.IluAny bounce(xerox.ilu.IluAny v) {
        return _bounce_S(this, v);
    } //bounce

    public static xerox.ilu.IluAny _bounce_S(O1 self, xerox.ilu.IluAny v) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        xerox.ilu.IluAny _r = null;
        _call = xerox.ilu.IluCall.startCall(
            O1Stub._bounce_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, O1Stub._classRep)
                + v._szAny(_call)
                ) : 0);
            _call.outObject(self, true, O1Stub._classRep);
            v._outAny(_call);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = xerox.ilu.IluAny._inAny(_call);
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
    } //_bounce_S

    public static void registerTrueObject(
        java.lang.String _ih,
        O1 _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public O1Stub() {
    }
    /** ilu use only */
    public O1Stub(java.lang.Object arg) {
    }
    static {
        Test2._allJavaStubs.load();
    }
} //O1Stub

class _O1_skeletonClass implements xerox.ilu.IluSkeleton {
    _O1_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //bounce
        {
          xerox.ilu.IluAny _r = null;
          O1 _sob;
          _call.startReadRequest();
          _sob = (O1)
              _call.inObject(true, O1Stub._classRep);
          xerox.ilu.IluAny v = xerox.ilu.IluAny._inAny(_call);
          _call.doneReadRequest();
          try {
            _r = _sob.bounce(v);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _r._szAny(_call);
          }
          _call.startWriteReply(_sz);
          _r._outAny(_call);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_O1_skeletonClass

