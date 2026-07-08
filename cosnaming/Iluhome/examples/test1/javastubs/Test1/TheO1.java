// javastubs/Test1/TheO1.java
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
 * sample
 * multi-line doc string
 * An ILU object type.
 */
public interface TheO1 extends org.omg.CORBA.Object {
    public TheU U_CSS_to_U(TheU u, java.lang.String[] css)
        throws E1, E2;
    public TheR f_CSS_to_RO(java.lang.String[] css)
        throws E1;
    public float R_ScS_to_F(TheR r, java.lang.String s);
    public void a_RO(TheR ro);
    public O2 get_O2()
        throws CantCreate;
    public O3 get_O3(boolean subclass)
        throws CantCreate;

}//TheO1

