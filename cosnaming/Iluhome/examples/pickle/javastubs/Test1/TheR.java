// javastubs/Test1/TheR.java
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
public class TheR { 

    public java.lang.String[] a = null;
    public java.lang.String[] css = null;
    public int i = 0;

    //to force ILU to allocate subclasses
    protected static java.lang.Class _theClass = null;

    public void _touch() {
    } //_touch

    //avoid unless corba compatibility required
    public TheR() {
    } //TheR

    //not standard corba
    public static TheR alloc_TheR() {
        if (_theClass!=null) {
            try {
                return (TheR) _theClass.newInstance();
            } catch (java.lang.Exception _e) {
            }
        }
        return new TheR();
    } //alloc_TheR

    //avoid unless corba compatibility required
    public TheR(java.lang.String[] a, java.lang.String[] css, int i) {
        this.a = a;
        this.css = css;
        this.i = i;
    } //constructor

    //not standard corba
    public static TheR alloc_TheR(java.lang.String[] a, java.lang.String[] css, int i) {
        TheR _r = alloc_TheR();
        _r.a = a;
        _r.css = css;
        _r.i = i;
        _r._touch();
        return _r;
    } //alloc_TheR

} //TheR
