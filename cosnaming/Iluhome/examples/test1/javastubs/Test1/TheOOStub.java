// javastubs/Test1/TheOOStub.java
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
 * Helper class for an ILU otional type.
 */
public final class TheOOStub { //ilu-otional

    public static int _szFunc(xerox.ilu.IluCall _call, TheO1 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (_a==null) {
            return _call.szOptional(false);
        } else {
            return _call.szOptional(true) + _call.szObject(((TheO1)_a), false, TheO1Stub.iluClass());
        }
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, TheO1 _a) 
        throws org.omg.CORBA.SystemException
    {
        if (_a==null) {
            _call.outOptional(false);
        } else {
            _call.outOptional(true);
            _call.outObject(((TheO1)_a), false, TheO1Stub.iluClass());
        }
    } //_outFunc

    public static TheO1 _inFunc(xerox.ilu.IluCall _call) 
        throws org.omg.CORBA.SystemException
    {
        if (_call.inOptional()) {
            return (TheO1) _call.inObject(false, TheO1Stub.iluClass());
        } else {
            return (null);
        }
    } //_inFunc

    static {
        xerox.ilu.IluTypeRep __t = xerox.ilu.IluTypeRep.registerOptionalType(
            "TheOO", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA", //uid
            "ilut:fmBFu4mQpwjov+CekDxhjwxkgty"); //baseUID
    } //static
} //TheOOStub
