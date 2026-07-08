/* $Id: clnt.h,v 1.4 2025/08/02 10:00:49 cvswxc Exp $ */

extern int doit();

#if defined (_WINDOWS)
#define OUTPUT	WIN_PRINTF
extern void WIN_PRINTF(char *format, ...);
#else
#define OUTPUT	printf
#endif

