#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
set<ll> PrimeList;
vector<ll> newPrime;
vector<ll> Values;
vector<ll> factor;
ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll dp[101];
vector<ll> primeFactor(ll i){
    factor.clear();
    for(int j=0;j<25;j++)
       if(i%prime[j]==0) factor.push_back(prime[j]);
    return factor;
}
ll checkGcd(ll i,set<ll> &primeList){
    ll gcd=1;
    vector<ll> fact(primeFactor(i));
    for(ll k=0;k<fact.size();k++){
            if(primeList.find(fact[k])!=primeList.end()){
                return fact[k];
            }
    }
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
ll solve(ll n, ll m,ll pos,ll lastInsertedItem,ll count,set<ll> primeList,vector<ll> values){
    if(pos==n) {
        ll A=dp[n],B=dp[n-count];
        ll ans=(A*power(B,MOD-2,MOD))%MOD;
        return ans;
    }
    if(primeList.size()>=25) return 0;
    ll ans=0;
    for(ll i=(lastInsertedItem==1)?1:lastInsertedItem+1;i<=m;i++){
        if(checkGcd(i,primeList)==1){
            if(i==1){ Values=values; Values.push_back(i);
                ans+=solve(n,m,pos+1,i,count,primeList,Values);
            }else{
                PrimeList=primeList;
                newPrime=primeFactor(i);
                for(ll j=0;j<newPrime.size();j++)
                    PrimeList.insert(newPrime[j]);
                Values=values; Values.push_back(i);
                ans=(ans+solve(n,m,pos+1,i,count+1,PrimeList,Values))%MOD;
            }
        }
    }
    return ans;
}
int main(){
    ll t; cin >> t;
    set<ll> primeList;
    vector<ll> values;
    dp[0]=1; for(int i=1;i<=100;i++) dp[i]=(dp[i-1]*i)%MOD;
    while(t--){
        ll n,m; cin >> n >> m;
        primeList.clear();
        ll lastInsertedItem=1,pos=0,ct=0;
        values.clear();
        cout<<solve(n,m,pos,lastInsertedItem,ct,primeList,values)<<endl;
    }
    return 0;
}
