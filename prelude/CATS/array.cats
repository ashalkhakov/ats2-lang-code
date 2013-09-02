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
** $PATSHOME/prelude/CATS/CODEGEN/array.atxt
** Time of generation: Sat Aug 10 22:13:09 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: January, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_PRELUDE_ARRAY_CATS
#define ATSLIB_PRELUDE_ARRAY_CATS

/* ****** ****** */
//
// [stdlib.h]
//
extern
void qsort
(
  void *base, size_t nmemb, size_t size
, int(*compar)(const void *, const void *)
) ; // end of [qsort]
extern
void *bsearch
(
  const void *key
, const void *base
, size_t nmemb, size_t size
, int (*compar)(const void *, const void *)
) ; // end of [bsearch]
//
#define atspre_array_qsort qsort
#define atspre_array_bsearch bsearch
//
/* ****** ****** */
//
// [string.h]
//
extern
void *memcpy(void *dst, const void *src, size_t n) ;
extern
void *memmove(void *dst, const void *src, size_t n) ;
//
#define atspre_array_memcpy memcpy
#define atspre_array_memmove memmove
//
/* ****** ****** */

#endif // ifndef ATSLIB_PRELUDE_ARRAY_CATS

/* ****** ****** */

/* end of [array.cats] */
