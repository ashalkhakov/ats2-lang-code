/*
**
** The C code is generated by ATS/Anairiats
** The compilation time is: 2013-9-3: 17h: 1m
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

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "libc/CATS/gmp.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_location.cats"

#include "pats_lexbuf.cats"

#include "pats_location.cats"

#include "pats_location.cats"
/* external codes at top */
/* type definitions */
typedef
struct {
ats_ptr_type atslab_3 ;
ats_ptr_type atslab_4 ;
} anairiats_rec_0 ;

typedef struct {
ats_ptr_type atslab_0 ;
ats_ptr_type atslab_1 ;
} anairiats_sum_1 ;

/* external typedefs */
/* external dynamic constructor declarations */
ATSextern_val(ats_sum_type, ATS_2d0_2e2_2e10_2prelude_2basics_sta_2esats__list_vt_cons_0) ;
ATSextern_val(ats_sum_type, ATS_2d0_2e2_2e10_2prelude_2basics_sta_2esats__list_vt_nil_1) ;

/* external dynamic constant declarations */
ATSextern_fun(ats_void_type, atspre_vbox_make_view_ptr) (ats_ptr_type) ;
ATSextern_fun(ats_bool_type, atspre_lte_int_int) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_isucc) (ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_iadd) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_isub) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_idiv) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_ilt) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_igt) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_igte) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_size1_of_int1) (ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_add_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_sub_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_mul2_size1_size1) (ats_size_type, ats_size_type) ;
ATSextern_fun(ats_bool_type, atspre_lt_size1_size1) (ats_size_type, ats_size_type) ;
ATSextern_fun(ats_bool_type, atspre_gt_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_neq_size1_size1) (ats_size_type, ats_size_type) ;
ATSextern_fun(ats_ptr_type, atspre_ptr_alloc_tsz) (ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_ptr_zero_tsz) (ats_ref_type, ats_size_type) ;
ATSextern_fun(ats_ptr_type, atspre_ref_make_elt_tsz) (ats_ref_type, ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_fprintf_exn) (ats_ptr_type, ats_ptr_type, ...) ;
ATSextern_fun(ats_ptr_type, ListSubscriptException_make) () ;
ATSextern_fun(ats_ptr_type, atspre_array_ptr_alloc_tsz) (ats_size_type, ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_array_ptr_free) (ats_ptr_type) ;
ATSextern_fun(ats_void_type, atspre_array_ptr_initialize_funenv_tsz) (ats_ref_type, ats_size_type, ats_ptr_type, ats_size_type, ats_ptr_type) ;
ATSextern_fun(ats_void_type, atspre_array_ptr_initialize_cloenv_tsz) (ats_ref_type, ats_size_type, ats_ref_type, ats_size_type, ats_ptr_type) ;
ATSextern_fun(ats_ptr_type, atspre_array_ptr_split_tsz) (ats_ptr_type, ats_size_type, ats_size_type) ;
ATSextern_fun(ats_ptr_type, atspre_array_ptr_takeout_tsz) (ats_ptr_type, ats_size_type, ats_size_type) ;
ATSextern_fun(anairiats_rec_0, atspre_array_ptr_takeout2_tsz) (ats_ptr_type, ats_size_type, ats_size_type, ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_array_ptr_foreach_funenv_tsz) (ats_ref_type, ats_ptr_type, ats_size_type, ats_size_type, ats_ptr_type) ;
ATSextern_fun(ats_void_type, atspre_array_ptr_iforeach_funenv_tsz) (ats_ref_type, ats_ptr_type, ats_size_type, ats_size_type, ats_ptr_type) ;
ATSextern_fun(ats_ptr_type, atspre_array2_ptr_takeout_tsz) (ats_ptr_type, ats_size_type, ats_size_type, ats_size_type) ;
ATSextern_fun(ats_void_type, atslib_qsort) (ats_ref_type, ats_size_type, ats_size_type, ats_ptr_type) ;
ATSextern_fun(ats_varet_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_error_2esats__abort) () ;

/* external dynamic terminating constant declarations */
#ifdef _ATS_PROOFCHECK
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2list_2esats__list_length_is_nonnegative_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2array_2esats__array_v_takeout2_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
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
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____copy_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____free_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____assert_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____assert_prfck () ;
#endif /* _ATS_PROOFCHECK */

/* assuming abstract types */
/* sum constructor declarations */
/* exn constructor declarations */
/* global dynamic (non-functional) constant declarations */
/* internal function declarations */
static
ats_ptr_type ref_01088_ats_ptr_type (ats_ptr_type arg0) ;
static
ats_ptr_type the_trans3errlst_get_1 () ;
static
ats_int_type loop_5 (ats_ptr_type arg0, ats_int_type arg1) ;
static
ats_int_type list_vt_length_01501_ats_ptr_type (ats_ptr_type arg0) ;
static
ats_void_type loop_7 (ats_ptr_type arg0) ;
static
ats_void_type list_vt_free_01499_ats_ptr_type (ats_ptr_type arg0) ;

