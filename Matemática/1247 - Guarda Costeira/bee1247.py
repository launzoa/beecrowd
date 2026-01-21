import math

if __name__ == "__main__":
    while True:
        try:
            d, v_f, v_p = map(int, input().split())

            if v_f == 0:
                print("S")
                continue

            if v_p == 0:
                print("N")
                continue

            t_f = 12 / v_f
            t_p = math.sqrt(d**2 + 12**2) / v_p

            if t_p <= t_f:
                print("S")
            else:
                print("N")

        except EOFError:
            break
