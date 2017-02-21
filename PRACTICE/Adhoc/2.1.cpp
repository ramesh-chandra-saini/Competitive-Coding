import math
t=int(raw_input())
while t :
    t=t-1
    h,s=raw_input().split()
    h,s=int(h),int(s)
    if(h**4-16*s**2<0):
        print '-1'
    else :
        second=math.sqrt(h**4-16*s**2)
        B=(h**2+second)/2
        B=math.sqrt(B)
        A=(2*s/B)
        print A,' ',B,' ',h
        
