// javastubs/Test1/TheA1.java
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
public final class TheA1 { 
  public static int szFunc(xerox.ilu.IluCall _call, java.lang.String[] _value)
    throws org.omg.CORBA.SystemException {
        int _size = _call.szArray(3);
        for (int _i0 = 0; _i0 < 3; _i0++) {
            _size += _call.szString8(_value[_i0], 0);
        }
    _call.endArray();
    return _size;
  }

  public static void outFunc(xerox.ilu.IluCall _call, java.lang.String[] _value)
    throws org.omg.CORBA.SystemException {
        _call.outArray(3);
        if (_value.length != 3)
            throw new org.omg.CORBA.BAD_PARAM("bad array length");
        for (int _i0 = 0; _i0 < 3; _i0++) {
                        _call.outString8(_value[_i0], 0);
        }
    _call.endArray();
  }

  public static java.lang.String[] inFunc(xerox.ilu.IluCall _call)
    throws org.omg.CORBA.SystemException {
    _call.inArray();
    java.lang.String[] _value = new java.lang.String[3];
    for (int _i0 = 0; _i0 < 3; _i0++)
        _value[_i0] = _call.inString8(0);
    _call.endArray();
    return _value;
  }

    static{
        int[] dims = new int[1];
        dims[0] = 3;
        xerox.ilu.IluTypeRep.registerArrayType(
            "TheA1", //name
            "Test1", //islIfName
            null, //islIfBrand
            "ilut:h3Dnvis94UwnmFURfYsCp700jVy", //uid
            "ilut:iqqhSf395+BafbY8Oo2elFQD1bK", //baseUID
            1, //dimcnt
            dims); //dims
    }//static
}// TheA1
