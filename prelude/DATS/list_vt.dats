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
** $PATSHOME/prelude/DATS/CODEGEN/list_vt.atxt
** Time of generation: Fri Aug 23 10:20:58 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: Feburary, 2012 *)

(* ****** ****** *)

staload UN = "prelude/SATS/unsafe.sats"

(* ****** ****** *)

implement{}
list_vt_unnil (xs) = let
  val+~list_vt_nil () = xs in (*nothing*)
end // end of [list_vt_unnil]

(* ****** ****** *)

implement{a}
list_vt_uncons (xs) = let
  val+~list_vt_cons (x, xs1) = xs in xs := xs1; x
end // end of [list_vt_uncons]

(* ****** ****** *)

implement{a}
print_list_vt (xs) = fprint_list_vt<a> (stdout_ref, xs)
implement{a}
prerr_list_vt (xs) = fprint_list_vt<a> (stderr_ref, xs)

(* ****** ****** *)

implement{}
fprint_list_vt$sep (out) = fprint_list$sep<> (out)

implement{a}
fprint_list_vt
  (out, xs) = let
//
implement(env)
list_vt_iforeach$fwork<a><env>
  (i, x, env) = let
  val () =
    if i > 0 then fprint_list_vt$sep<(*none*)> (out)
  // end of [val]
in
  fprint_ref<a> (out, x)
end // end of [list_iforeach$fwork]
//
val _(*n*) = list_vt_iforeach<a> (xs)
//
in
  // nothing
end // end of [fprint_list_vt]

implement{a}
fprint_list_vt_sep
  (out, xs, sep) = let
//
implement
fprint_list_vt$sep<(*none*)> (out) = fprint_string (out, sep)
//
in
  fprint_list_vt<a> (out, xs)
end // end of [fprint_list_vt_sep]

(* ****** ****** *)

implement{x}
list_vt_is_nil (xs) =
  case+ xs of list_vt_nil () => true | _ =>> false
// end of [list_vt_is_nil]

implement{x}
list_vt_is_cons (xs) =
  case+ xs of list_vt_cons _ => true | _ =>> false
// end of [list_vt_is_cons]

implement{x}
list_vt_is_sing (xs) =
  case+ xs of list_vt_sing (x) => true | _ =>> false
// end of [list_vt_is_sing]

implement{x}
list_vt_is_pair (xs) =
  case+ xs of list_vt_pair (x1, x2) => true | _ =>> false
// end of [list_vt_is_pair]

(* ****** ****** *)

implement{a}
list_vt_length (xs) = let
//
fun loop
  {i,j:nat} .<i>.
(
  xs: !list_vt (a, i), j: int j
) :<> int (i+j) = let
in
//
case+ xs of
| list_vt_cons
    (_, xs) => loop (xs, j + 1)
| list_vt_nil () => j
//
end // end of [loop]
//
prval () = lemma_list_vt_param (xs)
//
in
  loop (xs, 0)
end // end of [list_vt_length]

(* ****** ****** *)

implement{x}
list_vt_copy (xs) = let
//
implement
list_vt_copylin$copy<x> (x) = x
//
in
  $effmask_all (list_vt_copylin<x> (xs))
end // end of [list_vt_copy]

implement{x}
list_vt_copylin
  (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: !list_vt (x, n), res: &ptr? >> list_vt (x, n)
) : void = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs1) => let
    val x =
      list_vt_copylin$copy<x> (x)
    val () =
      res := list_vt_cons{x}{0}(x, _)
    val+list_vt_cons (_, res1) = res
    val () = loop (xs1, res1)
    prval () = fold@ (xs)
    prval () = fold@ (res)
  in
    // nothing
  end
| list_vt_nil () => res := list_vt_nil ()
//
end // end of [loop]
//
var res: ptr
val () = loop (xs, res)
//
in
  res
end // end of [list_vt_copylin]

(* ****** ****** *)

implement{a}
list_vt_getref_at
  {n}{i} (xs, i) = let
//
fun loop {
  n,i:nat | i <= n
} .<i>. (
  xs: &list_vt (a, n), i: int i
) :<> Ptr1 = let
in
  if i > 0 then let
    val+@list_vt_cons (_, xs1) = xs
    val res = loop{n-1,i-1}(xs1, pred(i))
  in
    fold@ (xs); res
  end else
    $UN.cast2Ptr1(addr@(xs))
  // end of [if]
