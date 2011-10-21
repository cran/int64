if(require("RUnit", quietly = TRUE)) {
  pkg <- "int64"
                                       
  require( pkg, character.only=TRUE)
  
  path <- system.file("unitTests", package = pkg)
  
  stopifnot(file.exists(path), file.info(path.expand(path))$isdir)
  
  # without this, we get unit test failures
  Sys.setenv( R_TESTS = "" )
  
  int64.unit.test.output.dir <- getwd()
  
  source(file.path(path, "runTests.R"), echo = TRUE)
  
} else {
	print( "package RUnit not available, cannot run unit tests" )
}       

