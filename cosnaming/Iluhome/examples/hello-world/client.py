# $Id: client.py,v 1.5 2025/07/28 09:09:22 cvswxc Exp $ # 

import sys, ilu, hello_world

def main(sbh):

	try:
		theService = ilu.ObjectOfSBH (hello_world.service, sbh)
	except:
		print "Can't create object from SBH <" + sbh + ">; error is", sys.exc_type, sys.exc_value
		sys.exit(1)

	if not theService:
		print "Can't create object from SBH <" + sbh + ">"
		sys.exit(1)
	try:
		response = theService.hello_world()
		print response
	except:
		print 'hello_world_service_hello_world (theService) fails with exception <' + str(sys.exc_type) + '> ' + str(sys.exc_value)
		sys.exit(1)

if __name__ == '__main__':
	if len(sys.argv) < 2:
		print "Usage:  %s SBH-OF-SERVER" % sys.argv[0]
		sys.exit(1)
	else:
		main (sys.argv[1])

