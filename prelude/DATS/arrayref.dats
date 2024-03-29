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
** $PATSHOME/prelude/DATS/CODEGEN/arrayref.atxt
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
arrayref_make_elt (asz, x) =
  arrayptr_refize(arrayptr_make_elt<a> (asz, x))
// end of [arrayref_make_elt]

(* ****** ****** *)

implement{a}
arrayref_make_list (asz, xs) =
  arrayptr_refize(arrayptr_make_list<a> (asz, xs))
// end of [arrayref_make_list]

implement{a}
arrayref_make_rlist (asz, xs) =
  arrayptr_refize(arrayptr_make_rlist<a> (asz, xs))
// end of [arrayref_make_rlist]

(* ****** ****** *)

implement{a}
arrayref_get_at_size
  (A, i) = let
//
val
(
vbox pf | p
) = arrayref_get_viewptr (A)
//
in
  array_get_at_size (!p, i)
end // end of [arrayref_get_at_size]

implement{a}{tk}
arrayref_get_at_gint
  (A, i) =
(
  arrayref_get_at_size (A, g1i2u(i))
) // end of [arrayref_get_at_gint]

implement{a}{tk}
arrayref_get_at_guint
  (A, i) =
(
  arrayref_get_at_size (A, g1u2u(i))
) // end of [arrayref_get_at_guint]

(* ****** ****** *)

implement{a}
arrayref_set_at_size
  (A, i, x) = let
//
val (vbox pf | p) =
  arrayref_get_viewptr (A) in array_set_at_size (!p, i, x)
//
end // end of [arrayref_set_at_size]

implement{a}{tk}
arrayref_set_at_gint
  (A, i, x) =
(
  arrayref_set_at_size (A, g1i2u(i), x)
) // end of [arrayref_set_at_gint]

implement{a}{tk}
arrayref_set_at_guint
  (A, i, x) =
(
  arrayref_set_at_size (A, g1u2u(i), x)
) // end of [arrayref_set_at_guint]

(* ****** ****** *)

implement{a}
arrayref_exch_at_size
  (A, i, x) = let
//
val (vbox pf | p) =
  arrayref_get_viewptr (A) in array_exch_at_size (!p, i, x)
//
end // end of [arrayref_exch_at_size]

implement{a}{tk}
arrayref_exch_at_gint
  (A, i, x) =
(
  arrayref_exch_at_size (A, g1i2u(i), x)
) // end of [arrayref_exch_at_gint]

implement{a}{tk}
arrayref_exch_at_guint
  (A, i, x) =
(
  arrayref_exch_at_size (A, g1u2u(i), x)
) // end of [arrayref_exch_at_guint]

(* ****** ****** *)

implement{a}
arrayref_interchange
  (A, i, j) = let
//
val (vbox pf | p) =
  arrayref_get_viewptr (A) in array_interchange (!p, i, j)
//
end // end of [arrayref_interchange]

(* ****** ****** *)

implement{a}
fprint_arrayref
  (out, A, n) = let
  val (
    vbox pf | p
  ) = arrayref_get_viewptr (A)
in
  $effmask_ref (fprint_array (out, !p, n))
end // end of [fprint_arrayref]

implement{a}
fprint_arrayref_sep
  (out, A, n, sep) = let
  val (
    vbox pf | p
  ) = arrayref_get_viewptr (A)
in
  $effmask_ref (fprint_array_sep (out, !p, n, sep))
end // end of [fprint_arrayref_sep]

(* ****** ****** *)

implement{a}
arrayref_foreach (A, asz) = let
  var env: void = () in arrayref_foreach_env<a><void> (A, asz, env)
end // end of [arrayref_foreach]

implement
{a}{env}
arrayref_foreach_env
  (A, asz, env) = let
  val (vbox pf | p) = arrayref_get_viewptr (A)
in
  $effmask_ref (array_foreach_env<a><env> (!p, asz, env))
end // end of [arrayref_foreach_env]

(* ****** ****** *)

implement{a}
arrayref_iforeach (A, asz) = let
  var env: void = () in arrayref_iforeach_env<a><void> (A, asz, env)
end // end of [arrayref_iforeach]

implement
{a}{env}
arrayref_iforeach_env
  (A, asz, env) = let
  val (vbox pf | p) = arrayref_get_viewptr (A)
in
  $effmask_ref (array_iforeach_env<a><env> (!p, asz, env))
end // end of [arrayref_iforeach_env]

(* ****** ****** *)

implement{a}
arrayref_rforeach (A, asz) = let
  var env: void = () in arrayref_rforeach_env<a><void> (A, asz, env)
end // end of [arrayref_rforeach]

implement
{a}{env}
arrayref_rforeach_env
  (A, asz, env) = let
  val (vbox pf | p) = arrayref_get_viewptr (A)
in
  $effmask_ref (array_rforeach_env<a><env> (!p, asz, env))
end // end of [arrayref_rforeach_env]

(* ****** ****** *)

implement{a}
arrayref_tabulate
  (asz) = arrayptr_refize (arrayptr_tabulate (asz))
// end of [arrayref_tabulate]

(* ****** ****** *)

local

datatype
arrszref
(
  a:viewt@ype
) =
  {n:int}
  ARRSZREF of (arrayref (a, n), size_t (n))
// end of [arrszref]

assume
arrszref_vt0ype_type = arrszref

in (* in of [local] *)

implement{}
arrszref_make_arrpsz
  (psz) = let
//
var asz: size_t
val A = arrpsz_get_ptrsize (psz, asz)
val A = arrayptr_refize (A)
//
in
  ARRSZREF (A, asz)
