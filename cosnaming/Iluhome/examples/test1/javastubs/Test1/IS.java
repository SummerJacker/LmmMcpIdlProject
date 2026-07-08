// javastubs/Test1/IS.java
// Stubs for "Test1"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test1;


/** 
 * Representing an ILU sequence type.
 */
public final class IS { 

    public static int _szFunc(xerox.ilu.IluCall _call, int[] _v)
                throws org.omg.CORBA.SystemException {
        int _sz = _call.szSequence(_v.length, 0);
        for (int _i = 0; _i < _v.length; _i++) {
            _sz += _call.szInt32(_v[_i]);
        }
        _call.endSequence();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, int[] _v)
                throws org.omg.CORBA.SystemException {
        _call.outSequence(_v.length, 0);
        for (int _i = 0; _i < _v.length; _i++) {
            _call.outInt32(_v[_i]);
        }
        _call.endSequence();
    } //_outFunc

    public static int[] _inFunc(xerox.ilu.IluCall _call)
            throws org.omg.CORBA.SystemException {
        int _ln = _call.inSequence(0);
        int[] _v = new int[_ln];
        for (int _i = 0; _i < _ln; _i++) {
            _v[_i] = _call.inInt32();
        }
        _call.endSequence();
        return _v;
    } //_inFunc

    static{
        xerox.ilu.IluTypeRep.registerSequenceType(
            "IS", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO", //uid
            "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", //baseUID
            0); //limit
    }//static
} //IS
