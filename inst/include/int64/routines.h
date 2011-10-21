// routines.h: int64 64 bit integers - .Call exports
//
// Copyright (C) 2011 Romain Francois
// Copyright (C) 2011 Google Inc.  All rights reserved.
//
// This file is part of int64.
//
// int64 is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// int64 is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with int64.  If not, see <http://www.gnu.org/licenses/>.

#ifndef int64_routines_h
#define int64_routines_h

#define CALLFUN_0(name) SEXP name()
#define CALLFUN_1(name) SEXP name(SEXP)
#define CALLFUN_2(name) SEXP name(SEXP,SEXP)
#define CALLFUN_3(name) SEXP name(SEXP,SEXP,SEXP)
#define CALLFUN_4(name) SEXP name(SEXP,SEXP,SEXP,SEXP)
#define CALLFUN_5(name) SEXP name(SEXP,SEXP,SEXP,SEXP,SEXP)
#define EXTFUN(name) SEXP name(SEXP)

// we have to do the ifdef __cplusplus dance because this file
// is included both in C and C++ files
#ifdef __cplusplus
extern "C" {
#endif

CALLFUN_1(int64_as_int64) ;
CALLFUN_1(int64_format_binary) ;
CALLFUN_2(int64_as_character_int64) ;
CALLFUN_4(int64_arith_int64_int64) ;
CALLFUN_4(int64_compare_int64_int64) ;
CALLFUN_3(int64_summary_int64) ;

CALLFUN_1(int64_as_uint64) ;

CALLFUN_1(int64_limits) ;

CALLFUN_3(int64_sort) ;
CALLFUN_3(int64_math) ;
CALLFUN_3(int64_signif) ;
CALLFUN_2(int64_isna) ;

#ifdef __cplusplus
}
#endif

#endif
