/*

    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
    07 FEB 2016

    CONCEPT USED
    (a/b)%MOD=( (a%MOD)*POW(B,MOD-2) )% MOD;
    REPEATED SQUARING TECHNIQUE
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int POWER(long long int N,long long int expo){

    long long int ans=1LL;
    N%=MOD;
    while(expo){
        if(expo & 1)
            ans=(ans*N)%MOD;
        N=(N*N)%MOD,expo>>=1;
    }
    return ans;
}

int main(){


    long long int T,N,x,M;
    scanf("%lld",&T);
    while(T--){

        scanf("%lld%lld%lld",&N,&x,&M);

        long long int arr[N];
        for(long long int i=0;i<N;i++)
            scanf("%lld",&arr[i]);

        //To get number of times any term added to final ans = upperFraction/lowerFraction
        long long int upperFraction=1LL;
        long long int lowerFraction=1LL;
/*
        //calculate upperFraction

        for(long long int i=0;i<M-1;i++)
            upperFraction=(upperFraction*(1+i))%M;

        //calculate LowerFraction

        for(long long int i=1;i<M;i++)
            lowerFraction=(lowerFraction*i)%MOD;
*/
        //just to be safe from overFlow
        for(int i=0;i<N;i++)
            arr[i]%=MOD;
        M%=MOD;
        //CALCULATE MY DESIRED ANSWER
        long long int ans=( ((arr[--x] *  upperFraction ) %MOD )*POWER(lowerFraction,MOD-2)  ) % MOD ;

        for(long long int ex=1,i=0;--x>=0;ex++,i++){

            upperFraction=(upperFraction*(M+ i) )%MOD;
            lowerFraction=(ex*lowerFraction)%MOD;
            ans=(ans+ ((arr[x] *  upperFraction ) %MOD) * POWER(lowerFraction,MOD-2)  ) % MOD;
        }
        // COMPLEXITY = O( N + M + M + N + X);

        //FINALLY GOT AN ANSWER....WOW...
        printf("%lld\n",ans);
    }
    return 0;
}
