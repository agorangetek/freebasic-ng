'' Regression: the DATA descriptor layout must stay linkable and readable.
'' Darwin uses the naturally aligned layout because ld64 rejects a pointer
'' relocation at an offset that is not pointer-aligned, a fatal error on arm64;
'' every other target keeps the packed layout.  Compiler and runtime have to
'' agree either way, see hCreateDataDesc() in src/compiler/ast-node-data.bas
'' and FB_DATADESC_PACKED in src/rtlib/fb_data.h.

dim as integer number
dim as string text
dim as double value

restore numbers
read number
if number <> 11 then end 1
read number
if number <> 22 then end 2
read number
if number <> 33 then end 3

restore words
read text
if text <> "alpha" then end 4
read text
if text <> "beta" then end 5

restore reals
read value
if value <> 0.5 then end 6

print "DATA descriptor regression"
end 0

numbers:
data 11, 22, 33

words:
data "alpha", "beta"

reals:
data 0.5
