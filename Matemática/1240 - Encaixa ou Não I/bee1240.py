if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        a, b = input().split()

        l = len(a) - len(b)
        if l < 0:
            print("nao encaixa")
            continue

        j = 0
        flag = 1

        for i in range(l, len(a)):
            if a[i] != b[j]:
                flag = 0
                break

            j += 1

        if flag:
            print("encaixa")
        else:
            print("nao encaixa")
