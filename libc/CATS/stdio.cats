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
** $PATSHOME/libc/CATS/CODEGEN/stdio.atxt
** Time of generation: Fri Aug 23 01:51:44 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: September, 2011 *)
*/

/* ****** ****** */

#ifndef ATSLIB_LIBC_STDIO_CATS
#define ATSLIB_LIBC_STDIO_CATS

/* ****** ****** */

#include <stdio.h>
/*
extern
void perror (const char* str) ; // in [stdio.h]
*/
extern void exit (int status) ; // in [stdlib.h]

/* ****** ****** */

#define \
ATSLIBfailexit(cmd) \
do { \
  perror(cmd) ; \
  fprintf(stderr, "exit(ATSLIB): [%s] failed\n", cmd) ; exit(1) ; \
} while (0) \

/* ****** ****** */

#define atslib_clearerr clearerr

/* ****** ****** */

#define atslib_fopen fopen
#define atslib_fopen_ref_exn atslib_fopen_exn

/* ****** ****** */

#define atslib_fclose fclose
#define atslib_fclose0 atslib_fclose
#define atslib_fclose1 atslib_fclose
#define atslib_fclose0_exn atslib_fclose_exn
#define atslib_fclose1_exn atslib_fclose_exn

/*
#define atslib_fclose_stdin() atslib_fclose_exn(stdin)
#define atslib_fclose_stdout() atslib_fclose_exn(stdout)
#define atslib_fclose_stderr() atslib_fclose_exn(stderr)
*/

/* ****** ****** */
//
#define atslib_fflush0_exn atslib_fflush_exn
//
#define atslib_fflush_all() atslib_fclose_exn((FILE*)0)
#define atslib_fflush_stdout() atslib_fclose_exn(stdout)
//
/* ****** ****** */

#define atslib_fileno fileno
#define atslib_fileno0 atslib_fileno
#define atslib_fileno1 atslib_fileno

/* ****** ****** */

#define atslib_fdopen fdopen

/* ****** ****** */

#define atslib_feof feof
#define atslib_feof0 atslib_feof
#define atslib_feof1 atslib_feof

/* ****** ****** */

#define atslib_ferror ferror
#define atslib_ferror0 atslib_ferror
#define atslib_ferror1 atslib_ferror

/* ****** ****** */

#define atslib_fgetc fgetc
#define atslib_fgetc0 atslib_fgetc
#define atslib_fgetc1 atslib_fgetc

/* ****** ****** */

#define atslib_getchar getchar
#define atslib_getchar0 atslib_getchar
#define atslib_getchar1 atslib_getchar

/* ****** ****** */

#define atslib_fputc fputc
#define atslib_fputc0_int atslib_fputc
#define atslib_fputc0_char(c, fp) atslib_fputc((int)c, fp)
#define atslib_fputc1_int atslib_fputc
#define atslib_fputc1_char(c, fp) atslib_fputc((int)c, fp)

#define atslib_fputc0_exn_int atslib_fputc_exn
#define atslib_fputc0_exn_char atslib_fputc_exn

/* ****** ****** */

#define atslib_fgets fgets
#define atslib_fgets0 atslib_fgets
#define atslib_fgets1 atslib_fgets
#define atslib_fgets1_err atslib_fgets
#define atslib_fgets0_gc atslib_fgets_gc
#define atslib_fgets1_gc atslib_fgets_gc

/* ****** ****** */

#define atslib_fputs fputs
#define atslib_fputs0 atslib_fputs
#define atslib_fputs1 atslib_fputs
#define atslib_fputs0_exn atslib_fputs_exn
#define atslib_fputs1_exn atslib_fputs_exn

/* ****** ****** */

#define atslib_puts puts

/* ****** ****** */

#define atslib_fread fread
#define atslib_fread0 atslib_fread
#define atslib_fread1 atslib_fread

/* ****** ****** */

#define atslib_fwrite fwrite
#define atslib_fwrite0 atslib_fwrite
#define atslib_fwrite1 atslib_fwrite

/* ****** ****** */

#define atslib_fseek fseek
#define atslib_fseek0 atslib_fseek
#define atslib_fseek1 atslib_fseek

/* ****** ****** */

#define atslib_ftell ftell
#define atslib_ftell0 atslib_ftell
#define atslib_ftell1 atslib_ftell

/* ****** ****** */

#define atslib_perror perror

/* ****** ****** */

#define atslib_popen popen

/* ****** ****** */

#define atslib_pclose0_exn atslib_pclose_exn
#define atslib_pclose1_exn atslib_pclose_exn

/* ****** ****** */

#define atslib_rewind rewind
#define atslib_rewind0 atslib_rewind
#define atslib_rewind1 atslib_rewind

/* ****** ****** */

#define atslib_tmpfile tmpfile
#define atslib_tmpfile_ref_exn atslib_tmpfile_exn

/* ****** ****** */

#endif // ifndef ATSLIB_LIBC_STDIO_CATS

/* ****** ****** */

/* end of [stdio.cats] */
