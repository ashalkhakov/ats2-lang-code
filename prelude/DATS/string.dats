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
** $PATSHOME/prelude/DATS/CODEGEN/string.atxt
** Time of generation: Thu Aug  8 16:36:00 2013
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

#define CNUL '\000'

(* ****** ****** *)

overload + with add_ptr_bsz

(* ****** ****** *)

macdef castvwtp_trans = $UN.castvwtp0 // former name

(* ****** ****** *)

extern
fun memcpy
  (d:ptr, s:ptr, n:size_t):<!wrt> ptr = "mac#atspre_string_memcpy"
// end of [memcpy]

(* ****** ****** *)

implement{}
string_is_empty (str) = let
  val p = string2ptr(str) in $UN.ptr1_get<char>(p) = CNUL
end // end of [string_is_empty]
implement{}
string_isnot_empty (str) = let
  val p = string2ptr(str) in $UN.ptr1_get<char>(p) != CNUL
end // end of [string_isnot_empty]

(* ****** ****** *)

implement{}
string_is_atend_size{n}{i}
  (str, i) = let
  val p_i = add_ptr_bsz (string2ptr(str), i)
in
  $UN.cast{bool(n==i)}($UN.ptr1_get<char>(p_i) = CNUL)
end // end of [string_is_atend_size]

implement{tk}
string_is_atend_gint (str, i) =
  string_is_atend_size (str, g1int2uint(i))
// end of [string_is_atend_gint]
implement{tk}
string_is_atend_guint (str, i) =
  string_is_atend_size (str, g1uint2uint(i))
// end of [string_is_atend_guint]

(* ****** ****** *)

implement{}
string_get_at_size (str, i) =
  $UN.ptr1_get<charNZ>(string2ptr(str) + i)
// end of [string_get_at_size]

implement{tk}
string_get_at_gint (str, i) =
  string_get_at_size (str, g1int2uint (i))
// end of [string_get_at_gint]
implement{tk}
string_get_at_guint (str, i) =
  string_get_at_size (str, g1uint2uint (i))
// end of [string_get_at_guint]

(* ****** ****** *)

implement{}
string_test_at_size
  {n}{i} (str, i) = let
//
extern
castfn
__cast (c: char):<>
  [c:int] (string_index_p (n, i, c) | char (c))
//
in
  __cast ($UN.ptr1_get<char>(string2ptr(str) + i))
end // end of [string_test_at_size]

implement{tk}
string_test_at_gint (str, i) =
  string_test_at_size (str, g1int2uint (i))
// end of [string_test_at_gint]
implement{tk}
string_test_at_guint (str, i) =
  string_test_at_size (str, g1uint2uint (i))
// end of [string_test_at_guint]

(* ****** ****** *)

implement{
} strintcmp
  {n1,n2} (x1, n2) = let
//
prval () = lemma_string_param (x1)
//
fun loop
  {n2:nat} .<n2>.
  (p1: ptr, n2: int n2):<> int = let
  val c = $UN.ptr0_get<char>(p1)
in
  if c != CNUL then (
    if n2 > 0 then loop (ptr_succ<char>(p1), n2-1) else 1(*gt*)
  ) else (
    if n2 > 0 then ~1(*lt*) else 0(*eq*)
  ) // end of [if]
end // end of [loop]
//
in
  $UN.cast{int(sgn(n1-n2))}(loop (string2ptr(x1), n2))
end // end of [strintcmp]

implement{
} strlencmp
  {n1,n2} (x1, x2) = let
//
prval () = lemma_string_param (x1)
prval () = lemma_string_param (x2)
//
//
fun loop
  {n1:nat} .<n1>. (
  p1: ptr, p2: ptr
) :<> int = let
  val c1 = $UN.ptr0_get<char>(p1)
  val c2 = $UN.ptr0_get<char>(p2)
in
//
if c1 != CNUL then let
  prval () =
    __assert () where {
      extern praxi __assert (): [n1 > 0] void
  } // end of [prval]
in
  if c2 != CNUL then
    loop {n1-1} (ptr_succ<char>(p1), ptr_succ<char>(p2))
  else 1(*gt*) // end of [if]
end else (
  if c2 != CNUL then ~1(*lt*) else 0(*eq*)
) (* end of [if] *)
//
end // end of [loop]
//
in
  $UN.cast{int(sgn(n1-n2))}(loop{n1}(string2ptr(x1), string2ptr(x2)))
end // end of [strlencmp]

(* ****** ****** *)

implement{
} string_make_list (cs) =
  string_make_listlen (cs, list_length (cs))
// end of [string_make_list]

implement{
} string_make_listlen
  {n} (cs, n) = let
