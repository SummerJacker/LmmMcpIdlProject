# $Id: webServer.py,v 1.4 2025/08/01 00:22:51 cvswxc Exp $


import Bank, ilu, Bank__skel, http, http__skel, rand

mainloopvar = ilu.CreateLoopHandle()

class realAccount (Bank__skel.Account):

	def __init__(self, manager, name, balance):
		self.manager = manager
		self.IluServer = manager.IluServer
		self.IluInstHandle = manager.IluInstHandle + ' - ' + name
		self.name = name
		self.bank_balance = balance

	def balance (self):
		return self.bank_balance

class realAccountManager (Bank__skel.AccountManager):

	def __init__(self, name, srvr=None):
		self.IluInstHandle = name
		self.IluServer = srvr
		self.accounts = {}

	def open (self, name):
		if not self.accounts.has_key(name):
			initial_balance = rand.rand() / 32.768
			account = realAccount (self, name, initial_balance)
			self.accounts[name] = account
		else:
			account = self.accounts[name]
		return account

class bankDoc (http__skel.Resource):

	prefix = '<h1>Client Applet</h1><hr><center><applet code=BankAppletVisi.class width=200 height=80><h2>This would be the VisiBroker for Java Bank Applet, but you are not running a Java enabled browser...</h2><PARAM NAME=IOR VALUE="'
	suffix = '"></applet></center><hr>'

	def __init__(self, name, srvr, ior):
		self.IluInstHandle = name
		self.IluServer = srvr
		self.IOR = ior

	def GET(self, request):
		text = self.prefix + self.IOR + self.suffix
		return http.Response(http.StatusCode.OK,
				     [http.Header('Content-Type', 'text/html'),],
				     text);

	def HEAD(self, request):
		return http.Response(http.StatusCode.OK, [], None)

	def POST(self, request):
		return http.Response(http.StatusCode.OK, [], None)

def main():

  instHandle = "Post-Modern Bank"
  serverID = "bankserver.somedept.somecompany.com"
  webServerID = "bankAppletServer"

  s = ilu.CreateServer(serverID, ("tcp_0_0",), "iiop_1_0_1");
  uc = realAccountManager(instHandle, s)

  wsrvr = ilu.CreateServer(webServerID, ("tcp_0_8777",), "http_1_0p");
  wobj = bankDoc("/bankApplet", wsrvr, ilu.IOROfObject(uc));
  print wobj.IluSBH()

  ilu.RunMainLoop(mainloopvar)

if __name__ == '__main__':
	main()
