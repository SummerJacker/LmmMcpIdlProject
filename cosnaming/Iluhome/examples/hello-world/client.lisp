;;;-*- Package: USER; Syntax: Common-Lisp; Mode: Lisp; Base: 10 -*-
;;; Last edited by Mike Spreitzer October 8, 1998 10:58 pm PDT
#|
 $Id: client.lisp,v 1.5 2025/07/28 09:09:22 cvswxc Exp $
|#

(cl:in-package :user)

(defun main(sbh)
  (let ((server (ilu:sbh->instance 'hello-world:service sbh)))
    (if (not server)
	(error "Can't create object from SBH <~a>~%" sbh)
      (progn
	(let ((response (hello-world:service.hello-world server)))
	  (format t "~a~%" response))))))
