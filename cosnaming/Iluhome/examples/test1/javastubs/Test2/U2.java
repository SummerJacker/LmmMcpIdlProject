// javastubs/Test2/U2.java
// Stubs for "Test2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test2;


/** 
 * Class representing an ILU union type.
 */
public class U2 implements java.io.Serializable {
    boolean _init = false;
    Test1.TheE _dis = null;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public U2() {
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

    public static U2 alloc_xerox_ilu_CString(Test1.TheE _dis, java.lang.String _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U2 _res = new U2();
        _res.set_xerox_ilu_CString(_dis, _v);
        return _res;
    } //alloc_xerox_ilu_CString

    public static U2 alloc_xerox_ilu_CString(java.lang.String _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_xerox_ilu_CString(Test1.TheE.ev1, _v);
    } //alloc_xerox_ilu_CString

    public java.lang.String get_xerox_ilu_CString()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case Test1.TheE._ev1:
                break;
            default: 
                _throw();
        }
        return (java.lang.String) ((java.lang.String)_val);
    } //get_xerox_ilu_CString

    public void set_xerox_ilu_CString(Test1.TheE _d, java.lang.String _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case Test1.TheE._ev1:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_xerox_ilu_CString

    public void set_xerox_ilu_CString(java.lang.String _v) {
        set_xerox_ilu_CString(Test1.TheE.ev1, _v);
    } //set_xerox_ilu_CString

    public static U2 alloc_Test1_O1(Test1.TheE _dis, Test1.TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U2 _res = new U2();
        _res.set_Test1_O1(_dis, _v);
        return _res;
    } //alloc_Test1_O1

    public static U2 alloc_Test1_O1(Test1.TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_Test1_O1(Test1.TheE.ev3, _v);
    } //alloc_Test1_O1

    public Test1.TheO1 get_Test1_O1()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case Test1.TheE._ev3:
                break;
            default: 
                _throw();
        }
        return (Test1.TheO1) ((Test1.TheO1)_val);
    } //get_Test1_O1

    public void set_Test1_O1(Test1.TheE _d, Test1.TheO1 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case Test1.TheE._ev3:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_Test1_O1

    public void set_Test1_O1(Test1.TheO1 _v) {
        set_Test1_O1(Test1.TheE.ev3, _v);
    } //set_Test1_O1

    public static U2 alloc_P(Test1.TheE _dis, P _v)
            throws org.omg.CORBA.BAD_OPERATION {
        U2 _res = new U2();
        _res.set_P(_dis, _v);
        return _res;
    } //alloc_P

    public static U2 alloc_P(P _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_P(Test1.TheE.ev7, _v);
    } //alloc_P

    public P get_P()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        switch(_dis.value()) {
            case Test1.TheE._ev7:
                break;
            default: 
                _throw();
        }
        return (P) ((P)_val);
    } //get_P

    public void set_P(Test1.TheE _d, P _v)
            throws org.omg.CORBA.BAD_OPERATION {
        switch (_d.value()) {
            case Test1.TheE._ev7:
                break;
            default: _throw();
        }
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_P

    public void set_P(P _v) {
        set_P(Test1.TheE.ev7, _v);
    } //set_P

} //U2
