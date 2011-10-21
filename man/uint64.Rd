\name{uint64}
\alias{uint64}
\title{
    Creates new uint64 vectors of a given length
}
\description{
    Creates new \code{\linkS4class{uint64}} vectors of a given length
}
\usage{
uint64(length = 0L)
}
\arguments{
  \item{length}{
Length of the resulting vector 
}
}
\value{
    A new \code{\linkS4class{uint64}} vector of the given length
}
\author{
Romain Francois, Sponsored by the Google Open Source Programs Office
}
\seealso{
    \code{\link{as.uint64}} for converting integer or character vectors
    into \code{\linkS4class{uint64}} vectors
}
\examples{
x <- uint64(10L)
}
\keyword{manip}

