\name{unique-methods}
\docType{methods}
\alias{unique-methods}
\alias{unique,ANY-method}
\alias{unique,int64-method}
\alias{unique,uint64-method}
\title{Unique implementation for 64 bit integer vectors}
\description{
    Implementation of \code{\link{unique}} for 64 bit integer vectors 
}
\section{Methods}{
\describe{

\item{\code{signature(x = "ANY")}}{default implementation (from base)}

\item{\code{signature(x = "int64")}}{
    signed 64 bit integer vectors. \code{\linkS4class{int64}}
}

\item{\code{signature(x = "uint64")}}{
    unsigned 64 bit integer vectors. \code{\linkS4class{uint64}}
}
}}
\keyword{methods}
\examples{
    x <- as.int64( c(1:5, 1L, 5L) )
    unique( x )

    x <- as.uint64( c(1:5, 1L, 5L) )
    unique( x )    
}

