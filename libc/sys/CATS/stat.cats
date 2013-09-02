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
** $PATSHOME/libc/sys/CATS/CODEGEN/stat.atxt
** Time of generation: Sat May  4 00:00:31 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: March, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_LIBC_SYS_STAT_CATS
#define ATSLIB_LIBC_SYS_STAT_CATS

/* ****** ****** */

#include <sys/stat.h>

/* ****** ****** */

#define atslib_umask umask

/* ****** ****** */

#define atslib_chmod chmod

/* ****** ****** */

#define atslib_mkdir mkdir

/* ****** ****** */

#define atslib_mkfifo mkfifo

/* ****** ****** */

#define atslib_stat stat
#define atslib_fstat fstat
#define atslib_lstat lstat

/* ****** ****** */

#endif // ifndef ATSLIB_LIBC_SYS_STAT_CATS

/* ****** ****** */

/* end of [stat.cats] */
