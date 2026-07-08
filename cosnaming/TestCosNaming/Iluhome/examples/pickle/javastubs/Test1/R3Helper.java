// javastubs/Test1/R3Helper.java
// Stubs for "Test1"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:39 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/pickle//Test1.isl" of Fri Aug 01 14:00:48 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/pickle//ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test1;


/** 
 * An ILU helper class.
 */
public class R3Helper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "IDL:Test1/R3:1.0";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new R3Helper(), org.omg.CORBA.TCKind.tk_struct);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, R3 _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static R3 extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((R3)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(R3 _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = R3Helper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            R3Helper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static R3 from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        R3 _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = R3Helper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        R3 _xx = ((R3)_x);
        return R3Helper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        R3 _xx = ((R3)_x);
        R3Helper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return R3Helper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof R3);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
    static {
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerRecordType(
            "R3", //name
            "Test1", //islIfName
            null, //islIfBrand
            "IDL:Test1/R3:1.0", //uid
            2 //cnt
            );
        __t.registerRecordField(0, "a", "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY");
        __t.registerRecordField(1, "b", "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP");
        __t.finish();
        __t = null;
    }

    //internal to ILU only
    public static int _szFunc(xerox.ilu.IluCall _call, R3 _r)
                throws org.omg.CORBA.SystemException {
        int _sz = _call.szRecord();
        _sz = _sz + _call.szInt32(_r.a);
        _sz = _sz + _call.szReal64(_r.b);
        _call.endRecord();
        return _sz;
    } //_szFunc

    //internal to ILU only
    public static void _outFunc(xerox.ilu.IluCall _call, R3 _r)
                throws org.omg.CORBA.SystemException {
        _call.outRecord();
        _call.outInt32(_r.a);
        _call.outReal64(_r.b);
        _call.endRecord();
    } //_outFunc

    //internal to ILU only
    public static R3 _inFunc(xerox.ilu.IluCall _call)
                throws org.omg.CORBA.SystemException {
        R3 _r = R3.alloc_R3();
        _call.inRecord();
        _r.a = _call.inInt32();
        _r.b = _call.inReal64();
        _call.endRecord();
        _r._touch();
        return _r;
    } //_inFunc

}//R3Helper

