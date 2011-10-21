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

#ifndef int64_LongVector_h
#define int64_LongVector_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

namespace Rint64{
    
    template <class LONG>
    class LongVector : public internal::long_traits<LONG> {
    private :
        SEXP data ;
        
    public:
        
        LongVector(SEXP x) : data(x) {
            if( Rf_inherits( x, internal::get_class<LONG>().c_str() ) ){
                data = x ;
                R_PreserveObject(data) ;
            } else {
                switch( TYPEOF(x) ){
                    case INTSXP:
                        {
                            int n = Rf_length(x) ;
                            SEXP y = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
                            int hb, lb ;
                            LONG tmp ;
                            int* p_i_x = INTEGER(x) ;
                            for( int i=0; i<n; i++){
                                if( p_i_x[i] == NA_INTEGER){                   
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(
                                        na_hb() , na_lb()    
                                    ) ) ;
                                } else {
                                    tmp = (LONG) p_i_x[i] ;
                                    hb = internal::get_high_bits<LONG>(tmp) ;
                                    lb = internal::get_low_bits<LONG>(tmp) ;
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(hb,lb) ) ;
                                }
                            }
                            UNPROTECT(1) ; // y
                            data = y ;
                            R_PreserveObject(data) ;  
                            break ;
                        }
                    case LGLSXP:
                        {
                           int n = Rf_length(x) ;
                            SEXP y = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
                            int hb, lb ;
                            LONG tmp ;
                            int* p_i_x = INTEGER(x) ;
                            for( int i=0; i<n; i++){
                                if( p_i_x[i] == NA_INTEGER){                   
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(
                                        na_hb(), na_lb()    
                                    ) ) ;
                                } else {
                                    tmp = (LONG) p_i_x[i] ;
                                    hb = internal::get_high_bits<LONG>(tmp) ;
                                    lb = internal::get_low_bits<LONG>(tmp) ;
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(hb,lb) ) ;
                                }
                            }
                            UNPROTECT(1) ; // y
                            data = y ;
                            R_PreserveObject(data) ;  
                            break ;
                         }
                    case REALSXP: 
                        {
                            int n = Rf_length(x) ;
                            SEXP y = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
                            int hb, lb ;
                            LONG tmp ;
                            double* p_d_x = REAL(x) ;
                            for( int i=0; i<n; i++){
                                if( R_IsNA(p_d_x[i]) ){
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(
                                        na_hb(), na_lb()    
                                    ) ) ;
                                } else {
                                    tmp = (LONG) p_d_x[i] ;
                                    hb = internal::get_high_bits<LONG>(tmp) ;
                                    lb = internal::get_low_bits<LONG>(tmp) ;
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(hb,lb) ) ;
                                }
                            }
                            UNPROTECT(1) ; // y
                            data = y ;
                            R_PreserveObject(data) ;  
                            break ;  
                        }
                    case STRSXP:
                        {
                            int n = Rf_length(x) ;
                            Rint64::internal::int64_naflag = false ;
                            SEXP y = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
                            int hb, lb ;
                            LONG tmp ;
                            for( int i=0; i<n; i++){
                                if( !strncmp("NA", CHAR(STRING_ELT(x,i)) , 2) ){
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(
                                        na_hb(), na_lb()    
                                    ) ) ;
                                } else{ 
                                    tmp = internal::read_string<LONG>( CHAR(STRING_ELT(x,i)) ) ;
                                    hb = internal::get_high_bits<LONG>(tmp) ;
                                    lb = internal::get_low_bits<LONG>(tmp) ;
                                    SET_VECTOR_ELT( y, i, Rint64::internal::int2(hb,lb) ) ;
                                }
                            }
                            UNPROTECT(1) ; // y
                            data = y ;
                            R_PreserveObject(data) ;  
                            if( Rint64::internal::int64_naflag ) {
                                Rf_warning( "NA introduced by overflow" ) ;
                            }
                            break ;        
                        }
                    default:
                        {
                            Rf_error( "unimplemented conversion" ) ;   
                        }
                }
            }
        }
        
        operator SEXP(){
            std::string klass = Rint64::internal::get_class<LONG>() ;
            SEXP res = PROTECT( 
                R_do_slot_assign( 
                    R_do_new_object( R_do_MAKE_CLASS( klass.c_str() ) ), 
                    Rf_install(".Data"), 
                    data ) ) ;
            UNPROTECT(1) ;
            return res ;    
        }
        
        LongVector(int n) : data(R_NilValue) {
            SEXP x = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
            for( int i=0; i<n; i++){
                SET_VECTOR_ELT( x, i, Rint64::internal::int2(0,0) ) ;    
            }
            UNPROTECT(1) ; // x
            data = x ;
            R_PreserveObject(data) ;
        }
        
        LongVector(int n, LONG value) : data(R_NilValue) {
            SEXP x = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
            int hb = internal::get_high_bits<LONG>( value ) ;
            int lb = internal::get_low_bits<LONG>( value ) ;
            for( int i=0; i<n; i++){
                SET_VECTOR_ELT( x, i, Rint64::internal::int2(hb,lb) ) ;    
            }
            UNPROTECT(1) ; // x
            data = x ;
            R_PreserveObject(data) ;
        }
        
        template <typename ITERATOR>
        LongVector(int n, ITERATOR start, ITERATOR end) : data(R_NilValue) {
            SEXP x = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
            int hb, lb ;
            for( int i=0; i<n; i++, ++start){
                hb = Rint64::internal::get_high_bits<LONG>(*start) ;
                lb = Rint64::internal::get_low_bits<LONG>(*start) ;
                SET_VECTOR_ELT( x, i, Rint64::internal::int2(hb,lb) ) ;    
            }
            UNPROTECT(1) ; // x
            data = x ;
            R_PreserveObject(data) ;
        }
        
        
        ~LongVector(){
            R_ReleaseObject(data) ;   
        }
        
        inline LONG get(int i) const {
            int* p = INTEGER(VECTOR_ELT(data,i)) ;
            return Rint64::internal::get_long<LONG>( p[0], p[1] ) ;
        }
        
        inline void set(int i, LONG x){
            int* p = INTEGER(VECTOR_ELT(data,i)) ;
            p[0] = Rint64::internal::get_high_bits(x) ;
            p[1] = Rint64::internal::get_low_bits(x) ;
        }
        
        inline int size() const { return Rf_length(data); }
        
        LongVector<LONG> sort(bool decreasing) const {
            int n = size() ;
            std::vector<LONG> x( n ) ;
            for( int i=0; i<n; i++){
                x[i] = get(i) ;
            }
            if( decreasing ){
                std::sort( x.begin(), x.end(), std::greater<LONG>() ) ;
            } else {
                std::sort( x.begin(), x.end() ) ;
            }
            return LongVector<LONG>( n, x.begin(), x.end() ) ;
        }
                      
        SEXP is_na(){
            int n = size() ;
            SEXP res = PROTECT( Rf_allocVector(LGLSXP,n)) ;
            int* p ;
            int* p_res = INTEGER(res) ;
            for( int i=0; i<n; i++){
                p = INTEGER(VECTOR_ELT(data, i)) ;
                p_res[i] = p[0] == na_hb() && p[1] == na_lb() ;
            }
            UNPROTECT(1) ; // res
            return res; 
        }
        
        inline int na_lb(){ return internal::long_traits<LONG>::na_lb(); }
        inline int na_hb(){ return internal::long_traits<LONG>::na_hb(); }
        
        
    } ;

}


#endif
