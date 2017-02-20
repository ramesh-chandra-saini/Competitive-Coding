#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int main(){


    long long int T,N;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&N);
        N%=M;
        long long int  p=( (N*N)%M + N )%M;
        long long int  q=( p + 1 ) %M;
        p=(p*q)%M;
        printf("%lld\n",p);
    }
    return 0;
}
