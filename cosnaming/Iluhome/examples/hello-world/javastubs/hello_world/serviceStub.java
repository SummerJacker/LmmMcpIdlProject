// javastubs/hello_world/serviceStub.java
// Stubs for "hello-world"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:51 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/hello-world/hello-world.isl" of Wed Jul 30 16:24:59 2025,
// and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package hello_world;


/** 
 * A stub class implementing surrogates for an ILU object type.
 */
public class serviceStub extends xerox.ilu.IluSurrogateObject implements service {

    static xerox.ilu.IluClassRep _classRep;
    static xerox.ilu.IluMethodRep _hello_world_methodRep;
    static private _service_skeletonClass _service_skeleton = new _service_skeletonClass();

  static {
    xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
    try {
        _classRep = xerox.ilu.IluClassRep.setupClass(
            "hello_world.service", //java reference interface name
            "hello-world.service", //ilu object type name
            "ilut:lIV5QXo6KXw4vrj0tHlcPTOi1oY", //uuid
            1); //method count
        _classRep.setSurrClass("hello_world.serviceStub");
        _classRep.setIfName("hello-world"); 
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering service: " + e);
        e.printStackTrace(System.err);
        throw e;    }
    _hello_world_methodRep = xerox.ilu.IluMethodRep.registerMethod(
        _classRep, //IluClassRep
        0, //local idx
        "hello-world", //name (in isl domain)
        1, //remote id
        false, //functional
        false, //asynch
        null, //exceptions
        1, //no of args
        "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", //return arg uuid
        _service_skeleton);
     _hello_world_methodRep.defineArg(
         0, //argIdx
         "inarg", //argName
         false, //sibling
         0, //direction
         "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"); //typeUid

    try {
        _classRep.finishClass();
        serviceHelper.id(); //makes sure helper class is loaded
    } catch (org.omg.CORBA.SystemException e) {
        System.err.println("**error registering service: " + e);
        e.printStackTrace(System.err);
        throw e;    }
  }//static

    /** returns ilu class implemented by this stub class */
    static public final xerox.ilu.IluClassRep iluClass() {
        return _classRep;
    }//iluClass

    public java.lang.String hello_world(java.lang.String inarg) {
        return _hello_world_S(this, inarg);
    } //hello_world

    public static java.lang.String _hello_world_S(service self, java.lang.String inarg) {
        xerox.ilu.IluCall _call;
        xerox.ilu.IluUserException _userException = null;
        int _ec = 0;
        java.lang.String _r = null;
        _call = xerox.ilu.IluCall.startCall(
            serviceStub._hello_world_methodRep,
            (xerox.ilu.IluSurrogateObject) self
            );
        try {
          _retry: do {
            _call.startWriteRequest(_call.needsSizing() ? (
                  _call.szObject(self, true, serviceStub._classRep)
                + _call.szString8(inarg, 0)
                ) : 0);
            _call.outObject(self, true, serviceStub._classRep);
            _call.outString8(inarg, 0);
            _call.doneWriteRequest();
            _ec = _call.startReadReply();
            if (_ec == 0) {
                _r = _call.inString8(0);
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
    } //_hello_world_S

    public static void registerTrueObject(
        java.lang.String _ih,
        service _tob,
        xerox.ilu.IluServer _s) throws org.omg.CORBA.SystemException {
        xerox.ilu.Ilu.registerTrueObject(_ih, _tob, _s, _classRep, 0);
    } //registerTrueObject

    /** ilu use only */
    public serviceStub() {
    }
    /** ilu use only */
    public serviceStub(java.lang.Object arg) {
    }
    static {
        hello_world._allJavaStubs.load();
    }
} //serviceStub

class _service_skeletonClass implements xerox.ilu.IluSkeleton {
    _service_skeletonClass() {
    }

  public void serveRequest(xerox.ilu.IluCall _call, xerox.ilu.IluMethodRep _m) 
            throws org.omg.CORBA.SystemException {
    int _sz = 0;
    switch(_m.methodIdx) {
      case 0: //hello_world
        {
          java.lang.String _r = null;
          service _sob;
          _call.startReadRequest();
          _sob = (service)
              _call.inObject(true, serviceStub._classRep);
          java.lang.String inarg = _call.inString8(0);
          _call.doneReadRequest();
          try {
            _r = _sob.hello_world(inarg);
          } catch (java.lang.Exception _e) {
              _call.unexpectedException(_e);
              return;
          }
          if (_call.needsSizing()) {
            _sz = _call.beginSizingReply();
            _sz += _call.szString8(_r, 0);
          }
          _call.startWriteReply(_sz);
          _call.outString8(_r, 0);
          _call.doneWriteReply();
        }
        break;
      default:
    }
  } //serveRequest

} //_service_skeletonClass

