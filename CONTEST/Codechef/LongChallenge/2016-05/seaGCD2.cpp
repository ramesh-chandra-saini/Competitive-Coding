#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
set<ll> PrimeList;
vector<ll> newPrime;
vector<ll> Values;
vector<ll> factor;
vector<ll> __m;
ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll dp[101];
vector<ll> primeFactor(ll i){
    factor.clear();
    for(int j=0;j<25;j++)
       if(i%prime[j]==0) factor.push_back(prime[j]);
    return factor;
}
ll checkGcd(ll i,set<ll> &primeList){
    for(set<ll> :: iterator it =primeList.begin();it!=primeList.end();++it)
        if(__gcd(i,*it)>1) return  __gcd(i,*it);
    return 1;//co prime
}
ll power(ll N,ll pow,ll mod){
    ll ans=1;
    while(pow){
        if(pow%2) ans=(ans*N)%mod;
        N=(N*N)%mod;pow/=2;
    }
    return ans;
}
ll solve(ll n, ll m,ll pos,ll lastInsertedItem,ll count,set<ll> primeList,vector<ll> __M){
    if(pos==n) {
        ll A=dp[n],B=dp[n-count];
        ll ans=(A*power(B,MOD-2,MOD))%MOD;
        return ans;
    }
    ll ans=0;
    for(vector<ll> ::iterator __it=__M.begin();__it!=__M.end();++__it){
        ll i=*__it;
        if(checkGcd(i,primeList)==1){
            if(i==1){
                ans=(ans+solve(n,m,pos+1,i,count,primeList,__M))%MOD;
            }else{
                PrimeList=primeList;
                newPrime=primeFactor(i);
                __m=__M;
                for(ll j=0;j<newPrime.size();j++){
                    PrimeList.insert(newPrime[j]);
                    for(ll k=0;k<__m.size();){
                        if((__m[k])<=newPrime[j] || (__m[k])%newPrime[j]==0) __m.erase(__m.begin()+k);
                        else k++;
                    }
                }
                ans=(ans+solve(n,m,pos+1,i,count+1,PrimeList,__m))%MOD;
            }
        }
    }
    return ans;
}
int main(){
    ll t; cin >> t;
    set<ll> primeList;
    vector<ll> __M;
    dp[0]=1; for(int i=1;i<=100;i++) dp[i]=(dp[i-1]*i)%MOD;
    while(t--){
        ll n,m; cin >> n >> m;
        primeList.clear();
        ll lastInsertedItem=1,pos=0,ct=0;
        __M.clear();
        for(ll i=1;i<=m;i++) __M.push_back(i);
        cout<<solve(n,m,pos,lastInsertedItem,ct,primeList,__M)<<endl;
    }
    return 0;
}
