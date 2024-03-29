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
** $PATSHOME/prelude/CATS/CODEGEN/char.atxt
** Time of generation: Mon Jul 22 19:30:28 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: February, 2012 *)
*/

/* ****** ****** */

#ifndef ATSLIB_PRELUDE_CHAR_CATS
#define ATSLIB_PRELUDE_CHAR_CATS

/* ****** ****** */

#include <ctype.h>

#ifndef isascii
extern int isascii (int c) ; // _XOPEN_SOURCE
#endif // end of [isascii]

#ifndef isblank
extern int isblank (int c) ; // _XOPEN_SOURCE >= 600
#endif // end of [isblank]

#ifndef toascii
extern int toascii (int c) ; // _XOPEN_SOURCE
#endif // end of [toascii]

/* ****** ****** */

extern
int fprintf (FILE *stream, const char *format, ...) ;
// in [stdio.h]

/* ****** ****** */

ATSinline()
atstype_char
atspre_int2char (atstype_int i) { return ((atstype_char)i) ; }
#define atspre_int2char0 atspre_int2char

ATSinline()
atstype_schar
atspre_int2schar (atstype_int i) { return ((atstype_schar)i) ; }
#define atspre_int2schar0 atspre_int2schar

ATSinline()
atstype_uchar
atspre_int2uchar (atstype_int i) { return ((atstype_uchar)i) ; }
#define atspre_int2uchar0 atspre_int2uchar

/* ****** ****** */

ATSinline()
atstype_int
atspre_char2int (atstype_char c) { return ((atstype_int)c) ; }
#define atspre_char2int0 atspre_char2int

ATSinline()
atstype_int
atspre_schar2int (atstype_schar c) { return ((atstype_int)c) ; }
#define atspre_schar2int0 atspre_schar2int

ATSinline()
atstype_int
atspre_uchar2int (atstype_uchar c) { return ((atstype_int)c) ; }
#define atspre_uchar2int0 atspre_uchar2int

/* ****** ****** */

ATSinline()
atstype_uint
atspre_char2uint (atstype_char c) { return ((atstype_uint)c) ; }
#define atspre_char2uint0 atspre_char2uint

ATSinline()
atstype_uint
atspre_schar2uint (atstype_schar c) { return ((atstype_uint)c) ; }
#define atspre_schar2uint0 atspre_schar2uint

ATSinline()
atstype_uint
atspre_uchar2uint (atstype_uchar c) { return ((atstype_uint)c) ; }
#define atspre_uchar2uint0 atspre_uchar2uint

/* ****** ****** */

ATSinline()
atstype_int
atspre_char2u2int
  (atstype_char c) { return ((atstype_int)((atstype_uchar)c)) ; }
#define atspre_char2u2int0 atspre_char2u2int
ATSinline()
atstype_uint
atspre_char2u2uint
  (atstype_char c) { return ((atstype_uint)((atstype_uchar)c)) ; }
#define atspre_char2u2uint0 atspre_char2u2uint

/* ****** ****** */

ATSinline()
atstype_char
atspre_add_char_int
  (atstype_char c1, atstype_int i2) { return (c1 + i2) ; }
// end of [atspre_add_char_int]
#define atspre_add_char0_int0 atspre_add_char_int

/* ****** ****** */

ATSinline()
atstype_int
atspre_sub_char_char
  (atstype_char c1, atstype_char c2) { return (c1 - c2) ; }
// end of [sub_char0_char0]
#define atspre_sub_char0_char0 atspre_sub_char_char

/* ****** ****** */

