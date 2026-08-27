# beecrowd 1008 - salário
using Printf

function main()
    n = parse(Int, readline())
    h = parse(Int, readline())
    v = parse(Float64, readline())

    println("NUMBER = ", n)
    @printf("SALARY = U\$ %.2f\n", h * v)
end

main()
