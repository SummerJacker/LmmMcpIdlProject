(* $Id: testJavaSerialObjects.isl,v 1.4 2025/08/07 08:37:30 cvswxc Exp $ *)


INTERFACE testJavaSerialObjects IMPORTS ilujava END;

(* For the test and demo program *) 


TYPE ObjectGetter =
  OBJECT 
    METHODS
      GetIt(): ilujava.JavaObject
    END;
