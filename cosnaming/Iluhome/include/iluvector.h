/* $Id: iluvector.h,v 2.1 2025/08/01 00:13:00 cvswxc Exp $ */

#ifndef _ILU_VECTOR_
#define _ILU_VECTOR_

/*L2, Main unconstrained*/

typedef struct ilu_vector_s {
  /*L1 >= {some mutex that protects the vector}*/
  
  ilu_refany *ve_elements;
  ilu_cardinal ve_capacity;
  ilu_cardinal ve_size;
} *ilu_Vector;

/*L1 unconstrained*/
extern ilu_Vector 
_ilu_vector_new(ilu_cardinal capacity,
		ILU_ERRS((no_memory)) *);

/*L1 >= {some mutex that protects the vector}*/

extern void 
_ilu_vector_destroy(ilu_Vector v,
		    void (*f) (ilu_refany));

extern void 
_ilu_vector_add(ilu_Vector v, ilu_refany e,
		ILU_ERRS((no_memory)) *);

extern ilu_boolean 
_ilu_vector_reserve(ilu_Vector v, ilu_cardinal dSize,
		    ILU_ERRS((no_memory)) *);

extern void     _ilu_vector_remove(ilu_Vector v, ilu_refany e);

extern ilu_cardinal _ilu_vector_size(ilu_Vector v);

extern ilu_refany *_ilu_vector_elements(ilu_Vector v);

extern ilu_Vector 
_ilu_vector_copy(ilu_Vector old,
		 ILU_ERRS((no_memory)) *);

extern void
_ilu_vector_assign(ilu_Vector l, ilu_Vector r,
		   ILU_ERRS((no_memory)) *);

extern void 
_ilu_vector_add_if_not_present(ilu_Vector v, ilu_refany e,
			       ILU_ERRS((no_memory)) *);
	
#define VECTOR(a)	((ilu_Vector)(a))

#endif /* _ILU_VECTOR_ */
