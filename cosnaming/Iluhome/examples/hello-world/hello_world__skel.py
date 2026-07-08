# Skeletons for "hello-world"
#
# This file was automatically generated with KISORB (version 2.0beta1) tools
# at Fri Aug 22 17:23:51 2025 by `沈阳市软件定义智能协同重点实验室'
# running "D:/Shaun-projects/newstar/Iluhome/bin/python-stubber.exe" of Mon Aug 18 11:47:25 2025
# on "D:/Shaun-projects/newstar/Iluhome/examples/hello-world/hello-world.isl" of Wed Jul 30 16:24:59 2025,
# and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025#
# KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
# KISORB information: Dr. Wang xcwang89@aliyun.com .

import sys;
_imported_modules = {};
import iluRt ; _imported_modules['iluRt'] = iluRt; _imported_modules['ilu'] = iluRt;
iluRt.CheckStubConsistency('2.0beta1', 'v2 (2.0beta1)');
_imported_modules['ilu__skel'] = iluRt
del iluRt
import hello_world; _imported_modules['hello_world'] = hello_world; del hello_world;
import iluRt

def _service__hello_world(_call):
    _self = iluRt.InputObjectID(_call, iluRt.TRUE, _imported_modules['hello_world'].service)
    inarg = iluRt.InputString(_call, 0)
    iluRt.RequestRead(_call)
    try:
        _result = _self.hello_world(inarg)
    except:
        iluRt.CaughtUnexpectedException(_call)
    iluRt.BeginReply(_call, iluRt.FALSE, iluRt.BeginSizingReply(_call, iluRt.FALSE) + iluRt.SizeOfString(_call, _result, 0))
    iluRt.OutputString(_call, _result, 0)
    iluRt.FinishReply(_call)


iluRt.RegisterSkeletons(_imported_modules['hello_world'].service._IluClass, (
    _service__hello_world,))


class service(iluRt.IluObjTrue):
    _IluClass = _imported_modules['hello_world'].service._IluClass

    def hello_world(_self, inarg):
        raise Exception(iluRt.IluUnimplementedMethodError, 'hello-world')

