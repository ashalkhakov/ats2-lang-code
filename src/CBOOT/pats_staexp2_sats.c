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
/* external codes at top */
/* type definitions */
typedef
struct {
ats_ptr_type atslab_s2qua_svs ;
ats_ptr_type atslab_s2qua_sps ;
} anairiats_rec_0 ;

/* external typedefs */
/* assuming abstract types */
/* sum constructor declarations */
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTBASpre_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTBASimp_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTBASdef_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTbas_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTfun_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTtup_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTVar_3) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTerr_4) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMvar_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMcst_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMe1xp_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMdatcontyp_3) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMdatconptr_4) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMfilenv_5) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDbox_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDbox_lin_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDflt0_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDflt1_3) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDflt_ext_4) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTnil_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTcons_invar_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTcons_trans_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTcons_none_3) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SLABELED_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2TEsrt_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2TEsub_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2TEerr_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EFFset_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EFFexp_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EFFadd_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2LABlab_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2LABind_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eint_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eintinf_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ecst_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eextype_3) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eextkind_4) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Evar_5) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EVar_6) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ehole_7) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Edatcontyp_8) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Edatconptr_9) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eat_10) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Esizeof_11) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eeff_12) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eeqeq_13) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eproj_14) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eapp_15) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Elam_16) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Efun_17) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Emetfun_18) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Emetdec_19) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Etop_20) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ewithout_21) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Etyarr_22) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Etyrec_23) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Einvar_24) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eexi_25) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Euni_26) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Erefarg_27) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Evararg_28) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ewth_29) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eerr_30) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SP2Tcon_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SP2Terr_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SKLABELED_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEany_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEcst_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEvar_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEextype_3) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEextkind_4) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEfun_5) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEapp_6) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEtyarr_7) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEtyrec_8) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SZLABELED_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEprf_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEptr_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEcst_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEvar_3) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEVar_4) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEextype_5) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEextkind_6) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEapp_7) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEtyarr_8) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEtyrec_9) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEclo_10) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEbot_11) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2VARARGone_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2VARARGall_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2VARARGseq_2) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EXPARGone_0) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EXPARGall_1) ;
ATSglobal(ats_sum_type, _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EXPARGseq_2) ;

/* exn constructor declarations */
/* static load function */

extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_intinf_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_counter_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_stamp_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_symbol_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_label_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_location_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_filename_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_syntax_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_effect_2esats__staload (void) ;
extern ats_void_type _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp1_2esats__staload (void) ;

ats_void_type
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__staload () {
static int _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__staload_flag = 0 ;
if (_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__staload_flag) return ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__staload_flag = 1 ;

_2home_2hwxi_2research_2Postiats_2git_2src_2pats_intinf_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_counter_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_stamp_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_symbol_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_label_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_location_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_filename_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_syntax_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_basics_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_effect_2esats__staload () ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp1_2esats__staload () ;

// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTBASpre_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTBASimp_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTBASdef_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTbas_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTfun_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTtup_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTVar_3.tag = 3 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2RTerr_4.tag = 4 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMvar_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMcst_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMe1xp_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMdatcontyp_3.tag = 3 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMdatconptr_4.tag = 4 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ITMfilenv_5.tag = 5 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDbox_0.tag = 0 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDbox_lin_1.tag = 1 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDflt0_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDflt1_3.tag = 3 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__TYRECKINDflt_ext_4.tag = 4 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTnil_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTcons_invar_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTcons_trans_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__WTHS2EXPLSTcons_none_3.tag = 3 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SLABELED_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2TEsrt_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2TEsub_1.tag = 1 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2TEerr_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EFFset_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EFFexp_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EFFadd_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2LABlab_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2LABind_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eint_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eintinf_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ecst_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eextype_3.tag = 3 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eextkind_4.tag = 4 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Evar_5.tag = 5 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EVar_6.tag = 6 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ehole_7.tag = 7 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Edatcontyp_8.tag = 8 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Edatconptr_9.tag = 9 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eat_10.tag = 10 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Esizeof_11.tag = 11 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eeff_12.tag = 12 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eeqeq_13.tag = 13 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eproj_14.tag = 14 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eapp_15.tag = 15 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Elam_16.tag = 16 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Efun_17.tag = 17 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Emetfun_18.tag = 18 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Emetdec_19.tag = 19 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Etop_20.tag = 20 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ewithout_21.tag = 21 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Etyarr_22.tag = 22 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Etyrec_23.tag = 23 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Einvar_24.tag = 24 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eexi_25.tag = 25 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Euni_26.tag = 26 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Erefarg_27.tag = 27 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Evararg_28.tag = 28 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Ewth_29.tag = 29 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2Eerr_30.tag = 30 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SP2Tcon_0.tag = 0 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SP2Terr_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SKLABELED_0.tag = 0 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEany_0.tag = 0 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEcst_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEvar_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEextype_3.tag = 3 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEextkind_4.tag = 4 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEfun_5.tag = 5 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEapp_6.tag = 6 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEtyarr_7.tag = 7 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2KEtyrec_8.tag = 8 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__SZLABELED_0.tag = 0 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEprf_0.tag = 0 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEptr_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEcst_2.tag = 2 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEvar_3.tag = 3 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEVar_4.tag = 4 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEextype_5.tag = 5 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEextkind_6.tag = 6 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEapp_7.tag = 7 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEtyarr_8.tag = 8 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEtyrec_9.tag = 9 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEclo_10.tag = 10 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2ZEbot_11.tag = 11 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2VARARGone_0.tag = 0 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2VARARGall_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2VARARGseq_2.tag = 2 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EXPARGone_0.tag = 0 ;
_2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EXPARGall_1.tag = 1 ;
// _2home_2hwxi_2research_2Postiats_2git_2src_2pats_staexp2_2esats__S2EXPARGseq_2.tag = 2 ;
return ;
} /* staload function */

/* external codes at mid */
/* external codes at bot */

/* ****** ****** */

/* end of [pats_staexp2_sats.c] */
