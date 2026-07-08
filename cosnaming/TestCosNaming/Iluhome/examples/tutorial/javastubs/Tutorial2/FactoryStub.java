// javastubs/Tutorial2/FactoryStub.java
// Stubs for "Tutorial2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:33 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial2.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Tutorial2;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class FactoryStub extends xerox.ilu.IluSurrogateObject implements Factory {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _CreateTapeCalculator_methodRep;
    static private _Factory_skeletonClass _Factory_skeleton = new _Factory_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    xerox.ilu.IluClassRep[] ca = new xerox.ilu.IluClassRep[1];
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Tutorial2.Factory", //java reference interface name
            "Tutorial2.Factory", //ilu object type name
            "ilut:cPIlfNX5Jw85kJwez4xg3JIM5ky", //uuid
            1); //method count
        ca[0] = Tutorial.FactoryStub.iluClass();
        _classRep.setSuperClasses(ca);
        _classRep.setSurrClass("Tutorial2.FactoryStub");
        _classRep.setIfName("Tutorial2"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering Factory: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _CreateTapeCalculator_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "CreateTapeCalculator", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        0, //no of args
        "ilut:o9d432P85uZzy0yd5M9hffcUvdP", //return arg uuid
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

    public TapeCalculator CreateTapeCalculator() {
        return _CreateTapeCalculator_S(this);
    } //CreateTapeCalculator

    public static TapeCalculator _CreateTapeCalculator_S(Factory self) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        TapeCalculator _r = null;
        _call = xerox.ilu.IluCall.startCall(
            FactoryStub._CreateTapeCalculator_methodRep,
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
                _r = (TapeCalculator) _call.inObject(false, TapeCalculatorStub.iluClass());
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
    } //_CreateTapeCalculator_S

    public Tutorial.Calculator CreateCalculator() {
        return Tutorial.FactoryStub._CreateCalculator_S(this);
    } //CreateCalculator

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
        Tutorial2._allJavaStubs.load();
    }
} //FactoryStub

class _Factory_skeletonClass implements xerox.ilu.IluSkeleton {
    _Factory_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //CreateTapeCalculator
        {
          TapeCalculator _r = null;
          Factory _sob;
          _call.startReadRequest();
          _sob = (Factory)
              _call.inObject(true, FactoryStub._classRep);
          _call.doneReadRequest();
          try {
            _r = _sob.CreateTapeCalculator();
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szObject(_r, false, TapeCalculatorStub.iluClass());
          }
          _call.startWriteReply(_sz);
          _call.outObject(_r, false, TapeCalculatorStub.iluClass());
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_Factory_skeletonClass

