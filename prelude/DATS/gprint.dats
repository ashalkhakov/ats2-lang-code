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
** $PATSHOME/prelude/DATS/CODEGEN/gprint.atxt
** Time of generation: Mon Jul 22 19:30:26 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: August, 2012 *)

(* ****** ****** *)

implement{} gprint$out () = stdout_ref

(* ****** ****** *)

implement{a}
gprint_val (x) = let
  val out = gprint$out () in fprint_val<a> (out, x)
end // end of [gprint_val]

(* ****** ****** *)

implement{}
gprint_newline () = let
  val out = gprint$out () in fprint_newline (out)
end // end of [gprint_newline]

(* ****** ****** *)
//
implement{}
gprint_int (x) =
  fprint_val<int> (gprint$out (), x)
implement{}
gprint_char (x) =
  fprint_val<char> (gprint$out (), x)
implement{}
gprint_float (x) =
  fprint_val<float> (gprint$out (), x)
implement{}
gprint_double (x) =
  fprint_val<double> (gprint$out (), x)
implement{}
gprint_string (x) =
  fprint_val<string> (gprint$out (), x)
//
implement gprint_val<int> (x) = gprint_int (x)
implement gprint_val<char> (x) = gprint_char (x)
implement gprint_val<float> (x) = gprint_float (x)
implement gprint_val<double> (x) = gprint_double (x)
implement gprint_val<string> (x) = gprint_string (x)
//
(* ****** ****** *)

implement{}
gprint_list$beg () = gprint_string "("
implement{}
gprint_list$end () = gprint_string ")"
implement{}
gprint_list$sep () = gprint_string ", "

(* ****** ****** *)

implement{a}
gprint_list (xs) = let
//
typedef tenv = int
//
implement
list_foreach$fwork<a><tenv>
  (x, env) = let
  val () =
    if env > 0 then gprint_list$sep ()
  val () = env := succ (env)
in
  gprint_val (x)
end // end of [list_foreach$fwork]
//
var env: tenv = 0
val () = gprint_list$beg ()
val () = list_foreach_env<a><tenv> (xs, env)
val () = gprint_list$end ()
//
in
  // nothing
end // end of [gprint_list]

implement(a)
gprint_val<List(a)> (xs) = gprint_list<a> (xs)

(* ****** ****** *)

implement{}
gprint_listlist$beg1 () = gprint_string "("
implement{}
gprint_listlist$end1 () = gprint_string ")"
implement{}
gprint_listlist$sep1 () = gprint_string ", "

implement{}
gprint_listlist$beg2 () = gprint_string "("
implement{}
gprint_listlist$end2 () = gprint_string ")"
implement{}
gprint_listlist$sep2 () = gprint_string ", "

implement{a}
gprint_listlist
  (xss) = let
//
typedef xs = List (a)
//
implement
gprint_val<xs> (xs) = let
//
implement gprint_list$beg<> () = gprint_listlist$beg2 ()
implement gprint_list$end<> () = gprint_listlist$end2 ()
implement gprint_list$sep<> () = gprint_listlist$sep2 ()
//
in
  gprint_list<a> (xs)
end // end of [gprint_val]
//
implement gprint_list$beg<> () = gprint_listlist$beg1 ()
implement gprint_list$end<> () = gprint_listlist$end1 ()
implement gprint_list$sep<> () = gprint_listlist$sep1 ()
//
in
  gprint_list<xs> (xss)
end // end of [gprint_listlist]

(* ****** ****** *)

implement{}
gprint_array$beg () = gprint_string "("
implement{}
gprint_array$end () = gprint_string ")"
implement{}
gprint_array$sep () = gprint_string ", "

(* ****** ****** *)

implement{a}
gprint_array (A, n) = let
//
typedef tenv = size_t
//
implement(env)
array_iforeach$fwork<a><env>
  (i, x, env) = let
  val () = if i > 0 then gprint_array$sep ()
in
  gprint_val<a> (x)
end // end of [array_iforeach$fwork]
//
var env: void = ()
val () = gprint_array$beg ()
val _(*n*) = array_iforeach<a> (A, n)
val () = gprint_array$end ()
//
in
  // nothing
end // end of [gprint_array]

(* ****** ****** *)

implement{a}
gprint_arrayptr
  (A, n) = () where {
  val p = ptrcast (A)
  prval pf = arrayptr_takeout (A)
  val () = gprint_array<a> (!p, n)
  prval () = arrayptr_addback (pf | A)
} // end of [gprint_arrayptr]

(* ****** ****** *)

implement{a}
gprint_arrayref
  (A, n) = () where {
  val (vbox pf | p) = arrayref_get_viewptr (A)
  val () = $effmask_ref (gprint_array<a> (!p, n))
} // end of [gprint_arrayref]

(* ****** ****** *)

(* end of [gprint.dats] *)
