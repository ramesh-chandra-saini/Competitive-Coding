/*
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
bool isPrime[10000001];
int numberPrime[10000001];
void seive(){

    memset(isPrime,true,sizeof(isPrime));
    //base case
    isPrime[0]=isPrime[1]=false;numberPrime[0]=numberPrime[1]=0;
    for(int i=2;i*i<=10000000;i++){

        if(isPrime[i]){
            for(int j=i*i;j<=10000000;j+=i)
                    isPrime[j]=false;
        }
    }
    for(int i=1;i<=10000000;i++)
        numberPrime[i]+=numberPrime[i-1]+isPrime[i];
}
long long int solve(int N,int K){

    long long int factK=1,ans=1,_gcd; for(int i=1;i<=K;i++) factK*=(long long int)i;
    while(factK>1){
        ans*=N;
        _gcd=__gcd(ans,factK);
        ans/=_gcd;
        factK/=_gcd;
        N--;K--;
    }
    ans%=Mod;
    while(K>0){
        ans=(ans*N)%Mod;
        N--;K--;
    }
    return ans;
}
int main(){

    int Q,L,R,K,N;
    scanf("%d",&Q);
    seive();   //cout<<numberPrime[10000000]<<endl;
    while(Q--){

        scanf("%d%d%d",&L,&R,&K);
        N=numberPrime[R]-numberPrime[L-1]; //cout<<N<<endl;
        if(N<K) printf("0\n");
        else printf("%lld\n",solve(N,K));
    }
    return 0;
}