ATSinline()
atstype_bool
atspre_lt_int_int
  (atstype_int i1, atstype_int i2) {
  return (i1 < i2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_lt_char_char]
#define atspre_lt_char0_char0 atspre_lt_int_int
#define atspre_lt_char1_char1 atspre_lt_int_int

ATSinline()
atstype_bool
atspre_lte_int_int
  (atstype_int i1, atstype_int i2) {
  return (i1 <= i2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_lte_char_char]
#define atspre_lte_char0_char0 atspre_lte_int_int
#define atspre_lte_char1_char1 atspre_lte_int_int

ATSinline()
atstype_bool
atspre_gt_int_int
  (atstype_int i1, atstype_int i2) {
  return (i1 > i2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_gt_char_char]
#define atspre_gt_char0_char0 atspre_gt_int_int
#define atspre_gt_char1_char1 atspre_gt_int_int

ATSinline()
atstype_bool
atspre_gte_int_int
  (atstype_int i1, atstype_int i2) {
  return (i1 >= i2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_gte_char_char]
#define atspre_gte_char0_char0 atspre_gte_int_int
#define atspre_gte_char1_char1 atspre_gte_int_int

ATSinline()
atstype_bool
atspre_eq_int_int
  (atstype_int i1, atstype_int i2) {
  return (i1 == i2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_eq_char_char]
#define atspre_eq_char0_char0 atspre_eq_int_int
#define atspre_eq_char1_char1 atspre_eq_int_int

ATSinline()
atstype_bool
atspre_neq_int_int
  (atstype_int i1, atstype_int i2) {
  return (i1 != i2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_neq_char_char]
#define atspre_neq_char0_char0 atspre_neq_int_int
#define atspre_neq_char1_char1 atspre_neq_int_int


/* ****** ****** */

ATSinline()
atstype_int
atspre_compare_int_int
  (atstype_int i1, atstype_int i2)
{
  return (i1 - i2) ;
} // end of [atspre_compare_char_char]
#define atspre_compare_char0_char0(c1, c2) atspre_compare_int_int(c1, c2)
#define atspre_compare_char1_char1(c1, c2) atspre_compare_int_int(c1, c2)

/* ****** ****** */

#define atspre_eq_char0_int0(c, i) atspre_eq_int_int(c, i)
#define atspre_eq_int0_char0(i, c) atspre_eq_int_int(i, c)
#define atspre_neq_char0_int0(c, i) atspre_neq_int_int(c, i)
#define atspre_neq_int0_char0(i, c) atspre_neq_int_int(i, c)

/* ****** ****** */

#define atspre_compare_char0_int0(c, i) atspre_compare_int_int(c, i)
#define atspre_compare_int0_char0(i, c) atspre_compare_int_int(i, c)

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_fprint_char (
  atstype_ref out, atstype_char c
) {
  int err = 0 ;
  err += fprintf ((FILE*)out, "%c", c) ;
/*
  if (err < 0) {
    fprintf(stderr, "exit(ATS): [fprint_char] failed.") ; exit(1) ;
  } // end of [if]
*/
  return ;
} // end of [atspre_fprint_char]
#define atspre_print_char(c) atspre_fprint_char(stdout, (c))
#define atspre_prerr_char(c) atspre_fprint_char(stderr, (c))

/* ****** ****** */
//
// unsigned characters
//
/* ****** ****** */

ATSinline()
atstype_bool
atspre_lt_uchar_uchar
  (atstype_uchar c1, atstype_uchar c2) {
  return (c1 < c2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_lt_uchar_uchar]
#define atspre_lt_uchar0_uchar0 atspre_lt_uchar_uchar
#define atspre_lt_uchar1_uchar1 atspre_lt_uchar_uchar

ATSinline()
atstype_bool
atspre_lte_uchar_uchar
  (atstype_uchar c1, atstype_uchar c2) {
  return (c1 <= c2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_lte_uchar_uchar]
#define atspre_lte_uchar0_uchar0 atspre_lte_uchar_uchar
#define atspre_lte_uchar1_uchar1 atspre_lte_uchar_uchar

ATSinline()
atstype_bool
atspre_gt_uchar_uchar
  (atstype_uchar c1, atstype_uchar c2) {
  return (c1 > c2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_gt_uchar_uchar]
#define atspre_gt_uchar0_uchar0 atspre_gt_uchar_uchar
#define atspre_gt_uchar1_uchar1 atspre_gt_uchar_uchar

ATSinline()
atstype_bool
atspre_gte_uchar_uchar
  (atstype_uchar c1, atstype_uchar c2) {
  return (c1 >= c2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_gte_uchar_uchar]
#define atspre_gte_uchar0_uchar0 atspre_gte_uchar_uchar
#define atspre_gte_uchar1_uchar1 atspre_gte_uchar_uchar

ATSinline()
atstype_bool
atspre_eq_uchar_uchar
  (atstype_uchar c1, atstype_uchar c2) {
  return (c1 == c2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_eq_uchar_uchar]
#define atspre_eq_uchar0_uchar0 atspre_eq_uchar_uchar
#define atspre_eq_uchar1_uchar1 atspre_eq_uchar_uchar

ATSinline()
atstype_bool
atspre_neq_uchar_uchar
  (atstype_uchar c1, atstype_uchar c2) {
  return (c1 != c2 ? atsbool_true : atsbool_false) ;
} // end of [atspre_neq_uchar_uchar]
#define atspre_neq_uchar0_uchar0 atspre_neq_uchar_uchar
#define atspre_neq_uchar1_uchar1 atspre_neq_uchar_uchar


ATSinline()
atstype_int
atspre_compare_uchar_uchar
  (atstype_uchar c1, atstype_uchar c2) {
  return ((atstype_int)c1 - (atstype_int)c2) ;
} // end of [atspre_compare_uchar_uchar]
#define atspre_compare_uchar0_uchar0 atspre_compare_uchar_uchar
#define atspre_compare_uchar1_uchar1 atspre_compare_uchar_uchar

/* ****** ****** */

ATSinline()
atstype_bool
atspre_isalpha_int
  (atstype_int c) {
  return (isalpha(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isalpha_int]
#define atspre_isalpha_char(c) atspre_isalpha_int((atstype_int)(c))
ATSinline()
atstype_bool
atspre_isalnum_int
  (atstype_int c) {
  return (isalnum(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isalnum_int]
#define atspre_isalnum_char(c) atspre_isalnum_int((atstype_int)(c))

ATSinline()
atstype_bool
atspre_isascii_int
  (atstype_int c) {
  return (isascii(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isascii_int]
#define atspre_isascii_char(c) atspre_isascii_int((atstype_int)(c))

ATSinline()
atstype_bool
atspre_isblank_int
  (atstype_int c) {
  return (isblank(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isblank_int]
#define atspre_isblank_char(c) atspre_isblank_int((atstype_int)(c))
ATSinline()
atstype_bool
atspre_isspace_int
  (atstype_int c) {
  return (isspace(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isspace_int]
#define atspre_isspace_char(c) atspre_isspace_int((atstype_int)(c))

ATSinline()
atstype_bool
atspre_iscntrl_int
  (atstype_int c) {
  return (iscntrl(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_iscntrl_int]
#define atspre_iscntrl_char(c) atspre_iscntrl_int((atstype_int)(c))

ATSinline()
atstype_bool
atspre_isdigit_int
  (atstype_int c) {
  return (isdigit(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isdigit_int]
#define atspre_isdigit_char(c) atspre_isdigit_int((atstype_int)(c))
ATSinline()
atstype_bool
atspre_isxdigit_int
  (atstype_int c) {
  return (isxdigit(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isxdigit_int]
#define atspre_isxdigit_char(c) atspre_isxdigit_int((atstype_int)(c))

ATSinline()
atstype_bool
atspre_isgraph_int
  (atstype_int c) {
  return (isgraph(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isgraph_int]
#define atspre_isgraph_char(c) atspre_isgraph_int((atstype_int)(c))
ATSinline()
atstype_bool
atspre_isprint_int
  (atstype_int c) {
  return (isprint(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isprint_int]
#define atspre_isprint_char(c) atspre_isprint_int((atstype_int)(c))
ATSinline()
atstype_bool
atspre_ispunct_int
  (atstype_int c) {
  return (ispunct(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_ispunct_int]
#define atspre_ispunct_char(c) atspre_ispunct_int((atstype_int)(c))

ATSinline()
atstype_bool
atspre_islower_int
  (atstype_int c) {
  return (islower(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_islower_int]
#define atspre_islower_char(c) atspre_islower_int((atstype_int)(c))
ATSinline()
atstype_bool
atspre_isupper_int
  (atstype_int c) {
  return (isupper(c) ? atsbool_true : atsbool_false) ;
} // end of [atspre_isupper_int]
#define atspre_isupper_char(c) atspre_isupper_int((atstype_int)(c))

/* ****** ****** */

#define atspre_toascii toascii

/* ****** ****** */

ATSinline()
atstype_int
atspre_tolower_int
  (atstype_int c) { return tolower(c) ; }
ATSinline()
atstype_char
atspre_tolower_char
  (atstype_char c) { return tolower(c) ; }
//
ATSinline()
atstype_int
atspre_toupper_int
  (atstype_int c) { return toupper(c) ; }
ATSinline()
atstype_char
atspre_toupper_char
  (atstype_char c) { return toupper(c) ; }
//
/* ****** ****** */

#endif // ifndef ATSLIB_PRELUDE_CHAR_CATS

/* ****** ****** */

/* end of [char.cats] */
