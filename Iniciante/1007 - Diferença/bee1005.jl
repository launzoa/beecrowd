using Printf
a = parse(Float64, readline())
b = parse(Float64, readline())
c = (a*3.5 + b*7.5) / 11.0
@printf("MEDIA = %.5f\n", c)
