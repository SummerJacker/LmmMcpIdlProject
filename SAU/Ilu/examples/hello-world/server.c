/** $Id: server.c,v 1.4 2025/06/22 07:51:53 cvswxc Exp $
    $Log: server.c,v $
    Revision 1.4  2025/06/22 07:51:53  cvswxc
    #681 remove old infor
    Committed on the Free edition of March Hare Software CVSNT Server.
    Upgrade to CVS Suite for more features and support:
    http://march-hare.com/cvsnt/
 
*/
/* Last edited by Mike Spreitzer October 8, 1998 11:01 pm PDT */

#include <stdio.h>
#include <unistd.h>	/* for gethostname */

#include "hello_world.h"

ilu_CString
  server_hello_world_service_hello_world (hello_world_service self,
					  ILU_C_ENVIRONMENT *status)
{
  return (ILU_C_Strdup("\"Hello, World!\" from ANSI C"));
}

int main (int ac, char **av)
{
  static ILU_C_Server theServer;
  hello_world_service theObject;

  hello_world__InitializeServer();

  theServer = ILU_C_InitializeServer (NULL, NULL, NULL, NULL, NULL, ilu_TRUE);
  if (theServer != NULL) {
    theObject = hello_world_service__CreateTrue (NULL, theServer, NULL);
    if (theObject != NULL) {
      printf ("hello world server is %s\n", ILU_C_SBHOfObject(theObject));
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

