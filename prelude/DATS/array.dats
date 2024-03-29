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
** Time of generation: Tue Aug 20 17:25:34 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: Feburary, 2012 *)

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"
staload IT = "prelude/SATS/giterator.sats"

(* ****** ****** *)

macdef castvwtp_trans = $UN.castvwtp0 // former name

(* ****** ****** *)

implement{a}
array_getref_at
  (A, i) = let
  val p = ptr0_add_guint<a> (addr@(A), i) in $UN.cast{cPtr1(a)}(p)
end // end of [array_getref_at]

implement{a}
array_get_at_size (A, i) = let
  val p = ptr0_add_guint<a> (addr@(A), i) in $UN.ptr0_get<a> (p)
end // end of [array_get_at_size]

implement{a}
array_set_at_size (A, i, x) = let
  val p = ptr0_add_guint<a> (addr@(A), i) in $UN.ptr0_set<a> (p, x)
end // end of [array_set_at_size]

implement{a}
array_exch_at_size (A, i, x) = let
  val p = ptr0_add_guint<a> (addr@(A), i) in $UN.ptr0_exch<a> (p, x)
end // end of [array_exch_at_size]

(* ****** ****** *)

implement{a}
array_interchange
  (A, i, j) = let
in
//
if i != j then let
  val p = addr@(A)
  val pi = ptr0_add_guint<a> (p, i)
  val pj = g1ofg0_ptr (ptr0_add_guint<a> (p, j))
  val (pf, fpf | pj) = $UN.ptr_vtake{a}(pj)
  val () = $UN.ptr0_exch<a> (pi, !pj)
  prval () = fpf (pf)
in
  // nothing
end else () // end of [if]
//
end // end of [array_interchange]

(* ****** ****** *)

implement{a}
array_subcirculate
  (A, i, j) = let
//
extern
fun memmove
(
  dst: ptr, src: ptr, bsz: size_t
) :<!wrt> ptr = "mac#atspre_array_memmove"
//
in
//
if i < j then
{
//
val p0 = ptr_add<a> (addr@(A), i)
val p1 = ptr_add<a> (addr@(A), j)
val A1 = $UN.ptr0_get<a> (p1)
val _(*ptr*) = memmove (ptr_succ<a>(p0), p0, (j-i)*sizeof<a>)
val () = $UN.ptr0_set<a> (p0, A1)
//
} else if i > j then
{
//
val p0 = ptr_add<a> (addr@(A), j)
val p1 = ptr_add<a> (addr@(A), i)
val A0 = $UN.ptr0_get<a> (p0)
val _(*ptr*) = memmove (p0, ptr_succ<a>(p0), (i-j)*sizeof<a>)
val () = $UN.ptr0_set<a> (p1, A0)
//
} else () // end of [if]
//
end // end of [array_subcirculate]

(* ****** ****** *)

implement{a}
array_ptr_takeout
  {l}{n}{i}(pf | p, i) = let
  prval (pf, fpf) =
    array_v_takeout {a}{l}{n}{i} (pf)
  // end of [prval]
in
  (pf, fpf | ptr1_add_guint<a> (p, i))
end // end of [array_ptr_takeout]

(* ****** ****** *)

implement{a}
array_ptr_alloc
  {n} (asz) = let
  val [l:addr] (
    pf, pfgc | p
  ) = malloc_gc (asz * sizeof<a>)
  prval pf =
    __assert (pf) where {
    extern praxi __assert
      (pf: b0ytes (n*sizeof(a)) @ l): array_v (a?, l, n)
    // end of [__assert]
  } // end of [where] // end of [prval]
in
  (pf, pfgc | p)
end // end of [array_ptr_alloc]

(* ****** ****** *)

implement{}
array_ptr_free
  {a}{l}{n}
  (pf, pfgc | p) = let
  prval pf =
    __assert (pf) where {
    extern praxi __assert
      (pf: array_v (a?, l, n)): b0ytes (n*sizeof(a)) @ l
    // end of [__assert]
  } // end of [where] // end of [prval]
