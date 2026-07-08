(* $Id: iluhttp.isl,v 1.5 2025/08/01 05:29:37 cvswxc Exp $ *)


(* 
   ILU Http Ilu_Http_1_0_resource_object ISL
		This is a modification of the Proposed ILU-Requester interface 
			(a CGI alternative) by Digital Creations info@digicool.com
			Reference: http://www.w3.org/pub/WWW/Protocols/HTTP1.0/draft-ietf-http-spec.html
			
*)

INTERFACE iluhttp;


(* -------------------- Header related Types ------------------------- *)

TYPE field-name = ilu.CString;						(* a header field-name *)

TYPE field-value = ilu.CString;						(* a header field-value *)

TYPE optional-field-value = OPTIONAL field-value;	(* field values are optional *)

TYPE Header = RECORD								(* message header *)
	name  : field-name,
	value : optional-field-value
  END;

TYPE HTTPHeader = Header;

TYPE HTTPHeaders = SEQUENCE of HTTPHeader;			(* all the headers *)



(* -------------------- Entity Body related Types -------------------- *)

TYPE EntityBody = SEQUENCE of BYTE;					(* the entity body *)

TYPE OptionalEntityBody = OPTIONAL EntityBody;		(* entity bodies are optional *)



(* -------------------- Request URI related Types -------------------- *)

TYPE RequestURI = ilu.CString;


(* -------------------- Full Request Types --------------------------- *)

TYPE Request = RECORD					(* 'mostly' a http full request *)

	URI     : RequestURI,				(* This can be the absoluteURI or abs_path uri - including params, 
										   queries, etc. (if it's the full absoluteURI or abs_path, then the 
										   scheme, netpath, and path portion of this should be http:, 
										   the netpath should agree with the server id, and the path the 
										   same as the object ID although this isn't checked), 
										   OR more commonly it can be just the params, queries, e.g. ;foo;bar?zap *)

	headers : HTTPHeaders,				(* the general, request and entity headers NOTE: if the user 
										   didn't supply a Content-Length header, ilu's http 
										   will automatically put in a Content-Length header if an
										   Entity body is supplied. Note that when responding to a 
										   HEAD method then (since there is no body) the user should 
										   supply a Content-Length header. *)

	body    : OptionalEntityBody		(* may or may not be some body in a request *)

  END;



(* -------------------- Response related Types ----------------------- *)

TYPE StatusCode = ENUMERATION			(* some possible status return codes *)
	OK = 200,
	Created = 201,
	Accepted = 202,
	NoContent = 204,
	MovedPermanently = 301,
	MovedTemporarily = 302,
	NotModified = 304,
	BadRequest = 400,
	Unauthorized = 401,
	Forbidden = 403,
	NotFound = 404,
	InternalError = 500,
	NotImplemented = 501,
	BadGateway = 502,
	ServiceUnavailable = 503
  END;


TYPE Response = RECORD					(* a http full response *)

	status  : StatusCode,				(* status of servicing the request *)

	headers : HTTPHeaders,				(* the general, response and entity headers *)

	body    : OptionalEntityBody		(* may or may not be some body in a response *)
END;


(* -------------------- Resource Object ------------------------------ *)

TYPE Resource = OBJECT					(* the object that knows the standard http methods *)
  (* NOTE the following TYPEID MUST AGREE with the definition of HTTP_RESOURCE_OBJECT_TYPE_ID
     in the file src/runtime/kernel/httpprot.h *)
  TYPEID "ilu:Ilu_Http_1_0_resource_object"

  METHODS	(* the standard http 1.0 methods, each taking a request and returning a response *)

	GET  (request: Request) : Response,	
	HEAD (request: Request) : Response,  
	POST (request: Request) : Response

  END;


(* ------------------------------------------------------------------- *)
(* -------------------- end of file ---------------------------------- *)
(* ------------------------------------------------------------------- *)

