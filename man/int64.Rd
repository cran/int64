\name{int64}
\alias{int64}
\title{
    Creates new int64 vectors of a given length
}
\description{
    Creates new \code{\linkS4class{int64}} vectors of a given length
}
\usage{
int64(length = 0L)
}
\arguments{
  \item{length}{
Length of the resulting vector 
}
}
\value{
    A new \code{\linkS4class{int64}} vector of the given length
}
\author{
Romain Francois, Sponsored by the Google Open Source Programs Office
}
\seealso{
    \code{\link{as.int64}} for converting integer or character vectors
    into \code{\linkS4class{int64}} vectors
}
\examples{
x <- int64(10L)
}
\keyword{manip}

