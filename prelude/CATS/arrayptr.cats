/***********************************************************************/
/*                                                                     */
/*                         Applied Type System                         */
/*                                                                     */
/***********************************************************************/

/* (*
** ATS/Postiats - Unleashing the Potential of Types!
** Copyright (C) 2011-2012 Hongwei Xi, ATS Trustful Software, Inc.
** All rights reserved
**
** ATS is free software;  you can  redistribute it and/or modify it under
** the terms of the GNU LESSER GENERAL PUBLIC LICENSE as published by the
** Free Software Foundation; either version 2.1, or (at your option)  any
** later version.
**
** ATS is distributed in the hope that it will be useful, but WITHOUT ANY
** WARRANTY; without  even  the  implied  warranty  of MERCHANTABILITY or
** FITNESS FOR A PARTICULAR PURPOSE.  See the  GNU General Public License
** for more details.
**
** You  should  have  received  a  copy of the GNU General Public License
** along  with  ATS;  see the  file COPYING.  If not, please write to the
** Free Software Foundation,  51 Franklin Street, Fifth Floor, Boston, MA
** 02110-1301, USA.
*) */

/* ****** ****** */

/*
** Source:
** $PATSHOME/prelude/CATS/CODEGEN/arrayptr.atxt
** Time of generation: Sat Jul 27 22:06:35 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: January, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_PRELUDE_ARRAYPTR_CATS
#define ATSLIB_PRELUDE_ARRAYPTR_CATS

/* ****** ****** */

ATSinline()
atstype_arrptr
atspre_arrpsz_get_ptrsize
(
  atstype_arrpsz psz, atstype_ref asz
) {
  *(size_t*)asz = psz.size ; return (psz.ptr) ;
} // en of [atspre_arrpsz_get_ptrsize]

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_arrayptr_free
  (atstype_arrptr p0) { ATS_MFREE (p0) ; return ; }
// end of [atspre_arrayptr_free]

/* ****** ****** */

ATSinline()
atstype_arrptr
atspre_arrayptr_make_arrpsz
  (atstype_arrpsz psz) { return (psz).ptr ; }
// end of [atspre_arrayptr_make_arrpsz]

/* ****** ****** */

#endif // ifndef ATSLIB_PRELUDE_ARRAYPTR_CATS

/* ****** ****** */

/* end of [arrayptr.cats] */
