// javastubs/Test1/R2Helper.java
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
public class R2Helper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:e-HyCzKuewwn0QoIiC7r79x3D4n";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        TheRHelper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new R2Helper(), org.omg.CORBA.TCKind.tk_struct);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, R2 _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static R2 extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((R2)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(R2 _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = R2Helper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            R2Helper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static R2 from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        R2 _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = R2Helper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        R2 _xx = ((R2)_x);
        return R2Helper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        R2 _xx = ((R2)_x);
        R2Helper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return R2Helper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof R2);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
    static {
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerRecordType(
            "R2", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:e-HyCzKuewwn0QoIiC7r79x3D4n", //uid
            2 //cnt
            );
        __t.registerRecordField(0, "a", "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7");
        __t.registerRecordField(1, "b", "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco");
        __t.finish();
        __t = null;
    }

    //internal to ILU only
    public static int _szFunc(xerox.ilu.IluCall _call, R2 _r)
                throws org.omg.CORBA.SystemException {
        int _sz = _call.szRecord();
        _sz = _sz + TheRHelper._szFunc(_call, _r.a);
        _sz = _sz + _r.b._szAny(_call);
        _call.endRecord();
        return _sz;
    } //_szFunc

    //internal to ILU only
    public static void _outFunc(xerox.ilu.IluCall _call, R2 _r)
                throws org.omg.CORBA.SystemException {
        _call.outRecord();
        TheRHelper._outFunc(_call, _r.a);
        _r.b._outAny(_call);
        _call.endRecord();
    } //_outFunc

    //internal to ILU only
    public static R2 _inFunc(xerox.ilu.IluCall _call)
                throws org.omg.CORBA.SystemException {
        R2 _r = R2.alloc_R2();
        _call.inRecord();
        _r.a = TheRHelper._inFunc(_call);
        _r.b = xerox.ilu.IluAny._inAny(_call);
        _call.endRecord();
        _r._touch();
        return _r;
    } //_inFunc

}//R2Helper

