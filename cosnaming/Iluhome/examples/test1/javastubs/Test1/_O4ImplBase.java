// javastubs/Test1/_O4ImplBase.java
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
 * A sample implementation for a true ILU object.
 */
public abstract class _O4ImplBase extends org.omg.CORBA.portable.ObjectImpl implements O4 {

    protected xerox.ilu.IluClassRep _implements() {
        return O4Stub.iluClass();
    } //_implements

    public O4 _this() {
        return this;
    } //_this

    public _O4ImplBase () {
    } //constructor

    protected _O4ImplBase (java.lang.String name) {
    } //constructor

    /** purly for reasons of corba compatibility */
    public java.lang.String[] _ids() {
        throw new org.omg.CORBA.NO_IMPLEMENT();
    } //_ids

} //_O4ImplBase

