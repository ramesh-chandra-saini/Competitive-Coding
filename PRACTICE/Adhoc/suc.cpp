#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll state,ll n,ll arr[],vector<vector<ll> >&dp){
    if(n<0){
        return INT_MIN;
    }
    if(n==0){
        if(state==1)
            return INT_MIN;
        else
            return 0;
    }
    if(dp[state][n]!=-1)return dp[state][n];
    if(state==0)
        return dp[state][n]=max(solve(0LL,n-1,arr,dp),solve(1LL,n-1,arr,dp));
    else
        return dp[state][n]=arr[n]+solve(0LL,n-2,arr,dp);
}
ll rec(ll n,ll ct,ll arr[],vector<vector<ll> > & dp){
    if(ct>=3){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][ct]!=-1)
        return dp[n][ct];
    return dp[n][ct]=max(arr[n]+rec(n-1,ct+1,arr,dp),rec(n-1,0,arr,dp));
}

int main(){

        ll n; cin >> n;
        ll arr[n+1]; for(ll i=1;i<=n;i++) cin >> arr[i];
        vector<vector<ll> > rc(n+1,vector<ll>(3,-1));
        cout<<rec(n,0,arr,rc)<<endl;
        return 0;
        vector<vector<ll> > dp(2,vector<ll>(n+1,-1));
        ll ans1 = solve(0LL,n,arr,dp);
        vector<vector<ll> > dp2(2,vector<ll>(n+1,-1));
        ll ans2= solve(1LL,n,arr,dp2);

        cout<<max(ans1,ans2)<<endl;
    return 0;
}
