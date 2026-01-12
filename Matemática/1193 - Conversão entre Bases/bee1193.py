def dec_to_bin(n):
    b = ""
    
    while (n > 0):
        b += str(n & 1)
        n = n >> 1
    
    return b[::-1]

def dec_to_hex(n):
    hex_map = "0123456789abcdef"
    h = ""
    
    while (n > 0):
        h += hex_map[n & 0xF]
        n = n >> 4
    
    return h[::-1]

def bin_to_dec(n):
    i = len(n)-1
    decimal = 0
    
    for j in n:
        if (j == '1'):
            decimal += 2**i 
       
        i-=1
        
    return decimal

def hex_to_dec(n):
    dec_map = {
        "0": 0,"1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9,
        "a": 10, "b": 11, "c": 12, "d": 13, "e": 14, "f": 15
    }
    decimal = 0
    
    for h in n:
        if (ord(h) > 64 and ord(h) <= 70):
            h = chr(ord(h)+32)
        
        v = dec_map[h]
        decimal = decimal << 4 
        decimal = decimal | v

    return decimal


if __name__ == "__main__":
    N = int(input())
    
    for z in range(N):
        X, f = input().split()
        print(f"Case {z+1}:")
        
        if (f == "dec"):           
            X = int(X)
            print(f"{dec_to_hex(X)} hex")
            print(f"{dec_to_bin(X)} bin")   
             
        elif (f == "bin"):
            decimal = bin_to_dec(X)
            print(f"{decimal} dec")
            print(f"{dec_to_hex(decimal)} hex")
                
        else:
            decimal = hex_to_dec(X)
            print(f"{decimal} dec")
            print(f"{dec_to_bin(decimal)} bin")
            
        print()