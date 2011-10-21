// long_traits.h: int64 64 bit integers
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

#ifndef int64_long_traits_h
#define int64_long_traits_h

namespace Rint64{
    namespace internal{
       
        template <typename LONG>
        struct long_traits ;
        
        template<>
        struct long_traits<int64_t>{
            static inline int64_t min   () { return std::numeric_limits<int64_t>::min() + 1 ;                        }
            static inline int64_t max   () { return std::numeric_limits<int64_t>::max() ;                            }
            static inline int64_t na    () { return std::numeric_limits<int64_t>::min() ;                            }
            static inline int     na_hb () { return get_high_bits<int64_t>( std::numeric_limits<int64_t>::min()  );  }
            static inline int     na_lb () { return get_low_bits<int64_t>( std::numeric_limits<int64_t>::min()  );   }
        } ;
        
        template<>
        struct long_traits<uint64_t>{
            static inline uint64_t min  () { return 0 ;                        }
            static inline uint64_t max  () { return std::numeric_limits<uint64_t>::max() - 1;                            }
            static inline uint64_t na   () { return std::numeric_limits<uint64_t>::max() ;                            }
            static inline int     na_hb () { return get_high_bits<uint64_t>( std::numeric_limits<uint64_t>::max()  );  }
            static inline int     na_lb () { return get_low_bits<uint64_t>( std::numeric_limits<uint64_t>::max()  );   }
        } ;
        
    }
}


#endif
