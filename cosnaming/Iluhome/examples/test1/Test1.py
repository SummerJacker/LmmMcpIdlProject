# Stubs for "Test1"
#
# This file was automatically generated with KISORB (version 2.0beta1) tools
# at Fri Aug 22 17:23:11 2025 by `沈阳市软件定义智能协同重点实验室'
# running "D:/Shaun-projects/newstar/Iluhome/bin/python-stubber.exe" of Mon Aug 18 11:47:25 2025
# on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025#
# KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
# KISORB information: Dr. Wang xcwang89@aliyun.com .

_imported_modules = {};
import iluRt ; _imported_modules['iluRt'] = iluRt; _imported_modules['ilu'] = iluRt;
iluRt.CheckStubConsistency('2.0beta1', 'v2 (2.0beta1)');
_imported_modules['ilu__skel'] = iluRt
del iluRt
__types__={}

import iluRt

class O3(iluRt.IluObjSurr):
    _IluClass = iluRt.FormClassRecord(
        'Test1.O3',
        'v1',
        'ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU',
        None,
        iluRt.TRUE,
        iluRt.FALSE,
        None,
        (
            ('RS-R-to-R-IS', 1, iluRt.FALSE, iluRt.FALSE, "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO", (('r', 0, 0, 'ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac'), ('r2', 1, 0, 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7')), ()),
            ('O1-U-to-U', 2, iluRt.FALSE, iluRt.FALSE, None, (('o', 0, 1, 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty'), ('u', 2, 0, 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW')), (('ilu:Test1.E2', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY',),)),
            ('BS-to-I', 3, iluRt.FALSE, iluRt.FALSE, "ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY", (('b', 0, 0, 'ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3'),), ()),
        ),
        ()
    )

    def RS_R_to_R_IS(_self, r):
        _result = None
        _call = iluRt.BeginCall(_self, O3._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, O3)
                    + _SizeOf_TheRS(_call, r))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, O3)
                _Output_TheRS(_call, r)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, O3._IluClass, _ecode)
                _result = _Input_IS(_call),\
                    _Input_TheR(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

    def O1_U_to_U(_self, o, u):
        _result = None
        iluRt.CheckSibling(_self, o)
        _call = iluRt.BeginCall(_self, O3._IluClass, 2)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, O3)
                    + iluRt.SizeOfObjectID(_call, o, iluRt.FALSE, TheO1)
                    + _SizeOf_TheU(_call, u))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, O3)
                iluRt.OutputObjectID(_call, o, iluRt.FALSE, TheO1)
                _Output_TheU(_call, u)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, O3._IluClass, _ecode)
                _result = _Input_TheU(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

    def BS_to_I(_self, b):
        _result = None
        _call = iluRt.BeginCall(_self, O3._IluClass, 3)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, O3)
                    + iluRt.SizeOfBytes(_call, b, 0))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, O3)
                iluRt.OutputBytes(_call, b, 0)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, O3._IluClass, _ecode)
                _result = iluRt.InputInteger(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['O3'] = iluRt.RegisterObjectType(O3, ('Test1','O3',), None, None)

class O4(O3):
    _IluClass = iluRt.FormClassRecord(
        'Test1.O4',
        '',
        'ilut:opvprHFYnSQTgU+rwo8xAJFn3CQ',
        None,
        iluRt.FALSE,
        iluRt.FALSE,
        None,
        (
            ('R-to-R', 1, iluRt.FALSE, iluRt.FALSE, "ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP", (('r', 0, 0, 'ilut:p9LouGgQ-eJLx53RwIV-rdnpmNP'),), ()),
        ),
        (O3._IluClass,)
    )

    def R_to_R(_self, r):
        _result = None
        _call = iluRt.BeginCall(_self, O4._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, O4)
                    + iluRt.SizeOfReal(_call, r))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, O4)
                iluRt.OutputReal(_call, r)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, O4._IluClass, _ecode)
                _result = iluRt.InputReal(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['O4'] = iluRt.RegisterObjectType(O4, ('Test1','O4',), None, None)

class P(O3):
    _IluClass = iluRt.FormClassRecord(
        'Test1.P',
        '',
        'ilut:dY9O+Pbe716S3dZTXTUzbvfKs87',
        None,
        iluRt.FALSE,
        iluRt.FALSE,
        None,
        (
            ('m2', 1, iluRt.FALSE, iluRt.FALSE, "ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO", (('j', 0, 0, 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY'),), ()),
        ),
        (O3._IluClass,)
    )

    def m2(_self, j):
        _result = None
        _call = iluRt.BeginCall(_self, P._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, P)
                    + iluRt.SizeOfInteger(_call, j))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, P)
                iluRt.OutputInteger(_call, j)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, P._IluClass, _ecode)
                _result = _Input_IS(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['P'] = iluRt.RegisterObjectType(P, ('Test1','P',), None, None)

class TheO1(iluRt.IluObjSurr):
    """sample
    multi-line doc string    """    _IluClass = iluRt.FormClassRecord(
        'Test1.TheO1',
        '',
        'ilut:fmBFu4mQpwjov+CekDxhjwxkgty',
        None,
        iluRt.FALSE,
        iluRt.FALSE,
        None,
        (
            ('U-CSS-to-U', 1, iluRt.FALSE, iluRt.FALSE, "ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW", (('u', 0, 0, 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW'), ('css', 0, 0, 'ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy')), (('ilu:Test1.E1', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW',), ('ilu:Test1.E2', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY',))),
            ('f-CSS-to-RO', 2, iluRt.TRUE, iluRt.FALSE, "ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2", (('css', 0, 0, 'ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy'),), (('ilu:Test1.E1', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW',),)),
            ('R-ScS-to-F', 3, iluRt.FALSE, iluRt.FALSE, "ilut:h9V4l47a8J5CGp2fg6ZpsYhXPSO", (('r', 0, 0, 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7'), ('s', 0, 0, 'ilut:iqqhSf395+BafbY8Oo2elFQD1bK')), ()),
            ('a-RO', 4, iluRt.FALSE, iluRt.TRUE, None, (('ro', 0, 0, 'ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2'),), ()),
            ('get-O2', 5, iluRt.FALSE, iluRt.FALSE, "ilut:jXB9BUoPU7650cspZmJCl3y4zzu", (), (('ilu:Test1.CantCreate',),)),
            ('get-O3', 6, iluRt.FALSE, iluRt.FALSE, "ilut:kIcGG8a2ke5Wa9+mDM-6ArsNDpU", (('subclass', 0, 0, 'ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I'),), (('ilu:Test1.CantCreate',),)),
        ),
        ()
    )

    def U_CSS_to_U(_self, u, css):
        _result = None
        _call = iluRt.BeginCall(_self, TheO1._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, TheO1)
                    + _SizeOf_TheU(_call, u)
                    + _SizeOf_CSS(_call, css))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, TheO1)
                _Output_TheU(_call, u)
                _Output_CSS(_call, css)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, TheO1._IluClass, _ecode)
                _result = _Input_TheU(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

    def f_CSS_to_RO(_self, css):
        _result = None
        _call = iluRt.BeginCall(_self, TheO1._IluClass, 2)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, TheO1)
                    + _SizeOf_CSS(_call, css))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, TheO1)
                _Output_CSS(_call, css)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, TheO1._IluClass, _ecode)
                _result = _Input_RO(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

    def R_ScS_to_F(_self, r, s):
        _result = None
        _call = iluRt.BeginCall(_self, TheO1._IluClass, 3)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, TheO1)
                    + _SizeOf_TheR(_call, r)
                    + iluRt.SizeOfString(_call, s, 0))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, TheO1)
                _Output_TheR(_call, r)
                iluRt.OutputString(_call, s, 0)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, TheO1._IluClass, _ecode)
                _result = iluRt.InputShortReal(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

    def a_RO(_self, ro):
        _call = iluRt.BeginCall(_self, TheO1._IluClass, 4)
        try:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, TheO1)
                    + _SizeOf_RO(_call, ro))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, TheO1)
                _Output_RO(_call, ro)
                iluRt.FinishRequest(_call)
        finally:
            iluRt.FinishCall(_call)

    def get_O2(_self):
        _result = None
        _call = iluRt.BeginCall(_self, TheO1._IluClass, 5)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, TheO1))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, TheO1)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, TheO1._IluClass, _ecode)
                _result = iluRt.InputObjectID(_call, iluRt.FALSE, O2)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

    def get_O3(_self, subclass):
        _result = None
        _call = iluRt.BeginCall(_self, TheO1._IluClass, 6)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, TheO1)
                    + iluRt.SizeOfBoolean(_call, subclass))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, TheO1)
                iluRt.OutputBoolean(_call, subclass)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, TheO1._IluClass, _ecode)
                _result = iluRt.InputObjectID(_call, iluRt.FALSE, O3)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['TheO1'] = iluRt.RegisterObjectType(TheO1, ('Test1','TheO1',), None, """sample
multi-line doc string""")

