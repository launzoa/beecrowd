if __name__ == "__main__":
    first = 1
    while True:
        try:
            n = int(input())
            l = 0
            h = 0
            if not (first):
                print()
            first = 0

            if n % 4 == 0 and (n % 400 == 0 or n % 100 != 0):
                print("This is leap year.")
                if n % 55 == 0:
                    if n % 15 == 0:
                        print("This is huluculu festival year.")
                        h = 1

                    print("This is bulukulu festival year.")
                l = 1

            if n % 15 == 0 and not (h):
                print("This is huluculu festival year.")
                l = 1

            if not l:
                print("This is an ordinary year.")

        except EOFError:
            break
