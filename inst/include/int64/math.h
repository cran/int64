// math.h : 64 bit integers
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
    
#ifndef int64__math__h
#define int64__math__h

namespace Rint64{
    namespace internal{
      
template <typename LONG>
SEXP abs( SEXP x ){
    const LONG na = long_traits<LONG>::na() ;
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    LONG tmp ;
    Rint64::LongVector<LONG> res(n) ;
    for( int i=0; i<n; i++){
        tmp = data.get(i) ;
        if( tmp == na ) res.set(i, na ) ;
        res.set( i, tmp > 0 ? tmp : -tmp ) ;            
    }
    return res ;    
}
template <>
inline SEXP abs<uint64_t>( SEXP x ){ return x ; }
     
template <typename LONG>
SEXP sign( SEXP x){
    const LONG na = long_traits<LONG>::na() ;
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    LONG tmp ;
    SEXP res = PROTECT(Rf_allocVector(REALSXP,n)) ;
    double* p_res = REAL(res) ;
    for( int i=0; i<n; i++){
        tmp = data.get(i) ;
        if( tmp == na ) {
            p_res[i] = NA_REAL ;
        } else {
            p_res[i] = ( data.get(i) > 0 ) ? 0.0 : 1.0 ;
        }
    }
    UNPROTECT(1) ;
    return res ;    
}

template <typename LONG>
SEXP cummax( SEXP x){
    const LONG na = long_traits<LONG>::na() ;
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    Rint64::LongVector<LONG> res(n, na) ;
    LONG max = data.get(0) ;
    res.set( 0, max) ;
    LONG tmp = 0 ;
    
    for( int i=1; i<n; i++){
        tmp = data.get(i) ;
        if( tmp == na ) break ;
        if( tmp > max ) max=tmp ;
        res.set( i, max ) ;
    }
    return res ;
}

template <typename LONG>
SEXP cummin( SEXP x){
    const LONG na = long_traits<LONG>::na() ;
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    Rint64::LongVector<LONG> res(n, na) ;
    LONG max = data.get(0) ;
    res.set( 0, max) ;
    LONG tmp = 0 ;
    
    for( int i=1; i<n; i++){
        tmp = data.get(i) ;
        if( tmp == na ) break ;
        if( tmp < max ) max=tmp ;
        res.set( i, max ) ;
    }
    return res ;
}

template <typename LONG>
SEXP cumprod( SEXP x){
    const LONG na = long_traits<LONG>::na() ;
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    Rint64::LongVector<LONG> res(n, na) ;
    LONG prod = data.get(0) ;
    res.set( 0, prod) ;
    int64_naflag = false ;
    for( int i=1; i<n; i++){
        prod = times<LONG>( prod, data.get(i) );
        if( prod == na ) break ;
        res.set( i, prod ) ;
    }
    if( int64_naflag ) {
        Rf_warning( "NA introduced by overflow" ) ;  
    }
    return res ;
}

template <typename LONG>
SEXP cumsum( SEXP x){
    const LONG na = long_traits<LONG>::na() ;
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    Rint64::LongVector<LONG> res(x) ;
    LONG prod = data.get(0) ;
    res.set( 0, prod) ;
    int64_naflag = false ;
    
    for( int i=1; i<n; i++){
        prod = plus<LONG>( prod, data.get(i) );
        if( prod == na ) break ;
        res.set( i, prod ) ;
    }
    if( int64_naflag ) {
        Rf_warning( "NA introduced by overflow" )  ; 
    }
    return res ;
}

template <typename LONG>
SEXP int64_log10( SEXP x ){
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    const LONG na = long_traits<LONG>::na() ;
    SEXP res = PROTECT( Rf_allocVector( REALSXP, n ) ) ;
    double* p_res = REAL(res) ;
    LONG tmp; 
    for(int i=0; i<n; i++){
        tmp = data.get(i) ;
        if( tmp == na ) {
            p_res[i] = NA_REAL;
        } else if( tmp < 1){
            p_res[i] = R_NaN ;
        } else {
            p_res[i] = (double) log10( (long double)data.get(i) ) ;   
        }
    }
    UNPROTECT(1) ; // res
    return res ;
}

template <typename LONG>
SEXP int64_log( SEXP x ){
    Rint64::LongVector<LONG> data(x) ;
    int n = data.size() ;
    const LONG na = long_traits<LONG>::na() ;
    SEXP res = PROTECT( Rf_allocVector( REALSXP, n ) ) ;
    double* p_res = REAL(res) ;
    LONG tmp; 
    for(int i=0; i<n; i++){
        tmp = data.get(i) ;
        if( tmp == na ) {
            p_res[i] = NA_REAL;
        } else if( tmp <= 0 ){
            p_res[i] = R_NaN ;
        } else {
            p_res[i] = (double) log( (long double)data.get(i) ) ;   
        }
    }
    UNPROTECT(1) ; // res
    return res ;
}



template <typename LONG>
SEXP math( const char* op, SEXP x ){
    
    if( !strncmp( op, "abs", 3 ) ){
        return abs<LONG>(x) ;
    } else if( !strncmp(op, "sign", 4) ) {
        return sign<LONG>(x) ;
    } else if( !strncmp( op, "trunc", 5 ) ){
        return x ;
    } else if( !strncmp( op, "floor", 5) ){
        return x ;   
    } else if( !strncmp( op, "cummax", 6 ) ){
        return cummax<LONG>( x ) ;
    } else if( !strncmp( op, "cummin", 6 ) ){
        return cummin<LONG>( x ) ;
    } else if( !strncmp( op, "cumprod", 7 ) ){
        return cumprod<LONG>( x ) ;
    } else if( !strncmp( op, "cumsum", 6 ) ){
        return cumsum<LONG>( x ) ;   
    } else if( !strncmp( op, "log10", 5 ) ){
        return int64_log10<LONG>( x ) ;   
    } else if( !strncmp( op, "log", 3 ) ){
        return int64_log<LONG>( x) ;   
    }
    
    Rf_error( "generic not implemented" );
    return R_NilValue ;
}

    } // namespace internal
    
} // namespace Rint64

#endif
