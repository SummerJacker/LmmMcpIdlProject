# $Id: pyServer.py,v 1.4 2025/08/01 05:59:40 cvswxc Exp $

import sys, ilu
if ilu.CORBAMapping:
	import Test2__POA
	trueModule = Test2__POA
else:
	import Test2__skel
	trueModule = Test2__skel

class O1(trueModule.O1):
  def __init__(self, ih, srvr):
    self.IluInstHandle = ih
    self.IluServer = srvr

  def bounce (self, v):
	  return v;

loopvar = ilu.CreateLoopHandle();

def main():
  instHandle = "pickleObj"
  serverId = "pickleServer"

  s = ilu.CreateServer(serverId, ('tcp_0_0',), 'iiop_1_0_1')
  uc = O1(instHandle, s)

  uc.IluPublish()

  print "exported", uc.IluSBH()

  ilu.RunMainLoop(loopvar)

main()
