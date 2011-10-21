\name{as.uint64}
\alias{as.uint64}
\title{
    Convert character or integer vectors into uint64 vectors. 
}
\description{
    Convert character or integer vectors into \code{\linkS4class{uint64}} vectors. 
}
\usage{
as.uint64(x)
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
    \code{\link{as.int64}} for conversion to signed long vectors.    
}
\author{
Romain Francois, sponsored by the Google Open Source Programs Office
}
\examples{
as.uint64( c(1L, 2L ) )
as.uint64( c("123456789123456", "987654321987654" ) )
}
\keyword{manip}
