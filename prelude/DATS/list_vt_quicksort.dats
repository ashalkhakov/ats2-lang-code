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
** $PATSHOME/prelude/DATS/CODEGEN/list_vt_quicksort.atxt
** Time of generation: Mon Jul 22 19:30:22 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: Feburary, 2012 *)

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

implement{a}
list_vt_quicksort$cmp (x1, x2) = gcompare_ref<a> (x1, x2)

(*
** HX-2012-05:
** copy a list into an array, perform quicksort on the
** array and then copy it back into the list
*)
implement{a}
list_vt_quicksort
  {n} (xs) = let
//
fun copyout
  {n:nat} .<n>.
(
  xs: !list_vt (a, n), p: ptr
) :<!wrt> void = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs1) => let
    val (
    ) = $UN.ptr0_set<a> (p, $UN.ptr0_get<a> (addr@(x)))
    val () = copyout (xs1, ptr0_succ<a> (p))
  in
    fold@ (xs)
  end // end of [list_vt_cons]
| list_vt_nil ((*void*)) => ()
//
end // end of [copyout]
//
fun copyinto
  {n:nat} .<n>.
(
  xs: !list_vt (a, n), p: ptr
) :<!wrt> void = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs1) => let
    val (
    ) = $UN.ptr0_set<a> (addr@(x), $UN.ptr0_get<a> (p))
    val () = copyinto (xs1, ptr0_succ<a> (p))
  in
    fold@ (xs)
  end // end of [list_vt_cons]
| list_vt_nil ((*void*)) => ()
//
end // end of [copyinto]
//
implement
array_quicksort$cmp<a>
  (x1, x2) = list_vt_quicksort$cmp<a> (x1, x2)
// end of [array_quicksort$cmp]
//
prval () = lemma_list_vt_param (xs)
//
val n = list_vt_length (xs)
//
val [l:addr]
  (pfat, pfgc | p0) = array_ptr_alloc<a> ((i2sz)n)
//
extern praxi
__out (pf: !array_v (a?, l, n) >> array_v (a, l, n)): void
extern praxi
__into (pf: !array_v (a, l, n) >> array_v (a?, l, n)): void
//
val () = copyout (xs, p0)
prval () = __out (pfat)
val () = array_quicksort<a> (!p0, (i2sz)n)
prval () = __into (pfat)
val () = copyinto (xs, p0)
//
val () = array_ptr_free {a} (pfat, pfgc | p0)
//
in
  xs
end // end of [list_vt_quicksort]

(* ****** ****** *)

implement{a}
list_vt_quicksort_fun
  (xs, cmp) = let
//
implement
list_vt_quicksort$cmp<a> (x1, x2) = cmp (x1, x2)
//
in
  list_vt_quicksort (xs)
end // end of [list_vt_quicksort_fun]

(* ****** ****** *)

(* end of [list_vt_quicksort.dats] *)
