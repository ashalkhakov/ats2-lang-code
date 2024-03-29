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
** $PATSHOME/prelude/SATS/CODEGEN/unsafe.atxt
** Time of generation: Mon Jul 22 19:30:06 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: April, 2012 *)

(* ****** ****** *)

#define ATS_PACKNAME "ATSLIB.prelude.unsafe"
#define ATS_STALOADFLAG 0 // no static loading at run-time

(* ****** ****** *)

sortdef t0p = t@ype and vt0p = viewt@ype

(* ****** ****** *)
//
castfn cast {to:t0p}{from:t0p} (x: INV(from)):<> to
//
castfn castvwtp0 {to:vt0p}{from:vt0p} (x: INV(from)):<> to
//
// HX:
// [castvwtp1] is mostly used in a situation
// where a linear value is passed as a read-only value;
// for instance, casting [strptr] to [string] is often
// done for treating a linear string as a nonlinear one
// temporarily.
//
castfn castvwtp1 {to:vt0p}{from:vt0p} (x: !INV(from)>>from):<> to
//
(* ****** ****** *)
//
castfn cast2ptr {a:type} (x: INV(a)):<> ptr
castfn cast2Ptr0 {a:type} (x: INV(a)):<> Ptr0
castfn cast2Ptr1 {a:type} (x: INV(a)):<> Ptr1
//
castfn cast2int {a:t0p} (x: INV(a)):<> int
castfn cast2uint {a:t0p} (x: INV(a)):<> uint
//
castfn cast2lint {a:t0p} (x: INV(a)):<> lint
castfn cast2ulint {a:t0p} (x: INV(a)):<> ulint
//
castfn cast2llint {a:t0p} (x: INV(a)):<> llint
castfn cast2ullint {a:t0p} (x: INV(a)):<> ullint
//
castfn cast2size {a:t0p} (x: INV(a)):<> size_t
castfn cast2ssize {a:t0p} (x: INV(a)):<> ssize_t
//
castfn cast2sint {a:t0p} (x: INV(a)):<> sint
castfn cast2usint {a:t0p} (x: INV(a)):<> usint
//
castfn cast2intptr {a:t0p} (x: INV(a)):<> intptr
castfn cast2uintptr {a:t0p} (x: INV(a)):<> uintptr
//
(* ****** ****** *)

praxi cast2void {a:vt0p} (x: INV(a)):<prf> void

(* ****** ****** *)

praxi castview0 {to:view}{from:view} (pf: from):<prf> to
praxi castview1 {to:view}{from:view} (pf: !INV(from)):<prf> to

(* ****** ****** *)
//
// HX: these are popular ones:
//
castfn list_vt2t
  {a:t0p}{n:int} (xs: !list_vt (INV(a), n)):<> list (a, n)
// end of [list_vt2t]

castfn arrayptr2ref
  {a:vt0p}{n:int} (x: !arrayptr (INV(a), n)):<> arrayref (a, n)
// end of [arrayptr2ref]

castfn strptr2string {l:agz} (x: !strptr l):<> String0
castfn strptr2stropt {l:addr} (x: !strptr l):<> Stropt0
castfn strnptr2string {l:addr}{n:nat} (x: !strnptr (l, n)):<> string (n)

(* ****** ****** *)
//
// HX: only if you know what you are doing ...
//
symintr ptr_vtake

castfn ptr0_vtake
  {a:vt0p} (ptr):<> [l:addr] (a@l, a@l -<lin,prf> void | ptr l)
overload ptr_vtake with ptr0_vtake of 0

castfn ptr1_vtake
  {a:vt0p}{l:addr} (ptr l):<> (a@l, a@l -<lin,prf> void | ptr l) 
overload ptr_vtake with ptr1_vtake of 10

(* ****** ****** *)

praxi
vtakeout_void {v:view} (pf: !v): vtakeout0 (v)
castfn
vttakeout_void {a:vt0p} (x: !a):<> vttakeout0 (a)

(* ****** ****** *)
//
// HX: only if you know what you are doing ...
//
fun{a:vt0p} ptr0_get (p: ptr):<> a
fun{a:vt0p} ptr1_get (p: Ptr1):<> a
//
fun{a:vt0p} ptr0_set (p: ptr, x: INV(a)):<!wrt> void
fun{a:vt0p} ptr1_set (p: Ptr1, x: INV(a)):<!wrt> void
//
fun{a:vt0p} ptr0_exch (p: ptr, x: &INV(a) >> a):<!wrt> void
fun{a:vt0p} ptr1_exch (p: Ptr1, x: &INV(a) >> a):<!wrt> void
//
fun{a:vt0p} ptr0_intch (p1: ptr, p2: ptr):<!wrt> void
fun{a:vt0p} ptr1_intch (p1: Ptr1, p2: Ptr1):<!wrt> void
//
(* ****** ****** *)
//
// HX-2012-06:
// generic ops on numbers: +=, -=, *=, /=, %=
//
fun{a:t0p} ptr0_addby (p: ptr, x: a):<!wrt> void // !p += x
fun{a:t0p} ptr1_addby (p: Ptr1, x: a):<!wrt> void // !p += x
//
fun{a:t0p} ptr0_subby (p: ptr, x: a):<!wrt> void // !p -= x
fun{a:t0p} ptr1_subby (p: Ptr1, x: a):<!wrt> void // !p -= x
//
fun{a:t0p} ptr0_mulby (p: ptr, x: a):<!wrt> void // !p *= x
fun{a:t0p} ptr1_mulby (p: Ptr1, x: a):<!wrt> void // !p *= x
//
fun{a:t0p} ptr0_divby (p: ptr, x: a):<!wrt> void // !p /= x
fun{a:t0p} ptr1_divby (p: Ptr1, x: a):<!wrt> void // !p /= x
//
fun{a:t0p} ptr0_modby (p: ptr, x: a):<!wrt> void // !p %= x
fun{a:t0p} ptr1_modby (p: Ptr1, x: a):<!wrt> void // !p %= x
//
(* ****** ****** *)
//
// HX: only if you know what you are doing ...
//
castfn
ptr2cptr {a:vt0p}{l:addr} (p: ptr l):<> cptr (a, l)
//
castfn
cptr_vtake
  {a:vt0p}{l:agz}
  (p: cptr (INV(a), l)):<> (a@l, a@l -<lin,prf> void | ptr l)
// end of [cptr_vtake]
//
fun{a:vt0p} cptr_get (p: cPtr1 (INV(a))):<> a
fun{a:vt0p} cptr_set (p: cPtr1 (INV(a)), x: a):<!wrt> void
fun{a:vt0p} cptr_exch (p: cPtr1 (INV(a)), x: &a >> a):<!wrt> void
//
(* ****** ****** *)

(* end of [unsafe.sats] *)
