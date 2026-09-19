'' Regression: -dylib has to produce a shared library the runtime can load
'' back under the name it chose for it.  Darwin names it lib<name>.dylib and
'' links it with -dynamiclib and -install_name; .so and the GNU linker
'' spellings do not apply there.

type ANSWER_FUNCTION as function cdecl ( ) as integer

dim as any ptr library = dylibload( "dylib-testlib" )
if library = 0 then
	print "dylibload failed"
	end 1
end if

dim as ANSWER_FUNCTION answer = dylibsymbol( library, "fb_regression_answer" )
if answer = 0 then
	print "dylibsymbol failed"
	end 2
end if

if answer( ) <> 42 then
	print "wrong result from the loaded library"
	end 3
end if

dylibfree( library )
print "dylib load regression"
end 0
