# Skeletons for "Test2"
#
# This file was automatically generated with KIS-CORBA (version 2.0beta1) tools
# at Mon Jan  8 12:44:19 2024 by `软智科技有限责任公司'
# running "D:/Shaun-projects/newstar/devsrc/rel_1_0/source/build/ilu/bin/python-stubber.EXE" of Tue Nov 21 17:45:01 2023
# on "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test2.isl" of Thu Dec 28 15:50:30 2023,
# and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/Test1.isl" of Thu Dec 28 15:50:30 2023,
# and "D:/Shaun-projects/newstar/Ilusrc/examples/test1/ilu.isl" of Mon Jan  8 12:28:51 2024#
# KIS-CORBA is Copyright 2006-2056 Chengdu Kestrel AI Institute Ltd., All Rights Reserved.
# KIS-CORBA information:  http://www.kestrelsystems.ca .

import sys;
_imported_modules = {};
import iluRt ; _imported_modules['iluRt'] = iluRt; _imported_modules['ilu'] = iluRt;
iluRt.CheckStubConsistency('2.0beta1', 'v2 (post-2.0alpha12)');
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

