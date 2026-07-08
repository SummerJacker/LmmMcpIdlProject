(* $Id: ChgUp.isl,v 1.4 2025/08/01 00:23:11 cvswxc Exp $  *)

(* Last edited by Mike Spreitzer October 8, 1998 10:37 pm PDT *)
(* $Log: ChgUp.isl,v $
(* Revision 1.4  2025/08/01 00:23:11  cvswxc
(* #681 remove the big ILU formating infor
(* Committed on the Free edition of March Hare Software CVSNT Server.
(* Upgrade to CVS Suite for more features and support:
(* http://march-hare.com/cvsnt/
(*
(* Revision 1.3  2018/08/13 08:13:55  cvswxc
(* 第一次标准化建立文件版本管理格式
(* *)




INTERFACE ChgUp;


TYPE T = OBJECT
  
METHODS
    
GetBrother(): T,
    
GetGeneration(): CARDINAL
  
END;

