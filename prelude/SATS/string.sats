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
** $PATSHOME/prelude/SATS/CODEGEN/string.atxt
** Time of generation: Mon Jul 22 19:30:03 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: September, 2011 *)

(* ****** ****** *)

(*
** HX: a string is a null-terminated arrayref of characters
*)

(* ****** ****** *)

sortdef tk = tkind

(* ****** ****** *)

typedef SHR(a:type) = a // for commenting purpose
typedef NSH(a:type) = a // for commenting purpose

(* ****** ****** *)
//
typedef
stringLt (n:int) = [k:nat | k < n] string (k)
typedef
stringLte (n:int) = [k:nat | k <= n] string (k)
//
typedef
stringGt (n:int) = [k:int | k > n] string (k)
typedef
stringGte (n:int) = [k:int | k >= n] string (k)
//
typedef
stringBtw
  (m:int, n:int) = [k:int | m <= k; k < n] string (k)
typedef
stringBtwe
  (m:int, n:int) = [k:int | m <= k; k <= n] string (k)
//
(* ****** ****** *)

typedef stringlst = List0 (string)
vtypedef stringlst_vt = List0_vt (string)

(* ****** ****** *)

dataprop
string_index_p
(
  n: int, int(*i*), int(*c*)
) =
  | string_index_p_eqz (n, n, 0)
  | {i:int | n > i}
    {c:int8 | c != 0}
    string_index_p_neqz (n, i, c)
// end of [string_index_p]

(* ****** ****** *)

praxi
lemma_string_param
  {n:int} (x: string n): [n >= 0] void
// end of [lemma_string_param]

(* ****** ****** *)

castfn string2ptr (x: string):<> Ptr1

(* ****** ****** *)
//
// HX: [string2string] = [string1_of_string0]
//
castfn g0ofg1_string (x: String):<> string
castfn g1ofg0_string (x: string):<> String0
//
overload g0ofg1 with g0ofg1_string // index-erasing
overload g1ofg0 with g1ofg0_string // index-inducing
//
(* ****** ****** *)

(* ****** ****** *)

fun{}
string_sing (c: charNZ):<> strnptr (1)

(* ****** ****** *)

fun{}
string_make_list
  {n:int} (cs: list(charNZ, n)):<> strnptr (n)
fun{}
string_make_listlen
  {n:int} (cs: list(charNZ, n), n: int n):<> strnptr (n)

(* ****** ****** *)

fun{
} string_make_rlist
  {n:int} (cs: list(charNZ, n)):<> strnptr (n)
// end of [string_make_rlist]

fun{
} string_make_rlistlen
  {n:int} (cs: list(charNZ, n), n: int n):<> strnptr (n)
// end of [string_make_rlistlen]

(* ****** ****** *)

fun{
} string_make_substring
  {n:int}{st,ln:nat | st+ln <= n}
  (str: string (n), st: size_t st, ln: size_t ln):<> strnptr (ln)
// end of [string_make_substring]

(* ****** ****** *)

fun{} string_is_empty (x: string):<> bool
fun{} string_isnot_empty (x: string):<> bool

(* ****** ****** *)
//
symintr string_is_atend
//
fun{}
string_is_atend_size
  {n:int}{i:nat | i <= n}
  (s: string (n), i: size_t (i)):<> bool (i==n)
fun{tk:tk}
string_is_atend_gint
  {n:int}{i:nat | i <= n}
  (s: string (n), i: g1int (tk, i)):<> bool (i==n)
overload string_is_atend with string_is_atend_gint
fun{tk:tk}
string_is_atend_guint
  {n:int}{i:nat | i <= n}
  (s: string (n), i: g1uint (tk, i)):<> bool (i==n)
overload string_is_atend with string_is_atend_guint

(* ****** ****** *)

macdef
string_isnot_atend
  (string, index) = ~string_is_atend (,(string), ,(index))
// end of [string_isnot_atend]

(* ****** ****** *)

fun{}
string_get_at_size
  {n:int}{i:nat | i < n}
  (s: string (n), i: size_t (i)):<> charNZ
overload [] with string_get_at_size of 1
fun{tk:tk}
string_get_at_gint
  {n:int}{i:nat | i < n}
  (s: string (n), i: g1int (tk, i)):<> charNZ
