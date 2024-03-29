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
** $PATSHOME/prelude/SATS/CODEGEN/array.atxt
** Time of generation: Tue Aug 20 17:55:50 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: Feburary, 2012 *)

(* ****** ****** *)

vtypedef
RD(a:vt0p) = a // for commenting: read-only
#define NSH (x) x // for commenting: no sharing
#define SHR (x) x // for commenting: it is shared

(* ****** ****** *)

sortdef t0p = t@ype
sortdef vtp = viewtype
sortdef vt0p = viewt@ype

(* ****** ****** *)

(*
//
// HX: [array_v] can also be defined as follows:
//
dataview
array_v (
  a:viewt@ype+, addr, int
) =
  | {l:addr}{n:int}
    array_v_cons (a, l, n+1) of (a @ l, array_v (a, l+sizeof a, n))
  | {l:addr} array_v_nil (a, l, 0)
// end of [array_v]
*)

(* ****** ****** *)

dataview
arrayopt_v (
  a:viewt@ype+, addr, int, bool
) = // HX: for optional array view
  | {l:addr}{n:int}
    arrayopt_v_some (a, l, n, true) of array_v (a, l, n)
  | {l:addr}{n:int}
    arrayopt_v_none (a, l, n, false) of array_v (a?, l, n)
// end of [arrayopt_v]

(* ****** ****** *)

exception ArraySubscriptExn of ()
(*
fun ArraySubscriptExn ():<> exn = "mac#%ArraySubscriptExn_make"
fun isArraySubscriptExn (x: !exn):<> bool = "mac#%isArraySubscriptExn"
macdef
ifArraySubscriptExn
  {tres}(exn, body) =
(
let val x = ,(exn) in
(
if isArraySubscriptExn(x)
  then
    let prval () = __vfree_exn (x) in ,(body) end
  else $raise (x)
) : tres // end of [if]
end (* end of [let] *)
) // end of [ifArraySubscriptExn]
*)

(* ****** ****** *)

praxi
lemma_array_param{a:vt0p}
  {l:addr}{n:int} (A: &(@[INV(a)][n])): [n >= 0] void
// end of [lemma_array_param]
praxi
lemma_array_v_param{a:vt0p}
  {l:addr}{n:int} (pf: !array_v (INV(a), l, n)): [n >= 0] void
// end of [lemma_array_v_param]

(* ****** ****** *)

praxi array_v_nil :
  {a:vt0p}{l:addr} () -<prf> array_v (a, l, 0)
praxi array_v_unnil :
  {a:vt0p}{l:addr} array_v (a, l, 0) -<prf> void

prfun array_v_unnil_nil :
  {a1,a2:vt0p}{l:addr} array_v (a1, l, 0) -<prf> array_v (a2, l, 0)
// end of [array_v_unnil_nil]

(* ****** ****** *)

praxi array_v_cons :
  {a:vt0p}{l:addr}{n:int}
  (a @ l, array_v (INV(a), l+sizeof(a), n)) -<prf> array_v (a, l, n+1)
praxi array_v_uncons :
  {a:vt0p}{l:addr}{n:int | n > 0}
  array_v (INV(a), l, n) -<prf> (a @ l, array_v (a, l+sizeof(a), n-1))

(* ****** ****** *)

prfun array_v_sing
  {a:vt0p}{l:addr} (pf: INV(a) @ l): array_v (a, l, 1)
prfun array_v_unsing
  {a:vt0p}{l:addr} (pf: array_v (INV(a), l, 1)): a @ l

(* ****** ****** *)
//
fun{a:vt0p}
array_getref_at
  {n:int} (A: &RD(@[INV(a)][n]), i: sizeLt n):<> cPtr1 (a)
//
(* ****** ****** *)

fun{a:t0p}
array_get_at_size
  {n:int} (A: &RD(@[INV(a)][n]), i: sizeLt n):<> a

