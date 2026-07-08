# Skeletons for "Test1"
#
# This file was automatically generated with KISORB (version 2.0beta1) tools
# at Fri Aug 22 17:23:11 2025 by `沈阳市软件定义智能协同重点实验室'
# running "D:/Shaun-projects/newstar/Iluhome/bin/python-stubber.exe" of Mon Aug 18 11:47:25 2025
# on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025#
# KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
# KISORB information: Dr. Wang xcwang89@aliyun.com .

import sys;
_imported_modules = {};
import iluRt ; _imported_modules['iluRt'] = iluRt; _imported_modules['ilu'] = iluRt;
iluRt.CheckStubConsistency('2.0beta1', 'v2 (2.0beta1)');
_imported_modules['ilu__skel'] = iluRt
del iluRt
import Test1; _imported_modules['Test1'] = Test1; del Test1;
import iluRt

def _O3__RS_R_to_R_IS(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].O3)
    r = _imported_modules['Test1']._Input_TheRS(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.RS_R_to_R_IS(r)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + _imported_modules['Test1']._SizeOf_IS(_call, _result[0])
        + _imported_modules['Test1']._SizeOf_TheR(_call, _result[1]))
    _imported_modules['Test1']._Output_IS(_call, _result[0])
    _imported_modules['Test1']._Output_TheR(_call, _result[1])
    iluRt.FinishReply(_call)

def _O3__O1_U_to_U(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].O3)
    o = iluRt.InputObjectID(_call, iluRt.FALSE, _imported_modules['Test1'].TheO1)
    u = _imported_modules['Test1']._Input_TheU(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.O1_U_to_U(o, u)
    except _imported_modules['Test1'].E2 as e:
        iluRt.BeginException(_call, 1, iluRt.BeginSizingException(_call, 1) + 
            iluRt.SizeOfInteger(_call, e.value))
        iluRt.OutputInteger(_call, e.value)
        iluRt.FinishException(_call)
        return
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.TRUE, iluRt.BeginSizingReply(_call, iluRt.TRUE) + _imported_modules['Test1']._SizeOf_TheU(_call, _result))
    _imported_modules['Test1']._Output_TheU(_call, _result)
    iluRt.FinishReply(_call)

def _O3__BS_to_I(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].O3)
    b = iluRt.InputBytes(_call, 0)
    iluRt.RequestRead(_call)
    try:
        _result = _self.BS_to_I(b)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + iluRt.SizeOfInteger(_call, _result))
    iluRt.OutputInteger(_call, _result)
    iluRt.FinishReply(_call)


iluRt.RegisterSkeletons(_imported_modules['Test1'].O3._IluClass, (
    _O3__RS_R_to_R_IS,
    _O3__O1_U_to_U,
    _O3__BS_to_I,))


class O3(iluRt.IluObjTrue):
    _IluClass = _imported_modules['Test1'].O3._IluClass

    def RS_R_to_R_IS(_self, r):
        raise Exception(iluRt.IluUnimplementedMethodError, 'RS-R-to-R-IS')

    def O1_U_to_U(_self, o, u):
        raise Exception(iluRt.IluUnimplementedMethodError, 'O1-U-to-U')

    def BS_to_I(_self, b):
        raise Exception(iluRt.IluUnimplementedMethodError, 'BS-to-I')


def _O4__R_to_R(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].O4)
    r = iluRt.InputReal(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.R_to_R(r)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + iluRt.SizeOfReal(_call, _result))
    iluRt.OutputReal(_call, _result)
    iluRt.FinishReply(_call)


iluRt.RegisterSkeletons(_imported_modules['Test1'].O4._IluClass, (
    _O4__R_to_R,))


class O4(iluRt.IluObjTrue):
    _IluClass = _imported_modules['Test1'].O4._IluClass

    def R_to_R(_self, r):
        raise Exception(iluRt.IluUnimplementedMethodError, 'R-to-R')


