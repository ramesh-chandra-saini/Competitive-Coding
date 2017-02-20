#include<bits/stdc++.h>
using namespace std;
#define energy first
#define apple second
#define ll long long int
ll solve(ll N,ll E,ll P,vector<pair<ll,ll> > &arr,vector<vector<ll> > &dp){
    if(E<0)
        return -(ll)INFINITY;
    if(N==0){
        if(E<=P)//at most P energy you can use
            return 0;
        return -(ll)INFINITY;
    }
    if(dp[N][E]!=-(ll)INFINITY)
        return dp[N][E];
    ll ans = arr[N].apple+solve(N-1,E+1,P,arr,dp);
    if(E-arr[N].energy+1>=1)//energy should be greater than 1 at previous farm
        ans = max(ans,solve(N-1,E-arr[N].energy+1,P,arr,dp));
    return dp[N][E]=ans;
}

int main(){
    ll T; scanf("%lld",&T);
    while(T--){
        vector<vector<ll> > dp(1003,vector<ll>(2003,-(ll)INFINITY));
        vector<pair<ll,ll> > arr(1003);
        ll N,P; scanf("%lld%lld",&N,&P);
        for(ll i=1;i<=N;i++) //read energy
             scanf("%lld",&arr[i].energy);
        for(ll i=1;i<=N;i++)//read apple
             scanf("%lld",&arr[i].apple);
        ll ans = 0;
        if(P==0) //cann't pick any apple
            ans = 0;
        else if(P>=N)//pick apple
            for(ll i=1;i<=N;i++)
                ans+=arr[i].apple;
        else
            for(ll i=0;i<=1000;i++)
                ans = max(ans,solve(N,i,P,arr,dp));
        printf("%lld\n",ans);
    }
    return 0;
}
