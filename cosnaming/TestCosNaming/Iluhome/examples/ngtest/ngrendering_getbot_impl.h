/* $Id: ngrendering_getbot_impl.h,v 1.4 2025/08/01 05:29:38 cvswxc Exp $ */

#ifndef __ngrendering_getbot_impl__h__
#define __ngrendering_getbot_impl__h__

#include "NgRendering.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct RenderingSinkObjectData_s {
	ilu_cardinal m_card_last_byte_received_index;
	NgStream_DataSource m_datasource;
	ilu_Mutex m_access_mutex;
	ilu_Condition m_done_condition;
	char* m_pc_object_id; /* object id os object whose rendering we're receiving */
	ilu_FineTime  m_time_begin;  /* When the SendRendering began */

} RenderingSinkObjectData;

/* allocates instance data for RenderingSinks 
 pc_object_id is the object id of the object whose rendering we're going to receive */
extern RenderingSinkObjectData* MallocRenderingSinkObjectData(char* pc_object_id, ilu_FineTime time_begin);


#ifdef __cplusplus
}
#endif


#endif /* __ngrendering_getbot_impl__h__ */
