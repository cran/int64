// read_string.h : 64 bit integers
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
    
#ifndef int64__read_string__h
#define int64__read_string__h
              
namespace Rint64{
    namespace internal{
 
    template <>
    inline int64_t read_string<int64_t>(const char* s ){
        errno = 0 ;
        int64_t res = strtoll( s, NULL, 0 ) ;
        if( errno == ERANGE ) {
            res = Rint64::LongVector<int64_t>::na() ;
            int64_naflag = true ;
        }
        return res ;
    }
        
    template <>
    inline uint64_t read_string<uint64_t>(const char* s){
        errno = 0 ;
        uint64_t res = strtoull( s, NULL, 0 ) ;
        if( errno == ERANGE ) {
            res = Rint64::LongVector<uint64_t>::na() ;
            int64_naflag = true ;
        }
        return res ;
    } 
        
    
    } // namespace internal
} // namespace Rint64

#endif
