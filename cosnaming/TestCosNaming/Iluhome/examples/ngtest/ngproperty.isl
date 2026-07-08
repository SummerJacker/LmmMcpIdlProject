(* $Id: ngproperty.isl,v 1.4 2025/08/01 05:29:37 cvswxc Exp $ *)

(* ************************************************************************ *)
(* ************************************************************************ *)
(*
    Version 1.3 ISL for HTTP-NG, Dan Larner, 3-19-98

    This work is very preliminary - Comments welcomed and encouraged!
    'xxx' marks areas where thought is definitly needed
    Please send comments, suggestions, contributions, etc. to the http-ng 
    mailing list, w3c-http-ng@w3.org and/or to larner@parc.xerox.com.

*)

(* ************************************************************************ *)
(* *************************** Properties ********************************* *)
(* ************************************************************************ *)

(* 
A PropertySet object contains a list of name value pairs.  
In the Web for example, a WebDocument would inherit from PropertySet
so that various attributes (e.g. last modification time, authors, etc.)
could be accessed.

*)

Interface NgProperty Brand "NG" Imports
    NgBasic From ngbasic.isl
    End;


(* ************************************************************************ *)
(* ************************ Property Value Pairs ************************** *)

(* a property is simply a named attribute paired with some value *)

Type Property = NgBasic.NameValuePair;
    
Type PropertySequence = Sequence Of Property;
Type PropertyNames    = NgBasic.NameSequence;


(* ************************************************************************ *)
(* ******************************** Exceptions **************************** *)

(* doesn't know these properties *)
Exception UnknownPropertyNames : PropertyNames ;



(* ************************************************************************ *)
(* *************************** Property Set Object ************************ *)

Type PropertySet = Object

    Supertypes NgBasic.NgObject End

    Methods

    (* GetProperties returns a Set of the requested named 'Properties' and 
       their values.  Sending an empty sequence of propertiesToGet is 
       equivalent to saying send all the properties. *)
      
    GetProperties ( propertiesToGet : PropertyNames ) : PropertySequence
        Raises UnknownPropertyNames, NgBasic.WouldBlock, 
        NgBasic.ObjectNotExist End  
                          
End;


(* ************************************************************************ *)
(* *********************** Putable Property Set Object ******************** *)


(* PropertyModification Records are used when modifying property sets *)
Type PropertyModificationKind = Enumeration Add, Remove, Change End;

Type PropertyModification = Record

    propertyName : NgBasic.String,
    
    modification : PropertyModificationKind,
    
    (* present when modification is Add or Change *)
    value        : NgBasic.OptionalPickle 
End;

Type PropertyModificationSequence = Sequence Of PropertyModification;


Type PutablePropertySet = Object

    Supertypes PropertySet End

    Methods
        
    (* PutProperties sends a Set of the requested modifications.
       Properties are added, removed and changed per the modification records.
       If an exception is raised, no modifictions will have been made to the 
       PropertySet.
       *)
      
    PutProperties ( propertiesToSet : PropertyModificationSequence )
        Raises UnknownPropertyNames, NgBasic.WouldBlock, NgBasic.Conflict,
         NgBasic.ObjectNotExist End    
                  
End;


(* ************************************************************************ *)
(* ******************************** END *********************************** *)
(* ************************************************************************ *)
