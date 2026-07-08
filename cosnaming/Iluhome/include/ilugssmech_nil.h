/* $Id: ilugssmech_nil.h,v 2.1 2025/08/14 09:53:18 cvswxc Exp $ */
#ifndef ILUGSSMECH_NIL_H
#define ILUGSSMECH_NIL_H 1

#ifdef __cplusplus
extern "C" {
#endif

/*
 * gss_nil_scheme.c -- implementation of "nil" security layer for GSS
 */

/* OID is { iso (1) member-body (2) US (840) Xerox (113550) ILU (9) GSS (1) nil-mech (3) } */

#define ILUGSSMECH_NIL_OID 	{ 9, "\x2a\x86\x48\x86\xf7\x0e\x09\x01\x03" }

GSS_PUBLIC gss_OID_desc ilugssmech_nil_OID[];

GSS_PUBLIC void ilugssmech_nil_initialize(void);

#ifdef __cplusplus
}
#endif

#endif /* ILUGSSMECH_NIL_H */              