def _Input_U_scard(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_shortcardinal)
    if _d == 0:
        _value = (_d, _Input_TheR(_call))
    elif _d == 1:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, TheO1))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_U_scard(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_shortcardinal)
    if _d == 0:
        _Output_TheR(_call, _value)
    elif _d == 1:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, TheO1)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_U_scard(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_shortcardinal)
    if _d == 0:
        _size = _size + _SizeOf_TheR(_call, _value)
    elif _d == 1:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, TheO1)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['U_scard'] = iluRt.RegisterUnionType(('Test1','U-scard',), None, 'ilut:jAPE1zV6LdNhqmjYERCpES3yBpF', 'ilut:k9dNYEhQmo4Yk0ZjuedVR90f0-Y', iluRt.TypeKind_shortcardinal, 0, 0, (('', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', (0,)), ('', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty', (1,))))
iluRt.RegisterIoFuncs('ilut:jAPE1zV6LdNhqmjYERCpES3yBpF', _Input_U_scard, _Output_U_scard, _SizeOf_U_scard, 'Test1.U-scard')

One = TheO1

__types__['One'] = iluRt.RegisterAliasType(('Test1','One',), None, 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty')
iluRt.NoteAlias('Test1.One', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty')

def _Input_U_card(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_cardinal)
    if _d == 0:
        _value = (_d, _Input_TheR(_call))
    elif _d == 1:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O2))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_U_card(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_cardinal)
    if _d == 0:
        _Output_TheR(_call, _value)
    elif _d == 1:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_U_card(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_cardinal)
    if _d == 0:
        _size = _size + _SizeOf_TheR(_call, _value)
    elif _d == 1:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['U_card'] = iluRt.RegisterUnionType(('Test1','U-card',), None, 'ilut:nY7eVP682HUe0ogce3ooQPrruH2', 'ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO', iluRt.TypeKind_cardinal, 0, 0, (('', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', (0,)), ('', 'ilut:jXB9BUoPU7650cspZmJCl3y4zzu', (1,))))
iluRt.RegisterIoFuncs('ilut:nY7eVP682HUe0ogce3ooQPrruH2', _Input_U_card, _Output_U_card, _SizeOf_U_card, 'Test1.U-card')

def _Input_U_int(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_integer)
    if _d == 0:
        _value = (_d, _Input_TheR(_call))
    elif _d == 1:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O2))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_U_int(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_integer)
    if _d == 0:
        _Output_TheR(_call, _value)
    elif _d == 1:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_U_int(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_integer)
    if _d == 0:
        _size = _size + _SizeOf_TheR(_call, _value)
    elif _d == 1:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['U_int'] = iluRt.RegisterUnionType(('Test1','U-int',), None, 'ilut:b8uuARf6GuBoeD-p8pOwYMjTZ69', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY', iluRt.TypeKind_integer, 0, 0, (('', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', (0,)), ('', 'ilut:jXB9BUoPU7650cspZmJCl3y4zzu', (1,))))
