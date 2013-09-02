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
** $PATSHOME/libc/CATS/CODEGEN/stdlib.atxt
** Time of generation: Sat Aug 10 22:13:10 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: February, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_LIBC_STDLIB_CATS
#define ATSLIB_LIBC_STDLIB_CATS

/* ****** ****** */

#include <stdlib.h>

/* ****** ****** */

#define atslib_atoi atoi
#define atslib_atol atol
#define atslib_atoll atoll
#define atslib_atof atof

/* ****** ****** */

#define atslib_getenv getenv
#define atslib_putenv putenv
#define atslib_setenv setenv
#define atslib_unsetenv unsetenv

/* ****** ****** */

#define atslib_rand rand
#define atslib_srand srand
#define atslib_rand_r rand_r

/* ****** ****** */

#define atslib_random random
#define atslib_srandom srandom

/* ****** ****** */

#define atslib_drand48 drand48
#define atslib_erand48 erand48
#define atslib_lrand48 lrand48
#define atslib_nrand48 nrand48
#define atslib_mrand48 mrand48
#define atslib_jrand48 jrand48
#define atslib_srand48 srand48
#define atslib_seed48 seed48
#define atslib_lcong48 lcong48

/* ****** ****** */

#define atslib_qsort qsort
#define atslib_bsearch bsearch

/* ****** ****** */

#define atslib_mkstemp mkstemp
#define atslib_mkostemp mkostemp

/* ****** ****** */

#define atslib_mfree_libc free
#define atslib_malloc_libc malloc

/* ****** ****** */

#define atslib_system system

/* ****** ****** */

#endif // ifndef ATSLIB_LIBC_STDLIB_CATS

/* ****** ****** */

/* end of [stdlib.cats] */
