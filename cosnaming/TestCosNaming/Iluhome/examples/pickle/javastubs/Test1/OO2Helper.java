// javastubs/Test1/OO2Helper.java
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
public class OO2Helper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:bh0wBMfkMH0UEIMcVf-O+gTohAr";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        O5Helper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new OO2Helper(), org.omg.CORBA.TCKind.tk_union);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, OO2 _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static OO2 extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((OO2)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(OO2 _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = OO2Helper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            OO2Helper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static OO2 from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        OO2 _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = OO2Helper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        OO2 _xx = ((OO2)_x);
        return OO2Helper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        OO2 _xx = ((OO2)_x);
        OO2Helper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return OO2Helper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof OO2);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
    public static int _szFunc(xerox.ilu.IluCall _call, OO2 _a) 
        throws org.omg.CORBA.SystemException
    {
        int _sz;
         _sz = _call.szUnion((_a._dis ? 1 : 0), xerox.ilu.IluTypeKind.boolean_tk);
        if(_a._dis) {
            _sz = _sz + _call.szObject(((O5)_a._val), false, O5Stub.iluClass());
        } else {
        }
        _call.endUnion();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, OO2 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (!_a._init) {throw new org.omg.CORBA.BAD_OPERATION();}
        _call.outUnion((_a._dis ? 1 : 0), xerox.ilu.IluTypeKind.boolean_tk);
        if(_a._dis) {
            _call.outObject(((O5)_a._val), false, O5Stub.iluClass());
        } else {
        }
        _call.endUnion();
    } //_outFunc

    public static OO2 _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        OO2 _v = null;
        boolean _d;
        _d = (_call.inUnion(xerox.ilu.IluTypeKind.boolean_tk) == 1);
        if(_d) {
            _v = OO2.alloc_O5(true, (O5) _call.inObject(false, O5Stub.iluClass()));
        } else {
              _v = OO2.allocOther(_d);
        }
        _call.endUnion();
        return _v;
    } //_inFunc

    static {
        int[] _ivals = null;
        java.lang.String[] _svals = null;
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerUnionType(
            "OO2", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:bh0wBMfkMH0UEIMcVf-O+gTohAr", //uid
            "ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I", //discriminatUID
            1, //cnt
            -1, //defaultArm
            true, //othersAllowed
            xerox.ilu.IluConstantValueKind.boolean_cvk); //valueKind
        OO2Helper.id(); //loads helper class
        _ivals = new int[1];
        _ivals[0] = 1;
        __t.registerUnionArm(
            0, //armNum
            null, //islArmName
            "IDL:Test1/O5:1.0", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        __t.finish();
        __t = null;
    } //static
}//OO2Helper

