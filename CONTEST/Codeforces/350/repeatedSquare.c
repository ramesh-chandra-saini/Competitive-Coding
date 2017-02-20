#include<stdio.h>
long long int repeatedSquare(long long int N, long long int Pow,long long int Mod){
    long long int ans=1LL;
    while(Pow){
        if(Pow & 1) ans=(ans*N)%Mod;
        N=(N*N)%Mod,Pow>>=1;
    }  return ans;
}
int main(){

    long long int N,Pow,Mod;
    while(1){
        printf("Enter N,Power,Mod: ");
        scanf("%lld%lld%lld",&N,&Pow,&Mod);
        printf("Your Ans : %lld\n",repeatedSquare(N,Pow,Mod));
    }
    return 0;
}
