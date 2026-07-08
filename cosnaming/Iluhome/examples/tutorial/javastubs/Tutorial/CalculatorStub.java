// javastubs/Tutorial/CalculatorStub.java
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
 * 4-function calculator
 * A stub class implementing surrogates for an ILU object type.
 */
public class CalculatorStub extends xerox.ilu.IluSurrogateObject implements Calculator {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _SetValue_methodRep;
    static xerox.ilu.IluMethodRep _GetValue_methodRep;
    static xerox.ilu.IluMethodRep _Add_methodRep;
    static xerox.ilu.IluMethodRep _Subtract_methodRep;
    static xerox.ilu.IluMethodRep _Multiply_methodRep;
    static xerox.ilu.IluMethodRep _Divide_methodRep;
    static private xerox.ilu.IluExceptionRep[] _xArr = null;
    static private _Calculator_skeletonClass _Calculator_skeleton = new _Calculator_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "Tutorial.Calculator", //java reference interface name
            "Tutorial.Calculator", //ilu object type name
            "ilut:hKWsBzveel2pjsqsi1Gw1UPmSNS", //uuid
            6); //method count
        _classRep.setCollectable();
        _classRep.setDocString("4-function calculator");
        _classRep.setSurrClass("Tutorial.CalculatorStub");
        _classRep.setIfName("Tutorial"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering Calculator: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _SetValue_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "SetValue", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        null, //return arg uuid
        _Calculator_skeleton);
     _SetValue_methodRep.defineArg(
         0, //argIdx
         "v", //argName
         false, //sibling
         0, //direction
         "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"); //typeUid

    _GetValue_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        1, //local idx
        "GetValue", //name (in isl domain)
        2, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        0, //no of args
        "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", //return arg uuid
        _Calculator_skeleton);

    _Add_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        2, //local idx
        "Add", //name (in isl domain)
        3, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        null, //return arg uuid
        _Calculator_skeleton);
     _Add_methodRep.defineArg(
         0, //argIdx
         "v", //argName
         false, //sibling
         0, //direction
         "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"); //typeUid

    _Subtract_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        3, //local idx
        "Subtract", //name (in isl domain)
        4, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        null, //return arg uuid
        _Calculator_skeleton);
     _Subtract_methodRep.defineArg(
         0, //argIdx
         "v", //argName
         false, //sibling
         0, //direction
         "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"); //typeUid

    _Multiply_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        4, //local idx
        "Multiply", //name (in isl domain)
        5, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        null, //return arg uuid
        _Calculator_skeleton);
     _Multiply_methodRep.defineArg(
         0, //argIdx
         "v", //argName
         false, //sibling
         0, //direction
         "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"); //typeUid

    _xArr = new xerox.ilu.IluExceptionRep[1];
    _xArr[0] = DivideByZero_exh_._DivideByZerogetRep();
    _Divide_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        5, //local idx
        "Divide", //name (in isl domain)
        6, //remote id
        false, //functional
        false, //asynch
        _xArr, //exceptions
        1, //no of args
        null, //return arg uuid
        _Calculator_skeleton);
     _Divide_methodRep.defineArg(
         0, //argIdx
         "v", //argName
         false, //sibling
         0, //direction
         "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP"); //typeUid

    try {
        _classRep.finishClass();
        CalculatorHelper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering Calculator: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public void SetValue(double v) {
        _SetValue_S(this, v);
    } //SetValue

    public static void _SetValue_S(Calculator self, double v) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        _call = xerox.ilu.IluCall.startCall(
            CalculatorStub._SetValue_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, CalculatorStub._classRep)
                + _call.szReal64(v)
                ) : 0);
            _call.outObject(self, true, CalculatorStub._classRep);
            _call.outReal64(v);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
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
    } //_SetValue_S

    public double GetValue() {
        return _GetValue_S(this);
    } //GetValue

    public static double _GetValue_S(Calculator self) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        double _r = 0D;
        _call = xerox.ilu.IluCall.startCall(
            CalculatorStub._GetValue_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, CalculatorStub._classRep)
                ) : 0);
            _call.outObject(self, true, CalculatorStub._classRep);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = _call.inReal64();
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
    } //_GetValue_S

    public void Add(double v) {
        _Add_S(this, v);
    } //Add

    public static void _Add_S(Calculator self, double v) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        _call = xerox.ilu.IluCall.startCall(
            CalculatorStub._Add_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, CalculatorStub._classRep)
                + _call.szReal64(v)
                ) : 0);
            _call.outObject(self, true, CalculatorStub._classRep);
            _call.outReal64(v);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
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
    } //_Add_S

    public void Subtract(double v) {
        _Subtract_S(this, v);
    } //Subtract

    public static void _Subtract_S(Calculator self, double v) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        _call = xerox.ilu.IluCall.startCall(
            CalculatorStub._Subtract_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, CalculatorStub._classRep)
                + _call.szReal64(v)
                ) : 0);
            _call.outObject(self, true, CalculatorStub._classRep);
            _call.outReal64(v);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
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
    } //_Subtract_S

    public void Multiply(double v) {
        _Multiply_S(this, v);
    } //Multiply

    public static void _Multiply_S(Calculator self, double v) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        _call = xerox.ilu.IluCall.startCall(
            CalculatorStub._Multiply_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, CalculatorStub._classRep)
                + _call.szReal64(v)
                ) : 0);
            _call.outObject(self, true, CalculatorStub._classRep);
            _call.outReal64(v);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
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
    } //_Multiply_S

    public void Divide(double v)
        throws DivideByZero {
        _Divide_S(this, v);
    } //Divide

    public static void _Divide_S(Calculator self, double v)
        throws DivideByZero {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        _call = xerox.ilu.IluCall.startCall(
            CalculatorStub._Divide_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, CalculatorStub._classRep)
                + _call.szReal64(v)
                ) : 0);
            _call.outObject(self, true, CalculatorStub._classRep);
            _call.outReal64(v);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
            } else if (_ec == xerox.ilu.IluCall.retryCode) {
              continue _retry;
            } else if (_ec > 0) {
                _userException = _call.readException(CalculatorStub._Divide_methodRep, _ec);
            }
            _call.doneReadReply();
            break _retry;
          } while (true);
        } finally {
            _call.finishCall();
        }
        if (_ec != 0) {
            switch (_ec) {
              case 1: throw (DivideByZero) _userException;
            }
            throw xerox.ilu.IluSystemExceptionBase.fromIluProtocolException(_ec);
        }
    } //_Divide_S

    public static void registerTrueObject(
        java.lang.String _ih,
        Calculator _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public CalculatorStub() {
    }
    /** ilu use only */
    public CalculatorStub(java.lang.Object arg) {
    }
    static {
        Tutorial._allJavaStubs.load();
    }
} //CalculatorStub

