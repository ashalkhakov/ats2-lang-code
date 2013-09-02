/*
**
** The C code is generated by ATS/Anairiats
** The compilation time is: 2013-9-2: 15h:44m
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
/* type definitions */
typedef struct {
ats_int_type atslab_0 ;
} anairiats_sum_0 ;

/* external typedefs */
/* external dynamic constructor declarations */
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__CK_case_0) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__CK_case_pos_1) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__CK_case_neg_2) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FK_fn_0) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FK_fnx_1) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FK_fun_2) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FK_prfn_3) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FK_prfun_4) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FK_praxi_5) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FK_castfn_6) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__VK_val_0) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__VK_prval_1) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__VK_val_pos_2) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__VK_val_neg_3) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__DCKfun_0) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__DCKval_1) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__DCKpraxi_2) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__DCKprfun_3) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__DCKprval_4) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__DCKcastfn_5) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FUNCLOfun_0) ;
ATSextern_val(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__FUNCLOclo_1) ;

/* external dynamic constant declarations */
ATSextern_fun(ats_void_type, atspre_vbox_make_view_ptr) (ats_ptr_type) ;
ATSextern_fun(ats_bool_type, atspre_neg_bool) (ats_bool_type) ;
ATSextern_fun(ats_bool_type, atspre_eq_int_int) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_neq_int_int) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_int_type, atspre_asl_int_int1) (ats_int_type, ats_int_type) ;
ATSextern_fun(ats_bool_type, atspre_lt_uint_uint) (ats_uint_type, ats_uint_type) ;
ATSextern_fun(ats_bool_type, atspre_gt_uint_uint) (ats_uint_type, ats_uint_type) ;
ATSextern_fun(ats_bool_type, atspre_eq_uint_uint) (ats_uint_type, ats_uint_type) ;
ATSextern_fun(ats_uint_type, atspre_lnot_uint) (ats_uint_type) ;
ATSextern_fun(ats_uint_type, atspre_land_uint_uint) (ats_uint_type, ats_uint_type) ;
ATSextern_fun(ats_uint_type, atspre_lor_uint_uint) (ats_uint_type, ats_uint_type) ;
ATSextern_fun(ats_void_type, atspre_fprint_string) (ats_ptr_type, ats_ptr_type) ;
ATSextern_fun(ats_void_type, atspre_fprintf_exn) (ats_ptr_type, ats_ptr_type, ...) ;
ATSextern_fun(ats_bool_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_fltkind) (ats_int_type) ;
ATSextern_fun(ats_void_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funclo) (ats_ptr_type, ats_ptr_type) ;
ATSextern_fun(ats_bool_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__eq_funclo_funclo) (ats_ptr_type, ats_ptr_type) ;

/* external dynamic terminating constant declarations */
#ifdef _ATS_PROOFCHECK
#endif /* _ATS_PROOFCHECK */

/* assuming abstract types */
/* sum constructor declarations */
/* exn constructor declarations */
/* global dynamic (non-functional) constant declarations */
ATSglobal(ats_int_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__VIEWT0YPE_knd) ;

/* internal function declarations */

/* partial value template declarations */
/* static temporary variable declarations */
ATSstatic (ats_int_type, statmp61) ;
// ATSstatic_void (statmp62) ;
// ATSstatic_void (statmp63) ;

/* external value variable declarations */

