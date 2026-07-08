/* $Id: iludebug.h,v 2.1 2025/08/01 00:13:00 cvswxc Exp $ */


/*L1, L2, Main unconstrained*/

ILU_PUBLIC ilu_cardinal ilu_DebugLevel;
ILU_PUBLIC ilu_boolean  ilu_DebuggingInitialized;

#ifdef ENABLE_DEBUGGING
#define ILU_NOTE(level,code)	do {if((ilu_DebugLevel & (level)) != 0)ilu_DebugPrintf code;} while (0)
#define ILU_NOTE_AND(level,code)	do {if ((ilu_DebugLevel & (level)) == (level))ilu_DebugPrintf code;} while (0)
#define ILU_AUTOSETDEBUGLEVEL	do {if(!ilu_DebuggingInitialized) _ilu_AutoSetDebugLevel();} while (0)
#else
#define ILU_NOTE(level,code)		0
#define ILU_NOTE_AND(level,code)	0
#define ILU_AUTOSETDEBUGLEVEL		0
#endif

#define MALLOC_DEBUG		0x01
#define LOCK_DEBUG		0x02
#define PACKET_DEBUG		0x04
#define ERROR_DEBUG		0x08
#define CONNECTION_DEBUG	0x10
#define INCOMING_DEBUG		0x20
#define EXPORT_DEBUG		0x40
#define AUTHENTICATION_DEBUG	0x80
#define OBJECT_DEBUG		0x100
#define SUNRPC_DEBUG		0x200
#define CALL_DEBUG		0x400
#define TCP_DEBUG		0x800
#define UDP_DEBUG		0x800
#define XNSSPP_DEBUG		0x800
#define COURIER_DEBUG		0x1000
#define GC_DEBUG		0x2000
#define SERVER_DEBUG		0x4000
#define DCERPC_DEBUG		0x8000
#define MAINLOOP_DEBUG		0x10000
#define IIOP_DEBUG		0x20000
#define SECURITY_DEBUG		0x40000
#define SUNRPCRM_DEBUG		0x80000
#define INMEM_DEBUG		0x100000
#define BINDING_DEBUG		0x200000
#define W3MUX_DEBUG		0x400000
#define W3NG_DEBUG		0x800000
#define THREAD_DEBUG		MAINLOOP_DEBUG
#define LSR_DEBUG		0x1000000
#define TYPE_DEBUG		0x2000000
#define RELEASEOBJ_DEBUG	0x4000000
#define JAVARMI_DEBUG		0x8000000
#define HTTP_DEBUG		0x10000000
#define TIMING_DEBUG		0x20000000
#define ZLIB_DEBUG		0x40000000

#define ILU_DEBUG_LIST		\
 { "PACKET", PACKET_DEBUG }, \
 { "CONNECTION", CONNECTION_DEBUG }, \
 { "INCOMING", INCOMING_DEBUG }, \
 { "EXPORT", EXPORT_DEBUG }, \
 { "AUTHENTICATION", AUTHENTICATION_DEBUG }, \
 { "OBJECT", OBJECT_DEBUG }, \
 { "SUNRPC", SUNRPC_DEBUG }, \
 { "CALL", CALL_DEBUG }, \
 { "TCP", TCP_DEBUG }, \
 { "UDP", UDP_DEBUG }, \
 { "XNSSPP", XNSSPP_DEBUG }, \
 { "COURIER", COURIER_DEBUG }, \
 { "GC", GC_DEBUG }, \
 { "SERVER", SERVER_DEBUG }, \
 { "LOCK", LOCK_DEBUG }, \
 { "DCERPC", DCERPC_DEBUG }, \
 { "MALLOC", MALLOC_DEBUG }, \
 { "MAINLOOP", MAINLOOP_DEBUG }, \
 { "IIOP", IIOP_DEBUG }, \
 { "SECURITY", SECURITY_DEBUG }, \
 { "ERROR", ERROR_DEBUG }, \
 { "SUNRPCRM", SUNRPCRM_DEBUG }, \
 { "INMEM", INMEM_DEBUG }, \
 { "BINDING", BINDING_DEBUG }, \
 { "W3MUX", W3MUX_DEBUG }, \
 { "W3NG", W3NG_DEBUG }, \
 { "THREAD", THREAD_DEBUG }, \
 { "LSR", LSR_DEBUG }, \
 { "TYPE", TYPE_DEBUG }, \
 { "RELEASEOBJ", RELEASEOBJ_DEBUG }, \
 { "JAVARMI", JAVARMI_DEBUG }, \
 { "HTTP", HTTP_DEBUG }, \
 { "TIMING", TIMING_DEBUG }, \
 { "ZLIB", ZLIB_DEBUG }, \
 { "MOST", (0xFFFFFFFF ^ (LOCK_DEBUG|MALLOC_DEBUG|RELEASEOBJ_DEBUG \
	                  |TIMING_DEBUG)) }, \
 { "ALL", 0xFFFFFFFF }

#define FATAL(msg)		(ILU_ERRPRINTF(msg),*((int *)0)=1)
