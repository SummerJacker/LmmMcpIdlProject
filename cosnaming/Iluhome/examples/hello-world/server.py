# $Id: server.py,v 1.5 2025/07/28 09:09:22 cvswxc Exp $ #

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
