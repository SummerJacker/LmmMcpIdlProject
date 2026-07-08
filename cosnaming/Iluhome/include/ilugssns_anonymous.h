/* $Id: ilugssns_anonymous.h,v 2.1 2025/08/14 09:53:18 cvswxc Exp $ */
#ifndef ILUGSSNS_ANONYMOUS_H
#define ILUGSSNS_ANONYMOUS_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ilugssns_anonymous.h -- internal data structures for representing GSS anonymous names
 */

/* OID is {2(joint-iso-ccitt) 16(country) 840(US(ANSI)) 1(organizations) 113687(OpenVision) 1(security) 2(nametypes) 1(anonymous-name)} */

#define ILUGSSNS_ANONYMOUS_OID	{10, "\x60\x86\x48\x01\x86\xf8\x17\x01\x02\x01"}

GSS_PUBLIC gss_OID_desc ilugssns_anonymous_OID[];

/* initialize routine: */
GSS_PUBLIC void ilugssns_anonymous_initialize(void);

/* fetch the only name in the namespace */
GSS_PUBLIC gss_name_t ilugssns_anonymous_default_name(void);

#ifdef __cplusplus
}
#endif

#endif /* ndef ILUGSSNS_RFC822_H */
