if __name__ == "__main__":
    while (True):
        try :
            x, y = map(int, input().split())
            print(abs(x-y))
        except EOFError:
            break
            