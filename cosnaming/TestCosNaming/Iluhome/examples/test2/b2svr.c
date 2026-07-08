/* $Id: b2svr.c,v 1.4 2025/08/01 09:11:44 cvswxc Exp $ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>	/* for exit() */

#ifndef WIN32
#include <unistd.h>
#endif

#include "Batcher2.h"

static int verbose = 0;
static unsigned int tosleep = 0;

void
server_Batcher2_Server_Request(Batcher2_Server self,
			       Batcher2_Time r,
			       ilu_cardinal x,
			       Batcher2_Bytes * phil,
			       Batcher2_CallBack replyTo,
			       ILU_C_ENVIRONMENT * Env)
{
  ilu_FineTime    now = ilu_FineTime_Now();
  Batcher2_Time   s;
  if (verbose)
    printf("Request(%lu:%lu -> %lu:%lu)\n",
	   (unsigned long) ILU_LONGCARD_HIGH_WORD(&r),
	   (unsigned long) ILU_LONGCARD_LOW_WORD(&r),
	   (unsigned long) x,
	   (unsigned long) now.ft_s, (unsigned long) now.ft_t);
  ILU_LONGCARD_HIGH_WORD(&s) = now.ft_s;
  ILU_LONGCARD_LOW_WORD(&s) = now.ft_t;
  Batcher2_CallBack_Reply(replyTo, r, x, s, Env);
  return;
}

void 
server_Batcher2_CallBack_Reply(Batcher2_CallBack self,
			       Batcher2_Time r,
			       ilu_cardinal x,
			       Batcher2_Time s,
			       ILU_C_ENVIRONMENT * Env)
{
  return;
}

int
main(int argc, char **argv)
{
  ILU_C_Server    s;
  Batcher2_Server svr;
  int             i;
  ilu_string      progname, sbh, pinfo = NULL;
  ilu_string      tinfo[10] = {"sunrpcrm", "tcp_0_0", NULL};

  Batcher2__InitializeServer();
  Batcher2__Initialize();
  progname = argv[0];
  argv++;
  argc--;
  for (i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-p") == 0 && ((i + 1) < argc))
      pinfo = argv[++i];
    else if (strcmp(argv[i], "-s") == 0 && ((i + 1) < argc))
      tosleep = atoi(argv[++i]);
    else if (strcmp(argv[i], "-t") == 0 && ((i + 1) < argc)) {
      int             j = 0;
      ++i;
      while ((i < argc) && (argv[i][0] != '-'))
	tinfo[j++] = argv[i++];
      tinfo[j] = NULL;
    } else if (strcmp(argv[i], "-v") == 0)
      verbose = 1;
    else
      goto usage;
  }
  s = ILU_C_InitializeServer("Batcher2-Server", NULL, pinfo, tinfo,
			     ILU_NIL, ilu_TRUE);
  if (s == NULL) {
    fprintf(stderr, "Unable to create ILU server!\n");
    exit(1);
  }
  svr = Batcher2_Server__CreateTrue("it", s, NULL);
  if (svr == NULL) {
    fprintf(stderr, "Unable to create ILU object!\n");
    exit(1);
  }
  if (ILU_C_PublishObject(svr) == NULL) {
    fprintf(stderr, "Can't publish object!\n");
    exit(1);
  }
  sbh = ILU_C_SBHOfObject(svr);
  printf("tosleep = %u\n", tosleep);
  printf("SBH = '%s'\n", sbh);
  ILU_C_Run();
usage:
  fprintf(stderr,
    "Usage: %s [-v] [-s sleep] [-p pinfo] [-t tinfo [tinfo...]]\n",
	  progname);
  return 1;
}