//
prval () = lemma_list_param (cs)
//
fun loop
  {n:nat} .<n>.
(
  cs: list (char, n), n: int n, p: ptr
) :<!wrt> ptr = let
in
  if n > 0 then let
    val+list_cons (c, cs) = cs
    val () = $UN.ptr0_set<char>(p, c)
  in
    loop (cs, n-1, ptr_succ<char>(p))
  end else p // end of [if]
end // end of [loop]
//
val n1 = n + 1
val (pf, pfgc | p0) =
  $effmask_wrt (malloc_gc ((i2sz)n1))
val p1 = $effmask_wrt (loop (cs, n, p0))
val () =
  $effmask_wrt ($UN.ptr0_set<char>(p1, CNUL))
//
in
  castvwtp_trans{strnptr(n)}((pf, pfgc | p0))
end // end of [string_make_listlen]

(* ****** ****** *)

implement{
} string_make_rlist (cs) =
  string_make_rlistlen (cs, list_length (cs))
// end of [string_make_rlist]

implement{
} string_make_rlistlen
  {n} (cs, n) = let
//
prval () = lemma_list_param (cs)
//
fun loop
  {n:nat} .<n>.
(
  cs: list (char, n), n: int n, p: ptr
) :<!wrt> ptr = let
in
  if n > 0 then let
    val p1 = ptr_pred<char>(p)
    val+list_cons (c, cs) = cs
    val () = $UN.ptr0_set<char>(p1, c)
  in
    loop (cs, n-1, p1)
  end else p // end of [if]
end // end of [loop]
//
val n1 = n + 1
val (pf, pfgc | p0) =
  $effmask_wrt (malloc_gc ((i2sz)n1))
val p1 = ptr_add<char>(p0, n)
val () =
  $effmask_wrt ($UN.ptr0_set<char>(p1, CNUL))
val p0 = $effmask_wrt (loop (cs, n, p1))
//
in
  castvwtp_trans{strnptr(n)}((pf, pfgc | p0))
end // end of [string_make_rlistlen]

(* ****** ****** *)

implement{
} string_make_substring
  {n}{st,ln}
  (str, st, ln) = $effmask_wrt let
//
val ln1 = succ(ln)
val (pf, pfgc | p_dst) = malloc_gc (ln1)
val p_src = string2ptr(str)
val p_dst = memcpy (p_dst, p_src + st, ln)
//
val () = $UN.ptr0_set<char>(p_dst + ln, CNUL)
//
in
  castvwtp_trans{strnptr(ln)}((pf, pfgc | p_dst))
end // end of [string_make_substring]

(* ****** ****** *)

implement{}
string0_length
  (str) = string1_length ($UN.cast{String}(str))
// end of [string0_length]

implement{}
string1_length
  {n} (str) =
  __strlen (str) where {
  extern fun __strlen (str: string n):<> size_t (n) = "mac#atspre_strlen"
} // end of [where] // end of [string1_length]

(* ****** ****** *)

implement{}
string0_copy
  (str) = let
//
val str = g1ofg0(str)
val str2 = string1_copy (str)
prval () = lemma_strnptr_param (str2)
//
in
  strnptr2strptr (str2)
end // end of [string0_copy]

implement{}
string1_copy
  {n} (str) = let
//
val n = string1_length (str)
val n1 = succ(n)
val (pf, pfgc | p) = malloc_gc (n1)
val _(*p*) = $effmask_wrt (memcpy (p, string2ptr(str), n1))
//
in
  castvwtp_trans{strnptr(n)}((pf, pfgc | p))
end // end of [string1_copy]

(* ****** ****** *)

implement{
} strchr {n} (str, c0) = let
//
prval () = lemma_string_param (str)
extern fun __strchr (string, int):<> ptr = "mac#atspre_strchr"
extern fun __sub (ptr, ptr):<> ssizeBtw (0, n) = "mac#atspre_sub_ptr_ptr"
val p0 = string2ptr(str)
val p1 = __strchr (str, (char2int0)c0)
//
in
  if p1 > the_null_ptr then __sub (p1, p0) else i2ssz(~1)
end // end of [strchr]

implement{
} strrchr {n} (str, c0) = let
//
prval () = lemma_string_param (str)
extern fun __strrchr (string, int):<> ptr = "mac#atspre_strrchr"
extern fun __sub (ptr, ptr):<> ssizeBtw (0, n) = "mac#atspre_sub_ptr_ptr"
val p0 = string2ptr(str)
val p1 = __strrchr (str, (char2int0)c0)
//
in
  if p1 > the_null_ptr then __sub (p1, p0) else i2ssz(~1)
end // end of [strrchr]

(* ****** ****** *)

