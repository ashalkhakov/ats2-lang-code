(***********************************************************************)
(*                                                                     *)
(*                         Applied Type System                         *)
(*                                                                     *)
(***********************************************************************)

(*
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
*)

(* ****** ****** *)

(*
** Source:
** $PATSHOME/prelude/DATS/CODEGEN/filebas.atxt
** Time of generation: Thu Jul 25 11:29:34 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: Feburary, 2012 *)

(* ****** ****** *)

#define ATS_DYNLOADFLAG 0 // no dynloading at run-time

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

staload _(*anon*) = "prelude/DATS/integer.dats"

(* ****** ****** *)

staload STDIO = "libc/SATS/stdio.sats"
vtypedef FILEptr1 = $STDIO.FILEptr1 (*linear/nonnull*)
staload STRING = "libc/SATS/string.sats"

(* ****** ****** *)

#define c2i char2int0
#define i2c int2char0

(* ****** ****** *)
//
// HX-2013-06:
// this is just Unix convention
//
implement{} dirsep_get () = '/'
implement{} dirname_self () = "."
implement{} dirname_parent () = ".."
//
(* ****** ****** *)

implement{}
filename_get_ext (name) = let
//
#define NUL '\000'
overload + with add_ptr_bsz
//
fun loop
(
  p1: ptr, p2: ptr, c0: char
) : ptr = let
  val c = $UN.ptr0_get<char> (p1)
in
  if c != NUL then let
    val p1 = p1 + (i2sz)1
  in
    if c != c0 then loop (p1, p2, c0) else loop (p1, p1, c0)
  end else p2 // end of [if]
end // end of [loop]
//
val p1 = string2ptr(name)
val p2 = $effmask_all (loop (p1, the_null_ptr, '.'))
//
in
  $UN.castvwtp0{vStrptr0}(p2)
end // end of [filename_get_ext]

(* ****** ****** *)

implement{}
filename_test_ext
  (name, ext0) = let
//
val (fpf | ext) = filename_get_ext (name)
//
val ans =
(
  if strptr2ptr(ext) > 0
    then eq_string_string (ext0, $UN.strptr2string(ext))
    else false
  // end of [if]
) : bool // end of [val]
//
prval () = fpf (ext)
//
in
  ans
end // end of [filename_test_ext]

(* ****** ****** *)

implement{}
filename_get_base (name) = let
//
#define NUL '\000'
overload + with add_ptr_bsz
//
fun loop
(
  p1: ptr, p2: ptr, c0: char
) : ptr = let
  val c = $UN.ptr0_get<char> (p1)
in
  if c != NUL then let
    val p1 = p1 + (i2sz)1
  in
    if c != c0 then loop (p1, p2, c0) else loop (p1, p1, c0)
  end else p2 // end of [if]
end // end of [loop]
//
val c0 = dirsep_get<> ()
val p1 = string2ptr(name)
val p2 = $effmask_all (loop (p1, p1, c0))
//
in
  $UN.castvwtp0{vStrptr1}(p2)
end // end of [filename_get_base]

(* ****** ****** *)

implement{}
filename_test_base
  (name, base0) = let
//
val (fpf | base) = filename_get_base (name)
//
val ans = eq_string_string (base0, $UN.strptr2string(base))
//
prval () = fpf (base)
//
in
  ans
end // end of [filename_test_base]

(* ****** ****** *)

(*
//
// HX-2013-04:
// this is now implemented in [filebas.cats].
//
local

extern
castfn file_mode
  {fm:file_mode} (x: string):<> file_mode (fm)
// end of [extern]

in (* in of [local] *)

implement file_mode_r = file_mode ("r")
implement file_mode_rr = file_mode ("r+")
implement file_mode_w = file_mode ("w")
implement file_mode_ww = file_mode ("w+")
implement file_mode_a = file_mode ("a")
implement file_mode_aa = file_mode ("a+")

end // end of [local]
*)

(* ****** ****** *)

extern
castfn
__cast_filp (r: FILEref): FILEptr1

(* ****** ****** *)

implement{}
fileref_open_opt
  (path, fm) = let
