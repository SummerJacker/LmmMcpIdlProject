(* $Id: iluhttp.isl,v 2.0 2014/04/15 08:53:39 cvsczh Exp $ *)


(* 
   ILU Http Ilu_Http_1_1_resource_object ISL

	This is a modification of the Proposed ILU-Requester interface 
	 (a CGI alternative) by Digital Creations info@digicool.com
	 Reference: https://www.rfc-editor.org/rfc/rfc9110.txt
			
*)

INTERFACE iluhttp;


(* -------------------- Header related Types ------------------------- *)

TYPE field-name = ilu.CString;
TYPE field-value = ilu.CString;
TYPE optional-field-value = OPTIONAL field-value;
TYPE Header = RECORD			(* message header *)
  name  : field-name,
  value : optional-field-value
END;
TYPE HTTPHeader = Header;
TYPE HTTPHeaders = SEQUENCE of HTTPHeader;

(* -------------------- Entity Body related Types -------------------- *)

TYPE EntityBody = SEQUENCE of BYTE;
TYPE OptionalEntityBody = OPTIONAL EntityBody;

(* -------------------- Request URI related Types -------------------- *)

TYPE RequestURI = ilu.CString;

(* -------------------- Full Request Types --------------------------- *)

TYPE Request = RECORD		(* 'mostly' a http full request *)

  URI     : RequestURI,	(* This can be the absoluteURI or abs_path uri - including params, 
			   queries, etc. (if it's the full absoluteURI or abs_path, then the 
			   scheme, netpath, and path portion of this should be http:, 
			   the netpath should agree with the server id, and the path the 
			   same as the object ID although this isn't checked), 
			   OR more commonly it can be just the params, queries, e.g. ;foo;bar?zap *)

  headers : HTTPHeaders,(* The general, request and entity headers NOTE: if the user 
			   didn't supply a Content-Length header, ilu's http 
			   will automatically put in a Content-Length header if an
			   Entity body is supplied. Note that when responding to a 
			   HEAD method then (since there is no body) the user should 
			   supply a Content-Length header. *)

  body    : OptionalEntityBody
			(* may or may not be some body in a request *)
  END;



(* -------------------- Response related Types ----------------------- *)

TYPE StatusCode = ENUMERATION  	(* some possible status return codes *)
        Continue = 100,
        SwitchingProtocols = 101,
	OK = 200,
	Created = 201,
	Accepted = 202,
	NonAuthoritativeInformation = 203,
	NoContent = 204,
	ResetContent = 205,
	PartialContent = 206,		
	MultipleChoices = 300,
	MovedPermanently = 301,
	Found = 302,
	SeeOther = 303,
	NotModified = 304,
	UseProxy = 305,
	(* Unused = 306,  Unused is not used but 306 is reeserved *)
	TemporaryRedirect = 307,
	PermanentRedirect = 308,		
	BadRequest = 400,
	Unauthorized = 401,
	PaymentRequired = 402, (* reserved for future use *)
	Forbidden = 403,
	NotFound = 404,
	MethodNotAllowed = 405,
	NotAcceptable = 406,
	ProxyAuthenticatoinRequired = 407,
	RequestTimeout = 408,
	Conflict = 409,
	Gone = 410, 
	LengthRequired = 411, 
	PreconditionFailed = 412,
	ContentTooLarge = 413,
	URITooLong = 414,
	UnsupportedMediaType = 415,
	RangeNotSatisfiable = 416,
	ExpectationFailed = 417,
	Unused = 418,
	MisdiectedRequest = 421,
	UnprocessableConent = 422, 
	UpgradeReqired = 426,			
	InternalServerError = 500,
	NotImplemented = 501,
	BadGateway = 502,
	ServiceUnavailable = 503,
	GatewayTimeout = 504,
	HTTPVersionNotSupported = 505
END;

TYPE Response = RECORD		(* a http full response *)

  status  : StatusCode,		(* status of servicing the request *)

  headers : HTTPHeaders,	(* the general, response and entity headers *)

  body    : OptionalEntityBody	(* may or may not be some body in a response *)
END;


(* -------------------- Resource Object ------------------------------ *)

TYPE Resource = OBJECT		(* the object that knows the standard http methods *)

  (* NOTE the following TYPEID MUST AGREE with the definition
     of HTTP_RESOURCE_OBJECT_TYPE_ID in the file
     src/runtime/kernel/httpprot.h *)
  TYPEID "ilu:Ilu_Http_1_1_resource_object"

  METHODS	(* the standard http 1.1 methods *)

    GET  (request: Request) : Response,	
    HEAD (request: Request) : Response,  
    POST (request: Request) : Response 

END;


(* ------------------------------------------------------------------- *)
(* -------------------- end of file ---------------------------------- *)
(* ------------------------------------------------------------------- *)

