/* $Id: stclnt.c,v 1.4 2025/08/01 09:14:34 cvswxc Exp $ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>	/* for exit() */

#ifndef WIN32
#include <unistd.h>	/* for sleep() */
#endif

#include "SerialTest.h"

#define ilu_Alarm ilu_refany

static ILU_C_Serializer *si = NULL;
static SerialTest_T t = NULL;
static int      verbose = 0;
static unsigned nsers, ndone = 0;

typedef struct {
  unsigned        i, n, seed;
  ilu_Alarm       a;
  ILU_C_Serializer si;
}               Inst;

static void Sched(Inst *inst);

static void DoCall(void *rock)
{
  Inst           *inst = (Inst *) rock;
  ilu_FineTime    now;
  ILU_C_ENVIRONMENT env;
  now = ilu_FineTime_Now();
  printf("Calling M(%u, %u) at %lu:%lu\n", inst->i, inst->n,
	 now.ft_s, now.ft_t);
  ILU_C_SetSerializationContext(inst->si);
  SerialTest_T_M(t, inst->i, inst->n, &env);
  if (!ILU_C_SUCCESSFUL(&env)) {
    fprintf(stderr, "M(%u, %u) => %s\n", inst->i, inst->n,
	    ILU_C_EXCEPTION_ID(&env));
  } else
    inst->n--;
  if (inst->n > 0)
    Sched(inst);
  else {
    ILU_C_SetSerializationContext(NULL);
    if (!ILU_C_ReleaseSerializer(inst->si, &env)) {
      fprintf(stderr, "ILU_C_ReleaseSerializer() => %s\n",
	      ILU_C_EXCEPTION_ID(&env));
      exit(1);
    }
    ndone += 1;
    if (ndone == nsers) {
      exit(0);
    }
  }
}

static void Sched(Inst *inst)
{
  ilu_FineTime    now = ilu_FineTime_Now();
  ilu_FineTime    dt = ilu_FineTime_FromDouble(inst->seed / 50.0);
  ilu_FineTime    todo = ilu_FineTime_Add(now, dt);
  inst->seed = (inst->seed * 101) % 1013;
  ilu_SetAlarm(inst->a, todo, DoCall, inst);
}

int
main(int argc, char *argv[])
{
  unsigned        i, nper, mt = 0;
  int             pipeit = 1;
  ILU_C_ENVIRONMENT env;
  if (argc < 3)
    goto usage;
  if (sscanf(argv[1], "%u", &nsers) != 1)
    goto usage;
  if (sscanf(argv[2], "%u", &nper) != 1)
    goto usage;
  for (i = 3; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0)
      verbose = 1;
    else if (strcmp(argv[i], "-mt") == 0)
      mt = 1;
    else if (strcmp(argv[i], "-st") == 0)
      mt = 0;
    else
      goto usage;
  }
  if (mt) {
#ifdef ILU_OS_THREADED
    ILU_C_USE_OS_THREADS;
#else
    fprintf(stderr, "Multi-threading not configured into ILU!\n");
    exit(1);
#endif
  }
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
  for (i = 0; i < nsers; i++) {
    Inst           *inst = (Inst *) ilu_must_malloc(sizeof(*inst));
    ilu_FineTime    now;
    inst->si = ILU_C_CreateSerializationContext(t->server, &env);
    if (!ILU_C_SUCCESSFUL(&env)) {
      fprintf(stderr, "ILU_C_CreateSerializationContext() => %s\n",
	      ILU_C_EXCEPTION_ID(&env));
      exit(1);
    }
    inst->a = ilu_CreateAlarm();
    inst->i = i;
    inst->n = nper;
    now = ilu_FineTime_Now();
    inst->seed = (now.ft_s + now.ft_t) % 1013;
    Sched(inst);
#if defined(WIN32)
      _sleep(1);
#else
      sleep(1);
#endif
  }
  ILU_C_Run();
  return 0;
usage:
  fprintf(stderr,
	  "Usage: %s n-threads calls-per-thread [-v] [-mt|-st]\n",
	  argv[0]);
  return (1);
}
