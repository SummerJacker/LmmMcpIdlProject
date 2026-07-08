(* $Id: ngform.isl,v 1.4 2025/08/01 05:29:37 cvswxc Exp $ *)

(* ************************************************************************ *)
(*
    Version 1.3 ISL for HTTP-NG, Dan Larner, 3-19-98

    This work is very preliminary - Comments welcomed and encouraged!
    'xxx' marks areas where thought is definitly needed
    Please send comments, suggestions, contributions, etc. to the http-ng
    mailing list, w3c-http-ng@w3.org and/or to larner@parc.xerox.com.

*)

(* ************************************************************************ *)
(* *************************** FormProcessors ***************************** *)
(* ************************************************************************ *)

(* An Object of type FormProcessor is able to process Form based input, and 
   produce an appropriate rendering as a response.
*)


Interface NgFormProcessor Brand "NG" Imports 
    NgBasic                From ngbasic.isl,
    IANA-Charsets-Registry From ianacharsets.isl,
    NgCache                From ngcache.isl,    
    NgRendering            From ngrendering.isl
End;



(* ************************************************************************ *)
(* ********************* Form entries  ************************************ *)

(* a Form input element is simply a named form field paired with some value *)

Type FormInputElement = NgBasic.NameValuePair;
    
Type FormInputElementSequence = Sequence Of FormInputElement;
Type FormInputElementNames    = NgBasic.NameSequence;



(* ************************************************************************ *)
(* ******************** FormProcessing Exceptions ************************* *)

(* The listed form inputs has invalid values *)
   
Exception InvalidFormEntries : FormInputElementNames;




(* ************************************************************************ *)
(* ********************** ProcessedFormSink  ****************************** *)


(* a FormProblemReport is used to pass information to asynchronous
   callbacks that would have normally been passed back as an exception 
   from the synchronous version of the same sort of call *)
   
Type FormProblemReport = Union
    invalidEntries : FormInputElementNames,
    conflict       : NgBasic.ExceptionInformation,
    objectNotExist : NgBasic.ExceptionInformation
End;

Type OptionalFormProblemReport = Optional FormProblemReport; 


(* A ProcessedFormSink is basically a NgRendering.RenderingSink
   except that there are some more problems that can be reported *)

Type ProcessedFormSink = Object  

    Supertypes NgRendering.RenderingSink End

    Methods        
        
    (* FormProblem is called when a Form related exception would have been
       raised from calling ProcessForm (with the same args as SendForm) on the 
       FormProcessor object.  This is basically to allow exceptions to be 
       passed back as the result of an async method. report is examined 
       for the same information as the exceptions that would have been raised
       from calling ProcessForm on the FormProcessor object. The calls to 
       the sink are considered Done if this method is called. *)
    Asynchronous FormProblem ( report : FormProblemReport )

End;


(* ************************************************************************ *)
(* *********************** FormProcessor Object *************************** *)

Type FormProcessor = Object  

    Supertypes NgBasic.NgObject End

    Methods
        
    (* ProcessForm - The caller supplies a FormInputElementSequence describing
       the form data.  If the supplied formEntries input is unacceptable (e.g.
       wrong type, etc.) the callee raises the InvalidFormEntries exception 
       which contains a sequence of the names of the entries which were 
       unacceptable, else a Rendering is returned.
    *)

    ProcessForm ( formEntries          : FormInputElementSequence, 
                 out responseCacheInfo : NgCache.OptionalResponseCacheControl ) 
                 : NgRendering.Rendering
        Raises InvalidFormEntries, NgBasic.WouldBlock, NgBasic.Conflict, 
               NgBasic.ObjectNotExist End,


    (* SendFormReply is just like ProcessForm only instead of synchronously 
       returning the Rendering, it sends it asynchronously via a call to the 
       ReceiveFormResult method on the supplied ProcessedFormSink *)

    Asynchronous SendFormReply ( formEntries  : FormInputElementSequence, 
                                 formSink     : ProcessedFormSink ),
                            
                            
    (* A Synchronous version of SendForm. The intent is to allow the 
    caller to simply know that the call was received. *)
    SendFormReplySynched( 
        formEntries     : FormInputElementSequence, 
        formSink        : ProcessedFormSink )                            

End;


(* ************************************************************************ *)
(* ******************************** END *********************************** *)
(* ************************************************************************ *)
