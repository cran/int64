\name{uint64-class}
\Rdversion{1.1}
\docType{class}
\alias{uint64-class}
\alias{Math,uint64-method}
\alias{Math2,uint64-method}
\alias{[,uint64-method}
\alias{[<-,uint64-method}
\alias{Arith,ANY,uint64-method}
\alias{Arith,uint64,ANY-method}
\alias{Arith,uint64,uint64-method}
\alias{as.character,uint64-method}
\alias{names,uint64-method}
\alias{names<-,uint64-method}
\alias{Compare,ANY,uint64-method}
\alias{Compare,uint64,ANY-method}
\alias{Compare,uint64,uint64-method}
\alias{length,uint64-method}
\alias{show,uint64-method}
\alias{Summary,uint64-method}
\alias{c,uint64-method}
\alias{is.na,uint64-method}

\title{Class \code{"uint64"}}
\description{
Vector of signed 64 bit integers
}
\section{Objects from the Class}{
    Objects can be created by using the \code{\link{uint64}} function, 
    by converting character vectors or integer vectors using the
    \code{\link{as.uint64}} function. 
}
\section{Slots}{
  \describe{
    \item{\code{.Data}:}{list of integer vectors of length 2. Each 
    uint64 number is coded as two integers. }
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
    \item{[}{\code{signature(x = "uint64")}: ... }
    \item{[<-}{\code{signature(x = "uint64")}: ... }
    \item{Arith}{\code{signature(e1 = "ANY", e2 = "uint64")}: ... }
    \item{Arith}{\code{signature(e1 = "uint64", e2 = "ANY")}: ... }
    \item{Arith}{\code{signature(e1 = "uint64", e2 = "uint64")}: ... }
    \item{as.character}{\code{signature(x = "uint64")}: ... }
    \item{Compare}{\code{signature(e1 = "ANY", e2 = "uint64")}: ... }
    \item{Compare}{\code{signature(e1 = "uint64", e2 = "ANY")}: ... }
    \item{Compare}{\code{signature(e1 = "uint64", e2 = "uint64")}: ... }
    \item{length}{\code{signature(x = "uint64")}: ... }
    \item{Summary}{\code{signature(x = "uint64")}: ... }
    \item{Math}{\code{signature(x = "uint64")}: ... }
    \item{Math2}{\code{signature(x = "uint64")}: ... }
    \item{c}{\code{signature(x = "uint64")}: ... }
    \item{is.na}{\code{signature(x = "uint64")}: ... }
	 }
}
\author{
Romain Francois. Sponsored the Google Open Source Programs Office. 
}
\seealso{
    \code{\link{as.uint64}} to convert character or integer vectors. 
    
    \code{\link{uint64}} to create new \code{\linkS4class{uint64}} vectors of a given size.
    
    The \code{\linkS4class{int64}} class to represent signed 64 bit 
    integer vectors.
}
\examples{
    x <- uint64( 4 )
    
    # setting subsets
    x[1:2] <- 1:2
    x[3:4] <- c("123456789012345", "9876543219876")
    x
    
    # arithmetic operations
    x * 2L
    x + x
    x - 3L
    
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
