import sys

while(True):
    try:           
        Ev1,Ev2,AT,D = map(int, input().split())
        
        if(Ev1 == 0 and Ev2 == 0 and AT == 0 and D == 0): 
            break 
    
        if(D != 1): 
            if(Ev1%D == 0):
                Ev1 = int(Ev1/D)
            else: 
                Ev1 = int(Ev1/D) + 1
                
            if(Ev2%D == 0):
                Ev2 = int(Ev2/D)
            else:
                Ev2 = int(Ev2/D) + 1

        p = (AT/6); q = 1 - p 
        N = Ev1 + Ev2
    
        if(p == q):
            sol = Ev1/N
            print("{:.1f}".format(sol*100))

        else: 
            sol = (1-(q/p)**Ev1)/(1-(q/p)**N)
            print("{:.1f}".format(sol*100))
    
    except ValueError:
        break