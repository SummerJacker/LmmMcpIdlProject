// javastubs/Simple/TestObjectStub.java
// Stubs for "Simple"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:42 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/javatest1/Simple.isl" of Sat Aug 02 19:45:15 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/javatest1/../../Interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Simple;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class TestObjectStub extends xerox.ilu.IluSurrogateObject implements TestObject {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _method1_methodRep;
    static private xerox.ilu.IluExceptionRep[] _xArr = null;
    static private _TestObject_skeletonClass _TestObject_skeleton = new _TestObject_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Simple.TestObject", //java reference interface name
            "Simple.TestObject", //ilu object type name
            "ilut:hdaROXdjTjHMQuKatVn1O6LS4yR", //uuid
            1); //method count
        _classRep.setOptional();
        _classRep.setSurrClass("Simple.TestObjectStub");
        _classRep.setIfName("Simple"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering TestObject: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _xArr = new xerox.ilu.IluExceptionRep[2];
    _xArr[0] = Exc1_exh_._Exc1getRep();
    _xArr[1] = Exc2_exh_._Exc2getRep();
    _method1_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "method1", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        1, //no of args
        "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", //return arg uuid
        _TestObject_skeleton);
     _method1_methodRep.defineArg(
         0, //argIdx
         "i", //argName
         false, //sibling
         0, //direction
         "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY"); //typeUid

    try {
        _classRep.finishClass();
        TestObjectHelper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering TestObject: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public int method1(int i)
        throws Exc1, Exc2 {
        return _method1_S(this, i);
    } //method1

    public static int _method1_S(TestObject self, int i)
        throws Exc1, Exc2 {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        int _r = 0;
        _call = xerox.ilu.IluCall.startCall(
            TestObjectStub._method1_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TestObjectStub._classRep)
                + _call.szInt32(i)
                ) : 0);
            _call.outObject(self, true, TestObjectStub._classRep);
            _call.outInt32(i);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = _call.inInt32();
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(TestObjectStub._method1_methodRep, _ec);
            }
            _call.doneReadReply();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
        if (_ec != 0) {
            switch (_ec) {
              case 1: throw (Exc1) _userException;
              case 2: throw (Exc2) _userException;
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
        return _r;
    } //_method1_S

    public static void registerTrueObject(
        java.lang.String _ih,
        TestObject _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public TestObjectStub() {
    }
    /** ilu use only */
    public TestObjectStub(java.lang.Object arg) {
    }
    static {
        Simple._allJavaStubs.load();
    }
} //TestObjectStub

class _TestObject_skeletonClass implements xerox.ilu.IluSkeleton {
    _TestObject_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //method1
        {
          int _r = 0;
          TestObject _sob;
          _call.startReadRequest();
          _sob = (TestObject)
              _call.inObject(true, TestObjectStub._classRep);
          int i = _call.inInt32();
          _call.doneReadRequest();
          try {
            _r = _sob.method1(i);
          } catch (Exc1 _e) {
            xerox.ilu.IluCall.simpleWriteException(_e, 1, _call);
            return;
          } catch (Exc2 _e) {
            xerox.ilu.IluCall.simpleWriteException(_e, 2, _call);
            return;
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

} //_TestObject_skeletonClass

