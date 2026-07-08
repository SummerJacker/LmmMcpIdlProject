# Skeletons for "Test2"
#
# This file was automatically generated with KISORB (version 2.0beta1) tools
# at Fri Aug 22 17:23:11 2025 by `沈阳市软件定义智能协同重点实验室'
# running "D:/Shaun-projects/newstar/Iluhome/bin/python-stubber.exe" of Mon Aug 18 11:47:25 2025
# on "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test2.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/Test1.isl" of Sat Aug 02 18:01:34 2025,
# and "D:/Shaun-projects/newstar/Iluhome/examples/test1/ilu.isl" of Fri Aug 01 14:15:57 2025#
# KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
# KISORB information: Dr. Wang xcwang89@aliyun.com .

import sys;
_imported_modules = {};
import iluRt ; _imported_modules['iluRt'] = iluRt; _imported_modules['ilu'] = iluRt;
iluRt.CheckStubConsistency('2.0beta1', 'v2 (2.0beta1)');
_imported_modules['ilu__skel'] = iluRt
del iluRt
import Test2; _imported_modules['Test2'] = Test2; del Test2;
import Test1; _imported_modules['Test1'] = Test1; del Test1;
import Test1__skel; _imported_modules['Test1__skel'] = Test1__skel; del Test1__skel;
import iluRt

T1O3 = _imported_modules['Test1__skel'].O3

def _P__SR_to_I(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['Test2'].P)
    i = iluRt.InputShortReal(_call)
    iluRt.RequestRead(_call)
    try:
        _result = _self.SR_to_I(i)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + iluRt.SizeOfInteger(_call, _result))
    iluRt.OutputInteger(_call, _result)
    iluRt.FinishReply(_call)


iluRt.RegisterSkeletons(_imported_modules['Test2'].P._IluClass, (
    _P__SR_to_I,))


class P(iluRt.IluObjTrue):
    _IluClass = _imported_modules['Test2'].P._IluClass

    def SR_to_I(_self, i):
        raise Exception(iluRt.IluUnimplementedMethodError, 'SR-to-I')

