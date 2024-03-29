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
/* external codes at top */

ATSinline()
ats_ptr_type
atspre_string_string_alloc
  (ats_size_type n) {
  char *p ;
  p = ATS_MALLOC(n+1); p[n] = '\000'; return p ;
} // end of [atspre_string_string_alloc]

/* type definitions */
typedef struct {
ats_char_type atslab_0 ;
ats_ptr_type atslab_1 ;
} anairiats_sum_0 ;

typedef struct {
ats_ptr_type atslab_0 ;
ats_ptr_type atslab_1 ;
} anairiats_sum_1 ;

/* external typedefs */
/* external dynamic constructor declarations */
ATSextern_val(ats_sum_type, ATS_2d0_2e2_2e10_2prelude_2basics_sta_2esats__list_cons_0) ;
ATSextern_val(ats_sum_type, ATS_2d0_2e2_2e10_2prelude_2basics_sta_2esats__list_nil_1) ;
ATSextern_val(ats_sum_type, ATS_2d0_2e2_2e10_2prelude_2basics_sta_2esats__list_vt_cons_0) ;
ATSextern_val(ats_sum_type, ATS_2d0_2e2_2e10_2prelude_2basics_sta_2esats__list_vt_nil_1) ;

/* external dynamic constant declarations */
ATSextern_fun(ats_bool_type, atspre_neq_char_char) (ats_char_type, ats_char_type) ;
ATSextern_fun(ats_int_type, atspre_iadd) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_isub) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_ilt) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_ilte) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_add_size_size) (ats_size_type, ats_size_type) ;
ATSextern_fun(ats_size_type, atspre_size1_of_int1) (ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_add_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_size_type, atspre_sub_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_lt_size1_size1) (ats_size_type, ats_size_type) ;
ATSextern_fun(ats_bool_type, atspre_gte_size1_int1) (ats_size_type, ats_int_type) ;
ATSextern_fun(ats_ptr_type, ats_malloc_gc) (ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_fprint_string) (ats_ptr_type, ats_ref_type) ;
ATSextern_fun(ats_char_type, atspre_string_get_char_at) (ats_ptr_type, ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_strbuf_set_char_at) (ats_ref_type, ats_size_type, ats_char_type) ;
ATSextern_fun(ats_char_type, atspre_string_test_char_at) (ats_ptr_type, ats_size_type) ;
ATSextern_fun(ats_ptr_type, atspre_string_make_list_int) (ats_ptr_type, ats_int_type) ;
ATSextern_fun(ats_ptr_type, atspre_string_make_substring) (ats_ptr_type, ats_size_type, ats_size_type) ;
ATSextern_fun(ats_size_type, atspre_string_length) (ats_ptr_type) ;
ATSextern_fun(ats_size_type, atspre_string_length) (ats_ptr_type) ;
ATSextern_fun(ats_bool_type, atspre_string_isnot_atend) (ats_ptr_type, ats_size_type) ;
ATSextern_fun(ats_void_type, atspre_fprint_strptr) (ats_ptr_type, ats_ptr_type) ;
ATSextern_fun(ats_void_type, atspre_prerrf_exn) (ats_ptr_type, ...) ;
ATSextern_fun(ats_ptr_type, atspre_string_string_alloc) (ats_size_type) ;
ATSextern_fun(ats_ptr_type, atspre_string_string_alloc) (ats_size_type) ;
ATSextern_fun(ats_ptr_type, atspre_string_string_alloc) (ats_size_type) ;
ATSextern_fun(ats_char_type, atspre_char_tolower) (ats_char_type) ;
ATSextern_fun(ats_char_type, atspre_char_toupper) (ats_char_type) ;

/* external dynamic terminating constant declarations */
#ifdef _ATS_PROOFCHECK
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_vsubr_lemma0_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_split_prfck () ;
extern
ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_unsplit_prfck () ;
#endif /* _ATS_PROOFCHECK */

