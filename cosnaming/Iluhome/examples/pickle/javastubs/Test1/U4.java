// javastubs/Test1/U4.java
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
 * Class representing an ILU union type.
 */
public class U4 implements java.io.Serializable {
    boolean _init = false;
    short _dis = 0;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public U4() {
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

    public static U4 alloc_x1(short _dis, boolean _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U4 _res = new U4();
        _res.set_x1(_dis, _v);
        return _res;
    } //alloc_x1

    public static U4 alloc_x1(boolean _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_x1((short)3, _v);
    } //alloc_x1

    public boolean get_x1()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)3:
            case (short)7:
                break;
            default: 
                _throw();
        }
        return (boolean) ((java.lang.Boolean)_val).booleanValue();
    } //get_x1

    public void set_x1(short _d, boolean _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)3:
            case (short)7:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = new java.lang.Boolean(_v);
        _init = true;
    } //set_x1

    public void set_x1(boolean _v) {
        set_x1((short)3, _v);
    } //set_x1

    public static U4 alloc_x2(short _dis, O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U4 _res = new U4();
        _res.set_x2(_dis, _v);
        return _res;
    } //alloc_x2

    public O5 get_x2()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)3:
            case (short)7:
            case (short)1:
            case (short)0:
                _throw();
            default: break;
        }
        return (O5) ((O5)_val);
    } //get_x2

    public void set_x2(short _d, O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)3:
            case (short)7:
            case (short)1:
            case (short)0:
                _throw();
            default:
                break;
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_x2

    public static U4 alloc_x3(short _dis, java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U4 _res = new U4();
        _res.set_x3(_dis, _v);
        return _res;
    } //alloc_x3

    public static U4 alloc_x3(java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_x3((short)1, _v);
    } //alloc_x3

    public java.lang.String[] get_x3()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis) {
            case (short)1:
            case (short)0:
                break;
            default: 
                _throw();
        }
        return (java.lang.String[]) ((java.lang.String[])_val);
    } //get_x3

    public void set_x3(short _d, java.lang.String[] _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d) {
            case (short)1:
            case (short)0:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_x3

    public void set_x3(java.lang.String[] _v) {
        set_x3((short)1, _v);
    } //set_x3

} //U4
