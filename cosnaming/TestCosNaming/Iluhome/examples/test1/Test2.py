# Stubs for "Test2"
#
# This file was automatically generated with KISORB (version 2.0beta1) tools
# at Fri Aug 22 17:23:11 2025 by `沈阳市软件定义智能协同重点实验室'
# running "D:/Shaun-projects/newstar/Iluhome/bin/python-stubber.exe" of Mon Aug 18 11:47:25 2025
# on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025#
# KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
# KISORB information: Dr. Wang xcwang89@aliyun.com .

_imported_modules = {};
import iluRt ; _imported_modules['iluRt'] = iluRt; _imported_modules['ilu'] = iluRt;
iluRt.CheckStubConsistency('2.0beta1', 'v2 (2.0beta1)');
_imported_modules['ilu__skel'] = iluRt
del iluRt
__types__={}

import Test1; _imported_modules['Test1'] = Test1; del Test1;
import iluRt

T1O3 = _imported_modules['Test1'].O3

__types__['T1O3'] = iluRt.RegisterAliasType(('Test2','T1O3',), None, 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU', 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU')
iluRt.NoteAlias('Test2.T1O3', 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU', 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU')

__types__['T1U3'] = iluRt.RegisterAliasType(('Test2','T1U3',), None, 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj', 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj')
iluRt.NoteAlias('Test2.T1U3', 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj', 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj')

__types__['T1U2'] = iluRt.RegisterAliasType(('Test2','T1U2',), None, 'ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9', 'ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9')
iluRt.NoteAlias('Test2.T1U2', 'ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9', 'ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9')

__types__['T1U'] = iluRt.RegisterAliasType(('Test2','T1U',), None, 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW')
iluRt.NoteAlias('Test2.T1U', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW')

def _Input_U2(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_enumeration)
    if _d == TheE.ev1:
        _value = (_d, iluRt.InputString(_call, 0))
    elif _d == TheE.ev3:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, _imported_modules['Test1'].TheO1))
    elif _d == TheE.ev7:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, P))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_U2(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_enumeration)
    if _d == TheE.ev1:
        iluRt.OutputString(_call, _value, 0)
    elif _d == TheE.ev3:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, _imported_modules['Test1'].TheO1)
    elif _d == TheE.ev7:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, P)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_U2(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_enumeration)
    if _d == TheE.ev1:
        _size = _size + iluRt.SizeOfString(_call, _value, 0)
    elif _d == TheE.ev3:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, _imported_modules['Test1'].TheO1)
    elif _d == TheE.ev7:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, P)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['U2'] = iluRt.RegisterUnionType(('Test2','U2',), None, 'ilut:dSc47PlWucPws3UX8kBfzRQVxyF', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', iluRt.TypeKind_enumeration, 0, 0, (('', 'ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv', ('ev1',)), ('', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty', ('ev3',)), ('', 'ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS', ('ev7',))))
iluRt.RegisterIoFuncs('ilut:dSc47PlWucPws3UX8kBfzRQVxyF', _Input_U2, _Output_U2, _SizeOf_U2, 'Test2.U2')

class P(iluRt.IluObjSurr):
    _IluClass = iluRt.FormClassRecord(
        'Test2.P',
        '',
        'ilut:l7u1rIEjawMUE+GJiOmDMtz2QvS',
        None,
        iluRt.FALSE,
        iluRt.FALSE,
        None,
        (
            ('SR-to-I', 1, iluRt.FALSE, iluRt.FALSE, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", (('i', 0, 0, 'ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO'),), ()),
        ),
        ()
    )

    def SR_to_I(_self, i):
        _result = None
        _call = iluRt.BeginCall(_self, P._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, P)
                    + iluRt.SizeOfShortReal(_call, i))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, P)
                iluRt.OutputShortReal(_call, i)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, P._IluClass, _ecode)
                _result = iluRt.InputInteger(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['P'] = iluRt.RegisterObjectType(P, ('Test2','P',), None, None)

class F:
    ev1 = 0
    ev3 = 3
    ev5 = 4
    ev7 = 5
    __image__ = {
        ev1: 'ev1',
        ev3: 'ev3',
        ev5: 'ev5',
        ev7: 'ev7'
    }

__types__['F'] = iluRt.RegisterAliasType(('Test2','F',), None, 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh')
iluRt.NoteAlias('Test2.F', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh')

E1__ExcnID = 'ilu:Test2.E1'

E1 = E1__ExcnID
class E1(Exception):
    def __init__(self,value):
        self.value=value

def _CatchException(_call, _IluClass, _ecode):
    _value = None
    _name = iluRt.ExceptionName(_call, _IluClass, _ecode)
    if _name == E1__ExcnID:
        _value = _imported_modules['Test1']._Input_TheU(_call)
        _name = E1(_value)
    raise _name
