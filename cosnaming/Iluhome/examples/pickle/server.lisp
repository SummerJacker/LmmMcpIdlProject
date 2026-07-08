;;;-*- Package: PICKLE-TEST; Syntax: Common-Lisp; Mode: Lisp; Base: 10 -*-
#|
 $Id: server.lisp,v 1.4 2025/08/01 06:00:22 cvswxc Exp $
|#

(cl:defpackage :pickle-test
  (:use :common-lisp :ilu)
  (:export #:start-server))

(cl:in-package :pickle-test)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;
;;;  pickle-test
;;;
(defclass pickle-test (test2:o1.impl) ())

(defmethod test2:o1.bounce ((self pickle-test) v)
  (format t "type:  ~s     value:  ~s~%" (pickle-type v) (pickle-value
  v))
  v)

(defun start-server ()
  (let* ((ks (make-instance 'ilu:kernel-server :id "pickleServer"))
	 (sv (make-instance 'pickle-test
			    :ilu-kernel-server ks
			    :ilu-instance-handle "pickleObj")))
    (ilu:publish sv)
    (format t "SBH:  ~a~%" (ilu:string-binding-handle sv))
    sv))
