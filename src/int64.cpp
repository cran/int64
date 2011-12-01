// int64.cpp: int64 64 bit integers
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

#define BUILDING_INT64

#include <int64.h>
#include <limits>

namespace Rint64{
    
    namespace internal{
  
        bool int64_naflag = false ;
        
        SEXP int64_format_binary__standard(SEXP x){
            int n = Rf_length(x) ;
            SEXP res = PROTECT( Rf_allocVector( STRSXP, n ) ) ;
            
            switch( TYPEOF(x) ){ 
            case INTSXP:
                {
                    int* data = INTEGER(x) ;
                    for( int i=0; i<n; i++){
                        SET_STRING_ELT( res, i, Rf_mkChar( Rint64::internal::format_binary__impl<int>( data[i] ) ) ) ;
                    }
                    break ;
                }
            case REALSXP:
                {
                    double* p_x = REAL(x) ;
                    for( int i=0; i<n; i++){
                        SET_STRING_ELT( res, i, Rf_mkChar( Rint64::internal::format_binary__impl<double>( p_x[i] ) ) );
                    }      
                    break ;
                }
            default:
                Rf_error( "incompatible type" ) ;
            }
            UNPROTECT(1) ; // res ;
            return res ;
        }
        
    }
}


extern "C" SEXP int64_format_binary(SEXP x){
    if( Rf_inherits( x, "int64" ) ){
        return Rint64::internal::int64_format_binary_long<int64_t>(x) ;
    } else if( Rf_inherits( x, "uint64" ) ){
        return Rint64::internal::int64_format_binary_long<uint64_t>(x) ;
    } else {
        return Rint64::internal::int64_format_binary__standard(x);
    }
    return R_NilValue ;
}

extern "C" SEXP int64_as_character_int64(SEXP x, SEXP unsign){
    bool is_unsigned = INTEGER(unsign)[0] ;
    if( is_unsigned ){
        return Rint64::internal::int64_as_character<uint64_t>( x ) ;
    } else {
        return Rint64::internal::int64_as_character<int64_t>( x ) ;
    }
}


extern "C" SEXP int64_as_int64(SEXP x){
    return Rint64::internal::as_long<int64_t>(x) ;
}
extern "C" SEXP int64_as_uint64(SEXP x){
    return Rint64::internal::as_long<uint64_t>(x) ;
}

extern "C" SEXP int64_arith_int64_int64(SEXP generic, SEXP e1, SEXP e2, SEXP unsign ) {
    const char* op = CHAR(STRING_ELT(generic, 0)) ;
    bool is_unsigned = INTEGER(unsign)[0] ;
    
    if( is_unsigned ){
        return Rint64::internal::int64_arith__impl<uint64_t>(op, e1, e2 ) ;
    } else {
        return Rint64::internal::int64_arith__impl<int64_t>(op, e1, e2 ) ;
    }
}

extern "C" SEXP int64_compare_int64_int64(SEXP generic, SEXP e1, SEXP e2, SEXP unsign) {
    const char* op = CHAR(STRING_ELT(generic, 0)) ;
    bool is_unsigned = INTEGER(unsign)[0]; 
    if( is_unsigned ){
        return Rint64::internal::int64_compare<uint64_t>(op,e1,e2) ;
    } else {
        return Rint64::internal::int64_compare<int64_t>(op,e1,e2) ;
    }
}

extern "C" SEXP int64_summary_int64(SEXP generic, SEXP x, SEXP unsign){
    const char* op = CHAR(STRING_ELT(generic, 0)) ;
    bool is_unsigned = INTEGER(unsign)[0] ;
    if( is_unsigned ){
        return Rint64::internal::int64_summary<uint64_t>(op, x ) ;
    } else {
        return Rint64::internal::int64_summary<int64_t>(op, x ) ;
    }                                 
}

extern "C" SEXP int64_limits( SEXP type_ ){
    const char* type = CHAR(STRING_ELT(type_, 0) ) ;
    
    if( !strncmp( type, "integer", 7 ) ){                                      
        SEXP res = PROTECT( Rf_allocVector(INTSXP, 2 ) ) ;
        INTEGER(res)[0] = std::numeric_limits<int>::min() + 1 ;
        INTEGER(res)[1] = std::numeric_limits<int>::max() ;
        UNPROTECT(1) ;
        return res ;
    } else if( ! strncmp( type, "int64", 5 ) ){
        return Rint64::internal::new_long_2<int64_t>( 
            Rint64::internal::long_traits<int64_t>::min() , 
            Rint64::internal::long_traits<int64_t>::max() 
            ) ;
    } else if( !strncmp( type, "uint64", 6 ) ){
        return Rint64::internal::new_long_2<uint64_t>( 
            Rint64::internal::long_traits<uint64_t>::min(), 
            Rint64::internal::long_traits<uint64_t>::max()
            ) ;                                    
    }
    
    
    Rf_error( "unsupported type" ) ;
    return R_NilValue ;
}

extern "C" SEXP int64_sort( SEXP x, SEXP unsign, SEXP decr ){
    bool is_unsigned = INTEGER(unsign)[0] ;
    bool decreasing = INTEGER(decr)[0] ;
    
    if( is_unsigned ){
        return Rint64::LongVector<uint64_t>(x).sort(decreasing ) ;   
    } else {
        return Rint64::LongVector<int64_t>(x).sort(decreasing ) ;
    }
}

extern "C" SEXP int64_math( SEXP generic, SEXP x, SEXP unsign){
    bool is_unsigned = INTEGER(unsign)[0]; 
    const char* op = CHAR(STRING_ELT(generic, 0 ) ); 
    
    if( is_unsigned ){
        return Rint64::internal::math<uint64_t>( op, x ) ;   
    } else {
        return Rint64::internal::math<int64_t>( op, x ) ;
    }   
}

extern "C" SEXP int64_signif( SEXP s_, SEXP digits_, SEXP len_){
    std::string s ;
    int n = Rf_length(s_) ;
    int* digits = INTEGER(digits_) ;
    int* len = INTEGER(len_) ;
    
    SEXP res = PROTECT( Rf_allocVector( STRSXP, n ) ) ;
    for( int i=0; i<n; i++){
        if( !strncmp( CHAR(STRING_ELT(s_, i)), "NA", 2 ) || digits[i] > len[i] ){
            SET_STRING_ELT( res, i, STRING_ELT( s_, i ) ) ;    
        } else {
            s = CHAR(STRING_ELT(s_, i ));
            for( int j=digits[i]; j<len[i]; j++){
                s[j] = '0' ;
            }
            SET_STRING_ELT( res, i, Rf_mkChar(s.c_str()) ) ;
        }
    }
    UNPROTECT(1) ;
    return res ; 
}
  
extern "C" SEXP int64_isna( SEXP x_, SEXP unsign ){
    bool is_unsigned = INTEGER(unsign)[0] ;
    if( is_unsigned ){
        return Rint64::LongVector<uint64_t>( x_ ).is_na() ;    
    } else {
        return Rint64::LongVector<int64_t>( x_ ).is_na() ;
    }
}

