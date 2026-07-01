;;;-*- Package: TEST1-SERVER; Syntax: Common-Lisp; Mode: Lisp; Base: 10 -*-
;;; Last edited by Mike Spreitzer October 8, 1998 11:02 pm PDT
#|
 $Id: server.lisp,v 1.4 2025/06/22 07:52:22 cvswxc Exp $
 $Log: server.lisp,v $
 Revision 1.4  2025/06/22 07:52:22  cvswxc
 #681 remove old infor
 Committed on the Free edition of March Hare Software CVSNT Server.
 Upgrade to CVS Suite for more features and support:
 http://march-hare.com/cvsnt/

|#

(cl:defpackage :hello-world-server
  (:use :common-lisp :ilu)
  (:export #:main))

(cl:in-package :hello-world-server)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;
;;;  hello-world.service
;;;
(defclass hello-world-service (hello-world:service.impl) ())

(defmethod hello-world:service.hello-world ((self hello-world-service))
  "\"Hello, World!\" from Common Lisp")

(defun main ()
  (let* ((theServer (make-instance 'ilu:kernel-server))
	 (theObject (make-instance 'hello-world-service
		      :ilu-kernel-server theServer)))
    (format t "hello world server is ~a~%" (ilu:string-binding-handle theObject))
    theObject))
