// javastubs/Tutorial/_CalculatorImplBase.java
// Stubs for "Tutorial"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:33 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Tutorial;


/** 
 * 4-function calculator
 * A sample implementation for a true ILU object.
 */
public abstract class _CalculatorImplBase extends org.omg.CORBA.portable.ObjectImpl implements Calculator {

    protected xerox.ilu.IluClassRep _implements() {
        return CalculatorStub.iluClass();
    } //_implements

    public Calculator _this() {
        return this;
    } //_this

    public _CalculatorImplBase () {
    } //constructor

    protected _CalculatorImplBase (java.lang.String name) {
    } //constructor

    /** purly for reasons of corba compatibility */
    public java.lang.String[] _ids() {
        throw new org.omg.CORBA.NO_IMPLEMENT();
    } //_ids

} //_CalculatorImplBase

