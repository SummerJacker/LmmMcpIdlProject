// javastubs/Test1/O3Stub.java
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
public class O3Stub extends xerox.ilu.IluSurrogateObject implements O3 {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _RS_R_to_R_IS_methodRep;
    static xerox.ilu.IluMethodRep _O1_U_to_U_methodRep;
    static xerox.ilu.IluMethodRep _BS_to_I_methodRep;
    static private xerox.ilu.IluExceptionRep[] _xArr = null;
    static private _O3_skeletonClass _O3_skeleton = new _O3_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test1.O3", //java reference interface name
            "Test1.O3", //ilu object type name
            "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU", //uuid
            3); //method count
        _classRep.setCollectable();
        _classRep.setBrand("v1");
        _classRep.setSurrClass("Test1.O3Stub");
        _classRep.setIfName("Test1"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O3: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _RS_R_to_R_IS_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "RS-R-to-R-IS", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        2, //no of args
        "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO", //return arg uuid
        _O3_skeleton);
     _RS_R_to_R_IS_methodRep.defineArg(
         0, //argIdx
         "r", //argName
         false, //sibling
         0, //direction
         "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac"); //typeUid
     _RS_R_to_R_IS_methodRep.defineArg(
         1, //argIdx
         "r2", //argName
         false, //sibling
         1, //direction
         "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"); //typeUid

    _xArr = new xerox.ilu.IluExceptionRep[1];
    _xArr[0] = E2_exh_._E2getRep();
    _O1_U_to_U_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        1, //local idx
        "O1-U-to-U", //name (in isl domain)
        2, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        2, //no of args
        null, //return arg uuid
        _O3_skeleton);
     _O1_U_to_U_methodRep.defineArg(
         0, //argIdx
         "o", //argName
         true, //sibling
         0, //direction
         "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"); //typeUid
     _O1_U_to_U_methodRep.defineArg(
         1, //argIdx
         "u", //argName
         false, //sibling
         2, //direction
         "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"); //typeUid

    _BS_to_I_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        2, //local idx
        "BS-to-I", //name (in isl domain)
        3, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", //return arg uuid
        _O3_skeleton);
     _BS_to_I_methodRep.defineArg(
         0, //argIdx
         "b", //argName
         false, //sibling
         0, //direction
         "ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3"); //typeUid

    try {
        _classRep.finishClass();
        O3Helper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O3: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public int[] RS_R_to_R_IS(TheR[] r, TheRHolder r2) {
        return _RS_R_to_R_IS_S(this, r, r2);
    } //RS_R_to_R_IS

    public static int[] _RS_R_to_R_IS_S(O3 self, TheR[] r, TheRHolder r2) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        int[] _r = null;
        _call = xerox.ilu.IluCall.startCall(
            O3Stub._RS_R_to_R_IS_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, O3Stub._classRep)
                + TheRS._szFunc(_call, r)
                ) : 0);
            _call.outObject(self, true, O3Stub._classRep);
            TheRS._outFunc(_call, r);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = IS._inFunc(_call);
                r2.value = TheRHelper._inFunc(_call);
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
    } //_RS_R_to_R_IS_S

    public void O1_U_to_U(TheO1 o, TheUHolder u)
        throws E2 {
        _O1_U_to_U_S(this, o, u);
    } //O1_U_to_U

    public static void _O1_U_to_U_S(O3 self, TheO1 o, TheUHolder u)
        throws E2 {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        _call = xerox.ilu.IluCall.startCall(
            O3Stub._O1_U_to_U_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, O3Stub._classRep)
                + _call.szObject(o, false, TheO1Stub.iluClass())
                + TheUHelper._szFunc(_call, u.value)
                ) : 0);
            _call.outObject(self, true, O3Stub._classRep);
            _call.checkSibling(o, TheO1Stub.iluClass());
            _call.outObject(o, false, TheO1Stub.iluClass());
            TheUHelper._outFunc(_call, u.value);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                u.value = TheUHelper._inFunc(_call);
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(O3Stub._O1_U_to_U_methodRep, _ec);
            }
            _call.doneReadReply();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
        if (_ec != 0) {
            switch (_ec) {
              case 1: throw (E2) _userException;
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
    } //_O1_U_to_U_S

    public int BS_to_I(byte[] b) {
        return _BS_to_I_S(this, b);
    } //BS_to_I

    public static int _BS_to_I_S(O3 self, byte[] b) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        int _r = 0;
        _call = xerox.ilu.IluCall.startCall(
            O3Stub._BS_to_I_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, O3Stub._classRep)
                + _call.szBytesS(b, 0)
                ) : 0);
            _call.outObject(self, true, O3Stub._classRep);
            _call.outBytesS(b, 0);
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
    } //_BS_to_I_S

    public static void registerTrueObject(
        java.lang.String _ih,
        O3 _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public O3Stub() {
    }
    /** ilu use only */
    public O3Stub(java.lang.Object arg) {
    }
    static {
        Test1._allJavaStubs.load();
    }
} //O3Stub

class _O3_skeletonClass implements xerox.ilu.IluSkeleton {
    _O3_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //RS_R_to_R_IS
        {
          int[] _r = null;
          O3 _sob;
          _call.startReadRequest();
          _sob = (O3)
              _call.inObject(true, O3Stub._classRep);
          TheR[] r = TheRS._inFunc(_call);
          TheRHolder r2 = new TheRHolder();
          _call.doneReadRequest();
          try {
            _r = _sob.RS_R_to_R_IS(r, r2);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += IS._szFunc(_call, _r);
            _sz += TheRHelper._szFunc(_call, r2.value);
          }
          _call.startWriteReply(_sz);
          IS._outFunc(_call, _r);
          TheRHelper._outFunc(_call, r2.value);
          _call.doneWriteReply();
        }
        break;
      case 1: //O1_U_to_U
        {
          O3 _sob;
          _call.startReadRequest();
          _sob = (O3)
              _call.inObject(true, O3Stub._classRep);
          TheO1 o = (TheO1) _call.inObject(false, TheO1Stub.iluClass());
          TheUHolder u = new TheUHolder();
          u.value = TheUHelper._inFunc(_call);
          _call.doneReadRequest();
          try {
            _sob.O1_U_to_U(o, u);
          } catch (E2 _e) {
            Test1.E2_exh_._E2_marshall(_e, 1, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += TheUHelper._szFunc(_call, u.value);
          }
          _call.startWriteReply(_sz);
          TheUHelper._outFunc(_call, u.value);
          _call.doneWriteReply();
        }
        break;
      case 2: //BS_to_I
        {
          int _r = 0;
          O3 _sob;
          _call.startReadRequest();
          _sob = (O3)
              _call.inObject(true, O3Stub._classRep);
          byte[] b = _call.inBytesS(0);
          _call.doneReadRequest();
          try {
            _r = _sob.BS_to_I(b);
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

} //_O3_skeletonClass

