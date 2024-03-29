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
** $PATSHOME/libc/CATS/CODEGEN/malloc.atxt
** Time of generation: Mon Jul 22 19:30:34 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: February, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_LIBC_MALLOC_CATS
#define ATSLIB_LIBC_MALLOC_CATS

/* ****** ****** */

#include <malloc.h>

/* ****** ****** */

#define atslib_mallopt mallopt
#define atslib_malloc_trim malloc_trim
#define atslib_malloc_usable_size malloc_usable_size
#define atslib_malloc_stats malloc_stats
#define atslib_malloc_get_state malloc_get_state
#define atslib_malloc_set_state malloc_set_state

/* ****** ****** */

#endif // ifndef ATSLIB_LIBC_MALLOC_CATS

/* ****** ****** */

/* end of [malloc.cats] */