/* assuming abstract types */
/* sum constructor declarations */
/* exn constructor declarations */
/* global dynamic (non-functional) constant declarations */
/* internal function declarations */
static
ats_void_type loop_6 (ats_ref_type arg0, ats_int_type arg1, ats_int_type arg2, ats_ptr_type arg3) ;
static
ats_void_type loop_8 (ats_ref_type arg0, ats_int_type arg1, ats_int_type arg2, ats_ptr_type arg3) ;
static
ats_size_type aux_10 (ats_ptr_type arg0, ats_size_type arg1) ;
static
ats_size_type loop1_11 (ats_ref_type arg0, ats_size_type arg1, ats_size_type arg2, ats_ptr_type arg3, ats_size_type arg4) ;
static
ats_void_type loop2_12 (ats_ref_type arg0, ats_size_type arg1, ats_size_type arg2, ats_ptr_type arg3) ;
static
ats_ptr_type loop_14 (ats_ptr_type arg0, ats_size_type arg1, ats_ptr_type arg2) ;
static
ats_int_type loop_16 (ats_ptr_type arg0, ats_int_type arg1) ;
static
ats_void_type loop_18 (ats_ptr_type arg0, ats_ptr_type arg1, ats_ptr_type arg2, ats_size_type arg3) ;
static
ats_void_type loop_20 (ats_ptr_type env0, ats_ptr_type env1, ats_size_type env2, ats_ptr_type arg0, ats_size_type arg1) ;
static
ats_clo_ptr_type loop_20_closure_make (ats_ptr_type env0, ats_ptr_type env1, ats_size_type env2) ;
static
ats_void_type loop_20_clofun (ats_clo_ptr_type cloptr, ats_ptr_type arg0, ats_size_type arg1) ;
static
ats_ptr_type string_make_fun_19 (ats_ptr_type arg0, ats_ptr_type arg1) ;

/* partial value template declarations */
/* static temporary variable declarations */
/* external value variable declarations */

/* function implementations */

#ifdef _ATS_PROOFCHECK
/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 1667(line=46, offs=1) -- 1715(line=46, offs=49)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_vsubr_lemma0_prfck () {
/* local vardec */
// ATSlocal_void (tmp0) ;

ats_proofcheck_beg_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_vsubr_lemma0) ;
ATS_2d0_2e2_2e10_2prelude_2SATS_2vsubrw_2esats__vsubr_refl_prfck () ;
ats_proofcheck_end_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_vsubr_lemma0) ;
return /* (tmp0) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_vsubr_lemma0_prfck] */
#endif /* _ATS_PROOFCHECK */

#ifdef _ATS_PROOFCHECK
/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 1738(line=50, offs=1) -- 2492(line=72, offs=2)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_split_prfck () {
/* local vardec */
// ATSlocal_void (tmp1) ;

ats_proofcheck_beg_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_split) ;
ats_proofcheck_end_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_split) ;
return /* (tmp1) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_split_prfck] */
#endif /* _ATS_PROOFCHECK */

