// javastubs/Tutorial2/TapeCalculatorStub.java
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
 * 4 function calculator with register tape
 * A stub class implementing surrogates for an ILU object type.
 */
public class TapeCalculatorStub extends xerox.ilu.IluSurrogateObject implements TapeCalculator {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _GetTape_methodRep;
    static private _TapeCalculator_skeletonClass _TapeCalculator_skeleton = new _TapeCalculator_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    xerox.ilu.IluClassRep[] ca = new xerox.ilu.IluClassRep[1];
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Tutorial2.TapeCalculator", //java reference interface name
            "Tutorial2.TapeCalculator", //ilu object type name
            "ilut:o9d432P85uZzy0yd5M9hffcUvdP", //uuid
            1); //method count
        ca[0] = Tutorial.CalculatorStub.iluClass();
        _classRep.setSuperClasses(ca);
        _classRep.setCollectable();
        _classRep.setDocString("4 function calculator with register tape");
        _classRep.setSurrClass("Tutorial2.TapeCalculatorStub");
        _classRep.setIfName("Tutorial2"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering TapeCalculator: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _GetTape_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "GetTape", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        0, //no of args
        "ilut:i03-tJkWBPLHe2ONK6OHat-LDSV", //return arg uuid
        _TapeCalculator_skeleton);

    try {
        _classRep.finishClass();
        TapeCalculatorHelper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering TapeCalculator: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public Operation[] GetTape() {
        return _GetTape_S(this);
    } //GetTape

    public static Operation[] _GetTape_S(TapeCalculator self) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        Operation[] _r = null;
        _call = xerox.ilu.IluCall.startCall(
            TapeCalculatorStub._GetTape_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, TapeCalculatorStub._classRep)
                ) : 0);
            _call.outObject(self, true, TapeCalculatorStub._classRep);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = RegisterTape._inFunc(_call);
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
    } //_GetTape_S

    public void SetValue(double v) {
        Tutorial.CalculatorStub._SetValue_S(this, v);
    } //SetValue

    public double GetValue() {
        return Tutorial.CalculatorStub._GetValue_S(this);
    } //GetValue

    public void Add(double v) {
        Tutorial.CalculatorStub._Add_S(this, v);
    } //Add

    public void Subtract(double v) {
        Tutorial.CalculatorStub._Subtract_S(this, v);
    } //Subtract

    public void Multiply(double v) {
        Tutorial.CalculatorStub._Multiply_S(this, v);
    } //Multiply

    public void Divide(double v)
        throws Tutorial.DivideByZero {
        Tutorial.CalculatorStub._Divide_S(this, v);
    } //Divide

    public static void registerTrueObject(
        java.lang.String _ih,
        TapeCalculator _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public TapeCalculatorStub() {
    }
    /** ilu use only */
    public TapeCalculatorStub(java.lang.Object arg) {
    }
    static {
        Tutorial2._allJavaStubs.load();
    }
} //TapeCalculatorStub

class _TapeCalculator_skeletonClass implements xerox.ilu.IluSkeleton {
    _TapeCalculator_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //GetTape
        {
          Operation[] _r = null;
          TapeCalculator _sob;
          _call.startReadRequest();
          _sob = (TapeCalculator)
              _call.inObject(true, TapeCalculatorStub._classRep);
          _call.doneReadRequest();
          try {
            _r = _sob.GetTape();
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += RegisterTape._szFunc(_call, _r);
          }
          _call.startWriteReply(_sz);
          RegisterTape._outFunc(_call, _r);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_TapeCalculator_skeletonClass

