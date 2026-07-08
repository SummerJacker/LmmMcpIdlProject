// javastubs/Simple/TestObjectHelper.java
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
 * An ILU helper class.
 */
public class TestObjectHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:hdaROXdjTjHMQuKatVn1O6LS4yR";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new TestObjectHelper(), org.omg.CORBA.TCKind.tk_objref);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, TestObject _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static TestObject extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((TestObject)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(TestObject _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = _call.szObject(_x, false, TestObjectStub.iluClass());
            _pickle.midToPickle(_call, _sz, id());
            _call.outObject(_x, false, TestObjectStub.iluClass());
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static TestObject from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        TestObject _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = (TestObject) _call.inObject(false, TestObjectStub.iluClass());
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        TestObject _xx = ((TestObject)_x);
        return _call.szObject(_xx, false, TestObjectStub.iluClass());
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        TestObject _xx = ((TestObject)_x);
        _call.outObject(_xx, false, TestObjectStub.iluClass());
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return (TestObject) _call.inObject(false, TestObjectStub.iluClass());
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return true;
        return (_x instanceof TestObject);
    } //isAFunc 

    static {
        Simple._allJavaStubs.load();
    }
    public static TestObject narrow(java.lang.Object _x) {
        return (TestObject) _x;
    } //narrow 

}//TestObjectHelper