#ifdef _ATS_PROOFCHECK
/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 2521(line=74, offs=1) -- 3260(line=94, offs=2)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_unsplit_prfck () {
/* local vardec */
// ATSlocal_void (tmp2) ;

ats_proofcheck_beg_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_unsplit) ;
ats_proofcheck_end_mac(ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_unsplit) ;
return /* (tmp2) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_unsplit_prfck] */
#endif /* _ATS_PROOFCHECK */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 3335(line=98, offs=24) -- 3375(line=98, offs=64)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__print_strbuf (ats_ref_type arg0) {
/* local vardec */
// ATSlocal_void (tmp3) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__print_strbuf:
/* tmp3 = */ atspre_fprint_string (stdout, arg0) ;
return /* (tmp3) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__print_strbuf] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 3399(line=99, offs=24) -- 3439(line=99, offs=64)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__prerr_strbuf (ats_ref_type arg0) {
/* local vardec */
// ATSlocal_void (tmp4) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__prerr_strbuf:
/* tmp4 = */ atspre_fprint_string (stderr, arg0) ;
return /* (tmp4) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__prerr_strbuf] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 4181(line=133, offs=9) -- 4889(line=154, offs=10)
*/
ATSstaticdec()
ats_void_type
loop_6 (ats_ref_type arg0, ats_int_type arg1, ats_int_type arg2, ats_ptr_type arg3) {
/* local vardec */
// ATSlocal_void (tmp9) ;
ATSlocal (ats_bool_type, tmp10) ;
ATSlocal (ats_char_type, tmp11) ;
ATSlocal (ats_ptr_type, tmp12) ;
// ATSlocal_void (tmp13) ;
ATSlocal (ats_bool_type, tmp14) ;
// ATSlocal_void (tmp15) ;
// ATSlocal_void (tmp16) ;
ATSlocal (ats_size_type, tmp17) ;
ATSlocal (ats_int_type, tmp18) ;

__ats_lab_loop_6:
tmp10 = atspre_ilt (arg2, arg1) ;
if (tmp10) {
// if (arg3 == (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
tmp11 = ats_caselptrlab_mac(anairiats_sum_0, arg3, atslab_0) ;
tmp12 = ats_caselptrlab_mac(anairiats_sum_0, arg3, atslab_1) ;
tmp14 = atspre_neq_char_char (ats_castfn_mac(ats_char_type, tmp11), '\000') ;
if (tmp14) {
/* empty */
} else {
/* tmp15 = */ atspre_prerrf_exn (ATSstrcst("exit(ATS): a string cannot contain null characters in the middle.\n")) ;
/* tmp13 = */ ats_exit (1) ;
} /* end of [if] */
tmp17 = atspre_size1_of_int1 (arg2) ;
/* tmp16 = */ atspre_strbuf_set_char_at (arg0, tmp17, ats_castfn_mac(ats_char_type, tmp11)) ;
tmp18 = atspre_iadd (arg2, 1) ;
arg0 = arg0 ;
arg1 = arg1 ;
arg2 = tmp18 ;
arg3 = tmp12 ;
goto __ats_lab_loop_6 ; // tail call
} else {
/* empty */
} /* end of [if] */
return /* (tmp9) */ ;
} /* end of [loop_6] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 3873(line=125, offs=22) -- 4963(line=158, offs=4)
*/
ATSglobaldec()
ats_ptr_type
atspre_string_make_list_int (ats_ptr_type arg0, ats_int_type arg1) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp5) ;
ATSlocal (ats_ptr_type, tmp6) ;
ATSlocal (ats_size_type, tmp7) ;
ATSlocal (ats_ptr_type, tmp8) ;
// ATSlocal_void (tmp19) ;

__ats_lab_atspre_string_make_list_int:
tmp7 = atspre_size1_of_int1 (arg1) ;
tmp6 = atspre_string_string_alloc (tmp7) ;
tmp8 = ats_selsin_mac(tmp6, atslab_2) ;
/* tmp19 = */ loop_6 (tmp8, arg1, 0, arg0) ;
tmp5 = tmp8 ;
return (tmp5) ;
} /* end of [atspre_string_make_list_int] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 5343(line=169, offs=9) -- 6064(line=190, offs=10)
*/
ATSstaticdec()
ats_void_type
loop_8 (ats_ref_type arg0, ats_int_type arg1, ats_int_type arg2, ats_ptr_type arg3) {
/* local vardec */
// ATSlocal_void (tmp24) ;
ATSlocal (ats_bool_type, tmp25) ;
ATSlocal (ats_char_type, tmp26) ;
ATSlocal (ats_ptr_type, tmp27) ;
// ATSlocal_void (tmp28) ;
ATSlocal (ats_bool_type, tmp29) ;
// ATSlocal_void (tmp30) ;
// ATSlocal_void (tmp31) ;
ATSlocal (ats_size_type, tmp32) ;
ATSlocal (ats_int_type, tmp33) ;
ATSlocal (ats_int_type, tmp34) ;

__ats_lab_loop_8:
tmp25 = atspre_ilte (arg2, arg1) ;
if (tmp25) {
// if (arg3 == (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
tmp26 = ats_caselptrlab_mac(anairiats_sum_0, arg3, atslab_0) ;
tmp27 = ats_caselptrlab_mac(anairiats_sum_0, arg3, atslab_1) ;
tmp29 = atspre_neq_char_char (ats_castfn_mac(ats_char_type, tmp26), '\000') ;
if (tmp29) {
/* empty */
} else {
/* tmp30 = */ atspre_prerrf_exn (ATSstrcst("exit(ATS): a string cannot contain null characters in the middle.\n")) ;
/* tmp28 = */ ats_exit (1) ;
} /* end of [if] */
tmp33 = atspre_isub (arg1, arg2) ;
tmp32 = atspre_size1_of_int1 (tmp33) ;
/* tmp31 = */ atspre_strbuf_set_char_at (arg0, tmp32, ats_castfn_mac(ats_char_type, tmp26)) ;
tmp34 = atspre_iadd (arg2, 1) ;
arg0 = arg0 ;
arg1 = arg1 ;
arg2 = tmp34 ;
arg3 = tmp27 ;
goto __ats_lab_loop_8 ; // tail call
} else {
/* empty */
} /* end of [if] */
return /* (tmp24) */ ;
} /* end of [loop_8] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 5033(line=161, offs=26) -- 6138(line=194, offs=4)
*/
ATSglobaldec()
ats_ptr_type
atspre_string_make_list_rev_int (ats_ptr_type arg0, ats_int_type arg1) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp20) ;
ATSlocal (ats_ptr_type, tmp21) ;
ATSlocal (ats_size_type, tmp22) ;
ATSlocal (ats_ptr_type, tmp23) ;
// ATSlocal_void (tmp35) ;
ATSlocal (ats_int_type, tmp36) ;

