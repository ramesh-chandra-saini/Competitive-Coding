#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld  double
ll solve(ll n,ll m,vector<vector<ll> >&dp,ll N, ll M){
    //cout<<n<<" "<<m<<endl;
    if(N-n<=M-m) return 0;
    if(n==0 ||  m==0) return 1;
    if(dp[n][m]!=-1) return dp[n][m];
    return dp[n][m]=n*solve(n-1,m,dp,N,M)+m*solve(n,m-1,dp,N,M);
}
ll fact(ll N){
    return N<=1?1LL:N*fact(N-1);
}

int main(){

/*    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);*/
    ll t; cin >> t; for(ll T=1;T<=t;T++){
        ll m,n; cin >> n >> m;
        vector<vector<ll> > dp(n+1,vector<ll>(m+1,-1));
        ll ans = n*solve(n-1,m,dp,n,m);
        ll k = fact(m+n); cout<<k<<endl;
        ld a = (ld)ans;
        ld K = (ld)k;
        ld f = a/K;
        printf("Case #%d: %.12lf\n",T,f);

    }
}