/* partial value template declarations */
/* static temporary variable declarations */
ATSstatic (ats_ptr_type, statmp0) ;
ATSstatic (ats_ptr_type, statmp3) ;

/* external value variable declarations */

/* function implementations */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/reference.dats: 1828(line=57, offs=18) -- 1902(line=59, offs=4)
*/
ATSstaticdec()
ats_ptr_type
ref_01088_ats_ptr_type (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp1) ;
ATSlocal (ats_ptr_type, tmp2) ;

__ats_lab_ref_01088_ats_ptr_type:
/* ats_ptr_type tmp2 ; */
tmp2 = arg0 ;
tmp1 = atspre_ref_make_elt_tsz ((&tmp2), sizeof(ats_ptr_type)) ;
return (tmp1) ;
} /* end of [ref_01088_ats_ptr_type] */

/*
// /home/hwxi/research/Postiats/git/src/pats_trans3_error.dats: 1705(line=58, offs=5) -- 1869(line=65, offs=4)
*/
ATSstaticdec()
ats_ptr_type
the_trans3errlst_get_1 () {
/* local vardec */
ATSlocal (ats_ptr_type, tmp4) ;
ATSlocal (ats_ptr_type, tmp5) ;
ATSlocal (ats_ptr_type, tmp6) ;
ATSlocal (ats_ptr_type, tmp7) ;

__ats_lab_the_trans3errlst_get_1:
tmp5 = ats_selsin_mac(ats_castfn_mac(ats_ptr_type, statmp0), atslab_1) ;
tmp6 = ats_ptrget_mac(ats_ptr_type, tmp5) ;
tmp7 = (ats_sum_ptr_type)0 ;
ats_ptrget_mac(ats_ptr_type, tmp5) = tmp7 ;
tmp4 = tmp6 ;
return (tmp4) ;
} /* end of [the_trans3errlst_get_1] */

/*
// /home/hwxi/research/Postiats/git/src/pats_trans3_error.dats: 1956(line=70, offs=22) -- 2070(line=73, offs=2)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__the_trans3errlst_add (ats_ptr_type arg0) {
/* local vardec */
// ATSlocal_void (tmp8) ;
ATSlocal (ats_ptr_type, tmp9) ;
ATSlocal (ats_ptr_type, tmp10) ;
ATSlocal (ats_ptr_type, tmp11) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__the_trans3errlst_add:
tmp9 = ats_selsin_mac(ats_castfn_mac(ats_ptr_type, statmp0), atslab_1) ;
tmp11 = ats_ptrget_mac(ats_ptr_type, tmp9) ;
tmp10 = ATS_MALLOC(sizeof(anairiats_sum_1)) ;
ats_selptrset_mac(anairiats_sum_1, tmp10, atslab_0, arg0) ;
ats_selptrset_mac(anairiats_sum_1, tmp10, atslab_1, tmp11) ;
ats_ptrget_mac(ats_ptr_type, tmp9) = tmp10 ;
return /* (tmp8) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__the_trans3errlst_add] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/list_vt.dats: 5506(line=202, offs=7) -- 5735(line=208, offs=6)
*/
ATSstaticdec()
ats_int_type
loop_5 (ats_ptr_type arg0, ats_int_type arg1) {
/* local vardec */
ATSlocal (ats_int_type, tmp16) ;
ATSlocal (ats_ptr_type, tmp17) ;
ATSlocal (ats_ptr_type, tmp18) ;
ATSlocal (ats_int_type, tmp19) ;

__ats_lab_loop_5:
do {
/* branch: __ats_lab_0 */
__ats_lab_0_0:
if (arg0 == (ats_sum_ptr_type)0) { goto __ats_lab_1_0 ; }
__ats_lab_0_1:
tmp17 = &ats_caselptrlab_mac(anairiats_sum_1, arg0, atslab_1) ;
tmp18 = ats_ptrget_mac(ats_ptr_type, tmp17) ;
tmp19 = atspre_iadd (arg1, 1) ;
arg0 = tmp18 ;
arg1 = tmp19 ;
goto __ats_lab_loop_5 ; // tail call
break ;

/* branch: __ats_lab_1 */
__ats_lab_1_0:
// if (arg0 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_1_1:
tmp16 = arg1 ;
break ;
} while (0) ;
return (tmp16) ;
} /* end of [loop_5] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/list_vt.dats: 5439(line=200, offs=16) -- 5775(line=211, offs=4)
*/
ATSstaticdec()
ats_int_type
list_vt_length_01501_ats_ptr_type (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_int_type, tmp15) ;