__ats_lab_atspre_string_make_list_rev_int:
tmp22 = atspre_size1_of_int1 (arg1) ;
tmp21 = atspre_string_string_alloc (tmp22) ;
tmp23 = ats_selsin_mac(tmp21, atslab_2) ;
tmp36 = atspre_isub (arg1, 1) ;
/* tmp35 = */ loop_8 (tmp23, tmp36, 0, arg0) ;
tmp20 = tmp23 ;
return (tmp20) ;
} /* end of [atspre_string_make_list_rev_int] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 6276(line=201, offs=9) -- 6436(line=203, offs=79)
*/
ATSstaticdec()
ats_size_type
aux_10 (ats_ptr_type arg0, ats_size_type arg1) {
/* local vardec */
ATSlocal (ats_size_type, tmp38) ;
ATSlocal (ats_ptr_type, tmp39) ;
ATSlocal (ats_ptr_type, tmp40) ;
ATSlocal (ats_size_type, tmp41) ;
ATSlocal (ats_size_type, tmp42) ;

__ats_lab_aux_10:
do {
/* branch: __ats_lab_0 */
__ats_lab_0_0:
if (arg0 == (ats_sum_ptr_type)0) { goto __ats_lab_1_0 ; }
__ats_lab_0_1:
tmp39 = ats_caselptrlab_mac(anairiats_sum_1, arg0, atslab_0) ;
tmp40 = ats_caselptrlab_mac(anairiats_sum_1, arg0, atslab_1) ;
tmp42 = atspre_string_length (tmp39) ;
tmp41 = atspre_add_size_size (arg1, tmp42) ;
arg0 = tmp40 ;
arg1 = tmp41 ;
goto __ats_lab_aux_10 ; // tail call
break ;

/* branch: __ats_lab_1 */
__ats_lab_1_0:
// if (arg0 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_1_1:
tmp38 = arg1 ;
break ;
} while (0) ;
return (tmp38) ;
} /* end of [aux_10] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 6525(line=207, offs=7) -- 6870(line=214, offs=6)
*/
ATSstaticdec()
ats_size_type
loop1_11 (ats_ref_type arg0, ats_size_type arg1, ats_size_type arg2, ats_ptr_type arg3, ats_size_type arg4) {
/* local vardec */
ATSlocal (ats_size_type, tmp45) ;
ATSlocal (ats_char_type, tmp46) ;
ATSlocal (ats_bool_type, tmp47) ;
ATSlocal (ats_bool_type, tmp48) ;
// ATSlocal_void (tmp49) ;
ATSlocal (ats_size_type, tmp50) ;
ATSlocal (ats_size_type, tmp51) ;

__ats_lab_loop1_11:
tmp46 = atspre_string_test_char_at (arg3, arg4) ;
tmp47 = atspre_neq_char_char (tmp46, '\000') ;
if (tmp47) {
tmp48 = atspre_lt_size1_size1 (arg2, arg1) ;
if (tmp48) {
/* tmp49 = */ atspre_strbuf_set_char_at (arg0, arg2, tmp46) ;
tmp50 = atspre_add_size1_int1 (arg2, 1) ;
tmp51 = atspre_add_size1_int1 (arg4, 1) ;
arg0 = arg0 ;
arg1 = arg1 ;
arg2 = tmp50 ;
arg3 = arg3 ;
arg4 = tmp51 ;
goto __ats_lab_loop1_11 ; // tail call
} else {
tmp45 = arg2 ;
} /* end of [if] */
} else {
tmp45 = arg2 ;
} /* end of [if] */
return (tmp45) ;
} /* end of [loop1_11] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 6898(line=215, offs=7) -- 7276(line=225, offs=6)
*/
ATSstaticdec()
ats_void_type
loop2_12 (ats_ref_type arg0, ats_size_type arg1, ats_size_type arg2, ats_ptr_type arg3) {
/* local vardec */
// ATSlocal_void (tmp52) ;
ATSlocal (ats_ptr_type, tmp53) ;
ATSlocal (ats_ptr_type, tmp54) ;
ATSlocal (ats_size_type, tmp55) ;

__ats_lab_loop2_12:
do {
/* branch: __ats_lab_2 */
__ats_lab_2_0:
if (arg3 == (ats_sum_ptr_type)0) { goto __ats_lab_3_0 ; }
__ats_lab_2_1:
tmp53 = ats_caselptrlab_mac(anairiats_sum_1, arg3, atslab_0) ;
tmp54 = ats_caselptrlab_mac(anairiats_sum_1, arg3, atslab_1) ;
tmp55 = loop1_11 (arg0, arg1, arg2, ats_castfn_mac(ats_ptr_type, tmp53), 0) ;
arg0 = arg0 ;
arg1 = arg1 ;
arg2 = tmp55 ;
arg3 = tmp54 ;
goto __ats_lab_loop2_12 ; // tail call
break ;

/* branch: __ats_lab_3 */
__ats_lab_3_0:
// if (arg3 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_3_1:
break ;
} while (0) ;
return /* (tmp52) */ ;
} /* end of [loop2_12] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 6221(line=199, offs=18) -- 7635(line=236, offs=4)
*/
ATSglobaldec()
ats_ptr_type
atspre_stringlst_concat (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp37) ;
ATSlocal (ats_size_type, tmp43) ;
ATSlocal (ats_size_type, tmp44) ;
ATSlocal (ats_ptr_type, tmp56) ;
ATSlocal (ats_ptr_type, tmp57) ;
// ATSlocal_void (tmp58) ;
ATSlocal (ats_ptr_type, tmp59) ;