fun{
a:t0p}{tk:tk
} array_get_at_gint
  {n:int} (A: &RD(@[INV(a)][n]), i: g1intLt (tk, n)):<> a
overload [] with array_get_at_gint of 0

fun{
a:t0p}{tk:tk
} array_get_at_guint
  {n:int} (A: &RD(@[INV(a)][n]), i: g1uintLt (tk, n)):<> a
overload [] with array_get_at_guint of 0

symintr array_get_at
overload array_get_at with array_get_at_gint of 0
overload array_get_at with array_get_at_guint of 0

(* ****** ****** *)

fun{a:t0p}
array_set_at_size
  {n:int} (A: &(@[INV(a)][n]), i: sizeLt n, x: a):<!wrt> void

fun{
a:t0p}{tk:tk
} array_set_at_gint
  {n:int} (A: &(@[INV(a)][n]), i: g1intLt (tk, n), x: a):<!wrt> void
overload [] with array_set_at_gint of 0

fun{
a:t0p}{tk:tk
} array_set_at_guint
  {n:int} (A: &(@[INV(a)][n]), i: g1uintLt (tk, n), x: a):<!wrt> void
overload [] with array_set_at_guint of 0

symintr array_set_at
overload array_set_at with array_set_at_gint of 0
overload array_set_at with array_set_at_guint of 0

(* ****** ****** *)

fun{a:vt0p}
array_exch_at_size{n:int}
(
  A: &(@[INV(a)][n]), i: sizeLt n, x: &a >> _
) :<!wrt> void // end of [array_exch_at_size]

fun{
a:vt0p}{tk:tk
} array_exch_at_gint{n:int}
(
  A: &(@[INV(a)][n]), i: g1intLt (tk, n), x: &a >> _
) :<!wrt> void
fun{
a:vt0p}{tk:tk
} array_exch_at_guint{n:int}
(
  A: &(@[INV(a)][n]), i: g1uintLt (tk, n), x: &a >> _
) :<!wrt> void

symintr array_exch_at
overload array_exch_at with array_exch_at_gint of 0
overload array_exch_at with array_exch_at_guint of 0

(* ****** ****** *)

fun{a:vt0p}
array_interchange{n:int}
(
  A: &(@[INV(a)][n]), i: sizeLt (n), j: sizeLt (n)
) :<!wrt> void // end of [array_interchange]

(* ****** ****** *)

fun{a:vt0p}
array_subcirculate{n:int}
(
  A: &(@[INV(a)][n]), i: sizeLt (n), j: sizeLt (n)
) :<!wrt> void // end of [array_subcirculate]

(* ****** ****** *)

fun{a:vt0p}
array_ptr_takeout
  {l:addr}{n:int}{i:nat | i < n}
(
  array_v (INV(a), l, n) | ptr l, size_t i
) : (
  a @ (l+i*sizeof(a))
, a @ (l+i*sizeof(a)) -<lin,prf> array_v (a, l, n)
| ptr (l+i*sizeof(a))
) // end of [array_ptr_takeout]

(* ****** ****** *)

fun{a:vt0p}
array_ptr_alloc
  {n:int}
(
  asz: size_t n
) :<!wrt> [l:agz]
(
  array_v (a?, l, n), mfree_gc_v (l) | ptr l
) // end of [array_ptr_alloc]

fun{}
array_ptr_free
  {a:vt0p}{l:addr}{n:int}
(
  array_v (a?, l, n), mfree_gc_v (l) | ptr l
) :<!wrt> void // end of [array_ptr_free]

(* ****** ****** *)

fun{a:vt0p}
array_tabulate$fopr (i: size_t): (a)
fun{a:vt0p}
array_ptr_tabulate
  {n:int} (asz: size_t n)
  : [l:addr] (array_v (a, l, n), mfree_gc_v (l) | ptr l)
// end of [arrayptr_tabulate]

(* ****** ****** *)

