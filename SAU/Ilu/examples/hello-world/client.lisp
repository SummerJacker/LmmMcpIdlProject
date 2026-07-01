;;;-*- Package: USER; Syntax: Common-Lisp; Mode: Lisp; Base: 10 -*-
;;; Last edited by Mike Spreitzer October 8, 1998 10:58 pm PDT
#|
 $Id: client.lisp,v 1.4 2025/06/22 07:49:24 cvswxc Exp $
 $Log: client.lisp,v $
 Revision 1.4  2025/06/22 07:49:24  cvswxc
 #681 remove old infor
 Committed on the Free edition of March Hare Software CVSNT Server.
 Upgrade to CVS Suite for more features and support:
 http://march-hare.com/cvsnt/
 
|#

(cl:in-package :user)

(defun main(sbh)
  (let ((server (ilu:sbh->instance 'hello-world:service sbh)))
    (if (not server)
	(error "Can't create object from SBH <~a>~%" sbh)
      (progn
	(let ((response (hello-world:service.hello-world server)))
	  (format t "~a~%" response))))))