implement{
} strstr {n}
  (haystack, needle) = let
//
prval () = lemma_string_param (haystack)
extern fun __strstr (string, string):<> ptr = "mac#atspre_strstr"
extern fun __sub (ptr, ptr):<> ssizeBtw (0, n) = "mac#atspre_sub_ptr_ptr"
val p0 = string2ptr(haystack)
val p1 = __strstr (haystack, needle)
//
in
  if p1 > the_null_ptr then __sub (p1, p0) else i2ssz(~1)
end // end of [strstr]

(* ****** ****** *)

implement{
} strspn {n}
  (str, accept) = let
//
prval () = lemma_string_param (str)
extern fun __strspn (string, string):<> sizeLte (n) = "mac#atspre_strspn"
//
in
  __strspn (str, accept)
end // end of [strspn]

implement{
} strcspn {n}
  (str, reject) = let
//
prval () = lemma_string_param (str)
extern fun __strcspn (string, string):<> sizeLte (n) = "mac#atspre_strcspn"
//
in
  __strcspn (str, reject)
end // end of [strcspn]

(* ****** ****** *)

implement{}
string_index {n}
  (str, c) = $UN.cast{ssizeBtw(~1,n)}(strchr (str, c))
// end of [string_index]

implement{}
string_rindex {n}
  (str, c) = $UN.cast{ssizeBtw(~1,n)}(strrchr (str, c))
// end of [string_rindex]

(* ****** ****** *)

implement{}
string0_append
  (x1, x2) = let
//
val x1 = g1ofg0(x1)
val x2 = g1ofg0(x2)
val x12 = string1_append (x1, x2)
prval () = lemma_strnptr_param (x12)
//
in
  strnptr2strptr (x12)
end // end of [string0_append]

implement{}
string1_append
  {n1,n2} (x1, x2) = let
//
val n1 = strlen (x1) and n2 = strlen (x2)
//
val n12 = n1 + n2
val (pf, fpf | p) = malloc_gc (succ(n12))
//
val p1 = memcpy (p, string2ptr(x1), n1)
val p2 = memcpy (p + n1, string2ptr(x2), succ(n2))
//
in
  castvwtp_trans{strnptr(n1+n2)}((pf, fpf | p))
end // end of [string1_append]

(* ****** ****** *)

implement{}
stringarr_concat (xs, asz) = let
//
fun loop
(
  p1: ptr, p2: ptr, i: size_t, ntot: size_t
) : size_t = let
in
//
if i > 0 then let
  val x = $UN.ptr0_get<string> (p1)
  val nx: size_t = string_length (x)
  val () = $UN.ptr0_set<size_t> (p2, nx)
in
  loop (ptr_succ<string> (p1), ptr_succ<size_t> (p2), pred(i), ntot+nx)
end else ntot // end of [if]
//
end // end of [loop]
//
fun loop2
(
  p1: ptr, p2: ptr, i: size_t, pres: ptr
) : void = let
in
//
if i > 0 then let
  val x = $UN.ptr0_get<string> (p1)
  val nx = $UN.ptr0_get<size_t> (p2)
  val _(*ptr*) = memcpy (pres, $UN.cast{ptr}(x), nx)
in
  loop2 (ptr_succ<string> (p1), ptr_succ<size_t> (p2), pred(i), pres+nx)
end else $UN.ptr0_set<char> (pres, CNUL)
//
end // end of [loop2]
//
val p1 = $UN.cast{ptr}(xs)
val nxs = arrayptr_make_uninitized<size_t> (asz)
val p2 = arrayptr2ptr (nxs)
//
val ntot = $effmask_all (loop (p1, p2, asz, i2sz(0)))
val (pf, pfgc | pres) = malloc_gc (g1ofg0(succ(ntot)))
val ((*void*)) = $effmask_all (loop2 (p1, p2, asz, pres))
//
val () = arrayptr_free (nxs)
//
in
  castvwtp_trans{Strptr1}((pf, pfgc | pres))
end // end of [stringarr_concat]

(* ****** ****** *)

implement{}
stringlst_concat (xs) = let
//
val n = list_length (xs)
prval () = lemma_list_param (xs)
prval [n:int] EQINT() = eqint_make_gint (n)
val xs2 = arrayptr_make_list (n, xs)
val res = stringarr_concat ($UN.castvwtp1{arrayref(string,n)}(xs2), i2sz(n))
val () = arrayptr_free (xs2)
//
in
  res
end // end of [stringlst_concat]

(* ****** ****** *)

implement{}
string_explode
  {n} (x) = let
//
prval () = lemma_string_param (x)
//
viewtypedef res(n) = list_vt (charNZ, n)
//
fun loop
  {n:nat} .<n>.
