def bin_to_dec(x):
    dec = 0
    pisano_period = 1500

    for c in x:
        dec = (dec * 2 + int(c)) % pisano_period

    return dec


def fibonacci(x):
    if x == 0:
        return 0

    if x == 1:
        return 1

    Q = [[1, 1], [1, 0]]
    res = [[1, 0], [0, 1]]

    while x > 0:
        if x % 2 == 1:
            res = matrix_exponentiation(res, Q)

        Q = matrix_exponentiation(Q, Q)
        x = x // 2

    return res[0][1]


def matrix_exponentiation(A, B):
    M = [[0, 0], [0, 0]]
    mod = 1000

    M[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod
    M[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod
    M[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod
    M[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod

    return M


if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        x = bin_to_dec(input())
        fib = fibonacci(x)

        if fib < 10:
            print("00" + str(fib))
        else:
            if fib < 100:
                print("0" + str(fib))
            else:
                print(str(fib))
