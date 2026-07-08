// javastubs/Test1/TheOOStub.java
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
 * Helper class for an ILU otional type.
 */
public final class TheOOStub { //ilu-otional

    public static int _szFunc(xerox.ilu.IluCall _call, O5 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (_a==null) {
            return _call.szOptional(false);
        } else {
            return _call.szOptional(true) + _call.szObject(((O5)_a), false, O5Stub.iluClass());
        }
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, O5 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (_a==null) {
            _call.outOptional(false);
        } else {
            _call.outOptional(true);
            _call.outObject(((O5)_a), false, O5Stub.iluClass());
        }
    } //_outFunc

    public static O5 _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        if (_call.inOptional()) {
            return (O5) _call.inObject(false, O5Stub.iluClass());
        } else {
            return (null);
        }
    } //_inFunc

    static {
        xerox.ilu.IluTypeRep __t = xerox.ilu.IluTypeRep.registerOptionalType(
            "TheOO", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:kpovP3jt0mWKroAd3v+z9qwsgeL", //uid
            "IDL:Test1/O5:1.0"); //baseUID
    } //static
} //TheOOStub
