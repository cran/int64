// routines.h: int64 64 bit integers
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

#ifndef int64_int2_h
#define int64_int2_h


namespace Rint64{
    namespace internal{
        
        // we only use this for T=int
        template <typename T>
        SEXP int2( T x, T y){
            SEXP res = PROTECT( Rf_allocVector(INTSXP, 2) ) ;
            int* p = INTEGER(res) ;
            p[0] = x;
            p[1] = y ;
            UNPROTECT(1) ;
            return res ;
        }
        
    }
}


#endif
