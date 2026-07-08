// javastubs/Test1/E8_exh_.java
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

public class E8_exh_ extends E8 {

    public E8_exh_() {
        super();
    }

    public E8_exh_(java.lang.String[] _val) {
        super();
        //not used; but required by type system
        throw new org.omg.CORBA.NO_IMPLEMENT();
    }

    private static xerox.ilu.IluExceptionRep _E8_rep;
    public static final xerox.ilu.IluExceptionRep _E8getRep() {
        return _E8_rep;
    }

    //NOT really public; Must be accessible by ilu...
    public void readException(java.lang.Object call)
            throws org.omg.CORBA.SystemException {
        xerox.ilu.IluCall _call = (xerox.ilu.IluCall) call;
        this.value = TheA1.inFunc(_call);
    } //readException

    //NOT really public; Must be accessible by ilu...
    public static void _E8_marshall(E8 _ex, int index, xerox.ilu.IluCall _call)
            throws org.omg.CORBA.SystemException {
        int sz = 0;
        if (_call.needsSizing()) {
            sz = _call.beginSizingException(index);
            sz += TheA1.szFunc(_call, _ex.value);
        }
        _call.startWriteException(index, sz);
        TheA1.outFunc(_call, _ex.value);
        _call.doneWriteException();
    } //_E8_marshall

    static {
        _E8_rep = xerox.ilu.IluExceptionRep.defineException(
            "Test1.E8_exh_", //java class name
            "Test1", //isl interface name
            "E8", //isl exception name
            "ilut:h3Dnvis94UwnmFURfYsCp700jVy"); //type uuid
    }

} //E8_exh_
