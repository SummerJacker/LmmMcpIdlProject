# $Id: strlen.py,v 1.4 2025/08/07 07:27:08 cvswxc Exp $¡¡
import ilu, sys
import strlenGlue, test

theStrlen = ilu.ObjectOfSBH(test.Strlen, strlenGlue.strlen_sbh)

def strlen(s):
	return theStrlen.len(s)
