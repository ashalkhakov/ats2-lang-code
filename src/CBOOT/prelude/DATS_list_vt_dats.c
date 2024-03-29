/*
**
** The C code is generated by ATS/Anairiats
** The compilation time is: 2013-9-2: 20h:48m
**
*/

/* include some .h files */
#ifndef _ATS_HEADER_NONE
#include "ats_config.h"
#include "ats_basics.h"
#include "ats_types.h"
#include "ats_exception.h"
#include "ats_memory.h"
#endif /* _ATS_HEADER_NONE */

/* include some .cats files */
#ifndef _ATS_PRELUDE_NONE
#include "prelude/CATS/basics.cats"
#include "prelude/CATS/bool.cats"
#include "prelude/CATS/char.cats"
#include "prelude/CATS/byte.cats"
#include "prelude/CATS/float.cats"
#include "prelude/CATS/integer.cats"
#include "prelude/CATS/integer_ptr.cats"
#include "prelude/CATS/integer_fixed.cats"
#include "prelude/CATS/sizetype.cats"
#include "prelude/CATS/pointer.cats"
#include "prelude/CATS/reference.cats"
#include "prelude/CATS/string.cats"
#include "prelude/CATS/lazy.cats"
#include "prelude/CATS/lazy_vt.cats"
#include "prelude/CATS/printf.cats"
#include "prelude/CATS/list.cats"
#include "prelude/CATS/option.cats"
#include "prelude/CATS/array.cats"
#include "prelude/CATS/matrix.cats"
#endif /* _ATS_PRELUDE_NONE */
/* prologues from statically loaded files */

#include "libc/CATS/stdlib.cats"

#include "libc/CATS/fcntl.cats"

#include "libc/sys/CATS/types.cats"
/* external codes at top */
/* type definitions */
/* external typedefs */
/* external dynamic constructor declarations */
/* external dynamic constant declarations */
ATSextern_fun(ats_bool_type, atspre_lte_int_int) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_iadd) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_isub) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_idiv) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_ilt) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_igt) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_igte) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_size1_of_int1) (ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_sub_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_gt_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_ptr_type, atspre_array_ptr_alloc_tsz) (ats_size_type, ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_array_ptr_free) (ats_ptr_type) ;
ATSextern_fun(ats_void_type, atslib_qsort) (ats_ref_type, ats_size_type, ats_size_type, ats_ptr_type) ;

/* external dynamic terminating constant declarations */
#ifdef _ATS_PROOFCHECK
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
#endif /* _ATS_PROOFCHECK */

/* assuming abstract types */
/* sum constructor declarations */
/* exn constructor declarations */
/* global dynamic (non-functional) constant declarations */
/* internal function declarations */

/* partial value template declarations */
/* static temporary variable declarations */
/* external value variable declarations */

/* function implementations */

#ifdef _ATS_PROOFCHECK
/*
// /home/hwxi/research/Anairiats/prelude/DATS/list_vt.dats: 1743(line=51, offs=1) -- 1869(line=54, offs=4)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative_prfck () {
/* local vardec */
// ATSlocal_void (tmp0) ;

ats_proofcheck_beg_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative) ;
ats_proofcheck_end_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative) ;
return /* (tmp0) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative_prfck] */
#endif /* _ATS_PROOFCHECK */

/* static load function */

// extern ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__staload (void) ;
// extern ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2unsafe_2esats__staload (void) ;
extern ats_void_type ATS_2d0_2e2_2e10_2libc_2SATS_2stdlib_2esats__staload (void) ;

ats_void_type
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__staload () {
static int ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__staload_flag = 0 ;
if (ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__staload_flag) return ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__staload_flag = 1 ;

// ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__staload () ;
// ATS_2d0_2e2_2e10_2prelude_2SATS_2unsafe_2esats__staload () ;
ATS_2d0_2e2_2e10_2libc_2SATS_2stdlib_2esats__staload () ;

return ;
} /* staload function */

/* dynamic load function */

// dynload flag declaration
// extern ats_int_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__dynload_flag ;

ats_void_type
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__dynload () {
// ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__dynload_flag = 1 ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats__staload () ;

#ifdef _ATS_PROOFCHECK
ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
#endif /* _ATS_PROOFCHECK */

/* marking static variables for GC */

/* marking external values for GC */

/* code for dynamic loading */
return ;
} /* end of [dynload function] */

/* external codes at mid */
/* external codes at bot */

/* ****** ****** */

/* end of [DATS_list_vt_dats.c] */
