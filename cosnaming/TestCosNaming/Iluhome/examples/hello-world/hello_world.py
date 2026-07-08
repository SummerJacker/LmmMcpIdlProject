# Stubs for "hello-world"
#
# This file was automatically generated with KISORB (version 2.0beta1) tools
# at Fri Aug 22 17:23:51 2025 by `沈阳市软件定义智能协同重点实验室'
# running "D:/Shaun-projects/newstar/Iluhome/bin/python-stubber.exe" of Mon Aug 18 11:47:25 2025
# on "D:/Shaun-projects/newstar/Iluhome/examples/hello-world/hello-world.isl" of Wed Jul 30 16:24:59 2025,
# and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025#
# KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
# KISORB information: Dr. Wang xcwang89@aliyun.com .

_imported_modules = {};
import iluRt ; _imported_modules['iluRt'] = iluRt; _imported_modules['ilu'] = iluRt;
iluRt.CheckStubConsistency('2.0beta1', 'v2 (2.0beta1)');
_imported_modules['ilu__skel'] = iluRt
del iluRt
__types__={}

import iluRt

class service(iluRt.IluObjSurr):
    _IluClass = iluRt.FormClassRecord(
        'hello_world.service',
        '',
        'ilut:lIV5QXo6KXw4vrj0tHlcPTOi1oY',
        None,
        iluRt.FALSE,
        iluRt.FALSE,
        None,
        (
            ('hello-world', 1, iluRt.FALSE, iluRt.FALSE, "ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv", (('inarg', 0, 0, 'ilut:naKu7NwC1iaZkRZFKFBdxeuTiXv'),), ()),
        ),
        ()
    )

    def hello_world(_self, inarg):
        _result = None
        _call = iluRt.BeginCall(_self, service._IluClass, 1)
        try:
            while 1:
                iluRt.BeginRequest(_call,
                    iluRt.SizeOfObjectID(_call, _self, iluRt.TRUE, service)
                    + iluRt.SizeOfString(_call, inarg, 0))
                iluRt.OutputObjectID(_call, _self, iluRt.TRUE, service)
                iluRt.OutputString(_call, inarg, 0)
                iluRt.FinishRequest(_call)
                _ecode = iluRt.GetReply(_call)
                if _ecode != iluRt.RetryCall:
                    break
            try:
                if _ecode != 0:
                    _CatchException(_call, service._IluClass, _ecode)
                _result = iluRt.InputString(_call, 0)
            finally:
                iluRt.ReplyRead(_call)
        finally:
            iluRt.FinishCall(_call)
        return _result

__types__['service'] = iluRt.RegisterObjectType(service, ('hello-world','service',), None, None)


def _CatchException(_call, _IluClass, _ecode):
    _value = None
    _name = iluRt.ExceptionName(_call, _IluClass, _ecode)
    raise _name