__ats_lab_list_vt_length_01501_ats_ptr_type:
tmp15 = loop_5 (arg0, 0) ;
return (tmp15) ;
} /* end of [list_vt_length_01501_ats_ptr_type] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/list_vt.dats: 4893(line=177, offs=7) -- 5015(line=178, offs=73)
*/
ATSstaticdec()
ats_void_type
loop_7 (ats_ptr_type arg0) {
/* local vardec */
// ATSlocal_void (tmp22) ;
ATSlocal (ats_ptr_type, tmp23) ;

__ats_lab_loop_7:
do {
/* branch: __ats_lab_2 */
__ats_lab_2_0:
if (arg0 == (ats_sum_ptr_type)0) { goto __ats_lab_3_0 ; }
__ats_lab_2_1:
tmp23 = ats_caselptrlab_mac(anairiats_sum_1, arg0, atslab_1) ;
ATS_FREE(arg0) ;
arg0 = tmp23 ;
goto __ats_lab_loop_7 ; // tail call
break ;

/* branch: __ats_lab_3 */
__ats_lab_3_0:
// if (arg0 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_3_1:
break ;
} while (0) ;
return /* (tmp22) */ ;
} /* end of [loop_7] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/list_vt.dats: 4875(line=176, offs=14) -- 5054(line=182, offs=4)
*/
ATSstaticdec()
ats_void_type
list_vt_free_01499_ats_ptr_type (ats_ptr_type arg0) {
/* local vardec */
// ATSlocal_void (tmp21) ;

__ats_lab_list_vt_free_01499_ats_ptr_type:
/* tmp21 = */ loop_7 (arg0) ;
return /* (tmp21) */ ;
} /* end of [list_vt_free_01499_ats_ptr_type] */

/*
// /home/hwxi/research/Postiats/git/src/pats_trans3_error.dats: 2141(line=76, offs=27) -- 2433(line=85, offs=2)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__the_trans3errlst_finalize () {
/* local vardec */
// ATSlocal_void (tmp12) ;
ATSlocal (ats_ptr_type, tmp13) ;
ATSlocal (ats_int_type, tmp14) ;
// ATSlocal_void (tmp20) ;
// ATSlocal_void (tmp24) ;
ATSlocal (ats_bool_type, tmp25) ;
ATSlocal (ats_bool_type, tmp26) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__the_trans3errlst_finalize:
tmp13 = the_trans3errlst_get_1 () ;
tmp14 = list_vt_length_01501_ats_ptr_type (tmp13) ;
/* tmp20 = */ list_vt_free_01499_ats_ptr_type (tmp13) ;
tmp25 = atspre_igt (tmp14, 0) ;
if (tmp25) {
/* tmp24 = */ atspre_fprintf_exn (stderr, ATSstrcst("TRANS3: there are [%i] errors in total.\n"), tmp14) ;
} else {
/* empty */
} /* end of [if] */
tmp26 = atspre_igt (tmp14, 0) ;
if (tmp26) {
/* tmp12 = */ _2home_2hwxi_2research_2Postiats_2git_2src_2pats_error_2esats__abort () ;
} else {
/* empty */
} /* end of [if] */
return /* (tmp12) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__the_trans3errlst_finalize] */

/* static load function */

// extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_atspre_2edats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_error_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__staload (void) ;

ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__staload () {
static int _2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__staload_flag = 0 ;
if (_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__staload_flag) return ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__staload_flag = 1 ;

// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_atspre_2edats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_error_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_2esats__staload () ;

return ;
} /* staload function */

/* dynamic load function */

// dynload flag declaration
extern ats_int_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__dynload_flag ;

ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__dynload () {
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__dynload_flag = 1 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_trans3_error_2edats__staload () ;

#ifdef _ATS_PROOFCHECK
ATS_2d0_2e2_2e10_2prelude_2SATS_2list_2esats__list_length_is_nonnegative_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2SATS_2list_vt_2esats__list_vt_length_is_nonnegative_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2SATS_2array_2esats__array_v_takeout2_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2list_vt_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____copy_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____free_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____assert_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2array_2edats____assert_prfck () ;
#endif /* _ATS_PROOFCHECK */

/* marking static variables for GC */
ATS_GC_MARKROOT(&statmp0, sizeof(ats_ptr_type)) ;
ATS_GC_MARKROOT(&statmp3, sizeof(ats_ptr_type)) ;

/* marking external values for GC */

/* code for dynamic loading */
statmp3 = (ats_sum_ptr_type)0 ;
statmp0 = ref_01088_ats_ptr_type (statmp3) ;
return ;
} /* end of [dynload function] */

/* external codes at mid */
/* external codes at bot */

/* ****** ****** */

/* end of [pats_trans3_error_dats.c] */
