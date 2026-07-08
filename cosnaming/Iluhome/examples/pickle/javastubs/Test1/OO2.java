// javastubs/Test1/OO2.java
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
public class OO2 implements java.io.Serializable {
    boolean _init = false;
    boolean _dis = false;
    java.lang.Object _val = null;

    static void _throw()
            throws org.omg.CORBA.BAD_OPERATION {
        throw new org.omg.CORBA.BAD_OPERATION();
    } //_throw

    public OO2() {
        _init = false;
        _val = null;
    } //constructor

    public boolean discriminator()
                throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {
            _throw();
        }
        return _dis;
    } //discriminator

    public static OO2 alloc_O5(boolean _dis, O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        OO2 _res = new OO2();
        _res.set_O5(_dis, _v);
        return _res;
    } //alloc_O5

    public static OO2 alloc_O5(O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        return alloc_O5(true, _v);
    } //alloc_O5

    public O5 get_O5()
            throws org.omg.CORBA.BAD_OPERATION {
        if (!_init) {_throw();}
        if(_dis) _throw();
        return (O5) ((O5)_val);
    } //get_O5

    public void set_O5(boolean _d, O5 _v)
            throws org.omg.CORBA.BAD_OPERATION {
        if(!_d) _throw();
        _dis = _d;
        _val = _v;
        _init = true;
    } //set_O5

    public void set_O5(O5 _v) {
        set_O5(true, _v);
    } //set_O5

    public void setOther(boolean _d)
            throws org.omg.CORBA.BAD_OPERATION {
        if(_d) _throw();
        _dis = _d;
        _val = null;
        _init = true;
    } //setOther

    public static OO2 allocOther(boolean _dis)
            throws org.omg.CORBA.BAD_OPERATION {
        OO2 _res = new OO2();
        _res.setOther(_dis);
        return _res;
    } //allocOther

} //OO2
