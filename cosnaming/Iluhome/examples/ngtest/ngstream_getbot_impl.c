/* $Id: ngstream_getbot_impl.c,v 1.4 2025/08/01 05:29:38 cvswxc Exp $ */

#include "nglib.h"
#include "nggetbot.h"

/* ILU server */
ILU_C_Server g_stream_server     = NULL;


/* ********************************************************* */
/* object table and setup functions                          */
/* ********************************************************* */

static CORBA_Object object_of_stream_handle (ilu_string str_object_id,  ilu_private p_iluserver) {
	
 /*  Stream Sinks are usually meant to be ephemeral.  As such,
	 the object table function for this server will return NULL (i.e.
	 sources and sinks cannot be created from the outside, e.g. a client
	 turns an sbh into a surrogate, and passes it to the server).
*/
	return NULL;
}


static void free_stream_object_table_storage (ilu_private p_iluserver) {
  return; /* nothing to do yet */
}


void ngstream_impl_setup_server() {

	static ilu_boolean b_already_setup = ilu_FALSE;
	ILU_C_ObjectTable object_table;
	char pc_serverid[1024];						/* holds a server id */

	if (b_already_setup)
		return ;
	
	/* create object table and ILU server*/

	/* StreamServer */
	object_table = ILU_C_CreateObjectTable (object_of_stream_handle, 
			free_stream_object_table_storage, (ilu_private) &g_stream_server);

	sprintf (pc_serverid, "nggetbot.StreamServer.%s%s", g_pc_hostname, g_pc_nggetbot_suffix);

	g_stream_server = ILU_C_InitializeServer ( pc_serverid, object_table, 
		g_pc_nonhttp_pinfo, get_ngtinfo(), (ilu_Passport) ILU_NIL, ilu_TRUE );

	b_already_setup = ilu_TRUE;

}




NgBasic_String 
server_NgStream_DataSink_GetInterfaceDefinitionSource 
(NgStream_DataSink datasink, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSink_GetInterfaceDefinitionSource");
    return NULL;
}


void 
server_NgStream_DataSink_RegisterSourceControl 
(NgStream_DataSink datasink, NgStream_DataSource thesource, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSink_RegisterSourceControl");
    return ;
}


void 
server_NgStream_DataSink_Done
(NgStream_DataSink datasink,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSink_Done");
    return ;
}


NgBasic_String 
server_NgStream_DataSource_GetInterfaceDefinitionSource 
(NgStream_DataSource _handle,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSource_GetInterfaceDefinitionSource");
    return NULL;
}


void 
server_NgStream_DataSource_Abort 
(NgStream_DataSource _handle, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSource_Abort");
    return ;
}


void 
server_NgStream_DataSource_Pause 
(NgStream_DataSource _handle,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSource_Pause");
    return ;
}


void 
server_NgStream_DataSource_Resume
(NgStream_DataSource _handle, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSource_Resume");
    return ;
}



void 
server_NgStream_DataSource_Resend 
(NgStream_DataSource _handle, 
 NgBasic_UnsignedInclusiveInterval* repeatRange,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSource_Resend");
    return ;
}



void
server_NgStream_DataSource_SuggestChunkSize 
(NgStream_DataSource _handle, 
 CORBA_unsigned_long suggestedSize, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgStream_DataSource_SuggestChunkSize");
    return ;
}

