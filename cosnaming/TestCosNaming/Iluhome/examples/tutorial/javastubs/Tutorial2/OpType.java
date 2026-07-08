// javastubs/Tutorial2/OpType.java
// Stubs for "Tutorial2"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:33 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial2.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/Tutorial.isl" of Thu Dec 28 15:50:20 2023,
// and "D:/Shaun-projects/newstar/Iluhome/examples/tutorial/ilu.isl" of Fri Aug 01 09:16:44 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Tutorial2;


/** 
 * Class representing an ILU enumeration type.
 */
public final class OpType implements java.io.Serializable, xerox.ilu.IluResolving {

    private int __val;
    private static OpType[] __a = new OpType[5];
    private static int __hashOffset = __a.hashCode();

    protected OpType(){}
    private static final OpType __define(int __i) {
        OpType __x = new OpType();
        __x.__val = __i;
        __a[__i] = __x;
        return __x;
    } //__define

    public static final OpType from_int(int __i)
            throws org.omg.CORBA.SystemException {
        if (__i < 0 || __i > 4) {
            throw new org.omg.CORBA.BAD_PARAM();
        }
        return __a[__i];
    } //from_int

    public final int value() {
        return __val;
    } //value

    public static final int _SetValue = 0;
    public static final int _Add = 1;
    public static final int _Subtract = 2;
    public static final int _Multiply = 3;
    public static final int _Divide = 4;

    public static final OpType SetValue = __define(_SetValue);
    public static final OpType Add = __define(_Add);
    public static final OpType Subtract = __define(_Subtract);
    public static final OpType Multiply = __define(_Multiply);
    public static final OpType Divide = __define(_Divide);

    /** Object procedure */
    public int hashCode() {
        return (__val + __hashOffset);
    } //hashCode

    /** Object procedure */
    public boolean equals(java.lang.Object __o) {
        if (this == __o) return true;
        if (__o instanceof OpType) {
            return (__val == ((OpType)__o).__val);
        }
        return false;
    } //equals

    /** IluResolving. Used by (de) serialization */
    public java.lang.Object readResolve() throws java.io.ObjectStreamException {
        return from_int(__val);
    } //readResolve

} //OpType
