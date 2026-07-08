#!/usr/bin/env iluguile
!#
;; $Id: server.scm,v 1.5 2025/07/28 09:09:22 cvswxc Exp $
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