fun{a:vt0p}
fprint_array{n:int}
(
  out: FILEref, A: &RD(@[INV(a)][n]), n: size_t n
) : void // end of [fprint_array]
fun{}
fprint_array$sep (out: FILEref): void

(* ****** ****** *)

fun{a:vt0p}
fprint_array_sep{n:int}
(
  out: FILEref
, A: &RD(@[INV(a)][n]), n: size_t n, sep: NSH(string)
) : void // end of [fprint_array_sep]

(* ****** ****** *)

fun{a:vt0p}
array_copy{n:int}
(
  to: &(@[a?][n]) >> @[a][n]
, from: &RD(@[INV(a)][n]) >> @[a?!][n]
, n: size_t (n)
) :<!wrt> void // end of [array_copy]

(* ****** ****** *)

fun{a:t0p}
array_copy_from_list{n:int}
(
  A: &(@[a?][n]) >> @[a][n], xs: list (INV(a), n)
) :<!wrt> void // end of [array_copy_from_list]

fun{a:vt0p}
array_copy_from_list_vt{n:int}
(
  A: &(@[a?][n]) >> @[a][n], xs: list_vt (INV(a), n)
) :<!wrt> void // end of [array_copy_from_list_vt]

(* ****** ****** *)

fun{a:vt0p}
array_copy_to_list_vt{n:int}
(
  A: &RD(@[INV(a)][n]) >> @[a?!][n], n: size_t n
) :<!wrt> list_vt (a, n) // endfun

macdef array2lst = array_copy_to_list_vt

(* ****** ****** *)

fun{
a:vt0p}{env:vt0p
} array_foreach$cont (x: &a, env: &env): bool
fun{
a:vt0p}{env:vt0p
} array_foreach$fwork (x: &a >> _, env: &(env) >> _): void
fun{
a:vt0p
} array_foreach{n:int}
(
  A: &(@[INV(a)][n]) >> @[a][n], asz: size_t n
) : sizeLte (n) // end of [array_foreach]
fun{
a:vt0p}{env:vt0p
} array_foreach_env{n:int}
(
  A: &(@[INV(a)][n]) >> @[a][n], asz: size_t n, env: &(env) >> _
) : sizeLte (n) // end of [array_foreach_env]

(* ****** ****** *)

fun{a:vt0p}
array_foreach_funenv
  {v:view}
  {vt:viewtype}
  {n:int}
  {fe:eff}
(
  pfv: !v
| A: &(@[INV(a)][n])
, asz: size_t n
, f: (!v | &a, !vt) -<fun,fe> void
, env: !vt
) :<fe> void
// end of [array_foreach_funenv]

fun
array_foreach_funenv_tsz
  {a:vt0p}
  {v:view}
  {vt:viewtype}
  {n:int}
  {fe:eff}
(
  pfv: !v
| A: &(@[INV(a)][n])
, asz: size_t n
, tsz: sizeof_t a
, f: (!v | &a, !vt) -<fun,fe> void
, env: !vt
) :<fe> void = "ext#%"
// end of [array_foreach_funenv_tsz]

(* ****** ****** *)

fun{a:vt0p}
array_foreach_fun
  {n:int}{fe:eff}
(
  &(@[INV(a)][n]), size_t (n), (&a) -<fun,fe> void
) :<fe> void // end of [array_foreach_fun]

fun{a:vt0p}
array_foreach_clo
  {n:int}{fe:eff}
(
  A: &(@[INV(a)][n])
, asz: size_t n
, f: &(&a) -<clo,fe> void
) :<fe> void // end of [array_foreach_clo]
fun{a:vt0p}
array_foreach_vclo
  {v:view}{n:int}{fe:eff}
(
  pfv: !v
| A: &(@[INV(a)][n])
, asz: size_t n
, f: &(!v | &a) -<clo,fe> void
) :<fe> void // end of [array_foreach_vclo]

fun{a:vt0p}
array_foreach_cloptr
  {n:int}{fe:eff}
