def fibonacci(n, m):
    fi, bo = 0, 1

    print(0, 1, end=" ")
    for i in range(n):
        fi, bo = bo, (fi + bo) % m
        print(bo, end=" ")
    return bo


if __name__ == "__main__":
    while True:
        try:
            n, m = map(int, input().split())
            fibonacci(n, m)
            print()
        except EOFError:
            break
