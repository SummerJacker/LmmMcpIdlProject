/* $Id: ngrendering_webserv_impl.c,v 1.4 2025/08/01 05:29:38 cvswxc Exp $ */

#include "nglib.h"
#include "NgRendering.h"


NgBasic_String 
server_NgRendering_PutableRenderable_GetInterfaceDefinitionSource 
(NgRendering_PutableRenderable _handle,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_PutableRenderable_GetInterfaceDefinitionSource");
    return NULL;
}



NgRendering_RenderingPreferences* 
server_NgRendering_PutableRenderable_GetAvailableRenderings
(NgRendering_PutableRenderable _handle, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_PutableRenderable_GetAvailableRenderings");
    return NULL;
}



NgRendering_Rendering*
server_NgRendering_PutableRenderable_GetRendering 
(NgRendering_PutableRenderable _handle, 
 NgRendering_RenderingPreferences* renderingPreferences, 
 NgCache_OptionalRequestCacheControl requestCacheInfo, 
 NgCache_OptionalResponseCacheControl* responseCacheInfo,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_PutableRenderable_GetRendering");
    return NULL;
}



void 
server_NgRendering_PutableRenderable_SendRendering 
(NgRendering_PutableRenderable _handle, 
 NgRendering_RenderingPreferences* renderingPreferences,
 NgCache_OptionalRequestCacheControl requestCacheInfo, 
 NgRendering_RenderingSink renderSink, 
 NgBasic_OptionalCardinal suggestedChunkSize, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_PutableRenderable_SendRendering");
    return ;
}



void 
server_NgRendering_PutableRenderable_SendRenderingSynched
(NgRendering_PutableRenderable _handle, 
 NgRendering_RenderingPreferences* renderingPreferences,
 NgCache_OptionalRequestCacheControl requestCacheInfo, 
 NgRendering_RenderingSink renderSink, 
 NgBasic_OptionalCardinal suggestedChunkSize, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_PutableRenderable_SendRenderingSynched");
    return ;
}



void 
server_NgRendering_PutableRenderable_PutRendering 
(NgRendering_PutableRenderable _handle, 
 NgRendering_Rendering* renderingInput, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_PutableRenderable_PutRendering");
    return ;
}



NgBasic_String 
server_NgRendering_Renderable_GetInterfaceDefinitionSource 
(NgRendering_Renderable _handle, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_Renderable_GetInterfaceDefinitionSource");
    return NULL;
}



NgRendering_RenderingPreferences* 
server_NgRendering_Renderable_GetAvailableRenderings
(NgRendering_Renderable _handle,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_Renderable_GetAvailableRenderings");
    return NULL;
}



NgRendering_Rendering* 
server_NgRendering_Renderable_GetRendering
(NgRendering_Renderable _handle, 
 NgRendering_RenderingPreferences* renderingPreferences, 
 NgCache_RequestCacheControl* requestCacheInfo,
 NgCache_ResponseCacheControl** responseCacheInfo, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_Renderable_GetRendering");
    return NULL;
}



void 
server_NgRendering_Renderable_SendRendering 
(NgRendering_Renderable _handle, 
 NgRendering_RenderingPreferences* renderingPreferences,
 NgCache_RequestCacheControl* requestCacheInfo, 
 NgRendering_RenderingSink renderSink, 
 NgBasic_OptionalCardinal suggestedChunkSize, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_Renderable_SendRendering");
    return ;
}



void 
server_NgRendering_Renderable_SendRenderingSynched 
(NgRendering_Renderable _handle,
 NgRendering_RenderingPreferences* renderingPreferences,
 NgCache_RequestCacheControl* requestCacheInfo, 
 NgRendering_RenderingSink renderSink,
 NgBasic_OptionalCardinal suggestedChunkSize, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_Renderable_SendRenderingSynched");
    return ;
}



NgBasic_String 
server_NgRendering_RenderingSink_GetInterfaceDefinitionSource 
(NgRendering_RenderingSink _handle,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_GetInterfaceDefinitionSource");
    return NULL;
}



void 
server_NgRendering_RenderingSink_RegisterSourceControl 
(NgRendering_RenderingSink _handle, 
 NgStream_DataSource thesource, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_RegisterSourceControl");
    return ;
}



void 
server_NgRendering_RenderingSink_Done
(NgRendering_RenderingSink _handle,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_Done");
    return ;
}



void
server_NgRendering_RenderingSink_RegisterResponseCacheControl 
(NgRendering_RenderingSink _handle,
 NgCache_ResponseCacheControl* responseCacheInfo,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_RegisterResponseCacheControl");
    return ;
}



void
server_NgRendering_RenderingSink_RenderingProblem 
(NgRendering_RenderingSink _handle,
 NgRendering_RenderingProblemReport* report, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_RenderingProblem");
    return ;
}



void
server_NgRendering_RenderingSink_ReceiveRendering 
(NgRendering_RenderingSink _handle, 
 NgRendering_Rendering* therendering, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_ReceiveRendering");
    return ;
}



void 
server_NgRendering_RenderingSink_ReceiveRenderingChunk
(NgRendering_RenderingSink _handle,
 NgRendering_RenderingChunk* thechunk,
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_ReceiveRenderingChunk");
    return ;
}



NgBasic_OptionalCardinal 
server_NgRendering_RenderingSink_Resynchronize 
(NgRendering_RenderingSink _handle, 
 ILU_C_ENVIRONMENT *_status) {
    
    NGLIB_NYI("server_NgRendering_RenderingSink_Resynchronize");
    return NULL;
}



