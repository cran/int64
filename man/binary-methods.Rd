\name{binary-methods}
\docType{methods}
\alias{binary}
\alias{binary-methods}
\alias{binary,integer-method}
\alias{binary,int64-method}
\alias{binary,uint64-method}
\alias{binary,numeric-method}
\title{Get binary representation}
\description{
Get binary representation
}
\section{Methods}{
\describe{

\item{\code{signature(object = "integer")}}{
    Method for integer Vectors
}

\item{\code{signature(object = "int64")}}{
    Method for \code{\linkS4class{int64}} vectors
}
\item{\code{signature(object = "uint64")}}{
    Method for \code{\linkS4class{uint64}} vectors
}

\item{\code{signature(object = "numeric")}}{
    Method for numeric vectors
}
}}
\examples{
    binary( 1:4 )
    binary( c( 1.0, 2.0 ) )
    binary( as.int64( 1:4 ) )
    binary( as.uint64( 1:4 ) )
}
\keyword{methods}

