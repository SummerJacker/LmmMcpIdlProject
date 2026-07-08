# $Id: bankClient.py,v 1.4 2025/08/01 00:22:51 cvswxc Exp $

import Bank, CORBA, sys

def do_test (orb, manager_IOR, account_name):
	manager = orb.string_to_object(manager_IOR)
	account = manager.open (account_name)
	balance = account.balance()
	print "The balance for %s is $%.2f.\n" % (account, balance)

def main (argv):
	if not (len(argv) == 3):
		print 'Usage:  %s ACCOUNT-MANAGER-SBH ACCOUNT-NAME'
		sys.exit(1)
	orb = CORBA.ORB_init(argv, '')
	do_test(orb, argv[1], argv[2])

if __name__ == '__main__':
	main(sys.argv)
		