iluRt.RegisterIoFuncs('ilut:b8uuARf6GuBoeD-p8pOwYMjTZ69', _Input_U_int, _Output_U_int, _SizeOf_U_int, 'Test1.U-int')

def _Input_U_byte(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_byte)
    if _d == 0:
        _value = (_d, _Input_TheR(_call))
    elif _d == 1:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O2))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_U_byte(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_byte)
    if _d == 0:
        _Output_TheR(_call, _value)
    elif _d == 1:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_U_byte(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_byte)
    if _d == 0:
        _size = _size + _SizeOf_TheR(_call, _value)
    elif _d == 1:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['U_byte'] = iluRt.RegisterUnionType(('Test1','U-byte',), None, 'ilut:eEo4ZOFawZcut8dv19+C65eQlWg', 'ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc', iluRt.TypeKind_byte, 0, 0, (('', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', (0,)), ('', 'ilut:jXB9BUoPU7650cspZmJCl3y4zzu', (1,))))
iluRt.RegisterIoFuncs('ilut:eEo4ZOFawZcut8dv19+C65eQlWg', _Input_U_byte, _Output_U_byte, _SizeOf_U_byte, 'Test1.U-byte')

def _Input_U4(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_shortinteger)
    if _d in (3, 7):
        _value = (_d, iluRt.InputBoolean(_call))
    elif _d in (1, 0):
        _value = (_d, _Input_CSS(_call))
    else:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O2))
    iluRt.EndUnion(_call)
    return _value

def _Output_U4(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d in (3, 7):
        iluRt.OutputBoolean(_call, _value)
    elif _d in (1, 0):
        _Output_CSS(_call, _value)
    else:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O2)
    iluRt.EndUnion(_call)

def _SizeOf_U4(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d in (3, 7):
        _size = _size + iluRt.SizeOfBoolean(_call, _value)
    elif _d in (1, 0):
        _size = _size + _SizeOf_CSS(_call, _value)
    else:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O2)
    iluRt.EndUnion(_call)
    return _size

__types__['U4'] = iluRt.RegisterUnionType(('Test1','U4',), None, 'ilut:iqhShhLIYYhlWJMKqapun2JReYg', 'ilut:fOLheADuTmKcJTSlmY16DQWP1YJ', iluRt.TypeKind_shortinteger, 2, 0, (('x1', 'ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I', (3, 7)), ('x2', 'ilut:jXB9BUoPU7650cspZmJCl3y4zzu', ()), ('x3', 'ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy', (1, 0))))
iluRt.RegisterIoFuncs('ilut:iqhShhLIYYhlWJMKqapun2JReYg', _Input_U4, _Output_U4, _SizeOf_U4, 'Test1.U4')

def _Input_U3(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_enumeration)
    if _d == TheE.ev1:
        _value = (_d, iluRt.InputString(_call, 0))
    elif _d == TheE.ev3:
        _value = (_d, _Input_U2(_call))
    elif _d == TheE.ev7:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O2))
    else:
        _value = (_d, _Input_RO(_call))
    iluRt.EndUnion(_call)
    return _value

def _Output_U3(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_enumeration)
    if _d == TheE.ev1:
        iluRt.OutputString(_call, _value, 0)
    elif _d == TheE.ev3:
        _Output_U2(_call, _value)
    elif _d == TheE.ev7:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        _Output_RO(_call, _value)
    iluRt.EndUnion(_call)

def _SizeOf_U3(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_enumeration)
    if _d == TheE.ev1:
        _size = _size + iluRt.SizeOfString(_call, _value, 0)
    elif _d == TheE.ev3:
        _size = _size + _SizeOf_U2(_call, _value)
    elif _d == TheE.ev7:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        _size = _size + _SizeOf_RO(_call, _value)
    iluRt.EndUnion(_call)
    return _size

