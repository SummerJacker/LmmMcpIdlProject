/* $Id: srvr.h,v 1.4 2025/08/02 10:01:23 cvswxc Exp $ */

#include <iluxport.h>

extern int      doit(char *pinfo, ilu_TransportInfo tinfo,
		     ilu_boolean threadly,
		     ilu_boolean init_credentials,
		     ilu_boolean use_ssl_if_available);
/*
 * Both pointer arguments may be defaulted to NULL; defaulting tinfo
 * means to initialize credentials and use security if available.
 */

extern ilu_TransportInfo DefaultTInfo(ilu_boolean secure, ilu_boolean ssl);
/*
 * Return the default ilu_TransportInfo.  Returns NIL if /secure/
 * but security support isn't configured into ILU.
 */


#if defined (_WINDOWS)
#define OUTPUT	WIN_PRINTF
extern void WIN_PRINTF(char *format, ...);
#else
#define OUTPUT	printf
#endif
