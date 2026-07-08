// javastubs/Test1/U1.java
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
public class U1 implements java.io.Serializable {
    boolean _init = false;
    short _dis = 0;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public U1() {
        _init = false;
        _val = null;
    } //constructor

    public short discriminator()
                throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {
            _throw();
        }
        return _dis;
    } //discriminator

    public static U1 alloc_R(short _dis, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U1 _res = new U1();
        _res.set_R(_dis, _v);
        return _res;
    } //alloc_R

    public static U1 alloc_R(TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_R((short)0, _v);
    } //alloc_R

    public TheR get_R()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)0:
                break;
            default: 
                _throw();
        }
        return (TheR) ((TheR)_val);
    } //get_R

    public void set_R(short _d, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)0:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_R

    public void set_R(TheR _v) {
        set_R((short)0, _v);
    } //set_R

    public static U1 alloc_A1(short _dis, java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U1 _res = new U1();
        _res.set_A1(_dis, _v);
        return _res;
    } //alloc_A1

    public static U1 alloc_A1(java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_A1((short)1, _v);
    } //alloc_A1

    public java.lang.String[] get_A1()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)1:
                break;
            default: 
                _throw();
        }
        return (java.lang.String[]) ((java.lang.String[])_val);
    } //get_A1

    public void set_A1(short _d, java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)1:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_A1

    public void set_A1(java.lang.String[] _v) {
        set_A1((short)1, _v);
    } //set_A1

} //U1
