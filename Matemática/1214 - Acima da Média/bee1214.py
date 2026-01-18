if __name__ == "__main__":
    c = int(input())

    for _ in range(c):
        n, *means = map(int, input().split())
        mean = 0

        for i in range(0, n):
            mean += means[i]

        mean /= n
        cont = 0

        for i in range(0, n):
            if means[i] > mean:
                cont += 1

        print("{:.3f}%".format((cont / n) * 100))
