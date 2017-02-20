
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define make_key(N,val,bound) make_pair(N,make_pair(val,bound))
#define key pair<ll,pair<ll,ll> >
bool check(ll N,ll base){
    while(N){
        if(N%base!=1)
            return false;
        N/=base;
    }
    return true;
}
ll solve(ll N,ll bound,ll val,map<key,ll>&dp){
    key cur = make_key(N,val,bound);
    if(N<0)
        return 0;
    if(N==0)
        return 1;
    if(dp.find(cur)!=dp.end())
        return dp[cur];
    ll ans = 0;
    for(ll i=0;i<=bound;i++)
        ans+=solve(N-(val+i),bound-i,val+i,dp);
    return dp[cur]=ans;
}

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
    ll t;cin >> t;
    for(ll T=1;T<=t;T++){
        ll N,D;cin>>N>>D;
        ll ans = 0;
        map<key,ll> dp;
        for(ll d=D,add=d;d<=N;d+=add){
                ll curr=solve(N-d,2,d,dp);
                //cout<<d<<" --> "<<curr<<endl;
                ans+=curr;
        }
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
    return 0;
}
