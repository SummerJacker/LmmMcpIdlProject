// javastubs/Test1/U3Helper.java
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
public class U3Helper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:cm4OUUbxSugq0XZxcQJOPsU8dtK";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        TheEHelper.id();
        xerox.ilu.CStringHelper.id();
        U2Helper.id();
        O5Helper.id();
        ROHelper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new U3Helper(), org.omg.CORBA.TCKind.tk_union);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, U3 _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static U3 extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((U3)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(U3 _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = U3Helper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            U3Helper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static U3 from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        U3 _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = U3Helper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U3 _xx = ((U3)_x);
        return U3Helper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U3 _xx = ((U3)_x);
        U3Helper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return U3Helper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof U3);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
    public static int _szFunc(xerox.ilu.IluCall _call, U3 _a) 
        throws org.omg.CORBA.SystemException
    {
        int _sz;
         _sz = _call.szUnion(_a._dis.value(), xerox.ilu.IluTypeKind.enumeration_tk);
        switch(_a._dis.value()) {
            case TheE._ev1:
                _sz = _sz + _call.szString8(((java.lang.String)_a._val), 0);
                break;
            case TheE._ev3:
                _sz = _sz + U2Helper._szFunc(_call, ((U2)_a._val));
                break;
            case TheE._ev7:
                _sz = _sz + _call.szObject(((O5)_a._val), false, O5Stub.iluClass());
                break;
            default: 
                _sz = _sz + ROStub._szFunc(_call, ((TheR)_a._val));
                break;
        }
        _call.endUnion();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, U3 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (!_a._init) {throw new org.omg.CORBA.BAD_OPERATION();}
        _call.outUnion(_a._dis.value(), xerox.ilu.IluTypeKind.enumeration_tk);
        switch(_a._dis.value()) {
            case TheE._ev1:
                _call.outString8(((java.lang.String)_a._val), 0);
                break;
            case TheE._ev3:
                U2Helper._outFunc(_call, ((U2)_a._val));
                break;
            case TheE._ev7:
                _call.outObject(((O5)_a._val), false, O5Stub.iluClass());
                break;
            default: 
                ROStub._outFunc(_call, ((TheR)_a._val));
                break;
        }
        _call.endUnion();
    } //_outFunc

    public static U3 _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        U3 _v = null;
        TheE _d;
        _d = (TheE.from_int(_call.inUnion(xerox.ilu.IluTypeKind.enumeration_tk)));
        switch(_d.value()) {
            case TheE._ev1:
                _v = U3.alloc_xerox_ilu_CString(_d, _call.inString8(0));
                break;
            case TheE._ev3:
                _v = U3.alloc_U2(_d, U2Helper._inFunc(_call));
                break;
            case TheE._ev7:
                _v = U3.alloc_v3(_d, (O5) _call.inObject(false, O5Stub.iluClass()));
                break;
            default: 
                _v = U3.alloc_v4(_d, ROStub._inFunc(_call));
                break;
        }
        _call.endUnion();
        return _v;
    } //_inFunc

    static {
        int[] _ivals = null;
        java.lang.String[] _svals = null;
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerUnionType(
            "U3", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:cm4OUUbxSugq0XZxcQJOPsU8dtK", //uid
            "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh", //discriminatUID
            4, //cnt
            3, //defaultArm
            false, //othersAllowed
            xerox.ilu.IluConstantValueKind.enumeration_cvk); //valueKind
        U3Helper.id(); //loads helper class
        _svals = new java.lang.String[1];
        _svals[0] = "ev1";
        __t.registerUnionArm(
            0, //armNum
            null, //islArmName
            "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _svals = new java.lang.String[1];
        _svals[0] = "ev3";
        __t.registerUnionArm(
            1, //armNum
            null, //islArmName
            "ilut:dukhDTFh4mafbwdOi4H6sUK50Wu", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _svals = new java.lang.String[1];
        _svals[0] = "ev7";
        __t.registerUnionArm(
            2, //armNum
            "v3", //islArmName
            "IDL:Test1/O5:1.0", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _svals = new java.lang.String[0];
        __t.registerUnionArm(
            3, //armNum
            "v4", //islArmName
            "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", //armUID
            0, //valNum
            _ivals, //ivals
            _svals); //svals
        __t.finish();
        __t = null;
    } //static
}//U3Helper

