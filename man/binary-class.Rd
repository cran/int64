\name{binary-class}
\Rdversion{1.1}
\docType{class}
\alias{binary-class}
\alias{show,binary-method}

\title{Class \code{"binary"}}
\description{
Binary representation
}
\section{Objects from the Class}{
    Objects can be created by one of the forms of the \code{\link{binary}} methods. 
}
\section{Slots}{
  \describe{
    \item{\code{data}:}{Character vectors, with 0 and 1}
    \item{\code{bits}:}{Number of bits}
  }
}
\section{Methods}{
  \describe{
    \item{show}{\code{signature(object = "binary")}: display method }
	 }
}
\author{
Romain Francois, sponsored by the Google Open Source Programs Office
}
\examples{
binary( 1:4 )
}
\keyword{classes}
