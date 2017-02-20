import sys

def _gcd(a, b):
    if b == 0:
        return a
    else:
        return _gcd(b, a%b)


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)


def main():

    t, b, w = map(int, input().split())
    #print ("%d"%gcd(10,4))
    #print ("%d"%gcd(b,w))

    #__b=int( (b)/gcd(b,w))
    #__b*=w
    
    x = int(t/b);x=int (x/w); x=int(x*gcd(b,w))
    
    #print("%d"% x)
    z = int(min(b, w))

    #print("%d"% z)
    y = int(x*z+min(b-1,min(w-1,t)))
    #print("%d,%d"% (t,y))
    
    a=int(_gcd(int(t),int(y)))
    #print("%d"%a)
    y=int(y/a)
    #print("%d"%y)
    t = int(t/a)
    #print("%d"%t)
    print("%d/%d"%(y,t))

if __name__ == '__main__':
    main()
