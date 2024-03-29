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
** $PATSHOME/prelude/DATS/CODEGEN/arrayptr.atxt
** Time of generation: Mon Jul 22 19:30:24 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: May, 2012 *)

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

implement{a}
arrayptr_make_elt
  (asz, elt) = let
//
val
(
  pf, pfgc | p
) = array_ptr_alloc<a> (asz)
//
val () = array_initize_elt<a> (!p, asz, elt)
//
in
  arrayptr_encode(pf, pfgc | p)
end // end of [arrayptr_make_elt]

(* ****** ****** *)

implement{}
arrayptr_make_intrange
  {l,r} (l, r) = let
//
val asz = g1int2uint (r-l)
val [A:addr] A =
  arrayptr_make_uninitized<int> (asz)
//
fun loop
  {n:nat} .<n>. (
  p: ptr, asz: size_t n, l: int
) :<!wrt> void = let
in
//
if asz > 0 then let
  val () = $UN.ptr0_set<int> (p, l)
in
  loop (ptr0_succ<int> (p), pred (asz), l+1)
end else () // end of [if]
//
end // end of [loop]
//
val () = loop (ptrcast (A), asz, l)
//
in
  $UN.castvwtp0{arrayptr(intBtw(l,r),A,r-l)}(A)
end // end of [arrayptr_make_intrange]

(* ****** ****** *)

implement{a}
arrayptr_make_list
  (asz, xs) = let
//
prval () = lemma_list_param (xs)
//
val (
  pf, pfgc | p
) = array_ptr_alloc<a> (i2sz(asz))
//
val () = array_initize_list<a> (!p, asz, xs)
//
in
  arrayptr_encode(pf, pfgc | p)
end // end of [arrayptr_make_list]

implement{a}
arrayptr_make_rlist
  (asz, xs) = let
//
prval () = lemma_list_param (xs)
//
val (
  pf, pfgc | p
) = array_ptr_alloc<a> (i2sz(asz))
//
val () = array_initize_rlist<a> (!p, asz, xs)
//
in
  arrayptr_encode(pf, pfgc | p)
end // end of [arrayptr_make_rlist]

(* ****** ****** *)

implement{a}
arrayptr_make_list_vt
  (asz, xs) = let
//
prval () = lemma_list_vt_param (xs)
//
val (
 pf, pfgc | p
) = array_ptr_alloc<a> (i2sz(asz))
val () = array_initize_list_vt<a> (!p, asz, xs)
//
in
  arrayptr_encode(pf, pfgc | p)
end // end of [arrayptr_make_list_vt]

implement{a}
arrayptr_make_rlist_vt
  (asz, xs) = let
//
prval () = lemma_list_vt_param (xs)
//
val (
 pf, pfgc | p
) = array_ptr_alloc<a> (i2sz(asz))
val () = array_initize_rlist_vt<a> (!p, asz, xs)
//
in
  arrayptr_encode(pf, pfgc | p)
end // end of [arrayptr_make_rlist_vt]

(* ****** ****** *)

implement{a}
arrayptr_make_uninitized
  (asz) = let
in
  arrayptr_encode2(array_ptr_alloc<a> (asz))
end // end of [arrayptr_uninitize]

(* ****** ****** *)

implement{a}
arrayptr_imake_list
  (A, asz) = res where
{
//
val p = ptrcast(A)
prval pf = arrayptr_takeout (A)
val res = list_make_array (!p, asz)
prval () = arrayptr_addback (pf | A)
} // end of [arrayptr_imake_list]

(* ****** ****** *)

(*
implement arrayptr_free = ATS_MFREE
*)

(* ****** ****** *)

implement{a}
fprint_arrayptr
  (out, A, n) = () where
{
//
val p = ptrcast(A)
prval pf = arrayptr_takeout (A)
val () = fprint_array<a> (out, !p, n)
prval () = arrayptr_addback (pf | A)
//
} // end of [fprint_arrayptr]

(* ****** ****** *)

implement{a}
fprint_arrayptr_sep
  (out, A, n, sep) = () where
{
//
val p = ptrcast (A)
prval pf = arrayptr_takeout (A)
val () = fprint_array_sep<a> (out, !p, n, sep)
prval () = arrayptr_addback (pf | A)
//
} // end of [fprint_arrayptr_sep]

(* ****** ****** *)