//
val filp = $STDIO.fopen (path, fm)
val isnot = $STDIO.FILEptr2ptr(filp) > 0
//
in
//
if isnot then let
  val fil = $STDIO.FILEptr_refize (filp)
in
  Some_vt{FILEref}(fil)
end else let
  prval () = $STDIO.FILEptr_free_null (filp)
in
  None_vt{FILEref}((*void*))
end // end of [if]
//
end // end of [fileref_open_opt]

(* ****** ****** *)

(*
//
// HX: atspre_fileref_close
//
implement
fileref_close (fil) = $STDIO.fclose0_exn (fil)
*)

(* ****** ****** *)

(*
//
// HX: atspre_fileref_flush
//
implement
fileref_flush (fil) = $STDIO.fflush0_exn (fil)
*)

(* ****** ****** *)

(*
//
// HX: atspre_fileref_getc
//
implement fileref_getc (inp) = $STDIO.fgetc0 (inp)
*)

(* ****** ****** *)

(*
//
// HX: atspre_fileref_putc_int
// HX: atspre_fileref_putc_char
//
implement
fileref_putc_int (out, c) = let
  val _(*ignored*) = $STDIO.fputc0 (c, out) in (*nothing*)
end // end of [fileref_putc_int]
implement
fileref_putc_char (out, c) = fileref_putc_int (out, (c2i)c)
*)

(* ****** ****** *)

(*
//
// HX: atspre_fileref_puts
//
implement
fileref_puts (out, s) = let
  val _(*ignored*) = $STDIO.fputs0 (s, out) in (*nothing*)
end // end of [fileref_puts]
*)

(* ****** ****** *)

(*
//
// HX: atspre_fileref_is_eof
//
implement
fileref_is_eof (fil) =
  if $STDIO.feof0 (fil) != 0 true else false
// end of [fileref_is_eof]
*)

(* ****** ****** *)
//
implement fileref_load<int> = fileref_load_int
implement fileref_load<lint> = fileref_load_lint
implement fileref_load<uint> = fileref_load_uint
implement fileref_load<ulint> = fileref_load_ulint
//
implement fileref_load<float> = fileref_load_float
implement fileref_load<double> = fileref_load_double
//
(* ****** ****** *)

implement{a}
fileref_get_optval (r) = let
  var x: a?
  val yn = fileref_load<a> (r, x)
in
  option_vt_make_opt<a> (yn, x)
end // end of [fileref_get_optval]

(* ****** ****** *)

implement{a}
fileref_get_exnmsg
  (r, msg) = let
  var x: a?
  val yn = fileref_load<a> (r, x)
in
  if yn then let
    prval () = opt_unsome (x) in x
  end else let
    prval () = opt_unnone (x) in exit_errmsg (1, msg)
  end (* end of [if] *)
end // end of [fileref_get_exnmsg]

(* ****** ****** *)

implement
fileref_get_line_charlst
  (inp) = let
//
val EOL = '\n'
//
fun loop
(
  inp: FILEref, res: &ptr? >> charlst_vt
) : void = let
  val i = fileref_getc (inp)
in
//
if i >= 0 then let
  val c = int2char0(i)
in
//
if (c != EOL) then let
  val () =
  (
    res :=
    list_vt_cons{char}{0}(c, _)
  )
  val+list_vt_cons (_, res1) = res
  val () = loop (inp, res1)
  prval () = fold@ (res)
in
  // nothing
end else (res := list_vt_nil)
//
end else (res := list_vt_nil)
//
end // end of [loop]
//
var res: ptr
val () = loop (inp, res)
//
in
  res
end // end of [fileref_get_line_charlst]

(* ****** ****** *)

implement
fileref_get_lines_charlstlst
  (inp) = let
//
vtypedef line = charlst_vt
vtypedef lines = List0_vt (line)
//
fun loop
(
  inp: FILEref
, res: &lines? >> lines
) : void = let
  val iseof = fileref_is_eof (inp)
in
//
if iseof then let
  val () = (res := list_vt_nil ())
in
  // nothing
