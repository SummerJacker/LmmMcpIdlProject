// javastubs/Tutorial/FactoryStub.java
// Stubs for "Tutorial"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:33 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Tutorial;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class FactoryStub extends xerox.ilu.IluSurrogateObject implements Factory {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _CreateCalculator_methodRep;
    static private _Factory_skeletonClass _Factory_skeleton = new _Factory_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Tutorial.Factory", //java reference interface name
            "Tutorial.Factory", //ilu object type name
            "ilut:fE09b9OL8wKjd0F0yXvJqDGNuqW", //uuid
            1); //method count
        _classRep.setSurrClass("Tutorial.FactoryStub");
        _classRep.setIfName("Tutorial"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering Factory: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _CreateCalculator_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "CreateCalculator", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        0, //no of args
        "ilut:hKWsBzveel2pjsqsi1Gw1UPmSNS", //return arg uuid
        _Factory_skeleton);

    try {
        _classRep.finishClass();
        FactoryHelper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering Factory: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public Calculator CreateCalculator() {
        return _CreateCalculator_S(this);
    } //CreateCalculator

    public static Calculator _CreateCalculator_S(Factory self) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        Calculator _r = null;
        _call = xerox.ilu.IluCall.startCall(
            FactoryStub._CreateCalculator_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, FactoryStub._classRep)
                ) : 0);
            _call.outObject(self, true, FactoryStub._classRep);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = (Calculator) _call.inObject(false, CalculatorStub.iluClass());
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
    } //_CreateCalculator_S

    public static void registerTrueObject(
        java.lang.String _ih,
        Factory _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public FactoryStub() {
    }
    /** ilu use only */
    public FactoryStub(java.lang.Object arg) {
    }
    static {
        Tutorial._allJavaStubs.load();
    }
} //FactoryStub

class _Factory_skeletonClass implements xerox.ilu.IluSkeleton {
    _Factory_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //CreateCalculator
        {
          Calculator _r = null;
          Factory _sob;
          _call.startReadRequest();
          _sob = (Factory)
              _call.inObject(true, FactoryStub._classRep);
          _call.doneReadRequest();
          try {
            _r = _sob.CreateCalculator();
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szObject(_r, false, CalculatorStub.iluClass());
          }
          _call.startWriteReply(_sz);
          _call.outObject(_r, false, CalculatorStub.iluClass());
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_Factory_skeletonClass