in
  mfree_gc (pf, pfgc | p)
end // end of [array_ptr_free]

(* ****** ****** *)

implement{a}
array_ptr_tabulate (asz) = let
//
val
(
  pf, pfgc | p
) = array_ptr_alloc<a> (asz)
//
implement
array_initize$init<a> (i, x) = x := array_tabulate$fopr<a> (i)
val () = array_initize<a> (!p, asz)
//
in
  @(pf, pfgc | p)
end // end of [array_ptr_tabulate]

(* ****** ****** *)

implement{}
fprint_array$sep (out) = fprint (out, ", ")

implement{a}
fprint_array
  (out, A, asz) = let
//
typedef tenv = int
implement
array_foreach$fwork<a><tenv>
  (x, env) = let
  val n = env
  val () = if n > 0 then fprint_array$sep<> (out)
  val () = env := n + 1
in
  fprint_ref<a> (out, x)
end // end of [array_foreach$fwork]
//
var env: tenv = 0
val _(*n*) = array_foreach_env<a><tenv> (A, asz, env)
//
in
  // nothing
end // end of [fprint_array]

implement{a}
fprint_array_sep
  (out, A, asz, sep) = let
//
implement
fprint_array$sep<> (out) = fprint (out, sep)
//
in
  fprint_array<a> (out, A, asz)
end // end of [fprint_array_sep]

(* ****** ****** *)

implement
{a}(*tmp*)
array_copy
  {n} (to, from, n) = let
//
val p_to = addr@(to) and p_from = addr@(from)
//
val _ =
$extfcall
(
  ptr, "atspre_array_memcpy", p_to, p_from, n*sizeof<a>
) (* end of [val] *)
//
extern
praxi __assert {l1,l2:addr}
(
  pf1: !array_v (a?, l1, n) >> array_v (a  , l1, n)
, pf2: !array_v (a , l2, n) >> array_v (a?!, l2, n)
) : void // end of [__assert]
//
prval () = __assert (view@ (to), view@ (from))
//
in
  // nothing
end // end of [array_copy]

(* ****** ****** *)

implement{a}
array_copy_from_list
  (A, xs) = let
//
prval () = lemma_list_param (xs)
//
fun loop
  {l:addr}{n:nat} .<n>. (
  pf: !array_v (a?, l, n) >> array_v (a, l, n)
| p: ptr l, xs: list (a, n)
) :<!wrt> void = (
  case+ xs of
  | list_cons (x, xs) => let
      prval (pf1, pf2) = array_v_uncons (pf)
      val () = !p := x
      val () = loop (pf2 | ptr1_succ<a> (p), xs)
      prval () = pf := array_v_cons (pf1, pf2)
    in
      // nothing
    end // end of [list_cons]
  | list_nil () => let
      prval () = pf := array_v_unnil_nil (pf)
    in
      // nothing
    end // end of [list_nil]
) (* end of [loop] *)
//
in
  loop (view@(A) | addr@(A), xs)
end // end of [array_copy_from_list]

(* ****** ****** *)

