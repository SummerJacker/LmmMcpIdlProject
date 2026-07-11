#!/usr/bin/env iluguile
!#
;; $Id: client.scm,v 1.4 2025/06/22 07:50:10 cvswxc Exp $
;; $Log: client.scm,v $
;; Revision 1.4  2025/06/22 07:50:10  cvswxc
;; #681 remove old infor
;; Committed on the Free edition of March Hare Software CVSNT Server.
;; Upgrade to CVS Suite for more features and support:
;; http://march-hare.com/cvsnt/
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
