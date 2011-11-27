require(int64)
require(tools)
Sweave( "int64.Rnw" )

texi2dvi( "int64.tex", pdf = TRUE, clean = FALSE )
texi2dvi( "int64.tex", pdf = TRUE, clean = FALSE )