implement{a}{tk}
arrayptr_get_at_gint
  (A, i) = let
  val p = ptrcast (A) in
  $UN.ptr0_get<a> (ptr1_add_gint<a><tk> (p, i))
end // end of [arrayptr_get_at_gint]

implement{a}{tk}
arrayptr_get_at_guint
  (A, i) = let
  val p = ptrcast (A) in
  $UN.ptr0_get<a> (ptr1_add_guint<a><tk> (p, i))
end // end of [arrayptr_get_at_guint]

(* ****** ****** *)

implement{a}{tk}
arrayptr_set_at_gint
  (A, i, x) = let
  val p = ptrcast (A) in
  $UN.ptr0_set<a> (ptr1_add_gint<a><tk> (p, i), x)
end // end of [arrayptr_set_at_gint]

implement{a}{tk}
arrayptr_set_at_guint
  (A, i, x) = let
  val p = ptrcast (A) in
  $UN.ptr0_set<a> (ptr1_add_guint<a><tk> (p, i), x)
end // end of [arrayptr_set_at_guint]

(* ****** ****** *)

implement{a}
arrayptr_interchange
  (A, i, j) = let
//
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val () = array_interchange (!p, i, j)
  prval () = arrayptr_addback (pfarr | A)
//
in
  // noting
end // end of [arrayptr_interchange]

(* ****** ****** *)

implement{a}
arrayptr_foreach (A, asz) = let
  var env: void = () in arrayptr_foreach_env<a><void> (A, asz, env)
end // end of [arrayptr_foreach]

implement
{a}{env}
arrayptr_foreach_env
  (A, asz, env) = res where {
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val res = array_foreach_env<a><env> (!p, asz, env)
  prval () = arrayptr_addback (pfarr | A)
} // end of [arrayptr_foreach_env]

(* ****** ****** *)

implement{a}
arrayptr_foreach_fun
  (A, asz, f) = let
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val () = array_foreach_fun<a> (!p, asz, f)
  prval () = arrayptr_addback (pfarr | A)
in
  // nothing
end // end of [arrayptr_foreach_fun]

(* ****** ****** *)

implement{a}
arrayptr_foreach_funenv
  (pfv | A, asz, f, env) = let
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val () = array_foreach_funenv<a> (pfv | !p, asz, f, env)
  prval () = arrayptr_addback (pfarr | A)
in
  // nothing
end // end of [arrayptr_foreach_funenv]

(* ****** ****** *)

implement{a}
arrayptr_iforeach (A, asz) = let
  var env: void = () in arrayptr_iforeach_env<a><void> (A, asz, env)
end // end of [arrayptr_iforeach]

implement
{a}{env}
arrayptr_iforeach_env
  (A, asz, env) = res where {
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val res = array_iforeach_env<a><env> (!p, asz, env)
  prval () = arrayptr_addback (pfarr | A)
} // end of [arrayptr_iforeach_env]

(* ****** ****** *)

implement{a}
arrayptr_rforeach (A, asz) = let
  var env: void = () in arrayptr_rforeach_env<a><void> (A, asz, env)
end // end of [arrayptr_rforeach]

implement
{a}{env}
arrayptr_rforeach_env
  (A, asz, env) = res where {
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val res = array_rforeach_env<a><env> (!p, asz, env)
  prval () = arrayptr_addback (pfarr | A)
} // end of [arrayptr_rforeach_env]

(* ****** ****** *)

implement{a}
arrayptr_initize
  (A, asz) = () where {
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val () = array_initize<a> (!p, asz)
  prval () = arrayptr_addback (pfarr | A)
} // end of [arrayptr_initize]

(* ****** ****** *)

implement{a}
arrayptr_uninitize
  (A, asz) = () where {
  val p = ptrcast (A)
  prval pfarr = arrayptr_takeout (A)
  val () = array_uninitize<a> (!p, asz)
  prval () = arrayptr_addback (pfarr | A)
} // end of [arrayptr_uninitize]

(* ****** ****** *)

implement{a}
arrayptr_freelin
  (A, asz) = let
//
val () = arrayptr_uninitize<a> (A, asz)
//
in
  arrayptr_free{a?}(A)
end // end of [arrayptr_freelin]

(* ****** ****** *)

implement{a}
arrayptr_tabulate
  (asz) = arrayptr_encode2(array_ptr_tabulate<a> (asz))
// end of [arrayptr_tabulate]

(* ****** ****** *)

(* end of [arrayptr.dats] *)
