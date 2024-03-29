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
** $PATSHOME/prelude/SATS/CODEGEN/arrayptr.atxt
** Time of generation: Mon Jul 22 19:30:08 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: February, 2012 *)

(* ****** ****** *)

#define NSH (x) x // for commenting: no sharing
#define SHR (x) x // for commenting: it is shared

(* ****** ****** *)

sortdef t0p = t@ype and vt0p = viewt@ype

(* ****** ****** *)

#if(0)
//
// HX-2013-06:
// it is declared in [basic_dyn.sats]
//
absvtype
arrayptr_vt0ype_addr_int_vtype
  (a:vt0ype+, l: addr, n: int) = ptr (l)
//
stadef
arrayptr = arrayptr_vt0ype_addr_int_vtype
vtypedef
arrayptr
  (a:vt0p, n:int) = [l:addr] arrayptr (a, l, n)
//
#endif

(* ****** ****** *)

absvtype
arrayptrout_vt0ype_addr_int_vtype
  (a:t@ype, l: addr, n: int) = ptr (l)
stadef arrayptrout = arrayptrout_vt0ype_addr_int_vtype

(* ****** ****** *)

praxi
lemma_arrayptr_param{a:vt0p}
  {l:addr}{n:int} (A: !arrayptr (a, l, n)): [n >= 0] void
// end of [lemma_arrayptr_param]

(* ****** ****** *)

castfn
arrayptr_encode :
  {a:vt0p}{l:addr}{n:int}
  (array_v (INV(a), l, n), mfree_gc_v l | ptr l) -<0> arrayptr (a, l, n)
// end of [arrayptr_encode]

castfn
arrayptr_encode2 :
  {a:vt0p}{l:addr}{n:int}
  @(array_v (INV(a), l, n), mfree_gc_v l | ptr l) -<0> arrayptr (a, l, n)
// end of [arrayptr_encode2]

(* ****** ****** *)

castfn
arrayptr2ptr
  {a:vt0p}
  {l:addr}{n:int} (A: !arrayptr (INV(a), l, n)):<> ptr (l)
overload ptrcast with arrayptr2ptr

castfn
arrayptrout2ptr
  {a:t0p}{l:addr}{n:int} (A: !arrayptrout (INV(a), l, n)):<> ptr (l)
overload ptrcast with arrayptrout2ptr

(* ****** ****** *)

praxi
arrayptr_takeout
  {a:vt0p}{l:addr}{n:int}
(
  A: !arrayptr (INV(a), l, n) >> arrayptrout (a?, l, n)
) : array_v (a, l, n) // end of [arrayptr_takeout]

praxi
arrayptr_addback
  {a:vt0p}{l:addr}{n:int}
(
  pf: array_v (INV(a), l, n) | A: !arrayptrout (a?, l, n) >> arrayptr (a, l, n)
) : void // end of [arrayptr_addback]

(* ****** ****** *)

castfn
arrayptr_takeout_viewptr
  {a:vt0p}{l:addr}{n:int}
(
  A: !arrayptr (INV(a), l, n) >> arrayptrout (a?, l, n)
) : (array_v (a, l, n) | ptr l) // endfun

(* ****** ****** *)

castfn
arrpsz_encode :
  {a:vt0p}{n:int}
  @(arrayptr (INV(a), n), size_t n) -<0> arrpsz (a, n)
// end of [arrpsz_encode]

castfn
arrpsz_decode :
  {a:vt0p}{n:int}
  arrpsz (INV(a), n) -<0> @(arrayptr (a, n), size_t n)
// end of [arrpsz_decode]

(* ****** ****** *)

fun
arrpsz_get_ptrsize
  {a:vt0p}{n:int}
(
  psz: arrpsz (INV(a), n), asz: &size_t? >> size_t (n)
) :<!wrt> arrayptr (a, n) = "mac#%" // endfun

(* ****** ****** *)

symintr arrayptr

(* ****** ****** *)

fun{
a:t0p
} arrayptr_make_elt
  {n:int} (asz: size_t n, x: a):<!wrt> arrayptr (a, n)
// end of [arrayptr_make_elt]

(* ****** ****** *)

fun{
} arrayptr_make_intrange
  {l,r:int | l <= r}
  (l: int l, r: int r):<!wrt> arrayptr (intBtw(l, r), r-l)
// end of [arrayptr_make_intrange]

(* ****** ****** *)
//
// HX: this one is a field-selection
//
fun
arrayptr_make_arrpsz
  {a:vt0p}{n:int}
  (psz: arrpsz (INV(a), n)):<> arrayptr (a, n) = "mac#%"
overload arrayptr with arrayptr_make_arrpsz

(* ****** ****** *)

fun{a:t0p}
arrayptr_make_list{n:int}
  (asz: int n, xs: list (INV(a), n)):<!wrt> arrayptr (a, n)
