(* $Id: ianacharsets.isl,v 1.4 2025/08/01 05:29:37 cvswxc Exp $ *)

(* ************************************************************************ *)
(*
    Version 1.3 ISL for HTTP-NG, Dan Larner, 3-19-98

    This work is very preliminary - Comments welcomed and encouraged!
    'xxx' marks areas where thought is definitly needed
    Please send comments, suggestions, contributions, etc. to the http-ng 
    mailing list, w3c-http-ng@w3.org and/or to larner@parc.xerox.com.

*)

(* ************************************************************************ *)
(* *************************** IANA Charsets ****************************** *)
(* ************************************************************************ *)

(* Defines standard charsets.        *)


Interface IANA-Charsets-Registry Brand "NG" ;


Type CharsetMIBEnumValue = Short Cardinal;

Type CharsetMIBEnumValueSequence = Sequence Of CharsetMIBEnumValue;  

Type OptionalCharsetMIBEnumValue = Optional CharsetMIBEnumValue;  

Constant US-ASCII : CharsetMIBEnumValue = 3;
  
(* XXX need to complete the list *)


(* ************************************************************************ *)
(* ******************************** END *********************************** *)
(* ************************************************************************ *)
