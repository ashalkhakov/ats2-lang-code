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
** $PATSHOME/prelude/SATS/CODEGEN/arith_prf.atxt
** Time of generation: Thu Aug  8 16:32:52 2013
*)

(* ****** ****** *)

(* Author: Hongwei Xi *)
(* Authoremail: hwxi AT cs DOT bu DOT edu *)
(* Start time: September, 2011 *)

(* ****** ****** *)

dataprop
MUL (int, int, int) =
  | {n:int}
    MULbas (0, n, 0)
  | {m:nat}{n:int}{p:int}
    MULind (m+1, n, p+n) of MUL (m, n, p)
  | {m:pos}{n:int}{p:int}
    MULneg (~m, n, ~p) of MUL (m, n, p)
// end of [MUL]

(* ****** ****** *)

praxi mul_make : {m,n:int} () -<prf> MUL (m, n, m*n)
praxi mul_elim : {m,n:int} {p:int} MUL (m, n, p) -<prf> [p == m*n] void

(* ****** ****** *)

prfun mul_istot {m,n:int} ():<prf> [p:int] MUL (m, n, p)

prfun mul_isfun {m,n:int} {p1,p2:int}
  (pf1: MUL (m, n, p1), pf2: MUL (m, n, p2)):<prf> [p1==p2] void
prfun mul_isfun2 {m,n:int} {p1,p2:int}
  (pf1: MUL (m, n, p1), pf2: MUL (m, n, p2)):<prf> EQINT (p1, p2)

(* ****** ****** *)
//
// HX: (m+i)*n = m*n+i*n
//
praxi mul_add_const {i:int}
  {m,n:int} {p:int} (pf: MUL (m, n, p)):<prf> MUL (m+i, n, p+i*n)
// end of [mul_add_const]

(* ****** ****** *)
//
// HX: (ax+b)*(cy+d) = ac*xy + ad*x + bc*y + bd
//
praxi mul_expand_linear // a,b,c,d: constants!
  {a,b:int}
  {c,d:int}
  {x,y:int}
  {xy:int} (
  pf: MUL (x, y, xy)
) :<prf> MUL (a*x+b, c*y+d, a*c*xy+a*d*x+b*c*y+b*d)
// end of [mul_expand_linear]

(* ****** ****** *)
//
// HX: (a1x1+a2x2+b)*(c1y1+c2y2+d) = ...
//
praxi mul_expand2_linear // a1,b1,c1,a2,b2,c2: constants!
  {a1,a2,b:int}
  {c1,c2,d:int}
  {x1,x2:int}
  {y1,y2:int}
  {x1y1,x1y2,x2y1,x2y2:int} (
  pf11: MUL (x1, y1, x1y1), pf12: MUL (x1, y2, x1y2)
, pf21: MUL (x2, y1, x2y1), pf22: MUL (x2, y2, x2y2)
) :<prf> MUL (
  a1*x1+a2*x2+b
, c1*y1+c2*y2+d
, a1*c1*x1y1 + a1*c2*x1y2 +
  a2*c1*x2y1 + a2*c2*x2y2 +
  a1*d*x1 + a2*d*x2 +
  b*c1*y1 + b*c2*y2 +
  b*d
) // end of [mul_expand2_linear]

(* ****** ****** *)

prfun mul_gte_gte_gte
  : {m,n:int | m >= 0; n >= 0} () -<prf> [m*n >= 0] void
prfun mul_lte_gte_lte
  : {m,n:int | m <= 0; n >= 0} () -<prf> [m*n <= 0] void
prfun mul_gte_lte_lte
  : {m,n:int | m >= 0; n <= 0} () -<prf> [m*n <= 0] void
prfun mul_lte_lte_gte
  : {m,n:int | m <= 0; n <= 0} () -<prf> [m*n >= 0] void

(* ****** ****** *)

prfun mul_nat_nat_nat :
  {m,n:nat} {p:int} MUL (m, n, p) -<prf> [p >= 0] void
prfun mul_pos_pos_pos :
  {m,n:pos} {p:int} MUL (m, n, p) -<prf> [p >= m+n-1] void

(* ****** ****** *)

prfun mul_negate
  {m,n:int} {p:int} (pf: MUL (m, n, p)):<prf> MUL (~m, n, ~p)
prfun mul_negate2
  {m,n:int} {p:int} (pf: MUL (m, n, p)):<prf> MUL (m, ~n, ~p)

(* ****** ****** *)
//
// HX: m*n = n*m
//
prfun mul_commute
  {m,n:int} {p:int} (pf: MUL (m, n, p)):<prf> MUL (n, m, p)
prfun mul_is_commutative
  {m,n:int} {p,q:int} (pf1: MUL (m, n, p), pf2: MUL (n, m, q)): [p==q] void

(* ****** ****** *)
//
// HX: m*(n1+n2) = m*n1+m*n2
//
prfun mul_distribute
  {m:int} {n1,n2:int} {p1,p2:int}
  (pf1: MUL (m, n1, p1), pf2: MUL (m, n2, p2)):<prf> MUL (m, n1+n2, p1+p2)
//
// HX: (m1+m2)*n = m1*n + m2*n
//
prfun mul_distribute2
  {m1,m2:int} {n:int} {p1,p2:int}
  (pf1: MUL (m1, n, p1), pf2: MUL (m2, n, p2)):<prf> MUL (m1+m2, n, p1+p2)
