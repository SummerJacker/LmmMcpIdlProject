/* $Id: ngstream_webserv_impl.h,v 1.4 2025/08/01 05:29:38 cvswxc Exp $ */

#ifndef __ngstream_webserv_impl__h__
#define __ngstream_webserv_impl__h__

#ifdef __cplusplus
extern "C" {
#endif

/* the chunk size to use if one isn't suggested */
#define NGWEBSEVER_DEFAULT_CHUNK_SIZE 2048


typedef struct DataSourceObjectData_s {
	int m_h_native_content_file;
	ilu_cardinal m_card_chunking_size;
	ilu_cardinal m_card_next_unsent_byte_index;
	ilu_cardinal m_card_last_byte_to_send_index;
	ilu_integer m_i_state; /* 0 = run, 1 = paused, 2 = abort */
	ilu_Mutex m_access_mutex;
	ilu_Condition m_state_change_condition;
	char* m_pc_content_type;
	ilu_boolean m_b_like_head;
	char* m_pc_object_id;
	NgStream_DataSink m_renderSink;
	ILU_C_Pipeline m_pipeline;
	ILU_C_Serializer m_serializer;
} DataSourceObjectData;


extern DataSourceObjectData* MallocDataSourceObjectData(int h_native_content_file,
												 ilu_cardinal start, 
												 ilu_cardinal end,
												 ilu_cardinal suggestedChunkSize,
												 char* pc_content_type,
												 ilu_boolean b_like_head,
												 char* pc_object_id,
												 NgStream_DataSink renderSink);


extern void do_data_source_work (NgStream_DataSource data_source);

#ifdef __cplusplus
}
#endif


#endif /* __ngstream_webserv_impl__h__ */