(
  A: &(@[INV(a)][n])
, asz: size_t n
, f: (&a) -<cloptr,fe> void
) :<fe> void // end of [array_foreach_cloptr]
fun{a:vt0p}
array_foreach_vcloptr
  {v:view}{n:int}{fe:eff}
(
  pfv: !v
| A: &(@[INV(a)][n])
, asz: size_t n
, f: !(!v | &a) -<cloptr,fe> void
) :<fe> void // end of [array_foreach_vcloptr]

fun{a:vt0p}
array_foreach_cloref
  {n:int}{fe:eff}
(
  A: &(@[INV(a)][n]), asz: size_t n, f: (&a) -<cloref,fe> void
) :<fe> void // end of [array_foreach_cloref]

(* ****** ****** *)

fun{
a1,a2:vt0p}{env:vt0p
} array_foreach2$cont
  (x1: &a1, x2: &a2, env: &env): bool
fun{
a1,a2:vt0p}{env:vt0p
} array_foreach2$fwork
  (x1: &a1 >> _, x2: &a2 >> _, env: &(env) >> _): void
fun{
a1,a2:vt0p
} array_foreach2
  {n:int}
(
  A1: &(@[INV(a1)][n]) >> @[a1][n]
, A2: &(@[INV(a2)][n]) >> @[a2][n]
, asz: size_t (n)
) : sizeLte (n) // end of [array_foreach2]
fun{
a1,a2:vt0p}{env:vt0p
} array_foreach2_env
  {n:int}
(
  A1: &(@[INV(a1)][n]) >> @[a1][n]
, A2: &(@[INV(a2)][n]) >> @[a2][n]
, asz:size_t (n)
, env: &(env) >> env
) : sizeLte (n) // end of [array_foreach2_env]

(* ****** ****** *)

fun{
a:vt0p}{env:vt0p
} array_iforeach$cont (i: size_t, x: &a, env: &env): bool
fun{
a:vt0p}{env:vt0p
} array_iforeach$fwork (i: size_t, x: &a >> _, env: &(env) >> _): void

fun{
a:vt0p
} array_iforeach{n:int}
(
  A: &(@[INV(a)][n]) >> @[a][n], asz: size_t n
) : sizeLte (n) // end of [array_iforeach]
fun{
a:vt0p}{env:vt0p
} array_iforeach_env{n:int}
(
  A: &(@[INV(a)][n]) >> @[a][n], asz: size_t n, env: &(env) >> _
) : sizeLte (n) // end of [array_iforeach_env]

(* ****** ****** *)

fun{
a:vt0p}{env:vt0p
} array_rforeach$cont (x: &a, env: &env): bool
fun{
a:vt0p}{env:vt0p
} array_rforeach$fwork (x: &a >> _, env: &(env) >> _): void

fun{
a:vt0p
} array_rforeach{n:int}
(
  A: &(@[INV(a)][n]) >> @[a][n], asz: size_t n
) : sizeLte (n) // end of [array_rforeach]
fun{
a:vt0p}{env:vt0p
} array_rforeach_env{n:int}
(
  A: &(@[INV(a)][n]) >> @[a][n], asz: size_t n, env: &(env) >> _
) : sizeLte (n) // end of [array_rforeach_env]

(* ****** ****** *)

fun{a:vt0p}
array_initize$init (i: size_t, x: &a? >> a): void

fun{a:vt0p}
array_initize{n:int}
  (A: &(@[a?][n]) >> @[a][n], asz: size_t n) : void
// end of [array_initize]

macdef array_initialize = array_initize

(* ****** ****** *)

fun{a:t0p}
array_initize_elt{n:int}
(
  A: &(@[a?][n]) >> @[a][n], asz: size_t n, elt: a
) :<!wrt> void // end of [array_initize_elt]

(* ****** ****** *)

