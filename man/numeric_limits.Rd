\name{numeric_limits}
\alias{numeric_limits}
\title{
Give numeric limits of integer types
}
\description{
Give numeric limits of integer types
}
\usage{
numeric_limits(type)
}
\arguments{
  \item{type}{type. must be integer, int64 or uint64. }
}
\value{
A vector of two values of the appropriate type. 
}
\author{
Romain Francois, sponsored by the Google Open Source Programs Office
}
\examples{
numeric_limits( "integer" )
numeric_limits( "int64" )
numeric_limits( "uint64" )
}
\keyword{manip}

