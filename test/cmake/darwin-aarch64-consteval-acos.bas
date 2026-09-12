function runtime_acos(byval value as single) as single
    function = acos(value)
end function

const folded as single = acos(-1.0f)
dim value as single = -1.0f

if folded <> runtime_acos(value) then end 1
print "Darwin AArch64 acosf constant-evaluation regression"
