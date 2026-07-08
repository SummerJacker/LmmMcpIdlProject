/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Wed Aug 20 14:48:01 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/ngtest/NgProperty.isl" of Fri Aug 01 13:29:37 2025,
 * and "ngbasic.isl" of Fri Aug 01 13:29:37 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/interfaces/ilu.isl" of Fri Aug 01 09:16:44 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#include "NgProperty.h"

void _NgProperty_PutablePropertySet_PutProperties__clientstub (NgProperty_PutablePropertySet _handle, NgProperty_PropertyModificationSequence* propertiesToSet, ILU_C_ENVIRONMENT *_status)
{
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgBasic_NameSequence), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_NameSequence__Input, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[1];
  __parmsBlock[0].parm_in  = 1;
  __parmsBlock[0].parm_out = 0;
  __parmsBlock[0].parm_needs_assignment   = 0;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgProperty_PropertyModificationSequence;
  __parmsBlock[0].parm_val  = (void *) propertiesToSet;
  _ILU_C_VectorCall (_NgProperty_PutablePropertySet__ILUType, &_NgProperty_PutablePropertySet__ILUType->cl_methods[0],
                     _evec, _handle, _status, 1, __parmsBlock);
  return;
}

static ILU_C_Class _NgProperty_PutablePropertySet__SurrogateClass = 0;
NgProperty_PutablePropertySet NgProperty_PutablePropertySet__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgProperty_PutablePropertySet) (ILU_C_SBHToObject(sbh, _NgProperty_PutablePropertySet__ILUType, env));
}

NgProperty_PropertySequence* _NgProperty_PropertySet_GetProperties__clientstub (NgProperty_PropertySet _handle, NgProperty_PropertyNames* propertiesToGet, ILU_C_ENVIRONMENT *_status)
{
  NgProperty_PropertySequence* _retvalue;
  static struct _ILU_C_ExceptionDescription_s _evec[] = {
    { sizeof(NgBasic_NameSequence), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_NameSequence__Input, (ILU_C_FreeFn) NgBasic_NameSequence__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free },
    { sizeof(NgBasic_ExceptionInformation), ILU_NIL, 0, 0, (ILU_C_InputFn) _NgBasic_ExceptionInformation__Input, (ILU_C_FreeFn) NgBasic_ExceptionInformation__Free }};

  _ILU_C_ParmDesc __parmsBlock[2];
  __parmsBlock[0].parm_in  = 0;
  __parmsBlock[0].parm_out = 1;
  __parmsBlock[0].parm_needs_assignment   = 1;
  __parmsBlock[0].parm_needs_dereference  = 0;
  __parmsBlock[0].parm_type = TC_NgProperty_PropertySequence;
  __parmsBlock[0].parm_val  = (void *) &_retvalue;
  __parmsBlock[1].parm_in  = 1;
  __parmsBlock[1].parm_out = 0;
  __parmsBlock[1].parm_needs_assignment   = 0;
  __parmsBlock[1].parm_needs_dereference  = 0;
  __parmsBlock[1].parm_type = TC_NgProperty_PropertyNames;
  __parmsBlock[1].parm_val  = (void *) propertiesToGet;
  _ILU_C_VectorCall (_NgProperty_PropertySet__ILUType, &_NgProperty_PropertySet__ILUType->cl_methods[0],
                     _evec, _handle, _status, 2, __parmsBlock);
  return _retvalue;
}

static ILU_C_Class _NgProperty_PropertySet__SurrogateClass = 0;
NgProperty_PropertySet NgProperty_PropertySet__CreateFromSBH (char *sbh, ILU_C_ENVIRONMENT * env)
{
  return (NgProperty_PropertySet) (ILU_C_SBHToObject(sbh, _NgProperty_PropertySet__ILUType, env));
}

void NgProperty__Initialize(void)
{
  extern void _NgProperty__GeneralInitialization(void);

  static ilu_boolean initialized = ilu_FALSE;
  if (initialized) return;
  initialized = ilu_TRUE;

  NgBasic__Initialize();
  _NgProperty__GeneralInitialization();
  _NgProperty_PutablePropertySet__SurrogateClass = NgProperty_PutablePropertySet__MakeClass(
    _NgProperty_PutablePropertySet_PutProperties__clientstub,
    _NgProperty_PropertySet_GetProperties__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgProperty_PutablePropertySet__ILUType,
	_NgProperty_PutablePropertySet__SurrogateClass);
  _NgProperty_PropertySet__SurrogateClass = NgProperty_PropertySet__MakeClass(
    _NgProperty_PropertySet_GetProperties__clientstub,
    _NgBasic_NgObject_GetInterfaceDefinitionSource__clientstub,
    0 /* no finalization */
    );
  _ILU_C_RegisterSurrogateCType (_NgProperty_PropertySet__ILUType,
	_NgProperty_PropertySet__SurrogateClass);
  return;
}
