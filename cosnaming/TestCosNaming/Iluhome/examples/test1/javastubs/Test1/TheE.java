// javastubs/Test1/TheE.java
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
 * Class representing an ILU enumeration type.
 */
public final class TheE implements java.io.Serializable, xerox.ilu.IluResolving {

    private int __val;
    private static xerox.basics.IntTab __tab = new xerox.basics.IntTab();
    private static int __hashOffset = __tab.hashCode();

    protected TheE(){}
    private static final TheE __define(int __i) {
        TheE __x = new TheE();
        __x.__val = __i;
        __tab.insert(__i, __x);
        return __x;
    } //__define

    public static final TheE from_int(int __i)
            throws org.omg.CORBA.SystemException {
        java.lang.Object __ob = __tab.unmonitoredFetch(__i);
        if (__ob == null) {
            throw new org.omg.CORBA.BAD_PARAM();
        }
        return (TheE) __ob;
    } //from_int

    public final int value() {
        return __val;
    } //value

    public static final int _ev1 = 0;
    public static final int _ev3 = 3;
    public static final int _ev5 = 4;
    public static final int _ev7 = 5;

    public static final TheE ev1 = __define(_ev1);
    public static final TheE ev3 = __define(_ev3);
    public static final TheE ev5 = __define(_ev5);
    public static final TheE ev7 = __define(_ev7);

    /** Object procedure */
    public int hashCode() {
        return (__val + __hashOffset);
    } //hashCode

    /** Object procedure */
    public boolean equals(java.lang.Object __o) {
        if (this == __o) return true;
        if (__o instanceof TheE) {
            return (__val == ((TheE)__o).__val);
        }
        return false;
    } //equals

    /** IluResolving. Used by (de) serialization */
    public java.lang.Object readResolve() throws java.io.ObjectStreamException {
        return from_int(__val);
    } //readResolve

} //TheE
