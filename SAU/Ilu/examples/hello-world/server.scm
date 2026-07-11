#!/usr/bin/env iluguile
!#
;; $Id: server.scm,v 1.4 2025/06/22 07:54:32 cvswxc Exp $
;; $Log: server.scm,v $
;; Revision 1.4  2025/06/22 07:54:32  cvswxc
;; #681 remove old infor
;; Committed on the Free edition of March Hare Software CVSNT Server.
;; Upgrade to CVS Suite for more features and support:
;; http://march-hare.com/cvsnt/
;; 

(require "hello-world")
(require "hello-world-server-stubs")

(define (make-hello-world:service-impl server)
  (ilu-object-with-ancestors
   ((hello-world:service (make-hello-world:service)))
   ((get-server this) server)
   ((hello-world hello-world:service-impl . status-only)
    (ilu-bind-arguments
     (status-only status)
     (set-return-code status hello-world:reply-success)
     "\"Hello, World!\" from Guile Scheme"))))

(define (main argv)
  (let ((theServer #f)
	(theObject #f))

    (ilu:init)

    (set! theServer (ilu-server:create #f #f))
    (ilu-server:add-port theServer #f #f #t)

    (let ((theObject (make-hello-world:service-impl theServer)))
      (if theObject
	  (begin
	    (format #t "hello world server is ~a~&" (string-binding-handle theObject))
	    (ilu:run-main-loop (ilu:make-main-loop-id)))
	  (error "could not create object"))
      )))

(main (command-line))
