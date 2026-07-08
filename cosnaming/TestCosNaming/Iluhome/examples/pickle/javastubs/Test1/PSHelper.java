// javastubs/Test1/PSHelper.java
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
public class PSHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:cwxcXxseM5ByCkx3dhm6UsMKHY4";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new PSHelper(), org.omg.CORBA.TCKind.tk_sequence);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, xerox.ilu.IluAny[] _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static xerox.ilu.IluAny[] extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((xerox.ilu.IluAny[])_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(xerox.ilu.IluAny[] _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = PS._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            PS._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static xerox.ilu.IluAny[] from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny[] _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = PS._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny[] _xx = ((xerox.ilu.IluAny[])_x);
        return PS._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny[] _xx = ((xerox.ilu.IluAny[])_x);
        PS._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return PS._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof xerox.ilu.IluAny[]);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
}//PSHelper

