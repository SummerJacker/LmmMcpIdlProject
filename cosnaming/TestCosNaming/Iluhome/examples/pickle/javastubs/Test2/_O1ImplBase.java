// javastubs/Test2/_O1ImplBase.java
// Stubs for "Test2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:39 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/pickle//Test2.isl" of Tue Sep 21 06:54:01 1999,
// and "D:/Shaun-projects/newstar/Iluhome/examples/pickle//ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test2;


/** 
 * A sample implementation for a true ILU object.
 */
public abstract class _O1ImplBase extends org.omg.CORBA.portable.ObjectImpl implements O1 {

    protected xerox.ilu.IluClassRep _implements() {
        return O1Stub.iluClass();
    } //_implements

    public O1 _this() {
        return this;
    } //_this

    public _O1ImplBase () {
    } //constructor

    protected _O1ImplBase (java.lang.String name) {
    } //constructor

    /** purly for reasons of corba compatibility */
    public java.lang.String[] _ids() {
        throw new org.omg.CORBA.NO_IMPLEMENT();
    } //_ids

} //_O1ImplBase

