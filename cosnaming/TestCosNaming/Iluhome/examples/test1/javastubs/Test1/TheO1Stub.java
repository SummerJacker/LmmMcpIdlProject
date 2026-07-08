// javastubs/Test1/TheO1Stub.java
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
 * sample
 * multi-line doc string
 * A stub class implementing surrogates for an ILU object type.
 */
public class TheO1Stub extends xerox.ilu.IluSurrogateObject implements TheO1 {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _U_CSS_to_U_methodRep;
    static xerox.ilu.IluMethodRep _f_CSS_to_RO_methodRep;
    static xerox.ilu.IluMethodRep _R_ScS_to_F_methodRep;
    static xerox.ilu.IluMethodRep _a_RO_methodRep;
    static xerox.ilu.IluMethodRep _get_O2_methodRep;
    static xerox.ilu.IluMethodRep _get_O3_methodRep;
    static private xerox.ilu.IluExceptionRep[] _xArr = null;
    static private _TheO1_skeletonClass _TheO1_skeleton = new _TheO1_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Test1.TheO1", //java reference interface name
            "Test1.TheO1", //ilu object type name
            "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", //uuid
            6); //method count
        _classRep.setDocString("sample\nmulti-line doc string");
        _classRep.setSurrClass("Test1.TheO1Stub");
        _classRep.setIfName("Test1"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering TheO1: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _xArr = new xerox.ilu.IluExceptionRep[2];
    _xArr[0] = E1_exh_._E1getRep();
    _xArr[1] = E2_exh_._E2getRep();
    _U_CSS_to_U_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "U-CSS-to-U", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        2, //no of args
        "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", //return arg uuid
        _TheO1_skeleton);
     _U_CSS_to_U_methodRep.defineArg(
         0, //argIdx
         "u", //argName
         false, //sibling
         0, //direction
         "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"); //typeUid
     _U_CSS_to_U_methodRep.defineArg(
         1, //argIdx
         "css", //argName
         false, //sibling
         0, //direction
         "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy"); //typeUid

    _xArr = new xerox.ilu.IluExceptionRep[1];
    _xArr[0] = E1_exh_._E1getRep();
    _f_CSS_to_RO_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        1, //local idx
        "f-CSS-to-RO", //name (in isl domain)
        2, //remote id
        true, //functional
        false, //asynch
        _xArr, //exceptions
        1, //no of args
        "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", //return arg uuid
        _TheO1_skeleton);
     _f_CSS_to_RO_methodRep.defineArg(
         0, //argIdx
         "css", //argName
         false, //sibling
         0, //direction
         "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy"); //typeUid

    _R_ScS_to_F_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        2, //local idx
        "R-ScS-to-F", //name (in isl domain)
        3, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        2, //no of args
        "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", //return arg uuid
        _TheO1_skeleton);
     _R_ScS_to_F_methodRep.defineArg(
         0, //argIdx
         "r", //argName
         false, //sibling
         0, //direction
         "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7"); //typeUid
     _R_ScS_to_F_methodRep.defineArg(
         1, //argIdx
         "s", //argName
         false, //sibling
         0, //direction
         "ilut:iqqhSf395+BafbY8Oo2elFQD1bK"); //typeUid

    _a_RO_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        3, //local idx
        "a-RO", //name (in isl domain)
        4, //remote id
        false, //functional
        true, //asynch
        null, //exceptions
        1, //no of args
        null, //return arg uuid
        _TheO1_skeleton);
     _a_RO_methodRep.defineArg(
         0, //argIdx
         "ro", //argName
         false, //sibling
         0, //direction
         "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2"); //typeUid

    _xArr = new xerox.ilu.IluExceptionRep[1];
    _xArr[0] = CantCreate_exh_._CantCreategetRep();
    _get_O2_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        4, //local idx
        "get-O2", //name (in isl domain)
        5, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        0, //no of args
        "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", //return arg uuid
        _TheO1_skeleton);

    _xArr = new xerox.ilu.IluExceptionRep[1];
    _xArr[0] = CantCreate_exh_._CantCreategetRep();
    _get_O3_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        5, //local idx
        "get-O3", //name (in isl domain)
        6, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        1, //no of args
        "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU", //return arg uuid
        _TheO1_skeleton);
     _get_O3_methodRep.defineArg(
         0, //argIdx
         "subclass", //argName
         false, //sibling
         0, //direction
         "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I"); //typeUid

    try {
        _classRep.finishClass();
        TheO1Helper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering TheO1: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public TheU U_CSS_to_U(TheU u, java.lang.String[] css)
        throws E1, E2 {
        return _U_CSS_to_U_S(this, u, css);
    } //U_CSS_to_U

    public static TheU _U_CSS_to_U_S(TheO1 self, TheU u, java.lang.String[] css)
        throws E1, E2 {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        TheU _r = null;
        _call = xerox.ilu.IluCall.startCall(
            TheO1Stub._U_CSS_to_U_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TheO1Stub._classRep)
                + TheUHelper._szFunc(_call, u)
                + CSS._szFunc(_call, css)
                ) : 0);
            _call.outObject(self, true, TheO1Stub._classRep);
            TheUHelper._outFunc(_call, u);
            CSS._outFunc(_call, css);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = TheUHelper._inFunc(_call);
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(TheO1Stub._U_CSS_to_U_methodRep, _ec);
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
              case 2: throw (E2) _userException;
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
        return _r;
    } //_U_CSS_to_U_S

    public TheR f_CSS_to_RO(java.lang.String[] css)
        throws E1 {
        return _f_CSS_to_RO_S(this, css);
    } //f_CSS_to_RO

    public static TheR _f_CSS_to_RO_S(TheO1 self, java.lang.String[] css)
        throws E1 {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        TheR _r = null;
        _call = xerox.ilu.IluCall.startCall(
            TheO1Stub._f_CSS_to_RO_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TheO1Stub._classRep)
                + CSS._szFunc(_call, css)
                ) : 0);
            _call.outObject(self, true, TheO1Stub._classRep);
            CSS._outFunc(_call, css);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = ROStub._inFunc(_call);
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(TheO1Stub._f_CSS_to_RO_methodRep, _ec);
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
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
        return _r;
    } //_f_CSS_to_RO_S

    public float R_ScS_to_F(TheR r, java.lang.String s) {
        return _R_ScS_to_F_S(this, r, s);
    } //R_ScS_to_F

    public static float _R_ScS_to_F_S(TheO1 self, TheR r, java.lang.String s) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        float _r = 0F;
        _call = xerox.ilu.IluCall.startCall(
            TheO1Stub._R_ScS_to_F_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TheO1Stub._classRep)
                + TheRHelper._szFunc(_call, r)
                + _call.szString8(s, 0)
                ) : 0);
            _call.outObject(self, true, TheO1Stub._classRep);
            TheRHelper._outFunc(_call, r);
            _call.outString8(s, 0);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = _call.inReal32();
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
    } //_R_ScS_to_F_S

    public void a_RO(TheR ro) {
        _a_RO_S(this, ro);
    } //a_RO

    public static void _a_RO_S(TheO1 self, TheR ro) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        _call = xerox.ilu.IluCall.startCall(
            TheO1Stub._a_RO_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TheO1Stub._classRep)
                + ROStub._szFunc(_call, ro)
                ) : 0);
            _call.outObject(self, true, TheO1Stub._classRep);
            ROStub._outFunc(_call, ro);
            _call.doneWriteRequest();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
    } //_a_RO_S

    public O2 get_O2()
        throws CantCreate {
        return _get_O2_S(this);
    } //get_O2

    public static O2 _get_O2_S(TheO1 self)
        throws CantCreate {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        O2 _r = null;
        _call = xerox.ilu.IluCall.startCall(
            TheO1Stub._get_O2_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TheO1Stub._classRep)
                ) : 0);
            _call.outObject(self, true, TheO1Stub._classRep);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = (O2) _call.inObject(false, O2Stub.iluClass());
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(TheO1Stub._get_O2_methodRep, _ec);
            }
            _call.doneReadReply();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
        if (_ec != 0) {
            switch (_ec) {
              case 1: throw (CantCreate) _userException;
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
        return _r;
    } //_get_O2_S

    public O3 get_O3(boolean subclass)
        throws CantCreate {
        return _get_O3_S(this, subclass);
    } //get_O3

    public static O3 _get_O3_S(TheO1 self, boolean subclass)
        throws CantCreate {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        O3 _r = null;
        _call = xerox.ilu.IluCall.startCall(
            TheO1Stub._get_O3_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TheO1Stub._classRep)
                + _call.szBool(subclass)
                ) : 0);
            _call.outObject(self, true, TheO1Stub._classRep);
            _call.outBool(subclass);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = (O3) _call.inObject(false, O3Stub.iluClass());
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(TheO1Stub._get_O3_methodRep, _ec);
            }
            _call.doneReadReply();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
        if (_ec != 0) {
            switch (_ec) {
              case 1: throw (CantCreate) _userException;
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
        return _r;
    } //_get_O3_S

    public static void registerTrueObject(
        java.lang.String _ih,
        TheO1 _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public TheO1Stub() {
    }
    /** ilu use only */
    public TheO1Stub(java.lang.Object arg) {
    }
    static {
        Test1._allJavaStubs.load();
    }
} //TheO1Stub

class _TheO1_skeletonClass implements xerox.ilu.IluSkeleton {
    _TheO1_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //U_CSS_to_U
        {
          TheU _r = null;
          TheO1 _sob;
          _call.startReadRequest();
          _sob = (TheO1)
              _call.inObject(true, TheO1Stub._classRep);
          TheU u = TheUHelper._inFunc(_call);
          java.lang.String[] css = CSS._inFunc(_call);
          _call.doneReadRequest();
          try {
            _r = _sob.U_CSS_to_U(u, css);
          } catch (E1 _e) {
            Test1.E1_exh_._E1_marshall(_e, 1, _call);
            return;
          } catch (E2 _e) {
            Test1.E2_exh_._E2_marshall(_e, 2, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += TheUHelper._szFunc(_call, _r);
          }
          _call.startWriteReply(_sz);
          TheUHelper._outFunc(_call, _r);
          _call.doneWriteReply();
        }
        break;
      case 1: //f_CSS_to_RO
        {
          TheR _r = null;
          TheO1 _sob;
          _call.startReadRequest();
          _sob = (TheO1)
              _call.inObject(true, TheO1Stub._classRep);
          java.lang.String[] css = CSS._inFunc(_call);
          _call.doneReadRequest();
          try {
            _r = _sob.f_CSS_to_RO(css);
          } catch (E1 _e) {
            Test1.E1_exh_._E1_marshall(_e, 1, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += ROStub._szFunc(_call, _r);
          }
          _call.startWriteReply(_sz);
          ROStub._outFunc(_call, _r);
          _call.doneWriteReply();
        }
        break;
      case 2: //R_ScS_to_F
        {
          float _r = 0F;
          TheO1 _sob;
          _call.startReadRequest();
          _sob = (TheO1)
              _call.inObject(true, TheO1Stub._classRep);
          TheR r = TheRHelper._inFunc(_call);
          java.lang.String s = _call.inString8(0);
          _call.doneReadRequest();
          try {
            _r = _sob.R_ScS_to_F(r, s);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szReal32(_r);
          }
          _call.startWriteReply(_sz);
          _call.outReal32(_r);
          _call.doneWriteReply();
        }
        break;
      case 3: //a_RO
        {
          TheO1 _sob;
          _call.startReadRequest();
          _sob = (TheO1)
              _call.inObject(true, TheO1Stub._classRep);
          TheR ro = ROStub._inFunc(_call);
          _call.doneReadRequest();
            _sob.a_RO(ro);
      _call.noReply();
        }
        break;
      case 4: //get_O2
        {
          O2 _r = null;
          TheO1 _sob;
          _call.startReadRequest();
          _sob = (TheO1)
              _call.inObject(true, TheO1Stub._classRep);
          _call.doneReadRequest();
          try {
            _r = _sob.get_O2();
          } catch (CantCreate _e) {
            xerox.ilu.IluCall.simpleWriteException(_e, 1, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szObject(_r, false, O2Stub.iluClass());
          }
          _call.startWriteReply(_sz);
          _call.outObject(_r, false, O2Stub.iluClass());
          _call.doneWriteReply();
        }
        break;
      case 5: //get_O3
        {
          O3 _r = null;
          TheO1 _sob;
          _call.startReadRequest();
          _sob = (TheO1)
              _call.inObject(true, TheO1Stub._classRep);
          boolean subclass = _call.inBool();
          _call.doneReadRequest();
          try {
            _r = _sob.get_O3(subclass);
          } catch (CantCreate _e) {
            xerox.ilu.IluCall.simpleWriteException(_e, 1, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szObject(_r, false, O3Stub.iluClass());
          }
          _call.startWriteReply(_sz);
          _call.outObject(_r, false, O3Stub.iluClass());
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_TheO1_skeletonClass

