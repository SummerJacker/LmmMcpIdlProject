/* $Id: ngwebserver.h,v 1.4 2025/08/01 05:29:38 cvswxc Exp $ */

/* very simple brute force web server program for testing HTTP-NG

  Dan Larner, larner@parc.xerox.com
  4-23-98
  */

/* ********************************************************* */
/* includes and defines                                      */
/* ********************************************************* */

#ifndef __ngwebserver_h__
#define __ngwebserver_h__

#ifdef __cplusplus
extern "C" {
#endif


#include "nglib.h"

#define MAX_VERBOSITY_LEVEL 3
#define LOG_NOTHING	0
#define LOG_SUMMARY 1
#define LOG_BASIC	2
#define LOG_FULL	3

/* makes a log entry if appropriate */

#define LOG_ENTER() if (g_logfile_mutex) ilu_AcquireMutex(g_logfile_mutex)
#define LOG_EXIT() if (g_logfile_mutex) ilu_ReleaseMutex(g_logfile_mutex)

#define DO_LOG_BASIC() g_p_logfile && g_i_verbosity >= LOG_BASIC 	
#define DO_LOG_SUMMARY() g_p_logfile && g_i_verbosity >= LOG_SUMMARY 	
#define DO_LOG_FULL() g_p_logfile && g_i_verbosity >= LOG_FULL 	


/* default string used as suffix to our ilu server names */
#define XEROX_PARC_DOMAIN ".parc.xerox.com"	

/* the file name we use if just a slash is specified in a URL */
#define DEFAULT_SERVER_FILE_NAME "/index.html"	

/* the file name we use if just a slash is specified in a URL */
#define DEFAULT_FILE_BASE "\\htmldocs"	

/* the file name where log output goes */
#define DEFAULT_LOG_FILENAME "stdout"	


/* ********************************************************* */
/* some globals                                              */
/* ********************************************************* */


/* level of output info */
extern int g_i_verbosity;

/* base location of files */
extern char* g_pc_file_base;

/* string used as suffix to our ilu server names */
extern ilu_string g_pc_ngwebserver_suffix;


/* default contact info to export iluhttp_Resource objects with */
extern char* g_pc_http_pinfo;
extern char* g_ppc_http_tinfo [];


/* default contact info to export non iluhttp_Resource objects with */
extern char* g_pc_nonhttp_pinfo;
extern char* g_ppc_nonhttp_tinfo [];


/* port to start creating ng servers at */
extern unsigned short g_us_ngtcpport;


/* whether to run ILU multithreaded */
extern int g_b_multithreaded;	

/* logfile */
extern FILE* g_p_logfile;
extern ilu_Mutex g_logfile_mutex;

/* simple total of how many WebDocument:GetRendering,
WebDocument:SendRendering, and iluhttp.Resource Get calls
were performed.  Increment under protection of g_logfile_mutex */
extern int g_i_request_count; 

/* ILU batcher if used */
extern ILU_C_Batcher g_batcher;

/* holds the name of this host */
extern char g_pc_hostname[];			

/* ********************************************************* */
/* ILU Servers                                               */
/* ********************************************************* */

/*
The object types defined in the NG ISL files are assigned to
ILU servers in the following fashion:


Note: These types that are meant to be abstract (just used as base types)
      ngbasic.isl:    Type NgObject = Object
      ngstream.isl:   Type DataSink = Object
      ngrendering.isl:Type Renderable = Object
      ngrendering.isl:Type PutableRenderable = Object

Note: Since this is a server, we'll never have true sink objects.
      ngdocument.isl:  Type RenderingAndPropertiesSink = Object
      ngrendering.isl: Type RenderingSink = Object
      ngform.isl:      Type ProcessedFormSink = Object


Where the full Server ID is formed by appending '.', the hostname, and then
the serversuffix from the command line to the ServerID value


ServerID = HTTPServer
----------------------
iluhttp.isl:TYPE Resource = OBJECT

Object ID's that begin with a forward slash are assumed to be for iluhttp.Resource objects.


ServerID = FormServer
---------------------
ngform.isl:Type FormProcessor = Object


ServerID = DocumentServer
-------------------------
ngdocument.isl:Type WebDocument = Object
ngdocument.isl:Type PutableWebDocument = Object
ngdocument.isl:Type HTTPCompatibleWebDocument = Object


ServerID = PropertyServer
-------------------------
ngproperty.isl:Type PropertySet = Object
ngproperty.isl:Type PutablePropertySet = Object


ServerID = StreamServer
-----------------------
Note: Stream Sources are usually meant to be ephemeral.  As such,
the object table function for this server will return NULL (i.e.
sources and sinks cannot be created from the outside, e.g. a client
turns an sbh into a surrogate, and passes it to the server).
ngstream.isl:    Type DataSource = Object


*/

extern ILU_C_Server g_http_server;
extern ILU_C_Server g_form_server;
extern ILU_C_Server g_document_server;
extern ILU_C_Server g_property_server;
extern ILU_C_Server g_stream_server;



/* returns g_ppc_nonhttp_tinfo set up with tcp_0_<value of g_us_ngtcpport++>
on each call */
extern char** get_ngtinfo();


#ifdef __cplusplus
}
#endif


#endif /* __ngwebserver_h__ */
