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
** $PATSHOME/prelude/CATS/CODEGEN/filebas.atxt
** Time of generation: Mon Jul 22 19:30:30 2013
*/

/* ****** ****** */

/*
(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: January, 2013 *)
*/

/* ****** ****** */

#ifndef ATSLIB_PRELUDE_FILEBAS_CATS
#define ATSLIB_PRELUDE_FILEBAS_CATS

/* ****** ****** */

#define atspre_FILE_stdin stdin
#define atspre_FILE_stdout stdout
#define atspre_FILE_stderr stderr

/* ****** ****** */

#define atspre_file_mode_r "r"
#define atspre_file_mode_rr "r+"
#define atspre_file_mode_w "w"
#define atspre_file_mode_ww "w+"
#define atspre_file_mode_a "a"
#define atspre_file_mode_aa "a+"

/* ****** ****** */

ATSinline()
atstype_ref
atspre_fileref_open_exn
  (atstype_string path, atstype_string fm)
{
  FILE* filr ;
  filr = fopen((char*)path, (char*)fm) ;
  if (!filr) {
    fprintf(
      stderr
    , "exit(ATS): [atspre_fileref_open_exn(%s, %s)] failed.\n"
    , (char*)path, (char*)fm
    ) ;
    exit(1) ;
  }
  return filr ;
} // end of [atspre_fileref_open]

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_fileref_close
  (atstype_ref filr)
{
  int err ;
  err = fclose((FILE*)filr) ;
  if (err < 0) {
    fprintf(
      stderr
    , "exit(ATS): [atspre_fileref_close] failed.\n"
    ) ;
    exit(1) ;
  }
  return ;
} // end of [atspre_fileref_close]

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_fileref_flush
  (atstype_ref filr)
{
  int err ;
  err = fflush((FILE*)filr) ;
  if (err < 0) {
    fprintf(
      stderr
    , "exit(ATS): [atspre_fileref_fflush] failed.\n"
    ) ;
    exit(1) ;
  }
  return ;
} // end of [atspre_fileref_flush]

/* ****** ****** */

ATSinline()
atstype_int
atspre_fileref_getc
  (atstype_ref filr) { return fgetc((FILE*)filr) ; }
// end of [atspre_fileref_getc]

/* ****** ****** */

ATSinline()
atsvoid_t0ype
atspre_fileref_putc
(
  atstype_ref filr, atstype_int c
) {
  fputc (c, (FILE*)filr) ; return ;
} // end of [atspre_fileref_putc]
#define atspre_fileref_putc_int atspre_fileref_putc
#define atspre_fileref_putc_char atspre_fileref_putc

/* ****** ****** */

ATSinline()
atstype_bool
atspre_fileref_is_eof (atstype_ref filr)
{
  int eof ;
  eof = feof ((FILE*)filr) ;
  return (eof != 0 ? atsbool_true : atsbool_false) ;
} // end of [fileref_is_eof]

/* ****** ****** */

ATSinline()
atstype_bool
atspre_fileref_load_int
  (atstype_ref inp, atstype_ref x)
{
  int n ;
  n = fscanf((FILE*)inp, "%i", (atstype_int*)x) ;
  return (n == 1 ? atsbool_true : atsbool_false) ;
} // end of [atspre_fileref_load_int]

ATSinline()
atstype_bool
atspre_fileref_load_lint
  (atstype_ref inp, atstype_ref x)
{
  int n ;
  n = fscanf((FILE*)inp, "%li", (atstype_lint*)x) ;
  return (n == 1 ? atsbool_true : atsbool_false) ;
} // end of [atspre_fileref_load_lint]

/* ****** ****** */

ATSinline()
atstype_bool
atspre_fileref_load_uint
  (atstype_ref inp, atstype_ref x)
{
  int n ;
  n = fscanf((FILE*)inp, "%u", (atstype_uint*)x) ;
  return (n == 1 ? atsbool_true : atsbool_false) ;
} // end of [atspre_fileref_load_uint]

ATSinline()
atstype_bool
atspre_fileref_load_ulint
  (atstype_ref inp, atstype_ref x)
{
  int n ;
  n = fscanf((FILE*)inp, "%lu", (atstype_ulint*)x) ;
  return (n == 1 ? atsbool_true : atsbool_false) ;
} // end of [atspre_fileref_load_ulint]

/* ****** ****** */

ATSinline()
atstype_bool
atspre_fileref_load_float
  (atstype_ref inp, atstype_ref x)
{
  int n ;
  n = fscanf((FILE*)inp, "%f", (atstype_float*)x) ;
  return (n == 1 ? atsbool_true : atsbool_false) ;
} // end of [atspre_fileref_load_float]

ATSinline()
atstype_bool
atspre_fileref_load_double
  (atstype_ref inp, atstype_ref x)
{
  int n ;
  n = fscanf((FILE*)inp, "%lf", (atstype_double*)x) ;
  return (n == 1 ? atsbool_true : atsbool_false) ;
} // end of [atspre_fileref_load_double]

/* ****** ****** */

extern
atstype_ptr
atspre_fileref_get_line_string_main2
(
  atstype_int bsz // int bsz
, atstype_ptr filp // FILE* filp
, atstype_ref nlen // int *nlen
) ; // endfun

/* ****** ****** */

#endif // ifndef ATSLIB_PRELUDE_FILEBAS_CATS

/* ****** ****** */

/* end of [filebas.cats] */