end // end of [loop]
//
in
  $UN.ptr2cptr{list_vt(a,n-i)}(loop (xs, i))
end // end of [list_vt_getref_at]

(* ****** ****** *)

implement{a}
list_vt_get_at
  {n} (xs, i) = x where
{
//
var xs = __ref (xs) where
{
  extern
  castfn __ref
    (xs: !list_vt (a, n)):<> list_vt (a, n)
} // end of [val]
//
val pi = list_vt_getref_at (xs, i)
val+list_cons (x, _) =
  $UN.ptr1_get<List1(a)> (cptr2ptr(pi))
//
prval () = __unref (xs) where
{
  extern praxi __unref (xs: list_vt (a, n)): void
} // end of [prval]
//
} // end of [list_vt_get_at]

implement{a}
list_vt_set_at
  {n} (xs, i, x0) = let
//
var xs = let
  extern
  castfn __ref
    (xs: !list_vt (a, n)):<> list_vt (a, n)
  // end of [__ref]
in
  __ref (xs)
end // end of [val]
//
val pi = list_vt_getref_at (xs, i)
val (pf, fpf | pi) = $UN.cptr_vtake (pi)
val+@list_vt_cons (x1, xs1) = !pi
val () = x1 := x0
prval () = fold@ (!pi)
prval () = fpf (pf)
//
prval () = let
  extern praxi __unref (xs: list_vt (a, n)): void
in
  __unref (xs)
end // end of [prval]
//
in
  // nothing
end // end of [list_vt_set_at]

(* ****** ****** *)

implement{a}
list_vt_exch_at
  {n} (xs, i, x0) = let
//
var xs = __ref (xs) where
{
  extern
  castfn __ref
    (xs: !list_vt (a, n)):<> list_vt (a, n)
} // end of [val]
//
val pi = list_vt_getref_at (xs, i)
val (pf, fpf | pi) = $UN.cptr_vtake (pi)
val+@list_vt_cons (x1, xs1) = !pi
//
val t = x1
val () = x1 := x0
val () = x0 := t
//
prval () = fold@ (!pi)
prval () = fpf (pf)
//
prval () = __unref (xs) where
{
  extern praxi __unref (xs: list_vt (a, n)): void
} // end of [prval]
//
in
  // nothing
end // end of [list_vt_exch_at]

(* ****** ****** *)

implement{a}
list_vt_insert_at
  {n} (xs, i, x) = let
//
val pi = list_vt_getref_at (xs, i)
val xs_i = $UN.cptr_get (pi)
val xs1_i = list_vt_cons (x, xs_i)
val () =
  $UN.ptr1_set<List1_vt(a)> (cptr2ptr(pi), xs1_i)
//
prval () = __assert (xs) where
{
  extern
  praxi __assert (xs: &list_vt (a, n) >> list_vt (a, n+1)): void
} // end of [prval]
in
  // nothing
end // end of [list_vt_insert_at]

(* ****** ****** *)

implement{a}
list_vt_takeout_at
{n} (xs, i) = x1 where
{
//
val pi = list_vt_getref_at (xs, i)
val xs_i = $UN.cptr_get (pi)
val+~list_vt_cons (x1, xs1_i) = xs_i
val () =
  $UN.ptr1_set<List0_vt(a)> (cptr2ptr(pi), xs1_i)
//
prval () = __assert (xs) where
{
  extern
  praxi __assert (xs: &list_vt (a, n) >> list_vt (a, n-1)): void
} // end of [prval]
//
} // end of [list_vt_takeout_at]

(* ****** ****** *)

implement{a}
list_vt_free (xs) = let
//
implement
list_vt_freelin$clear<a>
  (x) = let
  prval () = topize (x) in (*void*)
end // end of [list_vt_freelin$clear]
//
in
  list_vt_freelin (xs)
end // end of [list_vt_free]

(* ****** ****** *)

implement{a}
list_vt_freelin$clear (x) = gclear_ref (x)
implement{a}
list_vt_freelin (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: list_vt (a, n)
) :<!wrt> void =
  case+ xs of
  | @list_vt_cons
      (x, xs1) => let
      val () =
        list_vt_freelin$clear<a> (x)
      val xs1 = xs1
      val () = free@{a}{0}(xs)
    in
      loop (xs1)
    end // end of [list_vt_cons]
  | ~list_vt_nil () => ()
// end of [loop]
//
in
  loop (xs)
