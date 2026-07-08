// javastubs/Tutorial/Calculator.java
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
 * An ILU object type.
 */
public interface Calculator extends org.omg.CORBA.Object {

    /** 
     * Set the value of the calculator to `v'
     */
    public void SetValue(double v);

    /** 
     * Return the value of the calculator
     */
    public double GetValue();

    /** 
     * Adds `v' to the calculator's value
     */
    public void Add(double v);

    /** 
     * Subtracts `v' from the calculator's value
     */
    public void Subtract(double v);

    /** 
     * Multiplies the calculator's value by `v'
     */
    public void Multiply(double v);

    /** 
     * Divides the calculator's value by `v'
     */
    public void Divide(double v)
        throws DivideByZero;

}//Calculator