class _Calculator_skeletonClass implements xerox.ilu.IluSkeleton {
    _Calculator_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //SetValue
        {
          Calculator _sob;
          _call.startReadRequest();
          _sob = (Calculator)
              _call.inObject(true, CalculatorStub._classRep);
          double v = _call.inReal64();
          _call.doneReadRequest();
          try {
            _sob.SetValue(v);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
          }
          _call.startWriteReply(_sz);
          _call.doneWriteReply();
        }
        break;
      case 1: //GetValue
        {
          double _r = 0D;
          Calculator _sob;
          _call.startReadRequest();
          _sob = (Calculator)
              _call.inObject(true, CalculatorStub._classRep);
          _call.doneReadRequest();
          try {
            _r = _sob.GetValue();
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szReal64(_r);
          }
          _call.startWriteReply(_sz);
          _call.outReal64(_r);
          _call.doneWriteReply();
        }
        break;
      case 2: //Add
        {
          Calculator _sob;
          _call.startReadRequest();
          _sob = (Calculator)
              _call.inObject(true, CalculatorStub._classRep);
          double v = _call.inReal64();
          _call.doneReadRequest();
          try {
            _sob.Add(v);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
          }
          _call.startWriteReply(_sz);
          _call.doneWriteReply();
        }
        break;
      case 3: //Subtract
        {
          Calculator _sob;
          _call.startReadRequest();
          _sob = (Calculator)
              _call.inObject(true, CalculatorStub._classRep);
          double v = _call.inReal64();
          _call.doneReadRequest();
          try {
            _sob.Subtract(v);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
          }
          _call.startWriteReply(_sz);
          _call.doneWriteReply();
        }
        break;
      case 4: //Multiply
        {
          Calculator _sob;
          _call.startReadRequest();
          _sob = (Calculator)
              _call.inObject(true, CalculatorStub._classRep);
          double v = _call.inReal64();
          _call.doneReadRequest();
          try {
            _sob.Multiply(v);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
          }
          _call.startWriteReply(_sz);
          _call.doneWriteReply();
        }
        break;
      case 5: //Divide
        {
          Calculator _sob;
          _call.startReadRequest();
          _sob = (Calculator)
              _call.inObject(true, CalculatorStub._classRep);
          double v = _call.inReal64();
          _call.doneReadRequest();
          try {
            _sob.Divide(v);
          } catch (DivideByZero _e) {
            xerox.ilu.IluCall.simpleWriteException(_e, 1, _call);
            return;
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
          }
          _call.startWriteReply(_sz);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_Calculator_skeletonClass

