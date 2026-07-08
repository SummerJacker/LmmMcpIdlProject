/* $Id: server-cpp.cpp,v 1.4 2025/08/01 00:29:27 cvswxc Exp $ */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>	/* for exit() */
#include <string.h>

#include "Test2-cpp.hpp"

void Usage (char *pname)
{
  fprintf (stderr, "Usage:  %s [-p PINFO] [-t TINFO]\n", pname);
  exit(1);
}

class Test2_O1_impl : public virtual Test2(O1) {

public:

  Test2_O1_impl(char* pc_instance_handle,
		iluServer& r_an_ilu_server= iluServer::iluGetDefaultServer(),
		CORBA(Boolean) b_within_object_table = ILUCPP_FALSE) : 
	iluObject(iluGetILUClassRecord(), pc_instance_handle, r_an_ilu_server, b_within_object_table) {}
	  
  virtual ~Test2_O1_impl() {
    iluDeactivate();
  }

  CORBA(Any)* bounce (const CORBA(Any)&);
};

CORBA(Any)*
Test2_O1_impl::bounce (const CORBA(Any)& v)
{
  CORBA(Any) *p = new CORBA(Any)(v);
  return p;
}

int main (int ac, char **av)
{
  Test2_O1_impl	*uc;
  char *	tinfo[10] = { 0 };
  char *	pinfo = ILU_NIL;
  iluServer	*s;
  int i, j;
  ilu_boolean	threaded = ilu_FALSE;

  i = 1;
  while (i < ac) {
    if (strcmp(av[i], "-p") == 0) {
      if (i++ < ac)
	pinfo = av[i++];
      else
	Usage(av[0]);
    } else if (strcmp(av[i], "-t") == 0) {
      int j = 0;
      ++i;
      while ((i < ac) && (av[i][0] != '-'))
	tinfo[j++] = av[i++];
      tinfo[j] = ILU_NIL;
    } else if (strcmp(av[i], "-mt") == 0) {
      threaded = ilu_TRUE;
      ++i;
    } else
      Usage(av[0]);
  }

  iluCppRuntime::iluInitialize(threaded);

  s = new iluServer ("pickleServer",
		     ILU_NIL, /* obj table */
		     pinfo,
		     (tinfo[0] == 0) ? ILU_NIL : tinfo);

  if (s == NULL) {
    printf("Error.  Couldn't create server.\n");
    exit(1);
  }
  uc = new Test2_O1_impl ("pickleObj", *s);
  if (uc == NULL) {
    printf("Error.  Couldn't create object.\n");
    exit(1);
  };
  if (!uc->iluPublish()) {
    fprintf(stderr, "Error.  Couldn't publish Test1-Server object.\n");
    exit(1);
  };
  printf("exported %s\n", uc->iluObjectToString());
  s->iluRun();
  return 0;
}
