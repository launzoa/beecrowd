if __name__ == "__main__":
    N = int(input())
    
    for _ in range(0,N):
        C = float(input())
        b = 1; i = 0
        
        while (C > b):
            b*=2
            i+=1
            
        print(i, "dias")
