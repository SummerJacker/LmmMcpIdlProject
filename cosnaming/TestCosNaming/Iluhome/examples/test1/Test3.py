# Stubs for "Test3"
#
# This file was automatically generated with KISORB (version 2.0beta1) tools
# at Fri Aug 22 17:23:11 2025 by `沈阳市软件定义智能协同重点实验室'
# running "D:/Shaun-projects/newstar/Iluhome/bin/python-stubber.exe" of Mon Aug 18 11:47:25 2025
# on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test3.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
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
import Test2; _imported_modules['Test2'] = Test2; del Test2;
import iluRt

def _Input_FU(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_enumeration)
    if _d == _imported_modules['Test1'].TheE.ev1:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O))
    elif _d == _imported_modules['Test1'].TheE.ev3:
        _value = (_d, iluRt.InputInteger(_call))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_FU(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_enumeration)
    if _d == _imported_modules['Test1'].TheE.ev1:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O)
    elif _d == _imported_modules['Test1'].TheE.ev3:
        iluRt.OutputInteger(_call, _value)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_FU(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_enumeration)
    if _d == _imported_modules['Test1'].TheE.ev1:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O)
    elif _d == _imported_modules['Test1'].TheE.ev3:
        _size = _size + iluRt.SizeOfInteger(_call, _value)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['FU'] = iluRt.RegisterUnionType(('Test3','FU',), None, 'ilut:p7oYELOBiB2uFXthQiHxgFh1H8p', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', iluRt.TypeKind_enumeration, 0, 0, (('', 'ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg', ('ev1',)), ('', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY', ('ev3',))))
iluRt.RegisterIoFuncs('ilut:p7oYELOBiB2uFXthQiHxgFh1H8p', _Input_FU, _Output_FU, _SizeOf_FU, 'Test3.FU')

T2T1O3 = _imported_modules['Test1'].O3

__types__['T2T1O3'] = iluRt.RegisterAliasType(('Test3','T2T1O3',), None, 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU', 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU')
iluRt.NoteAlias('Test3.T2T1O3', 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU', 'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU')

__types__['T2T1U3'] = iluRt.RegisterAliasType(('Test3','T2T1U3',), None, 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj', 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj')
iluRt.NoteAlias('Test3.T2T1U3', 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj', 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj')

class O(_imported_modules['Test1'].O3, _imported_modules['Test2'].P):
    _IluClass = iluRt.FormClassRecord(
        'Test3.O',
        '',
        'ilut:jk-9FxqYR5X4GPtM0qc1nahuhHg',
        None,
        iluRt.FALSE,
        iluRt.FALSE,
        None,
        (
            ('I-to-Test1U', 1, iluRt.FALSE, iluRt.FALSE, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", (('i', 0, 0, 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY'),), (('ilu:Test3.E1', 'ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv',), ('ilu:Test1.E1', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW',))),
        ),
        (_imported_modules['Test1'].O3._IluClass, _imported_modules['Test2'].P._IluClass)
    )

    def I_to_Test1U(_self, i):
        _result = None
        _call = iluRt.BeginCall(_self, O._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, O)
                    + iluRt.SizeOfInteger(_call, i))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, O)
                iluRt.OutputInteger(_call, i)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, O._IluClass, _ecode)
                _result = _imported_modules['Test1']._Input_TheU(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['O'] = iluRt.RegisterObjectType(O, ('Test3','O',), None, None)

E1__ExcnID = 'ilu:Test3.E1'

E1 = E1__ExcnID
class E1(Exception):
    def __init__(self,value):
        self.value=value

def _CatchException(_call, _IluClass, _ecode):
    _value = None
    _name = iluRt.ExceptionName(_call, _IluClass, _ecode)
    if _name == E1__ExcnID:
        _value = iluRt.InputString(_call, 0)
        _name = E1(_value)
    elif _name == _imported_modules['Test1'].E1__ExcnID:
        _value = _imported_modules['Test1']._Input_TheU(_call)
        _name = _imported_modules['Test1'].E1(_value)
    raise _name