/* function implementations */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 1582(line=49, offs=14) -- 1697(line=54, offs=4)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_fltkind (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp0) ;
ATSlocal (ats_int_type, tmp1) ;
ATSlocal (ats_uint_type, tmp2) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_fltkind:
tmp1 = atspre_asl_int_int1 (1, 0) ;
tmp2 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg0), ats_castfn_mac(ats_uint_type, tmp1)) ;
tmp0 = atspre_gt_uint_uint (tmp2, 0u) ;
return (tmp0) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_fltkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 1747(line=57, offs=14) -- 1799(line=58, offs=45)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_boxkind (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp3) ;
ATSlocal (ats_bool_type, tmp4) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_boxkind:
tmp4 = _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_fltkind (arg0) ;
if (tmp4) {
tmp3 = ats_false_bool ;
} else {
tmp3 = ats_true_bool ;
} /* end of [if] */
return (tmp3) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_boxkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 1849(line=62, offs=14) -- 1964(line=67, offs=4)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_linkind (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp5) ;
ATSlocal (ats_int_type, tmp6) ;
ATSlocal (ats_uint_type, tmp7) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_linkind:
tmp6 = atspre_asl_int_int1 (1, 1) ;
tmp7 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg0), ats_castfn_mac(ats_uint_type, tmp6)) ;
tmp5 = atspre_gt_uint_uint (tmp7, 0u) ;
return (tmp5) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_linkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 2014(line=70, offs=14) -- 2129(line=75, offs=4)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_prfkind (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp8) ;
ATSlocal (ats_int_type, tmp9) ;
ATSlocal (ats_uint_type, tmp10) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_prfkind:
tmp9 = atspre_asl_int_int1 (1, 2) ;
tmp10 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg0), ats_castfn_mac(ats_uint_type, tmp9)) ;
tmp8 = atspre_gt_uint_uint (tmp10, 0u) ;
return (tmp8) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_prfkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 2180(line=78, offs=15) -- 2295(line=83, offs=4)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_prgmkind (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp11) ;
ATSlocal (ats_int_type, tmp12) ;
ATSlocal (ats_uint_type, tmp13) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_prgmkind:
tmp12 = atspre_asl_int_int1 (1, 2) ;
tmp13 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg0), ats_castfn_mac(ats_uint_type, tmp12)) ;
tmp11 = atspre_eq_uint_uint (tmp13, 0u) ;
return (tmp11) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_prgmkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 2346(line=86, offs=14) -- 2524(line=92, offs=4)
*/
ATSglobaldec()
ats_int_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_polkind (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_int_type, tmp14) ;
ATSlocal (ats_int_type, tmp15) ;
ATSlocal (ats_uint_type, tmp16) ;
ATSlocal (ats_bool_type, tmp17) ;
ATSlocal (ats_bool_type, tmp18) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_polkind:
tmp15 = atspre_asl_int_int1 (3, 3) ;
tmp16 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg0), ats_castfn_mac(ats_uint_type, tmp15)) ;
tmp17 = atspre_eq_uint_uint (tmp16, 0u) ;
if (tmp17) {
tmp14 = 0 ;
} else {
tmp18 = atspre_lt_uint_uint (tmp16, ats_castfn_mac(ats_uint_type, tmp15)) ;
if (tmp18) {
tmp14 = 1 ;
} else {
tmp14 = -1 ;
} /* end of [if] */
} /* end of [if] */
return (tmp14) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__test_polkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 2600(line=97, offs=19) -- 2716(line=102, offs=4)
*/
ATSglobaldec()
ats_int_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__impkind_linearize (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_int_type, tmp19) ;
ATSlocal (ats_int_type, tmp20) ;
ATSlocal (ats_uint_type, tmp21) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__impkind_linearize:
tmp20 = atspre_asl_int_int1 (1, 1) ;
tmp21 = atspre_lor_uint_uint (ats_castfn_mac(ats_uint_type, arg0), ats_castfn_mac(ats_uint_type, tmp20)) ;
tmp19 = ats_castfn_mac(ats_int_type, tmp21) ;
return (tmp19) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__impkind_linearize] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 2777(line=105, offs=20) -- 2895(line=110, offs=4)
*/
ATSglobaldec()
ats_int_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__impkind_neutralize (ats_int_type arg0) {
/* local vardec */
ATSlocal (ats_int_type, tmp22) ;
ATSlocal (ats_int_type, tmp23) ;
ATSlocal (ats_uint_type, tmp24) ;
ATSlocal (ats_uint_type, tmp25) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__impkind_neutralize:
tmp23 = atspre_asl_int_int1 (3, 3) ;
tmp25 = atspre_lnot_uint (ats_castfn_mac(ats_uint_type, tmp23)) ;
tmp24 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg0), tmp25) ;
tmp22 = ats_castfn_mac(ats_int_type, tmp24) ;
return (tmp22) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__impkind_neutralize] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 2979(line=115, offs=21) -- 3187(line=122, offs=4)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__lte_impkind_impkind (ats_int_type arg0, ats_int_type arg1) {
/* local vardec */
ATSlocal (ats_bool_type, tmp26) ;
ATSlocal (ats_int_type, tmp27) ;
ATSlocal (ats_uint_type, tmp28) ;
ATSlocal (ats_uint_type, tmp29) ;
ATSlocal (ats_uint_type, tmp30) ;
ATSlocal (ats_uint_type, tmp31) ;
ATSlocal (ats_uint_type, tmp32) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__lte_impkind_impkind:
tmp27 = atspre_asl_int_int1 (3, 3) ;
tmp28 = atspre_lnot_uint (ats_castfn_mac(ats_uint_type, tmp27)) ;
tmp29 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg0), tmp28) ;
tmp30 = atspre_land_uint_uint (ats_castfn_mac(ats_uint_type, arg1), tmp28) ;
tmp32 = atspre_lnot_uint (tmp30) ;
tmp31 = atspre_land_uint_uint (tmp29, tmp32) ;
tmp26 = atspre_eq_uint_uint (tmp31, 0u) ;
return (tmp26) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__lte_impkind_impkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 3269(line=128, offs=3) -- 3446(line=132, offs=51)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_caskind (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
// ATSlocal_void (tmp33) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_caskind:
do {
/* branch: __ats_lab_0 */
__ats_lab_0_0:
if (((ats_sum_ptr_type)arg1)->tag != 0) { goto __ats_lab_1_0 ; }
__ats_lab_0_1:
/* tmp33 = */ atspre_fprint_string (arg0, ATSstrcst("case")) ;
break ;

/* branch: __ats_lab_1 */
__ats_lab_1_0:
if (((ats_sum_ptr_type)arg1)->tag != 1) { goto __ats_lab_2_0 ; }
__ats_lab_1_1:
/* tmp33 = */ atspre_fprint_string (arg0, ATSstrcst("case+")) ;
break ;

/* branch: __ats_lab_2 */
__ats_lab_2_0:
// if (((ats_sum_ptr_type)arg1)->tag != 2) { ats_deadcode_failure_handle () ; }
__ats_lab_2_1:
/* tmp33 = */ atspre_fprint_string (arg0, ATSstrcst("case-")) ;
break ;
} while (0) ;
return /* (tmp33) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_caskind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 3527(line=139, offs=3) -- 3640(line=148, offs=4)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_proof (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp34) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_proof:
do {
/* branch: __ats_lab_3 */
__ats_lab_3_0:
if (((ats_sum_ptr_type)arg0)->tag != 3) { goto __ats_lab_4_0 ; }
__ats_lab_3_1:
tmp34 = ats_true_bool ;
break ;

/* branch: __ats_lab_4 */
__ats_lab_4_0:
if (((ats_sum_ptr_type)arg0)->tag != 4) { goto __ats_lab_5_0 ; }
__ats_lab_4_1:
tmp34 = ats_true_bool ;
break ;

/* branch: __ats_lab_5 */
__ats_lab_5_0:
if (((ats_sum_ptr_type)arg0)->tag != 5) { goto __ats_lab_6_0 ; }
__ats_lab_5_1:
tmp34 = ats_true_bool ;
break ;

/* branch: __ats_lab_6 */
__ats_lab_6_0:
__ats_lab_6_1:
tmp34 = ats_false_bool ;
break ;
} while (0) ;
return (tmp34) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_proof] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 3704(line=152, offs=3) -- 3837(line=162, offs=4)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_recursive (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp35) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_recursive:
do {
/* branch: __ats_lab_7 */
__ats_lab_7_0:
if (((ats_sum_ptr_type)arg0)->tag != 1) { goto __ats_lab_8_0 ; }
__ats_lab_7_1:
tmp35 = ats_true_bool ;
break ;

/* branch: __ats_lab_8 */
__ats_lab_8_0:
if (((ats_sum_ptr_type)arg0)->tag != 2) { goto __ats_lab_9_0 ; }
__ats_lab_8_1:
tmp35 = ats_true_bool ;
break ;

/* branch: __ats_lab_9 */
__ats_lab_9_0:
if (((ats_sum_ptr_type)arg0)->tag != 4) { goto __ats_lab_10_0 ; }
__ats_lab_9_1:
tmp35 = ats_true_bool ;
break ;

/* branch: __ats_lab_10 */
__ats_lab_10_0:
if (((ats_sum_ptr_type)arg0)->tag != 6) { goto __ats_lab_11_0 ; }
__ats_lab_10_1:
tmp35 = ats_true_bool ;
break ;

/* branch: __ats_lab_11 */
__ats_lab_11_0:
__ats_lab_11_1:
tmp35 = ats_false_bool ;
break ;
} while (0) ;
return (tmp35) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_recursive] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 3905(line=166, offs=3) -- 3954(line=166, offs=52)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_mutailrec (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp36) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_mutailrec:
do {
/* branch: __ats_lab_12 */
__ats_lab_12_0:
if (((ats_sum_ptr_type)arg0)->tag != 1) { goto __ats_lab_13_0 ; }
__ats_lab_12_1:
tmp36 = ats_true_bool ;
break ;

/* branch: __ats_lab_13 */
__ats_lab_13_0:
__ats_lab_13_1:
tmp36 = ats_false_bool ;
break ;
} while (0) ;
return (tmp36) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funkind_is_mutailrec] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 4016(line=171, offs=3) -- 4390(line=187, offs=4)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funkind (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
// ATSlocal_void (tmp37) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funkind:
do {
/* branch: __ats_lab_14 */
__ats_lab_14_0:
if (((ats_sum_ptr_type)arg1)->tag != 0) { goto __ats_lab_15_0 ; }
__ats_lab_14_1:
/* tmp37 = */ atspre_fprint_string (arg0, ATSstrcst("fn")) ;
break ;

/* branch: __ats_lab_15 */
__ats_lab_15_0:
if (((ats_sum_ptr_type)arg1)->tag != 1) { goto __ats_lab_16_0 ; }
__ats_lab_15_1:
/* tmp37 = */ atspre_fprint_string (arg0, ATSstrcst("fnx")) ;
break ;

/* branch: __ats_lab_16 */
__ats_lab_16_0:
if (((ats_sum_ptr_type)arg1)->tag != 2) { goto __ats_lab_17_0 ; }
__ats_lab_16_1:
/* tmp37 = */ atspre_fprint_string (arg0, ATSstrcst("fun")) ;
break ;

/* branch: __ats_lab_17 */
__ats_lab_17_0:
if (((ats_sum_ptr_type)arg1)->tag != 3) { goto __ats_lab_18_0 ; }
__ats_lab_17_1:
/* tmp37 = */ atspre_fprint_string (arg0, ATSstrcst("prfn")) ;
break ;

/* branch: __ats_lab_18 */
__ats_lab_18_0:
if (((ats_sum_ptr_type)arg1)->tag != 4) { goto __ats_lab_19_0 ; }
__ats_lab_18_1:
/* tmp37 = */ atspre_fprint_string (arg0, ATSstrcst("prfun")) ;
break ;

/* branch: __ats_lab_19 */
__ats_lab_19_0:
if (((ats_sum_ptr_type)arg1)->tag != 5) { goto __ats_lab_20_0 ; }
__ats_lab_19_1:
/* tmp37 = */ atspre_fprint_string (arg0, ATSstrcst("praxi")) ;
break ;

/* branch: __ats_lab_20 */
__ats_lab_20_0:
// if (((ats_sum_ptr_type)arg1)->tag != 6) { ats_deadcode_failure_handle () ; }
__ats_lab_20_1:
/* tmp37 = */ atspre_fprint_string (arg0, ATSstrcst("castfn")) ;
break ;
} while (0) ;
return /* (tmp37) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 4467(line=192, offs=18) -- 4520(line=193, offs=47)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__valkind_is_proof (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp38) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__valkind_is_proof:
do {
/* branch: __ats_lab_21 */
__ats_lab_21_0:
if (((ats_sum_ptr_type)arg0)->tag != 1) { goto __ats_lab_22_0 ; }
__ats_lab_21_1:
tmp38 = ats_true_bool ;
break ;

/* branch: __ats_lab_22 */
__ats_lab_22_0:
__ats_lab_22_1:
tmp38 = ats_false_bool ;
break ;
} while (0) ;
return (tmp38) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__valkind_is_proof] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 4576(line=197, offs=16) -- 4789(line=201, offs=48)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_valkind (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
// ATSlocal_void (tmp39) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_valkind:
do {
/* branch: __ats_lab_23 */
__ats_lab_23_0:
if (((ats_sum_ptr_type)arg1)->tag != 0) { goto __ats_lab_24_0 ; }
__ats_lab_23_1:
/* tmp39 = */ atspre_fprint_string (arg0, ATSstrcst("val")) ;
break ;

/* branch: __ats_lab_24 */
__ats_lab_24_0:
if (((ats_sum_ptr_type)arg1)->tag != 2) { goto __ats_lab_25_0 ; }
__ats_lab_24_1:
/* tmp39 = */ atspre_fprint_string (arg0, ATSstrcst("val+")) ;
break ;

/* branch: __ats_lab_25 */
__ats_lab_25_0:
if (((ats_sum_ptr_type)arg1)->tag != 3) { goto __ats_lab_26_0 ; }
__ats_lab_25_1:
/* tmp39 = */ atspre_fprint_string (arg0, ATSstrcst("val-")) ;
break ;

/* branch: __ats_lab_26 */
__ats_lab_26_0:
// if (((ats_sum_ptr_type)arg1)->tag != 1) { ats_deadcode_failure_handle () ; }
__ats_lab_26_1:
/* tmp39 = */ atspre_fprint_string (arg0, ATSstrcst("prval")) ;
break ;
} while (0) ;
return /* (tmp39) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_valkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 4867(line=208, offs=3) -- 5042(line=212, offs=36)
*/
ATSglobaldec()
ats_ptr_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__valkind2caskind (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_ptr_type, tmp40) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__valkind2caskind:
do {
/* branch: __ats_lab_27 */
__ats_lab_27_0:
if (((ats_sum_ptr_type)arg0)->tag != 0) { goto __ats_lab_28_0 ; }
__ats_lab_27_1:
tmp40 = (ats_sum_ptr_type)(&_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__CK_case_0) ;
break ;

/* branch: __ats_lab_28 */
__ats_lab_28_0:
if (((ats_sum_ptr_type)arg0)->tag != 1) { goto __ats_lab_29_0 ; }
__ats_lab_28_1:
tmp40 = (ats_sum_ptr_type)(&_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__CK_case_pos_1) ;
break ;

/* branch: __ats_lab_29 */
__ats_lab_29_0:
if (((ats_sum_ptr_type)arg0)->tag != 2) { goto __ats_lab_30_0 ; }
__ats_lab_29_1:
tmp40 = (ats_sum_ptr_type)(&_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__CK_case_pos_1) ;
break ;

/* branch: __ats_lab_30 */
__ats_lab_30_0:
// if (((ats_sum_ptr_type)arg0)->tag != 3) { ats_deadcode_failure_handle () ; }
__ats_lab_30_1:
tmp40 = (ats_sum_ptr_type)(&_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__CK_case_neg_2) ;
break ;
} while (0) ;
return (tmp40) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__valkind2caskind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 5121(line=218, offs=17) -- 5170(line=219, offs=44)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_fun (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp41) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_fun:
do {
/* branch: __ats_lab_31 */
__ats_lab_31_0:
if (((ats_sum_ptr_type)arg0)->tag != 0) { goto __ats_lab_32_0 ; }
__ats_lab_31_1:
tmp41 = ats_true_bool ;
break ;

/* branch: __ats_lab_32 */
__ats_lab_32_0:
__ats_lab_32_1:
tmp41 = ats_false_bool ;
break ;
} while (0) ;
return (tmp41) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_fun] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 5226(line=223, offs=17) -- 5275(line=224, offs=44)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_val (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp42) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_val:
do {
/* branch: __ats_lab_33 */
__ats_lab_33_0:
if (((ats_sum_ptr_type)arg0)->tag != 1) { goto __ats_lab_34_0 ; }
__ats_lab_33_1:
tmp42 = ats_true_bool ;
break ;

/* branch: __ats_lab_34 */
__ats_lab_34_0:
__ats_lab_34_1:
tmp42 = ats_false_bool ;
break ;
} while (0) ;
return (tmp42) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_val] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 5333(line=228, offs=19) -- 5384(line=229, offs=46)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_prfun (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp43) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_prfun:
do {
/* branch: __ats_lab_35 */
__ats_lab_35_0:
if (((ats_sum_ptr_type)arg0)->tag != 3) { goto __ats_lab_36_0 ; }
__ats_lab_35_1:
tmp43 = ats_true_bool ;
break ;

/* branch: __ats_lab_36 */
__ats_lab_36_0:
__ats_lab_36_1:
tmp43 = ats_false_bool ;
break ;
} while (0) ;
return (tmp43) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_prfun] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 5444(line=233, offs=19) -- 5495(line=234, offs=46)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_prval (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp44) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_prval:
do {
/* branch: __ats_lab_37 */
__ats_lab_37_0:
if (((ats_sum_ptr_type)arg0)->tag != 4) { goto __ats_lab_38_0 ; }
__ats_lab_37_1:
tmp44 = ats_true_bool ;
break ;

/* branch: __ats_lab_38 */
__ats_lab_38_0:
__ats_lab_38_1:
tmp44 = ats_false_bool ;
break ;
} while (0) ;
return (tmp44) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_prval] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 5555(line=238, offs=19) -- 5658(line=241, offs=15)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_proof (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp45) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_proof:
do {
/* branch: __ats_lab_39 */
__ats_lab_39_0:
if (((ats_sum_ptr_type)arg0)->tag != 2) { goto __ats_lab_40_0 ; }
__ats_lab_39_1:
tmp45 = ats_true_bool ;
break ;

/* branch: __ats_lab_40 */
__ats_lab_40_0:
if (((ats_sum_ptr_type)arg0)->tag != 3) { goto __ats_lab_41_0 ; }
__ats_lab_40_1:
tmp45 = ats_true_bool ;
break ;

/* branch: __ats_lab_41 */
__ats_lab_41_0:
if (((ats_sum_ptr_type)arg0)->tag != 4) { goto __ats_lab_42_0 ; }
__ats_lab_41_1:
tmp45 = ats_true_bool ;
break ;

/* branch: __ats_lab_42 */
__ats_lab_42_0:
__ats_lab_42_1:
tmp45 = ats_false_bool ;
break ;
} while (0) ;
return (tmp45) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_proof] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 5719(line=245, offs=20) -- 5771(line=246, offs=47)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_castfn (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp46) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_castfn:
do {
/* branch: __ats_lab_43 */
__ats_lab_43_0:
if (((ats_sum_ptr_type)arg0)->tag != 5) { goto __ats_lab_44_0 ; }
__ats_lab_43_1:
tmp46 = ats_true_bool ;
break ;

/* branch: __ats_lab_44 */
__ats_lab_44_0:
__ats_lab_44_1:
tmp46 = ats_false_bool ;
break ;
} while (0) ;
return (tmp46) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__dcstkind_is_castfn] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 5853(line=253, offs=3) -- 6186(line=259, offs=55)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_dcstkind (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
// ATSlocal_void (tmp47) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_dcstkind:
do {
/* branch: __ats_lab_45 */
__ats_lab_45_0:
if (((ats_sum_ptr_type)arg1)->tag != 0) { goto __ats_lab_46_0 ; }
__ats_lab_45_1:
/* tmp47 = */ atspre_fprint_string (arg0, ATSstrcst("DCKfun()")) ;
break ;

/* branch: __ats_lab_46 */
__ats_lab_46_0:
if (((ats_sum_ptr_type)arg1)->tag != 1) { goto __ats_lab_47_0 ; }
__ats_lab_46_1:
/* tmp47 = */ atspre_fprint_string (arg0, ATSstrcst("DCKval()")) ;
break ;

/* branch: __ats_lab_47 */
__ats_lab_47_0:
if (((ats_sum_ptr_type)arg1)->tag != 2) { goto __ats_lab_48_0 ; }
__ats_lab_47_1:
/* tmp47 = */ atspre_fprint_string (arg0, ATSstrcst("DCKpraxi()")) ;
break ;

/* branch: __ats_lab_48 */
__ats_lab_48_0:
if (((ats_sum_ptr_type)arg1)->tag != 3) { goto __ats_lab_49_0 ; }
__ats_lab_48_1:
/* tmp47 = */ atspre_fprint_string (arg0, ATSstrcst("DCKprfun()")) ;
break ;

/* branch: __ats_lab_49 */
__ats_lab_49_0:
if (((ats_sum_ptr_type)arg1)->tag != 4) { goto __ats_lab_50_0 ; }
__ats_lab_49_1:
/* tmp47 = */ atspre_fprint_string (arg0, ATSstrcst("DCKprval()")) ;
break ;

/* branch: __ats_lab_50 */
__ats_lab_50_0:
// if (((ats_sum_ptr_type)arg1)->tag != 5) { ats_deadcode_failure_handle () ; }
__ats_lab_50_1:
/* tmp47 = */ atspre_fprint_string (arg0, ATSstrcst("DCKcastfn()")) ;
break ;
} while (0) ;
return /* (tmp47) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_dcstkind] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 6261(line=265, offs=15) -- 6335(line=267, offs=54)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funclo_is_ptr (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp48) ;
ATSlocal (ats_int_type, tmp49) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funclo_is_ptr:
do {
/* branch: __ats_lab_51 */
__ats_lab_51_0:
if (arg0 == (ats_sum_ptr_type)0) { goto __ats_lab_52_0 ; }
__ats_lab_51_1:
tmp49 = ats_caselptrlab_mac(anairiats_sum_0, arg0, atslab_0) ;
tmp48 = atspre_neq_int_int (tmp49, 0) ;
break ;

/* branch: __ats_lab_52 */
__ats_lab_52_0:
// if (arg0 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_52_1:
tmp48 = ats_true_bool ;
break ;
} while (0) ;
return (tmp48) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funclo_is_ptr] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 6390(line=271, offs=18) -- 6465(line=273, offs=55)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funclo_is_cloptr (ats_ptr_type arg0) {
/* local vardec */
ATSlocal (ats_bool_type, tmp50) ;
ATSlocal (ats_int_type, tmp51) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funclo_is_cloptr:
do {
/* branch: __ats_lab_53 */
__ats_lab_53_0:
if (arg0 == (ats_sum_ptr_type)0) { goto __ats_lab_54_0 ; }
__ats_lab_53_1:
tmp51 = ats_caselptrlab_mac(anairiats_sum_0, arg0, atslab_0) ;
tmp50 = atspre_neq_int_int (tmp51, 0) ;
break ;

/* branch: __ats_lab_54 */
__ats_lab_54_0:
// if (arg0 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_54_1:
tmp50 = ats_false_bool ;
break ;
} while (0) ;
return (tmp50) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__funclo_is_cloptr] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 6546(line=280, offs=3) -- 6691(line=283, offs=20)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__eq_funclo_funclo (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
ATSlocal (ats_bool_type, tmp52) ;
ATSlocal (ats_int_type, tmp53) ;
ATSlocal (ats_int_type, tmp54) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__eq_funclo_funclo:
do {
/* branch: __ats_lab_55 */
__ats_lab_55_0:
if (arg0 == (ats_sum_ptr_type)0) { goto __ats_lab_56_0 ; }
__ats_lab_55_1:
if (arg1 == (ats_sum_ptr_type)0) { goto __ats_lab_57_1 ; }
__ats_lab_55_2:
tmp53 = ats_caselptrlab_mac(anairiats_sum_0, arg0, atslab_0) ;
tmp54 = ats_caselptrlab_mac(anairiats_sum_0, arg1, atslab_0) ;
tmp52 = atspre_eq_int_int (tmp53, tmp54) ;
break ;

/* branch: __ats_lab_56 */
__ats_lab_56_0:
if (arg0 != (ats_sum_ptr_type)0) { goto __ats_lab_57_0 ; }
__ats_lab_56_1:
if (arg1 != (ats_sum_ptr_type)0) { goto __ats_lab_57_1 ; }
__ats_lab_56_2:
tmp52 = ats_true_bool ;
break ;

/* branch: __ats_lab_57 */
__ats_lab_57_0:
__ats_lab_57_1:
__ats_lab_57_2:
tmp52 = ats_false_bool ;
break ;
} while (0) ;
return (tmp52) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__eq_funclo_funclo] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 6750(line=287, offs=19) -- 6791(line=287, offs=60)
*/
ATSglobaldec()
ats_bool_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__neq_funclo_funclo (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
ATSlocal (ats_bool_type, tmp55) ;
ATSlocal (ats_bool_type, tmp56) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__neq_funclo_funclo:
tmp56 = _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__eq_funclo_funclo (arg0, arg1) ;
tmp55 = atspre_neg_bool (tmp56) ;
return (tmp55) ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__neq_funclo_funclo] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 6840(line=293, offs=3) -- 6971(line=296, offs=46)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funclo (ats_ptr_type arg0, ats_ptr_type arg1) {
/* local vardec */
// ATSlocal_void (tmp57) ;
ATSlocal (ats_int_type, tmp58) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funclo:
do {
/* branch: __ats_lab_58 */
__ats_lab_58_0:
if (arg1 == (ats_sum_ptr_type)0) { goto __ats_lab_59_0 ; }
__ats_lab_58_1:
tmp58 = ats_caselptrlab_mac(anairiats_sum_0, arg1, atslab_0) ;
/* tmp57 = */ atspre_fprintf_exn (arg0, ATSstrcst("CLO(%i)"), tmp58) ;
break ;

/* branch: __ats_lab_59 */
__ats_lab_59_0:
// if (arg1 != (ats_sum_ptr_type)0) { ats_deadcode_failure_handle () ; }
__ats_lab_59_1:
/* tmp57 = */ atspre_fprintf_exn (arg0, ATSstrcst("FUN")) ;
break ;
} while (0) ;
return /* (tmp57) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funclo] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 7022(line=299, offs=24) -- 7059(line=299, offs=61)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__print_funclo (ats_ptr_type arg0) {
/* local vardec */
// ATSlocal_void (tmp59) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__print_funclo:
/* tmp59 = */ _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funclo (stdout, arg0) ;
return /* (tmp59) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__print_funclo] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 7083(line=300, offs=24) -- 7120(line=300, offs=61)
*/
ATSglobaldec()
ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__prerr_funclo (ats_ptr_type arg0) {
/* local vardec */
// ATSlocal_void (tmp60) ;

__ats_lab__2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__prerr_funclo:
/* tmp60 = */ _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__fprint_funclo (stderr, arg0) ;
return /* (tmp60) */ ;
} /* end of [_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__prerr_funclo] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 7349(line=315, offs=16) -- 7408(line=317, offs=4)
*/
ATSglobaldec()
ats_int_type
patsopt_debug_flag_get () {
/* local vardec */
ATSlocal (ats_int_type, tmp64) ;

__ats_lab_patsopt_debug_flag_get:
tmp64 = ats_ptrget_mac(ats_int_type, (&statmp61)) ;
return (tmp64) ;
} /* end of [patsopt_debug_flag_get] */

/*
// /home/hwxi/research/Postiats/git/src/pats_basics.dats: 7462(line=320, offs=16) -- 7527(line=322, offs=4)
*/
ATSglobaldec()
ats_void_type
patsopt_debug_flag_set (ats_int_type arg0) {
/* local vardec */
// ATSlocal_void (tmp65) ;

__ats_lab_patsopt_debug_flag_set:
ats_ptrget_mac(ats_int_type, (&statmp61)) = arg0 ;
return /* (tmp65) */ ;
} /* end of [patsopt_debug_flag_set] */

/* static load function */

extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__staload (void) ;

ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__staload () {
static int _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__staload_flag = 0 ;
if (_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__staload_flag) return ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__staload_flag = 1 ;

_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__staload () ;

return ;
} /* staload function */

/* dynamic load function */

// dynload flag declaration
extern ats_int_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__dynload_flag ;

ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__dynload () {
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__dynload_flag = 1 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2edats__staload () ;

#ifdef _ATS_PROOFCHECK
#endif /* _ATS_PROOFCHECK */

/* marking static variables for GC */
ATS_GC_MARKROOT(&statmp61, sizeof(ats_int_type)) ;

/* marking external values for GC */

/* code for dynamic loading */
ATS_GC_MARKROOT(&_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__VIEWT0YPE_knd, sizeof(ats_int_type)) ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__VIEWT0YPE_knd = 3 ;
/* ats_int_type statmp61 ; */
statmp61 = 1 ;
/* statmp62 = */ atspre_vbox_make_view_ptr ((&statmp61)) ;
/* statmp63 = ats_selsin_mac(statmp62, atslab_1) */ ;
return ;
} /* end of [dynload function] */

/* external codes at mid */
/* external codes at bot */


ats_void_type
patsopt_vfprintf_ifdebug (
  ats_ptr_type out
, ats_ptr_type fmt
, va_list ap // variadic arguments
) {
//
  if (patsopt_debug_flag_get () > 0) {
    (void)vfprintf((FILE*)out, (char*)fmt, ap) ;
  } // end of [if]
//
  return ;
} // end of [patsopt_debug_printf]

ats_void_type
patsopt_prerrf_ifdebug (
  ats_ptr_type fmt, ...
) {
  va_list ap ;
  va_start(ap, fmt) ;
  patsopt_vfprintf_ifdebug(stderr, (char*)fmt, ap) ;
  va_end(ap) ;
  return ;
} // end of [patsopt_debug_prerrf]



/* ****** ****** */

/* end of [pats_basics_dats.c] */
