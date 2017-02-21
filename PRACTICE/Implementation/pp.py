def sw(s,pos,c):
    print s,
    s=list(s)
    s[pos]=c
    s=''.join(s)
    print ' -> ',s
    return s
n=int(raw_input())
m=(n-1)*2+1
mid =m/2
ls=[]
p='e'
#print n,m,mid
for i in range(0,n):
    s=''.join(['-' for k in xrange(m)])
    print s
    c=p
    print c,i,n,n-i
    for j in range(0,n-i):
        print m-2*j,m+2*j
        sw(s,m-2*j,c)
        sw(s,m+2*j,c)
        ++c
    ls.append(s)
    --p
print ls
