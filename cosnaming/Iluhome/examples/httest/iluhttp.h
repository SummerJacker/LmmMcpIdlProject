/*
 * This file was automatically generated with KISORB (version 2.0beta1) tools
 * at Fri Aug 22 17:23:28 2025 by `沈阳市软件定义智能协同重点实验室'
 * running "D:/Shaun-projects/newstar/Iluhome/bin/c-stubber.exe" of Mon Aug 18 11:47:22 2025
 * on "D:/Shaun-projects/newstar/Iluhome/examples/httest/iluhttp.isl" of Mon Jul 21 17:22:19 2025,
 * and "D:/Shaun-projects/newstar/Iluhome/examples/httest/ilu.isl" of Wed Jul 30 16:32:51 2025 *
 * KISORB is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
 * KISORB information: Dr. Wang xcwang89@aliyun.com .
 */

#ifndef __iluhttp_h_
#define __iluhttp_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "ilucstub.h"

/************************************************************************/
/************************************************************************/
/***                             iluhttp                              ***/
/************************************************************************/
/************************************************************************/

extern void iluhttp__Initialize(void);
extern void iluhttp__InitializeServer(void);


/*======================================================================*/
/*====================== Object type declarations ======================*/

typedef ILU_C_OBJECT iluhttp_Resource;



/*======================================================================*/
/*========================= typedefs ===================================*/

typedef struct iluhttp_Response iluhttp_Response;
typedef struct iluhttp_Request iluhttp_Request;
typedef enum {iluhttp_Continue = 100, iluhttp_SwitchingProtocols = 101, iluhttp_OK = 200, iluhttp_Created = 201, iluhttp_Accepted = 202, iluhttp_NonAuthoritativeInformation = 203, iluhttp_NoContent = 204, iluhttp_ResetContent = 205, iluhttp_PartialContent = 206, iluhttp_MultipleChoices = 300, iluhttp_MovedPermanently = 301, iluhttp_Found = 302, iluhttp_SeeOther = 303, iluhttp_NotModified = 304, iluhttp_UseProxy = 305, iluhttp_TemporaryRedirect = 307, iluhttp_PermanentRedirect = 308, iluhttp_BadRequest = 400, iluhttp_Unauthorized = 401, iluhttp_PaymentRequired = 402, iluhttp_Forbidden = 403, iluhttp_NotFound = 404, iluhttp_MethodNotAllowed = 405, iluhttp_NotAcceptable = 406, iluhttp_ProxyAuthenticatoinRequired = 407, iluhttp_RequestTimeout = 408, iluhttp_Conflict = 409, iluhttp_Gone = 410, iluhttp_LengthRequired = 411, iluhttp_PreconditionFailed = 412, iluhttp_ContentTooLarge = 413, iluhttp_URITooLong = 414, iluhttp_UnsupportedMediaType = 415, iluhttp_RangeNotSatisfiable = 416, iluhttp_ExpectationFailed = 417, iluhttp_Unused = 418, iluhttp_MisdiectedRequest = 421, iluhttp_UnprocessableConent = 422, iluhttp_UpgradeReqired = 426, iluhttp_InternalServerError = 500, iluhttp_NotImplemented = 501, iluhttp_BadGateway = 502, iluhttp_ServiceUnavailable = 503, iluhttp_GatewayTimeout = 504, iluhttp_HTTPVersionNotSupported = 505} iluhttp_StatusCode;
typedef ilu_CString iluhttp_RequestURI;
typedef struct _iluhttp_EntityBody__sequence iluhttp_EntityBody;
typedef iluhttp_EntityBody *iluhttp_OptionalEntityBody;
typedef struct _iluhttp_HTTPHeaders__sequence iluhttp_HTTPHeaders;
typedef struct iluhttp_Header iluhttp_Header;
typedef iluhttp_Header iluhttp_HTTPHeader;
typedef ilu_CString iluhttp_field_value;
typedef ilu_CString iluhttp_optional_field_value;
typedef ilu_CString iluhttp_field_name;