overload [] with string_get_at_gint of 0
fun{tk:tk}
string_get_at_guint
  {n:int}{i:nat | i < n}
  (s: string (n), i: g1uint (tk, i)):<> charNZ
overload [] with string_get_at_guint of 0
//
symintr string_get_at
overload string_get_at with string_get_at_size of 1
overload string_get_at with string_get_at_gint of 0
overload string_get_at with string_get_at_guint of 0
//
(* ****** ****** *)

fun{}
string_test_at_size
  {n:int}{i:nat | i <= n}
  (s: string (n), i: size_t (i)):<> [c:int] (string_index_p (n, i, c) | char (c))
fun{tk:tk}
string_test_at_gint
  {n:int}{i:nat | i <= n}
  (s: string (n), i: g1int (tk, i)):<> [c:int] (string_index_p (n, i, c) | char (c))
fun{tk:tk}
string_test_at_guint
  {n:int}{i:nat | i <= n}
  (s: string (n), i: g1uint (tk, i)):<> [c:int] (string_index_p (n, i, c) | char (c))
//
symintr string_test_at
overload string_test_at with string_test_at_size of 1
overload string_test_at with string_test_at_gint of 0
overload string_test_at with string_test_at_guint of 0
//
(* ****** ****** *)

fun lt_string_string
  (x1: string, x2: string):<> bool = "mac#%"
overload < with lt_string_string
fun lte_string_string
  (x1: string, x2: string):<> bool = "mac#%"
overload <= with lte_string_string

fun gt_string_string
  (x1: string, x2: string):<> bool = "mac#%"
overload > with gt_string_string
fun gte_string_string
  (x1: string, x2: string):<> bool = "mac#%"
overload >= with gte_string_string

fun eq_string_string
  (x1: string, x2: string):<> bool = "mac#%"
overload = with eq_string_string
fun neq_string_string
  (x1: string, x2: string):<> bool = "mac#%"
overload != with neq_string_string
overload <> with neq_string_string

fun compare_string_string
  (x1: string, x2: string):<> Sgn = "mac#%"
overload compare with compare_string_string

(* ****** ****** *)

fun{
} strcmp (x1: string, x2: string):<> int

fun{
} strintcmp
  {n1,n2:int | n2 >=0}
  (x1: string n1, n2: int n2):<> int(sgn(n1-n2))
// end of [strintcmp]

fun{
} strlencmp
  {n1,n2:int}
  (x1: string n1, x2: string n2):<> int(sgn(n1-n2))
// end of [strlencmp]

(* ****** ****** *)

fun print_string (x: string): void = "mac#%"
fun prerr_string (x: string): void = "mac#%"
fun fprint_string (out: FILEref, x: string): void = "mac#%"

(* ****** ****** *)

fun{
} strchr {n:int}
  (str: string (n), c0: char):<> ssizeBtwe (~1, n)
// end of [strchr]

fun{
} strrchr {n:int}
  (str: string (n), c0: char):<> ssizeBtwe (~1, n)
// end of [strrchr]

fun{
} strstr {n:int}
  (haystack: string (n), needle: string):<> ssizeBtw (~1, n)
// end of [strstr]

(* ****** ****** *)

fun{
} strspn {n:int} // spanning
  (str: string (n), accept: string):<> sizeLte (n)
// end of [strspn]
fun{
} strcspn {n:int} // complement spanning
  (str: string (n), accept: string):<> sizeLte (n)
// end of [strcspn]

(* ****** ****** *)

fun{
} string_index {n:int}
  (str: string (n), c0: charNZ):<> ssizeBtw (~1, n)
// end of [string_index]

fun{
} string_rindex {n:int}
  (str: string (n), c0: charNZ):<> ssizeBtw (~1, n)
// end of [string_rindex]

(* ****** ****** *)
//
symintr strlen
symintr string_length
//
fun{
} string0_length
  (x: NSH(string)):<> size_t
fun{
} string1_length
  {n:int} (x: NSH(string(n))):<> size_t (n)
