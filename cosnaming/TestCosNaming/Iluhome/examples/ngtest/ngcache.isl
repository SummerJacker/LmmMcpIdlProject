(* $Id: ngcache.isl,v 1.4 2025/08/01 05:29:37 cvswxc Exp $ *)

(* ************************************************************************ *)
(*
    Version 1.3 ISL for HTTP-NG, Dan Larner, 3-19-98

    This work is very preliminary - Comments welcomed and encouraged!
    'xxx' marks areas where thought is definitly needed
    Please send comments, suggestions, contributions, etc. to the http-ng 
    mailing list, w3c-http-ng@w3.org and/or to larner@parc.xerox.com.

*)
(* ************************************************************************ *)

(* ************************************************************************ *)
(* *************************** Caching Control **************************** *)
(* ************************************************************************ *)

(* Caching control provides cache and proxy relevant information that
   may be sent along with requests and responses.  This mostly mimics
   the cache related headers and Cache-Control header values found in 
   HTTP 1.1.  See that specification for the semantics. 
*)



Interface NgCache Brand "NG" Imports 

    NgBasic From ngbasic.isl
    
End;


(* ************************************************************************ *)
(* *************************** Entity tags ******************************** *)

Type EntityTag             = NgBasic.String;
Type OptionalEntityTag     = Optional NgBasic.String;

Type EntityTagSequence     = Sequence Of EntityTag;

Type EntityTagOrDate = Union
    etag   : EntityTag,
    ifdate : NgBasic.AbsoluteTime
End;    


(* ************************************************************************ *)
(* ***************** Request Cache Control ******************************** *)

Type RequestCacheControl = Record

    (* analogous to HTTP Cache-Control header values *)
    noCache         : Boolean,
    noStore         : Boolean,
    noTransform     : Boolean,
    onlyIfCached    : Boolean,
    
    (* analogous to HTTP If-ModifiedSince, If-Match, If-None-Match and
       If-Range headers *)                                      
    ifModifiedSince : NgBasic.OptionalAbsoluteTime,
    ifMatch         : EntityTagSequence,
    ifNoneMatch     : EntityTagSequence,
    ifRange         : EntityTagOrDate

End;

Type OptionalRequestCacheControl = Optional RequestCacheControl;  


(* ************************************************************************ *)
(* ***************** Response Cache Control ******************************* *)

Type ResponseCacheControl = Record
   
    (* analogous to HTTP  Cache-Control header values*)
    okPublic        : Boolean,
    isPrivate       : Boolean,
    noCache         : Boolean,
    noStore         : Boolean,
    noTransform     : Boolean,
    mustRevalidate  : Boolean,
    proxyRevalidate : Boolean,
    maxAge          : NgBasic.OptionalRelativeTime,
    sMaxAge         : NgBasic.OptionalRelativeTime,
    
    (* analogous to HTTP Age, Vary, Etag, Last-Modified and Expires headers *)
    age             : NgBasic.OptionalRelativeTime,
    vary            : NgBasic.StringSequence,
    entityTag       : OptionalEntityTag,
    lastModified    : NgBasic.OptionalAbsoluteTime,
    expires         : NgBasic.OptionalAbsoluteTime
   
End;
   
Type OptionalResponseCacheControl = Optional ResponseCacheControl;


(* ************************************************************************ *)
(* ******************************** END *********************************** *)
(* ************************************************************************ *)
