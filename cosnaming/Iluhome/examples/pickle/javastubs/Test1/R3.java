// javastubs/Test1/R3.java
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
 * Class representing an ILU record type.
 */
public class R3 { 

    public int a = 0;
    public double b = 0D;

    //to force ILU to allocate subclasses
    protected static java.lang.Class _theClass = null;

    public void _touch() {
    } //_touch

    //avoid unless corba compatibility required
    public R3() {
    } //R3

    //not standard corba
    public static R3 alloc_R3() {
        if (_theClass!=null) {
            try {
                return (R3) _theClass.newInstance();
            } catch (java.lang.Exception _e) {
            }
        }
        return new R3();
    } //alloc_R3

    //avoid unless corba compatibility required
    public R3(int a, double b) {
        this.a = a;
        this.b = b;
    } //constructor

    //not standard corba
    public static R3 alloc_R3(int a, double b) {
        R3 _r = alloc_R3();
        _r.a = a;
        _r.b = b;
        _r._touch();
        return _r;
    } //alloc_R3

} //R3
