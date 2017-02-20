#include<bits/stdc++.h>
using namespace std;
#define lll long long int
#define __M 1000000007
lll ans = 0LL;
void  multiply(long long int F[][2],long long int M[][2]){
    long long int x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
    long long int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
    long long int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
    long long int w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
    F[0][0]=x%__M;F[0][1]=y%__M; F[1][0]=z%__M;F[1][1]=w%__M;
}
void  POWER(long long int F[][2],long long int N,long long int M[][2]){
    if(N==0|| N==1) return;
    POWER(F,N/2,M);
    multiply(F,F);
    if(N%2){
       long long int M[2][2]={{1,1},{1,0}};
        multiply(F,M);
    }
}
long long int  fib(long long int N){
    long long int F[2][2]={{1,1},{1,0}};
     long long int M[2][2]={{1,1},{1,0}};
    if(N==0) return 0;
    else if(N==1) return 1;
    else  POWER(F,N-1,M);
    return F[0][0];
}
void foo(lll array[], lll start, lll end, lll sum) {
    if(end == start) return ;
    lll val = sum + array[start];
  // printf("%lld,",val);
   ans = (ans+fib(val) ) %__M;
    foo(array, start + 1,end, val); //use the number
    foo(array, start + 1,end, sum); //don't use the number
}
int main(){
    lll n,Q; scanf("%lld%lld",&n,&Q);
    lll arr[n]; for(lll i=0;i<n;i++) scanf("%lld",&arr[i]);
    char c; lll x,y;
    while(Q--){
        cin >> c >> x >> y;
        if(c=='Q'){
            ans=0LL;foo(arr,x-1,y,0);
            printf("%lld\n",ans);
        } else arr[x-1] = y;
    }

    return 0;
}
