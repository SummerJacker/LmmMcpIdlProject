// javastubs/Test3/FU.java
// Stubs for "Test3"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test3;


/** 
 * Class representing an ILU union type.
 */
public class FU implements java.io.Serializable {
    boolean _init = false;
    Test1.TheE _dis = null;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public FU() {
        _init = false;
        _val = null;
    } //constructor

    public Test1.TheE discriminator()
                throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {
            _throw();
        }
        return _dis;
    } //discriminator

    public static FU alloc_O(Test1.TheE _dis, O _v)
            throws org.omg.CORBA.BAD_OPERATION {
        FU _res = new FU();
        _res.set_O(_dis, _v);
        return _res;
    } //alloc_O

    public static FU alloc_O(O _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_O(Test1.TheE.ev1, _v);
    } //alloc_O

    public O get_O()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case Test1.TheE._ev1:
                break;
            default: 
                _throw();
        }
        return (O) ((O)_val);
    } //get_O

    public void set_O(Test1.TheE _d, O _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case Test1.TheE._ev1:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_O

    public void set_O(O _v) {
        set_O(Test1.TheE.ev1, _v);
    } //set_O

    public static FU alloc_integer(Test1.TheE _dis, int _v)
            throws org.omg.CORBA.BAD_OPERATION {
        FU _res = new FU();
        _res.set_integer(_dis, _v);
        return _res;
    } //alloc_integer

    public static FU alloc_integer(int _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_integer(Test1.TheE.ev3, _v);
    } //alloc_integer

    public int get_integer()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case Test1.TheE._ev3:
                break;
            default: 
                _throw();
        }
        return (int) ((java.lang.Number)_val).intValue();
    } //get_integer

    public void set_integer(Test1.TheE _d, int _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case Test1.TheE._ev3:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = new java.lang.Integer(_v);
        _init = true;
    } //set_integer

    public void set_integer(int _v) {
        set_integer(Test1.TheE.ev3, _v);
    } //set_integer

} //FU
