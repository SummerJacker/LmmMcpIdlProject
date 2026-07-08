// javastubs/Test1/U4Helper.java
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
 * An ILU helper class.
 */
public class U4Helper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:iqhShhLIYYhlWJMKqapun2JReYg";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        O2Helper.id();
        CSSHelper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new U4Helper(), org.omg.CORBA.TCKind.tk_union);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, U4 _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static U4 extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((U4)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(U4 _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = U4Helper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            U4Helper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static U4 from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        U4 _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = U4Helper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U4 _xx = ((U4)_x);
        return U4Helper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U4 _xx = ((U4)_x);
        U4Helper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return U4Helper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof U4);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
    public static int _szFunc(xerox.ilu.IluCall _call, U4 _a) 
        throws org.omg.CORBA.SystemException
    {
        int _sz;
         _sz = _call.szUnion((int)_a._dis, xerox.ilu.IluTypeKind.shortinteger_tk);
        switch(_a._dis) {
            case (short)3:
            case (short)7:
                _sz = _sz + _call.szBool(((java.lang.Boolean)_a._val).booleanValue());
                break;
            default: 
                _sz = _sz + _call.szObject(((O2)_a._val), false, O2Stub.iluClass());
                break;
            case (short)1:
            case (short)0:
                _sz = _sz + CSS._szFunc(_call, ((java.lang.String[])_a._val));
                break;
        }
        _call.endUnion();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, U4 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (!_a._init) {throw new org.omg.CORBA.BAD_OPERATION();}
        _call.outUnion((int)_a._dis, xerox.ilu.IluTypeKind.shortinteger_tk);
        switch(_a._dis) {
            case (short)3:
            case (short)7:
                _call.outBool(((java.lang.Boolean)_a._val).booleanValue());
                break;
            default: 
                _call.outObject(((O2)_a._val), false, O2Stub.iluClass());
                break;
            case (short)1:
            case (short)0:
                CSS._outFunc(_call, ((java.lang.String[])_a._val));
                break;
        }
        _call.endUnion();
    } //_outFunc

    public static U4 _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        U4 _v = null;
        short _d;
        _d = (short)_call.inUnion(xerox.ilu.IluTypeKind.shortinteger_tk);
        switch(_d) {
            case (short)3:
            case (short)7:
                _v = U4.alloc_x1(_d, _call.inBool());
                break;
            default: 
                _v = U4.alloc_x2(_d, (O2) _call.inObject(false, O2Stub.iluClass()));
                break;
            case (short)1:
            case (short)0:
                _v = U4.alloc_x3(_d, CSS._inFunc(_call));
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
            "U4", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:iqhShhLIYYhlWJMKqapun2JReYg", //uid
            "ilut:fOLheADuTmKcJTSlmY16DQWP1YJ", //discriminatUID
            3, //cnt
            1, //defaultArm
            false, //othersAllowed
            xerox.ilu.IluConstantValueKind.shortinteger_cvk); //valueKind
        U4Helper.id(); //loads helper class
        _ivals = new int[2];
        _ivals[0] = (short)3;
        _ivals[1] = (short)7;
        __t.registerUnionArm(
            0, //armNum
            "x1", //islArmName
            "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", //armUID
            2, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[0];
        __t.registerUnionArm(
            1, //armNum
            "x2", //islArmName
            "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", //armUID
            0, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[2];
        _ivals[0] = (short)1;
        _ivals[1] = (short)0;
        __t.registerUnionArm(
            2, //armNum
            "x3", //islArmName
            "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", //armUID
            2, //valNum
            _ivals, //ivals
            _svals); //svals
        __t.finish();
        __t = null;
    } //static
}//U4Helper