// end of [arrayptr_make_list]
fun{a:t0p}
arrayptr_make_rlist{n:int}
  (asz: int n, xs: list (INV(a), n)):<!wrt> arrayptr (a, n)
// end of [arrayptr_make_rlist]

(* ****** ****** *)

fun{a:vt0p}
arrayptr_make_list_vt{n:int}
  (asz: int n, xs: list_vt (INV(a), n)):<!wrt> arrayptr (a, n)
// end of [arrayptr_make_list_vt]
fun{a:vt0p}
arrayptr_make_rlist_vt{n:int}
  (asz: int n, xs: list_vt (INV(a), n)):<!wrt> arrayptr (a, n)
// end of [arrayptr_make_rlist_vt]

(* ****** ****** *)

fun{a:vt0p}
arrayptr_make_uninitized
  {n:int} (asz: size_t n):<!wrt> arrayptr (a?, n)
// end of [arrayptr_make_uninitized]

(* ****** ****** *)

fun{a:vt0p}
arrayptr_imake_list{n:int}
(
  A: !arrayptr (INV(a), n) >> arrayptr (a?!, n), n: size_t (n)
) : list_vt (a, n) // end of [arrayptr_imake_list]

(* ****** ****** *)

fun arrayptr_free
  {a:t0p}{l:addr}{n:int}
  (A: arrayptr (INV(a), l, n)):<!wrt> void = "mac#%"
// end of [arrayptr_free]

(* ****** ****** *)

(*
fun{}
fprint_array$sep (out: FILEref): void
*)
fun{a:vt0p}
fprint_arrayptr
  {l:addr}{n:int}
(
  out: FILEref, A: !arrayptr (INV(a), l, n), n: size_t n
) : void // end of [fprint_arrayptr]
fun{a:vt0p}
fprint_arrayptr_sep
  {l:addr}{n:int}
(
  out: FILEref
, A: !arrayptr (INV(a), l, n), n: size_t n, sep: NSH(string)
) : void // end of [fprint_arrayptr_sep]

overload fprint with fprint_arrayptr
overload fprint with fprint_arrayptr_sep

(* ****** ****** *)

symintr arrayptr_get_at

fun{a:t0p}
arrayptr_get_at_size{n:int}
  (A: !arrayptr (INV(a), n), i: sizeLt (n)):<> (a)
// end of [arrayptr_get_at_size]

fun{
a:t0p}{tk:tk
} arrayptr_get_at_gint
  {n:int}{i:nat | i < n}
  (A: !arrayptr (INV(a), n), i: g1int (tk, i)):<> (a)
overload [] with arrayptr_get_at_gint of 0

fun{
a:t0p}{tk:tk
} arrayptr_get_at_guint
  {n:int}{i:nat | i < n}
  (A: !arrayptr (INV(a), n), i: g1uint (tk, i)):<> (a)
overload [] with arrayptr_get_at_guint of 0

overload arrayptr_get_at with arrayptr_get_at_gint
overload arrayptr_get_at with arrayptr_get_at_guint

(* ****** ****** *)

symintr arrayptr_set_at

fun{a:t0p}
arrayptr_set_at_size{n:int}
  (A: !arrayptr (INV(a), n), i: sizeLt (n), x: a):<!wrt> void
// end of [arrayptr_set_at_size]

fun{
a:t0p}{tk:tk
} arrayptr_set_at_gint
  {n:int}{i:nat | i < n}
  (A: !arrayptr (INV(a), n), i: g1int (tk, i), x: a):<!wrt> void
overload [] with arrayptr_set_at_gint of 0

fun{
a:t0p}{tk:tk
} arrayptr_set_at_guint
  {n:int}{i:nat | i < n}
  (A: !arrayptr (INV(a), n), i: g1uint (tk, i), x: a):<!wrt> void
overload [] with arrayptr_set_at_guint of 0

overload arrayptr_set_at with arrayptr_set_at_gint of 0
overload arrayptr_set_at with arrayptr_set_at_guint of 0

(* ****** ****** *)

symintr arrayptr_exch_at

fun{a:vt0p}
arrayptr_exch_at_size{n:int}
  (A: !arrayptr (INV(a), n), i: sizeLt (n), x: &a):<!wrt> void
// end of [arrayptr_exch_at_size]

fun{
a:vt0p}{tk:tk
} arrayptr_exch_at_gint
  {n:int}{i:nat | i < n}
  (A: !arrayptr (INV(a), n), i: g1int (tk, i), x: &a >> _):<!wrt> void
// end of [arrayptr_exch_at_gint]

fun{
a:vt0p}{tk:tk
} arrayptr_exch_at_guint
  {n:int}{i:nat | i < n}
  (A: !arrayptr (INV(a), n), i: g1uint (tk, i), x: &a >> _):<!wrt> void
// end of [arrayptr_exch_at_guint]

