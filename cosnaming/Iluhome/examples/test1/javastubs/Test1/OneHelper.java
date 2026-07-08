// javastubs/Test1/OneHelper.java
// Stubs for "Test1"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:19 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test1;


/** 
 * sample
 * multi-line doc string
 * An ILU helper class.
 */
public class OneHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:fmBFu4mQpwjov+CekDxhjwxkgty";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new OneHelper(), org.omg.CORBA.TCKind.tk_alias);
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerAliasType(
            "One", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", //uid
            "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"); //baseUID
        __t = null;
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, TheO1 _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static TheO1 extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((TheO1)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(TheO1 _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = _call.szObject(_x, false, TheO1Stub.iluClass());
            _pickle.midToPickle(_call, _sz, id());
            _call.outObject(_x, false, TheO1Stub.iluClass());
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static TheO1 from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        TheO1 _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = (TheO1) _call.inObject(false, TheO1Stub.iluClass());
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        TheO1 _xx = ((TheO1)_x);
        return _call.szObject(_xx, false, TheO1Stub.iluClass());
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        TheO1 _xx = ((TheO1)_x);
        _call.outObject(_xx, false, TheO1Stub.iluClass());
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return (TheO1) _call.inObject(false, TheO1Stub.iluClass());
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof TheO1);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
}//OneHelper

