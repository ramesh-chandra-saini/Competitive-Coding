import sys
import math
def getFactor(N):
    factors=[]
    till = math.sqrt(N)
    for i in range(2,int(till)+1):
        if(N%i==0):
            factors.append(i);
            if(i!=N/i):
                factors.append(N/i)
    return factors;
def main():
    N=int(raw_input());
    factors,D=getFactor(N),set()
    for i in factors:
        for j in factors:
            if(N%(i*j)!=0 and (i*j)<N):
                D.add(i*j);
    print len(D)
main()