__ats_lab_atspre_stringlst_concat:
tmp44 = atspre_size1_of_int1 (0) ;
tmp43 = aux_10 (arg0, tmp44) ;
tmp56 = atspre_string_string_alloc (ats_castfn_mac(ats_size_type, tmp43)) ;
tmp57 = ats_selsin_mac(tmp56, atslab_2) ;
/* tmp58 = */ loop2_12 (tmp57, ats_castfn_mac(ats_size_type, tmp43), 0, arg0) ;
tmp59 = tmp57 ;
tmp37 = ats_castfn_mac(ats_ptr_type, tmp59) ;
return (tmp37) ;
} /* end of [atspre_stringlst_concat] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 7728(line=242, offs=7) -- 8029(line=250, offs=8)
*/
ATSstaticdec()
ats_ptr_type
loop_14 (ats_ptr_type arg0, ats_size_type arg1, ats_ptr_type arg2) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp61) ;
ATSlocal (ats_bool_type, tmp62) ;
ATSlocal (ats_size_type, tmp63) ;
ATSlocal (ats_char_type, tmp64) ;
ATSlocal (ats_ptr_type, tmp65) ;

__ats_lab_loop_14:
tmp62 = atspre_gte_size1_int1 (arg1, 1) ;
if (tmp62) {
tmp63 = atspre_sub_size1_int1 (arg1, 1) ;
tmp64 = atspre_string_get_char_at (arg0, tmp63) ;
tmp65 = ATS_MALLOC(sizeof(anairiats_sum_0)) ;
ats_selptrset_mac(anairiats_sum_0, tmp65, atslab_0, tmp64) ;
ats_selptrset_mac(anairiats_sum_0, tmp65, atslab_1, arg2) ;
arg0 = arg0 ;
arg1 = tmp63 ;
arg2 = tmp65 ;
goto __ats_lab_loop_14 ; // tail call
} else {
tmp61 = arg2 ;
} /* end of [if] */
return (tmp61) ;
} /* end of [loop_14] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 7712(line=241, offs=16) -- 8111(line=255, offs=4)
*/
ATSglobaldec()
ats_ptr_type
atspre_string_explode (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp60) ;
ATSlocal (ats_size_type, tmp66) ;
ATSlocal (ats_ptr_type, tmp67) ;

