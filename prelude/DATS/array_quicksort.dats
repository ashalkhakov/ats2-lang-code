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
** $PATSHOME/prelude/DATS/CODEGEN/array.atxt
** Time of generation: Sat Aug 10 22:13:09 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: April, 2013 *)

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

(*
//
// HX-2013-04:
// Instead of employing advanced types, I happily
// ventured into the typeless territory of unsafe
// pointer arithmetic!
//
*)

implement{a}
array_quicksort
  (A, asz) = let
//
overload + with add_ptr0_bsz
overload - with sub_ptr0_bsz
//
(* ****** ****** *)
//
fun ptrcmp
(
  p1: ptr, p2: ptr
) : int = (sgn) where
{
//
val p1 = g1ofg0_ptr(p1)
val p2 = g1ofg0_ptr(p2)
//
val
(
  pf1, fpf1 | p1
) = $UN.ptr_vtake{a}(p1)
val
(
  pf2, fpf2 | p2
) = $UN.ptr_vtake{a}(p2)
//
val sgn = array_quicksort$cmp<a> (!p1, !p2)
//
prval () = fpf1 (pf1)
prval () = fpf2 (pf2)
//
} (* end of [ptrcmp] *)

(* ****** ****** *)
(*
//
// HX-2013-04:
// move min to the start
// HX-2013-04:
// this is not a safe approach
// in case [cmp] is not transitive!
//
fun auxmin
(
  pa: ptr, p: ptr, tsz: size_t
) : void = let
in
//
if pa < p then let
  val p1 = p - tsz
  val sgn = ptrcmp (p1, p)
  val () =
    if sgn > 0 then $UN.ptr0_intch<a> (p1, p)
  // end of [val]
in
  auxmin (pa, p1, tsz)
end (* end of [if] *)
//
end (* end of [auxmin] *)
*)
//
// HX: one round of insertion
//
fun auxins
(
  pa: ptr, p: ptr, tsz: size_t
) : void = let
in
//
if pa < p then let
  val p1 = p - tsz
  val sgn = ptrcmp (p1, p)
in
  if sgn > 0 then let
    val () = $UN.ptr0_intch<a> (p1, p) in auxins (pa, p1, tsz)
  end // end of [if]
end else () // end of [if]
//
end (* end of [auxins] *)
//
// HX: all rounds of insertion
//
fun auxinss
(
  pa: ptr, pz: ptr, p: ptr, tsz: size_t
) : void = let
in
//
if p < pz then let
  val () = auxins (pa, p, tsz)
in
  auxinss (pa, pz, p + tsz, tsz)
end // end of [if]
//
end (* end of [auxinss] *)

(* ****** ****** *)
//
// HX: insertion sorting
//
fun auxinsort
(
  pa: ptr, asz: size_t, tsz: size_t
) : void = let
  val pz = pa + asz * tsz
in
//
if pa < pz then let
  val () = auxinss (pa, pz, pa + tsz, tsz)
in
  (* nothing *)
end else () // end of [if]
//
end (* end of [auxinsort] *)

(* ****** ****** *)
//
// HX: locate the middle of 3
//
fun auxmid
(
  p1: ptr, p2: ptr, p3: ptr
) : ptr = let
  val sgn12 = ptrcmp (p1, p2)
in
//
if sgn12 <= 0 then (
  if ptrcmp (p2, p3) <= 0
    then p2 else (if ptrcmp (p1, p3) <= 0 then p3 else p1)
) else (
  if ptrcmp (p1, p3) <= 0
    then p1 else (if ptrcmp (p2, p3) <= 0 then p3 else p2)
) // end of [if]
end (* end of [auxmid] *)
//
// HX: pivot to the start
//
fun auxpivot
(
  pa: ptr, asz: size_t, tsz: size_t
) : void = let
//
val pm = auxmid
(
  pa, pa + half(asz) * tsz, pa + pred(asz) * tsz
) (* end of [val] *)
//
in
  $UN.ptr0_intch<a> (pa, pm)
end (* end of [auxpivot] *)

(* ****** ****** *)
//
// HX-2013-04:
// Invariants:
// 1. elements in [pa, pl) <= pivot
// 2. elements in (pr, pz) >= pivot
//
fun auxsplit_l
(
  pa: ptr, pl: ptr, pr: ptr, tsz: size_t
) : ptr =
(
if pl <= pr then let
  val sgn = ptrcmp (pl, pa)
in
//
if sgn <= 0 then auxsplit_l (pa, pl + tsz, pr, tsz) else pl
//
end else pl // end of [if]
) (* end of [auxsplit_l] *)

fun auxsplit_r
(
  pa: ptr, pl: ptr, pr: ptr, tsz: size_t
) : ptr =
(
if pl <= pr then let
  val sgn = ptrcmp (pa, pr)
in
//
if sgn <= 0 then auxsplit_r (pa, pl, pr - tsz, tsz) else pr
//
end else pr // end of [if]
) (* end of [auxsplit_r] *)

fun auxsplit_lr
(
  pa: ptr, pl: ptr, pr: ptr, tsz: size_t
) : ptr = let
  val pl = auxsplit_l (pa, pl, pr, tsz)
  val pr = auxsplit_r (pa, pl, pr, tsz)
in
//
if pl < pr then let
  val () = $UN.ptr0_intch<a> (pl, pr)
in
  auxsplit_lr (pa, pl + tsz, pr - tsz, tsz)
end else pl (* end of [if] *)
//
end (* end of [auxsplit_lr] *)

(* ****** ****** *)

#define CUTOFF 12

(* ****** ****** *)
//
// HX: quick sorting
//
fun auxqsort
(
  pa: ptr, asz: size_t, tsz: size_t
) : void = let
in
//
if asz >= CUTOFF then let
  val () = auxpivot (pa, asz, tsz)
  val pz = pa + asz * tsz
  val pm = auxsplit_lr (pa, pa + tsz, pz - tsz, tsz)
  val pm1 = pm - tsz
  val () = $UN.ptr0_intch<a> (pa, pm1)
  val asz_f = $UN.cast2size(pm1-pa) / tsz
  val asz_r = pred (asz - asz_f)
in
  if asz_f <= asz_r then let
    val () = auxqsort (pa, asz_f, tsz)
    val () = auxqsort (pm, asz_r, tsz)
  in
    // nothing
  end else let
    val () = auxqsort (pm, asz_r, tsz)
    val () = auxqsort (pa, asz_f, tsz)
  in
    // nothing
  end (* end of [if] *)
end else
  auxinsort (pa, asz, tsz)
// end of [if]
//
end (* end of [auxqsort] *)

(* ****** ****** *)

in (* in of [let] *)
//
$effmask_all (auxqsort (addr@(A), asz, sizeof<a>))
//
end (* end of [array_quicksort] *)

(* ****** ****** *)

(*
//
// HX: [qsort] is in libc/stdlib
//
void qsort
(
  void *base, size_t nmemb, size_t size,
  int(*compar)(const void *, const void *)
) ; // end of [qsort]
*)
implement{a}
array_quicksort_stdlib
  (A, asz, cmp) = let
in
  $extfcall (void, "atspre_array_qsort", addr@(A), asz, sizeof<a>, cmp)
end (* end of [array_quicksort_stdlib] *)

(* ****** ****** *)

(* end of [array_quicksort.dats] *)