//
(* ****** ****** *)

prfun
mul_is_associative
  {x,y,z:int}
  {xy,yz:int}
  {xy_z,x_yz:int} (
  pf1: MUL (x, y, xy), pf2: MUL (y, z, yz)
, pf3: MUL (xy, z, xy_z), pf4: MUL (x, yz, x_yz)
) :<prf> [xy_z==x_yz] void

(* ****** ****** *)
//
// HX-2010-12-30: 
//
absprop DIVMOD (
  x:int, y: int, q: int, r: int // x = q * y + r
) // end of [DIVMOD]

propdef DIV (x:int, y:int, q:int) = [r:int] DIVMOD (x, y, q, r)
propdef MOD (x:int, y:int, r:int) = [q:int] DIVMOD (x, y, q, r)

praxi div_istot {x,y:int | x >= 0; y > 0} (): DIV (x, y, x/y)

praxi divmod_istot
  {x,y:int | x >= 0; y > 0} (): [q,r:nat | r < y] DIVMOD (x, y, q, r)

praxi divmod_isfun
  {x,y:int | x >= 0; y > 0}
  {q1,q2:int} {r1,r2:int} (
  pf1: DIVMOD (x, y, q1, r1)
, pf2: DIVMOD (x, y, q2, r2)
) : [q1==q2;r1==r2] void // end of [divmod_isfun]

praxi divmod_elim
  {x,y:int | x >= 0; y > 0} {q,r:int}
  (pf: DIVMOD (x, y, q, r)): [qy:int | 0 <= r; r < y; x==qy+r] MUL (q, y, qy)
// end of [divmod_elim]

(* ****** ****** *)
//
dataprop EXP2 (int, int) =
  | {n:nat}{p:nat} EXP2ind (n+1, 2*p) of EXP2 (n, p)
  | EXP2bas (0, 1)
// end of [EXP2]
//
prfun lemma_exp2_param :
  {n:int}{p:int} EXP2 (n, p) -<prf> [n>=0;p>=1] void
// end of [lemma_exp2_param]
//
prfun exp2_istot {n:nat} (): [p:nat] EXP2 (n, p)
prfun exp2_isfun {n:nat} {p1,p2:int}
  (pf1: EXP2 (n, p1), pf2: EXP2 (n, p2)): [p1==p2] void
// end of [exp2_isfun]
//
// HX: proven in [arith_prf.dats]
//
prfun exp2_ispos
  {n:nat} {p:int} (pf: EXP2 (n, p)): [p >= 1] void
// end of [exp2_ispos]
//
// HX: proven in [arith_prf.dats]
//
prfun exp2_is_mono
  {n1,n2:nat | n1 <= n2} {p1,p2:int}
  (pf1: EXP2 (n1, p1), pf2: EXP2 (n2, p2)): [p1 <= p2] void
// end of [exp2_is_mono]
//
// HX: proven in [arith_prf.dats]
//
prfun exp2_muladd
  {n1,n2:nat | n1 <= n2} {p1,p2:int} {p:int} (
  pf1: EXP2 (n1, p1), pf2: EXP2 (n2, p2), pf3: MUL (p1, p2, p)
) : EXP2 (n1+n2, p) // end of [exp2_muladd]
//
(* ****** ****** *)

absprop EXP (int(*base*), int(*power*), int(*res*))

praxi lemma_exp_param
  {b:int}{n:int}{p:int} (pf: EXP (b, n, p)): [n >= 0] void
// end of [lemma_exp_param]

praxi exp_istot {b:int}{n:nat} (): [p:nat] EXP (b, n, p)
praxi exp_isfun {b:int}{n:int}{p1,p2:int}
  (pf1: EXP (b, n, p1), pf2: EXP (b, n, p2)): [p1==p2] void
// end of [exp_isfun]

praxi exp_elim_0 {n:pos}{p:int} (pf: EXP (0, n, p)): [p==0] void
praxi exp_elim_1 {n:int}{p:int} (pf: EXP (1, n, p)): [p==1] void
praxi exp_elim_2 {n:int}{p:int} (pf: EXP (2, n, p)): EXP2 (n, p)
praxi exp_elim_b_0 {b:int}{p:int} (pf: EXP (b, 0, p)): [p==1] void
praxi exp_elim_b_1 {b:int}{p:int} (pf: EXP (b, 1, p)): [p==b] void
praxi exp_elim_b_2 {b:int}{p:int} (pf: EXP (b, 2, p)): MUL (b, b, p)

praxi exp_muladd
  {b:int}{n1,n2:int}{p1,p2:int}{p:int} (
  pf1: EXP (b, n1, p1), pf2: EXP (b, n2, p2)
) : EXP (b, n1+n2, p1*p2) // end of [exp_muladd]

praxi exp_expmul
  {b:int}{n1,n2:int}{bn1:int}{bn1n2:int} (
  pf1: EXP (b, n1, bn1), pf2: EXP (bn1, n2, bn1n2)
) : EXP (b, n1*n2, bn1n2) // end of [exp_muladd]

(* ****** ****** *)

(* end of [arith_prf.sats] *)
