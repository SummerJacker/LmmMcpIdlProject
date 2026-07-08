// javastubs/Test2/U2Helper.java
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
public class U2Helper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:dSc47PlWucPws3UX8kBfzRQVxyF";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        Test1.TheEHelper.id();
        xerox.ilu.CStringHelper.id();
        Test1.O1Helper.id();
        PHelper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new U2Helper(), org.omg.CORBA.TCKind.tk_union);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, U2 _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static U2 extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((U2)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(U2 _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = U2Helper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            U2Helper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static U2 from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        U2 _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = U2Helper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U2 _xx = ((U2)_x);
        return U2Helper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U2 _xx = ((U2)_x);
        U2Helper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return U2Helper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof U2);
    } //isAFunc 

    static {
        Test2._allJavaStubs.load();
    }
    public static int _szFunc(xerox.ilu.IluCall _call, U2 _a) 
        throws org.omg.CORBA.SystemException
    {
        int _sz;
         _sz = _call.szUnion(_a._dis.value(), xerox.ilu.IluTypeKind.enumeration_tk);
        switch(_a._dis.value()) {
            case Test1.TheE._ev1:
                _sz = _sz + _call.szString8(((java.lang.String)_a._val), 0);
                break;
            case Test1.TheE._ev3:
                _sz = _sz + _call.szObject(((Test1.TheO1)_a._val), false, Test1.TheO1Stub.iluClass());
                break;
            case Test1.TheE._ev7:
                _sz = _sz + _call.szObject(((P)_a._val), false, PStub.iluClass());
                break;
        }
        _call.endUnion();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, U2 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (!_a._init) {throw new org.omg.CORBA.BAD_OPERATION();}
        _call.outUnion(_a._dis.value(), xerox.ilu.IluTypeKind.enumeration_tk);
        switch(_a._dis.value()) {
            case Test1.TheE._ev1:
                _call.outString8(((java.lang.String)_a._val), 0);
                break;
            case Test1.TheE._ev3:
                _call.outObject(((Test1.TheO1)_a._val), false, Test1.TheO1Stub.iluClass());
                break;
            case Test1.TheE._ev7:
                _call.outObject(((P)_a._val), false, PStub.iluClass());
                break;
        }
        _call.endUnion();
    } //_outFunc

    public static U2 _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        U2 _v = null;
        Test1.TheE _d;
        _d = (Test1.TheE.from_int(_call.inUnion(xerox.ilu.IluTypeKind.enumeration_tk)));
        switch(_d.value()) {
            case Test1.TheE._ev1:
                _v = U2.alloc_xerox_ilu_CString(_d, _call.inString8(0));
                break;
            case Test1.TheE._ev3:
                _v = U2.alloc_Test1_O1(_d, (Test1.TheO1) _call.inObject(false, Test1.TheO1Stub.iluClass()));
                break;
            case Test1.TheE._ev7:
                _v = U2.alloc_P(_d, (P) _call.inObject(false, PStub.iluClass()));
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
            "U2", //name
            "Test2", //islIfName
            null, //islIfBrand
            "ilut:dSc47PlWucPws3UX8kBfzRQVxyF", //uid
            "ilut:krAAJGDr0mWg96aGb8cRAqq6LEh", //discriminatUID
            3, //cnt
            -1, //defaultArm
            false, //othersAllowed
            xerox.ilu.IluConstantValueKind.enumeration_cvk); //valueKind
        U2Helper.id(); //loads helper class
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
            "ilut:fmBFu4mQpwjov+CekDxhjwxkgty", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _svals = new java.lang.String[1];
        _svals[0] = "ev7";
        __t.registerUnionArm(
            2, //armNum
            null, //islArmName
            "ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        __t.finish();
        __t = null;
    } //static
}//U2Helper

