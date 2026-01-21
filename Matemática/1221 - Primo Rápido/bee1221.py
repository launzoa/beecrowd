import math


def isPrime(x):
    for i in range(2, int(math.sqrt(x) + 1)):
        if (x % i) == 0:
            return 0
    return 1


if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        x = isPrime(int(input()))

        if x:
            print("Prime")
        else:
            print("Not Prime")
