#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define make_key(N,OC,prev,ct) make_pair(make_pair(N,OC),make_pair(prev,ct));
#define KEY pair<pair<ll,ll>,pair<ll,ll> >
ll solve(ll N,ll OC,ll prev,ll ct,ll K,map<KEY,ll>&dp){
    if(OC<0LL || OC>N)
        return 0LL;
    if(N==0LL){
        return (OC==0LL && ct>=K);
    }
    KEY key = make_key(N,OC,prev,ct);
    if(dp.find(key)!=dp.end())
        return dp[key];
    return dp[key]=solve(N-1LL,OC+1LL,0LL,ct+(prev!=0LL),K,dp)+ //putting open 0 --> '('
       solve(N-1LL,OC-1LL,1LL,ct+(prev!=1LL),K,dp);//putting open 1 --> ')'
}
int main(){
    ll q; cin >> q; while(q--){
        map<KEY,ll>dp;
        ll n,k; cin >> n >> k;
        cout<<solve(n,0LL,0LL,0LL,k,dp)<<endl;
    } return 0;
}
