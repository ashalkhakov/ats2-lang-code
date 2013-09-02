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
** $PATSHOME/prelude/SATS/CODEGEN/matrixref.atxt
** Time of generation: Mon Jul 22 19:30:09 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: April, 2013 *)

(* ****** ****** *)

#define NSH (x) x // for commenting: no sharing
#define SHR (x) x // for commenting: it is shared

(* ****** ****** *)

sortdef tk = tkind

(* ****** ****** *)

sortdef t0p = t@ype and vt0p = viewt@ype

(* ****** ****** *)
//
// matrixref: reference to a matrix with no dimension info attached
//
(* ****** ****** *)

abstype
matrixref_vt0ype_int_int_type
  (a:vt@ype(*invariant*), nrow: int, ncol:int) = ptr
stadef matrixref = matrixref_vt0ype_int_int_type

(* ****** ****** *)

praxi
lemma_matrixref_param
  {a:vt0p}{m,n:int} (A: matrixref (a, m, n)): [m >= 0; n >= 0] void
// end of [lemma_matrixref_param]

(* ****** ****** *)

castfn
matrixptr_refize
  {a:vt0p}
  {l:addr}
  {m,n:int} (
  A: matrixptr (INV(a), l, m, n)
) :<!wrt> matrixref (a, m, n) // end of [matrixptr_refize]

castfn
matrixref_get_viewptr
  {a:vt0p}
  {m,n:int} (
  A: matrixref (a, m, n)
) :<> [l:addr] (vbox (matrix_v (a, l, m, n)) | ptr l)

(* ****** ****** *)

fun{
a:t0p
} matrixref_make_elt_int
  {m,n:nat} (m: int m, n: int n, x: a):<!wrt> matrixref (a, m, n)
fun{
a:t0p
} matrixref_make_elt_size
  {m,n:int} (m: size_t m, n: size_t n, x: a):<!wrt> matrixref (a, m, n)
//
symintr matrixref_make_elt
overload matrixref_make_elt with matrixref_make_elt_int
overload matrixref_make_elt with matrixref_make_elt_size
//
(* ****** ****** *)

fun{a:t0p}
matrixref_get_at_int{m,n:int}
(
  A: matrixref (a, m, n), i: natLt(m), n: int(n), j: natLt(n)
) :<!ref> (a) // end of [matrixref_get_at_int]
overload [] with matrixref_get_at_int

fun{a:t0p}
matrixref_get_at_size{m,n:int}
(
  A: matrixref (a, m, n), i: sizeLt(m), n: size_t(n), j: sizeLt(n)
) :<!ref> (a) // end of [matrixref_get_at_size]
overload [] with matrixref_get_at_size
//
symintr matrixref_get_at
overload matrixref_get_at with matrixref_get_at_int of 0
overload matrixref_get_at with matrixref_get_at_size of 0
//
(* ****** ****** *)

fun{a:t0p}
matrixref_set_at_int
  {m,n:int}
(
  A: matrixref (INV(a), m, n), i: natLt (m), n: int n, j: natLt (n), x: a
) :<!refwrt> void // end of [matrixref_set_at_int]
overload [] with matrixref_set_at_int

fun{a:t0p}
matrixref_set_at_size
  {m,n:int}
(
  A: matrixref (INV(a), m, n), i: sizeLt (m), n: size_t n, j: sizeLt (n), x: a
) :<!refwrt> void // end of [matrixref_set_at_size]
overload [] with matrixref_set_at_size

symintr matrixref_set_at
overload matrixref_set_at with matrixref_set_at_int of 0
overload matrixref_set_at with matrixref_set_at_size of 0

(* ****** ****** *)

fun{a:vt0p}
matrixref_exch_at_int
  {m,n:int}
(
  A: matrixref (INV(a), m, n)
, i: natLt (m), n: int n, j: natLt (n), x: &a >> _
) :<!refwrt> void // end of [matrixref_exch_at_int]

fun{a:vt0p}
matrixref_exch_at_size
  {m,n:int}
(
  A: matrixref (INV(a), m, n)
, i: sizeLt (m), n: size_t n, j: sizeLt (n), x: &a >> _
) :<!refwrt> void // end of [matrixref_exch_at_size]

symintr matrixref_exch_at
overload matrixref_exch_at with matrixref_exch_at_int of 0
overload matrixref_exch_at with matrixref_exch_at_size of 0

(* end of [matrixref.sats] *)
