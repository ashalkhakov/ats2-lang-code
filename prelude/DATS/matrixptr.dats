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
** $PATSHOME/prelude/DATS/CODEGEN/matrixptr.atxt
** Time of generation: Mon Jul 22 19:30:25 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: Feburary, 2012 *)

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

implement{}
arrayptr2matrixptr_int (A, m, n) = $UN.castvwtp0 (A)
implement{}
arrayptr2matrixptr_size (A, m, n) = $UN.castvwtp0 (A)

(* ****** ****** *)

implement{a}
matrixptr_make_elt_int
  {m, n} (m, n, x0) = let
  val mn = $UN.cast{Size}(m * n)
in
  $UN.castvwtp0{matrixptr(a,m,n)}(arrayptr_make_elt<a> (mn, x0))
end // end of [matrixptr_make_elt_int]

implement{a}
matrixptr_make_elt_size
  {m, n} (m, n, x0) = let
  val mn = $UN.cast{Size}(m * n)
in
  $UN.castvwtp0{matrixptr(a,m,n)}(arrayptr_make_elt<a> (mn, x0))
end // end of [matrixptr_make_elt_size]

(* ****** ****** *)

implement{a}
matrixptr_get_at_int
  (A, i, n, j) = let
  val ij = $UN.cast{Size}(i * n + j)
in
  $UN.ptr0_get<a> (ptr_add<a> (ptrcast(A), ij))
end // end of [matrixptr_get_at_int]

implement{a}
matrixptr_get_at_size
  (A, i, n, j) = let
  val ij = $UN.cast{Size}(i * n + j)
in
  $UN.ptr0_get<a> (ptr_add<a> (ptrcast(A), ij))
end // end of [matrixptr_get_at_size]

(* ****** ****** *)

implement{a}
matrixptr_set_at_int
  (A, i, n, j, x) = let
  val ij = $UN.cast{Size}(i * n + j)
in
  $UN.ptr0_set<a> (ptr_add<a> (ptrcast(A), ij), x)
end // end of [matrixptr_set_at_int]

implement{a}
matrixptr_set_at_size
  (A, i, n, j, x) = let
  val ij = $UN.cast{Size}(i * n + j)
in
  $UN.ptr0_set<a> (ptr_add<a> (ptrcast(A), ij), x)
end // end of [matrixptr_set_at_size]

(* ****** ****** *)

implement{a}
matrixptr_exch_at_int
  (A, i, n, j, x) = let
  val ij = $UN.cast{Size}(i * n + j)
in
  $UN.ptr0_exch<a> (ptr_add<a> (ptrcast(A), ij), x)
end // end of [matrixptr_exch_at_int]

implement{a}
matrixptr_exch_at_size
  (A, i, n, j, x) = let
  val ij = $UN.cast{Size}(i * n + j)
in
  $UN.ptr0_exch<a> (ptr_add<a> (ptrcast(A), ij), x)
end // end of [matrixptr_exch_at_size]

(* ****** ****** *)

implement{a}
fprint_matrixptr
  {m,n} (out, M, m, n) = let
//
val p0 = ptrcast (M)
//
val (
  pf, fpf | p0
) = $UN.ptr_vtake {matrix(a,m,n)} (p0)
val () = fprint_matrix<a> (out, !p0, m, n)
prval () = fpf (pf)
//
in
  // nothing
end // end of [fprint_matrixptr]

(* ****** ****** *)

implement{a}
fprint_matrixptr_sep
(
  out, M, m, n, sep1, sep2
) = let
//
implement
fprint_matrix$sep1<> (out) = fprint_string (out, sep1)
implement
fprint_matrix$sep2<> (out) = fprint_string (out, sep2)
//
in
  fprint_matrixptr<a> (out, M, m, n)
end // end of [fprint_matrixptr_sep]

(* ****** ****** *)

(*
implement matrixptr_free = ATS_MFREE
*)

(* ****** ****** *)

(* end of [matrixptr.dats] *)
