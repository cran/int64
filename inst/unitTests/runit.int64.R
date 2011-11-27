# Copyright (C) 2011	Romain Francois
# Copyright (C) 2011	Google Inc.  All rights reserved.
#
# This file is part of int64.
#
# int64 is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# int64 is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with int64.  If not, see <http://www.gnu.org/licenses/>.

test.int64 <- function(){
    ints <- c(-122L, 0L, 1L, 122L)
    x <- as.int64(ints)

    checkEquals(
        as.integer(as.character(x)),
        ints
    )
    checkEquals( as.character(x+1L), as.character(ints+1L) )
    checkEquals( as.character(x-1L), as.character(ints-1L) )
    checkEquals( as.character(x*x), as.character(ints*ints) )
    checkEquals( as.character(x/2L), as.character(as.integer(ints/2L)) )

    checkEquals( x > 0L, ints > 0L )
    checkEquals( x < 0L, ints < 0L )
    checkEquals( x == 0L, ints == 0L )
    checkEquals( x != 0L, ints != 0L )
    checkEquals( x <= 0L, ints <= 0L )
    checkEquals( x >= 0L, ints >= 0L )

    checkEquals( range(x), as.int64(c(-122L, 122L)) )
    checkEquals( min(x), as.int64(-122L) )
    checkEquals( max(x), as.int64(122L) )
    checkEquals( prod(x), as.int64(as.integer(prod(ints))) )
    checkEquals( sum(x), as.int64(as.integer(sum(ints))) )
    checkEquals( any(x), any(ints) )
    checkEquals( all(x), all(ints) )

    chars <- c( "-9223372036854775807", "9223372036854775807" )
    x <- as.int64( chars )
    checkEquals( as.character(x), chars )

}

test.uint64 <- function(){
    ints <- c(0L, 1L, 123L)
    x <- as.uint64(ints)

    checkEquals(
        as.integer(as.character(x)),
        ints
    )

    chars <- c( "123456789123456789", "18446744073709551614" )
    x <- as.uint64( chars )
    checkEquals( as.character(x), chars )
}

test.unique.int64 <- function(){
    x <- as.int64( c(1:5, 1L, 3L) )
    checkEquals( unique(x), as.int64(1:5) )
    
    x <- as.uint64( c(1:5, 1L, 3L) )
    checkEquals( unique(x), as.uint64(1:5) )
    
}

test.sort <- function( ){
    x <- as.int64( c(1:4, 3L ) )
    checkEquals( sort( x ), as.int64( c(1:3,3L,4L) ) )
    checkEquals( sort( x, decreasing = TRUE), as.int64( c(4L,3L,3:1) ) )
    
    x <- as.uint64( c(1:4, 3L ) )
    checkEquals( sort( x ), as.uint64( c(1:3,3L,4L) ) )
    checkEquals( sort( x, decreasing = TRUE), as.uint64( c(4L,3L,3:1) ) )
}

test.signif <- function(){
    x <- as.int64( c( "12345", "12345", "12345" ) )
    checkEquals( 
        signif( x, c(2,3,7) ),
        as.int64( c("12000", "12300", "12345") )
        )
        
   x <- as.uint64( c( "12345", "12345", "12345" ) )
   checkEquals( 
       signif( x, c(2,3,7) ),
       as.uint64( c("12000", "12300", "12345") )
       )     
}

test.names <- function(){
    x <- as.int64( 1:5 )
    checkTrue( is.null(names(x) ) )
    names <- letters[1:5]
    names(x) <- names
    checkEquals( names(x), letters[1:5] )
    names(x) <- NULL
    checkTrue( is.null(names(x) ) )
    
    
    x <- as.uint64( 1:5 )
    checkTrue( is.null(names(x) ) )
    names <- letters[1:5]
    names(x) <- names
    checkEquals( names(x), letters[1:5] )
    names(x) <- NULL
    checkTrue( is.null(names(x) ) )
    
}


test.na <- function(){
    old.op <- options( warn = 2 )
    checkException( as.int64( "abcd12434" ) )
    checkException( as.uint64( "abcd12434" ) )
    
    checkEquals( as.int64("1234"), as.int64(1234))
    checkEquals( as.uint64("1234"), as.uint64(1234))
    
    options( old.op )
}

test.dataframe <- function(){
    df <- data.frame( a = 1:4 )
    df$b <- as.int64( 1:4 )
    df$c <- as.uint64( 1:4 )
    
    checkEquals( df$b[3:4], df$b[1:2] + 2L )
    checkEquals( df$c[3:4], df$c[1:2] + 2L )
}

test.read.csv <- function(){
    df <- data.frame( x = 1:10, y = 1:10, z = 1:10 )
    tf <- tempfile()
    write.table( df, tf, row.names = FALSE, sep = "," )
    df <- read.csv( tf, header = TRUE, 
        colClasses = c( "integer", "int64", "uint64" ) )
    
    checkEquals( df$x, 1:10 )
    checkEquals( df$y, as.int64(1:10) )
    checkEquals( df$z, as.uint64(1:10) )
}

