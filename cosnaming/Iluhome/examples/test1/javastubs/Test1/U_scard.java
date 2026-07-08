// javastubs/Test1/U_scard.java
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
public class U_scard implements java.io.Serializable {
    boolean _init = false;
    short _dis = 0;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public U_scard() {
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

    public static U_scard alloc_R(short _dis, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U_scard _res = new U_scard();
        _res.set_R(_dis, _v);
        return _res;
    } //alloc_R

    public static U_scard alloc_R(TheR _v)
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

    public static U_scard alloc_One(short _dis, TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U_scard _res = new U_scard();
        _res.set_One(_dis, _v);
        return _res;
    } //alloc_One

    public static U_scard alloc_One(TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_One((short)1, _v);
    } //alloc_One

    public TheO1 get_One()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)1:
                break;
            default: 
                _throw();
        }
        return (TheO1) ((TheO1)_val);
    } //get_One

    public void set_One(short _d, TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)1:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_One

    public void set_One(TheO1 _v) {
        set_One((short)1, _v);
    } //set_One

} //U_scard