end // end of [list_vt_freelin]

(* ****** ****** *)

implement{a}
list_vt_uninitize$clear (x) = gclear_ref (x)

implement{a}
list_vt_uninitize
  {n} (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: !list_vt (a, n) >> list_vt (a?, n)
) :<!wrt> void =
  case+ xs of
  | @list_vt_cons
      (x, xs1) => let
      val () =
        list_vt_uninitize$clear (x)
      val () = loop (xs1)
      prval () = fold@ {a?} (xs)
    in
      // nothing
    end // end of [list_vt_cons]
  | @list_vt_nil () => fold@ {a?} (xs)
// end of [loop]
//
in
  loop (xs)
end // end of [list_vt_uninitize]

(* ****** ****** *)

implement{a}
list_vt_append
  {m,n} (xs, ys) = let
//
prval () = lemma_list_vt_param (xs)
prval () = lemma_list_vt_param (ys)
//
fun loop
  {m:nat} .<m>.
(
  xs: &list_vt (a, m) >> list_vt (a, m+n), ys: list_vt (a, n)
) :<!wrt> void = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs1) => let
    val () = loop (xs1, ys); prval () = fold@ (xs) in (*none*)
  end // end of [list_vt_cons]
| ~list_vt_nil () => (xs := ys)
//
end (* end of [loop] *)
//
var res = xs
val () = loop (res, ys)
//
in
  res
end // end of [list_vt_append]

(* ****** ****** *)

implement{a}
list_vt_extend
  (xs, y) = list_vt_append<a> (xs, cons_vt{a}(y, nil_vt()))
// end of [list_vt_extend]

(* ****** ****** *)

implement{a}
list_vt_unextend
  (xs) = let
//
fun loop
  {n:pos} .<n>.
(
  xs: &list_vt (a, n) >> list_vt (a, n-1)
) :<!wrt> (a) = let
//
val+@list_vt_cons (x, xs1) = xs
//
in
//
case+ xs1 of
| list_vt_cons _ => let
    val x = loop (xs1)
    prval () = fold@ (xs)
  in
    x
  end // end of [list_vt_cons]
| list_vt_nil () => let
    val x = x
    val xs1 = xs1
    val () = free@{a}{0}(xs)
  in
    xs := xs1; x
  end // end of [list_vt_nil]
//
end // end of [loop]
//
in
  loop (xs)
end // end of [list_vt_unextend]

(* ****** ****** *)

implement{a}
list_vt_reverse (xs) = list_vt_reverse_append<a> (xs, list_vt_nil)

(* ****** ****** *)

implement{a}
list_vt_reverse_append
  (xs, ys) = let
//
prval () = lemma_list_vt_param (xs)
prval () = lemma_list_vt_param (ys)
//
fun loop
  {m,n:nat} .<m>.
(
  xs: list_vt (a, m), ys: list_vt (a, n)
) :<!wrt> list_vt (a, m+n) =
  case xs of
  | @list_vt_cons
      (_, xs1) => let
      val xs1_ = xs1
      val () = xs1 := ys; prval () = fold@ (xs)
    in
      loop (xs1_, xs)
    end // end of [cons]
  | ~list_vt_nil () => ys
(* end of [loop] *)
//
in
  loop (xs, ys)
end // end of [list_vt_reverse_append]

(* ****** ****** *)

implement
{x}(*tmp*)
list_vt_split_at
  (xs, i) = let
//
fun loop
  {n:int}
  {i:nat | i <= n} .<n>.
(
  xs: &list_vt (x, n) >> list_vt (x, i), i: int i
) :<!wrt> list_vt (x, n-i) =
(
if i > 0 then let
//
val+@cons_vt (x, xs1) = xs
val res = loop (xs1, i-1)
prval ((*void*)) = fold@ (xs)
//
in
  res
end else let
  val res = xs
  val () = xs := list_vt_nil((*void*))
in
  res
end // end of [if]
) // end of [loop]
//
var xs = xs
val res = loop (xs, i)
//
in
  (xs, res)
end // end of [list_split_vt_at]

(* ****** ****** *)

implement{a}
list_vt_concat
  (xss) = let
