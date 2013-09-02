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
** $PATSHOME/prelude/DATS/CODEGEN/reference.atxt
** Time of generation: Mon Jul 22 19:30:16 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: May, 2012 *)

(* ****** ****** *)

implement{a} ref = ref_make_elt<a>

implement{a}
ref_make_elt (x0) = let
  val (pfat, pfgc | p) = ptr_alloc<a> ()
  prval () = mfree_gc_v_elim (pfgc)
  val () = !p := x0 // initialization
in
  ref_make_viewptr (pfat | p)
end // end of [ref_make_elt]

(* ****** ****** *)

implement{a}
ref_get_elt
  (r) = !p where {
  val (vbox _ | p) = ref_get_viewptr (r)
} // end of [ref_get_elt]

implement{a}
ref_set_elt
  (r, x) = let
  val (vbox _ | p) = ref_get_viewptr (r)
in
  !p := x // assignment
end // end of [ref_set_elt]

implement{a}
ref_exch_elt
  (r, x) = let
  val (vbox _ | p) = ref_get_viewptr (r)
in
  !p :=: x // exchanging
end // end of [ref_exch_elt]

(* ****** ****** *)

implement{a}
ref_app_fun (r, f) = let
  val (vbox _ | p) = ref_get_viewptr (r) in f (!p)
end // end of [ref_app_fun]

implement{a}
ref_app_funenv
  (pfv | r, f, env) = let
  val (vbox _ | p) = ref_get_viewptr (r) in f (pfv | !p, env)
end // end of [ref_app_funenv]

(* ****** ****** *)

(* end of [reference.dats] *)
