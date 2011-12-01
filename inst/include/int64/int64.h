// int64.h : 64 bit integers
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
    
#ifndef int64__int64__h
#define int64__int64__h

namespace Rint64{
    namespace internal {
        extern bool int64_naflag ;
    }
}

#include <int64/int2.h>
#include <int64/read_string_forward.h>
#include <int64/get_long.h>
#include <int64/get_bits.h>
#include <int64/long_traits.h>
#include <int64/get_class.h>
#include <int64/LongVector.h>
#include <int64/read_string.h>
#include <int64/format_binary.h>
#include <int64/as_long.h>
#include <int64/as_character.h>

namespace Rint64{
    namespace internal {
        
        template <typename LONG>
        SEXP new_long(LONG x){
            std::string klass = get_class<LONG>() ;
            Rint64::LongVector<LONG> y(1) ;
            y.set(0, x) ;
            return y ;
        }
        
        template <typename LONG>
        SEXP new_long_2(LONG x, LONG y){
            std::string klass = get_class<LONG>() ;
            Rint64::LongVector<LONG> z(2) ;
            z.set(0, x ) ;
            z.set(1, y ) ;
            return z ;
        }
        
    }
}

#if defined(BUILDING_INT64)
#include <int64/routines.h>
#endif 

#include <int64/arith.h>
#include <int64/compare.h>
#include <int64/summary.h>
#include <int64/math.h>

#endif
