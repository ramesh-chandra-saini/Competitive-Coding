import sys

T = int(raw_input())
while(T):
    T-=1
    N,M,P,K = map(int,raw_input().split(' '))
    hvGame   =  not (N%2==1 and M%2==1) #?False:True;
    diagGame =  (N%2==0 and M%2==0)#?True:False;
    if(hvGame == True and diagGame == True):
        if (P==0) :
            print("1\n")
        else :
            print("1\n")
    elif(hvGame == False and diagGame == False):
        if (P==0) :
            print("1\n")
        else :
            print("0\n")
    else :
        fans = 1.0
        for _ in range(0,K):
            fans*=0.5
        ans ,prev = fans,fans
        if(P==0):
            ans = 0
        A,B=K*1.0,1.0;
        for i in range(1,P-1+1):
            prev = (prev/B)*A
            ans+=prev
            A,B=A-1,B+1
        print (1.0-ans)
