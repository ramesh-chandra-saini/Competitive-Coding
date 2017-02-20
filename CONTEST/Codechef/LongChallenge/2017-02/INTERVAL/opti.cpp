#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum(ll l,ll r,vector<ll>&cumm){
    return cumm[r]-((l>0)?cumm[l-1]:0);
}
ll dp[300005][201];
ll solve(ll L,ll R,vector<ll>&B, ll m,ll M,vector<ll>&cumm, ll flag){
    if(m>M)
        return 0LL;
    int id = (flag==-1)?0:1;
    if(dp[L][id]!=-1)
        return dp[L][id];

    if(flag==1){
        ll ans = INT_MIN;
        ll window = B[m];
        for(ll i=L;i+window-1<=R;i++){
            ll left = i,right = i+window-1;
           ans = max(ans,(flag*sum(left,right,cumm))+solve(left+1,right-1,B,m+1,M,cumm,-1*flag));
        }
        return dp[L][id]=ans;
    }else{
        ll ans = INT_MAX;
        ll window = B[m];
        for(ll i=L;i+window-1<=R;i++){
            ll left = i,right = i+window-1;
           ans = min(ans,(flag*sum(left,right,cumm))+solve(left+1,right-1,B,m+1,M,cumm,-1*flag));
        }
        return dp[L][id]= ans;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
   // freopen("out,txt","w",stdout);
    ll T; scanf("%lld",&T);
    while(T--){
        ll N,M,ans=INT_MIN; scanf("%lld%lld",&N,&M);
        vector<ll> A(N+1,0),cumm(N+1,0),B(M+1,0);
        for(ll i=1;i<=N;i++)
            scanf("%lld",&A[i]),cumm[i]=cumm[i-1]+A[i];
        for(ll i=1;i<=M;i++)
            scanf("%lld",&B[i]);
        for(ll i=0;i<=N;i++)
            for(ll j=0;j<=2;j++)
                dp[i][j]=-1;
        ans = solve(1LL,N,B,1LL,M,cumm,1LL);
        printf("%lld\n",ans);
    }
}