__ats_lab_atspre_string_explode:
tmp66 = atspre_string_length (arg0) ;
tmp67 = (ats_sum_ptr_type)0 ;
tmp60 = loop_14 (arg0, tmp66, tmp67) ;
return (tmp60) ;
} /* end of [atspre_string_explode] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 8229(line=260, offs=7) -- 8372(line=262, offs=61)
*/
ATSstaticdec()
ats_int_type
loop_16 (ats_ptr_type arg0, ats_int_type arg1) {
/* local vardec */
ATSlocal (ats_int_type, tmp69) ;
ATSlocal (ats_ptr_type, tmp70) ;
ATSlocal (ats_int_type, tmp71) ;

__ats_lab_loop_16:
do {
/* branch: __ats_lab_4 */
__ats_lab_4_0:
if (arg0 == (ats_sum_ptr_type)0) { goto __ats_lab_5_0 ; }
__ats_lab_4_1:
tmp70 = ats_caselptrlab_mac(anairiats_sum_0, arg0, atslab_1) ;
tmp71 = atspre_iadd (arg1, 1) ;
arg0 = tmp70 ;
arg1 = tmp71 ;
goto __ats_lab_loop_16 ; // tail call
break ;

/* branch: __ats_lab_5 */
__ats_lab_5_0:
// if (arg0 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_5_1:
tmp69 = arg1 ;
break ;
} while (0) ;
return (tmp69) ;
} /* end of [loop_16] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 8166(line=258, offs=16) -- 8390(line=264, offs=2)
*/
ATSglobaldec()
ats_ptr_type
atspre_string_implode (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp68) ;
ATSlocal (ats_int_type, tmp72) ;

__ats_lab_atspre_string_implode:
tmp72 = loop_16 (arg0, 0) ;
tmp68 = atspre_string_make_list_int (arg0, tmp72) ;
return (tmp68) ;
} /* end of [atspre_string_implode] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 8557(line=271, offs=7) -- 8787(line=275, offs=93)
*/
ATSstaticdec()
ats_void_type
loop_18 (ats_ptr_type arg0, ats_ptr_type arg1, ats_ptr_type arg2, ats_size_type arg3) {
/* local vardec */
// ATSlocal_void (tmp74) ;
ATSlocal (ats_bool_type, tmp75) ;
// ATSlocal_void (tmp76) ;
ATSlocal (ats_char_type, tmp77) ;
ATSlocal (ats_size_type, tmp78) ;

__ats_lab_loop_18:
tmp75 = atspre_string_isnot_atend (arg0, arg3) ;
if (tmp75) {
tmp77 = atspre_string_get_char_at (arg0, arg3) ;
/* tmp76 = */ ((ats_void_type(*)(ats_char_type, ats_ptr_type))arg1) (tmp77, arg2) ;
tmp78 = atspre_add_size1_int1 (arg3, 1) ;
arg0 = arg0 ;
arg1 = arg1 ;
arg2 = arg2 ;
arg3 = tmp78 ;
goto __ats_lab_loop_18 ; // tail call
} else {
/* empty */
} /* end of [if] */
return /* (tmp74) */ ;
} /* end of [loop_18] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 8494(line=270, offs=3) -- 8808(line=277, offs=2)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_foreach__main (ats_ptr_type arg0, ats_ptr_type arg1, ats_ptr_type arg2) {
/* local vardec */
// ATSlocal_void (tmp73) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_foreach__main:
/* tmp73 = */ loop_18 (arg0, arg1, arg2, 0) ;
return /* (tmp73) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_foreach__main] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 9118(line=289, offs=9) -- 9779(line=309, offs=8)
*/
ATSstaticdec()
ats_void_type
loop_20 (ats_ptr_type env0, ats_ptr_type env1, ats_size_type env2, ats_ptr_type arg0, ats_size_type arg1) {
/* local vardec */
// ATSlocal_void (tmp84) ;
ATSlocal (ats_bool_type, tmp85) ;
ATSlocal (ats_char_type, tmp86) ;
ATSlocal (ats_char_type, tmp87) ;
ATSlocal (ats_ptr_type, tmp88) ;
ATSlocal (ats_size_type, tmp89) ;

__ats_lab_loop_20:
tmp85 = atspre_lt_size1_size1 (arg1, env2) ;
if (tmp85) {
tmp86 = atspre_string_get_char_at (env0, arg1) ;
tmp87 = ((ats_char_type(*)(ats_char_type))env1) (tmp86) ;
ats_ptrget_mac(ats_char_type, arg0) = tmp87 ;
tmp88 = atspre_padd_size (arg0, sizeof(ats_byte_type)) ;
tmp89 = atspre_add_size1_int1 (arg1, 1) ;
arg0 = tmp88 ;
arg1 = tmp89 ;
goto __ats_lab_loop_20 ; // tail call
} else {
ats_ptrget_mac(ats_char_type, arg0) = '\000' ;
} /* end of [if] */
return /* (tmp84) */ ;
} /* end of [loop_20] */