//
overload strlen with string0_length of 0
overload strlen with string1_length of 10
overload string_length with string0_length of 0
overload string_length with string1_length of 10
//
(* ****** ****** *)
//
symintr string_copy
//
fun{
} string0_copy
  (xs: NSH(string)):<!wrt> Strptr1
fun{
} string1_copy
  {n:int} (xs: NSH(string(n))):<!wrt> strnptr (n)
//
overload string_copy with string0_copy of 0
(*
overload string_copy with string1_copy of 10
*)
//
(* ****** ****** *)
//
symintr string_append
//
fun{
} string0_append (
  x1: NSH(string), x2: NSH(string)
) :<!wrt> Strptr1 // endfun
fun{
} string1_append
  {n1,n2:int} (
  x1: NSH(string(n1)), x2: NSH(string(n2))
) :<!wrt> strnptr (n1+n2) // end of [string1_append]
//
overload string_append with string0_append of 0
(*
overload string_append with string1_append of 20
*)
//
(* ****** ****** *)

fun{
} stringarr_concat{n:int}
  (xs: arrayref(string, n), size_t n):<!wrt> Strptr1
fun{
} stringlst_concat (xs: List(string)):<!wrt> Strptr1

(* ****** ****** *)

fun{
} string_explode
  {n:int} (x: string(n)):<!wrt> list_vt (charNZ, n)
// end of [string_explode]

(* ****** ****** *)

fun{
} string_tabulate$fopr (size_t): charNZ
fun{
} string_tabulate {n:int} (n: size_t n): strnptr (n)

(* ****** ****** *)
//
fun{env:vt0p}
string_foreach$cont (c: char, env: &env): bool
fun{env:vt0p}
string_foreach$fwork (c: char, env: &(env) >> _): void
//
fun{
} string_foreach {n:int} (str: string(n)): sizeLte(n)
fun{
env:vt0p
} string_foreach_env
  {n:int} (str: string(n), env: &(env) >> _): sizeLte(n)
// end of [string_foreach_env]
//
(* ****** ****** *)
//
fun{env:vt0p}
string_rforeach$cont (c: char, env: &env): bool
fun{env:vt0p}
string_rforeach$fwork (c: char, env: &(env) >> _): void
//
fun{
} string_rforeach {n:int} (str: string(n)): sizeLte(n)
fun{
env:vt0p
} string_rforeach_env
  {n:int} (str: string(n), env: &(env) >> _): sizeLte(n)
// end of [string_rforeach_env]
//
(* ****** ****** *)

(*
** HX: [stropt_none] is just the null pointer
*)
fun stropt_none (): stropt (~1) = "mac#%"

(* ****** ****** *)

symintr stropt_some
castfn stropt0_some (x: SHR(string)): Stropt1
overload stropt_some with stropt0_some of 0
castfn stropt1_some {n:int} (x: SHR(string n)): stropt (n)
overload stropt_some with stropt1_some of 10

(* ****** ****** *)

fun{
} stropt_is_none {n:int} (x: stropt n): bool (n < 0)
fun{
} stropt_is_some {n:int} (x: stropt n): bool (n >= 0)

(* ****** ****** *)

castfn
stropt_unsome {n:nat} (x: stropt n): string (n)

(* ****** ****** *)

fun{
} stropt_length
  {n:int} (x: stropt (n)): ssize_t (n)
// end of [stropt_length]

(* ****** ****** *)

fun print_stropt (x: Stropt0): void = "mac#%"
fun prerr_stropt (x: Stropt0): void = "mac#%"
fun fprint_stropt (out: FILEref, x: Stropt0): void = "mac#%"

(* ****** ****** *)
//
// overloading for certain symbols
//
overload iseqz with string_is_empty of 0
overload isneqz with string_isnot_empty of 0
//
overload iseqz with stropt_is_none of 10
overload isneqz with stropt_is_some of 10
//
overload length with string0_length of 0
overload length with string1_length of 10
//
overload length with stropt_length of 10
//
overload print with print_string of 0
overload prerr with prerr_string of 0
overload fprint with fprint_string of 0
//
overload print with print_stropt of 0
overload prerr with prerr_stropt of 0
overload fprint with fprint_stropt of 0
//
(* ****** ****** *)

(* end of [string.sats] *)
