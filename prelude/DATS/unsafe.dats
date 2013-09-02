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
** $PATSHOME/prelude/DATS/CODEGEN/unsafe.atxt
** Time of generation: Mon Jul 22 19:30:21 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: April, 2012 *)

(* ****** ****** *)

staload "prelude/SATS/unsafe.sats"

(* ****** ****** *)

implement
{a}(*tmp*)
ptr0_get
  (p) = x where {
  val [l:addr]
    p = g1ofg0_ptr(p)
  prval (pf, fpf) = __assert () where {
    extern praxi __assert (): (a @ l, a? @ l -<lin,prf> void)
  } // end of [prval]
  val x = !p
  prval () = fpf (pf)
} // end of [ptr0_get]

implement{a} ptr1_get = ptr0_get<a>

(* ****** ****** *)

implement
{a}(*tmp*)
ptr0_set
  (p, x) = () where {
  val [l:addr]
    p = g1ofg0_ptr(p)
  prval (pf, fpf) = __assert () where {
    extern praxi __assert (): (a? @ l, a @ l -<lin,prf> void)
  } // end of [prval]
  val () = !p := x
  prval () = fpf (pf)
} // end of [ptr0_set]

implement{a} ptr1_set = ptr0_set<a>

(* ****** ****** *)

implement
{a}(*tmp*)
ptr0_exch
  (p, x) = () where {
  val p = g1ofg0_ptr(p)
  val (pf, fpf | p) = ptr_vtake{a}(p)
  val tmp = !p
  val ( ) = !p := x
  val ( ) = x := tmp
  prval () = fpf (pf)
} // end of [ptr0_exch]

implement{a} ptr1_exch = ptr0_exch<a>

(* ****** ****** *)

implement
{a}(*tmp*)
ptr0_intch
  (p1, p2) = () where {
  val p1 = g1ofg0_ptr(p1)
  val p2 = g1ofg0_ptr(p2)
  val (pf1, fpf1 | p1) = ptr_vtake{a}(p1)
  val (pf2, fpf2 | p2) = ptr_vtake{a}(p2)
  val tmp = !p1
  val ( ) = !p1 := !p2
  val ( ) = !p2 := tmp
  prval () = fpf1 (pf1)
  prval () = fpf2 (pf2)
} (* end of [ptr0_intch] *)

implement{a} ptr1_intch = ptr0_intch<a>

(* ****** ****** *)

implement{a}
cptr_get (p) = ptr1_get<a> (cptr2ptr(p))

implement{a}
cptr_set (p, x) = ptr1_set<a> (cptr2ptr(p), x)

implement{a}
cptr_exch (p, x) = ptr1_exch<a> (cptr2ptr(p), x)

(* ****** ****** *)

implement{a}
ptr0_addby (p, x) = let
  val x0 = ptr0_get<a> (p) in ptr0_set<a> (p, gadd_val<a> (x0, x))
end // end of [ptr0_addby]
implement{a} ptr1_addby = ptr0_addby<a>

implement{a}
ptr0_subby (p, x) = let
  val x0 = ptr0_get<a> (p) in ptr0_set<a> (p, gsub_val<a> (x0, x))
end // end of [ptr0_subby]
implement{a} ptr1_subby = ptr0_subby<a>

implement{a}
ptr0_mulby (p, x) = let
  val x0 = ptr0_get<a> (p) in ptr0_set<a> (p, gmul_val<a> (x0, x))
end // end of [ptr0_mulby]
implement{a} ptr1_mulby = ptr0_mulby<a>

implement{a}
ptr0_divby (p, x) = let
  val x0 = ptr0_get<a> (p) in ptr0_set<a> (p, gdiv_val<a> (x0, x))
end // end of [ptr0_divby]
implement{a} ptr1_divby = ptr0_divby<a>

implement{a}
ptr0_modby (p, x) = let
  val x0 = ptr0_get<a> (p) in ptr0_set<a> (p, gmod_val<a> (x0, x))
end // end of [ptr0_modby]
implement{a} ptr1_modby = ptr0_modby<a>

(* ****** ****** *)

(* end of [unsafe.dats] *)
