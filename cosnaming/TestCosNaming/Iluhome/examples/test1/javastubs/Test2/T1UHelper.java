// javastubs/Test2/T1UHelper.java
// Stubs for "Test2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test2;


/** 
 * An ILU helper class.
 */
public class T1UHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new T1UHelper(), org.omg.CORBA.TCKind.tk_alias);
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerAliasType(
            "T1U", //name
            "Test2", //islIfName
            null, //islIfBrand
            "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", //uid
            "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW"); //baseUID
        __t = null;
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, Test1.TheU _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static Test1.TheU extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((Test1.TheU)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(Test1.TheU _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = Test1.TheUHelper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            Test1.TheUHelper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static Test1.TheU from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        Test1.TheU _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = Test1.TheUHelper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        Test1.TheU _xx = ((Test1.TheU)_x);
        return Test1.TheUHelper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        Test1.TheU _xx = ((Test1.TheU)_x);
        Test1.TheUHelper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return Test1.TheUHelper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof Test1.TheU);
    } //isAFunc 

    static {
        Test2._allJavaStubs.load();
    }
}//T1UHelper

