// javastubs/Test1/PS.java
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
 * Representing an ILU sequence type.
 */
public final class PS { 

    public static int _szFunc(xerox.ilu.IluCall _call, xerox.ilu.IluAny[] _v)
                throws org.omg.CORBA.SystemException {
        int _sz = _call.szSequence(_v.length, 0);
        for (int _i = 0; _i < _v.length; _i++) {
            _sz += _v[_i]._szAny(_call);
        }
        _call.endSequence();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, xerox.ilu.IluAny[] _v)
                throws org.omg.CORBA.SystemException {
        _call.outSequence(_v.length, 0);
        for (int _i = 0; _i < _v.length; _i++) {
            _v[_i]._outAny(_call);
        }
        _call.endSequence();
    } //_outFunc

    public static xerox.ilu.IluAny[] _inFunc(xerox.ilu.IluCall _call)
            throws org.omg.CORBA.SystemException {
        int _ln = _call.inSequence(0);
        xerox.ilu.IluAny[] _v = new xerox.ilu.IluAny[_ln];
        for (int _i = 0; _i < _ln; _i++) {
            _v[_i] = xerox.ilu.IluAny._inAny(_call);
        }
        _call.endSequence();
        return _v;
    } //_inFunc

    static{
        xerox.ilu.IluTypeRep.registerSequenceType(
            "PS", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:cwxcXxseM5ByCkx3dhm6UsMKHY4", //uid
            "ilut:irM650Q4ZJ3aqx9pgLzoj5Delco", //baseUID
            0); //limit
    }//static
} //PS
