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
** $PATSHOME/prelude/CATS/CODEGEN/string.atxt
** Time of generation: Mon Jul 22 19:30:29 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: April, 2012 *)
*/

/* ****** ****** */

#ifndef ATSLIB_PRELUDE_STRING_CATS
#define ATSLIB_PRELUDE_STRING_CATS

/* ****** ****** */
//
// [string.h]
//
extern
size_t strlen (const char *str) ;
extern
int // (sign)
strcmp (const char *x1, const char *x2) ;

extern
char *strchr(const char *str1, int c2) ;
extern
char *strrchr(const char *str1, int c2) ;
extern
char *strstr(const char *str1, const char *str2) ;

extern
size_t strspn(const char *str1, const char *acc2) ;
extern
size_t strcspn(const char *str1, const char *rej2) ;

extern
void *memcpy(void *dest, const void *src, size_t n) ;

/* ****** ****** */
//
// [stdio.h]
//
extern
int // (errcode)
fprintf (FILE *stream, const char *format, ...) ;

/* ****** ****** */

#define atspre_stropt_none() atsptr_null

/* ****** ****** */

ATSinline()
atstype_bool
atspre_lt_string_string (
  atstype_string x1, atstype_string x2
) {
  return (strcmp((char*)x1, (char*)x2) < 0 ? atsbool_true : atsbool_false) ;
} // [atspre_lt_string_string]

ATSinline()
atstype_bool
atspre_lte_string_string (
  atstype_string x1, atstype_string x2
) {
  return (strcmp((char*)x1, (char*)x2) <= 0 ? atsbool_true : atsbool_false) ;
} // [atspre_lte_string_string]

ATSinline()
atstype_bool
atspre_gt_string_string(
  atstype_string x1, atstype_string x2
) {
  return (strcmp((char*)x1, (char*)x2) > 0 ? atsbool_true : atsbool_false) ;
} // [atspre_gt_string_string]

ATSinline()
atstype_bool
atspre_gte_string_string (
  atstype_string x1, atstype_string x2
) {
  return (strcmp((char*)x1, (char*)x2) >= 0 ? atsbool_true : atsbool_false) ;
} // [atspre_gte_string_string]

ATSinline()
atstype_bool
atspre_eq_string_string (
  atstype_string x1, atstype_string x2
) {
  return (strcmp((char*)x1, (char*)x2)==0 ? atsbool_true : atsbool_false) ;
} // [atspre_eq_string_string]

ATSinline()
atstype_bool
atspre_neq_string_string (
  atstype_string x1, atstype_string x2
) {
  return (strcmp((char*)x1, (char*)x2)!=0 ? atsbool_true : atsbool_false) ;
} // [atspre_neq_string_string]

/* ****** ****** */

#define atspre_string_equal atspre_eq_string_string
#define atspre_string_noteq atspre_neq_string_string

/* ****** ****** */

ATSinline()
atstype_int
atspre_compare_string_string
  (atstype_string x1, atstype_string x2) { return strcmp((char*)x1, (char*)x2) ; }
// [atspre_compare_string_string]

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_fprint_string
(
  atstype_ref out, atstype_string x
) {
  int err = 0 ;
  err += fprintf((FILE*)out, "%s", (char*)x) ;
/*
  if (err < 0) {
    fprintf(stderr, "exit(ATS): [fprint_string] failed.") ; exit(1) ;
  } // end of [if]
*/
  return ;
} // end of [atspre_fprint_string]
#define atspre_print_string(x) atspre_fprint_string(stdout, (x))
#define atspre_prerr_string(x) atspre_fprint_string(stderr, (x))

/* ****** ****** */

#define atspre_strlen strlen
#define atspre_strchr strchr
#define atspre_strrchr strrchr
#define atspre_strstr strstr
#define atspre_strspn strspn
#define atspre_strcspn strcspn

#define atspre_string_memcpy memcpy

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_fprint_stropt
(
  atstype_ref out, atstype_stropt x
) {
  int err = 0 ;
  if (!x)
  {
    err += fprintf((FILE*)out, "strnone()") ;
  } else {
    err += fprintf((FILE*)out, "strsome(%s)", (char*)x) ;
  }
/*
  if (err < 0) {
    fprintf(stderr, "exit(ATS): [fprint_stropt] failed.") ; exit(1) ;
  } // end of [if]
*/
  return ;
} // end of [atspre_fprint_stropt]
#define atspre_print_stropt(x) atspre_fprint_stropt(stdout, (x))
#define atspre_prerr_stropt(x) atspre_fprint_stropt(stderr, (x))

/* ****** ****** */

#endif // ifndef ATSLIB_PRELUDE_STRING_CATS

/* ****** ****** */

/* end of [string.cats] */
