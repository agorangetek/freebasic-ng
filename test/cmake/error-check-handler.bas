'' Regression: -e has to compile where clang is the C compiler, and the error
'' handler still has to be reached.  The C backend emits the jump to the
'' handler as a computed goto.  Clang rejects one in a procedure that takes no
'' label address, and a single unused label as a workaround is worse: it is
'' then the only destination the jump can have, so clang and gcc turn it into a
'' direct branch and ON ERROR GOTO loops forever.  See hEmitResumeLabels() in
'' src/compiler/rtl-error.bas.

declare sub open_existing( )
declare sub open_missing( )

on error goto handler

open_existing( )
open_missing( )

print "the error handler was not reached"
end 1

handler:
print "error handler reached"
end 0

'' Checked statements in a procedure that installs no handler of its own: this
'' is the shape that clang refuses to compile without the resume labels.
sub open_existing( )
	dim as integer f = freefile
	open "error-check-handler.tmp" for output as #f
	print #f, "regression"
	close #f
	kill "error-check-handler.tmp"
end sub

sub open_missing( )
	dim as integer f = freefile
	open "__fb_missing_directory__" + chr( 47 ) + "__fb_missing_file__" for input as #f
	close #f
end sub
