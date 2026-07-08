// javastubs/Tutorial2/Operation.java
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
 * Class representing an ILU record type.
 */
public class Operation { 

    public OpType op = null;
    public double value = 0D;
    public double accumulator = 0D;

    //to force ILU to allocate subclasses
    protected static java.lang.Class _theClass = null;

    public void _touch() {
    } //_touch

    //avoid unless corba compatibility required
    public Operation() {
    } //Operation

    //not standard corba
    public static Operation alloc_Operation() {
        if (_theClass!=null) {
            try {
                return (Operation) _theClass.newInstance();
            } catch (java.lang.Exception _e) {
            }
        }
        return new Operation();
    } //alloc_Operation

    //avoid unless corba compatibility required
    public Operation(OpType op, double value, double accumulator) {
        this.op = op;
        this.value = value;
        this.accumulator = accumulator;
    } //constructor

    //not standard corba
    public static Operation alloc_Operation(OpType op, double value, double accumulator) {
        Operation _r = alloc_Operation();
        _r.op = op;
        _r.value = value;
        _r.accumulator = accumulator;
        _r._touch();
        return _r;
    } //alloc_Operation

} //Operation
