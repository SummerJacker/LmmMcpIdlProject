// javastubs/Test1/TheUHelper.java
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
public class TheUHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:fIKxCkK+Cv1UWMLpSt0opzwBMuC";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        RHelper.id();
        ROHelper.id();
        CSSHelper.id();
        O5Helper.id();
        OOHelper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new TheUHelper(), org.omg.CORBA.TCKind.tk_union);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, TheU _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static TheU extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((TheU)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(TheU _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = TheUHelper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            TheUHelper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static TheU from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        TheU _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = TheUHelper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        TheU _xx = ((TheU)_x);
        return TheUHelper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        TheU _xx = ((TheU)_x);
        TheUHelper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return TheUHelper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof TheU);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
    public static int _szFunc(xerox.ilu.IluCall _call, TheU _a) 
        throws org.omg.CORBA.SystemException
    {
        int _sz;
         _sz = _call.szUnion((int)_a._dis, xerox.ilu.IluTypeKind.shortinteger_tk);
        switch(_a._dis) {
            case (short)0:
                _sz = _sz + TheRHelper._szFunc(_call, ((TheR)_a._val));
                break;
            case (short)1:
                _sz = _sz + ROStub._szFunc(_call, ((TheR)_a._val));
                break;
            case (short)2:
                _sz = _sz + CSS._szFunc(_call, ((java.lang.String[])_a._val));
                break;
            case (short)3:
                _sz = _sz + _call.szObject(((O5)_a._val), false, O5Stub.iluClass());
                break;
            case (short)4:
                _sz = _sz + TheOOStub._szFunc(_call, ((O5)_a._val));
                break;
            case (short)5:
                _sz = _sz + _call.szBool(((java.lang.Boolean)_a._val).booleanValue());
                break;
        }
        _call.endUnion();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, TheU _a) 
        throws org.omg.CORBA.SystemException
    {
        if (!_a._init) {throw new org.omg.CORBA.BAD_OPERATION();}
        _call.outUnion((int)_a._dis, xerox.ilu.IluTypeKind.shortinteger_tk);
        switch(_a._dis) {
            case (short)0:
                TheRHelper._outFunc(_call, ((TheR)_a._val));
                break;
            case (short)1:
                ROStub._outFunc(_call, ((TheR)_a._val));
                break;
            case (short)2:
                CSS._outFunc(_call, ((java.lang.String[])_a._val));
                break;
            case (short)3:
                _call.outObject(((O5)_a._val), false, O5Stub.iluClass());
                break;
            case (short)4:
                TheOOStub._outFunc(_call, ((O5)_a._val));
                break;
            case (short)5:
                _call.outBool(((java.lang.Boolean)_a._val).booleanValue());
                break;
        }
        _call.endUnion();
    } //_outFunc

    public static TheU _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        TheU _v = null;
        short _d;
        _d = (short)_call.inUnion(xerox.ilu.IluTypeKind.shortinteger_tk);
        switch(_d) {
            case (short)0:
                _v = TheU.alloc_R(_d, TheRHelper._inFunc(_call));
                break;
            case (short)1:
                _v = TheU.alloc_RO(_d, ROStub._inFunc(_call));
                break;
            case (short)2:
                _v = TheU.alloc_CSS(_d, CSS._inFunc(_call));
                break;
            case (short)3:
                _v = TheU.alloc_O5(_d, (O5) _call.inObject(false, O5Stub.iluClass()));
                break;
            case (short)4:
                _v = TheU.alloc_OO(_d, TheOOStub._inFunc(_call));
                break;
            case (short)5:
                _v = TheU.alloc__boolean(_d, _call.inBool());
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
            "TheU", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:fIKxCkK+Cv1UWMLpSt0opzwBMuC", //uid
            "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", //discriminatUID
            6, //cnt
            -1, //defaultArm
            false, //othersAllowed
            xerox.ilu.IluConstantValueKind.shortinteger_cvk); //valueKind
        TheUHelper.id(); //loads helper class
        _ivals = new int[1];
        _ivals[0] = (short)0;
        __t.registerUnionArm(
            0, //armNum
            null, //islArmName
            "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[1];
        _ivals[0] = (short)1;
        __t.registerUnionArm(
            1, //armNum
            null, //islArmName
            "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[1];
        _ivals[0] = (short)2;
        __t.registerUnionArm(
            2, //armNum
            null, //islArmName
            "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[1];
        _ivals[0] = (short)3;
        __t.registerUnionArm(
            3, //armNum
            null, //islArmName
            "IDL:Test1/O5:1.0", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[1];
        _ivals[0] = (short)4;
        __t.registerUnionArm(
            4, //armNum
            null, //islArmName
            "ilut:kpovP3jt0mWKroAd3v+z9qwsgeL", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[1];
        _ivals[0] = (short)5;
        __t.registerUnionArm(
            5, //armNum
            null, //islArmName
            "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        __t.finish();
        __t = null;
    } //static
}//TheUHelper

