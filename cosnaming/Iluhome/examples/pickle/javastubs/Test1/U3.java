// javastubs/Test1/U3.java
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
public class U3 implements java.io.Serializable {
    boolean _init = false;
    TheE _dis = null;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public U3() {
        _init = false;
        _val = null;
    } //constructor

    public TheE discriminator()
                throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {
            _throw();
        }
        return _dis;
    } //discriminator

    public static U3 alloc_xerox_ilu_CString(TheE _dis, java.lang.String _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U3 _res = new U3();
        _res.set_xerox_ilu_CString(_dis, _v);
        return _res;
    } //alloc_xerox_ilu_CString

    public static U3 alloc_xerox_ilu_CString(java.lang.String _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_xerox_ilu_CString(TheE.ev1, _v);
    } //alloc_xerox_ilu_CString

    public java.lang.String get_xerox_ilu_CString()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case TheE._ev1:
                break;
            default: 
                _throw();
        }
        return (java.lang.String) ((java.lang.String)_val);
    } //get_xerox_ilu_CString

    public void set_xerox_ilu_CString(TheE _d, java.lang.String _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case TheE._ev1:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_xerox_ilu_CString

    public void set_xerox_ilu_CString(java.lang.String _v) {
        set_xerox_ilu_CString(TheE.ev1, _v);
    } //set_xerox_ilu_CString

    public static U3 alloc_U2(TheE _dis, U2 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U3 _res = new U3();
        _res.set_U2(_dis, _v);
        return _res;
    } //alloc_U2

    public static U3 alloc_U2(U2 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_U2(TheE.ev3, _v);
    } //alloc_U2

    public U2 get_U2()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case TheE._ev3:
                break;
            default: 
                _throw();
        }
        return (U2) ((U2)_val);
    } //get_U2

    public void set_U2(TheE _d, U2 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case TheE._ev3:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_U2

    public void set_U2(U2 _v) {
        set_U2(TheE.ev3, _v);
    } //set_U2

    public static U3 alloc_v3(TheE _dis, O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U3 _res = new U3();
        _res.set_v3(_dis, _v);
        return _res;
    } //alloc_v3

    public static U3 alloc_v3(O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_v3(TheE.ev7, _v);
    } //alloc_v3

    public O5 get_v3()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case TheE._ev7:
                break;
            default: 
                _throw();
        }
        return (O5) ((O5)_val);
    } //get_v3

    public void set_v3(TheE _d, O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case TheE._ev7:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_v3

    public void set_v3(O5 _v) {
        set_v3(TheE.ev7, _v);
    } //set_v3

    public static U3 alloc_v4(TheE _dis, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U3 _res = new U3();
        _res.set_v4(_dis, _v);
        return _res;
    } //alloc_v4

    public TheR get_v4()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case TheE._ev1:
            case TheE._ev3:
            case TheE._ev7:
                _throw();
            default: break;
        }
        return (TheR) ((TheR)_val);
    } //get_v4

    public void set_v4(TheE _d, TheR _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case TheE._ev1:
            case TheE._ev3:
            case TheE._ev7:
                _throw();
            default:
                break;
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_v4

} //U3