//
viewtypedef VT = List_vt (a)
viewtypedef VT0 = List0_vt (a)
//
fun loop {n:nat} .<n>. (
  res: VT, xss: list_vt (VT, n)
) :<!wrt> VT0 =
  case+ xss of
  | ~list_vt_cons
      (xs, xss) => let
      val res = list_vt_append<a> (xs, res)
    in
      loop (res, xss)
    end // end of [list_vt_cons]
  | ~list_vt_nil () => let
      prval () = lemma_list_vt_param (res) in res
    end // end of [list_vt_nil]
// end of [loop]
val xss = list_vt_reverse (xss)
//
prval () = lemma_list_vt_param (xss)
//
in
//
case+ xss of
| ~list_vt_cons
    (xs, xss) => loop (xs, xss)
| ~list_vt_nil () => list_vt_nil ()
//
end // end of [list_vt_concat]

(* ****** ****** *)

implement{a}
list_vt_separate (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: list_vt (a, n)
, res1: &ptr? >> list_vt (a, n1)
, res2: &ptr? >> list_vt (a, n2)
) : #[n1,n2:nat | n1+n2==n] void = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs_tl) => let
    val xs_tl_v = xs_tl
    val test = list_vt_separate$pred (x)
  in
    if test then let
      val () = res1 := xs
      val () = loop (xs_tl_v, xs_tl, res2)
    in
      fold@ (res1)
    end else let
      val () = res2 := xs
      val () = loop (xs_tl_v, res1, xs_tl)
    in
      fold@ (res2)
    end // end of [if]
  end // end of [list_vt_cons]
| ~list_vt_nil () => (
    res1 := list_vt_nil; res2 := list_vt_nil
  )
//
end // end of [loop]
//
var res1: ptr
var res2: ptr
val () = loop (xs, res1, res2)
val () = xs := res1
//
in
  res2
end // end of [list_vt_separate]

(* ****** ****** *)

implement
{x}{env}
list_vt_foreach$cont (x, env) = true

implement{x}
list_vt_foreach (xs) = let
  var env: void = () in list_vt_foreach_env<x><void> (xs, env)
end // end of [list_vt_foreach]

implement
{x}{env}
list_vt_foreach_env
  (xs, env) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: !list_vt (x, n), env: &env
) : void = let
in
  case+ xs of
  | @list_vt_cons
      (x, xs1) => let
      val test = list_vt_foreach$cont (x, env)
    in
      if test then let
        val () = list_vt_foreach$fwork<x><env> (x, env)
        val () = loop (xs1, env)
        prval () = fold@ (xs)
      in
        // nothing
      end else let
        prval () = fold@ (xs) in (*nothing*)
      end // end of [if]
    end // end of [list_vt_cons]
  | list_vt_nil () => ()
end // end of [loop]
//
in
  loop (xs, env)
end // end of [list_vt_foreach_env]

(* ****** ****** *)

implement{a}
list_vt_foreach_fun
  {fe} (xs, f) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: !list_vt (a, n), f: (&a) -<fe> void
) :<fe> void =
  case+ xs of
  | @list_vt_cons
      (x, xs1) => let
      val () = f (x)
      val () = loop (xs1, f)
    in
      fold@ (xs)
    end // end of [list_vt_cons]
  | list_vt_nil () => ()
// end of [loop]
in
  loop (xs, f)
end // end of [list_vt_foreach_fun]

implement{a}
list_vt_foreach_funenv
  {v}{vt}{fe}
  (pf | xs, f, env) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  pf: !v
| xs: !list_vt (a, n)
, f: (!v | &a, !vt) -<fe> void
, env: !vt
) :<fe> void =
  case+ xs of
  | @list_vt_cons
      (x, xs1) => let
      val () = f (pf | x, env)
      val () = loop (pf | xs1, f, env)
    in
      fold@ (xs)
    end // end of [list_vt_cons]
  | list_vt_nil () => ()
// end of [loop]
//
in
  loop (pf | xs, f, env)
end // end of [list_vt_foreach_funenv]

(* ****** ****** *)

implement
{x}{env}
list_vt_iforeach$cont (i, x, env) = true

implement{x}
list_vt_iforeach (xs) = let
  var env: void = () in list_vt_iforeach_env<x><void> (xs, env)
end // end of [list_vt_iforeach]