overload arrayptr_exch_at with arrayptr_exch_at_gint of 0
overload arrayptr_exch_at with arrayptr_exch_at_guint of 0

(* ****** ****** *)

fun{a:vt0p}
arrayptr_interchange
  {n:int}
(
  A: !arrayptr (INV(a), n), i: sizeLt n, j: sizeLt n
) :<!wrt> void // end of [arrayptr_interchange]

(* ****** ****** *)

(*
fun{a:vt0p}{env:vt0p}
array_foreach$cont (x: &a, env: &env): void
fun{a:vt0p}{env:vt0p}
array_foreach$fwork (x: &a >> a, env: &(env) >> _): void
*)
fun{
a:vt0p
} arrayptr_foreach{n:int}
(
  A: !arrayptr (INV(a), n), asz: size_t (n)
) : sizeLte(n) // end of [arrayptr_foreach]
fun{
a:vt0p}{env:vt0p
} arrayptr_foreach_env{n:int}
(
  A: !arrayptr (INV(a), n), asz: size_t (n), env: &(env) >> _
) : sizeLte(n) // end of [arrayptr_foreach_env]

(* ****** ****** *)

fun{a:vt0p}
arrayptr_foreach_fun
  {n:int}{fe:eff}
(
  A: !arrayptr (INV(a), n), asz: size_t n, f: (&a) -<fun,fe> void
) :<fe> void // end of [arrayptr_foreach_fun]

fun{a:vt0p}
arrayptr_foreach_funenv
  {v:view}
  {vt:vtype}
  {n:int}
  {fe:eff}
(
  pfv: !v
| A: !arrayptr (INV(a), n)
, asz: size_t n
, f: (!v | &a, !vt) -<fun,fe> void
, env: !vt
) :<fe> void
// end of [arrayptr_foreach_funenv]

(* ****** ****** *)

(*
fun{a:vt0p}{env:vt0p}
array_iforeach$cont (i: size_t, x: &a, env: &env): void
fun{a:vt0p}{env:vt0p}
array_iforeach$fwork (i: size_t, x: &a >> a, env: &(env) >> _): void
*)
fun{
a:vt0p
} arrayptr_iforeach{n:int}
(
  A: !arrayptr (INV(a), n), asz: size_t (n)
) : sizeLte(n) // end of [arrayptr_iforeach]
fun{
a:vt0p}{env:vt0p
} arrayptr_iforeach_env{n:int}
(
  A: !arrayptr (INV(a), n), asz: size_t (n), env: &(env) >> _
) : sizeLte(n) // end of [arrayptr_iforeach_env]

(* ****** ****** *)

(*
fun{a:vt0p}{env:vt0p}
array_rforeach$cont (x: &a, env: &env): void
fun{a:vt0p}{env:vt0p}
array_rforeach$fwork (x: &a >> a, env: &(env) >> _): void
*)
fun{
a:vt0p
} arrayptr_rforeach{n:int}
(
  A: !arrayptr (INV(a), n), asz: size_t (n)
) : sizeLte(n) // end of [arrayptr_rforeach]
fun{
a:vt0p}{env:vt0p
} arrayptr_rforeach_env{n:int}
(
  A: !arrayptr (INV(a), n), asz: size_t (n), env: &(env) >> _
) : sizeLte(n) // end of [arrayptr_rforeach_env]

(* ****** ****** *)

(*
fun{a:vt0p}
array_initize$init (i: size_t, x: &a >> a?): void
*)
fun{a:vt0p}
arrayptr_initize
  {l:addr}{n:int}
(
  A: !arrayptr (a?, l, n) >> arrayptr (a, l, n), asz: size_t n
) : void // end of [arrayptr_initize]
macdef arrayptr_initialize = arrayptr_initize

(* ****** ****** *)

(*
fun{a:vt0p}
array_uninitize$clear (i: size_t, x: &a >> a?): void
*)
fun{a:vt0p}
arrayptr_uninitize
  {l:addr}{n:int}
(
  A: !arrayptr (INV(a), l, n) >> arrayptr (a?, l, n), asz: size_t n
) : void // end of [arrayptr_uninitize]
macdef
arrayptr_uninitialize = arrayptr_uninitize

(* ****** ****** *)

(*
fun{a:vt0p}
array_uninitize$clear (i: size_t, x: &a >> a?): void
*)
fun{a:vt0p}
arrayptr_freelin
  {l:addr}{n:int}
  (A: arrayptr (INV(a), l, n), asz: size_t (n)): void
// end of [arrayptr_freelin]

(* ****** ****** *)
//
(*
fun{a:vt0p}
array_tabulate$fopr (index: size_t): (a)
*)
fun{a:vt0p}
arrayptr_tabulate
  {n:int} (asz: size_t n): arrayptr (a, n)
//
(* ****** ****** *)

(* end of [arrayptr.sats] *)
