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
** $PATSHOME/prelude/SATS/CODEGEN/lazy.atxt
** Time of generation: Mon Jul 22 19:30:04 2013
*)

(* ****** ****** *)

sortdef t0p = t@ype

(* ****** ****** *)
//
// HX:
// [lazy(T)] : suspended computation of a value of type T
//
abstype
lazy_t0ype_type (t@ype+) // boxed type // unnamed
stadef lazy = lazy_t0ype_type
//
(* ****** ****** *)
//
// HX: lazy streams
//
datatype
stream_con (a:t@ype+) =
  | stream_cons (a) of (a, stream a) | stream_nil (a) of ()
where stream (a:t@ype) = lazy (stream_con a)
//
(* ****** ****** *)

(*
exception StreamSubscriptExn of ()
*)
fun StreamSubscriptExn ():<> exn = "mac#StreamSubscriptExn_make"
fun isStreamSubscriptExn (x: !exn):<> bool = "mac#isStreamSubscriptExn"

(* ****** ****** *)

fun{a:t0p}
stream2list
  (xs: stream (INV(a))):<!laz> List0_vt (a)
// end of [stream2list]

(* ****** ****** *)

fun{a:t0p}
stream_nth_exn
  (xs: stream (INV(a)), i: intGte(0)):<!laz> a
// end of [stream_nth_exn]
fun{a:t0p}
stream_nth_opt
  (xs: stream (INV(a)), i: intGte(0)):<!laz> Option_vt (a)
// end of [stream_nth_opt]

(* ****** ****** *)

fun{a:t0p}
stream_take_exn {n:nat}
  (xs: stream (INV(a)), n: int n):<!laz> list_vt (a, n)
// end of [stream_take_lte]

(* ****** ****** *)

fun{a:t0p}
stream_drop_exn
  (xs: stream (INV(a)), n: intGte(0)):<!laz> stream (a)
// end of [stream_drop_exn]

(* ****** ****** *)

fun{
env:vt0p
} stream_foreach$cont (env: &env): bool
fun{
a:t0p}{env:vt0p
} stream_foreach$fwork
  (x: a, env: &env): void // lin-cleared
fun{a:t0p}
stream_foreach (xs: stream (a)): void
fun{
a:t0p}{env:vt0p
} stream_foreach_env (xs: stream (a), &env): void

(* ****** ****** *)

fun{a:t0p}
stream_filter$pred (x: a):<> bool
fun{a:t0p}
stream_filter (xs: stream (INV(a))):<> stream (a)
fun{a:t0p}
stream_filter_fun
  (xs: stream (INV(a)), pred: (a) -<> bool):<> stream (a)
// end of [stream_filter_fun]
fun{a:t0p}
stream_filter_cloref
  (xs: stream (INV(a)), pred: (a) -<cloref> bool):<> stream (a)
// end of [stream_filter_cloref]

(* ****** ****** *)

fun{
a:t0p}{b:t0p
} stream_map$fwork (x: a):<!laz> b
fun{
a:t0p}{b:t0p
} stream_map (xs: stream (INV(a))):<> stream (b)
fun{
a:t0p}{b:t0p
} stream_map_fun
  (xs: stream (INV(a)), f: (a) -<fun,!laz> b):<> stream (b)
// end of [stream_map_fun]
fun{
a:t0p}{b:t0p
} stream_map_cloref
  (xs: stream (INV(a)), f: (a) -<cloref,!laz> b):<> stream (b)
// end of [stream_map_cloref]

(* ****** ****** *)

fun{
a1,a2:t0p}{b:t0p
} stream_map2$fwork (x1: a1, x2: a2):<!laz> b
fun{
a1,a2:t0p}{b:t0p
} stream_map2
  (xs1: stream (INV(a1)), xs2: stream (INV(a2))):<> stream (b)
// end of [stream_map2]
fun{
a1,a2:t0p}{b:t0p
} stream_map2_fun (
  xs1: stream (INV(a1))
, xs2: stream (INV(a2))
, f: (a1, a2) -<fun,!laz> b
) :<> stream (b)
// end of [stream_map2_fun]
fun{
a1,a2:t0p}{b:t0p
} stream_map2_cloref (
  xs1: stream (INV(a1))
, xs2: stream (INV(a2))
, f: (a1, a2) -<cloref,!laz> b
) :<> stream (b)
// end of [stream_map2_cloref]

(* ****** ****** *)

fun{a:t0p}
stream_merge$cmp (x1: a, x2: a):<> int
fun{a:t0p}
stream_merge
  (xs1: stream (INV(a)), xs2: stream (a)):<> stream (a)
fun{a:t0p}
stream_merge_fun (
  xs1: stream (INV(a)), xs2: stream (a), (a, a) -<fun> int
) :<> stream (a) // end of [stream_merge_fun]
fun{a:t0p}
stream_merge_cloref (
  xs1: stream (INV(a)), xs2: stream (a), (a, a) -<cloref> int
) :<> stream (a) // end of [stream_merge_cloref]

(* ****** ****** *)

(* end of [lazy.sats] *)
