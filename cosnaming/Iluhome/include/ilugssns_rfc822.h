/* $Id: ilugssns_rfc822.h,v 2.1 2025/08/14 09:53:18 cvswxc Exp $ */
#ifndef ILUGSSNS_RFC822_H
#define ILUGSSNS_RFC822_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ilugssns_rfc822.h -- internal data structures for representing RFC 822 style
 *		  names
 *
 * Antony Courtney,	14/7/95
 */

/* OID is { iso (1) member-body (2) US (840) Xerox (113550) ILU (9) GSS (1) rfc822-namespace (4) } */

#define ILUGSSNS_RFC822_OID	{ 9, "\x2a\x86\x48\x86\xf7\x0e\x09\x01\x04" }

GSS_PUBLIC gss_OID_desc ilugssns_rfc822_OID[];

typedef struct ilugssns_rfc822_name_s {
     char *rname;	/* user's real name */
     char *uname;	/* user name */
     char *dname;	/* domain name */
} ilugssns_rfc822_name_t;

/* initialize routine: */
GSS_PUBLIC void ilugssns_rfc822_initialize(void);

/* RFC-822 specific minor status codes: */

/* malformed names: */
#define ILUGSSNS_RFC822_INVALID_SPACE	1	/* whitespace occurred in a
						   name where none was
						   allowed   */
#define ILUGSSNS_RFC822_MULTIPLE_AT		2	/* multiple "@" delimiters */
#define ILUGSSNS_RFC822_NO_RDELIM		3	/* missing right-hand
						   delimiter */
#define ILUGSSNS_RFC822_MALFORMED		4	/* malformed name */

#ifdef __cplusplus
}
#endif

#endif /* ndef ILUGSSNS_RFC822_H */
