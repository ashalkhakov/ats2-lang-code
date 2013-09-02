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
** $PATSHOME/prelude/DATS/CODEGEN/matrixref.atxt
** Time of generation: Mon Jul 22 19:30:26 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: Feburary, 2012 *)

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

implement{a}
matrixref_get_at_size
  (A, i, n, j) = let
//
val
(
vbox pf | p
) = matrixref_get_viewptr (A)
//
in
  matrix_get_at_size (!p, i, n, j)
end // end of [matrixref_get_at_size]

(* ****** ****** *)

implement{a}
matrixref_set_at_size
  (A, i, n, j, x) = let
//
val
(
vbox pf | p
) = matrixref_get_viewptr (A)
//
in
  matrix_set_at_size (!p, i, n, j, x)
end // end of [matrixref_set_at_size]

(* ****** ****** *)

(* end of [matrixref.dats] *)
