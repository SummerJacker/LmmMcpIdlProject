/* $Id: ngproperty_webserv_impl.c,v 1.4 2025/08/01 05:29:37 cvswxc Exp $ */

#include "nglib.h"
#include "ngwebserver.h"

/* ILU server */
ILU_C_Server g_property_server     = NULL;

/* ********************************************************* */
/* object table and setup functions                          */
/* ********************************************************* */

static CORBA_Object object_of_property_handle (ilu_string str_object_id, 
										   ilu_private p_iluserver) {
	
	/* object ids in this server must begin with their typename :
	   e.g. w3ng:DocumentServer.pundit.parc.xerox.com/PropertySet:/foo/bar.html
	
	*/
	if (strncmp("PropertySet:", str_object_id, 14) == 0)
		return (NgProperty_PropertySet__OTCreateTrue (str_object_id,
		*((ILU_C_Server *) p_iluserver), NULL)); 

	if (strncmp("PutablePropertySet:", str_object_id, 14) == 0)
		return (NgProperty_PutablePropertySet__OTCreateTrue (str_object_id,
		*((ILU_C_Server *) p_iluserver), NULL)); 

	return NULL;
}


static void free_property_object_table_storage (ilu_private p_iluserver) {
  return; /* nothing to do yet */
}


void ngproperty_impl_setup_server() {

	static ilu_boolean b_already_setup = ilu_FALSE;
	ILU_C_ObjectTable object_table;
	char pc_serverid[1024];						/* holds a server id */

	if (b_already_setup)
		return ;
	
	/* create object table and ILU server*/

	/* PropertyServer */
	object_table = ILU_C_CreateObjectTable (object_of_property_handle, 
			free_property_object_table_storage, (ilu_private) &g_property_server);

	sprintf (pc_serverid, "PropertyServer.%s%s", g_pc_hostname, g_pc_ngwebserver_suffix);

	g_property_server = ILU_C_InitializeServer ( pc_serverid, object_table, 
		g_pc_nonhttp_pinfo, get_ngtinfo(), (ilu_Passport) ILU_NIL, ilu_TRUE );

	b_already_setup = ilu_TRUE;

}


NgBasic_String 
server_NgProperty_PutablePropertySet_GetInterfaceDefinitionSource 
(NgProperty_PutablePropertySet _handle, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgProperty_PutablePropertySet_GetInterfaceDefinitionSource");
    return NULL;
}



NgProperty_PropertySequence* 
server_NgProperty_PutablePropertySet_GetProperties 
(NgProperty_PutablePropertySet _handle, 
 NgProperty_PropertyNames* propertiesToGet, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgProperty_PutablePropertySet_GetProperties");
    return NULL;
}



void 
server_NgProperty_PutablePropertySet_PutProperties 
(NgProperty_PutablePropertySet _handle, 
 NgProperty_PropertyModificationSequence* propertiesToSet,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgProperty_PutablePropertySet_PutProperties");
    return ;
}



NgBasic_String
server_NgProperty_PropertySet_GetInterfaceDefinitionSource 
(NgProperty_PropertySet _handle, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgProperty_PropertySet_GetInterfaceDefinitionSource");
    return NULL;
}



NgProperty_PropertySequence* 
server_NgProperty_PropertySet_GetProperties 
(NgProperty_PropertySet _handle, 
 NgProperty_PropertyNames* propertiesToGet, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgProperty_PropertySet_GetProperties");
    return NULL;
}



