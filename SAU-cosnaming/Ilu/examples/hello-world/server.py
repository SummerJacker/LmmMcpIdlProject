# $Id: server.py,v 1.4 2025/06/22 07:54:25 cvswxc Exp $
# $Log: server.py,v $
# Revision 1.4  2025/06/22 07:54:25  cvswxc
# #681 remove old infor
# Committed on the Free edition of March Hare Software CVSNT Server.
# Upgrade to CVS Suite for more features and support:
# http://march-hare.com/cvsnt/
#

import ilu, hello_world__skel

class realService (hello_world__skel.service):
	def __init__(self, server=None, ih=None):
		self.IluServer = server
		self.IluInstHandle = ih

	def hello_world (self):
		return '"Hello, World!" from Python'

loopvar = ilu.CreateLoopHandle();

theServer = None

def main():
  global theServer

  theServer = ilu.CreateServer()
  theObject = realService (theServer)

  print "hello world server is", theObject.IluSBH()

  ilu.RunMainLoop(loopvar)

if __name__ == "__main__":
	main()