/*======================================================================*/
/*=============== non-object type declarations =========================*/

iluhttp_StatusCode *
  CORBA_sequence_iluhttp_StatusCode_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "iluhttp_HTTPHeaders" */
struct _iluhttp_HTTPHeaders__sequence {
 unsigned long _maximum;
 unsigned long _length;
 iluhttp_HTTPHeader *_buffer;
};
void iluhttp_HTTPHeaders_Every (iluhttp_HTTPHeaders *h, void (*f)(iluhttp_HTTPHeader*, void *, ilu_Error *), void *);
void iluhttp_HTTPHeaders_Append (iluhttp_HTTPHeaders *h, iluhttp_HTTPHeader* item, ilu_Error *);
void iluhttp_HTTPHeaders_Push (iluhttp_HTTPHeaders *h, iluhttp_HTTPHeader* item);
void iluhttp_HTTPHeaders_Pop (iluhttp_HTTPHeaders *h, iluhttp_HTTPHeader* item);
CORBA_unsigned_long iluhttp_HTTPHeaders_Length (iluhttp_HTTPHeaders *);
iluhttp_HTTPHeader * iluhttp_HTTPHeaders_Nth (iluhttp_HTTPHeaders *, CORBA_unsigned_long);
iluhttp_HTTPHeaders * iluhttp_HTTPHeaders_Create (CORBA_unsigned_long /* size */, iluhttp_HTTPHeader*  /* init val */);
void iluhttp_HTTPHeaders_Init (iluhttp_HTTPHeaders * /* seq */, CORBA_unsigned_long /* size */, iluhttp_HTTPHeader*  /* init val */);
iluhttp_HTTPHeaders *
  CORBA_sequence_iluhttp_HTTPHeaders_allocbuf (CORBA_unsigned_long /* count */);

