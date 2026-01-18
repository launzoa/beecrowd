if __name__ == "__main__":
    while (True):
        try:
            n = int(input())
            r = 1 % n
            cont = 1
            
            while (r != 0):
                r = (r * 10 + 1) % n
                cont += 1
                
            print(cont)
            
        except EOFError:
            break