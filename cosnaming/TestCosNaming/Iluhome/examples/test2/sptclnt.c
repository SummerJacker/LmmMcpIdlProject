/* $Id: sptclnt.c,v 1.4 2025/08/01 09:14:26 cvswxc Exp $ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>	/* for exit() */

#include "SerialTest.h"

#define ilu_Alarm ilu_refany

static ILU_C_Serializer si = NULL;
static ILU_C_Pipeline pl;
static SerialTest_T t = NULL;
static int      verbose = 0;
static unsigned nsers, ndone = 0;

typedef struct {
  unsigned        i, n;
}               Inst;

static void DoCall(void *rock)
{
  Inst           *inst = (Inst *) rock;
  ilu_boolean     synch = !!(inst->i % 2);
  ilu_FineTime    now;
  ILU_C_ENVIRONMENT env;
  now = ilu_FineTime_Now();
  printf("Calling       %c(%u, %u) at %lu:%06lu\n", 'M' + synch,
	 inst->i, inst->n, now.ft_s, now.ft_t);
  fflush(stdout);
  _ilu_Assert(ILU_C_SetSerializationContext(si), "set si");
  _ilu_Assert(ILU_C_SetPipelineContext(pl), "set pl");
  (synch ? SerialTest_T_N : SerialTest_T_M) (t, inst->i, inst->n, &env);
  now = ilu_FineTime_Now();
  if (!ILU_C_SUCCESSFUL(&env)) {
    fprintf(stderr, "%c(%u, %u) => @ %lu:%06lu %s\n", 'M' + synch,
	    inst->i, inst->n,
	    now.ft_s, now.ft_t,
	    ILU_C_EXCEPTION_ID(&env));
  } else {
    printf("Returned from %c(%u, %u) at %lu:%06lu\n", 'M' + synch,
	   inst->i, inst->n,
	   now.ft_s, now.ft_t);
    inst->n--;
  }
  fflush(stdout);
  ILU_C_SetSerializationContext(NULL);
  ndone += 1;
  if (ndone == nsers) {
    if (!ILU_C_ReleaseSerializer(si, &env)) {
      fprintf(stderr, "ILU_C_ReleaseSerializer() => %s\n",
	      ILU_C_EXCEPTION_ID(&env));
      exit(1);
    }
    ILU_C_SetPipelineContext(NULL);
    if (!ILU_C_ReleasePipeline(pl, &env)) {
      fprintf(stderr, "ILU_C_ReleasePipeline() => %s\n",
	      ILU_C_EXCEPTION_ID(&env));
      exit(1);
    }
    exit(0);
  }
}

int
main(int argc, char *argv[])
{
#ifdef ILU_OS_THREADED
  unsigned        i, nper = 1;
  ILU_C_ENVIRONMENT env;
  if (argc < 2)
    goto usage;
  if (sscanf(argv[1], "%u", &nsers) != 1)
    goto usage;
  for (i = 2; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0)
      verbose = 1;
    else
      goto usage;
  }
  ILU_C_USE_OS_THREADS;
  SerialTest__Initialize();
  t = ILU_C_LookupObject("SerialTest-Server", "it", SerialTest_T__MSType);
  if (t == NULL) {
    fprintf(stderr, "Unable to import server!\n");
    exit(1);
  }
  SerialTest_T_Prep(t, nsers, nper, &env);
  if (!ILU_C_SUCCESSFUL(&env)) {
    fprintf(stderr, "SerialTest_T_Prep(%u, %u) => %s\n",
	    nsers, nper, ILU_C_EXCEPTION_ID(&env));
    exit(1);
  }
  si = ILU_C_CreateSerializationContext(t->server, &env);
  if (!ILU_C_SUCCESSFUL(&env)) {
    fprintf(stderr, "ILU_C_CreateSerializationContext() => %s\n",
	    ILU_C_EXCEPTION_ID(&env));
    exit(1);
  }
  pl = ILU_C_CreatePipeline(&env);
  if (!ILU_C_SUCCESSFUL(&env)) {
    fprintf(stderr, "ILU_C_CreatePipeline() => %s\n",
	    ILU_C_EXCEPTION_ID(&env));
    exit(1);
  }
  for (i = 0; i < nsers; i++) {
    Inst           *inst = (Inst *) ilu_must_malloc(sizeof(*inst));
    ilu_FineTime    now;
    ILU_ERRS((no_memory, no_resources, internal)) kerr;
    inst->i = i;
    inst->n = 1001;
    now = ilu_FineTime_Now();
    if (!ilu_Fork(DoCall, inst, &kerr)) {
      fprintf(stderr, "Fork(%d) => %s", i, ILU_ERR_NAME(kerr));
      exit(1);
    }
  }
  ILU_C_Run();
  return 0;
usage:
  fprintf(stderr,
	  "Usage: %s n-threads [-v]\n",
	  argv[0]);
  return (1);
#else
  fprintf(stderr, "Multi-threading not configured into ILU!\n");
  return (1);
#endif
}
