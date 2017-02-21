def next(turn):
    if(turn == 2):
        turn = 1
    elif turn == 1 :
        turn = 2
    return turn   
def solve(n,curr,turn,m,arr):
    #print "curr : ",curr,"turn : ",turn
    for i in range(0,m):
        if(curr*arr[i]==n):
            return next(turn)
        if(curr*arr[i]<n):
            if next(turn)==solve(n,curr*arr[i],next(turn),m,arr) :
                return next(turn)
    return turn
def main():
    n,m=map(int,raw_input().split())
    arr,N=map(int,raw_input().split()),n
    for i in arr:
        while(N%i==0):
            N/=i
    turn1=solve(n,N,1,m,arr)
    turn2=solve(n,N,2,m,arr)
    if next(turn1)!=1 && next(turn2)!=1:
        
    
    
    
    
    #turn=toggle(turn)#every one is playing optimally
    #print turn
    if turn == 1:
        print "Second"
    else:
        print "First"       
if __name__ == "__main__":
    main()

