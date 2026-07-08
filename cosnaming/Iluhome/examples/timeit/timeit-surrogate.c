/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:22:50 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/timeit/timeit.idl" of Thu Aug 07 15:38:55 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "timeit.h"

CORBA_unsigned_long _timeit_p_ping1__clientstub (timeit_p _handle, CORBA_unsigned_long p1, ILU_C_ENVIRONMENT *_status)
{
  CORBA_unsigned_long _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[1].parm_val  = (void *) &p1;
  _ILU_C_VectorCall (_timeit_p__ILUType, &_timeit_p__ILUType->cl_methods[0],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

CORBA_double _timeit_p_ping2__clientstub (timeit_p _handle, CORBA_double p2, ILU_C_ENVIRONMENT *_status)
{
  CORBA_double _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_CORBA_double;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_CORBA_double;
  __parmsBlock[1].parm_val  = (void *) &p2;
  _ILU_C_VectorCall (_timeit_p__ILUType, &_timeit_p__ILUType->cl_methods[1],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

ilu_CString _timeit_p_ping3__clientstub (timeit_p _handle, ilu_CString p3, ILU_C_ENVIRONMENT *_status)
{
  ilu_CString _retvalue;
  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_ilu_CString;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_ilu_CString;
  __parmsBlock[1].parm_val  = (void *) p3;
  _ILU_C_VectorCall (_timeit_p__ILUType, &_timeit_p__ILUType->cl_methods[2],
                     ILU_NIL, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

timeit_pageSeq* _timeit_p_doctest__clientstub (timeit_p _handle, ilu_CString name, CORBA_unsigned_long count, CORBA_unsigned_long pagesize, ILU_C_ENVIRONMENT *_status)
{
  timeit_pageSeq* _retvalue;
  _ILU_C_ParmDesc __parmsBlock[4];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_timeit_pageSeq;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_ilu_CString;
  __parmsBlock[1].parm_val  = (void *) name;
  __parmsBlock[2].parm_in  = 1;
  __parmsBlock[2].parm_out = 0;
  __parmsBlock[2].parm_needs_assignment   = 0;
  __parmsBlock[2].parm_needs_dereference  = 0;
  __parmsBlock[2].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[2].parm_val  = (void *) &count;
  __parmsBlock[3].parm_in  = 1;
  __parmsBlock[3].parm_out = 0;
  __parmsBlock[3].parm_needs_assignment   = 0;
  __parmsBlock[3].parm_needs_dereference  = 0;
  __parmsBlock[3].parm_type = TC_CORBA_unsigned_long;
  __parmsBlock[3].parm_val  = (void *) &pagesize;
  _ILU_C_VectorCall (_timeit_p__ILUType, &_timeit_p__ILUType->cl_methods[3],
                     ILU_NIL, _handle, _status, 4, __parmsBlock);
  return _retvalue;
}

void _timeit_p_imgtest__clientstub (timeit_p _handle, timeit_img20x20x20 val, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_timeit_img20x20x20;
  __parmsBlock[0].parm_val  = (void *) val;
  _ILU_C_VectorCall (_timeit_p__ILUType, &_timeit_p__ILUType->cl_methods[4],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

void _timeit_p_rectest__clientstub (timeit_p _handle, timeit_recseq* val, ILU_C_ENVIRONMENT *_status)
{
  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_timeit_recseq;
  __parmsBlock[0].parm_val  = (void *) val;
  _ILU_C_VectorCall (_timeit_p__ILUType, &_timeit_p__ILUType->cl_methods[5],
                     ILU_NIL, _handle, _status, 1, __parmsBlock);
  return;
}

static ILU_C_Class _timeit_p__SurrogateClass = 0;
timeit_p timeit_p__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (timeit_p) (ILU_C_SBHToObject(sbh, _timeit_p__ILUType, env));
}

void timeit__Initialize(void)
{
  extern void _timeit__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  _timeit__GeneralInitialization();
  _timeit_p__SurrogateClass = timeit_p__MakeClass(
    _timeit_p_ping1__clientstub,
    _timeit_p_ping2__clientstub,
    _timeit_p_ping3__clientstub,
    _timeit_p_doctest__clientstub,
    _timeit_p_imgtest__clientstub,
    _timeit_p_rectest__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_timeit_p__ILUType,
	_timeit_p__SurrogateClass);
  return;
}
