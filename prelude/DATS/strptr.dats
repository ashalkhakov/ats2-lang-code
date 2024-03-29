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
** $PATSHOME/prelude/DATS/CODEGEN/strptr.atxt
** Time of generation: Mon Jul 22 19:30:17 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: April, 2012 *)

(* ****** ****** *)

#define ATS_DYNLOADFLAG 0 // no dynloading at run-time

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

staload _(*anon*) = "prelude/DATS/integer.dats"

(* ****** ****** *)

#define CNUL '\000'
#define nullp the_null_ptr

(* ****** ****** *)

overload + with add_ptr_bsz

(* ****** ****** *)

implement{}
strptr_is_null (str) = (strptr2ptr (str) = nullp)
implement{}
strptr_isnot_null (str) = (strptr2ptr (str) > nullp)

(* ****** ****** *)

implement{}
strptr_is_empty (str) = let
  val p = strptr2ptr (str) in $UN.ptr1_get<char>(p) = CNUL
end // end of [strptr_is_empty]
implement{}
strptr_isnot_empty (str) = let
  val p = strptr2ptr (str) in $UN.ptr1_get<char>(p) != CNUL
end // end of [strptr_isnot_empty]

(* ****** ****** *)

implement{}
strnptr_get_at_size (str, i) =
  $UN.ptr0_get<charNZ>(strnptr2ptr(str) + i)
// end of [strnptr_get_at_size]

implement{tk}
strnptr_get_at_gint (str, i) =
  strnptr_get_at_size (str, g1int2uint (i))
// end of [strnptr_get_at_gint]
implement{tk}
strnptr_get_at_guint (str, i) =
  strnptr_get_at_size (str, g1uint2uint (i))
// end of [strnptr_get_at_guint]

(* ****** ****** *)

implement{}
strnptr_set_at_size (str, i, c) =
  $UN.ptr0_set<charNZ>(strnptr2ptr(str) + i, c)
// end of [strnptr_set_at_size]

implement{tk}
strnptr_set_at_gint (str, i, c) =
  strnptr_set_at_size (str, g1int2uint (i), c)
// end of [strnptr_set_at_gint]
implement{tk}
strnptr_set_at_guint (str, i, c) =
  strnptr_set_at_size (str, g1uint2uint (i), c)
// end of [strnptr_set_at_guint]

(* ****** ****** *)

implement
lt_strptr_strptr (x1, x2) = (compare_strptr_strptr (x1, x2) < 0)
implement
lte_strptr_strptr (x1, x2) = (compare_strptr_strptr (x1, x2) <= 0)
implement
gt_strptr_strptr (x1, x2) = (compare_strptr_strptr (x1, x2) > 0)
implement
gte_strptr_strptr (x1, x2) = (compare_strptr_strptr (x1, x2) >= 0)
implement
eq_strptr_strptr (x1, x2) = (compare_strptr_strptr (x1, x2) = 0)
implement
neq_strptr_strptr (x1, x2) = (compare_strptr_strptr (x1, x2) != 0)

(* ****** ****** *)

(*
//
// HX: implemented in [strptr.cats]
//
implement
print_strptr (x) = fprint_strptr (stdout_ref, x)
implement
prerr_strptr (x) = fprint_strptr (stderr_ref, x)
*)

(* ****** ****** *)

implement{}
strnptr_is_null (str) = (strnptr2ptr (str) = nullp)
implement{}
strnptr_isnot_null (str) = (strnptr2ptr (str) > nullp)

(* ****** ****** *)

implement{}
strptr_length (x) = let
  val isnot = ptr_isnot_null (strptr2ptr(x))
in
  if isnot
    then g0u2i(string_length ($UN.strptr2string(x))) else g0i2i(~1)
  // end of [if]
end // end of [strptr_length]

implement{}
strnptr_length (x) = let
  prval () = lemma_strnptr_param (x)
  val isnot = ptr_isnot_null (strnptr2ptr(x))
in
  if isnot
    then g1u2i(string_length ($UN.strnptr2string(x))) else g1i2i(~1)
  // end of [if]
end // end of [strnptr_length]

(* ****** ****** *)

implement{}
strptr0_copy (x) = let
  val isnot = ptr_isnot_null (strptr2ptr(x))
in
  if isnot then string0_copy ($UN.strptr2string(x)) else strptr_null ()
end // end of [strptr0_copy]

implement{}
strptr1_copy (x) = string0_copy ($UN.strptr2string(x))

(* ****** ****** *)

implement{}
strptr_append
  (x1, x2) = let
//
val isnot1 = ptr_isnot_null (strptr2ptr(x1))
//
in
//
if isnot1 then let
//
val isnot2 = ptr_isnot_null (strptr2ptr(x2))
//
in
//
if
isnot2
then
  strnptr2strptr(string1_append ($UN.strptr2string(x1), $UN.strptr2string(x2)))
else
  strptr1_copy (x1)
// end of [if]
//
end else
  strptr0_copy (x2)
// end of [if]
//
end // end of [strptr_append]

(* ****** ****** *)

implement{}
strptrlst_concat (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n0:nat} .<n0>.
(
  xs: &list_vt(Strptr0, n0)>>list_vt(Strptr1, n1)
) :<!wrt> #[n1:nat | n1 <= n0] void = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs1) => let
    val isnot = strptr_isnot_null (x)
  in
    if isnot then let
      val () = loop (xs1)
      prval () = fold@ (xs)
    in
      // nothing
    end else let
      val () = strptr_free_null (x)
      val xs1 = xs1
      val () = free@ {..}{0} (xs)
      val () = xs := xs1
    in
      loop (xs)
    end // end of [if]
  end // end of [list_vt_cons]
| @list_vt_nil () => fold@ (xs)
//
end // end of [loop]
//
var xs = xs
val () = loop (xs)
//
in
//
case+ xs of
| ~list_vt_nil () => strptr_null ()
| ~list_vt_cons (x, ~list_vt_nil ()) => x
| _ => let
    val res =
      stringlst_concat ($UN.castvwtp1{List(string)}(xs))
    val () =
    loop (xs) where {
      fun loop {n:nat} .<n>.
        (xs: list_vt (Strptr1, n)):<!wrt> void =
        case+ xs of
        | ~list_vt_cons (x, xs) => (strptr_free (x); loop (xs))
        | ~list_vt_nil ((*void*)) => ()
      // end of [loop]
    } // end of [where] // end of [val]
  in
    res
  end // end of [_]
//
end // end of [strptrlst_concat]

(* ****** ****** *)

(* end of [strptr.dats] *)
