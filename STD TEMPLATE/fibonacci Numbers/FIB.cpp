/**MATRIX METHOD **/
/** O(N)**/
#include<bits/stdc++.h>
using namespace std;

long long int MOD;
long long int multiply(long long int F[][2],long long int M[][2])
{
    long long int x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
    long long int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
    long long int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
    long long int w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
    F[0][0]=x%MOD;F[0][1]=y%MOD; F[1][0]=z%MOD;F[1][1]=w%MOD;


}
long long int POWER(long long int F[][2],long long int N,long long int M[][2])
{
    for(long long i=2;i<=N;i++)
      multiply(F,M);
     return F[0][0];

}
long long int  fib(long long int N)
{
    long long int F[2][2]={{1,1},{1,0}};
     long long int M[2][2]={{1,1},{1,0}};
    if(N==0) return 0;
    else if(N==1) return 1;

    else return POWER(F,N-1,M);

}
int main()
{
  long long int T,N;
  scanf("%lld",&T);

  while(T--){

      scanf("%lld%lld",&N,&MOD);
     printf("%lld\n",(fib(N+2)+MOD-1)%MOD);

  }

  return 0;
}
