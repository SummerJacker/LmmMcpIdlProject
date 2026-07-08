// javastubs/Test1/U_byteHelper.java
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
public class U_byteHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:eEo4ZOFawZcut8dv19+C65eQlWg";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        RHelper.id();
        O2Helper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new U_byteHelper(), org.omg.CORBA.TCKind.tk_union);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, U_byte _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static U_byte extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((U_byte)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(U_byte _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = U_byteHelper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            U_byteHelper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static U_byte from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        U_byte _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = U_byteHelper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U_byte _xx = ((U_byte)_x);
        return U_byteHelper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        U_byte _xx = ((U_byte)_x);
        U_byteHelper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return U_byteHelper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof U_byte);
    } //isAFunc 

    static {
        Test1._allJavaStubs.load();
    }
    public static int _szFunc(xerox.ilu.IluCall _call, U_byte _a) 
        throws org.omg.CORBA.SystemException
    {
        int _sz;
         _sz = _call.szUnion((int)_a._dis, xerox.ilu.IluTypeKind.byte_tk);
        switch(_a._dis) {
            case (byte)0:
                _sz = _sz + TheRHelper._szFunc(_call, ((TheR)_a._val));
                break;
            case (byte)1:
                _sz = _sz + _call.szObject(((O2)_a._val), false, O2Stub.iluClass());
                break;
        }
        _call.endUnion();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, U_byte _a) 
        throws org.omg.CORBA.SystemException
    {
        if (!_a._init) {throw new org.omg.CORBA.BAD_OPERATION();}
        _call.outUnion((int)_a._dis, xerox.ilu.IluTypeKind.byte_tk);
        switch(_a._dis) {
            case (byte)0:
                TheRHelper._outFunc(_call, ((TheR)_a._val));
                break;
            case (byte)1:
                _call.outObject(((O2)_a._val), false, O2Stub.iluClass());
                break;
        }
        _call.endUnion();
    } //_outFunc

    public static U_byte _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        U_byte _v = null;
        byte _d;
        _d = (byte)_call.inUnion(xerox.ilu.IluTypeKind.byte_tk);
        switch(_d) {
            case (byte)0:
                _v = U_byte.alloc_R(_d, TheRHelper._inFunc(_call));
                break;
            case (byte)1:
                _v = U_byte.alloc_O2(_d, (O2) _call.inObject(false, O2Stub.iluClass()));
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
            "U-byte", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:eEo4ZOFawZcut8dv19+C65eQlWg", //uid
            "ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc", //discriminatUID
            2, //cnt
            -1, //defaultArm
            false, //othersAllowed
            xerox.ilu.IluConstantValueKind.byte_cvk); //valueKind
        U_byteHelper.id(); //loads helper class
        _ivals = new int[1];
        _ivals[0] = (byte)0;
        __t.registerUnionArm(
            0, //armNum
            null, //islArmName
            "ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        _ivals = new int[1];
        _ivals[0] = (byte)1;
        __t.registerUnionArm(
            1, //armNum
            null, //islArmName
            "ilut:hixrYb3gOsoXrLnWuqHZQZ+oSYc", //armUID
            1, //valNum
            _ivals, //ivals
            _svals); //svals
        __t.finish();
        __t = null;
    } //static
}//U_byteHelper