typedef struct {
ats_fun_ptr_type closure_fun ;
ats_ptr_type closure_env_0 ;
ats_ptr_type closure_env_1 ;
ats_size_type closure_env_2 ;
} loop_20_closure_type ;

ats_void_type
loop_20_clofun (ats_clo_ptr_type cloptr, ats_ptr_type arg0, ats_size_type arg1) {
loop_20 (((loop_20_closure_type*)cloptr)->closure_env_0, ((loop_20_closure_type*)cloptr)->closure_env_1, ((loop_20_closure_type*)cloptr)->closure_env_2, arg0, arg1) ; return ;
} /* end of function */

ATSinline()
ats_void_type
loop_20_closure_init (loop_20_closure_type *p_clo, ats_ptr_type env0, ats_ptr_type env1, ats_size_type env2) {
p_clo->closure_fun = (ats_fun_ptr_type)&loop_20_clofun ;
p_clo->closure_env_0 = env0 ;
p_clo->closure_env_1 = env1 ;
p_clo->closure_env_2 = env2 ;
return ;
} /* end of function */

ats_clo_ptr_type
loop_20_closure_make (ats_ptr_type env0, ats_ptr_type env1, ats_size_type env2) {
loop_20_closure_type *p_clo = ATS_MALLOC(sizeof(loop_20_closure_type)) ;
loop_20_closure_init (p_clo, env0, env1, env2) ;
return (ats_clo_ptr_type)p_clo ;
} /* end of function */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 8874(line=283, offs=4) -- 9859(line=313, offs=4)
*/
ATSstaticdec()
ats_ptr_type
string_make_fun_19 (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp79) ;
ATSlocal (ats_size_type, tmp80) ;
ATSlocal (ats_ptr_type, tmp81) ;
ATSlocal (ats_size_type, tmp82) ;
ATSlocal (ats_ptr_type, tmp83) ;
// ATSlocal_void (tmp90) ;

__ats_lab_string_make_fun_19:
tmp80 = atspre_string_length (arg0) ;
tmp82 = atspre_add_size1_int1 (tmp80, 1) ;
tmp81 = ats_malloc_gc (tmp82) ;
tmp83 = ats_selsin_mac(tmp81, atslab_2) ;
/* tmp90 = */ loop_20 (arg0, arg1, tmp80, tmp83, 0) ;
tmp79 = tmp83 ;
return (tmp79) ;
} /* end of [string_make_fun_19] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 9935(line=317, offs=26) -- 10047(line=321, offs=4)
*/
ATSglobaldec()
ats_ptr_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_tolower (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp91) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_tolower:
tmp91 = string_make_fun_19 (arg0, &atspre_char_tolower) ;
return (tmp91) ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_tolower] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 10109(line=323, offs=26) -- 10221(line=327, offs=4)
*/
ATSglobaldec()
ats_ptr_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_toupper (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp92) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_toupper:
tmp92 = string_make_fun_19 (arg0, &atspre_char_toupper) ;
return (tmp92) ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__string_toupper] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 10325(line=333, offs=24) -- 10360(line=333, offs=59)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__print_strptr (ats_ptr_type arg0) {
/* local vardec */
// ATSlocal_void (tmp93) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__print_strptr:
/* tmp93 = */ atspre_fprint_strptr (stdout, arg0) ;
return /* (tmp93) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__print_strptr] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 10384(line=334, offs=24) -- 10419(line=334, offs=59)
*/
ATSglobaldec()
ats_void_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__prerr_strptr (ats_ptr_type arg0) {
/* local vardec */
// ATSlocal_void (tmp94) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__prerr_strptr:
/* tmp94 = */ atspre_fprint_strptr (stderr, arg0) ;
return /* (tmp94) */ ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__prerr_strptr] */

/*
// /home/hwxi/research/Anairiats/prelude/DATS/string.dats: 10442(line=337, offs=12) -- 10671(line=345, offs=4)
*/
ATSglobaldec()
ats_ptr_type
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strptr_dup (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp95) ;
ATSlocal (ats_size_type, tmp96) ;
ATSlocal (ats_ptr_type, tmp97) ;

__ats_lab_ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strptr_dup:
tmp96 = atspre_string_length (ats_castfn_mac(ats_ptr_type, arg0)) ;
tmp97 = atspre_string_make_substring (ats_castfn_mac(ats_ptr_type, arg0), 0, tmp96) ;
tmp95 = ats_castfn_mac(ats_ptr_type, tmp97) ;
return (tmp95) ;
} /* end of [ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strptr_dup] */