(
  x: string n, res: &ptr? >> res(n)
) :<!wrt> void = let
  val p = string2ptr (x)
  val c = $UN.ptr1_get<Char> (p)
in
//
if c != CNUL then let
  prval () = __assert () where {
    extern praxi __assert (): [n > 0] void
  }
  val () = res :=
    list_vt_cons {charNZ}{0} (c, _)
  val+list_vt_cons (_, res1) = res
  val x = $UN.cast{string(n-1)} (ptr1_succ(p))
  val () = loop (x, res1)
in
  fold@ (res)
end else let
  prval () = __assert () where {
    extern praxi __assert (): [n == 0] void
  } // end of [prval]
in
  res := list_vt_nil ()
end // end of [if]
//
end // end of [loop]
//
var res: ptr
val () = $effmask_wrt (loop (x, res))
//
in
  res
end // end of [string_explode]

(* ****** ****** *)

implement{}
string_tabulate {n} (n) = let
//
prval () = lemma_g1uint_param (n)
//
fun loop (
  p: ptr, n: size_t, i: size_t
) : void = let
in
//
if i < n then let
  val c = string_tabulate$fopr (i)
  val () = $UN.ptr0_set<char> (p, c)
in
  loop (ptr_succ<char> (p), n, succ (i))
end else
  $UN.ptr0_set<char> (p, CNUL)
// end of [if]
//
end // end of [loop]
//
val n1 = succ(n)
val (pf, fpf | p0) = malloc_gc (n1)
val () = loop (p0, n, g1int2uint (0))
//
in
  castvwtp_trans{strnptr(n)}((pf, fpf | p0))
end // end of [string_tabulate]

(* ****** ****** *)

implement{env}
string_foreach$cont (c, env) = true
implement{env}
string_foreach$fwork (c, env) = ((*void*))

implement{}
string_foreach (str) = let
  var env: void = () in string_foreach_env (str, env)
end // end of [string_foreach]

implement{env}
string_foreach_env
  {n} (str, env) = let
//
fun loop (
  p: ptr, env: &env
) : ptr = let
  val c = $UN.ptr0_get<char> (p)
  val cont = (
    if c != CNUL then string_foreach$cont<env> (c, env) else false
  ) : bool // end of [val]
in
  if cont then let
    val () =
      string_foreach$fwork<env> (c, env) in loop (ptr_succ<char> (p), env)
    // end of [val]
  end else (p) // end of [if]
end // end of [fun]
//
val p0 =
  string2ptr (str)
val p1 = loop (p0, env)
//
in
  $UN.cast{sizeLte(n)}(p1 - p0)
end // end of [string_foreach_env]

(* ****** ****** *)

implement{env}
string_rforeach$cont (c, env) = true
implement{env}
string_rforeach$fwork (c, env) = ((*void*))

implement{}
string_rforeach (str) = let
  var env: void = () in string_rforeach_env (str, env)
end // end of [string_rforeach]

implement{env}
string_rforeach_env
  {n} (str, env) = let
//
val n = string1_length (str)
typedef chararr = array (char, n)
val p = string2ptr (str)
val (pf, fpf | p) = $UN.ptr_vtake {chararr} (p)
//
implement
array_rforeach$cont<char><env>
  (c, env) = string_rforeach$cont<env> (c, env)
implement
array_rforeach$fwork<char><env>
  (c, env) = string_rforeach$fwork<env> (c, env)
val res = array_rforeach_env<char><env> (!p, n, env)
//
prval () = fpf (pf)
//
in
  res
end // end of [string_rforeach_env]

(* ****** ****** *)

(*
//
// HX-2013-03: it is now defined as a macro
//
implement
stropt_none () = $UN.cast{stropt(~1)} (the_null_ptr)
*)

(* ****** ****** *)

implement{
} stropt_is_none {n} (x) = (
  $UN.cast{bool(n < 0)} (ptr0_is_null ($UN.cast2ptr (x)))
) // end of [stropt_is_none]

implement{
} stropt_is_some {n} (x) =
(
  $UN.cast{bool(n>=0)} (ptr0_isnot_null ($UN.cast2ptr (x)))
) // end of [stropt_is_some]

(* ****** ****** *)

implement{
} stropt_length (x) = let
  prval () = lemma_stropt_param (x)
in
  if stropt_is_some (x) then
    g1uint2int (string1_length (stropt_unsome(x)))
  else i2ssz(~1) // end of [if]
end // end of [stropt_length]

(* ****** ****** *)

implement fprint_val<string> = fprint_string
implement fprint_val<stropt> = fprint_stropt

(* end of [string.dats] *)
