// javastubs/Test1/TheU.java
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
public class TheU implements java.io.Serializable {
    boolean _init = false;
    short _dis = 0;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public TheU() {
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

    public static TheU alloc_R(short _dis, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        TheU _res = new TheU();
        _res.set_R(_dis, _v);
        return _res;
    } //alloc_R

    public static TheU alloc_R(TheR _v)
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

    public static TheU alloc_RO(short _dis, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        TheU _res = new TheU();
        _res.set_RO(_dis, _v);
        return _res;
    } //alloc_RO

    public static TheU alloc_RO(TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_RO((short)1, _v);
    } //alloc_RO

    public TheR get_RO()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)1:
                break;
            default: 
                _throw();
        }
        return (TheR) ((TheR)_val);
    } //get_RO

    public void set_RO(short _d, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)1:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_RO

    public void set_RO(TheR _v) {
        set_RO((short)1, _v);
    } //set_RO

    public static TheU alloc_CSS(short _dis, java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        TheU _res = new TheU();
        _res.set_CSS(_dis, _v);
        return _res;
    } //alloc_CSS

    public static TheU alloc_CSS(java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_CSS((short)2, _v);
    } //alloc_CSS

    public java.lang.String[] get_CSS()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)2:
                break;
            default: 
                _throw();
        }
        return (java.lang.String[]) ((java.lang.String[])_val);
    } //get_CSS

    public void set_CSS(short _d, java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)2:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_CSS

    public void set_CSS(java.lang.String[] _v) {
        set_CSS((short)2, _v);
    } //set_CSS

    public static TheU alloc_O1(short _dis, TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        TheU _res = new TheU();
        _res.set_O1(_dis, _v);
        return _res;
    } //alloc_O1

    public static TheU alloc_O1(TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_O1((short)3, _v);
    } //alloc_O1

    public TheO1 get_O1()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)3:
                break;
            default: 
                _throw();
        }
        return (TheO1) ((TheO1)_val);
    } //get_O1

    public void set_O1(short _d, TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)3:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_O1

    public void set_O1(TheO1 _v) {
        set_O1((short)3, _v);
    } //set_O1

    public static TheU alloc_OO(short _dis, TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        TheU _res = new TheU();
        _res.set_OO(_dis, _v);
        return _res;
    } //alloc_OO

    public static TheU alloc_OO(TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_OO((short)4, _v);
    } //alloc_OO

    public TheO1 get_OO()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)4:
                break;
            default: 
                _throw();
        }
        return (TheO1) ((TheO1)_val);
    } //get_OO

    public void set_OO(short _d, TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)4:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_OO

    public void set_OO(TheO1 _v) {
        set_OO((short)4, _v);
    } //set_OO

    public static TheU alloc__boolean(short _dis, boolean _v)
            throws org.omg.CORBA.BAD_OPERATION {
        TheU _res = new TheU();
        _res.set__boolean(_dis, _v);
        return _res;
    } //alloc__boolean

    public static TheU alloc__boolean(boolean _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc__boolean((short)5, _v);
    } //alloc__boolean

    public boolean get__boolean()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)5:
                break;
            default: 
                _throw();
        }
        return (boolean) ((java.lang.Boolean)_val).booleanValue();
    } //get__boolean

    public void set__boolean(short _d, boolean _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)5:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = new java.lang.Boolean(_v);
        _init = true;
    } //set__boolean

    public void set__boolean(boolean _v) {
        set__boolean((short)5, _v);
    } //set__boolean

} //TheU
