// javastubs/Test1/O2Stub.java
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
 * sample multi-line
 *     doc string with leading whitespace on the second line
 * A stub class implementing surrogates for an ILU object type.
 */
public class O2Stub extends xerox.ilu.IluSurrogateObject implements O2 {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _OO_A0_to_CSS_methodRep;
    static xerox.ilu.IluMethodRep _R_I_A1_to_I_A0_methodRep;
    static private xerox.ilu.IluExceptionRep[] _xArr = null;
    static private _O2_skeletonClass _O2_skeleton = new _O2_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test1.O2", //java reference interface name
            "Test1.O2", //ilu object type name
            "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", //uuid
            2); //method count
        _classRep.setSingleton("sunrpc_2_0x3458_3");
        _classRep.setDocString("sample multi-line\n    doc string with leading whitespace on the second line");
        _classRep.setSurrClass("Test1.O2Stub");
        _classRep.setIfName("Test1"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O2: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _xArr = new xerox.ilu.IluExceptionRep[1];
    _xArr[0] = E2_exh_._E2getRep();
    _OO_A0_to_CSS_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "OO-A0-to-CSS", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        2, //no of args
        "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", //return arg uuid
        _O2_skeleton);
     _OO_A0_to_CSS_methodRep.defineArg(
         0, //argIdx
         "o", //argName
         false, //sibling
         0, //direction
         "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA"); //typeUid
     _OO_A0_to_CSS_methodRep.defineArg(
         1, //argIdx
         "a", //argName
         false, //sibling
         0, //direction
         "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r"); //typeUid

    _R_I_A1_to_I_A0_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        1, //local idx
        "R-I-A1-to-I-A0", //name (in isl domain)
        2, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        3, //no of args
        "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r", //return arg uuid
        _O2_skeleton);
     _R_I_A1_to_I_A0_methodRep.defineArg(
         0, //argIdx
         "r", //argName
         false, //sibling
         0, //direction
         "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"); //typeUid
     _R_I_A1_to_I_A0_methodRep.defineArg(
         1, //argIdx
         "i", //argName
         false, //sibling
         2, //direction
         "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"); //typeUid
     _R_I_A1_to_I_A0_methodRep.defineArg(
         2, //argIdx
         "a", //argName
         false, //sibling
         0, //direction
         "ilut:h3Dnvis94UwnmFURfYsCp700jVy"); //typeUid

    try {
        _classRep.finishClass();
        O2Helper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering O2: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public java.lang.String[] OO_A0_to_CSS(TheO1 o, byte[] a)
        throws E2 {
        return _OO_A0_to_CSS_S(this, o, a);
    } //OO_A0_to_CSS

    public static java.lang.String[] _OO_A0_to_CSS_S(O2 self, TheO1 o, byte[] a)
        throws E2 {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        java.lang.String[] _r = null;
        _call = xerox.ilu.IluCall.startCall(
            O2Stub._OO_A0_to_CSS_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  0
                + TheOOStub._szFunc(_call, o)
                + _call.szBytesA(a, 8)
                ) : 0);
            TheOOStub._outFunc(_call, o);
            _call.outBytesA(a, 8);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = CSS._inFunc(_call);
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(O2Stub._OO_A0_to_CSS_methodRep, _ec);
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
        return _r;
    } //_OO_A0_to_CSS_S

    public byte[] R_I_A1_to_I_A0(TheR r, org.omg.CORBA.IntHolder i, java.lang.String[] a) {
        return _R_I_A1_to_I_A0_S(this, r, i, a);
    } //R_I_A1_to_I_A0

    public static byte[] _R_I_A1_to_I_A0_S(O2 self, TheR r, org.omg.CORBA.IntHolder i, java.lang.String[] a) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        byte[] _r = null;
        _call = xerox.ilu.IluCall.startCall(
            O2Stub._R_I_A1_to_I_A0_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  0
                + TheRHelper._szFunc(_call, r)
                + _call.szInt32(i.value)
                + TheA1.szFunc(_call, a)
                ) : 0);
            TheRHelper._outFunc(_call, r);
            _call.outInt32(i.value);
            TheA1.outFunc(_call, a);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = _call.inBytesA(8);
                i.value = _call.inInt32();
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
    } //_R_I_A1_to_I_A0_S

    public static void registerTrueObject(
        java.lang.String _ih,
        O2 _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public O2Stub() {
    }
    /** ilu use only */
    public O2Stub(java.lang.Object arg) {
    }
    static {
        Test1._allJavaStubs.load();
    }
} //O2Stub

class _O2_skeletonClass implements xerox.ilu.IluSkeleton {
    _O2_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //OO_A0_to_CSS
        {
          java.lang.String[] _r = null;
          O2 _sob;
          _call.startReadRequest();
          _sob = (O2)
              _call.getCallSingleton();
          TheO1 o = TheOOStub._inFunc(_call);
          byte[] a = _call.inBytesA(8);
          _call.doneReadRequest();
          try {
            _r = _sob.OO_A0_to_CSS(o, a);
          } catch (E2 _e) {
            Test1.E2_exh_._E2_marshall(_e, 1, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += CSS._szFunc(_call, _r);
          }
          _call.startWriteReply(_sz);
          CSS._outFunc(_call, _r);
          _call.doneWriteReply();
        }
        break;
      case 1: //R_I_A1_to_I_A0
        {
          byte[] _r = null;
          O2 _sob;
          _call.startReadRequest();
          _sob = (O2)
              _call.getCallSingleton();
          TheR r = TheRHelper._inFunc(_call);
          org.omg.CORBA.IntHolder i = new org.omg.CORBA.IntHolder();
          i.value = _call.inInt32();
          java.lang.String[] a = TheA1.inFunc(_call);
          _call.doneReadRequest();
          try {
            _r = _sob.R_I_A1_to_I_A0(r, i, a);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szBytesA(_r, 8);
            _sz += _call.szInt32(i.value);
          }
          _call.startWriteReply(_sz);
          _call.outBytesA(_r, 8);
          _call.outInt32(i.value);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_O2_skeletonClass

