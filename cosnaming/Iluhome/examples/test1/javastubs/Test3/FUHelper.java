// javastubs/Test3/FUHelper.java
// Stubs for "Test3"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test3;


/** 
 * An ILU helper class.
 */
public class FUHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:p7oYELOBiB2uFXthQiHxgFh1H8p";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        Test1.TheEHelper.id();
        OHelper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new FUHelper(), org.omg.CORBA.TCKind.tk_union);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, FU _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static FU extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((FU)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(FU _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = FUHelper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            FUHelper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static FU from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        FU _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = FUHelper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        FU _xx = ((FU)_x);
        return FUHelper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        FU _xx = ((FU)_x);
        FUHelper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return FUHelper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof FU);
    } //isAFunc 

    static {
        Test3._allJavaStubs.load();
    }
    public static int _szFunc(xerox.ilu.IluCall _call, FU _a) 
        throws org.omg.CORBA.SystemException
    {
        int _sz;
         _sz = _call.szUnion(_a._dis.value(), xerox.ilu.IluTypeKind.enumeration_tk);
        switch(_a._dis.value()) {
            case Test1.TheE._ev1:
                _sz = _sz + _call.szObject(((O)_a._val), false, OStub.iluClass());
                break;
            case Test1.TheE._ev3:
                _sz = _sz + _call.szInt32(((java.lang.Number)_a._val).intValue());
                break;
        }
        _call.endUnion();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, FU _a) 
        throws org.omg.CORBA.SystemException
    {
        if (!_a._init) {throw new org.omg.CORBA.BAD_OPERATION();}
        _call.outUnion(_a._dis.value(), xerox.ilu.IluTypeKind.enumeration_tk);
        switch(_a._dis.value()) {
            case Test1.TheE._ev1:
                _call.outObject(((O)_a._val), false, OStub.iluClass());
                break;
            case Test1.TheE._ev3:
                _call.outInt32(((java.lang.Number)_a._val).intValue());
                break;
        }
        _call.endUnion();
    } //_outFunc

    public static FU _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        FU _v = null;
        Test1.TheE _d;
        _d = (Test1.TheE.from_int(_call.inUnion(xerox.ilu.IluTypeKind.enumeration_tk)));
        switch(_d.value()) {
            case Test1.TheE._ev1:
                _v = FU.alloc_O(_d, (O) _call.inObject(false, OStub.iluClass()));
                break;
            case Test1.TheE._ev3:
                _v = FU.alloc_integer(_d, _call.inInt32());
                break;
            default:
              _call.endUnion();
              throw new org.omg.CORBA.BAD_OPERATION();
        }
        _call.endUnion();
        return _v;
    } //_inFunc

    static {
        int[] _ivals = null;
        java.lang.String[] _svals = null;
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerUnionType(
            "FU", //name
            "Test3", //islIfName
            null, //islIfBrand
            "ilut:p7oYELOBiB2uFXthQiHxgFh1H8p", //uid
            "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh", //discriminatUID
            2, //cnt
            -1, //defaultArm
            false, //othersAllowed
            xerox.ilu.IluConstantValueKind.enumeration_cvk); //valueKind
        FUHelper.id(); //loads helper class
        _svals = new java.lang.String[1];
        _svals[0] = "ev1";
        __t.registerUnionArm(
            0, //armNum
            null, //islArmName
            "ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _svals = new java.lang.String[1];
        _svals[0] = "ev3";
        __t.registerUnionArm(
            1, //armNum
            null, //islArmName
            "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        __t.finish();
        __t = null;
    } //static
}//FUHelper