__types__['U3'] = iluRt.RegisterUnionType(('Test1','U3',), None, 'ilut:b2Q65O-JOci2N0htlZ+qn5HntNj', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', iluRt.TypeKind_enumeration, 4, 0, (('', 'ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv', ('ev1',)), ('', 'ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9', ('ev3',)), ('v3', 'ilut:jXB9BUoPU7650cspZmJCl3y4zzu', ('ev7',)), ('v4', 'ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2', ())))
iluRt.RegisterIoFuncs('ilut:b2Q65O-JOci2N0htlZ+qn5HntNj', _Input_U3, _Output_U3, _SizeOf_U3, 'Test1.U3')

def _Input_U2(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_shortinteger)
    if _d in (3, 7):
        _value = (_d, iluRt.InputBoolean(_call))
    elif _d in (1, 22):
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O2))
    elif _d == 2:
        _value = (_d, _Input_CSS(_call))
    else:
        _value = (_d, None)
    iluRt.EndUnion(_call)
    return _value

def _Output_U2(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d in (3, 7):
        iluRt.OutputBoolean(_call, _value)
    elif _d in (1, 22):
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O2)
    elif _d == 2:
        _Output_CSS(_call, _value)
    else:
        pass
    iluRt.EndUnion(_call)

def _SizeOf_U2(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d in (3, 7):
        _size = _size + iluRt.SizeOfBoolean(_call, _value)
    elif _d in (1, 22):
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O2)
    elif _d == 2:
        _size = _size + _SizeOf_CSS(_call, _value)
    else:
        pass
    iluRt.EndUnion(_call)
    return _size

__types__['U2'] = iluRt.RegisterUnionType(('Test1','U2',), None, 'ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9', 'ilut:fOLheADuTmKcJTSlmY16DQWP1YJ', iluRt.TypeKind_shortinteger, 0, 1, (('x1', 'ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I', (3, 7)), ('x2', 'ilut:jXB9BUoPU7650cspZmJCl3y4zzu', (1, 22)), ('x3', 'ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy', (2,))))
iluRt.RegisterIoFuncs('ilut:ivO--2zVG+1M+RHVb2fSMGm5pW9', _Input_U2, _Output_U2, _SizeOf_U2, 'Test1.U2')

class TheE:
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