implement
{x}{env}
list_vt_iforeach_env
  (xs, env) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat}{i:int} .<n>. (
  i: int i, xs: !list_vt (x, n), env: &env
) : intBtwe(i, n+i) = let
in
  case+ xs of
  | @list_vt_cons (x, xs1) => let
      val test =
        list_vt_iforeach$cont<x><env> (i, x, env)
      // end of [val]
    in
      if test then let
        val () =
          list_vt_iforeach$fwork<x><env> (i, x, env)
        // end of [val]
        val i = loop (succ(i), xs1, env)
        prval () = fold@ (xs)
      in
        i // the number of processed elements
      end else let
        prval () = fold@ (xs)
      in
        i // the number of processed elements
      end // end of [if]
    end // end of [list_vt_cons]
  | list_vt_nil () => i // the number of processed elements
end // end of [loop]
//
in
  loop (0, xs, env)
end // end of [list_vt_iforeach_env]

(* ****** ****** *)

implement{a}
list_vt_filter (xs) = let
//
implement
list_vt_filterlin$pred<a>
  (x) = list_vt_filter$pred<a> (x)
implement
list_vt_filterlin$clear<a>
  (x) = let
  prval () = topize (x) in (*void*)
end // end of [list_vt_filterlin$clear]
//
in
  list_vt_filterlin<a> (xs)
end // end of [list_vt_filter]

(* ****** ****** *)

implement{a}
list_vt_filterlin$clear (x) = gclear_ref (x)
implement{a}
list_vt_filterlin (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: &list_vt (a, n) >> listLte_vt (a, n)
) :<!wrt> void = let
in
  case+ xs of
  | @list_vt_cons (x, xs1) => let
      val test = list_vt_filterlin$pred<a> (x)
    in
      if test then let
        val () = loop (xs1)
      in
        fold@ (xs)
      end else let
        val xs1 = xs1
        val () =
          list_vt_freelin$clear<a> (x)
        val () = free@{a}{0}(xs)
        val () = xs := xs1
      in
        loop (xs)
      end // end of [if]
    end // end of [list_vt_cons]
  | @list_vt_nil () => fold@ (xs)
end // end of [loop]
//
var xs = xs
val () = loop (xs)
//
in
  xs
end // end of [list_vt_filterlin]

(* ****** ****** *)

implement{a}
list_vt_app
  (xs) = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs1) => let
    val () =
      list_vt_app$fwork<a> (x)
    val () = list_vt_app<a> (xs1)
    prval () = fold@ (xs)
  in
    // nothing
  end
| list_vt_nil () => ()
//
end // end of [list_vt_app]

implement{a}
list_vt_appfree
  (xs) = let
in
//
case+ xs of
| @list_vt_cons
    (x, xs1) => let
    val xs1 = xs1
    val () = list_vt_appfree$fwork<a> (x)
    val () = free@ {a}{0} (xs)
  in
    list_vt_appfree<a> (xs1)
  end
| ~list_vt_nil () => ()
//
end // end of [list_vt_appfree]

(* ****** ****** *)

implement
{a}{b}
list_vt_map
  (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: !list_vt (a, n)
, res: &ptr? >> list_vt (b, n)
) : void = let
in
  case+ xs of
  | @list_vt_cons
      (x, xs1) => let
      val y =
        list_vt_map$fopr<a><b> (x)
      // end of [val]
      val () = res := list_vt_cons{b}{0}(y, _)
      val+list_vt_cons (_, res1) = res
      val () = loop (xs1, res1)
      val () = fold@ (xs)
      prval () = fold@ (res)
    in
      // nothing
    end // end of [list_vt_cons]
  | list_vt_nil () => (res := list_vt_nil ())
end // end of [loop]
//
var res: ptr
val () = loop (xs, res)
//
in
  res
end // end of [list_vt_map]

implement
{a}{b}
list_vt_mapfree
  (xs) = let
//
prval () = lemma_list_vt_param (xs)
//
fun loop
  {n:nat} .<n>. (
  xs: list_vt (a, n)
, res: &ptr? >> list_vt (b, n)
) : void = let
in
  case+ xs of
  | ~list_vt_cons
      (x, xs1) => let
      val y =
        list_vt_mapfree$fopr<a><b> (x)
      val () =
        res := list_vt_cons{b}{0}(y, _)
      val+list_vt_cons (_, res1) = res
      val () = loop (xs1, res1)
      prval () = fold@ (res)
    in
      // nothing
    end // end of [list_vt_cons]
  | ~list_vt_nil () => (res := list_vt_nil ())
end // end of [loop]
//
var res: ptr
val () = loop (xs, res)
//
in
  res
end // end of [list_vt_mapfree]

(* ****** ****** *)

(* end of [list_vt.dats] *)