def _P__m2(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].P)
    j = iluRt.InputInteger(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.m2(j)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + _imported_modules['Test1']._SizeOf_IS(_call, _result))
    _imported_modules['Test1']._Output_IS(_call, _result)
    iluRt.FinishReply(_call)


iluRt.RegisterSkeletons(_imported_modules['Test1'].P._IluClass, (
    _P__m2,))


class P(iluRt.IluObjTrue):
    _IluClass = _imported_modules['Test1'].P._IluClass

    def m2(_self, j):
        raise Exception(iluRt.IluUnimplementedMethodError, 'm2')


def _TheO1__U_CSS_to_U(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].TheO1)
    u = _imported_modules['Test1']._Input_TheU(_call)
    css = _imported_modules['Test1']._Input_CSS(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.U_CSS_to_U(u, css)
    except _imported_modules['Test1'].E1 as e:
        iluRt.BeginException(_call, 1, iluRt.BeginSizingException(_call, 1) + 
            _imported_modules['Test1']._SizeOf_TheU(_call, e.value))
        _imported_modules['Test1']._Output_TheU(_call, e.value)
        iluRt.FinishException(_call)
        return
    except _imported_modules['Test1'].E2 as e:
        iluRt.BeginException(_call, 2, iluRt.BeginSizingException(_call, 2) + 
            iluRt.SizeOfInteger(_call, e.value))
        iluRt.OutputInteger(_call, e.value)
        iluRt.FinishException(_call)
        return
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.TRUE, iluRt.BeginSizingReply(_call, iluRt.TRUE) + _imported_modules['Test1']._SizeOf_TheU(_call, _result))
    _imported_modules['Test1']._Output_TheU(_call, _result)
    iluRt.FinishReply(_call)

def _TheO1__f_CSS_to_RO(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].TheO1)
    css = _imported_modules['Test1']._Input_CSS(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.f_CSS_to_RO(css)
    except _imported_modules['Test1'].E1 as e:
        iluRt.BeginException(_call, 1, iluRt.BeginSizingException(_call, 1) + 
            _imported_modules['Test1']._SizeOf_TheU(_call, e.value))
        _imported_modules['Test1']._Output_TheU(_call, e.value)
        iluRt.FinishException(_call)
        return
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.TRUE, iluRt.BeginSizingReply(_call, iluRt.TRUE) + _imported_modules['Test1']._SizeOf_RO(_call, _result))
    _imported_modules['Test1']._Output_RO(_call, _result)
    iluRt.FinishReply(_call)

def _TheO1__R_ScS_to_F(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].TheO1)
    r = _imported_modules['Test1']._Input_TheR(_call)
    s = iluRt.InputString(_call, 0)
    iluRt.RequestRead(_call)
    try:
        _result = _self.R_ScS_to_F(r, s)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + iluRt.SizeOfShortReal(_call, _result))
    iluRt.OutputShortReal(_call, _result)
    iluRt.FinishReply(_call)

def _TheO1__a_RO(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].TheO1)
    ro = _imported_modules['Test1']._Input_RO(_call)
    iluRt.RequestRead(_call)
    _self.a_RO(ro)
    iluRt.NoReply(_call)

def _TheO1__get_O2(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].TheO1)
    iluRt.RequestRead(_call)
    try:
        _result = _self.get_O2()
    except _imported_modules['Test1'].CantCreate:
        iluRt.BeginException(_call, 1, iluRt.BeginSizingException(_call, 1) +  0)
        iluRt.FinishException(_call)
        return
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.TRUE, iluRt.BeginSizingReply(_call, iluRt.TRUE) + iluRt.SizeOfObjectID(_call, _result, iluRt.FALSE, _imported_modules['Test1'].O2))
    iluRt.OutputObjectID(_call, _result, iluRt.FALSE, _imported_modules['Test1'].O2)
    iluRt.FinishReply(_call)

