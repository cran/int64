// get_long.h : 64 bit integers
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
    
#ifndef int64__get_long__h
#define int64__get_long__h
    
namespace Rint64{
    namespace internal{

template <typename T>
inline T get_long( int highbits, int lowbits ){
    return ( ( (T) (unsigned int)highbits ) << 32 ) | ( (T) (unsigned int)lowbits ) ;    
}

    } // namespace internal
    
} // namespace Rint64

#endif
