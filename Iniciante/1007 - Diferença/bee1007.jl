# Beecrowd 1007 - Diferença

function main()
    A = parse(Float64, readline())
    B = parse(Float64, readline())
    C = parse(Float64, readline())
    D = parse(Float64, readline())

    DIFF = (A*B) - (C*D)
    println("DIFERENCA = ", trunc(Int, DIFF))

end

main()
