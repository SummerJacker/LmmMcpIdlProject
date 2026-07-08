#!/usr/bin/env iluguile
!#
;; $Id: client.scm,v 1.5 2025/07/28 09:09:22 cvswxc Exp $
;; 

(require "hello-world")

(define (main argv)
  (ilu:init)
  (let ((sbh (list-ref argv 2))
	(class hello-world:service:class-record))
    (let ((theObject (ilu:sbh-to-object sbh class))
	  (status-param (make-hello-world:status)))
      (if (not theObject)
	  (error "Unable to import hello-world service with SBH <~a>~%" sbh))
      (let ((response (hello-world theObject status-param)))
	(if (get-return-code status-param)
	    (format #t "(hello-world theObject) fails with exception <~a>~%"
		    (get-return-code status-param))
	    (format #t "~a~%" response))))))

(main (command-line))
