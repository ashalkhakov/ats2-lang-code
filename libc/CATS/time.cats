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
** $PATSHOME/libc/CATS/CODEGEN/time.atxt
** Time of generation: Thu Jul 25 13:42:19 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: March, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_LIBC_TIME_CATS
#define ATSLIB_LIBC_TIME_CATS

/* ****** ****** */

#include <time.h>

/* ****** ****** */

typedef time_t atslib_time_type ;
typedef struct tm atslib_tm_struct_type ;

/* ****** ****** */

typedef clock_t atslib_clock_type ;

/* ****** ****** */

#define atslib_difftime difftime

/* ****** ****** */

#define atslib_time_get() time((time_t*)0)

ATSinline()
atstype_bool
atslib_time_getset
(
  atstype_ref tval
) {
  return (time((time_t*)tval) >= 0 ? atsbool_true : atsbool_false) ;
} // end of [atslib_time_getset]

/* ****** ****** */

#define atslib_ctime ctime
#define atslib_ctime_r ctime_r

/* ****** ****** */

#define atslib_mktime mktime

/* ****** ****** */

#define atslib_asctime asctime

/* ****** ****** */

#define atslib_gmtime gmtime
#define atslib_gmtime_r gmtime_r

/* ****** ****** */

#define atslib_localtime localtime
#define atslib_localtime_r localtime_r

/* ****** ****** */

#define atslib_tzset tzset

/* ****** ****** */

#define atslib_clock clock

#define atslib_clock_getres clock_getres

/* ****** ****** */

#define atslib_clock_gettime clock_gettime
#define atslib_clock_settime clock_settime

/* ****** ****** */

#endif // ifndef ATSLIB_LIBC_TIME_CATS

/* ****** ****** */

/* end of [time.cats] */
