// javastubs/Test1/U_card.java
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
 * Class representing an ILU union type.
 */
public class U_card implements java.io.Serializable {
    boolean _init = false;
    int _dis = 0;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public U_card() {
        _init = false;
        _val = null;
    } //constructor

    public int discriminator()
                throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {
            _throw();
        }
        return _dis;
    } //discriminator

    public static U_card alloc_R(int _dis, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U_card _res = new U_card();
        _res.set_R(_dis, _v);
        return _res;
    } //alloc_R

    public static U_card alloc_R(TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_R(0, _v);
    } //alloc_R

    public TheR get_R()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case 0:
                break;
            default: 
                _throw();
        }
        return (TheR) ((TheR)_val);
    } //get_R

    public void set_R(int _d, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case 0:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_R

    public void set_R(TheR _v) {
        set_R(0, _v);
    } //set_R

    public static U_card alloc_O2(int _dis, O2 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U_card _res = new U_card();
        _res.set_O2(_dis, _v);
        return _res;
    } //alloc_O2

    public static U_card alloc_O2(O2 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_O2(1, _v);
    } //alloc_O2

    public O2 get_O2()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case 1:
                break;
            default: 
                _throw();
        }
        return (O2) ((O2)_val);
    } //get_O2

    public void set_O2(int _d, O2 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case 1:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_O2

    public void set_O2(O2 _v) {
        set_O2(1, _v);
    } //set_O2

} //U_card
