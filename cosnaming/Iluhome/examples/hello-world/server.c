/* $Id: server.c,v 1.6 2025/07/30 08:24:59 cvswxc Exp $ */

#include <stdio.h>
#if defined(WIN32)
#include <winsock2.h>
#else
#include <unistd.h>	/* for gethostname */
#endif 
#include "hello_world.h"

ilu_CString
  server_hello_world_service_hello_world (hello_world_service self,  char *message,
					  ILU_C_ENVIRONMENT *status)
{
 char  temp[300];
 sprintf(temp, "%s %s", "Hello!", message); 
 return (ILU_C_Strdup(temp));
}

int main (int ac, char **av)
{
  static ILU_C_Server theServer;
  hello_world_service theObject;
  FILE *file;
  file = fopen("SBHtempfile.tex", "w");

  hello_world__InitializeServer();

  theServer = ILU_C_InitializeServer (NULL, NULL, NULL, NULL, NULL, ilu_TRUE);
  if (theServer != NULL) {
    theObject = hello_world_service__CreateTrue (NULL, theServer, NULL);
    if (theObject != NULL) {
      printf ("hello world server is %s\n", ILU_C_SBHOfObject(theObject));
      fputs(ILU_C_SBHOfObject(theObject), file);
      fputs("\n", file);
      fclose(file); 
      ILU_C_Run( );
      return 0;
    } else {
      printf ("couldn't hello world object -- exiting\n");
      return 1;
    }
  } else {
    printf ("couldn't hello world server -- exiting\n");
    return 1;
  }
}

