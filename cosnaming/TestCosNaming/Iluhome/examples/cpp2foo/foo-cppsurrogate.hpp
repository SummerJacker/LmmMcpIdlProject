

// This file was automatically generated with  KISORB (version 2.0beta1) tools
// KIS-CORBA is Copyright 2006-2056 成都凯斯人工智能研究院, All Rights Reserved.
// KIS-CORBA information:  Dr. Wang at xcwang89@aliyun.com 

#ifndef __foo_cppsurrogate_H_
#define __foo_cppsurrogate_H_

#include "foo-cpp.hpp"

#ifndef CORBA_
#define CORBA_(name) NAME_INSIDE_SCOPE(CORBA,name)
#endif
#ifndef CORBA
#define CORBA(name) NAME_OUTSIDE_SCOPE(CORBA,name)
#endif
#ifndef foo_surrogate_
#define foo_surrogate_(name) NAME_INSIDE_SCOPE(foo_surrogate,name)
#endif
#ifndef foo_surrogate
#define foo_surrogate(name) NAME_OUTSIDE_SCOPE(foo_surrogate,name)
#endif

 // start the scope for foo_surrogate 
  class foo_surrogate_bar :public virtual foo_bar {
    public:

     //ISL specified methods


      virtual CORBA_Boolean 
         zap(
             CORBA_Long  inarg,
             CORBA_Octet&  inoutarg,
             CORBA_Double&  outarg
             ) throw (CORBA_SystemException, foo_zapexception);

      virtual foo_bar_ptr 
         passobj(
             foo_bar_ptr  inarg,
             foo_bar_ptr&  inoutarg,
             foo_bar_ptr&  outarg
             ) throw (CORBA_SystemException);

      virtual foo_enumtype 
         passenum(
             foo_enumtype  inarg,
             foo_enumtype&  inoutarg,
             foo_enumtype&  outarg
             ) throw (CORBA_SystemException);

      virtual iluShortCharacter* 
         passlatinstring(
             foo_const_LatinString    inarg,
             iluShortCharacter*&  inoutarg,
             iluShortCharacter*&  outarg
             ) throw (CORBA_SystemException);

      virtual iluCharacter* 
         passunicodestring(
             foo_const_UnicodeString    inarg,
             iluCharacter*&  inoutarg,
             iluCharacter*&  outarg
             ) throw (CORBA_SystemException);

      virtual foo_fixedrecordtype 
         passfixedrecord(
             const foo_fixedrecordtype&  inarg,
             foo_fixedrecordtype&  inoutarg,
             foo_fixedrecordtype&  outarg
             ) throw (CORBA_SystemException);

      virtual foo_variablerecordtype* 
         passvariablerecord(
             const foo_variablerecordtype&  inarg,
             foo_variablerecordtype&  inoutarg,
             foo_variablerecordtype*&  outarg
             ) throw (CORBA_SystemException);

      virtual foo_integerarray_slice* 
         passfixedarray(
             const foo_integerarray  inarg,
             foo_integerarray  inoutarg,
             foo_integerarray  outarg
             ) throw (CORBA_SystemException);

      virtual foo_bararray_slice* 
         passvariablearray(
             const foo_bararray  inarg,
             foo_bararray  inoutarg,
             foo_bararray_slice*&  outarg
             ) throw (CORBA_SystemException);

      virtual foo_unboundedlongseq* 
         passunboundedsequence(
             const foo_unboundedlongseq&  inarg,
             foo_unboundedlongseq&  inoutarg,
             foo_unboundedlongseq*&  outarg
             ) throw (CORBA_SystemException);

      virtual foo_boundedbarseq* 
         passboundedsequence(
             const foo_boundedbarseq&  inarg,
             foo_boundedbarseq&  inoutarg,
             foo_boundedbarseq*&  outarg
             ) throw (CORBA_SystemException);

      virtual foo_variableuniontype* 
         passvariableunion(
             const foo_variableuniontype&  inarg,
             foo_variableuniontype&  inoutarg,
             foo_variableuniontype*&  outarg
             ) throw (CORBA_SystemException);

      virtual CORBA_Long* 
         passoptionals(
             foo_const_optionalinteger    inarg,
             foo_optionalbarobject&  inoutarg,
             foo_optionalbarobject&  outarg
             ) throw (CORBA_SystemException);

      virtual CORBA_Any* 
         passsimpleanys(
             const CORBA_Any&  inarg,
             CORBA_Any&  inoutarg,
             CORBA_Any*&  outarg
             ) throw (CORBA_SystemException);

      virtual CORBA_Any* 
         passarrayanys(
             const CORBA_Any&  inarg,
             CORBA_Any&  inoutarg,
             CORBA_Any*&  outarg
             ) throw (CORBA_SystemException);

      virtual CORBA_Any* 
         passassortedanys(
             const CORBA_Any&  inarg,
             CORBA_Any&  inoutarg,
             CORBA_Any*&  outarg
             ) throw (CORBA_SystemException);

      // Initialize this class

      static void iluInitialize();

      // Function to create a surrogate for a foo_bar object

      static iluObject* create_surrogate(iluKernelObject);

      virtual void * iluDowncast(iluClass class_to_cast_down_to) {
             return foo_bar::iluDowncast_super(this, class_to_cast_down_to);
 };

    private:

      // Exception forwarding (if any)

 
      static void _throw_zap_exception
          (iluCardinal exception_index, iluSurrogateCall&)
          throw (CORBA_SystemException, foo_zapexception);

      static int _initialized;

  };

  // class initializer
  class foo_surrogate_bar_initializer {
    public:
      foo_surrogate_bar_initializer ();
      void * ensure_instantiation ();
      static foo_surrogate_bar_initializer sm_the_surrogate_foo_bar_initializer;
  };
 
// end the scope for foo_surrogate 
 
#endif
