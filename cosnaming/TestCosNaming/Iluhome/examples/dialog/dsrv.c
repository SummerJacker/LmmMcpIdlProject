/* $Id: dsrv.c,v 1.4 2025/08/01 04:58:01 cvswxc Exp $ */

#include <stdio.h>
#include <string.h>

#include "Dialog.h"

Dialog_String
server_Dialog_T_M(Dialog_T t, Dialog_String s1, ILU_C_ENVIRONMENT * Env)
{
  char            buf[1000], *ans;
  ilu_cardinal    len;
  printf("Caller sez: '%s'\n", s1);
  printf("Reply: ");
  ans = fgets(buf, 1000, stdin);
  if (ans != buf) {
    fprintf(stderr, "Error reading reply!\n");
    exit(1);
  }
  len = strlen(buf);
  ans = (char *) ilu_malloc(len);
  if (ans == NULL) {
    fprintf(stderr, "Unable to malloc reply!\n");
    exit(1);
  }
  strcpy(ans, buf);
  return ans;
}

int
main(int argc, char **argv)
{
  char           *pinfo = NULL;
  ilu_string      tinfo_space[10] = {"sunrpcrm", "tcp_0_0", ILU_NIL};
  ilu_string     *tinfo = NULL;
  ILU_C_Server    s;
  Dialog_T        t;
  ilu_string      sbh, mstid;
  int             i = 1;
  ILU_C_ENVIRONMENT env;
  Dialog__InitializeServer();
  s = ILU_C_InitializeServer("DialogTest-Server", NULL, NULL, NULL,
			     NULL, ilu_FALSE);
  if (s == NULL) {
    fprintf(stderr, "Unable to create ILU server!\n");
    exit(1);
  }
  while (i < argc) {
    if (strcmp(argv[i], "-pt") == 0) {
      char           *pinfo = NULL;
      ilu_string      tinfo_space[10] = {ILU_NIL};
      ilu_string     *tinfo = tinfo_space;
      int             j = 0;
      if (i++ + 2 >= argc)
	goto usage;
      pinfo = argv[i++];
      while ((i < argc) && (j < 9) && (argv[i][0] != '-'))
	tinfo[j++] = argv[i++];
      if (!ILU_C_AddPort(s, pinfo, tinfo, ILU_NIL, ilu_FALSE, &env)) {
	fprintf(stderr, "Unable to create port (%s, %s...): %s\n",
		pinfo, tinfo[0], ILU_C_EXCEPTION_ID(&env));
	return 3;
      }
    } else if (strcmp(argv[i], "-p") == 0) {
      if (i++ < argc)
	pinfo = argv[i++];
      else
	goto usage;
    } else if (strcmp(argv[i], "-t") == 0) {
      int             j = 0;
      tinfo = tinfo_space;
      ++i;
      while ((i < argc) && (j < 9) && (argv[i][0] != '-'))
	tinfo[j++] = argv[i++];
    } else
      goto usage;
  }
  if (!ILU_C_AddPort(s, pinfo, tinfo, ILU_NIL, ilu_FALSE, &env)) {
    fprintf(stderr, "Unable to create port (%s, %s...): %s\n",
	    pinfo, tinfo[0], ILU_C_EXCEPTION_ID(&env));
    return 3;
  }
  t = Dialog_T__CreateTrue("it", s, NULL);
  if (t == NULL) {
    fprintf(stderr, "Unable to create ILU object!\n");
    exit(1);
  }
  sbh = ILU_C_SBHOfObject(t);
  printf("SBH = '%s'\n", sbh);
  ILU_C_Run();
usage:
  fprintf(stderr, "Usage: %s [-t tinfo [tinfo...]] [-p pinfo]\n",
	  argv[0]);
  return 2;
}
