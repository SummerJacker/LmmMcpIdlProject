// javastubs/hello_world/_serviceImplBase.java
// Stubs for "hello-world"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:51 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/hello-world/hello-world.isl" of Wed Jul 30 16:24:59 2025,
// and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package hello_world;


/** 
 * A sample implementation for a true ILU object.
 */
public abstract class _serviceImplBase extends org.omg.CORBA.portable.ObjectImpl implements service {

    protected xerox.ilu.IluClassRep _implements() {
        return serviceStub.iluClass();
    } //_implements

    public service _this() {
        return this;
    } //_this

    public _serviceImplBase () {
    } //constructor

    protected _serviceImplBase (java.lang.String name) {
    } //constructor

    /** purly for reasons of corba compatibility */
    public java.lang.String[] _ids() {
        throw new org.omg.CORBA.NO_IMPLEMENT();
    } //_ids

} //_serviceImplBase

