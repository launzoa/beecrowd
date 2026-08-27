# Beecrowd 1006 - Média 2

function main()
    a = parse(Float64, readline())
    b = parse(Float64, readline())
    c = parse(Float64, readline())

    mean = (a*0.2) + (b*0.3) + (c*0.5)

    println("MEDIA = ", round(mean, digits=1))
end

main()
