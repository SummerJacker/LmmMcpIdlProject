/** $Id: client.c,v 1.4 2025/06/22 05:51:08 cvswxc Exp $
 ** $Log: client.c,v $
 ** Revision 1.4  2025/06/22 05:51:08  cvswxc
 ** test the new cvs server/client works or not
 ** Committed on the Free edition of March Hare Software CVSNT Server.
 ** Upgrade to CVS Suite for more features and support:
 ** http://march-hare.com/cvsnt/
 **  
*/
/* Last edited by Mike Spreitzer October 8, 1998 10:58 pm PDT */

#include <string.h>
#include <stdio.h>

#include "hello_world.h"

int main (int ac, char **av)
{
  hello_world_service theService;
  CORBA_Environment env;
  char *response;

  if (ac < 2)
    {
      fprintf (stderr, "Usage:  client SBH-OF-SERVER\n");
      return 1;
    }

  hello_world__Initialize();

  theService = (hello_world_service) ILU_C_SBHToObject(av[1],
						       hello_world_service__MSType,
						       &env);
  if (!ILU_C_SUCCESSFUL(&env)) {
    fprintf (stderr, "Can't create object from SBH <%s>; error is <%s>\n",
	     av[1], CORBA_exception_id(&env));
    CORBA_exception_free(&env);
    return 1;
  };

  response = hello_world_service_hello_world (theService, &env);
  if (!ILU_C_SUCCESSFUL(&env)) {
    fprintf (stderr, "hello_world_service_hello_world (theService) fails with exception <%s>\n",
	     CORBA_exception_id(&env));
    CORBA_exception_free(&env);
    return 1;
  } else {
    printf ("%s\n", response);
    return 0;
  }
}

