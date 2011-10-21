// format_binary.h : 64 bit integers
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
    
#ifndef int64__binary__h
#define int64__binary__h

namespace Rint64{
    namespace internal{

        template <typename T>
        inline const char* format_binary__impl(T x) {
            const int SIZE = sizeof(T)*8 ;
            static std::string b( SIZE, '0' ) ;
            
            for (int z = 0; z < SIZE; z++) {
                b[SIZE-1-z] = ((x>>z) & 0x1) ? '1' : '0';
            }
        
            return b.c_str() ;
        }    
        
        template <>
        inline const char* format_binary__impl<double>(double x){
                int64_t* y = (int64_t*)&x ;
                return format_binary__impl<int64_t>(*y) ;
        }

        template <typename LONG>
        SEXP int64_format_binary_long(SEXP x){
            Rint64::LongVector<LONG> data(x) ;
            int n = data.size() ; 
            
            SEXP res = PROTECT( Rf_allocVector( STRSXP, n ) ) ;
            for( int i=0; i<n; i++){
                SET_STRING_ELT( res, i, Rf_mkChar( format_binary__impl(data.get(i)) ) ) ;
            }
            UNPROTECT(1) ; // res
            return res ;
        }
        
    } // namespace internal
} // namespace Rint64
#endif