end // end of [arrszref_make_arrpsz]

implement{}
arrszref_make_arrayref (A, asz) = ARRSZREF (A, asz)

(* ****** ****** *)

implement{}
arrszref_get_ref
  (ASZ) = let
  val+ARRSZREF
    (A, _) = ASZ in $UN.cast2Ptr1(A)
  // end of [val]
end // end of [arrszref_get_ref]

implement{}
arrszref_get_size
  (ASZ) = let
  val+ARRSZREF (_(*A*), asz) = ASZ in asz
end // end of [arrszref_get_size]

implement{}
arrszref_get_refsize
  (ASZ, aszr) = let
//
val+ARRSZREF (A, asz) = ASZ
prval () = lemma_arrayref_param (A)
//
in
  aszr := asz; A
end // end of [arrszref_get_refsize]

end // end of [local]

(* ****** ****** *)

implement{a}
arrszref_make_elt
  (asz, x) = let
  val asz = g1ofg0_uint (asz)
  val A = arrayref_make_elt<a> (asz, x)
in
  arrszref_make_arrayref (A, asz)
end // end of [arrszref_make_elt]

(* ****** ****** *)

implement{a}
arrszref_make_list
  (xs) = let
//
prval () = lemma_list_param (xs)
//
val n = list_length<a> (xs)
val A = arrayref_make_list (n, xs)
val asz = (i2sz)n
//
in
  arrszref_make_arrayref (A, asz)
end // end of [arrszref_make_list]

implement{a}
arrszref_make_rlist
  (xs) = let
//
prval () = lemma_list_param (xs)
//
val n = list_length<a> (xs)
val A = arrayref_make_rlist (n, xs)
val asz = (i2sz)n
//
in
  arrszref_make_arrayref (A, asz)
end // end of [arrszref_make_rlist]

(* ****** ****** *)

implement{a}
fprint_arrszref
  (out, ASZ) = let
//
var asz: size_t
val A = arrszref_get_refsize (ASZ, asz)
//
in
  fprint_arrayref (out, A, asz)
end // end of [fprint_arrszref]

implement{a}
fprint_arrszref_sep
  (out, ASZ, sep) = let
//
var asz: size_t
val A = arrszref_get_refsize (ASZ, asz)
//
in
  fprint_arrayref_sep (out, A, asz, sep)
end // end of [fprint_arrszref_sep]

(* ****** ****** *)

implement{a}
arrszref_get_at_size
  (ASZ, i) = $effmask_wrt let
//
var n: size_t
val A = arrszref_get_refsize (ASZ, n)
val i = g1ofg0_uint (i)
//
in
//
if n > i
  then arrayref_get_at_size (A, i)
  else $raise ArraySubscriptExn((*fun*))
//
end // end of [arrszref_get_at_size]

implement
{a}{tk}
arrszref_get_at_gint
  (ASZ, i) = let
in
//
if i >= 0
  then arrszref_get_at_size (ASZ, g0i2u(i))
  else $raise ArraySubscriptExn((*fun*)) // i < 0
//
end // end of [arrszref_get_at_gint]

implement
{a}{tk}
arrszref_get_at_guint
  (ASZ, i) = let
in
  arrszref_get_at_size (ASZ, g0u2u(i))
end // end of [arrszref_get_at_guint]

(* ****** ****** *)

implement{a}
arrszref_set_at_size
  (ASZ, i, x) = $effmask_wrt let
//
var n: size_t
val A = arrszref_get_refsize (ASZ, n)
val i = g1ofg0_uint (i)
//
in
//
if n > i
  then arrayref_set_at_size (A, i, x)
  else $raise ArraySubscriptExn((*fun*))
//
end // end of [arrszref_set_at_size]

implement
{a}{tk}
arrszref_set_at_gint
  (ASZ, i, x) = let
in
//
if i >= 0
  then arrszref_set_at_size (ASZ, g0i2u(i), x)
  else $raise ArraySubscriptExn((*fun*)) // i < 0
//
end // end of [arrszref_set_at_gint]

implement
{a}{tk}
arrszref_set_at_guint
  (ASZ, i, x) = let
in
  arrszref_set_at_size (ASZ, g0u2u(i), x)
end // end of [arrszref_set_at_guint]

(* ****** ****** *)

implement{a}
arrszref_exch_at_size
  (ASZ, i, x) = $effmask_wrt let
//
var n: size_t
val A = arrszref_get_refsize (ASZ, n)
val i = g1ofg0_uint (i)
//
in
//
if n > i
  then arrayref_exch_at_size (A, i, x)
  else $raise ArraySubscriptExn((*fun*))
// end of [if]
//
end // end of [arrszref_exch_at_size]

implement
{a}{tk}
arrszref_exch_at_gint
  (ASZ, i, x) = let
in
//
if i >= 0
  then arrszref_exch_at_size (ASZ, g0i2u(i), x)
  else $raise ArraySubscriptExn((*fun*)) // i < 0
//
end // end of [arrszref_exch_at_gint]

implement
{a}{tk}
arrszref_exch_at_guint
  (ASZ, i, x) = let
in
  arrszref_exch_at_size (ASZ, g0u2u(i), x)
end // end of [arrszref_exch_at_guint]

(* ****** ****** *)

implement{a}
arrszref_tabulate (asz) = let
  val asz = g1ofg0_uint (asz)
  val A = arrayref_tabulate<a> (asz) in arrszref_make_arrayref(A, asz)
end // end of [arrszref_tabulate]

(* ****** ****** *)

(* end of [arrayref.dats] *)
