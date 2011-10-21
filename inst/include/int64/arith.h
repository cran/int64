// arith.h : 64 bit integers
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
    
#ifndef int64__arith__h
#define int64__arith__h
 
/* borrowed from R (arithmetic.c) */
# define OPPOSITE_SIGNS(x, y) ((x < 0) ^ (y < 0))
# define GOODISUM(x, y, z) (((x) > 0) ? ((y) < (z)) : ! ((y) < (z)))
# define GOODIDIFF(x, y, z) (!(OPPOSITE_SIGNS(x, y) && OPPOSITE_SIGNS(x, z)))
# define GOODIPROD(x, y, z) ((long double) (x) * (long double) (y) == (z))


namespace Rint64{
    namespace internal{

template <typename T> inline T plus(T x1,T x2){ 
    const T na = Rint64::LongVector<T>::na() ;
    if( x1 == na || x2 == na ){
        return na ;
    }
    T res = x1 + x2 ;
    if (res != na && GOODISUM(x1, x2, res)){
        return res ;
    }
    int64_naflag = true ;
    return na ;
}        
template <typename T> inline T minus(T x1,T x2){ 
    const T na = Rint64::LongVector<T>::na() ;
    if( x1 == na || x2 == na){
        return na ;
    }
    T res = x1 - x2 ;
    if( res != na  && GOODIDIFF(x1,x2,res) ){
        return res ;
    }
    int64_naflag = true ;
    return na ;
}
template <> inline uint64_t minus<uint64_t>( uint64_t x1, uint64_t x2){
    const uint64_t na = Rint64::LongVector<uint64_t>::na() ;
    if( x1 == na || x2 == na || x2 > x1) return na ;
    return x1 - x2 ;
}
template <typename T> inline T times(T x1,T x2){ 
    const T na = Rint64::LongVector<T>::na() ;
    if( x1 == na || x2 == na){
        return na ;
    }
    T res = x1 * x2 ;
    if( res != na && GOODIPROD(x1,x2,res)){
        return res ;
    }
    int64_naflag = true ;
    return na ;
}        
template <typename T> inline T divide(T x1,T x2){ 
    const T na = Rint64::LongVector<T>::na() ;
    if( x1 == na || x2 == na ){
        return na ;
    }
    return x1/x2 ;
}        
template <typename T> inline T modulo(T x1,T x2){ 
    const T na = Rint64::LongVector<T>::na() ;
    if( x1 == na || x2 == na ){
        return na ;
    }
    return x1 % x2 ;
}        
template <typename T> inline T int_div(T x1,T x2){ 
    const T na = Rint64::LongVector<T>::na() ;
    if( x1 == na || x2 == na ){
        return na ;
    }
    return x1 / x2 ;
}        
        
template <typename LONG, LONG Fun(LONG x1, LONG x2)>
SEXP arith_long_long(SEXP e1, SEXP e2){
    Rint64::LongVector<LONG> x1( e1 ) ;
    Rint64::LongVector<LONG> x2( e2 ) ;
    int64_naflag = false ;
    int n1 = x1.size(), n2 = x2.size();
    LONG tmp ;
    int i1 = 0, i2 = 0, i = 0 ;
    int n = (n1>n2) ? n1 : n2 ;
    Rint64::LongVector<LONG> res(n) ;
    
    if( n1 == n2 ){
        for( i=0; i<n1; i++){
            res.set( i, Fun( x1.get(i), x2.get(i) ) ) ;
        }
    } else if( n1 == 1 ){
        tmp = x1.get(0) ; 
        for( i=0; i<n2; i++){
            res.set(i, Fun( tmp, x2.get(i) ) ) ;
        }
    } else if( n2 == 1) {
        tmp = x2.get(i) ;
        for( i=0; i<n1; i++){
            res.set(i, Fun(x1.get(i), tmp) ) ;
        }
    } else {
        // recycling
        for (i=i1=i2=0; i<n; i1 = (++i1 == n1) ? 0 : i1, i2 = (++i2 == n2) ? 0 : i2, ++i){
           res.set( i, Fun( x1.get(i1), x2.get(i2) ) ) ;
        }
    }
    if( int64_naflag ) Rf_warning( "NAs produced by integer overflow" ) ;
    return res ;
}

    template <typename LONG>
    SEXP int64_arith__impl( const char* op, SEXP e1, SEXP e2){
        if( ! strncmp(op, "+", 1) ){
            return Rint64::internal::arith_long_long<LONG, Rint64::internal::plus<LONG> >( e1, e2) ;
        } else if( ! strncmp( op, "-", 1 ) ) {
            return Rint64::internal::arith_long_long<LONG, Rint64::internal::minus<LONG> >( e1, e2) ;
        } else if( ! strncmp( op, "*", 1) ) {
            return Rint64::internal::arith_long_long<LONG, Rint64::internal::times<LONG> >( e1, e2) ;
        } else if( ! strncmp( op, "^", 1 ) ) {
             Rf_error( "pow not implemented for long type" ) ;
        } else if( ! strncmp( op, "/", 1 ) ) {
            return Rint64::internal::arith_long_long<LONG, Rint64::internal::divide<LONG> >( e1, e2) ;
        } else if( ! strncmp( op, "%%", 2 ) ) {
            return Rint64::internal::arith_long_long<LONG, Rint64::internal::modulo<LONG> >( e1, e2) ;
        } else if( ! strncmp( op, "%/%", 3 ) ) {
            return Rint64::internal::arith_long_long<LONG, Rint64::internal::int_div<LONG> >( e1, e2) ;
        } 
        Rf_error( "unknown operator" ) ;
        return R_NilValue ; 
    }
    } // namespace internal
    
} // namespace Rint64

#endif
