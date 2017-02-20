#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define ll long long int
ll prime[MAX+1];
void Sieve(){
    for(ll i =0;i<=MAX;i++) prime[i]=1LL; prime[0]=prime[1]=0LL;
    for(ll i=2;i*i<=MAX;i++)
        if(prime[i]==1LL)
            for(ll j=i*i;j<=MAX;j+=i) prime[j]=0LL;
    for(ll i=0;i*i<=MAX;i++)
        if(prime[i]==1LL)
            for(ll j=i*i;j<=MAX;j*=i) prime[j]=1LL;
    for(int i=0;i<=MAX;i++)
        if(prime[i]==1LL) cout<<i<<" "; cout<<endl;
}
int main(){

    Sieve();
    return 0;
}