end else let
  val line =
    fileref_get_line_charlst (inp)
  val () =
  (
    res := list_vt_cons{line}{0}(line, _)
  )
  val+list_vt_cons (_, res1) = res
  val () = loop (inp, res1)
  prval () = fold@ (res)
in
  // nothing
end // end of [if]
//
end // end of [loop]
//
var res: lines
val () = loop (inp, res)
//
in
  res
end // end of [fileref_get_lines_charlstlst]

(* ****** ****** *)

local

fun loop
(
  inp: FILEref
, n: int, res: &ptr? >> charlst_vt
) : int = let
in
//
if n != 0 then let
  val i = fileref_getc (inp)
in
  if i >= 0 then let
    val () =
    (
      res :=
      list_vt_cons{char}{0}((i2c)i, _)
    )
    val+list_vt_cons (_, res1) = res
    val n = loop (inp, pred(n), res1)
    prval () = fold@ (res)
  in
    n
  end else let
    val () = res := list_vt_nil () in (n)
  end // end of [if]
end else let
  val () = res := list_vt_nil () in n(*=0*)
end // end of [if]
//
end // end of [loop]

in (* in of [local] *)

implement
fileref_get_file_charlst
  (inp) = res where {
  var res: ptr; val _ = loop (inp, ~1, res)
} // end of [fileref_get_file_charlst]

implement
fileref_nget_file_charlst
  {n} (inp, n) = let
  var res: ptr; val _(*nleft*) = loop (inp, n, res)
in
  $UN.castvwtp0{listLte_vt(char,n)}(res)
end // end of [fileref_nget_file_charlst]

end // end of [local]

(* ****** ****** *)

implement
fileref_put_charlst
  (out, cs) = let
//
fun loop
(
  out: FILEref, cs: List(char)
) : void = let
in
//
case+ cs of
| list_cons (c, cs) => let
    val () = fileref_putc (out, c) in loop (out, cs)
  end // end of [list_cons]
| list_nil ((*void*)) => ()
//
end // end of [loop]
//
in
  loop (out, cs)
end // end of [fileref_put_charlst]

(* ****** ****** *)

implement{}
fileref_get_line_string$bufsize () = 64
implement{}
fileref_get_file_string$bufsize () = 1024

(* ****** ****** *)

implement{}
fileref_get_line_string
  (inp) = let
  var nlen: int // uninitialized
  val line = fileref_get_line_string_main (inp, nlen)
  prval () = lemma_strnptr_param (line)
in
  strnptr2strptr (line)
end // end of [fileref_get_line_string]

(* ****** ****** *)

implement{}
fileref_get_line_string_main
  (inp, nlen) = let
//
val bsz = fileref_get_line_string$bufsize ()
val [l:addr,n:int] str = $extfcall
(
Strnptr0, "atspre_fileref_get_line_string_main2", bsz, inp, addr@(nlen)
)
//
prval () = lemma_strnptr_param (str)
//
extern
praxi
__assert {l:addr} (pf: !int? @ l >> int (n) @ l): void
prval () = __assert (view@(nlen)) 
//
val isnot = strnptr_isnot_null (str)
//
in
//
if isnot then str else let
  val (
  ) = exit_errmsg_void (1, "[fileref_get_line_string] failed.")
  val () = assert (nlen >= 0) // HX: for TC // deadcode at run-time
in
  str // HX: [str]=null is not returned
end (* end of [if] *)
//
end // end of [fileref_get_line_string_main]

(* ****** ****** *)

implement{}
fileref_get_lines_stringlst
  (inp) = let
//
vtypedef line = Strptr1
vtypedef lines = List0_vt (line)
//
fun loop
(
  inp: FILEref
, res: &lines? >> lines
) : void = let
  val iseof = fileref_is_eof (inp)
in
//
if iseof then let
  val () = (res := list_vt_nil ())
in
  // nothing
end else let
  val line =
    fileref_get_line_string (inp)
  val () =
  (
    res := list_vt_cons{line}{0}(line, _)
  )
  val+list_vt_cons (_, res1) = res
  val () = loop (inp, res1)
  prval () = fold@ (res)