fun{a:t0p}
array_initize_list{n:int}
(
  A: &(@[a?][n]) >> @[a][n], asz: int n, xs: list (INV(a), n)
) :<!wrt> void // end of [array_initize_list]
fun{a:t0p}
array_initize_rlist{n:int}
(
  A: &(@[a?][n]) >> @[a][n], asz: int n, xs: list (INV(a), n)
) :<!wrt> void // end of [array_initize_rlist]

(* ****** ****** *)

fun{a:vt0p}
array_initize_list_vt{n:int}
(
  A: &(@[a?][n]) >> @[a][n], asz: int n, xs: list_vt (INV(a), n)
) :<!wrt> void // end of [array_initize_list_vt]
fun{a:vt0p}
array_initize_rlist_vt{n:int}
(
  A: &(@[a?][n]) >> @[a][n], asz: int n, xs: list_vt (INV(a), n)
) :<!wrt> void // end of [array_initize_rlist_vt]

(* ****** ****** *)

fun{a:vt0p}
array_uninitize$clear
  (i: size_t, x: &a >> a?): void
fun{a:vt0p}
array_uninitize{n:int}
(
  A: &(@[INV(a)][n]) >> @[a?][n], asz: size_t n
) : void // end of [array_uninitize]
macdef array_uninitialize = array_uninitize

(* ****** ****** *)

fun{a:vt0p}
array_bsearch$ford (x: &RD(a)):<> int
fun{a:vt0p}
array_bsearch
  {n:int} (A: &RD(@[a][n]), n: size_t (n)):<> sizeLte (n)
// end of [array_bsearch]

fun{a:vt0p}
array_bsearch_fun{n:int}
(
  A: &RD(@[a][n]), asz: size_t (n), key: &RD(a), cmp: cmpref (a)
) :<> sizeLte (n) // end of [array_bsearch_fun]

(* ****** ****** *)

(*
** HX: this one is based on [bsearch] in [stdlib]
*)
fun{a:vt0p}
array_bsearch_stdlib{n:int}
(
  A: &RD(@[a][n]), asz: size_t (n), key: &RD(a), cmp: cmpref (a)
) :<> Ptr0 (* found/~found : ~null/null *)

(* ****** ****** *)

fun{a:vt0p}
array_quicksort$cmp
  (x1: &RD(a), x2: &RD(a)):<> int
fun{a:vt0p}
array_quicksort{n:int}
  (A: &(@[INV(a)][n]) >> @[a][n], n: size_t n):<!wrt> void
// end of [array_quicksort]

(*
** HX: this one is based on [qsort] in [stdlib]
*)
fun{a:vt0p}
array_quicksort_stdlib{n:int}
(
  A: &(@[INV(a)][n]) >> @[a][n], n: size_t n, cmp: cmpref (a)
) :<!wrt> void // end of [array_quicksort_stdlib]

(* ****** ****** *)

fun
{a:vt0p}
{b:vt0p}
array_mapto$fwork
(
  x: &a, y: &b? >> b
) : void // [array_mapto$fwork]
fun
{a:vt0p}
{b:vt0p}
array_mapto{n:int}
(
  A: &array(INV(a), n)
, B: &array(b?, n) >> array (b, n)
, n: size_t (n)
) : void // end of [array_mapto]

(* ****** ****** *)

fun
{a,b:vt0p}
{c:vt0p}
array_map2to$fwork
(
  x: &a, y: &b, z: &c? >> c
) : void // [array_map2to$fwork]
fun
{a,b:vt0p}
{c:vt0p}
array_map2to{n:int}
(
  A: &array(INV(a), n)
, B: &array(INV(b), n)
, C: &array(c?, n) >> array (c, n)
, n: size_t (n)
) : void // end of [array_map2to]

(* ****** ****** *)

fun{}
array_permute$randint
  {n:int | n > 0} (n: size_t n): sizeLt (n)
fun{a:vt0p}
array_permute{n:int}
  (A: &(@[INV(a)][n]) >> @[a][n], n: size_t n): void
// end of [array_permute]

(* ****** ****** *)

(* end of [array.sats] *)
