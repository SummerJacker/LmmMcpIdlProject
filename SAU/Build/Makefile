CFG = Debug
MAKE = make -w
CD = cd
SUB_DIR = ../ROSRobot/Build

all: subdir

subdir:
	@$(CD) $(SUB_DIR);\
	$(MAKE) -f Makefile CFG=$(CFG) LANG=$(LANG)

clean:
	@$(CD) $(SUB_DIR);\
	$(MAKE) -f Makefile CFG=$(CFG) LANG=$(LANG) clean

install:
	@$(CD) $(SUB_DIR);\
	$(MAKE) -f Makefile CFG=$(CFG) install

uninstall:
	@$(CD) $(SUB_DIR);\
	$(MAKE) -f Makefile CFG=$(CFG) uninstall

#$Log: Makefile,v $
#Revision 1.4  2025/06/23 05:23:00  cvswxc
##668 make a jlu module and set SRIO Project be solid
#Committed on the Free edition of March Hare Software CVSNT Server.
#Upgrade to CVS Suite for more features and support:
#http://march-hare.com/cvsnt/
#
#
