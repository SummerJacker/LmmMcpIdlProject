// javastubs/Test1/A2.java
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
 * Class representing an ILU array type.
 */
public final class A2 { 
  public static int szFunc(xerox.ilu.IluCall _call, int[][] _value)
    throws org.omg.CORBA.SystemException {
        int _size = _call.szArray(12);
        for (int _i0 = 0; _i0 < 3; _i0++) {
            for (int _i1 = 0; _i1 < 4; _i1++) {
                _size += _call.szCard32(_value[_i0][_i1]);
            }
        }
    _call.endArray();
    return _size;
  }

  public static void outFunc(xerox.ilu.IluCall _call, int[][] _value)
    throws org.omg.CORBA.SystemException {
        _call.outArray(12);
        if (_value.length != 3)
            throw new org.omg.CORBA.BAD_PARAM("bad array length");
        for (int _i0 = 0; _i0 < 3; _i0++) {
                        if (_value[_i0].length != 4)
                throw new org.omg.CORBA.BAD_PARAM("bad array length");
            for (int _i1 = 0; _i1 < 4; _i1++) {
                                _call.outCard32(_value[_i0][_i1]);
            }
        }
    _call.endArray();
  }

  public static int[][] inFunc(xerox.ilu.IluCall _call)
    throws org.omg.CORBA.SystemException {
    _call.inArray();
    int[][] _value = new int[3][4];
    for (int _i0 = 0; _i0 < 3; _i0++)
        for (int _i1 = 0; _i1 < 4; _i1++)
            _value[_i0][_i1] = _call.inCard32();
    _call.endArray();
    return _value;
  }

    static{
        int[] dims = new int[2];
        dims[0] = 3;
        dims[1] = 4;
        xerox.ilu.IluTypeRep.registerArrayType(
            "A2", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:kM2HH51HMYTWu-khgczpbgNaama", //uid
            "ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO", //baseUID
            2, //dimcnt
            dims); //dims
    }//static
}// A2
