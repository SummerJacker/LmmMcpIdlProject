// javastubs/Test3/E1_exh_.java
// Stubs for "Test3"
//
// This file was automatically generated with KISORB (version 2.0beta1) tools
// at Fri Aug 22 17:23:20 2025 by `沈阳市软件定义智能协同重点实验室'
// running "D:/Shaun-projects/newstar/Iluhome/bin/java-stubber.exe" of Mon Aug 18 11:47:37 2025
// on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
// and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025//
// KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KISORB information: Dr. Wang xcwang89@aliyun.com .



package Test3;

public class E1_exh_ extends E1 {

    public E1_exh_() {
        super();
    }

    public E1_exh_(java.lang.String _val) {
        super();
        //not used; but required by type system
        throw new org.omg.CORBA.NO_IMPLEMENT();
    }

    private static xerox.ilu.IluExceptionRep _E1_rep;
    public static final xerox.ilu.IluExceptionRep _E1getRep() {
        return _E1_rep;
    }

    //NOT really public; Must be accessible by ilu...
    public void readException(java.lang.Object call)
            throws org.omg.CORBA.SystemException {
        xerox.ilu.IluCall _call = (xerox.ilu.IluCall) call;
        this.value = _call.inString8(0);
    } //readException

    //NOT really public; Must be accessible by ilu...
    public static void _E1_marshall(E1 _ex, int index, xerox.ilu.IluCall _call)
            throws org.omg.CORBA.SystemException {
        int sz = 0;
        if (_call.needsSizing()) {
            sz = _call.beginSizingException(index);
            sz += _call.szString8(_ex.value, 0);
        }
        _call.startWriteException(index, sz);
        _call.outString8(_ex.value, 0);
        _call.doneWriteException();
    } //_E1_marshall

    static {
        _E1_rep = xerox.ilu.IluExceptionRep.defineException(
            "Test3.E1_exh_", //java class name
            "Test3", //isl interface name
            "E1", //isl exception name
            "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv"); //type uuid
    }

} //E1_exh_
