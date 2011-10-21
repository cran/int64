// int64_init.c : 64 bit integers
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
    
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

#include <int64/routines.h>

// borrowed from Matrix
#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}
#define EXTDEF(name)  {#name, (DL_FUNC) &name, -1}

static R_CallMethodDef callEntries[]  = {
    CALLDEF(int64_as_int64,1),
    CALLDEF(int64_format_binary,1),
    CALLDEF(int64_as_character_int64,2),
    CALLDEF(int64_arith_int64_int64,4),
    CALLDEF(int64_compare_int64_int64,4),
    CALLDEF(int64_summary_int64,3),
    
    CALLDEF(int64_as_uint64,1),
    
    CALLDEF(int64_limits,1),
    
    CALLDEF(int64_sort,3),
    CALLDEF(int64_math,3),
    CALLDEF(int64_signif,3),
    CALLDEF(int64_isna,2),
    
    {NULL, NULL, 0}
}; 

void R_init_int64( DllInfo* info){
  /* Register routines, allocate resources. */
  R_registerRoutines(info, 
      NULL /* .C*/, 
      callEntries /*.Call*/,
      NULL /* .Fortran */,
      NULL /*.External*/
  );
}
        
void R_unload_int64(DllInfo *info) {
  /* Release resources. */
}