/* sequence type "iluhttp_EntityBody" */
struct _iluhttp_EntityBody__sequence {
 unsigned long _maximum;
 unsigned long _length;
 CORBA_octet *_buffer;
};
void iluhttp_EntityBody_Every (iluhttp_EntityBody *h, void (*f)(CORBA_octet*, void *, ilu_Error *), void *);
void iluhttp_EntityBody_Append (iluhttp_EntityBody *h, CORBA_octet item, ilu_Error *);
void iluhttp_EntityBody_Push (iluhttp_EntityBody *h, CORBA_octet item);
void iluhttp_EntityBody_Pop (iluhttp_EntityBody *h, CORBA_octet *item);
CORBA_unsigned_long iluhttp_EntityBody_Length (iluhttp_EntityBody *);
CORBA_octet * iluhttp_EntityBody_Nth (iluhttp_EntityBody *, CORBA_unsigned_long);
iluhttp_EntityBody * iluhttp_EntityBody_Create (CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
void iluhttp_EntityBody_Init (iluhttp_EntityBody * /* seq */, CORBA_unsigned_long /* size */, CORBA_octet * /* init val */);
iluhttp_EntityBody *
  CORBA_sequence_iluhttp_EntityBody_allocbuf (CORBA_unsigned_long /* count */);

iluhttp_OptionalEntityBody *
  CORBA_sequence_iluhttp_OptionalEntityBody_allocbuf (CORBA_unsigned_long /* count */);

/* record "iluhttp_Response" */
struct iluhttp_Response {
	iluhttp_StatusCode status;
	iluhttp_HTTPHeaders headers;
	iluhttp_OptionalEntityBody body;
};
iluhttp_Response *
  CORBA_sequence_iluhttp_Response_allocbuf (CORBA_unsigned_long /* count */);

/* "iluhttp_RequestURI" alias for "ilu_CString" */
#define iluhttp_RequestURI_Length ilu_CString_Length
#define iluhttp_RequestURI_Nth ilu_CString_Nth
#define iluhttp_RequestURI_Every ilu_CString_Every
#define iluhttp_RequestURI_Append ilu_CString_Append
#define iluhttp_RequestURI_Push ilu_CString_Push
#define iluhttp_RequestURI_Pop ilu_CString_Pop
#define iluhttp_RequestURI_Init ilu_CString_Init
#define iluhttp_RequestURI_Create ilu_CString_Create
#define iluhttp_RequestURI__Free ilu_CString__Free
#define iluhttp_RequestURI__alloc ilu_CString__alloc
#define CORBA_sequence_iluhttp_RequestURI_allocbuf CORBA_sequence_string_allocbuf

/* record "iluhttp_Request" */
struct iluhttp_Request {
	iluhttp_RequestURI URI;
	iluhttp_HTTPHeaders headers;
	iluhttp_OptionalEntityBody body;
};
iluhttp_Request *
  CORBA_sequence_iluhttp_Request_allocbuf (CORBA_unsigned_long /* count */);

iluhttp_Resource *
  CORBA_sequence_iluhttp_Resource_allocbuf (CORBA_unsigned_long /* count */);

/* "iluhttp_field_name" alias for "ilu_CString" */
#define iluhttp_field_name_Length ilu_CString_Length
#define iluhttp_field_name_Nth ilu_CString_Nth
#define iluhttp_field_name_Every ilu_CString_Every
#define iluhttp_field_name_Append ilu_CString_Append
#define iluhttp_field_name_Push ilu_CString_Push
#define iluhttp_field_name_Pop ilu_CString_Pop
#define iluhttp_field_name_Init ilu_CString_Init
#define iluhttp_field_name_Create ilu_CString_Create
#define iluhttp_field_name__Free ilu_CString__Free
#define iluhttp_field_name__alloc ilu_CString__alloc
#define CORBA_sequence_iluhttp_field_name_allocbuf CORBA_sequence_string_allocbuf

/* "iluhttp_field_value" alias for "ilu_CString" */
#define iluhttp_field_value_Length ilu_CString_Length
#define iluhttp_field_value_Nth ilu_CString_Nth
#define iluhttp_field_value_Every ilu_CString_Every
#define iluhttp_field_value_Append ilu_CString_Append
#define iluhttp_field_value_Push ilu_CString_Push
#define iluhttp_field_value_Pop ilu_CString_Pop
#define iluhttp_field_value_Init ilu_CString_Init
#define iluhttp_field_value_Create ilu_CString_Create
#define iluhttp_field_value__Free ilu_CString__Free
#define iluhttp_field_value__alloc ilu_CString__alloc
#define CORBA_sequence_iluhttp_field_value_allocbuf CORBA_sequence_string_allocbuf

iluhttp_optional_field_value *
  CORBA_sequence_iluhttp_optional_field_value_allocbuf (CORBA_unsigned_long /* count */);

/* record "iluhttp_Header" */
struct iluhttp_Header {
	iluhttp_field_name name;
	iluhttp_optional_field_value value;
};
iluhttp_Header *
  CORBA_sequence_iluhttp_Header_allocbuf (CORBA_unsigned_long /* count */);

/* "iluhttp_HTTPHeader" alias for "iluhttp_Header" */
#define CORBA_sequence_iluhttp_HTTPHeader_allocbuf CORBA_sequence_iluhttp_Header_allocbuf



/*======================================================================*/
/*================= object type declarations ===========================*/

/*-----------------------------------------------------------------------*/
/*-----  object type "iluhttp_Resource"  --------------------------------*/

#define iluhttp_Resource__MSType _iluhttp_Resource__ILUType

iluhttp_Resource
  iluhttp_Resource__CreateFromSBH (char * /* sbh */, ILU_C_ENVIRONMENT * /* env */);

/* For true module only: */

void
  iluhttp_Resource__SetUserData (iluhttp_Resource /* self */, void * /* userData */);
void *
  iluhttp_Resource__GetUserData (iluhttp_Resource /* self */);

extern iluhttp_Resource
  iluhttp_Resource__CreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* ... using default iluhttp_Resource class */

extern iluhttp_Resource
  iluhttp_Resource__OTCreateTrue (ilu_string /* instance-handle */,
	ILU_C_Server /* server */, void * /* user data */);
/* only for use within an object table's `ot_object_of_ih' method */

/*------- methods of the default class -------*/

extern iluhttp_Response* server_iluhttp_Resource_GET (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern iluhttp_Response* server_iluhttp_Resource_HEAD (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern iluhttp_Response* server_iluhttp_Resource_POST (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern void iluhttp_Resource__SetDefaultClassFinalization(ILU_C_FinalizationProc f);

extern ILU_C_Class iluhttp_Resource__SetDefaultClass(ILU_C_Class);

extern ILU_C_Class iluhttp_Resource__MakeClass(
  iluhttp_Response* (*iluhttp_Resource_GET__Impl)
     (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_HEAD__Impl)
     (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  iluhttp_Response* (*iluhttp_Resource_POST__Impl)
     (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status),
  ILU_C_FinalizationProc _finalize);

/*------- generic functions --------------------------------------------*/

extern iluhttp_Response*
  iluhttp_Resource_GET (iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *);

extern iluhttp_Response*
  iluhttp_Resource_HEAD (iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *);

extern iluhttp_Response*
  iluhttp_Resource_POST (iluhttp_Resource, iluhttp_Request*, ILU_C_ENVIRONMENT *);






/*======================================================================*/
/*================= miscellaneous internal declarations ================*/
/*======================================================================*/
/*================= Humans never have to read this stuff ===============*/
/*======================================================================*/


extern void iluhttp__BindExceptionValue (ILU_C_ENVIRONMENT *, ilu_Exception, ...);

extern void _iluhttp_CatchException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_cardinal);
extern void _iluhttp_SendException (ilu_Call, ILU_C_ENVIRONMENT *, ilu_Error *);

extern struct _ILU_C_IoFnsRegistration_s _iluhttp_Resource__IoFns;
#define TC_iluhttp_Resource (& _iluhttp_Resource__IoFns)
extern void iluhttp_Resource__Free (iluhttp_Resource*);
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_Response__IoFns;
#define TC_iluhttp_Response (& _iluhttp_Response__IoFns)
extern void _iluhttp_Response__Output (ilu_Call, iluhttp_Response*, ilu_Error *);
extern ilu_cardinal _iluhttp_Response__SizeOf (ilu_Call, iluhttp_Response*, ilu_Error *);
extern iluhttp_Response* _iluhttp_Response__Input (ilu_Call, iluhttp_Response*, ilu_Error *);
extern void iluhttp_Response__Free (iluhttp_Response*);
iluhttp_Response* iluhttp_Response__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_StatusCode__IoFns;
#define TC_iluhttp_StatusCode (& _iluhttp_StatusCode__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_Request__IoFns;
#define TC_iluhttp_Request (& _iluhttp_Request__IoFns)
extern void _iluhttp_Request__Output (ilu_Call, iluhttp_Request*, ilu_Error *);
extern ilu_cardinal _iluhttp_Request__SizeOf (ilu_Call, iluhttp_Request*, ilu_Error *);
extern iluhttp_Request* _iluhttp_Request__Input (ilu_Call, iluhttp_Request*, ilu_Error *);
extern void iluhttp_Request__Free (iluhttp_Request*);
iluhttp_Request* iluhttp_Request__alloc (void);
#define _iluhttp_RequestURI__IoFns _ilu_CString__IoFns
#define TC_iluhttp_RequestURI (& _iluhttp_RequestURI__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_OptionalEntityBody__IoFns;
#define TC_iluhttp_OptionalEntityBody (& _iluhttp_OptionalEntityBody__IoFns)
extern void _iluhttp_OptionalEntityBody__Output (ilu_Call, iluhttp_OptionalEntityBody, ilu_Error *);
extern ilu_cardinal _iluhttp_OptionalEntityBody__SizeOf (ilu_Call, iluhttp_OptionalEntityBody, ilu_Error *);
extern iluhttp_OptionalEntityBody* _iluhttp_OptionalEntityBody__Input (ilu_Call, iluhttp_OptionalEntityBody*, ilu_Error *);
extern void iluhttp_OptionalEntityBody__Free (iluhttp_OptionalEntityBody*);
iluhttp_OptionalEntityBody* iluhttp_OptionalEntityBody__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_EntityBody__IoFns;
#define TC_iluhttp_EntityBody (& _iluhttp_EntityBody__IoFns)
extern void _iluhttp_EntityBody__Output (ilu_Call, iluhttp_EntityBody*, ilu_Error *);
extern ilu_cardinal _iluhttp_EntityBody__SizeOf (ilu_Call, iluhttp_EntityBody*, ilu_Error *);
extern iluhttp_EntityBody* _iluhttp_EntityBody__Input (ilu_Call, iluhttp_EntityBody*, ilu_Error *);
extern void iluhttp_EntityBody__Free (iluhttp_EntityBody*);
iluhttp_EntityBody* iluhttp_EntityBody__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_HTTPHeaders__IoFns;
#define TC_iluhttp_HTTPHeaders (& _iluhttp_HTTPHeaders__IoFns)
extern void _iluhttp_HTTPHeaders__Output (ilu_Call, iluhttp_HTTPHeaders*, ilu_Error *);
extern ilu_cardinal _iluhttp_HTTPHeaders__SizeOf (ilu_Call, iluhttp_HTTPHeaders*, ilu_Error *);
extern iluhttp_HTTPHeaders* _iluhttp_HTTPHeaders__Input (ilu_Call, iluhttp_HTTPHeaders*, ilu_Error *);
extern void iluhttp_HTTPHeaders__Free (iluhttp_HTTPHeaders*);
iluhttp_HTTPHeaders* iluhttp_HTTPHeaders__alloc (void);
#define _iluhttp_HTTPHeader__IoFns _iluhttp_Header__IoFns
#define TC_iluhttp_HTTPHeader (& _iluhttp_HTTPHeader__IoFns)
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_Header__IoFns;
#define TC_iluhttp_Header (& _iluhttp_Header__IoFns)
extern void _iluhttp_Header__Output (ilu_Call, iluhttp_Header*, ilu_Error *);
extern ilu_cardinal _iluhttp_Header__SizeOf (ilu_Call, iluhttp_Header*, ilu_Error *);
extern iluhttp_Header* _iluhttp_Header__Input (ilu_Call, iluhttp_Header*, ilu_Error *);
extern void iluhttp_Header__Free (iluhttp_Header*);
iluhttp_Header* iluhttp_Header__alloc (void);
extern struct _ILU_C_IoFnsRegistration_s _iluhttp_optional_field_value__IoFns;
#define TC_iluhttp_optional_field_value (& _iluhttp_optional_field_value__IoFns)
extern void _iluhttp_optional_field_value__Output (ilu_Call, iluhttp_optional_field_value, ilu_Error *);
extern ilu_cardinal _iluhttp_optional_field_value__SizeOf (ilu_Call, iluhttp_optional_field_value, ilu_Error *);
extern iluhttp_optional_field_value* _iluhttp_optional_field_value__Input (ilu_Call, iluhttp_optional_field_value*, ilu_Error *);
extern void iluhttp_optional_field_value__Free (iluhttp_optional_field_value*);
iluhttp_optional_field_value* iluhttp_optional_field_value__alloc (void);
#define _iluhttp_field_value__IoFns _ilu_CString__IoFns
#define TC_iluhttp_field_value (& _iluhttp_field_value__IoFns)
#define _iluhttp_field_name__IoFns _ilu_CString__IoFns
#define TC_iluhttp_field_name (& _iluhttp_field_name__IoFns)

extern ilu_Class _iluhttp_Resource__ILUType;
extern iluhttp_Response* _iluhttp_Resource_GET__clientstub (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);
extern iluhttp_Response* _iluhttp_Resource_HEAD__clientstub (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);
extern iluhttp_Response* _iluhttp_Resource_POST__clientstub (iluhttp_Resource _handle, iluhttp_Request* request, ILU_C_ENVIRONMENT *_status);

extern void _iluhttp__GeneralInitialization(void);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __iluhttp_h_ */
