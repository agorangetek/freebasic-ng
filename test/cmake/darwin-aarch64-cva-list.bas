function sum_byref(byval count as integer, byref args as cva_list) as integer
    dim copy as cva_list
    dim result as integer = 0

    cva_copy(copy, args)
    for index as integer = 1 to count
        result += cva_arg(copy, integer)
    next
    cva_end(copy)

    function = result
end function

sub verify_list cdecl(byval count as integer, ...)
    dim args as cva_list
    cva_start(args, count)

    if sum_byref(count, args) <> 300 then end 1

    dim byref alias_args as cva_list = args
    if cva_arg(alias_args, integer) <> 100 then end 2
    if cva_arg(alias_args, integer) <> 200 then end 3

    cva_end(args)
end sub

verify_list(2, 100, 200)
print "Darwin AArch64 cva_list regression"
