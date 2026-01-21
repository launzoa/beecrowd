if __name__ == "__main__":
    while True:
        x, y = input().split()

        if x == "0" and y == "0":
            break

        i, j = len(x) - 1, len(y) - 1
        carry = 0
        cont = 0

        while i >= 0 or j >= 0:
            if i < 0 and j >= 0:
                if not carry:
                    break

                s = int(y[j]) + carry
                j -= 1

            elif j < 0 and i >= 0:
                if not carry:
                    break

                s = int(x[i]) + carry
                i -= 1

            else:
                s = int(x[i]) + int(y[j]) + carry
                i -= 1
                j -= 1

            if s > 9:
                carry = 1
                cont += 1
            else:
                carry = 0

        if cont == 0:
            print("No carry operation.")
        elif cont == 1:
            print(f"{cont} carry operation.")
        else:
            print(f"{cont} carry operations.")

