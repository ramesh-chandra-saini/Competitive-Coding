#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll solve(ll curr,ll parent,vector<vector<ll> >&adj,vector<ll>&W,vector<ll>&dp){

    if(dp[curr]!=INT_MIN)
        return dp[curr];
    ll include = W[curr];
    ll exclude = 0;
    for(ll i=0;i<adj[curr].size();i++){
        ll next = adj[curr][i];
        if(next==parent)
            continue;
        exclude+=solve(next,curr,adj,W,dp);
        for(ll j=0;j<adj[next].size();j++){
            ll next_next = adj[next][j];
            if(next_next==curr)
                continue;
            include+=solve(next_next,next,adj,W,dp);
        }
    }
    return dp[curr]=max(include,exclude);
}
int main(){

    ll N;
    cin >> N;

    vector<ll> W(N+1);
    for(ll i=1;i<=N;i++)
        cin >> W[i];

    vector<vector<ll> > adj(N+1,vector<ll>());
    for(ll i=1,u,v;i<N;i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> dp(N+1,INT_MIN);
    cout<<solve(1,0,adj,W,dp)<<endl;
    return 0;
}
