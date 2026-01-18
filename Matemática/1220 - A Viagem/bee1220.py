if __name__ == "__main__":
    while True:
        n = int(input())

        if n == 0:
            break

        avg = 0
        x = []

        for i in range(n):
            val = float(input())
            x.append(int(round(val * 100)))

            avg += x[i]

        avg = avg // n
        avg_high = avg + 1

        taken = 0
        given = 0

        for v in x:
            if v > avg:
                taken += v - avg_high

            elif v < avg:
                given += avg - v

        print("${:.2f}".format(max(taken, given) / 100.00))
