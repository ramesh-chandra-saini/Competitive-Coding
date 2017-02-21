#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000106
vector<ll> primeList;
vector<bool> isPrime(MAX,true);
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i*i<MAX;i++)
        if(isPrime[i])
            for(ll j=i*i;j<MAX;j+=i)
                isPrime[j]=false;
    for(ll i=0;i<MAX;i++)
        if(isPrime[i])
            primeList.push_back(i);
}
map<ll,ll> getFact(ll N){
    map<ll,ll> factors;
    for(ll i=0;primeList[i]<=N;i++)
        while(N>1 && N%primeList[i]==0)
            factors[primeList[i]]++,N/=i;
    return factors;
}
map<ll,ll> mergeMap(map<ll,ll> A,map<ll,ll> B){
    for(map<ll,ll>::iterator it = B.begin();it!=B.end();++it)
        A[(it->first)]+=B[(it->first)];
}
map<ll,ll>
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll arr[n];
        for(int i=0;i<n;i++)
             cin >> arr[i];
        if(n==0){
            map<ll,ll> fact = getFact(arr[0]);
            ll ans = 0;
            for(map<ll,ll>::iterator it = fact.begin();it!=fact.end();++it)
                ans+=(it->second)%2;
        }else{


        }
    }
    return 0;
}
