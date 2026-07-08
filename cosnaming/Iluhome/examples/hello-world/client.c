/* $Id: client.c,v 1.7 2025/07/31 03:25:41 cvswxc Exp $ */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "hello_world.h"

#define MAX_INPUT_LEN 256

int main (int ac, char **av)
{
  hello_world_service theService;
  CORBA_Environment env;
  char input[MAX_INPUT_LEN];
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

  //we need send message to server, and then server package this message back.
  //TODO:　you need to do this
  printf("=== 循环字符串输入并发送给服务端 ===\n");
  printf("输入字符串  exit 退出\n");
  while (1) { 
	printf(">");
	fgets(input,MAX_INPUT_LEN, stdin); 
	//remove the line change char
	input[strcspn(input,"\n")]='\0';
	//check if exist 
	if (strcmp(input, "exit")==0) {
		printf("程序结束.\n");
		break;
	}

	response = hello_world_service_hello_world (theService, input, &env);
	if (!ILU_C_SUCCESSFUL(&env)) {
		fprintf (stderr, "hello_world_service_hello_world (theService) fails with exception <%s>\n",
					CORBA_exception_id(&env));
		CORBA_exception_free(&env);
		return 1; 
	}
	printf ("%s\n", response);
  }
 return 0; 
 }	


