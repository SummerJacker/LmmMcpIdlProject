/* $Id: server.c,v 1.4 2025/08/01 05:59:49 cvswxc Exp $ */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>	/* for exit() */
#include <string.h>

#include "Test2.h"

void Usage (char *pname)
{
  fprintf (stderr, "Usage:  %s [-p PINFO] [-t TINFO]\n", pname);
  exit(1);
}

int main (int ac, char **av)
{
  Test2_O1	uc;
  char *	tinfo[10] = { 0 };
  char *	pinfo = ILU_NIL;
  ILU_C_Server	s;
  char *	proof;
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

  if (threaded) {
#if (defined(ILU_OS_THREADED))
    ILU_C_USE_OS_THREADS;
#else
    OUTPUT("OS-supplied thread support not configured into ILU!\n");
    exit(-1);
#endif				/* (defined(ILU_OS_THREADED)) */
  }

  Test2__InitializeServer();

  s = ILU_C_InitializeServer("pickleServer", NULL, pinfo , (tinfo[0] == 0) ? ILU_NIL : tinfo,
			     NULL, ilu_TRUE);

  if (s == NULL) {
    printf("Error.  Couldn't create server.\n");
    exit(1);
  }
  uc = Test2_O1__CreateTrue("pickleObj", s, NULL);
  if (uc == NULL) {
    printf("Error.  Couldn't create object.\n");
    exit(1);
  }
  if ((proof = ILU_C_PublishObject(uc)) == NULL) {
    fprintf(stderr, "Error.  Couldn't publish Test1-Server object.\n");
    exit(1);
  }
  printf("exported %s\n", ILU_C_SBHOfObject(uc));
  ILU_C_Run();
  return 0;
}

CORBA_any *
  server_Test2_O1_bounce (Test2_O1 handle, CORBA_any *v, CORBA_Environment *env)
{
  CORBA_any *pickle;

  pickle = ILU_C_Any_Duplicate (v, env);
  return pickle;
}
