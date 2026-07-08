// javastubs/Test1/E6_exh_.java
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

public class E6_exh_ extends E6 {

    public E6_exh_() {
        super();
    }

    public E6_exh_(TheR[] _val) {
        super();
        //not used; but required by type system
        throw new org.omg.CORBA.NO_IMPLEMENT();
    }

    private static xerox.ilu.IluExceptionRep _E6_rep;
    public static final xerox.ilu.IluExceptionRep _E6getRep() {
        return _E6_rep;
    }

    //NOT really public; Must be accessible by ilu...
    public void readException(java.lang.Object call)
            throws org.omg.CORBA.SystemException {
        xerox.ilu.IluCall _call = (xerox.ilu.IluCall) call;
        this.value = TheRS._inFunc(_call);
    } //readException

    //NOT really public; Must be accessible by ilu...
    public static void _E6_marshall(E6 _ex, int index, xerox.ilu.IluCall _call)
            throws org.omg.CORBA.SystemException {
        int sz = 0;
        if (_call.needsSizing()) {
            sz = _call.beginSizingException(index);
            sz += TheRS._szFunc(_call, _ex.value);
        }
        _call.startWriteException(index, sz);
        TheRS._outFunc(_call, _ex.value);
        _call.doneWriteException();
    } //_E6_marshall

    static {
        _E6_rep = xerox.ilu.IluExceptionRep.defineException(
            "Test1.E6_exh_", //java class name
            "Test1", //isl interface name
            "E6", //isl exception name
            "ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac"); //type uuid
    }

} //E6_exh_
