\name{int64-class}
\Rdversion{1.1}
\docType{class}
\alias{int64-class}
\alias{[,int64-method}
\alias{Math,int64-method}
\alias{Math2,int64-method}
\alias{[<-,int64-method}
\alias{Arith,ANY,int64-method}
\alias{Arith,int64,ANY-method}
\alias{Arith,int64,int64-method}
\alias{as.character,int64-method}
\alias{names,int64-method}
\alias{names<-,int64-method}
\alias{Compare,ANY,int64-method}
\alias{Compare,int64,ANY-method}
\alias{Compare,int64,int64-method}
\alias{length,int64-method}
\alias{show,int64-method}
\alias{Summary,int64-method}
\alias{c,int64-method}
\alias{is.na,int64-method}

\title{Class \code{"int64"}}
\description{
Vector of signed 64 bit integers
}
\section{Objects from the Class}{
    Objects can be created by using the \code{\link{int64}} function, 
    by converting character vectors or integer vectors using the
    \code{\link{as.int64}} function. 
}
\section{Slots}{
  \describe{
    \item{\code{.Data}:}{list of integer vectors of length 2. Each 
    int64 number is coded as two integers. }
    \item{\code{NAMES}:}{Used for names of vectors. This is only being 
    used through the \code{names} and \code{names<-} functions. }
  }
}
\section{Extends}{
Class \code{"\linkS4class{list}"}, from data part.
Class \code{"\linkS4class{vector}"}, by class "list", distance 2.
}
\section{Methods}{
  \describe{
    \item{[}{\code{signature(x = "int64")}: ... }
    \item{[<-}{\code{signature(x = "int64")}: ... }
    \item{Arith}{\code{signature(e1 = "ANY", e2 = "int64")}: ... }
    \item{Arith}{\code{signature(e1 = "int64", e2 = "ANY")}: ... }
    \item{Arith}{\code{signature(e1 = "int64", e2 = "int64")}: ... }
    \item{as.character}{\code{signature(x = "int64")}: ... }
    \item{Compare}{\code{signature(e1 = "ANY", e2 = "int64")}: ... }
    \item{Compare}{\code{signature(e1 = "int64", e2 = "ANY")}: ... }
    \item{Compare}{\code{signature(e1 = "int64", e2 = "int64")}: ... }
    \item{length}{\code{signature(x = "int64")}: ... }
    \item{Summary}{\code{signature(x = "int64")}: ... }
    \item{Math}{\code{signature(x = "int64")}: ... }
    \item{Math2}{\code{signature(x = "int64")}: ... }
    \item{c}{\code{signature(x = "int64")}: ... }
    \item{is.na}{\code{signature(x = "int64")}: ... }
	 }
}
\author{
Romain Francois. Sponsored the Google Open Source Programs Office. 
}
\seealso{
    \code{\link{as.int64}} to convert character or integer vectors. 
    
    \code{\link{int64}} to create new \code{\linkS4class{int64}} vectors of a given size.
    
    The \code{\linkS4class{uint64}} class to represent unsigned 64 bit 
    integer vectors. 
}
\examples{
    x <- int64( 4 )
    
    # setting subsets
    x[1:2] <- 1:2
    x[3:4] <- c("123456789012345", "9876543219876")
    x
    
    # arithmetic operations
    x * 2L
    x + x
    x - 3L
    
    # arithmetic operations first convert both operands to 64 bit integer type
    # so some precision will be lost
    as.int64(1) + 1.5
    # but it feels appropriate for dealing with large values
    as.int64(43124567245667) + 1.5
    
    # logical operations
    x < 3L
    x != c( 1L, 2L )
    
    # Summary operations
    range( x )
    min( x )
    max( x )
    length(x)
    
    
    df <- data.frame( a = 1:4 )
    df$b <- x
    df
    
    as.character( x )
    
    
}
\keyword{classes}
