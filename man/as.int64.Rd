\name{as.int64}
\alias{as.int64}
\title{
    Convert character or integer vectors into int64 vectors. 
}
\description{
    Convert character or integer vectors into \code{\linkS4class{int64}} vectors. 
}
\usage{
as.int64(x)
}
\arguments{
  \item{x}{
A character or integer vector
}
}
\details{
    For conversion of character vectors, the C function \code{atol} is used. 
}
\value{
    A new \code{\linkS4class{int64}} vector. 
}
\references{
    C++ \code{atol} function: \url{http://www.cplusplus.com/reference/clibrary/cstdlib/atol/}
}
\seealso{
    \code{\link{as.uint64}} for conversion to unsigned long vectors.    
}
\author{
Romain Francois, sponsored by the Google Open Source Programs Office
}
\examples{
as.int64( c(1L, 2L ) )
as.int64( c("123456789123456", "987654321987654" ) )
}
\keyword{manip}