implement{a}
array_copy_from_list_vt
  (A, xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {l:addr}{n:nat} .<n>. (
  pf: !array_v (a?, l, n) >> array_v (a, l, n)
| p: ptr l, xs: list_vt (a, n)
) :<!wrt> void = (
  case+ xs of
  | ~list_vt_cons (x, xs) => let
      prval (pf1, pf2) = array_v_uncons (pf)
      val () = !p := x
      val () = loop (pf2 | ptr1_succ<a> (p), xs)
      prval () = pf := array_v_cons (pf1, pf2)
    in
      // nothing
    end // end of [list_vt_cons]
  | ~list_vt_nil () => let
      prval () = pf := array_v_unnil_nil (pf)
    in
      // nothing
    end // end of [list_vt_nil]
) (* end of [loop] *)
//
in
  loop (view@(A) | addr@(A), xs)
end // end of [array_copy_from_list_vt]

(* ****** ****** *)

implement{a}
array_copy_to_list_vt
  (A, n) = res where {
//
prval () = lemma_array_param (A)
//
fun loop
  {l:addr}{n:nat} .<n>. (
  pf: !array_v (a, l, n) >> array_v (a?!, l, n)
| p: ptr l, n: size_t n, res: &ptr? >> list_vt (a, n)
) :<!wrt> void = (
  if n > 0 then let
    prval (pf1, pf2) = array_v_uncons (pf)
    val () = res := list_vt_cons {a}{0} (!p, _)
    val+list_vt_cons (_, res1) = res
    val () = loop (pf2 | ptr1_succ<a> (p), pred(n), res1)
    prval () = pf := array_v_cons (pf1, pf2)
    prval () = fold@ (res)
  in
    // nothing
  end else let
    prval () = pf := array_v_unnil_nil (pf)
  in
    res := list_vt_nil ()
  end // end of [if]
) (* end of [loop] *)
//
var res: ptr
val () = loop (view@(A) | addr@(A), n, res)
//
} // end of [array_copy_to_list_vt]

(* ****** ****** *)

implement{a}{env}
array_foreach$cont (x, env) = true
(*
implement{a}{env}
array_foreach$fwork (x, env) = ((*void*))
*)

implement{a}
array_foreach (A, asz) = let
  var env: void = () in array_foreach_env<a><void> (A, asz, env)
end // end of [array_foreach]

implement
{a}{env}
array_foreach_env
  {n0} (A, asz, env) = let
//
prval () = lemma_array_param (A)
//
fun loop
  {l:addr}
  {n:nat | n <= n0} .<n>.
(
  pf: !array_v (a, l, n)
| p: ptr l, n: size_t n, env: &env
) : sizeLte (n0) = let
in
//
if n > 0 then let
  prval
  (
    pf1, pf2
  ) = array_v_uncons (pf)
  val cont = array_foreach$cont<a><env> (!p, env)
in
  if cont then let
    val () = array_foreach$fwork<a><env> (!p, env)
    val res = loop (pf2 | ptr1_succ<a> (p), pred(n), env)
    prval () = pf := array_v_cons (pf1, pf2)
  in
    res
  end else let
    prval () = pf := array_v_cons (pf1, pf2) in n
  end (* end of [if] *)
end else n(*0*)
//
end // end of [loop]
//
val p_beg = addr@(A)
val n = loop (view@(A) | p_beg, asz, env)
//
in
  asz - n
end // end of [array_foreach_env]

(* ****** ****** *)

implement{a}
array_foreach_funenv
  {v}{vt} (pf | A, asz, f, env) =
  array_foreach_funenv_tsz {a}{v}{vt} (pf | A, asz, sizeof<a>, f, env)
// end of [array_foreach_funenv]

implement{a}
array_foreach_fun
  {n}{fe} (A, asz, f) = let
  typedef tfun = (!unit_v | &a, !ptr) -<fun,fe> void
  val f = $UN.cast{tfun} (f)
  prval pfu = unit_v ()
  var env: ptr = the_null_ptr
  val () = array_foreach_funenv<a> (pfu | A, asz, f, env)
  prval () = unit_v_elim (pfu)
in
  // nothing
end // end of [array_foreach_fun]

implement{a}
array_foreach_cloref
  {n}{fe} (A, asz, f) = let
//
  viewdef v = unit_v
  typedef vt = (&a) -<cloref,fe> void
//
  fun app .<>. (pf: !v | x: &a, env: !vt):<fe> void = env (x)
  prval pfu = unit_v ()
  var env = f
  val () = array_foreach_funenv<a> {v}{vt} (pfu | A, asz, app, env)
  prval () = unit_v_elim (pfu)
in
  // nothing
end // end of [array_foreach_cloref]

(* ****** ****** *)

implement
{a1,a2}{env}
array_foreach2$cont (x1, x2, env) = true
(*
implement
{a1,a2}{env}
array_foreach2$fwork (x1, x2, env) = ((*void*))
*)

implement
{a1,a2}
array_foreach2 (A1, A2, asz) = let
  var env: void = () in array_foreach2_env<a1,a2><void> (A1, A2, asz, env)
end // end of [array_foreach2]

implement
{a1,a2}{env}
array_foreach2_env
  {n0} (A1, A2, asz, env) = let
//
prval () = lemma_array_param (A1)
//
fun loop
  {l1,l2:addr}
  {n:nat | n <= n0} .<n>. (
  pf1: !array_v (a1, l1, n)
, pf2: !array_v (a2, l2, n)
| p1: ptr l1, p2: ptr l2, n: size_t n, env: &env
) : sizeLte (n0) = let
in
  if n > 0 then let
    prval (pf11, pf12) = array_v_uncons (pf1)
    prval (pf21, pf22) = array_v_uncons (pf2)
    val cont = array_foreach2$cont<a1,a2><env> (!p1, !p2, env)
  in
    if cont then let
      val () = array_foreach2$fwork<a1,a2><env> (!p1, !p2, env)
      val res = loop (
        pf12, pf22 | ptr1_succ<a1> (p1), ptr1_succ<a2> (p2), pred(n), env
      ) // end of [val]
      prval () = pf1 := array_v_cons (pf11, pf12)
      prval () = pf2 := array_v_cons (pf21, pf22)
    in
      res
    end else let
      prval () = pf1 := array_v_cons (pf11, pf12)
      prval () = pf2 := array_v_cons (pf21, pf22) in n
    end (* end of [if] *)
  end else n(*0*)
end // end of [loop]
//
val p1_beg = addr@(A1)
val p2_beg = addr@(A2)
val n = loop (view@(A1), view@(A2) | p1_beg, p2_beg, asz, env)
//
in
  asz - n
end // end of [array_foreach2_env]

(* ****** ****** *)

implement{a}{env}
array_iforeach$cont (i, x, env) = true
(*
implement{a}{env}
array_iforeach$fwork (i, x, env) = ((*void*))
*)

implement{a}
array_iforeach (A, asz) = let
  var env: void = () in array_iforeach_env<a><void> (A, asz, env)
end // end of [array_iforeach]

implement
{a}{env}
array_iforeach_env
  {n0} (A, asz, env) = let
//
prval () = lemma_array_param (A)
//
fun loop
  {l:addr}
  {n:nat | n <= n0} .<n>. (
  pf: !array_v (a, l, n)
| i: size_t, p: ptr l, n: size_t n, env: &env
) : sizeLte (n0) = let
in
//
if n > 0 then let
  prval (
    pf1, pf2
  ) = array_v_uncons (pf)
  val cont = array_iforeach$cont<a><env> (i, !p, env)
in
  if cont then let
    val () = array_iforeach$fwork<a><env> (i, !p, env)
    val res = loop (pf2 | succ(i), ptr1_succ<a> (p), pred(n), env)
    prval () = pf := array_v_cons (pf1, pf2)
  in
    res
  end else let
    prval () = pf := array_v_cons (pf1, pf2) in n
  end (* end of [if] *)
end else n(*0*)
//
end // end of [loop]
//
val p_beg = addr@(A)
val n = loop (view@(A) | g0int2uint(0), p_beg, asz, env)
//
in
  asz - n
end // end of [array_iforeach_env]

(* ****** ****** *)

implement{a}{env}
array_rforeach$cont (x, env) = true
(*
implement{a}{env}
array_rforeach$fwork (x, env) = ((*void*))
*)

implement{a}
array_rforeach (A, asz) = let
  var env: void = () in array_rforeach_env<a><void> (A, asz, env)
end // end of [array_rforeach]

implement
{a}{env}
array_rforeach_env
  {n0} (A, asz, env) = let
//
prval () = lemma_array_param (A)
//
fun loop
  {l:addr}
  {n:nat | n <= n0} .<n>.
(
  pf: !array_v (a, l, n)
| p: ptr (l+n*sizeof(a)), n: size_t n, env: &env
) : sizeLte (n0) = let
in
//
if n > 0 then let
  prval
  (
    pf1, pf2
  ) = array_v_unextend (pf)
  val p1 = ptr1_pred<a> (p)
  val (pf2 | p1) = viewptr_match (pf2 | p1)
  val cont = array_rforeach$cont<a><env> (!p1, env)
in
  if cont then let
    val () = array_rforeach$fwork<a><env> (!p1, env)
    val res = loop (pf1 | p1, pred(n), env)
    prval () = pf := array_v_extend (pf1, pf2)
  in
    res
  end else let
    prval () = pf := array_v_extend (pf1, pf2) in n
  end (* end of [if] *)
end else n (*0*)
//
end // end of [loop]
//
val p_end =
  ptr1_add_guint<a> (addr@(A), asz)
val n = loop (view@(A) | p_end, asz, env)
//
in
  asz - n
end // end of [array_rforeach_env]

(* ****** ****** *)

implement{a}
array_initize
  (A, asz) = let
//
stadef V = array_v
//
fun loop
  {l:addr}{n:nat} .<n>.
(
  pf: !V (a?, l, n) >> V (a, l, n)
| p: ptr l, n: size_t n, i: size_t
) : void =
(
if n > 0 then let
  prval (pf1, pf2) = array_v_uncons (pf)
  val () = array_initize$init<a> (i, !p)
  val () = loop (pf2 | ptr1_succ<a> (p), pred(n), succ(i))
  prval () = pf := array_v_cons{a}(pf1, pf2)
in
  // nothing
end else let
  prval () = pf := array_v_unnil_nil (pf)
in
  // nothing
end // end of [if]
) (* end of [loop] *)
//
prval () = lemma_g1uint_param (asz)
//
in
  loop (view@ (A) | addr@ (A), asz, g0int2uint(0))
end // end of [array_initize]

(* ****** ****** *)

implement{a}
array_initize_elt
  (A, asz, elt) = let
//
implement
array_initize$init<a> (i, xi) = xi := elt
//
in
  $effmask_all (array_initize<a> (A, asz))
end // end of [array_initize_elt]

(* ****** ****** *)

implement{a}
array_initize_list
  {n} (A, asz, xs) = let
//
typedef list0 = listGte (a, 0)
typedef list1 = listGte (a, 1)
//
fun loop
(
  p: ptr, p1: ptr, xs: list0
) : void = let
in
//
if p < p1 then let
  val xs =
    $UN.cast{list1}(xs)
  val+list_cons (x, xs) = xs
  val () = $UN.ptr0_set<a> (p, x)
  val p = ptr_succ<a> (p)
in
  loop (p, p1, xs)
end else () // end of [if]
//
end // end of [loop]
//
prval () = lemma_list_param (xs)
//
val p = addr@(A)
val p1 = ptr_add<a> (p, asz)
val () = $effmask_all(loop (p, p1, xs))
//
prval (
) = __assert (A) where
{
extern praxi __assert (A: &array(a?, n) >> array(a, n)): void
} (* end of [prval] *)
//
in
  // nothing
end // end of [array_initize_list]

(* ****** ****** *)

implement{a}
array_initize_rlist
  {n} (A, asz, xs) = let
//
typedef list0 = listGte (a, 0)
typedef list1 = listGte (a, 1)
//
fun loop
(
  p: ptr, p0: ptr, xs: list0
) : void = let
in
//
if p > p0 then let
  val xs =
    $UN.cast{list1}(xs)
  val+list_cons (x, xs) = xs
  val p = ptr_pred<a> (p)
  val () = $UN.ptr0_set<a> (p, x)
in
  loop (p, p0, xs)
end else () // end of [if]
//
end // end of [loop]
//
prval () = lemma_list_param (xs)
//
val p0 = addr@(A)
val p = ptr_add<a> (p0, asz)
val () = $effmask_all(loop (p, p0, xs))
//
prval (
) = __assert (A) where
{
extern
praxi __assert (A: &array(a?, n) >> array(a, n)): void
} (* end of [prval] *)
//
in
  // nothing
end // end of [array_initize_rlist]

(* ****** ****** *)

implement{a}
array_initize_list_vt
  {n} (A, asz, xs) = let
//
vtypedef list0 = listGte_vt (a, 0)
vtypedef list1 = listGte_vt (a, 1)
//
fun loop
(
  p: ptr, p1: ptr, xs: list0
) : void = let
in
//
if p < p1 then let
  val xs =
    $UN.castvwtp0{list1}(xs)
  val+~list_vt_cons (x, xs) = xs
  val () = $UN.ptr0_set<a> (p, x)
  val p = ptr_succ<a> (p)
in
  loop (p, p1, xs)
end else let
  prval () = $UN.cast2void (xs) in (*nothing*)
end // end of [if]
//
end // end of [loop]
//
prval () = lemma_list_vt_param (xs)
//
val p = addr@(A)
val p1 = ptr_add<a> (p, asz)
val () = $effmask_all(loop (p, p1, xs))
//
prval (
) = __assert (A) where
{
extern
praxi __assert (A: &array(a?, n) >> array(a, n)): void
} (* end of [prval] *)
//
in
  // nothing
end // end of [array_initize_list_vt]

(* ****** ****** *)

implement{a}
array_initize_rlist_vt
  {n} (A, asz, xs) = let
//
vtypedef list0 = listGte_vt (a, 0)
vtypedef list1 = listGte_vt (a, 1)
//
fun loop
(
  p: ptr, p0: ptr, xs: list0
) : void = let
in
//
if p > p0 then let
  val xs =
    $UN.castvwtp0{list1}(xs)
  val+~list_vt_cons (x, xs) = xs
  val p = ptr_pred<a> (p)
  val () = $UN.ptr0_set<a> (p, x)
in
  loop (p, p0, xs)
end else let
  prval () = $UN.cast2void (xs) in (*nothing*)
end // end of [if]
//
end // end of [loop]
//
prval () = lemma_list_vt_param (xs)
//
val p0 = addr@(A)
val p = ptr_add<a> (p0, asz)
val () = $effmask_all(loop (p, p0, xs))
//
prval (
) = __assert (A) where
{
extern
praxi __assert (A: &array(a?, n) >> array(a, n)): void
} (* end of [prval] *)
//
in
  // nothing
end // end of [array_initize_rlist_vt]

(* ****** ****** *)

implement{a}
array_uninitize
  (A, asz) = let
//
fun loop
  {l:addr}{n:nat} .<n>.
(
  pf: !array_v (a, l, n) >> array_v (a?, l, n) | p: ptr l, n: size_t n, i: size_t
) : void = let
in
//
if n > 0 then let
  prval (pf1, pf2) = array_v_uncons (pf)
  val () = array_uninitize$clear<a> (i, !p)
  val () = loop (pf2 | ptr_succ<a> (p), pred (n), succ (i))
  prval () = pf := array_v_cons (pf1, pf2)
in
  // nothing
end else let
  prval () = pf := array_v_unnil_nil {a,a?} (pf)
in
  // nothing
end // end of [if]
//
end // end of [loop]
//
prval () = lemma_array_param (A)
//
prval pf = view@ (A)
val () = loop (pf | addr@ (A), asz, i2sz(0))
prval () = view@ (A) := pf
//
in
  // nothing  
end // end of [array_uninitize]

(* ****** ****** *)

implement
{a}{b}
array_mapto
  {n}(A, B, n) = let
//
val pa = addr@ (A)
val pa2 = ptr_add<a> (pa, n)
val pb = addr@ (B)
//
fun loop{la,lb:addr}
(
  pa: ptr la, pa2: ptr, pb: ptr lb
) : void =
(
if pa < pa2 then let
  val (pfa, fpfa | pa) = $UN.ptr_vtake{a}(pa)
  val (pfb, fpfb | pb) = $UN.ptr_vtake{b?}(pb)
  val () = array_mapto$fwork<a><b> (!pa, !pb)
  prval () = fpfa (pfa)
  prval () = fpfb ($UN.castview0{(b?)@lb}(pfb))
in
  loop (ptr_succ<a> (pa), pa2, ptr_succ<b> (pb))
end (* end of [if] *)
)
//
val () = loop (pa, pa2, pb)
prval [lb:addr] EQADDR () = ptr_get_index (pb)
prval () = view@(B) := $UN.castview0{array_v (b, lb, n)}(view@(B))
//
in
  // nothing
end (* end of [array_mapto] *)

(* ****** ****** *)

implement
{a,b}{c}
array_map2to
  {n}(A, B, C, n) = let
//
val pa = addr@ (A)
val pa2 = ptr_add<a> (pa, n)
val pb = addr@ (B)
val pc = addr@ (C)
//
fun loop{la,lb,lc:addr}
(
  pa: ptr la, pa2: ptr, pb: ptr lb, pc: ptr lc
) : void =
(
if pa < pa2 then let
  val (pfa, fpfa | pa) = $UN.ptr_vtake{a}(pa)
  val (pfb, fpfb | pb) = $UN.ptr_vtake{b}(pb)
  val (pfc, fpfc | pc) = $UN.ptr_vtake{c?}(pc)
  val () = array_map2to$fwork<a,b><c> (!pa, !pb, !pc)
  prval () = fpfa (pfa)
  prval () = fpfb (pfb)
  prval () = fpfc ($UN.castview0{(c?)@lc}(pfc))
in
  loop (ptr_succ<a> (pa), pa2, ptr_succ<b> (pb), ptr_succ<c> (pc))
end (* end of [if] *)
)
//
val () = loop (pa, pa2, pb, pc)
prval [lc:addr] EQADDR () = ptr_get_index (pc)
prval () = view@(C) := $UN.castview0{array_v (c, lc, n)}(view@(C))
//
in
  // nothing
end (* end of [array_map2to] *)

(* ****** ****** *)

(*
implement{a}
array_bsearch
  (A, n) = $effmask_all let
//
val itr =
  $IT.giter_make_array (view@(A) | addr@(A), n)
// end of [val]
implement
$IT.giter_bsearch$ford<a> (x) = array_bsearch$ford<a> (x)
val () = $IT.giter_bsearch (itr, n)
//
val ofs = $IT.giter_get_fofs (itr)
//
val (pf | ()) = $IT.giter_free_array (itr)
prval () = view@ (A) := pf
//
in
  ofs
end // end of [array_bsearch]
*)

(* ****** ****** *)

implement{a}
array_permute (A, asz) = let
//
prval () = lemma_array_param (A)
//
fun loop
  {l:addr}{n:nat} .<n>.
(
  pf: !array_v (a, l, n) | p: ptr l, n: size_t n
) : void = let
in
//
if n >= 2 then let
  val i = array_permute$randint<> (n)
  prval (pf1, pf2) = array_v_uncons (pf)
  val () = if i > 0 then $UN.ptr0_exch<a> (ptr0_add_guint<a> (p, i), !p)
  val () = loop (pf2 | ptr1_succ<a> (p), pred (n))
  prval () = pf := array_v_cons (pf1, pf2)
in
  // nothing
end else () // end of [if]
//
end // end of [loop]
//
in
  loop (view@ (A) | addr@ (A), asz)
end // end of [array_permute]

(* ****** ****** *)

(* end of [array.dats] *)