in
  // nothing
end // end of [if]
//
end // end of [loop]
//
var res: lines
val () = loop (inp, res)
//
in
  res
end // end of [fileref_get_lines_stringlst]

(* ****** ****** *)

implement{}
fileref_get_file_string (inp) = let
//
#define CNUL '\000'
//
fun loop
(
  inp: FILEref
, p0: ptr, n0: size_t, p1: ptr, n1: size_t
) : Strptr1 = let
//
val nw = $extfcall (size_t, "atslib_fread", p1, 1, n1, inp)
//
in
//
if nw > 0
then let
  val n1 = n1 - nw
  val p1 = add_ptr_bsz (p1, nw)
in
  if n1 > 0 then
    loop (inp, p0, n0, p1, n1) else loop2 (inp, p0, n0)
  // end of [if]
end else let
  val () = $UN.ptr0_set<char> (p1, CNUL) in $UN.castvwtp0{Strptr1}(p0)
end // end of [if]
//
end // end of [loop]
//
and loop2
(
  inp: FILEref, p0: ptr, n0: size_t
) : Strptr1 = let
  val bsz = succ(n0)
  val bsz2 = g1ofg0(bsz + bsz)
  val (pf, pfgc | p0_) = malloc_gc (bsz2)
  val p0_ = $UN.castvwtp0{ptr}((pf, pfgc | p0_))
  val _(*ptr*) = $extfcall (ptr, "atslib_memcpy", p0_, p0, n0)
  val () = strptr_free ($UN.castvwtp0{Strptr1}(p0))
  val n0_ = pred(g0ofg1(bsz2))
  val p1_ = add_ptr_bsz (p0_, n0)
in
  loop (inp, p0_, n0_, p1_, bsz)
end // end of [loop2]
//
val bsz =
  fileref_get_file_string$bufsize ()
val bsz = i2sz(bsz)
val (pf, pfgc | p0_) = malloc_gc (bsz)
val p0_ = $UN.castvwtp0{ptr}((pf, pfgc | p0_))
val n0_ = pred(bsz)
//
in
  loop (inp, p0_, n0_, p0_, n0_)
end // end of [fileref_get_file_string]

(* ****** ****** *)

%{
extern
atstype_ptr
atspre_fileref_get_line_string_main2
(
  atstype_int bsz0
, atstype_ptr filp0
, atstype_ref nlen // int *nlen
)
{
//
  int bsz = bsz0 ;
  FILE *filp = (FILE*)filp0 ;
  int ofs = 0, ofs2 ;
  char *buf, *buf2, *pres ;
  buf = atspre_malloc_gc(bsz) ;
//
  while (1) {
    buf2 = buf+ofs ;
    pres = fgets(buf2, bsz-ofs, filp) ;
    if (!pres)
    {
      if (feof(filp))
      {
        *buf2 = '\000' ;
        *(int*)nlen = ofs ; return buf ;
      } else {
        atspre_mfree_gc(buf) ;
        *(int*)nlen = -1 ; return (char*)0 ;
      } // end of [if]
    }
    ofs2 = strlen(buf2) ;
    if (ofs2==0) return buf ;
    ofs += ofs2 ; // HX: ofs > 0
//
// HX: the newline symbol needs to be trimmed:
//
    if (buf[ofs-1]=='\n')
    {
      buf[ofs-1] = '\0'; *(int*)nlen = ofs-1 ; return buf ;
    }
//
// HX: there is room // so there are no more chars:
//
    if (ofs+1 < bsz) { *(int*)nlen = ofs ; return buf ; }
//
// HX: there is no room // so another call to [fgets] is needed:
//
    bsz *= 2 ;
    buf2 = buf ; buf = atspre_malloc_gc(bsz) ; memcpy(buf, buf2, ofs) ;
    atspre_mfree_gc(buf2) ;
  } // end of [while]
//
  return buf ; // HX: deadcode
//
} // end of [atspre_fileref_get_line_string_main2]
%}

(* ****** ****** *)

(* end of [filebas.dats] *)
