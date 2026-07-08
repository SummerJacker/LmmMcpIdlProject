// javastubs/Tutorial2/RegisterTape.java
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
 * Representing an ILU sequence type.
 */
public final class RegisterTape { 

    public static int _szFunc(xerox.ilu.IluCall _call, Operation[] _v)
                throws org.omg.CORBA.SystemException {
        int _sz = _call.szSequence(_v.length, 0);
        for (int _i = 0; _i < _v.length; _i++) {
            _sz += OperationHelper._szFunc(_call, _v[_i]);
        }
        _call.endSequence();
        return _sz;
    } //_szFunc

    public static void _outFunc(xerox.ilu.IluCall _call, Operation[] _v)
                throws org.omg.CORBA.SystemException {
        _call.outSequence(_v.length, 0);
        for (int _i = 0; _i < _v.length; _i++) {
            OperationHelper._outFunc(_call, _v[_i]);
        }
        _call.endSequence();
    } //_outFunc

    public static Operation[] _inFunc(xerox.ilu.IluCall _call)
            throws org.omg.CORBA.SystemException {
        int _ln = _call.inSequence(0);
        Operation[] _v = new Operation[_ln];
        for (int _i = 0; _i < _ln; _i++) {
            _v[_i] = OperationHelper._inFunc(_call);
        }
        _call.endSequence();
        return _v;
    } //_inFunc

    static{
        xerox.ilu.IluTypeRep.registerSequenceType(
            "RegisterTape", //name
            "Tutorial2", //islIfName
            null, //islIfBrand
            "ilut:i03-tJkWBPLHe2ONK6OHat-LDSV", //uid
            "ilut:bX2AOQprALQNZsoUQzMDW4OQG35", //baseUID
            0); //limit
    }//static
} //RegisterTape