__types__['TheE'] = iluRt.RegisterEnumerationType(('Test1','TheE',), None, 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', (('ev1', 0), ('ev3', 3), ('ev5', 4), ('ev7', 5)))
iluRt.RegisterIoFuncs('ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', iluRt.InputEnum, iluRt.OutputEnum, iluRt.SizeOfEnum, 'Test1.TheE')

class E:
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

__types__['E'] = iluRt.RegisterAliasType(('Test1','E',), None, 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh')
iluRt.NoteAlias('Test1.E', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh', 'ilut:krAAJGDr0mWg96aGb8cRAqq6LEh')

def _Input_U1(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_shortinteger)
    if _d == 0:
        _value = (_d, _Input_TheR(_call))
    elif _d == 1:
        _value = (_d, _Input_TheA1(_call))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_U1(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d == 0:
        _Output_TheR(_call, _value)
    elif _d == 1:
        _Output_TheA1(_call, _value)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_U1(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d == 0:
        _size = _size + _SizeOf_TheR(_call, _value)
    elif _d == 1:
        _size = _size + _SizeOf_TheA1(_call, _value)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['U1'] = iluRt.RegisterUnionType(('Test1','U1',), None, 'ilut:jzGuxkzcjrh34B-89hMcq2ovHB6', 'ilut:fOLheADuTmKcJTSlmY16DQWP1YJ', iluRt.TypeKind_shortinteger, 0, 0, (('', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', (0,)), ('', 'ilut:h3Dnvis94UwnmFURfYsCp700jVy', (1,))))
iluRt.RegisterIoFuncs('ilut:jzGuxkzcjrh34B-89hMcq2ovHB6', _Input_U1, _Output_U1, _SizeOf_U1, 'Test1.U1')

def _Input_TheU(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_shortinteger)
    if _d == 0:
        _value = (_d, _Input_TheR(_call))
    elif _d == 1:
        _value = (_d, _Input_RO(_call))
    elif _d == 2:
        _value = (_d, _Input_CSS(_call))
    elif _d == 3:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, TheO1))
    elif _d == 4:
        _value = (_d, _Input_TheOO(_call))
    elif _d == 5:
        _value = (_d, iluRt.InputBoolean(_call))
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _value

def _Output_TheU(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d == 0:
        _Output_TheR(_call, _value)
    elif _d == 1:
        _Output_RO(_call, _value)
    elif _d == 2:
        _Output_CSS(_call, _value)
    elif _d == 3:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, TheO1)
    elif _d == 4:
        _Output_TheOO(_call, _value)
    elif _d == 5:
        iluRt.OutputBoolean(_call, _value)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)

def _SizeOf_TheU(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_shortinteger)
    if _d == 0:
        _size = _size + _SizeOf_TheR(_call, _value)
    elif _d == 1:
        _size = _size + _SizeOf_RO(_call, _value)
    elif _d == 2:
        _size = _size + _SizeOf_CSS(_call, _value)
    elif _d == 3:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, TheO1)
    elif _d == 4:
        _size = _size + _SizeOf_TheOO(_call, _value)
    elif _d == 5:
        _size = _size + iluRt.SizeOfBoolean(_call, _value)
    else:
        raise Exception( TypeError)
    iluRt.EndUnion(_call)
    return _size

__types__['TheU'] = iluRt.RegisterUnionType(('Test1','TheU',), None, 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW', 'ilut:fOLheADuTmKcJTSlmY16DQWP1YJ', iluRt.TypeKind_shortinteger, 0, 0, (('', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', (0,)), ('', 'ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2', (1,)), ('', 'ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy', (2,)), ('', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty', (3,)), ('', 'ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA', (4,)), ('', 'ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I', (5,))))
iluRt.RegisterIoFuncs('ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW', _Input_TheU, _Output_TheU, _SizeOf_TheU, 'Test1.TheU')

__types__['U'] = iluRt.RegisterAliasType(('Test1','U',), None, 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW')
iluRt.NoteAlias('Test1.U', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW', 'ilut:dYT-4t7fpcGfoI1YwPfwUxuLiSW')

def _Input_OO2(_call):
    _d = iluRt.InputUnion(_call, iluRt.TypeKind_boolean)
    if _d == 1:
        _value = (_d, iluRt.InputObjectID(_call, iluRt.FALSE, O2))
    else:
        _value = (_d, None)
    iluRt.EndUnion(_call)
    return _value

def _Output_OO2(_call, _value):
    _d = _value[0]
    _value = _value[1]
    iluRt.OutputUnion(_call, _d, iluRt.TypeKind_boolean)
    if _d == 1:
        iluRt.OutputObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        pass
    iluRt.EndUnion(_call)

def _SizeOf_OO2(_call, _value):
    _d = _value[0]
    _value = _value[1]
    _size = iluRt.SizeOfUnion(_call, _d, iluRt.TypeKind_boolean)
    if _d == 1:
        _size = _size + iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, O2)
    else:
        pass
    iluRt.EndUnion(_call)
    return _size

__types__['OO2'] = iluRt.RegisterUnionType(('Test1','OO2',), None, 'ilut:l-kEjRgqgSEZbJTDUfMwmrp5361', 'ilut:aAKxafHj0BIiFHR4LmrEzKJHc-I', iluRt.TypeKind_boolean, 0, 1, (('', 'ilut:jXB9BUoPU7650cspZmJCl3y4zzu', (1,)),))
iluRt.RegisterIoFuncs('ilut:l-kEjRgqgSEZbJTDUfMwmrp5361', _Input_OO2, _Output_OO2, _SizeOf_OO2, 'Test1.OO2')

class O2(iluRt.IluObjSurr):
    """sample multi-line
        doc string with leading whitespace on the second line    """    _IluClass = iluRt.FormClassRecord(
        'Test1.O2',
        '',
        'ilut:jXB9BUoPU7650cspZmJCl3y4zzu',
        'sunrpc_2_0x3458_3',
        iluRt.FALSE,
        iluRt.FALSE,
        None,
        (
            ('OO-A0-to-CSS', 1, iluRt.FALSE, iluRt.FALSE, "ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy", (('o', 0, 0, 'ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA'), ('a', 0, 0, 'ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r')), (('ilu:Test1.E2', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY',),)),
            ('R-I-A1-to-I-A0', 2, iluRt.FALSE, iluRt.FALSE, "ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r", (('r', 0, 0, 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7'), ('i', 2, 0, 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY'), ('a', 0, 0, 'ilut:h3Dnvis94UwnmFURfYsCp700jVy')), ()),
        ),
        ()
    )

    def OO_A0_to_CSS(_self, o, a):
        _result = None
        _call = iluRt.BeginCall(_self, O2._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    0
                    + _SizeOf_TheOO(_call, o)
                    + iluRt.SizeOfOpaque(_call, a, 8))
                _Output_TheOO(_call, o)
                iluRt.OutputOpaque(_call, a, 8)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, O2._IluClass, _ecode)
                _result = _Input_CSS(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

    def R_I_A1_to_I_A0(_self, r, i, a):
        _result = None
        _call = iluRt.BeginCall(_self, O2._IluClass, 2)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    0
                    + _SizeOf_TheR(_call, r)
                    + iluRt.SizeOfInteger(_call, i)
                    + _SizeOf_TheA1(_call, a))
                _Output_TheR(_call, r)
                iluRt.OutputInteger(_call, i)
                _Output_TheA1(_call, a)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, O2._IluClass, _ecode)
                _result = iluRt.InputOpaque(_call, 8),\
                    iluRt.InputInteger(_call)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['O2'] = iluRt.RegisterObjectType(O2, ('Test1','O2',), None, """sample multi-line
    doc string with leading whitespace on the second line""")

def _Input_TheOO(_call):
    return iluRt.InputOptional(_call) and iluRt.InputObjectID(_call, iluRt.FALSE, TheO1)

def _Output_TheOO(_call, _value):
    iluRt.OutputOptional(_call, (_value != None)) or ((_value != None) and iluRt.OutputObjectID(_call, _value, iluRt.FALSE, TheO1))

def _SizeOf_TheOO(_call, _value):
    return iluRt.SizeOfOptional(_call, (_value != None)) + ((_value != None) and iluRt.SizeOfObjectID(_call, _value, iluRt.FALSE, TheO1))

__types__['TheOO'] = iluRt.RegisterOptionalType(('Test1','TheOO',), None, 'ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty')
iluRt.RegisterIoFuncs('ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA', _Input_TheOO, _Output_TheOO, _SizeOf_TheOO, 'Test1.TheOO')

__types__['OO'] = iluRt.RegisterAliasType(('Test1','OO',), None, 'ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA', 'ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA')
iluRt.NoteAlias('Test1.OO', 'ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA', 'ilut:i9j-e0MTap9-HvwoTuOR4HVGRXA')

O1 = TheO1

__types__['O1'] = iluRt.RegisterAliasType(('Test1','O1',), None, 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty')
iluRt.NoteAlias('Test1.O1', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty', 'ilut:fmBFu4mQpwjov+CekDxhjwxkgty')

def _Input_RO(_call):
    return iluRt.InputOptional(_call) and _Input_TheR(_call)

def _Output_RO(_call, _value):
    iluRt.OutputOptional(_call, (_value != None)) or ((_value != None) and _Output_TheR(_call, _value))

def _SizeOf_RO(_call, _value):
    return iluRt.SizeOfOptional(_call, (_value != None)) + ((_value != None) and _SizeOf_TheR(_call, _value))

__types__['RO'] = iluRt.RegisterOptionalType(('Test1','RO',), None, 'ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7')
iluRt.RegisterIoFuncs('ilut:gicz6vvSCMp2VXZRiq6KTWQh7p2', _Input_RO, _Output_RO, _SizeOf_RO, 'Test1.RO')

def _Input_TheRS(_call):
    _length = iluRt.InputSequence(_call, 0)
    _value = []
    for _i in range(0, _length):
        _value.append(_Input_TheR(_call))
    iluRt.EndSequence(_call)
    return _value

def _Output_TheRS(_call, _value):
    iluRt.OutputSequence(_call, len(_value), 0)
    for _i in range(0, len(_value)):
        _Output_TheR(_call, _value[_i])
    iluRt.EndSequence(_call)

def _SizeOf_TheRS(_call, _value):
    _size = iluRt.SizeOfSequence(_call, len(_value), 0)
    for _i in range(0, len(_value)):
        _size = _size + _SizeOf_TheR(_call, _value[_i])
    iluRt.EndSequence(_call)
    return _size

__types__['TheRS'] = iluRt.RegisterSequenceType(('Test1','TheRS',), None, 'ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', 0)
iluRt.RegisterIoFuncs('ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac', _Input_TheRS, _Output_TheRS, _SizeOf_TheRS, 'Test1.TheRS')

__types__['RS'] = iluRt.RegisterAliasType(('Test1','RS',), None, 'ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac', 'ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac')
iluRt.NoteAlias('Test1.RS', 'ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac', 'ilut:dHs+dKhOHPjZlhqF+GcshQD3Zac')

def _Input_TheR(_call):
    iluRt.InputRecord(_call)
    _value = TheR (None, None, None)
    _value.a = _Input_TheA1(_call)
    _value.css = _Input_CSS(_call)
    _value.i = iluRt.InputInteger(_call)
    iluRt.EndRecord(_call)
    return _value

def _Output_TheR(_call, _value):
    iluRt.OutputRecord(_call)
    _Output_TheA1(_call, _value['a'])
    _Output_CSS(_call, _value['css'])
    iluRt.OutputInteger(_call, _value['i'])
    iluRt.EndRecord(_call)

def _SizeOf_TheR(_call, _value):
    _size = iluRt.SizeOfRecord(_call)\
        + _SizeOf_TheA1(_call, _value['a'])\
        + _SizeOf_CSS(_call, _value['css'])\
        + iluRt.SizeOfInteger(_call, _value['i'])
    iluRt.EndRecord(_call)
    return _size

class TheR (iluRt.IluRecord):
    __ilu_type_name__ = 'Test1.TheR'
    def __init__(self, _arg_a, _arg_css, _arg_i):
        self.a = _arg_a;
        self.css = _arg_css;
        self.i = _arg_i;

    def __getinitargs__(self):
        return (self.a, self.css, self.i, )

__types__['TheR'] = iluRt.RegisterRecordType(('Test1','TheR',), None, 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', (('a', 'ilut:h3Dnvis94UwnmFURfYsCp700jVy'),('css', 'ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy'),('i', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY'),), 0, None)
iluRt.RegisterIoFuncs('ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', _Input_TheR, _Output_TheR, _SizeOf_TheR, 'Test1.TheR')

__types__['R'] = iluRt.RegisterAliasType(('Test1','R',), None, 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7')
iluRt.NoteAlias('Test1.R', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7', 'ilut:aRm1NNwKmLTCta84rO4Q+MwTPU7')

def _Input_BS(_call):
    return iluRt.InputBytes(_call, 0)

def _Output_BS(_call, _value):
    iluRt.OutputBytes (_call, _value, 0)

def _SizeOf_BS(_call, _value):
    return iluRt.SizeOfBytes (_call, _value, 0)

__types__['BS'] = iluRt.RegisterSequenceType(('Test1','BS',), None, 'ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3', 'ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc', 0)
iluRt.RegisterIoFuncs('ilut:pqH8Qk4ZmLS8dZdSROhgJ7Xs0n3', _Input_BS, _Output_BS, _SizeOf_BS, 'Test1.BS')

def _Input_A2(_call):
    iluRt.InputArray(_call)
    _value0 = []
    for _i0 in range(0,3):
        _value1 = []
        for _i1 in range(0,4):
            _value1.append(iluRt.InputCardinal(_call))
        _value0.append(_value1)
    iluRt.EndArray(_call)
    return _value0

def _Output_A2(_call, _value):
    iluRt.OutputArray(_call, 12)
    for _i0 in range(0,3):
        for _i1 in range(0,4):
            iluRt.OutputCardinal(_call, _value[_i0][_i1])
    iluRt.EndArray(_call)

def _SizeOf_A2(_call, _value):
    _size = iluRt.SizeOfArray(_call, 12)
    for _i0 in range(0,3):
        for _i1 in range(0,4):
            _size = _size + iluRt.SizeOfCardinal(_call, _value[_i0][_i1])
    iluRt.EndArray(_call)
    return _size

__types__['A2'] = iluRt.RegisterArrayType(('Test1','A2',), None, 'ilut:kM2HH51HMYTWu-khgczpbgNaama', 'ilut:a9utKC9pScVOm5pXhcjtN2yJ5nO', (3,4,))
iluRt.RegisterIoFuncs('ilut:kM2HH51HMYTWu-khgczpbgNaama', _Input_A2, _Output_A2, _SizeOf_A2, 'Test1.A2')

def _Input_TheA1(_call):
    iluRt.InputArray(_call)
    _value0 = []
    for _i0 in range(0,3):
        _value0.append(iluRt.InputString(_call, 0))
    iluRt.EndArray(_call)
    return _value0

def _Output_TheA1(_call, _value):
    iluRt.OutputArray(_call, 3)
    for _i0 in range(0,3):
        iluRt.OutputString(_call, _value[_i0], 0)
    iluRt.EndArray(_call)

def _SizeOf_TheA1(_call, _value):
    _size = iluRt.SizeOfArray(_call, 3)
    for _i0 in range(0,3):
        _size = _size + iluRt.SizeOfString(_call, _value[_i0], 0)
    iluRt.EndArray(_call)
    return _size

__types__['TheA1'] = iluRt.RegisterArrayType(('Test1','TheA1',), None, 'ilut:h3Dnvis94UwnmFURfYsCp700jVy', 'ilut:iqqhSf395+BafbY8Oo2elFQD1bK', (3,))
iluRt.RegisterIoFuncs('ilut:h3Dnvis94UwnmFURfYsCp700jVy', _Input_TheA1, _Output_TheA1, _SizeOf_TheA1, 'Test1.TheA1')

__types__['A1'] = iluRt.RegisterAliasType(('Test1','A1',), None, 'ilut:h3Dnvis94UwnmFURfYsCp700jVy', 'ilut:h3Dnvis94UwnmFURfYsCp700jVy')
iluRt.NoteAlias('Test1.A1', 'ilut:h3Dnvis94UwnmFURfYsCp700jVy', 'ilut:h3Dnvis94UwnmFURfYsCp700jVy')

def _Input_A0(_call):
    return iluRt.InputOpaque(_call, 8);

def _Output_A0(_call, _value):
    iluRt.OutputOpaque (_call, _value, 8)

def _SizeOf_A0(_call, _value):
    return iluRt.SizeOfOpaque (_call, _value, 8)

__types__['A0'] = iluRt.RegisterArrayType(('Test1','A0',), None, 'ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r', 'ilut:a2Wo1vyRyBxuTRuOUfTsea5vmbc', (8,))
iluRt.RegisterIoFuncs('ilut:lZ4k5ayTnMAG2-pHyyivWhH8y5r', _Input_A0, _Output_A0, _SizeOf_A0, 'Test1.A0')

def _Input_CSS(_call):
    _length = iluRt.InputSequence(_call, 0)
    _value = []
    for _i in range(0, _length):
        _value.append(iluRt.InputString(_call, 0))
    iluRt.EndSequence(_call)
    return _value

def _Output_CSS(_call, _value):
    iluRt.OutputSequence(_call, len(_value), 0)
    for _i in range(0, len(_value)):
        iluRt.OutputString(_call, _value[_i], 0)
    iluRt.EndSequence(_call)

def _SizeOf_CSS(_call, _value):
    _size = iluRt.SizeOfSequence(_call, len(_value), 0)
    for _i in range(0, len(_value)):
        _size = _size + iluRt.SizeOfString(_call, _value[_i], 0)
    iluRt.EndSequence(_call)
    return _size

__types__['CSS'] = iluRt.RegisterSequenceType(('Test1','CSS',), None, 'ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy', 'ilut:iqqhSf395+BafbY8Oo2elFQD1bK', 0)
iluRt.RegisterIoFuncs('ilut:f-6N-TJeDtWrjsoVoolxLZVOEJy', _Input_CSS, _Output_CSS, _SizeOf_CSS, 'Test1.CSS')

def _Input_ScS(_call):
    return iluRt.InputString(_call, 0)

def _Output_ScS(_call, _value):
    iluRt.OutputString (_call, _value, 0)

def _SizeOf_ScS(_call, _value):
    return iluRt.SizeOfString (_call, _value, 0)

__types__['ScS'] = iluRt.RegisterSequenceType(('Test1','ScS',), None, 'ilut:iqqhSf395+BafbY8Oo2elFQD1bK', 'ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0', 0)
iluRt.RegisterIoFuncs('ilut:iqqhSf395+BafbY8Oo2elFQD1bK', _Input_ScS, _Output_ScS, _SizeOf_ScS, 'Test1.ScS')

__types__['C'] = iluRt.RegisterAliasType(('Test1','C',), None, 'ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx', 'ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx')
iluRt.NoteAlias('Test1.C', 'ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx', 'ilut:gdcPNJEAtHcOYaSV7ue4O0N8kXx')

__types__['SC'] = iluRt.RegisterAliasType(('Test1','SC',), None, 'ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0', 'ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0')
iluRt.NoteAlias('Test1.SC', 'ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0', 'ilut:pdAUFqZte+fyI-N5f1DgbGKd0K0')

def _Input_IS(_call):
    _length = iluRt.InputSequence(_call, 0)
    _value = []
    for _i in range(0, _length):
        _value.append(iluRt.InputInteger(_call))
    iluRt.EndSequence(_call)
    return _value

def _Output_IS(_call, _value):
    iluRt.OutputSequence(_call, len(_value), 0)
    for _i in range(0, len(_value)):
        iluRt.OutputInteger(_call, _value[_i])
    iluRt.EndSequence(_call)

def _SizeOf_IS(_call, _value):
    _size = iluRt.SizeOfSequence(_call, len(_value), 0)
    for _i in range(0, len(_value)):
        _size = _size + iluRt.SizeOfInteger(_call, _value[_i])
    iluRt.EndSequence(_call)
    return _size

__types__['IS'] = iluRt.RegisterSequenceType(('Test1','IS',), None, 'ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY', 0)
iluRt.RegisterIoFuncs('ilut:m0OjAX3I12PfKGHyJuMQ9fcV+qO', _Input_IS, _Output_IS, _SizeOf_IS, 'Test1.IS')

__types__['I'] = iluRt.RegisterAliasType(('Test1','I',), None, 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY')
iluRt.NoteAlias('Test1.I', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY', 'ilut:ggrbg-q7UoqiAlNTWvqkwfZ4rlY')

E1__ExcnID = 'ilu:Test1.E1'
E2__ExcnID = 'ilu:Test1.E2'
CantCreate__ExcnID = 'ilu:Test1.CantCreate'
E3__ExcnID = 'ilu:Test1.E3'
E4__ExcnID = 'ilu:Test1.E4'
E5__ExcnID = 'ilu:Test1.E5'
E6__ExcnID = 'ilu:Test1.E6'
E7__ExcnID = 'ilu:Test1.E7'
E8__ExcnID = 'ilu:Test1.E8'
E9__ExcnID = 'ilu:Test1.E9'

E1 = E1__ExcnID
class E1(Exception):
    def __init__(self,value):
        self.value=value
E2 = E2__ExcnID
class E2(Exception):
    def __init__(self,value):
        self.value=value
CantCreate = CantCreate__ExcnID
class CantCreate(Exception):
    def __init__(self):
        pass
E3 = E3__ExcnID
class E3(Exception):
    def __init__(self,value):
        self.value=value
E4 = E4__ExcnID
class E4(Exception):
    def __init__(self,value):
        self.value=value
E5 = E5__ExcnID
class E5(Exception):
    def __init__(self,value):
        self.value=value
E6 = E6__ExcnID
class E6(Exception):
    def __init__(self,value):
        self.value=value
E7 = E7__ExcnID
class E7(Exception):
    def __init__(self,value):
        self.value=value
E8 = E8__ExcnID
class E8(Exception):
    def __init__(self,value):
        self.value=value
E9 = E9__ExcnID
class E9(Exception):
    def __init__(self,value):
        self.value=value

def _CatchException(_call, _IluClass, _ecode):
    _value = None
    _name = iluRt.ExceptionName(_call, _IluClass, _ecode)
    if _name == E1__ExcnID:
        _value = _Input_TheU(_call)
        _name = E1(_value)
    elif _name == E2__ExcnID:
        _value = iluRt.InputInteger(_call)
        _name = E2(_value)
    elif _name == CantCreate__ExcnID:
        _name = CantCreate(_value)
    elif _name == E3__ExcnID:
        _value = _Input_RO(_call)
        _name = E3(_value)
    elif _name == E4__ExcnID:
        _value = iluRt.InputObjectID(_call, iluRt.FALSE, TheO1)
        _name = E4(_value)
    elif _name == E5__ExcnID:
        _value = iluRt.InputOpaque(_call, 8)
        _name = E5(_value)
    elif _name == E6__ExcnID:
        _value = _Input_TheRS(_call)
        _name = E6(_value)
    elif _name == E7__ExcnID:
        _value = iluRt.InputString(_call, 0)
        _name = E7(_value)
    elif _name == E8__ExcnID:
        _value = _Input_TheA1(_call)
        _name = E8(_value)
    elif _name == E9__ExcnID:
        _value = _Input_TheR(_call)
        _name = E9(_value)
    raise _name
