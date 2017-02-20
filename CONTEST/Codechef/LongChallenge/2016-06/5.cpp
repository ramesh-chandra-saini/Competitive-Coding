#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[10000007];
ll power(ll N,ll expo){
    ll ans=1LL;for(;expo;expo/=2LL,N=(N*N)%mod) if(expo%2) ans=(N*ans)%mod;return ans;
}
ll C(ll N, ll K){

    ll ans=(K==N && K && N)?1:0;

    if(K<N){
    ll k=dp[K]; 1LL;//for(ll i=2LL;i<=K;i++) k=(k*i)%mod;
    ll n_k=dp[N-K];//for(ll i=2LL;i<=N-K;i++) n_k=(n_k*i)%mod;
    ll n=dp[N];//for(ll i=2LL;i<=N;i++) n=(n*i)%mod;
    ll denom = (k*n_k)%mod;
    ans = ( n*power(denom,mod-2) )%mod;
    } //cout<<"C("<<N<<","<<K<<") : "<<ans<<"  ";
    return ans;
}
ll Solve(ll n, ll K, ll zero){
    ll ans=0,i=0,k;
    for(k=K;k>=K-zero && k>=0;k--){
        ll add=C(n,k)%mod; //cout<<" = "<<add<<endl;
        ans=(ans+add)%mod;
    }
    for(k=K-((zero+1)+((zero+1)%2));k>=0;k-=2){
        ll add=C(n,k)%mod; //cout<<" = "<<add<<endl;
        ans=(ans+add)%mod;
    } return ans;
}
void preprocessing(){
    dp[0]=1LL;for(ll i=1;i<=10000007;i++) dp[i]=(dp[i-1]*i)%mod;
}
int main(){
    preprocessing();
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        ll zero=0,arr[n];
        for(ll i=0;i<n;i++) cin >> arr[i] , zero+=(arr[i]==0);
        n-=zero;
        if(n==1){
            if(k%2) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }else cout<<Solve(n,k,zero)<<endl;
    }
    return 0;
}

