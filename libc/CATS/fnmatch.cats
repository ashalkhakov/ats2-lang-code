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
** $PATSHOME/libc/CATS/CODEGEN/fnmatch.atxt
** Time of generation: Mon Jul 22 19:30:34 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: March, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_LIBC_FNMATCH_CATS
#define ATSLIB_LIBC_FNMATCH_CATS

/* ****** ****** */

#include <fnmatch.h>

/* ****** ****** */

#define atslib_fnmatch_null(pat, str) fnmatch((char*)pat, (char*)str, 0)
#define atslib_fnmatch_flags(pat, str, flags) fnmatch((char*)pat, (char*)str, flags)

/* ****** ****** */

#endif // ifndef ATSLIB_LIBC_FNMATCH_CATS

/* ****** ****** */

/* end of [fnmatch.cats] */
