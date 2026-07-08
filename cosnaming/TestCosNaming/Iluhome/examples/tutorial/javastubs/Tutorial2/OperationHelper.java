// javastubs/Tutorial2/OperationHelper.java
// Stubs for "Tutorial2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:33 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial2.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Tutorial2;


/** 
 * An ILU helper class.
 */
public class OperationHelper implements xerox.ilu.IluIOFunctions  {
    private final static java.lang.String _id = 
        "ilut:bX2AOQprALQNZsoUQzMDW4OQG35";
    private static xerox.ilu.IluTypeCode _tc = null;
    static {
        xerox.ilu.IluPreLoad.checkStubConsistency13("v2 (2.0beta1)");
        OpTypeHelper.id();
        _tc = xerox.ilu.IluTypeCode.newTypeCode(id(), new OperationHelper(), org.omg.CORBA.TCKind.tk_struct);
    }

    public final static java.lang.String id() {
        return _id;
    } //id 

    public final static xerox.ilu.IluTypeCode type() {
        return _tc;
    } //type 

    public static void insert(org.omg.CORBA.Any _any, Operation _x) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        _ia.assign(_tc, _x);
    } //insert 

    public static Operation extract(org.omg.CORBA.Any _any) throws org.omg.CORBA.SystemException {
        xerox.ilu.IluAny _ia = (xerox.ilu.IluAny) _any;
        java.lang.Object _ob = _ia.cachedValue();
        if (_ob == null) {_ob = _ia.value(_tc);}
        return ((Operation)_ob);
    } //extract 

    public static xerox.ilu.IluPickle to_pickle(Operation _x) throws org.omg.CORBA.SystemException {
        int _sz = 0;
        xerox.ilu.IluCall _call = null;
        xerox.ilu.IluPickle _pickle = new xerox.ilu.IluPickle();
        try {
            _call = _pickle.startToPickle();
            _sz = OperationHelper._szFunc(_call, _x);
            _pickle.midToPickle(_call, _sz, id());
            OperationHelper._outFunc(_call, _x);
        } finally {
            _pickle.endToPickle(_call);
        }
        return _pickle;
    } //to_pickle 

    public static Operation from_pickle(xerox.ilu.IluPickle _pickle) throws org.omg.CORBA.SystemException {
        Operation _x = null;
        xerox.ilu.IluCall _call = null;
        try {
            _call = _pickle.startFromPickle(id());
            _x = OperationHelper._inFunc(_call);
        } finally {
            _pickle.endFromPickle(_call);
        }
        return _x;
    } //from_pickle 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public int szFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        Operation _xx = ((Operation)_x);
        return OperationHelper._szFunc(_call, _xx);
    } //szFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public void outFunc(xerox.ilu.IluCall _call, java.lang.Object _x, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        Operation _xx = ((Operation)_x);
        OperationHelper._outFunc(_call, _xx);
    } //outFunc 

    /** Not public; implements xerox.ilu.IluIOFunctions */
    public java.lang.Object inFunc(xerox.ilu.IluCall _call, xerox.ilu.IluTypeCode _tc) throws org.omg.CORBA.SystemException {
        return OperationHelper._inFunc(_call);
    } //inFunc 

    public boolean isAFunc(java.lang.Object _x, xerox.ilu.IluTypeCode _tc) {
        if (_x == null) return false;
        return (_x instanceof Operation);
    } //isAFunc 

    static {
        Tutorial2._allJavaStubs.load();
    }
    static {
        xerox.ilu.IluTypeRep __t = null;
        __t = xerox.ilu.IluTypeRep.registerRecordType(
            "Operation", //name
            "Tutorial2", //islIfName
            null, //islIfBrand
            "ilut:bX2AOQprALQNZsoUQzMDW4OQG35", //uid
            3 //cnt
            );
        __t.registerRecordField(0, "op", "ilut:pCUlWQIYicH3kzwh8PBwSxlbAMk");
        __t.registerRecordField(1, "value", "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP");
        __t.registerRecordField(2, "accumulator", "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP");
        __t.finish();
        __t = null;
    }

    //internal to ILU only
    public static int _szFunc(xerox.ilu.IluCall _call, Operation _r)
                throws org.omg.CORBA.SystemException {
        int _sz = _call.szRecord();
        _sz = _sz + _call.szEnum((_r.op).value());
        _sz = _sz + _call.szReal64(_r.value);
        _sz = _sz + _call.szReal64(_r.accumulator);
        _call.endRecord();
        return _sz;
    } //_szFunc

    //internal to ILU only
    public static void _outFunc(xerox.ilu.IluCall _call, Operation _r)
                throws org.omg.CORBA.SystemException {
        _call.outRecord();
        _call.outEnum((_r.op).value());
        _call.outReal64(_r.value);
        _call.outReal64(_r.accumulator);
        _call.endRecord();
    } //_outFunc

    //internal to ILU only
    public static Operation _inFunc(xerox.ilu.IluCall _call)
                throws org.omg.CORBA.SystemException {
        Operation _r = Operation.alloc_Operation();
        _call.inRecord();
        _r.op = OpType.from_int(_call.inEnum());
        _r.value = _call.inReal64();
        _r.accumulator = _call.inReal64();
        _call.endRecord();
        _r._touch();
        return _r;
    } //_inFunc

}//OperationHelper