def _TheO1__get_O3(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test1'].TheO1)
    subclass = iluRt.InputBoolean(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.get_O3(subclass)
    except _imported_modules['Test1'].CantCreate:
        iluRt.BeginException(_call, 1, iluRt.BeginSizingException(_call, 1) +  0)
        iluRt.FinishException(_call)
        return
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.TRUE, iluRt.BeginSizingReply(_call, iluRt.TRUE) + iluRt.SizeOfObjectID(_call, _result, iluRt.FALSE, _imported_modules['Test1'].O3))
    iluRt.OutputObjectID(_call, _result, iluRt.FALSE, _imported_modules['Test1'].O3)
    iluRt.FinishReply(_call)


iluRt.RegisterSkeletons(_imported_modules['Test1'].TheO1._IluClass, (
    _TheO1__U_CSS_to_U,
    _TheO1__f_CSS_to_RO,
    _TheO1__R_ScS_to_F,
    _TheO1__a_RO,
    _TheO1__get_O2,
    _TheO1__get_O3,))


class TheO1(iluRt.IluObjTrue):
    _IluClass = _imported_modules['Test1'].TheO1._IluClass

    def U_CSS_to_U(_self, u, css):
        raise Exception(iluRt.IluUnimplementedMethodError, 'U-CSS-to-U')

    def f_CSS_to_RO(_self, css):
        raise Exception(iluRt.IluUnimplementedMethodError, 'f-CSS-to-RO')

    def R_ScS_to_F(_self, r, s):
        raise Exception(iluRt.IluUnimplementedMethodError, 'R-ScS-to-F')

    def a_RO(_self, ro):
        raise Exception(iluRt.IluUnimplementedMethodError, 'a-RO')

    def get_O2(_self):
        raise Exception(iluRt.IluUnimplementedMethodError, 'get-O2')

    def get_O3(_self, subclass):
        raise Exception(iluRt.IluUnimplementedMethodError, 'get-O3')


One = TheO1

def _O2__OO_A0_to_CSS(_call):
    _self =     iluRt.GetSingleton(_call)
    o = _imported_modules['Test1']._Input_TheOO(_call)
    a = iluRt.InputOpaque(_call, 8)
    iluRt.RequestRead(_call)
    try:
        _result = _self.OO_A0_to_CSS(o, a)
    except _imported_modules['Test1'].E2 as e:
        iluRt.BeginException(_call, 1, iluRt.BeginSizingException(_call, 1) + 
            iluRt.SizeOfInteger(_call, e.value))
        iluRt.OutputInteger(_call, e.value)
        iluRt.FinishException(_call)
        return
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.TRUE, iluRt.BeginSizingReply(_call, iluRt.TRUE) + _imported_modules['Test1']._SizeOf_CSS(_call, _result))
    _imported_modules['Test1']._Output_CSS(_call, _result)
    iluRt.FinishReply(_call)

def _O2__R_I_A1_to_I_A0(_call):
    _self =     iluRt.GetSingleton(_call)
    r = _imported_modules['Test1']._Input_TheR(_call)
    i = iluRt.InputInteger(_call)
    a = _imported_modules['Test1']._Input_TheA1(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.R_I_A1_to_I_A0(r, i, a)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + iluRt.SizeOfOpaque(_call, _result[0], 8)
        + iluRt.SizeOfInteger(_call, _result[1]))
    iluRt.OutputOpaque(_call, _result[0], 8)
    iluRt.OutputInteger(_call, _result[1])
    iluRt.FinishReply(_call)


iluRt.RegisterSkeletons(_imported_modules['Test1'].O2._IluClass, (
    _O2__OO_A0_to_CSS,
    _O2__R_I_A1_to_I_A0,))


class O2(iluRt.IluObjTrue):
    _IluClass = _imported_modules['Test1'].O2._IluClass

    def OO_A0_to_CSS(_self, o, a):
        raise Exception(iluRt.IluUnimplementedMethodError, 'OO-A0-to-CSS')

    def R_I_A1_to_I_A0(_self, r, i, a):
        raise Exception(iluRt.IluUnimplementedMethodError, 'R-I-A1-to-I-A0')


O1 = TheO1
