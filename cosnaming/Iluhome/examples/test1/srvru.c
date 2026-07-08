/* $Id: srvru.c,v 1.4 2025/08/02 10:01:23 cvswxc Exp $ */

#include "srvr.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

int main (int ac, char **av)
{
  char           *pinfo = NULL;
  ilu_string      tinfo_space[10] = {ILU_NIL};
  ilu_string     *tinfo = NULL, *newti = NULL;
  ilu_boolean     sec = ilu_FALSE, cred = ilu_FALSE, mt = ilu_FALSE, ssl = ilu_FALSE;
  int             i = 1;

#if INCLUDE_SSL_SECMECH
  ssl = ilu_TRUE;
#endif

  while (i < ac) {
    if (strcmp(av[i], "-p") == 0) {
      if (i++ < ac)
	pinfo = av[i++];
      else
	goto usage;
    } else if (strcmp(av[i], "-t") == 0) {
      int             j = 0;
      tinfo = tinfo_space;
      ++i;
      while ((i < ac) && (av[i][0] != '-'))
	tinfo[j++] = av[i++];
      tinfo[j] = ILU_NIL;
    } else if (strcmp(av[i], "-st") == 0) {
      mt = 0; i++;
    } else if (strcmp(av[i], "-nossl") == 0) {
      ssl = ilu_FALSE; i++;
    } else if (strcmp(av[i], "-mt") == 0) {
      mt = 1; i++;
    } else if (strcmp(av[i], "-cred") == 0) {
      cred = 1; i++;
    } else if (strcmp(av[i], "-nosec") == 0) {
      cred = 0; i++;
      tinfo = DefaultTInfo(0, ssl);
    } else if (strcmp(av[i], "-errexit") == 0) {
      ilu_SetAssertionFailureAction(1);
      ilu_SetCheckFailureAction(1);
      i++;
    } else if (strcmp(av[i], "-sec") == 0) {
      cred = 1; i++;
      newti = DefaultTInfo(1, ssl);
      if (newti == NULL) {
	fprintf(stderr, "Security support not configured into ILU!\n");
	return -1;
      } else
	tinfo = newti;
    } else
      goto usage;
  }
  return doit(pinfo, tinfo, mt, cred, ssl);
usage:
  fprintf(stderr,
	  "Usage: %s [-t tinfo [tinfo...] [-cred] | -sec | -nosec ]"
	  " [-p pinfo] [-st | -mt]\n",
	  av[0]);
  return 2;
}