/* static load function */

// extern ats_void_type ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__staload (void) ;

ats_void_type
ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__staload () {
static int ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__staload_flag = 0 ;
if (ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__staload_flag) return ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__staload_flag = 1 ;

// ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__staload () ;

return ;
} /* staload function */

/* dynamic load function */

// dynload flag declaration
// extern ats_int_type ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__dynload_flag ;

ats_void_type
ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__dynload () {
// ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__dynload_flag = 1 ;
ATS_2d0_2e2_2e10_2prelude_2DATS_2string_2edats__staload () ;

#ifdef _ATS_PROOFCHECK
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_vsubr_lemma0_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_split_prfck () ;
ATS_2d0_2e2_2e10_2prelude_2SATS_2string_2esats__strbuf_v_unsplit_prfck () ;
#endif /* _ATS_PROOFCHECK */

/* marking static variables for GC */

/* marking external values for GC */

/* code for dynamic loading */
return ;
} /* end of [dynload function] */

/* external codes at mid */
/* external codes at bot */


#ifndef EXIT_SUCCESS
#define	EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif


//
// HX: a commonly used simple hash function
//
ats_ulint_type
atspre_string_hash_33 (ats_ptr_type s0) {
  unsigned long int hash_val ; unsigned char *s; int c;
  hash_val = 3141593UL ;
//
  s = (unsigned char*)s0 ;
  while (1) {
    c = *s ;
    if (!c) break ; // the end of string is reached
    hash_val = ((hash_val << 5) + hash_val) + c ; // hash_val = 33 * hash_val + c
    s += 1 ;
  } // end of [while]
//
  return hash_val ;
//
} // end of [atspre_string_hash_33]



ats_ptr_type
atspre_string_make_char (
  ats_size_type n, ats_char_type c
) {
  char *p ; 
  if (!c) { ats_exit_errmsg
    (EXIT_FAILURE, "exit(ATS): [string_make_char] failed: null char.\n") ;
  } ; // end of [if]
  p = ATS_MALLOC(n+1) ; memset (p, c, n) ; p[n] = '\000' ;
  return p ;
} // end of [atspre_string_make_char]

/* ****** ****** */

ats_ptr_type
atspre_string_make_substring (
  ats_ptr_type src0, ats_size_type start, ats_size_type len
) {
  char *des, *src ;
  des = ATS_MALLOC(len+1) ;
  src = ((char*)src0) + start ;
  memcpy(des, src, len) ; des[len] = '\000' ;
  return des ;
} // end of [atspre_string_make_substring]

/* ****** ****** */

ats_void_type
atspre_strbuf_tolower
  (ats_ptr_type p0) {
  int c ; char *p = (char*)p0 ;
  while ((c = *p)) { *p = tolower (c) ; p += 1 ; }
  return ;
} // end of [atspre_strbuf_tolower]

ats_void_type
atspre_strbuf_toupper
  (ats_ptr_type p0) {
  int c ; char *p = (char*)p0 ;
  while ((c = *p)) { *p = toupper (c) ; p += 1 ; }
  return ;
} // end of [atspre_strbuf_toupper]

/* ****** ****** */



/* ****** ****** */

/* end of [DATS_string_dats.c] */
