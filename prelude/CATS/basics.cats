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
** $PATSHOME/prelude/CATS/CODEGEN/basics.atxt
** Time of generation: Sat Jul 27 22:06:35 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: January, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_PRELUDE_BASICS_CATS
#define ATSLIB_PRELUDE_BASICS_CATS

/* ****** ****** */

#include <stdio.h>
#include <stdlib.h>

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_cloptr_free
(
  atstype_cloptr pclo
) {
  ATS_MFREE (pclo) ; return ;
} /* [atspre_cloptr_free] */

/* ****** ****** */

ATSinline()
atstype_string
atspre_argv_get_at
(
  atstype_arrptr argv, atstype_int i
)
{
  return (((atstype_string*)argv)[i]) ;
} /* end of [atspre_argv_get_at] */

ATSinline()
atsvoid_t0ype
atspre_argv_set_at
(
  atstype_arrptr argv
, atstype_int i, atstype_string x
)
{
  ((atstype_string*)argv)[i] = x ; return ;
} /* end of [atspre_argv_set_at] */

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_exit
 (atstype_int ecode) { exit(ecode) ; return ; }
// end of [atspre_exit]

ATSinline()
atsvoid_t0ype
atspre_exit_errmsg
(
  atstype_int ecode, atstype_string msg
)
{
  fprintf(stderr, "exit(ATS): %s", (char*)msg); exit(ecode); return;
} // end of [atspre_exit_errmsg]

/* ****** ****** */

#define atspre_exit_void atspre_exit
#define atspre_exit_errmsg_void atspre_exit_errmsg

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_assert_bool
  (atstype_bool b)
{
  if (!b) exit(1) ; return ;
} /* endfun */
#define atspre_assert_bool0 atspre_assert_bool
#define atspre_assert_bool1 atspre_assert_bool

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_assert_errmsg_bool
(
  atstype_bool b, atstype_string msg
)
{
  if (!b) {
    fprintf(stderr, "%s", (char*)msg) ; exit(1) ;
  } // end of [if]
  return ;
} /* endfun */
#define atspre_assert_errmsg_bool0 atspre_assert_errmsg_bool
#define atspre_assert_errmsg_bool1 atspre_assert_errmsg_bool

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_assert_errmsg2_bool
(
  atstype_bool b
, atstype_string msg1, atstype_string msg2
)
{
  if (!b) {
    fprintf(stderr, "%s%s", (char*)msg1, (char*)msg2) ; exit(1) ;
  } // end of [if]
  return ;
} /* endfun */
#define atspre_assert_errmsg2_bool0 atspre_assert_errmsg2_bool
#define atspre_assert_errmsg2_bool1 atspre_assert_errmsg2_bool

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_fprint_newline
  (atstype_ref out)
{
  int n ;
  int err = -1 ;
  n = fprintf((FILE*)out, "\n") ;
  if (n > 0) err = fflush((FILE*)out) ;
  if (err < 0) {
    fprintf(stderr, "exit(ATS): [fprint_newline] failed.") ; exit(1) ;
  } // end of [if]
  return ;
} /* endfun */
#define atspre_print_newline() atspre_fprint_newline(stdout)
#define atspre_prerr_newline() atspre_fprint_newline(stderr)

/* ****** ****** */

#endif // ifndef ATSLIB_PRELUDE_BASICS_CATS

/* ****** ****** */

/* end of [basics.cats] */
